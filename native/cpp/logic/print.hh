//  -*- Mode: C++ -*-

// print.hh

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
extern DECLARE_STELLA_SPECIAL(oPRINTMODEo, Keyword* );
extern DECLARE_STELLA_SPECIAL(oPRINTFUNCTIONSASRELATIONSpo, boolean );
extern char* VARIABLE_BINDING_SEPARATOR;
extern char* VALUE_OF_SEPARATOR;
extern DECLARE_STELLA_SPECIAL(oSKOLEMNAMEMAPPINGTABLEo, KeyValueList* );
extern boolean oDEBUG_MODEpo;

// Function signatures:
OutputStream* wrapNativeOutputStream(std::ostream* nativestream);
void printTopLevelObject(Object* self, std::ostream* nativestream);
void printLogicObject(LogicObject* self, OutputStream* stream, boolean toplevelP);
char* getSkolemPrintName(Skolem* self);
void printValueOfChain(Skolem* self, OutputStream* stream, Object* chainend);
void printSkolemName(Skolem* self, OutputStream* stream);
void printVariableName(PatternVariable* self, OutputStream* stream);
void printVariableValue(Object* self, OutputStream* stream);
void printSkolem(Skolem* self, OutputStream* stream, boolean toplevelP);
void printVariable(PatternVariable* self, OutputStream* stream);
void printQuantifiedVariable(PatternVariable* self, OutputStream* stream);
void printProposition(Proposition* self, OutputStream* stream, boolean toplevelP);
void printDescription(Description* self, OutputStream* stream, boolean toplevelP);
void startupPrint();

// Auxiliary global declarations:
extern Surrogate* SGT_PRINT_LOGIC_DESCRIPTION;
extern Surrogate* SGT_PRINT_LOGIC_PATTERN_VARIABLE;
extern Surrogate* SGT_PRINT_LOGIC_SKOLEM;
extern Surrogate* SGT_PRINT_LOGIC_TRUTH_VALUE;
extern Surrogate* SGT_PRINT_LOGIC_LOGIC_OBJECT;
extern Surrogate* SGT_PRINT_LOGIC_PROPOSITION;
extern Keyword* KWD_PRINT_FLAT;
extern Keyword* KWD_PRINT_REALISTIC;
extern Keyword* KWD_PRINT_ORIGINAL;
extern Keyword* KWD_PRINT_DEBUG_LOW;
extern Keyword* KWD_PRINT_DEBUG_HIGH;
extern Surrogate* SGT_PRINT_STELLA_RELATION;
extern Symbol* SYM_PRINT_LOGIC_DESCRIPTION;
extern Symbol* SYM_PRINT_LOGIC_DESCRIPTIVEp;
extern Symbol* SYM_PRINT_STELLA_SURROGATE_VALUE_INVERSE;
extern Symbol* SYM_PRINT_LOGIC_STARTUP_PRINT;
extern Symbol* SYM_PRINT_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
