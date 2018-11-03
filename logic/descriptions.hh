// descriptions.hh

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | 
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
Description* create_description(int arity, Keyword* kind);
Description* create_description_for_relation(Relation* self);
Description* string_get_description(char* self);
Surrogate* description_owner_type(Description* description);
Surrogate* logic_objectDmember_type_from_collection(Logic_Object* self);
Surrogate* descriptionDmember_type_from_collection(Description* self);
Surrogate* member_type_from_collection(Object* self);
Symbol* description_name(Description* self);
Cons* read_OlogicvariabletableO();
Cons* write_OlogicvariabletableO(Cons* value);
void push_logic_variable_binding(Skolem* variable);
void pop_logic_variable_binding();
void pop_logic_variable_bindings(Cons* variables);
Object* lookup_logic_variable_binding(Symbol* variablename);
Cons* parse_logic_variable_declarations(Cons* tree, Keyword* updatemode, boolean variableP);
Vector* copy_cons_list_to_variables_vector(Cons* conslist);
Cons* build_quantified_proposition(Cons* tree, Keyword* updatemode, Proposition*& return1, Proposition*& return2);
boolean contains_nested_argumentP(Proposition* atomicproposition);
void help_collect_flattened_arguments(Proposition* self, List* flattenedarguments, List* beenthere);
List* yield_flattened_arguments(Proposition* proposition);
Proposition* flatten_nested_function_arguments(Proposition* proposition);
void collapse_value_of_chains(Description* description);
void tighten_argument_bindings(Proposition* proposition);
void collect_all_variables(Proposition* self, List* collection, List* beenthere);
void compute_internal_variables(Description* self);
void equate_top_level_equivalences(Proposition* proposition);
Description* finish_building_description(Description* description, boolean checkforduplicateP);
Description* evaluate_description_term(Cons* term, boolean checkforduplicateP);
Description* create_top_level_description(Cons* tree, Keyword* kind, Relation* relation);
void augment_top_level_description(Description* self, Cons* tree);
Description* create_top_level_collection(Cons* tree, Class* renamed_Class);
Cons* extract_variable_type_propositions(Proposition* proposition);
Description* get_complement_description(Description* self);
Description* parse_logical_definition(char* definition, Relation* relation);
void inherit_type_onto_description(Description* description, Surrogate* type);
void inherit_slot_onto_description(Description* description, Slot* slot);
void preclassify_description(Description* description);
Proposition* conjoin_two_propositions(Proposition* prop1, Proposition* prop2);
void delete_proposition(Proposition* self);
void startup_descriptions();

// Global declarations:
extern Vector* FAKE_IO_VARIABLES;
extern Cons* SYSTEM_DEFINED_ARGUMENT_NAMES;
extern Symbol* SYM_DESCRIPTIONS_pX1;
extern Symbol* SYM_DESCRIPTIONS_pX2;
extern Symbol* SYM_DESCRIPTIONS_pX3;
extern Symbol* SYM_DESCRIPTIONS_pX4;
extern Symbol* SYM_DESCRIPTIONS_pX5;
extern Symbol* SYM_DESCRIPTIONS_pX6;
extern Symbol* SYM_DESCRIPTIONS_pX7;
extern Symbol* SYM_DESCRIPTIONS_pX8;
extern Symbol* SYM_DESCRIPTIONS_pX9;
extern Symbol* SYM_DESCRIPTIONS_pX10;
extern Symbol* SYM_DESCRIPTIONS_pX11;
extern Symbol* SYM_DESCRIPTIONS_pX12;
extern Symbol* SYM_DESCRIPTIONS_pX13;
extern Symbol* SYM_DESCRIPTIONS_pX14;
extern Symbol* SYM_DESCRIPTIONS_pX15;
extern Symbol* SYM_DESCRIPTIONS_pX16;
extern Symbol* SYM_DESCRIPTIONS_pX17;
extern Symbol* SYM_DESCRIPTIONS_pX18;
extern Symbol* SYM_DESCRIPTIONS_pX19;
extern Symbol* SYM_DESCRIPTIONS_pX20;
extern Symbol* SYM_DESCRIPTIONS_SETOFALL;
extern Symbol* SYM_DESCRIPTIONS_ISA;
extern Symbol* SYM_DESCRIPTIONS_pX;
extern Surrogate* SGT_DESCRIPTIONS_SLOT;
extern Surrogate* SGT_DESCRIPTIONS_BOOLEAN;
extern Surrogate* SGT_DESCRIPTIONS_TABLE;
extern Symbol* SYM_DESCRIPTIONS_KAPPA;
extern Symbol* SYM_DESCRIPTIONS_COMMA;
extern Symbol* SYM_DESCRIPTIONS_WHERE;
extern Surrogate* SGT_DESCRIPTIONS_COLLECTION;
extern Symbol* SYM_DESCRIPTIONS_IN;
extern Symbol* SYM_DESCRIPTIONS_e;
extern Keyword* KWD_DESCRIPTIONS_PREFIX_STELLA;
extern Keyword* KWD_DESCRIPTIONS_PRIMITIVE;
extern Symbol* SYM_DESCRIPTIONS_DESCRIPTION;
extern Surrogate* SGT_DESCRIPTIONS_DESCRIPTION;
extern Surrogate* SGT_DESCRIPTIONS_RELATION;
extern Symbol* SYM_DESCRIPTIONS_DEFINITION_STRING;
extern Symbol* SYM_DESCRIPTIONS_DEFINITION;
extern Surrogate* SGT_DESCRIPTIONS_LOGIC_OBJECT;
extern Symbol* SYM_DESCRIPTIONS_ANY_VALUE;
extern Surrogate* SGT_DESCRIPTIONS_ITERATOR;
extern Cons* oLOGICVARIABLETABLEo;
extern Symbol* SYM_DESCRIPTIONS_oLOGICVARIABLETABLEo;
extern Symbol* SYM_DESCRIPTIONS_SKOLEM_NAME;
extern Symbol* SYM_DESCRIPTIONS_VARIABLE_TYPEp;
extern Keyword* KWD_DESCRIPTIONS_CONCEIVE;
extern Keyword* KWD_DESCRIPTIONS_FUNCTION;
extern Keyword* KWD_DESCRIPTIONS_PREDICATE;
extern Keyword* KWD_DESCRIPTIONS_IN;
extern Keyword* KWD_DESCRIPTIONS_EQUIVALENT;
extern Surrogate* SGT_DESCRIPTIONS_PATTERN_VARIABLE;
extern Symbol* SYM_DESCRIPTIONS_EXISTS;
extern Symbol* SYM_DESCRIPTIONS_AND;
extern Symbol* SYM_DESCRIPTIONS_IO_VARIABLES;
extern Surrogate* SGT_DESCRIPTIONS_SKOLEM;
extern Surrogate* SGT_DESCRIPTIONS_PROPOSITION;
extern Keyword* KWD_DESCRIPTIONS_EQUIVALENCE;
extern Keyword* KWD_DESCRIPTIONS_AND;
extern Keyword* KWD_DESCRIPTIONS_EXISTS;
extern Keyword* KWD_DESCRIPTIONS_DEFINITION;
extern Keyword* KWD_DESCRIPTIONS_QUERY;
extern Symbol* SYM_DESCRIPTIONS_THE_ONLY;
extern Symbol* SYM_DESCRIPTIONS_IOTAp;
extern Keyword* KWD_DESCRIPTIONS_DESCRIPTION;
extern Surrogate* SGT_DESCRIPTIONS_PROPOSITION_ERROR;
extern Keyword* KWD_DESCRIPTIONS_ASSERT_TRUE;
extern Keyword* KWD_DESCRIPTIONS_ENUMERATION;
extern Keyword* KWD_DESCRIPTIONS_RETRACT_TRUE;
extern Surrogate* SGT_DESCRIPTIONS_UNKNOWN;
extern Symbol* SYM_DESCRIPTIONS_EXTENSION;
extern Symbol* SYM_DESCRIPTIONS_CLOSED;
extern Symbol* SYM_DESCRIPTIONS_LISTOF;
extern Symbol* SYM_DESCRIPTIONS_SETOF;
extern Symbol* SYM_DESCRIPTIONS_ORDERED;
extern Symbol* SYM_DESCRIPTIONS_DUPLICATE_FREE;
extern Symbol* SYM_DESCRIPTIONS_COMPLEMENT_DESCRIPTION;

