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


#ifndef _ObjectPtrVec_h
#ifdef __GNUG__
#pragma interface
#endif
#define _ObjectPtrVec_h 1

#include "gc.hh"

// Modified -erm
//#include <builtin.h>
#include "my-builtin.hh"
#include "ObjectPtr.defs.hh"

#ifndef _ObjectPtr_typedefs
#define _ObjectPtr_typedefs 1
typedef void (*ObjectPtrProcedure)(ObjectPtr );
typedef ObjectPtr  (*ObjectPtrMapper)(ObjectPtr );
typedef ObjectPtr  (*ObjectPtrCombiner)(ObjectPtr , ObjectPtr );
typedef int  (*ObjectPtrPredicate)(ObjectPtr );
typedef int  (*ObjectPtrComparator)(ObjectPtr , ObjectPtr );
#endif


class ObjectPtrVec 
{
protected:      
  int                   len;
  ObjectPtr                   *s;                  

                        ObjectPtrVec(int l, ObjectPtr* d);
public:
                        ObjectPtrVec ();
                        ObjectPtrVec (int l);
                        ObjectPtrVec (int l, ObjectPtr  fill_value);
                        ObjectPtrVec (const ObjectPtrVec&);
                        ~ObjectPtrVec ();

  ObjectPtrVec &              operator = (const ObjectPtrVec & a);
  ObjectPtrVec                at(int from = 0, int n = -1);

  int                   capacity() const;
  void                  resize(int newlen);                        

  ObjectPtr&                  operator [] (int n);
  ObjectPtr&                  elem(int n);

  friend ObjectPtrVec         concat(ObjectPtrVec & a, ObjectPtrVec & b);
  friend ObjectPtrVec         map(ObjectPtrMapper f, ObjectPtrVec & a);
  friend ObjectPtrVec         merge(ObjectPtrVec & a, ObjectPtrVec & b, ObjectPtrComparator f);
  friend ObjectPtrVec         combine(ObjectPtrCombiner f, ObjectPtrVec & a, ObjectPtrVec & b);
  friend ObjectPtrVec         reverse(ObjectPtrVec & a);

  void                  reverse();
  void                  sort(ObjectPtrComparator f);
  void                  fill(ObjectPtr  val, int from = 0, int n = -1);

  void                  apply(ObjectPtrProcedure f);
  ObjectPtr                   reduce(ObjectPtrCombiner f, ObjectPtr  base);
  int                   index(ObjectPtr  targ);

  friend int            operator == (ObjectPtrVec& a, ObjectPtrVec& b);
  friend int            operator != (ObjectPtrVec& a, ObjectPtrVec& b);

  void                  error(const char* msg);
  void                  range_error();
};

extern void default_ObjectPtrVec_error_handler(const char*);
extern one_arg_error_handler_t ObjectPtrVec_error_handler;

extern one_arg_error_handler_t 
        set_ObjectPtrVec_error_handler(one_arg_error_handler_t f);


inline ObjectPtrVec::ObjectPtrVec()
{
  len = 0; s = 0;
}

inline ObjectPtrVec::ObjectPtrVec(int l)
{
  s = new (GC) ObjectPtr [len = l];
}


inline ObjectPtrVec::ObjectPtrVec(int l, ObjectPtr* d) :len(l), s(d) {}


inline ObjectPtrVec::~ObjectPtrVec()
{
  delete [] s;
}


inline ObjectPtr& ObjectPtrVec::operator [] (int n)
{
  if ((unsigned)n >= (unsigned)len)
    range_error();
  return s[n];
}

inline ObjectPtr& ObjectPtrVec::elem(int n)
{
  return s[n];
}


inline int ObjectPtrVec::capacity() const
{
  return len;
}



inline int operator != (ObjectPtrVec& a, ObjectPtrVec& b)
{
  return !(a == b);
}

#endif
