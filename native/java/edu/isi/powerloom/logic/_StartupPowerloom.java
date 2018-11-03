//  -*- Mode: Java -*-
//
// _StartupPowerloom.java

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

public class _StartupPowerloom {
  public static void startupPowerloom() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          Logic.SYM_LOGIC_STARTUP_POWERLOOM = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-POWERLOOM", null, 0)));
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Logic.$POWERLOOM_VERSION_STRING$ = "PowerLoom " + Native.integerToString(Logic.$POWERLOOM_MAJOR_VERSION_NUMBER$) + "." + Native.integerToString(Logic.$POWERLOOM_MINOR_VERSION_NUMBER$) + "." + Native.integerToString(Logic.$POWERLOOM_PATCH_LEVEL$) + Logic.$POWERLOOM_RELEASE_STATE$;
          Logic.$POWERLOOM_LOCK$ = Stella.makeProcessLock();
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("POWERLOOM-COPYRIGHT-HEADER", "(DEFUN (POWERLOOM-COPYRIGHT-HEADER STRING) ())", Native.find_java_method("edu.isi.powerloom.logic.Logic", "powerloomCopyrightHeader", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("COPYRIGHT", "(DEFUN COPYRIGHT () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Print detailed PowerLoom copyright information.\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "copyright", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("COPYRIGHT-YEARS", "(DEFUN (COPYRIGHT-YEARS STRING) ())", Native.find_java_method("edu.isi.powerloom.logic.Logic", "copyrightYears", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("POWERLOOM", "(DEFUN POWERLOOM () :DOCUMENTATION \"Run the PowerLoom listener.  Read logic commands from the\nstandard input, evaluate them, and print their results.  Exit if the user\nentered `bye', `exit', `halt', `quit', or `stop'.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "powerloom", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("STARTUP-POWERLOOM", "(DEFUN STARTUP-POWERLOOM () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupPowerloom", "startupPowerloom", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_POWERLOOM);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("_Startup-Powerloom"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-MAJOR-VERSION-NUMBER* INTEGER 3)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-MINOR-VERSION-NUMBER* INTEGER 0)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-RELEASE-STATE* STRING \".beta\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-PATCH-LEVEL* INTEGER 2)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-VERSION-STRING* STRING (CONCATENATE \"PowerLoom \" (INTEGER-TO-STRING *POWERLOOM-MAJOR-VERSION-NUMBER*) \".\" (INTEGER-TO-STRING *POWERLOOM-MINOR-VERSION-NUMBER*) \".\" (INTEGER-TO-STRING *POWERLOOM-PATCH-LEVEL*) *POWERLOOM-RELEASE-STATE*))");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *POWERLOOM-LOCK* PROCESS-LOCK-OBJECT (MAKE-PROCESS-LOCK) :PUBLIC? TRUE :DOCUMENTATION \"Lock object for synchronizing safe multi-process access to PowerLoom\")");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
