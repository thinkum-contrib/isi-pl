// hierarchy.cc

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

#include "stella-includes.hh"

Symbol* SYM_HIERARCHY_TYPE_SPEC = NULL;

boolean oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = FALSE;

Symbol* SYM_HIERARCHY_REFERENCE_COUNT = NULL;

Symbol* SYM_HIERARCHY_BADp = NULL;

Symbol* SYM_HIERARCHY_HOME_CONTEXT = NULL;

Symbol* SYM_HIERARCHY_FIRST_ITERATIONp = NULL;

Symbol* SYM_HIERARCHY_OBJECT_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_CONS_ITERATOR_CURSOR = NULL;

Surrogate* SGT_HIERARCHY_CONS_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_LIST_ITERATOR_CURSOR = NULL;

Symbol* SYM_HIERARCHY_LIST_ITERATOR_COLLECTION = NULL;

Surrogate* SGT_HIERARCHY_LIST_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_THE_CONS_LIST = NULL;

Surrogate* SGT_HIERARCHY_DESTRUCTIVE_LIST_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_SET_ITERATOR_CURSOR = NULL;

Symbol* SYM_HIERARCHY_SET_ITERATOR_COLLECTION = NULL;

Surrogate* SGT_HIERARCHY_SET_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_KEY = NULL;

Symbol* SYM_HIERARCHY_ITERATOR_NEXT_CODE = NULL;

Symbol* SYM_HIERARCHY_ITERATOR_FILTER_CODE = NULL;

Symbol* SYM_HIERARCHY_ITERATOR_EMPTY_CODE = NULL;

Symbol* SYM_HIERARCHY_ITERATOR_NESTED_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_ITERATOR_OBJECT = NULL;

Symbol* SYM_HIERARCHY_ITERATOR_SECOND_OBJECT = NULL;

Symbol* SYM_HIERARCHY_ITERATOR_INTEGER = NULL;

Symbol* SYM_HIERARCHY_ITERATOR_SECOND_INTEGER = NULL;

Symbol* SYM_HIERARCHY_ITERATOR_CONS_LIST = NULL;

Surrogate* SGT_HIERARCHY_ALL_PURPOSE_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_ITERATOR_CURSOR = NULL;

Surrogate* SGT_HIERARCHY_TYPES_TO_CLASSES_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_OBJECT_DICTIONARY_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_PLIST_ITERATOR_CURSOR = NULL;

Symbol* SYM_HIERARCHY_PLIST_ITERATOR_COLLECTION = NULL;

Surrogate* SGT_HIERARCHY_PROPERTY_LIST_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_THE_KV_LIST = NULL;

Symbol* SYM_HIERARCHY_KV_LIST_ITERATOR_CURSOR = NULL;

Surrogate* SGT_HIERARCHY_KV_LIST_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_INTERVAL_CURSOR = NULL;

Symbol* SYM_HIERARCHY_LOWER_BOUND = NULL;

Symbol* SYM_HIERARCHY_UPPER_BOUND = NULL;

Surrogate* SGT_HIERARCHY_INTEGER_INTERVAL_ITERATOR = NULL;

Surrogate* SGT_HIERARCHY_REVERSE_INTEGER_INTERVAL_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_THE_STRING = NULL;

Symbol* SYM_HIERARCHY_CURSOR = NULL;

Symbol* SYM_HIERARCHY_END = NULL;

Surrogate* SGT_HIERARCHY_STRING_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_OBJECT_COLLECTION = NULL;

Symbol* SYM_HIERARCHY_OBJECT_SEQUENCE = NULL;

List* oRECYCLED_LIST_So = NULL;

Surrogate* SGT_HIERARCHY_LIST = NULL;

List* oRECYCLED_SET_So = NULL;

Surrogate* SGT_HIERARCHY_SET = NULL;

Surrogate* SGT_HIERARCHY_CLASS_EXTENSION = NULL;

Cons* oRECYCLED_CONS_So = NULL;

Symbol* SYM_HIERARCHY_VALUE = NULL;

Symbol* SYM_HIERARCHY_REST = NULL;

Surrogate* SGT_HIERARCHY_CONS = NULL;

Transient_Cons* oRECYCLED_TRANSIENT_CONS_So = NULL;

Transient_Cons* oALL_TRANSIENT_CONS_So = NULL;

Transient_Cons* oUNUSED_TRANSIENT_CONS_So = NULL;

Symbol* SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT = NULL;

Surrogate* SGT_HIERARCHY_TRANSIENT_CONS = NULL;

Symbol* SYM_HIERARCHY_OBJECT_TO_OBJECT_DICTIONARY = NULL;

Symbol* SYM_HIERARCHY_THE_PLIST = NULL;

Surrogate* SGT_HIERARCHY_PROPERTY_LIST = NULL;

Surrogate* SGT_HIERARCHY_KV_CONS = NULL;

Surrogate* SGT_HIERARCHY_KEY_VALUE_LIST = NULL;

Surrogate* SGT_HIERARCHY_HASH_TABLE = NULL;

Symbol* SYM_HIERARCHY_OBJECT_TO_OBJECT_HASH_TABLE = NULL;

Surrogate* SGT_HIERARCHY_INTEGER_HASH_TABLE = NULL;

Surrogate* SGT_HIERARCHY_FLOAT_HASH_TABLE = NULL;

Surrogate* SGT_HIERARCHY_STRING_HASH_TABLE = NULL;

Surrogate* SGT_HIERARCHY_STRING_TO_INTEGER_HASH_TABLE = NULL;

Symbol* SYM_HIERARCHY_ARRAY_SIZE = NULL;

Surrogate* SGT_HIERARCHY_VECTOR = NULL;

Surrogate* SGT_HIERARCHY_EXTENSIBLE_VECTOR = NULL;

Symbol* SYM_HIERARCHY_TOP_SYMBOL_OFFSET = NULL;

Symbol* SYM_HIERARCHY_POTENTIAL_FREE_SYMBOL_OFFSET = NULL;

Surrogate* SGT_HIERARCHY_EXTENSIBLE_SYMBOL_ARRAY = NULL;

int oHARDWIRED_RESIZE_INCREMENT_ON_VECTOR_SEQUENCEo = NULL_INTEGER;

Symbol* SYM_HIERARCHY_RESIZE_INCREMENT = NULL;

Symbol* SYM_HIERARCHY_SEQUENCE_LENGTH = NULL;

Symbol* SYM_HIERARCHY_VSEQ = NULL;

int oHARDWIRED_RESIZE_INCREMENT_ON_SHORT_VECTOR_SEQUENCEo = NULL_INTEGER;

Surrogate* SGT_HIERARCHY_SHORT_VECTOR_SEQUENCE = NULL;

Symbol* SYM_HIERARCHY_SVSEQ = NULL;

Surrogate* SGT_HIERARCHY_BOOLEAN_VECTOR = NULL;

Surrogate* SGT_HIERARCHY_INTEGER_VECTOR = NULL;

Surrogate* SGT_HIERARCHY_ARRAY = NULL;

Surrogate* SGT_HIERARCHY_NULL_TERMINATED_ARRAY = NULL;

Surrogate* SGT_HIERARCHY_ACTIVE_LIST = NULL;

Surrogate* SGT_HIERARCHY_ACTIVE_SET = NULL;

Symbol* SYM_HIERARCHY_DEMON_NAME = NULL;

Symbol* SYM_HIERARCHY_DEMON_ACTION = NULL;

Symbol* SYM_HIERARCHY_DEMON_CLASS_REFS = NULL;

Symbol* SYM_HIERARCHY_DEMON_SLOT_REFS = NULL;

Symbol* SYM_HIERARCHY_DEMON_CODE = NULL;

Symbol* SYM_HIERARCHY_DEMON_METHOD = NULL;

Symbol* SYM_HIERARCHY_DEMON_DOCUMENTATION = NULL;

Symbol* SYM_HIERARCHY_DEMON_GUARDp = NULL;

Symbol* SYM_HIERARCHY_DEMON_ALLp = NULL;

Symbol* SYM_HIERARCHY_DEMON_INHERITp = NULL;

Surrogate* SGT_HIERARCHY_DEMON = NULL;

Surrogate* SGT_HIERARCHY_LIST_OF_SLOT = NULL;

Surrogate* SGT_HIERARCHY_LIST_OF_SYMBOL = NULL;

Surrogate* SGT_HIERARCHY_LIST_OF_KEYWORD = NULL;

Surrogate* SGT_HIERARCHY_LIST_OF_TYPE = NULL;

Surrogate* SGT_HIERARCHY_KEYWORD_KEY_VALUE_LIST = NULL;

Symbol* SYM_HIERARCHY_SYMBOL_NAME = NULL;

Symbol* SYM_HIERARCHY_SYMBOL_ID = NULL;

Symbol* SYM_HIERARCHY_INTERNED_IN = NULL;

Symbol* SYM_HIERARCHY_SYMBOL_SLOT_OFFSET = NULL;

Symbol* SYM_HIERARCHY_SYMBOL_VALUE_AND_PLIST = NULL;

Surrogate* SGT_HIERARCHY_SYMBOL = NULL;

Symbol* SYM_HIERARCHY_SURROGATE_VALUE = NULL;

Symbol* SYM_HIERARCHY_SURROGATE_NAME = NULL;

Symbol* SYM_HIERARCHY_TYPE_CLASS = NULL;

Symbol* SYM_HIERARCHY_TYPE_NAME = NULL;

Symbol* SYM_HIERARCHY_SLOTREF_SLOT = NULL;

Surrogate* SGT_HIERARCHY_SURROGATE = NULL;

Symbol* SYM_HIERARCHY_TYPE = NULL;

Symbol* SYM_HIERARCHY_SLOTREF = NULL;

Symbol* SYM_HIERARCHY_KEYWORD_NAME = NULL;

Surrogate* SGT_HIERARCHY_KEYWORD = NULL;

Symbol* SYM_HIERARCHY_INDEXICAL_VALUE = NULL;

Surrogate* SGT_HIERARCHY_INDEXICAL = NULL;

Surrogate* SGT_HIERARCHY_TRANSIENT_SYMBOL = NULL;

Surrogate* SGT_HIERARCHY_TRANSIENT_KEYWORD = NULL;

Symbol* SYM_HIERARCHY_PROJECTS_ONTO = NULL;

Symbol* SYM_HIERARCHY_PROJECTED_FROM = NULL;

Symbol* SYM_HIERARCHY_PROPERTIES = NULL;

Symbol* SYM_HIERARCHY_STORED_ACTIVEp = NULL;

Symbol* SYM_HIERARCHY_ABSTRACTp = NULL;

int oHARDWIRED_CLASS_ARITY_ON_CLASSo = NULL_INTEGER;

Symbol* SYM_HIERARCHY_CLASS_CL_STRUCT_SLOTS = NULL;

Symbol* SYM_HIERARCHY_CLASS_RECYCLE_METHOD = NULL;

Keyword* KWD_HIERARCHY_NONE = NULL;

Symbol* SYM_HIERARCHY_CLASS_PARAMETERS = NULL;

Symbol* SYM_HIERARCHY_CLASS_REQUIRED_SLOT_NAMES = NULL;

Symbol* SYM_HIERARCHY_CLASS_GUARD_CONSTRUCTOR_DEMONS = NULL;

Symbol* SYM_HIERARCHY_CLASS_CONSTRUCTOR_DEMONS = NULL;

Symbol* SYM_HIERARCHY_CLASS_GUARD_DESTRUCTOR_DEMONS = NULL;

Symbol* SYM_HIERARCHY_CLASS_DESTRUCTOR_DEMONS = NULL;

Symbol* SYM_HIERARCHY_CLASS_KEY = NULL;

Symbol* SYM_HIERARCHY_CLASS_SYNONYMS = NULL;

Symbol* SYM_HIERARCHY_CL_STRUCTp = NULL;

Symbol* SYM_HIERARCHY_MIXINp = NULL;

Symbol* SYM_HIERARCHY_CLASS_TYPE = NULL;

Symbol* SYM_HIERARCHY_CLASS_ARITY = NULL;

Symbol* SYM_HIERARCHY_CLASS_DIRECT_SUPERS = NULL;

Symbol* SYM_HIERARCHY_CLASS_DIRECT_SUBS = NULL;

Symbol* SYM_HIERARCHY_CLASS_ALL_SUPER_CLASSES = NULL;

Symbol* SYM_HIERARCHY_CLASS_ALL_SLOTS = NULL;

Symbol* SYM_HIERARCHY_CLASS_LOCAL_SLOTS = NULL;

Symbol* SYM_HIERARCHY_CLASS_SLOT_AND_METHOD_CACHE = NULL;

Symbol* SYM_HIERARCHY_CLASS_ABSTRACTp = NULL;

Symbol* SYM_HIERARCHY_CLASS_MIXINp = NULL;

Symbol* SYM_HIERARCHY_CLASS_COLLECTIONp = NULL;

Symbol* SYM_HIERARCHY_CLASS_CL_STRUCTp = NULL;

Symbol* SYM_HIERARCHY_CLASS_PUBLICp = NULL;

Symbol* SYM_HIERARCHY_CLASS_FINALIZEDp = NULL;

Symbol* SYM_HIERARCHY_CLASS_SLOTS_FINALIZEDp = NULL;

Symbol* SYM_HIERARCHY_CLASS_STRINGIFIED_SOURCE = NULL;

Symbol* SYM_HIERARCHY_CLASS_CONSTRUCTOR_CODE = NULL;

Symbol* SYM_HIERARCHY_CLASS_SLOT_ACCESSOR_CODE = NULL;

Symbol* SYM_HIERARCHY_CLASS_MARKEDp = NULL;

Symbol* SYM_HIERARCHY_CLASS_TAXONOMY_NODE = NULL;

Symbol* SYM_HIERARCHY_CLASS_DOCUMENTATION = NULL;

Symbol* SYM_HIERARCHY_CLASS_PRINT_FORM = NULL;

Symbol* SYM_HIERARCHY_DOCUMENTATION = NULL;

Symbol* SYM_HIERARCHY_PRINT_FORM = NULL;

Surrogate* SGT_HIERARCHY_CLASS = NULL;

Surrogate* SGT_HIERARCHY_ACTIVE_OBJECT = NULL;

Symbol* SYM_HIERARCHY_CLASS_CREATOR = NULL;

Symbol* SYM_HIERARCHY_CLASS_INITIALIZER = NULL;

Symbol* SYM_HIERARCHY_CLASS_TERMINATOR = NULL;

Symbol* SYM_HIERARCHY_CLASS_DESTRUCTOR = NULL;

Symbol* SYM_HIERARCHY_CLASS_INITIAL_VALUE = NULL;

Symbol* SYM_HIERARCHY_CLASS_EXTENSION = NULL;

Symbol* SYM_HIERARCHY_CLASS_CL_NATIVE_TYPE = NULL;

Symbol* SYM_HIERARCHY_CLASS_CPP_NATIVE_TYPE = NULL;

Symbol* SYM_HIERARCHY_CLASS_JAVA_NATIVE_TYPE = NULL;

Symbol* SYM_HIERARCHY_SLOT_DIRECT_EQUIVALENT = NULL;

Symbol* SYM_HIERARCHY_SLOT_AUXILIARYp = NULL;

Symbol* SYM_HIERARCHY_SLOT_DIRECT_SUPERS = NULL;

Symbol* SYM_HIERARCHY_SLOT_DIRECT_SUBS = NULL;

Symbol* SYM_HIERARCHY_SLOT_NAME = NULL;

Symbol* SYM_HIERARCHY_SLOT_OWNER = NULL;

Symbol* SYM_HIERARCHY_SLOT_BASE_TYPE = NULL;

Symbol* SYM_HIERARCHY_SLOT_SLOTREF = NULL;

Symbol* SYM_HIERARCHY_SLOT_PUBLICp = NULL;

Symbol* SYM_HIERARCHY_SLOT_RENAMEDp = NULL;

Symbol* SYM_HIERARCHY_SLOT_EXTERNALp = NULL;

Symbol* SYM_HIERARCHY_SLOT_MARKEDp = NULL;

Symbol* SYM_HIERARCHY_SLOT_DOCUMENTATION = NULL;

Symbol* SYM_HIERARCHY_SLOT_TYPE_SPECIFIER = NULL;

Symbol* SYM_HIERARCHY_SLOT_RENAMES = NULL;

Surrogate* SGT_HIERARCHY_COLLECTION = NULL;

Symbol* SYM_HIERARCHY_SLOT_CLOSURE_ASSUMPTION = NULL;

Symbol* SYM_HIERARCHY_SLOT_ALLOCATION = NULL;

Keyword* KWD_HIERARCHY_INSTANCE = NULL;

Symbol* SYM_HIERARCHY_SLOT_GUARD_DEMONS = NULL;

Symbol* SYM_HIERARCHY_SLOT_DEMONS = NULL;

Symbol* SYM_HIERARCHY_SLOT_ACCESSOR_METHODS = NULL;

Symbol* SYM_HIERARCHY_SLOT_REQUIREDp = NULL;

Symbol* SYM_HIERARCHY_SLOT_COMPONENTp = NULL;

Symbol* SYM_HIERARCHY_SLOT_READ_ONLYp = NULL;

Symbol* SYM_HIERARCHY_SLOT_HARDWIREDp = NULL;

Symbol* SYM_HIERARCHY_SLOT_CONTEXT_SENSITIVEp = NULL;

Surrogate* SGT_HIERARCHY_STORAGE_SLOT = NULL;

Symbol* SYM_HIERARCHY_SLOT_DEFAULT_EXPRESSION = NULL;

Symbol* SYM_HIERARCHY_SLOT_READER = NULL;

Symbol* SYM_HIERARCHY_SLOT_WRITER = NULL;

Symbol* SYM_HIERARCHY_METHOD_PARAMETER_DIRECTIONS = NULL;

Symbol* SYM_HIERARCHY_METHOD_VARIABLE_ARGUMENTSp = NULL;

Symbol* SYM_HIERARCHY_METHOD_BODY_ARGUMENTp = NULL;

Symbol* SYM_HIERARCHY_METHOD_NATIVEp = NULL;

Symbol* SYM_HIERARCHY_METHOD_GLOBALLY_INLINEp = NULL;

Symbol* SYM_HIERARCHY_METHOD_INLINED_FUNCTIONS = NULL;

Symbol* SYM_HIERARCHY_METHOD_COMMANDp = NULL;

Symbol* SYM_HIERARCHY_METHOD_EVALUATE_ARGUMENTSp = NULL;

Symbol* SYM_HIERARCHY_METHOD_LISP_MACROp = NULL;

Symbol* SYM_HIERARCHY_METHOD_SETTERp = NULL;

Symbol* SYM_HIERARCHY_METHOD_PARAMETER_NAMES = NULL;

Symbol* SYM_HIERARCHY_METHOD_PARAMETER_TYPE_SPECIFIERS = NULL;

Symbol* SYM_HIERARCHY_METHOD_RETURN_TYPE_SPECIFIERS = NULL;

Symbol* SYM_HIERARCHY_METHOD_STRINGIFIED_SOURCE = NULL;

Symbol* SYM_HIERARCHY_METHOD_CODE = NULL;

Symbol* SYM_HIERARCHY_FUNCTION_CODE = NULL;

Symbol* SYM_HIERARCHY_METHOD_FUNCTIONp = NULL;

Symbol* SYM_HIERARCHY_METHOD_AUXILIARYp = NULL;

Symbol* SYM_HIERARCHY_METHOD_DOCUMENTATION = NULL;

Symbol* SYM_HIERARCHY_METHOD_STORAGE_SLOT = NULL;

Symbol* SYM_HIERARCHY_STORAGE_SLOT = NULL;

Surrogate* SGT_HIERARCHY_METHOD_SLOT = NULL;

Symbol* SYM_HIERARCHY_FUNCTION = NULL;

Symbol* SYM_HIERARCHY_SPECIFIER_BASE_TYPE = NULL;

Symbol* SYM_HIERARCHY_SPECIFIER_PARAMETER_TYPES = NULL;

Symbol* SYM_HIERARCHY_SPECIFIER_SEQUENCE_SIZE = NULL;

Surrogate* SGT_HIERARCHY_PARAMETRIC_TYPE_SPECIFIER = NULL;

Transient_Type_Specifier* oALL_TRANSIENT_TYPE_SPECIFIER_So = NULL;

Transient_Type_Specifier* oUNUSED_TRANSIENT_TYPE_SPECIFIER_So = NULL;

Surrogate* SGT_HIERARCHY_TRANSIENT_TYPE_SPECIFIER = NULL;

Symbol* SYM_HIERARCHY_SPECIFIER_PARAMETER_NAME = NULL;

Surrogate* SGT_HIERARCHY_ANCHORED_TYPE_SPECIFIER = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_ARITYp = NULL;

Symbol* SYM_HIERARCHY_TUPLE_DOMAINS = NULL;

Surrogate* SGT_HIERARCHY_TABLE = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_NAME = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_TYPE = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_SPECIALp = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_CONSTANTp = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_PUBLICp = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_AUXILIARYp = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_GET_VALUE_CODE = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_SET_VALUE_CODE = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_VALUE_STACK = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_DOCUMENTATION = NULL;

Symbol* SYM_HIERARCHY_VARIABLE_STRINGIFIED_SOURCE = NULL;

Surrogate* SGT_HIERARCHY_GLOBAL_VARIABLE = NULL;

Symbol* SYM_HIERARCHY_QUOTATION_TABLE_OFFSET = NULL;

Surrogate* SGT_HIERARCHY_QUOTED_EXPRESSION = NULL;

Symbol* SYM_HIERARCHY_CHILD_CONTEXTS = NULL;

Symbol* SYM_HIERARCHY_ALL_SUPER_CONTEXTS = NULL;

Symbol* SYM_HIERARCHY_BASE_MODULE = NULL;

Symbol* SYM_HIERARCHY_CONTEXT_NUMBER = NULL;

Surrogate* SGT_HIERARCHY_MODULE = NULL;

Surrogate* SGT_HIERARCHY_WORLD = NULL;

Symbol* SYM_HIERARCHY_WORLD_NAME = NULL;

Symbol* SYM_HIERARCHY_SHADOWED_SURROGATES = NULL;

Symbol* SYM_HIERARCHY_LOGIC_DIALECT = NULL;

Keyword* KWD_HIERARCHY_KIF = NULL;

Symbol* SYM_HIERARCHY_CLEARABLEp = NULL;

Symbol* SYM_HIERARCHY_PARENT_MODULES = NULL;

Symbol* SYM_HIERARCHY_REQUIRES = NULL;

Symbol* SYM_HIERARCHY_USES = NULL;

Symbol* SYM_HIERARCHY_USED_BY = NULL;

Symbol* SYM_HIERARCHY_MODULE_NATIVE_PACKAGE = NULL;

Symbol* SYM_HIERARCHY_DIRECTORY_FILE = NULL;

Symbol* SYM_HIERARCHY_CODE_FILES = NULL;

Symbol* SYM_HIERARCHY_DEFINITIONS_FILE = NULL;

Symbol* SYM_HIERARCHY_OPEN_WORLD_ASSUMPTIONp = NULL;

Symbol* SYM_HIERARCHY_CASE_SENSITIVEp = NULL;

Symbol* SYM_HIERARCHY_MODULE_NAME = NULL;

Symbol* SYM_HIERARCHY_MODULE_FULL_NAME = NULL;

Symbol* SYM_HIERARCHY_MODULE_STRINGIFIED_SOURCE = NULL;

Symbol* SYM_HIERARCHY_STRINGIFIED_OPTIONS = NULL;

Symbol* SYM_HIERARCHY_CARDINAL_MODULE = NULL;

Symbol* SYM_HIERARCHY_SYMBOL_OFFSET_TABLE = NULL;

Symbol* SYM_HIERARCHY_SURROGATE_OFFSET_TABLE = NULL;

Symbol* SYM_HIERARCHY_INDEXICAL_OFFSET_TABLE = NULL;

Symbol* SYM_HIERARCHY_ELABORATED_WORLD = NULL;

Symbol* SYM_HIERARCHY_PARENT_CONTEXT = NULL;

Surrogate* SGT_HIERARCHY_CS_VALUE = NULL;

Surrogate* SGT_HIERARCHY_INTERVAL = NULL;

Symbol* SYM_HIERARCHY_PARENTS = NULL;

Symbol* SYM_HIERARCHY_TREE_CHILDREN = NULL;

Symbol* SYM_HIERARCHY_CHILDREN = NULL;

Symbol* SYM_HIERARCHY_FIRST_INTERVAL_LOWER_BOUND = NULL;

Symbol* SYM_HIERARCHY_FIRST_INTERVAL_UPPER_BOUND = NULL;

Symbol* SYM_HIERARCHY_INITIAL_INTERVAL = NULL;

Symbol* SYM_HIERARCHY_INTERVALS = NULL;

Symbol* SYM_HIERARCHY_TOTAL_ANCESTORS = NULL;

Symbol* SYM_HIERARCHY_LABEL = NULL;

Symbol* SYM_HIERARCHY_NATIVE_OBJECT = NULL;

Surrogate* SGT_HIERARCHY_TAXONOMY_NODE = NULL;

Symbol* SYM_HIERARCHY_INCREMENTAL_MODEp = NULL;

Symbol* SYM_HIERARCHY_RENUMBER_IF_OUT_OF_NUMBERSp = NULL;

Symbol* SYM_HIERARCHY_LARGEST_POSTORDER_NUMBER = NULL;

Symbol* SYM_HIERARCHY_ROOTS = NULL;

Symbol* SYM_HIERARCHY_BROKEN_LINKS = NULL;

Surrogate* SGT_HIERARCHY_TAXONOMY_GRAPH = NULL;

Surrogate* SGT_HIERARCHY_EXCEPTION = NULL;

Surrogate* SGT_HIERARCHY_STELLA_EXCEPTION = NULL;

Surrogate* SGT_HIERARCHY_READ_EXCEPTION = NULL;

Surrogate* SGT_HIERARCHY_UNHANDLED_EXCEPTION = NULL;

Symbol* SYM_HIERARCHY_FILE_NAME = NULL;

List* oRECYCLED_INTEGER_WRAPPER_So = NULL;

Symbol* SYM_HIERARCHY_WRAPPER_VALUE = NULL;

Surrogate* SGT_HIERARCHY_INTEGER_WRAPPER = NULL;

List* oRECYCLED_FLOAT_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_FLOAT_WRAPPER = NULL;

List* oRECYCLED_STRING_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_STRING_WRAPPER = NULL;

List* oRECYCLED_CHARACTER_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_CHARACTER_WRAPPER = NULL;

Surrogate* SGT_HIERARCHY_BOOLEAN_WRAPPER = NULL;

Symbol* SYM_HIERARCHY_NULL_BOOLEAN = NULL;

Symbol* SYM_HIERARCHY_TRUE = NULL;

Symbol* SYM_HIERARCHY_FALSE = NULL;

List* oRECYCLED_FUNCTION_CODE_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_FUNCTION_CODE_WRAPPER = NULL;

List* oRECYCLED_METHOD_CODE_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_METHOD_CODE_WRAPPER = NULL;

Transient_Integer_Wrapper* oALL_TRANSIENT_INTEGER_WRAPPER_So = NULL;

Transient_Integer_Wrapper* oUNUSED_TRANSIENT_INTEGER_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_TRANSIENT_INTEGER_WRAPPER = NULL;

Transient_Float_Wrapper* oALL_TRANSIENT_FLOAT_WRAPPER_So = NULL;

Transient_Float_Wrapper* oUNUSED_TRANSIENT_FLOAT_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_TRANSIENT_FLOAT_WRAPPER = NULL;

List* oRECYCLED_TRANSIENT_STRING_WRAPPER_So = NULL;

Transient_String_Wrapper* oALL_TRANSIENT_STRING_WRAPPER_So = NULL;

Transient_String_Wrapper* oUNUSED_TRANSIENT_STRING_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_TRANSIENT_STRING_WRAPPER = NULL;

Transient_Character_Wrapper* oALL_TRANSIENT_CHARACTER_WRAPPER_So = NULL;

Transient_Character_Wrapper* oUNUSED_TRANSIENT_CHARACTER_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_TRANSIENT_CHARACTER_WRAPPER = NULL;

Transient_Function_Code_Wrapper* oALL_TRANSIENT_FUNCTION_CODE_WRAPPER_So = NULL;

Transient_Function_Code_Wrapper* oUNUSED_TRANSIENT_FUNCTION_CODE_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_TRANSIENT_FUNCTION_CODE_WRAPPER = NULL;

Transient_Method_Code_Wrapper* oALL_TRANSIENT_METHOD_CODE_WRAPPER_So = NULL;

Transient_Method_Code_Wrapper* oUNUSED_TRANSIENT_METHOD_CODE_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_TRANSIENT_METHOD_CODE_WRAPPER = NULL;

Verbatim_String_Wrapper* oALL_VERBATIM_STRING_WRAPPER_So = NULL;

Verbatim_String_Wrapper* oUNUSED_VERBATIM_STRING_WRAPPER_So = NULL;

Surrogate* SGT_HIERARCHY_VERBATIM_STRING_WRAPPER = NULL;

Symbol* SYM_HIERARCHY_ARGUMENT_LIST = NULL;

Surrogate* SGT_HIERARCHY_LISP_CONS_ITERATOR = NULL;

Symbol* SYM_HIERARCHY_STATE = NULL;

Surrogate* SGT_HIERARCHY_OUTPUT_STREAM = NULL;

Surrogate* SGT_HIERARCHY_INPUT_STREAM = NULL;

Keyword* KWD_HIERARCHY_SUPERSEDE = NULL;

Symbol* SYM_HIERARCHY_FILENAME = NULL;

Symbol* SYM_HIERARCHY_IF_EXISTS_ACTION = NULL;

Surrogate* SGT_HIERARCHY_OUTPUT_FILE_STREAM = NULL;

Keyword* KWD_HIERARCHY_ERROR = NULL;

Symbol* SYM_HIERARCHY_IF_NOT_EXISTS_ACTION = NULL;

Surrogate* SGT_HIERARCHY_INPUT_FILE_STREAM = NULL;

Surrogate* SGT_HIERARCHY_OUTPUT_STRING_STREAM = NULL;

Surrogate* SGT_HIERARCHY_INPUT_STRING_STREAM = NULL;

Surrogate* Object::primary_type() {
  // Returns the primary type of 'self'.
  // Gets defined automatically for every non-abstract subclass of OBJECT.
  { Object* self = this;

    return (NULL);
  }
}

void Object::increment_reference_count() {
  { Object* self = this;

  }
}

void Object::decrement_reference_count() {
  { Object* self = this;

  }
}

void Object::print_object(ostream* stream) {
  { Object* self = this;

    *(stream) << "|i|" << self->primary_type();
  }
}

ostream& operator<< (ostream& stream, Object* self) {
  self->print_object(&stream);
  return (stream);
}

boolean Transient_Mixin::transientP_reader() {
  { Transient_Mixin* self = this;

    return (oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo);
  }
}

Object* access_reference_count_object_slot_value(Reference_Count_Object* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_REFERENCE_COUNT) {
    if (setvalueP) {
      self->reference_count = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->reference_count));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

void Reference_Count_Object::increment_reference_count() {
  { Reference_Count_Object* self = this;

    self->reference_count = self->reference_count + 1;
  }
}

void Reference_Count_Object::decrement_reference_count() {
  { Reference_Count_Object* self = this;

    self->reference_count = self->reference_count - 1;
  }
}

boolean Dynamic_Slots_Mixin::badP_reader() {
  { Dynamic_Slots_Mixin* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_BADp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_context_sensitive_object_slot_value(Context_Sensitive_Object* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_HOME_CONTEXT) {
    if (setvalueP) {
      self->home_context = ((Context*)(value));
    }
    else {
      return (self->home_context);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Module* Context_Sensitive_Object::home_module() {
  { Context_Sensitive_Object* self = this;

    return (((Module*)(self->home_context)));
  }
}

Object* access_active_object_slot_value(Active_Object* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (TRUE) {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Object* access_abstract_iterator_slot_value(Abstract_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_FIRST_ITERATIONp) {
    if (setvalueP) {
      self->first_iterationP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->first_iterationP));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

boolean Abstract_Iterator::nextP() {
  { Abstract_Iterator* self = this;

    return (FALSE);
  }
}

Cons_Iterator* new_cons_iterator() {
  { Cons_Iterator* self = NULL;

    self = new Cons_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->cons_iterator_cursor = NULL;
    return (self);
  }
}

void Cons_Iterator::free() {
  { Cons_Iterator* self = this;

    if (terminate_cons_iteratorP(self)) {
      unmake(self);
    }
  }
}

Object* access_cons_iterator_slot_value(Cons_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_CONS_ITERATOR_CURSOR) {
    if (setvalueP) {
      self->cons_iterator_cursor = ((Cons*)(value));
    }
    else {
      return (self->cons_iterator_cursor);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Cons_Iterator::primary_type() {
  { Cons_Iterator* self = this;

    return (SGT_HIERARCHY_CONS_ITERATOR);
  }
}

List_Iterator* new_list_iterator() {
  { List_Iterator* self = NULL;

    self = new List_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->list_iterator_collection = NULL;
    self->list_iterator_cursor = NULL;
    return (self);
  }
}

void List_Iterator::free() {
  { List_Iterator* self = this;

    if (terminate_list_iteratorP(self)) {
      unmake(self);
    }
  }
}

Object* access_list_iterator_slot_value(List_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_LIST_ITERATOR_CURSOR) {
    if (setvalueP) {
      self->list_iterator_cursor = ((Cons*)(value));
    }
    else {
      return (self->list_iterator_cursor);
    }
  }
  else if (slotname == SYM_HIERARCHY_LIST_ITERATOR_COLLECTION) {
    if (setvalueP) {
      self->list_iterator_collection = ((List*)(value));
    }
    else {
      return (self->list_iterator_collection);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* List_Iterator::primary_type() {
  { List_Iterator* self = this;

    return (SGT_HIERARCHY_LIST_ITERATOR);
  }
}

Destructive_List_Iterator* new_destructive_list_iterator() {
  { Destructive_List_Iterator* self = NULL;

    self = new Destructive_List_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->list_iterator_cursor = NULL;
    self->the_cons_list = NIL;
    return (self);
  }
}

void Destructive_List_Iterator::free() {
  { Destructive_List_Iterator* self = this;

    if (terminate_destructive_list_iteratorP(self)) {
      unmake(self);
    }
  }
}

Object* access_destructive_list_iterator_slot_value(Destructive_List_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_THE_CONS_LIST) {
    if (setvalueP) {
      self->the_cons_list = ((Cons*)(value));
    }
    else {
      return (self->the_cons_list);
    }
  }
  else if (slotname == SYM_HIERARCHY_LIST_ITERATOR_CURSOR) {
    if (setvalueP) {
      self->list_iterator_cursor = ((Cons*)(value));
    }
    else {
      return (self->list_iterator_cursor);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Destructive_List_Iterator::primary_type() {
  { Destructive_List_Iterator* self = this;

    return (SGT_HIERARCHY_DESTRUCTIVE_LIST_ITERATOR);
  }
}

Set_Iterator* new_set_iterator() {
  { Set_Iterator* self = NULL;

    self = new Set_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->set_iterator_collection = NULL;
    self->set_iterator_cursor = NULL;
    return (self);
  }
}

void Set_Iterator::free() {
  { Set_Iterator* self = this;

    if (terminate_set_iteratorP(self)) {
      unmake(self);
    }
  }
}

Object* access_set_iterator_slot_value(Set_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_SET_ITERATOR_CURSOR) {
    if (setvalueP) {
      self->set_iterator_cursor = ((Cons*)(value));
    }
    else {
      return (self->set_iterator_cursor);
    }
  }
  else if (slotname == SYM_HIERARCHY_SET_ITERATOR_COLLECTION) {
    if (setvalueP) {
      self->set_iterator_collection = ((Set*)(value));
    }
    else {
      return (self->set_iterator_collection);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Set_Iterator::primary_type() {
  { Set_Iterator* self = this;

    return (SGT_HIERARCHY_SET_ITERATOR);
  }
}

All_Purpose_Iterator* new_all_purpose_iterator() {
  { All_Purpose_Iterator* self = NULL;

    self = new All_Purpose_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->iterator_cons_list = NULL;
    self->iterator_second_integer = NULL_INTEGER;
    self->iterator_integer = NULL_INTEGER;
    self->iterator_second_object = NULL;
    self->iterator_object = NULL;
    self->iterator_nested_iterator = NULL;
    self->iterator_empty_code = NULL;
    self->iterator_filter_code = NULL;
    self->iterator_next_code = NULL;
    self->key = NULL;
    return (self);
  }
}

void All_Purpose_Iterator::free() {
  { All_Purpose_Iterator* self = this;

    if (self->terminate_all_purpose_iteratorP()) {
      unmake(self);
    }
  }
}

Object* access_all_purpose_iterator_slot_value(All_Purpose_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_KEY) {
    if (setvalueP) {
      self->key = value;
    }
    else {
      return (self->key);
    }
  }
  else if (slotname == SYM_HIERARCHY_ITERATOR_NEXT_CODE) {
    if (setvalueP) {
      self->iterator_next_code = ((Function_Code_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (function_code_wrap_literal(self->iterator_next_code));
    }
  }
  else if (slotname == SYM_HIERARCHY_ITERATOR_FILTER_CODE) {
    if (setvalueP) {
      self->iterator_filter_code = ((Function_Code_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (function_code_wrap_literal(self->iterator_filter_code));
    }
  }
  else if (slotname == SYM_HIERARCHY_ITERATOR_EMPTY_CODE) {
    if (setvalueP) {
      self->iterator_empty_code = ((Function_Code_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (function_code_wrap_literal(self->iterator_empty_code));
    }
  }
  else if (slotname == SYM_HIERARCHY_ITERATOR_NESTED_ITERATOR) {
    if (setvalueP) {
      self->iterator_nested_iterator = ((Iterator*)(value));
    }
    else {
      return (self->iterator_nested_iterator);
    }
  }
  else if (slotname == SYM_HIERARCHY_ITERATOR_OBJECT) {
    if (setvalueP) {
      self->iterator_object = value;
    }
    else {
      return (self->iterator_object);
    }
  }
  else if (slotname == SYM_HIERARCHY_ITERATOR_SECOND_OBJECT) {
    if (setvalueP) {
      self->iterator_second_object = value;
    }
    else {
      return (self->iterator_second_object);
    }
  }
  else if (slotname == SYM_HIERARCHY_ITERATOR_INTEGER) {
    if (setvalueP) {
      self->iterator_integer = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->iterator_integer));
    }
  }
  else if (slotname == SYM_HIERARCHY_ITERATOR_SECOND_INTEGER) {
    if (setvalueP) {
      self->iterator_second_integer = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->iterator_second_integer));
    }
  }
  else if (slotname == SYM_HIERARCHY_ITERATOR_CONS_LIST) {
    if (setvalueP) {
      self->iterator_cons_list = ((Cons*)(value));
    }
    else {
      return (self->iterator_cons_list);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* All_Purpose_Iterator::primary_type() {
  { All_Purpose_Iterator* self = this;

    return (SGT_HIERARCHY_ALL_PURPOSE_ITERATOR);
  }
}

Types_To_Classes_Iterator* new_types_to_classes_iterator(Cons* iterator_cursor) {
  { Types_To_Classes_Iterator* self = NULL;

    self = new Types_To_Classes_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->iterator_cursor = iterator_cursor;
    return (self);
  }
}

Object* access_types_to_classes_iterator_slot_value(Types_To_Classes_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_ITERATOR_CURSOR) {
    if (setvalueP) {
      self->iterator_cursor = ((Cons*)(value));
    }
    else {
      return (self->iterator_cursor);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Types_To_Classes_Iterator::primary_type() {
  { Types_To_Classes_Iterator* self = this;

    return (SGT_HIERARCHY_TYPES_TO_CLASSES_ITERATOR);
  }
}

boolean Types_To_Classes_Iterator::nextP() {
  { Types_To_Classes_Iterator* self = this;

    if (self->first_iterationP) {
      self->first_iterationP = FALSE;
    }
    else {
      self->iterator_cursor = self->iterator_cursor->rest;
    }
    if (self->iterator_cursor->non_emptyP()) {
      self->value = ((Class*)(((Surrogate*)(self->iterator_cursor->first()))->surrogate_value));
      return (TRUE);
    }
    else {
      return (FALSE);
    }
  }
}

Property_List_Iterator* new_property_list_iterator() {
  { Property_List_Iterator* self = NULL;

    self = new Property_List_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->key = NULL;
    self->plist_iterator_collection = NULL;
    self->plist_iterator_cursor = NULL;
    return (self);
  }
}

Object* access_property_list_iterator_slot_value(Property_List_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_PLIST_ITERATOR_CURSOR) {
    if (setvalueP) {
      self->plist_iterator_cursor = ((Cons*)(value));
    }
    else {
      return (self->plist_iterator_cursor);
    }
  }
  else if (slotname == SYM_HIERARCHY_PLIST_ITERATOR_COLLECTION) {
    if (setvalueP) {
      self->plist_iterator_collection = ((Property_List*)(value));
    }
    else {
      return (self->plist_iterator_collection);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Property_List_Iterator::primary_type() {
  { Property_List_Iterator* self = this;

    return (SGT_HIERARCHY_PROPERTY_LIST_ITERATOR);
  }
}

Kv_List_Iterator* new_kv_list_iterator() {
  { Kv_List_Iterator* self = NULL;

    self = new Kv_List_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->key = NULL;
    self->kv_list_iterator_cursor = NULL;
    self->the_kv_list = NULL;
    return (self);
  }
}

Object* access_kv_list_iterator_slot_value(Kv_List_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_THE_KV_LIST) {
    if (setvalueP) {
      self->the_kv_list = ((Key_Value_List*)(value));
    }
    else {
      return (self->the_kv_list);
    }
  }
  else if (slotname == SYM_HIERARCHY_KV_LIST_ITERATOR_CURSOR) {
    if (setvalueP) {
      self->kv_list_iterator_cursor = ((Kv_Cons*)(value));
    }
    else {
      return (self->kv_list_iterator_cursor);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Kv_List_Iterator::primary_type() {
  { Kv_List_Iterator* self = this;

    return (SGT_HIERARCHY_KV_LIST_ITERATOR);
  }
}

Integer_Interval_Iterator* new_integer_interval_iterator(int lower_bound, int upper_bound) {
  { Integer_Interval_Iterator* self = NULL;

    self = new Integer_Interval_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL_INTEGER;
    self->interval_cursor = NULL_INTEGER;
    self->lower_bound = lower_bound;
    self->upper_bound = upper_bound;
    self->initialize_integer_interval_iterator();
    return (self);
  }
}

Object* access_integer_interval_iterator_slot_value(Integer_Interval_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_INTERVAL_CURSOR) {
    if (setvalueP) {
      self->interval_cursor = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->interval_cursor));
    }
  }
  else if (slotname == SYM_HIERARCHY_LOWER_BOUND) {
    if (setvalueP) {
      self->lower_bound = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->lower_bound));
    }
  }
  else if (slotname == SYM_HIERARCHY_UPPER_BOUND) {
    if (setvalueP) {
      self->upper_bound = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->upper_bound));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Integer_Interval_Iterator::primary_type() {
  { Integer_Interval_Iterator* self = this;

    return (SGT_HIERARCHY_INTEGER_INTERVAL_ITERATOR);
  }
}

Reverse_Integer_Interval_Iterator* new_reverse_integer_interval_iterator(int lower_bound, int upper_bound) {
  { Reverse_Integer_Interval_Iterator* self = NULL;

    self = new Reverse_Integer_Interval_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL_INTEGER;
    self->interval_cursor = NULL_INTEGER;
    self->lower_bound = lower_bound;
    self->upper_bound = upper_bound;
    initialize_reverse_integer_interval_iterator(self);
    return (self);
  }
}

Object* access_reverse_integer_interval_iterator_slot_value(Reverse_Integer_Interval_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_INTERVAL_CURSOR) {
    if (setvalueP) {
      self->interval_cursor = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->interval_cursor));
    }
  }
  else if (slotname == SYM_HIERARCHY_LOWER_BOUND) {
    if (setvalueP) {
      self->lower_bound = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->lower_bound));
    }
  }
  else if (slotname == SYM_HIERARCHY_UPPER_BOUND) {
    if (setvalueP) {
      self->upper_bound = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->upper_bound));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Reverse_Integer_Interval_Iterator::primary_type() {
  { Reverse_Integer_Interval_Iterator* self = this;

    return (SGT_HIERARCHY_REVERSE_INTEGER_INTERVAL_ITERATOR);
  }
}

String_Iterator* new_string_iterator() {
  { String_Iterator* self = NULL;

    self = new String_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL_CHARACTER;
    self->end = NULL_INTEGER;
    self->cursor = NULL_INTEGER;
    self->the_string = NULL;
    return (self);
  }
}

Object* access_string_iterator_slot_value(String_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_THE_STRING) {
    if (setvalueP) {
      self->the_string = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->the_string));
    }
  }
  else if (slotname == SYM_HIERARCHY_CURSOR) {
    if (setvalueP) {
      self->cursor = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->cursor));
    }
  }
  else if (slotname == SYM_HIERARCHY_END) {
    if (setvalueP) {
      self->end = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->end));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* String_Iterator::primary_type() {
  { String_Iterator* self = this;

    return (SGT_HIERARCHY_STRING_ITERATOR);
  }
}

Abstract_Iterator* Abstract_Collection::allocate_iterator() {
  { Abstract_Collection* self = this;

    return (NULL);
  }
}

int Abstract_Collection::length() {
  { Abstract_Collection* self = this;

    return (NULL_INTEGER);
  }
}

Abstract_Iterator* Collection::allocate_iterator() {
  { Collection* self = this;

    return (NULL);
  }
}

int Collection::length() {
  { Collection* self = this;

    return (NULL_INTEGER);
  }
}

void Collection::insert(Object* value) {
  { Collection* self = this;

    return;
  }
}

Abstract_Collection* Collection::remove(Object* value) {
  { Collection* self = this;

    return (NULL);
  }
}

Abstract_Iterator* Sequence::allocate_iterator() {
  { Sequence* self = this;

    return (NULL);
  }
}

int Sequence::length() {
  { Sequence* sequence = this;

    return (NULL_INTEGER);
  }
}

List* new_list() {
  { List* self = NULL;

    self = ((List*)(oRECYCLED_LIST_So->pop()));
    if (self != NULL) {
    }
    else {
      self = new List;
    }
    self->the_cons_list = NIL;
    return (self);
  }
}

void List::free() {
  { List* self = this;

    if (!(terminate_listP(self))) {
      return;
    }
    oRECYCLED_LIST_So->push(self);
  }
}

Object* access_list_slot_value(List* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_THE_CONS_LIST) {
    if (setvalueP) {
      self->the_cons_list = ((Cons*)(value));
    }
    else {
      return (self->the_cons_list);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* List::primary_type() {
  { List* self = this;

    return (SGT_HIERARCHY_LIST);
  }
}

void List::print_object(ostream* stream) {
  { List* self = this;

    print_cons_list(self->the_cons_list, stream);
  }
}

Set* new_set() {
  { Set* self = NULL;

    self = ((Set*)(oRECYCLED_SET_So->pop()));
    if (self != NULL) {
    }
    else {
      self = new Set;
    }
    self->the_cons_list = NIL;
    return (self);
  }
}

void Set::free() {
  { Set* self = this;

    if (!(terminate_setP(self))) {
      return;
    }
    oRECYCLED_SET_So->push(self);
  }
}

Object* access_set_slot_value(Set* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_THE_CONS_LIST) {
    if (setvalueP) {
      self->the_cons_list = ((Cons*)(value));
    }
    else {
      return (self->the_cons_list);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Set::primary_type() {
  { Set* self = this;

    return (SGT_HIERARCHY_SET);
  }
}

void Set::print_object(ostream* stream) {
  { Set* self = this;

    print_cons_list(self->the_cons_list, stream);
  }
}

Class_Extension* new_class_extension() {
  { Class_Extension* self = NULL;

    self = new Class_Extension;
    self->the_cons_list = NIL;
    return (self);
  }
}

void Class_Extension::free() {
  { Class_Extension* self = this;

    if (terminate_listP(self)) {
      unmake(self);
    }
  }
}

Surrogate* Class_Extension::primary_type() {
  { Class_Extension* self = this;

    return (SGT_HIERARCHY_CLASS_EXTENSION);
  }
}

Cons* new_cons() {
  { Cons* self = NULL;

    self = oRECYCLED_CONS_So;
    if (self != NULL) {
      oRECYCLED_CONS_So = self->rest;
    }
    else {
      self = new Cons;
    }
    self->rest = NIL;
    self->value = NULL;
    return (self);
  }
}

void Cons::free() {
  { Cons* self = this;

    self->rest = oRECYCLED_CONS_So;
    oRECYCLED_CONS_So = self;
  }
}

Object* access_cons_slot_value(Cons* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_VALUE) {
    if (setvalueP) {
      self->value = value;
    }
    else {
      return (self->value);
    }
  }
  else if (slotname == SYM_HIERARCHY_REST) {
    if (setvalueP) {
      self->rest = ((Cons*)(value));
    }
    else {
      return (self->rest);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Cons::primary_type() {
  { Cons* self = this;

    return (SGT_HIERARCHY_CONS);
  }
}

void Cons::print_object(ostream* stream) {
  { Cons* self = this;

    print_cons(self, stream, "{", "}");
  }
}

Transient_Cons* new_transient_cons() {
  { Transient_Cons* self = NULL;

    self = oRECYCLED_TRANSIENT_CONS_So;
    if (self != NULL) {
      oRECYCLED_TRANSIENT_CONS_So = ((Transient_Cons*)(self->rest));
    }
    else if (oUNUSED_TRANSIENT_CONS_So != NULL) {
      self = oUNUSED_TRANSIENT_CONS_So;
      oUNUSED_TRANSIENT_CONS_So = oUNUSED_TRANSIENT_CONS_So->next_sweep_list_object;
    }
    else {
      self = new Transient_Cons;
      self->next_sweep_list_object = oALL_TRANSIENT_CONS_So;
      oALL_TRANSIENT_CONS_So = self;
    }
    self->rest = NIL;
    self->value = NULL;
    return (self);
  }
}

void Transient_Cons::free() {
  { Transient_Cons* self = this;

    self->rest = oRECYCLED_TRANSIENT_CONS_So;
    oRECYCLED_TRANSIENT_CONS_So = self;
  }
}

void Transient_Cons::sweep() {
  { Transient_Cons* self = this;

    oRECYCLED_TRANSIENT_CONS_So = NULL;
    oUNUSED_TRANSIENT_CONS_So = oALL_TRANSIENT_CONS_So;
  }
}

Object* access_transient_cons_slot_value(Transient_Cons* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT) {
    if (setvalueP) {
      self->next_sweep_list_object = ((Transient_Cons*)(value));
    }
    else {
      return (self->next_sweep_list_object);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Transient_Cons::primary_type() {
  { Transient_Cons* self = this;

    return (SGT_HIERARCHY_TRANSIENT_CONS);
  }
}

void Transient_Cons::print_object(ostream* stream) {
  { Transient_Cons* self = this;

    print_cons(self, stream, "[", "]");
  }
}

Abstract_Iterator* Abstract_Dictionary::allocate_iterator() {
  { Abstract_Dictionary* self = this;

    return (NULL);
  }
}

Abstract_Iterator* Dictionary::allocate_iterator() {
  { Dictionary* self = this;

    return (NULL);
  }
}

Property_List* new_property_list() {
  { Property_List* self = NULL;

    self = new Property_List;
    self->the_plist = NIL;
    return (self);
  }
}

Object* access_property_list_slot_value(Property_List* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_THE_PLIST) {
    if (setvalueP) {
      self->the_plist = ((Cons*)(value));
    }
    else {
      return (self->the_plist);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Property_List::primary_type() {
  { Property_List* self = this;

    return (SGT_HIERARCHY_PROPERTY_LIST);
  }
}

void Property_List::print_object(ostream* stream) {
  { Property_List* self = this;

    print_cons_list(self->the_plist, stream);
  }
}

Kv_Cons* new_kv_cons() {
  { Kv_Cons* self = NULL;

    self = new Kv_Cons;
    self->rest = NULL;
    self->value = NULL;
    self->key = NULL;
    return (self);
  }
}

Object* access_kv_cons_slot_value(Kv_Cons* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_KEY) {
    if (setvalueP) {
      self->key = value;
    }
    else {
      return (self->key);
    }
  }
  else if (slotname == SYM_HIERARCHY_VALUE) {
    if (setvalueP) {
      self->value = value;
    }
    else {
      return (self->value);
    }
  }
  else if (slotname == SYM_HIERARCHY_REST) {
    if (setvalueP) {
      self->rest = ((Kv_Cons*)(value));
    }
    else {
      return (self->rest);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Kv_Cons::primary_type() {
  { Kv_Cons* self = this;

    return (SGT_HIERARCHY_KV_CONS);
  }
}

void Kv_Cons::print_object(ostream* stream) {
  { Kv_Cons* self = this;

    *(stream) << "<" << self->key << "," << self->value << ">";
  }
}

Key_Value_List* new_key_value_list() {
  { Key_Value_List* self = NULL;

    self = new Key_Value_List;
    self->the_kv_list = NULL;
    return (self);
  }
}

Object* access_key_value_list_slot_value(Key_Value_List* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_THE_KV_LIST) {
    if (setvalueP) {
      self->the_kv_list = ((Kv_Cons*)(value));
    }
    else {
      return (self->the_kv_list);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Key_Value_List::primary_type() {
  { Key_Value_List* self = this;

    return (SGT_HIERARCHY_KEY_VALUE_LIST);
  }
}

void Key_Value_List::print_object(ostream* stream) {
  { Key_Value_List* self = this;

    print_key_value_list(self, stream);
  }
}

Hash_Table* new_hash_table() {
  { Hash_Table* self = NULL;

    self = new Hash_Table;
    self->the_hash_table = NULL;
    self->initialize_hash_table();
    return (self);
  }
}

Surrogate* Hash_Table::primary_type() {
  { Hash_Table* self = this;

    return (SGT_HIERARCHY_HASH_TABLE);
  }
}

Integer_Hash_Table* new_integer_hash_table() {
  { Integer_Hash_Table* self = NULL;

    self = new Integer_Hash_Table;
    self->the_hash_table = NULL;
    self->initialize_hash_table();
    return (self);
  }
}

Surrogate* Integer_Hash_Table::primary_type() {
  { Integer_Hash_Table* self = this;

    return (SGT_HIERARCHY_INTEGER_HASH_TABLE);
  }
}

Float_Hash_Table* new_float_hash_table() {
  { Float_Hash_Table* self = NULL;

    self = new Float_Hash_Table;
    self->the_hash_table = NULL;
    self->initialize_hash_table();
    return (self);
  }
}

Surrogate* Float_Hash_Table::primary_type() {
  { Float_Hash_Table* self = this;

    return (SGT_HIERARCHY_FLOAT_HASH_TABLE);
  }
}

String_Hash_Table* new_string_hash_table() {
  { String_Hash_Table* self = NULL;

    self = new String_Hash_Table;
    self->the_hash_table = NULL;
    self->initialize_hash_table();
    return (self);
  }
}

Surrogate* String_Hash_Table::primary_type() {
  { String_Hash_Table* self = this;

    return (SGT_HIERARCHY_STRING_HASH_TABLE);
  }
}

String_To_Integer_Hash_Table* new_string_to_integer_hash_table() {
  { String_To_Integer_Hash_Table* self = NULL;

    self = new String_To_Integer_Hash_Table;
    self->the_hash_table = NULL;
    self->initialize_hash_table();
    return (self);
  }
}

Surrogate* String_To_Integer_Hash_Table::primary_type() {
  { String_To_Integer_Hash_Table* self = this;

    return (SGT_HIERARCHY_STRING_TO_INTEGER_HASH_TABLE);
  }
}

Vector* new_vector(int array_size) {
  { Vector* self = NULL;

    self = new Vector;
    self->the_array = NULL;
    self->array_size = array_size;
    self->initialize_vector();
    return (self);
  }
}

Object* access_vector_slot_value(Vector* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_ARRAY_SIZE) {
    if (setvalueP) {
      self->array_size = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->array_size));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Vector::primary_type() {
  { Vector* self = this;

    return (SGT_HIERARCHY_VECTOR);
  }
}

void Vector::print_object(ostream* stream) {
  { Vector* self = this;

    self->print_vector(stream);
  }
}

Extensible_Vector* new_extensible_vector(int array_size) {
  { Extensible_Vector* self = NULL;

    self = new Extensible_Vector;
    self->the_array = NULL;
    self->array_size = array_size;
    self->initialize_vector();
    return (self);
  }
}

Surrogate* Extensible_Vector::primary_type() {
  { Extensible_Vector* self = this;

    return (SGT_HIERARCHY_EXTENSIBLE_VECTOR);
  }
}

Extensible_Symbol_Array* new_extensible_symbol_array(int array_size) {
  { Extensible_Symbol_Array* self = NULL;

    self = new Extensible_Symbol_Array;
    self->the_array = NULL;
    self->potential_free_symbol_offset = 0;
    self->top_symbol_offset = -1;
    self->array_size = array_size;
    self->initialize_vector();
    return (self);
  }
}

Object* access_extensible_symbol_array_slot_value(Extensible_Symbol_Array* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_TOP_SYMBOL_OFFSET) {
    if (setvalueP) {
      self->top_symbol_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->top_symbol_offset));
    }
  }
  else if (slotname == SYM_HIERARCHY_POTENTIAL_FREE_SYMBOL_OFFSET) {
    if (setvalueP) {
      self->potential_free_symbol_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->potential_free_symbol_offset));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Extensible_Symbol_Array::primary_type() {
  { Extensible_Symbol_Array* self = this;

    return (SGT_HIERARCHY_EXTENSIBLE_SYMBOL_ARRAY);
  }
}

int Vector_Sequence::resize_increment_reader() {
  { Vector_Sequence* self = this;

    return (oHARDWIRED_RESIZE_INCREMENT_ON_VECTOR_SEQUENCEo);
  }
}

Object* access_vector_sequence_slot_value(Vector_Sequence* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_RESIZE_INCREMENT) {
    return (integer_wrap_literal(self->resize_increment_reader()));
  }
  else if (slotname == SYM_HIERARCHY_SEQUENCE_LENGTH) {
    if (setvalueP) {
      self->sequence_length = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->sequence_length));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Short_Vector_Sequence* new_short_vector_sequence(int array_size) {
  { Short_Vector_Sequence* self = NULL;

    self = new Short_Vector_Sequence;
    self->the_array = NULL;
    self->sequence_length = 0;
    self->array_size = array_size;
    self->initialize_vector();
    return (self);
  }
}

int Short_Vector_Sequence::resize_increment_reader() {
  { Short_Vector_Sequence* self = this;

    return (oHARDWIRED_RESIZE_INCREMENT_ON_SHORT_VECTOR_SEQUENCEo);
  }
}

Object* access_short_vector_sequence_slot_value(Short_Vector_Sequence* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_RESIZE_INCREMENT) {
    return (integer_wrap_literal(self->resize_increment_reader()));
  }
  else if (slotname == SYM_HIERARCHY_SEQUENCE_LENGTH) {
    if (setvalueP) {
      self->sequence_length = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->sequence_length));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Short_Vector_Sequence::primary_type() {
  { Short_Vector_Sequence* self = this;

    return (SGT_HIERARCHY_SHORT_VECTOR_SEQUENCE);
  }
}

Boolean_Vector* new_boolean_vector(int array_size) {
  { Boolean_Vector* self = NULL;

    self = new Boolean_Vector;
    self->the_array = NULL;
    self->array_size = array_size;
    self->initialize_vector();
    return (self);
  }
}

Surrogate* Boolean_Vector::primary_type() {
  { Boolean_Vector* self = this;

    return (SGT_HIERARCHY_BOOLEAN_VECTOR);
  }
}

Integer_Vector* new_integer_vector(int array_size) {
  { Integer_Vector* self = NULL;

    self = new Integer_Vector;
    self->the_array = NULL;
    self->array_size = array_size;
    self->initialize_vector();
    return (self);
  }
}

Surrogate* Integer_Vector::primary_type() {
  { Integer_Vector* self = this;

    return (SGT_HIERARCHY_INTEGER_VECTOR);
  }
}

Array* new_array() {
  { Array* self = NULL;

    self = new Array;
    return (self);
  }
}

Surrogate* Array::primary_type() {
  { Array* self = this;

    return (SGT_HIERARCHY_ARRAY);
  }
}

Null_Terminated_Array* new_null_terminated_array() {
  { Null_Terminated_Array* self = NULL;

    self = new Null_Terminated_Array;
    return (self);
  }
}

Surrogate* Null_Terminated_Array::primary_type() {
  { Null_Terminated_Array* self = this;

    return (SGT_HIERARCHY_NULL_TERMINATED_ARRAY);
  }
}

Active_List* new_active_list() {
  { Active_List* self = NULL;

    self = new Active_List;
    self->the_cons_list = NIL;
    self->owner_instance = NULL;
    self->active_slot = NULL;
    return (self);
  }
}

void Active_List::free() {
  { Active_List* self = this;

    if (terminate_listP(self)) {
      unmake(self);
    }
  }
}

Surrogate* Active_List::primary_type() {
  { Active_List* self = this;

    return (SGT_HIERARCHY_ACTIVE_LIST);
  }
}

Active_Set* new_active_set() {
  { Active_Set* self = NULL;

    self = new Active_Set;
    self->the_cons_list = NIL;
    self->owner_instance = NULL;
    self->active_slot = NULL;
    return (self);
  }
}

void Active_Set::free() {
  { Active_Set* self = this;

    if (terminate_listP(self)) {
      unmake(self);
    }
  }
}

Surrogate* Active_Set::primary_type() {
  { Active_Set* self = this;

    return (SGT_HIERARCHY_ACTIVE_SET);
  }
}

Demon* new_demon() {
  { Demon* self = NULL;

    self = new Demon;
    self->demon_inheritP = FALSE;
    self->demon_allP = FALSE;
    self->demon_guardP = FALSE;
    self->demon_documentation = NULL;
    self->demon_method = NULL;
    self->demon_code = NULL;
    self->demon_slot_refs = new_list();
    self->demon_class_refs = new_list();
    self->demon_action = NULL;
    self->demon_name = NULL;
    return (self);
  }
}

Object* access_demon_slot_value(Demon* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_DEMON_NAME) {
    if (setvalueP) {
      self->demon_name = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->demon_name));
    }
  }
  else if (slotname == SYM_HIERARCHY_DEMON_ACTION) {
    if (setvalueP) {
      self->demon_action = ((Keyword*)(value));
    }
    else {
      return (self->demon_action);
    }
  }
  else if (slotname == SYM_HIERARCHY_DEMON_CLASS_REFS) {
    if (setvalueP) {
      self->demon_class_refs = ((List*)(value));
    }
    else {
      return (self->demon_class_refs);
    }
  }
  else if (slotname == SYM_HIERARCHY_DEMON_SLOT_REFS) {
    if (setvalueP) {
      self->demon_slot_refs = ((List*)(value));
    }
    else {
      return (self->demon_slot_refs);
    }
  }
  else if (slotname == SYM_HIERARCHY_DEMON_CODE) {
    if (setvalueP) {
      self->demon_code = ((Function_Code_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (function_code_wrap_literal(self->demon_code));
    }
  }
  else if (slotname == SYM_HIERARCHY_DEMON_METHOD) {
    if (setvalueP) {
      self->demon_method = ((Method_Slot*)(value));
    }
    else {
      return (self->demon_method);
    }
  }
  else if (slotname == SYM_HIERARCHY_DEMON_DOCUMENTATION) {
    if (setvalueP) {
      self->demon_documentation = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->demon_documentation));
    }
  }
  else if (slotname == SYM_HIERARCHY_DEMON_GUARDp) {
    if (setvalueP) {
      self->demon_guardP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->demon_guardP));
    }
  }
  else if (slotname == SYM_HIERARCHY_DEMON_ALLp) {
    if (setvalueP) {
      self->demon_allP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->demon_allP));
    }
  }
  else if (slotname == SYM_HIERARCHY_DEMON_INHERITp) {
    if (setvalueP) {
      self->demon_inheritP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->demon_inheritP));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Demon::primary_type() {
  { Demon* self = this;

    return (SGT_HIERARCHY_DEMON);
  }
}

List_Of_Slot* new_list_of_slot() {
  { List_Of_Slot* self = NULL;

    self = new List_Of_Slot;
    self->the_cons_list = NIL;
    return (self);
  }
}

void List_Of_Slot::free() {
  { List_Of_Slot* self = this;

    if (terminate_listP(self)) {
      unmake(self);
    }
  }
}

Surrogate* List_Of_Slot::primary_type() {
  { List_Of_Slot* self = this;

    return (SGT_HIERARCHY_LIST_OF_SLOT);
  }
}

List_Of_Symbol* new_list_of_symbol() {
  { List_Of_Symbol* self = NULL;

    self = new List_Of_Symbol;
    self->the_cons_list = NIL;
    return (self);
  }
}

void List_Of_Symbol::free() {
  { List_Of_Symbol* self = this;

    if (terminate_listP(self)) {
      unmake(self);
    }
  }
}

Surrogate* List_Of_Symbol::primary_type() {
  { List_Of_Symbol* self = this;

    return (SGT_HIERARCHY_LIST_OF_SYMBOL);
  }
}

List_Of_Keyword* new_list_of_keyword() {
  { List_Of_Keyword* self = NULL;

    self = new List_Of_Keyword;
    self->the_cons_list = NIL;
    return (self);
  }
}

void List_Of_Keyword::free() {
  { List_Of_Keyword* self = this;

    if (terminate_listP(self)) {
      unmake(self);
    }
  }
}

Surrogate* List_Of_Keyword::primary_type() {
  { List_Of_Keyword* self = this;

    return (SGT_HIERARCHY_LIST_OF_KEYWORD);
  }
}

List_Of_Type* new_list_of_type() {
  { List_Of_Type* self = NULL;

    self = new List_Of_Type;
    self->the_cons_list = NIL;
    return (self);
  }
}

void List_Of_Type::free() {
  { List_Of_Type* self = this;

    if (terminate_listP(self)) {
      unmake(self);
    }
  }
}

Surrogate* List_Of_Type::primary_type() {
  { List_Of_Type* self = this;

    return (SGT_HIERARCHY_LIST_OF_TYPE);
  }
}

Keyword_Key_Value_List* new_keyword_key_value_list() {
  { Keyword_Key_Value_List* self = NULL;

    self = new Keyword_Key_Value_List;
    self->the_kv_list = NULL;
    return (self);
  }
}

Surrogate* Keyword_Key_Value_List::primary_type() {
  { Keyword_Key_Value_List* self = this;

    return (SGT_HIERARCHY_KEYWORD_KEY_VALUE_LIST);
  }
}

Object* access_generalized_symbol_slot_value(Generalized_Symbol* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_SYMBOL_NAME) {
    if (setvalueP) {
      self->symbol_name = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->symbol_name));
    }
  }
  else if (slotname == SYM_HIERARCHY_SYMBOL_ID) {
    if (setvalueP) {
      self->symbol_id = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->symbol_id));
    }
  }
  else if (slotname == SYM_HIERARCHY_INTERNED_IN) {
    if (setvalueP) {
      self->home_context = ((Module*)(value));
    }
    else {
      return (((Module*)(self->home_context)));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Symbol* new_symbol(char* symbol_name) {
  { Symbol* self = NULL;

    self = new Symbol;
    self->home_context = oMODULEo;
    self->symbol_id = NULL_INTEGER;
    self->symbol_value_and_plist = NIL;
    self->symbol_slot_offset = NULL_INTEGER;
    self->symbol_name = symbol_name;
    return (self);
  }
}

Object* access_symbol_slot_value(Symbol* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_SYMBOL_SLOT_OFFSET) {
    if (setvalueP) {
      self->symbol_slot_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->symbol_slot_offset));
    }
  }
  else if (slotname == SYM_HIERARCHY_SYMBOL_VALUE_AND_PLIST) {
    if (setvalueP) {
      self->symbol_value_and_plist = ((Cons*)(value));
    }
    else {
      return (self->symbol_value_and_plist);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Symbol::primary_type() {
  { Symbol* self = this;

    return (SGT_HIERARCHY_SYMBOL);
  }
}

void Symbol::print_object(ostream* stream) {
  { Symbol* self = this;

    print_symbol(self, stream);
  }
}

Surrogate* new_surrogate(char* symbol_name) {
  { Surrogate* self = NULL;

    self = new Surrogate;
    self->home_context = oMODULEo;
    self->symbol_id = NULL_INTEGER;
    self->surrogate_value = NULL;
    self->symbol_name = symbol_name;
    return (self);
  }
}

Object* access_surrogate_slot_value(Surrogate* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_SURROGATE_VALUE) {
    if (setvalueP) {
      self->surrogate_value = value;
    }
    else {
      return (self->surrogate_value);
    }
  }
  else if (slotname == SYM_HIERARCHY_SURROGATE_NAME) {
    if (setvalueP) {
      self->symbol_name = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->symbol_name));
    }
  }
  else if (slotname == SYM_HIERARCHY_TYPE_CLASS) {
    if (setvalueP) {
      self->surrogate_value = ((Class*)(value));
    }
    else {
      return (((Class*)(self->surrogate_value)));
    }
  }
  else if (slotname == SYM_HIERARCHY_TYPE_NAME) {
    if (setvalueP) {
      self->symbol_name = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->symbol_name));
    }
  }
  else if (slotname == SYM_HIERARCHY_SLOTREF_SLOT) {
    if (setvalueP) {
      self->surrogate_value = ((Slot*)(value));
    }
    else {
      return (((Slot*)(self->surrogate_value)));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Surrogate::primary_type() {
  { Surrogate* self = this;

    return (SGT_HIERARCHY_SURROGATE);
  }
}

void Surrogate::print_object(ostream* stream) {
  { Surrogate* self = this;

    *(stream) << self->relative_name();
  }
}

Keyword* new_keyword(char* symbol_name) {
  { Keyword* self = NULL;

    self = new Keyword;
    self->home_context = oMODULEo;
    self->symbol_id = NULL_INTEGER;
    self->symbol_name = symbol_name;
    return (self);
  }
}

Object* access_keyword_slot_value(Keyword* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_KEYWORD_NAME) {
    if (setvalueP) {
      self->symbol_name = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->symbol_name));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Keyword::primary_type() {
  { Keyword* self = this;

    return (SGT_HIERARCHY_KEYWORD);
  }
}

void Keyword::print_object(ostream* stream) {
  { Keyword* self = this;

    *(stream) << ":" << self->symbol_name;
  }
}

Indexical* new_indexical(char* symbol_name) {
  { Indexical* self = NULL;

    self = new Indexical;
    self->home_context = oMODULEo;
    self->symbol_id = NULL_INTEGER;
    self->indexical_value = NULL;
    self->symbol_name = symbol_name;
    return (self);
  }
}

Object* access_indexical_slot_value(Indexical* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_INDEXICAL_VALUE) {
    if (setvalueP) {
      { Indexical* object_001 = self;
        Object* value_001 = value;
        Object* old_value_001 = object_001->indexical_value;
        Object* new_value_001 = update_in_context(old_value_001, value_001, object_001, FALSE);

        if (!cs_valueP(old_value_001)) {
          object_001->indexical_value = new_value_001;
        }
      }
    }
    else {
      return (((Object*)(access_in_context(self->indexical_value, self, FALSE))));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Indexical::primary_type() {
  { Indexical* self = this;

    return (SGT_HIERARCHY_INDEXICAL);
  }
}

void Indexical::print_object(ostream* stream) {
  { Indexical* self = this;

    *(stream) << self->relative_name();
  }
}

Transient_Symbol* new_transient_symbol(char* symbol_name) {
  { Transient_Symbol* self = NULL;

    self = new Transient_Symbol;
    self->home_context = oMODULEo;
    self->symbol_id = NULL_INTEGER;
    self->symbol_value_and_plist = NIL;
    self->symbol_slot_offset = NULL_INTEGER;
    self->symbol_name = symbol_name;
    return (self);
  }
}

Surrogate* Transient_Symbol::primary_type() {
  { Transient_Symbol* self = this;

    return (SGT_HIERARCHY_TRANSIENT_SYMBOL);
  }
}

Transient_Keyword* new_transient_keyword(char* symbol_name) {
  { Transient_Keyword* self = NULL;

    self = new Transient_Keyword;
    self->home_context = oMODULEo;
    self->symbol_id = NULL_INTEGER;
    self->symbol_name = symbol_name;
    return (self);
  }
}

Surrogate* Transient_Keyword::primary_type() {
  { Transient_Keyword* self = this;

    return (SGT_HIERARCHY_TRANSIENT_KEYWORD);
  }
}

List* Mappable_Object::projects_onto_reader() {
  { Mappable_Object* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_PROJECTS_ONTO, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Mappable_Object::projected_from_reader() {
  { Mappable_Object* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_PROJECTED_FROM, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_mappable_object_slot_value(Mappable_Object* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_PROJECTS_ONTO) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_PROJECTS_ONTO, ((List*)(value)), NULL);
      }
      else {
        return (self->projects_onto_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_PROJECTED_FROM) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_PROJECTED_FROM, ((List*)(value)), NULL);
      }
      else {
        return (self->projected_from_reader());
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

List* Relation::properties_reader() {
  { Relation* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_PROPERTIES, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Relation::stored_activeP_reader() {
  { Relation* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_STORED_ACTIVEp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (NULL_BOOLEAN);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_relation_slot_value(Relation* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_ABSTRACTp) {
      if (setvalueP) {
        self->abstractP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->abstractP));
      }
    }
    else if (slotname == SYM_HIERARCHY_PROPERTIES) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_PROPERTIES, ((List*)(value)), NULL);
      }
      else {
        return (self->properties_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_STORED_ACTIVEp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_STORED_ACTIVEp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->stored_activeP_reader()));
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

char* Relation::name() {
  { Relation* self = this;

    return (NULL);
  }
}

Module* Relation::home_module() {
  { Relation* self = this;

    return (NULL);
  }
}

int Relation::arity() {
  { Relation* self = this;

    return (NULL_INTEGER);
  }
}

boolean Relation::publicP() {
  { Relation* self = this;

    return (FALSE);
  }
}

List* Relation::direct_supers() {
  { Relation* self = this;

    return (NULL);
  }
}

List* Relation::all_supers() {
  { Relation* self = this;

    return (NULL);
  }
}

Iterator* Relation::slots() {
  { Relation* self = this;

    return (NULL);
  }
}

Class* new_class() {
  { Class* self = NULL;

    self = new Class;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->class_taxonomy_node = NULL;
    self->class_markedP = FALSE;
    self->class_slot_accessor_code = NULL;
    self->class_constructor_code = NULL;
    self->class_stringified_source = NULL;
    self->class_slots_finalizedP = FALSE;
    self->class_finalizedP = FALSE;
    self->class_publicP = TRUE;
    self->cl_structP = FALSE;
    self->class_collectionP = FALSE;
    self->mixinP = FALSE;
    self->abstractP = FALSE;
    self->class_slot_and_method_cache = NULL;
    self->class_local_slots = NULL;
    self->class_all_slots = NULL;
    self->class_all_super_classes = NIL;
    self->class_direct_subs = new_list();
    self->class_direct_supers = new_list();
    self->class_type = NULL;
    return (self);
  }
}

int Class::class_arity_reader() {
  { Class* self = this;

    return (oHARDWIRED_CLASS_ARITY_ON_CLASSo);
  }
}

List* Class::class_cl_struct_slots_reader() {
  { Class* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_CL_STRUCT_SLOTS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

Keyword* Class::class_recycle_method_reader() {
  { Class* self = this;

    { Keyword* answer = ((Keyword*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_RECYCLE_METHOD, NULL)));

      if (answer == NULL) {
        return (KWD_HIERARCHY_NONE);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Class::class_parameters_reader() {
  { Class* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_PARAMETERS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Class::class_required_slot_names_reader() {
  { Class* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_REQUIRED_SLOT_NAMES, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Class::class_guard_constructor_demons_reader() {
  { Class* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_GUARD_CONSTRUCTOR_DEMONS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Class::class_constructor_demons_reader() {
  { Class* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_CONSTRUCTOR_DEMONS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Class::class_guard_destructor_demons_reader() {
  { Class* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_GUARD_DESTRUCTOR_DEMONS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Class::class_destructor_demons_reader() {
  { Class* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_DESTRUCTOR_DEMONS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Class::class_key_reader() {
  { Class* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_KEY, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Class::class_synonyms_reader() {
  { Class* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_SYNONYMS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_class_slot_value(Class* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_CL_STRUCTp) {
      if (setvalueP) {
        self->cl_structP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->cl_structP));
      }
    }
    else if (slotname == SYM_HIERARCHY_MIXINp) {
      if (setvalueP) {
        self->mixinP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->mixinP));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_TYPE) {
      if (setvalueP) {
        self->class_type = ((Surrogate*)(value));
      }
      else {
        return (self->class_type);
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_ARITY) {
      return (integer_wrap_literal(self->class_arity_reader()));
    }
    else if (slotname == SYM_HIERARCHY_CLASS_DIRECT_SUPERS) {
      if (setvalueP) {
        self->class_direct_supers = ((List*)(value));
      }
      else {
        return (self->class_direct_supers);
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_DIRECT_SUBS) {
      if (setvalueP) {
        self->class_direct_subs = ((List*)(value));
      }
      else {
        return (self->class_direct_subs);
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_ALL_SUPER_CLASSES) {
      if (setvalueP) {
        self->class_all_super_classes = ((Cons*)(value));
      }
      else {
        return (self->class_all_super_classes);
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_ALL_SLOTS) {
      if (setvalueP) {
        self->class_all_slots = ((Cons*)(value));
      }
      else {
        return (self->class_all_slots);
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_LOCAL_SLOTS) {
      if (setvalueP) {
        self->class_local_slots = ((List*)(value));
      }
      else {
        return (self->class_local_slots);
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_SLOT_AND_METHOD_CACHE) {
      if (setvalueP) {
        self->class_slot_and_method_cache = ((Vector*)(value));
      }
      else {
        return (self->class_slot_and_method_cache);
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_ABSTRACTp) {
      if (setvalueP) {
        self->abstractP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->abstractP));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_MIXINp) {
      if (setvalueP) {
        self->mixinP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->mixinP));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_COLLECTIONp) {
      if (setvalueP) {
        self->class_collectionP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->class_collectionP));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_CL_STRUCTp) {
      if (setvalueP) {
        self->cl_structP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->cl_structP));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_CL_STRUCT_SLOTS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_CLASS_CL_STRUCT_SLOTS, ((List*)(value)), NULL);
      }
      else {
        return (self->class_cl_struct_slots_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_PUBLICp) {
      if (setvalueP) {
        self->class_publicP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->class_publicP));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_RECYCLE_METHOD) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_CLASS_RECYCLE_METHOD, ((Keyword*)(value)), NULL);
      }
      else {
        return (self->class_recycle_method_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_FINALIZEDp) {
      if (setvalueP) {
        self->class_finalizedP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->class_finalizedP));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_SLOTS_FINALIZEDp) {
      if (setvalueP) {
        self->class_slots_finalizedP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->class_slots_finalizedP));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_STRINGIFIED_SOURCE) {
      if (setvalueP) {
        self->class_stringified_source = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->class_stringified_source));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_PARAMETERS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_CLASS_PARAMETERS, ((List*)(value)), NULL);
      }
      else {
        return (self->class_parameters_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_CONSTRUCTOR_CODE) {
      if (setvalueP) {
        self->class_constructor_code = ((Function_Code_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (function_code_wrap_literal(self->class_constructor_code));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_SLOT_ACCESSOR_CODE) {
      if (setvalueP) {
        self->class_slot_accessor_code = ((Function_Code_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (function_code_wrap_literal(self->class_slot_accessor_code));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_REQUIRED_SLOT_NAMES) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_CLASS_REQUIRED_SLOT_NAMES, ((List*)(value)), NULL);
      }
      else {
        return (self->class_required_slot_names_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_GUARD_CONSTRUCTOR_DEMONS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_CLASS_GUARD_CONSTRUCTOR_DEMONS, ((List*)(value)), NULL);
      }
      else {
        return (self->class_guard_constructor_demons_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_CONSTRUCTOR_DEMONS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_CLASS_CONSTRUCTOR_DEMONS, ((List*)(value)), NULL);
      }
      else {
        return (self->class_constructor_demons_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_GUARD_DESTRUCTOR_DEMONS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_CLASS_GUARD_DESTRUCTOR_DEMONS, ((List*)(value)), NULL);
      }
      else {
        return (self->class_guard_destructor_demons_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_DESTRUCTOR_DEMONS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_CLASS_DESTRUCTOR_DEMONS, ((List*)(value)), NULL);
      }
      else {
        return (self->class_destructor_demons_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_KEY) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_CLASS_KEY, ((List*)(value)), NULL);
      }
      else {
        return (self->class_key_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_SYNONYMS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_CLASS_SYNONYMS, ((List*)(value)), NULL);
      }
      else {
        return (self->class_synonyms_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_MARKEDp) {
      if (setvalueP) {
        self->class_markedP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->class_markedP));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLASS_TAXONOMY_NODE) {
      if (setvalueP) {
        self->class_taxonomy_node = ((Taxonomy_Node*)(value));
      }
      else {
        return (self->class_taxonomy_node);
      }
    }
    else {
      if (slotname == SYM_HIERARCHY_CLASS_DOCUMENTATION) {
        slotname = SYM_HIERARCHY_DOCUMENTATION;
      }
      else if (slotname == SYM_HIERARCHY_CLASS_PRINT_FORM) {
        slotname = SYM_HIERARCHY_PRINT_FORM;
      }
      else {
      }
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Class::primary_type() {
  { Class* self = this;

    return (SGT_HIERARCHY_CLASS);
  }
}

char* Class::name() {
  { Class* self = this;

    return (self->class_type->symbol_name);
  }
}

Module* Class::home_module() {
  { Class* self = this;

    return (((Module*)(self->class_type->home_context)));
  }
}

int Class::arity() {
  { Class* self = this;

    return (1);
  }
}

boolean Class::publicP() {
  { Class* self = this;

    return (self->class_publicP);
  }
}

boolean Class::activeP() {
  { Class* self = this;

    return (((self->stored_activeP_reader() != NULL_BOOLEAN) &&
        self->stored_activeP_reader()) ||
        subtype_ofP(self->class_type, SGT_HIERARCHY_ACTIVE_OBJECT));
  }
}

Symbol* Class::creator() {
  { Class* self = this;

    return (((Symbol*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_CREATOR, NULL))));
  }
}

Symbol* Class::initializer() {
  { Class* self = this;

    { Class* cursor = self;
      Symbol* value = ((Symbol*)(dynamic_slot_value(cursor, SYM_HIERARCHY_CLASS_INITIALIZER, NULL)));

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = ((Class*)(cursor->class_all_super_classes->first()));
        if (cursor != NULL) {
          value = ((Symbol*)(dynamic_slot_value(cursor, SYM_HIERARCHY_CLASS_INITIALIZER, NULL)));
        }
        else {
          return (NULL);
        }
      }
    }
  }
}

Symbol* Class::terminator() {
  { Class* self = this;

    { Class* cursor = self;
      Symbol* value = ((Symbol*)(dynamic_slot_value(cursor, SYM_HIERARCHY_CLASS_TERMINATOR, NULL)));

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = ((Class*)(cursor->class_all_super_classes->first()));
        if (cursor != NULL) {
          value = ((Symbol*)(dynamic_slot_value(cursor, SYM_HIERARCHY_CLASS_TERMINATOR, NULL)));
        }
        else {
          return (NULL);
        }
      }
    }
  }
}

Symbol* Class::destructor() {
  { Class* self = this;

    return (((Symbol*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_DESTRUCTOR, NULL))));
  }
}

List* Class::required_slots() {
  // Returns a list of names of required slots for 'self'.
  { Class* self = this;

    return (self->class_required_slot_names_reader());
  }
}

List* Class::parameters() {
  // Returns the list of parameters names of 'self'.
  { Class* self = this;

    { Class* cursor = self;
      List* value = ((List*)(dynamic_slot_value(cursor, SYM_HIERARCHY_CLASS_PARAMETERS, NULL)));

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = ((Class*)(cursor->class_all_super_classes->first()));
        if (cursor != NULL) {
          value = ((List*)(dynamic_slot_value(cursor, SYM_HIERARCHY_CLASS_PARAMETERS, NULL)));
        }
        else {
          return (NIL_LIST);
        }
      }
    }
  }
}

Object* Class::initial_value() {
  // Return an initial value for the class 'self'.
  { Class* self = this;

    { Class* cursor = self;
      Object* value = dynamic_slot_value(cursor, SYM_HIERARCHY_CLASS_INITIAL_VALUE, NULL);

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = ((Class*)(cursor->class_all_super_classes->first()));
        if (cursor != NULL) {
          value = dynamic_slot_value(cursor, SYM_HIERARCHY_CLASS_INITIAL_VALUE, NULL);
        }
        else {
          return (NULL);
        }
      }
    }
  }
}

Class_Extension* Class::extension() {
  // Return the nearest class extension that records instances
  // of the class 'self'.
  { Class* self = this;

    { Class* cursor = self;
      Class_Extension* value = ((Class_Extension*)(dynamic_slot_value(cursor, SYM_HIERARCHY_CLASS_EXTENSION, NULL)));

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = ((Class*)(cursor->class_all_super_classes->first()));
        if (cursor != NULL) {
          value = ((Class_Extension*)(dynamic_slot_value(cursor, SYM_HIERARCHY_CLASS_EXTENSION, NULL)));
        }
        else {
          return (NULL);
        }
      }
    }
  }
}

char* Class::cl_native_type() {
  { Class* self = this;

    return (((String_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_CL_NATIVE_TYPE, NULL_STRING_WRAPPER)))->wrapper_value);
  }
}

char* Class::cpp_native_type() {
  { Class* self = this;

    return (((String_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_CPP_NATIVE_TYPE, NULL_STRING_WRAPPER)))->wrapper_value);
  }
}

char* Class::idl_native_type() {
  { Class* self = this;

    return (((String_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_CPP_NATIVE_TYPE, NULL_STRING_WRAPPER)))->wrapper_value);
  }
}

char* Class::java_native_type() {
  { Class* self = this;

    return (((String_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_CLASS_JAVA_NATIVE_TYPE, NULL_STRING_WRAPPER)))->wrapper_value);
  }
}

void Class::print_object(ostream* stream) {
  { Class* self = this;

    *(stream) << "|C|" << (((self->class_type != NULL) ? ((char*)(self->class_type->symbol_name)) : ((char*)("??"))));
  }
}

Object* access_polymorphic_relation_slot_value(Polymorphic_Relation* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_SLOT_DIRECT_EQUIVALENT) {
      if (setvalueP) {
        self->slot_direct_equivalent = ((Slot*)(value));
      }
      else {
        return (self->slot_direct_equivalent);
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Polymorphic_Relation::owner() {
  { Polymorphic_Relation* self = this;

    return (NULL);
  }
}

Symbol* Polymorphic_Relation::renames() {
  { Polymorphic_Relation* self = this;

    return (NULL);
  }
}

boolean Polymorphic_Relation::activeP() {
  // True if 'self' or a superslot of 'self' is marked active.
  { Polymorphic_Relation* self = this;

    { Polymorphic_Relation* cursor = self;
      boolean value = ((Boolean_Wrapper*)(dynamic_slot_value(cursor, SYM_HIERARCHY_STORED_ACTIVEp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      for (;;) {
        if (value) {
          return (value);
        }
        cursor = cursor->slot_direct_equivalent;
        if (cursor != NULL) {
          value = ((Boolean_Wrapper*)(dynamic_slot_value(cursor, SYM_HIERARCHY_STORED_ACTIVEp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;
        }
        else {
          return (NULL_BOOLEAN);
        }
      }
    }
  }
}

boolean Slot::slot_auxiliaryP_reader() {
  { Slot* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_SLOT_AUXILIARYp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Slot::slot_direct_supers_reader() {
  { Slot* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_SLOT_DIRECT_SUPERS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Slot::slot_direct_subs_reader() {
  { Slot* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_SLOT_DIRECT_SUBS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_slot_slot_value(Slot* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_SLOT_NAME) {
      if (setvalueP) {
        self->slot_name = ((Symbol*)(value));
      }
      else {
        return (self->slot_name);
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_OWNER) {
      if (setvalueP) {
        self->slot_owner = ((Surrogate*)(value));
      }
      else {
        return (self->slot_owner);
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_BASE_TYPE) {
      if (setvalueP) {
        self->slot_base_type = ((Surrogate*)(value));
      }
      else {
        return (self->slot_base_type);
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_SLOTREF) {
      if (setvalueP) {
        self->slot_slotref = ((Surrogate*)(value));
      }
      else {
        return (self->slot_slotref);
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_PUBLICp) {
      if (setvalueP) {
        self->slot_publicP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->slot_publicP));
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_RENAMEDp) {
      if (setvalueP) {
        self->slot_renamedP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->slot_renamedP));
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_EXTERNALp) {
      if (setvalueP) {
        self->slot_externalP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->slot_externalP));
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_MARKEDp) {
      if (setvalueP) {
        self->slot_markedP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->slot_markedP));
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_AUXILIARYp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_SLOT_AUXILIARYp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->slot_auxiliaryP_reader()));
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_DIRECT_SUPERS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_SLOT_DIRECT_SUPERS, ((List*)(value)), NULL);
      }
      else {
        return (self->slot_direct_supers_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_DIRECT_SUBS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_SLOT_DIRECT_SUBS, ((List*)(value)), NULL);
      }
      else {
        return (self->slot_direct_subs_reader());
      }
    }
    else {
      if (slotname == SYM_HIERARCHY_SLOT_DOCUMENTATION) {
        slotname = SYM_HIERARCHY_DOCUMENTATION;
      }
      else {
      }
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

char* Slot::name() {
  { Slot* self = this;

    return (self->slot_name->symbol_name);
  }
}

Module* Slot::home_module() {
  { Slot* self = this;

    return (((Module*)(self->slot_name->home_context)));
  }
}

Surrogate* Slot::type() {
  // The type of a storage slot is its base type.
  { Slot* self = this;

    { Slot* cursor = self;
      Surrogate* value = cursor->slot_base_type;

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = cursor->slot_direct_equivalent;
        if (cursor != NULL) {
          value = cursor->slot_base_type;
        }
        else {
          return (NULL);
        }
      }
    }
  }
}

Standard_Object* Slot::type_specifier() {
  // If 'self' has a complex type return its
  // type specifier, otherwise, return 'type' of 'self'.
  { Slot* self = this;

    { Compound_Type_Specifier* tspec = ((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_HIERARCHY_SLOT_TYPE_SPECIFIER, NULL)));

      return (((tspec != NULL) ? ((Standard_Object*)(tspec)) : ((Standard_Object*)(self->type()))));
    }
  }
}

Surrogate* Slot::owner() {
  { Slot* self = this;

    return (self->slot_owner);
  }
}

Symbol* Slot::renames() {
  { Slot* self = this;

    return (((Symbol*)(dynamic_slot_value(self, SYM_HIERARCHY_SLOT_RENAMES, NULL))));
  }
}

boolean Slot::single_valuedP() {
  // True if slot values are not collections.
  { Slot* self = this;

    return (!subtype_ofP(self->slot_base_type, SGT_HIERARCHY_COLLECTION));
  }
}

Keyword* Slot::closure_assumption() {
  { Slot* self = this;

    { Slot* cursor = self;
      Keyword* value = ((Keyword*)(dynamic_slot_value(cursor, SYM_HIERARCHY_SLOT_CLOSURE_ASSUMPTION, NULL)));

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = cursor->slot_direct_equivalent;
        if (cursor != NULL) {
          value = ((Keyword*)(dynamic_slot_value(cursor, SYM_HIERARCHY_SLOT_CLOSURE_ASSUMPTION, NULL)));
        }
        else {
          return (NULL);
        }
      }
    }
  }
}

void Slot::print_object(ostream* stream) {
  { Slot* self = this;

    *(stream) << "|S|" << self->slot_owner->symbol_name << "." << self->slot_name->symbol_name;
  }
}

Storage_Slot* new_storage_slot() {
  { Storage_Slot* self = NULL;

    self = new Storage_Slot;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->abstractP = FALSE;
    self->slot_direct_equivalent = NULL;
    self->slot_markedP = FALSE;
    self->slot_externalP = FALSE;
    self->slot_renamedP = FALSE;
    self->slot_publicP = FALSE;
    self->slot_slotref = NULL;
    self->slot_base_type = NULL;
    self->slot_owner = NULL;
    self->slot_name = NULL;
    self->slot_context_sensitiveP = FALSE;
    self->slot_hardwiredP = FALSE;
    self->slot_read_onlyP = FALSE;
    self->slot_componentP = FALSE;
    self->slot_requiredP = FALSE;
    return (self);
  }
}

Keyword* Storage_Slot::slot_allocation_reader() {
  { Storage_Slot* self = this;

    { Keyword* answer = ((Keyword*)(dynamic_slot_value(self, SYM_HIERARCHY_SLOT_ALLOCATION, NULL)));

      if (answer == NULL) {
        return (KWD_HIERARCHY_INSTANCE);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Storage_Slot::slot_guard_demons_reader() {
  { Storage_Slot* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_SLOT_GUARD_DEMONS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Storage_Slot::slot_demons_reader() {
  { Storage_Slot* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_SLOT_DEMONS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Storage_Slot::slot_accessor_methods_reader() {
  { Storage_Slot* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_SLOT_ACCESSOR_METHODS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_storage_slot_slot_value(Storage_Slot* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_SLOT_ALLOCATION) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_SLOT_ALLOCATION, ((Keyword*)(value)), NULL);
      }
      else {
        return (self->slot_allocation_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_GUARD_DEMONS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_SLOT_GUARD_DEMONS, ((List*)(value)), NULL);
      }
      else {
        return (self->slot_guard_demons_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_DEMONS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_SLOT_DEMONS, ((List*)(value)), NULL);
      }
      else {
        return (self->slot_demons_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_REQUIREDp) {
      if (setvalueP) {
        self->slot_requiredP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->slot_requiredP));
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_COMPONENTp) {
      if (setvalueP) {
        self->slot_componentP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->slot_componentP));
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_READ_ONLYp) {
      if (setvalueP) {
        self->slot_read_onlyP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->slot_read_onlyP));
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_HARDWIREDp) {
      if (setvalueP) {
        self->slot_hardwiredP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->slot_hardwiredP));
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_CONTEXT_SENSITIVEp) {
      if (setvalueP) {
        self->slot_context_sensitiveP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->slot_context_sensitiveP));
      }
    }
    else if (slotname == SYM_HIERARCHY_SLOT_ACCESSOR_METHODS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_SLOT_ACCESSOR_METHODS, ((List*)(value)), NULL);
      }
      else {
        return (self->slot_accessor_methods_reader());
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Storage_Slot::primary_type() {
  { Storage_Slot* self = this;

    return (SGT_HIERARCHY_STORAGE_SLOT);
  }
}

Keyword* Storage_Slot::allocation() {
  // Return the most specific :allocation facet, or
  // :instance if all inherited values are NULL.
  { Storage_Slot* self = this;

    { Storage_Slot* cursor = self;
      Keyword* value = ((Keyword*)(dynamic_slot_value(cursor, SYM_HIERARCHY_SLOT_ALLOCATION, NULL)));

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = ((Storage_Slot*)(cursor->slot_direct_equivalent));
        if (cursor != NULL) {
          value = ((Keyword*)(dynamic_slot_value(cursor, SYM_HIERARCHY_SLOT_ALLOCATION, NULL)));
        }
        else {
          return (KWD_HIERARCHY_INSTANCE);
        }
      }
    }
  }
}

Object* Storage_Slot::default_form() {
  // Returns the current value of default expression when the
  // slot has not been assigned a value.
  { Storage_Slot* self = this;

    { Storage_Slot* cursor = self;
      Object* value = dynamic_slot_value(cursor, SYM_HIERARCHY_SLOT_DEFAULT_EXPRESSION, NULL);

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = ((Storage_Slot*)(cursor->slot_direct_equivalent));
        if (cursor != NULL) {
          value = dynamic_slot_value(cursor, SYM_HIERARCHY_SLOT_DEFAULT_EXPRESSION, NULL);
        }
        else {
          return (NULL);
        }
      }
    }
  }
}

boolean Storage_Slot::requiredP() {
  // True if a value must be assigned to this slot at
  // creation time.
  { Storage_Slot* self = this;

    { Storage_Slot* cursor = self;
      boolean value = cursor->slot_requiredP;

      for (;;) {
        if (value) {
          return (value);
        }
        cursor = ((Storage_Slot*)(cursor->slot_direct_equivalent));
        if (cursor != NULL) {
          value = cursor->slot_requiredP;
        }
        else {
          return (FALSE);
        }
      }
    }
  }
}

boolean Storage_Slot::componentP() {
  // True if fillers of this slot are components of the
  // owner slot, and therefore should be deleted if the owner is deleted.
  { Storage_Slot* self = this;

    { Storage_Slot* cursor = self;
      boolean value = cursor->slot_componentP;

      for (;;) {
        if (value) {
          return (value);
        }
        cursor = ((Storage_Slot*)(cursor->slot_direct_equivalent));
        if (cursor != NULL) {
          value = cursor->slot_componentP;
        }
        else {
          return (FALSE);
        }
      }
    }
  }
}

Symbol* Storage_Slot::reader() {
  // Name of a method called to read the value of the slot
  // 'self'.
  { Storage_Slot* self = this;

    { Storage_Slot* cursor = self;
      Symbol* value = ((Symbol*)(dynamic_slot_value(cursor, SYM_HIERARCHY_SLOT_READER, NULL)));

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = ((Storage_Slot*)(cursor->slot_direct_equivalent));
        if (cursor != NULL) {
          value = ((Symbol*)(dynamic_slot_value(cursor, SYM_HIERARCHY_SLOT_READER, NULL)));
        }
        else {
          return (NULL);
        }
      }
    }
  }
}

Symbol* Storage_Slot::writer() {
  // Name of a method called to write the value of the slot
  // 'self'.
  { Storage_Slot* self = this;

    { Storage_Slot* cursor = self;
      Symbol* value = ((Symbol*)(dynamic_slot_value(cursor, SYM_HIERARCHY_SLOT_WRITER, NULL)));

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = ((Storage_Slot*)(cursor->slot_direct_equivalent));
        if (cursor != NULL) {
          value = ((Symbol*)(dynamic_slot_value(cursor, SYM_HIERARCHY_SLOT_WRITER, NULL)));
        }
        else {
          return (NULL);
        }
      }
    }
  }
}

Method_Slot* new_method_slot() {
  { Method_Slot* self = NULL;

    self = new Method_Slot;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->abstractP = FALSE;
    self->slot_direct_equivalent = NULL;
    self->slot_markedP = FALSE;
    self->slot_externalP = FALSE;
    self->slot_renamedP = FALSE;
    self->slot_publicP = FALSE;
    self->slot_slotref = NULL;
    self->slot_base_type = NULL;
    self->slot_owner = NULL;
    self->slot_name = NULL;
    self->method_functionP = FALSE;
    self->function_code = NULL;
    self->method_code = ((cpp_method_code)(NULL));
    self->method_stringified_source = NULL;
    self->method_return_type_specifiers = NULL;
    self->method_parameter_type_specifiers = NULL;
    self->method_parameter_names = NULL;
    self->method_setterP = FALSE;
    return (self);
  }
}

List* Method_Slot::method_parameter_names_reader() {
  { Method_Slot* self = this;

    { List* answer = self->method_parameter_names;

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Method_Slot::method_parameter_type_specifiers_reader() {
  { Method_Slot* self = this;

    { List* answer = self->method_parameter_type_specifiers;

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Method_Slot::method_parameter_directions_reader() {
  { Method_Slot* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_METHOD_PARAMETER_DIRECTIONS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Method_Slot::method_return_type_specifiers_reader() {
  { Method_Slot* self = this;

    { List* answer = self->method_return_type_specifiers;

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Method_Slot::method_variable_argumentsP_reader() {
  { Method_Slot* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_METHOD_VARIABLE_ARGUMENTSp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Method_Slot::method_body_argumentP_reader() {
  { Method_Slot* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_METHOD_BODY_ARGUMENTp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Method_Slot::method_auxiliaryP_reader() {
  { Method_Slot* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_SLOT_AUXILIARYp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Method_Slot::method_nativeP_reader() {
  { Method_Slot* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_METHOD_NATIVEp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Method_Slot::method_globally_inlineP_reader() {
  { Method_Slot* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_METHOD_GLOBALLY_INLINEp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Method_Slot::method_inlined_functions_reader() {
  { Method_Slot* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_METHOD_INLINED_FUNCTIONS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Method_Slot::method_commandP_reader() {
  { Method_Slot* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_METHOD_COMMANDp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Method_Slot::method_evaluate_argumentsP_reader() {
  { Method_Slot* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_METHOD_EVALUATE_ARGUMENTSp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (TRUE);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Method_Slot::method_lisp_macroP_reader() {
  { Method_Slot* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_METHOD_LISP_MACROp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (NULL_BOOLEAN);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_method_slot_slot_value(Method_Slot* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_METHOD_SETTERp) {
      if (setvalueP) {
        self->method_setterP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->method_setterP));
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_PARAMETER_NAMES) {
      if (setvalueP) {
        self->method_parameter_names = ((List*)(value));
      }
      else {
        return (self->method_parameter_names_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_PARAMETER_TYPE_SPECIFIERS) {
      if (setvalueP) {
        self->method_parameter_type_specifiers = ((List*)(value));
      }
      else {
        return (self->method_parameter_type_specifiers_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_PARAMETER_DIRECTIONS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_METHOD_PARAMETER_DIRECTIONS, ((List*)(value)), NULL);
      }
      else {
        return (self->method_parameter_directions_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_RETURN_TYPE_SPECIFIERS) {
      if (setvalueP) {
        self->method_return_type_specifiers = ((List*)(value));
      }
      else {
        return (self->method_return_type_specifiers_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_STRINGIFIED_SOURCE) {
      if (setvalueP) {
        self->method_stringified_source = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->method_stringified_source));
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_CODE) {
      if (setvalueP) {
        self->method_code = ((Method_Code_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (method_code_wrap_literal(self->method_code));
      }
    }
    else if (slotname == SYM_HIERARCHY_FUNCTION_CODE) {
      if (setvalueP) {
        self->function_code = ((Function_Code_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (function_code_wrap_literal(self->function_code));
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_FUNCTIONp) {
      if (setvalueP) {
        self->method_functionP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->method_functionP));
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_VARIABLE_ARGUMENTSp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_METHOD_VARIABLE_ARGUMENTSp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->method_variable_argumentsP_reader()));
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_BODY_ARGUMENTp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_METHOD_BODY_ARGUMENTp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->method_body_argumentP_reader()));
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_AUXILIARYp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_SLOT_AUXILIARYp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->method_auxiliaryP_reader()));
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_NATIVEp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_METHOD_NATIVEp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->method_nativeP_reader()));
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_GLOBALLY_INLINEp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_METHOD_GLOBALLY_INLINEp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->method_globally_inlineP_reader()));
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_INLINED_FUNCTIONS) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_METHOD_INLINED_FUNCTIONS, ((List*)(value)), NULL);
      }
      else {
        return (self->method_inlined_functions_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_COMMANDp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_METHOD_COMMANDp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->method_commandP_reader()));
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_EVALUATE_ARGUMENTSp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_METHOD_EVALUATE_ARGUMENTSp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->method_evaluate_argumentsP_reader()));
      }
    }
    else if (slotname == SYM_HIERARCHY_METHOD_LISP_MACROp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_METHOD_LISP_MACROp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->method_lisp_macroP_reader()));
      }
    }
    else {
      if (slotname == SYM_HIERARCHY_METHOD_DOCUMENTATION) {
        slotname = SYM_HIERARCHY_DOCUMENTATION;
      }
      else if (slotname == SYM_HIERARCHY_METHOD_STORAGE_SLOT) {
        slotname = SYM_HIERARCHY_STORAGE_SLOT;
      }
      else {
      }
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Method_Slot::primary_type() {
  { Method_Slot* self = this;

    return (SGT_HIERARCHY_METHOD_SLOT);
  }
}

boolean Method_Slot::setterP() {
  { Method_Slot* self = this;

    return (self->method_setterP);
  }
}

void Method_Slot::print_object(ostream* stream) {
  { Method_Slot* self = this;

    if (self->method_functionP) {
      *(stream) << "|F|" << self->slot_name->symbol_name;
    }
    else {
      *(stream) << "|M|" << self->slot_owner->symbol_name << "." << self->slot_name->symbol_name;
    }
  }
}

void Compound_Type_Specifier::print_object(ostream* stream) {
  { Compound_Type_Specifier* self = this;

    *(stream) << "|TS|" << yield_type_spec_tree(self);
  }
}

Parametric_Type_Specifier* new_parametric_type_specifier() {
  { Parametric_Type_Specifier* self = NULL;

    self = make_parametric_type_specifier();
    self->specifier_sequence_size = NULL_INTEGER;
    self->specifier_parameter_types = new_list();
    self->specifier_base_type = NULL;
    return (self);
  }
}

Object* access_parametric_type_specifier_slot_value(Parametric_Type_Specifier* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_SPECIFIER_BASE_TYPE) {
    if (setvalueP) {
      self->specifier_base_type = ((Surrogate*)(value));
    }
    else {
      return (self->specifier_base_type);
    }
  }
  else if (slotname == SYM_HIERARCHY_SPECIFIER_PARAMETER_TYPES) {
    if (setvalueP) {
      self->specifier_parameter_types = ((List*)(value));
    }
    else {
      return (self->specifier_parameter_types);
    }
  }
  else if (slotname == SYM_HIERARCHY_SPECIFIER_SEQUENCE_SIZE) {
    if (setvalueP) {
      self->specifier_sequence_size = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->specifier_sequence_size));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Parametric_Type_Specifier::primary_type() {
  { Parametric_Type_Specifier* self = this;

    return (SGT_HIERARCHY_PARAMETRIC_TYPE_SPECIFIER);
  }
}

Transient_Type_Specifier* new_transient_type_specifier() {
  { Transient_Type_Specifier* self = NULL;

    self = oUNUSED_TRANSIENT_TYPE_SPECIFIER_So;
    if (self != NULL) {
      oUNUSED_TRANSIENT_TYPE_SPECIFIER_So = oUNUSED_TRANSIENT_TYPE_SPECIFIER_So->next_sweep_list_object;
      terminate_transient_type_specifierP(self);
    }
    else {
      self = new Transient_Type_Specifier;
      self->next_sweep_list_object = oALL_TRANSIENT_TYPE_SPECIFIER_So;
      oALL_TRANSIENT_TYPE_SPECIFIER_So = self;
    }
    self->specifier_sequence_size = NULL_INTEGER;
    self->specifier_parameter_types = new_list();
    self->specifier_base_type = NULL;
    return (self);
  }
}

void Transient_Type_Specifier::free() {
  { Transient_Type_Specifier* self = this;

  }
}

void Transient_Type_Specifier::sweep() {
  { Transient_Type_Specifier* self = this;

    oUNUSED_TRANSIENT_TYPE_SPECIFIER_So = oALL_TRANSIENT_TYPE_SPECIFIER_So;
  }
}

Object* access_transient_type_specifier_slot_value(Transient_Type_Specifier* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT) {
    if (setvalueP) {
      self->next_sweep_list_object = ((Transient_Type_Specifier*)(value));
    }
    else {
      return (self->next_sweep_list_object);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Transient_Type_Specifier::primary_type() {
  { Transient_Type_Specifier* self = this;

    return (SGT_HIERARCHY_TRANSIENT_TYPE_SPECIFIER);
  }
}

Anchored_Type_Specifier* new_anchored_type_specifier() {
  { Anchored_Type_Specifier* self = NULL;

    self = new Anchored_Type_Specifier;
    self->specifier_parameter_name = NULL;
    return (self);
  }
}

Object* access_anchored_type_specifier_slot_value(Anchored_Type_Specifier* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_SPECIFIER_PARAMETER_NAME) {
    if (setvalueP) {
      self->specifier_parameter_name = ((Symbol*)(value));
    }
    else {
      return (self->specifier_parameter_name);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Anchored_Type_Specifier::primary_type() {
  { Anchored_Type_Specifier* self = this;

    return (SGT_HIERARCHY_ANCHORED_TYPE_SPECIFIER);
  }
}

Table* new_table() {
  { Table* self = NULL;

    self = new Table;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->abstractP = FALSE;
    self->slot_direct_equivalent = NULL;
    self->slot_markedP = FALSE;
    self->slot_externalP = FALSE;
    self->slot_renamedP = FALSE;
    self->slot_publicP = FALSE;
    self->slot_slotref = NULL;
    self->slot_base_type = NULL;
    self->slot_owner = NULL;
    self->slot_name = NULL;
    self->tuple_domains = NULL;
    return (self);
  }
}

boolean Table::variable_arityP_reader() {
  { Table* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_VARIABLE_ARITYp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (FALSE);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_table_slot_value(Table* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_TUPLE_DOMAINS) {
      if (setvalueP) {
        self->tuple_domains = ((List*)(value));
      }
      else {
        return (self->tuple_domains);
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_ARITYp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_VARIABLE_ARITYp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->variable_arityP_reader()));
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Table::primary_type() {
  { Table* self = this;

    return (SGT_HIERARCHY_TABLE);
  }
}

void Table::print_object(ostream* stream) {
  { Table* self = this;

    *(stream) << "|T|" << self->slot_name->symbol_name;
  }
}

Global_Variable* new_global_variable() {
  { Global_Variable* self = NULL;

    self = new Global_Variable;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->variable_stringified_source = NULL;
    self->documentation = NULL;
    self->variable_value_stack = NULL;
    self->variable_set_value_code = NULL;
    self->variable_get_value_code = NULL;
    self->variable_auxiliaryP = FALSE;
    self->variable_publicP = FALSE;
    self->variable_constantP = FALSE;
    self->variable_specialP = FALSE;
    self->variable_type = NULL;
    self->variable_name = NULL;
    return (self);
  }
}

Object* access_global_variable_slot_value(Global_Variable* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_DOCUMENTATION) {
      if (setvalueP) {
        self->documentation = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->documentation));
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_NAME) {
      if (setvalueP) {
        self->variable_name = ((Symbol*)(value));
      }
      else {
        return (self->variable_name);
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_TYPE) {
      if (setvalueP) {
        self->variable_type = ((Surrogate*)(value));
      }
      else {
        return (self->variable_type);
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_SPECIALp) {
      if (setvalueP) {
        self->variable_specialP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->variable_specialP));
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_CONSTANTp) {
      if (setvalueP) {
        self->variable_constantP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->variable_constantP));
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_PUBLICp) {
      if (setvalueP) {
        self->variable_publicP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->variable_publicP));
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_AUXILIARYp) {
      if (setvalueP) {
        self->variable_auxiliaryP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->variable_auxiliaryP));
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_GET_VALUE_CODE) {
      if (setvalueP) {
        self->variable_get_value_code = ((Function_Code_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (function_code_wrap_literal(self->variable_get_value_code));
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_SET_VALUE_CODE) {
      if (setvalueP) {
        self->variable_set_value_code = ((Function_Code_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (function_code_wrap_literal(self->variable_set_value_code));
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_VALUE_STACK) {
      if (setvalueP) {
        self->variable_value_stack = ((List*)(value));
      }
      else {
        return (self->variable_value_stack);
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_DOCUMENTATION) {
      if (setvalueP) {
        self->documentation = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->documentation));
      }
    }
    else if (slotname == SYM_HIERARCHY_VARIABLE_STRINGIFIED_SOURCE) {
      if (setvalueP) {
        self->variable_stringified_source = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->variable_stringified_source));
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Global_Variable::primary_type() {
  { Global_Variable* self = this;

    return (SGT_HIERARCHY_GLOBAL_VARIABLE);
  }
}

char* Global_Variable::name() {
  { Global_Variable* self = this;

    return (self->variable_name->symbol_name);
  }
}

Surrogate* Global_Variable::type() {
  { Global_Variable* self = this;

    return (self->variable_type);
  }
}

Quoted_Expression* new_quoted_expression() {
  { Quoted_Expression* self = NULL;

    self = new Quoted_Expression;
    self->quotation_table_offset = NULL_INTEGER;
    return (self);
  }
}

Object* access_quoted_expression_slot_value(Quoted_Expression* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_QUOTATION_TABLE_OFFSET) {
    if (setvalueP) {
      self->quotation_table_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->quotation_table_offset));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Quoted_Expression::primary_type() {
  { Quoted_Expression* self = this;

    return (SGT_HIERARCHY_QUOTED_EXPRESSION);
  }
}

Object* access_context_slot_value(Context* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_CHILD_CONTEXTS) {
      if (setvalueP) {
        self->child_contexts = ((List*)(value));
      }
      else {
        return (self->child_contexts);
      }
    }
    else if (slotname == SYM_HIERARCHY_ALL_SUPER_CONTEXTS) {
      if (setvalueP) {
        self->all_super_contexts = ((Cons*)(value));
      }
      else {
        return (self->all_super_contexts);
      }
    }
    else if (slotname == SYM_HIERARCHY_BASE_MODULE) {
      if (setvalueP) {
        self->base_module = ((Module*)(value));
      }
      else {
        return (self->base_module);
      }
    }
    else if (slotname == SYM_HIERARCHY_CONTEXT_NUMBER) {
      if (setvalueP) {
        self->context_number = ((Integer_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (integer_wrap_literal(self->context_number));
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

char* Context::context_name() {
  { Context* self = this;

    { Context* aux = self;

      { Context* aux_001 = aux;

        if (taxonomy_isaP(aux, SGT_HIERARCHY_MODULE)) {
          { Module* aux = NULL;

            aux = ((Module*)(aux_001));
            return (aux->module_name);
          }
        }
        else if (taxonomy_isaP(aux, SGT_HIERARCHY_WORLD)) {
          { World* aux = NULL;

            aux = ((World*)(aux_001));
            return (((String_Wrapper*)(dynamic_slot_value(aux, SYM_HIERARCHY_WORLD_NAME, NULL_STRING_WRAPPER)))->wrapper_value);
          }
        }
        else {
          cerr << "`" << aux << "'" << " is not a valid case option";
        }
      }
    }
  }
}

void Context::print_object(ostream* stream) {
  { Context* self = this;

    print_context(self, stream);
  }
}

Module* new_module() {
  { Module* self = NULL;

    self = new Module;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->context_number = NULL_INTEGER;
    self->base_module = NULL;
    self->all_super_contexts = NULL;
    self->child_contexts = new_list();
    self->elaborated_world = NULL;
    self->indexical_offset_table = NULL;
    self->surrogate_offset_table = NULL;
    self->symbol_offset_table = NULL;
    self->cardinal_module = NULL;
    self->stringified_options = NULL;
    self->module_stringified_source = NULL;
    self->module_full_name = NULL;
    self->module_name = NULL;
    self->case_sensitiveP = FALSE;
    self->open_world_assumptionP = FALSE;
    self->definitions_file = NULL;
    self->code_files = new_list();
    self->directory_file = NULL;
    self->module_native_package = NULL;
    self->used_by = new_list();
    self->uses = new_list();
    self->requires = NULL;
    self->documentation = NULL;
    self->parent_modules = new_list();
    return (self);
  }
}

List* Module::shadowed_surrogates_reader() {
  { Module* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_HIERARCHY_SHADOWED_SURROGATES, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

char* Module::module_native_package_reader() {
  { Module* self = this;

    { char* answer = self->module_native_package;

      if (answer == NULL) {
        return ("STELLA");
      }
      else {
        return (answer);
      }
    }
  }
}

Keyword* Module::logic_dialect_reader() {
  { Module* self = this;

    { Keyword* answer = ((Keyword*)(dynamic_slot_value(self, SYM_HIERARCHY_LOGIC_DIALECT, NULL)));

      if (answer == NULL) {
        return (KWD_HIERARCHY_KIF);
      }
      else {
        return (answer);
      }
    }
  }
}

boolean Module::clearableP_reader() {
  { Module* self = this;

    { boolean answer = ((Boolean_Wrapper*)(dynamic_slot_value(self, SYM_HIERARCHY_CLEARABLEp, NULL_BOOLEAN_WRAPPER)))->wrapper_value;

      if (answer == NULL_BOOLEAN) {
        return (TRUE);
      }
      else {
        return (answer);
      }
    }
  }
}

Object* access_module_slot_value(Module* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_PARENT_MODULES) {
      if (setvalueP) {
        self->parent_modules = ((List*)(value));
      }
      else {
        return (self->parent_modules);
      }
    }
    else if (slotname == SYM_HIERARCHY_DOCUMENTATION) {
      if (setvalueP) {
        self->documentation = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->documentation));
      }
    }
    else if (slotname == SYM_HIERARCHY_REQUIRES) {
      if (setvalueP) {
        self->requires = ((List*)(value));
      }
      else {
        return (self->requires);
      }
    }
    else if (slotname == SYM_HIERARCHY_USES) {
      if (setvalueP) {
        self->uses = ((List*)(value));
      }
      else {
        return (self->uses);
      }
    }
    else if (slotname == SYM_HIERARCHY_USED_BY) {
      if (setvalueP) {
        self->used_by = ((List*)(value));
      }
      else {
        return (self->used_by);
      }
    }
    else if (slotname == SYM_HIERARCHY_SHADOWED_SURROGATES) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_SHADOWED_SURROGATES, ((List*)(value)), NULL);
      }
      else {
        return (self->shadowed_surrogates_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_MODULE_NATIVE_PACKAGE) {
      if (setvalueP) {
        self->module_native_package = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->module_native_package_reader()));
      }
    }
    else if (slotname == SYM_HIERARCHY_DIRECTORY_FILE) {
      if (setvalueP) {
        self->directory_file = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->directory_file));
      }
    }
    else if (slotname == SYM_HIERARCHY_CODE_FILES) {
      if (setvalueP) {
        self->code_files = ((List*)(value));
      }
      else {
        return (self->code_files);
      }
    }
    else if (slotname == SYM_HIERARCHY_DEFINITIONS_FILE) {
      if (setvalueP) {
        self->definitions_file = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->definitions_file));
      }
    }
    else if (slotname == SYM_HIERARCHY_LOGIC_DIALECT) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_LOGIC_DIALECT, ((Keyword*)(value)), NULL);
      }
      else {
        return (self->logic_dialect_reader());
      }
    }
    else if (slotname == SYM_HIERARCHY_OPEN_WORLD_ASSUMPTIONp) {
      if (setvalueP) {
        self->open_world_assumptionP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->open_world_assumptionP));
      }
    }
    else if (slotname == SYM_HIERARCHY_CASE_SENSITIVEp) {
      if (setvalueP) {
        self->case_sensitiveP = ((Boolean_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (wrap_boolean(self->case_sensitiveP));
      }
    }
    else if (slotname == SYM_HIERARCHY_CLEARABLEp) {
      if (setvalueP) {
        set_dynamic_slot_value(self, SYM_HIERARCHY_CLEARABLEp, wrap_boolean(((Boolean_Wrapper*)(value))->wrapper_value), NULL_BOOLEAN_WRAPPER);
      }
      else {
        return (wrap_boolean(self->clearableP_reader()));
      }
    }
    else if (slotname == SYM_HIERARCHY_MODULE_NAME) {
      if (setvalueP) {
        self->module_name = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->module_name));
      }
    }
    else if (slotname == SYM_HIERARCHY_MODULE_FULL_NAME) {
      if (setvalueP) {
        self->module_full_name = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->module_full_name));
      }
    }
    else if (slotname == SYM_HIERARCHY_MODULE_STRINGIFIED_SOURCE) {
      if (setvalueP) {
        self->module_stringified_source = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->module_stringified_source));
      }
    }
    else if (slotname == SYM_HIERARCHY_STRINGIFIED_OPTIONS) {
      if (setvalueP) {
        self->stringified_options = ((String_Wrapper*)(value))->wrapper_value;
      }
      else {
        return (string_wrap_literal(self->stringified_options));
      }
    }
    else if (slotname == SYM_HIERARCHY_CARDINAL_MODULE) {
      if (setvalueP) {
        self->cardinal_module = ((Module*)(value));
      }
      else {
        return (self->cardinal_module);
      }
    }
    else if (slotname == SYM_HIERARCHY_SYMBOL_OFFSET_TABLE) {
      if (setvalueP) {
        self->symbol_offset_table = ((String_To_Integer_Hash_Table*)(value));
      }
      else {
        return (self->symbol_offset_table);
      }
    }
    else if (slotname == SYM_HIERARCHY_SURROGATE_OFFSET_TABLE) {
      if (setvalueP) {
        self->surrogate_offset_table = ((String_To_Integer_Hash_Table*)(value));
      }
      else {
        return (self->surrogate_offset_table);
      }
    }
    else if (slotname == SYM_HIERARCHY_INDEXICAL_OFFSET_TABLE) {
      if (setvalueP) {
        self->indexical_offset_table = ((String_To_Integer_Hash_Table*)(value));
      }
      else {
        return (self->indexical_offset_table);
      }
    }
    else if (slotname == SYM_HIERARCHY_ELABORATED_WORLD) {
      if (setvalueP) {
        self->elaborated_world = ((World*)(value));
      }
      else {
        return (self->elaborated_world);
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* Module::primary_type() {
  { Module* self = this;

    return (SGT_HIERARCHY_MODULE);
  }
}

char* Module::native_package() {
  { Module* self = this;

    { Module* cursor = self;
      char* value = cursor->module_native_package;

      for (;;) {
        if (value != NULL) {
          return (value);
        }
        cursor = ((Module*)(cursor->parent_modules->first()));
        if (cursor != NULL) {
          value = cursor->module_native_package;
        }
        else {
          return ("STELLA");
        }
      }
    }
  }
}

char* Module::name() {
  { Module* self = this;

    return (self->module_name);
  }
}

Module* Module::parent_module() {
  { Module* self = this;

    return (((Module*)(((Context*)(self->parent_contexts()->pop())))));
  }
}

boolean Module::closed_world_assumptionP() {
  { Module* self = this;

    return (!self->open_world_assumptionP);
  }
}

World* new_world() {
  { World* self = NULL;

    self = new World;
    self->bits = ((int)(NULL_INTEGER));
    self->dynamic_slots = new_key_value_list();
    self->context_number = NULL_INTEGER;
    self->base_module = NULL;
    self->all_super_contexts = NULL;
    self->child_contexts = new_list();
    self->parent_context = NULL;
    return (self);
  }
}

Object* access_world_slot_value(World* self, Symbol* slotname, Object* value, boolean setvalueP) {
  { Object* dummy1;

    if (slotname == SYM_HIERARCHY_PARENT_CONTEXT) {
      if (setvalueP) {
        self->parent_context = ((Context*)(value));
      }
      else {
        return (self->parent_context);
      }
    }
    else if (slotname == SYM_HIERARCHY_CHILD_CONTEXTS) {
      if (setvalueP) {
        self->child_contexts = ((List*)(value));
      }
      else {
        return (self->child_contexts);
      }
    }
    else {
      if (setvalueP) {
        help_set_dynamic_slot_value(self->dynamic_slots, slotname, value, dummy1);
      }
      else {
        return (self->dynamic_slots->lookup(slotname));
      }
    }
    if (setvalueP) {
      return (value);
    }
  }
}

Surrogate* World::primary_type() {
  { World* self = this;

    return (SGT_HIERARCHY_WORLD);
  }
}

Cs_Value* new_cs_value() {
  { Cs_Value* self = NULL;

    self = new Cs_Value;
    self->the_kv_list = NULL;
    return (self);
  }
}

Surrogate* Cs_Value::primary_type() {
  { Cs_Value* self = this;

    return (SGT_HIERARCHY_CS_VALUE);
  }
}

Interval* new_interval() {
  { Interval* self = NULL;

    self = new Interval;
    self->upper_bound = NULL_INTEGER;
    self->lower_bound = NULL_INTEGER;
    return (self);
  }
}

Object* access_interval_slot_value(Interval* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_LOWER_BOUND) {
    if (setvalueP) {
      self->lower_bound = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->lower_bound));
    }
  }
  else if (slotname == SYM_HIERARCHY_UPPER_BOUND) {
    if (setvalueP) {
      self->upper_bound = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->upper_bound));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Interval::primary_type() {
  { Interval* self = this;

    return (SGT_HIERARCHY_INTERVAL);
  }
}

void Interval::print_object(ostream* stream) {
  { Interval* self = this;

    *(stream) << "[" << self->lower_bound << "," << self->upper_bound << "]";
  }
}

Taxonomy_Node* new_taxonomy_node() {
  { Taxonomy_Node* self = NULL;

    self = new Taxonomy_Node;
    self->native_object = NULL;
    self->label = NULL_INTEGER;
    self->total_ancestors = 1;
    self->intervals = NIL;
    self->initial_interval = NULL;
    self->first_interval_upper_bound = -1;
    self->first_interval_lower_bound = -1;
    self->children = NIL;
    self->tree_children = NIL;
    self->parents = NIL;
    return (self);
  }
}

Object* access_taxonomy_node_slot_value(Taxonomy_Node* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_PARENTS) {
    if (setvalueP) {
      self->parents = ((Cons*)(value));
    }
    else {
      return (self->parents);
    }
  }
  else if (slotname == SYM_HIERARCHY_TREE_CHILDREN) {
    if (setvalueP) {
      self->tree_children = ((Cons*)(value));
    }
    else {
      return (self->tree_children);
    }
  }
  else if (slotname == SYM_HIERARCHY_CHILDREN) {
    if (setvalueP) {
      self->children = ((Cons*)(value));
    }
    else {
      return (self->children);
    }
  }
  else if (slotname == SYM_HIERARCHY_FIRST_INTERVAL_LOWER_BOUND) {
    if (setvalueP) {
      self->first_interval_lower_bound = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->first_interval_lower_bound));
    }
  }
  else if (slotname == SYM_HIERARCHY_FIRST_INTERVAL_UPPER_BOUND) {
    if (setvalueP) {
      self->first_interval_upper_bound = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->first_interval_upper_bound));
    }
  }
  else if (slotname == SYM_HIERARCHY_INITIAL_INTERVAL) {
    if (setvalueP) {
      self->initial_interval = ((Interval*)(value));
    }
    else {
      return (self->initial_interval);
    }
  }
  else if (slotname == SYM_HIERARCHY_INTERVALS) {
    if (setvalueP) {
      self->intervals = ((Cons*)(value));
    }
    else {
      return (self->intervals);
    }
  }
  else if (slotname == SYM_HIERARCHY_TOTAL_ANCESTORS) {
    if (setvalueP) {
      self->total_ancestors = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->total_ancestors));
    }
  }
  else if (slotname == SYM_HIERARCHY_LABEL) {
    if (setvalueP) {
      self->label = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->label));
    }
  }
  else if (slotname == SYM_HIERARCHY_NATIVE_OBJECT) {
    if (setvalueP) {
      self->native_object = value;
    }
    else {
      return (self->native_object);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Taxonomy_Node::primary_type() {
  { Taxonomy_Node* self = this;

    return (SGT_HIERARCHY_TAXONOMY_NODE);
  }
}

void Taxonomy_Node::print_object(ostream* stream) {
  { Taxonomy_Node* self = this;

    *(stream) << "|TN|" << self->label << " " << self->intervals << " " << self->native_object;
  }
}

Taxonomy_Graph* new_taxonomy_graph() {
  { Taxonomy_Graph* self = NULL;

    self = new Taxonomy_Graph;
    self->broken_links = NIL;
    self->roots = NIL;
    self->largest_postorder_number = NULL_INTEGER;
    self->renumber_if_out_of_numbersP = FALSE;
    self->incremental_modeP = FALSE;
    return (self);
  }
}

Object* access_taxonomy_graph_slot_value(Taxonomy_Graph* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_INCREMENTAL_MODEp) {
    if (setvalueP) {
      self->incremental_modeP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->incremental_modeP));
    }
  }
  else if (slotname == SYM_HIERARCHY_RENUMBER_IF_OUT_OF_NUMBERSp) {
    if (setvalueP) {
      self->renumber_if_out_of_numbersP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->renumber_if_out_of_numbersP));
    }
  }
  else if (slotname == SYM_HIERARCHY_LARGEST_POSTORDER_NUMBER) {
    if (setvalueP) {
      self->largest_postorder_number = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->largest_postorder_number));
    }
  }
  else if (slotname == SYM_HIERARCHY_ROOTS) {
    if (setvalueP) {
      self->roots = ((Cons*)(value));
    }
    else {
      return (self->roots);
    }
  }
  else if (slotname == SYM_HIERARCHY_BROKEN_LINKS) {
    if (setvalueP) {
      self->broken_links = ((Cons*)(value));
    }
    else {
      return (self->broken_links);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Taxonomy_Graph::primary_type() {
  { Taxonomy_Graph* self = this;

    return (SGT_HIERARCHY_TAXONOMY_GRAPH);
  }
}

void Taxonomy_Graph::print_object(ostream* stream) {
  { Taxonomy_Graph* self = this;

    *(stream) << "|TG|" << self->roots;
  }
}

Exception* new_exception() {
  { Exception* self = NULL;

    self = new Exception;
    return (self);
  }
}

Surrogate* Exception::primary_type() {
  { Exception* self = this;

    return (SGT_HIERARCHY_EXCEPTION);
  }
}

Stella_Exception* new_stella_exception() {
  { Stella_Exception* self = NULL;

    self = new Stella_Exception;
    return (self);
  }
}

Surrogate* Stella_Exception::primary_type() {
  { Stella_Exception* self = this;

    return (SGT_HIERARCHY_STELLA_EXCEPTION);
  }
}

Read_Exception* new_read_exception() {
  { Read_Exception* self = NULL;

    self = new Read_Exception;
    return (self);
  }
}

Surrogate* Read_Exception::primary_type() {
  { Read_Exception* self = this;

    return (SGT_HIERARCHY_READ_EXCEPTION);
  }
}

Unhandled_Exception* new_unhandled_exception() {
  { Unhandled_Exception* self = NULL;

    self = new Unhandled_Exception;
    return (self);
  }
}

Surrogate* Unhandled_Exception::primary_type() {
  { Unhandled_Exception* self = this;

    return (SGT_HIERARCHY_UNHANDLED_EXCEPTION);
  }
}

Integer_Wrapper* new_integer_wrapper(int wrapper_value) {
  { Integer_Wrapper* self = NULL;

    self = ((Integer_Wrapper*)(oRECYCLED_INTEGER_WRAPPER_So->pop()));
    if (self != NULL) {
    }
    else {
      self = new Integer_Wrapper;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Integer_Wrapper::free() {
  { Integer_Wrapper* self = this;

    if (!(self->terminate_wrapperP())) {
      return;
    }
    oRECYCLED_INTEGER_WRAPPER_So->push(self);
  }
}

Object* access_integer_wrapper_slot_value(Integer_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_WRAPPER_VALUE) {
    if (setvalueP) {
      self->wrapper_value = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->wrapper_value));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Integer_Wrapper::primary_type() {
  { Integer_Wrapper* self = this;

    return (SGT_HIERARCHY_INTEGER_WRAPPER);
  }
}

void Integer_Wrapper::print_object(ostream* stream) {
  { Integer_Wrapper* self = this;

    if (oPRINTREADABLYpo) {
      *(stream) << self->wrapper_value;
    }
    else {
      *(stream) << ((transient_objectP(self) ? ((char*)("!L!")) : ((char*)("|L|")))) << self->wrapper_value;
    }
  }
}

Float_Wrapper* new_float_wrapper(double wrapper_value) {
  { Float_Wrapper* self = NULL;

    self = ((Float_Wrapper*)(oRECYCLED_FLOAT_WRAPPER_So->pop()));
    if (self != NULL) {
    }
    else {
      self = new Float_Wrapper;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Float_Wrapper::free() {
  { Float_Wrapper* self = this;

    if (!(self->terminate_wrapperP())) {
      return;
    }
    oRECYCLED_FLOAT_WRAPPER_So->push(self);
  }
}

Object* access_float_wrapper_slot_value(Float_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_WRAPPER_VALUE) {
    if (setvalueP) {
      self->wrapper_value = ((Float_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (float_wrap_literal(self->wrapper_value));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Float_Wrapper::primary_type() {
  { Float_Wrapper* self = this;

    return (SGT_HIERARCHY_FLOAT_WRAPPER);
  }
}

void Float_Wrapper::print_object(ostream* stream) {
  { Float_Wrapper* self = this;

    if (oPRINTREADABLYpo) {
      *(stream) << self->wrapper_value;
    }
    else {
      *(stream) << ((transient_objectP(self) ? ((char*)("!L!")) : ((char*)("|L|")))) << self->wrapper_value;
    }
  }
}

String_Wrapper* new_string_wrapper(char* wrapper_value) {
  { String_Wrapper* self = NULL;

    self = ((String_Wrapper*)(oRECYCLED_STRING_WRAPPER_So->pop()));
    if (self != NULL) {
    }
    else {
      self = new String_Wrapper;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void String_Wrapper::free() {
  { String_Wrapper* self = this;

    if (!(self->terminate_wrapperP())) {
      return;
    }
    oRECYCLED_STRING_WRAPPER_So->push(self);
  }
}

Object* access_string_wrapper_slot_value(String_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_WRAPPER_VALUE) {
    if (setvalueP) {
      self->wrapper_value = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->wrapper_value));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* String_Wrapper::primary_type() {
  { String_Wrapper* self = this;

    return (SGT_HIERARCHY_STRING_WRAPPER);
  }
}

void String_Wrapper::print_object(ostream* stream) {
  { String_Wrapper* self = this;

    { char* value = self->wrapper_value;

      if (oPRINTREADABLYpo) {
        print_string_readably(value, stream);
      }
      else {
        if (value != NULL) {
          *(stream) << ((transient_objectP(self) ? ((char*)("!L!")) : ((char*)("|L|")))) << "\"" << value << "\"";
        }
        else {
          *(stream) << ((transient_objectP(self) ? ((char*)("!L!")) : ((char*)("|L|")))) << "NULL-STRING";
        }
      }
    }
  }
}

Character_Wrapper* new_character_wrapper(char wrapper_value) {
  { Character_Wrapper* self = NULL;

    self = ((Character_Wrapper*)(oRECYCLED_CHARACTER_WRAPPER_So->pop()));
    if (self != NULL) {
    }
    else {
      self = new Character_Wrapper;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Character_Wrapper::free() {
  { Character_Wrapper* self = this;

    if (!(self->terminate_wrapperP())) {
      return;
    }
    oRECYCLED_CHARACTER_WRAPPER_So->push(self);
  }
}

Object* access_character_wrapper_slot_value(Character_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_WRAPPER_VALUE) {
    if (setvalueP) {
      self->wrapper_value = ((Character_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (character_wrap_literal(self->wrapper_value));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Character_Wrapper::primary_type() {
  { Character_Wrapper* self = this;

    return (SGT_HIERARCHY_CHARACTER_WRAPPER);
  }
}

void Character_Wrapper::print_object(ostream* stream) {
  { Character_Wrapper* self = this;

    if (oPRINTREADABLYpo) {
      print_character(self->wrapper_value, stream);
    }
    else {
      {
        *(stream) << ((transient_objectP(self) ? ((char*)("!L!")) : ((char*)("|L|"))));
        print_character(self->wrapper_value, stream);
      }
    }
  }
}

Boolean_Wrapper* new_boolean_wrapper(boolean wrapper_value) {
  { Boolean_Wrapper* self = NULL;

    self = new Boolean_Wrapper;
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Boolean_Wrapper::free() {
  { Boolean_Wrapper* self = this;

    if (self->terminate_wrapperP()) {
      unmake(self);
    }
  }
}

Object* access_boolean_wrapper_slot_value(Boolean_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_WRAPPER_VALUE) {
    if (setvalueP) {
      self->wrapper_value = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->wrapper_value));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Boolean_Wrapper::primary_type() {
  { Boolean_Wrapper* self = this;

    return (SGT_HIERARCHY_BOOLEAN_WRAPPER);
  }
}

void Boolean_Wrapper::print_object(ostream* stream) {
  { Boolean_Wrapper* self = this;

    *(stream) << ((oPRINTREADABLYpo ? ((char*)("")) : ((char*)("|L|")))) << (((self->wrapper_value == NULL_BOOLEAN) ? ((Symbol*)(SYM_HIERARCHY_NULL_BOOLEAN)) : ((Symbol*)((self->wrapper_value ? ((Symbol*)(SYM_HIERARCHY_TRUE)) : ((Symbol*)(SYM_HIERARCHY_FALSE)))))));
  }
}

Function_Code_Wrapper* new_function_code_wrapper(cpp_function_code wrapper_value) {
  { Function_Code_Wrapper* self = NULL;

    self = ((Function_Code_Wrapper*)(oRECYCLED_FUNCTION_CODE_WRAPPER_So->pop()));
    if (self != NULL) {
    }
    else {
      self = new Function_Code_Wrapper;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Function_Code_Wrapper::free() {
  { Function_Code_Wrapper* self = this;

    if (!(self->terminate_wrapperP())) {
      return;
    }
    oRECYCLED_FUNCTION_CODE_WRAPPER_So->push(self);
  }
}

Object* access_function_code_wrapper_slot_value(Function_Code_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_WRAPPER_VALUE) {
    if (setvalueP) {
      self->wrapper_value = ((Function_Code_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (function_code_wrap_literal(self->wrapper_value));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Function_Code_Wrapper::primary_type() {
  { Function_Code_Wrapper* self = this;

    return (SGT_HIERARCHY_FUNCTION_CODE_WRAPPER);
  }
}

Method_Code_Wrapper* new_method_code_wrapper(cpp_method_code wrapper_value) {
  { Method_Code_Wrapper* self = NULL;

    self = ((Method_Code_Wrapper*)(oRECYCLED_METHOD_CODE_WRAPPER_So->pop()));
    if (self != NULL) {
    }
    else {
      self = new Method_Code_Wrapper;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Method_Code_Wrapper::free() {
  { Method_Code_Wrapper* self = this;

    if (!(self->terminate_wrapperP())) {
      return;
    }
    oRECYCLED_METHOD_CODE_WRAPPER_So->push(self);
  }
}

Object* access_method_code_wrapper_slot_value(Method_Code_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_WRAPPER_VALUE) {
    if (setvalueP) {
      self->wrapper_value = ((Method_Code_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (method_code_wrap_literal(self->wrapper_value));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Method_Code_Wrapper::primary_type() {
  { Method_Code_Wrapper* self = this;

    return (SGT_HIERARCHY_METHOD_CODE_WRAPPER);
  }
}

Transient_Integer_Wrapper* new_transient_integer_wrapper(int wrapper_value) {
  { Transient_Integer_Wrapper* self = NULL;

    self = oUNUSED_TRANSIENT_INTEGER_WRAPPER_So;
    if (self != NULL) {
      oUNUSED_TRANSIENT_INTEGER_WRAPPER_So = oUNUSED_TRANSIENT_INTEGER_WRAPPER_So->next_sweep_list_object;
      self->terminate_wrapperP();
    }
    else {
      self = new Transient_Integer_Wrapper;
      self->next_sweep_list_object = oALL_TRANSIENT_INTEGER_WRAPPER_So;
      oALL_TRANSIENT_INTEGER_WRAPPER_So = self;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Transient_Integer_Wrapper::free() {
  { Transient_Integer_Wrapper* self = this;

  }
}

void Transient_Integer_Wrapper::sweep() {
  { Transient_Integer_Wrapper* self = this;

    oUNUSED_TRANSIENT_INTEGER_WRAPPER_So = oALL_TRANSIENT_INTEGER_WRAPPER_So;
  }
}

Object* access_transient_integer_wrapper_slot_value(Transient_Integer_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT) {
    if (setvalueP) {
      self->next_sweep_list_object = ((Transient_Integer_Wrapper*)(value));
    }
    else {
      return (self->next_sweep_list_object);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Transient_Integer_Wrapper::primary_type() {
  { Transient_Integer_Wrapper* self = this;

    return (SGT_HIERARCHY_TRANSIENT_INTEGER_WRAPPER);
  }
}

Transient_Float_Wrapper* new_transient_float_wrapper(double wrapper_value) {
  { Transient_Float_Wrapper* self = NULL;

    self = oUNUSED_TRANSIENT_FLOAT_WRAPPER_So;
    if (self != NULL) {
      oUNUSED_TRANSIENT_FLOAT_WRAPPER_So = oUNUSED_TRANSIENT_FLOAT_WRAPPER_So->next_sweep_list_object;
      self->terminate_wrapperP();
    }
    else {
      self = new Transient_Float_Wrapper;
      self->next_sweep_list_object = oALL_TRANSIENT_FLOAT_WRAPPER_So;
      oALL_TRANSIENT_FLOAT_WRAPPER_So = self;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Transient_Float_Wrapper::free() {
  { Transient_Float_Wrapper* self = this;

  }
}

void Transient_Float_Wrapper::sweep() {
  { Transient_Float_Wrapper* self = this;

    oUNUSED_TRANSIENT_FLOAT_WRAPPER_So = oALL_TRANSIENT_FLOAT_WRAPPER_So;
  }
}

Object* access_transient_float_wrapper_slot_value(Transient_Float_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT) {
    if (setvalueP) {
      self->next_sweep_list_object = ((Transient_Float_Wrapper*)(value));
    }
    else {
      return (self->next_sweep_list_object);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Transient_Float_Wrapper::primary_type() {
  { Transient_Float_Wrapper* self = this;

    return (SGT_HIERARCHY_TRANSIENT_FLOAT_WRAPPER);
  }
}

Transient_String_Wrapper* new_transient_string_wrapper(char* wrapper_value) {
  { Transient_String_Wrapper* self = NULL;

    self = ((Transient_String_Wrapper*)(oRECYCLED_TRANSIENT_STRING_WRAPPER_So->pop()));
    if (self != NULL) {
    }
    else if (oUNUSED_TRANSIENT_STRING_WRAPPER_So != NULL) {
      self = oUNUSED_TRANSIENT_STRING_WRAPPER_So;
      oUNUSED_TRANSIENT_STRING_WRAPPER_So = oUNUSED_TRANSIENT_STRING_WRAPPER_So->next_sweep_list_object;
      self->terminate_wrapperP();
    }
    else {
      self = new Transient_String_Wrapper;
      self->next_sweep_list_object = oALL_TRANSIENT_STRING_WRAPPER_So;
      oALL_TRANSIENT_STRING_WRAPPER_So = self;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Transient_String_Wrapper::free() {
  { Transient_String_Wrapper* self = this;

    self->terminate_wrapperP();
    oRECYCLED_TRANSIENT_STRING_WRAPPER_So->push(self);
  }
}

void Transient_String_Wrapper::sweep() {
  { Transient_String_Wrapper* self = this;

    oRECYCLED_TRANSIENT_STRING_WRAPPER_So->clear();
    oUNUSED_TRANSIENT_STRING_WRAPPER_So = oALL_TRANSIENT_STRING_WRAPPER_So;
  }
}

Object* access_transient_string_wrapper_slot_value(Transient_String_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT) {
    if (setvalueP) {
      self->next_sweep_list_object = ((Transient_String_Wrapper*)(value));
    }
    else {
      return (self->next_sweep_list_object);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Transient_String_Wrapper::primary_type() {
  { Transient_String_Wrapper* self = this;

    return (SGT_HIERARCHY_TRANSIENT_STRING_WRAPPER);
  }
}

Transient_Character_Wrapper* new_transient_character_wrapper(char wrapper_value) {
  { Transient_Character_Wrapper* self = NULL;

    self = oUNUSED_TRANSIENT_CHARACTER_WRAPPER_So;
    if (self != NULL) {
      oUNUSED_TRANSIENT_CHARACTER_WRAPPER_So = oUNUSED_TRANSIENT_CHARACTER_WRAPPER_So->next_sweep_list_object;
      self->terminate_wrapperP();
    }
    else {
      self = new Transient_Character_Wrapper;
      self->next_sweep_list_object = oALL_TRANSIENT_CHARACTER_WRAPPER_So;
      oALL_TRANSIENT_CHARACTER_WRAPPER_So = self;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Transient_Character_Wrapper::free() {
  { Transient_Character_Wrapper* self = this;

  }
}

void Transient_Character_Wrapper::sweep() {
  { Transient_Character_Wrapper* self = this;

    oUNUSED_TRANSIENT_CHARACTER_WRAPPER_So = oALL_TRANSIENT_CHARACTER_WRAPPER_So;
  }
}

Object* access_transient_character_wrapper_slot_value(Transient_Character_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT) {
    if (setvalueP) {
      self->next_sweep_list_object = ((Transient_Character_Wrapper*)(value));
    }
    else {
      return (self->next_sweep_list_object);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Transient_Character_Wrapper::primary_type() {
  { Transient_Character_Wrapper* self = this;

    return (SGT_HIERARCHY_TRANSIENT_CHARACTER_WRAPPER);
  }
}

Transient_Function_Code_Wrapper* new_transient_function_code_wrapper(cpp_function_code wrapper_value) {
  { Transient_Function_Code_Wrapper* self = NULL;

    self = oUNUSED_TRANSIENT_FUNCTION_CODE_WRAPPER_So;
    if (self != NULL) {
      oUNUSED_TRANSIENT_FUNCTION_CODE_WRAPPER_So = oUNUSED_TRANSIENT_FUNCTION_CODE_WRAPPER_So->next_sweep_list_object;
      self->terminate_wrapperP();
    }
    else {
      self = new Transient_Function_Code_Wrapper;
      self->next_sweep_list_object = oALL_TRANSIENT_FUNCTION_CODE_WRAPPER_So;
      oALL_TRANSIENT_FUNCTION_CODE_WRAPPER_So = self;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Transient_Function_Code_Wrapper::free() {
  { Transient_Function_Code_Wrapper* self = this;

  }
}

void Transient_Function_Code_Wrapper::sweep() {
  { Transient_Function_Code_Wrapper* self = this;

    oUNUSED_TRANSIENT_FUNCTION_CODE_WRAPPER_So = oALL_TRANSIENT_FUNCTION_CODE_WRAPPER_So;
  }
}

Object* access_transient_function_code_wrapper_slot_value(Transient_Function_Code_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT) {
    if (setvalueP) {
      self->next_sweep_list_object = ((Transient_Function_Code_Wrapper*)(value));
    }
    else {
      return (self->next_sweep_list_object);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Transient_Function_Code_Wrapper::primary_type() {
  { Transient_Function_Code_Wrapper* self = this;

    return (SGT_HIERARCHY_TRANSIENT_FUNCTION_CODE_WRAPPER);
  }
}

Transient_Method_Code_Wrapper* new_transient_method_code_wrapper(cpp_method_code wrapper_value) {
  { Transient_Method_Code_Wrapper* self = NULL;

    self = oUNUSED_TRANSIENT_METHOD_CODE_WRAPPER_So;
    if (self != NULL) {
      oUNUSED_TRANSIENT_METHOD_CODE_WRAPPER_So = oUNUSED_TRANSIENT_METHOD_CODE_WRAPPER_So->next_sweep_list_object;
      self->terminate_wrapperP();
    }
    else {
      self = new Transient_Method_Code_Wrapper;
      self->next_sweep_list_object = oALL_TRANSIENT_METHOD_CODE_WRAPPER_So;
      oALL_TRANSIENT_METHOD_CODE_WRAPPER_So = self;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Transient_Method_Code_Wrapper::free() {
  { Transient_Method_Code_Wrapper* self = this;

  }
}

void Transient_Method_Code_Wrapper::sweep() {
  { Transient_Method_Code_Wrapper* self = this;

    oUNUSED_TRANSIENT_METHOD_CODE_WRAPPER_So = oALL_TRANSIENT_METHOD_CODE_WRAPPER_So;
  }
}

Object* access_transient_method_code_wrapper_slot_value(Transient_Method_Code_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT) {
    if (setvalueP) {
      self->next_sweep_list_object = ((Transient_Method_Code_Wrapper*)(value));
    }
    else {
      return (self->next_sweep_list_object);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Transient_Method_Code_Wrapper::primary_type() {
  { Transient_Method_Code_Wrapper* self = this;

    return (SGT_HIERARCHY_TRANSIENT_METHOD_CODE_WRAPPER);
  }
}

Verbatim_String_Wrapper* new_verbatim_string_wrapper(char* wrapper_value) {
  { Verbatim_String_Wrapper* self = NULL;

    self = oUNUSED_VERBATIM_STRING_WRAPPER_So;
    if (self != NULL) {
      oUNUSED_VERBATIM_STRING_WRAPPER_So = ((Verbatim_String_Wrapper*)(oUNUSED_VERBATIM_STRING_WRAPPER_So->next_sweep_list_object));
      self->terminate_wrapperP();
    }
    else {
      self = new Verbatim_String_Wrapper;
      self->next_sweep_list_object = oALL_VERBATIM_STRING_WRAPPER_So;
      oALL_VERBATIM_STRING_WRAPPER_So = self;
    }
    self->wrapper_value = wrapper_value;
    return (self);
  }
}

void Verbatim_String_Wrapper::free() {
  { Verbatim_String_Wrapper* self = this;

  }
}

void Verbatim_String_Wrapper::sweep() {
  { Verbatim_String_Wrapper* self = this;

    oUNUSED_VERBATIM_STRING_WRAPPER_So = oALL_VERBATIM_STRING_WRAPPER_So;
  }
}

Object* access_verbatim_string_wrapper_slot_value(Verbatim_String_Wrapper* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT) {
    if (setvalueP) {
      self->next_sweep_list_object = ((Verbatim_String_Wrapper*)(value));
    }
    else {
      return (((Verbatim_String_Wrapper*)(self->next_sweep_list_object)));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Verbatim_String_Wrapper::primary_type() {
  { Verbatim_String_Wrapper* self = this;

    return (SGT_HIERARCHY_VERBATIM_STRING_WRAPPER);
  }
}

void Verbatim_String_Wrapper::print_object(ostream* stream) {
  { Verbatim_String_Wrapper* self = this;

    *(stream) << ((oPRINTREADABLYpo ? ((char*)("")) : ((char*)("!V!")))) << self->wrapper_value;
  }
}

Lisp_Cons_Iterator* new_lisp_cons_iterator() {
  { Lisp_Cons_Iterator* self = NULL;

    self = new Lisp_Cons_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->cons_iterator_cursor = NULL;
    return (self);
  }
}

Surrogate* Lisp_Cons_Iterator::primary_type() {
  { Lisp_Cons_Iterator* self = this;

    return (SGT_HIERARCHY_LISP_CONS_ITERATOR);
  }
}

Object* access_stream_slot_value(Stream* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_STATE) {
    if (setvalueP) {
      self->state = ((Keyword*)(value));
    }
    else {
      return (self->state);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Output_Stream* new_output_stream() {
  { Output_Stream* self = NULL;

    self = new Output_Stream;
    self->state = NULL;
    self->native_stream = NULL;
    return (self);
  }
}

Surrogate* Output_Stream::primary_type() {
  { Output_Stream* self = this;

    return (SGT_HIERARCHY_OUTPUT_STREAM);
  }
}

Input_Stream* new_input_stream() {
  { Input_Stream* self = NULL;

    self = new Input_Stream;
    self->state = NULL;
    self->native_stream = NULL;
    return (self);
  }
}

Surrogate* Input_Stream::primary_type() {
  { Input_Stream* self = this;

    return (SGT_HIERARCHY_INPUT_STREAM);
  }
}

Output_File_Stream* new_output_file_stream(char* filename) {
  { Output_File_Stream* self = NULL;

    self = new Output_File_Stream;
    self->state = NULL;
    self->native_stream = NULL;
    self->if_exists_action = KWD_HIERARCHY_SUPERSEDE;
    self->filename = filename;
    initialize_file_stream(self);
    return (self);
  }
}

void Output_File_Stream::free() {
  { Output_File_Stream* self = this;

    if (terminate_file_streamP(self)) {
      unmake(self);
    }
  }
}

Object* access_output_file_stream_slot_value(Output_File_Stream* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_FILENAME) {
    if (setvalueP) {
      self->filename = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->filename));
    }
  }
  else if (slotname == SYM_HIERARCHY_IF_EXISTS_ACTION) {
    if (setvalueP) {
      self->if_exists_action = ((Keyword*)(value));
    }
    else {
      return (self->if_exists_action);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Output_File_Stream::primary_type() {
  { Output_File_Stream* self = this;

    return (SGT_HIERARCHY_OUTPUT_FILE_STREAM);
  }
}

void Output_File_Stream::print_object(ostream* stream) {
  { Output_File_Stream* self = this;

    *(stream) << "|OFS|'" << self->filename << "'";
  }
}

Input_File_Stream* new_input_file_stream(char* filename) {
  { Input_File_Stream* self = NULL;

    self = new Input_File_Stream;
    self->state = NULL;
    self->native_stream = NULL;
    self->if_not_exists_action = KWD_HIERARCHY_ERROR;
    self->filename = filename;
    initialize_file_stream(self);
    return (self);
  }
}

void Input_File_Stream::free() {
  { Input_File_Stream* self = this;

    if (terminate_file_streamP(self)) {
      unmake(self);
    }
  }
}

Object* access_input_file_stream_slot_value(Input_File_Stream* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_FILENAME) {
    if (setvalueP) {
      self->filename = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->filename));
    }
  }
  else if (slotname == SYM_HIERARCHY_IF_NOT_EXISTS_ACTION) {
    if (setvalueP) {
      self->if_not_exists_action = ((Keyword*)(value));
    }
    else {
      return (self->if_not_exists_action);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Input_File_Stream::primary_type() {
  { Input_File_Stream* self = this;

    return (SGT_HIERARCHY_INPUT_FILE_STREAM);
  }
}

void Input_File_Stream::print_object(ostream* stream) {
  { Input_File_Stream* self = this;

    *(stream) << "|IFS|'" << self->filename << "'";
  }
}

Output_String_Stream* new_output_string_stream(char* the_string) {
  { Output_String_Stream* self = NULL;

    self = new Output_String_Stream;
    self->state = NULL;
    self->native_stream = NULL;
    self->the_string = the_string;
    return (self);
  }
}

Object* access_output_string_stream_slot_value(Output_String_Stream* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_THE_STRING) {
    if (setvalueP) {
      self->the_string = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->the_string));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Output_String_Stream::primary_type() {
  { Output_String_Stream* self = this;

    return (SGT_HIERARCHY_OUTPUT_STRING_STREAM);
  }
}

Input_String_Stream* new_input_string_stream(char* the_string) {
  { Input_String_Stream* self = NULL;

    self = new Input_String_Stream;
    self->state = NULL;
    self->native_stream = NULL;
    self->the_string = the_string;
    return (self);
  }
}

Object* access_input_string_stream_slot_value(Input_String_Stream* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_HIERARCHY_THE_STRING) {
    if (setvalueP) {
      self->the_string = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->the_string));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Input_String_Stream::primary_type() {
  { Input_String_Stream* self = this;

    return (SGT_HIERARCHY_INPUT_STRING_STREAM);
  }
}

void startup_hierarchy() {
  if (current_startup_time_phaseP(0)) {
    oRECYCLED_LIST_So = make_non_recycled_list();
    oRECYCLED_SET_So = make_non_recycled_list();
    oRECYCLED_INTEGER_WRAPPER_So = make_non_recycled_list();
    oRECYCLED_FLOAT_WRAPPER_So = make_non_recycled_list();
    oRECYCLED_STRING_WRAPPER_So = make_non_recycled_list();
    oRECYCLED_CHARACTER_WRAPPER_So = make_non_recycled_list();
    oRECYCLED_FUNCTION_CODE_WRAPPER_So = make_non_recycled_list();
    oRECYCLED_METHOD_CODE_WRAPPER_So = make_non_recycled_list();
    oRECYCLED_TRANSIENT_STRING_WRAPPER_So = make_non_recycled_list();
  }
  { Module* old_OmoduleO_001 = oMODULEo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = oSTELLA_MODULEo;
          oCONTEXTo = oMODULEo;
          if (current_startup_time_phaseP(2)) {
            SYM_HIERARCHY_TYPE_SPEC = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPE-SPEC", NULL, 0)));
            SYM_HIERARCHY_REFERENCE_COUNT = ((Symbol*)(intern_rigid_symbol_wrt_module("REFERENCE-COUNT", NULL, 0)));
            SYM_HIERARCHY_BADp = ((Symbol*)(intern_rigid_symbol_wrt_module("BAD?", NULL, 0)));
            SYM_HIERARCHY_HOME_CONTEXT = ((Symbol*)(intern_rigid_symbol_wrt_module("HOME-CONTEXT", NULL, 0)));
            SYM_HIERARCHY_FIRST_ITERATIONp = ((Symbol*)(intern_rigid_symbol_wrt_module("FIRST-ITERATION?", NULL, 0)));
            SYM_HIERARCHY_OBJECT_ITERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("OBJECT-ITERATOR", NULL, 0)));
            SYM_HIERARCHY_CONS_ITERATOR_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CONS-ITERATOR-CURSOR", NULL, 0)));
            SGT_HIERARCHY_CONS_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONS-ITERATOR", NULL, 1)));
            SYM_HIERARCHY_LIST_ITERATOR_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("LIST-ITERATOR-CURSOR", NULL, 0)));
            SYM_HIERARCHY_LIST_ITERATOR_COLLECTION = ((Symbol*)(intern_rigid_symbol_wrt_module("LIST-ITERATOR-COLLECTION", NULL, 0)));
            SGT_HIERARCHY_LIST_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("LIST-ITERATOR", NULL, 1)));
            SYM_HIERARCHY_THE_CONS_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-CONS-LIST", NULL, 0)));
            SGT_HIERARCHY_DESTRUCTIVE_LIST_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("DESTRUCTIVE-LIST-ITERATOR", NULL, 1)));
            SYM_HIERARCHY_SET_ITERATOR_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("SET-ITERATOR-CURSOR", NULL, 0)));
            SYM_HIERARCHY_SET_ITERATOR_COLLECTION = ((Symbol*)(intern_rigid_symbol_wrt_module("SET-ITERATOR-COLLECTION", NULL, 0)));
            SGT_HIERARCHY_SET_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("SET-ITERATOR", NULL, 1)));
            SYM_HIERARCHY_KEY = ((Symbol*)(intern_rigid_symbol_wrt_module("KEY", NULL, 0)));
            SYM_HIERARCHY_ITERATOR_NEXT_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-NEXT-CODE", NULL, 0)));
            SYM_HIERARCHY_ITERATOR_FILTER_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-FILTER-CODE", NULL, 0)));
            SYM_HIERARCHY_ITERATOR_EMPTY_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-EMPTY-CODE", NULL, 0)));
            SYM_HIERARCHY_ITERATOR_NESTED_ITERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-NESTED-ITERATOR", NULL, 0)));
            SYM_HIERARCHY_ITERATOR_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-OBJECT", NULL, 0)));
            SYM_HIERARCHY_ITERATOR_SECOND_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-SECOND-OBJECT", NULL, 0)));
            SYM_HIERARCHY_ITERATOR_INTEGER = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-INTEGER", NULL, 0)));
            SYM_HIERARCHY_ITERATOR_SECOND_INTEGER = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-SECOND-INTEGER", NULL, 0)));
            SYM_HIERARCHY_ITERATOR_CONS_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-CONS-LIST", NULL, 0)));
            SGT_HIERARCHY_ALL_PURPOSE_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("ALL-PURPOSE-ITERATOR", NULL, 1)));
            SYM_HIERARCHY_ITERATOR_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-CURSOR", NULL, 0)));
            SGT_HIERARCHY_TYPES_TO_CLASSES_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("TYPES-TO-CLASSES-ITERATOR", NULL, 1)));
            SYM_HIERARCHY_OBJECT_DICTIONARY_ITERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("OBJECT-DICTIONARY-ITERATOR", NULL, 0)));
            SYM_HIERARCHY_PLIST_ITERATOR_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("PLIST-ITERATOR-CURSOR", NULL, 0)));
            SYM_HIERARCHY_PLIST_ITERATOR_COLLECTION = ((Symbol*)(intern_rigid_symbol_wrt_module("PLIST-ITERATOR-COLLECTION", NULL, 0)));
            SGT_HIERARCHY_PROPERTY_LIST_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPERTY-LIST-ITERATOR", NULL, 1)));
            SYM_HIERARCHY_THE_KV_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-KV-LIST", NULL, 0)));
            SYM_HIERARCHY_KV_LIST_ITERATOR_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("KV-LIST-ITERATOR-CURSOR", NULL, 0)));
            SGT_HIERARCHY_KV_LIST_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("KV-LIST-ITERATOR", NULL, 1)));
            SYM_HIERARCHY_INTERVAL_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("INTERVAL-CURSOR", NULL, 0)));
            SYM_HIERARCHY_LOWER_BOUND = ((Symbol*)(intern_rigid_symbol_wrt_module("LOWER-BOUND", NULL, 0)));
            SYM_HIERARCHY_UPPER_BOUND = ((Symbol*)(intern_rigid_symbol_wrt_module("UPPER-BOUND", NULL, 0)));
            SGT_HIERARCHY_INTEGER_INTERVAL_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("INTEGER-INTERVAL-ITERATOR", NULL, 1)));
            SGT_HIERARCHY_REVERSE_INTEGER_INTERVAL_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("REVERSE-INTEGER-INTERVAL-ITERATOR", NULL, 1)));
            SYM_HIERARCHY_THE_STRING = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-STRING", NULL, 0)));
            SYM_HIERARCHY_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CURSOR", NULL, 0)));
            SYM_HIERARCHY_END = ((Symbol*)(intern_rigid_symbol_wrt_module("END", NULL, 0)));
            SGT_HIERARCHY_STRING_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("STRING-ITERATOR", NULL, 1)));
            SYM_HIERARCHY_OBJECT_COLLECTION = ((Symbol*)(intern_rigid_symbol_wrt_module("OBJECT-COLLECTION", NULL, 0)));
            SYM_HIERARCHY_OBJECT_SEQUENCE = ((Symbol*)(intern_rigid_symbol_wrt_module("OBJECT-SEQUENCE", NULL, 0)));
            SGT_HIERARCHY_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("LIST", NULL, 1)));
            SGT_HIERARCHY_SET = ((Surrogate*)(intern_rigid_symbol_wrt_module("SET", NULL, 1)));
            SGT_HIERARCHY_CLASS_EXTENSION = ((Surrogate*)(intern_rigid_symbol_wrt_module("CLASS-EXTENSION", NULL, 1)));
            SYM_HIERARCHY_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE", NULL, 0)));
            SYM_HIERARCHY_REST = ((Symbol*)(intern_rigid_symbol_wrt_module("REST", NULL, 0)));
            SGT_HIERARCHY_CONS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONS", NULL, 1)));
            SYM_HIERARCHY_NEXT_SWEEP_LIST_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("NEXT-SWEEP-LIST-OBJECT", NULL, 0)));
            SGT_HIERARCHY_TRANSIENT_CONS = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-CONS", NULL, 1)));
            SYM_HIERARCHY_OBJECT_TO_OBJECT_DICTIONARY = ((Symbol*)(intern_rigid_symbol_wrt_module("OBJECT-TO-OBJECT-DICTIONARY", NULL, 0)));
            SYM_HIERARCHY_THE_PLIST = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-PLIST", NULL, 0)));
            SGT_HIERARCHY_PROPERTY_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPERTY-LIST", NULL, 1)));
            SGT_HIERARCHY_KV_CONS = ((Surrogate*)(intern_rigid_symbol_wrt_module("KV-CONS", NULL, 1)));
            SGT_HIERARCHY_KEY_VALUE_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("KEY-VALUE-LIST", NULL, 1)));
            SGT_HIERARCHY_HASH_TABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("HASH-TABLE", NULL, 1)));
            SYM_HIERARCHY_OBJECT_TO_OBJECT_HASH_TABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("OBJECT-TO-OBJECT-HASH-TABLE", NULL, 0)));
            SGT_HIERARCHY_INTEGER_HASH_TABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("INTEGER-HASH-TABLE", NULL, 1)));
            SGT_HIERARCHY_FLOAT_HASH_TABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("FLOAT-HASH-TABLE", NULL, 1)));
            SGT_HIERARCHY_STRING_HASH_TABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("STRING-HASH-TABLE", NULL, 1)));
            SGT_HIERARCHY_STRING_TO_INTEGER_HASH_TABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("STRING-TO-INTEGER-HASH-TABLE", NULL, 1)));
            SYM_HIERARCHY_ARRAY_SIZE = ((Symbol*)(intern_rigid_symbol_wrt_module("ARRAY-SIZE", NULL, 0)));
            SGT_HIERARCHY_VECTOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("VECTOR", NULL, 1)));
            SGT_HIERARCHY_EXTENSIBLE_VECTOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("EXTENSIBLE-VECTOR", NULL, 1)));
            SYM_HIERARCHY_TOP_SYMBOL_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("TOP-SYMBOL-OFFSET", NULL, 0)));
            SYM_HIERARCHY_POTENTIAL_FREE_SYMBOL_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("POTENTIAL-FREE-SYMBOL-OFFSET", NULL, 0)));
            SGT_HIERARCHY_EXTENSIBLE_SYMBOL_ARRAY = ((Surrogate*)(intern_rigid_symbol_wrt_module("EXTENSIBLE-SYMBOL-ARRAY", NULL, 1)));
            SYM_HIERARCHY_RESIZE_INCREMENT = ((Symbol*)(intern_rigid_symbol_wrt_module("RESIZE-INCREMENT", NULL, 0)));
            SYM_HIERARCHY_SEQUENCE_LENGTH = ((Symbol*)(intern_rigid_symbol_wrt_module("SEQUENCE-LENGTH", NULL, 0)));
            SYM_HIERARCHY_VSEQ = ((Symbol*)(intern_rigid_symbol_wrt_module("VSEQ", NULL, 0)));
            SGT_HIERARCHY_SHORT_VECTOR_SEQUENCE = ((Surrogate*)(intern_rigid_symbol_wrt_module("SHORT-VECTOR-SEQUENCE", NULL, 1)));
            SYM_HIERARCHY_SVSEQ = ((Symbol*)(intern_rigid_symbol_wrt_module("SVSEQ", NULL, 0)));
            SGT_HIERARCHY_BOOLEAN_VECTOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN-VECTOR", NULL, 1)));
            SGT_HIERARCHY_INTEGER_VECTOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("INTEGER-VECTOR", NULL, 1)));
            SGT_HIERARCHY_ARRAY = ((Surrogate*)(intern_rigid_symbol_wrt_module("ARRAY", NULL, 1)));
            SGT_HIERARCHY_NULL_TERMINATED_ARRAY = ((Surrogate*)(intern_rigid_symbol_wrt_module("NULL-TERMINATED-ARRAY", NULL, 1)));
            SGT_HIERARCHY_ACTIVE_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("ACTIVE-LIST", NULL, 1)));
            SGT_HIERARCHY_ACTIVE_SET = ((Surrogate*)(intern_rigid_symbol_wrt_module("ACTIVE-SET", NULL, 1)));
            SYM_HIERARCHY_DEMON_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("DEMON-NAME", NULL, 0)));
            SYM_HIERARCHY_DEMON_ACTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEMON-ACTION", NULL, 0)));
            SYM_HIERARCHY_DEMON_CLASS_REFS = ((Symbol*)(intern_rigid_symbol_wrt_module("DEMON-CLASS-REFS", NULL, 0)));
            SYM_HIERARCHY_DEMON_SLOT_REFS = ((Symbol*)(intern_rigid_symbol_wrt_module("DEMON-SLOT-REFS", NULL, 0)));
            SYM_HIERARCHY_DEMON_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEMON-CODE", NULL, 0)));
            SYM_HIERARCHY_DEMON_METHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("DEMON-METHOD", NULL, 0)));
            SYM_HIERARCHY_DEMON_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEMON-DOCUMENTATION", NULL, 0)));
            SYM_HIERARCHY_DEMON_GUARDp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEMON-GUARD?", NULL, 0)));
            SYM_HIERARCHY_DEMON_ALLp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEMON-ALL?", NULL, 0)));
            SYM_HIERARCHY_DEMON_INHERITp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEMON-INHERIT?", NULL, 0)));
            SGT_HIERARCHY_DEMON = ((Surrogate*)(intern_rigid_symbol_wrt_module("DEMON", NULL, 1)));
            SGT_HIERARCHY_LIST_OF_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("LIST-OF-SLOT", NULL, 1)));
            SGT_HIERARCHY_LIST_OF_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("LIST-OF-SYMBOL", NULL, 1)));
            SGT_HIERARCHY_LIST_OF_KEYWORD = ((Surrogate*)(intern_rigid_symbol_wrt_module("LIST-OF-KEYWORD", NULL, 1)));
            SGT_HIERARCHY_LIST_OF_TYPE = ((Surrogate*)(intern_rigid_symbol_wrt_module("LIST-OF-TYPE", NULL, 1)));
            SGT_HIERARCHY_KEYWORD_KEY_VALUE_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("KEYWORD-KEY-VALUE-LIST", NULL, 1)));
            SYM_HIERARCHY_SYMBOL_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SYMBOL-NAME", NULL, 0)));
            SYM_HIERARCHY_SYMBOL_ID = ((Symbol*)(intern_rigid_symbol_wrt_module("SYMBOL-ID", NULL, 0)));
            SYM_HIERARCHY_INTERNED_IN = ((Symbol*)(intern_rigid_symbol_wrt_module("INTERNED-IN", NULL, 0)));
            SYM_HIERARCHY_SYMBOL_SLOT_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("SYMBOL-SLOT-OFFSET", NULL, 0)));
            SYM_HIERARCHY_SYMBOL_VALUE_AND_PLIST = ((Symbol*)(intern_rigid_symbol_wrt_module("SYMBOL-VALUE-AND-PLIST", NULL, 0)));
            SGT_HIERARCHY_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("SYMBOL", NULL, 1)));
            SYM_HIERARCHY_SURROGATE_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE-VALUE", NULL, 0)));
            SYM_HIERARCHY_SURROGATE_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE-NAME", NULL, 0)));
            SYM_HIERARCHY_TYPE_CLASS = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPE-CLASS", NULL, 0)));
            SYM_HIERARCHY_TYPE_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPE-NAME", NULL, 0)));
            SYM_HIERARCHY_SLOTREF_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOTREF-SLOT", NULL, 0)));
            SGT_HIERARCHY_SURROGATE = ((Surrogate*)(intern_rigid_symbol_wrt_module("SURROGATE", NULL, 1)));
            SYM_HIERARCHY_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPE", NULL, 0)));
            SYM_HIERARCHY_SLOTREF = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOTREF", NULL, 0)));
            SYM_HIERARCHY_KEYWORD_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("KEYWORD-NAME", NULL, 0)));
            SGT_HIERARCHY_KEYWORD = ((Surrogate*)(intern_rigid_symbol_wrt_module("KEYWORD", NULL, 1)));
            SYM_HIERARCHY_INDEXICAL_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("INDEXICAL-VALUE", NULL, 0)));
            SGT_HIERARCHY_INDEXICAL = ((Surrogate*)(intern_rigid_symbol_wrt_module("INDEXICAL", NULL, 1)));
            SGT_HIERARCHY_TRANSIENT_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-SYMBOL", NULL, 1)));
            SGT_HIERARCHY_TRANSIENT_KEYWORD = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-KEYWORD", NULL, 1)));
            SYM_HIERARCHY_PROJECTS_ONTO = ((Symbol*)(intern_rigid_symbol_wrt_module("PROJECTS-ONTO", NULL, 0)));
            SYM_HIERARCHY_PROJECTED_FROM = ((Symbol*)(intern_rigid_symbol_wrt_module("PROJECTED-FROM", NULL, 0)));
            SYM_HIERARCHY_PROPERTIES = ((Symbol*)(intern_rigid_symbol_wrt_module("PROPERTIES", NULL, 0)));
            SYM_HIERARCHY_STORED_ACTIVEp = ((Symbol*)(intern_rigid_symbol_wrt_module("STORED-ACTIVE?", NULL, 0)));
            SYM_HIERARCHY_ABSTRACTp = ((Symbol*)(intern_rigid_symbol_wrt_module("ABSTRACT?", NULL, 0)));
            SYM_HIERARCHY_CLASS_CL_STRUCT_SLOTS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CL-STRUCT-SLOTS", NULL, 0)));
            SYM_HIERARCHY_CLASS_RECYCLE_METHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-RECYCLE-METHOD", NULL, 0)));
            KWD_HIERARCHY_NONE = ((Keyword*)(intern_rigid_symbol_wrt_module("NONE", NULL, 2)));
            SYM_HIERARCHY_CLASS_PARAMETERS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-PARAMETERS", NULL, 0)));
            SYM_HIERARCHY_CLASS_REQUIRED_SLOT_NAMES = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-REQUIRED-SLOT-NAMES", NULL, 0)));
            SYM_HIERARCHY_CLASS_GUARD_CONSTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-GUARD-CONSTRUCTOR-DEMONS", NULL, 0)));
            SYM_HIERARCHY_CLASS_CONSTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CONSTRUCTOR-DEMONS", NULL, 0)));
            SYM_HIERARCHY_CLASS_GUARD_DESTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-GUARD-DESTRUCTOR-DEMONS", NULL, 0)));
            SYM_HIERARCHY_CLASS_DESTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-DESTRUCTOR-DEMONS", NULL, 0)));
            SYM_HIERARCHY_CLASS_KEY = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-KEY", NULL, 0)));
            SYM_HIERARCHY_CLASS_SYNONYMS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-SYNONYMS", NULL, 0)));
            SYM_HIERARCHY_CL_STRUCTp = ((Symbol*)(intern_rigid_symbol_wrt_module("CL-STRUCT?", NULL, 0)));
            SYM_HIERARCHY_MIXINp = ((Symbol*)(intern_rigid_symbol_wrt_module("MIXIN?", NULL, 0)));
            SYM_HIERARCHY_CLASS_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-TYPE", NULL, 0)));
            SYM_HIERARCHY_CLASS_ARITY = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-ARITY", NULL, 0)));
            SYM_HIERARCHY_CLASS_DIRECT_SUPERS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-DIRECT-SUPERS", NULL, 0)));
            SYM_HIERARCHY_CLASS_DIRECT_SUBS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-DIRECT-SUBS", NULL, 0)));
            SYM_HIERARCHY_CLASS_ALL_SUPER_CLASSES = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-ALL-SUPER-CLASSES", NULL, 0)));
            SYM_HIERARCHY_CLASS_ALL_SLOTS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-ALL-SLOTS", NULL, 0)));
            SYM_HIERARCHY_CLASS_LOCAL_SLOTS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-LOCAL-SLOTS", NULL, 0)));
            SYM_HIERARCHY_CLASS_SLOT_AND_METHOD_CACHE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-SLOT-AND-METHOD-CACHE", NULL, 0)));
            SYM_HIERARCHY_CLASS_ABSTRACTp = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-ABSTRACT?", NULL, 0)));
            SYM_HIERARCHY_CLASS_MIXINp = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-MIXIN?", NULL, 0)));
            SYM_HIERARCHY_CLASS_COLLECTIONp = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-COLLECTION?", NULL, 0)));
            SYM_HIERARCHY_CLASS_CL_STRUCTp = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CL-STRUCT?", NULL, 0)));
            SYM_HIERARCHY_CLASS_PUBLICp = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-PUBLIC?", NULL, 0)));
            SYM_HIERARCHY_CLASS_FINALIZEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-FINALIZED?", NULL, 0)));
            SYM_HIERARCHY_CLASS_SLOTS_FINALIZEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-SLOTS-FINALIZED?", NULL, 0)));
            SYM_HIERARCHY_CLASS_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-STRINGIFIED-SOURCE", NULL, 0)));
            SYM_HIERARCHY_CLASS_CONSTRUCTOR_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CONSTRUCTOR-CODE", NULL, 0)));
            SYM_HIERARCHY_CLASS_SLOT_ACCESSOR_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-SLOT-ACCESSOR-CODE", NULL, 0)));
            SYM_HIERARCHY_CLASS_MARKEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-MARKED?", NULL, 0)));
            SYM_HIERARCHY_CLASS_TAXONOMY_NODE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-TAXONOMY-NODE", NULL, 0)));
            SYM_HIERARCHY_CLASS_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-DOCUMENTATION", NULL, 0)));
            SYM_HIERARCHY_CLASS_PRINT_FORM = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-PRINT-FORM", NULL, 0)));
            SYM_HIERARCHY_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 0)));
            SYM_HIERARCHY_PRINT_FORM = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-FORM", NULL, 0)));
            SGT_HIERARCHY_CLASS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CLASS", NULL, 1)));
            SGT_HIERARCHY_ACTIVE_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("ACTIVE-OBJECT", NULL, 1)));
            SYM_HIERARCHY_CLASS_CREATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CREATOR", NULL, 0)));
            SYM_HIERARCHY_CLASS_INITIALIZER = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-INITIALIZER", NULL, 0)));
            SYM_HIERARCHY_CLASS_TERMINATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-TERMINATOR", NULL, 0)));
            SYM_HIERARCHY_CLASS_DESTRUCTOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-DESTRUCTOR", NULL, 0)));
            SYM_HIERARCHY_CLASS_INITIAL_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-INITIAL-VALUE", NULL, 0)));
            SYM_HIERARCHY_CLASS_EXTENSION = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-EXTENSION", NULL, 0)));
            SYM_HIERARCHY_CLASS_CL_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CL-NATIVE-TYPE", NULL, 0)));
            SYM_HIERARCHY_CLASS_CPP_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CPP-NATIVE-TYPE", NULL, 0)));
            SYM_HIERARCHY_CLASS_JAVA_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-JAVA-NATIVE-TYPE", NULL, 0)));
            SYM_HIERARCHY_SLOT_DIRECT_EQUIVALENT = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-DIRECT-EQUIVALENT", NULL, 0)));
            SYM_HIERARCHY_SLOT_AUXILIARYp = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-AUXILIARY?", NULL, 0)));
            SYM_HIERARCHY_SLOT_DIRECT_SUPERS = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-DIRECT-SUPERS", NULL, 0)));
            SYM_HIERARCHY_SLOT_DIRECT_SUBS = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-DIRECT-SUBS", NULL, 0)));
            SYM_HIERARCHY_SLOT_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-NAME", NULL, 0)));
            SYM_HIERARCHY_SLOT_OWNER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-OWNER", NULL, 0)));
            SYM_HIERARCHY_SLOT_BASE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-BASE-TYPE", NULL, 0)));
            SYM_HIERARCHY_SLOT_SLOTREF = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-SLOTREF", NULL, 0)));
            SYM_HIERARCHY_SLOT_PUBLICp = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-PUBLIC?", NULL, 0)));
            SYM_HIERARCHY_SLOT_RENAMEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-RENAMED?", NULL, 0)));
            SYM_HIERARCHY_SLOT_EXTERNALp = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-EXTERNAL?", NULL, 0)));
            SYM_HIERARCHY_SLOT_MARKEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-MARKED?", NULL, 0)));
            SYM_HIERARCHY_SLOT_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-DOCUMENTATION", NULL, 0)));
            SYM_HIERARCHY_SLOT_TYPE_SPECIFIER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-TYPE-SPECIFIER", NULL, 0)));
            SYM_HIERARCHY_SLOT_RENAMES = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-RENAMES", NULL, 0)));
            SGT_HIERARCHY_COLLECTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION", NULL, 1)));
            SYM_HIERARCHY_SLOT_CLOSURE_ASSUMPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-CLOSURE-ASSUMPTION", NULL, 0)));
            SYM_HIERARCHY_SLOT_ALLOCATION = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-ALLOCATION", NULL, 0)));
            KWD_HIERARCHY_INSTANCE = ((Keyword*)(intern_rigid_symbol_wrt_module("INSTANCE", NULL, 2)));
            SYM_HIERARCHY_SLOT_GUARD_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-GUARD-DEMONS", NULL, 0)));
            SYM_HIERARCHY_SLOT_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-DEMONS", NULL, 0)));
            SYM_HIERARCHY_SLOT_ACCESSOR_METHODS = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-ACCESSOR-METHODS", NULL, 0)));
            SYM_HIERARCHY_SLOT_REQUIREDp = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-REQUIRED?", NULL, 0)));
            SYM_HIERARCHY_SLOT_COMPONENTp = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-COMPONENT?", NULL, 0)));
            SYM_HIERARCHY_SLOT_READ_ONLYp = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-READ-ONLY?", NULL, 0)));
            SYM_HIERARCHY_SLOT_HARDWIREDp = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-HARDWIRED?", NULL, 0)));
            SYM_HIERARCHY_SLOT_CONTEXT_SENSITIVEp = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-CONTEXT-SENSITIVE?", NULL, 0)));
            SGT_HIERARCHY_STORAGE_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT", NULL, 1)));
            SYM_HIERARCHY_SLOT_DEFAULT_EXPRESSION = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-DEFAULT-EXPRESSION", NULL, 0)));
            SYM_HIERARCHY_SLOT_READER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-READER", NULL, 0)));
            SYM_HIERARCHY_SLOT_WRITER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-WRITER", NULL, 0)));
            SYM_HIERARCHY_METHOD_PARAMETER_DIRECTIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-PARAMETER-DIRECTIONS", NULL, 0)));
            SYM_HIERARCHY_METHOD_VARIABLE_ARGUMENTSp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-VARIABLE-ARGUMENTS?", NULL, 0)));
            SYM_HIERARCHY_METHOD_BODY_ARGUMENTp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-BODY-ARGUMENT?", NULL, 0)));
            SYM_HIERARCHY_METHOD_NATIVEp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-NATIVE?", NULL, 0)));
            SYM_HIERARCHY_METHOD_GLOBALLY_INLINEp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-GLOBALLY-INLINE?", NULL, 0)));
            SYM_HIERARCHY_METHOD_INLINED_FUNCTIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-INLINED-FUNCTIONS", NULL, 0)));
            SYM_HIERARCHY_METHOD_COMMANDp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-COMMAND?", NULL, 0)));
            SYM_HIERARCHY_METHOD_EVALUATE_ARGUMENTSp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-EVALUATE-ARGUMENTS?", NULL, 0)));
            SYM_HIERARCHY_METHOD_LISP_MACROp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-LISP-MACRO?", NULL, 0)));
            SYM_HIERARCHY_METHOD_SETTERp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-SETTER?", NULL, 0)));
            SYM_HIERARCHY_METHOD_PARAMETER_NAMES = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-PARAMETER-NAMES", NULL, 0)));
            SYM_HIERARCHY_METHOD_PARAMETER_TYPE_SPECIFIERS = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-PARAMETER-TYPE-SPECIFIERS", NULL, 0)));
            SYM_HIERARCHY_METHOD_RETURN_TYPE_SPECIFIERS = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-RETURN-TYPE-SPECIFIERS", NULL, 0)));
            SYM_HIERARCHY_METHOD_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-STRINGIFIED-SOURCE", NULL, 0)));
            SYM_HIERARCHY_METHOD_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-CODE", NULL, 0)));
            SYM_HIERARCHY_FUNCTION_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("FUNCTION-CODE", NULL, 0)));
            SYM_HIERARCHY_METHOD_FUNCTIONp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-FUNCTION?", NULL, 0)));
            SYM_HIERARCHY_METHOD_AUXILIARYp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-AUXILIARY?", NULL, 0)));
            SYM_HIERARCHY_METHOD_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-DOCUMENTATION", NULL, 0)));
            SYM_HIERARCHY_METHOD_STORAGE_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-STORAGE-SLOT", NULL, 0)));
            SYM_HIERARCHY_STORAGE_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT", NULL, 0)));
            SGT_HIERARCHY_METHOD_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("METHOD-SLOT", NULL, 1)));
            SYM_HIERARCHY_FUNCTION = ((Symbol*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 0)));
            SYM_HIERARCHY_SPECIFIER_BASE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("SPECIFIER-BASE-TYPE", NULL, 0)));
            SYM_HIERARCHY_SPECIFIER_PARAMETER_TYPES = ((Symbol*)(intern_rigid_symbol_wrt_module("SPECIFIER-PARAMETER-TYPES", NULL, 0)));
            SYM_HIERARCHY_SPECIFIER_SEQUENCE_SIZE = ((Symbol*)(intern_rigid_symbol_wrt_module("SPECIFIER-SEQUENCE-SIZE", NULL, 0)));
            SGT_HIERARCHY_PARAMETRIC_TYPE_SPECIFIER = ((Surrogate*)(intern_rigid_symbol_wrt_module("PARAMETRIC-TYPE-SPECIFIER", NULL, 1)));
            SGT_HIERARCHY_TRANSIENT_TYPE_SPECIFIER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-TYPE-SPECIFIER", NULL, 1)));
            SYM_HIERARCHY_SPECIFIER_PARAMETER_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SPECIFIER-PARAMETER-NAME", NULL, 0)));
            SGT_HIERARCHY_ANCHORED_TYPE_SPECIFIER = ((Surrogate*)(intern_rigid_symbol_wrt_module("ANCHORED-TYPE-SPECIFIER", NULL, 1)));
            SYM_HIERARCHY_VARIABLE_ARITYp = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-ARITY?", NULL, 0)));
            SYM_HIERARCHY_TUPLE_DOMAINS = ((Symbol*)(intern_rigid_symbol_wrt_module("TUPLE-DOMAINS", NULL, 0)));
            SGT_HIERARCHY_TABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TABLE", NULL, 1)));
            SYM_HIERARCHY_VARIABLE_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-NAME", NULL, 0)));
            SYM_HIERARCHY_VARIABLE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-TYPE", NULL, 0)));
            SYM_HIERARCHY_VARIABLE_SPECIALp = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-SPECIAL?", NULL, 0)));
            SYM_HIERARCHY_VARIABLE_CONSTANTp = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-CONSTANT?", NULL, 0)));
            SYM_HIERARCHY_VARIABLE_PUBLICp = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-PUBLIC?", NULL, 0)));
            SYM_HIERARCHY_VARIABLE_AUXILIARYp = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-AUXILIARY?", NULL, 0)));
            SYM_HIERARCHY_VARIABLE_GET_VALUE_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-GET-VALUE-CODE", NULL, 0)));
            SYM_HIERARCHY_VARIABLE_SET_VALUE_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-SET-VALUE-CODE", NULL, 0)));
            SYM_HIERARCHY_VARIABLE_VALUE_STACK = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-VALUE-STACK", NULL, 0)));
            SYM_HIERARCHY_VARIABLE_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-DOCUMENTATION", NULL, 0)));
            SYM_HIERARCHY_VARIABLE_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-STRINGIFIED-SOURCE", NULL, 0)));
            SGT_HIERARCHY_GLOBAL_VARIABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("GLOBAL-VARIABLE", NULL, 1)));
            SYM_HIERARCHY_QUOTATION_TABLE_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("QUOTATION-TABLE-OFFSET", NULL, 0)));
            SGT_HIERARCHY_QUOTED_EXPRESSION = ((Surrogate*)(intern_rigid_symbol_wrt_module("QUOTED-EXPRESSION", NULL, 1)));
            SYM_HIERARCHY_CHILD_CONTEXTS = ((Symbol*)(intern_rigid_symbol_wrt_module("CHILD-CONTEXTS", NULL, 0)));
            SYM_HIERARCHY_ALL_SUPER_CONTEXTS = ((Symbol*)(intern_rigid_symbol_wrt_module("ALL-SUPER-CONTEXTS", NULL, 0)));
            SYM_HIERARCHY_BASE_MODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("BASE-MODULE", NULL, 0)));
            SYM_HIERARCHY_CONTEXT_NUMBER = ((Symbol*)(intern_rigid_symbol_wrt_module("CONTEXT-NUMBER", NULL, 0)));
            SGT_HIERARCHY_MODULE = ((Surrogate*)(intern_rigid_symbol_wrt_module("MODULE", NULL, 1)));
            SGT_HIERARCHY_WORLD = ((Surrogate*)(intern_rigid_symbol_wrt_module("WORLD", NULL, 1)));
            SYM_HIERARCHY_WORLD_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("WORLD-NAME", NULL, 0)));
            SYM_HIERARCHY_SHADOWED_SURROGATES = ((Symbol*)(intern_rigid_symbol_wrt_module("SHADOWED-SURROGATES", NULL, 0)));
            SYM_HIERARCHY_LOGIC_DIALECT = ((Symbol*)(intern_rigid_symbol_wrt_module("LOGIC-DIALECT", NULL, 0)));
            KWD_HIERARCHY_KIF = ((Keyword*)(intern_rigid_symbol_wrt_module("KIF", NULL, 2)));
            SYM_HIERARCHY_CLEARABLEp = ((Symbol*)(intern_rigid_symbol_wrt_module("CLEARABLE?", NULL, 0)));
            SYM_HIERARCHY_PARENT_MODULES = ((Symbol*)(intern_rigid_symbol_wrt_module("PARENT-MODULES", NULL, 0)));
            SYM_HIERARCHY_REQUIRES = ((Symbol*)(intern_rigid_symbol_wrt_module("REQUIRES", NULL, 0)));
            SYM_HIERARCHY_USES = ((Symbol*)(intern_rigid_symbol_wrt_module("USES", NULL, 0)));
            SYM_HIERARCHY_USED_BY = ((Symbol*)(intern_rigid_symbol_wrt_module("USED-BY", NULL, 0)));
            SYM_HIERARCHY_MODULE_NATIVE_PACKAGE = ((Symbol*)(intern_rigid_symbol_wrt_module("MODULE-NATIVE-PACKAGE", NULL, 0)));
            SYM_HIERARCHY_DIRECTORY_FILE = ((Symbol*)(intern_rigid_symbol_wrt_module("DIRECTORY-FILE", NULL, 0)));
            SYM_HIERARCHY_CODE_FILES = ((Symbol*)(intern_rigid_symbol_wrt_module("CODE-FILES", NULL, 0)));
            SYM_HIERARCHY_DEFINITIONS_FILE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINITIONS-FILE", NULL, 0)));
            SYM_HIERARCHY_OPEN_WORLD_ASSUMPTIONp = ((Symbol*)(intern_rigid_symbol_wrt_module("OPEN-WORLD-ASSUMPTION?", NULL, 0)));
            SYM_HIERARCHY_CASE_SENSITIVEp = ((Symbol*)(intern_rigid_symbol_wrt_module("CASE-SENSITIVE?", NULL, 0)));
            SYM_HIERARCHY_MODULE_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("MODULE-NAME", NULL, 0)));
            SYM_HIERARCHY_MODULE_FULL_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("MODULE-FULL-NAME", NULL, 0)));
            SYM_HIERARCHY_MODULE_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("MODULE-STRINGIFIED-SOURCE", NULL, 0)));
            SYM_HIERARCHY_STRINGIFIED_OPTIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("STRINGIFIED-OPTIONS", NULL, 0)));
            SYM_HIERARCHY_CARDINAL_MODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("CARDINAL-MODULE", NULL, 0)));
            SYM_HIERARCHY_SYMBOL_OFFSET_TABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("SYMBOL-OFFSET-TABLE", NULL, 0)));
            SYM_HIERARCHY_SURROGATE_OFFSET_TABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE-OFFSET-TABLE", NULL, 0)));
            SYM_HIERARCHY_INDEXICAL_OFFSET_TABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("INDEXICAL-OFFSET-TABLE", NULL, 0)));
            SYM_HIERARCHY_ELABORATED_WORLD = ((Symbol*)(intern_rigid_symbol_wrt_module("ELABORATED-WORLD", NULL, 0)));
            SYM_HIERARCHY_PARENT_CONTEXT = ((Symbol*)(intern_rigid_symbol_wrt_module("PARENT-CONTEXT", NULL, 0)));
            SGT_HIERARCHY_CS_VALUE = ((Surrogate*)(intern_rigid_symbol_wrt_module("CS-VALUE", NULL, 1)));
            SGT_HIERARCHY_INTERVAL = ((Surrogate*)(intern_rigid_symbol_wrt_module("INTERVAL", NULL, 1)));
            SYM_HIERARCHY_PARENTS = ((Symbol*)(intern_rigid_symbol_wrt_module("PARENTS", NULL, 0)));
            SYM_HIERARCHY_TREE_CHILDREN = ((Symbol*)(intern_rigid_symbol_wrt_module("TREE-CHILDREN", NULL, 0)));
            SYM_HIERARCHY_CHILDREN = ((Symbol*)(intern_rigid_symbol_wrt_module("CHILDREN", NULL, 0)));
            SYM_HIERARCHY_FIRST_INTERVAL_LOWER_BOUND = ((Symbol*)(intern_rigid_symbol_wrt_module("FIRST-INTERVAL-LOWER-BOUND", NULL, 0)));
            SYM_HIERARCHY_FIRST_INTERVAL_UPPER_BOUND = ((Symbol*)(intern_rigid_symbol_wrt_module("FIRST-INTERVAL-UPPER-BOUND", NULL, 0)));
            SYM_HIERARCHY_INITIAL_INTERVAL = ((Symbol*)(intern_rigid_symbol_wrt_module("INITIAL-INTERVAL", NULL, 0)));
            SYM_HIERARCHY_INTERVALS = ((Symbol*)(intern_rigid_symbol_wrt_module("INTERVALS", NULL, 0)));
            SYM_HIERARCHY_TOTAL_ANCESTORS = ((Symbol*)(intern_rigid_symbol_wrt_module("TOTAL-ANCESTORS", NULL, 0)));
            SYM_HIERARCHY_LABEL = ((Symbol*)(intern_rigid_symbol_wrt_module("LABEL", NULL, 0)));
            SYM_HIERARCHY_NATIVE_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("NATIVE-OBJECT", NULL, 0)));
            SGT_HIERARCHY_TAXONOMY_NODE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TAXONOMY-NODE", NULL, 1)));
            SYM_HIERARCHY_INCREMENTAL_MODEp = ((Symbol*)(intern_rigid_symbol_wrt_module("INCREMENTAL-MODE?", NULL, 0)));
            SYM_HIERARCHY_RENUMBER_IF_OUT_OF_NUMBERSp = ((Symbol*)(intern_rigid_symbol_wrt_module("RENUMBER-IF-OUT-OF-NUMBERS?", NULL, 0)));
            SYM_HIERARCHY_LARGEST_POSTORDER_NUMBER = ((Symbol*)(intern_rigid_symbol_wrt_module("LARGEST-POSTORDER-NUMBER", NULL, 0)));
            SYM_HIERARCHY_ROOTS = ((Symbol*)(intern_rigid_symbol_wrt_module("ROOTS", NULL, 0)));
            SYM_HIERARCHY_BROKEN_LINKS = ((Symbol*)(intern_rigid_symbol_wrt_module("BROKEN-LINKS", NULL, 0)));
            SGT_HIERARCHY_TAXONOMY_GRAPH = ((Surrogate*)(intern_rigid_symbol_wrt_module("TAXONOMY-GRAPH", NULL, 1)));
            SGT_HIERARCHY_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("EXCEPTION", NULL, 1)));
            SGT_HIERARCHY_STELLA_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("STELLA-EXCEPTION", NULL, 1)));
            SGT_HIERARCHY_READ_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("READ-EXCEPTION", NULL, 1)));
            SGT_HIERARCHY_UNHANDLED_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNHANDLED-EXCEPTION", NULL, 1)));
            SYM_HIERARCHY_FILE_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("FILE-NAME", NULL, 0)));
            SYM_HIERARCHY_WRAPPER_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAPPER-VALUE", NULL, 0)));
            SGT_HIERARCHY_INTEGER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("INTEGER-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_FLOAT_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("FLOAT-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_STRING_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("STRING-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_CHARACTER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("CHARACTER-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_BOOLEAN_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN-WRAPPER", NULL, 1)));
            SYM_HIERARCHY_NULL_BOOLEAN = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-BOOLEAN", NULL, 0)));
            SYM_HIERARCHY_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            SYM_HIERARCHY_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", NULL, 0)));
            SGT_HIERARCHY_FUNCTION_CODE_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("FUNCTION-CODE-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_METHOD_CODE_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("METHOD-CODE-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_TRANSIENT_INTEGER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-INTEGER-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_TRANSIENT_FLOAT_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-FLOAT-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_TRANSIENT_STRING_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-STRING-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_TRANSIENT_CHARACTER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-CHARACTER-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_TRANSIENT_FUNCTION_CODE_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-FUNCTION-CODE-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_TRANSIENT_METHOD_CODE_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-METHOD-CODE-WRAPPER", NULL, 1)));
            SGT_HIERARCHY_VERBATIM_STRING_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("VERBATIM-STRING-WRAPPER", NULL, 1)));
            SYM_HIERARCHY_ARGUMENT_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("ARGUMENT-LIST", NULL, 0)));
            SGT_HIERARCHY_LISP_CONS_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("LISP-CONS-ITERATOR", NULL, 1)));
            SYM_HIERARCHY_STATE = ((Symbol*)(intern_rigid_symbol_wrt_module("STATE", NULL, 0)));
            SGT_HIERARCHY_OUTPUT_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("OUTPUT-STREAM", NULL, 1)));
            SGT_HIERARCHY_INPUT_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("INPUT-STREAM", NULL, 1)));
            KWD_HIERARCHY_SUPERSEDE = ((Keyword*)(intern_rigid_symbol_wrt_module("SUPERSEDE", NULL, 2)));
            SYM_HIERARCHY_FILENAME = ((Symbol*)(intern_rigid_symbol_wrt_module("FILENAME", NULL, 0)));
            SYM_HIERARCHY_IF_EXISTS_ACTION = ((Symbol*)(intern_rigid_symbol_wrt_module("IF-EXISTS-ACTION", NULL, 0)));
            SGT_HIERARCHY_OUTPUT_FILE_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("OUTPUT-FILE-STREAM", NULL, 1)));
            KWD_HIERARCHY_ERROR = ((Keyword*)(intern_rigid_symbol_wrt_module("ERROR", NULL, 2)));
            SYM_HIERARCHY_IF_NOT_EXISTS_ACTION = ((Symbol*)(intern_rigid_symbol_wrt_module("IF-NOT-EXISTS-ACTION", NULL, 0)));
            SGT_HIERARCHY_INPUT_FILE_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("INPUT-FILE-STREAM", NULL, 1)));
            SGT_HIERARCHY_OUTPUT_STRING_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("OUTPUT-STRING-STREAM", NULL, 1)));
            SGT_HIERARCHY_INPUT_STRING_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("INPUT-STRING-STREAM", NULL, 1)));
          }
          if (current_startup_time_phaseP(5)) {
            define_class_from_stringified_source("OBJECT", "(DEFCLASS OBJECT () :DOCUMENTATION \"A reflective object that can participate in dynamically-typed\ncontexts.  Either a STANDARD-OBJECT or a WRAPPER or a GENERIC-OBJECT.\nAlso, either an OBJECT-WITH-INHERITED-TYPE or an OBJECT-WITH-OWN-TYPE.\" :PUBLIC-METHODS ((PRIMARY-TYPE ((SELF OBJECT)) :TYPE TYPE :DOCUMENTATION \"Returns the primary type of 'self'.\nGets defined automatically for every non-abstract subclass of OBJECT.\" (RETURN NULL))) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|i|\" (PRIMARY-TYPE SELF)) :METHODS ((INCREMENT-REFERENCE-COUNT ((SELF OBJECT)) NULL) (DECREMENT-REFERENCE-COUNT ((SELF OBJECT)) NULL)) :ABSTRACT? TRUE)");
            define_class_from_stringified_source("SECOND-CLASS-OBJECT", "(DEFCLASS SECOND-CLASS-OBJECT () :DOCUMENTATION \"A C++ object, or a CLOS object pretending to be second class.\nNot a first-class object, since it can't participate in dynamically-typed\ncontexts.\" :ABSTRACT? TRUE)");
            define_class_from_stringified_source("NON-OBJECT", "(DEFCLASS NON-OBJECT () :DOCUMENTATION \"A data structure that cannot be a dispatch argument to\na (real) method, because its type is not accessible at run-time.\" :ABSTRACT? TRUE)");
            define_class_from_stringified_source("STANDARD-OBJECT", "(DEFCLASS STANDARD-OBJECT (OBJECT) :DOCUMENTATION \"Object that used to find its type stored in a :class slot.\nBy reimplementing 'primary-type' as a method, the justification for this\nclass went away, but we'll keep it for now to keep things working.\" :ABSTRACT? TRUE :SYNONYMS (TYPE-SPEC))");
            { Class* renamed_Class = define_class_from_stringified_source("TRANSIENT-MIXIN", "(DEFCLASS TRANSIENT-MIXIN () :DOCUMENTATION \"Transient objects are periodically swept back into a pool\nof free objects.  A transient object should never be pointed at by a\npermanent object.\" :MIXIN? TRUE :SLOTS ((TRANSIENT? :TYPE BOOLEAN :INITIALLY TRUE :HARDWIRED? TRUE)))");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
            }
            { Class* renamed_Class = define_class_from_stringified_source("REFERENCE-COUNT-OBJECT", "(DEFCLASS REFERENCE-COUNT-OBJECT (OBJECT) :DOCUMENTATION \"A reference count objects contains a slot 'reference-count' \nthat is incremented whenever the object is assigned to a slot, and decremented\nwhenever it is deassigned from a slot.\" :ABSTRACT? TRUE :SLOTS ((REFERENCE-COUNT :TYPE INTEGER :INITIALLY 0)) :METHODS ((INCREMENT-REFERENCE-COUNT ((SELF REFERENCE-COUNT-OBJECT)) (SETF (REFERENCE-COUNT SELF) (+ (REFERENCE-COUNT SELF) 1))) (DECREMENT-REFERENCE-COUNT ((SELF REFERENCE-COUNT-OBJECT)) (SETF (REFERENCE-COUNT SELF) (- (REFERENCE-COUNT SELF) 1)))))");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_reference_count_object_slot_value));
            }
            define_class_from_stringified_source("DYNAMIC-SLOTS-MIXIN", "(DEFCLASS DYNAMIC-SLOTS-MIXIN () :SLOTS ((DYNAMIC-SLOTS :TYPE KEY-VALUE-LIST :ALLOCATION :EMBEDDED) (BITS :TYPE THIRTY-TWO-BIT-VECTOR) (BAD? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :DOCUMENTATION \"Indicates that an object is in need of repair.\") (DELETED-OBJECT? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :READER DELETED? :WRITER DELETED?-SETTER :DOCUMENTATION \"Indicates that an object has been \ndestroyed/deleted.  A deleted object is visible only if something broke\nbefore it was fully excised from the network).\")) :DOCUMENTATION \"For system use only.  Object that can store\nslot values in non-preallocated storage.\" :MIXIN? TRUE)");
            { Class* renamed_Class = define_class_from_stringified_source("CONTEXT-SENSITIVE-OBJECT", "(DEFCLASS CONTEXT-SENSITIVE-OBJECT (STANDARD-OBJECT) :DOCUMENTATION \"Context sensitive objects inherit a slot 'home-context'\nthat enables context-dependent access machinery to determine the\nvisibility of objects from modules.\" :ABSTRACT? TRUE :SLOTS ((HOME-CONTEXT :TYPE CONTEXT :INITIALLY *MODULE*)) :METHODS ((HOME-MODULE ((SELF CONTEXT-SENSITIVE-OBJECT)) :TYPE MODULE :PUBLIC? TRUE (RETURN (HOME-CONTEXT SELF)))))");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_context_sensitive_object_slot_value));
            }
            define_class_from_stringified_source("ACTIVE-OBJECT", "(DEFCLASS ACTIVE-OBJECT (CONTEXT-SENSITIVE-OBJECT DYNAMIC-SLOTS-MIXIN) :DOCUMENTATION \"Active objects call class and slot triggers in response\nto instance creation/destruction and slot updates.  They include internal\nstorage slots needed for class extensions, dynamic storage, and home context.\" :ABSTRACT? TRUE)");
            { Class* renamed_Class = define_class_from_stringified_source("ABSTRACT-ITERATOR", "(DEFCLASS ABSTRACT-ITERATOR (STANDARD-OBJECT) :ABSTRACT? TRUE :DOCUMENTATION \"Instances of ABSTRACT-ITERATOR support iteration over collections.\" :PARAMETERS ((ANY-VALUE :TYPE UNKNOWN)) :PUBLIC-SLOTS ((VALUE :TYPE (LIKE (ANY-VALUE SELF)))) :PUBLIC-METHODS ((NEXT? ((SELF ABSTRACT-ITERATOR)) :TYPE BOOLEAN (RETURN NULL)) (LENGTH ((SELF ABSTRACT-ITERATOR)) :TYPE INTEGER)) :SLOTS ((FIRST-ITERATION? :TYPE BOOLEAN :INITIALLY TRUE)))");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_abstract_iterator_slot_value));
            }
            define_class_from_stringified_source("ITERATOR", "(DEFCLASS ITERATOR (ABSTRACT-ITERATOR) :ABSTRACT? TRUE :DOCUMENTATION \"Instances of ITERATOR support iteration over \ncollections of OBJECTs.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SYNONYMS (OBJECT-ITERATOR))");
            { Class* renamed_Class = define_class_from_stringified_source("CONS-ITERATOR", "(DEFCLASS CONS-ITERATOR (ITERATOR) :DOCUMENTATION \"Iterator class for the class CONS.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((CONS-ITERATOR-CURSOR :TYPE CONS)) :TERMINATOR TERMINATE-CONS-ITERATOR?)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_cons_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_cons_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("LIST-ITERATOR", "(DEFCLASS LIST-ITERATOR (ITERATOR) :DOCUMENTATION \"Iterator class for the collection LIST.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((LIST-ITERATOR-CURSOR :TYPE CONS) (LIST-ITERATOR-COLLECTION :TYPE LIST)) :TERMINATOR TERMINATE-LIST-ITERATOR?)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_list_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_list_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("DESTRUCTIVE-LIST-ITERATOR", "(DEFCLASS DESTRUCTIVE-LIST-ITERATOR (ITERATOR) :DOCUMENTATION \"An iterator that contains a cons list.  Iterates over\nthe stored list, and destroys it when the iterator is free'd.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((THE-CONS-LIST :TYPE CONS :INITIALLY NIL) (LIST-ITERATOR-CURSOR :TYPE CONS)) :TERMINATOR TERMINATE-DESTRUCTIVE-LIST-ITERATOR?)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_destructive_list_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_destructive_list_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("SET-ITERATOR", "(DEFCLASS SET-ITERATOR (ITERATOR) :DOCUMENTATION \"Iterator class for the collection SET.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((SET-ITERATOR-CURSOR :TYPE CONS) (SET-ITERATOR-COLLECTION :TYPE SET)) :TERMINATOR TERMINATE-SET-ITERATOR?)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_set_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_set_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("ALL-PURPOSE-ITERATOR", "(DEFCLASS ALL-PURPOSE-ITERATOR (ITERATOR) :DOCUMENTATION \"The all-purpose iterator works by storing a 'next?'\nfunction within itself during iterator allocation.  The method\n'ALL-PURPOSE-ITERAOR.next?' funcalls the stored 'next?' function.\nAn assortment of storage slots are provided for constructing different\nkinds of iterators.\" :PUBLIC-SLOTS ((KEY :TYPE OBJECT)) :SLOTS ((ITERATOR-NEXT-CODE :TYPE FUNCTION-CODE) (ITERATOR-FILTER-CODE :TYPE FUNCTION-CODE) (ITERATOR-EMPTY-CODE :TYPE FUNCTION-CODE) (ITERATOR-NESTED-ITERATOR :TYPE ITERATOR) (ITERATOR-OBJECT :TYPE OBJECT) (ITERATOR-SECOND-OBJECT :TYPE OBJECT) (ITERATOR-INTEGER :TYPE INTEGER) (ITERATOR-SECOND-INTEGER :TYPE INTEGER) (ITERATOR-CONS-LIST :TYPE CONS)) :TERMINATOR TERMINATE-ALL-PURPOSE-ITERATOR?)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_all_purpose_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_all_purpose_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TYPES-TO-CLASSES-ITERATOR", "(DEFCLASS TYPES-TO-CLASSES-ITERATOR (ITERATOR) :DOCUMENTATION \"Iterator that returns a class for each type\nin a cons list of types.\" :PARAMETERS ((ANY-VALUE :TYPE CLASS)) :SLOTS ((ITERATOR-CURSOR :TYPE (CONS OF TYPE) :REQUIRED? TRUE)) :METHODS ((NEXT? ((SELF TYPES-TO-CLASSES-ITERATOR)) :TYPE BOOLEAN (IF (FIRST-ITERATION? SELF) (SETF (FIRST-ITERATION? SELF) FALSE) (SETF (ITERATOR-CURSOR SELF) (REST (ITERATOR-CURSOR SELF)))) (COND ((NON-EMPTY? (ITERATOR-CURSOR SELF)) (SETF (VALUE SELF) (TYPE-CLASS (FIRST (ITERATOR-CURSOR SELF)))) (RETURN TRUE)) (OTHERWISE (RETURN FALSE))))))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_types_to_classes_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_types_to_classes_iterator_slot_value));
            }
            define_class_from_stringified_source("ABSTRACT-DICTIONARY-ITERATOR", "(DEFCLASS ABSTRACT-DICTIONARY-ITERATOR (ABSTRACT-ITERATOR) :ABSTRACT? TRUE :DOCUMENTATION \"Instances of ABSTRACT-DICTIONARY-ITERATOR support iteration\nover dictionaries.\" :PARAMETERS ((ANY-KEY :TYPE UNKNOWN) (ANY-VALUE :TYPE UNKNOWN)) :PUBLIC-SLOTS ((KEY :TYPE (LIKE (ANY-KEY SELF)))))");
            define_class_from_stringified_source("DICTIONARY-ITERATOR", "(DEFCLASS DICTIONARY-ITERATOR (ABSTRACT-DICTIONARY-ITERATOR) :ABSTRACT? TRUE :DOCUMENTATION \"Instances of DICTIONARY-ITERATOR support iteration\nover dictionaries with keys and values of type OBJECT.\" :PARAMETERS ((ANY-KEY :TYPE OBJECT) (ANY-VALUE :TYPE OBJECT)) :SYNONYMS (OBJECT-DICTIONARY-ITERATOR))");
            { Class* renamed_Class = define_class_from_stringified_source("PROPERTY-LIST-ITERATOR", "(DEFCLASS PROPERTY-LIST-ITERATOR (DICTIONARY-ITERATOR) :DOCUMENTATION \"Iterator class for the collection PROPERTY-LIST.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT) (ANY-KEY :TYPE OBJECT)) :SLOTS ((PLIST-ITERATOR-CURSOR :TYPE CONS) (PLIST-ITERATOR-COLLECTION :TYPE PROPERTY-LIST)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_property_list_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_property_list_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("KV-LIST-ITERATOR", "(DEFCLASS KV-LIST-ITERATOR (DICTIONARY-ITERATOR) :PARAMETERS ((ANY-VALUE :TYPE OBJECT) (ANY-KEY :TYPE OBJECT)) :SLOTS ((THE-KV-LIST :TYPE KEY-VALUE-LIST) (KV-LIST-ITERATOR-CURSOR :TYPE KV-CONS)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_kv_list_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_kv_list_iterator_slot_value));
            }
            define_class_from_stringified_source("INTERVAL-ITERATOR", "(DEFCLASS INTERVAL-ITERATOR (ABSTRACT-ITERATOR) :ABSTRACT? TRUE :DOCUMENTATION \"An iterator that specifies a (possibly infinite) range of\nvalues.  Supports 'member?' test as well as iteration methods.\" :SLOTS ((LOWER-BOUND :TYPE UNKNOWN :REQUIRED? TRUE) (UPPER-BOUND :TYPE UNKNOWN :REQUIRED? TRUE)))");
            { Class* renamed_Class = define_class_from_stringified_source("INTEGER-INTERVAL-ITERATOR", "(DEFCLASS INTEGER-INTERVAL-ITERATOR (INTERVAL-ITERATOR) :PARAMETERS ((ANY-VALUE :TYPE INTEGER)) :SLOTS ((INTERVAL-CURSOR :TYPE INTEGER) (LOWER-BOUND :TYPE INTEGER :REQUIRED? TRUE) (UPPER-BOUND :TYPE INTEGER :REQUIRED? TRUE)) :INITIALIZER INITIALIZE-INTEGER-INTERVAL-ITERATOR)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_integer_interval_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_integer_interval_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("REVERSE-INTEGER-INTERVAL-ITERATOR", "(DEFCLASS REVERSE-INTEGER-INTERVAL-ITERATOR (INTERVAL-ITERATOR) :PARAMETERS ((ANY-VALUE :TYPE INTEGER)) :SLOTS ((INTERVAL-CURSOR :TYPE INTEGER) (LOWER-BOUND :TYPE INTEGER :REQUIRED? TRUE) (UPPER-BOUND :TYPE INTEGER :REQUIRED? TRUE)) :INITIALIZER INITIALIZE-REVERSE-INTEGER-INTERVAL-ITERATOR)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_reverse_integer_interval_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_reverse_integer_interval_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("STRING-ITERATOR", "(DEFCLASS STRING-ITERATOR (ABSTRACT-ITERATOR) :DOCUMENTATION \"Iterator that yields characters from a string.\" :PARAMETERS ((ANY-VALUE :TYPE CHARACTER)) :SLOTS ((THE-STRING :TYPE STRING) (CURSOR :TYPE INTEGER) (END :TYPE INTEGER)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_string_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_string_iterator_slot_value));
            }
            define_class_from_stringified_source("ABSTRACT-COLLECTION", "(DEFCLASS ABSTRACT-COLLECTION (STANDARD-OBJECT) :PARAMETERS ((ANY-VALUE :TYPE UNKNOWN)) :PUBLIC-METHODS ((ALLOCATE-ITERATOR ((SELF ABSTRACT-COLLECTION)) :TYPE (ABSTRACT-ITERATOR OF (LIKE (ANY-VALUE SELF))) (RETURN NULL)) (LENGTH ((SELF ABSTRACT-COLLECTION)) :TYPE INTEGER (RETURN NULL)) (INSERT ((SELF ABSTRACT-COLLECTION) (VALUE (LIKE (ANY-VALUE SELF))))) (REMOVE ((SELF ABSTRACT-COLLECTION) (VALUE (LIKE (ANY-VALUE SELF)))) :TYPE ABSTRACT-COLLECTION)) :ABSTRACT? TRUE)");
            define_class_from_stringified_source("COLLECTION", "(DEFCLASS COLLECTION (ABSTRACT-COLLECTION) :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :PUBLIC-METHODS ((ALLOCATE-ITERATOR ((SELF COLLECTION)) :TYPE (ITERATOR OF (LIKE (ANY-VALUE SELF))) (RETURN NULL)) (LENGTH ((SELF COLLECTION)) :TYPE INTEGER (RETURN NULL)) (INSERT ((SELF COLLECTION) (VALUE (LIKE (ANY-VALUE SELF)))) (RETURN)) (REMOVE ((SELF COLLECTION) (VALUE (LIKE (ANY-VALUE SELF)))) :TYPE COLLECTION (RETURN NULL))) :SLOTS ((CLOSED :TYPE BOOLEAN :ABSTRACT? TRUE)) :ABSTRACT? TRUE :SYNONYMS (OBJECT-COLLECTION))");
            define_class_from_stringified_source("SET-MIXIN", "(DEFCLASS SET-MIXIN () :DOCUMENTATION \"Users of this mixin check for duplicates inside of \nthe method 'insert'.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :MIXIN? TRUE)");
            define_class_from_stringified_source("SEQUENCE-MIXIN", "(DEFCLASS SEQUENCE-MIXIN () :PARAMETERS ((ANY-VALUE :TYPE UNKNOWN)) :PUBLIC-METHODS ((FIRST ((SEQUENCE SEQUENCE-MIXIN)) :TYPE (LIKE (ANY-VALUE SELF))) (NTH ((SEQUENCE SEQUENCE-MIXIN) (POSITION INTEGER)) :TYPE (LIKE (ANY-VALUE SELF)))) :MIXIN? TRUE)");
            define_class_from_stringified_source("SEQUENCE", "(DEFCLASS SEQUENCE (COLLECTION SEQUENCE-MIXIN) :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :PUBLIC-METHODS ((ALLOCATE-ITERATOR ((SELF SEQUENCE)) :TYPE (ITERATOR OF (LIKE (ANY-VALUE SELF))) (RETURN NULL)) (LENGTH ((SEQUENCE SEQUENCE)) :TYPE INTEGER (RETURN NULL))) :ABSTRACT? TRUE :SYNONYMS (OBJECT-SEQUENCE))");
            { Class* renamed_Class = define_class_from_stringified_source("LIST", "(DEFCLASS LIST (SEQUENCE) :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((THE-CONS-LIST :TYPE (CONS OF (LIKE (ANY-VALUE SELF))) :INITIALLY NIL)) :RECYCLE-METHOD :FREE-LIST :TERMINATOR TERMINATE-LIST? :INITIAL-VALUE NIL-LIST :PRINT-FORM (PRINT-CONS-LIST (THE-CONS-LIST SELF) STREAM))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_list));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_list_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("SET", "(DEFCLASS SET (COLLECTION SET-MIXIN) :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((THE-CONS-LIST :TYPE (CONS OF (LIKE (ANY-VALUE SELF))) :INITIALLY NIL)) :RECYCLE-METHOD :FREE-LIST :TERMINATOR TERMINATE-SET? :PRINT-FORM (PRINT-CONS-LIST (THE-CONS-LIST SELF) STREAM))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_set));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_set_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("CLASS-EXTENSION", "(DEFCLASS CLASS-EXTENSION (LIST) :PARAMETERS ((ANY-VALUE :TYPE ACTIVE-OBJECT)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_class_extension));
            }
            { Class* renamed_Class = define_class_from_stringified_source("CONS", "(DEFCLASS CONS (STANDARD-OBJECT) :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :METHODS ((ALLOCATE-ITERATOR ((SELF CONS)) :TYPE (ITERATOR OF (LIKE (ANY-VALUE SELF))))) :SLOTS ((VALUE :TYPE (LIKE (ANY-VALUE SELF)) :PUBLIC? TRUE) (REST :TYPE (CONS OF (LIKE (ANY-VALUE SELF))) :PUBLIC? TRUE :INITIALLY NIL)) :RECYCLE-METHOD :FREE-LIST :INITIAL-VALUE NIL :PRINT-FORM (PRINT-CONS SELF STREAM \"{\" \"}\"))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_cons));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_cons_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TRANSIENT-CONS", "(DEFCLASS TRANSIENT-CONS (CONS TRANSIENT-MIXIN) :RECYCLE-METHOD :FREE-AND-SWEEP-LIST :PRINT-FORM (PRINT-CONS SELF STREAM \"[\" \"]\"))");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_transient_cons));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_transient_cons_slot_value));
            }
            define_class_from_stringified_source("ABSTRACT-DICTIONARY", "(DEFCLASS ABSTRACT-DICTIONARY (ABSTRACT-COLLECTION) :PARAMETERS ((ANY-KEY :TYPE UNKNOWN) (ANY-VALUE :TYPE UNKNOWN)) :PUBLIC-METHODS ((LOOKUP ((SELF ABSTRACT-DICTIONARY) (KEY (LIKE (ANY-KEY SELF)))) :TYPE (LIKE (ANY-VALUE SELF))) (INSERT-AT ((SELF ABSTRACT-DICTIONARY) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))))) :METHODS ((ALLOCATE-ITERATOR ((SELF ABSTRACT-DICTIONARY)) :TYPE (ABSTRACT-DICTIONARY-ITERATOR OF (LIKE (ANY-KEY SELF)) (LIKE (ANY-VALUE SELF))) (RETURN NULL))) :ABSTRACT? TRUE)");
            define_class_from_stringified_source("DICTIONARY", "(DEFCLASS DICTIONARY (ABSTRACT-DICTIONARY) :PARAMETERS ((ANY-KEY :TYPE OBJECT) (ANY-VALUE :TYPE OBJECT)) :METHODS ((ALLOCATE-ITERATOR ((SELF DICTIONARY)) :TYPE (DICTIONARY-ITERATOR OF (LIKE (ANY-KEY SELF)) (LIKE (ANY-VALUE SELF))) (RETURN NULL))) :ABSTRACT? TRUE :SYNONYMS (OBJECT-TO-OBJECT-DICTIONARY))");
            { Class* renamed_Class = define_class_from_stringified_source("PROPERTY-LIST", "(DEFCLASS PROPERTY-LIST (DICTIONARY) :PARAMETERS ((ANY-KEY :TYPE OBJECT) (ANY-VALUE :TYPE OBJECT)) :SLOTS ((THE-PLIST :TYPE CONS :INITIALLY NIL)) :PRINT-FORM (PRINT-CONS-LIST (THE-PLIST SELF) STREAM))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_property_list));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_property_list_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("KV-CONS", "(DEFCLASS KV-CONS (STANDARD-OBJECT) :SLOTS ((KEY :TYPE OBJECT) (VALUE :TYPE OBJECT) (REST :TYPE KV-CONS)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"<\" (KEY SELF) \",\" (VALUE SELF) \">\"))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_kv_cons));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_kv_cons_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("KEY-VALUE-LIST", "(DEFCLASS KEY-VALUE-LIST (DICTIONARY) :PARAMETERS ((ANY-KEY :TYPE OBJECT) (ANY-VALUE :TYPE OBJECT)) :SLOTS ((THE-KV-LIST :TYPE KV-CONS)) :PRINT-FORM (PRINT-KEY-VALUE-LIST SELF STREAM))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_key_value_list));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_key_value_list_slot_value));
            }
            define_class_from_stringified_source("ABSTRACT-HASH-TABLE", "(DEFCLASS ABSTRACT-HASH-TABLE (ABSTRACT-DICTIONARY) :PARAMETERS ((ANY-KEY :TYPE UNKNOWN) (ANY-VALUE :TYPE UNKNOWN)) :SLOTS ((THE-HASH-TABLE :TYPE NATIVE-HASH-TABLE)) :INITIALIZER INITIALIZE-HASH-TABLE :ABSTRACT? TRUE)");
            { Class* renamed_Class = define_class_from_stringified_source("HASH-TABLE", "(DEFCLASS HASH-TABLE (ABSTRACT-HASH-TABLE) :PARAMETERS ((ANY-KEY :TYPE OBJECT) (ANY-VALUE :TYPE OBJECT)) :INITIALIZER INITIALIZE-HASH-TABLE :SYNONYMS (OBJECT-TO-OBJECT-HASH-TABLE))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_hash_table));
            }
            { Class* renamed_Class = define_class_from_stringified_source("INTEGER-HASH-TABLE", "(DEFCLASS INTEGER-HASH-TABLE (ABSTRACT-HASH-TABLE) :PARAMETERS ((ANY-KEY :TYPE INTEGER) (ANY-VALUE :TYPE OBJECT)) :INITIALIZER INITIALIZE-HASH-TABLE)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_integer_hash_table));
            }
            { Class* renamed_Class = define_class_from_stringified_source("FLOAT-HASH-TABLE", "(DEFCLASS FLOAT-HASH-TABLE (ABSTRACT-HASH-TABLE) :PARAMETERS ((ANY-KEY :TYPE FLOAT) (ANY-VALUE :TYPE OBJECT)) :INITIALIZER INITIALIZE-HASH-TABLE)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_float_hash_table));
            }
            { Class* renamed_Class = define_class_from_stringified_source("STRING-HASH-TABLE", "(DEFCLASS STRING-HASH-TABLE (ABSTRACT-HASH-TABLE) :PARAMETERS ((ANY-KEY :TYPE STRING) (ANY-VALUE :TYPE OBJECT)) :INITIALIZER INITIALIZE-HASH-TABLE)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_string_hash_table));
            }
            { Class* renamed_Class = define_class_from_stringified_source("STRING-TO-INTEGER-HASH-TABLE", "(DEFCLASS STRING-TO-INTEGER-HASH-TABLE (ABSTRACT-HASH-TABLE) :PARAMETERS ((ANY-KEY :TYPE STRING) (ANY-VALUE :TYPE INTEGER)) :INITIALIZER INITIALIZE-HASH-TABLE)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_string_to_integer_hash_table));
            }
            { Class* renamed_Class = define_class_from_stringified_source("VECTOR", "(DEFCLASS VECTOR (SEQUENCE) :PUBLIC-SLOTS ((ARRAY-SIZE :TYPE INTEGER :REQUIRED? TRUE)) :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :SLOTS ((THE-ARRAY :TYPE NATIVE-VECTOR)) :PRINT-FORM (PRINT-VECTOR SELF STREAM) :INITIALIZER INITIALIZE-VECTOR)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_vector));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_vector_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("EXTENSIBLE-VECTOR", "(DEFCLASS EXTENSIBLE-VECTOR (VECTOR) :INITIALIZER INITIALIZE-VECTOR)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_extensible_vector));
            }
            { Class* renamed_Class = define_class_from_stringified_source("EXTENSIBLE-SYMBOL-ARRAY", "(DEFCLASS EXTENSIBLE-SYMBOL-ARRAY (EXTENSIBLE-VECTOR) :DOCUMENTATION \"Self-extending array with methods for storing and\naccessing symbols within it.\" :SLOTS ((TOP-SYMBOL-OFFSET :TYPE INTEGER :INITIALLY -1) (POTENTIAL-FREE-SYMBOL-OFFSET :TYPE INTEGER :INITIALLY 0)) :INITIALIZER INITIALIZE-VECTOR)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_extensible_symbol_array));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_extensible_symbol_array_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("VECTOR-SEQUENCE", "(DEFCLASS VECTOR-SEQUENCE (VECTOR) :ABSTRACT? TRUE :SLOTS ((RESIZE-INCREMENT :TYPE INTEGER :HARDWIRED? TRUE :INITIALLY 100) (SEQUENCE-LENGTH :TYPE INTEGER)) :INITIALIZER INITIALIZE-VECTOR :SYNONYMS (VSEQ))");

              oHARDWIRED_RESIZE_INCREMENT_ON_VECTOR_SEQUENCEo = 100;
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_vector_sequence_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("SHORT-VECTOR-SEQUENCE", "(DEFCLASS SHORT-VECTOR-SEQUENCE (VECTOR-SEQUENCE) :SLOTS ((RESIZE-INCREMENT :TYPE INTEGER :HARDWIRED? TRUE :INITIALLY 4) (SEQUENCE-LENGTH :TYPE INTEGER :INITIALLY 0)) :INITIALIZER INITIALIZE-VECTOR :SYNONYMS (SVSEQ))");

              oHARDWIRED_RESIZE_INCREMENT_ON_VECTOR_SEQUENCEo = 100;
              oHARDWIRED_RESIZE_INCREMENT_ON_SHORT_VECTOR_SEQUENCEo = 4;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_short_vector_sequence));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_short_vector_sequence_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("BOOLEAN-VECTOR", "(DEFCLASS BOOLEAN-VECTOR (VECTOR) :PARAMETERS ((ANY-VALUE :TYPE BOOLEAN-WRAPPER)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_boolean_vector));
            }
            { Class* renamed_Class = define_class_from_stringified_source("INTEGER-VECTOR", "(DEFCLASS INTEGER-VECTOR (VECTOR) :PARAMETERS ((ANY-VALUE :TYPE INTEGER-WRAPPER)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_integer_vector));
            }
            { Class* renamed_Class = define_class_from_stringified_source("ARRAY", "(DEFCLASS ARRAY (ABSTRACT-COLLECTION) :CL-NATIVE-TYPE \"ARRAY\")");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_array));
            }
            { Class* renamed_Class = define_class_from_stringified_source("NULL-TERMINATED-ARRAY", "(DEFCLASS NULL-TERMINATED-ARRAY (ARRAY) :PUBLIC-METHODS ((LENGTH ((SELF NULL-TERMINATED-ARRAY)) :TYPE INTEGER)) :CL-NATIVE-TYPE \"ARRAY\")");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_null_terminated_array));
            }
            define_class_from_stringified_source("NATIVE-HASH-TABLE", "(DEFCLASS NATIVE-HASH-TABLE () :CPP-NATIVE-TYPE \"cpp_hash_table*\" :CL-NATIVE-TYPE \"HASH-TABLE\")");
            define_class_from_stringified_source("NATIVE-VECTOR", "(DEFCLASS NATIVE-VECTOR () :CPP-NATIVE-TYPE \"cpp_vector*\" :CL-NATIVE-TYPE \"VECTOR\")");
            define_class_from_stringified_source("ACTIVE-COLLECTION-MIXIN", "(DEFCLASS ACTIVE-COLLECTION-MIXIN () :DOCUMENTATION \"Mixin class that provides collection instances with a\nbackpointer to the instance slot they belong to.\" :MIXIN? TRUE :SLOTS ((ACTIVE-SLOT :TYPE STORAGE-SLOT) (OWNER-INSTANCE :TYPE STANDARD-OBJECT)))");
            { Class* renamed_Class = define_class_from_stringified_source("ACTIVE-LIST", "(DEFCLASS ACTIVE-LIST (LIST ACTIVE-COLLECTION-MIXIN))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_active_list));
            }
            { Class* renamed_Class = define_class_from_stringified_source("ACTIVE-SET", "(DEFCLASS ACTIVE-SET (LIST SET-MIXIN ACTIVE-COLLECTION-MIXIN))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_active_set));
            }
            { Class* renamed_Class = define_class_from_stringified_source("DEMON", "(DEFCLASS DEMON (STANDARD-OBJECT) :SLOTS ((DEMON-NAME :TYPE STRING) (DEMON-ACTION :TYPE KEYWORD) (DEMON-CLASS-REFS :TYPE (LIST OF TYPE) :ALLOCATION :EMBEDDED) (DEMON-SLOT-REFS :TYPE (LIST OF SYMBOL) :ALLOCATION :EMBEDDED) (DEMON-CODE :TYPE FUNCTION-CODE) (DEMON-METHOD :TYPE METHOD-SLOT) (DEMON-DOCUMENTATION :TYPE STRING) (DEMON-GUARD? :TYPE BOOLEAN) (DEMON-ALL? :TYPE BOOLEAN) (DEMON-INHERIT? :TYPE BOOLEAN)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_demon));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_demon_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("LIST-OF-SLOT", "(DEFCLASS LIST-OF-SLOT (LIST) :PARAMETERS ((ANY-VALUE :TYPE SLOT)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_list_of_slot));
            }
            { Class* renamed_Class = define_class_from_stringified_source("LIST-OF-SYMBOL", "(DEFCLASS LIST-OF-SYMBOL (LIST) :PARAMETERS ((ANY-VALUE :TYPE SYMBOL)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_list_of_symbol));
            }
            { Class* renamed_Class = define_class_from_stringified_source("LIST-OF-KEYWORD", "(DEFCLASS LIST-OF-KEYWORD (LIST) :PARAMETERS ((ANY-VALUE :TYPE KEYWORD)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_list_of_keyword));
            }
            { Class* renamed_Class = define_class_from_stringified_source("LIST-OF-TYPE", "(DEFCLASS LIST-OF-TYPE (LIST) :PARAMETERS ((ANY-VALUE :TYPE TYPE)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_list_of_type));
            }
            { Class* renamed_Class = define_class_from_stringified_source("KEYWORD-KEY-VALUE-LIST", "(DEFCLASS KEYWORD-KEY-VALUE-LIST (KEY-VALUE-LIST) :PARAMETERS ((ANY-KEY :TYPE KEYWORD) (ANY-VALUE :TYPE OBJECT)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_keyword_key_value_list));
            }
            { Class* renamed_Class = define_class_from_stringified_source("GENERALIZED-SYMBOL", "(DEFCLASS GENERALIZED-SYMBOL (CONTEXT-SENSITIVE-OBJECT) :SLOTS ((SYMBOL-NAME :TYPE STRING :REQUIRED? TRUE) (SYMBOL-ID :TYPE INTEGER) (INTERNED-IN :RENAMES HOME-CONTEXT :TYPE MODULE)) :ABSTRACT? TRUE)");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_generalized_symbol_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("SYMBOL", "(DEFCLASS SYMBOL (GENERALIZED-SYMBOL) :SLOTS ((SYMBOL-SLOT-OFFSET :TYPE INTEGER) (SYMBOL-VALUE-AND-PLIST :TYPE CONS :INITIALLY NIL)) :PRINT-FORM (PRINT-SYMBOL SELF STREAM))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_symbol));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_symbol_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("SURROGATE", "(DEFCLASS SURROGATE (GENERALIZED-SYMBOL) :DOCUMENTATION \"Rigid surrogate.\" :SLOTS ((SURROGATE-VALUE :TYPE OBJECT) (SURROGATE-NAME :RENAMES SYMBOL-NAME) (TYPE-CLASS :RENAMES SURROGATE-VALUE :TYPE CLASS) (TYPE-NAME :RENAMES SYMBOL-NAME) (SLOTREF-SLOT :RENAMES SURROGATE-VALUE :TYPE SLOT)) :SYNONYMS (TYPE SLOTREF) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM (RELATIVE-NAME SELF)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_surrogate));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_surrogate_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("KEYWORD", "(DEFCLASS KEYWORD (GENERALIZED-SYMBOL) :SLOTS ((KEYWORD-NAME :RENAMES SYMBOL-NAME)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \":\" (SYMBOL-NAME SELF)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_keyword));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_keyword_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("INDEXICAL", "(DEFCLASS INDEXICAL (GENERALIZED-SYMBOL) :DOCUMENTATION \"Surrogate with context sensitive value.\" :SLOTS ((INDEXICAL-VALUE :TYPE OBJECT :CONTEXT-SENSITIVE? TRUE)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM (RELATIVE-NAME SELF)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_indexical));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_indexical_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TRANSIENT-SYMBOL", "(DEFCLASS TRANSIENT-SYMBOL (SYMBOL TRANSIENT-MIXIN))");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_transient_symbol));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TRANSIENT-KEYWORD", "(DEFCLASS TRANSIENT-KEYWORD (KEYWORD TRANSIENT-MIXIN))");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_transient_keyword));
            }
            { Class* renamed_Class = define_class_from_stringified_source("MAPPABLE-OBJECT", "(DEFCLASS MAPPABLE-OBJECT (STANDARD-OBJECT DYNAMIC-SLOTS-MIXIN) :DOCUMENTATION \"The class MAPPABLE-OBJECT enables the definition of projections\nfrom a Stella class, slot, global variable, etc. onto a corresponding native\nentity.\" :ABSTRACT? TRUE :PUBLIC-SLOTS ((PROJECTS-ONTO :TYPE (LIST OF SYMBOL) :ALLOCATION :DYNAMIC) (PROJECTED-FROM :TYPE (LIST OF SYMBOL) :ALLOCATION :DYNAMIC) (PROJECTION-TRANSFORM :TYPE SYMBOL :ALLOCATION :DYNAMIC :DOCUMENTATION \"Names a coersion function that translates\nvalues retrieved from the 'from' entity to the 'projecting' entity.\")) :SLOTS ((NATIVE-NAME :TYPE STRING :ALLOCATION :DYNAMIC :DOCUMENTATION \"Used in cases when the native name cannot be\ncast as a symbol (e.g., because it contains illegal characters).\")))");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_mappable_object_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("RELATION", "(DEFCLASS RELATION (MAPPABLE-OBJECT) :ABSTRACT? TRUE :PUBLIC-SLOTS ((DOCUMENTATION :TYPE STRING :ALLOCATION :DYNAMIC) (ABSTRACT? :TYPE BOOLEAN :OPTION-KEYWORD :ABSTRACT?) (META-ATTRIBUTES :TYPE (KEY-VALUE-LIST OF GENERALIZED-SYMBOL OBJECT) :ALLOCATION :DYNAMIC :OPTION-KEYWORD :META-ATTRIBUTES) (PROPERTIES :TYPE (LIST OF GENERALIZED-SYMBOL) :ALLOCATION :DYNAMIC :OPTION-KEYWORD :PROPERTIES)) :PUBLIC-METHODS ((NAME ((SELF RELATION)) :TYPE STRING (RETURN NULL)) (HOME-MODULE ((SELF RELATION)) :TYPE MODULE (RETURN NULL)) (ARITY ((SELF RELATION)) :TYPE INTEGER (RETURN NULL)) (PUBLIC? ((SELF RELATION)) :TYPE BOOLEAN (RETURN NULL)) (DIRECT-SUPERS ((SELF RELATION)) :TYPE (LIST OF RELATION) (RETURN NULL)) (ALL-SUPERS ((SELF RELATION)) :TYPE (LIST OF RELATION) (RETURN NULL)) (SLOTS ((SELF RELATION)) :TYPE (ITERATOR OF SLOT) (RETURN NULL))) :SLOTS ((STORED-ACTIVE? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :DEFAULT NULL-BOOLEAN :OPTION-KEYWORD :ACTIVE?)))");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_relation_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("CLASS", string_concatenate("(DEFCLASS CLASS (RELATION) :PUBLIC-SLOTS ((CL-STRUCT? :TYPE BOOLEAN :INITIALLY FALSE) (MIXIN? :TYPE BOOLEAN :INITIALLY FALSE) (PRINT-FORM :TYPE OBJECT :ALLOCATION :DYNAMIC :OPTION-KEYWORD :PRINT-FORM)) :PUBLIC-METHODS ((NAME ((SELF CLASS)) :TYPE STRING (RETURN (SYMBOL-NAME (CLASS-TYPE SELF)))) (HOME-MODULE ((SELF CLASS)) :TYPE MODULE (RETURN (INTERNED-IN (CLASS-TYPE SELF)))) (ARITY ((SELF CLASS)) :TYPE INTEGER (RETURN 1)) (PUBLIC? ((SELF CLASS)) :TYPE BOOLEAN :STORAGE-SLOT CLASS-PUBLIC? (RETURN (CLASS-PUBLIC? SELF))) (ACTIVE? ((SELF CLASS)) :TYPE BOOLEAN :STORAGE-SLOT STORED-ACTIVE? (RETURN (OR (AND (DEFINED? (STORED-ACTIVE? SELF)) (STORED-ACTIVE? SELF)) (SUBTYPE-OF? (CLASS-TYPE SELF) @ACTIVE-OBJECT)))) (CREATOR ((SELF CLASS)) :TYPE SYMBOL :STORAGE-SLOT CLASS-CREATOR (RETURN (CLASS-CREATOR SELF))) (INITIALIZER ((SELF CLASS)) :TYPE SYMBOL :STORAGE-SLOT CLASS-INITIALIZER :INHERITS-THROUGH SUPER-CLASSES) (TERMINATOR ((SELF CLASS)) :TYPE SYMBOL :STORAGE-SLOT CLASS-TERMINATOR :INHERITS-THROUGH SUPER-CLASSES) (DESTRUCTOR ((SELF CLASS)) :TYPE SYMBOL :STORAGE-SLOT CLASS-DESTRUCTOR (RETURN (CLASS-DESTRUCTOR SELF))) (REQUIRED-SLOTS ((SELF CLASS)) :TYPE (LIST OF SYMBOL) :DOCUMENTATION \"Returns a list of names of required slots for 'self'.\" (RETURN (CLASS-REQUIRED-SLOT-NAMES SELF))) (PARAMETERS ((SELF CLASS)) :TYPE (LIST OF SYMBOL) :DOCUMENTATION \"Returns the list of parameters names of 'self'.\" :STORAGE-SLOT CLASS-PARAMETERS :INHERITS-THROUGH SUPER-CLASSES) (INITIAL-VALUE ((SELF CLASS)) :TYPE OBJECT :DOCUMENTATION \"Return an initial value for the class 'self'.\" :STORAGE-SLOT CLASS-INITIAL-VALUE :INHERITS-THROUGH SUPER-CLASSES) (EXTENSION ((SELF CLASS)) :TYPE CLASS-EXTENSION :DOCUMENTATION \"Return the nearest class extension that records instances\nof the class 'self'.\" :STORAGE-SLOT CLASS-EXTENSION :INHERITS-THROUGH SUPER-CLASSES) (CL-NATIVE-TYPE ((SELF CLASS)) :TYPE STRING :STORAGE-SLOT CLASS-CL-NATIVE-TYPE (RETURN (CLASS-CL-NATIVE-TYPE SELF))) (CPP-NATIVE-TYPE ((SELF CLASS)) :TYPE STRING :STORAGE-SLOT CLASS-CPP-NATIVE-TYPE (RETURN (CLASS-CPP-NATIVE-TYPE SELF))) (IDL-NATIVE-TYPE ((SELF CLASS)) :TYPE STRING :STORAGE-SLOT CLASS-IDL-NATIVE-TYPE (RETURN (CLASS-CPP-NATIVE-TYPE SELF))) (JAVA-NATIVE-TYPE ((SELF CLASS)) :TYPE STRING :STORAGE-SLOT CLASS-JAVA-NATIVE-TYPE (RETURN (CLASS-JAVA-NATIVE-TYPE SELF)))) :SLOTS ((CLASS-TYPE :TYPE TYPE) (CLASS-ARITY :TYPE INTEGER :INITIALLY 1 :HARDWIRED? TRUE) (CLASS-DIRECT-SUPERS :TYPE (LIST OF TYPE) :ALLOCATION :EMBEDDED) (CLASS-DIRECT-SUBS :TYPE (LIST OF TYPE) :ALLOCATION :EMBEDDED) (CLASS-ALL-SUPER-CLASSES :TYPE (CONS OF CLASS) :INITIALLY NIL) (CLASS-ALL-SLOTS :TYPE (CONS OF SLOT)) (CLASS-LOCAL-SLOTS :TYPE (LIST OF SLOT)) (CLASS-SLOT-AND-METHOD-CACHE :TYPE (VECTOR OF SLOT)) (CLASS-ABSTRACT? :TYPE BOOLEAN :INITIALLY FALSE :RENAMES ABSTRACT?) (CLASS-MIXIN? :TYPE BOOLEAN :INITIALLY FALSE :RENAMES MIXIN?) (CLASS-COLLECTION? :TYPE BOOLEAN :INITIALLY FALSE) (CLASS-CL-STRUCT? :TYPE BOOLEAN :INITIALLY FALSE :RENAMES CL-STRUCT?) (CLASS-CL-STRUCT-SLOTS :TYPE (LIST OF STORAGE-SLOT) :ALLOCATION :DYNAMIC) (CLASS-PUBLIC? :TYPE BOOLEAN :INITIALLY TRUE :OPTION-KEYWORD :PUBLIC?) (CLASS-RECYCLE-METHOD :TYPE KEYWORD :ALLOCATION :DYNAMIC :DEFAULT :NONE :OPTION-KEYWORD :RECYCLE-METHOD) (CLASS-FINALIZED? :TYPE BOOLEAN :INITIALLY FALSE) (CLASS-SLOTS-FINALIZED? :TYPE BOOLEAN :INITIALLY FALSE) (CLASS-STRINGIFIED-SOURCE :TYPE STRING) (CLASS-PARAMETERS :TYPE (LIST OF SYMBOL) :ALLOCATION :DYNAMIC :DEFAULT NIL-LIST :OPTION-KEYWORD :PARAMETERS) (CLASS-CONSTRUCTOR-CODE :TYPE FUNCTION-CODE) (CLASS-SLOT-ACCESSOR-CODE :TYPE FUNCTION-CODE) (CLASS-CREATOR :TYPE SYMBOL :ALLOCATION :DYNAMIC :OPTION-KEYWORD :CREATOR) (CLASS-INITIALIZER :TYPE SYMBOL :ALLOCATION :DYNAMIC :OPTION-KEYWORD :INITIALIZER) (CLASS-TERMINATOR :TYPE SYMBOL :ALLOCATION :DYNAMIC :OPTION-KEYWORD :TERMINATOR) (CLASS-DESTRUCTOR :TYPE SYMBOL :ALLOCATION :DYNAMIC :OPTION-KEYWORD :DESTRUCTOR) (CLASS-DOCUMENTATION :ALLOCATION :DYNAMIC :RENAMES DOCUMENTATION :OPTION-KEYWORD :DOCU", "MENTATION) (CLASS-EXTENSION-NAME :TYPE SYMBOL :ALLOCATION :DYNAMIC :OPTION-KEYWORD :EXTENSION) (CLASS-EXTENSION :TYPE CLASS-EXTENSION :ALLOCATION :DYNAMIC) (CLASS-REQUIRED-SLOT-NAMES :TYPE (LIST OF SYMBOL) :ALLOCATION :DYNAMIC :DEFAULT NIL-LIST) (CLASS-GUARD-CONSTRUCTOR-DEMONS :TYPE (LIST OF DEMON) :ALLOCATION :DYNAMIC) (CLASS-CONSTRUCTOR-DEMONS :TYPE (LIST OF DEMON) :ALLOCATION :DYNAMIC) (CLASS-GUARD-DESTRUCTOR-DEMONS :TYPE (LIST OF DEMON) :ALLOCATION :DYNAMIC) (CLASS-DESTRUCTOR-DEMONS :TYPE (LIST OF DEMON) :ALLOCATION :DYNAMIC) (CLASS-INITIAL-VALUE :TYPE OBJECT :ALLOCATION :DYNAMIC :OPTION-KEYWORD :INITIAL-VALUE) (CLASS-PRINT-FORM :TYPE OBJECT :RENAMES PRINT-FORM :OPTION-KEYWORD :PRINT-FORM) (CLASS-KEY :TYPE (LIST OF SLOT) :ALLOCATION :DYNAMIC :DEFAULT NIL-LIST) (CLASS-SYNONYMS :TYPE (LIST OF TYPE) :ALLOCATION :DYNAMIC :DEFAULT NIL-LIST :OPTION-KEYWORD :SYNONYMS) (CLASS-IS-LINK :TYPE TYPE :ALLOCATION :DYNAMIC) (CLASS-INVERSE-IS-LINK :TYPE CLASS :ALLOCATION :DYNAMIC) (CLASS-CL-NATIVE-TYPE :TYPE STRING :ALLOCATION :DYNAMIC :OPTION-KEYWORD :CL-NATIVE-TYPE) (CLASS-CPP-NATIVE-TYPE :TYPE STRING :ALLOCATION :DYNAMIC :OPTION-KEYWORD :CPP-NATIVE-TYPE) (CLASS-JAVA-NATIVE-TYPE :TYPE STRING :ALLOCATION :DYNAMIC :OPTION-KEYWORD :JAVA-NATIVE-TYPE) (CLASS-IDL-NATIVE-TYPE :TYPE STRING :ALLOCATION :DYNAMIC :OPTION-KEYWORD :IDL-NATIVE-TYPE) (CLASS-MARKED? :TYPE BOOLEAN) (CLASS-PROTOTYPE :TYPE OBJECT :ALLOCATION :DYNAMIC) (CLASS-TAXONOMY-NODE :TYPE TAXONOMY-NODE)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|C|\" (CHOOSE (DEFINED? (CLASS-TYPE SELF)) (SYMBOL-NAME (CLASS-TYPE SELF)) \"??\")))"));

              oHARDWIRED_CLASS_ARITY_ON_CLASSo = 1;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_class));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_class_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("POLYMORPHIC-RELATION", "(DEFCLASS POLYMORPHIC-RELATION (RELATION) :ABSTRACT? TRUE :SLOTS ((SLOT-DIRECT-EQUIVALENT :TYPE SLOT)) :PUBLIC-METHODS ((OWNER ((SELF POLYMORPHIC-RELATION)) :TYPE TYPE (RETURN NULL)) (RENAMES ((SELF POLYMORPHIC-RELATION)) :TYPE SYMBOL (RETURN NULL)) (ACTIVE? ((SELF POLYMORPHIC-RELATION)) :TYPE BOOLEAN :STORAGE-SLOT STORED-ACTIVE? :INHERITS-THROUGH EQUIVALENT-SLOT :DOCUMENTATION \"True if 'self' or a superslot of 'self' is marked active.\")))");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_polymorphic_relation_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("SLOT", "(DEFCLASS SLOT (POLYMORPHIC-RELATION) :ABSTRACT? TRUE :PUBLIC-METHODS ((NAME ((SELF SLOT)) :TYPE STRING (RETURN (SYMBOL-NAME (SLOT-NAME SELF)))) (HOME-MODULE ((SELF SLOT)) :TYPE MODULE (RETURN (INTERNED-IN (SLOT-NAME SELF)))) (TYPE ((SELF SLOT)) :TYPE TYPE :STORAGE-SLOT SLOT-BASE-TYPE :INHERITS-THROUGH EQUIVALENT-SLOT :DOCUMENTATION \"The type of a storage slot is its base type.\") (TYPE-SPECIFIER ((SELF SLOT)) :TYPE TYPE-SPEC :DOCUMENTATION \"If 'self' has a complex type return its\ntype specifier, otherwise, return 'type' of 'self'.\" (LET ((TSPEC (SLOT-TYPE-SPECIFIER SELF))) (RETURN (CHOOSE (DEFINED? TSPEC) TSPEC (TYPE SELF))))) (OWNER ((SELF SLOT)) :TYPE TYPE :STORAGE-SLOT SLOT-OWNER (RETURN (SLOT-OWNER SELF))) (RENAMES ((SELF SLOT)) :TYPE SYMBOL :STORAGE-SLOT SLOT-RENAMES (RETURN (SLOT-RENAMES SELF))) (SINGLE-VALUED? ((SELF SLOT)) :TYPE BOOLEAN :DOCUMENTATION \"True if slot values are not collections.\" (RETURN (NOT (SUBTYPE-OF? (SLOT-BASE-TYPE SELF) @COLLECTION)))) (CLOSURE-ASSUMPTION ((SELF SLOT)) :TYPE KEYWORD :STORAGE-SLOT SLOT-CLOSURE-ASSUMPTION :INHERITS-THROUGH EQUIVALENT-SLOT)) :PUBLIC-SLOTS ((INVERSE :TYPE SLOT :ALLOCATION :DYNAMIC)) :SLOTS ((SLOT-NAME :TYPE SYMBOL) (SLOT-OWNER :TYPE TYPE) (SLOT-BASE-TYPE :TYPE TYPE) (SLOT-TYPE-SPECIFIER :TYPE COMPOUND-TYPE-SPECIFIER :ALLOCATION :DYNAMIC) (SLOT-SLOTREF :TYPE SLOTREF) (SLOT-PUBLIC? :TYPE BOOLEAN :INITIALLY FALSE :OPTION-KEYWORD :PUBLIC?) (SLOT-INVERSE :TYPE SYMBOL :ALLOCATION :DYNAMIC :OPTION-KEYWORD :INVERSE) (SLOT-RENAMES :TYPE SYMBOL :ALLOCATION :DYNAMIC :OPTION-KEYWORD :RENAMES) (SLOT-RENAMED? :TYPE BOOLEAN :INITIALLY FALSE) (SLOT-DOCUMENTATION :TYPE STRING :ALLOCATION :DYNAMIC :RENAMES DOCUMENTATION :OPTION-KEYWORD :DOCUMENTATION) (SLOT-EXTERNAL? :TYPE BOOLEAN :INITIALLY FALSE) (SLOT-MARKED? :TYPE BOOLEAN) (SLOT-AUXILIARY? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :OPTION-KEYWORD :AUXILIARY?) (SLOT-DIRECT-SUPERS :TYPE (LIST OF SLOT) :ALLOCATION :DYNAMIC) (SLOT-DIRECT-SUBS :TYPE (LIST OF SLOT) :ALLOCATION :DYNAMIC) (SLOT-CLOSURE-ASSUMPTION :TYPE KEYWORD :ALLOCATION :DYNAMIC)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|S|\" (SYMBOL-NAME (SLOT-OWNER SELF)) \".\" (SYMBOL-NAME (SLOT-NAME SELF))))");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_slot_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("STORAGE-SLOT", "(DEFCLASS STORAGE-SLOT (SLOT) :PUBLIC-METHODS ((INITIALLY ((SELF STORAGE-SLOT)) :TYPE OBJECT) (ALLOCATION ((SELF STORAGE-SLOT)) :TYPE KEYWORD :STORAGE-SLOT SLOT-ALLOCATION :INHERITS-THROUGH EQUIVALENT-SLOT :DOCUMENTATION \"Return the most specific :allocation facet, or\n:instance if all inherited values are NULL.\") (DEFAULT-FORM ((SELF STORAGE-SLOT)) :TYPE OBJECT :STORAGE-SLOT SLOT-DEFAULT-EXPRESSION :INHERITS-THROUGH EQUIVALENT-SLOT :DOCUMENTATION \"Returns the current value of default expression when the\nslot has not been assigned a value.\") (REQUIRED? ((SELF STORAGE-SLOT)) :TYPE BOOLEAN :STORAGE-SLOT SLOT-REQUIRED? :INHERITS-THROUGH EQUIVALENT-SLOT :DOCUMENTATION \"True if a value must be assigned to this slot at\ncreation time.\") (COMPONENT? ((SELF STORAGE-SLOT)) :TYPE BOOLEAN :STORAGE-SLOT SLOT-COMPONENT? :INHERITS-THROUGH EQUIVALENT-SLOT :DOCUMENTATION \"True if fillers of this slot are components of the\nowner slot, and therefore should be deleted if the owner is deleted.\") (READER ((SELF STORAGE-SLOT)) :TYPE SYMBOL :STORAGE-SLOT SLOT-READER :INHERITS-THROUGH EQUIVALENT-SLOT :DOCUMENTATION \"Name of a method called to read the value of the slot\n'self'.\") (WRITER ((SELF STORAGE-SLOT)) :TYPE SYMBOL :STORAGE-SLOT SLOT-WRITER :INHERITS-THROUGH EQUIVALENT-SLOT :DOCUMENTATION \"Name of a method called to write the value of the slot\n'self'.\")) :SLOTS ((SLOT-INITIAL-VALUE :TYPE OBJECT :ALLOCATION :DYNAMIC :OPTION-KEYWORD :INITIALLY) (SLOT-ALLOCATION :TYPE KEYWORD :ALLOCATION :DYNAMIC :DEFAULT :INSTANCE :OPTION-KEYWORD :ALLOCATION) (SLOT-DEFAULT-EXPRESSION :TYPE OBJECT :ALLOCATION :DYNAMIC :OPTION-KEYWORD :DEFAULT) (SLOT-GUARD-DEMONS :TYPE (LIST OF DEMON) :ALLOCATION :DYNAMIC) (SLOT-DEMONS :TYPE (LIST OF DEMON) :ALLOCATION :DYNAMIC) (SLOT-REQUIRED? :TYPE BOOLEAN :OPTION-KEYWORD :REQUIRED?) (SLOT-COMPONENT? :TYPE BOOLEAN :OPTION-KEYWORD :COMPONENT?) (SLOT-READ-ONLY? :TYPE BOOLEAN :OPTION-KEYWORD :READ-ONLY?) (SLOT-HARDWIRED? :TYPE BOOLEAN :OPTION-KEYWORD :HARDWIRED?) (SLOT-CONTEXT-SENSITIVE? :TYPE BOOLEAN :OPTION-KEYWORD :CONTEXT-SENSITIVE?) (SLOT-READER :TYPE SYMBOL :ALLOCATION :DYNAMIC :OPTION-KEYWORD :READER) (SLOT-WRITER :TYPE SYMBOL :ALLOCATION :DYNAMIC :OPTION-KEYWORD :WRITER) (SLOT-ACCESSOR-METHODS :TYPE (LIST OF METHOD-SLOT) :ALLOCATION :DYNAMIC) (SLOT-OPTION-KEYWORD :TYPE KEYWORD :ALLOCATION :DYNAMIC :OPTION-KEYWORD :OPTION-KEYWORD) (SLOT-OPTION-HANDLER :TYPE SYMBOL :ALLOCATION :DYNAMIC :OPTION-KEYWORD :OPTION-HANDLER)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_storage_slot));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_storage_slot_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("METHOD-SLOT", "(DEFCLASS METHOD-SLOT (SLOT) :SYNONYMS (FUNCTION) :PUBLIC-SLOTS ((STORAGE-SLOT :TYPE SYMBOL :ALLOCATION :DYNAMIC)) :PUBLIC-METHODS ((SETTER? ((SELF METHOD-SLOT)) :TYPE BOOLEAN :STORAGE-SLOT METHOD-SETTER? (RETURN (METHOD-SETTER? SELF)))) :SLOTS ((METHOD-SETTER? :TYPE BOOLEAN) (METHOD-DOCUMENTATION :TYPE STRING :ALLOCATION :DYNAMIC :RENAMES DOCUMENTATION) (METHOD-PARAMETER-NAMES :TYPE (LIST OF SYMBOL) :DEFAULT NIL-LIST :COMPONENT? TRUE) (METHOD-PARAMETER-TYPE-SPECIFIERS :TYPE (LIST OF TYPE-SPEC) :DEFAULT NIL-LIST :COMPONENT? TRUE) (METHOD-PARAMETER-DIRECTIONS :TYPE (LIST OF SYMBOL) :DEFAULT NIL-LIST :COMPONENT? TRUE :ALLOCATION :DYNAMIC) (METHOD-RETURN-TYPE-SPECIFIERS :TYPE (LIST OF TYPE-SPEC) :DEFAULT NIL-LIST :COMPONENT? TRUE) (METHOD-STRINGIFIED-SOURCE :TYPE STRING) (METHOD-CODE :TYPE METHOD-CODE) (FUNCTION-CODE :TYPE FUNCTION-CODE) (METHOD-FUNCTION? :TYPE BOOLEAN) (METHOD-VARIABLE-ARGUMENTS? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :DEFAULT FALSE) (METHOD-BODY-ARGUMENT? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :DEFAULT FALSE) (METHOD-AUXILIARY? :RENAMES SLOT-AUXILIARY?) (METHOD-NATIVE? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :DEFAULT FALSE) (METHOD-GLOBALLY-INLINE? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :DEFAULT FALSE) (METHOD-INLINED-FUNCTIONS :TYPE (LIST OF SYMBOL) :ALLOCATION :DYNAMIC :DEFAULT NIL-LIST) (METHOD-STORAGE-SLOT :TYPE SYMBOL :ALLOCATION :DYNAMIC :RENAMES STORAGE-SLOT) (METHOD-INHERITS-THROUGH :TYPE SYMBOL :ALLOCATION :DYNAMIC) (METHOD-COMMAND? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :DEFAULT FALSE) (METHOD-EVALUATE-ARGUMENTS? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :DEFAULT TRUE) (METHOD-LISP-MACRO? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :DEFAULT NULL-BOOLEAN) (EVALUATOR-WRAPPER-CODE :TYPE FUNCTION-CODE :ALLOCATION :DYNAMIC)) :PRINT-FORM (IF (METHOD-FUNCTION? SELF) (PRINT-NATIVE-STREAM STREAM \"|F|\" (SYMBOL-NAME (SLOT-NAME SELF))) (PRINT-NATIVE-STREAM STREAM \"|M|\" (SYMBOL-NAME (SLOT-OWNER SELF)) \".\" (SYMBOL-NAME (SLOT-NAME SELF)))))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_method_slot));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_method_slot_slot_value));
            }
            define_class_from_stringified_source("COMPOUND-TYPE-SPECIFIER", "(DEFCLASS COMPOUND-TYPE-SPECIFIER (STANDARD-OBJECT) :ABSTRACT? TRUE :PUBLIC? FALSE :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|TS|\" (YIELD-TYPE-SPEC-TREE SELF)))");
            { Class* renamed_Class = define_class_from_stringified_source("PARAMETRIC-TYPE-SPECIFIER", "(DEFCLASS PARAMETRIC-TYPE-SPECIFIER (COMPOUND-TYPE-SPECIFIER) :SLOTS ((SPECIFIER-BASE-TYPE :TYPE TYPE) (SPECIFIER-PARAMETER-TYPES :TYPE (LIST OF TYPE-SPEC) :ALLOCATION :EMBEDDED) (SPECIFIER-SEQUENCE-SIZE :TYPE INTEGER)) :CREATOR MAKE-PARAMETRIC-TYPE-SPECIFIER)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_parametric_type_specifier));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_parametric_type_specifier_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TRANSIENT-TYPE-SPECIFIER", "(DEFCLASS TRANSIENT-TYPE-SPECIFIER (PARAMETRIC-TYPE-SPECIFIER TRANSIENT-MIXIN) :RECYCLE-METHOD :SWEEP-LIST :TERMINATOR TERMINATE-TRANSIENT-TYPE-SPECIFIER?)");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_transient_type_specifier));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_transient_type_specifier_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("ANCHORED-TYPE-SPECIFIER", "(DEFCLASS ANCHORED-TYPE-SPECIFIER (COMPOUND-TYPE-SPECIFIER) :SLOTS ((SPECIFIER-PARAMETER-NAME :TYPE SYMBOL)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_anchored_type_specifier));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_anchored_type_specifier_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TABLE", "(DEFCLASS TABLE (SLOT) :PARAMETERS ((ANY-VALUE :TYPE BOOLEAN)) :SLOTS ((TUPLE-DOMAINS :TYPE (LIST OF TYPE-SPEC)) (VARIABLE-ARITY? :TYPE BOOLEAN :ALLOCATION :DYNAMIC)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|T|\" (SYMBOL-NAME (SLOT-NAME SELF))))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_table));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_table_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("GLOBAL-VARIABLE", "(DEFCLASS GLOBAL-VARIABLE (MAPPABLE-OBJECT) :PUBLIC-SLOTS ((DOCUMENTATION :TYPE STRING)) :PUBLIC-METHODS ((NAME ((SELF GLOBAL-VARIABLE)) :TYPE STRING (RETURN (SYMBOL-NAME (VARIABLE-NAME SELF)))) (TYPE ((SELF GLOBAL-VARIABLE)) :TYPE TYPE :STORAGE-SLOT VARIABLE-TYPE (RETURN (VARIABLE-TYPE SELF)))) :SLOTS ((VARIABLE-NAME :TYPE SYMBOL) (VARIABLE-TYPE :TYPE TYPE) (VARIABLE-TYPE-SPECIFIER :TYPE TYPE-SPEC :ALLOCATION :DYNAMIC) (VARIABLE-SPECIAL? :TYPE BOOLEAN) (VARIABLE-CONSTANT? :TYPE BOOLEAN) (VARIABLE-PUBLIC? :TYPE BOOLEAN) (VARIABLE-AUXILIARY? :TYPE BOOLEAN) (VARIABLE-GET-VALUE-CODE :TYPE FUNCTION-CODE) (VARIABLE-SET-VALUE-CODE :TYPE FUNCTION-CODE) (VARIABLE-VALUE-STACK :TYPE LIST) (VARIABLE-DOCUMENTATION :TYPE STRING :RENAMES DOCUMENTATION) (VARIABLE-STRINGIFIED-SOURCE :TYPE STRING)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_global_variable));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_global_variable_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("QUOTED-EXPRESSION", "(DEFCLASS QUOTED-EXPRESSION (STANDARD-OBJECT) :SLOTS ((QUOTATION-TABLE-OFFSET :TYPE INTEGER)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_quoted_expression));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_quoted_expression_slot_value));
            }
            define_class_from_stringified_source("VOID", "(DEFCLASS VOID () :ABSTRACT? TRUE :JAVA-NATIVE-TYPE \"void\" :IDL-NATIVE-TYPE \"void\" :CPP-NATIVE-TYPE \"void\")");
            define_class_from_stringified_source("UNKNOWN", "(DEFCLASS UNKNOWN () :ABSTRACT? TRUE :CPP-NATIVE-TYPE \"unknown\" :IDL-NATIVE-TYPE \"unknown\" :JAVA-NATIVE-TYPE \"unknown\" :SLOTS ((UNKNOWN-SLOT :TYPE UNKNOWN)))");
            { Class* renamed_Class = define_class_from_stringified_source("CONTEXT", "(DEFCLASS CONTEXT (STANDARD-OBJECT DYNAMIC-SLOTS-MIXIN) :ABSTRACT? TRUE :SLOTS ((CHILD-CONTEXTS :TYPE (LIST OF CONTEXT) :ALLOCATION :EMBEDDED) (ALL-SUPER-CONTEXTS :TYPE (CONS OF CONTEXT)) (BASE-MODULE :TYPE MODULE) (CONTEXT-NUMBER :TYPE INTEGER)) :METHODS ((CONTEXT-NAME ((SELF CONTEXT)) :TYPE STRING (LET ((AUX SELF)) (TYPECASE AUX (MODULE (RETURN (MODULE-NAME AUX))) (WORLD (RETURN (WORLD-NAME AUX)))))) (PARENT-CONTEXTS ((SELF CONTEXT)) :TYPE (ITERATOR OF CONTEXT))) :PRINT-FORM (PRINT-CONTEXT SELF STREAM))");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_context_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("MODULE", "(DEFCLASS MODULE (CONTEXT) :PUBLIC-METHODS ((NATIVE-PACKAGE ((SELF MODULE)) :TYPE STRING :STORAGE-SLOT MODULE-NATIVE-PACKAGE :INHERITS-THROUGH PARENT-MODULES)) :PUBLIC-SLOTS ((PARENT-MODULES :TYPE (LIST OF MODULE) :ALLOCATION :EMBEDDED) (DOCUMENTATION :TYPE STRING) (REQUIRES :TYPE (LIST OF MODULE)) (USES :TYPE (LIST OF MODULE) :ALLOCATION :EMBEDDED) (USED-BY :TYPE (LIST OF MODULE) :ALLOCATION :EMBEDDED) (SHADOWED-SURROGATES :TYPE (LIST OF SURROGATE) :ALLOCATION :DYNAMIC) (MODULE-NATIVE-PACKAGE :TYPE STRING :DEFAULT \"STELLA\") (DIRECTORY-FILE :TYPE FILE-NAME) (CODE-FILES :TYPE (LIST OF STRING-WRAPPER) :ALLOCATION :EMBEDDED) (DEFINITIONS-FILE :TYPE FILE-NAME) (LOGIC-DIALECT :TYPE KEYWORD :ALLOCATION :DYNAMIC :DEFAULT :KIF) (OPEN-WORLD-ASSUMPTION? :TYPE BOOLEAN :INITIALLY FALSE) (CASE-SENSITIVE? :TYPE BOOLEAN :INITIALLY FALSE) (CLEARABLE? :TYPE BOOLEAN :ALLOCATION :DYNAMIC :DEFAULT TRUE :OPTION-KEYWORD :CLEARABLE?)) :SLOTS ((MODULE-NAME :TYPE STRING :ALLOCATION :INSTANCE) (MODULE-FULL-NAME :TYPE STRING) (MODULE-STRINGIFIED-SOURCE :TYPE STRING) (STRINGIFIED-OPTIONS :TYPE STRING) (CARDINAL-MODULE :TYPE MODULE) (SYMBOL-OFFSET-TABLE :TYPE STRING-TO-INTEGER-HASH-TABLE) (SURROGATE-OFFSET-TABLE :TYPE STRING-TO-INTEGER-HASH-TABLE) (INDEXICAL-OFFSET-TABLE :TYPE STRING-TO-INTEGER-HASH-TABLE) (ELABORATED-WORLD :TYPE WORLD)) :PUBLIC-METHODS ((NAME ((SELF MODULE)) :TYPE STRING (RETURN (MODULE-NAME SELF))) (PARENT-MODULE ((SELF MODULE)) :TYPE MODULE (RETURN (POP (PARENT-CONTEXTS SELF)))) (CLOSED-WORLD-ASSUMPTION? ((SELF MODULE)) :TYPE BOOLEAN (RETURN (NOT (OPEN-WORLD-ASSUMPTION? SELF))))))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_module));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_module_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("WORLD", "(DEFCLASS WORLD (CONTEXT) :SLOTS ((PARENT-CONTEXT :TYPE CONTEXT) (CHILD-CONTEXTS :TYPE (LIST OF WORLD) :ALLOCATION :EMBEDDED) (WORLD-NAME :TYPE STRING :ALLOCATION :DYNAMIC)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_world));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_world_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("CS-VALUE", "(DEFCLASS CS-VALUE (KEY-VALUE-LIST) :DOCUMENTATION \"Contextualized value.  Contains a sorted kv-cons list indexed\nby context. The kv-cons list is never null.  Newer (higher numbered) contexts\nappear first.\" :PARAMETERS ((ANY-KEY :TYPE CONTEXT) (ANY-VALUE :TYPE OBJECT)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_cs_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("INTERVAL", "(DEFCLASS INTERVAL (STANDARD-OBJECT) :SLOTS ((LOWER-BOUND :TYPE INTEGER) (UPPER-BOUND :TYPE INTEGER)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"[\" (LOWER-BOUND SELF) \",\" (UPPER-BOUND SELF) \"]\"))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_interval));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_interval_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TAXONOMY-NODE", "(DEFCLASS TAXONOMY-NODE (STANDARD-OBJECT) :SLOTS ((PARENTS :TYPE (CONS OF TAXONOMY-NODE) :INITIALLY NIL) (TREE-CHILDREN :TYPE (CONS OF TAXONOMY-NODE) :INITIALLY NIL) (CHILDREN :TYPE (CONS OF TAXONOMY-NODE) :INITIALLY NIL) (FIRST-INTERVAL-LOWER-BOUND :TYPE INTEGER :INITIALLY -1) (FIRST-INTERVAL-UPPER-BOUND :TYPE INTEGER :INITIALLY -1) (INITIAL-INTERVAL :TYPE INTERVAL) (INTERVALS :TYPE (CONS OF INTERVAL) :INITIALLY NIL) (TOTAL-ANCESTORS :TYPE INTEGER :INITIALLY 1) (LABEL :TYPE INTEGER) (NATIVE-OBJECT :TYPE OBJECT)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|TN|\" (LABEL SELF) \" \" (INTERVALS SELF) \" \" (NATIVE-OBJECT SELF)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_taxonomy_node));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_taxonomy_node_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TAXONOMY-GRAPH", "(DEFCLASS TAXONOMY-GRAPH (STANDARD-OBJECT) :SLOTS ((INCREMENTAL-MODE? :TYPE BOOLEAN :INITIALLY FALSE) (RENUMBER-IF-OUT-OF-NUMBERS? :TYPE BOOLEAN :INITIALLY FALSE) (LARGEST-POSTORDER-NUMBER :TYPE INTEGER) (ROOTS :TYPE (CONS OF TAXONOMY-NODE) :INITIALLY NIL) (BROKEN-LINKS :TYPE (CONS OF (CONS OF TAXONOMY-NODE)) :INITIALLY NIL)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|TG|\" (ROOTS SELF)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_taxonomy_graph));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_taxonomy_graph_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("EXCEPTION", "(DEFCLASS EXCEPTION (STANDARD-OBJECT))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_exception));
            }
            define_class_from_stringified_source("NATIVE-ENVIRONMENT-POINTER", "(DEFCLASS NATIVE-ENVIRONMENT-POINTER () :CPP-NATIVE-TYPE \"jump_buffer\" :CL-NATIVE-TYPE \"KEYWORD\")");
            { Class* renamed_Class = define_class_from_stringified_source("STELLA-EXCEPTION", "(DEFCLASS STELLA-EXCEPTION (EXCEPTION))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_stella_exception));
            }
            { Class* renamed_Class = define_class_from_stringified_source("READ-EXCEPTION", "(DEFCLASS READ-EXCEPTION (STELLA-EXCEPTION))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_read_exception));
            }
            { Class* renamed_Class = define_class_from_stringified_source("UNHANDLED-EXCEPTION", "(DEFCLASS UNHANDLED-EXCEPTION (EXCEPTION))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_unhandled_exception));
            }
            define_class_from_stringified_source("LITERAL", "(DEFCLASS LITERAL (NON-OBJECT) :ABSTRACT? TRUE)");
            define_class_from_stringified_source("NUMBER", "(DEFCLASS NUMBER (LITERAL) :ABSTRACT? TRUE)");
            define_class_from_stringified_source("INTEGER", "(DEFCLASS INTEGER (NUMBER) :CL-NATIVE-TYPE \"INTEGER\" :CPP-NATIVE-TYPE \"int\" :IDL-NATIVE-TYPE \"long\" :JAVA-NATIVE-TYPE \"int\" :INITIAL-VALUE NULL-INTEGER :EQUALITY-TEST EQL?)");
            define_class_from_stringified_source("FLOAT", "(DEFCLASS FLOAT (NUMBER) :CL-NATIVE-TYPE \"FLOAT\" :CPP-NATIVE-TYPE \"double\" :IDL-NATIVE-TYPE \"double\" :JAVA-NATIVE-TYPE \"double\" :INITIAL-VALUE NULL-FLOAT :EQUALITY-TEST EQL?)");
            define_class_from_stringified_source("STRING", "(DEFCLASS STRING (LITERAL) :SYNONYMS (FILE-NAME) :CL-NATIVE-TYPE \"STRING\" :IDL-NATIVE-TYPE \"string\" :JAVA-NATIVE-TYPE \"String\" :CPP-NATIVE-TYPE \"char*\" :EQUALITY-TEST STRING-EQL?)");
            define_class_from_stringified_source("CHARACTER", "(DEFCLASS CHARACTER (LITERAL) :CL-NATIVE-TYPE \"CHARACTER\" :CPP-NATIVE-TYPE \"char\" :IDL-NATIVE-TYPE \"char\" :JAVA-NATIVE-TYPE \"char\" :INITIAL-VALUE NULL-CHARACTER)");
            define_class_from_stringified_source("SHORT-INTEGER", "(DEFCLASS SHORT-INTEGER (INTEGER) :CL-NATIVE-TYPE \"INTEGER\" :CPP-NATIVE-TYPE \"short int\" :IDL-NATIVE-TYPE \"short int\" :INITIAL-VALUE NULL-SHORT-INTEGER :EQUALITY-TEST EQL?)");
            define_class_from_stringified_source("LONG-INTEGER", "(DEFCLASS LONG-INTEGER (INTEGER) :CL-NATIVE-TYPE \"INTEGER\" :CPP-NATIVE-TYPE \"long int\" :IDL-NATIVE-TYPE \"long int\" :INITIAL-VALUE NULL-LONG-INTEGER :EQUALITY-TEST EQL?)");
            define_class_from_stringified_source("UNSIGNED-SHORT-INTEGER", "(DEFCLASS UNSIGNED-SHORT-INTEGER (INTEGER) :CL-NATIVE-TYPE \"INTEGER\" :CPP-NATIVE-TYPE \"unsigned short int\" :IDL-NATIVE-TYPE \"unsigned short int\" :INITIAL-VALUE NULL-UNSIGNED-SHORT-INTEGER :EQUALITY-TEST EQL?)");
            define_class_from_stringified_source("UNSIGNED-LONG-INTEGER", "(DEFCLASS UNSIGNED-LONG-INTEGER (INTEGER) :CL-NATIVE-TYPE \"INTEGER\" :IDL-NATIVE-TYPE \"unsigned long int\" :CPP-NATIVE-TYPE \"unsigned long int\" :INITIAL-VALUE NULL-UNSIGNED-LONG-INTEGER :EQUALITY-TEST EQL?)");
            define_class_from_stringified_source("SINGLE-FLOAT", "(DEFCLASS SINGLE-FLOAT (FLOAT) :CL-NATIVE-TYPE \"FLOAT\" :JAVA-NATIVE-TYPE \"float\" :IDL-NATIVE-TYPE \"float\" :CPP-NATIVE-TYPE \"float\" :INITIAL-VALUE NULL-SINGLE-FLOAT :EQUALITY-TEST EQL?)");
            define_class_from_stringified_source("DOUBLE-FLOAT", "(DEFCLASS DOUBLE-FLOAT (FLOAT) :CL-NATIVE-TYPE \"FLOAT\" :CPP-NATIVE-TYPE \"double\" :JAVA-NATIVE-TYPE \"double\" :IDL-NATIVE-TYPE \"double\" :INITIAL-VALUE NULL-DOUBLE-FLOAT :EQUALITY-TEST EQL?)");
            define_class_from_stringified_source("BYTE", "(DEFCLASS BYTE (CHARACTER) :CL-NATIVE-TYPE \"CHARACTER\" :CPP-NATIVE-TYPE \"char\" :IDL-NATIVE-TYPE \"char\" :JAVA-NATIVE-TYPE \"char\" :INITIAL-VALUE NULL-BYTE :EQUALITY-TEST EQL?)");
            define_class_from_stringified_source("OCTET", "(DEFCLASS OCTET (BYTE) :CL-NATIVE-TYPE \"FIXNUM\" :CPP-NATIVE-TYPE \"octet\" :IDL-NATIVE-TYPE \"octet\" :JAVA-NATIVE-TYPE \"octet\" :INITIAL-VALUE NULL-OCTET :EQUALITY-TEST EQL?)");
            define_class_from_stringified_source("WRAPPER", "(DEFCLASS WRAPPER (OBJECT) :SLOTS ((WRAPPER-VALUE :TYPE UNKNOWN :REQUIRED? TRUE)) :KEY (WRAPPER-VALUE) :PUBLIC? FALSE :ABSTRACT? TRUE :TERMINATOR TERMINATE-WRAPPER?)");
            define_class_from_stringified_source("LITERAL-WRAPPER", "(DEFCLASS LITERAL-WRAPPER (WRAPPER) :ABSTRACT? TRUE)");
            define_class_from_stringified_source("NUMBER-WRAPPER", "(DEFCLASS NUMBER-WRAPPER (LITERAL-WRAPPER) :ABSTRACT? TRUE)");
            { Class* renamed_Class = define_class_from_stringified_source("INTEGER-WRAPPER", "(DEFCLASS INTEGER-WRAPPER (NUMBER-WRAPPER) :SLOTS ((WRAPPER-VALUE :TYPE INTEGER)) :PRINT-FORM (IF *PRINTREADABLY?* (PRINT-NATIVE-STREAM STREAM (WRAPPER-VALUE SELF)) (PRINT-NATIVE-STREAM STREAM (CHOOSE (TRANSIENT-OBJECT? SELF) \"!L!\" \"|L|\") (WRAPPER-VALUE SELF))) :RECYCLE-METHOD :FREE-LIST)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_integer_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_integer_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("FLOAT-WRAPPER", "(DEFCLASS FLOAT-WRAPPER (NUMBER-WRAPPER) :SLOTS ((WRAPPER-VALUE :TYPE FLOAT)) :PRINT-FORM (IF *PRINTREADABLY?* (PRINT-NATIVE-STREAM STREAM (WRAPPER-VALUE SELF)) (PRINT-NATIVE-STREAM STREAM (CHOOSE (TRANSIENT-OBJECT? SELF) \"!L!\" \"|L|\") (WRAPPER-VALUE SELF))) :RECYCLE-METHOD :FREE-LIST)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_float_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_float_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("STRING-WRAPPER", "(DEFCLASS STRING-WRAPPER (LITERAL-WRAPPER) :SLOTS ((WRAPPER-VALUE :TYPE STRING)) :PRINT-FORM (LET ((VALUE (WRAPPER-VALUE SELF))) (IF *PRINTREADABLY?* (PRINT-STRING-READABLY VALUE STREAM) (IF (DEFINED? VALUE) (PRINT-NATIVE-STREAM STREAM (CHOOSE (TRANSIENT-OBJECT? SELF) \"!L!\" \"|L|\") #\\\" VALUE #\\\") (PRINT-NATIVE-STREAM STREAM (CHOOSE (TRANSIENT-OBJECT? SELF) \"!L!\" \"|L|\") \"NULL-STRING\")))) :RECYCLE-METHOD :FREE-LIST)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_string_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_string_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("CHARACTER-WRAPPER", "(DEFCLASS CHARACTER-WRAPPER (LITERAL-WRAPPER) :SLOTS ((WRAPPER-VALUE :TYPE CHARACTER)) :PRINT-FORM (IF *PRINTREADABLY?* (PRINT-CHARACTER (WRAPPER-VALUE SELF) STREAM) (PROGN (PRINT-NATIVE-STREAM STREAM (CHOOSE (TRANSIENT-OBJECT? SELF) \"!L!\" \"|L|\")) (PRINT-CHARACTER (WRAPPER-VALUE SELF) STREAM))) :RECYCLE-METHOD :FREE-LIST)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_character_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_character_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("BOOLEAN-WRAPPER", "(DEFCLASS BOOLEAN-WRAPPER (LITERAL-WRAPPER) :SLOTS ((WRAPPER-VALUE :TYPE BOOLEAN :ALLOCATION :INSTANCE)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM (CHOOSE *PRINTREADABLY?* \"\" \"|L|\") (CHOOSE (NULL? (WRAPPER-VALUE SELF)) (QUOTE NULL-BOOLEAN) (CHOOSE (WRAPPER-VALUE SELF) (QUOTE TRUE) (QUOTE FALSE)))))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_boolean_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_boolean_wrapper_slot_value));
            }
            define_class_from_stringified_source("CODE-WRAPPER", "(DEFCLASS CODE-WRAPPER (WRAPPER) :ABSTRACT? TRUE)");
            { Class* renamed_Class = define_class_from_stringified_source("FUNCTION-CODE-WRAPPER", "(DEFCLASS FUNCTION-CODE-WRAPPER (CODE-WRAPPER) :SLOTS ((WRAPPER-VALUE :TYPE FUNCTION-CODE)) :RECYCLE-METHOD :FREE-LIST)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_function_code_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_function_code_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("METHOD-CODE-WRAPPER", "(DEFCLASS METHOD-CODE-WRAPPER (CODE-WRAPPER) :SLOTS ((WRAPPER-VALUE :TYPE METHOD-CODE)) :RECYCLE-METHOD :FREE-LIST)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_method_code_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_method_code_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TRANSIENT-INTEGER-WRAPPER", "(DEFCLASS TRANSIENT-INTEGER-WRAPPER (INTEGER-WRAPPER TRANSIENT-MIXIN) :RECYCLE-METHOD :SWEEP-LIST)");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_transient_integer_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_transient_integer_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TRANSIENT-FLOAT-WRAPPER", "(DEFCLASS TRANSIENT-FLOAT-WRAPPER (FLOAT-WRAPPER TRANSIENT-MIXIN) :RECYCLE-METHOD :SWEEP-LIST)");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_transient_float_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_transient_float_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TRANSIENT-STRING-WRAPPER", "(DEFCLASS TRANSIENT-STRING-WRAPPER (STRING-WRAPPER TRANSIENT-MIXIN) :RECYCLE-METHOD :FREE-AND-SWEEP-LIST)");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_transient_string_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_transient_string_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TRANSIENT-CHARACTER-WRAPPER", "(DEFCLASS TRANSIENT-CHARACTER-WRAPPER (CHARACTER-WRAPPER TRANSIENT-MIXIN) :RECYCLE-METHOD :SWEEP-LIST)");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_transient_character_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_transient_character_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TRANSIENT-FUNCTION-CODE-WRAPPER", "(DEFCLASS TRANSIENT-FUNCTION-CODE-WRAPPER (FUNCTION-CODE-WRAPPER TRANSIENT-MIXIN) :RECYCLE-METHOD :SWEEP-LIST)");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_transient_function_code_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_transient_function_code_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("TRANSIENT-METHOD-CODE-WRAPPER", "(DEFCLASS TRANSIENT-METHOD-CODE-WRAPPER (METHOD-CODE-WRAPPER TRANSIENT-MIXIN) :RECYCLE-METHOD :SWEEP-LIST)");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_transient_method_code_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_transient_method_code_wrapper_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("VERBATIM-STRING-WRAPPER", "(DEFCLASS VERBATIM-STRING-WRAPPER (TRANSIENT-STRING-WRAPPER) :DOCUMENTATION \"Wrapper class used to hold verbatim native code strings.\" :RECYCLE-METHOD :SWEEP-LIST :PRINT-FORM (PRINT-NATIVE-STREAM STREAM (CHOOSE *PRINTREADABLY?* \"\" \"!V!\") (WRAPPER-VALUE SELF)))");

              oHARDWIRED_TRANSIENTp_ON_TRANSIENT_MIXINo = TRUE;
              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_verbatim_string_wrapper));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_verbatim_string_wrapper_slot_value));
            }
            define_class_from_stringified_source("BOOLEAN", "(DEFCLASS BOOLEAN (LITERAL) :DOCUMENTATION \"Boolean type with values TRUE, FALSE and NULL-BOOLEAN.\nStored by default using a single bit, thereby eliminating the value\nNULL-BOOLEAN.  Propagated within variables as an unsigned character.\" :INITIAL-VALUE FALSE :CL-NATIVE-TYPE \"FIXNUM\" :CPP-NATIVE-TYPE \"boolean\" :IDL-NATIVE-TYPE \"boolean\" :JAVA-NATIVE-TYPE \"boolean\")");
            define_class_from_stringified_source("FAT-BOOLEAN", "(DEFCLASS FAT-BOOLEAN (BOOLEAN) :DOCUMENTATION \"Boolean type stored in an unsigned character.  Values TRUE,\nFALSE, and NULL-BOOLEAN.  Slot read/write is faster than for the one-bit\nstorage, but it uses a lot more space.\" :CPP-NATIVE-TYPE \"fat_boolean\")");
            define_class_from_stringified_source("ONE-BIT-BOOLEAN", "(DEFCLASS ONE-BIT-BOOLEAN (BOOLEAN) :DOCUMENTATION \"Space-saving representation of Boolean.  Eliminates the\nvalue NULL-BOOLEAN and takes longer to read and write than FAT-BOOLEAN.\" :CPP-NATIVE-TYPE \"one_bit_boolean\")");
            define_class_from_stringified_source("CODE", "(DEFCLASS CODE (LITERAL) :ABSTRACT? TRUE)");
            define_class_from_stringified_source("FUNCTION-CODE", "(DEFCLASS FUNCTION-CODE (CODE) :CL-NATIVE-TYPE \"FUNCTION\" :JAVA-NATIVE-TYPE \"java_function_code\" :CPP-NATIVE-TYPE \"cpp_function_code\")");
            define_class_from_stringified_source("METHOD-CODE", "(DEFCLASS METHOD-CODE (CODE) :CL-NATIVE-TYPE \"STANDARD-GENERIC-FUNCTION\" :JAVA-NATIVE-TYPE \"java_method_code\" :CPP-NATIVE-TYPE \"cpp_method_code\" :INITIAL-VALUE (SAFE-CAST NULL @METHOD-CODE))");
            define_class_from_stringified_source("LISP-CODE", "(DEFCLASS LISP-CODE () :ABSTRACT? TRUE :DOCUMENTATION \"Used to indicate variables that input or output Common Lisp~\n      structures.\")");
            define_class_from_stringified_source("THIRTY-TWO-BIT-VECTOR", "(DEFCLASS THIRTY-TWO-BIT-VECTOR (INTEGER) :CL-NATIVE-TYPE \"FIXNUM\" :CPP-NATIVE-TYPE \"int\" :DOCUMENTATION \"Bit vector used to implement BOOLEAN slots.\" :INITIAL-VALUE NULL-INTEGER)");
            define_class_from_stringified_source("LISP-CLASS", "(DEFCLASS LISP-CLASS (LISP-CODE) :CL-NATIVE-TYPE \"CLASS\" :CPP-NATIVE-TYPE \"cpp_class*\")");
            define_class_from_stringified_source("LISP-CONS", "(DEFCLASS LISP-CONS (LISP-CODE) :PARAMETERS ((ANY-VALUE :TYPE OBJECT)) :CL-NATIVE-TYPE \"CONS\" :CPP-NATIVE-TYPE \"cpp_cons*\" :SYNONYMS (ARGUMENT-LIST))");
            define_class_from_stringified_source("LISP-NIL", "(DEFCLASS LISP-NIL (LISP-CONS) :CL-NATIVE-TYPE \"NULL\" :CPP-NATIVE-TYPE \"cpp_nil*\")");
            { Class* renamed_Class = define_class_from_stringified_source("LISP-CONS-ITERATOR", "(DEFCLASS LISP-CONS-ITERATOR (ITERATOR) :SLOTS ((CONS-ITERATOR-CURSOR :TYPE LISP-CONS)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_lisp_cons_iterator));
            }
            define_class_from_stringified_source("NATIVE-STREAM", "(DEFCLASS NATIVE-STREAM () :ABSTRACT? TRUE :CPP-NATIVE-TYPE \"ios*\" :CL-NATIVE-TYPE \"STREAM\")");
            define_class_from_stringified_source("NATIVE-OUTPUT-STREAM", "(DEFCLASS NATIVE-OUTPUT-STREAM (NATIVE-STREAM) :ABSTRACT? TRUE :CPP-NATIVE-TYPE \"ostream*\" :JAVA-NATIVE-TYPE \"PrintStream\" :CL-NATIVE-TYPE \"STREAM\")");
            define_class_from_stringified_source("NATIVE-INPUT-STREAM", "(DEFCLASS NATIVE-INPUT-STREAM (NATIVE-STREAM) :ABSTRACT? TRUE :CPP-NATIVE-TYPE \"istream*\" :CL-NATIVE-TYPE \"STREAM\")");
            { Class* renamed_Class = define_class_from_stringified_source("STREAM", "(DEFCLASS STREAM (STANDARD-OBJECT) :ABSTRACT? TRUE :SLOTS ((STATE :TYPE KEYWORD)))");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_stream_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("OUTPUT-STREAM", "(DEFCLASS OUTPUT-STREAM (STREAM) :SLOTS ((NATIVE-STREAM :TYPE NATIVE-OUTPUT-STREAM) (NATIVE-OUTPUT-STREAM :RENAMES NATIVE-STREAM)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_output_stream));
            }
            { Class* renamed_Class = define_class_from_stringified_source("INPUT-STREAM", "(DEFCLASS INPUT-STREAM (STREAM) :SLOTS ((NATIVE-STREAM :TYPE NATIVE-INPUT-STREAM) (NATIVE-INPUT-STREAM :RENAMES NATIVE-STREAM)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_input_stream));
            }
            { Class* renamed_Class = define_class_from_stringified_source("OUTPUT-FILE-STREAM", "(DEFCLASS OUTPUT-FILE-STREAM (OUTPUT-STREAM) :SLOTS ((FILENAME :TYPE STRING :REQUIRED? TRUE) (IF-EXISTS-ACTION :TYPE KEYWORD :INITIALLY :SUPERSEDE)) :INITIALIZER INITIALIZE-FILE-STREAM :TERMINATOR TERMINATE-FILE-STREAM? :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|OFS|'\" (FILENAME SELF) \"'\"))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_output_file_stream));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_output_file_stream_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("INPUT-FILE-STREAM", "(DEFCLASS INPUT-FILE-STREAM (INPUT-STREAM) :SLOTS ((FILENAME :TYPE STRING :REQUIRED? TRUE) (IF-NOT-EXISTS-ACTION :TYPE KEYWORD :INITIALLY :ERROR)) :INITIALIZER INITIALIZE-FILE-STREAM :TERMINATOR TERMINATE-FILE-STREAM? :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|IFS|'\" (FILENAME SELF) \"'\"))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_input_file_stream));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_input_file_stream_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("OUTPUT-STRING-STREAM", "(DEFCLASS OUTPUT-STRING-STREAM (OUTPUT-STREAM) :SLOTS ((THE-STRING :TYPE STRING :REQUIRED? TRUE)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_output_string_stream));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_output_string_stream_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("INPUT-STRING-STREAM", "(DEFCLASS INPUT-STRING-STREAM (INPUT-STREAM) :SLOTS ((THE-STRING :TYPE STRING :REQUIRED? TRUE)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_input_string_stream));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_input_string_stream_slot_value));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            define_method_from_stringified_source("STARTUP-HIERARCHY", NULL, "(DEFUN STARTUP-HIERARCHY ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          oCONTEXTo = old_OcontextO_001;
          oMODULEo = old_OmoduleO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oCONTEXTo = old_OcontextO_001;
        oMODULEo = old_OmoduleO_001;
        resignal();
      }
    }
  }
}

