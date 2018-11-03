//  -*- Mode: C++ -*-

// backlinks.hh

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



namespace logic {
  using namespace stella;

// Global declarations:
extern int oSPECIALIZED_BACKLINKS_CROSSOVER_POINTo;
extern IntegerHashTable* oINTEGER_LOGIC_WRAPPER_TABLEo;
extern FloatHashTable* oFLOAT_LOGIC_WRAPPER_TABLEo;
extern StringHashTable* oSTRING_LOGIC_WRAPPER_TABLEo;
extern boolean oBACKLINK_ALL_PROPOSITION_ARGUMENTSpo;
extern DECLARE_STELLA_SPECIAL(oSUPPRESSINSERTIONINTOCLASSEXTENSIONpo, boolean );

// Function signatures:
boolean typeHasBacklinksP(Surrogate* type);
BacklinksIndex* createBacklinksIndex(Object* self);
BacklinksIndex* getBacklinksIndex(Object* self);
void addDependentPropositionToSpecializedIndex(BacklinksIndex* index, Proposition* proposition, Object* argument);
void helpAddDependentProposition(BacklinksIndex* index, Proposition* proposition, Object* argument);
void addDependentPropositionLink(Object* self, Proposition* proposition);
void removeDependentPropositionLink(Object* self, Proposition* proposition);
void helpRemoveDependentProposition(BacklinksIndex* index, Proposition* proposition);
void removeAllDependentPropositionLinks(LogicObject* self);
Object* rewrapArgument(Object* argument);
boolean indexIthDomainP(NamedDescription* description, int i);
boolean rewrapIthArgumentP(Object* argument, Proposition* proposition, int i);
void rewrapPropositionArguments(Proposition* self);
SequenceIndex* unfilteredDependentPropositions(Object* self, Surrogate* relation);
boolean allSpecializingDependentPropositionsNextP(AllPurposeIterator* self);
Iterator* allSpecializingDependentPropositions(Object* self, Surrogate* relationref);
SequenceIndex* unfilteredDependentIsaPropositions(Object* self);
SequenceIndex* unfilteredDependentImpliesPropositions(Object* self);
boolean inheritsTruthFromMasterP(Proposition* self);
Cons* applicableRulesOfDescription(LogicObject* self, Keyword* direction, boolean truerulesonlyP);
Cons* makeSelectionPattern(Keyword* kind, Cons* options, Cons* arguments);
Keyword* patternKind(Cons* pattern);
Cons* patternOptions(Cons* pattern);
Cons* patternArguments(Cons* pattern);
Cons* makeDependentPropositionsPattern(Object* argument);
Cons* makeIsaPattern(Object* argument);
Cons* makeRelationExtensionPattern(Surrogate* relation);
Cons* makeRelationPattern(Surrogate* relation, Object* argument);
Cons* makeRelationPattern1(Surrogate* relation, Object* argument);
Cons* makeRelationPattern2(Surrogate* relation, Object* argument1, Object* argument2);
Cons* makeRelationPattern3(Surrogate* relation, Object* argument1, Object* argument2, Object* argument3);
Cons* makeRelationPattern4(Surrogate* relation, Object* argument1, Object* argument2, Object* argument3, Object* argument4);
Cons* makeRelationPatternN(Surrogate* relation, int arguments, ...);
Cons* makeRulesPattern(Object* posrelation, Object* negrelation);
LogicObject* findSelectionKeyWithEquivalents(Cons* pattern);
SequenceIndex* selectPropositions(Cons* pattern);
SequenceIndex* selectIsaPropositions(Cons* pattern);
SequenceIndex* selectRelationPropositions(Cons* pattern);
SequenceIndex* selectRulePropositions(Cons* pattern);
TruthValue* evaluateSelectionPattern(Cons* pattern);
boolean evaluationSelectionPatternP(Cons* pattern);
boolean argumentDiscouragesBacklinksP(Object* self);
void surrogatifyDiscouragedArguments(Proposition* self);
int countBacklinksOnRelation(Object* self, Keyword* kind, Surrogate* relation);
Object* selectArgumentWithBacklinks(Proposition* proposition, boolean& _Return1);
boolean instanceHasBacklinksP(Object* self);
Object* selectInstanceWithBacklinks(Cons* instances, Surrogate* relation);
SequenceIndex* findSimilarPropositions(Proposition* self);
Proposition* findMatchingConceivedProposition(Proposition* goal);
void transferPropositionsAndBacklinks(Object* from, Object* to);
void transferPropositionsExceptFor(Object* from, Object* to, List* exceptpropositions);
void transferDescriptionExtension(NamedDescription* from, NamedDescription* to);
SequenceIndex* getDescriptionExtension(NamedDescription* description, boolean updateP);
void cleanupDescriptionExtension(NamedDescription* description);
void cleanupAllDescriptionExtensions();
void updateDescriptionExtension(Proposition* self);
Iterator* allExtensionMembers(NamedDescription* description);
boolean collectionImpliesCollectionP(LogicObject* subcollection, LogicObject* supercollection);
boolean relationImpliesRelationP(NamedDescription* subrel, NamedDescription* superrel);
boolean descriptionImpliesDescriptionP(Description* subdesc, Description* superdesc);
boolean relationrefSpecializesRelationrefP(Surrogate* relationref1, Surrogate* relationref2);
void helpStartupBacklinks1();
void helpStartupBacklinks2();
void startupBacklinks();

// Auxiliary global declarations:
extern Surrogate* SGT_BACKLINKS_LOGIC_PATTERN_VARIABLE;
extern Keyword* KWD_BACKLINKS_NON_PAGING;
extern Keyword* KWD_BACKLINKS_DEPENDENTS;
extern Surrogate* SGT_BACKLINKS_LOGIC_LOGIC_OBJECT;
extern Surrogate* SGT_BACKLINKS_STELLA_THING;
extern Symbol* SYM_BACKLINKS_LOGIC_DEPENDENT_PROPOSITIONS_INDEX;
extern Surrogate* SGT_BACKLINKS_LOGIC_INTEGER_LOGIC_WRAPPER;
extern Surrogate* SGT_BACKLINKS_LOGIC_FLOAT_LOGIC_WRAPPER;
extern Surrogate* SGT_BACKLINKS_LOGIC_STRING_LOGIC_WRAPPER;
extern Keyword* KWD_BACKLINKS_ISA;
extern Keyword* KWD_BACKLINKS_RELATION;
extern Surrogate* SGT_BACKLINKS_LOGIC_PROPOSITION;
extern Keyword* KWD_BACKLINKS_CONSTANT;
extern Surrogate* SGT_BACKLINKS_LOGIC_DESCRIPTION;
extern Symbol* SYM_BACKLINKS_LOGIC_COMPLEMENT_DESCRIPTION;
extern Surrogate* SGT_BACKLINKS_LOGIC_SKOLEM;
extern Surrogate* SGT_BACKLINKS_LOGIC_NON_PAGING_INDEX;
extern Surrogate* SGT_BACKLINKS_STELLA_INTEGER;
extern Surrogate* SGT_BACKLINKS_STELLA_FLOAT;
extern Surrogate* SGT_BACKLINKS_STELLA_STRING;
extern Surrogate* SGT_BACKLINKS_STELLA_LITERAL_WRAPPER;
extern Surrogate* SGT_BACKLINKS_LOGIC_PAGING_INDEX;
extern Surrogate* SGT_BACKLINKS_PL_KERNEL_KB_SUBSET_OF;
extern Symbol* SYM_BACKLINKS_LOGIC_MASTER_PROPOSITION;
extern Keyword* KWD_BACKLINKS_FORWARD;
extern Symbol* SYM_BACKLINKS_LOGIC_SUBSUMPTION_LINKp;
extern Keyword* KWD_BACKLINKS_RULES;
extern Keyword* KWD_BACKLINKS_CONTEXT_PROPOSITIONS;
extern Keyword* KWD_BACKLINKS_CONTEXT_INSTANCES;
extern Keyword* KWD_BACKLINKS_EVALUATEp;
extern Symbol* SYM_BACKLINKS_STELLA_TRUE;
extern Keyword* KWD_BACKLINKS_FUNCTION;
extern Keyword* KWD_BACKLINKS_PREDICATE;
extern Keyword* KWD_BACKLINKS_EQUIVALENT;
extern Keyword* KWD_BACKLINKS_PAGING;
extern Symbol* SYM_BACKLINKS_LOGIC_HYPOTHESIZED_INSTANCEp;
extern Symbol* SYM_BACKLINKS_LOGIC_STARTUP_BACKLINKS;
extern Symbol* SYM_BACKLINKS_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
