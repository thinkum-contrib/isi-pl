//  -*- Mode: C++ -*-

// justifications.hh

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
void recordClosedNotJustification(ControlFrame* frame, Keyword* lastmove);
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
void helpStartupJustifications2();
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
extern Surrogate* SGT_JUSTIFICATIONS_STELLA_KEY_VALUE_LIST;
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
extern Keyword* KWD_JUSTIFICATIONS_CLOSED_NOT_INTRODUCTION;
extern Keyword* KWD_JUSTIFICATIONS_FAIL;
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
