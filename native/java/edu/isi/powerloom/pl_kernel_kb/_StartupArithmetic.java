//  -*- Mode: Java -*-
//
// _StartupArithmetic.java

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

package edu.isi.powerloom.pl_kernel_kb;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.powerloom.logic.*;
import edu.isi.stella.*;

public class _StartupArithmetic {
  static void helpStartupArithmetic1() {
    {
      PlKernelKb.SGT_PL_KERNEL_KB_INTEGER_INTERVAL = ((Surrogate)(Stella.internRigidSymbolWrtModule("INTEGER-INTERVAL", null, 1)));
      PlKernelKb.SYM_PL_KERNEL_KB_INTERVAL_LOWER_BOUND = ((Symbol)(Stella.internRigidSymbolWrtModule("INTERVAL-LOWER-BOUND", null, 0)));
      PlKernelKb.SYM_PL_KERNEL_KB_INTERVAL_UPPER_BOUND = ((Symbol)(Stella.internRigidSymbolWrtModule("INTERVAL-UPPER-BOUND", null, 0)));
      PlKernelKb.SYM_STELLA_HOME_CONTEXT = ((Symbol)(Stella.internRigidSymbolWrtModule("HOME-CONTEXT", Stella.getStellaModule("/STELLA", true), 0)));
      PlKernelKb.SYM_PL_KERNEL_KB_INTERVAL_MEMBER = ((Symbol)(Stella.internRigidSymbolWrtModule("INTERVAL-MEMBER", null, 0)));
      PlKernelKb.SGT_PL_KERNEL_KB_INTEGER_INTERVAL_CACHE = ((Surrogate)(Stella.internRigidSymbolWrtModule("INTEGER-INTERVAL-CACHE", null, 1)));
      PlKernelKb.SYM_STELLA_LOWER_BOUND = ((Symbol)(Stella.internRigidSymbolWrtModule("LOWER-BOUND", Stella.getStellaModule("/STELLA", true), 0)));
      PlKernelKb.SYM_STELLA_UPPER_BOUND = ((Symbol)(Stella.internRigidSymbolWrtModule("UPPER-BOUND", Stella.getStellaModule("/STELLA", true), 0)));
      PlKernelKb.SGT_PL_KERNEL_KB_FLOAT_INTERVAL_CACHE = ((Surrogate)(Stella.internRigidSymbolWrtModule("FLOAT-INTERVAL-CACHE", null, 1)));
      PlKernelKb.SYM_PL_KERNEL_KB_STRICT_LOWER_BOUNDp = ((Symbol)(Stella.internRigidSymbolWrtModule("STRICT-LOWER-BOUND?", null, 0)));
      PlKernelKb.SYM_PL_KERNEL_KB_STRICT_UPPER_BOUNDp = ((Symbol)(Stella.internRigidSymbolWrtModule("STRICT-UPPER-BOUND?", null, 0)));
      PlKernelKb.SGT_PL_KERNEL_KB_INTERVAL_CACHE_OF = ((Surrogate)(Stella.internRigidSymbolWrtModule("INTERVAL-CACHE-OF", null, 1)));
      PlKernelKb.SGT_PL_KERNEL_KB_g = ((Surrogate)(Stella.internRigidSymbolWrtModule(">", null, 1)));
      PlKernelKb.SGT_PL_KERNEL_KB_l = ((Surrogate)(Stella.internRigidSymbolWrtModule("<", null, 1)));
      PlKernelKb.SGT_PL_KERNEL_KB_el = ((Surrogate)(Stella.internRigidSymbolWrtModule("=<", null, 1)));
      PlKernelKb.KWD_LOWER_BOUND = ((Keyword)(Stella.internRigidSymbolWrtModule("LOWER-BOUND", null, 2)));
      PlKernelKb.KWD_UPPER_BOUND = ((Keyword)(Stella.internRigidSymbolWrtModule("UPPER-BOUND", null, 2)));
      PlKernelKb.SYM_PL_KERNEL_KB_STARTUP_ARITHMETIC = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-ARITHMETIC", null, 0)));
    }
  }

  public static void startupArithmetic() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/PL-KERNEL-KB", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupArithmetic.helpStartupArithmetic1();
        }
        if (Stella.currentStartupTimePhaseP(5)) {
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("INTEGER-INTERVAL", "(DEFCLASS INTEGER-INTERVAL (THING) :DOCUMENTATION \"An interval of integers\" :SLOTS ((INTERVAL-LOWER-BOUND :TYPE INTEGER) (INTERVAL-UPPER-BOUND :TYPE INTEGER)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntegerInterval", "newIntegerInterval", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntegerInterval", "accessIntegerIntervalSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.pl_kernel_kb.IntegerInterval"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("INTERVAL-CACHE", "(DEFCLASS INTERVAL-CACHE (THING) :PUBLIC? TRUE :PUBLIC-SLOTS ((HOME-CONTEXT :TYPE CONTEXT) (INTERVAL-MEMBER :TYPE LOGIC-OBJECT)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntervalCache", "newIntervalCache", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntervalCache", "accessIntervalCacheSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.pl_kernel_kb.IntervalCache"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("INTEGER-INTERVAL-CACHE", "(DEFCLASS INTEGER-INTERVAL-CACHE (INTERVAL-CACHE) :PUBLIC? TRUE :PUBLIC-SLOTS ((LOWER-BOUND :TYPE INTEGER) (UPPER-BOUND :TYPE INTEGER)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|IIcache-of: \" (INTERVAL-MEMBER SELF) \" [\" (CHOOSE (DEFINED? (LOWER-BOUND SELF)) (INTEGER-TO-STRING (LOWER-BOUND SELF)) \"?\") \",\" (CHOOSE (DEFINED? (UPPER-BOUND SELF)) (INTEGER-TO-STRING (UPPER-BOUND SELF)) \"?\") \"]|\"))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntegerIntervalCache", "newIntegerIntervalCache", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntegerIntervalCache", "accessIntegerIntervalCacheSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.pl_kernel_kb.IntegerIntervalCache"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("FLOAT-INTERVAL-CACHE", "(DEFCLASS FLOAT-INTERVAL-CACHE (INTERVAL-CACHE) :PUBLIC? TRUE :PUBLIC-SLOTS ((LOWER-BOUND :TYPE FLOAT) (UPPER-BOUND :TYPE FLOAT) (STRICT-LOWER-BOUND? :TYPE BOOLEAN) (STRICT-UPPER-BOUND? :TYPE BOOLEAN)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|FIcache-of: \" (INTERVAL-MEMBER SELF) \" \" (CHOOSE (STRICT-LOWER-BOUND? SELF) \"(\" \"[\") (CHOOSE (DEFINED? (LOWER-BOUND SELF)) (FLOAT-TO-STRING (LOWER-BOUND SELF)) \"?\") \",\" (CHOOSE (DEFINED? (UPPER-BOUND SELF)) (FLOAT-TO-STRING (UPPER-BOUND SELF)) \"?\") (CHOOSE (STRICT-UPPER-BOUND? SELF) \")\" \"]\") \"|\"))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.FloatIntervalCache", "newFloatIntervalCache", new java.lang.Class [] {});
            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.FloatIntervalCache", "accessFloatIntervalCacheSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.pl_kernel_kb.FloatIntervalCache"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("ARITHMETIC-EQUAL-TEST", "(DEFUN (ARITHMETIC-EQUAL-TEST BOOLEAN) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "arithmeticEqualTest", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("ARITHMETIC-LESS-TEST", "(DEFUN (ARITHMETIC-LESS-TEST BOOLEAN) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "arithmeticLessTest", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("ARITHMETIC-GREATER-TEST", "(DEFUN (ARITHMETIC-GREATER-TEST BOOLEAN) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "arithmeticGreaterTest", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("PLUS-COMPUTATION", "(DEFUN (PLUS-COMPUTATION NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "plusComputation", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("MINUS-COMPUTATION", "(DEFUN (MINUS-COMPUTATION NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "minusComputation", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("TIMES-COMPUTATION", "(DEFUN (TIMES-COMPUTATION NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "timesComputation", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("DIVIDE-COMPUTATION", "(DEFUN (DIVIDE-COMPUTATION NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "divideComputation", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("SQRT-COMPUTATION", "(DEFUN (SQRT-COMPUTATION NUMBER-WRAPPER) ((X NUMBER-WRAPPER)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "sqrtComputation", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("PLUS-CONSTRAINT", "(DEFUN (PLUS-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 NUMBER-WRAPPER) (X2 NUMBER-WRAPPER) (X3 NUMBER-WRAPPER)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "plusConstraint", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.IntegerWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("MINUS-CONSTRAINT", "(DEFUN (MINUS-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 NUMBER-WRAPPER) (X2 NUMBER-WRAPPER) (X3 NUMBER-WRAPPER)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "minusConstraint", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.IntegerWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("TIMES-CONSTRAINT", "(DEFUN (TIMES-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 NUMBER-WRAPPER) (X2 NUMBER-WRAPPER) (X3 NUMBER-WRAPPER)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "timesConstraint", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.IntegerWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("DIVIDE-CONSTRAINT", "(DEFUN (DIVIDE-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 NUMBER-WRAPPER) (X2 NUMBER-WRAPPER) (X3 NUMBER-WRAPPER)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "divideConstraint", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.IntegerWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("SQRT-CONSTRAINT", "(DEFUN (SQRT-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 NUMBER-WRAPPER) (X2 NUMBER-WRAPPER)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "sqrtConstraint", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.IntegerWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("CREATE-INTERVAL-CACHE", "(DEFUN (CREATE-INTERVAL-CACHE INTERVAL-CACHE) ((INTERVALMEMBER LOGIC-OBJECT) (INTEGER? BOOLEAN)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "createIntervalCache", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("GET-INTERVAL-CACHE", "(DEFUN (GET-INTERVAL-CACHE INTERVAL-CACHE) ((SELF LOGIC-OBJECT)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "getIntervalCache", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject")}), null);
          Stella.defineFunctionObject("COERCE-INTERVAL-BOUND-TO-INTEGER", "(DEFUN (COERCE-INTERVAL-BOUND-TO-INTEGER INTEGER) ((SELF OBJECT) (OPERATOR SURROGATE)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "coerceIntervalBoundToInteger", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("INTEGER.COERCE-INTERVAL-BOUND-TO-INTEGER", "(DEFUN (INTEGER.COERCE-INTERVAL-BOUND-TO-INTEGER INTEGER) ((SELF INTEGER-WRAPPER) (OPERATOR SURROGATE)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "integerDcoerceIntervalBoundToInteger", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.IntegerWrapper"), Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("FLOAT.COERCE-INTERVAL-BOUND-TO-INTEGER", "(DEFUN (FLOAT.COERCE-INTERVAL-BOUND-TO-INTEGER INTEGER) ((SELF FLOAT-WRAPPER) (OPERATOR SURROGATE)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "floatDcoerceIntervalBoundToInteger", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.FloatWrapper"), Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("SIGNAL-INTERVAL-CLASH", "(DEFUN SIGNAL-INTERVAL-CLASH ((INTERVAL INTERVAL-CACHE)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntervalCache", "signalIntervalClash", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.pl_kernel_kb.IntervalCache")}), null);
          Stella.defineFunctionObject("EVALUATE-ADJACENT-INEQUALITIES", "(DEFUN EVALUATE-ADJACENT-INEQUALITIES ((SELF LOGIC-OBJECT)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "evaluateAdjacentInequalities", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject")}), null);
          Stella.defineMethodObject("(DEFMETHOD EVALUATE-TIGHTER-INTERVAL ((INTERVAL INTERVAL-CACHE)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntervalCache", "evaluateTighterInterval", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD EVALUATE-TIGHTER-INTERVAL ((INTERVAL INTEGER-INTERVAL-CACHE)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntegerIntervalCache", "evaluateTighterInterval", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD EVALUATE-TIGHTER-INTERVAL ((INTERVAL FLOAT-INTERVAL-CACHE)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.FloatIntervalCache", "evaluateTighterInterval", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD PROPAGATE-INEQUALITY-TO-INTERVAL-CACHE ((SELF INTERVAL-CACHE) (VALUE OBJECT) (OPERATOR SURROGATE)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntervalCache", "propagateInequalityToIntervalCache", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Surrogate")}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD PROPAGATE-INEQUALITY-TO-INTERVAL-CACHE ((SELF INTEGER-INTERVAL-CACHE) (VALUE OBJECT) (OPERATOR SURROGATE)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntegerIntervalCache", "propagateInequalityToIntervalCache", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Surrogate")}), ((java.lang.reflect.Method)(null)));
          Stella.defineMethodObject("(DEFMETHOD PROPAGATE-INEQUALITY-TO-INTERVAL-CACHE ((SELF FLOAT-INTERVAL-CACHE) (VALUE OBJECT) (OPERATOR SURROGATE)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.FloatIntervalCache", "propagateInequalityToIntervalCache", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Surrogate")}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("INVERSE-INEQUALITY-OPERATOR", "(DEFUN (INVERSE-INEQUALITY-OPERATOR SURROGATE) ((OPERATOR SURROGATE)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "inverseInequalityOperator", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("UNIFY-INTERVAL-CACHES", "(DEFUN UNIFY-INTERVAL-CACHES ((CACHE1 INTERVAL-CACHE) (CACHE2 INTERVAL-CACHE) (OPERATOR SURROGATE)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntervalCache", "unifyIntervalCaches", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.pl_kernel_kb.IntervalCache"), Native.find_java_class("edu.isi.powerloom.pl_kernel_kb.IntervalCache"), Native.find_java_class("edu.isi.stella.Surrogate")}), null);
          Stella.defineFunctionObject("ACCESS-INTERVAL-BOUNDS", "(DEFUN (ACCESS-INTERVAL-BOUNDS NUMBER-WRAPPER BOOLEAN) ((X OBJECT) (LOWERORUPPER KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "accessIntervalBounds", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Keyword"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("ACCESS-INTERVAL-CACHE-BOUNDS", "(DEFUN (ACCESS-INTERVAL-CACHE-BOUNDS NUMBER-WRAPPER BOOLEAN) ((INTERVALCACHE INTERVAL-CACHE) (LOWERORUPPER KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.IntervalCache", "accessIntervalCacheBounds", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.pl_kernel_kb.IntervalCache"), Native.find_java_class("edu.isi.stella.Keyword"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("COMPARE-INTERVAL-BOUNDS?", "(DEFUN (COMPARE-INTERVAL-BOUNDS? BOOLEAN) ((RELATION SURROGATE) (X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "compareIntervalBoundsP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate"), Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("NULL-NUMBER?", "(DEFUN (NULL-NUMBER? BOOLEAN) ((SELF NUMBER-WRAPPER)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "nullNumberP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("SATISFIES-INTERVAL-BOUNDS?", "(DEFUN (SATISFIES-INTERVAL-BOUNDS? BOOLEAN) ((OBJECT OBJECT) (VALUE NUMBER-WRAPPER)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "satisfiesIntervalBoundsP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.NumberWrapper")}), null);
          Stella.defineFunctionObject("LESS-SPECIALIST", "(DEFUN (LESS-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "lessSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("GREATER-SPECIALIST", "(DEFUN (GREATER-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "greaterSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("INEQUALITY-EVALUATOR", "(DEFUN INEQUALITY-EVALUATOR ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "inequalityEvaluator", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("CONCATENATE-CONSTRAINT", "(DEFUN (CONCATENATE-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 STRING-WRAPPER) (X2 STRING-WRAPPER) (X3 STRING-WRAPPER)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "concatenateConstraint", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.IntegerWrapper"), Native.find_java_class("edu.isi.stella.StringWrapper"), Native.find_java_class("edu.isi.stella.StringWrapper"), Native.find_java_class("edu.isi.stella.StringWrapper")}), null);
          Stella.defineFunctionObject("SUBSEQUENCE-SPECIALIST", "(DEFUN (SUBSEQUENCE-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "subsequenceSpecialist", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.ControlFrame"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("STRING-MATCH-COMPUTATION", "(DEFUN (STRING-MATCH-COMPUTATION INTEGER-WRAPPER) ((PATTERN OBJECT) (X OBJECT) (START OBJECT) (END OBJECT)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "stringMatchComputation", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("LENGTH-COMPUTATION", "(DEFUN (LENGTH-COMPUTATION INTEGER-WRAPPER) ((X OBJECT)))", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "lengthComputation", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("STARTUP-ARITHMETIC", "(DEFUN STARTUP-ARITHMETIC () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.pl_kernel_kb._StartupArithmetic", "startupArithmetic", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(PlKernelKb.SYM_PL_KERNEL_KB_STARTUP_ARITHMETIC);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("_Startup-Arithmetic"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
