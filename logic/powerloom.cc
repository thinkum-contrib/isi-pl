// powerloom.cc

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

int oPOWERLOOM_MAJOR_VERSION_NUMBERo = 1;

int oPOWERLOOM_MINOR_VERSION_NUMBERo = 0;

char* oPOWERLOOM_RELEASE_STATEo = ".alpha";

int oPOWERLOOM_PATCH_LEVELo = 1;

char* oPOWERLOOM_VERSION_STRINGo = NULL;

char* oPOWERLOOM_COPYRIGHT_HEADERo = "--------------------------------------------------------------------------+\n |                                                                          |\n |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | \n |  University of Southern California, Information Sciences Institute       |\n |  4676 Admiralty Way                                                      |\n |  Marina Del Rey, California 90292                                        |\n |                                                                          |\n |  This software was developed under the terms and conditions of Contract  |\n |  No. N00014-94-C-0245 between the Defense Advanced Research Projects     |\n |  Agency and the University of Southern California, Information Sciences  | \n |  Institute.  Use and distribution of this software is further subject    |\n |  to the provisions of that contract and any other agreements developed   |\n |  between the user of the software and the University of Southern         |\n |  California, Information Sciences Institute.  It is supplied \"AS IS\",    |\n |  without any warranties of any kind.  It is furnished only on the basis  |\n |  that any party who receives it indemnifies and holds harmless the       |\n |  parties who furnish and originate it against any claims, demands, or    |\n |  liabilities connected with using it, furnishing it to others or         |\n |  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    |\n |  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  |\n |  BE ATTACHED TO EVERY PART.                                              |\n |                                                                          |\n +--------------------------------------------------------------------------";

void copyright() {
  // Print detailed PowerLoom copyright information.
  cout << " +" << oPOWERLOOM_COPYRIGHT_HEADERo << "+" << endl;
}

char* copyright_years() {
  { int start = string_search(oPOWERLOOM_COPYRIGHT_HEADERo, "1997", 0);
    int end = string_search(oPOWERLOOM_COPYRIGHT_HEADERo, "  ", start);

    return (string_subsequence(oPOWERLOOM_COPYRIGHT_HEADERo, start, end));
  }
}

void powerloom() {
  // Run the PowerLoom listener.  Read logic commands from the
  // standard input, evaluate them, and print their results.  Exit if the user
  // entered `bye', `exit', `halt', `quit', or `stop'.
  cout << endl << "    Welcome to " << oPOWERLOOM_VERSION_STRINGo << endl << endl << "Copyright (C) USC Information Sciences Institute, " << copyright_years() << "." << endl << "PowerLoom comes with ABSOLUTELY NO WARRANTY!" << endl << "Type `(copyright)' for detailed copyright information." << endl << "Type `(help)' for a list of available commands." << endl << "Type `(demo)' for a list of example applications." << endl << "Type `bye', `exit', `halt', `quit', or `stop', to exit." << endl << endl;
  {
    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;
      boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      oPENDINGEXCEPTIONHANDLERpo = TRUE;
      if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        logic_command_loop();
        oEXCEPTIONo = NULL;
      }
      oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        { Exception* e = oEXCEPTIONo;

          cerr << "Caught " << "`" << e->primary_type() << "'" << " at top level." << endl << "Exiting PowerLoom." << endl;
        }
      }
    }
  }
  cout << "Bye." << endl << endl;
}

void startup_logic() {
  startup_logic_macros();
  startup_kif_in();
  startup_propositions();
  startup_caches();
  startup_descriptions();
  startup_query();
  startup_rules();
  startup_partial_match();
  startup_kif_out();
  startup_print();
  startup_specialize();
  startup_optimize();
  startup_normalize();
  startup_logic_in();
  startup_api_support();
  startup_api();
  startup_powerloom();
}

int main() {
  // Main PowerLoom entry point for your code in C++.
  cout << "Initializing Stella..." << endl;
  startup(FALSE);
  cout << "Initializing PowerLoom..." << endl;
  startup_logic();
  powerloom();
  return (NULL_INTEGER);
}

void startup_powerloom() {
  { Module* old_OmoduleO_001 = oMODULEo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = string_get_module("/LOGIC", TRUE);
          oCONTEXTo = oMODULEo;
          if (current_startup_time_phaseP(4)) {
            oPOWERLOOM_VERSION_STRINGo = string_concatenate("PowerLoom ", string_concatenate(integer_to_string(oPOWERLOOM_MAJOR_VERSION_NUMBERo), string_concatenate(".", string_concatenate(integer_to_string(oPOWERLOOM_MINOR_VERSION_NUMBERo), string_concatenate(oPOWERLOOM_RELEASE_STATEo, string_concatenate(" (patch-level ", string_concatenate(integer_to_string(oPOWERLOOM_PATCH_LEVELo), ")")))))));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("COPYRIGHT", NULL, "(DEFUN COPYRIGHT () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Print detailed PowerLoom copyright information.\")");

              method->function_code = ((cpp_function_code)(&copyright));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPYRIGHT-YEARS", NULL, "(DEFUN (COPYRIGHT-YEARS STRING) ())");

              method->function_code = ((cpp_function_code)(&copyright_years));
            }
            { Method_Slot* method = define_method_from_stringified_source("POWERLOOM", NULL, "(DEFUN POWERLOOM () :DOCUMENTATION \"Run the PowerLoom listener.  Read logic commands from the\nstandard input, evaluate them, and print their results.  Exit if the user\nentered `bye', `exit', `halt', `quit', or `stop'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&powerloom));
            }
            { Method_Slot* method = define_method_from_stringified_source("STARTUP-LOGIC", NULL, "(DEFUN STARTUP-LOGIC ())");

              method->function_code = ((cpp_function_code)(&startup_logic));
            }
            { Method_Slot* method = define_method_from_stringified_source("MAIN", NULL, "(DEFUN (MAIN INTEGER) () :DOCUMENTATION \"Main PowerLoom entry point for your code in C++.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(NULL));
            }
            define_method_from_stringified_source("STARTUP-POWERLOOM", NULL, "(DEFUN STARTUP-POWERLOOM ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *POWERLOOM-MAJOR-VERSION-NUMBER* INTEGER 1)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *POWERLOOM-MINOR-VERSION-NUMBER* INTEGER 0)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *POWERLOOM-RELEASE-STATE* STRING \".alpha\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *POWERLOOM-PATCH-LEVEL* INTEGER 1)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *POWERLOOM-VERSION-STRING* STRING (CONCATENATE \"PowerLoom \" (CONCATENATE (INTEGER-TO-STRING *POWERLOOM-MAJOR-VERSION-NUMBER*) (CONCATENATE \".\" (CONCATENATE (INTEGER-TO-STRING *POWERLOOM-MINOR-VERSION-NUMBER*) (CONCATENATE *POWERLOOM-RELEASE-STATE* (CONCATENATE \" (patch-level \" (CONCATENATE (INTEGER-TO-STRING *POWERLOOM-PATCH-LEVEL*) \")\"))))))))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *POWERLOOM-COPYRIGHT-HEADER* STRING \"--------------------------------------------------------------------------+\n |                                                                          |\n |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | \n |  University of Southern California, Information Sciences Institute       |\n |  4676 Admiralty Way                                                      |\n |  Marina Del Rey, California 90292                                        |\n |                                                                          |\n |  This software was developed under the terms and conditions of Contract  |\n |  No. N00014-94-C-0245 between the Defense Advanced Research Projects     |\n |  Agency and the University of Southern California, Information Sciences  | \n |  Institute.  Use and distribution of this software is further subject    |\n |  to the provisions of that contract and any other agreements developed   |\n |  between the user of the software and the University of Southern         |\n |  California, Information Sciences Institute.  It is supplied \\\"AS IS\\\",    |\n |  without any warranties of any kind.  It is furnished only on the basis  |\n |  that any party who receives it indemnifies and holds harmless the       |\n |  parties who furnish and originate it against any claims, demands, or    |\n |  liabilities connected with using it, furnishing it to others or         |\n |  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    |\n |  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  |\n |  BE ATTACHED TO EVERY PART.                                              |\n |                                                                          |\n +--------------------------------------------------------------------------\")");
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

