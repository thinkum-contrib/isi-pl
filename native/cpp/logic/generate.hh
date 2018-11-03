//  -*- Mode: C++ -*-

// generate.hh

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

// Class definitions:
class TermGenerationException : public LogicException {
// Signals an exception during term generation.
public:
  Object* offendingTerm;
public:
  TermGenerationException(const std::string& msg) : LogicException(msg) {
}

};


// Global declarations:
extern DECLARE_STELLA_SPECIAL(oCANONICALVARIABLENAMEMAPPINGo, KeyValueList* );
extern DECLARE_STELLA_SPECIAL(oCANONICALVARIABLECOUNTERo, int );

// Function signatures:
TermGenerationException* newTermGenerationException(Object* offendingTerm, char* message);
Object* generateExpression(LogicObject* self, boolean canonicalizevariablenamesP);
Symbol* generateNameOfVariable(PatternVariable* self);
Object* generateOneVariable(PatternVariable* self, boolean typedP);
Cons* generateVariables(Vector* vector, boolean typedP);
Cons* generateStellaCollection(Collection* self);
Object* generateDescription(Description* self);
Cons* generateArguments(Vector* arguments);
Symbol* generateOperator(Proposition* self);
Object* generateProposition(Proposition* self);
Cons* generateFunctionAsTerm(Proposition* self);
Object* generateSkolem(Skolem* self);
Object* generateTerm(Object* self);
Cons* generateImpliesProposition(Proposition* self);
Cons* generateDescriptionProposition(Description* self, boolean invertP);
Cons* generateDescriptionsAsRule(Description* head, Description* tail, Proposition* rule, boolean reversepolarityP);
Object* deobjectifyTree(Object* self);
void helpStartupGenerate1();
void startupGenerate();

// Auxiliary global declarations:
extern Surrogate* SGT_GENERATE_STELLA_THING;
extern Symbol* SYM_GENERATE_STELLA_SETOF;
extern Symbol* SYM_GENERATE_LOGIC_LISTOF;
extern Symbol* SYM_GENERATE_LOGIC_COMPLEMENT_DESCRIPTION;
extern Symbol* SYM_GENERATE_STELLA_NOT;
extern Symbol* SYM_GENERATE_LOGIC_KAPPA;
extern Symbol* SYM_GENERATE_STELLA_NULL;
extern Keyword* KWD_GENERATE_PREDICATE;
extern Keyword* KWD_GENERATE_FUNCTION;
extern Keyword* KWD_GENERATE_ISA;
extern Keyword* KWD_GENERATE_AND;
extern Keyword* KWD_GENERATE_OR;
extern Keyword* KWD_GENERATE_NOT;
extern Keyword* KWD_GENERATE_EQUIVALENT;
extern Symbol* SYM_GENERATE_STELLA_e;
extern Keyword* KWD_GENERATE_EXISTS;
extern Symbol* SYM_GENERATE_STELLA_EXISTS;
extern Symbol* SYM_GENERATE_LOGIC_IO_VARIABLES;
extern Keyword* KWD_GENERATE_FORALL;
extern Symbol* SYM_GENERATE_STELLA_FORALL;
extern Symbol* SYM_GENERATE_STELLA_eg;
extern Keyword* KWD_GENERATE_IMPLIES;
extern Keyword* KWD_GENERATE_FAIL;
extern Symbol* SYM_GENERATE_LOGIC_FAIL;
extern Keyword* KWD_GENERATE_CONSTANT;
extern Symbol* SYM_GENERATE_LOGIC_UNIDENTIFIED_SKOLEM;
extern Surrogate* SGT_GENERATE_LOGIC_PROPOSITION;
extern Surrogate* SGT_GENERATE_STELLA_LITERAL_WRAPPER;
extern Surrogate* SGT_GENERATE_LOGIC_DESCRIPTION;
extern Surrogate* SGT_GENERATE_LOGIC_PATTERN_VARIABLE;
extern Surrogate* SGT_GENERATE_LOGIC_SKOLEM;
extern Surrogate* SGT_GENERATE_LOGIC_LOGIC_OBJECT;
extern Symbol* SYM_GENERATE_LOGIC_UNNAMED_OBJECT;
extern Surrogate* SGT_GENERATE_STELLA_COLLECTION;
extern Surrogate* SGT_GENERATE_LOGIC_LOGIC_THING;
extern Symbol* SYM_GENERATE_LOGIC_ILLEGAL_TERM;
extern Symbol* SYM_GENERATE_PL_KERNEL_KB_SUBSET_OF;
extern Symbol* SYM_GENERATE_LOGIC_FORWARD_ONLYp;
extern Surrogate* SGT_GENERATE_STELLA_CONS;
extern Symbol* SYM_GENERATE_LOGIC_STARTUP_GENERATE;
extern Symbol* SYM_GENERATE_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
