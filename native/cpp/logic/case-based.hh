//  -*- Mode: C++ -*-

// case-based.hh

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

// Global declarations:
extern boolean oLOG_MATCH_RULESo;
extern boolean oLOG_ANTECEDENT_CONSTRUCTIONo;
extern int oNUM_NEIGHBORSo;
extern Keyword* oCASE_SOLUTION_COMBINATIONo;
extern List* oCASE_RULE_NAMESo;
extern int oNUM_CASESo;
extern int oNUM_TRAINING_PER_CASEo;
extern int oCASE_VARIABLE_COUNTERo;
extern int oBASE_COUNTERo;
extern List* oVISITED_INSTANCESo;
extern boolean oONLY_VARIABLIZE_VISITED_INSTANCESo;
extern List* oVISITED_PROPOSITIONSo;
extern List* oSEEN_INSTANCESo;
extern List* oDELETED_CASE_VARIABLESo;
extern HashTable* oSYMBOL_VARIABLE_HASH_TABLEo;
extern StringHashTable* oCASE_ANTECEDENT_TABLEo;
extern StringHashTable* oCASE_TYPES_TABLEo;
extern HashTable* oCASE_NAME_TABLEo;
extern boolean oPRINT_CASE_DISTANCESo;

// Function signatures:
void setNumNeighbors(int d);
void setNumNeighborsEvaluatorWrapper(Cons* arguments);
void setCaseSolutionCombination(Keyword* k);
void setNumTrainingPerCase(int d);
void setNumTrainingPerCaseEvaluatorWrapper(Cons* arguments);
void clearCases();
void addAllClassInstancesToCaseRule(Surrogate* kind);
void finalizeCases(Symbol* kind);
void buildCaseRule(Surrogate* kind);
void addCase(Symbol* inst, Symbol* kind);
void buildCaseFromInstance(LogicObject* inst, Surrogate* kind);
Vector* createCaseInstanceVector(Surrogate* clasS);
FloatWrapper* matchInstances(LogicObject* x, LogicObject* y);
Vector* createCaseValueVector(List* instances, Surrogate* slot);
Object* guess(Symbol* instName, Symbol* slotName);
Object* generateCaseBasedAnswer(LogicObject* probe, Surrogate* slot, List* cases);
Object* combineCaseAnswers(Vector* closest, Vector* scores, Vector* slots);
void trainCaseMatcher(Symbol* className, Symbol* slotName, int cycles);
void trainCaseMatcherEvaluatorWrapper(Cons* arguments);
void generateCaseRuleWoSlot(Vector* cases, Symbol* className, Symbol* slotName);
double trainAndTestCaseMatcher(Symbol* className, Symbol* slotName, int numTrain, int numTest, int cycles);
FloatWrapper* trainAndTestCaseMatcherEvaluatorWrapper(Cons* arguments);
double testCaseBasedReasoner(Symbol* className, Symbol* slotName, int numTrain, int numTest);
FloatWrapper* testCaseBasedReasonerEvaluatorWrapper(Cons* arguments);
double testCaseMatcher(Symbol* className, Symbol* slotName);
FloatWrapper* testCaseMatcherEvaluatorWrapper(Cons* arguments);
int generateCaseTrainingExamples(Vector* instances, Surrogate* slot);
void normalizeNumbers(Vector* vect);
void clearSlotFromClass(Symbol* className, Symbol* slotName);
Object* logicSymbol(Object* obj);
double calculateCaseMatch(Object* x, Object* y);
Cons* getMostSpecificClasses(LogicObject* instance);
List* findUniqueVariableNames(Cons* tree, List* names);
List* variablizeConsPropositions(List* antecedent);
List* variablizeInstances(List* form, List* instances);
boolean stringArgumentP(Cons* clause);
void filterAntecedent(List* antecedent, char* ruleName);
Cons* findMatchingCaseVars(Cons* clause, List* antecedent, List* generatedVariables);
boolean parametersAlignedP(Cons* clause1, Cons* clause2, List* vars);
boolean variableArgP(Object* arg);
Cons* buildVariableConstraints(List* instances);
List* buildTypeDefs(List* instances);
void setPrintCaseDistances(boolean b);
void setPrintCaseDistancesEvaluatorWrapper(Cons* arguments);
List* getNearestNeighbors(TrainingExample* probe, List* cases, int k);
double euclideanDistance(Vector* vec1, Vector* vec2);
int hammingDistance(Vector* vec1, Vector* vec2);
Symbol* internLogicSymbol(char* name);
void helpStartupCaseBased1();
void helpStartupCaseBased2();
void helpStartupCaseBased3();
void startupCaseBased();

// Auxiliary global declarations:
extern Keyword* KWD_CASE_BASED_WEIGHTED_VOTE;
extern Keyword* KWD_CASE_BASED_RETRACT_TRUE;
extern Symbol* SYM_CASE_BASED_LOGIC_DEFRULE;
extern Symbol* SYM_CASE_BASED_STELLA_FORALL;
extern Symbol* SYM_CASE_BASED_STELLA_eg;
extern Symbol* SYM_CASE_BASED_STELLA_AND;
extern Symbol* SYM_CASE_BASED_LOGIC_CASE_MATCH;
extern Symbol* SYM_CASE_BASED_LOGIC_pX;
extern Symbol* SYM_CASE_BASED_LOGIC_pY;
extern Symbol* SYM_CASE_BASED_PL_KERNEL_KB_CASE_MATCH;
extern Keyword* KWD_CASE_BASED_WEIGHTED_AVERAGE;
extern Surrogate* SGT_CASE_BASED_STELLA_FLOAT_WRAPPER;
extern Surrogate* SGT_CASE_BASED_STELLA_INTEGER_WRAPPER;
extern Keyword* KWD_CASE_BASED_AVERAGE;
extern Keyword* KWD_CASE_BASED_ASSERT_TRUE;
extern Symbol* SYM_CASE_BASED_LOGIC_OBJECT_NAME;
extern Symbol* SYM_CASE_BASED_STELLA_SECOND;
extern Symbol* SYM_CASE_BASED_LOGIC_CASES;
extern Surrogate* SGT_CASE_BASED_LOGIC_DESCRIPTION;
extern Surrogate* SGT_CASE_BASED_LOGIC_PATTERN_VARIABLE;
extern Surrogate* SGT_CASE_BASED_LOGIC_SKOLEM;
extern Surrogate* SGT_CASE_BASED_LOGIC_LOGIC_OBJECT;
extern Surrogate* SGT_CASE_BASED_STELLA_CONS;
extern Symbol* SYM_CASE_BASED_LOGIC_SOFT_EQ;
extern Symbol* SYM_CASE_BASED_LOGIC_STARTUP_CASE_BASED;
extern Symbol* SYM_CASE_BASED_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
