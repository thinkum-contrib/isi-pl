// cl-translate.hh

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
Symbol* destructure_call_tree(Cons* tree, Surrogate*& return1, Cons*& return2);
boolean use_cl_structsP();
boolean use_vector_structsP();
Cons* cl_translate_list_of_trees(Cons* trees);
Cons* cl_translate_void_sys(Cons* tree);
Object* cl_translate_typed_sys(Cons* tree);
Object* cl_translate_bad_sys(Cons* tree);
Object* cl_translate_a_tree(Object* tree);
Object* help_cl_translate_a_tree(Object* tree);
Object* cl_translate_global_symbol(Symbol* symbol);
Object* yield_global_lisp_symbol(Module* symbolmodule, char* symbolname);
Cons* cl_translate_setq_tree(Cons* tree);
Object* yield_struct_slot_accessor_name(Surrogate* classtype, Symbol* slotname);
Object* yield_clos_slot_accessor_name(Symbol* slotname);
Cons* yield_slot_value_reader_tree(Symbol* slotname, Object* objectref, Surrogate* objecttype);
Cons* yield_slot_value_writer_tree(Symbol* slotname, Object* objectref, Surrogate* objecttype, Object* valueref);
Symbol* true_slot_name(Symbol* slotname, Surrogate* type);
Cons* cl_translate_fixed_slot_value_tree(Cons* tree);
Cons* cl_translate_fixed_slot_value_setter_tree(Cons* tree);
Cons* cl_translate_call_method_tree(Cons* tree);
Symbol* method_call_type_for_vector_structs(Symbol* slotname, Surrogate* owner, boolean functionP);
Cons* cl_translate_normal_call_method_tree(Symbol* renamed_Operator, Surrogate* owner, Cons* arguments);
Cons* cl_translate_nth_tree(Cons* tree);
boolean duplicate_cursor_variableP(Symbol* variable, Cons* iteratorbindings);
Cons* cl_translate_foreach_tree(Cons* tree);
Cons* maybe_wrap_with_continue_label(Cons* translatedloopbody);
Cons* cl_translate_let_tree(Cons* tree);
Cons* cl_translate_special_tree(Cons* tree);
Cons* cl_translate_startup_time_progn_tree(Cons* tree);
Object* cast(Object* value, Surrogate* type);
Object* cl_translate_cast_tree(Cons* tree);
Cons* cl_translate_return_tree(Cons* tree);
Cons* cl_translate_boolean_test(Object* tree, boolean invertP);
Cons* cl_translate_plain_boolean_test(Object* tree, boolean invertP);
Cons* cl_translate_while_tree(Cons* tree);
Cons* cl_translate_conditional_tree(Cons* tree);
Cons* cl_translate_cond_tree(Cons* tree);
Cons* cl_translate_case_tree(Cons* tree);
Cons* cl_translate_boolean_tree(Cons* tree);
Symbol* class_to_native_symbol(Class* renamed_Class);
Object* yield_struct_constructor_name(Class* renamed_Class);
Cons* cl_translate_make_tree(Cons* tree);
Cons* cl_translate_new_tree(Cons* tree);
Cons* cl_translate_operator_tree(Cons* tree);
Cons* yield_format_arguments(Cons* tree);
Cons* yield_print_tree(Cons* tree);
Cons* cl_translate_print_stream_tree(Cons* tree);
Cons* cl_translate_call_function_code_tree(Cons* tree);
Cons* cl_translate_the_code_tree(Cons* tree);
Object* cl_translate_verbatim_tree(Cons* tree);
Cons* cl_translate_inline_tree(Cons* tree);
Object* cl_translate_unit(Translation_Unit* unit);
Cons* cl_translate_method_parameters(Method_Slot* method);
Cons* cl_translate_define_method_unit(Translation_Unit* unit);
Cons* yield_clos_slot_tree(Storage_Slot* slot);
Cons* yield_clos_class_tree(Class* renamed_Class);
List* compute_cl_struct_slots(Class* renamed_Class);
List* cl_struct_slots(Class* renamed_Class);
int cl_struct_slot_offset(Symbol* slotname, Surrogate* classtype);
Cons* yield_struct_slot_trees(Class* renamed_Class);
Cons* yield_struct_tree(Class* renamed_Class);
Object* yield_vector_struct_name(Class* renamed_Class);
Cons* yield_vector_struct_tree(Class* renamed_Class);
Cons* cl_translate_define_native_class_unit(Translation_Unit* unit);
Cons* cl_translate_define_global_variable_unit(Translation_Unit* unit);
Cons* cl_translate_defprint_unit(Translation_Unit* unit);
void startup_cl_translate();

// Global declarations:
extern Symbol* SYM_CL_TRANSLATE_SYS_CALL_FUNCTION;
extern Symbol* SYM_CL_TRANSLATE_SYS_CALL_METHOD;
extern Key_Value_List* oCL_OPERATOR_TABLEo;
extern Surrogate* SGT_CL_TRANSLATE_KEY_VALUE_LIST;
extern Symbol* SYM_CL_TRANSLATE_i;
extern Symbol* SYM_CL_TRANSLATE__;
extern Symbol* SYM_CL_TRANSLATE_o;
extern Symbol* SYM_CL_TRANSLATE_s;
extern Symbol* SYM_CL_TRANSLATE_EQp;
extern Symbol* SYM_CL_TRANSLATE_l;
extern Symbol* SYM_CL_TRANSLATE_le;
extern Symbol* SYM_CL_TRANSLATE_ge;
extern Symbol* SYM_CL_TRANSLATE_g;
extern Symbol* SYM_CL_TRANSLATE_e;
extern Symbol* SYM_CL_TRANSLATE_xse;
extern Keyword* KWD_CL_TRANSLATE_USE_COMMON_LISP_STRUCTS;
extern Keyword* KWD_CL_TRANSLATE_USE_COMMON_LISP_VECTOR_STRUCTS;
extern Surrogate* SGT_CL_TRANSLATE_VOID;
extern Symbol* SYM_CL_TRANSLATE_VOID_SYS;
extern Symbol* SYM_CL_TRANSLATE_TYPED_SYS;
extern Symbol* SYM_CL_TRANSLATE_BAD_SYS;
extern Symbol* SYM_CL_TRANSLATE_SETQ;
extern Symbol* SYM_CL_TRANSLATE_SYS_SLOT_VALUE;
extern Symbol* SYM_CL_TRANSLATE_SYS_SLOT_VALUE_SETTER;
extern Symbol* SYM_CL_TRANSLATE_PROGN;
extern Symbol* SYM_CL_TRANSLATE_LOOP;
extern Symbol* SYM_CL_TRANSLATE_SYS_FOREACH;
extern Symbol* SYM_CL_TRANSLATE_LET;
extern Symbol* SYM_CL_TRANSLATE_STARTUP_TIME_PROGN;
extern Symbol* SYM_CL_TRANSLATE_SPECIAL;
extern Symbol* SYM_CL_TRANSLATE_CAST;
extern Symbol* SYM_CL_TRANSLATE_SAFE_CAST;
extern Symbol* SYM_CL_TRANSLATE_RETURN;
extern Symbol* SYM_CL_TRANSLATE_BREAK;
extern Symbol* SYM_CL_TRANSLATE_CONTINUE;
extern Symbol* SYM_CL_TRANSLATE_WHILE;
extern Symbol* SYM_CL_TRANSLATE_IF;
extern Symbol* SYM_CL_TRANSLATE_CHOOSE;
extern Symbol* SYM_CL_TRANSLATE_WHEN;
extern Symbol* SYM_CL_TRANSLATE_UNLESS;
extern Symbol* SYM_CL_TRANSLATE_AND;
extern Symbol* SYM_CL_TRANSLATE_OR;
extern Symbol* SYM_CL_TRANSLATE_NOT;
extern Symbol* SYM_CL_TRANSLATE_COND;
extern Symbol* SYM_CL_TRANSLATE_CASE;
extern Symbol* SYM_CL_TRANSLATE_MAKE;
extern Symbol* SYM_CL_TRANSLATE_SYS_NEW;
extern Symbol* SYM_CL_TRANSLATE_MV_SETQ;
extern Symbol* SYM_CL_TRANSLATE_QUOTE;
extern Symbol* SYM_CL_TRANSLATE_SYS_CALL_FUNCTION_CODE;
extern Symbol* SYM_CL_TRANSLATE_SYS_CALL_METHOD_CODE;
extern Symbol* SYM_CL_TRANSLATE_THE_CODE;
extern Symbol* SYM_CL_TRANSLATE_PRINT_STREAM;
extern Symbol* SYM_CL_TRANSLATE_PRINT_NATIVE_STREAM;
extern Symbol* SYM_CL_TRANSLATE_VERBATIM;
extern Symbol* SYM_CL_TRANSLATE_INLINE;
extern Symbol* SYM_CL_TRANSLATE_IGNORE;
extern Keyword* KWD_CL_TRANSLATE_CONTINUE;
extern Symbol* SYM_CL_TRANSLATE_GET_KWD;
extern Symbol* SYM_CL_TRANSLATE_GET_SGT;
extern Symbol* SYM_CL_TRANSLATE_CLSYS_SVAL;
extern Symbol* SYM_CL_TRANSLATE_NTH;
extern Symbol* SYM_CL_TRANSLATE_NTH_SETTER;
extern Symbol* SYM_CL_TRANSLATE_NULLp;
extern Symbol* SYM_CL_TRANSLATE_DEFINEDp;
extern Symbol* SYM_CL_TRANSLATE_NORMAL_CALL;
extern Surrogate* SGT_CL_TRANSLATE_OBJECT;
extern Symbol* SYM_CL_TRANSLATE_NON_OBJECT_METHOD;
extern Symbol* SYM_CL_TRANSLATE_PRINT_OBJECT;
extern Symbol* SYM_CL_TRANSLATE_OBJECT_METHOD;
extern Keyword* KWD_CL_TRANSLATE_COMMON_LISP;
extern Keyword* KWD_CL_TRANSLATE_FUNCTION;
extern Symbol* SYM_CL_TRANSLATE_CLSYS_CALL;
extern Symbol* SYM_CL_TRANSLATE_NULL;
extern Surrogate* SGT_CL_TRANSLATE_STRING;
extern Surrogate* SGT_CL_TRANSLATE_VECTOR;
extern Symbol* SYM_CL_TRANSLATE_THE_ARRAY;
extern Symbol* SYM_CL_TRANSLATE_DO;
extern Symbol* SYM_CL_TRANSLATE_EVAL_WHEN;
extern Symbol* SYM_CL_TRANSLATE_PRIMARY_TYPE;
extern Symbol* SYM_CL_TRANSLATE_NILp;
extern Symbol* SYM_CL_TRANSLATE_EMPTYp;
extern Symbol* SYM_CL_TRANSLATE_NON_EMPTYp;
extern Surrogate* SGT_CL_TRANSLATE_LITERAL;
extern Surrogate* SGT_CL_TRANSLATE_NUMBER;
extern Surrogate* SGT_CL_TRANSLATE_BOOLEAN;
extern Surrogate* SGT_CL_TRANSLATE_CODE;
extern Surrogate* SGT_CL_TRANSLATE_CONS;
extern Symbol* SYM_CL_TRANSLATE_NIL;
extern Symbol* SYM_CL_TRANSLATE_OTHERWISE;
extern Symbol* SYM_CL_TRANSLATE_TRUE;
extern Symbol* SYM_CL_TRANSLATE_FALSE;
extern Symbol* SYM_CL_TRANSLATE_CLASS_CL_NATIVE_TYPE;
extern Symbol* SYM_CL_TRANSLATE_CLSYS_MAKE;
extern Symbol* SYM_CL_TRANSLATE_rrSTREAM;
extern Keyword* KWD_CL_TRANSLATE_WARN;
extern Keyword* KWD_CL_TRANSLATE_ERROR;
extern Keyword* KWD_CL_TRANSLATE_CONTINUABLE_ERROR;
extern Symbol* SYM_CL_TRANSLATE_GLOBAL_VARIABLE;
extern Symbol* SYM_CL_TRANSLATE_CLASS;
extern Symbol* SYM_CL_TRANSLATE_METHOD;
extern Symbol* SYM_CL_TRANSLATE_MACRO;
extern Symbol* SYM_CL_TRANSLATE_PRINT_METHOD;
extern Symbol* SYM_CL_TRANSLATE_TYPE;
extern Symbol* SYM_CL_TRANSLATE_CLSYS_SELF;
extern Symbol* SYM_CL_TRANSLATE_CLSYS_DUMMY;
extern Symbol* SYM_CL_TRANSLATE_DOCUMENTATION;
extern Symbol* SYM_CL_TRANSLATE_SELF;
extern Symbol* SYM_CL_TRANSLATE_oCLSYS_SELFo;
extern Keyword* KWD_CL_TRANSLATE_VOID;
extern Keyword* KWD_CL_TRANSLATE_EMBEDDED;
extern Keyword* KWD_CL_TRANSLATE_INSTANCE;
extern Keyword* KWD_CL_TRANSLATE_ALLOCATION;
extern Keyword* KWD_CL_TRANSLATE_DOCUMENTATION;
extern Keyword* KWD_CL_TRANSLATE_ACCESSOR;
extern Symbol* SYM_CL_TRANSLATE_CLASS_CL_STRUCT_SLOTS;
extern Keyword* KWD_CL_TRANSLATE_CONC_NAME;
extern Keyword* KWD_CL_TRANSLATE_CONSTRUCTOR;
extern Keyword* KWD_CL_TRANSLATE_INCLUDE;
extern Keyword* KWD_CL_TRANSLATE_UNBOUND_SPECIAL_VARIABLE;
extern Symbol* SYM_CL_TRANSLATE_STREAM;

