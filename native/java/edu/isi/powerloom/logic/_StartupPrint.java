//  -*- Mode: Java -*-
//
// _StartupPrint.java

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

public class _StartupPrint {
  public static void startupPrint() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          Logic.KWD_DEBUG_LOW = ((Keyword)(Stella.internRigidSymbolWrtModule("DEBUG-LOW", null, 2)));
          Logic.KWD_DEBUG_HIGH = ((Keyword)(Stella.internRigidSymbolWrtModule("DEBUG-HIGH", null, 2)));
          Logic.SYM_LOGIC_STARTUP_PRINT = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-PRINT", null, 0)));
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Logic.$PRINTMODE$.setDefaultValue(Logic.KWD_FLAT);
          Logic.$PRINTFUNCTIONSASRELATIONSp$.setDefaultValue(new Boolean(Stella.FALSE));
          Logic.$SKOLEMNAMEMAPPINGTABLE$.setDefaultValue(null);
          Logic.$DEBUG_MODEp$ = Stella.FALSE;
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("WRAP-NATIVE-OUTPUT-STREAM", "(DEFUN (WRAP-NATIVE-OUTPUT-STREAM OUTPUT-STREAM) ((NATIVESTREAM NATIVE-OUTPUT-STREAM)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "wrapNativeOutputStream", new java.lang.Class [] {Native.find_java_class("java.io.PrintStream")}), null);
          Stella.defineFunctionObject("PRINT-TOP-LEVEL-OBJECT", "(DEFUN PRINT-TOP-LEVEL-OBJECT ((SELF OBJECT) (NATIVESTREAM NATIVE-OUTPUT-STREAM)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "printTopLevelObject", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("java.io.PrintStream")}), null);
          Stella.defineFunctionObject("PRINT-LOGIC-OBJECT", "(DEFUN PRINT-LOGIC-OBJECT ((SELF LOGIC-OBJECT) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.LogicObject", "printLogicObject", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.LogicObject"), Native.find_java_class("edu.isi.stella.OutputStream"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("GET-SKOLEM-PRINT-NAME", "(DEFUN (GET-SKOLEM-PRINT-NAME STRING) ((SELF SKOLEM)))", Native.find_java_method("edu.isi.powerloom.logic.Skolem", "getSkolemPrintName", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Skolem")}), null);
          Stella.defineFunctionObject("PRINT-VALUE-OF-CHAIN", "(DEFUN PRINT-VALUE-OF-CHAIN ((SELF SKOLEM) (STREAM OUTPUT-STREAM) (CHAINEND OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Skolem", "printValueOfChain", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Skolem"), Native.find_java_class("edu.isi.stella.OutputStream"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("PRINT-SKOLEM-NAME", "(DEFUN PRINT-SKOLEM-NAME ((SELF SKOLEM) (STREAM OUTPUT-STREAM)))", Native.find_java_method("edu.isi.powerloom.logic.Skolem", "printSkolemName", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Skolem"), Native.find_java_class("edu.isi.stella.OutputStream")}), null);
          Stella.defineFunctionObject("PRINT-VARIABLE-NAME", "(DEFUN PRINT-VARIABLE-NAME ((SELF PATTERN-VARIABLE) (STREAM OUTPUT-STREAM)))", Native.find_java_method("edu.isi.powerloom.logic.PatternVariable", "printVariableName", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.PatternVariable"), Native.find_java_class("edu.isi.stella.OutputStream")}), null);
          Stella.defineFunctionObject("PRINT-VARIABLE-VALUE", "(DEFUN PRINT-VARIABLE-VALUE ((SELF OBJECT) (STREAM OUTPUT-STREAM)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "printVariableValue", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.OutputStream")}), null);
          Stella.defineFunctionObject("PRINT-SKOLEM", "(DEFUN PRINT-SKOLEM ((SELF SKOLEM) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Skolem", "printSkolem", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Skolem"), Native.find_java_class("edu.isi.stella.OutputStream"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("PRINT-VARIABLE", "(DEFUN PRINT-VARIABLE ((SELF PATTERN-VARIABLE) (STREAM OUTPUT-STREAM)))", Native.find_java_method("edu.isi.powerloom.logic.PatternVariable", "printVariable", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.PatternVariable"), Native.find_java_class("edu.isi.stella.OutputStream")}), null);
          Stella.defineFunctionObject("PRINT-QUANTIFIED-VARIABLE", "(DEFUN PRINT-QUANTIFIED-VARIABLE ((SELF PATTERN-VARIABLE) (STREAM OUTPUT-STREAM)))", Native.find_java_method("edu.isi.powerloom.logic.PatternVariable", "printQuantifiedVariable", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.PatternVariable"), Native.find_java_class("edu.isi.stella.OutputStream")}), null);
          Stella.defineFunctionObject("PRINT-PROPOSITION", "(DEFUN PRINT-PROPOSITION ((SELF PROPOSITION) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "printProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.OutputStream"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("PRINT-DESCRIPTION", "(DEFUN PRINT-DESCRIPTION ((SELF DESCRIPTION) (STREAM OUTPUT-STREAM) (TOPLEVEL? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "printDescription", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description"), Native.find_java_class("edu.isi.stella.OutputStream"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("STARTUP-PRINT", "(DEFUN STARTUP-PRINT () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupPrint", "startupPrint", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_PRINT);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("_Startup-Print"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *PRINTMODE* KEYWORD :FLAT :DOCUMENTATION \"Controls the kind of detail that gets printed about\nindividual objects.  Values are :ORIGINAL, :REALISTIC, :FLAT, :DEBUG-LOW, and\n :DEBUG-HIGH.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *PRINTFUNCTIONSASRELATIONS?* BOOLEAN FALSE :DOCUMENTATION \"Controls whether functions are printed as relations (F i v) or\nas functions (= (F i) v).\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT VARIABLE-BINDING-SEPARATOR STRING \"/\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT VALUE-OF-SEPARATOR STRING \"//\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *SKOLEMNAMEMAPPINGTABLE* (KEY-VALUE-LIST OF SKOLEM SKOLEM) NULL :DOCUMENTATION \"If set, maps some skolems to names other than\ntheir own.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DEBUG-MODE?* BOOLEAN FALSE :DOCUMENTATION \"If set to TRUE, simplify printing so that it\ndoesn't break during a debugging session.\")");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
