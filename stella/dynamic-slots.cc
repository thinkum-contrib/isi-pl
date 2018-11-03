// dynamic-slots.cc

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

Keyword* KWD_DYNAMIC_SLOTS_DYNAMIC = NULL;

Keyword* KWD_DYNAMIC_SLOTS_NULL_WRAPPER = NULL;

Keyword* KWD_DYNAMIC_SLOTS_COMMON_LISP = NULL;

Surrogate* SGT_DYNAMIC_SLOTS_OBJECT = NULL;

Symbol* SYM_DYNAMIC_SLOTS_WRAPPER_VALUE = NULL;

Symbol* SYM_DYNAMIC_SLOTS_SAFE_CAST = NULL;

Symbol* SYM_DYNAMIC_SLOTS_DYNAMIC_SLOT_VALUE = NULL;

Symbol* SYM_DYNAMIC_SLOTS_QUOTE = NULL;

Symbol* SYM_DYNAMIC_SLOTS_NULL = NULL;

Symbol* SYM_DYNAMIC_SLOTS_SET_DYNAMIC_SLOT_VALUE = NULL;

Symbol* SYM_DYNAMIC_SLOTS_BQUOTE = NULL;

Keyword* KWD_DYNAMIC_SLOTS_WRAP_FUNCTION = NULL;

Object* dynamic_slot_value(Dynamic_Slots_Mixin* self, Symbol* slotname, Object* nullvalue) {
  { Object* value = NULL;
    Object* key = NULL;
    Kv_Cons* iter_001 = self->dynamic_slots->the_kv_list;

    while (iter_001 != NULL) {
      key = iter_001->key;
      {
        value = iter_001->value;
        iter_001 = iter_001->rest;
      }
      if (key == slotname) {
        if (value == NULL) {
          return (nullvalue);
        }
        else {
          return (value);
        }
      }
    }
  }
  return (nullvalue);
}

Object* help_set_dynamic_slot_value(Key_Value_List* dynamicslots, Symbol* slotname, Object* value, Object*& return1) {
  { Kv_Cons* cursor = dynamicslots->the_kv_list;
    Object* oldvalue = NULL;

    while (cursor != NULL) {
      if (cursor->key == slotname) {
        oldvalue = cursor->value;
        if (value == NULL) {
          dynamicslots->remove_at(slotname);
        }
        else {
          cursor->value = value;
        }
        { Object* return_temp = value;

          return1 = oldvalue;
          return (return_temp);
        }
      }
      cursor = cursor->rest;
    }
    if (value != NULL) {
      dynamicslots->the_kv_list = kv_cons(slotname, value, dynamicslots->the_kv_list);
    }
    { Object* return_temp = value;

      return1 = NULL;
      return (return_temp);
    }
  }
}

Object* set_dynamic_slot_value(Dynamic_Slots_Mixin* self, Symbol* slotname, Object* value, Wrapper* nullwrapper) {
  { Object* oldvalue = NULL;

    value = help_set_dynamic_slot_value(self->dynamic_slots, slotname, ((value == nullwrapper) ? ((Object*)(NULL)) : ((Object*)(value))), oldvalue);
    if ((nullwrapper != NULL) &&
        (oldvalue != NULL)) {
      oldvalue->free();
    }
    return (value);
  }
}

boolean standard_dynamic_slot_accessP(Storage_Slot* slot) {
  return ((!slot->activeP()) &&
      ((slot->allocation() == KWD_DYNAMIC_SLOTS_DYNAMIC) &&
       ((!slot_value_is_bare_literalP(slot)) ||
        (lookup_literal_type_info(slot->slot_base_type, KWD_DYNAMIC_SLOTS_NULL_WRAPPER) != NULL))));
}

Cons* yield_down_cast_tree(Cons* tree, Standard_Object* returntype) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;

    { Cons* otree = sys_tree(tree, returntype, dummy1);

      if (!(translator_output_language() == KWD_DYNAMIC_SLOTS_COMMON_LISP)) {
        set_target_language_type(otree, SGT_DYNAMIC_SLOTS_OBJECT, dummy2);
      }
      return (otree);
    }
  }
}

Cons* yield_standard_dynamic_slot_value_tree(Storage_Slot* slot, Object* objectref, Standard_Object* returntype) {
  { Standard_Object* dummy1;

    { Symbol* slotname = canonical_slot(slot)->slot_name;

      if (slot_value_is_bare_literalP(slot)) {
        return (listO(3, SYM_DYNAMIC_SLOTS_WRAPPER_VALUE, listO(4, SYM_DYNAMIC_SLOTS_SAFE_CAST, listO(3, SYM_DYNAMIC_SLOTS_DYNAMIC_SLOT_VALUE, objectref, listO(3, listO(3, SYM_DYNAMIC_SLOTS_QUOTE, slotname, NIL), lookup_literal_type_info(slot->type(), KWD_DYNAMIC_SLOTS_NULL_WRAPPER), NIL)), type_to_symbol(slot->type()->type_to_wrapped_type()), NIL), NIL));
      }
      else {
        return (yield_down_cast_tree(walk_a_cons_tree(listO(3, SYM_DYNAMIC_SLOTS_DYNAMIC_SLOT_VALUE, objectref, listO(3, listO(3, SYM_DYNAMIC_SLOTS_QUOTE, slotname, NIL), SYM_DYNAMIC_SLOTS_NULL, NIL)), dummy1), returntype));
      }
    }
  }
}

Cons* yield_standard_dynamic_slot_value_setter_tree(Storage_Slot* slot, Object* objectref, Object* valueref, Standard_Object* returntype) {
  { Standard_Object* dummy1;

    { Symbol* slotname = canonical_slot(slot)->slot_name;
      boolean literalslotP = slot_value_is_bare_literalP(slot);
      Cons* settertree = NULL;

      if (literalslotP) {
        settertree = listO(3, SYM_DYNAMIC_SLOTS_SET_DYNAMIC_SLOT_VALUE, objectref, listO(4, listO(3, SYM_DYNAMIC_SLOTS_BQUOTE, slotname, NIL), cons(lookup_literal_type_info(slot->type(), KWD_DYNAMIC_SLOTS_WRAP_FUNCTION), cons(valueref, NIL)), lookup_literal_type_info(slot->type(), KWD_DYNAMIC_SLOTS_NULL_WRAPPER), NIL));
      }
      else {
        settertree = listO(3, SYM_DYNAMIC_SLOTS_SET_DYNAMIC_SLOT_VALUE, objectref, listO(3, listO(3, SYM_DYNAMIC_SLOTS_BQUOTE, slotname, NIL), valueref, cons(SYM_DYNAMIC_SLOTS_NULL, NIL)));
      }
      if (walking_expressionP()) {
        if (literalslotP) {
          settertree = listO(3, SYM_DYNAMIC_SLOTS_WRAPPER_VALUE, listO(3, SYM_DYNAMIC_SLOTS_SAFE_CAST, settertree, cons(type_to_symbol(slot->type()->type_to_wrapped_type()), NIL)), NIL);
        }
        else {
          settertree = yield_down_cast_tree(walk_a_cons_tree(settertree, dummy1), returntype);
        }
      }
      return (settertree);
    }
  }
}

void startup_dynamic_slots() {
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
            KWD_DYNAMIC_SLOTS_DYNAMIC = ((Keyword*)(intern_rigid_symbol_wrt_module("DYNAMIC", NULL, 2)));
            KWD_DYNAMIC_SLOTS_NULL_WRAPPER = ((Keyword*)(intern_rigid_symbol_wrt_module("NULL-WRAPPER", NULL, 2)));
            KWD_DYNAMIC_SLOTS_COMMON_LISP = ((Keyword*)(intern_rigid_symbol_wrt_module("COMMON-LISP", NULL, 2)));
            SGT_DYNAMIC_SLOTS_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("OBJECT", NULL, 1)));
            SYM_DYNAMIC_SLOTS_WRAPPER_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAPPER-VALUE", NULL, 0)));
            SYM_DYNAMIC_SLOTS_SAFE_CAST = ((Symbol*)(intern_rigid_symbol_wrt_module("SAFE-CAST", NULL, 0)));
            SYM_DYNAMIC_SLOTS_DYNAMIC_SLOT_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("DYNAMIC-SLOT-VALUE", NULL, 0)));
            SYM_DYNAMIC_SLOTS_QUOTE = ((Symbol*)(intern_rigid_symbol_wrt_module("QUOTE", NULL, 0)));
            SYM_DYNAMIC_SLOTS_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", NULL, 0)));
            SYM_DYNAMIC_SLOTS_SET_DYNAMIC_SLOT_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SET-DYNAMIC-SLOT-VALUE", NULL, 0)));
            SYM_DYNAMIC_SLOTS_BQUOTE = ((Symbol*)(intern_rigid_symbol_wrt_module("BQUOTE", NULL, 0)));
            KWD_DYNAMIC_SLOTS_WRAP_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("WRAP-FUNCTION", NULL, 2)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("DYNAMIC-SLOT-VALUE", "DYNAMIC-SLOTS-MIXIN", "(DEFUN (DYNAMIC-SLOT-VALUE OBJECT) ((SELF DYNAMIC-SLOTS-MIXIN) (SLOTNAME SYMBOL) (NULLVALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&dynamic_slot_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-SET-DYNAMIC-SLOT-VALUE", "KEY-VALUE-LIST", "(DEFUN (HELP-SET-DYNAMIC-SLOT-VALUE OBJECT OBJECT) ((DYNAMICSLOTS KEY-VALUE-LIST) (SLOTNAME SYMBOL) (VALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&help_set_dynamic_slot_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("SET-DYNAMIC-SLOT-VALUE", "DYNAMIC-SLOTS-MIXIN", "(DEFUN (SET-DYNAMIC-SLOT-VALUE OBJECT) ((SELF DYNAMIC-SLOTS-MIXIN) (SLOTNAME SYMBOL) (VALUE OBJECT) (NULLWRAPPER WRAPPER)))");

              method->function_code = ((cpp_function_code)(&set_dynamic_slot_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("STANDARD-DYNAMIC-SLOT-ACCESS?", "STORAGE-SLOT", "(DEFUN (STANDARD-DYNAMIC-SLOT-ACCESS? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&standard_dynamic_slot_accessP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-DOWN-CAST-TREE", "CONS", "(DEFUN (YIELD-DOWN-CAST-TREE CONS) ((TREE CONS) (RETURNTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&yield_down_cast_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-STANDARD-DYNAMIC-SLOT-VALUE-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-STANDARD-DYNAMIC-SLOT-VALUE-TREE CONS) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (RETURNTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&yield_standard_dynamic_slot_value_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-STANDARD-DYNAMIC-SLOT-VALUE-SETTER-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-STANDARD-DYNAMIC-SLOT-VALUE-SETTER-TREE CONS) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (VALUEREF OBJECT) (RETURNTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&yield_standard_dynamic_slot_value_setter_tree));
            }
            define_method_from_stringified_source("STARTUP-DYNAMIC-SLOTS", NULL, "(DEFUN STARTUP-DYNAMIC-SLOTS ())");
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

