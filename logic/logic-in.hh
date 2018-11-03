// logic-in.hh

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
void print_features();
void set_powerloom_feature(Keyword* feature);
List* set_feature(Cons* features);
List* set_feature_evaluator_wrapper(Cons* arguments);
void unset_powerloom_feature(Keyword* feature);
List* unset_feature(Cons* features);
List* unset_feature_evaluator_wrapper(Cons* arguments);
List* reset_features();
void print_logic_prompt();
void print_logic_command_result(Object* result, Standard_Object* resulttype);
boolean read_Ocareful_logic_command_loop_exitOP();
boolean write_Ocareful_logic_command_loop_exitOP(boolean value);
boolean logic_command_loop_exitP(Object* command, boolean& return1);
void logic_command_loop();
Object* evaluate_logic_command(Object* command, boolean finalizeP, Standard_Object*& return1, boolean& return2);
void load(char* file);
void load_evaluator_wrapper(Cons* arguments);
int read_Odemo_levelO();
int write_Odemo_levelO(int value);
void print_demo_prompt();
boolean demo_skip_to_command(Input_Stream* stream);
boolean demo_pauseP(boolean pauseP, boolean& return1);
void demo_file(char* file, boolean pauseP);
char* select_example_demo(int index);
char* select_example_demo_from_menu();
void demo_example_demos();
void demo(Cons* fileandpause);
void demo_evaluator_wrapper(Cons* arguments);
void test_logic_file(char* file);
void run_powerloom_tests();
Symbol* default_self_variable(Relation* self);
Symbol* default_value_variable(Relation* self);
Relation* help_define_relation_from_parse_tree(Cons* tree, char* stringifiedsource);
List* parse_relation_parameters_tree(Cons* parameters, List*& return1, boolean& return2);
Relation* get_identical_relation(Symbol* name, Surrogate* owner, boolean polymorphicP, char* stringifiedsource);
void relation_full_definition_handler(Relation* self, Storage_Slot* slot, Object* definition);
void relation_sentence_definition_handler(Relation* self, Storage_Slot* slot, Object* definition);
void relation_term_definition_handler(Relation* self, Storage_Slot* slot, Object* definition);
Cons* yield_relation_parameters_tree(Relation* self, boolean typedP);
Object* complete_sentence_definition(Relation* self, Object* definition);
Object* complete_term_definition(Slot* self, Object* definition);
void relation_axioms_handler(Relation* self, Storage_Slot* slot, Object* axioms);
Object* add_relation_axioms(Relation* self, Object* oldaxioms, Object* newaxioms);
void relation_constraints_handler(Relation* self, Storage_Slot* slot, Object* constraints);
Object* complete_constraint_definition(Relation* self, Object* definition);
void remember_unfinalized_relation(Relation* self);
void finalize_defined_relation(Relation* self);
boolean finalized_relationP(Relation* self);
void finalize_relations();
Relation* define_relation_from_parse_tree(Cons* tree);
Relation* deffunction(Cons* args);
Relation* deffunction_evaluator_wrapper(Cons* arguments);
Relation* defrelation(Cons* args);
Relation* defrelation_evaluator_wrapper(Cons* arguments);
Class* defconcept(Cons* args);
Class* defconcept_evaluator_wrapper(Cons* arguments);
boolean commandL(Method_Slot* command1, Method_Slot* command2);
List* list_logic_commands();
void help(Cons* commands);
void help_evaluator_wrapper(Cons* arguments);
void startup_logic_in();

// Global declarations:
extern List* oAVAILABLE_POWERLOOM_FEATURESo;
extern Keyword* KWD_LOGIC_IN_GOAL_TRACE;
extern Keyword* KWD_LOGIC_IN_CLOSED_WORLD;
extern List* oCURRENT_POWERLOOM_FEATURESo;
extern List* oDEFAULT_POWERLOOM_FEATURESo;
extern Keyword* KWD_LOGIC_IN_GOAL_TREE;
extern Surrogate* SGT_LOGIC_IN_LOGIC_EXCEPTION;
extern Symbol* SYM_LOGIC_IN_EVALUATOR_WRAPPER_CODE;
extern char* oLOGIC_PROMPTo;
extern char* oLOGIC_COMMAND_RESULT_INDENTo;
extern Keyword* KWD_LOGIC_IN_REALISTIC;
extern boolean oCAREFUL_LOGIC_COMMAND_LOOP_EXITop;
extern Symbol* SYM_LOGIC_IN_oCAREFUL_LOGIC_COMMAND_LOOP_EXITop;
extern Keyword* KWD_LOGIC_IN_BYE;
extern Keyword* KWD_LOGIC_IN_EXIT;
extern Keyword* KWD_LOGIC_IN_HALT;
extern Keyword* KWD_LOGIC_IN_QUIT;
extern Keyword* KWD_LOGIC_IN_STOP;
extern Symbol* SYM_LOGIC_IN_BYE;
extern Symbol* SYM_LOGIC_IN_EXIT;
extern Symbol* SYM_LOGIC_IN_HALT;
extern Symbol* SYM_LOGIC_IN_QUIT;
extern Symbol* SYM_LOGIC_IN_STOP;
extern Surrogate* SGT_LOGIC_IN_READ_EXCEPTION;
extern Keyword* KWD_LOGIC_IN_DEFINE;
extern Symbol* SYM_LOGIC_IN_DEFCLASS;
extern Symbol* SYM_LOGIC_IN_DEFSLOT;
extern Symbol* SYM_LOGIC_IN_DEFUN;
extern Symbol* SYM_LOGIC_IN_DEFMETHOD;
extern Symbol* SYM_LOGIC_IN_DEFMODULE;
extern Symbol* SYM_LOGIC_IN_IN_MODULE;
extern Surrogate* SGT_LOGIC_IN_CLASS;
extern Surrogate* SGT_LOGIC_IN_STORAGE_SLOT;
extern Surrogate* SGT_LOGIC_IN_METHOD_SLOT;
extern Surrogate* SGT_LOGIC_IN_MODULE;
extern Surrogate* SGT_LOGIC_IN_VOID;
extern Surrogate* SGT_LOGIC_IN_CONS;
extern Keyword* KWD_LOGIC_IN_FINALIZE;
extern Symbol* SYM_LOGIC_IN_CLEAR_MODULE;
extern Symbol* SYM_LOGIC_IN_IN_DIALECT;
extern int oDEMO_LEVELo;
extern Symbol* SYM_LOGIC_IN_oDEMO_LEVELo;
extern char* oDEMO_FILE_DIRECTORYo;
extern char* oDEMO_FILE_SUFFIXo;
extern Cons* oDEMO_FILESo;
extern Symbol* SYM_LOGIC_IN_FALSE;
extern Symbol* SYM_LOGIC_IN_SORTp;
extern Symbol* SYM_LOGIC_IN_RELATION_PARAMETER_NAMES;
extern Keyword* KWD_LOGIC_IN_KIF;
extern Symbol* SYM_LOGIC_IN_pSELF;
extern Symbol* SYM_LOGIC_IN_SELF;
extern Symbol* SYM_LOGIC_IN_SELF_VARIABLE;
extern Symbol* SYM_LOGIC_IN_pVALUE;
extern Symbol* SYM_LOGIC_IN_VALUE;
extern Symbol* SYM_LOGIC_IN_VALUE_VARIABLE;
extern Symbol* SYM_LOGIC_IN_DEFFUNCTION;
extern Surrogate* SGT_LOGIC_IN_UNKNOWN;
extern Keyword* KWD_LOGIC_IN_POLYMORPHICp;
extern Keyword* KWD_LOGIC_IN_TYPE;
extern Surrogate* SGT_LOGIC_IN_BOOLEAN;
extern Symbol* SYM_LOGIC_IN_BOOLEAN;
extern Keyword* KWD_LOGIC_IN_ABSTRACTp;
extern Symbol* SYM_LOGIC_IN_TRUE;
extern Keyword* KWD_LOGIC_IN_SELF_VARIABLE;
extern Symbol* SYM_LOGIC_IN_VARIABLE_ARITYp;
extern Symbol* SYM_LOGIC_IN_SLOT_TYPE_SPECIFIER;
extern Keyword* KWD_LOGIC_IN_DOCUMENTATION;
extern Symbol* SYM_LOGIC_IN_DOCUMENTATION;
extern Keyword* KWD_LOGIC_IN_SINGLE_VALUEDp;
extern Keyword* KWD_LOGIC_IN_PROPERTIES;
extern Symbol* SYM_LOGIC_IN_PROPERTIES;
extern Keyword* KWD_LOGIC_IN_META_ATTRIBUTES;
extern Symbol* SYM_LOGIC_IN_META_ATTRIBUTES;
extern Symbol* SYM_LOGIC_IN_RELATION_STRINGIFIED_SOURCE;
extern Symbol* SYM_LOGIC_IN_aREST;
extern Symbol* SYM_LOGIC_IN_ARGUMENT_LIST;
extern Symbol* SYM_LOGIC_IN_OF;
extern Symbol* SYM_LOGIC_IN_RELATION_ORIGINATED_PROPOSITIONS;
extern Surrogate* SGT_LOGIC_IN_BOOLEAN_WRAPPER;
extern Symbol* SYM_LOGIC_IN_DEFINITION_STRING;
extern Symbol* SYM_LOGIC_IN_SLOT_OPTION_KEYWORD;
extern Surrogate* SGT_LOGIC_IN_TABLE;
extern Symbol* SYM_LOGIC_IN_UNKNOWN;
extern Symbol* SYM_LOGIC_IN_AND;
extern Symbol* SYM_LOGIC_IN_SETOFALL;
extern Symbol* SYM_LOGIC_IN_KAPPA;
extern Symbol* SYM_LOGIC_IN_e;
extern Symbol* SYM_LOGIC_IN_AXIOMS_STRING;
extern Surrogate* SGT_LOGIC_IN_SLOT;
extern Symbol* SYM_LOGIC_IN_FORALL;
extern Symbol* SYM_LOGIC_IN_eg;
extern List* oUNFINALIZED_DEFINED_RELATIONSo;
extern Symbol* SYM_LOGIC_IN_BADp;
extern Keyword* KWD_LOGIC_IN_ASSERT_TRUE;
extern Symbol* SYM_LOGIC_IN_DEFINITION;
extern Symbol* SYM_LOGIC_IN_DESCRIPTION;
extern Keyword* KWD_LOGIC_IN_ENUMERATION;
extern Symbol* SYM_LOGIC_IN_DEFRELATION;
extern Cons* oLOGIC_RELEVANT_STELLA_COMMANDSo;
extern Symbol* SYM_LOGIC_IN_CC;

