//  -*- Mode: Java -*-
//
// StartupLogicSystem.java

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

public class StartupLogicSystem {
  public static void startupLogicSystem() {
    if (Stella.currentStartupTimePhaseP(0)) {
      if (!(Stella.systemStartedUpP("stella", "/STELLA"))) {
        StartupStellaSystem.startupStellaSystem();
      }
    }
    if (Stella.currentStartupTimePhaseP(1)) {
      Stella.defineModuleFromStringifiedSource("/LOGIC", "(:LISP-PACKAGE \"STELLA\" :CPP-PACKAGE \"logic\" :JAVA-PACKAGE \"edu.isi.powerloom.logic\" :CLEARABLE? FALSE :CODE-ONLY? TRUE)");
      Stella.defineModuleFromStringifiedSource("/PL-KERNEL-KB", "(:DOCUMENTATION \"Defines foundation classes and relations for\nPowerLoom.\" :CPP-PACKAGE \"pl_kernel_kb\" :JAVA-PACKAGE \"edu.isi.powerloom.pl_kernel_kb\" :USES (\"LOGIC\" \"STELLA\") :SHADOW (COLLECTION SET RELATION FUNCTION CLASS LIST VALUE ARITY INVERSE NAME) :NICKNAME \"PL-KERNEL\" :PROTECT-SURROGATES? TRUE)");
      Stella.defineModuleFromStringifiedSource("/PL-KERNEL-KB/PL-USER", "(:DOCUMENTATION \"The default module for PowerLoom users.  It does not\ncontain any local declarations or axioms, but it includes other modules\nneeded to call PowerLoom functions.\" :INCLUDES (\"PL-KERNEL\") :USES (\"LOGIC\" \"STELLA\"))");
      Stella.defineModuleFromStringifiedSource("/PL-KERNEL-KB/LOOM-API", "(:DOCUMENTATION \"Defines a Loom API for PowerLoom.\" :LISP-PACKAGE \"LOOM-API\" :INCLUDES \"PL-KERNEL\" :USES (\"LOGIC\" \"STELLA\") :SHADOW (NAMED?) :PROTECT-SURROGATES? TRUE)");
      Stella.defineModuleFromStringifiedSource("/PL-KERNEL-KB/KIF-FRAME-ONTOLOGY", "(:DOCUMENTATION \"Defines KIF-compatible frame predicates following\nOntolingua conventions.\" :USES (\"LOGIC\" \"STELLA\"))");
      Stella.defineModuleFromStringifiedSource("/PL-KERNEL-KB/CYC-FRAME-ONTOLOGY", "(:DOCUMENTATION \"Defines Cyc-compatible frame predicates.\" :USES (\"LOGIC\" \"STELLA\"))");
      Stella.defineModuleFromStringifiedSource("/PLI", "(:DOCUMENTATION \"Defines the PowerLoom API.\" :USES (\"LOGIC\" \"STELLA\") :SHADOW (GET-OBJECT GET-RELATION GET-MODULE CHANGE-MODULE CLEAR-MODULE LOAD GET-RULES PRINT-RULES RUN-FORWARD-RULES SAVE-MODULE CREATE-OBJECT DESTROY-OBJECT ASSERT RETRACT CONCEIVE EVALUATE EVALUATE-STRING IS-TRUE IS-FALSE IS-UNKNOWN ASK RETRIEVE CREATE-ENUMERATED-SET) :API? TRUE :LISP-PACKAGE \"PLI\" :CPP-PACKAGE \"pli\" :JAVA-PACKAGE \"edu.isi.powerloom\" :JAVA-CATCHALL-CLASS \"PLI\" :CODE-ONLY? TRUE)");
    }
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          Logic.SYM_LOGIC_STARTUP_LOGIC_SYSTEM = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-LOGIC-SYSTEM", null, 0)));
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("STARTUP-LOGIC-SYSTEM", "(DEFUN STARTUP-LOGIC-SYSTEM () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.StartupLogicSystem", "startupLogicSystem", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_LOGIC_SYSTEM);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("Startup-Logic-System"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          { int phase = Stella.NULL_INTEGER;
            int iter102 = 0;
            int upperBound103 = 9;

            while (iter102 <= upperBound103) {
              {
                phase = iter102;
                iter102 = iter102 + 1;
              }
              Stella.$STARTUP_TIME_PHASE$ = phase;
              _StartupLogicMacros.startupLogicMacros();
              _StartupSequenceIndices.startupSequenceIndices();
              _StartupKifIn.startupKifIn();
              _StartupPropositions.startupPropositions();
              _StartupBacklinks.startupBacklinks();
              _StartupPropagate.startupPropagate();
              _StartupInferenceCaches.startupInferenceCaches();
              _StartupDescriptions.startupDescriptions();
              _StartupNormalize.startupNormalize();
              _StartupRules.startupRules();
              _StartupQuery.startupQuery();
              _StartupPartialMatch.startupPartialMatch();
              _StartupMachineLearning.startupMachineLearning();
              _StartupRuleInduction.startupRuleInduction();
              _StartupNeuralNetwork.startupNeuralNetwork();
              _StartupCaseBased.startupCaseBased();
              _StartupGoalCaches.startupGoalCaches();
              _StartupStrategies.startupStrategies();
              _StartupJustifications.startupJustifications();
              _StartupExplanations.startupExplanations();
              _StartupWhynot.startupWhynot();
              _StartupKifOut.startupKifOut();
              _StartupPrint.startupPrint();
              _StartupGenerate.startupGenerate();
              _StartupSpecialists.startupSpecialists();
              _StartupSpecialize.startupSpecialize();
              _StartupOptimize.startupOptimize();
              _StartupClassify.startupClassify();
              _StartupLogicIn.startupLogicIn();
              edu.isi.powerloom.pl_kernel_kb._StartupPlKernelKb.startupPlKernelKb();
              edu.isi.powerloom.pl_kernel_kb._StartupArithmetic.startupArithmetic();
              _StartupFrameSupport.startupFrameSupport();
              edu.isi.powerloom.pl_kernel_kb.loom_api._StartupLoomSupport.startupLoomSupport();
              _StartupLoomToKif.startupLoomToKif();
              _StartupApiSupport.startupApiSupport();
              edu.isi.powerloom._StartupPli.startupPli();
              _StartupPowerloom.startupPowerloom();
            }
          }
          Stella.$STARTUP_TIME_PHASE$ = 999;
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
