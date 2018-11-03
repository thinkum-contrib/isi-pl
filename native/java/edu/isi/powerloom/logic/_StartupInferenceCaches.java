//  -*- Mode: Java -*-
//
// _StartupInferenceCaches.java

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

public class _StartupInferenceCaches {
  public static void startupInferenceCaches() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          Logic.SYM_LOGIC_INFERENCE_CACHE_OF = ((Symbol)(Stella.internRigidSymbolWrtModule("INFERENCE-CACHE-OF", null, 0)));
          Logic.KWD_JUST_IN_TIME = ((Keyword)(Stella.internRigidSymbolWrtModule("JUST-IN-TIME", null, 2)));
          Logic.SYM_LOGIC_JUST_IN_TIME_INFERENCE_CACHE = ((Symbol)(Stella.internRigidSymbolWrtModule("JUST-IN-TIME-INFERENCE-CACHE", null, 0)));
          Logic.KWD_TMS = ((Keyword)(Stella.internRigidSymbolWrtModule("TMS", null, 2)));
          Logic.SYM_LOGIC_UP_TO_DATE_INFERENCESp = ((Symbol)(Stella.internRigidSymbolWrtModule("UP-TO-DATE-INFERENCES?", null, 0)));
          Logic.SYM_LOGIC_TRUTH_MAINTAINEDp = ((Symbol)(Stella.internRigidSymbolWrtModule("TRUTH-MAINTAINED?", null, 0)));
          Logic.KWD_PERFORMANCE_CLUES = ((Keyword)(Stella.internRigidSymbolWrtModule("PERFORMANCE-CLUES", null, 2)));
          Logic.KWD_FORCE = ((Keyword)(Stella.internRigidSymbolWrtModule("FORCE", null, 2)));
          Logic.SYM_LOGIC_STARTUP_INFERENCE_CACHES = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-INFERENCE-CACHES", null, 0)));
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Logic.$INVISIBLEASSERTIONp$.setDefaultValue(new Boolean(false));
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("WORLD-STATE?", "(DEFUN (WORLD-STATE? BOOLEAN) ((SELF CONTEXT)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "worldStateP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context")}), null);
          Stella.defineFunctionObject("GET-WORLD-STATE", "(DEFUN (GET-WORLD-STATE CONTEXT) ((SELF CONTEXT)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getWorldState", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context")}), null);
          Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT META-INFERENCE-CACHE :TYPE WORLD :ALLOCATION :DYNAMIC)");
          Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT TRUTH-MAINTAINED-INFERENCE-CACHE :TYPE WORLD :ALLOCATION :DYNAMIC)");
          Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT JUST-IN-TIME-INFERENCE-CACHE :TYPE WORLD :ALLOCATION :DYNAMIC)");
          Stella.defineExternalSlotFromStringifiedSource("(DEFSLOT WORLD INFERENCE-CACHE-OF :TYPE CONTEXT :PUBLIC? TRUE :ALLOCATION :DYNAMIC)");
          Stella.defineFunctionObject("LOOKUP-INFERENCE-CACHE", "(DEFUN (LOOKUP-INFERENCE-CACHE WORLD) ((CONTEXT CONTEXT) (KIND KEYWORD)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "lookupInferenceCache", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("INITIALIZE-INFERENCE-WORLD", "(DEFUN INITIALIZE-INFERENCE-WORLD ((WORLD WORLD)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "initializeInferenceWorld", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.World")}), null);
          Stella.defineFunctionObject("CREATE-INFERENCE-CACHE", "(DEFUN (CREATE-INFERENCE-CACHE WORLD) ((CONTEXT CONTEXT) (KIND KEYWORD)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "createInferenceCache", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("GET-INFERENCE-CACHE", "(DEFUN (GET-INFERENCE-CACHE WORLD) ((CONTEXT CONTEXT) (KIND KEYWORD)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getInferenceCache", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("DESTROY-INFERENCE-CACHE", "(DEFUN DESTROY-INFERENCE-CACHE ((CONTEXT CONTEXT) (KIND KEYWORD)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "destroyInferenceCache", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("UNLINK-INFERENCE-CACHE", "(DEFUN UNLINK-INFERENCE-CACHE ((SELF WORLD)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "unlinkInferenceCache", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.World")}), null);
          Stella.defineFunctionObject("DESTROY-INFERENCE-CACHES", "(DEFUN DESTROY-INFERENCE-CACHES ((CONTEXT CONTEXT)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "destroyInferenceCaches", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context")}), null);
          Stella.defineFunctionObject("META-PROPOSITION?", "(DEFUN (META-PROPOSITION? BOOLEAN) ((PROPOSITION PROPOSITION)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "metaPropositionP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("HANDLE-OUT-OF-DATE-INFERENCE-CACHE", "(DEFUN HANDLE-OUT-OF-DATE-INFERENCE-CACHE ((ASSERTORRETRACT KEYWORD) (PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "handleOutOfDateInferenceCache", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Keyword"), Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("BEST-INFERENCE-CACHE", "(DEFUN (BEST-INFERENCE-CACHE WORLD) ((CONTEXT CONTEXT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "bestInferenceCache", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context")}), null);
          Stella.defineFunctionObject("GET-QUERY-CONTEXT", "(DEFUN (GET-QUERY-CONTEXT CONTEXT) () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getQueryContext", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("GET-PROPERTY-TEST-CONTEXT", "(DEFUN (GET-PROPERTY-TEST-CONTEXT CONTEXT) ())", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getPropertyTestContext", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("GET-INFERABLE-TEST-CONTEXT", "(DEFUN (GET-INFERABLE-TEST-CONTEXT CONTEXT) ())", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getInferableTestContext", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("GET-TOP-LEVEL-UPDATE-CONTEXT", "(DEFUN (GET-TOP-LEVEL-UPDATE-CONTEXT CONTEXT) ())", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getTopLevelUpdateContext", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("LOOKUP-CONSTRAINT-PROPAGATION-WORLD", "(DEFUN (LOOKUP-CONSTRAINT-PROPAGATION-WORLD WORLD) ((SELF CONTEXT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "lookupConstraintPropagationWorld", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context")}), null);
          Stella.defineFunctionObject("INHERIT-CACHED-INFERENCES", "(DEFUN INHERIT-CACHED-INFERENCES ((FROMWORLD WORLD) (TOWORLD WORLD)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "inheritCachedInferences", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.World"), Native.find_java_class("edu.isi.stella.World")}), null);
          Stella.defineFunctionObject("INHERIT-TRUTH-VALUE-UPDATE", "(DEFUN INHERIT-TRUTH-VALUE-UPDATE ((PROPOSITION PROPOSITION) (TOWORLD WORLD)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "inheritTruthValueUpdate", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.World")}), null);
          Stella.defineFunctionObject("INHERIT-VARIABLE-VALUE-UPDATE", "(DEFUN INHERIT-VARIABLE-VALUE-UPDATE ((SKOLEM SKOLEM) (TOWORLD WORLD)))", Native.find_java_method("edu.isi.powerloom.logic.Skolem", "inheritVariableValueUpdate", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Skolem"), Native.find_java_class("edu.isi.stella.World")}), null);
          Stella.defineFunctionObject("CALL-PROPAGATE-CONSTRAINTS", "(DEFUN CALL-PROPAGATE-CONSTRAINTS ((CONTEXT CONTEXT)) :DOCUMENTATION \"Trigger constraint propagation over all propositions\nin the module or world `context'.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "callPropagateConstraints", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Context")}), null);
          Stella.defineFunctionObject("PROPAGATE-CONSTRAINTS", "(DEFUN PROPAGATE-CONSTRAINTS (|&REST| (NAME NAME)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Trigger constraint propagation over all propositions of module `name'.\nIf no `name' is supplied, the current module will be used.  This also\nenables incremental constraint propagation for future monotonic updates to\nthe module.  Once a non-monotonic update is performed, i.e., a retraction\nor clipping of a function value, all cached inferences will be discarded\nand constraint propagation will be turned off until this function is\ncalled again.\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "propagateConstraints", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "propagateConstraintsEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("REPROPAGATE-CONSTRAINTS", "(DEFUN REPROPAGATE-CONSTRAINTS (|&REST| (NAME NAME)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Force non-incremental constraint propagation over all propositions of\nmodule `name'.  If no `name' is supplied, the current module will be used.\nThis also enables incremental constraint propagation for future monotonic\nupdates to the module similar to `propagate-constraints'.\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "repropagateConstraints", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "repropagateConstraintsEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("CALL-RUN-FORWARD-RULES", "(DEFUN CALL-RUN-FORWARD-RULES ((MODULE MODULE) (FORCE? BOOLEAN)) :DOCUMENTATION \"Run forward inference rules in module 'module'. If 'module'\nis NULL, the current module will be used.  If forward inferencing is already\nup-to-date in the designated module, no additional inferencing will occur,\nunless 'force?' is set to TRUE, in which case all forward rules are run or rerun.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "callRunForwardRules", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Module"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("RUN-FORWARD-RULES", "(DEFUN RUN-FORWARD-RULES ((MODULEREF NAME) |&REST| (FORCE KEYWORD)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Run forward inference rules in module 'moduleRef'. If 'moduleRef' is NULL, the\ncurrent module will be used.  If forward inferencing is already up-to-date\nin the designated module, no additional inferencing will occur, unless the\noptional keyword `:force' is included, in which case all\nforward rules are run or rerun.\n\nCalling `run-forward-rules' temporarily puts the module into a mode where\nfuture assertional (monotonic) updates will trigger additional forward\ninference.  Once a non-monotonic update is performed, i.e., a retraction\nor clipping of relation value, all cached forward inferences will be discarded\nand forward inferencing will be disabled until this function is\ncalled again.\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "runForwardRules", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), Native.find_java_method("edu.isi.powerloom.logic.Logic", "runForwardRulesEvaluatorWrapper", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}));
          Stella.defineFunctionObject("STARTUP-INFERENCE-CACHES", "(DEFUN STARTUP-INFERENCE-CACHES () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupInferenceCaches", "startupInferenceCaches", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_INFERENCE_CACHES);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("_Startup-Inference-Caches"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *INVISIBLEASSERTION?* BOOLEAN FALSE :DOCUMENTATION \"Used to signal an assertion that doesn't\nblow away inference caches.\")");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
