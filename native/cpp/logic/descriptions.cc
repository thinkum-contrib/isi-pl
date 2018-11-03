//  -*- Mode: C++ -*-

// descriptions.cc

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

Iterator* directSuperrelations(Relation* self) {
  // Return direct super classes/slots of 'self'.
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfClassP(testValue000)) {
      { Relation* self000 = self;
        Class* self = ((Class*)(self000));

        return (self->directSuperClasses());
      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_STELLA_SLOT)) {
      { Relation* self001 = self;
        Slot* self = ((Slot*)(self001));

        return (((ListIterator*)(self->slotDirectSupers_reader()->allocateIterator())));
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

Cons* slotColumnTypes(Slot* self, int count) {
  { boolean dummy1;

    if (subtypeOfStorageSlotP(safePrimaryType(self))) {
      { Slot* self000 = self;
        StorageSlot* self = ((StorageSlot*)(self000));

        { Surrogate* domain = self->slotOwner;
          Surrogate* range = self->slotBaseType;
          Cons* typeslist = (booleanTypeP(range) ? consList(1, domain) : consList(2, domain, range));

          return (typeslist);
        }
      }
    }
    else {
      { List* typespecifiers = (isaP(self, SGT_DESCRIPTIONS_STELLA_METHOD_SLOT) ? ((MethodSlot*)(self))->methodParameterTypeSpecifiers_reader() : ((Table*)(self))->tupleDomains);
        Cons* typeslist = NIL;
        Cons* variabletypes = NIL;
        Cons* returntypes = NIL;
        Surrogate* returntype = unwrapWrappedType(self->slotBaseType);

        if (((boolean)(returntype)) &&
            (!booleanTypeP(returntype))) {
          returntypes = cons(returntype, returntypes);
        }
        if (self->arity() == NULL_INTEGER) {
          { StandardObject* variableargumentstype = extractParameterType(((ParametricTypeSpecifier*)(typespecifiers->last())), SYM_DESCRIPTIONS_STELLA_ANY_VALUE, dummy1);

            { Object* tspec = NULL;
              Iterator* iter000 = typespecifiers->butLast();
              Cons* collect000 = NULL;

              while (iter000->nextP()) {
                tspec = iter000->value;
                if (!((boolean)(collect000))) {
                  {
                    collect000 = cons(unwrapWrappedType(typeSpecToBaseType(((StandardObject*)(tspec)))), NIL);
                    if (typeslist == NIL) {
                      typeslist = collect000;
                    }
                    else {
                      addConsToEndOfConsList(typeslist, collect000);
                    }
                  }
                }
                else {
                  {
                    collect000->rest = cons(unwrapWrappedType(typeSpecToBaseType(((StandardObject*)(tspec)))), NIL);
                    collect000 = collect000->rest;
                  }
                }
              }
            }
            if (count == NULL_INTEGER) {
              count = 1;
            }
            else {
              count = count - (typeslist->length() + returntypes->length());
            }
            { int i = NULL_INTEGER;
              int iter001 = 1;
              int upperBound000 = count;
              boolean unboundedP000 = upperBound000 == NULL_INTEGER;

              while (unboundedP000 ||
                  (iter001 <= upperBound000)) {
                i = iter001;
                iter001 = iter001 + 1;
                i = i;
                variabletypes = cons(variableargumentstype, variabletypes);
              }
            }
            typeslist = typeslist->concatenate(variabletypes, 0);
          }
        }
        else {
          { Object* tspec = NULL;
            Cons* iter002 = typespecifiers->theConsList;
            Cons* collect001 = NULL;

            while (!(iter002 == NIL)) {
              tspec = iter002->value;
              iter002 = iter002->rest;
              if (!((boolean)(collect001))) {
                {
                  collect001 = cons(unwrapWrappedType(typeSpecToBaseType(((StandardObject*)(tspec)))), NIL);
                  if (typeslist == NIL) {
                    typeslist = collect001;
                  }
                  else {
                    addConsToEndOfConsList(typeslist, collect001);
                  }
                }
              }
              else {
                {
                  collect001->rest = cons(unwrapWrappedType(typeSpecToBaseType(((StandardObject*)(tspec)))), NIL);
                  collect001 = collect001->rest;
                }
              }
            }
          }
        }
        typeslist = typeslist->concatenate(returntypes, 0);
        return (typeslist);
      }
    }
  }
}

// Installed in a description with undetermined arity.
Vector* FAKE_IO_VARIABLES = NULL;

Description* createDescription(int arity, boolean namedP) {
  enforceCodeOnly();
  { Description* description = (namedP ? newNamedDescription() : newDescription());

    description->ioVariables = ((arity != NULL_INTEGER) ? newVector(arity) : FAKE_IO_VARIABLES);
    return (description);
  }
}

Symbol* Description::descriptionName() {
  // Return the name of the description `self', if it has one.
  { Description* self = this;

    return (NULL);
  }
}

Symbol* NamedDescription::descriptionName() {
  // Return the name of the description `self'.
  { NamedDescription* self = this;

    return (objectName(self));
  }
}

void createBaseRelationForPolymorphicDescription(Description* description) {
  { Surrogate* surrogate = internSurrogateInModule(description->descriptionName()->symbolName, ((Module*)(description->homeContext)), TRUE);
    Object* relation = surrogate->surrogateValue;

    if (!((boolean)(relation))) {
      { 
        BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_DESCRIPTIONS_EXTENSIONAL_ASSERTION);
        BIND_STELLA_SPECIAL(oFILLINGCONSTRAINTPROPAGATIONQUEUESpo, boolean, FALSE);
        assertIsaProposition(createLogicInstance(surrogate, SGT_DESCRIPTIONS_PL_KERNEL_KB_RELATION), SGT_DESCRIPTIONS_PL_KERNEL_KB_POLYMORPHIC);
      }
    }
  }
}

Cons* SYSTEM_DEFINED_ARGUMENT_NAMES = NULL;

Symbol* yieldSystemDefinedParameterName(int index, Object* referenceobject) {
  if (index < 100) {
    return (internSymbolInModule(((Symbol*)(SYSTEM_DEFINED_ARGUMENT_NAMES->nth(index)))->symbolName, referenceobject->homeModule(), TRUE));
  }
  else {
    return (internSymbolInModule(stringConcatenate("?X", integerToString(index + 1), 0), referenceobject->homeModule(), TRUE));
  }
}

void ensureDescriptionBody(Description* description) {
  if (((!((boolean)(description->proposition))) ||
      (description->proposition == TRUE_PROPOSITION)) &&
      isaP(description, SGT_DESCRIPTIONS_LOGIC_NAMED_DESCRIPTION)) {
    materializePrimitiveDescriptionBody(((NamedDescription*)(description)));
  }
}

void materializePrimitiveDescriptionBody(NamedDescription* description) {
  { boolean nativeP = ((boolean)(description->nativeRelation()));
    Symbol* name = (nativeP ? internSymbolInModule(description->nativeRelation()->name(), description->nativeRelation()->homeModule(), TRUE) : description->descriptionName());
    List* variabletypes = description->ioVariableTypes;
    int arity = variabletypes->length();
    Cons* tree = NULL;
    Cons* variables = NIL;
    Cons* arguments = NIL;

    { Symbol* name = NULL;
      IntegerIntervalIterator* i = interval(1, arity);
      Cons* iter000 = SYSTEM_DEFINED_ARGUMENT_NAMES;
      Cons* collect000 = NULL;

      while (i->nextP() &&
          (!(iter000 == NIL))) {
        name = ((Symbol*)(iter000->value));
        iter000 = iter000->rest;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(name, NIL);
            if (variables == NIL) {
              variables = collect000;
            }
            else {
              addConsToEndOfConsList(variables, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(name, NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    arguments = copyConsList(variables);
    if (nativeP &&
        (arity > 1)) {
      variables->firstSetter(listO(3, SYM_DESCRIPTIONS_STELLA_ISA, variables->value, cons(typeToSymbol(((Surrogate*)(variabletypes->first()))), NIL)));
    }
    tree = listO(3, SYM_DESCRIPTIONS_LOGIC_KAPPA, variables, cons(cons(name, arguments->concatenate(NIL, 0)), NIL));
    { 
      BIND_STELLA_SPECIAL(oLOGIC_DIALECTo, Keyword*, KWD_DESCRIPTIONS_KIF);
      BIND_STELLA_SPECIAL(oLOGICVARIABLETABLEo, Cons*, NIL);
      BIND_STELLA_SPECIAL(oTERMUNDERCONSTRUCTIONo, Object*, tree);
      BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_DESCRIPTIONS_DESCRIPTION);
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, description->homeContext);
      { Description* sacrificialdescription = evaluateDescriptionTerm(tree, FALSE);

        description->ioVariables = sacrificialdescription->ioVariables;
        description->proposition = sacrificialdescription->proposition;
        sacrificialdescription->deletedPSetter(TRUE);
      }
    }
  }
}

NamedDescription* createPrimitiveDescription(List* iovariablenames, List* iovariabletypes, boolean variablearityP, boolean classP, boolean functionP, Module* module) {
  if (iovariabletypes->length() > SYSTEM_DEFINED_ARGUMENT_NAMES->length()) {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "PowerLoom can't handle relations with arity > " << "`" << SYSTEM_DEFINED_ARGUMENT_NAMES->length() << "'" << std::endl;
      throw *newStellaException(stream000->theStringReader());
    }
  }
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, module);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    { 
      BIND_STELLA_SPECIAL(oFILLINGCONSTRAINTPROPAGATIONQUEUESpo, boolean, FALSE);
      { NamedDescription* description = ((NamedDescription*)(createDescription(NULL_INTEGER, TRUE)));

        description->ioVariableNames = iovariablenames;
        description->ioVariableTypes = iovariabletypes;
        if (classP) {
          linkOriginatedProposition(description, assertIsaProposition(description, SGT_DESCRIPTIONS_PL_KERNEL_KB_CONCEPT));
        }
        else if (functionP) {
          linkOriginatedProposition(description, assertIsaProposition(description, SGT_DESCRIPTIONS_PL_KERNEL_KB_FUNCTION));
        }
        else {
          linkOriginatedProposition(description, assertIsaProposition(description, SGT_DESCRIPTIONS_PL_KERNEL_KB_RELATION));
        }
        if (variablearityP) {
          linkOriginatedProposition(description, assertProperty(description, SGT_DESCRIPTIONS_PL_KERNEL_KB_VARIABLE_ARITY));
        }
        return (description);
      }
    }
  }
}

void linkStellaRelationAndDescription(Relation* self, NamedDescription* description) {
  setDynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, description, NULL);
  description->nativeRelationSetter(self);
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfClassP(testValue000)) {
      { Relation* self000 = self;
        Class* self = ((Class*)(self000));

        description->surrogateValueInverse = classLogicalType(self);
      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_STELLA_SLOT)) {
      { Relation* self001 = self;
        Slot* self = ((Slot*)(self001));

        description->surrogateValueInverse = self->slotSlotref;
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
  if (polymorphicRelationP(self)) {
    createBaseRelationForPolymorphicDescription(description);
  }
  return;
}

NamedDescription* createDescriptionForStellaRelation(Relation* self) {
  { Relation* super = NULL;
    Iterator* iter000 = directSuperrelations(self);

    while (iter000->nextP()) {
      super = ((Relation*)(iter000->value));
      if (((boolean)(super)) &&
          ((!isaP(super, SGT_DESCRIPTIONS_STELLA_CLASS)) ||
           logicClassP(((Class*)(super))))) {
        getDescription(super);
      }
    }
  }
  { NamedDescription* description = NULL;
    Module* homemodule = NULL;

    { Surrogate* testValue000 = safePrimaryType(self);

      if (subtypeOfClassP(testValue000)) {
        { Relation* self000 = self;
          Class* self = ((Class*)(self000));

          homemodule = classLogicalType(self)->homeModule();
        }
      }
      else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_STELLA_SLOT)) {
        { Relation* self001 = self;
          Slot* self = ((Slot*)(self001));

          homemodule = self->homeModule();
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    if (!(visibleFromP(oPL_KERNEL_MODULEo, homemodule))) {
      homemodule = oPL_KERNEL_MODULEo;
    }
    { Surrogate* testValue001 = safePrimaryType(self);

      if (subtypeOfClassP(testValue001)) {
        { Relation* self004 = self;
          Class* self = ((Class*)(self004));

          if (!logicClassP(self)) {
            { OutputStringStream* stream001 = newOutputStringStream();

              { 
                BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
                *(stream001->nativeStream) << "ERROR: " << "Can't use the class " << "`" << self << "'" << " as a logic class because it" << std::endl << "   does not inherit the top-level class THING." << "." << std::endl;
                helpSignalPropositionError(stream001, KWD_DESCRIPTIONS_ERROR);
              }
              throw *newPropositionError(stream001->theStringReader());
            }
          }
          description = createPrimitiveDescription(NIL_LIST, list(1, classLogicalType(self)), FALSE, TRUE, FALSE, homemodule);
        }
      }
      else if (subtypeOfP(testValue001, SGT_DESCRIPTIONS_STELLA_SLOT)) {
        { Relation* self005 = self;
          Slot* self = ((Slot*)(self005));

          { Surrogate* slotref = self->slotSlotref;
            Surrogate* superslotref = mostGeneralEquivalentSlotref(slotref);

            if (!(slotref == superslotref)) {
              self = ((Slot*)(superslotref->surrogateValue));
              if (((boolean)(((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL)))))) {
                return (((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL))));
              }
            }
          }
          { List* self008 = newList();

            self008->theConsList = slotColumnTypes(self, NULL_INTEGER);
            description = createPrimitiveDescription(NIL_LIST, self008, FALSE, FALSE, !booleanTypeP(self->slotBaseType), homemodule);
          }
        }
      }
      else {
        { OutputStringStream* stream002 = newOutputStringStream();

          *(stream002->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
          throw *newStellaException(stream002->theStringReader());
        }
      }
    }
    linkStellaRelationAndDescription(self, description);
    finalizeSuperrelationLinks(self);
    ensureDescriptionBody(description);
    return (description);
  }
}

NamedDescription* surrogateToDescription(Surrogate* self) {
  { Object* surrogatevalue = self->surrogateValue;

    if (!((boolean)(surrogatevalue))) {
      return (NULL);
    }
    if (isaP(surrogatevalue, SGT_DESCRIPTIONS_LOGIC_NAMED_DESCRIPTION)) {
      return (((NamedDescription*)(surrogatevalue)));
    }
    else {
      return (getDescription(self));
    }
  }
}

NamedDescription* getDescription(Object* self) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_NAMED_DESCRIPTION)) {
      { Object* self000 = self;
        NamedDescription* self = ((NamedDescription*)(self000));

        return (self);
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* self001 = self;
        Surrogate* self = ((Surrogate*)(self001));

        return (surrogateDgetDescription(self));
      }
    }
    else if (subtypeOfSymbolP(testValue000)) {
      { Object* self002 = self;
        Symbol* self = ((Symbol*)(self002));

        return (getDescription(symbolToSurrogate(self)));
      }
    }
    else if (subtypeOfStringP(testValue000)) {
      { Object* self003 = self;
        StringWrapper* self = ((StringWrapper*)(self003));

        return (stringDgetDescription(self->wrapperValue));
      }
    }
    else if (subtypeOfClassP(testValue000)) {
      { Object* self004 = self;
        Class* self = ((Class*)(self004));

        return (classDgetDescription(self));
      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_STELLA_SLOT)) {
      { Object* self005 = self;
        Slot* self = ((Slot*)(self005));

        return (slotDgetDescription(self));
      }
    }
    else {
      return (NULL);
    }
  }
}

NamedDescription* surrogateDgetDescription(Surrogate* self) {
  { Object* value = self->surrogateValue;
    ObjectStore* store = NULL;

    if (((boolean)(value))) {
      { Surrogate* testValue000 = safePrimaryType(value);

        if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_NAMED_DESCRIPTION)) {
          { Object* value000 = value;
            NamedDescription* value = ((NamedDescription*)(value000));

            return (value);
          }
        }
        else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_STELLA_RELATION)) {
          { Object* value001 = value;
            Relation* value = ((Relation*)(value001));

            if (((boolean)(((NamedDescription*)(dynamicSlotValue(value->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL)))))) {
              return (((NamedDescription*)(dynamicSlotValue(value->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL))));
            }
            else {
              return (createDescriptionForStellaRelation(value));
            }
          }
        }
        else {
          return (NULL);
        }
      }
    }
    else if (((boolean)(store = homeObjectStore(self)))) {
      return (store->fetchRelation(self));
    }
    else {
      return (NULL);
    }
  }
}

NamedDescription* stringDgetDescription(char* self) {
  { Surrogate* surrogate = lookupSurrogate(self);
    ObjectStore* store = NULL;

    if (((boolean)(surrogate))) {
      return (getDescription(surrogate));
    }
    else if (((boolean)(store = ((ObjectStore*)(dynamicSlotValue(oMODULEo.get()->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_OBJECT_STORE, NULL)))))) {
      return (store->fetchRelation(wrapString(self)));
    }
    else {
      return (NULL);
    }
  }
}

NamedDescription* classDgetDescription(Class* self) {
  if (((boolean)(((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL)))))) {
    return (((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL))));
  }
  else if (!logicClassP(self)) {
    if (!(oSUPPRESSNONLOGICOBJECTWARNINGpo.get())) {
      std::cout << "Reference to non-logic class: " << "`" << self->name() << "'" << std::endl << "Class must inherit 'THING' to be used by PowerLoom's logic." << std::endl << std::endl;
    }
    return (NULL);
  }
  else {
    return (getDescription(classLogicalType(self)));
  }
}

NamedDescription* slotDgetDescription(Slot* self) {
  if (((boolean)(((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL)))))) {
    return (((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL))));
  }
  else if (((boolean)(self->slotSlotref))) {
    return (getDescription(self->slotSlotref));
  }
  else {
    return (getDescription(lookupSlotref(self->slotOwner, self->slotName)));
  }
}

Surrogate* ensureDeferredDescription(Surrogate* self) {
  if ((!((boolean)(self->surrogateValue))) &&
      ((boolean)(homeObjectStore(self)))) {
    getDescription(self);
  }
  return (self);
}

boolean logicClassP(Class* self) {
  // Return TRUE if the class 'self' or one of its
  // supers supports indices that record extensions referenced by
  // the logic system. Also return true for literal classes.
  { boolean testValue000 = FALSE;

    if (((boolean)(((NamedDescription*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL)))))) {
      testValue000 = TRUE;
    }
    else {
      {
        { boolean foundP000 = FALSE;

          { Class* c = NULL;
            Cons* iter000 = self->classAllSuperClasses;

            while (!(iter000 == NIL)) {
              c = ((Class*)(iter000->value));
              iter000 = iter000->rest;
              if (((boolean)(((NamedDescription*)(dynamicSlotValue(c->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL))))) ||
                  (c == ((Class*)(SGT_DESCRIPTIONS_STELLA_THING->surrogateValue)))) {
                foundP000 = TRUE;
                break;
              }
            }
          }
          testValue000 = foundP000;
        }
        if (!testValue000) {
          testValue000 = (self == ((Class*)(SGT_DESCRIPTIONS_STELLA_THING->surrogateValue))) ||
              (subclassOfP(self, ((Class*)(SGT_DESCRIPTIONS_STELLA_LITERAL->surrogateValue))) ||
               (self == ((Class*)(SGT_DESCRIPTIONS_LOGIC_PROPOSITION->surrogateValue))));
        }
      }
    }
    if (testValue000) {
      return (TRUE);
    }
  }
  if (!self->classFinalizedP) {
    { List* badsupers = collectBadSuperClasses(self->classType, list(0));

      if (badsupers->emptyP()) {
        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(STANDARD_WARNING->nativeStream) << "WARNING: " << "Could not determine whether " << self << " is a logic class, " << "because it is not finalized." << std::endl;
          helpSignalPropositionError(STANDARD_WARNING, KWD_DESCRIPTIONS_WARNING);
        }
      }
      else {
        { 
          BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
          *(STANDARD_WARNING->nativeStream) << "WARNING: " << "Could not determine whether " << self << " is a logic class, " << "because it is not finalized." << std::endl << "   It has these undefined or bad supers: " << badsupers->theConsList << std::endl;
          helpSignalPropositionError(STANDARD_WARNING, KWD_DESCRIPTIONS_WARNING);
        }
      }
    }
  }
  return (FALSE);
}

boolean variableArityDomainTypesNextP(AllPurposeIterator* self) {
  { Iterator* nestediterator = self->iteratorNestedIterator;

    if (((boolean)(nestediterator)) &&
        nestediterator->nextP()) {
      self->value = nestediterator->value;
    }
    else {
      {
        self->iteratorNestedIterator = NULL;
        self->value = self->iteratorObject;
      }
    }
    return (TRUE);
  }
}

Iterator* allDomainTypes(NamedDescription* self) {
  { Iterator* iterator = (functionDescriptionP(self) ? ((Iterator*)(self->ioVariableTypes->butLast())) : ((ListIterator*)(self->ioVariableTypes->allocateIterator())));

    if (variableArityP(self)) {
      { AllPurposeIterator* allpurposeiterator = newAllPurposeIterator();

        allpurposeiterator->iteratorNextCode = ((cpp_function_code)(&variableArityDomainTypesNextP));
        allpurposeiterator->iteratorNestedIterator = iterator;
        iterator = allpurposeiterator;
      }
    }
    return (iterator);
  }
}

// Table mapping logic variable names to variables or skolems.
// Used during construction of a proposition or description.
DEFINE_STELLA_SPECIAL(oLOGICVARIABLETABLEo, Cons* , NULL);

void pushLogicVariableBinding(Skolem* variable) {
  if (anonymousVariableP(variable)) {
    { OutputStringStream* stream000 = newOutputStringStream();

      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
        *(stream000->nativeStream) << "ERROR: " << "Illegal nameless variable '?' found in list of\nquantified variables." << std::endl << "   Quantified variables must have names." << "." << std::endl;
        helpSignalPropositionError(stream000, KWD_DESCRIPTIONS_ERROR);
      }
      throw *newPropositionError(stream000->theStringReader());
    }
  }
  oLOGICVARIABLETABLEo.set(cons(variable, oLOGICVARIABLETABLEo.get()));
}

void popLogicVariableBinding() {
  { Cons* headcons = oLOGICVARIABLETABLEo.get();

    oLOGICVARIABLETABLEo.set(headcons->rest);
    headcons->free();
  }
}

void popLogicVariableBindings(Cons* variables) {
  { int i = NULL_INTEGER;
    int iter000 = 1;
    int upperBound000 = variables->length();

    while (iter000 <= upperBound000) {
      i = iter000;
      iter000 = iter000 + 1;
      i = i;
      popLogicVariableBinding();
    }
  }
}

Object* lookupLogicVariableBinding(Symbol* variablename) {
  if (((boolean)(oLOGICVARIABLETABLEo.get()))) {
    { Skolem* vbl = NULL;
      Cons* iter000 = oLOGICVARIABLETABLEo.get();

      while (!(iter000 == NIL)) {
        vbl = ((Skolem*)(iter000->value));
        iter000 = iter000->rest;
        if (vbl->skolemName == variablename) {
          return (vbl);
        }
      }
    }
  }
  return (NULL);
}

// List of propositions extracted from parsing
// a list of quantified, typed variables.
DEFINE_STELLA_SPECIAL(oVARIABLETYPEPROPOSITIONSo, Cons* , NULL);

void parseOneVariableDeclaration(Object* vdec, List* localdeclarations) {
  { Symbol* variablename = NULL;
    Cons* isatree = NULL;
    PatternVariable* variable = NULL;

    { Surrogate* testValue000 = safePrimaryType(vdec);

      if (testValue000 == SGT_DESCRIPTIONS_STELLA_CONS) {
        { Object* vdec000 = vdec;
          Cons* vdec = ((Cons*)(vdec000));

          variablename = ((Symbol*)(vdec->rest->value));
          isatree = vdec;
        }
      }
      else if (subtypeOfSymbolP(testValue000)) {
        { Object* vdec001 = vdec;
          Symbol* vdec = ((Symbol*)(vdec001));

          variablename = vdec;
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    { PatternVariable* v = NULL;
      Cons* iter000 = localdeclarations->theConsList;

      while (!(iter000 == NIL)) {
        v = ((PatternVariable*)(iter000->value));
        iter000 = iter000->rest;
        if (v->skolemName == variablename) {
          variable = v;
        }
      }
    }
    if (!((boolean)(variable))) {
      variable = createVariable(NULL, variablename, TRUE);
    }
    pushLogicVariableBinding(variable);
    localdeclarations->insertLast(variable);
    if (((boolean)(isatree))) {
      { Proposition* proposition = buildTopLevelProposition(isatree, FALSE);

        if (!((boolean)(proposition))) {
          { OutputStringStream* stream001 = newOutputStringStream();

            { 
              BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
              *(stream001->nativeStream) << "ERROR: " << "Error in declarations" << "." << std::endl;
              helpSignalPropositionError(stream001, KWD_DESCRIPTIONS_ERROR);
            }
            throw *newPropositionError(stream001->theStringReader());
          }
        }
        if (proposition->kind == KWD_DESCRIPTIONS_ISA) {
          setDynamicSlotValue(proposition->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_VARIABLE_TYPEp, TRUE_WRAPPER, NULL);
          updateSkolemType(((Skolem*)((proposition->arguments->theArray)[0])), ((Surrogate*)(proposition->operatoR)));
          oVARIABLETYPEPROPOSITIONSo.set(cons(proposition, oVARIABLETYPEPROPOSITIONSo.get()));
        }
      }
    }
  }
}

Cons* parseLogicVariableDeclarations(Object* tree) {
  { Cons* constree = (isaP(tree, SGT_DESCRIPTIONS_STELLA_CONS) ? ((Cons*)(tree)) : consList(1, tree));
    List* declarations = newList();

    { Object* term = NULL;
      Cons* iter000 = constree;

      while (!(iter000 == NIL)) {
        term = iter000->value;
        iter000 = iter000->rest;
        parseOneVariableDeclaration(term, declarations);
      }
    }
    return (declarations->theConsList);
  }
}

Cons* helpBuildQuantifiedProposition(Cons* tree, boolean converttypestoconstraintsP, Proposition*& _Return1, Proposition*& _Return2) {
  { 
    BIND_STELLA_SPECIAL(oVARIABLETYPEPROPOSITIONSo, Cons*, NIL);
    { Object* quantifier = tree->value;
      Object* antecedentclause = tree->rest->rest->value;
      Object* consequentclause = tree->fourth();
      Cons* variables = NULL;
      Proposition* antecedentproposition = NULL;
      Proposition* consequentproposition = NULL;

      variables = parseLogicVariableDeclarations(tree->rest->value);
      if (((boolean)(antecedentclause))) {
        antecedentproposition = ((Proposition*)(buildProposition(antecedentclause)));
      }
      if (((boolean)(consequentclause))) {
        consequentproposition = ((Proposition*)(buildProposition(consequentclause)));
      }
      popLogicVariableBindings(variables);
      if (converttypestoconstraintsP) {
        if (!(oVARIABLETYPEPROPOSITIONSo.get() == NIL)) {
          if (((boolean)(antecedentproposition))) {
            oVARIABLETYPEPROPOSITIONSo.set(cons(antecedentproposition, oVARIABLETYPEPROPOSITIONSo.get()));
          }
          oVARIABLETYPEPROPOSITIONSo.set(oVARIABLETYPEPROPOSITIONSo.get()->reverse()->removeDuplicates());
          antecedentproposition = conjoinPropositions(oVARIABLETYPEPROPOSITIONSo.get());
        }
      }
      _Return1 = antecedentproposition;
      _Return2 = consequentproposition;
      return (variables);
    }
  }
}

Cons* buildQuantifiedProposition(Cons* tree, boolean converttypestoconstraintsP, Proposition*& _Return1, Proposition*& _Return2) {
  if (((GeneralizedSymbol*)(tree->value)) == SYM_DESCRIPTIONS_STELLA_EXISTS) {
    { 
      BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_DESCRIPTIONS_DESCRIPTION);
      return (helpBuildQuantifiedProposition(tree, converttypestoconstraintsP, _Return1, _Return2));
    }
  }
  else {
    { 
      BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_DESCRIPTIONS_DESCRIPTION);
      return (helpBuildQuantifiedProposition(tree, converttypestoconstraintsP, _Return1, _Return2));
    }
  }
}

Vector* copyConsListToVariablesVector(Cons* conslist) {
  if (conslist == NIL) {
    return (ZERO_VARIABLES_VECTOR);
  }
  { Vector* vector = newVector(conslist->length());

    { Object* t = NULL;
      int i = NULL_INTEGER;
      Cons* iter000 = conslist;
      int iter001 = 0;

      while (!(iter000 == NIL)) {
        t = iter000->value;
        iter000 = iter000->rest;
        i = iter001;
        iter001 = iter001 + 1;
        (vector->theArray)[i] = (((PatternVariable*)(t)));
      }
    }
    return (vector);
  }
}

boolean equivalentHoldsPropositionP(Proposition* self, Proposition* other, KeyValueList* mapping) {
  { boolean testValue000 = FALSE;

    testValue000 = equivalentFormulaeP((self->arguments->theArray)[0], other->operatoR, mapping);
    if (testValue000) {
      testValue000 = (self->arguments->length() - 1) == other->arguments->length();
      if (testValue000) {
        { boolean alwaysP000 = TRUE;

          { int i1 = NULL_INTEGER;
            Object* arg2 = NULL;
            int iter000 = 1;
            Vector* vector000 = other->arguments;
            int index000 = 0;
            int length000 = vector000->length();

            while (index000 < length000) {
              i1 = iter000;
              iter000 = iter000 + 1;
              arg2 = (vector000->theArray)[index000];
              index000 = index000 + 1;
              if (!equivalentFormulaeP((self->arguments->theArray)[i1], arg2, mapping)) {
                alwaysP000 = FALSE;
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

boolean equivalentCommutativePropositionsP(Proposition* self, Proposition* other, KeyValueList* mapping) {
  { boolean testValue000 = FALSE;

    testValue000 = self->operatoR == other->operatoR;
    if (testValue000) {
      testValue000 = self->arguments->length() == other->arguments->length();
      if (testValue000) {
        { boolean alwaysP000 = TRUE;

          { Object* arg1 = NULL;
            Vector* vector000 = self->arguments;
            int index000 = 0;
            int length000 = vector000->length();

            while (index000 < length000) {
              arg1 = (vector000->theArray)[index000];
              index000 = index000 + 1;
              { boolean testValue001 = FALSE;

                { boolean foundP000 = FALSE;

                  { Object* arg2 = NULL;
                    Vector* vector001 = other->arguments;
                    int index001 = 0;
                    int length001 = vector001->length();

                    while (index001 < length001) {
                      arg2 = (vector001->theArray)[index001];
                      index001 = index001 + 1;
                      if (equivalentFormulaeP(arg1, arg2, mapping)) {
                        foundP000 = TRUE;
                        break;
                      }
                    }
                  }
                  testValue001 = foundP000;
                }
                testValue001 = !testValue001;
                if (testValue001) {
                  alwaysP000 = FALSE;
                  break;
                }
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

boolean equivalentPropositionsP(Proposition* self, Proposition* other, KeyValueList* mapping) {
  if (self == other) {
    return (TRUE);
  }
  if (!(self->kind == other->kind)) {
    return (FALSE);
  }
  { Keyword* testValue000 = self->kind;

    if ((testValue000 == KWD_DESCRIPTIONS_AND) ||
        ((testValue000 == KWD_DESCRIPTIONS_OR) ||
         (testValue000 == KWD_DESCRIPTIONS_EQUIVALENT))) {
      return (equivalentCommutativePropositionsP(self, other, mapping));
    }
    else {
      { Keyword* testValue001 = self->kind;

        if ((testValue001 == KWD_DESCRIPTIONS_FORALL) ||
            (testValue001 == KWD_DESCRIPTIONS_EXISTS)) {
          { Vector* iovars1 = ((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES, NULL)));
            Vector* iovars2 = ((Vector*)(dynamicSlotValue(other->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES, NULL)));

            if (!(iovars1->length() == iovars2->length())) {
              return (FALSE);
            }
            if (!((boolean)(mapping))) {
              mapping = newKeyValueList();
            }
            { PatternVariable* v1 = NULL;
              PatternVariable* v2 = NULL;
              Vector* vector000 = iovars1;
              int index000 = 0;
              int length000 = vector000->length();
              Vector* vector001 = iovars2;
              int index001 = 0;
              int length001 = vector001->length();

              while ((index000 < length000) &&
                  (index001 < length001)) {
                v1 = ((PatternVariable*)((vector000->theArray)[index000]));
                index000 = index000 + 1;
                v2 = ((PatternVariable*)((vector001->theArray)[index001]));
                index001 = index001 + 1;
                mapping->insertAt(v1, v2);
              }
            }
          }
        }
        else {
        }
      }
      { boolean testValue002 = FALSE;

        testValue002 = self->operatoR == other->operatoR;
        if (testValue002) {
          { boolean alwaysP000 = TRUE;

            { Object* arg1 = NULL;
              Object* arg2 = NULL;
              Vector* vector002 = self->arguments;
              int index002 = 0;
              int length002 = vector002->length();
              Vector* vector003 = other->arguments;
              int index003 = 0;
              int length003 = vector003->length();

              while ((index002 < length002) &&
                  (index003 < length003)) {
                arg1 = (vector002->theArray)[index002];
                index002 = index002 + 1;
                arg2 = (vector003->theArray)[index003];
                index003 = index003 + 1;
                if (!equivalentFormulaeP(arg1, arg2, mapping)) {
                  alwaysP000 = FALSE;
                  break;
                }
              }
            }
            testValue002 = alwaysP000;
          }
          if (testValue002) {
            testValue002 = self->arguments->length() == other->arguments->length();
          }
        }
        if (!testValue002) {
          testValue002 = ((boolean)(mapping)) &&
              ((self->operatoR == SGT_DESCRIPTIONS_PL_KERNEL_KB_HOLDS) &&
               equivalentHoldsPropositionP(self, other, mapping));
        }
        { boolean value000 = testValue002;

          return (value000);
        }
      }
    }
  }
}

boolean equivalentFunctionPropositionsP(Proposition* self, Proposition* other, KeyValueList* mapping) {
  if ((self->kind == KWD_DESCRIPTIONS_FUNCTION) &&
      (other->kind == KWD_DESCRIPTIONS_FUNCTION)) {
    if (!((boolean)(mapping))) {
      mapping = newKeyValueList();
    }
    mapping->insertAt((self->arguments->theArray)[(self->arguments->length() - 1)], (other->arguments->theArray)[(other->arguments->length() - 1)]);
    return (equivalentPropositionsP(self, other, mapping));
  }
  return (FALSE);
}

boolean equivalentDescriptionsP(Description* self, Description* other, KeyValueList* mapping) {
  if (self == other) {
    return (TRUE);
  }
  if (((boolean)(self->descriptionName())) &&
      ((boolean)(other->descriptionName()))) {
    return (FALSE);
  }
  if (!(self->arity() == other->arity())) {
    return (FALSE);
  }
  if (namedDescriptionP(self)) {
    return (FALSE);
  }
  else {
    if (!((boolean)(mapping))) {
      mapping = newKeyValueList();
    }
    { PatternVariable* v1 = NULL;
      PatternVariable* v2 = NULL;
      Vector* vector000 = self->ioVariables;
      int index000 = 0;
      int length000 = vector000->length();
      Vector* vector001 = other->ioVariables;
      int index001 = 0;
      int length001 = vector001->length();

      while ((index000 < length000) &&
          (index001 < length001)) {
        v1 = ((PatternVariable*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        v2 = ((PatternVariable*)((vector001->theArray)[index001]));
        index001 = index001 + 1;
        mapping->insertAt(v1, v2);
      }
    }
    { PatternVariable* v1 = NULL;
      PatternVariable* v2 = NULL;
      Vector* vector002 = self->internalVariables;
      int index002 = 0;
      int length002 = vector002->length();
      Vector* vector003 = other->internalVariables;
      int index003 = 0;
      int length003 = vector003->length();

      while ((index002 < length002) &&
          (index003 < length003)) {
        v1 = ((PatternVariable*)((vector002->theArray)[index002]));
        index002 = index002 + 1;
        v2 = ((PatternVariable*)((vector003->theArray)[index003]));
        index003 = index003 + 1;
        mapping->insertAt(v1, v2);
      }
    }
    return (equivalentFormulaeP(self->proposition, other->proposition, mapping));
  }
}

boolean equivalentEnumerationsP(Collection* self, Collection* other) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_STELLA_SET)) {
      { Collection* self000 = self;
        Set* self = ((Set*)(self000));

        { boolean testValue001 = FALSE;

          testValue001 = self->length() == other->length();
          if (testValue001) {
            { boolean alwaysP000 = TRUE;

              { Object* m = NULL;
                ListIterator* iter000 = ((ListIterator*)(self->allocateIterator()));

                while (iter000->nextP()) {
                  m = iter000->value;
                  if (!other->memberP(m)) {
                    alwaysP000 = FALSE;
                    break;
                  }
                }
              }
              testValue001 = alwaysP000;
            }
          }
          { boolean value000 = testValue001;

            return (value000);
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_STELLA_LIST)) {
      { Collection* self001 = self;
        List* self = ((List*)(self001));

        { boolean testValue002 = FALSE;

          testValue002 = self->length() == other->length();
          if (testValue002) {
            { boolean alwaysP001 = TRUE;

              { Object* m = NULL;
                Cons* iter001 = self->theConsList;

                while (!(iter001 == NIL)) {
                  m = iter001->value;
                  iter001 = iter001->rest;
                  if (!other->memberP(m)) {
                    alwaysP001 = FALSE;
                    break;
                  }
                }
              }
              testValue002 = alwaysP001;
            }
          }
          { boolean value001 = testValue002;

            return (value001);
          }
        }
      }
    }
    else {
      return (FALSE);
    }
  }
}

boolean equivalentFormulaeP(Object* self, Object* other, KeyValueList* mapping) {
  { Object* surrogatevalue = NULL;

    if (isaP(self, SGT_DESCRIPTIONS_STELLA_SURROGATE)) {
      surrogatevalue = ((Surrogate*)(self))->surrogateValue;
      if (((boolean)(surrogatevalue))) {
        self = surrogatevalue;
      }
    }
    if (isaP(other, SGT_DESCRIPTIONS_STELLA_SURROGATE)) {
      surrogatevalue = ((Surrogate*)(other))->surrogateValue;
      if (((boolean)(surrogatevalue))) {
        other = surrogatevalue;
      }
    }
  }
  if (((boolean)(mapping)) &&
      eqlP(other, mapping->lookup(self))) {
    return (TRUE);
  }
  if (equalP(self, other)) {
    return (TRUE);
  }
  if (((boolean)(mapping))) {
    if (oUNIFY_PROPOSITIONSpo.get() &&
        (variableP(self) ||
         variableP(other))) {
      if (!((boolean)(oQUERYITERATORo.get()))) {
        mapping->insertAt(self, other);
        return (TRUE);
      }
      { Object* value1 = argumentBoundTo(self);
        Object* value2 = argumentBoundTo(other);

        if ((!((boolean)(value1))) ||
            (!((boolean)(value2)))) {
          mapping->insertAt(self, other);
          return (TRUE);
        }
        else {
          return (equalP(value1, value2));
        }
      }
    }
  }
  if (!(self->primaryType() == other->primaryType())) {
    return (FALSE);
  }
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PROPOSITION)) {
      { Object* self000 = self;
        Proposition* self = ((Proposition*)(self000));

        return (equivalentPropositionsP(self, ((Proposition*)(other)), mapping));
      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_DESCRIPTION)) {
      { Object* self001 = self;
        Description* self = ((Description*)(self001));

        return (equivalentDescriptionsP(self, ((Description*)(other)), mapping));
      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_STELLA_SET)) {
      { Object* self002 = self;
        Set* self = ((Set*)(self002));

        return (equivalentEnumerationsP(self, ((Collection*)(other))));
      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_STELLA_LIST)) {
      { Object* self003 = self;
        List* self = ((List*)(self003));

        return (equivalentEnumerationsP(self, ((Collection*)(other))));
      }
    }
    else {
      return (FALSE);
    }
  }
}

boolean sameArgumentsP(Vector* variables, Vector* arguments) {
  { boolean testValue000 = FALSE;

    { boolean alwaysP000 = TRUE;

      { PatternVariable* v = NULL;
        Object* arg = NULL;
        Vector* vector000 = variables;
        int index000 = 0;
        int length000 = vector000->length();
        Vector* vector001 = arguments;
        int index001 = 0;
        int length001 = vector001->length();

        while ((index000 < length000) &&
            (index001 < length001)) {
          v = ((PatternVariable*)((vector000->theArray)[index000]));
          index000 = index000 + 1;
          arg = (vector001->theArray)[index001];
          index001 = index001 + 1;
          if (!(v == arg)) {
            alwaysP000 = FALSE;
            break;
          }
        }
      }
      testValue000 = alwaysP000;
    }
    if (testValue000) {
      testValue000 = variables->length() == arguments->length();
    }
    { boolean value000 = testValue000;

      return (value000);
    }
  }
}

DEFINE_STELLA_SPECIAL(oUNIFY_PROPOSITIONSpo, boolean , FALSE);

boolean unifyPropositionsP(Proposition* self, Proposition* other, KeyValueList* mapping) {
  { 
    BIND_STELLA_SPECIAL(oUNIFY_PROPOSITIONSpo, boolean, TRUE);
    return (equivalentPropositionsP(self, other, mapping));
  }
}

boolean namedDescriptionP(Description* self) {
  return (((boolean)(self->surrogateValueInverse)));
}

LogicObject* Description::findDuplicateNamedDescription() {
  { Description* self = this;

    if (namedDescriptionP(self)) {
      return (self);
    }
    { Proposition* proposition = self->proposition;

      { Keyword* testValue000 = proposition->kind;

        if (testValue000 == KWD_DESCRIPTIONS_AND) {
          { Proposition* onlygoal = NULL;

            { Object* arg = NULL;
              Vector* vector000 = proposition->arguments;
              int index000 = 0;
              int length000 = vector000->length();

              while (index000 < length000) {
                arg = (vector000->theArray)[index000];
                index000 = index000 + 1;
                if (coerceWrappedBooleanToBoolean(((Proposition*)(arg))->variableTypeP_reader())) {
                }
                else if (((boolean)(onlygoal))) {
                  return (NULL);
                }
                else {
                  onlygoal = ((Proposition*)(arg));
                }
              }
            }
            if (((boolean)(onlygoal)) &&
                sameArgumentsP(self->ioVariables, ((onlygoal->kind == KWD_DESCRIPTIONS_NOT) ? ((Proposition*)((onlygoal->arguments->theArray)[0]))->arguments : onlygoal->arguments))) {
              return (extractGoalDescription(onlygoal, NULL));
            }
          }
        }
        else if (testValue000 == KWD_DESCRIPTIONS_NOT) {
          if (sameArgumentsP(self->ioVariables, ((Proposition*)((proposition->arguments->theArray)[0]))->arguments)) {
            return (extractGoalDescription(proposition, NULL));
          }
        }
        else {
          if (sameArgumentsP(self->ioVariables, proposition->arguments)) {
            return (extractGoalDescription(proposition, NULL));
          }
        }
      }
      return (NULL);
    }
  }
}

// Contains a table of unnamed descriptions, indexed by the
// stringification of their propositions.  Tricky: Descriptions in two
// different modules could have the same stringification but be different.
StringHashTable* oSTRINGIFIED_DESCRIPTION_INDEXo = NULL;

boolean deletedLogicObjectP(LogicObject* self) {
  return (self->deletedP());
}

void uniquifyDescriptionVariables(Description* self) {
  { Cons* variablenames = SYSTEM_DEFINED_ARGUMENT_NAMES;

    if ((self->ioVariables->length() + self->internalVariables->length()) > variablenames->length()) {
      return;
    }
    { PatternVariable* v = NULL;
      Vector* vector000 = self->ioVariables;
      int index000 = 0;
      int length000 = vector000->length();

      while (index000 < length000) {
        v = ((PatternVariable*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        if (!((boolean)(((Symbol*)(dynamicSlotValue(v->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME, NULL)))))) {
          setDynamicSlotValue(v->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME, v->skolemName, NULL);
          { Symbol* head000 = ((Symbol*)(variablenames->value));

            variablenames = variablenames->rest;
            v->skolemName = head000;
          }
        }
      }
    }
    { PatternVariable* v = NULL;
      Vector* vector001 = self->internalVariables;
      int index001 = 0;
      int length001 = vector001->length();

      while (index001 < length001) {
        v = ((PatternVariable*)((vector001->theArray)[index001]));
        index001 = index001 + 1;
        if (!((boolean)(((Symbol*)(dynamicSlotValue(v->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME, NULL)))))) {
          setDynamicSlotValue(v->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME, v->skolemName, NULL);
          { Symbol* head001 = ((Symbol*)(variablenames->value));

            variablenames = variablenames->rest;
            v->skolemName = head001;
          }
        }
      }
    }
  }
}

void restoreDescriptionVariableNames(Description* self) {
  if (self->ioVariables->length() == 0) {
    return;
  }
  if (!((boolean)(((Symbol*)(dynamicSlotValue(((PatternVariable*)((self->ioVariables->theArray)[0]))->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME, NULL)))))) {
    return;
  }
  { PatternVariable* v = NULL;
    Vector* vector000 = self->ioVariables;
    int index000 = 0;
    int length000 = vector000->length();

    while (index000 < length000) {
      v = ((PatternVariable*)((vector000->theArray)[index000]));
      index000 = index000 + 1;
      if (((boolean)(((Symbol*)(dynamicSlotValue(v->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME, NULL)))))) {
        v->skolemName = ((Symbol*)(dynamicSlotValue(v->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME, NULL)));
        setDynamicSlotValue(v->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME, NULL, NULL);
      }
    }
  }
  { PatternVariable* v = NULL;
    Vector* vector001 = self->internalVariables;
    int index001 = 0;
    int length001 = vector001->length();

    while (index001 < length001) {
      v = ((PatternVariable*)((vector001->theArray)[index001]));
      index001 = index001 + 1;
      if (((boolean)(((Symbol*)(dynamicSlotValue(v->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME, NULL)))))) {
        v->skolemName = ((Symbol*)(dynamicSlotValue(v->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME, NULL)));
        setDynamicSlotValue(v->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME, NULL, NULL);
      }
    }
  }
}

boolean consTreeLessThanP(Object* tree1, Object* tree2) {
  if ((!((boolean)(tree1))) ||
      (!((boolean)(tree2)))) {
    return (FALSE);
  }
  { Surrogate* type1 = tree1->primaryType();
    Surrogate* type2 = tree2->primaryType();

    if (!(type1 == type2)) {
      return (type1->symbolId < type2->symbolId);
    }
    { Surrogate* testValue000 = safePrimaryType(tree1);

      if (testValue000 == SGT_DESCRIPTIONS_STELLA_CONS) {
        { Object* tree1000 = tree1;
          Cons* tree1 = ((Cons*)(tree1000));

          { Cons* cons2 = ((Cons*)(tree2));

            if (!(tree1->length() == cons2->length())) {
              return (tree1->length() < cons2->length());
            }
            { Object* v1 = NULL;
              Object* v2 = NULL;
              Cons* iter000 = tree1;
              Cons* iter001 = cons2;

              while ((!(iter000 == NIL)) &&
                  (!(iter001 == NIL))) {
                v1 = iter000->value;
                iter000 = iter000->rest;
                v2 = iter001->value;
                iter001 = iter001->rest;
                if (consTreeLessThanP(v1, v2)) {
                  return (TRUE);
                }
                else if (consTreeLessThanP(v2, v1)) {
                  return (FALSE);
                }
              }
            }
            return (FALSE);
          }
        }
      }
      else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_STELLA_GENERALIZED_SYMBOL)) {
        { Object* tree1001 = tree1;
          GeneralizedSymbol* tree1 = ((GeneralizedSymbol*)(tree1001));

          return (tree1->symbolId < ((GeneralizedSymbol*)(tree2))->symbolId);
        }
      }
      else if (subtypeOfIntegerP(testValue000)) {
        { Object* tree1002 = tree1;
          IntegerWrapper* tree1 = ((IntegerWrapper*)(tree1002));

          return (wrappedIntegerLessThanP(tree1, ((IntegerWrapper*)(tree2))));
        }
      }
      else if (subtypeOfStringP(testValue000)) {
        { Object* tree1003 = tree1;
          StringWrapper* tree1 = ((StringWrapper*)(tree1003));

          return (wrappedStringLessThanP(tree1, ((StringWrapper*)(tree2))));
        }
      }
      else if (subtypeOfFloatP(testValue000)) {
        { Object* tree1004 = tree1;
          FloatWrapper* tree1 = ((FloatWrapper*)(tree1004));

          return (wrappedFloatLessThanP(tree1, ((FloatWrapper*)(tree2))));
        }
      }
      else {
        return (!eqlP(tree1, tree2));
      }
    }
  }
}

Cons* sortPropositionClauses(Cons* clauses) {
  { Cons* canonicalclauses = NIL;

    { Object* c = NULL;
      Cons* iter000 = clauses;

      while (!(iter000 == NIL)) {
        c = iter000->value;
        iter000 = iter000->rest;
        canonicalclauses = cons(uniquifyPropositionTree(c), canonicalclauses);
      }
    }
    return (canonicalclauses->sort(((cpp_function_code)(&consTreeLessThanP))));
  }
}

Object* uniquifyPropositionTree(Object* tree) {
  if (!((boolean)(tree))) {
    return (tree);
  }
  if (safePrimaryType(tree) == SGT_DESCRIPTIONS_STELLA_CONS) {
    { Object* tree000 = tree;
      Cons* tree = ((Cons*)(tree000));

      { GeneralizedSymbol* testValue000 = ((GeneralizedSymbol*)(tree->value));

        if ((testValue000 == SYM_DESCRIPTIONS_STELLA_AND) ||
            (testValue000 == SYM_DESCRIPTIONS_STELLA_OR)) {
          tree->rest = sortPropositionClauses(tree->rest);
        }
        else if (testValue000 == SYM_DESCRIPTIONS_STELLA_NOT) {
          tree->secondSetter(uniquifyPropositionTree(tree->rest->value));
        }
        else if (testValue000 == SYM_DESCRIPTIONS_STELLA_EXISTS) {
          tree->thirdSetter(uniquifyPropositionTree(tree->rest->rest->value));
        }
        else if (testValue000 == SYM_DESCRIPTIONS_STELLA_FORALL) {
          tree->thirdSetter(uniquifyPropositionTree(tree->rest->rest->value));
          if (((boolean)(tree->fourth()))) {
            tree->fourthSetter(uniquifyPropositionTree(tree->fourth()));
          }
        }
        else {
        }
      }
    }
  }
  else {
  }
  return (tree);
}

Description* findExactDuplicateDescription(Description* self) {
  uniquifyDescriptionVariables(self);
  { char* stringification = stringify(uniquifyPropositionTree(generateProposition(self->proposition)));
    List* bucket = ((List*)(oSTRINGIFIED_DESCRIPTION_INDEXo->lookup(stringification)));

    restoreDescriptionVariableNames(self);
    if (!((boolean)(bucket))) {
      oSTRINGIFIED_DESCRIPTION_INDEXo->insertAt(stringification, list(1, self));
      return (NULL);
    }
    bucket->removeIf(((cpp_function_code)(&deletedLogicObjectP)));
    { Description* d = NULL;
      Cons* iter000 = bucket->theConsList;

      while (!(iter000 == NIL)) {
        d = ((Description*)(iter000->value));
        iter000 = iter000->rest;
        if (equivalentDescriptionsP(self, d, NULL) &&
            ((self->homeContext == d->homeContext) ||
             self->homeContext->allSuperContexts->membP(d->homeContext))) {
          return (d);
        }
      }
    }
    bucket->push(self);
    return (NULL);
  }
}

void helpCollectConstantReferences(Object* self, List* collection, boolean stopatoneP) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PROPOSITION)) {
      { Object* self000 = self;
        Proposition* self = ((Proposition*)(self000));

        { Object* arg = NULL;
          Vector* vector000 = self->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          while (index000 < length000) {
            arg = (vector000->theArray)[index000];
            index000 = index000 + 1;
            helpCollectConstantReferences(arg, collection, stopatoneP);
            if (stopatoneP &&
                collection->nonEmptyP()) {
              return;
            }
          }
        }
      }
    }
    else if (subtypeOfSurrogateP(testValue000)) {
      { Object* self001 = self;
        Surrogate* self = ((Surrogate*)(self001));

        helpCollectConstantReferences(self->surrogateValue, collection, stopatoneP);
      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
      { Object* self002 = self;
        PatternVariable* self = ((PatternVariable*)(self002));

      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_DESCRIPTION)) {
      { Object* self003 = self;
        Description* self = ((Description*)(self003));

        helpCollectConstantReferences(self->proposition, collection, stopatoneP);
      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_LOGIC_OBJECT)) {
      { Object* self004 = self;
        LogicObject* self = ((LogicObject*)(self004));

        collection->insertNew(self);
      }
    }
    else {
    }
  }
}

List* collectConstantDescriptionReferences(Description* self, List* collection, boolean stopatoneP) {
  if (!((boolean)(collection))) {
    collection = newList();
  }
  helpCollectConstantReferences(self->proposition, collection, stopatoneP);
  return (collection);
}

Description* findDuplicateDescriptionWithConstantReference(Description* self) {
  { LogicObject* referencedconstant = ((LogicObject*)(collectConstantDescriptionReferences(self, NULL, TRUE)->first()));

    if (((boolean)(referencedconstant))) {
      { KeyValueList* mapping = NULL;

        if (((boolean)(((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_EXTERNAL_VARIABLES, NULL)))))) {
          if (!((boolean)(oQUERYITERATORo.get()))) {
            return (NULL);
          }
          { PatternVariable* v = NULL;
            Vector* vector000 = ((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_EXTERNAL_VARIABLES, NULL)));
            int index000 = 0;
            int length000 = vector000->length();

            while (index000 < length000) {
              v = ((PatternVariable*)((vector000->theArray)[index000]));
              index000 = index000 + 1;
              { Object* binding = argumentBoundTo(v);

                if (!((boolean)(binding))) {
                  return (NULL);
                }
                mapping->insertAt(v, binding);
              }
            }
          }
        }
        { Description* dep = NULL;
          Cons* iter000 = referencedconstant->dependentDescriptions_reader()->theConsList;

          while (!(iter000 == NIL)) {
            dep = ((Description*)(iter000->value));
            iter000 = iter000->rest;
            if ((!dep->deletedP()) &&
                equivalentDescriptionsP(dep, self, mapping)) {
              return (dep);
            }
          }
        }
      }
    }
    return (NULL);
  }
}

Description* findDuplicateDescription(Description* self) {
  { Description* duplicate = NULL;

    if (namedDescriptionP(self)) {
      {
        return (NULL);
      }
    }
    else {
      { 
        duplicate = ((Description*)(self->findDuplicateNamedDescription()));
        if (((boolean)(duplicate))) {
          {
            return (duplicate);
          }
        }
        else {
          { 
            duplicate = findExactDuplicateDescription(self);
            if (((boolean)(duplicate))) {
              {
                return (duplicate);
              }
            }
            else {
              {
                return (NULL);
              }
            }
          }
        }
      }
    }
  }
}

void addDependentDescriptionLink(Object* self, Description* description) {
  if (subtypeOfP(safePrimaryType(self), SGT_DESCRIPTIONS_LOGIC_LOGIC_OBJECT)) {
    { Object* self000 = self;
      LogicObject* self = ((LogicObject*)(self000));

      { List* dependents = self->dependentDescriptions_reader();

        if (dependents == NIL_LIST) {
          setDynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DEPENDENT_DESCRIPTIONS, newList(), NULL);
        }
        self->dependentDescriptions_reader()->insertNew(description);
      }
    }
  }
  else {
  }
}

void fastenDownDescription(Description* self) {
  { LogicObject* ref = NULL;
    Cons* iter000 = collectConstantDescriptionReferences(self, NULL, FALSE)->theConsList;

    while (!(iter000 == NIL)) {
      ref = ((LogicObject*)(iter000->value));
      iter000 = iter000->rest;
      addDependentDescriptionLink(ref, self);
    }
  }
}

boolean containsNestedArgumentP(Proposition* proposition) {
  { Keyword* testValue000 = proposition->kind;

    if ((testValue000 == KWD_DESCRIPTIONS_ISA) ||
        ((testValue000 == KWD_DESCRIPTIONS_FUNCTION) ||
         ((testValue000 == KWD_DESCRIPTIONS_PREDICATE) ||
          ((testValue000 == KWD_DESCRIPTIONS_EQUIVALENT) ||
           (testValue000 == KWD_DESCRIPTIONS_IMPLIES))))) {
      { Object* term = NULL;
        Vector* vector000 = proposition->arguments;
        int index000 = 0;
        int length000 = vector000->length();

        while (index000 < length000) {
          term = (vector000->theArray)[index000];
          index000 = index000 + 1;
          if (subtypeOfP(safePrimaryType(term), SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
            { Object* term000 = term;
              PatternVariable* term = ((PatternVariable*)(term000));

              if (((boolean)(term->definingProposition))) {
                return (TRUE);
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
  return (FALSE);
}

Proposition* expandIfProposition(Proposition* ifproposition) {
  { Vector* arguments = ifproposition->arguments;
    Object* testprop = (arguments->theArray)[0];
    Proposition* negatedtestprop = createProposition(SYM_DESCRIPTIONS_STELLA_NOT, 1);
    Object* truevalue = (arguments->theArray)[1];
    Object* falsevalue = (arguments->theArray)[2];
    PatternVariable* valuevariable = ((PatternVariable*)((ifproposition->arguments->theArray)[(ifproposition->arguments->length() - 1)]));
    Proposition* trueequivalence = createEquivalenceProposition(valuevariable, truevalue);
    Proposition* falseequivalence = (((boolean)(falsevalue)) ? createEquivalenceProposition(valuevariable, falsevalue) : ((Proposition*)(NULL)));

    valuevariable->definingProposition = NULL;
    if (((boolean)(falsevalue))) {
      {
        (negatedtestprop->arguments->theArray)[0] = ((isaP(testprop, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE) ? testprop : shallowCopyProposition(((Proposition*)(testprop)))));
        return (disjoinPropositions(consList(2, conjoinTwoPropositions(((Proposition*)(testprop)), trueequivalence), conjoinTwoPropositions(negatedtestprop, falseequivalence))));
      }
    }
    else {
      return (conjoinTwoPropositions(((Proposition*)(testprop)), trueequivalence));
    }
  }
}

void helpCollectFlattenedArguments(Proposition* self, List* flattenedarguments, List* existsvariables) {
  { Object* term = NULL;
    Vector* vector000 = self->arguments;
    int index000 = 0;
    int length000 = vector000->length();

    while (index000 < length000) {
      term = (vector000->theArray)[index000];
      index000 = index000 + 1;
      if (subtypeOfP(safePrimaryType(term), SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
        { Object* term000 = term;
          PatternVariable* term = ((PatternVariable*)(term000));

          { Proposition* functionarg = term->definingProposition;

            if (((boolean)(functionarg)) &&
                (!existsvariables->memberP(term))) {
              existsvariables->push(term);
              helpCollectFlattenedArguments(functionarg, flattenedarguments, existsvariables);
              if (functionarg->operatoR == SGT_DESCRIPTIONS_STELLA_PROPOSITIONdIF) {
                flattenedarguments->push(expandIfProposition(functionarg));
              }
              else {
                flattenedarguments->push(functionarg);
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

List* yieldFlattenedArguments(Proposition* proposition, List* existsvariables) {
  { List* flattenedarguments = newList();

    helpCollectFlattenedArguments(proposition, flattenedarguments, existsvariables);
    flattenedarguments->push(proposition);
    existsvariables->reverse();
    return (flattenedarguments->reverse());
  }
}

Proposition* flattenNestedFunctionArguments(Proposition* proposition) {
  { Proposition* existsproposition = createProposition(SYM_DESCRIPTIONS_STELLA_EXISTS, 1);
    List* existsvariables = newList();
    List* flattenedpropositions = yieldFlattenedArguments(proposition, existsvariables);
    Proposition* andproposition = createProposition(SYM_DESCRIPTIONS_STELLA_AND, flattenedpropositions->length());

    { Proposition* prop = NULL;
      int i = NULL_INTEGER;
      Cons* iter000 = flattenedpropositions->theConsList;
      int iter001 = 0;

      while (!(iter000 == NIL)) {
        prop = ((Proposition*)(iter000->value));
        iter000 = iter000->rest;
        i = iter001;
        iter001 = iter001 + 1;
        (andproposition->arguments->theArray)[i] = prop;
      }
    }
    { PatternVariable* vbl = NULL;
      Cons* iter002 = existsvariables->theConsList;

      while (!(iter002 == NIL)) {
        vbl = ((PatternVariable*)(iter002->value));
        iter002 = iter002->rest;
        vbl->definingProposition = NULL;
      }
    }
    setDynamicSlotValue(existsproposition->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES, copyConsListToVariablesVector(existsvariables->theConsList), NULL);
    existsvariables->free();
    (existsproposition->arguments->theArray)[0] = andproposition;
    return (existsproposition);
  }
}

void collapseValueOfChainsForIoVariables(Vector* iovariables) {
  { PatternVariable* tightestvariable = NULL;

    { PatternVariable* vbl = NULL;
      int i = NULL_INTEGER;
      Vector* vector000 = iovariables;
      int index000 = 0;
      int length000 = vector000->length();
      int iter000 = 0;

      while (index000 < length000) {
        vbl = ((PatternVariable*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        i = iter000;
        iter000 = iter000 + 1;
        if (!(vbl == innermostVariableOf(vbl))) {
          tightestvariable = innermostVariableOf(vbl);
          (iovariables->theArray)[i] = tightestvariable;
          tightestvariable->skolemName = vbl->skolemName;
          { PatternVariable* object000 = tightestvariable;
            Cons* value000 = NIL;
            Object* oldValue000 = object000->variableValueInverse;
            Object* newValue000 = updateInContext(oldValue000, value000, object000->homeContext, FALSE);

            if (!(((boolean)(oldValue000)) &&
                (oldValue000->primaryType() == SGT_DESCRIPTIONS_STELLA_CS_VALUE))) {
              object000->variableValueInverse = newValue000;
            }
          }
          vbl->free();
        }
      }
    }
  }
}

Vector* removeNullsInVariablesVector(Vector* iovariables) {
  if (!iovariables->memberP(NULL)) {
    return (iovariables);
  }
  { Cons* newvbllist = NIL;
    Vector* result = NULL;

    { PatternVariable* vbl = NULL;
      Vector* vector000 = iovariables;
      int index000 = 0;
      int length000 = vector000->length();
      Cons* collect000 = NULL;

      while (index000 < length000) {
        vbl = ((PatternVariable*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        if (((boolean)(vbl))) {
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(vbl, NIL);
              if (newvbllist == NIL) {
                newvbllist = collect000;
              }
              else {
                addConsToEndOfConsList(newvbllist, collect000);
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
    result = copyConsListToVariablesVector(newvbllist);
    return (result);
  }
}

void collapseValueOfChains(Description* description) {
  tightenArgumentBindings(description->proposition, description->ioVariables);
  collapseValueOfChainsForIoVariables(description->ioVariables);
  { Object* value = NULL;

    { PatternVariable* vbl = NULL;
      int i = NULL_INTEGER;
      Vector* vector000 = description->internalVariables;
      int index000 = 0;
      int length000 = vector000->length();
      int iter000 = 0;

      while (index000 < length000) {
        vbl = ((PatternVariable*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        i = iter000;
        iter000 = iter000 + 1;
        if (((boolean)(((Object*)(accessInContext(vbl->variableValue, vbl->homeContext, FALSE))))) &&
            variableP(((Object*)(accessInContext(vbl->variableValue, vbl->homeContext, FALSE))))) {
          value = ((Object*)(accessInContext(vbl->variableValue, vbl->homeContext, FALSE)));
          (description->internalVariables->theArray)[i] = NULL;
          if (subtypeOfP(safePrimaryType(value), SGT_DESCRIPTIONS_LOGIC_LOGIC_OBJECT)) {
            { Object* value000 = value;
              LogicObject* value = ((LogicObject*)(value000));

              if (!(description->ioVariables->memberP(value->variableValueInverse_reader()))) {
                { LogicObject* object000 = value;
                  Cons* value001 = NIL;
                  Object* oldValue003 = object000->variableValueInverse;
                  Object* newValue000 = updateInContext(oldValue003, value001, object000->homeContext, FALSE);

                  if (!(((boolean)(oldValue003)) &&
                      (oldValue003->primaryType() == SGT_DESCRIPTIONS_STELLA_CS_VALUE))) {
                    object000->variableValueInverse = newValue000;
                  }
                }
              }
            }
          }
          else {
          }
          vbl->free();
        }
      }
    }
    { PatternVariable* vbl = NULL;
      int i = NULL_INTEGER;
      Vector* vector001 = description->internalVariables;
      int index001 = 0;
      int length001 = vector001->length();
      int iter001 = 0;

      while (index001 < length001) {
        vbl = ((PatternVariable*)((vector001->theArray)[index001]));
        index001 = index001 + 1;
        i = iter001;
        iter001 = iter001 + 1;
        if (description->ioVariables->memberP(vbl)) {
          value = vbl;
          (description->internalVariables->theArray)[i] = NULL;
        }
      }
    }
    description->internalVariables = removeNullsInVariablesVector(description->internalVariables);
  }
}

void tightenArgumentBindings(Proposition* proposition, Vector* iovariables) {
  { boolean tightenedachainP = FALSE;

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
        { Surrogate* testValue000 = safePrimaryType(arg);

          if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
            { Object* arg000 = arg;
              PatternVariable* arg = ((PatternVariable*)(arg000));

              { Object* value = ((((boolean)(iovariables)) &&
                    iovariables->memberP(arg)) ? innermostVariableOf(arg) : innermostOf(arg));

                if (!(value == arg)) {
                  (proposition->arguments->theArray)[i] = value;
                  tightenedachainP = TRUE;
                }
              }
            }
          }
          else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PROPOSITION)) {
            { Object* arg001 = arg;
              Proposition* arg = ((Proposition*)(arg001));

              tightenArgumentBindings(arg, iovariables);
            }
          }
          else {
          }
        }
      }
    }
    if (((boolean)(((Vector*)(dynamicSlotValue(proposition->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES, NULL)))))) {
      { Vector* quantifiedvariables = ((Vector*)(dynamicSlotValue(proposition->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES, NULL)));

        { PatternVariable* vbl = NULL;
          int i = NULL_INTEGER;
          Vector* vector001 = quantifiedvariables;
          int index001 = 0;
          int length001 = vector001->length();
          int iter001 = 0;

          while (index001 < length001) {
            vbl = ((PatternVariable*)((vector001->theArray)[index001]));
            index001 = index001 + 1;
            i = iter001;
            iter001 = iter001 + 1;
            if (!(vbl == innermostVariableOf(vbl))) {
              (quantifiedvariables->theArray)[i] = NULL;
              vbl->free();
            }
          }
        }
        setDynamicSlotValue(proposition->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES, removeNullsInVariablesVector(quantifiedvariables), NULL);
        if (((Vector*)(dynamicSlotValue(proposition->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES, NULL)))->arraySize == 0) {
          unfastenProposition(proposition);
          normalizeProposition(proposition);
          fastenDownOneProposition(proposition, FALSE);
        }
      }
    }
    if (tightenedachainP) {
      unfastenProposition(proposition);
      fastenDownOneProposition(proposition, FALSE);
    }
  }
}

void collectAllVariables(Proposition* self, List* collection, List* beenthere) {
  beenthere->insert(self);
  { Object* arg = NULL;
    Vector* vector000 = self->arguments;
    int index000 = 0;
    int length000 = vector000->length();

    while (index000 < length000) {
      arg = (vector000->theArray)[index000];
      index000 = index000 + 1;
      { Surrogate* testValue000 = safePrimaryType(arg);

        if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
          { Object* arg000 = arg;
            PatternVariable* arg = ((PatternVariable*)(arg000));

            collection->insertNew(arg);
          }
        }
        else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PROPOSITION)) {
          { Object* arg001 = arg;
            Proposition* arg = ((Proposition*)(arg001));

            if (!(beenthere->memberP(arg))) {
              collectAllVariables(arg, collection, beenthere);
            }
          }
        }
        else {
        }
      }
    }
  }
}

void computeInternalVariables(Description* self) {
  { List* collection = newList();
    List* beenthere = newList();

    collectAllVariables(self->proposition, collection, beenthere);
    { PatternVariable* vbl = NULL;
      Vector* vector000 = self->ioVariables;
      int index000 = 0;
      int length000 = vector000->length();

      while (index000 < length000) {
        vbl = ((PatternVariable*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        collection->remove(vbl);
      }
    }
    if (((boolean)(((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_EXTERNAL_VARIABLES, NULL)))))) {
      { PatternVariable* vbl = NULL;
        Vector* vector001 = ((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_EXTERNAL_VARIABLES, NULL)));
        int index001 = 0;
        int length001 = vector001->length();

        while (index001 < length001) {
          vbl = ((PatternVariable*)((vector001->theArray)[index001]));
          index001 = index001 + 1;
          collection->remove(vbl);
        }
      }
    }
    self->internalVariables = copyConsListToVariablesVector(collection->theConsList);
    collection->free();
    beenthere->free();
  }
}

void equateTopLevelEquivalences(Proposition* proposition) {
  { Vector* arguments = proposition->arguments;

    { Keyword* testValue000 = proposition->kind;

      if (testValue000 == KWD_DESCRIPTIONS_EQUIVALENT) {
        equateValues(innermostOf((arguments->theArray)[0]), innermostOf((arguments->theArray)[1]));
      }
      else if (testValue000 == KWD_DESCRIPTIONS_AND) {
        { Object* arg = NULL;
          Vector* vector000 = arguments;
          int index000 = 0;
          int length000 = vector000->length();

          while (index000 < length000) {
            arg = (vector000->theArray)[index000];
            index000 = index000 + 1;
            equateTopLevelEquivalences(((Proposition*)(arg)));
          }
        }
      }
      else if (testValue000 == KWD_DESCRIPTIONS_EXISTS) {
        equateTopLevelEquivalences(((Proposition*)((arguments->theArray)[0])));
      }
      else if (testValue000 == KWD_DESCRIPTIONS_FUNCTION) {
        evaluateFunctionProposition(proposition);
      }
      else {
      }
    }
  }
}

// Used by 'evaluate-DESCRIPTION-term' for collecting
// a list of variables declared external to the description in which they
// are referenced.
DEFINE_STELLA_SPECIAL(oEXTERNALVARIABLESo, Cons* , NULL);

void collectExternalVariables(Proposition* proposition) {
  { Object* arg = NULL;
    Vector* vector000 = proposition->arguments;
    int index000 = 0;
    int length000 = vector000->length();

    while (index000 < length000) {
      arg = (vector000->theArray)[index000];
      index000 = index000 + 1;
      { Surrogate* testValue000 = safePrimaryType(arg);

        if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
          { Object* arg000 = arg;
            PatternVariable* arg = ((PatternVariable*)(arg000));

            if (oLOGICVARIABLETABLEo.get()->memberP(arg) &&
                (!oEXTERNALVARIABLESo.get()->memberP(arg))) {
              oEXTERNALVARIABLESo.set(cons(arg, oEXTERNALVARIABLESo.get()));
            }
          }
        }
        else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PROPOSITION)) {
          { Object* arg001 = arg;
            Proposition* arg = ((Proposition*)(arg001));

            collectExternalVariables(arg);
          }
        }
        else {
        }
      }
    }
  }
}

Description* finishBuildingDescription(Description* description, boolean checkforduplicateP) {
  { Proposition* proposition = description->proposition;

    normalizeProposition(proposition);
    if (proposition->kind == KWD_DESCRIPTIONS_EXISTS) {
      proposition = ((Proposition*)((proposition->arguments->theArray)[0]));
      description->proposition = proposition;
    }
    resolveUnresolvedSlotReferences(description);
    recursivelyFastenDownPropositions(proposition, FALSE);
    updateSkolemTypeFromIsaAssertions(proposition);
    try {
      equateTopLevelEquivalences(proposition);
    }
    catch (Clash& _e) {
      Clash* e = &_e;

      *(STANDARD_ERROR->nativeStream) << exceptionMessage(e) << std::endl;
    }
  }
  collapseValueOfChains(description);
  simplifyDescription(description, FALSE);
  computeInternalVariables(description);
  if (checkforduplicateP) {
    { Description* duplicatedescription = findDuplicateDescription(description);

      if (((boolean)(duplicatedescription))) {
        description->free();
        return (duplicatedescription);
      }
    }
  }
  return (description);
}

Description* evaluateDescriptionTerm(Cons* term, boolean checkforduplicateP) {
  { Description* description = createDescription(NULL_INTEGER, FALSE);

    if (((GeneralizedSymbol*)(term->value)) == SYM_DESCRIPTIONS_LOGIC_THE_ONLY) {
      setDynamicSlotValue(description->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IOTAp, (TRUE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
    }
    else {
    }
    { 
      BIND_STELLA_SPECIAL(oDESCRIPTIONUNDERCONSTRUCTIONo, Object*, description);
      BIND_STELLA_SPECIAL(oEVALUATIONMODEo, Keyword*, KWD_DESCRIPTIONS_DESCRIPTION);
      BIND_STELLA_SPECIAL(oVARIABLEIDCOUNTERo, int, oVARIABLEIDCOUNTERo.get());
      { Cons* iovars = NULL;
        Proposition* proposition = NULL;
        Proposition* unused = NULL;

        iovars = buildQuantifiedProposition(term, TRUE, proposition, unused);
        unused = unused;
        description->ioVariables = copyConsListToVariablesVector(iovars);
        if (!(oLOGICVARIABLETABLEo.get() == NIL)) {
          { 
            BIND_STELLA_SPECIAL(oEXTERNALVARIABLESo, Cons*, NIL);
            collectExternalVariables(proposition);
            if (!(oEXTERNALVARIABLESo.get() == NIL)) {
              setDynamicSlotValue(description->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_EXTERNAL_VARIABLES, copyConsListToVariablesVector(oEXTERNALVARIABLESo.get()), NULL);
            }
          }
        }
        description->proposition = (((boolean)(proposition)) ? proposition : TRUE_PROPOSITION);
      }
      finishBuildingDescription(description, FALSE);
      if (checkforduplicateP) {
        { Description* duplicate = findDuplicateDescription(description);

          if (((boolean)(duplicate))) {
            return (duplicate);
          }
          fastenDownDescription(description);
        }
      }
      return (description);
    }
  }
}

Cons* removeVariableTypePropositions(Proposition* proposition) {
  { Keyword* testValue000 = proposition->kind;

    if (testValue000 == KWD_DESCRIPTIONS_AND) {
      { Cons* typedeclarations = NIL;
        Proposition* goalproposition = NULL;

        { Object* arg = NULL;
          Vector* vector000 = proposition->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          while (index000 < length000) {
            arg = (vector000->theArray)[index000];
            index000 = index000 + 1;
            if (coerceWrappedBooleanToBoolean(((Proposition*)(arg))->variableTypeP_reader())) {
              typedeclarations = cons(arg, typedeclarations);
            }
            else if (((boolean)(goalproposition))) {
            }
            else {
              goalproposition = ((Proposition*)(arg));
            }
          }
        }
        overlayProposition(proposition, goalproposition);
        return (typedeclarations);
      }
    }
    else if ((testValue000 == KWD_DESCRIPTIONS_ISA) ||
        ((testValue000 == KWD_DESCRIPTIONS_PREDICATE) ||
         ((testValue000 == KWD_DESCRIPTIONS_FUNCTION) ||
          (testValue000 == KWD_DESCRIPTIONS_NOT)))) {
      return (NIL);
    }
    else {
    }
  }
  return (NIL);
}

// Used to prevent infinite looping.
DEFINE_STELLA_SPECIAL(oRECURSIVEGETCOMPLEMENTARGUMENTo, NamedDescription* , NULL);

Description* getComplementOfGoalDescription(NamedDescription* self) {
  { Description* complement = ((Description*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_COMPLEMENT_DESCRIPTION, NULL)));

    if (((boolean)(complement))) {
      return (complement);
    }
    if (self == oRECURSIVEGETCOMPLEMENTARGUMENTo.get()) {
      return (NULL);
    }
    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, self->homeModule());
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
      { Cons* declarations = NIL;
        Cons* variables = NIL;
        Cons* clauses = NIL;

        { PatternVariable* v = NULL;
          Surrogate* type = NULL;
          Vector* vector000 = self->ioVariables;
          int index000 = 0;
          int length000 = vector000->length();
          Cons* iter000 = self->ioVariableTypes->theConsList;
          Cons* collect000 = NULL;

          while ((index000 < length000) &&
              (!(iter000 == NIL))) {
            v = ((PatternVariable*)((vector000->theArray)[index000]));
            index000 = index000 + 1;
            type = ((Surrogate*)(iter000->value));
            iter000 = iter000->rest;
            if ((!((boolean)(type))) ||
                classDescriptionP(self)) {
              declarations = cons(v->skolemName, declarations);
            }
            else {
              declarations = cons(cons(v->skolemName, cons(surrogateToSymbol(type), NIL)), declarations);
            }
            if (!((boolean)(collect000))) {
              {
                collect000 = cons(v->skolemName, NIL);
                if (variables == NIL) {
                  variables = collect000;
                }
                else {
                  addConsToEndOfConsList(variables, collect000);
                }
              }
            }
            else {
              {
                collect000->rest = cons(v->skolemName, NIL);
                collect000 = collect000->rest;
              }
            }
          }
        }
        declarations = declarations->reverse();
        clauses = cons(listO(3, SYM_DESCRIPTIONS_STELLA_NOT, cons(self->descriptionName(), variables->concatenate(NIL, 0)), NIL), NIL);
        if (classDescriptionP(self)) {
          { NamedDescription* p = NULL;
            Cons* iter001 = allDirectSuperrelations(self, TRUE);

            while (!(iter001 == NIL)) {
              p = ((NamedDescription*)(iter001->value));
              iter001 = iter001->rest;
              clauses = cons(cons(p->descriptionName(), cons(variables->value, NIL)), clauses);
            }
          }
        }
        { 
          BIND_STELLA_SPECIAL(oRECURSIVEGETCOMPLEMENTARGUMENTo, NamedDescription*, self);
          complement = ((Description*)(conceiveTerm(listO(3, SYM_DESCRIPTIONS_LOGIC_KAPPA, declarations, cons(cons(SYM_DESCRIPTIONS_STELLA_AND, clauses->concatenate(NIL, 0)), NIL)))));
        }
        setDynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_COMPLEMENT_DESCRIPTION, complement, NULL);
        setDynamicSlotValue(complement->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_COMPLEMENT_DESCRIPTION, self, NULL);
        deriveDeferredContrapositiveSatelliteRules(self);
        return (complement);
      }
    }
  }
}

void collectFreeVariables(Object* self, List* collection, List* quantifiedvars, List* beenthere) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
      { Object* self000 = self;
        PatternVariable* self = ((PatternVariable*)(self000));

        if (!quantifiedvars->memberP(self)) {
          collection->insertNew(self);
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PROPOSITION)) {
      { Object* self001 = self;
        Proposition* self = ((Proposition*)(self001));

        if (!(beenthere->memberP(self))) {
          { Keyword* testValue001 = self->kind;

            if ((testValue001 == KWD_DESCRIPTIONS_FORALL) ||
                (testValue001 == KWD_DESCRIPTIONS_EXISTS)) {
              { PatternVariable* v = NULL;
                Vector* vector000 = ((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES, NULL)));
                int index000 = 0;
                int length000 = vector000->length();

                while (index000 < length000) {
                  v = ((PatternVariable*)((vector000->theArray)[index000]));
                  index000 = index000 + 1;
                  quantifiedvars->insert(v);
                }
              }
            }
            else {
            }
          }
          beenthere->insert(self);
          { Object* arg = NULL;
            Vector* vector001 = self->arguments;
            int index001 = 0;
            int length001 = vector001->length();

            while (index001 < length001) {
              arg = (vector001->theArray)[index001];
              index001 = index001 + 1;
              collectFreeVariables(arg, collection, quantifiedvars, beenthere);
            }
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_DESCRIPTION)) {
      { Object* self002 = self;
        Description* self = ((Description*)(self002));

        { PatternVariable* v = NULL;
          Vector* vector002 = self->ioVariables;
          int index002 = 0;
          int length002 = vector002->length();

          while (index002 < length002) {
            v = ((PatternVariable*)((vector002->theArray)[index002]));
            index002 = index002 + 1;
            quantifiedvars->insert(v);
          }
        }
        { PatternVariable* v = NULL;
          Cons* iter000 = topLevelExistentialVariables(self);

          while (!(iter000 == NIL)) {
            v = ((PatternVariable*)(iter000->value));
            iter000 = iter000->rest;
            quantifiedvars->insert(v);
          }
        }
        collectFreeVariables(self->proposition, collection, quantifiedvars, beenthere);
      }
    }
    else {
    }
  }
}

Cons* topLevelExistentialVariables(Description* self) {
  { List* quantifiedvariables = newList();
    List* beenthere = newList();
    List* collection = newList();

    { PatternVariable* v = NULL;
      Vector* vector000 = self->ioVariables;
      int index000 = 0;
      int length000 = vector000->length();

      while (index000 < length000) {
        v = ((PatternVariable*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        quantifiedvariables->insert(v);
      }
    }
    if (((boolean)(((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_EXTERNAL_VARIABLES, NULL)))))) {
      { PatternVariable* v = NULL;
        Vector* vector001 = ((Vector*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_EXTERNAL_VARIABLES, NULL)));
        int index001 = 0;
        int length001 = vector001->length();

        while (index001 < length001) {
          v = ((PatternVariable*)((vector001->theArray)[index001]));
          index001 = index001 + 1;
          quantifiedvariables->insert(v);
        }
      }
    }
    if (!((boolean)(self->proposition))) {
      return (quantifiedvariables->theConsList);
    }
    collectFreeVariables(self->proposition, collection, quantifiedvariables, beenthere);
    quantifiedvariables->free();
    beenthere->free();
    return (collection->theConsList);
  }
}

boolean topLevelExistentialVariableP(PatternVariable* variable, Description* description) {
  return ((!description->ioVariables->memberP(variable)) &&
      (description->internalVariables->memberP(variable) &&
       freeVariableP(variable, description->proposition)));
}

boolean freeVariableP(PatternVariable* variable, Proposition* proposition) {
  { Keyword* testValue000 = proposition->kind;

    if ((testValue000 == KWD_DESCRIPTIONS_FORALL) ||
        (testValue000 == KWD_DESCRIPTIONS_EXISTS)) {
      if (((Vector*)(dynamicSlotValue(proposition->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES, NULL)))->memberP(variable)) {
        return (FALSE);
      }
    }
    else {
    }
  }
  { boolean alwaysP000 = TRUE;

    { Object* arg = NULL;
      Vector* vector000 = proposition->arguments;
      int index000 = 0;
      int length000 = vector000->length();

      while (index000 < length000) {
        arg = (vector000->theArray)[index000];
        index000 = index000 + 1;
        if (isaP(arg, SGT_DESCRIPTIONS_LOGIC_PROPOSITION)) {
          if (!freeVariableP(variable, ((Proposition*)(arg)))) {
            alwaysP000 = FALSE;
            break;
          }
        }
      }
    }
    { boolean value000 = alwaysP000;

      return (value000);
    }
  }
}

List* mostSpecificTypes(List* types) {
  if (!((boolean)(types->rest()))) {
    return (types);
  }
  { Cons* cursor1 = types->theConsList;
    Cons* cursor2 = NULL;
    Object* value1 = NULL;
    Object* value2 = NULL;

    while (!(cursor1 == NIL)) {
      value1 = ((Surrogate*)(cursor1->value));
      if (((boolean)(((Surrogate*)(cursor1->value))))) {
        cursor2 = cursor1->rest;
        while (!(cursor2 == NIL)) {
          value2 = cursor2->value;
          if (((boolean)(value2))) {
            if (logicalSubtypeOfP(((Surrogate*)(value1)), ((Surrogate*)(value2)))) {
              cursor2->value = NULL;
            }
            else {
              if (logicalSubtypeOfP(((Surrogate*)(value2)), ((Surrogate*)(value1)))) {
                cursor1->value = NULL;
                break;
              }
            }
          }
          cursor2 = cursor2->rest;
        }
      }
      cursor1 = cursor1->rest;
    }
  }
  types->remove(NULL);
  return (types);
}

// Used by 'infer-variable-types'.
DEFINE_STELLA_SPECIAL(oADDEDNEWTYPEpo, boolean , FALSE);

void addVariableType(PatternVariable* variable, Surrogate* newtype, KeyValueList* table, Cons* visiblevariables) {
  if (!visiblevariables->memberP(variable)) {
    return;
  }
  { List* types = ((List*)(table->lookup(variable)));

    if (!((boolean)(types))) {
      table->insertAt(variable, list(1, newtype));
    }
    else {
      {
        { Surrogate* t = NULL;
          Cons* iter000 = types->theConsList;

          while (!(iter000 == NIL)) {
            t = ((Surrogate*)(iter000->value));
            iter000 = iter000->rest;
            if (logicalSubtypeOfP(t, newtype)) {
              return;
            }
            if (logicalSubtypeOfP(newtype, t)) {
              types->remove(t);
              addVariableType(variable, newtype, table, visiblevariables);
              return;
            }
          }
        }
        types->insert(newtype);
      }
    }
    oADDEDNEWTYPEpo.set(TRUE);
  }
}

Object* inferPredicateFromOperatorAndTypes(Object* operatoR, List* types) {
  { Surrogate* testValue000 = safePrimaryType(operatoR);

    if (subtypeOfSurrogateP(testValue000)) {
      { Object* operator000 = operatoR;
        Surrogate* operatoR = ((Surrogate*)(operator000));

        if (isaP(operatoR->surrogateValue, SGT_DESCRIPTIONS_STELLA_SLOT)) {
          { Slot* slot = ((Slot*)(operatoR->surrogateValue));

            slot = ((Slot*)(inferPredicateFromOperatorAndTypes(slot->slotName, types)));
            if (((boolean)(slot))) {
              return (slot);
            }
            else {
              return (operatoR->surrogateValue);
            }
          }
        }
        else {
          return (operatoR->surrogateValue);
        }
      }
    }
    else if (subtypeOfSymbolP(testValue000)) {
      { Object* operator001 = operatoR;
        Symbol* operatoR = ((Symbol*)(operator001));

        { Surrogate* slotref = NULL;

          { Surrogate* type = NULL;
            Cons* iter000 = types->theConsList;

            while (!(iter000 == NIL)) {
              type = ((Surrogate*)(iter000->value));
              iter000 = iter000->rest;
              if (isaP(type->surrogateValue, SGT_DESCRIPTIONS_STELLA_CLASS)) {
                slotref = lookupSlotref(type, operatoR);
                if (((boolean)(slotref))) {
                  return (slotref->surrogateValue);
                }
                if (logicalSubtypeOfLiteralP(type)) {
                  type = type->typeToWrappedType();
                  slotref = lookupSlotref(type, operatoR);
                  if (((boolean)(slotref))) {
                    return (slotref->surrogateValue);
                  }
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
  return (NULL);
}

void inferTypesFromOneProposition(Proposition* proposition, KeyValueList* table, Cons* visiblevars) {
  if (proposition->arguments->length() == 0) {
    return;
  }
  { Vector* arguments = proposition->arguments;
    Object* firstarg = (arguments->theArray)[0];

    { Keyword* testValue000 = proposition->kind;

      if (testValue000 == KWD_DESCRIPTIONS_ISA) {
        if (isaP(firstarg, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
          addVariableType(((PatternVariable*)(firstarg)), ((Surrogate*)(proposition->operatoR)), table, visiblevars);
        }
      }
      else if ((testValue000 == KWD_DESCRIPTIONS_PREDICATE) ||
          (testValue000 == KWD_DESCRIPTIONS_FUNCTION)) {
        { Object* predicate = NULL;

          { Surrogate* testValue001 = safePrimaryType(firstarg);

            if (subtypeOfP(testValue001, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
              { Object* firstarg000 = firstarg;
                PatternVariable* firstarg = ((PatternVariable*)(firstarg000));

                { List* types = ((List*)(table->lookup(firstarg)));

                  if (((boolean)(types))) {
                    predicate = inferPredicateFromOperatorAndTypes(proposition->operatoR, types);
                  }
                }
              }
            }
            else if (subtypeOfSurrogateP(testValue001)) {
              { Object* firstarg001 = firstarg;
                Surrogate* firstarg = ((Surrogate*)(firstarg001));

                { Object* value = firstarg->surrogateValue;
                  List* types = newList();

                  if (((boolean)(value)) &&
                      isaP(value, SGT_DESCRIPTIONS_LOGIC_LOGIC_OBJECT)) {
                    { NamedDescription* d = NULL;
                      Cons* iter000 = allAssertedTypes(value);
                      Cons* collect000 = NULL;

                      while (!(iter000 == NIL)) {
                        d = ((NamedDescription*)(iter000->value));
                        iter000 = iter000->rest;
                        if (!((boolean)(collect000))) {
                          {
                            collect000 = cons(d->surrogateValueInverse, NIL);
                            if (types->theConsList == NIL) {
                              types->theConsList = collect000;
                            }
                            else {
                              addConsToEndOfConsList(types->theConsList, collect000);
                            }
                          }
                        }
                        else {
                          {
                            collect000->rest = cons(d->surrogateValueInverse, NIL);
                            collect000 = collect000->rest;
                          }
                        }
                      }
                    }
                    types = mostSpecificTypes(types);
                    predicate = inferPredicateFromOperatorAndTypes(proposition->operatoR, types);
                  }
                }
              }
            }
            else {
              { GeneralizedSymbol* operatoR = proposition->operatoR;

                if (isaP(operatoR, SGT_DESCRIPTIONS_STELLA_SURROGATE) &&
                    isaP(((Surrogate*)(operatoR))->surrogateValue, SGT_DESCRIPTIONS_STELLA_SLOT)) {
                  predicate = ((Slot*)(((Surrogate*)(operatoR))->surrogateValue));
                }
              }
            }
          }
          if (((boolean)(predicate))) {
            { Surrogate* testValue002 = safePrimaryType(predicate);

              if (subtypeOfP(testValue002, SGT_DESCRIPTIONS_LOGIC_NAMED_DESCRIPTION)) {
                { Object* predicate000 = predicate;
                  NamedDescription* predicate = ((NamedDescription*)(predicate000));

                  if (((boolean)(predicate->ioVariableTypes))) {
                    { Object* arg = NULL;
                      Surrogate* type = NULL;
                      Vector* vector000 = arguments;
                      int index000 = 0;
                      int length000 = vector000->length();
                      Cons* iter001 = predicate->ioVariableTypes->theConsList;

                      while ((index000 < length000) &&
                          (!(iter001 == NIL))) {
                        arg = (vector000->theArray)[index000];
                        index000 = index000 + 1;
                        type = ((Surrogate*)(iter001->value));
                        iter001 = iter001->rest;
                        if (isaP(arg, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
                          addVariableType(((PatternVariable*)(arg)), type, table, visiblevars);
                        }
                      }
                    }
                  }
                  else {
                  }
                }
              }
              else if (subtypeOfP(testValue002, SGT_DESCRIPTIONS_STELLA_SLOT)) {
                { Object* predicate001 = predicate;
                  Slot* predicate = ((Slot*)(predicate001));

                  { Object* arg = NULL;
                    Surrogate* columntype = NULL;
                    Vector* vector001 = arguments;
                    int index001 = 0;
                    int length001 = vector001->length();
                    Cons* iter002 = slotColumnTypes(predicate, arguments->length());

                    while ((index001 < length001) &&
                        (!(iter002 == NIL))) {
                      arg = (vector001->theArray)[index001];
                      index001 = index001 + 1;
                      columntype = ((Surrogate*)(iter002->value));
                      iter002 = iter002->rest;
                      if (isaP(arg, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
                        addVariableType(((PatternVariable*)(arg)), columntype, table, visiblevars);
                      }
                    }
                  }
                }
              }
              else if (subtypeOfP(testValue002, SGT_DESCRIPTIONS_LOGIC_LOGIC_OBJECT)) {
                { Object* predicate002 = predicate;
                  LogicObject* predicate = ((LogicObject*)(predicate002));

                }
              }
              else {
                { OutputStringStream* stream000 = newOutputStringStream();

                  *(stream000->nativeStream) << "`" << testValue002 << "'" << " is not a valid case option";
                  throw *newStellaException(stream000->theStringReader());
                }
              }
            }
          }
        }
      }
      else if (testValue000 == KWD_DESCRIPTIONS_EQUIVALENT) {
        { Object* secondarg = (arguments->theArray)[1];

          if (isaP(firstarg, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
            if (isaP(secondarg, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
              { Object* t = NULL;
                Cons* iter003 = mapNullToNilList(((List*)(table->lookup(((PatternVariable*)(secondarg))))))->theConsList;

                while (!(iter003 == NIL)) {
                  t = iter003->value;
                  iter003 = iter003->rest;
                  addVariableType(((PatternVariable*)(firstarg)), ((Surrogate*)(t)), table, visiblevars);
                }
              }
            }
            else {
              addVariableType(((PatternVariable*)(firstarg)), logicalType(secondarg), table, visiblevars);
            }
          }
          if (isaP(secondarg, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
            if (isaP(firstarg, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
              { Object* t = NULL;
                Cons* iter004 = mapNullToNilList(((List*)(table->lookup(((PatternVariable*)(firstarg))))))->theConsList;

                while (!(iter004 == NIL)) {
                  t = iter004->value;
                  iter004 = iter004->rest;
                  addVariableType(((PatternVariable*)(secondarg)), ((Surrogate*)(t)), table, visiblevars);
                }
              }
            }
            else {
              addVariableType(((PatternVariable*)(secondarg)), logicalType(firstarg), table, visiblevars);
            }
          }
        }
      }
      else {
      }
    }
  }
}

void inferTypesFromPropositions(Proposition* proposition, KeyValueList* table, Cons* visiblevars) {
  { Vector* arguments = proposition->arguments;

    { Keyword* testValue000 = proposition->kind;

      if (testValue000 == KWD_DESCRIPTIONS_AND) {
        { Object* arg = NULL;
          Vector* vector000 = arguments;
          int index000 = 0;
          int length000 = vector000->length();

          while (index000 < length000) {
            arg = (vector000->theArray)[index000];
            index000 = index000 + 1;
            inferTypesFromPropositions(((Proposition*)(arg)), table, visiblevars);
          }
        }
      }
      else if (testValue000 == KWD_DESCRIPTIONS_OR) {
        { Object* arg = NULL;
          Vector* vector001 = arguments;
          int index001 = 0;
          int length001 = vector001->length();

          while (index001 < length001) {
            arg = (vector001->theArray)[index001];
            index001 = index001 + 1;
            inferTypesFromPropositions(((Proposition*)(arg)), table, NIL);
          }
        }
      }
      else if ((testValue000 == KWD_DESCRIPTIONS_ISA) ||
          ((testValue000 == KWD_DESCRIPTIONS_PREDICATE) ||
           ((testValue000 == KWD_DESCRIPTIONS_FUNCTION) ||
            (testValue000 == KWD_DESCRIPTIONS_EQUIVALENT)))) {
        inferTypesFromOneProposition(proposition, table, visiblevars);
      }
      else if (testValue000 == KWD_DESCRIPTIONS_FORALL) {
        visiblevars = NIL;
        { PatternVariable* v = NULL;
          Vector* vector002 = ((Vector*)(dynamicSlotValue(proposition->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES, NULL)));
          int index002 = 0;
          int length002 = vector002->length();

          while (index002 < length002) {
            v = ((PatternVariable*)((vector002->theArray)[index002]));
            index002 = index002 + 1;
            visiblevars = cons(v, visiblevars);
          }
        }
        inferTypesFromPropositions(((Proposition*)((arguments->theArray)[0])), table, visiblevars);
        inferTypesFromPropositions(((Proposition*)((arguments->theArray)[1])), table, visiblevars);
      }
      else if (testValue000 == KWD_DESCRIPTIONS_EXISTS) {
        { PatternVariable* v = NULL;
          Vector* vector003 = ((Vector*)(dynamicSlotValue(proposition->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES, NULL)));
          int index003 = 0;
          int length003 = vector003->length();

          while (index003 < length003) {
            v = ((PatternVariable*)((vector003->theArray)[index003]));
            index003 = index003 + 1;
            visiblevars = cons(v, visiblevars);
          }
        }
        inferTypesFromPropositions(((Proposition*)((arguments->theArray)[0])), table, visiblevars);
      }
      else {
      }
    }
  }
}

KeyValueList* inferVariableTypesInProposition(Proposition* proposition, Cons* visiblevariables) {
  { KeyValueList* variabletypestable = newKeyValueList();

    { 
      BIND_STELLA_SPECIAL(oADDEDNEWTYPEpo, boolean, FALSE);
      for (;;) {
        oADDEDNEWTYPEpo.set(FALSE);
        inferTypesFromPropositions(proposition, variabletypestable, visiblevariables);
        if (!oADDEDNEWTYPEpo.get()) {
          return (variabletypestable);
        }
      }
    }
  }
}

KeyValueList* inferVariableTypesInDescription(Description* description) {
  { Cons* visiblevariables = NIL;

    { PatternVariable* v = NULL;
      Vector* vector000 = description->ioVariables;
      int index000 = 0;
      int length000 = vector000->length();

      while (index000 < length000) {
        v = ((PatternVariable*)((vector000->theArray)[index000]));
        index000 = index000 + 1;
        visiblevariables = cons(v, visiblevariables);
      }
    }
    { PatternVariable* v = NULL;
      Cons* iter000 = topLevelExistentialVariables(description);

      while (!(iter000 == NIL)) {
        v = ((PatternVariable*)(iter000->value));
        iter000 = iter000->rest;
        visiblevariables = cons(v, visiblevariables);
      }
    }
    return (inferVariableTypesInProposition(description->proposition, visiblevariables));
  }
}

Cons* collectUnresolvedSlotReferences(Proposition* self) {
  { Cons* unresolvedslotreferences = NIL;

    if (getQuotedTree("((:PREDICATE :FUNCTION) \"/LOGIC\")", "/LOGIC")->memberP(self->kind) &&
        isaP(self->operatoR, SGT_DESCRIPTIONS_STELLA_SYMBOL)) {
      unresolvedslotreferences = cons(self, unresolvedslotreferences);
    }
    { Object* arg = NULL;
      Vector* vector000 = self->arguments;
      int index000 = 0;
      int length000 = vector000->length();

      while (index000 < length000) {
        arg = (vector000->theArray)[index000];
        index000 = index000 + 1;
        if (isaP(arg, SGT_DESCRIPTIONS_LOGIC_PROPOSITION)) {
          { Proposition* u = NULL;
            Cons* iter000 = collectUnresolvedSlotReferences(((Proposition*)(arg)));

            while (!(iter000 == NIL)) {
              u = ((Proposition*)(iter000->value));
              iter000 = iter000->rest;
              unresolvedslotreferences = cons(u, unresolvedslotreferences);
            }
          }
        }
      }
    }
    return (unresolvedslotreferences);
  }
}

boolean resolveOneSlotReferenceP(Proposition* proposition, KeyValueList* variabletypestable) {
  { Object* firstargument = (proposition->arguments->theArray)[0];
    Object* predicate = NULL;

    { Surrogate* testValue000 = safePrimaryType(firstargument);

      if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE)) {
        { Object* firstargument000 = firstargument;
          PatternVariable* firstargument = ((PatternVariable*)(firstargument000));

          { List* types = ((List*)(variabletypestable->lookup(firstargument)));

            if (((boolean)(types))) {
              predicate = inferPredicateFromOperatorAndTypes(proposition->operatoR, ((List*)(variabletypestable->lookup(firstargument))));
            }
          }
        }
      }
      else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_LOGIC_OBJECT)) {
        { Object* firstargument001 = firstargument;
          LogicObject* firstargument = ((LogicObject*)(firstargument001));

          { Surrogate* roottype = safeLogicalType(firstargument);

            if (((boolean)(roottype))) {
              predicate = inferPredicateFromOperatorAndTypes(proposition->operatoR, list(1, roottype));
            }
          }
        }
      }
      else {
      }
    }
    if (((boolean)(predicate))) {
      if (subtypeOfP(safePrimaryType(predicate), SGT_DESCRIPTIONS_STELLA_SLOT)) {
        { Object* predicate000 = predicate;
          Slot* predicate = ((Slot*)(predicate000));

          { Surrogate* returntype = unwrapWrappedType(predicate->slotBaseType);

            if (!booleanTypeP(returntype)) {
              proposition->kind = KWD_DESCRIPTIONS_FUNCTION;
              if (variableP((proposition->arguments->theArray)[(proposition->arguments->length() - 1)])) {
                { PatternVariable* lastargument = ((PatternVariable*)((proposition->arguments->theArray)[(proposition->arguments->length() - 1)]));

                  updateSkolemType(lastargument, returntype);
                }
              }
            }
            proposition->operatoR = mostGeneralEquivalentSlotref(predicate->slotSlotref);
            evaluateNewProposition(proposition);
            return (TRUE);
          }
        }
      }
      else {
      }
    }
    return (FALSE);
  }
}

void resolveUnresolvedSlotReferences(Object* formula) {
  { Proposition* proposition = NULL;
    Cons* unresolvedpropositions = NULL;
    KeyValueList* variabletypestable = NULL;
    Cons* unresolvablepropositions = NIL;

    { Surrogate* testValue000 = safePrimaryType(formula);

      if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_DESCRIPTION)) {
        { Object* formula000 = formula;
          Description* formula = ((Description*)(formula000));

          proposition = formula->proposition;
        }
      }
      else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_PROPOSITION)) {
        { Object* formula001 = formula;
          Proposition* formula = ((Proposition*)(formula001));

          proposition = formula;
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    unresolvedpropositions = collectUnresolvedSlotReferences(proposition);
    if (unresolvedpropositions == NIL) {
      return;
    }
    { Surrogate* testValue001 = safePrimaryType(formula);

      if (subtypeOfP(testValue001, SGT_DESCRIPTIONS_LOGIC_DESCRIPTION)) {
        { Object* formula002 = formula;
          Description* formula = ((Description*)(formula002));

          variabletypestable = inferVariableTypesInDescription(formula);
        }
      }
      else if (subtypeOfP(testValue001, SGT_DESCRIPTIONS_LOGIC_PROPOSITION)) {
        { Object* formula003 = formula;
          Proposition* formula = ((Proposition*)(formula003));

          variabletypestable = inferVariableTypesInProposition(formula, NIL);
        }
      }
      else {
        { OutputStringStream* stream001 = newOutputStringStream();

          *(stream001->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
          throw *newStellaException(stream001->theStringReader());
        }
      }
    }
    { Proposition* prop = NULL;
      Cons* iter000 = unresolvedpropositions;
      Cons* collect000 = NULL;

      while (!(iter000 == NIL)) {
        prop = ((Proposition*)(iter000->value));
        iter000 = iter000->rest;
        if (symbolP(prop->operatoR) &&
            (!resolveOneSlotReferenceP(prop, variabletypestable))) {
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(prop, NIL);
              if (unresolvablepropositions == NIL) {
                unresolvablepropositions = collect000;
              }
              else {
                addConsToEndOfConsList(unresolvablepropositions, collect000);
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
    if (!(unresolvablepropositions == NIL)) {
      { Proposition* p = NULL;
        Cons* iter001 = unresolvablepropositions;

        while (!(iter001 == NIL)) {
          p = ((Proposition*)(iter001->value));
          iter001 = iter001->rest;
          complainAboutUndeclaredReference(p);
          createDummyRelation(p);
        }
      }
    }
  }
}

void createDummyRelation(Proposition* waywardproposition) {
  { List* fakevariabletypes = newList();
    Symbol* symbolref = ((Symbol*)(waywardproposition->operatoR));
    Surrogate* relationref = symbolToSurrogate(symbolref);
    NamedDescription* description = NULL;

    { IntegerIntervalIterator* i = interval(1, waywardproposition->arguments->length());

      while (i->nextP()) {
        fakevariabletypes->push(SGT_DESCRIPTIONS_STELLA_THING);
      }
    }
    description = createPrimitiveDescription(NIL_LIST, fakevariabletypes, FALSE, waywardproposition->kind == KWD_DESCRIPTIONS_ISA, waywardproposition->kind == KWD_DESCRIPTIONS_FUNCTION, ((Module*)(relationref->homeContext)));
    waywardproposition->operatoR = relationref;
    bindLogicObjectToSurrogate(symbolref, description);
    setDynamicSlotValue(description->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_UNDECLAREDp, (TRUE ? TRUE_WRAPPER : FALSE_WRAPPER), FALSE_WRAPPER);
  }
}

boolean definedRelationP(NamedDescription* self) {
  return ((!((BooleanWrapper*)(dynamicSlotValue(self->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_UNDECLAREDp, FALSE_WRAPPER)))->wrapperValue) &&
      ((stringifiedSource(self) != NULL) ||
       ((boolean)(self->nativeRelation()))));
}

Cons* listUndefinedRelations(Object* module, boolean localP) {
  // Return a list of as yet undefined concepts and relations in `module'.
  // These relations were defined by the system, since they were referenced
  // but have not yet been defined by the user.  If `module' is NULL look in
  // the current module.  If `local?' only look in `module' but not in any
  // modules it inherits.
  { Module* themodule = coerceToModule(module, TRUE);

    if (((boolean)(themodule))) {
      if (!((boolean)(module))) {
        themodule = NULL;
      }
    }
    if (!((boolean)(themodule))) {
      themodule = oMODULEo.get();
    }
    return (callListUndefinedRelations(themodule, localP));
  }
}

Cons* listUndefinedRelationsEvaluatorWrapper(Cons* arguments) {
  return (listUndefinedRelations(arguments->value, ((BooleanWrapper*)(arguments->rest->value))->wrapperValue));
}

Cons* callListUndefinedRelations(Module* module, boolean localP) {
  // Callable version of `list-undefined-relations' (which see).
  { TruthValue* dummy1;

    { Cons* undefined = NIL;

      finalizeObjects();
      { Object* term = NULL;
        Iterator* iter000 = allNamedTerms(module, localP);

        while (iter000->nextP()) {
          term = iter000->value;
          { Surrogate* testValue000 = safePrimaryType(term);

            if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_NAMED_DESCRIPTION)) {
              { Object* term000 = term;
                NamedDescription* term = ((NamedDescription*)(term000));

                if (!definedRelationP(term)) {
                  undefined = cons(term, undefined);
                }
              }
            }
            else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_LOGIC_OBJECT)) {
              { Object* term001 = term;
                LogicObject* term = ((LogicObject*)(term001));

                { 
                  BIND_STELLA_SPECIAL(oMODULEo, Module*, ((!((boolean)(module))) ? term->homeModule() : module));
                  BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
                  if (applyCachedAsk(cons(SYM_DESCRIPTIONS_LOGIC_pX, NIL), listO(3, SYM_DESCRIPTIONS_PL_KERNEL_KB_RELATION, SYM_DESCRIPTIONS_LOGIC_pX, NIL), consList(1, term), consList(0), SYM_DESCRIPTIONS_LOGIC_QUERY_038, dummy1)) {
                    undefined = cons(term, undefined);
                  }
                }
              }
            }
            else {
            }
          }
        }
      }
      return (undefined);
    }
  }
}

void complainAboutUndeclaredReference(Proposition* waywardproposition) {
  if (((BooleanWrapper*)(dynamicSlotValue(waywardproposition->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTIVEp, FALSE_WRAPPER)))->wrapperValue) {
    { OutputStringStream* stream000 = newOutputStringStream();

      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
        *(stream000->nativeStream) << "ERROR: " << "Undeclared predicate or function reference: " << "`" << waywardproposition->operatoR << "'" << "." << std::endl;
        helpSignalPropositionError(stream000, KWD_DESCRIPTIONS_ERROR);
      }
      throw *newPropositionError(stream000->theStringReader());
    }
  }
  else {
    { 
      BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
      *(STANDARD_WARNING->nativeStream) << "WARNING: " << "Undeclared predicate or function reference: " << waywardproposition->operatoR << std::endl;
      helpSignalPropositionError(STANDARD_WARNING, KWD_DESCRIPTIONS_WARNING);
    }
  }
}

boolean allNamedDescriptionsNextP(AllPurposeIterator* self) {
  { int cursor = self->iteratorInteger;
    Surrogate* surrogate = NULL;
    Object* surrogatevalue = NULL;
    NamedDescription* description = NULL;

    while (cursor < self->iteratorSecondInteger) {
      surrogate = ((Surrogate*)((oSURROGATE_ARRAYo->theArray)[cursor]));
      if (((boolean)(surrogate)) &&
          selectedMetaObjectP(self, ((Module*)(surrogate->homeContext)))) {
        surrogatevalue = surrogate->surrogateValue;
      }
      description = NULL;
      if (((boolean)(surrogatevalue))) {
        { Surrogate* testValue000 = safePrimaryType(surrogatevalue);

          if (subtypeOfClassP(testValue000)) {
            { Object* surrogatevalue000 = surrogatevalue;
              Class* surrogatevalue = ((Class*)(surrogatevalue000));

              if (((Class*)(surrogatevalue))->classType == surrogate) {
                description = ((NamedDescription*)(dynamicSlotValue(surrogatevalue->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL)));
              }
            }
          }
          else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_STELLA_RELATION)) {
            { Object* surrogatevalue001 = surrogatevalue;
              Relation* surrogatevalue = ((Relation*)(surrogatevalue001));

              description = ((NamedDescription*)(dynamicSlotValue(surrogatevalue->dynamicSlots, SYM_DESCRIPTIONS_LOGIC_DESCRIPTION, NULL)));
            }
          }
          else if (subtypeOfP(testValue000, SGT_DESCRIPTIONS_LOGIC_NAMED_DESCRIPTION)) {
            { Object* surrogatevalue002 = surrogatevalue;
              NamedDescription* surrogatevalue = ((NamedDescription*)(surrogatevalue002));

              description = surrogatevalue;
            }
          }
          else {
          }
        }
      }
      if (((boolean)(description))) {
        self->value = description;
        self->iteratorInteger = cursor + 1;
        return (TRUE);
      }
      cursor = cursor + 1;
    }
    return (FALSE);
  }
}

Iterator* allNamedDescriptions(Module* module, boolean localP) {
  // Iterate over all named descriptions visible from 'module'.
  // If 'local?', return only named descriptions interned in 'module'.
  // If 'module' is null, return all named descriptions interned everywhere.
  return (allocateAllMetaObjectsIterator(oSURROGATE_ARRAYo->topSymbolOffset + 1, ((cpp_function_code)(&allNamedDescriptionsNextP)), module, localP));
}

void helpStartupDescriptions1() {
  {
    SGT_DESCRIPTIONS_STELLA_SLOT = ((Surrogate*)(internRigidSymbolWrtModule("SLOT", getStellaModule("/STELLA", TRUE), 1)));
    SGT_DESCRIPTIONS_STELLA_METHOD_SLOT = ((Surrogate*)(internRigidSymbolWrtModule("METHOD-SLOT", getStellaModule("/STELLA", TRUE), 1)));
    SYM_DESCRIPTIONS_STELLA_ANY_VALUE = ((Symbol*)(internRigidSymbolWrtModule("ANY-VALUE", getStellaModule("/STELLA", TRUE), 0)));
    KWD_DESCRIPTIONS_EXTENSIONAL_ASSERTION = ((Keyword*)(internRigidSymbolWrtModule("EXTENSIONAL-ASSERTION", NULL, 2)));
    SGT_DESCRIPTIONS_PL_KERNEL_KB_RELATION = ((Surrogate*)(internRigidSymbolWrtModule("RELATION", getStellaModule("/PL-KERNEL-KB", TRUE), 1)));
    SGT_DESCRIPTIONS_PL_KERNEL_KB_POLYMORPHIC = ((Surrogate*)(internRigidSymbolWrtModule("POLYMORPHIC", getStellaModule("/PL-KERNEL-KB", TRUE), 1)));
    SYM_DESCRIPTIONS_LOGIC_pX1 = ((Symbol*)(internRigidSymbolWrtModule("?X1", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX2 = ((Symbol*)(internRigidSymbolWrtModule("?X2", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX3 = ((Symbol*)(internRigidSymbolWrtModule("?X3", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX4 = ((Symbol*)(internRigidSymbolWrtModule("?X4", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX5 = ((Symbol*)(internRigidSymbolWrtModule("?X5", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX6 = ((Symbol*)(internRigidSymbolWrtModule("?X6", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX7 = ((Symbol*)(internRigidSymbolWrtModule("?X7", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX8 = ((Symbol*)(internRigidSymbolWrtModule("?X8", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX9 = ((Symbol*)(internRigidSymbolWrtModule("?X9", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX10 = ((Symbol*)(internRigidSymbolWrtModule("?X10", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX11 = ((Symbol*)(internRigidSymbolWrtModule("?X11", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX12 = ((Symbol*)(internRigidSymbolWrtModule("?X12", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX13 = ((Symbol*)(internRigidSymbolWrtModule("?X13", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX14 = ((Symbol*)(internRigidSymbolWrtModule("?X14", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX15 = ((Symbol*)(internRigidSymbolWrtModule("?X15", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX16 = ((Symbol*)(internRigidSymbolWrtModule("?X16", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX17 = ((Symbol*)(internRigidSymbolWrtModule("?X17", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX18 = ((Symbol*)(internRigidSymbolWrtModule("?X18", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX19 = ((Symbol*)(internRigidSymbolWrtModule("?X19", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX20 = ((Symbol*)(internRigidSymbolWrtModule("?X20", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX21 = ((Symbol*)(internRigidSymbolWrtModule("?X21", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX22 = ((Symbol*)(internRigidSymbolWrtModule("?X22", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX23 = ((Symbol*)(internRigidSymbolWrtModule("?X23", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX24 = ((Symbol*)(internRigidSymbolWrtModule("?X24", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX25 = ((Symbol*)(internRigidSymbolWrtModule("?X25", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX26 = ((Symbol*)(internRigidSymbolWrtModule("?X26", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX27 = ((Symbol*)(internRigidSymbolWrtModule("?X27", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX28 = ((Symbol*)(internRigidSymbolWrtModule("?X28", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX29 = ((Symbol*)(internRigidSymbolWrtModule("?X29", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX30 = ((Symbol*)(internRigidSymbolWrtModule("?X30", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX31 = ((Symbol*)(internRigidSymbolWrtModule("?X31", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX32 = ((Symbol*)(internRigidSymbolWrtModule("?X32", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX33 = ((Symbol*)(internRigidSymbolWrtModule("?X33", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX34 = ((Symbol*)(internRigidSymbolWrtModule("?X34", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX35 = ((Symbol*)(internRigidSymbolWrtModule("?X35", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX36 = ((Symbol*)(internRigidSymbolWrtModule("?X36", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX37 = ((Symbol*)(internRigidSymbolWrtModule("?X37", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX38 = ((Symbol*)(internRigidSymbolWrtModule("?X38", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX39 = ((Symbol*)(internRigidSymbolWrtModule("?X39", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX40 = ((Symbol*)(internRigidSymbolWrtModule("?X40", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX41 = ((Symbol*)(internRigidSymbolWrtModule("?X41", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX42 = ((Symbol*)(internRigidSymbolWrtModule("?X42", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX43 = ((Symbol*)(internRigidSymbolWrtModule("?X43", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX44 = ((Symbol*)(internRigidSymbolWrtModule("?X44", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX45 = ((Symbol*)(internRigidSymbolWrtModule("?X45", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX46 = ((Symbol*)(internRigidSymbolWrtModule("?X46", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX47 = ((Symbol*)(internRigidSymbolWrtModule("?X47", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX48 = ((Symbol*)(internRigidSymbolWrtModule("?X48", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX49 = ((Symbol*)(internRigidSymbolWrtModule("?X49", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX50 = ((Symbol*)(internRigidSymbolWrtModule("?X50", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX51 = ((Symbol*)(internRigidSymbolWrtModule("?X51", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX52 = ((Symbol*)(internRigidSymbolWrtModule("?X52", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX53 = ((Symbol*)(internRigidSymbolWrtModule("?X53", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX54 = ((Symbol*)(internRigidSymbolWrtModule("?X54", NULL, 0)));
  }
}

void helpStartupDescriptions2() {
  {
    SYM_DESCRIPTIONS_LOGIC_pX55 = ((Symbol*)(internRigidSymbolWrtModule("?X55", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX56 = ((Symbol*)(internRigidSymbolWrtModule("?X56", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX57 = ((Symbol*)(internRigidSymbolWrtModule("?X57", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX58 = ((Symbol*)(internRigidSymbolWrtModule("?X58", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX59 = ((Symbol*)(internRigidSymbolWrtModule("?X59", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX60 = ((Symbol*)(internRigidSymbolWrtModule("?X60", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX61 = ((Symbol*)(internRigidSymbolWrtModule("?X61", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX62 = ((Symbol*)(internRigidSymbolWrtModule("?X62", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX63 = ((Symbol*)(internRigidSymbolWrtModule("?X63", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX64 = ((Symbol*)(internRigidSymbolWrtModule("?X64", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX65 = ((Symbol*)(internRigidSymbolWrtModule("?X65", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX66 = ((Symbol*)(internRigidSymbolWrtModule("?X66", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX67 = ((Symbol*)(internRigidSymbolWrtModule("?X67", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX68 = ((Symbol*)(internRigidSymbolWrtModule("?X68", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX69 = ((Symbol*)(internRigidSymbolWrtModule("?X69", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX70 = ((Symbol*)(internRigidSymbolWrtModule("?X70", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX71 = ((Symbol*)(internRigidSymbolWrtModule("?X71", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX72 = ((Symbol*)(internRigidSymbolWrtModule("?X72", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX73 = ((Symbol*)(internRigidSymbolWrtModule("?X73", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX74 = ((Symbol*)(internRigidSymbolWrtModule("?X74", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX75 = ((Symbol*)(internRigidSymbolWrtModule("?X75", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX76 = ((Symbol*)(internRigidSymbolWrtModule("?X76", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX77 = ((Symbol*)(internRigidSymbolWrtModule("?X77", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX78 = ((Symbol*)(internRigidSymbolWrtModule("?X78", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX79 = ((Symbol*)(internRigidSymbolWrtModule("?X79", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX80 = ((Symbol*)(internRigidSymbolWrtModule("?X80", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX81 = ((Symbol*)(internRigidSymbolWrtModule("?X81", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX82 = ((Symbol*)(internRigidSymbolWrtModule("?X82", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX83 = ((Symbol*)(internRigidSymbolWrtModule("?X83", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX84 = ((Symbol*)(internRigidSymbolWrtModule("?X84", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX85 = ((Symbol*)(internRigidSymbolWrtModule("?X85", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX86 = ((Symbol*)(internRigidSymbolWrtModule("?X86", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX87 = ((Symbol*)(internRigidSymbolWrtModule("?X87", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX88 = ((Symbol*)(internRigidSymbolWrtModule("?X88", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX89 = ((Symbol*)(internRigidSymbolWrtModule("?X89", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX90 = ((Symbol*)(internRigidSymbolWrtModule("?X90", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX91 = ((Symbol*)(internRigidSymbolWrtModule("?X91", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX92 = ((Symbol*)(internRigidSymbolWrtModule("?X92", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX93 = ((Symbol*)(internRigidSymbolWrtModule("?X93", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX94 = ((Symbol*)(internRigidSymbolWrtModule("?X94", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX95 = ((Symbol*)(internRigidSymbolWrtModule("?X95", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX96 = ((Symbol*)(internRigidSymbolWrtModule("?X96", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX97 = ((Symbol*)(internRigidSymbolWrtModule("?X97", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX98 = ((Symbol*)(internRigidSymbolWrtModule("?X98", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX99 = ((Symbol*)(internRigidSymbolWrtModule("?X99", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX100 = ((Symbol*)(internRigidSymbolWrtModule("?X100", NULL, 0)));
    SGT_DESCRIPTIONS_LOGIC_NAMED_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("NAMED-DESCRIPTION", NULL, 1)));
    SYM_DESCRIPTIONS_STELLA_ISA = ((Symbol*)(internRigidSymbolWrtModule("ISA", getStellaModule("/STELLA", TRUE), 0)));
    SYM_DESCRIPTIONS_LOGIC_KAPPA = ((Symbol*)(internRigidSymbolWrtModule("KAPPA", NULL, 0)));
    KWD_DESCRIPTIONS_KIF = ((Keyword*)(internRigidSymbolWrtModule("KIF", NULL, 2)));
    KWD_DESCRIPTIONS_DESCRIPTION = ((Keyword*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 2)));
    SGT_DESCRIPTIONS_PL_KERNEL_KB_CONCEPT = ((Surrogate*)(internRigidSymbolWrtModule("CONCEPT", getStellaModule("/PL-KERNEL-KB", TRUE), 1)));
    SGT_DESCRIPTIONS_PL_KERNEL_KB_FUNCTION = ((Surrogate*)(internRigidSymbolWrtModule("FUNCTION", getStellaModule("/PL-KERNEL-KB", TRUE), 1)));
    SGT_DESCRIPTIONS_PL_KERNEL_KB_VARIABLE_ARITY = ((Surrogate*)(internRigidSymbolWrtModule("VARIABLE-ARITY", getStellaModule("/PL-KERNEL-KB", TRUE), 1)));
    SYM_DESCRIPTIONS_LOGIC_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 0)));
    SGT_DESCRIPTIONS_STELLA_CLASS = ((Surrogate*)(internRigidSymbolWrtModule("CLASS", getStellaModule("/STELLA", TRUE), 1)));
    KWD_DESCRIPTIONS_ERROR = ((Keyword*)(internRigidSymbolWrtModule("ERROR", NULL, 2)));
    SGT_DESCRIPTIONS_STELLA_RELATION = ((Surrogate*)(internRigidSymbolWrtModule("RELATION", getStellaModule("/STELLA", TRUE), 1)));
    SYM_DESCRIPTIONS_LOGIC_OBJECT_STORE = ((Symbol*)(internRigidSymbolWrtModule("OBJECT-STORE", NULL, 0)));
    SGT_DESCRIPTIONS_STELLA_THING = ((Surrogate*)(internRigidSymbolWrtModule("THING", getStellaModule("/STELLA", TRUE), 1)));
  }
}

void helpStartupDescriptions3() {
  {
    SGT_DESCRIPTIONS_STELLA_LITERAL = ((Surrogate*)(internRigidSymbolWrtModule("LITERAL", getStellaModule("/STELLA", TRUE), 1)));
    SGT_DESCRIPTIONS_LOGIC_PROPOSITION = ((Surrogate*)(internRigidSymbolWrtModule("PROPOSITION", NULL, 1)));
    KWD_DESCRIPTIONS_WARNING = ((Keyword*)(internRigidSymbolWrtModule("WARNING", NULL, 2)));
    SGT_DESCRIPTIONS_STELLA_CONS = ((Surrogate*)(internRigidSymbolWrtModule("CONS", getStellaModule("/STELLA", TRUE), 1)));
    KWD_DESCRIPTIONS_ISA = ((Keyword*)(internRigidSymbolWrtModule("ISA", NULL, 2)));
    SYM_DESCRIPTIONS_LOGIC_VARIABLE_TYPEp = ((Symbol*)(internRigidSymbolWrtModule("VARIABLE-TYPE?", NULL, 0)));
    SYM_DESCRIPTIONS_STELLA_EXISTS = ((Symbol*)(internRigidSymbolWrtModule("EXISTS", getStellaModule("/STELLA", TRUE), 0)));
    SYM_DESCRIPTIONS_LOGIC_ENTITY_MAPPING = ((Symbol*)(internRigidSymbolWrtModule("ENTITY-MAPPING", NULL, 0)));
    KWD_DESCRIPTIONS_AND = ((Keyword*)(internRigidSymbolWrtModule("AND", NULL, 2)));
    KWD_DESCRIPTIONS_OR = ((Keyword*)(internRigidSymbolWrtModule("OR", NULL, 2)));
    KWD_DESCRIPTIONS_EQUIVALENT = ((Keyword*)(internRigidSymbolWrtModule("EQUIVALENT", NULL, 2)));
    KWD_DESCRIPTIONS_FORALL = ((Keyword*)(internRigidSymbolWrtModule("FORALL", NULL, 2)));
    KWD_DESCRIPTIONS_EXISTS = ((Keyword*)(internRigidSymbolWrtModule("EXISTS", NULL, 2)));
    SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES = ((Symbol*)(internRigidSymbolWrtModule("IO-VARIABLES", NULL, 0)));
    SGT_DESCRIPTIONS_PL_KERNEL_KB_HOLDS = ((Surrogate*)(internRigidSymbolWrtModule("HOLDS", getStellaModule("/PL-KERNEL-KB", TRUE), 1)));
    KWD_DESCRIPTIONS_FUNCTION = ((Keyword*)(internRigidSymbolWrtModule("FUNCTION", NULL, 2)));
    SGT_DESCRIPTIONS_STELLA_SET = ((Surrogate*)(internRigidSymbolWrtModule("SET", getStellaModule("/STELLA", TRUE), 1)));
    SGT_DESCRIPTIONS_STELLA_LIST = ((Surrogate*)(internRigidSymbolWrtModule("LIST", getStellaModule("/STELLA", TRUE), 1)));
    SGT_DESCRIPTIONS_STELLA_SURROGATE = ((Surrogate*)(internRigidSymbolWrtModule("SURROGATE", getStellaModule("/STELLA", TRUE), 1)));
    SGT_DESCRIPTIONS_LOGIC_DESCRIPTION = ((Surrogate*)(internRigidSymbolWrtModule("DESCRIPTION", NULL, 1)));
    KWD_DESCRIPTIONS_NOT = ((Keyword*)(internRigidSymbolWrtModule("NOT", NULL, 2)));
    SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME = ((Symbol*)(internRigidSymbolWrtModule("ORIGINAL-SKOLEM-NAME", NULL, 0)));
    SGT_DESCRIPTIONS_STELLA_GENERALIZED_SYMBOL = ((Surrogate*)(internRigidSymbolWrtModule("GENERALIZED-SYMBOL", getStellaModule("/STELLA", TRUE), 1)));
    SYM_DESCRIPTIONS_STELLA_AND = ((Symbol*)(internRigidSymbolWrtModule("AND", getStellaModule("/STELLA", TRUE), 0)));
    SYM_DESCRIPTIONS_STELLA_OR = ((Symbol*)(internRigidSymbolWrtModule("OR", getStellaModule("/STELLA", TRUE), 0)));
    SYM_DESCRIPTIONS_STELLA_NOT = ((Symbol*)(internRigidSymbolWrtModule("NOT", getStellaModule("/STELLA", TRUE), 0)));
    SYM_DESCRIPTIONS_STELLA_FORALL = ((Symbol*)(internRigidSymbolWrtModule("FORALL", getStellaModule("/STELLA", TRUE), 0)));
    SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE = ((Surrogate*)(internRigidSymbolWrtModule("PATTERN-VARIABLE", NULL, 1)));
    SGT_DESCRIPTIONS_LOGIC_LOGIC_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("LOGIC-OBJECT", NULL, 1)));
    SYM_DESCRIPTIONS_LOGIC_EXTERNAL_VARIABLES = ((Symbol*)(internRigidSymbolWrtModule("EXTERNAL-VARIABLES", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_DEPENDENT_DESCRIPTIONS = ((Symbol*)(internRigidSymbolWrtModule("DEPENDENT-DESCRIPTIONS", NULL, 0)));
    KWD_DESCRIPTIONS_PREDICATE = ((Keyword*)(internRigidSymbolWrtModule("PREDICATE", NULL, 2)));
    KWD_DESCRIPTIONS_IMPLIES = ((Keyword*)(internRigidSymbolWrtModule("IMPLIES", NULL, 2)));
    SGT_DESCRIPTIONS_STELLA_PROPOSITIONdIF = ((Surrogate*)(internRigidSymbolWrtModule("PROPOSITION.IF", getStellaModule("/STELLA", TRUE), 1)));
    SGT_DESCRIPTIONS_STELLA_CS_VALUE = ((Surrogate*)(internRigidSymbolWrtModule("CS-VALUE", getStellaModule("/STELLA", TRUE), 1)));
    SYM_DESCRIPTIONS_LOGIC_THE_ONLY = ((Symbol*)(internRigidSymbolWrtModule("THE-ONLY", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_IOTAp = ((Symbol*)(internRigidSymbolWrtModule("IOTA?", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_COMPLEMENT_DESCRIPTION = ((Symbol*)(internRigidSymbolWrtModule("COMPLEMENT-DESCRIPTION", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_VARIABLE_TYPE_TABLE = ((Symbol*)(internRigidSymbolWrtModule("VARIABLE-TYPE-TABLE", NULL, 0)));
    SGT_DESCRIPTIONS_STELLA_SYMBOL = ((Surrogate*)(internRigidSymbolWrtModule("SYMBOL", getStellaModule("/STELLA", TRUE), 1)));
    SYM_DESCRIPTIONS_LOGIC_UNDECLAREDp = ((Symbol*)(internRigidSymbolWrtModule("UNDECLARED?", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_pX = ((Symbol*)(internRigidSymbolWrtModule("?X", NULL, 0)));
    SYM_DESCRIPTIONS_PL_KERNEL_KB_RELATION = ((Symbol*)(internRigidSymbolWrtModule("RELATION", getStellaModule("/PL-KERNEL-KB", TRUE), 0)));
    SYM_DESCRIPTIONS_LOGIC_QUERY_038 = ((Symbol*)(internRigidSymbolWrtModule("QUERY-038", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_DESCRIPTIVEp = ((Symbol*)(internRigidSymbolWrtModule("DESCRIPTIVE?", NULL, 0)));
    SYM_DESCRIPTIONS_LOGIC_STARTUP_DESCRIPTIONS = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-DESCRIPTIONS", NULL, 0)));
    SYM_DESCRIPTIONS_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", TRUE), 0)));
  }
}

void helpStartupDescriptions4() {
  {
    defineExternalSlotFromStringifiedSource("(DEFSLOT RELATION DESCRIPTION :TYPE NAMED-DESCRIPTION :DOCUMENTATION \"Maps a relation (class or slot or table) to a\nprimitive description.\" :ALLOCATION :DYNAMIC)");
    defineFunctionObject("DIRECT-SUPERRELATIONS", "(DEFUN (DIRECT-SUPERRELATIONS (ITERATOR OF (LIKE SELF))) ((SELF RELATION)) :DOCUMENTATION \"Return direct super classes/slots of 'self'.\")", ((cpp_function_code)(&directSuperrelations)), NULL);
    defineFunctionObject("SLOT-COLUMN-TYPES", "(DEFUN (SLOT-COLUMN-TYPES (CONS OF TYPE)) ((SELF SLOT) (COUNT INTEGER)))", ((cpp_function_code)(&slotColumnTypes)), NULL);
    defineFunctionObject("CREATE-DESCRIPTION", "(DEFUN (CREATE-DESCRIPTION DESCRIPTION) ((ARITY INTEGER) (NAMED? BOOLEAN)) :PUBLIC? TRUE)", ((cpp_function_code)(&createDescription)), NULL);
    defineMethodObject("(DEFMETHOD (DESCRIPTION-NAME SYMBOL) ((SELF DESCRIPTION)) :DOCUMENTATION \"Return the name of the description `self', if it has one.\" :PUBLIC? TRUE)", ((cpp_method_code)(&Description::descriptionName)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD (DESCRIPTION-NAME SYMBOL) ((SELF NAMED-DESCRIPTION)) :DOCUMENTATION \"Return the name of the description `self'.\" :PUBLIC? TRUE)", ((cpp_method_code)(&NamedDescription::descriptionName)), ((cpp_method_code)(NULL)));
    defineFunctionObject("CREATE-BASE-RELATION-FOR-POLYMORPHIC-DESCRIPTION", "(DEFUN CREATE-BASE-RELATION-FOR-POLYMORPHIC-DESCRIPTION ((DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&createBaseRelationForPolymorphicDescription)), NULL);
    defineFunctionObject("YIELD-SYSTEM-DEFINED-PARAMETER-NAME", "(DEFUN (YIELD-SYSTEM-DEFINED-PARAMETER-NAME SYMBOL) ((INDEX INTEGER) (REFERENCEOBJECT OBJECT)))", ((cpp_function_code)(&yieldSystemDefinedParameterName)), NULL);
    defineFunctionObject("ENSURE-DESCRIPTION-BODY", "(DEFUN ENSURE-DESCRIPTION-BODY ((DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&ensureDescriptionBody)), NULL);
    defineFunctionObject("MATERIALIZE-PRIMITIVE-DESCRIPTION-BODY", "(DEFUN MATERIALIZE-PRIMITIVE-DESCRIPTION-BODY ((DESCRIPTION NAMED-DESCRIPTION)))", ((cpp_function_code)(&materializePrimitiveDescriptionBody)), NULL);
    defineFunctionObject("CREATE-PRIMITIVE-DESCRIPTION", "(DEFUN (CREATE-PRIMITIVE-DESCRIPTION NAMED-DESCRIPTION) ((IOVARIABLENAMES (LIST OF SYMBOL)) (IOVARIABLETYPES (LIST OF TYPE)) (VARIABLEARITY? BOOLEAN) (CLASS? BOOLEAN) (FUNCTION? BOOLEAN) (MODULE MODULE)))", ((cpp_function_code)(&createPrimitiveDescription)), NULL);
    defineFunctionObject("LINK-STELLA-RELATION-AND-DESCRIPTION", "(DEFUN LINK-STELLA-RELATION-AND-DESCRIPTION ((SELF RELATION) (DESCRIPTION NAMED-DESCRIPTION)))", ((cpp_function_code)(&linkStellaRelationAndDescription)), NULL);
    defineFunctionObject("CREATE-DESCRIPTION-FOR-STELLA-RELATION", "(DEFUN (CREATE-DESCRIPTION-FOR-STELLA-RELATION NAMED-DESCRIPTION) ((SELF RELATION)))", ((cpp_function_code)(&createDescriptionForStellaRelation)), NULL);
    defineFunctionObject("SURROGATE-TO-DESCRIPTION", "(DEFUN (SURROGATE-TO-DESCRIPTION NAMED-DESCRIPTION) ((SELF SURROGATE)))", ((cpp_function_code)(&surrogateToDescription)), NULL);
    defineFunctionObject("GET-DESCRIPTION", "(DEFUN (GET-DESCRIPTION NAMED-DESCRIPTION) ((SELF OBJECT)) :PUBLIC? TRUE)", ((cpp_function_code)(&getDescription)), NULL);
    defineFunctionObject("SURROGATE.GET-DESCRIPTION", "(DEFUN (SURROGATE.GET-DESCRIPTION NAMED-DESCRIPTION) ((SELF SURROGATE)))", ((cpp_function_code)(&surrogateDgetDescription)), NULL);
    defineFunctionObject("STRING.GET-DESCRIPTION", "(DEFUN (STRING.GET-DESCRIPTION NAMED-DESCRIPTION) ((SELF STRING)))", ((cpp_function_code)(&stringDgetDescription)), NULL);
    defineFunctionObject("CLASS.GET-DESCRIPTION", "(DEFUN (CLASS.GET-DESCRIPTION NAMED-DESCRIPTION) ((SELF CLASS)))", ((cpp_function_code)(&classDgetDescription)), NULL);
    defineFunctionObject("SLOT.GET-DESCRIPTION", "(DEFUN (SLOT.GET-DESCRIPTION NAMED-DESCRIPTION) ((SELF SLOT)))", ((cpp_function_code)(&slotDgetDescription)), NULL);
    defineFunctionObject("ENSURE-DEFERRED-DESCRIPTION", "(DEFUN (ENSURE-DEFERRED-DESCRIPTION SURROGATE) ((SELF SURROGATE)))", ((cpp_function_code)(&ensureDeferredDescription)), NULL);
    defineFunctionObject("LOGIC-CLASS?", "(DEFUN (LOGIC-CLASS? BOOLEAN) ((SELF CLASS)) :DOCUMENTATION \"Return TRUE if the class 'self' or one of its\nsupers supports indices that record extensions referenced by\nthe logic system. Also return true for literal classes.\")", ((cpp_function_code)(&logicClassP)), NULL);
    defineFunctionObject("VARIABLE-ARITY-DOMAIN-TYPES-NEXT?", "(DEFUN (VARIABLE-ARITY-DOMAIN-TYPES-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))", ((cpp_function_code)(&variableArityDomainTypesNextP)), NULL);
    defineFunctionObject("ALL-DOMAIN-TYPES", "(DEFUN (ALL-DOMAIN-TYPES ITERATOR) ((SELF NAMED-DESCRIPTION)))", ((cpp_function_code)(&allDomainTypes)), NULL);
    defineFunctionObject("PUSH-LOGIC-VARIABLE-BINDING", "(DEFUN PUSH-LOGIC-VARIABLE-BINDING ((VARIABLE SKOLEM)))", ((cpp_function_code)(&pushLogicVariableBinding)), NULL);
    defineFunctionObject("POP-LOGIC-VARIABLE-BINDING", "(DEFUN POP-LOGIC-VARIABLE-BINDING ())", ((cpp_function_code)(&popLogicVariableBinding)), NULL);
    defineFunctionObject("POP-LOGIC-VARIABLE-BINDINGS", "(DEFUN POP-LOGIC-VARIABLE-BINDINGS ((VARIABLES (CONS OF SKOLEM))))", ((cpp_function_code)(&popLogicVariableBindings)), NULL);
    defineFunctionObject("LOOKUP-LOGIC-VARIABLE-BINDING", "(DEFUN (LOOKUP-LOGIC-VARIABLE-BINDING OBJECT) ((VARIABLENAME SYMBOL)))", ((cpp_function_code)(&lookupLogicVariableBinding)), NULL);
    defineFunctionObject("PARSE-ONE-VARIABLE-DECLARATION", "(DEFUN PARSE-ONE-VARIABLE-DECLARATION ((VDEC OBJECT) (LOCALDECLARATIONS (LIST OF PATTERN-VARIABLE))))", ((cpp_function_code)(&parseOneVariableDeclaration)), NULL);
    defineFunctionObject("PARSE-LOGIC-VARIABLE-DECLARATIONS", "(DEFUN (PARSE-LOGIC-VARIABLE-DECLARATIONS (CONS OF PATTERN-VARIABLE)) ((TREE OBJECT)))", ((cpp_function_code)(&parseLogicVariableDeclarations)), NULL);
    defineFunctionObject("HELP-BUILD-QUANTIFIED-PROPOSITION", "(DEFUN (HELP-BUILD-QUANTIFIED-PROPOSITION (CONS OF SKOLEM) PROPOSITION PROPOSITION) ((TREE CONS) (CONVERTTYPESTOCONSTRAINTS? BOOLEAN)))", ((cpp_function_code)(&helpBuildQuantifiedProposition)), NULL);
    defineFunctionObject("BUILD-QUANTIFIED-PROPOSITION", "(DEFUN (BUILD-QUANTIFIED-PROPOSITION (CONS OF SKOLEM) PROPOSITION PROPOSITION) ((TREE CONS) (CONVERTTYPESTOCONSTRAINTS? BOOLEAN)))", ((cpp_function_code)(&buildQuantifiedProposition)), NULL);
    defineFunctionObject("COPY-CONS-LIST-TO-VARIABLES-VECTOR", "(DEFUN (COPY-CONS-LIST-TO-VARIABLES-VECTOR VARIABLES-VECTOR) ((CONSLIST CONS)))", ((cpp_function_code)(&copyConsListToVariablesVector)), NULL);
    defineFunctionObject("EQUIVALENT-HOLDS-PROPOSITION?", "(DEFUN (EQUIVALENT-HOLDS-PROPOSITION? BOOLEAN) ((SELF PROPOSITION) (OTHER PROPOSITION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&equivalentHoldsPropositionP)), NULL);
    defineFunctionObject("EQUIVALENT-COMMUTATIVE-PROPOSITIONS?", "(DEFUN (EQUIVALENT-COMMUTATIVE-PROPOSITIONS? BOOLEAN) ((SELF PROPOSITION) (OTHER PROPOSITION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&equivalentCommutativePropositionsP)), NULL);
    defineFunctionObject("EQUIVALENT-PROPOSITIONS?", "(DEFUN (EQUIVALENT-PROPOSITIONS? BOOLEAN) ((SELF PROPOSITION) (OTHER PROPOSITION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&equivalentPropositionsP)), NULL);
    defineFunctionObject("EQUIVALENT-FUNCTION-PROPOSITIONS?", "(DEFUN (EQUIVALENT-FUNCTION-PROPOSITIONS? BOOLEAN) ((SELF PROPOSITION) (OTHER PROPOSITION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&equivalentFunctionPropositionsP)), NULL);
    defineFunctionObject("EQUIVALENT-DESCRIPTIONS?", "(DEFUN (EQUIVALENT-DESCRIPTIONS? BOOLEAN) ((SELF DESCRIPTION) (OTHER DESCRIPTION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&equivalentDescriptionsP)), NULL);
    defineFunctionObject("EQUIVALENT-ENUMERATIONS?", "(DEFUN (EQUIVALENT-ENUMERATIONS? BOOLEAN) ((SELF COLLECTION) (OTHER COLLECTION)))", ((cpp_function_code)(&equivalentEnumerationsP)), NULL);
    defineFunctionObject("EQUIVALENT-FORMULAE?", "(DEFUN (EQUIVALENT-FORMULAE? BOOLEAN) ((SELF OBJECT) (OTHER OBJECT) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&equivalentFormulaeP)), NULL);
    defineFunctionObject("SAME-ARGUMENTS?", "(DEFUN (SAME-ARGUMENTS? BOOLEAN) ((VARIABLES VARIABLES-VECTOR) (ARGUMENTS VECTOR)))", ((cpp_function_code)(&sameArgumentsP)), NULL);
    defineFunctionObject("UNIFY-PROPOSITIONS?", "(DEFUN (UNIFY-PROPOSITIONS? BOOLEAN) ((SELF PROPOSITION) (OTHER PROPOSITION) (MAPPING ENTITY-MAPPING)))", ((cpp_function_code)(&unifyPropositionsP)), NULL);
    defineFunctionObject("NAMED-DESCRIPTION?", "(DEFUN (NAMED-DESCRIPTION? BOOLEAN) ((SELF DESCRIPTION)) :PUBLIC? TRUE)", ((cpp_function_code)(&namedDescriptionP)), NULL);
    defineMethodObject("(DEFMETHOD (FIND-DUPLICATE-NAMED-DESCRIPTION LOGIC-OBJECT) ((SELF DESCRIPTION)))", ((cpp_method_code)(&Description::findDuplicateNamedDescription)), ((cpp_method_code)(NULL)));
    defineFunctionObject("DELETED-LOGIC-OBJECT?", "(DEFUN (DELETED-LOGIC-OBJECT? BOOLEAN) ((SELF LOGIC-OBJECT)))", ((cpp_function_code)(&deletedLogicObjectP)), NULL);
    defineFunctionObject("UNIQUIFY-DESCRIPTION-VARIABLES", "(DEFUN UNIQUIFY-DESCRIPTION-VARIABLES ((SELF DESCRIPTION)))", ((cpp_function_code)(&uniquifyDescriptionVariables)), NULL);
    defineFunctionObject("RESTORE-DESCRIPTION-VARIABLE-NAMES", "(DEFUN RESTORE-DESCRIPTION-VARIABLE-NAMES ((SELF DESCRIPTION)))", ((cpp_function_code)(&restoreDescriptionVariableNames)), NULL);
    defineFunctionObject("CONS-TREE-LESS-THAN?", "(DEFUN (CONS-TREE-LESS-THAN? BOOLEAN) ((TREE1 OBJECT) (TREE2 OBJECT)))", ((cpp_function_code)(&consTreeLessThanP)), NULL);
    defineFunctionObject("SORT-PROPOSITION-CLAUSES", "(DEFUN (SORT-PROPOSITION-CLAUSES CONS) ((CLAUSES CONS)))", ((cpp_function_code)(&sortPropositionClauses)), NULL);
    defineFunctionObject("UNIQUIFY-PROPOSITION-TREE", "(DEFUN (UNIQUIFY-PROPOSITION-TREE OBJECT) ((TREE OBJECT)))", ((cpp_function_code)(&uniquifyPropositionTree)), NULL);
    defineFunctionObject("FIND-EXACT-DUPLICATE-DESCRIPTION", "(DEFUN (FIND-EXACT-DUPLICATE-DESCRIPTION DESCRIPTION) ((SELF DESCRIPTION)))", ((cpp_function_code)(&findExactDuplicateDescription)), NULL);
    defineFunctionObject("HELP-COLLECT-CONSTANT-REFERENCES", "(DEFUN HELP-COLLECT-CONSTANT-REFERENCES ((SELF OBJECT) (COLLECTION (LIST OF LOGIC-OBJECT)) (STOPATONE? BOOLEAN)))", ((cpp_function_code)(&helpCollectConstantReferences)), NULL);
    defineFunctionObject("COLLECT-CONSTANT-DESCRIPTION-REFERENCES", "(DEFUN (COLLECT-CONSTANT-DESCRIPTION-REFERENCES (LIST OF LOGIC-OBJECT)) ((SELF DESCRIPTION) (COLLECTION (LIST OF LOGIC-OBJECT)) (STOPATONE? BOOLEAN)))", ((cpp_function_code)(&collectConstantDescriptionReferences)), NULL);
    defineFunctionObject("FIND-DUPLICATE-DESCRIPTION-WITH-CONSTANT-REFERENCE", "(DEFUN (FIND-DUPLICATE-DESCRIPTION-WITH-CONSTANT-REFERENCE DESCRIPTION) ((SELF DESCRIPTION)))", ((cpp_function_code)(&findDuplicateDescriptionWithConstantReference)), NULL);
    defineFunctionObject("FIND-DUPLICATE-DESCRIPTION", "(DEFUN (FIND-DUPLICATE-DESCRIPTION DESCRIPTION) ((SELF DESCRIPTION)))", ((cpp_function_code)(&findDuplicateDescription)), NULL);
    defineFunctionObject("ADD-DEPENDENT-DESCRIPTION-LINK", "(DEFUN ADD-DEPENDENT-DESCRIPTION-LINK ((SELF OBJECT) (DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&addDependentDescriptionLink)), NULL);
    defineFunctionObject("FASTEN-DOWN-DESCRIPTION", "(DEFUN FASTEN-DOWN-DESCRIPTION ((SELF DESCRIPTION)))", ((cpp_function_code)(&fastenDownDescription)), NULL);
    defineFunctionObject("CONTAINS-NESTED-ARGUMENT?", "(DEFUN (CONTAINS-NESTED-ARGUMENT? BOOLEAN) ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&containsNestedArgumentP)), NULL);
    defineFunctionObject("EXPAND-IF-PROPOSITION", "(DEFUN (EXPAND-IF-PROPOSITION PROPOSITION) ((IFPROPOSITION PROPOSITION)))", ((cpp_function_code)(&expandIfProposition)), NULL);
    defineFunctionObject("HELP-COLLECT-FLATTENED-ARGUMENTS", "(DEFUN HELP-COLLECT-FLATTENED-ARGUMENTS ((SELF PROPOSITION) (FLATTENEDARGUMENTS (LIST OF PROPOSITION)) (EXISTSVARIABLES (LIST OF PATTERN-VARIABLE))))", ((cpp_function_code)(&helpCollectFlattenedArguments)), NULL);
    defineFunctionObject("YIELD-FLATTENED-ARGUMENTS", "(DEFUN (YIELD-FLATTENED-ARGUMENTS (LIST OF PROPOSITION)) ((PROPOSITION PROPOSITION) (EXISTSVARIABLES (LIST OF PATTERN-VARIABLE))))", ((cpp_function_code)(&yieldFlattenedArguments)), NULL);
  }
}

void startupDescriptions() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/LOGIC", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupDescriptions1();
      helpStartupDescriptions2();
      helpStartupDescriptions3();
    }
    if (currentStartupTimePhaseP(4)) {
      FAKE_IO_VARIABLES = newVector(0);
      SYSTEM_DEFINED_ARGUMENT_NAMES = listO(101, SYM_DESCRIPTIONS_LOGIC_pX1, SYM_DESCRIPTIONS_LOGIC_pX2, SYM_DESCRIPTIONS_LOGIC_pX3, SYM_DESCRIPTIONS_LOGIC_pX4, SYM_DESCRIPTIONS_LOGIC_pX5, SYM_DESCRIPTIONS_LOGIC_pX6, SYM_DESCRIPTIONS_LOGIC_pX7, SYM_DESCRIPTIONS_LOGIC_pX8, SYM_DESCRIPTIONS_LOGIC_pX9, SYM_DESCRIPTIONS_LOGIC_pX10, SYM_DESCRIPTIONS_LOGIC_pX11, SYM_DESCRIPTIONS_LOGIC_pX12, SYM_DESCRIPTIONS_LOGIC_pX13, SYM_DESCRIPTIONS_LOGIC_pX14, SYM_DESCRIPTIONS_LOGIC_pX15, SYM_DESCRIPTIONS_LOGIC_pX16, SYM_DESCRIPTIONS_LOGIC_pX17, SYM_DESCRIPTIONS_LOGIC_pX18, SYM_DESCRIPTIONS_LOGIC_pX19, SYM_DESCRIPTIONS_LOGIC_pX20, SYM_DESCRIPTIONS_LOGIC_pX21, SYM_DESCRIPTIONS_LOGIC_pX22, SYM_DESCRIPTIONS_LOGIC_pX23, SYM_DESCRIPTIONS_LOGIC_pX24, SYM_DESCRIPTIONS_LOGIC_pX25, SYM_DESCRIPTIONS_LOGIC_pX26, SYM_DESCRIPTIONS_LOGIC_pX27, SYM_DESCRIPTIONS_LOGIC_pX28, SYM_DESCRIPTIONS_LOGIC_pX29, SYM_DESCRIPTIONS_LOGIC_pX30, SYM_DESCRIPTIONS_LOGIC_pX31, SYM_DESCRIPTIONS_LOGIC_pX32, SYM_DESCRIPTIONS_LOGIC_pX33, SYM_DESCRIPTIONS_LOGIC_pX34, SYM_DESCRIPTIONS_LOGIC_pX35, SYM_DESCRIPTIONS_LOGIC_pX36, SYM_DESCRIPTIONS_LOGIC_pX37, SYM_DESCRIPTIONS_LOGIC_pX38, SYM_DESCRIPTIONS_LOGIC_pX39, SYM_DESCRIPTIONS_LOGIC_pX40, SYM_DESCRIPTIONS_LOGIC_pX41, SYM_DESCRIPTIONS_LOGIC_pX42, SYM_DESCRIPTIONS_LOGIC_pX43, SYM_DESCRIPTIONS_LOGIC_pX44, SYM_DESCRIPTIONS_LOGIC_pX45, SYM_DESCRIPTIONS_LOGIC_pX46, SYM_DESCRIPTIONS_LOGIC_pX47, SYM_DESCRIPTIONS_LOGIC_pX48, SYM_DESCRIPTIONS_LOGIC_pX49, SYM_DESCRIPTIONS_LOGIC_pX50, SYM_DESCRIPTIONS_LOGIC_pX51, SYM_DESCRIPTIONS_LOGIC_pX52, SYM_DESCRIPTIONS_LOGIC_pX53, SYM_DESCRIPTIONS_LOGIC_pX54, SYM_DESCRIPTIONS_LOGIC_pX55, SYM_DESCRIPTIONS_LOGIC_pX56, SYM_DESCRIPTIONS_LOGIC_pX57, SYM_DESCRIPTIONS_LOGIC_pX58, SYM_DESCRIPTIONS_LOGIC_pX59, SYM_DESCRIPTIONS_LOGIC_pX60, SYM_DESCRIPTIONS_LOGIC_pX61, SYM_DESCRIPTIONS_LOGIC_pX62, SYM_DESCRIPTIONS_LOGIC_pX63, SYM_DESCRIPTIONS_LOGIC_pX64, SYM_DESCRIPTIONS_LOGIC_pX65, SYM_DESCRIPTIONS_LOGIC_pX66, SYM_DESCRIPTIONS_LOGIC_pX67, SYM_DESCRIPTIONS_LOGIC_pX68, SYM_DESCRIPTIONS_LOGIC_pX69, SYM_DESCRIPTIONS_LOGIC_pX70, SYM_DESCRIPTIONS_LOGIC_pX71, SYM_DESCRIPTIONS_LOGIC_pX72, SYM_DESCRIPTIONS_LOGIC_pX73, SYM_DESCRIPTIONS_LOGIC_pX74, SYM_DESCRIPTIONS_LOGIC_pX75, SYM_DESCRIPTIONS_LOGIC_pX76, SYM_DESCRIPTIONS_LOGIC_pX77, SYM_DESCRIPTIONS_LOGIC_pX78, SYM_DESCRIPTIONS_LOGIC_pX79, SYM_DESCRIPTIONS_LOGIC_pX80, SYM_DESCRIPTIONS_LOGIC_pX81, SYM_DESCRIPTIONS_LOGIC_pX82, SYM_DESCRIPTIONS_LOGIC_pX83, SYM_DESCRIPTIONS_LOGIC_pX84, SYM_DESCRIPTIONS_LOGIC_pX85, SYM_DESCRIPTIONS_LOGIC_pX86, SYM_DESCRIPTIONS_LOGIC_pX87, SYM_DESCRIPTIONS_LOGIC_pX88, SYM_DESCRIPTIONS_LOGIC_pX89, SYM_DESCRIPTIONS_LOGIC_pX90, SYM_DESCRIPTIONS_LOGIC_pX91, SYM_DESCRIPTIONS_LOGIC_pX92, SYM_DESCRIPTIONS_LOGIC_pX93, SYM_DESCRIPTIONS_LOGIC_pX94, SYM_DESCRIPTIONS_LOGIC_pX95, SYM_DESCRIPTIONS_LOGIC_pX96, SYM_DESCRIPTIONS_LOGIC_pX97, SYM_DESCRIPTIONS_LOGIC_pX98, SYM_DESCRIPTIONS_LOGIC_pX99, SYM_DESCRIPTIONS_LOGIC_pX100, NIL);
      oUNIFY_PROPOSITIONSpo.set(FALSE);
      oSTRINGIFIED_DESCRIPTION_INDEXo = newStringHashTable();
      oADDEDNEWTYPEpo.set(FALSE);
    }
    if (currentStartupTimePhaseP(5)) {
      defineStellaTypeFromStringifiedSource("(DEFTYPE ENTITY-MAPPING (KEY-VALUE-LIST OF OBJECT OBJECT) :DOCUMENTATION \"Used to keep track of already copied variables\nand propositions within a 'copy-description' procedure.\")");
      defineStellaTypeFromStringifiedSource("(DEFTYPE VARIABLE-TYPE-TABLE (KEY-VALUE-LIST OF PATTERN-VARIABLE (LIST OF TYPE)))");
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupDescriptions4();
      defineFunctionObject("FLATTEN-NESTED-FUNCTION-ARGUMENTS", "(DEFUN (FLATTEN-NESTED-FUNCTION-ARGUMENTS PROPOSITION) ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&flattenNestedFunctionArguments)), NULL);
      defineFunctionObject("COLLAPSE-VALUE-OF-CHAINS-FOR-IO-VARIABLES", "(DEFUN COLLAPSE-VALUE-OF-CHAINS-FOR-IO-VARIABLES ((IOVARIABLES VARIABLES-VECTOR)))", ((cpp_function_code)(&collapseValueOfChainsForIoVariables)), NULL);
      defineFunctionObject("REMOVE-NULLS-IN-VARIABLES-VECTOR", "(DEFUN (REMOVE-NULLS-IN-VARIABLES-VECTOR VARIABLES-VECTOR) ((IOVARIABLES VARIABLES-VECTOR)))", ((cpp_function_code)(&removeNullsInVariablesVector)), NULL);
      defineFunctionObject("COLLAPSE-VALUE-OF-CHAINS", "(DEFUN COLLAPSE-VALUE-OF-CHAINS ((DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&collapseValueOfChains)), NULL);
      defineFunctionObject("TIGHTEN-ARGUMENT-BINDINGS", "(DEFUN TIGHTEN-ARGUMENT-BINDINGS ((PROPOSITION PROPOSITION) (IOVARIABLES VARIABLES-VECTOR)))", ((cpp_function_code)(&tightenArgumentBindings)), NULL);
      defineFunctionObject("COLLECT-ALL-VARIABLES", "(DEFUN COLLECT-ALL-VARIABLES ((SELF PROPOSITION) (COLLECTION (LIST OF PATTERN-VARIABLE)) (BEENTHERE LIST)))", ((cpp_function_code)(&collectAllVariables)), NULL);
      defineFunctionObject("COMPUTE-INTERNAL-VARIABLES", "(DEFUN COMPUTE-INTERNAL-VARIABLES ((SELF DESCRIPTION)))", ((cpp_function_code)(&computeInternalVariables)), NULL);
      defineFunctionObject("EQUATE-TOP-LEVEL-EQUIVALENCES", "(DEFUN EQUATE-TOP-LEVEL-EQUIVALENCES ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&equateTopLevelEquivalences)), NULL);
      defineFunctionObject("COLLECT-EXTERNAL-VARIABLES", "(DEFUN COLLECT-EXTERNAL-VARIABLES ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&collectExternalVariables)), NULL);
      defineFunctionObject("FINISH-BUILDING-DESCRIPTION", "(DEFUN (FINISH-BUILDING-DESCRIPTION DESCRIPTION) ((DESCRIPTION DESCRIPTION) (CHECKFORDUPLICATE? BOOLEAN)))", ((cpp_function_code)(&finishBuildingDescription)), NULL);
      defineFunctionObject("EVALUATE-DESCRIPTION-TERM", "(DEFUN (EVALUATE-DESCRIPTION-TERM DESCRIPTION) ((TERM CONS) (CHECKFORDUPLICATE? BOOLEAN)))", ((cpp_function_code)(&evaluateDescriptionTerm)), NULL);
      defineFunctionObject("REMOVE-VARIABLE-TYPE-PROPOSITIONS", "(DEFUN (REMOVE-VARIABLE-TYPE-PROPOSITIONS (CONS OF PROPOSITION)) ((PROPOSITION PROPOSITION)))", ((cpp_function_code)(&removeVariableTypePropositions)), NULL);
      defineFunctionObject("GET-COMPLEMENT-OF-GOAL-DESCRIPTION", "(DEFUN (GET-COMPLEMENT-OF-GOAL-DESCRIPTION DESCRIPTION) ((SELF NAMED-DESCRIPTION)))", ((cpp_function_code)(&getComplementOfGoalDescription)), NULL);
      defineFunctionObject("COLLECT-FREE-VARIABLES", "(DEFUN COLLECT-FREE-VARIABLES ((SELF OBJECT) (COLLECTION (LIST OF PATTERN-VARIABLE)) (QUANTIFIEDVARS LIST) (BEENTHERE LIST)))", ((cpp_function_code)(&collectFreeVariables)), NULL);
      defineFunctionObject("TOP-LEVEL-EXISTENTIAL-VARIABLES", "(DEFUN (TOP-LEVEL-EXISTENTIAL-VARIABLES (CONS OF PATTERN-VARIABLE)) ((SELF DESCRIPTION)))", ((cpp_function_code)(&topLevelExistentialVariables)), NULL);
      defineFunctionObject("TOP-LEVEL-EXISTENTIAL-VARIABLE?", "(DEFUN (TOP-LEVEL-EXISTENTIAL-VARIABLE? BOOLEAN) ((VARIABLE PATTERN-VARIABLE) (DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&topLevelExistentialVariableP)), NULL);
      defineFunctionObject("FREE-VARIABLE?", "(DEFUN (FREE-VARIABLE? BOOLEAN) ((VARIABLE PATTERN-VARIABLE) (PROPOSITION PROPOSITION)))", ((cpp_function_code)(&freeVariableP)), NULL);
      defineFunctionObject("MOST-SPECIFIC-TYPES", "(DEFUN (MOST-SPECIFIC-TYPES (LIST OF TYPE)) ((TYPES (LIST OF TYPE))))", ((cpp_function_code)(&mostSpecificTypes)), NULL);
      defineFunctionObject("ADD-VARIABLE-TYPE", "(DEFUN ADD-VARIABLE-TYPE ((VARIABLE PATTERN-VARIABLE) (NEWTYPE TYPE) (TABLE VARIABLE-TYPE-TABLE) (VISIBLEVARIABLES (CONS OF PATTERN-VARIABLE))))", ((cpp_function_code)(&addVariableType)), NULL);
      defineFunctionObject("INFER-PREDICATE-FROM-OPERATOR-AND-TYPES", "(DEFUN (INFER-PREDICATE-FROM-OPERATOR-AND-TYPES OBJECT) ((OPERATOR OBJECT) (TYPES (LIST OF TYPE))))", ((cpp_function_code)(&inferPredicateFromOperatorAndTypes)), NULL);
      defineFunctionObject("INFER-TYPES-FROM-ONE-PROPOSITION", "(DEFUN INFER-TYPES-FROM-ONE-PROPOSITION ((PROPOSITION PROPOSITION) (TABLE VARIABLE-TYPE-TABLE) (VISIBLEVARS (CONS OF PATTERN-VARIABLE))))", ((cpp_function_code)(&inferTypesFromOneProposition)), NULL);
      defineFunctionObject("INFER-TYPES-FROM-PROPOSITIONS", "(DEFUN INFER-TYPES-FROM-PROPOSITIONS ((PROPOSITION PROPOSITION) (TABLE VARIABLE-TYPE-TABLE) (VISIBLEVARS (CONS OF PATTERN-VARIABLE))))", ((cpp_function_code)(&inferTypesFromPropositions)), NULL);
      defineFunctionObject("INFER-VARIABLE-TYPES-IN-PROPOSITION", "(DEFUN (INFER-VARIABLE-TYPES-IN-PROPOSITION VARIABLE-TYPE-TABLE) ((PROPOSITION PROPOSITION) (VISIBLEVARIABLES (CONS OF PATTERN-VARIABLE))))", ((cpp_function_code)(&inferVariableTypesInProposition)), NULL);
      defineFunctionObject("INFER-VARIABLE-TYPES-IN-DESCRIPTION", "(DEFUN (INFER-VARIABLE-TYPES-IN-DESCRIPTION VARIABLE-TYPE-TABLE) ((DESCRIPTION DESCRIPTION)))", ((cpp_function_code)(&inferVariableTypesInDescription)), NULL);
      defineFunctionObject("COLLECT-UNRESOLVED-SLOT-REFERENCES", "(DEFUN (COLLECT-UNRESOLVED-SLOT-REFERENCES (CONS OF PROPOSITION)) ((SELF PROPOSITION)))", ((cpp_function_code)(&collectUnresolvedSlotReferences)), NULL);
      defineFunctionObject("RESOLVE-ONE-SLOT-REFERENCE?", "(DEFUN (RESOLVE-ONE-SLOT-REFERENCE? BOOLEAN) ((PROPOSITION PROPOSITION) (VARIABLETYPESTABLE VARIABLE-TYPE-TABLE)))", ((cpp_function_code)(&resolveOneSlotReferenceP)), NULL);
      defineFunctionObject("RESOLVE-UNRESOLVED-SLOT-REFERENCES", "(DEFUN RESOLVE-UNRESOLVED-SLOT-REFERENCES ((FORMULA OBJECT)))", ((cpp_function_code)(&resolveUnresolvedSlotReferences)), NULL);
      defineFunctionObject("CREATE-DUMMY-RELATION", "(DEFUN CREATE-DUMMY-RELATION ((WAYWARDPROPOSITION PROPOSITION)))", ((cpp_function_code)(&createDummyRelation)), NULL);
      defineFunctionObject("DEFINED-RELATION?", "(DEFUN (DEFINED-RELATION? BOOLEAN) ((SELF NAMED-DESCRIPTION)))", ((cpp_function_code)(&definedRelationP)), NULL);
      defineFunctionObject("LIST-UNDEFINED-RELATIONS", "(DEFUN (LIST-UNDEFINED-RELATIONS (CONS OF NAMED-DESCRIPTION)) ((MODULE NAME) (LOCAL? BOOLEAN)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Return a list of as yet undefined concepts and relations in `module'.\nThese relations were defined by the system, since they were referenced\nbut have not yet been defined by the user.  If `module' is NULL look in\nthe current module.  If `local?' only look in `module' but not in any\nmodules it inherits.\")", ((cpp_function_code)(&listUndefinedRelations)), ((cpp_function_code)(&listUndefinedRelationsEvaluatorWrapper)));
      defineFunctionObject("CALL-LIST-UNDEFINED-RELATIONS", "(DEFUN (CALL-LIST-UNDEFINED-RELATIONS CONS) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Callable version of `list-undefined-relations' (which see).\" :PUBLIC? TRUE)", ((cpp_function_code)(&callListUndefinedRelations)), NULL);
      defineFunctionObject("COMPLAIN-ABOUT-UNDECLARED-REFERENCE", "(DEFUN COMPLAIN-ABOUT-UNDECLARED-REFERENCE ((WAYWARDPROPOSITION PROPOSITION)))", ((cpp_function_code)(&complainAboutUndeclaredReference)), NULL);
      defineFunctionObject("ALL-NAMED-DESCRIPTIONS-NEXT?", "(DEFUN (ALL-NAMED-DESCRIPTIONS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))", ((cpp_function_code)(&allNamedDescriptionsNextP)), NULL);
      defineFunctionObject("ALL-NAMED-DESCRIPTIONS", "(DEFUN (ALL-NAMED-DESCRIPTIONS (ITERATOR OF NAMED-DESCRIPTION)) ((MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Iterate over all named descriptions visible from 'module'.\nIf 'local?', return only named descriptions interned in 'module'.\nIf 'module' is null, return all named descriptions interned everywhere.\" :PUBLIC? TRUE)", ((cpp_function_code)(&allNamedDescriptions)), NULL);
      defineFunctionObject("STARTUP-DESCRIPTIONS", "(DEFUN STARTUP-DESCRIPTIONS () :PUBLIC? TRUE)", ((cpp_function_code)(&startupDescriptions)), NULL);
      { MethodSlot* function = lookupFunction(SYM_DESCRIPTIONS_LOGIC_STARTUP_DESCRIPTIONS);

        setDynamicSlotValue(function->dynamicSlots, SYM_DESCRIPTIONS_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Descriptions"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT FAKE-IO-VARIABLES VARIABLES-VECTOR (NEW VARIABLES-VECTOR :ARRAY-SIZE 0) :DOCUMENTATION \"Installed in a description with undetermined arity.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT SYSTEM-DEFINED-ARGUMENT-NAMES (CONS OF SYMBOL) (BQUOTE (?X1 ?X2 ?X3 ?X4 ?X5 ?X6 ?X7 ?X8 ?X9 ?X10 ?X11 ?X12 ?X13 ?X14 ?X15 ?X16 ?X17 ?X18 ?X19 ?X20 ?X21 ?X22 ?X23 ?X24 ?X25 ?X26 ?X27 ?X28 ?X29 ?X30 ?X31 ?X32 ?X33 ?X34 ?X35 ?X36 ?X37 ?X38 ?X39 ?X40 ?X41 ?X42 ?X43 ?X44 ?X45 ?X46 ?X47 ?X48 ?X49 ?X50 ?X51 ?X52 ?X53 ?X54 ?X55 ?X56 ?X57 ?X58 ?X59 ?X60 ?X61 ?X62 ?X63 ?X64 ?X65 ?X66 ?X67 ?X68 ?X69 ?X70 ?X71 ?X72 ?X73 ?X74 ?X75 ?X76 ?X77 ?X78 ?X79 ?X80 ?X81 ?X82 ?X83 ?X84 ?X85 ?X86 ?X87 ?X88 ?X89 ?X90 ?X91 ?X92 ?X93 ?X94 ?X95 ?X96 ?X97 ?X98 ?X99 ?X100)) :PUBLIC? TRUE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *LOGICVARIABLETABLE* (CONS OF SKOLEM) NULL :DOCUMENTATION \"Table mapping logic variable names to variables or skolems.\nUsed during construction of a proposition or description.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *VARIABLETYPEPROPOSITIONS* (CONS OF PROPOSITION) :DOCUMENTATION \"List of propositions extracted from parsing\na list of quantified, typed variables.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *UNIFY-PROPOSITIONS?* BOOLEAN FALSE)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STRINGIFIED-DESCRIPTION-INDEX* (STRING-HASH-TABLE OF STRING LIST) (NEW STRING-HASH-TABLE) :DOCUMENTATION \"Contains a table of unnamed descriptions, indexed by the\nstringification of their propositions.  Tricky: Descriptions in two\ndifferent modules could have the same stringification but be different.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *EXTERNALVARIABLES* CONS :DOCUMENTATION \"Used by 'evaluate-DESCRIPTION-term' for collecting\na list of variables declared external to the description in which they\nare referenced.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *RECURSIVEGETCOMPLEMENTARGUMENT* NAMED-DESCRIPTION NULL :DOCUMENTATION \"Used to prevent infinite looping.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *ADDEDNEWTYPE?* BOOLEAN FALSE :DOCUMENTATION \"Used by 'infer-variable-types'.\")");
    }
  }
}

Surrogate* SGT_DESCRIPTIONS_STELLA_SLOT = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_METHOD_SLOT = NULL;

Symbol* SYM_DESCRIPTIONS_STELLA_ANY_VALUE = NULL;

Keyword* KWD_DESCRIPTIONS_EXTENSIONAL_ASSERTION = NULL;

Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_RELATION = NULL;

Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_POLYMORPHIC = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX1 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX2 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX3 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX4 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX5 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX6 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX7 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX8 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX9 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX10 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX11 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX12 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX13 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX14 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX15 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX16 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX17 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX18 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX19 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX20 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX21 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX22 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX23 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX24 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX25 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX26 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX27 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX28 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX29 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX30 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX31 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX32 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX33 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX34 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX35 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX36 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX37 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX38 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX39 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX40 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX41 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX42 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX43 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX44 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX45 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX46 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX47 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX48 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX49 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX50 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX51 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX52 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX53 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX54 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX55 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX56 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX57 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX58 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX59 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX60 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX61 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX62 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX63 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX64 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX65 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX66 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX67 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX68 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX69 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX70 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX71 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX72 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX73 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX74 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX75 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX76 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX77 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX78 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX79 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX80 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX81 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX82 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX83 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX84 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX85 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX86 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX87 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX88 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX89 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX90 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX91 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX92 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX93 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX94 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX95 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX96 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX97 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX98 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX99 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX100 = NULL;

Surrogate* SGT_DESCRIPTIONS_LOGIC_NAMED_DESCRIPTION = NULL;

Symbol* SYM_DESCRIPTIONS_STELLA_ISA = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_KAPPA = NULL;

Keyword* KWD_DESCRIPTIONS_KIF = NULL;

Keyword* KWD_DESCRIPTIONS_DESCRIPTION = NULL;

Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_CONCEPT = NULL;

Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_FUNCTION = NULL;

Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_VARIABLE_ARITY = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_DESCRIPTION = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_CLASS = NULL;

Keyword* KWD_DESCRIPTIONS_ERROR = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_RELATION = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_OBJECT_STORE = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_THING = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_LITERAL = NULL;

Surrogate* SGT_DESCRIPTIONS_LOGIC_PROPOSITION = NULL;

Keyword* KWD_DESCRIPTIONS_WARNING = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_CONS = NULL;

Keyword* KWD_DESCRIPTIONS_ISA = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_VARIABLE_TYPEp = NULL;

Symbol* SYM_DESCRIPTIONS_STELLA_EXISTS = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_ENTITY_MAPPING = NULL;

Keyword* KWD_DESCRIPTIONS_AND = NULL;

Keyword* KWD_DESCRIPTIONS_OR = NULL;

Keyword* KWD_DESCRIPTIONS_EQUIVALENT = NULL;

Keyword* KWD_DESCRIPTIONS_FORALL = NULL;

Keyword* KWD_DESCRIPTIONS_EXISTS = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES = NULL;

Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_HOLDS = NULL;

Keyword* KWD_DESCRIPTIONS_FUNCTION = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_SET = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_LIST = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_SURROGATE = NULL;

Surrogate* SGT_DESCRIPTIONS_LOGIC_DESCRIPTION = NULL;

Keyword* KWD_DESCRIPTIONS_NOT = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_GENERALIZED_SYMBOL = NULL;

Symbol* SYM_DESCRIPTIONS_STELLA_AND = NULL;

Symbol* SYM_DESCRIPTIONS_STELLA_OR = NULL;

Symbol* SYM_DESCRIPTIONS_STELLA_NOT = NULL;

Symbol* SYM_DESCRIPTIONS_STELLA_FORALL = NULL;

Surrogate* SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE = NULL;

Surrogate* SGT_DESCRIPTIONS_LOGIC_LOGIC_OBJECT = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_EXTERNAL_VARIABLES = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_DEPENDENT_DESCRIPTIONS = NULL;

Keyword* KWD_DESCRIPTIONS_PREDICATE = NULL;

Keyword* KWD_DESCRIPTIONS_IMPLIES = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_PROPOSITIONdIF = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_CS_VALUE = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_THE_ONLY = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_IOTAp = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_COMPLEMENT_DESCRIPTION = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_VARIABLE_TYPE_TABLE = NULL;

Surrogate* SGT_DESCRIPTIONS_STELLA_SYMBOL = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_UNDECLAREDp = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_pX = NULL;

Symbol* SYM_DESCRIPTIONS_PL_KERNEL_KB_RELATION = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_QUERY_038 = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_DESCRIPTIVEp = NULL;

Symbol* SYM_DESCRIPTIONS_LOGIC_STARTUP_DESCRIPTIONS = NULL;

Symbol* SYM_DESCRIPTIONS_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace logic
