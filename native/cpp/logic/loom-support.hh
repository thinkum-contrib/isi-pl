//  -*- Mode: C++ -*-

// loom-support.hh

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


namespace pl_kernel_kb_pl_kernel_kb_loom_api {
  using namespace stella;
  using namespace logic;
  using namespace pl_kernel_kb;

// Class definitions:
class LoomRole : public Thing {
// 
public:
  virtual Surrogate* primaryType();
};



// Function signatures:
Surrogate* safeSurrogatify(Object* surrogateref);
LoomRole* newLoomRole();
Object* accessLoomRoleSlotValue(LoomRole* self, Symbol* slotname, Object* value, boolean setvalueP);
LoomRole* findOrCreateLoomRole(Object* instanceref, Object* relationref, boolean createP);
Cons* getLoomRoles(Object* instanceref, boolean inferrolesP);
Cons* getRelationInducedRoles(Object* instanceref);
NamedDescription* relationOfLoomRole(LoomRole* role);
Cons* getRoleNamesAndValues(Object* instanceref);
Module* getXcontext(Object* contextref);
Cons* getParentContexts(Object* moduleref);
Cons* getChildContexts(Object* moduleref);
Module* contextOfInstance(Object* instanceref);
void clearUserContexts();
Cons* listContext(Module* context, Keyword* values);
int relationArity(Object* relationref);
LogicObject* findClass(Object* instanceref, Module* module, boolean localP);
LogicObject* findRelation(Object* instanceref, Module* module, boolean localP);
Surrogate* getInstanceSurrogate(Object* instanceref);
Symbol* getInstanceName(Object* instanceref);
Cons* getEquivalentNames(Object* relationref);
boolean instanceP(Object* objectref);
boolean individualP(Object* object);
boolean namedP(Object* instanceref);
Object* createInstance(Object* instanceref, Object* classref);
LogicObject* findOrCreateInstance(Object* instanceref, Object* classref);
boolean instanceOfP(Object* instanceref, Object* classref);
void addType(Object* instanceref, Object* classref);
void removeType(Object* instanceref, Object* classref);
Cons* getTypes(Object* instanceref, Keyword* directorasserted);
void updateRoleValue(Object* instanceref, Object* relationref, Object* valueref, boolean assertP);
void addRoleValue(Object* instanceref, Object* relationref, Object* valueref);
void removeRoleValue(Object* instanceref, Object* relationref, Object* valueref);
Object* getRoleValue(Object* instanceref, Object* relationref);
Cons* getRoleValues(Object* instanceref, Object* relationref);
Cons* getRoleDefaultValues(Object* instanceref, Object* relationref);
Cons* getClassInstances(Object* classref, boolean directP);
boolean subrelationP(Object* subrelationref, Object* superrelationref);
Cons* getSuperrelations(Object* relationref, boolean directP);
Cons* getSubrelations(Object* relationref, boolean directP);
Cons* mostSpecificRelations(Cons* relationrefs, boolean classifyfirstP);
Description* computeConjunctionRelation(Cons* relationrefs);
NamedDescription* getDomain(Object* relationref);
NamedDescription* getRange(Object* relationref);
int getMinCardinality(Object* instanceref, Object* relationref);
int getMaxCardinality(Object* instanceref, Object* relationref);
Description* getValueRestriction(Object* instanceref, Object* relationref);
void assertLoomProposition(Cons* loomsentence, boolean retractP);
void deleteInstance(Object* instanceref);
Object* generateSourceExpression(Object* instanceref);
Cons* getPartitions(Object* classref);
boolean disjointRelationsP(Object* relationref1, Object* relationref2);
boolean coveringP(Object* instanceref, Object* classref);
Cons* collectionMembers(Object* instanceref);
void helpStartupLoomSupport1();
void startupLoomSupport();

// Auxiliary global declarations:
extern Surrogate* SGT_LOOM_SUPPORT_LOOM_API_LOOM_ROLE;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_LOOM_ROLE_OF;
extern Keyword* KWD_LOOM_SUPPORT_DOCUMENTATION;
extern Keyword* KWD_LOOM_SUPPORT_AXIOMS;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_pI;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_pR;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_pROLE;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_QUERY_082;
extern Surrogate* SGT_LOOM_SUPPORT_LOOM_API_LOOM_ROLE_OF;
extern Symbol* SYM_LOOM_SUPPORT_STELLA_EXISTS;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_QUERY_083;
extern Symbol* SYM_LOOM_SUPPORT_STELLA_OR;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_pFR;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_pV;
extern Symbol* SYM_LOOM_SUPPORT_STELLA_AND;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_FRAME_PREDICATE;
extern Symbol* SYM_LOOM_SUPPORT_PL_KERNEL_KB_HOLDS;
extern Symbol* SYM_LOOM_SUPPORT_STELLA_NOT;
extern Symbol* SYM_LOOM_SUPPORT_STELLA_e;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_RANGE_MAX_CARDINALITY;
extern Symbol* SYM_LOOM_SUPPORT_LOGIC_pC;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_INSTANCE_OF;
extern Symbol* SYM_LOOM_SUPPORT_PL_KERNEL_KB_DOMAIN;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_QUERY_084;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_QUERY_085;
extern Surrogate* SGT_LOOM_SUPPORT_STELLA_MODULE;
extern Surrogate* SGT_LOOM_SUPPORT_LOGIC_LOGIC_OBJECT;
extern Keyword* KWD_LOOM_SUPPORT_ALL;
extern Keyword* KWD_LOOM_SUPPORT_CONCEPTS;
extern Symbol* SYM_LOOM_SUPPORT_LOGIC_pX;
extern Symbol* SYM_LOOM_SUPPORT_PL_KERNEL_KB_CLASS;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_QUERY_086;
extern Keyword* KWD_LOOM_SUPPORT_RELATIONS;
extern Symbol* SYM_LOOM_SUPPORT_PL_KERNEL_KB_RELATION;
extern Symbol* SYM_LOOM_SUPPORT_LOGIC_FAIL;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_QUERY_087;
extern Keyword* KWD_LOOM_SUPPORT_INSTANCES;
extern Surrogate* SGT_LOOM_SUPPORT_LOGIC_DESCRIPTION;
extern Surrogate* SGT_LOOM_SUPPORT_PL_KERNEL_KB_ARITY;
extern Surrogate* SGT_LOOM_SUPPORT_STELLA_SURROGATE;
extern Surrogate* SGT_LOOM_SUPPORT_STELLA_THING;
extern Keyword* KWD_LOOM_SUPPORT_ASSERT_TRUE;
extern Keyword* KWD_LOOM_SUPPORT_RETRACT_TRUE;
extern Keyword* KWD_LOOM_SUPPORT_DIRECT;
extern Keyword* KWD_LOOM_SUPPORT_ASSERTED;
extern Keyword* KWD_LOOM_SUPPORT_DEFAULT;
extern Keyword* KWD_LOOM_SUPPORT_STRICT;
extern Keyword* KWD_LOOM_SUPPORT_DESCRIPTION;
extern Symbol* SYM_LOOM_SUPPORT_LOGIC_KAPPA;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_pD;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_QUERY_088;
extern Symbol* SYM_LOOM_SUPPORT_PL_KERNEL_KB_RANGE;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_QUERY_089;
extern Symbol* SYM_LOOM_SUPPORT_LOGIC_pMDC;
extern Symbol* SYM_LOOM_SUPPORT_PL_KERNEL_KB_MEMBER_OF;
extern Symbol* SYM_LOOM_SUPPORT_PL_KERNEL_KB_MUTUALLY_DISJOINT_COLLECTION;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_QUERY_090;
extern Surrogate* SGT_LOOM_SUPPORT_PL_KERNEL_KB_MUTUALLY_DISJOINT_COLLECTION;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_pCOVERED;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_COVERING;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_QUERY_091;
extern Symbol* SYM_LOOM_SUPPORT_LOOM_API_STARTUP_LOOM_SUPPORT;
extern Symbol* SYM_LOOM_SUPPORT_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace pl_kernel_kb_pl_kernel_kb_loom_api
