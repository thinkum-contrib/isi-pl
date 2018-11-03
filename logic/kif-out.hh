// kif-out.hh

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
void collect_function_proposition_facts(Proposition* self, List* facts, List* beenthere);
void help_collect_facts(Object* self, List* facts, List* beenthere);
List* all_facts_of_object(Logic_Object* self);
Logic_Object* get_logic_object(char* name);
List* all_facts_of(Object* name);
void retract_facts_of_object(Logic_Object* self);
void retract_facts_of(Object* name);
boolean read_OprettyprintlogicalformsPO();
boolean write_OprettyprintlogicalformsPO(boolean value);
boolean read_OprettyprintkifPO();
boolean write_OprettyprintkifPO(boolean value);
Output_Stream* read_OprintlogicalformstreamO();
Output_Stream* write_OprintlogicalformstreamO(Output_Stream* value);
boolean read_OdowncaseoperatorsPO();
boolean write_OdowncaseoperatorsPO(boolean value);
char* maybe_downcase(char* string);
int read_OindentcounterO();
int write_OindentcounterO(int value);
void increase_indent(int indent);
void decrease_indent(int indent);
void print_indent(Output_Stream* stream, int indent);
void print_logical_form_in_dialect(Object* self, Keyword* dialect, Output_Stream* stream);
void print_logical_form(Object* form, Output_Stream* stream);
void pretty_print_logical_form(Object* form, Output_Stream* stream);
void print_unformatted_logical_form(Object* form, Output_Stream* stream);
void print_as_kif(Object* self);
boolean visible_argumentP(Object* self);
int visible_arguments_count(Vector* arguments);
void print_kif_arguments(Vector* arguments, boolean separatelinesP, boolean omitlastargumentP);
void print_kif_operator_with_arguments(char* renamed_Operator, Vector* arguments, boolean separatelinesP, boolean omitlastargumentP);
char* stringified_kif_operator(Proposition* self);
boolean read_OtoplevelprintkifpropositionPO();
boolean write_OtoplevelprintkifpropositionPO(boolean value);
void print_kif_proposition(Proposition* self);
void help_print_kif_proposition(Proposition* self);
void print_kif_function_proposition(Proposition* self);
void print_kif_function_expression(Proposition* self);
void print_kif_in_proposition(Proposition* self);
void print_kif_implies_proposition(Proposition* self);
void print_kif_quantified_variables(Vector* variables);
void print_kif_quantification(Proposition* self);
void print_kif_top_level_exists_proposition(Proposition* self);
void print_kif_literal_wrapper(Literal_Wrapper* self);
void print_kif_logic_object(Logic_Object* self);
void print_kif_skolem(Skolem* self, boolean suppressdefiningpropositionP);
void print_kif_variable(Pattern_Variable* self);
void print_kif_enumeration(Collection* self);
void print_kif_description(Description* self);
void print_descriptions_as_kif_rule(Description* head, Description* tail);
Hash_Table* read_OexcludedpropositionsO();
Hash_Table* write_OexcludedpropositionsO(Hash_Table* value);
void exclude_relation_originated_propositions();
boolean excluded_propositionP(Proposition* proposition);
boolean enumerated_classP(Object* collection);
void pretty_print_relation_definition(Relation* self, Output_Stream* stream);
void pretty_print_relation_definition_tree(Cons* tree, Output_Stream* stream);
void help_pretty_print_relation_definition_tree(Cons* tree, Output_Stream* stream, int startindent, int keyindent, boolean forcefirstkeyonseparatelineP);
void pretty_print_assertion(Proposition* proposition, Output_Stream* stream);
void pretty_print_named_rule(Surrogate* rulename, Output_Stream* stream);
void do_save_module(Module* module, char* file);
void save_module(Object* name, char* file);
void save_module_evaluator_wrapper(Cons* arguments);
void startup_kif_out();

// Global declarations:
extern Surrogate* SGT_KIF_OUT_LITERAL_WRAPPER;
extern Surrogate* SGT_KIF_OUT_LOGIC_OBJECT;
extern Keyword* KWD_KIF_OUT_FUNCTION;
extern Surrogate* SGT_KIF_OUT_PROPOSITION;
extern Symbol* SYM_KIF_OUT_DESCRIPTION;
extern Surrogate* SGT_KIF_OUT_SLOT;
extern boolean oPRETTYPRINTLOGICALFORMSpo;
extern Symbol* SYM_KIF_OUT_oPRETTYPRINTLOGICALFORMSpo;
extern boolean oPRETTYPRINTKIFpo;
extern Symbol* SYM_KIF_OUT_oPRETTYPRINTKIFpo;
extern Output_Stream* oPRINTLOGICALFORMSTREAMo;
extern Symbol* SYM_KIF_OUT_oPRINTLOGICALFORMSTREAMo;
extern boolean oDOWNCASEOPERATORSpo;
extern Symbol* SYM_KIF_OUT_oDOWNCASEOPERATORSpo;
extern int oINDENTCOUNTERo;
extern Symbol* SYM_KIF_OUT_oINDENTCOUNTERo;
extern int oINDENT_QUANTUMo;
extern Keyword* KWD_KIF_OUT_KIF;
extern Keyword* KWD_KIF_OUT_STELLA;
extern Keyword* KWD_KIF_OUT_PREFIX_STELLA;
extern Keyword* KWD_KIF_OUT_SQL;
extern Surrogate* SGT_KIF_OUT_DESCRIPTION;
extern Surrogate* SGT_KIF_OUT_PATTERN_VARIABLE;
extern Surrogate* SGT_KIF_OUT_SKOLEM;
extern Surrogate* SGT_KIF_OUT_COLLECTION;
extern Keyword* KWD_KIF_OUT_IN;
extern Keyword* KWD_KIF_OUT_REALISTIC;
extern Keyword* KWD_KIF_OUT_ORIGINAL;
extern boolean oTOPLEVELPRINTKIFPROPOSITIONpo;
extern Symbol* SYM_KIF_OUT_oTOPLEVELPRINTKIFPROPOSITIONpo;
extern Keyword* KWD_KIF_OUT_AND;
extern Keyword* KWD_KIF_OUT_OR;
extern Keyword* KWD_KIF_OUT_NOT;
extern Keyword* KWD_KIF_OUT_EQUIVALENT;
extern Keyword* KWD_KIF_OUT_PREDICATE;
extern Keyword* KWD_KIF_OUT_IMPLIES;
extern Keyword* KWD_KIF_OUT_FORALL;
extern Keyword* KWD_KIF_OUT_EXISTS;
extern Keyword* KWD_KIF_OUT_CONSTANT;
extern Keyword* KWD_KIF_OUT_CONTAINED_BY;
extern Keyword* KWD_KIF_OUT_DELETED;
extern Surrogate* SGT_KIF_OUT_TYPE;
extern Symbol* SYM_KIF_OUT_IO_VARIABLES;
extern Symbol* SYM_KIF_OUT_SURROGATE_VALUE_INVERSE;
extern Keyword* KWD_KIF_OUT_ENUMERATION;
extern Surrogate* SGT_KIF_OUT_COLLECTIONdORDERED;
extern Surrogate* SGT_KIF_OUT_COLLECTIONdDUPLICATE_FREE;
extern Vector* FAKE_VARIABLES;
extern Symbol* SYM_KIF_OUT_pX;
extern Symbol* SYM_KIF_OUT_pY;
extern Symbol* SYM_KIF_OUT_pZ;
extern Symbol* SYM_KIF_OUT_SKOLEM_NAME;
extern Key_Value_List* REUSABLE_SKOLEM_MAPPING_TABLE;
extern Hash_Table* oEXCLUDEDPROPOSITIONSo;
extern Symbol* SYM_KIF_OUT_oEXCLUDEDPROPOSITIONSo;
extern Symbol* SYM_KIF_OUT_MASTER_PROPOSITION;
extern Surrogate* SGT_KIF_OUT_COLLECTIONdCLOSED;
extern Symbol* SYM_KIF_OUT_RELATION_STRINGIFIED_SOURCE;
extern Keyword* KWD_KIF_OUT_SLOTS;
extern Keyword* KWD_KIF_OUT_PUBLIC_SLOTS;
extern Keyword* KWD_KIF_OUT_METHODS;
extern Keyword* KWD_KIF_OUT_PUBLIC_METHODS;
extern Symbol* SYM_KIF_OUT_ASSERT;
extern Symbol* SYM_KIF_OUT_DEFRULE;
extern Symbol* SYM_KIF_OUT_EVALUATOR_WRAPPER_CODE;

