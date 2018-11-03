//  -*- Mode: C++ -*-

// logic-in.cc

/*
 +--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997-2003              |
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
 +--------------------------------------------------------------------------+
*/

#include "logic/logic-system.hh"

namespace logic {
  using namespace stella;

// List of PowerLoom environment features.
List* oAVAILABLE_POWERLOOM_FEATURESo = NULL;

// List of currently enabled PowerLoom environment features.
List* oCURRENT_POWERLOOM_FEATURESo = NULL;

// List of PowerLoom environment features enabled upon call to
// 'reset-features'.
List* oDEFAULT_POWERLOOM_FEATURESo = NULL;

void printFeatures() {
  // Print the currently enabled and available PowerLoom environment features.
  std::cout << "Currently enabled PowerLoom features:" << std::endl << "   " << oCURRENT_POWERLOOM_FEATURESo << std::endl << std::endl << "Available PowerLoom features:" << std::endl << "   " << oAVAILABLE_POWERLOOM_FEATURESo << std::endl;
}

List* listFeatures() {
  // Return a list containing two lists, a list of currently enabled PowerLoom
  // features, and a list of all available PowerLoom features.
  return (list(2, oCURRENT_POWERLOOM_FEATURESo, oAVAILABLE_POWERLOOM_FEATURESo));
}

void setPowerloomFeature(Keyword* feature) {
  // Enable the PowerLoom environment feature `feature'.
  if (!(oCURRENT_POWERLOOM_FEATURESo->memberP(feature))) {
    if (feature == KWD_LOGIC_IN_TRACE_SUBGOALS) {
      addTrace(consList(1, KWD_LOGIC_IN_GOAL_TREE));
    }
    else if (feature == KWD_LOGIC_IN_TRACE_SOLUTIONS) {
      addTrace(consList(1, KWD_LOGIC_IN_TRACE_SOLUTIONS));
    }
    else if (feature == KWD_LOGIC_IN_TRACE_CLASSIFIER) {
      addTrace(consList(1, KWD_LOGIC_IN_CLASSIFIER_INFERENCES));
    }
    else if (feature == KWD_LOGIC_IN_CLOSED_WORLD) {
    }
    else if (feature == KWD_LOGIC_IN_ITERATIVE_DEEPENING) {
      oITERATIVE_DEEPENING_MODEpo = TRUE;
    }
    else if (feature == KWD_LOGIC_IN_JUSTIFICATIONS) {
      oRECORD_JUSTIFICATIONSpo.set(TRUE);
    }
    else if (feature == KWD_LOGIC_IN_JUST_IN_TIME_INFERENCE) {
      oJUST_IN_TIME_FORWARD_INFERENCEpo = TRUE;
    }
    else if (feature == KWD_LOGIC_IN_EMIT_THINKING_DOTS) {
      oEMIT_THINKING_DOTSpo = TRUE;
    }
    else {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "No such PowerLoom environment feature: " << "`" << feature << "'" << std::endl;
      printFeatures();
      return;
    }
    oCURRENT_POWERLOOM_FEATURESo->insert(feature);
  }
}

List* setFeature(Cons* features) {
  // Enable the PowerLoom environment feature(s) named by `features'.
  // Return the list of enabled features.  Calling `set-feature' without any
  // arguments can be used to display the currently enabled features.
  // The following features are supported:
  // 
  // `just-in-time-inference': Enables interleaving of forward chaining inference
  // within backward chaining queries.
  // 
  // `iterative-deepening': Tells the query processor to use iterative deepening
  // instead of a depth-first search to find answers.  This is less efficient
  // but necessary for some kinds of highly recursive queries.
  // 
  // `trace-subgoals': Enables the generation of subgoaling trace information during
  // backchaining inference.
  // 
  // `trace-solutions': Prints newly found solutions during retrieval right when they
  // are generated as opposed to when the query terminates.
  // 
  // `trace-classifier': Tells the classifier to describe the inferences it draws.
  // 
  // `justifications': Enables the generation of justifications during inference,
  // which is a prerequiste for the generation of explanations with `(why)'.
  // 
  // `emit-thinking-dots': Tells PowerLoom to annotate its inference progress by
  // outputting characters indicating the completion of individual reasoning steps.
  // 
  // By default, the features `emit-thinking-dots' and `just-in-time-inference'
  // are enabled, and the others are disabled.
  // 
  try {
    { Object* featurename = NULL;
      Cons* iter000 = features;

      while (!(iter000 == NIL)) {
        featurename = iter000->value;
        iter000 = iter000->rest;
        setPowerloomFeature(stringKeywordify(coerceToString(featurename)));
      }
    }
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
  }
  return (oCURRENT_POWERLOOM_FEATURESo);
}

List* setFeatureEvaluatorWrapper(Cons* arguments) {
  return (setFeature(arguments));
}

void unsetPowerloomFeature(Keyword* feature) {
  // Disable the PowerLoom environment feature `feature'.
  if (oCURRENT_POWERLOOM_FEATURESo->memberP(feature)) {
    if (feature == KWD_LOGIC_IN_TRACE_SUBGOALS) {
      dropTrace(consList(1, KWD_LOGIC_IN_GOAL_TREE));
    }
    else if (feature == KWD_LOGIC_IN_TRACE_SOLUTIONS) {
      dropTrace(consList(1, KWD_LOGIC_IN_TRACE_SOLUTIONS));
    }
    else if (feature == KWD_LOGIC_IN_TRACE_CLASSIFIER) {
      dropTrace(consList(1, KWD_LOGIC_IN_CLASSIFIER_INFERENCES));
    }
    else if (feature == KWD_LOGIC_IN_CLOSED_WORLD) {
    }
    else if (feature == KWD_LOGIC_IN_ITERATIVE_DEEPENING) {
      oITERATIVE_DEEPENING_MODEpo = FALSE;
    }
    else if (feature == KWD_LOGIC_IN_JUSTIFICATIONS) {
      oRECORD_JUSTIFICATIONSpo.set(FALSE);
    }
    else if (feature == KWD_LOGIC_IN_JUST_IN_TIME_INFERENCE) {
      oJUST_IN_TIME_FORWARD_INFERENCEpo = FALSE;
    }
    else if (feature == KWD_LOGIC_IN_EMIT_THINKING_DOTS) {
      oEMIT_THINKING_DOTSpo = FALSE;
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << feature << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
  else {
    if (!oAVAILABLE_POWERLOOM_FEATURESo->memberP(feature)) {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "No such PowerLoom environment feature: " << "`" << feature << "'" << std::endl;
      printFeatures();
    }
  }
  oCURRENT_POWERLOOM_FEATURESo->remove(feature);
}

List* unsetFeature(Cons* features) {
  // Disable the PowerLoom environment feature(s) named by `features'.
  // Return the list of enabled features.  Calling `unset-feature' without any
  // arguments can be used to display the currently enabled features.
  // See `set-feature' for a description of supported features.
  try {
    { Object* featurename = NULL;
      Cons* iter000 = features;

      while (!(iter000 == NIL)) {
        featurename = iter000->value;
        iter000 = iter000->rest;
        unsetPowerloomFeature(stringKeywordify(coerceToString(featurename)));
      }
    }
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
  }
  return (oCURRENT_POWERLOOM_FEATURESo);
}

List* unsetFeatureEvaluatorWrapper(Cons* arguments) {
  return (unsetFeature(arguments));
}

List* resetFeatures() {
  // Reset the PowerLoom environment features to their default settings.
  { Keyword* f = NULL;
    Cons* iter000 = oCURRENT_POWERLOOM_FEATURESo->copy()->theConsList;

    while (!(iter000 == NIL)) {
      f = ((Keyword*)(iter000->value));
      iter000 = iter000->rest;
      if (!oDEFAULT_POWERLOOM_FEATURESo->memberP(f)) {
        unsetPowerloomFeature(f);
      }
    }
  }
  { Keyword* f = NULL;
    Cons* iter001 = oDEFAULT_POWERLOOM_FEATURESo->theConsList;

    while (!(iter001 == NIL)) {
      f = ((Keyword*)(iter001->value));
      iter001 = iter001->rest;
      if (!oCURRENT_POWERLOOM_FEATURESo->memberP(f)) {
        setPowerloomFeature(f);
      }
    }
  }
  return (oCURRENT_POWERLOOM_FEATURESo);
}

boolean enabledPowerloomFeatureP(Keyword* feature) {
  // Return true if the STELLA `feature' is currently enabled.
  return (oCURRENT_POWERLOOM_FEATURESo->membP(feature));
}

boolean disabledPowerloomFeatureP(Keyword* feature) {
  // Return true if the STELLA `feature' is currently disabled.
  return (!oCURRENT_POWERLOOM_FEATURESo->membP(feature));
}

Object* coerceOptionValue(Object* value, Surrogate* type) {
  if (type == SGT_LOGIC_IN_STELLA_INTEGER) {
    { Surrogate* testValue000 = safePrimaryType(value);

      if (subtypeOfIntegerP(testValue000)) {
        { Object* value000 = value;
          IntegerWrapper* value = ((IntegerWrapper*)(value000));

          return (value);
        }
      }
      else if (subtypeOfFloatP(testValue000)) {
        { Object* value001 = value;
          FloatWrapper* value = ((FloatWrapper*)(value001));

          return (wrapInteger(stella::floor(value->wrapperValue)));
        }
      }
      else {
      }
    }
  }
  else if (type == SGT_LOGIC_IN_STELLA_FLOAT) {
    { Surrogate* testValue001 = safePrimaryType(value);

      if (subtypeOfIntegerP(testValue001)) {
        { Object* value002 = value;
          IntegerWrapper* value = ((IntegerWrapper*)(value002));

          return (wrapFloat(value->wrapperValue * 1.0));
        }
      }
      else if (subtypeOfFloatP(testValue001)) {
        { Object* value003 = value;
          FloatWrapper* value = ((FloatWrapper*)(value003));

          return (wrapFloat(value->wrapperValue * 1.0));
        }
      }
      else {
      }
    }
  }
  else if (type == SGT_LOGIC_IN_STELLA_NUMBER) {
    { Surrogate* testValue002 = safePrimaryType(value);

      if (subtypeOfIntegerP(testValue002)) {
        { Object* value004 = value;
          IntegerWrapper* value = ((IntegerWrapper*)(value004));

          return (value);
        }
      }
      else if (subtypeOfFloatP(testValue002)) {
        { Object* value005 = value;
          FloatWrapper* value = ((FloatWrapper*)(value005));

          return (value);
        }
      }
      else {
      }
    }
  }
  else if (type == SGT_LOGIC_IN_STELLA_KEYWORD) {
    { Surrogate* testValue003 = safePrimaryType(value);

      if (subtypeOfP(testValue003, SGT_LOGIC_IN_STELLA_GENERALIZED_SYMBOL)) {
        { Object* value006 = value;
          GeneralizedSymbol* value = ((GeneralizedSymbol*)(value006));

          return (value->keywordify());
        }
      }
      else if (subtypeOfStringP(testValue003)) {
        { Object* value007 = value;
          StringWrapper* value = ((StringWrapper*)(value007));

          return (value->keywordify());
        }
      }
      else {
      }
    }
  }
  else if (type == SGT_LOGIC_IN_STELLA_SYMBOL) {
    { Surrogate* testValue004 = safePrimaryType(value);

      if (subtypeOfKeywordP(testValue004)) {
        { Object* value008 = value;
          Keyword* value = ((Keyword*)(value008));

          return (internSymbol(value->symbolName));
        }
      }
      else if (subtypeOfSurrogateP(testValue004)) {
        { Object* value009 = value;
          Surrogate* value = ((Surrogate*)(value009));

          return (internDerivedSymbol(value, value->symbolName));
        }
      }
      else if (subtypeOfSymbolP(testValue004)) {
        { Object* value010 = value;
          Symbol* value = ((Symbol*)(value010));

          return (value);
        }
      }
      else {
      }
    }
  }
  else if (type == SGT_LOGIC_IN_STELLA_BOOLEAN) {
    return (coerceToBoolean(value));
  }
  else if (type == SGT_LOGIC_IN_STELLA_MODULE) {
    return (coerceToModule(value, FALSE));
  }
  else if ((type == SGT_LOGIC_IN_LOGIC_DESCRIPTION) ||
      (type == SGT_LOGIC_IN_LOGIC_NAMED_DESCRIPTION)) {
    return (coerceToDescription(value, NULL));
  }
  else {
    if (!((boolean)(type))) {
      return (value);
    }
    else if (isaP(value, type)) {
      return (value);
    }
    else if (isaP(value, type->typeToWrappedType())) {
      return (value);
    }
  }
  return (NULL);
}

PropertyList* parseLogicCommandOptions(Object* options, Cons* LEGALOPTIONSATYPES, boolean coercionerrorP) {
  { PropertyList* self000 = newPropertyList();

    self000->thePlist = LEGALOPTIONSATYPES;
    { PropertyList* legaloptions = self000;
      PropertyList* parsedoptions = NULL;
      Surrogate* type = NULL;
      Object* corecedvalue = NULL;

      { Surrogate* testValue000 = safePrimaryType(options);

        if (testValue000 == SGT_LOGIC_IN_STELLA_CONS) {
          { Object* options000 = options;
            Cons* options = ((Cons*)(options000));

            if (((options->length()) % 2)) {
              { OutputStringStream* stream000 = newOutputStringStream();

                { 
                  BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                  *(stream000->nativeStream) << "PARSING ERROR: " << "Odd-length command options list: " << "`" << options << "'" << "." << std::endl;
                  helpSignalPropositionError(stream000, KWD_LOGIC_IN_ERROR);
                }
                throw *newParsingError(stream000->theStringReader());
              }
            }
            { PropertyList* self003 = newPropertyList();

              self003->thePlist = options;
              parsedoptions = self003;
            }
          }
        }
        else if (subtypeOfP(testValue000, SGT_LOGIC_IN_STELLA_PROPERTY_LIST)) {
          { Object* options001 = options;
            PropertyList* options = ((PropertyList*)(options001));

            parsedoptions = options;
          }
        }
        else {
          { OutputStringStream* stream001 = newOutputStringStream();

            { 
              BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
              *(stream001->nativeStream) << "PARSING ERROR: " << "Illegal command options specification: " << "`" << options << "'" << "." << std::endl;
              helpSignalPropositionError(stream001, KWD_LOGIC_IN_ERROR);
            }
            throw *newParsingError(stream001->theStringReader());
          }
        }
      }
      if (((boolean)(legaloptions))) {
        { Object* key = NULL;
          Object* value = NULL;
          Cons* iter000 = parsedoptions->thePlist;

          while (!(iter000 == NIL)) {
            key = iter000->value;
            value = iter000->rest->value;
            iter000 = iter000->rest->rest;
            type = ((Surrogate*)(legaloptions->lookup(key)));
            if (!((boolean)(type))) {
              { OutputStringStream* stream002 = newOutputStringStream();

                { 
                  BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                  *(stream002->nativeStream) << "PARSING ERROR: " << "Illegal option: " << "`" << key << "'" << "." << std::endl;
                  helpSignalPropositionError(stream002, KWD_LOGIC_IN_ERROR);
                }
                throw *newParsingError(stream002->theStringReader());
              }
            }
            if (!(type == SGT_LOGIC_IN_LOGIC_IDENTITY)) {
              corecedvalue = coerceOptionValue(value, type);
              if (coercionerrorP &&
                  (!((boolean)(corecedvalue)))) {
                { OutputStringStream* stream003 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                    *(stream003->nativeStream) << "PARSING ERROR: " << "Can't corerce " << "`" << value << "'" << " to type " << "`" << type << "'" << "." << std::endl;
                    helpSignalPropositionError(stream003, KWD_LOGIC_IN_ERROR);
                  }
                  throw *newParsingError(stream003->theStringReader());
                }
              }
              parsedoptions->insertAt(key, corecedvalue);
            }
          }
        }
      }
      return (parsedoptions);
    }
  }
}

// The prompt used by the PowerLoom listener.
char* oLOGIC_PROMPTo = "|= ";

void printLogicPrompt() {
  std::cout << oLOGIC_PROMPTo;
}

char* oLOGIC_COMMAND_RESULT_INDENTo = "";

void printLogicCommandResult(Object* result) {
  { World* temp000 = lookupConstraintPropagationWorld(oCONTEXTo.get());

    { Context* printcontext = (((boolean)(temp000)) ? temp000 : oCONTEXTo.get());

      { 
        BIND_STELLA_SPECIAL(oPRINTMODEo, Keyword*, KWD_LOGIC_IN_REALISTIC);
        BIND_STELLA_SPECIAL(oPRETTYPRINTLOGICALFORMSpo, boolean, TRUE);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, printcontext);
        if (((boolean)(result))) {
          std::cout << oLOGIC_COMMAND_RESULT_INDENTo << result << std::endl;
        }
      }
    }
  }
}

// If TRUE exiting from the logic-command loop (or PowerLoom
// listener) will be protected by a confirmation dialog.  This is mainly useful
// for C++ where exiting the listener will also exit the program.
DEFINE_STELLA_SPECIAL(oCAREFUL_LOGIC_COMMAND_LOOP_EXITop, boolean , TRUE);

boolean logicCommandLoopExitP(Object* command, boolean& _Return1) {
  { boolean exitP = FALSE;

    { Surrogate* testValue000 = safePrimaryType(command);

      if (subtypeOfKeywordP(testValue000)) {
        { Object* command000 = command;
          Keyword* command = ((Keyword*)(command000));

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
      else if (subtypeOfSymbolP(testValue000)) {
        { Object* command001 = command;
          Symbol* command = ((Symbol*)(command001));

          if ((command == SYM_LOGIC_IN_LOGIC_BYE) ||
              ((command == SYM_LOGIC_IN_LOGIC_EXIT) ||
               ((command == SYM_LOGIC_IN_LOGIC_HALT) ||
                ((command == SYM_LOGIC_IN_LOGIC_QUIT) ||
                 (command == SYM_LOGIC_IN_LOGIC_STOP))))) {
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
        oCAREFUL_LOGIC_COMMAND_LOOP_EXITop.get()) {
      exitP = yesOrNoP("Really exit? (yes or no) ");
      if (exitP) {
        std::cout << std::endl;
      }
      _Return1 = TRUE;
      return (exitP);
    }
    _Return1 = exitP;
    return (exitP);
  }
}

void logicCommandLoop() {
  { boolean dummy1;

    { Object* command = NULL;
      Object* result = NULL;
      boolean exitP = FALSE;
      boolean exitcommandP = FALSE;

      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, oMODULEo.get());
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
        stringChangeModule("PL-USER");
        for (;;) {
          try {
            std::cout << std::endl;
            printLogicPrompt();
            command = readSExpression(STANDARD_INPUT, dummy1);
            std::cout << std::endl;
            exitP = logicCommandLoopExitP(command, exitcommandP);
            if (exitP) {
              break;
            }
            if (exitcommandP) {
              continue;
            }
            result = evaluateLogicCommand(command, FALSE);
            printLogicCommandResult(result);
          }
          catch (StellaException& _e) {
            StellaException* e = &_e;

            *(STANDARD_ERROR->nativeStream) << ">> Error: " << exceptionMessage(e);
          }
        }
      }
    }
  }
}

Object* evaluateLogicCommand(Object* command, boolean finalizeP) {
  { boolean dummy1;

    { 
      BIND_STELLA_SPECIAL(oTRANSLATIONERRORSo, int, 0);
      BIND_STELLA_SPECIAL(oTRANSLATIONWARNINGSo, int, 0);
      BIND_STELLA_SPECIAL(oIGNORETRANSLATIONERRORSpo, boolean, FALSE);
      BIND_STELLA_SPECIAL(oTRANSLATIONUNITSo, List*, NULL);
      BIND_STELLA_SPECIAL(oTRANSLATIONPHASEo, Keyword*, KWD_LOGIC_IN_DEFINE);
      BIND_STELLA_SPECIAL(oEVALUATIONTREEo, Object*, NULL);
      { Object* operatoR = NULL;
        Object* result = NULL;

        { Surrogate* testValue000 = safePrimaryType(command);

          if (testValue000 == SGT_LOGIC_IN_STELLA_CONS) {
            { Object* command000 = command;
              Cons* command = ((Cons*)(command000));

              operatoR = command->value;
              if (subtypeOfSymbolP(safePrimaryType(operatoR))) {
                { Object* operator000 = operatoR;
                  Symbol* operatoR = ((Symbol*)(operator000));

                  if (operatoR == SYM_LOGIC_IN_STELLA_IN_MODULE) {
                    handleInModuleTree(command, FALSE, dummy1);
                  }
                  else {
                    if (declarationTreeP(command)) {
                      oTRANSLATIONUNITSo.set(list(0));
                      walkTopLevelTree(command, FALSE);
                      switch (oTRANSLATIONUNITSo.get()->reverse()->length()) {
                        case 0: 
                          { OutputStringStream* stream000 = newOutputStringStream();

                            *(stream000->nativeStream) << "Translation failed: " << "`" << command << "'";
                            throw *newEvaluationException(stream000->theStringReader());
                          }
                        break;
                        case 1: 
                          result = ((TranslationUnit*)(oTRANSLATIONUNITSo.get()->first()))->theObject;
                        break;
                        default:
                          { Cons* results = NIL;

                            { TranslationUnit* unit = NULL;
                              Cons* iter000 = oTRANSLATIONUNITSo.get()->theConsList;
                              Cons* collect000 = NULL;

                              while (!(iter000 == NIL)) {
                                unit = ((TranslationUnit*)(iter000->value));
                                iter000 = iter000->rest;
                                if (!((boolean)(collect000))) {
                                  {
                                    collect000 = cons(unit->theObject, NIL);
                                    if (results == NIL) {
                                      results = collect000;
                                    }
                                    else {
                                      addConsToEndOfConsList(results, collect000);
                                    }
                                  }
                                }
                                else {
                                  {
                                    collect000->rest = cons(unit->theObject, NIL);
                                    collect000 = collect000->rest;
                                  }
                                }
                              }
                            }
                            result = results;
                          }
                        break;
                      }
                    }
                    else if (stringEqualP(operatoR->symbolName, "IN-PACKAGE")) {
                    }
                    else {
                      // Should be synchronized on process lock oPOWERLOOM_LOCKo
                      {
                        result = evaluate(command);
                      }
                    }
                  }
                }
              }
              else {
                // Should be synchronized on process lock oPOWERLOOM_LOCKo
                {
                  result = evaluate(command);
                }
              }
            }
          }
          else if (subtypeOfKeywordP(testValue000)) {
            { Object* command001 = command;
              Keyword* command = ((Keyword*)(command001));

              result = command;
            }
          }
          else if (subtypeOfSurrogateP(testValue000)) {
            { Object* command002 = command;
              Surrogate* command = ((Surrogate*)(command002));

              result = command;
            }
          }
          else {
            // Should be synchronized on process lock oPOWERLOOM_LOCKo
            {
              result = evaluate(command);
            }
          }
        }
        if ((!translationErrorsP()) &&
            finalizeP) {
          oTRANSLATIONPHASEo.set(KWD_LOGIC_IN_FINALIZE);
          finalizeObjects();
        }
        return (result);
      }
    }
  }
}

void load(char* file) {
  // Read logic commands from `file' and evaluate them.
  if (!probeFileP(file)) {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "File " << "`" << file << "'" << " does not exist.";
      throw *newNoSuchFileException(stream000->theStringReader());
    }
  }
  { boolean toplevelinvocationP = oCURRENTFILEo.get() == NULL;
    InputFileStream* inputstream = NULL;

    try {
      { 
        BIND_STELLA_SPECIAL(oCURRENTFILEo, char*, fileBaseName(file));
        inputstream = newInputFileStream(file);
        loadStream(inputstream);
      }
    }
catch (...) {
      if (toplevelinvocationP) {
        sweepTransients();
      }
      if (((boolean)(inputstream))) {
        inputstream->free();
      }
      throw;
    }
    if (toplevelinvocationP) {
      sweepTransients();
    }
    if (((boolean)(inputstream))) {
      inputstream->free();
    }
  }
}

void loadEvaluatorWrapper(Cons* arguments) {
  load(((StringWrapper*)(arguments->value))->wrapperValue);
}

void loadStream(InputStream* stream) {
  // Read logic commands from `stream' and evaluate them.
  { Keyword* currentdialect = oLOGIC_DIALECTo.get();
    boolean skipcommandP = FALSE;
    boolean seeninmoduleP = FALSE;
    Cons* commands = NIL;

    { 
      BIND_STELLA_SPECIAL(oLOGIC_DIALECTo, Keyword*, currentdialect);
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, oMODULEo.get());
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
        { Object* tree = NULL;
          SExpressionIterator* iter000 = sExpressions(stream);

          while (iter000->nextP()) {
            tree = iter000->value;
            if (safePrimaryType(tree) == SGT_LOGIC_IN_STELLA_CONS) {
              { Object* tree000 = tree;
                Cons* tree = ((Cons*)(tree000));

                skipcommandP = handleInModuleTree(tree, seeninmoduleP, seeninmoduleP);
                if (skipcommandP) {
                  continue;
                }
                { Object* operatoR = tree->value;

                  if (subtypeOfSymbolP(safePrimaryType(operatoR))) {
                    { Object* operator000 = operatoR;
                      Symbol* operatoR = ((Symbol*)(operator000));

                      if ((operatoR == SYM_LOGIC_IN_STELLA_DEFMODULE) ||
                          ((operatoR == SYM_LOGIC_IN_STELLA_CLEAR_MODULE) ||
                           ((operatoR == SYM_LOGIC_IN_STELLA_DEFCLASS) ||
                            ((operatoR == SYM_LOGIC_IN_STELLA_DEFSLOT) ||
                             ((operatoR == SYM_LOGIC_IN_STELLA_DEFUN) ||
                              ((operatoR == SYM_LOGIC_IN_STELLA_DEFMETHOD) ||
                               ((operatoR == SYM_LOGIC_IN_LOGIC_DEFCONCEPT) ||
                                ((operatoR == SYM_LOGIC_IN_LOGIC_DEFFUNCTION) ||
                                 ((operatoR == SYM_LOGIC_IN_LOGIC_DEFRELATION) ||
                                  ((operatoR == SYM_LOGIC_IN_LOGIC_DEFOBJECT) ||
                                   (operatoR == SYM_LOGIC_IN_LOGIC_DEFINSTANCE))))))))))) {
                        evaluateLogicCommand(tree, FALSE);
                      }
                      else if (operatoR == SYM_LOGIC_IN_LOGIC_IN_DIALECT) {
                        evaluateLogicCommand(tree, FALSE);
                        commands = cons(tree, commands);
                      }
                      else {
                        if (((boolean)(lookupCommand(operatoR)))) {
                          commands = cons(tree, commands);
                        }
                        else {
                          evaluateLogicCommand(tree, FALSE);
                        }
                      }
                    }
                  }
                  else {
                    evaluateLogicCommand(tree, FALSE);
                  }
                }
              }
            }
            else {
              evaluateLogicCommand(tree, FALSE);
            }
          }
        }
        { 
          BIND_STELLA_SPECIAL(oTRANSLATIONPHASEo, Keyword*, KWD_LOGIC_IN_FINALIZE);
          finalizeObjects();
        }
        { Object* tree = NULL;
          Cons* iter001 = commands->reverse();

          while (!(iter001 == NIL)) {
            tree = iter001->value;
            iter001 = iter001->rest;
            evaluateLogicCommand(tree, TRUE);
          }
        }
      }
    }
  }
}

DEFINE_STELLA_SPECIAL(oDEMO_LEVELo, int , 0);

void printDemoPrompt() {
  std::cout << oLOGIC_PROMPTo;
}

boolean demoSkipToCommand(InputStream* stream) {
  { char ch = NULL_CHARACTER;
    char* comment = NULL;
    boolean eofP = FALSE;
    boolean echoP = FALSE;
    OutputStream* echostream = stream->echoStream;

    for (;;) {
      stream->echoStream = NULL;
      ch = readCharacter(stream, eofP);
      if (eofP) {
        return (TRUE);
      }
      if (echoP) {
        stream->echoStream = echostream;
      }
      if (oCHARACTER_TYPE_TABLEo[(int)(unsigned char) ch] == KWD_LOGIC_IN_WHITE_SPACE) {
        if (echoP) {
          *(echostream->nativeStream) << ch;
        }
      }
      else if (ch == ';') {
        echoP = TRUE;
        stream->echoStream = echostream;
        *(echostream->nativeStream) << ch;
        comment = readLine(stream, eofP);
        comment = comment;
        if (eofP) {
          return (TRUE);
        }
      }
      else {
        stream->echoStream = echostream;
        unreadCharacter(ch, stream);
        break;
      }
    }
    return (FALSE);
  }
}

boolean demoPauseP(boolean pauseP, boolean& _Return1) {
  { boolean dummy1;

    { boolean exitP = FALSE;
      char* input = NULL;

      if (pauseP) {
        std::cout << "------ pause ------";
        input = readLine(STANDARD_INPUT, dummy1);
        std::cout << std::endl;
        if (strlen(input) > 0) {
          switch (oCHARACTER_UPCASE_TABLEo[((int)(unsigned char) (input[0]))]) {
            case 'C': 
              pauseP = FALSE;
            break;
            case 'Q': 
              if (yOrNP("Really exit demo? (y or n) ")) {
                pauseP = FALSE;
                exitP = TRUE;
              }
            break;
            case 'H': 
            case '?': 
              std::cout << "Type `c' to continue without pausing," << std::endl << "     `q' to quit from this demo," << std::endl << "     `?' or `h' to get this message," << std::endl << "     or any other key to continue." << std::endl;
              return (demoPauseP(pauseP, _Return1));
            default:
            break;
          }
        }
      }
      else {
        std::cout << std::endl;
      }
      _Return1 = exitP;
      return (pauseP);
    }
  }
}

void demoFile(char* file, boolean pauseP) {
  { boolean dummy1;

    if (!probeFileP(file)) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "File " << "`" << file << "'" << " does not exist.";
        throw *newNoSuchFileException(stream000->theStringReader());
      }
    }
    { int currentlevel = oDEMO_LEVELo.get();
      Object* command = NULL;
      Object* result = NULL;
      boolean exitP = FALSE;
      InputStream* inputstream = newInputFileStream(file);

      { 
        BIND_STELLA_SPECIAL(oCAREFUL_LOGIC_COMMAND_LOOP_EXITop, boolean, FALSE);
        BIND_STELLA_SPECIAL(oDEMO_LEVELo, int, currentlevel + 1);
        inputstream->echoStream = STANDARD_OUTPUT;
        { 
          BIND_STELLA_SPECIAL(oMODULEo, Module*, oMODULEo.get());
          BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
          if (pauseP) {
            std::cout << "Now reading from `" << file << "'." << std::endl << "Type `?' at the pause prompt for a list of available commands." << std::endl;
          }
          for (;;) {
            try {
              std::cout << std::endl;
              exitP = demoSkipToCommand(inputstream);
              printDemoPrompt();
              if (!(exitP)) {
                command = readSExpression(inputstream, exitP);
              }
              if (exitP ||
                  logicCommandLoopExitP(command, dummy1)) {
                break;
              }
              pauseP = demoPauseP(pauseP, exitP);
              if (exitP) {
                break;
              }
              result = evaluateLogicCommand(command, FALSE);
              printLogicCommandResult(result);
            }
            catch (EvaluationException& _e) {
              EvaluationException* e = &_e;

              *(STANDARD_ERROR->nativeStream) << ">> Error: " << exceptionMessage(e);
            }
          }
          inputstream->free();
          std::cout << std::endl << std::endl << oLOGIC_COMMAND_RESULT_INDENTo << "Finished demo `" << file << "'." << std::endl;
        }
      }
    }
  }
}

Cons* oDEMO_FILE_DEFAULTSo = NULL;

// List of example demo files.
// Each entry is a `(<file> <description>)' pair.
Cons* oDEMO_FILESo = NULL;

char* demoEntryFile(Cons* demoentry) {
  { char* demobasefile = ((StringWrapper*)(demoentry->value))->wrapperValue;
    char* demofile = NULL;

    { StringWrapper* defaulT = NULL;
      Cons* iter000 = oDEMO_FILE_DEFAULTSo;

      while (!(iter000 == NIL)) {
        defaulT = ((StringWrapper*)(iter000->value));
        iter000 = iter000->rest;
        demofile = mergeFileNames(demobasefile, defaulT->wrapperValue);
        if (probeFileP(demofile)) {
          return (demofile);
        }
      }
    }
    return (mergeFileNames(demobasefile, ((StringWrapper*)(oDEMO_FILE_DEFAULTSo->value))->wrapperValue));
  }
}

char* demoEntryDescription(Cons* demoentry) {
  return ((((boolean)(((StringWrapper*)(demoentry->rest->value)))) ? ((StringWrapper*)(demoentry->rest->value))->wrapperValue : ((StringWrapper*)(demoentry->value))->wrapperValue));
}

boolean demoEntryTestSuiteP(Cons* demoentry) {
  return (stringP(((StringWrapper*)(demoentry->rest->rest->value))) &&
      stringEqlP(((StringWrapper*)(demoentry->rest->rest->value))->wrapperValue, "test-suite"));
}

char* selectExampleDemo(int index) {
  { Cons* entry = ((Cons*)(oDEMO_FILESo->nth(index - 1)));

    if (((boolean)(entry))) {
      return (demoEntryFile(entry));
    }
    else {
      return (NULL);
    }
  }
}

char* selectExampleDemoFromMenu() {
  { boolean dummy1;

    std::cout << "Choose a demo:" << std::endl;
    { Cons* entry = NULL;
      int i = NULL_INTEGER;
      Cons* iter000 = oDEMO_FILESo;
      int iter001 = 1;

      while (!(iter000 == NIL)) {
        entry = ((Cons*)(iter000->value));
        iter000 = iter000->rest;
        i = iter001;
        iter001 = iter001 + 1;
        std::cout << "       " << i << ".  ";
        if (i < 10) {
          std::cout << " ";
        }
        std::cout << demoEntryDescription(entry) << std::endl;
      }
    }
    std::cout << "       " << "Q.   Quit demoing" << std::endl;
    std::cout << "Your choice: ";
    { Object* selection = readSExpression(STANDARD_INPUT, dummy1);
      char* file = NULL;

      if (subtypeOfIntegerP(safePrimaryType(selection))) {
        { Object* selection000 = selection;
          IntegerWrapper* selection = ((IntegerWrapper*)(selection000));

          file = selectExampleDemo(selection->wrapperValue);
          if (file != NULL) {
            return (file);
          }
        }
      }
      else {
        if (stringEqlP(stringify(selection), "Q")) {
          return (NULL);
        }
      }
      std::cout << ">> ERROR: Illegal choice `" << selection << "'; enter a number between 1 and " << oDEMO_FILESo->length() << "!" << std::endl << std::endl;
      return (selectExampleDemoFromMenu());
    }
  }
}

void demoExampleDemos() {
  { char* file = NULL;

    for (;;) {
      std::cout << std::endl;
      file = selectExampleDemoFromMenu();
      if (file == NULL) {
        return;
      }
      std::cout << std::endl;
      demoFile(file, TRUE);
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
  { Cons* thefileandpause = fileandpause;
    Object* filespec = thefileandpause->value;
    boolean pauseP = !(thefileandpause->rest->value == SYM_LOGIC_IN_STELLA_FALSE);
    char* file = NULL;

    if (integerP(filespec)) {
      file = selectExampleDemo(((IntegerWrapper*)(filespec))->wrapperValue);
      if (file != NULL) {
        filespec = wrapString(file);
      }
      else {
        filespec = NULL;
      }
    }
    if (!((boolean)(filespec))) {
      demoExampleDemos();
    }
    else {
      if (subtypeOfStringP(safePrimaryType(filespec))) {
        { Object* filespec000 = filespec;
          StringWrapper* filespec = ((StringWrapper*)(filespec000));

          demoFile(filespec->wrapperValue, pauseP);
        }
      }
      else {
        std::cout << ">> ERROR: Illegal file specification: " << filespec;
      }
    }
  }
}

void demoEvaluatorWrapper(Cons* arguments) {
  demo(arguments);
}

void testLogicFile(char* file) {
  { boolean dummy1;

    if (!probeFileP(file)) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "File " << "`" << file << "'" << " does not exist.";
        throw *newNoSuchFileException(stream000->theStringReader());
      }
    }
    { int currentlevel = oDEMO_LEVELo.get();
      Object* command = NULL;
      Object* result = NULL;
      boolean exitP = FALSE;
      InputStream* inputstream = newInputFileStream(file);
      char* filebasename = fileNameWithoutDirectory(file);

      { 
        BIND_STELLA_SPECIAL(oCAREFUL_LOGIC_COMMAND_LOOP_EXITop, boolean, FALSE);
        BIND_STELLA_SPECIAL(oDEMO_LEVELo, int, currentlevel + 1);
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
        BIND_STELLA_SPECIAL(oPRINTPRETTYpo, boolean, FALSE);
        { 
          BIND_STELLA_SPECIAL(oMODULEo, Module*, oMODULEo.get());
          BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
          std::cout << std::endl << "Now testing file `" << filebasename << "':" << std::endl;
          for (;;) {
            try {
              std::cout << std::endl;
              printDemoPrompt();
              if (!(exitP)) {
                command = readSExpression(inputstream, exitP);
              }
              if (exitP ||
                  logicCommandLoopExitP(command, dummy1)) {
                break;
              }
              std::cout << command << std::endl << std::endl;
              result = evaluateLogicCommand(command, FALSE);
              printLogicCommandResult(result);
            }
            catch (EvaluationException& _e) {
              EvaluationException* e = &_e;

              *(STANDARD_ERROR->nativeStream) << ">> Error: " << exceptionMessage(e);
            }
          }
          inputstream->free();
          std::cout << std::endl << std::endl << oLOGIC_COMMAND_RESULT_INDENTo << "Finished testing file `" << filebasename << "'." << std::endl;
        }
      }
    }
  }
}

char* getFormattedDateAndTime() {
  return (calendarDateToString(makeCurrentDateTime(), getLocalTimeZone(), TRUE));
}

void runPowerloomTests() {
  // Run the PowerLoom test suite.  Currently this simply runs all demos and
  // echos commands and their results to standard output.  The output can then
  // be diffed with previously validated runs to find deviations.
  { Module* pluser = getStellaModule("PL-USER", TRUE);
    CalendarDate* startTime = makeCurrentDateTime();
    CalendarDate* finishTime = NULL;

    std::cout << "RUNNING POWERLOOM TEST SUITE" << std::endl << "============================" << std::endl << std::endl;
    std::cout << "STELLA version:    " << oSTELLA_VERSION_STRINGo << std::endl << "PowerLoom version: " << oPOWERLOOM_VERSION_STRINGo << std::endl << "Start time:        " << calendarDateToString(startTime, getLocalTimeZone(), TRUE) << std::endl << std::endl;
    clearContext(pluser);
    { Context* child = NULL;
      Cons* iter000 = pluser->childContexts->copy()->theConsList;

      while (!(iter000 == NIL)) {
        child = ((Context*)(iter000->value));
        iter000 = iter000->rest;
        child->destroyContext();
      }
    }
    oSKOLEM_ID_COUNTERo = 0;
    { Cons* entry = NULL;
      Cons* iter001 = oDEMO_FILESo;

      while (!(iter001 == NIL)) {
        entry = ((Cons*)(iter001->value));
        iter001 = iter001->rest;
        if (demoEntryTestSuiteP(entry)) {
          testLogicFile(demoEntryFile(entry));
        }
      }
    }
    finishTime = makeCurrentDateTime();
    std::cout << std::endl << "FINISHED RUNNING POWERLOOM TEST SUITE" << std::endl << "=====================================" << std::endl << "Finish time:   " << calendarDateToString(finishTime, getLocalTimeZone(), TRUE) << std::endl << "Elapsed time:  " << timeDurationToString(((TimeDuration*)(timeSubtract(finishTime, startTime)))) << std::endl << std::endl;
  }
}

// Points to the source of the relation being parsed.
DEFINE_STELLA_SPECIAL(oTERMSOURCEBEINGPARSEDo, char* , NULL);

// Pofints to a description or its parse tree which
// is the input to the description being constructed.
DEFINE_STELLA_SPECIAL(oDESCRIPTIONUNDERCONSTRUCTIONo, Object* , NULL);

// Points to the parse tree which is the input to the
// proposition being constructed.
DEFINE_STELLA_SPECIAL(oTERMUNDERCONSTRUCTIONo, Object* , NULL);

// Limit on how big an s-expression we will print within
// an error message.
int oEXPRESSION_SIZE_CUTOFFo = 300;

void printFormulaContainingError(Object* self, OutputStream* stream) {
  { OutputStringStream* temp = newOutputStringStream();
    char* expressionstring = NULL;

    *(temp->nativeStream) << self;
    expressionstring = temp->theStringReader();
    if (strlen(expressionstring) > oEXPRESSION_SIZE_CUTOFFo) {
      expressionstring = stringConcatenate(stringSubsequence(expressionstring, 0, oEXPRESSION_SIZE_CUTOFFo), " ......)", 0);
    }
    *(stream->nativeStream) << expressionstring;
  }
}

void helpSignalPropositionError(OutputStream* stream, Keyword* warningorerror) {
  { Object* bestoutputobject = oTERMUNDERCONSTRUCTIONo.get();
    char* typenamE = (((boolean)(bestoutputobject)) ? (char*)"proposition" : (char*)"relation");

    if (!((boolean)(bestoutputobject))) {
      bestoutputobject = oDESCRIPTIONUNDERCONSTRUCTIONo.get();
    }
    if ((!((boolean)(bestoutputobject))) &&
        (oTERMSOURCEBEINGPARSEDo.get() != NULL)) {
      bestoutputobject = wrapString(oTERMSOURCEBEINGPARSEDo.get());
    }
    if (((boolean)(bestoutputobject))) {
      *(stream->nativeStream) << "   ";
      if (warningorerror == KWD_LOGIC_IN_ERROR) {
        *(stream->nativeStream) << "Error";
      }
      else if (warningorerror == KWD_LOGIC_IN_WARNING) {
        *(stream->nativeStream) << "Warning";
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << warningorerror << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
      *(stream->nativeStream) << " occurred while parsing the " << typenamE << ": ";
      { Surrogate* testValue000 = safePrimaryType(bestoutputobject);

        if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_NAMED_DESCRIPTION)) {
          { Object* bestoutputobject000 = bestoutputobject;
            NamedDescription* bestoutputobject = ((NamedDescription*)(bestoutputobject000));

            *(stream->nativeStream) << relationName(bestoutputobject) << std::endl;
            return;
          }
        }
        else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_PROPOSITION)) {
          { Object* bestoutputobject001 = bestoutputobject;
            Proposition* bestoutputobject = ((Proposition*)(bestoutputobject001));

            *(stream->nativeStream) << std::endl << "   ";
            printFormulaContainingError(oTERMUNDERCONSTRUCTIONo.get(), stream);
          }
        }
        else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_DESCRIPTION)) {
          { Object* bestoutputobject002 = bestoutputobject;
            Description* bestoutputobject = ((Description*)(bestoutputobject002));

            *(stream->nativeStream) << std::endl << "   ";
            printFormulaContainingError(oTERMUNDERCONSTRUCTIONo.get(), stream);
          }
        }
        else if (testValue000 == SGT_LOGIC_IN_STELLA_CONS) {
          { Object* bestoutputobject003 = bestoutputobject;
            Cons* bestoutputobject = ((Cons*)(bestoutputobject003));

            *(stream->nativeStream) << std::endl << "   ";
            printFormulaContainingError(oTERMUNDERCONSTRUCTIONo.get(), stream);
          }
        }
        else if (subtypeOfStringP(testValue000)) {
          { Object* bestoutputobject004 = bestoutputobject;
            StringWrapper* bestoutputobject = ((StringWrapper*)(bestoutputobject004));

            *(stream->nativeStream) << std::endl;
            { Object* sexpression = readSExpressionFromString(bestoutputobject->wrapperValue);

              printFormulaContainingError(sexpression, stream);
            }
          }
        }
        else {
        }
      }
      *(stream->nativeStream) << std::endl;
    }
  }
}

Keyword* logicDialect(Object* self) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_LOGIC_IN_STELLA_RELATION)) {
      { Object* self000 = self;
        Relation* self = ((Relation*)(self000));

        return (logicDialect(self->homeModule()));
      }
    }
    else if (subtypeOfP(testValue000, SGT_LOGIC_IN_STELLA_MODULE)) {
      { Object* self001 = self;
        Module* self = ((Module*)(self001));

        { Keyword* dialect = ((Keyword*)(dynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_LOGIC_MODULE_LOGIC_DIALECT, NULL)));

          if (((boolean)(dialect))) {
            return (dialect);
          }
          else {
            return (KWD_LOGIC_IN_KIF);
          }
        }
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

Surrogate* lookupLogicObjectSurrogate(Symbol* name, Module* definitionmodule) {
  definitionmodule = (((boolean)(definitionmodule)) ? definitionmodule : oMODULEo.get());
  if (explicitlyQualifiedLogicObjectNameP(name, definitionmodule)) {
    return (lookupSurrogateInModule(name->symbolName, ((Module*)(name->homeContext)), TRUE));
  }
  else {
    return (lookupSurrogate(name->symbolName));
  }
}

Surrogate* internLogicObjectSurrogate(Symbol* name) {
  if (!oMODULEo.get()->clearableP_reader()) {
    { OutputStringStream* stream000 = newOutputStringStream();

      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
        *(stream000->nativeStream) << "ERROR: " << "Can't define the term " << "`" << name << "'" << " in the unclearable module " << "`" << oMODULEo.get()->moduleFullName << "'" << "." << std::endl;
        helpSignalPropositionError(stream000, KWD_LOGIC_IN_ERROR);
      }
      throw *newPropositionError(stream000->theStringReader());
    }
  }
  { Surrogate* oldsurrogate = lookupLogicObjectSurrogate(name, oMODULEo.get());
    Object* oldvalue = (((boolean)(oldsurrogate)) ? oldsurrogate->surrogateValue : ((Object*)(NULL)));
    Module* oldmodule = (((boolean)(oldvalue)) ? oldvalue->homeModule() : ((Module*)(NULL)));

    if (((boolean)(oldvalue)) &&
        (!(oldmodule == oMODULEo.get()))) {
      if (oWARNIFREDEFINEpo.get()) {
        std::cout << "Defining " << "`" << name << "'" << " would cause a term with the same name" << std::endl << "   of type " << "`" << nameObjectMetaclass(oldvalue) << "'" << " in module " << "`" << oldmodule->moduleFullName << "'" << " to be shadowed." << std::endl;
        std::cout << "CAUTION: Automatic shadowing can be dangerous, because forward " << std::endl << "   references to a shadowed object may be bound to the now shadowed " << std::endl << "   object.  Suggestion: Explicitly shadow the name using" << std::endl << "   DEFMODULE's `:shadow' option." << std::endl;
        if (!(yesOrNoP("Do it anyway? "))) {
          { OutputStringStream* stream001 = newOutputStringStream();

            { 
              BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
              *(stream001->nativeStream) << "ERROR: " << "Couldn't shadow name " << "`" << name << "'" << " in " << "`" << oMODULEo.get()->moduleFullName << "'" << "." << std::endl;
              helpSignalPropositionError(stream001, KWD_LOGIC_IN_ERROR);
            }
            throw *newPropositionError(stream001->theStringReader());
          }
        }
      }
    }
    if (explicitlyQualifiedLogicObjectNameP(name, oMODULEo.get())) {
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, ((Module*)(name->homeContext)));
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
        return (shadowSurrogate(name->symbolName));
      }
    }
    else {
      return (shadowSurrogate(name->symbolName));
    }
  }
}

char* nameObjectMetaclass(Object* self) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_DESCRIPTION)) {
      { Object* self000 = self;
        Description* self = ((Description*)(self000));

        if (classP(self)) {
          return ("concept");
        }
        else if (functionP(self)) {
          return ("function");
        }
        else {
          return ("relation");
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
      { Object* self001 = self;
        LogicObject* self = ((LogicObject*)(self001));

        return ("logic object");
      }
    }
    else {
      return (stringDowncase(self->primaryType()->symbolName));
    }
  }
}

Keyword* logicObjectDefinitionType(Symbol* name, Object* oldobject, Object* newobject) {
  if (!((boolean)(oldobject))) {
    return (KWD_LOGIC_IN_DEFINITION);
  }
  { char* oldkind = nameObjectMetaclass(oldobject);
    char* newkind = nameObjectMetaclass(newobject);

    { Surrogate* testValue000 = safePrimaryType(oldobject);

      if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_NAMED_DESCRIPTION)) {
        { Object* oldobject000 = oldobject;
          NamedDescription* oldobject = ((NamedDescription*)(oldobject000));

          if (!(stringEqlP(oldkind, newkind))) {
            { OutputStringStream* stream000 = newOutputStringStream();

              { 
                BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                *(stream000->nativeStream) << "ERROR: " << "Can't redefine " << "`" << oldkind << "'" << " " << "`" << name << "'" << " with a " << "`" << newkind << "'" << "." << std::endl << "   Explicitly destroy the old object first before you redefine it" << "." << std::endl;
                helpSignalPropositionError(stream000, KWD_LOGIC_IN_ERROR);
              }
              throw *newPropositionError(stream000->theStringReader());
            }
          }
          if (!((oldobject->arity() == ((NamedDescription*)(newobject))->arity()) ||
              ((stringifiedSource(newobject) != NULL) &&
               (stringSearch(stringifiedSource(newobject), "VARIABLE-ARITY", 0) != NULL_INTEGER)))) {
            { OutputStringStream* stream001 = newOutputStringStream();

              { 
                BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                *(stream001->nativeStream) << "ERROR: " << "Can't redefine " << "`" << oldkind << "'" << " " << "`" << name << "'" << " with a different arity." << std::endl << "   Explicitly destroy the old object first before you redefine it" << "." << std::endl;
                helpSignalPropositionError(stream001, KWD_LOGIC_IN_ERROR);
              }
              throw *newPropositionError(stream001->theStringReader());
            }
          }
          return (KWD_LOGIC_IN_REDEFINITION);
        }
      }
      else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
        { Object* oldobject001 = oldobject;
          LogicObject* oldobject = ((LogicObject*)(oldobject001));

          { Surrogate* testValue001 = safePrimaryType(newobject);

            if (subtypeOfP(testValue001, SGT_LOGIC_IN_LOGIC_NAMED_DESCRIPTION)) {
              { Object* newobject000 = newobject;
                NamedDescription* newobject = ((NamedDescription*)(newobject000));

                return (KWD_LOGIC_IN_PROPER_DEFINITION);
              }
            }
            else if (subtypeOfP(testValue001, SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
              { Object* newobject001 = newobject;
                LogicObject* newobject = ((LogicObject*)(newobject001));

                return (KWD_LOGIC_IN_REDEFINITION);
              }
            }
            else {
            }
          }
        }
      }
      else {
        if (oldobject->primaryType() == newobject->primaryType()) {
          return (KWD_LOGIC_IN_REDEFINITION);
        }
      }
    }
    { OutputStringStream* stream002 = newOutputStringStream();

      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
        *(stream002->nativeStream) << "ERROR: " << "Can't redefine " << "`" << oldkind << "'" << " " << "`" << name << "'" << " with a " << "`" << newkind << "'" << "." << std::endl << "   Explicitly destroy the old object first before you redefine it" << "." << std::endl;
        helpSignalPropositionError(stream002, KWD_LOGIC_IN_ERROR);
      }
      throw *newPropositionError(stream002->theStringReader());
    }
  }
}

void bindLogicObjectToSurrogate(Symbol* name, Object* object) {
  { Surrogate* testValue000 = safePrimaryType(object);

    if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
      { Object* object000 = object;
        LogicObject* object = ((LogicObject*)(object000));

      }
    }
    else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_PROPOSITION)) {
      { Object* object001 = object;
        Proposition* object = ((Proposition*)(object001));

      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "INTERNAL ERROR: Can't yet define logic objects of type " << "`" << object->primaryType() << "'";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
  { Surrogate* namesurrogate = internLogicObjectSurrogate(name);
    Surrogate* objectsurrogate = objectSurrogate(object);
    Object* oldobject = namesurrogate->surrogateValue;
    Keyword* definitiontype = NULL;

    if (((boolean)(oldobject)) &&
        oldobject->deletedP()) {
      oldobject = NULL;
      namesurrogate->surrogateValue = NULL;
    }
    if (oWARNIFREDEFINEpo.get() &&
        (((boolean)(objectsurrogate)) &&
         (!(objectsurrogate == namesurrogate)))) {
      std::cout << "The " << "`" << nameObjectMetaclass(object) << "'" << " now named " << "`" << name << "'" << " used to be named " << "`" << internSymbolInModule(objectsurrogate->symbolName, ((Module*)(objectsurrogate->homeContext)), TRUE) << "'" << "." << std::endl << "    Unlinking it from its old name." << std::endl;
      objectsurrogate->surrogateValue = NULL;
    }
    objectSurrogateSetter(object, namesurrogate);
    definitiontype = logicObjectDefinitionType(name, oldobject, object);
    namesurrogate->surrogateValue = object;
    if (((boolean)(oldobject)) &&
        (!eqlP(oldobject, object))) {
      objectSurrogateSetter(oldobject, NULL);
    }
    if (definitiontype == KWD_LOGIC_IN_DEFINITION) {
    }
    else if (definitiontype == KWD_LOGIC_IN_PROPER_DEFINITION) {
      transferPropositionsAndBacklinks(oldobject, object);
      { Surrogate* testValue001 = safePrimaryType(oldobject);

        if (subtypeOfP(testValue001, SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
          { Object* oldobject000 = oldobject;
            LogicObject* oldobject = ((LogicObject*)(oldobject000));

            oldobject->deletedPSetter(TRUE);
          }
        }
        else if (subtypeOfP(testValue001, SGT_LOGIC_IN_LOGIC_PROPOSITION)) {
          { Object* oldobject001 = oldobject;
            Proposition* oldobject = ((Proposition*)(oldobject001));

            oldobject->deletedPSetter(TRUE);
          }
        }
        else {
          { OutputStringStream* stream001 = newOutputStringStream();

            *(stream001->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
            throw *newStellaException(stream001->theStringReader());
          }
        }
      }
    }
    else if (definitiontype == KWD_LOGIC_IN_REDEFINITION) {
      redefineLogicObject(name, oldobject, object);
    }
    else {
      { OutputStringStream* stream002 = newOutputStringStream();

        *(stream002->nativeStream) << "`" << definitiontype << "'" << " is not a valid case option";
        throw *newStellaException(stream002->theStringReader());
      }
    }
  }
}

void redefineLogicObject(Symbol* name, Object* oldobject, Object* newobject) {
  { List* originatedprops = originatedPropositions(oldobject);
    List* exceptprops = originatedprops->copy();

    { Proposition* prop = NULL;
      Cons* iter000 = originatedprops->theConsList;

      while (!(iter000 == NIL)) {
        prop = ((Proposition*)(iter000->value));
        iter000 = iter000->rest;
        { Proposition* satellite = NULL;
          Cons* iter001 = prop->satellitePropositions_reader()->theConsList;

          while (!(iter001 == NIL)) {
            satellite = ((Proposition*)(iter001->value));
            iter001 = iter001->rest;
            exceptprops->insertNew(satellite);
          }
        }
      }
    }
    if (oWARNIFREDEFINEpo.get() &&
        (!stringEqlP(stringifiedSource(oldobject), stringifiedSource(newobject)))) {
      std::cout << "Redefining the " << "`" << nameObjectMetaclass(oldobject) << "'" << " named " << "`" << name << "'" << std::endl;
    }
    transferSynonyms(oldobject, newobject);
    transferPropositionsExceptFor(oldobject, newobject, exceptprops);
    if (isaP(oldobject, SGT_LOGIC_IN_LOGIC_NAMED_DESCRIPTION)) {
      transferDescriptionExtension(((NamedDescription*)(oldobject)), ((NamedDescription*)(newobject)));
    }
    { Proposition* prop = NULL;
      Cons* iter002 = originatedprops->theConsList;

      while (!(iter002 == NIL)) {
        prop = ((Proposition*)(iter002->value));
        iter002 = iter002->rest;
        destroyProposition(prop);
      }
    }
    if (!(eqlP(oldobject, newobject))) {
      destroyObject(oldobject);
    }
  }
}

boolean oHANDLE_EXPLICITLY_QUALIFIED_LOGIC_OBJECTSpo = FALSE;

boolean explicitlyQualifiedLogicObjectNameP(GeneralizedSymbol* objectname, Module* definitionmodule) {
  if (oHANDLE_EXPLICITLY_QUALIFIED_LOGIC_OBJECTSpo) {
    definitionmodule = (((boolean)(definitionmodule)) ? definitionmodule : oMODULEo.get());
    return (!visibleFromP(((Module*)(objectname->homeContext)), definitionmodule));
  }
  return (FALSE);
}

Surrogate* coerceToBoundOrLocalSurrogate(GeneralizedSymbol* self) {
  { Surrogate* surrogate = NULL;

    if (explicitlyQualifiedLogicObjectNameP(self, oMODULEo.get())) {
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, ((Module*)(self->homeContext)));
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
        return (coerceToBoundOrLocalSurrogate(self));
      }
    }
    { Surrogate* testValue000 = safePrimaryType(self);

      if (subtypeOfSurrogateP(testValue000)) {
        { GeneralizedSymbol* self000 = self;
          Surrogate* self = ((Surrogate*)(self000));

          surrogate = self;
        }
      }
      else if (subtypeOfSymbolP(testValue000)) {
        { GeneralizedSymbol* self001 = self;
          Symbol* self = ((Symbol*)(self001));

          surrogate = lookupSurrogateInModule(self->symbolName, ((Module*)(self->homeContext)), FALSE);
          if ((!((boolean)(surrogate))) &&
              (!(((Module*)(self->homeContext)) == oMODULEo.get()))) {
            surrogate = lookupSurrogateInModule(self->symbolName, oMODULEo.get(), FALSE);
          }
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    if (((boolean)(surrogate)) &&
        ((boolean)(surrogate->surrogateValue))) {
      return (surrogate);
    }
    return (shadowSurrogate(self->symbolName));
  }
}

Cons* axioms(Object* self) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
      { Object* self000 = self;
        LogicObject* self = ((LogicObject*)(self000));

        return (((Cons*)(dynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_LOGIC_OBJECT_AXIOMS, NULL))));
      }
    }
    else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_PROPOSITION)) {
      { Object* self001 = self;
        Proposition* self = ((Proposition*)(self001));

        return (((Cons*)(dynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_LOGIC_PROPOSITION_AXIOMS, NULL))));
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

Object* axiomsSetter(Object* self, Cons* axioms) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
      { Object* self000 = self;
        LogicObject* self = ((LogicObject*)(self000));

        setDynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_LOGIC_OBJECT_AXIOMS, axioms, NULL);
      }
    }
    else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_PROPOSITION)) {
      { Object* self001 = self;
        Proposition* self = ((Proposition*)(self001));

        setDynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_LOGIC_PROPOSITION_AXIOMS, axioms, NULL);
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
  return (axioms);
}

void definitionAxiomsHandler(NamedDescription* self, StorageSlot* slot, Object* theaxioms) {
  slot = slot;
  if (stringP(theaxioms)) {
    theaxioms = unstringifyInModule(((StringWrapper*)(theaxioms))->wrapperValue, self->homeModule());
  }
  axiomsSetter(self, combineAxiomLists(axioms(self), theaxioms));
}

void definitionHalfRuleHandler(NamedDescription* self, StorageSlot* slot, Object* body) {
  { Keyword* keyword = ((Keyword*)(dynamicSlotValue(slot->dynamicSlots, SYM_LOGIC_IN_STELLA_SLOT_OPTION_KEYWORD, NULL)));
    Symbol* arrow = internSymbolInModule(keyword->symbolName, getStellaModule("PL-KERNEL-KB", TRUE), FALSE);
    Object* newrule = NULL;

    if (!((boolean)(body))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(stream000->nativeStream) << "ERROR: " << "Missing value for arrow keyword" << "." << std::endl;
          helpSignalPropositionError(stream000, KWD_LOGIC_IN_ERROR);
        }
        throw *newPropositionError(stream000->theStringReader());
      }
    }
    if (stringP(body)) {
      body = unstringifyInModule(((StringWrapper*)(body))->wrapperValue, self->homeModule());
    }
    newrule = completeRuleDefinition(self, body, arrow);
    axiomsSetter(self, combineAxiomLists(axioms(self), newrule));
  }
}

Cons* combineAxiomLists(Cons* oldaxioms, Object* newaxioms) {
  if (!((boolean)(oldaxioms))) {
    oldaxioms = NIL;
  }
  if (!((boolean)(newaxioms))) {
    newaxioms = NIL;
  }
  { Cons* normalizednewaxioms = NIL;

    if (safePrimaryType(newaxioms) == SGT_LOGIC_IN_STELLA_CONS) {
      { Object* newaxioms000 = newaxioms;
        Cons* newaxioms = ((Cons*)(newaxioms000));

        { boolean alwaysP000 = TRUE;

          { Object* elt = NULL;
            Cons* iter000 = newaxioms;

            while (!(iter000 == NIL)) {
              elt = iter000->value;
              iter000 = iter000->rest;
              if (!consP(elt)) {
                alwaysP000 = FALSE;
                break;
              }
            }
          }
          if (alwaysP000) {
            {
              normalizednewaxioms = newaxioms;
            }
          }
          else {
            if (newaxioms->value == SYM_LOGIC_IN_STELLA_AND) {
              {
                normalizednewaxioms = newaxioms->rest;
              }
            }
            else {
              {
                normalizednewaxioms = cons(newaxioms, NIL);
              }
            }
          }
        }
      }
    }
    else {
      normalizednewaxioms = cons(newaxioms, NIL);
    }
    return (oldaxioms->concatenate(normalizednewaxioms, 0));
  }
}

Cons* yieldRelationParametersTree(NamedDescription* self, boolean dropfunctionparameterP, boolean typedP) {
  { Cons* parameterlist = NIL;
    Object* parameter = NULL;

    { Symbol* pname = NULL;
      Surrogate* ptype = NULL;
      Cons* iter000 = self->ioVariableNames->theConsList;
      Cons* iter001 = self->ioVariableTypes->theConsList;

      while ((!(iter000 == NIL)) &&
          (!(iter001 == NIL))) {
        pname = ((Symbol*)(iter000->value));
        iter000 = iter000->rest;
        ptype = ((Surrogate*)(iter001->value));
        iter001 = iter001->rest;
        parameter = pname;
        if (typedP &&
            (!(ptype == SGT_LOGIC_IN_STELLA_THING))) {
          parameter = cons(parameter, cons(surrogateToSymbol(ptype), NIL));
        }
        parameterlist = cons(parameter, parameterlist);
      }
    }
    if (dropfunctionparameterP &&
        functionDescriptionP(self)) {
      parameterlist = parameterlist->rest;
    }
    return (parameterlist->reverse());
  }
}

Object* completeRuleDefinition(NamedDescription* self, Object* body, Symbol* arrow) {
  { Cons* parameters = yieldRelationParametersTree(self, FALSE, FALSE);

    return (listO(3, SYM_LOGIC_IN_STELLA_FORALL, parameters, cons(cons(arrow, listO(3, cons(self->descriptionName(), parameters->concatenate(NIL, 0)), wrapKifWithForall(body, parameters), NIL)), NIL)));
  }
}

void definitionKeywordAxiomsHandler(Object* self, Symbol* selfname, Keyword* key, Object* value) {
  axiomsSetter(self, combineAxiomLists(axioms(self), helpDefineKeywordAxioms(selfname, key, value)));
}

Cons* helpDefineKeywordAxioms(Symbol* selfname, Keyword* key, Object* value) {
  { Cons* axioms = NIL;
    Symbol* relationname = internSymbol(key->symbolName);

    if (symbolP(value) &&
        stringEqualP(((Symbol*)(value))->symbolName, "TRUE")) {
      axioms = cons(relationname, cons(selfname, NIL));
    }
    else if (symbolP(value) &&
        stringEqualP(((Symbol*)(value))->symbolName, "FALSE")) {
      axioms = listO(3, SYM_LOGIC_IN_STELLA_NOT, cons(relationname, cons(selfname, NIL)), NIL);
    }
    else if (consP(value)) {
      { Object* val = NULL;
        Cons* iter000 = ((Cons*)(value));
        Cons* collect000 = NULL;

        while (!(iter000 == NIL)) {
          val = iter000->value;
          iter000 = iter000->rest;
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(cons(relationname, cons(selfname, cons(val, NIL))), NIL);
              if (axioms == NIL) {
                axioms = collect000;
              }
              else {
                addConsToEndOfConsList(axioms, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(cons(relationname, cons(selfname, cons(val, NIL))), NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    else {
      axioms = cons(relationname, cons(selfname, cons(value, NIL)));
    }
    return (axioms);
  }
}

void assertKeywordAxiom(Object* self, Symbol* selfname, Keyword* key, Object* value) {
  { Object* axiom = NULL;
    Cons* iter000 = combineAxiomLists(NIL, helpDefineKeywordAxioms(selfname, key, value));

    while (!(iter000 == NIL)) {
      axiom = iter000->value;
      iter000 = iter000->rest;
      { Cons* props = updateProposition(axiom, KWD_LOGIC_IN_ASSERT_TRUE);

        if (((boolean)(props))) {
          { Proposition* p = NULL;
            Cons* iter001 = props;

            while (!(iter001 == NIL)) {
              p = ((Proposition*)(iter001->value));
              iter001 = iter001->rest;
              { Surrogate* testValue000 = safePrimaryType(self);

                if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
                  { Object* self000 = self;
                    LogicObject* self = ((LogicObject*)(self000));

                    linkOriginatedProposition(self, p);
                  }
                }
                else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_PROPOSITION)) {
                  { Object* self001 = self;
                    Proposition* self = ((Proposition*)(self001));

                    linkOriginatedProposition(self, p);
                  }
                }
                else {
                }
              }
            }
          }
        }
      }
    }
  }
}

// List of objects whose definitions and/or associated
// axioms and constraints are not yet processed.
List* oUNFINALIZED_OBJECTSo = NULL;

DEFINE_STELLA_SPECIAL(oFINALIZEOBJECTSIMMEDIATELYpo, boolean , FALSE);

void registerUnfinalizedObject(Object* object) {
  { Surrogate* testValue000 = safePrimaryType(object);

    if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
      { Object* object000 = object;
        LogicObject* object = ((LogicObject*)(object000));

        oUNFINALIZED_OBJECTSo->push(object);
      }
    }
    else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_PROPOSITION)) {
      { Object* object001 = object;
        Proposition* object = ((Proposition*)(object001));

        oUNFINALIZED_OBJECTSo->push(object);
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "INTERNAL ERROR: can't register objects of type " << "`" << object->primaryType() << "'" << " for finalization";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
  if (oFINALIZEOBJECTSIMMEDIATELYpo.get()) {
    finalizeObjects();
  }
}

void cleanupUnfinalizedObjects() {
  oUNFINALIZED_OBJECTSo->removeDeletedMembers();
}

void linkOriginatedProposition(Object* object, Proposition* proposition) {
  { List* propositions = originatedPropositions(object);

    if (nullListP(propositions)) {
      propositions = newList();
      originatedPropositionsSetter(object, propositions);
    }
    propositions->push(proposition);
  }
}

Cons* helpFinalizeObjectAxioms(Cons* theaxioms) {
  if (!((boolean)(theaxioms))) {
    return (NIL);
  }
  else {
    { Cons* propositions = NIL;
      Object* result = NULL;

      { Object* axiom = NULL;
        Cons* iter000 = theaxioms;

        while (!(iter000 == NIL)) {
          axiom = iter000->value;
          iter000 = iter000->rest;
          result = updateProposition(axiom, KWD_LOGIC_IN_ASSERT_TRUE);
          { Surrogate* testValue000 = safePrimaryType(result);

            if (testValue000 == SGT_LOGIC_IN_STELLA_CONS) {
              { Object* result000 = result;
                Cons* result = ((Cons*)(result000));

                propositions = result->reverse()->concatenate(propositions, 0);
              }
            }
            else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_PROPOSITION)) {
              { Object* result001 = result;
                Proposition* result = ((Proposition*)(result001));

                propositions = cons(result, propositions);
              }
            }
            else {
              return (NIL);
            }
          }
        }
      }
      return (propositions->reverse());
    }
  }
}

void finalizeObjectAxioms(Object* self) {
  { 
    BIND_STELLA_SPECIAL(oTERMSOURCEBEINGPARSEDo, char*, NULL);
    BIND_STELLA_SPECIAL(oLOGIC_DIALECTo, Keyword*, KWD_LOGIC_IN_KIF);
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, self->homeModule());
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
      { Surrogate* testValue000 = safePrimaryType(self);

        if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
          { Object* self000 = self;
            LogicObject* self = ((LogicObject*)(self000));

            oTERMSOURCEBEINGPARSEDo.set(stringifiedSource(self));
            if (!((boolean)(axioms(self)))) {
              return;
            }
            setDynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_STELLA_BADp, TRUE_WRAPPER, NULL);
            { Cons* theaxioms = helpFinalizeObjectAxioms(axioms(self));

              if (theaxioms == NIL) {
                return;
              }
              else {
                { Proposition* p = NULL;
                  Cons* iter000 = theaxioms;

                  while (!(iter000 == NIL)) {
                    p = ((Proposition*)(iter000->value));
                    iter000 = iter000->rest;
                    linkOriginatedProposition(self, p);
                  }
                }
              }
            }
            axiomsSetter(self, NULL);
            setDynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_STELLA_BADp, NULL, NULL);
          }
        }
        else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_PROPOSITION)) {
          { Object* self001 = self;
            Proposition* self = ((Proposition*)(self001));

            oTERMSOURCEBEINGPARSEDo.set(stringifiedSource(self));
            if (!((boolean)(axioms(self)))) {
              return;
            }
            setDynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_STELLA_BADp, TRUE_WRAPPER, NULL);
            { Cons* theaxioms = helpFinalizeObjectAxioms(axioms(self));

              if (theaxioms == NIL) {
                return;
              }
              else {
                { Proposition* p = NULL;
                  Cons* iter001 = theaxioms;

                  while (!(iter001 == NIL)) {
                    p = ((Proposition*)(iter001->value));
                    iter001 = iter001->rest;
                    linkOriginatedProposition(self, p);
                  }
                }
              }
            }
            axiomsSetter(self, NULL);
            setDynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_STELLA_BADp, NULL, NULL);
          }
        }
        else {
          { OutputStringStream* stream000 = newOutputStringStream();

            *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
            throw *newStellaException(stream000->theStringReader());
          }
        }
      }
    }
  }
}

void checkDescriptionArgumentTypes(NamedDescription* self) {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, self->homeModule());
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    { Surrogate* type = NULL;
      Cons* iter000 = self->ioVariableTypes->theConsList;

      while (!(iter000 == NIL)) {
        type = ((Surrogate*)(iter000->value));
        iter000 = iter000->rest;
        { NamedDescription* clasS = getDescription(type);

          if (!((boolean)(clasS))) {
            { OutputStringStream* stream000 = newOutputStringStream();

              { 
                BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                *(stream000->nativeStream) << "ERROR: " << "Undefined class " << "`" << type->symbolName << "'" << " appears as argument type" << std::endl << "   in the definition of relation " << "`" << self->descriptionName() << "'" << "." << std::endl << "." << std::endl;
                helpSignalPropositionError(stream000, KWD_LOGIC_IN_ERROR);
              }
              throw *newPropositionError(stream000->theStringReader());
            }
          }
          if (!classDescriptionP(clasS)) {
            std::cout << "Non-class " << "`" << type->symbolName << "'" << " appears as argument type" << std::endl << "in the definition of relation " << "`" << self->descriptionName() << "'" << "." << std::endl << std::endl;
          }
        }
      }
    }
  }
}

void finalizeObject(Object* self) {
  if (self->deletedP() ||
      finalizedObjectP(self)) {
    return;
  }
  try {
    { Surrogate* testValue000 = safePrimaryType(self);

      if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_NAMED_DESCRIPTION)) {
        { Object* self000 = self;
          NamedDescription* self = ((NamedDescription*)(self000));

          { boolean testValue001 = FALSE;

            if (coerceWrappedBooleanToBoolean(self->badP_reader())) {
              testValue001 = TRUE;
            }
            else {
              { boolean foundP000 = FALSE;

                { Surrogate* type = NULL;
                  Cons* iter000 = self->ioVariableTypes->theConsList;

                  while (!(iter000 == NIL)) {
                    type = ((Surrogate*)(iter000->value));
                    iter000 = iter000->rest;
                    if (type->symbolId == -1) {
                      foundP000 = TRUE;
                      break;
                    }
                  }
                }
                testValue001 = foundP000;
              }
            }
            if (testValue001) {
              return;
            }
          }
          finalizeObjectAxioms(self);
          checkDescriptionArgumentTypes(self);
        }
      }
      else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
        { Object* self001 = self;
          LogicObject* self = ((LogicObject*)(self001));

          if (coerceWrappedBooleanToBoolean(self->badP_reader())) {
            return;
          }
          finalizeObjectAxioms(self);
        }
      }
      else if (subtypeOfP(testValue000, SGT_LOGIC_IN_LOGIC_PROPOSITION)) {
        { Object* self002 = self;
          Proposition* self = ((Proposition*)(self002));

          if (coerceWrappedBooleanToBoolean(self->badP_reader())) {
            return;
          }
          finalizeObjectAxioms(self);
        }
      }
      else {
      }
    }
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
  }
}

boolean finalizedObjectP(Object* self) {
  return (!((boolean)(axioms(self))));
}

boolean objectsAreFinalizedP() {
  return (oUNFINALIZED_OBJECTSo->theConsList == NIL);
}

// Used to prevent finalization from triggering in the
// middle of 'delicate' computations.  Also used to prevent recursive
// invocation of 'finalize-objects'.
DEFINE_STELLA_SPECIAL(oINHIBITOBJECTFINALIZATIONpo, boolean , FALSE);

void finalizeObjects() {
  // Finalize all currently unfinalized objects.
  // The user-level entry point for this is `(process-definitions)'.
  if (oINHIBITOBJECTFINALIZATIONpo.get() ||
      ((oUNFINALIZED_OBJECTSo->theConsList == NIL) ||
       (!worldStateP(oCONTEXTo.get())))) {
    return;
  }
  { 
    BIND_STELLA_SPECIAL(oINHIBITOBJECTFINALIZATIONpo, boolean, TRUE);
    BIND_STELLA_SPECIAL(oTERMSOURCEBEINGPARSEDo, char*, NULL);
    BIND_STELLA_SPECIAL(oDESCRIPTIONUNDERCONSTRUCTIONo, Object*, NULL);
    BIND_STELLA_SPECIAL(oTERMUNDERCONSTRUCTIONo, Object*, NULL);
    finalizeClassesAndSlots();
    { Object* object = NULL;
      Cons* iter000 = oUNFINALIZED_OBJECTSo->reverse()->theConsList;

      while (!(iter000 == NIL)) {
        object = iter000->value;
        iter000 = iter000->rest;
        finalizeObject(object);
      }
    }
    oUNFINALIZED_OBJECTSo->clear();
  }
}

NamedDescription* helpDefineRelationFromParseTree(Cons* tree, char* stringifiedsource) {
  { Symbol* operatoR = ((Symbol*)(tree->value));
    Symbol* name = ((Symbol*)(tree->rest->value));
    Cons* parameters = ((Cons*)(tree->rest->rest->value));
    Cons* options = tree->nthRest(3);
    boolean classP = operatoR == SYM_LOGIC_IN_LOGIC_DEFCONCEPT;
    boolean functionP = operatoR == SYM_LOGIC_IN_LOGIC_DEFFUNCTION;
    NamedDescription* description = NULL;

    description = getIdenticalRelation(name, stringifiedsource);
    if (((boolean)(description))) {
      return (description);
    }
    { List* parameternames = NULL;
      List* parametertypes = NULL;
      boolean variablearityP = FALSE;

      parameternames = parseRelationParametersTree(parameters, parametertypes, variablearityP);
      description = createPrimitiveDescription(parameternames, parametertypes, variablearityP, classP, functionP, oMODULEo.get());
      oDESCRIPTIONUNDERCONSTRUCTIONo.set(description);
      stringifiedSourceSetter(description, stringifiedsource);
      setDynamicSlotValue(description->dynamicSlots, SYM_LOGIC_IN_STELLA_BADp, TRUE_WRAPPER, NULL);
      bindLogicObjectToSurrogate(name, description);
      ensureDescriptionBody(description);
      description->processDefinitionOptions(options);
      setDynamicSlotValue(description->dynamicSlots, SYM_LOGIC_IN_STELLA_BADp, NULL, NULL);
      registerUnfinalizedObject(description);
      return (description);
    }
  }
}

List* parseRelationParametersTree(Cons* parameters, List*& _Return1, boolean& _Return2) {
  if (!((boolean)(parameters))) {
    { OutputStringStream* stream000 = newOutputStringStream();

      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
        *(stream000->nativeStream) << "ERROR: " << "Missing concept or relation parameters" << "." << std::endl;
        helpSignalPropositionError(stream000, KWD_LOGIC_IN_ERROR);
      }
      throw *newPropositionError(stream000->theStringReader());
    }
  }
  { Symbol* name = NULL;
    Object* type = NULL;
    List* parameternames = newList();
    List* parametertypes = newList();
    boolean variablearityP = FALSE;

    { Object* p = NULL;
      Cons* iter000 = parameters;

      while (!(iter000 == NIL)) {
        p = iter000->value;
        iter000 = iter000->rest;
        { Surrogate* testValue000 = safePrimaryType(p);

          if (testValue000 == SGT_LOGIC_IN_STELLA_CONS) {
            { Object* p000 = p;
              Cons* p = ((Cons*)(p000));

              if (!((p->length() == 2) &&
                  (symbolP(p->value) &&
                   symbolP(p->rest->value)))) {
                { OutputStringStream* stream001 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                    *(stream001->nativeStream) << "ERROR: " << "Illegal parameter: " << "`" << p << "'" << "." << std::endl;
                    helpSignalPropositionError(stream001, KWD_LOGIC_IN_ERROR);
                  }
                  throw *newPropositionError(stream001->theStringReader());
                }
              }
              name = ((Symbol*)(p->value));
              if (!questionMarkSymbolP(name)) {
                { OutputStringStream* stream002 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                    *(stream002->nativeStream) << "ERROR: " << "Expected a question mark variable: " << "`" << name << "'" << "." << std::endl;
                    helpSignalPropositionError(stream002, KWD_LOGIC_IN_ERROR);
                  }
                  throw *newPropositionError(stream002->theStringReader());
                }
              }
              type = p->rest->value;
            }
          }
          else if (subtypeOfSymbolP(testValue000)) {
            { Object* p001 = p;
              Symbol* p = ((Symbol*)(p001));

              name = p;
              if (!questionMarkSymbolP(name)) {
                { OutputStringStream* stream003 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                    *(stream003->nativeStream) << "ERROR: " << "Expected a question mark variable: " << "`" << name << "'" << "." << std::endl;
                    helpSignalPropositionError(stream003, KWD_LOGIC_IN_ERROR);
                  }
                  throw *newPropositionError(stream003->theStringReader());
                }
              }
              type = SGT_LOGIC_IN_STELLA_THING;
            }
          }
          else {
            { OutputStringStream* stream004 = newOutputStringStream();

              { 
                BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                *(stream004->nativeStream) << "ERROR: " << "Illegal parameter: " << "`" << p << "'" << "." << std::endl;
                helpSignalPropositionError(stream004, KWD_LOGIC_IN_ERROR);
              }
              throw *newPropositionError(stream004->theStringReader());
            }
          }
        }
        if (sequenceVariableSymbolP(name)) {
          variablearityP = TRUE;
        }
        if (parameternames->memberP(name)) {
          { OutputStringStream* stream005 = newOutputStringStream();

            { 
              BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
              *(stream005->nativeStream) << "ERROR: " << "Duplicate relation parameter name: " << "`" << name << "'" << "." << std::endl;
              helpSignalPropositionError(stream005, KWD_LOGIC_IN_ERROR);
            }
            throw *newPropositionError(stream005->theStringReader());
          }
        }
        parameternames->push(name);
        parametertypes->push(coerceToBoundOrLocalSurrogate(((GeneralizedSymbol*)(type))));
        if (variablearityP) {
          break;
        }
      }
    }
    if (!((boolean)(parametertypes))) {
      { OutputStringStream* stream006 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(stream006->nativeStream) << "ERROR: " << "Missing relation parameter list" << "." << std::endl;
          helpSignalPropositionError(stream006, KWD_LOGIC_IN_ERROR);
        }
        throw *newPropositionError(stream006->theStringReader());
      }
    }
    if (parametertypes->emptyP()) {
      { OutputStringStream* stream007 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(stream007->nativeStream) << "ERROR: " << "Empty relation parameter list" << "." << std::endl;
          helpSignalPropositionError(stream007, KWD_LOGIC_IN_ERROR);
        }
        throw *newPropositionError(stream007->theStringReader());
      }
    }
    { List* _return_temp = parameternames->reverse();

      _Return1 = parametertypes->reverse();
      _Return2 = variablearityP;
      return (_return_temp);
    }
  }
}

NamedDescription* getIdenticalRelation(Symbol* name, char* stringifiedsource) {
  { Surrogate* surrogate = lookupLogicObjectSurrogate(name, oMODULEo.get());
    Object* surrogatevalue = (((boolean)(surrogate)) ? surrogate->surrogateValue : ((Object*)(NULL)));
    NamedDescription* description = NULL;

    if (((boolean)(surrogatevalue)) &&
        isaP(surrogatevalue, SGT_LOGIC_IN_LOGIC_NAMED_DESCRIPTION)) {
      description = ((NamedDescription*)(surrogatevalue));
    }
    if (((boolean)(description))) {
      if ((!coerceWrappedBooleanToBoolean(description->badP_reader())) &&
          stringEqlP(stringifiedSource(description), stringifiedsource)) {
        return (description);
      }
    }
    return (NULL);
  }
}

void NamedDescription::processDefinitionOptions(Object* options) {
  { NamedDescription* self = this;

    { Object* key = NULL;
      Object* value = NULL;
      Cons* iter000 = vetOptions(options, NULL)->thePlist;

      while (!(iter000 == NIL)) {
        key = iter000->value;
        value = iter000->rest->value;
        iter000 = iter000->rest->rest;
        if (!runOptionHandlerP(self, ((Keyword*)(key)), value)) {
          definitionKeywordAxiomsHandler(self, self->descriptionName(), ((Keyword*)(key)), value);
        }
      }
    }
    if (!(classP(self))) {
      { Symbol* name = self->descriptionName();
        Vector* iovariables = self->ioVariables;
        List* iovariabletypes = self->ioVariableTypes;
        Cons* theaxioms = axioms(self);
        Cons* typedarguments = NIL;
        Object* operatoR = NULL;
        Object* firstarg = NULL;
        Cons* argumenttypeaxioms = NIL;

        if (((boolean)(theaxioms)) &&
            iovariabletypes->membP(SGT_LOGIC_IN_STELLA_THING)) {
          { Object* axiom = NULL;
            Cons* iter001 = theaxioms;

            while (!(iter001 == NIL)) {
              axiom = iter001->value;
              iter001 = iter001->rest;
              if (safePrimaryType(axiom) == SGT_LOGIC_IN_STELLA_CONS) {
                { Object* axiom000 = axiom;
                  Cons* axiom = ((Cons*)(axiom000));

                  operatoR = axiom->value;
                  firstarg = axiom->rest->value;
                  if ((operatoR == SYM_LOGIC_IN_PL_KERNEL_KB_NTH_DOMAIN) &&
                      ((firstarg == name) &&
                       integerP(axiom->rest->rest->value))) {
                    typedarguments = cons(((PatternVariable*)((iovariables->theArray)[(((IntegerWrapper*)(axiom->rest->rest->value))->wrapperValue)])), typedarguments);
                  }
                  else if ((operatoR == SYM_LOGIC_IN_PL_KERNEL_KB_DOMAIN) &&
                      (firstarg == name)) {
                    typedarguments = cons(((PatternVariable*)((iovariables->theArray)[0])), typedarguments);
                  }
                  else if ((operatoR == SYM_LOGIC_IN_PL_KERNEL_KB_RANGE) &&
                      (firstarg == name)) {
                    typedarguments = cons(((PatternVariable*)(iovariables->last())), typedarguments);
                  }
                }
              }
              else {
              }
            }
          }
        }
        { Surrogate* type = NULL;
          PatternVariable* var = NULL;
          int i = NULL_INTEGER;
          Cons* iter002 = iovariabletypes->theConsList;
          Vector* vector000 = iovariables;
          int index000 = 0;
          int length000 = vector000->length();
          int iter003 = 0;
          Cons* collect000 = NULL;

          while ((!(iter002 == NIL)) &&
              (index000 < length000)) {
            type = ((Surrogate*)(iter002->value));
            iter002 = iter002->rest;
            var = ((PatternVariable*)((vector000->theArray)[index000]));
            index000 = index000 + 1;
            i = iter003;
            iter003 = iter003 + 1;
            if (((boolean)(type)) &&
                ((!(type == SGT_LOGIC_IN_STELLA_THING)) ||
                 (!typedarguments->membP(var)))) {
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(listO(3, SYM_LOGIC_IN_PL_KERNEL_KB_NTH_DOMAIN, name, cons(wrapInteger(i), cons(internSymbolInModule(type->symbolName, ((Module*)(type->homeContext)), TRUE), NIL))), NIL);
                  if (argumenttypeaxioms == NIL) {
                    argumenttypeaxioms = collect000;
                  }
                  else {
                    addConsToEndOfConsList(argumenttypeaxioms, collect000);
                  }
                }
              }
              else {
                {
                  collect000->rest = cons(listO(3, SYM_LOGIC_IN_PL_KERNEL_KB_NTH_DOMAIN, name, cons(wrapInteger(i), cons(internSymbolInModule(type->symbolName, ((Module*)(type->homeContext)), TRUE), NIL))), NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
        }
        if (!(argumenttypeaxioms == NIL)) {
          axiomsSetter(self, combineAxiomLists(argumenttypeaxioms, theaxioms));
        }
      }
    }
  }
}

NamedDescription* deffunction(Cons* args) {
  // Define (or redefine) a logic function.  The accepted syntax is:
  // 	 
  //  (deffunction <funconst> (<vardecl>+) [:-> <vardecl>]
  //     [:documentation <string>]
  //     [:<= <sentence>] | [:=> <sentence>] |
  //     [:<<= <sentence>] | [:=>> <sentence>] | 
  //     [:<=> <sentence>] | [:<=>> <sentence>] |
  //     [:<<=> <sentence>] | [:<<=>> <sentence>] |
  //     [:axioms {<sentence> | (<sentence>+)}]
  //     [<keyword-option>*])
  // 	
  // Function parameters can be typed or untyped.  If the `:->' option is
  // supplied, it specifies the output variable of the function.  Otherwise,
  // the last variable in the parameter list is used as the output variable.
  // See `defrelation' for a description of `<keyword-option>'s.
  // 
  try {
    return (callDeffunction(args));
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
    return (NULL);
  }
}

NamedDescription* deffunctionEvaluatorWrapper(Cons* arguments) {
  return (deffunction(arguments));
}

NamedDescription* callDeffunction(Cons* arguments) {
  // Callable version of the `deffunction' command (which see).
  // Expects the same arguments as `deffunction' but supplied as a list.
  { Cons* definition = cons(SYM_LOGIC_IN_LOGIC_DEFFUNCTION, arguments->concatenate(NIL, 0));

    { 
      BIND_STELLA_SPECIAL(oTERMSOURCEBEINGPARSEDo, char*, stringify(definition));
      BIND_STELLA_SPECIAL(oDESCRIPTIONUNDERCONSTRUCTIONo, Object*, NULL);
      definition->rest = normalizeDeffunctionArguments(arguments);
      internLogicObjectSurrogate(((Symbol*)(definition->rest->value)));
      return (helpDefineRelationFromParseTree(definition, oTERMSOURCEBEINGPARSEDo.get()));
    }
  }
}

Cons* normalizeDeffunctionArguments(Cons* arguments) {
  { Object* name = arguments->value;
    Object* parameters = arguments->rest->value;
    Cons* options = arguments->rest->rest;

    if (!(symbolP(name))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(stream000->nativeStream) << "ERROR: " << "Illegal function name where symbol expected: " << "`" << name << "'" << "." << std::endl;
          helpSignalPropositionError(stream000, KWD_LOGIC_IN_ERROR);
        }
        throw *newPropositionError(stream000->theStringReader());
      }
    }
    if (safePrimaryType(parameters) == SGT_LOGIC_IN_STELLA_CONS) {
      { Object* parameters000 = parameters;
        Cons* parameters = ((Cons*)(parameters000));

        while (!(options == NIL)) {
          if ((options->value == KWD_LOGIC_IN__g) &&
              ((boolean)(options->rest->value))) {
            parameters = parameters->concatenate(cons(options->rest->value, NIL), 0);
            arguments->secondSetter(parameters);
            options->firstSetter(NULL);
            options->secondSetter(NULL);
            options = arguments->rest->rest->remove(NULL);
            arguments->rest->rest = options;
            break;
          }
          options = options->rest->rest;
        }
        if (parameters == NIL) {
          { OutputStringStream* stream001 = newOutputStringStream();

            { 
              BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
              *(stream001->nativeStream) << "ERROR: " << "Cannot have 0-arity functions" << "." << std::endl;
              helpSignalPropositionError(stream001, KWD_LOGIC_IN_ERROR);
            }
            throw *newPropositionError(stream001->theStringReader());
          }
        }
      }
    }
    else {
      { OutputStringStream* stream002 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(stream002->nativeStream) << "ERROR: " << "Illegal parameter list: " << "`" << parameters << "'" << "." << std::endl;
          helpSignalPropositionError(stream002, KWD_LOGIC_IN_ERROR);
        }
        throw *newPropositionError(stream002->theStringReader());
      }
    }
    return (arguments);
  }
}

NamedDescription* defrelation(Cons* args) {
  // Define (or redefine) a logic relation.  The accepted syntax is:
  // 	 
  //  (defrelation <relconst> (<vardecl>+)
  //     [:documentation <string>]
  //     [:<= <sentence>] | [:=> <sentence>] |
  //     [:<<= <sentence>] | [:=>> <sentence>] | 
  //     [:<=> <sentence>] | [:<=>> <sentence>] |
  //     [:<<=> <sentence>] | [:<<=>> <sentence>] |
  //     [:axioms {<sentence> | (<sentence>+)}]
  //     [<keyword-option>*])
  // 	
  // Relation parameters can be typed or untyped.
  // `<keyword-option>' represents a keyword followed by a value that states an
  // assertion about `<relconst>'.  For example, including the option `:foo bar'
  // states that the proposition `(foo <relconst> bar)' is true.  `:foo (bar fum)'
  // states that both `(foo <relconst> bar)' and `(foo <relconst> fum)' are true.
  // `:foo true' states that `(foo <relconst>)' is true, `:foo false' states that
  // `(not (foo <relconst>))' is true.
  // 
  try {
    return (callDefrelation(args));
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
    return (NULL);
  }
}

NamedDescription* defrelationEvaluatorWrapper(Cons* arguments) {
  return (defrelation(arguments));
}

NamedDescription* callDefrelation(Cons* arguments) {
  // Callable version of the `defrelation' command (which see).
  // Expects the same arguments as `defrelation' but supplied as a list.
  { Cons* definition = cons(SYM_LOGIC_IN_LOGIC_DEFRELATION, arguments->concatenate(NIL, 0));

    { 
      BIND_STELLA_SPECIAL(oTERMSOURCEBEINGPARSEDo, char*, stringify(definition));
      BIND_STELLA_SPECIAL(oDESCRIPTIONUNDERCONSTRUCTIONo, Object*, NULL);
      definition->rest = normalizeDefrelationArguments(arguments);
      internLogicObjectSurrogate(((Symbol*)(definition->rest->value)));
      return (helpDefineRelationFromParseTree(definition, oTERMSOURCEBEINGPARSEDo.get()));
    }
  }
}

Cons* normalizeDefrelationArguments(Cons* arguments) {
  { Object* name = arguments->value;
    Object* parameters = arguments->rest->value;
    Cons* options = arguments->rest->rest;

    if (!(symbolP(name))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(stream000->nativeStream) << "ERROR: " << "Illegal relation name where symbol expected: " << "`" << name << "'" << "." << std::endl;
          helpSignalPropositionError(stream000, KWD_LOGIC_IN_ERROR);
        }
        throw *newPropositionError(stream000->theStringReader());
      }
    }
    if (!(consP(parameters))) {
      { OutputStringStream* stream001 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(stream001->nativeStream) << "ERROR: " << "Illegal parameter list: " << "`" << parameters << "'" << "." << std::endl;
          helpSignalPropositionError(stream001, KWD_LOGIC_IN_ERROR);
        }
        throw *newPropositionError(stream001->theStringReader());
      }
    }
    if (((Cons*)(parameters)) == NIL) {
      { OutputStringStream* stream002 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(stream002->nativeStream) << "ERROR: " << "Cannot have 0-arity relations" << "." << std::endl;
          helpSignalPropositionError(stream002, KWD_LOGIC_IN_ERROR);
        }
        throw *newPropositionError(stream002->theStringReader());
      }
    }
    if (options->memberP(KWD_LOGIC_IN__g)) {
      { OutputStringStream* stream003 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(stream003->nativeStream) << "ERROR: " << "'defrelation' does not allow a return value (':->') clause" << "." << std::endl;
          helpSignalPropositionError(stream003, KWD_LOGIC_IN_ERROR);
        }
        throw *newPropositionError(stream003->theStringReader());
      }
    }
    return (arguments);
  }
}

NamedDescription* defconcept(Cons* args) {
  // Define (or redefine) a concept.  The accepted syntax is:
  // 	 
  //  (defconcept <conceptconst> [(<var> <parent>*)]
  //     [:documentation <string>]
  //     [:<= <sentence>] | [:=> <sentence>] |
  //     [:<<= <sentence>] | [:=>> <sentence>] | 
  //     [:<=> <sentence>] | [:<=>> <sentence>] | [:<<=> <sentence>] |
  //     [:<<=>> <sentence>] |
  //     [:axioms {<sentence> | (<sentence>+)}] |
  //     <keyword-option>*)
  // 	
  // Declaration of a concept variable `<var>' is optional, unless any
  // implication (arrow) options are supplied that need to reference it.  A
  // possibly empty list of concept names following `<var>' is taken as the list
  // of parents of `<conceptconst>'.  Alternatively, parents can be specified
  // via the `:=>' option.  If no parents are specified, the parent of
  // `<conceptconst>' is taken to be THING.  `<keyword-option>' represents a
  // keyword followed by a value that states an assertion about `<conceptconst>'.
  // See `defrelation' for a description of `<keyword-option>'s.
  // 
  try {
    return (callDefconcept(args));
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
    return (NULL);
  }
}

NamedDescription* defconceptEvaluatorWrapper(Cons* arguments) {
  return (defconcept(arguments));
}

NamedDescription* callDefconcept(Cons* arguments) {
  // Callable version of the `defconcept' command (which see).
  // Expects the same arguments as `defconcept' but supplied as a list.
  { Cons* definition = cons(SYM_LOGIC_IN_LOGIC_DEFCONCEPT, arguments->concatenate(NIL, 0));

    { 
      BIND_STELLA_SPECIAL(oTERMSOURCEBEINGPARSEDo, char*, stringify(definition));
      BIND_STELLA_SPECIAL(oDESCRIPTIONUNDERCONSTRUCTIONo, Object*, NULL);
      definition->rest = normalizeDefconceptArguments(arguments);
      internLogicObjectSurrogate(((Symbol*)(definition->rest->value)));
      return (helpDefineRelationFromParseTree(definition, oTERMSOURCEBEINGPARSEDo.get()));
    }
  }
}

Cons* normalizeDefconceptArguments(Cons* arguments) {
  { Object* name = arguments->value;
    Cons* parameters = NULL;
    Symbol* selfvariable = SYM_LOGIC_IN_LOGIC_pSELF;
    Cons* supers = NIL;
    Cons* impliesrules = NIL;

    if (!(symbolP(name))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(stream000->nativeStream) << "ERROR: " << "Illegal concept name where symbol expected: " << "`" << name << "'" << "." << std::endl;
          helpSignalPropositionError(stream000, KWD_LOGIC_IN_ERROR);
        }
        throw *newPropositionError(stream000->theStringReader());
      }
    }
    if (consP(arguments->rest->value)) {
      parameters = ((Cons*)(arguments->rest->value));
    }
    if (((boolean)(parameters))) {
      if (consP(parameters->value)) {
        parameters = ((Cons*)(parameters->value));
      }
      if (parameters == NIL) {
        supers = NIL;
      }
      else if (questionMarkSymbolP(parameters->value)) {
        selfvariable = ((Symbol*)(parameters->value));
        supers = parameters->rest;
      }
      else if (symbolP(parameters->value)) {
        supers = parameters;
      }
      else {
        { OutputStringStream* stream001 = newOutputStringStream();

          { 
            BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
            *(stream001->nativeStream) << "ERROR: " << "Illegal parameter list: " << "`" << arguments->rest->value << "'" << "." << std::endl;
            helpSignalPropositionError(stream001, KWD_LOGIC_IN_ERROR);
          }
          throw *newPropositionError(stream001->theStringReader());
        }
      }
      { Object* super = NULL;
        Cons* iter000 = supers;

        while (!(iter000 == NIL)) {
          super = iter000->value;
          iter000 = iter000->rest;
          impliesrules = cons(KWD_LOGIC_IN_eg, impliesrules);
          impliesrules = cons(cons(super, cons(selfvariable, NIL)), impliesrules);
        }
      }
      impliesrules = impliesrules->reverse();
      arguments->rest = cons(cons(cons(selfvariable, cons(name, NIL)), NIL), impliesrules->concatenate(arguments->rest->rest->concatenate(NIL, 0), 0));
    }
    else if (arguments->rest == NIL) {
      arguments->rest = cons(cons(cons(selfvariable, cons(name, NIL)), NIL), NIL);
    }
    else if (keywordP(arguments->rest->value)) {
      arguments->rest->rest = cons(arguments->rest->value, arguments->rest->rest->concatenate(NIL, 0));
      arguments->secondSetter(cons(cons(selfvariable, cons(name, NIL)), NIL));
    }
    return (arguments);
  }
}

NamedDescription* defineRelationFromParseTree(Cons* tree) {
  { GeneralizedSymbol* testValue000 = ((GeneralizedSymbol*)(tree->value));

    if (testValue000 == SYM_LOGIC_IN_LOGIC_DEFCONCEPT) {
      return (callDefconcept(tree->rest));
    }
    else if (testValue000 == SYM_LOGIC_IN_LOGIC_DEFRELATION) {
      return (callDefrelation(tree->rest));
    }
    else if (testValue000 == SYM_LOGIC_IN_LOGIC_DEFFUNCTION) {
      return (callDeffunction(tree->rest));
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

LogicObject* defobject(Cons* args) {
  // Define (or redefine) a logic instance.  The accepted syntax is:
  // 	 
  //  (defobject <constant>
  //     [:documentation <string>]
  //     [<keyword-option>*])
  // 	
  // `<keyword-option>' represents a keyword followed by a value
  // that states an assertion about <constant>.  See `defrelation' for a
  // description of `<keyword-option>'s.
  // 
  // `defobject' provides a sugar-coated way to assert a collection of facts
  // about a logic constant, but otherwise adds nothing in terms of functionality.
  // 
  try {
    return (callDefobject(args));
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
    return (NULL);
  }
}

LogicObject* defobjectEvaluatorWrapper(Cons* arguments) {
  return (defobject(arguments));
}

LogicObject* definstance(Cons* args) {
  // Define (or redefine) a logic instance (`definstance' is an alias
  // for `defobject' which see).
  try {
    return (callDefobject(args));
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
    return (NULL);
  }
}

LogicObject* definstanceEvaluatorWrapper(Cons* arguments) {
  return (definstance(arguments));
}

LogicObject* callDefobject(Cons* arguments) {
  // Callable version of the `defobject' command (which see).
  // Expects the same arguments as `defobject' but supplied as a list.
  { Cons* definition = cons(SYM_LOGIC_IN_LOGIC_DEFOBJECT, arguments->concatenate(NIL, 0));
    Symbol* name = NULL;
    Cons* options = NIL;
    Object* term = NULL;

    { 
      BIND_STELLA_SPECIAL(oTERMSOURCEBEINGPARSEDo, char*, stringify(definition));
      arguments = normalizeDefobjectArguments(arguments);
      name = ((Symbol*)(arguments->value));
      options = arguments->rest;
      internLogicObjectSurrogate(name);
      term = createLogicInstance(NULL, NULL);
      if (subtypeOfP(safePrimaryType(term), SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT)) {
        { Object* term000 = term;
          LogicObject* term = ((LogicObject*)(term000));

          stringifiedSourceSetter(term, oTERMSOURCEBEINGPARSEDo.get());
          bindLogicObjectToSurrogate(name, term);
          term->processDefinitionOptions(options);
          registerUnfinalizedObject(term);
        }
      }
      else {
        bindLogicObjectToSurrogate(name, term);
        { Object* key = NULL;
          Object* value = NULL;
          Cons* iter000 = vetOptions(options, NULL)->thePlist;

          while (!(iter000 == NIL)) {
            key = iter000->value;
            value = iter000->rest->value;
            iter000 = iter000->rest->rest;
            assertKeywordAxiom(term, name, ((Keyword*)(key)), value);
          }
        }
      }
      return (((LogicObject*)(term)));
    }
  }
}

Cons* normalizeDefobjectArguments(Cons* arguments) {
  { Object* name = arguments->value;
    Cons* options = arguments->rest;

    if (!(symbolP(name))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(stream000->nativeStream) << "ERROR: " << "Illegal object name where symbol expected: " << "`" << name << "'" << "." << std::endl;
          helpSignalPropositionError(stream000, KWD_LOGIC_IN_ERROR);
        }
        throw *newPropositionError(stream000->theStringReader());
      }
    }
    options = options;
    return (arguments);
  }
}

void LogicObject::processDefinitionOptions(Object* options) {
  { LogicObject* self = this;

    { Object* key = NULL;
      Object* value = NULL;
      Cons* iter000 = vetOptions(options, NULL)->thePlist;

      while (!(iter000 == NIL)) {
        key = iter000->value;
        value = iter000->rest->value;
        iter000 = iter000->rest->rest;
        if (!runOptionHandlerP(self, ((Keyword*)(key)), value)) {
          definitionKeywordAxiomsHandler(self, objectName(self), ((Keyword*)(key)), value);
        }
      }
    }
  }
}

Proposition* defproposition(Cons* args) {
  // Define (or redefine) a named proposition.  The accepted syntax is:
  // 	 
  //  (defproposition <name> <sentence>
  //     [:documentation <string>]
  //     [:forward-only? {true | false}]
  //     [:backward-only? {true | false}]
  //     [:dont-optimize? {true | false}]
  //     [:confidence-level {:strict | :default}]
  //     [<keyword-option>*])
  // 	
  // <sentence> can be any sentence that is legal as a top-level assertion.
  // <name> can be a string or symbol and will be bound to the asserted
  // proposition represented by <sentence>.  After this definition every
  // occurrence of <name> will be replaced by the associated proposition.
  // 
  // The options :forward-only? and :backward-only? can be used to tell the
  // inference engine to only use the rule in forward or backward direction
  // (this can also be achieved by using the `<<=' or `=>>' implication
  // arrows).  :dont-optimize?  tells the inference engine to not rearrange
  // the order of clauses in the antecedent of a rule and instead evaluate
  // them in their original order.  :confidence-level can be used to mark a
  // proposition as default only.
  // 
  // `<keyword-option>' represents a keyword followed by a value
  // that states an assertion about the proposition <name>.  See `defrelation'
  // for a description of `<keyword-option>'s.
  // 
  try {
    return (callDefproposition(args));
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
    return (NULL);
  }
}

Proposition* defpropositionEvaluatorWrapper(Cons* arguments) {
  return (defproposition(arguments));
}

Proposition* defrule(Cons* args) {
  // Define (or redefine) a named rule (`defrule' is an alias
  // for `defproposition' which see).
  try {
    return (callDefproposition(args));
  }
  catch (LogicException& _e) {
    LogicException* e = &_e;

    *(STANDARD_ERROR->nativeStream) << exceptionMessage(e);
    return (NULL);
  }
}

Proposition* defruleEvaluatorWrapper(Cons* arguments) {
  return (defrule(arguments));
}

Proposition* callDefproposition(Cons* arguments) {
  // Callable version of the `defproposition' command (which see).
  // Expects the same arguments as `defproposition' but supplied as a list.
  { Cons* definition = cons(SYM_LOGIC_IN_LOGIC_DEFPROPOSITION, arguments->concatenate(NIL, 0));
    Symbol* name = NULL;
    Cons* options = NIL;
    Object* conception = NULL;
    Proposition* proposition = NULL;
    TruthValue* oldtruthvalue = NULL;

    { 
      BIND_STELLA_SPECIAL(oTERMSOURCEBEINGPARSEDo, char*, stringify(definition));
      arguments = normalizeDefpropositionArguments(arguments);
      name = ((Symbol*)(arguments->value));
      internLogicObjectSurrogate(name);
      conception = smartUpdateProposition(arguments->rest->value, KWD_LOGIC_IN_CONCEIVE);
      if (!((boolean)(conception))) {
        return (NULL);
      }
      else if (consP(conception)) {
        proposition = conjoinPropositions(((Cons*)(conception)));
      }
      else {
        proposition = ((Proposition*)(conception));
      }
      options = arguments->rest->rest;
      stringifiedSourceSetter(proposition, oTERMSOURCEBEINGPARSEDo.get());
      setDynamicSlotValue(proposition->dynamicSlots, SYM_LOGIC_IN_STELLA_BADp, TRUE_WRAPPER, NULL);
      bindLogicObjectToSurrogate(name, proposition);
      proposition->processDefinitionOptions(options);
      if (proposition->kind == KWD_LOGIC_IN_FORALL) {
        { Proposition* satellite = NULL;
          Cons* iter000 = proposition->satellitePropositions_reader()->theConsList;

          while (!(iter000 == NIL)) {
            satellite = ((Proposition*)(iter000->value));
            iter000 = iter000->rest;
            destroyProposition(satellite);
          }
        }
        setDynamicSlotValue(proposition->dynamicSlots, SYM_LOGIC_IN_LOGIC_SATELLITE_PROPOSITIONS, NULL, NULL);
      }
      oldtruthvalue = ((TruthValue*)(accessInContext(proposition->truthValue, proposition->homeContext, FALSE)));
      if (lookupAnnotation(proposition, KWD_LOGIC_IN_CONFIDENCE_LEVEL) == KWD_LOGIC_IN_DEFAULT) {
        removeAnnotation(proposition, KWD_LOGIC_IN_CONFIDENCE_LEVEL);
        updatePropositionTruthValue(proposition, KWD_LOGIC_IN_PRESUME_TRUE);
      }
      else {
        updatePropositionTruthValue(proposition, KWD_LOGIC_IN_ASSERT_TRUE);
      }
      if (oldtruthvalue == ((TruthValue*)(accessInContext(proposition->truthValue, proposition->homeContext, FALSE)))) {
        runGoesTrueDemons(proposition);
      }
      setDynamicSlotValue(proposition->dynamicSlots, SYM_LOGIC_IN_STELLA_BADp, NULL, NULL);
      registerUnfinalizedObject(proposition);
      return (proposition);
    }
  }
}

Cons* normalizeDefpropositionArguments(Cons* arguments) {
  { Object* name = arguments->value;
    Object* proposition = arguments->rest->value;
    PropertyList* options = NULL;
    Object* value = NULL;
    Cons* annotations = NIL;

    { Surrogate* testValue000 = safePrimaryType(arguments->value);

      if (subtypeOfSymbolP(testValue000)) {
      }
      else if (subtypeOfStringP(testValue000)) {
        name = internSymbol(((StringWrapper*)(arguments->value))->wrapperValue);
        arguments->firstSetter(name);
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          { 
            BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
            *(stream000->nativeStream) << "ERROR: " << "Illegal proposition name where symbol or string expected: " << "`" << name << "'" << "." << std::endl;
            helpSignalPropositionError(stream000, KWD_LOGIC_IN_ERROR);
          }
          throw *newPropositionError(stream000->theStringReader());
        }
      }
    }
    options = vetOptions(arguments->rest->rest, NULL);
    value = options->lookup(KWD_LOGIC_IN_FORWARDp);
    if (((boolean)(value))) {
      options->removeAt(KWD_LOGIC_IN_FORWARDp);
      options->insertAt(KWD_LOGIC_IN_FORWARD_ONLYp, value);
    }
    value = options->lookup(KWD_LOGIC_IN_BACKWARDp);
    if (((boolean)(value))) {
      options->removeAt(KWD_LOGIC_IN_BACKWARDp);
      options->insertAt(KWD_LOGIC_IN_BACKWARD_ONLYp, value);
    }
    value = options->lookup(KWD_LOGIC_IN_CONFIDENCE_LEVEL);
    if (((boolean)(value))) {
      annotations = annotations->concatenate(listO(3, KWD_LOGIC_IN_CONFIDENCE_LEVEL, value, NIL), 0);
      options->removeAt(KWD_LOGIC_IN_CONFIDENCE_LEVEL);
    }
    value = options->lookup(KWD_LOGIC_IN_WEIGHT);
    if (((boolean)(value))) {
      annotations = annotations->concatenate(listO(3, KWD_LOGIC_IN_WEIGHT, value, NIL), 0);
      options->removeAt(KWD_LOGIC_IN_WEIGHT);
    }
    if (!(annotations == NIL)) {
      arguments->secondSetter(listO(3, SYM_LOGIC_IN_LOGIC_ABOUT, proposition, annotations->concatenate(NIL, 0)));
    }
    arguments->rest->rest = options->thePlist;
    return (arguments);
  }
}

void Proposition::processDefinitionOptions(Object* options) {
  { Proposition* self = this;

    if (((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_LOGIC_FORWARD_ONLYp, FALSE_WRAPPER)))->wrapperValue) {
      setDynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_LOGIC_FORWARD_ONLYp, (FALSE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
    }
    if (((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_LOGIC_BACKWARD_ONLYp, FALSE_WRAPPER)))->wrapperValue) {
      setDynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_LOGIC_BACKWARD_ONLYp, (FALSE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
    }
    if (((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_LOGIC_DONT_OPTIMIZEp, FALSE_WRAPPER)))->wrapperValue) {
      setDynamicSlotValue(self->dynamicSlots, SYM_LOGIC_IN_LOGIC_DONT_OPTIMIZEp, (FALSE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
    }
    axiomsSetter(self, NULL);
    { Object* key = NULL;
      Object* value = NULL;
      Cons* iter000 = vetOptions(options, NULL)->thePlist;

      while (!(iter000 == NIL)) {
        key = iter000->value;
        value = iter000->rest->value;
        iter000 = iter000->rest->rest;
        if (!runOptionHandlerP(self, ((Keyword*)(key)), value)) {
          definitionKeywordAxiomsHandler(self, objectName(self), ((Keyword*)(key)), value);
        }
      }
    }
  }
}

Cons* oLOGIC_RELEVANT_STELLA_COMMANDSo = NULL;

boolean commandL(MethodSlot* command1, MethodSlot* command2) {
  return (stringL(command1->slotName->visibleName(), command2->slotName->visibleName()));
}

List* listLogicCommands() {
  { List* commands = newList();

    { MethodSlot* function = NULL;
      Iterator* iter000 = allFunctions(getStellaModule("/LOGIC", TRUE), TRUE);
      Cons* collect000 = NULL;

      while (iter000->nextP()) {
        function = ((MethodSlot*)(iter000->value));
        if (((BooleanWrapper*)(dynamicSlotValue(function->dynamicSlots, SYM_LOGIC_IN_STELLA_METHOD_COMMANDp, FALSE_WRAPPER)))->wrapperValue &&
            function->publicP()) {
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(function, NIL);
              if (commands->theConsList == NIL) {
                commands->theConsList = collect000;
              }
              else {
                addConsToEndOfConsList(commands->theConsList, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(function, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    { Symbol* stellacommand = NULL;
      Cons* iter001 = oLOGIC_RELEVANT_STELLA_COMMANDSo;
      Cons* collect001 = NULL;

      while (!(iter001 == NIL)) {
        stellacommand = ((Symbol*)(iter001->value));
        iter001 = iter001->rest;
        if (!((boolean)(collect001))) {
          {
            collect001 = cons(lookupCommand(stellacommand), NIL);
            if (commands->theConsList == NIL) {
              commands->theConsList = collect001;
            }
            else {
              addConsToEndOfConsList(commands->theConsList, collect001);
            }
          }
        }
        else {
          {
            collect001->rest = cons(lookupCommand(stellacommand), NIL);
            collect001 = collect001->rest;
          }
        }
      }
    }
    return (commands->sort(((cpp_function_code)(&commandL))));
  }
}

void help(Cons* commands) {
  // Describe specific commands, or print a list of available commands.
  { Cons* thecommands = commands;

    if (thecommands == NIL) {
      std::cout << "The following commands are available " << "(type `(help <command>+)'" << std::endl << "to get command-specific documentation):" << std::endl << std::endl;
      { List* allcommands = listLogicCommands();

        { MethodSlot* command = NULL;
          Cons* iter000 = allcommands->theConsList;

          while (!(iter000 == NIL)) {
            command = ((MethodSlot*)(iter000->value));
            iter000 = iter000->rest;
            if (((StringWrapper*)(dynamicSlotValue(command->dynamicSlots, SYM_LOGIC_IN_STELLA_DOCUMENTATION, NULL_STRING_WRAPPER)))->wrapperValue != NULL) {
              command->printDocumentation(STANDARD_OUTPUT, TRUE);
            }
          }
        }
        std::cout << std::endl << "Undocumented Commands:" << std::endl << std::endl;
        { MethodSlot* command = NULL;
          Cons* iter001 = allcommands->theConsList;

          while (!(iter001 == NIL)) {
            command = ((MethodSlot*)(iter001->value));
            iter001 = iter001->rest;
            if (!(((StringWrapper*)(dynamicSlotValue(command->dynamicSlots, SYM_LOGIC_IN_STELLA_DOCUMENTATION, NULL_STRING_WRAPPER)))->wrapperValue != NULL)) {
              std::cout << command->slotName << ":" << std::endl;
            }
          }
        }
      }
    }
    else {
      { Symbol* commandname = NULL;
        Cons* iter002 = thecommands;

        while (!(iter002 == NIL)) {
          commandname = ((Symbol*)(iter002->value));
          iter002 = iter002->rest;
          { MethodSlot* command = lookupCommand(commandname);

            if (((boolean)(command))) {
              command->printDocumentation(STANDARD_OUTPUT, FALSE);
            }
            else {
              std::cout << "Undefined command: " << "`" << commandname << "'" << std::endl;
            }
          }
        }
      }
    }
  }
}

void helpEvaluatorWrapper(Cons* arguments) {
  help(arguments);
}

void helpStartupLogicIn1() {
  {
    KWD_LOGIC_IN_TRACE_SUBGOALS = ((Keyword*)(internRigidSymbolWrtModule("TRACE-SUBGOALS", NULL, 2)));
    KWD_LOGIC_IN_TRACE_SOLUTIONS = ((Keyword*)(internRigidSymbolWrtModule("TRACE-SOLUTIONS", NULL, 2)));
    KWD_LOGIC_IN_TRACE_CLASSIFIER = ((Keyword*)(internRigidSymbolWrtModule("TRACE-CLASSIFIER", NULL, 2)));
    KWD_LOGIC_IN_ITERATIVE_DEEPENING = ((Keyword*)(internRigidSymbolWrtModule("ITERATIVE-DEEPENING", NULL, 2)));
    KWD_LOGIC_IN_JUSTIFICATIONS = ((Keyword*)(internRigidSymbolWrtModule("JUSTIFICATIONS", NULL, 2)));
    KWD_LOGIC_IN_JUST_IN_TIME_INFERENCE = ((Keyword*)(internRigidSymbolWrtModule("JUST-IN-TIME-INFERENCE", NULL, 2)));
    KWD_LOGIC_IN_EMIT_THINKING_DOTS = ((Keyword*)(internRigidSymbolWrtModule("EMIT-THINKING-DOTS", NULL, 2)));
    KWD_LOGIC_IN_GOAL_TREE = ((Keyword*)(internRigidSymbolWrtModule("GOAL-TREE", NULL, 2)));
    KWD_LOGIC_IN_CLASSIFIER_INFERENCES = ((Keyword*)(internRigidSymbolWrtModule("CLASSIFIER-INFERENCES", NULL, 2)));
    KWD_LOGIC_IN_CLOSED_WORLD = ((Keyword*)(internRigidSymbolWrtModule("CLOSED-WORLD", NULL, 2)));
    SGT_LOGIC_IN_STELLA_INTEGER = ((Surrogate*)(internRigidSymbolWrtModule("INTEGER", getStellaModule("/STELLA", TRUE), 1)));
    SGT_LOGIC_IN_STELLA_FLOAT = ((Surrogate*)(internRigidSymbolWrtModule("FLOAT", getStellaModule("/STELLA", TRUE), 1)));
    SGT_LOGIC_IN_STELLA_NUMBER = ((Surrogate*)(internRigidSymbolWrtModule("NUMBER", getStellaModule("/STELLA", TRUE), 1)));
    SGT_LOGIC_IN_STELLA_KEYWORD = ((Surrogate*)(internRigidSymbolWrtModule("KEYWORD", getStellaModule("/STELLA", TRUE), 1)));
    SGT_LOGIC_IN_STELLA_GENERALIZED_SYMBOL = ((Surrogate*)(internRigidSymbolWrtModule("GENERALIZED-SYMBOL", getStellaModule("/STELLA", TRUE), 1)));
    SGT_LOGIC_IN_STELLA_SYMBOL = ((Surrogate*)(internRigidSymbolWrtModule("SYMBOL", getStellaModule("/STELLA", TRUE), 1)));
    SGT_LOGIC_IN_STELLA_BOOLEAN = ((Surrogate*)(internRigidSymbolWrtModule("BOOLEAN", getStellaModule("/STELLA", TRUE), 1)));
    SGT_LOGIC_IN_STELLA_MODULE = ((Surrogate*)(internRigidSymbolWrtModule("MODULE", getStellaModule("/STELLA", TRUE), 1)));
    SGT_LOGIC_IN_LOGIC_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 1)));
    SGT_LOGIC_IN_LOGIC_NAMED_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("NAMED-DESCRIPTION", NULL, 1)));
    SGT_LOGIC_IN_STELLA_CONS = ((Surrogate*)(internRigidSymbolWrtModule("CONS", getStellaModule("/STELLA", TRUE), 1)));
    KWD_LOGIC_IN_ERROR = ((Keyword*)(internRigidSymbolWrtModule("ERROR", NULL, 2)));
    SGT_LOGIC_IN_STELLA_PROPERTY_LIST = ((Surrogate*)(internRigidSymbolWrtModule("PROPERTY-LIST", getStellaModule("/STELLA", TRUE), 1)));
    SGT_LOGIC_IN_LOGIC_IDENTITY = ((Surrogate*)(internRigidSymbolWrtModule("IDENTITY", NULL, 1)));
    KWD_LOGIC_IN_REALISTIC = ((Keyword*)(internRigidSymbolWrtModule("REALISTIC", NULL, 2)));
    KWD_LOGIC_IN_BYE = ((Keyword*)(internRigidSymbolWrtModule("BYE", NULL, 2)));
    KWD_LOGIC_IN_EXIT = ((Keyword*)(internRigidSymbolWrtModule("EXIT", NULL, 2)));
    KWD_LOGIC_IN_HALT = ((Keyword*)(internRigidSymbolWrtModule("HALT", NULL, 2)));
    KWD_LOGIC_IN_QUIT = ((Keyword*)(internRigidSymbolWrtModule("QUIT", NULL, 2)));
    KWD_LOGIC_IN_STOP = ((Keyword*)(internRigidSymbolWrtModule("STOP", NULL, 2)));
    SYM_LOGIC_IN_LOGIC_BYE = ((Symbol*)(internRigidSymbolWrtModule("BYE", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_EXIT = ((Symbol*)(internRigidSymbolWrtModule("EXIT", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_HALT = ((Symbol*)(internRigidSymbolWrtModule("HALT", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_QUIT = ((Symbol*)(internRigidSymbolWrtModule("QUIT", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_STOP = ((Symbol*)(internRigidSymbolWrtModule("STOP", NULL, 0)));
    KWD_LOGIC_IN_DEFINE = ((Keyword*)(internRigidSymbolWrtModule("DEFINE", NULL, 2)));
    SYM_LOGIC_IN_STELLA_IN_MODULE = ((Symbol*)(internRigidSymbolWrtModule("IN-MODULE", getStellaModule("/STELLA", TRUE), 0)));
    KWD_LOGIC_IN_FINALIZE = ((Keyword*)(internRigidSymbolWrtModule("FINALIZE", NULL, 2)));
    SYM_LOGIC_IN_STELLA_DEFMODULE = ((Symbol*)(internRigidSymbolWrtModule("DEFMODULE", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_STELLA_CLEAR_MODULE = ((Symbol*)(internRigidSymbolWrtModule("CLEAR-MODULE", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_STELLA_DEFCLASS = ((Symbol*)(internRigidSymbolWrtModule("DEFCLASS", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_STELLA_DEFSLOT = ((Symbol*)(internRigidSymbolWrtModule("DEFSLOT", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_STELLA_DEFUN = ((Symbol*)(internRigidSymbolWrtModule("DEFUN", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_STELLA_DEFMETHOD = ((Symbol*)(internRigidSymbolWrtModule("DEFMETHOD", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_LOGIC_DEFCONCEPT = ((Symbol*)(internRigidSymbolWrtModule("DEFCONCEPT", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_DEFFUNCTION = ((Symbol*)(internRigidSymbolWrtModule("DEFFUNCTION", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_DEFRELATION = ((Symbol*)(internRigidSymbolWrtModule("DEFRELATION", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_DEFOBJECT = ((Symbol*)(internRigidSymbolWrtModule("DEFOBJECT", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_DEFINSTANCE = ((Symbol*)(internRigidSymbolWrtModule("DEFINSTANCE", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_IN_DIALECT = ((Symbol*)(internRigidSymbolWrtModule("IN-DIALECT", NULL, 0)));
    KWD_LOGIC_IN_WHITE_SPACE = ((Keyword*)(internRigidSymbolWrtModule("WHITE-SPACE", NULL, 2)));
    SYM_LOGIC_IN_STELLA_FALSE = ((Symbol*)(internRigidSymbolWrtModule("FALSE", getStellaModule("/STELLA", TRUE), 0)));
    KWD_LOGIC_IN_WARNING = ((Keyword*)(internRigidSymbolWrtModule("WARNING", NULL, 2)));
    SGT_LOGIC_IN_LOGIC_PROPOSITION = ((Surrogate*)(internRigidSymbolWrtModule("PROPOSITION", NULL, 1)));
    SGT_LOGIC_IN_STELLA_RELATION = ((Surrogate*)(internRigidSymbolWrtModule("RELATION", getStellaModule("/STELLA", TRUE), 1)));
    SYM_LOGIC_IN_LOGIC_MODULE_LOGIC_DIALECT = ((Symbol*)(internRigidSymbolWrtModule("MODULE-LOGIC-DIALECT", NULL, 0)));
    KWD_LOGIC_IN_KIF = ((Keyword*)(internRigidSymbolWrtModule("KIF", NULL, 2)));
    SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("LOGIC-OBJECT", NULL, 1)));
    KWD_LOGIC_IN_DEFINITION = ((Keyword*)(internRigidSymbolWrtModule("DEFINITION", NULL, 2)));
    KWD_LOGIC_IN_REDEFINITION = ((Keyword*)(internRigidSymbolWrtModule("REDEFINITION", NULL, 2)));
  }
}

void helpStartupLogicIn2() {
  {
    KWD_LOGIC_IN_PROPER_DEFINITION = ((Keyword*)(internRigidSymbolWrtModule("PROPER-DEFINITION", NULL, 2)));
    SYM_LOGIC_IN_LOGIC_OBJECT_AXIOMS = ((Symbol*)(internRigidSymbolWrtModule("OBJECT-AXIOMS", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_PROPOSITION_AXIOMS = ((Symbol*)(internRigidSymbolWrtModule("PROPOSITION-AXIOMS", NULL, 0)));
    SYM_LOGIC_IN_STELLA_SLOT_OPTION_KEYWORD = ((Symbol*)(internRigidSymbolWrtModule("SLOT-OPTION-KEYWORD", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_STELLA_AND = ((Symbol*)(internRigidSymbolWrtModule("AND", getStellaModule("/STELLA", TRUE), 0)));
    SGT_LOGIC_IN_STELLA_THING = ((Surrogate*)(internRigidSymbolWrtModule("THING", getStellaModule("/STELLA", TRUE), 1)));
    SYM_LOGIC_IN_STELLA_FORALL = ((Symbol*)(internRigidSymbolWrtModule("FORALL", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_STELLA_NOT = ((Symbol*)(internRigidSymbolWrtModule("NOT", getStellaModule("/STELLA", TRUE), 0)));
    KWD_LOGIC_IN_ASSERT_TRUE = ((Keyword*)(internRigidSymbolWrtModule("ASSERT-TRUE", NULL, 2)));
    SYM_LOGIC_IN_STELLA_BADp = ((Symbol*)(internRigidSymbolWrtModule("BAD?", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_PL_KERNEL_KB_NTH_DOMAIN = ((Symbol*)(internRigidSymbolWrtModule("NTH-DOMAIN", getStellaModule("/PL-KERNEL-KB", TRUE), 0)));
    SYM_LOGIC_IN_PL_KERNEL_KB_DOMAIN = ((Symbol*)(internRigidSymbolWrtModule("DOMAIN", getStellaModule("/PL-KERNEL-KB", TRUE), 0)));
    SYM_LOGIC_IN_PL_KERNEL_KB_RANGE = ((Symbol*)(internRigidSymbolWrtModule("RANGE", getStellaModule("/PL-KERNEL-KB", TRUE), 0)));
    KWD_LOGIC_IN__g = ((Keyword*)(internRigidSymbolWrtModule("->", NULL, 2)));
    SYM_LOGIC_IN_LOGIC_pSELF = ((Symbol*)(internRigidSymbolWrtModule("?SELF", NULL, 0)));
    KWD_LOGIC_IN_eg = ((Keyword*)(internRigidSymbolWrtModule("=>", NULL, 2)));
    SYM_LOGIC_IN_LOGIC_DEFPROPOSITION = ((Symbol*)(internRigidSymbolWrtModule("DEFPROPOSITION", NULL, 0)));
    KWD_LOGIC_IN_CONCEIVE = ((Keyword*)(internRigidSymbolWrtModule("CONCEIVE", NULL, 2)));
    KWD_LOGIC_IN_FORALL = ((Keyword*)(internRigidSymbolWrtModule("FORALL", NULL, 2)));
    SYM_LOGIC_IN_LOGIC_SATELLITE_PROPOSITIONS = ((Symbol*)(internRigidSymbolWrtModule("SATELLITE-PROPOSITIONS", NULL, 0)));
    KWD_LOGIC_IN_CONFIDENCE_LEVEL = ((Keyword*)(internRigidSymbolWrtModule("CONFIDENCE-LEVEL", NULL, 2)));
    KWD_LOGIC_IN_DEFAULT = ((Keyword*)(internRigidSymbolWrtModule("DEFAULT", NULL, 2)));
    KWD_LOGIC_IN_PRESUME_TRUE = ((Keyword*)(internRigidSymbolWrtModule("PRESUME-TRUE", NULL, 2)));
    KWD_LOGIC_IN_FORWARDp = ((Keyword*)(internRigidSymbolWrtModule("FORWARD?", NULL, 2)));
    KWD_LOGIC_IN_FORWARD_ONLYp = ((Keyword*)(internRigidSymbolWrtModule("FORWARD-ONLY?", NULL, 2)));
    KWD_LOGIC_IN_BACKWARDp = ((Keyword*)(internRigidSymbolWrtModule("BACKWARD?", NULL, 2)));
    KWD_LOGIC_IN_BACKWARD_ONLYp = ((Keyword*)(internRigidSymbolWrtModule("BACKWARD-ONLY?", NULL, 2)));
    KWD_LOGIC_IN_WEIGHT = ((Keyword*)(internRigidSymbolWrtModule("WEIGHT", NULL, 2)));
    SYM_LOGIC_IN_LOGIC_ABOUT = ((Symbol*)(internRigidSymbolWrtModule("ABOUT", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_FORWARD_ONLYp = ((Symbol*)(internRigidSymbolWrtModule("FORWARD-ONLY?", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_BACKWARD_ONLYp = ((Symbol*)(internRigidSymbolWrtModule("BACKWARD-ONLY?", NULL, 0)));
    SYM_LOGIC_IN_LOGIC_DONT_OPTIMIZEp = ((Symbol*)(internRigidSymbolWrtModule("DONT-OPTIMIZE?", NULL, 0)));
    SYM_LOGIC_IN_STELLA_CC = ((Symbol*)(internRigidSymbolWrtModule("CC", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_STELLA_METHOD_COMMANDp = ((Symbol*)(internRigidSymbolWrtModule("METHOD-COMMAND?", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_STELLA_DOCUMENTATION = ((Symbol*)(internRigidSymbolWrtModule("DOCUMENTATION", getStellaModule("/STELLA", TRUE), 0)));
    SYM_LOGIC_IN_LOGIC_STARTUP_LOGIC_IN = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-LOGIC-IN", NULL, 0)));
    SYM_LOGIC_IN_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", TRUE), 0)));
  }
}

void helpStartupLogicIn3() {
  {
    oAVAILABLE_POWERLOOM_FEATURESo = list(7, KWD_LOGIC_IN_TRACE_SUBGOALS, KWD_LOGIC_IN_TRACE_SOLUTIONS, KWD_LOGIC_IN_TRACE_CLASSIFIER, KWD_LOGIC_IN_ITERATIVE_DEEPENING, KWD_LOGIC_IN_JUSTIFICATIONS, KWD_LOGIC_IN_JUST_IN_TIME_INFERENCE, KWD_LOGIC_IN_EMIT_THINKING_DOTS);
    oCURRENT_POWERLOOM_FEATURESo = list(0);
    oDEFAULT_POWERLOOM_FEATURESo = list(2, KWD_LOGIC_IN_JUST_IN_TIME_INFERENCE, KWD_LOGIC_IN_EMIT_THINKING_DOTS);
    resetFeatures();
    oDEMO_FILE_DEFAULTSo = consList(3, wrapString("PL:sources;logic;demos;foo.plm"), wrapString("PL:sources;logic;demos;foo.ploom"), wrapString("PL:sources;logic;demos;foo.ste"));
    oDEMO_FILESo = listO(21, listO(4, wrapString("basics"), wrapString("Basic PowerLoom commands"), wrapString("test-suite"), NIL), listO(4, wrapString("classes"), wrapString("Primitive and defined classes"), wrapString("test-suite"), NIL), listO(4, wrapString("collections"), wrapString("Reasoning with collections"), wrapString("test-suite"), NIL), listO(4, wrapString("append"), wrapString("Prolog-style `append'"), wrapString("test-suite"), NIL), listO(4, wrapString("inequalities"), wrapString("Reasoning with inequalities"), wrapString("test-suite"), NIL), listO(4, wrapString("recursion"), wrapString("Reasoning with recursive rules"), wrapString("test-suite"), NIL), listO(4, wrapString("negation"), wrapString("Reasoning with negation"), wrapString("test-suite"), NIL), listO(4, wrapString("constraints"), wrapString("Constraint propagation"), wrapString("test-suite"), NIL), listO(4, wrapString("subsumption"), wrapString("Simple subsumption reasoning"), wrapString("test-suite"), NIL), listO(4, wrapString("family"), wrapString("Subsumption reasoning within a family ontology"), wrapString("test-suite"), NIL), listO(4, wrapString("relation-hierarchy"), wrapString("Finding sub, super and equivalent concepts and relations"), wrapString("test-suite"), NIL), listO(4, wrapString("defaults"), wrapString("Default reasoning with Tweety and friends"), wrapString("test-suite"), NIL), listO(4, wrapString("defaults2"), wrapString("More default reasoning"), wrapString("test-suite"), NIL), listO(4, wrapString("definition-syntax"), wrapString("The whole scoop on relation definition, funny arrows, etc."), wrapString("test-suite"), NIL), listO(4, wrapString("meta-relations"), wrapString("Using meta-properties and relations"), wrapString("test-suite"), NIL), listO(4, wrapString("partial-match"), wrapString("Reasoning with partial information"), wrapString("test-suite"), NIL), listO(4, wrapString("probability-learning"), wrapString("Learning to answer probabilistic queries"), wrapString("test-suite"), NIL), listO(3, wrapString("regression-demo"), wrapString("Learning to predict functions"), NIL), listO(3, wrapString("rule-induction-demo"), wrapString("Learning inference rules"), NIL), listO(4, wrapString("test-suite"), wrapString("PowerLoom test suite"), wrapString("test-suite"), NIL), NIL);
    oHANDLE_EXPLICITLY_QUALIFIED_LOGIC_OBJECTSpo = TRUE;
    oUNFINALIZED_OBJECTSo = list(0);
    oFINALIZEOBJECTSIMMEDIATELYpo.set(FALSE);
    oINHIBITOBJECTFINALIZATIONpo.set(FALSE);
    oLOGIC_RELEVANT_STELLA_COMMANDSo = listO(5, SYM_LOGIC_IN_STELLA_CC, SYM_LOGIC_IN_STELLA_CLEAR_MODULE, SYM_LOGIC_IN_STELLA_DEFMODULE, SYM_LOGIC_IN_STELLA_IN_MODULE, NIL);
  }
}

void helpStartupLogicIn4() {
  {
    defineFunctionObject("PRINT-FEATURES", "(DEFUN PRINT-FEATURES () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Print the currently enabled and available PowerLoom environment features.\")", ((cpp_function_code)(&printFeatures)), NULL);
    defineFunctionObject("LIST-FEATURES", "(DEFUN (LIST-FEATURES LIST) () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Return a list containing two lists, a list of currently enabled PowerLoom\nfeatures, and a list of all available PowerLoom features.\")", ((cpp_function_code)(&listFeatures)), NULL);
    defineFunctionObject("SET-POWERLOOM-FEATURE", "(DEFUN SET-POWERLOOM-FEATURE ((FEATURE KEYWORD)) :DOCUMENTATION \"Enable the PowerLoom environment feature `feature'.\")", ((cpp_function_code)(&setPowerloomFeature)), NULL);
    defineFunctionObject("SET-FEATURE", "(DEFUN (SET-FEATURE (LIST OF KEYWORD)) (|&REST| (FEATURES NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Enable the PowerLoom environment feature(s) named by `features'.\nReturn the list of enabled features.  Calling `set-feature' without any\narguments can be used to display the currently enabled features.\nThe following features are supported:\n\n`just-in-time-inference': Enables interleaving of forward chaining inference\nwithin backward chaining queries.\n\n`iterative-deepening': Tells the query processor to use iterative deepening\ninstead of a depth-first search to find answers.  This is less efficient\nbut necessary for some kinds of highly recursive queries.\n\n`trace-subgoals': Enables the generation of subgoaling trace information during\nbackchaining inference.\n\n`trace-solutions': Prints newly found solutions during retrieval right when they\nare generated as opposed to when the query terminates.\n\n`trace-classifier': Tells the classifier to describe the inferences it draws.\n\n`justifications': Enables the generation of justifications during inference,\nwhich is a prerequiste for the generation of explanations with `(why)'.\n\n`emit-thinking-dots': Tells PowerLoom to annotate its inference progress by\noutputting characters indicating the completion of individual reasoning steps.\n\nBy default, the features `emit-thinking-dots' and `just-in-time-inference'\nare enabled, and the others are disabled.\n\")", ((cpp_function_code)(&setFeature)), ((cpp_function_code)(&setFeatureEvaluatorWrapper)));
    defineFunctionObject("UNSET-POWERLOOM-FEATURE", "(DEFUN UNSET-POWERLOOM-FEATURE ((FEATURE KEYWORD)) :DOCUMENTATION \"Disable the PowerLoom environment feature `feature'.\")", ((cpp_function_code)(&unsetPowerloomFeature)), NULL);
    defineFunctionObject("UNSET-FEATURE", "(DEFUN (UNSET-FEATURE (LIST OF KEYWORD)) (|&REST| (FEATURES NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Disable the PowerLoom environment feature(s) named by `features'.\nReturn the list of enabled features.  Calling `unset-feature' without any\narguments can be used to display the currently enabled features.\nSee `set-feature' for a description of supported features.\")", ((cpp_function_code)(&unsetFeature)), ((cpp_function_code)(&unsetFeatureEvaluatorWrapper)));
    defineFunctionObject("RESET-FEATURES", "(DEFUN (RESET-FEATURES (LIST OF KEYWORD)) () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Reset the PowerLoom environment features to their default settings.\")", ((cpp_function_code)(&resetFeatures)), NULL);
    defineFunctionObject("ENABLED-POWERLOOM-FEATURE?", "(DEFUN (ENABLED-POWERLOOM-FEATURE? BOOLEAN) ((FEATURE KEYWORD)) :DOCUMENTATION \"Return true if the STELLA `feature' is currently enabled.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (MEMB? *CURRENT-POWERLOOM-FEATURES* FEATURE)))", ((cpp_function_code)(&enabledPowerloomFeatureP)), NULL);
    defineFunctionObject("DISABLED-POWERLOOM-FEATURE?", "(DEFUN (DISABLED-POWERLOOM-FEATURE? BOOLEAN) ((FEATURE KEYWORD)) :DOCUMENTATION \"Return true if the STELLA `feature' is currently disabled.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (NOT (MEMB? *CURRENT-POWERLOOM-FEATURES* FEATURE))))", ((cpp_function_code)(&disabledPowerloomFeatureP)), NULL);
    defineFunctionObject("COERCE-OPTION-VALUE", "(DEFUN (COERCE-OPTION-VALUE OBJECT) ((VALUE OBJECT) (TYPE TYPE)))", ((cpp_function_code)(&coerceOptionValue)), NULL);
    defineFunctionObject("PARSE-LOGIC-COMMAND-OPTIONS", "(DEFUN (PARSE-LOGIC-COMMAND-OPTIONS PROPERTY-LIST) ((OPTIONS OBJECT) (|LEGALOPTIONS&TYPES| CONS) (COERCIONERROR? BOOLEAN)))", ((cpp_function_code)(&parseLogicCommandOptions)), NULL);
    defineFunctionObject("PRINT-LOGIC-PROMPT", "(DEFUN PRINT-LOGIC-PROMPT ())", ((cpp_function_code)(&printLogicPrompt)), NULL);
    defineFunctionObject("PRINT-LOGIC-COMMAND-RESULT", "(DEFUN PRINT-LOGIC-COMMAND-RESULT ((RESULT OBJECT)))", ((cpp_function_code)(&printLogicCommandResult)), NULL);
    defineFunctionObject("LOGIC-COMMAND-LOOP-EXIT?", "(DEFUN (LOGIC-COMMAND-LOOP-EXIT? BOOLEAN BOOLEAN) ((COMMAND OBJECT)))", ((cpp_function_code)(&logicCommandLoopExitP)), NULL);
    defineFunctionObject("LOGIC-COMMAND-LOOP", "(DEFUN LOGIC-COMMAND-LOOP ())", ((cpp_function_code)(&logicCommandLoop)), NULL);
    defineFunctionObject("EVALUATE-LOGIC-COMMAND", "(DEFUN (EVALUATE-LOGIC-COMMAND OBJECT) ((COMMAND OBJECT) (FINALIZE? BOOLEAN)))", ((cpp_function_code)(&evaluateLogicCommand)), NULL);
    defineFunctionObject("LOAD", "(DEFUN LOAD ((FILE STRING)) :DOCUMENTATION \"Read logic commands from `file' and evaluate them.\" :COMMAND? TRUE :PUBLIC? TRUE)", ((cpp_function_code)(&load)), ((cpp_function_code)(&loadEvaluatorWrapper)));
    defineFunctionObject("LOAD-STREAM", "(DEFUN LOAD-STREAM ((STREAM INPUT-STREAM)) :DOCUMENTATION \"Read logic commands from `stream' and evaluate them.\" :PUBLIC? TRUE)", ((cpp_function_code)(&loadStream)), NULL);
    defineFunctionObject("PRINT-DEMO-PROMPT", "(DEFUN PRINT-DEMO-PROMPT ())", ((cpp_function_code)(&printDemoPrompt)), NULL);
    defineFunctionObject("DEMO-SKIP-TO-COMMAND", "(DEFUN (DEMO-SKIP-TO-COMMAND BOOLEAN) ((STREAM INPUT-STREAM)))", ((cpp_function_code)(&demoSkipToCommand)), NULL);
    defineFunctionObject("DEMO-PAUSE?", "(DEFUN (DEMO-PAUSE? BOOLEAN BOOLEAN) ((PAUSE? BOOLEAN)))", ((cpp_function_code)(&demoPauseP)), NULL);
    defineFunctionObject("DEMO-FILE", "(DEFUN DEMO-FILE ((FILE FILE-NAME) (PAUSE? BOOLEAN)))", ((cpp_function_code)(&demoFile)), NULL);
    defineFunctionObject("DEMO-ENTRY-FILE", "(DEFUN (DEMO-ENTRY-FILE STRING) ((DEMOENTRY (CONS OF STRING-WRAPPER))))", ((cpp_function_code)(&demoEntryFile)), NULL);
    defineFunctionObject("DEMO-ENTRY-DESCRIPTION", "(DEFUN (DEMO-ENTRY-DESCRIPTION STRING) ((DEMOENTRY (CONS OF STRING-WRAPPER))))", ((cpp_function_code)(&demoEntryDescription)), NULL);
    defineFunctionObject("DEMO-ENTRY-TEST-SUITE?", "(DEFUN (DEMO-ENTRY-TEST-SUITE? BOOLEAN) ((DEMOENTRY (CONS OF STRING-WRAPPER))))", ((cpp_function_code)(&demoEntryTestSuiteP)), NULL);
    defineFunctionObject("SELECT-EXAMPLE-DEMO", "(DEFUN (SELECT-EXAMPLE-DEMO STRING) ((INDEX INTEGER)))", ((cpp_function_code)(&selectExampleDemo)), NULL);
    defineFunctionObject("SELECT-EXAMPLE-DEMO-FROM-MENU", "(DEFUN (SELECT-EXAMPLE-DEMO-FROM-MENU STRING) ())", ((cpp_function_code)(&selectExampleDemoFromMenu)), NULL);
    defineFunctionObject("DEMO-EXAMPLE-DEMOS", "(DEFUN DEMO-EXAMPLE-DEMOS ())", ((cpp_function_code)(&demoExampleDemos)), NULL);
    defineFunctionObject("DEMO", "(DEFUN DEMO (|&REST| (FILEANDPAUSE OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Read logic commands from a file, echo them verbatimly to standard output,\nand evaluate them just as if they had been typed in interactively.\nWhen called with no arguments, present a menu of example demos, otherwise,\nuse the first argument as the name of the file to demo.\nPause for user confirmation after each expression has been read but\nbefore it is evaluated.  Pausing can be turned off by suppling FALSE\nas the optional second argument, or by typing `c' at the pause prompt.\nTyping `?' at the pause prompt prints a list of available commands.\")", ((cpp_function_code)(&demo)), ((cpp_function_code)(&demoEvaluatorWrapper)));
    defineFunctionObject("TEST-LOGIC-FILE", "(DEFUN TEST-LOGIC-FILE ((FILE FILE-NAME)))", ((cpp_function_code)(&testLogicFile)), NULL);
    defineFunctionObject("GET-FORMATTED-DATE-AND-TIME", "(DEFUN (GET-FORMATTED-DATE-AND-TIME STRING) ())", ((cpp_function_code)(&getFormattedDateAndTime)), NULL);
    defineFunctionObject("RUN-POWERLOOM-TESTS", "(DEFUN RUN-POWERLOOM-TESTS () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Run the PowerLoom test suite.  Currently this simply runs all demos and\nechos commands and their results to standard output.  The output can then\nbe diffed with previously validated runs to find deviations.\")", ((cpp_function_code)(&runPowerloomTests)), NULL);
    defineFunctionObject("PRINT-FORMULA-CONTAINING-ERROR", "(DEFUN PRINT-FORMULA-CONTAINING-ERROR ((SELF OBJECT) (STREAM OUTPUT-STREAM)))", ((cpp_function_code)(&printFormulaContainingError)), NULL);
    defineFunctionObject("HELP-SIGNAL-PROPOSITION-ERROR", "(DEFUN HELP-SIGNAL-PROPOSITION-ERROR ((STREAM OUTPUT-STREAM) (WARNINGORERROR KEYWORD)))", ((cpp_function_code)(&helpSignalPropositionError)), NULL);
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION PERMUTATION-TABLE :TYPE (KEY-VALUE-LIST OF VECTOR SLOT) :OPTION-KEYWORD :PERMUTATION-TABLE :ALLOCATION :DYNAMIC)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT TABLE RELATION-PARAMETER-TYPE-SPECIFIERS :RENAMES TUPLE-DOMAINS)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT MODULE MODULE-LOGIC-DIALECT :TYPE KEYWORD :DEFAULT NULL :OPTION-KEYWORD :LOGIC-DIALECT :PUBLIC? TRUE :ALLOCATION :DYNAMIC)");
    defineFunctionObject("LOGIC-DIALECT", "(DEFUN (LOGIC-DIALECT KEYWORD) ((SELF OBJECT)))", ((cpp_function_code)(&logicDialect)), NULL);
    defineFunctionObject("LOOKUP-LOGIC-OBJECT-SURROGATE", "(DEFUN (LOOKUP-LOGIC-OBJECT-SURROGATE SURROGATE) ((NAME SYMBOL) (DEFINITIONMODULE MODULE)))", ((cpp_function_code)(&lookupLogicObjectSurrogate)), NULL);
    defineFunctionObject("INTERN-LOGIC-OBJECT-SURROGATE", "(DEFUN (INTERN-LOGIC-OBJECT-SURROGATE SURROGATE) ((NAME SYMBOL)))", ((cpp_function_code)(&internLogicObjectSurrogate)), NULL);
    defineFunctionObject("NAME-OBJECT-METACLASS", "(DEFUN (NAME-OBJECT-METACLASS STRING) ((SELF OBJECT)))", ((cpp_function_code)(&nameObjectMetaclass)), NULL);
    defineFunctionObject("LOGIC-OBJECT-DEFINITION-TYPE", "(DEFUN (LOGIC-OBJECT-DEFINITION-TYPE KEYWORD) ((NAME SYMBOL) (OLDOBJECT OBJECT) (NEWOBJECT OBJECT)))", ((cpp_function_code)(&logicObjectDefinitionType)), NULL);
    defineFunctionObject("BIND-LOGIC-OBJECT-TO-SURROGATE", "(DEFUN BIND-LOGIC-OBJECT-TO-SURROGATE ((NAME SYMBOL) (OBJECT OBJECT)))", ((cpp_function_code)(&bindLogicObjectToSurrogate)), NULL);
    defineFunctionObject("REDEFINE-LOGIC-OBJECT", "(DEFUN REDEFINE-LOGIC-OBJECT ((NAME SYMBOL) (OLDOBJECT OBJECT) (NEWOBJECT OBJECT)))", ((cpp_function_code)(&redefineLogicObject)), NULL);
    defineFunctionObject("EXPLICITLY-QUALIFIED-LOGIC-OBJECT-NAME?", "(DEFUN (EXPLICITLY-QUALIFIED-LOGIC-OBJECT-NAME? BOOLEAN) ((OBJECTNAME GENERALIZED-SYMBOL) (DEFINITIONMODULE MODULE)))", ((cpp_function_code)(&explicitlyQualifiedLogicObjectNameP)), NULL);
    defineFunctionObject("COERCE-TO-BOUND-OR-LOCAL-SURROGATE", "(DEFUN (COERCE-TO-BOUND-OR-LOCAL-SURROGATE SURROGATE) ((SELF GENERALIZED-SYMBOL)))", ((cpp_function_code)(&coerceToBoundOrLocalSurrogate)), NULL);
    defineExternalSlotFromStringifiedSource("(DEFSLOT LOGIC-OBJECT OBJECT-AXIOMS :TYPE CONS :DEFAULT NULL :READER AXIOMS :OPTION-KEYWORD :AXIOMS :OPTION-HANDLER DEFINITION-AXIOMS-HANDLER :ALLOCATION :DYNAMIC)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT PROPOSITION PROPOSITION-AXIOMS :TYPE CONS :DEFAULT NULL :WRITER AXIOMS-SETTER :OPTION-KEYWORD :AXIOMS :OPTION-HANDLER DEFINITION-AXIOMS-HANDLER :ALLOCATION :DYNAMIC)");
    defineFunctionObject("AXIOMS", "(DEFUN (AXIOMS CONS) ((SELF OBJECT)))", ((cpp_function_code)(&axioms)), NULL);
    defineFunctionObject("AXIOMS-SETTER", "(DEFUN (AXIOMS-SETTER OBJECT) ((SELF OBJECT) (AXIOMS CONS)))", ((cpp_function_code)(&axiomsSetter)), NULL);
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS1 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<= :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS2 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :=> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS3 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<<= :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS4 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :=>> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS5 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<=> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS6 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<=>> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS7 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<<=> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS8 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<<=>> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS9 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<~ :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS10 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :~> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
  }
}

void helpStartupLogicIn5() {
  {
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS11 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<<~ :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS12 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :~>> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS13 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<~> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS14 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<~>> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS15 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<<~> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION AXIOMS-ALIAS16 :RENAMES OBJECT-AXIOMS :OPTION-KEYWORD :<<~>> :OPTION-HANDLER DEFINITION-HALF-RULE-HANDLER)");
    defineFunctionObject("DEFINITION-AXIOMS-HANDLER", "(DEFUN DEFINITION-AXIOMS-HANDLER ((SELF NAMED-DESCRIPTION) (SLOT STORAGE-SLOT) (THEAXIOMS OBJECT)))", ((cpp_function_code)(&definitionAxiomsHandler)), NULL);
    defineFunctionObject("DEFINITION-HALF-RULE-HANDLER", "(DEFUN DEFINITION-HALF-RULE-HANDLER ((SELF NAMED-DESCRIPTION) (SLOT STORAGE-SLOT) (BODY OBJECT)))", ((cpp_function_code)(&definitionHalfRuleHandler)), NULL);
    defineFunctionObject("COMBINE-AXIOM-LISTS", "(DEFUN (COMBINE-AXIOM-LISTS CONS) ((OLDAXIOMS CONS) (NEWAXIOMS OBJECT)))", ((cpp_function_code)(&combineAxiomLists)), NULL);
    defineFunctionObject("YIELD-RELATION-PARAMETERS-TREE", "(DEFUN (YIELD-RELATION-PARAMETERS-TREE CONS) ((SELF NAMED-DESCRIPTION) (DROPFUNCTIONPARAMETER? BOOLEAN) (TYPED? BOOLEAN)))", ((cpp_function_code)(&yieldRelationParametersTree)), NULL);
    defineFunctionObject("COMPLETE-RULE-DEFINITION", "(DEFUN (COMPLETE-RULE-DEFINITION OBJECT) ((SELF NAMED-DESCRIPTION) (BODY OBJECT) (ARROW SYMBOL)))", ((cpp_function_code)(&completeRuleDefinition)), NULL);
    defineFunctionObject("DEFINITION-KEYWORD-AXIOMS-HANDLER", "(DEFUN DEFINITION-KEYWORD-AXIOMS-HANDLER ((SELF OBJECT) (SELFNAME SYMBOL) (KEY KEYWORD) (VALUE OBJECT)))", ((cpp_function_code)(&definitionKeywordAxiomsHandler)), NULL);
    defineFunctionObject("HELP-DEFINE-KEYWORD-AXIOMS", "(DEFUN (HELP-DEFINE-KEYWORD-AXIOMS CONS) ((SELFNAME SYMBOL) (KEY KEYWORD) (VALUE OBJECT)))", ((cpp_function_code)(&helpDefineKeywordAxioms)), NULL);
    defineFunctionObject("ASSERT-KEYWORD-AXIOM", "(DEFUN ASSERT-KEYWORD-AXIOM ((SELF OBJECT) (SELFNAME SYMBOL) (KEY KEYWORD) (VALUE OBJECT)))", ((cpp_function_code)(&assertKeywordAxiom)), NULL);
    defineFunctionObject("REGISTER-UNFINALIZED-OBJECT", "(DEFUN REGISTER-UNFINALIZED-OBJECT ((OBJECT OBJECT)))", ((cpp_function_code)(&registerUnfinalizedObject)), NULL);
    defineFunctionObject("CLEANUP-UNFINALIZED-OBJECTS", "(DEFUN CLEANUP-UNFINALIZED-OBJECTS ())", ((cpp_function_code)(&cleanupUnfinalizedObjects)), NULL);
    defineFunctionObject("LINK-ORIGINATED-PROPOSITION", "(DEFUN LINK-ORIGINATED-PROPOSITION ((OBJECT OBJECT) (PROPOSITION PROPOSITION)))", ((cpp_function_code)(&linkOriginatedProposition)), NULL);
    defineFunctionObject("HELP-FINALIZE-OBJECT-AXIOMS", "(DEFUN (HELP-FINALIZE-OBJECT-AXIOMS (CONS OF PROPOSITION)) ((THEAXIOMS CONS)))", ((cpp_function_code)(&helpFinalizeObjectAxioms)), NULL);
    defineFunctionObject("FINALIZE-OBJECT-AXIOMS", "(DEFUN FINALIZE-OBJECT-AXIOMS ((SELF OBJECT)))", ((cpp_function_code)(&finalizeObjectAxioms)), NULL);
    defineFunctionObject("CHECK-DESCRIPTION-ARGUMENT-TYPES", "(DEFUN CHECK-DESCRIPTION-ARGUMENT-TYPES ((SELF NAMED-DESCRIPTION)))", ((cpp_function_code)(&checkDescriptionArgumentTypes)), NULL);
    defineFunctionObject("FINALIZE-OBJECT", "(DEFUN FINALIZE-OBJECT ((SELF OBJECT)))", ((cpp_function_code)(&finalizeObject)), NULL);
    defineFunctionObject("FINALIZED-OBJECT?", "(DEFUN (FINALIZED-OBJECT? BOOLEAN) ((SELF OBJECT)))", ((cpp_function_code)(&finalizedObjectP)), NULL);
    defineFunctionObject("OBJECTS-ARE-FINALIZED?", "(DEFUN (OBJECTS-ARE-FINALIZED? BOOLEAN) () :GLOBALLY-INLINE? TRUE (RETURN (EMPTY? (THE-CONS-LIST *UNFINALIZED-OBJECTS*))))", ((cpp_function_code)(&objectsAreFinalizedP)), NULL);
    defineFunctionObject("FINALIZE-OBJECTS", "(DEFUN FINALIZE-OBJECTS () :DOCUMENTATION \"Finalize all currently unfinalized objects.\nThe user-level entry point for this is `(process-definitions)'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&finalizeObjects)), NULL);
    defineFunctionObject("HELP-DEFINE-RELATION-FROM-PARSE-TREE", "(DEFUN (HELP-DEFINE-RELATION-FROM-PARSE-TREE NAMED-DESCRIPTION) ((TREE CONS) (STRINGIFIEDSOURCE STRING)))", ((cpp_function_code)(&helpDefineRelationFromParseTree)), NULL);
    defineFunctionObject("PARSE-RELATION-PARAMETERS-TREE", "(DEFUN (PARSE-RELATION-PARAMETERS-TREE (LIST OF SYMBOL) (LIST OF TYPE) BOOLEAN) ((PARAMETERS CONS)))", ((cpp_function_code)(&parseRelationParametersTree)), NULL);
    defineFunctionObject("GET-IDENTICAL-RELATION", "(DEFUN (GET-IDENTICAL-RELATION NAMED-DESCRIPTION) ((NAME SYMBOL) (STRINGIFIEDSOURCE STRING)))", ((cpp_function_code)(&getIdenticalRelation)), NULL);
    defineMethodObject("(DEFMETHOD PROCESS-DEFINITION-OPTIONS ((SELF NAMED-DESCRIPTION) (OPTIONS OBJECT)))", ((cpp_method_code)(&NamedDescription::processDefinitionOptions)), ((cpp_method_code)(NULL)));
    defineFunctionObject("DEFFUNCTION", "(DEFUN (DEFFUNCTION NAMED-DESCRIPTION) (|&REST| (ARGS PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a logic function.  The accepted syntax is:\n	 \n (deffunction <funconst> (<vardecl>+) [:-> <vardecl>]\n    [:documentation <string>]\n    [:<= <sentence>] | [:=> <sentence>] |\n    [:<<= <sentence>] | [:=>> <sentence>] | \n    [:<=> <sentence>] | [:<=>> <sentence>] |\n    [:<<=> <sentence>] | [:<<=>> <sentence>] |\n    [:axioms {<sentence> | (<sentence>+)}]\n    [<keyword-option>*])\n	\nFunction parameters can be typed or untyped.  If the `:->' option is\nsupplied, it specifies the output variable of the function.  Otherwise,\nthe last variable in the parameter list is used as the output variable.\nSee `defrelation' for a description of `<keyword-option>'s.\n\")", ((cpp_function_code)(&deffunction)), ((cpp_function_code)(&deffunctionEvaluatorWrapper)));
    defineFunctionObject("CALL-DEFFUNCTION", "(DEFUN (CALL-DEFFUNCTION NAMED-DESCRIPTION) ((ARGUMENTS CONS)) :DOCUMENTATION \"Callable version of the `deffunction' command (which see).\nExpects the same arguments as `deffunction' but supplied as a list.\" :PUBLIC? TRUE)", ((cpp_function_code)(&callDeffunction)), NULL);
    defineFunctionObject("NORMALIZE-DEFFUNCTION-ARGUMENTS", "(DEFUN (NORMALIZE-DEFFUNCTION-ARGUMENTS CONS) ((ARGUMENTS CONS)))", ((cpp_function_code)(&normalizeDeffunctionArguments)), NULL);
    defineFunctionObject("DEFRELATION", "(DEFUN (DEFRELATION NAMED-DESCRIPTION) (|&REST| (ARGS PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a logic relation.  The accepted syntax is:\n	 \n (defrelation <relconst> (<vardecl>+)\n    [:documentation <string>]\n    [:<= <sentence>] | [:=> <sentence>] |\n    [:<<= <sentence>] | [:=>> <sentence>] | \n    [:<=> <sentence>] | [:<=>> <sentence>] |\n    [:<<=> <sentence>] | [:<<=>> <sentence>] |\n    [:axioms {<sentence> | (<sentence>+)}]\n    [<keyword-option>*])\n	\nRelation parameters can be typed or untyped.\n`<keyword-option>' represents a keyword followed by a value that states an\nassertion about `<relconst>'.  For example, including the option `:foo bar'\nstates that the proposition `(foo <relconst> bar)' is true.  `:foo (bar fum)'\nstates that both `(foo <relconst> bar)' and `(foo <relconst> fum)' are true.\n`:foo true' states that `(foo <relconst>)' is true, `:foo false' states that\n`(not (foo <relconst>))' is true.\n\")", ((cpp_function_code)(&defrelation)), ((cpp_function_code)(&defrelationEvaluatorWrapper)));
    defineFunctionObject("CALL-DEFRELATION", "(DEFUN (CALL-DEFRELATION NAMED-DESCRIPTION) ((ARGUMENTS CONS)) :DOCUMENTATION \"Callable version of the `defrelation' command (which see).\nExpects the same arguments as `defrelation' but supplied as a list.\" :PUBLIC? TRUE)", ((cpp_function_code)(&callDefrelation)), NULL);
    defineFunctionObject("NORMALIZE-DEFRELATION-ARGUMENTS", "(DEFUN (NORMALIZE-DEFRELATION-ARGUMENTS CONS) ((ARGUMENTS CONS)))", ((cpp_function_code)(&normalizeDefrelationArguments)), NULL);
    defineFunctionObject("DEFCONCEPT", "(DEFUN (DEFCONCEPT NAMED-DESCRIPTION) (|&REST| (ARGS PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a concept.  The accepted syntax is:\n	 \n (defconcept <conceptconst> [(<var> <parent>*)]\n    [:documentation <string>]\n    [:<= <sentence>] | [:=> <sentence>] |\n    [:<<= <sentence>] | [:=>> <sentence>] | \n    [:<=> <sentence>] | [:<=>> <sentence>] | [:<<=> <sentence>] |\n    [:<<=>> <sentence>] |\n    [:axioms {<sentence> | (<sentence>+)}] |\n    <keyword-option>*)\n	\nDeclaration of a concept variable `<var>' is optional, unless any\nimplication (arrow) options are supplied that need to reference it.  A\npossibly empty list of concept names following `<var>' is taken as the list\nof parents of `<conceptconst>'.  Alternatively, parents can be specified\nvia the `:=>' option.  If no parents are specified, the parent of\n`<conceptconst>' is taken to be THING.  `<keyword-option>' represents a\nkeyword followed by a value that states an assertion about `<conceptconst>'.\nSee `defrelation' for a description of `<keyword-option>'s.\n\")", ((cpp_function_code)(&defconcept)), ((cpp_function_code)(&defconceptEvaluatorWrapper)));
    defineFunctionObject("CALL-DEFCONCEPT", "(DEFUN (CALL-DEFCONCEPT NAMED-DESCRIPTION) ((ARGUMENTS CONS)) :DOCUMENTATION \"Callable version of the `defconcept' command (which see).\nExpects the same arguments as `defconcept' but supplied as a list.\" :PUBLIC? TRUE)", ((cpp_function_code)(&callDefconcept)), NULL);
    defineFunctionObject("NORMALIZE-DEFCONCEPT-ARGUMENTS", "(DEFUN (NORMALIZE-DEFCONCEPT-ARGUMENTS CONS) ((ARGUMENTS CONS)))", ((cpp_function_code)(&normalizeDefconceptArguments)), NULL);
    defineFunctionObject("DEFINE-RELATION-FROM-PARSE-TREE", "(DEFUN (DEFINE-RELATION-FROM-PARSE-TREE NAMED-DESCRIPTION) ((TREE CONS)))", ((cpp_function_code)(&defineRelationFromParseTree)), NULL);
    defineFunctionObject("DEFOBJECT", "(DEFUN (DEFOBJECT LOGIC-OBJECT) (|&REST| (ARGS PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a logic instance.  The accepted syntax is:\n	 \n (defobject <constant>\n    [:documentation <string>]\n    [<keyword-option>*])\n	\n`<keyword-option>' represents a keyword followed by a value\nthat states an assertion about <constant>.  See `defrelation' for a\ndescription of `<keyword-option>'s.\n\n`defobject' provides a sugar-coated way to assert a collection of facts\nabout a logic constant, but otherwise adds nothing in terms of functionality.\n\")", ((cpp_function_code)(&defobject)), ((cpp_function_code)(&defobjectEvaluatorWrapper)));
    defineFunctionObject("DEFINSTANCE", "(DEFUN (DEFINSTANCE LOGIC-OBJECT) (|&REST| (ARGS PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a logic instance (`definstance' is an alias\nfor `defobject' which see).\")", ((cpp_function_code)(&definstance)), ((cpp_function_code)(&definstanceEvaluatorWrapper)));
    defineFunctionObject("CALL-DEFOBJECT", "(DEFUN (CALL-DEFOBJECT LOGIC-OBJECT) ((ARGUMENTS CONS)) :DOCUMENTATION \"Callable version of the `defobject' command (which see).\nExpects the same arguments as `defobject' but supplied as a list.\" :PUBLIC? TRUE)", ((cpp_function_code)(&callDefobject)), NULL);
    defineFunctionObject("NORMALIZE-DEFOBJECT-ARGUMENTS", "(DEFUN (NORMALIZE-DEFOBJECT-ARGUMENTS CONS) ((ARGUMENTS CONS)))", ((cpp_function_code)(&normalizeDefobjectArguments)), NULL);
    defineMethodObject("(DEFMETHOD PROCESS-DEFINITION-OPTIONS ((SELF LOGIC-OBJECT) (OPTIONS OBJECT)))", ((cpp_method_code)(&LogicObject::processDefinitionOptions)), ((cpp_method_code)(NULL)));
    defineFunctionObject("DEFPROPOSITION", "(DEFUN (DEFPROPOSITION PROPOSITION) (|&REST| (ARGS PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a named proposition.  The accepted syntax is:\n	 \n (defproposition <name> <sentence>\n    [:documentation <string>]\n    [:forward-only? {true | false}]\n    [:backward-only? {true | false}]\n    [:dont-optimize? {true | false}]\n    [:confidence-level {:strict | :default}]\n    [<keyword-option>*])\n	\n<sentence> can be any sentence that is legal as a top-level assertion.\n<name> can be a string or symbol and will be bound to the asserted\nproposition represented by <sentence>.  After this definition every\noccurrence of <name> will be replaced by the associated proposition.\n\nThe options :forward-only? and :backward-only? can be used to tell the\ninference engine to only use the rule in forward or backward direction\n(this can also be achieved by using the `<<=' or `=>>' implication\narrows).  :dont-optimize?  tells the inference engine to not rearrange\nthe order of clauses in the antecedent of a rule and instead evaluate\nthem in their original order.  :confidence-level can be used to mark a\nproposition as default only.\n\n`<keyword-option>' represents a keyword followed by a value\nthat states an assertion about the proposition <name>.  See `defrelation'\nfor a description of `<keyword-option>'s.\n\")", ((cpp_function_code)(&defproposition)), ((cpp_function_code)(&defpropositionEvaluatorWrapper)));
    defineFunctionObject("DEFRULE", "(DEFUN (DEFRULE PROPOSITION) (|&REST| (ARGS PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a named rule (`defrule' is an alias\nfor `defproposition' which see).\")", ((cpp_function_code)(&defrule)), ((cpp_function_code)(&defruleEvaluatorWrapper)));
    defineFunctionObject("CALL-DEFPROPOSITION", "(DEFUN (CALL-DEFPROPOSITION PROPOSITION) ((ARGUMENTS CONS)) :DOCUMENTATION \"Callable version of the `defproposition' command (which see).\nExpects the same arguments as `defproposition' but supplied as a list.\" :PUBLIC? TRUE)", ((cpp_function_code)(&callDefproposition)), NULL);
    defineFunctionObject("NORMALIZE-DEFPROPOSITION-ARGUMENTS", "(DEFUN (NORMALIZE-DEFPROPOSITION-ARGUMENTS CONS) ((ARGUMENTS CONS)))", ((cpp_function_code)(&normalizeDefpropositionArguments)), NULL);
    defineMethodObject("(DEFMETHOD PROCESS-DEFINITION-OPTIONS ((SELF PROPOSITION) (OPTIONS OBJECT)))", ((cpp_method_code)(&Proposition::processDefinitionOptions)), ((cpp_method_code)(NULL)));
    defineFunctionObject("COMMAND<", "(DEFUN (COMMAND< BOOLEAN) ((COMMAND1 METHOD-SLOT) (COMMAND2 METHOD-SLOT)))", ((cpp_function_code)(&commandL)), NULL);
    defineFunctionObject("LIST-LOGIC-COMMANDS", "(DEFUN (LIST-LOGIC-COMMANDS (LIST OF METHOD-SLOT)) ())", ((cpp_function_code)(&listLogicCommands)), NULL);
    defineFunctionObject("HELP", "(DEFUN HELP (|&REST| (COMMANDS SYMBOL)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Describe specific commands, or print a list of available commands.\")", ((cpp_function_code)(&help)), ((cpp_function_code)(&helpEvaluatorWrapper)));
    defineFunctionObject("STARTUP-LOGIC-IN", "(DEFUN STARTUP-LOGIC-IN () :PUBLIC? TRUE)", ((cpp_function_code)(&startupLogicIn)), NULL);
    { MethodSlot* function = lookupFunction(SYM_LOGIC_IN_LOGIC_STARTUP_LOGIC_IN);

      setDynamicSlotValue(function->dynamicSlots, SYM_LOGIC_IN_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Logic-In"), NULL_STRING_WRAPPER);
    }
  }
}

void startupLogicIn() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupLogicIn1();
      helpStartupLogicIn2();
    }
    if (currentStartupTimePhaseP(4)) {
      helpStartupLogicIn3();
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupLogicIn4();
      helpStartupLogicIn5();
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *AVAILABLE-POWERLOOM-FEATURES* (LIST OF KEYWORD) (LIST :TRACE-SUBGOALS :TRACE-SOLUTIONS :TRACE-CLASSIFIER :ITERATIVE-DEEPENING :JUSTIFICATIONS :JUST-IN-TIME-INFERENCE :EMIT-THINKING-DOTS) :DOCUMENTATION \"List of PowerLoom environment features.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CURRENT-POWERLOOM-FEATURES* (LIST OF KEYWORD) (LIST) :DOCUMENTATION \"List of currently enabled PowerLoom environment features.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DEFAULT-POWERLOOM-FEATURES* (LIST OF KEYWORD) (LIST :JUST-IN-TIME-INFERENCE :EMIT-THINKING-DOTS) :DOCUMENTATION \"List of PowerLoom environment features enabled upon call to\n'reset-features'.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LOGIC-PROMPT* STRING \"|= \" :DOCUMENTATION \"The prompt used by the PowerLoom listener.\" :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LOGIC-COMMAND-RESULT-INDENT* STRING \"\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *CAREFUL-LOGIC-COMMAND-LOOP-EXIT*? BOOLEAN (VERBATIM :COMMON-LISP FALSE :OTHERWISE TRUE) :DOCUMENTATION \"If TRUE exiting from the logic-command loop (or PowerLoom\nlistener) will be protected by a confirmation dialog.  This is mainly useful\nfor C++ where exiting the listener will also exit the program.\" :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *DEMO-LEVEL* INTEGER 0)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DEMO-FILE-DEFAULTS* (CONS OF STRING-WRAPPER) (CONS-LIST \"PL:sources;logic;demos;foo.plm\" \"PL:sources;logic;demos;foo.ploom\" \"PL:sources;logic;demos;foo.ste\"))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DEMO-FILES* (CONS OF (CONS OF STRING-WRAPPER)) (BQUOTE ((\"basics\" \"Basic PowerLoom commands\" \"test-suite\") (\"classes\" \"Primitive and defined classes\" \"test-suite\") (\"collections\" \"Reasoning with collections\" \"test-suite\") (\"append\" \"Prolog-style `append'\" \"test-suite\") (\"inequalities\" \"Reasoning with inequalities\" \"test-suite\") (\"recursion\" \"Reasoning with recursive rules\" \"test-suite\") (\"negation\" \"Reasoning with negation\" \"test-suite\") (\"constraints\" \"Constraint propagation\" \"test-suite\") (\"subsumption\" \"Simple subsumption reasoning\" \"test-suite\") (\"family\" \"Subsumption reasoning within a family ontology\" \"test-suite\") (\"relation-hierarchy\" \"Finding sub, super and equivalent concepts and relations\" \"test-suite\") (\"defaults\" \"Default reasoning with Tweety and friends\" \"test-suite\") (\"defaults2\" \"More default reasoning\" \"test-suite\") (\"definition-syntax\" \"The whole scoop on relation definition, funny arrows, etc.\" \"test-suite\") (\"meta-relations\" \"Using meta-properties and relations\" \"test-suite\") (\"partial-match\" \"Reasoning with partial information\" \"test-suite\") (\"probability-learning\" \"Learning to answer probabilistic queries\" \"test-suite\") (\"regression-demo\" \"Learning to predict functions\") (\"rule-induction-demo\" \"Learning inference rules\") (\"test-suite\" \"PowerLoom test suite\" \"test-suite\"))) :DOCUMENTATION \"List of example demo files.\nEach entry is a `(<file> <description>)' pair.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *TERMSOURCEBEINGPARSED* STRING NULL :DOCUMENTATION \"Points to the source of the relation being parsed.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *DESCRIPTIONUNDERCONSTRUCTION* OBJECT NULL :DOCUMENTATION \"Pofints to a description or its parse tree which\nis the input to the description being constructed.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *TERMUNDERCONSTRUCTION* OBJECT NULL :DOCUMENTATION \"Points to the parse tree which is the input to the\nproposition being constructed.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *EXPRESSION-SIZE-CUTOFF* INTEGER 300 :DOCUMENTATION \"Limit on how big an s-expression we will print within\nan error message.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *HANDLE-EXPLICITLY-QUALIFIED-LOGIC-OBJECTS?* BOOLEAN TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *UNFINALIZED-OBJECTS* LIST (LIST) :DOCUMENTATION \"List of objects whose definitions and/or associated\naxioms and constraints are not yet processed.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *FINALIZEOBJECTSIMMEDIATELY?* BOOLEAN FALSE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *INHIBITOBJECTFINALIZATION?* BOOLEAN FALSE :DOCUMENTATION \"Used to prevent finalization from triggering in the\nmiddle of 'delicate' computations.  Also used to prevent recursive\ninvocation of 'finalize-objects'.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LOGIC-RELEVANT-STELLA-COMMANDS* (CONS OF SYMBOL) (BQUOTE (CC CLEAR-MODULE DEFMODULE IN-MODULE)))");
    }
  }
}

Keyword* KWD_LOGIC_IN_TRACE_SUBGOALS = NULL;

Keyword* KWD_LOGIC_IN_TRACE_SOLUTIONS = NULL;

Keyword* KWD_LOGIC_IN_TRACE_CLASSIFIER = NULL;

Keyword* KWD_LOGIC_IN_ITERATIVE_DEEPENING = NULL;

Keyword* KWD_LOGIC_IN_JUSTIFICATIONS = NULL;

Keyword* KWD_LOGIC_IN_JUST_IN_TIME_INFERENCE = NULL;

Keyword* KWD_LOGIC_IN_EMIT_THINKING_DOTS = NULL;

Keyword* KWD_LOGIC_IN_GOAL_TREE = NULL;

Keyword* KWD_LOGIC_IN_CLASSIFIER_INFERENCES = NULL;

Keyword* KWD_LOGIC_IN_CLOSED_WORLD = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_INTEGER = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_FLOAT = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_NUMBER = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_KEYWORD = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_GENERALIZED_SYMBOL = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_SYMBOL = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_BOOLEAN = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_MODULE = NULL;

Surrogate* SGT_LOGIC_IN_LOGIC_DESCRIPTION = NULL;

Surrogate* SGT_LOGIC_IN_LOGIC_NAMED_DESCRIPTION = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_CONS = NULL;

Keyword* KWD_LOGIC_IN_ERROR = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_PROPERTY_LIST = NULL;

Surrogate* SGT_LOGIC_IN_LOGIC_IDENTITY = NULL;

Keyword* KWD_LOGIC_IN_REALISTIC = NULL;

Keyword* KWD_LOGIC_IN_BYE = NULL;

Keyword* KWD_LOGIC_IN_EXIT = NULL;

Keyword* KWD_LOGIC_IN_HALT = NULL;

Keyword* KWD_LOGIC_IN_QUIT = NULL;

Keyword* KWD_LOGIC_IN_STOP = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_BYE = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_EXIT = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_HALT = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_QUIT = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_STOP = NULL;

Keyword* KWD_LOGIC_IN_DEFINE = NULL;

Symbol* SYM_LOGIC_IN_STELLA_IN_MODULE = NULL;

Keyword* KWD_LOGIC_IN_FINALIZE = NULL;

Symbol* SYM_LOGIC_IN_STELLA_DEFMODULE = NULL;

Symbol* SYM_LOGIC_IN_STELLA_CLEAR_MODULE = NULL;

Symbol* SYM_LOGIC_IN_STELLA_DEFCLASS = NULL;

Symbol* SYM_LOGIC_IN_STELLA_DEFSLOT = NULL;

Symbol* SYM_LOGIC_IN_STELLA_DEFUN = NULL;

Symbol* SYM_LOGIC_IN_STELLA_DEFMETHOD = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_DEFCONCEPT = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_DEFFUNCTION = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_DEFRELATION = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_DEFOBJECT = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_DEFINSTANCE = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_IN_DIALECT = NULL;

Keyword* KWD_LOGIC_IN_WHITE_SPACE = NULL;

Symbol* SYM_LOGIC_IN_STELLA_FALSE = NULL;

Keyword* KWD_LOGIC_IN_WARNING = NULL;

Surrogate* SGT_LOGIC_IN_LOGIC_PROPOSITION = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_RELATION = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_MODULE_LOGIC_DIALECT = NULL;

Keyword* KWD_LOGIC_IN_KIF = NULL;

Surrogate* SGT_LOGIC_IN_LOGIC_LOGIC_OBJECT = NULL;

Keyword* KWD_LOGIC_IN_DEFINITION = NULL;

Keyword* KWD_LOGIC_IN_REDEFINITION = NULL;

Keyword* KWD_LOGIC_IN_PROPER_DEFINITION = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_OBJECT_AXIOMS = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_PROPOSITION_AXIOMS = NULL;

Symbol* SYM_LOGIC_IN_STELLA_SLOT_OPTION_KEYWORD = NULL;

Symbol* SYM_LOGIC_IN_STELLA_AND = NULL;

Surrogate* SGT_LOGIC_IN_STELLA_THING = NULL;

Symbol* SYM_LOGIC_IN_STELLA_FORALL = NULL;

Symbol* SYM_LOGIC_IN_STELLA_NOT = NULL;

Keyword* KWD_LOGIC_IN_ASSERT_TRUE = NULL;

Symbol* SYM_LOGIC_IN_STELLA_BADp = NULL;

Symbol* SYM_LOGIC_IN_PL_KERNEL_KB_NTH_DOMAIN = NULL;

Symbol* SYM_LOGIC_IN_PL_KERNEL_KB_DOMAIN = NULL;

Symbol* SYM_LOGIC_IN_PL_KERNEL_KB_RANGE = NULL;

Keyword* KWD_LOGIC_IN__g = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_pSELF = NULL;

Keyword* KWD_LOGIC_IN_eg = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_DEFPROPOSITION = NULL;

Keyword* KWD_LOGIC_IN_CONCEIVE = NULL;

Keyword* KWD_LOGIC_IN_FORALL = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_SATELLITE_PROPOSITIONS = NULL;

Keyword* KWD_LOGIC_IN_CONFIDENCE_LEVEL = NULL;

Keyword* KWD_LOGIC_IN_DEFAULT = NULL;

Keyword* KWD_LOGIC_IN_PRESUME_TRUE = NULL;

Keyword* KWD_LOGIC_IN_FORWARDp = NULL;

Keyword* KWD_LOGIC_IN_FORWARD_ONLYp = NULL;

Keyword* KWD_LOGIC_IN_BACKWARDp = NULL;

Keyword* KWD_LOGIC_IN_BACKWARD_ONLYp = NULL;

Keyword* KWD_LOGIC_IN_WEIGHT = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_ABOUT = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_FORWARD_ONLYp = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_BACKWARD_ONLYp = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_DONT_OPTIMIZEp = NULL;

Symbol* SYM_LOGIC_IN_STELLA_CC = NULL;

Symbol* SYM_LOGIC_IN_STELLA_METHOD_COMMANDp = NULL;

Symbol* SYM_LOGIC_IN_STELLA_DOCUMENTATION = NULL;

Symbol* SYM_LOGIC_IN_LOGIC_STARTUP_LOGIC_IN = NULL;

Symbol* SYM_LOGIC_IN_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
