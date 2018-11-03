//  -*- Mode: C++ -*-

// pli.hh

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


namespace pli {
  using namespace stella;
  using namespace logic;

// Class definitions:
class Environment : public StandardObject {
public:
  char* level;
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
};

class PlIterator : public Iterator {
public:
  Cons* cursor;
public:
  virtual Surrogate* primaryType();
  virtual Cons* consify();
  virtual List* listify();
  virtual int length();
  virtual boolean emptyP();
  virtual boolean nextP();
};


// Global declarations:
extern boolean oPOWERLOOM_INITIALIZEDpo;
extern Environment* ASSERTION_ENV;
extern Environment* TAXONOMIC_ENV;
extern Environment* INFERENCE_ENV;
extern PlIterator* EMPTY_PL_ITERATOR;
extern NamedDescription* oLITERAL_CONCEPTo;
extern NamedDescription* oSTRING_CONCEPTo;
extern NamedDescription* oINTEGER_CONCEPTo;
extern NamedDescription* oFLOAT_CONCEPTo;

// Function signatures:
void initialize();
Environment* newEnvironment();
Object* accessEnvironmentSlotValue(Environment* self, Symbol* slotname, Object* value, boolean setvalueP);
PlIterator* newPlIterator();
Object* accessPlIteratorSlotValue(PlIterator* self, Symbol* slotname, Object* value, boolean setvalueP);
PlIterator* consToPlIterator(Cons* self);
PlIterator* listToPlIterator(List* self);
PlIterator* iteratorToPlIterator(Iterator* self);
Object* safelyGetObject(char* name, Module* module, Environment* environment);
Object* safelyGetConcept(char* name, Module* module, Environment* environment);
Object* safelyGetRelation(char* name, Module* module, Environment* environment);
Context* safelyGetModule(char* name, Environment* environment);
Object* safelyGetObjectOrNull(char* name, Module* module, Environment* environment);
Cons* sequenceToConsList(Object* sequence);
Cons* explodeStringList(char* stringlist, Module* module);
Object* getObject(char* name, Module* module, Environment* environment);
Object* sGetObject(char* name, char* moduleName, Environment* environment);
LogicObject* getConcept(char* name, Module* module, Environment* environment);
LogicObject* sGetConcept(char* name, char* moduleName, Environment* environment);
LogicObject* getRelation(char* name, Module* module, Environment* environment);
LogicObject* sGetRelation(char* name, char* moduleName, Environment* environment);
char* getName(Object* obj);
char* objectToString(Object* self);
int objectToInteger(Object* self);
double objectToFloat(Object* self);
char* objectToParsableString(Object* self);
Object* stringToObject(char* string, LogicObject* type, Module* module, Environment* environment);
Cons* helpGetTrueExtensionMembers(NamedDescription* relation, boolean specializeP);
Cons* helpGetPropositions(LogicObject* relation, Cons* arguments, int limit, Module* module, Environment* environment);
Proposition* getProposition(Object* relationAndArguments, Module* module, Environment* environment);
Proposition* sGetProposition(char* relationAndArguments, char* moduleName, Environment* environment);
PlIterator* getPropositions(Object* relationAndArguments, Module* module, Environment* environment);
PlIterator* sGetPropositions(char* relationAndArguments, char* moduleName, Environment* environment);
Proposition* getBinaryProposition(LogicObject* relation, Object* arg1, Object* arg2, Module* module, Environment* environment);
PlIterator* getBinaryPropositions(LogicObject* relation, Object* arg1, Object* arg2, Module* module, Environment* environment);
PlIterator* getInferredBinaryPropositionValues(LogicObject* relation, Object* arg, Module* module, Environment* environment);
PlIterator* sGetInferredBinaryPropositionValues(char* relationName, char* argName, char* moduleName, Environment* environment);
PlIterator* getPropositionsOf(LogicObject* object, Module* module, Environment* environment);
PlIterator* sGetPropositionsOf(char* objectName, char* moduleName, Environment* environment);
PlIterator* getPropositionsInModule(Module* module, Environment* environment);
boolean isTrueUnaryProposition(LogicObject* relation, Object* arg, Module* module, Environment* environment);
boolean isTrueBinaryProposition(LogicObject* relation, Object* arg, Object* value, Module* module, Environment* environment);
boolean isTrueProposition1(Object* relationAndArguments, Module* module, Environment* environment);
boolean isTrueProposition(Proposition* proposition, Module* module, Environment* environment);
boolean sIsTrueProposition(char* relationAndArguments, char* moduleName, Environment* environment);
boolean isSubrelation(LogicObject* sub, LogicObject* super, Module* module, Environment* environment);
PlIterator* getProperSubrelations(LogicObject* relation, Module* module, Environment* environment);
PlIterator* getDirectSubrelations(LogicObject* relation, Module* module, Environment* environment);
PlIterator* getProperSuperrelations(LogicObject* relation, Module* module, Environment* environment);
PlIterator* getDirectSuperrelations(LogicObject* relation, Module* module, Environment* environment);
boolean isA(Object* object, LogicObject* concept, Module* module, Environment* environment);
PlIterator* getConceptInstances(LogicObject* concept, Module* module, Environment* environment);
PlIterator* sGetConceptInstances(char* conceptName, char* moduleName, Environment* environment);
PlIterator* getDirectConceptInstances(LogicObject* concept, Module* module, Environment* environment);
PlIterator* sGetDirectConceptInstances(char* conceptName, char* moduleName, Environment* environment);
PlIterator* getConceptInstancesMatchingValue(LogicObject* concept, LogicObject* relation, Object* value, Module* module, Environment* environment);
Object* getConceptInstanceMatchingValue(LogicObject* concept, LogicObject* relation, Object* value, Module* module, Environment* environment);
PlIterator* getTypes(LogicObject* object, Module* module, Environment* environment);
PlIterator* getDirectTypes(LogicObject* object, Module* module, Environment* environment);
PlIterator* getRelationExtension(LogicObject* relation, Module* module, Environment* environment);
PlIterator* sGetRelationExtension(char* relationName, Module* module, Environment* environment);
Module* getModule(char* name, Environment* environment);
Module* getCurrentModule(Environment* environment);
Module* getHomeModule(LogicObject* object);
PlIterator* getModules();
Module* createModule(char* name, Module* parent, boolean caseSensitiveP);
Module* sCreateModule(char* name, char* parentName, boolean caseSensitiveP, Environment* environment);
Module* changeModule(Module* module);
Module* sChangeModule(char* name, Environment* environment);
Module* clearModule(Module* module);
Module* sClearModule(char* name, Environment* environment);
PlIterator* getChildModules(Module* module);
PlIterator* sGetChildModules(char* name, Environment* environment);
PlIterator* getParentModules(Module* module);
PlIterator* sGetParentModules(char* name, Environment* environment);
char* generateUniqueName(char* prefix, Module* module, Environment* environment);
LogicObject* createObject(char* name, LogicObject* concept, Module* module, Environment* environment);
LogicObject* sCreateObject(char* name, char* conceptName, char* moduleName, Environment* environment);
LogicObject* createConcept(char* name, LogicObject* parent, Module* module, Environment* environment);
LogicObject* sCreateConcept(char* name, char* parentName, char* moduleName, Environment* environment);
LogicObject* createRelation(char* name, int arity, Module* module, Environment* environment);
LogicObject* sCreateRelation(char* name, int arity, char* moduleName, Environment* environment);
LogicObject* createFunction(char* name, int arity, Module* module, Environment* environment);
LogicObject* sCreateFunction(char* name, int arity, char* moduleName, Environment* environment);
LogicObject* createEnumeratedList(Cons* members);
LogicObject* createEnumeratedSet(Cons* members);
void destroyObject(LogicObject* object);
void sDestroyObject(char* objectName, char* moduleName, Environment* environment);
Proposition* assertUnaryProposition(LogicObject* relation, Object* arg, Module* module, Environment* environment);
Proposition* assertBinaryProposition(LogicObject* relation, Object* arg, Object* value, Module* module, Environment* environment);
Proposition* assertNaryProposition(Object* relationAndArguments, Module* module, Environment* environment);
Proposition* retractUnaryProposition(LogicObject* relation, Object* arg, Module* module, Environment* environment);
Proposition* retractBinaryProposition(LogicObject* relation, Object* arg, Object* value, Module* module, Environment* environment);
Proposition* retractNaryProposition(Object* relationAndArguments, Module* module, Environment* environment);
Proposition* assertProposition(Proposition* proposition, Module* module, Environment* environment);
PlIterator* sAssertProposition(char* sentence, char* moduleName, Environment* environment);
Proposition* retractProposition(Proposition* proposition, Module* module, Environment* environment);
PlIterator* sRetractProposition(char* sentence, char* moduleName, Environment* environment);
PlIterator* conceive(Object* sentence, Module* module, Environment* environment);
PlIterator* sConceive(char* sentence, char* moduleName, Environment* environment);
PlIterator* getRules(LogicObject* relation, Module* module, Environment* environment);
PlIterator* sGetRules(char* relationName, char* moduleName, Environment* environment);
void sPrintRules(char* name, OutputStream* stream, char* moduleName, Environment* environment);
void runForwardRules(Object* module, boolean forceP);
int getArity(LogicObject* relation);
int sGetArity(char* relationName, char* moduleName, Environment* environment);
LogicObject* getDomain(LogicObject* relation);
LogicObject* sGetDomain(char* relationName, char* moduleName, Environment* environment);
LogicObject* getRange(LogicObject* relation);
LogicObject* sGetRange(char* relationName, char* moduleName, Environment* environment);
LogicObject* getNthDomain(LogicObject* relation, int n);
LogicObject* sGetNthDomain(char* relationName, int n, char* moduleName, Environment* environment);
void load(char* filename, Environment* environment);
void loadStream(InputStream* stream, Environment* environment);
void loadNativeStream(std::istream* stream, Environment* environment);
void saveModule(Module* module, char* filename, char* ifexists, Environment* environment);
void sSaveModule(char* moduleName, char* filename, char* ifexists, Environment* environment);
LogicObject* getPredicate(Proposition* prop);
int getColumnCount(Object* obj);
Object* getNthValue(Object* sequence, int n);
char* getNthString(Object* sequence, int n);
int getNthInteger(Object* sequence, int n);
double getNthFloat(Object* sequence, int n);
LogicObject* getNthLogicObject(Object* sequence, int n);
Cons* getEnumeratedCollectionMembers(Object* collection);
Object* evaluate(Object* command, Module* module, Environment* environment);
Object* sEvaluate(char* command, char* moduleName, Environment* environment);
boolean isLogicObject(Object* obj);
boolean isInteger(Object* obj);
boolean isFloat(Object* obj);
boolean isNumber(Object* obj);
boolean isString(Object* obj);
boolean isEnumeratedCollection(Object* obj);
boolean isEnumeratedSet(Object* obj);
boolean isEnumeratedList(Object* obj);
boolean isTrue(TruthValue* tv);
boolean isFalse(TruthValue* tv);
boolean isUnknown(TruthValue* tv);
boolean isStrict(TruthValue* tv);
boolean isDefault(TruthValue* tv);
TruthValue* ask(Cons* query, Module* module, Environment* environment);
TruthValue* sAsk(char* query, char* moduleName, Environment* environment);
PlIterator* retrieve(Cons* query, Module* module, Environment* environment);
PlIterator* sRetrieve(char* query, char* moduleName, Environment* environment);
void helpStartupPli1();
void helpStartupPli2();
void helpStartupPli3();
void startupPli();

// Auxiliary global declarations:
extern Surrogate* SGT_PLI_PLI_ENVIRONMENT;
extern Symbol* SYM_PLI_LOGIC_LEVEL;
extern Surrogate* SGT_PLI_PLI_PL_ITERATOR;
extern Symbol* SYM_PLI_STELLA_CURSOR;
extern Surrogate* SGT_PLI_STELLA_CONS;
extern Surrogate* SGT_PLI_STELLA_LIST;
extern Surrogate* SGT_PLI_STELLA_VECTOR;
extern Symbol* SYM_PLI_STELLA_NULL;
extern Surrogate* SGT_PLI_LOGIC_SKOLEM;
extern Surrogate* SGT_PLI_LOGIC_LOGIC_OBJECT;
extern Surrogate* SGT_PLI_STELLA_GENERALIZED_SYMBOL;
extern Surrogate* SGT_PLI_STELLA_CONTEXT;
extern Surrogate* SGT_PLI_LOGIC_COMPUTED_PROCEDURE;
extern Surrogate* SGT_PLI_STELLA_LITERAL_WRAPPER;
extern Surrogate* SGT_PLI_LOGIC_NAMED_DESCRIPTION;
extern Symbol* SYM_PLI_PLI_pR;
extern Symbol* SYM_PLI_PLI_pI;
extern Symbol* SYM_PLI_PLI_pV;
extern Symbol* SYM_PLI_PLI_F_GET_INFERRED_BINARY_PROPOSITION_VALUES_QUERY_000;
extern Keyword* KWD_PLI_ISA;
extern Symbol* SYM_PLI_STELLA_TRUE;
extern Symbol* SYM_PLI_STELLA_FALSE;
extern Keyword* KWD_PLI_CASE_SENSITIVEp;
extern Surrogate* SGT_PLI_STELLA_MODULE;
extern Keyword* KWD_PLI_SUBSET_OF;
extern Keyword* KWD_PLI_ERROR;
extern Keyword* KWD_PLI_RETRACT_TRUE;
extern Keyword* KWD_PLI_ASSERT_TRUE;
extern Surrogate* SGT_PLI_LOGIC_PROPOSITION;
extern Symbol* SYM_PLI_LOGIC_DESCRIPTION;
extern Surrogate* SGT_PLI_STELLA_INTEGER_WRAPPER;
extern Surrogate* SGT_PLI_STELLA_FLOAT_WRAPPER;
extern Surrogate* SGT_PLI_STELLA_NUMBER_WRAPPER;
extern Surrogate* SGT_PLI_STELLA_STRING_WRAPPER;
extern Symbol* SYM_PLI_PLI_STARTUP_PLI;
extern Symbol* SYM_PLI_STELLA_METHOD_STARTUP_CLASSNAME;

// Function signatures:
int main();

} // end of namespace pli
