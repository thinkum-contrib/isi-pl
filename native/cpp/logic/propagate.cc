//  -*- Mode: C++ -*-

// propagate.cc

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

// True if we are inside of 'react-to-kb-update'.
DEFINE_STELLA_SPECIAL(oFILLINGCONSTRAINTPROPAGATIONQUEUESpo, boolean , FALSE);

// True if we are propagating strict inferences, and
// posting derived default propositions to temporary queues.
DEFINE_STELLA_SPECIAL(oDEFERINGDEFAULTFORWARDINFERENCESpo, boolean , FALSE);

Cons* deferredDefaultPropositions(Context* self) {
  { Cons* value = ((Cons*)(dynamicSlotValue(self->dynamicSlots, SYM_PROPAGATE_LOGIC_DEFERRED_DEFAULT_PROPOSITIONS_INTERNAL, NULL)));

    if (!((boolean)(value))) {
      return (NIL);
    }
    else {
      return (value);
    }
  }
}

void deferredDefaultPropositionsSetter(Context* self, Cons* newvalue) {
  setDynamicSlotValue(self->dynamicSlots, SYM_PROPAGATE_LOGIC_DEFERRED_DEFAULT_PROPOSITIONS_INTERNAL, newvalue, NULL);
}

Keyword* evaluationState(Proposition* proposition) {
  { HashTable* table = ((HashTable*)(dynamicSlotValue(oCONTEXTo.get()->dynamicSlots, SYM_PROPAGATE_LOGIC_EVALUATION_STATE_TABLE, NULL)));

    if (!((boolean)(table))) {
      return (NULL);
    }
    return (((Keyword*)(table->lookup(proposition))));
  }
}

void evaluationStateSetter(Proposition* proposition, Keyword* state) {
  { HashTable* table = ((HashTable*)(dynamicSlotValue(oCONTEXTo.get()->dynamicSlots, SYM_PROPAGATE_LOGIC_EVALUATION_STATE_TABLE, NULL)));

    if (!((boolean)(table))) {
      return;
    }
    table->insertAt(proposition, state);
  }
}

void postForEvaluation(Proposition* self) {
  if (!oFILLINGCONSTRAINTPROPAGATIONQUEUESpo.get()) {
    evaluateProposition(self);
    return;
  }
  if (evaluationState(self) == KWD_PROPAGATE_POSTED) {
    return;
  }
  ((List*)(dynamicSlotValue(oCONTEXTo.get()->dynamicSlots, SYM_PROPAGATE_LOGIC_EVALUATION_QUEUE, NULL)))->insert(self);
  evaluationStateSetter(self, KWD_PROPAGATE_POSTED);
}

// Points to an active queue of propositions that will trigger
// forward inference.  New queue entries are posted to a separate queue
// attached to *context*.
DEFINE_STELLA_SPECIAL(oCURRENTLYEXECUTINGFORWARDCHAININGQUEUEo, List* , NULL);

Cons* helpCollectForwardRules(Description* description, KeyValueList* rules, KeyValueList* indices, boolean toucheddefaultP, List* beenthere) {
  if (!((boolean)(rules))) {
    rules = newKeyValueList();
  }
  if (!((boolean)(indices))) {
    indices = newKeyValueList();
  }
  if (!((boolean)(beenthere))) {
    beenthere = newList();
  }
  beenthere->insert(description);
  { ForwardChainingIndex* index = NULL;
    Cons* iter000 = description->forwardChainingIndices_reader()->theConsList;

    while (!(iter000 == NIL)) {
      index = ((ForwardChainingIndex*)(iter000->value));
      iter000 = iter000->rest;
      if ((!index->masterRule->deletedP()) &&
          trueP(index->masterRule)) {
        indices->insertAt(index, (toucheddefaultP ? TRUE_WRAPPER : FALSE_WRAPPER));
      }
    }
  }
  { Proposition* p = NULL;
    Cons* iter001 = applicableRulesOfDescription(description, KWD_PROPAGATE_FORWARD, TRUE);

    while (!(iter001 == NIL)) {
      p = ((Proposition*)(iter001->value));
      iter001 = iter001->rest;
      if (!((BooleanWrapper*)(dynamicSlotValue(p->dynamicSlots, SYM_PROPAGATE_LOGIC_BACKWARD_ONLYp, FALSE_WRAPPER)))->wrapperValue) {
        { Object* consequent = (p->arguments->theArray)[1];

          { Surrogate* testValue000 = safePrimaryType(consequent);

            if (subtypeOfP(testValue000, SGT_PROPAGATE_LOGIC_NAMED_DESCRIPTION)) {
              { Object* consequent000 = consequent;
                NamedDescription* consequent = ((NamedDescription*)(consequent000));

                { Object* super = valueOf(consequent);

                  if (defaultTrueP(p)) {
                    toucheddefaultP = TRUE;
                  }
                  if (!(classP(description) == classP(super))) {
                    rules->insertAt(p, (toucheddefaultP ? TRUE_WRAPPER : FALSE_WRAPPER));
                  }
                  if (!beenthere->memberP(super)) {
                    helpCollectForwardRules(((Description*)(super)), rules, indices, toucheddefaultP, beenthere);
                  }
                }
              }
            }
            else if (subtypeOfP(testValue000, SGT_PROPAGATE_LOGIC_DESCRIPTION)) {
              { Object* consequent001 = consequent;
                Description* consequent = ((Description*)(consequent001));

                rules->insertAt(p, (toucheddefaultP ? TRUE_WRAPPER : FALSE_WRAPPER));
              }
            }
            else {
            }
          }
        }
      }
    }
  }
  return (cons(rules, cons(indices, NIL)));
}

KeyValueList* collectForwardChainingRules(Description* description, KeyValueList*& _Return1) {
  { MemoizationTable* memoTable000 = ((MemoizationTable*)(SGT_PROPAGATE_LOGIC_F_COLLECT_FORWARD_CHAINING_RULES_MEMO_TABLE_000->surrogateValue));
    Cons* memoizedEntry000 = NULL;
    Object* memoizedValue000 = NULL;

    if (!((boolean)(memoTable000))) {
      initializeMemoizationTable(SGT_PROPAGATE_LOGIC_F_COLLECT_FORWARD_CHAINING_RULES_MEMO_TABLE_000, "(:MAX-VALUES 500 :TIMESTAMPS (:META-KB-UPDATE))");
      memoTable000 = ((MemoizationTable*)(SGT_PROPAGATE_LOGIC_F_COLLECT_FORWARD_CHAINING_RULES_MEMO_TABLE_000->surrogateValue));
    }
    if (oMEMOIZATION_ENABLEDpo) {
      memoizedEntry000 = lookupMruMemoizedValue(((MruMemoizationTable*)(memoTable000)), description, oCONTEXTo.get(), MEMOIZED_NULL_VALUE, NULL, -1);
      memoizedValue000 = memoizedEntry000->value;
    }
    if (((boolean)(memoizedValue000))) {
      if (memoizedValue000 == MEMOIZED_NULL_VALUE) {
        memoizedValue000 = NULL;
      }
    }
    else {
      memoizedValue000 = helpCollectForwardRules(description, NULL, NULL, FALSE, NULL);
      if (oMEMOIZATION_ENABLEDpo) {
        memoizedEntry000->value = ((!((boolean)(memoizedValue000))) ? MEMOIZED_NULL_VALUE : memoizedValue000);
      }
    }
    { Cons* rules = ((Cons*)(memoizedValue000));

      _Return1 = ((KeyValueList*)(rules->rest->value));
      return (((KeyValueList*)(rules->value)));
    }
  }
}

boolean hasForwardChainingRulesP(Description* description, Proposition* proposition) {
  if (falseP(proposition)) {
    description = getInferableComplementDescription(description);
    if (!((boolean)(description))) {
      return (FALSE);
    }
  }
  { KeyValueList* rules = NULL;
    KeyValueList* indices = NULL;

    rules = collectForwardChainingRules(description, indices);
    return (rules->nonEmptyP() ||
        indices->nonEmptyP());
  }
}

void postToForwardChainingQueue(Proposition* self, World* world) {
  if (unknownP(self) &&
      (!(self->kind == KWD_PROPAGATE_FUNCTION))) {
    return;
  }
  { List* forwardchainingqueue = ((List*)(dynamicSlotValue(world->dynamicSlots, SYM_PROPAGATE_LOGIC_FORWARD_CHAINING_QUEUE, NULL)));

    { Keyword* testValue000 = self->kind;

      if ((testValue000 == KWD_PROPAGATE_ISA) ||
          ((testValue000 == KWD_PROPAGATE_PREDICATE) ||
           (testValue000 == KWD_PROPAGATE_FUNCTION))) {
        { boolean foundP000 = FALSE;

          { Object* arg = NULL;
            Vector* vector000 = self->arguments;
            int index000 = 0;
            int length000 = vector000->length();

            while (index000 < length000) {
              arg = (vector000->theArray)[index000];
              index000 = index000 + 1;
              if (isaP(arg, SGT_PROPAGATE_LOGIC_SKOLEM) &&
                  ((!((boolean)(((Skolem*)(arg))->definingProposition))) &&
                   (!((BooleanWrapper*)(dynamicSlotValue(((Skolem*)(arg))->dynamicSlots, SYM_PROPAGATE_LOGIC_HYPOTHESIZED_INSTANCEp, FALSE_WRAPPER)))->wrapperValue))) {
                foundP000 = TRUE;
                break;
              }
            }
          }
          if (foundP000) {
            if (((boolean)(oCOLLECTFORWARDPROPOSITIONSo.get()))) {
              return;
            }
          }
        }
        { NamedDescription* description = getDescription(((Surrogate*)(self->operatoR)));

          if (((boolean)(description)) &&
              hasForwardChainingRulesP(description, self)) {
            forwardchainingqueue->push(self);
          }
        }
      }
      else {
      }
    }
  }
}

// Collect goes-true propositions produced by forward
// chaining.
DEFINE_STELLA_SPECIAL(oCOLLECTFORWARDPROPOSITIONSo, Cons* , NULL);

void applyRuleConsequentToVector(Description* consequent, Vector* arguments, Proposition* rule, Description* triggerdescription, Proposition* triggerproposition, boolean toucheddefaultP) {
  { 
    BIND_STELLA_SPECIAL(oCOLLECTFORWARDPROPOSITIONSo, Cons*, NIL);
    { boolean toucheddefaultknowledgeP = defaultTrueP(triggerproposition) ||
          (defaultTrueP(rule) ||
           toucheddefaultP);

      { 
        BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, NULL);
        inheritDescription(arguments, consequent, toucheddefaultknowledgeP);
      }
    }
    { Proposition* p = NULL;
      Cons* iter000 = oCOLLECTFORWARDPROPOSITIONSo.get();

      while (!(iter000 == NIL)) {
        p = ((Proposition*)(iter000->value));
        iter000 = iter000->rest;
        if (traceKeywordP(KWD_PROPAGATE_PROPAGATE)) {
          std::cout << "MODUS PONENS:" << std::endl;
          std::cout << "   ANTECEDENT:  (";
          if (namedDescriptionP(triggerdescription)) {
            std::cout << triggerdescription->descriptionName();
          }
          else {
            std::cout << "not-" << ((Description*)(dynamicSlotValue(triggerdescription->dynamicSlots, SYM_PROPAGATE_LOGIC_COMPLEMENT_DESCRIPTION, NULL)))->descriptionName();
          }
          { Object* arg = NULL;
            Vector* vector000 = arguments;
            int index000 = 0;
            int length000 = vector000->length();

            while (index000 < length000) {
              arg = (vector000->theArray)[index000];
              index000 = index000 + 1;
              std::cout << " ";
              printFormula(arg, 15);
            }
          }
          std::cout << ")" << std::endl;
          std::cout << "   RULE:  ";
          printFormula(rule, 10);
          std::cout << std::endl;
          std::cout << "   CONSEQUENT: ";
          printFormula(p, 15);
          std::cout << std::endl;
        }
        recordForwardGoal(rule, arguments, p);
        recordForwardJustification(p, rule, consList(1, triggerproposition));
      }
    }
  }
}

void applyForwardRulesToVector(Description* triggerdescription, Vector* arguments, Proposition* triggerproposition) {
  { Vector* evaluatedargs = arguments;

    { Object* arg = NULL;
      int i = NULL_INTEGER;
      Vector* vector000 = arguments;
      int index000 = 0;
      int length000 = vector000->length();
      int iter000 = 0;

      while (index000 < length000) {
        arg = (vector000->theArray)[index000];
        index000 = index000 + 1;
        i = iter000;
        iter000 = iter000 + 1;
        if (arg->deletedP()) {
          return;
        }
        else if (!eqlP(arg, valueOf(arg))) {
          if (arguments == evaluatedargs) {
            evaluatedargs = arguments->copy();
          }
          (evaluatedargs->theArray)[i] = (valueOf(arg));
        }
      }
    }
    arguments = evaluatedargs;
  }
  { KeyValueList* rules = NULL;
    KeyValueList* indices = NULL;

    rules = collectForwardChainingRules(triggerdescription, indices);
    { Proposition* r = NULL;
      BooleanWrapper* toucheddefaultP = NULL;
      KvCons* iter001 = rules->theKvList;

      while (((boolean)(iter001))) {
        r = ((Proposition*)(iter001->key));
        toucheddefaultP = ((BooleanWrapper*)(iter001->value));
        iter001 = iter001->rest;
        if (applicableForwardRuleP(r, arguments)) {
          applyRuleConsequentToVector(((Description*)((r->arguments->theArray)[1])), arguments, r, triggerdescription, triggerproposition, coerceWrappedBooleanToBoolean(toucheddefaultP));
        }
      }
    }
    { ForwardChainingIndex* fwdindex = NULL;
      BooleanWrapper* toucheddefaultP = NULL;
      KvCons* iter002 = indices->theKvList;

      while (((boolean)(iter002))) {
        fwdindex = ((ForwardChainingIndex*)(iter002->key));
        toucheddefaultP = ((BooleanWrapper*)(iter002->value));
        iter002 = iter002->rest;
        { Cons* inputargs = NIL;

          if (!(arguments->length() == fwdindex->forwardGoal->arguments->length())) {
            continue;
          }
          { Object* arg = NULL;
            Object* goalarg = NULL;
            Vector* vector001 = arguments;
            int index001 = 0;
            int length001 = vector001->length();
            Vector* vector002 = fwdindex->forwardGoal->arguments;
            int index002 = 0;
            int length002 = vector002->length();

            while ((index001 < length001) &&
                (index002 < length002)) {
              arg = (vector001->theArray)[index001];
              index001 = index001 + 1;
              goalarg = (vector002->theArray)[index002];
              index002 = index002 + 1;
              if (variableP(goalarg)) {
                inputargs = cons(arg, inputargs);
              }
              else if (!eqlP(arg, valueOf(goalarg))) {
                inputargs = NULL;
                break;
              }
            }
          }
          if (!((boolean)(inputargs))) {
            continue;
          }
          { Object* arg = NULL;
            ConsIterator* it = fwdindex->inputBindings->allocateIterator();
            Cons* iter003 = inputargs->reverse();

            while (it->nextP() &&
                (!(iter003 == NIL))) {
              arg = iter003->value;
              iter003 = iter003->rest;
                            it->valueSetter(arg);
            }
          }
        }
        { Cons* outputbindings = NULL;
          Cons* truthvalues = NULL;

          outputbindings = applyCachedRetrieve(fwdindex->ioVariables, fwdindex->queryBody, fwdindex->inputBindings, consList(2, KWD_PROPAGATE_SINGLETONSp, TRUE_WRAPPER), fwdindex->cacheId, truthvalues);
          { Object* ob = NULL;
            Object* tv = NULL;
            Cons* iter004 = outputbindings;
            Cons* iter005 = truthvalues;

            while ((!(iter004 == NIL)) &&
                (!(iter005 == NIL))) {
              ob = iter004->value;
              iter004 = iter004->rest;
              tv = iter005->value;
              iter005 = iter005->rest;
              applyRuleConsequentToVector(fwdindex->consequent, copyListToArgumentsVector(((Cons*)(ob))->listify()), fwdindex->masterRule, triggerdescription, triggerproposition, coerceWrappedBooleanToBoolean(toucheddefaultP) ||
                  (tv == DEFAULT_TRUE_TRUTH_VALUE));
            }
          }
        }
      }
    }
  }
}

boolean applicableForwardRuleP(Proposition* rule, Vector* arguments) {
  { Description* antecedentdescription = ((Description*)((rule->arguments->theArray)[0]));

    return (trueP(rule) &&
        (arguments->length() == antecedentdescription->ioVariables->length()));
  }
}

void Skolem::reactToInferenceUpdate() {
  { Skolem* self = this;

    { Object* derivedvalue = valueOf(self);
      Object* assertedvalue = NULL;

      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
        assertedvalue = valueOf(self);
      }
      if (((boolean)(assertedvalue)) &&
          (!eqlP(assertedvalue, derivedvalue))) {
        equateValues(valueOf(assertedvalue), derivedvalue);
      }
      { Proposition* prop = NULL;
        Iterator* iter000 = unfilteredDependentPropositions(self, NULL)->allocateIterator();

        while (iter000->nextP()) {
          prop = ((Proposition*)(iter000->value));
          postForEvaluation(prop);
        }
      }
      if (oFILLINGCONSTRAINTPROPAGATIONQUEUESpo.get()) {
        { Proposition* definingproposition = self->definingProposition;

          if (((boolean)(definingproposition))) {
            postToForwardChainingQueue(definingproposition, ((World*)(oCONTEXTo.get())));
          }
        }
      }
    }
  }
}

void Proposition::reactToInferenceUpdate() {
  { Proposition* self = this;

    { TruthValue* parenttruthvalue = ((TruthValue*)(accessInContext(self->truthValue, self->homeContext, FALSE)));

      if ((!(parenttruthvalue == ((TruthValue*)(accessInContext(self->truthValue, self->homeContext, FALSE))))) &&
          ((boolean)(parenttruthvalue))) {
        signalTruthValueClash(self);
      }
      postForEvaluation(self);
      { Proposition* prop = NULL;
        Iterator* iter000 = self->dependentPropositions->allocateIterator();

        while (iter000->nextP()) {
          prop = ((Proposition*)(iter000->value));
          postForEvaluation(prop);
        }
      }
      if (oFILLINGCONSTRAINTPROPAGATIONQUEUESpo.get()) {
        postToForwardChainingQueue(self, ((World*)(oCONTEXTo.get())));
      }
    }
  }
}

void reactToKbUpdate(Context* context, Object* object) {
  { boolean skolemP = FALSE;
    boolean propositionP = FALSE;
    boolean metapropositionP = FALSE;

    { Surrogate* testValue000 = safePrimaryType(object);

      if (subtypeOfP(testValue000, SGT_PROPAGATE_LOGIC_SKOLEM)) {
        { Object* object000 = object;
          Skolem* object = ((Skolem*)(object000));

          skolemP = TRUE;
        }
      }
      else if (subtypeOfP(testValue000, SGT_PROPAGATE_LOGIC_PROPOSITION)) {
        { Object* object001 = object;
          Proposition* object = ((Proposition*)(object001));

          propositionP = TRUE;
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    if (propositionP &&
        metaPropositionP(((Proposition*)(object)))) {
      metapropositionP = TRUE;
    }
    bumpMemoizationTimestamp(KWD_PROPAGATE_KB_UPDATE);
    if (metapropositionP) {
      bumpMemoizationTimestamp(KWD_PROPAGATE_META_KB_UPDATE);
    }
    if (oINVISIBLEASSERTIONpo.get()) {
      return;
    }
    else if (descriptionModeP()) {
      { 
        BIND_STELLA_SPECIAL(oFILLINGCONSTRAINTPROPAGATIONQUEUESpo, boolean, FALSE);
        if (propositionP) {
          ((Proposition*)(object))->reactToInferenceUpdate();
        }
        else if (skolemP) {
          ((Skolem*)(object))->reactToInferenceUpdate();
        }
      }
      return;
    }
    else if (oFILLINGCONSTRAINTPROPAGATIONQUEUESpo.get()) {
      if (propositionP) {
        ((Proposition*)(object))->reactToInferenceUpdate();
      }
      else if (skolemP) {
        ((Skolem*)(object))->reactToInferenceUpdate();
      }
      return;
    }
    { World* world = (metapropositionP ? lookupInferenceCache(context, KWD_PROPAGATE_META) : lookupConstraintPropagationWorld(context));

      if (((boolean)(world))) {
        { 
          BIND_STELLA_SPECIAL(oCONTEXTo, Context*, world);
          BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
          initializeConstraintPropagationQueues(world);
          { 
            BIND_STELLA_SPECIAL(oFILLINGCONSTRAINTPROPAGATIONQUEUESpo, boolean, TRUE);
            if (propositionP) {
              ((Proposition*)(object))->reactToInferenceUpdate();
            }
            else if (skolemP) {
              ((Skolem*)(object))->reactToInferenceUpdate();
            }
            executeConstraintPropagationQueues();
          }
        }
      }
    }
    if (isaP(context, SGT_PROPAGATE_STELLA_MODULE)) {
      { Context* child = NULL;
        Cons* iter000 = context->childContexts->theConsList;

        while (!(iter000 == NIL)) {
          child = ((Context*)(iter000->value));
          iter000 = iter000->rest;
          if (isaP(child, SGT_PROPAGATE_STELLA_MODULE)) {
            reactToKbUpdate(child, object);
          }
        }
      }
    }
  }
}

void initializeConstraintPropagationQueues(World* world) {
  setDynamicSlotValue(world->dynamicSlots, SYM_PROPAGATE_LOGIC_EVALUATION_QUEUE, newList(), NULL);
  setDynamicSlotValue(world->dynamicSlots, SYM_PROPAGATE_LOGIC_FORWARD_CHAINING_QUEUE, newList(), NULL);
}

void executeConstraintPropagationQueues() {
  { 
    BIND_STELLA_SPECIAL(oINHIBITOBJECTFINALIZATIONpo, boolean, TRUE);
    for (;;) {
      { List* queue = ((List*)(dynamicSlotValue(oCONTEXTo.get()->dynamicSlots, SYM_PROPAGATE_LOGIC_EVALUATION_QUEUE, NULL)));

        setDynamicSlotValue(oCONTEXTo.get()->dynamicSlots, SYM_PROPAGATE_LOGIC_EVALUATION_QUEUE, newList(), NULL);
        { Proposition* p = NULL;
          Cons* iter000 = queue->theConsList;

          while (!(iter000 == NIL)) {
            p = ((Proposition*)(iter000->value));
            iter000 = iter000->rest;
            evaluateProposition(p);
          }
        }
      }
      { List* queue = ((List*)(dynamicSlotValue(oCONTEXTo.get()->dynamicSlots, SYM_PROPAGATE_LOGIC_FORWARD_CHAINING_QUEUE, NULL)));

        setDynamicSlotValue(oCONTEXTo.get()->dynamicSlots, SYM_PROPAGATE_LOGIC_FORWARD_CHAINING_QUEUE, newList(), NULL);
        { Proposition* proposition = NULL;
          Cons* iter001 = queue->theConsList;

          while (!(iter001 == NIL)) {
            proposition = ((Proposition*)(iter001->value));
            iter001 = iter001->rest;
                        { Description* description = getDescription(((Surrogate*)(proposition->operatoR)));

              if (falseP(proposition)) {
                description = getInferableComplementDescription(description);
              }
              if (((boolean)(description))) {
                applyForwardRulesToVector(description, proposition->arguments, proposition);
              }
            }
          }
        }
      }
      if (((List*)(dynamicSlotValue(oCONTEXTo.get()->dynamicSlots, SYM_PROPAGATE_LOGIC_EVALUATION_QUEUE, NULL)))->emptyP() &&
          ((List*)(dynamicSlotValue(oCONTEXTo.get()->dynamicSlots, SYM_PROPAGATE_LOGIC_FORWARD_CHAINING_QUEUE, NULL)))->emptyP()) {
        return;
      }
    }
  }
}

void evaluateNewProposition(Proposition* self) {
  if (descriptionModeP()) {
    return;
  }
  { World* world = lookupConstraintPropagationWorld(oCONTEXTo.get());

    if (((boolean)(world))) {
      { 
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, world);
        evaluateProposition(self);
        if (!unknownP(self)) {
          if (((boolean)(oTRACED_KEYWORDSo)) &&
              oTRACED_KEYWORDSo->membP(KWD_PROPAGATE_PROPAGATE)) {
            std::cout << "evaluate-new-proposition:  " << self << std::endl;
          }
          { Proposition* prop = NULL;
            Iterator* iter000 = self->dependentPropositions->allocateIterator();

            while (iter000->nextP()) {
              prop = ((Proposition*)(iter000->value));
              evaluateProposition(prop);
            }
          }
        }
      }
    }
  }
}

void evaluateAndProposition(Proposition* self) {
  { Vector* arguments = self->arguments;

    if (trueP(self)) {
      { Proposition* arg = NULL;
        Vector* vector000 = arguments;
        int index000 = 0;
        int length000 = vector000->length();

        while (index000 < length000) {
          arg = ((Proposition*)((vector000->theArray)[index000]));
          index000 = index000 + 1;
          assignTruthValue(arg, ((TruthValue*)(accessInContext(self->truthValue, self->homeContext, FALSE))));
        }
      }
    }
    else if (falseP(self)) {
      { Proposition* onlyunboundarg = NULL;
        boolean toucheddefaultP = defaultFalseP(self);

        { Proposition* arg = NULL;
          Vector* vector001 = arguments;
          int index001 = 0;
          int length001 = vector001->length();

          while (index001 < length001) {
            arg = ((Proposition*)((vector001->theArray)[index001]));
            index001 = index001 + 1;
            if (falseP(arg)) {
              return;
            }
            else if (unknownP(arg)) {
              if (((boolean)(onlyunboundarg))) {
                return;
              }
              onlyunboundarg = arg;
            }
            else if (defaultTrueP(arg)) {
              toucheddefaultP = TRUE;
            }
          }
        }
        if (((boolean)(onlyunboundarg))) {
          assignTruthValue(onlyunboundarg, defaultifyTruthValue(FALSE, toucheddefaultP));
        }
        else {
          assignTruthValue(self, defaultifyTruthValue(TRUE, toucheddefaultP));
        }
      }
    }
    else {
      { boolean unboundargP = FALSE;
        boolean toucheddefaultP = FALSE;

        { Proposition* arg = NULL;
          Vector* vector002 = arguments;
          int index002 = 0;
          int length002 = vector002->length();

          while (index002 < length002) {
            arg = ((Proposition*)((vector002->theArray)[index002]));
            index002 = index002 + 1;
            if (falseP(arg)) {
              if (defaultFalseP(arg)) {
                assignTruthValue(self, DEFAULT_FALSE_TRUTH_VALUE);
              }
              else {
                {
                  assignTruthValue(self, FALSE_WRAPPER);
                  return;
                }
              }
            }
            else if (unknownP(arg)) {
              unboundargP = TRUE;
            }
            else if (defaultTrueP(arg)) {
              toucheddefaultP = TRUE;
            }
          }
        }
        if ((!unboundargP) &&
            (!defaultFalseP(self))) {
          assignTruthValue(self, defaultifyTruthValue(TRUE, toucheddefaultP));
        }
      }
    }
  }
}

void evaluateOrProposition(Proposition* self) {
  { Vector* arguments = self->arguments;

    if (falseP(self)) {
      { Proposition* arg = NULL;
        Vector* vector000 = arguments;
        int index000 = 0;
        int length000 = vector000->length();

        while (index000 < length000) {
          arg = ((Proposition*)((vector000->theArray)[index000]));
          index000 = index000 + 1;
          assignTruthValue(arg, ((TruthValue*)(accessInContext(self->truthValue, self->homeContext, FALSE))));
        }
      }
    }
    else if (trueP(self)) {
      { Proposition* onlyunboundarg = NULL;
        boolean toucheddefaultP = defaultTrueP(self);

        { Proposition* arg = NULL;
          Vector* vector001 = arguments;
          int index001 = 0;
          int length001 = vector001->length();

          while (index001 < length001) {
            arg = ((Proposition*)((vector001->theArray)[index001]));
            index001 = index001 + 1;
            if (trueP(arg)) {
              return;
            }
            else if (unknownP(arg)) {
              if (((boolean)(onlyunboundarg))) {
                return;
              }
              onlyunboundarg = arg;
            }
            else if (defaultFalseP(arg)) {
              toucheddefaultP = TRUE;
            }
          }
        }
        if (((boolean)(onlyunboundarg))) {
          assignTruthValue(onlyunboundarg, defaultifyTruthValue(TRUE, toucheddefaultP));
        }
        else {
          assignTruthValue(self, defaultifyTruthValue(FALSE, toucheddefaultP));
        }
      }
    }
    else {
      { boolean unboundargP = FALSE;
        boolean toucheddefaultP = FALSE;

        { Proposition* arg = NULL;
          Vector* vector002 = arguments;
          int index002 = 0;
          int length002 = vector002->length();

          while (index002 < length002) {
            arg = ((Proposition*)((vector002->theArray)[index002]));
            index002 = index002 + 1;
            if (trueP(arg)) {
              if (defaultTrueP(arg)) {
                assignTruthValue(self, DEFAULT_TRUE_TRUTH_VALUE);
              }
              else {
                {
                  assignTruthValue(self, TRUE_WRAPPER);
                  return;
                }
              }
            }
            else if (unknownP(arg)) {
              unboundargP = TRUE;
            }
            else if (defaultFalseP(arg)) {
              toucheddefaultP = TRUE;
            }
          }
        }
        if ((!unboundargP) &&
            (!defaultTrueP(self))) {
          assignTruthValue(self, defaultifyTruthValue(FALSE, toucheddefaultP));
        }
      }
    }
  }
}

void evaluateNotProposition(Proposition* self) {
  { Proposition* argument = ((Proposition*)((self->arguments->theArray)[0]));

    if (trueP(argument) ||
        falseP(argument)) {
      assignTruthValue(self, invertTruthValue(((TruthValue*)(accessInContext(argument->truthValue, argument->homeContext, FALSE)))));
    }
    if (trueP(self) ||
        falseP(self)) {
      assignTruthValue(argument, invertTruthValue(((TruthValue*)(accessInContext(self->truthValue, self->homeContext, FALSE)))));
    }
  }
}

void evaluateEquivalentProposition(Proposition* self) {
  { Vector* arguments = self->arguments;
    Object* firstarg = innermostOf((arguments->theArray)[0]);
    Object* secondarg = innermostOf((arguments->theArray)[1]);

    if (trueP(self)) {
      if (defaultTrueP(self)) {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "INTERNAL ERROR: DON'T KNOW YET HOW TO EQUATE THINGS BY DEFAULT." << std::endl;
      }
      equateValues(firstarg, secondarg);
    }
    else if (eqlP(firstarg, secondarg)) {
      assignTruthValue(self, TRUE_WRAPPER);
    }
    else if ((!skolemP(firstarg)) &&
        (!skolemP(secondarg))) {
      assignTruthValue(self, FALSE_WRAPPER);
    }
  }
}

void equateEquivalentFunctionPropositions(Proposition* self) {
  { Surrogate* relationref = ((Surrogate*)(self->operatoR));
    int nofargs = self->arguments->length();
    List* candidatepropositions = newList();

    { Object* arg = NULL;
      int i = NULL_INTEGER;
      Vector* vector000 = self->arguments;
      int index000 = 0;
      int length000 = vector000->length();
      int iter000 = 1;

      while (index000 < length000) {
        arg = (vector000->theArray)[index000];
        index000 = index000 + 1;
        i = iter000;
        iter000 = iter000 + 1;
        if (!(i == nofargs)) {
          { Surrogate* testValue000 = safePrimaryType(arg);

            if (subtypeOfP(testValue000, SGT_PROPAGATE_LOGIC_SKOLEM)) {
              { Object* arg000 = arg;
                Skolem* arg = ((Skolem*)(arg000));

                if (((boolean)(((Object*)(accessInContext(arg->variableValue, arg->homeContext, FALSE))))) &&
                    isaP(((Object*)(accessInContext(arg->variableValue, arg->homeContext, FALSE))), SGT_PROPAGATE_LOGIC_LOGIC_OBJECT)) {
                  { Proposition* prop = NULL;
                    Iterator* iter001 = unfilteredDependentPropositions(((Object*)(accessInContext(arg->variableValue, arg->homeContext, FALSE))), relationref)->allocateIterator();

                    while (iter001->nextP()) {
                      prop = ((Proposition*)(iter001->value));
                      if ((((Surrogate*)(prop->operatoR)) == relationref) &&
                          (!(prop == self))) {
                        candidatepropositions->insertNew(prop);
                      }
                    }
                  }
                }
                { LogicObject* invarg = NULL;
                  Cons* iter002 = arg->variableValueInverse_reader();

                  while (!(iter002 == NIL)) {
                    invarg = ((LogicObject*)(iter002->value));
                    iter002 = iter002->rest;
                    { Proposition* prop = NULL;
                      Iterator* iter003 = unfilteredDependentPropositions(invarg, relationref)->allocateIterator();

                      while (iter003->nextP()) {
                        prop = ((Proposition*)(iter003->value));
                        if ((((Surrogate*)(prop->operatoR)) == relationref) &&
                            (!(prop == self))) {
                          candidatepropositions->insertNew(prop);
                        }
                      }
                    }
                  }
                }
              }
            }
            else if (subtypeOfP(testValue000, SGT_PROPAGATE_LOGIC_LOGIC_OBJECT)) {
              { Object* arg001 = arg;
                LogicObject* arg = ((LogicObject*)(arg001));

                { LogicObject* invarg = NULL;
                  Cons* iter004 = arg->variableValueInverse_reader();

                  while (!(iter004 == NIL)) {
                    invarg = ((LogicObject*)(iter004->value));
                    iter004 = iter004->rest;
                    { Proposition* prop = NULL;
                      Iterator* iter005 = unfilteredDependentPropositions(invarg, relationref)->allocateIterator();

                      while (iter005->nextP()) {
                        prop = ((Proposition*)(iter005->value));
                        if ((((Surrogate*)(prop->operatoR)) == relationref) &&
                            (!(prop == self))) {
                          candidatepropositions->insertNew(prop);
                        }
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
      }
    }
    { Proposition* prop = NULL;
      Cons* iter006 = candidatepropositions->theConsList;

      while (!(iter006 == NIL)) {
        prop = ((Proposition*)(iter006->value));
        iter006 = iter006->rest;
        { boolean alwaysP000 = TRUE;

          { Object* arg1 = NULL;
            Object* arg2 = NULL;
            int i = NULL_INTEGER;
            Vector* vector001 = self->arguments;
            int index001 = 0;
            int length001 = vector001->length();
            Vector* vector002 = prop->arguments;
            int index002 = 0;
            int length002 = vector002->length();
            int iter007 = 1;

            while ((index001 < length001) &&
                (index002 < length002)) {
              arg1 = (vector001->theArray)[index001];
              index001 = index001 + 1;
              arg2 = (vector002->theArray)[index002];
              index002 = index002 + 1;
              i = iter007;
              iter007 = iter007 + 1;
              if (!(i == nofargs)) {
                if (!eqlP(innermostOf(arg1), innermostOf(arg2))) {
                  alwaysP000 = FALSE;
                  break;
                }
              }
            }
          }
          if (alwaysP000) {
            equateValues(innermostOf(self->arguments->last()), innermostOf(prop->arguments->last()));
          }
        }
      }
    }
    candidatepropositions->free();
  }
}

void evaluateFunctionProposition(Proposition* self) {
  if (isaP(self->operatoR, SGT_PROPAGATE_STELLA_SYMBOL)) {
    return;
  }
  equateEquivalentFunctionPropositions(self);
  { NamedDescription* description = getDescription(((Surrogate*)(self->operatoR)));
    cpp_function_code code = lookupConstraint(description);
    Cons* boundarguments = NIL;
    Object* computedvalue = NULL;
    Object* storedvalue = NULL;
    int missingvalueindex = -1;

    if (code != NULL) {
      { Object* arg = NULL;
        int i = NULL_INTEGER;
        Vector* vector000 = self->arguments;
        int index000 = 0;
        int length000 = vector000->length();
        int iter000 = 0;
        Cons* collect000 = NULL;

        while (index000 < length000) {
          arg = (vector000->theArray)[index000];
          index000 = index000 + 1;
          i = iter000;
          iter000 = iter000 + 1;
          if (isaP(valueOf(arg), SGT_PROPAGATE_LOGIC_SKOLEM)) {
            if (missingvalueindex == -1) {
              {
                missingvalueindex = i;
                arg = NULL;
              }
            }
            else {
              return;
            }
          }
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(valueOf(arg), NIL);
              if (boundarguments == NIL) {
                boundarguments = collect000;
              }
              else {
                addConsToEndOfConsList(boundarguments, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(valueOf(arg), NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      if (missingvalueindex == -1) {
        return;
      }
      computedvalue = apply(code, cons(wrapInteger(missingvalueindex), boundarguments));
      storedvalue = valueOf((self->arguments->theArray)[missingvalueindex]);
      if ((!eqlP(computedvalue, storedvalue)) &&
          ((boolean)(computedvalue))) {
        equateValues(computedvalue, storedvalue);
      }
      return;
    }
    code = lookupComputation(description);
    if (code != NULL) {
      { Object* arg = NULL;
        Iterator* iter001 = self->arguments->butLast();
        Cons* collect001 = NULL;

        while (iter001->nextP()) {
          arg = iter001->value;
          if (isaP(valueOf(arg), SGT_PROPAGATE_LOGIC_SKOLEM)) {
            return;
          }
          if (!((boolean)(collect001))) {
            {
              collect001 = cons(valueOf(arg), NIL);
              if (boundarguments == NIL) {
                boundarguments = collect001;
              }
              else {
                addConsToEndOfConsList(boundarguments, collect001);
              }
            }
          }
          else {
            {
              collect001->rest = cons(valueOf(arg), NIL);
              collect001 = collect001->rest;
            }
          }
        }
      }
      computedvalue = apply(code, boundarguments);
      storedvalue = valueOf((self->arguments->theArray)[(self->arguments->length() - 1)]);
      if ((!eqlP(computedvalue, storedvalue)) &&
          ((boolean)(computedvalue))) {
        equateValues(computedvalue, storedvalue);
      }
    }
  }
}

void evaluatePredicateProposition(Proposition* self) {
  { NamedDescription* description = getDescription(((Surrogate*)(self->operatoR)));
    cpp_function_code code = lookupConstraint(description);
    Cons* boundarguments = NIL;
    boolean successP = FALSE;

    if (code != NULL) {
      { Object* arg = NULL;
        Vector* vector000 = self->arguments;
        int index000 = 0;
        int length000 = vector000->length();
        Cons* collect000 = NULL;

        while (index000 < length000) {
          arg = (vector000->theArray)[index000];
          index000 = index000 + 1;
          if (isaP(valueOf(arg), SGT_PROPAGATE_LOGIC_SKOLEM)) {
            return;
          }
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(arg, NIL);
              if (boundarguments == NIL) {
                boundarguments = collect000;
              }
              else {
                addConsToEndOfConsList(boundarguments, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(arg, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      successP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(apply(code, cons(wrapInteger(-1), boundarguments)))));
      assignTruthValue(self, (successP ? TRUE_WRAPPER : FALSE_WRAPPER));
      return;
    }
    code = lookupComputation(description);
    if (code != NULL) {
      { Object* arg = NULL;
        Vector* vector001 = self->arguments;
        int index001 = 0;
        int length001 = vector001->length();
        Cons* collect001 = NULL;

        while (index001 < length001) {
          arg = (vector001->theArray)[index001];
          index001 = index001 + 1;
          if (isaP(valueOf(arg), SGT_PROPAGATE_LOGIC_SKOLEM)) {
            return;
          }
          if (!((boolean)(collect001))) {
            {
              collect001 = cons(arg, NIL);
              if (boundarguments == NIL) {
                boundarguments = collect001;
              }
              else {
                addConsToEndOfConsList(boundarguments, collect001);
              }
            }
          }
          else {
            {
              collect001->rest = cons(arg, NIL);
              collect001 = collect001->rest;
            }
          }
        }
      }
      successP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(apply(code, boundarguments))));
      assignTruthValue(self, (successP ? TRUE_WRAPPER : FALSE_WRAPPER));
    }
  }
}

void evaluateProposition(Proposition* self) {
  evaluationStateSetter(self, KWD_PROPAGATE_EVALUATED);
  { Keyword* testValue000 = self->kind;

    if (testValue000 == KWD_PROPAGATE_AND) {
      evaluateAndProposition(self);
    }
    else if (testValue000 == KWD_PROPAGATE_OR) {
      evaluateOrProposition(self);
    }
    else if (testValue000 == KWD_PROPAGATE_NOT) {
      evaluateNotProposition(self);
    }
    else if (testValue000 == KWD_PROPAGATE_EQUIVALENT) {
      evaluateEquivalentProposition(self);
    }
    else if (testValue000 == KWD_PROPAGATE_ISA) {
    }
    else if ((testValue000 == KWD_PROPAGATE_FUNCTION) ||
        (testValue000 == KWD_PROPAGATE_PREDICATE)) {
      { NamedDescription* description = getDescription(((Surrogate*)(self->operatoR)));
        cpp_function_code evaluator = lookupEvaluator(description);

        if (evaluator != NULL) {
          ((void  (*) (Proposition*))evaluator)(self);
        }
        else if (self->kind == KWD_PROPAGATE_PREDICATE) {
          evaluatePredicateProposition(self);
        }
        else {
          evaluateFunctionProposition(self);
        }
      }
    }
    else {
    }
  }
}

void LogicObject::markAsIncoherent() {
  { LogicObject* self = this;

  }
}

void Skolem::markAsIncoherent() {
  { Skolem* self = this;

    if (((boolean)(self->definingProposition))) {
      { Object* firstarg = (self->definingProposition->arguments->theArray)[0];

        if (subtypeOfP(safePrimaryType(firstarg), SGT_PROPAGATE_LOGIC_LOGIC_OBJECT)) {
          { Object* firstarg000 = firstarg;
            LogicObject* firstarg = ((LogicObject*)(firstarg000));

            firstarg->markAsIncoherent();
            return;
          }
        }
        else {
        }
      }
    }
  }
}

// If TRUE, ensures that forward propagation has
// been applied to each instance 'touched' during a query.
boolean oJUST_IN_TIME_FORWARD_INFERENCEpo = FALSE;

List* LogicObject::elaboratedInWorlds_reader() {
  { LogicObject* self = this;

    { List* answer = ((List*)(dynamicSlotValue(self->dynamicSlots, SYM_PROPAGATE_LOGIC_ELABORATED_IN_WORLDS, NULL)));

      if (!((boolean)(answer))) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

void recursivelyReactToInferenceUpdate(Proposition* self) {
  self->reactToInferenceUpdate();
  { Object* arg = NULL;
    Vector* vector000 = self->arguments;
    int index000 = 0;
    int length000 = vector000->length();

    while (index000 < length000) {
      arg = (vector000->theArray)[index000];
      index000 = index000 + 1;
      if (isaP(arg, SGT_PROPAGATE_LOGIC_PROPOSITION)) {
        recursivelyReactToInferenceUpdate(((Proposition*)(arg)));
      }
    }
  }
}

void elaborateMetaInstance(Object* self) {
  { Context* worldstate = getWorldState(oCONTEXTo.get());
    World* metaworld = getInferenceCache(worldstate, KWD_PROPAGATE_META);

    { 
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, metaworld);
      elaborateInstance(self);
    }
  }
}

void elaborateInstance(Object* self) {
  if (oFILLINGCONSTRAINTPROPAGATIONQUEUESpo.get()) {
    return;
  }
  if (oJUST_IN_TIME_FORWARD_INFERENCEpo) {
    if (subtypeOfP(safePrimaryType(self), SGT_PROPAGATE_LOGIC_LOGIC_OBJECT)) {
      { Object* self000 = self;
        LogicObject* self = ((LogicObject*)(self000));

        if (self->elaboratedInWorlds_reader()->memberP(oCONTEXTo.get())) {
          return;
        }
        if (((boolean)(oTRACED_KEYWORDSo)) &&
            oTRACED_KEYWORDSo->membP(KWD_PROPAGATE_ELABORATE)) {
          std::cout << " ELABORATING:  " << self << " in world " << oCONTEXTo.get() << std::endl;
        }
        if (self->elaboratedInWorlds_reader() == NIL_LIST) {
          setDynamicSlotValue(self->dynamicSlots, SYM_PROPAGATE_LOGIC_ELABORATED_IN_WORLDS, list(0), NULL);
        }
        else {
          self->elaboratedInWorlds_reader()->removeDeletedMembers();
        }
        self->elaboratedInWorlds_reader()->push(((World*)(oCONTEXTo.get())));
        { 
          BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_PROPAGATE_EXTENSIONAL_ASSERTION);
          BIND_STELLA_SPECIAL(oINHIBITOBJECTFINALIZATIONpo, boolean, TRUE);
          BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, NULL);
          try {
            initializeConstraintPropagationQueues(((World*)(oCONTEXTo.get())));
            { 
              BIND_STELLA_SPECIAL(oFILLINGCONSTRAINTPROPAGATIONQUEUESpo, boolean, TRUE);
              evaluateReachableInequalities(self, list(0));
              { Proposition* prop = NULL;
                Cons* iter000 = allFactsOfInstance(self, TRUE, FALSE)->theConsList;

                while (!(iter000 == NIL)) {
                  prop = ((Proposition*)(iter000->value));
                  iter000 = iter000->rest;
                  recursivelyReactToInferenceUpdate(prop);
                }
              }
              { 
                BIND_STELLA_SPECIAL(oDEFERINGDEFAULTFORWARDINFERENCESpo, boolean, TRUE);
                executeConstraintPropagationQueues();
              }
              { Proposition* p = NULL;
                Cons* iter001 = deferredDefaultPropositions(oCONTEXTo.get());

                while (!(iter001 == NIL)) {
                  p = ((Proposition*)(iter001->value));
                  iter001 = iter001->rest;
                  assignTruthValue(p, DEFAULT_TRUE_TRUTH_VALUE);
                }
              }
              deferredDefaultPropositionsSetter(oCONTEXTo.get(), NIL);
            }
            executeConstraintPropagationQueues();
          }
          catch (Clash& _e) {
            Clash* e = &_e;

            *(STANDARD_ERROR->nativeStream) << exceptionMessage(e) << std::endl;
          }
        }
      }
    }
    else {
    }
  }
}

void evaluateReachableInequalities(LogicObject* self, List* visitedlist) {
  { Proposition* p = NULL;
    Iterator* iter000 = allTrueDependentPropositions(self, SGT_PROPAGATE_PL_KERNEL_KB_INEQUALITY, TRUE);

    while (iter000->nextP()) {
      p = ((Proposition*)(iter000->value));
      if (!((boolean)(evaluationState(p)))) {
        postForEvaluation(p);
      }
      visitedlist->push(self);
      { Object* arg = NULL;
        Vector* vector000 = p->arguments;
        int index000 = 0;
        int length000 = vector000->length();

        while (index000 < length000) {
          arg = (vector000->theArray)[index000];
          index000 = index000 + 1;
          if ((!visitedlist->memberP(arg)) &&
              isaP(arg, SGT_PROPAGATE_LOGIC_LOGIC_OBJECT)) {
            evaluateReachableInequalities(((LogicObject*)(arg)), visitedlist);
          }
        }
      }
    }
  }
}

void elaborateSurrogatesInProposition(Proposition* proposition) {
  if (oJUST_IN_TIME_FORWARD_INFERENCEpo) {
    { Keyword* testValue000 = proposition->kind;

      if ((testValue000 == KWD_PROPAGATE_PREDICATE) ||
          ((testValue000 == KWD_PROPAGATE_FUNCTION) ||
           (testValue000 == KWD_PROPAGATE_ISA))) {
        elaborateMetaInstance(getDescription(((Surrogate*)(proposition->operatoR))));
        { Object* arg = NULL;
          Vector* vector000 = proposition->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          while (index000 < length000) {
            arg = (vector000->theArray)[index000];
            index000 = index000 + 1;
            if (isaP(arg, SGT_PROPAGATE_STELLA_SURROGATE)) {
              { Object* value = valueOf(arg);

                if (((boolean)(value))) {
                  elaborateInstance(value);
                }
              }
            }
          }
        }
      }
      else if ((testValue000 == KWD_PROPAGATE_AND) ||
          ((testValue000 == KWD_PROPAGATE_OR) ||
           ((testValue000 == KWD_PROPAGATE_NOT) ||
            ((testValue000 == KWD_PROPAGATE_EXISTS) ||
             (testValue000 == KWD_PROPAGATE_FORALL))))) {
        { Object* p = NULL;
          Vector* vector001 = proposition->arguments;
          int index001 = 0;
          int length001 = vector001->length();

          while (index001 < length001) {
            p = (vector001->theArray)[index001];
            index001 = index001 + 1;
            elaborateSurrogatesInProposition(((Proposition*)(p)));
          }
        }
      }
      else {
      }
    }
  }
}

void collectFunctionPropositionFacts(Proposition* self, List* facts, List* beenthere, boolean includeunknownP) {
  beenthere->insert(self);
  { Object* outputskolem = (self->arguments->theArray)[(self->arguments->length() - 1)];
    Object* value = valueOf(outputskolem);
    boolean hasassertedvalueP = !eqlP(value, outputskolem);

    if (hasassertedvalueP) {
      if (!facts->memberP(self)) {
        facts->insert(self);
      }
    }
    if ((!hasassertedvalueP) ||
        (nativeValueP(value) &&
         (!isaP(value, SGT_PROPAGATE_STELLA_LITERAL_WRAPPER)))) {
      helpCollectFacts(outputskolem, facts, beenthere, includeunknownP);
    }
  }
}

void helpCollectFacts(Object* self, List* facts, List* beenthere, boolean includeunknownP) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_PROPAGATE_LOGIC_LOGIC_OBJECT)) {
      { Object* self000 = self;
        LogicObject* self = ((LogicObject*)(self000));

        { Proposition* p = NULL;
          Iterator* iter000 = unfilteredDependentPropositions(self, NULL)->allocateIterator();

          while (iter000->nextP()) {
            p = ((Proposition*)(iter000->value));
            if (!beenthere->memberP(p)) {
              if (p->kind == KWD_PROPAGATE_FUNCTION) {
                collectFunctionPropositionFacts(p, facts, beenthere, includeunknownP);
              }
              else {
                helpCollectFacts(p, facts, beenthere, includeunknownP);
              }
            }
          }
        }
        { LogicObject* equivalent = NULL;
          Cons* iter001 = self->variableValueInverse_reader();

          while (!(iter001 == NIL)) {
            equivalent = ((LogicObject*)(iter001->value));
            iter001 = iter001->rest;
            helpCollectFacts(equivalent, facts, beenthere, includeunknownP);
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_PROPAGATE_LOGIC_PROPOSITION)) {
      { Object* self001 = self;
        Proposition* self = ((Proposition*)(self001));

        beenthere->insert(self);
        if ((!unknownP(self)) ||
            includeunknownP) {
          facts->insert(self);
        }
        { Proposition* p = NULL;
          Iterator* iter002 = self->dependentPropositions->allocateIterator();

          while (iter002->nextP()) {
            p = ((Proposition*)(iter002->value));
            if (!beenthere->memberP(p)) {
              helpCollectFacts(p, facts, beenthere, includeunknownP);
            }
          }
        }
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* self002 = self;
        Surrogate* self = ((Surrogate*)(self002));

        if (((boolean)(self->surrogateValue))) {
          helpCollectFacts(self->surrogateValue, facts, beenthere, includeunknownP);
        }
      }
    }
    else if (subtypeOfClassP(testValue000)) {
      { Object* self003 = self;
        Class* self = ((Class*)(self003));

        if (((boolean)(((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_PROPAGATE_LOGIC_DESCRIPTION, NULL)))))) {
          helpCollectFacts(((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_PROPAGATE_LOGIC_DESCRIPTION, NULL))), facts, beenthere, includeunknownP);
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_PROPAGATE_STELLA_SLOT)) {
      { Object* self004 = self;
        Slot* self = ((Slot*)(self004));

        if (((boolean)(((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_PROPAGATE_LOGIC_DESCRIPTION, NULL)))))) {
          helpCollectFacts(((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_PROPAGATE_LOGIC_DESCRIPTION, NULL))), facts, beenthere, includeunknownP);
        }
      }
    }
    else {
    }
  }
}

List* allFactsOfInstance(Object* self, boolean includeunknownfactsP, boolean elaborateP) {
  // Return a list of all definite (TRUE or FALSE) propositions
  // attached to `self'.
  { List* facts = newList();
    List* beenthere = newList();

    { 
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, getQueryContext());
      BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
      if (elaborateP) {
        elaborateInstance(self);
      }
      helpCollectFacts(self, facts, beenthere, includeunknownfactsP);
    }
    return (facts);
  }
}

Cons* allFactsOf(Object* instanceref) {
  // Return a cons list of all definite (TRUE or FALSE) propositions
  // that reference the instance `instanceRef'.  This includes propositions
  // asserted to be true by default, but it does not include propositions
  // that are found to be TRUE only by running the query engine.  Facts
  // inferred to be TRUE by the forward chainer will be included.
  // Hence, the returned list of facts may be longer in a context where the
  // forward chainer has been run then in one where it has not (see
  // `run-forward-rules').
  { LogicObject* instance = coerceToInstance(instanceref, NULL);

    if (((boolean)(instance))) {
      return (allFactsOfInstance(instance, FALSE, TRUE)->theConsList);
    }
    else {
      return (NULL);
    }
  }
}

List* callAllFactsOf(Object* instanceref) {
  // Return a list of all definite (TRUE or FALSE) propositions
  // that reference the instance `instanceRef'.
  { LogicObject* instance = coerceToInstance(instanceref, NULL);

    if (((boolean)(instance))) {
      return (allFactsOfInstance(instance, FALSE, TRUE));
    }
    else {
      return (NULL);
    }
  }
}

void retractFactsOfInstance(LogicObject* self) {
  // Retract all definite (TRUE or FALSE) propositions attached to `self'.
  if (!((boolean)(self))) {
    return;
  }
  { Proposition* p = NULL;
    Cons* iter000 = allFactsOfInstance(self, FALSE, TRUE)->theConsList;

    while (!(iter000 == NIL)) {
      p = ((Proposition*)(iter000->value));
      iter000 = iter000->rest;
      if (p->kind == KWD_PROPAGATE_FUNCTION) {
        { Skolem* skolem = ((Skolem*)(p->arguments->last()));

          if (skolem == self) {
            continue;
          }
          if (((boolean)(skolem)) &&
              ((boolean)(((Object*)(accessInContext(skolem->variableValue, skolem->homeContext, FALSE)))))) {
            unassertProposition(p);
          }
          retractFactsOfInstance(skolem);
        }
      }
      else {
        unassertProposition(p);
      }
    }
  }
}

void retractFactsOf(Object* instanceref) {
  // Retract all definite (TRUE or FALSE) propositions
  // that reference the instance `instanceRef'.
  { LogicObject* instance = coerceToInstance(instanceref, NULL);

    if (((boolean)(instance))) {
      retractFactsOfInstance(instance);
    }
  }
}

List* explodeVariablizedString(char* string) {
  { List* list = newList();
    int endofstring = strlen(string);
    int begin = 0;
    int end = NULL_INTEGER;
    char* substring = NULL;
    Symbol* symbol = NULL;

    for (;;) {
      if (begin >= endofstring) {
        return (list);
      }
      end = stringPosition(string, '?', begin);
      if (end == NULL_INTEGER) {
        substring = stringSubsequence(string, begin, endofstring);
        list->insertLast(wrapString(substring));
        return (list);
      }
      else if (end > begin) {
        substring = stringSubsequence(string, begin, end);
        list->insertLast(wrapString(substring));
      }
      begin = end;
      end = stringPosition(string, ' ', begin);
      if (end == NULL_INTEGER) {
        end = endofstring;
      }
      substring = stringSubsequence(string, begin, end);
      symbol = internSymbol(stringUpcase(substring));
      list->insertLast(symbol);
      begin = end;
    }
  }
}

char* factToSentence(Proposition* self, boolean periodP) {
  { Keyword* testValue000 = self->kind;

    if ((testValue000 == KWD_PROPAGATE_PREDICATE) ||
        ((testValue000 == KWD_PROPAGATE_FUNCTION) ||
         (testValue000 == KWD_PROPAGATE_ISA))) {
      { NamedDescription* relation = ((NamedDescription*)(((Surrogate*)(self->operatoR))->surrogateValue));
        Object* phrase = accessBinaryValue(relation, SGT_PROPAGATE_PL_KERNEL_KB_PHRASE);
        List* explodedstring = (((boolean)(phrase)) ? explodeVariablizedString(((StringWrapper*)(phrase))->wrapperValue) : ((List*)(NULL)));

        if (((boolean)(explodedstring))) {
          { KeyValueList* table = newKeyValueList();
            char* sentence = "";

            { Symbol* vbl = NULL;
              Object* arg = NULL;
              Cons* iter000 = relation->ioVariableNames->theConsList;
              Vector* vector000 = self->arguments;
              int index000 = 0;
              int length000 = vector000->length();

              while ((!(iter000 == NIL)) &&
                  (index000 < length000)) {
                vbl = ((Symbol*)(iter000->value));
                iter000 = iter000->rest;
                arg = (vector000->theArray)[index000];
                index000 = index000 + 1;
                table->insertAt(vbl, arg);
              }
            }
            { Object* item = NULL;
              Cons* iter001 = explodedstring->theConsList;

              while (!(iter001 == NIL)) {
                item = iter001->value;
                iter001 = iter001->rest;
                { Object* value = NULL;
                  char* stringvalue = NULL;

                  { Surrogate* testValue001 = safePrimaryType(item);

                    if (subtypeOfSymbolP(testValue001)) {
                      { Object* item000 = item;
                        Symbol* item = ((Symbol*)(item000));

                        value = table->lookup(item);
                        if (((boolean)(value))) {
                          { Surrogate* testValue002 = safePrimaryType(value);

                            if (subtypeOfP(testValue002, SGT_PROPAGATE_LOGIC_SKOLEM)) {
                              { Object* value000 = value;
                                Skolem* value = ((Skolem*)(value000));

                                { Surrogate* surrogate = ((LogicObject*)(value))->surrogateValueInverse;
                                  Proposition* definingproposition = value->definingProposition;

                                  if (((boolean)(definingproposition))) {
                                    stringvalue = factToSentence(definingproposition, FALSE);
                                  }
                                  else if (((boolean)(surrogate))) {
                                    stringvalue = surrogate->symbolName;
                                  }
                                  else {
                                    stringvalue = ((Skolem*)(value))->skolemName->symbolName;
                                  }
                                }
                              }
                            }
                            else if (subtypeOfP(testValue002, SGT_PROPAGATE_LOGIC_LOGIC_OBJECT)) {
                              { Object* value001 = value;
                                LogicObject* value = ((LogicObject*)(value001));

                                { Surrogate* surrogate = ((LogicObject*)(value))->surrogateValueInverse;

                                  if (((boolean)(surrogate))) {
                                    stringvalue = surrogate->symbolName;
                                  }
                                }
                              }
                            }
                            else if (subtypeOfStringP(testValue002)) {
                              { Object* value002 = value;
                                StringWrapper* value = ((StringWrapper*)(value002));

                                stringvalue = stringConcatenate("'", value->wrapperValue, 1, "'");
                              }
                            }
                            else if (subtypeOfIntegerP(testValue002)) {
                              { Object* value003 = value;
                                IntegerWrapper* value = ((IntegerWrapper*)(value003));

                                stringvalue = integerToString(value->wrapperValue);
                              }
                            }
                            else if (subtypeOfFloatP(testValue002)) {
                              { Object* value004 = value;
                                FloatWrapper* value = ((FloatWrapper*)(value004));

                                stringvalue = floatToString(value->wrapperValue);
                              }
                            }
                            else {
                            }
                          }
                        }
                        if (stringvalue != NULL) {
                          sentence = stringConcatenate(sentence, stringvalue, 0);
                        }
                        else {
                          sentence = stringConcatenate(sentence, item->symbolName, 0);
                        }
                      }
                    }
                    else if (subtypeOfStringP(testValue001)) {
                      { Object* item001 = item;
                        StringWrapper* item = ((StringWrapper*)(item001));

                        sentence = stringConcatenate(sentence, item->wrapperValue, 0);
                      }
                    }
                    else {
                      { OutputStringStream* stream000 = newOutputStringStream();

                        *(stream000->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
                        throw *newStellaException(stream000->theStringReader());
                      }
                    }
                  }
                }
              }
            }
            if (periodP) {
              sentence = stringConcatenate(sentence, ".", 0);
            }
            return (sentence);
          }
        }
        return (NULL);
      }
    }
    else if (testValue000 == KWD_PROPAGATE_IMPLIES) {
      return ("rules not yet implemented");
    }
    else {
      return ("???");
    }
  }
}

Cons* allSentencesOf(Object* instanceref) {
  // Return a list of sentences describing facts about 'instanceRef'.
  { LogicObject* instance = coerceToInstance(instanceref, NULL);
    char* sentence = NULL;

    if (((boolean)(instance))) {
      { Cons* list = NIL;

        { Proposition* fact = NULL;
          Cons* iter000 = allFactsOfInstance(instance, FALSE, TRUE)->theConsList;
          Cons* collect000 = NULL;

          while (!(iter000 == NIL)) {
            fact = ((Proposition*)(iter000->value));
            iter000 = iter000->rest;
            sentence = factToSentence(fact, TRUE);
            if (sentence == NULL) {
              continue;
            }
            if (!((boolean)(collect000))) {
              {
                collect000 = cons(wrapString(sentence), NIL);
                if (list == NIL) {
                  list = collect000;
                }
                else {
                  addConsToEndOfConsList(list, collect000);
                }
              }
            }
            else {
              {
                collect000->rest = cons(wrapString(sentence), NIL);
                collect000 = collect000->rest;
              }
            }
          }
        }
        return (list);
      }
    }
    else {
      return (NULL);
    }
  }
}

List* callAllFactsOfN(int n, Cons* seedrefs) {
  { HashTable* visited = newHashTable();
    HashTable* facts = newHashTable();
    List* factlist = newList();
    List* seeds = newList();
    List* newseeds = newList();
    Object* instance = NULL;

    { Object* seedref = NULL;
      Cons* iter000 = seedrefs;

      while (!(iter000 == NIL)) {
        seedref = iter000->value;
        iter000 = iter000->rest;
        instance = coerceToInstance(seedref, NULL);
        if (((boolean)(instance))) {
          seeds->insertNew(instance);
        }
      }
    }
    { int i = NULL_INTEGER;
      int iter001 = 0;
      int upperBound000 = ((n != NULL_INTEGER) ? n : 0);
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;

      while (unboundedP000 ||
          (iter001 <= upperBound000)) {
        i = iter001;
        iter001 = iter001 + 1;
        i = i;
        { Object* seed = NULL;
          Cons* iter002 = seeds->theConsList;

          while (!(iter002 == NIL)) {
            seed = iter002->value;
            iter002 = iter002->rest;
            visited->insertAt(seed, seed);
          }
        }
        { Object* seed = NULL;
          Cons* iter003 = seeds->theConsList;

          while (!(iter003 == NIL)) {
            seed = iter003->value;
            iter003 = iter003->rest;
            { Proposition* prop = NULL;
              Cons* iter004 = allFactsOfInstance(seed, FALSE, TRUE)->theConsList;

              while (!(iter004 == NIL)) {
                prop = ((Proposition*)(iter004->value));
                iter004 = iter004->rest;
                if (((boolean)(((Proposition*)(facts->lookup(prop)))))) {
                  continue;
                }
                facts->insertAt(prop, prop);
                factlist->insert(prop);
                { Object* arg = NULL;
                  Vector* vector000 = prop->arguments;
                  int index000 = 0;
                  int length000 = vector000->length();

                  while (index000 < length000) {
                    arg = (vector000->theArray)[index000];
                    index000 = index000 + 1;
                    if (!((boolean)(visited->lookup(arg)))) {
                      newseeds->insertNew(arg);
                    }
                  }
                }
              }
            }
          }
        }
        seeds = newseeds;
        newseeds = newList();
      }
    }
    return (factlist->reverse());
  }
}

List* filteredAllFactsOfN(int n, Cons* seedrefs, cpp_function_code filter) {
  { HashTable* visited = newHashTable();
    HashTable* facts = newHashTable();
    List* factlist = newList();
    List* seeds = newList();
    List* newseeds = newList();
    Object* instance = NULL;

    { Object* seedref = NULL;
      Cons* iter000 = seedrefs;

      while (!(iter000 == NIL)) {
        seedref = iter000->value;
        iter000 = iter000->rest;
        instance = coerceToInstance(seedref, NULL);
        if (((boolean)(instance))) {
          seeds->insertNew(instance);
        }
      }
    }
    { int i = NULL_INTEGER;
      int iter001 = 0;
      int upperBound000 = ((n != NULL_INTEGER) ? n : 0);
      boolean unboundedP000 = upperBound000 == NULL_INTEGER;

      while (unboundedP000 ||
          (iter001 <= upperBound000)) {
        i = iter001;
        iter001 = iter001 + 1;
        i = i;
        { Object* seed = NULL;
          Cons* iter002 = seeds->theConsList;

          while (!(iter002 == NIL)) {
            seed = iter002->value;
            iter002 = iter002->rest;
            visited->insertAt(seed, seed);
          }
        }
        { Object* seed = NULL;
          Cons* iter003 = seeds->theConsList;

          while (!(iter003 == NIL)) {
            seed = iter003->value;
            iter003 = iter003->rest;
            { Proposition* prop = NULL;
              Cons* iter004 = allFactsOfInstance(seed, FALSE, TRUE)->theConsList;

              while (!(iter004 == NIL)) {
                prop = ((Proposition*)(iter004->value));
                iter004 = iter004->rest;
                if (((boolean)(((Proposition*)(facts->lookup(prop)))))) {
                  continue;
                }
                { Cons* filteroutput = ((Cons*  (*) (Proposition*))filter)(prop);
                  Cons* factprops = ((Cons*)(filteroutput->value));
                  Cons* propseeds = ((Cons*)(filteroutput->rest->value));

                  { Proposition* factprop = NULL;
                    Cons* iter005 = factprops;

                    while (!(iter005 == NIL)) {
                      factprop = ((Proposition*)(iter005->value));
                      iter005 = iter005->rest;
                      facts->insertAt(factprop, factprop);
                      factlist->insert(factprop);
                    }
                  }
                  { Object* arg = NULL;
                    Cons* iter006 = propseeds;

                    while (!(iter006 == NIL)) {
                      arg = iter006->value;
                      iter006 = iter006->rest;
                      if (!((boolean)(visited->lookup(arg)))) {
                        newseeds->insertNew(arg);
                      }
                    }
                  }
                }
              }
            }
          }
        }
        seeds = newseeds;
        newseeds = newList();
      }
    }
    return (factlist->reverse());
  }
}

Cons* allFactsOfN(int n, Cons* instancerefs) {
  // This is a generalization of `all-facts-of' (which see).  With `n' = 0
  // and only one instance this command behaves just like `all-facts-of'.
  // Otherwise, returns a cons list of all definite (TRUE or FALSE) propositions
  // that reference any of the instances listed in `instanceRefs', plus if `n' >= 1
  // all propositions that reference any instances that are arguments of
  // propositions collected in the previous step, plus if `n' >= 2... and so on.
  // That is, if we only consider binary propositions, this can be viewed as
  // growing a graph with instances as its nodes and predicates as its arcs
  // starting from the set of seed `instanceRefs' to depth `n'-1.
  // Caution: with a fully connected KB and large enough `n' this could return
  // the whole knowledge base.
  // 
  // The returned propositions include those asserted to be true or false by
  // default, but it does not include propositions that are found to be
  // true only by running the query engine.  Facts inferred to be true by
  // the forward chainer will be included.  Hence, the returned list of
  // facts may be longer in a context where the forward chainer has been
  // run then in one where it has not (see `run-forward-rules').
  return (callAllFactsOfN(n, instancerefs)->theConsList);
}

Cons* allFactsOfNEvaluatorWrapper(Cons* arguments) {
  return (allFactsOfN(((IntegerWrapper*)(arguments->value))->wrapperValue, arguments->rest));
}

void helpStartupPropagate1() {
  {
    SYM_PROPAGATE_LOGIC_DEFERRED_DEFAULT_PROPOSITIONS_INTERNAL = ((Symbol*)(internRigidSymbolWrtModule("DEFERRED-DEFAULT-PROPOSITIONS-INTERNAL", NULL, 0)));
    SYM_PROPAGATE_LOGIC_EVALUATION_STATE_TABLE = ((Symbol*)(internRigidSymbolWrtModule("EVALUATION-STATE-TABLE", NULL, 0)));
    KWD_PROPAGATE_POSTED = ((Keyword*)(internRigidSymbolWrtModule("POSTED", NULL, 2)));
    SYM_PROPAGATE_LOGIC_EVALUATION_QUEUE = ((Symbol*)(internRigidSymbolWrtModule("EVALUATION-QUEUE", NULL, 0)));
    KWD_PROPAGATE_FORWARD = ((Keyword*)(internRigidSymbolWrtModule("FORWARD", NULL, 2)));
    SYM_PROPAGATE_LOGIC_BACKWARD_ONLYp = ((Symbol*)(internRigidSymbolWrtModule("BACKWARD-ONLY?", NULL, 0)));
    SGT_PROPAGATE_LOGIC_NAMED_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("NAMED-DESCRIPTION", NULL, 1)));
    SGT_PROPAGATE_LOGIC_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 1)));
    SGT_PROPAGATE_LOGIC_F_COLLECT_FORWARD_CHAINING_RULES_MEMO_TABLE_000 = ((Surrogate*)(internRigidSymbolWrtModule("F-COLLECT-FORWARD-CHAINING-RULES-MEMO-TABLE-000", NULL, 1)));
    KWD_PROPAGATE_FUNCTION = ((Keyword*)(internRigidSymbolWrtModule("FUNCTION", NULL, 2)));
    SYM_PROPAGATE_LOGIC_FORWARD_CHAINING_QUEUE = ((Symbol*)(internRigidSymbolWrtModule("FORWARD-CHAINING-QUEUE", NULL, 0)));
    KWD_PROPAGATE_ISA = ((Keyword*)(internRigidSymbolWrtModule("ISA", NULL, 2)));
    KWD_PROPAGATE_PREDICATE = ((Keyword*)(internRigidSymbolWrtModule("PREDICATE", NULL, 2)));
    SGT_PROPAGATE_LOGIC_SKOLEM = ((Surrogate*)(internRigidSymbolWrtModule("SKOLEM", NULL, 1)));
    SYM_PROPAGATE_LOGIC_HYPOTHESIZED_INSTANCEp = ((Symbol*)(internRigidSymbolWrtModule("HYPOTHESIZED-INSTANCE?", NULL, 0)));
    KWD_PROPAGATE_PROPAGATE = ((Keyword*)(internRigidSymbolWrtModule("PROPAGATE", NULL, 2)));
    SYM_PROPAGATE_LOGIC_COMPLEMENT_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("COMPLEMENT-DESCRIPTION", NULL, 0)));
    KWD_PROPAGATE_SINGLETONSp = ((Keyword*)(internRigidSymbolWrtModule("SINGLETONS?", NULL, 2)));
    SGT_PROPAGATE_LOGIC_PROPOSITION = ((Surrogate*)(internRigidSymbolWrtModule("PROPOSITION", NULL, 1)));
    KWD_PROPAGATE_KB_UPDATE = ((Keyword*)(internRigidSymbolWrtModule("KB-UPDATE", NULL, 2)));
    KWD_PROPAGATE_META_KB_UPDATE = ((Keyword*)(internRigidSymbolWrtModule("META-KB-UPDATE", NULL, 2)));
    KWD_PROPAGATE_META = ((Keyword*)(internRigidSymbolWrtModule("META", NULL, 2)));
    SGT_PROPAGATE_STELLA_MODULE = ((Surrogate*)(internRigidSymbolWrtModule("MODULE", getStellaModule("/STELLA", TRUE), 1)));
    SGT_PROPAGATE_LOGIC_LOGIC_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("LOGIC-OBJECT", NULL, 1)));
    SGT_PROPAGATE_STELLA_SYMBOL = ((Surrogate*)(internRigidSymbolWrtModule("SYMBOL", getStellaModule("/STELLA", TRUE), 1)));
    KWD_PROPAGATE_EVALUATED = ((Keyword*)(internRigidSymbolWrtModule("EVALUATED", NULL, 2)));
    KWD_PROPAGATE_AND = ((Keyword*)(internRigidSymbolWrtModule("AND", NULL, 2)));
    KWD_PROPAGATE_OR = ((Keyword*)(internRigidSymbolWrtModule("OR", NULL, 2)));
    KWD_PROPAGATE_NOT = ((Keyword*)(internRigidSymbolWrtModule("NOT", NULL, 2)));
    KWD_PROPAGATE_EQUIVALENT = ((Keyword*)(internRigidSymbolWrtModule("EQUIVALENT", NULL, 2)));
    SYM_PROPAGATE_LOGIC_ELABORATED_IN_WORLDS = ((Symbol*)(internRigidSymbolWrtModule("ELABORATED-IN-WORLDS", NULL, 0)));
    KWD_PROPAGATE_ELABORATE = ((Keyword*)(internRigidSymbolWrtModule("ELABORATE", NULL, 2)));
    KWD_PROPAGATE_EXTENSIONAL_ASSERTION = ((Keyword*)(internRigidSymbolWrtModule("EXTENSIONAL-ASSERTION", NULL, 2)));
    SGT_PROPAGATE_PL_KERNEL_KB_INEQUALITY = ((Surrogate*)(internRigidSymbolWrtModule("INEQUALITY", getStellaModule("/PL-KERNEL-KB", TRUE), 1)));
    SGT_PROPAGATE_STELLA_SURROGATE = ((Surrogate*)(internRigidSymbolWrtModule("SURROGATE", getStellaModule("/STELLA", TRUE), 1)));
    KWD_PROPAGATE_EXISTS = ((Keyword*)(internRigidSymbolWrtModule("EXISTS", NULL, 2)));
    KWD_PROPAGATE_FORALL = ((Keyword*)(internRigidSymbolWrtModule("FORALL", NULL, 2)));
    SGT_PROPAGATE_STELLA_LITERAL_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("LITERAL-WRAPPER", getStellaModule("/STELLA", TRUE), 1)));
    SYM_PROPAGATE_LOGIC_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 0)));
    SGT_PROPAGATE_STELLA_SLOT = ((Surrogate*)(internRigidSymbolWrtModule("SLOT", getStellaModule("/STELLA", TRUE), 1)));
    SGT_PROPAGATE_PL_KERNEL_KB_PHRASE = ((Surrogate*)(internRigidSymbolWrtModule("PHRASE", getStellaModule("/PL-KERNEL-KB", TRUE), 1)));
    KWD_PROPAGATE_IMPLIES = ((Keyword*)(internRigidSymbolWrtModule("IMPLIES", NULL, 2)));
    SYM_PROPAGATE_LOGIC_STARTUP_PROPAGATE = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-PROPAGATE", NULL, 0)));
    SYM_PROPAGATE_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", TRUE), 0)));
  }
}

void helpStartupPropagate2() {
  {
    defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT DEFERRED-DEFAULT-PROPOSITIONS-INTERNAL :TYPE (CONS OF PROPOSITION) :PUBLIC? TRUE :DOCUMENTATION \"List of propositions infered to be true or false by\ndefault before we enter default propagation mode.\" :DEFAULT NULL :ALLOCATION :DYNAMIC)");
    defineFunctionObject("DEFERRED-DEFAULT-PROPOSITIONS", "(DEFUN (DEFERRED-DEFAULT-PROPOSITIONS (CONS OF PROPOSITION)) ((SELF CONTEXT)))", ((cpp_function_code)(&deferredDefaultPropositions)), NULL);
    defineFunctionObject("DEFERRED-DEFAULT-PROPOSITIONS-SETTER", "(DEFUN DEFERRED-DEFAULT-PROPOSITIONS-SETTER ((SELF CONTEXT) (NEWVALUE (CONS OF PROPOSITION))))", ((cpp_function_code)(&deferredDefaultPropositionsSetter)), NULL);
    defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT EVALUATION-QUEUE :TYPE (LIST OF PROPOSITION) :PUBLIC? TRUE :DOCUMENTATION \"List of propositions waiting for evaluation in \n*context*.\" :DEFAULT NULL :ALLOCATION :DYNAMIC)");
    defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT EVALUATION-STATE-TABLE :TYPE (HASH-TABLE OF PROPOSITION KEYWORD) :PUBLIC? TRUE :DOCUMENTATION \"Records which propositions have been evaluated at\nleast one in the world 'self'.\" :ALLOCATION :DYNAMIC)");
    defineFunctionObject("EVALUATION-STATE", "(DEFUN (EVALUATION-STATE KEYWORD) ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&evaluationState)), NULL);
    defineFunctionObject("EVALUATION-STATE-SETTER", "(DEFUN EVALUATION-STATE-SETTER ((PROPOSITION PROPOSITION) (STATE KEYWORD)))", ((cpp_function_code)(&evaluationStateSetter)), NULL);
    defineFunctionObject("POST-FOR-EVALUATION", "(DEFUN POST-FOR-EVALUATION ((SELF PROPOSITION)) :PUBLIC? TRUE)", ((cpp_function_code)(&postForEvaluation)), NULL);
    defineExternalSlotFromStringifiedSource("(DEFSLOT CONTEXT FORWARD-CHAINING-QUEUE :TYPE (LIST OF PROPOSITION) :PUBLIC? TRUE :DOCUMENTATION \"Queue of recently asserted or inferred propositions\nhaving applicable forward rules.  Rules are triggered for each queue entry.\" :DEFAULT NULL :ALLOCATION :DYNAMIC)");
    defineFunctionObject("HELP-COLLECT-FORWARD-RULES", "(DEFUN (HELP-COLLECT-FORWARD-RULES (CONS OF KEY-VALUE-LIST)) ((DESCRIPTION DESCRIPTION) (RULES KEY-VALUE-LIST) (INDICES KEY-VALUE-LIST) (TOUCHEDDEFAULT? BOOLEAN) (BEENTHERE LIST)))", ((cpp_function_code)(&helpCollectForwardRules)), NULL);
    defineFunctionObject("COLLECT-FORWARD-CHAINING-RULES", "(DEFUN (COLLECT-FORWARD-CHAINING-RULES (KEY-VALUE-LIST OF PROPOSITION BOOLEAN-WRAPPER) (KEY-VALUE-LIST OF FORWARD-CHAINING-INDEX BOOLEAN-WRAPPER)) ((DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&collectForwardChainingRules)), NULL);
    defineFunctionObject("HAS-FORWARD-CHAINING-RULES?", "(DEFUN (HAS-FORWARD-CHAINING-RULES? BOOLEAN) ((DESCRIPTION DESCRIPTION) (PROPOSITION PROPOSITION)))", ((cpp_function_code)(&hasForwardChainingRulesP)), NULL);
    defineFunctionObject("POST-TO-FORWARD-CHAINING-QUEUE", "(DEFUN POST-TO-FORWARD-CHAINING-QUEUE ((SELF PROPOSITION) (WORLD WORLD)))", ((cpp_function_code)(&postToForwardChainingQueue)), NULL);
    defineFunctionObject("APPLY-RULE-CONSEQUENT-TO-VECTOR", "(DEFUN APPLY-RULE-CONSEQUENT-TO-VECTOR ((CONSEQUENT DESCRIPTION) (ARGUMENTS ARGUMENTS-VECTOR) (RULE PROPOSITION) (TRIGGERDESCRIPTION DESCRIPTION) (TRIGGERPROPOSITION PROPOSITION) (TOUCHEDDEFAULT? BOOLEAN)))", ((cpp_function_code)(&applyRuleConsequentToVector)), NULL);
    defineFunctionObject("APPLY-FORWARD-RULES-TO-VECTOR", "(DEFUN APPLY-FORWARD-RULES-TO-VECTOR ((TRIGGERDESCRIPTION DESCRIPTION) (ARGUMENTS ARGUMENTS-VECTOR) (TRIGGERPROPOSITION PROPOSITION)))", ((cpp_function_code)(&applyForwardRulesToVector)), NULL);
    defineFunctionObject("APPLICABLE-FORWARD-RULE?", "(DEFUN (APPLICABLE-FORWARD-RULE? BOOLEAN) ((RULE PROPOSITION) (ARGUMENTS ARGUMENTS-VECTOR)))", ((cpp_function_code)(&applicableForwardRuleP)), NULL);
    defineMethodObject("(DEFMETHOD REACT-TO-INFERENCE-UPDATE ((SELF SKOLEM)))", ((cpp_method_code)(&Skolem::reactToInferenceUpdate)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD REACT-TO-INFERENCE-UPDATE ((SELF PROPOSITION)))", ((cpp_method_code)(&Proposition::reactToInferenceUpdate)), ((cpp_method_code)(NULL)));
    defineFunctionObject("REACT-TO-KB-UPDATE", "(DEFUN REACT-TO-KB-UPDATE ((CONTEXT CONTEXT) (OBJECT OBJECT)))", ((cpp_function_code)(&reactToKbUpdate)), NULL);
    defineFunctionObject("INITIALIZE-CONSTRAINT-PROPAGATION-QUEUES", "(DEFUN INITIALIZE-CONSTRAINT-PROPAGATION-QUEUES ((WORLD WORLD)))", ((cpp_function_code)(&initializeConstraintPropagationQueues)), NULL);
    defineFunctionObject("EXECUTE-CONSTRAINT-PROPAGATION-QUEUES", "(DEFUN EXECUTE-CONSTRAINT-PROPAGATION-QUEUES ())", ((cpp_function_code)(&executeConstraintPropagationQueues)), NULL);
    defineFunctionObject("EVALUATE-NEW-PROPOSITION", "(DEFUN EVALUATE-NEW-PROPOSITION ((SELF PROPOSITION)))", ((cpp_function_code)(&evaluateNewProposition)), NULL);
    defineFunctionObject("EVALUATE-AND-PROPOSITION", "(DEFUN EVALUATE-AND-PROPOSITION ((SELF PROPOSITION)))", ((cpp_function_code)(&evaluateAndProposition)), NULL);
    defineFunctionObject("EVALUATE-OR-PROPOSITION", "(DEFUN EVALUATE-OR-PROPOSITION ((SELF PROPOSITION)))", ((cpp_function_code)(&evaluateOrProposition)), NULL);
    defineFunctionObject("EVALUATE-NOT-PROPOSITION", "(DEFUN EVALUATE-NOT-PROPOSITION ((SELF PROPOSITION)))", ((cpp_function_code)(&evaluateNotProposition)), NULL);
    defineFunctionObject("EVALUATE-EQUIVALENT-PROPOSITION", "(DEFUN EVALUATE-EQUIVALENT-PROPOSITION ((SELF PROPOSITION)))", ((cpp_function_code)(&evaluateEquivalentProposition)), NULL);
    defineFunctionObject("EQUATE-EQUIVALENT-FUNCTION-PROPOSITIONS", "(DEFUN EQUATE-EQUIVALENT-FUNCTION-PROPOSITIONS ((SELF PROPOSITION)))", ((cpp_function_code)(&equateEquivalentFunctionPropositions)), NULL);
    defineFunctionObject("EVALUATE-FUNCTION-PROPOSITION", "(DEFUN EVALUATE-FUNCTION-PROPOSITION ((SELF PROPOSITION)) :PUBLIC? TRUE)", ((cpp_function_code)(&evaluateFunctionProposition)), NULL);
    defineFunctionObject("EVALUATE-PREDICATE-PROPOSITION", "(DEFUN EVALUATE-PREDICATE-PROPOSITION ((SELF PROPOSITION)) :PUBLIC? TRUE)", ((cpp_function_code)(&evaluatePredicateProposition)), NULL);
    defineFunctionObject("EVALUATE-PROPOSITION", "(DEFUN EVALUATE-PROPOSITION ((SELF PROPOSITION)) :PUBLIC? TRUE)", ((cpp_function_code)(&evaluateProposition)), NULL);
    defineMethodObject("(DEFMETHOD MARK-AS-INCOHERENT ((SELF LOGIC-OBJECT)))", ((cpp_method_code)(&LogicObject::markAsIncoherent)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD MARK-AS-INCOHERENT ((SELF SKOLEM)))", ((cpp_method_code)(&Skolem::markAsIncoherent)), ((cpp_method_code)(NULL)));
    defineExternalSlotFromStringifiedSource("(DEFSLOT LOGIC-OBJECT ELABORATED-IN-WORLDS :TYPE (LIST OF WORLD) :DOCUMENTATION \"List of worlds in which 'elaborate-instance' has\nbeen applied to 'self'.\" :ALLOCATION :DYNAMIC)");
    defineFunctionObject("RECURSIVELY-REACT-TO-INFERENCE-UPDATE", "(DEFUN RECURSIVELY-REACT-TO-INFERENCE-UPDATE ((SELF PROPOSITION)))", ((cpp_function_code)(&recursivelyReactToInferenceUpdate)), NULL);
    defineFunctionObject("ELABORATE-META-INSTANCE", "(DEFUN ELABORATE-META-INSTANCE ((SELF OBJECT)))", ((cpp_function_code)(&elaborateMetaInstance)), NULL);
    defineFunctionObject("ELABORATE-INSTANCE", "(DEFUN ELABORATE-INSTANCE ((SELF OBJECT)))", ((cpp_function_code)(&elaborateInstance)), NULL);
    defineFunctionObject("EVALUATE-REACHABLE-INEQUALITIES", "(DEFUN EVALUATE-REACHABLE-INEQUALITIES ((SELF LOGIC-OBJECT) (VISITEDLIST LIST)))", ((cpp_function_code)(&evaluateReachableInequalities)), NULL);
    defineFunctionObject("ELABORATE-SURROGATES-IN-PROPOSITION", "(DEFUN ELABORATE-SURROGATES-IN-PROPOSITION ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&elaborateSurrogatesInProposition)), NULL);
    defineFunctionObject("COLLECT-FUNCTION-PROPOSITION-FACTS", "(DEFUN COLLECT-FUNCTION-PROPOSITION-FACTS ((SELF PROPOSITION) (FACTS (LIST OF PROPOSITION)) (BEENTHERE (LIST OF PROPOSITION)) (INCLUDEUNKNOWN? BOOLEAN)))", ((cpp_function_code)(&collectFunctionPropositionFacts)), NULL);
    defineFunctionObject("HELP-COLLECT-FACTS", "(DEFUN HELP-COLLECT-FACTS ((SELF OBJECT) (FACTS (LIST OF PROPOSITION)) (BEENTHERE (LIST OF PROPOSITION)) (INCLUDEUNKNOWN? BOOLEAN)))", ((cpp_function_code)(&helpCollectFacts)), NULL);
    defineFunctionObject("ALL-FACTS-OF-INSTANCE", "(DEFUN (ALL-FACTS-OF-INSTANCE (LIST OF PROPOSITION)) ((SELF OBJECT) (INCLUDEUNKNOWNFACTS? BOOLEAN) (ELABORATE? BOOLEAN)) :DOCUMENTATION \"Return a list of all definite (TRUE or FALSE) propositions\nattached to `self'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&allFactsOfInstance)), NULL);
    defineFunctionObject("ALL-FACTS-OF", "(DEFUN (ALL-FACTS-OF (CONS OF PROPOSITION)) ((INSTANCEREF NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Return a cons list of all definite (TRUE or FALSE) propositions\nthat reference the instance `instanceRef'.  This includes propositions\nasserted to be true by default, but it does not include propositions\nthat are found to be TRUE only by running the query engine.  Facts\ninferred to be TRUE by the forward chainer will be included.\nHence, the returned list of facts may be longer in a context where the\nforward chainer has been run then in one where it has not (see\n`run-forward-rules').\")", ((cpp_function_code)(&allFactsOf)), NULL);
    defineFunctionObject("CALL-ALL-FACTS-OF", "(DEFUN (CALL-ALL-FACTS-OF (LIST OF PROPOSITION)) ((INSTANCEREF OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? TRUE :DOCUMENTATION \"Return a list of all definite (TRUE or FALSE) propositions\nthat reference the instance `instanceRef'.\")", ((cpp_function_code)(&callAllFactsOf)), NULL);
    defineFunctionObject("RETRACT-FACTS-OF-INSTANCE", "(DEFUN RETRACT-FACTS-OF-INSTANCE ((SELF LOGIC-OBJECT)) :DOCUMENTATION \"Retract all definite (TRUE or FALSE) propositions attached to `self'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&retractFactsOfInstance)), NULL);
    defineFunctionObject("RETRACT-FACTS-OF", "(DEFUN RETRACT-FACTS-OF ((INSTANCEREF OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Retract all definite (TRUE or FALSE) propositions\nthat reference the instance `instanceRef'.\")", ((cpp_function_code)(&retractFactsOf)), NULL);
    defineFunctionObject("EXPLODE-VARIABLIZED-STRING", "(DEFUN (EXPLODE-VARIABLIZED-STRING LIST) ((STRING STRING)))", ((cpp_function_code)(&explodeVariablizedString)), NULL);
    defineFunctionObject("FACT-TO-SENTENCE", "(DEFUN (FACT-TO-SENTENCE STRING) ((SELF PROPOSITION) (PERIOD? BOOLEAN)))", ((cpp_function_code)(&factToSentence)), NULL);
    defineFunctionObject("ALL-SENTENCES-OF", "(DEFUN (ALL-SENTENCES-OF (CONS OF STRING-WRAPPER)) ((INSTANCEREF OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? TRUE :DOCUMENTATION \"Return a list of sentences describing facts about 'instanceRef'.\")", ((cpp_function_code)(&allSentencesOf)), NULL);
    defineFunctionObject("CALL-ALL-FACTS-OF-N", "(DEFUN (CALL-ALL-FACTS-OF-N (LIST OF PROPOSITION)) ((N INTEGER) (SEEDREFS CONS)))", ((cpp_function_code)(&callAllFactsOfN)), NULL);
    defineFunctionObject("FILTERED-ALL-FACTS-OF-N", "(DEFUN (FILTERED-ALL-FACTS-OF-N (LIST OF PROPOSITION)) ((N INTEGER) (SEEDREFS CONS) (FILTER FUNCTION-CODE)))", ((cpp_function_code)(&filteredAllFactsOfN)), NULL);
    defineFunctionObject("ALL-FACTS-OF-N", "(DEFUN (ALL-FACTS-OF-N (CONS OF PROPOSITION)) ((N INTEGER) |&REST| (INSTANCEREFS NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"This is a generalization of `all-facts-of' (which see).  With `n' = 0\nand only one instance this command behaves just like `all-facts-of'.\nOtherwise, returns a cons list of all definite (TRUE or FALSE) propositions\nthat reference any of the instances listed in `instanceRefs', plus if `n' >= 1\nall propositions that reference any instances that are arguments of\npropositions collected in the previous step, plus if `n' >= 2... and so on.\nThat is, if we only consider binary propositions, this can be viewed as\ngrowing a graph with instances as its nodes and predicates as its arcs\nstarting from the set of seed `instanceRefs' to depth `n'-1.\nCaution: with a fully connected KB and large enough `n' this could return\nthe whole knowledge base.\n\nThe returned propositions include those asserted to be true or false by\ndefault, but it does not include propositions that are found to be\ntrue only by running the query engine.  Facts inferred to be true by\nthe forward chainer will be included.  Hence, the returned list of\nfacts may be longer in a context where the forward chainer has been\nrun then in one where it has not (see `run-forward-rules').\")", ((cpp_function_code)(&allFactsOfN)), ((cpp_function_code)(&allFactsOfNEvaluatorWrapper)));
    defineFunctionObject("STARTUP-PROPAGATE", "(DEFUN STARTUP-PROPAGATE () :PUBLIC? TRUE)", ((cpp_function_code)(&startupPropagate)), NULL);
    { MethodSlot* function = lookupFunction(SYM_PROPAGATE_LOGIC_STARTUP_PROPAGATE);

      setDynamicSlotValue(function->dynamicSlots, SYM_PROPAGATE_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Propagate"), NULL_STRING_WRAPPER);
    }
  }
}

void startupPropagate() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupPropagate1();
    }
    if (currentStartupTimePhaseP(4)) {
      oFILLINGCONSTRAINTPROPAGATIONQUEUESpo.set(FALSE);
      oDEFERINGDEFAULTFORWARDINFERENCESpo.set(FALSE);
      oJUST_IN_TIME_FORWARD_INFERENCEpo = TRUE;
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupPropagate2();
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *FILLINGCONSTRAINTPROPAGATIONQUEUES?* BOOLEAN FALSE :DOCUMENTATION \"True if we are inside of 'react-to-kb-update'.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *DEFERINGDEFAULTFORWARDINFERENCES?* BOOLEAN FALSE :DOCUMENTATION \"True if we are propagating strict inferences, and\nposting derived default propositions to temporary queues.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *CURRENTLYEXECUTINGFORWARDCHAININGQUEUE* (LIST OF PROPOSITION) NULL :DOCUMENTATION \"Points to an active queue of propositions that will trigger\nforward inference.  New queue entries are posted to a separate queue\nattached to *context*.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *COLLECTFORWARDPROPOSITIONS* (CONS OF PROPOSITION) NULL :DOCUMENTATION \"Collect goes-true propositions produced by forward\nchaining.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *JUST-IN-TIME-FORWARD-INFERENCE?* BOOLEAN TRUE :DOCUMENTATION \"If TRUE, ensures that forward propagation has\nbeen applied to each instance 'touched' during a query.\")");
    }
  }
}

Symbol* SYM_PROPAGATE_LOGIC_DEFERRED_DEFAULT_PROPOSITIONS_INTERNAL = NULL;

Symbol* SYM_PROPAGATE_LOGIC_EVALUATION_STATE_TABLE = NULL;

Keyword* KWD_PROPAGATE_POSTED = NULL;

Symbol* SYM_PROPAGATE_LOGIC_EVALUATION_QUEUE = NULL;

Keyword* KWD_PROPAGATE_FORWARD = NULL;

Symbol* SYM_PROPAGATE_LOGIC_BACKWARD_ONLYp = NULL;

Surrogate* SGT_PROPAGATE_LOGIC_NAMED_DESCRIPTION = NULL;

Surrogate* SGT_PROPAGATE_LOGIC_DESCRIPTION = NULL;

Surrogate* SGT_PROPAGATE_LOGIC_F_COLLECT_FORWARD_CHAINING_RULES_MEMO_TABLE_000 = NULL;

Keyword* KWD_PROPAGATE_FUNCTION = NULL;

Symbol* SYM_PROPAGATE_LOGIC_FORWARD_CHAINING_QUEUE = NULL;

Keyword* KWD_PROPAGATE_ISA = NULL;

Keyword* KWD_PROPAGATE_PREDICATE = NULL;

Surrogate* SGT_PROPAGATE_LOGIC_SKOLEM = NULL;

Symbol* SYM_PROPAGATE_LOGIC_HYPOTHESIZED_INSTANCEp = NULL;

Keyword* KWD_PROPAGATE_PROPAGATE = NULL;

Symbol* SYM_PROPAGATE_LOGIC_COMPLEMENT_DESCRIPTION = NULL;

Keyword* KWD_PROPAGATE_SINGLETONSp = NULL;

Surrogate* SGT_PROPAGATE_LOGIC_PROPOSITION = NULL;

Keyword* KWD_PROPAGATE_KB_UPDATE = NULL;

Keyword* KWD_PROPAGATE_META_KB_UPDATE = NULL;

Keyword* KWD_PROPAGATE_META = NULL;

Surrogate* SGT_PROPAGATE_STELLA_MODULE = NULL;

Surrogate* SGT_PROPAGATE_LOGIC_LOGIC_OBJECT = NULL;

Surrogate* SGT_PROPAGATE_STELLA_SYMBOL = NULL;

Keyword* KWD_PROPAGATE_EVALUATED = NULL;

Keyword* KWD_PROPAGATE_AND = NULL;

Keyword* KWD_PROPAGATE_OR = NULL;

Keyword* KWD_PROPAGATE_NOT = NULL;

Keyword* KWD_PROPAGATE_EQUIVALENT = NULL;

Symbol* SYM_PROPAGATE_LOGIC_ELABORATED_IN_WORLDS = NULL;

Keyword* KWD_PROPAGATE_ELABORATE = NULL;

Keyword* KWD_PROPAGATE_EXTENSIONAL_ASSERTION = NULL;

Surrogate* SGT_PROPAGATE_PL_KERNEL_KB_INEQUALITY = NULL;

Surrogate* SGT_PROPAGATE_STELLA_SURROGATE = NULL;

Keyword* KWD_PROPAGATE_EXISTS = NULL;

Keyword* KWD_PROPAGATE_FORALL = NULL;

Surrogate* SGT_PROPAGATE_STELLA_LITERAL_WRAPPER = NULL;

Symbol* SYM_PROPAGATE_LOGIC_DESCRIPTION = NULL;

Surrogate* SGT_PROPAGATE_STELLA_SLOT = NULL;

Surrogate* SGT_PROPAGATE_PL_KERNEL_KB_PHRASE = NULL;

Keyword* KWD_PROPAGATE_IMPLIES = NULL;

Symbol* SYM_PROPAGATE_LOGIC_STARTUP_PROPAGATE = NULL;

Symbol* SYM_PROPAGATE_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
