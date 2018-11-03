// hierarchy.hh

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

// Class headers:
class Object;
class Standard_Object;
class Transient_Mixin;
class Reference_Count_Object;
class Dynamic_Slots_Mixin;
class Context_Sensitive_Object;
class Active_Object;
class Abstract_Iterator;
class Iterator;
class Cons_Iterator;
class List_Iterator;
class Destructive_List_Iterator;
class Set_Iterator;
class All_Purpose_Iterator;
class Types_To_Classes_Iterator;
class Abstract_Dictionary_Iterator;
class Dictionary_Iterator;
class Property_List_Iterator;
class Kv_List_Iterator;
class Interval_Iterator;
class Integer_Interval_Iterator;
class Reverse_Integer_Interval_Iterator;
class String_Iterator;
class Abstract_Collection;
class Collection;
class Set_Mixin;
class Sequence_Mixin;
class Sequence;
class List;
class Set;
class Class_Extension;
class Cons;
class Transient_Cons;
class Abstract_Dictionary;
class Dictionary;
class Property_List;
class Kv_Cons;
class Key_Value_List;
class Abstract_Hash_Table;
class Hash_Table;
class Integer_Hash_Table;
class Float_Hash_Table;
class String_Hash_Table;
class String_To_Integer_Hash_Table;
class Vector;
class Extensible_Vector;
class Extensible_Symbol_Array;
class Vector_Sequence;
class Short_Vector_Sequence;
class Boolean_Vector;
class Integer_Vector;
class Array;
class Null_Terminated_Array;
class Active_Collection_Mixin;
class Active_List;
class Active_Set;
class Demon;
class List_Of_Slot;
class List_Of_Symbol;
class List_Of_Keyword;
class List_Of_Type;
class Keyword_Key_Value_List;
class Generalized_Symbol;
class Symbol;
class Surrogate;
class Keyword;
class Indexical;
class Transient_Symbol;
class Transient_Keyword;
class Mappable_Object;
class Relation;
class Class;
class Polymorphic_Relation;
class Slot;
class Storage_Slot;
class Method_Slot;
class Compound_Type_Specifier;
class Parametric_Type_Specifier;
class Transient_Type_Specifier;
class Anchored_Type_Specifier;
class Table;
class Global_Variable;
class Quoted_Expression;
class Context;
class Module;
class World;
class Cs_Value;
class Interval;
class Taxonomy_Node;
class Taxonomy_Graph;
class Exception;
class Stella_Exception;
class Read_Exception;
class Unhandled_Exception;
class Wrapper;
class Literal_Wrapper;
class Number_Wrapper;
class Integer_Wrapper;
class Float_Wrapper;
class String_Wrapper;
class Character_Wrapper;
class Boolean_Wrapper;
class Code_Wrapper;
class Function_Code_Wrapper;
class Method_Code_Wrapper;
class Transient_Integer_Wrapper;
class Transient_Float_Wrapper;
class Transient_String_Wrapper;
class Transient_Character_Wrapper;
class Transient_Function_Code_Wrapper;
class Transient_Method_Code_Wrapper;
class Verbatim_String_Wrapper;
class Lisp_Code;
class Lisp_Cons_Iterator;
class Stream;
class Output_Stream;
class Input_Stream;
class Output_File_Stream;
class Input_File_Stream;
class Output_String_Stream;
class Input_String_Stream;

// Function signatures:
ostream& operator<< (ostream& stream, Object* self);
Object* access_reference_count_object_slot_value(Reference_Count_Object* self, Symbol* slotname, Object* value, boolean setvalueP);
Object* access_context_sensitive_object_slot_value(Context_Sensitive_Object* self, Symbol* slotname, Object* value, boolean setvalueP);
Object* access_active_object_slot_value(Active_Object* self, Symbol* slotname, Object* value, boolean setvalueP);
Object* access_abstract_iterator_slot_value(Abstract_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Cons_Iterator* new_cons_iterator();
Object* access_cons_iterator_slot_value(Cons_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
List_Iterator* new_list_iterator();
Object* access_list_iterator_slot_value(List_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Destructive_List_Iterator* new_destructive_list_iterator();
Object* access_destructive_list_iterator_slot_value(Destructive_List_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Set_Iterator* new_set_iterator();
Object* access_set_iterator_slot_value(Set_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
All_Purpose_Iterator* new_all_purpose_iterator();
Object* access_all_purpose_iterator_slot_value(All_Purpose_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Types_To_Classes_Iterator* new_types_to_classes_iterator(Cons* iterator_cursor);
Object* access_types_to_classes_iterator_slot_value(Types_To_Classes_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Property_List_Iterator* new_property_list_iterator();
Object* access_property_list_iterator_slot_value(Property_List_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Kv_List_Iterator* new_kv_list_iterator();
Object* access_kv_list_iterator_slot_value(Kv_List_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Integer_Interval_Iterator* new_integer_interval_iterator(int lower_bound, int upper_bound);
Object* access_integer_interval_iterator_slot_value(Integer_Interval_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Reverse_Integer_Interval_Iterator* new_reverse_integer_interval_iterator(int lower_bound, int upper_bound);
Object* access_reverse_integer_interval_iterator_slot_value(Reverse_Integer_Interval_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
String_Iterator* new_string_iterator();
Object* access_string_iterator_slot_value(String_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
List* new_list();
Object* access_list_slot_value(List* self, Symbol* slotname, Object* value, boolean setvalueP);
Set* new_set();
Object* access_set_slot_value(Set* self, Symbol* slotname, Object* value, boolean setvalueP);
Class_Extension* new_class_extension();
Cons* new_cons();
Object* access_cons_slot_value(Cons* self, Symbol* slotname, Object* value, boolean setvalueP);
Transient_Cons* new_transient_cons();
Object* access_transient_cons_slot_value(Transient_Cons* self, Symbol* slotname, Object* value, boolean setvalueP);
Property_List* new_property_list();
Object* access_property_list_slot_value(Property_List* self, Symbol* slotname, Object* value, boolean setvalueP);
Kv_Cons* new_kv_cons();
Object* access_kv_cons_slot_value(Kv_Cons* self, Symbol* slotname, Object* value, boolean setvalueP);
Key_Value_List* new_key_value_list();
Object* access_key_value_list_slot_value(Key_Value_List* self, Symbol* slotname, Object* value, boolean setvalueP);
Hash_Table* new_hash_table();
Integer_Hash_Table* new_integer_hash_table();
Float_Hash_Table* new_float_hash_table();
String_Hash_Table* new_string_hash_table();
String_To_Integer_Hash_Table* new_string_to_integer_hash_table();
Vector* new_vector(int array_size);
Object* access_vector_slot_value(Vector* self, Symbol* slotname, Object* value, boolean setvalueP);
Extensible_Vector* new_extensible_vector(int array_size);
Extensible_Symbol_Array* new_extensible_symbol_array(int array_size);
Object* access_extensible_symbol_array_slot_value(Extensible_Symbol_Array* self, Symbol* slotname, Object* value, boolean setvalueP);
Object* access_vector_sequence_slot_value(Vector_Sequence* self, Symbol* slotname, Object* value, boolean setvalueP);
Short_Vector_Sequence* new_short_vector_sequence(int array_size);
Object* access_short_vector_sequence_slot_value(Short_Vector_Sequence* self, Symbol* slotname, Object* value, boolean setvalueP);
Boolean_Vector* new_boolean_vector(int array_size);
Integer_Vector* new_integer_vector(int array_size);
Array* new_array();
Null_Terminated_Array* new_null_terminated_array();
Active_List* new_active_list();
Active_Set* new_active_set();
Demon* new_demon();
Object* access_demon_slot_value(Demon* self, Symbol* slotname, Object* value, boolean setvalueP);
List_Of_Slot* new_list_of_slot();
List_Of_Symbol* new_list_of_symbol();
List_Of_Keyword* new_list_of_keyword();
List_Of_Type* new_list_of_type();
Keyword_Key_Value_List* new_keyword_key_value_list();
Object* access_generalized_symbol_slot_value(Generalized_Symbol* self, Symbol* slotname, Object* value, boolean setvalueP);
Symbol* new_symbol(char* symbol_name);
Object* access_symbol_slot_value(Symbol* self, Symbol* slotname, Object* value, boolean setvalueP);
Surrogate* new_surrogate(char* symbol_name);
Object* access_surrogate_slot_value(Surrogate* self, Symbol* slotname, Object* value, boolean setvalueP);
Keyword* new_keyword(char* symbol_name);
Object* access_keyword_slot_value(Keyword* self, Symbol* slotname, Object* value, boolean setvalueP);
Indexical* new_indexical(char* symbol_name);
Object* access_indexical_slot_value(Indexical* self, Symbol* slotname, Object* value, boolean setvalueP);
Transient_Symbol* new_transient_symbol(char* symbol_name);
Transient_Keyword* new_transient_keyword(char* symbol_name);
Object* access_mappable_object_slot_value(Mappable_Object* self, Symbol* slotname, Object* value, boolean setvalueP);
Object* access_relation_slot_value(Relation* self, Symbol* slotname, Object* value, boolean setvalueP);
Class* new_class();
Object* access_class_slot_value(Class* self, Symbol* slotname, Object* value, boolean setvalueP);
Object* access_polymorphic_relation_slot_value(Polymorphic_Relation* self, Symbol* slotname, Object* value, boolean setvalueP);
Object* access_slot_slot_value(Slot* self, Symbol* slotname, Object* value, boolean setvalueP);
Storage_Slot* new_storage_slot();
Object* access_storage_slot_slot_value(Storage_Slot* self, Symbol* slotname, Object* value, boolean setvalueP);
Method_Slot* new_method_slot();
Object* access_method_slot_slot_value(Method_Slot* self, Symbol* slotname, Object* value, boolean setvalueP);
Parametric_Type_Specifier* new_parametric_type_specifier();
Object* access_parametric_type_specifier_slot_value(Parametric_Type_Specifier* self, Symbol* slotname, Object* value, boolean setvalueP);
Transient_Type_Specifier* new_transient_type_specifier();
Object* access_transient_type_specifier_slot_value(Transient_Type_Specifier* self, Symbol* slotname, Object* value, boolean setvalueP);
Anchored_Type_Specifier* new_anchored_type_specifier();
Object* access_anchored_type_specifier_slot_value(Anchored_Type_Specifier* self, Symbol* slotname, Object* value, boolean setvalueP);
Table* new_table();
Object* access_table_slot_value(Table* self, Symbol* slotname, Object* value, boolean setvalueP);
Global_Variable* new_global_variable();
Object* access_global_variable_slot_value(Global_Variable* self, Symbol* slotname, Object* value, boolean setvalueP);
Quoted_Expression* new_quoted_expression();
Object* access_quoted_expression_slot_value(Quoted_Expression* self, Symbol* slotname, Object* value, boolean setvalueP);
Object* access_context_slot_value(Context* self, Symbol* slotname, Object* value, boolean setvalueP);
Module* new_module();
Object* access_module_slot_value(Module* self, Symbol* slotname, Object* value, boolean setvalueP);
World* new_world();
Object* access_world_slot_value(World* self, Symbol* slotname, Object* value, boolean setvalueP);
Cs_Value* new_cs_value();
Interval* new_interval();
Object* access_interval_slot_value(Interval* self, Symbol* slotname, Object* value, boolean setvalueP);
Taxonomy_Node* new_taxonomy_node();
Object* access_taxonomy_node_slot_value(Taxonomy_Node* self, Symbol* slotname, Object* value, boolean setvalueP);
Taxonomy_Graph* new_taxonomy_graph();
Object* access_taxonomy_graph_slot_value(Taxonomy_Graph* self, Symbol* slotname, Object* value, boolean setvalueP);
Exception* new_exception();
Stella_Exception* new_stella_exception();
Read_Exception* new_read_exception();
Unhandled_Exception* new_unhandled_exception();
Integer_Wrapper* new_integer_wrapper(int wrapper_value);
Object* access_integer_wrapper_slot_value(Integer_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Float_Wrapper* new_float_wrapper(double wrapper_value);
Object* access_float_wrapper_slot_value(Float_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
String_Wrapper* new_string_wrapper(char* wrapper_value);
Object* access_string_wrapper_slot_value(String_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Character_Wrapper* new_character_wrapper(char wrapper_value);
Object* access_character_wrapper_slot_value(Character_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Boolean_Wrapper* new_boolean_wrapper(boolean wrapper_value);
Object* access_boolean_wrapper_slot_value(Boolean_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Function_Code_Wrapper* new_function_code_wrapper(cpp_function_code wrapper_value);
Object* access_function_code_wrapper_slot_value(Function_Code_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Method_Code_Wrapper* new_method_code_wrapper(cpp_method_code wrapper_value);
Object* access_method_code_wrapper_slot_value(Method_Code_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Transient_Integer_Wrapper* new_transient_integer_wrapper(int wrapper_value);
Object* access_transient_integer_wrapper_slot_value(Transient_Integer_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Transient_Float_Wrapper* new_transient_float_wrapper(double wrapper_value);
Object* access_transient_float_wrapper_slot_value(Transient_Float_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Transient_String_Wrapper* new_transient_string_wrapper(char* wrapper_value);
Object* access_transient_string_wrapper_slot_value(Transient_String_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Transient_Character_Wrapper* new_transient_character_wrapper(char wrapper_value);
Object* access_transient_character_wrapper_slot_value(Transient_Character_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Transient_Function_Code_Wrapper* new_transient_function_code_wrapper(cpp_function_code wrapper_value);
Object* access_transient_function_code_wrapper_slot_value(Transient_Function_Code_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Transient_Method_Code_Wrapper* new_transient_method_code_wrapper(cpp_method_code wrapper_value);
Object* access_transient_method_code_wrapper_slot_value(Transient_Method_Code_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Verbatim_String_Wrapper* new_verbatim_string_wrapper(char* wrapper_value);
Object* access_verbatim_string_wrapper_slot_value(Verbatim_String_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP);
Lisp_Cons_Iterator* new_lisp_cons_iterator();
Object* access_stream_slot_value(Stream* self, Symbol* slotname, Object* value, boolean setvalueP);
Output_Stream* new_output_stream();
Input_Stream* new_input_stream();
Output_File_Stream* new_output_file_stream(char* filename);
Object* access_output_file_stream_slot_value(Output_File_Stream* self, Symbol* slotname, Object* value, boolean setvalueP);
Input_File_Stream* new_input_file_stream(char* filename);
Object* access_input_file_stream_slot_value(Input_File_Stream* self, Symbol* slotname, Object* value, boolean setvalueP);
Output_String_Stream* new_output_string_stream(char* the_string);
Object* access_output_string_stream_slot_value(Output_String_Stream* self, Symbol* slotname, Object* value, boolean setvalueP);
Input_String_Stream* new_input_string_stream(char* the_string);
Object* access_input_string_stream_slot_value(Input_String_Stream* self, Symbol* slotname, Object* value, boolean setvalueP);
void startup_hierarchy();

// Global declarations:
extern Symbol* SYM_HIERARCHY_TYPE_SPEC;
extern boolean oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo;
extern Symbol* SYM_HIERARCHY_REFERENCE_COUNT;
extern Symbol* SYM_HIERARCHY_BADp;
extern Symbol* SYM_HIERARCHY_HOME_CONTEXT;
extern Symbol* SYM_HIERARCHY_FIRST_ITERATIONp;
extern Symbol* SYM_HIERARCHY_OBJECT_ITERATOR;
extern Symbol* SYM_HIERARCHY_CONS_ITERATOR_CURSOR;
extern Surrogate* SGT_HIERARCHY_CONS_ITERATOR;
extern Symbol* SYM_HIERARCHY_LIST_ITERATOR_CURSOR;
extern Symbol* SYM_HIERARCHY_LIST_ITERATOR_COLLECTION;
extern Surrogate* SGT_HIERARCHY_LIST_ITERATOR;
extern Symbol* SYM_HIERARCHY_THE_CONS_LIST;
extern Surrogate* SGT_HIERARCHY_DESTRUCTIVE_LIST_ITERATOR;
extern Symbol* SYM_HIERARCHY_SET_ITERATOR_CURSOR;
extern Symbol* SYM_HIERARCHY_SET_ITERATOR_COLLECTION;
extern Surrogate* SGT_HIERARCHY_SET_ITERATOR;
extern Symbol* SYM_HIERARCHY_KEY;
extern Symbol* SYM_HIERARCHY_ITERATOR_NEXT_CODE;
extern Symbol* SYM_HIERARCHY_ITERATOR_FILTER_CODE;
extern Symbol* SYM_HIERARCHY_ITERATOR_EMPTY_CODE;
extern Symbol* SYM_HIERARCHY_ITERATOR_NESTED_ITERATOR;
extern Symbol* SYM_HIERARCHY_ITERATOR_OBJECT;
extern Symbol* SYM_HIERARCHY_ITERATOR_SECOND_OBJECT;
extern Symbol* SYM_HIERARCHY_ITERATOR_INTEGER;
extern Symbol* SYM_HIERARCHY_ITERATOR_SECOND_INTEGER;
extern Symbol* SYM_HIERARCHY_ITERATOR_CONS_LIST;
extern Surrogate* SGT_HIERARCHY_ALL_PURPOSE_ITERATOR;
extern Symbol* SYM_HIERARCHY_ITERATOR_CURSOR;
extern Surrogate* SGT_HIERARCHY_TYPES_TO_CLASSES_ITERATOR;
extern Symbol* SYM_HIERARCHY_OBJECT_DICTIONARY_ITERATOR;
extern Symbol* SYM_HIERARCHY_PLIST_ITERATOR_CURSOR;
extern Symbol* SYM_HIERARCHY_PLIST_ITERATOR_COLLECTION;
extern Surrogate* SGT_HIERARCHY_PROPERTY_LIST_ITERATOR;
extern Symbol* SYM_HIERARCHY_THE_KV_LIST;
extern Symbol* SYM_HIERARCHY_KV_LIST_ITERATOR_CURSOR;
extern Surrogate* SGT_HIERARCHY_KV_LIST_ITERATOR;
extern Symbol* SYM_HIERARCHY_INTERVAL_CURSOR;
extern Symbol* SYM_HIERARCHY_LOWER_BOUND;
extern Symbol* SYM_HIERARCHY_UPPER_BOUND;
extern Surrogate* SGT_HIERARCHY_INTEGER_INTERVAL_ITERATOR;
extern Surrogate* SGT_HIERARCHY_REVERSE_INTEGER_INTERVAL_ITERATOR;
extern Symbol* SYM_HIERARCHY_THE_STRING;
extern Symbol* SYM_HIERARCHY_CURSOR;
extern Symbol* SYM_HIERARCHY_END;
extern Surrogate* SGT_HIERARCHY_STRING_ITERATOR;
extern Symbol* SYM_HIERARCHY_OBJECT_COLLECTION;
extern Symbol* SYM_HIERARCHY_OBJECT_SEQUENCE;
extern List* oRECYCLED_LIST_So;
extern Surrogate* SGT_HIERARCHY_LIST;
extern List* oRECYCLED_SET_So;
extern Surrogate* SGT_HIERARCHY_SET;
extern Surrogate* SGT_HIERARCHY_CLASS_EXTENSION;
extern Cons* oRECYCLED_CONS_So;
extern Symbol* SYM_HIERARCHY_VALUE;
extern Symbol* SYM_HIERARCHY_REST;
extern Surrogate* SGT_HIERARCHY_CONS;
extern Transient_Cons* oRECYCLED_TRANSIENT_CONS_So;
extern Transient_Cons* oALL_TRANSIENT_CONS_So;
extern Transient_Cons* oUNUSED_TRANSIENT_CONS_So;
extern Symbol* SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT;
extern Surrogate* SGT_HIERARCHY_TRANSIENT_CONS;
extern Symbol* SYM_HIERARCHY_OBJECT_TO_OBJECT_DICTIONARY;
extern Symbol* SYM_HIERARCHY_THE_PLIST;
extern Surrogate* SGT_HIERARCHY_PROPERTY_LIST;
extern Surrogate* SGT_HIERARCHY_KV_CONS;
extern Surrogate* SGT_HIERARCHY_KEY_VALUE_LIST;
extern Surrogate* SGT_HIERARCHY_HASH_TABLE;
extern Symbol* SYM_HIERARCHY_OBJECT_TO_OBJECT_HASH_TABLE;
extern Surrogate* SGT_HIERARCHY_INTEGER_HASH_TABLE;
extern Surrogate* SGT_HIERARCHY_FLOAT_HASH_TABLE;
extern Surrogate* SGT_HIERARCHY_STRING_HASH_TABLE;
extern Surrogate* SGT_HIERARCHY_STRING_TO_INTEGER_HASH_TABLE;
extern Symbol* SYM_HIERARCHY_ARRAY_SIZE;
extern Surrogate* SGT_HIERARCHY_VECTOR;
extern Surrogate* SGT_HIERARCHY_EXTENSIBLE_VECTOR;
extern Symbol* SYM_HIERARCHY_TOP_SYMBOL_OFFSET;
extern Symbol* SYM_HIERARCHY_POTENTIAL_FREE_SYMBOL_OFFSET;
extern Surrogate* SGT_HIERARCHY_EXTENSIBLE_SYMBOL_ARRAY;
extern int oHARDWIRED_RESIZE_INCREMENT_ON_VECTOR_SEQUENCEo;
extern Symbol* SYM_HIERARCHY_RESIZE_INCREMENT;
extern Symbol* SYM_HIERARCHY_SEQUENCE_LENGTH;
extern Symbol* SYM_HIERARCHY_VSEQ;
extern int oHARDWIRED_RESIZE_INCREMENT_ON_SHORT_VECTOR_SEQUENCEo;
extern Surrogate* SGT_HIERARCHY_SHORT_VECTOR_SEQUENCE;
extern Symbol* SYM_HIERARCHY_SVSEQ;
extern Surrogate* SGT_HIERARCHY_BOOLEAN_VECTOR;
extern Surrogate* SGT_HIERARCHY_INTEGER_VECTOR;
extern Surrogate* SGT_HIERARCHY_ARRAY;
extern Surrogate* SGT_HIERARCHY_NULL_TERMINATED_ARRAY;
extern Surrogate* SGT_HIERARCHY_ACTIVE_LIST;
extern Surrogate* SGT_HIERARCHY_ACTIVE_SET;
extern Symbol* SYM_HIERARCHY_DEMON_NAME;
extern Symbol* SYM_HIERARCHY_DEMON_ACTION;
extern Symbol* SYM_HIERARCHY_DEMON_CLASS_REFS;
extern Symbol* SYM_HIERARCHY_DEMON_SLOT_REFS;
extern Symbol* SYM_HIERARCHY_DEMON_CODE;
extern Symbol* SYM_HIERARCHY_DEMON_METHOD;
extern Symbol* SYM_HIERARCHY_DEMON_DOCUMENTATION;
extern Symbol* SYM_HIERARCHY_DEMON_GUARDp;
extern Symbol* SYM_HIERARCHY_DEMON_ALLp;
extern Symbol* SYM_HIERARCHY_DEMON_INHERITp;
extern Surrogate* SGT_HIERARCHY_DEMON;
extern Surrogate* SGT_HIERARCHY_LIST_OF_SLOT;
extern Surrogate* SGT_HIERARCHY_LIST_OF_SYMBOL;
extern Surrogate* SGT_HIERARCHY_LIST_OF_KEYWORD;
extern Surrogate* SGT_HIERARCHY_LIST_OF_TYPE;
extern Surrogate* SGT_HIERARCHY_KEYWORD_KEY_VALUE_LIST;
extern Symbol* SYM_HIERARCHY_SYMBOL_NAME;
extern Symbol* SYM_HIERARCHY_SYMBOL_ID;
extern Symbol* SYM_HIERARCHY_INTERNED_IN;
extern Symbol* SYM_HIERARCHY_SYMBOL_SLOT_OFFSET;
extern Symbol* SYM_HIERARCHY_SYMBOL_VALUE_AND_PLIST;
extern Surrogate* SGT_HIERARCHY_SYMBOL;
extern Symbol* SYM_HIERARCHY_SURROGATE_VALUE;
extern Symbol* SYM_HIERARCHY_SURROGATE_NAME;
extern Symbol* SYM_HIERARCHY_TYPE_CLASS;
extern Symbol* SYM_HIERARCHY_TYPE_NAME;
extern Symbol* SYM_HIERARCHY_SLOTREF_SLOT;
extern Surrogate* SGT_HIERARCHY_SURROGATE;
extern Symbol* SYM_HIERARCHY_TYPE;
extern Symbol* SYM_HIERARCHY_SLOTREF;
extern Symbol* SYM_HIERARCHY_KEYWORD_NAME;
extern Surrogate* SGT_HIERARCHY_KEYWORD;
extern Symbol* SYM_HIERARCHY_INDEXICAL_VALUE;
extern Surrogate* SGT_HIERARCHY_INDEXICAL;
extern Surrogate* SGT_HIERARCHY_TRANSIENT_SYMBOL;
extern Surrogate* SGT_HIERARCHY_TRANSIENT_KEYWORD;
extern Symbol* SYM_HIERARCHY_PROJECTS_ONTO;
extern Symbol* SYM_HIERARCHY_PROJECTED_FROM;
extern Symbol* SYM_HIERARCHY_PROPERTIES;
extern Symbol* SYM_HIERARCHY_STORED_ACTIVEp;
extern Symbol* SYM_HIERARCHY_ABSTRACTp;
extern int oHARDWIRED_CLASS_ARITY_ON_CLASSo;
extern Symbol* SYM_HIERARCHY_CLASS_CL_STRUCT_SLOTS;
extern Symbol* SYM_HIERARCHY_CLASS_RECYCLE_METHOD;
extern Keyword* KWD_HIERARCHY_NONE;
extern Symbol* SYM_HIERARCHY_CLASS_PARAMETERS;
extern Symbol* SYM_HIERARCHY_CLASS_REQUIRED_SLOT_NAMES;
extern Symbol* SYM_HIERARCHY_CLASS_GUARD_CONSTRUCTOR_DEMONS;
extern Symbol* SYM_HIERARCHY_CLASS_CONSTRUCTOR_DEMONS;
extern Symbol* SYM_HIERARCHY_CLASS_GUARD_DESTRUCTOR_DEMONS;
extern Symbol* SYM_HIERARCHY_CLASS_DESTRUCTOR_DEMONS;
extern Symbol* SYM_HIERARCHY_CLASS_KEY;
extern Symbol* SYM_HIERARCHY_CLASS_SYNONYMS;
extern Symbol* SYM_HIERARCHY_CL_STRUCTp;
extern Symbol* SYM_HIERARCHY_MIXINp;
extern Symbol* SYM_HIERARCHY_CLASS_TYPE;
extern Symbol* SYM_HIERARCHY_CLASS_ARITY;
extern Symbol* SYM_HIERARCHY_CLASS_DIRECT_SUPERS;
extern Symbol* SYM_HIERARCHY_CLASS_DIRECT_SUBS;
extern Symbol* SYM_HIERARCHY_CLASS_ALL_SUPER_CLASSES;
extern Symbol* SYM_HIERARCHY_CLASS_ALL_SLOTS;
extern Symbol* SYM_HIERARCHY_CLASS_LOCAL_SLOTS;
extern Symbol* SYM_HIERARCHY_CLASS_SLOT_AND_METHOD_CACHE;
extern Symbol* SYM_HIERARCHY_CLASS_ABSTRACTp;
extern Symbol* SYM_HIERARCHY_CLASS_MIXINp;
extern Symbol* SYM_HIERARCHY_CLASS_COLLECTIONp;
extern Symbol* SYM_HIERARCHY_CLASS_CL_STRUCTp;
extern Symbol* SYM_HIERARCHY_CLASS_PUBLICp;
extern Symbol* SYM_HIERARCHY_CLASS_FINALIZEDp;
extern Symbol* SYM_HIERARCHY_CLASS_SLOTS_FINALIZEDp;
extern Symbol* SYM_HIERARCHY_CLASS_STRINGIFIED_SOURCE;
extern Symbol* SYM_HIERARCHY_CLASS_CONSTRUCTOR_CODE;
extern Symbol* SYM_HIERARCHY_CLASS_SLOT_ACCESSOR_CODE;
extern Symbol* SYM_HIERARCHY_CLASS_MARKEDp;
extern Symbol* SYM_HIERARCHY_CLASS_TAXONOMY_NODE;
extern Symbol* SYM_HIERARCHY_CLASS_DOCUMENTATION;
extern Symbol* SYM_HIERARCHY_CLASS_PRINT_FORM;
extern Symbol* SYM_HIERARCHY_DOCUMENTATION;
extern Symbol* SYM_HIERARCHY_PRINT_FORM;
extern Surrogate* SGT_HIERARCHY_CLASS;
extern Surrogate* SGT_HIERARCHY_ACTIVE_OBJECT;
extern Symbol* SYM_HIERARCHY_CLASS_CREATOR;
extern Symbol* SYM_HIERARCHY_CLASS_INITIALIZER;
extern Symbol* SYM_HIERARCHY_CLASS_TERMINATOR;
extern Symbol* SYM_HIERARCHY_CLASS_DESTRUCTOR;
extern Symbol* SYM_HIERARCHY_CLASS_INITIAL_VALUE;
extern Symbol* SYM_HIERARCHY_CLASS_EXTENSION;
extern Symbol* SYM_HIERARCHY_CLASS_CL_NATIVE_TYPE;
extern Symbol* SYM_HIERARCHY_CLASS_CPP_NATIVE_TYPE;
extern Symbol* SYM_HIERARCHY_CLASS_JAVA_NATIVE_TYPE;
extern Symbol* SYM_HIERARCHY_SLOT_DIRECT_EQUIVALENT;
extern Symbol* SYM_HIERARCHY_SLOT_AUXILIARYp;
extern Symbol* SYM_HIERARCHY_SLOT_DIRECT_SUPERS;
extern Symbol* SYM_HIERARCHY_SLOT_DIRECT_SUBS;
extern Symbol* SYM_HIERARCHY_SLOT_NAME;
extern Symbol* SYM_HIERARCHY_SLOT_OWNER;
extern Symbol* SYM_HIERARCHY_SLOT_BASE_TYPE;
extern Symbol* SYM_HIERARCHY_SLOT_SLOTREF;
extern Symbol* SYM_HIERARCHY_SLOT_PUBLICp;
extern Symbol* SYM_HIERARCHY_SLOT_RENAMEDp;
extern Symbol* SYM_HIERARCHY_SLOT_EXTERNALp;
extern Symbol* SYM_HIERARCHY_SLOT_MARKEDp;
extern Symbol* SYM_HIERARCHY_SLOT_DOCUMENTATION;
extern Symbol* SYM_HIERARCHY_SLOT_TYPE_SPECIFIER;
extern Symbol* SYM_HIERARCHY_SLOT_RENAMES;
extern Surrogate* SGT_HIERARCHY_COLLECTION;
extern Symbol* SYM_HIERARCHY_SLOT_CLOSURE_ASSUMPTION;
extern Symbol* SYM_HIERARCHY_SLOT_ALLOCATION;
extern Keyword* KWD_HIERARCHY_INSTANCE;
extern Symbol* SYM_HIERARCHY_SLOT_GUARD_DEMONS;
extern Symbol* SYM_HIERARCHY_SLOT_DEMONS;
extern Symbol* SYM_HIERARCHY_SLOT_ACCESSOR_METHODS;
extern Symbol* SYM_HIERARCHY_SLOT_REQUIREDp;
extern Symbol* SYM_HIERARCHY_SLOT_COMPONENTp;
extern Symbol* SYM_HIERARCHY_SLOT_READ_ONLYp;
extern Symbol* SYM_HIERARCHY_SLOT_HARDWIREDp;
extern Symbol* SYM_HIERARCHY_SLOT_CONTEXT_SENSITIVEp;
extern Surrogate* SGT_HIERARCHY_STORAGE_SLOT;
extern Symbol* SYM_HIERARCHY_SLOT_DEFAULT_EXPRESSION;
extern Symbol* SYM_HIERARCHY_SLOT_READER;
extern Symbol* SYM_HIERARCHY_SLOT_WRITER;
extern Symbol* SYM_HIERARCHY_METHOD_PARAMETER_DIRECTIONS;
extern Symbol* SYM_HIERARCHY_METHOD_VARIABLE_ARGUMENTSp;
extern Symbol* SYM_HIERARCHY_METHOD_BODY_ARGUMENTp;
extern Symbol* SYM_HIERARCHY_METHOD_NATIVEp;
extern Symbol* SYM_HIERARCHY_METHOD_GLOBALLY_INLINEp;
extern Symbol* SYM_HIERARCHY_METHOD_INLINED_FUNCTIONS;
extern Symbol* SYM_HIERARCHY_METHOD_COMMANDp;
extern Symbol* SYM_HIERARCHY_METHOD_EVALUATE_ARGUMENTSp;
extern Symbol* SYM_HIERARCHY_METHOD_LISP_MACROp;
extern Symbol* SYM_HIERARCHY_METHOD_SETTERp;
extern Symbol* SYM_HIERARCHY_METHOD_PARAMETER_NAMES;
extern Symbol* SYM_HIERARCHY_METHOD_PARAMETER_TYPE_SPECIFIERS;
extern Symbol* SYM_HIERARCHY_METHOD_RETURN_TYPE_SPECIFIERS;
extern Symbol* SYM_HIERARCHY_METHOD_STRINGIFIED_SOURCE;
extern Symbol* SYM_HIERARCHY_METHOD_CODE;
extern Symbol* SYM_HIERARCHY_FUNCTION_CODE;
extern Symbol* SYM_HIERARCHY_METHOD_FUNCTIONp;
extern Symbol* SYM_HIERARCHY_METHOD_AUXILIARYp;
extern Symbol* SYM_HIERARCHY_METHOD_DOCUMENTATION;
extern Symbol* SYM_HIERARCHY_METHOD_STORAGE_SLOT;
extern Symbol* SYM_HIERARCHY_STORAGE_SLOT;
extern Surrogate* SGT_HIERARCHY_METHOD_SLOT;
extern Symbol* SYM_HIERARCHY_FUNCTION;
extern Symbol* SYM_HIERARCHY_SPECIFIER_BASE_TYPE;
extern Symbol* SYM_HIERARCHY_SPECIFIER_PARAMETER_TYPES;
extern Symbol* SYM_HIERARCHY_SPECIFIER_SEQUENCE_SIZE;
extern Surrogate* SGT_HIERARCHY_PARAMETRIC_TYPE_SPECIFIER;
extern Transient_Type_Specifier* oALL_TRANSIENT_TYPE_SPECIFIER_So;
extern Transient_Type_Specifier* oUNUSED_TRANSIENT_TYPE_SPECIFIER_So;
extern Surrogate* SGT_HIERARCHY_TRANSIENT_TYPE_SPECIFIER;
extern Symbol* SYM_HIERARCHY_SPECIFIER_PARAMETER_NAME;
extern Surrogate* SGT_HIERARCHY_ANCHORED_TYPE_SPECIFIER;
extern Symbol* SYM_HIERARCHY_VARIABLE_ARITYp;
extern Symbol* SYM_HIERARCHY_TUPLE_DOMAINS;
extern Surrogate* SGT_HIERARCHY_TABLE;
extern Symbol* SYM_HIERARCHY_VARIABLE_NAME;
extern Symbol* SYM_HIERARCHY_VARIABLE_TYPE;
extern Symbol* SYM_HIERARCHY_VARIABLE_SPECIALp;
extern Symbol* SYM_HIERARCHY_VARIABLE_CONSTANTp;
extern Symbol* SYM_HIERARCHY_VARIABLE_PUBLICp;
extern Symbol* SYM_HIERARCHY_VARIABLE_AUXILIARYp;
extern Symbol* SYM_HIERARCHY_VARIABLE_GET_VALUE_CODE;
extern Symbol* SYM_HIERARCHY_VARIABLE_SET_VALUE_CODE;
extern Symbol* SYM_HIERARCHY_VARIABLE_VALUE_STACK;
extern Symbol* SYM_HIERARCHY_VARIABLE_DOCUMENTATION;
extern Symbol* SYM_HIERARCHY_VARIABLE_STRINGIFIED_SOURCE;
extern Surrogate* SGT_HIERARCHY_GLOBAL_VARIABLE;
extern Symbol* SYM_HIERARCHY_QUOTATION_TABLE_OFFSET;
extern Surrogate* SGT_HIERARCHY_QUOTED_EXPRESSION;
extern Symbol* SYM_HIERARCHY_CHILD_CONTEXTS;
extern Symbol* SYM_HIERARCHY_ALL_SUPER_CONTEXTS;
extern Symbol* SYM_HIERARCHY_BASE_MODULE;
extern Symbol* SYM_HIERARCHY_CONTEXT_NUMBER;
extern Surrogate* SGT_HIERARCHY_MODULE;
extern Surrogate* SGT_HIERARCHY_WORLD;
extern Symbol* SYM_HIERARCHY_WORLD_NAME;
extern Symbol* SYM_HIERARCHY_SHADOWED_SURROGATES;
extern Symbol* SYM_HIERARCHY_LOGIC_DIALECT;
extern Keyword* KWD_HIERARCHY_KIF;
extern Symbol* SYM_HIERARCHY_CLEARABLEp;
extern Symbol* SYM_HIERARCHY_PARENT_MODULES;
extern Symbol* SYM_HIERARCHY_REQUIRES;
extern Symbol* SYM_HIERARCHY_USES;
extern Symbol* SYM_HIERARCHY_USED_BY;
extern Symbol* SYM_HIERARCHY_MODULE_NATIVE_PACKAGE;
extern Symbol* SYM_HIERARCHY_DIRECTORY_FILE;
extern Symbol* SYM_HIERARCHY_CODE_FILES;
extern Symbol* SYM_HIERARCHY_DEFINITIONS_FILE;
extern Symbol* SYM_HIERARCHY_OPEN_WORLD_ASSUMPTIONp;
extern Symbol* SYM_HIERARCHY_CASE_SENSITIVEp;
extern Symbol* SYM_HIERARCHY_MODULE_NAME;
extern Symbol* SYM_HIERARCHY_MODULE_FULL_NAME;
extern Symbol* SYM_HIERARCHY_MODULE_STRINGIFIED_SOURCE;
extern Symbol* SYM_HIERARCHY_STRINGIFIED_OPTIONS;
extern Symbol* SYM_HIERARCHY_CARDINAL_MODULE;
extern Symbol* SYM_HIERARCHY_SYMBOL_OFFSET_TABLE;
extern Symbol* SYM_HIERARCHY_SURROGATE_OFFSET_TABLE;
extern Symbol* SYM_HIERARCHY_INDEXICAL_OFFSET_TABLE;
extern Symbol* SYM_HIERARCHY_ELABORATED_WORLD;
extern Symbol* SYM_HIERARCHY_PARENT_CONTEXT;
extern Surrogate* SGT_HIERARCHY_CS_VALUE;
extern Surrogate* SGT_HIERARCHY_INTERVAL;
extern Symbol* SYM_HIERARCHY_PARENTS;
extern Symbol* SYM_HIERARCHY_TREE_CHILDREN;
extern Symbol* SYM_HIERARCHY_CHILDREN;
extern Symbol* SYM_HIERARCHY_FIRST_INTERVAL_LOWER_BOUND;
extern Symbol* SYM_HIERARCHY_FIRST_INTERVAL_UPPER_BOUND;
extern Symbol* SYM_HIERARCHY_INITIAL_INTERVAL;
extern Symbol* SYM_HIERARCHY_INTERVALS;
extern Symbol* SYM_HIERARCHY_TOTAL_ANCESTORS;
extern Symbol* SYM_HIERARCHY_LABEL;
extern Symbol* SYM_HIERARCHY_NATIVE_OBJECT;
extern Surrogate* SGT_HIERARCHY_TAXONOMY_NODE;
extern Symbol* SYM_HIERARCHY_INCREMENTAL_MODEp;
extern Symbol* SYM_HIERARCHY_RENUMBER_IF_OUT_OF_NUMBERSp;
extern Symbol* SYM_HIERARCHY_LARGEST_POSTORDER_NUMBER;
extern Symbol* SYM_HIERARCHY_ROOTS;
extern Symbol* SYM_HIERARCHY_BROKEN_LINKS;
extern Surrogate* SGT_HIERARCHY_TAXONOMY_GRAPH;
extern Surrogate* SGT_HIERARCHY_EXCEPTION;
extern Surrogate* SGT_HIERARCHY_STELLA_EXCEPTION;
extern Surrogate* SGT_HIERARCHY_READ_EXCEPTION;
extern Surrogate* SGT_HIERARCHY_UNHANDLED_EXCEPTION;
extern Symbol* SYM_HIERARCHY_FILE_NAME;
extern List* oRECYCLED_INTEGER_WRAPPER_So;
extern Symbol* SYM_HIERARCHY_WRAPPER_VALUE;
extern Surrogate* SGT_HIERARCHY_INTEGER_WRAPPER;
extern List* oRECYCLED_FLOAT_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_FLOAT_WRAPPER;
extern List* oRECYCLED_STRING_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_STRING_WRAPPER;
extern List* oRECYCLED_CHARACTER_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_CHARACTER_WRAPPER;
extern Surrogate* SGT_HIERARCHY_BOOLEAN_WRAPPER;
extern Symbol* SYM_HIERARCHY_NULL_BOOLEAN;
extern Symbol* SYM_HIERARCHY_TRUE;
extern Symbol* SYM_HIERARCHY_FALSE;
extern List* oRECYCLED_FUNCTION_CODE_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_FUNCTION_CODE_WRAPPER;
extern List* oRECYCLED_METHOD_CODE_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_METHOD_CODE_WRAPPER;
extern Transient_Integer_Wrapper* oALL_TRANSIENT_INTEGER_WRAPPER_So;
extern Transient_Integer_Wrapper* oUNUSED_TRANSIENT_INTEGER_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_TRANSIENT_INTEGER_WRAPPER;
extern Transient_Float_Wrapper* oALL_TRANSIENT_FLOAT_WRAPPER_So;
extern Transient_Float_Wrapper* oUNUSED_TRANSIENT_FLOAT_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_TRANSIENT_FLOAT_WRAPPER;
extern List* oRECYCLED_TRANSIENT_STRING_WRAPPER_So;
extern Transient_String_Wrapper* oALL_TRANSIENT_STRING_WRAPPER_So;
extern Transient_String_Wrapper* oUNUSED_TRANSIENT_STRING_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_TRANSIENT_STRING_WRAPPER;
extern Transient_Character_Wrapper* oALL_TRANSIENT_CHARACTER_WRAPPER_So;
extern Transient_Character_Wrapper* oUNUSED_TRANSIENT_CHARACTER_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_TRANSIENT_CHARACTER_WRAPPER;
extern Transient_Function_Code_Wrapper* oALL_TRANSIENT_FUNCTION_CODE_WRAPPER_So;
extern Transient_Function_Code_Wrapper* oUNUSED_TRANSIENT_FUNCTION_CODE_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_TRANSIENT_FUNCTION_CODE_WRAPPER;
extern Transient_Method_Code_Wrapper* oALL_TRANSIENT_METHOD_CODE_WRAPPER_So;
extern Transient_Method_Code_Wrapper* oUNUSED_TRANSIENT_METHOD_CODE_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_TRANSIENT_METHOD_CODE_WRAPPER;
extern Verbatim_String_Wrapper* oALL_VERBATIM_STRING_WRAPPER_So;
extern Verbatim_String_Wrapper* oUNUSED_VERBATIM_STRING_WRAPPER_So;
extern Surrogate* SGT_HIERARCHY_VERBATIM_STRING_WRAPPER;
extern Symbol* SYM_HIERARCHY_ARGUMENT_LIST;
extern Surrogate* SGT_HIERARCHY_LISP_CONS_ITERATOR;
extern Symbol* SYM_HIERARCHY_STATE;
extern Surrogate* SGT_HIERARCHY_OUTPUT_STREAM;
extern Surrogate* SGT_HIERARCHY_INPUT_STREAM;
extern Keyword* KWD_HIERARCHY_SUPERSEDE;
extern Symbol* SYM_HIERARCHY_FILENAME;
extern Symbol* SYM_HIERARCHY_IF_EXISTS_ACTION;
extern Surrogate* SGT_HIERARCHY_OUTPUT_FILE_STREAM;
extern Keyword* KWD_HIERARCHY_ERROR;
extern Symbol* SYM_HIERARCHY_IF_NOT_EXISTS_ACTION;
extern Surrogate* SGT_HIERARCHY_INPUT_FILE_STREAM;
extern Surrogate* SGT_HIERARCHY_OUTPUT_STRING_STREAM;
extern Surrogate* SGT_HIERARCHY_INPUT_STRING_STREAM;

class Object : public gc {
public:
  virtual Iterator* public_slots();
  virtual Surrogate* primary_type();
public:
  virtual void print_object(ostream* stream);
  virtual Object* value_of();
  virtual void propagate_kb_constraints(Context* context);
  virtual void describe_object(Stream* stream, Keyword* mode);
  virtual Object* get_object(Object* type);
  virtual Object* cl_translate_atomic_tree();
  virtual Object* walk_atomic_tree(Standard_Object*& return1);
  virtual void sweep();
  virtual Standard_Object* yield_type_specifier();
  virtual void free();
  virtual Class* primary_class();
  virtual Object* permanentify();
  virtual boolean object_eqlP(Object* y);
  virtual Surrogate* surrogatify();
  virtual boolean deletedP();
  virtual void free_parse_tree();
  virtual void increment_reference_count();
  virtual void decrement_reference_count();
};

class Standard_Object : public Object {
public:
  virtual boolean object_eqlP(Object* y);
  virtual Object* copy_wrapped_literal();
};

class Transient_Mixin {
public:
  virtual boolean transientP_reader();
};

class Reference_Count_Object : public Object {
public:
  int reference_count;
public:
  virtual void increment_reference_count();
  virtual void decrement_reference_count();
};

class Dynamic_Slots_Mixin {
public:
  Key_Value_List* dynamic_slots;
  int bits;
public:
  virtual boolean deletedP_setter(boolean value);
  virtual boolean deletedP();
  virtual boolean badP_reader();
};

class Context_Sensitive_Object : public Standard_Object {
public:
  Context* home_context;
public:
  virtual Module* home_module();
};

class Active_Object : public Context_Sensitive_Object, public Dynamic_Slots_Mixin {
public:
  virtual void free();
};

class Abstract_Iterator : public Standard_Object {
public:
  boolean first_iterationP;
public:
  virtual Abstract_Iterator* allocate_iterator();
  virtual boolean nextP();
  virtual int length();
};

class Iterator : public Abstract_Iterator {
public:
  Object* value;
public:
  virtual boolean emptyP();
  virtual Object* pop();
  virtual List* listify();
public:
  virtual All_Purpose_Iterator* concatenate(Iterator* iterator2);
  virtual boolean memberP(Object* value);
  virtual Iterator* advance(int n);
};

class Cons_Iterator : public Iterator {
public:
  Cons* cons_iterator_cursor;
public:
  virtual void free();
  virtual Object* value_setter(Object* value);
  virtual boolean emptyP();
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

class List_Iterator : public Iterator {
public:
  Cons* list_iterator_cursor;
  List* list_iterator_collection;
public:
  virtual void free();
  virtual Object* value_setter(Object* value);
  virtual boolean emptyP();
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

class Destructive_List_Iterator : public Iterator {
public:
  Cons* the_cons_list;
  Cons* list_iterator_cursor;
public:
  virtual void free();
  virtual void insert(Object* value);
  virtual boolean emptyP();
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

class Set_Iterator : public Iterator {
public:
  Cons* set_iterator_cursor;
  Set* set_iterator_collection;
public:
  virtual void free();
  virtual Object* value_setter(Object* value);
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

class All_Purpose_Iterator : public Iterator {
public:
  Object* key;
public:
  cpp_function_code iterator_next_code;
  cpp_function_code iterator_filter_code;
  cpp_function_code iterator_empty_code;
  Iterator* iterator_nested_iterator;
  Object* iterator_object;
  Object* iterator_second_object;
  int iterator_integer;
  int iterator_second_integer;
  Cons* iterator_cons_list;
public:
  virtual void free();
  virtual boolean terminate_all_purpose_iteratorP();
  virtual boolean emptyP();
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

class Types_To_Classes_Iterator : public Iterator {
public:
  Cons* iterator_cursor;
public:
  virtual Surrogate* primary_type();
  virtual boolean nextP();
};

class Abstract_Dictionary_Iterator : public Abstract_Iterator {
};

class Dictionary_Iterator : public Abstract_Dictionary_Iterator {
public:
  Object* key;
  Object* value;
};

class Property_List_Iterator : public Dictionary_Iterator {
public:
  Cons* plist_iterator_cursor;
  Property_List* plist_iterator_collection;
public:
  virtual Object* key_setter(Object* key);
  virtual Object* value_setter(Object* value);
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

class Kv_List_Iterator : public Dictionary_Iterator {
public:
  Key_Value_List* the_kv_list;
  Kv_Cons* kv_list_iterator_cursor;
public:
  virtual Object* value_setter(Object* value);
  virtual boolean nextP();
  virtual Object* key_setter(Object* key);
  virtual Surrogate* primary_type();
};

class Interval_Iterator : public Abstract_Iterator {
};

class Integer_Interval_Iterator : public Interval_Iterator {
public:
  int value;
public:
  int interval_cursor;
  int lower_bound;
  int upper_bound;
public:
  virtual Reverse_Integer_Interval_Iterator* reverse();
  virtual boolean nextP();
  virtual void initialize_integer_interval_iterator();
  virtual Surrogate* primary_type();
};

class Reverse_Integer_Interval_Iterator : public Interval_Iterator {
public:
  int value;
public:
  int interval_cursor;
  int lower_bound;
  int upper_bound;
public:
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

class String_Iterator : public Abstract_Iterator {
public:
  char value;
public:
  char* the_string;
  int cursor;
  int end;
public:
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

class Abstract_Collection : public Standard_Object {
public:
  virtual Abstract_Iterator* allocate_iterator();
  virtual int length();
};

class Collection : public Abstract_Collection {
public:
  virtual boolean orderedP();
  virtual boolean no_duplicatesP();
  virtual boolean memberP(Object* object);
  virtual Abstract_Iterator* allocate_iterator();
  virtual int length();
  virtual void insert(Object* value);
  virtual Abstract_Collection* remove(Object* value);
public:
  virtual boolean monadicP();
};

class Set_Mixin {
};

class Sequence_Mixin {
};

class Sequence : public Collection, public Sequence_Mixin {
public:
  virtual boolean orderedP();
  virtual Abstract_Iterator* allocate_iterator();
  virtual int length();
public:
  virtual boolean memberP(Object* value);
};

class List : public Sequence {
public:
  Cons* the_cons_list;
public:
  virtual Iterator* but_last();
  virtual List* sort(cpp_function_code predicate);
  virtual List* remove_if(cpp_function_code testP);
  virtual int position(Object* object, int start);
  virtual Cons* rest();
  virtual Object* last();
  virtual Object* fifth();
  virtual Object* fourth();
  virtual Object* third();
  virtual Object* second();
  virtual Object* first();
public:
  virtual void print_object(ostream* stream);
  virtual void free();
  virtual Iterator* allocate_destructive_list_iterator();
  virtual void remove_deleted_members();
  virtual Abstract_Iterator* allocate_iterator();
  virtual void clear();
  virtual List* copy();
  virtual List* prepend(List* list2);
  virtual List* concatenate(List* list2);
  virtual List* substitute(Object* invalue, Object* outvalue);
  virtual List* reverse();
  virtual Object* pop();
  virtual List* remove_duplicates();
  virtual Abstract_Collection* remove(Object* value);
  virtual void insert_last(Object* value);
  virtual void insert_new(Object* value);
  virtual void push(Object* value);
  virtual void insert(Object* value);
  virtual int length();
  virtual Object* nth_setter(Object* value, int position);
  virtual Object* fifth_setter(Object* value);
  virtual Object* fourth_setter(Object* value);
  virtual Object* third_setter(Object* value);
  virtual Object* second_setter(Object* value);
  virtual Object* first_setter(Object* value);
  virtual Object* nth(int position);
  virtual boolean memberP(Object* object);
  virtual boolean non_emptyP();
  virtual boolean emptyP();
  virtual Surrogate* primary_type();
};

class Set : public Collection, public Set_Mixin {
public:
  Cons* the_cons_list;
public:
  virtual void clear();
  virtual Set* copy();
  virtual Set* reverse();
  virtual Abstract_Collection* remove(Object* value);
  virtual void insert(Object* value);
  virtual boolean memberP(Object* object);
  virtual boolean non_emptyP();
  virtual boolean emptyP();
  virtual boolean no_duplicatesP();
public:
  virtual void print_object(ostream* stream);
  virtual void free();
  virtual Abstract_Iterator* allocate_iterator();
  virtual Surrogate* primary_type();
};

class Class_Extension : public List {
public:
  virtual void free();
  virtual Surrogate* primary_type();
};

class Cons : public Standard_Object {
public:
  Object* value;
  Cons* rest;
public:
  virtual Cons* sort(cpp_function_code predicate);
  virtual Iterator* but_last();
  virtual Object* last();
  virtual Cons* nth_rest(int position);
  virtual Object* nth(int position);
  virtual Object* fifth();
  virtual Object* fourth();
  virtual Object* third();
  virtual Object* second();
  virtual Object* first();
  virtual int position(Object* object, int start);
  virtual boolean non_emptyP();
  virtual boolean emptyP();
public:
  virtual void print_object(ostream* stream);
  virtual void free();
  virtual Query_Iterator* retrieve_bindings(int nofbindings);
  virtual Standard_Object* yield_type_specifier();
  virtual Surrogate* surrogatify();
  virtual Iterator* allocate_destructive_list_iterator();
  virtual void free_parse_tree();
  virtual Object* nth_rest_setter(Object* value, int position);
  virtual Object* fifth_setter(Object* value);
  virtual Object* fourth_setter(Object* value);
  virtual Object* nth_setter(Object* value, int position);
  virtual Object* third_setter(Object* value);
  virtual Object* second_setter(Object* value);
  virtual Object* first_setter(Object* value);
  virtual Cons* substitute(Object* invalue, Object* outvalue);
  virtual Cons* reverse();
  virtual Cons* prepend(Cons* list1);
  virtual Cons* concatenate(Cons* list2);
  virtual Cons* remove_duplicates();
  virtual Cons* remove(Object* value);
  virtual boolean membP(Object* object);
  virtual boolean memberP(Object* object);
  virtual int length();
  virtual void free_cons();
  virtual Surrogate* primary_type();
  virtual Cons_Iterator* allocate_iterator();
};

class Transient_Cons : public Cons, public Transient_Mixin {
public:
  Transient_Cons* next_sweep_list_object;
public:
  virtual void print_object(ostream* stream);
  virtual void sweep();
  virtual void free();
  virtual void free_parse_tree();
  virtual void free_cons();
  virtual Surrogate* primary_type();
};

class Abstract_Dictionary : public Abstract_Collection {
public:
  virtual Abstract_Iterator* allocate_iterator();
};

class Dictionary : public Abstract_Dictionary {
public:
  virtual Abstract_Iterator* allocate_iterator();
};

class Property_List : public Dictionary {
public:
  Cons* the_plist;
public:
  virtual void print_object(ostream* stream);
  virtual Abstract_Iterator* allocate_iterator();
  virtual void clear();
  virtual Property_List* copy();
  virtual boolean non_emptyP();
  virtual boolean emptyP();
  virtual Object* remove_at(Object* key);
  virtual void insert_at(Object* key, Object* value);
  virtual int length();
  virtual Object* lookup(Object* key);
  virtual void initialize_object();
  virtual Surrogate* primary_type();
};

class Kv_Cons : public Standard_Object {
public:
  Object* key;
  Object* value;
  Kv_Cons* rest;
public:
  virtual void print_object(ostream* stream);
  virtual Surrogate* primary_type();
};

class Key_Value_List : public Dictionary {
public:
  Kv_Cons* the_kv_list;
public:
  virtual Key_Value_List* reverse();
public:
  virtual void print_object(ostream* stream);
  virtual Abstract_Iterator* allocate_iterator();
  virtual void clear();
  virtual Key_Value_List* copy();
  virtual boolean non_emptyP();
  virtual boolean emptyP();
  virtual Object* pop();
  virtual void remove_entry(Object* key, Object* value);
  virtual void insert_entry(Object* key, Object* value);
  virtual Object* remove_at(Object* key);
  virtual void insert_at(Object* key, Object* value);
  virtual int length();
  virtual Object* lookup(Object* key);
  virtual Surrogate* primary_type();
};

class Abstract_Hash_Table : public Abstract_Dictionary {
public:
  cpp_hash_table* the_hash_table;
public:
  virtual void initialize_hash_table();
  virtual void free_hash_table_values();
};

class Hash_Table : public Abstract_Hash_Table {
public:
  virtual void remove_at(Object* key);
  virtual void insert_at(Object* key, Object* value);
  virtual Object* lookup(Object* key);
  virtual Surrogate* primary_type();
};

class Integer_Hash_Table : public Abstract_Hash_Table {
public:
  virtual void insert_at(int key, Object* value);
  virtual Object* lookup(int key);
  virtual Surrogate* primary_type();
};

class Float_Hash_Table : public Abstract_Hash_Table {
public:
  virtual void insert_at(double key, Object* value);
  virtual Object* lookup(double key);
  virtual Surrogate* primary_type();
};

class String_Hash_Table : public Abstract_Hash_Table {
public:
  virtual void remove_at(char* key);
  virtual void insert_at(char* key, Object* value);
  virtual Object* lookup(char* key);
  virtual void initialize_hash_table();
  virtual Surrogate* primary_type();
};

class String_To_Integer_Hash_Table : public Abstract_Hash_Table {
public:
  virtual void remove_at(char* key);
  virtual void insert_at(char* key, int value);
  virtual int lookup(char* key);
  virtual void initialize_hash_table();
  virtual Surrogate* primary_type();
};

class Vector : public Sequence {
public:
  int array_size;
public:
  cpp_vector* the_array;
public:
  virtual Iterator* but_last();
  virtual Vector* copy();
public:
  virtual void print_object(ostream* stream);
  virtual Abstract_Iterator* allocate_iterator();
  virtual void clear();
  virtual void insert_at(int offset, Object* value);
  virtual boolean memberP(Object* object);
  virtual int length();
  virtual Object* last_setter(Object* value);
  virtual Object* last();
  virtual Object* nth_setter(Object* value, int position);
  virtual Object* nth(int offset);
  virtual Object* fifth();
  virtual Object* fourth();
  virtual Object* third();
  virtual Object* second();
  virtual Object* first();
  virtual boolean non_emptyP();
  virtual boolean emptyP();
  virtual void print_vector(ostream* stream);
  virtual void initialize_vector();
  virtual Surrogate* primary_type();
};

class Extensible_Vector : public Vector {
public:
  virtual void insert_at(int offset, Object* value);
  virtual Surrogate* primary_type();
};

class Extensible_Symbol_Array : public Extensible_Vector {
public:
  int top_symbol_offset;
  int potential_free_symbol_offset;
public:
  virtual void free();
  virtual void insert_at(int offset, Object* value);
  virtual Surrogate* primary_type();
};

class Vector_Sequence : public Vector {
public:
  int sequence_length;
public:
  virtual int length();
  virtual Abstract_Collection* remove(Object* value);
  virtual void insert(Object* value);
  virtual int resize_increment_reader();
};

class Short_Vector_Sequence : public Vector_Sequence {
public:
  virtual Surrogate* primary_type();
  virtual int resize_increment_reader();
};

class Boolean_Vector : public Vector {
public:
  virtual Surrogate* primary_type();
};

class Integer_Vector : public Vector {
public:
  virtual Surrogate* primary_type();
};

class Array : public Abstract_Collection {
public:
  virtual Surrogate* primary_type();
};

class Null_Terminated_Array : public Array {
public:
  virtual int length();
public:
  virtual Surrogate* primary_type();
};

class Active_Collection_Mixin {
public:
  Storage_Slot* active_slot;
  Standard_Object* owner_instance;
};

class Active_List : public List, public Active_Collection_Mixin {
public:
  virtual void free();
  virtual Abstract_Collection* remove(Object* value);
  virtual void insert(Object* value);
  virtual Surrogate* primary_type();
};

class Active_Set : public List, public Set_Mixin, public Active_Collection_Mixin {
public:
  virtual void free();
  virtual Abstract_Collection* remove(Object* value);
  virtual void insert(Object* value);
  virtual Surrogate* primary_type();
};

class Demon : public Standard_Object {
public:
  char* demon_name;
  Keyword* demon_action;
  List* demon_class_refs;
  List* demon_slot_refs;
  cpp_function_code demon_code;
  Method_Slot* demon_method;
  char* demon_documentation;
  boolean demon_guardP;
  boolean demon_allP;
  boolean demon_inheritP;
public:
  virtual Surrogate* primary_type();
};

class List_Of_Slot : public List {
public:
  virtual void free();
  virtual Surrogate* primary_type();
};

class List_Of_Symbol : public List {
public:
  virtual void free();
  virtual Surrogate* primary_type();
};

class List_Of_Keyword : public List {
public:
  virtual void free();
  virtual Surrogate* primary_type();
};

class List_Of_Type : public List {
public:
  virtual void free();
  virtual Surrogate* primary_type();
};

class Keyword_Key_Value_List : public Key_Value_List {
public:
  virtual Surrogate* primary_type();
};

class Generalized_Symbol : public Context_Sensitive_Object {
public:
  char* symbol_name;
  int symbol_id;
public:
  virtual Description* get_description();
public:
  virtual Global_Variable* lookup_global_variable();
  virtual char* visible_name();
  virtual char* relative_name();
  virtual char* local_print_name();
};

class Symbol : public Generalized_Symbol {
public:
  int symbol_slot_offset;
  Cons* symbol_value_and_plist;
public:
  virtual void print_object(ostream* stream);
  virtual Description* get_description();
  virtual Context* slowly_get_context();
  virtual Object* cl_translate_atomic_tree();
  virtual Object* walk_atomic_tree(Standard_Object*& return1);
  virtual Method_Slot* lookup_function();
  virtual Standard_Object* yield_type_specifier();
  virtual Class* get_class(boolean errorP);
  virtual Class* lookup_class();
  virtual Symbol* soft_permanentify();
  virtual Object* permanentify();
  virtual Keyword* keywordify();
  virtual Surrogate* surrogatify();
  virtual Surrogate* primary_type();
};

class Surrogate : public Generalized_Symbol {
public:
  Object* surrogate_value;
public:
  virtual void print_object(ostream* stream);
  virtual Description* get_description();
  virtual Object* value_of();
  virtual Object* cl_translate_atomic_tree();
  virtual Object* walk_atomic_tree(Standard_Object*& return1);
  virtual Surrogate* type_to_wrapped_type();
  virtual Global_Variable* lookup_global_variable();
  virtual Standard_Object* yield_type_specifier();
  virtual void destroy_class();
  virtual Class* get_class(boolean errorP);
  virtual char* local_print_name();
  virtual Surrogate* surrogatify();
  virtual Surrogate* primary_type();
};

class Keyword : public Generalized_Symbol {
public:
  virtual void print_object(ostream* stream);
  virtual Object* cl_translate_atomic_tree();
  virtual Object* walk_atomic_tree(Standard_Object*& return1);
  virtual Object* permanentify();
  virtual Keyword* keywordify();
  virtual Surrogate* primary_type();
};

class Indexical : public Generalized_Symbol {
public:
  Object* indexical_value;
public:
  virtual void print_object(ostream* stream);
  virtual Surrogate* primary_type();
};

class Transient_Symbol : public Symbol, public Transient_Mixin {
public:
  virtual Symbol* soft_permanentify();
  virtual Object* permanentify();
  virtual void free_parse_tree();
  virtual Surrogate* primary_type();
};

class Transient_Keyword : public Keyword, public Transient_Mixin {
public:
  virtual Object* permanentify();
  virtual Keyword* keywordify();
  virtual void free_parse_tree();
  virtual Surrogate* primary_type();
};

class Mappable_Object : public Standard_Object, public Dynamic_Slots_Mixin {
public:
  virtual List* projects_onto_reader();
  virtual List* projected_from_reader();
public:
  virtual boolean deletedP_setter(boolean value);
  virtual boolean deletedP();
};

class Relation : public Mappable_Object {
public:
  boolean abstractP;
public:
  virtual boolean privateP();
  virtual char* name();
  virtual Module* home_module();
  virtual int arity();
  virtual boolean publicP();
  virtual List* direct_supers();
  virtual List* all_supers();
  virtual Iterator* slots();
  virtual List* properties_reader();
public:
  virtual Iterator* direct_superrelations();
  virtual boolean functionP();
  virtual Symbol* self_variable_getter();
  virtual Keyword* logic_dialect();
  virtual void construct_relation_definition();
  virtual Description* get_description();
  virtual Object* value_of();
  virtual boolean primitiveP();
  virtual List* relation_originated_propositions_reader();
  virtual boolean sortP_reader();
  virtual boolean stored_activeP_reader();
};

class Class : public Relation {
public:
  boolean cl_structP;
  boolean mixinP;
public:
  Surrogate* class_type;
  List* class_direct_supers;
  List* class_direct_subs;
  Cons* class_all_super_classes;
  Cons* class_all_slots;
  List* class_local_slots;
  Vector* class_slot_and_method_cache;
  boolean class_collectionP;
  boolean class_publicP;
  boolean class_finalizedP;
  boolean class_slots_finalizedP;
  char* class_stringified_source;
  cpp_function_code class_constructor_code;
  cpp_function_code class_slot_accessor_code;
  boolean class_markedP;
  Taxonomy_Node* class_taxonomy_node;
public:
  virtual Iterator* super_classes();
  virtual Iterator* direct_super_classes();
  virtual char* name();
  virtual Module* home_module();
  virtual int arity();
  virtual boolean publicP();
  virtual boolean activeP();
  virtual Symbol* creator();
  virtual Symbol* initializer();
  virtual Symbol* terminator();
  virtual Symbol* destructor();
  virtual List* required_slots();
  virtual List* parameters();
  virtual Object* initial_value();
  virtual Class_Extension* extension();
  virtual char* cl_native_type();
  virtual char* cpp_native_type();
  virtual char* idl_native_type();
  virtual char* java_native_type();
public:
  virtual void print_object(ostream* stream);
  virtual Iterator* direct_superrelations();
  virtual Slot* get_template_slot(char* slotname);
  virtual boolean primitiveP();
  virtual Description* get_description();
  virtual void describe_object(Stream* stream, Keyword* mode);
  virtual void pretty_print_object(Output_Stream* stream);
  virtual List* local_slots();
  virtual Iterator* class_slots();
  virtual Iterator* all_class_slots();
  virtual Iterator* public_slots();
  virtual boolean multiple_parentsP();
  virtual void destroy_class();
  virtual void unbind_from_surrogate();
  virtual Surrogate* primary_type();
  virtual boolean sortP_reader();
  virtual int class_arity_reader();
  virtual List* class_cl_struct_slots_reader();
  virtual Keyword* class_recycle_method_reader();
  virtual List* class_parameters_reader();
  virtual List* class_required_slot_names_reader();
  virtual List* class_guard_constructor_demons_reader();
  virtual List* class_constructor_demons_reader();
  virtual List* class_guard_destructor_demons_reader();
  virtual List* class_destructor_demons_reader();
  virtual List* class_key_reader();
  virtual List* class_synonyms_reader();
};

class Polymorphic_Relation : public Relation {
public:
  Slot* slot_direct_equivalent;
public:
  virtual Surrogate* owner();
  virtual Symbol* renames();
  virtual boolean activeP();
};

class Slot : public Polymorphic_Relation {
public:
  Symbol* slot_name;
  Surrogate* slot_owner;
  Surrogate* slot_base_type;
  Surrogate* slot_slotref;
  boolean slot_publicP;
  boolean slot_renamedP;
  boolean slot_externalP;
  boolean slot_markedP;
public:
  virtual char* name();
  virtual Module* home_module();
  virtual Surrogate* type();
  virtual Standard_Object* type_specifier();
  virtual Surrogate* owner();
  virtual Symbol* renames();
  virtual boolean single_valuedP();
  virtual Keyword* closure_assumption();
public:
  virtual void print_object(ostream* stream);
  virtual Iterator* direct_superrelations();
  virtual boolean functionP();
  virtual Symbol* value_variable_getter();
  virtual Boolean_Vector* get_indexing_vector();
  virtual List* get_uniqueness_vectors();
  virtual Object* apply_slot_to_native_query_arguments(Vector* arguments);
  virtual boolean primitiveP();
  virtual Description* get_description();
  virtual void evaluate_slot_permutations(Vector* arguments);
  virtual Object* apply_slot_to_native_arguments(Vector* arguments);
  virtual boolean open_worldP();
  virtual boolean closedP();
  virtual void pretty_print_object(Output_Stream* stream);
  virtual Cons* finish_walking_call_slot_tree(Cons* tree, Standard_Object* firstargtype, Standard_Object*& return1);
  virtual Standard_Object* compute_return_type_spec(Standard_Object* firstargtype);
  virtual int method_argument_count();
  virtual Object* system_default_value();
  virtual boolean activeP();
  virtual boolean publicP();
  virtual boolean conforming_signaturesP(Slot* superslot);
  virtual void unfinalize_local_slot();
  virtual void help_finalize_local_slot();
  virtual void finalize_slot_type_computations();
  virtual List* uniquenessvectors_reader();
  virtual boolean index_on_valuesP_reader();
  virtual boolean totalP_reader();
  virtual boolean slot_auxiliaryP_reader();
  virtual List* slot_direct_supers_reader();
  virtual List* slot_direct_subs_reader();
};

class Storage_Slot : public Slot {
public:
  boolean slot_requiredP;
  boolean slot_componentP;
  boolean slot_read_onlyP;
  boolean slot_hardwiredP;
  boolean slot_context_sensitiveP;
public:
  virtual Object* initially();
  virtual Keyword* allocation();
  virtual Object* default_form();
  virtual boolean requiredP();
  virtual boolean componentP();
  virtual Symbol* reader();
  virtual Symbol* writer();
public:
  virtual Boolean_Vector* get_indexing_vector();
  virtual List* get_uniqueness_vectors();
  virtual Object* apply_slot_to_native_query_arguments(Vector* arguments);
  virtual Object* apply_slot_to_native_arguments(Vector* arguments);
  virtual void describe_object(Stream* stream, Keyword* mode);
  virtual void pretty_print_object(Output_Stream* stream);
  virtual Cons* finish_walking_call_slot_tree(Cons* tree, Standard_Object* firstargtype, Standard_Object*& return1);
  virtual Standard_Object* compute_return_type_spec(Standard_Object* firstargtype);
  virtual int arity();
  virtual boolean method_body_argumentP();
  virtual boolean method_variable_argumentsP();
  virtual int method_argument_count();
  virtual Object* system_default_value();
  virtual Object* initial_value();
  virtual boolean dynamic_storageP();
  virtual boolean conforming_signaturesP(Slot* superslot);
  virtual void unfinalize_local_slot();
  virtual void help_finalize_local_slot();
  virtual void finalize_slot_type_computations();
  virtual Surrogate* primary_type();
  virtual Keyword* slot_allocation_reader();
  virtual List* slot_guard_demons_reader();
  virtual List* slot_demons_reader();
  virtual List* slot_accessor_methods_reader();
};

class Method_Slot : public Slot {
public:
  boolean method_setterP;
  List* method_parameter_names;
  List* method_parameter_type_specifiers;
  List* method_return_type_specifiers;
  char* method_stringified_source;
  cpp_method_code method_code;
  cpp_function_code function_code;
  boolean method_functionP;
public:
  virtual boolean setterP();
public:
  virtual void print_object(ostream* stream);
  virtual Symbol* self_variable_getter();
  virtual Object* apply_slot_to_native_query_arguments(Vector* arguments);
  virtual void evaluate_slot_permutations(Vector* originalarguments);
  virtual Object* apply_slot_to_native_arguments(Vector* arguments);
  virtual void print_documentation(Output_Stream* stream, boolean shortP);
  virtual void pretty_print_object(Output_Stream* stream);
  virtual Cons* finish_walking_call_slot_tree(Cons* tree, Standard_Object* firstargtype, Standard_Object*& return1);
  virtual Standard_Object* compute_return_type_spec(Standard_Object* firstargtype);
  virtual int arity();
  virtual int method_argument_count();
  virtual void unfinalize_local_slot();
  virtual void help_finalize_local_slot();
  virtual void finalize_slot_type_computations();
  virtual boolean conforming_signaturesP(Slot* superslot);
  virtual Surrogate* primary_type();
  virtual List* method_parameter_names_reader();
  virtual List* method_parameter_type_specifiers_reader();
  virtual List* method_parameter_directions_reader();
  virtual List* method_return_type_specifiers_reader();
  virtual boolean method_variable_argumentsP_reader();
  virtual boolean method_body_argumentP_reader();
  virtual boolean method_auxiliaryP_reader();
  virtual boolean method_nativeP_reader();
  virtual boolean method_globally_inlineP_reader();
  virtual List* method_inlined_functions_reader();
  virtual boolean method_commandP_reader();
  virtual boolean method_evaluate_argumentsP_reader();
  virtual boolean method_lisp_macroP_reader();
};

class Compound_Type_Specifier : public Standard_Object {
public:
  virtual void print_object(ostream* stream);
};

class Parametric_Type_Specifier : public Compound_Type_Specifier {
public:
  Surrogate* specifier_base_type;
  List* specifier_parameter_types;
  int specifier_sequence_size;
public:
  virtual Standard_Object* yield_type_specifier();
  virtual Surrogate* primary_type();
};

class Transient_Type_Specifier : public Parametric_Type_Specifier, public Transient_Mixin {
public:
  Transient_Type_Specifier* next_sweep_list_object;
public:
  virtual void sweep();
  virtual void free();
  virtual Surrogate* primary_type();
};

class Anchored_Type_Specifier : public Compound_Type_Specifier {
public:
  Symbol* specifier_parameter_name;
public:
  virtual Standard_Object* yield_type_specifier();
  virtual Surrogate* primary_type();
};

class Table : public Slot {
public:
  List* tuple_domains;
public:
  virtual void print_object(ostream* stream);
  virtual Symbol* self_variable_getter();
  virtual int arity();
  virtual int method_argument_count();
  virtual boolean conforming_signaturesP(Slot* superslot);
  virtual Surrogate* primary_type();
  virtual List* relation_parameter_names_reader();
  virtual boolean variable_arityP_reader();
};

class Global_Variable : public Mappable_Object {
public:
  char* documentation;
public:
  Symbol* variable_name;
  Surrogate* variable_type;
  boolean variable_specialP;
  boolean variable_constantP;
  boolean variable_publicP;
  boolean variable_auxiliaryP;
  cpp_function_code variable_get_value_code;
  cpp_function_code variable_set_value_code;
  List* variable_value_stack;
  char* variable_stringified_source;
public:
  virtual char* name();
  virtual Surrogate* type();
public:
  virtual Surrogate* primary_type();
};

class Quoted_Expression : public Standard_Object {
public:
  int quotation_table_offset;
public:
  virtual Surrogate* primary_type();
};

class Context : public Standard_Object, public Dynamic_Slots_Mixin {
public:
  List* child_contexts;
  Cons* all_super_contexts;
  Module* base_module;
  int context_number;
public:
  virtual Context* change_context();
public:
  virtual void print_object(ostream* stream);
  virtual World* get_constraint_propagation_world();
  virtual void react_to_kb_update(Object* object);
  virtual void log_newly_bound_proposition(Proposition* proposition);
  virtual void destroy_context();
  virtual char* context_name();
  virtual Iterator* parent_contexts();
  virtual List* context_assumed_propositions_reader();
};

class Module : public Context {
public:
  List* parent_modules;
  char* documentation;
  List* requires;
  List* uses;
  List* used_by;
  char* module_native_package;
  char* directory_file;
  List* code_files;
  char* definitions_file;
  boolean open_world_assumptionP;
  boolean case_sensitiveP;
public:
  char* module_name;
  char* module_full_name;
  char* module_stringified_source;
  char* stringified_options;
  Module* cardinal_module;
  String_To_Integer_Hash_Table* symbol_offset_table;
  String_To_Integer_Hash_Table* surrogate_offset_table;
  String_To_Integer_Hash_Table* indexical_offset_table;
  World* elaborated_world;
public:
  virtual void destroy_context();
  virtual Module* change_module();
  virtual Iterator* parent_contexts();
  virtual char* native_package();
  virtual char* name();
  virtual Module* parent_module();
  virtual boolean closed_world_assumptionP();
  virtual List* shadowed_surrogates_reader();
  virtual char* module_native_package_reader();
  virtual Keyword* logic_dialect_reader();
  virtual boolean clearableP_reader();
public:
  virtual World* get_constraint_propagation_world();
  virtual void react_to_kb_update(Object* object);
  virtual List* locally_conceived_propositions_getter();
  virtual void unfinalize_module();
  virtual boolean multiple_parentsP();
  virtual void describe_object(Stream* stream, Keyword* mode);
  virtual void print_definition(Stream* stream);
  virtual Surrogate* primary_type();
};

class World : public Context {
public:
  Context* parent_context;
public:
  virtual void destroy_context();
  virtual Iterator* parent_contexts();
public:
  virtual void react_to_kb_update(Object* object);
  virtual void log_newly_bound_proposition(Proposition* proposition);
  virtual List* locally_bound_skolems_getter();
  virtual List* locally_bound_propositions_getter();
  virtual void unfinalize_world();
  virtual Surrogate* primary_type();
  virtual boolean up_to_date_inferencesP_reader();
  virtual boolean truth_maintainedP_reader();
  virtual boolean monotonicP_reader();
};

class Cs_Value : public Key_Value_List {
public:
  virtual void insert_at(Context* context, Object* newvalue);
  virtual Surrogate* primary_type();
};

class Interval : public Standard_Object {
public:
  int lower_bound;
  int upper_bound;
public:
  virtual void print_object(ostream* stream);
  virtual Surrogate* primary_type();
};

class Taxonomy_Node : public Standard_Object {
public:
  Cons* parents;
  Cons* tree_children;
  Cons* children;
  int first_interval_lower_bound;
  int first_interval_upper_bound;
  Interval* initial_interval;
  Cons* intervals;
  int total_ancestors;
  int label;
  Object* native_object;
public:
  virtual void print_object(ostream* stream);
  virtual Surrogate* primary_type();
};

class Taxonomy_Graph : public Standard_Object {
public:
  boolean incremental_modeP;
  boolean renumber_if_out_of_numbersP;
  int largest_postorder_number;
  Cons* roots;
  Cons* broken_links;
public:
  virtual void print_object(ostream* stream);
  virtual Surrogate* primary_type();
};

class Exception : public Standard_Object {
public:
  virtual Surrogate* primary_type();
};

class Stella_Exception : public Exception {
public:
  virtual Surrogate* primary_type();
};

class Read_Exception : public Stella_Exception {
public:
  virtual Surrogate* primary_type();
};

class Unhandled_Exception : public Exception {
public:
  virtual Surrogate* primary_type();
};

class Wrapper : public Object {
public:
  virtual Object* walk_atomic_tree(Standard_Object*& return1);
  virtual boolean terminate_wrapperP();
  virtual void free_parse_tree();
};

class Literal_Wrapper : public Wrapper {
public:
  virtual Object* permanentify();
  virtual Literal_Wrapper* permanentify_literal();
};

class Number_Wrapper : public Literal_Wrapper {
public:
  virtual Number_Wrapper* divide(Number_Wrapper* y);
  virtual Number_Wrapper* times(Number_Wrapper* y);
  virtual Number_Wrapper* minus(Number_Wrapper* y);
  virtual Number_Wrapper* plus(Number_Wrapper* y);
  virtual Boolean_Wrapper* less_or_equalP(Number_Wrapper* y);
  virtual Boolean_Wrapper* less_thanP(Number_Wrapper* y);
  virtual Boolean_Wrapper* greater_or_equalP(Number_Wrapper* y);
  virtual Boolean_Wrapper* greater_thanP(Number_Wrapper* y);
  virtual double number_value();
};

class Integer_Wrapper : public Number_Wrapper {
public:
  int wrapper_value;
public:
  virtual void print_object(ostream* stream);
  virtual void free();
  virtual Literal_Wrapper* permanentify_literal();
  virtual boolean object_eqlP(Object* y);
  virtual Object* copy_wrapped_literal();
  virtual boolean terminate_wrapperP();
  virtual Surrogate* primary_type();
};

class Float_Wrapper : public Number_Wrapper {
public:
  double wrapper_value;
public:
  virtual void print_object(ostream* stream);
  virtual void free();
  virtual Literal_Wrapper* permanentify_literal();
  virtual boolean object_eqlP(Object* y);
  virtual Object* copy_wrapped_literal();
  virtual Surrogate* primary_type();
};

class String_Wrapper : public Literal_Wrapper {
public:
  char* wrapper_value;
public:
  virtual void print_object(ostream* stream);
  virtual void free();
  virtual Literal_Wrapper* permanentify_literal();
  virtual boolean object_eqlP(Object* y);
  virtual Object* copy_wrapped_literal();
  virtual Surrogate* primary_type();
};

class Character_Wrapper : public Literal_Wrapper {
public:
  char wrapper_value;
public:
  virtual void print_object(ostream* stream);
  virtual void free();
  virtual Literal_Wrapper* permanentify_literal();
  virtual boolean object_eqlP(Object* y);
  virtual Object* copy_wrapped_literal();
  virtual Surrogate* primary_type();
};

class Boolean_Wrapper : public Literal_Wrapper {
public:
  boolean wrapper_value;
public:
  virtual void print_object(ostream* stream);
  virtual void free();
  virtual boolean object_eqlP(Object* y);
  virtual Surrogate* primary_type();
};

class Code_Wrapper : public Wrapper {
};

class Function_Code_Wrapper : public Code_Wrapper {
public:
  cpp_function_code wrapper_value;
public:
  virtual void free();
  virtual Function_Code_Wrapper* permanentify_literal();
  virtual Object* copy_wrapped_literal();
  virtual Surrogate* primary_type();
};

class Method_Code_Wrapper : public Code_Wrapper {
public:
  cpp_method_code wrapper_value;
public:
  virtual void free();
  virtual Method_Code_Wrapper* permanentify_literal();
  virtual Object* copy_wrapped_literal();
  virtual Surrogate* primary_type();
};

class Transient_Integer_Wrapper : public Integer_Wrapper, public Transient_Mixin {
public:
  Transient_Integer_Wrapper* next_sweep_list_object;
public:
  virtual void sweep();
  virtual void free();
  virtual void free_parse_tree();
  virtual Surrogate* primary_type();
};

class Transient_Float_Wrapper : public Float_Wrapper, public Transient_Mixin {
public:
  Transient_Float_Wrapper* next_sweep_list_object;
public:
  virtual void sweep();
  virtual void free();
  virtual void free_parse_tree();
  virtual Surrogate* primary_type();
};

class Transient_String_Wrapper : public String_Wrapper, public Transient_Mixin {
public:
  Transient_String_Wrapper* next_sweep_list_object;
public:
  virtual void sweep();
  virtual void free();
  virtual void free_parse_tree();
  virtual Surrogate* primary_type();
};

class Transient_Character_Wrapper : public Character_Wrapper, public Transient_Mixin {
public:
  Transient_Character_Wrapper* next_sweep_list_object;
public:
  virtual void sweep();
  virtual void free();
  virtual void free_parse_tree();
  virtual Surrogate* primary_type();
};

class Transient_Function_Code_Wrapper : public Function_Code_Wrapper, public Transient_Mixin {
public:
  Transient_Function_Code_Wrapper* next_sweep_list_object;
public:
  virtual void sweep();
  virtual void free();
  virtual void free_parse_tree();
  virtual Surrogate* primary_type();
};

class Transient_Method_Code_Wrapper : public Method_Code_Wrapper, public Transient_Mixin {
public:
  Transient_Method_Code_Wrapper* next_sweep_list_object;
public:
  virtual void sweep();
  virtual void free();
  virtual void free_parse_tree();
  virtual Surrogate* primary_type();
};

class Verbatim_String_Wrapper : public Transient_String_Wrapper {
public:
  virtual void print_object(ostream* stream);
  virtual void sweep();
  virtual void free();
  virtual Surrogate* primary_type();
};

class Lisp_Code : public gc {
};

class Lisp_Cons_Iterator : public Iterator {
public:
  cpp_cons* cons_iterator_cursor;
public:
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

class Stream : public Standard_Object {
public:
  Keyword* state;
};

class Output_Stream : public Stream {
public:
  ostream* native_stream;
public:
  virtual Surrogate* primary_type();
};

class Input_Stream : public Stream {
public:
  istream* native_stream;
public:
  virtual Surrogate* primary_type();
};

class Output_File_Stream : public Output_Stream {
public:
  char* filename;
  Keyword* if_exists_action;
public:
  virtual void print_object(ostream* stream);
  virtual void free();
  virtual Surrogate* primary_type();
};

class Input_File_Stream : public Input_Stream {
public:
  char* filename;
  Keyword* if_not_exists_action;
public:
  virtual void print_object(ostream* stream);
  virtual void free();
  virtual Surrogate* primary_type();
};

class Output_String_Stream : public Output_Stream {
public:
  char* the_string;
public:
  virtual Surrogate* primary_type();
};

class Input_String_Stream : public Input_Stream {
public:
  char* the_string;
public:
  virtual Surrogate* primary_type();
};

