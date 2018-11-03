// macros.hh

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1996, 1997             | 
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


// Function signatures:
Object* pushq_expander(Cons* variable, Object* value);
Object* popq_expander(Cons* variable);
Object* pushf_expander(Cons* place, Object* value);
Object* string_quote_expander(Object* tree);
Object* II_expander(Object* place);
Object* ___expander(Object* place);
Object* oneI_expander(Object* expression);
Object* one__expander(Object* expression);
Object* setqP_expander(Symbol* variable, Cons* expression);
Object* with_permanent_objects_expander(Cons* body);
Object* with_transient_objects_expander(Cons* body);
Object* ignore_expander(Cons* variables);
Object* only_if_expander(Object* test, Object* expression);
Object* phase_to_integer_expander(Keyword* startuptimephase);
Object* if_output_language_expander(Keyword* language, Object* thenform, Object* elseform);
Object* within_world_expander(Object* worldform, Cons* body);
Object* within_module_expander(Object* moduleform, Cons* body);
Cons* extract_output_expressions_from_select(Cons* selectbody);
void startup_macros();

// Global declarations:
extern Symbol* SYM_MACROS_SETQ;
extern Symbol* SYM_MACROS_CONS;
extern Symbol* SYM_MACROS_PUSHQ;
extern Symbol* SYM_MACROS_PUSHQ_EXPANDER;
extern Symbol* SYM_MACROS_VRLET;
extern Symbol* SYM_MACROS_VALUE;
extern Symbol* SYM_MACROS_REST;
extern Symbol* SYM_MACROS_POPQ;
extern Symbol* SYM_MACROS_POPQ_EXPANDER;
extern Symbol* SYM_MACROS_SETF;
extern Symbol* SYM_MACROS_PUSHF;
extern Symbol* SYM_MACROS_PUSHF_EXPANDER;
extern Symbol* SYM_MACROS_UNSTRINGIFY;
extern Symbol* SYM_MACROS_STRING_QUOTE;
extern Symbol* SYM_MACROS_STRING_QUOTE_EXPANDER;
extern Symbol* SYM_MACROS_i;
extern Symbol* SYM_MACROS_ii;
extern Symbol* SYM_MACROS_ii_EXPANDER;
extern Symbol* SYM_MACROS__;
extern Symbol* SYM_MACROS___;
extern Symbol* SYM_MACROS____EXPANDER;
extern Symbol* SYM_MACROS_1i;
extern Symbol* SYM_MACROS_1i_EXPANDER;
extern Symbol* SYM_MACROS_1_;
extern Symbol* SYM_MACROS_1__EXPANDER;
extern Symbol* SYM_MACROS_DEFINEDp;
extern Symbol* SYM_MACROS_SETQp;
extern Symbol* SYM_MACROS_SETQp_EXPANDER;
extern Symbol* SYM_MACROS_SPECIAL;
extern Symbol* SYM_MACROS_oTRANSIENTOBJECTSpo;
extern Symbol* SYM_MACROS_FALSE;
extern Symbol* SYM_MACROS_WITH_PERMANENT_OBJECTS;
extern Symbol* SYM_MACROS_WITH_PERMANENT_OBJECTS_EXPANDER;
extern Symbol* SYM_MACROS_TRUE;
extern Symbol* SYM_MACROS_WITH_TRANSIENT_OBJECTS;
extern Symbol* SYM_MACROS_WITH_TRANSIENT_OBJECTS_EXPANDER;
extern Symbol* SYM_MACROS_IGNORE;
extern Symbol* SYM_MACROS_IGNORE_EXPANDER;
extern Symbol* SYM_MACROS_CHOOSE;
extern Symbol* SYM_MACROS_NULL;
extern Symbol* SYM_MACROS_ONLY_IF;
extern Symbol* SYM_MACROS_ONLY_IF_EXPANDER;
extern Symbol* SYM_MACROS_PHASE_TO_INTEGER;
extern Symbol* SYM_MACROS_PHASE_TO_INTEGER_EXPANDER;
extern Symbol* SYM_MACROS_IF_OUTPUT_LANGUAGE;
extern Symbol* SYM_MACROS_IF_OUTPUT_LANGUAGE_EXPANDER;
extern Symbol* SYM_MACROS_oCONTEXTo;
extern Symbol* SYM_MACROS_SAFETY;
extern Symbol* SYM_MACROS_EQLp;
extern Symbol* SYM_MACROS_BASE_MODULE;
extern Symbol* SYM_MACROS_CAST;
extern Symbol* SYM_MACROS_WORLD;
extern Symbol* SYM_MACROS_oMODULEo;
extern Symbol* SYM_MACROS_WITHIN_WORLD;
extern Symbol* SYM_MACROS_WITHIN_WORLD_EXPANDER;
extern Symbol* SYM_MACROS_LET;
extern Symbol* SYM_MACROS_WITHIN_MODULE;
extern Symbol* SYM_MACROS_WITHIN_MODULE_EXPANDER;
extern Symbol* SYM_MACROS_IN;
extern Symbol* SYM_MACROS_AS;
extern Symbol* SYM_MACROS_COMMA;

