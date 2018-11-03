// conses.cc

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996, 1997             | 
 |  University of Southern California, Information Sciences Institute       |
 |  4676 Admiralty Way                                                      |
 |  Marina Del Rey, California 90292                                        |
 |                                                                          |
 |  This software was developed under the terms and conditions of Contract  |
 |  No. N00014-94-C-0245 between the Defense Advanced Research Projects     |
 |  Agency and the University of Southern California, Information Sciences  | 
 |  Institute.  Use and distribution of this software is further subject    |
 |  to the provisions of that contract and any other agreements developed   |
 |  between the user of the software and the University of Southern         |
 |  California, Information Sciences Institute.  It is supplied "AS IS",    |
 |  without any warranties of any kind.  It is furnished only on the basis  |
 |  that any party who receives it indemnifies and holds harmless the       |
 |  parties who furnish and originate it against any claims, demands, or    |
 |  liabilities connected with using it, furnishing it to others or         |
 |  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    |
 |  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  |
 |  BE ATTACHED TO EVERY PART.                                              |
 |                                                                          |
 +--------------------------------------------------------------------------*/

#include "stella-includes.hh"

Cons* NIL = NULL;

Surrogate* SGT_CONSES_ABSTRACT_ITERATOR = NULL;

Symbol* SYM_CONSES_VALUE = NULL;

Symbol* SYM_CONSES_VALUE_SETTER = NULL;

Symbol* SYM_CONSES_SLOT_WRITER = NULL;

Surrogate* SGT_CONSES_GENERALIZED_SYMBOL = NULL;

boolean oPRINTPRETTYpo = TRUE;

Symbol* SYM_CONSES_oPRINTPRETTYpo = NULL;

boolean oPRINTREADABLYpo = FALSE;

Symbol* SYM_CONSES_oPRINTREADABLYpo = NULL;

Symbol* ELIPSIS = NULL;

boolean oPRINTPRETTYCODEpo = TRUE;

Symbol* SYM_CONSES_oPRINTPRETTYCODEpo = NULL;

boolean oDEPTHEXCEEDEDpo = FALSE;

Symbol* SYM_CONSES_oDEPTHEXCEEDEDpo = NULL;

int oDEPTHCUTOFFo = 33;

boolean Cons::emptyP() {
  // Return TRUE iff 'self' equals NIL.
  { Cons* self = this;

    return (self == NIL);
  }
}

boolean Cons::non_emptyP() {
  // Return TRUE iff 'self' is not equal to NIL.
  { Cons* self = this;

    return (!(self == NIL));
  }
}

boolean nilP(Object* x) {
  // Return TRUE iff 'x' equals NIL.
  return (x == NIL);
}

void Cons::free_cons() {
  { Cons* self = this;

    if (!(self == NIL)) {
      self->free();
    }
  }
}

void free_cons_list(Cons* self) {
  if (nilP(self)) {
    return;
  }
  { Cons* next = self;
    Cons* current = NULL;

    while (next->non_emptyP()) {
      current = next;
      next = next->rest;
      current->free_cons();
    }
  }
}

int Cons::length() {
  // Return the length of the CONS list 'self'.  CAUTION: Breaks if
  // 'self' is not the head of a CONS list.
  { Cons* self = this;

    { Cons* cons = self;
      int i = 0;

      while (cons->non_emptyP()) {
        i = i + 1;
        cons = cons->rest;
      }
      return (i);
    }
  }
}

int Cons::position(Object* object, int start) {
  // Return the position of 'object' within the cons-list
  // 'self' (counting from zero); or return NULL if 'object' does not occur within 
  // 'self' (uses an 'eql?' test).  If 'start' was supplied as non-NULL, only 
  // consider the sublist starting at 'start', however, the returned position 
  // will always be relative to the entire list.
  { Cons* self = this;

    if (start == NULL_INTEGER) {
      start = 0;
    }
    { int position = NULL_INTEGER;
      Object* element = NULL;
      Cons* iter_001 = self->nth_rest(start);
      int iter_002 = start;

      while (!nilP(iter_001)) {
        {
          element = iter_001->value;
          iter_001 = iter_001->rest;
        }
        {
          position = iter_002;
          iter_002 = iter_002 + 1;
        }
        if (eqlP(element, object)) {
          return (position);
        }
      }
    }
    return (NULL_INTEGER);
  }
}

boolean Cons::memberP(Object* object) {
  // Return TRUE iff 'object' is a member of the cons list
  // 'self' (uses an 'eql?' test).
  { Cons* self = this;

    { Object* i = NULL;
      Cons* iter_001 = self;

      while (!nilP(iter_001)) {
        {
          i = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if (eqlP(i, object)) {
          return (TRUE);
        }
      }
    }
    return (FALSE);
  }
}

boolean Cons::membP(Object* object) {
  // Return TRUE iff 'object' is a member of the cons list
  // 'self' (uses an 'eq?' test).
  { Cons* self = this;

    { Object* i = NULL;
      Cons* iter_001 = self;

      while (!nilP(iter_001)) {
        {
          i = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if (i == object) {
          return (TRUE);
        }
      }
    }
    return (FALSE);
  }
}

Cons* cons(Object* value, Cons* rest) {
  // Return a cons record that points to 'value' and 'rest'.
  { Cons* cons = NULL;

    if (oTRANSIENTOBJECTSpo) {
      cons = new_transient_cons();
    }
    else {
      cons = new_cons();
    }
    cons->value = value;
    cons->rest = rest;
    return (cons);
  }
}

Cons* permanent_cons(Object* value, Cons* rest) {
  // Return a permanent cons record that points to 'value' and 'rest'.
  { Cons* cons = NULL;

    cons = new_cons();
    cons->value = value;
    cons->rest = rest;
    return (cons);
  }
}

Cons* local_cons(Object* value, Cons* rest) {
  // Return local cons record that points to 'value' and 'rest'.
  return (cons(value, rest));
}

Cons* Cons::remove(Object* value) {
  // Remove all entries in the cons list 'self' that match
  // 'value'.  Unless the remaining list is NIL, insure that the cons that
  // heads the list is unchanged.
  { Cons* self = this;

    { Cons* cons = self;
      Cons* previouscons = NULL;
      Cons* matchingcons = NULL;

      if (cons->non_emptyP()) {
        if (cons->rest->non_emptyP()) {
          previouscons = cons;
          cons = cons->rest;
          while (cons->non_emptyP()) {
            if (eqlP(cons->value, value)) {
              {
                previouscons->rest = cons->rest;
                matchingcons = cons;
                cons = cons->rest;
                matchingcons->free();
              }
            }
            else {
              {
                previouscons = cons;
                cons = cons->rest;
              }
            }
          }
        }
        if (eqlP(self->value, value)) {
          if (self->rest->emptyP()) {
            self->free();
            return (NIL);
          }
          cons = self->rest;
          self->value = cons->value;
          self->rest = cons->rest;
          cons->free();
        }
      }
      return (self);
    }
  }
}

Cons* Cons::remove_duplicates() {
  // Remove duplicates from the cons list 'self' and return
  // 'self'. Removes all but the first occurrence of items in the list.
  // Preserves the original order of the remaining members.  Runs in quadratic
  // time.
  { Cons* self = this;

    { Cons* cursor = self;
      Cons* rest = NULL;

      while (cursor->non_emptyP()) {
        rest = cursor->rest;
        if (rest->memberP(cursor->value)) {
          rest = rest->remove(cursor->value);
          cursor->rest = rest;
        }
        cursor = rest;
      }
      return (self);
    }
  }
}

Cons* Cons::concatenate(Cons* list2) {
  // Return a cons list consisting of the concatenation of 'self' and
  // 'list2'.    The operation is destructive wrt 'self', but leaves 'list2'
  // intact.  CAUTION:  This operation results in structure sharing
  // of 'list2'; to avoid this, 'list2' should not be pointed to by anything
  // other than the tail of 'self'.
  { Cons* self = this;

    if (self->emptyP()) {
      return (list2);
    }
    if (list2->emptyP()) {
      return (self);
    }
    { Cons* cursor = self;

      while (cursor->rest->non_emptyP()) {
        cursor = cursor->rest;
      }
      cursor->rest = list2;
      return (self);
    }
  }
}

Cons* Cons::prepend(Cons* list1) {
  // Return a cons list consisting of the concatenation of
  // 'list1' and 'self'.  A copy of 'list1' is prepended to 'self'.  This
  // operation results in structure sharing of 'self'; to avoid this, 'self'
  // should not be pointed to by anything other than the tail of the prepended
  // copy.
  { Cons* self = this;

    if (list1->emptyP()) {
      return (self);
    }
    { Cons* copy1 = copy_cons_list(list1);

      copy1->concatenate(self);
      return (copy1);
    }
  }
}

Cons* Cons::reverse() {
  // Destructively reverse the members of the cons list 'self'.
  { Cons* self = this;

    if (self->emptyP()) {
      return (self);
    }
    { Cons* reversedconslist = self;
      Cons* remainingconslist = reversedconslist->rest;
      Cons* detachedcons = NULL;

      if (remainingconslist->emptyP()) {
        return (reversedconslist);
      }
      reversedconslist->rest = NIL;
      while (remainingconslist->non_emptyP()) {
        detachedcons = remainingconslist;
        remainingconslist = remainingconslist->rest;
        detachedcons->rest = reversedconslist;
        reversedconslist = detachedcons;
      }
      return (reversedconslist);
    }
  }
}

Cons* Cons::substitute(Object* invalue, Object* outvalue) {
  // Destructively replace each appearance of 'outValue' by
  // 'inValue' in the cons list 'self'.
  { Cons* self = this;

    { Cons* cursor = self;

      while (cursor->non_emptyP()) {
        if (eqlP(cursor->value, outvalue)) {
          cursor->value = invalue;
        }
        cursor = cursor->rest;
      }
      return (self);
    }
  }
}

Object* Cons::first() {
  // Return the first element of 'self'.  The first element
  // of 'self' can be set with 'setf'.  Note that '(first NIL)' = NULL.
  { Cons* self = this;

    return (self->value);
  }
}

Object* Cons::second() {
  // Return the second element of 'self'.  The second element
  // of 'self' can be set with 'setf'.  Note that '(second NIL)' = NULL.
  { Cons* self = this;

    return (self->rest->value);
  }
}

Object* Cons::third() {
  // Return the third element of 'self'.  The third element
  // of 'self' can be set with 'setf'.  Note that '(third NIL)' = NULL.
  { Cons* self = this;

    return (self->rest->rest->value);
  }
}

Object* Cons::fourth() {
  // Return the fourth element of 'self'.  The fourth element
  // of 'self' can be set with 'setf'.  Note that '(fourth NIL)' = NULL.
  { Cons* self = this;

    return (self->rest->rest->rest->value);
  }
}

Object* Cons::fifth() {
  // Return the fifth element of 'self'.  The fifth element
  // of 'self' can be set with 'setf'.  Note, that '(fifth NIL)' = NULL.
  { Cons* self = this;

    return (self->rest->rest->rest->rest->value);
  }
}

Object* Cons::nth(int position) {
  // Return the element of 'self' at 'position'.  The nth element
  // of 'self' can be set with 'setf'.  Note, that '(nth NIL <pos>)' = NULL.
  { Cons* self = this;

    { int i = -1;

      { Object* value = NULL;
        Cons* iter_001 = self;

        while (!nilP(iter_001)) {
          {
            value = iter_001->value;
            iter_001 = iter_001->rest;
          }
          if ((i = i + 1) == position) {
            return (value);
          }
        }
      }
      return (NULL);
    }
  }
}

Cons* Cons::nth_rest(int position) {
  // Apply 'rest' 'position' times to 'self'.
  { Cons* self = this;

    if (position < 0) {
      return (NULL);
    }
    { Cons* cursor = self;

      { int i = NULL_INTEGER;
        int iter_001 = 1;
        int upper_bound_001 = position;
        boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

        while (unboundedP_001 ||
            (iter_001 <= upper_bound_001)) {
          {
            i = iter_001;
            iter_001 = iter_001 + 1;
          }
          cursor = cursor->rest;
          if (cursor->emptyP()) {
            return (NIL);
          }
        }
      }
      return (cursor);
    }
  }
}

Cons* last_cons(Cons* self) {
  // Return the last cons of 'self'.
  while (!(self->rest == NIL)) {
    self = self->rest;
  }
  return (self);
}

Object* Cons::last() {
  // Return the last element of 'self'.
  { Cons* self = this;

    return (last_cons(self)->value);
  }
}

Object* Cons::first_setter(Object* value) {
  { Cons* self = this;

    if (self->emptyP()) {
      cerr << "Can't apply first setter to empty list.";
      return (NULL);
    }
    return (self->value = value);
  }
}

Object* Cons::second_setter(Object* value) {
  { Cons* self = this;

    if (self->rest->emptyP()) {
      cerr << "'second setter' applied to too short cons list.";
      return (NULL);
    }
    return (self->rest->value = value);
  }
}

Object* Cons::third_setter(Object* value) {
  { Cons* self = this;

    { Cons* thirdcons = self->rest->rest;

      if (thirdcons->non_emptyP()) {
        return (thirdcons->value = value);
      }
      else {
        {
          cerr << "'third setter' applied to too short cons list.";
          return (NULL);
        }
      }
    }
  }
}

Object* Cons::nth_setter(Object* value, int position) {
  { Cons* self = this;

    if (position < 0) {
      cerr << "Can't apply nth setter to negative position " << "`" << position << "'" << ".";
      return (NULL);
    }
    { Cons* cursor = self;

      { int i = NULL_INTEGER;
        int iter_001 = 1;
        int upper_bound_001 = position;
        boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

        while (unboundedP_001 ||
            (iter_001 <= upper_bound_001)) {
          {
            i = iter_001;
            iter_001 = iter_001 + 1;
          }
          i = i;
          cursor = cursor->rest;
          if (cursor->emptyP()) {
            cerr << "'nth setter' ran off end of cons list.";
            return (NULL);
          }
        }
      }
      cursor->value = value;
      return (value);
    }
  }
}

Object* Cons::fourth_setter(Object* value) {
  { Cons* self = this;

    return (self->nth_setter(value, 3));
  }
}

Object* Cons::fifth_setter(Object* value) {
  { Cons* self = this;

    return (self->nth_setter(value, 4));
  }
}

Object* Cons::nth_rest_setter(Object* value, int position) {
  { Cons* self = this;

    if (position <= 0) {
      cerr << "Can't apply nth-rest setter to negative position " << "`" << position << "'" << ".";
    }
    { Cons* cursor = self;

      { int i = NULL_INTEGER;
        int iter_001 = 2;
        int upper_bound_001 = position;
        boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

        while (unboundedP_001 ||
            (iter_001 <= upper_bound_001)) {
          {
            i = iter_001;
            iter_001 = iter_001 + 1;
          }
          cursor = cursor->rest;
          if (cursor->emptyP()) {
            cerr << "'nth-rest setter' ran off end of cons list.";
            return (NULL);
          }
        }
      }
      cursor->rest = ((Cons*)(value));
      return (value);
    }
  }
}

Cons_Iterator* Cons::allocate_iterator() {
  { Cons* self = this;

    { Cons_Iterator* iterator = new_cons_iterator();

      iterator->cons_iterator_cursor = self;
      iterator->first_iterationP = TRUE;
      return (iterator);
    }
  }
}

boolean terminate_cons_iteratorP(Cons_Iterator* self) {
  self->cons_iterator_cursor = NULL;
  return (TRUE);
}

boolean Cons_Iterator::nextP() {
  { Cons_Iterator* self = this;

    if (self->first_iterationP) {
      self->first_iterationP = FALSE;
    }
    else {
      self->cons_iterator_cursor = self->cons_iterator_cursor->rest;
    }
    self->value = self->cons_iterator_cursor->value;
    return (self->cons_iterator_cursor->non_emptyP());
  }
}

boolean Cons_Iterator::emptyP() {
  { Cons_Iterator* self = this;

    return (nilP(self->cons_iterator_cursor));
  }
}

Object* Cons_Iterator::value_setter(Object* value) {
  { Cons_Iterator* self = this;

    return (self->cons_iterator_cursor->value = value);
  }
}

void add_cons_to_end_of_cons_list(Cons* self, Cons* lastcons) {
  while (self->rest->non_emptyP()) {
    self = self->rest;
  }
  self->rest = lastcons;
}

boolean but_last_nextP(All_Purpose_Iterator* self) {
  if (self->first_iterationP) {
    self->first_iterationP = FALSE;
  }
  else {
    self->iterator_cons_list = self->iterator_cons_list->rest;
  }
  if (nilP(self->iterator_cons_list->rest)) {
    return (FALSE);
  }
  self->value = self->iterator_cons_list->value;
  return (TRUE);
}

Iterator* Cons::but_last() {
  // Generate all but the last element of the cons list 'self'.
  { Cons* self = this;

    { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

      iterator->iterator_cons_list = self;
      iterator->first_iterationP = TRUE;
      iterator->iterator_next_code = ((cpp_function_code)(&but_last_nextP));
      return (iterator);
    }
  }
}

void Transient_Cons::free_cons() {
  { Transient_Cons* self = this;

    self->free();
  }
}

Cons* transient_cons(Object* value, Object* rest) {
  // Return a transient cons record that points to 'value' and
  // 'rest'.
  { Transient_Cons* cons = new_transient_cons();

    cons->value = value;
    cons->rest = ((Cons*)(rest));
    return (cons);
  }
}

Cons* yield_cons_list_of(Object* self) {
  // If 'object' is a CONS, return it.  Otherwise, return
  // a singleton cons list containing it.
  return (((Cons*)((consP(self) ? ((Object*)(self)) : ((Object*)(cons(self, NIL)))))));
}

Cons* copy_cons_list(Cons* self) {
  // Return a copy of the cons list 'self'.
  if (self->emptyP()) {
    return (NIL);
  }
  { Cons* newconslist = cons(self->value, NIL);
    Cons* nextcons = newconslist;
    Cons* copyfromcons = NULL;
    Cons* previouscons = NULL;

    copyfromcons = self->rest;
    while (copyfromcons->non_emptyP()) {
      previouscons = nextcons;
      nextcons = cons(copyfromcons->value, NIL);
      previouscons->rest = nextcons;
      copyfromcons = copyfromcons->rest;
    }
    return (newconslist);
  }
}

Cons* permanent_copy_cons_list(Cons* self) {
  // Return a permanent copy of the cons list 'self'.
  if (self->emptyP()) {
    return (NIL);
  }
  { Cons* newconslist = permanent_cons(self->value, NIL);
    Cons* nextcons = newconslist;
    Cons* copyfromcons = NULL;
    Cons* previouscons = NULL;

    copyfromcons = self->rest;
    while (copyfromcons->non_emptyP()) {
      previouscons = nextcons;
      nextcons = permanent_cons(copyfromcons->value, NIL);
      previouscons->rest = nextcons;
      copyfromcons = copyfromcons->rest;
    }
    return (newconslist);
  }
}

Cons* cons_list(int values, ...) {
  // Return a cons list containing 'values', in order.
  { Cons* list = NIL;

    { va_list ap;
      Object* v;
      Cons* collect_001 = NULL;

      va_start(ap, values);
      while (values > 0) {
        v = va_arg(ap, Object*);
        values = values - 1;
        if (collect_001 == NULL) {
          {
            collect_001 = cons(v, NIL);
            if (nilP(list)) {
              list = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(list, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(v, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
      va_end(ap);
    }
    return (list);
  }
}

Cons* listO(int values, ...) {
  // Return a list of conses that make up the list 'values',
  // terminated by the last value rather than by NIL.  Assumes that
  // at least one value is passed in.
  { Cons* headcons = NIL;
    Object* answer = NULL;
    Cons* lastcons = NULL;

    { va_list ap;
      Object* v;

      va_start(ap, values);
      while (values > 0) {
        v = va_arg(ap, Object*);
        values = values - 1;
        headcons = cons(v, headcons);
      }
      va_end(ap);
    }
    answer = headcons->rest->reverse();
    if (nilP(answer)) {
      answer = headcons->value;
      headcons->free_cons();
      return (((Cons*)(answer)));
    }
    lastcons = ((Cons*)(answer));
    while (lastcons->rest->non_emptyP()) {
      lastcons = lastcons->rest;
    }
    lastcons->rest = ((Cons*)(headcons->value));
    headcons->free_cons();
    return (((Cons*)(answer)));
  }
}

Cons* append(Cons* conslist1, Cons* conslist2) {
  // Return a transient cons list representing the concatenation
  // of 'consList1' and 'consList2'.  The concatenation is NOT destructive.
  if (conslist1->emptyP()) {
    return (conslist2);
  }
  else if (conslist2->emptyP()) {
    return (conslist1);
  }
  else {
    return (cons(conslist1->value, append(conslist1->rest, conslist2)));
  }
}

Cons* Cons::sort(cpp_function_code predicate) {
  // Perform a stable, destructive sort of 'self' according to
  // 'predicate', and return the result.  If 'predicate' has a '<' semantics, the
  // result will be in ascending order.  It is not guaranteed that 'self' will
  // point to the beginning of the sorted result.  If 'predicate' is NULL, a
  // suitable '<' predicate is chosen depending on the first element of 'self',
  // and it is assumed that all elements of 'self' have the same type (supported
  // element types are GENERALIZED-SYMBOL, STRING, INTEGER, and FLOAT).
  { Cons* self = this;

    if (predicate == NULL) {
      predicate = choose_sort_predicate(self);
    }
    return (help_sort_cons_list(self, self->length(), predicate));
  }
}

Cons* help_sort_cons_list(Cons* list, int length, cpp_function_code predicate) {
  if (length < 2) {
    return (list);
  }
  { int frontlength = floor_(length / 2.0);
    Cons* temp = list;
    Cons* back = NIL;

    { int i = NULL_INTEGER;
      int iter_001 = 2;
      int upper_bound_001 = frontlength;
      boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

      while (unboundedP_001 ||
          (iter_001 <= upper_bound_001)) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        temp = temp->rest;
      }
    }
    back = temp->rest;
    temp->rest = NIL;
    return (merge_cons_lists(help_sort_cons_list(list, frontlength, predicate), help_sort_cons_list(back, length - frontlength, predicate), predicate));
  }
}

Cons* merge_cons_lists(Cons* list1, Cons* list2, cpp_function_code predicate) {
  { Cons* cursor1 = list1;
    Cons* cursor2 = list2;
    Cons* result = NIL;
    Cons* tail = NIL;
    Cons* temp = NIL;

    for (;;) {
      if (cursor1 == NIL) {
        if (tail == NIL) {
          return (cursor2);
        }
        tail->rest = cursor2;
        return (result);
      }
      if (cursor2 == NIL) {
        if (tail == NIL) {
          return (cursor1);
        }
        tail->rest = cursor1;
        return (result);
      }
      if (((boolean (*) (Object*, Object*))predicate)(cursor2->value, cursor1->value)) {
        temp = cursor2;
        cursor2 = cursor2->rest;
        list2 = cursor2;
      }
      else {
        temp = cursor1;
        cursor1 = cursor1->rest;
        list1 = cursor1;
      }
      if (tail == NIL) {
        result = temp;
      }
      else {
        tail->rest = temp;
      }
      tail = temp;
    }
  }
}

boolean generalized_symbol_less_thanP(Generalized_Symbol* x, Generalized_Symbol* y) {
  return (stringL(x->symbol_name, y->symbol_name));
}

boolean wrapped_integer_less_thanP(Integer_Wrapper* x, Integer_Wrapper* y) {
  return (x->wrapper_value < y->wrapper_value);
}

boolean wrapped_float_less_thanP(Float_Wrapper* x, Float_Wrapper* y) {
  return (x->wrapper_value < y->wrapper_value);
}

boolean wrapped_string_less_thanP(String_Wrapper* x, String_Wrapper* y) {
  return (stringL(x->wrapper_value, y->wrapper_value));
}

cpp_function_code choose_sort_predicate(Cons* self) {
  { Object* firstelement = self->value;

    if (firstelement == NULL) {
      return (NULL);
    }
    { Object* firstelement_001 = firstelement;

      if (taxonomy_isaP(firstelement, SGT_CONSES_GENERALIZED_SYMBOL)) {
        { Generalized_Symbol* firstelement = NULL;

          firstelement = ((Generalized_Symbol*)(firstelement_001));
          return (((cpp_function_code)(&generalized_symbol_less_thanP)));
        }
      }
      else if (integerP(firstelement)) {
        { Integer_Wrapper* firstelement = NULL;

          firstelement = ((Integer_Wrapper*)(firstelement_001));
          return (((cpp_function_code)(&wrapped_integer_less_thanP)));
        }
      }
      else if (floatP(firstelement)) {
        { Float_Wrapper* firstelement = NULL;

          firstelement = ((Float_Wrapper*)(firstelement_001));
          return (((cpp_function_code)(&wrapped_float_less_thanP)));
        }
      }
      else if (stringP(firstelement)) {
        { String_Wrapper* firstelement = NULL;

          firstelement = ((String_Wrapper*)(firstelement_001));
          return (((cpp_function_code)(&wrapped_string_less_thanP)));
        }
      }
      else {
        cerr << "choose-sort-predicate: Don't know how to sort " << "`" << firstelement->primary_type() << "'" << "s";
      }
    }
  }
}

boolean search_cons_treeP(Object* tree, Object* value) {
  // Return TRUE iff the value 'value' is embedded within
  // the cons tree 'tree'.  Uses an 'eql?' test.
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        if (nilP(tree)) {
          return (nilP(value));
        }
        else {
          return (search_cons_treeP(tree->value, value) ||
              search_cons_treeP(tree->rest, value));
        }
      }
    }
    else {
      return (eqlP(tree, value));
    }
  }
}

Object* copy_cons_tree(Object* self) {
  { Object* self_001 = self;

    if (consP(self)) {
      { Cons* self = NULL;

        self = ((Cons*)(self_001));
        if (nilP(self)) {
          return (NIL);
        }
        else {
          return (cons(copy_cons_tree(self->value), ((Cons*)(copy_cons_tree(self->rest)))));
        }
      }
    }
    else {
      return (self);
    }
  }
}

void free_cons_tree(Object* self) {
  { Object* self_001 = self;

    if (consP(self)) {
      { Cons* self = NULL;

        self = ((Cons*)(self_001));
        if (!nilP(self)) {
          free_cons_tree(self->value);
          free_cons_tree(self->rest);
          self->free_cons();
        }
      }
    }
    else {
    }
  }
}

boolean equal_cons_treesP(Object* tree1, Object* tree2) {
  // Return TRUE iff the cons trees 'tree1' and 'tree2' are
  // structurally equivalent.  Uses an 'eql?' test.
  if (eqlP(tree1, tree2)) {
    return (TRUE);
  }
  else {
    { Object* tree1_001 = tree1;

      if (consP(tree1)) {
        { Cons* tree1 = NULL;

          tree1 = ((Cons*)(tree1_001));
          { Object* tree2_001 = tree2;

            if (consP(tree2)) {
              { Cons* tree2 = NULL;

                tree2 = ((Cons*)(tree2_001));
                return (equal_cons_treesP(tree1->value, tree2->value) &&
                    equal_cons_treesP(tree1->rest, tree2->rest));
              }
            }
            else {
              return (FALSE);
            }
          }
        }
      }
      else {
        return (FALSE);
      }
    }
  }
}

Object* substitute_cons_tree(Object* tree, Object* newvalue, Object* oldvalue) {
  // Destructively replace each appearance of 'oldValue' by
  // 'newValue' in the cons tree 'tree'.  Return the tree.  Uses an 'eql?' test.
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        if (!nilP(tree)) {
          if (eqlP(tree->value, oldvalue)) {
            tree->value = newvalue;
          }
          else {
            substitute_cons_tree(tree->value, newvalue, oldvalue);
          }
          substitute_cons_tree(tree->rest, newvalue, oldvalue);
        }
      }
    }
    else {
    }
  }
  return (tree);
}

void Cons::free_parse_tree() {
  { Cons* self = this;

    if (!nilP(self)) {
      cout << "Permanent cons found while freeing parse tree:" << endl;
      if (tree_size(self) < 10) {
        cout << endl << "`" << self << "'" << endl;
      }
      else {
        cout << "Tree size = " << "`" << tree_size(self) << "'" << endl;
      }
    }
  }
}

void Transient_Cons::free_parse_tree() {
  { Transient_Cons* self = this;

    if (!(self->value == NULL)) {
      self->value->free_parse_tree();
    }
    self->rest->free_parse_tree();
    self->free_cons();
  }
}

void Object::free_parse_tree() {
  { Object* self = this;

  }
}

void Wrapper::free_parse_tree() {
  { Wrapper* self = this;

  }
}

void Transient_Integer_Wrapper::free_parse_tree() {
  { Transient_Integer_Wrapper* self = this;

    self->free();
  }
}

void Transient_Float_Wrapper::free_parse_tree() {
  { Transient_Float_Wrapper* self = this;

    self->free();
  }
}

void Transient_String_Wrapper::free_parse_tree() {
  { Transient_String_Wrapper* self = this;

    self->free();
  }
}

void Transient_Character_Wrapper::free_parse_tree() {
  { Transient_Character_Wrapper* self = this;

    self->free();
  }
}

void Transient_Function_Code_Wrapper::free_parse_tree() {
  { Transient_Function_Code_Wrapper* self = this;

    self->free();
  }
}

void Transient_Method_Code_Wrapper::free_parse_tree() {
  { Transient_Method_Code_Wrapper* self = this;

    self->free();
  }
}

void Transient_Symbol::free_parse_tree() {
  { Transient_Symbol* self = this;

    self->free();
  }
}

void Transient_Keyword::free_parse_tree() {
  { Transient_Keyword* self = this;

    self->free();
  }
}

boolean read_OprintprettyPO() {
  return (oPRINTPRETTYpo);
}

boolean write_OprintprettyPO(boolean value) {
  oPRINTPRETTYpo = value;
  return (value);
}

boolean read_OprintreadablyPO() {
  return (oPRINTREADABLYpo);
}

boolean write_OprintreadablyPO(boolean value) {
  oPRINTREADABLYpo = value;
  return (value);
}

void print_cons(Cons* tree, ostream* stream, char* lparen, char* rparen) {
  if (oPRINTREADABLYpo) {
    lparen = "(";
    rparen = ")";
  }
  if (oPRINTPRETTYpo) {
    pprint_cons(tree, stream, lparen, rparen);
    return;
  }
  *(stream) << lparen;
  if (!(tree->emptyP())) {
    *(stream) << tree->value;
    { Object* element = NULL;
      Cons* iter_001 = tree->rest;

      while (!nilP(iter_001)) {
        {
          element = iter_001->value;
          iter_001 = iter_001->rest;
        }
        *(stream) << " " << element;
      }
    }
  }
  *(stream) << rparen;
}

void pprint_cons(Cons* tree, ostream* stream, char* lparen, char* rparen) {
  { boolean old_OprintprettyPO_001 = oPRINTPRETTYpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRINTPRETTYpo = FALSE;
          print_cons(tree, stream, lparen, rparen);
          oPRINTPRETTYpo = old_OprintprettyPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPRINTPRETTYpo = old_OprintprettyPO_001;
        resignal();
      }
    }
  }
}

boolean read_OprintprettycodePO() {
  return (oPRINTPRETTYCODEpo);
}

boolean write_OprintprettycodePO(boolean value) {
  oPRINTPRETTYCODEpo = value;
  return (value);
}

void print_stella_code(Object* tree, ostream* stream) {
  { boolean old_OprintprettyPO_001 = oPRINTPRETTYpo;
    boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRINTPRETTYpo = oPRINTPRETTYCODEpo;
          oPRINTREADABLYpo = TRUE;
          *(stream) << tree << endl;
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
          oPRINTPRETTYpo = old_OprintprettyPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPRINTREADABLYpo = old_OprintreadablyPO_001;
        oPRINTPRETTYpo = old_OprintprettyPO_001;
        resignal();
      }
    }
  }
}

void print_stella_definition(Object* tree, ostream* stream) {
  { boolean old_OprintprettyPO_001 = oPRINTPRETTYpo;
    boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRINTPRETTYpo = oPRINTPRETTYCODEpo;
          oPRINTREADABLYpo = TRUE;
          { Object* tree_001 = tree;

            if (consP(tree)) {
              { Cons* tree = NULL;

                tree = ((Cons*)(tree_001));
                if (tree->length() >= 3) {
                  oPRINTPRETTYpo = FALSE;
                  *(stream) << "(" << tree->first() << " " << tree->second() << " " << tree->third();
                  oPRINTPRETTYpo = oPRINTPRETTYCODEpo;
                  { Object* form = NULL;
                    Cons* iter_001 = tree->nth_rest(3);

                    while (!nilP(iter_001)) {
                      {
                        form = iter_001->value;
                        iter_001 = iter_001->rest;
                      }
                      *(stream) << endl << "  " << form;
                    }
                  }
                  *(stream) << ")";
                }
                else {
                  *(stream) << tree;
                }
              }
            }
            else {
              *(stream) << tree;
            }
          }
          *(stream) << endl;
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
          oPRINTPRETTYpo = old_OprintprettyPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPRINTREADABLYpo = old_OprintreadablyPO_001;
        oPRINTPRETTYpo = old_OprintprettyPO_001;
        resignal();
      }
    }
  }
}

int tree_size(Object* self) {
  { Object* self_001 = self;

    if (consP(self)) {
      { Cons* self = NULL;

        self = ((Cons*)(self_001));
        if (nilP(self)) {
          return (0);
        }
        else {
          return (1 + (tree_size(self->value) + tree_size(self->rest)));
        }
      }
    }
    else {
      return (0);
    }
  }
}

boolean read_OdepthexceededPO() {
  return (oDEPTHEXCEEDEDpo);
}

boolean write_OdepthexceededPO(boolean value) {
  oDEPTHEXCEEDEDpo = value;
  return (value);
}

int safely_compute_tree_size(Cons* tree, int depthcount, int cutoff) {
  { int count = 1;
    Object* value = NULL;

    if (depthcount > oDEPTHCUTOFFo) {
      oDEPTHEXCEEDEDpo = TRUE;
      return (1);
    }
    for (;;) {
      value = tree->value;
      if (consP(value)) {
        count = count + safely_compute_tree_size(((Cons*)(tree->value)), depthcount + 1, cutoff);
      }
      if ((tree->rest == NULL) ||
          (nilP(tree->rest) ||
           (count > cutoff))) {
        return (count);
      }
      tree = tree->rest;
    }
  }
}

int safe_tree_size(Cons* tree, char*& return1) {
  { boolean old_OdepthexceededPO_001 = oDEPTHEXCEEDEDpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oDEPTHEXCEEDEDpo = FALSE;
          { int cutoff = 99;
            int size = safely_compute_tree_size(tree, 0, cutoff);

            { char* return_value_001 = ((oDEPTHEXCEEDEDpo ||
                  (size >= cutoff)) ? ((char*)("CIRCULAR")) : ((char*)("OK")));

              oDEPTHEXCEEDEDpo = old_OdepthexceededPO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              { int return_temp = size;

                return1 = return_value_001;
                return (return_temp);
              }
            }
          }
          oDEPTHEXCEEDEDpo = old_OdepthexceededPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oDEPTHEXCEEDEDpo = old_OdepthexceededPO_001;
        resignal();
      }
    }
  }
}

void startup_conses() {
  if (current_startup_time_phaseP(0)) {
    if (!(NIL != NULL)) {
      NIL = new Cons;
    }
    NIL->value = NULL;
    NIL->rest = NIL;
  }
  { Module* old_OmoduleO_001 = oMODULEo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = oSTELLA_MODULEo;
          oCONTEXTo = oMODULEo;
          if (current_startup_time_phaseP(2)) {
            SGT_CONSES_ABSTRACT_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("ABSTRACT-ITERATOR", NULL, 1)));
            SYM_CONSES_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE", NULL, 0)));
            SYM_CONSES_VALUE_SETTER = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE-SETTER", NULL, 0)));
            SYM_CONSES_SLOT_WRITER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-WRITER", NULL, 0)));
            SGT_CONSES_GENERALIZED_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("GENERALIZED-SYMBOL", NULL, 1)));
            SYM_CONSES_oPRINTPRETTYpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PRINTPRETTY?*", NULL, 0)));
            SYM_CONSES_oPRINTREADABLYpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PRINTREADABLY?*", NULL, 0)));
            SYM_CONSES_oPRINTPRETTYCODEpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PRINTPRETTYCODE?*", NULL, 0)));
            SYM_CONSES_oDEPTHEXCEEDEDpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*DEPTHEXCEEDED?*", NULL, 0)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("EMPTY?", "CONS", "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF CONS)) :DOCUMENTATION \"Return TRUE iff 'self' equals NIL.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NON-EMPTY?", "CONS", "(DEFMETHOD (NON-EMPTY? BOOLEAN) ((SELF CONS)) :DOCUMENTATION \"Return TRUE iff 'self' is not equal to NIL.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::non_emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NIL?", "OBJECT", "(DEFUN (NIL? BOOLEAN) ((X OBJECT)) :DOCUMENTATION \"Return TRUE iff 'x' equals NIL.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&nilP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-CONS", "CONS", "(DEFMETHOD FREE-CONS ((SELF CONS)))");

              method->method_code = ((cpp_method_code)(&Cons::free_cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-CONS-LIST", "CONS", "(DEFUN FREE-CONS-LIST ((SELF CONS)))");

              method->function_code = ((cpp_function_code)(&free_cons_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("LENGTH", "CONS", "(DEFMETHOD (LENGTH INTEGER) ((SELF CONS)) :DOCUMENTATION \"Return the length of the CONS list 'self'.  CAUTION: Breaks if\n'self' is not the head of a CONS list.\")");

              method->method_code = ((cpp_method_code)(&Cons::length));
            }
            { Method_Slot* method = define_method_from_stringified_source("POSITION", "CONS", "(DEFMETHOD (POSITION INTEGER) ((SELF CONS) (OBJECT OBJECT) (START INTEGER)) :DOCUMENTATION \"Return the position of 'object' within the cons-list\n'self' (counting from zero); or return NULL if 'object' does not occur within \n'self' (uses an 'eql?' test).  If 'start' was supplied as non-NULL, only \nconsider the sublist starting at 'start', however, the returned position \nwill always be relative to the entire list.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::position));
            }
            { Method_Slot* method = define_method_from_stringified_source("MEMBER?", "CONS", "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF CONS) (OBJECT OBJECT)) :DOCUMENTATION \"Return TRUE iff 'object' is a member of the cons list\n'self' (uses an 'eql?' test).\")");

              method->method_code = ((cpp_method_code)(&Cons::memberP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MEMB?", "CONS", "(DEFMETHOD (MEMB? BOOLEAN) ((SELF CONS) (OBJECT OBJECT)) :DOCUMENTATION \"Return TRUE iff 'object' is a member of the cons list\n'self' (uses an 'eq?' test).\")");

              method->method_code = ((cpp_method_code)(&Cons::membP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONS", "OBJECT", "(DEFUN (CONS CONS) ((VALUE OBJECT) (REST CONS)) :DOCUMENTATION \"Return a cons record that points to 'value' and 'rest'.\")");

              method->function_code = ((cpp_function_code)(&cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENT-CONS", "OBJECT", "(DEFUN (PERMANENT-CONS CONS) ((VALUE OBJECT) (REST CONS)) :DOCUMENTATION \"Return a permanent cons record that points to 'value' and 'rest'.\")");

              method->function_code = ((cpp_function_code)(&permanent_cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOCAL-CONS", "OBJECT", "(DEFUN (LOCAL-CONS CONS) ((VALUE OBJECT) (REST CONS)) :DOCUMENTATION \"Return local cons record that points to 'value' and 'rest'.\")");

              method->function_code = ((cpp_function_code)(&local_cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE", "CONS", "(DEFMETHOD (REMOVE CONS) ((SELF CONS) (VALUE OBJECT)) :DOCUMENTATION \"Remove all entries in the cons list 'self' that match\n'value'.  Unless the remaining list is NIL, insure that the cons that\nheads the list is unchanged.\")");

              method->method_code = ((cpp_method_code)(&Cons::remove));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-DUPLICATES", "CONS", "(DEFMETHOD (REMOVE-DUPLICATES CONS) ((SELF CONS)) :DOCUMENTATION \"Remove duplicates from the cons list 'self' and return\n'self'. Removes all but the first occurrence of items in the list.\nPreserves the original order of the remaining members.  Runs in quadratic\ntime.\")");

              method->method_code = ((cpp_method_code)(&Cons::remove_duplicates));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONCATENATE", "CONS", "(DEFMETHOD (CONCATENATE CONS) ((SELF CONS) (LIST2 CONS)) :DOCUMENTATION \"Return a cons list consisting of the concatenation of 'self' and\n'list2'.    The operation is destructive wrt 'self', but leaves 'list2'\nintact.  CAUTION:  This operation results in structure sharing\nof 'list2'; to avoid this, 'list2' should not be pointed to by anything\nother than the tail of 'self'.\")");

              method->method_code = ((cpp_method_code)(&Cons::concatenate));
            }
            { Method_Slot* method = define_method_from_stringified_source("PREPEND", "CONS", "(DEFMETHOD (PREPEND CONS) ((SELF CONS) (LIST1 CONS)) :DOCUMENTATION \"Return a cons list consisting of the concatenation of\n'list1' and 'self'.  A copy of 'list1' is prepended to 'self'.  This\noperation results in structure sharing of 'self'; to avoid this, 'self'\nshould not be pointed to by anything other than the tail of the prepended\ncopy.\")");

              method->method_code = ((cpp_method_code)(&Cons::prepend));
            }
            { Method_Slot* method = define_method_from_stringified_source("REVERSE", "CONS", "(DEFMETHOD (REVERSE (LIKE SELF)) ((SELF CONS)) :DOCUMENTATION \"Destructively reverse the members of the cons list 'self'.\")");

              method->method_code = ((cpp_method_code)(&Cons::reverse));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBSTITUTE", "CONS", "(DEFMETHOD (SUBSTITUTE CONS) ((SELF CONS) (INVALUE OBJECT) (OUTVALUE OBJECT)) :DOCUMENTATION \"Destructively replace each appearance of 'outValue' by\n'inValue' in the cons list 'self'.\")");

              method->method_code = ((cpp_method_code)(&Cons::substitute));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIRST", "CONS", "(DEFMETHOD (FIRST (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the first element of 'self'.  The first element\nof 'self' can be set with 'setf'.  Note that '(first NIL)' = NULL.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::first));
            }
            { Method_Slot* method = define_method_from_stringified_source("SECOND", "CONS", "(DEFMETHOD (SECOND (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the second element of 'self'.  The second element\nof 'self' can be set with 'setf'.  Note that '(second NIL)' = NULL.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::second));
            }
            { Method_Slot* method = define_method_from_stringified_source("THIRD", "CONS", "(DEFMETHOD (THIRD (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the third element of 'self'.  The third element\nof 'self' can be set with 'setf'.  Note that '(third NIL)' = NULL.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::third));
            }
            { Method_Slot* method = define_method_from_stringified_source("FOURTH", "CONS", "(DEFMETHOD (FOURTH (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the fourth element of 'self'.  The fourth element\nof 'self' can be set with 'setf'.  Note that '(fourth NIL)' = NULL.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::fourth));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIFTH", "CONS", "(DEFMETHOD (FIFTH (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the fifth element of 'self'.  The fifth element\nof 'self' can be set with 'setf'.  Note, that '(fifth NIL)' = NULL.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::fifth));
            }
            { Method_Slot* method = define_method_from_stringified_source("NTH", "CONS", "(DEFMETHOD (NTH (LIKE (ANY-VALUE SELF))) ((SELF CONS) (POSITION INTEGER)) :DOCUMENTATION \"Return the element of 'self' at 'position'.  The nth element\nof 'self' can be set with 'setf'.  Note, that '(nth NIL <pos>)' = NULL.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::nth));
            }
            { Method_Slot* method = define_method_from_stringified_source("NTH-REST", "CONS", "(DEFMETHOD (NTH-REST (LIKE SELF)) ((SELF CONS) (POSITION INTEGER)) :DOCUMENTATION \"Apply 'rest' 'position' times to 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::nth_rest));
            }
            { Method_Slot* method = define_method_from_stringified_source("LAST-CONS", "CONS", "(DEFUN (LAST-CONS (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF CONS)) :DOCUMENTATION \"Return the last cons of 'self'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&last_cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("LAST", "CONS", "(DEFMETHOD (LAST (LIKE (ANY-VALUE SELF))) ((SELF CONS)) :DOCUMENTATION \"Return the last element of 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::last));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIRST-SETTER", "CONS", "(DEFMETHOD (FIRST-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Cons::first_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("SECOND-SETTER", "CONS", "(DEFMETHOD (SECOND-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Cons::second_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("THIRD-SETTER", "CONS", "(DEFMETHOD (THIRD-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Cons::third_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("NTH-SETTER", "CONS", "(DEFMETHOD (NTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE OBJECT) (POSITION INTEGER)))");

              method->method_code = ((cpp_method_code)(&Cons::nth_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("FOURTH-SETTER", "CONS", "(DEFMETHOD (FOURTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Cons::fourth_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIFTH-SETTER", "CONS", "(DEFMETHOD (FIFTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF CONS) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Cons::fifth_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("NTH-REST-SETTER", "CONS", "(DEFMETHOD (NTH-REST-SETTER OBJECT) ((SELF CONS) (VALUE OBJECT) (POSITION INTEGER)))");

              method->method_code = ((cpp_method_code)(&Cons::nth_rest_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-ITERATOR", "CONS", "(DEFMETHOD (ALLOCATE-ITERATOR CONS-ITERATOR) ((SELF CONS)))");

              method->method_code = ((cpp_method_code)(&Cons::allocate_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-CONS-ITERATOR?", "CONS-ITERATOR", "(DEFUN (TERMINATE-CONS-ITERATOR? BOOLEAN) ((SELF CONS-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&terminate_cons_iteratorP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "CONS-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF CONS-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Cons_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EMPTY?", "CONS-ITERATOR", "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF CONS-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Cons_Iterator::emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALUE-SETTER", "CONS-ITERATOR", "(DEFMETHOD (VALUE-SETTER OBJECT) ((SELF CONS-ITERATOR) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Cons_Iterator::value_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-CONS-TO-END-OF-CONS-LIST", "CONS", "(DEFUN ADD-CONS-TO-END-OF-CONS-LIST ((SELF CONS) (LASTCONS CONS)))");

              method->function_code = ((cpp_function_code)(&add_cons_to_end_of_cons_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUT-LAST-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (BUT-LAST-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&but_last_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUT-LAST", "CONS", "(DEFMETHOD (BUT-LAST (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF CONS)) :DOCUMENTATION \"Generate all but the last element of the cons list 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Cons::but_last));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-CONS", "TRANSIENT-CONS", "(DEFMETHOD FREE-CONS ((SELF TRANSIENT-CONS)))");

              method->method_code = ((cpp_method_code)(&Transient_Cons::free_cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSIENT-CONS", "OBJECT", "(DEFUN (TRANSIENT-CONS CONS) ((VALUE OBJECT) (REST OBJECT)) :DOCUMENTATION \"Return a transient cons record that points to 'value' and\n'rest'.\")");

              method->function_code = ((cpp_function_code)(&transient_cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CONS-LIST-OF", "OBJECT", "(DEFUN (YIELD-CONS-LIST-OF CONS) ((SELF OBJECT)) :DOCUMENTATION \"If 'object' is a CONS, return it.  Otherwise, return\na singleton cons list containing it.\")");

              method->function_code = ((cpp_function_code)(&yield_cons_list_of));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-CONS-LIST", "CONS", "(DEFUN (COPY-CONS-LIST (LIKE SELF)) ((SELF CONS)) :DOCUMENTATION \"Return a copy of the cons list 'self'.\")");

              method->function_code = ((cpp_function_code)(&copy_cons_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENT-COPY-CONS-LIST", "CONS", "(DEFUN (PERMANENT-COPY-CONS-LIST (LIKE SELF)) ((SELF CONS)) :DOCUMENTATION \"Return a permanent copy of the cons list 'self'.\")");

              method->function_code = ((cpp_function_code)(&permanent_copy_cons_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONS-LIST", "ARGUMENT-LIST", "(DEFUN (CONS-LIST CONS) (|&REST| (VALUES OBJECT)) :DOCUMENTATION \"Return a cons list containing 'values', in order.\")");

              method->function_code = ((cpp_function_code)(&cons_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("LIST*", "ARGUMENT-LIST", "(DEFUN (LIST* CONS) (|&REST| (VALUES OBJECT)) :DOCUMENTATION \"Return a list of conses that make up the list 'values',\nterminated by the last value rather than by NIL.  Assumes that\nat least one value is passed in.\")");

              method->function_code = ((cpp_function_code)(&listO));
            }
            { Method_Slot* method = define_method_from_stringified_source("APPEND", "CONS", "(DEFUN (APPEND CONS) ((CONSLIST1 CONS) (CONSLIST2 CONS)) :DOCUMENTATION \"Return a transient cons list representing the concatenation\nof 'consList1' and 'consList2'.  The concatenation is NOT destructive.\")");

              method->function_code = ((cpp_function_code)(&append));
            }
            { Method_Slot* method = define_method_from_stringified_source("SORT", "CONS", "(DEFMETHOD (SORT (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF CONS) (PREDICATE FUNCTION-CODE)) :PUBLIC? TRUE :DOCUMENTATION \"Perform a stable, destructive sort of 'self' according to\n'predicate', and return the result.  If 'predicate' has a '<' semantics, the\nresult will be in ascending order.  It is not guaranteed that 'self' will\npoint to the beginning of the sorted result.  If 'predicate' is NULL, a\nsuitable '<' predicate is chosen depending on the first element of 'self',\nand it is assumed that all elements of 'self' have the same type (supported\nelement types are GENERALIZED-SYMBOL, STRING, INTEGER, and FLOAT).\")");

              method->method_code = ((cpp_method_code)(&Cons::sort));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-SORT-CONS-LIST", "CONS", "(DEFUN (HELP-SORT-CONS-LIST CONS) ((LIST CONS) (LENGTH INTEGER) (PREDICATE FUNCTION-CODE)))");

              method->function_code = ((cpp_function_code)(&help_sort_cons_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("MERGE-CONS-LISTS", "CONS", "(DEFUN (MERGE-CONS-LISTS CONS) ((LIST1 CONS) (LIST2 CONS) (PREDICATE FUNCTION-CODE)))");

              method->function_code = ((cpp_function_code)(&merge_cons_lists));
            }
            { Method_Slot* method = define_method_from_stringified_source("GENERALIZED-SYMBOL-LESS-THAN?", "GENERALIZED-SYMBOL", "(DEFUN (GENERALIZED-SYMBOL-LESS-THAN? BOOLEAN) ((X GENERALIZED-SYMBOL) (Y GENERALIZED-SYMBOL)))");

              method->function_code = ((cpp_function_code)(&generalized_symbol_less_thanP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAPPED-INTEGER-LESS-THAN?", "INTEGER-WRAPPER", "(DEFUN (WRAPPED-INTEGER-LESS-THAN? BOOLEAN) ((X INTEGER-WRAPPER) (Y INTEGER-WRAPPER)))");

              method->function_code = ((cpp_function_code)(&wrapped_integer_less_thanP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAPPED-FLOAT-LESS-THAN?", "FLOAT-WRAPPER", "(DEFUN (WRAPPED-FLOAT-LESS-THAN? BOOLEAN) ((X FLOAT-WRAPPER) (Y FLOAT-WRAPPER)))");

              method->function_code = ((cpp_function_code)(&wrapped_float_less_thanP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAPPED-STRING-LESS-THAN?", "STRING-WRAPPER", "(DEFUN (WRAPPED-STRING-LESS-THAN? BOOLEAN) ((X STRING-WRAPPER) (Y STRING-WRAPPER)))");

              method->function_code = ((cpp_function_code)(&wrapped_string_less_thanP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHOOSE-SORT-PREDICATE", "CONS", "(DEFUN (CHOOSE-SORT-PREDICATE FUNCTION-CODE) ((SELF CONS)))");

              method->function_code = ((cpp_function_code)(&choose_sort_predicate));
            }
            { Method_Slot* method = define_method_from_stringified_source("SEARCH-CONS-TREE?", "OBJECT", "(DEFUN (SEARCH-CONS-TREE? BOOLEAN) ((TREE OBJECT) (VALUE OBJECT)) :DOCUMENTATION \"Return TRUE iff the value 'value' is embedded within\nthe cons tree 'tree'.  Uses an 'eql?' test.\")");

              method->function_code = ((cpp_function_code)(&search_cons_treeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-CONS-TREE", "OBJECT", "(DEFUN (COPY-CONS-TREE (LIKE SELF)) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&copy_cons_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-CONS-TREE", "OBJECT", "(DEFUN FREE-CONS-TREE ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&free_cons_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("EQUAL-CONS-TREES?", "OBJECT", "(DEFUN (EQUAL-CONS-TREES? BOOLEAN) ((TREE1 OBJECT) (TREE2 OBJECT)) :DOCUMENTATION \"Return TRUE iff the cons trees 'tree1' and 'tree2' are\nstructurally equivalent.  Uses an 'eql?' test.\")");

              method->function_code = ((cpp_function_code)(&equal_cons_treesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBSTITUTE-CONS-TREE", "OBJECT", "(DEFUN (SUBSTITUTE-CONS-TREE OBJECT) ((TREE OBJECT) (NEWVALUE OBJECT) (OLDVALUE OBJECT)) :DOCUMENTATION \"Destructively replace each appearance of 'oldValue' by\n'newValue' in the cons tree 'tree'.  Return the tree.  Uses an 'eql?' test.\")");

              method->function_code = ((cpp_function_code)(&substitute_cons_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "CONS", "(DEFMETHOD FREE-PARSE-TREE ((SELF CONS)))");

              method->method_code = ((cpp_method_code)(&Cons::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "TRANSIENT-CONS", "(DEFMETHOD FREE-PARSE-TREE ((SELF TRANSIENT-CONS)))");

              method->method_code = ((cpp_method_code)(&Transient_Cons::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "OBJECT", "(DEFMETHOD FREE-PARSE-TREE ((SELF OBJECT)))");

              method->method_code = ((cpp_method_code)(&Object::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "WRAPPER", "(DEFMETHOD FREE-PARSE-TREE ((SELF WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Wrapper::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "TRANSIENT-INTEGER-WRAPPER", "(DEFMETHOD FREE-PARSE-TREE ((SELF TRANSIENT-INTEGER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Transient_Integer_Wrapper::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "TRANSIENT-FLOAT-WRAPPER", "(DEFMETHOD FREE-PARSE-TREE ((SELF TRANSIENT-FLOAT-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Transient_Float_Wrapper::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "TRANSIENT-STRING-WRAPPER", "(DEFMETHOD FREE-PARSE-TREE ((SELF TRANSIENT-STRING-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Transient_String_Wrapper::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "TRANSIENT-CHARACTER-WRAPPER", "(DEFMETHOD FREE-PARSE-TREE ((SELF TRANSIENT-CHARACTER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Transient_Character_Wrapper::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "TRANSIENT-FUNCTION-CODE-WRAPPER", "(DEFMETHOD FREE-PARSE-TREE ((SELF TRANSIENT-FUNCTION-CODE-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Transient_Function_Code_Wrapper::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "TRANSIENT-METHOD-CODE-WRAPPER", "(DEFMETHOD FREE-PARSE-TREE ((SELF TRANSIENT-METHOD-CODE-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Transient_Method_Code_Wrapper::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "TRANSIENT-SYMBOL", "(DEFMETHOD FREE-PARSE-TREE ((SELF TRANSIENT-SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Transient_Symbol::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-PARSE-TREE", "TRANSIENT-KEYWORD", "(DEFMETHOD FREE-PARSE-TREE ((SELF TRANSIENT-KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Transient_Keyword::free_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-CONS", "CONS", "(DEFUN PRINT-CONS ((TREE CONS) (STREAM NATIVE-OUTPUT-STREAM) (LPAREN STRING) (RPAREN STRING)))");

              method->function_code = ((cpp_function_code)(&print_cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("PPRINT-CONS", "CONS", "(DEFUN PPRINT-CONS ((TREE CONS) (STREAM NATIVE-OUTPUT-STREAM) (LPAREN STRING) (RPAREN STRING)))");

              method->function_code = ((cpp_function_code)(&pprint_cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-STELLA-CODE", "OBJECT", "(DEFUN PRINT-STELLA-CODE ((TREE OBJECT) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_stella_code));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-STELLA-DEFINITION", "OBJECT", "(DEFUN PRINT-STELLA-DEFINITION ((TREE OBJECT) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_stella_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("TREE-SIZE", "OBJECT", "(DEFUN (TREE-SIZE INTEGER) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&tree_size));
            }
            { Method_Slot* method = define_method_from_stringified_source("SAFELY-COMPUTE-TREE-SIZE", "CONS", "(DEFUN (SAFELY-COMPUTE-TREE-SIZE INTEGER) ((TREE CONS) (DEPTHCOUNT INTEGER) (CUTOFF INTEGER)))");

              method->function_code = ((cpp_function_code)(&safely_compute_tree_size));
            }
            { Method_Slot* method = define_method_from_stringified_source("SAFE-TREE-SIZE", "CONS", "(DEFUN (SAFE-TREE-SIZE INTEGER STRING) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&safe_tree_size));
            }
            define_method_from_stringified_source("STARTUP-CONSES", NULL, "(DEFUN STARTUP-CONSES ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL NIL CONS NULL)");
            set_dynamic_slot_value(((Storage_Slot*)(lookup_slot(((Class*)(SGT_CONSES_ABSTRACT_ITERATOR->surrogate_value)), SYM_CONSES_VALUE))), SYM_CONSES_SLOT_WRITER, SYM_CONSES_VALUE_SETTER, NULL);
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *PRINTPRETTY?* BOOLEAN TRUE :DOCUMENTATION \"If TRUE conses will be pretty printed.\")");
            { Global_Variable* global = SYM_CONSES_oPRINTPRETTYpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OprintprettyPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OprintprettyPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *PRINTREADABLY?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE conses will be printed as readable Stella code.\")");
            { Global_Variable* global = SYM_CONSES_oPRINTREADABLYpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OprintreadablyPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OprintreadablyPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL ELIPSIS SYMBOL NULL :DOCUMENTATION \"Generates an elipsis '...' when found in a\npretty-printed parse tree.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *PRINTPRETTYCODE?* BOOLEAN TRUE :DOCUMENTATION \"When TRUE pretty-print Stella and translated code.\nSince (Lisp) pretty-printing is somewhat slow, turning this off speeds up\nfile translation, but it also makes translated output very unreadable.\")");
            { Global_Variable* global = SYM_CONSES_oPRINTPRETTYCODEpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OprintprettycodePO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OprintprettycodePO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *DEPTHEXCEEDED?* BOOLEAN FALSE)");
            { Global_Variable* global = SYM_CONSES_oDEPTHEXCEEDEDpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OdepthexceededPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OdepthexceededPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEPTHCUTOFF* INTEGER 33)");
          }
          oCONTEXTo = old_OcontextO_001;
          oMODULEo = old_OmoduleO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oCONTEXTo = old_OcontextO_001;
        oMODULEo = old_OmoduleO_001;
        resignal();
      }
    }
  }
}

