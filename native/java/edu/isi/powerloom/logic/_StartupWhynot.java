//  -*- Mode: Java -*-
//
// _StartupWhynot.java

/*--------------------------------------------------------------------------+
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
 +--------------------------------------------------------------------------*/

package edu.isi.powerloom.logic;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.stella.*;

public class _StartupWhynot {
  static void helpStartupWhynot1() {
    {
      Logic.SYM_LOGIC_UNKNOWN_GOAL_CUTOFF = ((Symbol)(Stella.internRigidSymbolWrtModule("UNKNOWN-GOAL-CUTOFF", null, 0)));
      Logic.SGT_LOGIC_WHYNOT_DEEP_PARTIAL_MATCH = ((Surrogate)(Stella.internRigidSymbolWrtModule("WHYNOT-DEEP-PARTIAL-MATCH", null, 1)));
      Logic.SGT_LOGIC_NUMBER_OF_FAILED_SUBGOALS_MEMO_TABLE_000 = ((Surrogate)(Stella.internRigidSymbolWrtModule("NUMBER-OF-FAILED-SUBGOALS-MEMO-TABLE-000", null, 1)));
      Logic.SYM_LOGIC_REAL_ALLOTTED_CLOCK_TICKS = ((Symbol)(Stella.internRigidSymbolWrtModule("REAL-ALLOTTED-CLOCK-TICKS", null, 0)));
      Logic.SGT_STELLA_CONS_ITERATOR = ((Surrogate)(Stella.internRigidSymbolWrtModule("CONS-ITERATOR", Stella.getStellaModule("/STELLA", Stella.TRUE), 1)));
      Logic.SGT_LOGIC_WHYNOT_PROOF_CLASS = ((Surrogate)(Stella.internRigidSymbolWrtModule("WHYNOT-PROOF-CLASS", null, 1)));
      Logic.SYM_LOGIC_REPRESENTATIVE = ((Symbol)(Stella.internRigidSymbolWrtModule("REPRESENTATIVE", null, 0)));
      Logic.SYM_LOGIC_DEVIATING_PATTERN = ((Symbol)(Stella.internRigidSymbolWrtModule("DEVIATING-PATTERN", null, 0)));
      Logic.SYM_LOGIC_DEVIATING_VARIABLE = ((Symbol)(Stella.internRigidSymbolWrtModule("DEVIATING-VARIABLE", null, 0)));
      Logic.SYM_LOGIC_DEVIATING_INSTANCES = ((Symbol)(Stella.internRigidSymbolWrtModule("DEVIATING-INSTANCES", null, 0)));
      Logic.SYM_LOGIC_THE_VARIABLE = ((Symbol)(Stella.internRigidSymbolWrtModule("THE-VARIABLE", null, 0)));
      Logic.KWD_WHYNOT = ((Keyword)(Stella.internRigidSymbolWrtModule("WHYNOT", null, 2)));
      Logic.KWD_JUSTIFICATIONS = ((Keyword)(Stella.internRigidSymbolWrtModule("JUSTIFICATIONS", null, 2)));
      Logic.SYM_LOGIC_STARTUP_WHYNOT = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-WHYNOT", null, 0)));
    }
  }

  public static void startupWhynot() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupWhynot.helpStartupWhynot1();
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Logic.$MAX_WHYNOT_PROOF_CLASS_DEVIATIONS$.setDefaultValue(new Integer(1));
        }
        if (Stella.currentStartupTimePhaseP(5)) {
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("WHYNOT-PARTIAL-MATCH", "(DEFCLASS WHYNOT-PARTIAL-MATCH (INCREMENTAL-PARTIAL-MATCH) :DOCUMENTATION \"Variant of :BASIC partial match strategy to support WHYNOT queries.\" :SLOTS ((UNKNOWN-GOAL-CUTOFF :TYPE INTEGER :INITIALLY NULL)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "newWhynotPartialMatch", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Keyword"), Native.find_java_class("edu.isi.powerloom.logic.ControlFrame")});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "accessWhynotPartialMatchSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.WhynotPartialMatch"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("WHYNOT-DEEP-PARTIAL-MATCH", "(DEFCLASS WHYNOT-DEEP-PARTIAL-MATCH (WHYNOT-PARTIAL-MATCH) :DOCUMENTATION \"Variant of WhyNot partial match geared towards deep proofs.\")");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.WhynotDeepPartialMatch", "newWhynotDeepPartialMatch", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Keyword"), Native.find_java_class("edu.isi.powerloom.logic.ControlFrame")});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("WHYNOT-PROOF-CLASS", "(DEFCLASS WHYNOT-PROOF-CLASS (SET) :DOCUMENTATION \"Set of equivalent WhyNot proofs that differ in at most one\nvariable binding all on the same `deviating-variable'.\" :PARAMETERS ((ANY-VALUE :TYPE JUSTIFICATION)) :SLOTS ((REPRESENTATIVE :TYPE JUSTIFICATION) (DEVIATING-PATTERN :TYPE JUSTIFICATION) (DEVIATING-VARIABLE :TYPE PATTERN-VARIABLE) (DEVIATING-INSTANCES :TYPE LIST :INITIALLY (NEW LIST))))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.WhynotProofClass", "newWhynotProofClass", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.WhynotProofClass", "accessWhynotProofClassSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.WhynotProofClass"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("ALTERNATIVE-BINDINGS-SET", "(DEFCLASS ALTERNATIVE-BINDINGS-SET (THING) :DOCUMENTATION \"Represents a set of alternative bindings collected for the pattern\nvariable `(the-variable self)'.\" :SLOTS ((THE-VARIABLE :TYPE PATTERN-VARIABLE) (BINDINGS :TYPE SET :INITIALLY (NEW SET)) (SURROGATE-VALUE-INVERSE :INITIALLY @ALTERNATIVE-BINDINGS-SET)) :PRINT-FORM (PRINT-STREAM STREAM (STRING-DOWNCASE (GET-SKOLEM-PRINT-NAME (THE-VARIABLE SELF)))))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.AlternativeBindingsSet", "newAlternativeBindingsSet", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.AlternativeBindingsSet", "accessAlternativeBindingsSetSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.AlternativeBindingsSet"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("WHYNOT-PARTIAL-MATCH-MODE?", "(DEFUN (WHYNOT-PARTIAL-MATCH-MODE? BOOLEAN) () :GLOBALLY-INLINE? TRUE (RETURN (AND (PARTIAL-MATCH-MODE?) (ISA? (PARTIAL-MATCH-STRATEGY *QUERYITERATOR*) @WHYNOT-PARTIAL-MATCH))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "whynotPartialMatchModeP", new java.lang.Class [] {}), null);
          Stella.defineMethodObject("(DEFMETHOD (CREATE-PARTIAL-MATCH-FRAME WHYNOT-PARTIAL-MATCH) ((SELF WHYNOT-PARTIAL-MATCH) (FRAME CONTROL-FRAME) (KIND KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "createPartialMatchFrame", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD (CREATE-PARTIAL-MATCH-FRAME WHYNOT-DEEP-PARTIAL-MATCH) ((SELF WHYNOT-DEEP-PARTIAL-MATCH) (FRAME CONTROL-FRAME) (KIND KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotDeepPartialMatch", "createPartialMatchFrame", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD SET-DYNAMIC-CUTOFF ((SELF WHYNOT-PARTIAL-MATCH)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "setDynamicCutoff", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD (COMPUTE-UNKNOWN-GOAL-CUTOFF INTEGER) ((SELF WHYNOT-PARTIAL-MATCH)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "computeUnknownGoalCutoff", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD (NUMBER-OF-FAILED-SUBGOALS INTEGER) ((SELF WHYNOT-PARTIAL-MATCH)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "numberOfFailedSubgoals", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("COMPUTE-NUMBER-OF-FAILED-SUBGOALS", "(DEFUN (COMPUTE-NUMBER-OF-FAILED-SUBGOALS INTEGER) ((PROOF JUSTIFICATION)))", Native.find_java_method("edu.isi.powerloom.logic.Justification", "computeNumberOfFailedSubgoals", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification")}), null);
          Stella.defineMethodObject("(DEFMETHOD (CUTOFF-PARTIAL-MATCH? BOOLEAN) ((SELF WHYNOT-PARTIAL-MATCH) (TRACE? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "cutoffPartialMatchP", new java.lang.Class [] {java.lang.Boolean.TYPE}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("AUXILIARY-EQUIVALENCE-PROPOSITION?", "(DEFUN (AUXILIARY-EQUIVALENCE-PROPOSITION? BOOLEAN) ((PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "auxiliaryEquivalencePropositionP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineMethodObject("(DEFMETHOD (PROPOSITION-WEIGHT FLOAT) ((SELF WHYNOT-PARTIAL-MATCH) (PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "propositionWeight", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), ((java.lang.reflect.Method)(null)));
          Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT CONTROL-FRAME REAL-ALLOTTED-CLOCK-TICKS :TYPE INTEGER :ALLOCATION :DYNAMIC)");
          Stella.defineMethodObject("(DEFMETHOD (CONTINUE-PARTIAL-AND-PROOF KEYWORD) ((SELF WHYNOT-PARTIAL-MATCH) (FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "continuePartialAndProof", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("NUMBER-OF-REMAINING-ANTECEDENTS", "(DEFUN (NUMBER-OF-REMAINING-ANTECEDENTS INTEGER) ((ITERATOR ITERATOR)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "numberOfRemainingAntecedents", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Iterator")}), null);
          Stella.defineMethodObject("(DEFMETHOD (CHAINING-DEPTH-DEGRADATION FLOAT) ((SELF WHYNOT-PARTIAL-MATCH)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "chainingDepthDegradation", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD (CHAINING-DEPTH-DEGRADATION FLOAT) ((SELF WHYNOT-DEEP-PARTIAL-MATCH)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotDeepPartialMatch", "chainingDepthDegradation", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD (CONTINUE-PARTIAL-ANTECEDENTS-PROOF KEYWORD) ((SELF WHYNOT-PARTIAL-MATCH) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "continuePartialAntecedentsProof", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Keyword")}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD (MAX-UNCONSTRAINED-FANOUT FLOAT) ((SELF WHYNOT-PARTIAL-MATCH)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "maxUnconstrainedFanout", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD (MAX-UNCONSTRAINED-FANOUT FLOAT) ((SELF WHYNOT-DEEP-PARTIAL-MATCH)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotDeepPartialMatch", "maxUnconstrainedFanout", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD (SKIP-AND-CLAUSE? BOOLEAN) ((SELF WHYNOT-PARTIAL-MATCH) (FRAME CONTROL-FRAME) (FORBIDDENVARS (CONS OF PATTERN-VARIABLE))))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "skipAndClauseP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Cons")}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD INITIALIZE-PARTIAL-MATCH-STRATEGY ((SELF WHYNOT-PARTIAL-MATCH) (QUERY QUERY-ITERATOR)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "initializePartialMatchStrategy", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.QueryIterator")}), ((java.lang.reflect.Method)(null)));
          Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT CONTROL-FRAME ALL-JUSTIFICATIONS :TYPE (LIST OF JUSTIFICATION) :ALLOCATION :DYNAMIC)");
          Stella.defineMethodObject("(DEFMETHOD (COMPUTE-PARTIAL-TRUTH FLOAT) ((SELF WHYNOT-PARTIAL-MATCH) (QUERY QUERY-ITERATOR)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "computePartialTruth", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.QueryIterator")}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("BETTER-WHYNOT-PROOF?", "(DEFUN (BETTER-WHYNOT-PROOF? BOOLEAN) ((PROOF1 JUSTIFICATION) (PROOF2 JUSTIFICATION)))", Native.find_java_method("edu.isi.powerloom.logic.Justification", "betterWhynotProofP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification"), Native.find_java_class("edu.isi.powerloom.logic.Justification")}), null);
          Stella.defineFunctionObject("COMPUTE-PROOF-DEVIATION", "(DEFUN (COMPUTE-PROOF-DEVIATION INTEGER) ((PROOF1 JUSTIFICATION) (PROOF2 JUSTIFICATION) (MAXDEVIATIONS INTEGER) (DEVIATIONS (KEY-VALUE-LIST OF JUSTIFICATION JUSTIFICATION))))", Native.find_java_method("edu.isi.powerloom.logic.Justification", "computeProofDeviation", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification"), Native.find_java_class("edu.isi.powerloom.logic.Justification"), java.lang.Integer.TYPE, Native.find_java_class("edu.isi.stella.KeyValueList")}), null);
          Stella.defineFunctionObject("INSERT-WHYNOT-PROOF-TO-CLASS?", "(DEFUN (INSERT-WHYNOT-PROOF-TO-CLASS? BOOLEAN) ((CLASS WHYNOT-PROOF-CLASS) (PROOF JUSTIFICATION)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotProofClass", "insertWhynotProofToClassP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.WhynotProofClass"), Native.find_java_class("edu.isi.powerloom.logic.Justification")}), null);
          Stella.defineFunctionObject("INSERT-WHYNOT-PROOF", "(DEFUN (INSERT-WHYNOT-PROOF WHYNOT-PROOF-CLASS) ((CLASSES (LIST OF WHYNOT-PROOF-CLASS)) (PROOF JUSTIFICATION)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "insertWhynotProof", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.List"), Native.find_java_class("edu.isi.powerloom.logic.Justification")}), null);
          Stella.defineFunctionObject("BETTER-WHYNOT-PROOF-CLASS?", "(DEFUN (BETTER-WHYNOT-PROOF-CLASS? BOOLEAN) ((CLASS1 WHYNOT-PROOF-CLASS) (CLASS2 WHYNOT-PROOF-CLASS)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotProofClass", "betterWhynotProofClassP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.WhynotProofClass"), Native.find_java_class("edu.isi.powerloom.logic.WhynotProofClass")}), null);
          Stella.defineFunctionObject("ALTERNATIVE-BINDINGS-SET?", "(DEFUN (ALTERNATIVE-BINDINGS-SET? BOOLEAN) ((THING OBJECT)) :GLOBALLY-INLINE? TRUE (RETURN (AND (DEFINED? THING) (ISA? THING @ALTERNATIVE-BINDINGS-SET))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "alternativeBindingsSetP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("ALTERNATIVE-BINDINGS", "(DEFUN (ALTERNATIVE-BINDINGS SET) ((BINDINGSSET ALTERNATIVE-BINDINGS-SET)) :GLOBALLY-INLINE? TRUE (RETURN (BINDINGS BINDINGSSET)))", Native.find_java_method("edu.isi.powerloom.logic.AlternativeBindingsSet", "alternativeBindings", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.AlternativeBindingsSet")}), null);
          Stella.defineFunctionObject("POST-PROCESS-WHYNOT-PROOF-CLASSES", "(DEFUN POST-PROCESS-WHYNOT-PROOF-CLASSES ((CLASSES (LIST OF WHYNOT-PROOF-CLASS))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "postProcessWhynotProofClasses", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.List")}), null);
          Stella.defineFunctionObject("CUTOFF-SIMILAR-WHYNOT-PROOFS", "(DEFUN CUTOFF-SIMILAR-WHYNOT-PROOFS ((QUERY QUERY-ITERATOR)))", Native.find_java_method("edu.isi.powerloom.logic.QueryIterator", "cutoffSimilarWhynotProofs", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.QueryIterator")}), null);
          Stella.defineMethodObject("(DEFMETHOD (RETRIEVE-PARTIAL-SOLUTIONS QUERY-ITERATOR) ((SELF WHYNOT-PARTIAL-MATCH) (QUERY QUERY-ITERATOR)))", Native.find_java_method("edu.isi.powerloom.logic.WhynotPartialMatch", "retrievePartialSolutions", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.QueryIterator")}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("RETRIEVAL-PROOF-SOLUTION", "(DEFUN (RETRIEVAL-PROOF-SOLUTION CONS) ((PROOF JUSTIFICATION) (QUERY QUERY-ITERATOR)))", Native.find_java_method("edu.isi.powerloom.logic.Justification", "retrievalProofSolution", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification"), Native.find_java_class("edu.isi.powerloom.logic.QueryIterator")}), null);
          Stella.defineFunctionObject("COLLECT-FAILED-GOALS", "(DEFUN COLLECT-FAILED-GOALS ((PROOF JUSTIFICATION) (FAILURES (LIST OF JUSTIFICATION))))", Native.find_java_method("edu.isi.powerloom.logic.Justification", "collectFailedGoals", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification"), Native.find_java_class("edu.isi.stella.List")}), null);
          Stella.defineFunctionObject("DERIVE-JUSTIFIED-PARTIAL-QUERY", "(DEFUN (DERIVE-JUSTIFIED-PARTIAL-QUERY QUERY-ITERATOR) ((QUERY QUERY-ITERATOR)))", Native.find_java_method("edu.isi.powerloom.logic.QueryIterator", "deriveJustifiedPartialQuery", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.QueryIterator")}), null);
          Stella.defineFunctionObject("WHYNOT", "(DEFUN WHYNOT (|&REST| (ARGS OBJECT)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "whynot", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "whynotEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("EXPLAIN-WHYNOT", "(DEFUN EXPLAIN-WHYNOT ((LABEL STRING) (STYLE KEYWORD) (MAXDEPTH INTEGER) (SUMMARY? BOOLEAN) (STREAM OUTPUT-STREAM)) :DOCUMENTATION \"Programmer's interface to the WHYNOT function.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "explainWhynot", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Keyword"), java.lang.Integer.TYPE, java.lang.Boolean.TYPE, Native.find_java_class("edu.isi.stella.OutputStream")}), null);
          Stella.defineFunctionObject("PRINT-WHYNOT-JUSTIFICATION", "(DEFUN PRINT-WHYNOT-JUSTIFICATION ((JUSTIFICATION JUSTIFICATION) (STREAM OUTPUT-STREAM) (MAXDEPTH INTEGER) (STYLE KEYWORD) (SUMMARY? BOOLEAN)) :DOCUMENTATION \"Print a WHYNOT `justification' to `stream' according to\n`maxDepth' and `style'.  Print a summary only if `summary?' is TRUE.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Justification", "printWhynotJustification", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Justification"), Native.find_java_class("edu.isi.stella.OutputStream"), java.lang.Integer.TYPE, Native.find_java_class("edu.isi.stella.Keyword"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("GET-WHYNOT-JUSTIFICATIONS", "(DEFUN (GET-WHYNOT-JUSTIFICATIONS (LIST OF JUSTIFICATION)) ((QUERY QUERY-ITERATOR) (LABEL STRING) (MAPPING EXPLANATION-MAPPING)) :DOCUMENTATION \"Programmer's interface to WHYNOT function.  Derive\njustifications why `query' failed, or, if `label' was supplied as non-NULL,\nlookup its justification relative to `mapping' and return the result.\")", Native.find_java_method("edu.isi.powerloom.logic.QueryIterator", "getWhynotJustifications", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.QueryIterator"), Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.KeyValueList")}), null);
          Stella.defineFunctionObject("STARTUP-WHYNOT", "(DEFUN STARTUP-WHYNOT () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupWhynot", "startupWhynot", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_WHYNOT);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("_Startup-Whynot"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *MIN-CLOCK-TICKS-PER-WHYNOT-ANTECEDENT* INTEGER 5)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *MAX-WHYNOT-PROOF-CLASS-DEVIATIONS* INTEGER 1)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SIMILAR-WHYNOT-PROOF-CUTOFF* INTEGER 3)");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
