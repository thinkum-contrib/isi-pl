//  -*- Mode: C++ -*-

// rules.cc

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

List* findMatchableGoals(Proposition* forallprop, Keyword* headortail) {
  { int index = ((headortail == KWD_RULES_HEAD) ? 1 : 0);
    Proposition* proposition = ((Proposition*)((forallprop->arguments->theArray)[index]));
    Cons* variables = NIL;
    List* resultlist = newList();

    { PatternVariable* v = NULL;
      Vector* vector000 = ((Vector*)(dynamicSlotValue(forallprop->dynamicSlots, SYM_RULES_LOGIC_IO_VARIABLES, NULL)));
      int index000 = 0;
      int length000 = vector000->length();

      while (index000 < length000) {
        v = ((PatternVariable*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        variables = cons(v, variables);
      }
    }
    if (variables->length() > 1) {
      if (headortail == KWD_RULES_TAIL) {
        { Keyword* testValue000 = proposition->kind;

          if (testValue000 == KWD_RULES_AND) {
            { Object* g = NULL;
              Vector* vector001 = proposition->arguments;
              int index001 = 0;
              int length001 = vector001->length();

              while (index001 < length001) {
                g = (vector001->theArray)[index001];
                index001 = index001 + 1;
                collectMatchingRuleGoals(((Proposition*)(g)), variables, KWD_RULES_TAIL, resultlist);
              }
            }
            return (resultlist);
          }
          else if (testValue000 == KWD_RULES_EXISTS) {
            { Proposition* existsbody = ((Proposition*)((proposition->arguments->theArray)[0]));

              if (existsbody->kind == KWD_RULES_AND) {
                { Object* g = NULL;
                  Vector* vector002 = existsbody->arguments;
                  int index002 = 0;
                  int length002 = vector002->length();

                  while (index002 < length002) {
                    g = (vector002->theArray)[index002];
                    index002 = index002 + 1;
                    collectMatchingRuleGoals(((Proposition*)(g)), variables, KWD_RULES_TAIL, resultlist);
                  }
                }
              }
            }
            return (resultlist);
          }
          else {
          }
        }
      }
      else {
      }
    }
    collectMatchingRuleGoals(proposition, variables, headortail, resultlist);
    return (resultlist);
  }
}

void collectMatchingRuleGoals(Proposition* proposition, Cons* toplevelvars, Keyword* headortail, List* collection) {
  { Keyword* testValue000 = proposition->kind;

    if ((testValue000 == KWD_RULES_AND) ||
        (testValue000 == KWD_RULES_OR)) {
      if (headortail == KWD_RULES_HEAD) {
        { Object* arg = NULL;
          Vector* vector000 = proposition->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          while (index000 < length000) {
            arg = (vector000->theArray)[index000];
            index000 = index000 + 1;
            collectMatchingRuleGoals(((Proposition*)(arg)), toplevelvars, headortail, collection);
          }
        }
      }
      else if (headortail == KWD_RULES_TAIL) {
        { int goalcount = collection->length();

          { Object* arg = NULL;
            Vector* vector001 = proposition->arguments;
            int index001 = 0;
            int length001 = vector001->length();

            while (index001 < length001) {
              arg = (vector001->theArray)[index001];
              index001 = index001 + 1;
              collectMatchingRuleGoals(((Proposition*)(arg)), toplevelvars, headortail, collection);
            }
          }
          if (goalcount == collection->length()) {
            { Object* arg = NULL;
              Vector* vector002 = proposition->arguments;
              int index002 = 0;
              int length002 = vector002->length();

              while (index002 < length002) {
                arg = (vector002->theArray)[index002];
                index002 = index002 + 1;
                collectMatchingRuleGoals(((Proposition*)(arg)), toplevelvars, headortail, collection);
              }
            }
          }
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << headortail << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    else if (testValue000 == KWD_RULES_EXISTS) {
      if (headortail == KWD_RULES_HEAD) {
        collectMatchingRuleGoals(((Proposition*)((proposition->arguments->theArray)[0])), toplevelvars, headortail, collection);
      }
      else if (headortail == KWD_RULES_TAIL) {
        { PatternVariable* v = NULL;
          Vector* vector003 = ((Vector*)(dynamicSlotValue(proposition->dynamicSlots, SYM_RULES_LOGIC_IO_VARIABLES, NULL)));
          int index003 = 0;
          int length003 = vector003->length();

          while (index003 < length003) {
            v = ((PatternVariable*)((vector003->theArray)[index003]));
            index003 = index003 + 1;
            toplevelvars = cons(v, toplevelvars);
          }
        }
        collectMatchingRuleGoals(((Proposition*)((proposition->arguments->theArray)[0])), toplevelvars, headortail, collection);
      }
      else {
        { OutputStringStream* stream001 = newOutputStringStream();

          *(stream001->nativeStream) << "`" << headortail << "'" << " is not a valid case option";
          throw *newStellaException(stream001->theStringReader());
        }
      }
    }
    else if (testValue000 == KWD_RULES_FORALL) {
      if (headortail == KWD_RULES_HEAD) {
        { PatternVariable* v = NULL;
          Vector* vector004 = ((Vector*)(dynamicSlotValue(proposition->dynamicSlots, SYM_RULES_LOGIC_IO_VARIABLES, NULL)));
          int index004 = 0;
          int length004 = vector004->length();

          while (index004 < length004) {
            v = ((PatternVariable*)((vector004->theArray)[index004]));
            index004 = index004 + 1;
            toplevelvars = cons(v, toplevelvars);
          }
        }
        collectMatchingRuleGoals(((Proposition*)((proposition->arguments->theArray)[1])), toplevelvars, headortail, collection);
      }
      else if (headortail == KWD_RULES_TAIL) {
      }
      else {
        { OutputStringStream* stream002 = newOutputStringStream();

          *(stream002->nativeStream) << "`" << headortail << "'" << " is not a valid case option";
          throw *newStellaException(stream002->theStringReader());
        }
      }
    }
    else if ((testValue000 == KWD_RULES_ISA) ||
        ((testValue000 == KWD_RULES_PREDICATE) ||
         ((testValue000 == KWD_RULES_FUNCTION) ||
          ((testValue000 == KWD_RULES_NOT) ||
           (testValue000 == KWD_RULES_IMPLIES))))) {
      { boolean testValue001 = FALSE;

        { boolean alwaysP000 = TRUE;

          { Object* a = NULL;
            Cons* iter000 = extractGoalArguments(proposition);

            while (!(iter000 == NIL)) {
              a = iter000->value;
              iter000 = iter000->rest;
              if (!(toplevelvars->memberP(a) ||
                  (!isaP(a, SGT_RULES_LOGIC_PATTERN_VARIABLE)))) {
                alwaysP000 = FALSE;
                break;
              }
            }
          }
          testValue001 = alwaysP000;
        }
        if (testValue001) {
          testValue001 = ((boolean)(extractGoalDescription(proposition, headortail))) &&
              (!(proposition->operatoR == SGT_RULES_PL_KERNEL_KB_HOLDS));
        }
        if (testValue001) {
          collection->insert(proposition);
        }
      }
    }
    else {
    }
  }
}

boolean atomicForallArgumentP(Proposition* forallprop, Keyword* headortail) {
  return (atomicGoalPropositionP(((headortail == KWD_RULES_HEAD) ? ((Proposition*)((forallprop->arguments->theArray)[1])) : ((Proposition*)((forallprop->arguments->theArray)[0])))));
}

boolean atomicGoalPropositionP(Proposition* proposition) {
  { Keyword* testValue000 = proposition->kind;

    if ((testValue000 == KWD_RULES_ISA) ||
        ((testValue000 == KWD_RULES_PREDICATE) ||
         ((testValue000 == KWD_RULES_FUNCTION) ||
          (testValue000 == KWD_RULES_IMPLIES)))) {
      return (((boolean)(extractGoalDescription(proposition, NULL))));
    }
    else if (testValue000 == KWD_RULES_NOT) {
      return (((boolean)(extractGoalDescription(((Proposition*)((proposition->arguments->theArray)[0])), NULL))));
    }
    else if (testValue000 == KWD_RULES_AND) {
      { int count = 0;

        { Proposition* conjunct = NULL;
          Vector* vector000 = ((Vector*)(proposition->arguments));
          int index000 = 0;
          int length000 = vector000->length();

          while (index000 < length000) {
            conjunct = ((Proposition*)((vector000->theArray)[index000]));
            index000 = index000 + 1;
            if ((!(conjunct->kind == KWD_RULES_AND)) &&
                atomicGoalPropositionP(conjunct)) {
              count = count + 1;
            }
            else {
              return (FALSE);
            }
          }
        }
        return (count == 1);
      }
    }
    else {
      return (FALSE);
    }
  }
}

boolean atomicGoalDescriptionP(Description* description) {
  if (namedDescriptionP(description)) {
    return (TRUE);
  }
  { Description* complement = ((Description*)(dynamicSlotValue(description->dynamicSlots, SYM_RULES_LOGIC_COMPLEMENT_DESCRIPTION, NULL)));

    if (((boolean)(complement)) &&
        namedDescriptionP(complement)) {
      return (TRUE);
    }
    else {
      return (atomicGoalPropositionP(description->proposition));
    }
  }
}

boolean variableArityGoalPropositionP(Proposition* proposition) {
  { Keyword* testValue000 = proposition->kind;

    if ((testValue000 == KWD_RULES_PREDICATE) ||
        (testValue000 == KWD_RULES_FUNCTION)) {
      { Description* description = extractGoalDescription(proposition, NULL);

        return (((boolean)(description)) &&
            variableArityP(description));
      }
    }
    else {
    }
  }
  return (FALSE);
}

boolean chainableRelationP(NamedDescription* description, Keyword* headortail) {
  if (!((boolean)(headortail))) {
    return (TRUE);
  }
  { Cons* nonpermittedpredicates = NULL;

    if (headortail == KWD_RULES_TAIL) {
      nonpermittedpredicates = getQuotedTree("((/PL-KERNEL-KB/@HOLDS /PL-KERNEL-KB/@MEMBER-OF /PL-KERNEL-KB/@INSTANCE-OF /PL-KERNEL-KB/@SUBSET-OF @NUMBER-WRAPPER.PLUS @NUMBER-WRAPPER.MINUS @NUMBER-WRAPPER.TIMES @NUMBER-WRAPPER.DIVIDE) \"/LOGIC\")", "/LOGIC");
    }
    else if (headortail == KWD_RULES_HEAD) {
      nonpermittedpredicates = getQuotedTree("((@NUMBER-WRAPPER.PLUS @NUMBER-WRAPPER.MINUS @NUMBER-WRAPPER.TIMES @NUMBER-WRAPPER.DIVIDE) \"/LOGIC\")", "/LOGIC");
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << headortail << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    return (!nonpermittedpredicates->memberP(description->surrogateValueInverse));
  }
}

Description* extractGoalDescription(Proposition* goal, Keyword* headortail) {
  { Vector* arguments = goal->arguments;

    { Keyword* testValue000 = goal->kind;

      if ((testValue000 == KWD_RULES_ISA) ||
          ((testValue000 == KWD_RULES_PREDICATE) ||
           ((testValue000 == KWD_RULES_FUNCTION) ||
            (testValue000 == KWD_RULES_IMPLIES)))) {
        if (isaP(goal->operatoR, SGT_RULES_STELLA_SURROGATE)) {
          { NamedDescription* description = getDescription(((Surrogate*)(goal->operatoR)));

            if (!((boolean)(description))) {
              { OutputStringStream* stream000 = newOutputStringStream();

                { 
                  BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                  *(stream000->nativeStream) << "ERROR: " << "Can't finalize relations because relation " << "`" << ((Surrogate*)(goal->operatoR))->symbolName << "'" << " is undefined." << "." << std::endl;
                  helpSignalPropositionError(stream000, KWD_RULES_ERROR);
                }
                throw *newPropositionError(stream000->theStringReader());
              }
            }
            if (chainableRelationP(description, headortail)) {
              return (description);
            }
          }
        }
      }
      else if (testValue000 == KWD_RULES_NOT) {
        { Description* argumentdescription = extractGoalDescription(((Proposition*)((arguments->theArray)[0])), headortail);

          if (((boolean)(argumentdescription))) {
            return (getComplementOfGoalDescription(((NamedDescription*)(argumentdescription))));
          }
        }
      }
      else {
      }
    }
    return (NULL);
  }
}

Cons* extractGoalArguments(Proposition* goal) {
  { Vector* arguments = goal->arguments;

    { Keyword* testValue000 = goal->kind;

      if ((testValue000 == KWD_RULES_ISA) ||
          ((testValue000 == KWD_RULES_PREDICATE) ||
           ((testValue000 == KWD_RULES_FUNCTION) ||
            (testValue000 == KWD_RULES_IMPLIES)))) {
        { Cons* result = NIL;

          { Object* arg = NULL;
            Vector* vector000 = arguments;
            int index000 = 0;
            int length000 = vector000->length();
            Cons* collect000 = NULL;

            while (index000 < length000) {
              arg = (vector000->theArray)[index000];
              index000 = index000 + 1;
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(arg, NIL);
                  if (result == NIL) {
                    result = collect000;
                  }
                  else {
                    addConsToEndOfConsList(result, collect000);
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
          return (result);
        }
      }
      else if (testValue000 == KWD_RULES_NOT) {
        return (extractGoalArguments(((Proposition*)((arguments->theArray)[0]))));
      }
      else {
        return (NIL);
      }
    }
  }
}

Proposition* substituteProposition(Proposition* proposition, Proposition* outprop, Proposition* inprop) {
  if (proposition == outprop) {
    return (inprop);
  }
  { Object* arg = NULL;
    int i = NULL_INTEGER;
    Vector* vector000 = proposition->arguments;
    int index000 = 0;
    int length000 = vector000->length();
    int iter000 = 0;

    while (index000 < length000) {
      arg = (vector000->theArray)[index000];
      index000 = index000 + 1;
      i = iter000;
      iter000 = iter000 + 1;
      if (arg == outprop) {
        (proposition->arguments->theArray)[i] = inprop;
      }
      else if (isaP(arg, SGT_RULES_LOGIC_PROPOSITION)) {
        substituteProposition(((Proposition*)(arg)), outprop, inprop);
      }
    }
  }
  return (proposition);
}

Proposition* extractInvertedGoal(Proposition* proposition, Proposition* goal) {
  if (goal->kind == KWD_RULES_NOT) {
    return (extractInvertedGoal(proposition, ((Proposition*)((goal->arguments->theArray)[0]))));
  }
  { Keyword* testValue000 = proposition->kind;

    if (testValue000 == KWD_RULES_NOT) {
      if (equivalentPropositionsP(((Proposition*)((proposition->arguments->theArray)[0])), goal, NULL)) {
        return (proposition);
      }
      else {
        return (extractInvertedGoal(((Proposition*)((proposition->arguments->theArray)[0])), goal));
      }
    }
    else if ((testValue000 == KWD_RULES_AND) ||
        (testValue000 == KWD_RULES_OR)) {
      { Proposition* result = NULL;

        { Object* arg = NULL;
          Vector* vector000 = proposition->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          while (index000 < length000) {
            arg = (vector000->theArray)[index000];
            index000 = index000 + 1;
            result = extractInvertedGoal(((Proposition*)(arg)), goal);
            if (((boolean)(result))) {
              return (result);
            }
          }
        }
      }
    }
    else {
      if (equivalentPropositionsP(proposition, goal, NULL)) {
        return (proposition);
      }
    }
  }
  return (NULL);
}

Proposition* invertForallAroundGoal(Proposition* forallprop, Proposition* goal, Keyword* headortail, boolean contrapositiveP) {
  { KeyValueList* mapping = newKeyValueList();
    Proposition* invertedforall = copyProposition(forallprop, mapping);
    Object* oldhead = (invertedforall->arguments->theArray)[1];
    Object* oldtail = (invertedforall->arguments->theArray)[0];
    Proposition* newgoal = ((Proposition*)(mapping->lookup(goal)));
    Cons* newgoalarguments = extractGoalArguments(newgoal);
    Proposition* headprime = NULL;
    Proposition* tailprime = NULL;
    Proposition* newhead = NULL;
    Proposition* newtail = NULL;

    if (contrapositiveP) {
      oldhead = invertProposition(((Proposition*)(oldhead)));
      oldtail = invertProposition(((Proposition*)(oldtail)));
      newgoal = extractInvertedGoal(((headortail == KWD_RULES_HEAD) ? ((Proposition*)(oldhead)) : ((Proposition*)(oldtail))), newgoal);
      (invertedforall->arguments->theArray)[0] = oldhead;
      (invertedforall->arguments->theArray)[1] = oldtail;
      oldhead = oldtail;
      oldtail = (invertedforall->arguments->theArray)[0];
      headortail = ((headortail == KWD_RULES_HEAD) ? KWD_RULES_TAIL : KWD_RULES_HEAD);
    }
    { boolean testValue000 = FALSE;

      testValue000 = newgoal == (((headortail == KWD_RULES_HEAD) ? oldhead : oldtail));
      if (testValue000) {
        { boolean alwaysP000 = TRUE;

          { Object* arg = NULL;
            PatternVariable* v = NULL;
            Cons* iter000 = newgoalarguments;
            Vector* vector000 = ((Vector*)(dynamicSlotValue(invertedforall->dynamicSlots, SYM_RULES_LOGIC_IO_VARIABLES, NULL)));
            int index000 = 0;
            int length000 = vector000->length();

            while ((!(iter000 == NIL)) &&
                (index000 < length000)) {
              arg = iter000->value;
              iter000 = iter000->rest;
              v = ((PatternVariable*)((vector000->theArray)[index000]));
              index000 = index000 + 1;
              if (!(arg == v)) {
                alwaysP000 = FALSE;
                break;
              }
            }
          }
          testValue000 = alwaysP000;
        }
        if (testValue000) {
          testValue000 = newgoalarguments->length() == ((Vector*)(dynamicSlotValue(invertedforall->dynamicSlots, SYM_RULES_LOGIC_IO_VARIABLES, NULL)))->length();
        }
      }
      if (testValue000) {
        return (invertedforall);
      }
    }
    if (headortail == KWD_RULES_HEAD) {
      headprime = substituteProposition(((Proposition*)(oldhead)), newgoal, FALSE_PROPOSITION);
      normalizeProposition(headprime);
      if (headprime->operatoR == SGT_RULES_STELLA_FALSE) {
        newtail = ((Proposition*)(oldtail));
      }
      else {
        {
          oldtail = invertProposition(((Proposition*)(oldtail)));
          newtail = disjoinPropositions(consList(2, oldtail, headprime));
          newtail = invertProposition(newtail);
          normalizeProposition(newtail);
        }
      }
      (invertedforall->arguments->theArray)[0] = newtail;
      (invertedforall->arguments->theArray)[1] = newgoal;
    }
    else if (headortail == KWD_RULES_TAIL) {
      tailprime = substituteProposition(((Proposition*)(oldtail)), newgoal, TRUE_PROPOSITION);
      normalizeProposition(tailprime);
      if (tailprime->operatoR == SGT_RULES_STELLA_TRUE) {
        newhead = ((Proposition*)(oldhead));
      }
      else {
        { Cons* residuevariables = NIL;

          tailprime = invertProposition(tailprime);
          newhead = disjoinPropositions(consList(2, tailprime, oldhead));
          { PatternVariable* vbl = NULL;
            Vector* vector001 = ((Vector*)(dynamicSlotValue(invertedforall->dynamicSlots, SYM_RULES_LOGIC_IO_VARIABLES, NULL)));
            int index001 = 0;
            int length001 = vector001->length();
            Cons* collect000 = NULL;

            while (index001 < length001) {
              vbl = ((PatternVariable*)((vector001->theArray)[index001]));
              index001 = index001 + 1;
              if (!newgoalarguments->memberP(vbl)) {
                if (!((boolean)(collect000))) {
                  {
                    collect000 = cons(vbl, NIL);
                    if (residuevariables == NIL) {
                      residuevariables = collect000;
                    }
                    else {
                      addConsToEndOfConsList(residuevariables, collect000);
                    }
                  }
                }
                else {
                  {
                    collect000->rest = cons(vbl, NIL);
                    collect000 = collect000->rest;
                  }
                }
              }
            }
          }
          if (!(residuevariables == NIL)) {
            { Proposition* nestedforall = createProposition(SYM_RULES_STELLA_FORALL, 2);

              setDynamicSlotValue(nestedforall->dynamicSlots, SYM_RULES_LOGIC_IO_VARIABLES, copyConsListToVariablesVector(residuevariables), NULL);
              (nestedforall->arguments->theArray)[0] = TRUE_PROPOSITION;
              (nestedforall->arguments->theArray)[1] = newhead;
              newhead = nestedforall;
            }
          }
          normalizeProposition(newhead);
        }
      }
      (invertedforall->arguments->theArray)[0] = newgoal;
      (invertedforall->arguments->theArray)[1] = newhead;
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << headortail << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    { Cons* newvariables = extractGoalArguments(newgoal);

      { Object* v = NULL;
        int i = NULL_INTEGER;
        Cons* iter001 = newvariables;
        int iter002 = 0;

        while (!(iter001 == NIL)) {
          v = iter001->value;
          iter001 = iter001->rest;
          i = iter002;
          iter002 = iter002 + 1;
          if (!isaP(v, SGT_RULES_LOGIC_PATTERN_VARIABLE)) {
            { PatternVariable* constantvbl = createVariable(NULL, NULL, FALSE);

              updateSkolemType(constantvbl, logicalType(v));
              newvariables->nthSetter(constantvbl, i);
              if (headortail == KWD_RULES_HEAD) {
                (invertedforall->arguments->theArray)[0] = (conjoinTwoPropositions(createEquivalenceProposition(constantvbl, v), ((Proposition*)((invertedforall->arguments->theArray)[0]))));
              }
              else if (headortail == KWD_RULES_TAIL) {
                { Proposition* negatedequivalence = createEquivalenceProposition(constantvbl, v);

                  invertProposition(negatedequivalence);
                  (invertedforall->arguments->theArray)[1] = (disjoinPropositions(consList(2, negatedequivalence, (invertedforall->arguments->theArray)[1])));
                }
              }
              else {
                { OutputStringStream* stream001 = newOutputStringStream();

                  *(stream001->nativeStream) << "`" << headortail << "'" << " is not a valid case option";
                  throw *newStellaException(stream001->theStringReader());
                }
              }
              normalizeProposition(((Proposition*)((invertedforall->arguments->theArray)[0])));
            }
          }
        }
      }
      setDynamicSlotValue(invertedforall->dynamicSlots, SYM_RULES_LOGIC_IO_VARIABLES, copyConsListToVariablesVector(newvariables), NULL);
    }
    recursivelyFastenDownPropositions(invertedforall, FALSE);
    return (invertedforall);
  }
}

Object* constructDescriptionFromForallProposition(Proposition* forallprop, Keyword* headortail) {
  { Description* description = newDescription();

    description->proposition = ((Proposition*)((forallprop->arguments->theArray)[(((headortail == KWD_RULES_HEAD) ? 1 : 0))]));
    description->ioVariables = ((Vector*)(dynamicSlotValue(forallprop->dynamicSlots, SYM_RULES_LOGIC_IO_VARIABLES, NULL)))->copy();
    { 
      BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_RULES_DESCRIPTION);
      return (finishBuildingDescription(description, TRUE));
    }
  }
}

void markAsForwardRule(Proposition* impliesprop) {
  { Description* head = ((Description*)((impliesprop->arguments->theArray)[1]));

    if ((!namedDescriptionP(head)) &&
        (!((boolean)(((Description*)(dynamicSlotValue(head->dynamicSlots, SYM_RULES_LOGIC_COMPLEMENT_DESCRIPTION, NULL))))))) {
      setDynamicSlotValue(impliesprop->dynamicSlots, SYM_RULES_LOGIC_FORWARD_ONLYp, (TRUE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
    }
  }
}

void deriveOneSatelliteRule(Proposition* masterforall, Proposition* goal, Keyword* headortail, boolean contrapositiveP) {
  { Proposition* invertedforall = NULL;
    Description* head = NULL;
    Description* tail = NULL;
    boolean overrideforwardonlyP = FALSE;

    if ((headortail == KWD_RULES_TAIL) &&
        (((!atomicGoalPropositionP(((Proposition*)((masterforall->arguments->theArray)[0])))) ||
        variableArityGoalPropositionP(((Proposition*)((masterforall->arguments->theArray)[0])))) &&
         (!contrapositiveP))) {
      deriveComplexForwardRule(goal, masterforall);
      return;
    }
    { 
      BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_RULES_DESCRIPTION);
      invertedforall = invertForallAroundGoal(masterforall, goal, headortail, contrapositiveP);
    }
    if (contrapositiveP) {
      if (headortail == KWD_RULES_HEAD) {
        headortail = KWD_RULES_TAIL;
      }
      else if (headortail == KWD_RULES_TAIL) {
        headortail = KWD_RULES_HEAD;
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << headortail << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    if (headortail == KWD_RULES_HEAD) {
      head = extractGoalDescription(((Proposition*)((invertedforall->arguments->theArray)[1])), NULL);
      tail = ((Description*)(constructDescriptionFromForallProposition(invertedforall, KWD_RULES_TAIL)));
    }
    else if (headortail == KWD_RULES_TAIL) {
      tail = extractGoalDescription(((Proposition*)((invertedforall->arguments->theArray)[0])), NULL);
      head = ((Description*)(constructDescriptionFromForallProposition(invertedforall, KWD_RULES_HEAD)));
    }
    else {
      { OutputStringStream* stream001 = newOutputStringStream();

        *(stream001->nativeStream) << "`" << headortail << "'" << " is not a valid case option";
        throw *newStellaException(stream001->theStringReader());
      }
    }
    if (((BooleanWrapper*)(dynamicSlotValue(masterforall->dynamicSlots, SYM_RULES_LOGIC_FORWARD_ONLYp, FALSE_WRAPPER)))->wrapperValue &&
        (headortail == KWD_RULES_HEAD)) {
      overrideforwardonlyP = namedDescriptionP(head) &&
          (namedDescriptionP(tail) &&
           (head->arity() == tail->arity()));
      if (!overrideforwardonlyP) {
        return;
      }
    }
    { Proposition* impliesprop = createImpliesProposition(tail, head);

      { 
        BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_RULES_EXTENSIONAL_ASSERTION);
        { Proposition* duplicate = recursivelyFastenDownPropositions(impliesprop, FALSE);

          if (!(duplicate == impliesprop)) {
            impliesprop = duplicate;
          }
          else if (headortail == KWD_RULES_TAIL) {
            markAsForwardRule(impliesprop);
          }
        }
      }
      if (masterforall->satellitePropositions_reader()->emptyP()) {
        setDynamicSlotValue(masterforall->dynamicSlots, SYM_RULES_LOGIC_SATELLITE_PROPOSITIONS, newList(), NULL);
      }
      masterforall->satellitePropositions_reader()->insertNew(impliesprop);
      setDynamicSlotValue(impliesprop->dynamicSlots, SYM_RULES_LOGIC_MASTER_PROPOSITION, masterforall, NULL);
      if (((BooleanWrapper*)(dynamicSlotValue(masterforall->dynamicSlots, SYM_RULES_LOGIC_FORWARD_ONLYp, FALSE_WRAPPER)))->wrapperValue &&
          (!overrideforwardonlyP)) {
        if (contrapositiveP) {
          setDynamicSlotValue(impliesprop->dynamicSlots, SYM_RULES_LOGIC_BACKWARD_ONLYp, (TRUE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
        }
        else {
          setDynamicSlotValue(impliesprop->dynamicSlots, SYM_RULES_LOGIC_FORWARD_ONLYp, (TRUE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
        }
      }
      if (((BooleanWrapper*)(dynamicSlotValue(masterforall->dynamicSlots, SYM_RULES_LOGIC_BACKWARD_ONLYp, FALSE_WRAPPER)))->wrapperValue) {
        if (contrapositiveP) {
          setDynamicSlotValue(impliesprop->dynamicSlots, SYM_RULES_LOGIC_FORWARD_ONLYp, (TRUE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
        }
        else {
          setDynamicSlotValue(impliesprop->dynamicSlots, SYM_RULES_LOGIC_BACKWARD_ONLYp, (TRUE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
        }
      }
      if (((BooleanWrapper*)(dynamicSlotValue(masterforall->dynamicSlots, SYM_RULES_LOGIC_DONT_OPTIMIZEp, FALSE_WRAPPER)))->wrapperValue) {
        setDynamicSlotValue(impliesprop->dynamicSlots, SYM_RULES_LOGIC_DONT_OPTIMIZEp, (TRUE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
        tail = ((Description*)((impliesprop->arguments->theArray)[0]));
        if (!((boolean)(tail->nativeRelation()))) {
          setDynamicSlotValue(tail->dynamicSlots, SYM_RULES_LOGIC_DONT_OPTIMIZEp, (TRUE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
        }
        head = ((Description*)((impliesprop->arguments->theArray)[1]));
        if (!((boolean)(head->nativeRelation()))) {
          setDynamicSlotValue(head->dynamicSlots, SYM_RULES_LOGIC_DONT_OPTIMIZEp, (TRUE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
        }
      }
    }
  }
}

void equateAndSimplifyForallArgument(Proposition* proposition) {
  { 
    BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_RULES_DESCRIPTION);
    try {
      equateTopLevelEquivalences(proposition);
    }
    catch (Clash& _e) {
      Clash* e = &_e;

      *(STANDARD_ERROR->nativeStream) << exceptionMessage(e) << std::endl;
    }
    tightenArgumentBindings(proposition, NULL);
    simplifyProposition(proposition);
  }
}

// If true, inversion of forall propositions happens lazily.
// I.e., satellite rules are generated on-demand during inference only if they
// are actually needed.
boolean oLAZY_SATELLITE_RULESpo = FALSE;

boolean deriveSatelliteRulesForGoalP(Proposition* forallprop, Description* goaldescription, Keyword* direction, boolean lazysatellitesP) {
  finalizeObjects();
  { boolean createdsatellitesP = FALSE;
    Description* goaldesc = NULL;
    boolean positiveonlyP = direction == KWD_RULES_POSITIVE;
    boolean contrapositiveonlyP = direction == KWD_RULES_CONTRAPOSITIVE;

    { 
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, forallprop->homeContext);
      BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
      { Proposition* goal = NULL;
        Cons* iter000 = findMatchableGoals(forallprop, KWD_RULES_HEAD)->theConsList;

        while (!(iter000 == NIL)) {
          goal = ((Proposition*)(iter000->value));
          iter000 = iter000->rest;
          if ((!((boolean)(goaldescription))) ||
              (goaldescription == extractGoalDescription(goal, KWD_RULES_HEAD))) {
            createdsatellitesP = TRUE;
            if (lazysatellitesP) {
              if (!((boolean)(goaldescription))) {
                goaldesc = extractGoalDescription(goal, KWD_RULES_HEAD);
              }
              else {
                goaldesc = goaldescription;
              }
              if (!((boolean)(((SequenceIndex*)(dynamicSlotValue(goaldesc->dynamicSlots, SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES, NULL)))))) {
                setDynamicSlotValue(goaldesc->dynamicSlots, SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES, createSequenceIndex(KWD_RULES_NON_PAGING, NIL), NULL);
              }
              ((SequenceIndex*)(dynamicSlotValue(goaldesc->dynamicSlots, SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES, NULL)))->insert(forallprop);
            }
            else if (!contrapositiveonlyP) {
              deriveOneSatelliteRule(forallprop, goal, KWD_RULES_HEAD, FALSE);
            }
            if ((!positiveonlyP) &&
                ((!((BooleanWrapper*)(dynamicSlotValue(forallprop->dynamicSlots, SYM_RULES_LOGIC_BACKWARD_ONLYp, FALSE_WRAPPER)))->wrapperValue) &&
                 (!atomicForallArgumentP(forallprop, KWD_RULES_TAIL)))) {
              if (lazysatellitesP) {
                setDynamicSlotValue(goaldesc->dynamicSlots, SYM_RULES_LOGIC_DEFERRED_CONTRAPOSITIVESp, TRUE_WRAPPER, NULL);
              }
              else {
                deriveOneSatelliteRule(forallprop, goal, KWD_RULES_HEAD, TRUE);
              }
            }
          }
        }
      }
      if ((!((BooleanWrapper*)(dynamicSlotValue(forallprop->dynamicSlots, SYM_RULES_LOGIC_BACKWARD_ONLYp, FALSE_WRAPPER)))->wrapperValue) &&
          (atomicForallArgumentP(forallprop, KWD_RULES_TAIL) ||
           ((!atomicForallArgumentP(forallprop, KWD_RULES_HEAD)) ||
            ((BooleanWrapper*)(dynamicSlotValue(forallprop->dynamicSlots, SYM_RULES_LOGIC_FORWARD_ONLYp, FALSE_WRAPPER)))->wrapperValue))) {
        { Proposition* goal = NULL;
          Cons* iter001 = findMatchableGoals(forallprop, KWD_RULES_TAIL)->theConsList;

          while (!(iter001 == NIL)) {
            goal = ((Proposition*)(iter001->value));
            iter001 = iter001->rest;
            if ((!((boolean)(goaldescription))) ||
                (goaldescription == extractGoalDescription(goal, KWD_RULES_TAIL))) {
              createdsatellitesP = TRUE;
              if (lazysatellitesP) {
                if (!((boolean)(goaldescription))) {
                  goaldesc = extractGoalDescription(goal, KWD_RULES_TAIL);
                }
                else {
                  goaldesc = goaldescription;
                }
                if (!((boolean)(((SequenceIndex*)(dynamicSlotValue(goaldesc->dynamicSlots, SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES, NULL)))))) {
                  setDynamicSlotValue(goaldesc->dynamicSlots, SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES, createSequenceIndex(KWD_RULES_NON_PAGING, NIL), NULL);
                }
                ((SequenceIndex*)(dynamicSlotValue(goaldesc->dynamicSlots, SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES, NULL)))->insert(forallprop);
              }
              else if (!contrapositiveonlyP) {
                deriveOneSatelliteRule(forallprop, goal, KWD_RULES_TAIL, FALSE);
              }
              if ((!positiveonlyP) &&
                  ((!((BooleanWrapper*)(dynamicSlotValue(forallprop->dynamicSlots, SYM_RULES_LOGIC_FORWARD_ONLYp, FALSE_WRAPPER)))->wrapperValue) &&
                   (!atomicForallArgumentP(forallprop, KWD_RULES_HEAD)))) {
                if (lazysatellitesP) {
                  setDynamicSlotValue(goaldesc->dynamicSlots, SYM_RULES_LOGIC_DEFERRED_CONTRAPOSITIVESp, TRUE_WRAPPER, NULL);
                }
                else {
                  deriveOneSatelliteRule(forallprop, goal, KWD_RULES_TAIL, TRUE);
                }
              }
            }
          }
        }
      }
      if (createdsatellitesP &&
          ((boolean)(((TruthValue*)(accessInContext(forallprop->truthValue, forallprop->homeContext, FALSE)))))) {
        { 
          BIND_STELLA_SPECIAL(oCONTEXTo, Context*, forallprop->homeContext);
          BIND_STELLA_SPECIAL(oMODULEo, Module*, oCONTEXTo.get()->baseModule);
          { 
            BIND_STELLA_SPECIAL(oINVISIBLEASSERTIONpo, boolean, TRUE);
            { Proposition* satellite = NULL;
              Cons* iter002 = forallprop->satellitePropositions_reader()->theConsList;

              while (!(iter002 == NIL)) {
                satellite = ((Proposition*)(iter002->value));
                iter002 = iter002->rest;
                assignTruthValue(satellite, ((TruthValue*)(accessInContext(forallprop->truthValue, forallprop->homeContext, FALSE))));
              }
            }
          }
        }
      }
      return (createdsatellitesP);
    }
  }
}

void deriveSatelliteRules(Proposition* forallprop) {
  equateAndSimplifyForallArgument(((Proposition*)((forallprop->arguments->theArray)[0])));
  equateAndSimplifyForallArgument(((Proposition*)((forallprop->arguments->theArray)[1])));
  collapseValueOfChainsForIoVariables(((Vector*)(dynamicSlotValue(forallprop->dynamicSlots, SYM_RULES_LOGIC_IO_VARIABLES, NULL))));
  if (!deriveSatelliteRulesForGoalP(forallprop, NULL, (naturalDeductionModeP() ? KWD_RULES_POSITIVE : KWD_RULES_POSITIVE_AND_CONTRAPOSITIVE), oLAZY_SATELLITE_RULESpo)) {
    if (oCYC_KLUDGES_ENABLEDpo) {
      if (isaP((forallprop->arguments->theArray)[1], SGT_RULES_LOGIC_PROPOSITION) &&
          (((Proposition*)((forallprop->arguments->theArray)[1]))->kind == KWD_RULES_EXISTS)) {
        return;
      }
    }
    *(STANDARD_WARNING->nativeStream) << "Warning: " << "PowerLoom can't index the rule:" << std::endl << "   " << "`" << forallprop << "'" << std::endl << std::endl;
  }
}

DEFINE_STELLA_SPECIAL(oDERIVE_DEFERRED_SATELLITE_RULES_INVOCATIONSo, List* , NULL);

void deriveDeferredSatelliteRules(Description* self) {
  if (oLAZY_SATELLITE_RULESpo) {
    { 
      BIND_STELLA_SPECIAL(oDERIVE_DEFERRED_SATELLITE_RULES_INVOCATIONSo, List*, ((List*)(((!((boolean)(oDERIVE_DEFERRED_SATELLITE_RULES_INVOCATIONSo.get()))) ? newList() : oDERIVE_DEFERRED_SATELLITE_RULES_INVOCATIONSo.get()))));
      if (oDERIVE_DEFERRED_SATELLITE_RULES_INVOCATIONSo.get()->membP(self)) {
        return;
      }
      oDERIVE_DEFERRED_SATELLITE_RULES_INVOCATIONSo.get()->insert(self);
      if ((!((boolean)(((SequenceIndex*)(dynamicSlotValue(self->dynamicSlots, SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES, NULL)))))) &&
          (!((boolean)(((Description*)(dynamicSlotValue(self->dynamicSlots, SYM_RULES_LOGIC_COMPLEMENT_DESCRIPTION, NULL))))))) {
        return;
      }
      { SequenceIndex* queuedrules = ((SequenceIndex*)(dynamicSlotValue(self->dynamicSlots, SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES, NULL)));
        Description* complement = ((Description*)(dynamicSlotValue(self->dynamicSlots, SYM_RULES_LOGIC_COMPLEMENT_DESCRIPTION, NULL)));

        if (((boolean)(queuedrules))) {
          { Proposition* forallprop = NULL;
            Iterator* iter000 = queuedrules->allocateIterator();

            while (iter000->nextP()) {
              forallprop = ((Proposition*)(iter000->value));
              deriveSatelliteRulesForGoalP(forallprop, self, ((!((boolean)(complement))) ? KWD_RULES_POSITIVE : KWD_RULES_POSITIVE_AND_CONTRAPOSITIVE), FALSE);
            }
          }
          if (((boolean)(complement))) {
            setDynamicSlotValue(self->dynamicSlots, SYM_RULES_LOGIC_DEFERRED_CONTRAPOSITIVESp, NULL, NULL);
          }
          setDynamicSlotValue(self->dynamicSlots, SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES, NULL, NULL);
        }
        if (((boolean)(complement)) &&
            ((boolean)(((SequenceIndex*)(dynamicSlotValue(complement->dynamicSlots, SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES, NULL)))))) {
          deriveDeferredSatelliteRules(complement);
        }
      }
    }
  }
}

void deriveDeferredContrapositiveSatelliteRules(Description* self) {
  if (oLAZY_SATELLITE_RULESpo) {
    if (coerceWrappedBooleanToBoolean(self->deferredContrapositivesP_reader())) {
      { Proposition* masterproposition = NULL;
        List* queuedrules = newList();

        { Proposition* prop = NULL;
          Iterator* iter000 = unfilteredDependentImpliesPropositions(self)->allocateIterator();

          while (iter000->nextP()) {
            prop = ((Proposition*)(iter000->value));
            if (prop->kind == KWD_RULES_IMPLIES) {
              masterproposition = ((Proposition*)(dynamicSlotValue(prop->dynamicSlots, SYM_RULES_LOGIC_MASTER_PROPOSITION, NULL)));
              if (((boolean)(masterproposition)) &&
                  (!masterproposition->deletedP())) {
                queuedrules->insertNew(masterproposition);
              }
            }
          }
        }
        { Proposition* forallprop = NULL;
          Cons* iter001 = queuedrules->theConsList;

          while (!(iter001 == NIL)) {
            forallprop = ((Proposition*)(iter001->value));
            iter001 = iter001->rest;
            deriveSatelliteRulesForGoalP(forallprop, self, KWD_RULES_CONTRAPOSITIVE, FALSE);
          }
        }
      }
    }
  }
}

Description* getInferableComplementDescription(Description* self) {
  { Description* complement = ((Description*)(dynamicSlotValue(self->dynamicSlots, SYM_RULES_LOGIC_COMPLEMENT_DESCRIPTION, NULL)));

    if (oLAZY_SATELLITE_RULESpo) {
      if ((!((boolean)(complement))) &&
          coerceWrappedBooleanToBoolean(self->deferredContrapositivesP_reader())) {
        complement = getComplementOfGoalDescription(((NamedDescription*)(self)));
      }
      if (coerceWrappedBooleanToBoolean(self->deferredContrapositivesP_reader())) {
        deriveDeferredSatelliteRules(self);
        setDynamicSlotValue(self->dynamicSlots, SYM_RULES_LOGIC_DEFERRED_CONTRAPOSITIVESp, NULL, NULL);
      }
    }
    return (complement);
  }
}

Proposition* deriveImpliesFromForall(Proposition* forallprop) {
  { List* heads = findMatchableGoals(forallprop, KWD_RULES_HEAD);
    List* tails = findMatchableGoals(forallprop, KWD_RULES_TAIL);
    Proposition* headgoal = ((Proposition*)(heads->first()));
    Proposition* tailgoal = ((Proposition*)(tails->first()));
    Proposition* headproposition = ((Proposition*)((forallprop->arguments->theArray)[1]));
    Proposition* tailproposition = ((Proposition*)((forallprop->arguments->theArray)[0]));

    { boolean testValue000 = FALSE;

      testValue000 = heads->length() == 1;
      if (testValue000) {
        testValue000 = tails->length() == 1;
        if (testValue000) {
          { boolean alwaysP000 = TRUE;

            { Object* hv = NULL;
              Object* tv = NULL;
              Vector* vector000 = headgoal->arguments;
              int index000 = 0;
              int length000 = vector000->length();
              Vector* vector001 = tailgoal->arguments;
              int index001 = 0;
              int length001 = vector001->length();

              while ((index000 < length000) &&
                  (index001 < length001)) {
                hv = (vector000->theArray)[index000];
                index000 = index000 + 1;
                tv = (vector001->theArray)[index001];
                index001 = index001 + 1;
                if (!(eqlP(hv, tv) &&
                    isaP(hv, SGT_RULES_LOGIC_PATTERN_VARIABLE))) {
                  alwaysP000 = FALSE;
                  break;
                }
              }
            }
            testValue000 = alwaysP000;
          }
          if (testValue000) {
            testValue000 = headgoal->arguments->length() == tailgoal->arguments->length();
            if (testValue000) {
              testValue000 = ((Proposition*)(heads->first())) == headproposition;
              if (testValue000) {
                if (((Proposition*)(tails->first())) == tailproposition) {
                  testValue000 = TRUE;
                }
                else {
                  {
                    testValue000 = tailproposition->kind == KWD_RULES_AND;
                    if (testValue000) {
                      { boolean alwaysP001 = TRUE;

                        { Object* arg = NULL;
                          Vector* vector002 = tailproposition->arguments;
                          int index002 = 0;
                          int length002 = vector002->length();

                          while (index002 < length002) {
                            arg = (vector002->theArray)[index002];
                            index002 = index002 + 1;
                            if (!(arg == tailgoal)) {
                              alwaysP001 = FALSE;
                              break;
                            }
                          }
                        }
                        testValue000 = alwaysP001;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      if (testValue000) {
        return (createImpliesProposition(extractGoalDescription(tailgoal, NULL), extractGoalDescription(headgoal, NULL)));
      }
      else {
        return (NULL);
      }
    }
  }
}

Cons* deconstructForallTree(Cons* foralltree, Object*& _Return1, Cons*& _Return2) {
  { Cons* antecedent = ((Cons*)(foralltree->rest->rest->value));
    Object* ifclause = antecedent->rest->value;

    if (ifclause == SYM_RULES_STELLA_TRUE) {
      ifclause = getQuotedTree("((AND) \"/LOGIC\")", "/LOGIC");
    }
    _Return1 = ifclause;
    _Return2 = ((Cons*)(antecedent->rest->rest->value));
    return (((Cons*)(foralltree->rest->value)));
  }
}

Cons* removeExistsVariable(Cons* existsproposition, Symbol* variable) {
  if (!(existsproposition->value == SYM_RULES_STELLA_EXISTS)) {
    *(STANDARD_WARNING->nativeStream) << "Warning: " << "Weird FORALL body: " << "`" << existsproposition << "'" << std::endl;
    return (existsproposition);
  }
  { Cons* existsvariables = ((Cons*)(existsproposition->rest->value));
    Object* existsbody = existsproposition->rest->rest->value;

    existsproposition->secondSetter(existsvariables->remove(variable));
    if (existsproposition->rest->value == NIL) {
      return (((Cons*)(existsbody)));
    }
    else {
      return (existsproposition);
    }
  }
}

ForwardChainingIndex* createForwardChainingIndex(Proposition* goal, Proposition* masterforall) {
  { ForwardChainingIndex* index = newForwardChainingIndex();
    KeyValueList* mapping = newKeyValueList();
    Proposition* forallcopy = copyProposition(masterforall, mapping);
    Object* goalcopy = mapping->lookup(goal);

    forallcopy = substituteProposition(forallcopy, ((Proposition*)(goalcopy)), TRUE_PROPOSITION);
    { Cons* iovariablenames = NULL;
      Cons* querybody = NULL;
      Cons* consequenttree = NULL;
      Cons* reversegoalvblnames = NIL;
      Cons* inputbindings = NIL;

      { Cons* value000 = NULL;
        Object* value001 = NULL;
        Cons* value002 = NULL;

        value000 = deconstructForallTree(((Cons*)(generateProposition(forallcopy))), value001, value002);
        {
          iovariablenames = value000;
          querybody = ((Cons*)(value001));
          consequenttree = value002;
        }
      }
      { Object* v = NULL;
        Cons* iter000 = iovariablenames;

        while (!(iter000 == NIL)) {
          v = iter000->value;
          iter000 = iter000->rest;
          if (!searchConsTreeP(consequenttree, v)) {
            iovariablenames = iovariablenames->remove(v);
            querybody = listO(4, SYM_RULES_STELLA_EXISTS, cons(v, NIL), querybody, NIL);
          }
        }
      }
      index->consequent = ((Description*)(valueOf(conceiveTerm(listO(3, SYM_RULES_LOGIC_KAPPA, ((Cons*)(copyConsTree(iovariablenames))), cons(consequenttree, NIL))))));
      { Object* arg = NULL;
        Vector* vector000 = goal->arguments;
        int index000 = 0;
        int length000 = vector000->length();

        while (index000 < length000) {
          arg = (vector000->theArray)[index000];
          index000 = index000 + 1;
          if (variableP(arg)) {
            reversegoalvblnames = cons(((PatternVariable*)(arg))->skolemName, reversegoalvblnames);
          }
        }
      }
      { Object* v = NULL;
        Cons* iter001 = reversegoalvblnames;

        while (!(iter001 == NIL)) {
          v = iter001->value;
          iter001 = iter001->rest;
          if (!iovariablenames->memberP(v)) {
            querybody = removeExistsVariable(querybody, ((Symbol*)(v)));
          }
        }
      }
      { Object* v = NULL;
        Cons* iter002 = reversegoalvblnames;

        while (!(iter002 == NIL)) {
          v = iter002->value;
          iter002 = iter002->rest;
          iovariablenames = cons(v, iovariablenames);
        }
      }
      index->ioVariables = iovariablenames;
      index->queryBody = querybody;
      { Object* v = NULL;
        Cons* iter003 = iovariablenames;

        while (!(iter003 == NIL)) {
          v = iter003->value;
          iter003 = iter003->rest;
          v = v;
          inputbindings = cons(NULL, inputbindings);
        }
      }
      index->inputBindings = inputbindings;
    }
    index->forwardGoal = goal;
    index->masterRule = masterforall;
    index->cacheId = gensym("FWD-QUERY");
    return (index);
  }
}

void deriveComplexForwardRule(Proposition* goal, Proposition* masterforall) {
  { Description* goaldescription = ((goal->kind == KWD_RULES_NOT) ? getComplementOfGoalDescription(surrogateToDescription(((Surrogate*)(((Proposition*)((goal->arguments->theArray)[0]))->operatoR)))) : surrogateToDescription(((Surrogate*)(goal->operatoR))));
    ForwardChainingIndex* duplicate = NULL;

    { ForwardChainingIndex* idx = NULL;
      Cons* iter000 = goaldescription->forwardChainingIndices_reader()->theConsList;

      while (!(iter000 == NIL)) {
        idx = ((ForwardChainingIndex*)(iter000->value));
        iter000 = iter000->rest;
        if (goal == idx->forwardGoal) {
          duplicate = idx;
        }
      }
    }
    if (((boolean)(duplicate))) {
      goaldescription->forwardChainingIndices_reader()->remove(duplicate);
    }
    if (goaldescription->forwardChainingIndices_reader() == NIL_LIST) {
      setDynamicSlotValue(goaldescription->dynamicSlots, SYM_RULES_LOGIC_FORWARD_CHAINING_INDICES, list(0), NULL);
    }
    goaldescription->forwardChainingIndices_reader()->insert(createForwardChainingIndex(goal, masterforall));
  }
}

Cons* helpGetForwardChainingRules(Description* description) {
  { Cons* rules = NIL;

    { ForwardChainingIndex* idx = NULL;
      Cons* iter000 = description->forwardChainingIndices_reader()->theConsList;
      Cons* collect000 = NULL;

      while (!(iter000 == NIL)) {
        idx = ((ForwardChainingIndex*)(iter000->value));
        iter000 = iter000->rest;
        if (!idx->masterRule->deletedP()) {
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(idx->masterRule, NIL);
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
              collect000->rest = cons(idx->masterRule, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    return (rules);
  }
}

Cons* callGetRules(Object* relationref) {
  { LogicObject* description = getDescription(relationref);
    Cons* rules = NIL;

    if (!((boolean)(description))) {
      std::cout << "Can't find a relation named " << relationref << std::endl;
      return (NULL);
    }
    if (subtypeOfP(safePrimaryType(description), SGT_RULES_LOGIC_NAMED_DESCRIPTION)) {
      { LogicObject* description000 = description;
        NamedDescription* description = ((NamedDescription*)(description000));

        rules = applicableRulesOfDescription(description, KWD_RULES_FORWARD, FALSE)->concatenate(applicableRulesOfDescription(description, KWD_RULES_BACKWARD, FALSE), 1, helpGetForwardChainingRules(description));
        { Description* complement = ((Description*)(dynamicSlotValue(description->dynamicSlots, SYM_RULES_LOGIC_COMPLEMENT_DESCRIPTION, NULL)));

          if (((boolean)(complement))) {
            rules = rules->concatenate(applicableRulesOfDescription(complement, KWD_RULES_FORWARD, FALSE), 2, applicableRulesOfDescription(complement, KWD_RULES_BACKWARD, FALSE), helpGetForwardChainingRules(complement));
          }
        }
      }
    }
    else {
    }
    return (rules);
  }
}

Cons* getRules(Object* relation) {
  // Return the list of rules associated with `relation'.
  return (callGetRules(relation));
}

void deleteRules(Object* relation) {
  // Delete the list of rules associated with `relation'.
  // This function is included mainly for debugging purposes, when
  // a user wants to verify the behavior of different sets of rules.
  { Proposition* r = NULL;
    Cons* iter000 = callGetRules(relation);

    while (!(iter000 == NIL)) {
      r = ((Proposition*)(iter000->value));
      iter000 = iter000->rest;
      destroyProposition(r);
    }
  }
}

void printRules(Object* relation) {
  // Print the list of rules associated with `relation'.
  { Proposition* rule = NULL;
    Cons* iter000 = callGetRules(relation);

    while (!(iter000 == NIL)) {
      rule = ((Proposition*)(iter000->value));
      iter000 = iter000->rest;
      printLogicalForm(rule, STANDARD_OUTPUT);
      std::cout << std::endl << std::endl;
    }
  }
}

void printSatellites(Proposition* forallprop) {
  { Proposition* rule = NULL;
    Cons* iter000 = forallprop->satellitePropositions_reader()->theConsList;

    while (!(iter000 == NIL)) {
      rule = ((Proposition*)(iter000->value));
      iter000 = iter000->rest;
      std::cout << rule << std::endl;
    }
  }
}

Proposition* getRule(Object* rulename) {
  { Object* object = getInstance(rulename);

    if ((!((boolean)(object))) ||
        (!isaP(object, SGT_RULES_LOGIC_PROPOSITION))) {
      std::cout << "Can't find a rule named " << "`" << rulename << "'" << std::endl << std::endl;
      return (NULL);
    }
    return (((Proposition*)(object)));
  }
}

Proposition* findRule(Object* rulename) {
  // Search for a rule named 'ruleName'.  Like 'get-rule',
  // but 'find-rule' implicity quotes its input argument.
  return (getRule(rulename));
}

Proposition* assertRule(Object* rulename) {
  // Set the truth value of the rule named 'ruleName' to 
  // TRUE.  The proposition having the name 'ruleName' may be
  // any arbitrary proposition, although we expect that it is probably
  // a material implication.  (See `retract-rule').
  { Proposition* proposition = getRule(rulename);

    if (!((boolean)(proposition))) {
      return (NULL);
    }
    updatePropositionTruthValue(proposition, KWD_RULES_ASSERT_TRUE);
    return (proposition);
  }
}

Proposition* retractRule(Object* rulename) {
  // If it is currently TRUE, set the truth value 
  // of the rule named 'ruleName' to UNKNOWN  This
  // command may be used alternately with `assert-rule' to
  // observe the effects of querying with or without a particular (named) rule
  // being asserted within the current context. The proposition having the name
  // 'ruleName' may be any arbitrary proposition, although we expect that it is
  // probably a material implication.
  { Proposition* proposition = getRule(rulename);

    if (!((boolean)(proposition))) {
      return (NULL);
    }
    updatePropositionTruthValue(proposition, KWD_RULES_RETRACT_TRUE);
    return (proposition);
  }
}

void deleteRuleCachesOnRelation(Relation* relation) {
  { Proposition* rule = NULL;
    Cons* iter000 = callGetRules(relation);

    while (!(iter000 == NIL)) {
      rule = ((Proposition*)(iter000->value));
      iter000 = iter000->rest;
      { Object* arg = NULL;
        Vector* vector000 = rule->arguments;
        int index000 = 0;
        int length000 = vector000->length();

        while (index000 < length000) {
          arg = (vector000->theArray)[index000];
          index000 = index000 + 1;
          if (((boolean)(((Description*)(arg))->queryPatterns))) {
            { KvListIterator* it = ((KvListIterator*)(((Description*)(arg))->queryPatterns->allocateIterator()));

              while (it->nextP()) {
                it->valueSetter(NULL);
              }
            }
          }
        }
      }
    }
  }
}

void resetQueryCaches() {
  // Zero out all caches managed by the query optimizer,
  // so that it will reoptimize subgoal queries upon next invocation.
  { Slot* slot = NULL;
    Iterator* iter000 = allSlots(NULL, TRUE);

    while (iter000->nextP()) {
      slot = ((Slot*)(iter000->value));
      if (((boolean)(((NamedDescription*)(dynamicSlotValue(slot->dynamicSlots, SYM_RULES_LOGIC_DESCRIPTION, NULL)))))) {
        deleteRuleCachesOnRelation(slot);
      }
    }
  }
  { NamedDescription* description = NULL;
    Iterator* iter001 = allNamedDescriptions(NULL, TRUE);

    while (iter001->nextP()) {
      description = ((NamedDescription*)(iter001->value));
      if (((boolean)(description->queryPatterns))) {
        { KvListIterator* it = ((KvListIterator*)(description->queryPatterns->allocateIterator()));

          while (it->nextP()) {
            it->valueSetter(NULL);
          }
        }
      }
    }
  }
}

void helpStartupRules1() {
  {
    KWD_RULES_HEAD = ((Keyword*)(internRigidSymbolWrtModule("HEAD", NULL, 2)));
    SYM_RULES_LOGIC_IO_VARIABLES = ((Symbol*)(internRigidSymbolWrtModule("IO-VARIABLES", NULL, 0)));
    KWD_RULES_TAIL = ((Keyword*)(internRigidSymbolWrtModule("TAIL", NULL, 2)));
    KWD_RULES_AND = ((Keyword*)(internRigidSymbolWrtModule("AND", NULL, 2)));
    KWD_RULES_EXISTS = ((Keyword*)(internRigidSymbolWrtModule("EXISTS", NULL, 2)));
    KWD_RULES_OR = ((Keyword*)(internRigidSymbolWrtModule("OR", NULL, 2)));
    KWD_RULES_FORALL = ((Keyword*)(internRigidSymbolWrtModule("FORALL", NULL, 2)));
    KWD_RULES_ISA = ((Keyword*)(internRigidSymbolWrtModule("ISA", NULL, 2)));
    KWD_RULES_PREDICATE = ((Keyword*)(internRigidSymbolWrtModule("PREDICATE", NULL, 2)));
    KWD_RULES_FUNCTION = ((Keyword*)(internRigidSymbolWrtModule("FUNCTION", NULL, 2)));
    KWD_RULES_NOT = ((Keyword*)(internRigidSymbolWrtModule("NOT", NULL, 2)));
    KWD_RULES_IMPLIES = ((Keyword*)(internRigidSymbolWrtModule("IMPLIES", NULL, 2)));
    SGT_RULES_PL_KERNEL_KB_HOLDS = ((Surrogate*)(internRigidSymbolWrtModule("HOLDS", getStellaModule("/PL-KERNEL-KB", TRUE), 1)));
    SGT_RULES_LOGIC_PATTERN_VARIABLE = ((Surrogate*)(internRigidSymbolWrtModule("PATTERN-VARIABLE", NULL, 1)));
    SYM_RULES_LOGIC_COMPLEMENT_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("COMPLEMENT-DESCRIPTION", NULL, 0)));
    SGT_RULES_STELLA_SURROGATE = ((Surrogate*)(internRigidSymbolWrtModule("SURROGATE", getStellaModule("/STELLA", TRUE), 1)));
    KWD_RULES_ERROR = ((Keyword*)(internRigidSymbolWrtModule("ERROR", NULL, 2)));
    SGT_RULES_LOGIC_PROPOSITION = ((Surrogate*)(internRigidSymbolWrtModule("PROPOSITION", NULL, 1)));
    SGT_RULES_STELLA_FALSE = ((Surrogate*)(internRigidSymbolWrtModule("FALSE", getStellaModule("/STELLA", TRUE), 1)));
    SGT_RULES_STELLA_TRUE = ((Surrogate*)(internRigidSymbolWrtModule("TRUE", getStellaModule("/STELLA", TRUE), 1)));
    SYM_RULES_STELLA_FORALL = ((Symbol*)(internRigidSymbolWrtModule("FORALL", getStellaModule("/STELLA", TRUE), 0)));
    KWD_RULES_DESCRIPTION = ((Keyword*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 2)));
    SYM_RULES_LOGIC_FORWARD_ONLYp = ((Symbol*)(internRigidSymbolWrtModule("FORWARD-ONLY?", NULL, 0)));
    KWD_RULES_EXTENSIONAL_ASSERTION = ((Keyword*)(internRigidSymbolWrtModule("EXTENSIONAL-ASSERTION", NULL, 2)));
    SYM_RULES_LOGIC_SATELLITE_PROPOSITIONS = ((Symbol*)(internRigidSymbolWrtModule("SATELLITE-PROPOSITIONS", NULL, 0)));
    SYM_RULES_LOGIC_MASTER_PROPOSITION = ((Symbol*)(internRigidSymbolWrtModule("MASTER-PROPOSITION", NULL, 0)));
    SYM_RULES_LOGIC_BACKWARD_ONLYp = ((Symbol*)(internRigidSymbolWrtModule("BACKWARD-ONLY?", NULL, 0)));
    SYM_RULES_LOGIC_DONT_OPTIMIZEp = ((Symbol*)(internRigidSymbolWrtModule("DONT-OPTIMIZE?", NULL, 0)));
    KWD_RULES_POSITIVE = ((Keyword*)(internRigidSymbolWrtModule("POSITIVE", NULL, 2)));
    KWD_RULES_CONTRAPOSITIVE = ((Keyword*)(internRigidSymbolWrtModule("CONTRAPOSITIVE", NULL, 2)));
    SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES = ((Symbol*)(internRigidSymbolWrtModule("RULES-WITH-DEFERRED-SATELLITES", NULL, 0)));
    KWD_RULES_NON_PAGING = ((Keyword*)(internRigidSymbolWrtModule("NON-PAGING", NULL, 2)));
    SYM_RULES_LOGIC_DEFERRED_CONTRAPOSITIVESp = ((Symbol*)(internRigidSymbolWrtModule("DEFERRED-CONTRAPOSITIVES?", NULL, 0)));
    KWD_RULES_POSITIVE_AND_CONTRAPOSITIVE = ((Keyword*)(internRigidSymbolWrtModule("POSITIVE-AND-CONTRAPOSITIVE", NULL, 2)));
    SYM_RULES_STELLA_TRUE = ((Symbol*)(internRigidSymbolWrtModule("TRUE", getStellaModule("/STELLA", TRUE), 0)));
    SYM_RULES_STELLA_EXISTS = ((Symbol*)(internRigidSymbolWrtModule("EXISTS", getStellaModule("/STELLA", TRUE), 0)));
    SYM_RULES_LOGIC_KAPPA = ((Symbol*)(internRigidSymbolWrtModule("KAPPA", NULL, 0)));
    SYM_RULES_LOGIC_FORWARD_CHAINING_INDICES = ((Symbol*)(internRigidSymbolWrtModule("FORWARD-CHAINING-INDICES", NULL, 0)));
    SGT_RULES_LOGIC_NAMED_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("NAMED-DESCRIPTION", NULL, 1)));
    KWD_RULES_FORWARD = ((Keyword*)(internRigidSymbolWrtModule("FORWARD", NULL, 2)));
    KWD_RULES_BACKWARD = ((Keyword*)(internRigidSymbolWrtModule("BACKWARD", NULL, 2)));
    KWD_RULES_ASSERT_TRUE = ((Keyword*)(internRigidSymbolWrtModule("ASSERT-TRUE", NULL, 2)));
    KWD_RULES_RETRACT_TRUE = ((Keyword*)(internRigidSymbolWrtModule("RETRACT-TRUE", NULL, 2)));
    SYM_RULES_LOGIC_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 0)));
    SYM_RULES_LOGIC_STARTUP_RULES = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-RULES", NULL, 0)));
    SYM_RULES_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", TRUE), 0)));
  }
}

void startupRules() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupRules1();
    }
    if (currentStartupTimePhaseP(4)) {
      oLAZY_SATELLITE_RULESpo = TRUE;
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("FIND-MATCHABLE-GOALS", "(DEFUN (FIND-MATCHABLE-GOALS (LIST OF PROPOSITION)) ((FORALLPROP PROPOSITION) (HEADORTAIL KEYWORD)))", ((cpp_function_code)(&findMatchableGoals)), NULL);
      defineFunctionObject("COLLECT-MATCHING-RULE-GOALS", "(DEFUN COLLECT-MATCHING-RULE-GOALS ((PROPOSITION PROPOSITION) (TOPLEVELVARS CONS) (HEADORTAIL KEYWORD) (COLLECTION (LIST OF PROPOSITION))))", ((cpp_function_code)(&collectMatchingRuleGoals)), NULL);
      defineFunctionObject("ATOMIC-FORALL-ARGUMENT?", "(DEFUN (ATOMIC-FORALL-ARGUMENT? BOOLEAN) ((FORALLPROP PROPOSITION) (HEADORTAIL KEYWORD)))", ((cpp_function_code)(&atomicForallArgumentP)), NULL);
      defineFunctionObject("ATOMIC-GOAL-PROPOSITION?", "(DEFUN (ATOMIC-GOAL-PROPOSITION? BOOLEAN) ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&atomicGoalPropositionP)), NULL);
      defineFunctionObject("ATOMIC-GOAL-DESCRIPTION?", "(DEFUN (ATOMIC-GOAL-DESCRIPTION? BOOLEAN) ((DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&atomicGoalDescriptionP)), NULL);
      defineFunctionObject("VARIABLE-ARITY-GOAL-PROPOSITION?", "(DEFUN (VARIABLE-ARITY-GOAL-PROPOSITION? BOOLEAN) ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&variableArityGoalPropositionP)), NULL);
      defineFunctionObject("CHAINABLE-RELATION?", "(DEFUN (CHAINABLE-RELATION? BOOLEAN) ((DESCRIPTION NAMED-DESCRIPTION) (HEADORTAIL KEYWORD)))", ((cpp_function_code)(&chainableRelationP)), NULL);
      defineFunctionObject("EXTRACT-GOAL-DESCRIPTION", "(DEFUN (EXTRACT-GOAL-DESCRIPTION DESCRIPTION) ((GOAL PROPOSITION) (HEADORTAIL KEYWORD)))", ((cpp_function_code)(&extractGoalDescription)), NULL);
      defineFunctionObject("EXTRACT-GOAL-ARGUMENTS", "(DEFUN (EXTRACT-GOAL-ARGUMENTS CONS) ((GOAL PROPOSITION)))", ((cpp_function_code)(&extractGoalArguments)), NULL);
      defineFunctionObject("SUBSTITUTE-PROPOSITION", "(DEFUN (SUBSTITUTE-PROPOSITION PROPOSITION) ((PROPOSITION PROPOSITION) (OUTPROP PROPOSITION) (INPROP PROPOSITION)))", ((cpp_function_code)(&substituteProposition)), NULL);
      defineFunctionObject("EXTRACT-INVERTED-GOAL", "(DEFUN (EXTRACT-INVERTED-GOAL PROPOSITION) ((PROPOSITION PROPOSITION) (GOAL PROPOSITION)))", ((cpp_function_code)(&extractInvertedGoal)), NULL);
      defineFunctionObject("INVERT-FORALL-AROUND-GOAL", "(DEFUN (INVERT-FORALL-AROUND-GOAL PROPOSITION) ((FORALLPROP PROPOSITION) (GOAL PROPOSITION) (HEADORTAIL KEYWORD) (CONTRAPOSITIVE? BOOLEAN)))", ((cpp_function_code)(&invertForallAroundGoal)), NULL);
      defineFunctionObject("CONSTRUCT-DESCRIPTION-FROM-FORALL-PROPOSITION", "(DEFUN (CONSTRUCT-DESCRIPTION-FROM-FORALL-PROPOSITION OBJECT) ((FORALLPROP PROPOSITION) (HEADORTAIL KEYWORD)))", ((cpp_function_code)(&constructDescriptionFromForallProposition)), NULL);
      defineFunctionObject("MARK-AS-FORWARD-RULE", "(DEFUN MARK-AS-FORWARD-RULE ((IMPLIESPROP PROPOSITION)))", ((cpp_function_code)(&markAsForwardRule)), NULL);
      defineFunctionObject("DERIVE-ONE-SATELLITE-RULE", "(DEFUN DERIVE-ONE-SATELLITE-RULE ((MASTERFORALL PROPOSITION) (GOAL PROPOSITION) (HEADORTAIL KEYWORD) (CONTRAPOSITIVE? BOOLEAN)))", ((cpp_function_code)(&deriveOneSatelliteRule)), NULL);
      defineFunctionObject("EQUATE-AND-SIMPLIFY-FORALL-ARGUMENT", "(DEFUN EQUATE-AND-SIMPLIFY-FORALL-ARGUMENT ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&equateAndSimplifyForallArgument)), NULL);
      defineFunctionObject("DERIVE-SATELLITE-RULES-FOR-GOAL?", "(DEFUN (DERIVE-SATELLITE-RULES-FOR-GOAL? BOOLEAN) ((FORALLPROP PROPOSITION) (GOALDESCRIPTION DESCRIPTION) (DIRECTION KEYWORD) (LAZYSATELLITES? BOOLEAN)))", ((cpp_function_code)(&deriveSatelliteRulesForGoalP)), NULL);
      defineFunctionObject("DERIVE-SATELLITE-RULES", "(DEFUN DERIVE-SATELLITE-RULES ((FORALLPROP PROPOSITION)))", ((cpp_function_code)(&deriveSatelliteRules)), NULL);
      defineFunctionObject("DERIVE-DEFERRED-SATELLITE-RULES", "(DEFUN DERIVE-DEFERRED-SATELLITE-RULES ((SELF DESCRIPTION)))", ((cpp_function_code)(&deriveDeferredSatelliteRules)), NULL);
      defineFunctionObject("DERIVE-DEFERRED-CONTRAPOSITIVE-SATELLITE-RULES", "(DEFUN DERIVE-DEFERRED-CONTRAPOSITIVE-SATELLITE-RULES ((SELF DESCRIPTION)))", ((cpp_function_code)(&deriveDeferredContrapositiveSatelliteRules)), NULL);
      defineFunctionObject("GET-INFERABLE-COMPLEMENT-DESCRIPTION", "(DEFUN (GET-INFERABLE-COMPLEMENT-DESCRIPTION DESCRIPTION) ((SELF DESCRIPTION)))", ((cpp_function_code)(&getInferableComplementDescription)), NULL);
      defineFunctionObject("DERIVE-IMPLIES-FROM-FORALL", "(DEFUN (DERIVE-IMPLIES-FROM-FORALL PROPOSITION) ((FORALLPROP PROPOSITION)))", ((cpp_function_code)(&deriveImpliesFromForall)), NULL);
      defineFunctionObject("DECONSTRUCT-FORALL-TREE", "(DEFUN (DECONSTRUCT-FORALL-TREE CONS OBJECT CONS) ((FORALLTREE CONS)))", ((cpp_function_code)(&deconstructForallTree)), NULL);
      defineFunctionObject("REMOVE-EXISTS-VARIABLE", "(DEFUN (REMOVE-EXISTS-VARIABLE CONS) ((EXISTSPROPOSITION CONS) (VARIABLE SYMBOL)))", ((cpp_function_code)(&removeExistsVariable)), NULL);
      defineFunctionObject("CREATE-FORWARD-CHAINING-INDEX", "(DEFUN (CREATE-FORWARD-CHAINING-INDEX FORWARD-CHAINING-INDEX) ((GOAL PROPOSITION) (MASTERFORALL PROPOSITION)))", ((cpp_function_code)(&createForwardChainingIndex)), NULL);
      defineFunctionObject("DERIVE-COMPLEX-FORWARD-RULE", "(DEFUN DERIVE-COMPLEX-FORWARD-RULE ((GOAL PROPOSITION) (MASTERFORALL PROPOSITION)))", ((cpp_function_code)(&deriveComplexForwardRule)), NULL);
      defineFunctionObject("HELP-GET-FORWARD-CHAINING-RULES", "(DEFUN (HELP-GET-FORWARD-CHAINING-RULES (CONS OF PROPOSITION)) ((DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&helpGetForwardChainingRules)), NULL);
      defineFunctionObject("CALL-GET-RULES", "(DEFUN (CALL-GET-RULES (CONS OF PROPOSITION)) ((RELATIONREF OBJECT)))", ((cpp_function_code)(&callGetRules)), NULL);
      defineFunctionObject("GET-RULES", "(DEFUN (GET-RULES (CONS OF PROPOSITION)) ((RELATION NAME)) :DOCUMENTATION \"Return the list of rules associated with `relation'.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)", ((cpp_function_code)(&getRules)), NULL);
      defineFunctionObject("DELETE-RULES", "(DEFUN DELETE-RULES ((RELATION NAME)) :DOCUMENTATION \"Delete the list of rules associated with `relation'.\nThis function is included mainly for debugging purposes, when\na user wants to verify the behavior of different sets of rules.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)", ((cpp_function_code)(&deleteRules)), NULL);
      defineFunctionObject("PRINT-RULES", "(DEFUN PRINT-RULES ((RELATION OBJECT)) :DOCUMENTATION \"Print the list of rules associated with `relation'.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)", ((cpp_function_code)(&printRules)), NULL);
      defineFunctionObject("PRINT-SATELLITES", "(DEFUN PRINT-SATELLITES ((FORALLPROP PROPOSITION)))", ((cpp_function_code)(&printSatellites)), NULL);
      defineFunctionObject("GET-RULE", "(DEFUN (GET-RULE PROPOSITION) ((RULENAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? TRUE)", ((cpp_function_code)(&getRule)), NULL);
      defineFunctionObject("FIND-RULE", "(DEFUN (FIND-RULE PROPOSITION) ((RULENAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Search for a rule named 'ruleName'.  Like 'get-rule',\nbut 'find-rule' implicity quotes its input argument.\")", ((cpp_function_code)(&findRule)), NULL);
      defineFunctionObject("ASSERT-RULE", "(DEFUN (ASSERT-RULE PROPOSITION) ((RULENAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Set the truth value of the rule named 'ruleName' to \nTRUE.  The proposition having the name 'ruleName' may be\nany arbitrary proposition, although we expect that it is probably\na material implication.  (See `retract-rule').\")", ((cpp_function_code)(&assertRule)), NULL);
      defineFunctionObject("RETRACT-RULE", "(DEFUN (RETRACT-RULE PROPOSITION) ((RULENAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"If it is currently TRUE, set the truth value \nof the rule named 'ruleName' to UNKNOWN  This\ncommand may be used alternately with `assert-rule' to\nobserve the effects of querying with or without a particular (named) rule\nbeing asserted within the current context. The proposition having the name\n'ruleName' may be any arbitrary proposition, although we expect that it is\nprobably a material implication.\")", ((cpp_function_code)(&retractRule)), NULL);
      defineFunctionObject("DELETE-RULE-CACHES-ON-RELATION", "(DEFUN DELETE-RULE-CACHES-ON-RELATION ((RELATION RELATION)))", ((cpp_function_code)(&deleteRuleCachesOnRelation)), NULL);
      defineFunctionObject("RESET-QUERY-CACHES", "(DEFUN RESET-QUERY-CACHES () :DOCUMENTATION \"Zero out all caches managed by the query optimizer,\nso that it will reoptimize subgoal queries upon next invocation.\")", ((cpp_function_code)(&resetQueryCaches)), NULL);
      defineFunctionObject("STARTUP-RULES", "(DEFUN STARTUP-RULES () :PUBLIC? TRUE)", ((cpp_function_code)(&startupRules)), NULL);
      { MethodSlot* function = lookupFunction(SYM_RULES_LOGIC_STARTUP_RULES);

        setDynamicSlotValue(function->dynamicSlots, SYM_RULES_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Rules"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LAZY-SATELLITE-RULES?* BOOLEAN TRUE :DOCUMENTATION \"If true, inversion of forall propositions happens lazily.\nI.e., satellite rules are generated on-demand during inference only if they\nare actually needed.\" :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *DERIVE-DEFERRED-SATELLITE-RULES-INVOCATIONS* (LIST OF DESCRIPTION) NULL)");
    }
  }
}

Keyword* KWD_RULES_HEAD = NULL;

Symbol* SYM_RULES_LOGIC_IO_VARIABLES = NULL;

Keyword* KWD_RULES_TAIL = NULL;

Keyword* KWD_RULES_AND = NULL;

Keyword* KWD_RULES_EXISTS = NULL;

Keyword* KWD_RULES_OR = NULL;

Keyword* KWD_RULES_FORALL = NULL;

Keyword* KWD_RULES_ISA = NULL;

Keyword* KWD_RULES_PREDICATE = NULL;

Keyword* KWD_RULES_FUNCTION = NULL;

Keyword* KWD_RULES_NOT = NULL;

Keyword* KWD_RULES_IMPLIES = NULL;

Surrogate* SGT_RULES_PL_KERNEL_KB_HOLDS = NULL;

Surrogate* SGT_RULES_LOGIC_PATTERN_VARIABLE = NULL;

Symbol* SYM_RULES_LOGIC_COMPLEMENT_DESCRIPTION = NULL;

Surrogate* SGT_RULES_STELLA_SURROGATE = NULL;

Keyword* KWD_RULES_ERROR = NULL;

Surrogate* SGT_RULES_LOGIC_PROPOSITION = NULL;

Surrogate* SGT_RULES_STELLA_FALSE = NULL;

Surrogate* SGT_RULES_STELLA_TRUE = NULL;

Symbol* SYM_RULES_STELLA_FORALL = NULL;

Keyword* KWD_RULES_DESCRIPTION = NULL;

Symbol* SYM_RULES_LOGIC_FORWARD_ONLYp = NULL;

Keyword* KWD_RULES_EXTENSIONAL_ASSERTION = NULL;

Symbol* SYM_RULES_LOGIC_SATELLITE_PROPOSITIONS = NULL;

Symbol* SYM_RULES_LOGIC_MASTER_PROPOSITION = NULL;

Symbol* SYM_RULES_LOGIC_BACKWARD_ONLYp = NULL;

Symbol* SYM_RULES_LOGIC_DONT_OPTIMIZEp = NULL;

Keyword* KWD_RULES_POSITIVE = NULL;

Keyword* KWD_RULES_CONTRAPOSITIVE = NULL;

Symbol* SYM_RULES_LOGIC_RULES_WITH_DEFERRED_SATELLITES = NULL;

Keyword* KWD_RULES_NON_PAGING = NULL;

Symbol* SYM_RULES_LOGIC_DEFERRED_CONTRAPOSITIVESp = NULL;

Keyword* KWD_RULES_POSITIVE_AND_CONTRAPOSITIVE = NULL;

Symbol* SYM_RULES_STELLA_TRUE = NULL;

Symbol* SYM_RULES_STELLA_EXISTS = NULL;

Symbol* SYM_RULES_LOGIC_KAPPA = NULL;

Symbol* SYM_RULES_LOGIC_FORWARD_CHAINING_INDICES = NULL;

Surrogate* SGT_RULES_LOGIC_NAMED_DESCRIPTION = NULL;

Keyword* KWD_RULES_FORWARD = NULL;

Keyword* KWD_RULES_BACKWARD = NULL;

Keyword* KWD_RULES_ASSERT_TRUE = NULL;

Keyword* KWD_RULES_RETRACT_TRUE = NULL;

Symbol* SYM_RULES_LOGIC_DESCRIPTION = NULL;

Symbol* SYM_RULES_LOGIC_STARTUP_RULES = NULL;

Symbol* SYM_RULES_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
