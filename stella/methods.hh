// methods.hh

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
Object* apply(cpp_function_code code, Cons* arguments);
Parametric_Type_Specifier* make_parametric_type_specifier();
boolean terminate_transient_type_specifierP(Transient_Type_Specifier* self);
boolean defined_typeP(Surrogate* type);
Standard_Object* real_type_specifier(Surrogate* type);
Surrogate* canonical_type(Surrogate* type);
Parametric_Type_Specifier* yield_parametric_type_specifier(Cons* typespectree);
Anchored_Type_Specifier* yield_anchored_type_specifier(Cons* typespectree);
void incorporate_input_parameters(Method_Slot* method, Cons* parameters);
void incorporate_first_input_parameter(Method_Slot* method);
Method_Slot* define_stella_method_slot(Symbol* inputname, Cons* returntypes, boolean functionP, Cons* inputparameters, Keyword_Key_Value_List* options, Cons* methodbody);
Method_Slot* attach_method_slot_to_owner(Method_Slot* newmethod);
Object* yield_string_constant_tree(char* string);
Cons* yield_define_stella_method(Method_Slot* method);
Cons* yield_class_parameter_types(Class* renamed_Class);
boolean optimistic_subtype_ofP(Surrogate* subtype, Surrogate* supertype);
void warn_of_parameter_mismatch(Parametric_Type_Specifier* self, char* message);
Surrogate* validate_type_specifier(Standard_Object* self, Class* anchorclass, boolean skipanchoredtypeP);
Cons* synthesize_method_body(Method_Slot* method);
Surrogate* type_spec_to_base_type(Standard_Object* self);
Class* type_spec_to_class(Standard_Object* self);
boolean compatible_parameter_typesP(Standard_Object* subtype, Standard_Object* supertype);
boolean sub_type_spec_ofP(Standard_Object* subtype, Standard_Object* supertype);
boolean voidP(Standard_Object* type);
Standard_Object* extract_parameter_type(Standard_Object* self, Symbol* parameter, boolean& return1);
Standard_Object* compute_anchored_type_spec(Standard_Object* ownertype, Anchored_Type_Specifier* reltype);
Standard_Object* compute_relative_type_spec(Standard_Object* relativetype, Standard_Object* ownertype);
Object* yield_type_spec_tree(Standard_Object* self);
Method_Slot* attach_function(Method_Slot* newfunction);
Method_Slot* string_lookup_function(char* name);
Method_Slot* lookup_function_or_stella_function(Symbol* functionsymbol);
void destroy_function(Method_Slot* function);
Global_Variable* intern_global_variable(Global_Variable* global);
Global_Variable* string_lookup_global_variable(char* self);
Standard_Object* lookup_global_variable_type(Symbol* name);
Global_Variable* define_stella_global_variable_from_parse_tree(Cons* tree, char* stringifiedsource, Object*& return1);
void define_stella_global_variable_from_stringified_source(char* stringifiedsource);
Object* get_global_value(Surrogate* self);
Object* set_global_value(Surrogate* self, Object* value);
void destroy_variable(Global_Variable* variable);
Surrogate* define_stella_type_from_parse_tree(Cons* tree);
void define_stella_type_from_stringified_source(char* stringifiedsource);
void startup_methods();

// Global declarations:
extern Surrogate* SGT_METHODS_SURROGATE;
extern Surrogate* SGT_METHODS_PARAMETRIC_TYPE_SPECIFIER;
extern Surrogate* SGT_METHODS_ANCHORED_TYPE_SPECIFIER;
extern Surrogate* SGT_METHODS_OBJECT;
extern Surrogate* SGT_METHODS_VOID;
extern Symbol* SYM_METHODS_LIKE;
extern Symbol* SYM_METHODS_SIZE;
extern Symbol* SYM_METHODS_OF;
extern Symbol* SYM_METHODS_SELF;
extern Symbol* SYM_METHODS_IN;
extern Symbol* SYM_METHODS_OUT;
extern Symbol* SYM_METHODS_INOUT;
extern Symbol* SYM_METHODS_METHOD_PARAMETER_DIRECTIONS;
extern Symbol* SYM_METHODS_ARGUMENT_LIST;
extern Symbol* SYM_METHODS_aREST;
extern Symbol* SYM_METHODS_METHOD_VARIABLE_ARGUMENTSp;
extern Symbol* SYM_METHODS_aBODY;
extern Symbol* SYM_METHODS_METHOD_BODY_ARGUMENTp;
extern Surrogate* SGT_METHODS_UNKNOWN;
extern Keyword* KWD_METHODS_TYPE;
extern Keyword* KWD_METHODS_RETURN_TYPES;
extern Symbol* SYM_METHODS_SLOT_TYPE_SPECIFIER;
extern Keyword* KWD_METHODS_PUBLICp;
extern Keyword* KWD_METHODS_NATIVEp;
extern Symbol* SYM_METHODS_METHOD_NATIVEp;
extern Keyword* KWD_METHODS_GLOBALLY_INLINEp;
extern Symbol* SYM_METHODS_METHOD_GLOBALLY_INLINEp;
extern Keyword* KWD_METHODS_INLINE;
extern Symbol* SYM_METHODS_METHOD_INLINED_FUNCTIONS;
extern Keyword* KWD_METHODS_AUXILIARYp;
extern Symbol* SYM_METHODS_SLOT_AUXILIARYp;
extern Keyword* KWD_METHODS_DOCUMENTATION;
extern Symbol* SYM_METHODS_DOCUMENTATION;
extern Keyword* KWD_METHODS_RETURNS;
extern Keyword* KWD_METHODS_STORAGE_SLOT;
extern Symbol* SYM_METHODS_STORAGE_SLOT;
extern Keyword* KWD_METHODS_INHERITS_THROUGH;
extern Symbol* SYM_METHODS_METHOD_INHERITS_THROUGH;
extern Keyword* KWD_METHODS_PROPERTIES;
extern Symbol* SYM_METHODS_PROPERTIES;
extern Keyword* KWD_METHODS_META_ATTRIBUTES;
extern Symbol* SYM_METHODS_META_ATTRIBUTES;
extern Keyword* KWD_METHODS_COMMANDp;
extern Symbol* SYM_METHODS_METHOD_COMMANDp;
extern Keyword* KWD_METHODS_LISP_MACROp;
extern Symbol* SYM_METHODS_METHOD_LISP_MACROp;
extern Keyword* KWD_METHODS_EVALUATE_ARGUMENTSp;
extern Symbol* SYM_METHODS_METHOD_EVALUATE_ARGUMENTSp;
extern int oMAXIMUM_STRING_CONSTANT_SIZEo;
extern Symbol* SYM_METHODS_CONCATENATE;
extern Symbol* SYM_METHODS_NULL;
extern Symbol* SYM_METHODS_DEFINE_METHOD_FROM_STRINGIFIED_SOURCE;
extern Surrogate* SGT_METHODS_BOOLEAN;
extern Symbol* SYM_METHODS_SUPER_CLASSES;
extern Symbol* SYM_METHODS_EQUIVALENT_SLOT;
extern Symbol* SYM_METHODS_CLASS_ALL_SUPER_CLASSES;
extern Symbol* SYM_METHODS_SLOT_DIRECT_EQUIVALENT;
extern Symbol* SYM_METHODS_LET;
extern Symbol* SYM_METHODS_CURSOR;
extern Symbol* SYM_METHODS_VALUE;
extern Symbol* SYM_METHODS_SLOT_VALUE;
extern Symbol* SYM_METHODS_LOOP;
extern Symbol* SYM_METHODS_WHEN;
extern Symbol* SYM_METHODS_RETURN;
extern Symbol* SYM_METHODS_SETQ;
extern Symbol* SYM_METHODS_IF;
extern Symbol* SYM_METHODS_DEFINEDp;
extern Surrogate* SGT_METHODS_COLLECTION;
extern Surrogate* SGT_METHODS_CONS;
extern Symbol* SYM_METHODS_FIRST;
extern Hash_Table* oFUNCTION_LOOKUP_TABLEo;
extern Hash_Table* oGLOBAL_VARIABLE_LOOKUP_TABLEo;
extern Symbol* SYM_METHODS_VARIABLE_TYPE_SPECIFIER;
extern Symbol* SYM_METHODS_DEFSPECIAL;
extern Symbol* SYM_METHODS_DEFCONSTANT;
extern Keyword* KWD_METHODS_UNBOUND_SPECIAL_VARIABLE;

