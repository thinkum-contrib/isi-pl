// collections.cc

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

Surrogate* SGT_COLLECTIONS_COLLECTION = NULL;

Surrogate* SGT_COLLECTIONS_ABSTRACT_ITERATOR = NULL;

Symbol* SYM_COLLECTIONS_VALUE = NULL;

Symbol* SYM_COLLECTIONS_VALUE_SETTER = NULL;

Symbol* SYM_COLLECTIONS_SLOT_WRITER = NULL;

boolean Collection::memberP(Object* object) {
  // Return TRUE iff 'object' is a member of the collection 'self'.
  { Collection* self = this;

    { Object* i = NULL;
      Iterator* iter_001 = ((Iterator*)(self->allocate_iterator()));

      while (iter_001->nextP()) {
        {
          i = iter_001->value;
        }
        if (eqlP(i, object)) {
          return (TRUE);
        }
      }
    }
    return (FALSE);
  }
}

boolean collectionP(Object* self) {
  // Return TRUE if 'self' is a native collection.
  return (isaP(self, SGT_COLLECTIONS_COLLECTION));
}

boolean Collection::no_duplicatesP() {
  // Return TRUE if the collection 'self' forbids duplicate values.
  { Collection* self = this;

    return (FALSE);
  }
}

boolean Set::no_duplicatesP() {
  { Set* self = this;

    return (TRUE);
  }
}

boolean Collection::orderedP() {
  // Return TRUE if the collection 'self' is ordered.
  { Collection* self = this;

    return (FALSE);
  }
}

boolean Sequence::orderedP() {
  { Sequence* self = this;

    return (TRUE);
  }
}

boolean Set::emptyP() {
  // Return TRUE if the set 'self' has no members.
  { Set* self = this;

    return (self->the_cons_list == NIL);
  }
}

boolean Set::non_emptyP() {
  // Return TRUE if the set 'self' has at least one member.
  { Set* self = this;

    return (!(self->the_cons_list == NIL));
  }
}

boolean terminate_setP(Set* self) {
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

boolean Set::memberP(Object* object) {
  // Return TRUE iff 'object' is a member of the set 'self'.
  // Uses an 'eql?' test.
  { Set* self = this;

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

void Set::insert(Object* value) {
  // Add 'value' to the set 'self'.  First checks for duplicate.
  { Set* self = this;

    if (!self->memberP(value)) {
      self->the_cons_list = permanent_cons(value, self->the_cons_list);
    }
  }
}

Abstract_Collection* Set::remove(Object* value) {
  // Remove all entries in 'self' that match 'value'.
  { Set* self = this;

    self->the_cons_list = self->the_cons_list->remove(value);
    return (self);
  }
}

Set* Set::reverse() {
  { Set* self = this;

    self->the_cons_list = self->the_cons_list->reverse();
    return (self);
  }
}

Set* Set::copy() {
  // Return a copy of the set 'self'.  The conses in the copy are
  // freshly allocated.
  { Set* self = this;

    { Set* copy = ((Set*)(create_object(self->primary_type(), 0)));

      copy->the_cons_list = permanent_copy_cons_list(self->the_cons_list);
      return (copy);
    }
  }
}

void Set::clear() {
  // Make 'self' an empty set.
  { Set* self = this;

    free_cons_list(self->the_cons_list);
    self->the_cons_list = NIL;
  }
}

Abstract_Iterator* Set::allocate_iterator() {
  { Set* self = this;

    { Set_Iterator* iterator = new_set_iterator();

      iterator->set_iterator_cursor = self->the_cons_list;
      iterator->set_iterator_collection = self;
      iterator->first_iterationP = TRUE;
      return (iterator);
    }
  }
}

boolean terminate_set_iteratorP(Set_Iterator* self) {
  self->set_iterator_cursor = NIL;
  self->set_iterator_collection = NULL;
  return (TRUE);
}

boolean Set_Iterator::nextP() {
  { Set_Iterator* self = this;

    if (self->first_iterationP) {
      {
        self->first_iterationP = FALSE;
        self->set_iterator_cursor = self->set_iterator_collection->the_cons_list;
      }
    }
    else {
      self->set_iterator_cursor = self->set_iterator_cursor->rest;
    }
    self->value = self->set_iterator_cursor->value;
    return (!nilP(self->set_iterator_cursor));
  }
}

Object* Set_Iterator::value_setter(Object* value) {
  { Set_Iterator* self = this;

    self->set_iterator_cursor->value = value;
    return (value);
  }
}

void startup_collections() {
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
            SGT_COLLECTIONS_COLLECTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION", NULL, 1)));
            SGT_COLLECTIONS_ABSTRACT_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("ABSTRACT-ITERATOR", NULL, 1)));
            SYM_COLLECTIONS_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE", NULL, 0)));
            SYM_COLLECTIONS_VALUE_SETTER = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE-SETTER", NULL, 0)));
            SYM_COLLECTIONS_SLOT_WRITER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-WRITER", NULL, 0)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("MEMBER?", "COLLECTION", "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF COLLECTION) (OBJECT (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE iff 'object' is a member of the collection 'self'.\")");

              method->method_code = ((cpp_method_code)(&Collection::memberP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECTION?", "OBJECT", "(DEFUN (COLLECTION? BOOLEAN) ((SELF OBJECT)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if 'self' is a native collection.\")");

              method->function_code = ((cpp_function_code)(&collectionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NO-DUPLICATES?", "COLLECTION", "(DEFMETHOD (NO-DUPLICATES? BOOLEAN) ((SELF COLLECTION)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if the collection 'self' forbids duplicate values.\")");

              method->method_code = ((cpp_method_code)(&Collection::no_duplicatesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NO-DUPLICATES?", "SET", "(DEFMETHOD (NO-DUPLICATES? BOOLEAN) ((SELF SET)) :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Set::no_duplicatesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ORDERED?", "COLLECTION", "(DEFMETHOD (ORDERED? BOOLEAN) ((SELF COLLECTION)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if the collection 'self' is ordered.\")");

              method->method_code = ((cpp_method_code)(&Collection::orderedP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ORDERED?", "SEQUENCE", "(DEFMETHOD (ORDERED? BOOLEAN) ((SELF SEQUENCE)) :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Sequence::orderedP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EMPTY?", "SET", "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF SET)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if the set 'self' has no members.\")");

              method->method_code = ((cpp_method_code)(&Set::emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NON-EMPTY?", "SET", "(DEFMETHOD (NON-EMPTY? BOOLEAN) ((SELF SET)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if the set 'self' has at least one member.\")");

              method->method_code = ((cpp_method_code)(&Set::non_emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-SET?", "SET", "(DEFUN (TERMINATE-SET? BOOLEAN) ((SELF SET)))");

              method->function_code = ((cpp_function_code)(&terminate_setP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MEMBER?", "SET", "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF SET) (OBJECT (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Return TRUE iff 'object' is a member of the set 'self'.\nUses an 'eql?' test.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Set::memberP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT", "SET", "(DEFMETHOD INSERT ((SELF SET) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE :DOCUMENTATION \"Add 'value' to the set 'self'.  First checks for duplicate.\")");

              method->method_code = ((cpp_method_code)(&Set::insert));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE", "SET", "(DEFMETHOD (REMOVE SET) ((SELF SET) (VALUE (LIKE (ANY-VALUE SELF)))) :PUBLIC? TRUE :DOCUMENTATION \"Remove all entries in 'self' that match 'value'.\")");

              method->method_code = ((cpp_method_code)(&Set::remove));
            }
            { Method_Slot* method = define_method_from_stringified_source("REVERSE", "SET", "(DEFMETHOD (REVERSE SET) ((SELF SET)) :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Set::reverse));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY", "SET", "(DEFMETHOD (COPY (SET OF (LIKE (ANY-VALUE SELF)))) ((SELF SET)) :PUBLIC? TRUE :DOCUMENTATION \"Return a copy of the set 'self'.  The conses in the copy are\nfreshly allocated.\")");

              method->method_code = ((cpp_method_code)(&Set::copy));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR", "SET", "(DEFMETHOD CLEAR ((SELF SET)) :PUBLIC? TRUE :DOCUMENTATION \"Make 'self' an empty set.\")");

              method->method_code = ((cpp_method_code)(&Set::clear));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-ITERATOR", "SET", "(DEFMETHOD (ALLOCATE-ITERATOR (SET-ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF SET)))");

              method->method_code = ((cpp_method_code)(&Set::allocate_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-SET-ITERATOR?", "SET-ITERATOR", "(DEFUN (TERMINATE-SET-ITERATOR? BOOLEAN) ((SELF SET-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&terminate_set_iteratorP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "SET-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF SET-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Set_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALUE-SETTER", "SET-ITERATOR", "(DEFMETHOD (VALUE-SETTER OBJECT) ((SELF SET-ITERATOR) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Set_Iterator::value_setter));
            }
            define_method_from_stringified_source("STARTUP-COLLECTIONS", NULL, "(DEFUN STARTUP-COLLECTIONS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            set_dynamic_slot_value(((Storage_Slot*)(lookup_slot(((Class*)(SGT_COLLECTIONS_ABSTRACT_ITERATOR->surrogate_value)), SYM_COLLECTIONS_VALUE))), SYM_COLLECTIONS_SLOT_WRITER, SYM_COLLECTIONS_VALUE_SETTER, NULL);
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

