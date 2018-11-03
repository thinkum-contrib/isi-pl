//  -*- Mode: C++ -*-

// rule-induction.hh

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
class DecisionTree : public StandardObject {
public:
  Symbol* feature;
  int featureIndex;
  Proposition* proposition;
  boolean truthValue;
  Symbol* concept;
  DecisionTree* trueBranch;
  DecisionTree* falseBranch;
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
};


// Global declarations:
extern Keyword* oRULE_INDUCTION_STRATEGYo;
extern Keyword* oSIGNATURE_STRATEGYo;
extern boolean oENABLE_USER_THINGo;
extern boolean oOPTIMIZE_INDUCED_QUERIESo;
extern boolean oSIMPLIFY_RULE_ANTECEDENTpo;
extern boolean oTRACE_ID3o;
extern boolean oTRACE_FOILo;
extern boolean oINDUCE_RULES_FROM_SIGNATURESo;
extern int oNUM_LGGSo;
extern boolean oENFORCE_LINKED_VARIABLESo;
extern boolean oLOG_INDUCED_RULESo;
extern boolean oALLOW_RECURSIVE_DECISION_NODESo;
extern boolean oLOG_DECISION_RULE_CONSTRUCTIONo;
extern double LOG_2;
extern List* oINDUCED_DECISION_RULESo;
extern int oINDUCED_RULE_COUNTERo;
extern Vector* oCANDIDATE_CLAUSESo;
extern DECLARE_STELLA_SPECIAL(oBOTTOM_UP_VARIABLE_COUNTERo, int );

// Function signatures:
void setSignatureStrategy(Keyword* k);
void setSignatureRules(boolean b);
void setSignatureRulesEvaluatorWrapper(Cons* arguments);
void setRuleInductionStrategy(Keyword* k);
void setRecursiveDecisionNodes(boolean b);
void setRecursiveDecisionNodesEvaluatorWrapper(Cons* arguments);
DecisionTree* newDecisionTree();
Object* accessDecisionTreeSlotValue(DecisionTree* self, Symbol* slotname, Object* value, boolean setvalueP);
void induceInferenceRules(Symbol* relationName, Symbol* className);
void modularInduceInferenceRules(Symbol* relationName, Symbol* className, List* modules);
void bottomUpRuleInduction(List* examples, boolean simplifyRuleP);
void bottomUpRuleInductionEvaluatorWrapper(Cons* arguments);
Cons* learnOneRuleBottomUp(List* positive, List* negative);
boolean containsOutputVariableP(Cons* clause, Cons* outputVariables);
Cons* simplifyAntecedent(Cons* antecedent, Cons* outputVariables, List* positive, List* negative);
Cons* leastGeneralGeneralization(Cons* clause1, Cons* clause2);
Cons* generalizeInequality(Cons* probe, Cons* match, List* bindings);
boolean bothNumbersP(Object* t1, Object* t2);
boolean eitherNumbersP(Object* t1, Object* t2);
Cons* removeRedundantClauses(Cons* clauses);
Object* lookupVariableInBindings(Object* obj1, Object* obj2, List* bindings);
Cons* learnOneRuleBottomUpFromSignatures(List* positive, List* negative, List* covered, Vector* consProps);
List* intersectSignatures(Vector* sig1, Vector* sig2);
List* removeSignatureCoveredExamples(List* indices, List* examples);
int numSignatureIndicesCovered(List* indices, List* examples);
boolean signatureIndicesCoverAnyExampleP(List* indices, List* examples);
boolean signatureIndicesCoverExampleP(List* indices, TrainingExample* example);
void topDownRuleInduction(List* examples);
Cons* buildAntecedentFromRuleIndex(Vector* props, List* ruleIndex);
Cons* learnOneRuleTopDownFromSignatures(List* positive, List* negative, List* covered_pos, Vector* consProps);
void updateExampleMatches(List* examples, int index, IntegerWrapper* matchValue);
void updateCoveredExamples(int feature_index, List* covered_pos, List* covered_neg);
int countExampleMatches(List* examples, int index, IntegerWrapper* matchValue);
double foilGain(int featureIndex, double utility, List* coveredPos, List* coveredNeg);
double foilUtility(int p, int n);
Cons* learnOneRuleTopDown(Vector* propositions, List* positive, List* negative);
Cons* specializeRule(Cons* rule, Vector* propositions, List* positive, List* negative);
void removeExcludedExamples(Cons* rule, List* coveredPos, List* coveredNeg);
double queryFoilGain(Cons* rule, double utility, List* coveredPos, List* coveredNeg);
void queryAndUpdateCoveredExamples(Cons* rule, List* uncovered, List* covered);
void removeCoveredExamples(Cons* rule, List* uncovered);
int numExamplesCovered(Cons* rule, List* examples);
List* getCoveredExamples(Cons* rule, List* uncovered);
boolean ruleCoversAnyExampleP(Cons* rule, List* examples);
boolean ruleCoversExampleP(Cons* reverseRule, TrainingExample* example);
List* linkVariablesInInducedRule(Cons* rule, List* examples, Vector* consProps);
Vector* evaluateRuleInduction(Symbol* relationName, Symbol* className, int numTrials, int curveSplits);
Vector* evaluateRuleInductionEvaluatorWrapper(Cons* arguments);
double trainAndTestRuleInduction(List* trainSet, List* testSet);
void induceDecisionRules(Symbol* relationName, Symbol* className);
void modularInduceDecisionRules(Symbol* relationName, Symbol* className, List* modules);
boolean askDecisionTree(DecisionTree* tree, Cons* query);
boolean traverseDecisionTree(DecisionTree* tree, Vector* features);
DecisionTree* induceDecisionTree(List* examples);
void addPropositionsToDecisionTree(DecisionTree* tree, HashTable* table);
Object* buildDecisionTree(List* examples, List* features, Cons* featureStack);
double expectedEntropy(int featureIndex, List* examples);
double entropy(int p, int n);
void printDecisionTree(DecisionTree* tree, std::ostream* stream);
void helpPrintDecisionTree(DecisionTree* tree, int level, std::ostream* stream);
List* getRulesFromTree(Cons* query, DecisionTree* tree);
List* buildRulesFromTree(DecisionTree* tree, List* props);
void extractPathsFromTree(DecisionTree* tree, Cons* antecedentStack, List* antecedent);
void sortExamplesByTree(DecisionTree* tree, List* examples, List* sortedExamples);
void assertInducedRules();
void setCandidateClauses(Symbol* className);
List* getVariablesFromPropositionList(List* props);
List* getVariablesFromConsPropositions(Cons* props);
List* helpGetVariablesFromConsPropositions(Object* ele, List* theList);
List* getPropositionsFromDecisionTree(DecisionTree* tree);
void helpStartupRuleInduction1();
void helpStartupRuleInduction2();
void helpStartupRuleInduction3();
void startupRuleInduction();

// Auxiliary global declarations:
extern Keyword* KWD_RULE_INDUCTION_TOP_DOWN;
extern Surrogate* SGT_RULE_INDUCTION_LOGIC_DECISION_TREE;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_FEATURE;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_FEATURE_INDEX;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_PROPOSITION;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_TRUTH_VALUE;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_CONCEPT;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_TRUE_BRANCH;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_FALSE_BRANCH;
extern Keyword* KWD_RULE_INDUCTION_BOTTOM_UP;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_pY;
extern Symbol* SYM_RULE_INDUCTION_STELLA_eg;
extern Symbol* SYM_RULE_INDUCTION_STELLA_AND;
extern Surrogate* SGT_RULE_INDUCTION_STELLA_CONS;
extern Symbol* SYM_RULE_INDUCTION_STELLA_NOT;
extern Symbol* SYM_RULE_INDUCTION_STELLA_g;
extern Symbol* SYM_RULE_INDUCTION_STELLA_l;
extern Symbol* SYM_RULE_INDUCTION_STELLA_ge;
extern Symbol* SYM_RULE_INDUCTION_STELLA_el;
extern Surrogate* SGT_RULE_INDUCTION_STELLA_NUMBER_WRAPPER;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_FAIL;
extern Keyword* KWD_RULE_INDUCTION_DECISION_TREE;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_USER_THING;
extern Symbol* SYM_RULE_INDUCTION_STELLA_EXISTS;
extern Keyword* KWD_RULE_INDUCTION_TIMEOUT;
extern Keyword* KWD_RULE_INDUCTION_DONT_OPTIMIZEp;
extern Symbol* SYM_RULE_INDUCTION_STELLA_TRUE;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_DEFRULE;
extern Symbol* SYM_RULE_INDUCTION_STELLA_FORALL;
extern Keyword* KWD_RULE_INDUCTION_OR;
extern Keyword* KWD_RULE_INDUCTION_NOT;
extern Keyword* KWD_RULE_INDUCTION_AND;
extern Surrogate* SGT_RULE_INDUCTION_LOGIC_PATTERN_VARIABLE;
extern Surrogate* SGT_RULE_INDUCTION_LOGIC_PROPOSITION;
extern Surrogate* SGT_RULE_INDUCTION_LOGIC_LOGIC_OBJECT;
extern Symbol* SYM_RULE_INDUCTION_LOGIC_STARTUP_RULE_INDUCTION;
extern Symbol* SYM_RULE_INDUCTION_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
