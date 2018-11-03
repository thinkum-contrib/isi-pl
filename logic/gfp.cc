// gfp.cc

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

Surrogate* SGT_GFP_LOGIC_OBJECT = NULL;

Object* get_object_or_warn(char* name) {
  { Logic_Object* instance = string_get_frame(name);

    if (instance == NULL) {
      cerr << "Can't find an individual named " << "`" << name << "'" << ".";
    }
    return (instance);
  }
}

Object* get_frame_or_warn(char* name) {
  { Logic_Object* instance = string_get_frame(name);

    if (instance == NULL) {
      cerr << "Can't find an individual named " << "`" << name << "'" << ".";
    }
    return (instance);
  }
}

Class* get_class_or_warn(char* name) {
  { Class* renamed_Class = string_get_class(name, FALSE);

    if (renamed_Class == NULL) {
      cout << "A class named ' name ' does not exist.";
    }
    return (renamed_Class);
  }
}

Logic_Object* string_get_frame(char* name) {
  // Return the instanced named 'name'.
  return (get_instance(name, FALSE));
}

Slot* Logic_Object::get_own_slot(char* slotname) {
  // Return the slot named 'slotName' on the instance 'self'.
  { Logic_Object* self = this;

    { Surrogate* slotref = lookup_slotref_on_instance(self, intern_symbol(slotname));

      if (slotref == NULL) {
        return (NULL);
      }
      else {
        return (((Slot*)(slotref->surrogate_value)));
      }
    }
  }
}

Slot* Class::get_template_slot(char* slotname) {
  // Return the slot named 'slotName' on the class 'self'.
  { Class* self = this;

    return (safe_lookup_slot(self, intern_symbol(slotname)));
  }
}

Slot* string_get_template_slot(char* self, char* slotname) {
  // Return the slot named 'slotName' on the class 'self'.
  { Class* renamed_Class = get_class_or_warn(self);

    if (renamed_Class == NULL) {
      return (NULL);
    }
    return (renamed_Class->get_template_slot(slotname));
  }
}

Object* Logic_Object::get_slot_value(char* slotname) {
  // Get the value of 'slot' on 'self'.
  { Logic_Object* self = this;

    { Slot* slot = self->get_own_slot(slotname);

      return (get_attribute_proposition_value(self, slot->slot_slotref));
    }
  }
}

Object* string_get_slot_value(char* self, char* slotname) {
  // Get the value of 'slot' on the instance named 'self'.
  { Object* instance = get_object_or_warn(self);

    if (instance == NULL) {
      return (NULL);
    }
    { Object* instance_001 = instance;

      if (taxonomy_isaP(instance, SGT_GFP_LOGIC_OBJECT)) {
        { Logic_Object* instance = NULL;

          instance = ((Logic_Object*)(instance_001));
          return (instance->get_slot_value(slotname));
        }
      }
      else {
        cout << "Don't know how to read a slot value of the non-logic object " << self << ".";
        return (NULL);
      }
    }
  }
}

void startup_gfp() {
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
            SGT_GFP_LOGIC_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-OBJECT", NULL, 1)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("GET-OBJECT-OR-WARN", "STRING", "(DEFUN (GET-OBJECT-OR-WARN OBJECT) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&get_object_or_warn));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-FRAME-OR-WARN", "STRING", "(DEFUN (GET-FRAME-OR-WARN OBJECT) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&get_frame_or_warn));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-CLASS-OR-WARN", "STRING", "(DEFUN (GET-CLASS-OR-WARN CLASS) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&get_class_or_warn));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-FRAME", "STRING", "(DEFMETHOD (GET-FRAME LOGIC-OBJECT) ((NAME STRING)) :DOCUMENTATION \"Return the instanced named 'name'.\")");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-OWN-SLOT", "LOGIC-OBJECT", "(DEFMETHOD (GET-OWN-SLOT SLOT) ((SELF LOGIC-OBJECT) (SLOTNAME STRING)) :DOCUMENTATION \"Return the slot named 'slotName' on the instance 'self'.\")");

              method->method_code = ((cpp_method_code)(&Logic_Object::get_own_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-TEMPLATE-SLOT", "CLASS", "(DEFMETHOD (GET-TEMPLATE-SLOT SLOT) ((SELF CLASS) (SLOTNAME STRING)) :DOCUMENTATION \"Return the slot named 'slotName' on the class 'self'.\")");

              method->method_code = ((cpp_method_code)(&Class::get_template_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-TEMPLATE-SLOT", "STRING", "(DEFMETHOD (GET-TEMPLATE-SLOT SLOT) ((SELF STRING) (SLOTNAME STRING)) :DOCUMENTATION \"Return the slot named 'slotName' on the class 'self'.\")");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-SLOT-VALUE", "LOGIC-OBJECT", "(DEFMETHOD (GET-SLOT-VALUE OBJECT) ((SELF LOGIC-OBJECT) (SLOTNAME STRING)) :DOCUMENTATION \"Get the value of 'slot' on 'self'.\")");

              method->method_code = ((cpp_method_code)(&Logic_Object::get_slot_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-SLOT-VALUE", "STRING", "(DEFMETHOD (GET-SLOT-VALUE OBJECT) ((SELF STRING) (SLOTNAME STRING)) :DOCUMENTATION \"Get the value of 'slot' on the instance named 'self'.\")");

              method->method_code = ((cpp_method_code)(NULL));
            }
            define_method_from_stringified_source("STARTUP-GFP", NULL, "(DEFUN STARTUP-GFP ())");
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

