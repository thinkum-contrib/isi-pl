// defclass.cc

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

Keyword* oTRANSLATOR_OUTPUT_LANGUAGEo = NULL;

Keyword* KWD_DEFCLASS_COMMON_LISP = NULL;

Surrogate* SGT_DEFCLASS_LITERAL = NULL;

Symbol* SYM_DEFCLASS_NULL = NULL;

Symbol* SYM_DEFCLASS_DEFINE_CLASS_FROM_STRINGIFIED_SOURCE = NULL;

Symbol* SYM_DEFCLASS_CLASS_CL_NATIVE_TYPE = NULL;

Keyword* KWD_DEFCLASS_IDL = NULL;

Symbol* SYM_DEFCLASS_CLASS_IDL_NATIVE_TYPE = NULL;

Keyword* KWD_DEFCLASS_JAVA = NULL;

Symbol* SYM_DEFCLASS_CLASS_JAVA_NATIVE_TYPE = NULL;

Keyword* KWD_DEFCLASS_CPP = NULL;

Keyword* KWD_DEFCLASS_CPP_STANDALONE = NULL;

Symbol* SYM_DEFCLASS_CLASS_CPP_NATIVE_TYPE = NULL;

Surrogate* SGT_DEFCLASS_SECOND_CLASS_OBJECT = NULL;

Surrogate* SGT_DEFCLASS_NON_OBJECT = NULL;

Keyword* KWD_DEFCLASS_DYNAMIC = NULL;

Symbol* SYM_DEFCLASS_SLOT_INITIAL_VALUE = NULL;

Keyword* KWD_DEFCLASS_BIT = NULL;

Surrogate* SGT_DEFCLASS_BOOLEAN = NULL;

Symbol* SYM_DEFCLASS_SLOT_RENAMES = NULL;

Surrogate* SGT_DEFCLASS_UNKNOWN = NULL;

Symbol* SYM_DEFCLASS_NEXT_SWEEP_LIST_OBJECT = NULL;

Symbol* SYM_DEFCLASS_CLASS_CREATOR = NULL;

Symbol* SYM_DEFCLASS_DEFGLOBAL = NULL;

Symbol* SYM_DEFCLASS_LIST = NULL;

Symbol* SYM_DEFCLASS_OF = NULL;

Symbol* SYM_DEFCLASS_STARTUP_TIME_PROGN = NULL;

Keyword* KWD_DEFCLASS_EARLY_INITS = NULL;

Symbol* SYM_DEFCLASS_SETQ = NULL;

Symbol* SYM_DEFCLASS_MAKE_NON_RECYCLED_LIST = NULL;

Symbol* SYM_DEFCLASS_SELF = NULL;

Symbol* SYM_DEFCLASS_MAKE = NULL;

Symbol* SYM_DEFCLASS_WHEN = NULL;

Symbol* SYM_DEFCLASS_DEFINEDp = NULL;

Symbol* SYM_DEFCLASS_FREE = NULL;

Symbol* SYM_DEFCLASS_DYNAMIC_SLOTS = NULL;

Symbol* SYM_DEFCLASS_CLEAR = NULL;

Symbol* SYM_DEFCLASS_UNLESS = NULL;

Symbol* SYM_DEFCLASS_RETURN = NULL;

Symbol* SYM_DEFCLASS_SLOT_VALUE = NULL;

Symbol* SYM_DEFCLASS_SAFE_CAST = NULL;

Symbol* SYM_DEFCLASS_POP = NULL;

Symbol* SYM_DEFCLASS_COND = NULL;

Symbol* SYM_DEFCLASS_OTHERWISE = NULL;

Symbol* SYM_DEFCLASS_SETF = NULL;

Keyword* KWD_DEFCLASS_CONTEXT_SENSITIVEp = NULL;

Symbol* SYM_DEFCLASS_FALSE = NULL;

Symbol* SYM_DEFCLASS_RUN_CONSTRUCTOR_DEMONS = NULL;

Symbol* SYM_DEFCLASS_DEFUN = NULL;

Symbol* SYM_DEFCLASS_LET = NULL;

Symbol* SYM_DEFCLASS_CLASS_DESTRUCTOR = NULL;

Symbol* SYM_DEFCLASS_DEFMETHOD = NULL;

Symbol* SYM_DEFCLASS_PUSH = NULL;

Symbol* SYM_DEFCLASS_SWEEP = NULL;

Symbol* SYM_DEFCLASS_UNMAKE = NULL;

Surrogate* SGT_DEFCLASS_VOID = NULL;

Symbol* SYM_DEFCLASS_SLOT_TYPE_SPECIFIER = NULL;

Symbol* SYM_DEFCLASS_ANSWER = NULL;

Symbol* SYM_DEFCLASS_IF = NULL;

Symbol* SYM_DEFCLASS_NULLp = NULL;

Symbol* SYM_DEFCLASS_PROGN = NULL;

Symbol* SYM_DEFCLASS_ERROR = NULL;

Keyword* KWD_DEFCLASS_AUXILIARYp = NULL;

Symbol* SYM_DEFCLASS_TRUE = NULL;

Symbol* SYM_DEFCLASS_VALUE = NULL;

Symbol* SYM_DEFCLASS_IGNORE = NULL;

Surrogate* SGT_DEFCLASS_OBJECT = NULL;

Keyword* KWD_DEFCLASS_WRAP_FUNCTION = NULL;

Symbol* SYM_DEFCLASS_CAST = NULL;

Symbol* SYM_DEFCLASS_SETVALUEp = NULL;

Surrogate* SGT_DEFCLASS_DYNAMIC_SLOTS_MIXIN = NULL;

Symbol* SYM_DEFCLASS_SLOTNAME = NULL;

Symbol* SYM_DEFCLASS_QUOTE = NULL;

Symbol* SYM_DEFCLASS_CASE = NULL;

Symbol* SYM_DEFCLASS_HELP_SET_DYNAMIC_SLOT_VALUE = NULL;

Symbol* SYM_DEFCLASS_LOOKUP = NULL;

Symbol* SYM_DEFCLASS_OBJECT = NULL;

Symbol* SYM_DEFCLASS_SYMBOL = NULL;

Symbol* SYM_DEFCLASS_BOOLEAN = NULL;

Symbol* SYM_DEFCLASS_CLASS_SLOT_ACCESSOR_CODE = NULL;

Symbol* SYM_DEFCLASS_THE_CODE = NULL;

Keyword* KWD_DEFCLASS_FUNCTION = NULL;

Symbol* SYM_DEFCLASS_TYPECASE = NULL;

Symbol* SYM_DEFCLASS_EQp = NULL;

Symbol* SYM_DEFCLASS_OTHER = NULL;

Symbol* SYM_DEFCLASS_EQUAL = NULL;

Symbol* SYM_DEFCLASS_AND = NULL;

Surrogate* SGT_DEFCLASS_TRANSIENT_MIXIN = NULL;

Object* type_to_null_value_tree(Surrogate* type) {
  { Class* renamed_Class = type_to_class(type);

    if ((renamed_Class != NULL) &&
        subtype_ofP(type, SGT_DEFCLASS_LITERAL)) {
      { Object* nullvalue = renamed_Class->initial_value();

        if (nullvalue != NULL) {
          return (transientify_form(nullvalue));
        }
      }
    }
    return (SYM_DEFCLASS_NULL);
  }
}

Cons* yield_cons_list_from_sequence(Sequence* sequence) {
  { Cons* list = NIL;

    { Object* item = NULL;
      Iterator* iter_001 = ((Iterator*)(sequence->allocate_iterator()));
      Cons* collect_001 = NULL;

      while (iter_001->nextP()) {
        {
          item = iter_001->value;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(item, NIL);
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
            collect_001->rest = cons(item, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    return (list);
  }
}

Cons* yield_define_stella_class(Class* renamed_Class) {
  // Return a cons tree that (when evaluated) constructs
  // a Stella class object.
  return (listO(3, SYM_DEFCLASS_DEFINE_CLASS_FROM_STRINGIFIED_SOURCE, string_wrap_literal(renamed_Class->name()), cons(yield_string_constant_tree(renamed_Class->class_stringified_source), NIL)));
}

boolean create_native_classP(Class* renamed_Class) {
  { char* classnativetype = NULL;

    if (oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_DEFCLASS_COMMON_LISP) {
      classnativetype = ((String_Wrapper*)(dynamic_slot_value(renamed_Class, SYM_DEFCLASS_CLASS_CL_NATIVE_TYPE, NULL_STRING_WRAPPER)))->wrapper_value;
    }
    else if (oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_DEFCLASS_IDL) {
      classnativetype = ((String_Wrapper*)(dynamic_slot_value(renamed_Class, SYM_DEFCLASS_CLASS_IDL_NATIVE_TYPE, NULL_STRING_WRAPPER)))->wrapper_value;
    }
    else if (oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_DEFCLASS_JAVA) {
      classnativetype = ((String_Wrapper*)(dynamic_slot_value(renamed_Class, SYM_DEFCLASS_CLASS_JAVA_NATIVE_TYPE, NULL_STRING_WRAPPER)))->wrapper_value;
    }
    else if ((oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_DEFCLASS_CPP) ||
        (oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_DEFCLASS_CPP_STANDALONE)) {
      classnativetype = ((String_Wrapper*)(dynamic_slot_value(renamed_Class, SYM_DEFCLASS_CLASS_CPP_NATIVE_TYPE, NULL_STRING_WRAPPER)))->wrapper_value;
    }
    else {
      cerr << "`" << oTRANSLATOR_OUTPUT_LANGUAGEo << "'" << " is not a valid case option";
    }
    return (!(subtype_ofP(renamed_Class->class_type, SGT_DEFCLASS_SECOND_CLASS_OBJECT) ||
        (subtype_ofP(renamed_Class->class_type, SGT_DEFCLASS_NON_OBJECT) ||
         ((classnativetype != NULL) ||
          (!renamed_Class->primitiveP())))));
  }
}

void warn_about_multiple_parents(Class* renamed_Class) {
  if (renamed_Class->multiple_parentsP() &&
      create_native_classP(renamed_Class)) {
    if ((oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_DEFCLASS_CPP_STANDALONE) ||
        (oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_DEFCLASS_IDL)) {
    }
    else if ((oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_DEFCLASS_COMMON_LISP) ||
        ((oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_DEFCLASS_CPP) ||
         (oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_DEFCLASS_JAVA))) {
      { int nofsupers = 0;
        int nofmixinsupers = 0;

        { Surrogate* super = NULL;
          Iterator* iter_001 = class_native_supers(renamed_Class);

          while (iter_001->nextP()) {
            {
              super = ((Surrogate*)(iter_001->value));
            }
            nofsupers = nofsupers + 1;
            if (((Class*)(super->surrogate_value))->mixinP) {
              nofmixinsupers = nofmixinsupers + 1;
            }
          }
        }
        if ((nofsupers - nofmixinsupers) > 1) {
          { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  signal_translation_error();
                  if (!(suppress_warningsP())) {
                    print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                    cout << endl << " " << "Class " << "`" << class_name(renamed_Class) << "'" << " illegally inherits " << "`" << (nofsupers - nofmixinsupers) << "'" << " native non-mixin classes" << "." << endl;
                  }
                  oPRINTREADABLYpo = old_OprintreadablyPO_001;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
                resignal();
              }
            }
          }
        }
      }
    }
    else {
      cerr << "`" << oTRANSLATOR_OUTPUT_LANGUAGEo << "'" << " is not a valid case option";
    }
  }
}

void warn_about_non_direct_supers(Class* renamed_Class) {
  if (renamed_Class->multiple_parentsP() &&
      create_native_classP(renamed_Class)) {
    { List* directsupers = renamed_Class->class_direct_supers;

      { Surrogate* super = NULL;
        Cons* iter_001 = directsupers->the_cons_list;

        while (!nilP(iter_001)) {
          {
            super = ((Surrogate*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          { boolean foundP_001 = FALSE;

            { Surrogate* othersuper = NULL;
              Cons* iter_002 = directsupers->the_cons_list;

              while (!nilP(iter_002)) {
                {
                  othersuper = ((Surrogate*)(iter_002->value));
                  iter_002 = iter_002->rest;
                }
                if ((!(super == othersuper)) &&
                    subtype_ofP(othersuper, super)) {
                  foundP_001 = TRUE;
                  break;
                }
              }
            }
            if (foundP_001) {
              { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_error();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Bad list of supers defined for class " << "`" << class_name(renamed_Class) << "'" << "." << endl << " The class " << "`" << super->symbol_name << "'" << " is not a direct superclass" << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    resignal();
                  }
                }
              }
              return;
            }
          }
        }
      }
    }
  }
}

boolean space_saver_slot_allocationP(Storage_Slot* slot) {
  if (slot->allocation() == KWD_DEFCLASS_DYNAMIC) {
    if (dynamic_slot_value(slot, SYM_DEFCLASS_SLOT_INITIAL_VALUE, NULL) != NULL) {
      cerr << "Dynamic slot " << "`" << slot->slot_name << "'" << " should not have an" << endl << "   initial value (or it shouldn't be dynamic).";
    }
    return (TRUE);
  }
  else if ((slot->allocation() == KWD_DEFCLASS_BIT) ||
      ((slot->type() == SGT_DEFCLASS_BOOLEAN) &&
       (slot->slot_allocation_reader() == NULL))) {
    return (TRUE);
  }
  else {
    return (FALSE);
  }
}

boolean redundant_slotP(Storage_Slot* slot) {
  { Slot* equivslot = slot->slot_direct_equivalent;

    return ((equivslot != NULL) &&
        (dynamic_slot_value(slot, SYM_DEFCLASS_SLOT_RENAMES, NULL) == equivslot->slot_name));
  }
}

boolean native_slotP(Storage_Slot* slot) {
  return ((!slot->abstractP) &&
      ((!slot->slot_hardwiredP) &&
       ((!space_saver_slot_allocationP(slot)) &&
        (!redundant_slotP(slot)))));
}

Storage_Slot* canonical_slot(Storage_Slot* slot) {
  { Storage_Slot* canonicalslot = slot;

    while ((canonicalslot->slot_direct_equivalent != NULL) &&
        (canonicalslot->slot_direct_equivalent->slot_name == dynamic_slot_value(canonicalslot, SYM_DEFCLASS_SLOT_RENAMES, NULL))) {
      canonicalslot = ((Storage_Slot*)(canonicalslot->slot_direct_equivalent));
    }
    return (canonicalslot);
  }
}

boolean unknown_typeP(Surrogate* type) {
  return ((type == SGT_DEFCLASS_UNKNOWN) ||
      ((type_to_class(type) == NULL) ||
       ((type_to_class(type) == type_to_class(SGT_DEFCLASS_UNKNOWN)) ||
        (subtype_ofP(type, SGT_DEFCLASS_NON_OBJECT) &&
         type_to_class(type)->abstractP))));
}

boolean slot_has_unknown_typeP(Storage_Slot* slot, Class* renamed_Class) {
  return (unknown_typeP(type_spec_to_base_type(slot->compute_return_type_spec(renamed_Class->class_type))));
}

Class* native_slot_home(Storage_Slot* slot, Class* renamed_Class) {
  { Storage_Slot* slotwithknowntype = NULL;

    for (;;) {
      if (unknown_typeP(slot->type())) {
        break;
      }
      slotwithknowntype = slot;
      renamed_Class = type_to_class(slot->slot_owner);
      if ((slot->slot_direct_equivalent != NULL) &&
          native_slotP(((Storage_Slot*)(slot->slot_direct_equivalent)))) {
        slot = ((Storage_Slot*)(slot->slot_direct_equivalent));
      }
      else {
        break;
      }
    }
    if (slotwithknowntype != NULL) {
      return (renamed_Class);
    }
    if (slot_has_unknown_typeP(slot, renamed_Class)) {
      return (NULL);
    }
    { Class* super = NULL;
      Cons* iter_001 = renamed_Class->class_all_super_classes;

      while (!nilP(iter_001)) {
        {
          super = ((Class*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (slot_has_unknown_typeP(slot, super)) {
          return (renamed_Class);
        }
        else {
          renamed_Class = super;
        }
      }
    }
    return (renamed_Class);
  }
}

Class* mixin_slot_home(Storage_Slot* slot, Class* renamed_Class) {
  { Class* nativeslothome = native_slot_home(slot, renamed_Class);
    Class* candidate = renamed_Class;

    if (!((nativeslothome != NULL) &&
        (nativeslothome->mixinP &&
         translate_to_single_inheritance_languageP()))) {
      return (nativeslothome);
    }
    if (candidate->mixinP) {
      return (NULL);
    }
    { Class* superclass = NULL;
      Cons* iter_001 = renamed_Class->class_all_super_classes;

      while (!nilP(iter_001)) {
        {
          superclass = ((Class*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if ((!superclass->mixinP) &&
            superclass->class_all_super_classes->memberP(nativeslothome)) {
          candidate = superclass;
        }
      }
    }
    return (candidate);
  }
}

void Object::sweep() {
  // Default method.  Sweep up all 'self'-type objects.
  { Object* self = this;

  }
}

void sweep_transients() {
  new_transient_integer_wrapper(NULL_INTEGER)->sweep();
  new_transient_float_wrapper(NULL_FLOAT)->sweep();
  new_transient_string_wrapper(NULL)->sweep();
  new_verbatim_string_wrapper(NULL)->sweep();
  new_transient_character_wrapper(NULL_CHARACTER)->sweep();
  new_transient_function_code_wrapper(NULL)->sweep();
  new_transient_method_code_wrapper(((cpp_method_code)(NULL)))->sweep();
  new_transient_cons()->sweep();
  new_transient_type_specifier()->sweep();
}

Symbol* yield_recycle_list_name(Class* renamed_Class) {
  return (intern_derived_symbol(renamed_Class->class_type, string_concatenate("*RECYCLED-", string_concatenate(class_name(renamed_Class), "-S*"))));
}

Symbol* yield_sweep_list_name(Class* renamed_Class) {
  return (intern_derived_symbol(renamed_Class->class_type, string_concatenate("*ALL-", string_concatenate(class_name(renamed_Class), "-S*"))));
}

Symbol* yield_sweep_list_pointer_name(Class* renamed_Class) {
  return (intern_derived_symbol(renamed_Class->class_type, string_concatenate("*UNUSED-", string_concatenate(class_name(renamed_Class), "-S*"))));
}

Storage_Slot* recycle_slot(Class* renamed_Class) {
  { Surrogate* instancetype = renamed_Class->class_type;
    Storage_Slot* recycleslot = NULL;

    { Slot* slot = NULL;
      Iterator* iter_001 = renamed_Class->class_slots();

      while (iter_001->nextP()) {
        {
          slot = ((Slot*)(iter_001->value));
        }
        { Slot* slot_001 = slot;

          if (storage_slotP(slot)) {
            { Storage_Slot* slot = NULL;

              slot = ((Storage_Slot*)(slot_001));
              if ((!(slot->slot_name == SYM_DEFCLASS_NEXT_SWEEP_LIST_OBJECT)) &&
                  native_slotP(slot)) {
                if (instancetype == slot->slot_base_type) {
                  return (slot);
                }
                if ((((Class*)(slot->slot_base_type->surrogate_value)) != NULL) &&
                    subtype_ofP(instancetype, slot->slot_base_type)) {
                  recycleslot = slot;
                }
              }
            }
          }
          else {
          }
        }
      }
    }
    return (recycleslot);
  }
}

boolean use_free_listP(Class* renamed_Class) {
  return (get_quoted_tree("((:FREE-LIST :FREE-AND-SWEEP-LIST) \"/STELLA\")", "/STELLA")->memberP(renamed_Class->class_recycle_method_reader()));
}

boolean use_sweep_listP(Class* renamed_Class) {
  return (get_quoted_tree("((:SWEEP-LIST :FREE-AND-SWEEP-LIST) \"/STELLA\")", "/STELLA")->memberP(renamed_Class->class_recycle_method_reader()));
}

boolean decided_to_recycleP(Class* renamed_Class) {
  return ((!(renamed_Class->abstractP ||
      (((Symbol*)(dynamic_slot_value(renamed_Class, SYM_DEFCLASS_CLASS_CREATOR, NULL))) != NULL))) &&
      (use_free_listP(renamed_Class) ||
       use_sweep_listP(renamed_Class)));
}

List* make_non_recycled_list() {
  { List* list = new List;

    list->the_cons_list = NIL;
    return (list);
  }
}

Cons* yield_recycle_list_definitions(Class* renamed_Class) {
  { Cons* definitions = NIL;
    Symbol* recyclelistname = NULL;

    if (use_free_listP(renamed_Class)) {
      recyclelistname = yield_recycle_list_name(renamed_Class);
      if (recycle_slot(renamed_Class) != NULL) {
        definitions = cons(listO(3, SYM_DEFCLASS_DEFGLOBAL, recyclelistname, cons(class_symbol(renamed_Class), cons(SYM_DEFCLASS_NULL, NIL))), definitions);
      }
      else {
        definitions = cons(listO(3, SYM_DEFCLASS_DEFGLOBAL, recyclelistname, listO(3, listO(4, SYM_DEFCLASS_LIST, SYM_DEFCLASS_OF, class_symbol(renamed_Class), NIL), SYM_DEFCLASS_NULL, NIL)), definitions);
        definitions = cons(listO(4, SYM_DEFCLASS_STARTUP_TIME_PROGN, KWD_DEFCLASS_EARLY_INITS, listO(3, SYM_DEFCLASS_SETQ, recyclelistname, cons(cons(SYM_DEFCLASS_MAKE_NON_RECYCLED_LIST, NIL), NIL)), NIL), definitions);
      }
    }
    if (use_sweep_listP(renamed_Class)) {
      definitions = cons(listO(3, SYM_DEFCLASS_DEFGLOBAL, yield_sweep_list_name(renamed_Class), cons(class_symbol(renamed_Class), cons(SYM_DEFCLASS_NULL, NIL))), definitions);
      definitions = cons(listO(3, SYM_DEFCLASS_DEFGLOBAL, yield_sweep_list_pointer_name(renamed_Class), cons(class_symbol(renamed_Class), cons(SYM_DEFCLASS_NULL, NIL))), definitions);
    }
    return (definitions->reverse());
  }
}

Cons* yield_make_trees(Class* renamed_Class) {
  return (cons(listO(4, SYM_DEFCLASS_SETQ, SYM_DEFCLASS_SELF, listO(3, SYM_DEFCLASS_MAKE, class_symbol(renamed_Class), NIL), NIL), NIL));
}

Symbol* yield_constructor_name(Class* renamed_Class) {
  return (intern_derived_symbol(renamed_Class->class_type, string_concatenate("NEW-", class_name(renamed_Class))));
}

Cons* yield_creation_trees(Class* renamed_Class) {
  if (((Symbol*)(dynamic_slot_value(renamed_Class, SYM_DEFCLASS_CLASS_CREATOR, NULL))) != NULL) {
    if (dynamic_slot_value(renamed_Class, SYM_DEFCLASS_CLASS_CREATOR, NULL) == yield_constructor_name(renamed_Class)) {
      cerr << "Illegal creator name " << "`" << ((Symbol*)(dynamic_slot_value(renamed_Class, SYM_DEFCLASS_CLASS_CREATOR, NULL))) << "'" << " for the class " << endl << "`" << class_name(renamed_Class) << "'" << ".  Using the default creator.";
      return (yield_make_trees(renamed_Class));
    }
    return (cons(listO(4, SYM_DEFCLASS_SETQ, SYM_DEFCLASS_SELF, cons(((Symbol*)(dynamic_slot_value(renamed_Class, SYM_DEFCLASS_CLASS_CREATOR, NULL))), NIL), NIL), NIL));
  }
  else if (decided_to_recycleP(renamed_Class)) {
    return (yield_creation_or_reuse_trees(renamed_Class));
  }
  else {
    return (yield_make_trees(renamed_Class));
  }
}

Cons* yield_terminate_object_trees(Class* renamed_Class) {
  { Cons* trees = NIL;
    Symbol* terminator = renamed_Class->terminator();

    { Slot* slot = NULL;
      Iterator* iter_001 = renamed_Class->class_slots();

      while (iter_001->nextP()) {
        {
          slot = ((Slot*)(iter_001->value));
        }
        { Slot* slot_001 = slot;

          if (storage_slotP(slot)) {
            { Storage_Slot* slot = NULL;

              slot = ((Storage_Slot*)(slot_001));
              if (slot->componentP()) {
                trees = cons(listO(4, SYM_DEFCLASS_WHEN, listO(3, SYM_DEFCLASS_DEFINEDp, cons(slot->slot_name, cons(SYM_DEFCLASS_SELF, NIL)), NIL), listO(3, SYM_DEFCLASS_FREE, cons(slot->slot_name, cons(SYM_DEFCLASS_SELF, NIL)), NIL), NIL), trees);
              }
            }
          }
          else {
          }
        }
      }
    }
    if (lookup_slot(renamed_Class, SYM_DEFCLASS_DYNAMIC_SLOTS) != NULL) {
      trees = cons(listO(3, SYM_DEFCLASS_CLEAR, listO(3, SYM_DEFCLASS_DYNAMIC_SLOTS, SYM_DEFCLASS_SELF, NIL), NIL), trees);
    }
    if (terminator != NULL) {
      if (use_sweep_listP(renamed_Class)) {
        trees = cons(cons(terminator, cons(SYM_DEFCLASS_SELF, NIL)), trees);
      }
      else {
        trees = cons(listO(4, SYM_DEFCLASS_UNLESS, cons(terminator, cons(SYM_DEFCLASS_SELF, NIL)), cons(SYM_DEFCLASS_RETURN, NIL), NIL), trees);
      }
    }
    return (trees->reverse());
  }
}

Cons* yield_creation_or_reuse_trees(Class* renamed_Class) {
  { Storage_Slot* recycleslot = recycle_slot(renamed_Class);
    Symbol* recycleslotname = NULL;
    boolean usefreelistP = use_free_listP(renamed_Class);
    boolean usesweeplistP = use_sweep_listP(renamed_Class);
    Symbol* recyclelist = NULL;
    Symbol* sweeplist = NULL;
    Symbol* sweeplistpointer = NULL;
    Object* recyclelistpoptree = NULL;
    Cons* recyclelistbumptree = NULL;
    Cons* sweeplistbumptree = NULL;

    if (usefreelistP) {
      recyclelist = yield_recycle_list_name(renamed_Class);
      if (recycleslot != NULL) {
        recycleslotname = recycleslot->slot_name;
        recyclelistpoptree = recyclelist;
        recyclelistbumptree = ((recycleslot->slot_base_type == renamed_Class->class_type) ? ((Cons*)(cons(listO(3, SYM_DEFCLASS_SETQ, recyclelist, cons(listO(4, SYM_DEFCLASS_SLOT_VALUE, SYM_DEFCLASS_SELF, recycleslotname, NIL), NIL)), NIL))) : ((Cons*)(cons(listO(3, SYM_DEFCLASS_SETQ, recyclelist, cons(listO(4, SYM_DEFCLASS_SAFE_CAST, listO(4, SYM_DEFCLASS_SLOT_VALUE, SYM_DEFCLASS_SELF, recycleslotname, NIL), class_symbol(renamed_Class), NIL), NIL)), NIL))));
      }
      else {
        recyclelistbumptree = NIL;
        recyclelistpoptree = listO(3, SYM_DEFCLASS_POP, recyclelist, NIL);
      }
    }
    if (usesweeplistP) {
      sweeplist = yield_sweep_list_name(renamed_Class);
      sweeplistpointer = yield_sweep_list_pointer_name(renamed_Class);
      sweeplistbumptree = cons(listO(3, SYM_DEFCLASS_SETQ, sweeplistpointer, cons(listO(3, SYM_DEFCLASS_NEXT_SWEEP_LIST_OBJECT, sweeplistpointer, NIL), NIL)), yield_terminate_object_trees(renamed_Class)->concatenate(NIL));
    }
    return (listO(3, listO(4, SYM_DEFCLASS_SETQ, SYM_DEFCLASS_SELF, (usefreelistP ? ((Object*)(recyclelistpoptree)) : ((Object*)(sweeplistpointer))), NIL), listO(3, SYM_DEFCLASS_COND, cons(listO(3, SYM_DEFCLASS_DEFINEDp, SYM_DEFCLASS_SELF, NIL), (usefreelistP ? ((Cons*)(recyclelistbumptree)) : ((Cons*)(sweeplistbumptree)))->concatenate(NIL)), ((usefreelistP &&
        usesweeplistP) ? ((Cons*)(cons(listO(3, listO(3, SYM_DEFCLASS_DEFINEDp, sweeplistpointer, NIL), listO(4, SYM_DEFCLASS_SETQ, SYM_DEFCLASS_SELF, sweeplistpointer, NIL), sweeplistbumptree->concatenate(NIL)), NIL))) : ((Cons*)(NIL)))->concatenate(cons(cons(SYM_DEFCLASS_OTHERWISE, yield_make_trees(renamed_Class)->concatenate((usesweeplistP ? ((Cons*)(listO(3, listO(4, SYM_DEFCLASS_SETF, listO(3, SYM_DEFCLASS_NEXT_SWEEP_LIST_OBJECT, SYM_DEFCLASS_SELF, NIL), sweeplist, NIL), listO(3, SYM_DEFCLASS_SETQ, sweeplist, cons(SYM_DEFCLASS_SELF, NIL)), NIL))) : ((Cons*)(NIL)))->concatenate(NIL))), NIL))), NIL));
  }
}

void mark_direct_equivalent_slot(Slot* slot) {
  { Slot* directequivalent = slot->slot_direct_equivalent;

    if (directequivalent != NULL) {
      if (directequivalent->slot_markedP) {
        slot->slot_markedP = TRUE;
      }
      else {
        directequivalent->slot_markedP = TRUE;
      }
    }
  }
}

boolean is_context_sensitive_slotP(Storage_Slot* slot) {
  return (slot->slot_context_sensitiveP ||
      ((slot->slot_direct_equivalent != NULL) &&
       is_context_sensitive_slotP(((Storage_Slot*)(slot->slot_direct_equivalent)))));
}

Cons* yield_initial_value_assignment(Storage_Slot* slot) {
  { Object* initialvalueexpression = yield_initial_value_expression(slot);

    if ((initialvalueexpression != NULL) &&
        ((!slot->requiredP()) &&
         (!(slot->slot_name == SYM_DEFCLASS_NEXT_SWEEP_LIST_OBJECT)))) {
      return (listO(4, SYM_DEFCLASS_SETF, listO(4, SYM_DEFCLASS_SLOT_VALUE, SYM_DEFCLASS_SELF, canonical_slot(slot)->slot_name, (is_context_sensitive_slotP(slot) ? ((Cons*)(listO(3, KWD_DEFCLASS_CONTEXT_SENSITIVEp, SYM_DEFCLASS_FALSE, NIL))) : ((Cons*)(NIL)))->concatenate(NIL)), initialvalueexpression, NIL));
    }
    else {
      return (NULL);
    }
  }
}

Cons* yield_initial_value_assignments(Class* renamed_Class) {
  { Cons* assignments = NIL;
    Object* initialvalueassignment = NULL;

    { Slot* slot = NULL;
      Iterator* iter_001 = renamed_Class->class_slots();

      while (iter_001->nextP()) {
        {
          slot = ((Slot*)(iter_001->value));
        }
        slot->slot_markedP = FALSE;
      }
    }
    { Slot* slot = NULL;
      Iterator* iter_002 = renamed_Class->class_slots();

      while (iter_002->nextP()) {
        {
          slot = ((Slot*)(iter_002->value));
        }
        mark_direct_equivalent_slot(slot);
      }
    }
    { Slot* slot = NULL;
      Iterator* iter_003 = renamed_Class->class_slots();

      while (iter_003->nextP()) {
        {
          slot = ((Slot*)(iter_003->value));
        }
        if ((!slot->slot_markedP) &&
            storage_slotP(slot)) {
          initialvalueassignment = yield_initial_value_assignment(((Storage_Slot*)(slot)));
          if (initialvalueassignment != NULL) {
            assignments = cons(initialvalueassignment, assignments);
          }
        }
      }
    }
    return (assignments);
  }
}

Cons* yield_local_initial_value_assignments(Class* renamed_Class) {
  { Cons* assignments = NIL;
    Object* initialvalueassignment = NULL;

    { Slot* slot = NULL;
      Cons* iter_001 = renamed_Class->class_local_slots->the_cons_list;

      while (!nilP(iter_001)) {
        {
          slot = ((Slot*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        slot->slot_markedP = FALSE;
      }
    }
    { Slot* slot = NULL;
      Cons* iter_002 = renamed_Class->class_local_slots->the_cons_list;

      while (!nilP(iter_002)) {
        {
          slot = ((Slot*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        mark_direct_equivalent_slot(slot);
      }
    }
    { Slot* slot = NULL;
      Cons* iter_003 = renamed_Class->class_local_slots->the_cons_list;

      while (!nilP(iter_003)) {
        {
          slot = ((Slot*)(iter_003->value));
          iter_003 = iter_003->rest;
        }
        if ((!slot->slot_markedP) &&
            storage_slotP(slot)) {
          initialvalueassignment = yield_initial_value_assignment(((Storage_Slot*)(slot)));
          if (initialvalueassignment != NULL) {
            assignments = cons(initialvalueassignment, assignments);
          }
        }
      }
    }
    return (assignments->reverse());
  }
}

Cons* yield_constructor_body(Class* renamed_Class, Cons* requiredassignments) {
  { Cons* initialvalueassignments = yield_initial_value_assignments(renamed_Class);

    if (initialvalueassignments->emptyP() &&
        (requiredassignments->emptyP() &&
         ((!(renamed_Class->initializer() != NULL)) &&
          ((!renamed_Class->activeP()) &&
           (!decided_to_recycleP(renamed_Class)))))) {
      return (yield_creation_trees(renamed_Class));
    }
    return (yield_creation_trees(renamed_Class)->concatenate(initialvalueassignments->concatenate(requiredassignments->concatenate(((renamed_Class->initializer() != NULL) ? ((Cons*)(cons(cons(renamed_Class->initializer(), cons(SYM_DEFCLASS_SELF, NIL)), NIL))) : ((Cons*)(NIL)))->concatenate((renamed_Class->activeP() ? ((Cons*)(cons(listO(3, SYM_DEFCLASS_RUN_CONSTRUCTOR_DEMONS, SYM_DEFCLASS_SELF, NIL), NIL))) : ((Cons*)(NIL)))->concatenate(NIL))))));
  }
}

Cons* yield_constructor_definition(Class* renamed_Class) {
  { Cons* requiredparameters = NIL;
    Cons* assignments = NIL;
    Slot* slot = NULL;

    { Symbol* slotname = NULL;
      Cons* iter_001 = renamed_Class->class_required_slot_names_reader()->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          slotname = ((Symbol*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        assignments = cons(listO(4, SYM_DEFCLASS_SETF, cons(slotname, cons(SYM_DEFCLASS_SELF, NIL)), slotname, NIL), assignments);
        slot = lookup_slot(renamed_Class, slotname);
        if (collect_001 == NULL) {
          {
            collect_001 = cons(cons(slotname, cons(type_to_symbol(slot->type()), NIL)), NIL);
            if (nilP(requiredparameters)) {
              requiredparameters = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(requiredparameters, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(cons(slotname, cons(type_to_symbol(slot->type()), NIL)), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    return (listO(5, SYM_DEFCLASS_DEFUN, cons(yield_constructor_name(renamed_Class), cons(class_symbol(renamed_Class), NIL)), requiredparameters->concatenate(NIL), listO(3, SYM_DEFCLASS_LET, cons(listO(3, SYM_DEFCLASS_SELF, class_symbol(renamed_Class), cons(SYM_DEFCLASS_NULL, NIL)), NIL), yield_constructor_body(renamed_Class, assignments->reverse())->concatenate(cons(listO(3, SYM_DEFCLASS_RETURN, SYM_DEFCLASS_SELF, NIL), NIL))), NIL));
  }
}

Cons* yield_destructor_definitions(Class* renamed_Class) {
  { Symbol* classname = class_symbol(renamed_Class);
    Symbol* destructor = ((Symbol*)(dynamic_slot_value(renamed_Class, SYM_DEFCLASS_CLASS_DESTRUCTOR, NULL)));
    Symbol* terminator = renamed_Class->terminator();
    Cons* definitions = NIL;

    if (decided_to_recycleP(renamed_Class)) {
      { Storage_Slot* recycleslot = NULL;
        Symbol* recyclelist = NULL;

        if (use_free_listP(renamed_Class)) {
          recycleslot = recycle_slot(renamed_Class);
          recyclelist = yield_recycle_list_name(renamed_Class);
          definitions = cons(listO(4, SYM_DEFCLASS_DEFMETHOD, SYM_DEFCLASS_FREE, cons(listO(3, SYM_DEFCLASS_SELF, classname, NIL), NIL), yield_terminate_object_trees(renamed_Class)->concatenate(((recycleslot != NULL) ? ((Cons*)(listO(3, listO(4, SYM_DEFCLASS_SETF, listO(4, SYM_DEFCLASS_SLOT_VALUE, SYM_DEFCLASS_SELF, recycleslot->slot_name, NIL), recyclelist, NIL), listO(3, SYM_DEFCLASS_SETQ, recyclelist, cons(SYM_DEFCLASS_SELF, NIL)), NIL))) : ((Cons*)(cons(listO(3, SYM_DEFCLASS_PUSH, recyclelist, cons(SYM_DEFCLASS_SELF, NIL)), NIL))))->concatenate(NIL))), definitions);
        }
        if (use_sweep_listP(renamed_Class)) {
          if (!use_free_listP(renamed_Class)) {
            definitions = cons(listO(5, SYM_DEFCLASS_DEFMETHOD, SYM_DEFCLASS_FREE, cons(listO(3, SYM_DEFCLASS_SELF, classname, NIL), NIL), SYM_DEFCLASS_NULL, NIL), definitions);
          }
          definitions = cons(listO(4, SYM_DEFCLASS_DEFMETHOD, SYM_DEFCLASS_SWEEP, cons(listO(3, SYM_DEFCLASS_SELF, classname, NIL), NIL), (use_free_listP(renamed_Class) ? ((Cons*)(((recycle_slot(renamed_Class) != NULL) ? ((Cons*)(cons(listO(3, SYM_DEFCLASS_SETQ, recyclelist, cons(SYM_DEFCLASS_NULL, NIL)), NIL))) : ((Cons*)(cons(listO(3, SYM_DEFCLASS_CLEAR, recyclelist, NIL), NIL)))))) : ((Cons*)(NIL)))->concatenate(cons(listO(3, SYM_DEFCLASS_SETQ, yield_sweep_list_pointer_name(renamed_Class), cons(yield_sweep_list_name(renamed_Class), NIL)), NIL))), definitions);
        }
      }
    }
    else if ((terminator != NULL) ||
        (destructor != NULL)) {
      if (!(destructor != NULL)) {
        destructor = SYM_DEFCLASS_UNMAKE;
      }
      if (!(destructor == SYM_DEFCLASS_FREE)) {
        definitions = cons(listO(5, SYM_DEFCLASS_DEFMETHOD, SYM_DEFCLASS_FREE, cons(listO(3, SYM_DEFCLASS_SELF, classname, NIL), NIL), ((terminator != NULL) ? ((Cons*)(listO(4, SYM_DEFCLASS_WHEN, cons(terminator, cons(SYM_DEFCLASS_SELF, NIL)), cons(destructor, cons(SYM_DEFCLASS_SELF, NIL)), NIL))) : ((Cons*)(cons(destructor, cons(SYM_DEFCLASS_SELF, NIL))))), NIL), definitions);
      }
    }
    return (definitions->reverse());
  }
}

void create_constructor_and_destructor_units(Class* renamed_Class) {
  if (translator_output_language() == KWD_DEFCLASS_CPP_STANDALONE) {
    create_cpp_constructor_unit(renamed_Class);
    return;
  }
  if (!(renamed_Class->abstractP ||
      subtype_ofP(renamed_Class->class_type, SGT_DEFCLASS_LITERAL))) {
    { Object* definition = NULL;
      Cons* iter_001 = yield_recycle_list_definitions(renamed_Class);

      while (!nilP(iter_001)) {
        {
          definition = iter_001->value;
          iter_001 = iter_001->rest;
        }
        walk_auxiliary_tree(((Cons*)(definition)));
      }
    }
    walk_auxiliary_tree(yield_constructor_definition(renamed_Class));
    { Object* destructor = NULL;
      Cons* iter_002 = yield_destructor_definitions(renamed_Class);

      while (!nilP(iter_002)) {
        {
          destructor = iter_002->value;
          iter_002 = iter_002->rest;
        }
        walk_auxiliary_tree(((Cons*)(destructor)));
      }
    }
  }
}

boolean parameterized_classP(Class* renamed_Class) {
  { boolean foundP_001 = FALSE;

    { Symbol* parameters = NULL;
      Cons* iter_001 = renamed_Class->parameters()->the_cons_list;

      while (!nilP(iter_001)) {
        {
          parameters = ((Symbol*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        foundP_001 = TRUE;
        break;
      }
    }
    { boolean value_001 = foundP_001;

      return (value_001);
    }
  }
}

boolean class_with_initializerP(Class* renamed_Class) {
  { boolean foundP_001 = FALSE;

    { Slot* slot = NULL;
      Iterator* iter_001 = renamed_Class->class_slots();

      while (iter_001->nextP()) {
        {
          slot = ((Slot*)(iter_001->value));
        }
        if (storage_slotP(slot)) {
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

Symbol* yield_initializer_name(Class* renamed_Class) {
  return (intern_derived_symbol(renamed_Class->class_type, string_concatenate("initialize-", class_name(renamed_Class))));
}

Cons* yield_initializer_definition(Class* renamed_Class) {
  { Cons* parentinitforms = NIL;

    { Surrogate* super = NULL;
      Cons* iter_001 = renamed_Class->class_direct_supers->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          super = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (class_with_initializerP(((Class*)(super->surrogate_value)))) {
          if (collect_001 == NULL) {
            {
              collect_001 = cons(cons(yield_initializer_name(((Class*)(super->surrogate_value))), cons(SYM_DEFCLASS_SELF, NIL)), NIL);
              if (nilP(parentinitforms)) {
                parentinitforms = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(parentinitforms, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = cons(cons(yield_initializer_name(((Class*)(super->surrogate_value))), cons(SYM_DEFCLASS_SELF, NIL)), NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
    }
    return (listO(3, SYM_DEFCLASS_DEFUN, yield_initializer_name(renamed_Class), cons(cons(listO(3, SYM_DEFCLASS_SELF, yield_type_spec_tree(renamed_Class->class_type), NIL), NIL), parentinitforms->concatenate(yield_local_initial_value_assignments(renamed_Class)->concatenate(NIL)))));
  }
}

void create_cpp_constructor_unit(Class* renamed_Class) {
  if (!(parameterized_classP(renamed_Class))) {
    { Object* classname = yield_type_spec_tree(renamed_Class->class_type);
      boolean hasinitializerP = class_with_initializerP(renamed_Class);

      if (hasinitializerP) {
        walk_auxiliary_tree(yield_initializer_definition(renamed_Class));
      }
      help_walk_auxiliary_tree(listO(3, SYM_DEFCLASS_DEFMETHOD, classname, cons(cons(listO(3, SYM_DEFCLASS_SELF, classname, NIL), NIL), (hasinitializerP ? ((Cons*)(cons(cons(yield_initializer_name(renamed_Class), cons(SYM_DEFCLASS_SELF, NIL)), NIL))) : ((Cons*)(cons(SYM_DEFCLASS_NULL, NIL))))->concatenate(NIL))), FALSE);
    }
  }
}

boolean cpp_constructorP(Method_Slot* method) {
  return ((method->type() == SGT_DEFCLASS_VOID) &&
      ((method->method_parameter_names_reader()->length() == 1) &&
       (string_eqlP(method->slot_owner->symbol_name, method->slot_name->symbol_name) &&
        (method->slot_owner->home_context == method->slot_name->home_context))));
}

boolean has_non_null_default_valueP(Storage_Slot* slot) {
  { Object* defaultform = slot->system_default_value();

    return ((defaultform != NULL) &&
        ((!equal_cons_treesP(type_to_null_value_tree(slot->type()), defaultform)) ||
         ((slot->type() == SGT_DEFCLASS_BOOLEAN) &&
          (slot->allocation() == KWD_DEFCLASS_DYNAMIC))));
  }
}

boolean system_defined_slot_readerP(Storage_Slot* slot) {
  return ((slot->reader() == NULL) &&
      (has_non_null_default_valueP(slot) ||
       (slot->activeP() ||
        slot->slot_hardwiredP)));
}

boolean system_defined_slot_writerP(Storage_Slot* slot) {
  return ((slot->writer() == NULL) &&
      slot->activeP());
}

Object* yield_slot_type_tree(Storage_Slot* slot) {
  return (yield_type_spec_tree(((((Compound_Type_Specifier*)(dynamic_slot_value(slot, SYM_DEFCLASS_SLOT_TYPE_SPECIFIER, NULL))) != NULL) ? ((Standard_Object*)(((Compound_Type_Specifier*)(dynamic_slot_value(slot, SYM_DEFCLASS_SLOT_TYPE_SPECIFIER, NULL))))) : ((Standard_Object*)(slot->slot_base_type)))));
}

Symbol* yield_hardwired_slot_variable(Storage_Slot* slot) {
  return (intern_derived_symbol(slot->slot_name, string_concatenate("*HARDWIRED-", string_concatenate(slot->slot_name->symbol_name, string_concatenate("-ON-", string_concatenate(slot->slot_owner->symbol_name, "*"))))));
}

Cons* yield_hardwired_slot_reader_body(Storage_Slot* slot, Cons*& return1) {
  { Symbol* slotvariable = yield_hardwired_slot_variable(slot);
    Object* slottypedesc = yield_type_spec_tree(slot->compute_return_type_spec(slot->slot_owner));

    { Cons* return_temp = listO(3, SYM_DEFCLASS_RETURN, slotvariable, NIL);

      return1 = listO(3, SYM_DEFCLASS_DEFGLOBAL, slotvariable, cons(slottypedesc, cons(SYM_DEFCLASS_NULL, NIL)));
      return (return_temp);
    }
  }
}

void finalize_accessor_method(Method_Slot* method) {
  if ((method->slot_base_type == NULL) &&
      (((Compound_Type_Specifier*)(dynamic_slot_value(method, SYM_DEFCLASS_SLOT_TYPE_SPECIFIER, NULL))) != NULL)) {
    method->slot_base_type = validate_type_specifier(((Compound_Type_Specifier*)(dynamic_slot_value(method, SYM_DEFCLASS_SLOT_TYPE_SPECIFIER, NULL))), ((Class*)(method->slot_owner->surrogate_value)), FALSE);
  }
}

Cons* wrap_with_default_value_and_return_code(Cons* readcode, Object* defaultexpression) {
  if (defaultexpression != NULL) {
    return (listO(4, SYM_DEFCLASS_LET, cons(listO(3, SYM_DEFCLASS_ANSWER, readcode, NIL), NIL), listO(5, SYM_DEFCLASS_IF, listO(3, SYM_DEFCLASS_NULLp, SYM_DEFCLASS_ANSWER, NIL), listO(3, SYM_DEFCLASS_RETURN, transientify_form(defaultexpression), NIL), listO(3, SYM_DEFCLASS_RETURN, SYM_DEFCLASS_ANSWER, NIL), NIL), NIL));
  }
  else {
    return (listO(3, SYM_DEFCLASS_RETURN, readcode, NIL));
  }
}

Cons* yield_slot_reader_tree(Storage_Slot* slot, Class* renamed_Class) {
  { Cons* parameters = cons(listO(3, SYM_DEFCLASS_SELF, type_to_symbol(renamed_Class->class_type), NIL), NIL);
    Object* typetree = yield_slot_type_tree(slot);
    Object* defaultexpression = (has_non_null_default_valueP(slot) ? ((Object*)(slot->system_default_value())) : ((Object*)(NULL)));
    boolean slotvisibleP = subtype_ofP(renamed_Class->class_type, slot->slot_owner);
    Cons* readcode = NULL;
    Cons* auxiliarycode = NULL;

    if (!slotvisibleP) {
      readcode = listO(4, SYM_DEFCLASS_PROGN, listO(4, SYM_DEFCLASS_ERROR, string_wrap_literal("Slot '"), string_wrap_literal(slot->slot_name->symbol_name), listO(3, string_wrap_literal("' does not exist on "), SYM_DEFCLASS_SELF, NIL)), listO(3, SYM_DEFCLASS_RETURN, SYM_DEFCLASS_NULL, NIL), NIL);
    }
    else if (slot->activeP()) {
      readcode = yield_active_slot_reader_body(slot, defaultexpression);
    }
    else if (slot->slot_hardwiredP) {
      readcode = yield_hardwired_slot_reader_body(slot, auxiliarycode);
      if (renamed_Class->class_type == slot->slot_owner) {
        walk_auxiliary_tree(auxiliarycode);
      }
    }
    else {
      readcode = wrap_with_default_value_and_return_code(listO(4, SYM_DEFCLASS_SLOT_VALUE, SYM_DEFCLASS_SELF, slot->slot_name, NIL), defaultexpression);
    }
    return (listO(4, SYM_DEFCLASS_DEFMETHOD, cons(slot->slot_name, cons(typetree, NIL)), parameters, listO(4, KWD_DEFCLASS_AUXILIARYp, SYM_DEFCLASS_TRUE, readcode, NIL)));
  }
}

Cons* yield_slot_writer_tree(Storage_Slot* slot, Class* renamed_Class) {
  { Object* typetree = yield_slot_type_tree(slot);
    Cons* parameters = listO(3, listO(3, SYM_DEFCLASS_SELF, type_to_symbol(renamed_Class->class_type), NIL), listO(3, SYM_DEFCLASS_VALUE, typetree, NIL), NIL);
    boolean slotvisibleP = subtype_ofP(renamed_Class->class_type, slot->slot_owner);
    Cons* writecode = NULL;

    if (!slotvisibleP) {
      writecode = listO(4, SYM_DEFCLASS_PROGN, listO(4, SYM_DEFCLASS_ERROR, string_wrap_literal("Slot '"), string_wrap_literal(slot->slot_name->symbol_name), listO(3, string_wrap_literal("' does not exist on "), SYM_DEFCLASS_SELF, NIL)), listO(3, SYM_DEFCLASS_RETURN, SYM_DEFCLASS_NULL, NIL), NIL);
    }
    else if (slot->activeP()) {
      writecode = yield_active_slot_writer_body(slot);
    }
    else {
      writecode = listO(3, SYM_DEFCLASS_RETURN, listO(4, SYM_DEFCLASS_SETF, listO(4, SYM_DEFCLASS_SLOT_VALUE, SYM_DEFCLASS_SELF, slot->slot_name, NIL), SYM_DEFCLASS_VALUE, NIL), NIL);
    }
    return (listO(4, SYM_DEFCLASS_DEFMETHOD, cons(yield_setter_method_name(slot->slot_name), cons(copy_cons_tree(typetree), NIL)), parameters, listO(3, KWD_DEFCLASS_AUXILIARYp, SYM_DEFCLASS_TRUE, (slotvisibleP ? ((Cons*)(NIL)) : ((Cons*)(cons(listO(3, SYM_DEFCLASS_IGNORE, SYM_DEFCLASS_VALUE, NIL), NIL))))->concatenate(cons(writecode, NIL)))));
  }
}

boolean slot_value_is_bare_literalP(Slot* slot) {
  { Surrogate* type = slot->type();

    return ((type != NULL) &&
        ((((Class*)(type->surrogate_value)) != NULL) &&
         subtype_ofP(slot->type(), SGT_DEFCLASS_LITERAL)));
  }
}

boolean generically_accessible_typeP(Surrogate* type) {
  return (subtype_ofP(type, SGT_DEFCLASS_OBJECT) ||
      (subtype_ofP(type, SGT_DEFCLASS_LITERAL) &&
       (lookup_literal_type_info(type, KWD_DEFCLASS_WRAP_FUNCTION) != NULL)));
}

boolean generic_slot_readerP(Storage_Slot* slot) {
  { Surrogate* type = canonical_type(slot->type());

    return ((!slot->abstractP) &&
        (subtype_ofP(slot->slot_owner, SGT_DEFCLASS_OBJECT) &&
         ((((Class*)(type->surrogate_value)) != NULL) &&
          generically_accessible_typeP(type))));
  }
}

boolean generic_slot_writerP(Storage_Slot* slot) {
  return ((!slot->slot_hardwiredP) &&
      generic_slot_readerP(slot));
}

boolean slot_access_methodP(Storage_Slot* slot) {
  return ((slot->reader() != NULL) ||
      (system_defined_slot_readerP(slot) ||
       ((slot->writer() != NULL) ||
        system_defined_slot_writerP(slot))));
}

Symbol* yield_generic_slot_accessor_name(Class* renamed_Class) {
  return (intern_derived_symbol(renamed_Class->class_type, string_concatenate("ACCESS-", string_concatenate(renamed_Class->class_type->symbol_name, "-SLOT-VALUE"))));
}

Cons* yield_generic_slot_accessor_definition(Class* renamed_Class) {
  { Cons* clauses = NIL;
    Cons* accesstree = NIL;
    Object* valuetree = NULL;
    Surrogate* slottype = NULL;

    if (!subclass_ofP(renamed_Class, ((Class*)(SGT_DEFCLASS_OBJECT->surrogate_value)))) {
      return (NULL);
    }
    { Slot* slot = NULL;
      Cons* iter_001 = renamed_Class->class_local_slots->the_cons_list;

      while (!nilP(iter_001)) {
        {
          slot = ((Slot*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (storage_slotP(slot) &&
            generic_slot_readerP(((Storage_Slot*)(slot)))) {
          if (slot->slot_externalP ||
              (space_saver_slot_allocationP(((Storage_Slot*)(slot))) &&
               (!slot_access_methodP(((Storage_Slot*)(slot)))))) {
            continue;
          }
          accesstree = listO(3, SYM_DEFCLASS_RETURN, cons(slot->slot_name, cons(SYM_DEFCLASS_SELF, NIL)), NIL);
          if (!((Storage_Slot*)(slot))->slot_hardwiredP) {
            slottype = canonical_type(slot->type());
            valuetree = SYM_DEFCLASS_VALUE;
            if (subtype_ofP(slottype, SGT_DEFCLASS_LITERAL) &&
                (lookup_literal_type_info(slottype, KWD_DEFCLASS_WRAP_FUNCTION) != NULL)) {
              valuetree = listO(4, SYM_DEFCLASS_CAST, SYM_DEFCLASS_VALUE, slottype->type_to_wrapped_type(), NIL);
            }
            accesstree = listO(5, SYM_DEFCLASS_IF, SYM_DEFCLASS_SETVALUEp, listO(4, SYM_DEFCLASS_SETF, cons(slot->slot_name, cons(SYM_DEFCLASS_SELF, NIL)), valuetree, NIL), listO(3, SYM_DEFCLASS_RETURN, cons(slot->slot_name, cons(SYM_DEFCLASS_SELF, NIL)), NIL), NIL);
          }
          clauses = cons(cons(slot->slot_name, cons(accesstree, NIL)), clauses);
        }
      }
    }
    if (subclass_ofP(renamed_Class, ((Class*)(SGT_DEFCLASS_DYNAMIC_SLOTS_MIXIN->surrogate_value)))) {
      { Cons* renameclauses = NIL;

        { Slot* slot = NULL;
          Cons* iter_002 = renamed_Class->class_local_slots->the_cons_list;
          Cons* collect_001 = NULL;

          while (!nilP(iter_002)) {
            {
              slot = ((Slot*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            if (storage_slotP(slot) &&
                ((!slot->slot_externalP) &&
                 (space_saver_slot_allocationP(((Storage_Slot*)(slot))) &&
                  ((!slot_access_methodP(((Storage_Slot*)(slot)))) &&
                   (!(slot == canonical_slot(((Storage_Slot*)(slot))))))))) {
              if (collect_001 == NULL) {
                {
                  collect_001 = cons(cons(slot->slot_name, cons(listO(4, SYM_DEFCLASS_SETQ, SYM_DEFCLASS_SLOTNAME, listO(3, SYM_DEFCLASS_QUOTE, canonical_slot(((Storage_Slot*)(slot)))->slot_name, NIL), NIL), NIL)), NIL);
                  if (nilP(renameclauses)) {
                    renameclauses = collect_001;
                  }
                  else {
                    add_cons_to_end_of_cons_list(renameclauses, collect_001);
                  }
                }
              }
              else {
                {
                  collect_001->rest = cons(cons(slot->slot_name, cons(listO(4, SYM_DEFCLASS_SETQ, SYM_DEFCLASS_SLOTNAME, listO(3, SYM_DEFCLASS_QUOTE, canonical_slot(((Storage_Slot*)(slot)))->slot_name, NIL), NIL), NIL)), NIL);
                  collect_001 = collect_001->rest;
                }
              }
            }
          }
        }
        if (renameclauses->non_emptyP()) {
          renameclauses = cons(listO(3, SYM_DEFCLASS_CASE, SYM_DEFCLASS_SLOTNAME, renameclauses->concatenate(cons(listO(3, SYM_DEFCLASS_OTHERWISE, SYM_DEFCLASS_NULL, NIL), NIL))), NIL);
        }
        clauses = cons(cons(SYM_DEFCLASS_OTHERWISE, renameclauses->concatenate(cons(listO(5, SYM_DEFCLASS_IF, SYM_DEFCLASS_SETVALUEp, listO(5, SYM_DEFCLASS_HELP_SET_DYNAMIC_SLOT_VALUE, listO(3, SYM_DEFCLASS_DYNAMIC_SLOTS, SYM_DEFCLASS_SELF, NIL), SYM_DEFCLASS_SLOTNAME, SYM_DEFCLASS_VALUE, NIL), listO(3, SYM_DEFCLASS_RETURN, listO(4, SYM_DEFCLASS_LOOKUP, listO(3, SYM_DEFCLASS_DYNAMIC_SLOTS, SYM_DEFCLASS_SELF, NIL), SYM_DEFCLASS_SLOTNAME, NIL), NIL), NIL), NIL))), clauses);
      }
    }
    if (clauses->emptyP()) {
      return (NULL);
    }
    else {
      return (listO(6, SYM_DEFCLASS_DEFUN, cons(yield_generic_slot_accessor_name(renamed_Class), cons(SYM_DEFCLASS_OBJECT, NIL)), listO(5, listO(3, SYM_DEFCLASS_SELF, renamed_Class->class_type, NIL), listO(3, SYM_DEFCLASS_SLOTNAME, SYM_DEFCLASS_SYMBOL, NIL), listO(3, SYM_DEFCLASS_VALUE, SYM_DEFCLASS_OBJECT, NIL), listO(3, SYM_DEFCLASS_SETVALUEp, SYM_DEFCLASS_BOOLEAN, NIL), NIL), listO(3, SYM_DEFCLASS_CASE, SYM_DEFCLASS_SLOTNAME, clauses->reverse()->concatenate(NIL)), listO(4, SYM_DEFCLASS_WHEN, SYM_DEFCLASS_SETVALUEp, listO(3, SYM_DEFCLASS_RETURN, SYM_DEFCLASS_VALUE, NIL), NIL), NIL));
    }
  }
}

void create_generic_slot_accessor_unit(Class* renamed_Class) {
  { Cons* tree = yield_generic_slot_accessor_definition(renamed_Class);

    if (tree != NULL) {
      walk_auxiliary_tree(tree);
    }
  }
}

Cons* yield_generic_slot_accessor_attachment(Class* renamed_Class, Symbol* classref) {
  { boolean foundP_001 = FALSE;

    { Slot* slot = NULL;
      Cons* iter_001 = renamed_Class->class_local_slots->the_cons_list;

      while (!nilP(iter_001)) {
        {
          slot = ((Slot*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (storage_slotP(slot) &&
            generic_slot_readerP(((Storage_Slot*)(slot)))) {
          foundP_001 = TRUE;
          break;
        }
      }
    }
    if (foundP_001) {
      return (cons(listO(4, SYM_DEFCLASS_SETF, listO(3, SYM_DEFCLASS_CLASS_SLOT_ACCESSOR_CODE, classref, NIL), listO(4, SYM_DEFCLASS_THE_CODE, KWD_DEFCLASS_FUNCTION, yield_generic_slot_accessor_name(renamed_Class), NIL), NIL), NIL));
    }
    else {
      return (NIL);
    }
  }
}

Cons* yield_mixin_class_users_tree(Class* renamed_Class) {
  { Cons* result = NIL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            { Surrogate* sub = NULL;
              Cons* iter_001 = renamed_Class->class_direct_subs->the_cons_list;
              Cons* collect_001 = NULL;

              while (!nilP(iter_001)) {
                {
                  sub = ((Surrogate*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                if (!type_to_class(sub)->mixinP) {
                  if (collect_001 == NULL) {
                    {
                      collect_001 = cons(type_to_symbol(sub), NIL);
                      if (nilP(result)) {
                        result = collect_001;
                      }
                      else {
                        add_cons_to_end_of_cons_list(result, collect_001);
                      }
                    }
                  }
                  else {
                    {
                      collect_001->rest = cons(type_to_symbol(sub), NIL);
                      collect_001 = collect_001->rest;
                    }
                  }
                }
              }
            }
            { 
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (result);
            }
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          resignal();
        }
      }
    }
  }
}

Symbol* yield_mixin_slot_reader_name(Storage_Slot* slot) {
  return (intern_derived_symbol(slot->slot_name, string_concatenate(slot->slot_name->symbol_name, string_concatenate("-ON-", slot->slot_owner->symbol_name))));
}

Symbol* yield_mixin_slot_writer_name(Storage_Slot* slot) {
  return (yield_setter_method_name(yield_mixin_slot_reader_name(slot)));
}

Cons* yield_mixin_slot_reader_tree(Storage_Slot* slot) {
  { Symbol* readername = yield_mixin_slot_reader_name(slot);
    Object* typetree = yield_slot_type_tree(slot);

    return (listO(7, SYM_DEFCLASS_DEFUN, cons(readername, cons(typetree, NIL)), cons(listO(3, SYM_DEFCLASS_SELF, SYM_DEFCLASS_OBJECT, NIL), NIL), KWD_DEFCLASS_AUXILIARYp, SYM_DEFCLASS_TRUE, listO(5, SYM_DEFCLASS_TYPECASE, SYM_DEFCLASS_SELF, cons(yield_mixin_class_users_tree(((Class*)(slot->slot_owner->surrogate_value))), cons(listO(3, SYM_DEFCLASS_RETURN, cons(slot->slot_name, cons(SYM_DEFCLASS_SELF, NIL)), NIL), NIL)), listO(3, SYM_DEFCLASS_OTHERWISE, listO(3, SYM_DEFCLASS_RETURN, SYM_DEFCLASS_NULL, NIL), NIL), NIL), NIL));
  }
}

Cons* yield_mixin_slot_writer_tree(Storage_Slot* slot) {
  { Symbol* writername = yield_mixin_slot_writer_name(slot);
    Object* typetree = yield_slot_type_tree(slot);

    return (listO(7, SYM_DEFCLASS_DEFUN, cons(writername, cons(typetree, NIL)), listO(3, listO(3, SYM_DEFCLASS_SELF, SYM_DEFCLASS_OBJECT, NIL), listO(3, SYM_DEFCLASS_VALUE, copy_cons_tree(typetree), NIL), NIL), KWD_DEFCLASS_AUXILIARYp, SYM_DEFCLASS_TRUE, listO(5, SYM_DEFCLASS_TYPECASE, SYM_DEFCLASS_SELF, cons(yield_mixin_class_users_tree(((Class*)(slot->slot_owner->surrogate_value))), cons(listO(3, SYM_DEFCLASS_RETURN, listO(4, SYM_DEFCLASS_SETF, cons(slot->slot_name, cons(SYM_DEFCLASS_SELF, NIL)), SYM_DEFCLASS_VALUE, NIL), NIL), NIL)), listO(3, SYM_DEFCLASS_OTHERWISE, listO(3, SYM_DEFCLASS_RETURN, SYM_DEFCLASS_NULL, NIL), NIL), NIL), NIL));
  }
}

Symbol* yield_native_slot_reader_name(Storage_Slot* slot) {
  return (intern_derived_symbol(slot->slot_name, string_concatenate(slot->slot_name->symbol_name, "-NATIVE-VALUE")));
}

Symbol* yield_native_slot_writer_name(Storage_Slot* slot) {
  return (yield_setter_method_name(yield_native_slot_reader_name(slot)));
}

Cons* yield_native_slot_reader_tree(Storage_Slot* slot, Class* renamed_Class) {
  { Symbol* readername = yield_native_slot_reader_name(slot);
    Object* typetree = yield_slot_type_tree(slot);
    boolean slotvisibleP = subtype_ofP(renamed_Class->class_type, slot->slot_owner);

    return (listO(6, SYM_DEFCLASS_DEFMETHOD, cons(readername, cons(typetree, NIL)), cons(listO(3, SYM_DEFCLASS_SELF, class_symbol(renamed_Class), NIL), NIL), KWD_DEFCLASS_AUXILIARYp, SYM_DEFCLASS_TRUE, (slotvisibleP ? ((Cons*)(cons(listO(3, SYM_DEFCLASS_RETURN, listO(4, SYM_DEFCLASS_SLOT_VALUE, SYM_DEFCLASS_SELF, slot->slot_name, listO(3, KWD_DEFCLASS_CONTEXT_SENSITIVEp, SYM_DEFCLASS_FALSE, NIL)), NIL), NIL))) : ((Cons*)(listO(3, listO(4, SYM_DEFCLASS_ERROR, string_wrap_literal("Slot '"), string_wrap_literal(slot->slot_name->symbol_name), listO(3, string_wrap_literal("' does not exist on "), SYM_DEFCLASS_SELF, NIL)), listO(3, SYM_DEFCLASS_RETURN, SYM_DEFCLASS_NULL, NIL), NIL))))->concatenate(NIL)));
  }
}

Cons* yield_native_slot_writer_tree(Storage_Slot* slot, Class* renamed_Class) {
  { Symbol* writername = yield_native_slot_writer_name(slot);
    Object* typetree = yield_slot_type_tree(slot);
    boolean slotvisibleP = subtype_ofP(renamed_Class->class_type, slot->slot_owner);

    return (listO(6, SYM_DEFCLASS_DEFMETHOD, cons(writername, cons(typetree, NIL)), listO(3, listO(3, SYM_DEFCLASS_SELF, class_symbol(renamed_Class), NIL), listO(3, SYM_DEFCLASS_VALUE, copy_cons_tree(typetree), NIL), NIL), KWD_DEFCLASS_AUXILIARYp, SYM_DEFCLASS_TRUE, (slotvisibleP ? ((Cons*)(cons(listO(3, SYM_DEFCLASS_RETURN, listO(4, SYM_DEFCLASS_SETF, listO(4, SYM_DEFCLASS_SLOT_VALUE, SYM_DEFCLASS_SELF, slot->slot_name, listO(3, KWD_DEFCLASS_CONTEXT_SENSITIVEp, SYM_DEFCLASS_FALSE, NIL)), SYM_DEFCLASS_VALUE, NIL), NIL), NIL))) : ((Cons*)(listO(4, listO(3, SYM_DEFCLASS_IGNORE, SYM_DEFCLASS_VALUE, NIL), listO(4, SYM_DEFCLASS_ERROR, string_wrap_literal("Slot '"), string_wrap_literal(slot->slot_name->symbol_name), listO(3, string_wrap_literal("' does not exist on "), SYM_DEFCLASS_SELF, NIL)), listO(3, SYM_DEFCLASS_RETURN, SYM_DEFCLASS_NULL, NIL), NIL))))->concatenate(NIL)));
  }
}

void create_keyed_equality_method_unit(Class* renamed_Class) {
  { Cons* testtrees = NIL;

    { Slot* slotname = NULL;
      Cons* iter_001 = renamed_Class->class_key_reader()->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          slotname = ((Slot*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(listO(4, SYM_DEFCLASS_EQp, cons(slotname, cons(SYM_DEFCLASS_SELF, NIL)), cons(slotname, cons(SYM_DEFCLASS_OTHER, NIL)), NIL), NIL);
            if (nilP(testtrees)) {
              testtrees = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(testtrees, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(listO(4, SYM_DEFCLASS_EQp, cons(slotname, cons(SYM_DEFCLASS_SELF, NIL)), cons(slotname, cons(SYM_DEFCLASS_OTHER, NIL)), NIL), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    walk_auxiliary_tree(listO(5, SYM_DEFCLASS_DEFMETHOD, listO(3, SYM_DEFCLASS_EQUAL, SYM_DEFCLASS_BOOLEAN, NIL), listO(3, listO(3, SYM_DEFCLASS_SELF, class_symbol(renamed_Class), NIL), SYM_DEFCLASS_OTHER, NIL), listO(3, SYM_DEFCLASS_RETURN, cons(SYM_DEFCLASS_AND, testtrees->concatenate(NIL)), NIL), NIL));
  }
}

boolean transient_objectP(Object* object) {
  { Surrogate* type = object->primary_type();

    return (subtype_ofP(type, SGT_DEFCLASS_TRANSIENT_MIXIN));
  }
}

void startup_defclass() {
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
            KWD_DEFCLASS_COMMON_LISP = ((Keyword*)(intern_rigid_symbol_wrt_module("COMMON-LISP", NULL, 2)));
            SGT_DEFCLASS_LITERAL = ((Surrogate*)(intern_rigid_symbol_wrt_module("LITERAL", NULL, 1)));
            SYM_DEFCLASS_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", NULL, 0)));
            SYM_DEFCLASS_DEFINE_CLASS_FROM_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINE-CLASS-FROM-STRINGIFIED-SOURCE", NULL, 0)));
            SYM_DEFCLASS_CLASS_CL_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CL-NATIVE-TYPE", NULL, 0)));
            KWD_DEFCLASS_IDL = ((Keyword*)(intern_rigid_symbol_wrt_module("IDL", NULL, 2)));
            SYM_DEFCLASS_CLASS_IDL_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-IDL-NATIVE-TYPE", NULL, 0)));
            KWD_DEFCLASS_JAVA = ((Keyword*)(intern_rigid_symbol_wrt_module("JAVA", NULL, 2)));
            SYM_DEFCLASS_CLASS_JAVA_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-JAVA-NATIVE-TYPE", NULL, 0)));
            KWD_DEFCLASS_CPP = ((Keyword*)(intern_rigid_symbol_wrt_module("CPP", NULL, 2)));
            KWD_DEFCLASS_CPP_STANDALONE = ((Keyword*)(intern_rigid_symbol_wrt_module("CPP-STANDALONE", NULL, 2)));
            SYM_DEFCLASS_CLASS_CPP_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CPP-NATIVE-TYPE", NULL, 0)));
            SGT_DEFCLASS_SECOND_CLASS_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("SECOND-CLASS-OBJECT", NULL, 1)));
            SGT_DEFCLASS_NON_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("NON-OBJECT", NULL, 1)));
            KWD_DEFCLASS_DYNAMIC = ((Keyword*)(intern_rigid_symbol_wrt_module("DYNAMIC", NULL, 2)));
            SYM_DEFCLASS_SLOT_INITIAL_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-INITIAL-VALUE", NULL, 0)));
            KWD_DEFCLASS_BIT = ((Keyword*)(intern_rigid_symbol_wrt_module("BIT", NULL, 2)));
            SGT_DEFCLASS_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", NULL, 1)));
            SYM_DEFCLASS_SLOT_RENAMES = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-RENAMES", NULL, 0)));
            SGT_DEFCLASS_UNKNOWN = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNKNOWN", NULL, 1)));
            SYM_DEFCLASS_NEXT_SWEEP_LIST_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("NEXT-SWEEP-LIST-OBJECT", NULL, 0)));
            SYM_DEFCLASS_CLASS_CREATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CREATOR", NULL, 0)));
            SYM_DEFCLASS_DEFGLOBAL = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFGLOBAL", NULL, 0)));
            SYM_DEFCLASS_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("LIST", NULL, 0)));
            SYM_DEFCLASS_OF = ((Symbol*)(intern_rigid_symbol_wrt_module("OF", NULL, 0)));
            SYM_DEFCLASS_STARTUP_TIME_PROGN = ((Symbol*)(intern_rigid_symbol_wrt_module("STARTUP-TIME-PROGN", NULL, 0)));
            KWD_DEFCLASS_EARLY_INITS = ((Keyword*)(intern_rigid_symbol_wrt_module("EARLY-INITS", NULL, 2)));
            SYM_DEFCLASS_SETQ = ((Symbol*)(intern_rigid_symbol_wrt_module("SETQ", NULL, 0)));
            SYM_DEFCLASS_MAKE_NON_RECYCLED_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("MAKE-NON-RECYCLED-LIST", NULL, 0)));
            SYM_DEFCLASS_SELF = ((Symbol*)(intern_rigid_symbol_wrt_module("SELF", NULL, 0)));
            SYM_DEFCLASS_MAKE = ((Symbol*)(intern_rigid_symbol_wrt_module("MAKE", NULL, 0)));
            SYM_DEFCLASS_WHEN = ((Symbol*)(intern_rigid_symbol_wrt_module("WHEN", NULL, 0)));
            SYM_DEFCLASS_DEFINEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINED?", NULL, 0)));
            SYM_DEFCLASS_FREE = ((Symbol*)(intern_rigid_symbol_wrt_module("FREE", NULL, 0)));
            SYM_DEFCLASS_DYNAMIC_SLOTS = ((Symbol*)(intern_rigid_symbol_wrt_module("DYNAMIC-SLOTS", NULL, 0)));
            SYM_DEFCLASS_CLEAR = ((Symbol*)(intern_rigid_symbol_wrt_module("CLEAR", NULL, 0)));
            SYM_DEFCLASS_UNLESS = ((Symbol*)(intern_rigid_symbol_wrt_module("UNLESS", NULL, 0)));
            SYM_DEFCLASS_RETURN = ((Symbol*)(intern_rigid_symbol_wrt_module("RETURN", NULL, 0)));
            SYM_DEFCLASS_SLOT_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-VALUE", NULL, 0)));
            SYM_DEFCLASS_SAFE_CAST = ((Symbol*)(intern_rigid_symbol_wrt_module("SAFE-CAST", NULL, 0)));
            SYM_DEFCLASS_POP = ((Symbol*)(intern_rigid_symbol_wrt_module("POP", NULL, 0)));
            SYM_DEFCLASS_COND = ((Symbol*)(intern_rigid_symbol_wrt_module("COND", NULL, 0)));
            SYM_DEFCLASS_OTHERWISE = ((Symbol*)(intern_rigid_symbol_wrt_module("OTHERWISE", NULL, 0)));
            SYM_DEFCLASS_SETF = ((Symbol*)(intern_rigid_symbol_wrt_module("SETF", NULL, 0)));
            KWD_DEFCLASS_CONTEXT_SENSITIVEp = ((Keyword*)(intern_rigid_symbol_wrt_module("CONTEXT-SENSITIVE?", NULL, 2)));
            SYM_DEFCLASS_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", NULL, 0)));
            SYM_DEFCLASS_RUN_CONSTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("RUN-CONSTRUCTOR-DEMONS", NULL, 0)));
            SYM_DEFCLASS_DEFUN = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFUN", NULL, 0)));
            SYM_DEFCLASS_LET = ((Symbol*)(intern_rigid_symbol_wrt_module("LET", NULL, 0)));
            SYM_DEFCLASS_CLASS_DESTRUCTOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-DESTRUCTOR", NULL, 0)));
            SYM_DEFCLASS_DEFMETHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFMETHOD", NULL, 0)));
            SYM_DEFCLASS_PUSH = ((Symbol*)(intern_rigid_symbol_wrt_module("PUSH", NULL, 0)));
            SYM_DEFCLASS_SWEEP = ((Symbol*)(intern_rigid_symbol_wrt_module("SWEEP", NULL, 0)));
            SYM_DEFCLASS_UNMAKE = ((Symbol*)(intern_rigid_symbol_wrt_module("UNMAKE", NULL, 0)));
            SGT_DEFCLASS_VOID = ((Surrogate*)(intern_rigid_symbol_wrt_module("VOID", NULL, 1)));
            SYM_DEFCLASS_SLOT_TYPE_SPECIFIER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-TYPE-SPECIFIER", NULL, 0)));
            SYM_DEFCLASS_ANSWER = ((Symbol*)(intern_rigid_symbol_wrt_module("ANSWER", NULL, 0)));
            SYM_DEFCLASS_IF = ((Symbol*)(intern_rigid_symbol_wrt_module("IF", NULL, 0)));
            SYM_DEFCLASS_NULLp = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL?", NULL, 0)));
            SYM_DEFCLASS_PROGN = ((Symbol*)(intern_rigid_symbol_wrt_module("PROGN", NULL, 0)));
            SYM_DEFCLASS_ERROR = ((Symbol*)(intern_rigid_symbol_wrt_module("ERROR", NULL, 0)));
            KWD_DEFCLASS_AUXILIARYp = ((Keyword*)(intern_rigid_symbol_wrt_module("AUXILIARY?", NULL, 2)));
            SYM_DEFCLASS_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            SYM_DEFCLASS_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE", NULL, 0)));
            SYM_DEFCLASS_IGNORE = ((Symbol*)(intern_rigid_symbol_wrt_module("IGNORE", NULL, 0)));
            SGT_DEFCLASS_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("OBJECT", NULL, 1)));
            KWD_DEFCLASS_WRAP_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("WRAP-FUNCTION", NULL, 2)));
            SYM_DEFCLASS_CAST = ((Symbol*)(intern_rigid_symbol_wrt_module("CAST", NULL, 0)));
            SYM_DEFCLASS_SETVALUEp = ((Symbol*)(intern_rigid_symbol_wrt_module("SETVALUE?", NULL, 0)));
            SGT_DEFCLASS_DYNAMIC_SLOTS_MIXIN = ((Surrogate*)(intern_rigid_symbol_wrt_module("DYNAMIC-SLOTS-MIXIN", NULL, 1)));
            SYM_DEFCLASS_SLOTNAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOTNAME", NULL, 0)));
            SYM_DEFCLASS_QUOTE = ((Symbol*)(intern_rigid_symbol_wrt_module("QUOTE", NULL, 0)));
            SYM_DEFCLASS_CASE = ((Symbol*)(intern_rigid_symbol_wrt_module("CASE", NULL, 0)));
            SYM_DEFCLASS_HELP_SET_DYNAMIC_SLOT_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("HELP-SET-DYNAMIC-SLOT-VALUE", NULL, 0)));
            SYM_DEFCLASS_LOOKUP = ((Symbol*)(intern_rigid_symbol_wrt_module("LOOKUP", NULL, 0)));
            SYM_DEFCLASS_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("OBJECT", NULL, 0)));
            SYM_DEFCLASS_SYMBOL = ((Symbol*)(intern_rigid_symbol_wrt_module("SYMBOL", NULL, 0)));
            SYM_DEFCLASS_BOOLEAN = ((Symbol*)(intern_rigid_symbol_wrt_module("BOOLEAN", NULL, 0)));
            SYM_DEFCLASS_CLASS_SLOT_ACCESSOR_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-SLOT-ACCESSOR-CODE", NULL, 0)));
            SYM_DEFCLASS_THE_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-CODE", NULL, 0)));
            KWD_DEFCLASS_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            SYM_DEFCLASS_TYPECASE = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPECASE", NULL, 0)));
            SYM_DEFCLASS_EQp = ((Symbol*)(intern_rigid_symbol_wrt_module("EQ?", NULL, 0)));
            SYM_DEFCLASS_OTHER = ((Symbol*)(intern_rigid_symbol_wrt_module("OTHER", NULL, 0)));
            SYM_DEFCLASS_EQUAL = ((Symbol*)(intern_rigid_symbol_wrt_module("EQUAL", NULL, 0)));
            SYM_DEFCLASS_AND = ((Symbol*)(intern_rigid_symbol_wrt_module("AND", NULL, 0)));
            SGT_DEFCLASS_TRANSIENT_MIXIN = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-MIXIN", NULL, 1)));
          }
          if (current_startup_time_phaseP(4)) {
            oTRANSLATOR_OUTPUT_LANGUAGEo = KWD_DEFCLASS_COMMON_LISP;
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("TYPE-TO-NULL-VALUE-TREE", "TYPE", "(DEFUN (TYPE-TO-NULL-VALUE-TREE OBJECT) ((TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&type_to_null_value_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CONS-LIST-FROM-SEQUENCE", "SEQUENCE", "(DEFUN (YIELD-CONS-LIST-FROM-SEQUENCE CONS) ((SEQUENCE SEQUENCE)))");

              method->function_code = ((cpp_function_code)(&yield_cons_list_from_sequence));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-DEFINE-STELLA-CLASS", "CLASS", "(DEFUN (YIELD-DEFINE-STELLA-CLASS CONS) ((CLASS CLASS)) :DOCUMENTATION \"Return a cons tree that (when evaluated) constructs\na Stella class object.\")");

              method->function_code = ((cpp_function_code)(&yield_define_stella_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-NATIVE-CLASS?", "CLASS", "(DEFUN (CREATE-NATIVE-CLASS? BOOLEAN) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&create_native_classP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WARN-ABOUT-MULTIPLE-PARENTS", "CLASS", "(DEFUN WARN-ABOUT-MULTIPLE-PARENTS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&warn_about_multiple_parents));
            }
            { Method_Slot* method = define_method_from_stringified_source("WARN-ABOUT-NON-DIRECT-SUPERS", "CLASS", "(DEFUN WARN-ABOUT-NON-DIRECT-SUPERS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&warn_about_non_direct_supers));
            }
            { Method_Slot* method = define_method_from_stringified_source("SPACE-SAVER-SLOT-ALLOCATION?", "STORAGE-SLOT", "(DEFUN (SPACE-SAVER-SLOT-ALLOCATION? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&space_saver_slot_allocationP));
            }
            { Method_Slot* method = define_method_from_stringified_source("REDUNDANT-SLOT?", "STORAGE-SLOT", "(DEFUN (REDUNDANT-SLOT? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&redundant_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NATIVE-SLOT?", "STORAGE-SLOT", "(DEFUN (NATIVE-SLOT? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&native_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CANONICAL-SLOT", "STORAGE-SLOT", "(DEFUN (CANONICAL-SLOT STORAGE-SLOT) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&canonical_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNKNOWN-TYPE?", "TYPE", "(DEFUN (UNKNOWN-TYPE? BOOLEAN) ((TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&unknown_typeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOT-HAS-UNKNOWN-TYPE?", "STORAGE-SLOT", "(DEFUN (SLOT-HAS-UNKNOWN-TYPE? BOOLEAN) ((SLOT STORAGE-SLOT) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&slot_has_unknown_typeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NATIVE-SLOT-HOME", "STORAGE-SLOT", "(DEFUN (NATIVE-SLOT-HOME CLASS) ((SLOT STORAGE-SLOT) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&native_slot_home));
            }
            { Method_Slot* method = define_method_from_stringified_source("MIXIN-SLOT-HOME", "STORAGE-SLOT", "(DEFUN (MIXIN-SLOT-HOME CLASS) ((SLOT STORAGE-SLOT) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&mixin_slot_home));
            }
            { Method_Slot* method = define_method_from_stringified_source("SWEEP", "OBJECT", "(DEFMETHOD SWEEP ((SELF OBJECT)) :DOCUMENTATION \"Default method.  Sweep up all 'self'-type objects.\")");

              method->method_code = ((cpp_method_code)(&Object::sweep));
            }
            { Method_Slot* method = define_method_from_stringified_source("SWEEP-TRANSIENTS", NULL, "(DEFUN SWEEP-TRANSIENTS ())");

              method->function_code = ((cpp_function_code)(&sweep_transients));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-RECYCLE-LIST-NAME", "CLASS", "(DEFUN (YIELD-RECYCLE-LIST-NAME SYMBOL) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_recycle_list_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SWEEP-LIST-NAME", "CLASS", "(DEFUN (YIELD-SWEEP-LIST-NAME SYMBOL) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_sweep_list_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SWEEP-LIST-POINTER-NAME", "CLASS", "(DEFUN (YIELD-SWEEP-LIST-POINTER-NAME SYMBOL) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_sweep_list_pointer_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("RECYCLE-SLOT", "CLASS", "(DEFUN (RECYCLE-SLOT STORAGE-SLOT) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&recycle_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("USE-FREE-LIST?", "CLASS", "(DEFUN (USE-FREE-LIST? BOOLEAN) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&use_free_listP));
            }
            { Method_Slot* method = define_method_from_stringified_source("USE-SWEEP-LIST?", "CLASS", "(DEFUN (USE-SWEEP-LIST? BOOLEAN) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&use_sweep_listP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DECIDED-TO-RECYCLE?", "CLASS", "(DEFUN (DECIDED-TO-RECYCLE? BOOLEAN) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&decided_to_recycleP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MAKE-NON-RECYCLED-LIST", NULL, "(DEFUN (MAKE-NON-RECYCLED-LIST LIST) ())");

              method->function_code = ((cpp_function_code)(&make_non_recycled_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-RECYCLE-LIST-DEFINITIONS", "CLASS", "(DEFUN (YIELD-RECYCLE-LIST-DEFINITIONS CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_recycle_list_definitions));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-MAKE-TREES", "CLASS", "(DEFUN (YIELD-MAKE-TREES CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_make_trees));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CONSTRUCTOR-NAME", "CLASS", "(DEFUN (YIELD-CONSTRUCTOR-NAME SYMBOL) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_constructor_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CREATION-TREES", "CLASS", "(DEFUN (YIELD-CREATION-TREES CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_creation_trees));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-TERMINATE-OBJECT-TREES", "CLASS", "(DEFUN (YIELD-TERMINATE-OBJECT-TREES CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_terminate_object_trees));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CREATION-OR-REUSE-TREES", "CLASS", "(DEFUN (YIELD-CREATION-OR-REUSE-TREES CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_creation_or_reuse_trees));
            }
            { Method_Slot* method = define_method_from_stringified_source("MARK-DIRECT-EQUIVALENT-SLOT", "SLOT", "(DEFUN MARK-DIRECT-EQUIVALENT-SLOT ((SLOT SLOT)))");

              method->function_code = ((cpp_function_code)(&mark_direct_equivalent_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("IS-CONTEXT-SENSITIVE-SLOT?", "STORAGE-SLOT", "(DEFUN (IS-CONTEXT-SENSITIVE-SLOT? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&is_context_sensitive_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-INITIAL-VALUE-ASSIGNMENT", "STORAGE-SLOT", "(DEFUN (YIELD-INITIAL-VALUE-ASSIGNMENT CONS) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_initial_value_assignment));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-INITIAL-VALUE-ASSIGNMENTS", "CLASS", "(DEFUN (YIELD-INITIAL-VALUE-ASSIGNMENTS CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_initial_value_assignments));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-LOCAL-INITIAL-VALUE-ASSIGNMENTS", "CLASS", "(DEFUN (YIELD-LOCAL-INITIAL-VALUE-ASSIGNMENTS CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_local_initial_value_assignments));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CONSTRUCTOR-BODY", "CLASS", "(DEFUN (YIELD-CONSTRUCTOR-BODY CONS) ((CLASS CLASS) (REQUIREDASSIGNMENTS CONS)))");

              method->function_code = ((cpp_function_code)(&yield_constructor_body));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CONSTRUCTOR-DEFINITION", "CLASS", "(DEFUN (YIELD-CONSTRUCTOR-DEFINITION CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_constructor_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-DESTRUCTOR-DEFINITIONS", "CLASS", "(DEFUN (YIELD-DESTRUCTOR-DEFINITIONS CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_destructor_definitions));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-CONSTRUCTOR-AND-DESTRUCTOR-UNITS", "CLASS", "(DEFUN CREATE-CONSTRUCTOR-AND-DESTRUCTOR-UNITS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&create_constructor_and_destructor_units));
            }
            { Method_Slot* method = define_method_from_stringified_source("PARAMETERIZED-CLASS?", "CLASS", "(DEFUN (PARAMETERIZED-CLASS? BOOLEAN) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&parameterized_classP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-WITH-INITIALIZER?", "CLASS", "(DEFUN (CLASS-WITH-INITIALIZER? BOOLEAN) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&class_with_initializerP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-INITIALIZER-NAME", "CLASS", "(DEFUN (YIELD-INITIALIZER-NAME SYMBOL) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_initializer_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-INITIALIZER-DEFINITION", "CLASS", "(DEFUN (YIELD-INITIALIZER-DEFINITION CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_initializer_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-CPP-CONSTRUCTOR-UNIT", "CLASS", "(DEFUN CREATE-CPP-CONSTRUCTOR-UNIT ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&create_cpp_constructor_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("CPP-CONSTRUCTOR?", "METHOD-SLOT", "(DEFUN (CPP-CONSTRUCTOR? BOOLEAN) ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&cpp_constructorP));
            }
            { Method_Slot* method = define_method_from_stringified_source("HAS-NON-NULL-DEFAULT-VALUE?", "STORAGE-SLOT", "(DEFUN (HAS-NON-NULL-DEFAULT-VALUE? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&has_non_null_default_valueP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYSTEM-DEFINED-SLOT-READER?", "STORAGE-SLOT", "(DEFUN (SYSTEM-DEFINED-SLOT-READER? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&system_defined_slot_readerP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYSTEM-DEFINED-SLOT-WRITER?", "STORAGE-SLOT", "(DEFUN (SYSTEM-DEFINED-SLOT-WRITER? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&system_defined_slot_writerP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SLOT-TYPE-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-SLOT-TYPE-TREE OBJECT) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_slot_type_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-HARDWIRED-SLOT-VARIABLE", "STORAGE-SLOT", "(DEFUN (YIELD-HARDWIRED-SLOT-VARIABLE SYMBOL) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_hardwired_slot_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-HARDWIRED-SLOT-READER-BODY", "STORAGE-SLOT", "(DEFUN (YIELD-HARDWIRED-SLOT-READER-BODY CONS CONS) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_hardwired_slot_reader_body));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-ACCESSOR-METHOD", "METHOD-SLOT", "(DEFUN FINALIZE-ACCESSOR-METHOD ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&finalize_accessor_method));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-WITH-DEFAULT-VALUE-AND-RETURN-CODE", "CONS", "(DEFUN (WRAP-WITH-DEFAULT-VALUE-AND-RETURN-CODE CONS) ((READCODE CONS) (DEFAULTEXPRESSION OBJECT)))");

              method->function_code = ((cpp_function_code)(&wrap_with_default_value_and_return_code));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SLOT-READER-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-SLOT-READER-TREE CONS) ((SLOT STORAGE-SLOT) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_slot_reader_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SLOT-WRITER-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-SLOT-WRITER-TREE CONS) ((SLOT STORAGE-SLOT) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_slot_writer_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOT-VALUE-IS-BARE-LITERAL?", "SLOT", "(DEFUN (SLOT-VALUE-IS-BARE-LITERAL? BOOLEAN) ((SLOT SLOT)))");

              method->function_code = ((cpp_function_code)(&slot_value_is_bare_literalP));
            }
            { Method_Slot* method = define_method_from_stringified_source("GENERICALLY-ACCESSIBLE-TYPE?", "TYPE", "(DEFUN (GENERICALLY-ACCESSIBLE-TYPE? BOOLEAN) ((TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&generically_accessible_typeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("GENERIC-SLOT-READER?", "STORAGE-SLOT", "(DEFUN (GENERIC-SLOT-READER? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&generic_slot_readerP));
            }
            { Method_Slot* method = define_method_from_stringified_source("GENERIC-SLOT-WRITER?", "STORAGE-SLOT", "(DEFUN (GENERIC-SLOT-WRITER? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&generic_slot_writerP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOT-ACCESS-METHOD?", "STORAGE-SLOT", "(DEFUN (SLOT-ACCESS-METHOD? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&slot_access_methodP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-GENERIC-SLOT-ACCESSOR-NAME", "CLASS", "(DEFUN (YIELD-GENERIC-SLOT-ACCESSOR-NAME SYMBOL) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_generic_slot_accessor_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-GENERIC-SLOT-ACCESSOR-DEFINITION", "CLASS", "(DEFUN (YIELD-GENERIC-SLOT-ACCESSOR-DEFINITION CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_generic_slot_accessor_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-GENERIC-SLOT-ACCESSOR-UNIT", "CLASS", "(DEFUN CREATE-GENERIC-SLOT-ACCESSOR-UNIT ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&create_generic_slot_accessor_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-GENERIC-SLOT-ACCESSOR-ATTACHMENT", "CLASS", "(DEFUN (YIELD-GENERIC-SLOT-ACCESSOR-ATTACHMENT CONS) ((CLASS CLASS) (CLASSREF SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_generic_slot_accessor_attachment));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-MIXIN-CLASS-USERS-TREE", "CLASS", "(DEFUN (YIELD-MIXIN-CLASS-USERS-TREE (CONS OF SYMBOL)) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_mixin_class_users_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-MIXIN-SLOT-READER-NAME", "STORAGE-SLOT", "(DEFUN (YIELD-MIXIN-SLOT-READER-NAME SYMBOL) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_mixin_slot_reader_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-MIXIN-SLOT-WRITER-NAME", "STORAGE-SLOT", "(DEFUN (YIELD-MIXIN-SLOT-WRITER-NAME SYMBOL) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_mixin_slot_writer_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-MIXIN-SLOT-READER-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-MIXIN-SLOT-READER-TREE CONS) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_mixin_slot_reader_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-MIXIN-SLOT-WRITER-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-MIXIN-SLOT-WRITER-TREE CONS) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_mixin_slot_writer_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-NATIVE-SLOT-READER-NAME", "STORAGE-SLOT", "(DEFUN (YIELD-NATIVE-SLOT-READER-NAME SYMBOL) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_native_slot_reader_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-NATIVE-SLOT-WRITER-NAME", "STORAGE-SLOT", "(DEFUN (YIELD-NATIVE-SLOT-WRITER-NAME SYMBOL) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_native_slot_writer_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-NATIVE-SLOT-READER-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-NATIVE-SLOT-READER-TREE CONS) ((SLOT STORAGE-SLOT) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_native_slot_reader_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-NATIVE-SLOT-WRITER-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-NATIVE-SLOT-WRITER-TREE CONS) ((SLOT STORAGE-SLOT) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_native_slot_writer_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-KEYED-EQUALITY-METHOD-UNIT", "CLASS", "(DEFUN CREATE-KEYED-EQUALITY-METHOD-UNIT ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&create_keyed_equality_method_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSIENT-OBJECT?", "OBJECT", "(DEFUN (TRANSIENT-OBJECT? BOOLEAN) ((OBJECT OBJECT)))");

              method->function_code = ((cpp_function_code)(&transient_objectP));
            }
            define_method_from_stringified_source("STARTUP-DEFCLASS", NULL, "(DEFUN STARTUP-DEFCLASS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *TRANSLATOR-OUTPUT-LANGUAGE* KEYWORD :COMMON-LISP :DOCUMENTATION \"Specifies the translator output language; either\n:common-lisp, :idl, :java, :cpp, or :cpp-standalone.\")");
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

