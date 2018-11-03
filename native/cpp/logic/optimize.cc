//  -*- Mode: C++ -*-

// optimize.cc

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

#include "logic/logic-system.hh"

namespace logic {
  using namespace stella;

GoalRecord* newGoalRecord() {
  { GoalRecord* self = NULL;

    self = new GoalRecord();
    self->otherGoals = newList();
    self->generatorGoals = newList();
    return (self);
  }
}

Surrogate* GoalRecord::primaryType() {
  { GoalRecord* self = this;

    return (SGT_OPTIMIZE_LOGIC_GOAL_RECORD);
  }
}

Object* accessGoalRecordSlotValue(GoalRecord* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_OPTIMIZE_LOGIC_GENERATOR_GOALS) {
    if (setvalueP) {
      self->generatorGoals = ((List*)(value));
    }
    else {
      value = self->generatorGoals;
    }
  }
  else if (slotname == SYM_OPTIMIZE_LOGIC_OTHER_GOALS) {
    if (setvalueP) {
      self->otherGoals = ((List*)(value));
    }
    else {
      value = self->otherGoals;
    }
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << slotname << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  return (value);
}

boolean variableBoundP(PatternVariable* variable) {
  return (((boolean)((oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(variable->boundToOffset)])) ||
      ((boolean)(((Object*)(accessInContext(variable->variableValue, variable->homeContext, false))))));
}

boolean argumentBoundP(Object* argument) {
  { Surrogate* testValue000 = safePrimaryType(argument);

    if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
      { Object* argument000 = argument;
        PatternVariable* argument = ((PatternVariable*)(argument000));

        return (variableBoundP(argument));
      }
    }
    else if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PROPOSITION)) {
      { Object* argument001 = argument;
        Proposition* argument = ((Proposition*)(argument001));

        if (((boolean)(((Vector*)(dynamicSlotValue(argument->dynamicSlots, SYM_OPTIMIZE_LOGIC_IO_VARIABLES, NULL)))))) {
          return (quantifiedArgumentBoundP(argument, NULL));
        }
        else {
          { boolean alwaysP000 = true;

            { Object* arg = NULL;
              Vector* vector000 = argument->arguments;
              int index000 = 0;
              int length000 = vector000->length();

              for  (arg, vector000, index000, length000; 
                    index000 < length000; 
                    index000 = index000 + 1) {
                arg = (vector000->theArray)[index000];
                if (!argumentBoundP(arg)) {
                  alwaysP000 = false;
                  break;
                }
              }
            }
            { boolean value000 = alwaysP000;

              return (value000);
            }
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_DESCRIPTION)) {
      { Object* argument002 = argument;
        Description* argument = ((Description*)(argument002));

        { boolean testValue001 = false;

          if (!((boolean)(((Vector*)(dynamicSlotValue(argument->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, NULL)))))) {
            testValue001 = true;
          }
          else {
            { boolean alwaysP001 = true;

              { PatternVariable* v = NULL;
                Vector* vector001 = ((Vector*)(dynamicSlotValue(argument->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, NULL)));
                int index001 = 0;
                int length001 = vector001->length();

                for  (v, vector001, index001, length001; 
                      index001 < length001; 
                      index001 = index001 + 1) {
                  v = ((PatternVariable*)((vector001->theArray)[index001]));
                  if (!argumentBoundP(v)) {
                    alwaysP001 = false;
                    break;
                  }
                }
              }
              testValue001 = alwaysP001;
            }
          }
          { boolean value001 = testValue001;

            return (value001);
          }
        }
      }
    }
    else {
      return (true);
    }
  }
}

boolean quantifiedArgumentBoundP(Object* argument, List* quantifiedvars) {
  if (!((boolean)(quantifiedvars))) {
    quantifiedvars = newList();
  }
  { Surrogate* testValue000 = safePrimaryType(argument);

    if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
      { Object* argument000 = argument;
        PatternVariable* argument = ((PatternVariable*)(argument000));

        return (variableBoundP(argument) ||
            quantifiedvars->membP(argument));
      }
    }
    else if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PROPOSITION)) {
      { Object* argument001 = argument;
        Proposition* argument = ((Proposition*)(argument001));

        { Vector* iovars = ((Vector*)(dynamicSlotValue(argument->dynamicSlots, SYM_OPTIMIZE_LOGIC_IO_VARIABLES, NULL)));

          if (((boolean)(iovars))) {
            { PatternVariable* var = NULL;
              Vector* vector000 = iovars;
              int index000 = 0;
              int length000 = vector000->length();

              for  (var, vector000, index000, length000; 
                    index000 < length000; 
                    index000 = index000 + 1) {
                var = ((PatternVariable*)((vector000->theArray)[index000]));
                quantifiedvars->insert(var);
              }
            }
          }
          { boolean alwaysP000 = true;

            { Object* arg = NULL;
              Vector* vector001 = argument->arguments;
              int index001 = 0;
              int length001 = vector001->length();

              for  (arg, vector001, index001, length001; 
                    index001 < length001; 
                    index001 = index001 + 1) {
                arg = (vector001->theArray)[index001];
                if (!quantifiedArgumentBoundP(arg, quantifiedvars)) {
                  alwaysP000 = false;
                  break;
                }
              }
            }
            { boolean value000 = alwaysP000;

              return (value000);
            }
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_DESCRIPTION)) {
      { Object* argument002 = argument;
        Description* argument = ((Description*)(argument002));

        { boolean testValue001 = false;

          if (!((boolean)(((Vector*)(dynamicSlotValue(argument->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, NULL)))))) {
            testValue001 = true;
          }
          else {
            { boolean alwaysP001 = true;

              { PatternVariable* v = NULL;
                Vector* vector002 = ((Vector*)(dynamicSlotValue(argument->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, NULL)));
                int index002 = 0;
                int length002 = vector002->length();

                for  (v, vector002, index002, length002; 
                      index002 < length002; 
                      index002 = index002 + 1) {
                  v = ((PatternVariable*)((vector002->theArray)[index002]));
                  if (!quantifiedArgumentBoundP(v, quantifiedvars)) {
                    alwaysP001 = false;
                    break;
                  }
                }
              }
              testValue001 = alwaysP001;
            }
          }
          { boolean value001 = testValue001;

            return (value001);
          }
        }
      }
    }
    else {
      return (true);
    }
  }
}

boolean unboundVariableP(Object* argument) {
  if (subtypeOfP(safePrimaryType(argument), SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
    { Object* argument000 = argument;
      PatternVariable* argument = ((PatternVariable*)(argument000));

      return (!variableBoundP(argument));
    }
  }
  else {
    return (false);
  }
}

boolean hasDisjunctionP(Proposition* goal) {
  if (goal->kind == KWD_OPTIMIZE_OR) {
    return (true);
  }
  { boolean foundP000 = false;

    { Object* arg = NULL;
      Vector* vector000 = goal->arguments;
      int index000 = 0;
      int length000 = vector000->length();

      for  (arg, vector000, index000, length000; 
            index000 < length000; 
            index000 = index000 + 1) {
        arg = (vector000->theArray)[index000];
        if (isaP(arg, SGT_OPTIMIZE_LOGIC_PROPOSITION) &&
            hasDisjunctionP(((Proposition*)(arg)))) {
          foundP000 = true;
          break;
        }
      }
    }
    { boolean value000 = foundP000;

      return (value000);
    }
  }
}

boolean modalGoalP(Proposition* goal) {
  { boolean foundP000 = false;

    { Object* arg = NULL;
      Vector* vector000 = goal->arguments;
      int index000 = 0;
      int length000 = vector000->length();

      for  (arg, vector000, index000, length000; 
            index000 < length000; 
            index000 = index000 + 1) {
        arg = (vector000->theArray)[index000];
        if (isaP(arg, SGT_OPTIMIZE_LOGIC_PROPOSITION)) {
          foundP000 = true;
          break;
        }
      }
    }
    { boolean value000 = foundP000;

      return (value000);
    }
  }
}

boolean hasInversionsP(Proposition* goal) {
  return (((boolean)(((KeyValueList*)(dynamicSlotValue(getDescription(((Surrogate*)(goal->operatoR)))->dynamicSlots, SYM_OPTIMIZE_LOGIC_PERMUTATION_TABLE, NULL))))));
}

boolean computedTermP(Description* self) {
  return (testPropertyP(self, SGT_OPTIMIZE_PL_KERNEL_KB_COMPUTED));
}

boolean computedConstraintP(Description* self) {
  return (testPropertyP(self, SGT_OPTIMIZE_PL_KERNEL_KB_COMPUTED) &&
      ((boolean)(accessBinaryValue(self, SGT_OPTIMIZE_PL_KERNEL_KB_RELATION_CONSTRAINT))));
}

boolean computedPredicateP(Proposition* goal) {
  { NamedDescription* description = getDescription(((Surrogate*)(goal->operatoR)));

    return (((boolean)(description)) &&
        (computedTermP(description) ||
         getQuotedTree("((/PL-KERNEL-KB/@LISTOF /PL-KERNEL-KB/@SETOF) \"/LOGIC\")", "/LOGIC")->memberP(description->surrogateValueInverse)));
  }
}

int simulateCreateChoicePoint() {
  return (oQUERYITERATORo.get()->currentPatternRecord->topUnbindingStackOffset + 1);
}

boolean relationSupportsExtensionP(NamedDescription* self) {
  return ((!testPropertyP(self, SGT_OPTIMIZE_PL_KERNEL_KB_ABSTRACT)) &&
      (!logicalSubtypeOfLiteralP(self->surrogateValueInverse)));
}

boolean generatorCollectionP(Object* collection) {
  if (oREVERSEPOLARITYpo.get() &&
      (!closedTermP(collection))) {
    return (false);
  }
  { Surrogate* testValue000 = safePrimaryType(collection);

    if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_DESCRIPTION)) {
      { Object* collection000 = collection;
        Description* collection = ((Description*)(collection000));

        return ((!isaP(collection, SGT_OPTIMIZE_LOGIC_NAMED_DESCRIPTION)) ||
            relationSupportsExtensionP(((NamedDescription*)(collection))));
      }
    }
    else if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
      { Object* collection001 = collection;
        PatternVariable* collection = ((PatternVariable*)(collection001));

        { Object* boundtovalue = argumentBoundTo(collection);

          if (((boolean)(boundtovalue))) {
            return (generatorCollectionP(boundtovalue));
          }
          else if (((boolean)(collection->definingProposition))) {
            return (true);
          }
          else {
            return (false);
          }
        }
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* collection002 = collection;
        Surrogate* collection = ((Surrogate*)(collection002));

        return (relationSupportsExtensionP(getDescription(collection)));
      }
    }
    else {
      return (true);
    }
  }
}

void initializeOptimizerGoalRecords(int size) {
  { ExtensibleVector* stack = ((ExtensibleVector*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_OPTIMIZER_GOAL_RECORDS, NULL)));

    if (!((boolean)(stack))) {
      stack = newExtensibleVector(20);
      setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_OPTIMIZER_GOAL_RECORDS, stack, NULL);
    }
    if (size > stack->length()) {
      stack->insertAt(size, NULL);
    }
    { int i = NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = size - 1;

      for  (i, iter000, upperBound000; 
            iter000 <= upperBound000; 
            iter000 = iter000 + 1) {
        i = iter000;
        { GoalRecord* goalrecord = ((GoalRecord*)((stack->theArray)[i]));

          if (!((boolean)(goalrecord))) {
            goalrecord = newGoalRecord();
            (stack->theArray)[i] = goalrecord;
          }
          goalrecord->generatorGoals->clear();
          goalrecord->otherGoals->clear();
        }
      }
    }
  }
}

GoalRecord* goalRecord(PatternVariable* variable) {
  return (((GoalRecord*)((((ExtensibleVector*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_OPTIMIZER_GOAL_RECORDS, NULL)))->theArray)[(variable->boundToOffset)])));
}

// Used by 'distribute-open-goal' to signal that
// a goal was distributed by 'help-distribute-goal'.
DEFINE_STELLA_SPECIAL(oDISTRIBUTEDOPENGOALpo, boolean , false);

void helpDistributeGoal(Object* argument, Proposition* parentgoal, boolean generatorP) {
  { Surrogate* testValue000 = safePrimaryType(argument);

    if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
      { Object* argument000 = argument;
        PatternVariable* argument = ((PatternVariable*)(argument000));

        if (variableBoundP(argument)) {
          return;
        }
        { GoalRecord* goalrecord = goalRecord(argument);

          if (goalrecord->generatorGoals->memberP(parentgoal) ||
              goalrecord->otherGoals->memberP(parentgoal)) {
            return;
          }
          if (generatorP) {
            goalrecord->generatorGoals->insert(parentgoal);
          }
          else {
            goalrecord->otherGoals->insert(parentgoal);
          }
          oDISTRIBUTEDOPENGOALpo.set(true);
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PROPOSITION)) {
      { Object* argument001 = argument;
        Proposition* argument = ((Proposition*)(argument001));

        { Object* arg = NULL;
          Vector* vector000 = argument->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          for  (arg, vector000, index000, length000; 
                index000 < length000; 
                index000 = index000 + 1) {
            arg = (vector000->theArray)[index000];
            helpDistributeGoal(arg, parentgoal, generatorP);
          }
        }
      }
    }
    else {
    }
  }
}

void distributeOpenGoal(Proposition* goal) {
  { 
    BIND_STELLA_SPECIAL(oDISTRIBUTEDOPENGOALpo, boolean, false);
    { Keyword* testValue000 = goal->kind;

      if (testValue000 == KWD_OPTIMIZE_FUNCTION) {
        { Object* arg = NULL;
          Iterator* iter000 = goal->arguments->butLast();

          for (arg, iter000; iter000->nextP(); ) {
            arg = iter000->value;
            helpDistributeGoal(arg, goal, !computedPredicateP(goal));
          }
        }
        helpDistributeGoal((goal->arguments->theArray)[(goal->arguments->length() - 1)], goal, false);
      }
      else if (testValue000 == KWD_OPTIMIZE_EQUIVALENT) {
        { Object* arg = NULL;
          Vector* vector000 = goal->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          for  (arg, vector000, index000, length000; 
                index000 < length000; 
                index000 = index000 + 1) {
            arg = (vector000->theArray)[index000];
            helpDistributeGoal(arg, goal, false);
          }
        }
      }
      else if (testValue000 == KWD_OPTIMIZE_ISA) {
        helpDistributeGoal((goal->arguments->theArray)[0], goal, generatorCollectionP(getDescription(((Surrogate*)(goal->operatoR)))));
      }
      else if (testValue000 == KWD_OPTIMIZE_PREDICATE) {
        { Object* arg = NULL;
          Vector* vector001 = goal->arguments;
          int index001 = 0;
          int length001 = vector001->length();

          for  (arg, vector001, index001, length001; 
                index001 < length001; 
                index001 = index001 + 1) {
            arg = (vector001->theArray)[index001];
            helpDistributeGoal(arg, goal, !computedPredicateP(goal));
          }
        }
      }
      else if ((testValue000 == KWD_OPTIMIZE_NOT) ||
          (testValue000 == KWD_OPTIMIZE_FAIL)) {
        helpDistributeGoal((goal->arguments->theArray)[0], goal, false);
      }
      else if (testValue000 == KWD_OPTIMIZE_IMPLIES) {
        { Object* arg = NULL;
          Vector* vector002 = goal->arguments;
          int index002 = 0;
          int length002 = vector002->length();

          for  (arg, vector002, index002, length002; 
                index002 < length002; 
                index002 = index002 + 1) {
            arg = (vector002->theArray)[index002];
            helpDistributeGoal(arg, goal, true);
          }
        }
      }
      else {
      }
    }
    if (!oDISTRIBUTEDOPENGOALpo.get()) {
      oQUERYITERATORo.get()->residueGoals_reader()->insert(goal);
    }
  }
}

List* NamedDescription::uniquenessvectors_reader() {
  { NamedDescription* self = this;

    { List* answer = ((List*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_UNIQUENESSVECTORS, NULL)));

      if (!((boolean)(answer))) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

BooleanVector* V_0_0 = NULL;

BooleanVector* V_1_0 = NULL;

BooleanVector* V_0_1 = NULL;

BooleanVector* V_1_1 = NULL;

List* V_1_0_AND_V_0_1 = NULL;

List* V_1_0_SINGLETON = NULL;

List* V_0_1_SINGLETON = NULL;

List* getBinaryUniquenessVectors(NamedDescription* self) {
  { boolean singlevaluedinverseP = ((boolean)(((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_INVERSE_DESCRIPTION, NULL))))) &&
        singleValuedTermP(((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_INVERSE_DESCRIPTION, NULL))));

    if (singleValuedTermP(self)) {
      return ((singlevaluedinverseP ? V_1_0_AND_V_0_1 : V_1_0_SINGLETON));
    }
    else {
      return (((List*)((singlevaluedinverseP ? V_0_1_SINGLETON : NIL_LIST))));
    }
  }
}

List* getUniquenessVectors(NamedDescription* self) {
  if (self->arity() == 2) {
    return (getBinaryUniquenessVectors(self));
  }
  { List* cachedvectorlist = self->uniquenessvectors_reader();

    if (((boolean)(cachedvectorlist))) {
      return (cachedvectorlist);
    }
    else {
      return (NIL_LIST);
    }
  }
}

BooleanVector* getBinaryIndexingVector(NamedDescription* self) {
  { List* iovariabletypes = self->ioVariableTypes;
    Surrogate* typeone = ensureDeferredDescription(((Surrogate*)(iovariabletypes->nth(0))));
    Surrogate* typetwo = ensureDeferredDescription(((Surrogate*)(iovariabletypes->nth(1))));
    boolean bitoneP = typeHasBacklinksP(typeone);
    boolean bittwoP = typeHasBacklinksP(typetwo);

    if (bitoneP) {
      return ((bittwoP ? V_1_1 : V_1_0));
    }
    else {
      return ((bittwoP ? V_0_1 : V_0_0));
    }
  }
}

BooleanVector* getIndexingVector(NamedDescription* self) {
  if (self->arity() == 2) {
    return (getBinaryIndexingVector(self));
  }
  { BooleanVector* cachedvector = ((BooleanVector*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_INDEXING_VECTOR, NULL)));

    if (((boolean)(cachedvector))) {
      return (cachedvector);
    }
    { List* zeroonelist = newList();

      { Surrogate* type = NULL;
        Cons* iter000 = self->ioVariableTypes->theConsList;
        Cons* collect000 = NULL;

        for  (type, iter000, collect000; 
              !(iter000 == NIL); 
              iter000 = iter000->rest) {
          type = ((Surrogate*)(iter000->value));
          if (!((boolean)(collect000))) {
            {
              collect000 = cons((typeHasBacklinksP(ensureDeferredDescription(type)) ? ONE_WRAPPER : ZERO_WRAPPER), NIL);
              if (zeroonelist->theConsList == NIL) {
                zeroonelist->theConsList = collect000;
              }
              else {
                addConsToEndOfConsList(zeroonelist->theConsList, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons((typeHasBacklinksP(ensureDeferredDescription(type)) ? ONE_WRAPPER : ZERO_WRAPPER), NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      setDynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_INDEXING_VECTOR, zeroOneListToBooleanVector(zeroonelist), NULL);
      zeroonelist->free();
      return (((BooleanVector*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_INDEXING_VECTOR, NULL))));
    }
  }
}

// Estimate of the average size of a collection
// representing the fillers of a slot.
double ESTIMATED_SLOT_VALUE_COLLECTION_SIZE = 4.0;

// Very crude estimate of the number of stored propositions
// that will match a predicate at least one of whose arguments are bound.
// Chosen to be larger than ESTIMATED-SLOT-VALUE-COLLECTION-SIZE.
double ESTIMATED_NUMBER_OF_PREDICATE_BINDINGS = 6.0;

// Must be greater than ESTIMATED-NUMBER-OF-PREDICATE-BINDINGS
// to force the optimizer to prefer predicates containing at least
// one bound variable.  Also greater than ESTIMATED-SIZE-OF-PREDICATE-EXTENSION,
// for no particularly valid reason.
double ESTIMATED_SIZE_OF_CLASS_EXTENSION = 11.0;

// Indefensible estimate of the number instances
// generable by an arbitrary unnamed description.
double ESTIMATED_CARDINALITY_OF_DESCRIPTION = 20.0;

// Even more indefensible estimate of the number instances
// generable by a 'member-of' predicate.  CAUTION: Must be set
// less than 'ESTIMATED-CARDINALITY-OF-SUBSET-OF'.
double ESTIMATED_CARDINALITY_OF_MEMBER_OF = 30.0;

// Egregiously indefensible estimate of the number instances
// generable by a 'subset-of' predicate.  Set high because 'subset-of'
// can't generate all defined supersets or subsets, causing potential
// incompleteness.
double ESTIMATED_CARDINALITY_OF_SUBSET_OF = 40.0;

void updateObservedCardinality(NamedDescription* self, int cardinality) {
  { 
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
    { 
      BIND_STELLA_SPECIAL(oINVISIBLEASSERTIONpo, boolean, true);
      assertTuple(SGT_OPTIMIZE_PL_KERNEL_KB_OBSERVED_CARDINALITY_OF, consList(2, self, wrapInteger(cardinality)));
    }
  }
}

int accessObservedCardinality(Description* self) {
  { 
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
    { Object* value = accessBinaryValue(self, SGT_OPTIMIZE_PL_KERNEL_KB_OBSERVED_CARDINALITY_OF);

      if (((boolean)(value)) &&
          isaP(value, SGT_OPTIMIZE_STELLA_INTEGER_WRAPPER)) {
        return (((IntegerWrapper*)(value))->wrapperValue);
      }
      else {
        return (NULL_INTEGER);
      }
    }
  }
}

double estimateCardinalityOfExtension(NamedDescription* description) {
  if ((!((boolean)(description))) ||
      (!relationSupportsExtensionP(description))) {
    return (NULL_FLOAT);
  }
  { int estimate = accessObservedCardinality(description);

    if ((estimate == NULL_INTEGER) &&
        ((boolean)(description->extension))) {
      estimate = description->extension->estimatedLength();
    }
    if (estimate == NULL_INTEGER) {
      estimate = 0;
    }
    return (((double)(stella::max(estimate, (classDescriptionP(description) ? ((int)(ESTIMATED_SIZE_OF_CLASS_EXTENSION)) : ((int)(ESTIMATED_NUMBER_OF_PREDICATE_BINDINGS * ESTIMATED_NUMBER_OF_PREDICATE_BINDINGS * ESTIMATED_NUMBER_OF_PREDICATE_BINDINGS)))))));
  }
}

double estimateMemberOfGoalFanout(Proposition* goal) {
  { Object* membervalue = argumentBoundTo((goal->arguments->theArray)[0]);
    Object* collectionvalue = argumentBoundTo((goal->arguments->theArray)[1]);

    if (((boolean)(membervalue))) {
      return (ESTIMATED_CARDINALITY_OF_MEMBER_OF);
    }
    else if (((boolean)(collectionvalue))) {
      { Surrogate* testValue000 = safePrimaryType(collectionvalue);

        if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_DESCRIPTION)) {
          { Object* collectionvalue000 = collectionvalue;
            Description* collectionvalue = ((Description*)(collectionvalue000));

            return ((isaP(collectionvalue, SGT_OPTIMIZE_LOGIC_NAMED_DESCRIPTION) ? estimateCardinalityOfExtension(((NamedDescription*)(collectionvalue))) : ESTIMATED_CARDINALITY_OF_DESCRIPTION));
          }
        }
        else if (subtypeOfP(testValue000, SGT_OPTIMIZE_STELLA_COLLECTION)) {
          { Object* collectionvalue001 = collectionvalue;
            Collection* collectionvalue = ((Collection*)(collectionvalue001));

            return (((double)(collectionvalue->length())));
          }
        }
        else {
          return (ESTIMATED_SLOT_VALUE_COLLECTION_SIZE);
        }
      }
    }
    else {
      return (NULL_FLOAT);
    }
  }
}

double estimatePredicateGoalFanout(Proposition* goal) {
  if (goal->operatoR == SGT_OPTIMIZE_PL_KERNEL_KB_MEMBER_OF) {
    return (estimateMemberOfGoalFanout(goal));
  }
  { NamedDescription* description = getDescription(((Surrogate*)(goal->operatoR)));
    BooleanVector* goalvector = argumentsVectorToBooleanVector(goal->arguments);

    if (!((boolean)(description))) {
      return (NULL_FLOAT);
    }
    { boolean testValue000 = false;

      { boolean foundP000 = false;

        { BooleanWrapper* gbit = NULL;
          BooleanVector* vector000 = goalvector;
          int index000 = 0;
          int length000 = vector000->length();
          BooleanWrapper* ibit = NULL;
          BooleanVector* vector001 = getIndexingVector(description);
          int index001 = 0;
          int length001 = vector001->length();

          for  (gbit, vector000, index000, length000, ibit, vector001, index001, length001; 
                (index000 < length000) &&
                    (index001 < length001); 
                index000 = index000 + 1,
                index001 = index001 + 1) {
            gbit = ((BooleanWrapper*)((vector000->theArray)[index000]));
            ibit = ((BooleanWrapper*)((vector001->theArray)[index001]));
            if ((ibit == TRUE_WRAPPER) &&
                (gbit == TRUE_WRAPPER)) {
              foundP000 = true;
              break;
            }
          }
        }
        testValue000 = foundP000;
      }
      testValue000 = !testValue000;
      if (testValue000) {
        return (estimateCardinalityOfExtension(getDescription(((Surrogate*)(goal->operatoR)))));
      }
    }
    { boolean allbitsmatchP = false;

      { BooleanVector* uniquenesskey = NULL;
        Cons* iter000 = getUniquenessVectors(description)->theConsList;

        for (uniquenesskey, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
          uniquenesskey = ((BooleanVector*)(iter000->value));
          allbitsmatchP = true;
          { BooleanWrapper* ubit = NULL;
            BooleanVector* vector002 = uniquenesskey;
            int index002 = 0;
            int length002 = vector002->length();
            BooleanWrapper* gbit = NULL;
            BooleanVector* vector003 = goalvector;
            int index003 = 0;
            int length003 = vector003->length();

            for  (ubit, vector002, index002, length002, gbit, vector003, index003, length003; 
                  (index002 < length002) &&
                      (index003 < length003); 
                  index002 = index002 + 1,
                  index003 = index003 + 1) {
              ubit = ((BooleanWrapper*)((vector002->theArray)[index002]));
              gbit = ((BooleanWrapper*)((vector003->theArray)[index003]));
              if ((ubit == TRUE_WRAPPER) &&
                  (gbit == FALSE_WRAPPER)) {
                allbitsmatchP = false;
                break;
              }
            }
          }
          if (allbitsmatchP) {
            return (1.0);
          }
        }
      }
      return (ESTIMATED_NUMBER_OF_PREDICATE_BINDINGS);
    }
  }
}

// Amount of penalty for using inferable relations as goals.
double INFERABLE_PENALTY_COST = 7.0;

// Amount of penalty for using 'subset-of' as a goal.
double SUBSET_OF_PENALTY_COST = 20.0;

double estimateGoalCost(Proposition* goal) {
  { Keyword* testValue000 = goal->kind;

    if ((testValue000 == KWD_OPTIMIZE_ISA) ||
        ((testValue000 == KWD_OPTIMIZE_FUNCTION) ||
         (testValue000 == KWD_OPTIMIZE_PREDICATE))) {
      { NamedDescription* description = getDescription(((Surrogate*)(goal->operatoR)));

        if ((!((boolean)(description))) ||
            (!inferableP(description))) {
          return (1.0);
        }
        else {
          return (INFERABLE_PENALTY_COST);
        }
      }
    }
    else if (testValue000 == KWD_OPTIMIZE_IMPLIES) {
      return (SUBSET_OF_PENALTY_COST);
    }
    else {
      return (1.0);
    }
  }
}

double estimateGoalFanout(Proposition* goal) {
  { Keyword* testValue000 = goal->kind;

    if (testValue000 == KWD_OPTIMIZE_ISA) {
      return (estimateCardinalityOfExtension(getDescription(((Surrogate*)(goal->operatoR)))));
    }
    else if ((testValue000 == KWD_OPTIMIZE_FUNCTION) ||
        (testValue000 == KWD_OPTIMIZE_PREDICATE)) {
      return (estimatePredicateGoalFanout(goal));
    }
    else if (testValue000 == KWD_OPTIMIZE_IMPLIES) {
      return (ESTIMATED_CARDINALITY_OF_SUBSET_OF);
    }
    else if (testValue000 == KWD_OPTIMIZE_EQUIVALENT) {
      if (argumentBoundP((goal->arguments->theArray)[0]) ||
          argumentBoundP((goal->arguments->theArray)[1])) {
        return (1.0);
      }
      else {
        return (NULL_FLOAT);
      }
    }
    else if ((testValue000 == KWD_OPTIMIZE_NOT) ||
        (testValue000 == KWD_OPTIMIZE_FAIL)) {
      return (NULL_FLOAT);
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

Proposition* cheapestGeneratorGoal(PatternVariable* variable, double& _Return1, double& _Return2) {
  if (((boolean)(oTRACED_KEYWORDSo)) &&
      oTRACED_KEYWORDSo->membP(KWD_OPTIMIZE_OPTIMIZER)) {
    std::cout << std::endl << "CHEAPEST: " << variable << " GENERATORS: " << goalRecord(variable)->generatorGoals << std::endl;
  }
  { Proposition* bestgoal = NULL;
    double bestcost = NULL_FLOAT;
    double bestfanout = NULL_FLOAT;
    double generatorcost = NULL_FLOAT;
    double generatorfanout = NULL_FLOAT;

    { Proposition* goal = NULL;
      Cons* iter000 = goalRecord(variable)->generatorGoals->theConsList;

      for (goal, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        goal = ((Proposition*)(iter000->value));
        generatorcost = estimateGoalCost(goal);
        generatorfanout = estimateGoalFanout(goal);
        if ((generatorfanout != NULL_FLOAT) &&
            ((bestfanout == NULL_FLOAT) ||
             ((generatorfanout < bestfanout) ||
              ((generatorfanout == bestfanout) &&
               (generatorcost < bestcost))))) {
          if ((generatorfanout == 1.0) &&
              (generatorcost == 1.0)) {
            _Return1 = 1.0;
            _Return2 = 1.0;
            return (goal);
          }
          bestgoal = goal;
          bestfanout = generatorfanout;
          bestcost = generatorcost;
        }
      }
    }
    if (bestfanout != NULL_FLOAT) {
      {
        if (((boolean)(oTRACED_KEYWORDSo)) &&
            oTRACED_KEYWORDSo->membP(KWD_OPTIMIZE_OPTIMIZER)) {
          std::cout << "  SELECTED: " << bestgoal << "  " << bestcost << "  " << bestfanout << std::endl;
        }
        _Return1 = bestcost;
        _Return2 = bestfanout;
        return (bestgoal);
      }
    }
    else {
      _Return1 = 0.0;
      _Return2 = 0.0;
      return (NULL);
    }
  }
}

void propagateSingleValuedConstraints(Proposition* goal, List* goalsequence) {
  { Vector* arguments = goal->arguments;

    { Keyword* testValue000 = goal->kind;

      if ((testValue000 == KWD_OPTIMIZE_FUNCTION) ||
          (testValue000 == KWD_OPTIMIZE_PREDICATE)) {
        if (singleValuedTermP(getDescription(((Surrogate*)(goal->operatoR))))) {
          { boolean testValue001 = false;

            { boolean alwaysP000 = true;

              { Object* arg = NULL;
                Iterator* iter000 = arguments->butLast();

                for (arg, iter000; iter000->nextP(); ) {
                  arg = iter000->value;
                  if (!argumentBoundP(arg)) {
                    alwaysP000 = false;
                    break;
                  }
                }
              }
              testValue001 = alwaysP000;
            }
            if (testValue001) {
              testValue001 = unboundVariableP(arguments->last());
            }
            if (testValue001) {
              {
                if (!goalsequence->memberP(goal)) {
                  goalsequence->push(goal);
                }
                simulateBindVariableAndPropagateConstraints(((PatternVariable*)(arguments->last())), goalsequence);
              }
            }
            else {
              {
              }
            }
          }
        }
      }
      else if ((testValue000 == KWD_OPTIMIZE_ISA) ||
          (testValue000 == KWD_OPTIMIZE_IMPLIES)) {
      }
      else if (testValue000 == KWD_OPTIMIZE_EQUIVALENT) {
        if (unboundVariableP((arguments->theArray)[0])) {
          goalsequence->push(goal);
          simulateBindVariableAndPropagateConstraints(((PatternVariable*)((arguments->theArray)[0])), goalsequence);
        }
        else if (unboundVariableP((arguments->theArray)[1])) {
          goalsequence->push(goal);
          simulateBindVariableAndPropagateConstraints(((PatternVariable*)((arguments->theArray)[1])), goalsequence);
        }
      }
      else if ((testValue000 == KWD_OPTIMIZE_NOT) ||
          (testValue000 == KWD_OPTIMIZE_FAIL)) {
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
  }
}

void collectClosedGoals(List* goals, List* goalsequence) {
  { Proposition* g = NULL;
    Cons* iter000 = goals->theConsList;

    for (g, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
      g = ((Proposition*)(iter000->value));
      if (allArgumentsBoundP(g) &&
          (!goalsequence->memberP(g))) {
        goalsequence->push(g);
      }
    }
  }
}

void simulateBindVariableAndPropagateConstraints(PatternVariable* variable, List* goalsequence) {
  { GoalRecord* goalrecord = goalRecord(variable);

    simulateBindVariableToValue(variable);
    collectClosedGoals(goalrecord->generatorGoals, goalsequence);
    collectClosedGoals(goalrecord->otherGoals, goalsequence);
    { Proposition* g = NULL;
      Cons* iter000 = goalrecord->generatorGoals->theConsList;

      for (g, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        g = ((Proposition*)(iter000->value));
        propagateSingleValuedConstraints(g, goalsequence);
      }
    }
    { Proposition* g = NULL;
      Cons* iter001 = goalrecord->otherGoals->theConsList;

      for (g, iter001; !(iter001 == NIL); iter001 = iter001->rest) {
        g = ((Proposition*)(iter001->value));
        propagateSingleValuedConstraints(g, goalsequence);
      }
    }
  }
}

void bindAllVariablesInGeneratorGoal(Proposition* goal, List* goalsequence) {
  { Object* arg = NULL;
    Vector* vector000 = goal->arguments;
    int index000 = 0;
    int length000 = vector000->length();

    for  (arg, vector000, index000, length000; 
          index000 < length000; 
          index000 = index000 + 1) {
      arg = (vector000->theArray)[index000];
      if (isaP(arg, SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE) &&
          unboundVariableP(arg)) {
        simulateBindVariableAndPropagateConstraints(((PatternVariable*)(arg)), goalsequence);
      }
    }
  }
}

DEFINE_STELLA_SPECIAL(oOPTIMALGOALORDERINGRECURSIONSo, int , NULL_INTEGER);

int oOPTIMAL_GOAL_ORDERING_CUTOFFo = 100;

void computeOptimalOpenGoalOrdering(List* optimizervariables, int numberofopengoals, List* goalsequence, double priorcost, double priorfanout) {
  { Cons* goalsequencecheckpoint = NULL;
    int choicepointunbindingoffset = NULL_INTEGER;
    double cumulativecost = NULL_FLOAT;
    double cumulativefanout = NULL_FLOAT;

    if (oOPTIMALGOALORDERINGRECURSIONSo.get() >= oOPTIMAL_GOAL_ORDERING_CUTOFFo) {
      return;
    }
    else {
      oOPTIMALGOALORDERINGRECURSIONSo.set(oOPTIMALGOALORDERINGRECURSIONSo.get() + 1);
    }
    if (optimizervariables->emptyP()) {
      setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_GOAL_SEQUENCE, goalsequence, NULL);
      return;
    }
    { PatternVariable* vbl = NULL;
      Cons* iter000 = optimizervariables->theConsList;

      for (vbl, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        vbl = ((PatternVariable*)(iter000->value));
        if (!variableBoundP(vbl)) {
          { Proposition* generatorgoal = NULL;
            double generatorcost = NULL_FLOAT;
            double generatorfanout = NULL_FLOAT;

            generatorgoal = cheapestGeneratorGoal(vbl, generatorcost, generatorfanout);
            if (!((boolean)(generatorgoal))) {
              continue;
            }
            cumulativefanout = priorfanout * generatorfanout;
            cumulativecost = priorcost + (cumulativefanout * generatorcost);
            if ((cumulativecost == NULL_FLOAT) ||
                (cumulativecost < priorcost)) {
              continue;
            }
            if ((((FloatWrapper*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_COST, NULL_FLOAT_WRAPPER)))->wrapperValue != NULL_FLOAT) &&
                (cumulativecost >= ((FloatWrapper*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_COST, NULL_FLOAT_WRAPPER)))->wrapperValue)) {
              continue;
            }
            goalsequencecheckpoint = goalsequence->theConsList;
            choicepointunbindingoffset = simulateCreateChoicePoint();
            goalsequence->push(generatorgoal);
            bindAllVariablesInGeneratorGoal(generatorgoal, goalsequence);
          }
          if (goalsequence->length() == numberofopengoals) {
            if ((((FloatWrapper*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_COST, NULL_FLOAT_WRAPPER)))->wrapperValue == NULL_FLOAT) ||
                (cumulativecost < ((FloatWrapper*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_COST, NULL_FLOAT_WRAPPER)))->wrapperValue)) {
              setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_COST, wrapFloat(cumulativecost), NULL_FLOAT_WRAPPER);
              setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_GOAL_SEQUENCE, goalsequence->copy(), NULL);
            }
          }
          else {
            computeOptimalOpenGoalOrdering(optimizervariables, numberofopengoals, goalsequence, cumulativecost, cumulativefanout);
          }
          goalsequence->theConsList = goalsequencecheckpoint;
          unbindVariablesBeginningAt(oQUERYITERATORo.get()->currentPatternRecord, choicepointunbindingoffset);
        }
      }
    }
  }
}

void computeGreedyOpenGoalOrdering(List* optimizervariables, int numberofopengoals, List* goalsequence, double priorcost, double priorfanout) {
  { Cons* goalsequencecheckpoint = NULL;
    int choicepointunbindingoffset = NULL_INTEGER;
    Proposition* bestgeneratorgoal = NULL;
    double bestgeneratorfanout = NULL_FLOAT;
    double bestcombinedcost = NULL_FLOAT;
    int opengoalreduction = NULL_INTEGER;

    if (optimizervariables->emptyP()) {
      setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_GOAL_SEQUENCE, goalsequence, NULL);
      return;
    }
    for (;;) {
      bestgeneratorgoal = NULL;
      bestgeneratorfanout = NULL_FLOAT;
      bestcombinedcost = NULL_FLOAT;
      { PatternVariable* vbl = NULL;
        Cons* iter000 = optimizervariables->theConsList;

        for (vbl, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
          vbl = ((PatternVariable*)(iter000->value));
          if (!variableBoundP(vbl)) {
            { Proposition* generatorgoal = NULL;
              double generatorcost = NULL_FLOAT;
              double generatorfanout = NULL_FLOAT;

              generatorgoal = cheapestGeneratorGoal(vbl, generatorcost, generatorfanout);
              if (!((boolean)(generatorgoal))) {
                continue;
              }
              goalsequencecheckpoint = goalsequence->theConsList;
              choicepointunbindingoffset = simulateCreateChoicePoint();
              goalsequence->push(generatorgoal);
              bindAllVariablesInGeneratorGoal(generatorgoal, goalsequence);
              opengoalreduction = ceiling((((double)(goalsequence->length() - goalsequencecheckpoint->length())) / numberofopengoals) * 100);
              { double combinedcost = (generatorfanout + generatorcost) - opengoalreduction;

                if ((bestcombinedcost == NULL_FLOAT) ||
                    (combinedcost < bestcombinedcost)) {
                  bestgeneratorgoal = generatorgoal;
                  bestgeneratorfanout = generatorfanout;
                  bestcombinedcost = combinedcost;
                }
              }
              goalsequence->theConsList = goalsequencecheckpoint;
              unbindVariablesBeginningAt(oQUERYITERATORo.get()->currentPatternRecord, choicepointunbindingoffset);
            }
          }
        }
      }
      if (!((boolean)(bestgeneratorgoal))) {
        if (goalsequence->length() == numberofopengoals) {
          setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_COST, wrapFloat(priorcost), NULL_FLOAT_WRAPPER);
          setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_GOAL_SEQUENCE, goalsequence, NULL);
        }
        return;
      }
      priorfanout = priorfanout * bestgeneratorfanout;
      goalsequence->push(bestgeneratorgoal);
      bindAllVariablesInGeneratorGoal(bestgeneratorgoal, goalsequence);
    }
  }
}

void computeBackupOpenGoalOrdering(List* goalsequence) {
  { Proposition* g = NULL;
    Cons* iter000 = goalsequence->theConsList;

    for (g, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
      g = ((Proposition*)(iter000->value));
      if ((estimateGoalCost(g) == NULL_FLOAT) &&
          coerceWrappedBooleanToBoolean(g->variableTypeP_reader())) {
        oQUERYITERATORo.get()->residueGoals_reader()->insertLast(g);
      }
      else {
        oQUERYITERATORo.get()->bestGoalSequence_reader()->push(g);
      }
    }
  }
}

void collectUnboundGoalVariables(Proposition* goal, List* unboundvariables) {
  { Object* arg = NULL;
    Vector* vector000 = goal->arguments;
    int index000 = 0;
    int length000 = vector000->length();

    for  (arg, vector000, index000, length000; 
          index000 < length000; 
          index000 = index000 + 1) {
      arg = (vector000->theArray)[index000];
      { Surrogate* testValue000 = safePrimaryType(arg);

        if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
          { Object* arg000 = arg;
            PatternVariable* arg = ((PatternVariable*)(arg000));

            if (unboundVariableP(arg)) {
              unboundvariables->insertNew(arg);
            }
          }
        }
        else if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PROPOSITION)) {
          { Object* arg001 = arg;
            Proposition* arg = ((Proposition*)(arg001));

            collectUnboundGoalVariables(arg, unboundvariables);
            { Keyword* testValue001 = arg->kind;

              if ((testValue001 == KWD_OPTIMIZE_FORALL) ||
                  (testValue001 == KWD_OPTIMIZE_EXISTS)) {
                { PatternVariable* var = NULL;
                  Vector* vector001 = ((Vector*)(dynamicSlotValue(arg->dynamicSlots, SYM_OPTIMIZE_LOGIC_IO_VARIABLES, NULL)));
                  int index001 = 0;
                  int length001 = vector001->length();

                  for  (var, vector001, index001, length001; 
                        index001 < length001; 
                        index001 = index001 + 1) {
                    var = ((PatternVariable*)((vector001->theArray)[index001]));
                    unboundvariables->remove(var);
                  }
                }
              }
              else {
              }
            }
          }
        }
        else {
        }
      }
    }
  }
}

void extractOpenGoalClusters(List* opengoals, List* opengoalclusters) {
  { Cons* allgoals = copyConsList(opengoals->theConsList);
    Cons* remaininggoals = allgoals;
    Cons* cursor = NULL;
    Proposition* goal = NULL;
    List* clusters = newList();
    List* currentcluster = NULL;
    List* currentclustervars = newList();
    boolean currentclustervarsgrewP = false;
    List* unboundgoalvars = newList();

    for (;;) {
      currentclustervars->clear();
      for (;;) {
        if (remaininggoals == NIL) {
          break;
        }
        if (((boolean)(((Proposition*)(remaininggoals->value))))) {
          collectUnboundGoalVariables(((Proposition*)(remaininggoals->value)), currentclustervars);
        }
        if (currentclustervars->nonEmptyP()) {
          break;
        }
        else {
          remaininggoals = remaininggoals->rest;
        }
      }
      if (currentclustervars->emptyP()) {
        break;
      }
      currentcluster = newList();
      currentcluster->insert(((Proposition*)(remaininggoals->value)));
      remaininggoals->firstSetter(NULL);
      remaininggoals = remaininggoals->rest;
      for (;;) {
        currentclustervarsgrewP = false;
        cursor = remaininggoals;
        while (!(cursor == NIL)) {
          goal = ((Proposition*)(cursor->value));
          if (((boolean)(goal))) {
            unboundgoalvars->clear();
            collectUnboundGoalVariables(goal, unboundgoalvars);
            { boolean foundP000 = false;

              { PatternVariable* var = NULL;
                Cons* iter000 = unboundgoalvars->theConsList;

                for (var, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
                  var = ((PatternVariable*)(iter000->value));
                  if (currentclustervars->memberP(var)) {
                    foundP000 = true;
                    break;
                  }
                }
              }
              if (foundP000) {
                currentcluster->push(goal);
                cursor->firstSetter(NULL);
                { PatternVariable* var = NULL;
                  Cons* iter001 = unboundgoalvars->theConsList;

                  for (var, iter001; !(iter001 == NIL); iter001 = iter001->rest) {
                    var = ((PatternVariable*)(iter001->value));
                    if (!currentclustervars->memberP(var)) {
                      currentclustervars->insert(var);
                      currentclustervarsgrewP = true;
                    }
                  }
                }
              }
            }
          }
          cursor = cursor->rest;
        }
        if (!currentclustervarsgrewP) {
          break;
        }
      }
      clusters->push(currentcluster->reverse());
    }
    currentclustervars->free();
    if (clusters->length() >= 2) {
      opengoals->clear();
      opengoals->theConsList = allgoals->remove(NULL);
      { List* cluster = NULL;
        Cons* iter002 = clusters->reverse()->theConsList;
        Cons* collect000 = NULL;

        for  (cluster, iter002, collect000; 
              !(iter002 == NIL); 
              iter002 = iter002->rest) {
          cluster = ((List*)(iter002->value));
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(cluster, NIL);
              if (opengoalclusters->theConsList == NIL) {
                opengoalclusters->theConsList = collect000;
              }
              else {
                addConsToEndOfConsList(opengoalclusters->theConsList, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(cluster, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    else {
      if (((boolean)(currentcluster))) {
        currentcluster->free();
      }
    }
    clusters->free();
  }
}

void collectOptimizerVariables(Proposition* proposition, List* collection) {
  { Keyword* testValue000 = proposition->kind;

    if ((testValue000 == KWD_OPTIMIZE_ISA) ||
        ((testValue000 == KWD_OPTIMIZE_FUNCTION) ||
         ((testValue000 == KWD_OPTIMIZE_PREDICATE) ||
          ((testValue000 == KWD_OPTIMIZE_EQUIVALENT) ||
           (testValue000 == KWD_OPTIMIZE_IMPLIES))))) {
      { Object* arg = NULL;
        Vector* vector000 = proposition->arguments;
        int index000 = 0;
        int length000 = vector000->length();

        for  (arg, vector000, index000, length000; 
              index000 < length000; 
              index000 = index000 + 1) {
          arg = (vector000->theArray)[index000];
          if (unboundVariableP(arg)) {
            { PatternVariable* variable = ((PatternVariable*)(arg));

              if (!(variable == innermostOf(variable))) {
                simulateBindVariableToValue(variable);
              }
              else if ((!((boolean)(variable->definingProposition))) &&
                  (!anonymousVariableP(variable))) {
                collection->insertNew(variable);
              }
            }
          }
        }
      }
    }
    else {
    }
  }
}

boolean biggerConjunctionP(Proposition* prop1, Proposition* prop2) {
  return (prop1->arguments->length() > prop2->arguments->length());
}

void computeOpenGoalOrdering(Proposition* andproposition, List* opengoals, List* goalsequence) {
  { List* opengoalclusters = newList();
    List* clusterpropositions = NIL_LIST;
    List* optimizervariables = newList();
    Cons* initialgoalsequence = NULL;
    Cons* initialresiduegoals = NULL;

    if (oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_STATIC_WITH_CLUSTERING) {
      extractOpenGoalClusters(opengoals, opengoalclusters);
    }
    if (opengoalclusters->nonEmptyP()) {
      clusterpropositions = newList();
      { 
        BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_OPTIMIZE_DESCRIPTION);
        { List* cluster = NULL;
          Cons* iter000 = opengoalclusters->theConsList;
          Cons* collect000 = NULL;

          for  (cluster, iter000, collect000; 
                !(iter000 == NIL); 
                iter000 = iter000->rest) {
            cluster = ((List*)(iter000->value));
            if (!((boolean)(collect000))) {
              {
                collect000 = cons(((cluster->length() > 1) ? fastenDownOneProposition(conjoinPropositions(cluster->theConsList), true) : ((Proposition*)(cluster->first()))), NIL);
                if (clusterpropositions->theConsList == NIL) {
                  clusterpropositions->theConsList = collect000;
                }
                else {
                  addConsToEndOfConsList(clusterpropositions->theConsList, collect000);
                }
              }
            }
            else {
              {
                collect000->rest = cons(((cluster->length() > 1) ? fastenDownOneProposition(conjoinPropositions(cluster->theConsList), true) : ((Proposition*)(cluster->first()))), NIL);
                collect000 = collect000->rest;
              }
            }
          }
        }
      }
      { Proposition* prop = NULL;
        Cons* iter001 = clusterpropositions->theConsList;
        Cons* collect001 = NULL;

        for  (prop, iter001, collect001; 
              !(iter001 == NIL); 
              iter001 = iter001->rest) {
          prop = ((Proposition*)(iter001->value));
          if (!(prop->kind == KWD_OPTIMIZE_AND)) {
            if (!((boolean)(collect001))) {
              {
                collect001 = cons(prop, NIL);
                if (opengoals->theConsList == NIL) {
                  opengoals->theConsList = collect001;
                }
                else {
                  addConsToEndOfConsList(opengoals->theConsList, collect001);
                }
              }
            }
            else {
              {
                collect001->rest = cons(prop, NIL);
                collect001 = collect001->rest;
              }
            }
          }
        }
      }
      { ListIterator* it = ((ListIterator*)(goalsequence->allocateIterator()));

        for (it; it->nextP(); ) {
          if (!opengoals->memberP(((Proposition*)(it->value)))) {
            it->valueSetter(NULL);
          }
        }
      }
      goalsequence->remove(NULL);
    }
    opengoalclusters->free();
    initialgoalsequence = goalsequence->theConsList;
    initialresiduegoals = oQUERYITERATORo.get()->residueGoals_reader()->theConsList;
    { Proposition* goal = NULL;
      Cons* iter002 = opengoals->theConsList;

      for (goal, iter002; !(iter002 == NIL); iter002 = iter002->rest) {
        goal = ((Proposition*)(iter002->value));
        collectOptimizerVariables(goal, optimizervariables);
      }
    }
    { 
      BIND_STELLA_SPECIAL(oOPTIMALGOALORDERINGRECURSIONSo, int, 0);
      computeOptimalOpenGoalOrdering(optimizervariables, opengoals->length(), goalsequence, 1.0, 1.0);
      if (oOPTIMALGOALORDERINGRECURSIONSo.get() >= oOPTIMAL_GOAL_ORDERING_CUTOFFo) {
        goalsequence->theConsList = initialgoalsequence;
        oQUERYITERATORo.get()->residueGoals_reader()->theConsList = initialresiduegoals;
        oQUERYITERATORo.get()->bestGoalSequence_reader()->clear();
        setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_COST, wrapFloat(NULL_FLOAT), NULL_FLOAT_WRAPPER);
        computeGreedyOpenGoalOrdering(optimizervariables, opengoals->length(), goalsequence, 1.0, 1.0);
      }
    }
    if (oQUERYITERATORo.get()->bestGoalSequence_reader()->emptyP() &&
        (!opengoals->emptyP())) {
      computeBackupOpenGoalOrdering(opengoals->reverse());
      if (((boolean)(oTRACED_KEYWORDSo)) &&
          oTRACED_KEYWORDSo->membP(KWD_OPTIMIZE_OPTIMIZER)) {
        std::cout << "Using backup goal ordering:" << std::endl << "Original Goal: " << andproposition << std::endl;
      }
    }
    { Proposition* prop = NULL;
      Cons* iter003 = clusterpropositions->sort(((cpp_function_code)(&biggerConjunctionP)))->theConsList;

      for (prop, iter003; !(iter003 == NIL); iter003 = iter003->rest) {
        prop = ((Proposition*)(iter003->value));
        if (prop->kind == KWD_OPTIMIZE_AND) {
          oQUERYITERATORo.get()->bestGoalSequence_reader()->push(prop);
        }
      }
    }
  }
}

void optimizeOrderingOfConjuncts(Proposition* andproposition) {
  { List* initiallyclosedgoals = newList();
    List* opengoals = newList();
    List* goalsequence = newList();

    { Object* g = NULL;
      Vector* vector000 = andproposition->arguments;
      int index000 = 0;
      int length000 = vector000->length();

      for  (g, vector000, index000, length000; 
            index000 < length000; 
            index000 = index000 + 1) {
        g = (vector000->theArray)[index000];
        if (allArgumentsBoundP(((Proposition*)(g)))) {
          initiallyclosedgoals->insert(((Proposition*)(g)));
        }
        else if (hasDisjunctionP(((Proposition*)(g))) ||
            (((Proposition*)(g))->kind == KWD_OPTIMIZE_FORALL)) {
          oQUERYITERATORo.get()->residueGoals_reader()->insert(((Proposition*)(g)));
        }
        else {
          opengoals->insert(((Proposition*)(g)));
        }
      }
    }
    { Proposition* goal = NULL;
      Cons* iter000 = opengoals->theConsList;

      for (goal, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        goal = ((Proposition*)(iter000->value));
        distributeOpenGoal(goal);
      }
    }
    { Proposition* g = NULL;
      Cons* iter001 = opengoals->theConsList;

      for (g, iter001; !(iter001 == NIL); iter001 = iter001->rest) {
        g = ((Proposition*)(iter001->value));
        { boolean foundP000 = false;

          { Object* arg = NULL;
            Vector* vector001 = g->arguments;
            int index001 = 0;
            int length001 = vector001->length();

            for  (arg, vector001, index001, length001; 
                  index001 < length001; 
                  index001 = index001 + 1) {
              arg = (vector001->theArray)[index001];
              if (argumentBoundP(arg)) {
                foundP000 = true;
                break;
              }
            }
          }
          if (foundP000) {
            propagateSingleValuedConstraints(g, goalsequence);
          }
        }
      }
    }
    computeOpenGoalOrdering(andproposition, opengoals, goalsequence);
    reorderGoals(andproposition, initiallyclosedgoals->reverse(), oQUERYITERATORo.get()->bestGoalSequence_reader()->reverse(), oQUERYITERATORo.get()->residueGoals_reader());
    if (((boolean)(oTRACED_KEYWORDSo)) &&
        oTRACED_KEYWORDSo->membP(KWD_OPTIMIZE_OPTIMIZER)) {
      std::cout << "Optimized goal: " << andproposition << std::endl;
    }
  }
}

void reorderGoals(Proposition* andproposition, List* initiallyclosedgoals, List* goalsequence, List* residuegoals) {
  { Vector* arguments = andproposition->arguments;
    int originalnumberofarguments = arguments->length();
    int index = 0;

    { Proposition* g = NULL;
      Cons* iter000 = initiallyclosedgoals->theConsList;

      for (g, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        g = ((Proposition*)(iter000->value));
        (arguments->theArray)[index] = g;
        index = index + 1;
      }
    }
    { Proposition* g = NULL;
      Cons* iter001 = goalsequence->theConsList;

      for (g, iter001; !(iter001 == NIL); iter001 = iter001->rest) {
        g = ((Proposition*)(iter001->value));
        residuegoals->remove(g);
        (arguments->theArray)[index] = g;
        index = index + 1;
      }
    }
    { Proposition* g = NULL;
      Cons* iter002 = residuegoals->theConsList;

      for (g, iter002; !(iter002 == NIL); iter002 = iter002->rest) {
        g = ((Proposition*)(iter002->value));
        (arguments->theArray)[index] = g;
        index = index + 1;
      }
    }
    if (index < originalnumberofarguments) {
      andproposition->arguments = newVector(index);
      { Object* arg = NULL;
        Vector* vector000 = arguments;
        int index000 = 0;
        int length000 = vector000->length();
        int i = NULL_INTEGER;
        int iter003 = 0;
        int upperBound000 = index - 1;

        for  (arg, vector000, index000, length000, i, iter003, upperBound000; 
              (index000 < length000) &&
                  (iter003 <= upperBound000); 
              index000 = index000 + 1,
              iter003 = iter003 + 1) {
          arg = (vector000->theArray)[index000];
          i = iter003;
          (andproposition->arguments->theArray)[i] = arg;
        }
      }
    }
  }
}

void simulateBindVariableToValue(Object* formula) {
  if (subtypeOfP(safePrimaryType(formula), SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
    { Object* formula000 = formula;
      PatternVariable* formula = ((PatternVariable*)(formula000));

      if (!argumentBoundP(formula)) {
        setPatternVariableBinding(formula, KWD_OPTIMIZE_BOUND);
      }
    }
  }
  else {
  }
}

void warnOfUnboundVariableArgument(Proposition* proposition) {
  return;
}

void simulateGoalEvaluation(Proposition* goal) {
  { Vector* arguments = goal->arguments;
    boolean okP = false;

    { Keyword* testValue000 = goal->kind;

      if (testValue000 == KWD_OPTIMIZE_FUNCTION) {
        { boolean chooseValue000 = false;

          if (computedPredicateP(goal)) {
            { boolean alwaysP000 = true;

              { Object* arg = NULL;
                Iterator* iter000 = arguments->butLast();

                for (arg, iter000; iter000->nextP(); ) {
                  arg = iter000->value;
                  if (!argumentBoundP(arg)) {
                    alwaysP000 = false;
                    break;
                  }
                }
              }
              chooseValue000 = alwaysP000;
            }
          }
          else {
            { boolean foundP000 = false;

              { Object* arg = NULL;
                Vector* vector000 = arguments;
                int index000 = 0;
                int length000 = vector000->length();

                for  (arg, vector000, index000, length000; 
                      index000 < length000; 
                      index000 = index000 + 1) {
                  arg = (vector000->theArray)[index000];
                  if (argumentBoundP(arg) &&
                      typeHasBacklinksP(ensureDeferredDescription(logicalType(arg)))) {
                    foundP000 = true;
                    break;
                  }
                }
              }
              chooseValue000 = foundP000;
            }
          }
          okP = chooseValue000;
        }
      }
      else if (testValue000 == KWD_OPTIMIZE_PREDICATE) {
        if (goal->operatoR == SGT_OPTIMIZE_PL_KERNEL_KB_MEMBER_OF) {
          okP = argumentBoundP((arguments->theArray)[1]);
        }
        else {
          { boolean chooseValue001 = false;

            if (computedPredicateP(goal)) {
              { boolean alwaysP001 = true;

                { Object* arg = NULL;
                  Vector* vector001 = arguments;
                  int index001 = 0;
                  int length001 = vector001->length();

                  for  (arg, vector001, index001, length001; 
                        index001 < length001; 
                        index001 = index001 + 1) {
                    arg = (vector001->theArray)[index001];
                    if (!argumentBoundP(arg)) {
                      alwaysP001 = false;
                      break;
                    }
                  }
                }
                chooseValue001 = alwaysP001;
              }
            }
            else {
              { boolean foundP001 = false;

                { Object* arg = NULL;
                  Vector* vector002 = arguments;
                  int index002 = 0;
                  int length002 = vector002->length();

                  for  (arg, vector002, index002, length002; 
                        index002 < length002; 
                        index002 = index002 + 1) {
                    arg = (vector002->theArray)[index002];
                    if (argumentBoundP(arg) &&
                        typeHasBacklinksP(ensureDeferredDescription(logicalType(arg)))) {
                      foundP001 = true;
                      break;
                    }
                  }
                }
                chooseValue001 = foundP001;
              }
            }
            okP = chooseValue001;
          }
        }
      }
      else if (testValue000 == KWD_OPTIMIZE_ISA) {
        okP = true;
      }
      else if (testValue000 == KWD_OPTIMIZE_EQUIVALENT) {
        okP = argumentBoundP((arguments->theArray)[0]) ||
            argumentBoundP((arguments->theArray)[1]);
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    if (!okP) {
      warnOfUnboundVariableArgument(goal);
    }
    { Object* arg = NULL;
      Vector* vector003 = arguments;
      int index003 = 0;
      int length003 = vector003->length();

      for  (arg, vector003, index003, length003; 
            index003 < length003; 
            index003 = index003 + 1) {
        arg = (vector003->theArray)[index003];
        simulateBindVariableToValue(arg);
      }
    }
  }
}

void simulateAndOptimizeArgument(Object* formula) {
  if (subtypeOfP(safePrimaryType(formula), SGT_OPTIMIZE_LOGIC_PROPOSITION)) {
    { Object* formula000 = formula;
      Proposition* formula = ((Proposition*)(formula000));

      simulateAndOptimizeQuery(formula);
    }
  }
  else {
  }
}

void simulateAndOptimizeQuery(Proposition* proposition) {
  { Vector* arguments = proposition->arguments;
    Keyword* kind = proposition->kind;

    if (oREVERSEPOLARITYpo.get()) {
      if (kind == KWD_OPTIMIZE_AND) {
        kind = KWD_OPTIMIZE_OR;
      }
      else if (kind == KWD_OPTIMIZE_OR) {
        kind = KWD_OPTIMIZE_AND;
      }
      else if (kind == KWD_OPTIMIZE_IMPLIES) {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "REVERSE POLARITY NOT YET IMPLEMENTED FOR :IMPLIES WITHIN " << "QUERY OPTIMIZER";
          throw *newStellaException(stream000->theStringReader());
        }
      }
      else {
      }
    }
    if ((kind == KWD_OPTIMIZE_ISA) ||
        ((kind == KWD_OPTIMIZE_PREDICATE) ||
         ((kind == KWD_OPTIMIZE_FUNCTION) ||
          (kind == KWD_OPTIMIZE_EQUIVALENT)))) {
      simulateGoalEvaluation(proposition);
      { Object* arg = NULL;
        Vector* vector000 = arguments;
        int index000 = 0;
        int length000 = vector000->length();

        for  (arg, vector000, index000, length000; 
              index000 < length000; 
              index000 = index000 + 1) {
          arg = (vector000->theArray)[index000];
          simulateAndOptimizeArgument(arg);
        }
      }
    }
    else if (kind == KWD_OPTIMIZE_AND) {
      { int choicepointunbindingoffset = simulateCreateChoicePoint();

        initializeOptimizerMemory(-1);
        optimizeOrderingOfConjuncts(proposition);
        unbindVariablesBeginningAt(oQUERYITERATORo.get()->currentPatternRecord, choicepointunbindingoffset);
      }
      { Object* arg = NULL;
        Vector* vector001 = proposition->arguments;
        int index001 = 0;
        int length001 = vector001->length();

        for  (arg, vector001, index001, length001; 
              index001 < length001; 
              index001 = index001 + 1) {
          arg = (vector001->theArray)[index001];
          simulateAndOptimizeQuery(((Proposition*)(arg)));
        }
      }
    }
    else if (kind == KWD_OPTIMIZE_OR) {
      { Object* arg = NULL;
        Vector* vector002 = arguments;
        int index002 = 0;
        int length002 = vector002->length();

        for  (arg, vector002, index002, length002; 
              index002 < length002; 
              index002 = index002 + 1) {
          arg = (vector002->theArray)[index002];
          { int choicepointunbindingoffset = simulateCreateChoicePoint();

            simulateAndOptimizeQuery(((Proposition*)(arg)));
            unbindVariablesBeginningAt(oQUERYITERATORo.get()->currentPatternRecord, choicepointunbindingoffset);
          }
        }
      }
    }
    else if (kind == KWD_OPTIMIZE_NOT) {
      { boolean oldreversepolarityP = oREVERSEPOLARITYpo.get();

        { 
          BIND_STELLA_SPECIAL(oREVERSEPOLARITYpo, boolean, !oldreversepolarityP);
          if (oREVERSEPOLARITYpo.get()) {
            warnOfUnboundVariableArgument(proposition);
          }
          simulateAndOptimizeQuery(((Proposition*)((arguments->theArray)[0])));
        }
      }
    }
    else if (kind == KWD_OPTIMIZE_IMPLIES) {
      warnOfUnboundVariableArgument(proposition);
      { Object* arg = NULL;
        Vector* vector003 = arguments;
        int index003 = 0;
        int length003 = vector003->length();

        for  (arg, vector003, index003, length003; 
              index003 < length003; 
              index003 = index003 + 1) {
          arg = (vector003->theArray)[index003];
          simulateAndOptimizeArgument(arg);
        }
      }
    }
    else if (kind == KWD_OPTIMIZE_EXISTS) {
      simulateAndOptimizeQuery(((Proposition*)((arguments->theArray)[0])));
    }
    else if (kind == KWD_OPTIMIZE_FORALL) {
      { int choicepointunbindingoffset = simulateCreateChoicePoint();

        { Object* arg = NULL;
          Vector* vector004 = arguments;
          int index004 = 0;
          int length004 = vector004->length();

          for  (arg, vector004, index004, length004; 
                index004 < length004; 
                index004 = index004 + 1) {
            arg = (vector004->theArray)[index004];
            simulateAndOptimizeArgument(arg);
          }
        }
        unbindVariablesBeginningAt(oQUERYITERATORo.get()->currentPatternRecord, choicepointunbindingoffset);
      }
    }
    else {
    }
  }
}

void initializeOptimizerMemory(int stacksize) {
  if ((stacksize <= 0) &&
      ((boolean)(((ExtensibleVector*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_OPTIMIZER_GOAL_RECORDS, NULL)))))) {
    stacksize = ((ExtensibleVector*)(dynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_OPTIMIZER_GOAL_RECORDS, NULL)))->length();
  }
  initializeOptimizerGoalRecords(stacksize);
  setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_RESIDUE_GOALS, list(0), NULL);
  setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_GOAL_SEQUENCE, list(0), NULL);
  setDynamicSlotValue(oQUERYITERATORo.get()->dynamicSlots, SYM_OPTIMIZE_LOGIC_BEST_COST, wrapFloat(NULL_FLOAT), NULL_FLOAT_WRAPPER);
}

// Keeps track of last control frame allocated by
// the query optimizer.  Used by recursive invocations of the optimizer.
DEFINE_STELLA_SPECIAL(oQUERYOPTIMIZERCONTROLFRAMEo, ControlFrame* , NULL);

void optimizeQuery(Description* description, BooleanVector* booleanvector, ControlFrame* parentframe) {
  { ControlFrame* frame = createDownFrame(parentframe, NULL);
    int variablescount = description->ioVariables->length() + description->internalVariables->length() + ((((boolean)(((Vector*)(dynamicSlotValue(description->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, NULL))))) ? ((Vector*)(dynamicSlotValue(description->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, NULL)))->length() : 0));

    initializeOptimizerMemory(variablescount);
    createPatternRecord(frame, NULL, NULL);
    activatePatternRecord(frame->patternRecord, variablescount);
    { PatternVariable* iovar = NULL;
      Vector* vector000 = description->ioVariables;
      int index000 = 0;
      int length000 = vector000->length();
      BooleanWrapper* initiallyboundP = NULL;
      BooleanVector* vector001 = booleanvector;
      int index001 = 0;
      int length001 = vector001->length();

      for  (iovar, vector000, index000, length000, initiallyboundP, vector001, index001, length001; 
            (index000 < length000) &&
                (index001 < length001); 
            index000 = index000 + 1,
            index001 = index001 + 1) {
        iovar = ((PatternVariable*)((vector000->theArray)[index000]));
        initiallyboundP = ((BooleanWrapper*)((vector001->theArray)[index001]));
        if (coerceWrappedBooleanToBoolean(initiallyboundP)) {
          simulateBindVariableToValue(iovar);
        }
      }
    }
    { 
      BIND_STELLA_SPECIAL(oQUERYOPTIMIZERCONTROLFRAMEo, ControlFrame*, frame);
      simulateAndOptimizeQuery(description->proposition);
    }
    frame->state = KWD_OPTIMIZE_PATTERN;
    popDownFrame(parentframe);
  }
}

// Enables 'select-optimal-query-pattern' to tell
// 'copy-variables-vector' that it should initialize the 'bound-to-offset'
// slot of each variable in the copy operation.
DEFINE_STELLA_SPECIAL(oBOUNDTOOFFSETCOUNTERo, int , NULL_INTEGER);

// Keyword indicating what clause reordering strategy should
// be used for conjunctive queries.  Legal values are :STATIC which performs
// optimization once for each conjunctive pattern by simulating a query,
// :STATIC-WITH-CLUSTERING which additionally tries to cluster conjunction into
// independent clusters, :DYNAMIC which performs simple greedy optimization
// dynamically during a query, :DYNAMIC-WITH-CLUSTERING which also looks
// for clusters (not yet implemented), and :NONE to indicate no optimization
// should be performed.
Keyword* oQUERY_OPTIMIZATION_STRATEGYo = NULL;

boolean useDynamicQueryOptimizationP() {
  return ((oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_DYNAMIC) ||
      (oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_DYNAMIC_WITH_CLUSTERING));
}

boolean dynamicallyOptimizePropositionP(Proposition* self) {
  return (((oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_DYNAMIC) ||
      (oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_DYNAMIC_WITH_CLUSTERING)) &&
      (!((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_DONT_OPTIMIZEp, FALSE_WRAPPER)))->wrapperValue));
}

boolean useStaticQueryOptimizationP() {
  return ((!(oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_NONE)) &&
      (!((oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_DYNAMIC) ||
      (oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_DYNAMIC_WITH_CLUSTERING))));
}

boolean staticallyOptimizePropositionP(Proposition* self) {
  return (((!(oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_NONE)) &&
      (!((oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_DYNAMIC) ||
      (oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_DYNAMIC_WITH_CLUSTERING)))) &&
      (!((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_DONT_OPTIMIZEp, FALSE_WRAPPER)))->wrapperValue));
}

boolean tryToClusterConjunctionsP() {
  return (oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_STATIC_WITH_CLUSTERING);
}

Description* selectOptimalQueryPattern(Description* description, BooleanVector* booleanvector, ControlFrame* parentframe) {
  { Description* pattern = NULL;
    KeyValueList* querypatterns = description->queryPatterns;

    if (((boolean)(querypatterns))) {
      pattern = ((Description*)(querypatterns->lookup(booleanvector)));
    }
    if (traceKeywordP(KWD_OPTIMIZE_OPTIMIZER)) {
      pattern = NULL;
    }
    if (((boolean)(pattern))) {
      return (pattern);
    }
    if (!((boolean)(querypatterns))) {
      description->queryPatterns = newKeyValueList();
    }
    { 
      BIND_STELLA_SPECIAL(oBOUNDTOOFFSETCOUNTERo, int, 0);
      pattern = copyDescription(description, NULL, true);
    }
    description->queryPatterns->insertAt(booleanvector, pattern);
    if (!((!((!(oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_NONE)) &&
        (!((oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_DYNAMIC) ||
        (oQUERY_OPTIMIZATION_STRATEGYo == KWD_OPTIMIZE_DYNAMIC_WITH_CLUSTERING))))) ||
        (((BooleanWrapper*)(dynamicSlotValue(description->dynamicSlots, SYM_OPTIMIZE_LOGIC_DONT_OPTIMIZEp, FALSE_WRAPPER)))->wrapperValue ||
         (containsOperatorP(description->proposition, SGT_OPTIMIZE_PL_KERNEL_KB_CUT) ||
          containsOperatorP(description->proposition, SGT_OPTIMIZE_PL_KERNEL_KB_BOUND_VARIABLES))))) {
      optimizeQuery(pattern, booleanvector, parentframe);
    }
    simplifyDescription(pattern, true);
    return (pattern);
  }
}

double dynamicallyEstimateGoalCost(Proposition* goal) {
  { Keyword* testValue000 = goal->kind;

    if ((testValue000 == KWD_OPTIMIZE_ISA) ||
        ((testValue000 == KWD_OPTIMIZE_FUNCTION) ||
         (testValue000 == KWD_OPTIMIZE_PREDICATE))) {
      { GeneralizedSymbol* operatoR = goal->operatoR;
        NamedDescription* description = getDescription(operatoR);
        Object* firstargvalue = NULL;

        if (operatoR == SGT_OPTIMIZE_PL_KERNEL_KB_HOLDS) {
          firstargvalue = argumentBoundTo((goal->arguments->theArray)[0]);
          if (((boolean)(firstargvalue))) {
            if (isaP(firstargvalue, SGT_OPTIMIZE_LOGIC_NAMED_DESCRIPTION)) {
              description = ((NamedDescription*)(firstargvalue));
            }
            else {
              description = NULL;
            }
          }
          else {
            return (INFERABLE_PENALTY_COST);
          }
        }
        if ((!((boolean)(description))) ||
            (!inferableP(description))) {
          return (1.0);
        }
        else {
          return (INFERABLE_PENALTY_COST);
        }
      }
    }
    else if (testValue000 == KWD_OPTIMIZE_IMPLIES) {
      return (SUBSET_OF_PENALTY_COST);
    }
    else {
      return (1.0);
    }
  }
}

double dynamicallyEstimateGoalFanout(Proposition* goal) {
  if (allArgumentsBoundP(goal)) {
    return (1.0);
  }
  { Keyword* testValue000 = goal->kind;

    if (testValue000 == KWD_OPTIMIZE_ISA) {
      return (dynamicallyEstimateExtensionSize(getDescription(((Surrogate*)(goal->operatoR)))));
    }
    else if ((testValue000 == KWD_OPTIMIZE_FUNCTION) ||
        (testValue000 == KWD_OPTIMIZE_PREDICATE)) {
      if (goal->operatoR == SGT_OPTIMIZE_PL_KERNEL_KB_HOLDS) {
        if (!argumentBoundP((goal->arguments->theArray)[0])) {
          return (NULL_FLOAT);
        }
        else {
          return (dynamicallyEstimatePredicateGoalFanout(goal));
        }
      }
      if (allKeyArgumentsBoundP(goal)) {
        return (1.0);
      }
      else {
        return (dynamicallyEstimatePredicateGoalFanout(goal));
      }
    }
    else if (testValue000 == KWD_OPTIMIZE_IMPLIES) {
      return (ESTIMATED_CARDINALITY_OF_SUBSET_OF);
    }
    else if (testValue000 == KWD_OPTIMIZE_EQUIVALENT) {
      if (argumentBoundP((goal->arguments->theArray)[0]) ||
          argumentBoundP((goal->arguments->theArray)[1])) {
        return (1.0);
      }
      else {
        return (NULL_FLOAT);
      }
    }
    else if ((testValue000 == KWD_OPTIMIZE_NOT) ||
        ((testValue000 == KWD_OPTIMIZE_FAIL) ||
         (testValue000 == KWD_OPTIMIZE_FORALL))) {
      return (NULL_FLOAT);
    }
    else if (testValue000 == KWD_OPTIMIZE_AND) {
      { double fanout = NULL_FLOAT;
        double minfanout = NULL_FLOAT;

        { Object* arg = NULL;
          Vector* vector000 = goal->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          for  (arg, vector000, index000, length000; 
                index000 < length000; 
                index000 = index000 + 1) {
            arg = (vector000->theArray)[index000];
            fanout = dynamicallyEstimateGoalFanout(((Proposition*)(arg)));
            if ((minfanout == NULL_FLOAT) ||
                (fanout < minfanout)) {
              minfanout = fanout;
            }
          }
        }
        return (minfanout);
      }
    }
    else if (testValue000 == KWD_OPTIMIZE_OR) {
      { double fanout = NULL_FLOAT;
        double totalfanout = NULL_FLOAT;

        { Object* arg = NULL;
          Vector* vector001 = goal->arguments;
          int index001 = 0;
          int length001 = vector001->length();

          for  (arg, vector001, index001, length001; 
                index001 < length001; 
                index001 = index001 + 1) {
            arg = (vector001->theArray)[index001];
            fanout = dynamicallyEstimateGoalFanout(((Proposition*)(arg)));
            if (fanout != NULL_FLOAT) {
              if (totalfanout == NULL_FLOAT) {
                totalfanout = 0.0;
              }
              totalfanout = totalfanout + fanout;
            }
          }
        }
        return (totalfanout);
      }
    }
    else {
      return (NULL_FLOAT);
    }
  }
}

double dynamicallyEstimatePredicateGoalFanout(Proposition* goal) {
  { GeneralizedSymbol* testValue000 = goal->operatoR;

    if (testValue000 == SGT_OPTIMIZE_PL_KERNEL_KB_MEMBER_OF) {
      return (estimateMemberOfGoalFanout(goal));
    }
    else if (testValue000 == SGT_OPTIMIZE_PL_KERNEL_KB_INSTANCE_OF) {
      return (dynamicallyEstimateInstanceOfGoalFanout(goal));
    }
    else {
      { Cons* patternargs = NIL;
        GeneralizedSymbol* relation = goal->operatoR;
        Vector* arguments = goal->arguments;
        int firstargindex = 0;
        int nofunboundargs = 0;
        int unboundargindex = NULL_INTEGER;
        Object* key = NULL;
        boolean relationextensionP = true;
        NamedDescription* description = getDescription(relation);

        if (relation == SGT_OPTIMIZE_PL_KERNEL_KB_HOLDS) {
          if (isaP(argumentBoundTo((arguments->theArray)[0]), SGT_OPTIMIZE_LOGIC_NAMED_DESCRIPTION)) {
            description = ((NamedDescription*)(argumentBoundTo((arguments->theArray)[0])));
            firstargindex = 1;
          }
          else {
            description = NULL;
          }
        }
        if (!((boolean)(description))) {
          return (NULL_FLOAT);
        }
        { int i = NULL_INTEGER;
          int iter000 = firstargindex;
          int upperBound000 = arguments->length() - 1;
          Cons* collect000 = NULL;

          for  (i, iter000, upperBound000, collect000; 
                iter000 <= upperBound000; 
                iter000 = iter000 + 1) {
            i = iter000;
            key = argumentBoundTo((arguments->theArray)[i]);
            if (((boolean)(key))) {
              if (instanceHasBacklinksP(key)) {
                relationextensionP = false;
              }
            }
            else {
              nofunboundargs = nofunboundargs + 1;
              unboundargindex = i;
            }
            if (!((boolean)(collect000))) {
              {
                collect000 = cons(key, NIL);
                if (patternargs == NIL) {
                  patternargs = collect000;
                }
                else {
                  addConsToEndOfConsList(patternargs, collect000);
                }
              }
            }
            else {
              {
                collect000->rest = cons(key, NIL);
                collect000 = collect000->rest;
              }
            }
          }
        }
        if (computedTermP(description)) {
          switch (nofunboundargs) {
            case 0: 
              return (((double)(1)));
            case 1: 
              if (unboundargindex == (arguments->length() - 1)) {
                return (((double)(1)));
              }
              else if (computedConstraintP(description)) {
                return (((double)(1)));
              }
            break;
            default:
            break;
          }
          return (NULL_FLOAT);
        }
        if (testPropertyP(description, SGT_OPTIMIZE_PL_KERNEL_KB_TOTAL) &&
            ((nofunboundargs > 1) &&
             (unboundargindex == (arguments->length() - 1)))) {
          return (NULL_FLOAT);
        }
        if (relationextensionP) {
          return (dynamicallyEstimateExtensionSize(description));
        }
        else {
          return (((double)(selectPropositions(cons(KWD_OPTIMIZE_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(relation, patternargs))))->estimatedLength())));
        }
      }
    }
  }
}

double dynamicallyEstimateInstanceOfGoalFanout(Proposition* goal) {
  { Object* instancevalue = argumentBoundTo((goal->arguments->theArray)[0]);
    Object* collectionvalue = argumentBoundTo((goal->arguments->theArray)[1]);

    if (((boolean)(instancevalue))) {
      return (((double)(allTypes(instancevalue)->length())));
    }
    else if (((boolean)(collectionvalue))) {
      { Surrogate* testValue000 = safePrimaryType(collectionvalue);

        if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_DESCRIPTION)) {
          { Object* collectionvalue000 = collectionvalue;
            Description* collectionvalue = ((Description*)(collectionvalue000));

            return ((isaP(collectionvalue, SGT_OPTIMIZE_LOGIC_NAMED_DESCRIPTION) ? dynamicallyEstimateExtensionSize(((NamedDescription*)(collectionvalue))) : ESTIMATED_CARDINALITY_OF_DESCRIPTION));
          }
        }
        else if (subtypeOfP(testValue000, SGT_OPTIMIZE_STELLA_COLLECTION)) {
          { Object* collectionvalue001 = collectionvalue;
            Collection* collectionvalue = ((Collection*)(collectionvalue001));

            return (((double)(collectionvalue->length())));
          }
        }
        else {
          return (NULL_FLOAT);
        }
      }
    }
    else {
      return (NULL_FLOAT);
    }
  }
}

double dynamicallyEstimateExtensionSize(NamedDescription* description) {
  if ((!((boolean)(description))) ||
      (!relationSupportsExtensionP(description))) {
    return (NULL_FLOAT);
  }
  { double estimate = NULL_FLOAT;

    if (estimate == NULL_FLOAT) {
      estimate = ((double)(getDescriptionExtension(description, true)->estimatedLength()));
    }
    return (estimate);
  }
}

double dynamicallyEstimateUnboundVariablePenalty(Proposition* goal) {
  { Keyword* testValue000 = goal->kind;

    if ((testValue000 == KWD_OPTIMIZE_NOT) ||
        (testValue000 == KWD_OPTIMIZE_FAIL)) {
      return (dynamicallyEstimateUnboundVariablePenalty(((Proposition*)((goal->arguments->theArray)[0]))));
    }
    else if (testValue000 == KWD_OPTIMIZE_AND) {
      { double penalty = NULL_FLOAT;
        double minpenalty = NULL_FLOAT;

        { Object* arg = NULL;
          Vector* vector000 = goal->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          for  (arg, vector000, index000, length000; 
                index000 < length000; 
                index000 = index000 + 1) {
            arg = (vector000->theArray)[index000];
            penalty = dynamicallyEstimateUnboundVariablePenalty(((Proposition*)(arg)));
            if ((minpenalty == NULL_FLOAT) ||
                (penalty < minpenalty)) {
              minpenalty = penalty;
            }
          }
        }
        return (minpenalty);
      }
    }
    else if (testValue000 == KWD_OPTIMIZE_OR) {
      { double totalpenalty = 0.0;

        { Object* arg = NULL;
          Vector* vector001 = goal->arguments;
          int index001 = 0;
          int length001 = vector001->length();

          for  (arg, vector001, index001, length001; 
                index001 < length001; 
                index001 = index001 + 1) {
            arg = (vector001->theArray)[index001];
            totalpenalty = totalpenalty + dynamicallyEstimateUnboundVariablePenalty(((Proposition*)(arg)));
          }
        }
        return (totalpenalty);
      }
    }
    else if ((testValue000 == KWD_OPTIMIZE_FUNCTION) ||
        ((testValue000 == KWD_OPTIMIZE_PREDICATE) ||
         ((testValue000 == KWD_OPTIMIZE_EQUIVALENT) ||
          (testValue000 == KWD_OPTIMIZE_ISA)))) {
      { Vector* arguments = goal->arguments;
        GeneralizedSymbol* operatoR = goal->operatoR;
        boolean holdsP = operatoR == SGT_OPTIMIZE_PL_KERNEL_KB_HOLDS;
        boolean isfunctionP = (goal->kind == KWD_OPTIMIZE_FUNCTION) ||
            (holdsP &&
             ((!unboundVariableP((arguments->theArray)[0])) &&
              functionP(argumentBoundTo((arguments->theArray)[0]))));
        int firstkeyargindex = (holdsP ? 1 : 0);
        int lastkeyargindex = (isfunctionP ? (arguments->length() - 2) : (arguments->length() - 1));
        int nofunboundvars = ((holdsP &&
            unboundVariableP((arguments->theArray)[0])) ? 10 : 0);

        { int i = NULL_INTEGER;
          int iter000 = firstkeyargindex;
          int upperBound000 = lastkeyargindex;
          boolean unboundedP000 = upperBound000 == NULL_INTEGER;

          for  (i, iter000, upperBound000, unboundedP000; 
                unboundedP000 ||
                    (iter000 <= upperBound000); 
                iter000 = iter000 + 1) {
            i = iter000;
            if (unboundVariableP((arguments->theArray)[i])) {
              nofunboundvars = nofunboundvars + 1;
            }
          }
        }
        if (computedPredicateP(goal)) {
          switch (nofunboundvars) {
            case 0: 
              return (0.0);
            case 1: 
              if (computedConstraintP(getDescription(operatoR)) &&
                  ((!isfunctionP) ||
                   (!unboundVariableP((arguments->theArray)[(lastkeyargindex + 1)])))) {
                return (0.0);
              }
            break;
            default:
            break;
          }
          return (10000.0);
        }
        return (1.0 + (nofunboundvars * (((double)(nofunboundvars)) / ((lastkeyargindex - firstkeyargindex) - -1))));
      }
    }
    else {
      return (3.0);
    }
  }
}

void dynamicallyReoptimizeArguments(Vector* arguments, int cursor) {
  { int lastargindex = arguments->length() - 1;
    int cheapestargindex = cursor;
    double cost = NULL_FLOAT;
    double fanout = NULL_FLOAT;
    double unbound = NULL_FLOAT;
    double bestcost = NULL_FLOAT;
    Proposition* argument = NULL;

    if (cursor >= lastargindex) {
      return;
    }
    { int i = NULL_INTEGER;
      int iter000 = cursor;
      int upperBound000 = lastargindex;
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;

      for  (i, iter000, upperBound000, unboundedP000; 
            unboundedP000 ||
                (iter000 <= upperBound000); 
            iter000 = iter000 + 1) {
        i = iter000;
        argument = ((Proposition*)((arguments->theArray)[i]));
        if (containsOperatorP(argument, SGT_OPTIMIZE_PL_KERNEL_KB_CUT) ||
            containsOperatorP(argument, SGT_OPTIMIZE_PL_KERNEL_KB_BOUND_VARIABLES)) {
          break;
        }
        unbound = dynamicallyEstimateUnboundVariablePenalty(argument);
        if (unbound == 1.0) {
          fanout = 1.0;
        }
        else {
          fanout = dynamicallyEstimateGoalFanout(argument);
        }
        if (fanout == NULL_FLOAT) {
          continue;
        }
        if (fanout < 1.0) {
          fanout = 1.0;
        }
        cost = dynamicallyEstimateGoalCost(argument);
        cost = cost * fanout * unbound;
        if ((bestcost == NULL_FLOAT) ||
            (cost < bestcost)) {
          bestcost = cost;
          cheapestargindex = i;
          if (bestcost == 1.0) {
            break;
          }
        }
      }
    }
    if (cheapestargindex > cursor) {
      argument = ((Proposition*)((arguments->theArray)[cursor]));
      (arguments->theArray)[cursor] = (((Proposition*)((arguments->theArray)[cheapestargindex])));
      (arguments->theArray)[cheapestargindex] = argument;
    }
  }
}

// Used by 'simplify-description' to permit application
// of order-dependent optimizations.
DEFINE_STELLA_SPECIAL(oPOSTOPTIMIZATIONpo, boolean , false);

void simplifyDescription(Description* description, boolean postoptimizationP) {
  if (!((boolean)(description->proposition))) {
    return;
  }
  { 
    BIND_STELLA_SPECIAL(oPOSTOPTIMIZATIONpo, boolean, postoptimizationP);
    simplifyProposition(description->proposition);
  }
}

Vector* copyListToArgumentsVector(List* arguments) {
  { Vector* vector = newVector(arguments->length());

    { Object* arg = NULL;
      Cons* iter000 = arguments->theConsList;
      int i = NULL_INTEGER;
      int iter001 = 0;

      for  (arg, iter000, i, iter001; 
            !(iter000 == NIL); 
            iter000 = iter000->rest,
            iter001 = iter001 + 1) {
        arg = iter000->value;
        i = iter001;
        (vector->theArray)[i] = arg;
      }
    }
    return (vector);
  }
}

boolean conjunctCancelsIsaPropositionP(Proposition* isaconjunct, Proposition* otherconjunct) {
  { Keyword* testValue000 = otherconjunct->kind;

    if (testValue000 == KWD_OPTIMIZE_ISA) {
      return (eqlP((otherconjunct->arguments->theArray)[0], (isaconjunct->arguments->theArray)[0]) &&
          ((oPOSTOPTIMIZATIONpo.get() ? relationrefSpecializesRelationrefP(((Surrogate*)(otherconjunct->operatoR)), ((Surrogate*)(isaconjunct->operatoR))) : (((Surrogate*)(otherconjunct->operatoR)) == ((Surrogate*)(isaconjunct->operatoR))))));
    }
    else if ((testValue000 == KWD_OPTIMIZE_FUNCTION) ||
        (testValue000 == KWD_OPTIMIZE_PREDICATE)) {
      { Object* inmember = (isaconjunct->arguments->theArray)[0];
        Surrogate* intype = ((Surrogate*)(isaconjunct->operatoR));

        { boolean testValue001 = false;

          testValue001 = oPOSTOPTIMIZATIONpo.get();
          if (testValue001) {
            testValue001 = typeP(intype);
            if (testValue001) {
              testValue001 = surrogateP(((Surrogate*)(otherconjunct->operatoR)));
              if (testValue001) {
                { boolean foundP000 = false;

                  { Object* arg = NULL;
                    Vector* vector000 = otherconjunct->arguments;
                    int index000 = 0;
                    int length000 = vector000->length();
                    Surrogate* argtype = NULL;
                    Cons* iter000 = getDescription(((Surrogate*)(otherconjunct->operatoR)))->ioVariableTypes->theConsList;

                    for  (arg, vector000, index000, length000, argtype, iter000; 
                          (index000 < length000) &&
                              (!(iter000 == NIL)); 
                          index000 = index000 + 1,
                          iter000 = iter000->rest) {
                      arg = (vector000->theArray)[index000];
                      argtype = ((Surrogate*)(iter000->value));
                      if (eqlP(arg, inmember) &&
                          logicalSubtypeOfP(argtype, intype)) {
                        foundP000 = true;
                        break;
                      }
                    }
                  }
                  testValue001 = foundP000;
                }
              }
            }
          }
          { boolean value000 = testValue001;

            return (value000);
          }
        }
      }
    }
    else {
      return (false);
    }
  }
}

void simplifyConjunction(Proposition* andproposition) {
  { List* conjunctslist = newList();
    Cons* cursor = NULL;
    int cursorpos = 0;

    { Object* arg = NULL;
      Vector* vector000 = andproposition->arguments;
      int index000 = 0;
      int length000 = vector000->length();

      for  (arg, vector000, index000, length000; 
            index000 < length000; 
            index000 = index000 + 1) {
        arg = (vector000->theArray)[index000];
        conjunctslist->push(((Proposition*)(arg)));
      }
    }
    cursor = conjunctslist->theConsList;
    while (!(cursor == NIL)) {
      { Proposition* conjunct = ((Proposition*)(cursor->value));

        { Keyword* testValue000 = conjunct->kind;

          if (testValue000 == KWD_OPTIMIZE_EQUIVALENT) {
            if (eqlP((conjunct->arguments->theArray)[0], (conjunct->arguments->theArray)[1]) ||
                (eqlP(valueOf((conjunct->arguments->theArray)[0]), valueOf((conjunct->arguments->theArray)[1])) &&
                 (isaP((conjunct->arguments->theArray)[0], SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE) &&
                  isaP((conjunct->arguments->theArray)[1], SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)))) {
              { Object* arg = NULL;
                Vector* vector001 = conjunct->arguments;
                int index001 = 0;
                int length001 = vector001->length();

                for  (arg, vector001, index001, length001; 
                      index001 < length001; 
                      index001 = index001 + 1) {
                  arg = (vector001->theArray)[index001];
                  removeDependentPropositionLink(arg, conjunct);
                }
              }
              cursor->value = TRUE_PROPOSITION;
            }
          }
          else if (testValue000 == KWD_OPTIMIZE_ISA) {
            { Proposition* value000 = NULL;

              { Proposition* otherconj = NULL;
                Cons* iter000 = conjunctslist->theConsList;
                int i = NULL_INTEGER;
                int iter001 = 0;

                for  (otherconj, iter000, i, iter001; 
                      !(iter000 == NIL); 
                      iter000 = iter000->rest,
                      iter001 = iter001 + 1) {
                  otherconj = ((Proposition*)(iter000->value));
                  i = iter001;
                  if ((!(i == cursorpos)) &&
                      conjunctCancelsIsaPropositionP(conjunct, otherconj)) {
                    value000 = otherconj;
                    break;
                  }
                }
              }
              { Proposition* dominatingconjunct = value000;

                if ((((Surrogate*)(conjunct->operatoR)) == SGT_OPTIMIZE_STELLA_THING) ||
                    ((boolean)(dominatingconjunct))) {
                  if (!(conjunct == dominatingconjunct)) {
                    { Object* arg = NULL;
                      Vector* vector002 = conjunct->arguments;
                      int index002 = 0;
                      int length002 = vector002->length();

                      for  (arg, vector002, index002, length002; 
                            index002 < length002; 
                            index002 = index002 + 1) {
                        arg = (vector002->theArray)[index002];
                        removeDependentPropositionLink(arg, conjunct);
                      }
                    }
                  }
                  cursor->value = TRUE_PROPOSITION;
                }
              }
            }
          }
          else if (testValue000 == KWD_OPTIMIZE_AND) {
            simplifyConjunction(((Proposition*)(cursor->value)));
          }
          else {
          }
        }
      }
      cursor = cursor->rest;
      cursorpos = cursorpos + 1;
    }
    if (conjunctslist->memberP(TRUE_PROPOSITION)) {
      conjunctslist->remove(TRUE_PROPOSITION);
      conjunctslist->reverse();
      switch (conjunctslist->length()) {
        case 0: 
          overlayWithConstantProposition(andproposition, TRUE_PROPOSITION);
        break;
        case 1: 
          overlayProposition(andproposition, ((Proposition*)(conjunctslist->first())));
          { Object* arg = NULL;
            Vector* vector003 = andproposition->arguments;
            int index003 = 0;
            int length003 = vector003->length();

            for  (arg, vector003, index003, length003; 
                  index003 < length003; 
                  index003 = index003 + 1) {
              arg = (vector003->theArray)[index003];
              addDependentPropositionLink(arg, andproposition);
            }
          }
        break;
        default:
          andproposition->arguments = copyListToArgumentsVector(conjunctslist);
        break;
      }
      conjunctslist->free();
    }
  }
}

void simplifyProposition(Proposition* proposition) {
  { Keyword* testValue000 = proposition->kind;

    if (testValue000 == KWD_OPTIMIZE_FORALL) {
    }
    else if (testValue000 == KWD_OPTIMIZE_AND) {
      simplifyConjunction(proposition);
    }
    else {
      { Object* arg = NULL;
        Vector* vector000 = proposition->arguments;
        int index000 = 0;
        int length000 = vector000->length();

        for  (arg, vector000, index000, length000; 
              index000 < length000; 
              index000 = index000 + 1) {
          arg = (vector000->theArray)[index000];
          { Surrogate* testValue001 = safePrimaryType(arg);

            if (subtypeOfP(testValue001, SGT_OPTIMIZE_LOGIC_PROPOSITION)) {
              { Object* arg000 = arg;
                Proposition* arg = ((Proposition*)(arg000));

                simplifyProposition(arg);
              }
            }
            else if (subtypeOfP(testValue001, SGT_OPTIMIZE_LOGIC_DESCRIPTION)) {
              { Object* arg001 = arg;
                Description* arg = ((Description*)(arg001));

                simplifyDescription(arg, oPOSTOPTIMIZATIONpo.get());
              }
            }
            else {
            }
          }
        }
      }
    }
  }
}

Description* copyDescription(Description* self, KeyValueList* parentmapping, boolean addbacklinksP) {
  { 
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, self->homeContext);
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
    { Description* copy = createDescription(NULL_INTEGER, false);
      KeyValueList* mapping = newKeyValueList();

      if (((boolean)(parentmapping))) {
        { Object* k = NULL;
          Object* v = NULL;
          KvCons* iter000 = parentmapping->theKvList;

          for  (k, v, iter000; 
                ((boolean)(iter000)); 
                iter000 = iter000->rest) {
            k = iter000->key;
            v = iter000->value;
            if (isaP(k, SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
              mapping->insertAt(k, v);
            }
          }
        }
      }
      copy->ioVariables = copyVariablesVector(self->ioVariables, mapping);
      copy->internalVariables = copyVariablesVector(self->internalVariables, mapping);
      if (((boolean)(((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, NULL)))))) {
        { Cons* value000 = NIL;

          { PatternVariable* var = NULL;
            Vector* vector000 = ((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, NULL)));
            int index000 = 0;
            int length000 = vector000->length();
            Cons* collect000 = NULL;

            for  (var, vector000, index000, length000, collect000; 
                  index000 < length000; 
                  index000 = index000 + 1) {
              var = ((PatternVariable*)((vector000->theArray)[index000]));
              if ((!((boolean)(mapping->lookup(var)))) ||
                  variableP(mapping->lookup(var))) {
                if (!((boolean)(collect000))) {
                  {
                    collect000 = cons(var, NIL);
                    if (value000 == NIL) {
                      value000 = collect000;
                    }
                    else {
                      addConsToEndOfConsList(value000, collect000);
                    }
                  }
                }
                else {
                  {
                    collect000->rest = cons(var, NIL);
                    collect000 = collect000->rest;
                  }
                }
              }
            }
          }
          { Cons* realexternalvars = value000;
            Vector* externalvarscopy = NULL;

            if (((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, NULL)))->length() == realexternalvars->length()) {
              externalvarscopy = copyVariablesVector(((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, NULL))), mapping);
            }
            else {
              if (!(realexternalvars == NIL)) {
                externalvarscopy = copyVariablesVector(copyConsListToVariablesVector(realexternalvars), mapping);
              }
            }
            setDynamicSlotValue(copy->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, externalvarscopy, NULL);
          }
        }
      }
      if (((boolean)(self->proposition))) {
        { 
          BIND_STELLA_SPECIAL(oBOUNDTOOFFSETCOUNTERo, int, NULL_INTEGER);
          BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_OPTIMIZE_DESCRIPTION);
          copy->proposition = (addbacklinksP ? recursivelyFastenDownPropositions(copyProposition(self->proposition, mapping), false) : copyProposition(self->proposition, mapping));
        }
      }
      if (((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_DONT_OPTIMIZEp, FALSE_WRAPPER)))->wrapperValue) {
        setDynamicSlotValue(copy->dynamicSlots, SYM_OPTIMIZE_LOGIC_DONT_OPTIMIZEp, (true ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
      }
      mapping->free();
      return (copy);
    }
  }
}

PatternVariable* copyVariable(PatternVariable* self, KeyValueList* mapping) {
  { PatternVariable* copy = ((PatternVariable*)(mapping->lookup(self)));

    if (((boolean)(copy))) {
      return (copy);
    }
    copy = createVariable(self->skolemType, self->skolemName, false);
    if ((oPRINTMODEo.get() == KWD_OPTIMIZE_REALISTIC) ||
        (oPRINTMODEo.get() == KWD_OPTIMIZE_FLAT)) {
      copy->skolemName = self->skolemName;
    }
    else {
      { char* copyname = stringConcatenate("?CP_", stringSubsequence(self->skolemName->symbolName, 1, NULL_INTEGER), 0);

        copy->skolemName = internSymbol(copyname);
      }
    }
    copy->skolemType = self->skolemType;
    if (((boolean)(((Object*)(accessInContext(self->variableValue, self->homeContext, false)))))) {
      { PatternVariable* object000 = copy;
        Object* value000 = ((Object*)(accessInContext(self->variableValue, self->homeContext, false)));
        Object* oldValue002 = object000->variableValue;
        Object* newValue000 = updateInContext(oldValue002, value000, object000->homeContext, false);

        if (!(((boolean)(oldValue002)) &&
            (oldValue002->primaryType() == SGT_OPTIMIZE_STELLA_CS_VALUE))) {
          object000->variableValue = newValue000;
        }
      }
    }
    mapping->insertAt(self, copy);
    return (copy);
  }
}

Vector* copyVariablesVector(Vector* self, KeyValueList* mapping) {
  if (self->arraySize == 0) {
    return (ZERO_VARIABLES_VECTOR);
  }
  { Vector* copy = newVector(self->length());

    { PatternVariable* vbl = NULL;
      Vector* vector000 = self;
      int index000 = 0;
      int length000 = vector000->length();
      int i = NULL_INTEGER;
      int iter000 = 0;

      for  (vbl, vector000, index000, length000, i, iter000; 
            index000 < length000; 
            index000 = index000 + 1,
            iter000 = iter000 + 1) {
        vbl = ((PatternVariable*)((vector000->theArray)[index000]));
        i = iter000;
        { PatternVariable* vblcopy = copyVariable(vbl, mapping);

          if (oBOUNDTOOFFSETCOUNTERo.get() != NULL_INTEGER) {
            vblcopy->boundToOffset = oBOUNDTOOFFSETCOUNTERo.get();
            oBOUNDTOOFFSETCOUNTERo.set(oBOUNDTOOFFSETCOUNTERo.get() + 1);
          }
          (copy->theArray)[i] = vblcopy;
        }
      }
    }
    return (copy);
  }
}

Proposition* copyProposition(Proposition* self, KeyValueList* mapping) {
  { Proposition* copy = ((Proposition*)(mapping->lookup(self)));

    if (((boolean)(copy))) {
      return (copy);
    }
    else if (self->kind == KWD_OPTIMIZE_CONSTANT) {
      return (self);
    }
    copy = createProposition(SYM_OPTIMIZE_STELLA_PREDICATE, self->arguments->length());
    copy->homeContext = oMODULEo.get();
    copy->kind = self->kind;
    copy->operatoR = ((GeneralizedSymbol*)(copyPropositionArgument(self->operatoR, mapping)));
    { Proposition* object000 = copy;
      TruthValue* value000 = ((TruthValue*)(accessInContext(self->truthValue, self->homeContext, false)));
      Object* oldValue001 = object000->truthValue;
      Object* newValue000 = updateInContext(oldValue001, value000, object000->homeContext, false);

      if (!(((boolean)(oldValue001)) &&
          (oldValue001->primaryType() == SGT_OPTIMIZE_STELLA_CS_VALUE))) {
        object000->truthValue = newValue000;
      }
    }
    if (((FloatWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_WEIGHT, NULL_FLOAT_WRAPPER)))->wrapperValue != NULL_FLOAT) {
      setDynamicSlotValue(copy->dynamicSlots, SYM_OPTIMIZE_LOGIC_WEIGHT, wrapFloat(((FloatWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_WEIGHT, NULL_FLOAT_WRAPPER)))->wrapperValue), NULL_FLOAT_WRAPPER);
    }
    if (coerceWrappedBooleanToBoolean(self->variableTypeP_reader())) {
      setDynamicSlotValue(copy->dynamicSlots, SYM_OPTIMIZE_LOGIC_VARIABLE_TYPEp, TRUE_WRAPPER, NULL);
    }
    if (((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_DESCRIPTIVEp, FALSE_WRAPPER)))->wrapperValue) {
      setDynamicSlotValue(copy->dynamicSlots, SYM_OPTIMIZE_LOGIC_DESCRIPTIVEp, (true ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
    }
    if (((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_DONT_OPTIMIZEp, FALSE_WRAPPER)))->wrapperValue) {
      setDynamicSlotValue(copy->dynamicSlots, SYM_OPTIMIZE_LOGIC_DONT_OPTIMIZEp, (true ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
    }
    if (((boolean)(((PropertyList*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_ANNOTATIONS, NULL)))))) {
      setDynamicSlotValue(copy->dynamicSlots, SYM_OPTIMIZE_LOGIC_ANNOTATIONS, ((PropertyList*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_ANNOTATIONS, NULL)))->copy(), NULL);
      finalizePropositionAnnotations(copy);
    }
    mapping->insertAt(self, copy);
    { Keyword* testValue000 = self->kind;

      if ((testValue000 == KWD_OPTIMIZE_FORALL) ||
          (testValue000 == KWD_OPTIMIZE_EXISTS)) {
        setDynamicSlotValue(copy->dynamicSlots, SYM_OPTIMIZE_LOGIC_IO_VARIABLES, copyVariablesVector(((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_IO_VARIABLES, NULL))), mapping), NULL);
      }
      else {
      }
    }
    { Object* arg = NULL;
      Vector* vector000 = self->arguments;
      int index000 = 0;
      int length000 = vector000->length();
      int i = NULL_INTEGER;
      int iter000 = 0;

      for  (arg, vector000, index000, length000, i, iter000; 
            index000 < length000; 
            index000 = index000 + 1,
            iter000 = iter000 + 1) {
        arg = (vector000->theArray)[index000];
        i = iter000;
        (copy->arguments->theArray)[i] = (copyPropositionArgument(arg, mapping));
      }
    }
    return (copy);
  }
}

Object* copyPropositionArgument(Object* self, KeyValueList* mapping) {
  { Object* copy = mapping->lookup(self);

    if (((boolean)(copy))) {
      if (descriptionModeP()) {
        { Surrogate* testValue000 = safePrimaryType(copy);

          if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
            { Object* copy000 = copy;
              PatternVariable* copy = ((PatternVariable*)(copy000));

            }
          }
          else if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_LOGIC_OBJECT)) {
            { Object* copy001 = copy;
              LogicObject* copy = ((LogicObject*)(copy001));

              if (((boolean)(copy->surrogateValueInverse))) {
                return (copy->surrogateValueInverse);
              }
            }
          }
          else {
          }
        }
      }
      return (copy);
    }
    { Surrogate* testValue001 = safePrimaryType(self);

      if (subtypeOfP(testValue001, SGT_OPTIMIZE_LOGIC_PROPOSITION)) {
        { Object* self000 = self;
          Proposition* self = ((Proposition*)(self000));

          return (copyProposition(self, mapping));
        }
      }
      else if (subtypeOfP(testValue001, SGT_OPTIMIZE_LOGIC_DESCRIPTION)) {
        { Object* self001 = self;
          Description* self = ((Description*)(self001));

          if (((boolean)(((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES, NULL)))))) {
            { Description* copy = copyDescription(self, mapping, true);

              mapping->insertAt(self, copy);
              return (copy);
            }
          }
          else {
            return (self);
          }
        }
      }
      else if (subtypeOfP(testValue001, SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
        { Object* self002 = self;
          PatternVariable* self = ((PatternVariable*)(self002));

          throw *newStellaException("OOPS -- BUG IN 'copy-description'");
        }
      }
      else {
        return (self);
      }
    }
  }
}

Object* mappedValueOf(Object* self, KeyValueList* mapping, boolean createskolemP) {
  { Object* value = (((boolean)(mapping)) ? mapping->lookup(self) : ((Object*)(NULL)));

    if (((boolean)(value))) {
      return (value);
    }
    if (((boolean)(oQUERYITERATORo.get())) &&
        ((!variableP(self)) ||
         (((PatternVariable*)(self))->boundToOffset != NULL_INTEGER))) {
      value = argumentBoundTo(self);
    }
    else {
      {
        value = valueOf(self);
        if (variableP(self)) {
          value = NULL;
        }
      }
    }
    if (((boolean)(mapping)) &&
        ((boolean)(value))) {
      if (!(isaP(self, SGT_OPTIMIZE_LOGIC_PROPOSITION))) {
        mapping->insertAt(self, value);
      }
      return (value);
    }
    if (createskolemP) {
      return (createSkolemForUnmappedVariable(((PatternVariable*)(self)), mapping));
    }
    else {
      return (NULL);
    }
  }
}

boolean singleValuedPredicateP(Proposition* proposition) {
  return ((proposition->kind == KWD_OPTIMIZE_PREDICATE) &&
      singleValuedTermP(getDescription(((Surrogate*)(proposition->operatoR)))));
}

boolean binaryPropositionP(Proposition* proposition) {
  return (proposition->arguments->length() == 2);
}

Proposition* inheritEquivalentProposition(Skolem* skolem, Object* value) {
  { Proposition* value000 = NULL;

    { Proposition* p = NULL;
      Iterator* iter000 = unfilteredDependentPropositions(skolem, SGT_OPTIMIZE_PL_KERNEL_KB_EQUIVALENT)->allocateIterator();

      for (p, iter000; iter000->nextP(); ) {
        p = ((Proposition*)(iter000->value));
        if ((((Surrogate*)(p->operatoR)) == SGT_OPTIMIZE_PL_KERNEL_KB_EQUIVALENT) &&
            (eqlP((p->arguments->theArray)[0], value) ||
             eqlP((p->arguments->theArray)[1], value))) {
          value000 = p;
          break;
        }
      }
    }
    { Proposition* equivalentprop = value000;

      if (!((boolean)(equivalentprop))) {
        equivalentprop = createProposition(SYM_OPTIMIZE_LOGIC_EQUIVALENT, 2);
        (equivalentprop->arguments->theArray)[0] = skolem;
        (equivalentprop->arguments->theArray)[1] = value;
      }
      return (equivalentprop);
    }
  }
}

Proposition* inheritFunctionProposition(Proposition* self, KeyValueList* mapping) {
  { Proposition* copy = NULL;
    Cons* inputargs = NIL;
    int nofinputargs = self->arguments->length() - 1;
    Object* argmapsto = NULL;

    { Object* arg = NULL;
      Vector* vector000 = self->arguments;
      int index000 = 0;
      int length000 = vector000->length();
      int i = NULL_INTEGER;
      int iter000 = 1;
      Cons* collect000 = NULL;

      for  (arg, vector000, index000, length000, i, iter000, collect000; 
            index000 < length000; 
            index000 = index000 + 1,
            iter000 = iter000 + 1) {
        arg = (vector000->theArray)[index000];
        i = iter000;
        if (i <= nofinputargs) {
          argmapsto = mappedValueOf(arg, mapping, false);
          if (!((boolean)(argmapsto))) {
            return (NULL);
          }
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(argmapsto, NIL);
              if (inputargs == NIL) {
                inputargs = collect000;
              }
              else {
                addConsToEndOfConsList(inputargs, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(argmapsto, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    copy = createFunctionProposition(((Surrogate*)(self->operatoR)), inputargs);
    return (copy);
  }
}

boolean equalUpToSkolemIdentityP(Object* inheritedarg, Object* basearg, KeyValueList* mapping) {
  { Object* inheritedvalue = (((boolean)(mapping)) ? mappedValueOf(inheritedarg, mapping, false) : inheritedarg);
    Object* basevalue = valueOf(basearg);

    if (eqlP(inheritedvalue, basevalue)) {
      return (true);
    }
    return (false);
  }
}

Proposition* findSimilarProposition(Proposition* proposition, KeyValueList* mapping) {
  if (proposition->kind == KWD_OPTIMIZE_CONSTANT) {
    return (NULL);
  }
  { Keyword* kind = proposition->kind;
    GeneralizedSymbol* operatoR = proposition->operatoR;
    Object* argmapsto = NULL;
    SequenceIndex* dependentslist = NULL;
    boolean hasdiscouragedargumentP = false;

    { Object* arg = NULL;
      Vector* vector000 = proposition->arguments;
      int index000 = 0;
      int length000 = vector000->length();

      for  (arg, vector000, index000, length000; 
            index000 < length000; 
            index000 = index000 + 1) {
        arg = (vector000->theArray)[index000];
        if (false) {
          hasdiscouragedargumentP = true;
          continue;
        }
        { Object* mapsto = mappedValueOf(arg, mapping, false);

          if (((boolean)(mapsto)) &&
              instanceHasBacklinksP(mapsto)) {
            argmapsto = mapsto;
            break;
          }
        }
      }
    }
    if ((!((boolean)(argmapsto))) &&
        hasdiscouragedargumentP) {
      { Object* arg = NULL;
        Vector* vector001 = proposition->arguments;
        int index001 = 0;
        int length001 = vector001->length();

        for  (arg, vector001, index001, length001; 
              index001 < length001; 
              index001 = index001 + 1) {
          arg = (vector001->theArray)[index001];
          if (false) {
            { Object* mapsto = mappedValueOf(arg, mapping, false);

              if (((boolean)(mapsto)) &&
                  instanceHasBacklinksP(mapsto)) {
                argmapsto = mapsto;
                break;
              }
            }
          }
        }
      }
    }
    if (!((boolean)(argmapsto))) {
      return (NULL);
    }
    if (subtypeOfP(safePrimaryType(argmapsto), SGT_OPTIMIZE_LOGIC_LOGIC_OBJECT)) {
      { Object* argmapsto000 = argmapsto;
        LogicObject* argmapsto = ((LogicObject*)(argmapsto000));

        dependentslist = unfilteredDependentPropositions(argmapsto, ((Surrogate*)(operatoR)));
        if (kind == KWD_OPTIMIZE_FUNCTION) {
          { Proposition* value000 = NULL;

            { Proposition* p = NULL;
              Iterator* iter000 = dependentslist->allocateIterator();

              for (p, iter000; iter000->nextP(); ) {
                p = ((Proposition*)(iter000->value));
                { boolean testValue000 = false;

                  testValue000 = p->kind == kind;
                  if (testValue000) {
                    testValue000 = p->operatoR == operatoR;
                    if (testValue000) {
                      { boolean alwaysP000 = true;

                        { Object* arg1 = NULL;
                          Iterator* iter001 = proposition->arguments->butLast();
                          Object* arg2 = NULL;
                          Iterator* iter002 = p->arguments->butLast();

                          for  (arg1, iter001, arg2, iter002; 
                                iter001->nextP() &&
                                    iter002->nextP(); ) {
                            arg1 = iter001->value;
                            arg2 = iter002->value;
                            if (!equalUpToSkolemIdentityP(arg1, arg2, mapping)) {
                              alwaysP000 = false;
                              break;
                            }
                          }
                        }
                        testValue000 = alwaysP000;
                      }
                    }
                  }
                  if (testValue000) {
                    value000 = p;
                    break;
                  }
                }
              }
            }
            { Proposition* value001 = value000;

              return (value001);
            }
          }
        }
        else {
          { Proposition* value002 = NULL;

            { Proposition* p = NULL;
              Iterator* iter003 = dependentslist->allocateIterator();

              for (p, iter003; iter003->nextP(); ) {
                p = ((Proposition*)(iter003->value));
                { boolean testValue001 = false;

                  testValue001 = p->kind == kind;
                  if (testValue001) {
                    testValue001 = p->operatoR == operatoR;
                    if (testValue001) {
                      { boolean alwaysP001 = true;

                        { Object* arg1 = NULL;
                          Vector* vector002 = proposition->arguments;
                          int index002 = 0;
                          int length002 = vector002->length();
                          Object* arg2 = NULL;
                          Vector* vector003 = p->arguments;
                          int index003 = 0;
                          int length003 = vector003->length();

                          for  (arg1, vector002, index002, length002, arg2, vector003, index003, length003; 
                                (index002 < length002) &&
                                    (index003 < length003); 
                                index002 = index002 + 1,
                                index003 = index003 + 1) {
                            arg1 = (vector002->theArray)[index002];
                            arg2 = (vector003->theArray)[index003];
                            if (!equalUpToSkolemIdentityP(arg1, arg2, mapping)) {
                              alwaysP001 = false;
                              break;
                            }
                          }
                        }
                        testValue001 = alwaysP001;
                      }
                    }
                  }
                  if (testValue001) {
                    value002 = p;
                    break;
                  }
                }
              }
            }
            { Proposition* value003 = value002;

              return (value003);
            }
          }
        }
      }
    }
    else {
    }
    return (NULL);
  }
}

Object* inheritPropositionArgument(Object* argument, Proposition* parent, KeyValueList* mapping) {
  { Surrogate* testValue000 = safePrimaryType(argument);

    if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PROPOSITION)) {
      { Object* argument000 = argument;
        Proposition* argument = ((Proposition*)(argument000));

        return (inheritProposition(argument, mapping));
      }
    }
    else if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_DESCRIPTION)) {
      { Object* argument001 = argument;
        Description* argument = ((Description*)(argument001));

        if (namedDescriptionP(argument)) {
          return (argument);
        }
        else {
          return (copyDescription(argument, mapping, true));
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
      { Object* argument002 = argument;
        PatternVariable* argument = ((PatternVariable*)(argument002));

        return (mappedValueOf(argument, mapping, true));
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* argument003 = argument;
        Surrogate* argument = ((Surrogate*)(argument003));

        if (descriptionModeP() ||
            ((parent->kind == KWD_OPTIMIZE_ISA) &&
             (((Surrogate*)(parent->operatoR)) == argument))) {
          return (argument);
        }
        else {
          { Object* value = argument->surrogateValue;

            if (relationP(value)) {
              return (surrogateToDescription(argument));
            }
            else {
              return (value);
            }
          }
        }
      }
    }
    else {
      return (argument);
    }
  }
}

Proposition* eradicateHoldsProposition(Proposition* self) {
  if ((self->operatoR == SGT_OPTIMIZE_PL_KERNEL_KB_HOLDS) &&
      (!isaP((self->arguments->theArray)[0], SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE))) {
    normalizePredicateProposition(self);
    { Proposition* duplicate = findSimilarProposition(self, NULL);

      if (((boolean)(duplicate))) {
        { Object* arg = NULL;
          Vector* vector000 = self->arguments;
          int index000 = 0;
          int length000 = vector000->length();
          int i = NULL_INTEGER;
          int iter000 = 0;

          for  (arg, vector000, index000, length000, i, iter000; 
                index000 < length000; 
                index000 = index000 + 1,
                iter000 = iter000 + 1) {
            arg = (vector000->theArray)[index000];
            i = iter000;
            (duplicate->arguments->theArray)[i] = arg;
          }
        }
        self->free();
        return (duplicate);
      }
    }
  }
  return (self);
}

Proposition* inheritProposition(Proposition* self, KeyValueList* mapping) {
  { Keyword* testValue000 = self->kind;

    if ((testValue000 == KWD_OPTIMIZE_FORALL) ||
        (testValue000 == KWD_OPTIMIZE_EXISTS)) {
      { 
        BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_OPTIMIZE_DESCRIPTION);
        return (copyProposition(self, mapping));
      }
    }
    else if (testValue000 == KWD_OPTIMIZE_FUNCTION) {
      { Object* value = inheritPropositionArgument((self->arguments->theArray)[(self->arguments->length() - 1)], self, mapping);
        Proposition* copy = NULL;

        if (!((boolean)(value))) {
          return (NULL);
        }
        copy = findSimilarProposition(self, mapping);
        if (!((boolean)(copy))) {
          copy = inheritFunctionProposition(self, mapping);
          copy = eradicateHoldsProposition(copy);
        }
        if (eqlP((copy->arguments->theArray)[(copy->arguments->length() - 1)], value)) {
          copy = TRUE_PROPOSITION;
        }
        else {
          copy = inheritEquivalentProposition(((Skolem*)((copy->arguments->theArray)[(copy->arguments->length() - 1)])), value);
        }
        mapping->insertAt(self, copy);
        return (copy);
      }
    }
    else {
    }
  }
  { Proposition* matchingproposition = ((Proposition*)(mapping->lookup(self)));

    if (((boolean)(matchingproposition))) {
      return (matchingproposition);
    }
    if (coerceWrappedBooleanToBoolean(self->variableTypeP_reader())) {
      { Object* binding = mapping->lookup((self->arguments->theArray)[0]);

        if (((boolean)(binding)) &&
            (!skolemP(binding))) {
          return (TRUE_PROPOSITION);
        }
      }
    }
    if (((boolean)(matchingproposition))) {
      mapping->insertAt(self, matchingproposition);
      return (matchingproposition);
    }
  }
  { GeneralizedSymbol* operatoR = self->operatoR;
    List* argumentsmapto = newList();
    Proposition* copy = NULL;
    Object* argmapsto = NULL;

    { Object* arg = NULL;
      Vector* vector000 = self->arguments;
      int index000 = 0;
      int length000 = vector000->length();
      Cons* collect000 = NULL;

      for  (arg, vector000, index000, length000, collect000; 
            index000 < length000; 
            index000 = index000 + 1) {
        arg = (vector000->theArray)[index000];
        argmapsto = inheritPropositionArgument(arg, self, mapping);
        if (!((boolean)(argmapsto))) {
          return (NULL);
        }
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(argmapsto, NIL);
            if (argumentsmapto->theConsList == NIL) {
              argumentsmapto->theConsList = collect000;
            }
            else {
              addConsToEndOfConsList(argumentsmapto->theConsList, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(argmapsto, NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    copy = createProposition(SYM_OPTIMIZE_LOGIC_CONSTANT, 0);
    copy->kind = self->kind;
    copy->operatoR = operatoR;
    copy->arguments = copyListToArgumentsVector(argumentsmapto);
    if (coerceWrappedBooleanToBoolean(self->variableTypeP_reader())) {
      setDynamicSlotValue(copy->dynamicSlots, SYM_OPTIMIZE_LOGIC_VARIABLE_TYPEp, TRUE_WRAPPER, NULL);
    }
    copy = eradicateHoldsProposition(copy);
    mapping->insertAt(self, copy);
    return (copy);
  }
}

Skolem* createSkolemForUnmappedVariable(PatternVariable* variable, KeyValueList* mapping) {
  { Object* skolem = mapping->lookup(variable);

    if (((boolean)(skolem))) {
      return (((Skolem*)(skolem)));
    }
    skolem = createVariableOrSkolem(variable->skolemType, NULL);
    mapping->insertAt(variable, skolem);
    return (((Skolem*)(skolem)));
  }
}

Cons* inheritAsTopLevelProposition(Proposition* proposition, KeyValueList* mapping) {
  { Cons* resultlist = NIL;

    if (!((boolean)(mapping))) {
      mapping = newKeyValueList();
    }
    { Keyword* testValue000 = proposition->kind;

      if (testValue000 == KWD_OPTIMIZE_AND) {
        { Object* arg = NULL;
          Vector* vector000 = proposition->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          for  (arg, vector000, index000, length000; 
                index000 < length000; 
                index000 = index000 + 1) {
            arg = (vector000->theArray)[index000];
            resultlist = cons(inheritProposition(((Proposition*)(arg)), mapping), resultlist);
          }
        }
      }
      else if (testValue000 == KWD_OPTIMIZE_EXISTS) {
        { PatternVariable* vbl = NULL;
          Vector* vector001 = ((Vector*)(dynamicSlotValue(proposition->dynamicSlots, SYM_OPTIMIZE_LOGIC_IO_VARIABLES, NULL)));
          int index001 = 0;
          int length001 = vector001->length();

          for  (vbl, vector001, index001, length001; 
                index001 < length001; 
                index001 = index001 + 1) {
            vbl = ((PatternVariable*)((vector001->theArray)[index001]));
            createSkolemForUnmappedVariable(vbl, mapping);
          }
        }
        resultlist = cons(inheritProposition(((Proposition*)((proposition->arguments->theArray)[0])), mapping), resultlist);
      }
      else {
        resultlist = cons(inheritProposition(proposition, mapping), resultlist);
      }
    }
    mapping->free();
    { Object* p = NULL;
      Cons* iter000 = resultlist;

      for (p, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        p = iter000->value;
        normalizeTopLevelProposition(((Proposition*)(p)), NULL);
      }
    }
    return (resultlist);
  }
}

boolean mapAndEnqueueVariableP(Object* variable, Object* localvalue, KeyValueList* mapping, List* queue) {
  if (subtypeOfP(safePrimaryType(variable), SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE)) {
    { Object* variable000 = variable;
      PatternVariable* variable = ((PatternVariable*)(variable000));

      { Object* mapstovalue = mapping->lookup(variable);

        if (!((boolean)(mapstovalue))) {
          mapstovalue = nativeValueOf(variable);
          if (((boolean)(mapstovalue))) {
            mapping->insertAt(variable, mapstovalue);
          }
        }
        if (((boolean)(mapstovalue))) {
          return ((!((boolean)(localvalue))) ||
              (eqlP(mapstovalue, localvalue) ||
               (skolemP(localvalue) ||
                skolemP(mapstovalue))));
        }
        else if (((boolean)(localvalue))) {
          mapping->insertAt(variable, localvalue);
          if (isaP(localvalue, SGT_OPTIMIZE_LOGIC_LOGIC_OBJECT)) {
            queue->push(variable);
          }
        }
        else {
          { Skolem* skolem = createVariableOrSkolem(variable->skolemType, NULL);

            mapping->insertAt(variable, skolem);
            queue->push(variable);
          }
        }
      }
    }
  }
  else {
  }
  return (true);
}

void collectStructuralFunctions(Proposition* proposition, List* structuralfunctions) {
  { Keyword* testValue000 = proposition->kind;

    if (testValue000 == KWD_OPTIMIZE_FUNCTION) {
      structuralfunctions->insert(proposition);
    }
    else if (testValue000 == KWD_OPTIMIZE_PREDICATE) {
      if (singleValuedPredicateP(proposition)) {
        structuralfunctions->insert(proposition);
      }
    }
    else if (testValue000 == KWD_OPTIMIZE_AND) {
      { Object* conjunct = NULL;
        Vector* vector000 = proposition->arguments;
        int index000 = 0;
        int length000 = vector000->length();

        for  (conjunct, vector000, index000, length000; 
              index000 < length000; 
              index000 = index000 + 1) {
          conjunct = (vector000->theArray)[index000];
          collectStructuralFunctions(((Proposition*)(conjunct)), structuralfunctions);
        }
      }
    }
    else if (testValue000 == KWD_OPTIMIZE_EXISTS) {
      collectStructuralFunctions(((Proposition*)((proposition->arguments->theArray)[0])), structuralfunctions);
    }
    else {
    }
  }
}

boolean mapFunctionalValueP(Proposition* proposition, KeyValueList* mapping, List* queue) {
  { Proposition* copy = findSimilarProposition(proposition, mapping);

    if ((!((boolean)(copy))) &&
        (proposition->kind == KWD_OPTIMIZE_FUNCTION)) {
      copy = inheritFunctionProposition(proposition, mapping);
    }
    if (((boolean)(copy))) {
      { Object* localfunctionalvalue = valueOf((copy->arguments->theArray)[(copy->arguments->length() - 1)]);

        return (mapAndEnqueueVariableP((proposition->arguments->theArray)[(proposition->arguments->length() - 1)], localfunctionalvalue, mapping, queue));
      }
    }
    return (true);
  }
}

Cons* inheritDescriptionPropositions(Vector* arguments, Description* description) {
  { KeyValueList* mapping = newKeyValueList();
    List* variablequeue = newList();
    List* structuralfunctions = newList();

    { PatternVariable* v = NULL;
      Vector* vector000 = description->ioVariables;
      int index000 = 0;
      int length000 = vector000->length();
      Object* arg = NULL;
      Vector* vector001 = arguments;
      int index001 = 0;
      int length001 = vector001->length();

      for  (v, vector000, index000, length000, arg, vector001, index001, length001; 
            (index000 < length000) &&
                (index001 < length001); 
            index000 = index000 + 1,
            index001 = index001 + 1) {
        v = ((PatternVariable*)((vector000->theArray)[index000]));
        arg = (vector001->theArray)[index001];
        if (!(mapAndEnqueueVariableP(v, arg, mapping, variablequeue))) {
          return (NIL);
        }
      }
    }
    { PatternVariable* v = NULL;
      Vector* vector002 = description->internalVariables;
      int index002 = 0;
      int length002 = vector002->length();
      Cons* collect000 = NULL;

      for  (v, vector002, index002, length002, collect000; 
            index002 < length002; 
            index002 = index002 + 1) {
        v = ((PatternVariable*)((vector002->theArray)[index002]));
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(v, NIL);
            if (variablequeue->theConsList == NIL) {
              variablequeue->theConsList = collect000;
            }
            else {
              addConsToEndOfConsList(variablequeue->theConsList, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(v, NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    collectStructuralFunctions(description->proposition, structuralfunctions);
    for (;;) {
      if (variablequeue->emptyP()) {
        break;
      }
      { PatternVariable* variable = ((PatternVariable*)(variablequeue->pop()));

        { Proposition* p = NULL;
          Iterator* iter000 = unfilteredDependentPropositions(variable, NULL)->allocateIterator();

          for (p, iter000; iter000->nextP(); ) {
            p = ((Proposition*)(iter000->value));
            if (structuralfunctions->memberP(p)) {
              if (!(mapFunctionalValueP(p, mapping, variablequeue))) {
                return (NIL);
              }
            }
          }
        }
      }
    }
    { Cons* propositions = inheritAsTopLevelProposition(description->proposition, mapping);

      { ConsIterator* it = propositions->allocateIterator();

        for (it; it->nextP(); ) {
          it->valueSetter(recursivelyFastenDownPropositions(((Proposition*)(it->value)), false));
        }
      }
      return (propositions);
    }
  }
}

void inheritUnnamedDescription(Object* self, Description* description, boolean defaulttrueP) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_OPTIMIZE_STELLA_VECTOR)) {
      { Object* self000 = self;
        Vector* self = ((Vector*)(self000));

        vectorDinheritUnnamedDescription(self, description, defaulttrueP);
      }
    }
    else if (subtypeOfP(testValue000, SGT_OPTIMIZE_LOGIC_LOGIC_OBJECT)) {
      { Object* self001 = self;
        LogicObject* self = ((LogicObject*)(self001));

        logicObjectDinheritUnnamedDescription(self, description, defaulttrueP);
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

void vectorDinheritUnnamedDescription(Vector* arguments, Description* description, boolean defaulttrueP) {
  { Proposition* prop = NULL;
    Cons* iter000 = inheritDescriptionPropositions(arguments, description);
    Cons* collect000 = NULL;

    for  (prop, iter000, collect000; 
          !(iter000 == NIL); 
          iter000 = iter000->rest) {
      prop = ((Proposition*)(iter000->value));
      if (!trueP(prop)) {
        assignTruthValue(prop, (defaulttrueP ? DEFAULT_TRUE_TRUTH_VALUE : TRUE_TRUTH_VALUE));
        if (!(((boolean)(oCOLLECTFORWARDPROPOSITIONSo.get())))) {
          continue;
        }
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(prop, NIL);
            if (oCOLLECTFORWARDPROPOSITIONSo.get() == NIL) {
              oCOLLECTFORWARDPROPOSITIONSo.set(collect000);
            }
            else {
              addConsToEndOfConsList(oCOLLECTFORWARDPROPOSITIONSo.get(), collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(prop, NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
  }
}

void logicObjectDinheritUnnamedDescription(LogicObject* instance, Description* description, boolean defaulttrueP) {
  { Vector* vector = newVector(1);

    (vector->theArray)[0] = instance;
    inheritUnnamedDescription(vector, description, defaulttrueP);
  }
}

void inheritDescription(Vector* arguments, Description* description, boolean defaulttrueP) {
  if (subtypeOfP(safePrimaryType(description), SGT_OPTIMIZE_LOGIC_NAMED_DESCRIPTION)) {
    { Description* description000 = description;
      NamedDescription* description = ((NamedDescription*)(description000));

      { Proposition* prop = updateTuple(description->surrogateValueInverse, arguments->consify(), KWD_OPTIMIZE_CONCEIVE);

        if (!(trueP(prop))) {
          if (((boolean)(oCOLLECTFORWARDPROPOSITIONSo.get()))) {
            oCOLLECTFORWARDPROPOSITIONSo.set(cons(prop, oCOLLECTFORWARDPROPOSITIONSo.get()));
          }
          assignTruthValue(prop, (defaulttrueP ? DEFAULT_TRUE_TRUTH_VALUE : TRUE_TRUTH_VALUE));
        }
      }
    }
  }
  else {
    inheritUnnamedDescription(arguments, description, defaulttrueP);
  }
}

void helpStartupOptimize1() {
  {
    SGT_OPTIMIZE_LOGIC_GOAL_RECORD = ((Surrogate*)(internRigidSymbolWrtModule("GOAL-RECORD", NULL, 1)));
    SYM_OPTIMIZE_LOGIC_GENERATOR_GOALS = ((Symbol*)(internRigidSymbolWrtModule("GENERATOR-GOALS", NULL, 0)));
    SYM_OPTIMIZE_LOGIC_OTHER_GOALS = ((Symbol*)(internRigidSymbolWrtModule("OTHER-GOALS", NULL, 0)));
    SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE = ((Surrogate*)(internRigidSymbolWrtModule("PATTERN-VARIABLE", NULL, 1)));
    SGT_OPTIMIZE_LOGIC_PROPOSITION = ((Surrogate*)(internRigidSymbolWrtModule("PROPOSITION", NULL, 1)));
    SYM_OPTIMIZE_LOGIC_IO_VARIABLES = ((Symbol*)(internRigidSymbolWrtModule("IO-VARIABLES", NULL, 0)));
    SGT_OPTIMIZE_LOGIC_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 1)));
    SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES = ((Symbol*)(internRigidSymbolWrtModule("EXTERNAL-VARIABLES", NULL, 0)));
    KWD_OPTIMIZE_OR = ((Keyword*)(internRigidSymbolWrtModule("OR", NULL, 2)));
    SYM_OPTIMIZE_LOGIC_PERMUTATION_TABLE = ((Symbol*)(internRigidSymbolWrtModule("PERMUTATION-TABLE", NULL, 0)));
    SGT_OPTIMIZE_PL_KERNEL_KB_COMPUTED = ((Surrogate*)(internRigidSymbolWrtModule("COMPUTED", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SGT_OPTIMIZE_PL_KERNEL_KB_RELATION_CONSTRAINT = ((Surrogate*)(internRigidSymbolWrtModule("RELATION-CONSTRAINT", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SGT_OPTIMIZE_PL_KERNEL_KB_ABSTRACT = ((Surrogate*)(internRigidSymbolWrtModule("ABSTRACT", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SGT_OPTIMIZE_LOGIC_NAMED_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("NAMED-DESCRIPTION", NULL, 1)));
    SYM_OPTIMIZE_LOGIC_OPTIMIZER_GOAL_RECORDS = ((Symbol*)(internRigidSymbolWrtModule("OPTIMIZER-GOAL-RECORDS", NULL, 0)));
    KWD_OPTIMIZE_FUNCTION = ((Keyword*)(internRigidSymbolWrtModule("FUNCTION", NULL, 2)));
    KWD_OPTIMIZE_EQUIVALENT = ((Keyword*)(internRigidSymbolWrtModule("EQUIVALENT", NULL, 2)));
    KWD_OPTIMIZE_ISA = ((Keyword*)(internRigidSymbolWrtModule("ISA", NULL, 2)));
    KWD_OPTIMIZE_PREDICATE = ((Keyword*)(internRigidSymbolWrtModule("PREDICATE", NULL, 2)));
    KWD_OPTIMIZE_NOT = ((Keyword*)(internRigidSymbolWrtModule("NOT", NULL, 2)));
    KWD_OPTIMIZE_FAIL = ((Keyword*)(internRigidSymbolWrtModule("FAIL", NULL, 2)));
    KWD_OPTIMIZE_IMPLIES = ((Keyword*)(internRigidSymbolWrtModule("IMPLIES", NULL, 2)));
    SYM_OPTIMIZE_LOGIC_UNIQUENESSVECTORS = ((Symbol*)(internRigidSymbolWrtModule("UNIQUENESSVECTORS", NULL, 0)));
    SYM_OPTIMIZE_LOGIC_INVERSE_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("INVERSE-DESCRIPTION", NULL, 0)));
    SYM_OPTIMIZE_LOGIC_INDEXING_VECTOR = ((Symbol*)(internRigidSymbolWrtModule("INDEXING-VECTOR", NULL, 0)));
    SGT_OPTIMIZE_PL_KERNEL_KB_OBSERVED_CARDINALITY_OF = ((Surrogate*)(internRigidSymbolWrtModule("OBSERVED-CARDINALITY-OF", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SGT_OPTIMIZE_STELLA_INTEGER_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("INTEGER-WRAPPER", getStellaModule("/STELLA", true), 1)));
    SGT_OPTIMIZE_STELLA_COLLECTION = ((Surrogate*)(internRigidSymbolWrtModule("COLLECTION", getStellaModule("/STELLA", true), 1)));
    SGT_OPTIMIZE_PL_KERNEL_KB_MEMBER_OF = ((Surrogate*)(internRigidSymbolWrtModule("MEMBER-OF", getStellaModule("/PL-KERNEL-KB", true), 1)));
    KWD_OPTIMIZE_OPTIMIZER = ((Keyword*)(internRigidSymbolWrtModule("OPTIMIZER", NULL, 2)));
    SYM_OPTIMIZE_LOGIC_BEST_GOAL_SEQUENCE = ((Symbol*)(internRigidSymbolWrtModule("BEST-GOAL-SEQUENCE", NULL, 0)));
    SYM_OPTIMIZE_LOGIC_BEST_COST = ((Symbol*)(internRigidSymbolWrtModule("BEST-COST", NULL, 0)));
    KWD_OPTIMIZE_FORALL = ((Keyword*)(internRigidSymbolWrtModule("FORALL", NULL, 2)));
    KWD_OPTIMIZE_EXISTS = ((Keyword*)(internRigidSymbolWrtModule("EXISTS", NULL, 2)));
    KWD_OPTIMIZE_STATIC_WITH_CLUSTERING = ((Keyword*)(internRigidSymbolWrtModule("STATIC-WITH-CLUSTERING", NULL, 2)));
    KWD_OPTIMIZE_DESCRIPTION = ((Keyword*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 2)));
    KWD_OPTIMIZE_AND = ((Keyword*)(internRigidSymbolWrtModule("AND", NULL, 2)));
    KWD_OPTIMIZE_BOUND = ((Keyword*)(internRigidSymbolWrtModule("BOUND", NULL, 2)));
    SYM_OPTIMIZE_LOGIC_RESIDUE_GOALS = ((Symbol*)(internRigidSymbolWrtModule("RESIDUE-GOALS", NULL, 0)));
    KWD_OPTIMIZE_PATTERN = ((Keyword*)(internRigidSymbolWrtModule("PATTERN", NULL, 2)));
    KWD_OPTIMIZE_DYNAMIC = ((Keyword*)(internRigidSymbolWrtModule("DYNAMIC", NULL, 2)));
    KWD_OPTIMIZE_DYNAMIC_WITH_CLUSTERING = ((Keyword*)(internRigidSymbolWrtModule("DYNAMIC-WITH-CLUSTERING", NULL, 2)));
    SYM_OPTIMIZE_LOGIC_DONT_OPTIMIZEp = ((Symbol*)(internRigidSymbolWrtModule("DONT-OPTIMIZE?", NULL, 0)));
    KWD_OPTIMIZE_NONE = ((Keyword*)(internRigidSymbolWrtModule("NONE", NULL, 2)));
    SGT_OPTIMIZE_PL_KERNEL_KB_CUT = ((Surrogate*)(internRigidSymbolWrtModule("CUT", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SGT_OPTIMIZE_PL_KERNEL_KB_BOUND_VARIABLES = ((Surrogate*)(internRigidSymbolWrtModule("BOUND-VARIABLES", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SGT_OPTIMIZE_PL_KERNEL_KB_HOLDS = ((Surrogate*)(internRigidSymbolWrtModule("HOLDS", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SGT_OPTIMIZE_PL_KERNEL_KB_INSTANCE_OF = ((Surrogate*)(internRigidSymbolWrtModule("INSTANCE-OF", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SGT_OPTIMIZE_PL_KERNEL_KB_TOTAL = ((Surrogate*)(internRigidSymbolWrtModule("TOTAL", getStellaModule("/PL-KERNEL-KB", true), 1)));
    KWD_OPTIMIZE_RELATION = ((Keyword*)(internRigidSymbolWrtModule("RELATION", NULL, 2)));
    SGT_OPTIMIZE_STELLA_THING = ((Surrogate*)(internRigidSymbolWrtModule("THING", getStellaModule("/STELLA", true), 1)));
    KWD_OPTIMIZE_REALISTIC = ((Keyword*)(internRigidSymbolWrtModule("REALISTIC", NULL, 2)));
    KWD_OPTIMIZE_FLAT = ((Keyword*)(internRigidSymbolWrtModule("FLAT", NULL, 2)));
    SGT_OPTIMIZE_STELLA_CS_VALUE = ((Surrogate*)(internRigidSymbolWrtModule("CS-VALUE", getStellaModule("/STELLA", true), 1)));
    KWD_OPTIMIZE_CONSTANT = ((Keyword*)(internRigidSymbolWrtModule("CONSTANT", NULL, 2)));
    SYM_OPTIMIZE_STELLA_PREDICATE = ((Symbol*)(internRigidSymbolWrtModule("PREDICATE", getStellaModule("/STELLA", true), 0)));
    SYM_OPTIMIZE_LOGIC_WEIGHT = ((Symbol*)(internRigidSymbolWrtModule("WEIGHT", NULL, 0)));
    SYM_OPTIMIZE_LOGIC_VARIABLE_TYPEp = ((Symbol*)(internRigidSymbolWrtModule("VARIABLE-TYPE?", NULL, 0)));
    SYM_OPTIMIZE_LOGIC_DESCRIPTIVEp = ((Symbol*)(internRigidSymbolWrtModule("DESCRIPTIVE?", NULL, 0)));
    SYM_OPTIMIZE_LOGIC_ANNOTATIONS = ((Symbol*)(internRigidSymbolWrtModule("ANNOTATIONS", NULL, 0)));
  }
}

void helpStartupOptimize2() {
  {
    SGT_OPTIMIZE_LOGIC_LOGIC_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("LOGIC-OBJECT", NULL, 1)));
    SGT_OPTIMIZE_PL_KERNEL_KB_EQUIVALENT = ((Surrogate*)(internRigidSymbolWrtModule("EQUIVALENT", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SYM_OPTIMIZE_LOGIC_EQUIVALENT = ((Symbol*)(internRigidSymbolWrtModule("EQUIVALENT", NULL, 0)));
    SYM_OPTIMIZE_LOGIC_CONSTANT = ((Symbol*)(internRigidSymbolWrtModule("CONSTANT", NULL, 0)));
    SGT_OPTIMIZE_STELLA_VECTOR = ((Surrogate*)(internRigidSymbolWrtModule("VECTOR", getStellaModule("/STELLA", true), 1)));
    KWD_OPTIMIZE_CONCEIVE = ((Keyword*)(internRigidSymbolWrtModule("CONCEIVE", NULL, 2)));
    SYM_OPTIMIZE_LOGIC_STARTUP_OPTIMIZE = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-OPTIMIZE", NULL, 0)));
    SYM_OPTIMIZE_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", true), 0)));
  }
}

void helpStartupOptimize3() {
  {
    V_0_0 = zeroOneListToBooleanVector(list(2, wrapInteger(0), wrapInteger(0)));
    V_1_0 = zeroOneListToBooleanVector(list(2, wrapInteger(1), wrapInteger(0)));
    V_0_1 = zeroOneListToBooleanVector(list(2, wrapInteger(0), wrapInteger(1)));
    V_1_1 = zeroOneListToBooleanVector(list(2, wrapInteger(1), wrapInteger(1)));
    V_1_0_AND_V_0_1 = list(2, V_1_0, V_0_1);
    V_1_0_SINGLETON = list(1, V_1_0);
    V_0_1_SINGLETON = list(1, V_0_1);
    oQUERY_OPTIMIZATION_STRATEGYo = KWD_OPTIMIZE_DYNAMIC;
  }
}

void helpStartupOptimize4() {
  {
    defineFunctionObject("VARIABLE-BOUND?", "(DEFUN (VARIABLE-BOUND? BOOLEAN) ((VARIABLE PATTERN-VARIABLE)))", ((cpp_function_code)(&variableBoundP)), NULL);
    defineFunctionObject("ARGUMENT-BOUND?", "(DEFUN (ARGUMENT-BOUND? BOOLEAN) ((ARGUMENT OBJECT)))", ((cpp_function_code)(&argumentBoundP)), NULL);
    defineFunctionObject("QUANTIFIED-ARGUMENT-BOUND?", "(DEFUN (QUANTIFIED-ARGUMENT-BOUND? BOOLEAN) ((ARGUMENT OBJECT) (QUANTIFIEDVARS LIST)))", ((cpp_function_code)(&quantifiedArgumentBoundP)), NULL);
    defineFunctionObject("UNBOUND-VARIABLE?", "(DEFUN (UNBOUND-VARIABLE? BOOLEAN) ((ARGUMENT OBJECT)))", ((cpp_function_code)(&unboundVariableP)), NULL);
    defineFunctionObject("HAS-DISJUNCTION?", "(DEFUN (HAS-DISJUNCTION? BOOLEAN) ((GOAL PROPOSITION)))", ((cpp_function_code)(&hasDisjunctionP)), NULL);
    defineFunctionObject("MODAL-GOAL?", "(DEFUN (MODAL-GOAL? BOOLEAN) ((GOAL PROPOSITION)))", ((cpp_function_code)(&modalGoalP)), NULL);
    defineFunctionObject("HAS-INVERSIONS?", "(DEFUN (HAS-INVERSIONS? BOOLEAN) ((GOAL PROPOSITION)))", ((cpp_function_code)(&hasInversionsP)), NULL);
    defineFunctionObject("COMPUTED-TERM?", "(DEFUN (COMPUTED-TERM? BOOLEAN) ((SELF DESCRIPTION)))", ((cpp_function_code)(&computedTermP)), NULL);
    defineFunctionObject("COMPUTED-CONSTRAINT?", "(DEFUN (COMPUTED-CONSTRAINT? BOOLEAN) ((SELF DESCRIPTION)))", ((cpp_function_code)(&computedConstraintP)), NULL);
    defineFunctionObject("COMPUTED-PREDICATE?", "(DEFUN (COMPUTED-PREDICATE? BOOLEAN) ((GOAL PROPOSITION)))", ((cpp_function_code)(&computedPredicateP)), NULL);
    defineFunctionObject("SIMULATE-CREATE-CHOICE-POINT", "(DEFUN (SIMULATE-CREATE-CHOICE-POINT INTEGER) ())", ((cpp_function_code)(&simulateCreateChoicePoint)), NULL);
    defineFunctionObject("RELATION-SUPPORTS-EXTENSION?", "(DEFUN (RELATION-SUPPORTS-EXTENSION? BOOLEAN) ((SELF NAMED-DESCRIPTION)))", ((cpp_function_code)(&relationSupportsExtensionP)), NULL);
    defineFunctionObject("GENERATOR-COLLECTION?", "(DEFUN (GENERATOR-COLLECTION? BOOLEAN) ((COLLECTION OBJECT)))", ((cpp_function_code)(&generatorCollectionP)), NULL);
    defineFunctionObject("INITIALIZE-OPTIMIZER-GOAL-RECORDS", "(DEFUN INITIALIZE-OPTIMIZER-GOAL-RECORDS ((SIZE INTEGER)))", ((cpp_function_code)(&initializeOptimizerGoalRecords)), NULL);
    defineFunctionObject("GOAL-RECORD", "(DEFUN (GOAL-RECORD GOAL-RECORD) ((VARIABLE PATTERN-VARIABLE)))", ((cpp_function_code)(&goalRecord)), NULL);
    defineFunctionObject("HELP-DISTRIBUTE-GOAL", "(DEFUN HELP-DISTRIBUTE-GOAL ((ARGUMENT OBJECT) (PARENTGOAL PROPOSITION) (GENERATOR? BOOLEAN)))", ((cpp_function_code)(&helpDistributeGoal)), NULL);
    defineFunctionObject("DISTRIBUTE-OPEN-GOAL", "(DEFUN DISTRIBUTE-OPEN-GOAL ((GOAL PROPOSITION)))", ((cpp_function_code)(&distributeOpenGoal)), NULL);
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION UNIQUENESSVECTORS :TYPE (LIST OF BOOLEAN-VECTOR) :DOCUMENTATION \"Caches a list of vectors representing keys\nfor the slot/relation.\" :ALLOCATION :DYNAMIC)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT NAMED-DESCRIPTION INDEXING-VECTOR :TYPE BOOLEAN-VECTOR :DOCUMENTATION \"Caches a vector indicating which arguments\nof a slot/relation have backlinks to referencing propositions.\" :ALLOCATION :DYNAMIC)");
    defineFunctionObject("GET-BINARY-UNIQUENESS-VECTORS", "(DEFUN (GET-BINARY-UNIQUENESS-VECTORS (LIST OF BOOLEAN-VECTOR)) ((SELF NAMED-DESCRIPTION)))", ((cpp_function_code)(&getBinaryUniquenessVectors)), NULL);
    defineFunctionObject("GET-UNIQUENESS-VECTORS", "(DEFUN (GET-UNIQUENESS-VECTORS (LIST OF BOOLEAN-VECTOR)) ((SELF NAMED-DESCRIPTION)))", ((cpp_function_code)(&getUniquenessVectors)), NULL);
    defineFunctionObject("GET-BINARY-INDEXING-VECTOR", "(DEFUN (GET-BINARY-INDEXING-VECTOR BOOLEAN-VECTOR) ((SELF NAMED-DESCRIPTION)))", ((cpp_function_code)(&getBinaryIndexingVector)), NULL);
    defineFunctionObject("GET-INDEXING-VECTOR", "(DEFUN (GET-INDEXING-VECTOR BOOLEAN-VECTOR) ((SELF NAMED-DESCRIPTION)))", ((cpp_function_code)(&getIndexingVector)), NULL);
    defineFunctionObject("UPDATE-OBSERVED-CARDINALITY", "(DEFUN UPDATE-OBSERVED-CARDINALITY ((SELF NAMED-DESCRIPTION) (CARDINALITY INTEGER)))", ((cpp_function_code)(&updateObservedCardinality)), NULL);
    defineFunctionObject("ACCESS-OBSERVED-CARDINALITY", "(DEFUN (ACCESS-OBSERVED-CARDINALITY INTEGER) ((SELF DESCRIPTION)))", ((cpp_function_code)(&accessObservedCardinality)), NULL);
    defineFunctionObject("ESTIMATE-CARDINALITY-OF-EXTENSION", "(DEFUN (ESTIMATE-CARDINALITY-OF-EXTENSION COST-ESTIMATE) ((DESCRIPTION NAMED-DESCRIPTION)))", ((cpp_function_code)(&estimateCardinalityOfExtension)), NULL);
    defineFunctionObject("ESTIMATE-MEMBER-OF-GOAL-FANOUT", "(DEFUN (ESTIMATE-MEMBER-OF-GOAL-FANOUT COST-ESTIMATE) ((GOAL PROPOSITION)))", ((cpp_function_code)(&estimateMemberOfGoalFanout)), NULL);
    defineFunctionObject("ESTIMATE-PREDICATE-GOAL-FANOUT", "(DEFUN (ESTIMATE-PREDICATE-GOAL-FANOUT COST-ESTIMATE) ((GOAL PROPOSITION)))", ((cpp_function_code)(&estimatePredicateGoalFanout)), NULL);
    defineFunctionObject("ESTIMATE-GOAL-COST", "(DEFUN (ESTIMATE-GOAL-COST COST-ESTIMATE) ((GOAL PROPOSITION)))", ((cpp_function_code)(&estimateGoalCost)), NULL);
    defineFunctionObject("ESTIMATE-GOAL-FANOUT", "(DEFUN (ESTIMATE-GOAL-FANOUT COST-ESTIMATE) ((GOAL PROPOSITION)))", ((cpp_function_code)(&estimateGoalFanout)), NULL);
    defineFunctionObject("CHEAPEST-GENERATOR-GOAL", "(DEFUN (CHEAPEST-GENERATOR-GOAL PROPOSITION COST-ESTIMATE COST-ESTIMATE) ((VARIABLE PATTERN-VARIABLE)))", ((cpp_function_code)(&cheapestGeneratorGoal)), NULL);
    defineFunctionObject("PROPAGATE-SINGLE-VALUED-CONSTRAINTS", "(DEFUN PROPAGATE-SINGLE-VALUED-CONSTRAINTS ((GOAL PROPOSITION) (GOALSEQUENCE (LIST OF PROPOSITION))))", ((cpp_function_code)(&propagateSingleValuedConstraints)), NULL);
    defineFunctionObject("COLLECT-CLOSED-GOALS", "(DEFUN COLLECT-CLOSED-GOALS ((GOALS (LIST OF PROPOSITION)) (GOALSEQUENCE (LIST OF PROPOSITION))))", ((cpp_function_code)(&collectClosedGoals)), NULL);
    defineFunctionObject("SIMULATE-BIND-VARIABLE-AND-PROPAGATE-CONSTRAINTS", "(DEFUN SIMULATE-BIND-VARIABLE-AND-PROPAGATE-CONSTRAINTS ((VARIABLE PATTERN-VARIABLE) (GOALSEQUENCE (LIST OF PROPOSITION))))", ((cpp_function_code)(&simulateBindVariableAndPropagateConstraints)), NULL);
    defineFunctionObject("BIND-ALL-VARIABLES-IN-GENERATOR-GOAL", "(DEFUN BIND-ALL-VARIABLES-IN-GENERATOR-GOAL ((GOAL PROPOSITION) (GOALSEQUENCE (LIST OF PROPOSITION))))", ((cpp_function_code)(&bindAllVariablesInGeneratorGoal)), NULL);
    defineFunctionObject("COMPUTE-OPTIMAL-OPEN-GOAL-ORDERING", "(DEFUN COMPUTE-OPTIMAL-OPEN-GOAL-ORDERING ((OPTIMIZERVARIABLES (LIST OF PATTERN-VARIABLE)) (NUMBEROFOPENGOALS INTEGER) (GOALSEQUENCE (LIST OF PROPOSITION)) (PRIORCOST COST-ESTIMATE) (PRIORFANOUT COST-ESTIMATE)))", ((cpp_function_code)(&computeOptimalOpenGoalOrdering)), NULL);
    defineFunctionObject("COMPUTE-GREEDY-OPEN-GOAL-ORDERING", "(DEFUN COMPUTE-GREEDY-OPEN-GOAL-ORDERING ((OPTIMIZERVARIABLES (LIST OF PATTERN-VARIABLE)) (NUMBEROFOPENGOALS INTEGER) (GOALSEQUENCE (LIST OF PROPOSITION)) (PRIORCOST COST-ESTIMATE) (PRIORFANOUT COST-ESTIMATE)))", ((cpp_function_code)(&computeGreedyOpenGoalOrdering)), NULL);
    defineFunctionObject("COMPUTE-BACKUP-OPEN-GOAL-ORDERING", "(DEFUN COMPUTE-BACKUP-OPEN-GOAL-ORDERING ((GOALSEQUENCE (LIST OF PROPOSITION))))", ((cpp_function_code)(&computeBackupOpenGoalOrdering)), NULL);
    defineFunctionObject("COLLECT-UNBOUND-GOAL-VARIABLES", "(DEFUN COLLECT-UNBOUND-GOAL-VARIABLES ((GOAL PROPOSITION) (UNBOUNDVARIABLES (LIST OF PATTERN-VARIABLE))))", ((cpp_function_code)(&collectUnboundGoalVariables)), NULL);
    defineFunctionObject("EXTRACT-OPEN-GOAL-CLUSTERS", "(DEFUN EXTRACT-OPEN-GOAL-CLUSTERS ((OPENGOALS (LIST OF PROPOSITION)) (OPENGOALCLUSTERS (LIST OF (LIST OF PROPOSITION)))))", ((cpp_function_code)(&extractOpenGoalClusters)), NULL);
    defineFunctionObject("COLLECT-OPTIMIZER-VARIABLES", "(DEFUN COLLECT-OPTIMIZER-VARIABLES ((PROPOSITION PROPOSITION) (COLLECTION LIST)))", ((cpp_function_code)(&collectOptimizerVariables)), NULL);
    defineFunctionObject("BIGGER-CONJUNCTION?", "(DEFUN (BIGGER-CONJUNCTION? BOOLEAN) ((PROP1 PROPOSITION) (PROP2 PROPOSITION)))", ((cpp_function_code)(&biggerConjunctionP)), NULL);
    defineFunctionObject("COMPUTE-OPEN-GOAL-ORDERING", "(DEFUN COMPUTE-OPEN-GOAL-ORDERING ((ANDPROPOSITION PROPOSITION) (OPENGOALS (LIST OF PROPOSITION)) (GOALSEQUENCE (LIST OF PROPOSITION))))", ((cpp_function_code)(&computeOpenGoalOrdering)), NULL);
    defineFunctionObject("OPTIMIZE-ORDERING-OF-CONJUNCTS", "(DEFUN OPTIMIZE-ORDERING-OF-CONJUNCTS ((ANDPROPOSITION PROPOSITION)))", ((cpp_function_code)(&optimizeOrderingOfConjuncts)), NULL);
    defineFunctionObject("REORDER-GOALS", "(DEFUN REORDER-GOALS ((ANDPROPOSITION PROPOSITION) (INITIALLYCLOSEDGOALS (LIST OF PROPOSITION)) (GOALSEQUENCE (LIST OF PROPOSITION)) (RESIDUEGOALS (LIST OF PROPOSITION))))", ((cpp_function_code)(&reorderGoals)), NULL);
    defineFunctionObject("SIMULATE-BIND-VARIABLE-TO-VALUE", "(DEFUN SIMULATE-BIND-VARIABLE-TO-VALUE ((FORMULA OBJECT)))", ((cpp_function_code)(&simulateBindVariableToValue)), NULL);
    defineFunctionObject("WARN-OF-UNBOUND-VARIABLE-ARGUMENT", "(DEFUN WARN-OF-UNBOUND-VARIABLE-ARGUMENT ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&warnOfUnboundVariableArgument)), NULL);
    defineFunctionObject("SIMULATE-GOAL-EVALUATION", "(DEFUN SIMULATE-GOAL-EVALUATION ((GOAL PROPOSITION)))", ((cpp_function_code)(&simulateGoalEvaluation)), NULL);
    defineFunctionObject("SIMULATE-AND-OPTIMIZE-ARGUMENT", "(DEFUN SIMULATE-AND-OPTIMIZE-ARGUMENT ((FORMULA OBJECT)))", ((cpp_function_code)(&simulateAndOptimizeArgument)), NULL);
    defineFunctionObject("SIMULATE-AND-OPTIMIZE-QUERY", "(DEFUN SIMULATE-AND-OPTIMIZE-QUERY ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&simulateAndOptimizeQuery)), NULL);
    defineFunctionObject("INITIALIZE-OPTIMIZER-MEMORY", "(DEFUN INITIALIZE-OPTIMIZER-MEMORY ((STACKSIZE INTEGER)))", ((cpp_function_code)(&initializeOptimizerMemory)), NULL);
    defineFunctionObject("OPTIMIZE-QUERY", "(DEFUN OPTIMIZE-QUERY ((DESCRIPTION DESCRIPTION) (BOOLEANVECTOR BOOLEAN-VECTOR) (PARENTFRAME CONTROL-FRAME)))", ((cpp_function_code)(&optimizeQuery)), NULL);
    defineFunctionObject("USE-DYNAMIC-QUERY-OPTIMIZATION?", "(DEFUN (USE-DYNAMIC-QUERY-OPTIMIZATION? BOOLEAN) () :GLOBALLY-INLINE? TRUE (RETURN (AND (OR (EQL? *QUERY-OPTIMIZATION-STRATEGY* :DYNAMIC) (EQL? *QUERY-OPTIMIZATION-STRATEGY* :DYNAMIC-WITH-CLUSTERING)))))", ((cpp_function_code)(&useDynamicQueryOptimizationP)), NULL);
    defineFunctionObject("DYNAMICALLY-OPTIMIZE-PROPOSITION?", "(DEFUN (DYNAMICALLY-OPTIMIZE-PROPOSITION? BOOLEAN) ((SELF PROPOSITION)))", ((cpp_function_code)(&dynamicallyOptimizePropositionP)), NULL);
    defineFunctionObject("USE-STATIC-QUERY-OPTIMIZATION?", "(DEFUN (USE-STATIC-QUERY-OPTIMIZATION? BOOLEAN) () :GLOBALLY-INLINE? TRUE (RETURN (AND (NOT (EQL? *QUERY-OPTIMIZATION-STRATEGY* :NONE)) (NOT (USE-DYNAMIC-QUERY-OPTIMIZATION?)))))", ((cpp_function_code)(&useStaticQueryOptimizationP)), NULL);
    defineFunctionObject("STATICALLY-OPTIMIZE-PROPOSITION?", "(DEFUN (STATICALLY-OPTIMIZE-PROPOSITION? BOOLEAN) ((SELF PROPOSITION)))", ((cpp_function_code)(&staticallyOptimizePropositionP)), NULL);
    defineFunctionObject("TRY-TO-CLUSTER-CONJUNCTIONS?", "(DEFUN (TRY-TO-CLUSTER-CONJUNCTIONS? BOOLEAN) () :GLOBALLY-INLINE? TRUE (RETURN (OR (EQL? *QUERY-OPTIMIZATION-STRATEGY* :STATIC-WITH-CLUSTERING))))", ((cpp_function_code)(&tryToClusterConjunctionsP)), NULL);
    defineFunctionObject("SELECT-OPTIMAL-QUERY-PATTERN", "(DEFUN (SELECT-OPTIMAL-QUERY-PATTERN DESCRIPTION) ((DESCRIPTION DESCRIPTION) (BOOLEANVECTOR BOOLEAN-VECTOR) (PARENTFRAME CONTROL-FRAME)))", ((cpp_function_code)(&selectOptimalQueryPattern)), NULL);
    defineFunctionObject("DYNAMICALLY-ESTIMATE-GOAL-COST", "(DEFUN (DYNAMICALLY-ESTIMATE-GOAL-COST COST-ESTIMATE) ((GOAL PROPOSITION)))", ((cpp_function_code)(&dynamicallyEstimateGoalCost)), NULL);
    defineFunctionObject("DYNAMICALLY-ESTIMATE-GOAL-FANOUT", "(DEFUN (DYNAMICALLY-ESTIMATE-GOAL-FANOUT COST-ESTIMATE) ((GOAL PROPOSITION)))", ((cpp_function_code)(&dynamicallyEstimateGoalFanout)), NULL);
  }
}

void helpStartupOptimize5() {
  {
    defineFunctionObject("DYNAMICALLY-ESTIMATE-PREDICATE-GOAL-FANOUT", "(DEFUN (DYNAMICALLY-ESTIMATE-PREDICATE-GOAL-FANOUT COST-ESTIMATE) ((GOAL PROPOSITION)))", ((cpp_function_code)(&dynamicallyEstimatePredicateGoalFanout)), NULL);
    defineFunctionObject("DYNAMICALLY-ESTIMATE-INSTANCE-OF-GOAL-FANOUT", "(DEFUN (DYNAMICALLY-ESTIMATE-INSTANCE-OF-GOAL-FANOUT COST-ESTIMATE) ((GOAL PROPOSITION)))", ((cpp_function_code)(&dynamicallyEstimateInstanceOfGoalFanout)), NULL);
    defineFunctionObject("DYNAMICALLY-ESTIMATE-EXTENSION-SIZE", "(DEFUN (DYNAMICALLY-ESTIMATE-EXTENSION-SIZE COST-ESTIMATE) ((DESCRIPTION NAMED-DESCRIPTION)))", ((cpp_function_code)(&dynamicallyEstimateExtensionSize)), NULL);
    defineFunctionObject("DYNAMICALLY-ESTIMATE-UNBOUND-VARIABLE-PENALTY", "(DEFUN (DYNAMICALLY-ESTIMATE-UNBOUND-VARIABLE-PENALTY COST-ESTIMATE) ((GOAL PROPOSITION)))", ((cpp_function_code)(&dynamicallyEstimateUnboundVariablePenalty)), NULL);
    defineFunctionObject("DYNAMICALLY-REOPTIMIZE-ARGUMENTS", "(DEFUN DYNAMICALLY-REOPTIMIZE-ARGUMENTS ((ARGUMENTS (VECTOR OF PROPOSITION)) (CURSOR INTEGER)))", ((cpp_function_code)(&dynamicallyReoptimizeArguments)), NULL);
    defineFunctionObject("SIMPLIFY-DESCRIPTION", "(DEFUN SIMPLIFY-DESCRIPTION ((DESCRIPTION DESCRIPTION) (POSTOPTIMIZATION? BOOLEAN)))", ((cpp_function_code)(&simplifyDescription)), NULL);
    defineFunctionObject("COPY-LIST-TO-ARGUMENTS-VECTOR", "(DEFUN (COPY-LIST-TO-ARGUMENTS-VECTOR ARGUMENTS-VECTOR) ((ARGUMENTS LIST)))", ((cpp_function_code)(&copyListToArgumentsVector)), NULL);
    defineFunctionObject("CONJUNCT-CANCELS-ISA-PROPOSITION?", "(DEFUN (CONJUNCT-CANCELS-ISA-PROPOSITION? BOOLEAN) ((ISACONJUNCT PROPOSITION) (OTHERCONJUNCT PROPOSITION)))", ((cpp_function_code)(&conjunctCancelsIsaPropositionP)), NULL);
    defineFunctionObject("SIMPLIFY-CONJUNCTION", "(DEFUN SIMPLIFY-CONJUNCTION ((ANDPROPOSITION PROPOSITION)))", ((cpp_function_code)(&simplifyConjunction)), NULL);
    defineFunctionObject("SIMPLIFY-PROPOSITION", "(DEFUN SIMPLIFY-PROPOSITION ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&simplifyProposition)), NULL);
    defineFunctionObject("COPY-DESCRIPTION", "(DEFUN (COPY-DESCRIPTION DESCRIPTION) ((SELF DESCRIPTION) (PARENTMAPPING ENTITY-MAPPING) (ADDBACKLINKS? BOOLEAN)))", ((cpp_function_code)(&copyDescription)), NULL);
    defineFunctionObject("COPY-VARIABLE", "(DEFUN (COPY-VARIABLE PATTERN-VARIABLE) ((SELF PATTERN-VARIABLE) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&copyVariable)), NULL);
    defineFunctionObject("COPY-VARIABLES-VECTOR", "(DEFUN (COPY-VARIABLES-VECTOR VARIABLES-VECTOR) ((SELF VARIABLES-VECTOR) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&copyVariablesVector)), NULL);
    defineFunctionObject("COPY-PROPOSITION", "(DEFUN (COPY-PROPOSITION PROPOSITION) ((SELF PROPOSITION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&copyProposition)), NULL);
    defineFunctionObject("COPY-PROPOSITION-ARGUMENT", "(DEFUN (COPY-PROPOSITION-ARGUMENT OBJECT) ((SELF OBJECT) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&copyPropositionArgument)), NULL);
    defineFunctionObject("MAPPED-VALUE-OF", "(DEFUN (MAPPED-VALUE-OF OBJECT) ((SELF OBJECT) (MAPPING ENTITY-MAPPING) (CREATESKOLEM? BOOLEAN)))", ((cpp_function_code)(&mappedValueOf)), NULL);
    defineFunctionObject("SINGLE-VALUED-PREDICATE?", "(DEFUN (SINGLE-VALUED-PREDICATE? BOOLEAN) ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&singleValuedPredicateP)), NULL);
    defineFunctionObject("BINARY-PROPOSITION?", "(DEFUN (BINARY-PROPOSITION? BOOLEAN) ((PROPOSITION PROPOSITION)) :GLOBALLY-INLINE? TRUE (RETURN (EQL? (LENGTH (ARGUMENTS PROPOSITION)) 2)))", ((cpp_function_code)(&binaryPropositionP)), NULL);
    defineFunctionObject("INHERIT-EQUIVALENT-PROPOSITION", "(DEFUN (INHERIT-EQUIVALENT-PROPOSITION PROPOSITION) ((SKOLEM SKOLEM) (VALUE OBJECT)))", ((cpp_function_code)(&inheritEquivalentProposition)), NULL);
    defineFunctionObject("INHERIT-FUNCTION-PROPOSITION", "(DEFUN (INHERIT-FUNCTION-PROPOSITION PROPOSITION) ((SELF PROPOSITION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&inheritFunctionProposition)), NULL);
    defineFunctionObject("EQUAL-UP-TO-SKOLEM-IDENTITY?", "(DEFUN (EQUAL-UP-TO-SKOLEM-IDENTITY? BOOLEAN) ((INHERITEDARG OBJECT) (BASEARG OBJECT) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&equalUpToSkolemIdentityP)), NULL);
    defineFunctionObject("FIND-SIMILAR-PROPOSITION", "(DEFUN (FIND-SIMILAR-PROPOSITION PROPOSITION) ((PROPOSITION PROPOSITION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&findSimilarProposition)), NULL);
    defineFunctionObject("INHERIT-PROPOSITION-ARGUMENT", "(DEFUN (INHERIT-PROPOSITION-ARGUMENT OBJECT) ((ARGUMENT OBJECT) (PARENT PROPOSITION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&inheritPropositionArgument)), NULL);
    defineFunctionObject("ERADICATE-HOLDS-PROPOSITION", "(DEFUN (ERADICATE-HOLDS-PROPOSITION PROPOSITION) ((SELF PROPOSITION)))", ((cpp_function_code)(&eradicateHoldsProposition)), NULL);
    defineFunctionObject("INHERIT-PROPOSITION", "(DEFUN (INHERIT-PROPOSITION PROPOSITION) ((SELF PROPOSITION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&inheritProposition)), NULL);
    defineFunctionObject("CREATE-SKOLEM-FOR-UNMAPPED-VARIABLE", "(DEFUN (CREATE-SKOLEM-FOR-UNMAPPED-VARIABLE SKOLEM) ((VARIABLE PATTERN-VARIABLE) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&createSkolemForUnmappedVariable)), NULL);
    defineFunctionObject("INHERIT-AS-TOP-LEVEL-PROPOSITION", "(DEFUN (INHERIT-AS-TOP-LEVEL-PROPOSITION (CONS OF PROPOSITION)) ((PROPOSITION PROPOSITION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&inheritAsTopLevelProposition)), NULL);
    defineFunctionObject("MAP-AND-ENQUEUE-VARIABLE?", "(DEFUN (MAP-AND-ENQUEUE-VARIABLE? BOOLEAN) ((VARIABLE OBJECT) (LOCALVALUE OBJECT) (MAPPING ENTITY-MAPPING) (QUEUE LIST)))", ((cpp_function_code)(&mapAndEnqueueVariableP)), NULL);
    defineFunctionObject("COLLECT-STRUCTURAL-FUNCTIONS", "(DEFUN COLLECT-STRUCTURAL-FUNCTIONS ((PROPOSITION PROPOSITION) (STRUCTURALFUNCTIONS (LIST OF PROPOSITION))))", ((cpp_function_code)(&collectStructuralFunctions)), NULL);
    defineFunctionObject("MAP-FUNCTIONAL-VALUE?", "(DEFUN (MAP-FUNCTIONAL-VALUE? BOOLEAN) ((PROPOSITION PROPOSITION) (MAPPING ENTITY-MAPPING) (QUEUE LIST)))", ((cpp_function_code)(&mapFunctionalValueP)), NULL);
    defineFunctionObject("INHERIT-DESCRIPTION-PROPOSITIONS", "(DEFUN (INHERIT-DESCRIPTION-PROPOSITIONS (CONS OF PROPOSITION)) ((ARGUMENTS VECTOR) (DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&inheritDescriptionPropositions)), NULL);
    defineFunctionObject("INHERIT-UNNAMED-DESCRIPTION", "(DEFUN INHERIT-UNNAMED-DESCRIPTION ((SELF OBJECT) (DESCRIPTION DESCRIPTION) (DEFAULTTRUE? BOOLEAN)) :PUBLIC? TRUE)", ((cpp_function_code)(&inheritUnnamedDescription)), NULL);
    defineFunctionObject("VECTOR.INHERIT-UNNAMED-DESCRIPTION", "(DEFUN VECTOR.INHERIT-UNNAMED-DESCRIPTION ((ARGUMENTS VECTOR) (DESCRIPTION DESCRIPTION) (DEFAULTTRUE? BOOLEAN)))", ((cpp_function_code)(&vectorDinheritUnnamedDescription)), NULL);
    defineFunctionObject("LOGIC-OBJECT.INHERIT-UNNAMED-DESCRIPTION", "(DEFUN LOGIC-OBJECT.INHERIT-UNNAMED-DESCRIPTION ((INSTANCE LOGIC-OBJECT) (DESCRIPTION DESCRIPTION) (DEFAULTTRUE? BOOLEAN)))", ((cpp_function_code)(&logicObjectDinheritUnnamedDescription)), NULL);
    defineFunctionObject("INHERIT-DESCRIPTION", "(DEFUN INHERIT-DESCRIPTION ((ARGUMENTS VECTOR) (DESCRIPTION DESCRIPTION) (DEFAULTTRUE? BOOLEAN)))", ((cpp_function_code)(&inheritDescription)), NULL);
    defineFunctionObject("STARTUP-OPTIMIZE", "(DEFUN STARTUP-OPTIMIZE () :PUBLIC? TRUE)", ((cpp_function_code)(&startupOptimize)), NULL);
    { MethodSlot* function = lookupFunction(SYM_OPTIMIZE_LOGIC_STARTUP_OPTIMIZE);

      setDynamicSlotValue(function->dynamicSlots, SYM_OPTIMIZE_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupOptimize"), NULL_STRING_WRAPPER);
    }
  }
}

void startupOptimize() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupOptimize1();
      helpStartupOptimize2();
    }
    if (currentStartupTimePhaseP(4)) {
      helpStartupOptimize3();
    }
    if (currentStartupTimePhaseP(5)) {
      { Class* clasS = defineClassFromStringifiedSource("GOAL-RECORD", "(DEFCLASS GOAL-RECORD (STANDARD-OBJECT) :SLOTS ((GENERATOR-GOALS :TYPE (LIST OF PROPOSITION) :ALLOCATION :EMBEDDED) (OTHER-GOALS :TYPE (LIST OF PROPOSITION) :ALLOCATION :EMBEDDED)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newGoalRecord));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessGoalRecordSlotValue));
      }
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupOptimize4();
      helpStartupOptimize5();
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *DISTRIBUTEDOPENGOAL?* BOOLEAN FALSE :DOCUMENTATION \"Used by 'distribute-open-goal' to signal that\na goal was distributed by 'help-distribute-goal'.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT V-0-0 BOOLEAN-VECTOR (ZERO-ONE-LIST-TO-BOOLEAN-VECTOR (LIST 0 0)))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT V-1-0 BOOLEAN-VECTOR (ZERO-ONE-LIST-TO-BOOLEAN-VECTOR (LIST 1 0)))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT V-0-1 BOOLEAN-VECTOR (ZERO-ONE-LIST-TO-BOOLEAN-VECTOR (LIST 0 1)))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT V-1-1 BOOLEAN-VECTOR (ZERO-ONE-LIST-TO-BOOLEAN-VECTOR (LIST 1 1)))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT V-1-0-AND-V-0-1 (LIST OF BOOLEAN-VECTOR) (LIST V-1-0 V-0-1))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT V-1-0-SINGLETON (LIST OF BOOLEAN-VECTOR) (LIST V-1-0))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT V-0-1-SINGLETON (LIST OF BOOLEAN-VECTOR) (LIST V-0-1))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT ESTIMATED-SLOT-VALUE-COLLECTION-SIZE COST-ESTIMATE 4.0 :DOCUMENTATION \"Estimate of the average size of a collection\nrepresenting the fillers of a slot.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT ESTIMATED-NUMBER-OF-PREDICATE-BINDINGS COST-ESTIMATE 6.0 :DOCUMENTATION \"Very crude estimate of the number of stored propositions\nthat will match a predicate at least one of whose arguments are bound.\nChosen to be larger than ESTIMATED-SLOT-VALUE-COLLECTION-SIZE.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT ESTIMATED-SIZE-OF-CLASS-EXTENSION COST-ESTIMATE 11.0 :DOCUMENTATION \"Must be greater than ESTIMATED-NUMBER-OF-PREDICATE-BINDINGS\nto force the optimizer to prefer predicates containing at least\none bound variable.  Also greater than ESTIMATED-SIZE-OF-PREDICATE-EXTENSION,\nfor no particularly valid reason.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT ESTIMATED-CARDINALITY-OF-DESCRIPTION COST-ESTIMATE 20.0 :DOCUMENTATION \"Indefensible estimate of the number instances\ngenerable by an arbitrary unnamed description.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT ESTIMATED-CARDINALITY-OF-MEMBER-OF COST-ESTIMATE 30.0 :DOCUMENTATION \"Even more indefensible estimate of the number instances\ngenerable by a 'member-of' predicate.  CAUTION: Must be set\nless than 'ESTIMATED-CARDINALITY-OF-SUBSET-OF'.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT ESTIMATED-CARDINALITY-OF-SUBSET-OF COST-ESTIMATE 40.0 :DOCUMENTATION \"Egregiously indefensible estimate of the number instances\ngenerable by a 'subset-of' predicate.  Set high because 'subset-of'\ncan't generate all defined supersets or subsets, causing potential\nincompleteness.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT INFERABLE-PENALTY-COST COST-ESTIMATE 7.0 :DOCUMENTATION \"Amount of penalty for using inferable relations as goals.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT SUBSET-OF-PENALTY-COST COST-ESTIMATE 20.0 :DOCUMENTATION \"Amount of penalty for using 'subset-of' as a goal.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *OPTIMALGOALORDERINGRECURSIONS* INTEGER NULL)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *OPTIMAL-GOAL-ORDERING-CUTOFF* INTEGER 100)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *QUERYOPTIMIZERCONTROLFRAME* CONTROL-FRAME :DOCUMENTATION \"Keeps track of last control frame allocated by\nthe query optimizer.  Used by recursive invocations of the optimizer.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *BOUNDTOOFFSETCOUNTER* INTEGER NULL :DOCUMENTATION \"Enables 'select-optimal-query-pattern' to tell\n'copy-variables-vector' that it should initialize the 'bound-to-offset'\nslot of each variable in the copy operation.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *QUERY-OPTIMIZATION-STRATEGY* KEYWORD :DYNAMIC :DOCUMENTATION \"Keyword indicating what clause reordering strategy should\nbe used for conjunctive queries.  Legal values are :STATIC which performs\noptimization once for each conjunctive pattern by simulating a query,\n:STATIC-WITH-CLUSTERING which additionally tries to cluster conjunction into\nindependent clusters, :DYNAMIC which performs simple greedy optimization\ndynamically during a query, :DYNAMIC-WITH-CLUSTERING which also looks\nfor clusters (not yet implemented), and :NONE to indicate no optimization\nshould be performed.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *POSTOPTIMIZATION?* BOOLEAN FALSE :DOCUMENTATION \"Used by 'simplify-description' to permit application\nof order-dependent optimizations.\")");
    }
  }
}

Surrogate* SGT_OPTIMIZE_LOGIC_GOAL_RECORD = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_GENERATOR_GOALS = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_OTHER_GOALS = NULL;

Surrogate* SGT_OPTIMIZE_LOGIC_PATTERN_VARIABLE = NULL;

Surrogate* SGT_OPTIMIZE_LOGIC_PROPOSITION = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_IO_VARIABLES = NULL;

Surrogate* SGT_OPTIMIZE_LOGIC_DESCRIPTION = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_EXTERNAL_VARIABLES = NULL;

Keyword* KWD_OPTIMIZE_OR = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_PERMUTATION_TABLE = NULL;

Surrogate* SGT_OPTIMIZE_PL_KERNEL_KB_COMPUTED = NULL;

Surrogate* SGT_OPTIMIZE_PL_KERNEL_KB_RELATION_CONSTRAINT = NULL;

Surrogate* SGT_OPTIMIZE_PL_KERNEL_KB_ABSTRACT = NULL;

Surrogate* SGT_OPTIMIZE_LOGIC_NAMED_DESCRIPTION = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_OPTIMIZER_GOAL_RECORDS = NULL;

Keyword* KWD_OPTIMIZE_FUNCTION = NULL;

Keyword* KWD_OPTIMIZE_EQUIVALENT = NULL;

Keyword* KWD_OPTIMIZE_ISA = NULL;

Keyword* KWD_OPTIMIZE_PREDICATE = NULL;

Keyword* KWD_OPTIMIZE_NOT = NULL;

Keyword* KWD_OPTIMIZE_FAIL = NULL;

Keyword* KWD_OPTIMIZE_IMPLIES = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_UNIQUENESSVECTORS = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_INVERSE_DESCRIPTION = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_INDEXING_VECTOR = NULL;

Surrogate* SGT_OPTIMIZE_PL_KERNEL_KB_OBSERVED_CARDINALITY_OF = NULL;

Surrogate* SGT_OPTIMIZE_STELLA_INTEGER_WRAPPER = NULL;

Surrogate* SGT_OPTIMIZE_STELLA_COLLECTION = NULL;

Surrogate* SGT_OPTIMIZE_PL_KERNEL_KB_MEMBER_OF = NULL;

Keyword* KWD_OPTIMIZE_OPTIMIZER = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_BEST_GOAL_SEQUENCE = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_BEST_COST = NULL;

Keyword* KWD_OPTIMIZE_FORALL = NULL;

Keyword* KWD_OPTIMIZE_EXISTS = NULL;

Keyword* KWD_OPTIMIZE_STATIC_WITH_CLUSTERING = NULL;

Keyword* KWD_OPTIMIZE_DESCRIPTION = NULL;

Keyword* KWD_OPTIMIZE_AND = NULL;

Keyword* KWD_OPTIMIZE_BOUND = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_RESIDUE_GOALS = NULL;

Keyword* KWD_OPTIMIZE_PATTERN = NULL;

Keyword* KWD_OPTIMIZE_DYNAMIC = NULL;

Keyword* KWD_OPTIMIZE_DYNAMIC_WITH_CLUSTERING = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_DONT_OPTIMIZEp = NULL;

Keyword* KWD_OPTIMIZE_NONE = NULL;

Surrogate* SGT_OPTIMIZE_PL_KERNEL_KB_CUT = NULL;

Surrogate* SGT_OPTIMIZE_PL_KERNEL_KB_BOUND_VARIABLES = NULL;

Surrogate* SGT_OPTIMIZE_PL_KERNEL_KB_HOLDS = NULL;

Surrogate* SGT_OPTIMIZE_PL_KERNEL_KB_INSTANCE_OF = NULL;

Surrogate* SGT_OPTIMIZE_PL_KERNEL_KB_TOTAL = NULL;

Keyword* KWD_OPTIMIZE_RELATION = NULL;

Surrogate* SGT_OPTIMIZE_STELLA_THING = NULL;

Keyword* KWD_OPTIMIZE_REALISTIC = NULL;

Keyword* KWD_OPTIMIZE_FLAT = NULL;

Surrogate* SGT_OPTIMIZE_STELLA_CS_VALUE = NULL;

Keyword* KWD_OPTIMIZE_CONSTANT = NULL;

Symbol* SYM_OPTIMIZE_STELLA_PREDICATE = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_WEIGHT = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_VARIABLE_TYPEp = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_DESCRIPTIVEp = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_ANNOTATIONS = NULL;

Surrogate* SGT_OPTIMIZE_LOGIC_LOGIC_OBJECT = NULL;

Surrogate* SGT_OPTIMIZE_PL_KERNEL_KB_EQUIVALENT = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_EQUIVALENT = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_CONSTANT = NULL;

Surrogate* SGT_OPTIMIZE_STELLA_VECTOR = NULL;

Keyword* KWD_OPTIMIZE_CONCEIVE = NULL;

Symbol* SYM_OPTIMIZE_LOGIC_STARTUP_OPTIMIZE = NULL;

Symbol* SYM_OPTIMIZE_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
