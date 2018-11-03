// more-demons.cc

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

Symbol* SYM_MORE_DEMONS_INVERSE = NULL;

Keyword* KWD_MORE_DEMONS_CODE = NULL;

Symbol* SYM_MORE_DEMONS_SLOT_DEMONS = NULL;

Keyword* KWD_MORE_DEMONS_DOCUMENTATION = NULL;

Keyword* KWD_MORE_DEMONS_CREATE = NULL;

Keyword* KWD_MORE_DEMONS_ALL = NULL;

Keyword* KWD_MORE_DEMONS_DESTROY = NULL;

void inverse_slot_demon(Standard_Object* self, Storage_Slot* slot, Standard_Object* oldvalue, Standard_Object* newvalue) {
  { Slot* inverseslot = ((Slot*)(dynamic_slot_value(slot, SYM_MORE_DEMONS_INVERSE, NULL)));

    if (oldvalue != NULL) {
      drop_slot_value(oldvalue, ((Storage_Slot*)(inverseslot)), self);
    }
    if (newvalue != NULL) {
      put_slot_value(newvalue, ((Storage_Slot*)(inverseslot)), self);
    }
  }
}

void attach_inverse_slot_demon(Slot* slot) {
  { Slot* slot_001 = slot;

    if (storage_slotP(slot)) {
      { Storage_Slot* slot = NULL;

        slot = ((Storage_Slot*)(slot_001));
        { Demon* inversedemon = lookup_demon("inverse-slot-demon");

          inversedemon->demon_class_refs->push(slot->slot_owner);
          inversedemon->demon_slot_refs->push(slot->slot_name);
          set_dynamic_slot_value(slot, SYM_MORE_DEMONS_SLOT_DEMONS, inject_demon(slot->slot_demons_reader(), inversedemon), NULL);
        }
      }
    }
    else {
      return;
    }
  }
}

void class_extension_constructor_demon(Active_Object* self, Class* renamed_Class) {
  { Class_Extension* extension = renamed_Class->extension();

    if (extension != NULL) {
      extension->insert(self);
    }
  }
}

void class_extension_destructor_demon(Active_Object* self, Class* renamed_Class) {
  { Class_Extension* extension = renamed_Class->extension();

    if (extension != NULL) {
      extension->remove(self);
    }
  }
}

void startup_more_demons() {
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
            SYM_MORE_DEMONS_INVERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("INVERSE", NULL, 0)));
            KWD_MORE_DEMONS_CODE = ((Keyword*)(intern_rigid_symbol_wrt_module("CODE", NULL, 2)));
            SYM_MORE_DEMONS_SLOT_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-DEMONS", NULL, 0)));
            KWD_MORE_DEMONS_DOCUMENTATION = ((Keyword*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 2)));
            KWD_MORE_DEMONS_CREATE = ((Keyword*)(intern_rigid_symbol_wrt_module("CREATE", NULL, 2)));
            KWD_MORE_DEMONS_ALL = ((Keyword*)(intern_rigid_symbol_wrt_module("ALL", NULL, 2)));
            KWD_MORE_DEMONS_DESTROY = ((Keyword*)(intern_rigid_symbol_wrt_module("DESTROY", NULL, 2)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("INVERSE-SLOT-DEMON", "STANDARD-OBJECT", "(DEFUN INVERSE-SLOT-DEMON ((SELF STANDARD-OBJECT) (SLOT STORAGE-SLOT) (OLDVALUE STANDARD-OBJECT) (NEWVALUE STANDARD-OBJECT)))");

              method->function_code = ((cpp_function_code)(&inverse_slot_demon));
            }
            { Method_Slot* method = define_method_from_stringified_source("ATTACH-INVERSE-SLOT-DEMON", "SLOT", "(DEFUN ATTACH-INVERSE-SLOT-DEMON ((SLOT SLOT)))");

              method->function_code = ((cpp_function_code)(&attach_inverse_slot_demon));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-EXTENSION-CONSTRUCTOR-DEMON", "ACTIVE-OBJECT", "(DEFUN CLASS-EXTENSION-CONSTRUCTOR-DEMON ((SELF ACTIVE-OBJECT) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&class_extension_constructor_demon));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-EXTENSION-DESTRUCTOR-DEMON", "ACTIVE-OBJECT", "(DEFUN CLASS-EXTENSION-DESTRUCTOR-DEMON ((SELF ACTIVE-OBJECT) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&class_extension_destructor_demon));
            }
            define_method_from_stringified_source("STARTUP-MORE-DEMONS", NULL, "(DEFUN STARTUP-MORE-DEMONS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_demon("inverse-slot-demon", 2, KWD_MORE_DEMONS_CODE, function_code_wrap_literal(((cpp_function_code)(&inverse_slot_demon))));
            define_demon("class-extension-constructor-demon", 6, KWD_MORE_DEMONS_DOCUMENTATION, string_wrap_literal("Demon that inserts the instance 'self' into the extension of\nthe class 'class'."), KWD_MORE_DEMONS_CREATE, KWD_MORE_DEMONS_ALL, KWD_MORE_DEMONS_CODE, function_code_wrap_literal(((cpp_function_code)(&class_extension_constructor_demon))));
            define_demon("class-extension-destructor-demon", 6, KWD_MORE_DEMONS_DOCUMENTATION, string_wrap_literal("Demon that removes the instance 'self' from the extension of\nthe class 'class'.  Removal removes the instance forever.  Deletion without\nremoval can be achieved in constant time by setting 'deleted?' on 'self'."), KWD_MORE_DEMONS_DESTROY, KWD_MORE_DEMONS_ALL, KWD_MORE_DEMONS_CODE, function_code_wrap_literal(((cpp_function_code)(&class_extension_destructor_demon))));
            { Demon* createdemon = lookup_demon("class-extension-constructor-demon");
              Demon* destroydemon = lookup_demon("class-extension-destructor-demon");

              activate_demon(createdemon);
              activate_demon(destroydemon);
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

