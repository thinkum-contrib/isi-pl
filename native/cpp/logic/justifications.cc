//  -*- Mode: C++ -*-

// justifications.cc

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

Justification* newJustification() {
  { Justification* self = NULL;

    self = new Justification();
    self->negativeScore = NULL_FLOAT;
    self->positiveScore = NULL_FLOAT;
    self->truthValue = NULL;
    self->reversePolarityP = false;
    self->substitution = NULL;
    self->patternJustification = NULL;
    self->antecedents = NIL;
    self->proposition = NULL;
    self->inferenceRule = NULL;
    return (self);
  }
}

Surrogate* Justification::primaryType() {
  { Justification* self = this;

    return (SGT_JUSTIFICATIONS_LOGIC_JUSTIFICATION);
  }
}

Keyword* Justification::inferenceStrategy() {
  { Justification* self = this;

    return (NULL);
  }
}

Object* accessJustificationSlotValue(Justification* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_JUSTIFICATIONS_LOGIC_INFERENCE_RULE) {
    if (setvalueP) {
      self->inferenceRule = ((Keyword*)(value));
    }
    else {
      value = self->inferenceRule;
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_PROPOSITION) {
    if (setvalueP) {
      self->proposition = ((Proposition*)(value));
    }
    else {
      value = self->proposition;
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_ANTECEDENTS) {
    if (setvalueP) {
      self->antecedents = ((Cons*)(value));
    }
    else {
      value = self->antecedents;
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_PATTERN_JUSTIFICATION) {
    if (setvalueP) {
      self->patternJustification = ((Justification*)(value));
    }
    else {
      value = self->patternJustification;
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_SUBSTITUTION) {
    if (setvalueP) {
      self->substitution = ((KeyValueList*)(value));
    }
    else {
      value = self->substitution;
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_REVERSE_POLARITYp) {
    if (setvalueP) {
      self->reversePolarityP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->reversePolarityP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_TRUTH_VALUE) {
    if (setvalueP) {
      self->truthValue = ((TruthValue*)(value));
    }
    else {
      value = self->truthValue;
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_POSITIVE_SCORE) {
    if (setvalueP) {
      self->positiveScore = ((FloatWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapFloat(self->positiveScore);
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_NEGATIVE_SCORE) {
    if (setvalueP) {
      self->negativeScore = ((FloatWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapFloat(self->negativeScore);
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

PrimitiveStrategy* newPrimitiveStrategy() {
  { PrimitiveStrategy* self = NULL;

    self = new PrimitiveStrategy();
    self->negativeScore = NULL_FLOAT;
    self->positiveScore = NULL_FLOAT;
    self->truthValue = NULL;
    self->reversePolarityP = false;
    self->substitution = NULL;
    self->patternJustification = NULL;
    self->antecedents = NIL;
    self->proposition = NULL;
    self->strategy = NULL;
    self->inferenceRule = KWD_JUSTIFICATIONS_PRIMITIVE_STRATEGY;
    return (self);
  }
}

Surrogate* PrimitiveStrategy::primaryType() {
  { PrimitiveStrategy* self = this;

    return (SGT_JUSTIFICATIONS_LOGIC_PRIMITIVE_STRATEGY);
  }
}

Keyword* PrimitiveStrategy::inferenceStrategy() {
  { PrimitiveStrategy* self = this;

    return (self->strategy);
  }
}

Object* accessPrimitiveStrategySlotValue(PrimitiveStrategy* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_JUSTIFICATIONS_LOGIC_INFERENCE_RULE) {
    if (setvalueP) {
      self->inferenceRule = ((Keyword*)(value));
    }
    else {
      value = self->inferenceRule;
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_STRATEGY) {
    if (setvalueP) {
      self->strategy = ((Keyword*)(value));
    }
    else {
      value = self->strategy;
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

Object* justificationArgumentBoundTo(Object* argument, Justification* justification) {
  if (subtypeOfP(safePrimaryType(argument), SGT_JUSTIFICATIONS_LOGIC_PATTERN_VARIABLE)) {
    { Object* argument000 = argument;
      PatternVariable* argument = ((PatternVariable*)(argument000));

      if (!((boolean)(justification))) {
        justification = oCURRENTJUSTIFICATIONo.get();
      }
      if (((boolean)(justification))) {
        { Justification* pattern = ((justification->inferenceRule == KWD_JUSTIFICATIONS_PATTERN) ? justification : justification->patternJustification);
          KeyValueList* substitution = (((boolean)(pattern)) ? pattern->substitution : ((KeyValueList*)(NULL)));
          Object* value = NULL;

          if (((boolean)(substitution))) {
            value = substitution->lookup(argument);
          }
          if ((!((boolean)(value))) &&
              ((boolean)(pattern))) {
            pattern = pattern->patternJustification;
            if (((boolean)(pattern))) {
              value = justificationArgumentBoundTo(argument, pattern);
            }
          }
          return (value);
        }
      }
    }
  }
  else {
    return (argument);
  }
  return (NULL);
}

KeyValueList* yieldJustificationSubstitution(Justification* justification, KeyValueList* substitution, Proposition* argument) {
  { Proposition* top = justification->proposition;
    Proposition* proposition = ((!((boolean)(argument))) ? top : argument);

    { Object* arg = NULL;
      Vector* vector000 = proposition->arguments;
      int index000 = 0;
      int length000 = vector000->length();

      for  (arg, vector000, index000, length000; 
            index000 < length000; 
            index000 = index000 + 1) {
        arg = (vector000->theArray)[index000];
        { Surrogate* testValue000 = safePrimaryType(arg);

          if (subtypeOfP(testValue000, SGT_JUSTIFICATIONS_LOGIC_PATTERN_VARIABLE)) {
            { Object* arg000 = arg;
              PatternVariable* arg = ((PatternVariable*)(arg000));

              if (freeVariableP(arg, top)) {
                if (!((boolean)(substitution))) {
                  substitution = newKeyValueList();
                }
                substitution->insertAt(arg, justificationArgumentBoundTo(arg, justification));
              }
            }
          }
          else if (subtypeOfP(testValue000, SGT_JUSTIFICATIONS_LOGIC_PROPOSITION)) {
            { Object* arg001 = arg;
              Proposition* arg = ((Proposition*)(arg001));

              substitution = yieldJustificationSubstitution(justification, substitution, arg);
            }
          }
          else {
          }
        }
      }
    }
    return (substitution);
  }
}

boolean justificationEqlP(Justification* just1, Justification* just2) {
  return ((just1 == just2) ||
      ((just1->inferenceRule == just2->inferenceRule) &&
       ((just1->reversePolarityP == just2->reversePolarityP) &&
        ((((!(just1->inferenceRule == KWD_JUSTIFICATIONS_PRIMITIVE_STRATEGY)) &&
      (!(just2->inferenceRule == KWD_JUSTIFICATIONS_PRIMITIVE_STRATEGY))) ||
      (((PrimitiveStrategy*)(just1))->strategy == ((PrimitiveStrategy*)(just2))->strategy)) &&
         justificationPropositionsEqlP(just1->proposition, just1, just2->proposition, just2)))));
}

boolean justificationPropositionsEqlP(Proposition* proposition1, Justification* just1, Proposition* proposition2, Justification* just2) {
  if ((proposition1->operatoR == proposition2->operatoR) &&
      (proposition1->arguments->length() == proposition2->arguments->length())) {
    { Object* arg1 = NULL;
      Vector* vector000 = proposition1->arguments;
      int index000 = 0;
      int length000 = vector000->length();
      Object* arg2 = NULL;
      Vector* vector001 = proposition2->arguments;
      int index001 = 0;
      int length001 = vector001->length();

      for  (arg1, vector000, index000, length000, arg2, vector001, index001, length001; 
            (index000 < length000) &&
                (index001 < length001); 
            index000 = index000 + 1,
            index001 = index001 + 1) {
        arg1 = (vector000->theArray)[index000];
        arg2 = (vector001->theArray)[index001];
        if ((!eqlP(arg1, arg2)) ||
            variableP(arg1)) {
          { Surrogate* testValue000 = safePrimaryType(arg1);

            if (subtypeOfP(testValue000, SGT_JUSTIFICATIONS_LOGIC_PROPOSITION)) {
              { Object* arg1000 = arg1;
                Proposition* arg1 = ((Proposition*)(arg1000));

                if (!(isaP(arg2, SGT_JUSTIFICATIONS_LOGIC_PROPOSITION) &&
                    justificationPropositionsEqlP(arg1, just1, ((Proposition*)(arg2)), just2))) {
                  return (false);
                }
              }
            }
            else if (subtypeOfP(testValue000, SGT_JUSTIFICATIONS_LOGIC_PATTERN_VARIABLE)) {
              { Object* arg1001 = arg1;
                PatternVariable* arg1 = ((PatternVariable*)(arg1001));

                if (subtypeOfP(safePrimaryType(arg2), SGT_JUSTIFICATIONS_LOGIC_PATTERN_VARIABLE)) {
                  { Object* arg2000 = arg2;
                    PatternVariable* arg2 = ((PatternVariable*)(arg2000));

                    { Object* value1 = justificationArgumentBoundTo(arg1, just1);
                      Object* value2 = justificationArgumentBoundTo(arg2, just2);

                      if ((!((boolean)(value1))) ||
                          ((!((boolean)(value2))) ||
                           (!eqlP(value1, value2)))) {
                        return (false);
                      }
                    }
                  }
                }
                else {
                  if (!eqlP(justificationArgumentBoundTo(arg1, just1), arg2)) {
                    return (false);
                  }
                }
              }
            }
            else {
              if (subtypeOfP(safePrimaryType(arg2), SGT_JUSTIFICATIONS_LOGIC_PATTERN_VARIABLE)) {
                { Object* arg2001 = arg2;
                  PatternVariable* arg2 = ((PatternVariable*)(arg2001));

                  if (!eqlP(justificationArgumentBoundTo(arg2, just2), arg1)) {
                    return (false);
                  }
                }
              }
              else {
                return (false);
              }
            }
          }
        }
      }
    }
    return (true);
  }
  return (false);
}

Justification* Justification::copy() {
  // Return a copy of the proof starting at `self'.  Allocates
  // all new justification objects, but structure-shares other information such
  // as propositions and substitutions.
  { Justification* self = this;

    { Justification* copy = NULL;
      Cons* antecedents = NIL;

      if (subtypeOfP(safePrimaryType(self), SGT_JUSTIFICATIONS_LOGIC_PRIMITIVE_STRATEGY)) {
        { Justification* self000 = self;
          PrimitiveStrategy* self = ((PrimitiveStrategy*)(self000));

          { PrimitiveStrategy* self001 = newPrimitiveStrategy();

            self001->strategy = self->strategy;
            copy = self001;
          }
        }
      }
      else {
        copy = newJustification();
      }
      copy->inferenceRule = self->inferenceRule;
      copy->proposition = self->proposition;
      copy->substitution = self->substitution;
      copy->reversePolarityP = self->reversePolarityP;
      copy->truthValue = self->truthValue;
      copy->positiveScore = self->positiveScore;
      copy->negativeScore = self->negativeScore;
      { Justification* antecedent = NULL;
        Cons* iter000 = self->antecedents;
        Cons* collect000 = NULL;

        for  (antecedent, iter000, collect000; 
              !(iter000 == NIL); 
              iter000 = iter000->rest) {
          antecedent = ((Justification*)(iter000->value));
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(antecedent->copy(), NIL);
              if (antecedents == NIL) {
                antecedents = collect000;
              }
              else {
                addConsToEndOfConsList(antecedents, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(antecedent->copy(), NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      copy->antecedents = antecedents;
      if (self->inferenceRule == KWD_JUSTIFICATIONS_PATTERN) {
        { Justification* antecedent = NULL;
          Cons* iter001 = copy->antecedents;

          for (antecedent, iter001; !(iter001 == NIL); iter001 = iter001->rest) {
            antecedent = ((Justification*)(iter001->value));
            backlinkToPatternJustification(antecedent, copy);
          }
        }
      }
      return (copy);
    }
  }
}

// If TRUE every query records justifications to enable
// the explanation of concluded results.
DEFINE_STELLA_SPECIAL(oRECORD_JUSTIFICATIONSpo, boolean , false);

boolean recordJustificationsP() {
  // Return TRUE if every query records justifications to enable
  // the explanation of concluded results.
  return (oRECORD_JUSTIFICATIONSpo.get());
}

void recordGoalJustification(ControlFrame* goal, Justification* justification) {
  if (!((boolean)(justification->proposition))) {
    justification->proposition = goal->proposition;
  }
  justification->reversePolarityP = goal->reversePolarityP;
  justification->truthValue = goal->truthValue;
  if (((boolean)(oQUERYITERATORo.get())) &&
      ((boolean)(oQUERYITERATORo.get()->partialMatchStrategy))) {
    goal->setJustificationPartialTruth(justification);
  }
  setDynamicSlotValue(goal->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, justification, NULL);
}

void recordPrimitiveJustification(ControlFrame* frame, Keyword* lastmove) {
  if ((lastmove == KWD_JUSTIFICATIONS_UP_TRUE) ||
      (lastmove == KWD_JUSTIFICATIONS_UP_FAIL)) {
    { Cons* antecedents = ((((boolean)(frame->result)) &&
          ((boolean)(((Justification*)(dynamicSlotValue(frame->result->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL)))))) ? cons(((Justification*)(dynamicSlotValue(frame->result->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL))), NIL) : NIL);

      { PrimitiveStrategy* self000 = newPrimitiveStrategy();

        self000->strategy = ((lastmove == KWD_JUSTIFICATIONS_UP_FAIL) ? KWD_JUSTIFICATIONS_FAILURE : frame->currentStrategy);
        self000->antecedents = antecedents;
        recordGoalJustification(frame, self000);
      }
    }
  }
  else {
  }
}

void recordPatternJustification(ControlFrame* frame, Keyword* lastmove) {
  { ControlFrame* argument = frame->result;

    if ((lastmove == KWD_JUSTIFICATIONS_UP_TRUE) ||
        (lastmove == KWD_JUSTIFICATIONS_UP_FAIL)) {
      if (!((boolean)(((Justification*)(dynamicSlotValue(argument->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL)))))) {
        return;
      }
      { Justification* self000 = newJustification();

        self000->inferenceRule = KWD_JUSTIFICATIONS_PATTERN;
        self000->antecedents = cons(((Justification*)(dynamicSlotValue(argument->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL))), NIL);
        recordGoalJustification(frame, self000);
      }
      backlinkToPatternJustification(((Justification*)(dynamicSlotValue(argument->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL))), ((Justification*)(dynamicSlotValue(frame->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL))));
      { KeyValueList* substitution = newKeyValueList();
        PatternRecord* patternrecord = frame->patternRecord;
        Description* description = NULL;

        if (((boolean)(patternrecord))) {
          if (subtypeOfP(safePrimaryType(patternrecord), SGT_JUSTIFICATIONS_LOGIC_PATTERN_RECORD)) {
            { PatternRecord* patternrecord000 = patternrecord;
              PatternRecord* patternrecord = patternrecord000;

              description = patternrecord->optimalPattern;
              if (((boolean)(description))) {
                { PatternVariable* vbl = NULL;
                  Vector* vector000 = description->ioVariables;
                  int index000 = 0;
                  int length000 = vector000->length();

                  for  (vbl, vector000, index000, length000; 
                        index000 < length000; 
                        index000 = index000 + 1) {
                    vbl = ((PatternVariable*)((vector000->theArray)[index000]));
                    substitution->insertAt(vbl, (oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(vbl->boundToOffset)]);
                  }
                }
                { PatternVariable* vbl = NULL;
                  Vector* vector001 = description->internalVariables;
                  int index001 = 0;
                  int length001 = vector001->length();

                  for  (vbl, vector001, index001, length001; 
                        index001 < length001; 
                        index001 = index001 + 1) {
                    vbl = ((PatternVariable*)((vector001->theArray)[index001]));
                    substitution->insertAt(vbl, (oQUERYITERATORo.get()->currentPatternRecord->variableBindings->theArray)[(vbl->boundToOffset)]);
                  }
                }
              }
            }
          }
          else {
          }
        }
        if (isaP(substitution, SGT_JUSTIFICATIONS_STELLA_KEY_VALUE_LIST)) {
          substitution = ((KeyValueList*)(((KeyValueList*)(substitution))->reverse()));
        }
        ((Justification*)(dynamicSlotValue(frame->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL)))->substitution = ((KeyValueList*)(substitution));
      }
    }
    else {
    }
  }
}

void backlinkToPatternJustification(Justification* justification, Justification* pattern) {
  if (!((boolean)(justification->patternJustification))) {
    justification->patternJustification = pattern;
    { Justification* antecedent = NULL;
      Cons* iter000 = justification->antecedents;

      for (antecedent, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        antecedent = ((Justification*)(iter000->value));
        backlinkToPatternJustification(antecedent, pattern);
      }
    }
  }
}

void recordModusPonensJustification(ControlFrame* frame, Keyword* lastmove) {
  { ControlFrame* antecedent = frame->result;

    if (lastmove == KWD_JUSTIFICATIONS_UP_TRUE) {
      { Proposition* goal = extractSubgoalOfFrame(frame);
        boolean reversepolarityP = frame->reversePolarityP;
        Keyword* inferencerule = (reversepolarityP ? KWD_JUSTIFICATIONS_MODUS_TOLLENS : KWD_JUSTIFICATIONS_MODUS_PONENS);
        Proposition* rule = ((Proposition*)(dynamicSlotValue(frame->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_ANTECEDENTS_RULE, NULL)));
        Proposition* ruleconsequent = ((Description*)(((inferencerule == KWD_JUSTIFICATIONS_MODUS_PONENS) ? (rule->arguments->theArray)[1] : (rule->arguments->theArray)[0])))->proposition;
        boolean invertedP = ruleconsequent->kind == KWD_JUSTIFICATIONS_NOT;

        { Justification* self000 = newJustification();

          self000->inferenceRule = inferencerule;
          self000->proposition = goal;
          { PrimitiveStrategy* self001 = newPrimitiveStrategy();

            self001->strategy = KWD_JUSTIFICATIONS_SCAN_PROPOSITIONS;
            self001->proposition = rule;
            self001->truthValue = ((TruthValue*)(accessInContext(rule->truthValue, rule->homeContext, false)));
            self001->positiveScore = ((TruthValue*)(accessInContext(rule->truthValue, rule->homeContext, false)))->positiveScore;
            self000->antecedents = cons(self001, cons(((Justification*)(dynamicSlotValue(antecedent->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL))), NIL));
          }
          { Justification* justification = self000;

            recordGoalJustification(frame, justification);
            justification->reversePolarityP = (reversepolarityP ? (!invertedP) : invertedP);
          }
        }
      }
    }
    else {
    }
  }
}

void recordAndIntroductionJustification(ControlFrame* frame, Keyword* lastmove) {
  { Vector* conjuncts = ((Vector*)(dynamicSlotValue(frame->dynamicSlots, SYM_JUSTIFICATIONS_STELLA_ARGUMENTS, NULL)));
    Cons* antecedents = NIL;

    if (lastmove == KWD_JUSTIFICATIONS_UP_TRUE) {
      { ControlFrame* conjunct = NULL;
        Vector* vector000 = conjuncts;
        int index000 = 0;
        int length000 = vector000->length();
        Cons* collect000 = NULL;

        for  (conjunct, vector000, index000, length000, collect000; 
              index000 < length000; 
              index000 = index000 + 1) {
          conjunct = ((ControlFrame*)((vector000->theArray)[index000]));
                    if (!((boolean)(collect000))) {
            {
              collect000 = cons(((conjunct->state == KWD_JUSTIFICATIONS_POPPED) ? ((Justification*)(dynamicSlotValue(conjunct->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL)))->copy() : ((Justification*)(dynamicSlotValue(conjunct->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL)))), NIL);
              if (antecedents == NIL) {
                antecedents = collect000;
              }
              else {
                addConsToEndOfConsList(antecedents, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(((conjunct->state == KWD_JUSTIFICATIONS_POPPED) ? ((Justification*)(dynamicSlotValue(conjunct->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL)))->copy() : ((Justification*)(dynamicSlotValue(conjunct->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL)))), NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      { Justification* self000 = newJustification();

        self000->inferenceRule = KWD_JUSTIFICATIONS_AND_INTRODUCTION;
        self000->antecedents = antecedents;
        recordGoalJustification(frame, self000);
      }
    }
    else {
    }
  }
}

void recordOrIntroductionJustification(ControlFrame* frame, Keyword* lastmove) {
  { ControlFrame* disjunct = frame->result;

    if (lastmove == KWD_JUSTIFICATIONS_UP_TRUE) {
      { Justification* self000 = newJustification();

        self000->inferenceRule = KWD_JUSTIFICATIONS_OR_INTRODUCTION;
        self000->antecedents = cons(((Justification*)(dynamicSlotValue(disjunct->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL))), NIL);
        recordGoalJustification(frame, self000);
      }
    }
    else {
    }
  }
}

void recordDisproofJustification(ControlFrame* frame, Keyword* lastmove) {
  { ControlFrame* argument = frame->result;

    if ((lastmove == KWD_JUSTIFICATIONS_UP_TRUE) ||
        (lastmove == KWD_JUSTIFICATIONS_UP_FAIL)) {
      { Justification* self000 = newJustification();

        self000->inferenceRule = KWD_JUSTIFICATIONS_DISPROOF;
        self000->antecedents = cons(((Justification*)(dynamicSlotValue(argument->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL))), NIL);
        recordGoalJustification(frame, self000);
      }
    }
    else {
    }
  }
}

void recordFailJustification(ControlFrame* frame, Keyword* lastmove) {
  if (lastmove == KWD_JUSTIFICATIONS_UP_FAIL) {
    { Justification* self000 = newJustification();

      self000->inferenceRule = KWD_JUSTIFICATIONS_FAIL_INTRODUCTION;
      recordGoalJustification(frame, self000);
    }
  }
  else {
  }
}

void recordClosedNotJustification(ControlFrame* frame, Keyword* lastmove) {
  if (lastmove == KWD_JUSTIFICATIONS_UP_FAIL) {
    { Justification* self000 = newJustification();

      self000->inferenceRule = KWD_JUSTIFICATIONS_CLOSED_NOT_INTRODUCTION;
      self000->proposition = ((frame->proposition->kind == KWD_JUSTIFICATIONS_FAIL) ? frame->up->proposition : frame->proposition);
      recordGoalJustification(frame, self000);
    }
  }
  else {
  }
}

void recordExistentialIntroductionJustification(ControlFrame* frame, Keyword* lastmove) {
  { ControlFrame* argument = frame->result;

    if (lastmove == KWD_JUSTIFICATIONS_UP_TRUE) {
      { Justification* self000 = newJustification();

        self000->inferenceRule = KWD_JUSTIFICATIONS_EXISTENTIAL_INTRODUCTION;
        self000->antecedents = (((boolean)(((Justification*)(dynamicSlotValue(argument->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL))))) ? cons(((Justification*)(dynamicSlotValue(argument->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION, NULL))), NIL) : NIL);
        recordGoalJustification(frame, self000);
      }
    }
    else {
    }
  }
}

boolean failedGoalJustificationP(Justification* self) {
  { Keyword* testValue000 = self->inferenceRule;

    if ((testValue000 == KWD_JUSTIFICATIONS_PRIMITIVE_STRATEGY) ||
        ((testValue000 == KWD_JUSTIFICATIONS_TIMEOUT) ||
         (testValue000 == KWD_JUSTIFICATIONS_DEPTH_CUTOFF))) {
      if (((PrimitiveStrategy*)(self))->strategy == KWD_JUSTIFICATIONS_FAILURE) {
        return (true);
      }
      else {
      }
    }
    else {
    }
  }
  return (false);
}

boolean cutoffGoalJustificationP(Justification* self) {
  { Keyword* testValue000 = self->inferenceRule;

    if ((testValue000 == KWD_JUSTIFICATIONS_TIMEOUT) ||
        (testValue000 == KWD_JUSTIFICATIONS_DEPTH_CUTOFF)) {
      return (true);
    }
    else {
    }
  }
  return (false);
}

Cons* Justification::consify() {
  // Return a CONS tree representation of the proof `self'.
  // Each proof step is represented as a CONS tree of the form
  //   (<proposition> (<key> <value>...) <antecedent>...)
  // where each <antecedent> is a CONS tree representing a subproof.  The
  // consification follows the original proof structure literally, i.e., no
  // uninteresting nodes such as patterns or AND-introductions are suppressed.
  { Justification* self = this;

    return (consifyJustification(self, KWD_JUSTIFICATIONS_RAW));
  }
}

Cons* consifyJustification(Justification* self, Keyword* style) {
  // Return a CONS tree representation of the proof `self'.
  // Each proof step is represented as a CONS tree of the form
  //   (<proposition> (<key> <value>...) <antecedent>...)
  // where each <antecedent> is a CONS tree representing a subproof.
  // `style' indicates what nodes in the proof tree should be suppressed.
  // :RAW preserves the original structure literally, :VERBOSE keeps AND-
  // introductions but suppresses all auxiliary (non-logical) nodes such as
  // pattern nodes, and :BRIEF additionally suppresses AND-introduction nodes.
  { 
    BIND_STELLA_SPECIAL(oEXPLANATION_STYLEo, Keyword*, style);
    if (!(style == KWD_JUSTIFICATIONS_RAW)) {
      self = visibleJustification(self);
    }
    { Cons* antecedents = ((style == KWD_JUSTIFICATIONS_RAW) ? self->antecedents : visibleAntecedents(self)->theConsList);
      Object* proposition = NULL;
      PropertyList* keys = newPropertyList();
      Cons* substitution = NIL;
      Cons* consifiedself = NIL;

      if (((boolean)(self->inferenceRule))) {
        keys->insertAt(KWD_JUSTIFICATIONS_INFERENCE_RULE, self->inferenceRule);
        if (isaP(self, SGT_JUSTIFICATIONS_LOGIC_PRIMITIVE_STRATEGY)) {
          keys->insertAt(KWD_JUSTIFICATIONS_STRATEGY, ((PrimitiveStrategy*)(self))->strategy);
        }
      }
      if (((boolean)(self->truthValue))) {
        keys->insertAt(KWD_JUSTIFICATIONS_TRUTH_VALUE, self->truthValue);
      }
      else {
        keys->insertAt(KWD_JUSTIFICATIONS_TRUTH_VALUE, UNKNOWN_TRUTH_VALUE);
      }
      if (self->positiveScore != NULL_FLOAT) {
        keys->insertAt(KWD_JUSTIFICATIONS_POSITIVE_SCORE, wrapFloat(self->positiveScore));
      }
      { KeyValueList* thesubstitution = self->substitution;

        if (!((boolean)(thesubstitution))) {
          { Justification* ant = NULL;
            Cons* iter000 = self->antecedents;

            for (ant, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
              ant = ((Justification*)(iter000->value));
              if (ant->inferenceRule == KWD_JUSTIFICATIONS_PATTERN) {
                thesubstitution = ant->substitution;
                break;
              }
            }
          }
        }
        if (((boolean)(thesubstitution))) {
          { PatternVariable* var = NULL;
            Object* binding = NULL;
            KvCons* iter001 = thesubstitution->theKvList;

            for  (var, binding, iter001; 
                  ((boolean)(iter001)); 
                  iter001 = iter001->rest) {
              var = ((PatternVariable*)(iter001->key));
              binding = iter001->value;
              substitution = cons(generateTerm(var), substitution);
              substitution = cons(generateTerm(binding), substitution);
            }
          }
          keys->insertAt(KWD_JUSTIFICATIONS_SUBSTITUTION, substitution->reverse());
        }
      }
      { 
        BIND_STELLA_SPECIAL(oCURRENTJUSTIFICATIONo, Justification*, self);
        proposition = generateProposition(self->proposition);
        if (self->reversePolarityP) {
          proposition = listO(3, SYM_JUSTIFICATIONS_STELLA_NOT, proposition, NIL);
        }
      }
      consifiedself = consList(2, proposition, keys->thePlist);
      { Justification* antecedent = NULL;
        Cons* iter002 = antecedents;
        Cons* collect000 = NULL;

        for  (antecedent, iter002, collect000; 
              !(iter002 == NIL); 
              iter002 = iter002->rest) {
          antecedent = ((Justification*)(iter002->value));
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(consifyJustification(antecedent, style), NIL);
              if (consifiedself == NIL) {
                consifiedself = collect000;
              }
              else {
                addConsToEndOfConsList(consifiedself, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(consifyJustification(antecedent, style), NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      return (consifiedself);
    }
  }
}

List* getQueryJustifications(QueryIterator* query, int solutionindex, int maxjustifications, boolean createP) {
  { boolean askqueryP = query->queryIsTrueFalseP();
    QuerySolutionTable* solutions = query->solutions;
    QuerySolution* solution = NULL;
    int nofsolutions = solutions->length();
    List* justifications = NULL;

    if (solutions->emptyP()) {
      return (NIL_LIST);
    }
    if (askqueryP ||
        ((solutionindex == NULL_INTEGER) ||
         (solutionindex < 0))) {
      solutionindex = nofsolutions - 1;
    }
    if (solutionindex >= nofsolutions) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "There were only " << "`" << nofsolutions << "'" << " solutions";
        throw *newExplainException(stream000->theStringReader());
      }
    }
    solution = solutions->nth(solutionindex);
    if (!((boolean)(solution->justification))) {
      if (createP) {
        justifications = deriveQueryJustifications(query, NULL, solutionindex, maxjustifications);
        solution->justification = ((Justification*)(justifications->first()));
        solution->allJustifications = justifications;
        return (justifications);
      }
      else {
        return (NIL_LIST);
      }
    }
    else {
      if (((boolean)(solution->allJustifications)) &&
          solution->allJustifications->nonEmptyP()) {
        justifications = list(0);
        { Justification* just = NULL;
          Cons* iter000 = solution->allJustifications->theConsList;
          int i = NULL_INTEGER;
          int iter001 = 1;
          int upperBound000 = maxjustifications;
          boolean unboundedP000 = upperBound000 == NULL_INTEGER;
          Cons* collect000 = NULL;

          for  (just, iter000, i, iter001, upperBound000, unboundedP000, collect000; 
                (!(iter000 == NIL)) &&
                    (unboundedP000 ||
                     (iter001 <= upperBound000)); 
                iter000 = iter000->rest,
                iter001 = iter001 + 1) {
            just = ((Justification*)(iter000->value));
            i = iter001;
            if (!((boolean)(collect000))) {
              {
                collect000 = cons(just, NIL);
                if (justifications->theConsList == NIL) {
                  justifications->theConsList = collect000;
                }
                else {
                  addConsToEndOfConsList(justifications->theConsList, collect000);
                }
              }
            }
            else {
              {
                collect000->rest = cons(just, NIL);
                collect000 = collect000->rest;
              }
            }
          }
        }
      }
      if (((boolean)(justifications))) {
        return (justifications);
      }
      else {
        return (list(1, solution->justification));
      }
    }
  }
}

List* deriveQueryJustifications(QueryIterator* query, Object* options, int solutionindex, int maxjustifications) {
  { 
    BIND_STELLA_SPECIAL(oQUERYITERATORo, QueryIterator*, query);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, query->queryContext);
    BIND_STELLA_SPECIAL(oINFERENCELEVELo, NormalInferenceLevel*, currentInferenceLevel());
    BIND_STELLA_SPECIAL(oREVERSEPOLARITYpo, boolean, false);
    BIND_STELLA_SPECIAL(oGENERATE_ALL_PROOFSpo, boolean, false);
    BIND_STELLA_SPECIAL(oRECORD_JUSTIFICATIONSpo, boolean, true);
    { QueryIterator* askquery = allocateQueryIterator();
      PropertyList* queryoptions = query->options;

      if (!((boolean)(options))) {
        queryoptions = queryoptions->copy();
        queryoptions->removeAt(KWD_JUSTIFICATIONS_HOW_MANY);
        options = queryoptions;
      }
      processQueryOptions(askquery, options);
      { 
        BIND_STELLA_SPECIAL(oTYPE_CHECK_STRATEGYo, Keyword*, KWD_JUSTIFICATIONS_NONE);
        initializeQueryIterator(askquery, query->queryDescription(), query->solutions->nth(solutionindex)->bindings);
      }
      if (query->queryIsPartialP()) {
        callAskPartial(askquery);
      }
      else {
        callAsk(askquery);
      }
      return (getQueryJustifications(askquery, NULL_INTEGER, maxjustifications, false));
    }
  }
}

ForwardGoalRecord* newForwardGoalRecord() {
  { ForwardGoalRecord* self = NULL;

    self = new ForwardGoalRecord();
    self->forwardRule = NULL;
    self->forwardGoal = NULL;
    return (self);
  }
}

Surrogate* ForwardGoalRecord::primaryType() {
  { ForwardGoalRecord* self = this;

    return (SGT_JUSTIFICATIONS_LOGIC_FORWARD_GOAL_RECORD);
  }
}

Object* accessForwardGoalRecordSlotValue(ForwardGoalRecord* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_JUSTIFICATIONS_LOGIC_FORWARD_GOAL) {
    if (setvalueP) {
      self->forwardGoal = ((Proposition*)(value));
    }
    else {
      value = self->forwardGoal;
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_FORWARD_RULE) {
    if (setvalueP) {
      self->forwardRule = ((Proposition*)(value));
    }
    else {
      value = self->forwardRule;
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

List* Proposition::forwardChainingGoals_reader() {
  { Proposition* self = this;

    { List* answer = ((List*)(dynamicSlotValue(self->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_FORWARD_CHAINING_GOALS, NULL)));

      if (!((boolean)(answer))) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean ForwardGoalRecord::deletedP() {
  { ForwardGoalRecord* self = this;

    { Proposition* goal = self->forwardGoal;
      Proposition* rule = self->forwardRule;

      return ((!((boolean)(goal))) ||
          ((!((boolean)(rule))) ||
           (deletedPropositionP(goal) ||
            deletedPropositionP(rule))));
    }
  }
}

boolean ForwardGoalRecord::deletedPSetter(boolean value) {
  { ForwardGoalRecord* self = this;

    if (value) {
      self->forwardGoal = NULL;
      self->forwardRule = NULL;
    }
    return (value);
  }
}

void recordForwardGoal(Proposition* forwardrule, Vector* arguments, Proposition* consequentproposition) {
  { ForwardGoalRecord* fwdgoalrec = NULL;
    Cons* iter000 = consequentproposition->forwardChainingGoals_reader()->theConsList;

    for (fwdgoalrec, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
      fwdgoalrec = ((ForwardGoalRecord*)(iter000->value));
      if (!fwdgoalrec->deletedP()) {
        { Proposition* fwdgoal = fwdgoalrec->forwardGoal;

          { boolean testValue000 = false;

            testValue000 = fwdgoalrec->forwardRule == forwardrule;
            if (testValue000) {
              { boolean alwaysP000 = true;

                { Object* arg = NULL;
                  Vector* vector000 = arguments;
                  int index000 = 0;
                  int length000 = vector000->length();
                  int i = NULL_INTEGER;
                  int iter001 = 1;

                  for  (arg, vector000, index000, length000, i, iter001; 
                        index000 < length000; 
                        index000 = index000 + 1,
                        iter001 = iter001 + 1) {
                    arg = (vector000->theArray)[index000];
                    i = iter001;
                    if (!eqlP((fwdgoal->arguments->theArray)[i], arg)) {
                      alwaysP000 = false;
                      break;
                    }
                  }
                }
                testValue000 = alwaysP000;
              }
            }
            if (testValue000) {
              return;
            }
          }
        }
      }
    }
  }
  if (elaborationRuleP(consequentproposition, forwardrule, arguments)) {
    return;
  }
  { Proposition* forwardgoal = createProposition(SYM_JUSTIFICATIONS_STELLA_PREDICATE, arguments->length() + 1);

    { ForwardGoalRecord* self000 = newForwardGoalRecord();

      self000->forwardGoal = forwardgoal;
      self000->forwardRule = forwardrule;
      { ForwardGoalRecord* fwdgoalrec = self000;

        forwardgoal->operatoR = SGT_JUSTIFICATIONS_PL_KERNEL_KB_HOLDS;
        (forwardgoal->arguments->theArray)[0] = ((forwardrule->arguments->theArray)[0]);
        { Object* arg = NULL;
          Vector* vector001 = arguments;
          int index001 = 0;
          int length001 = vector001->length();
          int i = NULL_INTEGER;
          int iter002 = 1;

          for  (arg, vector001, index001, length001, i, iter002; 
                index001 < length001; 
                index001 = index001 + 1,
                iter002 = iter002 + 1) {
            arg = (vector001->theArray)[index001];
            i = iter002;
            (forwardgoal->arguments->theArray)[i] = arg;
          }
        }
        if (consequentproposition->forwardChainingGoals_reader()->emptyP()) {
          setDynamicSlotValue(consequentproposition->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_FORWARD_CHAINING_GOALS, list(1, fwdgoalrec), NULL);
        }
        else {
          consequentproposition->forwardChainingGoals_reader()->insertNew(fwdgoalrec);
        }
      }
    }
  }
}

boolean predicationP(Proposition* proposition) {
  return (getQuotedTree("((:PREDICATE :FUNCTION :ISA :EQUIVALENT) \"/LOGIC\")", "/LOGIC")->memberP(proposition->kind));
}

boolean assertedAsTrueP(Proposition* proposition) {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    return ((!proposition->deletedP()) &&
        ((oREVERSEPOLARITYpo.get() ? falseP(proposition) : (trueP(proposition) ||
        functionWithDefinedValueP(proposition)))));
  }
}

boolean elaborationRuleP(Proposition* consequentproposition, Proposition* forwardrule, Vector* arguments) {
  { boolean testValue000 = false;

    testValue000 = predicationP(consequentproposition);
    if (testValue000) {
      testValue000 = assertedAsTrueP(forwardrule);
      if (testValue000) {
        { boolean alwaysP000 = true;

          { Object* arg = NULL;
            Vector* vector000 = consequentproposition->arguments;
            int index000 = 0;
            int length000 = vector000->length();

            for  (arg, vector000, index000, length000; 
                  index000 < length000; 
                  index000 = index000 + 1) {
              arg = (vector000->theArray)[index000];
              if (!arguments->memberP(arg)) {
                alwaysP000 = false;
                break;
              }
            }
          }
          testValue000 = alwaysP000;
        }
      }
    }
    { boolean value000 = testValue000;

      return (value000);
    }
  }
}

List* getForwardGoals(Proposition* proposition) {
  { List* goals = proposition->forwardChainingGoals_reader()->removeDeletedMembers();

    if (goals->emptyP() &&
        ((boolean)(((Proposition*)(dynamicSlotValue(proposition->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_MASTER_PROPOSITION, NULL)))))) {
      goals = ((Proposition*)(dynamicSlotValue(proposition->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_MASTER_PROPOSITION, NULL)))->forwardChainingGoals_reader()->removeDeletedMembers();
    }
    return (goals);
  }
}

ForwardJustification* newForwardJustification() {
  { ForwardJustification* self = NULL;

    self = new ForwardJustification();
    self->antecedents = NULL;
    self->forwardRule = NULL;
    self->consequent = NULL;
    return (self);
  }
}

Surrogate* ForwardJustification::primaryType() {
  { ForwardJustification* self = this;

    return (SGT_JUSTIFICATIONS_LOGIC_FORWARD_JUSTIFICATION);
  }
}

Object* accessForwardJustificationSlotValue(ForwardJustification* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_JUSTIFICATIONS_LOGIC_CONSEQUENT) {
    if (setvalueP) {
      self->consequent = ((Proposition*)(value));
    }
    else {
      value = self->consequent;
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_FORWARD_RULE) {
    if (setvalueP) {
      self->forwardRule = ((Proposition*)(value));
    }
    else {
      value = self->forwardRule;
    }
  }
  else if (slotname == SYM_JUSTIFICATIONS_LOGIC_ANTECEDENTS) {
    if (setvalueP) {
      self->antecedents = ((Cons*)(value));
    }
    else {
      value = self->antecedents;
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

List* Proposition::forwardJustifications_reader() {
  { Proposition* self = this;

    { List* answer = ((List*)(dynamicSlotValue(self->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_FORWARD_JUSTIFICATIONS, NULL)));

      if (!((boolean)(answer))) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

ForwardJustification* createForwardJustification(Proposition* consequentproposition, Proposition* forwardrule, Cons* antecedents) {
  { ForwardJustification* fj = newForwardJustification();

    fj->consequent = consequentproposition;
    fj->forwardRule = forwardrule;
    fj->antecedents = antecedents;
    return (fj);
  }
}

void recordForwardJustification(Proposition* consequentproposition, Proposition* forwardrule, Cons* antecedents) {
  if (!oRECORD_JUSTIFICATIONSpo.get()) {
    return;
  }
  { List* justifications = consequentproposition->forwardJustifications_reader();

    { ForwardJustification* fj = NULL;
      Cons* iter000 = justifications->theConsList;

      for (fj, iter000; !(iter000 == NIL); iter000 = iter000->rest) {
        fj = ((ForwardJustification*)(iter000->value));
        if (fj->forwardRule == forwardrule) {
          fj->antecedents = antecedents;
          return;
        }
      }
    }
    if (justifications == NIL_LIST) {
      justifications = list(0);
      setDynamicSlotValue(consequentproposition->dynamicSlots, SYM_JUSTIFICATIONS_LOGIC_FORWARD_JUSTIFICATIONS, justifications, NULL);
    }
    antecedents = cons(forwardrule, antecedents);
    justifications->push(createForwardJustification(consequentproposition, forwardrule, antecedents));
  }
}

void helpStartupJustifications1() {
  {
    SGT_JUSTIFICATIONS_LOGIC_JUSTIFICATION = ((Surrogate*)(internRigidSymbolWrtModule("JUSTIFICATION", NULL, 1)));
    SYM_JUSTIFICATIONS_LOGIC_INFERENCE_RULE = ((Symbol*)(internRigidSymbolWrtModule("INFERENCE-RULE", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_PROPOSITION = ((Symbol*)(internRigidSymbolWrtModule("PROPOSITION", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_ANTECEDENTS = ((Symbol*)(internRigidSymbolWrtModule("ANTECEDENTS", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_PATTERN_JUSTIFICATION = ((Symbol*)(internRigidSymbolWrtModule("PATTERN-JUSTIFICATION", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_SUBSTITUTION = ((Symbol*)(internRigidSymbolWrtModule("SUBSTITUTION", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_REVERSE_POLARITYp = ((Symbol*)(internRigidSymbolWrtModule("REVERSE-POLARITY?", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_TRUTH_VALUE = ((Symbol*)(internRigidSymbolWrtModule("TRUTH-VALUE", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_POSITIVE_SCORE = ((Symbol*)(internRigidSymbolWrtModule("POSITIVE-SCORE", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_NEGATIVE_SCORE = ((Symbol*)(internRigidSymbolWrtModule("NEGATIVE-SCORE", NULL, 0)));
    KWD_JUSTIFICATIONS_PRIMITIVE_STRATEGY = ((Keyword*)(internRigidSymbolWrtModule("PRIMITIVE-STRATEGY", NULL, 2)));
    SGT_JUSTIFICATIONS_LOGIC_PRIMITIVE_STRATEGY = ((Surrogate*)(internRigidSymbolWrtModule("PRIMITIVE-STRATEGY", NULL, 1)));
    SYM_JUSTIFICATIONS_LOGIC_STRATEGY = ((Symbol*)(internRigidSymbolWrtModule("STRATEGY", NULL, 0)));
    SGT_JUSTIFICATIONS_LOGIC_PATTERN_VARIABLE = ((Surrogate*)(internRigidSymbolWrtModule("PATTERN-VARIABLE", NULL, 1)));
    KWD_JUSTIFICATIONS_PATTERN = ((Keyword*)(internRigidSymbolWrtModule("PATTERN", NULL, 2)));
    SGT_JUSTIFICATIONS_LOGIC_PROPOSITION = ((Surrogate*)(internRigidSymbolWrtModule("PROPOSITION", NULL, 1)));
    SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION = ((Symbol*)(internRigidSymbolWrtModule("JUSTIFICATION", NULL, 0)));
    KWD_JUSTIFICATIONS_UP_TRUE = ((Keyword*)(internRigidSymbolWrtModule("UP-TRUE", NULL, 2)));
    KWD_JUSTIFICATIONS_UP_FAIL = ((Keyword*)(internRigidSymbolWrtModule("UP-FAIL", NULL, 2)));
    KWD_JUSTIFICATIONS_FAILURE = ((Keyword*)(internRigidSymbolWrtModule("FAILURE", NULL, 2)));
    KWD_JUSTIFICATIONS_SCAN_COLLECTION = ((Keyword*)(internRigidSymbolWrtModule("SCAN-COLLECTION", NULL, 2)));
    KWD_JUSTIFICATIONS_TECHNICAL = ((Keyword*)(internRigidSymbolWrtModule("TECHNICAL", NULL, 2)));
    KWD_JUSTIFICATIONS_SCAN_PROPOSITIONS = ((Keyword*)(internRigidSymbolWrtModule("SCAN-PROPOSITIONS", NULL, 2)));
    KWD_JUSTIFICATIONS_LOOKUP_ASSERTIONS = ((Keyword*)(internRigidSymbolWrtModule("LOOKUP-ASSERTIONS", NULL, 2)));
    KWD_JUSTIFICATIONS_LAY = ((Keyword*)(internRigidSymbolWrtModule("LAY", NULL, 2)));
    KWD_JUSTIFICATIONS_SPECIALIST = ((Keyword*)(internRigidSymbolWrtModule("SPECIALIST", NULL, 2)));
    KWD_JUSTIFICATIONS_COMPUTED_PREDICATE = ((Keyword*)(internRigidSymbolWrtModule("COMPUTED-PREDICATE", NULL, 2)));
    KWD_JUSTIFICATIONS_GOAL_COMPLEMENT = ((Keyword*)(internRigidSymbolWrtModule("GOAL-COMPLEMENT", NULL, 2)));
    KWD_JUSTIFICATIONS_EQUIVALENCE = ((Keyword*)(internRigidSymbolWrtModule("EQUIVALENCE", NULL, 2)));
    KWD_JUSTIFICATIONS_SUBSUMPTION_TEST = ((Keyword*)(internRigidSymbolWrtModule("SUBSUMPTION-TEST", NULL, 2)));
    SGT_JUSTIFICATIONS_LOGIC_PATTERN_RECORD = ((Surrogate*)(internRigidSymbolWrtModule("PATTERN-RECORD", NULL, 1)));
    SGT_JUSTIFICATIONS_STELLA_KEY_VALUE_LIST = ((Surrogate*)(internRigidSymbolWrtModule("KEY-VALUE-LIST", getStellaModule("/STELLA", true), 1)));
    KWD_JUSTIFICATIONS_MODUS_TOLLENS = ((Keyword*)(internRigidSymbolWrtModule("MODUS-TOLLENS", NULL, 2)));
    KWD_JUSTIFICATIONS_MODUS_PONENS = ((Keyword*)(internRigidSymbolWrtModule("MODUS-PONENS", NULL, 2)));
    SYM_JUSTIFICATIONS_LOGIC_ANTECEDENTS_RULE = ((Symbol*)(internRigidSymbolWrtModule("ANTECEDENTS-RULE", NULL, 0)));
    KWD_JUSTIFICATIONS_NOT = ((Keyword*)(internRigidSymbolWrtModule("NOT", NULL, 2)));
    KWD_JUSTIFICATIONS_AMPLIFICATION = ((Keyword*)(internRigidSymbolWrtModule("AMPLIFICATION", NULL, 2)));
    SYM_JUSTIFICATIONS_STELLA_ARGUMENTS = ((Symbol*)(internRigidSymbolWrtModule("ARGUMENTS", getStellaModule("/STELLA", true), 0)));
    KWD_JUSTIFICATIONS_POPPED = ((Keyword*)(internRigidSymbolWrtModule("POPPED", NULL, 2)));
    KWD_JUSTIFICATIONS_AND_INTRODUCTION = ((Keyword*)(internRigidSymbolWrtModule("AND-INTRODUCTION", NULL, 2)));
    KWD_JUSTIFICATIONS_PARTIAL = ((Keyword*)(internRigidSymbolWrtModule("PARTIAL", NULL, 2)));
    KWD_JUSTIFICATIONS_REVERSE = ((Keyword*)(internRigidSymbolWrtModule("REVERSE", NULL, 2)));
    KWD_JUSTIFICATIONS_OR_INTRODUCTION = ((Keyword*)(internRigidSymbolWrtModule("OR-INTRODUCTION", NULL, 2)));
    KWD_JUSTIFICATIONS_DISPROOF = ((Keyword*)(internRigidSymbolWrtModule("DISPROOF", NULL, 2)));
    KWD_JUSTIFICATIONS_FAIL_INTRODUCTION = ((Keyword*)(internRigidSymbolWrtModule("FAIL-INTRODUCTION", NULL, 2)));
    KWD_JUSTIFICATIONS_CLOSED_NOT_INTRODUCTION = ((Keyword*)(internRigidSymbolWrtModule("CLOSED-NOT-INTRODUCTION", NULL, 2)));
    KWD_JUSTIFICATIONS_FAIL = ((Keyword*)(internRigidSymbolWrtModule("FAIL", NULL, 2)));
    KWD_JUSTIFICATIONS_EXISTENTIAL_INTRODUCTION = ((Keyword*)(internRigidSymbolWrtModule("EXISTENTIAL-INTRODUCTION", NULL, 2)));
    KWD_JUSTIFICATIONS_TIMEOUT = ((Keyword*)(internRigidSymbolWrtModule("TIMEOUT", NULL, 2)));
    KWD_JUSTIFICATIONS_DEPTH_CUTOFF = ((Keyword*)(internRigidSymbolWrtModule("DEPTH-CUTOFF", NULL, 2)));
    KWD_JUSTIFICATIONS_RAW = ((Keyword*)(internRigidSymbolWrtModule("RAW", NULL, 2)));
    KWD_JUSTIFICATIONS_INFERENCE_RULE = ((Keyword*)(internRigidSymbolWrtModule("INFERENCE-RULE", NULL, 2)));
    KWD_JUSTIFICATIONS_STRATEGY = ((Keyword*)(internRigidSymbolWrtModule("STRATEGY", NULL, 2)));
    KWD_JUSTIFICATIONS_TRUTH_VALUE = ((Keyword*)(internRigidSymbolWrtModule("TRUTH-VALUE", NULL, 2)));
    KWD_JUSTIFICATIONS_POSITIVE_SCORE = ((Keyword*)(internRigidSymbolWrtModule("POSITIVE-SCORE", NULL, 2)));
    KWD_JUSTIFICATIONS_SUBSTITUTION = ((Keyword*)(internRigidSymbolWrtModule("SUBSTITUTION", NULL, 2)));
    SYM_JUSTIFICATIONS_STELLA_NOT = ((Symbol*)(internRigidSymbolWrtModule("NOT", getStellaModule("/STELLA", true), 0)));
    KWD_JUSTIFICATIONS_HOW_MANY = ((Keyword*)(internRigidSymbolWrtModule("HOW-MANY", NULL, 2)));
    KWD_JUSTIFICATIONS_NONE = ((Keyword*)(internRigidSymbolWrtModule("NONE", NULL, 2)));
    SGT_JUSTIFICATIONS_LOGIC_FORWARD_GOAL_RECORD = ((Surrogate*)(internRigidSymbolWrtModule("FORWARD-GOAL-RECORD", NULL, 1)));
  }
}

void helpStartupJustifications2() {
  {
    SYM_JUSTIFICATIONS_LOGIC_FORWARD_GOAL = ((Symbol*)(internRigidSymbolWrtModule("FORWARD-GOAL", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_FORWARD_RULE = ((Symbol*)(internRigidSymbolWrtModule("FORWARD-RULE", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_FORWARD_CHAINING_GOALS = ((Symbol*)(internRigidSymbolWrtModule("FORWARD-CHAINING-GOALS", NULL, 0)));
    SYM_JUSTIFICATIONS_STELLA_PREDICATE = ((Symbol*)(internRigidSymbolWrtModule("PREDICATE", getStellaModule("/STELLA", true), 0)));
    SGT_JUSTIFICATIONS_PL_KERNEL_KB_HOLDS = ((Surrogate*)(internRigidSymbolWrtModule("HOLDS", getStellaModule("/PL-KERNEL-KB", true), 1)));
    SYM_JUSTIFICATIONS_LOGIC_MASTER_PROPOSITION = ((Symbol*)(internRigidSymbolWrtModule("MASTER-PROPOSITION", NULL, 0)));
    SGT_JUSTIFICATIONS_LOGIC_FORWARD_JUSTIFICATION = ((Surrogate*)(internRigidSymbolWrtModule("FORWARD-JUSTIFICATION", NULL, 1)));
    SYM_JUSTIFICATIONS_LOGIC_CONSEQUENT = ((Symbol*)(internRigidSymbolWrtModule("CONSEQUENT", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_FORWARD_JUSTIFICATIONS = ((Symbol*)(internRigidSymbolWrtModule("FORWARD-JUSTIFICATIONS", NULL, 0)));
    SYM_JUSTIFICATIONS_LOGIC_STARTUP_JUSTIFICATIONS = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-JUSTIFICATIONS", NULL, 0)));
    SYM_JUSTIFICATIONS_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", true), 0)));
  }
}

void startupJustifications() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupJustifications1();
      helpStartupJustifications2();
    }
    if (currentStartupTimePhaseP(5)) {
      { Class* clasS = defineClassFromStringifiedSource("JUSTIFICATION", "(DEFCLASS JUSTIFICATION (STANDARD-OBJECT) :SLOTS ((INFERENCE-RULE :TYPE KEYWORD :DOCUMENTATION \"Keyword describing the inference rule used to conclude the\nproposition of this justification.\") (PROPOSITION :TYPE PROPOSITION :DOCUMENTATION \"The proposition supported by this justification.\") (ANTECEDENTS :TYPE (CONS OF JUSTIFICATION) :INITIALLY NIL :DOCUMENTATION \"Antecedents justifications of this justification.\") (PATTERN-JUSTIFICATION :TYPE JUSTIFICATION :DOCUMENTATION \"Backpointer to the closest parent :PATTERN justification containing\nthe variable substitutions from the associated pattern control frame.  If this\nis a :PATTERN justification, the slot points to the parent pattern.\") (SUBSTITUTION :TYPE (ENTITY-MAPPING OF PATTERN-VARIABLE OBJECT) :DOCUMENTATION \"List of variable bindings recorded for :PATTERN justifications.\") (REVERSE-POLARITY? :TYPE BOOLEAN :DOCUMENTATION \"True if proposition was derived in reverse polarity.\") (TRUTH-VALUE :TYPE TRUTH-VALUE :DOCUMENTATION \"Truth value of the" " derived proposition.\") (POSITIVE-SCORE :TYPE PARTIAL-MATCH-SCORE :DOCUMENTATION \"Positive partial match score of the derived proposition.\") (NEGATIVE-SCORE :TYPE PARTIAL-MATCH-SCORE :DOCUMENTATION \"Negative partial match score of the derived proposition.\")) :METHODS ((INFERENCE-STRATEGY ((SELF JUSTIFICATION)) :TYPE KEYWORD (RETURN NULL))))");

        clasS->classConstructorCode = ((cpp_function_code)(&newJustification));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessJustificationSlotValue));
      }
      { Class* clasS = defineClassFromStringifiedSource("PRIMITIVE-STRATEGY", "(DEFCLASS PRIMITIVE-STRATEGY (JUSTIFICATION) :SLOTS ((INFERENCE-RULE :TYPE KEYWORD :INITIALLY :PRIMITIVE-STRATEGY) (STRATEGY :TYPE KEYWORD)) :METHODS ((INFERENCE-STRATEGY ((SELF PRIMITIVE-STRATEGY)) :TYPE KEYWORD (RETURN (STRATEGY SELF)))))");

        clasS->classConstructorCode = ((cpp_function_code)(&newPrimitiveStrategy));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessPrimitiveStrategySlotValue));
      }
      { Class* clasS = defineClassFromStringifiedSource("FORWARD-GOAL-RECORD", "(DEFCLASS FORWARD-GOAL-RECORD (STANDARD-OBJECT) :SLOTS ((FORWARD-GOAL :TYPE PROPOSITION) (FORWARD-RULE :TYPE PROPOSITION)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newForwardGoalRecord));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessForwardGoalRecordSlotValue));
      }
      { Class* clasS = defineClassFromStringifiedSource("FORWARD-JUSTIFICATION", "(DEFCLASS FORWARD-JUSTIFICATION (STANDARD-OBJECT) :DOCUMENTATION \"Connects a proposition to other propositions\nthat collectively implied its truth.\" :SLOTS ((CONSEQUENT :TYPE PROPOSITION) (FORWARD-RULE :TYPE PROPOSITION) (ANTECEDENTS :TYPE (CONS OF PROPOSITION))))");

        clasS->classConstructorCode = ((cpp_function_code)(&newForwardJustification));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessForwardJustificationSlotValue));
      }
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("JUSTIFICATION-ARGUMENT-BOUND-TO", "(DEFUN (JUSTIFICATION-ARGUMENT-BOUND-TO OBJECT) ((ARGUMENT OBJECT) (JUSTIFICATION JUSTIFICATION)))", ((cpp_function_code)(&justificationArgumentBoundTo)), NULL);
      defineFunctionObject("YIELD-JUSTIFICATION-SUBSTITUTION", "(DEFUN (YIELD-JUSTIFICATION-SUBSTITUTION ENTITY-MAPPING) ((JUSTIFICATION JUSTIFICATION) (SUBSTITUTION ENTITY-MAPPING) (ARGUMENT PROPOSITION)))", ((cpp_function_code)(&yieldJustificationSubstitution)), NULL);
      defineFunctionObject("JUSTIFICATION-EQL?", "(DEFUN (JUSTIFICATION-EQL? BOOLEAN) ((JUST1 JUSTIFICATION) (JUST2 JUSTIFICATION)))", ((cpp_function_code)(&justificationEqlP)), NULL);
      defineFunctionObject("JUSTIFICATION-PROPOSITIONS-EQL?", "(DEFUN (JUSTIFICATION-PROPOSITIONS-EQL? BOOLEAN) ((PROPOSITION1 PROPOSITION) (JUST1 JUSTIFICATION) (PROPOSITION2 PROPOSITION) (JUST2 JUSTIFICATION)))", ((cpp_function_code)(&justificationPropositionsEqlP)), NULL);
      defineMethodObject("(DEFMETHOD (COPY (LIKE SELF)) ((SELF JUSTIFICATION)) :DOCUMENTATION \"Return a copy of the proof starting at `self'.  Allocates\nall new justification objects, but structure-shares other information such\nas propositions and substitutions.\" :PUBLIC? TRUE)", ((cpp_method_code)(&Justification::copy)), ((cpp_method_code)(NULL)));
      defineFunctionObject("RECORD-JUSTIFICATIONS?", "(DEFUN (RECORD-JUSTIFICATIONS? BOOLEAN) () :DOCUMENTATION \"Return TRUE if every query records justifications to enable\nthe explanation of concluded results.\" :GLOBALLY-INLINE? TRUE (RETURN *RECORD-JUSTIFICATIONS?*))", ((cpp_function_code)(&recordJustificationsP)), NULL);
      defineFunctionObject("RECORD-GOAL-JUSTIFICATION", "(DEFUN RECORD-GOAL-JUSTIFICATION ((GOAL CONTROL-FRAME) (JUSTIFICATION JUSTIFICATION)))", ((cpp_function_code)(&recordGoalJustification)), NULL);
      defineFunctionObject("RECORD-PRIMITIVE-JUSTIFICATION", "(DEFUN RECORD-PRIMITIVE-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&recordPrimitiveJustification)), NULL);
      defineFunctionObject("RECORD-PATTERN-JUSTIFICATION", "(DEFUN RECORD-PATTERN-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&recordPatternJustification)), NULL);
      defineFunctionObject("BACKLINK-TO-PATTERN-JUSTIFICATION", "(DEFUN BACKLINK-TO-PATTERN-JUSTIFICATION ((JUSTIFICATION JUSTIFICATION) (PATTERN JUSTIFICATION)))", ((cpp_function_code)(&backlinkToPatternJustification)), NULL);
      defineFunctionObject("RECORD-MODUS-PONENS-JUSTIFICATION", "(DEFUN RECORD-MODUS-PONENS-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&recordModusPonensJustification)), NULL);
      defineFunctionObject("RECORD-AND-INTRODUCTION-JUSTIFICATION", "(DEFUN RECORD-AND-INTRODUCTION-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&recordAndIntroductionJustification)), NULL);
      defineFunctionObject("RECORD-OR-INTRODUCTION-JUSTIFICATION", "(DEFUN RECORD-OR-INTRODUCTION-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&recordOrIntroductionJustification)), NULL);
      defineFunctionObject("RECORD-DISPROOF-JUSTIFICATION", "(DEFUN RECORD-DISPROOF-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&recordDisproofJustification)), NULL);
      defineFunctionObject("RECORD-FAIL-JUSTIFICATION", "(DEFUN RECORD-FAIL-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&recordFailJustification)), NULL);
      defineFunctionObject("RECORD-CLOSED-NOT-JUSTIFICATION", "(DEFUN RECORD-CLOSED-NOT-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&recordClosedNotJustification)), NULL);
      defineFunctionObject("RECORD-EXISTENTIAL-INTRODUCTION-JUSTIFICATION", "(DEFUN RECORD-EXISTENTIAL-INTRODUCTION-JUSTIFICATION ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&recordExistentialIntroductionJustification)), NULL);
      defineFunctionObject("FAILED-GOAL-JUSTIFICATION?", "(DEFUN (FAILED-GOAL-JUSTIFICATION? BOOLEAN) ((SELF JUSTIFICATION)))", ((cpp_function_code)(&failedGoalJustificationP)), NULL);
      defineFunctionObject("CUTOFF-GOAL-JUSTIFICATION?", "(DEFUN (CUTOFF-GOAL-JUSTIFICATION? BOOLEAN) ((SELF JUSTIFICATION)))", ((cpp_function_code)(&cutoffGoalJustificationP)), NULL);
      defineMethodObject("(DEFMETHOD (CONSIFY CONS) ((SELF JUSTIFICATION)) :DOCUMENTATION \"Return a CONS tree representation of the proof `self'.\nEach proof step is represented as a CONS tree of the form\n  (<proposition> (<key> <value>...) <antecedent>...)\nwhere each <antecedent> is a CONS tree representing a subproof.  The\nconsification follows the original proof structure literally, i.e., no\nuninteresting nodes such as patterns or AND-introductions are suppressed.\" :PUBLIC? TRUE)", ((cpp_method_code)(&Justification::consify)), ((cpp_method_code)(NULL)));
      defineFunctionObject("CONSIFY-JUSTIFICATION", "(DEFUN (CONSIFY-JUSTIFICATION CONS) ((SELF JUSTIFICATION) (STYLE KEYWORD)) :DOCUMENTATION \"Return a CONS tree representation of the proof `self'.\nEach proof step is represented as a CONS tree of the form\n  (<proposition> (<key> <value>...) <antecedent>...)\nwhere each <antecedent> is a CONS tree representing a subproof.\n`style' indicates what nodes in the proof tree should be suppressed.\n:RAW preserves the original structure literally, :VERBOSE keeps AND-\nintroductions but suppresses all auxiliary (non-logical) nodes such as\npattern nodes, and :BRIEF additionally suppresses AND-introduction nodes.\" :PUBLIC? TRUE)", ((cpp_function_code)(&consifyJustification)), NULL);
      defineFunctionObject("GET-QUERY-JUSTIFICATIONS", "(DEFUN (GET-QUERY-JUSTIFICATIONS (LIST OF JUSTIFICATION)) ((QUERY QUERY-ITERATOR) (SOLUTIONINDEX INTEGER) (MAXJUSTIFICATIONS INTEGER) (CREATE? BOOLEAN)))", ((cpp_function_code)(&getQueryJustifications)), NULL);
      defineFunctionObject("DERIVE-QUERY-JUSTIFICATIONS", "(DEFUN (DERIVE-QUERY-JUSTIFICATIONS (LIST OF JUSTIFICATION)) ((QUERY QUERY-ITERATOR) (OPTIONS OBJECT) (SOLUTIONINDEX INTEGER) (MAXJUSTIFICATIONS INTEGER)))", ((cpp_function_code)(&deriveQueryJustifications)), NULL);
      defineExternalSlotFromStringifiedSource("(DEFSLOT PROPOSITION FORWARD-CHAINING-GOALS :TYPE (LIST OF FORWARD-GOAL-RECORD) :ALLOCATION :DYNAMIC)");
      defineMethodObject("(DEFMETHOD (DELETED? BOOLEAN) ((SELF FORWARD-GOAL-RECORD)))", ((cpp_method_code)(&ForwardGoalRecord::deletedP)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (DELETED?-SETTER BOOLEAN) ((SELF FORWARD-GOAL-RECORD) (VALUE BOOLEAN)))", ((cpp_method_code)(&ForwardGoalRecord::deletedPSetter)), ((cpp_method_code)(NULL)));
      defineFunctionObject("RECORD-FORWARD-GOAL", "(DEFUN RECORD-FORWARD-GOAL ((FORWARDRULE PROPOSITION) (ARGUMENTS ARGUMENTS-VECTOR) (CONSEQUENTPROPOSITION PROPOSITION)))", ((cpp_function_code)(&recordForwardGoal)), NULL);
      defineFunctionObject("PREDICATION?", "(DEFUN (PREDICATION? BOOLEAN) ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&predicationP)), NULL);
      defineFunctionObject("ASSERTED-AS-TRUE?", "(DEFUN (ASSERTED-AS-TRUE? BOOLEAN) ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&assertedAsTrueP)), NULL);
      defineFunctionObject("ELABORATION-RULE?", "(DEFUN (ELABORATION-RULE? BOOLEAN) ((CONSEQUENTPROPOSITION PROPOSITION) (FORWARDRULE PROPOSITION) (ARGUMENTS ARGUMENTS-VECTOR)))", ((cpp_function_code)(&elaborationRuleP)), NULL);
      defineFunctionObject("GET-FORWARD-GOALS", "(DEFUN (GET-FORWARD-GOALS (LIST OF FORWARD-GOAL-RECORD)) ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&getForwardGoals)), NULL);
      defineExternalSlotFromStringifiedSource("(DEFSLOT PROPOSITION FORWARD-JUSTIFICATIONS :TYPE (LIST OF FORWARD-JUSTIFICATION) :ALLOCATION :DYNAMIC)");
      defineFunctionObject("CREATE-FORWARD-JUSTIFICATION", "(DEFUN (CREATE-FORWARD-JUSTIFICATION FORWARD-JUSTIFICATION) ((CONSEQUENTPROPOSITION PROPOSITION) (FORWARDRULE PROPOSITION) (ANTECEDENTS (CONS OF PROPOSITION))))", ((cpp_function_code)(&createForwardJustification)), NULL);
      defineFunctionObject("RECORD-FORWARD-JUSTIFICATION", "(DEFUN RECORD-FORWARD-JUSTIFICATION ((CONSEQUENTPROPOSITION PROPOSITION) (FORWARDRULE PROPOSITION) (ANTECEDENTS (CONS OF PROPOSITION))))", ((cpp_function_code)(&recordForwardJustification)), NULL);
      defineFunctionObject("STARTUP-JUSTIFICATIONS", "(DEFUN STARTUP-JUSTIFICATIONS () :PUBLIC? TRUE)", ((cpp_function_code)(&startupJustifications)), NULL);
      { MethodSlot* function = lookupFunction(SYM_JUSTIFICATIONS_LOGIC_STARTUP_JUSTIFICATIONS);

        setDynamicSlotValue(function->dynamicSlots, SYM_JUSTIFICATIONS_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_StartupJustifications"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *RECORD-JUSTIFICATIONS?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE every query records justifications to enable\nthe explanation of concluded results.\")");
      defineExplanationPhrase(KWD_JUSTIFICATIONS_SCAN_COLLECTION, KWD_JUSTIFICATIONS_TECHNICAL, "by explicit assertion", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_SCAN_PROPOSITIONS, KWD_JUSTIFICATIONS_TECHNICAL, "by explicit assertion", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_LOOKUP_ASSERTIONS, KWD_JUSTIFICATIONS_TECHNICAL, "by explicit assertion", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_SCAN_COLLECTION, KWD_JUSTIFICATIONS_LAY, "because the system was told this fact", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_SCAN_PROPOSITIONS, KWD_JUSTIFICATIONS_LAY, "because the system was told this fact", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_LOOKUP_ASSERTIONS, KWD_JUSTIFICATIONS_LAY, "because the system was told this fact", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_SPECIALIST, KWD_JUSTIFICATIONS_TECHNICAL, "because it was proven by an inference specialist", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_SPECIALIST, KWD_JUSTIFICATIONS_LAY, "because of a specialized reasoning procedure", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_COMPUTED_PREDICATE, KWD_JUSTIFICATIONS_TECHNICAL, "because of a computation", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_COMPUTED_PREDICATE, KWD_JUSTIFICATIONS_LAY, "because of a computation", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_GOAL_COMPLEMENT, KWD_JUSTIFICATIONS_TECHNICAL, "because its argument was proven false", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_GOAL_COMPLEMENT, KWD_JUSTIFICATIONS_LAY, "because its argument is false", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_EQUIVALENCE, KWD_JUSTIFICATIONS_TECHNICAL, "from equivalence", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_EQUIVALENCE, KWD_JUSTIFICATIONS_LAY, "because its arguments are equivalent", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_SUBSUMPTION_TEST, KWD_JUSTIFICATIONS_TECHNICAL, "because of a successful subsumption test", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_SUBSUMPTION_TEST, KWD_JUSTIFICATIONS_LAY, "because of a successful subsumption test", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_FAILURE, KWD_JUSTIFICATIONS_TECHNICAL, "could not be proven", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_FAILURE, KWD_JUSTIFICATIONS_LAY, "could not be proven", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_MODUS_PONENS, KWD_JUSTIFICATIONS_TECHNICAL, "by Modus Ponens", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_MODUS_PONENS, KWD_JUSTIFICATIONS_LAY, "because an if-then rule applies", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_MODUS_TOLLENS, KWD_JUSTIFICATIONS_TECHNICAL, "by Modus Tollens", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_MODUS_TOLLENS, KWD_JUSTIFICATIONS_TECHNICAL, "(p => q, ~q |= ~p)", 1, KWD_JUSTIFICATIONS_AMPLIFICATION);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_MODUS_TOLLENS, KWD_JUSTIFICATIONS_LAY, "because an if-then rule was used backwards", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_MODUS_TOLLENS, KWD_JUSTIFICATIONS_LAY, "(if P then Q with Q false allows us to conclude P)", 1, KWD_JUSTIFICATIONS_AMPLIFICATION);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_AND_INTRODUCTION, KWD_JUSTIFICATIONS_TECHNICAL, "by And-Introduction", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_AND_INTRODUCTION, KWD_JUSTIFICATIONS_LAY, "because all parts of an AND expression were true", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_AND_INTRODUCTION, KWD_JUSTIFICATIONS_LAY, "because parts of an AND expression were true", 1, KWD_JUSTIFICATIONS_PARTIAL);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_AND_INTRODUCTION, KWD_JUSTIFICATIONS_TECHNICAL, "by Not-Or-Introduction", 1, KWD_JUSTIFICATIONS_REVERSE);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_AND_INTRODUCTION, KWD_JUSTIFICATIONS_LAY, "because all parts of an OR expression were false", 1, KWD_JUSTIFICATIONS_REVERSE);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_AND_INTRODUCTION, KWD_JUSTIFICATIONS_TECHNICAL, "(~p, ~q |= ~(p v q))", 2, KWD_JUSTIFICATIONS_REVERSE, KWD_JUSTIFICATIONS_AMPLIFICATION);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_AND_INTRODUCTION, KWD_JUSTIFICATIONS_LAY, "(therefore the OR is also false)", 2, KWD_JUSTIFICATIONS_REVERSE, KWD_JUSTIFICATIONS_AMPLIFICATION);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_OR_INTRODUCTION, KWD_JUSTIFICATIONS_TECHNICAL, "by Or-Introduction", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_OR_INTRODUCTION, KWD_JUSTIFICATIONS_LAY, "because at least one part of an OR expression was true", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_OR_INTRODUCTION, KWD_JUSTIFICATIONS_TECHNICAL, "by Not-And-Introduction", 1, KWD_JUSTIFICATIONS_REVERSE);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_OR_INTRODUCTION, KWD_JUSTIFICATIONS_LAY, "because at least one part of an AND expression was false", 1, KWD_JUSTIFICATIONS_REVERSE);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_OR_INTRODUCTION, KWD_JUSTIFICATIONS_TECHNICAL, "(~p |= ~(p & q))", 2, KWD_JUSTIFICATIONS_REVERSE, KWD_JUSTIFICATIONS_AMPLIFICATION);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_OR_INTRODUCTION, KWD_JUSTIFICATIONS_LAY, "(therefore the AND is also false)", 2, KWD_JUSTIFICATIONS_REVERSE, KWD_JUSTIFICATIONS_AMPLIFICATION);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_DISPROOF, KWD_JUSTIFICATIONS_TECHNICAL, "by disproof", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_DISPROOF, KWD_JUSTIFICATIONS_LAY, "by proving the negation", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_DISPROOF, KWD_JUSTIFICATIONS_TECHNICAL, "by Double-Negation-Introduction", 1, KWD_JUSTIFICATIONS_REVERSE);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_DISPROOF, KWD_JUSTIFICATIONS_LAY, "by negating a negation", 1, KWD_JUSTIFICATIONS_REVERSE);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_CLOSED_NOT_INTRODUCTION, KWD_JUSTIFICATIONS_TECHNICAL, "because the argument proposition was not derivable and it uses closed-world semantics", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_CLOSED_NOT_INTRODUCTION, KWD_JUSTIFICATIONS_LAY, "because the argument proposition could not be proven and it is a closed-world proposition", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_FAIL_INTRODUCTION, KWD_JUSTIFICATIONS_TECHNICAL, "because the argument proposition was not derivable", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_FAIL_INTRODUCTION, KWD_JUSTIFICATIONS_LAY, "because the argument proposition could not be proven", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_EXISTENTIAL_INTRODUCTION, KWD_JUSTIFICATIONS_TECHNICAL, "by Existential Introduction", 0);
      defineExplanationPhrase(KWD_JUSTIFICATIONS_EXISTENTIAL_INTRODUCTION, KWD_JUSTIFICATIONS_LAY, "because it was true for at least one case", 0);
    }
  }
}

Surrogate* SGT_JUSTIFICATIONS_LOGIC_JUSTIFICATION = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_INFERENCE_RULE = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_PROPOSITION = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_ANTECEDENTS = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_PATTERN_JUSTIFICATION = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_SUBSTITUTION = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_REVERSE_POLARITYp = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_TRUTH_VALUE = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_POSITIVE_SCORE = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_NEGATIVE_SCORE = NULL;

Keyword* KWD_JUSTIFICATIONS_PRIMITIVE_STRATEGY = NULL;

Surrogate* SGT_JUSTIFICATIONS_LOGIC_PRIMITIVE_STRATEGY = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_STRATEGY = NULL;

Surrogate* SGT_JUSTIFICATIONS_LOGIC_PATTERN_VARIABLE = NULL;

Keyword* KWD_JUSTIFICATIONS_PATTERN = NULL;

Surrogate* SGT_JUSTIFICATIONS_LOGIC_PROPOSITION = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_JUSTIFICATION = NULL;

Keyword* KWD_JUSTIFICATIONS_UP_TRUE = NULL;

Keyword* KWD_JUSTIFICATIONS_UP_FAIL = NULL;

Keyword* KWD_JUSTIFICATIONS_FAILURE = NULL;

Keyword* KWD_JUSTIFICATIONS_SCAN_COLLECTION = NULL;

Keyword* KWD_JUSTIFICATIONS_TECHNICAL = NULL;

Keyword* KWD_JUSTIFICATIONS_SCAN_PROPOSITIONS = NULL;

Keyword* KWD_JUSTIFICATIONS_LOOKUP_ASSERTIONS = NULL;

Keyword* KWD_JUSTIFICATIONS_LAY = NULL;

Keyword* KWD_JUSTIFICATIONS_SPECIALIST = NULL;

Keyword* KWD_JUSTIFICATIONS_COMPUTED_PREDICATE = NULL;

Keyword* KWD_JUSTIFICATIONS_GOAL_COMPLEMENT = NULL;

Keyword* KWD_JUSTIFICATIONS_EQUIVALENCE = NULL;

Keyword* KWD_JUSTIFICATIONS_SUBSUMPTION_TEST = NULL;

Surrogate* SGT_JUSTIFICATIONS_LOGIC_PATTERN_RECORD = NULL;

Surrogate* SGT_JUSTIFICATIONS_STELLA_KEY_VALUE_LIST = NULL;

Keyword* KWD_JUSTIFICATIONS_MODUS_TOLLENS = NULL;

Keyword* KWD_JUSTIFICATIONS_MODUS_PONENS = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_ANTECEDENTS_RULE = NULL;

Keyword* KWD_JUSTIFICATIONS_NOT = NULL;

Keyword* KWD_JUSTIFICATIONS_AMPLIFICATION = NULL;

Symbol* SYM_JUSTIFICATIONS_STELLA_ARGUMENTS = NULL;

Keyword* KWD_JUSTIFICATIONS_POPPED = NULL;

Keyword* KWD_JUSTIFICATIONS_AND_INTRODUCTION = NULL;

Keyword* KWD_JUSTIFICATIONS_PARTIAL = NULL;

Keyword* KWD_JUSTIFICATIONS_REVERSE = NULL;

Keyword* KWD_JUSTIFICATIONS_OR_INTRODUCTION = NULL;

Keyword* KWD_JUSTIFICATIONS_DISPROOF = NULL;

Keyword* KWD_JUSTIFICATIONS_FAIL_INTRODUCTION = NULL;

Keyword* KWD_JUSTIFICATIONS_CLOSED_NOT_INTRODUCTION = NULL;

Keyword* KWD_JUSTIFICATIONS_FAIL = NULL;

Keyword* KWD_JUSTIFICATIONS_EXISTENTIAL_INTRODUCTION = NULL;

Keyword* KWD_JUSTIFICATIONS_TIMEOUT = NULL;

Keyword* KWD_JUSTIFICATIONS_DEPTH_CUTOFF = NULL;

Keyword* KWD_JUSTIFICATIONS_RAW = NULL;

Keyword* KWD_JUSTIFICATIONS_INFERENCE_RULE = NULL;

Keyword* KWD_JUSTIFICATIONS_STRATEGY = NULL;

Keyword* KWD_JUSTIFICATIONS_TRUTH_VALUE = NULL;

Keyword* KWD_JUSTIFICATIONS_POSITIVE_SCORE = NULL;

Keyword* KWD_JUSTIFICATIONS_SUBSTITUTION = NULL;

Symbol* SYM_JUSTIFICATIONS_STELLA_NOT = NULL;

Keyword* KWD_JUSTIFICATIONS_HOW_MANY = NULL;

Keyword* KWD_JUSTIFICATIONS_NONE = NULL;

Surrogate* SGT_JUSTIFICATIONS_LOGIC_FORWARD_GOAL_RECORD = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_FORWARD_GOAL = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_FORWARD_RULE = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_FORWARD_CHAINING_GOALS = NULL;

Symbol* SYM_JUSTIFICATIONS_STELLA_PREDICATE = NULL;

Surrogate* SGT_JUSTIFICATIONS_PL_KERNEL_KB_HOLDS = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_MASTER_PROPOSITION = NULL;

Surrogate* SGT_JUSTIFICATIONS_LOGIC_FORWARD_JUSTIFICATION = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_CONSEQUENT = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_FORWARD_JUSTIFICATIONS = NULL;

Symbol* SYM_JUSTIFICATIONS_LOGIC_STARTUP_JUSTIFICATIONS = NULL;

Symbol* SYM_JUSTIFICATIONS_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
