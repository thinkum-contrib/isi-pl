// defclass.hh

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
Object* type_to_null_value_tree(Surrogate* type);
Cons* yield_cons_list_from_sequence(Sequence* sequence);
Cons* yield_define_stella_class(Class* renamed_Class);
boolean create_native_classP(Class* renamed_Class);
void warn_about_multiple_parents(Class* renamed_Class);
void warn_about_non_direct_supers(Class* renamed_Class);
boolean space_saver_slot_allocationP(Storage_Slot* slot);
boolean redundant_slotP(Storage_Slot* slot);
boolean native_slotP(Storage_Slot* slot);
Storage_Slot* canonical_slot(Storage_Slot* slot);
boolean unknown_typeP(Surrogate* type);
boolean slot_has_unknown_typeP(Storage_Slot* slot, Class* renamed_Class);
Class* native_slot_home(Storage_Slot* slot, Class* renamed_Class);
Class* mixin_slot_home(Storage_Slot* slot, Class* renamed_Class);
void sweep_transients();
Symbol* yield_recycle_list_name(Class* renamed_Class);
Symbol* yield_sweep_list_name(Class* renamed_Class);
Symbol* yield_sweep_list_pointer_name(Class* renamed_Class);
Storage_Slot* recycle_slot(Class* renamed_Class);
boolean use_free_listP(Class* renamed_Class);
boolean use_sweep_listP(Class* renamed_Class);
boolean decided_to_recycleP(Class* renamed_Class);
List* make_non_recycled_list();
Cons* yield_recycle_list_definitions(Class* renamed_Class);
Cons* yield_make_trees(Class* renamed_Class);
Symbol* yield_constructor_name(Class* renamed_Class);
Cons* yield_creation_trees(Class* renamed_Class);
Cons* yield_terminate_object_trees(Class* renamed_Class);
Cons* yield_creation_or_reuse_trees(Class* renamed_Class);
void mark_direct_equivalent_slot(Slot* slot);
boolean is_context_sensitive_slotP(Storage_Slot* slot);
Cons* yield_initial_value_assignment(Storage_Slot* slot);
Cons* yield_initial_value_assignments(Class* renamed_Class);
Cons* yield_local_initial_value_assignments(Class* renamed_Class);
Cons* yield_constructor_body(Class* renamed_Class, Cons* requiredassignments);
Cons* yield_constructor_definition(Class* renamed_Class);
Cons* yield_destructor_definitions(Class* renamed_Class);
void create_constructor_and_destructor_units(Class* renamed_Class);
boolean parameterized_classP(Class* renamed_Class);
boolean class_with_initializerP(Class* renamed_Class);
Symbol* yield_initializer_name(Class* renamed_Class);
Cons* yield_initializer_definition(Class* renamed_Class);
void create_cpp_constructor_unit(Class* renamed_Class);
boolean cpp_constructorP(Method_Slot* method);
boolean has_non_null_default_valueP(Storage_Slot* slot);
boolean system_defined_slot_readerP(Storage_Slot* slot);
boolean system_defined_slot_writerP(Storage_Slot* slot);
Object* yield_slot_type_tree(Storage_Slot* slot);
Symbol* yield_hardwired_slot_variable(Storage_Slot* slot);
Cons* yield_hardwired_slot_reader_body(Storage_Slot* slot, Cons*& return1);
void finalize_accessor_method(Method_Slot* method);
Cons* wrap_with_default_value_and_return_code(Cons* readcode, Object* defaultexpression);
Cons* yield_slot_reader_tree(Storage_Slot* slot, Class* renamed_Class);
Cons* yield_slot_writer_tree(Storage_Slot* slot, Class* renamed_Class);
boolean slot_value_is_bare_literalP(Slot* slot);
boolean generically_accessible_typeP(Surrogate* type);
boolean generic_slot_readerP(Storage_Slot* slot);
boolean generic_slot_writerP(Storage_Slot* slot);
boolean slot_access_methodP(Storage_Slot* slot);
Symbol* yield_generic_slot_accessor_name(Class* renamed_Class);
Cons* yield_generic_slot_accessor_definition(Class* renamed_Class);
void create_generic_slot_accessor_unit(Class* renamed_Class);
Cons* yield_generic_slot_accessor_attachment(Class* renamed_Class, Symbol* classref);
Cons* yield_mixin_class_users_tree(Class* renamed_Class);
Symbol* yield_mixin_slot_reader_name(Storage_Slot* slot);
Symbol* yield_mixin_slot_writer_name(Storage_Slot* slot);
Cons* yield_mixin_slot_reader_tree(Storage_Slot* slot);
Cons* yield_mixin_slot_writer_tree(Storage_Slot* slot);
Symbol* yield_native_slot_reader_name(Storage_Slot* slot);
Symbol* yield_native_slot_writer_name(Storage_Slot* slot);
Cons* yield_native_slot_reader_tree(Storage_Slot* slot, Class* renamed_Class);
Cons* yield_native_slot_writer_tree(Storage_Slot* slot, Class* renamed_Class);
void create_keyed_equality_method_unit(Class* renamed_Class);
boolean transient_objectP(Object* object);
void startup_defclass();

// Global declarations:
extern Keyword* oTRANSLATOR_OUTPUT_LANGUAGEo;
extern Keyword* KWD_DEFCLASS_COMMON_LISP;
extern Surrogate* SGT_DEFCLASS_LITERAL;
extern Symbol* SYM_DEFCLASS_NULL;
extern Symbol* SYM_DEFCLASS_DEFINE_CLASS_FROM_STRINGIFIED_SOURCE;
extern Symbol* SYM_DEFCLASS_CLASS_CL_NATIVE_TYPE;
extern Keyword* KWD_DEFCLASS_IDL;
extern Symbol* SYM_DEFCLASS_CLASS_IDL_NATIVE_TYPE;
extern Keyword* KWD_DEFCLASS_JAVA;
extern Symbol* SYM_DEFCLASS_CLASS_JAVA_NATIVE_TYPE;
extern Keyword* KWD_DEFCLASS_CPP;
extern Keyword* KWD_DEFCLASS_CPP_STANDALONE;
extern Symbol* SYM_DEFCLASS_CLASS_CPP_NATIVE_TYPE;
extern Surrogate* SGT_DEFCLASS_SECOND_CLASS_OBJECT;
extern Surrogate* SGT_DEFCLASS_NON_OBJECT;
extern Keyword* KWD_DEFCLASS_DYNAMIC;
extern Symbol* SYM_DEFCLASS_SLOT_INITIAL_VALUE;
extern Keyword* KWD_DEFCLASS_BIT;
extern Surrogate* SGT_DEFCLASS_BOOLEAN;
extern Symbol* SYM_DEFCLASS_SLOT_RENAMES;
extern Surrogate* SGT_DEFCLASS_UNKNOWN;
extern Symbol* SYM_DEFCLASS_NEXT_SWEEP_LIST_OBJECT;
extern Symbol* SYM_DEFCLASS_CLASS_CREATOR;
extern Symbol* SYM_DEFCLASS_DEFGLOBAL;
extern Symbol* SYM_DEFCLASS_LIST;
extern Symbol* SYM_DEFCLASS_OF;
extern Symbol* SYM_DEFCLASS_STARTUP_TIME_PROGN;
extern Keyword* KWD_DEFCLASS_EARLY_INITS;
extern Symbol* SYM_DEFCLASS_SETQ;
extern Symbol* SYM_DEFCLASS_MAKE_NON_RECYCLED_LIST;
extern Symbol* SYM_DEFCLASS_SELF;
extern Symbol* SYM_DEFCLASS_MAKE;
extern Symbol* SYM_DEFCLASS_WHEN;
extern Symbol* SYM_DEFCLASS_DEFINEDp;
extern Symbol* SYM_DEFCLASS_FREE;
extern Symbol* SYM_DEFCLASS_DYNAMIC_SLOTS;
extern Symbol* SYM_DEFCLASS_CLEAR;
extern Symbol* SYM_DEFCLASS_UNLESS;
extern Symbol* SYM_DEFCLASS_RETURN;
extern Symbol* SYM_DEFCLASS_SLOT_VALUE;
extern Symbol* SYM_DEFCLASS_SAFE_CAST;
extern Symbol* SYM_DEFCLASS_POP;
extern Symbol* SYM_DEFCLASS_COND;
extern Symbol* SYM_DEFCLASS_OTHERWISE;
extern Symbol* SYM_DEFCLASS_SETF;
extern Keyword* KWD_DEFCLASS_CONTEXT_SENSITIVEp;
extern Symbol* SYM_DEFCLASS_FALSE;
extern Symbol* SYM_DEFCLASS_RUN_CONSTRUCTOR_DEMONS;
extern Symbol* SYM_DEFCLASS_DEFUN;
extern Symbol* SYM_DEFCLASS_LET;
extern Symbol* SYM_DEFCLASS_CLASS_DESTRUCTOR;
extern Symbol* SYM_DEFCLASS_DEFMETHOD;
extern Symbol* SYM_DEFCLASS_PUSH;
extern Symbol* SYM_DEFCLASS_SWEEP;
extern Symbol* SYM_DEFCLASS_UNMAKE;
extern Surrogate* SGT_DEFCLASS_VOID;
extern Symbol* SYM_DEFCLASS_SLOT_TYPE_SPECIFIER;
extern Symbol* SYM_DEFCLASS_ANSWER;
extern Symbol* SYM_DEFCLASS_IF;
extern Symbol* SYM_DEFCLASS_NULLp;
extern Symbol* SYM_DEFCLASS_PROGN;
extern Symbol* SYM_DEFCLASS_ERROR;
extern Keyword* KWD_DEFCLASS_AUXILIARYp;
extern Symbol* SYM_DEFCLASS_TRUE;
extern Symbol* SYM_DEFCLASS_VALUE;
extern Symbol* SYM_DEFCLASS_IGNORE;
extern Surrogate* SGT_DEFCLASS_OBJECT;
extern Keyword* KWD_DEFCLASS_WRAP_FUNCTION;
extern Symbol* SYM_DEFCLASS_CAST;
extern Symbol* SYM_DEFCLASS_SETVALUEp;
extern Surrogate* SGT_DEFCLASS_DYNAMIC_SLOTS_MIXIN;
extern Symbol* SYM_DEFCLASS_SLOTNAME;
extern Symbol* SYM_DEFCLASS_QUOTE;
extern Symbol* SYM_DEFCLASS_CASE;
extern Symbol* SYM_DEFCLASS_HELP_SET_DYNAMIC_SLOT_VALUE;
extern Symbol* SYM_DEFCLASS_LOOKUP;
extern Symbol* SYM_DEFCLASS_OBJECT;
extern Symbol* SYM_DEFCLASS_SYMBOL;
extern Symbol* SYM_DEFCLASS_BOOLEAN;
extern Symbol* SYM_DEFCLASS_CLASS_SLOT_ACCESSOR_CODE;
extern Symbol* SYM_DEFCLASS_THE_CODE;
extern Keyword* KWD_DEFCLASS_FUNCTION;
extern Symbol* SYM_DEFCLASS_TYPECASE;
extern Symbol* SYM_DEFCLASS_EQp;
extern Symbol* SYM_DEFCLASS_OTHER;
extern Symbol* SYM_DEFCLASS_EQUAL;
extern Symbol* SYM_DEFCLASS_AND;
extern Surrogate* SGT_DEFCLASS_TRANSIENT_MIXIN;

