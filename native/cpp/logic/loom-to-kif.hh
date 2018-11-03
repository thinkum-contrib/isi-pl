//  -*- Mode: C++ -*-

// loom-to-kif.hh

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

// Function signatures:
Object* loomArgumentDescriptionToKif(Object* tree, Keyword* arity);
Cons* loomRestrictionToKif(Cons* tree, Symbol* implicitvariable);
Cons* loomRelatesToKif(Cons* tree, Cons* implicitvariables);
void substituteVariablesInTree(Cons* tree, Cons* substitution);
Cons* loomThroughToKif(Cons* tree, Cons* implicitvariables);
Cons* loomSatisfiesToKif(Cons* tree, Cons* implicitvariables);
Cons* loomDescriptionToKif(Object* tree, Cons* implicitvariables);
boolean loomDescriptionOperatorP(Object* self);
Object* loomSentenceToKif(Object* tree);
int computeLoomDescriptionArity(Object* tree);
Object* eliminateLoomKeywords(Object* tree);
Cons* yieldImplicitVariables(int arity);
Cons* helpTranslateLoomDescriptionToKif(Object* tree, Cons* implicitvariables);
Cons* translateLoomDescriptionToKif(Object* tree);
Object* translateLoomSentenceToKif(Object* tree);
Cons* translateLoomAssertions(Cons* tree, boolean retractP);
Cons* translateLoomAsk(Cons* tree);
Cons* translateLoomRetrieve(Cons* tree);
Cons* translateOneLoomForm(Object* tree);
Object* safeGetNextSExpression(SExpressionIterator* iter);
void translateLoomFile(char* input, char* output);
Cons* translateLoomStatement(Cons* tree);
int guessLoomDefinitionArity(int arity, Object* definition, Cons* constraints);
Object* conjoinSentences(Cons* sentences);
Cons* translateLoomPartitions(Object* partitions, boolean exhaustiveP, Symbol* parentconcept);
Cons* translateLoomCharacteristics(Object* characteristics, Symbol* name);
Cons* translateLoomAnnotations(Object* annotations, Symbol* name);
Cons* translateLoomDefaults(Object* defaultTree, Cons* variables);
Keyword* simplifyTopLevelLoomKeywords(Keyword* keyword);
Cons* translateLoomDefinition(Cons* tree);
Cons* translateLoomContextChange(Cons* tree, boolean needsquoteP);
void helpStartupLoomToKif1();
void helpStartupLoomToKif2();
void startupLoomToKif();

// Auxiliary global declarations:
extern Surrogate* SGT_LOOM_TO_KIF_STELLA_CONS;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_INVERSE;
extern Symbol* SYM_LOOM_TO_KIF_PL_KERNEL_KB_INVERSE;
extern Keyword* KWD_LOOM_TO_KIF_BINARY;
extern Keyword* KWD_LOOM_TO_KIF_UNARY;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_KAPPA;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_AT_LEAST;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_AT_MOST;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_EXACTLY;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_ALL;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_SOME;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_THE;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_FILLED_BY;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_FILLERS;
extern Symbol* SYM_LOOM_TO_KIF_PL_KERNEL_KB_RANGE_CARDINALITY_LOWER_BOUND;
extern Symbol* SYM_LOOM_TO_KIF_PL_KERNEL_KB_RANGE_CARDINALITY_UPPER_BOUND;
extern Symbol* SYM_LOOM_TO_KIF_PL_KERNEL_KB_RANGE_CARDINALITY;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_EXISTS;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_eg;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_AND;
extern Symbol* SYM_LOOM_TO_KIF_PL_KERNEL_KB_RANGE_TYPE;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_RELATES;
extern Surrogate* SGT_LOOM_TO_KIF_STELLA_NUMBER_WRAPPER;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_FORALL;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_THROUGH;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_INTERVALii;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_INTERVALi_;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_INTERVAL_i;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_INTERVAL__;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_el;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_l;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_ge;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_g;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_OR;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_NOT;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_SAME_AS;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_le;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_lg;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_e;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_ONE_OF;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_THE_ORDERED_SET;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_SATISFIES;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_DOMAIN;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_DOMAINS;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_RANGE;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_COMPOSE;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_MEMBER_OF;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_SETOF;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_LISTOF;
extern Keyword* KWD_LOOM_TO_KIF_ERROR;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_ABOUT;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_CREATE;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_SUPERRELATIONS;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_SUPERCONCEPTS;
extern Symbol* SYM_LOOM_TO_KIF_PL_KERNEL_KB_SUBSET_OF;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_QUOTE;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_RETRACT;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_ASSERT;
extern Keyword* KWD_LOOM_TO_KIF_3_VALUED_P;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_ASK;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_NULL;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_CONSIFY;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_RETRIEVE;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_PROGN;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_EVAL_WHEN;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_TELL;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_FORGET;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_TELLM;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_FORGETM;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_DEFCONCEPT;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_DEFRELATION;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_DEFPROPERTY;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_CREATEM;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_DEFCONTEXT;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_ADD_VALUE;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_SET_VALUE;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_FADD_VALUE;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_CHANGE_CONTEXT;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_IN_CONTEXT;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_IN_KB;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_CC;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_IN_DIALECT;
extern Keyword* KWD_LOOM_TO_KIF_KIF;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_MUTUALLY_DISJOINT_COLLECTION;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_COVERING;
extern Keyword* KWD_LOOM_TO_KIF_SINGLE_VALUED;
extern Keyword* KWD_LOOM_TO_KIF_CLOSED_WORLD;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_CLOSED;
extern Keyword* KWD_LOOM_TO_KIF_COMMUTATIVE;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_COMMUTATIVE;
extern Keyword* KWD_LOOM_TO_KIF_SYMMETRIC;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_SYMMETRIC;
extern Keyword* KWD_LOOM_TO_KIF_CLOS_CLASS;
extern Keyword* KWD_LOOM_TO_KIF_MULTIPLE_VALUED;
extern Keyword* KWD_LOOM_TO_KIF_HASH_ON_DOMAINS;
extern Keyword* KWD_LOOM_TO_KIF_NON_EXPORTED;
extern Keyword* KWD_LOOM_TO_KIF_PERFECT;
extern Keyword* KWD_LOOM_TO_KIF_CLOSED_ON_CONSTANTS;
extern Keyword* KWD_LOOM_TO_KIF_BACKWARD_CHAINING;
extern Keyword* KWD_LOOM_TO_KIF_MONOTONIC;
extern Keyword* KWD_LOOM_TO_KIF_TEMPORAL;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_tg;
extern Keyword* KWD_LOOM_TO_KIF_ATTRIBUTES;
extern Keyword* KWD_LOOM_TO_KIF_CHARACTERISTICS;
extern Keyword* KWD_LOOM_TO_KIF_PARTITION;
extern Keyword* KWD_LOOM_TO_KIF_PARTITIONS;
extern Keyword* KWD_LOOM_TO_KIF_IMPLIES;
extern Keyword* KWD_LOOM_TO_KIF_CONSTRAINTS;
extern Keyword* KWD_LOOM_TO_KIF_EXHAUSTIVE_PARTITION;
extern Keyword* KWD_LOOM_TO_KIF_EXHAUSTIVE_PARTITIONS;
extern Surrogate* SGT_LOOM_TO_KIF_STELLA_STRING_WRAPPER;
extern Keyword* KWD_LOOM_TO_KIF_IS_PRIMITIVE;
extern Keyword* KWD_LOOM_TO_KIF_IS;
extern Keyword* KWD_LOOM_TO_KIF_DEFAULTS;
extern Keyword* KWD_LOOM_TO_KIF_DOMAIN;
extern Keyword* KWD_LOOM_TO_KIF_DOMAINS;
extern Keyword* KWD_LOOM_TO_KIF_RANGE;
extern Keyword* KWD_LOOM_TO_KIF_ARITY;
extern Keyword* KWD_LOOM_TO_KIF_IN_PARTITION;
extern Keyword* KWD_LOOM_TO_KIF_ANNOTATIONS;
extern Keyword* KWD_LOOM_TO_KIF_ROLES;
extern Keyword* KWD_LOOM_TO_KIF_NAME;
extern Keyword* KWD_LOOM_TO_KIF_IDENTIFIER;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_DEFFUNCTION;
extern Keyword* KWD_LOOM_TO_KIF__g;
extern Keyword* KWD_LOOM_TO_KIF_DOCUMENTATION;
extern Keyword* KWD_LOOM_TO_KIF_llegg;
extern Keyword* KWD_LOOM_TO_KIF_egg;
extern Keyword* KWD_LOOM_TO_KIF_AXIOMS;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_IN_MODULE;
extern Symbol* SYM_LOOM_TO_KIF_LOGIC_STARTUP_LOOM_TO_KIF;
extern Symbol* SYM_LOOM_TO_KIF_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
