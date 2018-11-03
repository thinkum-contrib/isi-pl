// translate-file.cc

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

boolean oRECORD_SIGNATURESpo = FALSE;

boolean oWALK_WITH_RECORDED_SIGNATURESpo = FALSE;

boolean oUSERECORDEDSIGNATURESpo = FALSE;

Symbol* SYM_TRANSLATE_FILE_oUSERECORDEDSIGNATURESpo = NULL;

Cons* oSTELLA_FILESo = NULL;

Keyword* KWD_TRANSLATE_FILE_COMMON_LISP = NULL;

Keyword* KWD_TRANSLATE_FILE_TRANSLATE = NULL;

Keyword* KWD_TRANSLATE_FILE_CPP = NULL;

Keyword* KWD_TRANSLATE_FILE_CPP_STANDALONE = NULL;

Keyword* KWD_TRANSLATE_FILE_IDL = NULL;

Keyword* KWD_TRANSLATE_FILE_JAVA = NULL;

Keyword* KWD_TRANSLATE_FILE_DEFINE = NULL;

Keyword* KWD_TRANSLATE_FILE_FINALIZE = NULL;

Keyword* KWD_TRANSLATE_FILE_WALK = NULL;

Keyword* KWD_TRANSLATE_FILE_STELLA = NULL;

Keyword* KWD_TRANSLATE_FILE_LISP = NULL;

Keyword* KWD_TRANSLATE_FILE_BINARY = NULL;

Symbol* SYM_TRANSLATE_FILE_STARTUP_TIME_PROGN = NULL;

Keyword* KWD_TRANSLATE_FILE_SYMBOLS = NULL;

Symbol* SYM_TRANSLATE_FILE_NULL = NULL;

char* oCOPYRIGHT_HEADERo = "--------------------------------------------------------------------------+\n |                                                                          |\n |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996, 1997             | \n |  University of Southern California, Information Sciences Institute       |\n |  4676 Admiralty Way                                                      |\n |  Marina Del Rey, California 90292                                        |\n |                                                                          |\n |  This software was developed under the terms and conditions of Contract  |\n |  No. N00014-94-C-0245 between the Defense Advanced Research Projects     |\n |  Agency and the University of Southern California, Information Sciences  | \n |  Institute.  Use and distribution of this software is further subject    |\n |  to the provisions of that contract and any other agreements developed   |\n |  between the user of the software and the University of Southern         |\n |  California, Information Sciences Institute.  It is supplied \"AS IS\",    |\n |  without any warranties of any kind.  It is furnished only on the basis  |\n |  that any party who receives it indemnifies and holds harmless the       |\n |  parties who furnish and originate it against any claims, demands, or    |\n |  liabilities connected with using it, furnishing it to others or         |\n |  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    |\n |  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  |\n |  BE ATTACHED TO EVERY PART.                                              |\n |                                                                          |\n +--------------------------------------------------------------------------";

Keyword* KWD_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER = NULL;

Keyword* KWD_TRANSLATE_FILE_UNIX = NULL;

Keyword* KWD_TRANSLATE_FILE_MAC = NULL;

char TYPE_SEPARATOR = '.';

Symbol* SYM_TRANSLATE_FILE_THE_STRING = NULL;

Symbol* SYM_TRANSLATE_FILE_DELIMITERS = NULL;

Symbol* SYM_TRANSLATE_FILE_CURSOR = NULL;

Symbol* SYM_TRANSLATE_FILE_END = NULL;

Surrogate* SGT_TRANSLATE_FILE_TOKEN_ITERATOR = NULL;

Keyword* oOSo = NULL;

char* oSYSTEMSOURCEDIRECTORYo = "PL:sources;stella;";

Symbol* SYM_TRANSLATE_FILE_oSYSTEMSOURCEDIRECTORYo = NULL;

char* oSYSTEMBINARYDIRECTORYo = "PL:binaries;stella;";

Symbol* SYM_TRANSLATE_FILE_oSYSTEMBINARYDIRECTORYo = NULL;

char* oSTELLA_SOURCE_EXTENSIONo = ".ste";

char* oSTELLA_BINARY_EXTENSIONo = ".fasl";

char* oSTELLA_LISP_EXTENSIONo = ".lisp";

char* oSTELLA_CPP_CODE_EXTENSIONo = ".cc";

char* oSTELLA_CPP_HEADER_EXTENSIONo = ".hh";

char* oSTELLA_JAVA_EXTENSIONo = ".java";

char* oSTELLA_IDL_EXTENSIONo = ".idl";

Keyword* KWD_TRANSLATE_FILE_CPP_CODE = NULL;

Keyword* KWD_TRANSLATE_FILE_CPP_HEADER = NULL;

Keyword* KWD_TRANSLATE_FILE_NONE = NULL;

Keyword* KWD_TRANSLATE_FILE_DIRECTORY = NULL;

boolean read_OuserecordedsignaturesPO() {
  return (oUSERECORDEDSIGNATURESpo);
}

boolean write_OuserecordedsignaturesPO(boolean value) {
  oUSERECORDEDSIGNATURESpo = value;
  return (value);
}

Cons* stella_files(Keyword* outputlanguage) {
  { Cons* stellafiles = oSTELLA_FILESo;

    if (!((outputlanguage == KWD_TRANSLATE_FILE_COMMON_LISP) &&
        (0 == 1))) {
      stellafiles = NIL;
      { Object* file = NULL;
        Cons* iter_001 = oSTELLA_FILESo;
        Cons* collect_001 = NULL;

        while (!nilP(iter_001)) {
          {
            file = iter_001->value;
            iter_001 = iter_001->rest;
          }
          if (!consP(file)) {
            if (collect_001 == NULL) {
              {
                collect_001 = cons(file, NIL);
                if (nilP(stellafiles)) {
                  stellafiles = collect_001;
                }
                else {
                  add_cons_to_end_of_cons_list(stellafiles, collect_001);
                }
              }
            }
            else {
              {
                collect_001->rest = cons(file, NIL);
                collect_001 = collect_001->rest;
              }
            }
          }
        }
      }
    }
    return (stellafiles);
  }
}

boolean handle_in_module_tree(Cons* tree, boolean seeninmoduleP, boolean& return1) {
  { Object* renamed_Operator = tree->first();
    Object* firstarg = NULL;

    { Object* operator_001 = renamed_Operator;

      if (symbolP(renamed_Operator)) {
        { Symbol* renamed_Operator = NULL;

          renamed_Operator = ((Symbol*)(operator_001));
          { char* test_value_001 = renamed_Operator->symbol_name;

            if (string_eqlP(test_value_001, "IN-PACKAGE")) {
              tree->free_parse_tree();
              { boolean return_temp = TRUE;

                return1 = seeninmoduleP;
                return (return_temp);
              }
            }
            else if (string_eqlP(test_value_001, "IN-MODULE")) {
              if (seeninmoduleP) {
                { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_warning();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Ignoring duplicate IN-MODULE declaration: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
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
                { boolean return_temp = TRUE;

                  return1 = seeninmoduleP;
                  return (return_temp);
                }
              }
              firstarg = tree->second();
              { Object* firstarg_001 = firstarg;

                if (stringP(firstarg)) {
                  { String_Wrapper* firstarg = NULL;

                    firstarg = ((String_Wrapper*)(firstarg_001));
                    string_change_module(firstarg->wrapper_value);
                    seeninmoduleP = TRUE;
                  }
                }
                else {
                  { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                    { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oPRINTREADABLYpo = TRUE;
                          signal_translation_warning();
                          if (!(suppress_warningsP())) {
                            print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                            cout << endl << " " << "Ignoring illegal IN-MODULE declaration: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                          }
                          oPRINTREADABLYpo = old_OprintreadablyPO_002;
                        }
                        oEXCEPTIONo = NULL;
                      }
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                    }
                    if (oEXCEPTIONo != NULL) {
                      if (TRUE) {
                        oPRINTREADABLYpo = old_OprintreadablyPO_002;
                        resignal();
                      }
                    }
                  }
                }
              }
              { boolean return_temp = TRUE;

                return1 = seeninmoduleP;
                return (return_temp);
              }
            }
            else if (string_eqlP(test_value_001, "DEFMODULE") ||
                string_eqlP(test_value_001, "VERBATIM")) {
            }
            else {
              if (!(seeninmoduleP)) {
                { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_warning();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Missing IN-MODULE declaration, translating " << "into module STELLA" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_003;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_003;
                      resignal();
                    }
                  }
                }
                string_change_module("/STELLA");
                seeninmoduleP = TRUE;
              }
            }
          }
        }
      }
      else {
      }
    }
    { boolean return_temp = FALSE;

      return1 = seeninmoduleP;
      return (return_temp);
    }
  }
}

void operate_on_file(char* file, Keyword* operation) {
  { boolean needtoggleP = use_bootstrap_translatorP();
    char* targetlanguage = translator_output_language()->symbol_name;
    Module* currentmodule = oMODULEo;
    Context* currentcontext = oCONTEXTo;
    boolean seeninmoduleP = FALSE;
    boolean skipP = FALSE;

    if (operation == NULL) {
      operation = KWD_TRANSLATE_FILE_TRANSLATE;
    }
    { List* old_OtranslationunitsO_001 = oTRANSLATIONUNITSo;
      Keyword* old_OtranslationphaseO_001 = oTRANSLATIONPHASEo;
      int old_OtranslationerrorsO_001 = oTRANSLATIONERRORSo;
      int old_OtranslationwarningsO_001 = oTRANSLATIONWARNINGSo;
      char* old_OcurrentfileO_001 = oCURRENTFILEo;
      Module* old_OmoduleO_001 = oMODULEo;
      Context* old_OcontextO_001 = oCONTEXTo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSLATIONUNITSo = new_list();
            oTRANSLATIONPHASEo = NULL;
            oTRANSLATIONERRORSo = 0;
            oTRANSLATIONWARNINGSo = 0;
            oCURRENTFILEo = file_base_name(file);
            oMODULEo = currentmodule;
            oCONTEXTo = currentcontext;
            if (needtoggleP) {
              toggle_translators();
            }
            { Keyword* test_value_001 = translator_output_language();

              if (test_value_001 == KWD_TRANSLATE_FILE_COMMON_LISP) {
                targetlanguage = "Common Lisp";
              }
              else if ((test_value_001 == KWD_TRANSLATE_FILE_CPP) ||
                  (test_value_001 == KWD_TRANSLATE_FILE_CPP_STANDALONE)) {
                targetlanguage = "C++";
              }
              else if (test_value_001 == KWD_TRANSLATE_FILE_IDL) {
                targetlanguage = "IDL";
              }
              else if (test_value_001 == KWD_TRANSLATE_FILE_JAVA) {
                targetlanguage = "Java";
              }
              else {
              }
            }
            if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
              cout << "Translating file " << "`" << file << "'" << " to " << "`" << targetlanguage << "'" << ":" << endl;
              cout << "*** Pass 1, generating objects..." << endl;
            }
            { Object* tree = NULL;
              S_Expression_Iterator* iter_001 = s_expressions(new_input_file_stream(file));

              while (iter_001->nextP()) {
                {
                  tree = iter_001->value;
                }
                { Object* tree_001 = tree;

                  if (consP(tree)) {
                    { Cons* tree = NULL;

                      tree = ((Cons*)(tree_001));
                      skipP = handle_in_module_tree(tree, seeninmoduleP, seeninmoduleP);
                      if (!(skipP)) {
                        { Keyword* old_OtranslationphaseO_002 = oTRANSLATIONPHASEo;

                          { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                            oEXCEPTIONHANDLERADDRESSo = NULL;
                            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                              {
                                oTRANSLATIONPHASEo = KWD_TRANSLATE_FILE_DEFINE;
                                walk_top_level_tree(tree, TRUE);
                                oTRANSLATIONPHASEo = old_OtranslationphaseO_002;
                              }
                              oEXCEPTIONo = NULL;
                            }
                            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                          }
                          if (oEXCEPTIONo != NULL) {
                            if (TRUE) {
                              oTRANSLATIONPHASEo = old_OtranslationphaseO_002;
                              resignal();
                            }
                          }
                        }
                      }
                    }
                  }
                  else {
                  }
                }
              }
            }
            oTRANSLATIONUNITSo->reverse();
            if (!(operation == KWD_TRANSLATE_FILE_DEFINE)) {
              if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
                cout << "*** Pass 2, finalizing objects..." << endl;
              }
              oTRANSLATIONPHASEo = KWD_TRANSLATE_FILE_FINALIZE;
              finalize_classes_and_slots();
              if (!(operation == KWD_TRANSLATE_FILE_FINALIZE)) {
                if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
                  cout << "*** Pass 3, walking objects..." << endl;
                }
                oTRANSLATIONPHASEo = KWD_TRANSLATE_FILE_WALK;
                if (!(use_hardcoded_symbolsP())) {
                  clear_symbol_registry();
                }
                { boolean old_OuserecordedsignaturesPO_001 = oUSERECORDEDSIGNATURESpo;

                  { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oUSERECORDEDSIGNATURESpo = oWALK_WITH_RECORDED_SIGNATURESpo;
                        walk_all_phase_one_units(startup_function_name(file));
                        oUSERECORDEDSIGNATURESpo = old_OuserecordedsignaturesPO_001;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oUSERECORDEDSIGNATURESpo = old_OuserecordedsignaturesPO_001;
                      resignal();
                    }
                  }
                }
                if (!(operation == KWD_TRANSLATE_FILE_WALK)) {
                  { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

                    { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oTRANSIENTOBJECTSpo = TRUE;
                          if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
                            cout << "*** Pass 4, translating to " << "`" << targetlanguage << "'" << "..." << endl;
                          }
                          oTRANSLATIONPHASEo = KWD_TRANSLATE_FILE_TRANSLATE;
                          translate_all_units();
                          if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
                            cout << "*** Pass 5, writing translation to file..." << endl;
                          }
                          output_all_units_to_file(file);
                          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                        }
                        oEXCEPTIONo = NULL;
                      }
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
                    }
                    if (oEXCEPTIONo != NULL) {
                      if (TRUE) {
                        oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                        resignal();
                      }
                    }
                  }
                }
                if (oRECORD_SIGNATURESpo) {
                  cout << "Recording object signatures..." << endl;
                  record_signatures_of_all_units(file);
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
                unit->free();
              }
            }
            oTRANSLATIONUNITSo->clear();
            sweep_transients();
            if (needtoggleP) {
              toggle_translators();
            }
            summarize_translation_errors();
            oCONTEXTo = old_OcontextO_001;
            oMODULEo = old_OmoduleO_001;
            oCURRENTFILEo = old_OcurrentfileO_001;
            oTRANSLATIONWARNINGSo = old_OtranslationwarningsO_001;
            oTRANSLATIONERRORSo = old_OtranslationerrorsO_001;
            oTRANSLATIONPHASEo = old_OtranslationphaseO_001;
            oTRANSLATIONUNITSo = old_OtranslationunitsO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oCONTEXTo = old_OcontextO_001;
          oMODULEo = old_OmoduleO_001;
          oCURRENTFILEo = old_OcurrentfileO_001;
          oTRANSLATIONWARNINGSo = old_OtranslationwarningsO_001;
          oTRANSLATIONERRORSo = old_OtranslationerrorsO_001;
          oTRANSLATIONPHASEo = old_OtranslationphaseO_001;
          oTRANSLATIONUNITSo = old_OtranslationunitsO_001;
          resignal();
        }
      }
    }
  }
}

void translate_file(char* file, boolean walkonlyP) {
  operate_on_file(file, (walkonlyP ? ((Keyword*)(KWD_TRANSLATE_FILE_WALK)) : ((Keyword*)(KWD_TRANSLATE_FILE_TRANSLATE))));
}

boolean stella_need_to_translateP(Object* file) {
  { char* sourcefile = make_file_name(file, KWD_TRANSLATE_FILE_STELLA, NULL);
    char* translatedfile = make_file_name(file, KWD_TRANSLATE_FILE_LISP, NULL);

    return ((!probe_fileP(translatedfile)) ||
        ((file_write_date(sourcefile) == NULL_INTEGER) ||
         ((file_write_date(translatedfile) == NULL_INTEGER) ||
          (file_write_date(translatedfile) < file_write_date(sourcefile)))));
  }
}

boolean stella_need_to_compileP(Object* file) {
  { char* sourcefile = make_file_name(file, KWD_TRANSLATE_FILE_LISP, NULL);
    char* compiledfile = make_file_name(file, KWD_TRANSLATE_FILE_BINARY, NULL);

    return ((!probe_fileP(compiledfile)) ||
        ((file_write_date(sourcefile) == NULL_INTEGER) ||
         ((file_write_date(compiledfile) == NULL_INTEGER) ||
          (file_write_date(compiledfile) < file_write_date(sourcefile)))));
  }
}

boolean simple_translate_system(Cons* files, boolean twopassP, boolean forcetranslationP) {
  { char* filename = NULL;
    boolean translatedfileP = FALSE;

    if (twopassP) {
      { Object* file = NULL;
        Cons* iter_001 = files;

        while (!nilP(iter_001)) {
          {
            file = iter_001->value;
            iter_001 = iter_001->rest;
          }
          if (forcetranslationP ||
              stella_need_to_translateP(file)) {
            filename = make_file_name(file, KWD_TRANSLATE_FILE_STELLA, NULL);
            if (!(probe_fileP(filename))) {
              cout << "Warning: File " << "`" << filename << "'" << " does not exist." << endl;
              continue;
            }
            operate_on_file(filename, KWD_TRANSLATE_FILE_DEFINE);
            translatedfileP = TRUE;
          }
        }
      }
      if (translatedfileP) {
        if (oTRANSLATIONVERBOSITYLEVELo >= 1) {
          cout << "*** Pass 2, finalizing objects..." << endl;
        }
        finalize_classes_and_slots();
      }
    }
    { Object* file = NULL;
      Cons* iter_002 = files;

      while (!nilP(iter_002)) {
        {
          file = iter_002->value;
          iter_002 = iter_002->rest;
        }
        if (forcetranslationP ||
            stella_need_to_translateP(file)) {
          filename = make_file_name(file, KWD_TRANSLATE_FILE_STELLA, NULL);
          if (!(probe_fileP(filename))) {
            cout << "Warning: File " << "`" << filename << "'" << " does not exist." << endl;
            continue;
          }
          { Keyword* test_value_001 = translator_output_language();

            if (test_value_001 == KWD_TRANSLATE_FILE_COMMON_LISP) {
              cl_translate_file(filename);
            }
            else if (test_value_001 == KWD_TRANSLATE_FILE_CPP) {
              cpp_translate_file(filename);
            }
            else if (test_value_001 == KWD_TRANSLATE_FILE_JAVA) {
              java_translate_file(filename);
            }
            else if (test_value_001 == KWD_TRANSLATE_FILE_IDL) {
              idl_translate_file(filename);
            }
            else {
              operate_on_file(filename, KWD_TRANSLATE_FILE_TRANSLATE);
            }
          }
        }
      }
    }
    return (translatedfileP);
  }
}

boolean simple_load_system(Cons* files) {
  { boolean translatedfileP = FALSE;

    { Object* file = NULL;
      Cons* iter_001 = files;

      while (!nilP(iter_001)) {
        {
          file = iter_001->value;
          iter_001 = iter_001->rest;
        }
        cl_compile_and_load_file(make_file_name(file, KWD_TRANSLATE_FILE_LISP, NULL), 1, wrap_boolean(TRUE));
        translatedfileP = TRUE;
      }
    }
    return (translatedfileP);
  }
}

void simple_make_clean(Cons* files) {
  { Object* file = NULL;
    Cons* iter_001 = files;

    while (!nilP(iter_001)) {
      {
        file = iter_001->value;
        iter_001 = iter_001->rest;
      }
      delete_file(make_file_name(file, KWD_TRANSLATE_FILE_LISP, NULL));
      delete_file(make_file_name(file, KWD_TRANSLATE_FILE_BINARY, NULL));
    }
  }
}

void make_system(Cons* files, boolean forcerecompilationP) {
  { boolean updatedsystemP = FALSE;

    updatedsystemP = simple_translate_system(files, TRUE, forcerecompilationP);
    updatedsystemP = simple_load_system(files) ||
        updatedsystemP;
  }
}

void make_stella(boolean forcerecompilationP) {
  make_system(oSTELLA_FILESo, forcerecompilationP);
}

void output_all_units_to_file(char* sourcefile) {
  { Keyword* test_value_001 = translator_output_language();

    if (test_value_001 == KWD_TRANSLATE_FILE_COMMON_LISP) {
      cl_output_all_units_to_file(sourcefile);
    }
    else if (test_value_001 == KWD_TRANSLATE_FILE_JAVA) {
      java_output_all_units_to_file(sourcefile);
    }
    else if (test_value_001 == KWD_TRANSLATE_FILE_IDL) {
      idl_output_all_units_to_file(sourcefile);
    }
    else if ((test_value_001 == KWD_TRANSLATE_FILE_CPP) ||
        (test_value_001 == KWD_TRANSLATE_FILE_CPP_STANDALONE)) {
      cpp_output_all_units_to_file(sourcefile);
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

void record_signatures_of_all_units(char* sourcefile) {
}

void create_symbol_startup_file(char* startupfile) {
  { Output_File_Stream* outputstream = new_output_file_stream(startupfile);
    ostream* nativeoutputstream = outputstream->native_stream;

    print_stella_code(get_quoted_tree("((IN-PACKAGE \"STELLA\") \"/STELLA\")", "/STELLA"), nativeoutputstream);
    *(nativeoutputstream) << endl;
    print_stella_code(get_quoted_tree("((IN-MODULE \"/STELLA\") \"/STELLA\")", "/STELLA"), nativeoutputstream);
    *(nativeoutputstream) << endl;
    if (use_hardcoded_symbolsP()) {
      print_stella_code(yield_hardcoded_intern_registered_symbols_tree(), nativeoutputstream);
    }
    else {
      print_stella_code(listO(4, SYM_TRANSLATE_FILE_STARTUP_TIME_PROGN, KWD_TRANSLATE_FILE_SYMBOLS, SYM_TRANSLATE_FILE_NULL, NIL), nativeoutputstream);
    }
    outputstream->free();
  }
}

boolean translate_with_copyright_headerP() {
  return (oCURRENT_ENVIRONMENT_FEATURESo->memberP(KWD_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER));
}

void output_copyright_header(Output_Stream* stream) {
  { Keyword* test_value_001 = translator_output_language();

    if (test_value_001 == KWD_TRANSLATE_FILE_COMMON_LISP) {
      *(stream->native_stream) << "#|";
    }
    else if ((test_value_001 == KWD_TRANSLATE_FILE_JAVA) ||
        ((test_value_001 == KWD_TRANSLATE_FILE_CPP) ||
         (test_value_001 == KWD_TRANSLATE_FILE_CPP_STANDALONE))) {
      *(stream->native_stream) << "/*";
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
  *(stream->native_stream) << oCOPYRIGHT_HEADERo;
  { Keyword* test_value_002 = translator_output_language();

    if (test_value_002 == KWD_TRANSLATE_FILE_COMMON_LISP) {
      *(stream->native_stream) << "|#";
    }
    else if ((test_value_002 == KWD_TRANSLATE_FILE_JAVA) ||
        ((test_value_002 == KWD_TRANSLATE_FILE_CPP) ||
         (test_value_002 == KWD_TRANSLATE_FILE_CPP_STANDALONE))) {
      *(stream->native_stream) << "*/";
    }
    else {
      cerr << "`" << test_value_002 << "'" << " is not a valid case option";
    }
  }
  *(stream->native_stream) << endl << endl;
}

char directory_separator() {
  { Keyword* test_value_001 = translator_output_language();

    if ((test_value_001 == KWD_TRANSLATE_FILE_CPP) ||
        ((test_value_001 == KWD_TRANSLATE_FILE_CPP_STANDALONE) ||
         ((test_value_001 == KWD_TRANSLATE_FILE_IDL) ||
          (test_value_001 == KWD_TRANSLATE_FILE_JAVA)))) {
      if (oOSo == KWD_TRANSLATE_FILE_UNIX) {
        return ('/');
      }
      else if (oOSo == KWD_TRANSLATE_FILE_MAC) {
        return (':');
      }
      else {
        cerr << "`" << oOSo << "'" << " is not a valid case option";
      }
    }
    else if (test_value_001 == KWD_TRANSLATE_FILE_COMMON_LISP) {
      if (oOSo == KWD_TRANSLATE_FILE_UNIX) {
        return ('/');
      }
      else if (oOSo == KWD_TRANSLATE_FILE_MAC) {
        return (':');
      }
      else {
        cerr << "`" << oOSo << "'" << " is not a valid case option";
      }
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

char* file_name_without_directory(char* file) {
  { int start = 0;
    char separator = directory_separator();

    if (string_position(file, ';', 0) != NULL_INTEGER) {
      separator = ';';
    }
    while (string_position(file, separator, start) != NULL_INTEGER) {
      start = string_position(file, separator, start) + 1;
    }
    return (string_subsequence(file, start, NULL_INTEGER));
  }
}

char* file_name_without_type(char* file) {
  { int start = 0;
    int end = NULL_INTEGER;

    while (string_position(file, TYPE_SEPARATOR, start) != NULL_INTEGER) {
      end = string_position(file, TYPE_SEPARATOR, start);
      start = end + 1;
    }
    return (string_subsequence(file, 0, end));
  }
}

char* file_base_name(char* file) {
  return (file_name_without_type(file_name_without_directory(file)));
}

Symbol* startup_function_name(char* sourcefile) {
  return (((Symbol*)(intern_qualified_name(string_concatenate("/STELLA/STARTUP-", string_upcase(file_base_name(sourcefile)))))));
}

Token_Iterator* new_token_iterator() {
  { Token_Iterator* self = NULL;

    self = new Token_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->end = NULL_INTEGER;
    self->cursor = NULL_INTEGER;
    self->delimiters = NULL;
    self->the_string = NULL;
    return (self);
  }
}

Object* access_token_iterator_slot_value(Token_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_TRANSLATE_FILE_THE_STRING) {
    if (setvalueP) {
      self->the_string = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->the_string));
    }
  }
  else if (slotname == SYM_TRANSLATE_FILE_DELIMITERS) {
    if (setvalueP) {
      self->delimiters = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->delimiters));
    }
  }
  else if (slotname == SYM_TRANSLATE_FILE_CURSOR) {
    if (setvalueP) {
      self->cursor = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->cursor));
    }
  }
  else if (slotname == SYM_TRANSLATE_FILE_END) {
    if (setvalueP) {
      self->end = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->end));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Token_Iterator::primary_type() {
  { Token_Iterator* self = this;

    return (SGT_TRANSLATE_FILE_TOKEN_ITERATOR);
  }
}

Token_Iterator* tokenize(char* string, char* delimiters) {
  { Token_Iterator* self_001 = new_token_iterator();

    self_001->the_string = string;
    { Token_Iterator* iterator = self_001;

      iterator->delimiters = delimiters;
      iterator->cursor = 0;
      iterator->end = string_length(string);
      return (iterator);
    }
  }
}

boolean Token_Iterator::nextP() {
  { Token_Iterator* self = this;

    { char* s = self->the_string;
      int pos = self->cursor;
      int closestdelimiter = self->end;

      if (pos < self->end) {
        { char c = NULL_CHARACTER;
          char* vector_001 = self->delimiters;
          int index_001 = 0;
          int length_001 = string_length(vector_001);

          while (index_001 < length_001) {
            {
              c = string_nth(vector_001, index_001);
              index_001 = index_001 + 1;
            }
            closestdelimiter = min(string_position(s, c, pos + 1), closestdelimiter);
          }
        }
        self->value = string_wrap_literal(string_subsequence(s, pos, closestdelimiter));
        self->cursor = 1 + closestdelimiter;
        return (TRUE);
      }
      return (FALSE);
    }
  }
}

Cons* parse_pathname(char* pathname) {
  { Cons* result = NIL;

    { String_Wrapper* token = NULL;
      Token_Iterator* iter_001 = tokenize(pathname, "/");
      Cons* collect_001 = NULL;

      while (iter_001->nextP()) {
        {
          token = iter_001->value;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(token, NIL);
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
            collect_001->rest = cons(token, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    return (result);
  }
}

char* read_OsystemsourcedirectoryO() {
  return (oSYSTEMSOURCEDIRECTORYo);
}

char* write_OsystemsourcedirectoryO(char* value) {
  oSYSTEMSOURCEDIRECTORYo = value;
  return (value);
}

char* read_OsystembinarydirectoryO() {
  return (oSYSTEMBINARYDIRECTORYo);
}

char* write_OsystembinarydirectoryO(char* value) {
  oSYSTEMBINARYDIRECTORYo = value;
  return (value);
}

Cons* separate_last_cons(Cons* conslist, Object*& return1) {
  { Cons* copieditems = copy_cons_list(conslist);
    Cons* reverseditems = NULL;
    Cons* allbutlastitem = NULL;
    Object* lastitem = NULL;

    reverseditems = copieditems->reverse();
    lastitem = reverseditems->value;
    allbutlastitem = reverseditems->rest->reverse();
    if (!(conslist->emptyP())) {
      reverseditems->free_cons();
    }
    { Cons* return_temp = allbutlastitem;

      return1 = lastitem;
      return (return_temp);
    }
  }
}

char* make_file_name(Object* relativepath, Keyword* type, char* root) {
  { String_Wrapper* file = NULL;
    char* directoryseparator = NULL;
    Cons* directories = NIL;
    char* extension = NULL;
    char* result = NULL;

    directoryseparator = make_string(1, directory_separator());
    if (type == KWD_TRANSLATE_FILE_STELLA) {
      extension = oSTELLA_SOURCE_EXTENSIONo;
      if (!(root != NULL)) {
        root = oSYSTEMSOURCEDIRECTORYo;
      }
    }
    else if (type == KWD_TRANSLATE_FILE_LISP) {
      extension = oSTELLA_LISP_EXTENSIONo;
      if (!(root != NULL)) {
        root = oSYSTEMSOURCEDIRECTORYo;
      }
    }
    else if (type == KWD_TRANSLATE_FILE_CPP_CODE) {
      extension = oSTELLA_CPP_CODE_EXTENSIONo;
      if (!(root != NULL)) {
        root = oSYSTEMSOURCEDIRECTORYo;
      }
    }
    else if (type == KWD_TRANSLATE_FILE_CPP_HEADER) {
      extension = oSTELLA_CPP_HEADER_EXTENSIONo;
      if (!(root != NULL)) {
        root = oSYSTEMSOURCEDIRECTORYo;
      }
    }
    else if (type == KWD_TRANSLATE_FILE_JAVA) {
      extension = oSTELLA_JAVA_EXTENSIONo;
      if (!(root != NULL)) {
        root = oSYSTEMSOURCEDIRECTORYo;
      }
    }
    else if (type == KWD_TRANSLATE_FILE_IDL) {
      extension = oSTELLA_IDL_EXTENSIONo;
      if (!(root != NULL)) {
        root = oSYSTEMSOURCEDIRECTORYo;
      }
    }
    else if (type == KWD_TRANSLATE_FILE_NONE) {
      extension = "";
      if (!(root != NULL)) {
        root = oSYSTEMSOURCEDIRECTORYo;
      }
    }
    else if (type == KWD_TRANSLATE_FILE_BINARY) {
      extension = oSTELLA_BINARY_EXTENSIONo;
      if (!(root != NULL)) {
        root = oSYSTEMBINARYDIRECTORYo;
      }
    }
    else if (type == KWD_TRANSLATE_FILE_DIRECTORY) {
      extension = directoryseparator;
      if (!(root != NULL)) {
        root = oSYSTEMBINARYDIRECTORYo;
      }
    }
    else {
      cerr << "`" << type << "'" << " is not a valid case option";
    }
    { Object* relativepath_001 = relativepath;

      if (consP(relativepath)) {
        { Cons* relativepath = NULL;

          relativepath = ((Cons*)(relativepath_001));
          { Cons* value_001 = NULL;
            Object* value_002 = NULL;

            value_001 = separate_last_cons(relativepath, value_002);
            {
              directories = value_001;
              file = ((String_Wrapper*)(value_002));
            }
          }
        }
      }
      else {
        file = ((String_Wrapper*)(relativepath));
        relativepath = NIL;
      }
    }
    result = root;
    { String_Wrapper* directory = NULL;
      Cons* iter_001 = directories;

      while (!nilP(iter_001)) {
        {
          directory = ((String_Wrapper*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        result = string_concatenate(result, string_concatenate(directory->wrapper_value, directoryseparator));
      }
    }
    result = string_concatenate(result, string_concatenate(file->wrapper_value, extension));
    if (directories->non_emptyP()) {
      free_cons_list(directories);
    }
    return (result);
  }
}

char* reroot_file_name(char* file, char* fromroot, char* toroot) {
  { boolean absoluteP = string_search(file, fromroot, 0) == 0;

    if (absoluteP) {
      if (string_eqlP(fromroot, toroot)) {
        return (file);
      }
      else {
        return (string_concatenate(toroot, string_subsequence(file, string_length(fromroot), NULL_INTEGER)));
      }
    }
    else {
      return (string_concatenate(toroot, file));
    }
  }
}

void startup_translate_file() {
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
            SYM_TRANSLATE_FILE_oUSERECORDEDSIGNATURESpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*USERECORDEDSIGNATURES?*", NULL, 0)));
            KWD_TRANSLATE_FILE_COMMON_LISP = ((Keyword*)(intern_rigid_symbol_wrt_module("COMMON-LISP", NULL, 2)));
            KWD_TRANSLATE_FILE_TRANSLATE = ((Keyword*)(intern_rigid_symbol_wrt_module("TRANSLATE", NULL, 2)));
            KWD_TRANSLATE_FILE_CPP = ((Keyword*)(intern_rigid_symbol_wrt_module("CPP", NULL, 2)));
            KWD_TRANSLATE_FILE_CPP_STANDALONE = ((Keyword*)(intern_rigid_symbol_wrt_module("CPP-STANDALONE", NULL, 2)));
            KWD_TRANSLATE_FILE_IDL = ((Keyword*)(intern_rigid_symbol_wrt_module("IDL", NULL, 2)));
            KWD_TRANSLATE_FILE_JAVA = ((Keyword*)(intern_rigid_symbol_wrt_module("JAVA", NULL, 2)));
            KWD_TRANSLATE_FILE_DEFINE = ((Keyword*)(intern_rigid_symbol_wrt_module("DEFINE", NULL, 2)));
            KWD_TRANSLATE_FILE_FINALIZE = ((Keyword*)(intern_rigid_symbol_wrt_module("FINALIZE", NULL, 2)));
            KWD_TRANSLATE_FILE_WALK = ((Keyword*)(intern_rigid_symbol_wrt_module("WALK", NULL, 2)));
            KWD_TRANSLATE_FILE_STELLA = ((Keyword*)(intern_rigid_symbol_wrt_module("STELLA", NULL, 2)));
            KWD_TRANSLATE_FILE_LISP = ((Keyword*)(intern_rigid_symbol_wrt_module("LISP", NULL, 2)));
            KWD_TRANSLATE_FILE_BINARY = ((Keyword*)(intern_rigid_symbol_wrt_module("BINARY", NULL, 2)));
            SYM_TRANSLATE_FILE_STARTUP_TIME_PROGN = ((Symbol*)(intern_rigid_symbol_wrt_module("STARTUP-TIME-PROGN", NULL, 0)));
            KWD_TRANSLATE_FILE_SYMBOLS = ((Keyword*)(intern_rigid_symbol_wrt_module("SYMBOLS", NULL, 2)));
            SYM_TRANSLATE_FILE_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", NULL, 0)));
            KWD_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER = ((Keyword*)(intern_rigid_symbol_wrt_module("TRANSLATE-WITH-COPYRIGHT-HEADER", NULL, 2)));
            KWD_TRANSLATE_FILE_UNIX = ((Keyword*)(intern_rigid_symbol_wrt_module("UNIX", NULL, 2)));
            KWD_TRANSLATE_FILE_MAC = ((Keyword*)(intern_rigid_symbol_wrt_module("MAC", NULL, 2)));
            SYM_TRANSLATE_FILE_THE_STRING = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-STRING", NULL, 0)));
            SYM_TRANSLATE_FILE_DELIMITERS = ((Symbol*)(intern_rigid_symbol_wrt_module("DELIMITERS", NULL, 0)));
            SYM_TRANSLATE_FILE_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CURSOR", NULL, 0)));
            SYM_TRANSLATE_FILE_END = ((Symbol*)(intern_rigid_symbol_wrt_module("END", NULL, 0)));
            SGT_TRANSLATE_FILE_TOKEN_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("TOKEN-ITERATOR", NULL, 1)));
            SYM_TRANSLATE_FILE_oSYSTEMSOURCEDIRECTORYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*SYSTEMSOURCEDIRECTORY*", NULL, 0)));
            SYM_TRANSLATE_FILE_oSYSTEMBINARYDIRECTORYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*SYSTEMBINARYDIRECTORY*", NULL, 0)));
            KWD_TRANSLATE_FILE_CPP_CODE = ((Keyword*)(intern_rigid_symbol_wrt_module("CPP-CODE", NULL, 2)));
            KWD_TRANSLATE_FILE_CPP_HEADER = ((Keyword*)(intern_rigid_symbol_wrt_module("CPP-HEADER", NULL, 2)));
            KWD_TRANSLATE_FILE_NONE = ((Keyword*)(intern_rigid_symbol_wrt_module("NONE", NULL, 2)));
            KWD_TRANSLATE_FILE_DIRECTORY = ((Keyword*)(intern_rigid_symbol_wrt_module("DIRECTORY", NULL, 2)));
          }
          if (current_startup_time_phaseP(4)) {
            oSTELLA_FILESo = listO(47, string_wrap_literal("hierarchy"), string_wrap_literal("taxonomies"), string_wrap_literal("streams"), string_wrap_literal("primal"), listO(3, string_wrap_literal("cl-lib"), string_wrap_literal("cl-primal"), NIL), listO(3, string_wrap_literal("cl-lib"), string_wrap_literal("stella-to-cl"), NIL), string_wrap_literal("type-predicates"), string_wrap_literal("conses"), string_wrap_literal("lists"), string_wrap_literal("collections"), string_wrap_literal("iterators"), string_wrap_literal("symbols"), string_wrap_literal("literals"), string_wrap_literal("classes"), string_wrap_literal("methods"), string_wrap_literal("defclass"), string_wrap_literal("stella-in"), string_wrap_literal("foreach"), string_wrap_literal("walk"), string_wrap_literal("cl-translate"), string_wrap_literal("cl-translate-file"), string_wrap_literal("dynamic-slots"), string_wrap_literal("dynamic-literal-slots"), string_wrap_literal("modules"), string_wrap_literal("contexts"), string_wrap_literal("read"), string_wrap_literal("macros"), string_wrap_literal("demons"), string_wrap_literal("more-demons"), string_wrap_literal("translate-file"), string_wrap_literal("describe"), string_wrap_literal("cpp-translate-file"), string_wrap_literal("cpp-translate"), string_wrap_literal("cpp-class-out"), string_wrap_literal("cpp-output"), string_wrap_literal("java-translate-file"), string_wrap_literal("java-translate"), string_wrap_literal("java-class-out"), string_wrap_literal("java-output"), string_wrap_literal("idl-translate"), string_wrap_literal("idl-class-out"), string_wrap_literal("idl-translate-file"), string_wrap_literal("idl-output"), string_wrap_literal("your-file"), string_wrap_literal("your-file2"), string_wrap_literal("startup"), NIL);
            oOSo = KWD_TRANSLATE_FILE_UNIX;
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("TOKEN-ITERATOR", "(DEFCLASS TOKEN-ITERATOR (ABSTRACT-ITERATOR) :DOCUMENTATION \"Iterator that yields tokens from an input string\" :PARAMETERS ((ANY-VALUE :TYPE STRING-WRAPPER)) :SLOTS ((THE-STRING :TYPE STRING) (DELIMITERS :TYPE STRING) (CURSOR :TYPE INTEGER) (END :TYPE INTEGER)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_token_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_token_iterator_slot_value));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("STELLA-FILES", "KEYWORD", "(DEFUN (STELLA-FILES (CONS OF STRING-WRAPPER)) ((OUTPUTLANGUAGE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&stella_files));
            }
            { Method_Slot* method = define_method_from_stringified_source("HANDLE-IN-MODULE-TREE", "CONS", "(DEFUN (HANDLE-IN-MODULE-TREE BOOLEAN BOOLEAN) ((TREE CONS) (SEENINMODULE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&handle_in_module_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("OPERATE-ON-FILE", "FILE-NAME", "(DEFUN OPERATE-ON-FILE ((FILE FILE-NAME) (OPERATION KEYWORD)))");

              method->function_code = ((cpp_function_code)(&operate_on_file));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSLATE-FILE", "FILE-NAME", "(DEFUN TRANSLATE-FILE ((FILE FILE-NAME) (WALKONLY? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&translate_file));
            }
            { Method_Slot* method = define_method_from_stringified_source("STELLA-NEED-TO-TRANSLATE?", "OBJECT", "(DEFUN (STELLA-NEED-TO-TRANSLATE? BOOLEAN) ((FILE OBJECT)))");

              method->function_code = ((cpp_function_code)(&stella_need_to_translateP));
            }
            { Method_Slot* method = define_method_from_stringified_source("STELLA-NEED-TO-COMPILE?", "OBJECT", "(DEFUN (STELLA-NEED-TO-COMPILE? BOOLEAN) ((FILE OBJECT)))");

              method->function_code = ((cpp_function_code)(&stella_need_to_compileP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMPLE-TRANSLATE-SYSTEM", "CONS", "(DEFUN (SIMPLE-TRANSLATE-SYSTEM BOOLEAN) ((FILES CONS) (TWOPASS? BOOLEAN) (FORCETRANSLATION? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&simple_translate_system));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMPLE-LOAD-SYSTEM", "CONS", "(DEFUN (SIMPLE-LOAD-SYSTEM BOOLEAN) ((FILES CONS)))");

              method->function_code = ((cpp_function_code)(&simple_load_system));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMPLE-MAKE-CLEAN", "CONS", "(DEFUN SIMPLE-MAKE-CLEAN ((FILES CONS)))");

              method->function_code = ((cpp_function_code)(&simple_make_clean));
            }
            { Method_Slot* method = define_method_from_stringified_source("MAKE-SYSTEM", "CONS", "(DEFUN MAKE-SYSTEM ((FILES CONS) (FORCERECOMPILATION? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&make_system));
            }
            { Method_Slot* method = define_method_from_stringified_source("MAKE-STELLA", "BOOLEAN", "(DEFUN MAKE-STELLA ((FORCERECOMPILATION? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&make_stella));
            }
            { Method_Slot* method = define_method_from_stringified_source("OUTPUT-ALL-UNITS-TO-FILE", "FILE-NAME", "(DEFUN OUTPUT-ALL-UNITS-TO-FILE ((SOURCEFILE FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&output_all_units_to_file));
            }
            { Method_Slot* method = define_method_from_stringified_source("RECORD-SIGNATURES-OF-ALL-UNITS", "FILE-NAME", "(DEFUN RECORD-SIGNATURES-OF-ALL-UNITS ((SOURCEFILE FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&record_signatures_of_all_units));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-SYMBOL-STARTUP-FILE", "FILE-NAME", "(DEFUN CREATE-SYMBOL-STARTUP-FILE ((STARTUPFILE FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&create_symbol_startup_file));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSLATE-WITH-COPYRIGHT-HEADER?", NULL, "(DEFUN (TRANSLATE-WITH-COPYRIGHT-HEADER? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&translate_with_copyright_headerP));
            }
            { Method_Slot* method = define_method_from_stringified_source("OUTPUT-COPYRIGHT-HEADER", "OUTPUT-STREAM", "(DEFUN OUTPUT-COPYRIGHT-HEADER ((STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&output_copyright_header));
            }
            { Method_Slot* method = define_method_from_stringified_source("DIRECTORY-SEPARATOR", NULL, "(DEFUN (DIRECTORY-SEPARATOR CHARACTER) ())");

              method->function_code = ((cpp_function_code)(&directory_separator));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILE-NAME-WITHOUT-DIRECTORY", "FILE-NAME", "(DEFUN (FILE-NAME-WITHOUT-DIRECTORY FILE-NAME) ((FILE FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&file_name_without_directory));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILE-NAME-WITHOUT-TYPE", "FILE-NAME", "(DEFUN (FILE-NAME-WITHOUT-TYPE FILE-NAME) ((FILE FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&file_name_without_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILE-BASE-NAME", "FILE-NAME", "(DEFUN (FILE-BASE-NAME FILE-NAME) ((FILE FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&file_base_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("STARTUP-FUNCTION-NAME", "FILE-NAME", "(DEFUN (STARTUP-FUNCTION-NAME SYMBOL) ((SOURCEFILE FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&startup_function_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("TOKENIZE", "STRING", "(DEFUN (TOKENIZE TOKEN-ITERATOR) ((STRING STRING) (DELIMITERS STRING)))");

              method->function_code = ((cpp_function_code)(&tokenize));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "TOKEN-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF TOKEN-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Token_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PARSE-PATHNAME", "STRING", "(DEFUN (PARSE-PATHNAME (CONS OF STRING-WRAPPER)) ((PATHNAME STRING)))");

              method->function_code = ((cpp_function_code)(&parse_pathname));
            }
            { Method_Slot* method = define_method_from_stringified_source("SEPARATE-LAST-CONS", "CONS", "(DEFUN (SEPARATE-LAST-CONS CONS OBJECT) ((CONSLIST CONS)))");

              method->function_code = ((cpp_function_code)(&separate_last_cons));
            }
            { Method_Slot* method = define_method_from_stringified_source("MAKE-FILE-NAME", "OBJECT", "(DEFUN (MAKE-FILE-NAME FILE-NAME) ((RELATIVEPATH OBJECT) (TYPE KEYWORD) (ROOT STRING)))");

              method->function_code = ((cpp_function_code)(&make_file_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("REROOT-FILE-NAME", "FILE-NAME", "(DEFUN (REROOT-FILE-NAME FILE-NAME) ((FILE FILE-NAME) (FROMROOT FILE-NAME) (TOROOT FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&reroot_file_name));
            }
            define_method_from_stringified_source("STARTUP-TRANSLATE-FILE", NULL, "(DEFUN STARTUP-TRANSLATE-FILE ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *RECORD-SIGNATURES?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE, record object signatures into a persistent table.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *WALK-WITH-RECORDED-SIGNATURES?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE, the walker will try to find previously recorded\nsignatures for referenced but undefined functions, methods, etc.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *USERECORDEDSIGNATURES?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE, 'safe-lookup-slot' and 'lookup-function' will\ntry to retrieve a previously recorded signature if normal lookup fails.\")");
            { Global_Variable* global = SYM_TRANSLATE_FILE_oUSERECORDEDSIGNATURESpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OuserecordedsignaturesPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OuserecordedsignaturesPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-FILES* CONS (BQUOTE (\"hierarchy\" \"taxonomies\" \"streams\" \"primal\" (\"cl-lib\" \"cl-primal\") (\"cl-lib\" \"stella-to-cl\") \"type-predicates\" \"conses\" \"lists\" \"collections\" \"iterators\" \"symbols\" \"literals\" \"classes\" \"methods\" \"defclass\" \"stella-in\" \"foreach\" \"walk\" \"cl-translate\" \"cl-translate-file\" \"dynamic-slots\" \"dynamic-literal-slots\" \"modules\" \"contexts\" \"read\" \"macros\" \"demons\" \"more-demons\" \"translate-file\" \"describe\" \"cpp-translate-file\" \"cpp-translate\" \"cpp-class-out\" \"cpp-output\" \"java-translate-file\" \"java-translate\" \"java-class-out\" \"java-output\" \"idl-translate\" \"idl-class-out\" \"idl-translate-file\" \"idl-output\" \"your-file\" \"your-file2\" \"startup\")))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *COPYRIGHT-HEADER* STRING \"--------------------------------------------------------------------------+\n |                                                                          |\n |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996, 1997             | \n |  University of Southern California, Information Sciences Institute       |\n |  4676 Admiralty Way                                                      |\n |  Marina Del Rey, California 90292                                        |\n |                                                                          |\n |  This software was developed under the terms and conditions of Contract  |\n |  No. N00014-94-C-0245 between the Defense Advanced Research Projects     |\n |  Agency and the University of Southern California, Information Sciences  | \n |  Institute.  Use and distribution of this software is further subject    |\n |  to the provisions of that contract and any other agreements developed   |\n |  between the user of the software and the University of Southern         |\n |  California, Information Sciences Institute.  It is supplied \\\"AS IS\\\",    |\n |  without any warranties of any kind.  It is furnished only on the basis  |\n |  that any party who receives it indemnifies and holds harmless the       |\n |  parties who furnish and originate it against any claims, demands, or    |\n |  liabilities connected with using it, furnishing it to others or         |\n |  providing it to a third party.  THIS NOTICE MUST NOT BE REMOVED FROM    |\n |  THE SOFTWARE, AND IN THE EVENT THAT THE SOFTWARE IS DIVIDED, IT SHOULD  |\n |  BE ATTACHED TO EVERY PART.                                              |\n |                                                                          |\n +--------------------------------------------------------------------------\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT TYPE-SEPARATOR CHARACTER #\\.)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *OS* KEYWORD :UNIX :DOCUMENTATION \"Target Operating System, currently :UNIX or :MAC.  Should probably\n            be replaced by option in *current-environment-features*\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *SYSTEMSOURCEDIRECTORY* STRING \"PL:sources;stella;\")");
            { Global_Variable* global = SYM_TRANSLATE_FILE_oSYSTEMSOURCEDIRECTORYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OsystemsourcedirectoryO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OsystemsourcedirectoryO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *SYSTEMBINARYDIRECTORY* STRING \"PL:binaries;stella;\")");
            { Global_Variable* global = SYM_TRANSLATE_FILE_oSYSTEMBINARYDIRECTORYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OsystembinarydirectoryO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OsystembinarydirectoryO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-SOURCE-EXTENSION* STRING \".ste\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-BINARY-EXTENSION* STRING \".fasl\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-LISP-EXTENSION* STRING \".lisp\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-CPP-CODE-EXTENSION* STRING \".cc\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-CPP-HEADER-EXTENSION* STRING \".hh\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-JAVA-EXTENSION* STRING \".java\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-IDL-EXTENSION* STRING \".idl\")");
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

