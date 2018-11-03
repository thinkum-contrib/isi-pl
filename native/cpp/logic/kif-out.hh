//  -*- Mode: C++ -*-

// kif-out.hh

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
extern DECLARE_STELLA_SPECIAL(oPRETTYPRINTLOGICALFORMSpo, boolean );
extern DECLARE_STELLA_SPECIAL(oPRETTYPRINTKIFpo, boolean );
extern DECLARE_STELLA_SPECIAL(oPRINTLOGICALFORMSTREAMo, OutputStream* );
extern DECLARE_STELLA_SPECIAL(oDOWNCASEOPERATORSpo, boolean );
extern KeyValueList* oLOGIC_DIALECT_PRINT_FUNCTIONSo;
extern DECLARE_STELLA_SPECIAL(oINDENTCOUNTERo, int );
extern int oINDENT_QUANTUMo;
extern DECLARE_STELLA_SPECIAL(oTOPLEVELPRINTKIFPROPOSITIONpo, boolean );
extern DECLARE_STELLA_SPECIAL(oEXCLUDEDPROPOSITIONSo, HashTable* );
extern Cons* oBUILT_IN_MODULE_NAMESo;

// Function signatures:
void registerLogicDialectPrintFunction(Keyword* dialect, FunctionCodeWrapper* fn);
char* maybeDowncase(char* string);
void increaseIndent(int indent);
void decreaseIndent(int indent);
void printIndent(OutputStream* stream, int indent);
void printLogicalFormInDialect(Object* self, Keyword* dialect, OutputStream* stream);
void printLogicalForm(Object* form, OutputStream* stream);
void prettyPrintLogicalForm(Object* form, OutputStream* stream);
void printUnformattedLogicalForm(Object* form, OutputStream* stream);
void printFormula(Object* formula, int indent);
void printAsKif(Object* self, OutputStream* stream);
void printAsKifInternal(Object* self);
boolean visibleArgumentP(Object* self);
int visibleArgumentsCount(Vector* arguments);
void printKifArguments(Vector* arguments, boolean separatelinesP, boolean omitlastargumentP);
void printKifOperatorWithArguments(char* operatoR, Vector* arguments, boolean separatelinesP, boolean omitlastargumentP);
char* stringifiedSurrogate(Surrogate* operatoR);
char* stringifiedKifOperator(Proposition* self);
void printKifProposition(Proposition* self);
void helpPrintKifProposition(Proposition* self);
void printKifFunctionProposition(Proposition* self);
void printKifFunctionExpression(Proposition* self);
void printKifImpliesProposition(Proposition* self);
void printKifQuantifiedVariables(Vector* variables, boolean includetypesP);
void printKifQuantification(Proposition* self);
void printKifTopLevelExistsProposition(Proposition* self);
void printKifWrapper(LiteralWrapper* self);
void printKifLogicObject(LogicObject* self);
void printKifSkolem(Skolem* self, boolean suppressdefiningpropositionP);
void printKifVariable(PatternVariable* self);
void printKifStellaCollection(Collection* self);
void printKifDescription(Description* self);
void printKifDescriptionProposition(Description* self, boolean invertP);
Surrogate* chooseImplicationOperator(Proposition* rule, boolean forwardP);
KeyValueList* createSkolemMappingTable(Vector* oldvars, Vector* newvars);
void printDescriptionsAsKifRule(Description* head, Description* tail, Proposition* rule, boolean reversepolarityP);
void excludeOriginatedPropositions();
boolean functionOutputSkolemP(Object* self);
boolean excludedPropositionP(Proposition* proposition);
void prettyPrintNamedDescription(NamedDescription* self, OutputStream* stream);
char* stellaRelationStringifiedSource(Relation* self);
void prettyPrintRelationDefinition(Relation* self, OutputStream* stream);
void prettyPrintRelationDefinitionTree(Cons* tree, OutputStream* stream);
void helpPrettyPrintRelationDefinitionTree(Cons* tree, OutputStream* stream, int startindent, int keyindent, boolean forcefirstkeyonseparatelineP);
void prettyPrintAssertion(Proposition* proposition, OutputStream* stream);
void prettyPrintNamedRule(Surrogate* rulename, OutputStream* stream);
void printModuleFileHeader(Module* module, OutputStream* stream);
void saveObject(Object* object, Object* store);
void doSaveModule(Module* module, Object* store);
void saveModule(Object* name, char* file);
void saveModuleEvaluatorWrapper(Cons* arguments);
void helpStartupKifOut1();
void helpStartupKifOut2();
void helpStartupKifOut3();
void startupKifOut();

// Auxiliary global declarations:
extern Keyword* KWD_KIF_OUT_KIF;
extern Keyword* KWD_KIF_OUT_STELLA;
extern Keyword* KWD_KIF_OUT_PREFIX_STELLA;
extern Keyword* KWD_KIF_OUT_SQL;
extern Surrogate* SGT_KIF_OUT_LOGIC_PROPOSITION;
extern Surrogate* SGT_KIF_OUT_LOGIC_DESCRIPTION;
extern Surrogate* SGT_KIF_OUT_LOGIC_PATTERN_VARIABLE;
extern Surrogate* SGT_KIF_OUT_LOGIC_SKOLEM;
extern Surrogate* SGT_KIF_OUT_LOGIC_LOGIC_OBJECT;
extern Surrogate* SGT_KIF_OUT_STELLA_COLLECTION;
extern Surrogate* SGT_KIF_OUT_STELLA_THING;
extern Keyword* KWD_KIF_OUT_ISA;
extern Keyword* KWD_KIF_OUT_REALISTIC;
extern Keyword* KWD_KIF_OUT_ORIGINAL;
extern Keyword* KWD_KIF_OUT_UNESCAPED;
extern Keyword* KWD_KIF_OUT_ESCAPED;
extern Keyword* KWD_KIF_OUT_COMPLEX_ESCAPED;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_NOT;
extern Keyword* KWD_KIF_OUT_AND;
extern Keyword* KWD_KIF_OUT_OR;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_AND;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_OR;
extern Keyword* KWD_KIF_OUT_NOT;
extern Keyword* KWD_KIF_OUT_EQUIVALENT;
extern Keyword* KWD_KIF_OUT_PREDICATE;
extern Keyword* KWD_KIF_OUT_FUNCTION;
extern Keyword* KWD_KIF_OUT_IMPLIES;
extern Keyword* KWD_KIF_OUT_FORALL;
extern Keyword* KWD_KIF_OUT_EXISTS;
extern Keyword* KWD_KIF_OUT_CONSTANT;
extern Keyword* KWD_KIF_OUT_CONTAINED_BY;
extern Keyword* KWD_KIF_OUT_DELETED;
extern Symbol* SYM_KIF_OUT_LOGIC_FORWARD_ONLYp;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_le;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_FORALL;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_EXISTS;
extern Symbol* SYM_KIF_OUT_LOGIC_IO_VARIABLES;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_SETOF;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_LISTOF;
extern Symbol* SYM_KIF_OUT_LOGIC_COMPLEMENT_DESCRIPTION;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_KAPPA;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_eg;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_egg;
extern Symbol* SYM_KIF_OUT_LOGIC_BACKWARD_ONLYp;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_lle;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_lt;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_tg;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_llt;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_tgg;
extern Symbol* SYM_KIF_OUT_LOGIC_MASTER_PROPOSITION;
extern Surrogate* SGT_KIF_OUT_STELLA_LITERAL_WRAPPER;
extern Surrogate* SGT_KIF_OUT_PL_KERNEL_KB_CLOSED;
extern Keyword* KWD_KIF_OUT_TERSE;
extern Keyword* KWD_KIF_OUT_VERBOSE;
extern Keyword* KWD_KIF_OUT_SOURCE;
extern Keyword* KWD_KIF_OUT_SLOTS;
extern Keyword* KWD_KIF_OUT_PUBLIC_SLOTS;
extern Keyword* KWD_KIF_OUT_METHODS;
extern Keyword* KWD_KIF_OUT_PUBLIC_METHODS;
extern Symbol* SYM_KIF_OUT_STELLA_ASSERT;
extern Symbol* SYM_KIF_OUT_STELLA_SURROGATE_VALUE_INVERSE;
extern Symbol* SYM_KIF_OUT_LOGIC_DEFRULE;
extern Symbol* SYM_KIF_OUT_LOGIC_IN_DIALECT;
extern Surrogate* SGT_KIF_OUT_STELLA_RELATION;
extern Surrogate* SGT_KIF_OUT_STELLA_OUTPUT_STREAM;
extern Surrogate* SGT_KIF_OUT_LOGIC_OBJECT_STORE;
extern Surrogate* SGT_KIF_OUT_LOGIC_NAMED_DESCRIPTION;
extern Symbol* SYM_KIF_OUT_LOGIC_UNDECLAREDp;
extern Symbol* SYM_KIF_OUT_LOGIC_STARTUP_KIF_OUT;
extern Symbol* SYM_KIF_OUT_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
