// type-predicates.cc

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

boolean oCLASS_HIERARCHY_BOOTEDpo = FALSE;

Surrogate* SGT_TYPE_PREDICATES_BOOLEAN_WRAPPER = NULL;

Surrogate* SGT_TYPE_PREDICATES_INTEGER_WRAPPER = NULL;

Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_INTEGER_WRAPPER = NULL;

Surrogate* SGT_TYPE_PREDICATES_FLOAT_WRAPPER = NULL;

Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_FLOAT_WRAPPER = NULL;

Surrogate* SGT_TYPE_PREDICATES_STRING_WRAPPER = NULL;

Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_STRING_WRAPPER = NULL;

Surrogate* SGT_TYPE_PREDICATES_VERBATIM_STRING_WRAPPER = NULL;

Surrogate* SGT_TYPE_PREDICATES_CHARACTER_WRAPPER = NULL;

Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_CHARACTER_WRAPPER = NULL;

Surrogate* SGT_TYPE_PREDICATES_WRAPPER = NULL;

Surrogate* SGT_TYPE_PREDICATES_SURROGATE = NULL;

Surrogate* SGT_TYPE_PREDICATES_SYMBOL = NULL;

Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_SYMBOL = NULL;

Surrogate* SGT_TYPE_PREDICATES_KEYWORD = NULL;

Surrogate* SGT_TYPE_PREDICATES_CONS = NULL;

Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_CONS = NULL;

Surrogate* SGT_TYPE_PREDICATES_CLASS = NULL;

Surrogate* SGT_TYPE_PREDICATES_STORAGE_SLOT = NULL;

Surrogate* SGT_TYPE_PREDICATES_METHOD_SLOT = NULL;

Surrogate* SGT_TYPE_PREDICATES_ANCHORED_TYPE_SPECIFIER = NULL;

Surrogate* SGT_TYPE_PREDICATES_PARAMETRIC_TYPE_SPECIFIER = NULL;

boolean bootstrap_isaP(Object* x, Surrogate* type) {
  return ((x != NULL) &&
      ((x->primary_type() == type) ||
       ((((Class*)(type->surrogate_value)) != NULL) &&
        ((((Class*)(x->primary_type()->surrogate_value)) != NULL) &&
         isaP(x, type)))));
}

boolean booleanP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_BOOLEAN_WRAPPER));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_BOOLEAN_WRAPPER));
}

boolean integerP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_INTEGER_WRAPPER));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_INTEGER_WRAPPER) ||
      bootstrap_isaP(x, SGT_TYPE_PREDICATES_TRANSIENT_INTEGER_WRAPPER));
}

boolean floatP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_FLOAT_WRAPPER));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_FLOAT_WRAPPER) ||
      bootstrap_isaP(x, SGT_TYPE_PREDICATES_TRANSIENT_FLOAT_WRAPPER));
}

boolean stringP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_STRING_WRAPPER));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_STRING_WRAPPER) ||
      (bootstrap_isaP(x, SGT_TYPE_PREDICATES_TRANSIENT_STRING_WRAPPER) ||
       bootstrap_isaP(x, SGT_TYPE_PREDICATES_VERBATIM_STRING_WRAPPER)));
}

boolean verbatim_stringP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_VERBATIM_STRING_WRAPPER));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_VERBATIM_STRING_WRAPPER));
}

boolean characterP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_CHARACTER_WRAPPER));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_CHARACTER_WRAPPER) ||
      bootstrap_isaP(x, SGT_TYPE_PREDICATES_TRANSIENT_CHARACTER_WRAPPER));
}

boolean wrapperP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_WRAPPER));
  }
  return (booleanP(x) ||
      (integerP(x) ||
       (floatP(x) ||
        (stringP(x) ||
         (characterP(x) ||
          bootstrap_isaP(x, SGT_TYPE_PREDICATES_WRAPPER))))));
}

boolean surrogateP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_SURROGATE));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_SURROGATE));
}

boolean typeP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_SURROGATE));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_SURROGATE));
}

boolean symbolP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_SYMBOL));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_SYMBOL) ||
      bootstrap_isaP(x, SGT_TYPE_PREDICATES_TRANSIENT_SYMBOL));
}

boolean transient_symbolP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_TRANSIENT_SYMBOL));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_TRANSIENT_SYMBOL));
}

boolean keywordP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_KEYWORD));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_KEYWORD));
}

boolean consP(Object* x) {
  if (x != NULL) {
    { Surrogate* type = x->primary_type();

      return ((type == SGT_TYPE_PREDICATES_CONS) ||
          (type == SGT_TYPE_PREDICATES_TRANSIENT_CONS));
    }
  }
  else {
    return (FALSE);
  }
}

boolean classP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_CLASS));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_CLASS));
}

boolean storage_slotP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_STORAGE_SLOT));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_STORAGE_SLOT));
}

boolean method_slotP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_METHOD_SLOT));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_METHOD_SLOT));
}

boolean anchored_type_specifierP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_ANCHORED_TYPE_SPECIFIER));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_ANCHORED_TYPE_SPECIFIER));
}

boolean parametric_type_specifierP(Object* x) {
  if (oCLASS_HIERARCHY_BOOTEDpo) {
    return ((x != NULL) &&
        taxonomy_isaP(x, SGT_TYPE_PREDICATES_PARAMETRIC_TYPE_SPECIFIER));
  }
  return (bootstrap_isaP(x, SGT_TYPE_PREDICATES_PARAMETRIC_TYPE_SPECIFIER));
}

void startup_type_predicates() {
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
            SGT_TYPE_PREDICATES_BOOLEAN_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN-WRAPPER", NULL, 1)));
            SGT_TYPE_PREDICATES_INTEGER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("INTEGER-WRAPPER", NULL, 1)));
            SGT_TYPE_PREDICATES_TRANSIENT_INTEGER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-INTEGER-WRAPPER", NULL, 1)));
            SGT_TYPE_PREDICATES_FLOAT_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("FLOAT-WRAPPER", NULL, 1)));
            SGT_TYPE_PREDICATES_TRANSIENT_FLOAT_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-FLOAT-WRAPPER", NULL, 1)));
            SGT_TYPE_PREDICATES_STRING_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("STRING-WRAPPER", NULL, 1)));
            SGT_TYPE_PREDICATES_TRANSIENT_STRING_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-STRING-WRAPPER", NULL, 1)));
            SGT_TYPE_PREDICATES_VERBATIM_STRING_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("VERBATIM-STRING-WRAPPER", NULL, 1)));
            SGT_TYPE_PREDICATES_CHARACTER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("CHARACTER-WRAPPER", NULL, 1)));
            SGT_TYPE_PREDICATES_TRANSIENT_CHARACTER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-CHARACTER-WRAPPER", NULL, 1)));
            SGT_TYPE_PREDICATES_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("WRAPPER", NULL, 1)));
            SGT_TYPE_PREDICATES_SURROGATE = ((Surrogate*)(intern_rigid_symbol_wrt_module("SURROGATE", NULL, 1)));
            SGT_TYPE_PREDICATES_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("SYMBOL", NULL, 1)));
            SGT_TYPE_PREDICATES_TRANSIENT_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-SYMBOL", NULL, 1)));
            SGT_TYPE_PREDICATES_KEYWORD = ((Surrogate*)(intern_rigid_symbol_wrt_module("KEYWORD", NULL, 1)));
            SGT_TYPE_PREDICATES_CONS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONS", NULL, 1)));
            SGT_TYPE_PREDICATES_TRANSIENT_CONS = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-CONS", NULL, 1)));
            SGT_TYPE_PREDICATES_CLASS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CLASS", NULL, 1)));
            SGT_TYPE_PREDICATES_STORAGE_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT", NULL, 1)));
            SGT_TYPE_PREDICATES_METHOD_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("METHOD-SLOT", NULL, 1)));
            SGT_TYPE_PREDICATES_ANCHORED_TYPE_SPECIFIER = ((Surrogate*)(intern_rigid_symbol_wrt_module("ANCHORED-TYPE-SPECIFIER", NULL, 1)));
            SGT_TYPE_PREDICATES_PARAMETRIC_TYPE_SPECIFIER = ((Surrogate*)(intern_rigid_symbol_wrt_module("PARAMETRIC-TYPE-SPECIFIER", NULL, 1)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("BOOTSTRAP-ISA?", "OBJECT", "(DEFUN (BOOTSTRAP-ISA? BOOLEAN) ((X OBJECT) (TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&bootstrap_isaP));
            }
            { Method_Slot* method = define_method_from_stringified_source("BOOLEAN?", "OBJECT", "(DEFUN (BOOLEAN? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&booleanP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTEGER?", "OBJECT", "(DEFUN (INTEGER? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&integerP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FLOAT?", "OBJECT", "(DEFUN (FLOAT? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&floatP));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING?", "OBJECT", "(DEFUN (STRING? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&stringP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VERBATIM-STRING?", "OBJECT", "(DEFUN (VERBATIM-STRING? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&verbatim_stringP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHARACTER?", "OBJECT", "(DEFUN (CHARACTER? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&characterP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAPPER?", "OBJECT", "(DEFUN (WRAPPER? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&wrapperP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SURROGATE?", "OBJECT", "(DEFUN (SURROGATE? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&surrogateP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TYPE?", "OBJECT", "(DEFUN (TYPE? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&typeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYMBOL?", "OBJECT", "(DEFUN (SYMBOL? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&symbolP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSIENT-SYMBOL?", "OBJECT", "(DEFUN (TRANSIENT-SYMBOL? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&transient_symbolP));
            }
            { Method_Slot* method = define_method_from_stringified_source("KEYWORD?", "OBJECT", "(DEFUN (KEYWORD? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&keywordP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONS?", "OBJECT", "(DEFUN (CONS? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&consP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS?", "OBJECT", "(DEFUN (CLASS? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&classP));
            }
            { Method_Slot* method = define_method_from_stringified_source("STORAGE-SLOT?", "OBJECT", "(DEFUN (STORAGE-SLOT? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&storage_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("METHOD-SLOT?", "OBJECT", "(DEFUN (METHOD-SLOT? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&method_slotP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ANCHORED-TYPE-SPECIFIER?", "OBJECT", "(DEFUN (ANCHORED-TYPE-SPECIFIER? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&anchored_type_specifierP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PARAMETRIC-TYPE-SPECIFIER?", "OBJECT", "(DEFUN (PARAMETRIC-TYPE-SPECIFIER? BOOLEAN) ((X OBJECT)))");

              method->function_code = ((cpp_function_code)(&parametric_type_specifierP));
            }
            define_method_from_stringified_source("STARTUP-TYPE-PREDICATES", NULL, "(DEFUN STARTUP-TYPE-PREDICATES ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CLASS-HIERARCHY-BOOTED?* BOOLEAN FALSE)");
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

