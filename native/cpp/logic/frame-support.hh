//  -*- Mode: C++ -*-

// frame-support.hh

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




namespace logic {
  using namespace stella;

// Function signatures:
Object* coerceToInstanceInModule(Object* self, Module* module, boolean localP, Object* original);
Object* getInstance(Object* instanceref);
Object* findInstance(Object* instanceref);
LogicObject* getSelfOrPrototype(Object* instanceref);
LogicObject* getClass(Object* instanceref);
LogicObject* getRelation(Object* instanceref);
Module* getModule(Object* moduleref);
boolean collectionP(Object* objectref);
boolean classP(Object* objectref);
boolean relationP(Object* objectref);
boolean functionP(Object* relationref);
boolean constantP(Object* objectref);
char* relationName(NamedDescription* self);
Object* termify(Object* self);
boolean relationArityOkP(Surrogate* relationref, int arity);
Cons* filterOutUnnamedDescriptions(Cons* descriptions);
Cons* allAssertedTypes(Object* self);
Cons* allTypes(Object* self);
Cons* helpAllTypes(Object* self);
Cons* allDirectTypes(Object* self);
boolean testTypeOnInstanceP(Object* self, Surrogate* type);
Cons* allEquivalentRelations(NamedDescription* relation, boolean reflexiveP);
Cons* removeEquivalentRelations(Cons* relationslist, NamedDescription* relation);
Cons* helpMemoizeAllSuperrelations(NamedDescription* relation, boolean removeequivalentsP);
Cons* allSuperrelations(NamedDescription* relation, boolean removeequivalentsP);
Cons* helpMemoizeAllSubrelations(NamedDescription* relation, boolean removeequivalentsP);
Cons* allSubrelations(NamedDescription* relation, boolean removeequivalentsP);
Cons* allDirectSuperrelations(NamedDescription* relation, boolean removeequivalentsP);
Cons* allDirectSubrelations(NamedDescription* relation, boolean removeequivalentsP);
boolean testSubrelationP(Surrogate* subrelation, Surrogate* superrelation);
Cons* allClassInstances(Surrogate* type);
Cons* allRelationValues(Surrogate* relation, Cons* nminusonearguments);
boolean testRelationOnArgumentsP(Surrogate* relation, Cons* arguments);
Cons* allSlotValues(LogicObject* self, Surrogate* relation);
Object* getSlotValue(LogicObject* self, Surrogate* relation);
boolean testSlotValueP(LogicObject* self, Surrogate* relation, Object* filler);
int getSlotMinimumCardinality(LogicObject* self, Surrogate* relation);
boolean testClosedSlotP(Surrogate* relation);
boolean testFunctionSlotP(Surrogate* relation);
int getSlotMaximumCardinality(LogicObject* self, Surrogate* relation);
NamedDescription* getSlotValueType(LogicObject* self, Surrogate* relation);
Cons* allSlotValueTypes(LogicObject* self, Surrogate* relation);
void helpStartupFrameSupport1();
void helpStartupFrameSupport2();
void startupFrameSupport();

// Auxiliary global declarations:
extern Surrogate* SGT_FRAME_SUPPORT_LOGIC_LOGIC_OBJECT;
extern Symbol* SYM_FRAME_SUPPORT_LOGIC_OBJECT_STORE;
extern Surrogate* SGT_FRAME_SUPPORT_STELLA_RELATION;
extern Surrogate* SGT_FRAME_SUPPORT_STELLA_THING;
extern Surrogate* SGT_FRAME_SUPPORT_LOGIC_PROPOSITION;
extern Surrogate* SGT_FRAME_SUPPORT_STELLA_MODULE;
extern Surrogate* SGT_FRAME_SUPPORT_PL_KERNEL_KB_COLLECTION;
extern Surrogate* SGT_FRAME_SUPPORT_PL_KERNEL_KB_CLASS;
extern Surrogate* SGT_FRAME_SUPPORT_PL_KERNEL_KB_RELATION;
extern Surrogate* SGT_FRAME_SUPPORT_PL_KERNEL_KB_FUNCTION;
extern Surrogate* SGT_FRAME_SUPPORT_STELLA_LITERAL_WRAPPER;
extern Surrogate* SGT_FRAME_SUPPORT_STELLA_LITERAL;
extern Surrogate* SGT_FRAME_SUPPORT_PL_KERNEL_KB_SCALAR;
extern Surrogate* SGT_FRAME_SUPPORT_LOGIC_NAMED_DESCRIPTION;
extern Surrogate* SGT_FRAME_SUPPORT_LOGIC_ALL_TYPES_MEMO_TABLE_000;
extern Keyword* KWD_FRAME_SUPPORT_ISA;
extern Surrogate* SGT_FRAME_SUPPORT_LOGIC_ALL_EQUIVALENT_RELATIONS_MEMO_TABLE_000;
extern Surrogate* SGT_FRAME_SUPPORT_LOGIC_ALL_SUPERRELATIONS_MEMO_TABLE_000;
extern Surrogate* SGT_FRAME_SUPPORT_LOGIC_ALL_SUBRELATIONS_MEMO_TABLE_000;
extern Surrogate* SGT_FRAME_SUPPORT_LOGIC_ALL_DIRECT_SUPERRELATIONS_MEMO_TABLE_000;
extern Surrogate* SGT_FRAME_SUPPORT_LOGIC_ALL_DIRECT_SUBRELATIONS_MEMO_TABLE_000;
extern Surrogate* SGT_FRAME_SUPPORT_PL_KERNEL_KB_RANGE_MIN_CARDINALITY;
extern Surrogate* SGT_FRAME_SUPPORT_PL_KERNEL_KB_RANGE_MAX_CARDINALITY;
extern Surrogate* SGT_FRAME_SUPPORT_PL_KERNEL_KB_RANGE_TYPE;
extern Symbol* SYM_FRAME_SUPPORT_LOGIC_STARTUP_FRAME_SUPPORT;
extern Symbol* SYM_FRAME_SUPPORT_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
