// specialize.cc

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | 
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

Symbol* SYM_SPECIALIZE_PROPOSITION_CURSOR = NULL;

Symbol* SYM_SPECIALIZE_KIND_OF_PROPOSITION = NULL;

Symbol* SYM_SPECIALIZE_ATTRIBUTE_PROPOSITIONSp = NULL;

Symbol* SYM_SPECIALIZE_VARIABLE_VALUE_INVERSE_STACK = NULL;

Surrogate* SGT_SPECIALIZE_ABSTRACT_DEPENDENT_PROPOSITIONS_ITERATOR = NULL;

Symbol* SYM_SPECIALIZE_SUBSUMPTION_TEST_FILTERp = NULL;

Symbol* SYM_SPECIALIZE_RETURN_ARGUMENT_INDEX = NULL;

Symbol* SYM_SPECIALIZE_REFERENCE_PROPOSITION = NULL;

Surrogate* SGT_SPECIALIZE_DIRECTLY_DEPENDENT_PROPOSITIONS_ITERATOR = NULL;

Keyword* KWD_SPECIALIZE_FUNCTION = NULL;

Symbol* SYM_SPECIALIZE_DESCRIPTION = NULL;

Surrogate* SGT_SPECIALIZE_LOGIC_OBJECT = NULL;

Iterator* EMPTY_ALL_PROPOSITIONS_ITERATOR = NULL;

Keyword* KWD_SPECIALIZE_PREDICATE = NULL;

Keyword* KWD_SPECIALIZE_IN = NULL;

Proposition* BLANK_PROPERTY_PROPOSITION = NULL;

Symbol* SYM_SPECIALIZE_PREDICATE = NULL;

Proposition* BLANK_IN_PROPOSITION = NULL;

Symbol* SYM_SPECIALIZE_IN = NULL;

Symbol* SYM_SPECIALIZE_ALLOCATE_ADJACENCY_ITERATOR_FUNCTION = NULL;

Symbol* SYM_SPECIALIZE_FILTERp = NULL;

Symbol* SYM_SPECIALIZE_ADJACENCY_ITERATOR_STACK = NULL;

Symbol* SYM_SPECIALIZE_BEEN_THERE_LIST = NULL;

Surrogate* SGT_SPECIALIZE_TRANSITIVE_CLOSURE_ITERATOR = NULL;

Symbol* SYM_SPECIALIZE_INVERSEp = NULL;

Symbol* SYM_SPECIALIZE_REFERENCE_INSTANCE = NULL;

Surrogate* SGT_SPECIALIZE_DIRECT_SUPERCOLLECTIONS_ITERATOR = NULL;

Keyword* KWD_SPECIALIZE_IMPLIES = NULL;

Taxonomy_Graph* oIMPLICATION_SUBSUMPTION_GRAPHo = NULL;

Abstract_Dependent_Propositions_Iterator* new_abstract_dependent_propositions_iterator() {
  { Abstract_Dependent_Propositions_Iterator* self = NULL;

    self = new Abstract_Dependent_Propositions_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->variable_value_inverse_stack = NIL;
    self->attribute_propositionsP = FALSE;
    self->kind_of_proposition = NULL;
    self->proposition_cursor = NIL;
    return (self);
  }
}

Object* access_abstract_dependent_propositions_iterator_slot_value(Abstract_Dependent_Propositions_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_SPECIALIZE_PROPOSITION_CURSOR) {
    if (setvalueP) {
      self->proposition_cursor = ((Cons*)(value));
    }
    else {
      return (self->proposition_cursor);
    }
  }
  else if (slotname == SYM_SPECIALIZE_KIND_OF_PROPOSITION) {
    if (setvalueP) {
      self->kind_of_proposition = ((Keyword*)(value));
    }
    else {
      return (self->kind_of_proposition);
    }
  }
  else if (slotname == SYM_SPECIALIZE_ATTRIBUTE_PROPOSITIONSp) {
    if (setvalueP) {
      self->attribute_propositionsP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->attribute_propositionsP));
    }
  }
  else if (slotname == SYM_SPECIALIZE_VARIABLE_VALUE_INVERSE_STACK) {
    if (setvalueP) {
      self->variable_value_inverse_stack = ((Cons*)(value));
    }
    else {
      return (self->variable_value_inverse_stack);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Abstract_Dependent_Propositions_Iterator::primary_type() {
  { Abstract_Dependent_Propositions_Iterator* self = this;

    return (SGT_SPECIALIZE_ABSTRACT_DEPENDENT_PROPOSITIONS_ITERATOR);
  }
}

Directly_Dependent_Propositions_Iterator* new_directly_dependent_propositions_iterator() {
  { Directly_Dependent_Propositions_Iterator* self = NULL;

    self = new Directly_Dependent_Propositions_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->variable_value_inverse_stack = NIL;
    self->attribute_propositionsP = FALSE;
    self->kind_of_proposition = NULL;
    self->proposition_cursor = NIL;
    self->reference_proposition = NULL;
    self->return_argument_index = NULL_INTEGER;
    self->subsumption_test_filterP = NULL;
    return (self);
  }
}

Object* access_directly_dependent_propositions_iterator_slot_value(Directly_Dependent_Propositions_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_SPECIALIZE_SUBSUMPTION_TEST_FILTERp) {
    if (setvalueP) {
      self->subsumption_test_filterP = ((Function_Code_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (function_code_wrap_literal(self->subsumption_test_filterP));
    }
  }
  else if (slotname == SYM_SPECIALIZE_RETURN_ARGUMENT_INDEX) {
    if (setvalueP) {
      self->return_argument_index = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->return_argument_index));
    }
  }
  else if (slotname == SYM_SPECIALIZE_REFERENCE_PROPOSITION) {
    if (setvalueP) {
      self->reference_proposition = ((Proposition*)(value));
    }
    else {
      return (self->reference_proposition);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Directly_Dependent_Propositions_Iterator::primary_type() {
  { Directly_Dependent_Propositions_Iterator* self = this;

    return (SGT_SPECIALIZE_DIRECTLY_DEPENDENT_PROPOSITIONS_ITERATOR);
  }
}

Cons* find_propositions_on_next_equivalent_skolem(Abstract_Dependent_Propositions_Iterator* self) {
  { Cons* topskolemslist = ((Cons*)(self->variable_value_inverse_stack->first()));
    Skolem* nextskolem = ((Skolem*)(topskolemslist->first()));
    Cons* cursor = NULL;

    self->variable_value_inverse_stack->first_setter(topskolemslist->rest);
    cursor = (self->attribute_propositionsP ? ((Cons*)(nextskolem->dependent_attribute_propositions->the_cons_list)) : ((Cons*)(nextskolem->dependent_propositions->the_cons_list)));
    if (nilP(topskolemslist->rest)) {
      self->variable_value_inverse_stack = self->variable_value_inverse_stack->rest;
    }
    if (nextskolem->variable_value_inverse_reader()->non_emptyP()) {
      self->variable_value_inverse_stack = cons(nextskolem->variable_value_inverse_reader(), self->variable_value_inverse_stack);
    }
    return (cursor);
  }
}

boolean Directly_Dependent_Propositions_Iterator::nextP() {
  { Directly_Dependent_Propositions_Iterator* self = this;

    { Cons* cursor = NULL;
      Proposition* proposition = NULL;

      if (self->first_iterationP) {
        {
          self->first_iterationP = FALSE;
          cursor = self->proposition_cursor;
        }
      }
      else {
        cursor = self->proposition_cursor->rest;
      }
      for (;;) {
        while (nilP(cursor)) {
          if (nilP(self->variable_value_inverse_stack)) {
            return (FALSE);
          }
          cursor = find_propositions_on_next_equivalent_skolem(self);
        }
        proposition = ((Proposition*)(cursor->value));
        if ((proposition->kind == self->kind_of_proposition) &&
            (((oREVERSEPOLARITYpo ? ((boolean)(falseP(proposition))) : ((boolean)(trueP(proposition) ||
            (self->kind_of_proposition == KWD_SPECIALIZE_FUNCTION))))) &&
             ((self->subsumption_test_filterP == NULL) ||
              ((boolean (*) (Proposition*, Proposition*))self->subsumption_test_filterP)(proposition, self->reference_proposition)))) {
          if (self->return_argument_index != NULL_INTEGER) {
            self->value = proposition->arguments->nth(self->return_argument_index);
          }
          else {
            self->value = proposition;
          }
          self->proposition_cursor = cursor;
          return (TRUE);
        }
        cursor = cursor->rest;
      }
    }
  }
}

Iterator* all_directly_dependent_propositions(Logic_Object* self, Keyword* kind) {
  { Directly_Dependent_Propositions_Iterator* iterator = new_directly_dependent_propositions_iterator();

    iterator->proposition_cursor = self->dependent_propositions->the_cons_list;
    iterator->kind_of_proposition = kind;
    if (self->variable_value_inverse_reader()->non_emptyP()) {
      iterator->variable_value_inverse_stack = cons_list(1, self->variable_value_inverse_reader());
    }
    return (iterator);
  }
}

Iterator* all_dependent_attribute_propositions(Logic_Object* self, Keyword* kind) {
  { Directly_Dependent_Propositions_Iterator* iterator = new_directly_dependent_propositions_iterator();

    iterator->proposition_cursor = self->dependent_attribute_propositions->the_cons_list;
    iterator->kind_of_proposition = kind;
    iterator->attribute_propositionsP = TRUE;
    if (self->variable_value_inverse_reader()->non_emptyP()) {
      iterator->variable_value_inverse_stack = cons_list(1, self->variable_value_inverse_reader());
    }
    return (iterator);
  }
}

boolean slotref_specializes_slotrefP(Surrogate* slotref1, Surrogate* slotref2) {
  if (slotref1 == slotref2) {
    return (TRUE);
  }
  { Description* desc1 = ((Description*)(dynamic_slot_value(((Slot*)(slotref1->surrogate_value)), SYM_SPECIALIZE_DESCRIPTION, NULL)));
    Description* desc2 = ((Description*)(dynamic_slot_value(((Slot*)(slotref2->surrogate_value)), SYM_SPECIALIZE_DESCRIPTION, NULL)));

    if ((desc1 != NULL) &&
        (desc1 != NULL)) {
      return (all_supercollections(desc1)->memberP(desc2));
    }
    else {
      return (FALSE);
    }
  }
}

Logic_Object* find_logic_object_bound_to_argument(Proposition* proposition) {
  { Object* value = NULL;

    { Object* arg = NULL;
      Vector* vector_001 = proposition->arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        value = argument_bound_to(arg);
        if ((value != NULL) &&
            isaP(value, SGT_SPECIALIZE_LOGIC_OBJECT)) {
          return (((Logic_Object*)(value)));
        }
      }
    }
  }
  return (NULL);
}

boolean specializes_predicate_propositionP(Proposition* subproposition, Proposition* referenceproposition) {
  if (!slotref_specializes_slotrefP(((Surrogate*)(subproposition->renamed_Operator)), ((Surrogate*)(referenceproposition->renamed_Operator)))) {
    return (FALSE);
  }
  { int ubstackoffset = oQUERYENVIRONMENTo->top_unbinding_stack_offset;
    boolean successP = FALSE;

    { boolean alwaysP_001 = TRUE;

      { Object* superarg = NULL;
        Object* subarg = NULL;
        Vector* vector_001 = subproposition->arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();
        Vector* vector_002 = referenceproposition->arguments;
        int index_002 = 0;
        int length_002 = vector_002->length();

        while ((index_001 < length_001) &&
            (index_002 < length_002)) {
          {
            subarg = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          {
            superarg = vector_002->nth(index_002);
            index_002 = index_002 + 1;
          }
          if (!bind_argument_to_valueP(superarg, subarg->value_of(), FALSE)) {
            alwaysP_001 = FALSE;
            break;
          }
        }
      }
      successP = alwaysP_001;
    }
    if (!successP) {
      unbind_variables_beginning_at(ubstackoffset + 1);
    }
    return (successP);
  }
}

boolean specializes_in_propositionP(Proposition* subproposition, Proposition* referenceproposition) {
  return (collection_implies_collectionP(subproposition->arguments->nth(1)->value_of(), argument_bound_to(referenceproposition->arguments->nth(1))));
}

boolean failing_subsumption_testP(Proposition* subproposition, Proposition* referenceproposition) {
  {
    subproposition = subproposition;
    referenceproposition = referenceproposition;
  }
  return (FALSE);
}

Iterator* all_specializing_propositions(Proposition* self) {
  { Logic_Object* logicargument = find_logic_object_bound_to_argument(self);
    Directly_Dependent_Propositions_Iterator* iterator = NULL;

    if (logicargument == NULL) {
      return (EMPTY_ALL_PROPOSITIONS_ITERATOR);
    }
    if (attribute_propositionP(self) &&
        argument_boundP(self->arguments->first())) {
      iterator = ((Directly_Dependent_Propositions_Iterator*)(all_dependent_attribute_propositions(logicargument, self->kind)));
    }
    else {
      iterator = ((Directly_Dependent_Propositions_Iterator*)(all_directly_dependent_propositions(logicargument, self->kind)));
    }
    iterator->reference_proposition = self;
    { Keyword* test_value_001 = self->kind;

      if ((test_value_001 == KWD_SPECIALIZE_PREDICATE) ||
          (test_value_001 == KWD_SPECIALIZE_FUNCTION)) {
        iterator->subsumption_test_filterP = ((cpp_function_code)(&specializes_predicate_propositionP));
      }
      else if (test_value_001 == KWD_SPECIALIZE_IN) {
        iterator->subsumption_test_filterP = ((cpp_function_code)(&specializes_in_propositionP));
      }
      else {
        iterator->subsumption_test_filterP = ((cpp_function_code)(&failing_subsumption_testP));
      }
    }
    return (iterator);
  }
}

boolean specializes_attribute_propositionP(Proposition* subproposition, Proposition* referenceproposition) {
  { boolean test_value_001 = FALSE;

    test_value_001 = slotref_specializes_slotrefP(((Surrogate*)(subproposition->renamed_Operator)), ((Surrogate*)(referenceproposition->renamed_Operator)));
    if (test_value_001) {
      { boolean alwaysP_001 = TRUE;

        { Object* otherarg = NULL;
          Object* arg = NULL;
          Iterator* iter_001 = subproposition->arguments->but_last();
          Vector* vector_001 = referenceproposition->arguments;
          int index_001 = 0;
          int length_001 = vector_001->length();

          while (iter_001->nextP() &&
              (index_001 < length_001)) {
            {
              arg = iter_001->value;
            }
            {
              otherarg = vector_001->nth(index_001);
              index_001 = index_001 + 1;
            }
            if (!eqlP(arg->value_of(), argument_bound_to(otherarg))) {
              alwaysP_001 = FALSE;
              break;
            }
          }
        }
        test_value_001 = alwaysP_001;
      }
    }
    { boolean value_001 = test_value_001;

      return (value_001);
    }
  }
}

Object* fast_get_attribute_proposition_value(Logic_Object* self, Surrogate* relation) {
  { Proposition* p = NULL;
    Cons* iter_001 = self->dependent_attribute_propositions->the_cons_list;

    while (!nilP(iter_001)) {
      {
        p = ((Proposition*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if ((p->renamed_Operator == relation) &&
          (trueP(p) ||
           (p->kind == KWD_SPECIALIZE_FUNCTION))) {
        return (p->arguments->nth(1)->value_of());
      }
    }
  }
  return (NULL);
}

Object* get_attribute_proposition_value(Logic_Object* self, Surrogate* relation) {
  { Object* result = NULL;
    Directly_Dependent_Propositions_Iterator* iterator = ((Directly_Dependent_Propositions_Iterator*)(all_dependent_attribute_propositions(self, KWD_SPECIALIZE_FUNCTION)));
    Proposition* proposition = NULL;

    while (iterator->nextP()) {
      proposition = ((Proposition*)(iterator->value));
      if (slotref_specializes_slotrefP(((Surrogate*)(proposition->renamed_Operator)), relation) &&
          (trueP(proposition) ||
           (proposition->kind == KWD_SPECIALIZE_FUNCTION))) {
        result = proposition->arguments->nth(1)->value_of();
        iterator->free();
        return (result);
      }
    }
    iterator->free();
    return (NULL);
  }
}

boolean specializes_property_propositionP(Proposition* subproposition, Proposition* referenceproposition) {
  return (slotref_specializes_slotrefP(((Surrogate*)(subproposition->renamed_Operator)), ((Surrogate*)(referenceproposition->renamed_Operator))));
}

boolean exists_property_propositionP(Logic_Object* self, Surrogate* relation) {
  { Directly_Dependent_Propositions_Iterator* iterator = ((Directly_Dependent_Propositions_Iterator*)(all_dependent_attribute_propositions(self, KWD_SPECIALIZE_PREDICATE)));

    iterator->reference_proposition = BLANK_PROPERTY_PROPOSITION;
    iterator->subsumption_test_filterP = ((cpp_function_code)(&specializes_property_propositionP));
    BLANK_PROPERTY_PROPOSITION->renamed_Operator = relation;
    if (iterator->nextP()) {
      iterator->free();
      return (TRUE);
    }
    iterator->free();
    return (FALSE);
  }
}

boolean exists_specializing_in_propositionP(Logic_Object* member, Object* collection) {
  { Directly_Dependent_Propositions_Iterator* iterator = ((Directly_Dependent_Propositions_Iterator*)(all_directly_dependent_propositions(member, KWD_SPECIALIZE_IN)));

    BLANK_IN_PROPOSITION->arguments->nth_setter(collection, 1);
    iterator->reference_proposition = BLANK_IN_PROPOSITION;
    iterator->subsumption_test_filterP = ((cpp_function_code)(&specializes_in_propositionP));
    if (iterator->nextP()) {
      iterator->free();
      return (TRUE);
    }
    iterator->free();
    return (FALSE);
  }
}

boolean matches_in_proposition_collection_argumentP(Proposition* subproposition, Proposition* referenceproposition) {
  return (eqlP(subproposition->arguments->nth(1), referenceproposition->arguments->nth(1)));
}

Directly_Dependent_Propositions_Iterator* all_in_proposition_members(Logic_Object* collection) {
  { Directly_Dependent_Propositions_Iterator* iterator = ((Directly_Dependent_Propositions_Iterator*)(all_directly_dependent_propositions(collection, KWD_SPECIALIZE_IN)));

    BLANK_IN_PROPOSITION->arguments->nth_setter(collection, 1);
    iterator->reference_proposition = BLANK_IN_PROPOSITION;
    iterator->subsumption_test_filterP = ((cpp_function_code)(&matches_in_proposition_collection_argumentP));
    iterator->return_argument_index = 0;
    return (iterator);
  }
}

Transitive_Closure_Iterator* new_transitive_closure_iterator() {
  { Transitive_Closure_Iterator* self = NULL;

    self = new Transitive_Closure_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->been_there_list = NULL;
    self->adjacency_iterator_stack = NIL;
    self->filterP = NULL;
    self->allocate_adjacency_iterator_function = NULL;
    return (self);
  }
}

Object* access_transitive_closure_iterator_slot_value(Transitive_Closure_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_SPECIALIZE_ALLOCATE_ADJACENCY_ITERATOR_FUNCTION) {
    if (setvalueP) {
      self->allocate_adjacency_iterator_function = ((Function_Code_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (function_code_wrap_literal(self->allocate_adjacency_iterator_function));
    }
  }
  else if (slotname == SYM_SPECIALIZE_FILTERp) {
    if (setvalueP) {
      self->filterP = ((Function_Code_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (function_code_wrap_literal(self->filterP));
    }
  }
  else if (slotname == SYM_SPECIALIZE_ADJACENCY_ITERATOR_STACK) {
    if (setvalueP) {
      self->adjacency_iterator_stack = ((Cons*)(value));
    }
    else {
      return (self->adjacency_iterator_stack);
    }
  }
  else if (slotname == SYM_SPECIALIZE_BEEN_THERE_LIST) {
    if (setvalueP) {
      self->been_there_list = ((Cons*)(value));
    }
    else {
      return (self->been_there_list);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Transitive_Closure_Iterator::primary_type() {
  { Transitive_Closure_Iterator* self = this;

    return (SGT_SPECIALIZE_TRANSITIVE_CLOSURE_ITERATOR);
  }
}

void Transitive_Closure_Iterator::free() {
  { Transitive_Closure_Iterator* self = this;

    free_cons_list(self->adjacency_iterator_stack);
    free_cons_list(self->been_there_list);
    unmake(self);
  }
}

boolean Transitive_Closure_Iterator::nextP() {
  { Transitive_Closure_Iterator* self = this;

    { Object* node = self->value;
      Iterator* adjacencyiterator = ((Iterator* (*) (Object*))self->allocate_adjacency_iterator_function)(node);

      if (adjacencyiterator != NULL) {
        self->adjacency_iterator_stack = cons(adjacencyiterator, self->adjacency_iterator_stack);
      }
      else {
        {
          adjacencyiterator = ((Iterator*)(self->adjacency_iterator_stack->first()));
          if (adjacencyiterator == NULL) {
            return (FALSE);
          }
        }
      }
      for (;;) {
        while (!adjacencyiterator->nextP()) {
          self->adjacency_iterator_stack = self->adjacency_iterator_stack->rest;
          adjacencyiterator = ((Iterator*)(self->adjacency_iterator_stack->first()));
          if (adjacencyiterator == NULL) {
            return (FALSE);
          }
        }
        node = adjacencyiterator->value;
        if ((!self->been_there_list->memberP(adjacencyiterator->value)) &&
            ((self->filterP == NULL) ||
             ((boolean (*) (Object*))self->filterP)(node))) {
          self->been_there_list = cons(node, self->been_there_list);
          self->value = node;
          return (TRUE);
        }
      }
    }
  }
}

Iterator* allocate_transitive_closure_iterator(Object* startnode, cpp_function_code allocateadjacencyiterator, cpp_function_code filterfunction) {
  // Return an iterator that generates the transitive
  // closure of applying iterators generated by 'allocateAdjacencyIterator'
  // to 'startNode'.  If 'filterFunction' is non-null, that function is applied
  // as a filter to each node generated (nodes filtered out still generate
  // descendants, but they don't get returned).
  { Transitive_Closure_Iterator* iterator = new_transitive_closure_iterator();

    iterator->value = startnode;
    iterator->been_there_list = cons_list(1, startnode);
    iterator->allocate_adjacency_iterator_function = allocateadjacencyiterator;
    iterator->filterP = filterfunction;
    return (iterator);
  }
}

Direct_Supercollections_Iterator* new_direct_supercollections_iterator() {
  { Direct_Supercollections_Iterator* self = NULL;

    self = new Direct_Supercollections_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->variable_value_inverse_stack = NIL;
    self->attribute_propositionsP = FALSE;
    self->kind_of_proposition = NULL;
    self->proposition_cursor = NIL;
    self->reference_instance = NULL;
    self->inverseP = FALSE;
    return (self);
  }
}

Object* access_direct_supercollections_iterator_slot_value(Direct_Supercollections_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_SPECIALIZE_INVERSEp) {
    if (setvalueP) {
      self->inverseP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->inverseP));
    }
  }
  else if (slotname == SYM_SPECIALIZE_REFERENCE_INSTANCE) {
    if (setvalueP) {
      self->reference_instance = ((Logic_Object*)(value));
    }
    else {
      return (self->reference_instance);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Direct_Supercollections_Iterator::primary_type() {
  { Direct_Supercollections_Iterator* self = this;

    return (SGT_SPECIALIZE_DIRECT_SUPERCOLLECTIONS_ITERATOR);
  }
}

boolean Direct_Supercollections_Iterator::nextP() {
  { Direct_Supercollections_Iterator* self = this;

    { Cons* cursor = NULL;
      Proposition* proposition = NULL;

      if (self->first_iterationP) {
        {
          self->first_iterationP = FALSE;
          cursor = self->proposition_cursor;
        }
      }
      else {
        cursor = self->proposition_cursor->rest;
      }
      for (;;) {
        while (nilP(cursor)) {
          if (nilP(self->variable_value_inverse_stack)) {
            return (FALSE);
          }
          cursor = find_propositions_on_next_equivalent_skolem(self);
        }
        proposition = ((Proposition*)(cursor->value));
        if ((proposition->kind == self->kind_of_proposition) &&
            (trueP(proposition) &&
             (self->reference_instance == (self->inverseP ? ((Object*)(proposition->arguments->nth(1))) : ((Object*)(proposition->arguments->nth(0))))->value_of()))) {
          self->value = (self->inverseP ? ((Object*)(proposition->arguments->nth(0))) : ((Object*)(proposition->arguments->nth(1))))->value_of();
          self->proposition_cursor = cursor;
          return (TRUE);
        }
        cursor = cursor->rest;
      }
    }
  }
}

Iterator* all_directly_linked_objects(Logic_Object* self, Keyword* kind, boolean inverseP) {
  { Direct_Supercollections_Iterator* iterator = new_direct_supercollections_iterator();

    iterator->kind_of_proposition = kind;
    iterator->inverseP = inverseP;
    iterator->reference_instance = self;
    iterator->proposition_cursor = self->dependent_propositions->the_cons_list;
    if (self->variable_value_inverse_reader()->non_emptyP()) {
      iterator->variable_value_inverse_stack = cons_list(1, self->variable_value_inverse_reader());
    }
    return (iterator);
  }
}

Iterator* all_direct_supercollections(Logic_Object* self) {
  return (all_directly_linked_objects(self, KWD_SPECIALIZE_IMPLIES, oREVERSEPOLARITYpo));
}

Iterator* all_direct_subcollections(Logic_Object* self) {
  return (all_directly_linked_objects(self, KWD_SPECIALIZE_IMPLIES, !oREVERSEPOLARITYpo));
}

Iterator* all_supercollections(Logic_Object* self) {
  return (allocate_transitive_closure_iterator(self, ((cpp_function_code)(&all_direct_supercollections)), NULL));
}

Iterator* all_subcollections(Logic_Object* self) {
  return (allocate_transitive_closure_iterator(self, ((cpp_function_code)(&all_direct_subcollections)), NULL));
}

boolean clashes_with_function_propositionP(Proposition* nextproposition, Proposition* referenceproposition) {
  if (!(nextproposition->renamed_Operator == referenceproposition->renamed_Operator)) {
    return (FALSE);
  }
  { boolean alwaysP_001 = TRUE;

    { Object* subarg = NULL;
      Object* superarg = NULL;
      Iterator* iter_001 = referenceproposition->arguments->but_last();
      Iterator* iter_002 = nextproposition->arguments->but_last();

      while (iter_001->nextP() &&
          iter_002->nextP()) {
        {
          superarg = iter_001->value;
        }
        {
          subarg = iter_002->value;
        }
        if (!eqlP(argument_bound_to(superarg), subarg->value_of())) {
          alwaysP_001 = FALSE;
          break;
        }
      }
    }
    if (alwaysP_001) {
      { Object* lastsupervalue = argument_bound_to(referenceproposition->arguments->last());
        Object* lastsubvalue = nextproposition->arguments->last()->value_of();

        if ((lastsupervalue != NULL) &&
            ((lastsubvalue != NULL) &&
             (!eqlP(lastsupervalue, lastsubvalue)))) {
          return (TRUE);
        }
      }
    }
  }
  return (FALSE);
}

Directly_Dependent_Propositions_Iterator* all_clashing_propositions(Proposition* self) {
  { Logic_Object* logicargument = find_logic_object_bound_to_argument(self);
    Directly_Dependent_Propositions_Iterator* iterator = NULL;

    if (logicargument == NULL) {
      return (((Directly_Dependent_Propositions_Iterator*)(EMPTY_ALL_PROPOSITIONS_ITERATOR)));
    }
    if (attribute_propositionP(self)) {
      iterator = ((Directly_Dependent_Propositions_Iterator*)(all_dependent_attribute_propositions(logicargument, self->kind)));
    }
    else {
      iterator = ((Directly_Dependent_Propositions_Iterator*)(all_directly_dependent_propositions(logicargument, self->kind)));
    }
    iterator->reference_proposition = self;
    { Keyword* test_value_001 = self->kind;

      if (test_value_001 == KWD_SPECIALIZE_FUNCTION) {
        iterator->subsumption_test_filterP = ((cpp_function_code)(&clashes_with_function_propositionP));
      }
      else {
        cerr << "`" << test_value_001 << "'" << " is not a valid case option";
      }
    }
    return (iterator);
  }
}

List* relations_with_descriptions() {
  { List* result = new_list();

    { Class* renamed_Class = NULL;
      Iterator* iter_001 = all_classes(NULL, FALSE);
      Cons* collect_001 = NULL;

      while (iter_001->nextP()) {
        {
          renamed_Class = ((Class*)(iter_001->value));
        }
        if (((Description*)(dynamic_slot_value(renamed_Class, SYM_SPECIALIZE_DESCRIPTION, NULL))) != NULL) {
          if (collect_001 == NULL) {
            {
              collect_001 = permanent_cons(renamed_Class, NIL);
              if (result->the_cons_list->emptyP()) {
                result->the_cons_list = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(result->the_cons_list, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = permanent_cons(renamed_Class, NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
    }
    { Slot* slot = NULL;
      Iterator* iter_002 = all_slots(NULL, FALSE);
      Cons* collect_002 = NULL;

      while (iter_002->nextP()) {
        {
          slot = ((Slot*)(iter_002->value));
        }
        if (((Description*)(dynamic_slot_value(slot, SYM_SPECIALIZE_DESCRIPTION, NULL))) != NULL) {
          if (collect_002 == NULL) {
            {
              collect_002 = permanent_cons(slot, NIL);
              if (result->the_cons_list->emptyP()) {
                result->the_cons_list = collect_002;
              }
              else {
                add_cons_to_end_of_cons_list(result->the_cons_list, collect_002);
              }
            }
          }
          else {
            {
              collect_002->rest = permanent_cons(slot, NIL);
              collect_002 = collect_002->rest;
            }
          }
        }
      }
    }
    return (result);
  }
}

void build_subsumption_taxonomy_graph() {
  { List* relationswithdescriptions = relations_with_descriptions();

    { Relation* r = NULL;
      Cons* iter_001 = relationswithdescriptions->the_cons_list;

      while (!nilP(iter_001)) {
        {
          r = ((Relation*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        create_description_implication_subsumption_node(((Description*)(dynamic_slot_value(r, SYM_SPECIALIZE_DESCRIPTION, NULL))), NULL);
      }
    }
    { Relation* r = NULL;
      Cons* iter_002 = relationswithdescriptions->the_cons_list;

      while (!nilP(iter_002)) {
        {
          r = ((Relation*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        { Class* super = NULL;
          Iterator* iter_003 = direct_superclasses(((Class*)(r)));

          while (iter_003->nextP()) {
            {
              super = ((Class*)(iter_003->value));
            }
            if (relationswithdescriptions->memberP(super)) {
              link_nodes(oIMPLICATION_SUBSUMPTION_GRAPHo, find_description_implication_subsumption_node(((Description*)(dynamic_slot_value(super, SYM_SPECIALIZE_DESCRIPTION, NULL)))), find_description_implication_subsumption_node(((Description*)(dynamic_slot_value(r, SYM_SPECIALIZE_DESCRIPTION, NULL)))));
            }
          }
        }
      }
    }
  }
}

void clear_implication_subsumption_graph() {
  { Relation* r = NULL;
    Cons* iter_001 = relations_with_descriptions()->the_cons_list;

    while (!nilP(iter_001)) {
      {
        r = ((Relation*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      ((Description*)(dynamic_slot_value(r, SYM_SPECIALIZE_DESCRIPTION, NULL)))->taxonomy_node = NULL;
    }
  }
}

void initialize_implication_subsumption_graph() {
  clear_implication_subsumption_graph();
  oIMPLICATION_SUBSUMPTION_GRAPHo = new_taxonomy_graph();
  create_spanning_forest(oIMPLICATION_SUBSUMPTION_GRAPHo);
}

Taxonomy_Node* find_description_implication_subsumption_node(Description* description) {
  return (description->taxonomy_node);
}

Taxonomy_Node* create_description_implication_subsumption_node(Description* description, Taxonomy_Node* parentnode) {
  { Taxonomy_Node* node = create_and_intern_node(oIMPLICATION_SUBSUMPTION_GRAPHo, parentnode, description);

    description->taxonomy_node = node;
    return (node);
  }
}

Taxonomy_Node* find_or_create_description_implication_subsumption_node(Description* description) {
  { Taxonomy_Node* result = find_description_implication_subsumption_node(description);

    if (result != NULL) {
      return (result);
    }
    return (create_description_implication_subsumption_node(description, NULL));
  }
}

Description* create_description_for_relation_and_ancestors(Relation* self) {
  if (self == NULL) {
    return (NULL);
  }
  { Description* description = self->get_description();
    Taxonomy_Node* taxonomynode = find_or_create_description_implication_subsumption_node(description);

    { Relation* super = NULL;
      Iterator* iter_001 = self->direct_superrelations();

      while (iter_001->nextP()) {
        {
          super = ((Relation*)(iter_001->value));
        }
        { Description* superdescription = create_description_for_relation_and_ancestors(super);
          Taxonomy_Node* supertaxonomynode = find_description_implication_subsumption_node(superdescription);

          link_nodes(oIMPLICATION_SUBSUMPTION_GRAPHo, supertaxonomynode, taxonomynode);
        }
      }
    }
    return (description);
  }
}

void add_taxonomy_implies_subsumes_link(Description* taildescription, Description* headdescription) {
  return;
  { Taxonomy_Node* parentnode = find_or_create_description_implication_subsumption_node(headdescription);
    Taxonomy_Node* childnode = find_description_implication_subsumption_node(taildescription);

    if (childnode != NULL) {
      link_nodes(oIMPLICATION_SUBSUMPTION_GRAPHo, parentnode, childnode);
    }
    else {
      create_description_implication_subsumption_node(taildescription, parentnode);
    }
    create_description_for_relation_and_ancestors(headdescription->native_relation);
    create_description_for_relation_and_ancestors(headdescription->native_relation);
  }
}

void drop_taxonomy_implies_subsumes_link(Description* taildescription, Description* headdescription) {
  {
    headdescription = headdescription;
    taildescription = taildescription;
  }
  return;
  cout << "'drop-taxonomy-implies-subsumes-link':  Write me, I am a dummy!" << endl;
}

boolean taxonomy_implies_or_is_subsumedP(Relation* premise, Relation* conclusion) {
  { Description* premisedescription = ((Description*)(dynamic_slot_value(premise, SYM_SPECIALIZE_DESCRIPTION, NULL)));
    Description* conclusiondescription = NULL;

    if ((premisedescription == NULL) ||
        (find_description_implication_subsumption_node(premisedescription) == NULL)) {
      premisedescription = create_description_for_relation_and_ancestors(premise);
    }
    conclusiondescription = ((Description*)(dynamic_slot_value(conclusion, SYM_SPECIALIZE_DESCRIPTION, NULL)));
    if (conclusiondescription == NULL) {
      return (FALSE);
    }
    if (find_description_implication_subsumption_node(conclusiondescription) == NULL) {
      cerr << "'taxonomy-implies-or-is-subsumed?' conclusionDescription should have taxonomy-node";
    }
    return (taxonomy_node_subclass_ofP(find_description_implication_subsumption_node(premisedescription), find_description_implication_subsumption_node(conclusiondescription)));
  }
}

void startup_specialize() {
  { Module* old_OmoduleO_001 = oMODULEo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = string_get_module("/LOGIC", TRUE);
          oCONTEXTo = oMODULEo;
          if (current_startup_time_phaseP(2)) {
            SYM_SPECIALIZE_PROPOSITION_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("PROPOSITION-CURSOR", NULL, 0)));
            SYM_SPECIALIZE_KIND_OF_PROPOSITION = ((Symbol*)(intern_rigid_symbol_wrt_module("KIND-OF-PROPOSITION", NULL, 0)));
            SYM_SPECIALIZE_ATTRIBUTE_PROPOSITIONSp = ((Symbol*)(intern_rigid_symbol_wrt_module("ATTRIBUTE-PROPOSITIONS?", NULL, 0)));
            SYM_SPECIALIZE_VARIABLE_VALUE_INVERSE_STACK = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-VALUE-INVERSE-STACK", NULL, 0)));
            SGT_SPECIALIZE_ABSTRACT_DEPENDENT_PROPOSITIONS_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("ABSTRACT-DEPENDENT-PROPOSITIONS-ITERATOR", NULL, 1)));
            SYM_SPECIALIZE_SUBSUMPTION_TEST_FILTERp = ((Symbol*)(intern_rigid_symbol_wrt_module("SUBSUMPTION-TEST-FILTER?", NULL, 0)));
            SYM_SPECIALIZE_RETURN_ARGUMENT_INDEX = ((Symbol*)(intern_rigid_symbol_wrt_module("RETURN-ARGUMENT-INDEX", NULL, 0)));
            SYM_SPECIALIZE_REFERENCE_PROPOSITION = ((Symbol*)(intern_rigid_symbol_wrt_module("REFERENCE-PROPOSITION", NULL, 0)));
            SGT_SPECIALIZE_DIRECTLY_DEPENDENT_PROPOSITIONS_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("DIRECTLY-DEPENDENT-PROPOSITIONS-ITERATOR", NULL, 1)));
            KWD_SPECIALIZE_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            SYM_SPECIALIZE_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 0)));
            SGT_SPECIALIZE_LOGIC_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-OBJECT", NULL, 1)));
            KWD_SPECIALIZE_PREDICATE = ((Keyword*)(intern_rigid_symbol_wrt_module("PREDICATE", NULL, 2)));
            KWD_SPECIALIZE_IN = ((Keyword*)(intern_rigid_symbol_wrt_module("IN", NULL, 2)));
            SYM_SPECIALIZE_PREDICATE = ((Symbol*)(intern_rigid_symbol_wrt_module("PREDICATE", string_get_module("/STELLA", TRUE), 0)));
            SYM_SPECIALIZE_IN = ((Symbol*)(intern_rigid_symbol_wrt_module("IN", string_get_module("/STELLA", TRUE), 0)));
            SYM_SPECIALIZE_ALLOCATE_ADJACENCY_ITERATOR_FUNCTION = ((Symbol*)(intern_rigid_symbol_wrt_module("ALLOCATE-ADJACENCY-ITERATOR-FUNCTION", NULL, 0)));
            SYM_SPECIALIZE_FILTERp = ((Symbol*)(intern_rigid_symbol_wrt_module("FILTER?", NULL, 0)));
            SYM_SPECIALIZE_ADJACENCY_ITERATOR_STACK = ((Symbol*)(intern_rigid_symbol_wrt_module("ADJACENCY-ITERATOR-STACK", NULL, 0)));
            SYM_SPECIALIZE_BEEN_THERE_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("BEEN-THERE-LIST", NULL, 0)));
            SGT_SPECIALIZE_TRANSITIVE_CLOSURE_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSITIVE-CLOSURE-ITERATOR", NULL, 1)));
            SYM_SPECIALIZE_INVERSEp = ((Symbol*)(intern_rigid_symbol_wrt_module("INVERSE?", NULL, 0)));
            SYM_SPECIALIZE_REFERENCE_INSTANCE = ((Symbol*)(intern_rigid_symbol_wrt_module("REFERENCE-INSTANCE", NULL, 0)));
            SGT_SPECIALIZE_DIRECT_SUPERCOLLECTIONS_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("DIRECT-SUPERCOLLECTIONS-ITERATOR", NULL, 1)));
            KWD_SPECIALIZE_IMPLIES = ((Keyword*)(intern_rigid_symbol_wrt_module("IMPLIES", NULL, 2)));
          }
          if (current_startup_time_phaseP(4)) {
            EMPTY_ALL_PROPOSITIONS_ITERATOR = new_directly_dependent_propositions_iterator();
            BLANK_PROPERTY_PROPOSITION = create_proposition(SYM_SPECIALIZE_PREDICATE, 1);
            BLANK_IN_PROPOSITION = create_proposition(SYM_SPECIALIZE_IN, 2);
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("ABSTRACT-DEPENDENT-PROPOSITIONS-ITERATOR", "(DEFCLASS ABSTRACT-DEPENDENT-PROPOSITIONS-ITERATOR (ITERATOR) :SLOTS ((PROPOSITION-CURSOR :TYPE (CONS OF PROPOSITION) :INITIALLY NIL) (KIND-OF-PROPOSITION :TYPE KEYWORD) (ATTRIBUTE-PROPOSITIONS? :TYPE BOOLEAN) (VARIABLE-VALUE-INVERSE-STACK :TYPE (CONS OF CONS) :INITIALLY NIL)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_abstract_dependent_propositions_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_abstract_dependent_propositions_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("DIRECTLY-DEPENDENT-PROPOSITIONS-ITERATOR", "(DEFCLASS DIRECTLY-DEPENDENT-PROPOSITIONS-ITERATOR (ABSTRACT-DEPENDENT-PROPOSITIONS-ITERATOR) :SLOTS ((SUBSUMPTION-TEST-FILTER? :TYPE FUNCTION-CODE) (RETURN-ARGUMENT-INDEX :TYPE INTEGER) (REFERENCE-PROPOSITION :TYPE PROPOSITION)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_directly_dependent_propositions_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_directly_dependent_propositions_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TRANSITIVE-CLOSURE-ITERATOR", "(DEFCLASS TRANSITIVE-CLOSURE-ITERATOR (ITERATOR) :DOCUMENTATION \"Iterator that visits all nodes reachable using an\nembedded adjacency function.\" :SLOTS ((ALLOCATE-ADJACENCY-ITERATOR-FUNCTION :TYPE FUNCTION-CODE) (FILTER? :TYPE FUNCTION-CODE) (ADJACENCY-ITERATOR-STACK :TYPE (CONS OF ITERATOR) :INITIALLY NIL) (BEEN-THERE-LIST :TYPE CONS)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_transitive_closure_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_transitive_closure_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("DIRECT-SUPERCOLLECTIONS-ITERATOR", "(DEFCLASS DIRECT-SUPERCOLLECTIONS-ITERATOR (ABSTRACT-DEPENDENT-PROPOSITIONS-ITERATOR) :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((INVERSE? :TYPE BOOLEAN) (REFERENCE-INSTANCE :TYPE LOGIC-OBJECT)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_direct_supercollections_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_direct_supercollections_iterator_slot_value));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("FIND-PROPOSITIONS-ON-NEXT-EQUIVALENT-SKOLEM", "ABSTRACT-DEPENDENT-PROPOSITIONS-ITERATOR", "(DEFUN (FIND-PROPOSITIONS-ON-NEXT-EQUIVALENT-SKOLEM (CONS OF PROPOSITION)) ((SELF ABSTRACT-DEPENDENT-PROPOSITIONS-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&find_propositions_on_next_equivalent_skolem));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "DIRECTLY-DEPENDENT-PROPOSITIONS-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF DIRECTLY-DEPENDENT-PROPOSITIONS-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Directly_Dependent_Propositions_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-DIRECTLY-DEPENDENT-PROPOSITIONS", "LOGIC-OBJECT", "(DEFUN (ALL-DIRECTLY-DEPENDENT-PROPOSITIONS ITERATOR) ((SELF LOGIC-OBJECT) (KIND KEYWORD)))");

              method->function_code = ((cpp_function_code)(&all_directly_dependent_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-DEPENDENT-ATTRIBUTE-PROPOSITIONS", "LOGIC-OBJECT", "(DEFUN (ALL-DEPENDENT-ATTRIBUTE-PROPOSITIONS (ITERATOR OF PROPOSITION)) ((SELF LOGIC-OBJECT) (KIND KEYWORD)))");

              method->function_code = ((cpp_function_code)(&all_dependent_attribute_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOTREF-SPECIALIZES-SLOTREF?", "SLOTREF", "(DEFUN (SLOTREF-SPECIALIZES-SLOTREF? BOOLEAN) ((SLOTREF1 SLOTREF) (SLOTREF2 SLOTREF)))");

              method->function_code = ((cpp_function_code)(&slotref_specializes_slotrefP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-LOGIC-OBJECT-BOUND-TO-ARGUMENT", "PROPOSITION", "(DEFUN (FIND-LOGIC-OBJECT-BOUND-TO-ARGUMENT LOGIC-OBJECT) ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&find_logic_object_bound_to_argument));
            }
            { Method_Slot* method = define_method_from_stringified_source("SPECIALIZES-PREDICATE-PROPOSITION?", "PROPOSITION", "(DEFUN (SPECIALIZES-PREDICATE-PROPOSITION? BOOLEAN) ((SUBPROPOSITION PROPOSITION) (REFERENCEPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&specializes_predicate_propositionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SPECIALIZES-IN-PROPOSITION?", "PROPOSITION", "(DEFUN (SPECIALIZES-IN-PROPOSITION? BOOLEAN) ((SUBPROPOSITION PROPOSITION) (REFERENCEPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&specializes_in_propositionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FAILING-SUBSUMPTION-TEST?", "PROPOSITION", "(DEFUN (FAILING-SUBSUMPTION-TEST? BOOLEAN) ((SUBPROPOSITION PROPOSITION) (REFERENCEPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&failing_subsumption_testP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-SPECIALIZING-PROPOSITIONS", "PROPOSITION", "(DEFUN (ALL-SPECIALIZING-PROPOSITIONS (ITERATOR OF PROPOSITION)) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&all_specializing_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("SPECIALIZES-ATTRIBUTE-PROPOSITION?", "PROPOSITION", "(DEFUN (SPECIALIZES-ATTRIBUTE-PROPOSITION? BOOLEAN) ((SUBPROPOSITION PROPOSITION) (REFERENCEPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&specializes_attribute_propositionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FAST-GET-ATTRIBUTE-PROPOSITION-VALUE", "LOGIC-OBJECT", "(DEFUN (FAST-GET-ATTRIBUTE-PROPOSITION-VALUE OBJECT) ((SELF LOGIC-OBJECT) (RELATION SLOTREF)))");

              method->function_code = ((cpp_function_code)(&fast_get_attribute_proposition_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-ATTRIBUTE-PROPOSITION-VALUE", "LOGIC-OBJECT", "(DEFUN (GET-ATTRIBUTE-PROPOSITION-VALUE OBJECT) ((SELF LOGIC-OBJECT) (RELATION SLOTREF)))");

              method->function_code = ((cpp_function_code)(&get_attribute_proposition_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("SPECIALIZES-PROPERTY-PROPOSITION?", "PROPOSITION", "(DEFUN (SPECIALIZES-PROPERTY-PROPOSITION? BOOLEAN) ((SUBPROPOSITION PROPOSITION) (REFERENCEPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&specializes_property_propositionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXISTS-PROPERTY-PROPOSITION?", "LOGIC-OBJECT", "(DEFUN (EXISTS-PROPERTY-PROPOSITION? BOOLEAN) ((SELF LOGIC-OBJECT) (RELATION SLOTREF)))");

              method->function_code = ((cpp_function_code)(&exists_property_propositionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXISTS-SPECIALIZING-IN-PROPOSITION?", "LOGIC-OBJECT", "(DEFUN (EXISTS-SPECIALIZING-IN-PROPOSITION? BOOLEAN) ((MEMBER LOGIC-OBJECT) (COLLECTION OBJECT)))");

              method->function_code = ((cpp_function_code)(&exists_specializing_in_propositionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MATCHES-IN-PROPOSITION-COLLECTION-ARGUMENT?", "PROPOSITION", "(DEFUN (MATCHES-IN-PROPOSITION-COLLECTION-ARGUMENT? BOOLEAN) ((SUBPROPOSITION PROPOSITION) (REFERENCEPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&matches_in_proposition_collection_argumentP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-IN-PROPOSITION-MEMBERS", "LOGIC-OBJECT", "(DEFUN (ALL-IN-PROPOSITION-MEMBERS DIRECTLY-DEPENDENT-PROPOSITIONS-ITERATOR) ((COLLECTION LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&all_in_proposition_members));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE", "TRANSITIVE-CLOSURE-ITERATOR", "(DEFMETHOD FREE ((SELF TRANSITIVE-CLOSURE-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Transitive_Closure_Iterator::free));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "TRANSITIVE-CLOSURE-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF TRANSITIVE-CLOSURE-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Transitive_Closure_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-TRANSITIVE-CLOSURE-ITERATOR", "OBJECT", "(DEFUN (ALLOCATE-TRANSITIVE-CLOSURE-ITERATOR ITERATOR) ((STARTNODE OBJECT) (ALLOCATEADJACENCYITERATOR FUNCTION-CODE) (FILTERFUNCTION FUNCTION-CODE)) :DOCUMENTATION \"Return an iterator that generates the transitive\nclosure of applying iterators generated by 'allocateAdjacencyIterator'\nto 'startNode'.  If 'filterFunction' is non-null, that function is applied\nas a filter to each node generated (nodes filtered out still generate\ndescendants, but they don't get returned).\")");

              method->function_code = ((cpp_function_code)(&allocate_transitive_closure_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "DIRECT-SUPERCOLLECTIONS-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF DIRECT-SUPERCOLLECTIONS-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Direct_Supercollections_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-DIRECTLY-LINKED-OBJECTS", "LOGIC-OBJECT", "(DEFUN (ALL-DIRECTLY-LINKED-OBJECTS (ITERATOR OF LOGIC-OBJECT)) ((SELF LOGIC-OBJECT) (KIND KEYWORD) (INVERSE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&all_directly_linked_objects));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-DIRECT-SUPERCOLLECTIONS", "LOGIC-OBJECT", "(DEFUN (ALL-DIRECT-SUPERCOLLECTIONS (ITERATOR OF LOGIC-OBJECT)) ((SELF LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&all_direct_supercollections));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-DIRECT-SUBCOLLECTIONS", "LOGIC-OBJECT", "(DEFUN (ALL-DIRECT-SUBCOLLECTIONS (ITERATOR OF LOGIC-OBJECT)) ((SELF LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&all_direct_subcollections));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-SUPERCOLLECTIONS", "LOGIC-OBJECT", "(DEFUN (ALL-SUPERCOLLECTIONS (ITERATOR OF LOGIC-OBJECT)) ((SELF LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&all_supercollections));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-SUBCOLLECTIONS", "LOGIC-OBJECT", "(DEFUN (ALL-SUBCOLLECTIONS ITERATOR) ((SELF LOGIC-OBJECT)))");

              method->function_code = ((cpp_function_code)(&all_subcollections));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASHES-WITH-FUNCTION-PROPOSITION?", "PROPOSITION", "(DEFUN (CLASHES-WITH-FUNCTION-PROPOSITION? BOOLEAN) ((NEXTPROPOSITION PROPOSITION) (REFERENCEPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&clashes_with_function_propositionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-CLASHING-PROPOSITIONS", "PROPOSITION", "(DEFUN (ALL-CLASHING-PROPOSITIONS DIRECTLY-DEPENDENT-PROPOSITIONS-ITERATOR) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&all_clashing_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("RELATIONS-WITH-DESCRIPTIONS", NULL, "(DEFUN (RELATIONS-WITH-DESCRIPTIONS (LIST OF RELATION)) ())");

              method->function_code = ((cpp_function_code)(&relations_with_descriptions));
            }
            { Method_Slot* method = define_method_from_stringified_source("BUILD-SUBSUMPTION-TAXONOMY-GRAPH", NULL, "(DEFUN BUILD-SUBSUMPTION-TAXONOMY-GRAPH ())");

              method->function_code = ((cpp_function_code)(&build_subsumption_taxonomy_graph));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-IMPLICATION-SUBSUMPTION-GRAPH", NULL, "(DEFUN CLEAR-IMPLICATION-SUBSUMPTION-GRAPH ())");

              method->function_code = ((cpp_function_code)(&clear_implication_subsumption_graph));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-IMPLICATION-SUBSUMPTION-GRAPH", NULL, "(DEFUN INITIALIZE-IMPLICATION-SUBSUMPTION-GRAPH ())");

              method->function_code = ((cpp_function_code)(&initialize_implication_subsumption_graph));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-DESCRIPTION-IMPLICATION-SUBSUMPTION-NODE", "DESCRIPTION", "(DEFUN (FIND-DESCRIPTION-IMPLICATION-SUBSUMPTION-NODE TAXONOMY-NODE) ((DESCRIPTION DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&find_description_implication_subsumption_node));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-DESCRIPTION-IMPLICATION-SUBSUMPTION-NODE", "DESCRIPTION", "(DEFUN (CREATE-DESCRIPTION-IMPLICATION-SUBSUMPTION-NODE TAXONOMY-NODE) ((DESCRIPTION DESCRIPTION) (PARENTNODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&create_description_implication_subsumption_node));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-OR-CREATE-DESCRIPTION-IMPLICATION-SUBSUMPTION-NODE", "DESCRIPTION", "(DEFUN (FIND-OR-CREATE-DESCRIPTION-IMPLICATION-SUBSUMPTION-NODE TAXONOMY-NODE) ((DESCRIPTION DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&find_or_create_description_implication_subsumption_node));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-DESCRIPTION-FOR-RELATION-AND-ANCESTORS", "RELATION", "(DEFUN (CREATE-DESCRIPTION-FOR-RELATION-AND-ANCESTORS DESCRIPTION) ((SELF RELATION)))");

              method->function_code = ((cpp_function_code)(&create_description_for_relation_and_ancestors));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-TAXONOMY-IMPLIES-SUBSUMES-LINK", "DESCRIPTION", "(DEFUN ADD-TAXONOMY-IMPLIES-SUBSUMES-LINK ((TAILDESCRIPTION DESCRIPTION) (HEADDESCRIPTION DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&add_taxonomy_implies_subsumes_link));
            }
            { Method_Slot* method = define_method_from_stringified_source("DROP-TAXONOMY-IMPLIES-SUBSUMES-LINK", "DESCRIPTION", "(DEFUN DROP-TAXONOMY-IMPLIES-SUBSUMES-LINK ((TAILDESCRIPTION DESCRIPTION) (HEADDESCRIPTION DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&drop_taxonomy_implies_subsumes_link));
            }
            { Method_Slot* method = define_method_from_stringified_source("TAXONOMY-IMPLIES-OR-IS-SUBSUMED?", "RELATION", "(DEFUN (TAXONOMY-IMPLIES-OR-IS-SUBSUMED? BOOLEAN) ((PREMISE RELATION) (CONCLUSION RELATION)))");

              method->function_code = ((cpp_function_code)(&taxonomy_implies_or_is_subsumedP));
            }
            define_method_from_stringified_source("STARTUP-SPECIALIZE", NULL, "(DEFUN STARTUP-SPECIALIZE ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT EMPTY-ALL-PROPOSITIONS-ITERATOR (ITERATOR OF PROPOSITION) (NEW DIRECTLY-DEPENDENT-PROPOSITIONS-ITERATOR) :DOCUMENTATION \"This iterator returns no values whenever its called.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT BLANK-PROPERTY-PROPOSITION PROPOSITION (CREATE-PROPOSITION (QUOTE PREDICATE) 1) :DOCUMENTATION \"Used by 'exists-property-proposition' to construct an\non-the-fly unary predicate proposition.\" :PUBLIC? FALSE)");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT BLANK-IN-PROPOSITION PROPOSITION (CREATE-PROPOSITION (QUOTE IN) 2) :DOCUMENTATION \"Used by 'DESCRIPTION-EXTENSION-ITERATOR.next? to quickly\nconstruct an IN proposition to be passed to 'all-specializing-propositions'\nduring filtering of generated instances.\" :PUBLIC? FALSE)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *IMPLICATION-SUBSUMPTION-GRAPH* TAXONOMY-GRAPH NULL)");
            initialize_implication_subsumption_graph();
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

