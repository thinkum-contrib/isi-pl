//  -*- Mode: Java -*-
//
// _StartupRules.java

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

public class _StartupRules {
  public static void startupRules() {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("/LOGIC", Stella.$STARTUP_TIME_PHASE$ > 1));
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          Logic.KWD_HEAD = ((Keyword)(Stella.internRigidSymbolWrtModule("HEAD", null, 2)));
          Logic.KWD_TAIL = ((Keyword)(Stella.internRigidSymbolWrtModule("TAIL", null, 2)));
          Logic.KWD_POSITIVE = ((Keyword)(Stella.internRigidSymbolWrtModule("POSITIVE", null, 2)));
          Logic.KWD_CONTRAPOSITIVE = ((Keyword)(Stella.internRigidSymbolWrtModule("CONTRAPOSITIVE", null, 2)));
          Logic.SYM_LOGIC_RULES_WITH_DEFERRED_SATELLITES = ((Symbol)(Stella.internRigidSymbolWrtModule("RULES-WITH-DEFERRED-SATELLITES", null, 0)));
          Logic.KWD_POSITIVE_AND_CONTRAPOSITIVE = ((Keyword)(Stella.internRigidSymbolWrtModule("POSITIVE-AND-CONTRAPOSITIVE", null, 2)));
          Logic.SYM_LOGIC_STARTUP_RULES = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-RULES", null, 0)));
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          Logic.$LAZY_SATELLITE_RULESp$ = Stella.TRUE;
          Logic.$DERIVE_DEFERRED_SATELLITE_RULES_INVOCATIONS$.setDefaultValue(null);
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          Stella.defineFunctionObject("FIND-MATCHABLE-GOALS", "(DEFUN (FIND-MATCHABLE-GOALS (LIST OF PROPOSITION)) ((FORALLPROP PROPOSITION) (HEADORTAIL KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "findMatchableGoals", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("COLLECT-MATCHING-RULE-GOALS", "(DEFUN COLLECT-MATCHING-RULE-GOALS ((PROPOSITION PROPOSITION) (TOPLEVELVARS CONS) (HEADORTAIL KEYWORD) (COLLECTION (LIST OF PROPOSITION))))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "collectMatchingRuleGoals", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Keyword"), Native.find_java_class("edu.isi.stella.List")}), null);
          Stella.defineFunctionObject("ATOMIC-FORALL-ARGUMENT?", "(DEFUN (ATOMIC-FORALL-ARGUMENT? BOOLEAN) ((FORALLPROP PROPOSITION) (HEADORTAIL KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "atomicForallArgumentP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("ATOMIC-GOAL-PROPOSITION?", "(DEFUN (ATOMIC-GOAL-PROPOSITION? BOOLEAN) ((PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "atomicGoalPropositionP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("ATOMIC-GOAL-DESCRIPTION?", "(DEFUN (ATOMIC-GOAL-DESCRIPTION? BOOLEAN) ((DESCRIPTION DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "atomicGoalDescriptionP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description")}), null);
          Stella.defineFunctionObject("VARIABLE-ARITY-GOAL-PROPOSITION?", "(DEFUN (VARIABLE-ARITY-GOAL-PROPOSITION? BOOLEAN) ((PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "variableArityGoalPropositionP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("CHAINABLE-RELATION?", "(DEFUN (CHAINABLE-RELATION? BOOLEAN) ((DESCRIPTION NAMED-DESCRIPTION) (HEADORTAIL KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.NamedDescription", "chainableRelationP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.NamedDescription"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("EXTRACT-GOAL-DESCRIPTION", "(DEFUN (EXTRACT-GOAL-DESCRIPTION DESCRIPTION) ((GOAL PROPOSITION) (HEADORTAIL KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "extractGoalDescription", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("EXTRACT-GOAL-ARGUMENTS", "(DEFUN (EXTRACT-GOAL-ARGUMENTS CONS) ((GOAL PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "extractGoalArguments", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("SUBSTITUTE-PROPOSITION", "(DEFUN (SUBSTITUTE-PROPOSITION PROPOSITION) ((PROPOSITION PROPOSITION) (OUTPROP PROPOSITION) (INPROP PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "substituteProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("EXTRACT-INVERTED-GOAL", "(DEFUN (EXTRACT-INVERTED-GOAL PROPOSITION) ((PROPOSITION PROPOSITION) (GOAL PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "extractInvertedGoal", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("INVERT-FORALL-AROUND-GOAL", "(DEFUN (INVERT-FORALL-AROUND-GOAL PROPOSITION) ((FORALLPROP PROPOSITION) (GOAL PROPOSITION) (HEADORTAIL KEYWORD) (CONTRAPOSITIVE? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "invertForallAroundGoal", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Keyword"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("CONSTRUCT-DESCRIPTION-FROM-FORALL-PROPOSITION", "(DEFUN (CONSTRUCT-DESCRIPTION-FROM-FORALL-PROPOSITION OBJECT) ((FORALLPROP PROPOSITION) (HEADORTAIL KEYWORD)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "constructDescriptionFromForallProposition", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Keyword")}), null);
          Stella.defineFunctionObject("MARK-AS-FORWARD-RULE", "(DEFUN MARK-AS-FORWARD-RULE ((IMPLIESPROP PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "markAsForwardRule", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("DERIVE-ONE-SATELLITE-RULE", "(DEFUN DERIVE-ONE-SATELLITE-RULE ((MASTERFORALL PROPOSITION) (GOAL PROPOSITION) (HEADORTAIL KEYWORD) (CONTRAPOSITIVE? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "deriveOneSatelliteRule", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.stella.Keyword"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("EQUATE-AND-SIMPLIFY-FORALL-ARGUMENT", "(DEFUN EQUATE-AND-SIMPLIFY-FORALL-ARGUMENT ((PROPOSITION PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "equateAndSimplifyForallArgument", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("DERIVE-SATELLITE-RULES-FOR-GOAL?", "(DEFUN (DERIVE-SATELLITE-RULES-FOR-GOAL? BOOLEAN) ((FORALLPROP PROPOSITION) (GOALDESCRIPTION DESCRIPTION) (DIRECTION KEYWORD) (LAZYSATELLITES? BOOLEAN)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "deriveSatelliteRulesForGoalP", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Description"), Native.find_java_class("edu.isi.stella.Keyword"), java.lang.Boolean.TYPE}), null);
          Stella.defineFunctionObject("DERIVE-SATELLITE-RULES", "(DEFUN DERIVE-SATELLITE-RULES ((FORALLPROP PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "deriveSatelliteRules", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("DERIVE-DEFERRED-SATELLITE-RULES", "(DEFUN DERIVE-DEFERRED-SATELLITE-RULES ((SELF DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "deriveDeferredSatelliteRules", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description")}), null);
          Stella.defineFunctionObject("DERIVE-DEFERRED-CONTRAPOSITIVE-SATELLITE-RULES", "(DEFUN DERIVE-DEFERRED-CONTRAPOSITIVE-SATELLITE-RULES ((SELF DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "deriveDeferredContrapositiveSatelliteRules", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description")}), null);
          Stella.defineFunctionObject("GET-INFERABLE-COMPLEMENT-DESCRIPTION", "(DEFUN (GET-INFERABLE-COMPLEMENT-DESCRIPTION DESCRIPTION) ((SELF DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "getInferableComplementDescription", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description")}), null);
          Stella.defineFunctionObject("DERIVE-IMPLIES-FROM-FORALL", "(DEFUN (DERIVE-IMPLIES-FROM-FORALL PROPOSITION) ((FORALLPROP PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "deriveImpliesFromForall", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("DECONSTRUCT-FORALL-TREE", "(DEFUN (DECONSTRUCT-FORALL-TREE CONS OBJECT CONS) ((FORALLTREE CONS)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "deconstructForallTree", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("[Ljava.lang.Object;")}), null);
          Stella.defineFunctionObject("REMOVE-EXISTS-VARIABLE", "(DEFUN (REMOVE-EXISTS-VARIABLE CONS) ((EXISTSPROPOSITION CONS) (VARIABLE SYMBOL)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "removeExistsVariable", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Symbol")}), null);
          Stella.defineFunctionObject("CREATE-FORWARD-CHAINING-INDEX", "(DEFUN (CREATE-FORWARD-CHAINING-INDEX FORWARD-CHAINING-INDEX) ((GOAL PROPOSITION) (MASTERFORALL PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "createForwardChainingIndex", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("DERIVE-COMPLEX-FORWARD-RULE", "(DEFUN DERIVE-COMPLEX-FORWARD-RULE ((GOAL PROPOSITION) (MASTERFORALL PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "deriveComplexForwardRule", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition"), Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("HELP-GET-FORWARD-CHAINING-RULES", "(DEFUN (HELP-GET-FORWARD-CHAINING-RULES (CONS OF PROPOSITION)) ((DESCRIPTION DESCRIPTION)))", Native.find_java_method("edu.isi.powerloom.logic.Description", "helpGetForwardChainingRules", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Description")}), null);
          Stella.defineFunctionObject("CALL-GET-RULES", "(DEFUN (CALL-GET-RULES (CONS OF PROPOSITION)) ((RELATIONREF OBJECT)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "callGetRules", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("GET-RULES", "(DEFUN (GET-RULES (CONS OF PROPOSITION)) ((RELATION NAME)) :DOCUMENTATION \"Return the list of rules associated with `relation'.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getRules", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("DELETE-RULES", "(DEFUN DELETE-RULES ((RELATION NAME)) :DOCUMENTATION \"Delete the list of rules associated with `relation'.\nThis function is included mainly for debugging purposes, when\na user wants to verify the behavior of different sets of rules.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "deleteRules", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("PRINT-RULES", "(DEFUN PRINT-RULES ((RELATION OBJECT)) :DOCUMENTATION \"Print the list of rules associated with `relation'.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "printRules", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("PRINT-SATELLITES", "(DEFUN PRINT-SATELLITES ((FORALLPROP PROPOSITION)))", Native.find_java_method("edu.isi.powerloom.logic.Proposition", "printSatellites", new java.lang.Class [] {Native.find_java_class("edu.isi.powerloom.logic.Proposition")}), null);
          Stella.defineFunctionObject("GET-RULE", "(DEFUN (GET-RULE PROPOSITION) ((RULENAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? TRUE)", Native.find_java_method("edu.isi.powerloom.logic.Logic", "getRule", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("FIND-RULE", "(DEFUN (FIND-RULE PROPOSITION) ((RULENAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Search for a rule named 'ruleName'.  Like 'get-rule',\nbut 'find-rule' implicity quotes its input argument.\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "findRule", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("ASSERT-RULE", "(DEFUN (ASSERT-RULE PROPOSITION) ((RULENAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Set the truth value of the rule named 'ruleName' to \nTRUE.  The proposition having the name 'ruleName' may be\nany arbitrary proposition, although we expect that it is probably\na material implication.  (See `retract-rule').\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "assertRule", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("RETRACT-RULE", "(DEFUN (RETRACT-RULE PROPOSITION) ((RULENAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"If it is currently TRUE, set the truth value \nof the rule named 'ruleName' to UNKNOWN  This\ncommand may be used alternately with `assert-rule' to\nobserve the effects of querying with or without a particular (named) rule\nbeing asserted within the current context. The proposition having the name\n'ruleName' may be any arbitrary proposition, although we expect that it is\nprobably a material implication.\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "retractRule", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
          Stella.defineFunctionObject("DELETE-RULE-CACHES-ON-RELATION", "(DEFUN DELETE-RULE-CACHES-ON-RELATION ((RELATION RELATION)))", Native.find_java_method("edu.isi.powerloom.logic.Logic", "deleteRuleCachesOnRelation", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Relation")}), null);
          Stella.defineFunctionObject("RESET-QUERY-CACHES", "(DEFUN RESET-QUERY-CACHES () :DOCUMENTATION \"Zero out all caches managed by the query optimizer,\nso that it will reoptimize subgoal queries upon next invocation.\")", Native.find_java_method("edu.isi.powerloom.logic.Logic", "resetQueryCaches", new java.lang.Class [] {}), null);
          Stella.defineFunctionObject("STARTUP-RULES", "(DEFUN STARTUP-RULES () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.powerloom.logic._StartupRules", "startupRules", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Logic.SYM_LOGIC_STARTUP_RULES);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Logic.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("_Startup-Rules"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LAZY-SATELLITE-RULES?* BOOLEAN TRUE :DOCUMENTATION \"If true, inversion of forall propositions happens lazily.\nI.e., satellite rules are generated on-demand during inference only if they\nare actually needed.\" :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *DERIVE-DEFERRED-SATELLITE-RULES-INVOCATIONS* (LIST OF DESCRIPTION) NULL)");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
