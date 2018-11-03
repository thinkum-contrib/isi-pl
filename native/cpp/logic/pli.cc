//  -*- Mode: C++ -*-

// pli.cc

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

namespace pli {
  using namespace stella;
  using namespace logic;

void initialize() {
  // Initialize the PowerLoom logic system.  This needs to
  // be called by all applications before using PowerLoom.
  startupLogicSystem();
}

Environment* newEnvironment() {
  { Environment* self = NULL;

    self = new Environment();
    self->level = NULL;
    return (self);
  }
}

Surrogate* Environment::primaryType() {
  { Environment* self = this;

    return (SGT_PLI_PLI_ENVIRONMENT);
  }
}

Object* accessEnvironmentSlotValue(Environment* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_PLI_LOGIC_LEVEL) {
    if (setvalueP) {
      self->level = ((StringWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapString(self->level);
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

void Environment::printObject(std::ostream* stream) {
  { Environment* self = this;

    *(stream) << "|ENV|" << self->level;
  }
}

Environment* ASSERTION_ENV = NULL;

Environment* TAXONOMIC_ENV = NULL;

Environment* INFERENCE_ENV = NULL;

PlIterator* newPlIterator() {
  { PlIterator* self = NULL;

    self = new PlIterator();
    self->firstIterationP = TRUE;
    self->value = NULL;
    self->cursor = NULL;
    return (self);
  }
}

Surrogate* PlIterator::primaryType() {
  { PlIterator* self = this;

    return (SGT_PLI_PLI_PL_ITERATOR);
  }
}

Object* accessPlIteratorSlotValue(PlIterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_PLI_STELLA_CURSOR) {
    if (setvalueP) {
      self->cursor = ((Cons*)(value));
    }
    else {
      value = self->cursor;
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

boolean PlIterator::nextP() {
  // Advance the PL-Iterator `self' and return `true' if more
  // elements are available, `false' otherwise.
  { PlIterator* self = this;

    { Cons* cursor = self->cursor;

      if (cursor == NIL) {
        self->value = NULL;
        return (FALSE);
      }
      self->value = cursor->value;
      self->cursor = cursor->rest;
      return (TRUE);
    }
  }
}

boolean PlIterator::emptyP() {
  // Return TRUE if the iterator `self' has no more elements.
  { PlIterator* self = this;

    return (self->cursor == NIL);
  }
}

int PlIterator::length() {
  // Number of items in `self'.
  { PlIterator* self = this;

    return (self->cursor->length());
  }
}

// Iterator that generates no values.
PlIterator* EMPTY_PL_ITERATOR = NULL;

PlIterator* consToPlIterator(Cons* self) {
  // Convert a Stella cons list into an API iterator.
  if (self == NIL) {
    return (EMPTY_PL_ITERATOR);
  }
  else {
    { PlIterator* self000 = newPlIterator();

      self000->cursor = self;
      { PlIterator* value000 = self000;

        return (value000);
      }
    }
  }
}

PlIterator* listToPlIterator(List* self) {
  // Convert a Stella list into an API iterator.
  if (self->emptyP()) {
    return (EMPTY_PL_ITERATOR);
  }
  else {
    return (consToPlIterator(self->theConsList));
  }
}

PlIterator* iteratorToPlIterator(Iterator* self) {
  // Convert an arbitrary Stella iterator into an API iterator.
  return (consToPlIterator(self->consify()));
}

List* PlIterator::listify() {
  { PlIterator* self = this;

    { List* self000 = newList();

      { Cons* v096 = NIL;

        { Object* x = NULL;
          PlIterator* iter000 = self;
          Cons* collect000 = NULL;

          while (iter000->nextP()) {
            x = iter000->value;
            if (!((boolean)(collect000))) {
              {
                collect000 = cons(x, NIL);
                if (v096 == NIL) {
                  v096 = collect000;
                }
                else {
                  addConsToEndOfConsList(v096, collect000);
                }
              }
            }
            else {
              {
                collect000->rest = cons(x, NIL);
                collect000 = collect000->rest;
              }
            }
          }
        }
        self000->theConsList = v096;
      }
      { List* value000 = self000;

        return (value000);
      }
    }
  }
}

Cons* PlIterator::consify() {
  { PlIterator* self = this;

    { Cons* v097 = NIL;

      { Object* x = NULL;
        PlIterator* iter000 = self;
        Cons* collect000 = NULL;

        while (iter000->nextP()) {
          x = iter000->value;
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(x, NIL);
              if (v097 == NIL) {
                v097 = collect000;
              }
              else {
                addConsToEndOfConsList(v097, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(x, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      { Cons* value000 = v097;

        return (value000);
      }
    }
  }
}

Object* safelyGetObject(char* name, Module* module, Object* environment) {
  if (name == NULL) {
    return (NULL);
  }
  { Object* object = getObject(name, module, environment);

    if (!((boolean)(object))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Can't find an object named " << "`" << name << "'";
        throw *newNoSuchObjectException(stream000->theStringReader());
      }
    }
    else {
      return (object);
    }
  }
}

Object* safelyGetConcept(char* name, Module* module, Object* environment) {
  if (name == NULL) {
    return (NULL);
  }
  { LogicObject* object = getConcept(name, module, environment);

    if (!((boolean)(object))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Can't find a concept named " << "`" << name << "'";
        throw *newNoSuchObjectException(stream000->theStringReader());
      }
    }
    else {
      return (object);
    }
  }
}

Object* safelyGetRelation(char* name, Module* module, Object* environment) {
  if (name == NULL) {
    return (NULL);
  }
  { LogicObject* object = getRelation(name, module, environment);

    if (!((boolean)(object))) {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Can't find a relation named " << "`" << name << "'";
        throw *newNoSuchObjectException(stream000->theStringReader());
      }
    }
    else {
      return (object);
    }
  }
}

Context* safelyGetModule(char* name, Object* environment) {
  environment = environment;
  if ((name == NULL) ||
      stringEqlP(name, "")) {
    return (oMODULEo.get());
  }
  return (getStellaModule(name, TRUE));
}

Object* safelyGetObjectOrNull(char* name, Module* module, Object* environment) {
  if ((!((boolean)(module))) ||
      ((name == NULL) ||
       (stringEqlP(name, "") ||
        stringEqualP(name, "null")))) {
    return (NULL);
  }
  try {
    return (getObject(name, module, environment));
  }
  catch (NoSuchObjectException ) {
    return (NULL);
  }
}

Cons* sequenceToConsList(Object* sequence) {
  { Surrogate* testValue000 = safePrimaryType(sequence);

    if (testValue000 == SGT_PLI_STELLA_CONS) {
      { Object* sequence000 = sequence;
        Cons* sequence = ((Cons*)(sequence000));

        return (sequence);
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_LIST)) {
      { Object* sequence001 = sequence;
        List* sequence = ((List*)(sequence001));

        return (sequence->theConsList);
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_VECTOR)) {
      { Object* sequence002 = sequence;
        Vector* sequence = ((Vector*)(sequence002));

        { Cons* result = NIL;

          { int i = NULL_INTEGER;
            int iter000 = 0;
            int upperBound000 = sequence->length();
            Cons* collect000 = NULL;

            while (iter000 <= upperBound000) {
              i = iter000;
              iter000 = iter000 + 1;
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons((sequence->theArray)[i], NIL);
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
                  collect000->rest = cons((sequence->theArray)[i], NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
          return (result);
        }
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "Don't know how to convert object of type " << "`" << sequence->primaryType() << "'" << " into a cons list.";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

Cons* explodeStringList(char* stringlist, Module* module) {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, module);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    { Cons* expression = ((Cons*)(readSExpressionFromString(stringlist)));
      Object* term = NULL;
      Cons* result = NIL;

      { Object* ref = NULL;
        Cons* iter000 = expression;
        Cons* collect000 = NULL;

        while (!(iter000 == NIL)) {
          ref = iter000->value;
          iter000 = iter000->rest;
          term = ((ref == SYM_PLI_STELLA_NULL) ? NULL : evaluateTerm(ref));
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(term, NIL);
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
              collect000->rest = cons(term, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      return (result);
    }
  }
}

Object* getObject(char* name, Module* module, Object* environment) {
  // Look for an object named `name' that is local to
  // or visible from the module `module'.
  { Module* currentmodule = (((boolean)(module)) ? module : oMODULEo.get());

    if (!(currentmodule->caseSensitiveP ||
        allUpperCaseStringP(name))) {
      name = stringUpcase(name);
    }
  }
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (getInstance(wrapString(name)));
      }
    }
  }
}

Object* sGetObject(char* name, char* moduleName, Object* environment) {
  // Look for an object named `name' that is local to
  // or visible from the module `module-name'.
  return (getObject(name, ((Module*)(safelyGetModule(moduleName, environment))), environment));
}

LogicObject* getConcept(char* name, Module* module, Object* environment) {
  // Return a class/concept named `name' that is local to
  // or visible from the module `module'.
  { Module* currentmodule = (((boolean)(module)) ? module : oMODULEo.get());

    if (!(currentmodule->caseSensitiveP ||
        allUpperCaseStringP(name))) {
      name = stringUpcase(name);
    }
  }
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (getClass(wrapString(name)));
      }
    }
  }
}

LogicObject* sGetConcept(char* name, char* moduleName, Object* environment) {
  // Return a class/concept named `name' that is local to
  // or visible from the module `module-name'.
  return (getConcept(name, ((Module*)(safelyGetModule(moduleName, environment))), environment));
}

LogicObject* getRelation(char* name, Module* module, Object* environment) {
  // Return a concept or relation named `name' that is local to
  // or visible from the module `module'.
  { Module* currentmodule = (((boolean)(module)) ? module : oMODULEo.get());

    if (!(currentmodule->caseSensitiveP ||
        allUpperCaseStringP(name))) {
      name = stringUpcase(name);
    }
  }
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (logic::getRelation(wrapString(name)));
      }
    }
  }
}

LogicObject* sGetRelation(char* name, char* moduleName, Object* environment) {
  // Return a concept or relation named `name' that is local to
  // or visible from the module `module-name'.
  return (getRelation(name, ((Module*)(safelyGetModule(moduleName, environment))), environment));
}

char* getName(Object* obj) {
  // Return the name of `obj', if it has one.  Otherwise return `null'.
  { Surrogate* testValue000 = safePrimaryType(obj);

    if (subtypeOfP(testValue000, SGT_PLI_LOGIC_SKOLEM)) {
      { Object* obj000 = obj;
        Skolem* obj = ((Skolem*)(obj000));

        return (NULL);
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
      { Object* obj001 = obj;
        LogicObject* obj = ((LogicObject*)(obj001));

        return (objectNameString(obj));
      }
    }
    else if (subtypeOfKeywordP(testValue000)) {
      { Object* obj002 = obj;
        Keyword* obj = ((Keyword*)(obj002));

        return (stringConcatenate(":", obj->symbolName, 0));
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_GENERALIZED_SYMBOL)) {
      { Object* obj003 = obj;
        GeneralizedSymbol* obj = ((GeneralizedSymbol*)(obj003));

        return (obj->symbolName);
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_CONTEXT)) {
      { Object* obj004 = obj;
        Context* obj = ((Context*)(obj004));

        return (obj->contextName());
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_LOGIC_COMPUTED_PROCEDURE)) {
      { Object* obj005 = obj;
        ComputedProcedure* obj = ((ComputedProcedure*)(obj005));

        return (obj->surrogateValueInverse->symbolName);
      }
    }
    else {
      return (NULL);
    }
  }
}

char* objectToString(Object* self) {
  // Return a printed representation of the term `self' as a string.
  if (!((boolean)(self))) {
    return (NULL);
  }
  else {
    { 
      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
      { Surrogate* testValue000 = safePrimaryType(self);

        if (subtypeOfStringP(testValue000)) {
          { Object* self000 = self;
            StringWrapper* self = ((StringWrapper*)(self000));

            return (self->wrapperValue);
          }
        }
        else if (subtypeOfP(testValue000, SGT_PLI_LOGIC_SKOLEM)) {
          { Object* self001 = self;
            Skolem* self = ((Skolem*)(self001));

            { Object* value = valueOf(self);

              if (value == self) {
                return (stringify(self));
              }
              else {
                return (objectToString(value));
              }
            }
          }
        }
        else if (subtypeOfP(testValue000, SGT_PLI_PLI_PL_ITERATOR)) {
          { Object* self002 = self;
            PlIterator* self = ((PlIterator*)(self002));

            return (stringify(self->consify()));
          }
        }
        else {
          return (stringify(self));
        }
      }
    }
  }
}

int objectToInteger(Object* self) {
  // Coerce `self' to an integer, or throw a Stella Exception if the coersion is not feasible.
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_PLI_LOGIC_SKOLEM)) {
      { Object* self000 = self;
        Skolem* self = ((Skolem*)(self000));

        { Object* value = valueOf(self);

          if (value == self) {
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "Can't coerce " << "`" << self << "'" << " to an integer.";
              throw *newStellaException(stream000->theStringReader());
            }
          }
          else {
            return (objectToInteger(value));
          }
        }
      }
    }
    else if (subtypeOfIntegerP(testValue000)) {
      { Object* self001 = self;
        IntegerWrapper* self = ((IntegerWrapper*)(self001));

        return (self->wrapperValue);
      }
    }
    else if (subtypeOfFloatP(testValue000)) {
      { Object* self002 = self;
        FloatWrapper* self = ((FloatWrapper*)(self002));

        return (stella::round(self->wrapperValue));
      }
    }
    else {
      { OutputStringStream* stream001 = newOutputStringStream();

        *(stream001->nativeStream) << "Can't coerce " << "`" << self << "'" << " to an integer.";
        throw *newStellaException(stream001->theStringReader());
      }
    }
  }
}

double objectToFloat(Object* self) {
  // Coerce `self' to a float, or throw a Stella Exception if the coersion is not feasible.
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_PLI_LOGIC_SKOLEM)) {
      { Object* self000 = self;
        Skolem* self = ((Skolem*)(self000));

        { Object* value = valueOf(self);

          if (value == self) {
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "Can't coerce " << "`" << self << "'" << " to a float.";
              throw *newStellaException(stream000->theStringReader());
            }
          }
          else {
            return (objectToFloat(value));
          }
        }
      }
    }
    else if (subtypeOfIntegerP(testValue000)) {
      { Object* self001 = self;
        IntegerWrapper* self = ((IntegerWrapper*)(self001));

        return (self->numberWrapperToFloat());
      }
    }
    else if (subtypeOfFloatP(testValue000)) {
      { Object* self002 = self;
        FloatWrapper* self = ((FloatWrapper*)(self002));

        return (self->wrapperValue);
      }
    }
    else {
      { OutputStringStream* stream001 = newOutputStringStream();

        *(stream001->nativeStream) << "Can't coerce " << "`" << self << "'" << " to a float.";
        throw *newStellaException(stream001->theStringReader());
      }
    }
  }
}

char* objectToParsableString(Object* self) {
  // Return a string representing a printed
  // representation of the object `self'.  Like `object-to-string', but puts
  // escaped double quotes around strings.
  if (subtypeOfStringP(safePrimaryType(self))) {
    { Object* self000 = self;
      StringWrapper* self = ((StringWrapper*)(self000));

      return (stringConcatenate("\"", self->wrapperValue, 1, "\""));
    }
  }
  else {
    return (objectToString(self));
  }
}

NamedDescription* oLITERAL_CONCEPTo = NULL;

NamedDescription* oSTRING_CONCEPTo = NULL;

NamedDescription* oINTEGER_CONCEPTo = NULL;

NamedDescription* oFLOAT_CONCEPTo = NULL;

Object* stringToObject(char* string, LogicObject* type, Module* module, Object* environment) {
  // Evaluate `string' with respect to `module' and `environment'
  // and return the corresponding logical term.  `type' is a concept used to assist the
  // correct interpretation of `string'.
  // 
  // Currently `type' only has an effect on the interpretation of literal types.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { Object* obj = readSExpressionFromString(string);

          if (subtypeOfP(safePrimaryType(obj), SGT_PLI_STELLA_LITERAL_WRAPPER)) {
            { Object* obj000 = obj;
              LiteralWrapper* obj = ((LiteralWrapper*)(obj000));

              if (!((boolean)(type))) {
                return (obj);
              }
              { Surrogate* testValue000 = safePrimaryType(obj);

                if (subtypeOfStringP(testValue000)) {
                  { LiteralWrapper* obj001 = obj;
                    StringWrapper* obj = ((StringWrapper*)(obj001));

                    if (subrelationOfP(((NamedDescription*)(type)), oSTRING_CONCEPTo)) {
                      return (obj);
                    }
                    else {
                      { OutputStringStream* stream000 = newOutputStringStream();

                        *(stream000->nativeStream) << "String argument found, but " << "`" << type << "'" << " is not a subconcept of " << "`" << oSTRING_CONCEPTo << "'";
                        throw *newParsingError(stream000->theStringReader());
                      }
                    }
                  }
                }
                else if (subtypeOfIntegerP(testValue000)) {
                  { LiteralWrapper* obj002 = obj;
                    IntegerWrapper* obj = ((IntegerWrapper*)(obj002));

                    if (subrelationOfP(((NamedDescription*)(type)), oINTEGER_CONCEPTo)) {
                      return (obj);
                    }
                    else if (subrelationOfP(((NamedDescription*)(type)), oFLOAT_CONCEPTo)) {
                      return (wrapFloat(((double)(obj->wrapperValue))));
                    }
                    else {
                      return (getObject(string, module, environment));
                    }
                  }
                }
                else if (subtypeOfFloatP(testValue000)) {
                  { LiteralWrapper* obj003 = obj;
                    FloatWrapper* obj = ((FloatWrapper*)(obj003));

                    if (subrelationOfP(((NamedDescription*)(type)), oFLOAT_CONCEPTo)) {
                      return (obj);
                    }
                    else {
                      return (getObject(string, module, environment));
                    }
                  }
                }
                else {
                  { OutputStringStream* stream001 = newOutputStringStream();

                    *(stream001->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
                    throw *newStellaException(stream001->theStringReader());
                  }
                }
              }
            }
          }
          else {
            if (!((boolean)(type))) {
              return (getObject(string, module, environment));
            }
            else if (subrelationOfP(((NamedDescription*)(type)), oSTRING_CONCEPTo)) {
              return (wrapString(string));
            }
            else if (subrelationOfP(((NamedDescription*)(type)), oLITERAL_CONCEPTo)) {
              { OutputStringStream* stream002 = newOutputStringStream();

                *(stream002->nativeStream) << "`" << string << "'" << " is a non-literal, but " << "`" << type << "'" << " is a subconcept of " << "`" << oLITERAL_CONCEPTo << "'";
                throw *newParsingError(stream002->theStringReader());
              }
            }
            else {
              return (getObject(string, module, environment));
            }
          }
        }
      }
    }
  }
}

Cons* helpGetTrueExtensionMembers(NamedDescription* relation, boolean specializeP) {
  { Cons* v098 = NIL;

    { Object* p = NULL;
      Iterator* iter000 = allExtensionMembers(relation);
      Cons* collect000 = NULL;

      while (iter000->nextP()) {
        p = iter000->value;
        if ((!((Proposition*)(p))->deletedP()) &&
            ((oREVERSEPOLARITYpo.get() ? falseP(((Proposition*)(p))) : (trueP(((Proposition*)(p))) ||
            functionWithDefinedValueP(((Proposition*)(p))))))) {
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(p, NIL);
              if (v098 == NIL) {
                v098 = collect000;
              }
              else {
                addConsToEndOfConsList(v098, collect000);
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
    { Cons* result = v098;

      if (specializeP) {
        { LogicObject* sub = NULL;
          Iterator* iter001 = allSubcollections(relation);

          while (iter001->nextP()) {
            sub = ((LogicObject*)(iter001->value));
            if (isaP(sub, SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
              { Object* p = NULL;
                Iterator* iter002 = allExtensionMembers(((NamedDescription*)(sub)));

                while (iter002->nextP()) {
                  p = iter002->value;
                  if ((!((Proposition*)(p))->deletedP()) &&
                      ((oREVERSEPOLARITYpo.get() ? falseP(((Proposition*)(p))) : (trueP(((Proposition*)(p))) ||
                      functionWithDefinedValueP(((Proposition*)(p))))))) {
                    result = cons(p, result);
                  }
                }
              }
            }
          }
        }
        return (result->removeDuplicates());
      }
      return (result);
    }
  }
}

Cons* helpGetPropositions(LogicObject* relation, Cons* arguments, int limit, Module* module, Object* environment) {
  if (!((boolean)(relation))) {
    return (NIL);
  }
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { boolean specializeP = !(environment == ASSERTION_ENV);

          { Object* value000 = NULL;

            { Object* arg = NULL;
              Cons* iter000 = arguments;

              while (!(iter000 == NIL)) {
                arg = iter000->value;
                iter000 = iter000->rest;
                if (((boolean)(arg)) &&
                    isaP(arg, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
                  value000 = arg;
                  break;
                }
              }
            }
            { Object* argumentwithbacklinks = value000;
              Iterator* iterator = (((boolean)(argumentwithbacklinks)) ? ((Iterator*)(allTrueDependentPropositions(argumentwithbacklinks, relation->surrogateValueInverse, specializeP))) : helpGetTrueExtensionMembers(((NamedDescription*)(relation)), specializeP)->allocateIterator());
              Cons* results = NIL;

              { Proposition* p = NULL;
                Iterator* iter001 = iterator;

                while (iter001->nextP()) {
                  p = ((Proposition*)(iter001->value));
                  { boolean testValue000 = FALSE;

                    { boolean alwaysP000 = TRUE;

                      { Object* inputarg = NULL;
                        Object* arg2 = NULL;
                        Cons* iter002 = arguments;
                        Vector* vector000 = p->arguments;
                        int index000 = 0;
                        int length000 = vector000->length();

                        while ((!(iter002 == NIL)) &&
                            (index000 < length000)) {
                          inputarg = iter002->value;
                          iter002 = iter002->rest;
                          arg2 = (vector000->theArray)[index000];
                          index000 = index000 + 1;
                          if (!((!((boolean)(inputarg))) ||
                              eqlP(inputarg, valueOf(arg2)))) {
                            alwaysP000 = FALSE;
                            break;
                          }
                        }
                      }
                      testValue000 = alwaysP000;
                    }
                    if (testValue000) {
                      testValue000 = arguments->length() == p->arguments->length();
                    }
                    if (testValue000) {
                      results = cons(p, results);
                      limit = limit - 1;
                      if (limit == 0) {
                        break;
                      }
                    }
                  }
                }
              }
              return (results);
            }
          }
        }
      }
    }
  }
}

Proposition* getProposition(Object* relationAndArguments, Module* module, Object* environment) {
  // Return a proposition matching `relation-and-arguments' that
  // has been asserted (or inferred by forward chaining).  `relation-and-arguments'
  // is a sequence containing objects and nulls.  The first argument must be the
  // name of a relation.  A null value acts like a wild card.  If more than one 
  // proposition matches the input criteria, the selection among satisficing
  // propositions is arbitrary.  This procedure is normally applied to single-valued
  // relations or functions.
  { Cons* list = sequenceToConsList(relationAndArguments);
    Object* relation = list->value;
    Cons* arguments = list->rest;

    return (((Proposition*)(helpGetPropositions(((LogicObject*)(relation)), arguments, 1, module, environment)->value)));
  }
}

Proposition* sGetProposition(char* relationAndArguments, char* moduleName, Object* environment) {
  // Return a proposition matching `relation-and-arguments' that
  // has been asserted (or inferred by forward chaining).  `relation-and-arguments'
  // is a string that begins with a left parenthesis, followed by a relation name, 
  // one or more argument identifiers, and terminated by a right parenthesis.  Each
  // argument identifier can be the name of a logical constant, a literal
  // reference (e.g., a number), the null identifier, or a variable (an identifier that begins
  // with a question mark). Each occurrence of a null or a variable acts like a wild card.
  // If more than one proposition matches the input criteria, the selection among
  // satisficing propositions is arbitrary.  This procedure is normally applied to
  // single-valued relations or functions.
  { Context* module = safelyGetModule(moduleName, environment);
    Cons* elements = explodeStringList(relationAndArguments, ((Module*)(module)));
    Object* relation = elements->value;
    Cons* arguments = elements->rest;

    return (((Proposition*)(helpGetPropositions(((LogicObject*)(relation)), arguments, 1, ((Module*)(module)), environment)->value)));
  }
}

PlIterator* getPropositions(Object* relationAndArguments, Module* module, Object* environment) {
  // Return propositions matching `relation-and-arguments' that
  // have been asserted (or inferred by forward chaining).  `relation-and-arguments'
  // is a sequence containing objects and nulls.  The first argument must be the
  // name of a relation.  A null value acts like a wild card.
  { Cons* list = sequenceToConsList(relationAndArguments);
    Object* relation = list->value;
    Cons* arguments = list->rest;

    return (consToPlIterator(helpGetPropositions(((LogicObject*)(relation)), arguments, 0, module, environment)));
  }
}

PlIterator* sGetPropositions(char* relationAndArguments, char* moduleName, Object* environment) {
  // Return propositions matching `relation-and-arguments' that
  // have been asserted (or inferred by forward chaining).  `relation-and-arguments'
  // is a string that begins with a left parenthesis, followed by a relation name, 
  // one or more argument identifiers, and terminated by a right parenthesis.  Each
  // argument identifier can be the name of a logical constant, a literal 
  // reference (e.g., a number), the null identifier, or a variable (an identifier that begins
  // with a question mark). Each occurrence of a null or a variable acts like a wild card.
  { Context* module = safelyGetModule(moduleName, environment);
    Cons* elements = explodeStringList(relationAndArguments, ((Module*)(module)));
    Object* relation = elements->value;
    Cons* arguments = elements->rest;

    return (consToPlIterator(helpGetPropositions(((LogicObject*)(relation)), arguments, 0, ((Module*)(module)), environment)));
  }
}

Proposition* getBinaryProposition(LogicObject* relation, Object* arg1, Object* arg2, Module* module, Object* environment) {
  // Return a proposition such that (`relation' `arg1' `arg2')
  // is true.  The `relation' argument must be bound to a relation.  One or both
  // of the `arg1' and `arg2' arguments may be set to NULL, which is interpreted
  // as a wildcard. If more than one proposition matches the input criteria,
  // the selection is arbitrary.  This procedure is normally applied to single-valued
  // relations or functions.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { LogicObject* argumentwithbacklinks = NULL;

          if (((boolean)(arg1)) &&
              isaP(arg1, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
            argumentwithbacklinks = ((LogicObject*)(arg1));
          }
          else if (((boolean)(arg2)) &&
              isaP(arg2, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
            argumentwithbacklinks = ((LogicObject*)(arg2));
          }
          if (((boolean)(argumentwithbacklinks))) {
            { Proposition* p = NULL;
              Iterator* iter000 = allTrueDependentPropositions(argumentwithbacklinks, relation->surrogateValueInverse, FALSE);

              while (iter000->nextP()) {
                p = ((Proposition*)(iter000->value));
                if (((!((boolean)(arg1))) ||
                    eqlP(arg1, valueOf((p->arguments->theArray)[0]))) &&
                    ((!((boolean)(arg2))) ||
                     eqlP(arg2, valueOf((p->arguments->theArray)[1])))) {
                  return (p);
                }
              }
            }
          }
          else {
            return (((Proposition*)(helpGetPropositions(relation, consList(2, arg1, arg2), 1, module, environment)->value)));
          }
          return (NULL);
        }
      }
    }
  }
}

PlIterator* getBinaryPropositions(LogicObject* relation, Object* arg1, Object* arg2, Module* module, Object* environment) {
  // Return propositions such that (`relation' `arg1' `arg2')
  // is true.  The `relation' argument
  // must be bound to a relation.  One or both of the `arg1' and `arg2' arguments
  // may be set to NULL, which is interpreted as a wildcard.
  return (consToPlIterator(helpGetPropositions(relation, consList(2, arg1, arg2), 0, module, environment)));
}

PlIterator* getInferredBinaryPropositionValues(LogicObject* relation, Object* arg, Module* module, Object* environment) {
  // Return all values `v' such that (`relation' `arg' `v')
  // has been asserted or can be inferred.
  { Cons* dummy1;

    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (consToPlIterator(applyCachedRetrieve(listO(4, SYM_PLI_PLI_pR, SYM_PLI_PLI_pI, SYM_PLI_PLI_pV, NIL), listO(4, SYM_PLI_PLI_pR, SYM_PLI_PLI_pI, SYM_PLI_PLI_pV, NIL), consList(3, relation, arg, NULL), consList(0), SYM_PLI_PLI_QUERY_099, dummy1)));
        }
      }
    }
  }
}

PlIterator* sGetInferredBinaryPropositionValues(char* relationName, char* argName, char* moduleName, Object* environment) {
  // Return all values `v' such that (`relation-name' `arg-name' `v')
  // has been asserted or can be inferred.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);
    Object* object = safelyGetObject(argName, ((Module*)(module)), environment);

    if (((boolean)(object)) &&
        ((boolean)(relation))) {
      return (getInferredBinaryPropositionValues(((LogicObject*)(relation)), object, ((Module*)(module)), environment));
    }
    else {
      return (EMPTY_PL_ITERATOR);
    }
  }
}

PlIterator* getPropositionsOf(LogicObject* object, Module* module, Object* environment) {
  // Return all propositions that have `object' among their arguments,
  // and that are TRUE in the scope of the module `module'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (listToPlIterator(allFactsOfInstance(object, FALSE, FALSE)));
      }
    }
  }
}

PlIterator* sGetPropositionsOf(char* objectName, char* moduleName, Object* environment) {
  // Return all propositions that have the object named `object-name' among
  // their arguments, and that are TRUE in the scope of the module `module'.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* object = safelyGetObject(objectName, ((Module*)(module)), environment);

    if (((boolean)(object))) {
      return (getPropositionsOf(((LogicObject*)(object)), ((Module*)(module)), environment));
    }
    else {
      return (EMPTY_PL_ITERATOR);
    }
  }
}

PlIterator* getPropositionsInModule(Module* module, Object* environment) {
  // Return propositions that have been conceived in
  // the module `module'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(allPropositions(oMODULEo.get(), TRUE)->consify()));
      }
    }
  }
}

boolean isTrueUnaryProposition(LogicObject* relation, Object* arg, Module* module, Object* environment) {
  // Return TRUE if the proposition (`relation' `arg') has
  // been asserted (or inferred by forward chaining).
  return (((boolean)(helpGetPropositions(relation, consList(1, arg), 1, module, environment))));
}

boolean isTrueBinaryProposition(LogicObject* relation, Object* arg, Object* value, Module* module, Object* environment) {
  // Return TRUE if the proposition (`relation' `arg' `value') has
  // been asserted (or inferred by forward chaining).
  return (((boolean)(getBinaryProposition(relation, arg, value, module, environment))));
}

boolean isTrueProposition1(Object* relationAndArguments, Module* module, Object* environment) {
  // Return TRUE if a proposition (`relation' `args') has
  // been asserted (or inferred by forward chaining).
  { Cons* list = sequenceToConsList(relationAndArguments);
    Object* relation = list->value;
    Cons* arguments = list->rest;

    return (((boolean)(helpGetPropositions(((LogicObject*)(relation)), arguments, 1, module, environment))));
  }
}

boolean isTrueProposition(Proposition* proposition, Module* module, Object* environment) {
  // Return TRUE if `proposition' is  TRUE in the module `module'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return ((!proposition->deletedP()) &&
            ((oREVERSEPOLARITYpo.get() ? falseP(proposition) : (trueP(proposition) ||
            functionWithDefinedValueP(proposition)))));
      }
    }
  }
}

boolean sIsTrueProposition(char* relationAndArguments, char* moduleName, Object* environment) {
  // Return TRUE if a proposition that prints as the string
  // `relation-and-arguments' is true in the module named `module-name'.
  return (((boolean)(sGetProposition(relationAndArguments, moduleName, environment))));
}

boolean isSubrelation(LogicObject* sub, LogicObject* super, Module* module, Object* environment) {
  // Return TRUE if `sub' is a subconcept/subrelation of `super'.
  if ((!((boolean)(sub))) ||
      (!((boolean)(super)))) {
    return (FALSE);
  }
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (trueTruthValueP(descriptionSpecializesDescriptionP(((Description*)(sub)), ((Description*)(super)))));
      }
    }
  }
}

PlIterator* getProperSubrelations(LogicObject* relation, Module* module, Object* environment) {
  // Return relations that specialize `relation'.
  // Non-reflexive.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(allSubrelations(((NamedDescription*)(relation)), TRUE)));
      }
    }
  }
}

PlIterator* getDirectSubrelations(LogicObject* relation, Module* module, Object* environment) {
  // Return relations that directly specialize `relation'.
  // Non-reflexive.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(allDirectSubrelations(((NamedDescription*)(relation)), TRUE)));
      }
    }
  }
}

PlIterator* getProperSuperrelations(LogicObject* relation, Module* module, Object* environment) {
  // Return relations that generalize `relation'.
  // Non-reflexive.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(allSuperrelations(((NamedDescription*)(relation)), TRUE)));
      }
    }
  }
}

PlIterator* getDirectSuperrelations(LogicObject* relation, Module* module, Object* environment) {
  // Return relations that directly generalize `relation'.
  // Non-reflexive.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(allDirectSuperrelations(((NamedDescription*)(relation)), TRUE)));
      }
    }
  }
}

boolean isA(Object* object, LogicObject* concept, Module* module, Object* environment) {
  // Return TRUE if `object' is a member of the concept `concept'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (testIsaP(object, concept->surrogateValueInverse));
      }
    }
  }
}

PlIterator* getConceptInstances(LogicObject* concept, Module* module, Object* environment) {
  // Return instances of the concept `concept'.
  // Include instances of subconcepts of `concept'.  Depending on `concept',
  // the return values could be (wrapped) literals.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (listToPlIterator(assertedCollectionMembers(concept, FALSE)->removeDeletedMembers()));
      }
    }
  }
}

PlIterator* sGetConceptInstances(char* conceptName, char* moduleName, Object* environment) {
  // Return instances of concept `concept-name'.
  // Include instances of subconcepts of `concept-name'.  Depending on `concept-name',
  // the return values could be (wrapped) literals.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* concept = safelyGetConcept(conceptName, ((Module*)(module)), environment);

    if (((boolean)(concept))) {
      return (getConceptInstances(((LogicObject*)(concept)), ((Module*)(module)), environment));
    }
    else {
      return (EMPTY_PL_ITERATOR);
    }
  }
}

PlIterator* getDirectConceptInstances(LogicObject* concept, Module* module, Object* environment) {
  // Return instances of concept `concept'.
  // Exclude instances of subconcepts of `concept'.  Depending on `concept',
  // the return values could be (wrapped) literals.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (listToPlIterator(assertedCollectionMembers(concept, TRUE)));
      }
    }
  }
}

PlIterator* sGetDirectConceptInstances(char* conceptName, char* moduleName, Object* environment) {
  // Return instances of concept `concept-name'.
  // Exclude instances of subconcepts of `concept-name'.  Depending on `concept-name',
  // the return values could be (wrapped) literals.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* concept = safelyGetConcept(conceptName, ((Module*)(module)), environment);

    if (((boolean)(concept))) {
      return (getDirectConceptInstances(((LogicObject*)(concept)), ((Module*)(module)), environment));
    }
    else {
      return (EMPTY_PL_ITERATOR);
    }
  }
}

PlIterator* getConceptInstancesMatchingValue(LogicObject* concept, LogicObject* relation, Object* value, Module* module, Object* environment) {
  // Return members of concept `concept' that
  // have an attribute matching `value' for the binary relation `relation', i.e.,
  // `(relation <result> value)' holds.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { PlIterator* instances = getConceptInstances(concept, module, environment);
          Cons* answers = NIL;

          { Object* i = NULL;
            PlIterator* iter000 = instances;

            while (iter000->nextP()) {
              i = iter000->value;
              if (isTrueBinaryProposition(relation, i, value, module, environment)) {
                answers = cons(i, answers);
              }
            }
          }
          return (consToPlIterator(answers));
        }
      }
    }
  }
}

Object* getConceptInstanceMatchingValue(LogicObject* concept, LogicObject* relation, Object* value, Module* module, Object* environment) {
  // Return a member of concept `concept' that
  // has an attribute matching `value' for the binary relation `relation', i.e.,
  // `(relation <result> value)' holds.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { PlIterator* instances = getConceptInstances(concept, module, environment);

          { Object* i = NULL;
            PlIterator* iter000 = instances;

            while (iter000->nextP()) {
              i = iter000->value;
              if (isTrueBinaryProposition(relation, i, value, module, environment)) {
                return (i);
              }
            }
          }
          return (NULL);
        }
      }
    }
  }
}

PlIterator* getTypes(LogicObject* object, Module* module, Object* environment) {
  // Return all named concepts that `object' belongs to.
  { PlIterator* directtypes = getDirectTypes(object, module, environment);
    Cons* types = NIL;

    { LogicObject* d = NULL;
      PlIterator* iter000 = directtypes;

      while (iter000->nextP()) {
        d = ((LogicObject*)(iter000->value));
        if (!types->memberP(d)) {
          types = cons(d, types);
        }
        { LogicObject* c = NULL;
          Iterator* iter001 = allSupercollections(d);

          while (iter001->nextP()) {
            c = ((LogicObject*)(iter001->value));
            if (isaP(c, SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
              if (!types->memberP(c)) {
                types = cons(c, types);
              }
            }
          }
        }
      }
    }
    return (consToPlIterator(types));
  }
}

PlIterator* getDirectTypes(LogicObject* object, Module* module, Object* environment) {
  // Return most specific concepts that `object' belongs to.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { Cons* derivabletypes = NIL;

          { Proposition* prop = NULL;
            Iterator* iter000 = allTrueDependentPropositions(object, NULL, FALSE);

            while (iter000->nextP()) {
              prop = ((Proposition*)(iter000->value));
              if (prop->kind == KWD_PLI_ISA) {
                derivabletypes = cons(getNthValue(prop, 0), derivabletypes);
              }
            }
          }
          return (consToPlIterator(mostSpecificNamedDescriptions(derivabletypes)));
        }
      }
    }
  }
}

PlIterator* getRelationExtension(LogicObject* relation, Module* module, Object* environment) {
  // Return propositions that satisfy `relation'.
  // Include propositions that satisfy subrelations of `relation'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(helpGetTrueExtensionMembers(((NamedDescription*)(relation)), TRUE)));
      }
    }
  }
}

PlIterator* sGetRelationExtension(char* relationName, Module* module, Object* environment) {
  // Return propositions that satisfy the relation named
  // `relation-name'.  Include propositions that satisfy subrelations of the relation.
  { Object* relation = safelyGetRelation(relationName, module, environment);

    if (((boolean)(relation))) {
      return (getRelationExtension(((LogicObject*)(relation)), module, environment));
    }
    else {
      return (EMPTY_PL_ITERATOR);
    }
  }
}

Module* getModule(char* name, Object* environment) {
  // Return a module named `name'.
  environment = environment;
  return (getStellaModule(name, FALSE));
}

Module* getHomeModule(LogicObject* object) {
  // Return the module in which `object' was created.
  return (object->homeModule());
}

Object* changeModule(Module* module) {
  // Set the current module to `module'.  The return value
  // is `module' unless the context switch cannot be performed, in which case
  // the current module is returned.
  if (!((boolean)(module))) {
    return (oMODULEo.get());
  }
  return (module->changeContext());
}

Object* sChangeModule(char* name, Object* environment) {
  // Set the current module to the module named `name'.  
  // The return value is the module named `name' unless the context switch
  // cannot be performed, in which case the current module is returned.
  { Context* module = safelyGetModule(name, environment);

    if (((boolean)(module))) {
      return (module->changeContext());
    }
    else {
      return (oMODULEo.get());
    }
  }
}

Module* clearModule(Module* module) {
  // Destroy the contents of the module `module' as well as
  // the contents of all of its children, recursively.
  callClearModule(consList(1, module));
  return (module);
}

Module* sClearModule(char* name, Object* environment) {
  // Destroy the contents of the module named `name', as
  // well as the contents of all of its children, recursively.
  { Context* module = safelyGetModule(name, environment);

    callClearModule(consList(1, module));
    return (((Module*)(module)));
  }
}

PlIterator* getChildModules(Module* module) {
  // Return the modules that are immediate children of `module'.
  { Cons* directsubmodules = NIL;

    { Context* child = NULL;
      Cons* iter000 = module->childContexts->theConsList;
      Cons* collect000 = NULL;

      while (!(iter000 == NIL)) {
        child = ((Context*)(iter000->value));
        iter000 = iter000->rest;
        if (isaP(child, SGT_PLI_STELLA_MODULE)) {
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(child, NIL);
              if (directsubmodules == NIL) {
                directsubmodules = collect000;
              }
              else {
                addConsToEndOfConsList(directsubmodules, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(child, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    return (consToPlIterator(directsubmodules));
  }
}

PlIterator* sGetChildModules(char* name, Object* environment) {
  // Return the modules that are immediate children of module `name'.
  return (getChildModules(((Module*)(safelyGetModule(name, environment)))));
}

PlIterator* getParentModules(Module* module) {
  // Return the modules that are immediate parents of `module'.
  return (listToPlIterator(module->parentModules));
}

PlIterator* sGetParentModules(char* name, Object* environment) {
  // Return the modules that are immediate parents of module `name'.
  return (getParentModules(((Module*)(safelyGetModule(name, environment)))));
}

PlIterator* getModules() {
  // Return all modules currently loaded into PowerLoom.
  { Cons* v100 = NIL;

    { Module* m = NULL;
      Iterator* iter000 = allModules();
      Cons* collect000 = NULL;

      while (iter000->nextP()) {
        m = ((Module*)(iter000->value));
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(m, NIL);
            if (v100 == NIL) {
              v100 = collect000;
            }
            else {
              addConsToEndOfConsList(v100, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(m, NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    { Cons* modules = v100;

      return (consToPlIterator(modules));
    }
  }
}

char* generateUniqueName(char* prefix, Module* module, Object* environment) {
  // Generates a name based on `prefix' with a number appended that
  // is not currently in use in the knowledge base.
  environment = environment;
  if (!((boolean)(module))) {
    module = oMODULEo.get();
  }
  return (yieldUniqueGensymName(prefix, module));
}

LogicObject* createObject(char* name, LogicObject* concept, Module* module, Object* environment) {
  // Create an object named `name' of type `concept' in the designated
  // module.  Both `name' and `concept' can be `null'.  If `name' is `null' then an object
  // will be created with a new, non-conflicting name based on the name of `concept', or
  // system-generated if no concept is specified.  If `concept' is `null', then the object
  // will be of type THING.
  // 
  // Return the object.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        { LogicObject* object = NULL;

          if (name != NULL) {
            object = ((LogicObject*)(createLogicInstance(internSurrogate(name), NULL)));
          }
          else if (((boolean)(concept))) {
            object = ((LogicObject*)(createLogicInstance(internSurrogate(generateUniqueName(getName(concept), NULL, NULL)), NULL)));
          }
          else {
            object = ((LogicObject*)(createLogicInstance(internSurrogate(generateUniqueName("I-", NULL, NULL)), NULL)));
          }
          if (((boolean)(concept))) {
            if (((boolean)(assertUnaryProposition(concept, object, module, environment)))) {
              return (object);
            }
            else {
              return (NULL);
            }
          }
          return (object);
        }
      }
    }
  }
}

LogicObject* sCreateObject(char* name, char* conceptName, char* moduleName, Object* environment) {
  // Create an object named `name' of type `concept-name' in the designated
  // module.  Both `name' and `concept-name' can be null strings.  If `name' is a null string
  // then an object will be created with a new, non-conflicting name based on `concept-name', or
  // system-generated if no concept nameis specified.  If `concept-name' is the null string, then
  // the object will be of type THING.
  // 
  // Return the object.
  { Context* module = safelyGetModule(moduleName, environment);

    return (createObject(name, ((LogicObject*)(safelyGetConcept(conceptName, ((Module*)(module)), environment))), ((Module*)(module)), environment));
  }
}

LogicObject* createConcept(char* name, LogicObject* parent, Module* module, Object* environment) {
  // Create a concept named `name' in the designated `module', with the
  // designated `parent' superconcept (which can be left undefined).  Additional
  // superconcepts can be added via assertions of the `subset-of' relation.  Note
  // that a specified `parent' concept needs to be created separately.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (callDefconcept(cons(internSymbol(name), ((((boolean)(parent)) ? listO(3, KWD_PLI_SUBSET_OF, objectName(parent), NIL) : NIL))->concatenate(NIL, 0))));
      }
    }
  }
}

LogicObject* sCreateConcept(char* name, char* parentName, char* moduleName, Object* environment) {
  // Create a concept named `name' in the designated module, with
  // with the concept named `parent-name' as superconcept (which can be left
  // undefined).  Additional superconcepts can be added via assertions of the
  // `subset-of' relation.  Note that a specified parent concept needs to be
  // created separately.
  { Context* module = safelyGetModule(moduleName, environment);

    return (createConcept(name, ((LogicObject*)(safelyGetConcept(parentName, ((Module*)(module)), environment))), ((Module*)(module)), environment));
  }
}

LogicObject* createRelation(char* name, int arity, Module* module, Object* environment) {
  // Create a relation named `name' with arity `arity' in the
  // designated module.  Domain and range information can be added via assertions
  // of `nth-domain' (or `domain' and `range') relations.
  if (!(arity > 0)) {
    { OutputStringStream* stream000 = newOutputStringStream();

      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
        *(stream000->nativeStream) << "PARSING ERROR: " << "Relations must have arity of at least 1" << "." << std::endl;
        helpSignalPropositionError(stream000, KWD_PLI_ERROR);
      }
      throw *newParsingError(stream000->theStringReader());
    }
  }
  { Cons* args = NIL;

    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          { int i = NULL_INTEGER;
            int iter000 = 0;
            int upperBound000 = arity - 1;
            Cons* collect000 = NULL;

            while (iter000 <= upperBound000) {
              i = iter000;
              iter000 = iter000 + 1;
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(yieldSystemDefinedParameterName(i, oMODULEo.get()), NIL);
                  if (args == NIL) {
                    args = collect000;
                  }
                  else {
                    addConsToEndOfConsList(args, collect000);
                  }
                }
              }
              else {
                {
                  collect000->rest = cons(yieldSystemDefinedParameterName(i, oMODULEo.get()), NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
          return (callDefrelation(cons(internSymbol(name), cons(args, NIL))));
        }
      }
    }
  }
}

LogicObject* sCreateRelation(char* name, int arity, char* moduleName, Object* environment) {
  // Create a relation named `name' with arity `arity' in the
  // designated module.  Domain and range information can be added via assertions
  // of `nth-domain' (or `domain' and `range') relations.
  return (createRelation(name, arity, ((Module*)(safelyGetModule(moduleName, environment))), environment));
}

LogicObject* createFunction(char* name, int arity, Module* module, Object* environment) {
  // Create a function named `name' with arity `arity'  in the designated 
  // `module'.  Domain and range information can be added via assertions of
  // `nth-domain' (or `domain' and `range') relations.
  if (!(arity > 0)) {
    { OutputStringStream* stream000 = newOutputStringStream();

      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
        *(stream000->nativeStream) << "PARSING ERROR: " << "Functions must have arity of at least 1" << "." << std::endl;
        helpSignalPropositionError(stream000, KWD_PLI_ERROR);
      }
      throw *newParsingError(stream000->theStringReader());
    }
  }
  { Cons* args = NIL;

    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          { int i = NULL_INTEGER;
            int iter000 = 0;
            int upperBound000 = arity - 1;
            Cons* collect000 = NULL;

            while (iter000 <= upperBound000) {
              i = iter000;
              iter000 = iter000 + 1;
              if (!((boolean)(collect000))) {
                {
                  collect000 = cons(yieldSystemDefinedParameterName(i, oMODULEo.get()), NIL);
                  if (args == NIL) {
                    args = collect000;
                  }
                  else {
                    addConsToEndOfConsList(args, collect000);
                  }
                }
              }
              else {
                {
                  collect000->rest = cons(yieldSystemDefinedParameterName(i, oMODULEo.get()), NIL);
                  collect000 = collect000->rest;
                }
              }
            }
          }
          return (callDeffunction(cons(internSymbol(name), cons(args, NIL))));
        }
      }
    }
  }
}

LogicObject* sCreateFunction(char* name, int arity, char* moduleName, Object* environment) {
  // Create a function named `name' with arity `arity' in the designated 
  // module.  Domain and range information can be added via assertions of
  // `domain', `nth-domain' and `range' relations.
  return (createFunction(name, arity, ((Module*)(safelyGetModule(moduleName, environment))), environment));
}

LogicObject* createEnumeratedList(Cons* members) {
  // Create a logical term that denotes a list containing `members'.
  // Useful for passing lists as arguments to parameterized queries.
  { List* self000 = newList();

    self000->theConsList = members;
    { Skolem* value000 = createLogicalList(self000);

      return (value000);
    }
  }
}

LogicObject* createEnumeratedSet(Cons* members) {
  // Create a logical term that denotes the enumerated set containing `members'.
  { List* self000 = newList();

    self000->theConsList = members;
    { Skolem* value000 = logic::createEnumeratedSet(self000);

      return (value000);
    }
  }
}

void destroyObject(LogicObject* object) {
  // Delete the object `object', retracting all facts attached to it.
  destroyInstance(object);
}

void sDestroyObject(char* objectName, char* moduleName, Object* environment) {
  // Delete the object named `object-name', retracting all facts
  // attached to it.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* object = safelyGetObject(objectName, ((Module*)(module)), environment);

    if (((boolean)(object))) {
      destroyObject(((LogicObject*)(object)));
    }
  }
}

Proposition* assertUnaryProposition(LogicObject* relation, Object* arg, Module* module, Object* environment) {
  // Assert that the proposition (`relation' `arg') is TRUE in `module'.  Return the asserted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        if (classP(relation)) {
          return (assertIsaProposition(arg, relation->surrogateValueInverse));
        }
        else {
          return (assertProperty(((LogicObject*)(arg)), relation->surrogateValueInverse));
        }
      }
    }
  }
}

Proposition* assertBinaryProposition(LogicObject* relation, Object* arg, Object* value, Module* module, Object* environment) {
  // Assert that the proposition (`relation' `arg' `value') is TRUE
  // in `module'.  Return the asserted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (assertBinaryValue(relation->surrogateValueInverse, arg, value));
      }
    }
  }
}

Proposition* assertNaryProposition(Object* relationAndArguments, Module* module, Object* environment) {
  // Assert that the proposition represented by the list `arguments' satisfies
  // the relation `relation'.
  { Cons* list = sequenceToConsList(relationAndArguments);
    NamedDescription* relation = ((NamedDescription*)(list->value));
    Surrogate* relationsurrogate = relation->surrogateValueInverse;
    Cons* arguments = list->rest;

    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (assertTuple(relationsurrogate, arguments));
        }
      }
    }
  }
}

Proposition* retractUnaryProposition(LogicObject* relation, Object* arg, Module* module, Object* environment) {
  // Retract that the proposition (`relation' `arg') is TRUE in `module'.  Return the asserted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        if (classP(relation)) {
          return (retractIsaProposition(arg, relation->surrogateValueInverse));
        }
        else {
          return (retractProperty(((LogicObject*)(arg)), relation->surrogateValueInverse));
        }
      }
    }
  }
}

Proposition* retractBinaryProposition(LogicObject* relation, Object* arg, Object* value, Module* module, Object* environment) {
  // Retract that the proposition (`relation' `arg' `value') is TRUE
  // in `module'.  Return the asserted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (retractBinaryValue(relation->surrogateValueInverse, arg, value));
      }
    }
  }
}

Proposition* retractNaryProposition(Object* relationAndArguments, Module* module, Object* environment) {
  // Retract the proposition that `arguments' satisfies
  // the relation `relation'.
  { Cons* list = sequenceToConsList(relationAndArguments);
    NamedDescription* relation = ((NamedDescription*)(list->value));
    Surrogate* relationsurrogate = relation->surrogateValueInverse;
    Cons* arguments = list->rest;

    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (updateTuple(relationsurrogate, arguments, KWD_PLI_RETRACT_TRUE));
        }
      }
    }
  }
}

Proposition* assertProposition(Proposition* proposition, Module* module, Object* environment) {
  // Assert that the proposition `proposition' is true in `module'.
  // Return the asserted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        helpUpdateTopLevelProposition(proposition, KWD_PLI_ASSERT_TRUE);
        return (proposition);
      }
    }
  }
}

PlIterator* sAssertProposition(char* sentence, char* moduleName, Object* environment) {
  // Assert that the logical sentence `sentence' is true in the module
  // named `module-name'. Return an iterator of the propositions resulting
  // from sentence.
  { Context* module = safelyGetModule(moduleName, environment);
    PlIterator* propositions = NULL;
    PlIterator* returnValue = NULL;

    { Module* mdl000 = ((Module*)(module));
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          propositions = sConceive(sentence, moduleName, environment);
          returnValue = consToPlIterator(propositions->cursor);
          { Proposition* proposition = NULL;
            PlIterator* iter000 = propositions;

            while (iter000->nextP()) {
              proposition = ((Proposition*)(iter000->value));
              helpUpdateTopLevelProposition(proposition, KWD_PLI_ASSERT_TRUE);
            }
          }
          return (returnValue);
        }
      }
    }
  }
}

Proposition* retractProposition(Proposition* proposition, Module* module, Object* environment) {
  // Retract the truth of the proposition `proposition' in `module'.
  // Return the retracted proposition.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        updatePropositionTruthValue(proposition, KWD_PLI_RETRACT_TRUE);
        return (proposition);
      }
    }
  }
}

PlIterator* sRetractProposition(char* sentence, char* moduleName, Object* environment) {
  // Retract the truth of the logical sentence `sentence' in the module named
  // `module-name'.  Return an iterator of the retracted propositions resulting
  // from sentence.
  { Context* module = safelyGetModule(moduleName, environment);
    PlIterator* propositions = NULL;
    PlIterator* returnValue = NULL;

    { Module* mdl000 = ((Module*)(module));
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          propositions = sConceive(sentence, moduleName, environment);
          returnValue = consToPlIterator(propositions->cursor);
          { Proposition* proposition = NULL;
            PlIterator* iter000 = propositions;

            while (iter000->nextP()) {
              proposition = ((Proposition*)(iter000->value));
              updatePropositionTruthValue(proposition, KWD_PLI_RETRACT_TRUE);
            }
          }
          return (returnValue);
        }
      }
    }
  }
}

PlIterator* conceive(Object* sentence, Module* module, Object* environment) {
  // Create one or more proposition objects from the sentence `sentence'
  // in the  module `module'.  Return an iterator of the propositions.
  // If any of the new propositions has the same structure as an already existing
  // proposition, an automatic check for duplicates will return the pre-existing
  // proposition.  Multiple propositions may be returned for a single sentence
  // because of normalization of equivalences, conjunctions, etc.
  // 
  // Signals a `Proposition-Error' if PowerLoom could not conceive `sentence'.
  if (!((boolean)(sentence))) {
    return (NULL);
  }
  else {
    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          { Object* propositions = conceiveFormula(sentence);

            if (!((boolean)(propositions))) {
              { OutputStringStream* stream000 = newOutputStringStream();

                { 
                  BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                  *(stream000->nativeStream) << "ERROR: " << "Failed to conceive " << "`" << sentence << "'" << "." << std::endl;
                  helpSignalPropositionError(stream000, KWD_PLI_ERROR);
                }
                throw *newPropositionError(stream000->theStringReader());
              }
            }
            { Surrogate* testValue000 = safePrimaryType(propositions);

              if (subtypeOfP(testValue000, SGT_PLI_LOGIC_PROPOSITION)) {
                { Object* propositions000 = propositions;
                  Proposition* propositions = ((Proposition*)(propositions000));

                  return (consToPlIterator(cons(propositions, NIL)));
                }
              }
              else if (testValue000 == SGT_PLI_STELLA_CONS) {
                { Object* propositions001 = propositions;
                  Cons* propositions = ((Cons*)(propositions001));

                  return (consToPlIterator(propositions));
                }
              }
              else {
                { OutputStringStream* stream001 = newOutputStringStream();

                  { 
                    BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                    *(stream001->nativeStream) << "ERROR: " << "Formula is not a sentence: " << "`" << sentence << "'" << "." << std::endl;
                    helpSignalPropositionError(stream001, KWD_PLI_ERROR);
                  }
                  throw *newPropositionError(stream001->theStringReader());
                }
              }
            }
          }
        }
      }
    }
  }
}

PlIterator* sConceive(char* sentence, char* moduleName, Object* environment) {
  // Create one or more proposition objects from the sentence `sentence'
  // in the  module named `module-name'.  Return an iterator of the propositions.
  // If any of the new propositions has the same structure as an already existing
  // proposition, an automatic check for duplicates will return the pre-existing
  // proposition.  Multiple propositions may be returned for a single sentence
  // because of normalization of equivalences, conjunctions, etc.
  // 
  // Signals a `Proposition-Error' if PowerLoom could not conceive `sentence'.
  { Context* module = safelyGetModule(moduleName, environment);

    { Module* mdl000 = ((Module*)(module));
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (conceive(readSExpressionFromString(sentence), ((Module*)(module)), environment));
        }
      }
    }
  }
}

PlIterator* getRules(LogicObject* relation, Module* module, Object* environment) {
  // Return rules attached to the concept/relation `relation'
  // in either antecedent or consequent position.
  if (!((boolean)(relation))) {
    return (EMPTY_PL_ITERATOR);
  }
  else {
    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (consToPlIterator(callGetRules(relation)));
        }
      }
    }
  }
}

PlIterator* sGetRules(char* relationName, char* moduleName, Object* environment) {
  // Return rules attached to the concept/relation named
  // `relation-name' found in the module named `module-name'.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);

    return (getRules(((LogicObject*)(relation)), ((Module*)(module)), environment));
  }
}

void sPrintRules(char* name, OutputStream* stream, char* moduleName, Object* environment) {
  // Print rules attached to the concept/relation named `name'.
  if (!((boolean)(stream))) {
    stream = STANDARD_OUTPUT;
  }
  { Proposition* rule = NULL;
    PlIterator* iter000 = sGetRules(name, moduleName, environment);

    while (iter000->nextP()) {
      rule = ((Proposition*)(iter000->value));
      printLogicalForm(rule, stream);
      *(stream->nativeStream) << std::endl << std::endl;
    }
  }
}

void runForwardRules(Object* module, boolean forceP) {
  // Run forward inference rules in module `module'.
  // If `module' is NULL, the
  // current module will be used.  If forward inferencing is already up-to-date
  // in the designated module, no additional inferencing will occur, unless `force'
  // is set to TRUE, in which case all forward rules are run or rerun.
  // 
  // Calling `run-forward-rules' temporarily puts the module into a mode where
  // future assertional (monotonic) updates will trigger additional forward
  // inference.  Once a non-monotonic update is performed, i.e., a retraction
  // or clipping of relation value, all cached forward inferences will be discarded
  // and forward inferencing will be disabled until this function is
  // called again.
  if (!((boolean)(module))) {
    module = oMODULEo.get();
  }
  if (((boolean)(module))) {
    callRunForwardRules(((Module*)(module)), forceP);
  }
}

int getArity(LogicObject* relation) {
  // Return the arity of the relation `relation'.
  if (subtypeOfP(safePrimaryType(relation), SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
    { LogicObject* relation000 = relation;
      NamedDescription* relation = ((NamedDescription*)(relation000));

      return (relation->arity());
    }
  }
  else {
    return (0);
  }
}

int sGetArity(char* relationName, char* moduleName, Object* environment) {
  // Return the arity of the relation named `relation-name'.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);

    if (((boolean)(relation))) {
      return (getArity(((LogicObject*)(relation))));
    }
    else {
      return (NULL_INTEGER);
    }
  }
}

LogicObject* getDomain(LogicObject* relation) {
  // Return the type (a concept) for the first argument to the binary
  // relation `relation'.
  if (subtypeOfP(safePrimaryType(relation), SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
    { LogicObject* relation000 = relation;
      NamedDescription* relation = ((NamedDescription*)(relation000));

      return (getNthDomain(relation, 0));
    }
  }
  else {
    return (NULL);
  }
}

LogicObject* sGetDomain(char* relationName, char* moduleName, Object* environment) {
  // Return the type (concept) for the first argument to the binary
  // relation `relation-name'.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);

    if (((boolean)(relation))) {
      return (getDomain(((LogicObject*)(relation))));
    }
    else {
      return (NULL);
    }
  }
}

LogicObject* getRange(LogicObject* relation) {
  // Return the type (a concept) for fillers of the binary relation
  // `relation'.
  if (subtypeOfP(safePrimaryType(relation), SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
    { LogicObject* relation000 = relation;
      NamedDescription* relation = ((NamedDescription*)(relation000));

      return (getNthDomain(relation, 1));
    }
  }
  else {
    return (NULL);
  }
}

LogicObject* sGetRange(char* relationName, char* moduleName, Object* environment) {
  // Return the type (a concept) for fillers of the binary relation
  // `relation-name'.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);

    if (((boolean)(relation))) {
      return (getRange(((LogicObject*)(relation))));
    }
    else {
      return (NULL);
    }
  }
}

LogicObject* getNthDomain(LogicObject* relation, int n) {
  // Return the type (a concept) for the the nth argument of the
  // relation `relation'.  Counting starts at zero.
  if (classP(relation)) {
    return (((n == 0) ? relation : NULL));
  }
  else {
    if (subtypeOfP(safePrimaryType(relation), SGT_PLI_LOGIC_NAMED_DESCRIPTION)) {
      { LogicObject* relation000 = relation;
        NamedDescription* relation = ((NamedDescription*)(relation000));

        if ((n >= 0) &&
            (n < relation->ioVariableTypes->length())) {
          { Object* type = ((Surrogate*)(relation->ioVariableTypes->nth(n)))->surrogateValue;

            if (!((boolean)(type))) {
              return (NULL);
            }
            { Surrogate* testValue000 = safePrimaryType(type);

              if (subtypeOfClassP(testValue000)) {
                { Object* type000 = type;
                  Class* type = ((Class*)(type000));

                  return (((NamedDescription*)(dynamicSlotValue(type->dynamicSlots, SYM_PLI_LOGIC_DESCRIPTION, NULL))));
                }
              }
              else if (subtypeOfP(testValue000, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
                { Object* type001 = type;
                  LogicObject* type = ((LogicObject*)(type001));

                  return (type);
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
        }
        else {
          return (NULL);
        }
      }
    }
    else {
      return (NULL);
    }
  }
}

LogicObject* sGetNthDomain(char* relationName, int n, char* moduleName, Object* environment) {
  // Return the type (a concept) for the nth argument of the relation
  // named `relation-name'.  Counting starts at zero.
  { Context* module = safelyGetModule(moduleName, environment);
    Object* relation = safelyGetRelation(relationName, ((Module*)(module)), environment);

    if (((boolean)(relation))) {
      return (getNthDomain(((LogicObject*)(relation)), n));
    }
    else {
      return (NULL);
    }
  }
}

void load(char* filename) {
  // Read logic commands from the file named `filename' and evaluate them.
  // The file should begin with an `in-module' declaration that specifies
  // the module within which all remaining commands are to be evaluated
  // The remaining commands are evaluated one-by-one, applying the function
  // `evaluate' to each of them.
  logic::load(filename);
}

void saveModule(Module* module, char* filename, char* ifexists, Object* environment) {
  // Save the contents of the module `mod' into a file named `filename'.
  // If a file named `filename' already exists, then the action taken depends on the
  // value of `ifexists'.  Possible values are "ASK", "REPLACE", "WARN" and "ERROR":
  // 
  //   REPLACE => Means overwrite without warning.
  //   WARN    => Means overwrite with a warning.
  //   ERROR   => Means don't overwrite, signal an error instead.
  //   ASK     => Ask the user whether to overwrite or not.  If not overwritten, an
  //              exception is thrown.
  { boolean existsP = probeFileP(filename);

    if ((!existsP) ||
        stringEqualP(ifexists, "REPLACE")) {
    }
    else if (stringEqualP(ifexists, "ASK")) {
      if (!(yesOrNoP(stringConcatenate("File `", filename, 1, "' already exists.  Overwrite it? (yes or no) ")))) {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "File " << "`" << filename << "'" << " already exists";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    else if (stringEqualP(ifexists, "WARN")) {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "File " << "`" << filename << "'" << " already exists, overwriting." << std::endl;
    }
    else if (stringEqualP(ifexists, "ERROR")) {
      { OutputStringStream* stream001 = newOutputStringStream();

        *(stream001->nativeStream) << "File " << "`" << filename << "'" << " already exists.";
        throw *newStellaException(stream001->theStringReader());
      }
    }
    else {
      { OutputStringStream* stream002 = newOutputStringStream();

        *(stream002->nativeStream) << "Unrecognized ifexists option " << "`" << ifexists << "'";
        throw *newStellaException(stream002->theStringReader());
      }
    }
    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          { OutputFileStream* stream = NULL;

            try {
              stream = newOutputFileStream(filename);
              doSaveModule(oMODULEo.get(), stream);
            }
catch (...) {
              if (((boolean)(stream))) {
                stream->free();
              }
              throw;
            }
            if (((boolean)(stream))) {
              stream->free();
            }
          }
        }
      }
    }
  }
}

void sSaveModule(char* moduleName, char* filename, char* ifexists, Object* environment) {
  // Save the contents of the module `module-name' into a file named `filename'.
  // If a file named `filename' already exists, then the action taken depends on the
  // value of `ifexists'.  Possible values are "ASK", "REPLACE", "WARN" and "ERROR":
  // 
  //   REPLACE => Means overwrite without warning.
  //   WARN    => Means overwrite with a warning.
  //   ERROR   => Means don't overwrite, signal an error instead.
  //   ASK     => Ask the user whether to overwrite or not.  If not overwritten, an
  //              exception is thrown.
  saveModule(((Module*)(safelyGetModule(moduleName, environment))), filename, ifexists, environment);
}

LogicObject* getPredicate(Proposition* prop) {
  // Return the concept or relation predicate for
  // the proposition `prop'.
  { LogicObject* relation = getDescription(((Surrogate*)(prop->operatoR)));

    if (!((boolean)(relation))) {
      relation = ((LogicObject*)(((Surrogate*)(prop->operatoR))->surrogateValue));
    }
    return (relation);
  }
}

int getColumnCount(Object* obj) {
  // Return the number of columns in `obj', which must
  // be of type proposition, cons, vector or PL-iterator.  For a proposition,
  // the number includes both the predidate and arguments. For the PL-iterator
  // case,the number of columns is for the current value of the iterator.
  if (!((boolean)(obj))) {
    return (0);
  }
  { Surrogate* testValue000 = safePrimaryType(obj);

    if (subtypeOfP(testValue000, SGT_PLI_LOGIC_PROPOSITION)) {
      { Object* obj000 = obj;
        Proposition* obj = ((Proposition*)(obj000));

        return (obj->arguments->length() + 1);
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_PLI_PL_ITERATOR)) {
      { Object* obj001 = obj;
        PlIterator* obj = ((PlIterator*)(obj001));

        return (getColumnCount(obj->value));
      }
    }
    else if (testValue000 == SGT_PLI_STELLA_CONS) {
      { Object* obj002 = obj;
        Cons* obj = ((Cons*)(obj002));

        return (obj->length());
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_VECTOR)) {
      { Object* obj003 = obj;
        Vector* obj = ((Vector*)(obj003));

        return (obj->length());
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

Object* getNthValue(Object* sequence, int n) {
  // Return the value in the `nth' column of `sequence'.
  // Counting starts at zero.  `sequence' must be of type proposition, cons,
  // vector or PL-iterator.  A zero column number returns a proposition's 
  // relational predicate.  For the PL-iterator case, the number of columns
  // is for the current value of the iterator.
  if ((n >= getColumnCount(sequence)) ||
      (n < 0)) {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "Column index " << "`" << n << "'" << " is out of range for " << "`" << sequence << "'";
      throw *newLogicException(stream000->theStringReader());
    }
  }
  { Surrogate* testValue000 = safePrimaryType(sequence);

    if (subtypeOfP(testValue000, SGT_PLI_LOGIC_PROPOSITION)) {
      { Object* sequence000 = sequence;
        Proposition* sequence = ((Proposition*)(sequence000));

        if (n == 0) {
          return (getPredicate(sequence));
        }
        else {
          return ((sequence->arguments->theArray)[(n - 1)]);
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_PLI_PL_ITERATOR)) {
      { Object* sequence001 = sequence;
        PlIterator* sequence = ((PlIterator*)(sequence001));

        return (getNthValue(sequence->value, n));
      }
    }
    else if (testValue000 == SGT_PLI_STELLA_CONS) {
      { Object* sequence002 = sequence;
        Cons* sequence = ((Cons*)(sequence002));

        return (sequence->nth(n));
      }
    }
    else if (subtypeOfP(testValue000, SGT_PLI_STELLA_VECTOR)) {
      { Object* sequence003 = sequence;
        Vector* sequence = ((Vector*)(sequence003));

        return ((sequence->theArray)[n]);
      }
    }
    else {
      { OutputStringStream* stream001 = newOutputStringStream();

        *(stream001->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream001->theStringReader());
      }
    }
  }
}

char* getNthString(Object* sequence, int n) {
  // Return a string representation of the value in the `nth' column of
  // `sequence'. Counting starts at zero.  `sequence' must be of type
  // proposition, cons, vector or PL-iterator.  A zero column number returns
  // a proposition's relational predicate.  For the PL-iterator case, the
  // the current value pointed to by the iterator is used.  This will always
  // succeed, even if the `nth' value is not a string object.  In that case, a
  // string reprensentation will be returned.
  return (objectToString(getNthValue(sequence, n)));
}

int getNthInteger(Object* sequence, int n) {
  // Return an integer representation of the value in the `nth' column of
  // `sequence'. Counting starts at zero.  `sequence' must be of type
  // proposition, cons, vector or PL-iterator.  A zero column number returns
  // a proposition's relational predicate.  For the PL-iterator case, the
  // the current value pointed to by the iterator is used.  If this is not
  // an integer value, then NULL-INTEGER will be returned.
  return (objectToInteger(getNthValue(sequence, n)));
}

double getNthFloat(Object* sequence, int n) {
  // Return the floating point value in the `nth' column of
  // `sequence'. Counting starts at zero.  `sequence' must be of type
  // proposition, cons, vector or PL-iterator.  A zero column number returns
  // a proposition's relational predicate.  For the PL-iterator case, the
  // the current value pointed to by the iterator is used.  If this is not
  // a floating point value, then NULL-FLOAT will be returned.
  return (objectToFloat(getNthValue(sequence, n)));
}

LogicObject* getNthLogicObject(Object* sequence, int n) {
  // Return a logic object representation of the value in the `nth' column
  // of `sequence'.  Counting starts at zero.  `sequence' must be of type
  // proposition, cons, vector or PL-iterator.  A zero column number returns
  // a proposition's relational predicate.  For the PL-iterator case, the
  // the current value pointed to by the iterator is used.  A zero column number
  // returns the proposition's relational predicate.
  { Object* value = getNthValue(sequence, n);

    if (isaP(value, SGT_PLI_LOGIC_LOGIC_OBJECT)) {
      return (((LogicObject*)(value)));
    }
    else {
      return (NULL);
    }
  }
}

Cons* getEnumeratedCollectionMembers(Object* collection) {
  // Returns the members of an enumerated collection.  This works on all types
  // of collection, i.e., sets and lists
  return (assertedCollectionMembers(collection, TRUE)->theConsList);
}

Object* evaluate(Object* command, Module* module, Object* environment) {
  // Evaluate the command `command' within `module' and return
  // the result. Currently, only the evaluation of (possibly nested) commands and
  // global variables is supported.  Commands are simple to program in Common Lisp,
  // since they are built into the language, and relatively awkward in Java and C++.
  // Users of either of those languages are more likely to want to call `s-evaluate'.
  if (((boolean)(command))) {
    { Module* mdl000 = module;
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (stella::evaluate(command));
        }
      }
    }
  }
  return (NULL);
}

Object* sEvaluate(char* command, char* moduleName, Object* environment) {
  // Evaluate the command represented by the string `command' within `module' and
  // return the result.  Currently, only the evaluation of (possibly nested) commands and
  // global variables is supported.
  { Context* module = safelyGetModule(moduleName, environment);

    { Module* mdl000 = ((Module*)(module));
      Context* cxt000 = mdl000;

      if (!((boolean)(mdl000))) {
        mdl000 = oMODULEo.get();
        cxt000 = oCONTEXTo.get();
      }
      { 
        BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
        BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
        environment = environment;
        // Should be synchronized on process lock oPOWERLOOM_LOCKo
        {
          return (evaluate(readSExpressionFromString(command), ((Module*)(module)), environment));
        }
      }
    }
  }
}

boolean isLogicObject(Object* obj) {
  // Test whether `obj' is of type LOGIC-OBJECT
  return (isaP(obj, SGT_PLI_LOGIC_LOGIC_OBJECT));
}

boolean isInteger(Object* obj) {
  // Test whether `obj' is of type INTEGER
  return (isaP(obj, SGT_PLI_STELLA_INTEGER_WRAPPER));
}

boolean isFloat(Object* obj) {
  // Test whether `obj' is of type FLOAT (double)
  return (isaP(obj, SGT_PLI_STELLA_FLOAT_WRAPPER));
}

boolean isNumber(Object* obj) {
  // Test whether `obj' is of type NUMBER.  This can
  // be either an integer or a floating point number.  One key characteristic
  // is that 'object-to-integer' and `object-to-float' will both work on it.
  return (isaP(obj, SGT_PLI_STELLA_NUMBER_WRAPPER));
}

boolean isString(Object* obj) {
  // Test whether `obj' is of type STRING
  return (isaP(obj, SGT_PLI_STELLA_STRING_WRAPPER));
}

boolean isEnumeratedCollection(Object* obj) {
  // Test whether `obj' is an enumerated collection.  This
  // subsumes both sets and lists.
  return (logicalCollectionP(obj));
}

boolean isEnumeratedSet(Object* obj) {
  // Test whether `obj' is an enumerated set.
  return (enumeratedSetP(obj));
}

boolean isEnumeratedList(Object* obj) {
  // Test whether `obj' is an enumerated list
  return (enumeratedListP(obj));
}

boolean isTrue(TruthValue* tv) {
  // Tests whether `tv' is a true truth value.  It can be true
  // either absolutely or by default.
  return ((tv == TRUE_TRUTH_VALUE) ||
      (tv == DEFAULT_TRUE_TRUTH_VALUE));
}

boolean isFalse(TruthValue* tv) {
  // Tests whether `tv' is a false truth value.  It can be false
  // either absolutely or by default.
  return ((tv == FALSE_TRUTH_VALUE) ||
      (tv == DEFAULT_FALSE_TRUTH_VALUE));
}

boolean isUnknown(TruthValue* tv) {
  // Tests whether `tv' is an unknown truth value.
  return ((tv == UNKNOWN_TRUTH_VALUE) ||
      (!((boolean)(tv))));
}

boolean isStrict(TruthValue* tv) {
  // Tests whether `tv' is a strict (non-default) truth value.
  return ((tv == TRUE_TRUTH_VALUE) ||
      (tv == FALSE_TRUTH_VALUE));
}

boolean isDefault(TruthValue* tv) {
  // Tests whether `tv' is a default truth value.
  return ((tv == DEFAULT_TRUE_TRUTH_VALUE) ||
      (tv == DEFAULT_FALSE_TRUTH_VALUE));
}

TruthValue* ask(Cons* query, Module* module, Object* environment) {
  // Returns a truth value for the `query' in `module' and `environment'.
  // The truth value represents the degree of belief in the answer.  See also the
  // helping functions `is-true', `is-false' , `is-unknown'.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        if (isaP(query->value, SGT_PLI_STELLA_SYMBOL)) {
          query = cons(query, NIL);
        }
        return (callAsk(query));
      }
    }
  }
}

TruthValue* sAsk(char* query, char* moduleName, Object* environment) {
  // Returns a truth value for the `query' in `module-name' and `environment'.
  // The truth value represents the degree of belief in the answer.  See also the
  // helping functions `is-true', `is-false' , `is-unknown'.
  { Cons* queryform = NIL;

    { Object* sexp = NULL;
      SExpressionIterator* iter000 = sExpressions(newInputStringStream(query));
      Cons* collect000 = NULL;

      while (iter000->nextP()) {
        sexp = iter000->value;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(sexp, NIL);
            if (queryform == NIL) {
              queryform = collect000;
            }
            else {
              addConsToEndOfConsList(queryform, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(sexp, NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    if (((!((boolean)(queryform->rest))) ||
        (queryform->rest == NIL)) &&
        (!isaP(((Cons*)(queryform->value))->value, SGT_PLI_STELLA_SYMBOL))) {
      queryform = ((Cons*)(queryform->value));
    }
    return (ask(queryform, ((Module*)(safelyGetModule(moduleName, environment))), environment));
  }
}

PlIterator* retrieve(Cons* query, Module* module, Object* environment) {
  // Returns an iterator for variables that satisfy `query' in `module-name'
  // and `environment'.  This uses the normal PowerLoom query syntax:
  // 
  //    `[n-values] output-variables query-form [options]'
  // 
  // The `output-variables' should either be a single variable name
  // -- preceded by the '?' character -- or a list of one or more such names.
  // If a single variable name is provided, then each element in the returned
  // iterator will be a value binding.  If a list (even of one variable name)
  // is provided, then each element in the returned iterator can be accessed
  // using the `get-nth-'... functions.
  { Module* mdl000 = module;
    Context* cxt000 = mdl000;

    if (!((boolean)(mdl000))) {
      mdl000 = oMODULEo.get();
      cxt000 = oCONTEXTo.get();
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, mdl000);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, cxt000);
      environment = environment;
      // Should be synchronized on process lock oPOWERLOOM_LOCKo
      {
        return (consToPlIterator(callRetrieve(query)->consifyCurrentSolutions()));
      }
    }
  }
}

PlIterator* sRetrieve(char* query, char* moduleName, Object* environment) {
  // Returns an iterator for variables that satisfy `query' in `module-name'
  // and `environment'.  This uses the normal PowerLoom query syntax:
  // 
  //    `"[n-values] output-variables query-form [options]"'
  // 
  // The `output-variables' should either be a single variable name
  // -- preceded by the '?' character -- or a list of one or more such names.
  // If a single variable name is provided, then each element in the returned
  // iterator will be a value binding.  If a list (even of one variable name)
  // is provided, then each element in the returned iterator can be accessed
  // using the `get-nth-'... functions.
  { Cons* queryform = NIL;

    { Object* sexp = NULL;
      SExpressionIterator* iter000 = sExpressions(newInputStringStream(query));
      Cons* collect000 = NULL;

      while (iter000->nextP()) {
        sexp = iter000->value;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(sexp, NIL);
            if (queryform == NIL) {
              queryform = collect000;
            }
            else {
              addConsToEndOfConsList(queryform, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(sexp, NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    if ((!((boolean)(queryform->rest))) ||
        (queryform->rest == NIL)) {
      queryform = ((Cons*)(queryform->value));
    }
    return (retrieve(queryform, ((Module*)(safelyGetModule(moduleName, environment))), environment));
  }
}

int main() {
  // Main PowerLoom entry point for your code in C++ and Java.
  std::cout << "Initializing STELLA..." << std::endl;
  startupStellaSystem();
  std::cout << "Initializing PowerLoom..." << std::endl;
  startupLogicSystem();
  powerloom();
  return (1);
}

void helpStartupPli1() {
  {
    SGT_PLI_PLI_ENVIRONMENT = ((Surrogate*)(internRigidSymbolWrtModule("ENVIRONMENT", NULL, 1)));
    SYM_PLI_LOGIC_LEVEL = ((Symbol*)(internRigidSymbolWrtModule("LEVEL", getStellaModule("/LOGIC", TRUE), 0)));
    SGT_PLI_PLI_PL_ITERATOR = ((Surrogate*)(internRigidSymbolWrtModule("PL-ITERATOR", NULL, 1)));
    SYM_PLI_STELLA_CURSOR = ((Symbol*)(internRigidSymbolWrtModule("CURSOR", getStellaModule("/STELLA", TRUE), 0)));
    SGT_PLI_STELLA_CONS = ((Surrogate*)(internRigidSymbolWrtModule("CONS", getStellaModule("/STELLA", TRUE), 1)));
    SGT_PLI_STELLA_LIST = ((Surrogate*)(internRigidSymbolWrtModule("LIST", getStellaModule("/STELLA", TRUE), 1)));
    SGT_PLI_STELLA_VECTOR = ((Surrogate*)(internRigidSymbolWrtModule("VECTOR", getStellaModule("/STELLA", TRUE), 1)));
    SYM_PLI_STELLA_NULL = ((Symbol*)(internRigidSymbolWrtModule("NULL", getStellaModule("/STELLA", TRUE), 0)));
    SGT_PLI_LOGIC_SKOLEM = ((Surrogate*)(internRigidSymbolWrtModule("SKOLEM", getStellaModule("/LOGIC", TRUE), 1)));
    SGT_PLI_LOGIC_LOGIC_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("LOGIC-OBJECT", getStellaModule("/LOGIC", TRUE), 1)));
    SGT_PLI_STELLA_GENERALIZED_SYMBOL = ((Surrogate*)(internRigidSymbolWrtModule("GENERALIZED-SYMBOL", getStellaModule("/STELLA", TRUE), 1)));
    SGT_PLI_STELLA_CONTEXT = ((Surrogate*)(internRigidSymbolWrtModule("CONTEXT", getStellaModule("/STELLA", TRUE), 1)));
    SGT_PLI_LOGIC_COMPUTED_PROCEDURE = ((Surrogate*)(internRigidSymbolWrtModule("COMPUTED-PROCEDURE", getStellaModule("/LOGIC", TRUE), 1)));
    SGT_PLI_STELLA_LITERAL_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("LITERAL-WRAPPER", getStellaModule("/STELLA", TRUE), 1)));
    SGT_PLI_LOGIC_NAMED_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("NAMED-DESCRIPTION", getStellaModule("/LOGIC", TRUE), 1)));
    SYM_PLI_PLI_pR = ((Symbol*)(internRigidSymbolWrtModule("?R", NULL, 0)));
    SYM_PLI_PLI_pI = ((Symbol*)(internRigidSymbolWrtModule("?I", NULL, 0)));
    SYM_PLI_PLI_pV = ((Symbol*)(internRigidSymbolWrtModule("?V", NULL, 0)));
    SYM_PLI_PLI_QUERY_099 = ((Symbol*)(internRigidSymbolWrtModule("QUERY-099", NULL, 0)));
    KWD_PLI_ISA = ((Keyword*)(internRigidSymbolWrtModule("ISA", NULL, 2)));
    SGT_PLI_STELLA_MODULE = ((Surrogate*)(internRigidSymbolWrtModule("MODULE", getStellaModule("/STELLA", TRUE), 1)));
    KWD_PLI_SUBSET_OF = ((Keyword*)(internRigidSymbolWrtModule("SUBSET-OF", NULL, 2)));
    KWD_PLI_ERROR = ((Keyword*)(internRigidSymbolWrtModule("ERROR", NULL, 2)));
    KWD_PLI_RETRACT_TRUE = ((Keyword*)(internRigidSymbolWrtModule("RETRACT-TRUE", NULL, 2)));
    KWD_PLI_ASSERT_TRUE = ((Keyword*)(internRigidSymbolWrtModule("ASSERT-TRUE", NULL, 2)));
    SGT_PLI_LOGIC_PROPOSITION = ((Surrogate*)(internRigidSymbolWrtModule("PROPOSITION", getStellaModule("/LOGIC", TRUE), 1)));
    SYM_PLI_LOGIC_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("DESCRIPTION", getStellaModule("/LOGIC", TRUE), 0)));
    SGT_PLI_STELLA_INTEGER_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("INTEGER-WRAPPER", getStellaModule("/STELLA", TRUE), 1)));
    SGT_PLI_STELLA_FLOAT_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("FLOAT-WRAPPER", getStellaModule("/STELLA", TRUE), 1)));
    SGT_PLI_STELLA_NUMBER_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("NUMBER-WRAPPER", getStellaModule("/STELLA", TRUE), 1)));
    SGT_PLI_STELLA_STRING_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("STRING-WRAPPER", getStellaModule("/STELLA", TRUE), 1)));
    SGT_PLI_STELLA_SYMBOL = ((Surrogate*)(internRigidSymbolWrtModule("SYMBOL", getStellaModule("/STELLA", TRUE), 1)));
    SYM_PLI_PLI_STARTUP_PLI = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-PLI", NULL, 0)));
    SYM_PLI_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", TRUE), 0)));
  }
}

void helpStartupPli2() {
  {
    defineFunctionObject("INITIALIZE", "(DEFUN INITIALIZE () :DOCUMENTATION \"Initialize the PowerLoom logic system.  This needs to\nbe called by all applications before using PowerLoom.\" :PUBLIC? TRUE)", ((cpp_function_code)(&initialize)), NULL);
    defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF PL-ITERATOR)) :DOCUMENTATION \"Advance the PL-Iterator `self' and return `true' if more\nelements are available, `false' otherwise.\")", ((cpp_method_code)(&PlIterator::nextP)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (EMPTY? BOOLEAN) ((SELF PL-ITERATOR)) :DOCUMENTATION \"Return TRUE if the iterator `self' has no more elements.\" :PUBLIC? TRUE)", ((cpp_method_code)(&PlIterator::emptyP)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (LENGTH INTEGER) ((SELF PL-ITERATOR)) :DOCUMENTATION \"Number of items in `self'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&PlIterator::length)), ((cpp_method_code)(NULL)));
    defineFunctionObject("CONS-TO-PL-ITERATOR", "(DEFUN (CONS-TO-PL-ITERATOR PL-ITERATOR) ((SELF CONS)) :DOCUMENTATION \"Convert a Stella cons list into an API iterator.\")", ((cpp_function_code)(&consToPlIterator)), NULL);
    defineFunctionObject("LIST-TO-PL-ITERATOR", "(DEFUN (LIST-TO-PL-ITERATOR PL-ITERATOR) ((SELF LIST)) :DOCUMENTATION \"Convert a Stella list into an API iterator.\")", ((cpp_function_code)(&listToPlIterator)), NULL);
    defineFunctionObject("ITERATOR-TO-PL-ITERATOR", "(DEFUN (ITERATOR-TO-PL-ITERATOR PL-ITERATOR) ((SELF ITERATOR)) :DOCUMENTATION \"Convert an arbitrary Stella iterator into an API iterator.\")", ((cpp_function_code)(&iteratorToPlIterator)), NULL);
    defineMethodObject("(DEFMETHOD (LISTIFY LIST) ((SELF PL-ITERATOR)))", ((cpp_method_code)(&PlIterator::listify)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (CONSIFY CONS) ((SELF PL-ITERATOR)))", ((cpp_method_code)(&PlIterator::consify)), ((cpp_method_code)(NULL)));
    defineFunctionObject("SAFELY-GET-OBJECT", "(DEFUN (SAFELY-GET-OBJECT OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT OBJECT)))", ((cpp_function_code)(&safelyGetObject)), NULL);
    defineFunctionObject("SAFELY-GET-CONCEPT", "(DEFUN (SAFELY-GET-CONCEPT OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT OBJECT)))", ((cpp_function_code)(&safelyGetConcept)), NULL);
    defineFunctionObject("SAFELY-GET-RELATION", "(DEFUN (SAFELY-GET-RELATION OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT OBJECT)))", ((cpp_function_code)(&safelyGetRelation)), NULL);
    defineFunctionObject("SAFELY-GET-MODULE", "(DEFUN (SAFELY-GET-MODULE CONTEXT) ((NAME STRING) (ENVIRONMENT OBJECT)))", ((cpp_function_code)(&safelyGetModule)), NULL);
    defineFunctionObject("SAFELY-GET-OBJECT-OR-NULL", "(DEFUN (SAFELY-GET-OBJECT-OR-NULL OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT OBJECT)))", ((cpp_function_code)(&safelyGetObjectOrNull)), NULL);
    defineFunctionObject("SEQUENCE-TO-CONS-LIST", "(DEFUN (SEQUENCE-TO-CONS-LIST CONS) ((SEQUENCE OBJECT)))", ((cpp_function_code)(&sequenceToConsList)), NULL);
    defineFunctionObject("EXPLODE-STRING-LIST", "(DEFUN (EXPLODE-STRING-LIST CONS) ((STRINGLIST STRING) (MODULE MODULE)))", ((cpp_function_code)(&explodeStringList)), NULL);
    defineFunctionObject("GET-OBJECT", "(DEFUN (GET-OBJECT OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Look for an object named `name' that is local to\nor visible from the module `module'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getObject)), NULL);
    defineFunctionObject("S-GET-OBJECT", "(DEFUN (S-GET-OBJECT OBJECT) ((NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Look for an object named `name' that is local to\nor visible from the module `module-name'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sGetObject)), NULL);
    defineFunctionObject("GET-CONCEPT", "(DEFUN (GET-CONCEPT LOGIC-OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return a class/concept named `name' that is local to\nor visible from the module `module'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getConcept)), NULL);
    defineFunctionObject("S-GET-CONCEPT", "(DEFUN (S-GET-CONCEPT LOGIC-OBJECT) ((NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return a class/concept named `name' that is local to\nor visible from the module `module-name'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sGetConcept)), NULL);
    defineFunctionObject("GET-RELATION", "(DEFUN (GET-RELATION LOGIC-OBJECT) ((NAME STRING) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return a concept or relation named `name' that is local to\nor visible from the module `module'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getRelation)), NULL);
    defineFunctionObject("S-GET-RELATION", "(DEFUN (S-GET-RELATION LOGIC-OBJECT) ((NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return a concept or relation named `name' that is local to\nor visible from the module `module-name'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sGetRelation)), NULL);
    defineFunctionObject("GET-NAME", "(DEFUN (GET-NAME STRING) ((OBJ OBJECT)) :DOCUMENTATION \"Return the name of `obj', if it has one.  Otherwise return `null'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getName)), NULL);
    defineFunctionObject("OBJECT-TO-STRING", "(DEFUN (OBJECT-TO-STRING STRING) ((SELF OBJECT)) :DOCUMENTATION \"Return a printed representation of the term `self' as a string.\" :PUBLIC? TRUE)", ((cpp_function_code)(&objectToString)), NULL);
    defineFunctionObject("OBJECT-TO-INTEGER", "(DEFUN (OBJECT-TO-INTEGER INTEGER) ((SELF OBJECT)) :DOCUMENTATION \"Coerce `self' to an integer, or throw a Stella Exception if the coersion is not feasible.\" :PUBLIC? TRUE)", ((cpp_function_code)(&objectToInteger)), NULL);
    defineFunctionObject("OBJECT-TO-FLOAT", "(DEFUN (OBJECT-TO-FLOAT FLOAT) ((SELF OBJECT)) :DOCUMENTATION \"Coerce `self' to a float, or throw a Stella Exception if the coersion is not feasible.\" :PUBLIC? TRUE)", ((cpp_function_code)(&objectToFloat)), NULL);
    defineFunctionObject("OBJECT-TO-PARSABLE-STRING", "(DEFUN (OBJECT-TO-PARSABLE-STRING STRING) ((SELF OBJECT)) :DOCUMENTATION \"Return a string representing a printed\nrepresentation of the object `self'.  Like `object-to-string', but puts\nescaped double quotes around strings.\" :PUBLIC? TRUE)", ((cpp_function_code)(&objectToParsableString)), NULL);
    defineFunctionObject("STRING-TO-OBJECT", "(DEFUN (STRING-TO-OBJECT OBJECT) ((STRING STRING) (TYPE LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Evaluate `string' with respect to `module' and `environment'\nand return the corresponding logical term.  `type' is a concept used to assist the\ncorrect interpretation of `string'.\n\nCurrently `type' only has an effect on the interpretation of literal types.\" :PUBLIC? TRUE)", ((cpp_function_code)(&stringToObject)), NULL);
    defineFunctionObject("HELP-GET-TRUE-EXTENSION-MEMBERS", "(DEFUN (HELP-GET-TRUE-EXTENSION-MEMBERS (CONS OF PROPOSITION)) ((RELATION NAMED-DESCRIPTION) (SPECIALIZE? BOOLEAN)) :PUBLIC? FALSE)", ((cpp_function_code)(&helpGetTrueExtensionMembers)), NULL);
    defineFunctionObject("HELP-GET-PROPOSITIONS", "(DEFUN (HELP-GET-PROPOSITIONS (CONS OF PROPOSITION)) ((RELATION LOGIC-OBJECT) (ARGUMENTS CONS) (LIMIT INTEGER) (MODULE MODULE) (ENVIRONMENT OBJECT)) :PUBLIC? FALSE)", ((cpp_function_code)(&helpGetPropositions)), NULL);
    defineFunctionObject("GET-PROPOSITION", "(DEFUN (GET-PROPOSITION PROPOSITION) ((RELATION-AND-ARGUMENTS OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return a proposition matching `relation-and-arguments' that\nhas been asserted (or inferred by forward chaining).  `relation-and-arguments'\nis a sequence containing objects and nulls.  The first argument must be the\nname of a relation.  A null value acts like a wild card.  If more than one \nproposition matches the input criteria, the selection among satisficing\npropositions is arbitrary.  This procedure is normally applied to single-valued\nrelations or functions.\")", ((cpp_function_code)(&getProposition)), NULL);
    defineFunctionObject("S-GET-PROPOSITION", "(DEFUN (S-GET-PROPOSITION PROPOSITION) ((RELATION-AND-ARGUMENTS STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return a proposition matching `relation-and-arguments' that\nhas been asserted (or inferred by forward chaining).  `relation-and-arguments'\nis a string that begins with a left parenthesis, followed by a relation name, \none or more argument identifiers, and terminated by a right parenthesis.  Each\nargument identifier can be the name of a logical constant, a literal\nreference (e.g., a number), the null identifier, or a variable (an identifier that begins\nwith a question mark). Each occurrence of a null or a variable acts like a wild card.\nIf more than one proposition matches the input criteria, the selection among\nsatisficing propositions is arbitrary.  This procedure is normally applied to\nsingle-valued relations or functions.\")", ((cpp_function_code)(&sGetProposition)), NULL);
    defineFunctionObject("GET-PROPOSITIONS", "(DEFUN (GET-PROPOSITIONS (PL-ITERATOR OF PROPOSITION)) ((RELATION-AND-ARGUMENTS OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return propositions matching `relation-and-arguments' that\nhave been asserted (or inferred by forward chaining).  `relation-and-arguments'\nis a sequence containing objects and nulls.  The first argument must be the\nname of a relation.  A null value acts like a wild card.\")", ((cpp_function_code)(&getPropositions)), NULL);
    defineFunctionObject("S-GET-PROPOSITIONS", "(DEFUN (S-GET-PROPOSITIONS (PL-ITERATOR OF PROPOSITION)) ((RELATION-AND-ARGUMENTS STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return propositions matching `relation-and-arguments' that\nhave been asserted (or inferred by forward chaining).  `relation-and-arguments'\nis a string that begins with a left parenthesis, followed by a relation name, \none or more argument identifiers, and terminated by a right parenthesis.  Each\nargument identifier can be the name of a logical constant, a literal \nreference (e.g., a number), the null identifier, or a variable (an identifier that begins\nwith a question mark). Each occurrence of a null or a variable acts like a wild card.\")", ((cpp_function_code)(&sGetPropositions)), NULL);
    defineFunctionObject("GET-BINARY-PROPOSITION", "(DEFUN (GET-BINARY-PROPOSITION PROPOSITION) ((RELATION LOGIC-OBJECT) (ARG1 OBJECT) (ARG2 OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return a proposition such that (`relation' `arg1' `arg2')\nis true.  The `relation' argument must be bound to a relation.  One or both\nof the `arg1' and `arg2' arguments may be set to NULL, which is interpreted\nas a wildcard. If more than one proposition matches the input criteria,\nthe selection is arbitrary.  This procedure is normally applied to single-valued\nrelations or functions.\")", ((cpp_function_code)(&getBinaryProposition)), NULL);
    defineFunctionObject("GET-BINARY-PROPOSITIONS", "(DEFUN (GET-BINARY-PROPOSITIONS (PL-ITERATOR OF PROPOSITION)) ((RELATION LOGIC-OBJECT) (ARG1 OBJECT) (ARG2 OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return propositions such that (`relation' `arg1' `arg2')\nis true.  The `relation' argument\nmust be bound to a relation.  One or both of the `arg1' and `arg2' arguments\nmay be set to NULL, which is interpreted as a wildcard.\")", ((cpp_function_code)(&getBinaryPropositions)), NULL);
    defineFunctionObject("GET-INFERRED-BINARY-PROPOSITION-VALUES", "(DEFUN (GET-INFERRED-BINARY-PROPOSITION-VALUES PL-ITERATOR) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return all values `v' such that (`relation' `arg' `v')\nhas been asserted or can be inferred.\")", ((cpp_function_code)(&getInferredBinaryPropositionValues)), NULL);
    defineFunctionObject("S-GET-INFERRED-BINARY-PROPOSITION-VALUES", "(DEFUN (S-GET-INFERRED-BINARY-PROPOSITION-VALUES PL-ITERATOR) ((RELATION-NAME STRING) (ARG-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return all values `v' such that (`relation-name' `arg-name' `v')\nhas been asserted or can be inferred.\")", ((cpp_function_code)(&sGetInferredBinaryPropositionValues)), NULL);
    defineFunctionObject("GET-PROPOSITIONS-OF", "(DEFUN (GET-PROPOSITIONS-OF (PL-ITERATOR OF PROPOSITION)) ((OBJECT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return all propositions that have `object' among their arguments,\nand that are TRUE in the scope of the module `module'.\")", ((cpp_function_code)(&getPropositionsOf)), NULL);
    defineFunctionObject("S-GET-PROPOSITIONS-OF", "(DEFUN (S-GET-PROPOSITIONS-OF (PL-ITERATOR OF PROPOSITION)) ((OBJECT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return all propositions that have the object named `object-name' among\ntheir arguments, and that are TRUE in the scope of the module `module'.\")", ((cpp_function_code)(&sGetPropositionsOf)), NULL);
    defineFunctionObject("GET-PROPOSITIONS-IN-MODULE", "(DEFUN (GET-PROPOSITIONS-IN-MODULE (PL-ITERATOR OF PROPOSITION)) ((MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return propositions that have been conceived in\nthe module `module'.\")", ((cpp_function_code)(&getPropositionsInModule)), NULL);
    defineFunctionObject("IS-TRUE-UNARY-PROPOSITION", "(DEFUN (IS-TRUE-UNARY-PROPOSITION BOOLEAN) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return TRUE if the proposition (`relation' `arg') has\nbeen asserted (or inferred by forward chaining).\")", ((cpp_function_code)(&isTrueUnaryProposition)), NULL);
    defineFunctionObject("IS-TRUE-BINARY-PROPOSITION", "(DEFUN (IS-TRUE-BINARY-PROPOSITION BOOLEAN) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (VALUE OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return TRUE if the proposition (`relation' `arg' `value') has\nbeen asserted (or inferred by forward chaining).\")", ((cpp_function_code)(&isTrueBinaryProposition)), NULL);
    defineFunctionObject("IS-TRUE-PROPOSITION1", "(DEFUN (IS-TRUE-PROPOSITION1 BOOLEAN) ((RELATION-AND-ARGUMENTS OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return TRUE if a proposition (`relation' `args') has\nbeen asserted (or inferred by forward chaining).\")", ((cpp_function_code)(&isTrueProposition1)), NULL);
    defineFunctionObject("IS-TRUE-PROPOSITION", "(DEFUN (IS-TRUE-PROPOSITION BOOLEAN) ((PROPOSITION PROPOSITION) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return TRUE if `proposition' is  TRUE in the module `module'.\")", ((cpp_function_code)(&isTrueProposition)), NULL);
    defineFunctionObject("S-IS-TRUE-PROPOSITION", "(DEFUN (S-IS-TRUE-PROPOSITION BOOLEAN) ((RELATION-AND-ARGUMENTS STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return TRUE if a proposition that prints as the string\n`relation-and-arguments' is true in the module named `module-name'.\")", ((cpp_function_code)(&sIsTrueProposition)), NULL);
    defineFunctionObject("IS-SUBRELATION", "(DEFUN (IS-SUBRELATION BOOLEAN) ((SUB LOGIC-OBJECT) (SUPER LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return TRUE if `sub' is a subconcept/subrelation of `super'.\")", ((cpp_function_code)(&isSubrelation)), NULL);
    defineFunctionObject("GET-PROPER-SUBRELATIONS", "(DEFUN (GET-PROPER-SUBRELATIONS (PL-ITERATOR OF LOGIC-OBJECT)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return relations that specialize `relation'.\nNon-reflexive.\")", ((cpp_function_code)(&getProperSubrelations)), NULL);
    defineFunctionObject("GET-DIRECT-SUBRELATIONS", "(DEFUN (GET-DIRECT-SUBRELATIONS (PL-ITERATOR OF LOGIC-OBJECT)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return relations that directly specialize `relation'.\nNon-reflexive.\")", ((cpp_function_code)(&getDirectSubrelations)), NULL);
    defineFunctionObject("GET-PROPER-SUPERRELATIONS", "(DEFUN (GET-PROPER-SUPERRELATIONS (PL-ITERATOR OF LOGIC-OBJECT)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return relations that generalize `relation'.\nNon-reflexive.\")", ((cpp_function_code)(&getProperSuperrelations)), NULL);
    defineFunctionObject("GET-DIRECT-SUPERRELATIONS", "(DEFUN (GET-DIRECT-SUPERRELATIONS (PL-ITERATOR OF LOGIC-OBJECT)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return relations that directly generalize `relation'.\nNon-reflexive.\")", ((cpp_function_code)(&getDirectSuperrelations)), NULL);
    defineFunctionObject("IS-A", "(DEFUN (IS-A BOOLEAN) ((OBJECT OBJECT) (CONCEPT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return TRUE if `object' is a member of the concept `concept'.\")", ((cpp_function_code)(&isA)), NULL);
    defineFunctionObject("GET-CONCEPT-INSTANCES", "(DEFUN (GET-CONCEPT-INSTANCES PL-ITERATOR) ((CONCEPT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return instances of the concept `concept'.\nInclude instances of subconcepts of `concept'.  Depending on `concept',\nthe return values could be (wrapped) literals.\")", ((cpp_function_code)(&getConceptInstances)), NULL);
    defineFunctionObject("S-GET-CONCEPT-INSTANCES", "(DEFUN (S-GET-CONCEPT-INSTANCES PL-ITERATOR) ((CONCEPT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return instances of concept `concept-name'.\nInclude instances of subconcepts of `concept-name'.  Depending on `concept-name',\nthe return values could be (wrapped) literals.\")", ((cpp_function_code)(&sGetConceptInstances)), NULL);
    defineFunctionObject("GET-DIRECT-CONCEPT-INSTANCES", "(DEFUN (GET-DIRECT-CONCEPT-INSTANCES PL-ITERATOR) ((CONCEPT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return instances of concept `concept'.\nExclude instances of subconcepts of `concept'.  Depending on `concept',\nthe return values could be (wrapped) literals.\")", ((cpp_function_code)(&getDirectConceptInstances)), NULL);
    defineFunctionObject("S-GET-DIRECT-CONCEPT-INSTANCES", "(DEFUN (S-GET-DIRECT-CONCEPT-INSTANCES PL-ITERATOR) ((CONCEPT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return instances of concept `concept-name'.\nExclude instances of subconcepts of `concept-name'.  Depending on `concept-name',\nthe return values could be (wrapped) literals.\")", ((cpp_function_code)(&sGetDirectConceptInstances)), NULL);
    defineFunctionObject("GET-CONCEPT-INSTANCES-MATCHING-VALUE", "(DEFUN (GET-CONCEPT-INSTANCES-MATCHING-VALUE PL-ITERATOR) ((CONCEPT LOGIC-OBJECT) (RELATION LOGIC-OBJECT) (VALUE OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return members of concept `concept' that\nhave an attribute matching `value' for the binary relation `relation', i.e.,\n`(relation <result> value)' holds.\")", ((cpp_function_code)(&getConceptInstancesMatchingValue)), NULL);
    defineFunctionObject("GET-CONCEPT-INSTANCE-MATCHING-VALUE", "(DEFUN (GET-CONCEPT-INSTANCE-MATCHING-VALUE OBJECT) ((CONCEPT LOGIC-OBJECT) (RELATION LOGIC-OBJECT) (VALUE OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return a member of concept `concept' that\nhas an attribute matching `value' for the binary relation `relation', i.e.,\n`(relation <result> value)' holds.\")", ((cpp_function_code)(&getConceptInstanceMatchingValue)), NULL);
    defineFunctionObject("GET-TYPES", "(DEFUN (GET-TYPES (PL-ITERATOR OF LOGIC-OBJECT)) ((OBJECT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return all named concepts that `object' belongs to.\")", ((cpp_function_code)(&getTypes)), NULL);
    defineFunctionObject("GET-DIRECT-TYPES", "(DEFUN (GET-DIRECT-TYPES (PL-ITERATOR OF LOGIC-OBJECT)) ((OBJECT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return most specific concepts that `object' belongs to.\")", ((cpp_function_code)(&getDirectTypes)), NULL);
  }
}

void helpStartupPli3() {
  {
    defineFunctionObject("GET-RELATION-EXTENSION", "(DEFUN (GET-RELATION-EXTENSION (PL-ITERATOR OF PROPOSITION)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return propositions that satisfy `relation'.\nInclude propositions that satisfy subrelations of `relation'.\")", ((cpp_function_code)(&getRelationExtension)), NULL);
    defineFunctionObject("S-GET-RELATION-EXTENSION", "(DEFUN (S-GET-RELATION-EXTENSION (PL-ITERATOR OF PROPOSITION)) ((RELATION-NAME STRING) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return propositions that satisfy the relation named\n`relation-name'.  Include propositions that satisfy subrelations of the relation.\")", ((cpp_function_code)(&sGetRelationExtension)), NULL);
    defineFunctionObject("GET-MODULE", "(DEFUN (GET-MODULE MODULE) ((NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return a module named `name'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getModule)), NULL);
    defineFunctionObject("GET-HOME-MODULE", "(DEFUN (GET-HOME-MODULE MODULE) ((OBJECT LOGIC-OBJECT)) :DOCUMENTATION \"Return the module in which `object' was created.\")", ((cpp_function_code)(&getHomeModule)), NULL);
    defineFunctionObject("CHANGE-MODULE", "(DEFUN (CHANGE-MODULE OBJECT) ((MODULE MODULE)) :DOCUMENTATION \"Set the current module to `module'.  The return value\nis `module' unless the context switch cannot be performed, in which case\nthe current module is returned.\")", ((cpp_function_code)(&changeModule)), NULL);
    defineFunctionObject("S-CHANGE-MODULE", "(DEFUN (S-CHANGE-MODULE OBJECT) ((NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Set the current module to the module named `name'.  \nThe return value is the module named `name' unless the context switch\ncannot be performed, in which case the current module is returned.\")", ((cpp_function_code)(&sChangeModule)), NULL);
    defineFunctionObject("CLEAR-MODULE", "(DEFUN (CLEAR-MODULE MODULE) ((MODULE MODULE)) :DOCUMENTATION \"Destroy the contents of the module `module' as well as\nthe contents of all of its children, recursively.\" :PUBLIC? TRUE)", ((cpp_function_code)(&clearModule)), NULL);
    defineFunctionObject("S-CLEAR-MODULE", "(DEFUN (S-CLEAR-MODULE MODULE) ((NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Destroy the contents of the module named `name', as\nwell as the contents of all of its children, recursively.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sClearModule)), NULL);
    defineFunctionObject("GET-CHILD-MODULES", "(DEFUN (GET-CHILD-MODULES (PL-ITERATOR OF MODULE)) ((MODULE MODULE)) :DOCUMENTATION \"Return the modules that are immediate children of `module'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getChildModules)), NULL);
    defineFunctionObject("S-GET-CHILD-MODULES", "(DEFUN (S-GET-CHILD-MODULES (PL-ITERATOR OF MODULE)) ((NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return the modules that are immediate children of module `name'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sGetChildModules)), NULL);
    defineFunctionObject("GET-PARENT-MODULES", "(DEFUN (GET-PARENT-MODULES (PL-ITERATOR OF MODULE)) ((MODULE MODULE)) :DOCUMENTATION \"Return the modules that are immediate parents of `module'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getParentModules)), NULL);
    defineFunctionObject("S-GET-PARENT-MODULES", "(DEFUN (S-GET-PARENT-MODULES (PL-ITERATOR OF MODULE)) ((NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return the modules that are immediate parents of module `name'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sGetParentModules)), NULL);
    defineFunctionObject("GET-MODULES", "(DEFUN (GET-MODULES (PL-ITERATOR OF MODULE)) () :DOCUMENTATION \"Return all modules currently loaded into PowerLoom.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getModules)), NULL);
    defineFunctionObject("GENERATE-UNIQUE-NAME", "(DEFUN (GENERATE-UNIQUE-NAME STRING) ((PREFIX STRING) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Generates a name based on `prefix' with a number appended that\nis not currently in use in the knowledge base.\" :PUBLIC? TRUE)", ((cpp_function_code)(&generateUniqueName)), NULL);
    defineFunctionObject("CREATE-OBJECT", "(DEFUN (CREATE-OBJECT LOGIC-OBJECT) ((NAME STRING) (CONCEPT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Create an object named `name' of type `concept' in the designated\nmodule.  Both `name' and `concept' can be `null'.  If `name' is `null' then an object\nwill be created with a new, non-conflicting name based on the name of `concept', or\nsystem-generated if no concept is specified.  If `concept' is `null', then the object\nwill be of type THING.\n\nReturn the object.\")", ((cpp_function_code)(&createObject)), NULL);
    defineFunctionObject("S-CREATE-OBJECT", "(DEFUN (S-CREATE-OBJECT LOGIC-OBJECT) ((NAME STRING) (CONCEPT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Create an object named `name' of type `concept-name' in the designated\nmodule.  Both `name' and `concept-name' can be null strings.  If `name' is a null string\nthen an object will be created with a new, non-conflicting name based on `concept-name', or\nsystem-generated if no concept nameis specified.  If `concept-name' is the null string, then\nthe object will be of type THING.\n\nReturn the object.\")", ((cpp_function_code)(&sCreateObject)), NULL);
    defineFunctionObject("CREATE-CONCEPT", "(DEFUN (CREATE-CONCEPT LOGIC-OBJECT) ((NAME STRING) (PARENT LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Create a concept named `name' in the designated `module', with the\ndesignated `parent' superconcept (which can be left undefined).  Additional\nsuperconcepts can be added via assertions of the `subset-of' relation.  Note\nthat a specified `parent' concept needs to be created separately.\")", ((cpp_function_code)(&createConcept)), NULL);
    defineFunctionObject("S-CREATE-CONCEPT", "(DEFUN (S-CREATE-CONCEPT LOGIC-OBJECT) ((NAME STRING) (PARENT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Create a concept named `name' in the designated module, with\nwith the concept named `parent-name' as superconcept (which can be left\nundefined).  Additional superconcepts can be added via assertions of the\n`subset-of' relation.  Note that a specified parent concept needs to be\ncreated separately.\")", ((cpp_function_code)(&sCreateConcept)), NULL);
    defineFunctionObject("CREATE-RELATION", "(DEFUN (CREATE-RELATION LOGIC-OBJECT) ((NAME STRING) (ARITY INTEGER) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Create a relation named `name' with arity `arity' in the\ndesignated module.  Domain and range information can be added via assertions\nof `nth-domain' (or `domain' and `range') relations.\")", ((cpp_function_code)(&createRelation)), NULL);
    defineFunctionObject("S-CREATE-RELATION", "(DEFUN (S-CREATE-RELATION LOGIC-OBJECT) ((NAME STRING) (ARITY INTEGER) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Create a relation named `name' with arity `arity' in the\ndesignated module.  Domain and range information can be added via assertions\nof `nth-domain' (or `domain' and `range') relations.\")", ((cpp_function_code)(&sCreateRelation)), NULL);
    defineFunctionObject("CREATE-FUNCTION", "(DEFUN (CREATE-FUNCTION LOGIC-OBJECT) ((NAME STRING) (ARITY INTEGER) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Create a function named `name' with arity `arity'  in the designated \n`module'.  Domain and range information can be added via assertions of\n`nth-domain' (or `domain' and `range') relations.\")", ((cpp_function_code)(&createFunction)), NULL);
    defineFunctionObject("S-CREATE-FUNCTION", "(DEFUN (S-CREATE-FUNCTION LOGIC-OBJECT) ((NAME STRING) (ARITY INTEGER) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Create a function named `name' with arity `arity' in the designated \nmodule.  Domain and range information can be added via assertions of\n`domain', `nth-domain' and `range' relations.\")", ((cpp_function_code)(&sCreateFunction)), NULL);
    defineFunctionObject("CREATE-ENUMERATED-LIST", "(DEFUN (CREATE-ENUMERATED-LIST LOGIC-OBJECT) ((MEMBERS CONS)) :DOCUMENTATION \"Create a logical term that denotes a list containing `members'.\nUseful for passing lists as arguments to parameterized queries.\" :PUBLIC? TRUE)", ((cpp_function_code)(&createEnumeratedList)), NULL);
    defineFunctionObject("CREATE-ENUMERATED-SET", "(DEFUN (CREATE-ENUMERATED-SET LOGIC-OBJECT) ((MEMBERS CONS)) :DOCUMENTATION \"Create a logical term that denotes the enumerated set containing `members'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&createEnumeratedSet)), NULL);
    defineFunctionObject("DESTROY-OBJECT", "(DEFUN DESTROY-OBJECT ((OBJECT LOGIC-OBJECT)) :DOCUMENTATION \"Delete the object `object', retracting all facts attached to it.\")", ((cpp_function_code)(&destroyObject)), NULL);
    defineFunctionObject("S-DESTROY-OBJECT", "(DEFUN S-DESTROY-OBJECT ((OBJECT-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Delete the object named `object-name', retracting all facts\nattached to it.\")", ((cpp_function_code)(&sDestroyObject)), NULL);
    defineFunctionObject("ASSERT-UNARY-PROPOSITION", "(DEFUN (ASSERT-UNARY-PROPOSITION PROPOSITION) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Assert that the proposition (`relation' `arg') is TRUE in `module'.  Return the asserted proposition.\")", ((cpp_function_code)(&assertUnaryProposition)), NULL);
    defineFunctionObject("ASSERT-BINARY-PROPOSITION", "(DEFUN (ASSERT-BINARY-PROPOSITION PROPOSITION) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (VALUE OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Assert that the proposition (`relation' `arg' `value') is TRUE\nin `module'.  Return the asserted proposition.\")", ((cpp_function_code)(&assertBinaryProposition)), NULL);
    defineFunctionObject("ASSERT-NARY-PROPOSITION", "(DEFUN (ASSERT-NARY-PROPOSITION PROPOSITION) ((RELATION-AND-ARGUMENTS OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Assert that the proposition represented by the list `arguments' satisfies\nthe relation `relation'.\")", ((cpp_function_code)(&assertNaryProposition)), NULL);
    defineFunctionObject("RETRACT-UNARY-PROPOSITION", "(DEFUN (RETRACT-UNARY-PROPOSITION PROPOSITION) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Retract that the proposition (`relation' `arg') is TRUE in `module'.  Return the asserted proposition.\")", ((cpp_function_code)(&retractUnaryProposition)), NULL);
    defineFunctionObject("RETRACT-BINARY-PROPOSITION", "(DEFUN (RETRACT-BINARY-PROPOSITION PROPOSITION) ((RELATION LOGIC-OBJECT) (ARG OBJECT) (VALUE OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Retract that the proposition (`relation' `arg' `value') is TRUE\nin `module'.  Return the asserted proposition.\")", ((cpp_function_code)(&retractBinaryProposition)), NULL);
    defineFunctionObject("RETRACT-NARY-PROPOSITION", "(DEFUN (RETRACT-NARY-PROPOSITION PROPOSITION) ((RELATION-AND-ARGUMENTS OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Retract the proposition that `arguments' satisfies\nthe relation `relation'.\")", ((cpp_function_code)(&retractNaryProposition)), NULL);
    defineFunctionObject("ASSERT-PROPOSITION", "(DEFUN (ASSERT-PROPOSITION PROPOSITION) ((PROPOSITION PROPOSITION) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Assert that the proposition `proposition' is true in `module'.\nReturn the asserted proposition.\")", ((cpp_function_code)(&assertProposition)), NULL);
    defineFunctionObject("S-ASSERT-PROPOSITION", "(DEFUN (S-ASSERT-PROPOSITION (PL-ITERATOR OF PROPOSITION)) ((SENTENCE STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Assert that the logical sentence `sentence' is true in the module\nnamed `module-name'. Return an iterator of the propositions resulting\nfrom sentence.\")", ((cpp_function_code)(&sAssertProposition)), NULL);
    defineFunctionObject("RETRACT-PROPOSITION", "(DEFUN (RETRACT-PROPOSITION PROPOSITION) ((PROPOSITION PROPOSITION) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Retract the truth of the proposition `proposition' in `module'.\nReturn the retracted proposition.\")", ((cpp_function_code)(&retractProposition)), NULL);
    defineFunctionObject("S-RETRACT-PROPOSITION", "(DEFUN (S-RETRACT-PROPOSITION (PL-ITERATOR OF PROPOSITION)) ((SENTENCE STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Retract the truth of the logical sentence `sentence' in the module named\n`module-name'.  Return an iterator of the retracted propositions resulting\nfrom sentence.\")", ((cpp_function_code)(&sRetractProposition)), NULL);
    defineFunctionObject("CONCEIVE", "(DEFUN (CONCEIVE (PL-ITERATOR OF PROPOSITION)) ((SENTENCE OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Create one or more proposition objects from the sentence `sentence'\nin the  module `module'.  Return an iterator of the propositions.\nIf any of the new propositions has the same structure as an already existing\nproposition, an automatic check for duplicates will return the pre-existing\nproposition.  Multiple propositions may be returned for a single sentence\nbecause of normalization of equivalences, conjunctions, etc.\n\nSignals a `Proposition-Error' if PowerLoom could not conceive `sentence'.\")", ((cpp_function_code)(&conceive)), NULL);
    defineFunctionObject("S-CONCEIVE", "(DEFUN (S-CONCEIVE (PL-ITERATOR OF PROPOSITION)) ((SENTENCE STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Create one or more proposition objects from the sentence `sentence'\nin the  module named `module-name'.  Return an iterator of the propositions.\nIf any of the new propositions has the same structure as an already existing\nproposition, an automatic check for duplicates will return the pre-existing\nproposition.  Multiple propositions may be returned for a single sentence\nbecause of normalization of equivalences, conjunctions, etc.\n\nSignals a `Proposition-Error' if PowerLoom could not conceive `sentence'.\")", ((cpp_function_code)(&sConceive)), NULL);
    defineFunctionObject("GET-RULES", "(DEFUN (GET-RULES (PL-ITERATOR OF PROPOSITION)) ((RELATION LOGIC-OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return rules attached to the concept/relation `relation'\nin either antecedent or consequent position.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getRules)), NULL);
    defineFunctionObject("S-GET-RULES", "(DEFUN (S-GET-RULES (PL-ITERATOR OF PROPOSITION)) ((RELATION-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return rules attached to the concept/relation named\n`relation-name' found in the module named `module-name'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sGetRules)), NULL);
    defineFunctionObject("S-PRINT-RULES", "(DEFUN S-PRINT-RULES ((NAME STRING) (STREAM OUTPUT-STREAM) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Print rules attached to the concept/relation named `name'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sPrintRules)), NULL);
    defineFunctionObject("RUN-FORWARD-RULES", "(DEFUN RUN-FORWARD-RULES ((MODULE OBJECT) (FORCE? BOOLEAN)) :DOCUMENTATION \"Run forward inference rules in module `module'.\nIf `module' is NULL, the\ncurrent module will be used.  If forward inferencing is already up-to-date\nin the designated module, no additional inferencing will occur, unless `force'\nis set to TRUE, in which case all forward rules are run or rerun.\n\nCalling `run-forward-rules' temporarily puts the module into a mode where\nfuture assertional (monotonic) updates will trigger additional forward\ninference.  Once a non-monotonic update is performed, i.e., a retraction\nor clipping of relation value, all cached forward inferences will be discarded\nand forward inferencing will be disabled until this function is\ncalled again.\")", ((cpp_function_code)(&runForwardRules)), NULL);
    defineFunctionObject("GET-ARITY", "(DEFUN (GET-ARITY INTEGER) ((RELATION LOGIC-OBJECT)) :DOCUMENTATION \"Return the arity of the relation `relation'.\")", ((cpp_function_code)(&getArity)), NULL);
    defineFunctionObject("S-GET-ARITY", "(DEFUN (S-GET-ARITY INTEGER) ((RELATION-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return the arity of the relation named `relation-name'.\")", ((cpp_function_code)(&sGetArity)), NULL);
    defineFunctionObject("GET-DOMAIN", "(DEFUN (GET-DOMAIN LOGIC-OBJECT) ((RELATION LOGIC-OBJECT)) :DOCUMENTATION \"Return the type (a concept) for the first argument to the binary\nrelation `relation'.\")", ((cpp_function_code)(&getDomain)), NULL);
    defineFunctionObject("S-GET-DOMAIN", "(DEFUN (S-GET-DOMAIN LOGIC-OBJECT) ((RELATION-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return the type (concept) for the first argument to the binary\nrelation `relation-name'.\")", ((cpp_function_code)(&sGetDomain)), NULL);
    defineFunctionObject("GET-RANGE", "(DEFUN (GET-RANGE LOGIC-OBJECT) ((RELATION LOGIC-OBJECT)) :DOCUMENTATION \"Return the type (a concept) for fillers of the binary relation\n`relation'.\")", ((cpp_function_code)(&getRange)), NULL);
    defineFunctionObject("S-GET-RANGE", "(DEFUN (S-GET-RANGE LOGIC-OBJECT) ((RELATION-NAME STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return the type (a concept) for fillers of the binary relation\n`relation-name'.\")", ((cpp_function_code)(&sGetRange)), NULL);
    defineFunctionObject("GET-NTH-DOMAIN", "(DEFUN (GET-NTH-DOMAIN LOGIC-OBJECT) ((RELATION LOGIC-OBJECT) (N INTEGER)) :DOCUMENTATION \"Return the type (a concept) for the the nth argument of the\nrelation `relation'.  Counting starts at zero.\")", ((cpp_function_code)(&getNthDomain)), NULL);
    defineFunctionObject("S-GET-NTH-DOMAIN", "(DEFUN (S-GET-NTH-DOMAIN LOGIC-OBJECT) ((RELATION-NAME STRING) (N INTEGER) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Return the type (a concept) for the nth argument of the relation\nnamed `relation-name'.  Counting starts at zero.\")", ((cpp_function_code)(&sGetNthDomain)), NULL);
    defineFunctionObject("LOAD", "(DEFUN LOAD ((FILENAME STRING)) :DOCUMENTATION \"Read logic commands from the file named `filename' and evaluate them.\nThe file should begin with an `in-module' declaration that specifies\nthe module within which all remaining commands are to be evaluated\nThe remaining commands are evaluated one-by-one, applying the function\n`evaluate' to each of them.\" :PUBLIC? TRUE)", ((cpp_function_code)(&load)), NULL);
    defineFunctionObject("SAVE-MODULE", "(DEFUN SAVE-MODULE ((MODULE MODULE) (FILENAME STRING) (IFEXISTS STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Save the contents of the module `mod' into a file named `filename'.\nIf a file named `filename' already exists, then the action taken depends on the\nvalue of `ifexists'.  Possible values are \\\"ASK\\\", \\\"REPLACE\\\", \\\"WARN\\\" and \\\"ERROR\\\":\n\n  REPLACE => Means overwrite without warning.\n  WARN    => Means overwrite with a warning.\n  ERROR   => Means don't overwrite, signal an error instead.\n  ASK     => Ask the user whether to overwrite or not.  If not overwritten, an\n             exception is thrown.\" :PUBLIC? TRUE)", ((cpp_function_code)(&saveModule)), NULL);
    defineFunctionObject("S-SAVE-MODULE", "(DEFUN S-SAVE-MODULE ((MODULE-NAME STRING) (FILENAME STRING) (IFEXISTS STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Save the contents of the module `module-name' into a file named `filename'.\nIf a file named `filename' already exists, then the action taken depends on the\nvalue of `ifexists'.  Possible values are \\\"ASK\\\", \\\"REPLACE\\\", \\\"WARN\\\" and \\\"ERROR\\\":\n\n  REPLACE => Means overwrite without warning.\n  WARN    => Means overwrite with a warning.\n  ERROR   => Means don't overwrite, signal an error instead.\n  ASK     => Ask the user whether to overwrite or not.  If not overwritten, an\n             exception is thrown.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sSaveModule)), NULL);
    defineFunctionObject("GET-PREDICATE", "(DEFUN (GET-PREDICATE LOGIC-OBJECT) ((PROP PROPOSITION)) :DOCUMENTATION \"Return the concept or relation predicate for\nthe proposition `prop'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getPredicate)), NULL);
    defineFunctionObject("GET-COLUMN-COUNT", "(DEFUN (GET-COLUMN-COUNT INTEGER) ((OBJ OBJECT)) :DOCUMENTATION \"Return the number of columns in `obj', which must\nbe of type proposition, cons, vector or PL-iterator.  For a proposition,\nthe number includes both the predidate and arguments. For the PL-iterator\ncase,the number of columns is for the current value of the iterator.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getColumnCount)), NULL);
    defineFunctionObject("GET-NTH-VALUE", "(DEFUN (GET-NTH-VALUE OBJECT) ((SEQUENCE OBJECT) (N INTEGER)) :DOCUMENTATION \"Return the value in the `nth' column of `sequence'.\nCounting starts at zero.  `sequence' must be of type proposition, cons,\nvector or PL-iterator.  A zero column number returns a proposition's \nrelational predicate.  For the PL-iterator case, the number of columns\nis for the current value of the iterator.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getNthValue)), NULL);
    defineFunctionObject("GET-NTH-STRING", "(DEFUN (GET-NTH-STRING STRING) ((SEQUENCE OBJECT) (N INTEGER)) :DOCUMENTATION \"Return a string representation of the value in the `nth' column of\n`sequence'. Counting starts at zero.  `sequence' must be of type\nproposition, cons, vector or PL-iterator.  A zero column number returns\na proposition's relational predicate.  For the PL-iterator case, the\nthe current value pointed to by the iterator is used.  This will always\nsucceed, even if the `nth' value is not a string object.  In that case, a\nstring reprensentation will be returned.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getNthString)), NULL);
    defineFunctionObject("GET-NTH-INTEGER", "(DEFUN (GET-NTH-INTEGER INTEGER) ((SEQUENCE OBJECT) (N INTEGER)) :DOCUMENTATION \"Return an integer representation of the value in the `nth' column of\n`sequence'. Counting starts at zero.  `sequence' must be of type\nproposition, cons, vector or PL-iterator.  A zero column number returns\na proposition's relational predicate.  For the PL-iterator case, the\nthe current value pointed to by the iterator is used.  If this is not\nan integer value, then NULL-INTEGER will be returned.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getNthInteger)), NULL);
    defineFunctionObject("GET-NTH-FLOAT", "(DEFUN (GET-NTH-FLOAT FLOAT) ((SEQUENCE OBJECT) (N INTEGER)) :DOCUMENTATION \"Return the floating point value in the `nth' column of\n`sequence'. Counting starts at zero.  `sequence' must be of type\nproposition, cons, vector or PL-iterator.  A zero column number returns\na proposition's relational predicate.  For the PL-iterator case, the\nthe current value pointed to by the iterator is used.  If this is not\na floating point value, then NULL-FLOAT will be returned.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getNthFloat)), NULL);
    defineFunctionObject("GET-NTH-LOGIC-OBJECT", "(DEFUN (GET-NTH-LOGIC-OBJECT LOGIC-OBJECT) ((SEQUENCE OBJECT) (N INTEGER)) :DOCUMENTATION \"Return a logic object representation of the value in the `nth' column\nof `sequence'.  Counting starts at zero.  `sequence' must be of type\nproposition, cons, vector or PL-iterator.  A zero column number returns\na proposition's relational predicate.  For the PL-iterator case, the\nthe current value pointed to by the iterator is used.  A zero column number\nreturns the proposition's relational predicate.\" :PUBLIC? TRUE)", ((cpp_function_code)(&getNthLogicObject)), NULL);
  }
}

void startupPli() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/PLI", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupPli1();
    }
    if (currentStartupTimePhaseP(4)) {
      { Environment* self092 = newEnvironment();

        self092->level = "ASSERTION";
        ASSERTION_ENV = self092;
      }
      { Environment* self093 = newEnvironment();

        self093->level = "TAXONOMIC";
        TAXONOMIC_ENV = self093;
      }
      { Environment* self094 = newEnvironment();

        self094->level = "INFERENCE";
        INFERENCE_ENV = self094;
      }
      { PlIterator* self095 = newPlIterator();

        self095->cursor = NIL;
        EMPTY_PL_ITERATOR = self095;
      }
    }
    if (currentStartupTimePhaseP(5)) {
      { Class* clasS = defineClassFromStringifiedSource("ENVIRONMENT", "(DEFCLASS ENVIRONMENT (STANDARD-OBJECT) :SLOTS ((LEVEL :TYPE STRING)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|ENV|\" (LEVEL SELF)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newEnvironment));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessEnvironmentSlotValue));
      }
      { Class* clasS = defineClassFromStringifiedSource("PL-ITERATOR", "(DEFCLASS PL-ITERATOR (ITERATOR) :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((CURSOR :TYPE CONS)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newPlIterator));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessPlIteratorSlotValue));
      }
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupPli2();
      helpStartupPli3();
      defineFunctionObject("GET-ENUMERATED-COLLECTION-MEMBERS", "(DEFUN (GET-ENUMERATED-COLLECTION-MEMBERS CONS) ((COLLECTION OBJECT)) :DOCUMENTATION \"Returns the members of an enumerated collection.  This works on all types\nof collection, i.e., sets and lists\" :PUBLIC? TRUE)", ((cpp_function_code)(&getEnumeratedCollectionMembers)), NULL);
      defineFunctionObject("EVALUATE", "(DEFUN (EVALUATE OBJECT) ((COMMAND OBJECT) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Evaluate the command `command' within `module' and return\nthe result. Currently, only the evaluation of (possibly nested) commands and\nglobal variables is supported.  Commands are simple to program in Common Lisp,\nsince they are built into the language, and relatively awkward in Java and C++.\nUsers of either of those languages are more likely to want to call `s-evaluate'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&evaluate)), NULL);
      defineFunctionObject("S-EVALUATE", "(DEFUN (S-EVALUATE OBJECT) ((COMMAND STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Evaluate the command represented by the string `command' within `module' and\nreturn the result.  Currently, only the evaluation of (possibly nested) commands and\nglobal variables is supported.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sEvaluate)), NULL);
      defineFunctionObject("IS-LOGIC-OBJECT", "(DEFUN (IS-LOGIC-OBJECT BOOLEAN) ((OBJ OBJECT)) :DOCUMENTATION \"Test whether `obj' is of type LOGIC-OBJECT\" :PUBLIC? TRUE)", ((cpp_function_code)(&isLogicObject)), NULL);
      defineFunctionObject("IS-INTEGER", "(DEFUN (IS-INTEGER BOOLEAN) ((OBJ OBJECT)) :DOCUMENTATION \"Test whether `obj' is of type INTEGER\" :PUBLIC? TRUE)", ((cpp_function_code)(&isInteger)), NULL);
      defineFunctionObject("IS-FLOAT", "(DEFUN (IS-FLOAT BOOLEAN) ((OBJ OBJECT)) :DOCUMENTATION \"Test whether `obj' is of type FLOAT (double)\" :PUBLIC? TRUE)", ((cpp_function_code)(&isFloat)), NULL);
      defineFunctionObject("IS-NUMBER", "(DEFUN (IS-NUMBER BOOLEAN) ((OBJ OBJECT)) :DOCUMENTATION \"Test whether `obj' is of type NUMBER.  This can\nbe either an integer or a floating point number.  One key characteristic\nis that 'object-to-integer' and `object-to-float' will both work on it.\" :PUBLIC? TRUE)", ((cpp_function_code)(&isNumber)), NULL);
      defineFunctionObject("IS-STRING", "(DEFUN (IS-STRING BOOLEAN) ((OBJ OBJECT)) :DOCUMENTATION \"Test whether `obj' is of type STRING\" :PUBLIC? TRUE)", ((cpp_function_code)(&isString)), NULL);
      defineFunctionObject("IS-ENUMERATED-COLLECTION", "(DEFUN (IS-ENUMERATED-COLLECTION BOOLEAN) ((OBJ OBJECT)) :DOCUMENTATION \"Test whether `obj' is an enumerated collection.  This\nsubsumes both sets and lists.\" :PUBLIC? TRUE)", ((cpp_function_code)(&isEnumeratedCollection)), NULL);
      defineFunctionObject("IS-ENUMERATED-SET", "(DEFUN (IS-ENUMERATED-SET BOOLEAN) ((OBJ OBJECT)) :DOCUMENTATION \"Test whether `obj' is an enumerated set.\" :PUBLIC? TRUE)", ((cpp_function_code)(&isEnumeratedSet)), NULL);
      defineFunctionObject("IS-ENUMERATED-LIST", "(DEFUN (IS-ENUMERATED-LIST BOOLEAN) ((OBJ OBJECT)) :DOCUMENTATION \"Test whether `obj' is an enumerated list\" :PUBLIC? TRUE)", ((cpp_function_code)(&isEnumeratedList)), NULL);
      defineFunctionObject("IS-TRUE", "(DEFUN (IS-TRUE BOOLEAN) ((TV TRUTH-VALUE)) :DOCUMENTATION \"Tests whether `tv' is a true truth value.  It can be true\neither absolutely or by default.\" :PUBLIC? TRUE)", ((cpp_function_code)(&isTrue)), NULL);
      defineFunctionObject("IS-FALSE", "(DEFUN (IS-FALSE BOOLEAN) ((TV TRUTH-VALUE)) :DOCUMENTATION \"Tests whether `tv' is a false truth value.  It can be false\neither absolutely or by default.\" :PUBLIC? TRUE)", ((cpp_function_code)(&isFalse)), NULL);
      defineFunctionObject("IS-UNKNOWN", "(DEFUN (IS-UNKNOWN BOOLEAN) ((TV TRUTH-VALUE)) :DOCUMENTATION \"Tests whether `tv' is an unknown truth value.\" :PUBLIC? TRUE)", ((cpp_function_code)(&isUnknown)), NULL);
      defineFunctionObject("IS-STRICT", "(DEFUN (IS-STRICT BOOLEAN) ((TV TRUTH-VALUE)) :DOCUMENTATION \"Tests whether `tv' is a strict (non-default) truth value.\" :PUBLIC? TRUE)", ((cpp_function_code)(&isStrict)), NULL);
      defineFunctionObject("IS-DEFAULT", "(DEFUN (IS-DEFAULT BOOLEAN) ((TV TRUTH-VALUE)) :DOCUMENTATION \"Tests whether `tv' is a default truth value.\" :PUBLIC? TRUE)", ((cpp_function_code)(&isDefault)), NULL);
      defineFunctionObject("ASK", "(DEFUN (ASK TRUTH-VALUE) ((QUERY CONS) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Returns a truth value for the `query' in `module' and `environment'.\nThe truth value represents the degree of belief in the answer.  See also the\nhelping functions `is-true', `is-false' , `is-unknown'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&ask)), NULL);
      defineFunctionObject("S-ASK", "(DEFUN (S-ASK TRUTH-VALUE) ((QUERY STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Returns a truth value for the `query' in `module-name' and `environment'.\nThe truth value represents the degree of belief in the answer.  See also the\nhelping functions `is-true', `is-false' , `is-unknown'.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sAsk)), NULL);
      defineFunctionObject("RETRIEVE", "(DEFUN (RETRIEVE PL-ITERATOR) ((QUERY CONS) (MODULE MODULE) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Returns an iterator for variables that satisfy `query' in `module-name'\nand `environment'.  This uses the normal PowerLoom query syntax:\n\n   `[n-values] output-variables query-form [options]'\n\nThe `output-variables' should either be a single variable name\n-- preceded by the '?' character -- or a list of one or more such names.\nIf a single variable name is provided, then each element in the returned\niterator will be a value binding.  If a list (even of one variable name)\nis provided, then each element in the returned iterator can be accessed\nusing the `get-nth-'... functions.\" :PUBLIC? TRUE)", ((cpp_function_code)(&retrieve)), NULL);
      defineFunctionObject("S-RETRIEVE", "(DEFUN (S-RETRIEVE PL-ITERATOR) ((QUERY STRING) (MODULE-NAME STRING) (ENVIRONMENT OBJECT)) :DOCUMENTATION \"Returns an iterator for variables that satisfy `query' in `module-name'\nand `environment'.  This uses the normal PowerLoom query syntax:\n\n   `\\\"[n-values] output-variables query-form [options]\\\"'\n\nThe `output-variables' should either be a single variable name\n-- preceded by the '?' character -- or a list of one or more such names.\nIf a single variable name is provided, then each element in the returned\niterator will be a value binding.  If a list (even of one variable name)\nis provided, then each element in the returned iterator can be accessed\nusing the `get-nth-'... functions.\" :PUBLIC? TRUE)", ((cpp_function_code)(&sRetrieve)), NULL);
      defineFunctionObject("MAIN", "(DEFUN (MAIN INTEGER) () :PUBLIC? TRUE :DOCUMENTATION \"Main PowerLoom entry point for your code in C++ and Java.\")", NULL, NULL);
      defineFunctionObject("STARTUP-PLI", "(DEFUN STARTUP-PLI () :PUBLIC? TRUE)", ((cpp_function_code)(&startupPli)), NULL);
      { MethodSlot* function = lookupFunction(SYM_PLI_PLI_STARTUP_PLI);

        setDynamicSlotValue(function->dynamicSlots, SYM_PLI_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Pli"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT ASSERTION-ENV ENVIRONMENT (NEW ENVIRONMENT :LEVEL \"ASSERTION\"))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT TAXONOMIC-ENV ENVIRONMENT (NEW ENVIRONMENT :LEVEL \"TAXONOMIC\"))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT INFERENCE-ENV ENVIRONMENT (NEW ENVIRONMENT :LEVEL \"INFERENCE\"))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL EMPTY-PL-ITERATOR PL-ITERATOR (NEW PL-ITERATOR :CURSOR NIL) :DOCUMENTATION \"Iterator that generates no values.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LITERAL-CONCEPT* NAMED-DESCRIPTION NULL :PUBLIC? FALSE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STRING-CONCEPT* NAMED-DESCRIPTION NULL :PUBLIC? FALSE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *INTEGER-CONCEPT* NAMED-DESCRIPTION NULL :PUBLIC? FALSE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *FLOAT-CONCEPT* NAMED-DESCRIPTION NULL :PUBLIC? FALSE)");
      oLITERAL_CONCEPTo = ((NamedDescription*)(sGetConcept("LITERAL", "PL-USER", NULL)));
      oSTRING_CONCEPTo = ((NamedDescription*)(sGetConcept("STRING", "PL-USER", NULL)));
      oINTEGER_CONCEPTo = ((NamedDescription*)(sGetConcept("INTEGER", "PL-USER", NULL)));
      oFLOAT_CONCEPTo = ((NamedDescription*)(sGetConcept("FLOAT", "PL-USER", NULL)));
    }
  }
}

Surrogate* SGT_PLI_PLI_ENVIRONMENT = NULL;

Symbol* SYM_PLI_LOGIC_LEVEL = NULL;

Surrogate* SGT_PLI_PLI_PL_ITERATOR = NULL;

Symbol* SYM_PLI_STELLA_CURSOR = NULL;

Surrogate* SGT_PLI_STELLA_CONS = NULL;

Surrogate* SGT_PLI_STELLA_LIST = NULL;

Surrogate* SGT_PLI_STELLA_VECTOR = NULL;

Symbol* SYM_PLI_STELLA_NULL = NULL;

Surrogate* SGT_PLI_LOGIC_SKOLEM = NULL;

Surrogate* SGT_PLI_LOGIC_LOGIC_OBJECT = NULL;

Surrogate* SGT_PLI_STELLA_GENERALIZED_SYMBOL = NULL;

Surrogate* SGT_PLI_STELLA_CONTEXT = NULL;

Surrogate* SGT_PLI_LOGIC_COMPUTED_PROCEDURE = NULL;

Surrogate* SGT_PLI_STELLA_LITERAL_WRAPPER = NULL;

Surrogate* SGT_PLI_LOGIC_NAMED_DESCRIPTION = NULL;

Symbol* SYM_PLI_PLI_pR = NULL;

Symbol* SYM_PLI_PLI_pI = NULL;

Symbol* SYM_PLI_PLI_pV = NULL;

Symbol* SYM_PLI_PLI_QUERY_099 = NULL;

Keyword* KWD_PLI_ISA = NULL;

Surrogate* SGT_PLI_STELLA_MODULE = NULL;

Keyword* KWD_PLI_SUBSET_OF = NULL;

Keyword* KWD_PLI_ERROR = NULL;

Keyword* KWD_PLI_RETRACT_TRUE = NULL;

Keyword* KWD_PLI_ASSERT_TRUE = NULL;

Surrogate* SGT_PLI_LOGIC_PROPOSITION = NULL;

Symbol* SYM_PLI_LOGIC_DESCRIPTION = NULL;

Surrogate* SGT_PLI_STELLA_INTEGER_WRAPPER = NULL;

Surrogate* SGT_PLI_STELLA_FLOAT_WRAPPER = NULL;

Surrogate* SGT_PLI_STELLA_NUMBER_WRAPPER = NULL;

Surrogate* SGT_PLI_STELLA_STRING_WRAPPER = NULL;

Surrogate* SGT_PLI_STELLA_SYMBOL = NULL;

Symbol* SYM_PLI_PLI_STARTUP_PLI = NULL;

Symbol* SYM_PLI_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace pli


