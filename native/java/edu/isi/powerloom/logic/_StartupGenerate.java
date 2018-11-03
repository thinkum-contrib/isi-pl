//  -*- Mode: Java -*-
//
// _StartupGenerate.java

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

public class _StartupGenerate {
  public static void startupGenerate() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          Logic.SYM_LOGIC_UNIDENTIFIED_SKOLEM = ((Symbol)(Stella.internRigidSymbolWrtModule("UNIDENTIFIED-SKOLEM", null, 0)));
          Logic.SYM_LOGIC_UNNAMED_OBJECT = ((Symbol)(Stella.internRigidSymbolWrtModule("UNNAMED_OBJECT", null, 0)));
          Logic.SYM_LOGIC_ILLEGAL_TERM = ((Symbol)(Stella.internRigidSymbolWrtModule("ILLEGAL-TERM", null, 0)));
          Logic.SYM_LOGIC_STARTUP_GENERATE = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-GENERATE", null, 0)));
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Logic.$CANONICALVARIABLENAMEMAPPING$.setDefaultValue(null);
          Logic.$CANONICALVARIABLECOUNTER$.setDefaultValue(new Integer(Stella.NULL_INTEGER));
        }
        if (Stella.currentStartupTimePhaseP(5)) {
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("TERM-GENERATION-EXCEPTION", "(DEFCLASS TERM-GENERATION-EXCEPTION (LOGIC-EXCEPTION) :PUBLIC? TRUE :DOCUMENTATION \"Signals an exception during term generation.\" :PUBLIC-SLOTS ((OFFENDING-TERM :TYPE OBJECT :REQUIRED? TRUE)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.powerloom.logic.TermGenerationException", "newTermGenerationException", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("java.lang.String")});
          }
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("GENERATE-EXPRESSION", "(DEFUN (GENERATE-EXPRESSION OBJECT) ((SELF LOGIC-OBJECT) (CANONICALIZEVARIABLENAMES? BOOLEAN)) :PUBLIC? TRUE :DOCUMENTATION \"Return an s-expression representing the source expression for 'self'.\")", Native.find_java_method("edu.isi.powerloom.logic.LogicObject", "generateExpression", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("GENERATE-NAME-OF-VARIABLE", "(DEFUN (GENERATE-NAME-OF-VARIABLE SYMBOL) ((SELF PATTERN-VARIABLE)))", Native.find_java_method("edu.isi.powerloom.logic.PatternVariable", "generateNameOfVariable", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.PatternVariable")}), null);
          Stella.defineFunctionObject("GENERATE-ONE-VARIABLE", "(DEFUN (GENERATE-ONE-VARIABLE OBJECT) ((SELF PATTERN-VARIABLE) (TYPED? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.PatternVariable", "generateOneVariable", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.PatternVariable"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("GENERATE-VARIABLES", "(DEFUN (GENERATE-VARIABLES CONS) ((VECTOR VECTOR) (TYPED? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "generateVariables", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Vector"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("GENERATE-STELLA-COLLECTION", "(DEFUN (GENERATE-STELLA-COLLECTION CONS) ((SELF COLLECTION)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "generateStellaCollection", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Collection")}), null);
          Stella.defineFunctionObject("GENERATE-DESCRIPTION", "(DEFUN (GENERATE-DESCRIPTION OBJECT) ((SELF DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "generateDescription", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description")}), null);
          Stella.defineFunctionObject("GENERATE-ARGUMENTS", "(DEFUN (GENERATE-ARGUMENTS CONS) ((ARGUMENTS VECTOR)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "generateArguments", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Vector")}), null);
          Stella.defineFunctionObject("GENERATE-OPERATOR", "(DEFUN (GENERATE-OPERATOR SYMBOL) ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "generateOperator", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("GENERATE-PROPOSITION", "(DEFUN (GENERATE-PROPOSITION OBJECT) ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "generateProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("GENERATE-FUNCTION-AS-TERM", "(DEFUN (GENERATE-FUNCTION-AS-TERM CONS) ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "generateFunctionAsTerm", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("GENERATE-SKOLEM", "(DEFUN (GENERATE-SKOLEM OBJECT) ((SELF SKOLEM)))", Native.find_java_method("edu.isi.powerloom.logic.Skolem", "generateSkolem", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Skolem")}), null);
          Stella.defineMethodObject("(DEFMETHOD (GENERATE-SPECIALIZED-TERM OBJECT) ((SELF LOGIC-THING)) :PUBLIC? TRUE :DOCUMENTATION \"Method to generate a specialized term for `self'.  This is designed\nto allow for extension of the term generation code to cover other\ntypes of objects for the logic.  This particular method will signal\nan error unless there is a surrogate-value-inverse link set.\")", Native.find_java_method("edu.isi.powerloom.logic.LogicThing", "generateSpecializedTerm", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
          Stella.defineFunctionObject("GENERATE-TERM", "(DEFUN (GENERATE-TERM OBJECT) ((SELF OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "generateTerm", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("GENERATE-IMPLIES-PROPOSITION", "(DEFUN (GENERATE-IMPLIES-PROPOSITION CONS) ((SELF PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "generateImpliesProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("GENERATE-DESCRIPTION-PROPOSITION", "(DEFUN (GENERATE-DESCRIPTION-PROPOSITION CONS) ((SELF DESCRIPTION) (INVERT? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "generateDescriptionProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("GENERATE-DESCRIPTIONS-AS-RULE", "(DEFUN (GENERATE-DESCRIPTIONS-AS-RULE CONS) ((HEAD DESCRIPTION) (TAIL DESCRIPTION) (RULE PROPOSITION) (REVERSEPOLARITY? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "generateDescriptionsAsRule", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description"), Native.find_java_class("edu.isi.powerloom.logic.Description"), Native.find_java_class("edu.isi.powerloom.logic.Proposition"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("DEOBJECTIFY-TREE", "(DEFUN (DEOBJECTIFY-TREE OBJECT) ((SELF OBJECT)) :DOCUMENTATION \"Return a copy of `self' where all logic objects are\nreplaced by their `generated' parse-tree version.  This is useful to\nconvert the result of a retrieval query into a regular parse tree.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "deobjectifyTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("STARTUP-GENERATE", "(DEFUN STARTUP-GENERATE () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupGenerate", "startupGenerate", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_GENERATE);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("_Startup-Generate"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *CANONICALVARIABLENAMEMAPPING* KEY-VALUE-LIST NULL :DOCUMENTATION \"Maps variables to symbols in SYSTEM-DEFINED-ARGUMENT-NAMES.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *CANONICALVARIABLECOUNTER* INTEGER NULL :DOCUMENTATION \"Number of the last canonically-mapped variable.\")");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
