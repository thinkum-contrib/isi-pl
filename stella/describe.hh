// describe.hh

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
Object* get_expander(Object* name, Cons* body);
Object* string_get_object(char* self, Object* type);
Object* integer_get_object(int self, Object* type);
Object* search_for_object(Object* self, Object* typeref);
boolean filter_string_to_classP(Class* self, All_Purpose_Iterator* iterator);
Iterator* string_to_classes(char* string, boolean exactP);
Object* string_to_class(char* string);
Object* string_to_context(char* string);
Object* string_to_function(char* string);
boolean dotted_stringP(char* string);
char* yield_exploded_method_name(char* dottedstring, char*& return1);
Object* string_to_slot(char* string);
Object* string_to_demon(char* string);
Object* integer_to_context(int integer);
Object* describe_expander(Object* name, Cons* body);
void describe_tersely(Object* self, Output_Stream* stream);
void pretty_print_stella_tree(Cons* tree, Output_Stream* stream);
void pretty_print_definition_tree(Cons* tree, Output_Stream* stream);
Object* consify_lists_and_iterators(Object* tree);
void print_class_list(Iterator* self, Output_Stream* stream);
Cons* read_OslotoptionslotsO();
Cons* write_OslotoptionslotsO(Cons* value);
Cons* read_OclassoptionslotsO();
Cons* write_OclassoptionslotsO(Cons* value);
Property_List* read_OclassunstringifiedoptionsO();
Property_List* write_OclassunstringifiedoptionsO(Property_List* value);
Cons* get_class_options();
Property_List* get_unstringified_class_options(Class* renamed_Class);
Cons* get_slot_options();
void pretty_print_literal(Object* literal, Output_Stream* stream);
boolean literal_eqlP(Object* x, Object* y);
Object* convert_to_literal(Object* object);
void pretty_print_class_options(Class* renamed_Class, Output_Stream* stream);
void pretty_print_slot_options(Storage_Slot* slot, Output_Stream* stream);
void pretty_print_method_parameters(Output_Stream* stream, Method_Slot* method);
void pretty_print_slot_block(Output_Stream* stream, Iterator* iterator, char* slotgroup);
void pretty_print_slots(Class* self, Output_Stream* stream);
char* xmodule_stringified_source(Module* self);
char* short_documentation(char* documentation);
void print_documentation_string(char* string, int indent, Output_Stream* stream);
void startup_describe();

// Global declarations:
extern Symbol* SYM_DESCRIBE_BQUOTE;
extern Symbol* SYM_DESCRIBE_GET_OBJECT;
extern Symbol* SYM_DESCRIBE_GET;
extern Symbol* SYM_DESCRIBE_GET_EXPANDER;
extern Key_Value_List* oSTRING_TO_OBJECT_FUNCTIONSo;
extern List* oINTEGER_TO_OBJECT_FUNCTIONSo;
extern Surrogate* SGT_DESCRIBE_CLASS;
extern Surrogate* SGT_DESCRIBE_FUNCTION_CODE_WRAPPER;
extern Surrogate* SGT_DESCRIBE_OBJECT;
extern Surrogate* SGT_DESCRIBE_CONTEXT;
extern Surrogate* SGT_DESCRIBE_METHOD_SLOT;
extern Surrogate* SGT_DESCRIBE_SLOT;
extern Surrogate* SGT_DESCRIBE_DEMON;
extern Keyword* oDEFAULT_DESCRIBE_MODEo;
extern Keyword* KWD_DESCRIBE_VERBOSE;
extern Keyword* KWD_DESCRIBE_TERSE;
extern Keyword* KWD_DESCRIBE_SOURCE;
extern Symbol* SYM_DESCRIBE_VERBOSE;
extern Symbol* SYM_DESCRIBE_TERSE;
extern Symbol* SYM_DESCRIBE_SOURCE;
extern Symbol* SYM_DESCRIBE_LET;
extern Symbol* SYM_DESCRIBE_NAMEEXPRESSION;
extern Symbol* SYM_DESCRIBE_OBJECT;
extern Symbol* SYM_DESCRIBE_ONLY_IF;
extern Symbol* SYM_DESCRIBE_DEFINEDp;
extern Symbol* SYM_DESCRIBE_NULL;
extern Symbol* SYM_DESCRIBE_IF;
extern Symbol* SYM_DESCRIBE_NULLp;
extern Symbol* SYM_DESCRIBE_PRINT;
extern Symbol* SYM_DESCRIBE_DESCRIBE_OBJECT;
extern Symbol* SYM_DESCRIBE_STANDARD_OUTPUT;
extern Symbol* SYM_DESCRIBE_DESCRIBE;
extern Symbol* SYM_DESCRIBE_DESCRIBE_EXPANDER;
extern Keyword* KWD_DESCRIBE_VOID;
extern int oPRETTY_PRINT_LIST_CUTOFFo;
extern Surrogate* SGT_DESCRIBE_LIST;
extern Surrogate* SGT_DESCRIBE_ITERATOR;
extern Cons* oSLOTOPTIONSLOTSo;
extern Symbol* SYM_DESCRIBE_oSLOTOPTIONSLOTSo;
extern Cons* oCLASSOPTIONSLOTSo;
extern Symbol* SYM_DESCRIBE_oCLASSOPTIONSLOTSo;
extern Property_List* oCLASSUNSTRINGIFIEDOPTIONSo;
extern Symbol* SYM_DESCRIBE_oCLASSUNSTRINGIFIEDOPTIONSo;
extern Symbol* SYM_DESCRIBE_SLOT_OPTION_KEYWORD;
extern Surrogate* SGT_DESCRIBE_RELATION;
extern Surrogate* SGT_DESCRIBE_STORAGE_SLOT;
extern Surrogate* SGT_DESCRIBE_BOOLEAN_WRAPPER;
extern Surrogate* SGT_DESCRIBE_LITERAL_WRAPPER;
extern Symbol* SYM_DESCRIBE_TRUE;
extern Symbol* SYM_DESCRIBE_FALSE;
extern Symbol* SYM_DESCRIBE_NULL_BOOLEAN;
extern Symbol* SYM_DESCRIBE_SLOT_INITIAL_VALUE;
extern Symbol* SYM_DESCRIBE_SLOT_TYPE_SPECIFIER;
extern Symbol* SYM_DESCRIBE_SLOT;
extern Keyword* KWD_DESCRIBE_OWNER;
extern Keyword* KWD_DESCRIBE_TYPE;
extern Keyword* KWD_DESCRIBE_INITIALLY;
extern Symbol* SYM_DESCRIBE_DEFMODULE;
extern Keyword* KWD_DESCRIBE_INCLUDES;
extern Keyword* KWD_DESCRIBE_USES;
extern Keyword* KWD_DESCRIBE_SHADOWS;
extern Symbol* SYM_DESCRIBE_gg_INFERRED_SLOTS;
extern Keyword* KWD_DESCRIBE_CHILDREN;
extern Keyword* KWD_DESCRIBE_USED_BY;
extern Keyword* KWD_DESCRIBE_CARDINAL_MODULE;
extern Symbol* SYM_DESCRIBE_DOCUMENTATION;

