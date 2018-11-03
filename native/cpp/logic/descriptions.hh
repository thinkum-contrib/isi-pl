//  -*- Mode: C++ -*-

// descriptions.hh

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

// Global declarations:
extern Vector* FAKE_IO_VARIABLES;
extern Cons* SYSTEM_DEFINED_ARGUMENT_NAMES;
extern DECLARE_STELLA_SPECIAL(oLOGICVARIABLETABLEo, Cons* );
extern DECLARE_STELLA_SPECIAL(oVARIABLETYPEPROPOSITIONSo, Cons* );
extern DECLARE_STELLA_SPECIAL(oUNIFY_PROPOSITIONSpo, boolean );
extern StringHashTable* oSTRINGIFIED_DESCRIPTION_INDEXo;
extern DECLARE_STELLA_SPECIAL(oEXTERNALVARIABLESo, Cons* );
extern DECLARE_STELLA_SPECIAL(oRECURSIVEGETCOMPLEMENTARGUMENTo, NamedDescription* );
extern DECLARE_STELLA_SPECIAL(oADDEDNEWTYPEpo, boolean );

// Function signatures:
Iterator* directSuperrelations(Relation* self);
Cons* slotColumnTypes(Slot* self, int count);
Description* createDescription(int arity, boolean namedP);
void createBaseRelationForPolymorphicDescription(Description* description);
Symbol* yieldSystemDefinedParameterName(int index, Object* referenceobject);
void ensureDescriptionBody(Description* description);
void materializePrimitiveDescriptionBody(NamedDescription* description);
NamedDescription* createPrimitiveDescription(List* iovariablenames, List* iovariabletypes, boolean variablearityP, boolean classP, boolean functionP, Module* module);
void linkStellaRelationAndDescription(Relation* self, NamedDescription* description);
NamedDescription* createDescriptionForStellaRelation(Relation* self);
NamedDescription* surrogateToDescription(Surrogate* self);
NamedDescription* getDescription(Object* self);
NamedDescription* surrogateDgetDescription(Surrogate* self);
NamedDescription* stringDgetDescription(char* self);
NamedDescription* classDgetDescription(Class* self);
NamedDescription* slotDgetDescription(Slot* self);
Surrogate* ensureDeferredDescription(Surrogate* self);
boolean logicClassP(Class* self);
boolean variableArityDomainTypesNextP(AllPurposeIterator* self);
Iterator* allDomainTypes(NamedDescription* self);
void pushLogicVariableBinding(Skolem* variable);
void popLogicVariableBinding();
void popLogicVariableBindings(Cons* variables);
Object* lookupLogicVariableBinding(Symbol* variablename);
void parseOneVariableDeclaration(Object* vdec, List* localdeclarations);
Cons* parseLogicVariableDeclarations(Object* tree);
Cons* helpBuildQuantifiedProposition(Cons* tree, boolean converttypestoconstraintsP, Proposition*& _Return1, Proposition*& _Return2);
Cons* buildQuantifiedProposition(Cons* tree, boolean converttypestoconstraintsP, Proposition*& _Return1, Proposition*& _Return2);
Vector* copyConsListToVariablesVector(Cons* conslist);
boolean equivalentHoldsPropositionP(Proposition* self, Proposition* other, KeyValueList* mapping);
boolean equivalentCommutativePropositionsP(Proposition* self, Proposition* other, KeyValueList* mapping);
boolean equivalentPropositionsP(Proposition* self, Proposition* other, KeyValueList* mapping);
boolean equivalentFunctionPropositionsP(Proposition* self, Proposition* other, KeyValueList* mapping);
boolean equivalentDescriptionsP(Description* self, Description* other, KeyValueList* mapping);
boolean equivalentEnumerationsP(Collection* self, Collection* other);
boolean equivalentFormulaeP(Object* self, Object* other, KeyValueList* mapping);
boolean sameArgumentsP(Vector* variables, Vector* arguments);
boolean unifyPropositionsP(Proposition* self, Proposition* other, KeyValueList* mapping);
boolean namedDescriptionP(Description* self);
boolean deletedLogicObjectP(LogicObject* self);
void uniquifyDescriptionVariables(Description* self);
void restoreDescriptionVariableNames(Description* self);
boolean consTreeLessThanP(Object* tree1, Object* tree2);
Cons* sortPropositionClauses(Cons* clauses);
Object* uniquifyPropositionTree(Object* tree);
Description* findExactDuplicateDescription(Description* self);
void helpCollectConstantReferences(Object* self, List* collection, boolean stopatoneP);
List* collectConstantDescriptionReferences(Description* self, List* collection, boolean stopatoneP);
Description* findDuplicateDescriptionWithConstantReference(Description* self);
Description* findDuplicateDescription(Description* self);
void addDependentDescriptionLink(Object* self, Description* description);
void fastenDownDescription(Description* self);
boolean containsNestedArgumentP(Proposition* proposition);
Proposition* expandIfProposition(Proposition* ifproposition);
void helpCollectFlattenedArguments(Proposition* self, List* flattenedarguments, List* existsvariables);
List* yieldFlattenedArguments(Proposition* proposition, List* existsvariables);
Proposition* flattenNestedFunctionArguments(Proposition* proposition);
void collapseValueOfChainsForIoVariables(Vector* iovariables);
Vector* removeNullsInVariablesVector(Vector* iovariables);
void collapseValueOfChains(Description* description);
void tightenArgumentBindings(Proposition* proposition, Vector* iovariables);
void collectAllVariables(Proposition* self, List* collection, List* beenthere);
void computeInternalVariables(Description* self);
void equateTopLevelEquivalences(Proposition* proposition);
void collectExternalVariables(Proposition* proposition);
Description* finishBuildingDescription(Description* description, boolean checkforduplicateP);
Description* evaluateDescriptionTerm(Cons* term, boolean checkforduplicateP);
Cons* removeVariableTypePropositions(Proposition* proposition);
Description* getComplementOfGoalDescription(NamedDescription* self);
void collectFreeVariables(Object* self, List* collection, List* quantifiedvars, List* beenthere);
Cons* topLevelExistentialVariables(Description* self);
boolean topLevelExistentialVariableP(PatternVariable* variable, Description* description);
boolean freeVariableP(PatternVariable* variable, Proposition* proposition);
List* mostSpecificTypes(List* types);
void addVariableType(PatternVariable* variable, Surrogate* newtype, KeyValueList* table, Cons* visiblevariables);
Object* inferPredicateFromOperatorAndTypes(Object* operatoR, List* types);
void inferTypesFromOneProposition(Proposition* proposition, KeyValueList* table, Cons* visiblevars);
void inferTypesFromPropositions(Proposition* proposition, KeyValueList* table, Cons* visiblevars);
KeyValueList* inferVariableTypesInProposition(Proposition* proposition, Cons* visiblevariables);
KeyValueList* inferVariableTypesInDescription(Description* description);
Cons* collectUnresolvedSlotReferences(Proposition* self);
boolean resolveOneSlotReferenceP(Proposition* proposition, KeyValueList* variabletypestable);
void resolveUnresolvedSlotReferences(Object* formula);
void createDummyRelation(Proposition* waywardproposition);
boolean definedRelationP(NamedDescription* self);
Cons* listUndefinedRelations(Object* module, boolean localP);
Cons* listUndefinedRelationsEvaluatorWrapper(Cons* arguments);
Cons* callListUndefinedRelations(Module* module, boolean localP);
void complainAboutUndeclaredReference(Proposition* waywardproposition);
boolean allNamedDescriptionsNextP(AllPurposeIterator* self);
Iterator* allNamedDescriptions(Module* module, boolean localP);
void helpStartupDescriptions1();
void helpStartupDescriptions2();
void helpStartupDescriptions3();
void helpStartupDescriptions4();
void startupDescriptions();

// Auxiliary global declarations:
extern Surrogate* SGT_DESCRIPTIONS_STELLA_SLOT;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_METHOD_SLOT;
extern Symbol* SYM_DESCRIPTIONS_STELLA_ANY_VALUE;
extern Keyword* KWD_DESCRIPTIONS_EXTENSIONAL_ASSERTION;
extern Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_RELATION;
extern Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_POLYMORPHIC;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX1;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX2;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX3;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX4;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX5;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX6;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX7;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX8;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX9;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX10;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX11;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX12;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX13;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX14;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX15;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX16;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX17;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX18;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX19;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX20;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX21;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX22;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX23;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX24;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX25;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX26;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX27;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX28;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX29;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX30;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX31;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX32;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX33;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX34;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX35;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX36;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX37;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX38;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX39;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX40;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX41;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX42;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX43;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX44;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX45;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX46;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX47;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX48;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX49;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX50;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX51;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX52;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX53;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX54;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX55;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX56;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX57;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX58;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX59;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX60;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX61;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX62;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX63;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX64;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX65;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX66;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX67;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX68;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX69;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX70;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX71;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX72;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX73;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX74;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX75;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX76;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX77;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX78;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX79;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX80;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX81;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX82;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX83;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX84;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX85;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX86;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX87;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX88;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX89;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX90;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX91;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX92;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX93;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX94;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX95;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX96;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX97;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX98;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX99;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX100;
extern Surrogate* SGT_DESCRIPTIONS_LOGIC_NAMED_DESCRIPTION;
extern Symbol* SYM_DESCRIPTIONS_STELLA_ISA;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_KAPPA;
extern Keyword* KWD_DESCRIPTIONS_KIF;
extern Keyword* KWD_DESCRIPTIONS_DESCRIPTION;
extern Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_CONCEPT;
extern Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_FUNCTION;
extern Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_VARIABLE_ARITY;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_DESCRIPTION;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_CLASS;
extern Keyword* KWD_DESCRIPTIONS_ERROR;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_RELATION;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_OBJECT_STORE;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_THING;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_LITERAL;
extern Surrogate* SGT_DESCRIPTIONS_LOGIC_PROPOSITION;
extern Keyword* KWD_DESCRIPTIONS_WARNING;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_CONS;
extern Keyword* KWD_DESCRIPTIONS_ISA;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_VARIABLE_TYPEp;
extern Symbol* SYM_DESCRIPTIONS_STELLA_EXISTS;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_ENTITY_MAPPING;
extern Keyword* KWD_DESCRIPTIONS_AND;
extern Keyword* KWD_DESCRIPTIONS_OR;
extern Keyword* KWD_DESCRIPTIONS_EQUIVALENT;
extern Keyword* KWD_DESCRIPTIONS_FORALL;
extern Keyword* KWD_DESCRIPTIONS_EXISTS;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_IO_VARIABLES;
extern Surrogate* SGT_DESCRIPTIONS_PL_KERNEL_KB_HOLDS;
extern Keyword* KWD_DESCRIPTIONS_FUNCTION;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_SET;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_LIST;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_SURROGATE;
extern Surrogate* SGT_DESCRIPTIONS_LOGIC_DESCRIPTION;
extern Keyword* KWD_DESCRIPTIONS_NOT;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_ORIGINAL_SKOLEM_NAME;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_GENERALIZED_SYMBOL;
extern Symbol* SYM_DESCRIPTIONS_STELLA_AND;
extern Symbol* SYM_DESCRIPTIONS_STELLA_OR;
extern Symbol* SYM_DESCRIPTIONS_STELLA_NOT;
extern Symbol* SYM_DESCRIPTIONS_STELLA_FORALL;
extern Surrogate* SGT_DESCRIPTIONS_LOGIC_PATTERN_VARIABLE;
extern Surrogate* SGT_DESCRIPTIONS_LOGIC_LOGIC_OBJECT;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_EXTERNAL_VARIABLES;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_DEPENDENT_DESCRIPTIONS;
extern Keyword* KWD_DESCRIPTIONS_PREDICATE;
extern Keyword* KWD_DESCRIPTIONS_IMPLIES;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_PROPOSITIONdIF;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_CS_VALUE;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_THE_ONLY;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_IOTAp;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_COMPLEMENT_DESCRIPTION;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_VARIABLE_TYPE_TABLE;
extern Surrogate* SGT_DESCRIPTIONS_STELLA_SYMBOL;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_UNDECLAREDp;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_pX;
extern Symbol* SYM_DESCRIPTIONS_PL_KERNEL_KB_RELATION;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_QUERY_038;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_DESCRIPTIVEp;
extern Symbol* SYM_DESCRIPTIONS_LOGIC_STARTUP_DESCRIPTIONS;
extern Symbol* SYM_DESCRIPTIONS_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
