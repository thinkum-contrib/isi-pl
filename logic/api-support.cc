// api-support.cc

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

Symbol* SYM_API_SUPPORT_NESTED_ITERATOR = NULL;

Surrogate* SGT_API_SUPPORT_SLOT_VALUE_ITERATOR = NULL;

Surrogate* SGT_API_SUPPORT_DESCRIPTION = NULL;

Surrogate* SGT_API_SUPPORT_SLOT = NULL;

Symbol* SYM_API_SUPPORT_SURROGATE_VALUE_INVERSE = NULL;

Surrogate* SGT_API_SUPPORT_RELATION = NULL;

Symbol* SYM_API_SUPPORT_DESCRIPTION = NULL;

Symbol* SYM_API_SUPPORT_DEFINITION = NULL;

Surrogate* SGT_API_SUPPORT_LOGIC_OBJECT = NULL;

Surrogate* SGT_API_SUPPORT_PATTERN_VARIABLE = NULL;

Surrogate* SGT_API_SUPPORT_SKOLEM = NULL;

boolean filtered_types_to_classes_nextP(All_Purpose_Iterator* self) {
  { Cons* types = ((Cons*)(self->iterator_cons_list));
    Iterator* typesiterator = ((Iterator*)(self->iterator_nested_iterator));
    List* modules = ((List*)(self->iterator_object));
    boolean filterclassesP = (modules != NULL) &&
        modules->non_emptyP();
    Surrogate* type = NULL;

    for (;;) {
      if (typesiterator != NULL) {
        if (!typesiterator->nextP()) {
          return (FALSE);
        }
        type = ((Surrogate*)(typesiterator->value));
      }
      else {
        if (types->emptyP()) {
          return (FALSE);
        }
        type = ((Surrogate*)(types->value));
        types = types->rest;
      }
      { boolean test_value_001 = FALSE;

        if (!filterclassesP) {
          test_value_001 = TRUE;
        }
        else {
          { boolean foundP_001 = FALSE;

            { Module* module = NULL;
              Cons* iter_001 = modules->the_cons_list;

              while (!nilP(iter_001)) {
                {
                  module = ((Module*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                if (module == type->home_context) {
                  foundP_001 = TRUE;
                  break;
                }
              }
            }
            test_value_001 = foundP_001;
          }
        }
        if (test_value_001) {
          self->value = type_to_class(type);
          if (typesiterator == NULL) {
            self->iterator_cons_list = types;
          }
          return (TRUE);
        }
      }
    }
  }
}

boolean filtered_types_nextP(All_Purpose_Iterator* self) {
  { Cons* types = ((Cons*)(self->iterator_cons_list));
    Iterator* typesiterator = ((Iterator*)(self->iterator_nested_iterator));
    List* modules = ((List*)(self->iterator_object));
    boolean filterclassesP = (modules != NULL) &&
        modules->non_emptyP();
    Surrogate* type = NULL;

    for (;;) {
      if (typesiterator != NULL) {
        if (!typesiterator->nextP()) {
          return (FALSE);
        }
        type = ((Surrogate*)(typesiterator->value));
      }
      else {
        if (types->emptyP()) {
          return (FALSE);
        }
        type = ((Surrogate*)(types->value));
        types = types->rest;
      }
      { boolean test_value_001 = FALSE;

        if (!filterclassesP) {
          test_value_001 = TRUE;
        }
        else {
          { boolean foundP_001 = FALSE;

            { Module* module = NULL;
              Cons* iter_001 = modules->the_cons_list;

              while (!nilP(iter_001)) {
                {
                  module = ((Module*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                if (module == type->home_context) {
                  foundP_001 = TRUE;
                  break;
                }
              }
            }
            test_value_001 = foundP_001;
          }
        }
        if (test_value_001) {
          self->value = type;
          if (typesiterator == NULL) {
            self->iterator_cons_list = types;
          }
          return (TRUE);
        }
      }
    }
  }
}

boolean get_types_nextP(All_Purpose_Iterator* self) {
  if (self->first_iterationP) {
    self->first_iterationP = FALSE;
    self->value = ((Class*)(((Logic_Object*)(self->iterator_object))->root_type->surrogate_value));
    return (TRUE);
  }
  { boolean nextP = self->iterator_nested_iterator->nextP();

    if (nextP) {
      self->value = ((Class*)(((Surrogate*)(((Proposition*)(self->iterator_nested_iterator->value))->arguments->nth(1)))->surrogate_value));
    }
    return (nextP);
  }
}

boolean class_names_nextP(All_Purpose_Iterator* self) {
  if (self->first_iterationP) {
    self->first_iterationP = FALSE;
    self->value = ((Class*)(self->iterator_object))->class_type;
    return (TRUE);
  }
  { boolean nextP = self->iterator_nested_iterator->nextP();

    if (nextP) {
      self->value = self->iterator_nested_iterator->value;
    }
    return (nextP);
  }
}

void collect_subtypes(Surrogate* type, List* result) {
  result->insert_new(type);
  { Class* renamed_Class = type_to_class(type);

    if (renamed_Class != NULL) {
      { Surrogate* sub = NULL;
        Cons* iter_001 = renamed_Class->class_direct_subs->the_cons_list;

        while (!nilP(iter_001)) {
          {
            sub = ((Surrogate*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          collect_subtypes(sub, result);
        }
      }
    }
  }
}

Slot_Value_Iterator* new_slot_value_iterator() {
  { Slot_Value_Iterator* self = NULL;

    self = new Slot_Value_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->key = NULL;
    self->nested_iterator = NULL;
    return (self);
  }
}

Object* access_slot_value_iterator_slot_value(Slot_Value_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_API_SUPPORT_NESTED_ITERATOR) {
    if (setvalueP) {
      self->nested_iterator = ((Iterator*)(value));
    }
    else {
      return (self->nested_iterator);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Slot_Value_Iterator::primary_type() {
  { Slot_Value_Iterator* self = this;

    return (SGT_API_SUPPORT_SLOT_VALUE_ITERATOR);
  }
}

boolean Slot_Value_Iterator::nextP() {
  { Slot_Value_Iterator* self = this;

    if (self->first_iterationP) {
      self->first_iterationP = FALSE;
    }
    { Iterator* iterator = self->nested_iterator;
      Proposition* proposition = NULL;

      while (iterator->nextP()) {
        proposition = ((Proposition*)(iterator->value));
        if (trueP(proposition)) {
          self->key = ((Slot*)(((Surrogate*)(proposition->renamed_Operator))->surrogate_value));
          self->value = proposition->arguments->nth(1)->value_of();
          return (TRUE);
        }
      }
      return (FALSE);
    }
  }
}

boolean all_propositions_nextP(All_Purpose_Iterator* self) {
  { Cons* propositions = self->iterator_cons_list;
    Proposition* proposition = NULL;
    Module* module = NULL;

    while (proposition == NULL) {
      while (nilP(propositions)) {
        module = ((Module*)(((List*)(self->iterator_object))->pop()));
        if (module == NULL) {
          self->value = NULL;
          return (FALSE);
        }
        propositions = module->locally_conceived_propositions_getter()->the_cons_list;
      }
      { Object* cons_001 = propositions->value;

        propositions = propositions->rest;
        proposition = ((Proposition*)(cons_001));
      }
      if (proposition->deletedP()) {
        proposition = NULL;
      }
    }
    self->value = proposition;
    self->iterator_cons_list = propositions;
    return (TRUE);
  }
}

Iterator* all_propositions(Module* module, boolean localP) {
  // Iterate over all conceived propositions visible from `module'.
  // Only propositions that haven't been deleted will be considered.
  // If `local?', only return propositions conceived locally in `module'.
  { All_Purpose_Iterator* self_001 = new_all_purpose_iterator();

    self_001->iterator_object = (localP ? ((List*)(list(1, module))) : ((List*)(visible_modules(module)->listify()->reverse())));
    self_001->iterator_next_code = ((cpp_function_code)(&all_propositions_nextP));
    self_001->iterator_cons_list = NIL;
    { All_Purpose_Iterator* value_001 = self_001;

      return (value_001);
    }
  }
}

boolean visible_termP(Logic_Object* term, Context* context, boolean localP) {
  return ((localP ? ((boolean)(term->home_context == context)) : ((boolean)(visible_fromP(((Module*)(term->home_context)), ((Module*)(context)))))));
}

boolean term_linked_to_visible_surrogateP(Logic_Object* term, Context* context, boolean localP) {
  { Context* namecontext = NULL;

    { Logic_Object* term_001 = term;

      if (taxonomy_isaP(term, SGT_API_SUPPORT_DESCRIPTION)) {
        { Description* term = NULL;

          term = ((Description*)(term_001));
          { Relation* nativerelation = term->native_relation;

            if (nativerelation != NULL) {
              { Relation* nativerelation_001 = nativerelation;

                if (classP(nativerelation)) {
                  { Class* nativerelation = NULL;

                    nativerelation = ((Class*)(nativerelation_001));
                    namecontext = ((Module*)(nativerelation->class_type->home_context));
                  }
                }
                else if (taxonomy_isaP(nativerelation, SGT_API_SUPPORT_SLOT)) {
                  { Slot* nativerelation = NULL;

                    nativerelation = ((Slot*)(nativerelation_001));
                    namecontext = ((Module*)(nativerelation->slot_owner->home_context));
                  }
                }
                else {
                }
              }
            }
          }
        }
      }
      else {
        { Surrogate* surrogate = ((Surrogate*)(dynamic_slot_value(term, SYM_API_SUPPORT_SURROGATE_VALUE_INVERSE, NULL)));

          if (surrogate != NULL) {
            namecontext = ((Module*)(surrogate->home_context));
          }
        }
      }
    }
    return ((namecontext != NULL) &&
        ((localP ? ((boolean)(namecontext == context)) : ((boolean)(visible_fromP(((Module*)(namecontext)), ((Module*)(context))))))));
  }
}

Iterator* all_unnamed_terms(Module* module, boolean localP) {
  // Iterate over all unnamed terms visible from `module'.  A term can be
  // an instance (or individual) as well as a description.  Only terms that
  // haven't been deleted will be considered.  If `local?', only return
  // terms created locally in `module'.
  { Cons* terms = NIL;
    Cons* termswithduplicates = NIL;
    Object* value = NULL;
    Logic_Object* term = NULL;

    { Surrogate* surrogate = NULL;
      Iterator* iter_001 = all_surrogates(module, localP);

      while (iter_001->nextP()) {
        {
          surrogate = ((Surrogate*)(iter_001->value));
        }
        value = surrogate->surrogate_value;
        if (value != NULL) {
          { Object* value_001 = value;

            if (taxonomy_isaP(value, SGT_API_SUPPORT_RELATION)) {
              { Relation* value = NULL;

                value = ((Relation*)(value_001));
                term = ((Description*)(dynamic_slot_value(value, SYM_API_SUPPORT_DESCRIPTION, NULL)));
                if ((term != NULL) &&
                    ((!term->deletedP()) &&
                     visible_termP(term, module, localP))) {
                  terms = cons(term, terms);
                }
                term = ((Description*)(dynamic_slot_value(value, SYM_API_SUPPORT_DEFINITION, NULL)));
                if ((term != NULL) &&
                    ((!term->deletedP()) &&
                     visible_termP(term, module, localP))) {
                  terms = cons(term, terms);
                }
              }
            }
            else {
            }
          }
        }
      }
    }
    { Proposition* proposition = NULL;
      Iterator* iter_002 = all_propositions(module, localP);

      while (iter_002->nextP()) {
        {
          proposition = ((Proposition*)(iter_002->value));
        }
        { Object* arg = NULL;
          Vector* vector_001 = proposition->arguments;
          int index_001 = 0;
          int length_001 = vector_001->length();

          while (index_001 < length_001) {
            {
              arg = vector_001->nth(index_001);
              index_001 = index_001 + 1;
            }
            if (isaP(arg, SGT_API_SUPPORT_LOGIC_OBJECT) &&
                (!arg->deletedP())) {
              term = ((Logic_Object*)(arg));
              if ((!visible_termP(term, module, localP)) ||
                  term_linked_to_visible_surrogateP(term, module, localP)) {
                continue;
              }
              { Logic_Object* term_001 = term;

                if (taxonomy_isaP(term, SGT_API_SUPPORT_PATTERN_VARIABLE)) {
                  { Pattern_Variable* term = NULL;

                    term = ((Pattern_Variable*)(term_001));
                  }
                }
                else if (taxonomy_isaP(term, SGT_API_SUPPORT_SKOLEM)) {
                  { Skolem* term = NULL;

                    term = ((Skolem*)(term_001));
                    if (term->defining_proposition != NULL) {
                      if (term->defining_proposition == proposition) {
                        terms = cons(term, terms);
                      }
                    }
                    else {
                      termswithduplicates = cons(term, termswithduplicates);
                    }
                  }
                }
                else {
                  termswithduplicates = cons(term, termswithduplicates);
                }
              }
            }
          }
        }
      }
    }
    { List* self_001 = new_list();

      self_001->the_cons_list = termswithduplicates->remove_duplicates()->concatenate(terms);
      { Iterator* value_002 = self_001->allocate_destructive_list_iterator();

        return (value_002);
      }
    }
  }
}

boolean all_named_terms_nextP(All_Purpose_Iterator* self) {
  { int cursor = self->iterator_integer;
    Cons* modules = self->iterator_cons_list;
    Surrogate* surrogate = NULL;
    Object* value = NULL;

    while (cursor < self->iterator_second_integer) {
      surrogate = ((Surrogate*)(oSURROGATE_ARRAYo->nth(cursor)));
      if ((surrogate != NULL) &&
          modules->memberP(((Module*)(surrogate->home_context)))) {
        value = surrogate->surrogate_value;
        if (value != NULL) {
          { Object* value_001 = value;

            if (taxonomy_isaP(value, SGT_API_SUPPORT_LOGIC_OBJECT)) {
              { Logic_Object* value = NULL;

                value = ((Logic_Object*)(value_001));
                if ((!value->deletedP()) &&
                    ((surrogate == dynamic_slot_value(value, SYM_API_SUPPORT_SURROGATE_VALUE_INVERSE, NULL)) &&
                     modules->memberP(value->home_context))) {
                  self->value = value;
                  self->iterator_integer = cursor + 1;
                  return (TRUE);
                }
              }
            }
            else {
            }
          }
        }
      }
      cursor = cursor + 1;
    }
    return (FALSE);
  }
}

Iterator* all_named_terms(Module* module, boolean localP) {
  // Iterate over all named terms visible from `module'.  A term can be an
  // instance (or individual) as well as a description.  Only terms that
  // haven't been deleted will be considered.  If `local?', only return 
  // terms created locally in `module'.
  return (allocate_all_meta_objects_iterator(oSURROGATE_ARRAYo->top_symbol_offset + 1, ((cpp_function_code)(&all_named_terms_nextP)), module, localP));
}

Iterator* all_terms(Module* module, boolean localP) {
  // Iterate over all terms visible from `module'.  A term can be an
  // instance (or individual) as well as a description.  Only terms that
  // haven't been deleted will be considered.  If `local?', only return 
  // terms created locally in `module'.
  return (all_named_terms(module, localP)->concatenate(all_unnamed_terms(module, localP)));
}

boolean filter_instanceP(Logic_Object* self, All_Purpose_Iterator* iterator) {
  iterator = iterator;
  return (!isaP(self, SGT_API_SUPPORT_DESCRIPTION));
}

Iterator* all_named_instances(Module* module, boolean localP) {
  // Iterate over all named instances (or individuals) visible from `module'.
  // Only instances that haven't been deleted will be considered.  If `local?',
  // only return instances created locally in `module'.
  { All_Purpose_Iterator* self_001 = new_all_purpose_iterator();

    self_001->iterator_nested_iterator = all_named_terms(module, localP);
    self_001->iterator_next_code = ((cpp_function_code)(&filtered_nested_iterator_nextP));
    self_001->iterator_filter_code = ((cpp_function_code)(&filter_instanceP));
    { All_Purpose_Iterator* value_001 = self_001;

      return (value_001);
    }
  }
}

Iterator* all_instances(Module* module, boolean localP) {
  // Iterate over all instances (or individuals) visible from `module'.
  // Only instances that haven't been deleted will be considered.  If `local?',
  // only return instances created locally in `module'.
  { All_Purpose_Iterator* iterator = ((All_Purpose_Iterator*)(all_terms(module, localP)));

    iterator->iterator_filter_code = ((cpp_function_code)(&filter_instanceP));
    return (iterator);
  }
}

Logic_Object* string_to_logic_object(char* string) {
  { Surrogate* sgt = NULL;
    Iterator* iter_001 = all_surrogates(NULL, FALSE);

    while (iter_001->nextP()) {
      {
        sgt = ((Surrogate*)(iter_001->value));
      }
      if (string_eqlP(sgt->symbol_name, string) &&
          ((sgt->surrogate_value != NULL) &&
           isaP(sgt->surrogate_value, SGT_API_SUPPORT_LOGIC_OBJECT))) {
        return (((Logic_Object*)(sgt->surrogate_value)));
      }
    }
  }
  return (NULL);
}

void startup_api_support() {
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
            SYM_API_SUPPORT_NESTED_ITERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("NESTED-ITERATOR", NULL, 0)));
            SGT_API_SUPPORT_SLOT_VALUE_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("SLOT-VALUE-ITERATOR", NULL, 1)));
            SGT_API_SUPPORT_DESCRIPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 1)));
            SGT_API_SUPPORT_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("SLOT", string_get_module("/STELLA", TRUE), 1)));
            SYM_API_SUPPORT_SURROGATE_VALUE_INVERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE-VALUE-INVERSE", NULL, 0)));
            SGT_API_SUPPORT_RELATION = ((Surrogate*)(intern_rigid_symbol_wrt_module("RELATION", string_get_module("/STELLA", TRUE), 1)));
            SYM_API_SUPPORT_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 0)));
            SYM_API_SUPPORT_DEFINITION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINITION", NULL, 0)));
            SGT_API_SUPPORT_LOGIC_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-OBJECT", NULL, 1)));
            SGT_API_SUPPORT_PATTERN_VARIABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("PATTERN-VARIABLE", NULL, 1)));
            SGT_API_SUPPORT_SKOLEM = ((Surrogate*)(intern_rigid_symbol_wrt_module("SKOLEM", NULL, 1)));
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("SLOT-VALUE-ITERATOR", "(DEFCLASS SLOT-VALUE-ITERATOR (DICTIONARY-ITERATOR) :PARAMETERS ((ANY-VALUE :TYPE OBJECT) (ANY-KEY :TYPE OBJECT)) :SLOTS ((NESTED-ITERATOR :TYPE ITERATOR)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_slot_value_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_slot_value_iterator_slot_value));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("FILTERED-TYPES-TO-CLASSES-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (FILTERED-TYPES-TO-CLASSES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filtered_types_to_classes_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTERED-TYPES-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (FILTERED-TYPES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filtered_types_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-TYPES-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (GET-TYPES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&get_types_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-NAMES-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (CLASS-NAMES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&class_names_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-SUBTYPES", "TYPE", "(DEFUN COLLECT-SUBTYPES ((TYPE TYPE) (RESULT LIST)))");

              method->function_code = ((cpp_function_code)(&collect_subtypes));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "SLOT-VALUE-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF SLOT-VALUE-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Slot_Value_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-PROPOSITIONS-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ALL-PROPOSITIONS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&all_propositions_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-PROPOSITIONS", "MODULE", "(DEFUN (ALL-PROPOSITIONS (ITERATOR OF PROPOSITION)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all conceived propositions visible from `module'.\nOnly propositions that haven't been deleted will be considered.\nIf `local?', only return propositions conceived locally in `module'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("VISIBLE-TERM?", "LOGIC-OBJECT", "(DEFUN (VISIBLE-TERM? BOOLEAN) ((TERM LOGIC-OBJECT) (CONTEXT CONTEXT) (LOCAL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&visible_termP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERM-LINKED-TO-VISIBLE-SURROGATE?", "LOGIC-OBJECT", "(DEFUN (TERM-LINKED-TO-VISIBLE-SURROGATE? BOOLEAN) ((TERM LOGIC-OBJECT) (CONTEXT CONTEXT) (LOCAL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&term_linked_to_visible_surrogateP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-UNNAMED-TERMS", "MODULE", "(DEFUN (ALL-UNNAMED-TERMS (ITERATOR OF LOGIC-OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all unnamed terms visible from `module'.  A term can be\nan instance (or individual) as well as a description.  Only terms that\nhaven't been deleted will be considered.  If `local?', only return\nterms created locally in `module'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_unnamed_terms));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-NAMED-TERMS-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ALL-NAMED-TERMS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&all_named_terms_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-NAMED-TERMS", "MODULE", "(DEFUN (ALL-NAMED-TERMS (ITERATOR OF LOGIC-OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all named terms visible from `module'.  A term can be an\ninstance (or individual) as well as a description.  Only terms that\nhaven't been deleted will be considered.  If `local?', only return \nterms created locally in `module'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_named_terms));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-TERMS", "MODULE", "(DEFUN (ALL-TERMS (ITERATOR OF LOGIC-OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all terms visible from `module'.  A term can be an\ninstance (or individual) as well as a description.  Only terms that\nhaven't been deleted will be considered.  If `local?', only return \nterms created locally in `module'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_terms));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-INSTANCE?", "LOGIC-OBJECT", "(DEFUN (FILTER-INSTANCE? BOOLEAN) ((SELF LOGIC-OBJECT) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_instanceP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-NAMED-INSTANCES", "MODULE", "(DEFUN (ALL-NAMED-INSTANCES (ITERATOR OF LOGIC-OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all named instances (or individuals) visible from `module'.\nOnly instances that haven't been deleted will be considered.  If `local?',\nonly return instances created locally in `module'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_named_instances));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-INSTANCES", "MODULE", "(DEFUN (ALL-INSTANCES (ITERATOR OF LOGIC-OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all instances (or individuals) visible from `module'.\nOnly instances that haven't been deleted will be considered.  If `local?',\nonly return instances created locally in `module'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_instances));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING-TO-LOGIC-OBJECT", "STRING", "(DEFUN (STRING-TO-LOGIC-OBJECT LOGIC-OBJECT) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&string_to_logic_object));
            }
            define_method_from_stringified_source("STARTUP-API-SUPPORT", NULL, "(DEFUN STARTUP-API-SUPPORT ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            oSTRING_TO_OBJECT_FUNCTIONSo->insert_at(SGT_API_SUPPORT_LOGIC_OBJECT, function_code_wrap_literal(((cpp_function_code)(&string_to_logic_object))));
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

