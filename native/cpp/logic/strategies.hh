//  -*- Mode: C++ -*-

// strategies.hh

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


namespace logic {
  using namespace stella;

// Class definitions:
class ConditionalAntecedentProofAdjunct : public ProofAdjunct {
public:
  Proposition* provableRule;
  Proposition* goal;
  Keyword* phase;
public:
  virtual Surrogate* primaryType();
};

class ClusteredConjunctionProofAdjunct : public ProofAdjunct {
public:
  Vector* clusterFrames;
public:
  virtual Surrogate* primaryType();
};


// Global declarations:
extern List* oPARALLEL_STRATEGIESo;
extern int oFAILED_GOAL_CUTOFFSo;
extern int oSUCCEEDED_GOAL_CUTOFFSo;

// Function signatures:
Keyword* continueStrategiesProofs(ControlFrame* frame, Keyword* lastmove);
void clearStrategySlots(ControlFrame* frame);
ControlFrame* selectNextStrategy(ControlFrame* frame);
void recordBasePartialMatchTruth(ControlFrame* frame, Keyword* result);
Keyword* continueCurrentOrNextStrategy(ControlFrame* frame);
Keyword* resumeProofStrategyAfterSubgoal(ControlFrame* frame, Keyword* lastmove);
boolean filterOutStrategyP(Keyword* strategy, ControlFrame* frame);
Keyword* executeProofStrategy(ControlFrame* frame);
Keyword* continueParallelStrategiesProofs(ParallelControlFrame* pframe, Keyword* lastmove);
boolean parallelStrategyP(Keyword* strategy);
ParallelThread* selectNextChildThread(ParallelControlFrame* pframe);
ParallelThread* createChildThread(ParallelControlFrame* pframe);
Keyword* tryParallelThreadProof(ControlFrame* frame);
void pushNextStrategy(ControlFrame* frame, Keyword* strategy);
ControlFrame* createSubgoalFrame(ControlFrame* upframe, Proposition* goal, Keyword* strategy);
Keyword* continueSpecialistProof(ControlFrame* frame, Keyword* lastmove);
Keyword* lookupCachedProof(ControlFrame* frame);
Keyword* scanCachedGoals(ControlFrame* frame);
Keyword* finishCachedGoalProcessing(AtomicGoalCache* cachedgoal, ControlFrame* frame, Keyword* successorfailure, boolean continuingP);
Keyword* tryGoalCachesProof(ControlFrame* frame);
Keyword* tryLookupGroundAssertionsProof(ControlFrame* frame);
Keyword* tryScanPropositionsProof(ControlFrame* frame);
boolean hasShallowDisproofP(ControlFrame* frame);
Keyword* tryShallowDisproof(ControlFrame* frame);
Keyword* tryScanForValueClashProof(ControlFrame* frame);
Keyword* tryManufactureSkolemProof(ControlFrame* frame);
Proposition* extractSubgoalOfFrame(ControlFrame* frame);
Description* extractSubgoalDescriptionOfFrame(ControlFrame* frame);
Vector* findExternalArgumentsForSubgoal(ControlFrame* frame);
Keyword* trySubgoalStrategiesProof(ControlFrame* frame);
void establishGoalCache(ControlFrame* frame);
boolean checkForDuplicateRuleP(ControlFrame* frame, Proposition* impliesproposition);
Keyword* continueAntecedentsProof(ControlFrame* frame, Keyword* lastmove);
Iterator* allocateAntecedentsIterator(Description* goaldescription, Vector* externalarguments, boolean reversepolarityP);
Cons* optimizeOrderOfApplicableRules(Cons* rules, boolean tailP);
Keyword* tryGoalComplementProof(ControlFrame* frame);
Keyword* tryForwardGoalsProof(ControlFrame* frame);
ConditionalAntecedentProofAdjunct* newConditionalAntecedentProofAdjunct();
Object* accessConditionalAntecedentProofAdjunctSlotValue(ConditionalAntecedentProofAdjunct* self, Symbol* slotname, Object* value, boolean setvalueP);
ControlFrame* createConditionalAntecedentSubframe(ControlFrame* frame, Proposition* goal, Proposition* provablerule);
Keyword* continueConditionalAntecedentProof(ControlFrame* frame, Keyword* lastmove);
Keyword* tryFullSubqueryProof(ControlFrame* frame);
NamedDescription* extractCollectionArgument(Proposition* proposition);
Keyword* tryIsaPropositionProof(ControlFrame* frame);
Keyword* tryScanCollectionProof(ControlFrame* frame);
boolean inferableDescriptionP(Object* self);
Keyword* tryImpliesProof(ControlFrame* frame);
Keyword* trySimpleContainedByProof(Object* subcollection, Object* supercollection, boolean reversepolarityP);
Keyword* tryContainedByProof(ControlFrame* upframe);
Proposition* createContainedByArgument(Object* collection, List* bridgeargs);
Keyword* continueContainedByProof(ControlFrame* frame, Keyword* lastmove);
Keyword* trySubsumptionTest(ControlFrame* frame);
Keyword* tryEquivalenceProof(ControlFrame* frame);
ClusteredConjunctionProofAdjunct* newClusteredConjunctionProofAdjunct();
Object* accessClusteredConjunctionProofAdjunctSlotValue(ClusteredConjunctionProofAdjunct* self, Symbol* slotname, Object* value, boolean setvalueP);
Keyword* continueClusteredConjunctionProof(ControlFrame* andframe, Keyword* lastmove);
World* pushMonotonicWorld();
Keyword* tryDisjunctiveImplicationProof(ControlFrame* frame);
Skolem* createHypothesizedSkolem(char* prefix);
Keyword* tryUniversalIntroductionProof(ControlFrame* frame);
Keyword* tryRefutationProof(ControlFrame* frame);
Keyword* continueForallProof(ControlFrame* frame, Keyword* lastmove);
Keyword* continueExistsProof(ControlFrame* frame, Keyword* lastmove);
Keyword* continueConstantProof(ControlFrame* frame, Keyword* lastmove);
void registerInferenceCutoff(ControlFrame* frame, Keyword* reason);
Keyword* continueFailProof(ControlFrame* frame, Keyword* lastmove);
void helpStartupStrategies1();
void helpStartupStrategies2();
void helpStartupStrategies3();
void startupStrategies();

// Auxiliary global declarations:
extern Keyword* KWD_STRATEGIES_DOWN;
extern Keyword* KWD_STRATEGIES_MOVE_DOWN;
extern Keyword* KWD_STRATEGIES_UP_TRUE;
extern Keyword* KWD_STRATEGIES_UP_FAIL;
extern Keyword* KWD_STRATEGIES_FAILURE;
extern Keyword* KWD_STRATEGIES_FINAL_SUCCESS;
extern Keyword* KWD_STRATEGIES_CONTINUING_SUCCESS;
extern Keyword* KWD_STRATEGIES_GOAL_TREE;
extern Symbol* SYM_STRATEGIES_LOGIC_JUSTIFICATION;
extern Keyword* KWD_STRATEGIES_TERMINAL_FAILURE;
extern Symbol* SYM_STRATEGIES_STELLA_ITERATOR;
extern Symbol* SYM_STRATEGIES_LOGIC_ANTECEDENTS_RULE;
extern Symbol* SYM_STRATEGIES_LOGIC_PROOF_ADJUNCT;
extern Keyword* KWD_STRATEGIES_PARALLEL_STRATEGIES;
extern Keyword* KWD_STRATEGIES_SELECT_PARALLEL_THREAD;
extern Keyword* KWD_STRATEGIES_FAIL;
extern Keyword* KWD_STRATEGIES_TRUE;
extern Keyword* KWD_STRATEGIES_STRATEGIES;
extern Symbol* SYM_STRATEGIES_LOGIC_DESCRIPTION;
extern Keyword* KWD_STRATEGIES_MOVE_IN_PLACE;
extern Keyword* KWD_STRATEGIES_TIME_OUT;
extern Keyword* KWD_STRATEGIES_SPECIALIST;
extern Keyword* KWD_STRATEGIES_ANTECEDENTS;
extern Keyword* KWD_STRATEGIES_CLUSTERED_CONJUNCTION;
extern Keyword* KWD_STRATEGIES_CONDITIONAL_ANTECEDENT;
extern Keyword* KWD_STRATEGIES_ATOMIC_GOAL;
extern Keyword* KWD_STRATEGIES_DUMMY_JUSTIFICATION;
extern Keyword* KWD_STRATEGIES_LOOKUP_GOAL_CACHES;
extern Symbol* SYM_STRATEGIES_LOGIC_CHECK_FOR_CACHED_GOALSp;
extern Keyword* KWD_STRATEGIES_DUPLICATE_GOALS;
extern Keyword* KWD_STRATEGIES_MANUFACTURE_SKOLEM;
extern Surrogate* SGT_STRATEGIES_PL_KERNEL_KB_TOTAL;
extern Keyword* KWD_STRATEGIES_LOOKUP_ASSERTIONS;
extern Keyword* KWD_STRATEGIES_SCAN_PROPOSITIONS;
extern Keyword* KWD_STRATEGIES_SCAN_PARTIAL_PROPOSITIONS;
extern Keyword* KWD_STRATEGIES_SCAN_COLLECTION;
extern Keyword* KWD_STRATEGIES_SHALLOW_DISPROOF;
extern Keyword* KWD_STRATEGIES_SCAN_FOR_VALUE_CLASH;
extern Keyword* KWD_STRATEGIES_ALL_SUBGOAL_STRATEGIES;
extern Keyword* KWD_STRATEGIES_FULL_SUBQUERY;
extern Keyword* KWD_STRATEGIES_GOAL_COMPLEMENT;
extern Keyword* KWD_STRATEGIES_FORWARD_GOALS;
extern Keyword* KWD_STRATEGIES_IMPLIES;
extern Keyword* KWD_STRATEGIES_CONTAINED_BY;
extern Keyword* KWD_STRATEGIES_EQUIVALENCE;
extern Keyword* KWD_STRATEGIES_DISJUNCTIVE_IMPLICATION_INTRODUCTION;
extern Keyword* KWD_STRATEGIES_UNIVERSAL_INTRODUCTION;
extern Keyword* KWD_STRATEGIES_SUBSUMPTION_TEST;
extern Keyword* KWD_STRATEGIES_REFUTATION;
extern Keyword* KWD_STRATEGIES_STRATEGY;
extern Keyword* KWD_STRATEGIES_SUCCESS;
extern Symbol* SYM_STRATEGIES_LOGIC_LATEST_POSITIVE_SCORE;
extern Keyword* KWD_STRATEGIES_GOAL_CACHES;
extern Keyword* KWD_STRATEGIES_ISA;
extern Surrogate* SGT_STRATEGIES_LOGIC_WHYNOT_PARTIAL_MATCH;
extern Keyword* KWD_STRATEGIES_FUNCTION;
extern Symbol* SYM_STRATEGIES_LOGIC_WEIGHT;
extern Surrogate* SGT_STRATEGIES_PL_KERNEL_KB_MEMBER_OF;
extern Surrogate* SGT_STRATEGIES_STELLA_LIST;
extern Keyword* KWD_STRATEGIES_FORWARD;
extern Keyword* KWD_STRATEGIES_DUPLICATE_;
extern Keyword* KWD_STRATEGIES_BACKWARD;
extern Symbol* SYM_STRATEGIES_LOGIC_BACKWARD_ONLYp;
extern Symbol* SYM_STRATEGIES_LOGIC_FORWARD_ONLYp;
extern Surrogate* SGT_STRATEGIES_LOGIC_DESCRIPTION;
extern Keyword* KWD_STRATEGIES_FORWARD_RULE;
extern Surrogate* SGT_STRATEGIES_LOGIC_CONDITIONAL_ANTECEDENT_PROOF_ADJUNCT;
extern Symbol* SYM_STRATEGIES_LOGIC_PROVABLE_RULE;
extern Symbol* SYM_STRATEGIES_LOGIC_GOAL;
extern Symbol* SYM_STRATEGIES_STELLA_PHASE;
extern Keyword* KWD_STRATEGIES_ORIGINAL_GOAL;
extern Surrogate* SGT_STRATEGIES_STELLA_LITERAL_WRAPPER;
extern Symbol* SYM_STRATEGIES_LOGIC_COMPLEMENT_DESCRIPTION;
extern Symbol* SYM_STRATEGIES_LOGIC_CONTAINED_BY;
extern Surrogate* SGT_STRATEGIES_LOGIC_NAMED_DESCRIPTION;
extern Symbol* SYM_STRATEGIES_STELLA_ISA;
extern Symbol* SYM_STRATEGIES_STELLA_PREDICATE;
extern Keyword* KWD_STRATEGIES_LOCAL;
extern Symbol* SYM_STRATEGIES_LOGIC_BACK;
extern Keyword* KWD_STRATEGIES_POPPED;
extern Symbol* SYM_STRATEGIES_LOGIC_EXTERNAL_VARIABLES;
extern Surrogate* SGT_STRATEGIES_LOGIC_CLUSTERED_CONJUNCTION_PROOF_ADJUNCT;
extern Symbol* SYM_STRATEGIES_LOGIC_CLUSTER_FRAMES;
extern Keyword* KWD_STRATEGIES_AND;
extern Keyword* KWD_STRATEGIES_PREDICATE;
extern Symbol* SYM_STRATEGIES_LOGIC_MONOTONICp;
extern Keyword* KWD_STRATEGIES_NOT;
extern Symbol* SYM_STRATEGIES_LOGIC_HYPOTHESIZED_INSTANCEp;
extern Symbol* SYM_STRATEGIES_LOGIC_IO_VARIABLES;
extern Keyword* KWD_STRATEGIES_ITERATIVE_FORALL;
extern Keyword* KWD_STRATEGIES_NORMAL;
extern Keyword* KWD_STRATEGIES_CONSTANT_PROPOSITION;
extern Keyword* KWD_STRATEGIES_TECHNICAL;
extern Keyword* KWD_STRATEGIES_LAY;
extern Symbol* SYM_STRATEGIES_LOGIC_INFERENCE_CUTOFF_REASON;
extern Symbol* SYM_STRATEGIES_LOGIC_STARTUP_STRATEGIES;
extern Symbol* SYM_STRATEGIES_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
