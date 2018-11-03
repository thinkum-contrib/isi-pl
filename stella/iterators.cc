// iterators.cc

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

Surrogate* SGT_ITERATORS_TABLE = NULL;

Abstract_Iterator* Abstract_Iterator::allocate_iterator() {
  // Iterator objects return themselves when asked
  // for an iterator (they occupy the same position as a collection
  // within a 'foreach' statement).
  { Abstract_Iterator* self = this;

    return (self);
  }
}

int Abstract_Iterator::length() {
  // Iterate over 'self', and count how many
  // items there are.  Bad idea if 'self' iterates over an infinite
  // collection, since in that case it will run forever.'
  { Abstract_Iterator* self = this;

    { int count = 0;

      { Abstract_Iterator* i = self;

        while (i->nextP()) {
          count = count + 1;
        }
      }
      return (count);
    }
  }
}

Object* Iterator::pop() {
  // Return the first item of the sequence represented by 'self',
  // or NULL if it is empty.  Destructively uses up the first iteration element.
  { Iterator* self = this;

    if (self->nextP()) {
      return (self->value);
    }
    else {
      return (NULL);
    }
  }
}

Iterator* Iterator::advance(int n) {
  // Return 'self' after skipping over the first
  // 'n' elements in the (remainder of the) iteration.
  { Iterator* self = this;

    while ((n > 0) &&
        self->nextP()) {
      n = n - 1;
    }
    return (self);
  }
}

boolean Iterator::emptyP() {
  // Return TRUE if the sequence represented by 'self'
  // has no elements.  Side-effect free.
  { Iterator* self = this;

    cerr << "Missing 'empty?' method";
    return (FALSE);
  }
}

boolean Iterator::memberP(Object* value) {
  // Iterate over values of 'self', returning TRUE
  // if one of them is 'eql' to 'value.
  { Iterator* self = this;

    { Object* m = NULL;
      Iterator* iter_001 = self;

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

boolean Destructive_List_Iterator::nextP() {
  { Destructive_List_Iterator* self = this;

    if (self->first_iterationP) {
      self->first_iterationP = FALSE;
      self->list_iterator_cursor = self->the_cons_list;
    }
    else {
      self->list_iterator_cursor = self->list_iterator_cursor->rest;
    }
    self->value = self->list_iterator_cursor->value;
    return (self->list_iterator_cursor->non_emptyP());
  }
}

boolean Destructive_List_Iterator::emptyP() {
  { Destructive_List_Iterator* self = this;

    return (nilP(self->the_cons_list));
  }
}

boolean terminate_destructive_list_iteratorP(Destructive_List_Iterator* self) {
  free_cons_list(self->the_cons_list);
  self->the_cons_list = NIL;
  return (TRUE);
}

void Destructive_List_Iterator::insert(Object* value) {
  // Add 'value' to the front of the list 'self'.
  { Destructive_List_Iterator* self = this;

    self->the_cons_list = cons(value, self->the_cons_list);
  }
}

Iterator* Cons::allocate_destructive_list_iterator() {
  { Cons* self = this;

    { Destructive_List_Iterator* iterator = new_destructive_list_iterator();

      iterator->the_cons_list = self;
      iterator->list_iterator_cursor = self;
      iterator->first_iterationP = TRUE;
      return (iterator);
    }
  }
}

Iterator* List::allocate_destructive_list_iterator() {
  { List* self = this;

    { Iterator* iterator = self->the_cons_list->allocate_destructive_list_iterator();

      self->the_cons_list = NIL;
      self->free();
      return (iterator);
    }
  }
}

boolean All_Purpose_Iterator::nextP() {
  // Apply the stored 'next?' function to 'self'.
  { All_Purpose_Iterator* self = this;

    return (((boolean (*) (All_Purpose_Iterator*))self->iterator_next_code)(self));
  }
}

boolean All_Purpose_Iterator::emptyP() {
  { All_Purpose_Iterator* self = this;

    if (self->iterator_empty_code == NULL) {
      cerr << "Missing 'empty?' method";
    }
    return (((boolean (*) ())self->iterator_empty_code)());
  }
}

boolean All_Purpose_Iterator::terminate_all_purpose_iteratorP() {
  { All_Purpose_Iterator* self = this;

    if (self->iterator_cons_list != NULL) {
      free_cons_list(self->iterator_cons_list);
    }
    if (self->iterator_nested_iterator != NULL) {
      self->iterator_nested_iterator->free();
    }
    return (TRUE);
  }
}

boolean filtered_nested_iterator_nextP(All_Purpose_Iterator* self) {
  { Iterator* nestediterator = self->iterator_nested_iterator;
    Object* value = NULL;

    while (nestediterator->nextP()) {
      value = nestediterator->value;
      if (((boolean (*) (Object*, All_Purpose_Iterator*))self->iterator_filter_code)(value, self)) {
        self->value = value;
        return (TRUE);
      }
    }
    return (FALSE);
  }
}

boolean iterator_cons_list_nextP(All_Purpose_Iterator* self) {
  if (self->first_iterationP) {
    self->first_iterationP = FALSE;
  }
  else {
    self->iterator_cons_list = self->iterator_cons_list->rest;
  }
  self->value = self->iterator_cons_list->value;
  return (self->iterator_cons_list->non_emptyP());
}

boolean iterator_cons_list_emptyP(All_Purpose_Iterator* self) {
  return (self->iterator_cons_list->emptyP());
}

boolean filtered_concatenated_iterator_nextP(All_Purpose_Iterator* self) {
  { Iterator* nestediterator = self->iterator_nested_iterator;
    cpp_function_code filtercode = self->iterator_filter_code;
    Object* value = NULL;

    for (;;) {
      while (nestediterator->nextP()) {
        value = nestediterator->value;
        if (((filtercode != NULL) ? ((boolean)(((boolean (*) (Object*, All_Purpose_Iterator*))filtercode)(value, self))) : ((boolean)(TRUE)))) {
          self->value = value;
          return (TRUE);
        }
      }
      nestediterator = ((Iterator*)(self->iterator_cons_list->value));
      self->iterator_cons_list = self->iterator_cons_list->rest;
      if (nestediterator == NULL) {
        break;
      }
      else {
        self->iterator_nested_iterator = nestediterator;
      }
    }
    return (FALSE);
  }
}

All_Purpose_Iterator* Iterator::concatenate(Iterator* iterator2) {
  // Return an iterator that first generates all values of
  // `iterator1' and then those of `iterator2'.  The generated values can be
  // filtered by supplying a filter function to the resulting iterator.
  { Iterator* iterator1 = this;

    { All_Purpose_Iterator* self_001 = new_all_purpose_iterator();

      self_001->iterator_nested_iterator = iterator1;
      self_001->iterator_cons_list = cons(iterator2, NIL);
      self_001->iterator_next_code = ((cpp_function_code)(&filtered_concatenated_iterator_nextP));
      { All_Purpose_Iterator* value_001 = self_001;

        return (value_001);
      }
    }
  }
}

void Integer_Interval_Iterator::initialize_integer_interval_iterator() {
  { Integer_Interval_Iterator* self = this;

    self->interval_cursor = self->lower_bound;
    self->first_iterationP = TRUE;
  }
}

boolean Integer_Interval_Iterator::nextP() {
  { Integer_Interval_Iterator* self = this;

    if (self->first_iterationP) {
      self->first_iterationP = FALSE;
    }
    else {
      self->interval_cursor = self->interval_cursor + 1;
    }
    { int upperbound = self->upper_bound;

      self->value = self->interval_cursor;
      return ((upperbound == NULL_INTEGER) ||
          (self->interval_cursor <= upperbound));
    }
  }
}

Integer_Interval_Iterator* interval(int lowerbound, int upperbound) {
  return (new_integer_interval_iterator(lowerbound, upperbound));
}

Reverse_Integer_Interval_Iterator* Integer_Interval_Iterator::reverse() {
  { Integer_Interval_Iterator* self = this;

    return (reverse_interval(self->lower_bound, self->upper_bound));
  }
}

void initialize_reverse_integer_interval_iterator(Reverse_Integer_Interval_Iterator* self) {
  self->interval_cursor = self->upper_bound;
  self->first_iterationP = TRUE;
}

boolean Reverse_Integer_Interval_Iterator::nextP() {
  { Reverse_Integer_Interval_Iterator* self = this;

    if (self->first_iterationP) {
      self->first_iterationP = FALSE;
    }
    else {
      self->interval_cursor = self->interval_cursor - 1;
    }
    { int lowerbound = self->lower_bound;

      self->value = self->interval_cursor;
      return ((lowerbound == NULL_INTEGER) ||
          (self->interval_cursor >= lowerbound));
    }
  }
}

Reverse_Integer_Interval_Iterator* reverse_interval(int lowerbound, int upperbound) {
  // Create a reverse interval object.
  return (new_reverse_integer_interval_iterator(lowerbound, upperbound));
}

Abstract_Iterator* Vector::allocate_iterator() {
  { Vector* self = this;

    { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

      iterator->iterator_object = self;
      iterator->iterator_integer = 0;
      iterator->iterator_second_integer = self->array_size;
      iterator->iterator_next_code = ((cpp_function_code)(&vector_nextP));
      return (iterator);
    }
  }
}

boolean vector_nextP(All_Purpose_Iterator* self) {
  { int cursor = self->iterator_integer;

    if (cursor < self->iterator_second_integer) {
      self->value = ((Vector*)(self->iterator_object))->nth(cursor);
      self->iterator_integer = cursor + 1;
      return (TRUE);
    }
    return (FALSE);
  }
}

Iterator* Vector::but_last() {
  // Generate all but the last element of the vector 'self'.
  { Vector* self = this;

    { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

      iterator->iterator_object = self;
      iterator->iterator_integer = 0;
      iterator->iterator_second_integer = self->array_size - 1;
      iterator->iterator_next_code = ((cpp_function_code)(&vector_nextP));
      return (iterator);
    }
  }
}

String_Iterator* string_allocate_iterator(char* self) {
  { String_Iterator* self_001 = new_string_iterator();

    self_001->the_string = self;
    { String_Iterator* iterator = self_001;

      iterator->cursor = 0;
      iterator->end = string_length(self);
      return (iterator);
    }
  }
}

boolean String_Iterator::nextP() {
  { String_Iterator* self = this;

    { int pos = self->cursor;

      if (pos < self->end) {
        self->value = string_nth(self->the_string, pos);
        self->cursor = pos + 1;
        return (TRUE);
      }
      return (FALSE);
    }
  }
}

Cons* yield_modules_list(Module* module, boolean localP) {
  { Cons* moduleslist = NIL;

    if (module != NULL) {
      if (localP) {
        moduleslist = cons(module, moduleslist);
      }
      else {
        { Module* mod = NULL;
          Iterator* iter_001 = visible_modules(module);
          Cons* collect_001 = NULL;

          while (iter_001->nextP()) {
            {
              mod = ((Module*)(iter_001->value));
            }
            if (collect_001 == NULL) {
              {
                collect_001 = cons(mod, NIL);
                if (nilP(moduleslist)) {
                  moduleslist = collect_001;
                }
                else {
                  add_cons_to_end_of_cons_list(moduleslist, collect_001);
                }
              }
            }
            else {
              {
                collect_001->rest = cons(mod, NIL);
                collect_001 = collect_001->rest;
              }
            }
          }
        }
      }
    }
    return (moduleslist);
  }
}

Iterator* allocate_all_meta_objects_iterator(int arraysize, cpp_function_code nextcode, Module* module, boolean localP) {
  { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

    iterator->iterator_integer = 0;
    iterator->iterator_second_integer = arraysize;
    { Cons* moduleslist = NIL;

      if (module != NULL) {
        if (localP) {
          moduleslist = cons(module, moduleslist);
        }
        else {
          { Module* mod = NULL;
            Iterator* iter_001 = visible_modules(module);
            Cons* collect_001 = NULL;

            while (iter_001->nextP()) {
              {
                mod = ((Module*)(iter_001->value));
              }
              if (collect_001 == NULL) {
                {
                  collect_001 = cons(mod, NIL);
                  if (nilP(moduleslist)) {
                    moduleslist = collect_001;
                  }
                  else {
                    add_cons_to_end_of_cons_list(moduleslist, collect_001);
                  }
                }
              }
              else {
                {
                  collect_001->rest = cons(mod, NIL);
                  collect_001 = collect_001->rest;
                }
              }
            }
          }
        }
      }
      iterator->iterator_cons_list = moduleslist;
    }
    iterator->iterator_next_code = nextcode;
    return (iterator);
  }
}

boolean all_symbols_nextP(All_Purpose_Iterator* self) {
  { int cursor = self->iterator_integer;
    Cons* modules = self->iterator_cons_list;
    Symbol* symbol = NULL;

    while (cursor < self->iterator_second_integer) {
      symbol = ((Symbol*)(oSYMBOL_ARRAYo->nth(cursor)));
      if ((symbol != NULL) &&
          (nilP(modules) ||
           modules->memberP(((Module*)(symbol->home_context))))) {
        self->value = symbol;
        self->iterator_integer = cursor + 1;
        return (TRUE);
      }
      cursor = cursor + 1;
    }
    return (FALSE);
  }
}

Iterator* all_symbols(Module* module, boolean localP) {
  // Iterate over all symbols visible from 'module'.
  // If 'local?', return only symbols interned in 'module'.
  // If 'module' is null, return all symbols interned everywhere.
  return (allocate_all_meta_objects_iterator(oSYMBOL_ARRAYo->top_symbol_offset + 1, ((cpp_function_code)(&all_symbols_nextP)), module, localP));
}

boolean filter_public_slotP(Slot* self, All_Purpose_Iterator* iterator) {
  iterator = iterator;
  return (self->slot_publicP);
}

boolean filter_private_slotP(Slot* self, All_Purpose_Iterator* iterator) {
  iterator = iterator;
  return (!self->slot_publicP);
}

boolean filter_method_slotP(Slot* self, All_Purpose_Iterator* iterator) {
  iterator = iterator;
  return (method_slotP(self));
}

boolean filter_public_method_slotP(Slot* self, All_Purpose_Iterator* iterator) {
  iterator = iterator;
  return (self->slot_publicP &&
      method_slotP(self));
}

boolean filter_non_external_slotP(Slot* self, All_Purpose_Iterator* iterator) {
  iterator = iterator;
  return (!self->slot_externalP);
}

boolean filter_non_parameter_slotP(Slot* self, All_Purpose_Iterator* iterator) {
  iterator = iterator;
  return (!((Class*)(self->slot_owner->surrogate_value))->class_parameters_reader()->memberP(self->slot_name));
}

boolean filter_non_auxiliary_slotP(Slot* self, All_Purpose_Iterator* iterator) {
  iterator = iterator;
  return (!self->slot_auxiliaryP_reader());
}

boolean filter_slotP(Slot* self, All_Purpose_Iterator* iterator) {
  { boolean alwaysP_001 = TRUE;

    { Function_Code_Wrapper* filter = NULL;
      Cons* iter_001 = ((Cons*)(iterator->iterator_object));

      while (!nilP(iter_001)) {
        {
          filter = ((Function_Code_Wrapper*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (!((boolean (*) (Slot*, All_Purpose_Iterator*))filter->wrapper_value)(self, iterator)) {
          alwaysP_001 = FALSE;
          break;
        }
      }
    }
    { boolean value_001 = alwaysP_001;

      return (value_001);
    }
  }
}

boolean all_functions_nextP(All_Purpose_Iterator* self) {
  { int cursor = self->iterator_integer;
    Cons* modules = self->iterator_cons_list;
    Symbol* symbol = NULL;
    Method_Slot* function = NULL;

    while (cursor < self->iterator_second_integer) {
      symbol = ((Symbol*)(oSYMBOL_ARRAYo->nth(cursor)));
      if ((symbol != NULL) &&
          (nilP(modules) ||
           modules->memberP(((Module*)(symbol->home_context))))) {
        function = ((Method_Slot*)(oFUNCTION_LOOKUP_TABLEo->lookup(symbol)));
        if ((function != NULL) &&
            ((self->iterator_filter_code == NULL) ||
             ((boolean (*) (Method_Slot*, All_Purpose_Iterator*))self->iterator_filter_code)(function, self))) {
          self->value = function;
          self->iterator_integer = cursor + 1;
          return (TRUE);
        }
      }
      cursor = cursor + 1;
    }
    return (FALSE);
  }
}

Iterator* all_functions(Module* module, boolean localP) {
  // Iterate over all functions visible from 'module'.
  // If 'local?', return only functions bound to symbols interned in 'module'.
  // If 'module' is null, return all functions defined everywhere.
  return (allocate_all_meta_objects_iterator(oSYMBOL_ARRAYo->top_symbol_offset + 1, ((cpp_function_code)(&all_functions_nextP)), module, localP));
}

Iterator* all_public_functions(Module* module, boolean localP) {
  // Iterate over all functions visible from 'module'.
  // If 'local?', return only functions bound to symbols interned in 'module'.
  // If 'module' is null, return all functions defined everywhere.
  { All_Purpose_Iterator* iterator = ((All_Purpose_Iterator*)(all_functions(module, localP)));

    iterator->iterator_filter_code = ((cpp_function_code)(&filter_public_slotP));
    return (iterator);
  }
}

boolean all_variables_nextP(All_Purpose_Iterator* self) {
  { int cursor = self->iterator_integer;
    Cons* modules = self->iterator_cons_list;
    Symbol* symbol = NULL;
    Global_Variable* variable = NULL;

    while (cursor < self->iterator_second_integer) {
      symbol = ((Symbol*)(oSYMBOL_ARRAYo->nth(cursor)));
      if ((symbol != NULL) &&
          (nilP(modules) ||
           modules->memberP(((Module*)(symbol->home_context))))) {
        variable = ((Global_Variable*)(oGLOBAL_VARIABLE_LOOKUP_TABLEo->lookup(symbol)));
        if ((variable != NULL) &&
            ((self->iterator_filter_code == NULL) ||
             ((boolean (*) (Global_Variable*, All_Purpose_Iterator*))self->iterator_filter_code)(variable, self))) {
          self->value = variable;
          self->iterator_integer = cursor + 1;
          return (TRUE);
        }
      }
      cursor = cursor + 1;
    }
    return (FALSE);
  }
}

Iterator* all_variables(Module* module, boolean localP) {
  // Iterate over all variables visible from 'module'.
  // If 'local?', return only variables bound to symbols interned in 'module'.
  // If 'module' is null, return all variables defined everywhere.
  return (allocate_all_meta_objects_iterator(oSYMBOL_ARRAYo->top_symbol_offset + 1, ((cpp_function_code)(&all_variables_nextP)), module, localP));
}

boolean all_surrogates_nextP(All_Purpose_Iterator* self) {
  { int cursor = self->iterator_integer;
    Cons* modules = self->iterator_cons_list;
    Surrogate* surrogate = NULL;

    while (cursor < self->iterator_second_integer) {
      surrogate = ((Surrogate*)(oSURROGATE_ARRAYo->nth(cursor)));
      if ((surrogate != NULL) &&
          (nilP(modules) ||
           modules->memberP(((Module*)(surrogate->home_context))))) {
        self->value = surrogate;
        self->iterator_integer = cursor + 1;
        return (TRUE);
      }
      cursor = cursor + 1;
    }
    return (FALSE);
  }
}

Iterator* all_surrogates(Module* module, boolean localP) {
  // Iterate over all surrogates visible from 'module'.
  // If 'local?', return only surrogates interned in 'module'.
  // If 'module' is null, return all surrogates interned everywhere.
  return (allocate_all_meta_objects_iterator(oSURROGATE_ARRAYo->top_symbol_offset + 1, ((cpp_function_code)(&all_surrogates_nextP)), module, localP));
}

boolean all_classes_nextP(All_Purpose_Iterator* self) {
  { int cursor = self->iterator_integer;
    Cons* modules = self->iterator_cons_list;
    Surrogate* surrogate = NULL;
    Object* value = NULL;

    while (cursor < self->iterator_second_integer) {
      surrogate = ((Surrogate*)(oSURROGATE_ARRAYo->nth(cursor)));
      if ((surrogate != NULL) &&
          (nilP(modules) ||
           modules->memberP(((Module*)(surrogate->home_context))))) {
        value = surrogate->surrogate_value;
        if ((value != NULL) &&
            (classP(value) &&
             (((Class*)(value))->class_type == surrogate))) {
          self->value = value;
          self->iterator_integer = cursor + 1;
          return (TRUE);
        }
      }
      cursor = cursor + 1;
    }
    return (FALSE);
  }
}

Iterator* all_classes(Module* module, boolean localP) {
  // Iterate over all classes visible from 'module'.
  // If 'local?', return only classes interned in 'module'.
  // If 'module' is null, return all classes interned everywhere.
  return (allocate_all_meta_objects_iterator(oSURROGATE_ARRAYo->top_symbol_offset + 1, ((cpp_function_code)(&all_classes_nextP)), module, localP));
}

boolean slots_nextP(All_Purpose_Iterator* self) {
  { Slot* slot = NULL;

    for (;;) {
      for (;;) {
        { 
          slot = ((Slot*)(self->iterator_cons_list->first()));
          if (!(slot != NULL)) {
            break;
          }
        }
        self->iterator_cons_list = self->iterator_cons_list->rest;
        if ((self->iterator_filter_code == NULL) ||
            ((boolean (*) (Slot*, All_Purpose_Iterator*))self->iterator_filter_code)(slot, self)) {
          self->value = slot;
          return (TRUE);
        }
      }
      if (!self->iterator_nested_iterator->nextP()) {
        return (FALSE);
      }
      self->iterator_cons_list = ((Class*)(self->iterator_nested_iterator->value))->class_local_slots->the_cons_list;
    }
  }
}

Iterator* all_slots(Module* module, boolean localP) {
  // Iterate over all slots visible from 'module'.
  // If 'local?', return only methods interned in 'module'.
  // If 'module' is null, return all methods interned everywhere.
  { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

    iterator->iterator_next_code = ((cpp_function_code)(&slots_nextP));
    iterator->iterator_nested_iterator = all_classes(module, localP);
    iterator->iterator_cons_list = NIL;
    return (iterator);
  }
}

Iterator* all_methods(Module* module, boolean localP) {
  // Iterate over all methods visible from 'module'.
  // If 'local?', return only methods interned in 'module'.
  // If 'module' is null, return all methods interned everywhere.
  { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

    iterator->iterator_next_code = ((cpp_function_code)(&slots_nextP));
    iterator->iterator_nested_iterator = all_classes(module, localP);
    iterator->iterator_filter_code = ((cpp_function_code)(&filter_method_slotP));
    iterator->iterator_cons_list = NIL;
    return (iterator);
  }
}

Iterator* all_public_methods(Module* module, boolean localP) {
  // Iterate over all public methods visible from 'module'.
  // If 'local?', return only methods interned in 'module'.
  // If 'module' is null, return all methods interned everywhere.
  { All_Purpose_Iterator* iterator = ((All_Purpose_Iterator*)(all_slots(module, localP)));

    iterator->iterator_filter_code = ((cpp_function_code)(&filter_public_method_slotP));
    return (iterator);
  }
}

boolean class_methods_nextP(All_Purpose_Iterator* self) {
  { Slot* slot = NULL;

    for (;;) {
      { 
        slot = ((Slot*)(self->iterator_cons_list->first()));
        if (!(slot != NULL)) {
          break;
        }
      }
      self->iterator_cons_list = self->iterator_cons_list->rest;
      if (method_slotP(slot) &&
          ((self->iterator_filter_code == NULL) ||
           ((boolean (*) (Slot*, All_Purpose_Iterator*))self->iterator_filter_code)(slot, self))) {
        self->value = slot;
        return (TRUE);
      }
    }
    return (FALSE);
  }
}

Iterator* class_methods(Class* renamed_Class, Cons* filters) {
  { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

    iterator->iterator_next_code = ((cpp_function_code)(&class_methods_nextP));
    iterator->iterator_cons_list = renamed_Class->class_local_slots->the_cons_list;
    iterator->iterator_object = filters;
    iterator->iterator_filter_code = ((cpp_function_code)(&filter_slotP));
    return (iterator);
  }
}

Iterator* public_class_methods(Class* renamed_Class) {
  // Iterate over all private methods attached to 'class'.
  return (class_methods(renamed_Class, cons(function_code_wrap_literal(((cpp_function_code)(&filter_public_slotP))), cons(function_code_wrap_literal(((cpp_function_code)(&filter_non_external_slotP))), cons(function_code_wrap_literal(((cpp_function_code)(&filter_non_auxiliary_slotP))), NIL)))));
}

Iterator* private_class_methods(Class* renamed_Class) {
  // Iterate over all private methods attached to 'class'.
  return (class_methods(renamed_Class, cons(function_code_wrap_literal(((cpp_function_code)(&filter_private_slotP))), cons(function_code_wrap_literal(((cpp_function_code)(&filter_non_external_slotP))), cons(function_code_wrap_literal(((cpp_function_code)(&filter_non_auxiliary_slotP))), NIL)))));
}

boolean class_storage_slots_nextP(All_Purpose_Iterator* self) {
  { Slot* slot = NULL;

    for (;;) {
      { 
        slot = ((Slot*)(self->iterator_cons_list->first()));
        if (!(slot != NULL)) {
          break;
        }
      }
      self->iterator_cons_list = self->iterator_cons_list->rest;
      if (storage_slotP(slot) &&
          ((self->iterator_filter_code == NULL) ||
           ((boolean (*) (Slot*, All_Purpose_Iterator*))self->iterator_filter_code)(slot, self))) {
        self->value = slot;
        return (TRUE);
      }
    }
    return (FALSE);
  }
}

Iterator* class_storage_slots(Class* renamed_Class, Cons* filters) {
  { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

    iterator->iterator_next_code = ((cpp_function_code)(&class_storage_slots_nextP));
    iterator->iterator_cons_list = renamed_Class->class_local_slots->the_cons_list;
    iterator->iterator_object = filters;
    iterator->iterator_filter_code = ((cpp_function_code)(&filter_slotP));
    return (iterator);
  }
}

boolean class_tables_nextP(All_Purpose_Iterator* self) {
  { Slot* slot = NULL;

    for (;;) {
      { 
        slot = ((Slot*)(self->iterator_cons_list->first()));
        if (!(slot != NULL)) {
          break;
        }
      }
      self->iterator_cons_list = self->iterator_cons_list->rest;
      if (isaP(slot, SGT_ITERATORS_TABLE) &&
          ((self->iterator_filter_code == NULL) ||
           ((boolean (*) (Slot*, All_Purpose_Iterator*))self->iterator_filter_code)(slot, self))) {
        self->value = slot;
        return (TRUE);
      }
    }
    return (FALSE);
  }
}

Iterator* class_tables(Class* renamed_Class, Cons* filters) {
  { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

    iterator->iterator_next_code = ((cpp_function_code)(&class_tables_nextP));
    iterator->iterator_cons_list = renamed_Class->class_local_slots->the_cons_list;
    iterator->iterator_object = filters;
    iterator->iterator_filter_code = ((cpp_function_code)(&filter_slotP));
    return (iterator);
  }
}

Iterator* public_class_storage_slots(Class* renamed_Class) {
  // Iterate over all public storage-slots attached to 'class'.
  return (class_storage_slots(renamed_Class, cons(function_code_wrap_literal(((cpp_function_code)(&filter_public_slotP))), cons(function_code_wrap_literal(((cpp_function_code)(&filter_non_parameter_slotP))), cons(function_code_wrap_literal(((cpp_function_code)(&filter_non_external_slotP))), cons(function_code_wrap_literal(((cpp_function_code)(&filter_non_auxiliary_slotP))), NIL))))));
}

Iterator* private_class_storage_slots(Class* renamed_Class) {
  // Iterate over all private storage-slots attached to 'class'.
  return (class_storage_slots(renamed_Class, cons(function_code_wrap_literal(((cpp_function_code)(&filter_private_slotP))), cons(function_code_wrap_literal(((cpp_function_code)(&filter_non_parameter_slotP))), cons(function_code_wrap_literal(((cpp_function_code)(&filter_non_external_slotP))), cons(function_code_wrap_literal(((cpp_function_code)(&filter_non_auxiliary_slotP))), NIL))))));
}

void startup_iterators() {
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
            SGT_ITERATORS_TABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TABLE", NULL, 1)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-ITERATOR", "ABSTRACT-ITERATOR", "(DEFMETHOD (ALLOCATE-ITERATOR (LIKE SELF)) ((SELF ABSTRACT-ITERATOR)) :DOCUMENTATION \"Iterator objects return themselves when asked\nfor an iterator (they occupy the same position as a collection\nwithin a 'foreach' statement).\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Abstract_Iterator::allocate_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("LENGTH", "ABSTRACT-ITERATOR", "(DEFMETHOD (LENGTH INTEGER) ((SELF ABSTRACT-ITERATOR)) :DOCUMENTATION \"Iterate over 'self', and count how many\nitems there are.  Bad idea if 'self' iterates over an infinite\ncollection, since in that case it will run forever.'\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Abstract_Iterator::length));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP", "ITERATOR", "(DEFMETHOD (POP (LIKE (ANY-VALUE SELF))) ((SELF ITERATOR)) :DOCUMENTATION \"Return the first item of the sequence represented by 'self',\nor NULL if it is empty.  Destructively uses up the first iteration element.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Iterator::pop));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADVANCE", "ITERATOR", "(DEFMETHOD (ADVANCE (LIKE SELF)) ((SELF ITERATOR) (N INTEGER)) :DOCUMENTATION \"Return 'self' after skipping over the first\n'n' elements in the (remainder of the) iteration.\")");

              method->method_code = ((cpp_method_code)(&Iterator::advance));
            }
            { Method_Slot* method = define_method_from_stringified_source("EMPTY?", "ITERATOR", "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF ITERATOR)) :DOCUMENTATION \"Return TRUE if the sequence represented by 'self'\nhas no elements.  Side-effect free.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Iterator::emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MEMBER?", "ITERATOR", "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF ITERATOR) (VALUE OBJECT)) :DOCUMENTATION \"Iterate over values of 'self', returning TRUE\nif one of them is 'eql' to 'value.\")");

              method->method_code = ((cpp_method_code)(&Iterator::memberP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "DESTRUCTIVE-LIST-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF DESTRUCTIVE-LIST-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Destructive_List_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EMPTY?", "DESTRUCTIVE-LIST-ITERATOR", "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF DESTRUCTIVE-LIST-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Destructive_List_Iterator::emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-DESTRUCTIVE-LIST-ITERATOR?", "DESTRUCTIVE-LIST-ITERATOR", "(DEFUN (TERMINATE-DESTRUCTIVE-LIST-ITERATOR? BOOLEAN) ((SELF DESTRUCTIVE-LIST-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&terminate_destructive_list_iteratorP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT", "DESTRUCTIVE-LIST-ITERATOR", "(DEFMETHOD INSERT ((SELF DESTRUCTIVE-LIST-ITERATOR) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Add 'value' to the front of the list 'self'.\")");

              method->method_code = ((cpp_method_code)(&Destructive_List_Iterator::insert));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-DESTRUCTIVE-LIST-ITERATOR", "CONS", "(DEFMETHOD (ALLOCATE-DESTRUCTIVE-LIST-ITERATOR (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF CONS)))");

              method->method_code = ((cpp_method_code)(&Cons::allocate_destructive_list_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-DESTRUCTIVE-LIST-ITERATOR", "LIST", "(DEFMETHOD (ALLOCATE-DESTRUCTIVE-LIST-ITERATOR (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF LIST)))");

              method->method_code = ((cpp_method_code)(&List::allocate_destructive_list_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)) :DOCUMENTATION \"Apply the stored 'next?' function to 'self'.\")");

              method->method_code = ((cpp_method_code)(&All_Purpose_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EMPTY?", "ALL-PURPOSE-ITERATOR", "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&All_Purpose_Iterator::emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-ALL-PURPOSE-ITERATOR?", "ALL-PURPOSE-ITERATOR", "(DEFMETHOD (TERMINATE-ALL-PURPOSE-ITERATOR? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&All_Purpose_Iterator::terminate_all_purpose_iteratorP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTERED-NESTED-ITERATOR-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (FILTERED-NESTED-ITERATOR-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filtered_nested_iterator_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ITERATOR-CONS-LIST-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ITERATOR-CONS-LIST-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&iterator_cons_list_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ITERATOR-CONS-LIST-EMPTY?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ITERATOR-CONS-LIST-EMPTY? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&iterator_cons_list_emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTERED-CONCATENATED-ITERATOR-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (FILTERED-CONCATENATED-ITERATOR-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filtered_concatenated_iterator_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONCATENATE", "ITERATOR", "(DEFMETHOD (CONCATENATE ALL-PURPOSE-ITERATOR) ((ITERATOR1 ITERATOR) (ITERATOR2 ITERATOR)) :DOCUMENTATION \"Return an iterator that first generates all values of\n`iterator1' and then those of `iterator2'.  The generated values can be\nfiltered by supplying a filter function to the resulting iterator.\")");

              method->method_code = ((cpp_method_code)(&Iterator::concatenate));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-INTEGER-INTERVAL-ITERATOR", "INTEGER-INTERVAL-ITERATOR", "(DEFMETHOD INITIALIZE-INTEGER-INTERVAL-ITERATOR ((SELF INTEGER-INTERVAL-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Integer_Interval_Iterator::initialize_integer_interval_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "INTEGER-INTERVAL-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF INTEGER-INTERVAL-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Integer_Interval_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERVAL", "INTEGER", "(DEFUN (INTERVAL INTEGER-INTERVAL-ITERATOR) ((LOWERBOUND INTEGER) (UPPERBOUND INTEGER)))");

              method->function_code = ((cpp_function_code)(&interval));
            }
            { Method_Slot* method = define_method_from_stringified_source("REVERSE", "INTEGER-INTERVAL-ITERATOR", "(DEFMETHOD (REVERSE REVERSE-INTEGER-INTERVAL-ITERATOR) ((SELF INTEGER-INTERVAL-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Integer_Interval_Iterator::reverse));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-REVERSE-INTEGER-INTERVAL-ITERATOR", "REVERSE-INTEGER-INTERVAL-ITERATOR", "(DEFUN INITIALIZE-REVERSE-INTEGER-INTERVAL-ITERATOR ((SELF REVERSE-INTEGER-INTERVAL-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&initialize_reverse_integer_interval_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "REVERSE-INTEGER-INTERVAL-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF REVERSE-INTEGER-INTERVAL-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Reverse_Integer_Interval_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("REVERSE-INTERVAL", "INTEGER", "(DEFUN (REVERSE-INTERVAL REVERSE-INTEGER-INTERVAL-ITERATOR) ((LOWERBOUND INTEGER) (UPPERBOUND INTEGER)) :DOCUMENTATION \"Create a reverse interval object.\")");

              method->function_code = ((cpp_function_code)(&reverse_interval));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-ITERATOR", "VECTOR", "(DEFMETHOD (ALLOCATE-ITERATOR (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF VECTOR)))");

              method->method_code = ((cpp_method_code)(&Vector::allocate_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("VECTOR-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (VECTOR-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&vector_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUT-LAST", "VECTOR", "(DEFMETHOD (BUT-LAST (ITERATOR OF (LIKE (ANY-VALUE SELF)))) ((SELF VECTOR)) :DOCUMENTATION \"Generate all but the last element of the vector 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Vector::but_last));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-ITERATOR", "STRING", "(DEFMETHOD (ALLOCATE-ITERATOR STRING-ITERATOR) ((SELF STRING)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "STRING-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF STRING-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&String_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-MODULES-LIST", "MODULE", "(DEFUN (YIELD-MODULES-LIST (CONS OF MODULE)) ((MODULE MODULE) (LOCAL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&yield_modules_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-ALL-META-OBJECTS-ITERATOR", "INTEGER", "(DEFUN (ALLOCATE-ALL-META-OBJECTS-ITERATOR ITERATOR) ((ARRAYSIZE INTEGER) (NEXTCODE FUNCTION-CODE) (MODULE MODULE) (LOCAL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&allocate_all_meta_objects_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-SYMBOLS-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ALL-SYMBOLS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&all_symbols_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-SYMBOLS", "MODULE", "(DEFUN (ALL-SYMBOLS (ITERATOR OF SYMBOL)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all symbols visible from 'module'.\nIf 'local?', return only symbols interned in 'module'.\nIf 'module' is null, return all symbols interned everywhere.\")");

              method->function_code = ((cpp_function_code)(&all_symbols));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-PUBLIC-SLOT?", "SLOT", "(DEFUN (FILTER-PUBLIC-SLOT? BOOLEAN) ((SELF SLOT) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_public_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-PRIVATE-SLOT?", "SLOT", "(DEFUN (FILTER-PRIVATE-SLOT? BOOLEAN) ((SELF SLOT) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_private_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-METHOD-SLOT?", "SLOT", "(DEFUN (FILTER-METHOD-SLOT? BOOLEAN) ((SELF SLOT) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_method_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-PUBLIC-METHOD-SLOT?", "SLOT", "(DEFUN (FILTER-PUBLIC-METHOD-SLOT? BOOLEAN) ((SELF SLOT) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_public_method_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-NON-EXTERNAL-SLOT?", "SLOT", "(DEFUN (FILTER-NON-EXTERNAL-SLOT? BOOLEAN) ((SELF SLOT) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_non_external_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-NON-PARAMETER-SLOT?", "SLOT", "(DEFUN (FILTER-NON-PARAMETER-SLOT? BOOLEAN) ((SELF SLOT) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_non_parameter_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-NON-AUXILIARY-SLOT?", "SLOT", "(DEFUN (FILTER-NON-AUXILIARY-SLOT? BOOLEAN) ((SELF SLOT) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_non_auxiliary_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-SLOT?", "SLOT", "(DEFUN (FILTER-SLOT? BOOLEAN) ((SELF SLOT) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-FUNCTIONS-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ALL-FUNCTIONS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&all_functions_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-FUNCTIONS", "MODULE", "(DEFUN (ALL-FUNCTIONS (ITERATOR OF FUNCTION)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all functions visible from 'module'.\nIf 'local?', return only functions bound to symbols interned in 'module'.\nIf 'module' is null, return all functions defined everywhere.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_functions));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-PUBLIC-FUNCTIONS", "MODULE", "(DEFUN (ALL-PUBLIC-FUNCTIONS (ITERATOR OF FUNCTION)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all functions visible from 'module'.\nIf 'local?', return only functions bound to symbols interned in 'module'.\nIf 'module' is null, return all functions defined everywhere.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_public_functions));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-VARIABLES-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ALL-VARIABLES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&all_variables_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-VARIABLES", "MODULE", "(DEFUN (ALL-VARIABLES (ITERATOR OF GLOBAL-VARIABLE)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all variables visible from 'module'.\nIf 'local?', return only variables bound to symbols interned in 'module'.\nIf 'module' is null, return all variables defined everywhere.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_variables));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-SURROGATES-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ALL-SURROGATES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&all_surrogates_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-SURROGATES", "MODULE", "(DEFUN (ALL-SURROGATES (ITERATOR OF SURROGATE)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all surrogates visible from 'module'.\nIf 'local?', return only surrogates interned in 'module'.\nIf 'module' is null, return all surrogates interned everywhere.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_surrogates));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-CLASSES-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ALL-CLASSES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&all_classes_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-CLASSES", "MODULE", "(DEFUN (ALL-CLASSES (ITERATOR OF CLASS)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all classes visible from 'module'.\nIf 'local?', return only classes interned in 'module'.\nIf 'module' is null, return all classes interned everywhere.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_classes));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOTS-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (SLOTS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&slots_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-SLOTS", "MODULE", "(DEFUN (ALL-SLOTS (ITERATOR OF SLOT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all slots visible from 'module'.\nIf 'local?', return only methods interned in 'module'.\nIf 'module' is null, return all methods interned everywhere.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-METHODS", "MODULE", "(DEFUN (ALL-METHODS (ITERATOR OF METHOD-SLOT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all methods visible from 'module'.\nIf 'local?', return only methods interned in 'module'.\nIf 'module' is null, return all methods interned everywhere.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_methods));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-PUBLIC-METHODS", "MODULE", "(DEFUN (ALL-PUBLIC-METHODS (ITERATOR OF METHOD-SLOT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all public methods visible from 'module'.\nIf 'local?', return only methods interned in 'module'.\nIf 'module' is null, return all methods interned everywhere.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_public_methods));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-METHODS-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (CLASS-METHODS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&class_methods_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-METHODS", "CLASS", "(DEFUN (CLASS-METHODS (ITERATOR OF METHOD-SLOT)) ((CLASS CLASS) (FILTERS (CONS OF FUNCTION-WRAPPER))))");

              method->function_code = ((cpp_function_code)(&class_methods));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUBLIC-CLASS-METHODS", "CLASS", "(DEFUN (PUBLIC-CLASS-METHODS (ITERATOR OF METHOD-SLOT)) ((CLASS CLASS)) :DOCUMENTATION \"Iterate over all private methods attached to 'class'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&public_class_methods));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRIVATE-CLASS-METHODS", "CLASS", "(DEFUN (PRIVATE-CLASS-METHODS (ITERATOR OF METHOD-SLOT)) ((CLASS CLASS)) :DOCUMENTATION \"Iterate over all private methods attached to 'class'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&private_class_methods));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-STORAGE-SLOTS-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (CLASS-STORAGE-SLOTS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&class_storage_slots_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-STORAGE-SLOTS", "CLASS", "(DEFUN (CLASS-STORAGE-SLOTS (ITERATOR OF STORAGE-SLOT)) ((CLASS CLASS) (FILTERS (CONS OF FUNCTION-CODE-WRAPPER))))");

              method->function_code = ((cpp_function_code)(&class_storage_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-TABLES-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (CLASS-TABLES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&class_tables_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-TABLES", "CLASS", "(DEFUN (CLASS-TABLES (ITERATOR OF TABLE)) ((CLASS CLASS) (FILTERS (CONS OF FUNCTION-CODE-WRAPPER))))");

              method->function_code = ((cpp_function_code)(&class_tables));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUBLIC-CLASS-STORAGE-SLOTS", "CLASS", "(DEFUN (PUBLIC-CLASS-STORAGE-SLOTS (ITERATOR OF STORAGE-SLOT)) ((CLASS CLASS)) :DOCUMENTATION \"Iterate over all public storage-slots attached to 'class'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&public_class_storage_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRIVATE-CLASS-STORAGE-SLOTS", "CLASS", "(DEFUN (PRIVATE-CLASS-STORAGE-SLOTS (ITERATOR OF STORAGE-SLOT)) ((CLASS CLASS)) :DOCUMENTATION \"Iterate over all private storage-slots attached to 'class'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&private_class_storage_slots));
            }
            define_method_from_stringified_source("STARTUP-ITERATORS", NULL, "(DEFUN STARTUP-ITERATORS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
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

