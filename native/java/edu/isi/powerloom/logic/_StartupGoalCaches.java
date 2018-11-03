//  -*- Mode: Java -*-
//
// _StartupGoalCaches.java

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

public class _StartupGoalCaches {
  static void helpStartupGoalCaches1() {
    {
      Logic.SGT_LOGIC_GOAL_CACHE = ((Surrogate)(Stella.internRigidSymbolWrtModule("GOAL-CACHE", null, 1)));
      Logic.SYM_LOGIC_CACHED_BINDINGS = ((Symbol)(Stella.internRigidSymbolWrtModule("CACHED-BINDINGS", null, 0)));
      Logic.SYM_LOGIC_CACHE_CONTEXT = ((Symbol)(Stella.internRigidSymbolWrtModule("CACHE-CONTEXT", null, 0)));
      Logic.SYM_LOGIC_GOAL_CACHE_TABLE = ((Symbol)(Stella.internRigidSymbolWrtModule("GOAL-CACHE-TABLE", null, 0)));
      Logic.SYM_LOGIC_NEGATED_GOAL_CACHE_TABLE = ((Symbol)(Stella.internRigidSymbolWrtModule("NEGATED-GOAL-CACHE-TABLE", null, 0)));
      Logic.SGT_LOGIC_ATOMIC_GOAL_CACHE = ((Surrogate)(Stella.internRigidSymbolWrtModule("ATOMIC-GOAL-CACHE", null, 1)));
      Logic.SYM_LOGIC_GOAL_CONTEXT = ((Symbol)(Stella.internRigidSymbolWrtModule("GOAL-CONTEXT", null, 0)));
      Logic.SYM_LOGIC_PREVIOUS = ((Symbol)(Stella.internRigidSymbolWrtModule("PREVIOUS", null, 0)));
      Logic.SYM_LOGIC_GOAL_CACHE_LIST = ((Symbol)(Stella.internRigidSymbolWrtModule("GOAL-CACHE-LIST", null, 0)));
      Logic.KWD_GOAL_INSTANTIATES_CACHE = ((Keyword)(Stella.internRigidSymbolWrtModule("GOAL-INSTANTIATES-CACHE", null, 2)));
      Logic.KWD_CACHE_INSTANTIATES_GOAL = ((Keyword)(Stella.internRigidSymbolWrtModule("CACHE-INSTANTIATES-GOAL", null, 2)));
      Logic.SGT_PL_KERNEL_KB_FRAME_PREDICATE = ((Surrogate)(Stella.internRigidSymbolWrtModule("FRAME-PREDICATE", Stella.getStellaModule("/PL-KERNEL-KB", true), 1)));
      Logic.SYM_LOGIC_CHECK_FOR_CACHED_GOALSp = ((Symbol)(Stella.internRigidSymbolWrtModule("CHECK-FOR-CACHED-GOALS?", null, 0)));
      Logic.KWD_SUCCESS = ((Keyword)(Stella.internRigidSymbolWrtModule("SUCCESS", null, 2)));
      Logic.SGT_LOGIC_ATOMIC_GOAL_CACHE_ITERATOR = ((Surrogate)(Stella.internRigidSymbolWrtModule("ATOMIC-GOAL-CACHE-ITERATOR", null, 1)));
      Logic.SYM_LOGIC_GOAL = ((Symbol)(Stella.internRigidSymbolWrtModule("GOAL", null, 0)));
      Logic.SYM_LOGIC_CACHE_LIST = ((Symbol)(Stella.internRigidSymbolWrtModule("CACHE-LIST", null, 0)));
      Logic.SYM_LOGIC_STARTUP_GOAL_CACHES = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-GOAL-CACHES", null, 0)));
    }
  }

  public static void startupGoalCaches() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupGoalCaches.helpStartupGoalCaches1();
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Logic.$CACHE_SUCCEEDED_GOALSp$ = true;
          Logic.$CACHE_FAILED_GOALSp$ = true;
          Logic.$SUCCEEDED_GOALS_CACHE$ = Vector.newVector(1541);
          Logic.$FAILED_GOALS_CACHE$ = Vector.newVector(1541);
          Logic.$UNIFICATION_VECTOR_1$.setDefaultValue(Vector.newVector(10));
          Logic.$UNIFICATION_VECTOR_2$.setDefaultValue(Vector.newVector(10));
        }
        if (Stella.currentStartupTimePhaseP(5)) {
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("GOAL-CACHE", "(DEFCLASS GOAL-CACHE (STANDARD-OBJECT) :DOCUMENTATION \"Cache of output bindings derived for a particular goal\nand set of input bindings.\" :SLOTS ((CACHED-BINDINGS :TYPE (LIST OF GOAL-BINDINGS) :ALLOCATION :EMBEDDED) (TIMESTAMP :TYPE TIMESTAMP) (PROPOSITION :TYPE PROPOSITION) (REVERSE-POLARITY? :TYPE BOOLEAN) (CACHE-CONTEXT :TYPE CONTEXT)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.GoalCache", "newGoalCache", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.GoalCache", "accessGoalCacheSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.GoalCache"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          Stella.defineStellaTypeFromStringifiedSource("(DEFTYPE GOAL-CACHE-TABLE (KEY-VALUE-LIST OF CONTEXT GOAL-CACHE))");
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("ATOMIC-GOAL-CACHE", "(DEFCLASS ATOMIC-GOAL-CACHE (STANDARD-OBJECT) :DOCUMENTATION \"Cache data structure to store the result of proving an atomic\nand possibly open `proposition' relative to a set of variable `bindings'.\" :SLOTS ((GOAL-CONTEXT :TYPE CONTEXT) (TIMESTAMP :TYPE TIMESTAMP) (TRUTH-VALUE :TYPE TRUTH-VALUE) (REVERSE-POLARITY? :TYPE BOOLEAN) (PROPOSITION :TYPE PROPOSITION) (BINDINGS :TYPE GOAL-BINDINGS) (JUSTIFICATION :TYPE JUSTIFICATION) (POSITIVE-SCORE :TYPE PARTIAL-MATCH-SCORE) (NEGATIVE-SCORE :TYPE PARTIAL-MATCH-SCORE) (PREVIOUS :TYPE ATOMIC-GOAL-CACHE) (NEXT :TYPE ATOMIC-GOAL-CACHE)) :PRINT-FORM (PRINT-ATOMIC-GOAL-CACHE SELF STREAM))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.AtomicGoalCache", "newAtomicGoalCache", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.AtomicGoalCache", "accessAtomicGoalCacheSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.AtomicGoalCache"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("ATOMIC-GOAL-CACHE-ITERATOR", "(DEFCLASS ATOMIC-GOAL-CACHE-ITERATOR (ITERATOR) :PARAMETERS ((ANY-VALUE :TYPE ATOMIC-GOAL-CACHE)) :SLOTS ((GOAL :TYPE CONTROL-FRAME) (CACHE-LIST :TYPE ATOMIC-GOAL-CACHE)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.AtomicGoalCacheIterator", "newAtomicGoalCacheIterator", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.logic.AtomicGoalCacheIterator", "accessAtomicGoalCacheIteratorSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.AtomicGoalCacheIterator"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("TRACE-GOAL-CACHE", "(DEFUN TRACE-GOAL-CACHE ((STRING STRING) (FRAME CONTROL-FRAME)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "traceGoalCache", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.powerloom.logic.ControlFrame")}), null);
          Stella.defineFunctionObject("REMOVE-OBSOLETE-GOAL-CACHES", "(DEFUN REMOVE-OBSOLETE-GOAL-CACHES ((TABLE (KEY-VALUE-LIST OF CONTEXT GOAL-CACHE))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "removeObsoleteGoalCaches", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.KeyValueList")}), null);
          Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION GOAL-CACHE-TABLE :TYPE GOAL-CACHE-TABLE :DOCUMENTATION \"Allows attachment of goal caches to classes or slots.\" :ALLOCATION :DYNAMIC)");
          Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION NEGATED-GOAL-CACHE-TABLE :TYPE GOAL-CACHE-TABLE :DOCUMENTATION \"Allows attachment of goal caches to classes or slots.\" :ALLOCATION :DYNAMIC)");
          Stella.defineFunctionObject("YIELD-GOAL-BINDINGS", "(DEFUN (YIELD-GOAL-BINDINGS GOAL-BINDINGS) ((GOAL PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "yieldGoalBindings", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("FIND-GOAL-CACHE-TABLE", "(DEFUN (FIND-GOAL-CACHE-TABLE GOAL-CACHE-TABLE) ((GOAL PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "findGoalCacheTable", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("CREATE-GOAL-CACHE?", "(DEFUN (CREATE-GOAL-CACHE? BOOLEAN) ((FRAME CONTROL-FRAME)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "createGoalCacheP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame")}), null);
          Stella.defineFunctionObject("LOOKUP-GOAL-CACHE", "(DEFUN (LOOKUP-GOAL-CACHE GOAL-CACHE) ((TABLE GOAL-CACHE-TABLE)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "lookupGoalCache", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.KeyValueList")}), null);
          Stella.defineFunctionObject("FIND-GOAL-CACHE", "(DEFUN (FIND-GOAL-CACHE GOAL-CACHE) ((FRAME CONTROL-FRAME)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "findGoalCache", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame")}), null);
          Stella.defineFunctionObject("UPDATE-GOAL-CACHE", "(DEFUN UPDATE-GOAL-CACHE ((FRAME CONTROL-FRAME) (SUCCESS? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "updateGoalCache", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("YIELD-RELATIVE-GOAL-BINDINGS", "(DEFUN (YIELD-RELATIVE-GOAL-BINDINGS GOAL-BINDINGS) ((FRAME CONTROL-FRAME)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "yieldRelativeGoalBindings", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame")}), null);
          Stella.defineFunctionObject("CONTINUE-CACHED-BINDINGS-PROOF", "(DEFUN (CONTINUE-CACHED-BINDINGS-PROOF KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "continueCachedBindingsProof", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("TOP-LEVEL-QUERY-CONTEXT?", "(DEFUN (TOP-LEVEL-QUERY-CONTEXT? BOOLEAN) ((SELF CONTEXT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "topLevelQueryContextP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context")}), null);
          Stella.defineFunctionObject("CACHE-QUERY-RESULTS?", "(DEFUN (CACHE-QUERY-RESULTS? BOOLEAN) () :GLOBALLY-INLINE? TRUE (RETURN (AND (OR *CACHE-SUCCEEDED-GOALS?* *CACHE-FAILED-GOALS?*) (EQL? *DUPLICATE-SUBGOAL-STRATEGY* :DUPLICATE-GOALS) (NOT (PARTIAL-MATCH-MODE?)))))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "cacheQueryResultsP", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("TOGGLE-GOAL-CACHING", "(DEFUN (TOGGLE-GOAL-CACHING STRING) ())", Native.find_java_method("edu.isi.powerloom.logic.Logic", "toggleGoalCaching", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("PRINT-ATOMIC-GOAL-CACHE", "(DEFUN PRINT-ATOMIC-GOAL-CACHE ((SELF ATOMIC-GOAL-CACHE) (STREAM NATIVE-OUTPUT-STREAM)))", Native.find_java_method("edu.isi.powerloom.logic.AtomicGoalCache", "printAtomicGoalCache", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.AtomicGoalCache"), Native.find_java_class("java.io.PrintStream")}), null);
          Stella.defineFunctionObject("CLEAR-QUERY-RESULTS-CACHE", "(DEFUN CLEAR-QUERY-RESULTS-CACHE ())", Native.find_java_method("edu.isi.powerloom.logic.Logic", "clearQueryResultsCache", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("PRINT-QUERY-RESULTS-CACHE", "(DEFUN PRINT-QUERY-RESULTS-CACHE ((LIMIT INTEGER)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "printQueryResultsCache", new java.lang.Class [] {java.lang.Integer.TYPE}), null);
          Stella.defineFunctionObject("SUCCEEDED-GOAL-INDEX", "(DEFUN (SUCCEEDED-GOAL-INDEX INTEGER) ((FRAME CONTROL-FRAME)) :GLOBALLY-INLINE? TRUE (RETURN (HASHMOD (GOAL-HASH-CODE FRAME) 1541)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "succeededGoalIndex", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame")}), null);
          Stella.defineFunctionObject("FAILED-GOAL-INDEX", "(DEFUN (FAILED-GOAL-INDEX INTEGER) ((FRAME CONTROL-FRAME)) :GLOBALLY-INLINE? TRUE (RETURN (HASHMOD (GOAL-HASH-CODE FRAME) 1541)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "failedGoalIndex", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame")}), null);
          Stella.defineFunctionObject("GOAL-HASH-CODE", "(DEFUN (GOAL-HASH-CODE INTEGER) ((FRAME CONTROL-FRAME)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "goalHashCode", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame")}), null);
          Stella.defineFunctionObject("HASH-UNBOUND-GOAL-VARIABLE", "(DEFUN (HASH-UNBOUND-GOAL-VARIABLE INTEGER) ((VAR PATTERN-VARIABLE) (ARGUMENTS VECTOR) (CODE INTEGER)))", Native.find_java_method("edu.isi.powerloom.logic.PatternVariable", "hashUnboundGoalVariable", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.PatternVariable"), Native.find_java_class("edu.isi.stella.Vector"), java.lang.Integer.TYPE}), null);
          Stella.defineFunctionObject("HASH-GOAL-ARGUMENT", "(DEFUN (HASH-GOAL-ARGUMENT INTEGER) ((ARG OBJECT) (CODE INTEGER)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "hashGoalArgument", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Integer.TYPE}), null);
          Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION GOAL-CACHE-LIST :TYPE ATOMIC-GOAL-CACHE :DOCUMENTATION \"Points at the beginning of a chain of cached values\nfor some named description\" :ALLOCATION :DYNAMIC)");
          Stella.defineFunctionObject("CACHED-GOAL-OPERATOR", "(DEFUN (CACHED-GOAL-OPERATOR SURROGATE) ((GOAL PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "cachedGoalOperator", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("GET-GOAL-CACHE-LIST", "(DEFUN (GET-GOAL-CACHE-LIST ATOMIC-GOAL-CACHE) ((GOAL PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "getGoalCacheList", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("SET-GOAL-CACHE-LIST", "(DEFUN (SET-GOAL-CACHE-LIST ATOMIC-GOAL-CACHE) ((GOAL PROPOSITION) (FIRSTCACHE ATOMIC-GOAL-CACHE)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "setGoalCacheList", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.AtomicGoalCache")}), null);
          Stella.defineFunctionObject("CREATE-ATOMIC-GOAL-CACHE", "(DEFUN (CREATE-ATOMIC-GOAL-CACHE ATOMIC-GOAL-CACHE) ((FRAME CONTROL-FRAME) (CACHE ATOMIC-GOAL-CACHE) (SUCCESS? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "createAtomicGoalCache", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.powerloom.logic.AtomicGoalCache"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("CACHE-MATCHES-GOAL?", "(DEFUN (CACHE-MATCHES-GOAL? BOOLEAN) ((CACHE ATOMIC-GOAL-CACHE) (GOAL CONTROL-FRAME) (SUCCESS? BOOLEAN) (MODE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.AtomicGoalCache", "cacheMatchesGoalP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.AtomicGoalCache"), Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), java.lang.Boolean.TYPE, Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("GOAL-INSTANTIATES-CACHE?", "(DEFUN (GOAL-INSTANTIATES-CACHE? BOOLEAN) ((GOAL CONTROL-FRAME) (CACHE ATOMIC-GOAL-CACHE) (SUCCESS? BOOLEAN)) :GLOBALLY-INLINE? TRUE (RETURN (CACHE-MATCHES-GOAL? CACHE GOAL SUCCESS? :GOAL-INSTANTIATES-CACHE)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "goalInstantiatesCacheP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.powerloom.logic.AtomicGoalCache"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("CACHE-INSTANTIATES-GOAL?", "(DEFUN (CACHE-INSTANTIATES-GOAL? BOOLEAN) ((CACHE ATOMIC-GOAL-CACHE) (GOAL CONTROL-FRAME) (SUCCESS? BOOLEAN)) :GLOBALLY-INLINE? TRUE (RETURN (CACHE-MATCHES-GOAL? CACHE GOAL SUCCESS? :CACHE-INSTANTIATES-GOAL)))", Native.find_java_method("edu.isi.powerloom.logic.AtomicGoalCache", "cacheInstantiatesGoalP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.AtomicGoalCache"), Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("DONT-CACHE-GOAL-FAILURE-BETWEEN-FRAMES", "(DEFUN DONT-CACHE-GOAL-FAILURE-BETWEEN-FRAMES ((TOPFRAME CONTROL-FRAME) (BOTTOMFRAME CONTROL-FRAME)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "dontCacheGoalFailureBetweenFrames", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.powerloom.logic.ControlFrame")}), null);
          Stella.defineFunctionObject("CACHE-GOAL", "(DEFUN CACHE-GOAL ((FRAME CONTROL-FRAME) (SUCCESS? BOOLEAN) (KEEPFRAME? BOOLEAN) (CLOCKTICKS INTEGER)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "cacheGoal", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), java.lang.Boolean.TYPE, java.lang.Boolean.TYPE, java.lang.Integer.TYPE}), null);
          Stella.defineFunctionObject("FIND-CACHED-GOAL", "(DEFUN (FIND-CACHED-GOAL ATOMIC-GOAL-CACHE) ((FRAME CONTROL-FRAME) (SUCCESSORFAILURE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "findCachedGoal", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("ALL-CACHED-PROPOSITIONS", "(DEFUN (ALL-CACHED-PROPOSITIONS ATOMIC-GOAL-CACHE-ITERATOR) ((GOAL CONTROL-FRAME)))", Native.find_java_method("edu.isi.powerloom.logic.ControlFrame", "allCachedPropositions", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame")}), null);
          Stella.defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF ATOMIC-GOAL-CACHE-ITERATOR)))", Native.find_java_method("edu.isi.powerloom.logic.AtomicGoalCacheIterator", "nextP", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("STARTUP-GOAL-CACHES", "(DEFUN STARTUP-GOAL-CACHES () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupGoalCaches", "startupGoalCaches", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_GOAL_CACHES);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("_Startup-Goal-Caches"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CACHE-SUCCEEDED-GOALS?* BOOLEAN TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CACHE-FAILED-GOALS?* BOOLEAN TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CACHE-GOAL-QUANTUM* INTEGER 5 :DOCUMENTATION \"Only goals whose success or failure took at least this\nnumber of query clock ticks will be cached.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SUCCEEDED-GOALS-CACHE* (VECTOR OF ATOMIC-GOAL-CACHE) (NEW VECTOR :ARRAY-SIZE 1541))");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *FAILED-GOALS-CACHE* (VECTOR OF ATOMIC-GOAL-CACHE) (NEW VECTOR :ARRAY-SIZE 1541))");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *UNIFICATION-VECTOR-1* VECTOR (NEW VECTOR :ARRAY-SIZE 10))");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *UNIFICATION-VECTOR-2* VECTOR (NEW VECTOR :ARRAY-SIZE 10))");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
