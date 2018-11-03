// lists.cc

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

List* NIL_LIST = NULL;

Surrogate* SGT_LISTS_ABSTRACT_DICTIONARY_ITERATOR = NULL;

Symbol* SYM_LISTS_KEY = NULL;

Symbol* SYM_LISTS_KEY_SETTER = NULL;

Symbol* SYM_LISTS_SLOT_WRITER = NULL;

Surrogate* SGT_LISTS_ABSTRACT_ITERATOR = NULL;

Symbol* SYM_LISTS_VALUE = NULL;

Symbol* SYM_LISTS_VALUE_SETTER = NULL;

Symbol* SYM_LISTS_DELETED_OBJECTp = NULL;

Surrogate* SGT_LISTS_LIST = NULL;

Surrogate* SGT_LISTS_KEY_VALUE_LIST = NULL;

Surrogate* SGT_LISTS_PROPERTY_LIST = NULL;

boolean defined_listP(List* self) {
  // Return TRUE unless 'self' is NULL or the 'NIL-LIST'.
  return ((!(self == NIL_LIST)) &&
      (self != NULL));
}

boolean null_listP(List* self) {
  // Return TRUE iff 'self' is NULL or the 'NIL-LIST'.
  return ((self == NIL_LIST) ||
      (self == NULL));
}

boolean List::emptyP() {
  // Return TRUE if the list 'self' has no members.
  { List* self = this;

    return (self->the_cons_list->emptyP());
  }
}

boolean List::non_emptyP() {
  // Return TRUE if the list 'self' has at least one member.
  { List* self = this;

    return (self->the_cons_list->non_emptyP());
  }
}

boolean terminate_listP(List* self) {
  if (self == NIL_LIST) {
    if (!(!(self == NIL_LIST))) {
      cerr << "Safety violation: " << "Attempt to free NIL-LIST.";
    }
    return (FALSE);
  }
  { Cons* cons = self->the_cons_list;
    Cons* rest = NULL;

    while (cons->non_emptyP()) {
      rest = cons->rest;
      cons->free();
      cons = rest;
    }
    self->the_cons_list = NIL;
    return (TRUE);
  }
}

boolean List::memberP(Object* object) {
  // Return TRUE iff 'object' is a member of the list 'self'.
  //  Uses an 'eql?' test.
  { List* self = this;

    { Object* i = NULL;
      Cons* iter_001 = self->the_cons_list;

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

Object* List::first() {
  // Return the first item in the list 'self', or NULL if empty.
  { List* self = this;

    { Cons* cons = self->the_cons_list;

      return ((cons->non_emptyP() ? ((Object*)(cons->value)) : ((Object*)(NULL))));
    }
  }
}

Object* List::second() {
  // Return the second item in the list 'self', or NULL if empty.
  { List* self = this;

    return (self->the_cons_list->second());
  }
}

Object* List::third() {
  // Return the third item in the list 'self', or NULL if empty.
  { List* self = this;

    return (self->the_cons_list->third());
  }
}

Object* List::fourth() {
  // Return the fourth item in the list 'self', or NULL if empty.
  { List* self = this;

    return (self->the_cons_list->fourth());
  }
}

Object* List::fifth() {
  // Return the fifth item in the list 'self', or NULL if empty.
  { List* self = this;

    return (self->the_cons_list->fifth());
  }
}

Object* List::nth(int position) {
  // Return the nth item in the list 'self', or NULL if empty.
  { List* self = this;

    return (self->the_cons_list->nth(position));
  }
}

Object* List::last() {
  // Return the last element of 'self'.
  { List* self = this;

    return (self->the_cons_list->last());
  }
}

Cons* List::rest() {
  // Return a cons list of all but the first item in the list 'self'.
  { List* self = this;

    return (self->the_cons_list->rest);
  }
}

Object* List::first_setter(Object* value) {
  { List* self = this;

    return (self->the_cons_list->first_setter(value));
  }
}

Object* List::second_setter(Object* value) {
  { List* self = this;

    return (self->the_cons_list->second_setter(value));
  }
}

Object* List::third_setter(Object* value) {
  { List* self = this;

    return (self->the_cons_list->third_setter(value));
  }
}

Object* List::fourth_setter(Object* value) {
  { List* self = this;

    return (self->the_cons_list->fourth_setter(value));
  }
}

Object* List::fifth_setter(Object* value) {
  { List* self = this;

    return (self->the_cons_list->fifth_setter(value));
  }
}

Object* List::nth_setter(Object* value, int position) {
  { List* self = this;

    return (self->the_cons_list->nth_setter(value, position));
  }
}

int List::length() {
  { List* self = this;

    // inline method
    return (self->the_cons_list->length());
  }
}

int List::position(Object* object, int start) {
  // Return the position of 'object' within the list
  // 'self' (counting from zero); or return NULL if 'object' does not occur within 
  // 'self' (uses an 'eql?' test).  If 'start' was supplied as non-NULL, only 
  // consider the sublist starting at 'start', however, the returned position 
  // will always be relative to the entire list.
  { List* self = this;

    return (self->the_cons_list->position(object, start));
  }
}

void List::insert(Object* value) {
  // Add 'value' to the front of the list 'self'.
  { List* self = this;

    if (!(!(self == NIL_LIST))) {
      cerr << "Safety violation: " << "Attempt to insert into NIL-LIST.";
    }
    self->the_cons_list = permanent_cons(value, self->the_cons_list);
  }
}

void List::push(Object* value) {
  // Add 'value' to the front of the list 'self'.
  { List* self = this;

    if (!(!(self == NIL_LIST))) {
      cerr << "Safety violation: " << "Attempt to insert into NIL-LIST.";
    }
    self->the_cons_list = permanent_cons(value, self->the_cons_list);
  }
}

void List::insert_new(Object* value) {
  // Add 'value' to the front of the list 'self' unless its 
  // already a member.
  { List* self = this;

    if (!(!(self == NIL_LIST))) {
      cerr << "Safety violation: " << "Attempt to insert into NIL-LIST.";
    }
    if (!self->the_cons_list->memberP(value)) {
      self->the_cons_list = permanent_cons(value, self->the_cons_list);
    }
  }
}

void List::insert_last(Object* value) {
  // Insert 'value' as the last entry in the list 'self'.
  { List* self = this;

    if (!(!(self == NIL_LIST))) {
      cerr << "Safety violation: " << "Attempt to insert into NIL-LIST.";
    }
    { Cons* cursor = self->the_cons_list;
      Cons* lastcons = permanent_cons(value, NIL);

      if (cursor->emptyP()) {
        self->the_cons_list = lastcons;
      }
      else {
        {
          while (cursor->rest->non_emptyP()) {
            cursor = cursor->rest;
          }
          cursor->rest = lastcons;
        }
      }
    }
  }
}

Abstract_Collection* List::remove(Object* value) {
  // Remove all entries in 'self' that match 'value'.
  { List* self = this;

    self->the_cons_list = self->the_cons_list->remove(value);
    return (self);
  }
}

List* List::remove_if(cpp_function_code testP) {
  // Remove all members of the list 'self' for which 'test?'
  // evaluates to TRUE.  'test' takes a single argument of type OBJECT and
  // returns TRUE or FALSE.  Returns 'self'.
  { List* self = this;

    { Cons* cursor = self->the_cons_list;
      Cons* trailer = NULL;

      while (!(cursor == NIL)) {
        if (((boolean (*) (Object*))testP)(cursor->value) &&
            (trailer != NULL)) {
          {
            trailer->rest = cursor->rest;
            cursor->free_cons();
            cursor = trailer->rest;
          }
        }
        else {
          {
            trailer = cursor;
            cursor = cursor->rest;
          }
        }
      }
      cursor = self->the_cons_list;
      if (cursor->non_emptyP() &&
          ((boolean (*) (Object*))testP)(cursor->value)) {
        self->the_cons_list = cursor->rest;
        cursor->free_cons();
      }
      return (self);
    }
  }
}

List* List::remove_duplicates() {
  // Return 'self' with duplicates removed.  Preserves the
  // original order of the remaining members.
  { List* self = this;

    if (self->the_cons_list->non_emptyP()) {
      self->the_cons_list->remove_duplicates();
    }
    return (self);
  }
}

Object* List::pop() {
  // Remove and return the first element in the list 'self'.
  // Return NULL if the list is empty.
  { List* self = this;

    { Cons* cons = self->the_cons_list;
      Object* value = NULL;

      if (cons->emptyP()) {
        return (NULL);
      }
      value = cons->value;
      self->the_cons_list = cons->rest;
      cons->free_cons();
      return (value);
    }
  }
}

List* List::reverse() {
  // Reverse the members of 'self' (in place).
  { List* self = this;

    self->the_cons_list = self->the_cons_list->reverse();
    return (self);
  }
}

List* List::substitute(Object* invalue, Object* outvalue) {
  // Destructively replace each appearance of 'outValue' by
  // 'inValue' in the list 'self'.
  { List* self = this;

    self->the_cons_list = self->the_cons_list->substitute(invalue, outvalue);
    return (self);
  }
}

List* List::concatenate(List* list2) {
  // Copy 'list2' onto the end of the list 'self'.
  // The operation is destructive wrt 'self', but leaves 'list2' intact.
  { List* self = this;

    if (list2->emptyP()) {
      return (self);
    }
    { Cons* copy2 = permanent_copy_cons_list(list2->the_cons_list);

      if (self->emptyP()) {
        self->the_cons_list = copy2;
      }
      else {
        self->the_cons_list->concatenate(copy2);
      }
      return (self);
    }
  }
}

List* List::prepend(List* list2) {
  // Copy 'list2' onto the front of the list 'self'.
  // The operation is destructive wrt 'self', but leaves 'list2' intact.
  { List* self = this;

    if (list2->emptyP()) {
      return (self);
    }
    self->the_cons_list = permanent_copy_cons_list(list2->the_cons_list)->concatenate(self->the_cons_list);
    return (self);
  }
}

List* List::copy() {
  // Return a copy of the list 'self'.  The conses in the copy are
  // freshly allocated.
  { List* self = this;

    { List* copy = ((List*)(create_object(self->primary_type(), 0)));

      copy->the_cons_list = permanent_copy_cons_list(self->the_cons_list);
      return (copy);
    }
  }
}

void List::clear() {
  // Make 'self' an empty list.
  { List* self = this;

    free_cons_list(self->the_cons_list);
    self->the_cons_list = NIL;
  }
}

List* List::sort(cpp_function_code predicate) {
  // Perform a stable, destructive sort of 'self' according to
  // 'predicate', and return the result.  If 'predicate' has a '<' semantics, the
  // result will be in ascending order.  If 'predicate' is NULL, a suitable
  // '<' predicate is chosen depending on the first element of 'self', and it 
  // is assumed that all elements of 'self' have the same type (supported
  // element types are GENERALIZED-SYMBOL, STRING, INTEGER, and FLOAT).
  { List* self = this;

    self->the_cons_list = self->the_cons_list->sort(predicate);
    return (self);
  }
}

Abstract_Iterator* List::allocate_iterator() {
  { List* self = this;

    { List_Iterator* iterator = new_list_iterator();

      iterator->list_iterator_cursor = self->the_cons_list;
      iterator->list_iterator_collection = self;
      iterator->first_iterationP = TRUE;
      return (iterator);
    }
  }
}

boolean terminate_list_iteratorP(List_Iterator* self) {
  self->list_iterator_cursor = NIL;
  self->list_iterator_collection = NULL;
  return (TRUE);
}

boolean List_Iterator::nextP() {
  { List_Iterator* self = this;

    if (self->first_iterationP) {
      {
        self->first_iterationP = FALSE;
        self->list_iterator_cursor = self->list_iterator_collection->the_cons_list;
      }
    }
    else {
      self->list_iterator_cursor = self->list_iterator_cursor->rest;
    }
    self->value = self->list_iterator_cursor->value;
    return (!nilP(self->list_iterator_cursor));
  }
}

boolean List_Iterator::emptyP() {
  { List_Iterator* self = this;

    return (nilP(self->list_iterator_collection->the_cons_list));
  }
}

Object* Kv_List_Iterator::key_setter(Object* key) {
  { Kv_List_Iterator* self = this;

    self->kv_list_iterator_cursor->key = key;
    return (key);
  }
}

Object* List_Iterator::value_setter(Object* value) {
  { List_Iterator* self = this;

    self->list_iterator_cursor->value = value;
    return (value);
  }
}

Iterator* List::but_last() {
  // Generate all but the last element of the list 'self'.
  { List* self = this;

    return (self->the_cons_list->but_last());
  }
}

boolean Object::deletedP() {
  // Default 'deleted?' method returns FALSE.  Objects
  // that inherit the mixin DYNAMIC-SLOTS-MIXIN also inherit the
  // dynamically-allocated slot 'deleted?'.
  { Object* self = this;

    return (FALSE);
  }
}

boolean Dynamic_Slots_Mixin::deletedP() {
  { Dynamic_Slots_Mixin* self = this;

    { boolean deletedP = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_LISTS_DELETED_OBJECTp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (deletedP != NULL_BOOLEAN) {
        return (deletedP);
      }
      else {
        return (FALSE);
      }
    }
  }
}

boolean Dynamic_Slots_Mixin::deletedP_setter(boolean value) {
  { Dynamic_Slots_Mixin* self = this;

    set_dynamic_slot_value(self, SYM_LISTS_DELETED_OBJECTp, wrap_boolean(value), NULL_BOOLEAN_WRAPPER);
    return (value);
  }
}

boolean Mappable_Object::deletedP() {
  { Mappable_Object* self = this;

    { boolean deletedP = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_LISTS_DELETED_OBJECTp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (deletedP != NULL_BOOLEAN) {
        return (deletedP);
      }
      else {
        return (FALSE);
      }
    }
  }
}

boolean Mappable_Object::deletedP_setter(boolean value) {
  { Mappable_Object* self = this;

    set_dynamic_slot_value(self, SYM_LISTS_DELETED_OBJECTp, wrap_boolean(value), NULL_BOOLEAN_WRAPPER);
    return (value);
  }
}

void List::remove_deleted_members() {
  { List* self = this;

    { Cons* cursor = self->the_cons_list;
      Cons* trailer = NULL;

      while (!(cursor == NIL)) {
        if (cursor->value->deletedP() &&
            (trailer != NULL)) {
          {
            trailer->rest = cursor->rest;
            cursor->free_cons();
            cursor = trailer->rest;
          }
        }
        else {
          {
            trailer = cursor;
            cursor = cursor->rest;
          }
        }
      }
      cursor = self->the_cons_list;
      if (cursor->non_emptyP() &&
          cursor->value->deletedP()) {
        self->the_cons_list = cursor->rest;
        cursor->free_cons();
      }
    }
  }
}

void Property_List::initialize_object() {
  { Property_List* self = this;

    self->the_plist = NIL;
  }
}

Object* search_plist(Cons* plist, Object* key) {
  while (plist->non_emptyP()) {
    if (eqlP(plist->value, key)) {
      return (plist->rest->value);
    }
    plist = plist->rest->rest;
  }
  return (NULL);
}

Object* Property_List::lookup(Object* key) {
  { Property_List* self = this;

    // inline method
    return (search_plist(self->the_plist, key));
  }
}

int Property_List::length() {
  { Property_List* self = this;

    { Cons* cursor = self->the_plist;
      int length = 0;

      while (cursor->non_emptyP()) {
        length = length + 1;
        cursor = cursor->rest->rest;
      }
      return (length);
    }
  }
}

void Property_List::insert_at(Object* key, Object* value) {
  // Insert the entry <`key', `value'> into the property list `self'.
  // If a previous entry existed with key `key', that entry is replaced.
  { Property_List* self = this;

    { Cons* cursor = self->the_plist;

      while (cursor->non_emptyP()) {
        if (eqlP(cursor->value, key)) {
          cursor = cursor->rest;
          cursor->value = value;
          return;
        }
        cursor = cursor->rest->rest;
      }
      self->the_plist = permanent_cons(key, permanent_cons(value, self->the_plist));
    }
  }
}

Object* Property_List::remove_at(Object* key) {
  // Remove the entry that matches the key `key'.  Return the
  // value of the matching entry, or NULL if there is no matching entry.  Assumes that at
  // most one entry matches `key'.
  { Property_List* self = this;

    { Cons* cursor = self->the_plist;
      Cons* previouscons = NULL;
      Object* value = NULL;

      if (cursor->non_emptyP()) {
        if (eqlP(cursor->value, key)) {
          self->the_plist = cursor->rest->rest;
          value = cursor->rest->value;
          cursor->rest->free_cons();
          cursor->free_cons();
          return (value);
        }
        previouscons = cursor->rest;
        cursor = previouscons->rest;
        while (cursor->non_emptyP()) {
          if (eqlP(cursor->value, key)) {
            previouscons->rest = cursor->rest->rest;
            value = cursor->rest->value;
            cursor->rest->free_cons();
            cursor->free_cons();
            return (value);
          }
          previouscons = cursor->rest;
          cursor = previouscons->rest;
        }
      }
      return (NULL);
    }
  }
}

boolean Property_List::emptyP() {
  { Property_List* self = this;

    return (self->the_plist->emptyP());
  }
}

boolean Property_List::non_emptyP() {
  { Property_List* self = this;

    return (self->the_plist->non_emptyP());
  }
}

Property_List* Property_List::copy() {
  // Return a copy of the list `self'.  The conses in the copy are
  // freshly allocated.
  { Property_List* self = this;

    { Property_List* copy = ((Property_List*)(create_object(self->primary_type(), 0)));

      copy->the_plist = permanent_copy_cons_list(self->the_plist);
      return (copy);
    }
  }
}

void Property_List::clear() {
  // Make `self' an empty property list.
  { Property_List* self = this;

    free_cons_list(self->the_plist);
    self->the_plist = NIL;
  }
}

Abstract_Iterator* Property_List::allocate_iterator() {
  { Property_List* self = this;

    { Property_List_Iterator* iterator = new_property_list_iterator();

      iterator->plist_iterator_cursor = self->the_plist;
      iterator->plist_iterator_collection = self;
      iterator->first_iterationP = TRUE;
      return (iterator);
    }
  }
}

boolean Property_List_Iterator::nextP() {
  { Property_List_Iterator* self = this;

    if (self->first_iterationP) {
      self->first_iterationP = FALSE;
    }
    else {
      self->plist_iterator_cursor = self->plist_iterator_cursor->rest->rest;
    }
    { Cons* remainingplist = self->plist_iterator_cursor;

      if (remainingplist->non_emptyP()) {
        self->key = remainingplist->value;
        self->value = remainingplist->rest->value;
        return (TRUE);
      }
      return (FALSE);
    }
  }
}

Object* Property_List_Iterator::value_setter(Object* value) {
  { Property_List_Iterator* self = this;

    self->plist_iterator_cursor->rest->value = value;
    return (value);
  }
}

Object* Property_List_Iterator::key_setter(Object* key) {
  { Property_List_Iterator* self = this;

    self->plist_iterator_cursor->value = key;
    return (key);
  }
}

Kv_Cons* kv_cons(Object* key, Object* value, Kv_Cons* rest) {
  // Create, fill-in, and return a new KV-CONS.
  { Kv_Cons* newkvc = new_kv_cons();

    newkvc->key = key;
    newkvc->value = value;
    newkvc->rest = rest;
    return (newkvc);
  }
}

void free_kv_cons(Kv_Cons* kvcons) {
  kvcons->free();
}

Object* Key_Value_List::lookup(Object* key) {
  { Key_Value_List* self = this;

    { Kv_Cons* cursor = self->the_kv_list;

      while (cursor != NULL) {
        if (eqlP(cursor->key, key)) {
          return (cursor->value);
        }
        cursor = cursor->rest;
      }
      return (NULL);
    }
  }
}

int Key_Value_List::length() {
  { Key_Value_List* self = this;

    { int length = 0;
      Kv_Cons* cursor = self->the_kv_list;

      while (cursor != NULL) {
        length = length + 1;
        cursor = cursor->rest;
      }
      return (length);
    }
  }
}

void Key_Value_List::insert_at(Object* key, Object* value) {
  // Insert the entry <'key', 'value'> into the association
  // 'self'. If a previous entry existed with key 'key', that entry is replaced.
  { Key_Value_List* self = this;

    { Kv_Cons* cursor = self->the_kv_list;

      while (cursor != NULL) {
        if (eqlP(cursor->key, key)) {
          cursor->value = value;
          return;
        }
        cursor = cursor->rest;
      }
      self->the_kv_list = kv_cons(key, value, self->the_kv_list);
    }
  }
}

Object* Key_Value_List::remove_at(Object* key) {
  // Remove the entry that matches the key 'key'.
  // Return the value of the matching entry, or NULL if there is no matching entry.
  // Assumes that at most one entry matches 'key'.
  { Key_Value_List* self = this;

    { Kv_Cons* cursor = self->the_kv_list;
      Kv_Cons* previouscursor = NULL;
      Object* value = NULL;

      if (cursor != NULL) {
        if (eqlP(cursor->key, key)) {
          self->the_kv_list = cursor->rest;
          value = cursor->value;
          free_kv_cons(cursor);
          return (value);
        }
        while (cursor->rest != NULL) {
          previouscursor = cursor;
          cursor = cursor->rest;
          if (eqlP(cursor->key, key)) {
            previouscursor->rest = cursor->rest;
            value = cursor->value;
            free_kv_cons(cursor);
            return (value);
          }
        }
      }
      return (NULL);
    }
  }
}

void Key_Value_List::insert_entry(Object* key, Object* value) {
  // Insert an entry <'key','value'> to 'self' unless an identical
  // entry already exists.  This can generate duplicate entries for 'key'.
  { Key_Value_List* self = this;

    { boolean foundP_001 = FALSE;

      { Object* v = NULL;
        Object* k = NULL;
        Kv_Cons* iter_001 = self->the_kv_list;

        while (iter_001 != NULL) {
          k = iter_001->key;
          {
            v = iter_001->value;
            iter_001 = iter_001->rest;
          }
          if ((k == key) &&
              (v == value)) {
            foundP_001 = TRUE;
            break;
          }
        }
      }
      if (!(foundP_001)) {
        self->the_kv_list = kv_cons(key, value, self->the_kv_list);
      }
    }
  }
}

void Key_Value_List::remove_entry(Object* key, Object* value) {
  // Remove the entry that matches <'key','value'>.
  // Assumes that more than one entry can match 'key'.
  { Key_Value_List* self = this;

    { Kv_Cons* cursor = self->the_kv_list;
      Kv_Cons* previouscursor = NULL;

      if (cursor != NULL) {
        if (eqlP(cursor->key, key) &&
            eqlP(cursor->value, value)) {
          self->the_kv_list = cursor->rest;
          free_kv_cons(cursor);
          return;
        }
        while (cursor->rest != NULL) {
          previouscursor = cursor;
          cursor = cursor->rest;
          if (eqlP(cursor->key, key) &&
              eqlP(cursor->value, value)) {
            previouscursor->rest = cursor->rest;
            free_kv_cons(cursor);
            return;
          }
        }
      }
    }
  }
}

Object* Key_Value_List::pop() {
  // Remove and return the first element of the kv-list 'self'.
  // Return NULL if the list is empty.
  { Key_Value_List* self = this;

    if (self->emptyP()) {
      return (NULL);
    }
    { Kv_Cons* cons = self->the_kv_list;
      Object* value = NULL;

      value = cons->value;
      self->the_kv_list = cons->rest;
      free_kv_cons(cons);
      return (value);
    }
  }
}

Key_Value_List* Key_Value_List::reverse() {
  // Destructively reverse the members of the list 'self'.
  { Key_Value_List* self = this;

    { Kv_Cons* reversedlist = self->the_kv_list;
      Kv_Cons* remaininglist = NULL;
      Kv_Cons* temp = NULL;

      if (reversedlist == NULL) {
        return (self);
      }
      remaininglist = reversedlist->rest;
      if (remaininglist == NULL) {
        return (self);
      }
      reversedlist->rest = NULL;
      while (remaininglist != NULL) {
        temp = remaininglist;
        remaininglist = remaininglist->rest;
        temp->rest = reversedlist;
        reversedlist = temp;
      }
      self->the_kv_list = reversedlist;
      return (self);
    }
  }
}

boolean Key_Value_List::emptyP() {
  { Key_Value_List* self = this;

    return (self->the_kv_list == NULL);
  }
}

boolean Key_Value_List::non_emptyP() {
  { Key_Value_List* self = this;

    return (self->the_kv_list != NULL);
  }
}

Kv_Cons* copy_kv_cons_list(Kv_Cons* kvconslist) {
  // Return a copy of the cons list 'consList'.
  if (kvconslist == NULL) {
    return (NULL);
  }
  { Kv_Cons* newkvconslist = new_kv_cons();
    Kv_Cons* nextkvcons = newkvconslist;
    Kv_Cons* copyfromkvcons = NULL;
    Kv_Cons* previouskvcons = NULL;

    nextkvcons->key = kvconslist->key;
    nextkvcons->value = kvconslist->value;
    copyfromkvcons = kvconslist->rest;
    while (copyfromkvcons != NULL) {
      previouskvcons = nextkvcons;
      nextkvcons = new_kv_cons();
      previouskvcons->rest = nextkvcons;
      nextkvcons->key = copyfromkvcons->key;
      nextkvcons->value = copyfromkvcons->value;
      copyfromkvcons = copyfromkvcons->rest;
    }
    nextkvcons->rest = NULL;
    return (newkvconslist);
  }
}

Key_Value_List* Key_Value_List::copy() {
  // Return a copy of the kv-list 'self'.  The kv-conses in
  // the copy are freshly allocated.
  { Key_Value_List* self = this;

    { Key_Value_List* copy = new_key_value_list();

      copy->the_kv_list = copy_kv_cons_list(self->the_kv_list);
      return (copy);
    }
  }
}

void Key_Value_List::clear() {
  // Make 'self' an empty dictionary.
  { Key_Value_List* self = this;

    { Kv_Cons* next = self->the_kv_list;
      Kv_Cons* current = NULL;

      while (next != NULL) {
        current = next;
        next = next->rest;
        free_kv_cons(current);
      }
      self->the_kv_list = NULL;
    }
  }
}

Abstract_Iterator* Key_Value_List::allocate_iterator() {
  { Key_Value_List* self = this;

    { Kv_List_Iterator* iterator = new_kv_list_iterator();

      iterator->the_kv_list = self;
      iterator->kv_list_iterator_cursor = self->the_kv_list;
      iterator->first_iterationP = TRUE;
      return (iterator);
    }
  }
}

boolean Kv_List_Iterator::nextP() {
  { Kv_List_Iterator* self = this;

    if (self->first_iterationP) {
      self->first_iterationP = FALSE;
    }
    else {
      self->kv_list_iterator_cursor = self->kv_list_iterator_cursor->rest;
    }
    if (self->kv_list_iterator_cursor == NULL) {
      return (FALSE);
    }
    self->key = self->kv_list_iterator_cursor->key;
    self->value = self->kv_list_iterator_cursor->value;
    return (TRUE);
  }
}

Object* Kv_List_Iterator::value_setter(Object* value) {
  { Kv_List_Iterator* self = this;

    self->kv_list_iterator_cursor->value = value;
    return (value);
  }
}

boolean Sequence::memberP(Object* value) {
  // Return TRUE if 'value' is a member of the sequence 'self'.
  { Sequence* self = this;

    { Object* m = NULL;
      Iterator* iter_001 = ((Iterator*)(self->allocate_iterator()));

      while (iter_001->nextP()) {
        {
          m = iter_001->value;
        }
        if (eqlP(m, value)) {
          return (TRUE);
        }
      }
    }
    return (FALSE);
  }
}

List* list(int values, ...) {
  // Return a list containing 'values', in order.
  { List* list = new_list();

    { va_list ap;
      Object* v;
      Cons* collect_001 = NULL;

      va_start(ap, values);
      while (values > 0) {
        v = va_arg(ap, Object*);
        values = values - 1;
        if (collect_001 == NULL) {
          {
            collect_001 = permanent_cons(v, NIL);
            if (list->the_cons_list->emptyP()) {
              list->the_cons_list = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(list->the_cons_list, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = permanent_cons(v, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
      va_end(ap);
    }
    return (list);
  }
}

Sequence* sequence(Surrogate* collectiontype, int values, ...) {
  // Return a sequence containing 'values', in order.
  { Sequence* sequence = ((Sequence*)(create_object(collectiontype, 0)));

    { va_list ap;
      Object* i;

      va_start(ap, values);
      while (values > 0) {
        i = va_arg(ap, Object*);
        values = values - 1;
        { Sequence* sequence_001 = sequence;

          if (taxonomy_isaP(sequence, SGT_LISTS_LIST)) {
            { List* sequence = NULL;

              sequence = ((List*)(sequence_001));
              sequence->insert_last(i);
            }
          }
          else {
            cerr << "sequence: Don't know how to 'insert-last' into a " << "`" << collectiontype << "'";
          }
        }
      }
      va_end(ap);
    }
    return (sequence);
  }
}

Dictionary* dictionary(Surrogate* collectiontype, int alternatingkeysandvalues, ...) {
  // Return a dictionary containing 'values', in order.
  { Dictionary* dictionary = ((Dictionary*)(create_object(collectiontype, 0)));
    Object* key = NULL;
    Object* value = NULL;
    Cons* copy = NIL;
    Cons* cursor = NULL;

    { va_list ap;
      Object* item;
      Cons* collect_001 = NULL;

      va_start(ap, alternatingkeysandvalues);
      while (alternatingkeysandvalues > 0) {
        item = va_arg(ap, Object*);
        alternatingkeysandvalues = alternatingkeysandvalues - 1;
        if (collect_001 == NULL) {
          {
            collect_001 = cons(item, NIL);
            if (nilP(copy)) {
              copy = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(copy, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(item, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
      va_end(ap);
    }
    cursor = copy;
    while (cursor->non_emptyP()) {
      key = cursor->first();
      value = cursor->second();
      { Dictionary* dictionary_001 = dictionary;

        if (taxonomy_isaP(dictionary, SGT_LISTS_KEY_VALUE_LIST)) {
          { Key_Value_List* dictionary = NULL;

            dictionary = ((Key_Value_List*)(dictionary_001));
            dictionary->insert_at(key, value);
          }
        }
        else if (taxonomy_isaP(dictionary, SGT_LISTS_PROPERTY_LIST)) {
          { Property_List* dictionary = NULL;

            dictionary = ((Property_List*)(dictionary_001));
            dictionary->insert_at(key, value);
          }
        }
        else {
          cerr << "dictionary: Don't know how to 'insert-at' into a " << "`" << collectiontype << "'";
        }
      }
      cursor = cursor->rest->rest;
    }
    free_cons_list(copy);
    return (dictionary);
  }
}

List* Iterator::listify() {
  // Return a list of elements generated by 'self'.
  { Iterator* self = this;

    { List* list = new_list();

      { Object* value = NULL;
        Iterator* iter_001 = self;

        while (iter_001->nextP()) {
          {
            value = iter_001->value;
          }
          list->push(value);
        }
      }
      return (list->reverse());
    }
  }
}

void print_key_value_list(Key_Value_List* self, ostream* stream) {
  *(stream) << "(";
  { Kv_Cons* cursor = self->the_kv_list;
    int position = 1;

    while (cursor != NULL) {
      if (position > 5) {
        *(stream) << " ...";
        break;
      }
      *(stream) << cursor;
      cursor = cursor->rest;
      position = position + 1;
    }
    *(stream) << ")";
  }
}

void print_cons_list(Cons* list, ostream* stream) {
  if (list->emptyP()) {
    *(stream) << "|i|()";
  }
  else {
    { int i = 0;
      int limit = 9;

      *(stream) << "|i|(" << list->first();
      { Object* item = NULL;
        Cons* iter_001 = list->rest;

        while (!nilP(iter_001)) {
          {
            item = iter_001->value;
            iter_001 = iter_001->rest;
          }
          *(stream) << " " << item;
          i = i + 1;
          if (i > limit) {
            break;
          }
        }
      }
      if (i <= limit) {
        *(stream) << ")";
      }
      else {
        *(stream) << " ...)";
      }
    }
  }
}

void startup_lists() {
  if (current_startup_time_phaseP(0)) {
    if (!(NIL_LIST != NULL)) {
      NIL_LIST = new List;
    }
    NIL_LIST->the_cons_list = NIL;
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
            SGT_LISTS_ABSTRACT_DICTIONARY_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("ABSTRACT-DICTIONARY-ITERATOR", NULL, 1)));
            SYM_LISTS_KEY = ((Symbol*)(intern_rigid_symbol_wrt_module("KEY", NULL, 0)));
            SYM_LISTS_KEY_SETTER = ((Symbol*)(intern_rigid_symbol_wrt_module("KEY-SETTER", NULL, 0)));
            SYM_LISTS_SLOT_WRITER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-WRITER", NULL, 0)));
            SGT_LISTS_ABSTRACT_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("ABSTRACT-ITERATOR", NULL, 1)));
            SYM_LISTS_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE", NULL, 0)));
            SYM_LISTS_VALUE_SETTER = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE-SETTER", NULL, 0)));
            SYM_LISTS_DELETED_OBJECTp = ((Symbol*)(intern_rigid_symbol_wrt_module("DELETED-OBJECT?", NULL, 0)));
            SGT_LISTS_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("LIST", NULL, 1)));
            SGT_LISTS_KEY_VALUE_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("KEY-VALUE-LIST", NULL, 1)));
            SGT_LISTS_PROPERTY_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPERTY-LIST", NULL, 1)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("DEFINED-LIST?", "LIST", "(DEFUN (DEFINED-LIST? BOOLEAN) ((SELF LIST)) :DOCUMENTATION \"Return TRUE unless 'self' is NULL or the 'NIL-LIST'.\")");

              method->function_code = ((cpp_function_code)(&defined_listP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NULL-LIST?", "LIST", "(DEFUN (NULL-LIST? BOOLEAN) ((SELF LIST)) :DOCUMENTATION \"Return TRUE iff 'self' is NULL or the 'NIL-LIST'.\")");

              method->function_code = ((cpp_function_code)(&null_listP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EMPTY?", "LIST", "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF LIST)) :DOCUMENTATION \"Return TRUE if the list 'self' has no members.\")");

              method->method_code = ((cpp_method_code)(&List::emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NON-EMPTY?", "LIST", "(DEFMETHOD (NON-EMPTY? BOOLEAN) ((SELF LIST)) :DOCUMENTATION \"Return TRUE if the list 'self' has at least one member.\")");

              method->method_code = ((cpp_method_code)(&List::non_emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-LIST?", "LIST", "(DEFUN (TERMINATE-LIST? BOOLEAN) ((SELF LIST)))");

              method->function_code = ((cpp_function_code)(&terminate_listP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MEMBER?", "LIST", "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF LIST) (OBJECT (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Return TRUE iff 'object' is a member of the list 'self'.\n Uses an 'eql?' test.\")");

              method->method_code = ((cpp_method_code)(&List::memberP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIRST", "LIST", "(DEFMETHOD (FIRST (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the first item in the list 'self', or NULL if empty.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&List::first));
            }
            { Method_Slot* method = define_method_from_stringified_source("SECOND", "LIST", "(DEFMETHOD (SECOND (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the second item in the list 'self', or NULL if empty.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&List::second));
            }
            { Method_Slot* method = define_method_from_stringified_source("THIRD", "LIST", "(DEFMETHOD (THIRD (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the third item in the list 'self', or NULL if empty.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&List::third));
            }
            { Method_Slot* method = define_method_from_stringified_source("FOURTH", "LIST", "(DEFMETHOD (FOURTH (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the fourth item in the list 'self', or NULL if empty.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&List::fourth));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIFTH", "LIST", "(DEFMETHOD (FIFTH (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the fifth item in the list 'self', or NULL if empty.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&List::fifth));
            }
            { Method_Slot* method = define_method_from_stringified_source("NTH", "LIST", "(DEFMETHOD (NTH (LIKE (ANY-VALUE SELF))) ((SELF LIST) (POSITION INTEGER)) :DOCUMENTATION \"Return the nth item in the list 'self', or NULL if empty.\")");

              method->method_code = ((cpp_method_code)(&List::nth));
            }
            { Method_Slot* method = define_method_from_stringified_source("LAST", "LIST", "(DEFMETHOD (LAST (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Return the last element of 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&List::last));
            }
            { Method_Slot* method = define_method_from_stringified_source("REST", "LIST", "(DEFMETHOD (REST (CONS OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST)) :DOCUMENTATION \"Return a cons list of all but the first item in the list 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&List::rest));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIRST-SETTER", "LIST", "(DEFMETHOD (FIRST-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&List::first_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("SECOND-SETTER", "LIST", "(DEFMETHOD (SECOND-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&List::second_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("THIRD-SETTER", "LIST", "(DEFMETHOD (THIRD-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&List::third_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("FOURTH-SETTER", "LIST", "(DEFMETHOD (FOURTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&List::fourth_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIFTH-SETTER", "LIST", "(DEFMETHOD (FIFTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&List::fifth_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("NTH-SETTER", "LIST", "(DEFMETHOD (NTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF LIST) (VALUE OBJECT) (POSITION INTEGER)))");

              method->method_code = ((cpp_method_code)(&List::nth_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("LENGTH", "LIST", "(DEFMETHOD (LENGTH INTEGER) ((SELF LIST)))");

              method->method_code = ((cpp_method_code)(&List::length));
            }
            { Method_Slot* method = define_method_from_stringified_source("POSITION", "LIST", "(DEFMETHOD (POSITION INTEGER) ((SELF LIST) (OBJECT OBJECT) (START INTEGER)) :DOCUMENTATION \"Return the position of 'object' within the list\n'self' (counting from zero); or return NULL if 'object' does not occur within \n'self' (uses an 'eql?' test).  If 'start' was supplied as non-NULL, only \nconsider the sublist starting at 'start', however, the returned position \nwill always be relative to the entire list.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&List::position));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT", "LIST", "(DEFMETHOD INSERT ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Add 'value' to the front of the list 'self'.\")");

              method->method_code = ((cpp_method_code)(&List::insert));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUSH", "LIST", "(DEFMETHOD PUSH ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Add 'value' to the front of the list 'self'.\")");

              method->method_code = ((cpp_method_code)(&List::push));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT-NEW", "LIST", "(DEFMETHOD INSERT-NEW ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Add 'value' to the front of the list 'self' unless its \nalready a member.\")");

              method->method_code = ((cpp_method_code)(&List::insert_new));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT-LAST", "LIST", "(DEFMETHOD INSERT-LAST ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Insert 'value' as the last entry in the list 'self'.\")");

              method->method_code = ((cpp_method_code)(&List::insert_last));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE", "LIST", "(DEFMETHOD (REMOVE LIST) ((SELF LIST) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Remove all entries in 'self' that match 'value'.\")");

              method->method_code = ((cpp_method_code)(&List::remove));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-IF", "LIST", "(DEFMETHOD (REMOVE-IF LIST) ((SELF LIST) (TEST? FUNCTION-CODE)) :PUBLIC? TRUE :DOCUMENTATION \"Remove all members of the list 'self' for which 'test?'\nevaluates to TRUE.  'test' takes a single argument of type OBJECT and\nreturns TRUE or FALSE.  Returns 'self'.\")");

              method->method_code = ((cpp_method_code)(&List::remove_if));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-DUPLICATES", "LIST", "(DEFMETHOD (REMOVE-DUPLICATES (LIKE SELF)) ((SELF LIST)) :DOCUMENTATION \"Return 'self' with duplicates removed.  Preserves the\noriginal order of the remaining members.\")");

              method->method_code = ((cpp_method_code)(&List::remove_duplicates));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP", "LIST", "(DEFMETHOD (POP (LIKE (ANY-VALUE SELF))) ((SELF LIST)) :DOCUMENTATION \"Remove and return the first element in the list 'self'.\nReturn NULL if the list is empty.\")");

              method->method_code = ((cpp_method_code)(&List::pop));
            }
            { Method_Slot* method = define_method_from_stringified_source("REVERSE", "LIST", "(DEFMETHOD (REVERSE (LIKE SELF)) ((SELF LIST)) :DOCUMENTATION \"Reverse the members of 'self' (in place).\")");

              method->method_code = ((cpp_method_code)(&List::reverse));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBSTITUTE", "LIST", "(DEFMETHOD (SUBSTITUTE (LIKE SELF)) ((SELF LIST) (INVALUE OBJECT) (OUTVALUE OBJECT)) :DOCUMENTATION \"Destructively replace each appearance of 'outValue' by\n'inValue' in the list 'self'.\")");

              method->method_code = ((cpp_method_code)(&List::substitute));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONCATENATE", "LIST", "(DEFMETHOD (CONCATENATE (LIKE SELF)) ((SELF LIST) (LIST2 LIST)) :DOCUMENTATION \"Copy 'list2' onto the end of the list 'self'.\nThe operation is destructive wrt 'self', but leaves 'list2' intact.\")");

              method->method_code = ((cpp_method_code)(&List::concatenate));
            }
            { Method_Slot* method = define_method_from_stringified_source("PREPEND", "LIST", "(DEFMETHOD (PREPEND (LIKE SELF)) ((SELF LIST) (LIST2 LIST)) :DOCUMENTATION \"Copy 'list2' onto the front of the list 'self'.\nThe operation is destructive wrt 'self', but leaves 'list2' intact.\")");

              method->method_code = ((cpp_method_code)(&List::prepend));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY", "LIST", "(DEFMETHOD (COPY (LIST OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST)) :DOCUMENTATION \"Return a copy of the list 'self'.  The conses in the copy are\nfreshly allocated.\")");

              method->method_code = ((cpp_method_code)(&List::copy));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR", "LIST", "(DEFMETHOD CLEAR ((SELF LIST)) :DOCUMENTATION \"Make 'self' an empty list.\")");

              method->method_code = ((cpp_method_code)(&List::clear));
            }
            { Method_Slot* method = define_method_from_stringified_source("SORT", "LIST", "(DEFMETHOD (SORT (LIST OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST) (PREDICATE FUNCTION-CODE)) :PUBLIC? TRUE :DOCUMENTATION \"Perform a stable, destructive sort of 'self' according to\n'predicate', and return the result.  If 'predicate' has a '<' semantics, the\nresult will be in ascending order.  If 'predicate' is NULL, a suitable\n'<' predicate is chosen depending on the first element of 'self', and it \nis assumed that all elements of 'self' have the same type (supported\nelement types are GENERALIZED-SYMBOL, STRING, INTEGER, and FLOAT).\")");

              method->method_code = ((cpp_method_code)(&List::sort));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-ITERATOR", "LIST", "(DEFMETHOD (ALLOCATE-ITERATOR (LIST-ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST)))");

              method->method_code = ((cpp_method_code)(&List::allocate_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-LIST-ITERATOR?", "LIST-ITERATOR", "(DEFUN (TERMINATE-LIST-ITERATOR? BOOLEAN) ((SELF LIST-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&terminate_list_iteratorP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "LIST-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF LIST-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&List_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EMPTY?", "LIST-ITERATOR", "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF LIST-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&List_Iterator::emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("KEY-SETTER", "KV-LIST-ITERATOR", "(DEFMETHOD (KEY-SETTER OBJECT) ((SELF KV-LIST-ITERATOR) (KEY OBJECT)))");

              method->method_code = ((cpp_method_code)(&Kv_List_Iterator::key_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALUE-SETTER", "LIST-ITERATOR", "(DEFMETHOD (VALUE-SETTER OBJECT) ((SELF LIST-ITERATOR) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&List_Iterator::value_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUT-LAST", "LIST", "(DEFMETHOD (BUT-LAST (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST)) :DOCUMENTATION \"Generate all but the last element of the list 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&List::but_last));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETED?", "OBJECT", "(DEFMETHOD (DELETED? BOOLEAN) ((SELF OBJECT)) :DOCUMENTATION \"Default 'deleted?' method returns FALSE.  Objects\nthat inherit the mixin DYNAMIC-SLOTS-MIXIN also inherit the\ndynamically-allocated slot 'deleted?'.\")");

              method->method_code = ((cpp_method_code)(&Object::deletedP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETED?", "DYNAMIC-SLOTS-MIXIN", "(DEFMETHOD (DELETED? BOOLEAN) ((SELF DYNAMIC-SLOTS-MIXIN)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETED?-SETTER", "DYNAMIC-SLOTS-MIXIN", "(DEFMETHOD (DELETED?-SETTER BOOLEAN) ((SELF DYNAMIC-SLOTS-MIXIN) (VALUE BOOLEAN)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETED?", "MAPPABLE-OBJECT", "(DEFMETHOD (DELETED? BOOLEAN) ((SELF MAPPABLE-OBJECT)))");

              method->method_code = ((cpp_method_code)(&Mappable_Object::deletedP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETED?-SETTER", "MAPPABLE-OBJECT", "(DEFMETHOD (DELETED?-SETTER BOOLEAN) ((SELF MAPPABLE-OBJECT) (VALUE BOOLEAN)))");

              method->method_code = ((cpp_method_code)(&Mappable_Object::deletedP_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-DELETED-MEMBERS", "LIST", "(DEFMETHOD REMOVE-DELETED-MEMBERS ((SELF LIST)))");

              method->method_code = ((cpp_method_code)(&List::remove_deleted_members));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-OBJECT", "PROPERTY-LIST", "(DEFMETHOD INITIALIZE-OBJECT ((SELF PROPERTY-LIST)))");

              method->method_code = ((cpp_method_code)(&Property_List::initialize_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("SEARCH-PLIST", "CONS", "(DEFUN (SEARCH-PLIST OBJECT) ((PLIST CONS) (KEY OBJECT)))");

              method->function_code = ((cpp_function_code)(&search_plist));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP", "PROPERTY-LIST", "(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF PROPERTY-LIST) (KEY (LIKE (ANY-KEY SELF)))))");

              method->method_code = ((cpp_method_code)(&Property_List::lookup));
            }
            { Method_Slot* method = define_method_from_stringified_source("LENGTH", "PROPERTY-LIST", "(DEFMETHOD (LENGTH INTEGER) ((SELF PROPERTY-LIST)))");

              method->method_code = ((cpp_method_code)(&Property_List::length));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT-AT", "PROPERTY-LIST", "(DEFMETHOD INSERT-AT ((SELF PROPERTY-LIST) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Insert the entry <`key', `value'> into the property list `self'.\nIf a previous entry existed with key `key', that entry is replaced.\")");

              method->method_code = ((cpp_method_code)(&Property_List::insert_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-AT", "PROPERTY-LIST", "(DEFMETHOD (REMOVE-AT OBJECT) ((SELF PROPERTY-LIST) (KEY (LIKE (ANY-KEY SELF)))) :DOCUMENTATION \"Remove the entry that matches the key `key'.  Return the\nvalue of the matching entry, or NULL if there is no matching entry.  Assumes that at\nmost one entry matches `key'.\")");

              method->method_code = ((cpp_method_code)(&Property_List::remove_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("EMPTY?", "PROPERTY-LIST", "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF PROPERTY-LIST)))");

              method->method_code = ((cpp_method_code)(&Property_List::emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NON-EMPTY?", "PROPERTY-LIST", "(DEFMETHOD (NON-EMPTY? BOOLEAN) ((SELF PROPERTY-LIST)))");

              method->method_code = ((cpp_method_code)(&Property_List::non_emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY", "PROPERTY-LIST", "(DEFMETHOD (COPY (LIKE SELF)) ((SELF PROPERTY-LIST)) :DOCUMENTATION \"Return a copy of the list `self'.  The conses in the copy are\nfreshly allocated.\")");

              method->method_code = ((cpp_method_code)(&Property_List::copy));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR", "PROPERTY-LIST", "(DEFMETHOD CLEAR ((SELF PROPERTY-LIST)) :DOCUMENTATION \"Make `self' an empty property list.\")");

              method->method_code = ((cpp_method_code)(&Property_List::clear));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-ITERATOR", "PROPERTY-LIST", "(DEFMETHOD (ALLOCATE-ITERATOR PROPERTY-LIST-ITERATOR) ((SELF PROPERTY-LIST)))");

              method->method_code = ((cpp_method_code)(&Property_List::allocate_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "PROPERTY-LIST-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF PROPERTY-LIST-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Property_List_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALUE-SETTER", "PROPERTY-LIST-ITERATOR", "(DEFMETHOD (VALUE-SETTER OBJECT) ((SELF PROPERTY-LIST-ITERATOR) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Property_List_Iterator::value_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("KEY-SETTER", "PROPERTY-LIST-ITERATOR", "(DEFMETHOD (KEY-SETTER OBJECT) ((SELF PROPERTY-LIST-ITERATOR) (KEY OBJECT)))");

              method->method_code = ((cpp_method_code)(&Property_List_Iterator::key_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("KV-CONS", "OBJECT", "(DEFUN (KV-CONS KV-CONS) ((KEY OBJECT) (VALUE OBJECT) (REST KV-CONS)) :DOCUMENTATION \"Create, fill-in, and return a new KV-CONS.\")");

              method->function_code = ((cpp_function_code)(&kv_cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-KV-CONS", "KV-CONS", "(DEFUN FREE-KV-CONS ((KVCONS KV-CONS)))");

              method->function_code = ((cpp_function_code)(&free_kv_cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP", "KEY-VALUE-LIST", "(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF)))))");

              method->method_code = ((cpp_method_code)(&Key_Value_List::lookup));
            }
            { Method_Slot* method = define_method_from_stringified_source("LENGTH", "KEY-VALUE-LIST", "(DEFMETHOD (LENGTH INTEGER) ((SELF KEY-VALUE-LIST)))");

              method->method_code = ((cpp_method_code)(&Key_Value_List::length));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT-AT", "KEY-VALUE-LIST", "(DEFMETHOD INSERT-AT ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Insert the entry <'key', 'value'> into the association\n'self'. If a previous entry existed with key 'key', that entry is replaced.\")");

              method->method_code = ((cpp_method_code)(&Key_Value_List::insert_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-AT", "KEY-VALUE-LIST", "(DEFMETHOD (REMOVE-AT OBJECT) ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF)))) :DOCUMENTATION \"Remove the entry that matches the key 'key'.\nReturn the value of the matching entry, or NULL if there is no matching entry.\nAssumes that at most one entry matches 'key'.\")");

              method->method_code = ((cpp_method_code)(&Key_Value_List::remove_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT-ENTRY", "KEY-VALUE-LIST", "(DEFMETHOD INSERT-ENTRY ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Insert an entry <'key','value'> to 'self' unless an identical\nentry already exists.  This can generate duplicate entries for 'key'.\")");

              method->method_code = ((cpp_method_code)(&Key_Value_List::insert_entry));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-ENTRY", "KEY-VALUE-LIST", "(DEFMETHOD REMOVE-ENTRY ((SELF KEY-VALUE-LIST) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Remove the entry that matches <'key','value'>.\nAssumes that more than one entry can match 'key'.\")");

              method->method_code = ((cpp_method_code)(&Key_Value_List::remove_entry));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP", "KEY-VALUE-LIST", "(DEFMETHOD (POP (LIKE (ANY-VALUE SELF))) ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Remove and return the first element of the kv-list 'self'.\nReturn NULL if the list is empty.\")");

              method->method_code = ((cpp_method_code)(&Key_Value_List::pop));
            }
            { Method_Slot* method = define_method_from_stringified_source("REVERSE", "KEY-VALUE-LIST", "(DEFMETHOD (REVERSE (LIKE SELF)) ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Destructively reverse the members of the list 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Key_Value_List::reverse));
            }
            { Method_Slot* method = define_method_from_stringified_source("EMPTY?", "KEY-VALUE-LIST", "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF KEY-VALUE-LIST)))");

              method->method_code = ((cpp_method_code)(&Key_Value_List::emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NON-EMPTY?", "KEY-VALUE-LIST", "(DEFMETHOD (NON-EMPTY? BOOLEAN) ((SELF KEY-VALUE-LIST)))");

              method->method_code = ((cpp_method_code)(&Key_Value_List::non_emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-KV-CONS-LIST", "KV-CONS", "(DEFUN (COPY-KV-CONS-LIST KV-CONS) ((KVCONSLIST KV-CONS)) :DOCUMENTATION \"Return a copy of the cons list 'consList'.\")");

              method->function_code = ((cpp_function_code)(&copy_kv_cons_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY", "KEY-VALUE-LIST", "(DEFMETHOD (COPY (LIKE SELF)) ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Return a copy of the kv-list 'self'.  The kv-conses in\nthe copy are freshly allocated.\")");

              method->method_code = ((cpp_method_code)(&Key_Value_List::copy));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR", "KEY-VALUE-LIST", "(DEFMETHOD CLEAR ((SELF KEY-VALUE-LIST)) :DOCUMENTATION \"Make 'self' an empty dictionary.\")");

              method->method_code = ((cpp_method_code)(&Key_Value_List::clear));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-ITERATOR", "KEY-VALUE-LIST", "(DEFMETHOD (ALLOCATE-ITERATOR KV-LIST-ITERATOR) ((SELF KEY-VALUE-LIST)))");

              method->method_code = ((cpp_method_code)(&Key_Value_List::allocate_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "KV-LIST-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF KV-LIST-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Kv_List_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALUE-SETTER", "KV-LIST-ITERATOR", "(DEFMETHOD (VALUE-SETTER OBJECT) ((SELF KV-LIST-ITERATOR) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Kv_List_Iterator::value_setter));
            }
            { Method_Slot* method = define_method_from_stringified_source("MEMBER?", "SEQUENCE", "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF SEQUENCE) (VALUE OBJECT)) :DOCUMENTATION \"Return TRUE if 'value' is a member of the sequence 'self'.\")");

              method->method_code = ((cpp_method_code)(&Sequence::memberP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LIST", "ARGUMENT-LIST", "(DEFUN (LIST LIST) (|&REST| (VALUES OBJECT)) :DOCUMENTATION \"Return a list containing 'values', in order.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&list));
            }
            { Method_Slot* method = define_method_from_stringified_source("SEQUENCE", "TYPE", "(DEFUN (SEQUENCE (SEQUENCE OF OBJECT)) ((COLLECTIONTYPE TYPE) |&REST| (VALUES OBJECT)) :DOCUMENTATION \"Return a sequence containing 'values', in order.\")");

              method->function_code = ((cpp_function_code)(&sequence));
            }
            { Method_Slot* method = define_method_from_stringified_source("DICTIONARY", "TYPE", "(DEFUN (DICTIONARY (DICTIONARY OF OBJECT OBJECT)) ((COLLECTIONTYPE TYPE) |&REST| (ALTERNATINGKEYSANDVALUES OBJECT)) :DOCUMENTATION \"Return a dictionary containing 'values', in order.\")");

              method->function_code = ((cpp_function_code)(&dictionary));
            }
            { Method_Slot* method = define_method_from_stringified_source("LISTIFY", "ITERATOR", "(DEFMETHOD (LISTIFY LIST) ((SELF ITERATOR)) :DOCUMENTATION \"Return a list of elements generated by 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Iterator::listify));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-KEY-VALUE-LIST", "KEY-VALUE-LIST", "(DEFUN PRINT-KEY-VALUE-LIST ((SELF KEY-VALUE-LIST) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_key_value_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-CONS-LIST", "CONS", "(DEFUN PRINT-CONS-LIST ((LIST CONS) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_cons_list));
            }
            define_method_from_stringified_source("STARTUP-LISTS", NULL, "(DEFUN STARTUP-LISTS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL NIL-LIST LIST NULL)");
            set_dynamic_slot_value(((Storage_Slot*)(lookup_slot(((Class*)(SGT_LISTS_ABSTRACT_DICTIONARY_ITERATOR->surrogate_value)), SYM_LISTS_KEY))), SYM_LISTS_SLOT_WRITER, SYM_LISTS_KEY_SETTER, NULL);
            set_dynamic_slot_value(((Storage_Slot*)(lookup_slot(((Class*)(SGT_LISTS_ABSTRACT_ITERATOR->surrogate_value)), SYM_LISTS_VALUE))), SYM_LISTS_SLOT_WRITER, SYM_LISTS_VALUE_SETTER, NULL);
            set_dynamic_slot_value(((Storage_Slot*)(lookup_slot(((Class*)(SGT_LISTS_ABSTRACT_ITERATOR->surrogate_value)), SYM_LISTS_VALUE))), SYM_LISTS_SLOT_WRITER, SYM_LISTS_VALUE_SETTER, NULL);
            set_dynamic_slot_value(((Storage_Slot*)(lookup_slot(((Class*)(SGT_LISTS_ABSTRACT_DICTIONARY_ITERATOR->surrogate_value)), SYM_LISTS_KEY))), SYM_LISTS_SLOT_WRITER, SYM_LISTS_KEY_SETTER, NULL);
            set_dynamic_slot_value(((Storage_Slot*)(lookup_slot(((Class*)(SGT_LISTS_ABSTRACT_ITERATOR->surrogate_value)), SYM_LISTS_VALUE))), SYM_LISTS_SLOT_WRITER, SYM_LISTS_VALUE_SETTER, NULL);
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

