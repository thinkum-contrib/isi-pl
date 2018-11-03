//  -*- Mode: C++ -*-

// whynot.hh

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

// Class definitions:
class WhynotPartialMatch : public IncrementalPartialMatch {
// Variant of :BASIC partial match strategy to support WHYNOT queries.
public:
  int unknownGoalCutoff;
public:
  virtual Surrogate* primaryType();
  virtual QueryIterator* retrievePartialSolutions(QueryIterator* query);
  virtual double computePartialTruth(QueryIterator* query);
  virtual void initializePartialMatchStrategy(QueryIterator* query);
  virtual boolean skipAndClauseP(ControlFrame* frame, Cons* forbiddenvars);
  virtual double maxUnconstrainedFanout();
  virtual Keyword* continuePartialAntecedentsProof(Keyword* lastmove);
  virtual double chainingDepthDegradation();
  virtual Keyword* continuePartialAndProof(ControlFrame* frame, Keyword* lastmove);
  virtual double propositionWeight(Proposition* proposition);
  virtual boolean cutoffPartialMatchP(boolean traceP);
  virtual int numberOfFailedSubgoals();
  virtual int computeUnknownGoalCutoff();
  virtual void setDynamicCutoff();
  virtual PartialMatchFrame* createPartialMatchFrame(ControlFrame* frame, Keyword* kind);
};

class WhynotDeepPartialMatch : public WhynotPartialMatch {
// Variant of WhyNot partial match geared towards deep proofs.
public:
  virtual Surrogate* primaryType();
  virtual double maxUnconstrainedFanout();
  virtual double chainingDepthDegradation();
  virtual PartialMatchFrame* createPartialMatchFrame(ControlFrame* frame, Keyword* kind);
};

class WhynotProofClass : public Set {
// Set of equivalent WhyNot proofs that differ in at most one
// variable binding all on the same `deviating-variable'.
public:
  Justification* representative;
  Justification* deviatingPattern;
  PatternVariable* deviatingVariable;
  List* deviatingInstances;
public:
  virtual Surrogate* primaryType();
};

class AlternativeBindingsSet : public Thing {
// Represents a set of alternative bindings collected for the pattern
// variable `(the-variable self)'.
public:
  PatternVariable* theVariable;
  Set* bindings;
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
};


// Global declarations:
extern int oMIN_CLOCK_TICKS_PER_WHYNOT_ANTECEDENTo;
extern DECLARE_STELLA_SPECIAL(oMAX_WHYNOT_PROOF_CLASS_DEVIATIONSo, int );
extern int oSIMILAR_WHYNOT_PROOF_CUTOFFo;

// Function signatures:
WhynotPartialMatch* newWhynotPartialMatch(Keyword* kind, ControlFrame* controlFrame);
Object* accessWhynotPartialMatchSlotValue(WhynotPartialMatch* self, Symbol* slotname, Object* value, boolean setvalueP);
WhynotDeepPartialMatch* newWhynotDeepPartialMatch(Keyword* kind, ControlFrame* controlFrame);
boolean whynotPartialMatchModeP();
int computeNumberOfFailedSubgoals(Justification* proof);
boolean auxiliaryEquivalencePropositionP(Proposition* proposition);
int numberOfRemainingAntecedents(Iterator* iterator);
boolean betterWhynotProofP(Justification* proof1, Justification* proof2);
int computeProofDeviation(Justification* proof1, Justification* proof2, int maxdeviations, KeyValueList* deviations);
WhynotProofClass* newWhynotProofClass();
Object* accessWhynotProofClassSlotValue(WhynotProofClass* self, Symbol* slotname, Object* value, boolean setvalueP);
boolean insertWhynotProofToClassP(WhynotProofClass* clasS, Justification* proof);
WhynotProofClass* insertWhynotProof(List* classes, Justification* proof);
boolean betterWhynotProofClassP(WhynotProofClass* class1, WhynotProofClass* class2);
AlternativeBindingsSet* newAlternativeBindingsSet();
Object* accessAlternativeBindingsSetSlotValue(AlternativeBindingsSet* self, Symbol* slotname, Object* value, boolean setvalueP);
boolean alternativeBindingsSetP(Object* thing);
Set* alternativeBindings(AlternativeBindingsSet* bindingsset);
void postProcessWhynotProofClasses(List* classes);
void cutoffSimilarWhynotProofs(QueryIterator* query);
Cons* retrievalProofSolution(Justification* proof, QueryIterator* query);
void collectFailedGoals(Justification* proof, List* failures);
QueryIterator* deriveJustifiedPartialQuery(QueryIterator* query);
void whynot(Cons* args);
void whynotEvaluatorWrapper(Cons* arguments);
void explainWhynot(char* label, Keyword* style, int maxdepth, boolean summaryP, OutputStream* stream);
void printWhynotJustification(Justification* justification, OutputStream* stream, int maxdepth, Keyword* style, boolean summaryP);
List* getWhynotJustifications(QueryIterator* query, char* label, KeyValueList* mapping);
void helpStartupWhynot1();
void startupWhynot();

// Auxiliary global declarations:
extern Surrogate* SGT_WHYNOT_LOGIC_WHYNOT_PARTIAL_MATCH;
extern Symbol* SYM_WHYNOT_LOGIC_UNKNOWN_GOAL_CUTOFF;
extern Surrogate* SGT_WHYNOT_LOGIC_WHYNOT_DEEP_PARTIAL_MATCH;
extern Keyword* KWD_WHYNOT_AND;
extern Symbol* SYM_WHYNOT_STELLA_ARGUMENTS;
extern Symbol* SYM_WHYNOT_LOGIC_JUSTIFICATION;
extern Surrogate* SGT_WHYNOT_LOGIC_NUMBER_OF_FAILED_SUBGOALS_MEMO_TABLE_000;
extern Keyword* KWD_WHYNOT_EQUIVALENT;
extern Keyword* KWD_WHYNOT_ISA;
extern Keyword* KWD_WHYNOT_NOT;
extern Symbol* SYM_WHYNOT_LOGIC_WEIGHT;
extern Keyword* KWD_WHYNOT_DOWN;
extern Symbol* SYM_WHYNOT_LOGIC_REAL_ALLOTTED_CLOCK_TICKS;
extern Keyword* KWD_WHYNOT_UP_TRUE;
extern Keyword* KWD_WHYNOT_UP_FAIL;
extern Keyword* KWD_WHYNOT_GOAL_TREE;
extern Keyword* KWD_WHYNOT_MOVE_DOWN;
extern Keyword* KWD_WHYNOT_FAILURE;
extern Surrogate* SGT_WHYNOT_STELLA_CONS_ITERATOR;
extern Symbol* SYM_WHYNOT_LOGIC_ANTECEDENTS_RULE;
extern Symbol* SYM_WHYNOT_STELLA_ITERATOR;
extern Keyword* KWD_WHYNOT_SKIPPED_CONJUNCT;
extern Keyword* KWD_WHYNOT_POPPED;
extern Keyword* KWD_WHYNOT_MINIMUM_SCORE;
extern Keyword* KWD_WHYNOT_MAXIMUM_UNKNOWNS;
extern Symbol* SYM_WHYNOT_LOGIC_LATEST_POSITIVE_SCORE;
extern Symbol* SYM_WHYNOT_LOGIC_ALL_JUSTIFICATIONS;
extern Keyword* KWD_WHYNOT_MAXIMIZE_SCOREp;
extern Keyword* KWD_WHYNOT_PATTERN;
extern Surrogate* SGT_WHYNOT_LOGIC_WHYNOT_PROOF_CLASS;
extern Symbol* SYM_WHYNOT_LOGIC_REPRESENTATIVE;
extern Symbol* SYM_WHYNOT_LOGIC_DEVIATING_PATTERN;
extern Symbol* SYM_WHYNOT_LOGIC_DEVIATING_VARIABLE;
extern Symbol* SYM_WHYNOT_LOGIC_DEVIATING_INSTANCES;
extern Surrogate* SGT_WHYNOT_LOGIC_ALTERNATIVE_BINDINGS_SET;
extern Symbol* SYM_WHYNOT_LOGIC_THE_VARIABLE;
extern Symbol* SYM_WHYNOT_LOGIC_BINDINGS;
extern Symbol* SYM_WHYNOT_STELLA_SURROGATE_VALUE_INVERSE;
extern Keyword* KWD_WHYNOT_REALISTIC;
extern Keyword* KWD_WHYNOT_AND_INTRODUCTION;
extern Keyword* KWD_WHYNOT_MATCH_MODE;
extern Keyword* KWD_WHYNOT_WHYNOT;
extern Keyword* KWD_WHYNOT_JUSTIFICATIONS;
extern Keyword* KWD_WHYNOT_BRIEF;
extern Keyword* KWD_WHYNOT_NOT_ASSERTED;
extern Keyword* KWD_WHYNOT_NO_RULES;
extern Symbol* SYM_WHYNOT_LOGIC_STARTUP_WHYNOT;
extern Symbol* SYM_WHYNOT_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
