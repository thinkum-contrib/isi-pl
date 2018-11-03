//  -*- Mode: C++ -*-

// propagate.hh

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
extern Surrogate* SGT_PROPAGATE_LOGIC_DESCRIPTION;
extern Surrogate* SGT_PROPAGATE_LOGIC_COLLECT_FORWARD_CHAINING_RULES_MEMO_TABLE_000;
extern Keyword* KWD_PROPAGATE_FUNCTION;
extern Symbol* SYM_PROPAGATE_LOGIC_FORWARD_CHAINING_QUEUE;
extern Keyword* KWD_PROPAGATE_ISA;
extern Keyword* KWD_PROPAGATE_PREDICATE;
extern Surrogate* SGT_PROPAGATE_LOGIC_SKOLEM;
extern Symbol* SYM_PROPAGATE_LOGIC_HYPOTHESIZED_INSTANCEp;
extern Keyword* KWD_PROPAGATE_PROPAGATE;
extern Symbol* SYM_PROPAGATE_LOGIC_COMPLEMENT_DESCRIPTION;
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
