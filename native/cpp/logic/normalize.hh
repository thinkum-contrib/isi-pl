//  -*- Mode: C++ -*-

// normalize.hh

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
boolean searchControlPropositionP(Proposition* self);
boolean duplicateAndOrArgumentsP(Proposition* prop1, Proposition* prop2);
void collectFlatConjuncts(Proposition* self, List* flatconjuncts);
void overlayWithConstantProposition(Proposition* self, Proposition* constantproposition);
Proposition* conjoinPropositions(Cons* conjuncts);
Proposition* conjoinTwoPropositions(Proposition* prop1, Proposition* prop2);
void collectFlatDisjuncts(Proposition* self, List* flatdisjuncts);
Proposition* disjoinPropositions(Cons* disjuncts);
PatternVariable* renameLogicVariableApart(PatternVariable* variable, boolean destructiveP);
void overlayProposition(Proposition* self, Proposition* overlayingprop);
void normalizeExistsProposition(Proposition* self);
boolean migrateConsequentGoalsToAntecedentP(Proposition* self);
void flattenNestedForallProposition(Proposition* self);
void normalizeForallProposition(Proposition* self);
void normalizeNotProposition(Proposition* self);
void normalizeAndProposition(Proposition* self);
void normalizeOrProposition(Proposition* self);
void helpNormalizePredicateProposition(Proposition* self, Surrogate* relationref, List* predicatearguments);
void normalizePredicateProposition(Proposition* self);
Surrogate* computeRelationTermSurrogate(Skolem* skolem, Proposition* proposition);
Surrogate* evaluateRelationTerm(Object* relationterm, Proposition* proposition);
Proposition* normalizeValueFunction(Proposition* self);
void normalizeEquivalentProposition(Proposition* self);
Proposition* shallowCopyProposition(Proposition* self);
void normalizeProposition(Proposition* self);
void invertAtomicProposition(Proposition* self);
void invertExistsProposition(Proposition* self);
void invertForallProposition(Proposition* self);
Proposition* extractProposition(Description* self, KeyValueList* mapping);
void invertImpliesProposition(Proposition* self);
Proposition* invertProposition(Proposition* self);
Proposition* safelyInvertProposition(Proposition* self);
void helpStartupNormalize1();
void startupNormalize();

// Auxiliary global declarations:
extern Surrogate* SGT_NORMALIZE_PL_KERNEL_KB_CUT;
extern Surrogate* SGT_NORMALIZE_PL_KERNEL_KB_BOUND_VARIABLES;
extern Surrogate* SGT_NORMALIZE_PL_KERNEL_KB_FORK;
extern Surrogate* SGT_NORMALIZE_PL_KERNEL_KB_QUERY;
extern Keyword* KWD_NORMALIZE_AND;
extern Keyword* KWD_NORMALIZE_CONSTANT;
extern Surrogate* SGT_NORMALIZE_STELLA_TRUE;
extern Symbol* SYM_NORMALIZE_LOGIC_CONSTANT;
extern Surrogate* SGT_NORMALIZE_STELLA_CS_VALUE;
extern Symbol* SYM_NORMALIZE_STELLA_AND;
extern Symbol* SYM_NORMALIZE_LOGIC_DESCRIPTIVEp;
extern Keyword* KWD_NORMALIZE_OR;
extern Symbol* SYM_NORMALIZE_STELLA_OR;
extern Symbol* SYM_NORMALIZE_LOGIC_WEIGHT;
extern Symbol* SYM_NORMALIZE_LOGIC_NEURAL_NETWORK;
extern Symbol* SYM_NORMALIZE_LOGIC_IO_VARIABLES;
extern Symbol* SYM_NORMALIZE_LOGIC_VARIABLE_TYPEp;
extern Keyword* KWD_NORMALIZE_DESCRIPTION;
extern Keyword* KWD_NORMALIZE_EXISTS;
extern Keyword* KWD_NORMALIZE_NOT;
extern Keyword* KWD_NORMALIZE_ERROR;
extern Surrogate* SGT_NORMALIZE_STELLA_FALSE;
extern Keyword* KWD_NORMALIZE_FORALL;
extern Keyword* KWD_NORMALIZE_ISA;
extern Keyword* KWD_NORMALIZE_EQUIVALENT;
extern Keyword* KWD_NORMALIZE_PREDICATE;
extern Keyword* KWD_NORMALIZE_FUNCTION;
extern Symbol* SYM_NORMALIZE_STELLA_EXISTS;
extern Surrogate* SGT_NORMALIZE_PL_KERNEL_KB_HOLDS;
extern Surrogate* SGT_NORMALIZE_STELLA_THING;
extern Surrogate* SGT_NORMALIZE_LOGIC_PROPOSITION;
extern Surrogate* SGT_NORMALIZE_PL_KERNEL_KB_VARIABLE_ARITY;
extern Surrogate* SGT_NORMALIZE_PL_KERNEL_KB_ARITY;
extern Surrogate* SGT_NORMALIZE_PL_KERNEL_KB_CLASS;
extern Surrogate* SGT_NORMALIZE_PL_KERNEL_KB_FUNCTION;
extern Surrogate* SGT_NORMALIZE_PL_KERNEL_KB_VALUE;
extern Surrogate* SGT_NORMALIZE_LOGIC_PATTERN_VARIABLE;
extern Surrogate* SGT_NORMALIZE_LOGIC_SKOLEM;
extern Surrogate* SGT_NORMALIZE_LOGIC_NAMED_DESCRIPTION;
extern Symbol* SYM_NORMALIZE_STELLA_FUNCTION;
extern Symbol* SYM_NORMALIZE_LOGIC_DONT_OPTIMIZEp;
extern Keyword* KWD_NORMALIZE_IMPLIES;
extern Keyword* KWD_NORMALIZE_FAIL;
extern Keyword* KWD_NORMALIZE_COLLECT_INTO;
extern Symbol* SYM_NORMALIZE_STELLA_NOT;
extern Surrogate* SGT_NORMALIZE_LOGIC_NOT;
extern Surrogate* SGT_NORMALIZE_LOGIC_FORALL;
extern Surrogate* SGT_NORMALIZE_LOGIC_EXISTS;
extern Surrogate* SGT_NORMALIZE_LOGIC_DESCRIPTION;
extern Surrogate* SGT_NORMALIZE_LOGIC_OR;
extern Surrogate* SGT_NORMALIZE_LOGIC_AND;
extern Symbol* SYM_NORMALIZE_LOGIC_STARTUP_NORMALIZE;
extern Symbol* SYM_NORMALIZE_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
