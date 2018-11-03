//  -*- Mode: Java -*-
//
// _StartupMachineLearning.java

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

package edu.isi.powerloom.logic;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.stella.*;

public class _StartupMachineLearning {
  static void helpStartupMachineLearning1() {
    {
      Logic.SGT_LOGIC_TRAINING_EXAMPLE = ((Surrogate)(Stella.internRigidSymbolWrtModule("TRAINING-EXAMPLE", null, 1)));
      Logic.SYM_LOGIC_CONCEPT = ((Symbol)(Stella.internRigidSymbolWrtModule("CONCEPT", null, 0)));
      Logic.SYM_STELLA_NAME = ((Symbol)(Stella.internRigidSymbolWrtModule("NAME", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.SYM_LOGIC_INPUT_FEATURES = ((Symbol)(Stella.internRigidSymbolWrtModule("INPUT-FEATURES", null, 0)));
      Logic.SYM_LOGIC_INPUT = ((Symbol)(Stella.internRigidSymbolWrtModule("INPUT", null, 0)));
      Logic.SYM_LOGIC_FACTS = ((Symbol)(Stella.internRigidSymbolWrtModule("FACTS", null, 0)));
      Logic.SYM_LOGIC_NN_HIDDEN = ((Symbol)(Stella.internRigidSymbolWrtModule("NN-HIDDEN", null, 0)));
      Logic.SYM_LOGIC_OUTPUT = ((Symbol)(Stella.internRigidSymbolWrtModule("OUTPUT", null, 0)));
      Logic.SYM_LOGIC_TEMP = ((Symbol)(Stella.internRigidSymbolWrtModule("TEMP", null, 0)));
      Logic.SYM_LOGIC_CACHED_SOLUTION = ((Symbol)(Stella.internRigidSymbolWrtModule("CACHED-SOLUTION", null, 0)));
      Logic.SYM_LOGIC_DEFRELATION = ((Symbol)(Stella.internRigidSymbolWrtModule("DEFRELATION", null, 0)));
      Logic.SYM_STELLA_THING = ((Symbol)(Stella.internRigidSymbolWrtModule("THING", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.SYM_LOGIC_DEFRULE = ((Symbol)(Stella.internRigidSymbolWrtModule("DEFRULE", null, 0)));
      Logic.SYM_LOGIC_pY = ((Symbol)(Stella.internRigidSymbolWrtModule("?Y", null, 0)));
      Logic.SGT_STELLA_NUMBER_WRAPPER = ((Surrogate)(Stella.internRigidSymbolWrtModule("NUMBER-WRAPPER", Stella.getStellaModule("/STELLA", true), 1)));
      Logic.SYM_STELLA_ge = ((Symbol)(Stella.internRigidSymbolWrtModule(">=", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.SYM_STELLA_el = ((Symbol)(Stella.internRigidSymbolWrtModule("=<", Stella.getStellaModule("/STELLA", true), 0)));
      Logic.KWD_IN = ((Keyword)(Stella.internRigidSymbolWrtModule("IN", null, 2)));
      Logic.SYM_LOGIC_STARTUP_MACHINE_LEARNING = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-MACHINE-LEARNING", null, 0)));
    }
  }

  public static void startupMachineLearning() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupMachineLearning.helpStartupMachineLearning1();
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Logic.$TRAINING_EXAMPLES$ = List.newList();
          Logic.$TESTING_EXAMPLES$ = List.newList();
          Logic.$CLOSED_WORLD_TRAINING_EXAMPLES$ = true;
          Logic.$DROP_FUNCTION_VALUESp$ = true;
          Logic.$TABOO_OPERATORS$ = List.newList();
        }
        if (Stella.currentStartupTimePhaseP(5)) {
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("TRAINING-EXAMPLE", "(DEFCLASS TRAINING-EXAMPLE (STANDARD-OBJECT) :DOCUMENTATION \"A single example of a proposition paired with the score\n  that should be returned and the module it should be evaluated in.\" :SLOTS ((QUERY :TYPE CONS) (CONCEPT :TYPE SYMBOL) (NAME :TYPE SYMBOL) (SCORE :TYPE PARTIAL-MATCH-SCORE) (MODULE :TYPE MODULE) (INPUT-FEATURES :TYPE LIST) (INPUT :TYPE VECTOR) (FACTS :TYPE (CONS OF CONS)) (NN-HIDDEN :TYPE (VECTOR OF FLOAT-WRAPPER)) (OUTPUT :TYPE OBJECT) (TEMP :TYPE FLOAT) (CACHED-SOLUTION :TYPE OBJECT) (TIMESTAMP :TYPE TIMESTAMP)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.TrainingExample", "newTrainingExample", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.TrainingExample", "accessTrainingExampleSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.TrainingExample"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("SET-CLOSED-WORLD-TRAINING-EXAMPLES", "(DEFUN SET-CLOSED-WORLD-TRAINING-EXAMPLES ((B BOOLEAN)) :COMMAND? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "setClosedWorldTrainingExamples", new java.lang.Class [] {java.lang.Boolean.TYPE}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "setClosedWorldTrainingExamplesEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("PRINT-TRAINING-EXAMPLE", "(DEFUN PRINT-TRAINING-EXAMPLE ((EXAMPLE TRAINING-EXAMPLE)))", Native.find_java_method("edu.isi.powerloom.logic.TrainingExample", "printTrainingExample", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.TrainingExample")}), null);
          Stella.defineFunctionObject("ADD-TRAINING-EXAMPLE", "(DEFUN ADD-TRAINING-EXAMPLE ((FORM CONS) (SCORE PARTIAL-MATCH-SCORE)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE :DOCUMENTATION \"Add a query and score pair to the master list of \n  training examples\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "addTrainingExample", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), java.lang.Double.TYPE}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "addTrainingExampleEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("ADD-TRAINING-EXAMPLE-IN-MODULE", "(DEFUN ADD-TRAINING-EXAMPLE-IN-MODULE ((FORM CONS) (SCORE PARTIAL-MATCH-SCORE) (MODULE SYMBOL)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "addTrainingExampleInModule", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), java.lang.Double.TYPE, Native.find_java_class("edu.isi.stella.Symbol")}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "addTrainingExampleInModuleEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("ADD-TESTING-EXAMPLE", "(DEFUN ADD-TESTING-EXAMPLE ((FORM CONS) (SCORE PARTIAL-MATCH-SCORE)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE :DOCUMENTATION \"Add a query and score pair to the master list of \n  testing examples\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "addTestingExample", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), java.lang.Double.TYPE}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "addTestingExampleEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("CLEAR-TRAINING-EXAMPLES", "(DEFUN CLEAR-TRAINING-EXAMPLES () :COMMAND? TRUE :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "clearTrainingExamples", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("SHUFFLE-LIST", "(DEFUN SHUFFLE-LIST ((CARDS LIST)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "shuffleList", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.List")}), null);
          Stella.defineFunctionObject("SHUFFLE-VECTOR", "(DEFUN SHUFFLE-VECTOR ((CARDS VECTOR)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "shuffleVector", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Vector")}), null);
          Stella.defineFunctionObject("SAVE-TRAINING-EXAMPLES", "(DEFUN SAVE-TRAINING-EXAMPLES () :COMMAND? TRUE :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "saveTrainingExamples", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("CREATE-PROPOSITIONAL-TRAINING-EXAMPLES", "(DEFUN (CREATE-PROPOSITIONAL-TRAINING-EXAMPLES INTEGER) ((EXAMPLES (LIST OF TRAINING-EXAMPLE)) (NAME-FILE OUTPUT-FILE-STREAM) (DATA-FILE OUTPUT-FILE-STREAM)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "createPropositionalTrainingExamples", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.List"), Native.find_java_class("edu.isi.stella.OutputFileStream"), Native.find_java_class("edu.isi.stella.OutputFileStream")}), null);
          Stella.defineFunctionObject("FILL-IN-EXAMPLE-OUTPUTS", "(DEFUN FILL-IN-EXAMPLE-OUTPUTS ((EXAMPLES (LIST OF TRAINING-EXAMPLE)) (SLOT-NAME SYMBOL)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "fillInExampleOutputs", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.List"), Native.find_java_class("edu.isi.stella.Symbol")}), null);
          Stella.defineFunctionObject("DETECT-NOISE-IN-TRAINING-EXAMPLES", "(DEFUN DETECT-NOISE-IN-TRAINING-EXAMPLES ((EXAMPLES (LIST OF TRAINING-EXAMPLE))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "detectNoiseInTrainingExamples", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.List")}), null);
          Stella.defineFunctionObject("GET-CLASSIFICATION-RELATIONS", "(DEFUN (GET-CLASSIFICATION-RELATIONS (LIST OF PROPOSITION)) ((CONS-QUERY CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getClassificationRelations", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("CREATE-INPUT-SIGNATURE", "(DEFUN (CREATE-INPUT-SIGNATURE (VECTOR OF INTEGER-WRAPPER)) ((CONS-QUERY CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "createInputSignature", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("GENERATE-CLASSIFICATION-RULE", "(DEFUN GENERATE-CLASSIFICATION-RULE ((INSTANCES (VECTOR OF LOGIC-OBJECT)) (CONCEPT-NAME SYMBOL) (CLASS-NAME SYMBOL) (BUILD-RULE? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "generateClassificationRule", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Vector"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Symbol"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("BUILD-CLASSIFICATION-RULE", "(DEFUN BUILD-CLASSIFICATION-RULE ((KIND SYMBOL) (CLASS-NAME SYMBOL)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "buildClassificationRule", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Symbol")}), null);
          Stella.defineFunctionObject("OLD-GENERATE-CLASSIFICATION-TRAINING-EXAMPLES", "(DEFUN (OLD-GENERATE-CLASSIFICATION-TRAINING-EXAMPLES INTEGER) ((INSTANCES (VECTOR OF LOGIC-OBJECT)) (CONCEPT SURROGATE)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "oldGenerateClassificationTrainingExamples", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Vector"), Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("TEST-DOMAIN-THEORY", "(DEFUN TEST-DOMAIN-THEORY ((RELATION-NAME SYMBOL) (CLASS-NAME SYMBOL)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "testDomainTheory", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Symbol")}), null);
          Stella.defineFunctionObject("TEST-THEORY-OVER-EXAMPLES", "(DEFUN (TEST-THEORY-OVER-EXAMPLES FLOAT) ((EXAMPLES (LIST OF TRAINING-EXAMPLE))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "testTheoryOverExamples", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.List")}), null);
          Stella.defineFunctionObject("GENERATE-TRAINING-EXAMPLES", "(DEFUN (GENERATE-TRAINING-EXAMPLES INTEGER) ((INSTANCES (VECTOR OF LOGIC-OBJECT)) (CONCEPT SURROGATE)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "generateTrainingExamples", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Vector"), Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("GENERATE-CLASSIFICATION-TRAINING-EXAMPLES", "(DEFUN (GENERATE-CLASSIFICATION-TRAINING-EXAMPLES INTEGER) ((INSTANCES (VECTOR OF LOGIC-OBJECT)) (CONCEPT SURROGATE) (CREATE-SIGNATURE? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "generateClassificationTrainingExamples", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Vector"), Native.find_java_class("edu.isi.stella.Surrogate"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("GENERATE-REGRESSION-RULE-WO-SLOT", "(DEFUN GENERATE-REGRESSION-RULE-WO-SLOT ((CASES (VECTOR OF LOGIC-OBJECT)) (SLOT-NAME SYMBOL) (CLASS-NAME SYMBOL) (REALLY-BUILD-RULE BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "generateRegressionRuleWoSlot", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Vector"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Symbol"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("GENERATE-REGRESSION-TRAINING-EXAMPLES", "(DEFUN (GENERATE-REGRESSION-TRAINING-EXAMPLES INTEGER) ((INSTANCES (VECTOR OF LOGIC-OBJECT)) (SLOT SURROGATE)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "generateRegressionTrainingExamples", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Vector"), Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("APPROXIMATE", "(DEFUN (APPROXIMATE FLOAT) ((INST-NAME SYMBOL) (SLOT-NAME SYMBOL)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "approximate", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Symbol")}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "approximateEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("GENERATE-SLOT-APPROXIMATION", "(DEFUN (GENERATE-SLOT-APPROXIMATION FLOAT) ((INST-NAME SYMBOL) (SLOT SURROGATE)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "generateSlotApproximation", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("FLOAT-FUNCTION?", "(DEFUN (FLOAT-FUNCTION? BOOLEAN) ((RELATION SURROGATE)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "floatFunctionP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("SET-STRUCTURE-DEPTH", "(DEFUN SET-STRUCTURE-DEPTH ((D INTEGER)) :COMMAND? TRUE :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "setStructureDepth", new java.lang.Class [] {java.lang.Integer.TYPE}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "setStructureDepthEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("ADD-TABOO-OPERATORS", "(DEFUN ADD-TABOO-OPERATORS ((S SYMBOL)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "addTabooOperators", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol")}), null);
          Stella.defineFunctionObject("GET-ASSERTION-STRUCTURE", "(DEFUN (GET-ASSERTION-STRUCTURE (LIST OF CONS)) ((INST SYMBOL) (DEPTH INTEGER)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getAssertionStructure", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), java.lang.Integer.TYPE}), null);
          Stella.defineFunctionObject("HELP-GET-ASSERTION-STRUCTURE", "(DEFUN (HELP-GET-ASSERTION-STRUCTURE (LIST OF CONS)) ((INST SYMBOL) (DEPTH INTEGER)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "helpGetAssertionStructure", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), java.lang.Integer.TYPE}), null);
          Stella.defineFunctionObject("COLLECT-FACTS-IN-EXAMPLES", "(DEFUN COLLECT-FACTS-IN-EXAMPLES ((EXAMPLES (LIST OF TRAINING-EXAMPLE))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "collectFactsInExamples", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.List")}), null);
          Stella.defineFunctionObject("OLD-RECURSIVE-BUILD-ANTECEDENT", "(DEFUN (OLD-RECURSIVE-BUILD-ANTECEDENT CONS) ((INST SYMBOL) (DEPTH INTEGER)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "oldRecursiveBuildAntecedent", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), java.lang.Integer.TYPE}), null);
          Stella.defineFunctionObject("GET-ARGUMENT-BINDING", "(DEFUN (GET-ARGUMENT-BINDING OBJECT) ((ARG OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getArgumentBinding", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("CONSIFY-ARGUMENT", "(DEFUN (CONSIFY-ARGUMENT OBJECT) ((ARG OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "consifyArgument", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("PROPOSITION-TO-CONS", "(DEFUN (PROPOSITION-TO-CONS CONS) ((PROP PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "propositionToCons", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("THINGIFY-UNTYPED-INSTANCES", "(DEFUN THINGIFY-UNTYPED-INSTANCES () :COMMAND? TRUE :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "thingifyUntypedInstances", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("PRINT-FACTS", "(DEFUN PRINT-FACTS ((INSTANCEREF OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "printFacts", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("TRANSLATE-LEARNING", "(DEFUN TRANSLATE-LEARNING () :COMMAND? TRUE :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "translateLearning", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("STARTUP-MACHINE-LEARNING", "(DEFUN STARTUP-MACHINE-LEARNING () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupMachineLearning", "startupMachineLearning", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_MACHINE_LEARNING);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("_Startup-Machine-Learning"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *TRAINING-EXAMPLES* (LIST OF TRAINING-EXAMPLE) (NEW LIST))");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *TESTING-EXAMPLES* (LIST OF TRAINING-EXAMPLE) (NEW LIST))");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CLOSED-WORLD-TRAINING-EXAMPLES* BOOLEAN TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *MAX-STRUCTURE-DEPTH* INTEGER 3)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DROP-FUNCTION-VALUES?* BOOLEAN TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *TABOO-OPERATORS* (LIST OF SURROGATE) (NEW (LIST OF SURROGATE)))");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
