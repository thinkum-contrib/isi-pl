//  -*- Mode: C++ -*-

// backlinks.cc

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

#include "logic/logic-system.hh"

namespace logic {
  using namespace stella;

boolean typeHasBacklinksP(Surrogate* type) {
  if (!((boolean)(type->surrogateValue))) {
    return (FALSE);
  }
  else {
    return (!literalTypeP(type));
  }
}

BacklinksIndex* createBacklinksIndex(Object* self) {
  { BacklinksIndex* index = newBacklinksIndex();

    index->dependentPropositionsList = (isaP(self, SGT_BACKLINKS_LOGIC_PATTERN_VARIABLE) ? createSequenceIndex(KWD_BACKLINKS_NON_PAGING, NIL) : createSequenceIndex(oMODULEo.get(), cons(KWD_BACKLINKS_DEPENDENTS, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(self, NIL)))));
    return (index);
  }
}

BacklinksIndex* getBacklinksIndex(Object* self) {
  if (!((boolean)(self))) {
    return (NULL);
  }
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_BACKLINKS_LOGIC_LOGIC_OBJECT)) {
      { Object* self000 = self;
        LogicObject* self = ((LogicObject*)(self000));

        { BacklinksIndex* index = self->dependentPropositionsIndex;

          if (((boolean)(index))) {
            return (index);
          }
          index = createBacklinksIndex(self);
          self->dependentPropositionsIndex = index;
          return (index);
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_BACKLINKS_STELLA_THING)) {
      { Object* self001 = self;
        Thing* self = ((Thing*)(self001));

        { BacklinksIndex* index = ((BacklinksIndex*)(dynamicSlotValue(self->dynamicSlots, SYM_BACKLINKS_LOGIC_DEPENDENT_PROPOSITIONS_INDEX, NULL)));

          if (((boolean)(index))) {
            return (index);
          }
          index = createBacklinksIndex(self);
          setDynamicSlotValue(self->dynamicSlots, SYM_BACKLINKS_LOGIC_DEPENDENT_PROPOSITIONS_INDEX, index, NULL);
          return (index);
        }
      }
    }
    else if (subtypeOfWrapperP(testValue000)) {
      { Object* self002 = self;
        Wrapper* self = ((Wrapper*)(self002));

        { Surrogate* testValue001 = safePrimaryType(self);

          if (subtypeOfP(testValue001, SGT_BACKLINKS_LOGIC_INTEGER_LOGIC_WRAPPER)) {
            { Wrapper* self003 = self;
              IntegerLogicWrapper* self = ((IntegerLogicWrapper*)(self003));

              { BacklinksIndex* index = self->dependentPropositionsIndex;

                if (((boolean)(index))) {
                  return (index);
                }
                index = createBacklinksIndex(self);
                self->dependentPropositionsIndex = index;
                return (index);
              }
            }
          }
          else if (subtypeOfP(testValue001, SGT_BACKLINKS_LOGIC_FLOAT_LOGIC_WRAPPER)) {
            { Wrapper* self004 = self;
              FloatLogicWrapper* self = ((FloatLogicWrapper*)(self004));

              { BacklinksIndex* index = self->dependentPropositionsIndex;

                if (((boolean)(index))) {
                  return (index);
                }
                index = createBacklinksIndex(self);
                self->dependentPropositionsIndex = index;
                return (index);
              }
            }
          }
          else if (subtypeOfP(testValue001, SGT_BACKLINKS_LOGIC_STRING_LOGIC_WRAPPER)) {
            { Wrapper* self005 = self;
              StringLogicWrapper* self = ((StringLogicWrapper*)(self005));

              { BacklinksIndex* index = self->dependentPropositionsIndex;

                if (((boolean)(index))) {
                  return (index);
                }
                index = createBacklinksIndex(self);
                self->dependentPropositionsIndex = index;
                return (index);
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
  return (NULL);
}

// When 'dependent-propositions-list' gets this long in a
// backlinks index, then we create a hash table index and other
// specialized indices.
int oSPECIALIZED_BACKLINKS_CROSSOVER_POINTo = 10;

void addDependentPropositionToSpecializedIndex(BacklinksIndex* index, Proposition* proposition, Object* argument) {
  { HashTable* table = index->predicatePropositionsTable;

    if (!((boolean)(table))) {
      table = newHashTable();
      index->predicatePropositionsTable = table;
      { Proposition* prop = NULL;
        Iterator* iter000 = index->dependentPropositionsList->allocateIterator();

        while (iter000->nextP()) {
          prop = ((Proposition*)(iter000->value));
          addDependentPropositionToSpecializedIndex(index, prop, argument);
        }
      }
    }
    if (proposition->kind == KWD_BACKLINKS_ISA) {
      if (!((boolean)(index->dependentIsaPropositionsList))) {
        index->dependentIsaPropositionsList = createSequenceIndex(oMODULEo.get(), cons(KWD_BACKLINKS_ISA, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(argument, NIL))));
      }
      index->dependentIsaPropositionsList->insert(proposition);
    }
    else {
      { Surrogate* surrogate = ((Surrogate*)(proposition->operatoR));
        SequenceIndex* bucket = NULL;

        bucket = ((SequenceIndex*)(table->lookup(surrogate)));
        if (!((boolean)(bucket))) {
          bucket = createSequenceIndex(oMODULEo.get(), cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(surrogate, cons(argument, NIL)))));
          table->insertAt(surrogate, bucket);
        }
        bucket->insert(proposition);
      }
    }
  }
}

void helpAddDependentProposition(BacklinksIndex* index, Proposition* proposition, Object* argument) {
  { SequenceIndex* alldependentpropositions = index->dependentPropositionsList;
    HashTable* table = index->predicatePropositionsTable;

    if (!((boolean)(table))) {
      if (sequenceIndexDestimatedLength(alldependentpropositions) < oSPECIALIZED_BACKLINKS_CROSSOVER_POINTo) {
        alldependentpropositions->insert(proposition);
        return;
      }
    }
    addDependentPropositionToSpecializedIndex(index, proposition, argument);
    alldependentpropositions->insert(proposition);
  }
}

void addDependentPropositionLink(Object* self, Proposition* proposition) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_BACKLINKS_LOGIC_PROPOSITION)) {
      { Object* self000 = self;
        Proposition* self = ((Proposition*)(self000));

        if (self->kind == KWD_BACKLINKS_CONSTANT) {
        }
        else {
          { NonPagingIndex* index = self->dependentPropositions;

            if (index == NIL_NON_PAGING_INDEX) {
              index = ((NonPagingIndex*)(createSequenceIndex(KWD_BACKLINKS_NON_PAGING, NIL)));
              self->dependentPropositions = index;
            }
            self->dependentPropositions->insert(proposition);
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_BACKLINKS_LOGIC_LOGIC_OBJECT)) {
      { Object* self001 = self;
        LogicObject* self = ((LogicObject*)(self001));

        if (descriptionModeP() &&
            (isaP(self, SGT_BACKLINKS_LOGIC_DESCRIPTION) &&
             (namedDescriptionP(((Description*)(self))) ||
              ((boolean)(((Description*)(dynamicSlotValue(((Description*)(self))->dynamicSlots, SYM_BACKLINKS_LOGIC_COMPLEMENT_DESCRIPTION, NULL)))))))) {
          return;
        }
        { BacklinksIndex* index = getBacklinksIndex(self);

          if (isaP(self, SGT_BACKLINKS_LOGIC_SKOLEM) &&
              ((!isaP(self, SGT_BACKLINKS_LOGIC_PATTERN_VARIABLE)) &&
               descriptionModeP())) {
            std::cout << "Can we eliminate the skolem " << "`" << self << "'" << " from the description???" << std::endl << std::endl;
          }
          helpAddDependentProposition(index, proposition, self);
        }
      }
    }
    else if (subtypeOfWrapperP(testValue000)) {
      { Object* self002 = self;
        Wrapper* self = ((Wrapper*)(self002));

        if (!descriptionModeP()) {
          { BacklinksIndex* index = getBacklinksIndex(self);

            if (((boolean)(index))) {
              helpAddDependentProposition(index, proposition, self);
            }
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_BACKLINKS_STELLA_THING)) {
      { Object* self003 = self;
        Thing* self = ((Thing*)(self003));

        helpAddDependentProposition(getBacklinksIndex(self), proposition, self);
      }
    }
    else {
    }
  }
}

void removeDependentPropositionLink(Object* self, Proposition* proposition) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_BACKLINKS_LOGIC_PROPOSITION)) {
      { Object* self000 = self;
        Proposition* self = ((Proposition*)(self000));

        self->dependentPropositions->remove(proposition);
      }
    }
    else if (subtypeOfP(testValue000, SGT_BACKLINKS_LOGIC_LOGIC_OBJECT)) {
      { Object* self001 = self;
        LogicObject* self = ((LogicObject*)(self001));

        helpRemoveDependentProposition(getBacklinksIndex(self), proposition);
      }
    }
    else if (subtypeOfWrapperP(testValue000)) {
      { Object* self002 = self;
        Wrapper* self = ((Wrapper*)(self002));

        { BacklinksIndex* index = getBacklinksIndex(self);

          if (((boolean)(index))) {
            helpRemoveDependentProposition(index, proposition);
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_BACKLINKS_STELLA_THING)) {
      { Object* self003 = self;
        Thing* self = ((Thing*)(self003));

        helpRemoveDependentProposition(getBacklinksIndex(self), proposition);
      }
    }
    else {
    }
  }
}

void helpRemoveDependentProposition(BacklinksIndex* index, Proposition* proposition) {
  { SequenceIndex* list = index->dependentPropositionsList;
    HashTable* table = index->predicatePropositionsTable;

    if (((boolean)(list))) {
      if (subtypeOfP(safePrimaryType(list), SGT_BACKLINKS_LOGIC_NON_PAGING_INDEX)) {
        { SequenceIndex* list000 = list;
          NonPagingIndex* list = ((NonPagingIndex*)(list000));

          list->remove(proposition);
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "INTERNAL ERROR: `remove' not yet implemented " << "for paging indices";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    if (((boolean)(table))) {
      if (proposition->kind == KWD_BACKLINKS_ISA) {
        list = index->dependentIsaPropositionsList;
        if (((boolean)(list))) {
          if (subtypeOfP(safePrimaryType(list), SGT_BACKLINKS_LOGIC_NON_PAGING_INDEX)) {
            { SequenceIndex* list001 = list;
              NonPagingIndex* list = ((NonPagingIndex*)(list001));

              list->remove(proposition);
            }
          }
          else {
            { OutputStringStream* stream001 = newOutputStringStream();

              *(stream001->nativeStream) << "INTERNAL ERROR: `remove' not yet implemented " << "for paging indices";
              throw *newStellaException(stream001->theStringReader());
            }
          }
        }
      }
      else {
        list = ((SequenceIndex*)(table->lookup(((Surrogate*)(proposition->operatoR)))));
        if (((boolean)(list))) {
          if (subtypeOfP(safePrimaryType(list), SGT_BACKLINKS_LOGIC_NON_PAGING_INDEX)) {
            { SequenceIndex* list002 = list;
              NonPagingIndex* list = ((NonPagingIndex*)(list002));

              list->remove(proposition);
            }
          }
          else {
            { OutputStringStream* stream002 = newOutputStringStream();

              *(stream002->nativeStream) << "INTERNAL ERROR: `remove' not yet implemented " << "for paging indices";
              throw *newStellaException(stream002->theStringReader());
            }
          }
        }
      }
    }
  }
}

void removeAllDependentPropositionLinks(LogicObject* self) {
  self->dependentPropositionsIndex = NULL;
}

IntegerHashTable* oINTEGER_LOGIC_WRAPPER_TABLEo = NULL;

FloatHashTable* oFLOAT_LOGIC_WRAPPER_TABLEo = NULL;

StringHashTable* oSTRING_LOGIC_WRAPPER_TABLEo = NULL;

Object* rewrapArgument(Object* argument) {
  { Object* wrapper = NULL;

    { Surrogate* testValue000 = safePrimaryType(argument);

      if (subtypeOfIntegerP(testValue000)) {
        { Object* argument000 = argument;
          IntegerWrapper* argument = ((IntegerWrapper*)(argument000));

          { int value = argument->wrapperValue;

            wrapper = oINTEGER_LOGIC_WRAPPER_TABLEo->lookup(value);
            if (!((boolean)(wrapper))) {
              wrapper = newIntegerLogicWrapper(value);
              oINTEGER_LOGIC_WRAPPER_TABLEo->insertAt(value, wrapper);
            }
          }
        }
      }
      else if (subtypeOfFloatP(testValue000)) {
        { Object* argument001 = argument;
          FloatWrapper* argument = ((FloatWrapper*)(argument001));

          { double value = argument->wrapperValue;

            wrapper = oFLOAT_LOGIC_WRAPPER_TABLEo->lookup(value);
            if (!((boolean)(wrapper))) {
              wrapper = newFloatLogicWrapper(value);
              oFLOAT_LOGIC_WRAPPER_TABLEo->insertAt(value, wrapper);
            }
          }
        }
      }
      else if (subtypeOfStringP(testValue000)) {
        { Object* argument002 = argument;
          StringWrapper* argument = ((StringWrapper*)(argument002));

          { char* value = argument->wrapperValue;

            wrapper = oSTRING_LOGIC_WRAPPER_TABLEo->lookup(value);
            if (!((boolean)(wrapper))) {
              wrapper = newStringLogicWrapper(value);
              oSTRING_LOGIC_WRAPPER_TABLEo->insertAt(value, wrapper);
            }
          }
        }
      }
      else if (subtypeOfP(testValue000, SGT_BACKLINKS_STELLA_LITERAL_WRAPPER)) {
        { Object* argument003 = argument;
          LiteralWrapper* argument = ((LiteralWrapper*)(argument003));

          std::cout << "Backlinking not implemented on literal of type: " << "`" << argument->primaryType() << "'" << std::endl << std::endl;
          return (argument);
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    return (wrapper);
  }
}

// If TRUE, wrap all literal proposition arguments
// so that they can all support backlink indices.
boolean oBACKLINK_ALL_PROPOSITION_ARGUMENTSpo = FALSE;

boolean indexIthDomainP(NamedDescription* description, int i) {
  { boolean testValue000 = FALSE;

    testValue000 = functionDescriptionP(description);
    if (testValue000) {
      testValue000 = !computedRelationP(description);
      if (testValue000) {
        testValue000 = i == 0;
        if (testValue000) {
          { boolean alwaysP000 = TRUE;

            { Surrogate* t = NULL;
              Iterator* iter000 = description->ioVariableTypes->butLast();

              while (iter000->nextP()) {
                t = ((Surrogate*)(iter000->value));
                if (!logicalSubtypeOfLiteralP(t)) {
                  alwaysP000 = FALSE;
                  break;
                }
              }
            }
            testValue000 = alwaysP000;
          }
        }
      }
    }
    { boolean value000 = testValue000;

      return (value000);
    }
  }
}

boolean rewrapIthArgumentP(Object* argument, Proposition* proposition, int i) {
  { Surrogate* testValue000 = safePrimaryType(argument);

    if (subtypeOfP(testValue000, SGT_BACKLINKS_LOGIC_LOGIC_OBJECT)) {
      { Object* argument000 = argument;
        LogicObject* argument = ((LogicObject*)(argument000));

        return (FALSE);
      }
    }
    else if (subtypeOfP(testValue000, SGT_BACKLINKS_LOGIC_PROPOSITION)) {
      { Object* argument001 = argument;
        Proposition* argument = ((Proposition*)(argument001));

        return (FALSE);
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* argument002 = argument;
        Surrogate* argument = ((Surrogate*)(argument002));

        return (FALSE);
      }
    }
    else if (subtypeOfP(testValue000, SGT_BACKLINKS_STELLA_THING)) {
      { Object* argument003 = argument;
        Thing* argument = ((Thing*)(argument003));

        return (FALSE);
      }
    }
    else {
      return (oBACKLINK_ALL_PROPOSITION_ARGUMENTSpo ||
          (getQuotedTree("((:PREDICATE :FUNCTION) \"/LOGIC\")", "/LOGIC")->memberP(proposition->kind) &&
           indexIthDomainP(getDescription(((Surrogate*)(proposition->operatoR))), i)));
    }
  }
}

void rewrapPropositionArguments(Proposition* self) {
  { Object* arg = NULL;
    int i = NULL_INTEGER;
    Vector* vector000 = self->arguments;
    int index000 = 0;
    int length000 = vector000->length();
    int iter000 = 0;

    while (index000 < length000) {
      arg = (vector000->theArray)[index000];
      index000 = index000 + 1;
      i = iter000;
      iter000 = iter000 + 1;
      if (((boolean)(arg)) &&
          rewrapIthArgumentP(arg, self, i)) {
        (self->arguments->theArray)[i] = (rewrapArgument(arg));
      }
    }
  }
}

SequenceIndex* unfilteredDependentPropositions(Object* self, Surrogate* relation) {
  if (subtypeOfP(safePrimaryType(self), SGT_BACKLINKS_LOGIC_PROPOSITION)) {
    { Object* self000 = self;
      Proposition* self = ((Proposition*)(self000));

      if (!((boolean)(relation))) {
        return (self->dependentPropositions);
      }
      else {
        { SequenceIndex* dependents = createSequenceIndex(KWD_BACKLINKS_NON_PAGING, NULL);

          { Proposition* prop = NULL;
            Iterator* iter000 = self->dependentPropositions->allocateIterator();

            while (iter000->nextP()) {
              prop = ((Proposition*)(iter000->value));
              if (((Surrogate*)(prop->operatoR)) == relation) {
                dependents->push(prop);
              }
            }
          }
          return (dependents);
        }
      }
    }
  }
  else {
    { BacklinksIndex* index = getBacklinksIndex(self);
      SequenceIndex* allpropositionsindex = NULL;

      if (!((boolean)(index))) {
        return (NIL_NON_PAGING_INDEX);
      }
      allpropositionsindex = index->dependentPropositionsList;
      if (!((boolean)(relation))) {
        return (allpropositionsindex);
      }
      { HashTable* table = index->predicatePropositionsTable;
        SequenceIndex* list = ((!((boolean)(table))) ? allpropositionsindex : ((SequenceIndex*)(table->lookup(relation))));

        if (!((boolean)(list))) {
          list = index->dependentIsaPropositionsList;
        }
        if (!((boolean)(list))) {
          return (NIL_NON_PAGING_INDEX);
        }
        if ((list == allpropositionsindex) &&
            isaP(list, SGT_BACKLINKS_LOGIC_PAGING_INDEX)) {
          { ObjectStore* store = ((PagingIndex*)(list))->store;
            SequenceIndex* paginglist = (((boolean)(store)) ? createSequenceIndex(store, cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(relation, cons(self, NIL))))) : ((SequenceIndex*)(NULL)));

            if (((boolean)(paginglist))) {
              { Cons* value000 = NIL;

                { Proposition* prop = NULL;
                  Cons* iter001 = ((Cons*)(list->theSequence));
                  Cons* collect000 = NULL;

                  while (!(iter001 == NIL)) {
                    prop = ((Proposition*)(iter001->value));
                    iter001 = iter001->rest;
                    if (prop->operatoR == relation) {
                      if (!((boolean)(collect000))) {
                        {
                          collect000 = cons(prop, NIL);
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
                          collect000->rest = cons(prop, NIL);
                          collect000 = collect000->rest;
                        }
                      }
                    }
                  }
                }
                paginglist->theSequence = value000;
              }
              list = paginglist;
            }
          }
        }
        return (list);
      }
    }
  }
}

boolean allSpecializingDependentPropositionsNextP(AllPurposeIterator* self) {
  { Iterator* iterator = self->iteratorNestedIterator;
    NamedDescription* relation = ((NamedDescription*)(self->iteratorConsList->value));

    for (;;) {
      while (iterator->nextP()) {
        { Proposition* proposition = ((Proposition*)(iterator->value));

          if (((Surrogate*)(proposition->operatoR)) == relation->surrogateValueInverse) {
            self->value = proposition;
            return (TRUE);
          }
        }
      }
      self->iteratorConsList = self->iteratorConsList->rest;
      relation = ((NamedDescription*)(self->iteratorConsList->value));
      if (!((boolean)(relation))) {
        self->value = NULL;
        return (FALSE);
      }
      iterator = unfilteredDependentPropositions(self->iteratorObject, relation->surrogateValueInverse)->allocateIterator();
      self->iteratorNestedIterator = iterator;
    }
  }
}

Iterator* allSpecializingDependentPropositions(Object* self, Surrogate* relationref) {
  { NamedDescription* relation = getDescription(relationref);

    { AllPurposeIterator* self000 = newAllPurposeIterator();

      self000->iteratorObject = self;
      self000->iteratorConsList = cons(relation, allSubrelations(relation, FALSE));
      self000->iteratorNestedIterator = unfilteredDependentPropositions(self, relationref)->allocateIterator();
      self000->iteratorNextCode = ((cpp_function_code)(&allSpecializingDependentPropositionsNextP));
      { AllPurposeIterator* value000 = self000;

        return (value000);
      }
    }
  }
}

SequenceIndex* unfilteredDependentIsaPropositions(Object* self) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_BACKLINKS_LOGIC_LOGIC_OBJECT)) {
      { Object* self000 = self;
        LogicObject* self = ((LogicObject*)(self000));

        { BacklinksIndex* index = getBacklinksIndex(self);
          SequenceIndex* list = ((!((boolean)(index))) ? NIL_NON_PAGING_INDEX : ((SequenceIndex*)(index->dependentIsaPropositionsList)));

          if (!((boolean)(list))) {
            list = index->dependentPropositionsList;
            if (isaP(list, SGT_BACKLINKS_LOGIC_PAGING_INDEX)) {
              { ObjectStore* store = ((PagingIndex*)(list))->store;
                SequenceIndex* paginglist = (((boolean)(store)) ? createSequenceIndex(store, cons(KWD_BACKLINKS_ISA, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(self, NIL)))) : ((SequenceIndex*)(NULL)));

                if (((boolean)(paginglist))) {
                  { Cons* value000 = NIL;

                    { Proposition* prop = NULL;
                      Cons* iter000 = ((Cons*)(list->theSequence));
                      Cons* collect000 = NULL;

                      while (!(iter000 == NIL)) {
                        prop = ((Proposition*)(iter000->value));
                        iter000 = iter000->rest;
                        if (prop->kind == KWD_BACKLINKS_ISA) {
                          if (!((boolean)(collect000))) {
                            {
                              collect000 = cons(prop, NIL);
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
                              collect000->rest = cons(prop, NIL);
                              collect000 = collect000->rest;
                            }
                          }
                        }
                      }
                    }
                    paginglist->theSequence = value000;
                  }
                  list = paginglist;
                }
              }
            }
          }
          return (((SequenceIndex*)(list)));
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_BACKLINKS_STELLA_THING)) {
      { Object* self001 = self;
        Thing* self = ((Thing*)(self001));

        { BacklinksIndex* index = getBacklinksIndex(self);
          SequenceIndex* list = ((!((boolean)(index))) ? NIL_NON_PAGING_INDEX : ((SequenceIndex*)(index->dependentIsaPropositionsList)));

          if (!((boolean)(list))) {
            list = index->dependentPropositionsList;
            if (isaP(list, SGT_BACKLINKS_LOGIC_PAGING_INDEX)) {
              { ObjectStore* store = ((PagingIndex*)(list))->store;
                SequenceIndex* paginglist = (((boolean)(store)) ? createSequenceIndex(store, cons(KWD_BACKLINKS_ISA, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(self, NIL)))) : ((SequenceIndex*)(NULL)));

                if (((boolean)(paginglist))) {
                  { Cons* value001 = NIL;

                    { Proposition* prop = NULL;
                      Cons* iter001 = ((Cons*)(list->theSequence));
                      Cons* collect001 = NULL;

                      while (!(iter001 == NIL)) {
                        prop = ((Proposition*)(iter001->value));
                        iter001 = iter001->rest;
                        if (prop->kind == KWD_BACKLINKS_ISA) {
                          if (!((boolean)(collect001))) {
                            {
                              collect001 = cons(prop, NIL);
                              if (value001 == NIL) {
                                value001 = collect001;
                              }
                              else {
                                addConsToEndOfConsList(value001, collect001);
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
                    paginglist->theSequence = value001;
                  }
                  list = paginglist;
                }
              }
            }
          }
          return (((SequenceIndex*)(list)));
        }
      }
    }
    else {
      { BacklinksIndex* index = getBacklinksIndex(self);
        SequenceIndex* list = ((!((boolean)(index))) ? NIL_NON_PAGING_INDEX : ((SequenceIndex*)(index->dependentIsaPropositionsList)));

        if (((boolean)(list))) {
          return (((SequenceIndex*)(list)));
        }
        else {
          return (index->dependentPropositionsList);
        }
      }
    }
  }
}

SequenceIndex* unfilteredDependentImpliesPropositions(Object* self) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_BACKLINKS_LOGIC_LOGIC_OBJECT)) {
      { Object* self000 = self;
        LogicObject* self = ((LogicObject*)(self000));

        { BacklinksIndex* index = getBacklinksIndex(self);

          if (!((boolean)(index))) {
            return (NIL_NON_PAGING_INDEX);
          }
          else {
            { HashTable* table = index->predicatePropositionsTable;
              SequenceIndex* list = NULL;

              if (((boolean)(table))) {
                list = ((SequenceIndex*)(table->lookup(SGT_BACKLINKS_PL_KERNEL_KB_SUBSET_OF)));
                if (!((boolean)(list))) {
                  list = NIL_NON_PAGING_INDEX;
                }
              }
              if (!((boolean)(list))) {
                list = index->dependentPropositionsList;
                if (isaP(list, SGT_BACKLINKS_LOGIC_PAGING_INDEX)) {
                  { ObjectStore* store = ((PagingIndex*)(list))->store;
                    SequenceIndex* paginglist = (((boolean)(store)) ? createSequenceIndex(store, cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(SGT_BACKLINKS_PL_KERNEL_KB_SUBSET_OF, cons(self, NIL))))) : ((SequenceIndex*)(NULL)));

                    if (((boolean)(paginglist))) {
                      { Cons* value000 = NIL;

                        { Proposition* prop = NULL;
                          Cons* iter000 = ((Cons*)(list->theSequence));
                          Cons* collect000 = NULL;

                          while (!(iter000 == NIL)) {
                            prop = ((Proposition*)(iter000->value));
                            iter000 = iter000->rest;
                            if (prop->operatoR == SGT_BACKLINKS_PL_KERNEL_KB_SUBSET_OF) {
                              if (!((boolean)(collect000))) {
                                {
                                  collect000 = cons(prop, NIL);
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
                                  collect000->rest = cons(prop, NIL);
                                  collect000 = collect000->rest;
                                }
                              }
                            }
                          }
                        }
                        paginglist->theSequence = value000;
                      }
                      list = paginglist;
                    }
                  }
                }
              }
              return (list);
            }
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_BACKLINKS_STELLA_THING)) {
      { Object* self001 = self;
        Thing* self = ((Thing*)(self001));

        { BacklinksIndex* index = getBacklinksIndex(self);

          if (!((boolean)(index))) {
            return (NIL_NON_PAGING_INDEX);
          }
          else {
            { HashTable* table = index->predicatePropositionsTable;
              SequenceIndex* list = NULL;

              if (((boolean)(table))) {
                list = ((SequenceIndex*)(table->lookup(SGT_BACKLINKS_PL_KERNEL_KB_SUBSET_OF)));
                if (!((boolean)(list))) {
                  list = NIL_NON_PAGING_INDEX;
                }
              }
              if (!((boolean)(list))) {
                list = index->dependentPropositionsList;
                if (isaP(list, SGT_BACKLINKS_LOGIC_PAGING_INDEX)) {
                  { ObjectStore* store = ((PagingIndex*)(list))->store;
                    SequenceIndex* paginglist = (((boolean)(store)) ? createSequenceIndex(store, cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(SGT_BACKLINKS_PL_KERNEL_KB_SUBSET_OF, cons(self, NIL))))) : ((SequenceIndex*)(NULL)));

                    if (((boolean)(paginglist))) {
                      { Cons* value001 = NIL;

                        { Proposition* prop = NULL;
                          Cons* iter001 = ((Cons*)(list->theSequence));
                          Cons* collect001 = NULL;

                          while (!(iter001 == NIL)) {
                            prop = ((Proposition*)(iter001->value));
                            iter001 = iter001->rest;
                            if (prop->operatoR == SGT_BACKLINKS_PL_KERNEL_KB_SUBSET_OF) {
                              if (!((boolean)(collect001))) {
                                {
                                  collect001 = cons(prop, NIL);
                                  if (value001 == NIL) {
                                    value001 = collect001;
                                  }
                                  else {
                                    addConsToEndOfConsList(value001, collect001);
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
                        paginglist->theSequence = value001;
                      }
                      list = paginglist;
                    }
                  }
                }
              }
              return (list);
            }
          }
        }
      }
    }
    else {
      { BacklinksIndex* index = getBacklinksIndex(self);

        if (!((boolean)(index))) {
          return (NIL_NON_PAGING_INDEX);
        }
        else {
          { HashTable* table = index->predicatePropositionsTable;

            if (((boolean)(table))) {
              { SequenceIndex* temp000 = ((SequenceIndex*)(table->lookup(SGT_BACKLINKS_PL_KERNEL_KB_SUBSET_OF)));

                { SequenceIndex* value002 = (((boolean)(temp000)) ? ((SequenceIndex*)(temp000)) : NIL_NON_PAGING_INDEX);

                  return (((SequenceIndex*)(value002)));
                }
              }
            }
            else {
              return (index->dependentPropositionsList);
            }
          }
        }
      }
    }
  }
}

boolean inheritsTruthFromMasterP(Proposition* self) {
  { Proposition* master = ((Proposition*)(dynamicSlotValue(self->dynamicSlots, SYM_BACKLINKS_LOGIC_MASTER_PROPOSITION, NULL)));

    if (((boolean)(master)) &&
        trueP(master)) {
      assignTruthValue(self, TRUE_WRAPPER);
      return (TRUE);
    }
  }
  return (FALSE);
}

Cons* applicableRulesOfDescription(LogicObject* self, Keyword* direction, boolean truerulesonlyP) {
  if (isaP(self, SGT_BACKLINKS_LOGIC_DESCRIPTION)) {
    deriveDeferredSatelliteRules(((Description*)(self)));
  }
  { Cons* rules = NIL;

    { Proposition* p = NULL;
      Iterator* iter000 = selectRulePropositions(makeRulesPattern(((direction == KWD_BACKLINKS_FORWARD) ? NULL : self), ((direction == KWD_BACKLINKS_FORWARD) ? self : NULL)))->allocateIterator();
      Cons* collect000 = NULL;

      while (iter000->nextP()) {
        p = ((Proposition*)(iter000->value));
        if ((trueP(p) &&
            (!((BooleanWrapper*)(dynamicSlotValue(p->dynamicSlots, SYM_BACKLINKS_LOGIC_SUBSUMPTION_LINKp, FALSE_WRAPPER)))->wrapperValue)) ||
            (inheritsTruthFromMasterP(p) ||
             (!truerulesonlyP))) {
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(p, NIL);
              if (rules == NIL) {
                rules = collect000;
              }
              else {
                addConsToEndOfConsList(rules, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(p, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    return (rules);
  }
}

Cons* makeSelectionPattern(Keyword* kind, Cons* options, Cons* arguments) {
  return (cons(kind, cons(((!((boolean)(options))) ? NIL : options), arguments)));
}

Keyword* patternKind(Cons* pattern) {
  return (((Keyword*)(pattern->value)));
}

Cons* patternOptions(Cons* pattern) {
  return (((Cons*)(pattern->rest->value)));
}

Cons* patternArguments(Cons* pattern) {
  return (pattern->rest->rest);
}

Cons* makeDependentPropositionsPattern(Object* argument) {
  return (cons(KWD_BACKLINKS_DEPENDENTS, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(argument, NIL))));
}

Cons* makeIsaPattern(Object* argument) {
  return (cons(KWD_BACKLINKS_ISA, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(argument, NIL))));
}

Cons* makeRelationExtensionPattern(Surrogate* relation) {
  return (cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(relation, NIL))));
}

Cons* makeRelationPattern(Surrogate* relation, Object* argument) {
  return (cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(relation, cons(argument, NIL)))));
}

Cons* makeRelationPattern1(Surrogate* relation, Object* argument) {
  return (makeRelationPattern2(relation, argument, NULL));
}

Cons* makeRelationPattern2(Surrogate* relation, Object* argument1, Object* argument2) {
  return (cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(relation, cons(argument1, cons(argument2, NIL))))));
}

Cons* makeRelationPattern3(Surrogate* relation, Object* argument1, Object* argument2, Object* argument3) {
  return (cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(relation, cons(argument1, cons(argument2, cons(argument3, NIL)))))));
}

Cons* makeRelationPattern4(Surrogate* relation, Object* argument1, Object* argument2, Object* argument3, Object* argument4) {
  return (cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(relation, cons(argument1, cons(argument2, cons(argument3, cons(argument4, NIL))))))));
}

Cons* makeRelationPatternN(Surrogate* relation, int arguments, ...) {
  { Cons* arglist000 = NIL;

    { Object* arg000 = NULL;
      va_list iter000;
      int iter000Count = arguments;
      Cons* collect000 = NULL;

      va_start(iter000, arguments);
      while ((iter000Count--) > 0) {
        arg000 = va_arg(iter000, Object*);
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(arg000, NIL);
            if (arglist000 == NIL) {
              arglist000 = collect000;
            }
            else {
              addConsToEndOfConsList(arglist000, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(arg000, NIL);
            collect000 = collect000->rest;
          }
        }
      }
      va_end(iter000);
    }
    { Cons* value000 = cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(relation, arglist000)));

      return (value000);
    }
  }
}

Cons* makeRulesPattern(Object* posrelation, Object* negrelation) {
  return (cons(KWD_BACKLINKS_RULES, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(posrelation, cons(negrelation, NIL)))));
}

LogicObject* findSelectionKeyWithEquivalents(Cons* pattern) {
  { Cons* candidatekeys = pattern->rest->rest;

    { Keyword* testValue000 = ((Keyword*)(pattern->value));

      if ((testValue000 == KWD_BACKLINKS_DEPENDENTS) ||
          (testValue000 == KWD_BACKLINKS_ISA)) {
      }
      else if (testValue000 == KWD_BACKLINKS_RELATION) {
        candidatekeys = candidatekeys->rest;
      }
      else if ((testValue000 == KWD_BACKLINKS_CONTEXT_PROPOSITIONS) ||
          (testValue000 == KWD_BACKLINKS_CONTEXT_INSTANCES)) {
        candidatekeys = candidatekeys->rest;
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "get-selection-key-equivalents: Can't yet handle pattern " << "`" << pattern << "'";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    { Object* key = NULL;
      Cons* iter000 = candidatekeys;

      while (!(iter000 == NIL)) {
        key = iter000->value;
        iter000 = iter000->rest;
        if (subtypeOfP(safePrimaryType(key), SGT_BACKLINKS_LOGIC_LOGIC_OBJECT)) {
          { Object* key000 = key;
            LogicObject* key = ((LogicObject*)(key000));

            if (!(key->variableValueInverse_reader() == NIL)) {
              return (key);
            }
          }
        }
        else {
        }
      }
    }
    return (NULL);
  }
}

SequenceIndex* selectPropositions(Cons* pattern) {
  { Keyword* kind = ((Keyword*)(pattern->value));
    Cons* arguments = pattern->rest->rest;

    if (kind == KWD_BACKLINKS_DEPENDENTS) {
      return (unfilteredDependentPropositions(arguments->value, NULL));
    }
    else if (kind == KWD_BACKLINKS_ISA) {
      return (selectIsaPropositions(pattern));
    }
    else if (kind == KWD_BACKLINKS_RELATION) {
      return (selectRelationPropositions(pattern));
    }
    else if (kind == KWD_BACKLINKS_RULES) {
      return (selectRulePropositions(pattern));
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "select-propositions: Can't yet handle pattern " << "`" << pattern << "'";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

SequenceIndex* selectIsaPropositions(Cons* pattern) {
  { Object* object = pattern->rest->rest->value;
    SequenceIndex* index = unfilteredDependentIsaPropositions(object);

    if (subtypeOfP(safePrimaryType(index), SGT_BACKLINKS_LOGIC_PAGING_INDEX)) {
      { SequenceIndex* index000 = index;
        PagingIndex* index = ((PagingIndex*)(index000));

        if (((Keyword*)(index->selectionPattern->value)) == KWD_BACKLINKS_ISA) {
          return (index);
        }
      }
    }
    else {
    }
    { Cons* sequence = index->theSequence;
      Cons* filteredsequence = NIL;

      if (sequence == NIL) {
        return (NIL_NON_PAGING_INDEX);
      }
      { Proposition* prop = NULL;
        Cons* iter000 = sequence;

        while (!(iter000 == NIL)) {
          prop = ((Proposition*)(iter000->value));
          iter000 = iter000->rest;
          if ((prop->kind == KWD_BACKLINKS_ISA) &&
              (!prop->deletedP())) {
            filteredsequence = cons(prop, filteredsequence);
          }
        }
      }
      if (filteredsequence == NIL) {
        return (NIL_NON_PAGING_INDEX);
      }
      else {
        { NonPagingIndex* self000 = newNonPagingIndex();

          self000->theSequence = filteredsequence;
          { NonPagingIndex* value000 = self000;

            return (value000);
          }
        }
      }
    }
  }
}

SequenceIndex* selectRelationPropositions(Cons* pattern) {
  { Cons* arguments = pattern->rest->rest;
    Object* relation = arguments->value;
    Cons* keys = arguments->rest;

    { Object* value000 = NULL;

      { Object* key = NULL;
        Cons* iter000 = keys;

        while (!(iter000 == NIL)) {
          key = iter000->value;
          iter000 = iter000->rest;
          if (((boolean)(key)) &&
              instanceHasBacklinksP(key)) {
            value000 = key;
            break;
          }
        }
      }
      { Object* anchor = value000;

        if (!((boolean)(anchor))) {
          { NamedDescription* description = getDescription(relation);

            if (((boolean)(description))) {
              return (getDescriptionExtension(description, TRUE));
            }
            else {
              return (NIL_NON_PAGING_INDEX);
            }
          }
        }
        { SequenceIndex* index = unfilteredDependentPropositions(anchor, ((Surrogate*)(relation)));
          Cons* sequence = index->theSequence;
          Cons* filteredsequence = NIL;

          if (subtypeOfP(safePrimaryType(index), SGT_BACKLINKS_LOGIC_PAGING_INDEX)) {
            { SequenceIndex* index000 = index;
              PagingIndex* index = ((PagingIndex*)(index000));

              if (((boolean)(index->store)) &&
                  (((Keyword*)(index->selectionPattern->value)) == KWD_BACKLINKS_RELATION)) {
                index->selectionPattern = pattern;
                return (index);
              }
            }
          }
          else {
          }
          if (sequence == NIL) {
            return (NIL_NON_PAGING_INDEX);
          }
          { Proposition* prop = NULL;
            Cons* iter001 = sequence;

            while (!(iter001 == NIL)) {
              prop = ((Proposition*)(iter001->value));
              iter001 = iter001->rest;
              { boolean testValue000 = FALSE;

                testValue000 = equalP(relation, prop->operatoR);
                if (testValue000) {
                  testValue000 = !prop->deletedP();
                  if (testValue000) {
                    if (keys->rest == NIL) {
                      testValue000 = TRUE;
                    }
                    else {
                      { boolean alwaysP000 = TRUE;

                        { Object* key = NULL;
                          Object* arg = NULL;
                          Cons* iter002 = keys;
                          Vector* vector000 = prop->arguments;
                          int index001 = 0;
                          int length000 = vector000->length();

                          while ((!(iter002 == NIL)) &&
                              (index001 < length000)) {
                            key = iter002->value;
                            iter002 = iter002->rest;
                            arg = (vector000->theArray)[index001];
                            index001 = index001 + 1;
                            if (!((!((boolean)(key))) ||
                                (equalP(valueOf(key), valueOf(arg)) ||
                                 (isaP(valueOf(key), SGT_BACKLINKS_LOGIC_PROPOSITION) &&
                                  (isaP(valueOf(arg), SGT_BACKLINKS_LOGIC_PROPOSITION) &&
                                   unifyPropositionsP(((Proposition*)(valueOf(key))), ((Proposition*)(valueOf(arg))), newKeyValueList())))))) {
                              alwaysP000 = FALSE;
                              break;
                            }
                          }
                        }
                        testValue000 = alwaysP000;
                      }
                    }
                  }
                }
                if (testValue000) {
                  filteredsequence = cons(prop, filteredsequence);
                }
              }
            }
          }
          if (filteredsequence == NIL) {
            return (NIL_NON_PAGING_INDEX);
          }
          else {
            { NonPagingIndex* self001 = newNonPagingIndex();

              self001->theSequence = filteredsequence->reverse();
              { NonPagingIndex* value001 = self001;

                return (value001);
              }
            }
          }
        }
      }
    }
  }
}

SequenceIndex* selectRulePropositions(Cons* pattern) {
  { Cons* arguments = pattern->rest->rest;
    Object* posrelation = arguments->value;
    Object* negrelation = arguments->rest->value;
    Description* description = NULL;
    ObjectStore* store = NULL;

    if (((boolean)(posrelation))) {
      if (subtypeOfP(safePrimaryType(posrelation), SGT_BACKLINKS_LOGIC_DESCRIPTION)) {
        { Object* posrelation000 = posrelation;
          Description* posrelation = ((Description*)(posrelation000));

          description = posrelation;
        }
      }
      else {
        description = getDescription(posrelation);
      }
      negrelation = NULL;
    }
    if (((boolean)(negrelation))) {
      if (subtypeOfP(safePrimaryType(negrelation), SGT_BACKLINKS_LOGIC_DESCRIPTION)) {
        { Object* negrelation000 = negrelation;
          Description* negrelation = ((Description*)(negrelation000));

          description = negrelation;
        }
      }
      else {
        description = getDescription(negrelation);
      }
    }
    if (((boolean)(description))) {
      deriveDeferredSatelliteRules(description);
      store = homeObjectStore(description);
    }
    if (((boolean)(store))) {
      return (createSequenceIndex(store, pattern));
    }
    else {
      if (((boolean)(description))) {
        return (selectRelationPropositions(makeRelationPattern2(SGT_BACKLINKS_PL_KERNEL_KB_SUBSET_OF, negrelation, posrelation)));
      }
      else {
        return (NIL_NON_PAGING_INDEX);
      }
    }
  }
}

TruthValue* evaluateSelectionPattern(Cons* pattern) {
  pattern = makeSelectionPattern(((Keyword*)(pattern->value)), listO(3, KWD_BACKLINKS_EVALUATEp, SYM_BACKLINKS_STELLA_TRUE, ((Cons*)(pattern->rest->value))->concatenate(NIL, 0)), pattern->rest->rest);
  { Proposition* proposition = NULL;
    Iterator* iter000 = selectPropositions(pattern)->allocateIterator();

    while (iter000->nextP()) {
      proposition = ((Proposition*)(iter000->value));
      if (!unknownTruthValueP(((TruthValue*)(accessInContext(proposition->truthValue, proposition->homeContext, FALSE))))) {
        return (((TruthValue*)(accessInContext(proposition->truthValue, proposition->homeContext, FALSE))));
      }
    }
  }
  return (UNKNOWN_TRUTH_VALUE);
}

boolean evaluationSelectionPatternP(Cons* pattern) {
  { Cons* options = ((Cons*)(pattern->rest->value));

    while (!(options == NIL)) {
      if ((options->value == KWD_BACKLINKS_EVALUATEp) &&
          (coerceToBoolean(options->rest->value) == TRUE_WRAPPER)) {
        return (TRUE);
      }
      options = options->rest->rest;
    }
    return (FALSE);
  }
}

boolean argumentDiscouragesBacklinksP(Object* self) {
  return (FALSE);
}

void surrogatifyDiscouragedArguments(Proposition* self) {
}

int countBacklinksOnRelation(Object* self, Keyword* kind, Surrogate* relation) {
  { BacklinksIndex* index = getBacklinksIndex(self);
    Cons* equivalents = (isaP(self, SGT_BACKLINKS_LOGIC_LOGIC_OBJECT) ? ((LogicObject*)(self))->variableValueInverse_reader() : NIL);
    int count = 0;

    if (!((boolean)(index))) {
      return (NULL_INTEGER);
    }
    count = selectPropositions(cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(relation, cons(self, NIL)))))->estimatedLength();
    if ((count == 0) &&
        (!(allDirectSubrelations(surrogateToDescription(relation), FALSE) == NIL))) {
      count = 1;
    }
    { Object* equiv = NULL;
      Cons* iter000 = equivalents;

      while (!(iter000 == NIL)) {
        equiv = iter000->value;
        iter000 = iter000->rest;
        count = count + countBacklinksOnRelation(equiv, kind, relation);
      }
    }
    return (count);
  }
}

Object* selectArgumentWithBacklinks(Proposition* proposition, boolean& _Return1) {
  { Surrogate* relation = ((Surrogate*)(proposition->operatoR));
    Keyword* kind = proposition->kind;
    Object* value = NULL;
    int count = NULL_INTEGER;
    int lowestbacklinkcount = NULL_INTEGER;
    Object* bestargument = NULL;
    boolean founddiscouragedargumentP = FALSE;

    { Object* arg = NULL;
      Vector* vector000 = proposition->arguments;
      int index000 = 0;
      int length000 = vector000->length();

      while (index000 < length000) {
        arg = (vector000->theArray)[index000];
        index000 = index000 + 1;
        value = argumentBoundTo(arg);
        if (((boolean)(value))) {
          if (FALSE) {
            founddiscouragedargumentP = TRUE;
            continue;
          }
          count = countBacklinksOnRelation(value, kind, relation);
          if ((count != NULL_INTEGER) &&
              ((lowestbacklinkcount == NULL_INTEGER) ||
               (count < lowestbacklinkcount))) {
            lowestbacklinkcount = count;
            bestargument = value;
          }
        }
      }
    }
    if ((lowestbacklinkcount == NULL_INTEGER) &&
        founddiscouragedargumentP) {
      { Object* arg = NULL;
        Vector* vector001 = proposition->arguments;
        int index001 = 0;
        int length001 = vector001->length();

        while (index001 < length001) {
          arg = (vector001->theArray)[index001];
          index001 = index001 + 1;
          value = argumentBoundTo(arg);
          if (((boolean)(value))) {
            if (!FALSE) {
              continue;
            }
            count = countBacklinksOnRelation(value, kind, relation);
            if ((count != NULL_INTEGER) &&
                ((lowestbacklinkcount == NULL_INTEGER) ||
                 (count < lowestbacklinkcount))) {
              lowestbacklinkcount = count;
              bestargument = value;
            }
          }
        }
      }
    }
    if (lowestbacklinkcount == NULL_INTEGER) {
      _Return1 = FALSE;
      return (NULL);
    }
    else {
      _Return1 = FALSE;
      return (bestargument);
    }
  }
}

boolean instanceHasBacklinksP(Object* self) {
  return (((boolean)(getBacklinksIndex(self))) ||
      isaP(self, SGT_BACKLINKS_LOGIC_PROPOSITION));
}

Object* selectInstanceWithBacklinks(Cons* instances, Surrogate* relation) {
  relation = relation;
  { Object* i = NULL;
    Cons* iter000 = instances;

    while (!(iter000 == NIL)) {
      i = iter000->value;
      iter000 = iter000->rest;
      if (((boolean)(i)) &&
          (!FALSE)) {
        { Object* value = valueOf(i);

          if (instanceHasBacklinksP(value)) {
            return (value);
          }
        }
      }
    }
  }
  { Object* i = NULL;
    Cons* iter001 = instances;

    while (!(iter001 == NIL)) {
      i = iter001->value;
      iter001 = iter001->rest;
      if (((boolean)(i)) &&
          FALSE) {
        { Object* value = valueOf(i);

          if (instanceHasBacklinksP(value)) {
            return (value);
          }
        }
      }
    }
  }
  return (NULL);
}

SequenceIndex* findSimilarPropositions(Proposition* self) {
  if (self->kind == KWD_BACKLINKS_FUNCTION) {
    { Object* arg = NULL;
      Iterator* iter000 = self->arguments->butLast();

      while (iter000->nextP()) {
        arg = iter000->value;
        if (instanceHasBacklinksP(valueOf(arg))) {
          return (unfilteredDependentPropositions(valueOf(arg), ((Surrogate*)(self->operatoR))));
        }
      }
    }
  }
  else {
    { Object* arg = NULL;
      Vector* vector000 = self->arguments;
      int index000 = 0;
      int length000 = vector000->length();

      while (index000 < length000) {
        arg = (vector000->theArray)[index000];
        index000 = index000 + 1;
        if (instanceHasBacklinksP(arg)) {
          return (unfilteredDependentPropositions(arg, ((Surrogate*)(self->operatoR))));
        }
      }
    }
  }
  rewrapPropositionArguments(self);
  { Object* arg = NULL;
    Vector* vector001 = self->arguments;
    int index001 = 0;
    int length001 = vector001->length();

    while (index001 < length001) {
      arg = (vector001->theArray)[index001];
      index001 = index001 + 1;
      if (((boolean)(arg)) &&
          instanceHasBacklinksP(arg)) {
        return (unfilteredDependentPropositions(arg, ((Surrogate*)(self->operatoR))));
      }
    }
  }
  return (NIL_NON_PAGING_INDEX);
}

Proposition* findMatchingConceivedProposition(Proposition* goal) {
  { boolean dummy1;

    { Keyword* testValue000 = goal->kind;

      if ((testValue000 == KWD_BACKLINKS_PREDICATE) ||
          ((testValue000 == KWD_BACKLINKS_FUNCTION) ||
           ((testValue000 == KWD_BACKLINKS_ISA) ||
            (testValue000 == KWD_BACKLINKS_EQUIVALENT)))) {
        { Object* backlinkedargument = selectArgumentWithBacklinks(goal, dummy1);

          if (!((boolean)(backlinkedargument))) {
            return (NULL);
          }
          { Proposition* value000 = NULL;

            { Proposition* p = NULL;
              Iterator* iter000 = unfilteredDependentPropositions(backlinkedargument, ((Surrogate*)(goal->operatoR)))->allocateIterator();

              while (iter000->nextP()) {
                p = ((Proposition*)(iter000->value));
                if ((((Surrogate*)(p->operatoR)) == goal->operatoR) &&
                    argumentsMatchArgumentsP(p, goal)) {
                  value000 = p;
                  break;
                }
              }
            }
            { Proposition* value001 = value000;

              return (value001);
            }
          }
        }
      }
      else {
        return (goal);
      }
    }
  }
}

void transferPropositionsAndBacklinks(Object* from, Object* to) {
  transferPropositionsExceptFor(from, to, NIL_LIST);
}

void transferPropositionsExceptFor(Object* from, Object* to, List* exceptpropositions) {
  if (oLOADINGREGENERABLEOBJECTSpo.get()) {
    return;
  }
  { Cons* value000 = NIL;

    { Proposition* p = NULL;
      Iterator* iter000 = unfilteredDependentPropositions(to, NULL)->allocateIterator();
      Cons* collect000 = NULL;

      while (iter000->nextP()) {
        p = ((Proposition*)(iter000->value));
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(p, NIL);
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
            collect000->rest = cons(p, NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    { Cons* topropositions = value000;

      if (!((boolean)(exceptpropositions))) {
        exceptpropositions = NIL_LIST;
      }
      { Proposition* p = NULL;
        Iterator* iter001 = unfilteredDependentPropositions(from, NULL)->allocateIterator();

        while (iter001->nextP()) {
          p = ((Proposition*)(iter001->value));
          if (!exceptpropositions->memberP(p)) {
            { Object* arg = NULL;
              int i = NULL_INTEGER;
              Vector* vector000 = p->arguments;
              int index000 = 0;
              int length000 = vector000->length();
              int iter002 = 0;

              while (index000 < length000) {
                arg = (vector000->theArray)[index000];
                index000 = index000 + 1;
                i = iter002;
                iter002 = iter002 + 1;
                if (eqlP(arg, from)) {
                  (p->arguments->theArray)[i] = to;
                }
              }
            }
            { boolean testValue000 = FALSE;

              { boolean foundP000 = FALSE;

                { Object* top = NULL;
                  Cons* iter003 = topropositions;

                  while (!(iter003 == NIL)) {
                    top = iter003->value;
                    iter003 = iter003->rest;
                    if (equivalentPropositionsP(p, ((Proposition*)(top)), NULL)) {
                      foundP000 = TRUE;
                      break;
                    }
                  }
                }
                testValue000 = foundP000;
              }
              testValue000 = !testValue000;
              if (testValue000) {
                removeDependentPropositionLink(from, p);
                addDependentPropositionLink(to, p);
              }
            }
          }
        }
      }
    }
  }
}

void transferDescriptionExtension(NamedDescription* from, NamedDescription* to) {
  to->extension = from->extension;
  from->extension = NULL;
}

SequenceIndex* getDescriptionExtension(NamedDescription* description, boolean updateP) {
  { SequenceIndex* extension = description->extension;

    if (((boolean)(extension)) &&
        (!(extension == NIL_PAGING_INDEX))) {
      return (extension);
    }
    else if (updateP) {
      extension = createSequenceIndex(KWD_BACKLINKS_PAGING, cons(KWD_BACKLINKS_RELATION, cons(((!((boolean)(NIL))) ? NIL : NIL), cons(description->surrogateValueInverse, NIL))));
      description->extension = extension;
      return (extension);
    }
    else {
      return (NIL_PAGING_INDEX);
    }
  }
}

void cleanupDescriptionExtension(NamedDescription* description) {
  description->extension->removeDeletedMembers();
}

void cleanupAllDescriptionExtensions() {
  { NamedDescription* description = NULL;
    Iterator* iter000 = allNamedDescriptions(NULL, FALSE);

    while (iter000->nextP()) {
      description = ((NamedDescription*)(iter000->value));
      if (((boolean)(description->extension)) &&
          (!(description->extension == NIL_PAGING_INDEX))) {
        description->extension->removeDeletedMembers();
      }
    }
  }
}

// Used when creating a skolem (e.g., a prototype) that
// isn't visible in the corresponding class extension.
DEFINE_STELLA_SPECIAL(oSUPPRESSINSERTIONINTOCLASSEXTENSIONpo, boolean , FALSE);

void updateDescriptionExtension(Proposition* self) {
  if (descriptionModeP()) {
    return;
  }
  { Keyword* testValue000 = self->kind;

    if ((testValue000 == KWD_BACKLINKS_ISA) ||
        ((testValue000 == KWD_BACKLINKS_PREDICATE) ||
         (testValue000 == KWD_BACKLINKS_FUNCTION))) {
      { NamedDescription* description = getDescription(((Surrogate*)(self->operatoR)));

        { Object* arg = NULL;
          Vector* vector000 = self->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          while (index000 < length000) {
            arg = (vector000->theArray)[index000];
            index000 = index000 + 1;
            { Surrogate* testValue001 = safePrimaryType(arg);

              if (subtypeOfP(testValue001, SGT_BACKLINKS_LOGIC_PATTERN_VARIABLE)) {
                { Object* arg000 = arg;
                  PatternVariable* arg = ((PatternVariable*)(arg000));

                  return;
                }
              }
              else if (subtypeOfP(testValue001, SGT_BACKLINKS_LOGIC_SKOLEM)) {
                { Object* arg001 = arg;
                  Skolem* arg = ((Skolem*)(arg001));

                  if ((classDescriptionP(description) &&
                      literalTypeP(description->surrogateValueInverse)) ||
                      (oSUPPRESSINSERTIONINTOCLASSEXTENSIONpo.get() ||
                       ((BooleanWrapper*)(dynamicSlotValue(arg->dynamicSlots, SYM_BACKLINKS_LOGIC_HYPOTHESIZED_INSTANCEp, FALSE_WRAPPER)))->wrapperValue)) {
                    return;
                  }
                }
              }
              else if (subtypeOfP(testValue001, SGT_BACKLINKS_LOGIC_LOGIC_OBJECT)) {
                { Object* arg002 = arg;
                  LogicObject* arg = ((LogicObject*)(arg002));

                  if (((BooleanWrapper*)(dynamicSlotValue(arg->dynamicSlots, SYM_BACKLINKS_LOGIC_HYPOTHESIZED_INSTANCEp, FALSE_WRAPPER)))->wrapperValue) {
                    return;
                  }
                }
              }
              else {
              }
            }
          }
        }
        { SequenceIndex* extension = getDescriptionExtension(description, TRUE);

          if (!oLOADINGREGENERABLEOBJECTSpo.get()) {
            extension->insert(self);
          }
        }
      }
    }
    else {
    }
  }
}

Iterator* allExtensionMembers(NamedDescription* description) {
  { SequenceIndex* extension = getDescriptionExtension(description, TRUE);

    extension->removeDeletedMembers();
    return (extension->allocateIterator());
  }
}

boolean collectionImpliesCollectionP(LogicObject* subcollection, LogicObject* supercollection) {
  if (subcollection == supercollection) {
    return (TRUE);
  }
  else {
    return (allSupercollections(subcollection)->memberP(supercollection));
  }
}

boolean relationImpliesRelationP(NamedDescription* subrel, NamedDescription* superrel) {
  return (collectionImpliesCollectionP(subrel, superrel));
}

boolean descriptionImpliesDescriptionP(Description* subdesc, Description* superdesc) {
  return (collectionImpliesCollectionP(subdesc, superdesc));
}

boolean relationrefSpecializesRelationrefP(Surrogate* relationref1, Surrogate* relationref2) {
  if (relationref1 == relationref2) {
    return (TRUE);
  }
  { NamedDescription* desc1 = surrogateToDescription(relationref1);
    NamedDescription* desc2 = surrogateToDescription(relationref2);

    return (((boolean)(desc1)) &&
        (((boolean)(desc2)) &&
         collectionImpliesCollectionP(desc1, desc2)));
  }
}

void helpStartupBacklinks1() {
  {
    SGT_BACKLINKS_LOGIC_PATTERN_VARIABLE = ((Surrogate*)(internRigidSymbolWrtModule("PATTERN-VARIABLE", NULL, 1)));
    KWD_BACKLINKS_NON_PAGING = ((Keyword*)(internRigidSymbolWrtModule("NON-PAGING", NULL, 2)));
    KWD_BACKLINKS_DEPENDENTS = ((Keyword*)(internRigidSymbolWrtModule("DEPENDENTS", NULL, 2)));
    SGT_BACKLINKS_LOGIC_LOGIC_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("LOGIC-OBJECT", NULL, 1)));
    SGT_BACKLINKS_STELLA_THING = ((Surrogate*)(internRigidSymbolWrtModule("THING", getStellaModule("/STELLA", TRUE), 1)));
    SYM_BACKLINKS_LOGIC_DEPENDENT_PROPOSITIONS_INDEX = ((Symbol*)(internRigidSymbolWrtModule("DEPENDENT-PROPOSITIONS-INDEX", NULL, 0)));
    SGT_BACKLINKS_LOGIC_INTEGER_LOGIC_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("INTEGER-LOGIC-WRAPPER", NULL, 1)));
    SGT_BACKLINKS_LOGIC_FLOAT_LOGIC_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("FLOAT-LOGIC-WRAPPER", NULL, 1)));
    SGT_BACKLINKS_LOGIC_STRING_LOGIC_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("STRING-LOGIC-WRAPPER", NULL, 1)));
    KWD_BACKLINKS_ISA = ((Keyword*)(internRigidSymbolWrtModule("ISA", NULL, 2)));
    KWD_BACKLINKS_RELATION = ((Keyword*)(internRigidSymbolWrtModule("RELATION", NULL, 2)));
    SGT_BACKLINKS_LOGIC_PROPOSITION = ((Surrogate*)(internRigidSymbolWrtModule("PROPOSITION", NULL, 1)));
    KWD_BACKLINKS_CONSTANT = ((Keyword*)(internRigidSymbolWrtModule("CONSTANT", NULL, 2)));
    SGT_BACKLINKS_LOGIC_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 1)));
    SYM_BACKLINKS_LOGIC_COMPLEMENT_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("COMPLEMENT-DESCRIPTION", NULL, 0)));
    SGT_BACKLINKS_LOGIC_SKOLEM = ((Surrogate*)(internRigidSymbolWrtModule("SKOLEM", NULL, 1)));
    SGT_BACKLINKS_LOGIC_NON_PAGING_INDEX = ((Surrogate*)(internRigidSymbolWrtModule("NON-PAGING-INDEX", NULL, 1)));
    SGT_BACKLINKS_STELLA_INTEGER = ((Surrogate*)(internRigidSymbolWrtModule("INTEGER", getStellaModule("/STELLA", TRUE), 1)));
    SGT_BACKLINKS_STELLA_FLOAT = ((Surrogate*)(internRigidSymbolWrtModule("FLOAT", getStellaModule("/STELLA", TRUE), 1)));
    SGT_BACKLINKS_STELLA_STRING = ((Surrogate*)(internRigidSymbolWrtModule("STRING", getStellaModule("/STELLA", TRUE), 1)));
    SGT_BACKLINKS_STELLA_LITERAL_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("LITERAL-WRAPPER", getStellaModule("/STELLA", TRUE), 1)));
    SGT_BACKLINKS_LOGIC_PAGING_INDEX = ((Surrogate*)(internRigidSymbolWrtModule("PAGING-INDEX", NULL, 1)));
    SGT_BACKLINKS_PL_KERNEL_KB_SUBSET_OF = ((Surrogate*)(internRigidSymbolWrtModule("SUBSET-OF", getStellaModule("/PL-KERNEL-KB", TRUE), 1)));
    SYM_BACKLINKS_LOGIC_MASTER_PROPOSITION = ((Symbol*)(internRigidSymbolWrtModule("MASTER-PROPOSITION", NULL, 0)));
    KWD_BACKLINKS_FORWARD = ((Keyword*)(internRigidSymbolWrtModule("FORWARD", NULL, 2)));
    SYM_BACKLINKS_LOGIC_SUBSUMPTION_LINKp = ((Symbol*)(internRigidSymbolWrtModule("SUBSUMPTION-LINK?", NULL, 0)));
    KWD_BACKLINKS_RULES = ((Keyword*)(internRigidSymbolWrtModule("RULES", NULL, 2)));
    KWD_BACKLINKS_CONTEXT_PROPOSITIONS = ((Keyword*)(internRigidSymbolWrtModule("CONTEXT-PROPOSITIONS", NULL, 2)));
    KWD_BACKLINKS_CONTEXT_INSTANCES = ((Keyword*)(internRigidSymbolWrtModule("CONTEXT-INSTANCES", NULL, 2)));
    KWD_BACKLINKS_EVALUATEp = ((Keyword*)(internRigidSymbolWrtModule("EVALUATE?", NULL, 2)));
    SYM_BACKLINKS_STELLA_TRUE = ((Symbol*)(internRigidSymbolWrtModule("TRUE", getStellaModule("/STELLA", TRUE), 0)));
    KWD_BACKLINKS_FUNCTION = ((Keyword*)(internRigidSymbolWrtModule("FUNCTION", NULL, 2)));
    KWD_BACKLINKS_PREDICATE = ((Keyword*)(internRigidSymbolWrtModule("PREDICATE", NULL, 2)));
    KWD_BACKLINKS_EQUIVALENT = ((Keyword*)(internRigidSymbolWrtModule("EQUIVALENT", NULL, 2)));
    KWD_BACKLINKS_PAGING = ((Keyword*)(internRigidSymbolWrtModule("PAGING", NULL, 2)));
    SYM_BACKLINKS_LOGIC_HYPOTHESIZED_INSTANCEp = ((Symbol*)(internRigidSymbolWrtModule("HYPOTHESIZED-INSTANCE?", NULL, 0)));
    SYM_BACKLINKS_LOGIC_STARTUP_BACKLINKS = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-BACKLINKS", NULL, 0)));
    SYM_BACKLINKS_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", TRUE), 0)));
  }
}

void helpStartupBacklinks2() {
  {
    defineFunctionObject("TYPE-HAS-BACKLINKS?", "(DEFUN (TYPE-HAS-BACKLINKS? BOOLEAN) ((TYPE TYPE)))", ((cpp_function_code)(&typeHasBacklinksP)), NULL);
    defineExternalSlotFromStringifiedSource("(DEFSLOT THING DEPENDENT-PROPOSITIONS-INDEX :TYPE BACKLINKS-INDEX :DOCUMENTATION \"Enables instances of 'THING' to have backindexes to \npropositions, making them first class logic objects.\" :PUBLIC? TRUE :ALLOCATION :DYNAMIC)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT PROPOSITION DEPENDENT-PROPOSITIONS-INDEX :TYPE BACKLINKS-INDEX :DOCUMENTATION \"Enables instances of 'PROPOSITION' to have (standard)\nbackindexes to propositions (as well as their own special ones), making them\nfirst class logic objects.\" :PUBLIC? TRUE :ALLOCATION :DYNAMIC)");
    defineFunctionObject("CREATE-BACKLINKS-INDEX", "(DEFUN (CREATE-BACKLINKS-INDEX BACKLINKS-INDEX) ((SELF OBJECT)))", ((cpp_function_code)(&createBacklinksIndex)), NULL);
    defineFunctionObject("GET-BACKLINKS-INDEX", "(DEFUN (GET-BACKLINKS-INDEX BACKLINKS-INDEX) ((SELF OBJECT)))", ((cpp_function_code)(&getBacklinksIndex)), NULL);
    defineFunctionObject("ADD-DEPENDENT-PROPOSITION-TO-SPECIALIZED-INDEX", "(DEFUN ADD-DEPENDENT-PROPOSITION-TO-SPECIALIZED-INDEX ((INDEX BACKLINKS-INDEX) (PROPOSITION PROPOSITION) (ARGUMENT OBJECT)))", ((cpp_function_code)(&addDependentPropositionToSpecializedIndex)), NULL);
    defineFunctionObject("HELP-ADD-DEPENDENT-PROPOSITION", "(DEFUN HELP-ADD-DEPENDENT-PROPOSITION ((INDEX BACKLINKS-INDEX) (PROPOSITION PROPOSITION) (ARGUMENT OBJECT)))", ((cpp_function_code)(&helpAddDependentProposition)), NULL);
    defineFunctionObject("ADD-DEPENDENT-PROPOSITION-LINK", "(DEFUN ADD-DEPENDENT-PROPOSITION-LINK ((SELF OBJECT) (PROPOSITION PROPOSITION)))", ((cpp_function_code)(&addDependentPropositionLink)), NULL);
    defineFunctionObject("REMOVE-DEPENDENT-PROPOSITION-LINK", "(DEFUN REMOVE-DEPENDENT-PROPOSITION-LINK ((SELF OBJECT) (PROPOSITION PROPOSITION)))", ((cpp_function_code)(&removeDependentPropositionLink)), NULL);
    defineFunctionObject("HELP-REMOVE-DEPENDENT-PROPOSITION", "(DEFUN HELP-REMOVE-DEPENDENT-PROPOSITION ((INDEX BACKLINKS-INDEX) (PROPOSITION PROPOSITION)))", ((cpp_function_code)(&helpRemoveDependentProposition)), NULL);
    defineFunctionObject("REMOVE-ALL-DEPENDENT-PROPOSITION-LINKS", "(DEFUN REMOVE-ALL-DEPENDENT-PROPOSITION-LINKS ((SELF LOGIC-OBJECT)))", ((cpp_function_code)(&removeAllDependentPropositionLinks)), NULL);
    defineFunctionObject("REWRAP-ARGUMENT", "(DEFUN (REWRAP-ARGUMENT OBJECT) ((ARGUMENT OBJECT)))", ((cpp_function_code)(&rewrapArgument)), NULL);
    defineFunctionObject("INDEX-ITH-DOMAIN?", "(DEFUN (INDEX-ITH-DOMAIN? BOOLEAN) ((DESCRIPTION NAMED-DESCRIPTION) (I INTEGER)))", ((cpp_function_code)(&indexIthDomainP)), NULL);
    defineFunctionObject("REWRAP-ITH-ARGUMENT?", "(DEFUN (REWRAP-ITH-ARGUMENT? BOOLEAN) ((ARGUMENT OBJECT) (PROPOSITION PROPOSITION) (I INTEGER)))", ((cpp_function_code)(&rewrapIthArgumentP)), NULL);
    defineFunctionObject("REWRAP-PROPOSITION-ARGUMENTS", "(DEFUN REWRAP-PROPOSITION-ARGUMENTS ((SELF PROPOSITION)))", ((cpp_function_code)(&rewrapPropositionArguments)), NULL);
    defineFunctionObject("UNFILTERED-DEPENDENT-PROPOSITIONS", "(DEFUN (UNFILTERED-DEPENDENT-PROPOSITIONS PROPOSITIONS-INDEX) ((SELF OBJECT) (RELATION SURROGATE)))", ((cpp_function_code)(&unfilteredDependentPropositions)), NULL);
    defineFunctionObject("ALL-SPECIALIZING-DEPENDENT-PROPOSITIONS-NEXT?", "(DEFUN (ALL-SPECIALIZING-DEPENDENT-PROPOSITIONS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)) :PUBLIC? TRUE)", ((cpp_function_code)(&allSpecializingDependentPropositionsNextP)), NULL);
    defineFunctionObject("ALL-SPECIALIZING-DEPENDENT-PROPOSITIONS", "(DEFUN (ALL-SPECIALIZING-DEPENDENT-PROPOSITIONS (ITERATOR OF PROPOSITION)) ((SELF OBJECT) (RELATIONREF SURROGATE)) :PUBLIC? TRUE)", ((cpp_function_code)(&allSpecializingDependentPropositions)), NULL);
    defineFunctionObject("UNFILTERED-DEPENDENT-ISA-PROPOSITIONS", "(DEFUN (UNFILTERED-DEPENDENT-ISA-PROPOSITIONS PROPOSITIONS-INDEX) ((SELF OBJECT)))", ((cpp_function_code)(&unfilteredDependentIsaPropositions)), NULL);
    defineFunctionObject("UNFILTERED-DEPENDENT-IMPLIES-PROPOSITIONS", "(DEFUN (UNFILTERED-DEPENDENT-IMPLIES-PROPOSITIONS PROPOSITIONS-INDEX) ((SELF OBJECT)))", ((cpp_function_code)(&unfilteredDependentImpliesPropositions)), NULL);
    defineFunctionObject("INHERITS-TRUTH-FROM-MASTER?", "(DEFUN (INHERITS-TRUTH-FROM-MASTER? BOOLEAN) ((SELF PROPOSITION)))", ((cpp_function_code)(&inheritsTruthFromMasterP)), NULL);
    defineFunctionObject("APPLICABLE-RULES-OF-DESCRIPTION", "(DEFUN (APPLICABLE-RULES-OF-DESCRIPTION (CONS OF PROPOSITION)) ((SELF LOGIC-OBJECT) (DIRECTION KEYWORD) (TRUERULESONLY? BOOLEAN)))", ((cpp_function_code)(&applicableRulesOfDescription)), NULL);
    defineFunctionObject("MAKE-SELECTION-PATTERN", "(DEFUN (MAKE-SELECTION-PATTERN SELECTION-PATTERN) ((KIND KEYWORD) (OPTIONS CONS) (ARGUMENTS CONS)) :GLOBALLY-INLINE? TRUE (RETURN (CONS KIND (CONS (CHOOSE (NULL? OPTIONS) NIL OPTIONS) ARGUMENTS))))", ((cpp_function_code)(&makeSelectionPattern)), NULL);
    defineFunctionObject("PATTERN-KIND", "(DEFUN (PATTERN-KIND KEYWORD) ((PATTERN SELECTION-PATTERN)) :GLOBALLY-INLINE? TRUE (RETURN (FIRST PATTERN)))", ((cpp_function_code)(&patternKind)), NULL);
    defineFunctionObject("PATTERN-OPTIONS", "(DEFUN (PATTERN-OPTIONS CONS) ((PATTERN SELECTION-PATTERN)) :GLOBALLY-INLINE? TRUE (RETURN (SECOND PATTERN)))", ((cpp_function_code)(&patternOptions)), NULL);
    defineFunctionObject("PATTERN-ARGUMENTS", "(DEFUN (PATTERN-ARGUMENTS CONS) ((PATTERN SELECTION-PATTERN)) :GLOBALLY-INLINE? TRUE (RETURN (REST (REST PATTERN))))", ((cpp_function_code)(&patternArguments)), NULL);
    defineFunctionObject("MAKE-DEPENDENT-PROPOSITIONS-PATTERN", "(DEFUN (MAKE-DEPENDENT-PROPOSITIONS-PATTERN SELECTION-PATTERN) ((ARGUMENT OBJECT)) :GLOBALLY-INLINE? TRUE (RETURN (MAKE-SELECTION-PATTERN :DEPENDENTS NIL (CONS ARGUMENT NIL))))", ((cpp_function_code)(&makeDependentPropositionsPattern)), NULL);
    defineFunctionObject("MAKE-ISA-PATTERN", "(DEFUN (MAKE-ISA-PATTERN SELECTION-PATTERN) ((ARGUMENT OBJECT)) :GLOBALLY-INLINE? TRUE (RETURN (MAKE-SELECTION-PATTERN :ISA NIL (CONS ARGUMENT NIL))))", ((cpp_function_code)(&makeIsaPattern)), NULL);
    defineFunctionObject("MAKE-RELATION-EXTENSION-PATTERN", "(DEFUN (MAKE-RELATION-EXTENSION-PATTERN SELECTION-PATTERN) ((RELATION SURROGATE)) :GLOBALLY-INLINE? TRUE (RETURN (MAKE-SELECTION-PATTERN :RELATION NIL (CONS RELATION NIL))))", ((cpp_function_code)(&makeRelationExtensionPattern)), NULL);
    defineFunctionObject("MAKE-RELATION-PATTERN", "(DEFUN (MAKE-RELATION-PATTERN SELECTION-PATTERN) ((RELATION SURROGATE) (ARGUMENT OBJECT)) :GLOBALLY-INLINE? TRUE (RETURN (MAKE-SELECTION-PATTERN :RELATION NIL (CONS RELATION (CONS ARGUMENT NIL)))))", ((cpp_function_code)(&makeRelationPattern)), NULL);
    defineFunctionObject("MAKE-RELATION-PATTERN-1", "(DEFUN (MAKE-RELATION-PATTERN-1 CONS) ((RELATION SURROGATE) (ARGUMENT OBJECT)) :GLOBALLY-INLINE? TRUE (RETURN (MAKE-RELATION-PATTERN-2 RELATION ARGUMENT NULL)))", ((cpp_function_code)(&makeRelationPattern1)), NULL);
    defineFunctionObject("MAKE-RELATION-PATTERN-2", "(DEFUN (MAKE-RELATION-PATTERN-2 SELECTION-PATTERN) ((RELATION SURROGATE) (ARGUMENT1 OBJECT) (ARGUMENT2 OBJECT)))", ((cpp_function_code)(&makeRelationPattern2)), NULL);
    defineFunctionObject("MAKE-RELATION-PATTERN-3", "(DEFUN (MAKE-RELATION-PATTERN-3 SELECTION-PATTERN) ((RELATION SURROGATE) (ARGUMENT1 OBJECT) (ARGUMENT2 OBJECT) (ARGUMENT3 OBJECT)))", ((cpp_function_code)(&makeRelationPattern3)), NULL);
    defineFunctionObject("MAKE-RELATION-PATTERN-4", "(DEFUN (MAKE-RELATION-PATTERN-4 SELECTION-PATTERN) ((RELATION SURROGATE) (ARGUMENT1 OBJECT) (ARGUMENT2 OBJECT) (ARGUMENT3 OBJECT) (ARGUMENT4 OBJECT)))", ((cpp_function_code)(&makeRelationPattern4)), NULL);
    defineFunctionObject("MAKE-RELATION-PATTERN-N", "(DEFUN (MAKE-RELATION-PATTERN-N SELECTION-PATTERN) ((RELATION SURROGATE) |&REST| (ARGUMENTS OBJECT)))", ((cpp_function_code)(&makeRelationPatternN)), NULL);
    defineFunctionObject("MAKE-RULES-PATTERN", "(DEFUN (MAKE-RULES-PATTERN SELECTION-PATTERN) ((POSRELATION OBJECT) (NEGRELATION OBJECT)))", ((cpp_function_code)(&makeRulesPattern)), NULL);
    defineFunctionObject("FIND-SELECTION-KEY-WITH-EQUIVALENTS", "(DEFUN (FIND-SELECTION-KEY-WITH-EQUIVALENTS LOGIC-OBJECT) ((PATTERN SELECTION-PATTERN)))", ((cpp_function_code)(&findSelectionKeyWithEquivalents)), NULL);
    defineFunctionObject("SELECT-PROPOSITIONS", "(DEFUN (SELECT-PROPOSITIONS PROPOSITIONS-INDEX) ((PATTERN SELECTION-PATTERN)))", ((cpp_function_code)(&selectPropositions)), NULL);
    defineFunctionObject("SELECT-ISA-PROPOSITIONS", "(DEFUN (SELECT-ISA-PROPOSITIONS PROPOSITIONS-INDEX) ((PATTERN SELECTION-PATTERN)))", ((cpp_function_code)(&selectIsaPropositions)), NULL);
    defineFunctionObject("SELECT-RELATION-PROPOSITIONS", "(DEFUN (SELECT-RELATION-PROPOSITIONS PROPOSITIONS-INDEX) ((PATTERN SELECTION-PATTERN)))", ((cpp_function_code)(&selectRelationPropositions)), NULL);
    defineFunctionObject("SELECT-RULE-PROPOSITIONS", "(DEFUN (SELECT-RULE-PROPOSITIONS PROPOSITIONS-INDEX) ((PATTERN SELECTION-PATTERN)))", ((cpp_function_code)(&selectRulePropositions)), NULL);
    defineFunctionObject("EVALUATE-SELECTION-PATTERN", "(DEFUN (EVALUATE-SELECTION-PATTERN TRUTH-VALUE) ((PATTERN SELECTION-PATTERN)))", ((cpp_function_code)(&evaluateSelectionPattern)), NULL);
    defineFunctionObject("EVALUATION-SELECTION-PATTERN?", "(DEFUN (EVALUATION-SELECTION-PATTERN? BOOLEAN) ((PATTERN SELECTION-PATTERN)))", ((cpp_function_code)(&evaluationSelectionPatternP)), NULL);
    defineFunctionObject("ARGUMENT-DISCOURAGES-BACKLINKS?", "(DEFUN (ARGUMENT-DISCOURAGES-BACKLINKS? BOOLEAN) ((SELF OBJECT)) :GLOBALLY-INLINE? TRUE (RETURN FALSE))", ((cpp_function_code)(&argumentDiscouragesBacklinksP)), NULL);
    defineFunctionObject("SURROGATIFY-DISCOURAGED-ARGUMENTS", "(DEFUN SURROGATIFY-DISCOURAGED-ARGUMENTS ((SELF PROPOSITION)))", ((cpp_function_code)(&surrogatifyDiscouragedArguments)), NULL);
    defineFunctionObject("COUNT-BACKLINKS-ON-RELATION", "(DEFUN (COUNT-BACKLINKS-ON-RELATION INTEGER) ((SELF OBJECT) (KIND KEYWORD) (RELATION SURROGATE)))", ((cpp_function_code)(&countBacklinksOnRelation)), NULL);
    defineFunctionObject("SELECT-ARGUMENT-WITH-BACKLINKS", "(DEFUN (SELECT-ARGUMENT-WITH-BACKLINKS OBJECT BOOLEAN) ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&selectArgumentWithBacklinks)), NULL);
    defineFunctionObject("INSTANCE-HAS-BACKLINKS?", "(DEFUN (INSTANCE-HAS-BACKLINKS? BOOLEAN) ((SELF OBJECT)))", ((cpp_function_code)(&instanceHasBacklinksP)), NULL);
    defineFunctionObject("SELECT-INSTANCE-WITH-BACKLINKS", "(DEFUN (SELECT-INSTANCE-WITH-BACKLINKS OBJECT) ((INSTANCES CONS) (RELATION SURROGATE)) :INLINE INSTANCE-HAS-BACKLINKS?)", ((cpp_function_code)(&selectInstanceWithBacklinks)), NULL);
    defineFunctionObject("FIND-SIMILAR-PROPOSITIONS", "(DEFUN (FIND-SIMILAR-PROPOSITIONS PROPOSITIONS-INDEX) ((SELF PROPOSITION)))", ((cpp_function_code)(&findSimilarPropositions)), NULL);
    defineFunctionObject("FIND-MATCHING-CONCEIVED-PROPOSITION", "(DEFUN (FIND-MATCHING-CONCEIVED-PROPOSITION PROPOSITION) ((GOAL PROPOSITION)))", ((cpp_function_code)(&findMatchingConceivedProposition)), NULL);
    defineFunctionObject("TRANSFER-PROPOSITIONS-AND-BACKLINKS", "(DEFUN TRANSFER-PROPOSITIONS-AND-BACKLINKS ((FROM OBJECT) (TO OBJECT)))", ((cpp_function_code)(&transferPropositionsAndBacklinks)), NULL);
    defineFunctionObject("TRANSFER-PROPOSITIONS-EXCEPT-FOR", "(DEFUN TRANSFER-PROPOSITIONS-EXCEPT-FOR ((FROM OBJECT) (TO OBJECT) (EXCEPTPROPOSITIONS (LIST OF PROPOSITION))))", ((cpp_function_code)(&transferPropositionsExceptFor)), NULL);
    defineFunctionObject("TRANSFER-DESCRIPTION-EXTENSION", "(DEFUN TRANSFER-DESCRIPTION-EXTENSION ((FROM NAMED-DESCRIPTION) (TO NAMED-DESCRIPTION)))", ((cpp_function_code)(&transferDescriptionExtension)), NULL);
    defineFunctionObject("GET-DESCRIPTION-EXTENSION", "(DEFUN (GET-DESCRIPTION-EXTENSION PROPOSITIONS-INDEX) ((DESCRIPTION NAMED-DESCRIPTION) (UPDATE? BOOLEAN)))", ((cpp_function_code)(&getDescriptionExtension)), NULL);
    defineFunctionObject("CLEANUP-DESCRIPTION-EXTENSION", "(DEFUN CLEANUP-DESCRIPTION-EXTENSION ((DESCRIPTION NAMED-DESCRIPTION)))", ((cpp_function_code)(&cleanupDescriptionExtension)), NULL);
    defineFunctionObject("CLEANUP-ALL-DESCRIPTION-EXTENSIONS", "(DEFUN CLEANUP-ALL-DESCRIPTION-EXTENSIONS ())", ((cpp_function_code)(&cleanupAllDescriptionExtensions)), NULL);
    defineFunctionObject("UPDATE-DESCRIPTION-EXTENSION", "(DEFUN UPDATE-DESCRIPTION-EXTENSION ((SELF PROPOSITION)))", ((cpp_function_code)(&updateDescriptionExtension)), NULL);
    defineFunctionObject("ALL-EXTENSION-MEMBERS", "(DEFUN (ALL-EXTENSION-MEMBERS ITERATOR) ((DESCRIPTION NAMED-DESCRIPTION)))", ((cpp_function_code)(&allExtensionMembers)), NULL);
    defineFunctionObject("COLLECTION-IMPLIES-COLLECTION?", "(DEFUN (COLLECTION-IMPLIES-COLLECTION? BOOLEAN) ((SUBCOLLECTION LOGIC-OBJECT) (SUPERCOLLECTION LOGIC-OBJECT)))", ((cpp_function_code)(&collectionImpliesCollectionP)), NULL);
  }
}

void startupBacklinks() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupBacklinks1();
    }
    if (currentStartupTimePhaseP(4)) {
      oINTEGER_LOGIC_WRAPPER_TABLEo = newIntegerHashTable();
      oFLOAT_LOGIC_WRAPPER_TABLEo = newFloatHashTable();
      oSTRING_LOGIC_WRAPPER_TABLEo = newStringHashTable();
      oBACKLINK_ALL_PROPOSITION_ARGUMENTSpo = FALSE;
      oSUPPRESSINSERTIONINTOCLASSEXTENSIONpo.set(FALSE);
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupBacklinks2();
      defineFunctionObject("RELATION-IMPLIES-RELATION?", "(DEFUN (RELATION-IMPLIES-RELATION? BOOLEAN) ((SUBREL NAMED-DESCRIPTION) (SUPERREL NAMED-DESCRIPTION)) :GLOBALLY-INLINE? TRUE (RETURN (COLLECTION-IMPLIES-COLLECTION? SUBREL SUPERREL)))", ((cpp_function_code)(&relationImpliesRelationP)), NULL);
      defineFunctionObject("DESCRIPTION-IMPLIES-DESCRIPTION?", "(DEFUN (DESCRIPTION-IMPLIES-DESCRIPTION? BOOLEAN) ((SUBDESC DESCRIPTION) (SUPERDESC DESCRIPTION)) :GLOBALLY-INLINE? TRUE (RETURN (COLLECTION-IMPLIES-COLLECTION? SUBDESC SUPERDESC)))", ((cpp_function_code)(&descriptionImpliesDescriptionP)), NULL);
      defineFunctionObject("RELATIONREF-SPECIALIZES-RELATIONREF?", "(DEFUN (RELATIONREF-SPECIALIZES-RELATIONREF? BOOLEAN) ((RELATIONREF1 SURROGATE) (RELATIONREF2 SURROGATE)) :INLINE SURROGATE-TO-DESCRIPTION)", ((cpp_function_code)(&relationrefSpecializesRelationrefP)), NULL);
      defineFunctionObject("STARTUP-BACKLINKS", "(DEFUN STARTUP-BACKLINKS () :PUBLIC? TRUE)", ((cpp_function_code)(&startupBacklinks)), NULL);
      { MethodSlot* function = lookupFunction(SYM_BACKLINKS_LOGIC_STARTUP_BACKLINKS);

        setDynamicSlotValue(function->dynamicSlots, SYM_BACKLINKS_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Backlinks"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SPECIALIZED-BACKLINKS-CROSSOVER-POINT* INTEGER 10 :DOCUMENTATION \"When 'dependent-propositions-list' gets this long in a\nbacklinks index, then we create a hash table index and other\nspecialized indices.\")");
      oWRAPPED_TYPE_TABLEo = oWRAPPED_TYPE_TABLEo->concatenate(listO(4, listO(3, SGT_BACKLINKS_LOGIC_INTEGER_LOGIC_WRAPPER, SGT_BACKLINKS_STELLA_INTEGER, NIL), listO(3, SGT_BACKLINKS_LOGIC_FLOAT_LOGIC_WRAPPER, SGT_BACKLINKS_STELLA_FLOAT, NIL), listO(3, SGT_BACKLINKS_LOGIC_STRING_LOGIC_WRAPPER, SGT_BACKLINKS_STELLA_STRING, NIL), NIL), 0);
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *INTEGER-LOGIC-WRAPPER-TABLE* INTEGER-HASH-TABLE (NEW INTEGER-HASH-TABLE))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *FLOAT-LOGIC-WRAPPER-TABLE* FLOAT-HASH-TABLE (NEW FLOAT-HASH-TABLE))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STRING-LOGIC-WRAPPER-TABLE* STRING-HASH-TABLE (NEW STRING-HASH-TABLE))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *BACKLINK-ALL-PROPOSITION-ARGUMENTS?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE, wrap all literal proposition arguments\nso that they can all support backlink indices.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *SUPPRESSINSERTIONINTOCLASSEXTENSION?* BOOLEAN FALSE :DOCUMENTATION \"Used when creating a skolem (e.g., a prototype) that\nisn't visible in the corresponding class extension.\")");
    }
  }
}

Surrogate* SGT_BACKLINKS_LOGIC_PATTERN_VARIABLE = NULL;

Keyword* KWD_BACKLINKS_NON_PAGING = NULL;

Keyword* KWD_BACKLINKS_DEPENDENTS = NULL;

Surrogate* SGT_BACKLINKS_LOGIC_LOGIC_OBJECT = NULL;

Surrogate* SGT_BACKLINKS_STELLA_THING = NULL;

Symbol* SYM_BACKLINKS_LOGIC_DEPENDENT_PROPOSITIONS_INDEX = NULL;

Surrogate* SGT_BACKLINKS_LOGIC_INTEGER_LOGIC_WRAPPER = NULL;

Surrogate* SGT_BACKLINKS_LOGIC_FLOAT_LOGIC_WRAPPER = NULL;

Surrogate* SGT_BACKLINKS_LOGIC_STRING_LOGIC_WRAPPER = NULL;

Keyword* KWD_BACKLINKS_ISA = NULL;

Keyword* KWD_BACKLINKS_RELATION = NULL;

Surrogate* SGT_BACKLINKS_LOGIC_PROPOSITION = NULL;

Keyword* KWD_BACKLINKS_CONSTANT = NULL;

Surrogate* SGT_BACKLINKS_LOGIC_DESCRIPTION = NULL;

Symbol* SYM_BACKLINKS_LOGIC_COMPLEMENT_DESCRIPTION = NULL;

Surrogate* SGT_BACKLINKS_LOGIC_SKOLEM = NULL;

Surrogate* SGT_BACKLINKS_LOGIC_NON_PAGING_INDEX = NULL;

Surrogate* SGT_BACKLINKS_STELLA_INTEGER = NULL;

Surrogate* SGT_BACKLINKS_STELLA_FLOAT = NULL;

Surrogate* SGT_BACKLINKS_STELLA_STRING = NULL;

Surrogate* SGT_BACKLINKS_STELLA_LITERAL_WRAPPER = NULL;

Surrogate* SGT_BACKLINKS_LOGIC_PAGING_INDEX = NULL;

Surrogate* SGT_BACKLINKS_PL_KERNEL_KB_SUBSET_OF = NULL;

Symbol* SYM_BACKLINKS_LOGIC_MASTER_PROPOSITION = NULL;

Keyword* KWD_BACKLINKS_FORWARD = NULL;

Symbol* SYM_BACKLINKS_LOGIC_SUBSUMPTION_LINKp = NULL;

Keyword* KWD_BACKLINKS_RULES = NULL;

Keyword* KWD_BACKLINKS_CONTEXT_PROPOSITIONS = NULL;

Keyword* KWD_BACKLINKS_CONTEXT_INSTANCES = NULL;

Keyword* KWD_BACKLINKS_EVALUATEp = NULL;

Symbol* SYM_BACKLINKS_STELLA_TRUE = NULL;

Keyword* KWD_BACKLINKS_FUNCTION = NULL;

Keyword* KWD_BACKLINKS_PREDICATE = NULL;

Keyword* KWD_BACKLINKS_EQUIVALENT = NULL;

Keyword* KWD_BACKLINKS_PAGING = NULL;

Symbol* SYM_BACKLINKS_LOGIC_HYPOTHESIZED_INSTANCEp = NULL;

Symbol* SYM_BACKLINKS_LOGIC_STARTUP_BACKLINKS = NULL;

Symbol* SYM_BACKLINKS_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
