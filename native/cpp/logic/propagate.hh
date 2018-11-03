//  -*- Mode: C++ -*-

// propagate.hh

/*
 +---------------------------- BEGIN LICENSE BLOCK ---------------------------+
 |                                                                            |
 | Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          |
 |                                                                            |
 | The contents of this file are subject to the Mozilla Public License        |
 | Version 1.1 (the "License"); you may not use this file except in           |
 | compliance with the License. You may obtain a copy of the License at       |
 | http://www.mozilla.org/MPL/                                                |
 |                                                                            |
 | Software distributed under the License is distributed on an "AS IS" basis, |
 | WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   |
 | for the specific language governing rights and limitations under the       |
 | License.                                                                   |
 |                                                                            |
 | The Original Code is the PowerLoom KR&R System.                            |
 |                                                                            |
 | The Initial Developer of the Original Code is                              |
 | UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
 | 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
 |                                                                            |
 | Portions created by the Initial Developer are Copyright (C) 1997-2006      |
 | the Initial Developer. All Rights Reserved.                                |
 |                                                                            |
 | Contributor(s):                                                            |
 |                                                                            |
 | Alternatively, the contents of this file may be used under the terms of    |
 | either the GNU General Public License Version 2 or later (the "GPL"), or   |
 | the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   |
 | in which case the provisions of the GPL or the LGPL are applicable instead |
 | of those above. If you wish to allow use of your version of this file only |
 | under the terms of either the GPL or the LGPL, and not to allow others to  |
 | use your version of this file under the terms of the MPL, indicate your    |
 | decision by deleting the provisions above and replace them with the notice |
 | and other provisions required by the GPL or the LGPL. If you do not delete |
 | the provisions above, a recipient may use your version of this file under  |
 | the terms of any one of the MPL, the GPL or the LGPL.                      |
 |                                                                            |
 +----------------------------- END LICENSE BLOCK ----------------------------+
*/



namespace logic {
  using namespace stella;

// Global declarations:
extern DECLARE_STELLA_SPECIAL(oFILLINGCONSTRAINTPROPAGATIONQUEUESpo, boolean );
extern DECLARE_STELLA_SPECIAL(oDEFERINGDEFAULTFORWARDINFERENCESpo, boolean );
extern DECLARE_STELLA_SPECIAL(oCURRENTLYEXECUTINGFORWARDCHAININGQUEUEo, List* );
extern DECLARE_STELLA_SPECIAL(oCOLLECTFORWARDPROPOSITIONSo, Cons* );
extern boolean oJUST_IN_TIME_FORWARD_INFERENCEpo;

// Function signatures:
Cons* deferredDefaultPropositions(Context* self);
void deferredDefaultPropositionsSetter(Context* self, Cons* newvalue);
Keyword* evaluationState(Proposition* proposition);
void evaluationStateSetter(Proposition* proposition, Keyword* state);
void postForEvaluation(Proposition* self);
Cons* helpCollectForwardRules(Description* description, KeyValueList* rules, KeyValueList* indices, boolean toucheddefaultP, List* beenthere);
KeyValueList* collectForwardChainingRules(Description* description, KeyValueList*& _Return1);
boolean hasForwardChainingRulesP(Description* description, Proposition* proposition);
void postToForwardChainingQueue(Proposition* self, World* world);
void applyRuleConsequentToVector(Description* consequent, Vector* arguments, Proposition* rule, Description* triggerdescription, Proposition* triggerproposition, boolean toucheddefaultP);
void traceForwardRule(Proposition* rule, Proposition* trigger, Cons* consequents);
void applyForwardRulesToVector(Description* triggerdescription, Vector* arguments, Proposition* triggerproposition);
boolean applicableForwardRuleP(Proposition* rule, Vector* arguments);
void reactToKbUpdate(Context* context, Object* object);
void initializeConstraintPropagationQueues(World* world);
void executeConstraintPropagationQueues();
void evaluateNewProposition(Proposition* self);
void evaluateAndProposition(Proposition* self);
void evaluateOrProposition(Proposition* self);
void evaluateNotProposition(Proposition* self);
void evaluateEquivalentProposition(Proposition* self);
void equateEquivalentFunctionPropositions(Proposition* self);
void evaluateFunctionProposition(Proposition* self);
void evaluatePredicateProposition(Proposition* self);
void evaluateProposition(Proposition* self);
void recursivelyReactToInferenceUpdate(Proposition* self);
void elaborateMetaInstance(Object* self);
void elaborateInstance(Object* self);
void evaluateReachableInequalities(LogicObject* self, List* visitedlist);
void elaborateSurrogatesInProposition(Proposition* proposition);
void collectFunctionPropositionFacts(Proposition* self, List* facts, List* beenthere, boolean includeunknownP);
void helpCollectFacts(Object* self, List* facts, List* beenthere, boolean includeunknownP);
List* allFactsOfInstance(Object* self, boolean includeunknownfactsP, boolean elaborateP);
Cons* allFactsOf(Object* instanceref);
List* callAllFactsOf(Object* instanceref);
void retractFactsOfInstance(LogicObject* self);
void retractFactsOf(Object* instanceref);
List* explodeVariablizedString(char* string);
char* factToSentence(Proposition* self, boolean periodP);
Cons* allSentencesOf(Object* instanceref);
List* callAllFactsOfN(int n, Cons* seedrefs);
List* filteredAllFactsOfN(int n, Cons* seedrefs, cpp_function_code filter);
Cons* allFactsOfN(int n, Cons* instancerefs);
Cons* allFactsOfNEvaluatorWrapper(Cons* arguments);
void helpStartupPropagate1();
void helpStartupPropagate2();
void startupPropagate();

// Auxiliary global declarations:
extern Symbol* SYM_PROPAGATE_LOGIC_DEFERRED_DEFAULT_PROPOSITIONS_INTERNAL;
extern Symbol* SYM_PROPAGATE_LOGIC_EVALUATION_STATE_TABLE;
extern Keyword* KWD_PROPAGATE_POSTED;
extern Symbol* SYM_PROPAGATE_LOGIC_EVALUATION_QUEUE;
extern Keyword* KWD_PROPAGATE_FORWARD;
extern Symbol* SYM_PROPAGATE_LOGIC_BACKWARD_ONLYp;
extern Surrogate* SGT_PROPAGATE_LOGIC_NAMED_DESCRIPTION;
extern Symbol* SYM_PROPAGATE_LOGIC_FORWARD_ONLYp;
extern Surrogate* SGT_PROPAGATE_LOGIC_DESCRIPTION;
extern Surrogate* SGT_PROPAGATE_LOGIC_F_COLLECT_FORWARD_CHAINING_RULES_MEMO_TABLE_000;
extern Keyword* KWD_PROPAGATE_FUNCTION;
extern Symbol* SYM_PROPAGATE_LOGIC_FORWARD_CHAINING_QUEUE;
extern Keyword* KWD_PROPAGATE_ISA;
extern Keyword* KWD_PROPAGATE_PREDICATE;
extern Surrogate* SGT_PROPAGATE_LOGIC_SKOLEM;
extern Symbol* SYM_PROPAGATE_LOGIC_HYPOTHESIZED_INSTANCEp;
extern Keyword* KWD_PROPAGATE_PROPAGATE;
extern Surrogate* SGT_PROPAGATE_PL_KERNEL_KB_AND;
extern Keyword* KWD_PROPAGATE_GOAL_TREE;
extern Keyword* KWD_PROPAGATE_SINGLETONSp;
extern Surrogate* SGT_PROPAGATE_LOGIC_PROPOSITION;
extern Keyword* KWD_PROPAGATE_KB_UPDATE;
extern Keyword* KWD_PROPAGATE_META_KB_UPDATE;
extern Keyword* KWD_PROPAGATE_META;
extern Surrogate* SGT_PROPAGATE_STELLA_MODULE;
extern Surrogate* SGT_PROPAGATE_LOGIC_LOGIC_OBJECT;
extern Surrogate* SGT_PROPAGATE_STELLA_SYMBOL;
extern Keyword* KWD_PROPAGATE_EVALUATED;
extern Keyword* KWD_PROPAGATE_AND;
extern Keyword* KWD_PROPAGATE_OR;
extern Keyword* KWD_PROPAGATE_NOT;
extern Keyword* KWD_PROPAGATE_EQUIVALENT;
extern Symbol* SYM_PROPAGATE_LOGIC_ELABORATED_IN_WORLDS;
extern Keyword* KWD_PROPAGATE_ELABORATE;
extern Keyword* KWD_PROPAGATE_EXTENSIONAL_ASSERTION;
extern Surrogate* SGT_PROPAGATE_PL_KERNEL_KB_INEQUALITY;
extern Surrogate* SGT_PROPAGATE_STELLA_SURROGATE;
extern Keyword* KWD_PROPAGATE_EXISTS;
extern Keyword* KWD_PROPAGATE_FORALL;
extern Surrogate* SGT_PROPAGATE_STELLA_LITERAL_WRAPPER;
extern Symbol* SYM_PROPAGATE_LOGIC_DESCRIPTION;
extern Surrogate* SGT_PROPAGATE_STELLA_SLOT;
extern Surrogate* SGT_PROPAGATE_PL_KERNEL_KB_PHRASE;
extern Keyword* KWD_PROPAGATE_IMPLIES;
extern Symbol* SYM_PROPAGATE_LOGIC_STARTUP_PROPAGATE;
extern Symbol* SYM_PROPAGATE_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
