//  -*- Mode: C++ -*-

// startup-system.cc

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

void startupLogicSystem() {
  // Should be synchronized on process lock oBOOTSTRAP_LOCKo
  {
    if (currentStartupTimePhaseP(0)) {
      if (!(systemStartedUpP("stella", "/STELLA"))) {
        startupStellaSystem();
      }
    }
    if (currentStartupTimePhaseP(1)) {
      defineModuleFromStringifiedSource("/LOGIC", "(:LISP-PACKAGE \"STELLA\" :CPP-PACKAGE \"logic\" :JAVA-PACKAGE \"edu.isi.powerloom.logic\" :CLEARABLE? FALSE :CODE-ONLY? TRUE)");
      defineModuleFromStringifiedSource("/PL-KERNEL-KB", "(:DOCUMENTATION \"Defines foundation classes and relations for\nPowerLoom.\" :CPP-PACKAGE \"pl_kernel_kb\" :JAVA-PACKAGE \"edu.isi.powerloom.pl_kernel_kb\" :USES (\"LOGIC\" \"STELLA\") :SHADOW (COLLECTION SET RELATION FUNCTION CLASS LIST VALUE ARITY INVERSE NAME) :NICKNAME \"PL-KERNEL\" :PROTECT-SURROGATES? TRUE)");
      defineModuleFromStringifiedSource("/PL-KERNEL-KB/PL-USER", "(:DOCUMENTATION \"The default module for PowerLoom users.  It does not\ncontain any local declarations or axioms, but it includes other modules\nneeded to call PowerLoom functions.\" :INCLUDES (\"PL-KERNEL\") :USES (\"LOGIC\" \"STELLA\"))");
      defineModuleFromStringifiedSource("/PL-KERNEL-KB/LOOM-API", "(:DOCUMENTATION \"Defines a Loom API for PowerLoom.\" :LISP-PACKAGE \"LOOM-API\" :INCLUDES \"PL-KERNEL\" :USES (\"LOGIC\" \"STELLA\") :SHADOW (NAMED?) :PROTECT-SURROGATES? TRUE)");
      defineModuleFromStringifiedSource("/PL-KERNEL-KB/KIF-FRAME-ONTOLOGY", "(:DOCUMENTATION \"Defines KIF-compatible frame predicates following\nOntolingua conventions.\" :USES (\"LOGIC\" \"STELLA\"))");
      defineModuleFromStringifiedSource("/PL-KERNEL-KB/CYC-FRAME-ONTOLOGY", "(:DOCUMENTATION \"Defines Cyc-compatible frame predicates.\" :USES (\"LOGIC\" \"STELLA\"))");
      defineModuleFromStringifiedSource("/PLI", "(:DOCUMENTATION \"Defines the PowerLoom API.\" :USES (\"LOGIC\" \"STELLA\") :SHADOW (GET-OBJECT GET-RELATION GET-MODULE CHANGE-MODULE CLEAR-MODULE LOAD LOAD-STREAM GET-RULES PRINT-RULES RUN-FORWARD-RULES SAVE-MODULE CREATE-OBJECT DESTROY-OBJECT ASSERT RETRACT CONCEIVE EVALUATE EVALUATE-STRING IS-TRUE IS-FALSE IS-UNKNOWN ASK RETRIEVE CREATE-ENUMERATED-SET) :API? TRUE :LISP-PACKAGE \"PLI\" :CPP-PACKAGE \"pli\" :JAVA-PACKAGE \"edu.isi.powerloom\" :JAVA-CATCHALL-CLASS \"PLI\" :CODE-ONLY? TRUE)");
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
      if (currentStartupTimePhaseP(2)) {
        SYM_STARTUP_SYSTEM_LOGIC_STARTUP_LOGIC_SYSTEM = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-LOGIC-SYSTEM", NULL, 0)));
        SYM_STARTUP_SYSTEM_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", TRUE), 0)));
      }
      if (currentStartupTimePhaseP(6)) {
        finalizeClasses();
      }
      if (currentStartupTimePhaseP(7)) {
        defineFunctionObject("STARTUP-LOGIC-SYSTEM", "(DEFUN STARTUP-LOGIC-SYSTEM () :PUBLIC? TRUE)", ((cpp_function_code)(&startupLogicSystem)), NULL);
        { MethodSlot* function = lookupFunction(SYM_STARTUP_SYSTEM_LOGIC_STARTUP_LOGIC_SYSTEM);

          setDynamicSlotValue(function->dynamicSlots, SYM_STARTUP_SYSTEM_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("Startup-Logic-System"), NULL_STRING_WRAPPER);
        }
      }
      if (currentStartupTimePhaseP(8)) {
        finalizeSlots();
        cleanupUnfinalizedClasses();
      }
      if (currentStartupTimePhaseP(9)) {
        { int phase = NULL_INTEGER;
          int iter063 = 0;
          int upperBound064 = 9;

          while (iter063 <= upperBound064) {
            phase = iter063;
            iter063 = iter063 + 1;
            oSTARTUP_TIME_PHASEo = phase;
            startupLogicMacros();
            startupSequenceIndices();
            startupKifIn();
            startupPropositions();
            startupBacklinks();
            startupPropagate();
            startupInferenceCaches();
            startupDescriptions();
            startupNormalize();
            startupRules();
            startupQuery();
            startupPartialMatch();
            startupMachineLearning();
            startupRuleInduction();
            startupNeuralNetwork();
            startupCaseBased();
            startupGoalCaches();
            startupStrategies();
            startupJustifications();
            startupExplanations();
            startupWhynot();
            startupKifOut();
            startupPrint();
            startupGenerate();
            startupSpecialists();
            startupSpecialize();
            startupOptimize();
            startupClassify();
            startupLogicIn();
            pl_kernel_kb::startupPlKernelKb();
            pl_kernel_kb::startupArithmetic();
            startupFrameSupport();
            pl_kernel_kb_pl_kernel_kb_loom_api::startupLoomSupport();
            startupLoomToKif();
            startupApiSupport();
            pli::startupPli();
            startupPowerloom();
          }
        }
        oSTARTUP_TIME_PHASEo = 999;
      }
    }
  }
}

Symbol* SYM_STARTUP_SYSTEM_LOGIC_STARTUP_LOGIC_SYSTEM = NULL;

Symbol* SYM_STARTUP_SYSTEM_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
