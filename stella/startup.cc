// startup.cc

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

int oSTELLA_MAJOR_VERSION_NUMBERo = 1;

int oSTELLA_MINOR_VERSION_NUMBERo = 2;

char* oSTELLA_RELEASE_STATEo = ".alpha";

int oSTELLA_PATCH_LEVELo = 1;

char* oSTELLA_VERSION_STRINGo = NULL;

List* oSTARTUP_TIME_PHASESo = NULL;

Keyword* KWD_STARTUP_EARLY_INITS = NULL;

Keyword* KWD_STARTUP_MODULES = NULL;

Keyword* KWD_STARTUP_SYMBOLS = NULL;

Keyword* KWD_STARTUP_QUOTED_CONSTANTS = NULL;

Keyword* KWD_STARTUP_GLOBALS = NULL;

Keyword* KWD_STARTUP_CLASSES = NULL;

Keyword* KWD_STARTUP_FINALIZE_CLASSES = NULL;

Keyword* KWD_STARTUP_METHODS = NULL;

Keyword* KWD_STARTUP_FINALIZE_METHODS = NULL;

Keyword* KWD_STARTUP_FINAL = NULL;

int oSTARTUP_TIME_PHASEo = 999;

boolean current_startup_time_phaseP(int phase) {
  return ((oSTARTUP_TIME_PHASEo == 999) ||
      (phase == oSTARTUP_TIME_PHASEo));
}

int encode_startup_time_phase(Keyword* phase) {
  { int startuptimephaseasnumber = 0;

    if (!(oSTARTUP_TIME_PHASESo->memberP(phase))) {
      phase = KWD_STARTUP_FINAL;
    }
    { Keyword* ph = NULL;
      Cons* iter_001 = oSTARTUP_TIME_PHASESo->the_cons_list;

      while (!nilP(iter_001)) {
        {
          ph = ((Keyword*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (ph == phase) {
          return (startuptimephaseasnumber);
        }
        else {
          startuptimephaseasnumber = startuptimephaseasnumber + 1;
        }
      }
    }
  }
}

void startup_kernel(boolean verboseP) {
  { int phase = NULL_INTEGER;
    int iter_001 = 0;
    int upper_bound_001 = 9;
    boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

    while (unboundedP_001 ||
        (iter_001 <= upper_bound_001)) {
      {
        phase = iter_001;
        iter_001 = iter_001 + 1;
      }
      oSTARTUP_TIME_PHASEo = phase;
      if (verboseP) {
        if (phase == 0) {
        }
        else if (phase == 2) {
          cout << "Running kernel startup code..." << endl;
          cout << "Initializing symbol tables..." << endl;
        }
        else if (phase == 3) {
          cout << "Initializing quoted constants..." << endl;
        }
        else if (phase == 4) {
          cout << "Initializing global variables..." << endl;
        }
        else if (phase == 5) {
          cout << "Creating class objects..." << endl;
        }
        else if (phase == 6) {
          cout << "Finalizing classes..." << endl;
        }
        else if (phase == 7) {
          cout << "Creating method objects..." << endl;
        }
        else if (phase == 8) {
          cout << "Finalizing methods..." << endl;
        }
        else if (phase == 9) {
          cout << "Running non-phased startup code..." << endl;
        }
      }
      if (phase == 6) {
        finalize_classes();
        oCLASS_HIERARCHY_BOOTEDpo = TRUE;
        continue;
      }
      if (phase == 8) {
        finalize_slots();
        cleanup_unfinalized_classes();
        continue;
      }
      startup_startup();
      startup_primal();
      startup_cpp_primal();      startup_type_predicates();
      startup_conses();
      startup_hierarchy();
      startup_taxonomies();
      startup_lists();
      startup_collections();
      startup_iterators();
      startup_symbols();
      startup_boot_symbols();
      startup_literals();
      startup_classes();
      startup_methods();
      startup_defclass();
      startup_stella_in();
      startup_foreach();
      startup_walk();
      startup_dynamic_slots();
      startup_dynamic_literal_slots();
      startup_cl_translate();
      startup_macros();
      startup_streams();
      startup_describe();
      startup_demons();
      startup_more_demons();
      startup_modules();
      startup_contexts();
      startup_read();
    }
  }
}

void startup_cpp_translator(boolean verboseP) {
  if (verboseP) {
    cout << "Starting up C++ translator..." << endl;
  }
  startup_cpp_translate();
  startup_cpp_class_out();
  startup_cpp_output();
  startup_cpp_translate_file();
}

void startup_java_translator(boolean verboseP) {
  if (verboseP) {
    cout << "Starting up Java translator..." << endl;
  }
  startup_java_translate();
  startup_java_class_out();
  startup_java_output();
  startup_java_translate_file();
}

void startup_idl_translator(boolean verboseP) {
  if (verboseP) {
    cout << "Starting up IDL translator..." << endl;
  }
  startup_idl_translate();
  startup_idl_class_out();
  startup_idl_output();
  startup_idl_translate_file();
}

void startup(boolean verboseP) {
  startup_kernel(verboseP);
  oSTARTUP_TIME_PHASEo = 999;
  if (verboseP) {
    cout << "Starting up CL translator..." << endl;
  }
  startup_translate_file();
  startup_cl_translate_file();
  startup_cpp_translator(verboseP);
  startup_java_translator(verboseP);
  startup_idl_translator(verboseP);
  if (verboseP) {
    cout << "Starting up your-files..." << endl;
  }
  startup_your_file();
  startup_your_file2();
  sweep_transients();
  if (verboseP) {
    cout << "Welcome to " << "`" << oSTELLA_VERSION_STRINGo << "'" << endl;
  }
}

void startup_startup() {
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
            KWD_STARTUP_EARLY_INITS = ((Keyword*)(intern_rigid_symbol_wrt_module("EARLY-INITS", NULL, 2)));
            KWD_STARTUP_MODULES = ((Keyword*)(intern_rigid_symbol_wrt_module("MODULES", NULL, 2)));
            KWD_STARTUP_SYMBOLS = ((Keyword*)(intern_rigid_symbol_wrt_module("SYMBOLS", NULL, 2)));
            KWD_STARTUP_QUOTED_CONSTANTS = ((Keyword*)(intern_rigid_symbol_wrt_module("QUOTED-CONSTANTS", NULL, 2)));
            KWD_STARTUP_GLOBALS = ((Keyword*)(intern_rigid_symbol_wrt_module("GLOBALS", NULL, 2)));
            KWD_STARTUP_CLASSES = ((Keyword*)(intern_rigid_symbol_wrt_module("CLASSES", NULL, 2)));
            KWD_STARTUP_FINALIZE_CLASSES = ((Keyword*)(intern_rigid_symbol_wrt_module("FINALIZE-CLASSES", NULL, 2)));
            KWD_STARTUP_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("METHODS", NULL, 2)));
            KWD_STARTUP_FINALIZE_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("FINALIZE-METHODS", NULL, 2)));
            KWD_STARTUP_FINAL = ((Keyword*)(intern_rigid_symbol_wrt_module("FINAL", NULL, 2)));
          }
          if (current_startup_time_phaseP(4)) {
            oSTELLA_VERSION_STRINGo = string_concatenate("STELLA ", string_concatenate(integer_to_string(oSTELLA_MAJOR_VERSION_NUMBERo), string_concatenate(".", string_concatenate(integer_to_string(oSTELLA_MINOR_VERSION_NUMBERo), string_concatenate(oSTELLA_RELEASE_STATEo, string_concatenate(" (patch-level ", string_concatenate(integer_to_string(oSTELLA_PATCH_LEVELo), ")")))))));
            oSTARTUP_TIME_PHASESo = ((List*)(list(10, KWD_STARTUP_EARLY_INITS, KWD_STARTUP_MODULES, KWD_STARTUP_SYMBOLS, KWD_STARTUP_QUOTED_CONSTANTS, KWD_STARTUP_GLOBALS, KWD_STARTUP_CLASSES, KWD_STARTUP_FINALIZE_CLASSES, KWD_STARTUP_METHODS, KWD_STARTUP_FINALIZE_METHODS, KWD_STARTUP_FINAL)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("CURRENT-STARTUP-TIME-PHASE?", "INTEGER", "(DEFUN (CURRENT-STARTUP-TIME-PHASE? BOOLEAN) ((PHASE INTEGER)))");

              method->function_code = ((cpp_function_code)(&current_startup_time_phaseP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ENCODE-STARTUP-TIME-PHASE", "KEYWORD", "(DEFUN (ENCODE-STARTUP-TIME-PHASE INTEGER) ((PHASE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&encode_startup_time_phase));
            }
            { Method_Slot* method = define_method_from_stringified_source("STARTUP-KERNEL", "BOOLEAN", "(DEFUN STARTUP-KERNEL ((VERBOSE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&startup_kernel));
            }
            { Method_Slot* method = define_method_from_stringified_source("STARTUP-CPP-TRANSLATOR", "BOOLEAN", "(DEFUN STARTUP-CPP-TRANSLATOR ((VERBOSE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&startup_cpp_translator));
            }
            { Method_Slot* method = define_method_from_stringified_source("STARTUP-JAVA-TRANSLATOR", "BOOLEAN", "(DEFUN STARTUP-JAVA-TRANSLATOR ((VERBOSE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&startup_java_translator));
            }
            { Method_Slot* method = define_method_from_stringified_source("STARTUP-IDL-TRANSLATOR", "BOOLEAN", "(DEFUN STARTUP-IDL-TRANSLATOR ((VERBOSE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&startup_idl_translator));
            }
            { Method_Slot* method = define_method_from_stringified_source("STARTUP", "BOOLEAN", "(DEFUN STARTUP ((VERBOSE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&startup));
            }
            define_method_from_stringified_source("STARTUP-STARTUP", NULL, "(DEFUN STARTUP-STARTUP ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-MAJOR-VERSION-NUMBER* INTEGER 1)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-MINOR-VERSION-NUMBER* INTEGER 2)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-RELEASE-STATE* STRING \".alpha\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-PATCH-LEVEL* INTEGER 1)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-VERSION-STRING* STRING (CONCATENATE \"STELLA \" (CONCATENATE (INTEGER-TO-STRING *STELLA-MAJOR-VERSION-NUMBER*) (CONCATENATE \".\" (CONCATENATE (INTEGER-TO-STRING *STELLA-MINOR-VERSION-NUMBER*) (CONCATENATE *STELLA-RELEASE-STATE* (CONCATENATE \" (patch-level \" (CONCATENATE (INTEGER-TO-STRING *STELLA-PATCH-LEVEL*) \")\"))))))))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STARTUP-TIME-PHASES* (LIST OF KEYWORD) (CAST (LIST :EARLY-INITS :MODULES :SYMBOLS :QUOTED-CONSTANTS :GLOBALS :CLASSES :FINALIZE-CLASSES :METHODS :FINALIZE-METHODS :FINAL) (LIST OF KEYWORD)) :DOCUMENTATION \"List of phases that can be legally used as an optional\nphase argument to a 'startup-time-progn' form.  The corresponding code\nwill be executed during the execution of a startup-time-code function only\nif the position of the keyword in the list corresponds to the current value of\n'*startup-time-phase*', or if phasing of startup-time code is disabled.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STARTUP-TIME-PHASE* INTEGER 999 :DOCUMENTATION \"The current phase during 'phased startup'.\nThe value has to correspond to the position of one of the keywords\nin '*startup-time-phases*'.  999 means no phasing at all.\")");
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

