// This may look like C code, but it is really -*- C++ -*-
/* 
Copyright (C) 1988 Free Software Foundation
    written by Doug Lea (dl@rocky.oswego.edu)

This file is part of the GNU C++ Library.  This library is free
software; you can redistribute it and/or modify it under the terms of
the GNU Library General Public License as published by the Free
Software Foundation; either version 2 of the License, or (at your
option) any later version.  This library is distributed in the hope
that it will be useful, but WITHOUT ANY WARRANTY; without even the
implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
PURPOSE.  See the GNU Library General Public License for more details.
You should have received a copy of the GNU Library General Public
License along with this library; if not, write to the Free Software
Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#ifdef __GNUG__
#pragma implementation
#endif

// commented -erm
//#include <stream.h>
#include <iostream.h>
#include "my-builtin.hh"
#include "ObjectPtr.Vec.hh"

// Added -erm
#include <stdlib.h>

// error handling


void default_ObjectPtrVec_error_handler(const char* msg)
{
  cerr << "Fatal ObjectPtrVec error. " << msg << "\n";
  exit(1);
}

one_arg_error_handler_t ObjectPtrVec_error_handler = default_ObjectPtrVec_error_handler;

one_arg_error_handler_t set_ObjectPtrVec_error_handler(one_arg_error_handler_t f)
{
  one_arg_error_handler_t old = ObjectPtrVec_error_handler;
  ObjectPtrVec_error_handler = f;
  return old;
}

void ObjectPtrVec::error(const char* msg)
{
  (*ObjectPtrVec_error_handler)(msg);
}

void ObjectPtrVec::range_error()
{
  (*ObjectPtrVec_error_handler)("Index out of range.");
}

ObjectPtrVec::ObjectPtrVec(const ObjectPtrVec& v)
{
  s = new (GC) ObjectPtr [len = v.len];
  ObjectPtr* top = &(s[len]);
  ObjectPtr* t = s;
  const ObjectPtr* u = v.s;
  while (t < top) *t++ = *u++;
}

ObjectPtrVec::ObjectPtrVec(int l, ObjectPtr  fill_value)
{
  s = new (GC) ObjectPtr [len = l];
  ObjectPtr* top = &(s[len]);
  ObjectPtr* t = s;
  while (t < top) *t++ = fill_value;
}


ObjectPtrVec& ObjectPtrVec::operator = (const ObjectPtrVec& v)
{
  if (this != &v)
  {
    delete [] s;
    s = new (GC) ObjectPtr [len = v.len];
    ObjectPtr* top = &(s[len]);
    ObjectPtr* t = s;
    const ObjectPtr* u = v.s;
    while (t < top) *t++ = *u++;
  }
  return *this;
}

void ObjectPtrVec::apply(ObjectPtrProcedure f)
{
  ObjectPtr* top = &(s[len]);
  ObjectPtr* t = s;
  while (t < top) (*f)(*t++);
}

// can't just realloc since there may be need for constructors/destructors
void ObjectPtrVec::resize(int newl)
{
  ObjectPtr* news = new (GC) ObjectPtr [newl];
  ObjectPtr* p = news;
  int minl = (len < newl)? len : newl;
  ObjectPtr* top = &(s[minl]);
  ObjectPtr* t = s;
  while (t < top) *p++ = *t++;
  delete [] s;
  s = news;
  len = newl;
}

ObjectPtrVec concat(ObjectPtrVec & a, ObjectPtrVec & b)
{
  int newl = a.len + b.len;
  ObjectPtr* news = new (GC) ObjectPtr [newl];
  ObjectPtr* p = news;
  ObjectPtr* top = &(a.s[a.len]);
  ObjectPtr* t = a.s;
  while (t < top) *p++ = *t++;
  top = &(b.s[b.len]);
  t = b.s;
  while (t < top) *p++ = *t++;
  return ObjectPtrVec(newl, news);
}


ObjectPtrVec combine(ObjectPtrCombiner f, ObjectPtrVec& a, ObjectPtrVec& b)
{
  int newl = (a.len < b.len)? a.len : b.len;
  ObjectPtr* news = new (GC) ObjectPtr [newl];
  ObjectPtr* p = news;
  ObjectPtr* top = &(a.s[newl]);
  ObjectPtr* t = a.s;
  ObjectPtr* u = b.s;
  while (t < top) *p++ = (*f)(*t++, *u++);
  return ObjectPtrVec(newl, news);
}

ObjectPtr ObjectPtrVec::reduce(ObjectPtrCombiner f, ObjectPtr  base)
{
  ObjectPtr r = base;
  ObjectPtr* top = &(s[len]);
  ObjectPtr* t = s;
  while (t < top) r = (*f)(r, *t++);
  return r;
}

ObjectPtrVec reverse(ObjectPtrVec& a)
{
  ObjectPtr* news = new (GC) ObjectPtr [a.len];
  if (a.len != 0)
  {
    ObjectPtr* lo = news;
    ObjectPtr* hi = &(news[a.len - 1]);
    while (lo < hi)
    {
      ObjectPtr tmp = *lo;
      *lo++ = *hi;
      *hi-- = tmp;
    }
  }
  return ObjectPtrVec(a.len, news);
}

void ObjectPtrVec::reverse()
{
  if (len != 0)
  {
    ObjectPtr* lo = s;
    ObjectPtr* hi = &(s[len - 1]);
    while (lo < hi)
    {
      ObjectPtr tmp = *lo;
      *lo++ = *hi;
      *hi-- = tmp;
    }
  }
}

int ObjectPtrVec::index(ObjectPtr  targ)
{
  for (int i = 0; i < len; ++i) if (ObjectPtrEQ(targ, s[i])) return i;
  return -1;
}

ObjectPtrVec map(ObjectPtrMapper f, ObjectPtrVec& a)
{
  ObjectPtr* news = new (GC) ObjectPtr [a.len];
  ObjectPtr* p = news;
  ObjectPtr* top = &(a.s[a.len]);
  ObjectPtr* t = a.s;
  while(t < top) *p++ = (*f)(*t++);
  return ObjectPtrVec(a.len, news);
}

int operator == (ObjectPtrVec& a, ObjectPtrVec& b)
{
  if (a.len != b.len)
    return 0;
  ObjectPtr* top = &(a.s[a.len]);
  ObjectPtr* t = a.s;
  ObjectPtr* u = b.s;
  while (t < top) if (!(ObjectPtrEQ(*t++, *u++))) return 0;
  return 1;
}

void ObjectPtrVec::fill(ObjectPtr  val, int from, int n)
{
  int to;
  if (n < 0)
    to = len - 1;
  else
    to = from + n - 1;
  if ((unsigned)from > (unsigned)to)
    range_error();
  ObjectPtr* t = &(s[from]);
  ObjectPtr* top = &(s[to]);
  while (t <= top) *t++ = val;
}

ObjectPtrVec ObjectPtrVec::at(int from, int n)
{
  int to;
  if (n < 0)
  {
    n = len - from;
    to = len - 1;
  }
  else
    to = from + n - 1;
  if ((unsigned)from > (unsigned)to)
    range_error();
  ObjectPtr* news = new (GC) ObjectPtr [n];
  ObjectPtr* p = news;
  ObjectPtr* t = &(s[from]);
  ObjectPtr* top = &(s[to]);
  while (t <= top) *p++ = *t++;
  return ObjectPtrVec(n, news);
}

ObjectPtrVec merge(ObjectPtrVec & a, ObjectPtrVec & b, ObjectPtrComparator f)
{
  int newl = a.len + b.len;
  ObjectPtr* news = new (GC) ObjectPtr [newl];
  ObjectPtr* p = news;
  ObjectPtr* topa = &(a.s[a.len]);
  ObjectPtr* as = a.s;
  ObjectPtr* topb = &(b.s[b.len]);
  ObjectPtr* bs = b.s;

  for (;;)
  {
    if (as >= topa)
    {
      while (bs < topb) *p++ = *bs++;
      break;
    }
    else if (bs >= topb)
    {
      while (as < topa) *p++ = *as++;
      break;
    }
    else if ((*f)(*as, *bs) <= 0)
      *p++ = *as++;
    else
      *p++ = *bs++;
  }
  return ObjectPtrVec(newl, news);
}

static int gsort(ObjectPtr*, int, ObjectPtrComparator);
 
void ObjectPtrVec::sort (ObjectPtrComparator compar)
{
  gsort(s, len, compar);
}


// An adaptation of Schmidt's new quicksort

static inline void SWAP(ObjectPtr* A, ObjectPtr* B)
{
  ObjectPtr tmp = *A; *A = *B; *B = tmp;
}

/* This should be replaced by a standard ANSI macro. */
#define BYTES_PER_WORD 8
#define BYTES_PER_LONG 4

/* The next 4 #defines implement a very fast in-line stack abstraction. */

#define STACK_SIZE (BYTES_PER_WORD * BYTES_PER_LONG)
#define PUSH(LOW,HIGH) do {top->lo = LOW;top++->hi = HIGH;} while (0)
#define POP(LOW,HIGH)  do {LOW = (--top)->lo;HIGH = top->hi;} while (0)
#define STACK_NOT_EMPTY (stack < top)                

/* Discontinue quicksort algorithm when partition gets below this size.
   This particular magic number was chosen to work best on a Sun 4/260. */
#define MAX_THRESH 4


/* Order size using quicksort.  This implementation incorporates
   four optimizations discussed in Sedgewick:
   
   1. Non-recursive, using an explicit stack of pointer that
      store the next array partition to sort.  To save time, this
      maximum amount of space required to store an array of
      MAX_INT is allocated on the stack.  Assuming a 32-bit integer,
      this needs only 32 * sizeof (stack_node) == 136 bits.  Pretty
      cheap, actually.

   2. Chose the pivot element using a median-of-three decision tree.
      This reduces the probability of selecting a bad pivot value and 
      eliminates certain extraneous comparisons.

   3. Only quicksorts TOTAL_ELEMS / MAX_THRESH partitions, leaving
      insertion sort to order the MAX_THRESH items within each partition.  
      This is a big win, since insertion sort is faster for small, mostly
      sorted array segements.
   
   4. The larger of the two sub-partitions is always pushed onto the
      stack first, with the algorithm then concentrating on the
      smaller partition.  This *guarantees* no more than log (n)
      stack size is needed! */
      
static int gsort (ObjectPtr *base_ptr, int total_elems, ObjectPtrComparator cmp)
{
/* Stack node declarations used to store unfulfilled partition obligations. */
  struct stack_node {  ObjectPtr *lo;  ObjectPtr *hi; };
  ObjectPtr   pivot_buffer;
  int   max_thresh   = MAX_THRESH;

  if (total_elems > MAX_THRESH)
    {
      ObjectPtr       *lo = base_ptr;
      ObjectPtr       *hi = lo + (total_elems - 1);
      ObjectPtr       *left_ptr;
      ObjectPtr       *right_ptr;
      stack_node stack[STACK_SIZE]; /* Largest size needed for 32-bit int!!! */
      stack_node *top = stack + 1;

      while (STACK_NOT_EMPTY)
        {
          {
            ObjectPtr *pivot = &pivot_buffer;
            {
              /* Select median value from among LO, MID, and HI. Rearrange
                 LO and HI so the three values are sorted. This lowers the 
                 probability of picking a pathological pivot value and 
                 skips a comparison for both the LEFT_PTR and RIGHT_PTR. */

              ObjectPtr *mid = lo + ((hi - lo) >> 1);

              if ((*cmp) (*mid, *lo) < 0)
                SWAP (mid, lo);
              if ((*cmp) (*hi, *mid) < 0)
              {
                SWAP (mid, hi);
                if ((*cmp) (*mid, *lo) < 0)
                  SWAP (mid, lo);
              }
              *pivot = *mid;
              pivot = &pivot_buffer;
            }
            left_ptr  = lo + 1;
            right_ptr = hi - 1; 

            /* Here's the famous ``collapse the walls'' section of quicksort.  
               Gotta like those tight inner loops!  They are the main reason 
               that this algorithm runs much faster than others. */
            do 
              {
                while ((*cmp) (*left_ptr, *pivot) < 0)
                  left_ptr += 1;

                while ((*cmp) (*pivot, *right_ptr) < 0)
                  right_ptr -= 1;

                if (left_ptr < right_ptr) 
                  {
                    SWAP (left_ptr, right_ptr);
                    left_ptr += 1;
                    right_ptr -= 1;
                  }
                else if (left_ptr == right_ptr) 
                  {
                    left_ptr += 1;
                    right_ptr -= 1;
                    break;
                  }
              } 
            while (left_ptr <= right_ptr);

          }

          /* Set up pointers for next iteration.  First determine whether
             left and right partitions are below the threshold size. If so, 
             ignore one or both.  Otherwise, push the larger partition's
             bounds on the stack and continue sorting the smaller one. */

          if ((right_ptr - lo) <= max_thresh)
            {
              if ((hi - left_ptr) <= max_thresh) /* Ignore both small partitions. */
                POP (lo, hi); 
              else              /* Ignore small left partition. */  
                lo = left_ptr;
            }
          else if ((hi - left_ptr) <= max_thresh) /* Ignore small right partition. */
            hi = right_ptr;
          else if ((right_ptr - lo) > (hi - left_ptr)) /* Push larger left partition indices. */
            {                   
              PUSH (lo, right_ptr);
              lo = left_ptr;
            }
          else                  /* Push larger right partition indices. */
            {                   
              PUSH (left_ptr, hi);
              hi = right_ptr;
            }
        }
    }

  /* Once the BASE_PTR array is partially sorted by quicksort the rest
     is completely sorted using insertion sort, since this is efficient 
     for partitions below MAX_THRESH size. BASE_PTR points to the beginning 
     of the array to sort, and END_PTR points at the very last element in
     the array (*not* one beyond it!). */


  {
    ObjectPtr *end_ptr = base_ptr + 1 * (total_elems - 1);
    ObjectPtr *run_ptr;
    ObjectPtr *tmp_ptr = base_ptr;
    ObjectPtr *thresh  = (end_ptr < (base_ptr + max_thresh))? 
      end_ptr : (base_ptr + max_thresh);

    /* Find smallest element in first threshold and place it at the
       array's beginning.  This is the smallest array element,
       and the operation speeds up insertion sort's inner loop. */

    for (run_ptr = tmp_ptr + 1; run_ptr <= thresh; run_ptr += 1)
      if ((*cmp) (*run_ptr, *tmp_ptr) < 0)
        tmp_ptr = run_ptr;

    if (tmp_ptr != base_ptr)
      SWAP (tmp_ptr, base_ptr);

    /* Insertion sort, running from left-hand-side up to `right-hand-side.' 
       Pretty much straight out of the original GNU qsort routine. */

    for (run_ptr = base_ptr + 1; (tmp_ptr = run_ptr += 1) <= end_ptr; )
      {

        while ((*cmp) (*run_ptr, *(tmp_ptr -= 1)) < 0)
          ;

        if ((tmp_ptr += 1) != run_ptr)
          {
            ObjectPtr *trav;

            for (trav = run_ptr + 1; --trav >= run_ptr;)
              {
                ObjectPtr c = *trav;
                ObjectPtr *hi, *lo;

                for (hi = lo = trav; (lo -= 1) >= tmp_ptr; hi = lo)
                  *hi = *lo;
                *hi = c;
              }
          }

      }
  }
  return 1;
}
