// cl-translate-file.cc

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

char* oCL_TRANSLATED_FILE_SUFFIXo = ".lisp";

char* oSTELLA_TRANSLATED_FILE_SUFFIXo = ".ste";

Symbol* SYM_CL_TRANSLATE_FILE_GLOBAL_VARIABLE = NULL;

Symbol* SYM_CL_TRANSLATE_FILE_CLASS = NULL;

Keyword* KWD_CL_TRANSLATE_FILE_COMMON_LISP = NULL;

Keyword* KWD_CL_TRANSLATE_FILE_TRANSLATE = NULL;

Keyword* KWD_CL_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER = NULL;

Keyword* KWD_CL_TRANSLATE_FILE_WARN_ABOUT_MISSING_METHODS = NULL;

Keyword* KWD_CL_TRANSLATE_FILE_WARN_ABOUT_UNDEFINED_METHODS = NULL;

Keyword* KWD_CL_TRANSLATE_FILE_USE_HARDCODED_SYMBOLS = NULL;

Symbol* SYM_CL_TRANSLATE_FILE_STARTUP = NULL;

char* cl_make_output_file_name(char* sourcefile) {
  return (string_concatenate(file_name_without_type(sourcefile), oCL_TRANSLATED_FILE_SUFFIXo));
}

char* stella_make_output_file_name(char* sourcefile) {
  return (string_concatenate(file_name_without_type(sourcefile), oSTELLA_TRANSLATED_FILE_SUFFIXo));
}

boolean auxiliary_variable_unitP(Translation_Unit* unit) {
  return (unit->auxiliaryP &&
      (unit->category == SYM_CL_TRANSLATE_FILE_GLOBAL_VARIABLE));
}

void cl_output_one_unit(Translation_Unit* unit, ostream* stream) {
  if (unit->category != NULL) {
    if (!(auxiliary_variable_unitP(unit))) {
      *(stream) << endl;
    }
    if (unit->annotation != NULL) {
      *(stream) << ";;; " << unit->annotation << endl << endl;
    }
    print_stella_definition(unit->translation, stream);
    unit->category = NULL;
  }
}

void cl_output_all_units_to_file(char* sourcefile) {
  { char* outputfile = cl_make_output_file_name(sourcefile);
    Output_File_Stream* outputstream = new_output_file_stream(outputfile);
    ostream* nativeoutputstream = outputstream->native_stream;

    cl_output_file_header(outputstream, oMODULEo->native_package(), translate_with_copyright_headerP(), TRUE);
    *(nativeoutputstream) << ";;; Auxiliary variables:" << endl << endl;
    { Translation_Unit* unit = NULL;
      Cons* iter_001 = oTRANSLATIONUNITSo->the_cons_list;

      while (!nilP(iter_001)) {
        {
          unit = ((Translation_Unit*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (auxiliary_variable_unitP(unit)) {
          cl_output_one_unit(unit, nativeoutputstream);
        }
      }
    }
    cl_output_forward_declarations(nativeoutputstream);
    if (use_cl_structsP() &&
        (!use_vector_structsP())) {
      { Translation_Unit* unit = NULL;
        Cons* iter_002 = oTRANSLATIONUNITSo->the_cons_list;

        while (!nilP(iter_002)) {
          {
            unit = ((Translation_Unit*)(iter_002->value));
            iter_002 = iter_002->rest;
          }
          if (unit->category == SYM_CL_TRANSLATE_FILE_CLASS) {
            cl_output_one_unit(unit, nativeoutputstream);
          }
        }
      }
    }
    { Translation_Unit* unit = NULL;
      Cons* iter_003 = oTRANSLATIONUNITSo->the_cons_list;

      while (!nilP(iter_003)) {
        {
          unit = ((Translation_Unit*)(iter_003->value));
          iter_003 = iter_003->rest;
        }
        if (!auxiliary_variable_unitP(unit)) {
          cl_output_one_unit(unit, nativeoutputstream);
        }
      }
    }
    outputstream->free();
  }
}

void cl_output_file_header(Output_Stream* stream, char* package, boolean copyrightP, boolean ensurepackageP) {
  *(stream->native_stream) << ";;; -*- Mode: Lisp; Package: " << package << "; Syntax: COMMON-LISP; Base: 10 -*-" << endl << endl;
  if (copyrightP) {
    output_copyright_header(stream);
  }
  if (!(string_eqlP(package, "STELLA") ||
      (!ensurepackageP))) {
    *(stream->native_stream) << "#.(CL:UNLESS (CL:FIND-PACKAGE \"" << package << "\")" << endl << "     '(CL:DEFPACKAGE \"" << package << "\"))" << endl << endl;
  }
  *(stream->native_stream) << "(CL:IN-PACKAGE \"" << package << "\")" << endl << endl;
}

void cl_output_forward_declarations(ostream* stream) {
  { List* definedvariables = new_list();
    List* forwardreferencedvariables = new_list();

    { Translation_Unit* unit = NULL;
      Cons* iter_001 = oTRANSLATIONUNITSo->the_cons_list;

      while (!nilP(iter_001)) {
        {
          unit = ((Translation_Unit*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (auxiliary_variable_unitP(unit)) {
          definedvariables->push(unit->the_object);
        }
      }
    }
    { Translation_Unit* unit = NULL;
      Cons* iter_002 = oTRANSLATIONUNITSo->the_cons_list;

      while (!nilP(iter_002)) {
        {
          unit = ((Translation_Unit*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        if (!auxiliary_variable_unitP(unit)) {
          if (unit->category == SYM_CL_TRANSLATE_FILE_GLOBAL_VARIABLE) {
            definedvariables->push(unit->the_object);
          }
          { Global_Variable* variable = NULL;
            Cons* iter_003 = unit->referenced_globals->the_cons_list;

            while (!nilP(iter_003)) {
              {
                variable = ((Global_Variable*)(iter_003->value));
                iter_003 = iter_003->rest;
              }
              if ((!definedvariables->memberP(variable)) &&
                  (!forwardreferencedvariables->memberP(variable))) {
                forwardreferencedvariables->push(variable);
              }
            }
          }
        }
      }
    }
    { List_Iterator* it = ((List_Iterator*)(forwardreferencedvariables->allocate_iterator()));

      while (it->nextP()) {
        it->value_setter(((Global_Variable*)(it->value))->variable_name);
      }
    }
    if (forwardreferencedvariables->non_emptyP()) {
      *(stream) << endl << ";;; Forward declarations:" << endl << endl;
      print_stella_definition(listO(3, intern_common_lisp_symbol("DECLAIM"), cons(intern_common_lisp_symbol("SPECIAL"), cl_translate_list_of_trees(forwardreferencedvariables->the_cons_list)->concatenate(NIL)), NIL), stream);
    }
    definedvariables->free();
    forwardreferencedvariables->free();
  }
}

void cl_translate_file(char* file) {
  // Translate a Stella 'file' to Common-Lisp.
  { Keyword* oldoutputlanguage = translator_output_language();

    set_translator_output_language(KWD_CL_TRANSLATE_FILE_COMMON_LISP);
    operate_on_file(file, KWD_CL_TRANSLATE_FILE_TRANSLATE);
    set_translator_output_language(oldoutputlanguage);
  }
}

void cl_translate_stella() {
  oGENSYM_COUNTERo = -1;
  enable_environment_feature(3, KWD_CL_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER, KWD_CL_TRANSLATE_FILE_WARN_ABOUT_MISSING_METHODS, KWD_CL_TRANSLATE_FILE_WARN_ABOUT_UNDEFINED_METHODS);
  disable_environment_feature(1, KWD_CL_TRANSLATE_FILE_USE_HARDCODED_SYMBOLS);
  { Keyword* oldoutputlanguage = translator_output_language();
    char* bootsymbolsfile = ((directory_separator() == ';') ? ((char*)("PL:sources;stella;boot-symbols.ste")) : ((char*)("boot-symbols.ste")));

    set_translator_output_language(KWD_CL_TRANSLATE_FILE_COMMON_LISP);
    { int old_OsafetyO_001 = oSAFETYo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oSAFETYo = 1;
            simple_translate_system(stella_files(KWD_CL_TRANSLATE_FILE_COMMON_LISP), SYM_CL_TRANSLATE_FILE_STARTUP->lookup_function() == NULL, TRUE);
            create_symbol_startup_file(bootsymbolsfile);
            cl_translate_file(bootsymbolsfile);
            oSAFETYo = old_OsafetyO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oSAFETYo = old_OsafetyO_001;
          resignal();
        }
      }
    }
    set_translator_output_language(oldoutputlanguage);
    disable_environment_feature(1, KWD_CL_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER);
  }
}

void cl_compile_and_load_file(char* file, int args, ...) {
  { boolean callstartupfunctionP = TRUE;

    { va_list ap;
      Object* arg;

      va_start(ap, args);
      while (args > 0) {
        arg = va_arg(ap, Object*);
        args = args - 1;
        if (eqlP(FALSE_WRAPPER, arg) ||
            NULL) {
          callstartupfunctionP = FALSE;
        }
      }
      va_end(ap);
    }
  }
}

void startup_cl_translate_file() {
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
            SYM_CL_TRANSLATE_FILE_GLOBAL_VARIABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("GLOBAL-VARIABLE", NULL, 0)));
            SYM_CL_TRANSLATE_FILE_CLASS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS", NULL, 0)));
            KWD_CL_TRANSLATE_FILE_COMMON_LISP = ((Keyword*)(intern_rigid_symbol_wrt_module("COMMON-LISP", NULL, 2)));
            KWD_CL_TRANSLATE_FILE_TRANSLATE = ((Keyword*)(intern_rigid_symbol_wrt_module("TRANSLATE", NULL, 2)));
            KWD_CL_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER = ((Keyword*)(intern_rigid_symbol_wrt_module("TRANSLATE-WITH-COPYRIGHT-HEADER", NULL, 2)));
            KWD_CL_TRANSLATE_FILE_WARN_ABOUT_MISSING_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("WARN-ABOUT-MISSING-METHODS", NULL, 2)));
            KWD_CL_TRANSLATE_FILE_WARN_ABOUT_UNDEFINED_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("WARN-ABOUT-UNDEFINED-METHODS", NULL, 2)));
            KWD_CL_TRANSLATE_FILE_USE_HARDCODED_SYMBOLS = ((Keyword*)(intern_rigid_symbol_wrt_module("USE-HARDCODED-SYMBOLS", NULL, 2)));
            SYM_CL_TRANSLATE_FILE_STARTUP = ((Symbol*)(intern_rigid_symbol_wrt_module("STARTUP", NULL, 0)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("CL-MAKE-OUTPUT-FILE-NAME", "FILE-NAME", "(DEFUN (CL-MAKE-OUTPUT-FILE-NAME FILE-NAME) ((SOURCEFILE FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&cl_make_output_file_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("STELLA-MAKE-OUTPUT-FILE-NAME", "FILE-NAME", "(DEFUN (STELLA-MAKE-OUTPUT-FILE-NAME FILE-NAME) ((SOURCEFILE FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&stella_make_output_file_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("AUXILIARY-VARIABLE-UNIT?", "TRANSLATION-UNIT", "(DEFUN (AUXILIARY-VARIABLE-UNIT? BOOLEAN) ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&auxiliary_variable_unitP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-OUTPUT-ONE-UNIT", "TRANSLATION-UNIT", "(DEFUN CL-OUTPUT-ONE-UNIT ((UNIT TRANSLATION-UNIT) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&cl_output_one_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-OUTPUT-ALL-UNITS-TO-FILE", "FILE-NAME", "(DEFUN CL-OUTPUT-ALL-UNITS-TO-FILE ((SOURCEFILE FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&cl_output_all_units_to_file));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-OUTPUT-FILE-HEADER", "OUTPUT-STREAM", "(DEFUN CL-OUTPUT-FILE-HEADER ((STREAM OUTPUT-STREAM) (PACKAGE STRING) (COPYRIGHT? BOOLEAN) (ENSUREPACKAGE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&cl_output_file_header));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-OUTPUT-FORWARD-DECLARATIONS", "NATIVE-OUTPUT-STREAM", "(DEFUN CL-OUTPUT-FORWARD-DECLARATIONS ((STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&cl_output_forward_declarations));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-FILE", "FILE-NAME", "(DEFUN CL-TRANSLATE-FILE ((FILE FILE-NAME)) :DOCUMENTATION \"Translate a Stella 'file' to Common-Lisp.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&cl_translate_file));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-STELLA", NULL, "(DEFUN CL-TRANSLATE-STELLA ())");

              method->function_code = ((cpp_function_code)(&cl_translate_stella));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-COMPILE-AND-LOAD-FILE", "STRING", "(DEFUN CL-COMPILE-AND-LOAD-FILE ((FILE STRING) |&REST| (ARGS OBJECT)))");

              method->function_code = ((cpp_function_code)(&cl_compile_and_load_file));
            }
            define_method_from_stringified_source("STARTUP-CL-TRANSLATE-FILE", NULL, "(DEFUN STARTUP-CL-TRANSLATE-FILE ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CL-TRANSLATED-FILE-SUFFIX* STRING \".lisp\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-TRANSLATED-FILE-SUFFIX* STRING \".ste\")");
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

