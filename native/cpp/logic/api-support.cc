//  -*- Mode: C++ -*-

// api-support.cc

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

boolean classNamesNextP(AllPurposeIterator* self) {
  if (self->firstIterationP) {
    self->firstIterationP = FALSE;
    self->value = ((Class*)(self->iteratorObject))->classType;
    return (TRUE);
  }
  { boolean nextP = self->iteratorNestedIterator->nextP();

    if (nextP) {
      self->value = self->iteratorNestedIterator->value;
    }
    return (nextP);
  }
}

boolean allPropositionsNextP(AllPurposeIterator* self) {
  for (;;) {
    { Iterator* iterator = self->iteratorNestedIterator;
      Module* module = NULL;

      if (iterator->nextP()) {
        self->value = iterator->value;
        return (TRUE);
      }
      module = ((Module*)(((List*)(self->iteratorObject))->pop()));
      if (!((boolean)(module))) {
        self->value = NULL;
        return (FALSE);
      }
      self->iteratorNestedIterator = locallyConceivedPropositions(module)->allocateIterator();
    }
  }
}

Iterator* allPropositions(Module* module, boolean localP) {
  // Iterate over all conceived propositions visible from `module'.
  // Only propositions that haven't been deleted will be considered.
  // If `local?', only return propositions conceived locally in `module'.
  { AllPurposeIterator* self000 = newAllPurposeIterator();

    self000->iteratorObject = (localP ? list(1, module) : visibleModules(module)->listify()->reverse());
    self000->iteratorNestedIterator = locallyConceivedPropositions(module)->allocateIterator();
    self000->iteratorNextCode = ((cpp_function_code)(&allPropositionsNextP));
    { AllPurposeIterator* value000 = self000;

      return (value000);
    }
  }
}

boolean visibleTermP(LogicObject* term, Context* context, boolean localP) {
  return ((localP ? (term->homeContext == context) : visibleFromP(term->homeContext, context)));
}

Iterator* allUnnamedTerms(Module* module, boolean localP) {
  // Iterate over all unnamed terms visible from `module'.  A term can be
  // an instance (or individual) as well as a description.  Only terms that
  // haven't been deleted will be considered.  If `local?', only return
  // terms created locally in `module'.
  { Cons* terms = NIL;
    Cons* termswithduplicates = NIL;
    LogicObject* term = NULL;

    { Proposition* proposition = NULL;
      Iterator* iter000 = allPropositions(module, localP);

      while (iter000->nextP()) {
        proposition = ((Proposition*)(iter000->value));
        { Object* arg = NULL;
          Vector* vector000 = proposition->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          while (index000 < length000) {
            arg = (vector000->theArray)[index000];
            index000 = index000 + 1;
            if (((boolean)(arg)) &&
                (isaP(arg, SGT_API_SUPPORT_LOGIC_LOGIC_OBJECT) &&
                 (!arg->deletedP()))) {
              term = ((LogicObject*)(arg));
              if ((!visibleTermP(term, module, localP)) ||
                  ((boolean)(term->surrogateValueInverse))) {
                continue;
              }
              { Surrogate* testValue000 = safePrimaryType(term);

                if (subtypeOfP(testValue000, SGT_API_SUPPORT_LOGIC_PATTERN_VARIABLE)) {
                  { LogicObject* term000 = term;
                    PatternVariable* term = ((PatternVariable*)(term000));

                  }
                }
                else if (subtypeOfP(testValue000, SGT_API_SUPPORT_LOGIC_SKOLEM)) {
                  { LogicObject* term001 = term;
                    Skolem* term = ((Skolem*)(term001));

                    if (((boolean)(term->definingProposition))) {
                      if (term->definingProposition == proposition) {
                        terms = cons(term, terms);
                      }
                    }
                    else {
                      termswithduplicates = cons(term, termswithduplicates);
                    }
                  }
                }
                else {
                  termswithduplicates = cons(term, termswithduplicates);
                }
              }
            }
          }
        }
      }
    }
    { List* self000 = newList();

      self000->theConsList = termswithduplicates->removeDuplicates();
      { Iterator* value000 = self000->allocateDestructiveListIterator();

        return (value000);
      }
    }
  }
}

boolean allNamedTermsNextP(AllPurposeIterator* self) {
  { int cursor = self->iteratorInteger;
    Cons* modules = self->iteratorConsList;
    Surrogate* surrogate = NULL;
    Object* value = NULL;

    { 
      BIND_STELLA_SPECIAL(oSUPPRESSNONLOGICOBJECTWARNINGpo, boolean, TRUE);
      while (cursor < self->iteratorSecondInteger) {
        surrogate = ((Surrogate*)((oSURROGATE_ARRAYo->theArray)[cursor]));
        if (((boolean)(surrogate)) &&
            (modules->memberP(((Module*)(surrogate->homeContext))) &&
             ((boolean)(surrogate->surrogateValue)))) {
          value = valueOf(surrogate);
          if (((boolean)(value))) {
            { Surrogate* testValue000 = safePrimaryType(value);

              if (subtypeOfP(testValue000, SGT_API_SUPPORT_LOGIC_LOGIC_OBJECT)) {
                { Object* value000 = value;
                  LogicObject* value = ((LogicObject*)(value000));

                  if (value->deletedP() ||
                      (!modules->memberP(value->homeContext))) {
                    value = NULL;
                  }
                }
              }
              else if (subtypeOfP(testValue000, SGT_API_SUPPORT_STELLA_THING)) {
                { Object* value001 = value;
                  Thing* value = ((Thing*)(value001));

                  if (value->deletedP()) {
                    value = NULL;
                  }
                }
              }
              else {
                value = NULL;
              }
            }
          }
          if (((boolean)(value))) {
            self->value = value;
            self->iteratorInteger = cursor + 1;
            return (TRUE);
          }
        }
        cursor = cursor + 1;
      }
      return (FALSE);
    }
  }
}

Iterator* allNamedTerms(Module* module, boolean localP) {
  // Iterate over all named terms visible from `module'.  A term can be an
  // instance (or individual) as well as a description.  Only terms that
  // haven't been deleted will be considered.  If `local?', only return 
  // terms created locally in `module'.
  return (allocateAllMetaObjectsIterator(oSURROGATE_ARRAYo->topSymbolOffset + 1, ((cpp_function_code)(&allNamedTermsNextP)), module, localP));
}

Iterator* allTerms(Module* module, boolean localP) {
  // Return a list of all terms visible from `module'.  A term can be an
  // instance (or individual) as well as a description.  Only terms that
  // haven't been deleted will be considered.  If `local?', only return 
  // terms created locally in `module'.
  if (localP) {
    {
      locallyConceivedInstances(module)->removeDeletedMembers();
      return (locallyConceivedInstances(module)->allocateIterator());
    }
  }
  else {
    return (allNamedTerms(module, FALSE)->concatenate(allUnnamedTerms(module, FALSE), 0));
  }
}

boolean filterInstanceP(LogicObject* self, AllPurposeIterator* iterator) {
  iterator = iterator;
  return (!isaP(self, SGT_API_SUPPORT_LOGIC_DESCRIPTION));
}

Iterator* allNamedInstances(Module* module, boolean localP) {
  // Iterate over all named instances (or individuals) visible from `module'.
  // Only instances that haven't been deleted will be considered.  If `local?',
  // only return instances created locally in `module'.
  { AllPurposeIterator* self000 = newAllPurposeIterator();

    self000->iteratorNestedIterator = allNamedTerms(module, localP);
    self000->iteratorNextCode = ((cpp_function_code)(&filteredNestedIteratorNextP));
    self000->iteratorFilterCode = ((cpp_function_code)(&filterInstanceP));
    { AllPurposeIterator* value000 = self000;

      return (value000);
    }
  }
}

Iterator* allInstances(Module* module, boolean localP) {
  // Iterate over all instances (or individuals) visible from `module'.
  // Only instances that haven't been deleted will be considered.  If `local?',
  // only return instances created locally in `module'.
  { Iterator* iterator = allTerms(module, localP);
    AllPurposeIterator* allpurposeiterator = NULL;

    if (localP) {
      { AllPurposeIterator* self000 = newAllPurposeIterator();

        self000->iteratorNestedIterator = iterator;
        self000->iteratorNextCode = ((cpp_function_code)(&filteredNestedIteratorNextP));
        allpurposeiterator = self000;
      }
    }
    else {
      allpurposeiterator = ((AllPurposeIterator*)(iterator));
    }
    allpurposeiterator->iteratorFilterCode = ((cpp_function_code)(&filterInstanceP));
    return (allpurposeiterator);
  }
}

LogicObject* stringToLogicObject(char* string) {
  { Surrogate* sgt = NULL;
    Iterator* iter000 = allSurrogates(NULL, FALSE);

    while (iter000->nextP()) {
      sgt = ((Surrogate*)(iter000->value));
      if (stringEqlP(sgt->symbolName, string) &&
          (((boolean)(sgt->surrogateValue)) &&
           isaP(sgt->surrogateValue, SGT_API_SUPPORT_LOGIC_LOGIC_OBJECT))) {
        return (((LogicObject*)(sgt->surrogateValue)));
      }
    }
  }
  return (NULL);
}

void startupApiSupport() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      SGT_API_SUPPORT_LOGIC_LOGIC_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("LOGIC-OBJECT", NULL, 1)));
      SGT_API_SUPPORT_LOGIC_PATTERN_VARIABLE = ((Surrogate*)(internRigidSymbolWrtModule("PATTERN-VARIABLE", NULL, 1)));
      SGT_API_SUPPORT_LOGIC_SKOLEM = ((Surrogate*)(internRigidSymbolWrtModule("SKOLEM", NULL, 1)));
      SGT_API_SUPPORT_STELLA_THING = ((Surrogate*)(internRigidSymbolWrtModule("THING", getStellaModule("/STELLA", TRUE), 1)));
      SGT_API_SUPPORT_LOGIC_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 1)));
      SYM_API_SUPPORT_LOGIC_STARTUP_API_SUPPORT = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-API-SUPPORT", NULL, 0)));
      SYM_API_SUPPORT_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", TRUE), 0)));
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("CLASS-NAMES-NEXT?", "(DEFUN (CLASS-NAMES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))", ((cpp_function_code)(&classNamesNextP)), NULL);
      defineFunctionObject("ALL-PROPOSITIONS-NEXT?", "(DEFUN (ALL-PROPOSITIONS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))", ((cpp_function_code)(&allPropositionsNextP)), NULL);
      defineFunctionObject("ALL-PROPOSITIONS", "(DEFUN (ALL-PROPOSITIONS (ITERATOR OF PROPOSITION)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all conceived propositions visible from `module'.\nOnly propositions that haven't been deleted will be considered.\nIf `local?', only return propositions conceived locally in `module'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&allPropositions)), NULL);
      defineFunctionObject("VISIBLE-TERM?", "(DEFUN (VISIBLE-TERM? BOOLEAN) ((TERM LOGIC-OBJECT) (CONTEXT CONTEXT) (LOCAL? BOOLEAN)))", ((cpp_function_code)(&visibleTermP)), NULL);
      defineFunctionObject("ALL-UNNAMED-TERMS", "(DEFUN (ALL-UNNAMED-TERMS ITERATOR) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all unnamed terms visible from `module'.  A term can be\nan instance (or individual) as well as a description.  Only terms that\nhaven't been deleted will be considered.  If `local?', only return\nterms created locally in `module'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&allUnnamedTerms)), NULL);
      defineFunctionObject("ALL-NAMED-TERMS-NEXT?", "(DEFUN (ALL-NAMED-TERMS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))", ((cpp_function_code)(&allNamedTermsNextP)), NULL);
      defineFunctionObject("ALL-NAMED-TERMS", "(DEFUN (ALL-NAMED-TERMS (ITERATOR OF OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all named terms visible from `module'.  A term can be an\ninstance (or individual) as well as a description.  Only terms that\nhaven't been deleted will be considered.  If `local?', only return \nterms created locally in `module'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&allNamedTerms)), NULL);
      defineFunctionObject("ALL-TERMS", "(DEFUN (ALL-TERMS (ITERATOR OF OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Return a list of all terms visible from `module'.  A term can be an\ninstance (or individual) as well as a description.  Only terms that\nhaven't been deleted will be considered.  If `local?', only return \nterms created locally in `module'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&allTerms)), NULL);
      defineFunctionObject("FILTER-INSTANCE?", "(DEFUN (FILTER-INSTANCE? BOOLEAN) ((SELF LOGIC-OBJECT) (ITERATOR ALL-PURPOSE-ITERATOR)))", ((cpp_function_code)(&filterInstanceP)), NULL);
      defineFunctionObject("ALL-NAMED-INSTANCES", "(DEFUN (ALL-NAMED-INSTANCES (ITERATOR OF LOGIC-OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all named instances (or individuals) visible from `module'.\nOnly instances that haven't been deleted will be considered.  If `local?',\nonly return instances created locally in `module'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&allNamedInstances)), NULL);
      defineFunctionObject("ALL-INSTANCES", "(DEFUN (ALL-INSTANCES (ITERATOR OF LOGIC-OBJECT)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all instances (or individuals) visible from `module'.\nOnly instances that haven't been deleted will be considered.  If `local?',\nonly return instances created locally in `module'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&allInstances)), NULL);
      defineFunctionObject("STRING-TO-LOGIC-OBJECT", "(DEFUN (STRING-TO-LOGIC-OBJECT LOGIC-OBJECT) ((STRING STRING)))", ((cpp_function_code)(&stringToLogicObject)), NULL);
      defineFunctionObject("STARTUP-API-SUPPORT", "(DEFUN STARTUP-API-SUPPORT () :PUBLIC? TRUE)", ((cpp_function_code)(&startupApiSupport)), NULL);
      { MethodSlot* function = lookupFunction(SYM_API_SUPPORT_LOGIC_STARTUP_API_SUPPORT);

        setDynamicSlotValue(function->dynamicSlots, SYM_API_SUPPORT_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Api-Support"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      oSTRING_TO_OBJECT_FUNCTIONSo->insertAt(SGT_API_SUPPORT_LOGIC_LOGIC_OBJECT, wrapFunctionCode(((cpp_function_code)(&stringToLogicObject))));
    }
  }
}

Surrogate* SGT_API_SUPPORT_LOGIC_LOGIC_OBJECT = NULL;

Surrogate* SGT_API_SUPPORT_LOGIC_PATTERN_VARIABLE = NULL;

Surrogate* SGT_API_SUPPORT_LOGIC_SKOLEM = NULL;

Surrogate* SGT_API_SUPPORT_STELLA_THING = NULL;

Surrogate* SGT_API_SUPPORT_LOGIC_DESCRIPTION = NULL;

Symbol* SYM_API_SUPPORT_LOGIC_STARTUP_API_SUPPORT = NULL;

Symbol* SYM_API_SUPPORT_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
