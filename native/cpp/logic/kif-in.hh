//  -*- Mode: C++ -*-

// kif-in.hh

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
extern char oAUTOMATIC_INSTANCE_CHARACTERo;
extern Cons* oANNOTATION_TRANSLATION_TABLEo;
extern Cons* oKIF_SENTENCE_OPERATORSo;
extern Cons* oKIF_TERM_OPERATORSo;
extern DECLARE_STELLA_SPECIAL(oLOGIC_DIALECTo, Keyword* );

// Function signatures:
boolean questionMarkSymbolP(Object* symbol);
boolean sequenceVariableSymbolP(Object* self);
boolean automaticInstanceSymbolP(Object* symbol);
GeneralizedSymbol* kifSymbolToStellaSymbol(Symbol* symbol);
Symbol* kifVariableToStellaVariable(Object* variable);
boolean kifVariableDeclarationP(Object* tree);
Object* oneKifVariableDeclarationToStella(Object* tree);
boolean stellaVariableDeclarationsP(Object* tree);
Cons* kifVariableDeclarationsToStella(Object* tree, boolean errorP);
Cons* kifTheToStellaTheOnly(Cons* tree);
Cons* kifSetofallToStellaSetofall(Cons* tree);
Cons* kifKappaToStellaKappa(Cons* tree);
Cons* kifLambdaToStellaKappa(Cons* tree);
Cons* kifCondToIf(Cons* conditions);
Cons* kifImpliesToOrNot(Cons* tree);
Cons* kifBiconditionalToTwoImplies(Cons* tree);
Cons* kifExistsToStellaExists(Cons* tree);
Cons* kifThreeArgumentForallToStellaForall(Cons* tree, Cons* declarations);
Cons* kifTwoArgumentForallToStellaForall(Cons* tree, Cons* declarations);
Cons* kifForallToStellaForall(Cons* tree);
Cons* kifPredicationToStellaPredication(Cons* tree);
Cons* helpTransformKifFunction(Object* arg1, Object* arg2);
Cons* kifEqualityToStellaEquality(Cons* tree);
Symbol* kifOperatorToInternalStella(Symbol* operatoR);
Symbol* internalStellaOperatorToKif(Symbol* operatoR);
void changeKifExpressionsToStellaExpressions(Cons* expressions, boolean termsP);
Cons* canonicalizeAnnotation(Cons* tree);
Object* kifSentenceToUntypedStellaSentence(Object* tree);
boolean termKifSpecialFormP(Object* operatoR);
Object* kifTermToUntypedStellaTerm(Object* tree);
boolean kifVariableP(Object* self);
Cons* extractVariablesFromDeclarations(Object* declarations);
void collectUndeclaredVariables(Object* tree, Cons* declaredvariables, List* undeclaredvariables);
Object* wrapKifWithForall(Object* tree, Cons* declaredvariables);
Object* kifExpressionToUntypedStellaExpression(Object* tree);
Object* convertToPrefixPropositionTree(Object* tree);
Cons* infixToPrefixQuantificationTree(Cons* tree);
Object* standardizeLogicalParseTree(Object* tree);
Keyword* inDialect(Object* dialect);
void helpStartupKifIn1();
void startupKifIn();

// Auxiliary global declarations:
extern Symbol* SYM_KIF_IN_LOGIC_PARSE_TREE;
extern Keyword* KWD_KIF_IN_ERROR;
extern Surrogate* SGT_KIF_IN_STELLA_CONS;
extern Symbol* SYM_KIF_IN_STELLA_ISA;
extern Symbol* SYM_KIF_IN_LOGIC_THE_ONLY;
extern Symbol* SYM_KIF_IN_STELLA_TRUE;
extern Symbol* SYM_KIF_IN_STELLA_AND;
extern Symbol* SYM_KIF_IN_LOGIC_KAPPA;
extern Symbol* SYM_KIF_IN_STELLA_e;
extern Symbol* SYM_KIF_IN_STELLA_IF;
extern Symbol* SYM_KIF_IN_STELLA_le;
extern Symbol* SYM_KIF_IN_STELLA_OR;
extern Symbol* SYM_KIF_IN_STELLA_NOT;
extern Symbol* SYM_KIF_IN_STELLA_eg;
extern Symbol* SYM_KIF_IN_LOGIC_legg;
extern Symbol* SYM_KIF_IN_LOGIC_lleg;
extern Symbol* SYM_KIF_IN_LOGIC_llegg;
extern Symbol* SYM_KIF_IN_LOGIC_ltg;
extern Symbol* SYM_KIF_IN_LOGIC_ltgg;
extern Symbol* SYM_KIF_IN_LOGIC_lltg;
extern Symbol* SYM_KIF_IN_LOGIC_lltgg;
extern Symbol* SYM_KIF_IN_LOGIC_egg;
extern Symbol* SYM_KIF_IN_LOGIC_lle;
extern Symbol* SYM_KIF_IN_LOGIC_tg;
extern Symbol* SYM_KIF_IN_LOGIC_lt;
extern Symbol* SYM_KIF_IN_LOGIC_tgg;
extern Symbol* SYM_KIF_IN_LOGIC_llt;
extern Symbol* SYM_KIF_IN_STELLA_EXISTS;
extern Symbol* SYM_KIF_IN_STELLA_FORALL;
extern Symbol* SYM_KIF_IN_LOGIC_ABOUT;
extern Symbol* SYM_KIF_IN_PL_KERNEL_KB_VALUE;
extern Keyword* KWD_KIF_IN_DIRECTION;
extern Keyword* KWD_KIF_IN_BACKWARD;
extern Keyword* KWD_KIF_IN_FORWARD;
extern Keyword* KWD_KIF_IN_CONFIDENCE_LEVEL;
extern Keyword* KWD_KIF_IN_DEFAULT;
extern Keyword* KWD_KIF_IN_ABOUT;
extern Symbol* SYM_KIF_IN_PL_KERNEL_KB_HOLDS;
extern Symbol* SYM_KIF_IN_LOGIC_FAIL;
extern Symbol* SYM_KIF_IN_LOGIC_leg;
extern Symbol* SYM_KIF_IN_LOGIC_THE;
extern Symbol* SYM_KIF_IN_LOGIC_SETOFALL;
extern Symbol* SYM_KIF_IN_LOGIC_LAMBDA;
extern Symbol* SYM_KIF_IN_STELLA_COND;
extern Symbol* SYM_KIF_IN_STELLA_SETOF;
extern Symbol* SYM_KIF_IN_LOGIC_LISTOF;
extern Symbol* SYM_KIF_IN_STELLA_WHERE;
extern Symbol* SYM_KIF_IN_STELLA_ALWAYS;
extern Keyword* KWD_KIF_IN_KIF;
extern Keyword* KWD_KIF_IN_STELLA;
extern Keyword* KWD_KIF_IN_PREFIX_STELLA;
extern Keyword* KWD_KIF_IN_MELD;
extern Keyword* KWD_KIF_IN_LOOM;
extern Symbol* SYM_KIF_IN_LOGIC_STARTUP_KIF_IN;
extern Symbol* SYM_KIF_IN_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
