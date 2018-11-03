// logic-in.cc

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

List* oAVAILABLE_POWERLOOM_FEATURESo = NULL;

Keyword* KWD_LOGIC_IN_GOAL_TRACE = NULL;

Keyword* KWD_LOGIC_IN_CLOSED_WORLD = NULL;

List* oCURRENT_POWERLOOM_FEATURESo = NULL;

List* oDEFAULT_POWERLOOM_FEATURESo = NULL;

Keyword* KWD_LOGIC_IN_GOAL_TREE = NULL;

Surrogate* SGT_LOGIC_IN_LOGIC_EXCEPTION = NULL;

Symbol* SYM_LOGIC_IN_EVALUATOR_WRAPPER_CODE = NULL;

char* oLOGIC_PROMPTo = "|= ";

char* oLOGIC_COMMAND_RESULT_INDENTo = "";

Keyword* KWD_LOGIC_IN_REALISTIC = NULL;

boolean oCAREFUL_LOGIC_COMMAND_LOOP_EXITop = TRUE;

Symbol* SYM_LOGIC_IN_oCAREFUL_LOGIC_COMMAND_LOOP_EXITop = NULL;

Keyword* KWD_LOGIC_IN_BYE = NULL;

Keyword* KWD_LOGIC_IN_EXIT = NULL;

Keyword* KWD_LOGIC_IN_HALT = NULL;

Keyword* KWD_LOGIC_IN_QUIT = NULL;

Keyword* KWD_LOGIC_IN_STOP = NULL;

Symbol* SYM_LOGIC_IN_BYE = NULL;

Symbol* SYM_LOGIC_IN_EXIT = NULL;

Symbol* SYM_LOGIC_IN_HALT = NULL;

Symbol* SYM_LOGIC_IN_QUIT = NULL;

Symbol* SYM_LOGIC_IN_STOP = NULL;

Surrogate* SGT_LOGIC_IN_READ_EXCEPTION = NULL;

Keyword* KWD_LOGIC_IN_DEFINE = NULL;

Symbol* SYM_LOGIC_IN_DEFCLASS = NULL;

Symbol* SYM_LOGIC_IN_DEFSLOT = NULL;

Symbol* SYM_LOGIC_IN_DEFUN = NULL;

Symbol* SYM_LOGIC_IN_DEFMETHOD = NULL;

Symbol* SYM_LOGIC_IN_DEFMODULE = NULL;

Symbol* SYM_LOGIC_IN_IN_MODULE = NULL;

Surrogate* SGT_LOGIC_IN_CLASS = NULL;

Surrogate* SGT_LOGIC_IN_STORAGE_SLOT = NULL;

Surrogate* SGT_LOGIC_IN_METHOD_SLOT = NULL;

Surrogate* SGT_LOGIC_IN_MODULE = NULL;

Surrogate* SGT_LOGIC_IN_VOID = NULL;

Surrogate* SGT_LOGIC_IN_CONS = NULL;

Keyword* KWD_LOGIC_IN_FINALIZE = NULL;

Symbol* SYM_LOGIC_IN_CLEAR_MODULE = NULL;

Symbol* SYM_LOGIC_IN_IN_DIALECT = NULL;

int oDEMO_LEVELo = 0;

Symbol* SYM_LOGIC_IN_oDEMO_LEVELo = NULL;

char* oDEMO_FILE_DIRECTORYo = DEMO_FILE_PATHNAME;

char* oDEMO_FILE_SUFFIXo = ".ste";

Cons* oDEMO_FILESo = NULL;

Symbol* SYM_LOGIC_IN_FALSE = NULL;

Symbol* SYM_LOGIC_IN_SORTp = NULL;

Symbol* SYM_LOGIC_IN_RELATION_PARAMETER_NAMES = NULL;

Keyword* KWD_LOGIC_IN_KIF = NULL;

Symbol* SYM_LOGIC_IN_pSELF = NULL;

Symbol* SYM_LOGIC_IN_SELF = NULL;

Symbol* SYM_LOGIC_IN_SELF_VARIABLE = NULL;

Symbol* SYM_LOGIC_IN_pVALUE = NULL;

Symbol* SYM_LOGIC_IN_VALUE = NULL;

Symbol* SYM_LOGIC_IN_VALUE_VARIABLE = NULL;

Symbol* SYM_LOGIC_IN_DEFFUNCTION = NULL;

Surrogate* SGT_LOGIC_IN_UNKNOWN = NULL;

Keyword* KWD_LOGIC_IN_POLYMORPHICp = NULL;

Keyword* KWD_LOGIC_IN_TYPE = NULL;

Surrogate* SGT_LOGIC_IN_BOOLEAN = NULL;

Symbol* SYM_LOGIC_IN_BOOLEAN = NULL;

Keyword* KWD_LOGIC_IN_ABSTRACTp = NULL;

Symbol* SYM_LOGIC_IN_TRUE = NULL;

Keyword* KWD_LOGIC_IN_SELF_VARIABLE = NULL;

Symbol* SYM_LOGIC_IN_VARIABLE_ARITYp = NULL;

Symbol* SYM_LOGIC_IN_SLOT_TYPE_SPECIFIER = NULL;

Keyword* KWD_LOGIC_IN_DOCUMENTATION = NULL;

Symbol* SYM_LOGIC_IN_DOCUMENTATION = NULL;

Keyword* KWD_LOGIC_IN_SINGLE_VALUEDp = NULL;

Keyword* KWD_LOGIC_IN_PROPERTIES = NULL;

Symbol* SYM_LOGIC_IN_PROPERTIES = NULL;

Keyword* KWD_LOGIC_IN_META_ATTRIBUTES = NULL;

Symbol* SYM_LOGIC_IN_META_ATTRIBUTES = NULL;

Symbol* SYM_LOGIC_IN_RELATION_STRINGIFIED_SOURCE = NULL;

Symbol* SYM_LOGIC_IN_aREST = NULL;

Symbol* SYM_LOGIC_IN_ARGUMENT_LIST = NULL;

Symbol* SYM_LOGIC_IN_OF = NULL;

Symbol* SYM_LOGIC_IN_RELATION_ORIGINATED_PROPOSITIONS = NULL;

Surrogate* SGT_LOGIC_IN_BOOLEAN_WRAPPER = NULL;

Symbol* SYM_LOGIC_IN_DEFINITION_STRING = NULL;

Symbol* SYM_LOGIC_IN_SLOT_OPTION_KEYWORD = NULL;

Surrogate* SGT_LOGIC_IN_TABLE = NULL;

Symbol* SYM_LOGIC_IN_UNKNOWN = NULL;

Symbol* SYM_LOGIC_IN_AND = NULL;

Symbol* SYM_LOGIC_IN_SETOFALL = NULL;

Symbol* SYM_LOGIC_IN_KAPPA = NULL;

Symbol* SYM_LOGIC_IN_e = NULL;

Symbol* SYM_LOGIC_IN_AXIOMS_STRING = NULL;

Surrogate* SGT_LOGIC_IN_SLOT = NULL;

Symbol* SYM_LOGIC_IN_FORALL = NULL;

Symbol* SYM_LOGIC_IN_eg = NULL;

List* oUNFINALIZED_DEFINED_RELATIONSo = NULL;

Symbol* SYM_LOGIC_IN_BADp = NULL;

Keyword* KWD_LOGIC_IN_ASSERT_TRUE = NULL;

Symbol* SYM_LOGIC_IN_DEFINITION = NULL;

Symbol* SYM_LOGIC_IN_DESCRIPTION = NULL;

Keyword* KWD_LOGIC_IN_ENUMERATION = NULL;

Symbol* SYM_LOGIC_IN_DEFRELATION = NULL;

Cons* oLOGIC_RELEVANT_STELLA_COMMANDSo = NULL;

Symbol* SYM_LOGIC_IN_CC = NULL;

void print_features() {
  // Print the currently enabled and available PowerLoom environment features.
  cout << "Currently enabled PowerLoom features:" << endl << "   " << oCURRENT_POWERLOOM_FEATURESo << endl << endl << "Available PowerLoom features:" << endl << "   " << oAVAILABLE_POWERLOOM_FEATURESo << endl;
}

void set_powerloom_feature(Keyword* feature) {
  // Enable the PowerLoom environment feature `feature'.
  if (!(oCURRENT_POWERLOOM_FEATURESo->memberP(feature))) {
    if (feature == KWD_LOGIC_IN_GOAL_TRACE) {
      add_trace(cons_list(1, KWD_LOGIC_IN_GOAL_TREE));
    }
    else if (feature == KWD_LOGIC_IN_CLOSED_WORLD) {
    }
    else {
      cerr << "No such PowerLoom environment feature: " << "`" << feature << "'";
      print_features();
      return;
    }
    oCURRENT_POWERLOOM_FEATURESo->insert(feature);
  }
}

List* set_feature(Cons* features) {
  // Enable the PowerLoom environment feature(s) named by `features'.
  // Return the list of enabled features.  Calling `set-feature' without any
  // arguments can be used to display the currently enabled features.
  // The following features are supported:
  // 
  // `closed-world': Enables closed-world reasoning.  NOT YET IMPLEMENTED!
  // 
  // `goal-trace': Enables the generation of goal trace information during
  // inference.
  {
    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;
      boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      oPENDINGEXCEPTIONHANDLERpo = TRUE;
      if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        { Object* featurename = NULL;
          Cons* iter_001 = features;

          while (!nilP(iter_001)) {
            {
              featurename = iter_001->value;
              iter_001 = iter_001->rest;
            }
            set_powerloom_feature(string_keywordify(coerce_to_string(featurename)));
          }
        }
        oEXCEPTIONo = NULL;
      }
      oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (subtype_ofP(oEXCEPTION_TYPEo, SGT_LOGIC_IN_LOGIC_EXCEPTION)) {
      }
      else {
        resignal();
      }
    }
  }
  return (oCURRENT_POWERLOOM_FEATURESo);
}

List* set_feature_evaluator_wrapper(Cons* arguments) {
  return (set_feature(((Cons*)(arguments))));
}

void unset_powerloom_feature(Keyword* feature) {
  // Disable the PowerLoom environment feature `feature'.
  if (oCURRENT_POWERLOOM_FEATURESo->memberP(feature)) {
    if (feature == KWD_LOGIC_IN_GOAL_TRACE) {
      drop_trace(cons_list(1, KWD_LOGIC_IN_GOAL_TREE));
    }
    else if (feature == KWD_LOGIC_IN_CLOSED_WORLD) {
    }
    else {
      cerr << "`" << feature << "'" << " is not a valid case option";
    }
  }
  else {
    if (!oAVAILABLE_POWERLOOM_FEATURESo->memberP(feature)) {
      cerr << "No such PowerLoom environment feature: " << "`" << feature << "'";
      print_features();
    }
  }
  oCURRENT_POWERLOOM_FEATURESo->remove(feature);
}

List* unset_feature(Cons* features) {
  // Disable the PowerLoom environment feature(s) named by `features'.
  // Return the list of enabled features.  Calling `unset-feature' without any
  // arguments can be used to display the currently enabled features.
  // See `set-feature' for a description of supported features.
  {
    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;
      boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      oPENDINGEXCEPTIONHANDLERpo = TRUE;
      if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        { Object* featurename = NULL;
          Cons* iter_001 = features;

          while (!nilP(iter_001)) {
            {
              featurename = iter_001->value;
              iter_001 = iter_001->rest;
            }
            unset_powerloom_feature(string_keywordify(coerce_to_string(featurename)));
          }
        }
        oEXCEPTIONo = NULL;
      }
      oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (subtype_ofP(oEXCEPTION_TYPEo, SGT_LOGIC_IN_LOGIC_EXCEPTION)) {
      }
      else {
        resignal();
      }
    }
  }
  return (oCURRENT_POWERLOOM_FEATURESo);
}

List* unset_feature_evaluator_wrapper(Cons* arguments) {
  return (unset_feature(((Cons*)(arguments))));
}

List* reset_features() {
  // Reset the PowerLoom environment features to their default settings.
  { Keyword* f = NULL;
    Cons* iter_001 = oCURRENT_POWERLOOM_FEATURESo->copy()->the_cons_list;

    while (!nilP(iter_001)) {
      {
        f = ((Keyword*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (!oDEFAULT_POWERLOOM_FEATURESo->memberP(f)) {
        unset_powerloom_feature(f);
      }
    }
  }
  { Keyword* f = NULL;
    Cons* iter_002 = oDEFAULT_POWERLOOM_FEATURESo->the_cons_list;

    while (!nilP(iter_002)) {
      {
        f = ((Keyword*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      if (!oCURRENT_POWERLOOM_FEATURESo->memberP(f)) {
        set_powerloom_feature(f);
      }
    }
  }
  return (oCURRENT_POWERLOOM_FEATURESo);
}

void print_logic_prompt() {
  cout << oLOGIC_PROMPTo;
}

void print_logic_command_result(Object* result, Standard_Object* resulttype) {
  resulttype = resulttype;
  { Keyword* old_OprintmodeO_001 = oPRINTMODEo;
    boolean old_OprettyprintlogicalformsPO_001 = oPRETTYPRINTLOGICALFORMSpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRINTMODEo = KWD_LOGIC_IN_REALISTIC;
          oPRETTYPRINTLOGICALFORMSpo = TRUE;
          if (result != NULL) {
            cout << oLOGIC_COMMAND_RESULT_INDENTo << result << endl;
          }
          oPRETTYPRINTLOGICALFORMSpo = old_OprettyprintlogicalformsPO_001;
          oPRINTMODEo = old_OprintmodeO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPRETTYPRINTLOGICALFORMSpo = old_OprettyprintlogicalformsPO_001;
        oPRINTMODEo = old_OprintmodeO_001;
        resignal();
      }
    }
  }
}

boolean read_Ocareful_logic_command_loop_exitOP() {
  return (oCAREFUL_LOGIC_COMMAND_LOOP_EXITop);
}

boolean write_Ocareful_logic_command_loop_exitOP(boolean value) {
  oCAREFUL_LOGIC_COMMAND_LOOP_EXITop = value;
  return (value);
}

boolean logic_command_loop_exitP(Object* command, boolean& return1) {
  { boolean exitP = FALSE;

    { Object* command_001 = command;

      if (keywordP(command)) {
        { Keyword* command = NULL;

          command = ((Keyword*)(command_001));
          if ((command == KWD_LOGIC_IN_BYE) ||
              ((command == KWD_LOGIC_IN_EXIT) ||
               ((command == KWD_LOGIC_IN_HALT) ||
                ((command == KWD_LOGIC_IN_QUIT) ||
                 (command == KWD_LOGIC_IN_STOP))))) {
            exitP = TRUE;
          }
          else {
          }
        }
      }
      else if (symbolP(command)) {
        { Symbol* command = NULL;

          command = ((Symbol*)(command_001));
          if ((command == SYM_LOGIC_IN_BYE) ||
              ((command == SYM_LOGIC_IN_EXIT) ||
               ((command == SYM_LOGIC_IN_HALT) ||
                ((command == SYM_LOGIC_IN_QUIT) ||
                 (command == SYM_LOGIC_IN_STOP))))) {
            exitP = TRUE;
          }
          else {
          }
        }
      }
      else {
      }
    }
    if (exitP &&
        oCAREFUL_LOGIC_COMMAND_LOOP_EXITop) {
      exitP = yes_or_noP("Really exit? (yes or no) ");
      if (exitP) {
        cout << endl;
      }
      { boolean return_temp = exitP;

        return1 = TRUE;
        return (return_temp);
      }
    }
    { boolean return_temp = exitP;

      return1 = exitP;
      return (return_temp);
    }
  }
}

void logic_command_loop() {
  { boolean dummy1;

    { Object* command = NULL;
      Object* result = NULL;
      Standard_Object* resulttype = NULL;
      boolean exitP = FALSE;
      boolean exitcommandP = FALSE;
      boolean errorP = FALSE;

      { Module* module_001 = oMODULEo;

        { Module* old_OmoduleO_001 = oMODULEo;
          Context* old_OcontextO_001 = oCONTEXTo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oMODULEo = module_001;
                oCONTEXTo = oMODULEo;
                string_change_module("/PL-USER");
                for (;;) {
                  {
                    { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;
                      boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      oPENDINGEXCEPTIONHANDLERpo = TRUE;
                      if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          cout << endl;
                          print_logic_prompt();
                          command = read_stella_expression(STANDARD_INPUT->native_stream, dummy1);
                          cout << endl;
                          exitP = logic_command_loop_exitP(command, exitcommandP);
                          if (exitP) {
                            {
                              {
                                oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
                                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                              }
                              break;
                            }
                          }
                          if (exitcommandP) {
                            {
                              {
                                oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
                                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                              }
                              continue;
                            }
                          }
                          result = evaluate_logic_command(command, TRUE, resulttype, errorP);
                          if (!errorP) {
                            print_logic_command_result(result, resulttype);
                          }
                        }
                        oEXCEPTIONo = NULL;
                      }
                      oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                    }
                    if (oEXCEPTIONo != NULL) {
                      if (subtype_ofP(oEXCEPTION_TYPEo, SGT_LOGIC_IN_READ_EXCEPTION)) {
                        if (!(oUNFINALIZED_DEFINED_RELATIONSo->emptyP())) {
                          { Relation* badrelation = ((Relation*)(oUNFINALIZED_DEFINED_RELATIONSo->pop()));

                          }
                        }
                      }
                      else if (TRUE) {
                        { Exception* e = oEXCEPTIONo;

                          cout << "logic-command-loop: caught " << e->primary_type();
                        }
                      }
                    }
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
    }
  }
}

Object* evaluate_logic_command(Object* command, boolean finalizeP, Standard_Object*& return1, boolean& return2) {
  { boolean dummy1;

    { int old_OtranslationerrorsO_001 = oTRANSLATIONERRORSo;
      int old_OtranslationwarningsO_001 = oTRANSLATIONWARNINGSo;
      boolean old_OignoretranslationerrorsPO_001 = oIGNORETRANSLATIONERRORSpo;
      List* old_OtranslationunitsO_001 = oTRANSLATIONUNITSo;
      Keyword* old_OtranslationphaseO_001 = oTRANSLATIONPHASEo;
      Object* old_OevaluationtreeO_001 = oEVALUATIONTREEo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSLATIONERRORSo = 0;
            oTRANSLATIONWARNINGSo = 0;
            oIGNORETRANSLATIONERRORSpo = FALSE;
            oTRANSLATIONUNITSo = NULL;
            oTRANSLATIONPHASEo = KWD_LOGIC_IN_DEFINE;
            oEVALUATIONTREEo = NULL;
            { Object* renamed_Operator = NULL;
              Object* result = NULL;
              Standard_Object* resulttype = NULL;
              boolean errorP = FALSE;

              { Object* command_001 = command;

                if (consP(command)) {
                  { Cons* command = NULL;

                    command = ((Cons*)(command_001));
                    renamed_Operator = command->value;
                    { Object* operator_001 = renamed_Operator;

                      if (symbolP(renamed_Operator)) {
                        { Symbol* renamed_Operator = NULL;

                          renamed_Operator = ((Symbol*)(operator_001));
                          if (renamed_Operator == SYM_LOGIC_IN_DEFCLASS) {
                            result = define_class_from_parse_tree(command);
                            resulttype = SGT_LOGIC_IN_CLASS;
                          }
                          else if (renamed_Operator == SYM_LOGIC_IN_DEFSLOT) {
                            result = define_external_slot_from_parse_tree(command);
                            resulttype = SGT_LOGIC_IN_STORAGE_SLOT;
                          }
                          else if ((renamed_Operator == SYM_LOGIC_IN_DEFUN) ||
                              (renamed_Operator == SYM_LOGIC_IN_DEFMETHOD)) {
                            result = define_method_from_parse_tree(command);
                            resulttype = SGT_LOGIC_IN_METHOD_SLOT;
                          }
                          else if (renamed_Operator == SYM_LOGIC_IN_DEFMODULE) {
                            result = define_module(((String_Wrapper*)(command->second()))->wrapper_value, command->rest->rest);
                            resulttype = SGT_LOGIC_IN_MODULE;
                          }
                          else if (renamed_Operator == SYM_LOGIC_IN_IN_MODULE) {
                            handle_in_module_tree(command, FALSE, dummy1);
                          }
                          else {
                            if (declaration_treeP(command)) {
                              oTRANSLATIONUNITSo = list(0);
                              walk_top_level_tree(command, FALSE);
                              switch (oTRANSLATIONUNITSo->reverse()->length()) {
                                case 0: 
                                  errorP = TRUE;
                                break;
                                case 1: 
                                  result = ((Translation_Unit*)(oTRANSLATIONUNITSo->first()))->the_object;
                                  resulttype = ((result != NULL) ? ((Surrogate*)(result->primary_type())) : ((Surrogate*)(SGT_LOGIC_IN_VOID)));
                                break;
                                default:
                                  { Cons* results = NIL;

                                    { Translation_Unit* unit = NULL;
                                      Cons* iter_001 = oTRANSLATIONUNITSo->the_cons_list;
                                      Cons* collect_001 = NULL;

                                      while (!nilP(iter_001)) {
                                        {
                                          unit = ((Translation_Unit*)(iter_001->value));
                                          iter_001 = iter_001->rest;
                                        }
                                        if (collect_001 == NULL) {
                                          {
                                            collect_001 = cons(unit->the_object, NIL);
                                            if (nilP(results)) {
                                              results = collect_001;
                                            }
                                            else {
                                              add_cons_to_end_of_cons_list(results, collect_001);
                                            }
                                          }
                                        }
                                        else {
                                          {
                                            collect_001->rest = cons(unit->the_object, NIL);
                                            collect_001 = collect_001->rest;
                                          }
                                        }
                                      }
                                    }
                                    result = results;
                                    resulttype = SGT_LOGIC_IN_CONS;
                                  }
                                break;
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
                              oTRANSLATIONUNITSo->free();
                            }
                            else if (string_eqlP(renamed_Operator->symbol_name, "IN-PACKAGE") ||
                                string_eqlP(renamed_Operator->symbol_name, "in-package")) {
                            }
                            else {
                              result = evaluate(command, resulttype, errorP);
                            }
                          }
                        }
                      }
                      else {
                        result = evaluate(command, resulttype, errorP);
                      }
                    }
                  }
                }
                else if (keywordP(command)) {
                  { Keyword* command = NULL;

                    command = ((Keyword*)(command_001));
                    result = command;
                  }
                }
                else if (surrogateP(command)) {
                  { Surrogate* command = NULL;

                    command = ((Surrogate*)(command_001));
                    result = command;
                  }
                }
                else {
                  result = evaluate(command, resulttype, errorP);
                }
              }
              errorP = errorP ||
                  translation_errorsP();
              if ((!errorP) &&
                  finalizeP) {
                oTRANSLATIONPHASEo = KWD_LOGIC_IN_FINALIZE;
                finalize_relations();
              }
              { 
                oEVALUATIONTREEo = old_OevaluationtreeO_001;
                oTRANSLATIONPHASEo = old_OtranslationphaseO_001;
                oTRANSLATIONUNITSo = old_OtranslationunitsO_001;
                oIGNORETRANSLATIONERRORSpo = old_OignoretranslationerrorsPO_001;
                oTRANSLATIONWARNINGSo = old_OtranslationwarningsO_001;
                oTRANSLATIONERRORSo = old_OtranslationerrorsO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Object* return_temp = result;

                  return1 = resulttype;
                  return2 = errorP;
                  return (return_temp);
                }
              }
            }
            oEVALUATIONTREEo = old_OevaluationtreeO_001;
            oTRANSLATIONPHASEo = old_OtranslationphaseO_001;
            oTRANSLATIONUNITSo = old_OtranslationunitsO_001;
            oIGNORETRANSLATIONERRORSpo = old_OignoretranslationerrorsPO_001;
            oTRANSLATIONWARNINGSo = old_OtranslationwarningsO_001;
            oTRANSLATIONERRORSo = old_OtranslationerrorsO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oEVALUATIONTREEo = old_OevaluationtreeO_001;
          oTRANSLATIONPHASEo = old_OtranslationphaseO_001;
          oTRANSLATIONUNITSo = old_OtranslationunitsO_001;
          oIGNORETRANSLATIONERRORSpo = old_OignoretranslationerrorsPO_001;
          oTRANSLATIONWARNINGSo = old_OtranslationwarningsO_001;
          oTRANSLATIONERRORSo = old_OtranslationerrorsO_001;
          resignal();
        }
      }
    }
  }
}

void load(char* file) {
  // Read logic commands from `file' and evaluate them.
  { Standard_Object* dummy1;
    boolean dummy2;
    Standard_Object* dummy3;
    boolean dummy4;
    Standard_Object* dummy5;
    boolean dummy6;
    Standard_Object* dummy7;
    boolean dummy8;
    Standard_Object* dummy9;
    boolean dummy10;
    Standard_Object* dummy11;
    boolean dummy12;

    if (!probe_fileP(file)) {
      cout << ">> ERROR: File '" << file << "' does not exist." << endl;
      return;
    }
    { boolean toplevelinvocationP = oCURRENTFILEo == NULL;
      Keyword* currentdialect = oLOGIC_DIALECTo;
      boolean skipcommandP = FALSE;
      boolean seeninmoduleP = FALSE;
      Cons* commands = NIL;

      { char* old_OcurrentfileO_001 = oCURRENTFILEo;
        Keyword* old_Ologic_dialectO_001 = oLOGIC_DIALECTo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oCURRENTFILEo = file_base_name(file);
              oLOGIC_DIALECTo = currentdialect;
              { Module* module_001 = oMODULEo;

                { Module* old_OmoduleO_001 = oMODULEo;
                  Context* old_OcontextO_001 = oCONTEXTo;

                  { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oMODULEo = module_001;
                        oCONTEXTo = oMODULEo;
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
                                  skipcommandP = handle_in_module_tree(tree, seeninmoduleP, seeninmoduleP);
                                  if (skipcommandP) {
                                    {
                                      continue;
                                    }
                                  }
                                  { Object* renamed_Operator = tree->first();

                                    { Object* operator_001 = renamed_Operator;

                                      if (symbolP(renamed_Operator)) {
                                        { Symbol* renamed_Operator = NULL;

                                          renamed_Operator = ((Symbol*)(operator_001));
                                          if ((renamed_Operator == SYM_LOGIC_IN_DEFCLASS) ||
                                              ((renamed_Operator == SYM_LOGIC_IN_DEFSLOT) ||
                                               ((renamed_Operator == SYM_LOGIC_IN_DEFUN) ||
                                                ((renamed_Operator == SYM_LOGIC_IN_DEFMETHOD) ||
                                                 ((renamed_Operator == SYM_LOGIC_IN_DEFMODULE) ||
                                                  (renamed_Operator == SYM_LOGIC_IN_CLEAR_MODULE)))))) {
                                            evaluate_logic_command(tree, FALSE, dummy1, dummy2);
                                            tree->free_parse_tree();
                                          }
                                          else if (renamed_Operator == SYM_LOGIC_IN_IN_DIALECT) {
                                            evaluate_logic_command(tree, FALSE, dummy3, dummy4);
                                            commands = cons(tree, commands);
                                          }
                                          else {
                                            if (lookup_command(renamed_Operator) != NULL) {
                                              commands = cons(tree, commands);
                                            }
                                            else {
                                              evaluate_logic_command(tree, FALSE, dummy5, dummy6);
                                            }
                                          }
                                        }
                                      }
                                      else {
                                        evaluate_logic_command(tree, FALSE, dummy7, dummy8);
                                      }
                                    }
                                  }
                                }
                              }
                              else {
                                evaluate_logic_command(tree, FALSE, dummy9, dummy10);
                              }
                            }
                          }
                        }
                        { Keyword* old_OtranslationphaseO_001 = oTRANSLATIONPHASEo;

                          { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                            oEXCEPTIONHANDLERADDRESSo = NULL;
                            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                              {
                                oTRANSLATIONPHASEo = KWD_LOGIC_IN_FINALIZE;
                                finalize_classes_and_slots();
                                oTRANSLATIONPHASEo = old_OtranslationphaseO_001;
                              }
                              oEXCEPTIONo = NULL;
                            }
                            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                          }
                          if (oEXCEPTIONo != NULL) {
                            if (TRUE) {
                              oTRANSLATIONPHASEo = old_OtranslationphaseO_001;
                              resignal();
                            }
                          }
                        }
                        { Object* tree = NULL;
                          Cons* iter_002 = commands->reverse();

                          while (!nilP(iter_002)) {
                            {
                              tree = iter_002->value;
                              iter_002 = iter_002->rest;
                            }
                            evaluate_logic_command(tree, FALSE, dummy11, dummy12);
                          }
                        }
                        { Keyword* old_OtranslationphaseO_002 = oTRANSLATIONPHASEo;

                          { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                            oEXCEPTIONHANDLERADDRESSo = NULL;
                            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                              {
                                oTRANSLATIONPHASEo = KWD_LOGIC_IN_FINALIZE;
                                finalize_relations();
                                oTRANSLATIONPHASEo = old_OtranslationphaseO_002;
                              }
                              oEXCEPTIONo = NULL;
                            }
                            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
                          }
                          if (oEXCEPTIONo != NULL) {
                            if (TRUE) {
                              oTRANSLATIONPHASEo = old_OtranslationphaseO_002;
                              resignal();
                            }
                          }
                        }
                        free_cons_list(commands);
                        oCONTEXTo = old_OcontextO_001;
                        oMODULEo = old_OmoduleO_001;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
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
              if (toplevelinvocationP) {
                sweep_transients();
              }
              oLOGIC_DIALECTo = old_Ologic_dialectO_001;
              oCURRENTFILEo = old_OcurrentfileO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oLOGIC_DIALECTo = old_Ologic_dialectO_001;
            oCURRENTFILEo = old_OcurrentfileO_001;
            resignal();
          }
        }
      }
    }
  }
}

void load_evaluator_wrapper(Cons* arguments) {
  load(((String_Wrapper*)(arguments->value))->wrapper_value);
}

int read_Odemo_levelO() {
  return (oDEMO_LEVELo);
}

int write_Odemo_levelO(int value) {
  oDEMO_LEVELo = value;
  return (value);
}

void print_demo_prompt() {
  cout << oLOGIC_PROMPTo;
}

boolean demo_skip_to_command(Input_Stream* stream) {
  { char renamed_Char = NULL_CHARACTER;
    boolean eofP = FALSE;
    ostream* echostream = oINPUTECHOSTREAMo;
    boolean echoP = FALSE;

    { ostream* old_OinputechostreamO_001 = oINPUTECHOSTREAMo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oINPUTECHOSTREAMo = NULL;
            for (;;) {
              oINPUTECHOSTREAMo = NULL;
              renamed_Char = read_next_character(stream->native_stream, eofP);
              if (eofP) {
                { 
                  oINPUTECHOSTREAMo = old_OinputechostreamO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  return (TRUE);
                }
              }
              if (echoP) {
                oINPUTECHOSTREAMo = echostream;
              }
              switch (renamed_Char) {
                case ' ': 
                case '\t': 
                case '\n': 
                  if (echoP) {
                    *(echostream) << renamed_Char;
                  }
                break;
                case ';': 
                  echoP = TRUE;
                  oINPUTECHOSTREAMo = echostream;
                  *(echostream) << renamed_Char;
                  for (;;) {
                    renamed_Char = read_next_character(stream->native_stream, eofP);
                    if (eofP) {
                      { 
                        oINPUTECHOSTREAMo = old_OinputechostreamO_001;
                        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                        return (TRUE);
                      }
                    }
                    else {
                      if (renamed_Char == '\n') {
                        {
                          break;
                        }
                      }
                    }
                  }
                break;
                default:
                  unread_character(renamed_Char, stream->native_stream);
                  { 
                    oINPUTECHOSTREAMo = old_OinputechostreamO_001;
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                    return (FALSE);
                  }
                break;
              }
            }
            oINPUTECHOSTREAMo = old_OinputechostreamO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oINPUTECHOSTREAMo = old_OinputechostreamO_001;
          resignal();
        }
      }
    }
  }
}

boolean demo_pauseP(boolean pauseP, boolean& return1) {
  { boolean dummy1;

    { boolean exitP = FALSE;
      char* input = NULL;

      if (pauseP) {
        cout << "------ pause ------";
        input = read_line(STANDARD_INPUT->native_stream, dummy1);
        cout << endl;
        if (string_length(input) > 0) {
          switch (upcase_character(string_nth(input, 0))) {
            case 'C': 
              pauseP = FALSE;
            break;
            case 'Q': 
              if (y_or_nP("Really exit demo? (y or n) ")) {
                pauseP = FALSE;
                exitP = TRUE;
              }
            break;
            case 'H': 
            case '?': 
              cout << "Type `c' to continue without pausing," << endl << "     `q' to quit from this demo," << endl << "     `?' or `h' to get this message," << endl << "     or any other key to continue." << endl;
              return (demo_pauseP(pauseP, return1));
            default:
            break;
          }
        }
      }
      else {
        cout << endl;
      }
      { boolean return_temp = pauseP;

        return1 = exitP;
        return (return_temp);
      }
    }
  }
}

void demo_file(char* file, boolean pauseP) {
  { boolean dummy1;

    if (!probe_fileP(file)) {
      cout << ">> ERROR: File `" << file << "' does not exist." << endl;
      return;
    }
    { int currentlevel = oDEMO_LEVELo;
      Object* command = NULL;
      Object* result = NULL;
      Standard_Object* resulttype = NULL;
      boolean exitP = FALSE;
      boolean errorP = FALSE;
      Input_Stream* inputstream = new_input_file_stream(file);

      { ostream* old_OinputechostreamO_001 = oINPUTECHOSTREAMo;
        boolean old_Ocareful_logic_command_loop_exitOP_001 = oCAREFUL_LOGIC_COMMAND_LOOP_EXITop;
        int old_Odemo_levelO_001 = oDEMO_LEVELo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oINPUTECHOSTREAMo = STANDARD_OUTPUT->native_stream;
              oCAREFUL_LOGIC_COMMAND_LOOP_EXITop = FALSE;
              oDEMO_LEVELo = currentlevel + 1;
              { Module* module_001 = oMODULEo;

                { Module* old_OmoduleO_001 = oMODULEo;
                  Context* old_OcontextO_001 = oCONTEXTo;

                  { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oMODULEo = module_001;
                        oCONTEXTo = oMODULEo;
                        if (pauseP) {
                          cout << "Now reading from `" << file << "'." << endl << "Type `?' at the pause prompt for a list of available commands." << endl;
                        }
                        for (;;) {
                          cout << endl;
                          exitP = demo_skip_to_command(inputstream);
                          print_demo_prompt();
                          if (!(exitP)) {
                            command = read_stella_expression(inputstream->native_stream, exitP);
                          }
                          if (exitP ||
                              logic_command_loop_exitP(command, dummy1)) {
                            {
                              break;
                            }
                          }
                          pauseP = demo_pauseP(pauseP, exitP);
                          if (exitP) {
                            {
                              break;
                            }
                          }
                          result = evaluate_logic_command(command, TRUE, resulttype, errorP);
                          if (!errorP) {
                            print_logic_command_result(result, resulttype);
                          }
                        }
                        inputstream->free();
                        cout << endl << endl << oLOGIC_COMMAND_RESULT_INDENTo << "Finished demo `" << file << "'." << endl;
                        oCONTEXTo = old_OcontextO_001;
                        oMODULEo = old_OmoduleO_001;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
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
              oDEMO_LEVELo = old_Odemo_levelO_001;
              oCAREFUL_LOGIC_COMMAND_LOOP_EXITop = old_Ocareful_logic_command_loop_exitOP_001;
              oINPUTECHOSTREAMo = old_OinputechostreamO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oDEMO_LEVELo = old_Odemo_levelO_001;
            oCAREFUL_LOGIC_COMMAND_LOOP_EXITop = old_Ocareful_logic_command_loop_exitOP_001;
            oINPUTECHOSTREAMo = old_OinputechostreamO_001;
            resignal();
          }
        }
      }
    }
  }
}

char* select_example_demo(int index) {
  { Cons* entry = ((Cons*)(oDEMO_FILESo->nth(index - 1)));

    if (entry != NULL) {
      return (string_concatenate(oDEMO_FILE_DIRECTORYo, string_concatenate(((String_Wrapper*)(entry->first()))->wrapper_value, oDEMO_FILE_SUFFIXo)));
    }
    else {
      return (NULL);
    }
  }
}

char* select_example_demo_from_menu() {
  { boolean dummy1;

    cout << "Choose a demo:" << endl;
    { int i = NULL_INTEGER;
      Cons* entry = NIL;
      Cons* iter_001 = oDEMO_FILESo;
      int iter_002 = 1;

      while (!nilP(iter_001)) {
        {
          entry = ((Cons*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        {
          i = iter_002;
          iter_002 = iter_002 + 1;
        }
        cout << "       " << i << ".  ";
        if (i < 10) {
          cout << " ";
        }
        cout << (((((String_Wrapper*)(entry->second())) != NULL) ? ((char*)(((String_Wrapper*)(entry->second()))->wrapper_value)) : ((char*)(((String_Wrapper*)(entry->first()))->wrapper_value)))) << endl;
      }
    }
    cout << "       " << "Q.   Quit demoing" << endl;
    cout << "Your choice: ";
    { Object* selection = read_stella_expression(STANDARD_INPUT->native_stream, dummy1);
      char* file = NULL;

      { Object* selection_001 = selection;

        if (integerP(selection)) {
          { Integer_Wrapper* selection = NULL;

            selection = ((Integer_Wrapper*)(selection_001));
            file = select_example_demo(selection->wrapper_value);
            if (file != NULL) {
              return (file);
            }
          }
        }
        else {
          if (string_eqlP(stringify(selection), "Q")) {
            return (NULL);
          }
        }
      }
      cout << ">> ERROR: Illegal choice `" << selection << "'; enter a number between 1 and " << oDEMO_FILESo->length() << "!" << endl << endl;
      return (select_example_demo_from_menu());
    }
  }
}

void demo_example_demos() {
  { char* file = NULL;

    for (;;) {
      cout << endl;
      file = select_example_demo_from_menu();
      if (file == NULL) {
        return;
      }
      cout << endl;
      demo_file(file, TRUE);
    }
  }
}

void demo(Cons* fileandpause) {
  // Read logic commands from a file, echo them verbatimly to standard output,
  // and evaluate them just as if they had been typed in interactively.
  // When called with no arguments, present a menu of example demos, otherwise,
  // use the first argument as the name of the file to demo.
  // Pause for user confirmation after each expression has been read but
  // before it is evaluated.  Pausing can be turned off by suppling FALSE
  // as the optional second argument, or by typing `c' at the pause prompt.
  // Typing `?' at the pause prompt prints a list of available commands.
  { Object* filespec = fileandpause->first();
    boolean pauseP = !(fileandpause->second() == SYM_LOGIC_IN_FALSE);
    char* file = NULL;

    if (integerP(filespec)) {
      file = select_example_demo(((Integer_Wrapper*)(filespec))->wrapper_value);
      if (file != NULL) {
        filespec = string_wrap_literal(file);
      }
      else {
        filespec = NULL;
      }
    }
    if (filespec == NULL) {
      demo_example_demos();
    }
    else {
      { Object* filespec_001 = filespec;

        if (stringP(filespec)) {
          { String_Wrapper* filespec = NULL;

            filespec = ((String_Wrapper*)(filespec_001));
            demo_file(filespec->wrapper_value, pauseP);
          }
        }
        else {
          cout << ">> ERROR: Illegal file specification: " << filespec;
        }
      }
    }
  }
}

void demo_evaluator_wrapper(Cons* arguments) {
  demo(((Cons*)(arguments)));
}

void test_logic_file(char* file) {
  { boolean dummy1;

    if (!probe_fileP(file)) {
      cout << ">> ERROR: File `" << file << "' does not exist." << endl;
      return;
    }
    { int currentlevel = oDEMO_LEVELo;
      Object* command = NULL;
      Object* result = NULL;
      Standard_Object* resulttype = NULL;
      boolean exitP = FALSE;
      boolean errorP = FALSE;
      Input_Stream* inputstream = new_input_file_stream(file);
      char* filebasename = string_subsequence(file, string_length(oDEMO_FILE_DIRECTORYo), NULL_INTEGER);

      { boolean old_Ocareful_logic_command_loop_exitOP_001 = oCAREFUL_LOGIC_COMMAND_LOOP_EXITop;
        int old_Odemo_levelO_001 = oDEMO_LEVELo;
        boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;
        boolean old_OprintprettyPO_001 = oPRINTPRETTYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oCAREFUL_LOGIC_COMMAND_LOOP_EXITop = FALSE;
              oDEMO_LEVELo = currentlevel + 1;
              oPRINTREADABLYpo = TRUE;
              oPRINTPRETTYpo = FALSE;
              { Module* module_001 = oMODULEo;

                { Module* old_OmoduleO_001 = oMODULEo;
                  Context* old_OcontextO_001 = oCONTEXTo;

                  { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oMODULEo = module_001;
                        oCONTEXTo = oMODULEo;
                        cout << endl << "Now testing file `" << filebasename << "':" << endl;
                        for (;;) {
                          cout << endl;
                          print_demo_prompt();
                          if (!(exitP)) {
                            command = read_stella_expression(inputstream->native_stream, exitP);
                          }
                          if (exitP ||
                              logic_command_loop_exitP(command, dummy1)) {
                            {
                              break;
                            }
                          }
                          cout << command << endl << endl;
                          result = evaluate_logic_command(command, TRUE, resulttype, errorP);
                          if (!errorP) {
                            print_logic_command_result(result, resulttype);
                          }
                        }
                        inputstream->free();
                        cout << endl << endl << oLOGIC_COMMAND_RESULT_INDENTo << "Finished testing file `" << filebasename << "'." << endl;
                        oCONTEXTo = old_OcontextO_001;
                        oMODULEo = old_OmoduleO_001;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
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
              oPRINTPRETTYpo = old_OprintprettyPO_001;
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
              oDEMO_LEVELo = old_Odemo_levelO_001;
              oCAREFUL_LOGIC_COMMAND_LOOP_EXITop = old_Ocareful_logic_command_loop_exitOP_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTPRETTYpo = old_OprintprettyPO_001;
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            oDEMO_LEVELo = old_Odemo_levelO_001;
            oCAREFUL_LOGIC_COMMAND_LOOP_EXITop = old_Ocareful_logic_command_loop_exitOP_001;
            resignal();
          }
        }
      }
    }
  }
}

void run_powerloom_tests() {
  // Run the PowerLoom test suite.  Currently this simply runs all demos and
  // echos commands and their results to standard output.  The output can then
  // be diffed with previously validated runs to find deviations.
  cout << "RUNNING POWERLOOM TEST SUITE" << endl << "============================" << endl << endl;
  cout << "STELLA version:    " << oSTELLA_VERSION_STRINGo << endl << "PowerLoom version: " << oPOWERLOOM_VERSION_STRINGo << endl << "Current time:      " << ((char*)("Not available")) << endl << endl;
  { Context* pluser = get_context("/PL-USER", TRUE);

    { Context* child = NULL;
      Cons* iter_001 = pluser->child_contexts->copy()->the_cons_list;

      while (!nilP(iter_001)) {
        {
          child = ((Context*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        child->destroy_context();
      }
    }
    clear_context(pluser);
  }
  { int i = NULL_INTEGER;
    int iter_002 = 1;
    int upper_bound_001 = oDEMO_FILESo->length();

    while (iter_002 <= upper_bound_001) {
      {
        i = iter_002;
        iter_002 = iter_002 + 1;
      }
      test_logic_file(select_example_demo(i));
    }
  }
  cout << endl << "FINISHED RUNNING POWERLOOM TEST SUITE" << endl << "=====================================" << endl << endl;
}

boolean Relation::sortP_reader() {
  { Relation* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_LOGIC_IN_SORTp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Class::sortP_reader() {
  { Class* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_LOGIC_IN_SORTp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (TRUE);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Table::relation_parameter_names_reader() {
  { Table* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_LOGIC_IN_RELATION_PARAMETER_NAMES, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

Keyword* Relation::logic_dialect() {
  { Relation* self = this;

    return (oLOGIC_DIALECTo);
  }
}

Symbol* default_self_variable(Relation* self) {
  { Keyword* test_value_001 = ((self == NULL) ? ((Keyword*)(oLOGIC_DIALECTo)) : ((Keyword*)(self->logic_dialect())));

    if (test_value_001 == KWD_LOGIC_IN_KIF) {
      return (SYM_LOGIC_IN_pSELF);
    }
    else {
      return (SYM_LOGIC_IN_SELF);
    }
  }
}

Symbol* Relation::self_variable_getter() {
  { Relation* self = this;

    { Symbol* variable = ((Symbol*)(dynamic_slot_value(self, SYM_LOGIC_IN_SELF_VARIABLE, NULL)));

      if (variable != NULL) {
        return (variable);
      }
      else {
        return (default_self_variable(self));
      }
    }
  }
}

Symbol* Table::self_variable_getter() {
  { Table* self = this;

    return (((Symbol*)(self->relation_parameter_names_reader()->first())));
  }
}

Symbol* Method_Slot::self_variable_getter() {
  { Method_Slot* self = this;

    return (((Symbol*)(self->method_parameter_names_reader()->first())));
  }
}

Symbol* default_value_variable(Relation* self) {
  { Keyword* test_value_001 = ((self == NULL) ? ((Keyword*)(oLOGIC_DIALECTo)) : ((Keyword*)(self->logic_dialect())));

    if (test_value_001 == KWD_LOGIC_IN_KIF) {
      return (SYM_LOGIC_IN_pVALUE);
    }
    else {
      return (SYM_LOGIC_IN_VALUE);
    }
  }
}

Symbol* Slot::value_variable_getter() {
  { Slot* self = this;

    { Symbol* variable = ((Symbol*)(dynamic_slot_value(self, SYM_LOGIC_IN_VALUE_VARIABLE, NULL)));

      if (variable != NULL) {
        return (variable);
      }
      else {
        return (default_value_variable(self));
      }
    }
  }
}

Relation* help_define_relation_from_parse_tree(Cons* tree, char* stringifiedsource) {
  { Object* nametree = NULL;
    Symbol* name = NULL;
    Surrogate* ownertype = NULL;
    Cons* valuetypes = NULL;
    Object* valuetype = NULL;
    Cons* parameters = NULL;
    Cons* typedparameters = NIL;

    { Property_List* self_001 = new_property_list();

      self_001->the_plist = extract_options(tree, NULL);
      { Property_List* options = self_001;
        boolean functionP = tree->first() == SYM_LOGIC_IN_DEFFUNCTION;
        boolean polymorphicP = TRUE;
        boolean unaryP = FALSE;
        Relation* relation = NULL;

        nametree = destructure_defmethod_tree(tree, NULL, parameters, tree);
        name = destructure_method_name_tree(nametree, valuetypes);
        if (name == NULL) {
          return (NULL);
        }
        else {
          name = ((Symbol*)(name->permanentify()));
        }
        valuetype = valuetypes->first();
        { List* parameternames = NULL;
          List* parametertypes = NULL;
          boolean n_aryP = FALSE;

          parameternames = parse_relation_parameters_tree(parameters, parametertypes, n_aryP);
          { Standard_Object* type = NULL;
            Symbol* name = NULL;
            Cons* iter_001 = parameternames->the_cons_list;
            Cons* iter_002 = parametertypes->the_cons_list;
            Cons* collect_001 = NULL;

            while ((!nilP(iter_001)) &&
                (!nilP(iter_002))) {
              {
                name = ((Symbol*)(iter_001->value));
                iter_001 = iter_001->rest;
              }
              {
                type = ((Standard_Object*)(iter_002->value));
                iter_002 = iter_002->rest;
              }
              if (collect_001 == NULL) {
                {
                  collect_001 = cons(cons(name, cons(type, NIL)), NIL);
                  if (nilP(typedparameters)) {
                    typedparameters = collect_001;
                  }
                  else {
                    add_cons_to_end_of_cons_list(typedparameters, collect_001);
                  }
                }
              }
              else {
                {
                  collect_001->rest = cons(cons(name, cons(type, NIL)), NIL);
                  collect_001 = collect_001->rest;
                }
              }
            }
          }
          if (parameternames->emptyP()) {
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
                      cout << endl << " " << "Empty relation parameter list" << "." << endl;
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
            return (NULL);
          }
          ownertype = type_spec_to_base_type(((Standard_Object*)(parametertypes->first())));
          unaryP = (!n_aryP) &&
              (parameternames->length() == 1);
          polymorphicP = !((ownertype == SGT_LOGIC_IN_UNKNOWN) ||
              (options->lookup(KWD_LOGIC_IN_POLYMORPHICp) == SYM_LOGIC_IN_FALSE));
          options->remove_at(KWD_LOGIC_IN_POLYMORPHICp);
          if (polymorphicP &&
              (!(((Class*)(ownertype->surrogate_value)) != NULL))) {
            { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Can't define polymorphic relation on non-existent class " << "`" << de_uglify_parse_tree(ownertype) << "'" << "." << endl;
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
            return (NULL);
          }
          if (valuetype == NULL) {
            valuetype = options->lookup(KWD_LOGIC_IN_TYPE);
          }
          options->remove_at(KWD_LOGIC_IN_TYPE);
          if (valuetype == NULL) {
            valuetype = (functionP ? ((Surrogate*)(SGT_LOGIC_IN_UNKNOWN)) : ((Surrogate*)(SGT_LOGIC_IN_BOOLEAN)));
          }
          else {
            if ((!functionP) &&
                (!((valuetype == SGT_LOGIC_IN_BOOLEAN) ||
                (valuetype == SYM_LOGIC_IN_BOOLEAN)))) {
              { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_error();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Illegal value type for relation: " << "`" << de_uglify_parse_tree(valuetype) << "'" << "." << endl << " Changing it to BOOLEAN instead" << "." << endl;
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
              valuetype = SGT_LOGIC_IN_BOOLEAN;
            }
          }
          relation = get_identical_relation(name, ownertype, polymorphicP, stringifiedsource);
          if (relation != NULL) {
            return (relation);
          }
          if (unaryP &&
              polymorphicP) {
            options->insert_at(KWD_LOGIC_IN_TYPE, valuetype);
            options->insert_at(KWD_LOGIC_IN_ABSTRACTp, SYM_LOGIC_IN_TRUE);
            if (!(default_self_variable(NULL) == parameternames->first())) {
              options->insert_at(KWD_LOGIC_IN_SELF_VARIABLE, ((Symbol*)(parameternames->first())));
            }
            { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

              { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oTRANSIENTOBJECTSpo = TRUE;
                    tree = listO(3, SYM_LOGIC_IN_DEFSLOT, type_to_symbol(ownertype), cons(name, ((Cons*)(transientify_form(options->the_plist)))->concatenate(NIL)));
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
            options->clear();
            relation = define_external_slot_from_parse_tree(tree);
          }
          if ((relation == NULL) &&
              (!polymorphicP)) {
            if (unaryP &&
                (!functionP)) {
              if (!(default_self_variable(NULL) == parameternames->first())) {
                options->insert_at(KWD_LOGIC_IN_SELF_VARIABLE, ((Symbol*)(parameternames->first())));
              }
              { boolean old_OtransientobjectsPO_002 = oTRANSIENTOBJECTSpo;

                { jump_buffer old_OexceptionhandleraddressO_005 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oTRANSIENTOBJECTSpo = TRUE;
                      tree = listO(3, SYM_LOGIC_IN_DEFCLASS, name, cons(((ownertype == SGT_LOGIC_IN_UNKNOWN) ? ((Cons*)(NIL)) : ((Cons*)(cons(type_to_symbol(ownertype), NIL)))), ((Cons*)(transientify_form(options->the_plist)))->concatenate(NIL)));
                      oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_002;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_005;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_002;
                    resignal();
                  }
                }
              }
              options->clear();
              relation = define_class_from_parse_tree(tree);
            }
            else {
              options->insert_at(KWD_LOGIC_IN_TYPE, valuetype);
              { boolean old_OtransientobjectsPO_003 = oTRANSIENTOBJECTSpo;

                { jump_buffer old_OexceptionhandleraddressO_006 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oTRANSIENTOBJECTSpo = TRUE;
                      tree = listO(3, SYM_LOGIC_IN_DEFUN, name, cons(typedparameters, ((Cons*)(transientify_form(options->the_plist)))->concatenate(NIL)));
                      oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_003;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_006;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_003;
                    resignal();
                  }
                }
              }
              options->clear();
              relation = define_method_from_parse_tree(tree);
            }
          }
          if (relation == NULL) {
            valuetype = valuetype->yield_type_specifier();
            { Table* self_002 = new_table();

              self_002->slot_name = name;
              self_002->slot_owner = ownertype;
              self_002->slot_base_type = type_spec_to_base_type(((Standard_Object*)(valuetype)));
              self_002->slot_externalP = TRUE;
              set_dynamic_slot_value(self_002, SYM_LOGIC_IN_RELATION_PARAMETER_NAMES, parameternames, NULL);
              self_002->tuple_domains = parametertypes;
              { Table* table = self_002;

                if (n_aryP) {
                  set_dynamic_slot_value(table, SYM_LOGIC_IN_VARIABLE_ARITYp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
                }
                if (!typeP(valuetype)) {
                  set_dynamic_slot_value(table, SYM_LOGIC_IN_SLOT_TYPE_SPECIFIER, ((Compound_Type_Specifier*)(valuetype)), NULL);
                }
                { Object* value = NULL;
                  Object* key = NULL;
                  Cons* iter_003 = options->the_plist;

                  while (!nilP(iter_003)) {
                    key = iter_003->value;
                    {
                      value = iter_003->rest->value;
                      iter_003 = iter_003->rest->rest;
                    }
                    { Keyword* test_value_001 = ((Keyword*)(key));

                      if (test_value_001 == KWD_LOGIC_IN_DOCUMENTATION) {
                        set_dynamic_slot_value(table, SYM_LOGIC_IN_DOCUMENTATION, wrap_string(((String_Wrapper*)(value))->wrapper_value), NULL_STRING_WRAPPER);
                      }
                      else if (test_value_001 == KWD_LOGIC_IN_SINGLE_VALUEDp) {
                      }
                      else if (test_value_001 == KWD_LOGIC_IN_PROPERTIES) {
                        set_dynamic_slot_value(table, SYM_LOGIC_IN_PROPERTIES, ((List*)(value)), NULL);
                      }
                      else if (test_value_001 == KWD_LOGIC_IN_META_ATTRIBUTES) {
                        set_dynamic_slot_value(table, SYM_LOGIC_IN_META_ATTRIBUTES, ((Key_Value_List*)(value)), NULL);
                      }
                      else {
                        if (!(run_option_handlerP(table, ((Keyword*)(key)), value))) {
                          { boolean old_OprintreadablyPO_004 = oPRINTREADABLYpo;

                            { jump_buffer old_OexceptionhandleraddressO_007 = oEXCEPTIONHANDLERADDRESSo;

                              oEXCEPTIONHANDLERADDRESSo = NULL;
                              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                                {
                                  oPRINTREADABLYpo = TRUE;
                                  signal_translation_warning();
                                  if (!(suppress_warningsP())) {
                                    print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                                    cout << endl << " " << "Skipping invalid option " << "`" << de_uglify_parse_tree(key) << "'" << endl << "in the definition of " << "`" << de_uglify_parse_tree(ownertype) << "'" << "." << "`" << de_uglify_parse_tree(name) << "'" << "." << endl;
                                  }
                                  oPRINTREADABLYpo = old_OprintreadablyPO_004;
                                }
                                oEXCEPTIONo = NULL;
                              }
                              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_007;
                            }
                            if (oEXCEPTIONo != NULL) {
                              if (TRUE) {
                                oPRINTREADABLYpo = old_OprintreadablyPO_004;
                                resignal();
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
                attach_slot_to_owner(table);
                relation = table;
              }
            }
          }
          set_dynamic_slot_value(relation, SYM_LOGIC_IN_RELATION_STRINGIFIED_SOURCE, wrap_string(stringifiedsource), NULL_STRING_WRAPPER);
          return (relation);
        }
      }
    }
  }
}

List* parse_relation_parameters_tree(Cons* parameters, List*& return1, boolean& return2) {
  if (parameters->emptyP()) {
    { List* return_temp = NIL_LIST;

      return1 = NIL_LIST;
      return2 = FALSE;
      return (return_temp);
    }
  }
  { Symbol* name = NULL;
    Standard_Object* typespec = NULL;
    List* names = new_list();
    List* typespecs = new_list();
    boolean variableargsP = FALSE;

    { Object* p = NULL;
      Cons* iter_001 = parameters;

      while (!nilP(iter_001)) {
        {
          p = iter_001->value;
          iter_001 = iter_001->rest;
        }
        { Object* p_001 = p;

          if (consP(p)) {
            { Cons* p = NULL;

              p = ((Cons*)(p_001));
              if (!(p->length() == 2)) {
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
                          cout << endl << " " << "Illegal parameter: " << "`" << de_uglify_parse_tree(p) << "'" << "." << endl;
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
                continue;
              }
              name = ((Symbol*)(p->first()));
              typespec = ((Standard_Object*)(p->second()));
            }
          }
          else if (symbolP(p)) {
            { Symbol* p = NULL;

              p = ((Symbol*)(p_001));
              if (p == SYM_LOGIC_IN_aREST) {
                variableargsP = TRUE;
                continue;
              }
              name = p;
              typespec = SGT_LOGIC_IN_UNKNOWN;
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
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Illegal parameter: " << "`" << de_uglify_parse_tree(p) << "'" << "." << endl;
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
            continue;
          }
        }
        if (variableargsP) {
          typespec = listO(4, SYM_LOGIC_IN_ARGUMENT_LIST, SYM_LOGIC_IN_OF, typespec, NIL);
        }
        names->push(name);
        typespecs->push(typespec->yield_type_specifier());
        if (variableargsP) {
          break;
        }
      }
    }
    { List* return_temp = names->reverse();

      return1 = typespecs->reverse();
      return2 = variableargsP;
      return (return_temp);
    }
  }
}

Relation* get_identical_relation(Symbol* name, Surrogate* owner, boolean polymorphicP, char* stringifiedsource) {
  { Relation* relation = NULL;

    if (polymorphicP) {
      relation = safe_lookup_slot(((Class*)(owner->surrogate_value)), name);
      if ((relation == NULL) ||
          (!(((Slot*)(relation))->slot_owner == owner))) {
        relation = NULL;
      }
    }
    else {
      relation = name->lookup_class();
      if (relation == NULL) {
        relation = name->lookup_function();
      }
    }
    if ((relation != NULL) &&
        string_eqlP(((String_Wrapper*)(dynamic_slot_value(relation, SYM_LOGIC_IN_RELATION_STRINGIFIED_SOURCE, NULL_STRING_WRAPPER)))->wrapper_value, stringifiedsource)) {
      return (relation);
    }
    else {
      return (NULL);
    }
  }
}

List* Relation::relation_originated_propositions_reader() {
  { Relation* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_LOGIC_IN_RELATION_ORIGINATED_PROPOSITIONS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Relation::functionP() {
  { Relation* self = this;

    return (FALSE);
  }
}

boolean Slot::functionP() {
  { Slot* self = this;

    { Surrogate* test_value_001 = self->type();

      if ((test_value_001 == SGT_LOGIC_IN_BOOLEAN) ||
          (test_value_001 == SGT_LOGIC_IN_BOOLEAN_WRAPPER)) {
        return (FALSE);
      }
      else {
        return (TRUE);
      }
    }
  }
}

void relation_full_definition_handler(Relation* self, Storage_Slot* slot, Object* definition) {
  slot = slot;
  self->abstractP = TRUE;
  remember_unfinalized_relation(self);
  if (classP(self)) {
    set_dynamic_slot_value(self, SYM_LOGIC_IN_SORTp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
  }
  { Object* definition_001 = definition;

    if (stringP(definition)) {
      { String_Wrapper* definition = NULL;

        definition = ((String_Wrapper*)(definition_001));
        set_dynamic_slot_value(self, SYM_LOGIC_IN_DEFINITION_STRING, wrap_string(definition->wrapper_value), NULL_STRING_WRAPPER);
      }
    }
    else {
      set_dynamic_slot_value(self, SYM_LOGIC_IN_DEFINITION_STRING, wrap_string(stringify(definition)), NULL_STRING_WRAPPER);
    }
  }
}

void relation_sentence_definition_handler(Relation* self, Storage_Slot* slot, Object* definition) {
  slot = slot;
  self->abstractP = TRUE;
  remember_unfinalized_relation(self);
  if (classP(self)) {
    set_dynamic_slot_value(self, SYM_LOGIC_IN_SORTp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
  }
  if (stringP(definition)) {
    definition = unstringify(((String_Wrapper*)(definition))->wrapper_value);
  }
  set_dynamic_slot_value(self, SYM_LOGIC_IN_DEFINITION_STRING, wrap_string(stringify(complete_sentence_definition(self, definition))), NULL_STRING_WRAPPER);
}

void relation_term_definition_handler(Relation* self, Storage_Slot* slot, Object* definition) {
  if (self->functionP()) {
    self->abstractP = TRUE;
    remember_unfinalized_relation(self);
    if (stringP(definition)) {
      definition = unstringify(((String_Wrapper*)(definition))->wrapper_value);
    }
    set_dynamic_slot_value(self, SYM_LOGIC_IN_DEFINITION_STRING, wrap_string(stringify(complete_term_definition(((Slot*)(self)), definition))), NULL_STRING_WRAPPER);
    return;
  }
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
            cout << endl << " " << "Can't define " << "`" << de_uglify_parse_tree(self) << "'" << " with the definition option " << "`" << ((Keyword*)(dynamic_slot_value(slot, SYM_LOGIC_IN_SLOT_OPTION_KEYWORD, NULL))) << "'" << "," << endl << " since it is not a function" << "." << endl;
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

Cons* yield_relation_parameters_tree(Relation* self, boolean typedP) {
  { Keyword* test_value_001 = self->logic_dialect();

    if (test_value_001 == KWD_LOGIC_IN_KIF) {
      { Cons* parameters = NIL;
        Object* parameter = NULL;

        { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oTRANSIENTOBJECTSpo = TRUE;
                { Relation* self_001 = self;

                  if (classP(self)) {
                    { Class* self = NULL;

                      self = ((Class*)(self_001));
                      parameter = self->self_variable_getter();
                      if (typedP) {
                        parameter = cons(parameter, cons(class_symbol(self), NIL));
                      }
                      parameters = cons(parameter, NIL);
                    }
                  }
                  else if (storage_slotP(self)) {
                    { Storage_Slot* self = NULL;

                      self = ((Storage_Slot*)(self_001));
                      parameter = self->self_variable_getter();
                      if (typedP) {
                        parameter = cons(parameter, cons(type_to_symbol(self->slot_owner), NIL));
                      }
                      parameters = cons(parameter, parameters);
                    }
                  }
                  else if (method_slotP(self)) {
                    { Method_Slot* self = NULL;

                      self = ((Method_Slot*)(self_001));
                      { Standard_Object* ptype = NULL;
                        Symbol* pname = NULL;
                        Cons* iter_001 = self->method_parameter_names_reader()->the_cons_list;
                        Cons* iter_002 = self->method_parameter_type_specifiers_reader()->the_cons_list;

                        while ((!nilP(iter_001)) &&
                            (!nilP(iter_002))) {
                          {
                            pname = ((Symbol*)(iter_001->value));
                            iter_001 = iter_001->rest;
                          }
                          {
                            ptype = ((Standard_Object*)(iter_002->value));
                            iter_002 = iter_002->rest;
                          }
                          parameter = pname;
                          if (typedP &&
                              (!(ptype == SGT_LOGIC_IN_UNKNOWN))) {
                            parameter = cons(parameter, cons(yield_type_spec_tree(ptype), NIL));
                          }
                          parameters = cons(parameter, parameters);
                        }
                      }
                    }
                  }
                  else if (taxonomy_isaP(self, SGT_LOGIC_IN_TABLE)) {
                    { Table* self = NULL;

                      self = ((Table*)(self_001));
                      { Object* ptype = NULL;
                        Symbol* pname = NULL;
                        Cons* iter_003 = self->relation_parameter_names_reader()->the_cons_list;
                        Cons* iter_004 = self->tuple_domains->the_cons_list;

                        while ((!nilP(iter_003)) &&
                            (!nilP(iter_004))) {
                          {
                            pname = ((Symbol*)(iter_003->value));
                            iter_003 = iter_003->rest;
                          }
                          {
                            ptype = iter_004->value;
                            iter_004 = iter_004->rest;
                          }
                          parameter = pname;
                          if (typedP &&
                              (!(ptype == SGT_LOGIC_IN_UNKNOWN))) {
                            parameter = cons(parameter, cons(yield_type_spec_tree(((Standard_Object*)(ptype))), NIL));
                          }
                          parameters = cons(parameter, parameters);
                        }
                      }
                    }
                  }
                  else {
                    cerr << "`" << self << "'" << " is not a valid case option";
                  }
                }
                if (self->functionP()) {
                  { Slot* slot = ((Slot*)(self));

                    parameter = slot->value_variable_getter();
                    if (typedP &&
                        ((slot->type() != NULL) &&
                         (!(slot->type() == SGT_LOGIC_IN_UNKNOWN)))) {
                      parameter = cons(parameter, cons(type_to_symbol(slot->type()), NIL));
                    }
                    parameters = cons(parameter, parameters);
                  }
                }
                { Cons* return_value_001 = parameters->reverse();

                  oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  return (return_value_001);
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
    else {
      cerr << "yield-relation-parameters-tree: Not yet implemented for dialect " << "`" << self->logic_dialect() << "'";
      return (NULL);
    }
  }
}

Object* complete_sentence_definition(Relation* self, Object* definition) {
  { Keyword* test_value_001 = self->logic_dialect();

    if (test_value_001 == KWD_LOGIC_IN_KIF) {
      { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oTRANSIENTOBJECTSpo = TRUE;
              { Cons* parameters = yield_relation_parameters_tree(self, TRUE);

                { Relation* self_001 = self;

                  if (classP(self)) {
                    { Class* self = NULL;

                      self = ((Class*)(self_001));
                      parameters = ((Cons*)(parameters->first()));
                      parameters->second_setter((self->class_direct_supers->emptyP() ? ((Symbol*)(SYM_LOGIC_IN_UNKNOWN)) : ((Symbol*)(type_to_symbol(((Surrogate*)(self->class_direct_supers->first())))))));
                      if (self->class_direct_supers->rest()->non_emptyP()) {
                        { Object* selfvariable = parameters->first();
                          Cons* restrictions = NIL;

                          { Surrogate* othersuper = NULL;
                            Cons* iter_001 = self->class_direct_supers->rest();
                            Cons* collect_001 = NULL;

                            while (!nilP(iter_001)) {
                              {
                                othersuper = ((Surrogate*)(iter_001->value));
                                iter_001 = iter_001->rest;
                              }
                              if (collect_001 == NULL) {
                                {
                                  collect_001 = cons(cons(type_to_symbol(othersuper), cons(selfvariable, NIL)), NIL);
                                  if (nilP(restrictions)) {
                                    restrictions = collect_001;
                                  }
                                  else {
                                    add_cons_to_end_of_cons_list(restrictions, collect_001);
                                  }
                                }
                              }
                              else {
                                {
                                  collect_001->rest = cons(cons(type_to_symbol(othersuper), cons(selfvariable, NIL)), NIL);
                                  collect_001 = collect_001->rest;
                                }
                              }
                            }
                          }
                          definition = cons(SYM_LOGIC_IN_AND, restrictions->concatenate(cons(definition, NIL)));
                        }
                      }
                      { Cons* return_value_001 = listO(3, SYM_LOGIC_IN_SETOFALL, parameters, cons(definition, NIL));

                        oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                        return (return_value_001);
                      }
                    }
                  }
                  else {
                    { Cons* return_value_002 = listO(3, SYM_LOGIC_IN_KAPPA, parameters, cons(definition, NIL));

                      oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                      return (return_value_002);
                    }
                  }
                }
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
    else {
      cerr << "complete-sentence-definition: Not yet implemented for dialect " << "`" << self->logic_dialect() << "'";
      return (NULL);
    }
  }
}

Object* complete_term_definition(Slot* self, Object* definition) {
  { Keyword* test_value_001 = self->logic_dialect();

    if (test_value_001 == KWD_LOGIC_IN_KIF) {
      { Symbol* valuevariable = self->value_variable_getter();

        { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oTRANSIENTOBJECTSpo = TRUE;
                definition = listO(3, SYM_LOGIC_IN_KAPPA, yield_relation_parameters_tree(self, TRUE), cons(listO(3, SYM_LOGIC_IN_e, definition, cons(valuevariable, NIL)), NIL));
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
        return (definition);
      }
    }
    else {
      cerr << "complete-term-definition: Not yet implemented for dialect " << "`" << self->logic_dialect() << "'";
      return (NULL);
    }
  }
}

void relation_axioms_handler(Relation* self, Storage_Slot* slot, Object* axioms) {
  slot = slot;
  { char* oldaxioms = ((String_Wrapper*)(dynamic_slot_value(self, SYM_LOGIC_IN_AXIOMS_STRING, NULL_STRING_WRAPPER)))->wrapper_value;
    Object* newaxioms = axioms;

    remember_unfinalized_relation(self);
    if (stringP(axioms)) {
      newaxioms = unstringify(((String_Wrapper*)(axioms))->wrapper_value);
    }
    set_dynamic_slot_value(self, SYM_LOGIC_IN_AXIOMS_STRING, wrap_string(stringify(add_relation_axioms(self, ((oldaxioms == NULL) ? ((Object*)(NULL)) : ((Object*)(unstringify(oldaxioms)))), newaxioms))), NULL_STRING_WRAPPER);
  }
}

Object* add_relation_axioms(Relation* self, Object* oldaxioms, Object* newaxioms) {
  { Keyword* test_value_001 = self->logic_dialect();

    if (test_value_001 == KWD_LOGIC_IN_KIF) {
      { Cons* axioms = NIL;

        if (oldaxioms != NULL) {
          { Object* oldaxioms_001 = oldaxioms;

            if (consP(oldaxioms)) {
              { Cons* oldaxioms = NULL;

                oldaxioms = ((Cons*)(oldaxioms_001));
                if (oldaxioms->first() == SYM_LOGIC_IN_AND) {
                  axioms = oldaxioms;
                }
                else {
                  axioms = cons(oldaxioms, axioms);
                }
              }
            }
            else {
              axioms = cons(oldaxioms, axioms);
            }
          }
        }
        if (newaxioms != NULL) {
          { Object* newaxioms_001 = newaxioms;

            if (consP(newaxioms)) {
              { Cons* newaxioms = NULL;

                newaxioms = ((Cons*)(newaxioms_001));
                if (consP(newaxioms->first())) {
                  axioms = axioms->concatenate(newaxioms->concatenate(NIL));
                }
                else if (newaxioms->first() == SYM_LOGIC_IN_AND) {
                  if (axioms->emptyP()) {
                    axioms = newaxioms;
                  }
                  else {
                    axioms = axioms->concatenate(newaxioms->rest->concatenate(NIL));
                  }
                }
                else {
                  axioms = axioms->concatenate(cons(newaxioms, NIL));
                }
              }
            }
            else {
              axioms = axioms->concatenate(cons(newaxioms, NIL));
            }
          }
        }
        switch (axioms->length()) {
          case 1: 
            return (axioms->first());
          default:
            if (!(axioms->first() == SYM_LOGIC_IN_AND)) {
              axioms = cons(SYM_LOGIC_IN_AND, axioms);
            }
            return (axioms);
        }
      }
    }
    else {
      cerr << "add-relation-axioms: Not yet implemented for dialect " << "`" << self->logic_dialect() << "'";
      return (NULL);
    }
  }
}

void relation_constraints_handler(Relation* self, Storage_Slot* slot, Object* constraints) {
  slot = slot;
  { char* oldaxioms = ((String_Wrapper*)(dynamic_slot_value(self, SYM_LOGIC_IN_AXIOMS_STRING, NULL_STRING_WRAPPER)))->wrapper_value;
    Object* newaxioms = NULL;

    remember_unfinalized_relation(self);
    if (stringP(constraints)) {
      constraints = unstringify(((String_Wrapper*)(constraints))->wrapper_value);
    }
    { Object* constraints_001 = constraints;

      if (consP(constraints)) {
        { Cons* constraints = NULL;

          constraints = ((Cons*)(constraints_001));
          if (consP(constraints->first())) {
            { Cons_Iterator* it = constraints->allocate_iterator();

              while (it->nextP()) {
                it->value_setter(complete_constraint_definition(self, it->value));
              }
            }
          }
          else {
            constraints = ((Cons*)(complete_constraint_definition(self, constraints)));
          }
          newaxioms = constraints;
        }
      }
      else {
        newaxioms = complete_constraint_definition(self, constraints);
      }
    }
    set_dynamic_slot_value(self, SYM_LOGIC_IN_AXIOMS_STRING, wrap_string(stringify(add_relation_axioms(self, ((oldaxioms == NULL) ? ((Object*)(NULL)) : ((Object*)(unstringify(oldaxioms)))), newaxioms))), NULL_STRING_WRAPPER);
  }
}

Object* complete_constraint_definition(Relation* self, Object* definition) {
  { Keyword* test_value_001 = self->logic_dialect();

    if (test_value_001 == KWD_LOGIC_IN_KIF) {
      { Cons* antecedent = yield_relation_parameters_tree(self, FALSE);

        { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oTRANSIENTOBJECTSpo = TRUE;
                { Relation* self_001 = self;

                  if (classP(self)) {
                    { Class* self = NULL;

                      self = ((Class*)(self_001));
                      antecedent = cons(class_symbol(self), antecedent);
                    }
                  }
                  else if (taxonomy_isaP(self, SGT_LOGIC_IN_SLOT)) {
                    { Slot* self = NULL;

                      self = ((Slot*)(self_001));
                      antecedent = cons(self->slot_name, antecedent);
                    }
                  }
                  else {
                    cerr << "`" << self << "'" << " is not a valid case option";
                  }
                }
                if (self->functionP()) {
                  antecedent = listO(3, SYM_LOGIC_IN_e, antecedent->reverse()->rest->reverse(), cons(((Slot*)(self))->value_variable_getter(), NIL));
                }
                { Cons* return_value_001 = listO(3, SYM_LOGIC_IN_FORALL, yield_relation_parameters_tree(self, TRUE), cons(listO(3, SYM_LOGIC_IN_eg, antecedent, cons(definition, NIL)), NIL));

                  oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  return (return_value_001);
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
    else {
      cerr << "complete-constraint-definition: Not yet implemented for dialect " << "`" << self->logic_dialect() << "'";
      return (NULL);
    }
  }
}

void remember_unfinalized_relation(Relation* self) {
  if ((((String_Wrapper*)(dynamic_slot_value(self, SYM_LOGIC_IN_DEFINITION_STRING, NULL_STRING_WRAPPER)))->wrapper_value == NULL) &&
      (((String_Wrapper*)(dynamic_slot_value(self, SYM_LOGIC_IN_AXIOMS_STRING, NULL_STRING_WRAPPER)))->wrapper_value == NULL)) {
    oUNFINALIZED_DEFINED_RELATIONSo->push(self);
  }
}

void finalize_defined_relation(Relation* self) {
  { Cons* old_OtoplevelpropositionsO_001 = oTOPLEVELPROPOSITIONSo;
    Keyword* old_Ologic_dialectO_001 = oLOGIC_DIALECTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTOPLEVELPROPOSITIONSo = NIL;
          oLOGIC_DIALECTo = self->logic_dialect();
          { Module* old_OmoduleO_001 = oMODULEo;
            Context* old_OcontextO_001 = oCONTEXTo;

            { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oMODULEo = self->home_module();
                  oCONTEXTo = oMODULEo;
                  set_dynamic_slot_value(self, SYM_LOGIC_IN_BADp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
                  if (((String_Wrapper*)(dynamic_slot_value(self, SYM_LOGIC_IN_DEFINITION_STRING, NULL_STRING_WRAPPER)))->wrapper_value != NULL) {
                    self->construct_relation_definition();
                    self->get_description();
                  }
                  if (((String_Wrapper*)(dynamic_slot_value(self, SYM_LOGIC_IN_AXIOMS_STRING, NULL_STRING_WRAPPER)))->wrapper_value != NULL) {
                    update_proposition(unstringify(((String_Wrapper*)(dynamic_slot_value(self, SYM_LOGIC_IN_AXIOMS_STRING, NULL_STRING_WRAPPER)))->wrapper_value), KWD_LOGIC_IN_ASSERT_TRUE);
                    if (oTOPLEVELPROPOSITIONSo != NULL) {
                      { List* self_001 = new_list();

                        self_001->the_cons_list = oTOPLEVELPROPOSITIONSo;
                        set_dynamic_slot_value(self, SYM_LOGIC_IN_RELATION_ORIGINATED_PROPOSITIONS, self_001, NULL);
                      }
                    }
                  }
                  set_dynamic_slot_value(self, SYM_LOGIC_IN_BADp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
                  oCONTEXTo = old_OcontextO_001;
                  oMODULEo = old_OmoduleO_001;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oCONTEXTo = old_OcontextO_001;
                oMODULEo = old_OmoduleO_001;
                resignal();
              }
            }
          }
          oLOGIC_DIALECTo = old_Ologic_dialectO_001;
          oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oLOGIC_DIALECTo = old_Ologic_dialectO_001;
        oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
        resignal();
      }
    }
  }
}

boolean finalized_relationP(Relation* self) {
  { boolean test_value_001 = FALSE;

    test_value_001 = (((String_Wrapper*)(dynamic_slot_value(self, SYM_LOGIC_IN_DEFINITION_STRING, NULL_STRING_WRAPPER)))->wrapper_value == NULL) ||
        ((((Description*)(dynamic_slot_value(self, SYM_LOGIC_IN_DEFINITION, NULL))) != NULL) ||
         ((((Description*)(dynamic_slot_value(self, SYM_LOGIC_IN_DESCRIPTION, NULL))) != NULL) &&
          (((Description*)(dynamic_slot_value(self, SYM_LOGIC_IN_DESCRIPTION, NULL)))->kind == KWD_LOGIC_IN_ENUMERATION)));
    if (test_value_001) {
      if (((String_Wrapper*)(dynamic_slot_value(self, SYM_LOGIC_IN_AXIOMS_STRING, NULL_STRING_WRAPPER)))->wrapper_value == NULL) {
        test_value_001 = TRUE;
      }
      else {
        {
          test_value_001 = self->relation_originated_propositions_reader() != NULL;
          if (test_value_001) {
            { boolean foundP_001 = FALSE;

              { Proposition* p = NULL;
                Cons* iter_001 = self->relation_originated_propositions_reader()->the_cons_list;

                while (!nilP(iter_001)) {
                  {
                    p = ((Proposition*)(iter_001->value));
                    iter_001 = iter_001->rest;
                  }
                  if (!p->subrelation_linkP_reader()) {
                    foundP_001 = TRUE;
                    break;
                  }
                }
              }
              test_value_001 = foundP_001;
            }
          }
        }
      }
    }
    { boolean value_001 = test_value_001;

      return (value_001);
    }
  }
}

void finalize_relations() {
  // Finalize all currently unfinalized relations.
  { Relation* relation = NULL;

    finalize_classes_and_slots();
    for (;;) {
      if (oUNFINALIZED_DEFINED_RELATIONSo != NULL) {
        relation = ((Relation*)(oUNFINALIZED_DEFINED_RELATIONSo->pop()));
      }
      if (relation == NULL) {
        break;
      }
      if ((!relation->deletedP()) &&
          (!finalized_relationP(relation))) {
        finalize_defined_relation(relation);
      }
    }
  }
}

Relation* define_relation_from_parse_tree(Cons* tree) {
  return (help_define_relation_from_parse_tree(tree, stringify(tree)));
}

Relation* deffunction(Cons* args) {
  // Define (or redefine) a logic function.  The accepted syntax is:
  // 	 
  //   (deffunction {<function-name> |
  //                 (<function-name> <value-type>)} (<var>+)
  //      [:documentation <docstring>]
  //      [:-> <value-variable>]
  //      [:type <value-type>]
  //      [[{:definition | :is} <relation-expression>] |
  //       [<=> <sentence-with-argument-variables>] |
  //       [:= <term-expression-with-argument-variables>]]
  //      [:polymorphic? {TRUE | FALSE}]
  //      [:axioms {<sentence> | (<sentence>+)}]
  //      [:constraints {<sentence-with-argument-variables> |
  //                     (<sentence-with-argument-variables>+)}]
  //      [:properties <list-of-properties>]
  //      [:meta-attributes <list-of-key-value-pairs>]
  //      [<other-options>*])
  // 	
  // Function parameters can be typed or untyped.  An untyped first parameter
  // or a `:polymorphic? FALSE' specification defines a non-polymorphic function.
  // Otherwise, the function will be polymorphic.  If a value variable is
  // specified, it must be specified before any definition options, otherwise,
  // the expansions of definitions might be incorrect.  The default KIF value
  // variable is `?value'.
  return (define_relation_from_parse_tree(cons(SYM_LOGIC_IN_DEFFUNCTION, args->concatenate(NIL))));
}

Relation* deffunction_evaluator_wrapper(Cons* arguments) {
  return (deffunction(((Cons*)(arguments))));
}

Relation* defrelation(Cons* args) {
  // Define (or redefine) a logic relation.  The accepted syntax is:
  // 	 
  //   (defrelation {<relation-name> | 
  //                 (<relation-name> BOOLEAN)} (<var>+)
  //      [:documentation <docstring>]
  //      [:type BOOLEAN]
  //      [[{:definition | :is} <relation-expression>] |
  //       [<=> <sentence-with-argument-variables>]]
  //      [:polymorphic? {TRUE | FALSE}]
  //      [:axioms {<sentence> | (<sentence>+)}]
  //      [:constraints {<sentence-with-argument-variables> |
  //                     (<sentence-with-argument-variables>+)}]
  //      [:properties <list-of-properties>]
  //      [:meta-attributes <list-of-key-value-pairs>]
  //      [<other-options>*])
  // 	
  // Relation parameters can be typed or untyped.  An untyped first parameter
  // or a `:polymorphic? FALSE' specification defines a non-polymorphic relation.
  // Otherwise, the relation will be polymorphic.
  return (define_relation_from_parse_tree(cons(SYM_LOGIC_IN_DEFRELATION, args->concatenate(NIL))));
}

Relation* defrelation_evaluator_wrapper(Cons* arguments) {
  return (defrelation(((Cons*)(arguments))));
}

Class* defconcept(Cons* args) {
  // Define (or redefine) a class that is not a sort.
  // The accepted syntax is identical to that of `defclass'.  The only difference
  // is that the value of the `:sort?' option will always be forced to be FALSE.
  // This means that unrestricted inference might be used to determine whether
  // a particular object is an instance of a non-sortal class defined with
  // `defconcept', since no disjointness assumptions can be made.  For example,
  // suppose a hierarchy contains the classes `Human' and `Featherless-Biped'
  // which share a common superclass, say `Living-Thing'.  If the two classes
  // were defined as sorts, their extensions are assumed to be disjoint.  Thus,
  // even if we have a rule 
  // 	 
  //   (forall (?x Living-Thing)
  //      (=> (and (Featherless ?x) (Biped ?x))
  //          (Featherless-Biped ?x)))
  // 	
  // and `Human's are in fact featherless and bipeds, we will not be able to
  // infer `Human's to be `Featherless-Biped's.  However, if `Featherless-Biped'
  // was defined with `defconcept', the rule will become applicable, since now
  // `Human's and `Featherless-Biped's are not necessarily disjoint anymore.
  // CAUTION: The semantics of sorts is still somwhat in flux.
  { Class* renamed_Class = define_class_from_parse_tree(cons(SYM_LOGIC_IN_DEFCLASS, args->concatenate(NIL)));

    if (renamed_Class != NULL) {
      set_dynamic_slot_value(renamed_Class, SYM_LOGIC_IN_SORTp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
    }
    return (renamed_Class);
  }
}

Class* defconcept_evaluator_wrapper(Cons* arguments) {
  return (defconcept(((Cons*)(arguments))));
}

boolean commandL(Method_Slot* command1, Method_Slot* command2) {
  return (stringL(command1->slot_name->visible_name(), command2->slot_name->visible_name()));
}

List* list_logic_commands() {
  { List* commands = new_list();

    { Method_Slot* function = NULL;
      Iterator* iter_001 = all_functions(string_get_module("/LOGIC", TRUE), TRUE);
      Cons* collect_001 = NULL;

      while (iter_001->nextP()) {
        {
          function = ((Method_Slot*)(iter_001->value));
        }
        if (function->method_commandP_reader()) {
          if (collect_001 == NULL) {
            {
              collect_001 = permanent_cons(function, NIL);
              if (commands->the_cons_list->emptyP()) {
                commands->the_cons_list = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(commands->the_cons_list, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = permanent_cons(function, NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
    }
    { Symbol* stellacommand = NULL;
      Cons* iter_002 = oLOGIC_RELEVANT_STELLA_COMMANDSo;
      Cons* collect_002 = NULL;

      while (!nilP(iter_002)) {
        {
          stellacommand = ((Symbol*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        if (collect_002 == NULL) {
          {
            collect_002 = permanent_cons(lookup_command(stellacommand), NIL);
            if (commands->the_cons_list->emptyP()) {
              commands->the_cons_list = collect_002;
            }
            else {
              add_cons_to_end_of_cons_list(commands->the_cons_list, collect_002);
            }
          }
        }
        else {
          {
            collect_002->rest = permanent_cons(lookup_command(stellacommand), NIL);
            collect_002 = collect_002->rest;
          }
        }
      }
    }
    return (commands->sort(((cpp_function_code)(&commandL))));
  }
}

void help(Cons* commands) {
  // Describe specific commands, or print a list of available commands.
  if (commands->emptyP()) {
    cout << "The following commands are available " << "(type `(help <command>+)'" << endl << "to get command-specific documentation):" << endl << endl;
    { Method_Slot* command = NULL;
      Cons* iter_001 = list_logic_commands()->the_cons_list;

      while (!nilP(iter_001)) {
        {
          command = ((Method_Slot*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        command->print_documentation(STANDARD_OUTPUT, TRUE);
      }
    }
  }
  else {
    { Symbol* commandname = NULL;
      Cons* iter_002 = commands;

      while (!nilP(iter_002)) {
        {
          commandname = ((Symbol*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        { Method_Slot* command = lookup_command(commandname);

          if (command != NULL) {
            command->print_documentation(STANDARD_OUTPUT, FALSE);
          }
          else {
            cout << "Undefined command: " << "`" << commandname << "'" << endl;
          }
        }
      }
    }
  }
}

void help_evaluator_wrapper(Cons* arguments) {
  help(((Cons*)(arguments)));
}

void startup_logic_in() {
  if (current_startup_time_phaseP(1)) {
    define_module_from_stringified_source("/PL-USER", "(:USES (\"LOGIC\" \"STELLA\"))");
  }
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
            KWD_LOGIC_IN_GOAL_TRACE = ((Keyword*)(intern_rigid_symbol_wrt_module("GOAL-TRACE", NULL, 2)));
            KWD_LOGIC_IN_CLOSED_WORLD = ((Keyword*)(intern_rigid_symbol_wrt_module("CLOSED-WORLD", NULL, 2)));
            KWD_LOGIC_IN_GOAL_TREE = ((Keyword*)(intern_rigid_symbol_wrt_module("GOAL-TREE", NULL, 2)));
            SGT_LOGIC_IN_LOGIC_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-EXCEPTION", NULL, 1)));
            SYM_LOGIC_IN_EVALUATOR_WRAPPER_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("EVALUATOR-WRAPPER-CODE", string_get_module("/STELLA", TRUE), 0)));
            KWD_LOGIC_IN_REALISTIC = ((Keyword*)(intern_rigid_symbol_wrt_module("REALISTIC", NULL, 2)));
            SYM_LOGIC_IN_oCAREFUL_LOGIC_COMMAND_LOOP_EXITop = ((Symbol*)(intern_rigid_symbol_wrt_module("*CAREFUL-LOGIC-COMMAND-LOOP-EXIT*?", NULL, 0)));
            KWD_LOGIC_IN_BYE = ((Keyword*)(intern_rigid_symbol_wrt_module("BYE", NULL, 2)));
            KWD_LOGIC_IN_EXIT = ((Keyword*)(intern_rigid_symbol_wrt_module("EXIT", NULL, 2)));
            KWD_LOGIC_IN_HALT = ((Keyword*)(intern_rigid_symbol_wrt_module("HALT", NULL, 2)));
            KWD_LOGIC_IN_QUIT = ((Keyword*)(intern_rigid_symbol_wrt_module("QUIT", NULL, 2)));
            KWD_LOGIC_IN_STOP = ((Keyword*)(intern_rigid_symbol_wrt_module("STOP", NULL, 2)));
            SYM_LOGIC_IN_BYE = ((Symbol*)(intern_rigid_symbol_wrt_module("BYE", NULL, 0)));
            SYM_LOGIC_IN_EXIT = ((Symbol*)(intern_rigid_symbol_wrt_module("EXIT", NULL, 0)));
            SYM_LOGIC_IN_HALT = ((Symbol*)(intern_rigid_symbol_wrt_module("HALT", NULL, 0)));
            SYM_LOGIC_IN_QUIT = ((Symbol*)(intern_rigid_symbol_wrt_module("QUIT", NULL, 0)));
            SYM_LOGIC_IN_STOP = ((Symbol*)(intern_rigid_symbol_wrt_module("STOP", NULL, 0)));
            SGT_LOGIC_IN_READ_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("READ-EXCEPTION", string_get_module("/STELLA", TRUE), 1)));
            KWD_LOGIC_IN_DEFINE = ((Keyword*)(intern_rigid_symbol_wrt_module("DEFINE", NULL, 2)));
            SYM_LOGIC_IN_DEFCLASS = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFCLASS", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_DEFSLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFSLOT", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_DEFUN = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFUN", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_DEFMETHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFMETHOD", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_DEFMODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFMODULE", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_IN_MODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("IN-MODULE", string_get_module("/STELLA", TRUE), 0)));
            SGT_LOGIC_IN_CLASS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CLASS", string_get_module("/STELLA", TRUE), 1)));
            SGT_LOGIC_IN_STORAGE_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT", string_get_module("/STELLA", TRUE), 1)));
            SGT_LOGIC_IN_METHOD_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("METHOD-SLOT", string_get_module("/STELLA", TRUE), 1)));
            SGT_LOGIC_IN_MODULE = ((Surrogate*)(intern_rigid_symbol_wrt_module("MODULE", string_get_module("/STELLA", TRUE), 1)));
            SGT_LOGIC_IN_VOID = ((Surrogate*)(intern_rigid_symbol_wrt_module("VOID", string_get_module("/STELLA", TRUE), 1)));
            SGT_LOGIC_IN_CONS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONS", string_get_module("/STELLA", TRUE), 1)));
            KWD_LOGIC_IN_FINALIZE = ((Keyword*)(intern_rigid_symbol_wrt_module("FINALIZE", NULL, 2)));
            SYM_LOGIC_IN_CLEAR_MODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLEAR-MODULE", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_IN_DIALECT = ((Symbol*)(intern_rigid_symbol_wrt_module("IN-DIALECT", NULL, 0)));
            SYM_LOGIC_IN_oDEMO_LEVELo = ((Symbol*)(intern_rigid_symbol_wrt_module("*DEMO-LEVEL*", NULL, 0)));
            SYM_LOGIC_IN_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_SORTp = ((Symbol*)(intern_rigid_symbol_wrt_module("SORT?", NULL, 0)));
            SYM_LOGIC_IN_RELATION_PARAMETER_NAMES = ((Symbol*)(intern_rigid_symbol_wrt_module("RELATION-PARAMETER-NAMES", NULL, 0)));
            KWD_LOGIC_IN_KIF = ((Keyword*)(intern_rigid_symbol_wrt_module("KIF", NULL, 2)));
            SYM_LOGIC_IN_pSELF = ((Symbol*)(intern_rigid_symbol_wrt_module("?SELF", NULL, 0)));
            SYM_LOGIC_IN_SELF = ((Symbol*)(intern_rigid_symbol_wrt_module("SELF", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_SELF_VARIABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("SELF-VARIABLE", NULL, 0)));
            SYM_LOGIC_IN_pVALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("?VALUE", NULL, 0)));
            SYM_LOGIC_IN_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_VALUE_VARIABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE-VARIABLE", NULL, 0)));
            SYM_LOGIC_IN_DEFFUNCTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFFUNCTION", NULL, 0)));
            SGT_LOGIC_IN_UNKNOWN = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNKNOWN", string_get_module("/STELLA", TRUE), 1)));
            KWD_LOGIC_IN_POLYMORPHICp = ((Keyword*)(intern_rigid_symbol_wrt_module("POLYMORPHIC?", NULL, 2)));
            KWD_LOGIC_IN_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("TYPE", NULL, 2)));
            SGT_LOGIC_IN_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", string_get_module("/STELLA", TRUE), 1)));
            SYM_LOGIC_IN_BOOLEAN = ((Symbol*)(intern_rigid_symbol_wrt_module("BOOLEAN", string_get_module("/STELLA", TRUE), 0)));
            KWD_LOGIC_IN_ABSTRACTp = ((Keyword*)(intern_rigid_symbol_wrt_module("ABSTRACT?", NULL, 2)));
            SYM_LOGIC_IN_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", string_get_module("/STELLA", TRUE), 0)));
            KWD_LOGIC_IN_SELF_VARIABLE = ((Keyword*)(intern_rigid_symbol_wrt_module("SELF-VARIABLE", NULL, 2)));
            SYM_LOGIC_IN_VARIABLE_ARITYp = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-ARITY?", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_SLOT_TYPE_SPECIFIER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-TYPE-SPECIFIER", string_get_module("/STELLA", TRUE), 0)));
            KWD_LOGIC_IN_DOCUMENTATION = ((Keyword*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 2)));
            SYM_LOGIC_IN_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", string_get_module("/STELLA", TRUE), 0)));
            KWD_LOGIC_IN_SINGLE_VALUEDp = ((Keyword*)(intern_rigid_symbol_wrt_module("SINGLE-VALUED?", NULL, 2)));
            KWD_LOGIC_IN_PROPERTIES = ((Keyword*)(intern_rigid_symbol_wrt_module("PROPERTIES", NULL, 2)));
            SYM_LOGIC_IN_PROPERTIES = ((Symbol*)(intern_rigid_symbol_wrt_module("PROPERTIES", string_get_module("/STELLA", TRUE), 0)));
            KWD_LOGIC_IN_META_ATTRIBUTES = ((Keyword*)(intern_rigid_symbol_wrt_module("META-ATTRIBUTES", NULL, 2)));
            SYM_LOGIC_IN_META_ATTRIBUTES = ((Symbol*)(intern_rigid_symbol_wrt_module("META-ATTRIBUTES", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_RELATION_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("RELATION-STRINGIFIED-SOURCE", NULL, 0)));
            SYM_LOGIC_IN_aREST = ((Symbol*)(intern_rigid_symbol_wrt_module("&REST", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_ARGUMENT_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("ARGUMENT-LIST", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_OF = ((Symbol*)(intern_rigid_symbol_wrt_module("OF", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_RELATION_ORIGINATED_PROPOSITIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("RELATION-ORIGINATED-PROPOSITIONS", NULL, 0)));
            SGT_LOGIC_IN_BOOLEAN_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN-WRAPPER", string_get_module("/STELLA", TRUE), 1)));
            SYM_LOGIC_IN_DEFINITION_STRING = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINITION-STRING", NULL, 0)));
            SYM_LOGIC_IN_SLOT_OPTION_KEYWORD = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-OPTION-KEYWORD", string_get_module("/STELLA", TRUE), 0)));
            SGT_LOGIC_IN_TABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TABLE", string_get_module("/STELLA", TRUE), 1)));
            SYM_LOGIC_IN_UNKNOWN = ((Symbol*)(intern_rigid_symbol_wrt_module("UNKNOWN", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_AND = ((Symbol*)(intern_rigid_symbol_wrt_module("AND", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_SETOFALL = ((Symbol*)(intern_rigid_symbol_wrt_module("SETOFALL", NULL, 0)));
            SYM_LOGIC_IN_KAPPA = ((Symbol*)(intern_rigid_symbol_wrt_module("KAPPA", NULL, 0)));
            SYM_LOGIC_IN_e = ((Symbol*)(intern_rigid_symbol_wrt_module("=", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_AXIOMS_STRING = ((Symbol*)(intern_rigid_symbol_wrt_module("AXIOMS-STRING", NULL, 0)));
            SGT_LOGIC_IN_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("SLOT", string_get_module("/STELLA", TRUE), 1)));
            SYM_LOGIC_IN_FORALL = ((Symbol*)(intern_rigid_symbol_wrt_module("FORALL", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_eg = ((Symbol*)(intern_rigid_symbol_wrt_module("=>", string_get_module("/STELLA", TRUE), 0)));
            SYM_LOGIC_IN_BADp = ((Symbol*)(intern_rigid_symbol_wrt_module("BAD?", string_get_module("/STELLA", TRUE), 0)));
            KWD_LOGIC_IN_ASSERT_TRUE = ((Keyword*)(intern_rigid_symbol_wrt_module("ASSERT-TRUE", NULL, 2)));
            SYM_LOGIC_IN_DEFINITION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINITION", NULL, 0)));
            SYM_LOGIC_IN_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 0)));
            KWD_LOGIC_IN_ENUMERATION = ((Keyword*)(intern_rigid_symbol_wrt_module("ENUMERATION", NULL, 2)));
            SYM_LOGIC_IN_DEFRELATION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFRELATION", NULL, 0)));
            SYM_LOGIC_IN_CC = ((Symbol*)(intern_rigid_symbol_wrt_module("CC", string_get_module("/STELLA", TRUE), 0)));
          }
          if (current_startup_time_phaseP(4)) {
            oAVAILABLE_POWERLOOM_FEATURESo = list(2, KWD_LOGIC_IN_GOAL_TRACE, KWD_LOGIC_IN_CLOSED_WORLD);
            oCURRENT_POWERLOOM_FEATURESo = list(0);
            oDEFAULT_POWERLOOM_FEATURESo = list(0);
            reset_features();
            oDEMO_FILESo = listO(10, listO(3, string_wrap_literal("basics"), string_wrap_literal("Basic PowerLoom commands"), NIL), listO(3, string_wrap_literal("classes"), string_wrap_literal("Primitive and defined classes"), NIL), listO(3, string_wrap_literal("collections"), string_wrap_literal("Reasoning with collections"), NIL), listO(3, string_wrap_literal("append"), string_wrap_literal("Prolog-style `append'"), NIL), listO(3, string_wrap_literal("named-rules"), string_wrap_literal("Using named rules"), NIL), listO(3, string_wrap_literal("recursion"), string_wrap_literal("Reasoning with recursive rules"), NIL), listO(3, string_wrap_literal("negation"), string_wrap_literal("Reasoning with negation"), NIL), listO(3, string_wrap_literal("constraints"), string_wrap_literal("Constraint propagation"), NIL), listO(3, string_wrap_literal("subsumption"), string_wrap_literal("Subsumption"), NIL), NIL);
            oUNFINALIZED_DEFINED_RELATIONSo = list(0);
            oLOGIC_RELEVANT_STELLA_COMMANDSo = listO(6, SYM_LOGIC_IN_CC, SYM_LOGIC_IN_CLEAR_MODULE, SYM_LOGIC_IN_DEFCLASS, SYM_LOGIC_IN_DEFMODULE, SYM_LOGIC_IN_IN_MODULE, NIL);
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("PRINT-FEATURES", NULL, "(DEFUN PRINT-FEATURES () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Print the currently enabled and available PowerLoom environment features.\")");

              method->function_code = ((cpp_function_code)(&print_features));
            }
            { Method_Slot* method = define_method_from_stringified_source("SET-POWERLOOM-FEATURE", "KEYWORD", "(DEFUN SET-POWERLOOM-FEATURE ((FEATURE KEYWORD)) :DOCUMENTATION \"Enable the PowerLoom environment feature `feature'.\")");

              method->function_code = ((cpp_function_code)(&set_powerloom_feature));
            }
            { Method_Slot* method = define_method_from_stringified_source("SET-FEATURE", "ARGUMENT-LIST", "(DEFUN (SET-FEATURE (LIST OF KEYWORD)) (|&REST| (FEATURES NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Enable the PowerLoom environment feature(s) named by `features'.\nReturn the list of enabled features.  Calling `set-feature' without any\narguments can be used to display the currently enabled features.\nThe following features are supported:\n\n`closed-world': Enables closed-world reasoning.  NOT YET IMPLEMENTED!\n\n`goal-trace': Enables the generation of goal trace information during\ninference.\")");

              method->function_code = ((cpp_function_code)(&set_feature));
              set_dynamic_slot_value(method, SYM_LOGIC_IN_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&set_feature_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("UNSET-POWERLOOM-FEATURE", "KEYWORD", "(DEFUN UNSET-POWERLOOM-FEATURE ((FEATURE KEYWORD)) :DOCUMENTATION \"Disable the PowerLoom environment feature `feature'.\")");

              method->function_code = ((cpp_function_code)(&unset_powerloom_feature));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNSET-FEATURE", "ARGUMENT-LIST", "(DEFUN (UNSET-FEATURE (LIST OF KEYWORD)) (|&REST| (FEATURES NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Disable the PowerLoom environment feature(s) named by `features'.\nReturn the list of enabled features.  Calling `unset-feature' without any\narguments can be used to display the currently enabled features.\nSee `set-feature' for a description of supported features.\")");

              method->function_code = ((cpp_function_code)(&unset_feature));
              set_dynamic_slot_value(method, SYM_LOGIC_IN_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&unset_feature_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("RESET-FEATURES", NULL, "(DEFUN (RESET-FEATURES (LIST OF KEYWORD)) () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Reset the PowerLoom environment features to their default settings.\")");

              method->function_code = ((cpp_function_code)(&reset_features));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-LOGIC-PROMPT", NULL, "(DEFUN PRINT-LOGIC-PROMPT ())");

              method->function_code = ((cpp_function_code)(&print_logic_prompt));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-LOGIC-COMMAND-RESULT", "OBJECT", "(DEFUN PRINT-LOGIC-COMMAND-RESULT ((RESULT OBJECT) (RESULTTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&print_logic_command_result));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOGIC-COMMAND-LOOP-EXIT?", "OBJECT", "(DEFUN (LOGIC-COMMAND-LOOP-EXIT? BOOLEAN BOOLEAN) ((COMMAND OBJECT)))");

              method->function_code = ((cpp_function_code)(&logic_command_loop_exitP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOGIC-COMMAND-LOOP", NULL, "(DEFUN LOGIC-COMMAND-LOOP ())");

              method->function_code = ((cpp_function_code)(&logic_command_loop));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-LOGIC-COMMAND", "OBJECT", "(DEFUN (EVALUATE-LOGIC-COMMAND OBJECT TYPE-SPEC BOOLEAN) ((COMMAND OBJECT) (FINALIZE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&evaluate_logic_command));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOAD", "STRING", "(DEFUN LOAD ((FILE STRING)) :DOCUMENTATION \"Read logic commands from `file' and evaluate them.\" :COMMAND? TRUE :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&load));
              set_dynamic_slot_value(method, SYM_LOGIC_IN_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&load_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-DEMO-PROMPT", NULL, "(DEFUN PRINT-DEMO-PROMPT ())");

              method->function_code = ((cpp_function_code)(&print_demo_prompt));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEMO-SKIP-TO-COMMAND", "INPUT-STREAM", "(DEFUN (DEMO-SKIP-TO-COMMAND BOOLEAN) ((STREAM INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&demo_skip_to_command));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEMO-PAUSE?", "BOOLEAN", "(DEFUN (DEMO-PAUSE? BOOLEAN BOOLEAN) ((PAUSE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&demo_pauseP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEMO-FILE", "FILE-NAME", "(DEFUN DEMO-FILE ((FILE FILE-NAME) (PAUSE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&demo_file));
            }
            { Method_Slot* method = define_method_from_stringified_source("SELECT-EXAMPLE-DEMO", "INTEGER", "(DEFUN (SELECT-EXAMPLE-DEMO STRING) ((INDEX INTEGER)))");

              method->function_code = ((cpp_function_code)(&select_example_demo));
            }
            { Method_Slot* method = define_method_from_stringified_source("SELECT-EXAMPLE-DEMO-FROM-MENU", NULL, "(DEFUN (SELECT-EXAMPLE-DEMO-FROM-MENU STRING) ())");

              method->function_code = ((cpp_function_code)(&select_example_demo_from_menu));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEMO-EXAMPLE-DEMOS", NULL, "(DEFUN DEMO-EXAMPLE-DEMOS ())");

              method->function_code = ((cpp_function_code)(&demo_example_demos));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEMO", "ARGUMENT-LIST", "(DEFUN DEMO (|&REST| (FILEANDPAUSE OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Read logic commands from a file, echo them verbatimly to standard output,\nand evaluate them just as if they had been typed in interactively.\nWhen called with no arguments, present a menu of example demos, otherwise,\nuse the first argument as the name of the file to demo.\nPause for user confirmation after each expression has been read but\nbefore it is evaluated.  Pausing can be turned off by suppling FALSE\nas the optional second argument, or by typing `c' at the pause prompt.\nTyping `?' at the pause prompt prints a list of available commands.\")");

              method->function_code = ((cpp_function_code)(&demo));
              set_dynamic_slot_value(method, SYM_LOGIC_IN_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&demo_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("TEST-LOGIC-FILE", "FILE-NAME", "(DEFUN TEST-LOGIC-FILE ((FILE FILE-NAME)))");

              method->function_code = ((cpp_function_code)(&test_logic_file));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-POWERLOOM-TESTS", NULL, "(DEFUN RUN-POWERLOOM-TESTS () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Run the PowerLoom test suite.  Currently this simply runs all demos and\nechos commands and their results to standard output.  The output can then\nbe diffed with previously validated runs to find deviations.\")");

              method->function_code = ((cpp_function_code)(&run_powerloom_tests));
            }
            define_external_slot_from_stringified_source("(DEFSLOT RELATION SORT? :TYPE BOOLEAN :OPTION-KEYWORD :SORT? :DOCUMENTATION \"If TRUE, indicates that the relation is a class \nbelonging to a sortal hierarchy that assumes disjointness of sorts\n(classes) not having a common subsort.\" :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT CLASS SORT? :TYPE BOOLEAN :DEFAULT TRUE :OPTION-KEYWORD :SORT? :DOCUMENTATION \"If TRUE, indicates that the class is a sort.\" :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT RELATION RELATION-STRINGIFIED-SOURCE :TYPE STRING :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT TABLE RELATION-PARAMETER-NAMES :TYPE (LIST OF SYMBOL) :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT TABLE RELATION-PARAMETER-TYPE-SPECIFIERS :RENAMES TUPLE-DOMAINS)");
            define_external_slot_from_stringified_source("(DEFSLOT RELATION SELF-VARIABLE :TYPE SYMBOL :READER SELF-VARIABLE-GETTER :OPTION-KEYWORD :SELF-VARIABLE :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT SLOT VALUE-VARIABLE :TYPE SYMBOL :READER VALUE-VARIABLE-GETTER :OPTION-KEYWORD :-> :ALLOCATION :DYNAMIC)");
            { Method_Slot* method = define_method_from_stringified_source("LOGIC-DIALECT", "RELATION", "(DEFMETHOD (LOGIC-DIALECT KEYWORD) ((SELF RELATION)))");

              method->method_code = ((cpp_method_code)(&Relation::logic_dialect));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFAULT-SELF-VARIABLE", "RELATION", "(DEFUN (DEFAULT-SELF-VARIABLE SYMBOL) ((SELF RELATION)))");

              method->function_code = ((cpp_function_code)(&default_self_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("SELF-VARIABLE-GETTER", "RELATION", "(DEFMETHOD (SELF-VARIABLE-GETTER SYMBOL) ((SELF RELATION)))");

              method->method_code = ((cpp_method_code)(&Relation::self_variable_getter));
            }
            { Method_Slot* method = define_method_from_stringified_source("SELF-VARIABLE-GETTER", "TABLE", "(DEFMETHOD (SELF-VARIABLE-GETTER SYMBOL) ((SELF TABLE)))");

              method->method_code = ((cpp_method_code)(&Table::self_variable_getter));
            }
            { Method_Slot* method = define_method_from_stringified_source("SELF-VARIABLE-GETTER", "METHOD-SLOT", "(DEFMETHOD (SELF-VARIABLE-GETTER SYMBOL) ((SELF METHOD-SLOT)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::self_variable_getter));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFAULT-VALUE-VARIABLE", "RELATION", "(DEFUN (DEFAULT-VALUE-VARIABLE SYMBOL) ((SELF RELATION)))");

              method->function_code = ((cpp_function_code)(&default_value_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALUE-VARIABLE-GETTER", "SLOT", "(DEFMETHOD (VALUE-VARIABLE-GETTER SYMBOL) ((SELF SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::value_variable_getter));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-DEFINE-RELATION-FROM-PARSE-TREE", "CONS", "(DEFUN (HELP-DEFINE-RELATION-FROM-PARSE-TREE RELATION) ((TREE CONS) (STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&help_define_relation_from_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("PARSE-RELATION-PARAMETERS-TREE", "CONS", "(DEFUN (PARSE-RELATION-PARAMETERS-TREE (LIST OF SYMBOL) (LIST OF TYPE-SPEC) BOOLEAN) ((PARAMETERS CONS)))");

              method->function_code = ((cpp_function_code)(&parse_relation_parameters_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-IDENTICAL-RELATION", "SYMBOL", "(DEFUN (GET-IDENTICAL-RELATION RELATION) ((NAME SYMBOL) (OWNER TYPE) (POLYMORPHIC? BOOLEAN) (STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&get_identical_relation));
            }
            define_external_slot_from_stringified_source("(DEFSLOT RELATION DEFINITION-STRING :TYPE STRING :OPTION-KEYWORD :IS :OPTION-HANDLER RELATION-FULL-DEFINITION-HANDLER :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT RELATION DEFINITION-STRING-ALIAS :RENAMES DEFINITION-STRING :OPTION-KEYWORD :DEFINITION :OPTION-HANDLER RELATION-FULL-DEFINITION-HANDLER)");
            define_external_slot_from_stringified_source("(DEFSLOT RELATION DEFINITION-STRING-ALIAS2 :RENAMES DEFINITION-STRING :OPTION-KEYWORD :<=> :OPTION-HANDLER RELATION-SENTENCE-DEFINITION-HANDLER)");
            define_external_slot_from_stringified_source("(DEFSLOT RELATION DEFINITION-STRING-ALIAS3 :RENAMES DEFINITION-STRING :OPTION-KEYWORD := :OPTION-HANDLER RELATION-TERM-DEFINITION-HANDLER)");
            define_external_slot_from_stringified_source("(DEFSLOT RELATION AXIOMS-STRING :TYPE STRING :OPTION-KEYWORD :AXIOMS :OPTION-HANDLER RELATION-AXIOMS-HANDLER :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT RELATION AXIOMS-STRING-ALIAS :RENAMES AXIOMS-STRING :OPTION-KEYWORD :CONSTRAINTS :OPTION-HANDLER RELATION-CONSTRAINTS-HANDLER)");
            define_external_slot_from_stringified_source("(DEFSLOT RELATION RELATION-ORIGINATED-PROPOSITIONS :TYPE (LIST OF PROPOSITION) :ALLOCATION :DYNAMIC)");
            { Method_Slot* method = define_method_from_stringified_source("FUNCTION?", "RELATION", "(DEFMETHOD (FUNCTION? BOOLEAN) ((SELF RELATION)))");

              method->method_code = ((cpp_method_code)(&Relation::functionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FUNCTION?", "SLOT", "(DEFMETHOD (FUNCTION? BOOLEAN) ((SELF SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::functionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("RELATION-FULL-DEFINITION-HANDLER", "RELATION", "(DEFUN RELATION-FULL-DEFINITION-HANDLER ((SELF RELATION) (SLOT STORAGE-SLOT) (DEFINITION OBJECT)))");

              method->function_code = ((cpp_function_code)(&relation_full_definition_handler));
            }
            { Method_Slot* method = define_method_from_stringified_source("RELATION-SENTENCE-DEFINITION-HANDLER", "RELATION", "(DEFUN RELATION-SENTENCE-DEFINITION-HANDLER ((SELF RELATION) (SLOT STORAGE-SLOT) (DEFINITION OBJECT)))");

              method->function_code = ((cpp_function_code)(&relation_sentence_definition_handler));
            }
            { Method_Slot* method = define_method_from_stringified_source("RELATION-TERM-DEFINITION-HANDLER", "RELATION", "(DEFUN RELATION-TERM-DEFINITION-HANDLER ((SELF RELATION) (SLOT STORAGE-SLOT) (DEFINITION OBJECT)))");

              method->function_code = ((cpp_function_code)(&relation_term_definition_handler));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-RELATION-PARAMETERS-TREE", "RELATION", "(DEFUN (YIELD-RELATION-PARAMETERS-TREE CONS) ((SELF RELATION) (TYPED? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&yield_relation_parameters_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPLETE-SENTENCE-DEFINITION", "RELATION", "(DEFUN (COMPLETE-SENTENCE-DEFINITION OBJECT) ((SELF RELATION) (DEFINITION OBJECT)))");

              method->function_code = ((cpp_function_code)(&complete_sentence_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPLETE-TERM-DEFINITION", "SLOT", "(DEFUN (COMPLETE-TERM-DEFINITION OBJECT) ((SELF SLOT) (DEFINITION OBJECT)))");

              method->function_code = ((cpp_function_code)(&complete_term_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("RELATION-AXIOMS-HANDLER", "RELATION", "(DEFUN RELATION-AXIOMS-HANDLER ((SELF RELATION) (SLOT STORAGE-SLOT) (AXIOMS OBJECT)))");

              method->function_code = ((cpp_function_code)(&relation_axioms_handler));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-RELATION-AXIOMS", "RELATION", "(DEFUN (ADD-RELATION-AXIOMS OBJECT) ((SELF RELATION) (OLDAXIOMS OBJECT) (NEWAXIOMS OBJECT)))");

              method->function_code = ((cpp_function_code)(&add_relation_axioms));
            }
            { Method_Slot* method = define_method_from_stringified_source("RELATION-CONSTRAINTS-HANDLER", "RELATION", "(DEFUN RELATION-CONSTRAINTS-HANDLER ((SELF RELATION) (SLOT STORAGE-SLOT) (CONSTRAINTS OBJECT)))");

              method->function_code = ((cpp_function_code)(&relation_constraints_handler));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPLETE-CONSTRAINT-DEFINITION", "RELATION", "(DEFUN (COMPLETE-CONSTRAINT-DEFINITION OBJECT) ((SELF RELATION) (DEFINITION OBJECT)))");

              method->function_code = ((cpp_function_code)(&complete_constraint_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMEMBER-UNFINALIZED-RELATION", "RELATION", "(DEFUN REMEMBER-UNFINALIZED-RELATION ((SELF RELATION)))");

              method->function_code = ((cpp_function_code)(&remember_unfinalized_relation));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-DEFINED-RELATION", "RELATION", "(DEFUN FINALIZE-DEFINED-RELATION ((SELF RELATION)))");

              method->function_code = ((cpp_function_code)(&finalize_defined_relation));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZED-RELATION?", "RELATION", "(DEFUN (FINALIZED-RELATION? BOOLEAN) ((SELF RELATION)))");

              method->function_code = ((cpp_function_code)(&finalized_relationP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-RELATIONS", NULL, "(DEFUN FINALIZE-RELATIONS () :DOCUMENTATION \"Finalize all currently unfinalized relations.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&finalize_relations));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-RELATION-FROM-PARSE-TREE", "CONS", "(DEFUN (DEFINE-RELATION-FROM-PARSE-TREE RELATION) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&define_relation_from_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFFUNCTION", "ARGUMENT-LIST", "(DEFUN (DEFFUNCTION RELATION) (|&REST| (ARGS PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a logic function.  The accepted syntax is:\n	 \n  (deffunction {<function-name> |\n                (<function-name> <value-type>)} (<var>+)\n     [:documentation <docstring>]\n     [:-> <value-variable>]\n     [:type <value-type>]\n     [[{:definition | :is} <relation-expression>] |\n      [<=> <sentence-with-argument-variables>] |\n      [:= <term-expression-with-argument-variables>]]\n     [:polymorphic? {TRUE | FALSE}]\n     [:axioms {<sentence> | (<sentence>+)}]\n     [:constraints {<sentence-with-argument-variables> |\n                    (<sentence-with-argument-variables>+)}]\n     [:properties <list-of-properties>]\n     [:meta-attributes <list-of-key-value-pairs>]\n     [<other-options>*])\n	\nFunction parameters can be typed or untyped.  An untyped first parameter\nor a `:polymorphic? FALSE' specification defines a non-polymorphic function.\nOtherwise, the function will be polymorphic.  If a value variable is\nspecified, it must be specified before any definition options, otherwise,\nthe expansions of definitions might be incorrect.  The default KIF value\nvariable is `?value'.\")");

              method->function_code = ((cpp_function_code)(&deffunction));
              set_dynamic_slot_value(method, SYM_LOGIC_IN_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&deffunction_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFRELATION", "ARGUMENT-LIST", "(DEFUN (DEFRELATION RELATION) (|&REST| (ARGS PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a logic relation.  The accepted syntax is:\n	 \n  (defrelation {<relation-name> | \n                (<relation-name> BOOLEAN)} (<var>+)\n     [:documentation <docstring>]\n     [:type BOOLEAN]\n     [[{:definition | :is} <relation-expression>] |\n      [<=> <sentence-with-argument-variables>]]\n     [:polymorphic? {TRUE | FALSE}]\n     [:axioms {<sentence> | (<sentence>+)}]\n     [:constraints {<sentence-with-argument-variables> |\n                    (<sentence-with-argument-variables>+)}]\n     [:properties <list-of-properties>]\n     [:meta-attributes <list-of-key-value-pairs>]\n     [<other-options>*])\n	\nRelation parameters can be typed or untyped.  An untyped first parameter\nor a `:polymorphic? FALSE' specification defines a non-polymorphic relation.\nOtherwise, the relation will be polymorphic.\")");

              method->function_code = ((cpp_function_code)(&defrelation));
              set_dynamic_slot_value(method, SYM_LOGIC_IN_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&defrelation_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            define_method_from_stringified_source("DEFCLASS", "ARGUMENT-LIST", "(DEFUN (DEFCLASS CLASS) (|&REST| (ARGS PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :NATIVE? TRUE :DOCUMENTATION \"Define (or redefine) a class.  The accepted syntax is:\n	 \n  (defclass <class-name> (<superclass-name>*)\n     [:documentation <docstring>]\n     [:self-variable <var>]\n     [[{:definition | :is} <relation-expression>] |\n      [<=> <sentence-with-argument-variables>]]\n     [:axioms {<sentence> | (<sentence>+)}]\n     [:constraints {<sentence-with-argument-variables> |\n                    (<sentence-with-argument-variables>+)}]\n     [:sort? {TRUE | FALSE}]\n     [:properties <list-of-properties>]\n     [:meta-attributes <list-of-key-value-pairs>]\n     [:slots ({(<slot-name> <slot-options>*)}*)]\n     [<other-options>*])\n	\n<slot-options> is a list of keyword/value pairs.  The set of legal slot\noptions is the same as those accepted by `defrelation'.  Unless the `:sort?'\noption specifies otherwise, classes defined with `defclass' are assumed\nto be sorts, i.e., the extensions of two sibling classes that don't share\na common subclass are assumed to be disjoint.\nCAUTION: The semantics of sorts is still somwhat in flux.\")");
            { Method_Slot* method = define_method_from_stringified_source("DEFCONCEPT", "ARGUMENT-LIST", "(DEFUN (DEFCONCEPT CLASS) (|&REST| (ARGS PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a class that is not a sort.\nThe accepted syntax is identical to that of `defclass'.  The only difference\nis that the value of the `:sort?' option will always be forced to be FALSE.\nThis means that unrestricted inference might be used to determine whether\na particular object is an instance of a non-sortal class defined with\n`defconcept', since no disjointness assumptions can be made.  For example,\nsuppose a hierarchy contains the classes `Human' and `Featherless-Biped'\nwhich share a common superclass, say `Living-Thing'.  If the two classes\nwere defined as sorts, their extensions are assumed to be disjoint.  Thus,\neven if we have a rule \n	 \n  (forall (?x Living-Thing)\n     (=> (and (Featherless ?x) (Biped ?x))\n         (Featherless-Biped ?x)))\n	\nand `Human's are in fact featherless and bipeds, we will not be able to\ninfer `Human's to be `Featherless-Biped's.  However, if `Featherless-Biped'\nwas defined with `defconcept', the rule will become applicable, since now\n`Human's and `Featherless-Biped's are not necessarily disjoint anymore.\nCAUTION: The semantics of sorts is still somwhat in flux.\")");

              method->function_code = ((cpp_function_code)(&defconcept));
              set_dynamic_slot_value(method, SYM_LOGIC_IN_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&defconcept_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("COMMAND<", "METHOD-SLOT", "(DEFUN (COMMAND< BOOLEAN) ((COMMAND1 METHOD-SLOT) (COMMAND2 METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&commandL));
            }
            { Method_Slot* method = define_method_from_stringified_source("LIST-LOGIC-COMMANDS", NULL, "(DEFUN (LIST-LOGIC-COMMANDS (LIST OF METHOD-SLOT)) ())");

              method->function_code = ((cpp_function_code)(&list_logic_commands));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP", "ARGUMENT-LIST", "(DEFUN HELP (|&REST| (COMMANDS SYMBOL)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Describe specific commands, or print a list of available commands.\")");

              method->function_code = ((cpp_function_code)(&help));
              set_dynamic_slot_value(method, SYM_LOGIC_IN_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&help_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            define_method_from_stringified_source("STARTUP-LOGIC-IN", NULL, "(DEFUN STARTUP-LOGIC-IN ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *AVAILABLE-POWERLOOM-FEATURES* (LIST OF KEYWORD) (LIST :GOAL-TRACE :CLOSED-WORLD) :DOCUMENTATION \"List of PowerLoom environment features.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CURRENT-POWERLOOM-FEATURES* (LIST OF KEYWORD) (LIST) :DOCUMENTATION \"List of currently enabled PowerLoom environment features.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEFAULT-POWERLOOM-FEATURES* (LIST OF KEYWORD) (LIST) :DOCUMENTATION \"List of PowerLoom environment features enabled upon call to\n'reset-features'.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *LOGIC-PROMPT* STRING \"|= \" :DOCUMENTATION \"The prompt used by the PowerLoom listener.\" :PUBLIC? TRUE)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *LOGIC-COMMAND-RESULT-INDENT* STRING \"\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *CAREFUL-LOGIC-COMMAND-LOOP-EXIT*? BOOLEAN (VERBATIM :COMMON-LISP FALSE :OTHERWISE TRUE) :DOCUMENTATION \"If TRUE exiting from the logic-command loop (or PowerLoom\nlistener) will be protected by a confirmation dialog.  This is mainly useful\nfor C++ where exiting the listener will also exit the program.\" :PUBLIC? TRUE)");
            { Global_Variable* global = SYM_LOGIC_IN_oCAREFUL_LOGIC_COMMAND_LOOP_EXITop->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Ocareful_logic_command_loop_exitOP));
              global->variable_set_value_code = ((cpp_function_code)(&write_Ocareful_logic_command_loop_exitOP));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *DEMO-LEVEL* INTEGER 0)");
            { Global_Variable* global = SYM_LOGIC_IN_oDEMO_LEVELo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Odemo_levelO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Odemo_levelO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEMO-FILE-DIRECTORY* STRING (VERBATIM :COMMON-LISP \"\\\"PL:sources;logic;demos;\\\"\" :CPP \"DEMO_FILE_PATHNAME\"))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEMO-FILE-SUFFIX* STRING \".ste\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEMO-FILES* (CONS OF (CONS OF STRING-WRAPPER)) (BQUOTE ((\"basics\" \"Basic PowerLoom commands\") (\"classes\" \"Primitive and defined classes\") (\"collections\" \"Reasoning with collections\") (\"append\" \"Prolog-style `append'\") (\"named-rules\" \"Using named rules\") (\"recursion\" \"Reasoning with recursive rules\") (\"negation\" \"Reasoning with negation\") (\"constraints\" \"Constraint propagation\") (\"subsumption\" \"Subsumption\"))) :DOCUMENTATION \"List of example demo files.\nEach entry is a `(<file> <description>)' pair.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *UNFINALIZED-DEFINED-RELATIONS* (LIST OF RELATION) (LIST) :DOCUMENTATION \"List of relations whose definitions and/or associated\naxioms and constraints are not yet processed.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *LOGIC-RELEVANT-STELLA-COMMANDS* (CONS OF SYMBOL) (BQUOTE (CC CLEAR-MODULE DEFCLASS DEFMODULE IN-MODULE)))");
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

