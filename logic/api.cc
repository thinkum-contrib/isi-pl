// api.cc

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

Surrogate* SGT_API_RELATION = NULL;

Symbol* SYM_API_DEFINITION_STRING = NULL;

Surrogate* SGT_API_SLOT = NULL;

Surrogate* SGT_API_LOGIC_OBJECT = NULL;

Symbol* SYM_API_SURROGATE_VALUE_INVERSE = NULL;

Surrogate* SGT_API_MODULE = NULL;

Surrogate* SGT_API_GENERALIZED_SYMBOL = NULL;

Surrogate* SGT_API_CLASS = NULL;

Surrogate* SGT_API_CONTEXT = NULL;

Symbol* SYM_API_DESCRIPTION = NULL;

Surrogate* SGT_API_LITERAL_WRAPPER = NULL;

Surrogate* SGT_API_SYMBOL = NULL;

Keyword* KWD_API_IN = NULL;

Keyword* KWD_API_FUNCTION = NULL;

List* oSELECTED_MODULESo = NULL;

Symbol* SYM_API_oSELECTED_MODULESo = NULL;

Surrogate* SGT_API_BOOLEAN = NULL;

Surrogate* SGT_API_TABLE = NULL;

char* logic_definition(Object* object) {
  // Return the logic definition of `object'.
  { Object* object_001 = object;

    if (taxonomy_isaP(object, SGT_API_RELATION)) {
      { Relation* object = NULL;

        object = ((Relation*)(object_001));
        return (((String_Wrapper*)(dynamic_slot_value(object, SYM_API_DEFINITION_STRING, NULL_STRING_WRAPPER)))->wrapper_value);
      }
    }
    else {
      return (NULL);
    }
  }
}

char* source_definition(Object* object) {
  // Return the source definition of `object'.
  { Object* object_001 = object;

    if (classP(object)) {
      { Class* object = NULL;

        object = ((Class*)(object_001));
        return (object->class_stringified_source);
      }
    }
    else if (method_slotP(object)) {
      { Method_Slot* object = NULL;

        object = ((Method_Slot*)(object_001));
        return (object->method_stringified_source);
      }
    }
    else {
      return (NULL);
    }
  }
}

char* object_name(Object* object) {
  // Return the name of a stella object
  { Object* object_001 = object;

    if (classP(object)) {
      { Class* object = NULL;

        object = ((Class*)(object_001));
        return (object->class_type->symbol_name);
      }
    }
    else if (taxonomy_isaP(object, SGT_API_SLOT)) {
      { Slot* object = NULL;

        object = ((Slot*)(object_001));
        return (object->slot_name->symbol_name);
      }
    }
    else if (taxonomy_isaP(object, SGT_API_LOGIC_OBJECT)) {
      { Logic_Object* object = NULL;

        object = ((Logic_Object*)(object_001));
        return (((Surrogate*)(dynamic_slot_value(object, SYM_API_SURROGATE_VALUE_INVERSE, NULL)))->symbol_name);
      }
    }
    else if (taxonomy_isaP(object, SGT_API_MODULE)) {
      { Module* object = NULL;

        object = ((Module*)(object_001));
        return (object->module_name);
      }
    }
    else if (taxonomy_isaP(object, SGT_API_GENERALIZED_SYMBOL)) {
      { Generalized_Symbol* object = NULL;

        object = ((Generalized_Symbol*)(object_001));
        return (object->symbol_name);
      }
    }
    else {
      cerr << "`" << object << "'" << " is not a valid case option";
    }
  }
}

Class* find_class(char* name) {
  // Retrieve the class with name `name'
  return (((Class*)(search_for_object(string_wrap_literal(name), SGT_API_CLASS))));
}

Context* find_context(char* name) {
  // Retrieve the context with name `name'
  return (((Context*)(search_for_object(string_wrap_literal(name), SGT_API_CONTEXT))));
}

Logic_Object* find_instance(char* name) {
  // Find the instance with name `name'
  { Surrogate* surrogate = lookup_surrogate(name);

    if (surrogate != NULL) {
      return (((Logic_Object*)(surrogate->surrogate_value)));
    }
    return (NULL);
  }
}

Logic_Object* get_instance(char* name, boolean errorP) {
  // Find the instance with name `name'
  { Surrogate* surrogate = lookup_surrogate(name);

    if (surrogate != NULL) {
      return (((Logic_Object*)(surrogate->surrogate_value)));
    }
    if (errorP) {
      cerr << "Instance " << "`" << name << "'" << " does not exist.";
    }
    else {
      return (NULL);
    }
  }
}

Iterator* all_superclasses(Class* renamed_Class) {
  // Get all superclasses (excluding `class') of `class'.
  { List* supertypes = new_list();

    { Class* super = NULL;
      Cons* iter_001 = renamed_Class->class_all_super_classes;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          super = ((Class*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = permanent_cons(super->class_type, NIL);
            if (supertypes->the_cons_list->emptyP()) {
              supertypes->the_cons_list = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(supertypes->the_cons_list, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = permanent_cons(super->class_type, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    { All_Purpose_Iterator* self_002 = new_all_purpose_iterator();

      self_002->iterator_nested_iterator = supertypes->allocate_destructive_list_iterator();
      self_002->iterator_object = oSELECTED_MODULESo;
      self_002->iterator_next_code = ((cpp_function_code)(&filtered_types_to_classes_nextP));
      { All_Purpose_Iterator* value_001 = self_002;

        return (value_001);
      }
    }
  }
}

boolean subclassP(Class* class1, Class* class2) {
  return (subclass_ofP(class1, class2));
}

Iterator* direct_superclasses(Class* renamed_Class) {
  // Get direct superclasses of `class'.
  { All_Purpose_Iterator* self_001 = new_all_purpose_iterator();

    self_001->iterator_cons_list = renamed_Class->class_direct_supers->the_cons_list;
    self_001->iterator_object = oSELECTED_MODULESo;
    self_001->iterator_next_code = ((cpp_function_code)(&filtered_types_to_classes_nextP));
    { All_Purpose_Iterator* value_001 = self_001;

      return (value_001);
    }
  }
}

Iterator* Relation::direct_superrelations() {
  // Return direct super classes/slots/tables of 'self'.
  { Relation* self = this;

    return (NULL);
  }
}

Iterator* Slot::direct_superrelations() {
  { Slot* self = this;

    return (((List_Iterator*)(self->slot_direct_supers_reader()->allocate_iterator())));
  }
}

Iterator* Class::direct_superrelations() {
  { Class* self = this;

    return (self->direct_super_classes());
  }
}

Cons* test1(Cons* parents) {
  { Cons* mostspecificsupers = NIL;

    return (mostspecificsupers);
  }
}

Iterator* direct_supertypes(Class* renamed_Class) {
  // Get direct supertypes of `class'.
  { Cons* parents = renamed_Class->class_direct_supers->the_cons_list;
    Cons* mostspecificsupers = NIL;

    { Surrogate* supertype = NULL;
      Cons* iter_001 = parents;

      while (!nilP(iter_001)) {
        {
          supertype = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        { boolean test_value_001 = FALSE;

          if (((Class*)(supertype->surrogate_value)) == NULL) {
            test_value_001 = TRUE;
          }
          else {
            {
              { boolean foundP_001 = FALSE;

                { Surrogate* othersupertype = NULL;
                  Cons* iter_002 = parents;

                  while (!nilP(iter_002)) {
                    {
                      othersupertype = ((Surrogate*)(iter_002->value));
                      iter_002 = iter_002->rest;
                    }
                    if ((!(supertype == othersupertype)) &&
                        ((((Class*)(othersupertype->surrogate_value)) != NULL) &&
                         subtype_ofP(othersupertype, supertype))) {
                      foundP_001 = TRUE;
                      break;
                    }
                  }
                }
                test_value_001 = foundP_001;
              }
              test_value_001 = !test_value_001;
            }
          }
          if (test_value_001) {
            mostspecificsupers = cons(supertype, mostspecificsupers);
          }
        }
      }
    }
    { All_Purpose_Iterator* self_001 = new_all_purpose_iterator();

      self_001->iterator_cons_list = mostspecificsupers;
      self_001->iterator_object = oSELECTED_MODULESo;
      self_001->iterator_next_code = ((cpp_function_code)(&filtered_types_nextP));
      { All_Purpose_Iterator* value_001 = self_001;

        return (value_001);
      }
    }
  }
}

Iterator* direct_subclasses(Class* renamed_Class) {
  // Get direct subclasses of `class'.
  { All_Purpose_Iterator* self_001 = new_all_purpose_iterator();

    self_001->iterator_cons_list = renamed_Class->class_direct_subs->the_cons_list;
    self_001->iterator_object = oSELECTED_MODULESo;
    self_001->iterator_next_code = ((cpp_function_code)(&filtered_types_to_classes_nextP));
    { All_Purpose_Iterator* value_001 = self_001;

      return (value_001);
    }
  }
}

All_Purpose_Iterator* class_names(Class* renamed_Class) {
  // Get all names (including synonyms) of `class'
  { List_Iterator* synonymsiter = ((List_Iterator*)(renamed_Class->class_synonyms_reader()->allocate_iterator()));
    All_Purpose_Iterator* resultiter = new_all_purpose_iterator();

    resultiter->iterator_nested_iterator = synonymsiter;
    resultiter->iterator_object = renamed_Class;
    resultiter->iterator_next_code = ((cpp_function_code)(&class_names_nextP));
    return (resultiter);
  }
}

Cons_Iterator* get_instances(Class* renamed_Class) {
  // Return all instances asserted to be of type `class'
  { Cons* instances = NIL;

    { boolean alwaysP_001 = TRUE;

      { Surrogate* super = NULL;
        Cons* iter_001 = renamed_Class->class_direct_supers->the_cons_list;

        while (!nilP(iter_001)) {
          {
            super = ((Surrogate*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          if (!(((Class*)(super->surrogate_value)) != NULL)) {
            alwaysP_001 = FALSE;
            break;
          }
        }
      }
      if (!(alwaysP_001)) {
        cerr << "Get-instances: " << "`" << renamed_Class << "'" << " isn't finalized, returning empty list.";
        return (NIL->allocate_iterator());
      }
    }
    { Class* rootclass = NULL;
      Iterator* iter_002 = all_root_classes(renamed_Class);

      while (iter_002->nextP()) {
        {
          rootclass = ((Class*)(iter_002->value));
        }
        if (((Description*)(dynamic_slot_value(rootclass, SYM_API_DESCRIPTION, NULL))) != NULL) {
          { Object* instance = NULL;
            Cons* iter_003 = ((Description*)(dynamic_slot_value(rootclass, SYM_API_DESCRIPTION, NULL)))->extension_reader()->the_cons_list;

            while (!nilP(iter_003)) {
              {
                instance = iter_003->value;
                iter_003 = iter_003->rest;
              }
              instances = cons(instance, instances);
            }
          }
        }
      }
    }
    return (instances->allocate_iterator());
  }
}

Iterator* get_subclasses(Class* renamed_Class) {
  // Get all subclasses of `class', including self.
  { List* subtypes = new_list();

    collect_subtypes(renamed_Class->class_type, subtypes);
    { All_Purpose_Iterator* self_002 = new_all_purpose_iterator();

      self_002->iterator_nested_iterator = subtypes->allocate_destructive_list_iterator();
      self_002->iterator_object = oSELECTED_MODULESo;
      self_002->iterator_next_code = ((cpp_function_code)(&filtered_types_to_classes_nextP));
      { All_Purpose_Iterator* value_001 = self_002;

        return (value_001);
      }
    }
  }
}

void add_superclass(Generalized_Symbol* super, Class* renamed_Class) {
  // Add the class named 'super' to the list of
  // superclasses of 'class'.
  { Module* old_OmoduleO_001 = oMODULEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = ((Module*)(renamed_Class->class_type->home_context));
          super = intern_derived_symbol(super, super->symbol_name);
          { Cons* sourcetree = ((Cons*)(unstringify(renamed_Class->class_stringified_source)));
            Cons* directsupers = ((Cons*)(sourcetree->third()));

            if (!(directsupers->memberP(super))) {
              { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

                { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oTRANSIENTOBJECTSpo = TRUE;
                      sourcetree->third_setter(directsupers->concatenate(cons(super, NIL)));
                      oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                    resignal();
                  }
                }
              }
              define_class_from_parse_tree(sourcetree);
              finalize_classes_and_slots();
            }
            sourcetree->free_parse_tree();
          }
          oMODULEo = old_OmoduleO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oMODULEo = old_OmoduleO_001;
        resignal();
      }
    }
  }
}

void remove_superclass(Generalized_Symbol* super, Class* renamed_Class) {
  // Remove the class named 'super' from the list of
  // superclasses of 'class'.
  { Module* old_OmoduleO_001 = oMODULEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = ((Module*)(renamed_Class->class_type->home_context));
          super = intern_derived_symbol(super, super->symbol_name);
          { Cons* sourcetree = ((Cons*)(unstringify(renamed_Class->class_stringified_source)));
            Cons* directsupers = ((Cons*)(sourcetree->third()));

            if (directsupers->memberP(super)) {
              sourcetree->third_setter(directsupers->remove(super));
              define_class_from_parse_tree(sourcetree);
              finalize_classes_and_slots();
            }
            sourcetree->free_parse_tree();
          }
          oMODULEo = old_OmoduleO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oMODULEo = old_OmoduleO_001;
        resignal();
      }
    }
  }
}

Class* domain(Slot* slot) {
  // Return the owner of `slot'
  return (((Class*)(slot->slot_owner->surrogate_value)));
}

boolean computedP(Slot* slot) {
  // Return TRUE if 'slot is computed by a STELLA method or
  // function.
  return (method_slotP(slot));
}

Class* range(Slot* slot) {
  // Return the type of `slot'
  return (((Class*)(slot->slot_base_type->surrogate_value)));
}

boolean read_onlyP(Storage_Slot* slot) {
  // Return TRUE if `slot' is readonly
  return (slot->slot_read_onlyP);
}

boolean slotP(Object* object) {
  // Return TRUE if `object' is a slot
  return (isaP(object, SGT_API_SLOT));
}

boolean asserted_instance_of_classP(Logic_Object* instance, Class* renamed_Class) {
  // Return TRUE if `instance' has been asserted to be
  //                   of type `class'
  return (get_types(instance)->memberP(renamed_Class));
}

boolean constantP(Object* object) {
  // Return TRUE if `object' is a literal or symbol
  return (isaP(object, SGT_API_LITERAL_WRAPPER) ||
      isaP(object, SGT_API_SYMBOL));
}

All_Purpose_Iterator* get_types(Logic_Object* instance) {
  // Return all classes `instance' belongs to
  { Iterator* inpropiter = all_directly_dependent_propositions(instance, KWD_API_IN);
    All_Purpose_Iterator* resultiter = new_all_purpose_iterator();

    resultiter->iterator_nested_iterator = inpropiter;
    resultiter->iterator_object = instance;
    resultiter->iterator_next_code = ((cpp_function_code)(&get_types_nextP));
    return (resultiter);
  }
}

Object* get_value(Logic_Object* instance, Slot* slot) {
  // Get the value of 'slot' on `instance'
  return (get_attribute_proposition_value(instance, slot->slot_slotref));
}

Slot_Value_Iterator* list_slot_names_and_values(Logic_Object* instance) {
  // Return all slots and associated values asserted for
  // `instance'
  { Iterator* propiter = all_dependent_attribute_propositions(instance, KWD_API_FUNCTION);
    Slot_Value_Iterator* resultiter = new_slot_value_iterator();

    resultiter->nested_iterator = propiter;
    return (resultiter);
  }
}

Context* context(Object* object) {
  // Return context (if any) of `object'
  { Object* object_001 = object;

    if (classP(object)) {
      { Class* object = NULL;

        object = ((Class*)(object_001));
        return (object->class_type->home_context);
      }
    }
    else if (taxonomy_isaP(object, SGT_API_SLOT)) {
      { Slot* object = NULL;

        object = ((Slot*)(object_001));
        return (object->slot_owner->home_context);
      }
    }
    else if (taxonomy_isaP(object, SGT_API_LOGIC_OBJECT)) {
      { Logic_Object* object = NULL;

        object = ((Logic_Object*)(object_001));
        return (object->home_context);
      }
    }
    else if (taxonomy_isaP(object, SGT_API_GENERALIZED_SYMBOL)) {
      { Generalized_Symbol* object = NULL;

        object = ((Generalized_Symbol*)(object_001));
        return (((Module*)(object->home_context)));
      }
    }
    else {
      return (NULL);
    }
  }
}

All_Purpose_Iterator* list_module(Module* module) {
  // Return all classes and instances in `module'
  return (all_classes(module, TRUE)->concatenate(all_instances(module, TRUE)));
}

Iterator* context_parents(Module* module) {
  // Return the parent contexts of `module'.
  return (module->parent_contexts());
}

Iterator* context_children(Module* module) {
  // Return the child contexts of `module'.
  return (((List_Iterator*)(module->child_contexts->allocate_iterator())));
}

Object* iterator_key(Dictionary_Iterator* self) {
  // Return the current key of `self'
  return (self->key);
}

Object* iterator_value(Iterator* self) {
  // Return the current value of `self'
  return (self->value);
}

List* read_Oselected_modulesO() {
  return (oSELECTED_MODULESo);
}

List* write_Oselected_modulesO(List* value) {
  oSELECTED_MODULESo = value;
  return (value);
}

void select_module(Module* module, boolean localP) {
  // Add 'module' to the list of selected modules.  
  // If 'local?' is FALSE also select all modules visible from 'module'.
  if (null_listP(oSELECTED_MODULESo)) {
    oSELECTED_MODULESo = new_list();
  }
  if (localP) {
    if (!(oSELECTED_MODULESo->memberP(module))) {
      oSELECTED_MODULESo->insert_last(module);
    }
  }
  else {
    { Module* mod = NULL;
      Iterator* iter_001 = visible_modules(module);
      Cons* collect_001 = NULL;

      while (iter_001->nextP()) {
        {
          mod = ((Module*)(iter_001->value));
        }
        if (!oSELECTED_MODULESo->memberP(mod)) {
          if (collect_001 == NULL) {
            {
              collect_001 = permanent_cons(mod, NIL);
              if (oSELECTED_MODULESo->the_cons_list->emptyP()) {
                oSELECTED_MODULESo->the_cons_list = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(oSELECTED_MODULESo->the_cons_list, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = permanent_cons(mod, NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
    }
  }
}

void deselect_module(Module* module, boolean localP) {
  // Remove 'module' from the list of selected modules.  
  // If 'local?' is FALSE also deselect all modules visible from 'module'.
  if (defined_listP(oSELECTED_MODULESo)) {
    if (localP) {
      oSELECTED_MODULESo->remove(module);
    }
    else {
      { Module* mod = NULL;
        Iterator* iter_001 = visible_modules(module);

        while (iter_001->nextP()) {
          {
            mod = ((Module*)(iter_001->value));
          }
          oSELECTED_MODULESo->remove(mod);
        }
      }
    }
  }
}

void select_all_modules() {
  // Select all modules.
  if (defined_listP(oSELECTED_MODULESo)) {
    oSELECTED_MODULESo->clear();
  }
}

boolean visible_objectP(Object* object) {
  // Return TRUE if 'object' is visible with respect to the
  // set of currently selected modules.
  if ((oSELECTED_MODULESo == NULL) ||
      oSELECTED_MODULESo->emptyP()) {
    return (TRUE);
  }
  else {
    { Context* ct = context(object);

      { boolean foundP_001 = FALSE;

        { Module* module = NULL;
          Cons* iter_001 = oSELECTED_MODULESo->the_cons_list;

          while (!nilP(iter_001)) {
            {
              module = ((Module*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            if (module == ct) {
              foundP_001 = TRUE;
              break;
            }
          }
        }
        { boolean value_001 = foundP_001;

          return (value_001);
        }
      }
    }
  }
}

Iterator* slot_column_types(Slot* self) {
  { Slot* self_001 = self;

    if (storage_slotP(self)) {
      { Storage_Slot* self = NULL;

        self = ((Storage_Slot*)(self_001));
        { Surrogate* domain = self->slot_owner;
          Surrogate* range = self->slot_base_type;
          List* typeslist = ((range == SGT_API_BOOLEAN) ? ((List*)(list(1, domain))) : ((List*)(list(2, domain, range))));

          return (typeslist->allocate_destructive_list_iterator());
        }
      }
    }
    else if (method_slotP(self)) {
      { Method_Slot* self = NULL;

        self = ((Method_Slot*)(self_001));
        { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

          iterator->iterator_next_code = ((cpp_function_code)(&slot_column_types_nextP));
          iterator->iterator_nested_iterator = ((List_Iterator*)(((Method_Slot*)(self))->method_parameter_type_specifiers_reader()->allocate_iterator()));
          iterator->iterator_empty_code = ((cpp_function_code)(&slot_column_types_emptyP));
          iterator->iterator_object = self;
          iterator->iterator_integer = 1;
          return (iterator);
        }
      }
    }
    else if (taxonomy_isaP(self, SGT_API_TABLE)) {
      { Table* self = NULL;

        self = ((Table*)(self_001));
        { List* typeslist = new_list();

          { Object* tspec = NULL;
            Cons* iter_001 = self->tuple_domains->the_cons_list;
            Cons* collect_001 = NULL;

            while (!nilP(iter_001)) {
              {
                tspec = iter_001->value;
                iter_001 = iter_001->rest;
              }
              if (collect_001 == NULL) {
                {
                  collect_001 = permanent_cons(type_spec_to_base_type(((Standard_Object*)(tspec))), NIL);
                  if (typeslist->the_cons_list->emptyP()) {
                    typeslist->the_cons_list = collect_001;
                  }
                  else {
                    add_cons_to_end_of_cons_list(typeslist->the_cons_list, collect_001);
                  }
                }
              }
              else {
                {
                  collect_001->rest = permanent_cons(type_spec_to_base_type(((Standard_Object*)(tspec))), NIL);
                  collect_001 = collect_001->rest;
                }
              }
            }
          }
          return (typeslist->allocate_destructive_list_iterator());
        }
      }
    }
    else {
      cerr << "`" << self << "'" << " is not a valid case option";
    }
  }
}

boolean slot_column_types_nextP(All_Purpose_Iterator* self) {
  switch (self->iterator_integer) {
    case 1: 
      if (!self->iterator_nested_iterator->nextP()) {
        self->iterator_nested_iterator = ((List_Iterator*)(((Method_Slot*)(self->iterator_object))->method_return_type_specifiers_reader()->allocate_iterator()));
        self->iterator_integer = 2;
        if (self->iterator_nested_iterator->nextP()) {
          self->iterator_second_object = type_spec_to_base_type(((Standard_Object*)(self->iterator_nested_iterator->value)));
        }
        else {
          return (FALSE);
        }
        return (slot_column_types_nextP(self));
      }
      self->value = type_spec_to_base_type(((Standard_Object*)(self->iterator_nested_iterator->value)));
      return (TRUE);
    case 2: 
      self->value = self->iterator_second_object;
      if (self->iterator_nested_iterator->nextP()) {
        self->iterator_second_object = type_spec_to_base_type(((Standard_Object*)(self->iterator_nested_iterator->value)));
        return (TRUE);
      }
      else if (self->value == SGT_API_BOOLEAN) {
        return (FALSE);
      }
      else {
        self->iterator_integer = 3;
        return (TRUE);
      }
    break;
    case 3: 
      return (FALSE);
  }
}

boolean slot_column_types_emptyP(All_Purpose_Iterator* self) {
  return (self->iterator_nested_iterator->emptyP());
}

boolean instance_p(Object* object) {
  // Return TRUE if `object' is an instance
  return (isaP(object, SGT_API_LOGIC_OBJECT));
}

void startup_api() {
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
            SGT_API_RELATION = ((Surrogate*)(intern_rigid_symbol_wrt_module("RELATION", string_get_module("/STELLA", TRUE), 1)));
            SYM_API_DEFINITION_STRING = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINITION-STRING", NULL, 0)));
            SGT_API_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("SLOT", string_get_module("/STELLA", TRUE), 1)));
            SGT_API_LOGIC_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-OBJECT", NULL, 1)));
            SYM_API_SURROGATE_VALUE_INVERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE-VALUE-INVERSE", NULL, 0)));
            SGT_API_MODULE = ((Surrogate*)(intern_rigid_symbol_wrt_module("MODULE", string_get_module("/STELLA", TRUE), 1)));
            SGT_API_GENERALIZED_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("GENERALIZED-SYMBOL", string_get_module("/STELLA", TRUE), 1)));
            SGT_API_CLASS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CLASS", string_get_module("/STELLA", TRUE), 1)));
            SGT_API_CONTEXT = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONTEXT", string_get_module("/STELLA", TRUE), 1)));
            SYM_API_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 0)));
            SGT_API_LITERAL_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("LITERAL-WRAPPER", string_get_module("/STELLA", TRUE), 1)));
            SGT_API_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("SYMBOL", string_get_module("/STELLA", TRUE), 1)));
            KWD_API_IN = ((Keyword*)(intern_rigid_symbol_wrt_module("IN", NULL, 2)));
            KWD_API_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            SYM_API_oSELECTED_MODULESo = ((Symbol*)(intern_rigid_symbol_wrt_module("*SELECTED-MODULES*", NULL, 0)));
            SGT_API_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", string_get_module("/STELLA", TRUE), 1)));
            SGT_API_TABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TABLE", string_get_module("/STELLA", TRUE), 1)));
          }
          if (current_startup_time_phaseP(4)) {
            oSELECTED_MODULESo = new_list();
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("LOGIC-DEFINITION", "OBJECT", "(DEFUN (LOGIC-DEFINITION STRING) ((OBJECT OBJECT)) :DOCUMENTATION \"Return the logic definition of `object'.\")");

              method->function_code = ((cpp_function_code)(&logic_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("SOURCE-DEFINITION", "OBJECT", "(DEFUN (SOURCE-DEFINITION STRING) ((OBJECT OBJECT)) :DOCUMENTATION \"Return the source definition of `object'.\")");

              method->function_code = ((cpp_function_code)(&source_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("OBJECT-NAME", "OBJECT", "(DEFUN (OBJECT-NAME STRING) ((OBJECT OBJECT)) :DOCUMENTATION \"Return the name of a stella object\")");

              method->function_code = ((cpp_function_code)(&object_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-CLASS", "STRING", "(DEFUN (FIND-CLASS CLASS) ((NAME STRING)) :DOCUMENTATION \"Retrieve the class with name `name'\")");

              method->function_code = ((cpp_function_code)(&find_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-CONTEXT", "STRING", "(DEFUN (FIND-CONTEXT CONTEXT) ((NAME STRING)) :DOCUMENTATION \"Retrieve the context with name `name'\")");

              method->function_code = ((cpp_function_code)(&find_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-INSTANCE", "STRING", "(DEFUN (FIND-INSTANCE LOGIC-OBJECT) ((NAME STRING)) :DOCUMENTATION \"Find the instance with name `name'\")");

              method->function_code = ((cpp_function_code)(&find_instance));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-INSTANCE", "STRING", "(DEFUN (GET-INSTANCE LOGIC-OBJECT) ((NAME STRING) (ERROR? BOOLEAN)) :DOCUMENTATION \"Find the instance with name `name'\")");

              method->function_code = ((cpp_function_code)(&get_instance));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-SUPERCLASSES", "CLASS", "(DEFUN (ALL-SUPERCLASSES (ITERATOR OF CLASS)) ((CLASS CLASS)) :DOCUMENTATION \"Get all superclasses (excluding `class') of `class'.\")");

              method->function_code = ((cpp_function_code)(&all_superclasses));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBCLASS?", "CLASS", "(DEFUN (SUBCLASS? BOOLEAN) ((CLASS1 CLASS) (CLASS2 CLASS)))");

              method->function_code = ((cpp_function_code)(&subclassP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DIRECT-SUPERCLASSES", "CLASS", "(DEFUN (DIRECT-SUPERCLASSES (ITERATOR OF CLASS)) ((CLASS CLASS)) :DOCUMENTATION \"Get direct superclasses of `class'.\")");

              method->function_code = ((cpp_function_code)(&direct_superclasses));
            }
            { Method_Slot* method = define_method_from_stringified_source("DIRECT-SUPERRELATIONS", "RELATION", "(DEFMETHOD (DIRECT-SUPERRELATIONS (ITERATOR OF RELATION)) ((SELF RELATION)) :DOCUMENTATION \"Return direct super classes/slots/tables of 'self'.\")");

              method->method_code = ((cpp_method_code)(&Relation::direct_superrelations));
            }
            { Method_Slot* method = define_method_from_stringified_source("DIRECT-SUPERRELATIONS", "SLOT", "(DEFMETHOD (DIRECT-SUPERRELATIONS (ITERATOR OF SLOT)) ((SELF SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::direct_superrelations));
            }
            { Method_Slot* method = define_method_from_stringified_source("DIRECT-SUPERRELATIONS", "CLASS", "(DEFMETHOD (DIRECT-SUPERRELATIONS (ITERATOR OF CLASS)) ((SELF CLASS)))");

              method->method_code = ((cpp_method_code)(&Class::direct_superrelations));
            }
            { Method_Slot* method = define_method_from_stringified_source("TEST1", "CONS", "(DEFUN (TEST1 CONS) ((PARENTS CONS)))");

              method->function_code = ((cpp_function_code)(&test1));
            }
            { Method_Slot* method = define_method_from_stringified_source("DIRECT-SUPERTYPES", "CLASS", "(DEFUN (DIRECT-SUPERTYPES (ITERATOR OF CLASS)) ((CLASS CLASS)) :DOCUMENTATION \"Get direct supertypes of `class'.\")");

              method->function_code = ((cpp_function_code)(&direct_supertypes));
            }
            { Method_Slot* method = define_method_from_stringified_source("DIRECT-SUBCLASSES", "CLASS", "(DEFUN (DIRECT-SUBCLASSES (ITERATOR OF CLASS)) ((CLASS CLASS)) :DOCUMENTATION \"Get direct subclasses of `class'.\")");

              method->function_code = ((cpp_function_code)(&direct_subclasses));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-NAMES", "CLASS", "(DEFUN (CLASS-NAMES (ALL-PURPOSE-ITERATOR OF SURROGATE)) ((CLASS CLASS)) :DOCUMENTATION \"Get all names (including synonyms) of `class'\")");

              method->function_code = ((cpp_function_code)(&class_names));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-INSTANCES", "CLASS", "(DEFUN (GET-INSTANCES CONS-ITERATOR) ((CLASS CLASS)) :DOCUMENTATION \"Return all instances asserted to be of type `class'\")");

              method->function_code = ((cpp_function_code)(&get_instances));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-SUBCLASSES", "CLASS", "(DEFUN (GET-SUBCLASSES (ITERATOR OF CLASS)) ((CLASS CLASS)) :DOCUMENTATION \"Get all subclasses of `class', including self.\")");

              method->function_code = ((cpp_function_code)(&get_subclasses));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-SUPERCLASS", "GENERALIZED-SYMBOL", "(DEFUN ADD-SUPERCLASS ((SUPER GENERALIZED-SYMBOL) (CLASS CLASS)) :DOCUMENTATION \"Add the class named 'super' to the list of\nsuperclasses of 'class'.\")");

              method->function_code = ((cpp_function_code)(&add_superclass));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-SUPERCLASS", "GENERALIZED-SYMBOL", "(DEFUN REMOVE-SUPERCLASS ((SUPER GENERALIZED-SYMBOL) (CLASS CLASS)) :DOCUMENTATION \"Remove the class named 'super' from the list of\nsuperclasses of 'class'.\")");

              method->function_code = ((cpp_function_code)(&remove_superclass));
            }
            { Method_Slot* method = define_method_from_stringified_source("DOMAIN", "SLOT", "(DEFUN (DOMAIN CLASS) ((SLOT SLOT)) :DOCUMENTATION \"Return the owner of `slot'\")");

              method->function_code = ((cpp_function_code)(&domain));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTED?", "SLOT", "(DEFUN (COMPUTED? BOOLEAN) ((SLOT SLOT)) :DOCUMENTATION \"Return TRUE if 'slot is computed by a STELLA method or\nfunction.\")");

              method->function_code = ((cpp_function_code)(&computedP));
            }
            { Method_Slot* method = define_method_from_stringified_source("RANGE", "SLOT", "(DEFUN (RANGE CLASS) ((SLOT SLOT)) :DOCUMENTATION \"Return the type of `slot'\")");

              method->function_code = ((cpp_function_code)(&range));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-ONLY?", "STORAGE-SLOT", "(DEFUN (READ-ONLY? BOOLEAN) ((SLOT STORAGE-SLOT)) :DOCUMENTATION \"Return TRUE if `slot' is readonly\")");

              method->function_code = ((cpp_function_code)(&read_onlyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOT?", "OBJECT", "(DEFUN (SLOT? BOOLEAN) ((OBJECT OBJECT)) :DOCUMENTATION \"Return TRUE if `object' is a slot\")");

              method->function_code = ((cpp_function_code)(&slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ASSERTED-INSTANCE-OF-CLASS?", "LOGIC-OBJECT", "(DEFUN (ASSERTED-INSTANCE-OF-CLASS? BOOLEAN) ((INSTANCE LOGIC-OBJECT) (CLASS CLASS)) :DOCUMENTATION \"Return TRUE if `instance' has been asserted to be\n                  of type `class'\")");

              method->function_code = ((cpp_function_code)(&asserted_instance_of_classP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONSTANT?", "OBJECT", "(DEFUN (CONSTANT? BOOLEAN) ((OBJECT OBJECT)) :DOCUMENTATION \"Return TRUE if `object' is a literal or symbol\")");

              method->function_code = ((cpp_function_code)(&constantP));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-TYPES", "LOGIC-OBJECT", "(DEFUN (GET-TYPES ALL-PURPOSE-ITERATOR) ((INSTANCE LOGIC-OBJECT)) :DOCUMENTATION \"Return all classes `instance' belongs to\")");

              method->function_code = ((cpp_function_code)(&get_types));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-VALUE", "LOGIC-OBJECT", "(DEFUN (GET-VALUE OBJECT) ((INSTANCE LOGIC-OBJECT) (SLOT SLOT)) :DOCUMENTATION \"Get the value of 'slot' on `instance'\")");

              method->function_code = ((cpp_function_code)(&get_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("LIST-SLOT-NAMES-AND-VALUES", "LOGIC-OBJECT", "(DEFUN (LIST-SLOT-NAMES-AND-VALUES SLOT-VALUE-ITERATOR) ((INSTANCE LOGIC-OBJECT)) :DOCUMENTATION \"Return all slots and associated values asserted for\n`instance'\")");

              method->function_code = ((cpp_function_code)(&list_slot_names_and_values));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTEXT", "OBJECT", "(DEFUN (CONTEXT CONTEXT) ((OBJECT OBJECT)) :DOCUMENTATION \"Return context (if any) of `object'\")");

              method->function_code = ((cpp_function_code)(&context));
            }
            { Method_Slot* method = define_method_from_stringified_source("LIST-MODULE", "MODULE", "(DEFUN (LIST-MODULE ALL-PURPOSE-ITERATOR) ((MODULE MODULE)) :DOCUMENTATION \"Return all classes and instances in `module'\")");

              method->function_code = ((cpp_function_code)(&list_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTEXT-PARENTS", "MODULE", "(DEFUN (CONTEXT-PARENTS ITERATOR) ((MODULE MODULE)) :DOCUMENTATION \"Return the parent contexts of `module'.\")");

              method->function_code = ((cpp_function_code)(&context_parents));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTEXT-CHILDREN", "MODULE", "(DEFUN (CONTEXT-CHILDREN ITERATOR) ((MODULE MODULE)) :DOCUMENTATION \"Return the child contexts of `module'.\")");

              method->function_code = ((cpp_function_code)(&context_children));
            }
            { Method_Slot* method = define_method_from_stringified_source("ITERATOR-KEY", "DICTIONARY-ITERATOR", "(DEFUN (ITERATOR-KEY OBJECT) ((SELF DICTIONARY-ITERATOR)) :DOCUMENTATION \"Return the current key of `self'\")");

              method->function_code = ((cpp_function_code)(&iterator_key));
            }
            { Method_Slot* method = define_method_from_stringified_source("ITERATOR-VALUE", "ITERATOR", "(DEFUN (ITERATOR-VALUE OBJECT) ((SELF ITERATOR)) :DOCUMENTATION \"Return the current value of `self'\")");

              method->function_code = ((cpp_function_code)(&iterator_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("SELECT-MODULE", "MODULE", "(DEFUN SELECT-MODULE ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Add 'module' to the list of selected modules.  \nIf 'local?' is FALSE also select all modules visible from 'module'.\")");

              method->function_code = ((cpp_function_code)(&select_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESELECT-MODULE", "MODULE", "(DEFUN DESELECT-MODULE ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Remove 'module' from the list of selected modules.  \nIf 'local?' is FALSE also deselect all modules visible from 'module'.\")");

              method->function_code = ((cpp_function_code)(&deselect_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("SELECT-ALL-MODULES", NULL, "(DEFUN SELECT-ALL-MODULES () :DOCUMENTATION \"Select all modules.\")");

              method->function_code = ((cpp_function_code)(&select_all_modules));
            }
            { Method_Slot* method = define_method_from_stringified_source("VISIBLE-OBJECT?", "OBJECT", "(DEFUN (VISIBLE-OBJECT? BOOLEAN) ((OBJECT OBJECT)) :DOCUMENTATION \"Return TRUE if 'object' is visible with respect to the\nset of currently selected modules.\")");

              method->function_code = ((cpp_function_code)(&visible_objectP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOT-COLUMN-TYPES", "SLOT", "(DEFUN (SLOT-COLUMN-TYPES (ITERATOR OF TYPE)) ((SELF SLOT)))");

              method->function_code = ((cpp_function_code)(&slot_column_types));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOT-COLUMN-TYPES-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (SLOT-COLUMN-TYPES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&slot_column_types_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOT-COLUMN-TYPES-EMPTY?", "ALL-PURPOSE-ITERATOR", "(DEFUN (SLOT-COLUMN-TYPES-EMPTY? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&slot_column_types_emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSTANCE-P", "OBJECT", "(DEFUN (INSTANCE-P BOOLEAN) ((OBJECT OBJECT)) :DOCUMENTATION \"Return TRUE if `object' is an instance\")");

              method->function_code = ((cpp_function_code)(&instance_p));
            }
            define_method_from_stringified_source("STARTUP-API", NULL, "(DEFUN STARTUP-API ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *SELECTED-MODULES* (LIST OF MODULE) (NEW LIST) :DOCUMENTATION \"API functions filter out any objects whose home-context is\nnot mentioned in this list.  If it is NULL or an empty list all modules \nwill be considered.\")");
            { Global_Variable* global = SYM_API_oSELECTED_MODULESo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Oselected_modulesO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Oselected_modulesO));
            }
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

