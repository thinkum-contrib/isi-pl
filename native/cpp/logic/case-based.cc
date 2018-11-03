//  -*- Mode: C++ -*-

// case-based.cc

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

#include "logic/logic-system.hh"

namespace logic {
  using namespace stella;

boolean oLOG_MATCH_RULESo = FALSE;

boolean oLOG_ANTECEDENT_CONSTRUCTIONo = FALSE;

int oNUM_NEIGHBORSo = 3;

Keyword* oCASE_SOLUTION_COMBINATIONo = NULL;

List* oCASE_RULE_NAMESo = NULL;

int oNUM_CASESo = 0;

int oNUM_TRAINING_PER_CASEo = 12;

int oCASE_VARIABLE_COUNTERo = 0;

int oBASE_COUNTERo = 0;

List* oVISITED_INSTANCESo = NULL;

boolean oONLY_VARIABLIZE_VISITED_INSTANCESo = FALSE;

List* oVISITED_PROPOSITIONSo = NULL;

List* oSEEN_INSTANCESo = NULL;

List* oDELETED_CASE_VARIABLESo = NULL;

HashTable* oSYMBOL_VARIABLE_HASH_TABLEo = NULL;

StringHashTable* oCASE_ANTECEDENT_TABLEo = NULL;

StringHashTable* oCASE_TYPES_TABLEo = NULL;

HashTable* oCASE_NAME_TABLEo = NULL;

void setNumNeighbors(int d) {
  // Sets the number of nearest neighbors to predict from.
  oNUM_NEIGHBORSo = d;
}

void setNumNeighborsEvaluatorWrapper(Cons* arguments) {
  setNumNeighbors(((IntegerWrapper*)(arguments->value))->wrapperValue);
}

void setCaseSolutionCombination(Keyword* k) {
  oCASE_SOLUTION_COMBINATIONo = k;
}

void setNumTrainingPerCase(int d) {
  // Sets the number of training examples for each case in the training set.
  oNUM_TRAINING_PER_CASEo = d;
}

void setNumTrainingPerCaseEvaluatorWrapper(Cons* arguments) {
  setNumTrainingPerCase(((IntegerWrapper*)(arguments->value))->wrapperValue);
}

void clearCases() {
  { Symbol* name = NULL;
    Cons* iter000 = oCASE_RULE_NAMESo->theConsList;

    while (!(iter000 == NIL)) {
      name = ((Symbol*)(iter000->value));
      iter000 = iter000->rest;
      smartUpdateProposition(name, KWD_CASE_BASED_RETRACT_TRUE);
    }
  }
  oNUM_CASESo = 0;
  oSEEN_INSTANCESo = newList();
  oVISITED_PROPOSITIONSo = newList();
  oVISITED_INSTANCESo = newList();
  oCASE_RULE_NAMESo = newList();
  oCASE_ANTECEDENT_TABLEo = newStringHashTable();
  oCASE_TYPES_TABLEo = newStringHashTable();
  oCASE_NAME_TABLEo = newHashTable();
  oCASE_VARIABLE_COUNTERo = 0;
}

void addAllClassInstancesToCaseRule(Surrogate* kind) {
  { Object* instance = NULL;
    Cons* iter000 = allClassInstances(kind);

    while (!(iter000 == NIL)) {
      instance = iter000->value;
      iter000 = iter000->rest;
      buildCaseFromInstance(((LogicObject*)(instance)), kind);
    }
  }
  buildCaseRule(kind);
}

void finalizeCases(Symbol* kind) {
  { Surrogate* clasS = getDescription(kind)->surrogateValueInverse;

    buildCaseRule(clasS);
  }
}

void buildCaseRule(Surrogate* kind) {
  { char* ruleName = stringConcatenate(kind->symbolName, "-match", 0);
    Symbol* ruleNameSymbol = internSymbol(ruleName);
    List* ruleAntecedent = ((List*)(oCASE_ANTECEDENT_TABLEo->lookup(ruleName)));
    List* ruleTypes = ((List*)(oCASE_TYPES_TABLEo->lookup(ruleName)));
    Cons* rule = NIL;

    rule = listO(3, SYM_CASE_BASED_LOGIC_DEFRULE, wrapString(ruleName), cons(listO(3, SYM_CASE_BASED_STELLA_FORALL, ruleTypes, cons(listO(4, SYM_CASE_BASED_STELLA_eg, cons(SYM_CASE_BASED_STELLA_AND, ruleAntecedent->consify()->concatenate(NIL, 0)), listO(4, SYM_CASE_BASED_LOGIC_CASE_MATCH, SYM_CASE_BASED_LOGIC_pX, SYM_CASE_BASED_LOGIC_pY, NIL), NIL), NIL)), NIL));
    if (!oCASE_RULE_NAMESo->memberP(ruleNameSymbol)) {
      oCASE_RULE_NAMESo->push(ruleNameSymbol);
    }
    if (oLOG_MATCH_RULESo) {
      std::cout << rule << std::endl;
    }
    if (!ruleAntecedent->emptyP()) {
      evaluateLogicCommand(rule, FALSE);
    }
  }
}

void addCase(Symbol* inst, Symbol* kind) {
  inst = ((Symbol*)(inst->permanentify()));
  kind = ((Symbol*)(kind->permanentify()));
  buildCaseFromInstance(((LogicObject*)(getInstance(inst))), getDescription(kind)->surrogateValueInverse);
}

void buildCaseFromInstance(LogicObject* inst, Surrogate* kind) {
  oSEEN_INSTANCESo = newList();
  oDELETED_CASE_VARIABLESo = newList();
  oNUM_CASESo = oNUM_CASESo + 1;
  oBASE_COUNTERo = oCASE_VARIABLE_COUNTERo;
  { Symbol* name = objectName(inst);
    List* antecedent = getAssertionStructure(name, 1);
    Object* clasS = kind->surrogateValue;
    Symbol* classSymbol = objectName(clasS);
    char* ruleName = stringConcatenate(objectNameString(clasS), "-match", 0);
    List* ruleAntecedent = ((List*)(oCASE_ANTECEDENT_TABLEo->lookup(ruleName)));
    List* ruleTypes = ((List*)(oCASE_TYPES_TABLEo->lookup(ruleName)));
    List* caseList = ((List*)(oCASE_NAME_TABLEo->lookup(classSymbol)));
    List* typeDefs = NULL;

    if (!((boolean)(caseList))) {
      oCASE_NAME_TABLEo->insertAt(classSymbol, list(1, name));
    }
    else {
      {
        caseList->push(name);
        oCASE_NAME_TABLEo->insertAt(classSymbol, caseList);
      }
    }
    if (!((boolean)(ruleAntecedent))) {
      ruleAntecedent = newList();
    }
    if (!((boolean)(ruleTypes))) {
      ruleTypes = newList();
    }
    oSYMBOL_VARIABLE_HASH_TABLEo = newHashTable();
    if (oONLY_VARIABLIZE_VISITED_INSTANCESo) {
      antecedent = variablizeInstances(antecedent, oVISITED_INSTANCESo);
    }
    else {
      antecedent = variablizeConsPropositions(antecedent);
    }
    { Cons* clause = NULL;
      Cons* iter000 = antecedent->theConsList;

      while (!(iter000 == NIL)) {
        clause = ((Cons*)(iter000->value));
        iter000 = iter000->rest;
        substituteConsTree(clause, SYM_CASE_BASED_LOGIC_pY, ((Symbol*)(oSYMBOL_VARIABLE_HASH_TABLEo->lookup(name))));
      }
    }
    oSYMBOL_VARIABLE_HASH_TABLEo->insertAt(name, SYM_CASE_BASED_LOGIC_pY);
    filterAntecedent(antecedent, ruleName);
    typeDefs = buildTypeDefs(oSEEN_INSTANCESo);
    ruleAntecedent = ruleAntecedent->concatenate(antecedent, 0);
    ruleTypes = ruleTypes->concatenate(typeDefs, 0);
    oCASE_ANTECEDENT_TABLEo->insertAt(ruleName, ruleAntecedent);
    oCASE_TYPES_TABLEo->insertAt(ruleName, ruleTypes);
  }
}

Vector* createCaseInstanceVector(Surrogate* clasS) {
  { Cons* iterator = allClassInstances(clasS);
    int num = iterator->length();
    Vector* instances = newVector(num);

    { int i = NULL_INTEGER;
      Object* inst = NULL;
      int iter000 = 0;
      int upperBound000 = num - 1;
      Cons* iter001 = iterator;

      while ((iter000 <= upperBound000) &&
          (!(iter001 == NIL))) {
        i = iter000;
        iter000 = iter000 + 1;
        inst = iter001->value;
        iter001 = iter001->rest;
        (instances->theArray)[i] = inst;
      }
    }
    return (instances);
  }
}

FloatWrapper* matchInstances(LogicObject* x, LogicObject* y) {
  { Cons* prop = listO(3, SYM_CASE_BASED_PL_KERNEL_KB_CASE_MATCH, x, cons(y, NIL));

    return (wrapFloat(returnPartialTruth(makeQuery(NIL, coerceToTree(prop), NIL, NIL), TRUE)));
  }
}

Vector* createCaseValueVector(List* instances, Surrogate* slot) {
  { Vector* slotValues = newVector(instances->length());

    { int i = NULL_INTEGER;
      LogicObject* inst = NULL;
      int iter000 = 0;
      int upperBound000 = instances->length() - 1;
      Cons* iter001 = instances->theConsList;

      while ((iter000 <= upperBound000) &&
          (!(iter001 == NIL))) {
        i = iter000;
        iter000 = iter000 + 1;
        inst = ((LogicObject*)(iter001->value));
        iter001 = iter001->rest;
        (slotValues->theArray)[i] = (getSlotValue(inst, slot));
      }
    }
    return (slotValues);
  }
}

Object* guess(Symbol* instName, Symbol* slotName) {
  instName = ((Symbol*)(instName->permanentify()));
  slotName = ((Symbol*)(slotName->permanentify()));
  { Object* probe = getInstance(instName);
    Surrogate* clasS = ((LogicObject*)(getMostSpecificClasses(((LogicObject*)(probe)))->last()))->surrogateValueInverse;
    char* ruleName = stringConcatenate(clasS->symbolName, "-match", 0);
    Symbol* ruleNameSymbol = internSymbol(ruleName);
    List* instances = allClassInstances(clasS)->listify();
    Surrogate* slot = getDescription(slotName)->surrogateValueInverse;

    if (!oCASE_RULE_NAMESo->memberP(ruleNameSymbol)) {
      std::cout << "Building match rule." << std::endl;
      addAllClassInstancesToCaseRule(clasS);
    }
    std::cout << "Generating answer" << std::endl;
    return (generateCaseBasedAnswer(((LogicObject*)(probe)), slot, instances));
  }
}

Object* generateCaseBasedAnswer(LogicObject* probe, Surrogate* slot, List* cases) {
  { int num = cases->length();
    Vector* slotVector = createCaseValueVector(cases, slot);
    Vector* matchScores = newVector(num);
    int farthest = 0;
    Vector* nearestNeighbors = newVector(oNUM_NEIGHBORSo);
    double max = 0.0;

    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = oNUM_NEIGHBORSo - 1;

      while (iter000 <= upperBound000) {
        i = iter000;
        iter000 = iter000 + 1;
        (nearestNeighbors->theArray)[i] = (wrapInteger(0));
      }
    }
    { int i = NULL_INTEGER;
      int iter001 = 0;
      int upperBound001 = num - 1;

      while (iter001 <= upperBound001) {
        i = iter001;
        iter001 = iter001 + 1;
        (matchScores->theArray)[i] = (wrapFloat(1.0));
      }
    }
    { int i = NULL_INTEGER;
      Object* casE = NULL;
      int iter002 = 0;
      int upperBound002 = num - 1;
      Cons* iter003 = cases->theConsList;

      while ((iter002 <= upperBound002) &&
          (!(iter003 == NIL))) {
        i = iter002;
        iter002 = iter002 + 1;
        casE = iter003->value;
        iter003 = iter003->rest;
        if (!(probe == casE)) {
          { FloatWrapper* score = matchInstances(probe, ((LogicObject*)(casE)));

            (matchScores->theArray)[i] = score;
            if (score->wrapperValue > max) {
              max = ((double)(i));
            }
            if (score->wrapperValue > ((FloatWrapper*)((matchScores->theArray)[(((IntegerWrapper*)((nearestNeighbors->theArray)[farthest]))->wrapperValue)]))->wrapperValue) {
              (nearestNeighbors->theArray)[farthest] = (wrapInteger(i));
              farthest = 0;
              { int j = NULL_INTEGER;
                int iter004 = 1;
                int upperBound003 = oNUM_NEIGHBORSo - 1;

                while (iter004 <= upperBound003) {
                  j = iter004;
                  iter004 = iter004 + 1;
                  if (((FloatWrapper*)((matchScores->theArray)[(((IntegerWrapper*)((nearestNeighbors->theArray)[j]))->wrapperValue)]))->wrapperValue < ((FloatWrapper*)((matchScores->theArray)[(((IntegerWrapper*)((nearestNeighbors->theArray)[farthest]))->wrapperValue)]))->wrapperValue) {
                    farthest = j;
                  }
                }
              }
            }
          }
        }
      }
    }
    return (combineCaseAnswers(nearestNeighbors, matchScores, slotVector));
  }
}

Object* combineCaseAnswers(Vector* closest, Vector* scores, Vector* slots) {
  scores = scores;
  if (oCASE_SOLUTION_COMBINATIONo == KWD_CASE_BASED_WEIGHTED_VOTE) {
    { PropertyList* answerTable = newPropertyList();
      List* keys = newList();

      { IntegerWrapper* neighbor = NULL;
        Vector* vector000 = closest;
        int index000 = 0;
        int length000 = vector000->length();

        while (index000 < length000) {
          neighbor = ((IntegerWrapper*)((vector000->theArray)[index000]));
          index000 = index000 + 1;
          { Object* answer = (slots->theArray)[(neighbor->wrapperValue)];
            IntegerWrapper* votes = ((IntegerWrapper*)(answerTable->lookup(answer)));

            if (!((boolean)(votes))) {
              {
                keys->push(answer);
                answerTable->insertAt(answer, wrapInteger(1));
              }
            }
            else {
              answerTable->insertAt(answer, wrapInteger(votes->wrapperValue + 1));
            }
          }
        }
      }
      { int max = 0;
        Object* answer = NULL;

        { Object* key = NULL;
          Cons* iter000 = keys->theConsList;

          while (!(iter000 == NIL)) {
            key = iter000->value;
            iter000 = iter000->rest;
            { IntegerWrapper* votes = ((IntegerWrapper*)(answerTable->lookup(key)));

              if (votes->wrapperValue > max) {
                max = votes->wrapperValue;
                answer = key;
              }
            }
          }
        }
        return (answer);
      }
    }
  }
  else if (oCASE_SOLUTION_COMBINATIONo == KWD_CASE_BASED_WEIGHTED_AVERAGE) {
    if (isaP((slots->theArray)[0], SGT_CASE_BASED_STELLA_FLOAT_WRAPPER) ||
        isaP((slots->theArray)[0], SGT_CASE_BASED_STELLA_INTEGER_WRAPPER)) {
      std::cout << "Weighted average not implemented yet" << std::endl;
    }
    else {
      std::cout << "Warning:  Slot type not number.  Cannot average" << std::endl;
    }
  }
  else if (oCASE_SOLUTION_COMBINATIONo == KWD_CASE_BASED_AVERAGE) {
    { Surrogate* testValue000 = safePrimaryType((slots->theArray)[0]);

      if (subtypeOfFloatP(testValue000)) {
        { FloatWrapper* sum = ((FloatWrapper*)((slots->theArray)[(((IntegerWrapper*)((closest->theArray)[0]))->wrapperValue)]));

          { int i = NULL_INTEGER;
            int iter001 = 1;
            int upperBound000 = oNUM_NEIGHBORSo - 1;

            while (iter001 <= upperBound000) {
              i = iter001;
              iter001 = iter001 + 1;
              sum = wrapFloat(sum->wrapperValue + ((FloatWrapper*)((slots->theArray)[(((IntegerWrapper*)((closest->theArray)[i]))->wrapperValue)]))->wrapperValue);
            }
          }
          return (wrapFloat(sum->wrapperValue / oNUM_NEIGHBORSo));
        }
      }
      else if (subtypeOfIntegerP(testValue000)) {
        { IntegerWrapper* sum = ((IntegerWrapper*)((slots->theArray)[(((IntegerWrapper*)((closest->theArray)[0]))->wrapperValue)]));

          { int i = NULL_INTEGER;
            int iter002 = 1;
            int upperBound001 = oNUM_NEIGHBORSo - 1;

            while (iter002 <= upperBound001) {
              i = iter002;
              iter002 = iter002 + 1;
              sum = wrapInteger(sum->wrapperValue + ((IntegerWrapper*)((slots->theArray)[(((IntegerWrapper*)((closest->theArray)[i]))->wrapperValue)]))->wrapperValue);
            }
          }
          return (wrapFloat(((double)(sum->wrapperValue)) / oNUM_NEIGHBORSo));
        }
      }
      else {
        std::cout << "Warning:  Slot type not number.  Cannot average" << std::endl;
      }
    }
  }
  else {
  }
  return ((slots->theArray)[(((IntegerWrapper*)((closest->theArray)[0]))->wrapperValue)]);
}

void trainCaseMatcher(Symbol* className, Symbol* slotName, int cycles) {
  slotName = ((Symbol*)(slotName->permanentify()));
  className = ((Symbol*)(className->permanentify()));
  std::cout << "Generating training examples" << std::endl;
  { Surrogate* clasS = getDescription(className)->surrogateValueInverse;
    Surrogate* slot = getDescription(slotName)->surrogateValueInverse;
    List* ilist = allClassInstances(clasS)->listify();
    Vector* instances = newVector(ilist->length());

    { int i = NULL_INTEGER;
      Object* instance = NULL;
      int iter000 = 0;
      int upperBound000 = ilist->length() - 1;
      Cons* iter001 = ilist->theConsList;

      while ((iter000 <= upperBound000) &&
          (!(iter001 == NIL))) {
        i = iter000;
        iter000 = iter000 + 1;
        instance = iter001->value;
        iter001 = iter001->rest;
        (instances->theArray)[i] = (((LogicObject*)(instance)));
      }
    }
    generateCaseRuleWoSlot(instances, className, slotName);
    { int num = generateCaseTrainingExamples(instances, slot);

      std::cout << "Training case match network" << std::endl;
      trainCachedNeuralNetworks(cycles, num * oNUM_TRAINING_PER_CASEo);
    }
  }
}

void trainCaseMatcherEvaluatorWrapper(Cons* arguments) {
  trainCaseMatcher(((Symbol*)(arguments->value)), ((Symbol*)(arguments->rest->value)), ((IntegerWrapper*)(arguments->rest->rest->value))->wrapperValue);
}

void generateCaseRuleWoSlot(Vector* cases, Symbol* className, Symbol* slotName) {
  { int numCases = cases->length();
    Surrogate* kind = getDescription(className)->surrogateValueInverse;
    List* caseNames = newList();
    Surrogate* slot = getDescription(slotName)->surrogateValueInverse;
    Vector* slotValues = newVector(numCases);

    clearCases();
    { LogicObject* casE = NULL;
      Vector* vector000 = cases;
      int index000 = 0;
      int length000 = vector000->length();
      Cons* collect000 = NULL;

      while (index000 < length000) {
        casE = ((LogicObject*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(objectName(casE), NIL);
            if (caseNames->theConsList == NIL) {
              caseNames->theConsList = collect000;
            }
            else {
              addConsToEndOfConsList(caseNames->theConsList, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(objectName(casE), NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    { LogicObject* casE = NULL;
      Symbol* caseName = NULL;
      int i = NULL_INTEGER;
      Vector* vector001 = cases;
      int index001 = 0;
      int length001 = vector001->length();
      Cons* iter000 = caseNames->theConsList;
      int iter001 = 0;

      while ((index001 < length001) &&
          (!(iter000 == NIL))) {
        casE = ((LogicObject*)((vector001->theArray)[index001]));
        index001 = index001 + 1;
        caseName = ((Symbol*)(iter000->value));
        iter000 = iter000->rest;
        i = iter001;
        iter001 = iter001 + 1;
        { Object* val = getSlotValue(casE, slot);

          (slotValues->theArray)[i] = val;
          smartUpdateProposition(cons(slotName, cons(caseName, cons(val, NIL))), KWD_CASE_BASED_RETRACT_TRUE);
        }
      }
    }
    { OutputFileStream* fptr = newOutputFileStream("current-cases.ste");

      *(fptr->nativeStream) << "(in-package \"STELLA\")" << std::endl;
      { int i = NULL_INTEGER;
        Symbol* caseName = NULL;
        int iter002 = 0;
        int upperBound000 = numCases - 1;
        Cons* iter003 = caseNames->theConsList;

        while ((iter002 <= upperBound000) &&
            (!(iter003 == NIL))) {
          i = iter002;
          iter002 = iter002 + 1;
          caseName = ((Symbol*)(iter003->value));
          iter003 = iter003->rest;
          buildCaseFromInstance(((LogicObject*)((cases->theArray)[i])), kind);
          *(fptr->nativeStream) << "(add-case " << caseName << ")" << std::endl;
        }
      }
    }
    buildCaseRule(kind);
    { Object* val = NULL;
      Symbol* caseName = NULL;
      Vector* vector002 = slotValues;
      int index002 = 0;
      int length002 = vector002->length();
      Cons* iter004 = caseNames->theConsList;

      while ((index002 < length002) &&
          (!(iter004 == NIL))) {
        val = (vector002->theArray)[index002];
        index002 = index002 + 1;
        caseName = ((Symbol*)(iter004->value));
        iter004 = iter004->rest;
        smartUpdateProposition(cons(slotName, cons(caseName, cons(val, NIL))), KWD_CASE_BASED_ASSERT_TRUE);
      }
    }
  }
}

double trainAndTestCaseMatcher(Symbol* className, Symbol* slotName, int numTrain, int numTest, int cycles) {
  className = ((Symbol*)(className->permanentify()));
  slotName = ((Symbol*)(slotName->permanentify()));
  { Surrogate* clasS = getDescription(className)->surrogateValueInverse;
    List* cases = allClassInstances(clasS)->listify();
    Vector* instances = newVector(numTrain);
    Surrogate* slot = getDescription(slotName)->surrogateValueInverse;
    Vector* slotValues = newVector(cases->length());
    int numCorrect = 0;

    shuffleList(cases);
    { Object* casE = NULL;
      int i = NULL_INTEGER;
      Cons* iter000 = cases->theConsList;
      int iter001 = 0;
      int upperBound000 = numTrain - 1;

      while ((!(iter000 == NIL)) &&
          (iter001 <= upperBound000)) {
        casE = iter000->value;
        iter000 = iter000->rest;
        i = iter001;
        iter001 = iter001 + 1;
        (instances->theArray)[i] = (((LogicObject*)(casE)));
      }
    }
    generateCaseRuleWoSlot(instances, className, slotName);
    returnPartialTruth(makeQuery(NIL, coerceToTree(listO(3, SYM_CASE_BASED_LOGIC_CASE_MATCH, objectName(cases->first()), cons(listO(3, SYM_CASE_BASED_LOGIC_OBJECT_NAME, listO(3, SYM_CASE_BASED_STELLA_SECOND, SYM_CASE_BASED_LOGIC_CASES, NIL), NIL), NIL))), NIL, NIL), TRUE);
    saveAllNeuralNetworks(oSAVE_NETWORK_FILEo);
    std::cout << "Training case matcher" << std::endl;
    { int numInstances = generateCaseTrainingExamples(instances, slot);

      trainNeuralNetwork(cycles, numInstances * oNUM_TRAINING_PER_CASEo);
    }
    { List* trainingCases = newList();

      { int i = NULL_INTEGER;
        int iter002 = 0;
        int upperBound001 = numTrain - 1;
        Cons* collect000 = NULL;

        while (iter002 <= upperBound001) {
          i = iter002;
          iter002 = iter002 + 1;
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(((LogicObject*)((instances->theArray)[i])), NIL);
              if (trainingCases->theConsList == NIL) {
                trainingCases->theConsList = collect000;
              }
              else {
                addConsToEndOfConsList(trainingCases->theConsList, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(((LogicObject*)((instances->theArray)[i])), NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      { int i = NULL_INTEGER;
        int iter003 = numTrain;
        int upperBound002 = (numTrain + numTest) - 1;

        while (iter003 <= upperBound002) {
          i = iter003;
          iter003 = iter003 + 1;
          { Object* probe = cases->nth(i);
            Object* correctAnswer = (slotValues->theArray)[i];
            Object* answer = generateCaseBasedAnswer(((LogicObject*)(probe)), slot, trainingCases);

            std::cout << probe << "  Predicted: " << answer << ", Correct: " << correctAnswer << std::endl;
            if (eqlP(answer, correctAnswer)) {
              numCorrect = numCorrect + 1;
            }
          }
        }
      }
    }
    return (((double)(numCorrect)) / numTest);
  }
}

FloatWrapper* trainAndTestCaseMatcherEvaluatorWrapper(Cons* arguments) {
  { double result = trainAndTestCaseMatcher(((Symbol*)(arguments->value)), ((Symbol*)(arguments->rest->value)), ((IntegerWrapper*)(arguments->rest->rest->value))->wrapperValue, ((IntegerWrapper*)(arguments->rest->rest->rest->value))->wrapperValue, ((IntegerWrapper*)(arguments->rest->rest->rest->rest->value))->wrapperValue);

    if (result != NULL_FLOAT) {
      return (wrapFloat(result));
    }
    else {
      return (NULL);
    }
  }
}

double testCaseBasedReasoner(Symbol* className, Symbol* slotName, int numTrain, int numTest) {
  className = ((Symbol*)(className->permanentify()));
  slotName = ((Symbol*)(slotName->permanentify()));
  { Surrogate* clasS = getDescription(className)->surrogateValueInverse;
    List* caseList = allClassInstances(clasS)->listify();
    int numCases = caseList->length();
    Surrogate* slot = getDescription(slotName)->surrogateValueInverse;
    OutputFileStream* fptr = newOutputFileStream("cbr-test-output.txt");
    List* trainingCases = newList();
    Vector* caseVector = newVector(numCases);
    int numCorrect = 0;

    shuffleList(caseList);
    if ((numTrain + numTest) > numCases) {
      std::cout << "Error:  training and test instances out number total instances" << std::endl;
      return (0.0);
    }
    { int i = NULL_INTEGER;
      Object* casE = NULL;
      int iter000 = 0;
      int upperBound000 = numCases - 1;
      Cons* iter001 = caseList->theConsList;

      while ((iter000 <= upperBound000) &&
          (!(iter001 == NIL))) {
        i = iter000;
        iter000 = iter000 + 1;
        casE = iter001->value;
        iter001 = iter001->rest;
        (caseVector->theArray)[i] = (((LogicObject*)(casE)));
      }
    }
    { int i = NULL_INTEGER;
      Object* casE = NULL;
      int iter002 = 1;
      int upperBound001 = numTrain;
      boolean unboundedP000 = upperBound001 == NULL_INTEGER;
      Cons* iter003 = caseList->theConsList;
      Cons* collect000 = NULL;

      while ((unboundedP000 ||
          (iter002 <= upperBound001)) &&
          (!(iter003 == NIL))) {
        i = iter002;
        iter002 = iter002 + 1;
        casE = iter003->value;
        iter003 = iter003->rest;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(casE, NIL);
            if (trainingCases->theConsList == NIL) {
              trainingCases->theConsList = collect000;
            }
            else {
              addConsToEndOfConsList(trainingCases->theConsList, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(casE, NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    { int i = NULL_INTEGER;
      int iter004 = numTrain;
      int upperBound002 = (numTrain + numTest) - 1;

      while (iter004 <= upperBound002) {
        i = iter004;
        iter004 = iter004 + 1;
        { LogicObject* probe = ((LogicObject*)((caseVector->theArray)[i]));
          Symbol* caseName = objectName(probe);
          Object* correctAnswer = getSlotValue(probe, slot);
          Object* answer = generateCaseBasedAnswer(probe, slot, trainingCases);

          if (eqlP(answer, correctAnswer)) {
            numCorrect = numCorrect + 1;
          }
          *(fptr->nativeStream) << "Case " << caseName << " predicted: " << answer << " correct: " << correctAnswer;
          std::cout << "Case " << caseName << " predicted: " << answer << " correct: " << correctAnswer;
          *(fptr->nativeStream) << "  Summary: " << numCorrect << " out of " << numTest << std::endl;
          std::cout << "  Summary: " << numCorrect << " out of " << numTest << std::endl;
        }
      }
    }
    return (((double)(numCorrect)) / numTest);
  }
}

FloatWrapper* testCaseBasedReasonerEvaluatorWrapper(Cons* arguments) {
  { double result = testCaseBasedReasoner(((Symbol*)(arguments->value)), ((Symbol*)(arguments->rest->value)), ((IntegerWrapper*)(arguments->rest->rest->value))->wrapperValue, ((IntegerWrapper*)(arguments->rest->rest->rest->value))->wrapperValue);

    if (result != NULL_FLOAT) {
      return (wrapFloat(result));
    }
    else {
      return (NULL);
    }
  }
}

double testCaseMatcher(Symbol* className, Symbol* slotName) {
  className = ((Symbol*)(className->permanentify()));
  slotName = ((Symbol*)(slotName->permanentify()));
  { Surrogate* clasS = getDescription(className)->surrogateValueInverse;
    List* cases = allClassInstances(clasS)->listify();
    Surrogate* slot = getDescription(slotName)->surrogateValueInverse;
    OutputFileStream* fptr = newOutputFileStream("test-output.txt");
    List* trainingCaseNames = ((List*)(oCASE_NAME_TABLEo->lookup(className)));
    List* trainingCases = newList();
    List* caseNames = newList();
    int total = 0;
    int numCorrect = 0;

    { Object* casE = NULL;
      Cons* iter000 = cases->theConsList;
      Cons* collect000 = NULL;

      while (!(iter000 == NIL)) {
        casE = iter000->value;
        iter000 = iter000->rest;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(objectName(casE), NIL);
            if (caseNames->theConsList == NIL) {
              caseNames->theConsList = collect000;
            }
            else {
              addConsToEndOfConsList(caseNames->theConsList, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(objectName(casE), NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    { Object* casE = NULL;
      Symbol* caseName = NULL;
      Cons* iter001 = cases->theConsList;
      Cons* iter002 = caseNames->theConsList;
      Cons* collect001 = NULL;

      while ((!(iter001 == NIL)) &&
          (!(iter002 == NIL))) {
        casE = iter001->value;
        iter001 = iter001->rest;
        caseName = ((Symbol*)(iter002->value));
        iter002 = iter002->rest;
        if (trainingCaseNames->memberP(caseName)) {
          if (!((boolean)(collect001))) {
            {
              collect001 = cons(casE, NIL);
              if (trainingCases->theConsList == NIL) {
                trainingCases->theConsList = collect001;
              }
              else {
                addConsToEndOfConsList(trainingCases->theConsList, collect001);
              }
            }
          }
          else {
            {
              collect001->rest = cons(casE, NIL);
              collect001 = collect001->rest;
            }
          }
        }
      }
    }
    { Object* casE = NULL;
      Object* probe = NULL;
      Symbol* caseName = NULL;
      Cons* iter003 = cases->theConsList;
      Cons* iter004 = cases->theConsList;
      Cons* iter005 = caseNames->theConsList;

      while ((!(iter003 == NIL)) &&
          ((!(iter004 == NIL)) &&
           (!(iter005 == NIL)))) {
        casE = iter003->value;
        iter003 = iter003->rest;
        probe = iter004->value;
        iter004 = iter004->rest;
        caseName = ((Symbol*)(iter005->value));
        iter005 = iter005->rest;
        if (!trainingCaseNames->memberP(caseName)) {
          { Object* correctAnswer = getSlotValue(((LogicObject*)(casE)), slot);
            Object* answer = generateCaseBasedAnswer(((LogicObject*)(probe)), slot, cases);

            *(fptr->nativeStream) << "Case " << caseName << " predicted: " << answer << " correct: " << correctAnswer;
            std::cout << "Case " << caseName << " predicted: " << answer << " correct: " << correctAnswer;
            total = total + 1;
            if (eqlP(answer, correctAnswer)) {
              numCorrect = numCorrect + 1;
            }
            *(fptr->nativeStream) << "  Summary: " << numCorrect << " out of " << total << std::endl;
            std::cout << "  Summary: " << numCorrect << " out of " << total << std::endl;
          }
        }
      }
    }
    return (((double)(numCorrect)) / total);
  }
}

FloatWrapper* testCaseMatcherEvaluatorWrapper(Cons* arguments) {
  { double result = testCaseMatcher(((Symbol*)(arguments->value)), ((Symbol*)(arguments->rest->value)));

    if (result != NULL_FLOAT) {
      return (wrapFloat(result));
    }
    else {
      return (NULL);
    }
  }
}

int generateCaseTrainingExamples(Vector* instances, Surrogate* slot) {
  { int numInstances = instances->length();
    Vector* slotValues = newVector(numInstances);
    int k = 0;
    int l = 0;
    Vector* index = newVector(numInstances * oNUM_TRAINING_PER_CASEo);
    Vector* matchScores = newVector(numInstances * oNUM_TRAINING_PER_CASEo);

    { int i = NULL_INTEGER;
      LogicObject* inst = NULL;
      int iter000 = 0;
      int upperBound000 = numInstances - 1;
      Vector* vector000 = instances;
      int index000 = 0;
      int length000 = vector000->length();

      while ((iter000 <= upperBound000) &&
          (index000 < length000)) {
        i = iter000;
        iter000 = iter000 + 1;
        inst = ((LogicObject*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        (slotValues->theArray)[i] = (getSlotValue(inst, slot));
      }
    }
    { int i = NULL_INTEGER;
      int iter001 = 0;
      int upperBound001 = numInstances - 1;

      while (iter001 <= upperBound001) {
        i = iter001;
        iter001 = iter001 + 1;
        { int j = NULL_INTEGER;
          int iter002 = 1;
          int upperBound002 = oNUM_TRAINING_PER_CASEo;
          boolean unboundedP000 = upperBound002 == NULL_INTEGER;

          while (unboundedP000 ||
              (iter002 <= upperBound002)) {
            j = iter002;
            iter002 = iter002 + 1;
            j = j;
            l = stella::random(numInstances);
            while (i == l) {
              l = stella::random(numInstances);
            }
            (index->theArray)[k] = (wrapInteger(l));
            (matchScores->theArray)[k] = (wrapFloat(calculateCaseMatch((slotValues->theArray)[i], (slotValues->theArray)[l])));
            k = k + 1;
          }
        }
      }
    }
    k = 0;
    normalizeNumbers(matchScores);
    { int i = NULL_INTEGER;
      int iter003 = 0;
      int upperBound003 = matchScores->length() - 1;

      while (iter003 <= upperBound003) {
        i = iter003;
        iter003 = iter003 + 1;
        (matchScores->theArray)[i] = (wrapFloat(1.0 - ((FloatWrapper*)((matchScores->theArray)[i]))->wrapperValue));
      }
    }
    { int i = NULL_INTEGER;
      int iter004 = 0;
      int upperBound004 = numInstances - 1;

      while (iter004 <= upperBound004) {
        i = iter004;
        iter004 = iter004 + 1;
        { int j = NULL_INTEGER;
          int iter005 = 1;
          int upperBound005 = oNUM_TRAINING_PER_CASEo;
          boolean unboundedP001 = upperBound005 == NULL_INTEGER;

          while (unboundedP001 ||
              (iter005 <= upperBound005)) {
            j = iter005;
            iter005 = iter005 + 1;
            j = j;
            { TrainingExample* example = newTrainingExample();

              example->query = listO(3, SYM_CASE_BASED_PL_KERNEL_KB_CASE_MATCH, logicSymbol(((LogicObject*)((instances->theArray)[i]))), cons(logicSymbol(((LogicObject*)((instances->theArray)[(((IntegerWrapper*)((index->theArray)[k]))->wrapperValue)]))), NIL));
              example->score = ((FloatWrapper*)((matchScores->theArray)[k]))->wrapperValue;
              oTRAINING_EXAMPLESo->push(example);
            }
            k = k + 1;
          }
        }
      }
    }
    return (numInstances);
  }
}

void normalizeNumbers(Vector* vect) {
  { int num = vect->length();
    double max = -99999.0;
    double min = 99999.0;
    double range = 0.0;

    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = num - 1;

      while (iter000 <= upperBound000) {
        i = iter000;
        iter000 = iter000 + 1;
        (vect->theArray)[i] = (wrapFloat(1.0 * ((FloatWrapper*)((vect->theArray)[i]))->wrapperValue));
        if (((FloatWrapper*)((vect->theArray)[i]))->wrapperValue > max) {
          max = ((FloatWrapper*)((vect->theArray)[i]))->wrapperValue;
        }
        if (((FloatWrapper*)((vect->theArray)[i]))->wrapperValue < min) {
          min = ((FloatWrapper*)((vect->theArray)[i]))->wrapperValue;
        }
      }
    }
    range = max - min;
    { int i = NULL_INTEGER;
      int iter001 = 0;
      int upperBound001 = num - 1;

      while (iter001 <= upperBound001) {
        i = iter001;
        iter001 = iter001 + 1;
        (vect->theArray)[i] = (wrapFloat((((FloatWrapper*)((vect->theArray)[i]))->wrapperValue - min) / range));
      }
    }
  }
}

void clearSlotFromClass(Symbol* className, Symbol* slotName) {
  className = ((Symbol*)(className->permanentify()));
  slotName = ((Symbol*)(slotName->permanentify()));
  { Surrogate* clasS = getDescription(className)->surrogateValueInverse;
    List* cases = allClassInstances(clasS)->listify();
    Surrogate* slot = getDescription(slotName)->surrogateValueInverse;

    { Object* casE = NULL;
      Cons* iter000 = cases->theConsList;

      while (!(iter000 == NIL)) {
        casE = iter000->value;
        iter000 = iter000->rest;
        smartUpdateProposition(cons(slotName, cons(casE, cons(getSlotValue(((LogicObject*)(casE)), slot), NIL))), KWD_CASE_BASED_RETRACT_TRUE);
      }
    }
  }
}

Object* logicSymbol(Object* obj) {
  { Surrogate* testValue000 = safePrimaryType(obj);

    if (subtypeOfP(testValue000, SGT_CASE_BASED_LOGIC_DESCRIPTION)) {
      { Object* obj000 = obj;
        Description* obj = ((Description*)(obj000));

        return (obj);
      }
    }
    else if (subtypeOfP(testValue000, SGT_CASE_BASED_LOGIC_PATTERN_VARIABLE)) {
      { Object* obj001 = obj;
        PatternVariable* obj = ((PatternVariable*)(obj001));

        return (internSymbol(getSkolemPrintName(obj)));
      }
    }
    else if (subtypeOfP(testValue000, SGT_CASE_BASED_LOGIC_SKOLEM)) {
      { Object* obj002 = obj;
        Skolem* obj = ((Skolem*)(obj002));

        return (internSymbol(getSkolemPrintName(obj)));
      }
    }
    else if (subtypeOfP(testValue000, SGT_CASE_BASED_LOGIC_LOGIC_OBJECT)) {
      { Object* obj003 = obj;
        LogicObject* obj = ((LogicObject*)(obj003));

        return (internSymbol(obj->surrogateValueInverse->symbolName));
      }
    }
    else {
      return (obj);
    }
  }
}

double calculateCaseMatch(Object* x, Object* y) {
  { Surrogate* testValue000 = safePrimaryType(x);

    if (subtypeOfFloatP(testValue000)) {
      { Object* x000 = x;
        FloatWrapper* x = ((FloatWrapper*)(x000));

        return (floatAbs(((FloatWrapper*)(x))->wrapperValue - ((FloatWrapper*)(y))->wrapperValue));
      }
    }
    else if (subtypeOfIntegerP(testValue000)) {
      { Object* x001 = x;
        IntegerWrapper* x = ((IntegerWrapper*)(x001));

        return (((double)(integerAbs(((IntegerWrapper*)(x))->wrapperValue - ((IntegerWrapper*)(y))->wrapperValue))));
      }
    }
    else if (subtypeOfSymbolP(testValue000)) {
      { Object* x002 = x;
        Symbol* x = ((Symbol*)(x002));

        if (x == y) {
          return (1.0);
        }
        else {
          return (0.0);
        }
      }
    }
    else {
      return (((double)(0)));
    }
  }
}

Cons* getMostSpecificClasses(LogicObject* instance) {
  { Cons* types = allDirectTypes(instance);

    if (types == NIL) {
      return (allAssertedTypes(instance));
    }
    return (types);
  }
}

List* findUniqueVariableNames(Cons* tree, List* names) {
  { Object* arg = NULL;
    Cons* iter000 = tree->rest;

    while (!(iter000 == NIL)) {
      arg = iter000->value;
      iter000 = iter000->rest;
      { Surrogate* testValue000 = safePrimaryType(arg);

        if (testValue000 == SGT_CASE_BASED_STELLA_CONS) {
          { Object* arg000 = arg;
            Cons* arg = ((Cons*)(arg000));

            findUniqueVariableNames(arg, names);
          }
        }
        else if (subtypeOfSymbolP(testValue000)) {
          { Object* arg001 = arg;
            Symbol* arg = ((Symbol*)(arg001));

            if (!names->memberP(arg)) {
              names->push(arg);
            }
          }
        }
        else {
        }
      }
    }
  }
  return (names);
}

List* variablizeConsPropositions(List* antecedent) {
  { List* varList = newList();

    { Cons* prop = NULL;
      Cons* iter000 = antecedent->theConsList;

      while (!(iter000 == NIL)) {
        prop = ((Cons*)(iter000->value));
        iter000 = iter000->rest;
        findUniqueVariableNames(prop, varList);
      }
    }
    return (variablizeInstances(antecedent, varList));
  }
}

List* variablizeInstances(List* form, List* instances) {
  { Object* bind = NULL;
    Cons* iter000 = instances->theConsList;

    while (!(iter000 == NIL)) {
      bind = iter000->value;
      iter000 = iter000->rest;
      { Symbol* var = internLogicSymbol(stringConcatenate("?X", stringify(wrapInteger(oCASE_VARIABLE_COUNTERo)), 0));

        oCASE_VARIABLE_COUNTERo = oCASE_VARIABLE_COUNTERo + 1;
        oSYMBOL_VARIABLE_HASH_TABLEo->insertAt(((Symbol*)(bind)), var);
        oSEEN_INSTANCESo->push(((Symbol*)(bind)));
        { Cons* clause = NULL;
          Cons* iter001 = form->theConsList;

          while (!(iter001 == NIL)) {
            clause = ((Cons*)(iter001->value));
            iter001 = iter001->rest;
            substituteConsTree(clause, var, bind);
          }
        }
      }
    }
  }
  return (form);
}

boolean stringArgumentP(Cons* clause) {
  { Object* ele = NULL;
    Cons* iter000 = clause;

    while (!(iter000 == NIL)) {
      ele = iter000->value;
      iter000 = iter000->rest;
      { Surrogate* testValue000 = safePrimaryType(ele);

        if (testValue000 == SGT_CASE_BASED_STELLA_CONS) {
          { Object* ele000 = ele;
            Cons* ele = ((Cons*)(ele000));

            if (stringArgumentP(ele)) {
              return (TRUE);
            }
          }
        }
        else if (subtypeOfStringP(testValue000)) {
          { Object* ele001 = ele;
            StringWrapper* ele = ((StringWrapper*)(ele001));

            return (TRUE);
          }
        }
        else {
        }
      }
    }
  }
  return (FALSE);
}

void filterAntecedent(List* antecedent, char* ruleName) {
  { ListIterator* clause = ((ListIterator*)(antecedent->allocateIterator()));

    while (clause->nextP()) {
      if (stringArgumentP(((Cons*)(clause->value)))) {
        clause->valueSetter(NULL);
      }
    }
  }
  antecedent->remove(NULL);
  { List* ruleAnt = ((List*)(oCASE_ANTECEDENT_TABLEo->lookup(ruleName)));
    List* generatedVariables = list(1, internLogicSymbol("?Y"));
    int index = 0;

    if (oLOG_ANTECEDENT_CONSTRUCTIONo) {
      std::cout << "New clauses: " << antecedent << std::endl;
    }
    if (!((boolean)(ruleAnt))) {
      return;
    }
    { int i = NULL_INTEGER;
      int iter000 = 1;
      int upperBound000 = antecedent->length();

      while (iter000 <= upperBound000) {
        i = iter000;
        iter000 = iter000 + 1;
        i = i;
        { Cons* clause = ((Cons*)(antecedent->nth(index)));
          Cons* vars = findMatchingCaseVars(clause, ruleAnt, generatedVariables);

          if (!(vars == NIL)) {
            {
              antecedent = ((List*)(antecedent->remove(clause)));
              { Cons* sub = NULL;
                Cons* iter001 = vars;

                while (!(iter001 == NIL)) {
                  sub = ((Cons*)(iter001->value));
                  iter001 = iter001->rest;
                  if (symbolP(sub->rest->value)) {
                    oDELETED_CASE_VARIABLESo->push(((Symbol*)(sub->rest->value)));
                    if (!eqlP(sub->value, sub->rest->value)) {
                      { Cons* ant = NULL;
                        Cons* iter002 = antecedent->theConsList;

                        while (!(iter002 == NIL)) {
                          ant = ((Cons*)(iter002->value));
                          iter002 = iter002->rest;
                          substituteConsTree(ant, sub->value, sub->rest->value);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          else {
            index = index + 1;
          }
        }
      }
    }
    if (oLOG_ANTECEDENT_CONSTRUCTIONo) {
      std::cout << "Clauses added to antecedent: " << antecedent << std::endl;
    }
    return;
  }
}

Cons* findMatchingCaseVars(Cons* clause, List* antecedent, List* generatedVariables) {
  { Object* predicate = clause->value;
    int arity = clause->length();

    { Cons* ant = NULL;
      Cons* iter000 = antecedent->theConsList;

      while (!(iter000 == NIL)) {
        ant = ((Cons*)(iter000->value));
        iter000 = iter000->rest;
        { Cons* realAnt = ant;

          if (oLOG_ANTECEDENT_CONSTRUCTIONo) {
            std::cout << "   Comparing " << clause << " to " << realAnt << std::endl;
          }
          if (eqlP(realAnt->value, predicate) &&
              (parametersAlignedP(clause, realAnt, generatedVariables) &&
               (realAnt->length() == arity))) {
            { Cons* subs = NIL;

              { Object* var1 = NULL;
                Object* var2 = NULL;
                Cons* iter001 = clause->rest;
                Cons* iter002 = realAnt->rest;
                Cons* collect000 = NULL;

                while ((!(iter001 == NIL)) &&
                    (!(iter002 == NIL))) {
                  var1 = iter001->value;
                  iter001 = iter001->rest;
                  var2 = iter002->value;
                  iter002 = iter002->rest;
                  generatedVariables->push(var2);
                  if (!((boolean)(collect000))) {
                    {
                      collect000 = cons(consList(2, var2, var1), NIL);
                      if (subs == NIL) {
                        subs = collect000;
                      }
                      else {
                        addConsToEndOfConsList(subs, collect000);
                      }
                    }
                  }
                  else {
                    {
                      collect000->rest = cons(consList(2, var2, var1), NIL);
                      collect000 = collect000->rest;
                    }
                  }
                }
              }
              if (oLOG_ANTECEDENT_CONSTRUCTIONo) {
                std::cout << "   Found match: " << subs << std::endl;
              }
              return (subs);
            }
          }
        }
      }
    }
    return (NIL);
  }
}

boolean parametersAlignedP(Cons* clause1, Cons* clause2, List* vars) {
  { Object* var = NULL;
    Cons* iter000 = vars->theConsList;

    while (!(iter000 == NIL)) {
      var = iter000->value;
      iter000 = iter000->rest;
      if (!(clause1->position(var, 0) == clause2->position(var, 0))) {
        return (FALSE);
      }
    }
  }
  { Object* p1 = NULL;
    Object* p2 = NULL;
    Cons* iter001 = clause1->rest;
    Cons* iter002 = clause2->rest;

    while ((!(iter001 == NIL)) &&
        (!(iter002 == NIL))) {
      p1 = iter001->value;
      iter001 = iter001->rest;
      p2 = iter002->value;
      iter002 = iter002->rest;
      if (consP(p1)) {
        if ((!consP(p2)) ||
            (!parametersAlignedP(((Cons*)(p1)), ((Cons*)(p2)), vars))) {
          return (FALSE);
        }
      }
      else {
        if (((!variableArgP(p1)) ||
            (!variableArgP(p2))) &&
            (!eqlP(p1, p2))) {
          return (FALSE);
        }
      }
    }
  }
  return (TRUE);
}

boolean variableArgP(Object* arg) {
  if (subtypeOfSymbolP(safePrimaryType(arg))) {
    { Object* arg000 = arg;
      Symbol* arg = ((Symbol*)(arg000));

      if ((arg->symbolName)[0] == '?') {
        return (TRUE);
      }
      else {
        return (FALSE);
      }
    }
  }
  else {
    return (FALSE);
  }
}

Cons* buildVariableConstraints(List* instances) {
  { Cons* constraints = NIL;

    { Symbol* var = NULL;
      Cons* iter000 = instances->theConsList;

      while (!(iter000 == NIL)) {
        var = ((Symbol*)(iter000->value));
        iter000 = iter000->rest;
        { Symbol* name = ((Symbol*)(oSYMBOL_VARIABLE_HASH_TABLEo->lookup(var)));

          if (!oDELETED_CASE_VARIABLESo->memberP(name)) {
            constraints = cons(listO(3, SYM_CASE_BASED_LOGIC_SOFT_EQ, name, cons(internLogicSymbol(stringConcatenate("X", stringSubsequence(stringify(name), 1, NULL_INTEGER), 0)), NIL)), constraints);
          }
        }
      }
    }
    return (constraints);
  }
}

List* buildTypeDefs(List* instances) {
  { List* typeDefs = newList();
    Symbol* name = NULL;

    { Symbol* var = NULL;
      Cons* iter000 = instances->theConsList;

      while (!(iter000 == NIL)) {
        var = ((Symbol*)(iter000->value));
        iter000 = iter000->rest;
        name = ((Symbol*)(oSYMBOL_VARIABLE_HASH_TABLEo->lookup(var)));
        if (!oDELETED_CASE_VARIABLESo->memberP(name)) {
          typeDefs->push(name);
        }
      }
    }
    return (typeDefs);
  }
}

boolean oPRINT_CASE_DISTANCESo = FALSE;

void setPrintCaseDistances(boolean b) {
  oPRINT_CASE_DISTANCESo = b;
}

void setPrintCaseDistancesEvaluatorWrapper(Cons* arguments) {
  setPrintCaseDistances(((BooleanWrapper*)(arguments->value))->wrapperValue);
}

List* getNearestNeighbors(TrainingExample* probe, List* cases, int k) {
  { List* result = newList();
    Module* currentModule = oMODULEo.get();
    Vector* neighbors = newVector(k);
    int farthest = 0;
    double distance = 0.0;
    Vector* distances = newVector(k);

    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = k - 1;

      while (iter000 <= upperBound000) {
        i = iter000;
        iter000 = iter000 + 1;
        (distances->theArray)[i] = (wrapFloat(999999.0));
      }
    }
    if (!((boolean)(probe->input))) {
      probe->input = createInputSignature(probe->query);
    }
    { TrainingExample* casE = NULL;
      Cons* iter001 = cases->theConsList;

      while (!(iter001 == NIL)) {
        casE = ((TrainingExample*)(iter001->value));
        iter001 = iter001->rest;
        if (!((boolean)(casE->input))) {
          if (!(!((boolean)(casE->module)))) {
            casE->module->changeModule();
          }
          casE->input = createInputSignature(casE->query);
          currentModule->changeModule();
        }
        if (probe->input->length() == 1) {
          probe->input = createInputSignature(probe->query);
        }
        distance = hammingDistance(probe->input, casE->input) + 0.0;
        if (oPRINT_CASE_DISTANCESo) {
          std::cout << "  Distance from " << casE->query->last() << ": " << distance << std::endl;
        }
        casE->temp = distance;
        if (distance < ((FloatWrapper*)((distances->theArray)[farthest]))->wrapperValue) {
          (distances->theArray)[farthest] = (wrapFloat(distance));
          (neighbors->theArray)[farthest] = casE;
          farthest = 0;
          { int j = NULL_INTEGER;
            int iter002 = 1;
            int upperBound001 = k - 1;

            while (iter002 <= upperBound001) {
              j = iter002;
              iter002 = iter002 + 1;
              if (((FloatWrapper*)((distances->theArray)[j]))->wrapperValue > ((FloatWrapper*)((distances->theArray)[farthest]))->wrapperValue) {
                farthest = j;
              }
            }
          }
        }
      }
    }
    { int i = NULL_INTEGER;
      int iter003 = 0;
      int upperBound002 = k - 1;
      Cons* collect000 = NULL;

      while (iter003 <= upperBound002) {
        i = iter003;
        iter003 = iter003 + 1;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(((TrainingExample*)((neighbors->theArray)[i])), NIL);
            if (result->theConsList == NIL) {
              result->theConsList = collect000;
            }
            else {
              addConsToEndOfConsList(result->theConsList, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(((TrainingExample*)((neighbors->theArray)[i])), NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    return (result);
  }
}

double euclideanDistance(Vector* vec1, Vector* vec2) {
  { double result = 0.0;
    double diff = 0.0;

    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = vec1->length() - 1;

      while (iter000 <= upperBound000) {
        i = iter000;
        iter000 = iter000 + 1;
        diff = ((FloatWrapper*)((vec1->theArray)[i]))->wrapperValue - ((FloatWrapper*)((vec2->theArray)[i]))->wrapperValue;
        result = result + (diff * diff);
      }
    }
    return (::sqrt(result));
  }
}

int hammingDistance(Vector* vec1, Vector* vec2) {
  { int result = 0;

    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = vec1->length() - 1;

      while (iter000 <= upperBound000) {
        i = iter000;
        iter000 = iter000 + 1;
        if (!(((IntegerWrapper*)((vec1->theArray)[i])) == ((IntegerWrapper*)((vec2->theArray)[i])))) {
          result = result + 1;
        }
      }
    }
    return (result);
  }
}

Symbol* internLogicSymbol(char* name) {
  return (internSymbolInModule(name, getModule(wrapString("LOGIC")), TRUE));
}

void helpStartupCaseBased1() {
  {
    KWD_CASE_BASED_WEIGHTED_VOTE = ((Keyword*)(internRigidSymbolWrtModule("WEIGHTED-VOTE", NULL, 2)));
    KWD_CASE_BASED_RETRACT_TRUE = ((Keyword*)(internRigidSymbolWrtModule("RETRACT-TRUE", NULL, 2)));
    SYM_CASE_BASED_LOGIC_DEFRULE = ((Symbol*)(internRigidSymbolWrtModule("DEFRULE", NULL, 0)));
    SYM_CASE_BASED_STELLA_FORALL = ((Symbol*)(internRigidSymbolWrtModule("FORALL", getStellaModule("/STELLA", TRUE), 0)));
    SYM_CASE_BASED_STELLA_eg = ((Symbol*)(internRigidSymbolWrtModule("=>", getStellaModule("/STELLA", TRUE), 0)));
    SYM_CASE_BASED_STELLA_AND = ((Symbol*)(internRigidSymbolWrtModule("AND", getStellaModule("/STELLA", TRUE), 0)));
    SYM_CASE_BASED_LOGIC_CASE_MATCH = ((Symbol*)(internRigidSymbolWrtModule("CASE-MATCH", NULL, 0)));
    SYM_CASE_BASED_LOGIC_pX = ((Symbol*)(internRigidSymbolWrtModule("?X", NULL, 0)));
    SYM_CASE_BASED_LOGIC_pY = ((Symbol*)(internRigidSymbolWrtModule("?Y", NULL, 0)));
    SYM_CASE_BASED_PL_KERNEL_KB_CASE_MATCH = ((Symbol*)(internRigidSymbolWrtModule("CASE-MATCH", getStellaModule("/PL-KERNEL-KB", TRUE), 0)));
    KWD_CASE_BASED_WEIGHTED_AVERAGE = ((Keyword*)(internRigidSymbolWrtModule("WEIGHTED-AVERAGE", NULL, 2)));
    SGT_CASE_BASED_STELLA_FLOAT_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("FLOAT-WRAPPER", getStellaModule("/STELLA", TRUE), 1)));
    SGT_CASE_BASED_STELLA_INTEGER_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("INTEGER-WRAPPER", getStellaModule("/STELLA", TRUE), 1)));
    KWD_CASE_BASED_AVERAGE = ((Keyword*)(internRigidSymbolWrtModule("AVERAGE", NULL, 2)));
    KWD_CASE_BASED_ASSERT_TRUE = ((Keyword*)(internRigidSymbolWrtModule("ASSERT-TRUE", NULL, 2)));
    SYM_CASE_BASED_LOGIC_OBJECT_NAME = ((Symbol*)(internRigidSymbolWrtModule("OBJECT-NAME", NULL, 0)));
    SYM_CASE_BASED_STELLA_SECOND = ((Symbol*)(internRigidSymbolWrtModule("SECOND", getStellaModule("/STELLA", TRUE), 0)));
    SYM_CASE_BASED_LOGIC_CASES = ((Symbol*)(internRigidSymbolWrtModule("CASES", NULL, 0)));
    SGT_CASE_BASED_LOGIC_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 1)));
    SGT_CASE_BASED_LOGIC_PATTERN_VARIABLE = ((Surrogate*)(internRigidSymbolWrtModule("PATTERN-VARIABLE", NULL, 1)));
    SGT_CASE_BASED_LOGIC_SKOLEM = ((Surrogate*)(internRigidSymbolWrtModule("SKOLEM", NULL, 1)));
    SGT_CASE_BASED_LOGIC_LOGIC_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("LOGIC-OBJECT", NULL, 1)));
    SGT_CASE_BASED_STELLA_CONS = ((Surrogate*)(internRigidSymbolWrtModule("CONS", getStellaModule("/STELLA", TRUE), 1)));
    SYM_CASE_BASED_LOGIC_SOFT_EQ = ((Symbol*)(internRigidSymbolWrtModule("SOFT-EQ", NULL, 0)));
    SYM_CASE_BASED_LOGIC_STARTUP_CASE_BASED = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-CASE-BASED", NULL, 0)));
    SYM_CASE_BASED_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", TRUE), 0)));
  }
}

void helpStartupCaseBased2() {
  {
    oLOG_MATCH_RULESo = FALSE;
    oLOG_ANTECEDENT_CONSTRUCTIONo = FALSE;
    oCASE_SOLUTION_COMBINATIONo = KWD_CASE_BASED_WEIGHTED_VOTE;
    oCASE_RULE_NAMESo = newList();
    oVISITED_INSTANCESo = newList();
    oONLY_VARIABLIZE_VISITED_INSTANCESo = FALSE;
    oVISITED_PROPOSITIONSo = newList();
    oCASE_ANTECEDENT_TABLEo = newStringHashTable();
    oCASE_TYPES_TABLEo = newStringHashTable();
    oCASE_NAME_TABLEo = newHashTable();
    oPRINT_CASE_DISTANCESo = FALSE;
  }
}

void helpStartupCaseBased3() {
  {
    defineFunctionObject("SET-NUM-NEIGHBORS", "(DEFUN SET-NUM-NEIGHBORS ((D INTEGER)) :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Sets the number of nearest neighbors to predict from.\")", ((cpp_function_code)(&setNumNeighbors)), ((cpp_function_code)(&setNumNeighborsEvaluatorWrapper)));
    defineFunctionObject("SET-CASE-SOLUTION-COMBINATION", "(DEFUN SET-CASE-SOLUTION-COMBINATION ((K KEYWORD)) :COMMAND? TRUE :PUBLIC? TRUE)", ((cpp_function_code)(&setCaseSolutionCombination)), NULL);
    defineFunctionObject("SET-NUM-TRAINING-PER-CASE", "(DEFUN SET-NUM-TRAINING-PER-CASE ((D INTEGER)) :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Sets the number of training examples for each case in the training set.\")", ((cpp_function_code)(&setNumTrainingPerCase)), ((cpp_function_code)(&setNumTrainingPerCaseEvaluatorWrapper)));
    defineFunctionObject("CLEAR-CASES", "(DEFUN CLEAR-CASES () :COMMAND? TRUE :PUBLIC? TRUE)", ((cpp_function_code)(&clearCases)), NULL);
    defineFunctionObject("ADD-ALL-CLASS-INSTANCES-TO-CASE-RULE", "(DEFUN ADD-ALL-CLASS-INSTANCES-TO-CASE-RULE ((KIND SURROGATE)))", ((cpp_function_code)(&addAllClassInstancesToCaseRule)), NULL);
    defineFunctionObject("FINALIZE-CASES", "(DEFUN FINALIZE-CASES ((KIND SYMBOL)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE)", ((cpp_function_code)(&finalizeCases)), NULL);
    defineFunctionObject("BUILD-CASE-RULE", "(DEFUN BUILD-CASE-RULE ((KIND SURROGATE)))", ((cpp_function_code)(&buildCaseRule)), NULL);
    defineFunctionObject("ADD-CASE", "(DEFUN ADD-CASE ((INST SYMBOL) (KIND SYMBOL)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE)", ((cpp_function_code)(&addCase)), NULL);
    defineFunctionObject("BUILD-CASE-FROM-INSTANCE", "(DEFUN BUILD-CASE-FROM-INSTANCE ((INST LOGIC-OBJECT) (KIND SURROGATE)))", ((cpp_function_code)(&buildCaseFromInstance)), NULL);
    defineFunctionObject("CREATE-CASE-INSTANCE-VECTOR", "(DEFUN (CREATE-CASE-INSTANCE-VECTOR VECTOR) ((CLASS SURROGATE)))", ((cpp_function_code)(&createCaseInstanceVector)), NULL);
    defineFunctionObject("MATCH-INSTANCES", "(DEFUN (MATCH-INSTANCES FLOAT-WRAPPER) ((X LOGIC-OBJECT) (Y LOGIC-OBJECT)))", ((cpp_function_code)(&matchInstances)), NULL);
    defineFunctionObject("CREATE-CASE-VALUE-VECTOR", "(DEFUN (CREATE-CASE-VALUE-VECTOR VECTOR) ((INSTANCES (LIST OF LOGIC-OBJECT)) (SLOT SURROGATE)))", ((cpp_function_code)(&createCaseValueVector)), NULL);
    defineFunctionObject("GUESS", "(DEFUN (GUESS OBJECT) ((INST-NAME SYMBOL) (SLOT-NAME SYMBOL)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE)", ((cpp_function_code)(&guess)), NULL);
    defineFunctionObject("GENERATE-CASE-BASED-ANSWER", "(DEFUN (GENERATE-CASE-BASED-ANSWER OBJECT) ((PROBE LOGIC-OBJECT) (SLOT SURROGATE) (CASES LIST)))", ((cpp_function_code)(&generateCaseBasedAnswer)), NULL);
    defineFunctionObject("COMBINE-CASE-ANSWERS", "(DEFUN (COMBINE-CASE-ANSWERS OBJECT) ((CLOSEST (VECTOR OF INTEGER-WRAPPER)) (SCORES (VECTOR OF FLOAT-WRAPPER)) (SLOTS (VECTOR OF OBJECT))))", ((cpp_function_code)(&combineCaseAnswers)), NULL);
    defineFunctionObject("TRAIN-CASE-MATCHER", "(DEFUN TRAIN-CASE-MATCHER ((CLASS-NAME SYMBOL) (SLOT-NAME SYMBOL) (CYCLES INTEGER)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE)", ((cpp_function_code)(&trainCaseMatcher)), ((cpp_function_code)(&trainCaseMatcherEvaluatorWrapper)));
    defineFunctionObject("GENERATE-CASE-RULE-WO-SLOT", "(DEFUN GENERATE-CASE-RULE-WO-SLOT ((CASES (VECTOR OF LOGIC-OBJECT)) (CLASS-NAME SYMBOL) (SLOT-NAME SYMBOL)))", ((cpp_function_code)(&generateCaseRuleWoSlot)), NULL);
    defineFunctionObject("TRAIN-AND-TEST-CASE-MATCHER", "(DEFUN (TRAIN-AND-TEST-CASE-MATCHER FLOAT) ((CLASS-NAME SYMBOL) (SLOT-NAME SYMBOL) (NUM-TRAIN INTEGER) (NUM-TEST INTEGER) (CYCLES INTEGER)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE)", ((cpp_function_code)(&trainAndTestCaseMatcher)), ((cpp_function_code)(&trainAndTestCaseMatcherEvaluatorWrapper)));
    defineFunctionObject("TEST-CASE-BASED-REASONER", "(DEFUN (TEST-CASE-BASED-REASONER FLOAT) ((CLASS-NAME SYMBOL) (SLOT-NAME SYMBOL) (NUM-TRAIN INTEGER) (NUM-TEST INTEGER)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE)", ((cpp_function_code)(&testCaseBasedReasoner)), ((cpp_function_code)(&testCaseBasedReasonerEvaluatorWrapper)));
    defineFunctionObject("TEST-CASE-MATCHER", "(DEFUN (TEST-CASE-MATCHER FLOAT) ((CLASS-NAME SYMBOL) (SLOT-NAME SYMBOL)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE)", ((cpp_function_code)(&testCaseMatcher)), ((cpp_function_code)(&testCaseMatcherEvaluatorWrapper)));
    defineFunctionObject("GENERATE-CASE-TRAINING-EXAMPLES", "(DEFUN (GENERATE-CASE-TRAINING-EXAMPLES INTEGER) ((INSTANCES (VECTOR OF LOGIC-OBJECT)) (SLOT SURROGATE)))", ((cpp_function_code)(&generateCaseTrainingExamples)), NULL);
    defineFunctionObject("NORMALIZE-NUMBERS", "(DEFUN NORMALIZE-NUMBERS ((VECT (VECTOR OF FLOAT-WRAPPER))))", ((cpp_function_code)(&normalizeNumbers)), NULL);
    defineFunctionObject("CLEAR-SLOT-FROM-CLASS", "(DEFUN CLEAR-SLOT-FROM-CLASS ((CLASS-NAME SYMBOL) (SLOT-NAME SYMBOL)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE)", ((cpp_function_code)(&clearSlotFromClass)), NULL);
    defineFunctionObject("LOGIC-SYMBOL", "(DEFUN (LOGIC-SYMBOL OBJECT) ((OBJ OBJECT)))", ((cpp_function_code)(&logicSymbol)), NULL);
    defineFunctionObject("CALCULATE-CASE-MATCH", "(DEFUN (CALCULATE-CASE-MATCH FLOAT) ((X OBJECT) (Y OBJECT)))", ((cpp_function_code)(&calculateCaseMatch)), NULL);
    defineFunctionObject("GET-MOST-SPECIFIC-CLASSES", "(DEFUN (GET-MOST-SPECIFIC-CLASSES CONS) ((INSTANCE LOGIC-OBJECT)))", ((cpp_function_code)(&getMostSpecificClasses)), NULL);
    defineFunctionObject("FIND-UNIQUE-VARIABLE-NAMES", "(DEFUN (FIND-UNIQUE-VARIABLE-NAMES LIST) ((TREE CONS) (NAMES (LIST OF SYMBOL))))", ((cpp_function_code)(&findUniqueVariableNames)), NULL);
    defineFunctionObject("VARIABLIZE-CONS-PROPOSITIONS", "(DEFUN (VARIABLIZE-CONS-PROPOSITIONS (LIST OF CONS)) ((ANTECEDENT (LIST OF CONS))))", ((cpp_function_code)(&variablizeConsPropositions)), NULL);
    defineFunctionObject("VARIABLIZE-INSTANCES", "(DEFUN (VARIABLIZE-INSTANCES (LIST OF CONS)) ((FORM (LIST OF CONS)) (INSTANCES (LIST OF OBJECT))))", ((cpp_function_code)(&variablizeInstances)), NULL);
    defineFunctionObject("STRING-ARGUMENT?", "(DEFUN (STRING-ARGUMENT? BOOLEAN) ((CLAUSE CONS)))", ((cpp_function_code)(&stringArgumentP)), NULL);
    defineFunctionObject("FILTER-ANTECEDENT", "(DEFUN FILTER-ANTECEDENT ((ANTECEDENT (LIST OF CONS)) (RULE-NAME STRING)))", ((cpp_function_code)(&filterAntecedent)), NULL);
    defineFunctionObject("FIND-MATCHING-CASE-VARS", "(DEFUN (FIND-MATCHING-CASE-VARS CONS) ((CLAUSE CONS) (ANTECEDENT (LIST OF CONS)) (GENERATED-VARIABLES LIST)))", ((cpp_function_code)(&findMatchingCaseVars)), NULL);
    defineFunctionObject("PARAMETERS-ALIGNED?", "(DEFUN (PARAMETERS-ALIGNED? BOOLEAN) ((CLAUSE1 CONS) (CLAUSE2 CONS) (VARS LIST)))", ((cpp_function_code)(&parametersAlignedP)), NULL);
    defineFunctionObject("VARIABLE-ARG?", "(DEFUN (VARIABLE-ARG? BOOLEAN) ((ARG OBJECT)))", ((cpp_function_code)(&variableArgP)), NULL);
    defineFunctionObject("BUILD-VARIABLE-CONSTRAINTS", "(DEFUN (BUILD-VARIABLE-CONSTRAINTS CONS) ((INSTANCES (LIST OF SYMBOL))))", ((cpp_function_code)(&buildVariableConstraints)), NULL);
    defineFunctionObject("BUILD-TYPE-DEFS", "(DEFUN (BUILD-TYPE-DEFS (LIST OF SYMBOL)) ((INSTANCES (LIST OF SYMBOL))))", ((cpp_function_code)(&buildTypeDefs)), NULL);
    defineFunctionObject("SET-PRINT-CASE-DISTANCES", "(DEFUN SET-PRINT-CASE-DISTANCES ((B BOOLEAN)) :COMMAND? TRUE :PUBLIC? TRUE)", ((cpp_function_code)(&setPrintCaseDistances)), ((cpp_function_code)(&setPrintCaseDistancesEvaluatorWrapper)));
    defineFunctionObject("GET-NEAREST-NEIGHBORS", "(DEFUN (GET-NEAREST-NEIGHBORS (LIST OF TRAINING-EXAMPLE)) ((PROBE TRAINING-EXAMPLE) (CASES (LIST OF TRAINING-EXAMPLE)) (K INTEGER)))", ((cpp_function_code)(&getNearestNeighbors)), NULL);
    defineFunctionObject("EUCLIDEAN-DISTANCE", "(DEFUN (EUCLIDEAN-DISTANCE FLOAT) ((VEC1 (VECTOR OF FLOAT-WRAPPER)) (VEC2 (VECTOR OF FLOAT-WRAPPER))))", ((cpp_function_code)(&euclideanDistance)), NULL);
    defineFunctionObject("HAMMING-DISTANCE", "(DEFUN (HAMMING-DISTANCE INTEGER) ((VEC1 (VECTOR OF INTEGER-WRAPPER)) (VEC2 (VECTOR OF INTEGER-WRAPPER))))", ((cpp_function_code)(&hammingDistance)), NULL);
    defineFunctionObject("INTERN-LOGIC-SYMBOL", "(DEFUN (INTERN-LOGIC-SYMBOL SYMBOL) ((NAME STRING)))", ((cpp_function_code)(&internLogicSymbol)), NULL);
    defineFunctionObject("STARTUP-CASE-BASED", "(DEFUN STARTUP-CASE-BASED () :PUBLIC? TRUE)", ((cpp_function_code)(&startupCaseBased)), NULL);
    { MethodSlot* function = lookupFunction(SYM_CASE_BASED_LOGIC_STARTUP_CASE_BASED);

      setDynamicSlotValue(function->dynamicSlots, SYM_CASE_BASED_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Case-Based"), NULL_STRING_WRAPPER);
    }
  }
}

void startupCaseBased() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupCaseBased1();
    }
    if (currentStartupTimePhaseP(4)) {
      helpStartupCaseBased2();
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupCaseBased3();
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LOG-MATCH-RULES* BOOLEAN FALSE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LOG-ANTECEDENT-CONSTRUCTION* BOOLEAN FALSE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *NUM-NEIGHBORS* INTEGER 3)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CASE-SOLUTION-COMBINATION* KEYWORD :WEIGHTED-VOTE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CASE-RULE-NAMES* (LIST OF SYMBOL) (NEW (LIST OF SYMBOL)))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *NUM-CASES* INTEGER 0)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *NUM-TRAINING-PER-CASE* INTEGER 12)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CASE-VARIABLE-COUNTER* INTEGER 0)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *BASE-COUNTER* INTEGER 0)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *VISITED-INSTANCES* (LIST OF SYMBOL) (NEW (LIST OF SYMBOL)))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *ONLY-VARIABLIZE-VISITED-INSTANCES* BOOLEAN FALSE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *VISITED-PROPOSITIONS* (LIST OF PROPOSITION) (NEW (LIST OF PROPOSITION)))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SEEN-INSTANCES* (LIST OF SYMBOL) NULL)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *DELETED-CASE-VARIABLES* (LIST OF SYMBOL) NULL)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SYMBOL-VARIABLE-HASH-TABLE* (HASH-TABLE OF SYMBOL SYMBOL) NULL)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CASE-ANTECEDENT-TABLE* (STRING-HASH-TABLE OF STRING (LIST OF CONS)) (NEW (STRING-HASH-TABLE OF STRING (LIST OF CONS))))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CASE-TYPES-TABLE* (STRING-HASH-TABLE OF STRING (LIST OF SYMBOL)) (NEW (STRING-HASH-TABLE OF STRING (LIST OF SYMBOL))))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CASE-NAME-TABLE* (HASH-TABLE OF SYMBOL (LIST OF SYMBOL)) (NEW (HASH-TABLE OF SYMBOL (LIST OF SYMBOL))))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *PRINT-CASE-DISTANCES* BOOLEAN FALSE)");
    }
  }
}

Keyword* KWD_CASE_BASED_WEIGHTED_VOTE = NULL;

Keyword* KWD_CASE_BASED_RETRACT_TRUE = NULL;

Symbol* SYM_CASE_BASED_LOGIC_DEFRULE = NULL;

Symbol* SYM_CASE_BASED_STELLA_FORALL = NULL;

Symbol* SYM_CASE_BASED_STELLA_eg = NULL;

Symbol* SYM_CASE_BASED_STELLA_AND = NULL;

Symbol* SYM_CASE_BASED_LOGIC_CASE_MATCH = NULL;

Symbol* SYM_CASE_BASED_LOGIC_pX = NULL;

Symbol* SYM_CASE_BASED_LOGIC_pY = NULL;

Symbol* SYM_CASE_BASED_PL_KERNEL_KB_CASE_MATCH = NULL;

Keyword* KWD_CASE_BASED_WEIGHTED_AVERAGE = NULL;

Surrogate* SGT_CASE_BASED_STELLA_FLOAT_WRAPPER = NULL;

Surrogate* SGT_CASE_BASED_STELLA_INTEGER_WRAPPER = NULL;

Keyword* KWD_CASE_BASED_AVERAGE = NULL;

Keyword* KWD_CASE_BASED_ASSERT_TRUE = NULL;

Symbol* SYM_CASE_BASED_LOGIC_OBJECT_NAME = NULL;

Symbol* SYM_CASE_BASED_STELLA_SECOND = NULL;

Symbol* SYM_CASE_BASED_LOGIC_CASES = NULL;

Surrogate* SGT_CASE_BASED_LOGIC_DESCRIPTION = NULL;

Surrogate* SGT_CASE_BASED_LOGIC_PATTERN_VARIABLE = NULL;

Surrogate* SGT_CASE_BASED_LOGIC_SKOLEM = NULL;

Surrogate* SGT_CASE_BASED_LOGIC_LOGIC_OBJECT = NULL;

Surrogate* SGT_CASE_BASED_STELLA_CONS = NULL;

Symbol* SYM_CASE_BASED_LOGIC_SOFT_EQ = NULL;

Symbol* SYM_CASE_BASED_LOGIC_STARTUP_CASE_BASED = NULL;

Symbol* SYM_CASE_BASED_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
