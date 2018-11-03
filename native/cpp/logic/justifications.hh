//  -*- Mode: C++ -*-

// justifications.hh

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
class Justification : public StandardObject {
public:
  // Keyword describing the inference rule used to conclude the
  // proposition of this justification.
  Keyword* inferenceRule;
  // The proposition supported by this justification.
  Proposition* proposition;
  // Antecedents justifications of this justification.
  Cons* antecedents;
  // Backpointer to the closest parent :PATTERN justification containing
  // the variable substitutions from the associated pattern control frame.  If this
  // is a :PATTERN justification, the slot points to the parent pattern.
  Justification* patternJustification;
  // List of variable bindings recorded for :PATTERN justifications.
  KeyValueList* substitution;
  // True if proposition was derived in reverse polarity.
  boolean reversePolarityP;
  // Truth value of the derived proposition.
  TruthValue* truthValue;
  // Positive partial match score of the derived proposition.
  double positiveScore;
  // Negative partial match score of the derived proposition.
  double negativeScore;
public:
  virtual Surrogate* primaryType();
  virtual Cons* consify();
  virtual Justification* copy();
  virtual Keyword* inferenceStrategy();
};

class PrimitiveStrategy : public Justification {
public:
  Keyword* strategy;
public:
  virtual Surrogate* primaryType();
  virtual Keyword* inferenceStrategy();
};

class ForwardGoalRecord : public StandardObject {
public:
  Proposition* forwardGoal;
  Proposition* forwardRule;
public:
  virtual Surrogate* primaryType();
  virtual boolean deletedPSetter(boolean value);
  virtual boolean deletedP();
};

class ForwardJustification : public StandardObject {
// Connects a proposition to other propositions
// that collectively implied its truth.
public:
  Proposition* consequent;
  Proposition* forwardRule;
  Cons* antecedents;
public:
  virtual Surrogate* primaryType();
};


// Global declarations:
extern DECLARE_STELLA_SPECIAL(oRECORD_JUSTIFICATIONSpo, boolean );

// Function signatures:
Justification* newJustification();
Object* accessJustificationSlotValue(Justification* self, Symbol* slotname, Object* value, boolean setvalueP);
PrimitiveStrategy* newPrimitiveStrategy();
Object* accessPrimitiveStrategySlotValue(PrimitiveStrategy* self, Symbol* slotname, Object* value, boolean setvalueP);
Object* justificationArgumentBoundTo(Object* argument, Justification* justification);
KeyValueList* yieldJustificationSubstitution(Justification* justification, KeyValueList* substitution, Proposition* argument);
boolean justificationEqlP(Justification* just1, Justification* just2);
boolean justificationPropositionsEqlP(Proposition* proposition1, Justification* just1, Proposition* proposition2, Justification* just2);
boolean recordJustificationsP();
void recordGoalJustification(ControlFrame* goal, Justification* justification);
void recordPrimitiveJustification(ControlFrame* frame, Keyword* lastmove);
void recordPatternJustification(ControlFrame* frame, Keyword* lastmove);
void backlinkToPatternJustification(Justification* justification, Justification* pattern);
void recordModusPonensJustification(ControlFrame* frame, Keyword* lastmove);
void recordAndIntroductionJustification(ControlFrame* frame, Keyword* lastmove);
void recordOrIntroductionJustification(ControlFrame* frame, Keyword* lastmove);
void recordDisproofJustification(ControlFrame* frame, Keyword* lastmove);
void recordFailJustification(ControlFrame* frame, Keyword* lastmove);
void recordExistentialIntroductionJustification(ControlFrame* frame, Keyword* lastmove);
boolean failedGoalJustificationP(Justification* self);
boolean cutoffGoalJustificationP(Justification* self);
Cons* consifyJustification(Justification* self, Keyword* style);
List* getQueryJustifications(QueryIterator* query, int solutionindex, int maxjustifications, boolean createP);
List* deriveQueryJustifications(QueryIterator* query, Object* options, int solutionindex, int maxjustifications);
ForwardGoalRecord* newForwardGoalRecord();
Object* accessForwardGoalRecordSlotValue(ForwardGoalRecord* self, Symbol* slotname, Object* value, boolean setvalueP);
void recordForwardGoal(Proposition* forwardrule, Vector* arguments, Proposition* consequentproposition);
boolean predicationP(Proposition* proposition);
boolean assertedAsTrueP(Proposition* proposition);
boolean elaborationRuleP(Proposition* consequentproposition, Proposition* forwardrule, Vector* arguments);
List* getForwardGoals(Proposition* proposition);
ForwardJustification* newForwardJustification();
Object* accessForwardJustificationSlotValue(ForwardJustification* self, Symbol* slotname, Object* value, boolean setvalueP);
ForwardJustification* createForwardJustification(Proposition* consequentproposition, Proposition* forwardrule, Cons* antecedents);
void recordForwardJustification(Proposition* consequentproposition, Proposition* forwardrule, Cons* antecedents);
void helpStartupJustifications1();
void startupJustifications();

// Auxiliary global declarations:
extern Surrogate* SGT_JUSTIFICATIONS_LOGIC_JUSTIFICATION;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_INFERENCE_RULE;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_PROPOSITION;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_ANTECEDENTS;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_PATTERN_JUSTIFICATION;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_SUBSTITUTION;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_REVERSE_POLARITYp;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_TRUTH_VALUE;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_POSITIVE_SCORE;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_NEGATIVE_SCORE;
extern Keyword* KWD_JUSTIFICATIONS_PRIMITIVE_STRATEGY;
extern Surrogate* SGT_JUSTIFICATIONS_LOGIC_PRIMITIVE_STRATEGY;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_STRATEGY;
extern Surrogate* SGT_JUSTIFICATIONS_LOGIC_PATTERN_VARIABLE;
extern Keyword* KWD_JUSTIFICATIONS_PATTERN;
extern Surrogate* SGT_JUSTIFICATIONS_LOGIC_PROPOSITION;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION;
extern Keyword* KWD_JUSTIFICATIONS_UP_TRUE;
extern Keyword* KWD_JUSTIFICATIONS_UP_FAIL;
extern Keyword* KWD_JUSTIFICATIONS_FAILURE;
extern Keyword* KWD_JUSTIFICATIONS_SCAN_COLLECTION;
extern Keyword* KWD_JUSTIFICATIONS_TECHNICAL;
extern Keyword* KWD_JUSTIFICATIONS_SCAN_PROPOSITIONS;
extern Keyword* KWD_JUSTIFICATIONS_LOOKUP_ASSERTIONS;
extern Keyword* KWD_JUSTIFICATIONS_LAY;
extern Keyword* KWD_JUSTIFICATIONS_SPECIALIST;
extern Keyword* KWD_JUSTIFICATIONS_COMPUTED_PREDICATE;
extern Keyword* KWD_JUSTIFICATIONS_GOAL_COMPLEMENT;
extern Keyword* KWD_JUSTIFICATIONS_EQUIVALENCE;
extern Keyword* KWD_JUSTIFICATIONS_SUBSUMPTION_TEST;
extern Surrogate* SGT_JUSTIFICATIONS_LOGIC_PATTERN_RECORD;
extern Keyword* KWD_JUSTIFICATIONS_MODUS_TOLLENS;
extern Keyword* KWD_JUSTIFICATIONS_MODUS_PONENS;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_ANTECEDENTS_RULE;
extern Keyword* KWD_JUSTIFICATIONS_NOT;
extern Keyword* KWD_JUSTIFICATIONS_AMPLIFICATION;
extern Symbol* SYM_JUSTIFICATIONS_STELLA_ARGUMENTS;
extern Keyword* KWD_JUSTIFICATIONS_POPPED;
extern Keyword* KWD_JUSTIFICATIONS_AND_INTRODUCTION;
extern Keyword* KWD_JUSTIFICATIONS_PARTIAL;
extern Keyword* KWD_JUSTIFICATIONS_REVERSE;
extern Keyword* KWD_JUSTIFICATIONS_OR_INTRODUCTION;
extern Keyword* KWD_JUSTIFICATIONS_DISPROOF;
extern Keyword* KWD_JUSTIFICATIONS_FAIL_INTRODUCTION;
extern Keyword* KWD_JUSTIFICATIONS_EXISTENTIAL_INTRODUCTION;
extern Keyword* KWD_JUSTIFICATIONS_TIMEOUT;
extern Keyword* KWD_JUSTIFICATIONS_DEPTH_CUTOFF;
extern Keyword* KWD_JUSTIFICATIONS_RAW;
extern Keyword* KWD_JUSTIFICATIONS_INFERENCE_RULE;
extern Keyword* KWD_JUSTIFICATIONS_STRATEGY;
extern Keyword* KWD_JUSTIFICATIONS_TRUTH_VALUE;
extern Keyword* KWD_JUSTIFICATIONS_POSITIVE_SCORE;
extern Keyword* KWD_JUSTIFICATIONS_SUBSTITUTION;
extern Symbol* SYM_JUSTIFICATIONS_STELLA_NOT;
extern Keyword* KWD_JUSTIFICATIONS_HOW_MANY;
extern Keyword* KWD_JUSTIFICATIONS_NONE;
extern Surrogate* SGT_JUSTIFICATIONS_LOGIC_FORWARD_GOAL_RECORD;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_FORWARD_GOAL;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_FORWARD_RULE;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_FORWARD_CHAINING_GOALS;
extern Symbol* SYM_JUSTIFICATIONS_STELLA_PREDICATE;
extern Surrogate* SGT_JUSTIFICATIONS_PL_KERNEL_KB_HOLDS;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_MASTER_PROPOSITION;
extern Surrogate* SGT_JUSTIFICATIONS_LOGIC_FORWARD_JUSTIFICATION;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_CONSEQUENT;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_FORWARD_JUSTIFICATIONS;
extern Symbol* SYM_JUSTIFICATIONS_LOGIC_STARTUP_JUSTIFICATIONS;
extern Symbol* SYM_JUSTIFICATIONS_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
