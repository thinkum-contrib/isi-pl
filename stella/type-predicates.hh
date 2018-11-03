// type-predicates.hh

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
boolean bootstrap_isaP(Object* x, Surrogate* type);
boolean booleanP(Object* x);
boolean integerP(Object* x);
boolean floatP(Object* x);
boolean stringP(Object* x);
boolean verbatim_stringP(Object* x);
boolean characterP(Object* x);
boolean wrapperP(Object* x);
boolean surrogateP(Object* x);
boolean typeP(Object* x);
boolean symbolP(Object* x);
boolean transient_symbolP(Object* x);
boolean keywordP(Object* x);
boolean consP(Object* x);
boolean classP(Object* x);
boolean storage_slotP(Object* x);
boolean method_slotP(Object* x);
boolean anchored_type_specifierP(Object* x);
boolean parametric_type_specifierP(Object* x);
void startup_type_predicates();

// Global declarations:
extern boolean oCLASS_HIERARCHY_BOOTEDpo;
extern Surrogate* SGT_TYPE_PREDICATES_BOOLEAN_WRAPPER;
extern Surrogate* SGT_TYPE_PREDICATES_INTEGER_WRAPPER;
extern Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_INTEGER_WRAPPER;
extern Surrogate* SGT_TYPE_PREDICATES_FLOAT_WRAPPER;
extern Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_FLOAT_WRAPPER;
extern Surrogate* SGT_TYPE_PREDICATES_STRING_WRAPPER;
extern Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_STRING_WRAPPER;
extern Surrogate* SGT_TYPE_PREDICATES_VERBATIM_STRING_WRAPPER;
extern Surrogate* SGT_TYPE_PREDICATES_CHARACTER_WRAPPER;
extern Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_CHARACTER_WRAPPER;
extern Surrogate* SGT_TYPE_PREDICATES_WRAPPER;
extern Surrogate* SGT_TYPE_PREDICATES_SURROGATE;
extern Surrogate* SGT_TYPE_PREDICATES_SYMBOL;
extern Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_SYMBOL;
extern Surrogate* SGT_TYPE_PREDICATES_KEYWORD;
extern Surrogate* SGT_TYPE_PREDICATES_CONS;
extern Surrogate* SGT_TYPE_PREDICATES_TRANSIENT_CONS;
extern Surrogate* SGT_TYPE_PREDICATES_CLASS;
extern Surrogate* SGT_TYPE_PREDICATES_STORAGE_SLOT;
extern Surrogate* SGT_TYPE_PREDICATES_METHOD_SLOT;
extern Surrogate* SGT_TYPE_PREDICATES_ANCHORED_TYPE_SPECIFIER;
extern Surrogate* SGT_TYPE_PREDICATES_PARAMETRIC_TYPE_SPECIFIER;

