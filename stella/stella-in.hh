// stella-in.hh

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
Object* permanentify_form(Object* form);
Object* transientify_form(Object* form);
List* collect_feature_list(Object* tree);
Key_Value_List* collect_key_value_list(Object* tree);
Method_Slot* define_inline_method(Symbol* name, Cons* parametersandbody);
Class* help_define_class_from_parse_tree(Cons* parsetree, char* stringifiedsource);
Storage_Slot* define_storage_slot_from_parse_tree(Cons* slotdef, Surrogate* owner);
Class* get_identical_class(char* classname, char* stringifiedsource);
Class* define_class_from_parse_tree(Cons* parsetree);
Class* define_class_from_stringified_source(char* classname, char* stringifiedsource);
Cons* extract_options(Cons* tree, Key_Value_List* optionstable);
Object* destructure_defmethod_tree(Cons* methodtree, Key_Value_List* optionstable, Cons*& return1, Cons*& return2);
Symbol* yield_setter_method_name(Symbol* methodname);
Symbol* destructure_method_name_tree(Object* nametree, Cons*& return1);
void in_place_normalize_method_options(Keyword_Key_Value_List* methodoptions, Symbol* methodname);
Method_Slot* get_function_with_identical_signature(Symbol* name, char* stringifiedsource);
Method_Slot* get_method_with_identical_signature(Symbol* name, Cons* parameterstree, char* stringifiedsource);
Method_Slot* help_define_method_from_parse_tree(Cons* inputtree, char* stringifiedsource, boolean& return1);
Method_Slot* define_method_from_parse_tree(Cons* parsetree);
char* stringify_method_definition_tree(Cons* parsetree);
Method_Slot* define_method_from_stringified_source(char* methodname, char* classname, char* stringifiedsource);
Storage_Slot* define_external_slot_from_parse_tree(Cons* parsetree);
Storage_Slot* define_external_slot_from_stringified_source(char* stringifiedsource);
Storage_Slot* lookup_slot_from_option_keyword(Surrogate* owner, Keyword* keyword);
Method_Slot* lookup_option_handler(Storage_Slot* slot);
boolean run_option_handlerP(Object* object, Keyword* option, Object* valuetree);
void default_option_handler(Object* self, Storage_Slot* slot, Object* tree);
void startup_stella_in();

// Global declarations:
extern boolean oREDEFINE_IDENTICAL_CLASSESpo;
extern Symbol* SYM_STELLA_IN_TRUE;
extern Symbol* SYM_STELLA_IN_FALSE;
extern Surrogate* SGT_STELLA_IN_GENERALIZED_SYMBOL;
extern Symbol* SYM_STELLA_IN_DEFMETHOD;
extern Keyword* KWD_STELLA_IN_PUBLIC_SLOTS;
extern Keyword* KWD_STELLA_IN_SLOTS;
extern Keyword* KWD_STELLA_IN_PUBLIC_METHODS;
extern Keyword* KWD_STELLA_IN_METHODS;
extern Keyword* KWD_STELLA_IN_PARAMETERS;
extern Keyword* KWD_STELLA_IN_KEY;
extern Keyword* KWD_STELLA_IN_SYNONYMS;
extern Keyword* KWD_STELLA_IN_DOCUMENTATION;
extern Keyword* KWD_STELLA_IN_CL_NATIVE_TYPE;
extern Keyword* KWD_STELLA_IN_CPP_NATIVE_TYPE;
extern Keyword* KWD_STELLA_IN_JAVA_NATIVE_TYPE;
extern Keyword* KWD_STELLA_IN_IDL_NATIVE_TYPE;
extern Keyword* KWD_STELLA_IN_ABSTRACTp;
extern Keyword* KWD_STELLA_IN_ACTIVEp;
extern Keyword* KWD_STELLA_IN_PUBLICp;
extern Keyword* KWD_STELLA_IN_CL_STRUCTp;
extern Keyword* KWD_STELLA_IN_MIXINp;
extern Keyword* KWD_STELLA_IN_RECYCLE_METHOD;
extern Symbol* SYM_STELLA_IN_NEXT_SWEEP_LIST_OBJECT;
extern Keyword* KWD_STELLA_IN_TYPE;
extern Keyword* KWD_STELLA_IN_EXTENSION;
extern Keyword* KWD_STELLA_IN_CREATOR;
extern Keyword* KWD_STELLA_IN_DESTRUCTOR;
extern Keyword* KWD_STELLA_IN_INITIALIZER;
extern Keyword* KWD_STELLA_IN_TERMINATOR;
extern Keyword* KWD_STELLA_IN_EQUALITY_TEST;
extern Keyword* KWD_STELLA_IN_INITIAL_VALUE;
extern Keyword* KWD_STELLA_IN_PRINT_FORM;
extern Keyword* KWD_STELLA_IN_PROPERTIES;
extern Keyword* KWD_STELLA_IN_META_ATTRIBUTES;
extern Keyword* KWD_STELLA_IN_CHILDREN;
extern Keyword* KWD_STELLA_IN_INITIALLY;
extern Keyword* KWD_STELLA_IN_DEFAULT;
extern Symbol* SYM_STELLA_IN_LIKE;
extern Keyword* KWD_STELLA_IN_ALLOCATION;
extern Keyword* KWD_STELLA_IN_READER;
extern Keyword* KWD_STELLA_IN_WRITER;
extern Keyword* KWD_STELLA_IN_INVERSE;
extern Keyword* KWD_STELLA_IN_RENAMES;
extern Keyword* KWD_STELLA_IN_REQUIREDp;
extern Keyword* KWD_STELLA_IN_COMPONENTp;
extern Keyword* KWD_STELLA_IN_READ_ONLYp;
extern Keyword* KWD_STELLA_IN_CONTEXT_SENSITIVEp;
extern Keyword* KWD_STELLA_IN_HARDWIREDp;
extern Keyword* KWD_STELLA_IN_OPTION_KEYWORD;
extern Keyword* KWD_STELLA_IN_OPTION_HANDLER;
extern Symbol* SYM_STELLA_IN_SETTER;
extern Keyword* KWD_STELLA_IN_RETURN_TYPES;
extern Keyword* KWD_STELLA_IN_STORAGE_SLOT;
extern Keyword* KWD_STELLA_IN_INHERITS_THROUGH;
extern Keyword* KWD_STELLA_IN_SETTERp;
extern Keyword* KWD_STELLA_IN_NATIVEp;
extern Keyword* KWD_STELLA_IN_AUXILIARYp;
extern Keyword* KWD_STELLA_IN_GLOBALLY_INLINEp;
extern Keyword* KWD_STELLA_IN_COMMANDp;
extern Keyword* KWD_STELLA_IN_LISP_MACROp;
extern Keyword* KWD_STELLA_IN_EVALUATE_ARGUMENTSp;
extern Keyword* KWD_STELLA_IN_INLINE;
extern Symbol* SYM_STELLA_IN_DEFUN;
extern List* oUNSUPPORTED_EXTERNAL_SLOT_OPTIONSo;
extern Keyword* KWD_STELLA_IN_DYNAMIC;
extern Surrogate* SGT_STELLA_IN_DYNAMIC_SLOTS_MIXIN;
extern Symbol* SYM_STELLA_IN_SLOT_OPTION_KEYWORD;
extern Method_Slot* oDEFAULT_OPTION_HANDLERo;
extern Symbol* SYM_STELLA_IN_DEFAULT_OPTION_HANDLER;
extern Symbol* SYM_STELLA_IN_SLOT_OPTION_HANDLER;
extern Surrogate* SGT_STELLA_IN_BOOLEAN;
extern Surrogate* SGT_STELLA_IN_MAPPABLE_OBJECT;
extern Surrogate* SGT_STELLA_IN_CONTEXT;

