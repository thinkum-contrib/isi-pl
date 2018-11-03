// walk.cc

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

List* oAVAILABLE_ENVIRONMENT_FEATURESo = NULL;

Keyword* KWD_WALK_WARN_ABOUT_UNDEFINED_METHODS = NULL;

Keyword* KWD_WALK_SUPPRESS_WARNINGS = NULL;

Keyword* KWD_WALK_USE_BOOTSTRAP_TRANSLATOR = NULL;

Keyword* KWD_WALK_WARN_ABOUT_MISSING_METHODS = NULL;

Keyword* KWD_WALK_USE_HARDCODED_SYMBOLS = NULL;

Keyword* KWD_WALK_USE_COMMON_LISP_STRUCTS = NULL;

Keyword* KWD_WALK_USE_COMMON_LISP_VECTOR_STRUCTS = NULL;

Keyword* KWD_WALK_USE_CPP_GARBAGE_COLLECTOR = NULL;

Keyword* KWD_WALK_TRANSLATE_WITH_COPYRIGHT_HEADER = NULL;

List* oCURRENT_ENVIRONMENT_FEATURESo = NULL;

List* oDEFAULT_ENVIRONMENT_FEATURESo = NULL;

List* oTRACED_KEYWORDSo = NULL;

Symbol* SYM_WALK_WHEN = NULL;

Symbol* SYM_WALK_AND = NULL;

Symbol* SYM_WALK_DEFINEDp = NULL;

Symbol* SYM_WALK_oTRACED_KEYWORDSo = NULL;

Symbol* SYM_WALK_MEMBERp = NULL;

Symbol* SYM_WALK_PRINT = NULL;

Symbol* SYM_WALK_TRACE_IF = NULL;

Symbol* SYM_WALK_TRACE_IF_EXPANDER = NULL;

Symbol* SYM_WALK_EVALUATOR_WRAPPER_CODE = NULL;

String_Hash_Table* oQUOTATION_TABLEo = NULL;

Translation_Unit* oRECYCLED_TRANSLATION_UNIT_So = NULL;

Symbol* SYM_WALK_THE_OBJECT = NULL;

Symbol* SYM_WALK_CATEGORY = NULL;

Symbol* SYM_WALK_ANNOTATION = NULL;

Symbol* SYM_WALK_AUXILIARYp = NULL;

Symbol* SYM_WALK_CODE_REGISTER = NULL;

Symbol* SYM_WALK_TRANSLATION = NULL;

Symbol* SYM_WALK_REFERENCED_GLOBALS = NULL;

Surrogate* SGT_WALK_TRANSLATION_UNIT = NULL;

Symbol* SYM_WALK_CLASS = NULL;

Symbol* SYM_WALK_METHOD = NULL;

Symbol* SYM_WALK_MACRO = NULL;

Symbol* SYM_WALK_GLOBAL_VARIABLE = NULL;

List* oTRANSLATIONUNITSo = NULL;

Symbol* SYM_WALK_oTRANSLATIONUNITSo = NULL;

Translation_Unit* oCURRENTTRANSLATIONUNITo = NULL;

Symbol* SYM_WALK_oCURRENTTRANSLATIONUNITo = NULL;

Keyword* oTRANSLATIONPHASEo = NULL;

Symbol* SYM_WALK_oTRANSLATIONPHASEo = NULL;

int oTRANSLATIONVERBOSITYLEVELo = 1;

Symbol* SYM_WALK_oTRANSLATIONVERBOSITYLEVELo = NULL;

boolean oUSEHARDCODEDSYMBOLSpo = FALSE;

Symbol* SYM_WALK_oUSEHARDCODEDSYMBOLSpo = NULL;

Keyword* KWD_WALK_REAL = NULL;

Keyword* KWD_WALK_BOOTSTRAP = NULL;

Keyword* KWD_WALK_COMMON_LISP = NULL;

Keyword* KWD_WALK_JAVA = NULL;

Keyword* KWD_WALK_CPP = NULL;

Symbol* SYM_WALK_PROGN = NULL;

Symbol* SYM_WALK_DEFCLASS = NULL;

Symbol* SYM_WALK_DEFSLOT = NULL;

Symbol* SYM_WALK_DEFMETHOD = NULL;

Symbol* SYM_WALK_DEFUN = NULL;

Symbol* SYM_WALK_DEFOPERATOR = NULL;

Symbol* SYM_WALK_DEFGLOBAL = NULL;

Symbol* SYM_WALK_DEFSPECIAL = NULL;

Symbol* SYM_WALK_DEFCONSTANT = NULL;

Symbol* SYM_WALK_DEFTYPE = NULL;

Symbol* SYM_WALK_DEFMODULE = NULL;

Symbol* SYM_WALK_DEFMACRO = NULL;

Symbol* SYM_WALK_STARTUP_TIME_PROGN = NULL;

Symbol* SYM_WALK_VERBATIM = NULL;

Symbol* SYM_WALK_MODULE = NULL;

Symbol* SYM_WALK_TYPE = NULL;

Symbol* SYM_WALK_PRINT_METHOD = NULL;

Symbol* SYM_WALK_SLOT = NULL;

Keyword* KWD_WALK_IDL = NULL;

Keyword* KWD_WALK_CPP_STANDALONE = NULL;

Key_Value_List* oLOCALVARIABLETYPETABLEo;

Symbol* SYM_WALK_oLOCALVARIABLETYPETABLEo = NULL;

Method_Slot* oMETHODBEINGWALKEDo = NULL;

Symbol* SYM_WALK_oMETHODBEINGWALKEDo = NULL;

boolean oFOUNDRETURNpo = FALSE;

Symbol* SYM_WALK_oFOUNDRETURNpo = NULL;

Standard_Object* oTARGETTYPEo = NULL;

Surrogate* SGT_WALK_VOID = NULL;

Symbol* SYM_WALK_oTARGETTYPEo = NULL;

Key_Value_List* oLOCALGENSYMTABLEo = NULL;

Symbol* SYM_WALK_oLOCALGENSYMTABLEo = NULL;

int oTRANSLATIONERRORSo = 0;

Symbol* SYM_WALK_oTRANSLATIONERRORSo = NULL;

int oTRANSLATIONWARNINGSo = 0;

Symbol* SYM_WALK_oTRANSLATIONWARNINGSo = NULL;

boolean oIGNORETRANSLATIONERRORSpo = TRUE;

Symbol* SYM_WALK_oIGNORETRANSLATIONERRORSpo = NULL;

Keyword* KWD_WALK_DEFINE = NULL;

Keyword* KWD_WALK_FINALIZE = NULL;

Keyword* KWD_WALK_WALK = NULL;

Keyword* KWD_WALK_TRANSLATE = NULL;

Surrogate* SGT_WALK_GLOBAL_VARIABLE = NULL;

Surrogate* SGT_WALK_TYPE_SPEC = NULL;

Surrogate* SGT_WALK_MODULE = NULL;

Surrogate* SGT_WALK_UNINITIALIZED = NULL;

Surrogate* SGT_WALK_UNKNOWN = NULL;

Symbol* SYM_WALK_NULL = NULL;

Symbol* SYM_WALK_ERROR = NULL;

Symbol* SYM_WALK_EOL = NULL;

Symbol* SYM_WALK_ILLEGAL_EXPRESSION_FLAGGED_BY_THE_TRANSLATOR = NULL;

Symbol* SYM_WALK_BAD_SYS = NULL;

Cons* oWRAPPED_TYPE_TABLEo = NULL;

Surrogate* SGT_WALK_INTEGER_WRAPPER = NULL;

Surrogate* SGT_WALK_INTEGER = NULL;

Surrogate* SGT_WALK_TRANSIENT_INTEGER_WRAPPER = NULL;

Surrogate* SGT_WALK_FLOAT_WRAPPER = NULL;

Surrogate* SGT_WALK_FLOAT = NULL;

Surrogate* SGT_WALK_TRANSIENT_FLOAT_WRAPPER = NULL;

Surrogate* SGT_WALK_NUMBER_WRAPPER = NULL;

Surrogate* SGT_WALK_NUMBER = NULL;

Surrogate* SGT_WALK_STRING_WRAPPER = NULL;

Surrogate* SGT_WALK_STRING = NULL;

Surrogate* SGT_WALK_TRANSIENT_STRING_WRAPPER = NULL;

Surrogate* SGT_WALK_CHARACTER_WRAPPER = NULL;

Surrogate* SGT_WALK_CHARACTER = NULL;

Surrogate* SGT_WALK_TRANSIENT_CHARACTER_WRAPPER = NULL;

Surrogate* SGT_WALK_BOOLEAN_WRAPPER = NULL;

Surrogate* SGT_WALK_BOOLEAN = NULL;

Surrogate* SGT_WALK_FUNCTION_CODE_WRAPPER = NULL;

Surrogate* SGT_WALK_FUNCTION_CODE = NULL;

Surrogate* SGT_WALK_TRANSIENT_FUNCTION_CODE_WRAPPER = NULL;

Surrogate* SGT_WALK_METHOD_CODE_WRAPPER = NULL;

Surrogate* SGT_WALK_METHOD_CODE = NULL;

Surrogate* SGT_WALK_TRANSIENT_METHOD_CODE_WRAPPER = NULL;

Surrogate* SGT_WALK_OBJECT = NULL;

Cons* oCOERSION_TABLEo = NULL;

Symbol* SYM_WALK_WRAP_BOOLEAN = NULL;

Symbol* SYM_WALK_WRAP_LITERAL = NULL;

Symbol* SYM_WALK_INTEGER_TO_BOOLEAN_WRAPPER = NULL;

Symbol* SYM_WALK_INTEGER_TO_BOOLEAN = NULL;

Surrogate* SGT_WALK_SYMBOL = NULL;

Symbol* SYM_WALK_INTERN_SYMBOL = NULL;

Symbol* SYM_WALK_SYMBOL_NAME = NULL;

Symbol* SYM_WALK_WRAPPER_VALUE = NULL;

Surrogate* SGT_WALK_SURROGATE = NULL;

Surrogate* SGT_WALK_CLASS = NULL;

Symbol* SYM_WALK_SURROGATE_VALUE = NULL;

Surrogate* SGT_WALK_INPUT_STREAM = NULL;

Surrogate* SGT_WALK_NATIVE_INPUT_STREAM = NULL;

Symbol* SYM_WALK_NATIVE_STREAM = NULL;

Surrogate* SGT_WALK_OUTPUT_STREAM = NULL;

Surrogate* SGT_WALK_NATIVE_OUTPUT_STREAM = NULL;

Symbol* SYM_WALK_IDENTITY = NULL;

Surrogate* SGT_WALK_SINGLE_FLOAT = NULL;

Surrogate* SGT_WALK_DOUBLE_FLOAT = NULL;

Surrogate* SGT_WALK_SHORT_INTEGER = NULL;

Surrogate* SGT_WALK_LONG_INTEGER = NULL;

Surrogate* SGT_WALK_UNSIGNED_SHORT_INTEGER = NULL;

Surrogate* SGT_WALK_UNSIGNED_LONG_INTEGER = NULL;

Symbol* SYM_WALK_VRLET = NULL;

Symbol* SYM_WALK_SYS_CALL_METHOD = NULL;

Symbol* SYM_WALK_SYS_CALL_FUNCTION = NULL;

Symbol* SYM_WALK_SAFE_CAST = NULL;

Symbol* SYM_WALK_CAST = NULL;

Surrogate* SGT_WALK_NON_OBJECT = NULL;

Surrogate* SGT_WALK_WRAPPER = NULL;

Symbol* SYM_WALK_LET = NULL;

Symbol* SYM_WALK_VOID_SYS = NULL;

Symbol* SYM_WALK_TYPED_SYS = NULL;

Symbol* SYM_WALK_SLOT_TYPE_SPECIFIER = NULL;

Surrogate* SGT_WALK_CONS = NULL;

Symbol* SYM_WALK_SYS_FOREACH = NULL;

Symbol* SYM_WALK_SETQ = NULL;

Symbol* SYM_WALK_SETF = NULL;

Symbol* SYM_WALK_SLOT_VALUE = NULL;

Symbol* SYM_WALK_SLOT_VALUE_SETTER = NULL;

Symbol* SYM_WALK_LOOP = NULL;

Symbol* SYM_WALK_VALUES = NULL;

Symbol* SYM_WALK_SPECIAL = NULL;

Symbol* SYM_WALK_SYS_SPECIAL = NULL;

Symbol* SYM_WALK_RETURN = NULL;

Symbol* SYM_WALK_MV_SETQ = NULL;

Symbol* SYM_WALK_MV_BIND = NULL;

Symbol* SYM_WALK_BREAK = NULL;

Symbol* SYM_WALK_CONTINUE = NULL;

Symbol* SYM_WALK_WHILE = NULL;

Symbol* SYM_WALK_FOREACH = NULL;

Symbol* SYM_WALK_EXISTS = NULL;

Symbol* SYM_WALK_FORALL = NULL;

Symbol* SYM_WALK_SOME = NULL;

Symbol* SYM_WALK_SETOF = NULL;

Symbol* SYM_WALK_SET_OF = NULL;

Symbol* SYM_WALK_SELECT = NULL;

Symbol* SYM_WALK_IF = NULL;

Symbol* SYM_WALK_UNLESS = NULL;

Symbol* SYM_WALK_CHOOSE = NULL;

Symbol* SYM_WALK_OR = NULL;

Symbol* SYM_WALK_NOT = NULL;

Symbol* SYM_WALK_COND = NULL;

Symbol* SYM_WALK_CASE = NULL;

Symbol* SYM_WALK_TYPECASE = NULL;

Symbol* SYM_WALK_EQp = NULL;

Symbol* SYM_WALK_EQLp = NULL;

Symbol* SYM_WALK_e = NULL;

Symbol* SYM_WALK_i = NULL;

Symbol* SYM_WALK__ = NULL;

Symbol* SYM_WALK_o = NULL;

Symbol* SYM_WALK_s = NULL;

Symbol* SYM_WALK_QUOTE = NULL;

Symbol* SYM_WALK_BQUOTE = NULL;

Symbol* SYM_WALK_PRINT_STREAM = NULL;

Symbol* SYM_WALK_PRINT_NATIVE_STREAM = NULL;

Symbol* SYM_WALK_NEW = NULL;

Symbol* SYM_WALK_ALLOCATE = NULL;

Symbol* SYM_WALK_LOCAL_NEW = NULL;

Symbol* SYM_WALK_MAKE = NULL;

Symbol* SYM_WALK_FUNCALL = NULL;

Symbol* SYM_WALK_SYS_CALL_FUNCTION_CODE = NULL;

Symbol* SYM_WALK_SYS_CALL_METHOD_CODE = NULL;

Symbol* SYM_WALK_THE_CODE = NULL;

Symbol* SYM_WALK_EXCEPTION_CASE = NULL;

Symbol* SYM_WALK_INLINE = NULL;

Symbol* SYM_WALK_SYS_SLOT_VALUE = NULL;

Symbol* SYM_WALK_SYS_SLOT_VALUE_SETTER = NULL;

Symbol* SYM_WALK_SYS_CALL_METHOD_SETTER = NULL;

Symbol* SYM_WALK_SYS_NEW = NULL;

Hash_Table* oSYMBOL_REGISTRYo = NULL;

List* oSYMBOL_SETo = NULL;

char* oCURRENTFILEo = NULL;

Symbol* SYM_WALK_oCURRENTFILEo = NULL;

Keyword* KWD_WALK_SYMBOLS = NULL;

Symbol* SYM_WALK_INTERN_RIGID_SYMBOL_WRT_MODULE = NULL;

Symbol* SYM_WALK_GET_MODULE = NULL;

Symbol* SYM_WALK_TRUE = NULL;

Symbol* SYM_WALK_INTERN_SYMBOL_AT = NULL;

Symbol* SYM_WALK_INTERN_SURROGATE_AT = NULL;

Symbol* SYM_WALK_INTERN_KEYWORD_AT = NULL;

Symbol* SYM_WALK_FALSE = NULL;

Symbol* SYM_WALK_NIL = NULL;

Symbol* SYM_WALK_NULL_BOOLEAN = NULL;

Symbol* SYM_WALK_NULL_INTEGER = NULL;

Symbol* SYM_WALK_NULL_FLOAT = NULL;

Surrogate* SGT_WALK_KEYWORD = NULL;

Keyword* KWD_WALK_PLACE_WHERE_VRLET_WAS = NULL;

Keyword* KWD_WALK_PLACE_WHERE_LAST_EXPRESSION_WAS = NULL;

Keyword* KWD_WALK_DYNAMIC = NULL;

Symbol* SYM_WALK_IT = NULL;

Symbol* SYM_WALK_ON = NULL;

Symbol* SYM_WALK_DYNAMIC_SLOTS = NULL;

Symbol* SYM_WALK_WHERE = NULL;

Symbol* SYM_WALK_KEY = NULL;

Symbol* SYM_WALK_DO = NULL;

Symbol* SYM_WALK_WRAPPEDVALUE = NULL;

Symbol* SYM_WALK_VALUE = NULL;

Keyword* KWD_WALK_BIT = NULL;

Symbol* SYM_WALK_DYNAMICSLOTS = NULL;

Symbol* SYM_WALK_NEWVALUE = NULL;

Symbol* SYM_WALK_FOUNDMATCHINGENTRYp = NULL;

Symbol* SYM_WALK_THE_KV_LIST = NULL;

Symbol* SYM_WALK_KV_CONS = NULL;

Symbol* SYM_WALK_OLDVALUE = NULL;

Keyword* KWD_WALK_CONTEXT_SENSITIVEp = NULL;

Keyword* KWD_WALK_DONT_INHERITp = NULL;

Symbol* SYM_WALK_ACCESS_IN_CONTEXT = NULL;

Keyword* KWD_WALK_COPY_TO_CHILDRENp = NULL;

Symbol* SYM_WALK_UPDATE_IN_CONTEXT = NULL;

Symbol* SYM_WALK_CS_VALUEp = NULL;

Symbol* SYM_WALK_VARIABLE_DECLARATION = NULL;

Symbol* SYM_WALK_ILLEGAL_VARIABLE = NULL;

Key_Value_List* oSPECIALVARIABLESTACKo = NULL;

Symbol* SYM_WALK_oSPECIALVARIABLESTACKo = NULL;

boolean oSPECIALSENABLEDpo = TRUE;

Symbol* SYM_WALK_oSPECIALSENABLEDpo = NULL;

int oNOFSPECIALSATLOOPENTRYo = 0;

Symbol* SYM_WALK_oNOFSPECIALSATLOOPENTRYo = NULL;

Keyword* KWD_WALK_SAVE_AND_RESTORE = NULL;

Symbol* SYM_WALK_EXCEPTION = NULL;

Symbol* SYM_WALK_RESIGNAL = NULL;

Surrogate* SGT_WALK_METHOD_SLOT = NULL;

Symbol* SYM_WALK_OTHERWISE = NULL;

Symbol* SYM_WALK_SYMBOL_ID = NULL;

Symbol* SYM_WALK_GENERALIZED_SYMBOL = NULL;

Cons* oTYPE_PREDICATE_TABLEo = NULL;

Symbol* SYM_WALK_BOOLEANp = NULL;

Symbol* SYM_WALK_INTEGERp = NULL;

Symbol* SYM_WALK_FLOATp = NULL;

Symbol* SYM_WALK_STRINGp = NULL;

Symbol* SYM_WALK_CHARACTERp = NULL;

Symbol* SYM_WALK_WRAPPERp = NULL;

Surrogate* SGT_WALK_VERBATIM_STRING_WRAPPER = NULL;

Symbol* SYM_WALK_VERBATIM_STRINGp = NULL;

Symbol* SYM_WALK_SURROGATEp = NULL;

Surrogate* SGT_WALK_TYPE = NULL;

Symbol* SYM_WALK_TYPEp = NULL;

Symbol* SYM_WALK_SYMBOLp = NULL;

Surrogate* SGT_WALK_TRANSIENT_SYMBOL = NULL;

Symbol* SYM_WALK_TRANSIENT_SYMBOLp = NULL;

Symbol* SYM_WALK_KEYWORDp = NULL;

Symbol* SYM_WALK_CONSp = NULL;

Symbol* SYM_WALK_CLASSp = NULL;

Surrogate* SGT_WALK_STORAGE_SLOT = NULL;

Symbol* SYM_WALK_STORAGE_SLOTp = NULL;

Symbol* SYM_WALK_METHOD_SLOTp = NULL;

Surrogate* SGT_WALK_ANCHORED_TYPE_SPECIFIER = NULL;

Symbol* SYM_WALK_ANCHORED_TYPE_SPECIFIERp = NULL;

Surrogate* SGT_WALK_PARAMETRIC_TYPE_SPECIFIER = NULL;

Symbol* SYM_WALK_PARAMETRIC_TYPE_SPECIFIERp = NULL;

Symbol* SYM_WALK_ISAp = NULL;

Symbol* SYM_WALK_TAXONOMY_ISAp = NULL;

Symbol* SYM_WALK_STRING_EQLp = NULL;

Surrogate* SGT_WALK_STANDARD_OBJECT = NULL;

Surrogate* SGT_WALK_LITERAL = NULL;

Symbol* SYM_WALK_EQL_TO_BOOLEANp = NULL;

Symbol* SYM_WALK_EQL_TO_INTEGERp = NULL;

Symbol* SYM_WALK_EQL_TO_FLOATp = NULL;

Symbol* SYM_WALK_EQL_TO_STRINGp = NULL;

List* oNUMERIC_TYPE_HIERARCHYo = NULL;

Symbol* SYM_WALK_GET_QUOTED_TREE = NULL;

Keyword* KWD_WALK_WARN = NULL;

Keyword* KWD_WALK_ERROR = NULL;

Keyword* KWD_WALK_CONTINUABLE_ERROR = NULL;

Symbol* SYM_WALK_CONS = NULL;

Symbol* SYM_WALK_CONS_LIST = NULL;

Symbol* SYM_WALK_GET_SYM = NULL;

Symbol* SYM_WALK_GET_SGT = NULL;

Symbol* SYM_WALK_GET_KWD = NULL;

Surrogate* SGT_WALK_ARGUMENT_LIST = NULL;

Symbol* SYM_WALK_ANY_VALUE = NULL;

Symbol* SYM_WALK_METHOD_INHERITS_THROUGH = NULL;

Keyword* KWD_WALK_FUNCTION = NULL;

Symbol* SYM_WALK_SLOT_WRITER = NULL;

Symbol* SYM_WALK_LOOKUP_SLOT = NULL;

Symbol* SYM_WALK_TYPE_CLASS = NULL;

Symbol* SYM_WALK_STORAGE_SLOT = NULL;

Keyword* KWD_WALK_METHODS = NULL;

Symbol* SYM_WALK_FUNCTION_CODE = NULL;

Symbol* SYM_WALK_METHOD_CODE = NULL;

Keyword* KWD_WALK_METHOD = NULL;

Keyword* KWD_WALK_CLASS = NULL;

Keyword* KWD_WALK_EMBEDDED = NULL;

Symbol* SYM_WALK_CLASS_CONSTRUCTOR_CODE = NULL;

Symbol* SYM_WALK_SLOT_ACCESSOR_METHODS = NULL;

Symbol* SYM_WALK_PRINT_FORM = NULL;

Symbol* SYM_WALK_PRINT_OBJECT = NULL;

Symbol* SYM_WALK_SELF = NULL;

Symbol* SYM_WALK_STREAM = NULL;

Symbol* SYM_WALK_NATIVE_OUTPUT_STREAM = NULL;

Keyword* KWD_WALK_CLASSES = NULL;

Keyword* KWD_WALK_FINALIZE_CLASSES = NULL;

Symbol* SYM_WALK_FINALIZE_CLASSES = NULL;

Keyword* KWD_WALK_FINALIZE_METHODS = NULL;

Symbol* SYM_WALK_FINALIZE_SLOTS = NULL;

Symbol* SYM_WALK_CLEANUP_UNFINALIZED_CLASSES = NULL;

Symbol* SYM_WALK_DEFINE_EXTERNAL_SLOT_FROM_STRINGIFIED_SOURCE = NULL;

Hash_Table* oMACRO_TABLEo = NULL;

Symbol* SYM_WALK_OBJECT = NULL;

Symbol* SYM_WALK_METHOD_LISP_MACROp = NULL;

Symbol* SYM_WALK_STORE_MACRO = NULL;

Keyword* KWD_WALK_UNBOUND_SPECIAL_VARIABLE = NULL;

Keyword* KWD_WALK_GLOBALS = NULL;

Symbol* SYM_WALK_VARIABLE_TYPE_SPECIFIER = NULL;

Symbol* SYM_WALK_DEFINE_STELLA_GLOBAL_VARIABLE_FROM_STRINGIFIED_SOURCE = NULL;

Symbol* SYM_WALK_GLOBAL = NULL;

Symbol* SYM_WALK_LOOKUP_GLOBAL_VARIABLE = NULL;

Symbol* SYM_WALK_VARIABLE_GET_VALUE_CODE = NULL;

Symbol* SYM_WALK_VARIABLE_SET_VALUE_CODE = NULL;

Symbol* SYM_WALK_DEFINE_STELLA_TYPE_FROM_STRINGIFIED_SOURCE = NULL;

Keyword* KWD_WALK_FINAL = NULL;

Symbol* SYM_WALK_CURRENT_STARTUP_TIME_PHASEp = NULL;

Keyword* KWD_WALK_MODULES = NULL;

Symbol* SYM_WALK_WITHIN_MODULE = NULL;

Symbol* SYM_WALK_oSTELLA_MODULEo = NULL;

Keyword* KWD_WALK_AUXILIARYp = NULL;

jump_buffer oEXCEPTIONHANDLERADDRESSo = NULL;

boolean oPENDINGEXCEPTIONHANDLERpo = FALSE;

Symbol* SYM_WALK_oPENDINGEXCEPTIONHANDLERpo = NULL;

Exception* oEXCEPTIONo = NULL;

Surrogate* oEXCEPTION_TYPEo = NULL;

Symbol* SYM_WALK_oEXCEPTIONHANDLERADDRESSo = NULL;

Symbol* SYM_WALK_oEXCEPTIONo = NULL;

Symbol* SYM_WALK_SETUP_LONG_JUMPp = NULL;

Surrogate* SGT_WALK_EXCEPTION = NULL;

Symbol* SYM_WALK_SUBTYPE_OFp = NULL;

Symbol* SYM_WALK_oEXCEPTION_TYPEo = NULL;

Keyword* KWD_WALK_OTHERWISE = NULL;

Surrogate* SGT_WALK_CODE = NULL;

Symbol* SYM_WALK_MAIN = NULL;

Surrogate* SGT_WALK_COMPOUND_TYPE_SPECIFIER = NULL;

Hash_Table* oNATIVE_NAME_TABLEo = NULL;

Symbol* SYM_WALK_DOCUMENTATION = NULL;

Symbol* SYM_WALK_EXPRESSION = NULL;

Symbol* SYM_WALK_IGNORE = NULL;

Symbol* SYM_WALK_INCREMENTALLY_TRANSLATE = NULL;

Symbol* SYM_WALK_REGISTER_NATIVE_NAME = NULL;

Symbol* SYM_WALK_REST = NULL;

Symbol* SYM_WALK_NTH_REST = NULL;

Symbol* SYM_WALK_NTH = NULL;

Symbol* SYM_WALK_ARGUMENTS = NULL;

Symbol* SYM_WALK_RESULT = NULL;

Symbol* SYM_WALK_METHOD_EVALUATE_ARGUMENTSp = NULL;

Symbol* SYM_WALK_METHOD_VARIABLE_ARGUMENTSp = NULL;

boolean oEVALUATIONERRORpo = FALSE;

Symbol* SYM_WALK_oEVALUATIONERRORpo = NULL;

Object* oEVALUATIONTREEo = NULL;

Symbol* SYM_WALK_oEVALUATIONTREEo = NULL;

Object* oEVALUATIONPARENTTREEo = NULL;

Symbol* SYM_WALK_oEVALUATIONPARENTTREEo = NULL;

void display_environment_features() {
  // Print a list of the currently enabled environment 
  // features and print a list of all Stella environment features.
  cout << "CURRENTLY ENABLED ENVIRONMENT FEATURES:" << endl << "   " << oCURRENT_ENVIRONMENT_FEATURESo << endl << endl << "AVAILABLE ENVIRONMENT FEATURES:" << endl << "   " << oAVAILABLE_ENVIRONMENT_FEATURESo << endl;
}

void enable_environment_feature(int features, ...) {
  // Enable the environment feature(s) indicated by the
  // keywords in 'features'.
  { va_list ap;
    Keyword* f;

    va_start(ap, features);
    while (features > 0) {
      f = va_arg(ap, Keyword*);
      features = features - 1;
      if ((f == KWD_WALK_SUPPRESS_WARNINGS) ||
          ((f == KWD_WALK_WARN_ABOUT_UNDEFINED_METHODS) ||
           ((f == KWD_WALK_USE_BOOTSTRAP_TRANSLATOR) ||
            ((f == KWD_WALK_WARN_ABOUT_MISSING_METHODS) ||
             ((f == KWD_WALK_USE_HARDCODED_SYMBOLS) ||
              ((f == KWD_WALK_USE_COMMON_LISP_STRUCTS) ||
               ((f == KWD_WALK_USE_COMMON_LISP_VECTOR_STRUCTS) ||
                ((f == KWD_WALK_USE_CPP_GARBAGE_COLLECTOR) ||
                 (f == KWD_WALK_TRANSLATE_WITH_COPYRIGHT_HEADER))))))))) {
        if (!(oCURRENT_ENVIRONMENT_FEATURESo->memberP(f))) {
          oCURRENT_ENVIRONMENT_FEATURESo->insert(f);
        }
      }
      else {
        if (oAVAILABLE_ENVIRONMENT_FEATURESo->memberP(f)) {
          cerr << "Oops. Forgot to implement environment feature:  " << "`" << f << "'";
        }
        else {
          cerr << "Unrecognizable environment feature:  " << "`" << f << "'";
        }
      }
      if (f == KWD_WALK_USE_COMMON_LISP_STRUCTS) {
        oCURRENT_ENVIRONMENT_FEATURESo->remove(KWD_WALK_USE_COMMON_LISP_VECTOR_STRUCTS);
        oCL_TRANSLATED_FILE_SUFFIXo = ".slisp";
      }
      else if (f == KWD_WALK_USE_COMMON_LISP_VECTOR_STRUCTS) {
        if (!(oCURRENT_ENVIRONMENT_FEATURESo->memberP(KWD_WALK_USE_COMMON_LISP_STRUCTS))) {
          oCURRENT_ENVIRONMENT_FEATURESo->insert(KWD_WALK_USE_COMMON_LISP_STRUCTS);
        }
        oCL_TRANSLATED_FILE_SUFFIXo = ".vslisp";
      }
      else {
      }
    }
    va_end(ap);
  }
}

void disable_environment_feature(int features, ...) {
  // Disable the environment feature(s) indicated by the
  // keywords in 'features'.
  { va_list ap;
    Keyword* f;

    va_start(ap, features);
    while (features > 0) {
      f = va_arg(ap, Keyword*);
      features = features - 1;
      if ((f == KWD_WALK_SUPPRESS_WARNINGS) ||
          ((f == KWD_WALK_WARN_ABOUT_UNDEFINED_METHODS) ||
           ((f == KWD_WALK_USE_BOOTSTRAP_TRANSLATOR) ||
            ((f == KWD_WALK_WARN_ABOUT_MISSING_METHODS) ||
             ((f == KWD_WALK_USE_HARDCODED_SYMBOLS) ||
              ((f == KWD_WALK_USE_COMMON_LISP_STRUCTS) ||
               ((f == KWD_WALK_USE_COMMON_LISP_VECTOR_STRUCTS) ||
                ((f == KWD_WALK_USE_CPP_GARBAGE_COLLECTOR) ||
                 (f == KWD_WALK_TRANSLATE_WITH_COPYRIGHT_HEADER))))))))) {
        oCURRENT_ENVIRONMENT_FEATURESo->remove(f);
      }
      else {
        if (oAVAILABLE_ENVIRONMENT_FEATURESo->memberP(f)) {
          cerr << "Oops. Forgot to implement environment feature:  " << "`" << f << "'";
        }
        else {
          cerr << "Unrecognizable environment feature:  " << "`" << f << "'";
        }
      }
      if ((f == KWD_WALK_USE_COMMON_LISP_STRUCTS) ||
          (f == KWD_WALK_USE_COMMON_LISP_VECTOR_STRUCTS)) {
        oCURRENT_ENVIRONMENT_FEATURESo->remove(KWD_WALK_USE_COMMON_LISP_STRUCTS);
        oCURRENT_ENVIRONMENT_FEATURESo->remove(KWD_WALK_USE_COMMON_LISP_VECTOR_STRUCTS);
        oCL_TRANSLATED_FILE_SUFFIXo = ".lisp";
      }
      else {
      }
    }
    va_end(ap);
  }
}

void reset_environment_features() {
  // Reset the current environment features to their default
  // settings.
  { Keyword* f = NULL;
    Cons* iter_001 = oCURRENT_ENVIRONMENT_FEATURESo->the_cons_list;

    while (!nilP(iter_001)) {
      {
        f = ((Keyword*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (!oDEFAULT_ENVIRONMENT_FEATURESo->memberP(f)) {
        disable_environment_feature(1, f);
      }
    }
  }
  { Keyword* f = NULL;
    Cons* iter_002 = oDEFAULT_ENVIRONMENT_FEATURESo->the_cons_list;

    while (!nilP(iter_002)) {
      {
        f = ((Keyword*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      if (!oCURRENT_ENVIRONMENT_FEATURESo->memberP(f)) {
        enable_environment_feature(1, f);
      }
    }
  }
}

Object* trace_if_expander(Keyword* keyword, Cons* body) {
  return (listO(4, SYM_WALK_WHEN, listO(4, SYM_WALK_AND, listO(3, SYM_WALK_DEFINEDp, SYM_WALK_oTRACED_KEYWORDSo, NIL), listO(4, SYM_WALK_MEMBERp, SYM_WALK_oTRACED_KEYWORDSo, keyword, NIL), NIL), cons(SYM_WALK_PRINT, copy_cons_list(body)->concatenate(NIL)), NIL));
}

boolean trace_keywordP(Keyword* keyword) {
  return ((oTRACED_KEYWORDSo != NULL) &&
      oTRACED_KEYWORDSo->memberP(keyword));
}

List* add_trace(Cons* keywords) {
  // Enable trace messages identified by any of the listed `keywords'.  After
  // calling `(add-trace <keyword>)' code guarded by `(trace-if <keyword> ...)'
  // will be executed when it is encountered.
  if (oTRACED_KEYWORDSo == NULL) {
    oTRACED_KEYWORDSo = list(0);
  }
  { Generalized_Symbol* k = NULL;
    Cons* iter_001 = keywords;

    while (!nilP(iter_001)) {
      {
        k = ((Generalized_Symbol*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      oTRACED_KEYWORDSo->insert_new(string_keywordify(k->symbol_name));
    }
  }
  return (oTRACED_KEYWORDSo);
}

List* add_trace_evaluator_wrapper(Cons* arguments) {
  return (add_trace(((Cons*)(arguments))));
}

List* drop_trace(Cons* keywords) {
  // Disable trace messages identified by any of the listed `keywords'.  After
  // calling `(drop-trace <keyword>)' code guarded by `(trace-if <keyword> ...)'
  // will not be executed when it is encountered.
  if (oTRACED_KEYWORDSo != NULL) {
    { Generalized_Symbol* k = NULL;
      Cons* iter_001 = keywords;

      while (!nilP(iter_001)) {
        {
          k = ((Generalized_Symbol*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        oTRACED_KEYWORDSo->remove(string_keywordify(k->symbol_name));
      }
    }
    if (oTRACED_KEYWORDSo->emptyP()) {
      oTRACED_KEYWORDSo = NULL;
    }
  }
  return (oTRACED_KEYWORDSo);
}

List* drop_trace_evaluator_wrapper(Cons* arguments) {
  return (drop_trace(((Cons*)(arguments))));
}

void clear_trace() {
  // Disable all tracing previously enabled with `add-trace'.
  oTRACED_KEYWORDSo->clear();
}

char* name_quoted_tree(Cons* tree) {
  { Cons* nametree = cons(tree, cons(string_wrap_literal(oMODULEo->module_full_name), NIL));
    char* name = stringify(nametree);

    free_cons_list(nametree);
    return (name);
  }
}

Cons* get_quoted_tree(char* treename, char* modulename) {
  // Return the quoted tree with name 'treeName'.
  { Cons* quotedtree = ((Cons*)(oQUOTATION_TABLEo->lookup(treename)));

    if (quotedtree != NULL) {
      return (quotedtree);
    }
    { Module* old_OmoduleO_001 = oMODULEo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oMODULEo = string_get_module(modulename, TRUE);
            { Cons* tree = ((Cons*)(unstringify(treename)));

              quotedtree = ((Cons*)(permanentify_form(tree->first())));
              tree->free_parse_tree();
              oQUOTATION_TABLEo->insert_at(treename, quotedtree);
              { 
                oMODULEo = old_OmoduleO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (quotedtree);
              }
            }
            oMODULEo = old_OmoduleO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oMODULEo = old_OmoduleO_001;
          resignal();
        }
      }
    }
  }
}

Translation_Unit* new_translation_unit() {
  { Translation_Unit* self = NULL;

    self = oRECYCLED_TRANSLATION_UNIT_So;
    if (self != NULL) {
      oRECYCLED_TRANSLATION_UNIT_So = ((Translation_Unit*)(self->translation));
    }
    else {
      self = new Translation_Unit;
    }
    self->referenced_globals = new_list();
    self->translation = NULL;
    self->code_register = NULL;
    self->auxiliaryP = FALSE;
    self->annotation = NULL;
    self->category = NULL;
    self->the_object = NULL;
    return (self);
  }
}

void Translation_Unit::free() {
  { Translation_Unit* self = this;

    if (self->referenced_globals != NULL) {
      self->referenced_globals->free();
    }
    if (!(terminate_translation_unitP(self))) {
      return;
    }
    self->translation = oRECYCLED_TRANSLATION_UNIT_So;
    oRECYCLED_TRANSLATION_UNIT_So = self;
  }
}

Object* access_translation_unit_slot_value(Translation_Unit* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_WALK_THE_OBJECT) {
    if (setvalueP) {
      self->the_object = value;
    }
    else {
      return (self->the_object);
    }
  }
  else if (slotname == SYM_WALK_CATEGORY) {
    if (setvalueP) {
      self->category = ((Symbol*)(value));
    }
    else {
      return (self->category);
    }
  }
  else if (slotname == SYM_WALK_ANNOTATION) {
    if (setvalueP) {
      self->annotation = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->annotation));
    }
  }
  else if (slotname == SYM_WALK_AUXILIARYp) {
    if (setvalueP) {
      self->auxiliaryP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->auxiliaryP));
    }
  }
  else if (slotname == SYM_WALK_CODE_REGISTER) {
    if (setvalueP) {
      self->code_register = value;
    }
    else {
      return (self->code_register);
    }
  }
  else if (slotname == SYM_WALK_TRANSLATION) {
    if (setvalueP) {
      self->translation = value;
    }
    else {
      return (self->translation);
    }
  }
  else if (slotname == SYM_WALK_REFERENCED_GLOBALS) {
    if (setvalueP) {
      self->referenced_globals = ((List*)(value));
    }
    else {
      return (self->referenced_globals);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Translation_Unit::primary_type() {
  { Translation_Unit* self = this;

    return (SGT_WALK_TRANSLATION_UNIT);
  }
}

void Translation_Unit::print_object(ostream* stream) {
  { Translation_Unit* self = this;

    print_translation_unit(self, stream);
  }
}

boolean terminate_translation_unitP(Translation_Unit* self) {
  { Object* translation = self->translation;

    if (translation != NULL) {
      translation->free_parse_tree();
    }
  }
  return (TRUE);
}

void print_translation_unit(Translation_Unit* self, ostream* stream) {
  *(stream) << "|TU|[" << self->category;
  { Symbol* test_value_001 = self->category;

    if ((test_value_001 == SYM_WALK_CLASS) ||
        ((test_value_001 == SYM_WALK_METHOD) ||
         ((test_value_001 == SYM_WALK_MACRO) ||
          (test_value_001 == SYM_WALK_GLOBAL_VARIABLE)))) {
      *(stream) << " " << self->the_object;
    }
    else {
    }
  }
  *(stream) << "]";
}

List* read_OtranslationunitsO() {
  return (oTRANSLATIONUNITSo);
}

List* write_OtranslationunitsO(List* value) {
  oTRANSLATIONUNITSo = value;
  return (value);
}

Translation_Unit* read_OcurrenttranslationunitO() {
  return (oCURRENTTRANSLATIONUNITo);
}

Translation_Unit* write_OcurrenttranslationunitO(Translation_Unit* value) {
  oCURRENTTRANSLATIONUNITo = value;
  return (value);
}

Keyword* read_OtranslationphaseO() {
  return (oTRANSLATIONPHASEo);
}

Keyword* write_OtranslationphaseO(Keyword* value) {
  oTRANSLATIONPHASEo = value;
  return (value);
}

int read_OtranslationverbositylevelO() {
  return (oTRANSLATIONVERBOSITYLEVELo);
}

int write_OtranslationverbositylevelO(int value) {
  oTRANSLATIONVERBOSITYLEVELo = value;
  return (value);
}

boolean read_OusehardcodedsymbolsPO() {
  return (oUSEHARDCODEDSYMBOLSpo);
}

boolean write_OusehardcodedsymbolsPO(boolean value) {
  oUSEHARDCODEDSYMBOLSpo = value;
  return (value);
}

boolean use_hardcoded_symbolsP() {
  return (oCURRENT_ENVIRONMENT_FEATURESo->memberP(KWD_WALK_USE_HARDCODED_SYMBOLS) ||
      oUSEHARDCODEDSYMBOLSpo);
}

boolean use_bootstrap_translatorP() {
  return (oCURRENT_ENVIRONMENT_FEATURESo->memberP(KWD_WALK_USE_BOOTSTRAP_TRANSLATOR));
}

Keyword* toggle_translators() {
  // Switch between the bootstrap and real translators.
  if (use_bootstrap_translatorP()) {
    {
      disable_environment_feature(1, KWD_WALK_USE_BOOTSTRAP_TRANSLATOR);
      return (KWD_WALK_REAL);
    }
  }
  else {
    {
      enable_environment_feature(1, KWD_WALK_USE_BOOTSTRAP_TRANSLATOR);
      return (KWD_WALK_BOOTSTRAP);
    }
  }
}

boolean translate_to_common_lispP() {
  // Return TRUE if current output language is Common-Lisp.
  return (oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_WALK_COMMON_LISP);
}

boolean translate_to_single_inheritance_languageP() {
  return ((oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_WALK_JAVA) ||
      ((oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_WALK_COMMON_LISP) &&
       oCURRENT_ENVIRONMENT_FEATURESo->memberP(KWD_WALK_USE_COMMON_LISP_STRUCTS)));
}

Keyword* toggle_output_language() {
  // Switch between Common Lisp and C++ as output languages.
  if (translate_to_common_lispP()) {
    {
      oTRANSLATOR_OUTPUT_LANGUAGEo = KWD_WALK_CPP;
      return (KWD_WALK_CPP);
    }
  }
  else {
    {
      oTRANSLATOR_OUTPUT_LANGUAGEo = KWD_WALK_COMMON_LISP;
      return (KWD_WALK_COMMON_LISP);
    }
  }
}

boolean declaration_operatorP(Symbol* renamed_Operator) {
  return (get_quoted_tree("((DEFCLASS DEFSLOT DEFMETHOD DEFUN DEFTYPE DEFGLOBAL DEFSPECIAL DEFCONSTANT DEFMACRO DEFMODULE STARTUP-TIME-PROGN) \"/STELLA\")", "/STELLA")->memberP(renamed_Operator));
}

boolean declaration_treeP(Cons* tree) {
  { Object* renamed_Operator = tree->value;

    if (declaration_operatorP(((Symbol*)(renamed_Operator)))) {
      return (TRUE);
    }
    if (renamed_Operator == SYM_WALK_PROGN) {
      { boolean foundP_001 = FALSE;

        { Object* subtree = NULL;
          Cons* iter_001 = tree->rest;

          while (!nilP(iter_001)) {
            {
              subtree = iter_001->value;
              iter_001 = iter_001->rest;
            }
            if (consP(subtree) &&
                declaration_treeP(((Cons*)(subtree)))) {
              foundP_001 = TRUE;
              break;
            }
          }
        }
        { boolean value_001 = foundP_001;

          return (value_001);
        }
      }
    }
    if (lookup_macro(((Symbol*)(renamed_Operator))) != NULL) {
      { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oTRANSIENTOBJECTSpo = TRUE;
              { Object* expansion = expand_macro(copy_cons_list(tree));

                if (expansion != NULL) {
                  { Object* expansion_001 = expansion;

                    if (consP(expansion)) {
                      { Cons* expansion = NULL;

                        expansion = ((Cons*)(expansion_001));
                        tree->value = expansion->value;
                        tree->rest = expansion->rest;
                        { boolean return_value_001 = declaration_treeP(tree);

                          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                          return (return_value_001);
                        }
                      }
                    }
                    else {
                      { 
                        oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                        return (FALSE);
                      }
                    }
                  }
                }
                else {
                  tree->value = SYM_WALK_PROGN;
                  tree->rest = NIL;
                  { 
                    oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                    return (FALSE);
                  }
                }
              }
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
            resignal();
          }
        }
      }
    }
    return (FALSE);
  }
}

char* create_annotation(Cons* top_level_tree) {
  return (string_concatenate("(", string_concatenate(((Symbol*)(top_level_tree->first()))->symbol_name, string_concatenate(" ", string_concatenate(stringify(top_level_tree->second()), " ...)")))));
}

void walk_top_level_tree(Cons* tree, boolean createannotationP) {
  { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTRANSIENTOBJECTSpo = TRUE;
          { Translation_Unit* old_OcurrenttranslationunitO_001 = oCURRENTTRANSLATIONUNITo;

            { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oCURRENTTRANSLATIONUNITo = NULL;
                  { char* annotation = NULL;

                    if (createannotationP) {
                      annotation = create_annotation(tree);
                      if (oTRANSLATIONVERBOSITYLEVELo >= 2) {
                        cout << "Defining " << "`" << annotation << "'" << endl;
                      }
                    }
                    { Object* test_value_001 = tree->first();

                      if (test_value_001 == SYM_WALK_DEFCLASS) {
                        walk_defclass_tree(tree);
                      }
                      else if (test_value_001 == SYM_WALK_DEFSLOT) {
                        walk_defslot_tree(tree);
                      }
                      else if ((test_value_001 == SYM_WALK_DEFMETHOD) ||
                          ((test_value_001 == SYM_WALK_DEFUN) ||
                           (test_value_001 == SYM_WALK_DEFOPERATOR))) {
                        if (tree->first() == SYM_WALK_DEFOPERATOR) {
                          tree->first_setter(SYM_WALK_DEFMETHOD);
                        }
                        walk_defmethod_tree(tree);
                      }
                      else if ((test_value_001 == SYM_WALK_DEFGLOBAL) ||
                          ((test_value_001 == SYM_WALK_DEFSPECIAL) ||
                           (test_value_001 == SYM_WALK_DEFCONSTANT))) {
                        walk_defglobal_tree(tree);
                      }
                      else if (test_value_001 == SYM_WALK_DEFTYPE) {
                        walk_deftype_tree(tree);
                      }
                      else if (test_value_001 == SYM_WALK_DEFMODULE) {
                        walk_defmodule_tree(tree);
                      }
                      else if (test_value_001 == SYM_WALK_DEFMACRO) {
                        walk_defmacro_tree(tree);
                      }
                      else if (test_value_001 == SYM_WALK_STARTUP_TIME_PROGN) {
                        walk_startup_time_progn_tree(tree);
                      }
                      else if (test_value_001 == SYM_WALK_VERBATIM) {
                        walk_verbatim_definition_tree(tree);
                      }
                      else if (test_value_001 == SYM_WALK_PROGN) {
                        { Object* form = NULL;
                          Cons* iter_001 = tree->rest;

                          while (!nilP(iter_001)) {
                            {
                              form = iter_001->value;
                              iter_001 = iter_001->rest;
                            }
                            walk_top_level_tree(((Cons*)(form)), createannotationP);
                          }
                        }
                        free_cons_list(tree);
                        {
                          {
                            oCURRENTTRANSLATIONUNITo = old_OcurrenttranslationunitO_001;
                            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                          }
                          return;
                        }
                      }
                      else {
                        if (lookup_macro(((Symbol*)(tree->first()))) != NULL) {
                          { Object* expansion = expand_macro(tree);

                            if (expansion != NULL) {
                              walk_top_level_tree(((Cons*)(expansion)), createannotationP);
                            }
                          }
                        }
                        else {
                          if (!(incremental_translationP() ||
                              (lookup_command(((Symbol*)(tree->first()))) != NULL))) {
                            { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                              { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                                oEXCEPTIONHANDLERADDRESSo = NULL;
                                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                                  {
                                    oPRINTREADABLYpo = TRUE;
                                    signal_translation_warning();
                                    if (!(suppress_warningsP())) {
                                      print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                                      cout << endl << " " << "Illegal top-level statement:" << endl << "   " << "`" << de_uglify_parse_tree(tree) << "'" << endl << " Wrapping it into a 'startup-time-progn'" << "." << endl;
                                    }
                                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                                  }
                                  oEXCEPTIONo = NULL;
                                }
                                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                              }
                              if (oEXCEPTIONo != NULL) {
                                if (TRUE) {
                                  oPRINTREADABLYpo = old_OprintreadablyPO_001;
                                  resignal();
                                }
                              }
                            }
                          }
                          { boolean old_OtransientobjectsPO_002 = oTRANSIENTOBJECTSpo;

                            { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                              oEXCEPTIONHANDLERADDRESSo = NULL;
                              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                                {
                                  oTRANSIENTOBJECTSpo = TRUE;
                                  tree = listO(3, SYM_WALK_STARTUP_TIME_PROGN, tree, NIL);
                                  oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_002;
                                }
                                oEXCEPTIONo = NULL;
                              }
                              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
                            }
                            if (oEXCEPTIONo != NULL) {
                              if (TRUE) {
                                oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_002;
                                resignal();
                              }
                            }
                          }
                          walk_top_level_tree(tree, FALSE);
                        }
                        {
                          {
                            oCURRENTTRANSLATIONUNITo = old_OcurrenttranslationunitO_001;
                            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                          }
                          return;
                        }
                      }
                    }
                    if (oCURRENTTRANSLATIONUNITo != NULL) {
                      oTRANSLATIONUNITSo->push(oCURRENTTRANSLATIONUNITo);
                      oCURRENTTRANSLATIONUNITo->annotation = annotation;
                    }
                  }
                  oCURRENTTRANSLATIONUNITo = old_OcurrenttranslationunitO_001;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oCURRENTTRANSLATIONUNITo = old_OcurrenttranslationunitO_001;
                resignal();
              }
            }
          }
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
        resignal();
      }
    }
  }
}

Object* walk_top_level_expression(Object* tree) {
  { Key_Value_List* old_OlocalvariabletypetableO_001 = oLOCALVARIABLETYPETABLEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oLOCALVARIABLETYPETABLEo = new_key_value_list();
          { Object* otree = walk_without_type_tree(tree);

            if (vrlet_expressionP(otree)) {
              { Object* return_value_001 = walk_without_type_tree(listO(3, SYM_WALK_PROGN, otree, NIL));

                oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (return_value_001);
              }
            }
            { 
              oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (otree);
            }
          }
          oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
        resignal();
      }
    }
  }
}

void walk_phase_one_unit(Translation_Unit* unit) {
  { Key_Value_List* old_OlocalvariabletypetableO_001 = oLOCALVARIABLETYPETABLEo;
    Translation_Unit* old_OcurrenttranslationunitO_001 = oCURRENTTRANSLATIONUNITo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oLOCALVARIABLETYPETABLEo = new_key_value_list();
          oCURRENTTRANSLATIONUNITo = unit;
          { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

            { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oTRANSIENTOBJECTSpo = TRUE;
                  { Symbol* test_value_001 = unit->category;

                    if (test_value_001 == SYM_WALK_GLOBAL_VARIABLE) {
                      walk_global_unit(unit);
                    }
                    else if (test_value_001 == SYM_WALK_MODULE) {
                      walk_module_unit(unit);
                    }
                    else if (test_value_001 == SYM_WALK_TYPE) {
                      walk_type_unit(unit);
                    }
                    else if ((test_value_001 == SYM_WALK_METHOD) ||
                        (test_value_001 == SYM_WALK_PRINT_METHOD)) {
                      walk_method_unit(unit);
                    }
                    else if (test_value_001 == SYM_WALK_MACRO) {
                      walk_macro_unit(unit);
                    }
                    else if (test_value_001 == SYM_WALK_CLASS) {
                      walk_class_unit(unit);
                    }
                    else if (test_value_001 == SYM_WALK_SLOT) {
                      walk_slot_unit(unit);
                    }
                    else if (test_value_001 == SYM_WALK_STARTUP_TIME_PROGN) {
                      walk_startup_time_progn_unit(unit);
                    }
                    else if (test_value_001 == SYM_WALK_VERBATIM) {
                      walk_verbatim_unit(unit);
                    }
                    else {
                      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
                    }
                  }
                  oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                resignal();
              }
            }
          }
          oCURRENTTRANSLATIONUNITo = old_OcurrenttranslationunitO_001;
          oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oCURRENTTRANSLATIONUNITo = old_OcurrenttranslationunitO_001;
        oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
        resignal();
      }
    }
  }
}

void walk_auxiliary_tree(Cons* tree) {
  help_walk_auxiliary_tree(tree, TRUE);
}

Translation_Unit* help_walk_auxiliary_tree(Cons* tree, boolean finalizeP) {
  if (!(get_quoted_tree("((DEFCLASS DEFMETHOD DEFUN DEFMACRO DEFGLOBAL DEFSPECIAL DEFCONSTANT STARTUP-TIME-PROGN VERBATIM) \"/STELLA\")", "/STELLA")->memberP(tree->first()))) {
    cerr << "OOPS, illegal auxiliary statement:" << endl << "   " << "`" << tree << "'";
  }
  walk_top_level_tree(tree, FALSE);
  if (finalizeP) {
    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = FALSE;
            finalize_classes_and_slots();
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          resignal();
        }
      }
    }
  }
  { Translation_Unit* unit = ((Translation_Unit*)(oTRANSLATIONUNITSo->pop()));

    unit->auxiliaryP = TRUE;
    walk_phase_one_unit(unit);
    return (unit);
  }
}

void walk_all_phase_one_units(Symbol* startupfnname) {
  { List* phaseoneunits = oTRANSLATIONUNITSo;

    oTRANSLATIONUNITSo = new_list();
    { Translation_Unit* unit = NULL;
      Cons* iter_001 = phaseoneunits->the_cons_list;

      while (!nilP(iter_001)) {
        {
          unit = ((Translation_Unit*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if ((oTRANSLATIONVERBOSITYLEVELo >= 2) &&
            (unit->annotation != NULL)) {
          cout << "Walking " << "`" << unit->annotation << "'" << endl;
        }
        walk_phase_one_unit(unit);
      }
    }
    create_finalization_units();
    create_startup_function_unit(startupfnname);
    phaseoneunits->clear();
    oTRANSLATIONUNITSo->reverse();
  }
}

void translate_all_units() {
  { Translation_Unit* unit = NULL;
    Cons* iter_001 = oTRANSLATIONUNITSo->the_cons_list;

    while (!nilP(iter_001)) {
      {
        unit = ((Translation_Unit*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      { Translation_Unit* old_OcurrenttranslationunitO_001 = oCURRENTTRANSLATIONUNITo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oCURRENTTRANSLATIONUNITo = unit;
              if ((oTRANSLATIONVERBOSITYLEVELo >= 2) &&
                  (unit->annotation != NULL)) {
                cout << "Translating " << "`" << unit->annotation << "'" << endl;
              }
              { Keyword* test_value_001 = translator_output_language();

                if (test_value_001 == KWD_WALK_COMMON_LISP) {
                  unit->translation = cl_translate_unit(unit);
                }
                else if (test_value_001 == KWD_WALK_IDL) {
                  unit->translation = idl_translate_unit(unit);
                }
                else if (test_value_001 == KWD_WALK_JAVA) {
                  unit->translation = java_translate_unit(unit);
                }
                else if ((test_value_001 == KWD_WALK_CPP) ||
                    (test_value_001 == KWD_WALK_CPP_STANDALONE)) {
                  unit->translation = cpp_translate_unit(unit);
                }
                else {
                  cerr << "`" << test_value_001 << "'" << " is not a valid case option";
                }
              }
              oCURRENTTRANSLATIONUNITo = old_OcurrenttranslationunitO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oCURRENTTRANSLATIONUNITo = old_OcurrenttranslationunitO_001;
            resignal();
          }
        }
      }
    }
  }
}

Cons* combine_translated_trees() {
  { Cons* otree = NIL;

    { Translation_Unit* unit = NULL;
      Cons* iter_001 = oTRANSLATIONUNITSo->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          unit = ((Translation_Unit*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(unit->translation, NIL);
            if (nilP(otree)) {
              otree = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(otree, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(unit->translation, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    { Keyword* test_value_001 = translator_output_language();

      if (test_value_001 == KWD_WALK_COMMON_LISP) {
        otree = cons(intern_common_lisp_symbol("PROGN"), otree->concatenate(NIL));
      }
      else if ((test_value_001 == KWD_WALK_CPP) ||
          ((test_value_001 == KWD_WALK_CPP_STANDALONE) ||
           ((test_value_001 == KWD_WALK_JAVA) ||
            (test_value_001 == KWD_WALK_IDL)))) {
      }
      else {
        cerr << "`" << test_value_001 << "'" << " is not a valid case option";
      }
    }
    return (otree);
  }
}

Object* translate_walked_tree(Object* codetree) {
  { Keyword* test_value_001 = translator_output_language();

    if (test_value_001 == KWD_WALK_COMMON_LISP) {
      return (cl_translate_a_tree(codetree));
    }
    else if (test_value_001 == KWD_WALK_IDL) {
      return (idl_translate_a_tree(codetree));
    }
    else if (test_value_001 == KWD_WALK_JAVA) {
      return (java_translate_a_tree(codetree));
    }
    else if ((test_value_001 == KWD_WALK_CPP) ||
        (test_value_001 == KWD_WALK_CPP_STANDALONE)) {
      return (cpp_translate_a_tree(codetree));
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

Key_Value_List* read_OlocalvariabletypetableO() {
  return (oLOCALVARIABLETYPETABLEo);
}

Key_Value_List* write_OlocalvariabletypetableO(Key_Value_List* value) {
  oLOCALVARIABLETYPETABLEo = value;
  return (value);
}

Method_Slot* read_OmethodbeingwalkedO() {
  return (oMETHODBEINGWALKEDo);
}

Method_Slot* write_OmethodbeingwalkedO(Method_Slot* value) {
  oMETHODBEINGWALKEDo = value;
  return (value);
}

boolean read_OfoundreturnPO() {
  return (oFOUNDRETURNpo);
}

boolean write_OfoundreturnPO(boolean value) {
  oFOUNDRETURNpo = value;
  return (value);
}

Standard_Object* read_OtargettypeO() {
  return (oTARGETTYPEo);
}

Standard_Object* write_OtargettypeO(Standard_Object* value) {
  oTARGETTYPEo = value;
  return (value);
}

Key_Value_List* read_OlocalgensymtableO() {
  return (oLOCALGENSYMTABLEo);
}

Key_Value_List* write_OlocalgensymtableO(Key_Value_List* value) {
  oLOCALGENSYMTABLEo = value;
  return (value);
}

Keyword* translator_output_language() {
  return (oTRANSLATOR_OUTPUT_LANGUAGEo);
}

Keyword* set_translator_output_language(Keyword* newlanguage) {
  { Keyword* oldlanguage = translator_output_language();

    if (!(listO(6, KWD_WALK_CPP, KWD_WALK_CPP_STANDALONE, KWD_WALK_COMMON_LISP, KWD_WALK_JAVA, KWD_WALK_IDL, NIL)->memberP(newlanguage))) {
      cerr << "`" << newlanguage << "'" << " is not a legal translation language";
    }
    oTRANSLATOR_OUTPUT_LANGUAGEo = newlanguage;
    return (oldlanguage);
  }
}

int read_OtranslationerrorsO() {
  return (oTRANSLATIONERRORSo);
}

int write_OtranslationerrorsO(int value) {
  oTRANSLATIONERRORSo = value;
  return (value);
}

int read_OtranslationwarningsO() {
  return (oTRANSLATIONWARNINGSo);
}

int write_OtranslationwarningsO(int value) {
  oTRANSLATIONWARNINGSo = value;
  return (value);
}

void reset_translation_errors() {
  oTRANSLATIONERRORSo = 0;
  oTRANSLATIONWARNINGSo = 0;
}

void signal_translation_error() {
  oTRANSLATIONERRORSo = oTRANSLATIONERRORSo + 1;
}

void signal_translation_warning() {
  oTRANSLATIONWARNINGSo = oTRANSLATIONWARNINGSo + 1;
}

boolean read_OignoretranslationerrorsPO() {
  return (oIGNORETRANSLATIONERRORSpo);
}

boolean write_OignoretranslationerrorsPO(boolean value) {
  oIGNORETRANSLATIONERRORSpo = value;
  return (value);
}

boolean ignore_translation_errorsP() {
  return (oIGNORETRANSLATIONERRORSpo);
}

boolean translation_errorsP() {
  return ((oTRANSLATIONERRORSo > 0) &&
      (!ignore_translation_errorsP()));
}

void summarize_translation_errors() {
  if (oTRANSLATIONERRORSo > 0) {
    cout << oTRANSLATIONERRORSo << " error";
    if (oTRANSLATIONERRORSo > 1) {
      cout << "s";
    }
  }
  if (oTRANSLATIONWARNINGSo > 0) {
    if (oTRANSLATIONERRORSo > 0) {
      cout << ", ";
    }
    cout << oTRANSLATIONWARNINGSo << " warning";
    if (oTRANSLATIONWARNINGSo > 1) {
      cout << "s";
    }
  }
  if ((oTRANSLATIONERRORSo > 0) ||
      (oTRANSLATIONWARNINGSo > 0)) {
    cout << "." << endl;
  }
}

void print_error_context(char* prefix, Output_Stream* stream) {
  *(stream->native_stream) << prefix << "While ";
  if (oTRANSLATIONPHASEo != NULL) {
    if (oTRANSLATIONPHASEo == KWD_WALK_DEFINE) {
      *(stream->native_stream) << "defining ";
    }
    else if (oTRANSLATIONPHASEo == KWD_WALK_FINALIZE) {
      *(stream->native_stream) << "finalizing ";
    }
    else if (oTRANSLATIONPHASEo == KWD_WALK_WALK) {
      *(stream->native_stream) << "walking ";
    }
    else if (oTRANSLATIONPHASEo == KWD_WALK_TRANSLATE) {
      *(stream->native_stream) << "translating ";
    }
    else {
      cerr << "`" << oTRANSLATIONPHASEo << "'" << " is not a valid case option";
    }
  }
  else {
    *(stream->native_stream) << "processing ";
  }
  if (oCURRENTTRANSLATIONUNITo != NULL) {
    { Object* object = oCURRENTTRANSLATIONUNITo->the_object;
      Symbol* category = oCURRENTTRANSLATIONUNITo->category;

      if (category == SYM_WALK_CLASS) {
        *(stream->native_stream) << "class ";
        { Object* object_001 = object;

          if (classP(object)) {
            { Class* object = NULL;

              object = ((Class*)(object_001));
              *(stream->native_stream) << object->name();
            }
          }
          else {
            *(stream->native_stream) << object;
          }
        }
      }
      else if (category == SYM_WALK_SLOT) {
        *(stream->native_stream) << "external slot ";
        { Object* object_002 = object;

          if (consP(object)) {
            { Cons* object = NULL;

              object = ((Cons*)(object_002));
              *(stream->native_stream) << object->second() << "." << object->third();
            }
          }
          else if (storage_slotP(object)) {
            { Storage_Slot* object = NULL;

              object = ((Storage_Slot*)(object_002));
              *(stream->native_stream) << object->slot_owner << "." << object->slot_name->symbol_name;
            }
          }
          else {
            cerr << "`" << object << "'" << " is not a valid case option";
          }
        }
      }
      else if ((category == SYM_WALK_METHOD) ||
          ((category == SYM_WALK_PRINT_METHOD) ||
           (category == SYM_WALK_MACRO))) {
        { Object* object_003 = object;

          if (method_slotP(object)) {
            { Method_Slot* object = NULL;

              object = ((Method_Slot*)(object_003));
              if (category == SYM_WALK_MACRO) {
                *(stream->native_stream) << "macro expander ";
              }
              if (object->method_functionP) {
                *(stream->native_stream) << "function " << object->slot_name;
              }
              else {
                *(stream->native_stream) << "method " << object->slot_owner << "." << object->slot_name->symbol_name;
              }
            }
          }
          else if (consP(object)) {
            { Cons* object = NULL;

              object = ((Cons*)(object_003));
              if (object->first() == SYM_WALK_DEFUN) {
                *(stream->native_stream) << "function ";
              }
              else {
                *(stream->native_stream) << "method ";
              }
              *(stream->native_stream) << ((consP(object->second()) ? ((Object*)(((Cons*)(object->second()))->first())) : ((Object*)(object->second()))));
            }
          }
          else {
            cerr << "`" << object << "'" << " is not a valid case option";
          }
        }
      }
      else if (category == SYM_WALK_GLOBAL_VARIABLE) {
        { Object* object_004 = object;

          if (taxonomy_isaP(object, SGT_WALK_GLOBAL_VARIABLE)) {
            { Global_Variable* object = NULL;

              object = ((Global_Variable*)(object_004));
              if (object->variable_constantP) {
                *(stream->native_stream) << "constant ";
              }
              else {
                if (object->variable_specialP) {
                  *(stream->native_stream) << "special variable ";
                }
                else {
                  *(stream->native_stream) << "global variable ";
                }
              }
              *(stream->native_stream) << object->variable_name;
            }
          }
          else if (consP(object)) {
            { Cons* object = NULL;

              object = ((Cons*)(object_004));
              *(stream->native_stream) << object->first() << " " << object->second();
            }
          }
          else {
            cerr << "`" << object << "'" << " is not a valid case option";
          }
        }
      }
      else if (category == SYM_WALK_TYPE) {
        *(stream->native_stream) << "type ";
        { Object* object_005 = object;

          if (consP(object)) {
            { Cons* object = NULL;

              object = ((Cons*)(object_005));
              *(stream->native_stream) << object->second();
            }
          }
          else if (taxonomy_isaP(object, SGT_WALK_TYPE_SPEC)) {
            { Standard_Object* object = NULL;

              object = ((Standard_Object*)(object_005));
              *(stream->native_stream) << yield_type_spec_tree(object);
            }
          }
          else {
            cerr << "`" << object << "'" << " is not a valid case option";
          }
        }
      }
      else if (category == SYM_WALK_MODULE) {
        *(stream->native_stream) << "module ";
        { Object* object_006 = object;

          if (taxonomy_isaP(object, SGT_WALK_MODULE)) {
            { Module* object = NULL;

              object = ((Module*)(object_006));
              *(stream->native_stream) << object->module_name;
            }
          }
          else if (consP(object)) {
            { Cons* object = NULL;

              object = ((Cons*)(object_006));
              *(stream->native_stream) << object->second();
            }
          }
          else {
            cerr << "`" << object << "'" << " is not a valid case option";
          }
        }
      }
      else {
        *(stream->native_stream) << category;
      }
    }
  }
  else {
    *(stream->native_stream) << "top-level statement";
  }
  *(stream->native_stream) << ":";
}

void push_variable_binding(Symbol* variable, Standard_Object* type) {
  if (typeP(type) &&
      ((((Class*)(((Surrogate*)(type))->surrogate_value)) == NULL) &&
       (!(type == SGT_WALK_UNINITIALIZED)))) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            signal_translation_error();
            if (!(suppress_warningsP())) {
              print_error_context(">> ERROR: ", STANDARD_OUTPUT);
              cout << endl << " " << "No class defined for type: " << "`" << de_uglify_parse_tree(type) << "'" << "." << endl;
            }
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
          resignal();
        }
      }
    }
    type = SGT_WALK_UNKNOWN;
  }
  oLOCALVARIABLETYPETABLEo->the_kv_list = kv_cons(variable->soft_permanentify(), type, oLOCALVARIABLETYPETABLEo->the_kv_list);
}

void pop_variable_binding() {
  { Kv_Cons* kvlist = oLOCALVARIABLETYPETABLEo->the_kv_list;

    oLOCALVARIABLETYPETABLEo->the_kv_list = kvlist->rest;
    free_kv_cons(kvlist);
  }
}

Standard_Object* lookup_variable_type(Symbol* variablename) {
  variablename = variablename->soft_permanentify();
  { Standard_Object* type = ((Standard_Object*)(oLOCALVARIABLETYPETABLEo->lookup(variablename)));

    if (type == NULL) {
      if (variablename == SYM_WALK_NULL) {
        return (SGT_WALK_UNKNOWN);
      }
      type = lookup_global_variable_type(variablename);
      register_reference_to_global_variable(variablename);
    }
    if (type == NULL) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Undeclared variable " << "`" << de_uglify_parse_tree(variablename) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
      return (SGT_WALK_UNKNOWN);
    }
    if (type == SGT_WALK_UNINITIALIZED) {
      { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Reference to defined but uninitialized variable " << "`" << de_uglify_parse_tree(variablename) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_002;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_002;
            resignal();
          }
        }
      }
      return (SGT_WALK_UNKNOWN);
    }
    return (type);
  }
}

void register_reference_to_global_variable(Symbol* variablename) {
  if (oCURRENTTRANSLATIONUNITo != NULL) {
    { Global_Variable* global = variablename->lookup_global_variable();
      List* referencedglobals = oCURRENTTRANSLATIONUNITo->referenced_globals;

      if ((global != NULL) &&
          (!referencedglobals->memberP(global))) {
        referencedglobals->insert(global);
      }
    }
  }
}

Symbol* local_gensym(char* prefix) {
  if (oLOCALGENSYMTABLEo == NULL) {
    return (gensym(prefix));
  }
  { Symbol* prefixsymbol = intern_transient_symbol(prefix);
    Integer_Wrapper* prefixcounter = ((Integer_Wrapper*)(oLOCALGENSYMTABLEo->lookup(prefixsymbol)));

    if (prefixcounter == NULL) {
      prefixcounter = new_transient_integer_wrapper(0);
      oLOCALGENSYMTABLEo->insert_at(prefixsymbol, prefixcounter);
    }
    prefixcounter->wrapper_value = prefixcounter->wrapper_value + 1;
    return (intern_transient_symbol(yield_gensym_name(prefix, prefixcounter->wrapper_value)));
  }
}

void free_transient_type_spec(Standard_Object* self) {
  self = self;
}

boolean suppress_warningsP() {
  return (oCURRENT_ENVIRONMENT_FEATURESo->memberP(KWD_WALK_SUPPRESS_WARNINGS));
}

boolean bad_argument_rangeP(Cons* tree, int minarity, int maxarity) {
  { int argnum = tree->length() - 1;

    if (argnum < minarity) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Missing arguments in the expression: " << endl << " " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
      return (TRUE);
    }
    else if ((maxarity != NULL_INTEGER) &&
        (argnum > maxarity)) {
      { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Too many arguments in the expression: " << endl << " " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_002;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_002;
            resignal();
          }
        }
      }
      return (TRUE);
    }
    else {
      return (FALSE);
    }
  }
}

boolean bad_argument_countP(Cons* tree, int arity) {
  return (bad_argument_rangeP(tree, arity, arity));
}

Cons* yield_illegal_statement_tree() {
  { Key_Value_List* old_OlocalvariabletypetableO_001 = oLOCALVARIABLETYPETABLEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oLOCALVARIABLETYPETABLEo = new_key_value_list();
          { Object* return_value_001 = walk_without_type_tree(listO(5, SYM_WALK_ERROR, string_wrap_literal("Attempt to execute illegal statement flagged by the translator"), SYM_WALK_EOL, string_wrap_literal("    but not yet fixed."), NIL));

            oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
            return (((Cons*)(return_value_001)));
          }
          oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
        resignal();
      }
    }
  }
}

Object* yield_illegal_expression_tree() {
  return (SYM_WALK_ILLEGAL_EXPRESSION_FLAGGED_BY_THE_TRANSLATOR);
}

Cons* walk_dont_call_me_tree(Object* tree, Standard_Object* returntype, Standard_Object*& return1) {
  { Cons* return_temp = listO(3, SYM_WALK_BAD_SYS, tree, cons(type_spec_to_base_type(returntype), NIL));

    return1 = returntype;
    return (return_temp);
  }
}

boolean illegal_treeP(Object* tree) {
  return (consP(tree) &&
      (((Cons*)(tree))->first() == SYM_WALK_BAD_SYS));
}

boolean native_class_method_inliningP() {
  { Keyword* test_value_001 = translator_output_language();

    if (test_value_001 == KWD_WALK_COMMON_LISP) {
      return (FALSE);
    }
    else if ((test_value_001 == KWD_WALK_JAVA) ||
        ((test_value_001 == KWD_WALK_CPP) ||
         ((test_value_001 == KWD_WALK_CPP_STANDALONE) ||
          (test_value_001 == KWD_WALK_IDL)))) {
      return (TRUE);
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

Object* prognify(Cons* trees) {
  switch (trees->length()) {
    case 0: 
      return (NIL);
    case 1: 
      { Object* tree = trees->first();

        trees->first_setter(NULL);
        trees->free_parse_tree();
        return (tree);
      }
    break;
    default:
      return (cons(SYM_WALK_PROGN, trees->concatenate(NIL)));
  }
}

Object* optimize_progn(Cons* progn_tree) {
  switch (progn_tree->rest->length()) {
    case 0: 
      progn_tree->free_parse_tree();
      return (NIL);
    case 1: 
      { Object* tree = progn_tree->second();

        progn_tree->second_setter(NULL);
        progn_tree->free_parse_tree();
        return (tree);
      }
    break;
    default:
      return (progn_tree);
  }
}

Cons* tree_to_trees(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        if (tree->first() == SYM_WALK_PROGN) {
          return (tree->rest);
        }
      }
    }
    else {
    }
  }
  return (cons(tree, NIL));
}

Surrogate* wrapped_type_to_type(Surrogate* self) {
  // Return the unwrapped type for the wrapped type 'self',
  // or 'self' if it is not a wrapped type.
  { Cons* entry = NIL;
    Cons* iter_001 = oWRAPPED_TYPE_TABLEo;

    while (!nilP(iter_001)) {
      {
        entry = ((Cons*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (entry->first() == self) {
        return (((Surrogate*)(entry->second())));
      }
    }
  }
  return (self);
}

Surrogate* wrapper_value_type(Wrapper* self) {
  // Return the type of the value stored in the wrapper 'self'.
  { Surrogate* wrappertype = self->primary_type();
    Surrogate* valuetype = wrapped_type_to_type(wrappertype);

    if (valuetype == wrappertype) {
      cerr << "Missing *wrapped-type-table* entry";
    }
    else {
      return (valuetype);
    }
  }
}

Surrogate* Surrogate::type_to_wrapped_type() {
  // Return the wrapped type for the type 'self',
  // or 'self' if it is not a bare literal type.
  { Surrogate* self = this;

    if (((Class*)(self->surrogate_value)) == NULL) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Can't find a class named " << "`" << de_uglify_parse_tree(self) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
    }
    if (subtype_ofP(self, SGT_WALK_OBJECT)) {
      return (self);
    }
    { Cons* entry = NIL;
      Cons* iter_001 = oWRAPPED_TYPE_TABLEo;

      while (!nilP(iter_001)) {
        {
          entry = ((Cons*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (entry->second() == self) {
          return (((Surrogate*)(entry->first())));
        }
      }
    }
    { Surrogate* realtype = ((Class*)(self->surrogate_value))->class_type;

      if (!(self == realtype)) {
        { Cons* entry = NIL;
          Cons* iter_002 = oWRAPPED_TYPE_TABLEo;

          while (!nilP(iter_002)) {
            {
              entry = ((Cons*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            if (entry->second() == realtype) {
              return (((Surrogate*)(entry->first())));
            }
          }
        }
      }
    }
    return (NULL);
  }
}

Symbol* lookup_coersion_method(Surrogate* sourcetype, Surrogate* targettype, Object* expression) {
  expression = expression;
  sourcetype = canonical_type(sourcetype);
  { Cons* triple = NIL;
    Cons* iter_001 = oCOERSION_TABLEo;

    while (!nilP(iter_001)) {
      {
        triple = ((Cons*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if ((sourcetype == triple->first()) &&
          subtype_ofP(((Surrogate*)(triple->second())), targettype)) {
        return (((Symbol*)(triple->third())));
      }
    }
  }
  return (NULL);
}

boolean translating_codeP() {
  return ((oTRANSLATIONPHASEo == KWD_WALK_WALK) ||
      (oTRANSLATIONPHASEo == KWD_WALK_TRANSLATE));
}

Surrogate* verify_type(Surrogate* self) {
  if (translating_codeP() &&
      ((((Class*)(self->surrogate_value)) == NULL) ||
       (self->surrogate_value == SGT_WALK_UNKNOWN->surrogate_value))) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            signal_translation_warning();
            if (!(suppress_warningsP())) {
              print_error_context(">> WARNING: ", STANDARD_OUTPUT);
              cout << endl << " " << "Reference to undefined class " << "`" << self->symbol_name << "'" << "." << endl;
            }
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
          resignal();
        }
      }
    }
    self->surrogate_value = ((Class*)(SGT_WALK_UNKNOWN->surrogate_value));
  }
  return (self);
}

boolean safe_subtype_ofP(Surrogate* subtype, Surrogate* supertype) {
  verify_type(subtype);
  verify_type(supertype);
  return (subtype_ofP(subtype, supertype));
}

void warn_about_unknown_source_type(Object* tree) {
  if (warn_about_undefined_methodsP()) {
    { Object* tree_001 = tree;

      if (symbolP(tree)) {
        { Symbol* tree = NULL;

          tree = ((Symbol*)(tree_001));
          return;
        }
      }
      else if (consP(tree)) {
        { Cons* tree = NULL;

          tree = ((Cons*)(tree_001));
          { Object* test_value_001 = tree->first();

            if ((test_value_001 == SYM_WALK_VERBATIM) ||
                (test_value_001 == SYM_WALK_VRLET)) {
              return;
            }
            else if (test_value_001 == SYM_WALK_SYS_CALL_METHOD) {
              if (symbol_common_lispP(((Symbol*)(tree->third()))) ||
                  (safe_lookup_slot(((Class*)(((Surrogate*)(tree->second()))->surrogate_value)), ((Symbol*)(tree->third()))) == NULL)) {
                return;
              }
            }
            else if (test_value_001 == SYM_WALK_SYS_CALL_FUNCTION) {
              if (lookup_function_or_stella_function(((Symbol*)(tree->second())))->slot_base_type == SGT_WALK_UNKNOWN) {
                return;
              }
            }
            else {
            }
          }
        }
      }
      else {
        if (tree == NULL) {
          return;
        }
      }
    }
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            signal_translation_error();
            if (!(suppress_warningsP())) {
              print_error_context(">> ERROR: ", STANDARD_OUTPUT);
              cout << endl << " " << "The expression" << endl << "   " << "`" << de_uglify_parse_tree(tree) << "'" << endl << " has UNKNOWN type" << "." << endl;
            }
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
          resignal();
        }
      }
    }
  }
}

Object* coerce_a_tree(Object* tree, Standard_Object* sourcetype, Standard_Object* targettype, Standard_Object*& return1) {
  { Object* otree = NULL;
    Standard_Object* otype = NULL;
    boolean coercibleP = FALSE;

    otree = help_coerce_a_tree(tree, sourcetype, targettype, FALSE, otype, coercibleP);
    if (!(coercibleP)) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Type conflict: the expression:" << endl << "   " << "`" << de_uglify_parse_tree(tree) << "'" << endl << " has type " << "`" << yield_type_spec_tree(sourcetype) << "'" << " but should have type " << "`" << yield_type_spec_tree(targettype) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
    }
    { Object* return_temp = otree;

      return1 = otype;
      return (return_temp);
    }
  }
}

Object* help_coerce_a_tree(Object* tree, Standard_Object* sourcetype, Standard_Object* targettype, boolean testonlyP, Standard_Object*& return1, boolean& return2) {
  { Standard_Object* dummy1;

    { Symbol* coersionfunction = NULL;
      Surrogate* realsourcetype = target_language_type(tree);
      Surrogate* sourcebasetype = type_spec_to_base_type(sourcetype);
      Surrogate* targetbasetype = type_spec_to_base_type(targettype);

      if (sourcetype == SGT_WALK_UNKNOWN) {
        warn_about_unknown_source_type(tree);
        if ((tree == SYM_WALK_NULL) &&
            (targetbasetype != NULL)) {
          { Object* return_temp = type_to_null_value_tree(targetbasetype);

            return1 = targettype;
            return2 = TRUE;
            return (return_temp);
          }
        }
        else {
          { Object* return_temp = tree;

            return1 = targettype;
            return2 = TRUE;
            return (return_temp);
          }
        }
      }
      if (realsourcetype != NULL) {
        set_target_language_type(((Cons*)(tree)), NULL, dummy1);
        tree = coerce_a_tree(tree, realsourcetype, sourcetype, sourcetype);
      }
      if (targettype == SGT_WALK_UNKNOWN) {
        { Object* return_temp = tree;

          return1 = sourcetype;
          return2 = TRUE;
          return (return_temp);
        }
      }
      if (((Class*)(sourcebasetype->surrogate_value)) == NULL) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "No class defined for type: " << "`" << de_uglify_parse_tree(sourcebasetype) << "'" << "." << endl;
                }
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
              resignal();
            }
          }
        }
        { Object* return_temp = tree;

          return1 = targettype;
          return2 = TRUE;
          return (return_temp);
        }
      }
      if ((targetbasetype != NULL) &&
          (((Class*)(targetbasetype->surrogate_value)) == NULL)) {
        { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "No class defined for type: " << "`" << de_uglify_parse_tree(targetbasetype) << "'" << "." << endl;
                }
                oPRINTREADABLYpo = old_OprintreadablyPO_002;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_002;
              resignal();
            }
          }
        }
        { Object* return_temp = tree;

          return1 = sourcetype;
          return2 = TRUE;
          return (return_temp);
        }
      }
      if (sub_type_spec_ofP(sourcetype, targettype)) {
        { Object* return_temp = tree;

          return1 = sourcetype;
          return2 = TRUE;
          return (return_temp);
        }
      }
      if ((targetbasetype != NULL) &&
          compatible_parameter_typesP(sourcetype, targettype)) {
        { boolean test_value_001 = FALSE;

          test_value_001 = typeP(sourcetype);
          if (test_value_001) {
            { 
              coersionfunction = lookup_coersion_method(((Surrogate*)(sourcetype)), targetbasetype, tree);
              test_value_001 = coersionfunction != NULL;
            }
          }
          if (test_value_001) {
            if (coersionfunction == SYM_WALK_IDENTITY) {
              { Object* return_temp = tree;

                return1 = targettype;
                return2 = TRUE;
                return (return_temp);
              }
            }
            else {
              { Object* return_temp = (testonlyP ? ((Object*)(tree)) : ((Object*)(walk_without_type_tree(cons(coersionfunction, cons(tree, NIL))))));

                return1 = targettype;
                return2 = TRUE;
                return (return_temp);
              }
            }
          }
        }
        if (subtype_ofP(targetbasetype, sourcebasetype)) {
          if (testonlyP) {
            { Object* return_temp = tree;

              return1 = targettype;
              return2 = TRUE;
              return (return_temp);
            }
          }
          { Object* return_temp = walk_without_type_tree(cons(((realsourcetype != NULL) ? ((Symbol*)(SYM_WALK_SAFE_CAST)) : ((Symbol*)(SYM_WALK_CAST))), cons(tree, cons(targetbasetype, NIL))));

            return1 = targettype;
            return2 = TRUE;
            return (return_temp);
          }
        }
        if (subtype_ofP(targetbasetype, SGT_WALK_NON_OBJECT) &&
            (typeP(sourcetype) &&
             subtype_ofP(SGT_WALK_WRAPPER, ((Surrogate*)(sourcetype))))) {
          { Surrogate* wrappertype = targetbasetype->type_to_wrapped_type();

            if (wrappertype != NULL) {
              if (testonlyP) {
                { Object* return_temp = tree;

                  return1 = targettype;
                  return2 = TRUE;
                  return (return_temp);
                }
              }
              coersionfunction = lookup_coersion_method(wrappertype, targetbasetype, tree);
              if (coersionfunction != NULL) {
                { Object* return_temp = walk_without_type_tree(cons(coersionfunction, cons(listO(3, SYM_WALK_CAST, tree, cons(wrappertype, NIL)), NIL)));

                  return1 = targettype;
                  return2 = TRUE;
                  return (return_temp);
                }
              }
            }
          }
        }
      }
      { Object* return_temp = tree;

        return1 = sourcetype;
        return2 = FALSE;
        return (return_temp);
      }
    }
  }
}

boolean coercibleP(Object* tree, Standard_Object* sourcetype, Standard_Object* targettype) {
  { Object* otree = NULL;
    Standard_Object* otype = NULL;
    boolean coercibleP = FALSE;

    otree = help_coerce_a_tree(tree, sourcetype, targettype, TRUE, otype, coercibleP);
    return (coercibleP);
  }
}

boolean walking_expressionP() {
  return (!(oTARGETTYPEo == SGT_WALK_VOID));
}

Object* walk_expression_tree(Object* exptree, Standard_Object* targettype, Symbol* operatorname, boolean vrletisokP, Standard_Object*& return1) {
  { Standard_Object* old_OtargettypeO_001 = oTARGETTYPEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTARGETTYPEo = ((targettype != NULL) ? ((Standard_Object*)(targettype)) : ((Standard_Object*)(SGT_WALK_UNKNOWN)));
          { Object* oexp = NULL;
            Standard_Object* sourcetype = NULL;

            oexp = walk_a_tree(exptree, sourcetype);
            if (vrlet_expressionP(oexp)) {
              if (!(vrletisokP)) {
                { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_error();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Illegal procedural expression as argument to " << "`" << de_uglify_parse_tree(operatorname) << "'" << ":" << endl << "   " << "`" << de_uglify_parse_tree(exptree) << "'" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      resignal();
                    }
                  }
                }
              }
              { 
                oTARGETTYPEo = old_OtargettypeO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Object* return_temp = oexp;

                  return1 = sourcetype;
                  return (return_temp);
                }
              }
            }
            if (voidP(sourcetype) &&
                (!voidP(targettype))) {
              { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_error();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Illegal argument to " << "`" << de_uglify_parse_tree(operatorname) << "'" << ":" << endl << "   " << "`" << de_uglify_parse_tree(oexp) << "'" << endl << "The argument must be an expression, not a statement" << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    resignal();
                  }
                }
              }
              { 
                oTARGETTYPEo = old_OtargettypeO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Object* return_temp = oexp;

                  return1 = sourcetype;
                  return (return_temp);
                }
              }
            }
            if (sourcetype == NULL) {
              sourcetype = SGT_WALK_UNKNOWN;
            }
            if (targettype == NULL) {
              targettype = sourcetype;
            }
            { Object* return_value_001 = NULL;
              Standard_Object* return_value_002 = NULL;

              return_value_001 = coerce_a_tree(oexp, sourcetype, targettype, return_value_002);
              oTARGETTYPEo = old_OtargettypeO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              { Object* return_temp = return_value_001;

                return1 = return_value_002;
                return (return_temp);
              }
            }
          }
          oTARGETTYPEo = old_OtargettypeO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oTARGETTYPEo = old_OtargettypeO_001;
        resignal();
      }
    }
  }
}

Object* walk_without_type_tree(Object* tree) {
  { Object* otree = NULL;
    Standard_Object* unusedtypespec = NULL;

    otree = walk_a_tree(tree, unusedtypespec);
    free_transient_type_spec(unusedtypespec);
    return (otree);
  }
}

Cons* walk_list_of_trees(Cons* trees) {
  { Cons* cursor = trees;

    while (cursor->non_emptyP()) {
      cursor->value = walk_statement(cursor->value, FALSE);
      cursor = cursor->rest;
    }
    return (trees);
  }
}

Object* walk_statement(Object* tree, boolean warnonatomP) {
  { Object* otree = NULL;
    Standard_Object* unusedtypespec = NULL;

    otree = walk_a_tree(tree, unusedtypespec);
    free_transient_type_spec(unusedtypespec);
    { Object* otree_001 = otree;

      if (consP(otree)) {
        { Cons* otree = NULL;

          otree = ((Cons*)(otree_001));
          if (otree->first() == SYM_WALK_VRLET) {
            otree = eliminate_vrlet_statement(otree);
          }
        }
      }
      else {
        if ((!(tree == SYM_WALK_NULL)) &&
            warnonatomP) {
          { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  signal_translation_warning();
                  if (!(suppress_warningsP())) {
                    print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                    cout << endl << " " << "Expression found where statement expected: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                  }
                  oPRINTREADABLYpo = old_OprintreadablyPO_001;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
                resignal();
              }
            }
          }
        }
      }
    }
    return (otree);
  }
}

Cons* eliminate_vrlet_statement(Cons* tree) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;

    tree->first_setter(SYM_WALK_LET);
    { Cons* cursor = tree;

      while (cursor->rest->non_emptyP()) {
        cursor = cursor->rest;
      }
      if (consP(cursor->value)) {
        return (((Cons*)(walk_a_tree(tree, dummy1))));
      }
      free_cons_tree(cursor->value);
      cursor->value = NULL;
    }
    delete_null_statements(tree);
    return (((Cons*)(walk_a_tree(tree, dummy2))));
  }
}

Cons* sys_tree(Object* tree, Standard_Object* typespec, Standard_Object*& return1) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Object* test_value_001 = tree->first();

          if (test_value_001 == SYM_WALK_VOID_SYS) {
            if (voidP(typespec)) {
              { Cons* return_temp = tree;

                return1 = typespec;
                return (return_temp);
              }
            }
          }
          else if (test_value_001 == SYM_WALK_TYPED_SYS) {
            if (tree->third() == typespec) {
              { Cons* return_temp = tree;

                return1 = typespec;
                return (return_temp);
              }
            }
          }
          else {
          }
        }
      }
    }
    else {
    }
  }
  if (voidP(typespec)) {
    { Cons* return_temp = listO(3, SYM_WALK_VOID_SYS, tree, NIL);

      return1 = SGT_WALK_VOID;
      return (return_temp);
    }
  }
  else {
    { Cons* return_temp = listO(3, SYM_WALK_TYPED_SYS, tree, cons(typespec, NIL));

      return1 = typespec;
      return (return_temp);
    }
  }
}

Standard_Object* walked_expression_type(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        if (tree->first() == SYM_WALK_TYPED_SYS) {
          return (((Standard_Object*)(tree->third())));
        }
      }
    }
    else if (wrapperP(tree)) {
      { Wrapper* tree = NULL;

        tree = ((Wrapper*)(tree_001));
        return (wrapped_type_to_type(tree->primary_type()));
      }
    }
    else {
    }
  }
  return (SGT_WALK_UNKNOWN);
}

boolean need_identical_method_signaturesP() {
  { Keyword* test_value_001 = translator_output_language();

    if ((test_value_001 == KWD_WALK_CPP) ||
        (test_value_001 == KWD_WALK_CPP_STANDALONE)) {
      return (TRUE);
    }
    else {
      return (FALSE);
    }
  }
}

Standard_Object* compute_most_general_return_type(Method_Slot* method, Standard_Object* returntype) {
  { Standard_Object* mostgeneralreturntype = returntype;
    Method_Slot* mostgeneralmethod = method;

    while (mostgeneralmethod->slot_direct_equivalent != NULL) {
      mostgeneralmethod = ((Method_Slot*)(mostgeneralmethod->slot_direct_equivalent));
      if (!(mostgeneralmethod->slot_base_type == SGT_WALK_UNKNOWN)) {
        mostgeneralreturntype = mostgeneralmethod->slot_base_type;
      }
    }
    return (mostgeneralreturntype);
  }
}

Standard_Object* compute_real_slot_type(Storage_Slot* slot, Standard_Object* firstargtype, Standard_Object* returntype) {
  { Standard_Object* slottype = returntype;
    Storage_Slot* canonicalslot = canonical_slot(slot);
    Class* nativeslothome = NULL;

    if (!(translator_output_language() == KWD_WALK_COMMON_LISP)) {
      if (native_slotP(canonicalslot)) {
        nativeslothome = native_slot_home(slot, type_spec_to_class(firstargtype));
      }
      if (nativeslothome != NULL) {
        slottype = type_spec_to_base_type(lookup_slot(nativeslothome, canonicalslot->slot_name)->compute_return_type_spec(nativeslothome->class_type));
      }
      else {
        slottype = type_spec_to_base_type(slot->compute_return_type_spec(type_spec_to_base_type(firstargtype)));
      }
      if (slottype == type_spec_to_base_type(returntype)) {
        slottype = returntype;
      }
    }
    if (!(slot == canonicalslot)) {
      slottype = canonicalslot->slot_base_type;
    }
    return (slottype);
  }
}

Object* sys_tree_if_needed(Slot* slot, Object* tree, Standard_Object* firstargtype, Standard_Object* returntype, Standard_Object*& return1) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;
    Standard_Object* dummy3;

    if (slot != NULL) {
      { Slot* slot_001 = slot;

        if (method_slotP(slot)) {
          { Method_Slot* slot = NULL;

            slot = ((Method_Slot*)(slot_001));
            if ((!slot->method_functionP) &&
                need_identical_method_signaturesP()) {
              { Standard_Object* mostgeneralreturntype = compute_most_general_return_type(slot, returntype);

                if (!(returntype == mostgeneralreturntype)) {
                  return (set_target_language_type(sys_tree(tree, returntype, dummy1), ((Surrogate*)(mostgeneralreturntype)), return1));
                }
              }
            }
          }
        }
        else if (storage_slotP(slot)) {
          { Storage_Slot* slot = NULL;

            slot = ((Storage_Slot*)(slot_001));
            { Standard_Object* realslottype = compute_real_slot_type(slot, firstargtype, returntype);

              if (!(returntype == realslottype)) {
                return (set_target_language_type(sys_tree(tree, returntype, dummy2), ((Surrogate*)(realslottype)), return1));
              }
            }
          }
        }
        else {
          cerr << "`" << slot << "'" << " is not a valid case option";
        }
      }
      { Compound_Type_Specifier* slottype = ((Compound_Type_Specifier*)(dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, NULL)));

        { boolean test_value_001 = FALSE;

          test_value_001 = slottype != NULL;
          if (test_value_001) {
            if (anchored_type_specifierP(slottype)) {
              test_value_001 = TRUE;
            }
            else {
              { boolean foundP_001 = FALSE;

                { Standard_Object* ts = NULL;
                  Cons* iter_001 = ((Parametric_Type_Specifier*)(slottype))->specifier_parameter_types->the_cons_list;

                  while (!nilP(iter_001)) {
                    {
                      ts = ((Standard_Object*)(iter_001->value));
                      iter_001 = iter_001->rest;
                    }
                    if (anchored_type_specifierP(ts)) {
                      foundP_001 = TRUE;
                      break;
                    }
                  }
                }
                test_value_001 = foundP_001;
              }
            }
          }
          if (test_value_001) {
            if (anchored_type_specifierP(slottype) &&
                (!(translator_output_language() == KWD_WALK_COMMON_LISP))) {
              return (set_target_language_type(sys_tree(tree, returntype, dummy3), ((slot->slot_base_type == SGT_WALK_UNKNOWN) ? ((Surrogate*)(type_spec_to_base_type(returntype))) : ((Surrogate*)(slot->slot_base_type))), return1));
            }
            else {
              return (sys_tree(tree, returntype, return1));
            }
          }
        }
      }
    }
    { Object* return_temp = tree;

      return1 = returntype;
      return (return_temp);
    }
  }
}

Surrogate* target_language_type(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        if ((tree->first() == SYM_WALK_TYPED_SYS) &&
            (tree->length() == 4)) {
          return (((Surrogate*)(tree->fourth())));
        }
      }
    }
    else {
    }
  }
  return (NULL);
}

Cons* set_target_language_type(Cons* systree, Surrogate* type, Standard_Object*& return1) {
  if (systree->length() == 4) {
    systree->fourth_setter(type);
  }
  else {
    systree->rest->rest->rest = cons_list(1, type);
  }
  { Cons* return_temp = systree;

    return1 = ((Standard_Object*)(systree->third()));
    return (return_temp);
  }
}

Cons* delete_null_statements(Cons* trees) {
  return (trees->remove(NULL));
}

Object* walk_a_tree(Object* tree, Standard_Object*& return1) {
  return (help_walk_a_tree(tree, return1));
}

Object* help_walk_a_tree(Object* tree, Standard_Object*& return1) {
  if (tree == NULL) {
    { Object* return_temp = NULL;

      return1 = SGT_WALK_UNKNOWN;
      return (return_temp);
    }
  }
  else {
    { Object* tree_001 = tree;

      if (consP(tree)) {
        { Cons* tree = NULL;

          tree = ((Cons*)(tree_001));
          if (nilP(tree)) {
            { Object* return_temp = NIL;

              return1 = SGT_WALK_CONS;
              return (return_temp);
            }
          }
          if (consP(tree->value)) {
            { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Unimplemented or illegal parse tree: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_001;
                  resignal();
                }
              }
            }
            { Object* return_temp = tree;

              return1 = SGT_WALK_VOID;
              return (return_temp);
            }
          }
          if (!(consP(tree->rest))) {
            { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Illegal dotted pair or list*" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_002;
                  resignal();
                }
              }
            }
            { Object* return_temp = tree;

              return1 = SGT_WALK_VOID;
              return (return_temp);
            }
          }
          { Object* test_value_001 = tree->first();

            if (test_value_001 == SYM_WALK_VOID_SYS) {
              { Object* return_temp = tree;

                return1 = SGT_WALK_VOID;
                return (return_temp);
              }
            }
            else if (test_value_001 == SYM_WALK_TYPED_SYS) {
              { Object* return_temp = tree;

                return1 = ((Standard_Object*)(tree->third()));
                return (return_temp);
              }
            }
            else if (test_value_001 == SYM_WALK_SYS_FOREACH) {
              { Object* return_temp = tree;

                return1 = SGT_WALK_VOID;
                return (return_temp);
              }
            }
            else if (test_value_001 == SYM_WALK_BAD_SYS) {
              { Object* return_temp = tree;

                return1 = ((Standard_Object*)(tree->third()));
                return (return_temp);
              }
            }
            else if (test_value_001 == SYM_WALK_SETQ) {
              return (walk_setq_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_SETF) {
              return (walk_setf_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_SLOT_VALUE) {
              return (walk_slot_value_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_SLOT_VALUE_SETTER) {
              return (walk_slot_value_setter_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_PROGN) {
              tree->rest = walk_list_of_trees(delete_null_statements(tree->rest));
              return (sys_tree(tree, SGT_WALK_VOID, return1));
            }
            else if (test_value_001 == SYM_WALK_LOOP) {
              return (walk_loop_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_LET) {
              return (walk_let_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_VRLET) {
              { Object* return_temp = tree;

                return1 = SGT_WALK_UNKNOWN;
                return (return_temp);
              }
            }
            else if (test_value_001 == SYM_WALK_VALUES) {
              return (walk_values_tree(tree, return1));
            }
            else if ((test_value_001 == SYM_WALK_SPECIAL) ||
                (test_value_001 == SYM_WALK_SYS_SPECIAL)) {
              return (walk_special_tree(tree, return1));
            }
            else if ((test_value_001 == SYM_WALK_CAST) ||
                (test_value_001 == SYM_WALK_SAFE_CAST)) {
              return (walk_cast_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_RETURN) {
              return (walk_return_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_MV_SETQ) {
              return (walk_mv_setq_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_MV_BIND) {
              return (walk_mv_bind_tree(tree, return1));
            }
            else if ((test_value_001 == SYM_WALK_BREAK) ||
                (test_value_001 == SYM_WALK_CONTINUE)) {
              return (walk_loop_exit_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_WHILE) {
              return (walk_while_tree(tree, return1));
            }
            else if ((test_value_001 == SYM_WALK_FOREACH) ||
                ((test_value_001 == SYM_WALK_EXISTS) ||
                 ((test_value_001 == SYM_WALK_FORALL) ||
                  ((test_value_001 == SYM_WALK_SOME) ||
                   ((test_value_001 == SYM_WALK_SETOF) ||
                    ((test_value_001 == SYM_WALK_SET_OF) ||
                     (test_value_001 == SYM_WALK_SELECT))))))) {
              return (walk_foreach_tree(tree, return1));
            }
            else if ((test_value_001 == SYM_WALK_IF) ||
                ((test_value_001 == SYM_WALK_WHEN) ||
                 (test_value_001 == SYM_WALK_UNLESS))) {
              return (walk_conditional_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_CHOOSE) {
              return (walk_choose_tree(tree, return1));
            }
            else if ((test_value_001 == SYM_WALK_AND) ||
                ((test_value_001 == SYM_WALK_OR) ||
                 (test_value_001 == SYM_WALK_NOT))) {
              return (walk_boolean_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_COND) {
              return (walk_cond_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_CASE) {
              return (walk_case_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_TYPECASE) {
              return (walk_typecase_tree(tree, return1));
            }
            else if ((test_value_001 == SYM_WALK_EQp) ||
                ((test_value_001 == SYM_WALK_EQLp) ||
                 (test_value_001 == SYM_WALK_e))) {
              return (walk_equality_tree(tree, return1));
            }
            else if ((test_value_001 == SYM_WALK_i) ||
                ((test_value_001 == SYM_WALK__) ||
                 ((test_value_001 == SYM_WALK_o) ||
                  (test_value_001 == SYM_WALK_s)))) {
              { Object* value_001 = NULL;
                Surrogate* value_002 = NULL;

                value_001 = walk_arithmetic_tree(tree, value_002);
                { Object* return_temp = value_001;

                  return1 = value_002;
                  return (return_temp);
                }
              }
            }
            else if (test_value_001 == SYM_WALK_QUOTE) {
              return (walk_quoted_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_BQUOTE) {
              return (walk_bquote_tree(tree, return1));
            }
            else if ((test_value_001 == SYM_WALK_PRINT_STREAM) ||
                (test_value_001 == SYM_WALK_PRINT_NATIVE_STREAM)) {
              return (walk_print_stream_tree(tree, return1));
            }
            else if ((test_value_001 == SYM_WALK_NEW) ||
                ((test_value_001 == SYM_WALK_ALLOCATE) ||
                 (test_value_001 == SYM_WALK_LOCAL_NEW))) {
              return (walk_new_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_MAKE) {
              return (walk_make_tree(tree, return1));
            }
            else if ((test_value_001 == SYM_WALK_FUNCALL) ||
                ((test_value_001 == SYM_WALK_SYS_CALL_FUNCTION_CODE) ||
                 (test_value_001 == SYM_WALK_SYS_CALL_METHOD_CODE))) {
              return (walk_funcall_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_THE_CODE) {
              return (walk_the_code_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_EXCEPTION_CASE) {
              return (walk_exception_case_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_VERBATIM) {
              return (walk_verbatim_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_INLINE) {
              { Object* return_temp = tree;

                return1 = SGT_WALK_VOID;
                return (return_temp);
              }
            }
            else if ((test_value_001 == SYM_WALK_SYS_SLOT_VALUE) ||
                ((test_value_001 == SYM_WALK_SYS_SLOT_VALUE_SETTER) ||
                 ((test_value_001 == SYM_WALK_SYS_CALL_METHOD) ||
                  ((test_value_001 == SYM_WALK_SYS_CALL_METHOD_SETTER) ||
                   (test_value_001 == SYM_WALK_SYS_CALL_FUNCTION))))) {
              return (walk_sys_call_tree(tree, return1));
            }
            else if (test_value_001 == SYM_WALK_SYS_NEW) {
              { Object* return_temp = tree;

                return1 = ((Standard_Object*)(tree->second()));
                return (return_temp);
              }
            }
            else if ((test_value_001 == SYM_WALK_DEFCLASS) ||
                ((test_value_001 == SYM_WALK_DEFMETHOD) ||
                 ((test_value_001 == SYM_WALK_DEFUN) ||
                  ((test_value_001 == SYM_WALK_DEFMACRO) ||
                   ((test_value_001 == SYM_WALK_STARTUP_TIME_PROGN) ||
                    ((test_value_001 == SYM_WALK_DEFGLOBAL) ||
                     ((test_value_001 == SYM_WALK_DEFSPECIAL) ||
                      (test_value_001 == SYM_WALK_DEFCONSTANT)))))))) {
              { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_error();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Illegal declaration -- must appear as a top-level statement;" << endl << "   not nested within other statements." << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_003;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_003;
                    resignal();
                  }
                }
              }
              free_cons_tree(tree);
              { Object* return_temp = NULL;

                return1 = SGT_WALK_VOID;
                return (return_temp);
              }
            }
            else {
              if (symbolP(tree->first())) {
                return (walk_call_slot_tree(tree, return1));
              }
              else {
                {
                  { boolean old_OprintreadablyPO_004 = oPRINTREADABLYpo;

                    { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oPRINTREADABLYpo = TRUE;
                          signal_translation_error();
                          if (!(suppress_warningsP())) {
                            print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                            cout << endl << " " << "Illegal expression where method name expected:" << endl << "   " << "`" << tree->first() << "'" << "." << endl;
                          }
                          oPRINTREADABLYpo = old_OprintreadablyPO_004;
                        }
                        oEXCEPTIONo = NULL;
                      }
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
                    }
                    if (oEXCEPTIONo != NULL) {
                      if (TRUE) {
                        oPRINTREADABLYpo = old_OprintreadablyPO_004;
                        resignal();
                      }
                    }
                  }
                  return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
                }
              }
            }
          }
        }
      }
      else {
        return (tree->walk_atomic_tree(return1));
      }
    }
  }
}

Cons* walk_a_cons_tree(Cons* tree, Standard_Object*& return1) {
  { Object* otree = NULL;
    Standard_Object* otype = NULL;

    otree = walk_a_tree(tree, otype);
    { Cons* return_temp = ((Cons*)(otree));

      return1 = otype;
      return (return_temp);
    }
  }
}

char* read_OcurrentfileO() {
  return (oCURRENTFILEo);
}

char* write_OcurrentfileO(char* value) {
  oCURRENTFILEo = value;
  return (value);
}

boolean incremental_translationP() {
  return (oCURRENTFILEo == NULL);
}

Symbol* yield_symbol_constant_name(Generalized_Symbol* symbol) {
  { char* prefix = NULL;
    char* filename = (incremental_translationP() ? ((char*)("")) : ((char*)(string_concatenate("-", oCURRENTFILEo))));

    { Generalized_Symbol* symbol_001 = symbol;

      if (symbolP(symbol)) {
        { Symbol* symbol = NULL;

          symbol = ((Symbol*)(symbol_001));
          prefix = "SYM";
        }
      }
      else if (surrogateP(symbol)) {
        { Surrogate* symbol = NULL;

          symbol = ((Surrogate*)(symbol_001));
          prefix = "SGT";
        }
      }
      else if (keywordP(symbol)) {
        { Keyword* symbol = NULL;

          symbol = ((Keyword*)(symbol_001));
          prefix = "KWD";
        }
      }
      else {
        cerr << "`" << symbol << "'" << " is not a valid case option";
      }
    }
    return (intern_derived_symbol(symbol, string_concatenate(prefix, string_concatenate(filename, string_concatenate("-", symbol->symbol_name)))));
  }
}

Symbol* create_startup_symbol(Generalized_Symbol* symbol) {
  { Module* symbolmodule = ((Module*)(symbol->home_context));
    Symbol* symbolconstant = yield_symbol_constant_name(symbol);
    char* symbolconstantname = symbolconstant->symbol_name;
    Object* symbolconstanttypetree = yield_type_spec_tree(symbol->primary_type());
    char* nativepackage = symbolmodule->native_package();
    Cons* tree = NULL;

    if (incremental_translationP()) {
    }
    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            tree = listO(3, SYM_WALK_DEFGLOBAL, symbolconstant, cons(symbolconstanttypetree, cons(SYM_WALK_NULL, NIL)));
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          resignal();
        }
      }
    }
    walk_auxiliary_tree(tree);
    { boolean old_OtransientobjectsPO_002 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            tree = listO(4, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_SYMBOLS, listO(3, SYM_WALK_SETQ, symbolconstant, cons(listO(4, SYM_WALK_SAFE_CAST, listO(3, SYM_WALK_INTERN_RIGID_SYMBOL_WRT_MODULE, string_wrap_literal(symbol->symbol_name), cons((((symbolmodule == oMODULEo) ||
                keywordP(symbol)) ? ((Standard_Object*)(SYM_WALK_NULL)) : ((Standard_Object*)(listO(3, SYM_WALK_GET_MODULE, string_wrap_literal(symbolmodule->module_full_name), cons(SYM_WALK_TRUE, NIL))))), cons(integer_wrap_literal((keywordP(symbol) ? ((int)(KEYWORD_SYM)) : ((int)((surrogateP(symbol) ? ((int)(SURROGATE_SYM)) : ((int)(SYMBOL_SYM))))))), NIL))), symbolconstanttypetree, NIL), NIL)), NIL);
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_002;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_002;
          resignal();
        }
      }
    }
    walk_auxiliary_tree(tree);
    return (symbolconstant);
  }
}

void register_symbol(Generalized_Symbol* symbol) {
  symbol = ((Generalized_Symbol*)(symbol->permanentify()));
  if (!(((Generalized_Symbol*)(oSYMBOL_REGISTRYo->lookup(symbol))) != NULL)) {
    oSYMBOL_REGISTRYo->insert_at(symbol, symbol);
    oSYMBOL_SETo->insert(symbol);
    if (!(use_hardcoded_symbolsP())) {
      create_startup_symbol(symbol);
    }
  }
}

void clear_symbol_registry() {
  { Generalized_Symbol* symbol = NULL;
    Cons* iter_001 = oSYMBOL_SETo->the_cons_list;

    while (!nilP(iter_001)) {
      {
        symbol = ((Generalized_Symbol*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      oSYMBOL_REGISTRYo->remove_at(symbol);
    }
  }
  oSYMBOL_SETo->clear();
}

Cons* yield_hardcoded_intern_registered_symbols_tree() {
  { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTRANSIENTOBJECTSpo = TRUE;
          { Cons* interntrees = listO(3, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_SYMBOLS, NIL);

            { Generalized_Symbol* symbol = NULL;
              Cons* iter_001 = oSYMBOL_SETo->the_cons_list;
              Cons* collect_001 = NULL;

              while (!nilP(iter_001)) {
                {
                  symbol = ((Generalized_Symbol*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                if (collect_001 == NULL) {
                  {
                    collect_001 = cons(cons((symbolP(symbol) ? ((Symbol*)(SYM_WALK_INTERN_SYMBOL_AT)) : ((Symbol*)((surrogateP(symbol) ? ((Symbol*)(SYM_WALK_INTERN_SURROGATE_AT)) : ((Symbol*)(SYM_WALK_INTERN_KEYWORD_AT)))))), cons(string_wrap_literal(symbol->symbol_name), cons(integer_wrap_literal(symbol->symbol_id), NIL))), NIL);
                    if (nilP(interntrees)) {
                      interntrees = collect_001;
                    }
                    else {
                      add_cons_to_end_of_cons_list(interntrees, collect_001);
                    }
                  }
                }
                else {
                  {
                    collect_001->rest = cons(cons((symbolP(symbol) ? ((Symbol*)(SYM_WALK_INTERN_SYMBOL_AT)) : ((Symbol*)((surrogateP(symbol) ? ((Symbol*)(SYM_WALK_INTERN_SURROGATE_AT)) : ((Symbol*)(SYM_WALK_INTERN_KEYWORD_AT)))))), cons(string_wrap_literal(symbol->symbol_name), cons(integer_wrap_literal(symbol->symbol_id), NIL))), NIL);
                    collect_001 = collect_001->rest;
                  }
                }
              }
            }
            { 
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (interntrees);
            }
          }
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
        resignal();
      }
    }
  }
}

Object* Object::walk_atomic_tree(Standard_Object*& return1) {
  { Object* self = this;

    cerr << "walk-atomic-tree: Not defined on " << "`" << self << "'";
    { Object* return_temp = NULL;

      return1 = NULL;
      return (return_temp);
    }
  }
}

Object* Wrapper::walk_atomic_tree(Standard_Object*& return1) {
  { Wrapper* self = this;

    { Object* return_temp = self;

      return1 = wrapper_value_type(self);
      return (return_temp);
    }
  }
}

Surrogate* lookup_constant_symbol(Symbol* self) {
  if ((self == SYM_WALK_TRUE) ||
      (self == SYM_WALK_FALSE)) {
    return (SGT_WALK_BOOLEAN);
  }
  else if (self == SYM_WALK_NIL) {
    return (SGT_WALK_CONS);
  }
  else if (self == SYM_WALK_NULL) {
    return (SGT_WALK_UNKNOWN);
  }
  else if (self == SYM_WALK_NULL_BOOLEAN) {
    return (SGT_WALK_BOOLEAN);
  }
  else if (self == SYM_WALK_NULL_INTEGER) {
    return (SGT_WALK_INTEGER);
  }
  else if (self == SYM_WALK_NULL_FLOAT) {
    return (SGT_WALK_FLOAT);
  }
  else {
    return (NULL);
  }
}

boolean constant_symbolP(Symbol* symbol) {
  return (lookup_constant_symbol(symbol) != NULL);
}

Symbol* walk_constant_symbol(Symbol* self, Surrogate*& return1) {
  { Symbol* return_temp = self;

    return1 = lookup_constant_symbol(self);
    return (return_temp);
  }
}

Object* Symbol::walk_atomic_tree(Standard_Object*& return1) {
  { Symbol* self = this;

    if (constant_symbolP(self)) {
      { Symbol* value_001 = NULL;
        Surrogate* value_002 = NULL;

        value_001 = walk_constant_symbol(self, value_002);
        { Object* return_temp = value_001;

          return1 = value_002;
          return (return_temp);
        }
      }
    }
    { Object* return_temp = self;

      return1 = lookup_variable_type(self);
      return (return_temp);
    }
  }
}

Object* Keyword::walk_atomic_tree(Standard_Object*& return1) {
  { Keyword* self = this;

    register_symbol(self);
    { Object* return_temp = self;

      return1 = SGT_WALK_KEYWORD;
      return (return_temp);
    }
  }
}

Object* Surrogate::walk_atomic_tree(Standard_Object*& return1) {
  { Surrogate* self = this;

    register_symbol(self);
    { Object* return_temp = self;

      return1 = SGT_WALK_SURROGATE;
      return (return_temp);
    }
  }
}

boolean vrlet_expressionP(Object* tree) {
  return (consP(tree) &&
      (((Cons*)(tree))->value == SYM_WALK_VRLET));
}

boolean procedural_expressionP(Object* tree) {
  { boolean test_value_001 = FALSE;

    test_value_001 = consP(tree);
    if (test_value_001) {
      if (((Cons*)(tree))->value == SYM_WALK_VRLET) {
        test_value_001 = TRUE;
      }
      else {
        { boolean foundP_001 = FALSE;

          { Object* term = NULL;
            Cons* iter_001 = ((Cons*)(tree))->rest;

            while (!nilP(iter_001)) {
              {
                term = iter_001->value;
                iter_001 = iter_001->rest;
              }
              if (procedural_expressionP(term)) {
                foundP_001 = TRUE;
                break;
              }
            }
          }
          test_value_001 = foundP_001;
        }
      }
    }
    { boolean value_001 = test_value_001;

      return (value_001);
    }
  }
}

boolean substitute_once(Object* expression, Object* newtree, Object* oldtree) {
  { Object* expression_001 = expression;

    if (consP(expression)) {
      { Cons* expression = NULL;

        expression = ((Cons*)(expression_001));
        if (!nilP(expression)) {
          if (eqlP(expression->value, oldtree)) {
            expression->value = newtree;
            return (TRUE);
          }
          return (substitute_once(expression->value, newtree, oldtree) ||
              substitute_once(expression->rest, newtree, oldtree));
        }
      }
    }
    else {
    }
  }
  return (FALSE);
}

Cons* transform_vrlet_expression(Cons* statement, Cons* vrexpression, Standard_Object*& return1) {
  { Cons* cursor = NULL;
    Object* laststatement = NULL;

    substitute_once(statement, KWD_WALK_PLACE_WHERE_VRLET_WAS, vrexpression);
    vrexpression->value = SYM_WALK_LET;
    cursor = vrexpression->rest->rest;
    while (cursor->non_emptyP()) {
      if (cursor->rest->emptyP()) {
        laststatement = cursor->value;
        cursor->value = statement;
        break;
      }
      cursor = cursor->rest;
    }
    substitute_once(statement, laststatement, KWD_WALK_PLACE_WHERE_VRLET_WAS);
    return (walk_a_cons_tree(vrexpression, return1));
  }
}

Cons* help_transform_boolean_procedural_expression(Object* expression, Symbol* testvariable) {
  if ((!consP(expression)) ||
      (!procedural_expressionP(expression))) {
    return (cons(listO(3, SYM_WALK_SETQ, testvariable, cons(expression, NIL)), NIL));
  }
  { Cons* exp = ((Cons*)(expression));
    Object* renamed_Operator = exp->value;
    Object* firstarg = exp->second();
    Cons* otherargs = exp->rest->rest;

    exp->rest->rest = NIL;
    free_cons_list(exp);
    if (renamed_Operator == SYM_WALK_AND) {
      if (otherargs->emptyP()) {
        return (help_transform_boolean_procedural_expression(firstarg, testvariable));
      }
      else if (procedural_expressionP(firstarg)) {
        return (help_transform_boolean_procedural_expression(firstarg, testvariable)->concatenate(cons(listO(3, SYM_WALK_WHEN, testvariable, help_transform_boolean_procedural_expression(cons(SYM_WALK_AND, otherargs->concatenate(NIL)), testvariable)->concatenate(NIL)), NIL)));
      }
      else {
        return (listO(3, listO(3, SYM_WALK_SETQ, testvariable, cons(firstarg, NIL)), listO(3, SYM_WALK_WHEN, testvariable, help_transform_boolean_procedural_expression(cons(SYM_WALK_AND, otherargs->concatenate(NIL)), testvariable)->concatenate(NIL)), NIL));
      }
    }
    else if (renamed_Operator == SYM_WALK_OR) {
      if (otherargs->emptyP()) {
        return (help_transform_boolean_procedural_expression(firstarg, testvariable));
      }
      else if (procedural_expressionP(firstarg)) {
        return (help_transform_boolean_procedural_expression(firstarg, testvariable)->concatenate(cons(listO(3, SYM_WALK_WHEN, listO(3, SYM_WALK_NOT, testvariable, NIL), help_transform_boolean_procedural_expression(cons(SYM_WALK_OR, otherargs->concatenate(NIL)), testvariable)->concatenate(NIL)), NIL)));
      }
      else {
        { Cons* otherargstest = help_transform_boolean_procedural_expression(cons(SYM_WALK_OR, otherargs->concatenate(NIL)), testvariable);

          if (otherargstest->rest->non_emptyP()) {
            otherargstest = cons(cons(SYM_WALK_PROGN, otherargstest->concatenate(NIL)), NIL);
          }
          return (cons(listO(3, SYM_WALK_IF, firstarg, cons(listO(3, SYM_WALK_SETQ, testvariable, cons(SYM_WALK_TRUE, NIL)), otherargstest->concatenate(NIL))), NIL));
        }
      }
    }
    else if (renamed_Operator == SYM_WALK_NOT) {
      return (help_transform_boolean_procedural_expression(firstarg, testvariable)->concatenate(cons(listO(3, SYM_WALK_SETQ, testvariable, cons(listO(3, SYM_WALK_NOT, testvariable, NIL), NIL)), NIL)));
    }
    else if (renamed_Operator == SYM_WALK_VRLET) {
      { Cons* cursor = otherargs;

        while (cursor->rest->non_emptyP()) {
          cursor = cursor->rest;
        }
        cursor->value = listO(3, SYM_WALK_SETQ, testvariable, cons(cursor->value, NIL));
      }
      return (cons(listO(3, SYM_WALK_LET, firstarg, otherargs->concatenate(NIL)), NIL));
    }
    else {
      cerr << "`" << renamed_Operator << "'" << " is not a valid case option";
    }
  }
}

Cons* transform_boolean_procedural_expression(Cons* statement, Cons* vrexpression, Standard_Object*& return1) {
  if (vrexpression->first() == SYM_WALK_VRLET) {
    return (transform_vrlet_expression(statement, vrexpression, return1));
  }
  { Symbol* testvariable = local_gensym("TEST-VALUE");
    Cons* otree = NULL;

    substitute_once(statement, testvariable, vrexpression);
    otree = ((Cons*)(walk_without_type_tree(listO(3, SYM_WALK_LET, cons(cons(testvariable, cons(SYM_WALK_FALSE, NIL)), NIL), help_transform_boolean_procedural_expression(vrexpression, testvariable)->concatenate(cons(statement, NIL))))));
    { Cons* return_temp = otree;

      return1 = SGT_WALK_BOOLEAN;
      return (return_temp);
    }
  }
}

Cons* percolate_out_boolean_vrlet_expressions(Cons* booleanexpression) {
  { Symbol* testvariable = local_gensym("TEST-VALUE");
    Cons* otree = NULL;

    otree = listO(3, SYM_WALK_VRLET, cons(cons(testvariable, cons(SYM_WALK_FALSE, NIL)), NIL), help_transform_boolean_procedural_expression(booleanexpression, testvariable)->concatenate(cons(testvariable, NIL)));
    return (otree);
  }
}

Cons* transform_procedural_expression(Cons* statement, Cons* vrexpression, Standard_Object* type, Standard_Object*& return1) {
  if (type_spec_to_base_type(type) == SGT_WALK_BOOLEAN) {
    return (transform_boolean_procedural_expression(statement, vrexpression, return1));
  }
  else {
    return (transform_vrlet_expression(statement, vrexpression, return1));
  }
}

Cons* percolate_out_vrlet_expression(Cons* statement, Cons* vrexpression, Standard_Object* type, Standard_Object*& return1) {
  { Object* laststatement = NULL;
    Cons* cursor = vrexpression->rest->rest;

    while (cursor->non_emptyP()) {
      if (cursor->rest->emptyP()) {
        laststatement = cursor->value;
        cursor->value = KWD_WALK_PLACE_WHERE_LAST_EXPRESSION_WAS;
        break;
      }
      cursor = cursor->rest;
    }
    substitute_once(statement, laststatement, vrexpression);
    substitute_once(vrexpression, statement, KWD_WALK_PLACE_WHERE_LAST_EXPRESSION_WAS);
    { Cons* return_temp = vrexpression;

      return1 = type;
      return (return_temp);
    }
  }
}

Cons* walk_setq_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    bad_argument_countP(tree, 2);
    { Object* variable = tree->second();
      Object* value = tree->third();
      Standard_Object* variabletype = NULL;
      Object* ovalue = NULL;
      Standard_Object* otype = NULL;

      if (!(symbolP(variable))) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Illegal first argument to 'setq'; should be a symbol: " << "`" << de_uglify_parse_tree(variable) << "'" << "." << endl;
                }
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
              resignal();
            }
          }
        }
        return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
      }
      variabletype = lookup_variable_type(((Symbol*)(variable)));
      ovalue = walk_expression_tree(value, variabletype, SYM_WALK_SETQ, TRUE, otype);
      tree->third_setter(ovalue);
      if (!(procedural_expressionP(ovalue))) {
        if (walking_expressionP() &&
            (!(translator_output_language() == KWD_WALK_COMMON_LISP))) {
          return (set_target_language_type(sys_tree(tree, otype, dummy1), type_spec_to_base_type(variabletype), return1));
        }
        { Cons* return_temp = tree;

          return1 = otype;
          return (return_temp);
        }
      }
      free_transient_type_spec(otype);
      return (transform_procedural_expression(tree, ((Cons*)(ovalue)), ((otype == SGT_WALK_UNKNOWN) ? ((Standard_Object*)(variabletype)) : ((Standard_Object*)(otype))), return1));
    }
  }
}

Cons* yield_fixed_slot_value_setter_tree(Slot* slot, Object* objectref, Object* valuetree) {
  { Standard_Object* dummy1;

    return (listO(3, SYM_WALK_SYS_SLOT_VALUE_SETTER, slot->slot_owner, cons(slot->slot_name, cons(objectref, cons(walk_expression_tree(valuetree, slot->type(), SYM_WALK_SLOT_VALUE_SETTER, FALSE, dummy1), NIL)))));
  }
}

Cons* walk_setf_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;
    Standard_Object* dummy3;

    { Cons* place = NULL;

      if (consP(tree->second())) {
        place = ((Cons*)(tree->second()));
      }
      if (!((place != NULL) &&
          (symbolP(place->first()) &&
           (place->length() >= (((place->first() == SYM_WALK_SLOT_VALUE) ? ((int)(3)) : ((int)(2)))))))) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Illegal place argument in 'setf' expression: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                }
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
              resignal();
            }
          }
        }
        return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
      }
      if (bad_argument_countP(tree, 2)) {
        return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
      }
      { Object* objectref = NULL;
        Standard_Object* objecttype = NULL;

        objectref = walk_a_tree(place->second(), objecttype);
        objectref = coerce_a_tree(objectref, objecttype, objecttype, dummy1);
        { Class* objectclass = type_spec_to_class(objecttype);
          Object* slotname = place->first();
          Slot* slot = safe_lookup_slot(objectclass, ((Symbol*)(slotname)));
          Standard_Object* slottype = NULL;
          Method_Slot* settermethod = NULL;
          Cons* otherplacearguments = place->rest->rest;
          Cons* otree = NIL;

          if (slot != NULL) {
            slottype = slot->compute_return_type_spec(objecttype);
          }
          { Object* valueref = NULL;
            Standard_Object* valuetypespec = NULL;

            valueref = walk_expression_tree(tree->third(), slottype, SYM_WALK_SETF, TRUE, valuetypespec);
            if (procedural_expressionP(valueref)) {
              tree->third_setter(valueref);
              { Cons* otree = NULL;
                Standard_Object* otypespec = NULL;

                otree = transform_procedural_expression(tree, ((Cons*)(valueref)), valuetypespec, otypespec);
                free_transient_type_spec(valuetypespec);
                { Cons* return_temp = otree;

                  return1 = otypespec;
                  return (return_temp);
                }
              }
            }
            place->rest->rest = NIL;
            free_cons_list(place);
            free_cons_list(tree);
            free_transient_type_spec(objecttype);
            if (slotname == SYM_WALK_SLOT_VALUE) {
              return (walk_a_cons_tree(listO(3, SYM_WALK_SLOT_VALUE_SETTER, objectref, cons(valueref, otherplacearguments->concatenate(NIL))), return1));
            }
            { Slot* slot_001 = slot;

              if (storage_slotP(slot)) {
                { Storage_Slot* slot = NULL;

                  slot = ((Storage_Slot*)(slot_001));
                  settermethod = ((Method_Slot*)(((slot->writer() != NULL) ? ((Slot*)(safe_lookup_slot(objectclass, slot->writer()))) : ((Slot*)(safe_lookup_slot(objectclass, yield_setter_method_name(((Symbol*)(slotname)))))))));
                  if (settermethod != NULL) {
                    return (walk_a_cons_tree(cons(settermethod->slot_name, cons(objectref, cons(valueref, otherplacearguments->concatenate(NIL)))), return1));
                  }
                  if (system_defined_slot_writerP(slot)) {
                    { Object* value_001 = NULL;
                      Standard_Object* value_002 = NULL;

                      value_001 = sys_tree_if_needed(slot, listO(3, SYM_WALK_SYS_CALL_METHOD, slot->slot_owner, cons(yield_setter_method_name(((Symbol*)(slotname))), cons(objectref, cons(walk_expression_tree(valueref, slottype, SYM_WALK_SETF, FALSE, dummy2), NIL)))), objecttype, slottype, value_002);
                      { Cons* return_temp = ((Cons*)(value_001));

                        return1 = value_002;
                        return (return_temp);
                      }
                    }
                  }
                  otree = yield_slot_value_setter_tree(slot, objectref, objecttype, valueref, slottype, NULL, dummy3);
                  if (procedural_expressionP(otree)) {
                    { Cons* return_temp = otree;

                      return1 = slottype;
                      return (return_temp);
                    }
                  }
                  else {
                    { Object* value_003 = NULL;
                      Standard_Object* value_004 = NULL;

                      value_003 = sys_tree_if_needed(slot, otree, objecttype, slottype, value_004);
                      { Cons* return_temp = ((Cons*)(value_003));

                        return1 = value_004;
                        return (return_temp);
                      }
                    }
                  }
                }
              }
              else {
                return (walk_a_cons_tree(cons(yield_setter_method_name(((Symbol*)(slotname))), cons(objectref, cons(valueref, otherplacearguments->concatenate(NIL)))), return1));
              }
            }
          }
        }
      }
    }
  }
}

Cons* yield_dynamic_slot_value_tree(Storage_Slot* slot, Object* objectref, Standard_Object* returntype) {
  if (standard_dynamic_slot_accessP(slot)) {
    return (yield_standard_dynamic_slot_value_tree(slot, objectref, returntype));
  }
  { Keyword* test_value_001 = slot->allocation();

    if (test_value_001 == KWD_WALK_DYNAMIC) {
      { Symbol* answervar = local_gensym("ANSWER");

        return (listO(5, SYM_WALK_VRLET, cons(cons(answervar, cons(returntype, cons(type_to_null_value_tree(slot->type()), NIL))), NIL), listO(9, SYM_WALK_FOREACH, SYM_WALK_IT, SYM_WALK_ON, listO(3, SYM_WALK_DYNAMIC_SLOTS, objectref, NIL), SYM_WALK_WHERE, listO(4, SYM_WALK_EQp, listO(3, SYM_WALK_KEY, SYM_WALK_IT, NIL), listO(3, SYM_WALK_BQUOTE, slot->slot_name, NIL), NIL), SYM_WALK_DO, (slot_value_is_bare_literalP(slot) ? ((Cons*)(listO(4, SYM_WALK_LET, cons(listO(3, SYM_WALK_WRAPPEDVALUE, slot->type()->type_to_wrapped_type(), cons(listO(3, SYM_WALK_VALUE, SYM_WALK_IT, NIL), NIL)), NIL), listO(3, SYM_WALK_SETQ, answervar, cons(listO(3, SYM_WALK_WRAPPER_VALUE, SYM_WALK_WRAPPEDVALUE, NIL), NIL)), NIL))) : ((Cons*)(listO(3, SYM_WALK_SETQ, answervar, cons(listO(3, SYM_WALK_VALUE, SYM_WALK_IT, NIL), NIL))))), cons(cons(SYM_WALK_BREAK, NIL), NIL)), answervar, NIL));
      }
    }
    else if (test_value_001 == KWD_WALK_BIT) {
      cerr << "Allocation :bit IS NOT YET IMPLEMENTED";
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

Cons* yield_dynamic_slot_value_setter_tree(Storage_Slot* slot, Object* objectref, Object* valueref, Standard_Object* returntype) {
  { Symbol* slotname = slot->slot_name;

    if (standard_dynamic_slot_accessP(slot)) {
      return (yield_standard_dynamic_slot_value_setter_tree(slot, objectref, valueref, returntype));
    }
    { Keyword* test_value_001 = slot->allocation();

      if (test_value_001 == KWD_WALK_DYNAMIC) {
        return (listO(6, SYM_WALK_VRLET, listO(4, listO(3, SYM_WALK_DYNAMICSLOTS, listO(3, SYM_WALK_DYNAMIC_SLOTS, objectref, NIL), NIL), listO(3, SYM_WALK_NEWVALUE, valueref, NIL), listO(3, SYM_WALK_FOUNDMATCHINGENTRYp, SYM_WALK_FALSE, NIL), NIL), listO(9, SYM_WALK_FOREACH, SYM_WALK_IT, SYM_WALK_ON, SYM_WALK_DYNAMICSLOTS, SYM_WALK_WHERE, listO(4, SYM_WALK_EQp, listO(3, SYM_WALK_KEY, SYM_WALK_IT, NIL), listO(3, SYM_WALK_BQUOTE, slotname, NIL), NIL), SYM_WALK_DO, (slot_value_is_bare_literalP(slot) ? ((Cons*)(listO(4, SYM_WALK_LET, cons(listO(3, SYM_WALK_OLDVALUE, type_to_symbol(slot->type()->type_to_wrapped_type()), cons(listO(3, SYM_WALK_VALUE, SYM_WALK_IT, NIL), NIL)), NIL), listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_WRAPPER_VALUE, SYM_WALK_OLDVALUE, NIL), SYM_WALK_NEWVALUE, NIL), NIL))) : ((Cons*)(listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_VALUE, SYM_WALK_IT, NIL), SYM_WALK_NEWVALUE, NIL)))), cons(listO(4, SYM_WALK_SETQ, SYM_WALK_FOUNDMATCHINGENTRYp, SYM_WALK_TRUE, NIL), NIL)), listO(4, SYM_WALK_WHEN, listO(4, SYM_WALK_AND, listO(3, SYM_WALK_NOT, SYM_WALK_FOUNDMATCHINGENTRYp, NIL), listO(3, SYM_WALK_DEFINEDp, SYM_WALK_NEWVALUE, NIL), NIL), listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_THE_KV_LIST, SYM_WALK_DYNAMICSLOTS, NIL), listO(4, SYM_WALK_KV_CONS, listO(3, SYM_WALK_BQUOTE, slotname, NIL), (slot_value_is_bare_literalP(slot) ? ((Object*)(listO(3, SYM_WALK_WRAP_LITERAL, SYM_WALK_NEWVALUE, NIL))) : ((Object*)(((Object*)(SYM_WALK_NEWVALUE))))), cons(listO(3, SYM_WALK_THE_KV_LIST, SYM_WALK_DYNAMICSLOTS, NIL), NIL)), NIL), NIL), SYM_WALK_NEWVALUE, NIL));
      }
      else if (test_value_001 == KWD_WALK_BIT) {
        cerr << "Allocation :bit IS NOT YET IMPLEMENTED";
      }
      else {
        cerr << "`" << test_value_001 << "'" << " is not a valid case option";
      }
    }
  }
}

Cons* yield_native_slot_value_tree(Storage_Slot* slot, Object* objectref, Standard_Object* objecttype) {
  { Standard_Object* dummy1;

    slot = canonical_slot(slot);
    { boolean mixinslotP = ((Class*)(slot->slot_owner->surrogate_value))->mixinP;
      Class* objectclass = type_spec_to_class(objecttype);

      if (mixinslotP &&
          translate_to_single_inheritance_languageP()) {
        if (objectclass->mixinP) {
          return (sys_tree(listO(4, SYM_WALK_SYS_CALL_METHOD, SGT_WALK_OBJECT, yield_native_slot_reader_name(slot), cons(objectref, NIL)), ((((Compound_Type_Specifier*)(dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, NULL))) != NULL) ? ((Standard_Object*)(((Compound_Type_Specifier*)(dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, NULL))))) : ((Standard_Object*)(slot->slot_base_type))), dummy1));
        }
      }
      if (slot->slot_hardwiredP) {
        return (listO(3, SYM_WALK_SYS_CALL_METHOD, objectclass->class_type, cons(slot->slot_name, cons(objectref, NIL))));
      }
      else {
        return (listO(3, SYM_WALK_SYS_SLOT_VALUE, objectclass->class_type, cons(slot->slot_name, cons(objectref, NIL))));
      }
    }
  }
}

Cons* yield_context_sensitive_slot_value_tree(Storage_Slot* slot, Object* objectref, Standard_Object* returntype, Cons* csoptions, Standard_Object*& return1) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;

    { boolean contextsensitiveP = !((csoptions != NULL) &&
          (search_plist(csoptions, KWD_WALK_CONTEXT_SENSITIVEp) == SYM_WALK_FALSE));
      Symbol* dontinheritP = (((csoptions != NULL) &&
          (search_plist(csoptions, KWD_WALK_DONT_INHERITp) == SYM_WALK_TRUE)) ? ((Symbol*)(SYM_WALK_TRUE)) : ((Symbol*)(SYM_WALK_FALSE)));
      Object* objectrefcopy = objectref;
      boolean onceonlywrapperP = contextsensitiveP &&
          consP(objectref);
      boolean literalslotP = slot_value_is_bare_literalP(slot);
      Surrogate* realbasetype = slot->slot_base_type;
      Compound_Type_Specifier* realtypespec = ((Compound_Type_Specifier*)(dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, NULL)));
      Object* oldvaluetree = NULL;
      Symbol* oldvalueref = local_gensym("OLD-VALUE");
      Cons* accesstree = NULL;

      if (onceonlywrapperP) {
        objectref = local_gensym("OBJECT");
        push_variable_binding(((Symbol*)(objectref)), slot->slot_owner);
      }
      else {
        objectref = sys_tree(walk_without_type_tree(objectref), slot->slot_owner, dummy1);
      }
      slot->slot_base_type = SGT_WALK_OBJECT;
      if (realtypespec != NULL) {
        set_dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, NULL, NULL);
      }
      slot->slot_context_sensitiveP = FALSE;
      oldvaluetree = sys_tree(walk_without_type_tree(listO(3, SYM_WALK_SLOT_VALUE, (contextsensitiveP ? ((Object*)(copy_cons_tree(objectref))) : ((Object*)(objectref))), cons(slot->slot_name, NIL))), SGT_WALK_OBJECT, dummy2);
      slot->slot_base_type = realbasetype;
      if (realtypespec != NULL) {
        set_dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, realtypespec, NULL);
      }
      slot->slot_context_sensitiveP = TRUE;
      if (!contextsensitiveP) {
        { Cons* return_temp = ((Cons*)(oldvaluetree));

          return1 = SGT_WALK_OBJECT;
          return (return_temp);
        }
      }
      if (onceonlywrapperP) {
        pop_variable_binding();
      }
      accesstree = listO(4, SYM_WALK_SAFE_CAST, listO(3, SYM_WALK_ACCESS_IN_CONTEXT, (onceonlywrapperP ? ((Object*)(oldvalueref)) : ((Object*)(oldvaluetree))), cons(objectref, cons(dontinheritP, NIL))), yield_type_spec_tree((literalslotP ? ((Standard_Object*)(slot->type()->type_to_wrapped_type())) : ((Standard_Object*)(returntype)))), NIL);
      if (literalslotP) {
        accesstree = listO(3, SYM_WALK_WRAPPER_VALUE, accesstree, NIL);
      }
      if (onceonlywrapperP) {
        { Cons* return_temp = listO(4, SYM_WALK_VRLET, listO(3, cons(objectref, cons(objectrefcopy, NIL)), cons(oldvalueref, cons(oldvaluetree, NIL)), NIL), accesstree, NIL);

          return1 = returntype;
          return (return_temp);
        }
      }
      else {
        { Cons* return_temp = ((Cons*)(walk_without_type_tree(accesstree)));

          return1 = returntype;
          return (return_temp);
        }
      }
    }
  }
}

Cons* yield_slot_value_tree(Storage_Slot* slot, Object* objectref, Standard_Object* objecttype, Standard_Object* returntype, Cons* csoptions, Standard_Object*& return1) {
  if (slot->slot_context_sensitiveP) {
    return (yield_context_sensitive_slot_value_tree(slot, objectref, returntype, csoptions, return1));
  }
  else {
    if (slot->dynamic_storageP()) {
      { Cons* return_temp = ((Cons*)(walk_without_type_tree(yield_dynamic_slot_value_tree(slot, objectref, returntype))));

        return1 = returntype;
        return (return_temp);
      }
    }
    else {
      { Cons* return_temp = yield_native_slot_value_tree(slot, objectref, objecttype);

        return1 = returntype;
        return (return_temp);
      }
    }
  }
}

Cons* walk_slot_value_tree(Cons* tree, Standard_Object*& return1) {
  { Object* objectref = NULL;
    Standard_Object* objecttype = NULL;

    objectref = walk_a_tree(tree->second(), objecttype);
    { Object* slotname = tree->third();
      Cons* csoptions = tree->nth_rest(3);
      Class* objectclass = type_spec_to_class(objecttype);
      Slot* slot = safe_lookup_slot(objectclass, ((Symbol*)(slotname)));
      Cons* otree = NULL;
      Standard_Object* otype = NULL;

      if (slot == NULL) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Can't read a non-existent slot " << "`" << de_uglify_parse_tree(slotname) << "'" << endl << "   on the class " << "`" << class_name(objectclass) << "'" << "." << endl;
                }
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
              resignal();
            }
          }
        }
        return (walk_dont_call_me_tree(tree, SGT_WALK_UNKNOWN, return1));
      }
      { Slot* slot_001 = slot;

        if (method_slotP(slot)) {
          { Method_Slot* slot = NULL;

            slot = ((Method_Slot*)(slot_001));
            { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Can't read the method slot " << "`" << de_uglify_parse_tree(slot) << "'" << " by calling 'slot-value'" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_002;
                  resignal();
                }
              }
            }
          }
        }
        else if (storage_slotP(slot)) {
          { Storage_Slot* slot = NULL;

            slot = ((Storage_Slot*)(slot_001));
            otype = slot->compute_return_type_spec(objecttype);
            otree = yield_slot_value_tree(slot, objectref, objecttype, otype, csoptions, otype);
            free_cons_list(tree);
            if (procedural_expressionP(otree)) {
              { Cons* return_temp = otree;

                return1 = otype;
                return (return_temp);
              }
            }
            else {
              { Object* value_001 = NULL;
                Standard_Object* value_002 = NULL;

                value_001 = sys_tree_if_needed(slot, otree, objecttype, otype, value_002);
                { Cons* return_temp = ((Cons*)(value_001));

                  return1 = value_002;
                  return (return_temp);
                }
              }
            }
          }
        }
        else {
          cerr << "`" << slot << "'" << " is not a valid case option";
        }
      }
    }
  }
}

Cons* yield_native_slot_value_setter_tree(Storage_Slot* slot, Object* objectref, Standard_Object* objecttype, Object* valueref) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;

    slot = canonical_slot(slot);
    { boolean mixinslotP = ((Class*)(slot->slot_owner->surrogate_value))->mixinP;
      Class* objectclass = type_spec_to_class(objecttype);

      if (mixinslotP &&
          translate_to_single_inheritance_languageP()) {
        if (objectclass->mixinP) {
          return (sys_tree(listO(4, SYM_WALK_SYS_CALL_METHOD, SGT_WALK_OBJECT, yield_native_slot_reader_name(slot), cons(objectref, cons(valueref, NIL))), ((((Compound_Type_Specifier*)(dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, NULL))) != NULL) ? ((Standard_Object*)(((Compound_Type_Specifier*)(dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, NULL))))) : ((Standard_Object*)(slot->slot_base_type))), dummy1));
        }
      }
      if (slot->slot_hardwiredP) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Can't set the value of the hardwired slot " << "`" << slot->slot_owner << "'" << "." << "`" << slot->slot_name << "'" << "." << endl;
                }
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
              resignal();
            }
          }
        }
        return (walk_dont_call_me_tree(NULL, slot->slot_base_type, dummy2));
      }
      return (listO(3, SYM_WALK_SYS_SLOT_VALUE_SETTER, objectclass->class_type, cons(slot->slot_name, cons(objectref, cons(valueref, NIL)))));
    }
  }
}

Cons* yield_context_sensitive_slot_value_setter_tree(Storage_Slot* slot, Object* objectref, Object* valueref, Standard_Object* returntype, Cons* csoptions, Standard_Object*& return1) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;
    Standard_Object* dummy3;

    { boolean contextsensitiveP = !((csoptions != NULL) &&
          (search_plist(csoptions, KWD_WALK_CONTEXT_SENSITIVEp) == SYM_WALK_FALSE));
      Symbol* copytochildren = (((csoptions != NULL) &&
          (search_plist(csoptions, KWD_WALK_COPY_TO_CHILDRENp) == SYM_WALK_TRUE)) ? ((Symbol*)(SYM_WALK_TRUE)) : ((Symbol*)(SYM_WALK_FALSE)));
      Surrogate* realbasetype = slot->slot_base_type;
      Compound_Type_Specifier* realtypespec = ((Compound_Type_Specifier*)(dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, NULL)));
      Symbol* objectvar = NULL;
      Symbol* valuevar = NULL;
      Symbol* oldvaluevar = NULL;
      Symbol* newvaluevar = NULL;
      Cons* oldvaluetree = NULL;
      Cons* setnewvaluetree = NULL;

      slot->slot_base_type = SGT_WALK_OBJECT;
      if (realtypespec != NULL) {
        set_dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, NULL, NULL);
      }
      slot->slot_context_sensitiveP = FALSE;
      if (contextsensitiveP) {
        objectvar = local_gensym("OBJECT");
        valuevar = local_gensym("VALUE");
        oldvaluevar = local_gensym("OLD-VALUE");
        newvaluevar = local_gensym("NEW-VALUE");
        push_variable_binding(objectvar, slot->slot_owner);
        push_variable_binding(newvaluevar, SGT_WALK_OBJECT);
        oldvaluetree = sys_tree(walk_without_type_tree(listO(3, SYM_WALK_SLOT_VALUE, objectvar, cons(slot->slot_name, NIL))), SGT_WALK_OBJECT, dummy1);
        setnewvaluetree = sys_tree(walk_without_type_tree(listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_SLOT_VALUE, objectvar, cons(slot->slot_name, NIL)), newvaluevar, NIL)), SGT_WALK_OBJECT, dummy2);
      }
      else {
        setnewvaluetree = sys_tree(walk_without_type_tree(listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_SLOT_VALUE, objectref, cons(slot->slot_name, NIL)), valueref, NIL)), SGT_WALK_OBJECT, dummy3);
      }
      slot->slot_base_type = realbasetype;
      if (realtypespec != NULL) {
        set_dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, realtypespec, NULL);
      }
      slot->slot_context_sensitiveP = TRUE;
      if (!contextsensitiveP) {
        { Cons* return_temp = setnewvaluetree;

          return1 = SGT_WALK_OBJECT;
          return (return_temp);
        }
      }
      pop_variable_binding();
      pop_variable_binding();
      { Cons* return_temp = listO(5, SYM_WALK_VRLET, listO(5, cons(objectvar, cons(objectref, NIL)), cons(valuevar, cons(realbasetype, cons(valueref, NIL))), cons(oldvaluevar, cons(oldvaluetree, NIL)), cons(newvaluevar, cons(listO(3, SYM_WALK_UPDATE_IN_CONTEXT, oldvaluevar, cons(valuevar, cons(objectvar, cons(copytochildren, NIL)))), NIL)), NIL), listO(4, SYM_WALK_WHEN, listO(3, SYM_WALK_NOT, listO(3, SYM_WALK_CS_VALUEp, oldvaluevar, NIL), NIL), setnewvaluetree, NIL), valuevar, NIL);

        return1 = returntype;
        return (return_temp);
      }
    }
  }
}

Cons* yield_slot_value_setter_tree(Storage_Slot* slot, Object* objectref, Standard_Object* objecttype, Object* valueref, Standard_Object* returntype, Cons* csoptions, Standard_Object*& return1) {
  if (slot->slot_context_sensitiveP) {
    return (yield_context_sensitive_slot_value_setter_tree(slot, objectref, valueref, returntype, csoptions, return1));
  }
  else {
    if (slot->dynamic_storageP()) {
      { Cons* return_temp = ((Cons*)(walk_without_type_tree(yield_dynamic_slot_value_setter_tree(slot, objectref, valueref, returntype))));

        return1 = returntype;
        return (return_temp);
      }
    }
    else {
      { Cons* return_temp = yield_native_slot_value_setter_tree(slot, objectref, objecttype, valueref);

        return1 = returntype;
        return (return_temp);
      }
    }
  }
}

Cons* walk_slot_value_setter_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    { Object* objectref = NULL;
      Standard_Object* objecttype = NULL;

      objectref = walk_a_tree(tree->second(), objecttype);
      { Object* slotname = tree->fourth();
        Cons* csoptions = tree->nth_rest(4);
        Class* objectclass = type_spec_to_class(objecttype);
        Storage_Slot* slot = ((Storage_Slot*)(safe_lookup_slot(objectclass, ((Symbol*)(slotname)))));
        Object* valueref = NULL;
        Cons* otree = NULL;
        Standard_Object* otype = NULL;

        if (slot == NULL) {
          { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  signal_translation_error();
                  if (!(suppress_warningsP())) {
                    print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                    cout << endl << " " << "Can't set a non-existent slot " << "`" << de_uglify_parse_tree(slotname) << "'" << endl << "   on the class " << "`" << class_name(objectclass) << "'" << "." << endl;
                  }
                  oPRINTREADABLYpo = old_OprintreadablyPO_001;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
                resignal();
              }
            }
          }
          return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
        }
        { Storage_Slot* slot_001 = slot;

          if (method_slotP(slot)) {
            { Method_Slot* slot = NULL;

              slot = ((Method_Slot*)(slot_001));
              { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_error();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Can't set the method slot " << "`" << de_uglify_parse_tree(slot) << "'" << " by calling 'slot-value-setter'" << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    resignal();
                  }
                }
              }
            }
          }
          else if (storage_slotP(slot)) {
            { Storage_Slot* slot = NULL;

              slot = ((Storage_Slot*)(slot_001));
              otype = slot->compute_return_type_spec(objecttype);
              valueref = walk_expression_tree(tree->third(), otype, SYM_WALK_SLOT_VALUE_SETTER, FALSE, dummy1);
              otree = yield_slot_value_setter_tree(slot, objectref, objecttype, valueref, otype, csoptions, otype);
              free_cons_list(tree);
              if (procedural_expressionP(otree)) {
                { Cons* return_temp = otree;

                  return1 = otype;
                  return (return_temp);
                }
              }
              else {
                { Object* value_001 = NULL;
                  Standard_Object* value_002 = NULL;

                  value_001 = sys_tree_if_needed(slot, otree, objecttype, otype, value_002);
                  { Cons* return_temp = ((Cons*)(value_001));

                    return1 = value_002;
                    return (return_temp);
                  }
                }
              }
            }
          }
          else {
            cerr << "`" << slot << "'" << " is not a valid case option";
          }
        }
      }
    }
  }
}

Standard_Object* safe_yield_type_specifier(Object* typetree) {
  if (typetree != NULL) {
    { Standard_Object* typespec = typetree->yield_type_specifier();

      validate_type_specifier(typespec, NULL, TRUE);
      return (typespec);
    }
  }
  else {
    return (NULL);
  }
}

Cons* walk_a_declaration(Symbol* variable, Object* typetree, Object* value, boolean inputparameterP) {
  { Standard_Object* sourcetype = NULL;
    Standard_Object* targettype = safe_yield_type_specifier(typetree);
    Surrogate* methodownertype = ((oMETHODBEINGWALKEDo != NULL) ? ((Surrogate*)(oMETHODBEINGWALKEDo->slot_owner)) : ((Surrogate*)(NULL)));
    Object* ovalue = NULL;

    if ((targettype != NULL) &&
        ((methodownertype != NULL) &&
         (!voidP(methodownertype)))) {
      targettype = compute_relative_type_spec(targettype, methodownertype);
    }
    if (!(inputparameterP)) {
      push_variable_binding(variable, SGT_WALK_UNINITIALIZED);
      ovalue = walk_expression_tree(value, targettype, SYM_WALK_VARIABLE_DECLARATION, TRUE, sourcetype);
      if (targettype == NULL) {
        targettype = sourcetype;
      }
      pop_variable_binding();
    }
    push_variable_binding(variable, targettype);
    if (inputparameterP) {
      return (cons(variable, cons(targettype, NIL)));
    }
    else {
      return (cons(variable, cons(targettype, cons(ovalue, NIL))));
    }
  }
}

Cons* walk_variable_declarations(Cons* declarations) {
  { Cons* odeclarations = NIL;
    Symbol* variable = NULL;

    { Object* decl = NULL;
      Cons* iter_001 = declarations;

      while (!nilP(iter_001)) {
        {
          decl = iter_001->value;
          iter_001 = iter_001->rest;
        }
        { Object* decl_001 = decl;

          if (consP(decl)) {
            { Cons* decl = NULL;

              decl = ((Cons*)(decl_001));
              if (!symbolP(decl->first())) {
                { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_error();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Illegal variable in `let' declaration: " << "`" << de_uglify_parse_tree(decl) << "'" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      resignal();
                    }
                  }
                }
                variable = SYM_WALK_ILLEGAL_VARIABLE;
              }
              else {
                variable = ((Symbol*)(decl->first()));
                if (variable->lookup_global_variable() != NULL) {
                  { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                    { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oPRINTREADABLYpo = TRUE;
                          signal_translation_error();
                          if (!(suppress_warningsP())) {
                            print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                            cout << endl << " " << "Illegal binding of global or special variable " << "in `let' declaration:" << endl << "    " << "`" << de_uglify_parse_tree(decl) << "'" << "." << endl;
                          }
                          oPRINTREADABLYpo = old_OprintreadablyPO_002;
                        }
                        oEXCEPTIONo = NULL;
                      }
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                    }
                    if (oEXCEPTIONo != NULL) {
                      if (TRUE) {
                        oPRINTREADABLYpo = old_OprintreadablyPO_002;
                        resignal();
                      }
                    }
                  }
                  variable = SYM_WALK_ILLEGAL_VARIABLE;
                }
              }
              switch (decl->length()) {
                case 1: 
                  { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

                    { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oPRINTREADABLYpo = TRUE;
                          signal_translation_error();
                          if (!(suppress_warningsP())) {
                            print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                            cout << endl << " " << "Missing argument(s) in `let' declaration: " << "`" << de_uglify_parse_tree(decl) << "'" << "." << endl;
                          }
                          oPRINTREADABLYpo = old_OprintreadablyPO_003;
                        }
                        oEXCEPTIONo = NULL;
                      }
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                    }
                    if (oEXCEPTIONo != NULL) {
                      if (TRUE) {
                        oPRINTREADABLYpo = old_OprintreadablyPO_003;
                        resignal();
                      }
                    }
                  }
                break;
                case 2: 
                  if (decl->second() == SYM_WALK_NULL) {
                    { boolean old_OprintreadablyPO_004 = oPRINTREADABLYpo;

                      { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                        oEXCEPTIONHANDLERADDRESSo = NULL;
                        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                          {
                            oPRINTREADABLYpo = TRUE;
                            signal_translation_error();
                            if (!(suppress_warningsP())) {
                              print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                              cout << endl << " " << "Missing type specifier in `let' declaration: " << "`" << de_uglify_parse_tree(decl) << "'" << "." << endl;
                            }
                            oPRINTREADABLYpo = old_OprintreadablyPO_004;
                          }
                          oEXCEPTIONo = NULL;
                        }
                        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
                      }
                      if (oEXCEPTIONo != NULL) {
                        if (TRUE) {
                          oPRINTREADABLYpo = old_OprintreadablyPO_004;
                          resignal();
                        }
                      }
                    }
                  }
                  odeclarations = cons(walk_a_declaration(variable, NULL, decl->second(), FALSE), odeclarations);
                break;
                case 3: 
                  odeclarations = cons(walk_a_declaration(variable, decl->second(), decl->third(), FALSE), odeclarations);
                break;
                default:
                  { boolean old_OprintreadablyPO_005 = oPRINTREADABLYpo;

                    { jump_buffer old_OexceptionhandleraddressO_005 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oPRINTREADABLYpo = TRUE;
                          signal_translation_error();
                          if (!(suppress_warningsP())) {
                            print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                            cout << endl << " " << "Too many terms in `let' declaration:" << "`" << de_uglify_parse_tree(decl) << "'" << "." << endl;
                          }
                          oPRINTREADABLYpo = old_OprintreadablyPO_005;
                        }
                        oEXCEPTIONo = NULL;
                      }
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_005;
                    }
                    if (oEXCEPTIONo != NULL) {
                      if (TRUE) {
                        oPRINTREADABLYpo = old_OprintreadablyPO_005;
                        resignal();
                      }
                    }
                  }
                break;
              }
              free_cons_list(decl);
            }
          }
          else {
            { boolean old_OprintreadablyPO_006 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_006 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Illegal `let' declaration: " << "`" << de_uglify_parse_tree(decl) << "'" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_006;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_006;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_006;
                  resignal();
                }
              }
            }
          }
        }
      }
    }
    free_cons_list(declarations);
    return (odeclarations->reverse());
  }
}

Cons* transform_let_with_procedural_expression(Cons* tree) {
  { Cons* firstdeclaration = ((Cons*)(((Cons*)(tree->second()))->first()));
    Object* typetree = firstdeclaration->second();
    Cons* typetreecons = firstdeclaration->rest;
    Object* vrlettree = walk_without_type_tree(firstdeclaration->third());

    if (typetree == SGT_WALK_UNKNOWN) {
      firstdeclaration->rest = firstdeclaration->rest->rest;
      typetreecons->free_cons();
    }
    { Cons* otree = NULL;
      Standard_Object* unusedtypespec = NULL;

      otree = transform_procedural_expression(tree, ((Cons*)(vrlettree)), ((Standard_Object*)(typetree)), unusedtypespec);
      unusedtypespec = unusedtypespec;
      return (otree);
    }
  }
}

void pop_local_variable_bindings(Cons* declarations) {
  { Object* d = NULL;
    Cons* iter_001 = declarations;

    while (!nilP(iter_001)) {
      {
        d = iter_001->value;
        iter_001 = iter_001->rest;
      }
      {
      }
      pop_variable_binding();
    }
  }
}

Cons* walk_let_tree(Cons* tree, Standard_Object*& return1) {
  tree->second_setter(walk_variable_declarations(((Cons*)(tree->second()))));
  { boolean test_value_001 = FALSE;

    { boolean foundP_001 = FALSE;

      { Cons* d = NIL;
        Cons* iter_001 = ((Cons*)(tree->second()));

        while (!nilP(iter_001)) {
          {
            d = ((Cons*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          if (procedural_expressionP(d->third())) {
            foundP_001 = TRUE;
            break;
          }
        }
      }
      test_value_001 = foundP_001;
    }
    test_value_001 = !test_value_001;
    if (test_value_001) {
      tree->rest->rest = walk_list_of_trees(tree->rest->rest);
      pop_local_variable_bindings(((Cons*)(tree->second())));
      return (sys_tree(tree, SGT_WALK_VOID, return1));
    }
  }
  pop_local_variable_bindings(((Cons*)(tree->second())));
  { Cons* originaldeclarations = ((Cons*)(tree->second()));
    Cons* leadingdeclarations = NIL;
    Cons* trailingdeclarations = NIL;
    boolean leadingP = TRUE;

    { Cons* d = NIL;
      Cons* iter_002 = ((Cons*)(originaldeclarations));

      while (!nilP(iter_002)) {
        {
          d = ((Cons*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        if (procedural_expressionP(d->third())) {
          leadingP = FALSE;
        }
        if (leadingP) {
          leadingdeclarations = cons(d, leadingdeclarations);
          push_variable_binding(((Symbol*)(d->first())), ((Standard_Object*)(d->second())));
        }
        else {
          trailingdeclarations = cons(d, trailingdeclarations);
        }
      }
    }
    leadingdeclarations = leadingdeclarations->reverse();
    trailingdeclarations = trailingdeclarations->reverse();
    tree->second_setter(trailingdeclarations);
    free_cons_list(originaldeclarations);
    tree = transform_let_with_procedural_expression(tree);
    if (leadingdeclarations->non_emptyP()) {
      pop_local_variable_bindings(leadingdeclarations);
      tree = listO(3, SYM_WALK_LET, leadingdeclarations, cons(tree, NIL));
    }
    return (walk_a_cons_tree(tree, return1));
  }
}

Key_Value_List* read_OspecialvariablestackO() {
  return (oSPECIALVARIABLESTACKo);
}

Key_Value_List* write_OspecialvariablestackO(Key_Value_List* value) {
  oSPECIALVARIABLESTACKo = value;
  return (value);
}

boolean read_OspecialsenabledPO() {
  return (oSPECIALSENABLEDpo);
}

boolean write_OspecialsenabledPO(boolean value) {
  oSPECIALSENABLEDpo = value;
  return (value);
}

int read_OnofspecialsatloopentryO() {
  return (oNOFSPECIALSATLOOPENTRYo);
}

int write_OnofspecialsatloopentryO(int value) {
  oNOFSPECIALSATLOOPENTRYo = value;
  return (value);
}

Keyword* special_implementation_style() {
  { Keyword* test_value_001 = translator_output_language();

    if (test_value_001 == KWD_WALK_COMMON_LISP) {
      return (KWD_WALK_COMMON_LISP);
    }
    else {
      return (KWD_WALK_SAVE_AND_RESTORE);
    }
  }
}

void push_special(Symbol* variable, Symbol* oldvaluevariable) {
  oSPECIALVARIABLESTACKo->the_kv_list = kv_cons(variable->soft_permanentify(), oldvaluevariable->soft_permanentify(), oSPECIALVARIABLESTACKo->the_kv_list);
}

void pop_special() {
  { Kv_Cons* kvlist = oSPECIALVARIABLESTACKo->the_kv_list;

    oSPECIALVARIABLESTACKo->the_kv_list = kvlist->rest;
    free_kv_cons(kvlist);
  }
}

Symbol* lookup_old_value_variable(Symbol* variable) {
  return (((Symbol*)(oSPECIALVARIABLESTACKo->lookup(variable))));
}

boolean need_to_unbind_specialsP() {
  return (oSPECIALSENABLEDpo &&
      ((oSPECIALVARIABLESTACKo->length() > 0) &&
       (!get_quoted_tree("((:COMMON-LISP :UNBIND-WITH-DESTRUCTORS) \"/STELLA\")", "/STELLA")->memberP(special_implementation_style()))));
}

Cons* yield_special_unbind_tree(int nofbindings) {
  { Cons* otree = NIL;

    { Keyword* test_value_001 = special_implementation_style();

      if (test_value_001 == KWD_WALK_SAVE_AND_RESTORE) {
        { Symbol* oldvaluevariable = NULL;
          Symbol* variable = NULL;
          Kv_Cons* iter_001 = oSPECIALVARIABLESTACKo->the_kv_list;

          while (iter_001 != NULL) {
            variable = ((Symbol*)(iter_001->key));
            {
              oldvaluevariable = ((Symbol*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            if ((nofbindings = nofbindings - 1) >= 0) {
              { Cons* value_001 = NULL;

                { Cons* tree = NIL;
                  Cons* iter_002 = otree;

                  while (!nilP(iter_002)) {
                    {
                      tree = ((Cons*)(iter_002->value));
                      iter_002 = iter_002->rest;
                    }
                    if (tree->second() == variable) {
                      value_001 = tree;
                      break;
                    }
                  }
                }
                otree = otree->remove(value_001);
              }
              otree = cons(listO(3, SYM_WALK_SETQ, variable, cons(oldvaluevariable, NIL)), otree);
            }
          }
        }
        return (((Cons*)(prognify(otree->reverse()))));
      }
      else {
        return (NULL);
      }
    }
  }
}

Cons* yield_return_special_unbind_tree() {
  return (yield_special_unbind_tree(oSPECIALVARIABLESTACKo->length()));
}

Cons* yield_loop_exit_special_unbind_tree() {
  return (yield_special_unbind_tree(oSPECIALVARIABLESTACKo->length() - oNOFSPECIALSATLOOPENTRYo));
}

Cons* walk_special_tree(Cons* tree, Standard_Object*& return1) {
  if (!(oSPECIALSENABLEDpo)) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            signal_translation_error();
            if (!(suppress_warningsP())) {
              print_error_context(">> ERROR: ", STANDARD_OUTPUT);
              cout << endl << " " << "'special' statement not legal in the current context: " << endl << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
            }
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
          resignal();
        }
      }
    }
    return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
  }
  { boolean test_value_001 = FALSE;

    if (tree->length() < 2) {
      test_value_001 = TRUE;
    }
    else {
      if (!consP(tree->second())) {
        test_value_001 = TRUE;
      }
      else {
        {
          { boolean alwaysP_001 = TRUE;

            { Cons* binding = NIL;
              Cons* iter_001 = ((Cons*)(tree->second()));

              while (!nilP(iter_001)) {
                {
                  binding = ((Cons*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                if (!(consP(binding) &&
                    (symbolP(binding->first()) &&
                     (binding->length() == 2)))) {
                  alwaysP_001 = FALSE;
                  break;
                }
              }
            }
            test_value_001 = alwaysP_001;
          }
          test_value_001 = !test_value_001;
        }
      }
    }
    if (test_value_001) {
      { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Illegal 'special' statement: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_002;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_002;
            resignal();
          }
        }
      }
      return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
    }
  }
  if (((Cons*)(tree->second()))->length() == 0) {
    tree->first_setter(SYM_WALK_LET);
    return (walk_let_tree(tree, return1));
  }
  { Global_Variable* variable = NULL;

    { Cons* binding = NIL;
      Cons* iter_002 = ((Cons*)(tree->second()));

      while (!nilP(iter_002)) {
        {
          binding = ((Cons*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        variable = ((Symbol*)(binding->first()))->lookup_global_variable();
        if ((variable == NULL) ||
            (!variable->variable_specialP)) {
          { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  signal_translation_error();
                  if (!(suppress_warningsP())) {
                    print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                    cout << endl << " " << "Trying to bind non-special variable " << "`" << binding->first() << "'" << endl << " in 'special' statement" << "." << endl;
                  }
                  oPRINTREADABLYpo = old_OprintreadablyPO_003;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oPRINTREADABLYpo = old_OprintreadablyPO_003;
                resignal();
              }
            }
          }
        }
      }
    }
  }
  { Keyword* test_value_002 = special_implementation_style();

    if (test_value_002 == KWD_WALK_COMMON_LISP) {
      return (walk_cl_special_tree(tree, return1));
    }
    else if (test_value_002 == KWD_WALK_SAVE_AND_RESTORE) {
      return (walk_save_and_restore_special_tree(tree, return1));
    }
    else {
      cerr << "`" << test_value_002 << "'" << " is not a valid case option";
    }
  }
}

Cons* walk_cl_special_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;
    Standard_Object* dummy3;

    { Cons* bindings = ((Cons*)(tree->second()));
      Cons* body = tree->rest->rest;
      Symbol* variablename = NULL;
      Standard_Object* variabletype = NULL;
      boolean bindviasetqP = FALSE;
      Cons* bindviasetqtrees = NIL;
      Object* otree = NULL;

      { Cons* binding = NIL;
        Cons* iter_001 = bindings;

        while (!nilP(iter_001)) {
          {
            binding = ((Cons*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          variablename = ((Symbol*)(binding->first()));
          variabletype = lookup_global_variable_type(variablename);
          if (bindviasetqP) {
            bindviasetqtrees = cons(walk_a_tree(listO(3, SYM_WALK_SETQ, variablename, cons(binding->second(), NIL)), dummy1), bindviasetqtrees);
            binding->second_setter(variabletype);
            binding->rest->rest = cons(SYM_WALK_NULL, NIL);
          }
          else {
            otree = walk_expression_tree(binding->second(), variabletype, SYM_WALK_SPECIAL, TRUE, dummy2);
            if (procedural_expressionP(otree)) {
              bindviasetqP = TRUE;
              bindviasetqtrees = cons(walk_a_tree(listO(3, SYM_WALK_SETQ, variablename, cons(otree, NIL)), dummy3), bindviasetqtrees);
              otree = SYM_WALK_NULL;
            }
            binding->second_setter(variabletype);
            binding->rest->rest = cons(otree, NIL);
          }
        }
      }
      tree->first_setter(SYM_WALK_SPECIAL);
      tree->rest->rest = bindviasetqtrees->reverse()->concatenate(walk_list_of_trees(body));
      return (sys_tree(tree, SGT_WALK_VOID, return1));
    }
  }
}

Cons* walk_save_and_restore_special_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    if (tree->first() == SYM_WALK_SPECIAL) {
      tree->first_setter(SYM_WALK_SYS_SPECIAL);
      return (walk_protected_save_and_restore_special_tree(tree, return1));
    }
    { Cons* bindings = ((Cons*)(tree->second()));
      Cons* body = tree->rest->rest;
      Symbol* variable = NULL;
      Symbol* oldvaluevariable = NULL;
      Cons* oldvaluebindings = NIL;
      Cons* bindtrees = NIL;
      Cons* unbindtrees = NIL;

      { Cons* binding = NIL;
        Cons* iter_001 = bindings;

        while (!nilP(iter_001)) {
          {
            binding = ((Cons*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          variable = ((Symbol*)(binding->first()));
          bindtrees = cons(listO(3, SYM_WALK_SETQ, variable, cons(binding->second(), NIL)), bindtrees);
          oldvaluevariable = local_gensym(string_concatenate("OLD-", variable->symbol_name));
          push_special(variable, oldvaluevariable);
          oldvaluebindings = cons(cons(oldvaluevariable, cons(variable, NIL)), oldvaluebindings);
          unbindtrees = cons(listO(3, SYM_WALK_SETQ, variable, cons(oldvaluevariable, NIL)), unbindtrees);
        }
      }
      tree = ((Cons*)(walk_a_tree(listO(3, SYM_WALK_LET, oldvaluebindings->reverse(), bindtrees->reverse()->concatenate(body->concatenate(unbindtrees->concatenate(NIL)))), dummy1)));
      { Cons* binding = NIL;
        Cons* iter_002 = bindings;

        while (!nilP(iter_002)) {
          {
            binding = ((Cons*)(iter_002->value));
            iter_002 = iter_002->rest;
          }
          binding = binding;
          pop_special();
        }
      }
      { Cons* return_temp = tree;

        return1 = SGT_WALK_VOID;
        return (return_temp);
      }
    }
  }
}

Cons* walk_protected_save_and_restore_special_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    if (!use_stella_exceptionsP()) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_warning();
              if (!(suppress_warningsP())) {
                print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                cout << endl << " " << "Protection of special-unbinding via native exception handling" << endl << " is not yet implemented" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
    }
    { Cons* specialtree = listO(3, SYM_WALK_PROGN, tree, NIL);
      Cons* oldvaluebindings = NULL;
      Cons* unbindtrees = NIL;

      tree = ((Cons*)(walk_a_tree(yield_protected_statement_tree(specialtree, TRUE), dummy1)));
      specialtree->rest = ((Cons*)(((Cons*)(specialtree->second()))->second()))->rest;
      oldvaluebindings = ((Cons*)(specialtree->second()));
      specialtree->rest = specialtree->rest->rest;
      { Cons* binding = NIL;
        Cons* iter_001 = oldvaluebindings;

        while (!nilP(iter_001)) {
          {
            binding = ((Cons*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          unbindtrees = cons(listO(3, SYM_WALK_SETQ, binding->last(), cons(binding->first(), NIL)), unbindtrees);
        }
      }
      { Object* value_001 = NULL;
        Standard_Object* value_002 = NULL;

        value_001 = walk_a_tree(listO(3, SYM_WALK_LET, oldvaluebindings, cons(tree, cons(yield_exception_handler_tree(cons(listO(3, SYM_WALK_EXCEPTION, NIL, unbindtrees->concatenate(cons(cons(SYM_WALK_RESIGNAL, NIL), NIL))), NIL)), NIL))), value_002);
        { Cons* return_temp = ((Cons*)(value_001));

          return1 = value_002;
          return (return_temp);
        }
      }
    }
  }
}

Cons* walk_cast_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;

    bad_argument_countP(tree, 2);
    { Standard_Object* typespec = tree->third()->yield_type_specifier();
      Surrogate* basetype = type_spec_to_base_type(typespec);

      tree->second_setter(walk_expression_tree(tree->second(), SGT_WALK_UNKNOWN, SYM_WALK_CAST, TRUE, dummy1));
      if (vrlet_expressionP(tree->second())) {
        return (percolate_out_vrlet_expression(tree, ((Cons*)(tree->second())), typespec, return1));
      }
      tree->third_setter(basetype);
      if ((translator_output_language() == KWD_WALK_COMMON_LISP) &&
          ((tree->first() == SYM_WALK_CAST) &&
           (oSAFETYo >= 2))) {
        register_symbol(basetype);
      }
      if (!(typespec == basetype)) {
        tree = sys_tree(tree, typespec, dummy2);
      }
      { Cons* return_temp = tree;

        return1 = typespec;
        return (return_temp);
      }
    }
  }
}

boolean values_treeP(Object* tree) {
  return (consP(tree) &&
      (SYM_WALK_VALUES == ((Cons*)(tree))->first()));
}

Cons* walk_values_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    { Object* otree = NULL;
      Standard_Object* otype = NULL;
      Cons* bindtree = NIL;
      Symbol* valuevar = NULL;
      boolean hasproceduralvalueP = FALSE;

      { Cons_Iterator* it = tree->rest->allocate_iterator();

        while (it->nextP()) {
          otree = walk_a_tree(it->value, otype);
          if (vrlet_expressionP(otree)) {
            it->value_setter(otree);
            hasproceduralvalueP = TRUE;
            break;
          }
          otree = sys_tree(otree, otype, dummy1);
          if (voidP(otype)) {
            otree = ((Cons*)(otree))->concatenate(cons(SGT_WALK_VOID, NIL));
          }
          it->value_setter(otree);
        }
      }
      if (!hasproceduralvalueP) {
        tree->first_setter(SYM_WALK_PROGN);
        { Cons* return_temp = tree;

          return1 = SGT_WALK_VOID;
          return (return_temp);
        }
      }
      { Cons_Iterator* it = tree->rest->allocate_iterator();

        while (it->nextP()) {
          { Cons* value = ((Cons*)(it->value));

            if (procedural_expressionP(value) ||
                consP(value->second())) {
              valuevar = local_gensym("VALUE");
              bindtree = cons(cons(valuevar, cons((procedural_expressionP(value) ? ((Object*)(value)) : ((Object*)(value->second()))), NIL)), bindtree);
              if (procedural_expressionP(value)) {
                it->value_setter(valuevar);
                break;
              }
              else {
                value->second_setter(valuevar);
              }
            }
          }
        }
      }
      return (walk_a_cons_tree(listO(3, SYM_WALK_LET, bindtree->reverse(), cons(tree, NIL)), return1));
    }
  }
}

Object* walk_mv_expression_tree(Object* tree, List* targettypes, Symbol* renamed_Operator, Cons*& return1, List*& return2) {
  { Standard_Object* old_OtargettypeO_001 = oTARGETTYPEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTARGETTYPEo = ((targettypes->length() == 1) ? ((Standard_Object*)(((Standard_Object*)(targettypes->first())))) : ((Standard_Object*)(SGT_WALK_UNKNOWN)));
          { Object* otree = NULL;
            Cons* valuestree = NULL;
            List* sourcetypes = NULL;

            otree = walk_mv_tree(tree, valuestree, sourcetypes);
            if (!(sourcetypes->length() == targettypes->length())) {
              if ((sourcetypes->length() == 1) &&
                  (SGT_WALK_UNKNOWN == sourcetypes->first())) {
                warn_about_unknown_source_type(otree);
              }
              else {
                { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_error();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << " " << "`" << de_uglify_parse_tree(renamed_Operator) << "'" << " operator expected " << "`" << targettypes->length() << "'" << " value(s) from " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      resignal();
                    }
                  }
                }
              }
              { List* return_value_001 = targettypes->copy();

                oTARGETTYPEo = old_OtargettypeO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Object* return_temp = otree;

                  return1 = valuestree;
                  return2 = return_value_001;
                  return (return_temp);
                }
              }
            }
            if (sourcetypes->emptyP()) {
              { 
                oTARGETTYPEo = old_OtargettypeO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Object* return_temp = otree;

                  return1 = valuestree;
                  return2 = sourcetypes;
                  return (return_temp);
                }
              }
            }
            if (valuestree != NULL) {
              tree = coerce_mv_tree(valuestree, renamed_Operator, sourcetypes, targettypes, valuestree, targettypes);
            }
            else {
              otree = coerce_mv_tree(otree, renamed_Operator, sourcetypes, targettypes, valuestree, targettypes);
            }
            sourcetypes->free();
            { 
              oTARGETTYPEo = old_OtargettypeO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              { Object* return_temp = otree;

                return1 = valuestree;
                return2 = targettypes;
                return (return_temp);
              }
            }
          }
          oTARGETTYPEo = old_OtargettypeO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oTARGETTYPEo = old_OtargettypeO_001;
        resignal();
      }
    }
  }
}

List* listify_type_spec(Standard_Object* typespec) {
  if (voidP(typespec)) {
    return (list(0));
  }
  else {
    return (list(1, typespec));
  }
}

Slot* slot_from_expression_tree(Cons* tree) {
  if (SYM_WALK_TYPED_SYS == tree->first()) {
    tree = ((Cons*)(tree->second()));
  }
  { Object* test_value_001 = tree->first();

    if ((test_value_001 == SYM_WALK_SYS_SLOT_VALUE) ||
        ((test_value_001 == SYM_WALK_SYS_CALL_METHOD) ||
         ((test_value_001 == SYM_WALK_SYS_SLOT_VALUE_SETTER) ||
          (test_value_001 == SYM_WALK_SYS_CALL_METHOD_SETTER)))) {
      return (safe_lookup_slot(((Class*)(((Surrogate*)(tree->second()))->surrogate_value)), ((Symbol*)(tree->third()))));
    }
    else if (test_value_001 == SYM_WALK_SYS_CALL_FUNCTION) {
      { Method_Slot* function = lookup_function_or_stella_function(((Symbol*)(tree->second())));

        if ((function != NULL) &&
            isaP(function, SGT_WALK_METHOD_SLOT)) {
          return (function);
        }
      }
    }
    else {
      return (NULL);
    }
  }
  return (NULL);
}

Object* walk_mv_tree(Object* tree, Cons*& return1, List*& return2) {
  { Object* otree = NULL;
    Standard_Object* otype = NULL;
    Slot* slot = NULL;

    if (values_treeP(tree)) {
      return (walk_mv_values_tree(((Cons*)(tree)), return1, return2));
    }
    otree = walk_a_tree(tree, otype);
    if (consP(otree)) {
      slot = slot_from_expression_tree(((Cons*)(otree)));
    }
    if (slot != NULL) {
      { Slot* slot_001 = slot;

        if (method_slotP(slot)) {
          { Method_Slot* slot = NULL;

            slot = ((Method_Slot*)(slot_001));
            { Object* return_temp = otree;

              return1 = NULL;
              return2 = slot->method_return_type_specifiers_reader()->copy();
              return (return_temp);
            }
          }
        }
        else {
        }
      }
    }
    { Object* return_temp = otree;

      return1 = NULL;
      return2 = listify_type_spec(otype);
      return (return_temp);
    }
  }
}

Cons* walk_mv_values_tree(Cons* tree, Cons*& return1, List*& return2) {
  if (tree->length() == 1) {
    { Cons* return_temp = tree;

      return1 = tree;
      return2 = listify_type_spec(SGT_WALK_VOID);
      return (return_temp);
    }
  }
  { Object* otree = NULL;
    Standard_Object* otype = NULL;
    List* returntypes = new_list();
    Cons* typedsystree = NULL;

    otype = otype;
    otree = walk_values_tree(tree, otype);
    tree->first_setter(SYM_WALK_VALUES);
    { Cons_Iterator* it = tree->rest->allocate_iterator();

      while (it->nextP()) {
        typedsystree = ((Cons*)(it->value));
        returntypes->push(((Standard_Object*)(typedsystree->third())));
        if (SGT_WALK_UNKNOWN == typedsystree->third()) {
          it->value_setter(typedsystree->second());
          free_cons_list(typedsystree);
        }
      }
    }
    { Cons* return_temp = ((Cons*)(otree));

      return1 = tree;
      return2 = returntypes->reverse();
      return (return_temp);
    }
  }
}

Object* coerce_mv_tree(Object* tree, Symbol* renamed_Operator, List* sourcetypes, List* targettypes, Cons*& return1, List*& return2) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;
    Standard_Object* dummy3;

    { boolean valuestreeP = values_treeP(tree);
      Cons* valuestree = NIL;
      boolean needtemporariesP = FALSE;
      boolean successP = FALSE;
      Object* otree = NULL;
      Standard_Object* otype = NULL;
      List* returntypes = new_list();

      if (valuestreeP) {
        valuestree = ((Cons*)(tree));
      }
      else {
        valuestree = cons(SYM_WALK_VALUES, NIL);
        { Standard_Object* type = NULL;
          Cons* iter_001 = sourcetypes->the_cons_list;
          Cons* collect_001 = NULL;

          while (!nilP(iter_001)) {
            {
              type = ((Standard_Object*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            if (collect_001 == NULL) {
              {
                collect_001 = cons(sys_tree(NULL, type, dummy1), NIL);
                if (nilP(valuestree)) {
                  valuestree = collect_001;
                }
                else {
                  add_cons_to_end_of_cons_list(valuestree, collect_001);
                }
              }
            }
            else {
              {
                collect_001->rest = cons(sys_tree(NULL, type, dummy2), NIL);
                collect_001 = collect_001->rest;
              }
            }
          }
        }
      }
      { int i = NULL_INTEGER;
        Standard_Object* srcts = NULL;
        Standard_Object* tgtts = NULL;
        Cons* iter_002 = targettypes->the_cons_list;
        Cons* iter_003 = sourcetypes->the_cons_list;
        int iter_004 = 1;
        Cons_Iterator* it = valuestree->rest->allocate_iterator();
        Cons* collect_002 = NULL;

        while ((!nilP(iter_002)) &&
            ((!nilP(iter_003)) &&
             it->nextP())) {
          {
            tgtts = ((Standard_Object*)(iter_002->value));
            iter_002 = iter_002->rest;
          }
          {
            srcts = ((Standard_Object*)(iter_003->value));
            iter_003 = iter_003->rest;
          }
          {
            i = iter_004;
            iter_004 = iter_004 + 1;
          }
          otree = help_coerce_a_tree(it->value, srcts, tgtts, FALSE, otype, successP);
          if (!(successP)) {
            { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Type clash on argument " << "`" << de_uglify_parse_tree(integer_wrap_literal(i)) << "'" << " of " << "`" << de_uglify_parse_tree(renamed_Operator) << "'" << " operator." << endl << " " << "`" << de_uglify_parse_tree(srcts) << "'" << " found where " << "`" << de_uglify_parse_tree(tgtts) << "'" << " expected" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_001;
                  resignal();
                }
              }
            }
            { Object* return_temp = tree;

              return1 = ((Cons*)((valuestreeP ? ((Object*)(tree)) : ((Object*)(NULL)))));
              return2 = targettypes->copy();
              return (return_temp);
            }
          }
          if ((!eqlP(otree, it->value)) ||
              ((i > 1) &&
               ((!valuestreeP) &&
                ((!(translator_output_language() == KWD_WALK_COMMON_LISP)) &&
                 ((!(type_spec_to_base_type(tgtts) == SGT_WALK_UNKNOWN)) &&
                  (!(type_spec_to_base_type(srcts) == type_spec_to_base_type(tgtts)))))))) {
            needtemporariesP = TRUE;
          }
          it->value_setter(otree);
          if (collect_002 == NULL) {
            {
              collect_002 = permanent_cons(otype, NIL);
              if (returntypes->the_cons_list->emptyP()) {
                returntypes->the_cons_list = collect_002;
              }
              else {
                add_cons_to_end_of_cons_list(returntypes->the_cons_list, collect_002);
              }
            }
          }
          else {
            {
              collect_002->rest = permanent_cons(otype, NIL);
              collect_002 = collect_002->rest;
            }
          }
        }
      }
      if (valuestreeP) {
        { Object* return_temp = tree;

          return1 = ((Cons*)(tree));
          return2 = returntypes;
          return (return_temp);
        }
      }
      valuestree->free_parse_tree();
      if (!needtemporariesP) {
        { Object* return_temp = tree;

          return1 = NULL;
          return2 = returntypes;
          return (return_temp);
        }
      }
      valuestree = cons(SYM_WALK_VALUES, NIL);
      { int i = NULL_INTEGER;
        int iter_005 = 1;
        int upper_bound_001 = targettypes->length();
        Cons* collect_003 = NULL;

        while (iter_005 <= upper_bound_001) {
          {
            i = iter_005;
            iter_005 = iter_005 + 1;
          }
          if (collect_003 == NULL) {
            {
              collect_003 = cons(local_gensym("VALUE"), NIL);
              if (nilP(valuestree)) {
                valuestree = collect_003;
              }
              else {
                add_cons_to_end_of_cons_list(valuestree, collect_003);
              }
            }
          }
          else {
            {
              collect_003->rest = cons(local_gensym("VALUE"), NIL);
              collect_003 = collect_003->rest;
            }
          }
        }
      }
      otree = walk_without_type_tree(listO(3, SYM_WALK_MV_BIND, copy_cons_list(valuestree->rest), cons(tree, cons(valuestree, NIL))));
      valuestree->first_setter(get_quoted_tree("((VALUES) \"/STELLA\")", "/STELLA"));
      { Standard_Object* tgtts = NULL;
        Standard_Object* srcts = NULL;
        Cons_Iterator* it = valuestree->rest->allocate_iterator();
        Cons* iter_006 = sourcetypes->the_cons_list;
        Cons* iter_007 = targettypes->the_cons_list;

        while (it->nextP() &&
            ((!nilP(iter_006)) &&
             (!nilP(iter_007)))) {
          {
            srcts = ((Standard_Object*)(iter_006->value));
            iter_006 = iter_006->rest;
          }
          {
            tgtts = ((Standard_Object*)(iter_007->value));
            iter_007 = iter_007->rest;
          }
          it->value_setter(coerce_a_tree(it->value, srcts, tgtts, dummy3));
        }
      }
      { Object* return_temp = otree;

        return1 = valuestree;
        return2 = returntypes;
        return (return_temp);
      }
    }
  }
}

Cons* walk_return_and_unbind_specials(Cons* tree, Standard_Object*& return1) {
  { Cons* unbindtree = yield_return_special_unbind_tree();
    Cons* valuetrees = tree->rest;
    Cons* valuevariables = NIL;
    Cons* valuebindings = NIL;

    { boolean old_OspecialsenabledPO_001 = oSPECIALSENABLEDpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oSPECIALSENABLEDpo = FALSE;
            if (valuetrees->length() == 0) {
              { Cons* return_value_001 = NULL;
                Standard_Object* return_value_002 = NULL;

                return_value_001 = walk_a_cons_tree(listO(3, SYM_WALK_PROGN, unbindtree, cons(tree, NIL)), return_value_002);
                oSPECIALSENABLEDpo = old_OspecialsenabledPO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Cons* return_temp = return_value_001;

                  return1 = return_value_002;
                  return (return_temp);
                }
              }
            }
            if ((valuetrees->length() == 1) &&
                oMETHODBEINGWALKEDo->method_return_type_specifiers_reader()->rest()->non_emptyP()) {
              { int i = NULL_INTEGER;
                int iter_001 = 0;
                int upper_bound_001 = oMETHODBEINGWALKEDo->method_return_type_specifiers_reader()->length() - 1;
                Cons* collect_001 = NULL;

                while (iter_001 <= upper_bound_001) {
                  {
                    i = iter_001;
                    iter_001 = iter_001 + 1;
                  }
                  i = i;
                  if (collect_001 == NULL) {
                    {
                      collect_001 = cons(local_gensym("RETURN-VALUE"), NIL);
                      if (nilP(valuevariables)) {
                        valuevariables = collect_001;
                      }
                      else {
                        add_cons_to_end_of_cons_list(valuevariables, collect_001);
                      }
                    }
                  }
                  else {
                    {
                      collect_001->rest = cons(local_gensym("RETURN-VALUE"), NIL);
                      collect_001 = collect_001->rest;
                    }
                  }
                }
              }
              tree->rest = valuevariables;
              { Cons* return_value_003 = NULL;
                Standard_Object* return_value_004 = NULL;

                return_value_003 = walk_a_cons_tree(listO(3, SYM_WALK_MV_BIND, copy_cons_list(valuevariables), cons(valuetrees->first(), tree_to_trees(unbindtree)->concatenate(cons(tree, NIL)))), return_value_004);
                oSPECIALSENABLEDpo = old_OspecialsenabledPO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Cons* return_temp = return_value_003;

                  return1 = return_value_004;
                  return (return_temp);
                }
              }
            }
            { Cons_Iterator* it = valuetrees->allocate_iterator();

              while (it->nextP()) {
                if (consP(it->value) ||
                    (symbolP(it->value) &&
                     (lookup_old_value_variable(((Symbol*)(it->value))) != NULL))) {
                  valuebindings = cons(cons(local_gensym("RETURN-VALUE"), cons(it->value, NIL)), valuebindings);
                  it->value_setter(((Cons*)(valuebindings->first()))->first());
                }
              }
            }
            { Cons* return_value_005 = NULL;
              Standard_Object* return_value_006 = NULL;

              return_value_005 = walk_a_cons_tree(listO(3, SYM_WALK_LET, valuebindings->reverse(), tree_to_trees(unbindtree)->concatenate(cons(tree, NIL))), return_value_006);
              oSPECIALSENABLEDpo = old_OspecialsenabledPO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              { Cons* return_temp = return_value_005;

                return1 = return_value_006;
                return (return_temp);
              }
            }
            oSPECIALSENABLEDpo = old_OspecialsenabledPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oSPECIALSENABLEDpo = old_OspecialsenabledPO_001;
          resignal();
        }
      }
    }
  }
}

Cons* walk_return_tree(Cons* tree, Standard_Object*& return1) {
  if (!(oMETHODBEINGWALKEDo != NULL)) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            signal_translation_error();
            if (!(suppress_warningsP())) {
              print_error_context(">> ERROR: ", STANDARD_OUTPUT);
              cout << endl << " " << "Return statement encountered outside of method or function definition" << "." << endl;
            }
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
          resignal();
        }
      }
    }
    return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
  }
  oFOUNDRETURNpo = TRUE;
  if (need_to_unbind_specialsP()) {
    return (walk_return_and_unbind_specials(tree, return1));
  }
  { Method_Slot* method = oMETHODBEINGWALKEDo;
    List* targettypes = new_list();

    { Standard_Object* rtype = NULL;
      Cons* iter_001 = method->method_return_type_specifiers_reader()->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          rtype = ((Standard_Object*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = permanent_cons(compute_relative_type_spec(rtype, method->slot_owner), NIL);
            if (targettypes->the_cons_list->emptyP()) {
              targettypes->the_cons_list = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(targettypes->the_cons_list, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = permanent_cons(compute_relative_type_spec(rtype, method->slot_owner), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    { Object* otree = NULL;
      Cons* valuestree = NULL;
      List* valuetypes = NULL;

      otree = walk_mv_expression_tree((((tree->rest->length() == 1) &&
          targettypes->rest()->non_emptyP()) ? ((Object*)(tree->second())) : ((Object*)(cons(SYM_WALK_VALUES, tree->rest->concatenate(NIL))))), targettypes, SYM_WALK_RETURN, valuestree, valuetypes);
      targettypes->free();
      valuetypes->free();
      if (valuestree == NULL) {
        if (tree->rest->non_emptyP()) {
          tree->second_setter(otree);
        }
        { Cons* return_temp = tree;

          return1 = SGT_WALK_VOID;
          return (return_temp);
        }
      }
      valuestree->first_setter(SYM_WALK_RETURN);
      tree->free_cons();
      { Cons* return_temp = ((Cons*)(otree));

        return1 = SGT_WALK_VOID;
        return (return_temp);
      }
    }
  }
}

Cons* walk_mv_setq_tree(Cons* tree, Standard_Object*& return1) {
  { boolean test_value_001 = FALSE;

    if (bad_argument_countP(tree, 2)) {
      test_value_001 = TRUE;
    }
    else {
      if (!consP(tree->second())) {
        test_value_001 = TRUE;
      }
      else {
        {
          { boolean alwaysP_001 = TRUE;

            { Object* v = NULL;
              Cons* iter_001 = ((Cons*)(tree->second()));

              while (!nilP(iter_001)) {
                {
                  v = iter_001->value;
                  iter_001 = iter_001->rest;
                }
                if (!symbolP(v)) {
                  alwaysP_001 = FALSE;
                  break;
                }
              }
            }
            test_value_001 = alwaysP_001;
          }
          test_value_001 = !test_value_001;
        }
      }
    }
    if (test_value_001) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Illegal 'mv-setq' expression: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
      return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
    }
  }
  { Cons* variables = ((Cons*)(tree->second()));
    List* targettypes = new_list();

    { Object* v = NULL;
      Cons* iter_002 = variables;
      Cons* collect_001 = NULL;

      while (!nilP(iter_002)) {
        {
          v = iter_002->value;
          iter_002 = iter_002->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = permanent_cons(lookup_variable_type(((Symbol*)(v))), NIL);
            if (targettypes->the_cons_list->emptyP()) {
              targettypes->the_cons_list = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(targettypes->the_cons_list, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = permanent_cons(lookup_variable_type(((Symbol*)(v))), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    { Object* otree = NULL;
      Cons* valuestree = NULL;
      List* valuetypes = NULL;

      otree = walk_mv_expression_tree(tree->third(), targettypes, SYM_WALK_MV_SETQ, valuestree, valuetypes);
      valuetypes->free();
      targettypes->free();
      if (valuestree != NULL) {
        valuestree->first_setter(SYM_WALK_PROGN);
        { Object* var = NULL;
          Cons_Iterator* it = valuestree->rest->allocate_iterator();
          Cons* iter_003 = variables;

          while (it->nextP() &&
              (!nilP(iter_003))) {
            {
              var = iter_003->value;
              iter_003 = iter_003->rest;
            }
            it->value_setter(listO(3, SYM_WALK_SETQ, var, cons(it->value, NIL)));
          }
        }
        tree->rest->rest = NIL;
        tree->free_parse_tree();
        { Cons* return_temp = ((Cons*)(otree));

          return1 = SGT_WALK_VOID;
          return (return_temp);
        }
      }
      tree->third_setter(otree);
      { Cons* return_temp = tree;

        return1 = SGT_WALK_VOID;
        return (return_temp);
      }
    }
  }
}

Cons* walk_mv_bind_tree(Cons* tree, Standard_Object*& return1) {
  if ((tree->length() < 3) ||
      (!consP(tree->second()))) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            signal_translation_error();
            if (!(suppress_warningsP())) {
              print_error_context(">> ERROR: ", STANDARD_OUTPUT);
              cout << endl << " " << "Illegal 'mv-bind' expression: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
            }
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
          resignal();
        }
      }
    }
    return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
  }
  { Cons* declarations = ((Cons*)(tree->second()));
    Object* mvtree = tree->third();
    Cons* body = tree->rest->rest->rest;
    Cons* variables = NIL;
    Object* decl = NULL;
    List* targettypes = new_list();

    { Cons_Iterator* it = declarations->allocate_iterator();

      while (it->nextP()) {
        decl = it->value;
        { Object* decl_001 = decl;

          if (consP(decl)) {
            { Cons* decl = NULL;

              decl = ((Cons*)(decl_001));
              if (!(symbolP(decl->first()) &&
                  (decl->length() == 2))) {
                { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_error();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Illegal variable declaration " << "`" << de_uglify_parse_tree(decl) << "'" << " in 'mv-bind' expression: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_002;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_002;
                      resignal();
                    }
                  }
                }
                return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
              }
              targettypes->push(decl->second()->yield_type_specifier());
              decl->rest->rest = cons(SYM_WALK_NULL, NIL);
              variables = cons(decl->first(), variables);
            }
          }
          else if (symbolP(decl)) {
            { Symbol* decl = NULL;

              decl = ((Symbol*)(decl_001));
              targettypes->push(SGT_WALK_UNKNOWN);
              it->value_setter(cons(decl, listO(3, SGT_WALK_UNKNOWN, SYM_WALK_NULL, NIL)));
              variables = cons(decl, variables);
            }
          }
          else {
            { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Illegal variable " << "`" << de_uglify_parse_tree(decl) << "'" << " in 'mv-bind' expression: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_003;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_003;
                  resignal();
                }
              }
            }
            return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
          }
        }
      }
    }
    variables = variables->reverse();
    { Object* variable = NULL;
      Cons* iter_001 = variables;

      while (!nilP(iter_001)) {
        {
          variable = iter_001->value;
          iter_001 = iter_001->rest;
        }
        push_variable_binding(((Symbol*)(variable)), SGT_WALK_UNINITIALIZED);
      }
    }
    { Object* omvtree = NULL;
      Cons* valuestree = NULL;
      List* variabletypes = NULL;

      omvtree = walk_mv_expression_tree(mvtree, targettypes->reverse(), SYM_WALK_MV_BIND, valuestree, variabletypes);
      { Object* variable = NULL;
        Cons* iter_002 = variables;

        while (!nilP(iter_002)) {
          {
            variable = iter_002->value;
            iter_002 = iter_002->rest;
          }
          pop_variable_binding();
        }
      }
      targettypes->free();
      tree->rest->rest->rest = NIL;
      free_cons_list(tree);
      { Standard_Object* type = NULL;
        Cons* decl = NIL;
        Cons* iter_003 = ((Cons*)(declarations));
        Cons* iter_004 = variabletypes->the_cons_list;

        while ((!nilP(iter_003)) &&
            (!nilP(iter_004))) {
          {
            decl = ((Cons*)(iter_003->value));
            iter_003 = iter_003->rest;
          }
          {
            type = ((Standard_Object*)(iter_004->value));
            iter_004 = iter_004->rest;
          }
          if (SGT_WALK_UNKNOWN == decl->second()) {
            decl->second_setter(type);
          }
        }
      }
      variabletypes->free();
      if (valuestree != NULL) {
        valuestree->first_setter(SYM_WALK_PROGN);
        { Object* var = NULL;
          Cons_Iterator* it = valuestree->rest->allocate_iterator();
          Cons* iter_005 = variables;

          while (it->nextP() &&
              (!nilP(iter_005))) {
            {
              var = iter_005->value;
              iter_005 = iter_005->rest;
            }
            it->value_setter(listO(3, SYM_WALK_SETQ, var, cons(it->value, NIL)));
          }
        }
        valuestree = ((Cons*)(omvtree));
      }
      else {
        valuestree = listO(3, SYM_WALK_MV_SETQ, variables, cons(omvtree, NIL));
      }
      return (walk_a_cons_tree(listO(3, SYM_WALK_LET, declarations, cons(valuestree, body->concatenate(NIL))), return1));
    }
  }
}

Cons* walk_loop_tree(Cons* tree, Standard_Object*& return1) {
  { int old_OnofspecialsatloopentryO_001 = oNOFSPECIALSATLOOPENTRYo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oNOFSPECIALSATLOOPENTRYo = oSPECIALVARIABLESTACKo->length();
          tree->rest = walk_list_of_trees(tree->rest);
          { Cons* return_value_001 = NULL;
            Standard_Object* return_value_002 = NULL;

            return_value_001 = sys_tree(tree, SGT_WALK_VOID, return_value_002);
            oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
            { Cons* return_temp = return_value_001;

              return1 = return_value_002;
              return (return_temp);
            }
          }
          oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
        resignal();
      }
    }
  }
}

Cons* walk_loop_exit_tree(Cons* tree, Standard_Object*& return1) {
  bad_argument_countP(tree, 0);
  if (need_to_unbind_specialsP()) {
    { Cons* unbindtree = yield_loop_exit_special_unbind_tree();

      { boolean old_OspecialsenabledPO_001 = oSPECIALSENABLEDpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oSPECIALSENABLEDpo = FALSE;
              { Cons* return_value_001 = NULL;
                Standard_Object* return_value_002 = NULL;

                return_value_001 = walk_a_cons_tree(listO(3, SYM_WALK_PROGN, unbindtree, cons(tree, NIL)), return_value_002);
                oSPECIALSENABLEDpo = old_OspecialsenabledPO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Cons* return_temp = return_value_001;

                  return1 = return_value_002;
                  return (return_temp);
                }
              }
              oSPECIALSENABLEDpo = old_OspecialsenabledPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oSPECIALSENABLEDpo = old_OspecialsenabledPO_001;
            resignal();
          }
        }
      }
    }
  }
  else {
    { Cons* return_temp = tree;

      return1 = SGT_WALK_VOID;
      return (return_temp);
    }
  }
}

Cons* walk_while_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    { int old_OnofspecialsatloopentryO_001 = oNOFSPECIALSATLOOPENTRYo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oNOFSPECIALSATLOOPENTRYo = oSPECIALVARIABLESTACKo->length();
            { Object* test = walk_expression_tree(tree->second(), SGT_WALK_BOOLEAN, SYM_WALK_WHILE, TRUE, dummy1);
              Cons* body = tree->rest->rest;

              tree->second_setter(test);
              if (procedural_expressionP(test)) {
                tree->rest->rest = NIL;
                free_cons_list(tree);
                { Cons* return_value_001 = NULL;
                  Standard_Object* return_value_002 = NULL;

                  return_value_001 = walk_a_cons_tree(listO(3, SYM_WALK_LOOP, listO(3, SYM_WALK_UNLESS, test, cons(cons(SYM_WALK_BREAK, NIL), NIL)), body->concatenate(NIL)), return_value_002);
                  oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Cons* return_temp = return_value_001;

                    return1 = return_value_002;
                    return (return_temp);
                  }
                }
              }
              tree->rest->rest = walk_list_of_trees(tree->rest->rest);
              { 
                oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Cons* return_temp = tree;

                  return1 = SGT_WALK_VOID;
                  return (return_temp);
                }
              }
            }
            oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
          resignal();
        }
      }
    }
  }
}

Cons* walk_conditional_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;

    { Object* renamed_Operator = tree->first();
      Object* test = walk_expression_tree(tree->second(), SGT_WALK_BOOLEAN, ((Symbol*)(renamed_Operator)), TRUE, dummy1);

      tree->second_setter(test);
      if (procedural_expressionP(test)) {
        { Cons* return_temp = transform_boolean_procedural_expression(tree, ((Cons*)(test)), dummy2);

          return1 = SGT_WALK_VOID;
          return (return_temp);
        }
      }
      if (renamed_Operator == SYM_WALK_IF) {
        if (bad_argument_countP(tree, 3)) {
          return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
        }
        tree->third_setter(walk_statement(tree->third(), TRUE));
        tree->fourth_setter(walk_statement(tree->fourth(), TRUE));
      }
      else if ((renamed_Operator == SYM_WALK_WHEN) ||
          (renamed_Operator == SYM_WALK_UNLESS)) {
        tree->rest->rest = walk_list_of_trees(tree->rest->rest);
      }
      else {
        cerr << "`" << renamed_Operator << "'" << " is not a valid case option";
      }
      { Cons* return_temp = tree;

        return1 = SGT_WALK_VOID;
        return (return_temp);
      }
    }
  }
}

Cons* walk_choose_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;
    Standard_Object* dummy3;
    Standard_Object* dummy4;
    Standard_Object* dummy5;

    { Object* renamed_Operator = tree->first();
      Object* test = walk_expression_tree(tree->second(), SGT_WALK_BOOLEAN, ((Symbol*)(renamed_Operator)), TRUE, dummy1);
      Object* temp = NULL;
      Standard_Object* type1 = NULL;
      Standard_Object* type2 = NULL;
      Standard_Object* type = NULL;

      tree->second_setter(test);
      if (vrlet_expressionP(test)) {
        return (percolate_out_vrlet_expression(tree, ((Cons*)(test)), SGT_WALK_BOOLEAN, return1));
      }
      if (bad_argument_countP(tree, 3)) {
        return (walk_dont_call_me_tree(tree, SGT_WALK_UNKNOWN, return1));
      }
      temp = walk_a_tree(tree->third(), type1);
      tree->third_setter(temp);
      temp = walk_a_tree(tree->fourth(), type2);
      tree->fourth_setter(temp);
      if (type1 == SGT_WALK_UNKNOWN) {
        type = type2;
      }
      else if (type2 == SGT_WALK_UNKNOWN) {
        type = type1;
      }
      else {
        type = two_argument_least_common_supertype(type_spec_to_base_type(type1), type_spec_to_base_type(type2));
      }
      if (type == SGT_WALK_VOID) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Incompatible return types " << "`" << de_uglify_parse_tree(type1) << "'" << " and " << "`" << de_uglify_parse_tree(type2) << "'" << endl << "in 'choose' expression." << "." << endl;
                }
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
              resignal();
            }
          }
        }
      }
      else {
        tree->third_setter(coerce_a_tree(tree->third(), type1, type, dummy2));
        tree->fourth_setter(coerce_a_tree(tree->fourth(), type2, type, dummy3));
      }
      if (vrlet_expressionP(tree->third()) ||
          vrlet_expressionP(tree->fourth())) {
        { Symbol* resultvariable = local_gensym("CHOOSE-VALUE");

          { Object* value_001 = NULL;
            Standard_Object* value_002 = NULL;

            value_001 = walk_a_tree(listO(5, SYM_WALK_VRLET, cons(cons(resultvariable, cons(type, cons(SYM_WALK_NULL, NIL))), NIL), listO(3, SYM_WALK_IF, tree->second(), listO(3, listO(3, SYM_WALK_SETQ, resultvariable, cons(tree->third(), NIL)), listO(3, SYM_WALK_SETQ, resultvariable, cons(tree->fourth(), NIL)), NIL)), resultvariable, NIL), value_002);
            { Cons* return_temp = ((Cons*)(value_001));

              return1 = value_002;
              return (return_temp);
            }
          }
        }
      }
      tree->third_setter(sys_tree(tree->third(), type, dummy4));
      tree->fourth_setter(sys_tree(tree->fourth(), type, dummy5));
      { Cons* return_temp = tree;

        return1 = type;
        return (return_temp);
      }
    }
  }
}

Object* walk_boolean_tree(Cons* tree, Standard_Object*& return1) {
  { Object* otree = help_walk_boolean_tree(tree);

    if (procedural_expressionP(otree)) {
      otree = percolate_out_boolean_vrlet_expressions(((Cons*)(otree)));
    }
    { Object* return_temp = otree;

      return1 = SGT_WALK_BOOLEAN;
      return (return_temp);
    }
  }
}

boolean and_or_not_treeP(Object* tree) {
  if (consP(tree)) {
    { Object* test_value_001 = ((Cons*)(tree))->value;

      if ((test_value_001 == SYM_WALK_AND) ||
          ((test_value_001 == SYM_WALK_OR) ||
           (test_value_001 == SYM_WALK_NOT))) {
        return (TRUE);
      }
      else {
        return (FALSE);
      }
    }
  }
  else {
    return (FALSE);
  }
}

Object* help_walk_boolean_tree(Cons* tree) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;

    { Cons* cursor = tree->rest;
      Object* temp = NULL;

      while (cursor->non_emptyP()) {
        cursor->value = (and_or_not_treeP(cursor->value) ? ((Object*)(help_walk_boolean_tree(((Cons*)(cursor->value))))) : ((Object*)(walk_expression_tree(cursor->value, SGT_WALK_BOOLEAN, ((Symbol*)(tree->first())), TRUE, dummy1))));
        cursor = cursor->rest;
      }
      { Object* test_value_001 = tree->first();

        if (test_value_001 == SYM_WALK_AND) {
          if (tree->rest->emptyP()) {
            free_cons_list(tree);
            return (TRUE_WRAPPER);
          }
          if (tree->rest->rest->emptyP()) {
            temp = tree->second();
            free_cons_list(tree);
            return (temp);
          }
        }
        else if (test_value_001 == SYM_WALK_OR) {
          if (tree->rest->emptyP()) {
            free_cons_list(tree);
            return (FALSE_WRAPPER);
          }
          if (tree->rest->rest->emptyP()) {
            temp = tree->second();
            free_cons_list(tree);
            return (temp);
          }
        }
        else if (test_value_001 == SYM_WALK_NOT) {
          if (bad_argument_countP(tree, 1)) {
            return (walk_dont_call_me_tree(tree, SGT_WALK_BOOLEAN, dummy2));
          }
        }
        else {
          cerr << "`" << test_value_001 << "'" << " is not a valid case option";
        }
      }
      return (tree);
    }
  }
}

Cons* walk_cond_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    { Object* condition = NULL;
      Cons* iter_001 = tree->rest;

      while (!nilP(iter_001)) {
        {
          condition = iter_001->value;
          iter_001 = iter_001->rest;
        }
        { Object* condition_001 = condition;

          if (consP(condition)) {
            { Cons* condition = NULL;

              condition = ((Cons*)(condition_001));
              if (!(condition->value == SYM_WALK_OTHERWISE)) {
                condition->value = walk_expression_tree(condition->value, SGT_WALK_BOOLEAN, SYM_WALK_COND, TRUE, dummy1);
                if (procedural_expressionP(condition->value)) {
                  return (walk_a_cons_tree(cond_tree_to_if_tree(tree), return1));
                }
              }
              condition->rest = walk_list_of_trees(condition->rest);
            }
          }
          else {
            { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Illegal condition in COND statement: " << "`" << de_uglify_parse_tree(condition) << "'" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_001;
                  resignal();
                }
              }
            }
            return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
          }
        }
      }
    }
    { Cons* return_temp = tree;

      return1 = SGT_WALK_VOID;
      return (return_temp);
    }
  }
}

Cons* cond_tree_to_if_tree(Cons* tree) {
  { Standard_Object* dummy1;

    { Object* firstcondition = tree->rest->value;
      Cons* otherconditions = tree->rest->rest;
      Object* firsttest = NULL;

      { Object* firstcondition_001 = firstcondition;

        if (consP(firstcondition)) {
          { Cons* firstcondition = NULL;

            firstcondition = ((Cons*)(firstcondition_001));
            firsttest = firstcondition->value;
            if (firsttest == SYM_WALK_OTHERWISE) {
              if (otherconditions->emptyP()) {
                tree->first_setter(SYM_WALK_PROGN);
                tree->rest = firstcondition->rest;
                return (tree);
              }
              else {
                firstcondition->value = SYM_WALK_TRUE;
                return (cond_tree_to_if_tree(tree));
              }
            }
            else if (otherconditions->emptyP()) {
              tree->first_setter(SYM_WALK_WHEN);
              tree->rest = firstcondition;
              return (tree);
            }
            else {
              firstcondition->value = SYM_WALK_PROGN;
              tree->second_setter(SYM_WALK_COND);
              return (listO(3, SYM_WALK_IF, firsttest, cons(firstcondition, cons(cond_tree_to_if_tree(tree->rest), NIL))));
            }
          }
        }
        else {
          { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  signal_translation_error();
                  if (!(suppress_warningsP())) {
                    print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                    cout << endl << " " << "Illegal condition in COND statement: " << "`" << de_uglify_parse_tree(firstcondition) << "'" << "." << endl;
                  }
                  oPRINTREADABLYpo = old_OprintreadablyPO_001;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
                resignal();
              }
            }
          }
          return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, dummy1));
        }
      }
    }
  }
}

Object* yield_hardcoded_case_symbol_id_or_ids(Object* casetest) {
  if (casetest == SYM_WALK_OTHERWISE) {
    return (casetest);
  }
  { Symbol* symbol = NULL;

    { Object* casetest_001 = casetest;

      if (consP(casetest)) {
        { Cons* casetest = NULL;

          casetest = ((Cons*)(casetest_001));
          { Cons_Iterator* it = casetest->allocate_iterator();

            while (it->nextP()) {
              symbol = ((Symbol*)(it->value));
              if (!(symbol->symbol_id != NULL_INTEGER)) {
                symbol = intern_permanent_symbol(symbol->symbol_name);
              }
              it->value_setter(integer_wrap_literal(symbol->symbol_id));
              register_symbol(symbol);
            }
          }
          return (casetest);
        }
      }
      else if (symbolP(casetest)) {
        { Symbol* casetest = NULL;

          casetest = ((Symbol*)(casetest_001));
          symbol = casetest;
          if (!(symbol->symbol_id != NULL_INTEGER)) {
            symbol = intern_permanent_symbol(symbol->symbol_name);
          }
          register_symbol(casetest);
          return (integer_wrap_literal(symbol->symbol_id));
        }
      }
      else {
        cerr << "`" << casetest << "'" << " is not a valid case option";
      }
    }
  }
}

Cons* walk_hardcoded_symbol_case_tree(Cons* tree, Standard_Object*& return1) {
  tree->second_setter(listO(3, SYM_WALK_SYMBOL_ID, listO(3, SYM_WALK_CAST, tree->second(), cons(SYM_WALK_GENERALIZED_SYMBOL, NIL)), NIL));
  { Cons* cond = NIL;
    Cons* iter_001 = ((Cons*)(tree->rest->rest));

    while (!nilP(iter_001)) {
      {
        cond = ((Cons*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      cond->first_setter(yield_hardcoded_case_symbol_id_or_ids(cond->first()));
    }
  }
  return (walk_case_tree(tree, return1));
}

Cons* yield_cond_test(Object* casetest, Symbol* testvariable, Symbol* equalitytest) {
  if (symbolP(casetest) &&
      (!use_hardcoded_symbolsP())) {
    register_symbol(((Generalized_Symbol*)(casetest)));
    casetest = listO(3, SYM_WALK_TYPED_SYS, yield_symbol_constant_name(((Generalized_Symbol*)(casetest))), cons(SGT_WALK_SYMBOL, NIL));
  }
  if (equalitytest == SYM_WALK_ISAp) {
    { Cons* pair = NIL;
      Cons* iter_001 = oTYPE_PREDICATE_TABLEo;

      while (!nilP(iter_001)) {
        {
          pair = ((Cons*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (pair->first() == casetest) {
          return (cons(pair->second(), cons(testvariable, NIL)));
        }
      }
    }
    if (subtype_ofP(typify(casetest), SGT_WALK_OBJECT)) {
      equalitytest = SYM_WALK_TAXONOMY_ISAp;
    }
  }
  return (cons(equalitytest, cons(testvariable, cons(casetest, NIL))));
}

Object* yield_cond_test_or_tests(Object* casetest, Symbol* testvariable, Symbol* equalitytest) {
  { Object* casetest_001 = casetest;

    if (consP(casetest)) {
      { Cons* casetest = NULL;

        casetest = ((Cons*)(casetest_001));
        { Cons_Iterator* it = casetest->allocate_iterator();

          while (it->nextP()) {
            it->value_setter(yield_cond_test(it->value, testvariable, equalitytest));
          }
        }
        casetest = cons(SYM_WALK_OR, casetest);
        return (casetest);
      }
    }
    else {
      if (casetest == SYM_WALK_OTHERWISE) {
        return (casetest);
      }
      else {
        return (yield_cond_test(casetest, testvariable, equalitytest));
      }
    }
  }
}

Cons* walk_non_built_in_case_tree(Cons* tree, Symbol* equalitytest, Standard_Object*& return1) {
  { Object* testexpression = tree->second();
    Symbol* testvariable = (symbolP(tree->second()) ? ((Symbol*)(((Symbol*)(tree->second())))) : ((Symbol*)(local_gensym("TEST-VALUE"))));
    boolean otherwiseP = FALSE;
    Cons* conditions = tree->rest->rest;

    { Cons* cond = NIL;
      Cons* iter_001 = ((Cons*)(conditions));

      while (!nilP(iter_001)) {
        {
          cond = ((Cons*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (cond->first() == SYM_WALK_OTHERWISE) {
          otherwiseP = TRUE;
        }
        cond->first_setter(yield_cond_test_or_tests(cond->first(), testvariable, equalitytest));
      }
    }
    tree->rest->free_cons();
    tree->free_cons();
    if (!otherwiseP) {
      conditions = ((Cons*)(conditions->concatenate(cons(listO(3, SYM_WALK_OTHERWISE, listO(3, SYM_WALK_ERROR, testvariable, cons(string_wrap_literal(" is not a valid case option"), NIL)), NIL), NIL))));
    }
    return (walk_a_cons_tree(((testexpression == testvariable) ? ((Cons*)(cons(SYM_WALK_COND, conditions->concatenate(NIL)))) : ((Cons*)(listO(4, SYM_WALK_LET, cons(cons(testvariable, cons(testexpression, NIL)), NIL), cons(SYM_WALK_COND, conditions->concatenate(NIL)), NIL)))), return1));
  }
}

Cons* walk_case_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    { Object* firsttesttree = ((Cons*)(tree->rest->rest->first()))->first();

      tree->second_setter(walk_without_type_tree(tree->second()));
      if (consP(firsttesttree)) {
        firsttesttree = ((Cons*)(firsttesttree))->first();
      }
      if (symbolP(firsttesttree) &&
          use_hardcoded_symbolsP()) {
        return (walk_hardcoded_symbol_case_tree(tree, return1));
      }
      if (!(integerP(firsttesttree) ||
          characterP(firsttesttree))) {
        return (walk_non_built_in_case_tree(tree, (stringP(firsttesttree) ? ((Symbol*)(SYM_WALK_STRING_EQLp)) : ((Symbol*)(SYM_WALK_EQLp))), return1));
      }
      { Cons* cursor = tree->rest->rest;
        Cons* conditiontree = NULL;

        while (cursor->non_emptyP()) {
          conditiontree = ((Cons*)(cursor->value));
          if (!(conditiontree->first() == SYM_WALK_OTHERWISE)) {
            conditiontree->first_setter((consP(conditiontree->first()) ? ((Object*)(walk_list_of_trees(((Cons*)(conditiontree->first()))))) : ((Object*)(walk_a_tree(conditiontree->first(), dummy1)))));
          }
          conditiontree->rest = walk_list_of_trees(conditiontree->rest);
          cursor = cursor->rest;
        }
        { Cons* return_temp = tree;

          return1 = SGT_WALK_VOID;
          return (return_temp);
        }
      }
    }
  }
}

Cons* walk_typecase_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    { Object* testtree = tree->second();
      Symbol* testvariable = NULL;
      Symbol* auxvariable = NULL;
      Cons* expandedcases = NIL;
      boolean needcastP = FALSE;

      if (symbolP(testtree)) {
        testvariable = ((Symbol*)(testtree));
        auxvariable = local_gensym(testvariable->symbol_name);
        needcastP = TRUE;
      }
      if (needcastP) {
        { Object* casetree = NULL;
          Cons* iter_001 = tree->rest->rest;

          while (!nilP(iter_001)) {
            {
              casetree = iter_001->value;
              iter_001 = iter_001->rest;
            }
            { Object* casetree_001 = casetree;

              if (consP(casetree)) {
                { Cons* casetree = NULL;

                  casetree = ((Cons*)(casetree_001));
                  { Object* typetree = casetree->first();

                    { Object* typetree_001 = typetree;

                      if (consP(typetree)) {
                        { Cons* typetree = NULL;

                          typetree = ((Cons*)(typetree_001));
                          casetree->first_setter(typetree->first());
                          expandedcases = cons(casetree, expandedcases);
                          { Object* type = NULL;
                            Cons* iter_002 = typetree->rest;

                            while (!nilP(iter_002)) {
                              {
                                type = iter_002->value;
                                iter_002 = iter_002->rest;
                              }
                              expandedcases = cons(cons(type, ((Cons*)(((Cons*)(copy_cons_tree(casetree->rest)))))->concatenate(NIL)), expandedcases);
                            }
                          }
                        }
                      }
                      else {
                        expandedcases = cons(casetree, expandedcases);
                      }
                    }
                  }
                }
              }
              else {
                expandedcases = cons(casetree, expandedcases);
              }
            }
          }
        }
        free_cons_list(tree->rest->rest);
        tree->rest->rest = expandedcases->reverse();
      }
      { Object* casetree = NULL;
        Cons* iter_003 = tree->rest->rest;

        while (!nilP(iter_003)) {
          {
            casetree = iter_003->value;
            iter_003 = iter_003->rest;
          }
          { Object* casetree_002 = casetree;

            if (consP(casetree)) {
              { Cons* casetree = NULL;

                casetree = ((Cons*)(casetree_002));
                { Object* typetree = casetree->first();

                  { Object* typetree_002 = typetree;

                    if (symbolP(typetree)) {
                      { Symbol* typetree = NULL;

                        typetree = ((Symbol*)(typetree_002));
                        if (!(string_eqlP(typetree->symbol_name, "OTHERWISE"))) {
                          { Surrogate* type = type_spec_to_base_type(typetree->yield_type_specifier());

                            if (unknown_typeP(type)) {
                              { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                                { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                                  oEXCEPTIONHANDLERADDRESSo = NULL;
                                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                                    {
                                      oPRINTREADABLYpo = TRUE;
                                      signal_translation_error();
                                      if (!(suppress_warningsP())) {
                                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                                        cout << endl << " " << "Reference to undefined class in 'typecase': " << "`" << de_uglify_parse_tree(type) << "'" << "." << endl;
                                      }
                                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                                    }
                                    oEXCEPTIONo = NULL;
                                  }
                                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                                }
                                if (oEXCEPTIONo != NULL) {
                                  if (TRUE) {
                                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                                    resignal();
                                  }
                                }
                              }
                              return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
                            }
                            casetree->first_setter(type);
                            type = type->type_to_wrapped_type();
                            if (needcastP &&
                                casetree->rest->non_emptyP()) {
                              casetree->rest = cons(listO(4, SYM_WALK_LET, cons(cons(testvariable, cons(type, cons(SYM_WALK_NULL, NIL))), NIL), listO(3, SYM_WALK_SETQ, testvariable, cons(listO(3, SYM_WALK_SAFE_CAST, auxvariable, cons(yield_type_spec_tree(type), NIL)), NIL)), casetree->rest->concatenate(NIL)), NIL);
                            }
                          }
                        }
                      }
                    }
                    else if (surrogateP(typetree)) {
                      { Surrogate* typetree = NULL;

                        typetree = ((Surrogate*)(typetree_002));
                        if (!(string_eqlP(typetree->symbol_name, "OTHERWISE"))) {
                          { Surrogate* type = type_spec_to_base_type(typetree->yield_type_specifier());

                            if (unknown_typeP(type)) {
                              { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                                { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                                  oEXCEPTIONHANDLERADDRESSo = NULL;
                                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                                    {
                                      oPRINTREADABLYpo = TRUE;
                                      signal_translation_error();
                                      if (!(suppress_warningsP())) {
                                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                                        cout << endl << " " << "Reference to undefined class in 'typecase': " << "`" << de_uglify_parse_tree(type) << "'" << "." << endl;
                                      }
                                      oPRINTREADABLYpo = old_OprintreadablyPO_002;
                                    }
                                    oEXCEPTIONo = NULL;
                                  }
                                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                                }
                                if (oEXCEPTIONo != NULL) {
                                  if (TRUE) {
                                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                                    resignal();
                                  }
                                }
                              }
                              return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
                            }
                            casetree->first_setter(type);
                            type = type->type_to_wrapped_type();
                            if (needcastP &&
                                casetree->rest->non_emptyP()) {
                              casetree->rest = cons(listO(4, SYM_WALK_LET, cons(cons(testvariable, cons(type, cons(SYM_WALK_NULL, NIL))), NIL), listO(3, SYM_WALK_SETQ, testvariable, cons(listO(3, SYM_WALK_SAFE_CAST, auxvariable, cons(yield_type_spec_tree(type), NIL)), NIL)), casetree->rest->concatenate(NIL)), NIL);
                            }
                          }
                        }
                      }
                    }
                    else if (consP(typetree)) {
                      { Cons* typetree = NULL;

                        typetree = ((Cons*)(typetree_002));
                        { Cons_Iterator* it = typetree->allocate_iterator();

                          while (it->nextP()) {
                            if (consP(it->value)) {
                              { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

                                { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                                  oEXCEPTIONHANDLERADDRESSo = NULL;
                                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                                    {
                                      oPRINTREADABLYpo = TRUE;
                                      signal_translation_error();
                                      if (!(suppress_warningsP())) {
                                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                                        cout << endl << " " << "Illegal type expression in 'typecase': " << "`" << de_uglify_parse_tree(typetree) << "'" << "." << endl;
                                      }
                                      oPRINTREADABLYpo = old_OprintreadablyPO_003;
                                    }
                                    oEXCEPTIONo = NULL;
                                  }
                                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                                }
                                if (oEXCEPTIONo != NULL) {
                                  if (TRUE) {
                                    oPRINTREADABLYpo = old_OprintreadablyPO_003;
                                    resignal();
                                  }
                                }
                              }
                              return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
                            }
                            it->value_setter(type_spec_to_base_type(it->value->yield_type_specifier()));
                            if (unknown_typeP(((Surrogate*)(it->value)))) {
                              { boolean old_OprintreadablyPO_004 = oPRINTREADABLYpo;

                                { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                                  oEXCEPTIONHANDLERADDRESSo = NULL;
                                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                                    {
                                      oPRINTREADABLYpo = TRUE;
                                      signal_translation_error();
                                      if (!(suppress_warningsP())) {
                                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                                        cout << endl << " " << "Reference to undefined class in 'typecase': " << "`" << it->value << "'" << "." << endl;
                                      }
                                      oPRINTREADABLYpo = old_OprintreadablyPO_004;
                                    }
                                    oEXCEPTIONo = NULL;
                                  }
                                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
                                }
                                if (oEXCEPTIONo != NULL) {
                                  if (TRUE) {
                                    oPRINTREADABLYpo = old_OprintreadablyPO_004;
                                    resignal();
                                  }
                                }
                              }
                              return (walk_dont_call_me_tree(it->value, SGT_WALK_VOID, return1));
                            }
                          }
                        }
                      }
                    }
                    else {
                      { boolean old_OprintreadablyPO_005 = oPRINTREADABLYpo;

                        { jump_buffer old_OexceptionhandleraddressO_005 = oEXCEPTIONHANDLERADDRESSo;

                          oEXCEPTIONHANDLERADDRESSo = NULL;
                          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                            {
                              oPRINTREADABLYpo = TRUE;
                              signal_translation_error();
                              if (!(suppress_warningsP())) {
                                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                                cout << endl << " " << "Illegal type expression in 'typecase': " << "`" << de_uglify_parse_tree(typetree) << "'" << "." << endl;
                              }
                              oPRINTREADABLYpo = old_OprintreadablyPO_005;
                            }
                            oEXCEPTIONo = NULL;
                          }
                          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_005;
                        }
                        if (oEXCEPTIONo != NULL) {
                          if (TRUE) {
                            oPRINTREADABLYpo = old_OprintreadablyPO_005;
                            resignal();
                          }
                        }
                      }
                      return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
                    }
                  }
                }
              }
            }
            else {
              { boolean old_OprintreadablyPO_006 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_006 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_error();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Illegal case expression in 'typecase': " << "`" << de_uglify_parse_tree(casetree) << "'" << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_006;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_006;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_006;
                    resignal();
                  }
                }
              }
              return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
            }
          }
        }
      }
      tree->first_setter(SYM_WALK_CASE);
      if (needcastP) {
        push_variable_binding(auxvariable, lookup_variable_type(testvariable));
        tree = walk_non_built_in_case_tree(tree, SYM_WALK_ISAp, dummy1);
        pop_variable_binding();
        return (walk_a_cons_tree(listO(4, SYM_WALK_LET, cons(cons(auxvariable, cons(testvariable, NIL)), NIL), tree, NIL), return1));
      }
      return (walk_non_built_in_case_tree(tree, SYM_WALK_ISAp, return1));
    }
  }
}

Cons* finish_walking_eql_tree(Cons* tree, Surrogate* type1, Surrogate* type2, Standard_Object*& return1) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;

    if (subtype_ofP(type1, SGT_WALK_STANDARD_OBJECT) ||
        (subtype_ofP(type2, SGT_WALK_STANDARD_OBJECT) ||
         (((!subtype_ofP(type1, SGT_WALK_OBJECT)) &&
        (!subtype_ofP(type1, SGT_WALK_LITERAL))) ||
          ((!subtype_ofP(type2, SGT_WALK_OBJECT)) &&
           (!subtype_ofP(type2, SGT_WALK_LITERAL)))))) {
      tree->first_setter(SYM_WALK_EQp);
      tree->second_setter(sys_tree(tree->second(), type1, dummy1));
      tree->third_setter(sys_tree(tree->third(), type2, dummy2));
      { Cons* return_temp = tree;

        return1 = SGT_WALK_BOOLEAN;
        return (return_temp);
      }
    }
    if (subtype_ofP(type1, SGT_WALK_LITERAL) &&
        subtype_ofP(type2, SGT_WALK_LITERAL)) {
      if (type1 == SGT_WALK_STRING) {
        tree->first_setter(SYM_WALK_STRING_EQLp);
      }
      else {
        tree->first_setter(SYM_WALK_EQp);
      }
      return (walk_a_cons_tree(tree, return1));
    }
    if ((!subtype_ofP(type1, SGT_WALK_LITERAL)) &&
        (!subtype_ofP(type2, SGT_WALK_LITERAL))) {
      { Object* otree = NULL;
        Standard_Object* otype = NULL;

        otree = walk_call_slot_tree(tree, otype);
        { Cons* return_temp = ((Cons*)(otree));

          return1 = otype;
          return (return_temp);
        }
      }
    }
    if (!subtype_ofP(type2, SGT_WALK_LITERAL)) {
      { Object* temparg = tree->third();
        Surrogate* temptype = type2;

        tree->third_setter(tree->second());
        tree->second_setter(temparg);
        type2 = type1;
        type1 = temptype;
      }
    }
    if (type2 == SGT_WALK_BOOLEAN) {
      tree->first_setter(SYM_WALK_EQL_TO_BOOLEANp);
    }
    else if (type2 == SGT_WALK_INTEGER) {
      tree->first_setter(SYM_WALK_EQL_TO_INTEGERp);
    }
    else if (type2 == SGT_WALK_FLOAT) {
      tree->first_setter(SYM_WALK_EQL_TO_FLOATp);
    }
    else if (type2 == SGT_WALK_STRING) {
      tree->first_setter(SYM_WALK_EQL_TO_STRINGp);
    }
    else {
      cerr << "`" << type2 << "'" << " is not a valid case option";
    }
    { Cons* return_temp = ((Cons*)(walk_without_type_tree(tree)));

      return1 = SGT_WALK_BOOLEAN;
      return (return_temp);
    }
  }
}

Cons* finish_walking_equal_tree(Cons* tree, Surrogate* type1, Surrogate* type2, Standard_Object*& return1) {
  {
    tree = tree;
    type1 = type1;
    type2 = type2;
  }
  { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRINTREADABLYpo = TRUE;
          signal_translation_error();
          if (!(suppress_warningsP())) {
            print_error_context(">> ERROR: ", STANDARD_OUTPUT);
            cout << endl << " " << "finish-walking-equal-tree: NOT YET IMPLEMENTED." << "." << endl;
          }
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPRINTREADABLYpo = old_OprintreadablyPO_001;
        resignal();
      }
    }
  }
  { Cons* return_temp = NULL;

    return1 = SGT_WALK_BOOLEAN;
    return (return_temp);
  }
}

Object* walk_equality_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;
    Standard_Object* dummy3;
    Standard_Object* dummy4;

    { Object* arg1 = NULL;
      Object* arg2 = NULL;
      Standard_Object* type1 = NULL;
      Standard_Object* type2 = NULL;

      arg1 = walk_a_tree(tree->second(), type1);
      arg2 = walk_a_tree(tree->third(), type2);
      tree->second_setter(arg1);
      tree->third_setter(arg2);
      if (vrlet_expressionP(arg1)) {
        return (walk_a_tree(percolate_out_vrlet_expression(tree, ((Cons*)(arg1)), SGT_WALK_BOOLEAN, dummy1), return1));
      }
      if (vrlet_expressionP(arg2)) {
        return (walk_a_tree(percolate_out_vrlet_expression(tree, ((Cons*)(arg2)), SGT_WALK_BOOLEAN, dummy2), return1));
      }
      type1 = type_spec_to_base_type(type1);
      type2 = type_spec_to_base_type(type2);
      if (!((type1 == SGT_WALK_UNKNOWN) ||
          ((type2 == SGT_WALK_UNKNOWN) ||
           (subtype_ofP(((Surrogate*)(type1)), ((Surrogate*)(type2))) ||
            subtype_ofP(((Surrogate*)(type2)), ((Surrogate*)(type1))))))) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_warning();
                if (!(suppress_warningsP())) {
                  print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                  cout << endl << " " << "This equality test will always fail due to disjoint " << "argument types:" << endl << "    " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                }
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
              resignal();
            }
          }
        }
      }
      { Object* test_value_001 = tree->first();

        if ((test_value_001 == SYM_WALK_EQp) ||
            (test_value_001 == SYM_WALK_e)) {
          tree->first_setter(SYM_WALK_EQp);
          tree->second_setter(sys_tree(tree->second(), type1, dummy3));
          tree->third_setter(sys_tree(tree->third(), type2, dummy4));
          { Object* return_temp = tree;

            return1 = SGT_WALK_BOOLEAN;
            return (return_temp);
          }
        }
        else if (test_value_001 == SYM_WALK_EQLp) {
          return (finish_walking_eql_tree(tree, ((Surrogate*)(type1)), ((Surrogate*)(type2)), return1));
        }
        else {
          cerr << "`" << test_value_001 << "'" << " is not a valid case option";
        }
      }
    }
  }
}

Surrogate* more_general_numeric_type(Surrogate* type1, Surrogate* type2) {
  { int position1 = oNUMERIC_TYPE_HIERARCHYo->position(type1, 0);
    int position2 = oNUMERIC_TYPE_HIERARCHYo->position(type2, 0);

    if ((position1 == NULL_INTEGER) ||
        (position2 == NULL_INTEGER)) {
      return (SGT_WALK_NUMBER);
    }
    if (position1 > position2) {
      return (type1);
    }
    else {
      return (type2);
    }
  }
}

Cons* yield_arithmetic_operator_call_tree(Symbol* renamed_Operator, Cons* operands) {
  return (listO(4, SYM_WALK_SYS_CALL_METHOD, SGT_WALK_NUMBER, renamed_Operator, operands->concatenate(NIL)));
}

Cons* yield_nested_arithmetic_operator_call_tree(Symbol* renamed_Operator, Cons* operands) {
  { int nofoperands = operands->length();
    Cons* parenthesizedtree = yield_arithmetic_operator_call_tree(renamed_Operator, cons_list(2, operands->first(), operands->second()));

    { int i = NULL_INTEGER;
      int iter_001 = 2;
      int upper_bound_001 = nofoperands - 1;

      while (iter_001 <= upper_bound_001) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        parenthesizedtree = yield_arithmetic_operator_call_tree(renamed_Operator, cons_list(2, parenthesizedtree, operands->nth(i)));
      }
    }
    return (parenthesizedtree);
  }
}

Object* walk_arithmetic_tree(Cons* tree, Surrogate*& return1) {
  { Object* renamed_Operator = tree->first();
    Cons* operands = tree->rest;
    int nofoperands = operands->length();
    Object* operand = NULL;
    Standard_Object* operandtype = NULL;
    Surrogate* returntype = SGT_WALK_INTEGER;

    switch (nofoperands) {
      case 0: 
        if (renamed_Operator == SYM_WALK_i) {
          { Object* return_temp = integer_wrap_literal(0);

            return1 = SGT_WALK_INTEGER;
            return (return_temp);
          }
        }
        else if (renamed_Operator == SYM_WALK_o) {
          { Object* return_temp = integer_wrap_literal(1);

            return1 = SGT_WALK_INTEGER;
            return (return_temp);
          }
        }
        else {
          bad_argument_countP(tree, 1);
          { Cons* value_001 = NULL;
            Standard_Object* value_002 = NULL;

            value_001 = walk_dont_call_me_tree(tree, SGT_WALK_NUMBER, value_002);
            { Object* return_temp = value_001;

              return1 = ((Surrogate*)(value_002));
              return (return_temp);
            }
          }
        }
      break;
      case 1: 
        if ((renamed_Operator == SYM_WALK_i) ||
            (renamed_Operator == SYM_WALK_o)) {
          { Object* value_003 = NULL;
            Standard_Object* value_004 = NULL;

            value_003 = walk_expression_tree(operands->first(), SGT_WALK_NUMBER, ((Symbol*)(renamed_Operator)), FALSE, value_004);
            { Object* return_temp = value_003;

              return1 = ((Surrogate*)(value_004));
              return (return_temp);
            }
          }
        }
        else if ((renamed_Operator == SYM_WALK__) ||
            (renamed_Operator == SYM_WALK_s)) {
          operands->rest = cons(operands->first(), NIL);
          operands->first_setter(((renamed_Operator == SYM_WALK__) ? ((Integer_Wrapper*)(integer_wrap_literal(0))) : ((Integer_Wrapper*)(integer_wrap_literal(1)))));
        }
        else {
          cerr << "`" << renamed_Operator << "'" << " is not a valid case option";
        }
      break;
      default:
      break;
    }
    { Cons_Iterator* it = operands->allocate_iterator();

      while (it->nextP()) {
        operand = walk_expression_tree(it->value, SGT_WALK_NUMBER, ((Symbol*)(renamed_Operator)), FALSE, operandtype);
        returntype = more_general_numeric_type(returntype, type_spec_to_base_type(operandtype));
        it->value_setter(operand);
      }
    }
    if ((renamed_Operator == SYM_WALK_s) &&
        (returntype == SGT_WALK_INTEGER)) {
      if (wrapperP(operands->first())) {
        operands->first_setter(float_wrap_literal(((Integer_Wrapper*)(operands->first()))->wrapper_value * 1.0));
      }
      else if (wrapperP(operands->second())) {
        operands->second_setter(float_wrap_literal(((Integer_Wrapper*)(operands->second()))->wrapper_value * 1.0));
      }
      else {
        operands = cons(operands->first(), cons(float_wrap_literal(1.0), operands->rest->concatenate(NIL)));
        nofoperands = nofoperands + 1;
      }
      returntype = SGT_WALK_FLOAT;
    }
    if ((nofoperands > 2) &&
        (!(translator_output_language() == KWD_WALK_COMMON_LISP))) {
      { Object* return_temp = yield_nested_arithmetic_operator_call_tree(((Symbol*)(renamed_Operator)), operands);

        return1 = returntype;
        return (return_temp);
      }
    }
    else {
      { Object* return_temp = yield_arithmetic_operator_call_tree(((Symbol*)(renamed_Operator)), operands);

        return1 = returntype;
        return (return_temp);
      }
    }
  }
}

Object* walk_quoted_tree(Cons* tree, Standard_Object*& return1) {
  if (bad_argument_countP(tree, 1)) {
    return (walk_dont_call_me_tree(tree, SGT_WALK_UNKNOWN, return1));
  }
  { Object* argument = tree->second();
    boolean quotedliteralP = (!consP(argument)) ||
        nilP(argument);
    char* objectname = NULL;

    if (quotedliteralP) {
      { Object* otree = NULL;
        Standard_Object* otype = NULL;

        otree = walk_a_tree(bquotify(argument), otype);
        tree->free_parse_tree();
        { Object* return_temp = otree;

          return1 = otype;
          return (return_temp);
        }
      }
    }
    objectname = name_quoted_tree(((Cons*)(argument)));
    tree->free_parse_tree();
    return (walk_a_tree(listO(3, SYM_WALK_GET_QUOTED_TREE, string_wrap_literal(objectname), cons(string_wrap_literal(oMODULEo->module_full_name), NIL)), return1));
  }
}

Object* walk_bquote_tree(Cons* tree, Standard_Object*& return1) {
  if (bad_argument_countP(tree, 1)) {
    return (walk_dont_call_me_tree(tree, SGT_WALK_UNKNOWN, return1));
  }
  { Object* otree = NULL;
    Standard_Object* otype = NULL;

    otree = walk_a_tree(simplify_bquote_tree(expand_bquote_tree(tree->second())), otype);
    free_cons_list(tree);
    { Object* return_temp = otree;

      return1 = otype;
      return (return_temp);
    }
  }
}

Object* expand_macro(Cons* tree) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;

    { Symbol* macroname = ((Symbol*)(tree->first()));
      Method_Slot* expanderobject = lookup_macro(macroname);
      cpp_function_code expandercode = expanderobject->function_code;
      Cons* args = tree->rest;
      Object* expansion = NULL;

      if (expandercode == NULL) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Macro expander code for " << "`" << de_uglify_parse_tree(macroname) << "'" << " is not available" << "." << endl;
                }
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
              resignal();
            }
          }
        }
        return (walk_dont_call_me_tree(tree, SGT_WALK_UNKNOWN, dummy1));
      }
      if (expanderobject->method_body_argumentP_reader()) {
        switch (expanderobject->method_argument_count()) {
          case 1: 
            expansion = ((Object* (*) (Cons*))expandercode)(args);
            tree->rest = NIL;
          break;
          case 2: 
            expansion = ((Object* (*) (Object*, Cons*))expandercode)(args->first(), args->rest);
            args->rest = NIL;
          break;
          case 3: 
            expansion = ((Object* (*) (Object*, Object*, Cons*))expandercode)(args->first(), args->second(), args->rest->rest);
            args->rest->rest = NIL;
          break;
          case 4: 
            expansion = ((Object* (*) (Object*, Object*, Object*, Cons*))expandercode)(args->first(), args->second(), args->nth(2), args->nth_rest(2));
            args->nth_rest_setter(NIL, 2);
          break;
          case 5: 
            expansion = ((Object* (*) (Object*, Object*, Object*, Object*, Cons*))expandercode)(args->first(), args->second(), args->nth(2), args->nth(3), args->nth_rest(3));
            args->nth_rest_setter(NIL, 3);
          break;
          default:
            { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Too many arguments in definition of macro " << "`" << de_uglify_parse_tree(macroname) << "'" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_002;
                  resignal();
                }
              }
            }
            return (walk_dont_call_me_tree(tree, SGT_WALK_UNKNOWN, dummy2));
        }
      }
      else {
        expansion = apply(expandercode, tree->rest);
      }
      free_cons_list(tree);
      return (expansion);
    }
  }
}

Object* walk_macro_tree(Cons* tree, Standard_Object*& return1) {
  return (walk_a_tree(expand_macro(tree), return1));
}

Cons* walk_print_stream_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;
    Standard_Object* dummy2;

    if (tree->length() <= 2) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Missing arguments in print statement: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
      return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
    }
    { Object* renamed_Operator = tree->first();
      boolean printnativestreamP = renamed_Operator == SYM_WALK_PRINT_NATIVE_STREAM;
      Object* streamtree = tree->second();
      Object* otree = NULL;
      Standard_Object* otype = NULL;

      if (keywordP(streamtree)) {
        if (!((streamtree == KWD_WALK_WARN) ||
            ((streamtree == KWD_WALK_ERROR) ||
             (streamtree == KWD_WALK_CONTINUABLE_ERROR)))) {
          { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  signal_translation_error();
                  if (!(suppress_warningsP())) {
                    print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                    cout << endl << " " << "Illegal stream argument in print statement: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                  }
                  oPRINTREADABLYpo = old_OprintreadablyPO_002;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oPRINTREADABLYpo = old_OprintreadablyPO_002;
                resignal();
              }
            }
          }
          return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
        }
      }
      else {
        otree = walk_expression_tree(streamtree, (printnativestreamP ? ((Surrogate*)(SGT_WALK_NATIVE_OUTPUT_STREAM)) : ((Surrogate*)(SGT_WALK_OUTPUT_STREAM))), ((Symbol*)(tree->first())), FALSE, otype);
        if ((!printnativestreamP) &&
            sub_type_spec_ofP(otype, SGT_WALK_OUTPUT_STREAM)) {
          otree = walk_a_tree(listO(3, SYM_WALK_NATIVE_STREAM, otree, NIL), dummy1);
        }
        tree->first_setter(SYM_WALK_PRINT_NATIVE_STREAM);
        tree->second_setter(otree);
      }
      { Cons_Iterator* it = tree->rest->rest->allocate_iterator();

        while (it->nextP()) {
          otree = walk_expression_tree(it->value, SGT_WALK_UNKNOWN, ((Symbol*)(renamed_Operator)), FALSE, otype);
          it->value_setter(otree);
          if (!(otree == SYM_WALK_EOL)) {
            { Object* otree_001 = otree;

              if (stringP(otree)) {
                { String_Wrapper* otree = NULL;

                  otree = ((String_Wrapper*)(otree_001));
                }
              }
              else if (integerP(otree)) {
                { Integer_Wrapper* otree = NULL;

                  otree = ((Integer_Wrapper*)(otree_001));
                  it->value_setter(string_wrap_literal(stringify(otree)));
                }
              }
              else if (floatP(otree)) {
                { Float_Wrapper* otree = NULL;

                  otree = ((Float_Wrapper*)(otree_001));
                  it->value_setter(string_wrap_literal(stringify(otree)));
                }
              }
              else if (characterP(otree)) {
                { Character_Wrapper* otree = NULL;

                  otree = ((Character_Wrapper*)(otree_001));
                  it->value_setter(string_wrap_literal(make_string(1, otree->wrapper_value)));
                }
              }
              else {
                it->value_setter(sys_tree(otree, otype, dummy2));
              }
            }
          }
        }
      }
      { Cons* return_temp = tree;

        return1 = SGT_WALK_VOID;
        return (return_temp);
      }
    }
  }
}

boolean warn_about_undefined_methodsP() {
  return (oCURRENT_ENVIRONMENT_FEATURESo->memberP(KWD_WALK_WARN_ABOUT_UNDEFINED_METHODS));
}

boolean warn_about_missing_methodsP() {
  return ((!(translator_output_language() == KWD_WALK_COMMON_LISP)) ||
      oCURRENT_ENVIRONMENT_FEATURESo->memberP(KWD_WALK_WARN_ABOUT_MISSING_METHODS));
}

Cons* walk_undefined_slot_tree(Cons* tree, Standard_Object* firstargtype, boolean warnP, Surrogate*& return1) {
  { Standard_Object* dummy1;

    { Cons* cursor = tree->rest->rest;
      Surrogate* type = type_spec_to_base_type(firstargtype);
      Symbol* operatorname = ((Symbol*)(tree->first()));

      free_transient_type_spec(firstargtype);
      while (cursor->non_emptyP()) {
        cursor->value = walk_expression_tree(cursor->value, NULL, operatorname, TRUE, dummy1);
        cursor = cursor->rest;
      }
      if (warnP &&
          (!symbol_common_lispP(operatorname))) {
        { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "Reference to undefined method or function named " << "`" << de_uglify_parse_tree(operatorname) << "'" << endl << "   in the expression:" << endl << "   " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                }
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
              resignal();
            }
          }
        }
      }
      { Cons* return_temp = listO(3, SYM_WALK_SYS_CALL_METHOD, type, tree->concatenate(NIL));

        return1 = SGT_WALK_UNKNOWN;
        return (return_temp);
      }
    }
  }
}

Cons* walk_slot_on_abstract_type_tree(Cons* tree, Surrogate* abstracttype, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    { Object* methodname = tree->first();
      Method_Slot* prototypemethod = find_prototype_method(((Symbol*)(methodname)), abstracttype);
      boolean undefinedmethodP = TRUE;
      Object* otree = NULL;
      Standard_Object* otype = NULL;

      if (prototypemethod != NULL) {
        undefinedmethodP = FALSE;
        if (warn_about_missing_methodsP()) {
          { int nofsubs = NULL_INTEGER;
            int nofmethods = NULL_INTEGER;
            boolean compatibleP = FALSE;

            nofsubs = compatible_real_methods(prototypemethod, abstracttype, nofmethods, compatibleP);
            if ((nofsubs == nofmethods) &&
                compatibleP) {
              { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_warning();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Inferred the method " << "`" << de_uglify_parse_tree(methodname) << "'" << " on the abstract" << endl << "   type " << "`" << de_uglify_parse_tree(abstracttype) << "'" << ", since " << "`" << de_uglify_parse_tree(methodname) << "'" << " is implemented" << endl << "   on all non-abstract subtypes of " << "`" << de_uglify_parse_tree(abstracttype) << "'" << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    resignal();
                  }
                }
              }
              tree->second_setter(sys_tree(tree->second(), prototypemethod->slot_owner, dummy1));
              otree = walk_call_slot_tree(tree, otype);
            }
            else if (nofsubs == nofmethods) {
              { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_warning();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Could not infer " << "`" << de_uglify_parse_tree(methodname) << "'" << " on abstract type " << "`" << de_uglify_parse_tree(abstracttype) << "'" << "," << endl << "   since the implementations of " << "`" << de_uglify_parse_tree(methodname) << "'" << " on the non-abstract" << endl << "   subtypes of " << "`" << de_uglify_parse_tree(abstracttype) << "'" << " are not all compatible" << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    resignal();
                  }
                }
              }
            }
            else {
              { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_warning();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Could not infer " << "`" << de_uglify_parse_tree(methodname) << "'" << " on abstract type " << "`" << de_uglify_parse_tree(abstracttype) << "'" << "," << endl << "   since " << "`" << de_uglify_parse_tree(methodname) << "'" << " is only implemented on " << "`" << de_uglify_parse_tree(integer_wrap_literal(nofmethods)) << "'" << " of the " << "`" << de_uglify_parse_tree(integer_wrap_literal(nofsubs)) << "'" << endl << "   non-abstract subtypes of " << "`" << de_uglify_parse_tree(abstracttype) << "'" << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_003;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_003;
                    resignal();
                  }
                }
              }
              if (!(compatibleP)) {
                cout << " Additionally, the method signatures are " << "not compatible." << endl;
              }
            }
          }
        }
      }
      if (undefinedmethodP) {
        { Cons* value_001 = NULL;
          Surrogate* value_002 = NULL;

          value_001 = walk_undefined_slot_tree(tree, abstracttype, warn_about_undefined_methodsP(), value_002);
          {
            otree = value_001;
            otype = value_002;
          }
        }
      }
      else {
        { Cons* value_003 = NULL;
          Surrogate* value_004 = NULL;

          value_003 = walk_undefined_slot_tree(tree, abstracttype, FALSE, value_004);
          {
            otree = value_003;
            otype = value_004;
          }
        }
      }
      { Cons* return_temp = ((Cons*)(otree));

        return1 = otype;
        return (return_temp);
      }
    }
  }
}

Method_Slot* find_prototype_method(Symbol* methodname, Surrogate* abstracttype) {
  { Slot* method = NULL;

    { Surrogate* sub = NULL;
      Cons* iter_001 = ((Class*)(abstracttype->surrogate_value))->class_direct_subs->the_cons_list;

      while (!nilP(iter_001)) {
        {
          sub = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (((Class*)(sub->surrogate_value)) != NULL) {
          if (((Class*)(sub->surrogate_value))->abstractP) {
            method = find_prototype_method(methodname, sub);
          }
          else {
            method = safe_lookup_slot(((Class*)(sub->surrogate_value)), methodname);
          }
          if ((method != NULL) &&
              (!storage_slotP(method))) {
            return (((Method_Slot*)(method)));
          }
        }
      }
    }
    return (NULL);
  }
}

int compatible_real_methods(Method_Slot* prototypemethod, Surrogate* abstracttype, int& return1, boolean& return2) {
  { Symbol* methodname = prototypemethod->slot_name;
    int nofrealsubtypes = 0;
    int nofrealmethods = 0;
    boolean compatiblesignaturesP = TRUE;

    { Surrogate* sub = NULL;
      Cons* iter_001 = ((Class*)(abstracttype->surrogate_value))->class_direct_subs->the_cons_list;

      while (!nilP(iter_001)) {
        {
          sub = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (((Class*)(sub->surrogate_value))->abstractP) {
          { int nofsubs = NULL_INTEGER;
            int nofmethods = NULL_INTEGER;
            boolean compatibleP = FALSE;

            nofsubs = compatible_real_methods(prototypemethod, sub, nofmethods, compatibleP);
            nofrealsubtypes = nofrealsubtypes + nofsubs;
            nofrealmethods = nofrealmethods + nofmethods;
            if (!(compatibleP)) {
              compatiblesignaturesP = FALSE;
            }
          }
        }
        else {
          { Method_Slot* thismethod = NULL;

            nofrealsubtypes = nofrealsubtypes + 1;
            thismethod = ((Method_Slot*)(safe_lookup_slot(((Class*)(sub->surrogate_value)), methodname)));
            if ((thismethod != NULL) &&
                (!storage_slotP(thismethod))) {
              nofrealmethods = nofrealmethods + 1;
              if (!(identical_signaturesP(prototypemethod, thismethod))) {
                compatiblesignaturesP = FALSE;
              }
            }
          }
        }
      }
    }
    { int return_temp = nofrealsubtypes;

      return1 = nofrealmethods;
      return2 = compatiblesignaturesP;
      return (return_temp);
    }
  }
}

Cons* Slot::finish_walking_call_slot_tree(Cons* tree, Standard_Object* firstargtype, Standard_Object*& return1) {
  { Slot* self = this;

    {
      tree = tree;
      firstargtype = firstargtype;
    }
    cerr << "finish-walking-call-slot-tree: Not defined on " << "`" << self << "'";
    { Cons* return_temp = NULL;

      return1 = NULL;
      return (return_temp);
    }
  }
}

Cons* Storage_Slot::finish_walking_call_slot_tree(Cons* tree, Standard_Object* firstargtype, Standard_Object*& return1) {
  { Storage_Slot* self = this;
    Standard_Object* dummy1;

    { Object* objectref = tree->second();
      Standard_Object* otype = self->compute_return_type_spec(firstargtype);

      if ((self->reader() != NULL) &&
          (safe_lookup_slot(type_spec_to_class(firstargtype), self->reader()) != NULL)) {
        free_transient_type_spec(firstargtype);
        tree->first_setter(self->reader());
        return (walk_a_cons_tree(tree, return1));
      }
      free_cons_list(tree);
      if (system_defined_slot_readerP(self)) {
        { Cons* return_temp = listO(3, SYM_WALK_SYS_CALL_METHOD, self->slot_owner, cons(self->slot_name, cons(objectref, NIL)));

          return1 = otype;
          return (return_temp);
        }
      }
      else {
        { Cons* return_temp = yield_slot_value_tree(self, objectref, firstargtype, otype, NULL, dummy1);

          return1 = otype;
          return (return_temp);
        }
      }
    }
  }
}

Cons* yield_listified_variable_arguments(Cons* walkedargs, Standard_Object* targettype, boolean wrapargsP) {
  { Standard_Object* dummy1;

    if (walkedargs->non_emptyP()) {
      { Object* listifiedargs = SYM_WALK_NIL;

        { Cons_Iterator* it = walkedargs->allocate_iterator();

          while (it->nextP()) {
            { Object* arg = it->value;

              arg = sys_tree(arg, targettype, dummy1);
              if (wrapargsP) {
                arg = cons(((targettype == SGT_WALK_BOOLEAN) ? ((Symbol*)(SYM_WALK_WRAP_BOOLEAN)) : ((Symbol*)(SYM_WALK_WRAP_LITERAL))), cons(arg, NIL));
              }
              it->value_setter(arg);
            }
          }
        }
        { Keyword* test_value_001 = translator_output_language();

          if (test_value_001 == KWD_WALK_JAVA) {
            { Object* arg = NULL;
              Cons* iter_001 = walkedargs->reverse();

              while (!nilP(iter_001)) {
                {
                  arg = iter_001->value;
                  iter_001 = iter_001->rest;
                }
                listifiedargs = listO(3, SYM_WALK_CONS, arg, cons(listifiedargs, NIL));
              }
            }
          }
          else {
            listifiedargs = listO(3, SYM_WALK_CONS_LIST, walkedargs->value, walkedargs->rest->concatenate(NIL));
          }
        }
        return (((Cons*)(walk_without_type_tree(listifiedargs))));
      }
    }
    else {
      return (cons(SYM_WALK_NIL, NIL));
    }
  }
}

Cons* walk_variable_arguments(Cons* arguments, Method_Slot* method) {
  { Standard_Object* dummy1;

    toggle_variable_arguments_type(method);
    { Standard_Object* targettype = variable_arguments_type(method);
      boolean listifyargsP = pass_variable_arguments_as_listP(method);
      boolean wrapargsP = listifyargsP &&
          sub_type_spec_ofP(targettype, SGT_WALK_LITERAL);
      Cons* cursor = arguments;

      while (cursor->non_emptyP()) {
        cursor->value = walk_expression_tree(cursor->value, targettype, method->slot_name, FALSE, dummy1);
        cursor = cursor->rest;
      }
      if (listifyargsP) {
        { Cons* listifiedargs = yield_listified_variable_arguments(arguments, targettype, wrapargsP);

          if (arguments->emptyP()) {
            return (listifiedargs);
          }
          arguments->value = listifiedargs;
          arguments->rest = NIL;
        }
      }
      return (arguments);
    }
  }
}

Cons* Method_Slot::finish_walking_call_slot_tree(Cons* tree, Standard_Object* firstargtype, Standard_Object*& return1) {
  { Method_Slot* self = this;
    Standard_Object* dummy1;

    { Symbol* methodname = self->slot_name;
      Standard_Object* otypespec = self->compute_return_type_spec(firstargtype);
      Cons* otree = NULL;

      { List* ptypespecs = self->method_parameter_type_specifiers_reader();
        int nofparameters = ptypespecs->length();
        Cons* cursor = tree->rest->rest;

        { int pindex = NULL_INTEGER;
          Standard_Object* targetts = NULL;
          Cons* iter_001 = ptypespecs->rest();
          int iter_002 = 2;
          int upper_bound_001 = nofparameters;
          boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

          while ((!nilP(iter_001)) &&
              (unboundedP_001 ||
               (iter_002 <= upper_bound_001))) {
            {
              targetts = ((Standard_Object*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            {
              pindex = iter_002;
              iter_002 = iter_002 + 1;
            }
            targetts = compute_relative_type_spec(targetts, firstargtype);
            if ((pindex == nofparameters) &&
                self->method_variable_argumentsP_reader()) {
              tree->nth_rest_setter(walk_variable_arguments(cursor, self), pindex);
              break;
            }
            cursor->value = walk_expression_tree(cursor->value, targetts, methodname, TRUE, dummy1);
            cursor = cursor->rest;
          }
        }
      }
      free_transient_type_spec(firstargtype);
      { Object* arg = NULL;
        Cons* iter_003 = tree->rest;

        while (!nilP(iter_003)) {
          {
            arg = iter_003->value;
            iter_003 = iter_003->rest;
          }
          if (vrlet_expressionP(arg)) {
            return (percolate_out_vrlet_expression(tree, ((Cons*)(arg)), otypespec, return1));
          }
        }
      }
      if (self->method_functionP) {
        otree = cons(SYM_WALK_SYS_CALL_FUNCTION, tree->concatenate(NIL));
      }
      else {
        otree = listO(3, SYM_WALK_SYS_CALL_METHOD, self->slot_owner, tree->concatenate(NIL));
      }
      if (procedural_expressionP(tree->fifth())) {
        { Standard_Object* outgoingtypespec = otypespec;

          otree = transform_procedural_expression(otree, ((Cons*)(tree->fifth())), outgoingtypespec, otypespec);
          free_transient_type_spec(outgoingtypespec);
        }
      }
      { Cons* return_temp = otree;

        return1 = otypespec;
        return (return_temp);
      }
    }
  }
}

Cons* quote_arguments(Method_Slot* method, Cons* arguments) {
  { List* ptypespecs = method->method_parameter_type_specifiers_reader();
    int lastparameterindex = ptypespecs->length() - 1;
    Standard_Object* varargstype = (method->method_variable_argumentsP_reader() ? ((Standard_Object*)(variable_arguments_type(method))) : ((Standard_Object*)(NULL)));
    Standard_Object* ptype = NULL;

    { int argindex = NULL_INTEGER;
      Cons_Iterator* it = arguments->allocate_iterator();
      int iter_001 = 0;

      while (it->nextP()) {
        {
          argindex = iter_001;
          iter_001 = iter_001 + 1;
        }
        if (!(surrogateP(it->value) ||
            keywordP(it->value))) {
          if ((argindex >= lastparameterindex) &&
              (varargstype != NULL)) {
            ptype = varargstype;
          }
          else {
            ptype = ((Standard_Object*)(ptypespecs->nth(argindex)));
          }
          if ((it->value == SYM_WALK_NULL) ||
              (((ptype == SGT_WALK_BOOLEAN) &&
              ((it->value == SYM_WALK_TRUE) ||
               (it->value == SYM_WALK_FALSE))) ||
               (wrapperP(it->value) &&
                ((ptype != NULL) &&
                 sub_type_spec_ofP(ptype, SGT_WALK_LITERAL))))) {
            continue;
          }
          it->value_setter(listO(3, SYM_WALK_BQUOTE, it->value, NIL));
        }
      }
    }
    return (arguments);
  }
}

Standard_Object* walk_first_argument_to_function(Method_Slot* fnslot, Cons* tree) {
  { List* ptypespecs = fnslot->method_parameter_type_specifiers_reader();
    Standard_Object* targetts = ((Standard_Object*)(ptypespecs->first()));

    if (!fnslot->method_evaluate_argumentsP_reader()) {
      tree->rest = quote_arguments(fnslot, tree->rest);
    }
    if (fnslot->method_variable_argumentsP_reader() &&
        (ptypespecs->length() == 1)) {
      tree->rest = walk_variable_arguments(tree->rest, fnslot);
      return (SGT_WALK_UNKNOWN);
    }
    if (tree->rest->emptyP() ||
        fnslot->method_parameter_type_specifiers_reader()->emptyP()) {
      return (SGT_WALK_UNKNOWN);
    }
    { Object* otree = NULL;
      Standard_Object* otype = NULL;

      otree = walk_expression_tree(tree->second(), targetts, fnslot->slot_name, TRUE, otype);
      tree->second_setter(otree);
      { Object* otree_001 = otree;

        if (integerP(otree)) {
          { Integer_Wrapper* otree = NULL;

            otree = ((Integer_Wrapper*)(otree_001));
            { Symbol* test_value_001 = fnslot->slot_name;

              if (test_value_001 == SYM_WALK_GET_SYM) {
                register_symbol(get_sym_from_offset(otree->wrapper_value));
              }
              else if (test_value_001 == SYM_WALK_GET_SGT) {
                register_symbol(get_sgt_from_offset(otree->wrapper_value));
              }
              else if (test_value_001 == SYM_WALK_GET_KWD) {
                register_symbol(get_kwd_from_offset(otree->wrapper_value));
              }
              else {
              }
            }
          }
        }
        else {
        }
      }
      return (otype);
    }
  }
}

Object* walk_call_slot_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    { Object* slotname = tree->first();
      Object* walkedfirstarg = NULL;
      Standard_Object* firstargtype = SGT_WALK_VOID;
      Class* firstargclass = NULL;
      boolean illegalfirstargP = FALSE;
      int previouserrors = oTRANSLATIONERRORSo;
      Slot* slot = NULL;

      if (lookup_macro(((Symbol*)(slotname))) != NULL) {
        return (walk_macro_tree(tree, return1));
      }
      { 
        slot = lookup_function_or_stella_function(((Symbol*)(slotname)));
        if (slot != NULL) {
          firstargtype = walk_first_argument_to_function(((Method_Slot*)(slot)), tree);
        }
        else {
          if (tree->rest->non_emptyP()) {
            walkedfirstarg = walk_a_tree(tree->second(), firstargtype);
            tree->second_setter(coerce_a_tree(walkedfirstarg, firstargtype, firstargtype, dummy1));
            if (voidP(firstargtype)) {
              { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_error();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << " " << "First argument in call to " << "`" << de_uglify_parse_tree(slotname) << "'" << " returns @VOID" << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    resignal();
                  }
                }
              }
              return (walk_dont_call_me_tree(tree, SGT_WALK_UNKNOWN, return1));
            }
            firstargclass = type_spec_to_class(firstargtype);
            slot = safe_lookup_slot(firstargclass, ((Symbol*)(slotname)));
          }
        }
      }
      illegalfirstargP = oTRANSLATIONERRORSo > previouserrors;
      if (vrlet_expressionP(tree->second())) {
        return (percolate_out_vrlet_expression(tree, ((Cons*)(tree->second())), SGT_WALK_UNKNOWN, return1));
      }
      if (slot == NULL) {
        if (warn_about_undefined_methodsP() &&
            ((!(firstargtype == SGT_WALK_UNKNOWN)) &&
             ((firstargclass != NULL) &&
              firstargclass->abstractP))) {
          return (walk_slot_on_abstract_type_tree(tree, type_spec_to_base_type(firstargtype), return1));
        }
        else {
          { Cons* value_001 = NULL;
            Surrogate* value_002 = NULL;

            value_001 = walk_undefined_slot_tree(tree, (voidP(firstargtype) ? ((Standard_Object*)(SGT_WALK_UNKNOWN)) : ((Standard_Object*)(firstargtype))), (!illegalfirstargP) &&
                warn_about_undefined_methodsP(), value_002);
            { Object* return_temp = value_001;

              return1 = value_002;
              return (return_temp);
            }
          }
        }
      }
      { int minargs = slot->method_argument_count();
        int maxargs = minargs;

        { Slot* slot_001 = slot;

          if (method_slotP(slot)) {
            { Method_Slot* slot = NULL;

              slot = ((Method_Slot*)(slot_001));
              if (slot->method_variable_argumentsP_reader() ||
                  slot->method_body_argumentP_reader()) {
                minargs = minargs - 1;
                maxargs = NULL_INTEGER;
              }
            }
          }
          else {
          }
        }
        if (bad_argument_rangeP(tree, minargs, maxargs)) {
          return (walk_dont_call_me_tree(tree, SGT_WALK_UNKNOWN, return1));
        }
      }
      { Object* otree = NULL;
        Standard_Object* otype = NULL;

        otree = slot->finish_walking_call_slot_tree(tree, firstargtype, otype);
        return (sys_tree_if_needed(slot, otree, firstargtype, otype, return1));
      }
    }
  }
}

Cons* yield_synthesized_method_body(Translation_Unit* unit) {
  { Method_Slot* method = ((Method_Slot*)(unit->the_object));
    Cons* body = ((Cons*)(unit->code_register));

    if (method->method_parameter_names_reader() == NULL) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Missing parameters for :inherits-through method" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
    }
    if (body->non_emptyP()) {
      { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Over-specified definition of :inherits-through method" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_002;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_002;
            resignal();
          }
        }
      }
      return (body);
    }
    else {
      return (synthesize_method_body(method));
    }
  }
}

boolean pass_variable_arguments_as_listP(Method_Slot* method) {
  return (method_must_be_evaluableP(method) ||
      (translator_output_language() == KWD_WALK_JAVA));
}

void toggle_variable_arguments_type(Method_Slot* method) {
  { Parametric_Type_Specifier* rvtype = ((Parametric_Type_Specifier*)(((Standard_Object*)(method->method_parameter_type_specifiers_reader()->last()))));
    Surrogate* basetype = rvtype->specifier_base_type;
    List* parametertypes = rvtype->specifier_parameter_types;
    boolean listifyP = pass_variable_arguments_as_listP(method);

    if (basetype == SGT_WALK_ARGUMENT_LIST) {
      if (listifyP) {
        rvtype->specifier_base_type = SGT_WALK_CONS;
        if (sub_type_spec_ofP(((Standard_Object*)(parametertypes->first())), SGT_WALK_LITERAL)) {
          parametertypes->push(type_spec_to_base_type(((Standard_Object*)(rvtype->specifier_parameter_types->first())))->type_to_wrapped_type());
        }
      }
    }
    else if (basetype == SGT_WALK_CONS) {
      if (!listifyP) {
        rvtype->specifier_base_type = SGT_WALK_ARGUMENT_LIST;
        if (parametertypes->length() == 2) {
          parametertypes->pop();
        }
      }
    }
    else {
      cerr << "`" << basetype << "'" << " is not a valid case option";
    }
  }
}

Standard_Object* variable_arguments_type(Method_Slot* method) {
  { boolean dummy1;

    { Parametric_Type_Specifier* rvtype = ((Parametric_Type_Specifier*)(((Standard_Object*)(method->method_parameter_type_specifiers_reader()->last()))));
      List* parametertypes = rvtype->specifier_parameter_types;

      if (parametertypes->length() == 2) {
        return (((Standard_Object*)(rvtype->specifier_parameter_types->second())));
      }
      else {
        return (extract_parameter_type(rvtype, SYM_WALK_ANY_VALUE, dummy1));
      }
    }
  }
}

Cons* walk_method_object(Translation_Unit* unit) {
  { Method_Slot* method = ((Method_Slot*)(unit->the_object));
    Cons* body = ((Cons*)(unit->code_register));

    { Key_Value_List* old_OlocalvariabletypetableO_001 = oLOCALVARIABLETYPETABLEo;
      Key_Value_List* old_OlocalgensymtableO_001 = oLOCALGENSYMTABLEo;
      Key_Value_List* old_OspecialvariablestackO_001 = oSPECIALVARIABLESTACKo;
      Method_Slot* old_OmethodbeingwalkedO_001 = oMETHODBEINGWALKEDo;
      boolean old_OfoundreturnPO_001 = oFOUNDRETURNpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oLOCALVARIABLETYPETABLEo = new_key_value_list();
            oLOCALGENSYMTABLEo = new_key_value_list();
            oSPECIALVARIABLESTACKo = new_key_value_list();
            oMETHODBEINGWALKEDo = method;
            oFOUNDRETURNpo = FALSE;
            if (((Symbol*)(dynamic_slot_value(method, SYM_WALK_METHOD_INHERITS_THROUGH, NULL))) != NULL) {
              body = yield_synthesized_method_body(unit);
            }
            { Standard_Object* typespec = NULL;
              Symbol* name = NULL;
              Cons* iter_001 = method->method_parameter_names_reader()->the_cons_list;
              Cons* iter_002 = method->method_parameter_type_specifiers_reader()->the_cons_list;

              while ((!nilP(iter_001)) &&
                  (!nilP(iter_002))) {
                {
                  name = ((Symbol*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                {
                  typespec = ((Standard_Object*)(iter_002->value));
                  iter_002 = iter_002->rest;
                }
                walk_a_declaration(name, typespec, NULL, TRUE);
              }
            }
            if (method->method_variable_argumentsP_reader()) {
              toggle_variable_arguments_type(method);
            }
            if (!(body->emptyP())) {
              body = walk_list_of_trees(body);
              if ((!voidP(method->slot_base_type)) &&
                  (!oFOUNDRETURNpo)) {
                { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_error();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Missing return statement" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      resignal();
                    }
                  }
                }
              }
            }
            oLOCALVARIABLETYPETABLEo->free();
            oLOCALGENSYMTABLEo->free();
            oSPECIALVARIABLESTACKo->free();
            unit->code_register = body;
            { 
              oFOUNDRETURNpo = old_OfoundreturnPO_001;
              oMETHODBEINGWALKEDo = old_OmethodbeingwalkedO_001;
              oSPECIALVARIABLESTACKo = old_OspecialvariablestackO_001;
              oLOCALGENSYMTABLEo = old_OlocalgensymtableO_001;
              oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (body);
            }
            oFOUNDRETURNpo = old_OfoundreturnPO_001;
            oMETHODBEINGWALKEDo = old_OmethodbeingwalkedO_001;
            oSPECIALVARIABLESTACKo = old_OspecialvariablestackO_001;
            oLOCALGENSYMTABLEo = old_OlocalgensymtableO_001;
            oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oFOUNDRETURNpo = old_OfoundreturnPO_001;
          oMETHODBEINGWALKEDo = old_OmethodbeingwalkedO_001;
          oSPECIALVARIABLESTACKo = old_OspecialvariablestackO_001;
          oLOCALGENSYMTABLEo = old_OlocalgensymtableO_001;
          oLOCALVARIABLETYPETABLEo = old_OlocalvariabletypetableO_001;
          resignal();
        }
      }
    }
  }
}

void walk_defmethod_tree(Cons* tree) {
  { Method_Slot* method = NULL;

    { Translation_Unit* self_001 = new_translation_unit();

      self_001->category = SYM_WALK_METHOD;
      self_001->the_object = tree;
      oCURRENTTRANSLATIONUNITo = self_001;
    }
    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = FALSE;
            method = define_method_from_parse_tree(tree);
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          resignal();
        }
      }
    }
    if ((!method->method_functionP) &&
        ((method->slot_owner == NULL) ||
         (((Class*)(method->slot_owner->surrogate_value)) == NULL))) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Can't define method " << "`" << method->slot_name << "'" << " on the non-existent class " << "`" << method->slot_owner << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
      method->free();
      oCURRENTTRANSLATIONUNITo->free();
      oCURRENTTRANSLATIONUNITo = NULL;
    }
    else {
      oCURRENTTRANSLATIONUNITo->the_object = method;
      oCURRENTTRANSLATIONUNITo->code_register = tree->nth_rest(3);
      if (method_needs_lisp_macroP(method)) {
        register_native_name(method->slot_name, KWD_WALK_COMMON_LISP, KWD_WALK_FUNCTION);
      }
    }
  }
}

Cons* yield_initialize_slot_writer(Method_Slot* method) {
  { Symbol* slotname = method->slot_name;
    char* slotnamestring = slotname->symbol_name;
    Slot* slot = NULL;
    int setterstart = -1;

    while (string_search(slotnamestring, "-SETTER", setterstart + 1) != NULL_INTEGER) {
      setterstart = string_search(slotnamestring, "-SETTER", setterstart + 1);
    }
    if (setterstart > 0) {
      slotname = intern_derived_symbol(slotname, string_subsequence(slotnamestring, 0, setterstart));
      slot = safe_lookup_slot(((Class*)(method->slot_owner->surrogate_value)), slotname);
      if (storage_slotP(slot) &&
          (string_search(((Class*)(slot->slot_owner->surrogate_value))->class_stringified_source, ":WRITER", 0) == NULL_INTEGER)) {
        set_dynamic_slot_value(((Storage_Slot*)(slot)), SYM_WALK_SLOT_WRITER, method->slot_name, NULL);
        return (cons(listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_SLOT_WRITER, listO(4, SYM_WALK_CAST, listO(4, SYM_WALK_LOOKUP_SLOT, listO(3, SYM_WALK_TYPE_CLASS, slot->slot_owner, NIL), listO(3, SYM_WALK_BQUOTE, slotname, NIL), NIL), SYM_WALK_STORAGE_SLOT, NIL), NIL), listO(3, SYM_WALK_BQUOTE, method->slot_name, NIL), NIL), NIL));
      }
    }
    return (NIL);
  }
}

void walk_method_unit(Translation_Unit* unit) {
  { Translation_Unit* old_OcurrenttranslationunitO_001 = oCURRENTTRANSLATIONUNITo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oCURRENTTRANSLATIONUNITo = unit;
          { Method_Slot* method = ((Method_Slot*)(unit->the_object));
            Surrogate* owner = method->slot_owner;
            Symbol* name = method->slot_name;
            Cons* body = ((Cons*)(unit->code_register));
            boolean createmethodobjectP = TRUE;
            boolean createevaluatorwrapperP = FALSE;

            if ((!method->method_functionP) &&
                ((owner != NULL) &&
                 ((((Class*)(owner->surrogate_value)) != NULL) &&
                  (((Class*)(owner->surrogate_value))->mixinP &&
                   translate_to_single_inheritance_languageP())))) {
              { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_error();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Methods on mixin classes are currently not supported" << endl << " in single-inheritance target languages" << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    resignal();
                  }
                }
              }
              unit->free();
              {
                {
                  oCURRENTTRANSLATIONUNITo = old_OcurrenttranslationunitO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                }
                return;
              }
            }
            if (body->emptyP() &&
                (((Symbol*)(dynamic_slot_value(method, SYM_WALK_METHOD_INHERITS_THROUGH, NULL))) == NULL)) {
              walk_method_object(unit);
              if (!(method->method_nativeP_reader())) {
                createmethodobjectP = FALSE;
                if (oTRANSLATIONVERBOSITYLEVELo >= 3) {
                  cout << "Forward declaration of " << "`" << method << "'" << endl;
                }
              }
              unit->free();
            }
            else if (method->method_auxiliaryP_reader() ||
                unit->auxiliaryP) {
              createmethodobjectP = FALSE;
              oTRANSLATIONUNITSo->push(unit);
              walk_method_object(unit);
            }
            else {
              oTRANSLATIONUNITSo->push(unit);
              walk_method_object(unit);
            }
            if (createmethodobjectP) {
              if (method->method_commandP_reader() &&
                  (!commandP(method))) {
                { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_warning();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Ignored :command? declaration.  " << "Currently, only functions can be commands." << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_002;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_002;
                      resignal();
                    }
                  }
                }
              }
              if (method_needs_evaluator_wrapperP(method)) {
                createevaluatorwrapperP = TRUE;
                create_evaluator_wrapper_unit(method);
              }
              if (method_needs_lisp_macroP(method)) {
                create_lisp_macro_units(name, method);
              }
              if (method->method_nativeP_reader()) {
                walk_auxiliary_tree(listO(4, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_METHODS, yield_define_stella_method(method), NIL));
              }
              else {
                walk_auxiliary_tree(listO(4, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_METHODS, listO(4, SYM_WALK_LET, cons(listO(3, SYM_WALK_METHOD, yield_define_stella_method(method), NIL), NIL), (method->method_functionP ? ((Cons*)(listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_FUNCTION_CODE, SYM_WALK_METHOD, NIL), listO(4, SYM_WALK_THE_CODE, KWD_WALK_FUNCTION, name, NIL), NIL))) : ((Cons*)(listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_METHOD_CODE, SYM_WALK_METHOD, NIL), listO(4, SYM_WALK_THE_CODE, KWD_WALK_METHOD, method->slot_owner, cons(name, NIL)), NIL)))), (createevaluatorwrapperP ? ((Cons*)(cons(listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_EVALUATOR_WRAPPER_CODE, SYM_WALK_METHOD, NIL), listO(4, SYM_WALK_THE_CODE, KWD_WALK_FUNCTION, yield_evaluator_wrapper_name(name), NIL), NIL), NIL))) : ((Cons*)(NIL)))->concatenate(NIL)), NIL));
              }
              { Cons* writertree = yield_initialize_slot_writer(method);

                if (writertree->non_emptyP()) {
                  walk_auxiliary_tree(cons(SYM_WALK_STARTUP_TIME_PROGN, writertree->concatenate(NIL)));
                }
              }
            }
          }
          oCURRENTTRANSLATIONUNITo = old_OcurrenttranslationunitO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oCURRENTTRANSLATIONUNITo = old_OcurrenttranslationunitO_001;
        resignal();
      }
    }
  }
}

Cons* walk_sys_call_tree(Cons* tree, Standard_Object*& return1) {
  { Slot* slot = slot_from_expression_tree(tree);
    Standard_Object* slottype = SGT_WALK_UNKNOWN;

    if (slot != NULL) {
      slottype = ((Compound_Type_Specifier*)(dynamic_slot_value(slot, SYM_WALK_SLOT_TYPE_SPECIFIER, NULL)));
      { boolean test_value_001 = FALSE;

        test_value_001 = slottype != NULL;
        if (test_value_001) {
          if (anchored_type_specifierP(slottype)) {
            test_value_001 = TRUE;
          }
          else {
            { boolean foundP_001 = FALSE;

              { Standard_Object* ts = NULL;
                Cons* iter_001 = ((Parametric_Type_Specifier*)(slottype))->specifier_parameter_types->the_cons_list;

                while (!nilP(iter_001)) {
                  {
                    ts = ((Standard_Object*)(iter_001->value));
                    iter_001 = iter_001->rest;
                  }
                  if (anchored_type_specifierP(ts)) {
                    foundP_001 = TRUE;
                    break;
                  }
                }
              }
              test_value_001 = foundP_001;
            }
          }
        }
        if (test_value_001) {
          cerr << "walk-sys-call-tree: OOPS, can't handle anchored slot types: " << "`" << tree << "'";
        }
      }
      if (!(slottype != NULL)) {
        slottype = slot->type();
      }
    }
    { Cons* return_temp = tree;

      return1 = slottype;
      return (return_temp);
    }
  }
}

void walk_defclass_tree(Cons* tree) {
  { Translation_Unit* self_001 = new_translation_unit();

    self_001->category = SYM_WALK_CLASS;
    self_001->the_object = tree->second();
    oCURRENTTRANSLATIONUNITo = self_001;
  }
  { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTRANSIENTOBJECTSpo = FALSE;
          oCURRENTTRANSLATIONUNITo->the_object = define_class_from_parse_tree(tree);
          if (oCURRENTTRANSLATIONUNITo->the_object == NULL) {
            oCURRENTTRANSLATIONUNITo->free();
            oCURRENTTRANSLATIONUNITo = NULL;
          }
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
        resignal();
      }
    }
  }
  tree->free_parse_tree();
}

Cons* yield_initialize_hardwired_slots(Class* renamed_Class) {
  { Cons* hardwiredslotinitializers = NIL;

    if (create_native_classP(renamed_Class)) {
      { Slot* slot = NULL;
        Iterator* iter_001 = renamed_Class->class_slots();

        while (iter_001->nextP()) {
          {
            slot = ((Slot*)(iter_001->value));
          }
          { Slot* slot_001 = slot;

            if (storage_slotP(slot)) {
              { Storage_Slot* slot = NULL;

                slot = ((Storage_Slot*)(slot_001));
                if (slot->slot_hardwiredP &&
                    (slot->initial_value() != NULL)) {
                  hardwiredslotinitializers = cons(listO(3, SYM_WALK_SETQ, yield_hardwired_slot_variable(slot), cons(slot->initial_value(), NIL)), hardwiredslotinitializers);
                }
              }
            }
            else {
            }
          }
        }
      }
    }
    return (hardwiredslotinitializers);
  }
}

Object* yield_initial_value_expression(Storage_Slot* slot) {
  if (slot->abstractP ||
      (slot->dynamic_storageP() ||
       (slot->slot_hardwiredP ||
        (slot->allocation() == KWD_WALK_CLASS)))) {
    return (NULL);
  }
  { Object* initialvalueexpression = slot->initially();

    if (initialvalueexpression != NULL) {
      return (transientify_form(initialvalueexpression));
    }
    { Keyword* test_value_001 = translator_output_language();

      if (test_value_001 == KWD_WALK_COMMON_LISP) {
        if (slot->allocation() == KWD_WALK_EMBEDDED) {
          return (listO(3, SYM_WALK_ALLOCATE, type_to_symbol(slot->type()), NIL));
        }
      }
      else if ((test_value_001 == KWD_WALK_JAVA) ||
          ((test_value_001 == KWD_WALK_CPP) ||
           ((test_value_001 == KWD_WALK_CPP_STANDALONE) ||
            (test_value_001 == KWD_WALK_IDL)))) {
        if (slot->allocation() == KWD_WALK_EMBEDDED) {
          return (listO(3, SYM_WALK_ALLOCATE, type_to_symbol(slot->type()), NIL));
        }
      }
      else {
        cerr << "`" << test_value_001 << "'" << " is not a valid case option";
      }
    }
    return (type_to_null_value_tree(slot->type()));
  }
}

Cons* yield_constructor_attachment(Class* renamed_Class, Symbol* classref) {
  if ((!renamed_Class->abstractP) &&
      create_native_classP(renamed_Class)) {
    { Cons* constructorfncode = listO(4, SYM_WALK_THE_CODE, KWD_WALK_FUNCTION, yield_constructor_name(renamed_Class), NIL);

      return (cons(listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_CLASS_CONSTRUCTOR_CODE, classref, NIL), constructorfncode, NIL), NIL));
    }
  }
  else {
    return (NIL);
  }
}

void clear_slot_accessor_methods(Storage_Slot* slot) {
  { List* accessors = slot->slot_accessor_methods_reader();

    if (defined_listP(accessors)) {
      accessors->clear();
    }
  }
}

void register_slot_accessor_method(Storage_Slot* slot, Method_Slot* method) {
  { List* accessors = slot->slot_accessor_methods_reader();

    if (null_listP(accessors)) {
      accessors = new_list();
      set_dynamic_slot_value(slot, SYM_WALK_SLOT_ACCESSOR_METHODS, accessors, NULL);
    }
    accessors->push(method);
  }
}

void create_accessor_units_for_slot(Storage_Slot* slot, Class* renamed_Class, boolean nativeaccessorsP, boolean signaturesonlyP) {
  { Cons* methodtree = NULL;
    Method_Slot* method = NULL;

    if (system_defined_slot_readerP(slot)) {
      methodtree = yield_slot_reader_tree(slot, renamed_Class);
      if (signaturesonlyP) {
        method = define_method_from_parse_tree(methodtree);
      }
      else {
        method = ((Method_Slot*)(help_walk_auxiliary_tree(methodtree, TRUE)->the_object));
      }
      finalize_accessor_method(method);
      register_slot_accessor_method(slot, method);
    }
    if (system_defined_slot_writerP(slot)) {
      methodtree = yield_slot_writer_tree(slot, renamed_Class);
      if (signaturesonlyP) {
        method = define_method_from_parse_tree(methodtree);
      }
      else {
        method = ((Method_Slot*)(help_walk_auxiliary_tree(methodtree, TRUE)->the_object));
      }
      finalize_accessor_method(method);
      register_slot_accessor_method(slot, method);
    }
    if (nativeaccessorsP &&
        (!slot->abstractP)) {
      methodtree = yield_native_slot_reader_tree(slot, renamed_Class);
      if (signaturesonlyP) {
        method = define_method_from_parse_tree(methodtree);
      }
      else {
        method = ((Method_Slot*)(help_walk_auxiliary_tree(methodtree, TRUE)->the_object));
      }
      finalize_accessor_method(method);
      register_slot_accessor_method(slot, method);
      if (!(slot->slot_hardwiredP)) {
        methodtree = yield_native_slot_writer_tree(slot, renamed_Class);
        if (signaturesonlyP) {
          method = define_method_from_parse_tree(methodtree);
        }
        else {
          method = ((Method_Slot*)(help_walk_auxiliary_tree(methodtree, TRUE)->the_object));
        }
        finalize_accessor_method(method);
        register_slot_accessor_method(slot, method);
      }
    }
  }
}

void create_accessor_units_for_mixin_slot(Storage_Slot* slot, Class* renamed_Class) {
  if (native_slotP(slot) &&
      (native_slot_home(slot, renamed_Class) == renamed_Class)) {
    create_accessor_units_for_slot(slot, ((Class*)(SGT_WALK_OBJECT->surrogate_value)), TRUE, FALSE);
  }
  if (slot->slot_hardwiredP) {
    { Cons* readcode = NULL;
      Cons* auxiliarycode = NULL;

      readcode = yield_hardwired_slot_reader_body(slot, auxiliarycode);
      readcode = readcode;
      walk_auxiliary_tree(auxiliarycode);
    }
    create_accessor_units_for_slot(slot, ((Class*)(SGT_WALK_OBJECT->surrogate_value)), FALSE, FALSE);
  }
}

void create_slot_accessor_units(Class* renamed_Class) {
  { boolean eliminatemixinslotsP = renamed_Class->mixinP &&
        translate_to_single_inheritance_languageP();

    { Slot* slot = NULL;
      Cons* iter_001 = renamed_Class->local_slots()->the_cons_list;

      while (!nilP(iter_001)) {
        {
          slot = ((Slot*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        { Slot* slot_001 = slot;

          if (storage_slotP(slot)) {
            { Storage_Slot* slot = NULL;

              slot = ((Storage_Slot*)(slot_001));
              clear_slot_accessor_methods(slot);
              if (eliminatemixinslotsP) {
                create_accessor_units_for_mixin_slot(slot, renamed_Class);
              }
              else {
                create_accessor_units_for_slot(slot, renamed_Class, FALSE, slot->slot_externalP);
              }
            }
          }
          else {
          }
        }
      }
    }
    { boolean test_value_001 = FALSE;

      test_value_001 = translate_to_single_inheritance_languageP();
      if (test_value_001) {
        { boolean foundP_001 = FALSE;

          { Surrogate* super = NULL;
            Cons* iter_002 = renamed_Class->class_direct_supers->the_cons_list;

            while (!nilP(iter_002)) {
              {
                super = ((Surrogate*)(iter_002->value));
                iter_002 = iter_002->rest;
              }
              if (((Class*)(super->surrogate_value))->mixinP) {
                foundP_001 = TRUE;
                break;
              }
            }
          }
          test_value_001 = foundP_001;
        }
      }
      if (test_value_001) {
        { Slot* slot = NULL;
          Iterator* iter_003 = renamed_Class->class_slots();

          while (iter_003->nextP()) {
            {
              slot = ((Slot*)(iter_003->value));
            }
            if (storage_slotP(slot) &&
                (type_to_class(slot->slot_owner)->mixinP &&
                 (mixin_slot_home(((Storage_Slot*)(slot)), renamed_Class) == renamed_Class))) {
              create_accessor_units_for_slot(((Storage_Slot*)(slot)), renamed_Class, TRUE, slot->slot_externalP);
            }
          }
        }
      }
    }
    create_generic_slot_accessor_unit(renamed_Class);
  }
}

void create_inline_method_units(Class* renamed_Class) {
  { Slot* slot = NULL;
    Cons* iter_001 = renamed_Class->local_slots()->the_cons_list;

    while (!nilP(iter_001)) {
      {
        slot = ((Slot*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (inline_methodP(slot)) {
        { Method_Slot* method = ((Method_Slot*)(slot));

          { Translation_Unit* self_001 = new_translation_unit();

            self_001->the_object = method;
            self_001->category = SYM_WALK_METHOD;
            self_001->code_register = unstringify(method->method_stringified_source);
            self_001->auxiliaryP = TRUE;
            walk_method_unit(self_001);
          }
        }
      }
    }
  }
}

void create_defprint_unit(Class* renamed_Class) {
  if (!(dynamic_slot_value(renamed_Class, SYM_WALK_PRINT_FORM, NULL) == NULL)) {
    walk_auxiliary_tree(listO(5, SYM_WALK_DEFMETHOD, SYM_WALK_PRINT_OBJECT, listO(3, listO(3, SYM_WALK_SELF, renamed_Class->class_type, NIL), listO(3, SYM_WALK_STREAM, SYM_WALK_NATIVE_OUTPUT_STREAM, NIL), NIL), transientify_form(dynamic_slot_value(renamed_Class, SYM_WALK_PRINT_FORM, NULL)), NIL));
    { boolean test_value_001 = FALSE;

      test_value_001 = translator_output_language() == KWD_WALK_CPP;
      if (test_value_001) {
        { boolean foundP_001 = FALSE;

          { Class* super = NULL;
            Cons* iter_001 = renamed_Class->class_all_super_classes;

            while (!nilP(iter_001)) {
              {
                super = ((Class*)(iter_001->value));
                iter_001 = iter_001->rest;
              }
              if (dynamic_slot_value(super, SYM_WALK_PRINT_FORM, NULL) != NULL) {
                foundP_001 = TRUE;
                break;
              }
            }
          }
          test_value_001 = foundP_001;
        }
        test_value_001 = !test_value_001;
      }
      if (test_value_001) {
        { Translation_Unit* self_001 = new_translation_unit();

          self_001->the_object = renamed_Class;
          self_001->category = SYM_WALK_PRINT_METHOD;
          self_001->code_register = listO(3, SYM_WALK_SYS_CALL_METHOD, renamed_Class->class_type, listO(4, SYM_WALK_PRINT_OBJECT, SYM_WALK_SELF, SYM_WALK_STREAM, NIL));
          self_001->auxiliaryP = TRUE;
          { Translation_Unit* unit = self_001;

            oTRANSLATIONUNITSo->push(unit);
          }
        }
      }
    }
  }
}

void walk_class_unit(Translation_Unit* unit) {
  { Class* renamed_Class = ((Class*)(unit->the_object));
    Cons* startuptimecode = NULL;

    if (!renamed_Class->class_finalizedP) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Cannot translate class " << "`" << class_symbol(renamed_Class) << "'" << ", since it could not be finalized" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
      unit->free();
      return;
    }
    if (create_native_classP(renamed_Class)) {
      warn_about_multiple_parents(renamed_Class);
      warn_about_non_direct_supers(renamed_Class);
      if (renamed_Class->mixinP &&
          translate_to_single_inheritance_languageP()) {
        create_slot_accessor_units(renamed_Class);
      }
      else {
        oTRANSLATIONUNITSo->push(unit);
        create_constructor_and_destructor_units(renamed_Class);
        create_slot_accessor_units(renamed_Class);
        create_inline_method_units(renamed_Class);
      }
    }
    create_defprint_unit(renamed_Class);
    startuptimecode = yield_initialize_hardwired_slots(renamed_Class)->concatenate(yield_constructor_attachment(renamed_Class, SYM_WALK_CLASS)->concatenate(yield_generic_slot_accessor_attachment(renamed_Class, SYM_WALK_CLASS)->concatenate(NIL)));
    walk_auxiliary_tree((startuptimecode->emptyP() ? ((Cons*)(listO(4, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_CLASSES, yield_define_stella_class(renamed_Class), NIL))) : ((Cons*)(listO(4, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_CLASSES, listO(3, SYM_WALK_LET, cons(listO(3, SYM_WALK_CLASS, yield_define_stella_class(renamed_Class), NIL), NIL), startuptimecode->concatenate(NIL)), NIL)))));
    { Surrogate* synonym = NULL;
      Cons* iter_001 = renamed_Class->class_synonyms_reader()->the_cons_list;

      while (!nilP(iter_001)) {
        {
          synonym = ((Surrogate*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        register_symbol(type_to_symbol(synonym));
      }
    }
  }
}

void create_finalization_units() {
  { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTRANSIENTOBJECTSpo = TRUE;
          walk_auxiliary_tree(listO(4, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_FINALIZE_CLASSES, cons(SYM_WALK_FINALIZE_CLASSES, NIL), NIL));
          walk_auxiliary_tree(listO(5, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_FINALIZE_METHODS, cons(SYM_WALK_FINALIZE_SLOTS, NIL), cons(SYM_WALK_CLEANUP_UNFINALIZED_CLASSES, NIL), NIL));
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
        resignal();
      }
    }
  }
}

void walk_defslot_tree(Cons* tree) {
  { Translation_Unit* self_001 = new_translation_unit();

    self_001->category = SYM_WALK_SLOT;
    self_001->the_object = tree;
    oCURRENTTRANSLATIONUNITo = self_001;
  }
  { Storage_Slot* slot = NULL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = FALSE;
            slot = define_external_slot_from_parse_tree(tree);
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          resignal();
        }
      }
    }
    if (slot == NULL) {
      oCURRENTTRANSLATIONUNITo->free();
      oCURRENTTRANSLATIONUNITo = NULL;
      return;
    }
    oCURRENTTRANSLATIONUNITo->the_object = slot;
    oCURRENTTRANSLATIONUNITo->code_register = tree;
  }
}

void walk_slot_unit(Translation_Unit* unit) {
  { Storage_Slot* slot = ((Storage_Slot*)(unit->the_object));
    Class* ownerclass = ((Class*)(slot->slot_owner->surrogate_value));
    char* stringifieddefinition = stringify(unit->code_register);

    clear_slot_accessor_methods(slot);
    create_accessor_units_for_slot(slot, ownerclass, FALSE, FALSE);
    unit->free();
    walk_auxiliary_tree(listO(4, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_METHODS, listO(3, SYM_WALK_DEFINE_EXTERNAL_SLOT_FROM_STRINGIFIED_SOURCE, string_wrap_literal(stringifieddefinition), NIL), NIL));
  }
}

Method_Slot* lookup_macro(Symbol* name) {
  { Cons* macroinfo = ((Cons*)(oMACRO_TABLEo->lookup(name)));
    Method_Slot* expandermethod = NULL;

    if (macroinfo != NULL) {
      expandermethod = lookup_function_or_stella_function(((Symbol*)(macroinfo->first())));
      if (expandermethod != NULL) {
        expandermethod->function_code = ((Function_Code_Wrapper*)(macroinfo->second()))->wrapper_value;
        return (expandermethod);
      }
    }
    return (NULL);
  }
}

void store_macro(Symbol* name, Symbol* expandername, cpp_function_code expandercode) {
  oMACRO_TABLEo->insert_at(name, cons_list(2, expandername, function_code_wrap_literal(expandercode)));
}

Symbol* yield_macro_expander_function_name(Symbol* macroname) {
  return (intern_derived_symbol(macroname, string_concatenate(macroname->symbol_name, "-EXPANDER")));
}

void walk_defmacro_tree(Cons* tree) {
  { Object* name = tree->second();

    if (!(symbolP(name))) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Illegal macro name: " << "`" << de_uglify_parse_tree(name) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
    }
    tree->first_setter(SYM_WALK_DEFUN);
    tree->second_setter(cons(yield_macro_expander_function_name(((Symbol*)(name))), cons(SYM_WALK_OBJECT, NIL)));
    walk_defmethod_tree(tree);
    if (oCURRENTTRANSLATIONUNITo != NULL) {
      oCURRENTTRANSLATIONUNITo->category = SYM_WALK_MACRO;
      tree->second_setter(name);
      oCURRENTTRANSLATIONUNITo->code_register = tree;
    }
  }
}

void walk_macro_unit(Translation_Unit* unit) {
  { Cons* definition = ((Cons*)(unit->code_register));
    Symbol* name = ((Symbol*)(definition->second()));
    Method_Slot* expandermethod = ((Method_Slot*)(unit->the_object));
    Symbol* expanderfnname = expandermethod->slot_name;
    boolean needslispmacroP = method_needs_lisp_macroP(expandermethod);

    if (needslispmacroP) {
      create_lisp_macro_units(name, expandermethod);
      set_dynamic_slot_value(expandermethod, SYM_WALK_METHOD_LISP_MACROp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
    }
    unit->code_register = definition->nth_rest(3);
    walk_method_unit(unit);
    if (needslispmacroP) {
      set_dynamic_slot_value(expandermethod, SYM_WALK_METHOD_LISP_MACROp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
    }
    if (expandermethod->method_argument_count() > 5) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Too many arguments in macro definition" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
    }
    walk_auxiliary_tree(listO(3, SYM_WALK_STARTUP_TIME_PROGN, listO(5, SYM_WALK_STORE_MACRO, listO(3, SYM_WALK_BQUOTE, name, NIL), listO(3, SYM_WALK_BQUOTE, expanderfnname, NIL), listO(4, SYM_WALK_THE_CODE, KWD_WALK_FUNCTION, expanderfnname, NIL), NIL), NIL));
  }
}

void walk_defglobal_tree(Cons* tree) {
  { Translation_Unit* self_001 = new_translation_unit();

    self_001->category = SYM_WALK_GLOBAL_VARIABLE;
    self_001->the_object = tree;
    oCURRENTTRANSLATIONUNITo = self_001;
  }
  if (tree->length() < 3) {
    bad_argument_countP(tree, 3);
    oCURRENTTRANSLATIONUNITo->free();
    oCURRENTTRANSLATIONUNITo = NULL;
    return;
  }
  { Global_Variable* global = NULL;
    Object* initialvaluetree = NULL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = FALSE;
            global = define_stella_global_variable_from_parse_tree(tree, stringify(tree), initialvaluetree);
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          resignal();
        }
      }
    }
    oCURRENTTRANSLATIONUNITo->the_object = global;
    oCURRENTTRANSLATIONUNITo->code_register = initialvaluetree;
    oCURRENTTRANSLATIONUNITo->auxiliaryP = global->variable_auxiliaryP;
    if (tree->length() > 3) {
      tree->fourth_setter(NULL);
    }
    tree->free_parse_tree();
  }
}

void walk_global_unit(Translation_Unit* unit) {
  { Standard_Object* dummy1;

    { Global_Variable* global = ((Global_Variable*)(unit->the_object));
      Symbol* variablename = global->variable_name;
      Object* initialvaluetree = unit->code_register;
      char* stringifiedsource = global->variable_stringified_source;
      boolean activeP = global->variable_specialP &&
          generically_accessible_typeP(type_spec_to_base_type(global->variable_type));
      Symbol* getvariablevaluefn = NULL;
      Symbol* setvariablevaluefn = NULL;
      Standard_Object* variabletypespec = NULL;

      oTRANSLATIONUNITSo->push(unit);
      if (!(initialvaluetree == KWD_WALK_UNBOUND_SPECIAL_VARIABLE)) {
        if (wrapperP(initialvaluetree) ||
            ((symbolP(initialvaluetree) &&
            constant_symbolP(((Symbol*)(initialvaluetree)))) ||
             (consP(initialvaluetree) &&
              (((Cons*)(initialvaluetree))->first() == SYM_WALK_VERBATIM)))) {
          initialvaluetree = walk_expression_tree(initialvaluetree, global->variable_type, global->variable_name, TRUE, dummy1);
        }
        else {
          walk_auxiliary_tree(listO(4, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_GLOBALS, listO(3, SYM_WALK_SETQ, global->variable_name, cons(initialvaluetree, NIL)), NIL));
          initialvaluetree = type_to_null_value_tree(type_spec_to_base_type(global->variable_type));
        }
      }
      unit->code_register = initialvaluetree;
      if (activeP) {
        getvariablevaluefn = intern_derived_symbol(global->variable_name, string_concatenate("READ-", variablename->symbol_name));
        setvariablevaluefn = intern_derived_symbol(global->variable_name, string_concatenate("WRITE-", variablename->symbol_name));
        variabletypespec = ((((Standard_Object*)(dynamic_slot_value(global, SYM_WALK_VARIABLE_TYPE_SPECIFIER, NULL))) == NULL) ? ((Standard_Object*)(global->variable_type)) : ((Standard_Object*)(((Standard_Object*)(dynamic_slot_value(global, SYM_WALK_VARIABLE_TYPE_SPECIFIER, NULL))))));
        walk_auxiliary_tree(listO(5, SYM_WALK_DEFUN, cons(getvariablevaluefn, cons(yield_type_spec_tree(variabletypespec), NIL)), NIL, listO(3, SYM_WALK_RETURN, variablename, NIL), NIL));
        walk_auxiliary_tree(listO(6, SYM_WALK_DEFUN, cons(setvariablevaluefn, cons(yield_type_spec_tree(variabletypespec), NIL)), cons(listO(3, SYM_WALK_VALUE, yield_type_spec_tree(variabletypespec), NIL), NIL), listO(3, SYM_WALK_SETQ, variablename, cons(SYM_WALK_VALUE, NIL)), listO(3, SYM_WALK_RETURN, SYM_WALK_VALUE, NIL), NIL));
      }
      if (!(unit->auxiliaryP)) {
        walk_auxiliary_tree(listO(3, SYM_WALK_STARTUP_TIME_PROGN, listO(3, SYM_WALK_DEFINE_STELLA_GLOBAL_VARIABLE_FROM_STRINGIFIED_SOURCE, string_wrap_literal(stringifiedsource), NIL), (activeP ? ((Cons*)(cons(listO(5, SYM_WALK_LET, cons(listO(3, SYM_WALK_GLOBAL, listO(3, SYM_WALK_LOOKUP_GLOBAL_VARIABLE, listO(3, SYM_WALK_QUOTE, variablename, NIL), NIL), NIL), NIL), listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_VARIABLE_GET_VALUE_CODE, SYM_WALK_GLOBAL, NIL), listO(4, SYM_WALK_THE_CODE, KWD_WALK_FUNCTION, getvariablevaluefn, NIL), NIL), listO(4, SYM_WALK_SETF, listO(3, SYM_WALK_VARIABLE_SET_VALUE_CODE, SYM_WALK_GLOBAL, NIL), listO(4, SYM_WALK_THE_CODE, KWD_WALK_FUNCTION, setvariablevaluefn, NIL), NIL), NIL), NIL))) : ((Cons*)(NIL)))->concatenate(NIL)));
      }
    }
  }
}

void walk_deftype_tree(Cons* tree) {
  { Translation_Unit* self_001 = new_translation_unit();

    self_001->category = SYM_WALK_TYPE;
    self_001->the_object = tree;
    oCURRENTTRANSLATIONUNITo = self_001;
  }
  if (tree->length() < 3) {
    bad_argument_countP(tree, 3);
    oCURRENTTRANSLATIONUNITo->free();
    oCURRENTTRANSLATIONUNITo = NULL;
    return;
  }
  { Surrogate* type = NULL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = FALSE;
            type = define_stella_type_from_parse_tree(tree);
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          resignal();
        }
      }
    }
    oCURRENTTRANSLATIONUNITo->the_object = type;
    oCURRENTTRANSLATIONUNITo->code_register = tree;
  }
}

void walk_type_unit(Translation_Unit* unit) {
  { char* stringifieddefinition = stringify(unit->code_register);

    oTRANSLATIONUNITSo->push(unit);
    walk_auxiliary_tree(listO(4, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_CLASSES, listO(3, SYM_WALK_DEFINE_STELLA_TYPE_FROM_STRINGIFIED_SOURCE, string_wrap_literal(stringifieddefinition), NIL), NIL));
    register_symbol(type_to_symbol(((Surrogate*)(unit->the_object))));
  }
}

void walk_startup_time_progn_tree(Cons* tree) {
  { Translation_Unit* self_001 = new_translation_unit();

    self_001->category = SYM_WALK_STARTUP_TIME_PROGN;
    self_001->code_register = tree;
    oCURRENTTRANSLATIONUNITo = self_001;
  }
}

Keyword* extract_startup_time_phase(Cons* tree) {
  { Keyword* startuptimephase = KWD_WALK_FINAL;
    Cons* startuptimephasetree = NULL;

    if ((tree->length() >= 2) &&
        (keywordP(tree->second()) &&
         oSTARTUP_TIME_PHASESo->memberP(((Keyword*)(tree->second()))))) {
      startuptimephase = ((Keyword*)(tree->second()));
      startuptimephasetree = tree->rest;
      tree->rest = tree->rest->rest;
      startuptimephasetree->rest = NIL;
      startuptimephasetree->free_cons();
    }
    return (startuptimephase);
  }
}

void walk_startup_time_progn_unit(Translation_Unit* unit) {
  { Cons* tree = ((Cons*)(unit->code_register));
    Keyword* phase = extract_startup_time_phase(tree);

    oTRANSLATIONUNITSo->push(unit);
    unit->the_object = walk_list_of_trees(tree->rest);
    unit->code_register = phase;
  }
}

Cons* combine_startup_function_units() {
  { Cons* earlystartuptrees = NIL;
    Cons* startuptrees = NIL;
    Cons* startupphasetrees = NIL;
    Translation_Unit* placeholderunit = NULL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            { Keyword* phase = NULL;
              Cons* iter_001 = oSTARTUP_TIME_PHASESo->the_cons_list;

              while (!nilP(iter_001)) {
                {
                  phase = ((Keyword*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                { List_Iterator* it = ((List_Iterator*)(oTRANSLATIONUNITSo->allocate_iterator()));

                  while (it->nextP()) {
                    { Translation_Unit* unit = ((Translation_Unit*)(it->value));

                      if ((unit->category == SYM_WALK_STARTUP_TIME_PROGN) &&
                          (unit->code_register == phase)) {
                        startupphasetrees = ((Cons*)(unit->the_object))->concatenate(startupphasetrees);
                        if (placeholderunit != NULL) {
                          unit->free();
                          it->value_setter(placeholderunit);
                        }
                        else {
                          placeholderunit = unit;
                        }
                      }
                    }
                  }
                }
                if (startupphasetrees->non_emptyP()) {
                  startupphasetrees = listO(3, SYM_WALK_VOID_SYS, listO(3, SYM_WALK_WHEN, listO(4, SYM_WALK_SYS_CALL_FUNCTION, SYM_WALK_CURRENT_STARTUP_TIME_PHASEp, integer_wrap_literal(encode_startup_time_phase(phase)), NIL), startupphasetrees->concatenate(NIL)), NIL);
                  if (encode_startup_time_phase(phase) <= encode_startup_time_phase(KWD_WALK_MODULES)) {
                    earlystartuptrees = cons(startupphasetrees, earlystartuptrees);
                  }
                  else {
                    startuptrees = cons(startupphasetrees, startuptrees);
                  }
                  startupphasetrees = NIL;
                }
              }
            }
            if (startuptrees->non_emptyP()) {
              startuptrees = cons(listO(3, SYM_WALK_WITHIN_MODULE, ((oMODULEo == oSTELLA_MODULEo) ? ((Standard_Object*)(SYM_WALK_oSTELLA_MODULEo)) : ((Standard_Object*)(listO(3, SYM_WALK_GET_MODULE, string_wrap_literal(oMODULEo->module_full_name), cons(SYM_WALK_TRUE, NIL))))), startuptrees->reverse()->concatenate(NIL)), NIL);
            }
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          resignal();
        }
      }
    }
    if (earlystartuptrees->non_emptyP() ||
        startuptrees->non_emptyP()) {
      startuptrees = earlystartuptrees->reverse()->concatenate(startuptrees);
      oTRANSLATIONUNITSo->remove(placeholderunit);
      placeholderunit->free();
    }
    return (startuptrees);
  }
}

void create_startup_function_unit(Symbol* startupfnname) {
  { Cons* tree = NULL;
    Method_Slot* method = NULL;

    if (dont_generate_startup_codeP()) {
      remove_all_startup_time_progn_units();
    }
    else if (startupfnname != NULL) {
      { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oTRANSIENTOBJECTSpo = TRUE;
              tree = listO(3, SYM_WALK_DEFUN, startupfnname, listO(3, NIL, SYM_WALK_NULL, NIL));
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
            resignal();
          }
        }
      }
      method = define_method_from_parse_tree(tree);
      { boolean old_OtransientobjectsPO_002 = oTRANSIENTOBJECTSpo;

        { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oTRANSIENTOBJECTSpo = TRUE;
              tree = listO(4, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_METHODS, yield_define_stella_method(method), NIL);
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_002;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_002;
            resignal();
          }
        }
      }
      walk_auxiliary_tree(tree);
      { boolean old_OtransientobjectsPO_003 = oTRANSIENTOBJECTSpo;

        { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oTRANSIENTOBJECTSpo = TRUE;
              tree = listO(3, SYM_WALK_DEFUN, startupfnname, listO(4, NIL, KWD_WALK_AUXILIARYp, SYM_WALK_TRUE, combine_startup_function_units()->concatenate(NIL)));
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_003;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_003;
            resignal();
          }
        }
      }
      walk_auxiliary_tree(tree);
    }
    else {
      { boolean old_OtransientobjectsPO_004 = oTRANSIENTOBJECTSpo;

        { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oTRANSIENTOBJECTSpo = TRUE;
              tree = cons(SYM_WALK_STARTUP_TIME_PROGN, combine_startup_function_units()->concatenate(NIL));
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_004;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_004;
            resignal();
          }
        }
      }
      walk_auxiliary_tree(tree);
      { boolean old_OtransientobjectsPO_005 = oTRANSIENTOBJECTSpo;

        { jump_buffer old_OexceptionhandleraddressO_005 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oTRANSIENTOBJECTSpo = TRUE;
              tree = cons(SYM_WALK_PROGN, ((Cons*)(((Translation_Unit*)(oTRANSLATIONUNITSo->first()))->the_object)));
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_005;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_005;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_005;
            resignal();
          }
        }
      }
      ((Translation_Unit*)(oTRANSLATIONUNITSo->first()))->the_object = tree;
    }
  }
}

boolean dont_generate_startup_codeP() {
  return (oTRANSLATOR_OUTPUT_LANGUAGEo == KWD_WALK_CPP_STANDALONE);
}

void remove_all_startup_time_progn_units() {
  { Translation_Unit* placeholderunit = NULL;

    { List_Iterator* it = ((List_Iterator*)(oTRANSLATIONUNITSo->allocate_iterator()));

      while (it->nextP()) {
        if (((Translation_Unit*)(it->value))->category == SYM_WALK_STARTUP_TIME_PROGN) {
          { Translation_Unit* unit = ((Translation_Unit*)(it->value));

            ((Cons*)(unit->the_object))->free_parse_tree();
            if (placeholderunit == NULL) {
              placeholderunit = unit;
            }
            else {
              unit->free();
            }
            it->value_setter(placeholderunit);
          }
        }
      }
    }
    oTRANSLATIONUNITSo->remove(placeholderunit);
    placeholderunit->free();
  }
}

boolean use_stella_exceptionsP() {
  return (TRUE);
}

boolean read_OpendingexceptionhandlerPO() {
  return (oPENDINGEXCEPTIONHANDLERpo);
}

boolean write_OpendingexceptionhandlerPO(boolean value) {
  oPENDINGEXCEPTIONHANDLERpo = value;
  return (value);
}

void signal(Exception* exception) {
  // Signal an 'exception'.  Signal an error if there is
  // no pending exception handler that can handle 'exception'.
  if (!oPENDINGEXCEPTIONHANDLERpo) {
    cerr << "signal: No available handlers to handle " << "`" << exception << "'";
  }
  oEXCEPTIONo = exception;
  oEXCEPTION_TYPEo = exception->primary_type();
  long_jump(oEXCEPTIONHANDLERADDRESSo);
}

void resignal() {
  // Resignal the most recently re/signalled exception.
  // Signal an error if there is no pending exception handler that can handle it.
  if (!oPENDINGEXCEPTIONHANDLERpo) {
    cerr << "signal: No available handlers to handle " << "`" << oEXCEPTIONo << "'";
  }
  long_jump(oEXCEPTIONHANDLERADDRESSo);
}

Cons* walk_exception_case_tree(Cons* tree, Standard_Object*& return1) {
  { Standard_Object* dummy1;

    if (tree->length() <= 2) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Missing handler(s) in 'exception-case': " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
      return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
    }
    if (!use_stella_exceptionsP()) {
      { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_warning();
              if (!(suppress_warningsP())) {
                print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                cout << endl << " " << "Native exception handling is not yet implemented" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_002;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_002;
            resignal();
          }
        }
      }
    }
    { Cons* protectedtree = yield_protected_statement_tree(tree->second(), FALSE);
      Cons* handlertree = yield_exception_handler_tree(tree->rest->rest);

      if ((protectedtree == NULL) ||
          (handlertree == NULL)) {
        return (walk_dont_call_me_tree(tree, SGT_WALK_VOID, return1));
      }
      { Cons* return_temp = ((Cons*)(walk_a_tree(listO(3, SYM_WALK_PROGN, protectedtree, cons(handlertree, NIL)), dummy1)));

        return1 = SGT_WALK_VOID;
        return (return_temp);
      }
    }
  }
}

boolean lexically_visible_exception_caseP() {
  return (lookup_old_value_variable(SYM_WALK_oPENDINGEXCEPTIONHANDLERpo) != NULL);
}

Cons* yield_protected_statement_tree(Object* tree, boolean unwindprotectP) {
  { Keyword* test_value_001 = translator_output_language();

    if (test_value_001 == KWD_WALK_COMMON_LISP) {
      tree = listO(4, SYM_WALK_SYS_SPECIAL, cons(listO(3, SYM_WALK_oPENDINGEXCEPTIONHANDLERpo, SYM_WALK_TRUE, NIL), NIL), listO(4, intern_common_lisp_symbol("CATCH"), SYM_WALK_oEXCEPTIONHANDLERADDRESSo, listO(3, SYM_WALK_PROGN, tree, cons(listO(4, SYM_WALK_SETQ, SYM_WALK_oEXCEPTIONo, SYM_WALK_NULL, NIL), NIL)), NIL), NIL);
    }
    else if (test_value_001 == KWD_WALK_CPP) {
      if (unwindprotectP) {
        tree = listO(4, SYM_WALK_SYS_SPECIAL, cons(listO(3, SYM_WALK_oEXCEPTIONHANDLERADDRESSo, SYM_WALK_NULL, NIL), NIL), listO(3, SYM_WALK_WHEN, (lexically_visible_exception_caseP() ? ((Cons*)(listO(3, SYM_WALK_SETUP_LONG_JUMPp, SYM_WALK_oEXCEPTIONHANDLERADDRESSo, NIL))) : ((Cons*)(listO(4, SYM_WALK_OR, listO(3, SYM_WALK_NOT, SYM_WALK_oPENDINGEXCEPTIONHANDLERpo, NIL), listO(3, SYM_WALK_SETUP_LONG_JUMPp, SYM_WALK_oEXCEPTIONHANDLERADDRESSo, NIL), NIL)))), cons(tree, cons(listO(4, SYM_WALK_SETQ, SYM_WALK_oEXCEPTIONo, SYM_WALK_NULL, NIL), NIL))), NIL);
      }
      else {
        tree = listO(4, SYM_WALK_SYS_SPECIAL, listO(3, listO(3, SYM_WALK_oEXCEPTIONHANDLERADDRESSo, SYM_WALK_NULL, NIL), listO(3, SYM_WALK_oPENDINGEXCEPTIONHANDLERpo, SYM_WALK_TRUE, NIL), NIL), listO(4, SYM_WALK_WHEN, listO(3, SYM_WALK_SETUP_LONG_JUMPp, SYM_WALK_oEXCEPTIONHANDLERADDRESSo, NIL), tree, cons(listO(4, SYM_WALK_SETQ, SYM_WALK_oEXCEPTIONo, SYM_WALK_NULL, NIL), NIL)), NIL);
      }
    }
    else {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "'exception-case' not yet implemented for " << "`" << translator_output_language() << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
      return (NULL);
    }
  }
  return (((Cons*)(tree)));
}

Cons* yield_exception_handler_tree(Cons* tree) {
  { Cons* clauses = NIL;
    Object* lastclause = tree->last();
    Object* exceptiontype = NULL;
    Object* exceptionvariablespec = NULL;
    Symbol* exceptionvariable = NULL;
    boolean noexceptionclauseP = FALSE;
    boolean needresignalP = TRUE;

    { Object* clause = NULL;
      Cons* iter_001 = tree;

      while (!nilP(iter_001)) {
        {
          clause = iter_001->value;
          iter_001 = iter_001->rest;
        }
        { Object* clause_001 = clause;

          if (consP(clause)) {
            { Cons* clause = NULL;

              clause = ((Cons*)(clause_001));
              if (clause->length() < 2) {
                { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_error();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Illegal exception handler clause: " << "`" << de_uglify_parse_tree(clause) << "'" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      resignal();
                    }
                  }
                }
                return (NULL);
              }
              exceptiontype = clause->first();
              if (FALSE) {
                if (!(clause == lastclause)) {
                  { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                    { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oPRINTREADABLYpo = TRUE;
                          signal_translation_error();
                          if (!(suppress_warningsP())) {
                            print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                            cout << endl << " " << "Premature 'no-exception' clause in 'exception-case'" << endl << "    " << "`" << de_uglify_parse_tree(clause) << "'" << "." << endl;
                          }
                          oPRINTREADABLYpo = old_OprintreadablyPO_002;
                        }
                        oEXCEPTIONo = NULL;
                      }
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                    }
                    if (oEXCEPTIONo != NULL) {
                      if (TRUE) {
                        oPRINTREADABLYpo = old_OprintreadablyPO_002;
                        resignal();
                      }
                    }
                  }
                  return (NULL);
                }
                clause->first_setter(SYM_WALK_PROGN);
                noexceptionclauseP = TRUE;
                break;
              }
              if (!symbolP(exceptiontype)) {
                { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_error();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Illegal exception type: " << "`" << de_uglify_parse_tree(exceptiontype) << "'" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_003;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_003;
                      resignal();
                    }
                  }
                }
                return (NULL);
              }
              exceptiontype = typify(exceptiontype);
              if (type_to_class(((Surrogate*)(exceptiontype))) == NULL) {
                { boolean old_OprintreadablyPO_004 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_error();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Undefined exception type: " << "`" << de_uglify_parse_tree(exceptiontype) << "'" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_004;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_004;
                      resignal();
                    }
                  }
                }
                return (NULL);
              }
              if (!subtype_ofP(((Surrogate*)(exceptiontype)), SGT_WALK_EXCEPTION)) {
                { boolean old_OprintreadablyPO_005 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_005 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_error();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Exception type " << "`" << de_uglify_parse_tree(exceptiontype) << "'" << " is not a subtype of EXCEPTION" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_005;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_005;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_005;
                      resignal();
                    }
                  }
                }
                return (NULL);
              }
              exceptionvariablespec = clause->second();
              if ((!consP(exceptionvariablespec)) ||
                  ((((Cons*)(exceptionvariablespec))->length() > 1) ||
                   ((((Cons*)(exceptionvariablespec))->length() == 1) &&
                    (!symbolP(((Cons*)(exceptionvariablespec))->first()))))) {
                { boolean old_OprintreadablyPO_006 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_006 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_error();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Illegal exception variable specification: " << "`" << de_uglify_parse_tree(clause) << "'" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_006;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_006;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_006;
                      resignal();
                    }
                  }
                }
                return (NULL);
              }
              exceptionvariable = ((Symbol*)(((Cons*)(exceptionvariablespec))->first()));
              clause = clause->rest;
              if (exceptiontype == SGT_WALK_EXCEPTION) {
                needresignalP = FALSE;
                clause->first_setter(SYM_WALK_TRUE);
              }
              else {
                clause->first_setter(listO(4, SYM_WALK_SUBTYPE_OFp, SYM_WALK_oEXCEPTION_TYPEo, exceptiontype, NIL));
              }
              if (exceptionvariable != NULL) {
                clause->rest = cons(listO(3, SYM_WALK_LET, cons(cons(exceptionvariable, cons(exceptiontype, cons(SYM_WALK_oEXCEPTIONo, NIL))), NIL), clause->rest->concatenate(NIL)), NIL);
              }
              clauses = cons(clause, clauses);
            }
          }
          else {
            { boolean old_OprintreadablyPO_007 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_007 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Illegal exception handler clause: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_007;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_007;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_007;
                  resignal();
                }
              }
            }
            return (NULL);
          }
        }
      }
    }
    clauses = cons(SYM_WALK_COND, clauses->reverse()->concatenate((needresignalP ? ((Cons*)(cons(listO(3, SYM_WALK_OTHERWISE, cons(SYM_WALK_RESIGNAL, NIL), NIL), NIL))) : ((Cons*)(NIL)))->concatenate(NIL)));
    if (noexceptionclauseP) {
      return (listO(4, SYM_WALK_IF, listO(3, SYM_WALK_DEFINEDp, SYM_WALK_oEXCEPTIONo, NIL), clauses, cons(lastclause, NIL)));
    }
    else {
      return (listO(4, SYM_WALK_WHEN, listO(3, SYM_WALK_DEFINEDp, SYM_WALK_oEXCEPTIONo, NIL), clauses, NIL));
    }
  }
}

void walk_verbatim_definition_tree(Cons* tree) {
  { Translation_Unit* self_001 = new_translation_unit();

    self_001->category = SYM_WALK_VERBATIM;
    self_001->code_register = tree;
    oCURRENTTRANSLATIONUNITo = self_001;
  }
}

void walk_verbatim_unit(Translation_Unit* unit) {
  { Standard_Object* dummy1;

    unit->the_object = walk_a_tree(unit->code_register, dummy1);
    if (unit->the_object != NULL) {
      oTRANSLATIONUNITSo->push(unit);
      unit->code_register = NULL;
    }
    else {
      unit->code_register = NULL;
      unit->free();
    }
  }
}

Object* walk_verbatim_tree(Cons* tree, Standard_Object*& return1) {
  { Property_List* self_001 = new_property_list();

    self_001->the_plist = tree->rest;
    { Property_List* options = self_001;
      Object* verbatimtree = options->lookup(translator_output_language());

      if (verbatimtree == NULL) {
        verbatimtree = options->lookup(KWD_WALK_OTHERWISE);
        if (verbatimtree == NULL) {
          { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  signal_translation_error();
                  if (!(suppress_warningsP())) {
                    print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                    cout << endl << " " << "Verbatim statement has no " << "`" << translator_output_language() << "'" << " option." << "." << endl;
                  }
                  oPRINTREADABLYpo = old_OprintreadablyPO_001;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oPRINTREADABLYpo = old_OprintreadablyPO_001;
                resignal();
              }
            }
          }
          { Object* return_temp = NULL;

            return1 = SGT_WALK_UNKNOWN;
            return (return_temp);
          }
        }
        if (!(verbatimtree == SYM_WALK_NULL)) {
          return (walk_a_tree(verbatimtree, return1));
        }
      }
      if (verbatimtree == SYM_WALK_NULL) {
        tree->free_parse_tree();
        { Object* return_temp = NULL;

          return1 = SGT_WALK_UNKNOWN;
          return (return_temp);
        }
      }
      { Object* verbatimtree_001 = verbatimtree;

        if (stringP(verbatimtree)) {
          { String_Wrapper* verbatimtree = NULL;

            verbatimtree = ((String_Wrapper*)(verbatimtree_001));
            options->insert_at(translator_output_language(), new_verbatim_string_wrapper(verbatimtree->wrapper_value));
          }
        }
        else {
        }
      }
      { Object* return_temp = tree;

        return1 = SGT_WALK_UNKNOWN;
        return (return_temp);
      }
    }
  }
}

void walk_defmodule_tree(Cons* tree) {
  { Translation_Unit* self_001 = new_translation_unit();

    self_001->category = SYM_WALK_MODULE;
    self_001->the_object = tree;
    oCURRENTTRANSLATIONUNITo = self_001;
  }
  { Module* module = NULL;
    char* modulename = coerce_to_module_name(tree->second(), FALSE);

    if (modulename == NULL) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Illegal module name: " << "`" << tree->second() << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
      oCURRENTTRANSLATIONUNITo->free();
      oCURRENTTRANSLATIONUNITo = NULL;
      return;
    }
    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = FALSE;
            module = define_module(modulename, tree->rest->rest);
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          resignal();
        }
      }
    }
    oCURRENTTRANSLATIONUNITo->the_object = module;
    tree->rest->rest = NIL;
    free_cons_list(tree);
  }
}

void walk_module_unit(Translation_Unit* unit) {
  { Module* module = ((Module*)(unit->the_object));
    Cons* tree = NULL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            tree = listO(4, SYM_WALK_STARTUP_TIME_PROGN, KWD_WALK_MODULES, yield_define_module(module), NIL);
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
          resignal();
        }
      }
    }
    walk_auxiliary_tree(tree);
  }
}

Cons* extract_required_argument_values(Class* renamed_Class, Property_List* slotnamesandvalues) {
  { Standard_Object* dummy1;

    { Cons* requiredvalues = NIL;

      { Symbol* sname = NULL;
        Cons* iter_001 = renamed_Class->class_required_slot_names_reader()->the_cons_list;

        while (!nilP(iter_001)) {
          {
            sname = ((Symbol*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          { Object* valueref = slotnamesandvalues->lookup(sname);

            if (valueref != NULL) {
              {
                requiredvalues = cons(walk_expression_tree(valueref, lookup_slot(renamed_Class, sname)->compute_return_type_spec(renamed_Class), SYM_WALK_NEW, FALSE, dummy1), requiredvalues);
                slotnamesandvalues->remove_at(sname);
              }
            }
            else {
              { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_error();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Missing required argument: " << "`" << de_uglify_parse_tree(sname) << "'" << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    resignal();
                  }
                }
              }
            }
          }
        }
      }
      return (requiredvalues->reverse());
    }
  }
}

Cons* yield_new_arguments_tree(Cons* keywordsandvalues, Class* renamed_Class, Symbol* selfvariable, Cons*& return1) {
  if (oddP(keywordsandvalues->length())) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            signal_translation_error();
            if (!(suppress_warningsP())) {
              print_error_context(">> ERROR: ", STANDARD_OUTPUT);
              cout << endl << " " << "Odd number of arguments in 'new' expression: " << "`" << de_uglify_parse_tree(keywordsandvalues) << "'" << "." << endl;
            }
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPRINTREADABLYpo = old_OprintreadablyPO_001;
          resignal();
        }
      }
    }
    { Cons* return_temp = NIL;

      return1 = NIL;
      return (return_temp);
    }
  }
  { Property_List* self_001 = new_property_list();

    self_001->the_plist = keywordsandvalues;
    { Property_List* plist = self_001;
      Cons* otherassignments = NIL;
      Cons* requiredvalues = NULL;
      Slot* slot = NULL;

      { Property_List_Iterator* it = ((Property_List_Iterator*)(plist->allocate_iterator()));

        while (it->nextP()) {
          it->key_setter(intern_symbol(((Keyword*)(it->key))->symbol_name));
        }
      }
      requiredvalues = extract_required_argument_values(renamed_Class, plist);
      { Object* valueref = NULL;
        Symbol* slotname = NULL;
        Cons* iter_001 = plist->the_plist;
        Cons* collect_001 = NULL;

        while (!nilP(iter_001)) {
          slotname = ((Symbol*)(iter_001->value));
          {
            valueref = iter_001->rest->value;
            iter_001 = iter_001->rest->rest;
          }
          slot = lookup_slot(renamed_Class, slotname);
          if (slot == NULL) {
            { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_error();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << " " << "No such slot " << "`" << de_uglify_parse_tree(slotname) << "'" << " on the class " << "`" << class_name(renamed_Class) << "'" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_002;
                  resignal();
                }
              }
            }
            { Cons* return_temp = NIL;

              return1 = NIL;
              return (return_temp);
            }
          }
          if (!storage_slotP(slot)) {
            { Method_Slot* method = ((Method_Slot*)(slot));

              if (((Symbol*)(dynamic_slot_value(method, SYM_WALK_STORAGE_SLOT, NULL))) != NULL) {
                slot = lookup_slot(renamed_Class, ((Symbol*)(dynamic_slot_value(method, SYM_WALK_STORAGE_SLOT, NULL))));
              }
            }
          }
          if (collect_001 == NULL) {
            {
              collect_001 = cons(listO(4, SYM_WALK_SETF, cons(slot->slot_name, cons(selfvariable, NIL)), valueref, NIL), NIL);
              if (nilP(otherassignments)) {
                otherassignments = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(otherassignments, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = cons(listO(4, SYM_WALK_SETF, cons(slot->slot_name, cons(selfvariable, NIL)), valueref, NIL), NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
      { Cons* return_temp = requiredvalues;

        return1 = otherassignments;
        return (return_temp);
      }
    }
  }
}

Cons* walk_new_tree(Cons* tree, Standard_Object*& return1) {
  { Object* renamed_Operator = tree->first();
    Object* classtree = tree->second();
    Object* baseclassname = (consP(classtree) ? ((Object*)(((Cons*)(classtree))->first())) : ((Object*)(classtree)));
    Cons* keywordarguments = tree->rest->rest;
    Symbol* selfvariable = local_gensym("SELF");
    Standard_Object* classtype = NULL;
    Cons* newtree = NULL;

    if ((!symbolP(baseclassname)) &&
        (!keywordP(baseclassname))) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Illegal argument to " << "`" << de_uglify_parse_tree(renamed_Operator) << "'" << " where symbol expected:  " << "`" << de_uglify_parse_tree(baseclassname) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
    }
    classtype = classtree->yield_type_specifier();
    tree->rest->free_cons();
    tree->free_cons();
    { Cons* requiredargs = NULL;
      Cons* otherassignments = NULL;

      requiredargs = yield_new_arguments_tree(keywordarguments, (typeP(classtype) ? ((Surrogate*)(((Surrogate*)(classtype)))) : ((Surrogate*)(((Parametric_Type_Specifier*)(classtype))->specifier_base_type)))->get_class(TRUE), selfvariable, otherassignments);
      newtree = listO(3, SYM_WALK_SYS_NEW, classtype, requiredargs->concatenate(NIL));
      if (otherassignments->emptyP()) {
        { Cons* return_temp = newtree;

          return1 = classtype;
          return (return_temp);
        }
      }
      else {
        { Cons* return_temp = listO(3, SYM_WALK_VRLET, cons(cons(selfvariable, cons(newtree, NIL)), NIL), otherassignments->concatenate(cons(selfvariable, NIL)));

          return1 = classtype;
          return (return_temp);
        }
      }
    }
  }
}

Cons* walk_make_tree(Cons* tree, Standard_Object*& return1) {
  { Object* classname = tree->second();
    Surrogate* type = NULL;

    bad_argument_countP(tree, 1);
    if (symbolP(classname)) {
    }
    else if (typeP(classname)) {
      tree->second_setter(type_to_symbol(((Surrogate*)(classname))));
    }
    else {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Bad argument to 'make':" << endl << "   " << "`" << de_uglify_parse_tree(classname) << "'" << " found where symbol expected" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
      return (walk_dont_call_me_tree(tree, SGT_WALK_UNKNOWN, return1));
    }
    type = typify(classname);
    if (!(((Class*)(type->surrogate_value)) != NULL)) {
      { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Reference to undefined class " << "`" << de_uglify_parse_tree(classname) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_002;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_002;
            resignal();
          }
        }
      }
      return (walk_dont_call_me_tree(tree, SGT_WALK_UNKNOWN, return1));
    }
    { Cons* return_temp = tree;

      return1 = type;
      return (return_temp);
    }
  }
}

Cons* walk_funcall_tree(Cons* tree, Standard_Object*& return1) {
  if ((tree->first() == SYM_WALK_SYS_CALL_FUNCTION_CODE) ||
      (tree->first() == SYM_WALK_SYS_CALL_METHOD_CODE)) {
    { Cons* return_temp = tree;

      return1 = ((Standard_Object*)(((Cons*)(((Cons*)(tree->second()))->first()))->first()));
      return (return_temp);
    }
  }
  { Surrogate* returntype = ((oTARGETTYPEo == SGT_WALK_UNKNOWN) ? ((Surrogate*)(SGT_WALK_VOID)) : ((Surrogate*)(type_spec_to_base_type(oTARGETTYPEo))));
    Cons* signature = cons(cons(returntype, NIL), NIL);

    { Object* otree = NULL;
      Standard_Object* otype = NULL;

      otree = walk_expression_tree(tree->second(), SGT_WALK_CODE, SYM_WALK_FUNCALL, TRUE, otype);
      tree->first_setter(((otype == SGT_WALK_METHOD_CODE) ? ((Symbol*)(SYM_WALK_SYS_CALL_METHOD_CODE)) : ((Symbol*)(SYM_WALK_SYS_CALL_FUNCTION_CODE))));
      tree->second_setter(otree);
    }
    { Cons_Iterator* it = tree->rest->rest->allocate_iterator();

      while (it->nextP()) {
        { Object* argtree = NULL;
          Standard_Object* argtype = NULL;

          argtree = walk_a_tree(it->value, argtype);
          it->value_setter(argtree);
          signature = cons(type_spec_to_base_type(argtype), signature);
          free_transient_type_spec(argtype);
        }
      }
    }
    tree->rest = cons(signature->reverse(), tree->rest);
    { Cons* return_temp = tree;

      return1 = returntype;
      return (return_temp);
    }
  }
}

Cons* walk_the_code_tree(Cons* tree, Standard_Object*& return1) {
  { Object* test_value_001 = tree->second();

    if (test_value_001 == KWD_WALK_FUNCTION) {
      if (bad_argument_countP(tree, 2)) {
        return (walk_dont_call_me_tree(tree, SGT_WALK_FUNCTION_CODE, return1));
      }
      { Keyword* test_value_002 = translator_output_language();

        if ((test_value_002 == KWD_WALK_CPP) ||
            (test_value_002 == KWD_WALK_CPP_STANDALONE)) {
          if (tree->third() == SYM_WALK_MAIN) {
            { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_warning();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Cannot generate function pointer to main" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_001;
                  resignal();
                }
              }
            }
            { Object* value_001 = NULL;
              Standard_Object* value_002 = NULL;

              value_001 = walk_a_tree(listO(4, SYM_WALK_CAST, SYM_WALK_NULL, SYM_WALK_FUNCTION_CODE, NIL), value_002);
              { Cons* return_temp = ((Cons*)(value_001));

                return1 = value_002;
                return (return_temp);
              }
            }
          }
        }
        else {
        }
      }
      { Cons* return_temp = tree;

        return1 = SGT_WALK_FUNCTION_CODE;
        return (return_temp);
      }
    }
    else if (test_value_001 == KWD_WALK_METHOD) {
      if (bad_argument_countP(tree, 3)) {
        return (walk_dont_call_me_tree(tree, SGT_WALK_METHOD_CODE, return1));
      }
      { Surrogate* type = typify(tree->third());

        tree->third_setter(type);
        if (((Class*)(type->surrogate_value)) == NULL) {
          { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  signal_translation_error();
                  if (!(suppress_warningsP())) {
                    print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                    cout << endl << " " << "No class defined for the type: " << "`" << de_uglify_parse_tree(type) << "'" << "." << endl;
                  }
                  oPRINTREADABLYpo = old_OprintreadablyPO_002;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oPRINTREADABLYpo = old_OprintreadablyPO_002;
                resignal();
              }
            }
          }
        }
        else {
          { Keyword* test_value_003 = translator_output_language();

            if ((test_value_003 == KWD_WALK_CPP) ||
                (test_value_003 == KWD_WALK_CPP_STANDALONE)) {
              if (subtype_ofP(type, SGT_WALK_LITERAL)) {
                { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_warning();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Cannot have methods on literals in " << "`" << translator_output_language() << "'" << ", hence, cannot generate" << endl << " a method-code pointer for " << "`" << tree->third() << "'" << "." << "`" << tree->fourth() << "'" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_003;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_003;
                      resignal();
                    }
                  }
                }
                { Object* value_003 = NULL;
                  Standard_Object* value_004 = NULL;

                  value_003 = walk_a_tree(listO(4, SYM_WALK_CAST, SYM_WALK_NULL, SYM_WALK_METHOD_CODE, NIL), value_004);
                  { Cons* return_temp = ((Cons*)(value_003));

                    return1 = value_004;
                    return (return_temp);
                  }
                }
              }
              if (!subtype_ofP(type, SGT_WALK_OBJECT)) {
                { boolean old_OprintreadablyPO_004 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_translation_warning();
                        if (!(suppress_warningsP())) {
                          print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                          cout << endl << " " << "Cannot store a method-code pointer for " << endl << " " << "`" << tree->third() << "'" << "." << "`" << tree->fourth() << "'" << endl << " since it is not defined on a subtype of @OBJECT" << "." << endl;
                        }
                        oPRINTREADABLYpo = old_OprintreadablyPO_004;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_004;
                      resignal();
                    }
                  }
                }
                { Object* value_005 = NULL;
                  Standard_Object* value_006 = NULL;

                  value_005 = walk_a_tree(listO(4, SYM_WALK_CAST, SYM_WALK_NULL, SYM_WALK_METHOD_CODE, NIL), value_006);
                  { Cons* return_temp = ((Cons*)(value_005));

                    return1 = value_006;
                    return (return_temp);
                  }
                }
              }
            }
            else {
            }
          }
        }
        { Cons* return_temp = tree;

          return1 = SGT_WALK_METHOD_CODE;
          return (return_temp);
        }
      }
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

Cons* de_uglify_arguments(Cons* uglyarguments) {
  { Cons* prettyarguments = NIL;

    { Object* arg = NULL;
      Cons* iter_001 = uglyarguments;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          arg = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(de_uglify_parse_tree(arg), NIL);
            if (nilP(prettyarguments)) {
              prettyarguments = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(prettyarguments, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(de_uglify_parse_tree(arg), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    return (prettyarguments);
  }
}

Object* de_uglify_parse_tree(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Object* renamed_Operator = tree->first();

          if (!symbolP(renamed_Operator)) {
            return (de_uglify_arguments(tree));
          }
          if ((renamed_Operator == SYM_WALK_SYS_SLOT_VALUE) ||
              ((renamed_Operator == SYM_WALK_SYS_SLOT_VALUE_SETTER) ||
               (renamed_Operator == SYM_WALK_SYS_CALL_METHOD))) {
            return (de_uglify_parse_tree(tree->rest->rest));
          }
          else if (renamed_Operator == SYM_WALK_SYS_CALL_FUNCTION) {
            return (de_uglify_parse_tree(tree->rest));
          }
          else if ((renamed_Operator == SYM_WALK_TYPED_SYS) ||
              ((renamed_Operator == SYM_WALK_VOID_SYS) ||
               (renamed_Operator == SYM_WALK_BAD_SYS))) {
            return (de_uglify_parse_tree(tree->second()));
          }
          else if (renamed_Operator == SYM_WALK_GET_SYM) {
            return (get_sym_from_offset(((Integer_Wrapper*)(tree->second()))->wrapper_value));
          }
          else {
            { Cons* prettyarguments = NIL;

              { Object* arg = NULL;
                Cons* iter_001 = tree->rest;
                Cons* collect_001 = NULL;

                while (!nilP(iter_001)) {
                  {
                    arg = iter_001->value;
                    iter_001 = iter_001->rest;
                  }
                  if (collect_001 == NULL) {
                    {
                      collect_001 = cons(de_uglify_parse_tree(arg), NIL);
                      if (nilP(prettyarguments)) {
                        prettyarguments = collect_001;
                      }
                      else {
                        add_cons_to_end_of_cons_list(prettyarguments, collect_001);
                      }
                    }
                  }
                  else {
                    {
                      collect_001->rest = cons(de_uglify_parse_tree(arg), NIL);
                      collect_001 = collect_001->rest;
                    }
                  }
                }
              }
              return (cons(renamed_Operator, prettyarguments->concatenate(NIL)));
            }
          }
        }
      }
    }
    else if (taxonomy_isaP(tree, SGT_WALK_COMPOUND_TYPE_SPECIFIER)) {
      { Compound_Type_Specifier* tree = NULL;

        tree = ((Compound_Type_Specifier*)(tree_001));
        { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oTRANSIENTOBJECTSpo = TRUE;
                { Object* return_value_001 = yield_type_spec_tree(tree);

                  oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  return (return_value_001);
                }
                oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
              resignal();
            }
          }
        }
      }
    }
    else {
      return (tree);
    }
  }
}

void register_native_name(Symbol* name, Keyword* language, Keyword* category) {
  { Key_Value_List* tableentry = ((Key_Value_List*)(oNATIVE_NAME_TABLEo->lookup(name)));
    List* categories = NULL;

    if (tableentry == NULL) {
      tableentry = new_key_value_list();
    }
    categories = ((List*)(tableentry->lookup(language)));
    if (categories == NULL) {
      categories = new_list();
    }
    categories->insert_new(category);
    tableentry->insert_at(language, categories);
    oNATIVE_NAME_TABLEo->insert_at(name, tableentry);
  }
}

boolean native_nameP(Symbol* name, Keyword* language, Keyword* category) {
  { Key_Value_List* tableentry = ((Key_Value_List*)(oNATIVE_NAME_TABLEo->lookup(name)));
    List* categories = NULL;

    if (tableentry == NULL) {
      return (FALSE);
    }
    categories = ((List*)(tableentry->lookup(language)));
    if (categories == NULL) {
      return (FALSE);
    }
    else {
      return (categories->memberP(category));
    }
  }
}

Symbol* yield_renamed_name_if_native(Symbol* name, Keyword* language, Keyword* category) {
  if (native_nameP(name, language, category)) {
    { Symbol* newname = NULL;

      if (language == KWD_WALK_COMMON_LISP) {
        newname = intern_derived_symbol(name, string_concatenate("%%", name->symbol_name));
      }
      else {
        newname = intern_derived_symbol(name, string_concatenate(name->symbol_name, "_"));
      }
      return (yield_renamed_name_if_native(newname, language, category));
    }
  }
  else {
    return (name);
  }
}

boolean method_needs_lisp_macroP(Method_Slot* method) {
  if (translate_to_common_lispP() &&
      method->method_parameter_names_reader()->non_emptyP()) {
    { boolean lispmacroP = method->method_lisp_macroP_reader();

      return (((lispmacroP != NULL_BOOLEAN) &&
          lispmacroP) ||
          (commandP(method) &&
           ((!method->method_nativeP_reader()) &&
            ((lispmacroP == NULL_BOOLEAN) ||
             lispmacroP))));
    }
  }
  else {
    return (FALSE);
  }
}

Cons* yield_lisp_macro_trees(Symbol* name, Method_Slot* method, Cons*& return1) {
  { Module* module = ((((Module*)(name->home_context)) != NULL) ? ((Module*)(((Module*)(name->home_context)))) : ((Module*)(oMODULEo)));
    Object* translatedname = yield_global_lisp_symbol(module, name->symbol_name);
    Object* translatedfullname = yield_global_lisp_symbol(module, compute_full_name(name->symbol_name, module));
    char* documentation = ((String_Wrapper*)(dynamic_slot_value(method, SYM_WALK_DOCUMENTATION, NULL_STRING_WRAPPER)))->wrapper_value;

    { Cons* return_temp = listO(6, SYM_WALK_VERBATIM, KWD_WALK_COMMON_LISP, listO(3, intern_common_lisp_symbol("DEFMACRO"), translatedname, cons(listO(5, intern_common_lisp_symbol("&WHOLE"), SYM_WALK_EXPRESSION, intern_common_lisp_symbol("&REST"), SYM_WALK_IGNORE, NIL), ((documentation != NULL) ? ((Cons*)(cons(string_wrap_literal(documentation), NIL))) : ((Cons*)(NIL)))->concatenate(listO(3, listO(3, intern_common_lisp_symbol("DECLARE"), listO(3, intern_common_lisp_symbol("IGNORE"), SYM_WALK_IGNORE, NIL), NIL), listO(4, intern_common_lisp_symbol("LET"), cons(listO(3, SYM_WALK_oIGNORETRANSLATIONERRORSpo, (commandP(method) ? ((Symbol*)(SYM_WALK_FALSE)) : ((Symbol*)(SYM_WALK_TRUE))), NIL), NIL), listO(4, SYM_WALK_INCREMENTALLY_TRANSLATE, SYM_WALK_EXPRESSION, SYM_WALK_FALSE, NIL), NIL), NIL)))), KWD_WALK_OTHERWISE, SYM_WALK_NULL, NIL);

      return1 = listO(6, SYM_WALK_VERBATIM, KWD_WALK_COMMON_LISP, listO(4, SYM_WALK_SETF, listO(3, intern_common_lisp_symbol("MACRO-FUNCTION"), listO(3, intern_common_lisp_symbol("QUOTE"), translatedfullname, NIL), NIL), listO(3, intern_common_lisp_symbol("MACRO-FUNCTION"), listO(3, intern_common_lisp_symbol("QUOTE"), translatedname, NIL), NIL), NIL), KWD_WALK_OTHERWISE, SYM_WALK_NULL, NIL);
      return (return_temp);
    }
  }
}

void create_lisp_macro_units(Symbol* name, Method_Slot* method) {
  if (name == method->slot_name) {
    register_native_name(name, KWD_WALK_COMMON_LISP, KWD_WALK_FUNCTION);
  }
  { Cons* macrotree = NULL;
    Cons* aliasdefinitiontree = NULL;

    macrotree = yield_lisp_macro_trees(name, method, aliasdefinitiontree);
    walk_auxiliary_tree(macrotree);
    walk_auxiliary_tree(aliasdefinitiontree);
  }
  if (name == method->slot_name) {
    { Cons* startuptree = NIL;

      { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oTRANSIENTOBJECTSpo = TRUE;
              startuptree = listO(3, SYM_WALK_STARTUP_TIME_PROGN, listO(5, SYM_WALK_REGISTER_NATIVE_NAME, listO(3, SYM_WALK_QUOTE, name, NIL), KWD_WALK_COMMON_LISP, KWD_WALK_FUNCTION, NIL), NIL);
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
            resignal();
          }
        }
      }
      walk_auxiliary_tree(startuptree);
    }
  }
}

boolean commandP(Method_Slot* method) {
  // Return TRUE if 'method' is an evaluable command.
  return (method->method_commandP_reader() &&
      method->method_functionP);
}

Method_Slot* lookup_command(Symbol* name) {
  // If 'name' names an evaluable command return its associated
  // command object;  otherwise, return NULL.  Currently, commands are not
  // polymorphic, i.e., they can only be implemented by functions.
  { Method_Slot* function = name->lookup_function();

    if ((function != NULL) &&
        commandP(function)) {
      return (function);
    }
    else {
      return (NULL);
    }
  }
}

boolean method_must_be_evaluableP(Method_Slot* method) {
  return (commandP(method) &&
      (!method->method_nativeP_reader()));
}

boolean method_needs_evaluator_wrapperP(Method_Slot* method) {
  { boolean test_value_001 = FALSE;

    test_value_001 = method_must_be_evaluableP(method);
    if (test_value_001) {
      if (method->method_variable_argumentsP_reader()) {
        test_value_001 = TRUE;
      }
      else {
        if (method->method_parameter_names_reader()->length() > 5) {
          test_value_001 = TRUE;
        }
        else {
          if (method->method_return_type_specifiers_reader()->length() > 1) {
            test_value_001 = TRUE;
          }
          else {
            if (subtype_ofP(method->type(), SGT_WALK_LITERAL)) {
              test_value_001 = TRUE;
            }
            else {
              { boolean foundP_001 = FALSE;

                { Standard_Object* tspec = NULL;
                  Cons* iter_001 = method->method_parameter_type_specifiers_reader()->the_cons_list;

                  while (!nilP(iter_001)) {
                    {
                      tspec = ((Standard_Object*)(iter_001->value));
                      iter_001 = iter_001->rest;
                    }
                    if (subtype_ofP(type_spec_to_base_type(tspec), SGT_WALK_LITERAL)) {
                      foundP_001 = TRUE;
                      break;
                    }
                  }
                }
                test_value_001 = foundP_001;
              }
            }
          }
        }
      }
    }
    { boolean value_001 = test_value_001;

      return (value_001);
    }
  }
}

Symbol* yield_evaluator_wrapper_name(Symbol* methodname) {
  return (intern_derived_symbol(methodname, string_concatenate(methodname->symbol_name, "-EVALUATOR-WRAPPER")));
}

Object* yield_argument_access_tree(Symbol* argumentsvariable, int index, boolean restargumentP) {
  { int limit = 5;
    Object* accesstree = argumentsvariable;

    if (index <= limit) {
      { int i = NULL_INTEGER;
        int iter_001 = 2;
        int upper_bound_001 = index;
        boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

        while (unboundedP_001 ||
            (iter_001 <= upper_bound_001)) {
          {
            i = iter_001;
            iter_001 = iter_001 + 1;
          }
          accesstree = listO(3, SYM_WALK_REST, accesstree, NIL);
        }
      }
    }
    else {
      accesstree = listO(3, SYM_WALK_NTH_REST, accesstree, cons(integer_wrap_literal(index - 1), NIL));
    }
    if (!restargumentP) {
      if (index <= limit) {
        accesstree = listO(3, SYM_WALK_VALUE, accesstree, NIL);
      }
      else {
        ((Cons*)(accesstree))->value = SYM_WALK_NTH;
      }
    }
    return (accesstree);
  }
}

Cons* yield_evaluator_wrapper_tree(Method_Slot* method) {
  { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTRANSIENTOBJECTSpo = TRUE;
          { Object* nametree = yield_evaluator_wrapper_name(method->slot_name);
            Cons* calltree = cons(method->slot_name, NIL);
            List* parametertypespecs = method->method_parameter_type_specifiers_reader();
            Surrogate* resulttype = method->type();
            int nofparameters = parametertypespecs->length();
            boolean variableargumentsP = method->method_variable_argumentsP_reader();

            { int index = NULL_INTEGER;
              int iter_001 = 1;
              int upper_bound_001 = nofparameters;
              boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;
              Cons* collect_001 = NULL;

              while (unboundedP_001 ||
                  (iter_001 <= upper_bound_001)) {
                {
                  index = iter_001;
                  iter_001 = iter_001 + 1;
                }
                if (collect_001 == NULL) {
                  {
                    collect_001 = cons(yield_argument_access_tree(SYM_WALK_ARGUMENTS, index, variableargumentsP &&
                        (index == nofparameters)), NIL);
                    if (nilP(calltree)) {
                      calltree = collect_001;
                    }
                    else {
                      add_cons_to_end_of_cons_list(calltree, collect_001);
                    }
                  }
                }
                else {
                  {
                    collect_001->rest = cons(yield_argument_access_tree(SYM_WALK_ARGUMENTS, index, variableargumentsP &&
                        (index == nofparameters)), NIL);
                    collect_001 = collect_001->rest;
                  }
                }
              }
            }
            { Standard_Object* ptype = NULL;
              Cons* iter_002 = parametertypespecs->the_cons_list;
              Cons_Iterator* it = calltree->rest->allocate_iterator();

              while ((!nilP(iter_002)) &&
                  it->nextP()) {
                {
                  ptype = ((Standard_Object*)(iter_002->value));
                  iter_002 = iter_002->rest;
                }
                if (sub_type_spec_ofP(ptype, SGT_WALK_LITERAL)) {
                  it->value_setter(listO(3, SYM_WALK_WRAPPER_VALUE, listO(3, SYM_WALK_SAFE_CAST, it->value, cons(type_spec_to_base_type(ptype)->type_to_wrapped_type(), NIL)), NIL));
                }
                else {
                  if (!(ptype == SGT_WALK_OBJECT)) {
                    it->value_setter(listO(3, SYM_WALK_SAFE_CAST, it->value, cons(yield_type_spec_tree(ptype), NIL)));
                  }
                }
              }
            }
            if (voidP(resulttype)) {
            }
            else if (subtype_ofP(resulttype, SGT_WALK_LITERAL)) {
              nametree = cons(nametree, cons(resulttype->type_to_wrapped_type(), NIL));
              calltree = listO(4, SYM_WALK_LET, cons(listO(3, SYM_WALK_RESULT, calltree, NIL), NIL), listO(5, SYM_WALK_IF, listO(3, SYM_WALK_DEFINEDp, SYM_WALK_RESULT, NIL), listO(3, SYM_WALK_RETURN, cons(((method->type() == SGT_WALK_BOOLEAN) ? ((Symbol*)(SYM_WALK_WRAP_BOOLEAN)) : ((Symbol*)(SYM_WALK_WRAP_LITERAL))), cons(SYM_WALK_RESULT, NIL)), NIL), listO(3, SYM_WALK_RETURN, SYM_WALK_NULL, NIL), NIL), NIL);
            }
            else {
              nametree = cons(nametree, cons(resulttype, NIL));
              calltree = listO(3, SYM_WALK_RETURN, calltree, NIL);
            }
            { Cons* return_value_001 = listO(3, SYM_WALK_DEFUN, nametree, listO(5, cons(listO(3, SYM_WALK_ARGUMENTS, SYM_WALK_CONS, NIL), NIL), KWD_WALK_AUXILIARYp, SYM_WALK_TRUE, calltree, NIL));

              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (return_value_001);
            }
          }
          oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
        resignal();
      }
    }
  }
}

void create_evaluator_wrapper_unit(Method_Slot* method) {
  { boolean variableargumentsP = method->method_variable_argumentsP_reader();
    boolean evaluateargumentsP = method->method_evaluate_argumentsP_reader();
    Cons* wrappertree = yield_evaluator_wrapper_tree(method);

    if (method->method_return_type_specifiers_reader()->length() > 1) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_warning();
              if (!(suppress_warningsP())) {
                print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                cout << endl << " " << "During interpreted command evaluation only the" << endl << " first return value will be usable" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_001;
            resignal();
          }
        }
      }
    }
    if (!evaluateargumentsP) {
      set_dynamic_slot_value(method, SYM_WALK_METHOD_EVALUATE_ARGUMENTSp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
    }
    if (variableargumentsP) {
      set_dynamic_slot_value(method, SYM_WALK_METHOD_VARIABLE_ARGUMENTSp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
    }
    walk_auxiliary_tree(wrappertree);
    if (!evaluateargumentsP) {
      set_dynamic_slot_value(method, SYM_WALK_METHOD_EVALUATE_ARGUMENTSp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
    }
    if (variableargumentsP) {
      set_dynamic_slot_value(method, SYM_WALK_METHOD_VARIABLE_ARGUMENTSp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
    }
  }
}

boolean read_OevaluationerrorPO() {
  return (oEVALUATIONERRORpo);
}

boolean write_OevaluationerrorPO(boolean value) {
  oEVALUATIONERRORpo = value;
  return (value);
}

void reset_evaluation_error() {
  // Reset the global evaluation error indicator.
  oEVALUATIONERRORpo = FALSE;
}

void signal_evaluation_error() {
  // Signal an evaluation error.  This is done automatically
  // by calling 'eval-error'.
  oEVALUATIONERRORpo = TRUE;
}

boolean evaluation_errorP() {
  // Return TRUE if the global evaluation error indicator is set.
  return (oEVALUATIONERRORpo);
}

Object* read_OevaluationtreeO() {
  return (oEVALUATIONTREEo);
}

Object* write_OevaluationtreeO(Object* value) {
  oEVALUATIONTREEo = value;
  return (value);
}

Object* read_OevaluationparenttreeO() {
  return (oEVALUATIONPARENTTREEo);
}

Object* write_OevaluationparenttreeO(Object* value) {
  oEVALUATIONPARENTTREEo = value;
  return (value);
}

void print_evaluation_error_context(char* prefix, Output_Stream* stream) {
  *(stream->native_stream) << prefix << "While evaluating '" << oEVALUATIONTREEo;
  if (oEVALUATIONPARENTTREEo != NULL) {
    *(stream->native_stream) << "' inside '" << oEVALUATIONPARENTTREEo;
  }
  *(stream->native_stream) << "':";
}

Object* evaluate(Object* expression, Standard_Object*& return1, boolean& return2) {
  // Evaluate the expression `expression' and return the result.
  // Currently, only the evaluation of (possibly nested) commands and global
  // variables is supported.  The second return value indicates the actual type 
  // of the result (which might have been wrapped), and the third return value
  // indicates whether an error occurred during the evaluation.
  reset_evaluation_error();
  { Object* otree = NULL;
    Standard_Object* otype = SGT_WALK_UNKNOWN;

    if (expression != NULL) {
      { Object* expression_001 = expression;

        if (consP(expression)) {
          { Cons* expression = NULL;

            expression = ((Cons*)(expression_001));
            otree = evaluate_cons_tree(expression, otype);
          }
        }
        else {
          otree = evaluate_atomic_tree(expression, otype);
        }
      }
    }
    { Object* return_temp = otree;

      return1 = otype;
      return2 = evaluation_errorP();
      return (return_temp);
    }
  }
}

Object* evaluate_string(char* expression, Standard_Object*& return1, boolean& return2) {
  // Evaluate the expression represented by `expression' and return the result.
  // This is equivalent to `(evaluate (unstringify expression))'.
  return (evaluate(unstringify(expression), return1, return2));
}

Object* try_to_evaluate(Object* tree, Standard_Object*& return1, boolean& return2) {
  // Variant of 'evaluate' that only evaluates 'tree' if it
  // represents an evaluable expression.  If it does not, 'tree' is returned
  // unmodified.  This can be used to implement commands with mixed argument
  // evaluation strategies.
  reset_evaluation_error();
  { Object* otree = tree;
    Standard_Object* otype = SGT_WALK_UNKNOWN;

    if (tree != NULL) {
      { Object* tree_001 = tree;

        if (consP(tree)) {
          { Cons* tree = NULL;

            tree = ((Cons*)(tree_001));
            if (symbolP(tree->value) &&
                (lookup_command(((Symbol*)(tree->value))) != NULL)) {
              otree = evaluate_cons_tree(tree, otype);
            }
            else {
              otype = tree->primary_type();
            }
          }
        }
        else {
          otype = tree->primary_type();
        }
      }
    }
    { Object* return_temp = otree;

      return1 = otype;
      return2 = evaluation_errorP();
      return (return_temp);
    }
  }
}

Object* evaluate_cons_tree(Cons* tree, Standard_Object*& return1) {
  { Object* old_OevaluationparenttreeO_001 = oEVALUATIONPARENTTREEo;
    Object* old_OevaluationtreeO_001 = oEVALUATIONTREEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oEVALUATIONPARENTTREEo = oEVALUATIONTREEo;
          oEVALUATIONTREEo = tree;
          { Object* operatorname = tree->value;
            Cons* arguments = tree->rest;
            Method_Slot* renamed_Operator = NULL;

            { Object* operatorname_001 = operatorname;

              if (symbolP(operatorname)) {
                { Symbol* operatorname = NULL;

                  operatorname = ((Symbol*)(operatorname_001));
                  if (operatorname == SYM_WALK_QUOTE) {
                    if (arguments->length() == 1) {
                      { Object* return_value_001 = arguments->value;
                        Surrogate* return_value_002 = arguments->value->primary_type();

                        oEVALUATIONTREEo = old_OevaluationtreeO_001;
                        oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                        { Object* return_temp = return_value_001;

                          return1 = return_value_002;
                          return (return_temp);
                        }
                      }
                    }
                    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                      { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                        oEXCEPTIONHANDLERADDRESSo = NULL;
                        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                          {
                            oPRINTREADABLYpo = TRUE;
                            signal_evaluation_error();
                            print_evaluation_error_context(">> ERROR: ", STANDARD_OUTPUT);
                            cout << endl << "   " << "Illegal QUOTE expression" << "." << endl;
                            oPRINTREADABLYpo = old_OprintreadablyPO_001;
                          }
                          oEXCEPTIONo = NULL;
                        }
                        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                      }
                      if (oEXCEPTIONo != NULL) {
                        if (TRUE) {
                          oPRINTREADABLYpo = old_OprintreadablyPO_001;
                          resignal();
                        }
                      }
                    }
                    { 
                      oEVALUATIONTREEo = old_OevaluationtreeO_001;
                      oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                      { Object* return_temp = NULL;

                        return1 = NULL;
                        return (return_temp);
                      }
                    }
                  }
                  else {
                    { boolean test_value_001 = FALSE;

                      { 
                        renamed_Operator = lookup_command(operatorname);
                        test_value_001 = renamed_Operator != NULL;
                      }
                      test_value_001 = !test_value_001;
                      if (test_value_001) {
                        { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                          { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                            oEXCEPTIONHANDLERADDRESSo = NULL;
                            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                              {
                                oPRINTREADABLYpo = TRUE;
                                signal_evaluation_error();
                                print_evaluation_error_context(">> ERROR: ", STANDARD_OUTPUT);
                                cout << endl << "   " << "Undefined operator: " << "`" << de_uglify_parse_tree(operatorname) << "'" << "." << endl;
                                oPRINTREADABLYpo = old_OprintreadablyPO_002;
                              }
                              oEXCEPTIONo = NULL;
                            }
                            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                          }
                          if (oEXCEPTIONo != NULL) {
                            if (TRUE) {
                              oPRINTREADABLYpo = old_OprintreadablyPO_002;
                              resignal();
                            }
                          }
                        }
                        { 
                          oEVALUATIONTREEo = old_OevaluationtreeO_001;
                          oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                          { Object* return_temp = NULL;

                            return1 = NULL;
                            return (return_temp);
                          }
                        }
                      }
                    }
                  }
                }
              }
              else {
                { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_evaluation_error();
                        print_evaluation_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << "   " << "Illegal operator: " << "`" << de_uglify_parse_tree(operatorname) << "'" << "." << endl;
                        oPRINTREADABLYpo = old_OprintreadablyPO_003;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_003;
                      resignal();
                    }
                  }
                }
                { 
                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = NULL;

                    return1 = NULL;
                    return (return_temp);
                  }
                }
              }
            }
            { cpp_function_code evaluatorwrappercode = ((Function_Code_Wrapper*)(dynamic_slot_value(renamed_Operator, SYM_WALK_EVALUATOR_WRAPPER_CODE, NULL_FUNCTION_CODE_WRAPPER)))->wrapper_value;
              boolean evaluateargsP = renamed_Operator->method_evaluate_argumentsP_reader();
              boolean variableargsP = renamed_Operator->method_variable_argumentsP_reader();
              List* parametertypes = renamed_Operator->method_parameter_type_specifiers_reader();
              int nofparameters = parametertypes->length();
              int nofargs = arguments->length();
              int minargs = (variableargsP ? ((int)(nofparameters - 1)) : ((int)(nofparameters)));
              int maxargs = (variableargsP ? ((int)(NULL_INTEGER)) : ((int)(nofparameters)));
              Cons* unevaluatedargs = arguments;
              Object* evaluatedarg = NULL;
              Standard_Object* evaluatedargtype = NULL;
              int argindex = 0;
              Surrogate* returntype = renamed_Operator->type();
              Object* result = NULL;

              if ((nofargs < minargs) ||
                  ((maxargs != NULL_INTEGER) &&
                   (nofargs > maxargs))) {
                { boolean old_OprintreadablyPO_004 = oPRINTREADABLYpo;

                  { jump_buffer old_OexceptionhandleraddressO_005 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        signal_evaluation_error();
                        print_evaluation_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << "   " << "Wrong number of arguments" << "." << endl;
                        oPRINTREADABLYpo = old_OprintreadablyPO_004;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_005;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTREADABLYpo = old_OprintreadablyPO_004;
                      resignal();
                    }
                  }
                }
                { 
                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = NULL;

                    return1 = NULL;
                    return (return_temp);
                  }
                }
              }
              while (unevaluatedargs->non_emptyP()) {
                evaluatedarg = evaluate_argument_tree(unevaluatedargs->value, evaluateargsP, evaluatedargtype);
                if (evaluation_errorP()) {
                  { 
                    oEVALUATIONTREEo = old_OevaluationtreeO_001;
                    oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                    { Object* return_temp = NULL;

                      return1 = NULL;
                      return (return_temp);
                    }
                  }
                }
                evaluatedarg = coerce_evaluated_tree(evaluatedarg, unevaluatedargs->value, evaluatedargtype, ((argindex >= minargs) ? ((Standard_Object*)(variable_arguments_type(renamed_Operator))) : ((Standard_Object*)(((Standard_Object*)(parametertypes->nth(argindex)))))), evaluateargsP, evaluatedargtype);
                if (evaluation_errorP()) {
                  { 
                    oEVALUATIONTREEo = old_OevaluationtreeO_001;
                    oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                    { Object* return_temp = NULL;

                      return1 = NULL;
                      return (return_temp);
                    }
                  }
                }
                unevaluatedargs->value = evaluatedarg;
                unevaluatedargs = unevaluatedargs->rest;
                argindex = argindex + 1;
              }
              if (evaluatorwrappercode != NULL) {
                if (voidP(returntype)) {
                  ((void (*) (Cons*))evaluatorwrappercode)(arguments);
                }
                else {
                  result = ((Object* (*) (Cons*))evaluatorwrappercode)(arguments);
                }
              }
              else {
                if (voidP(returntype)) {
                  apply(renamed_Operator->function_code, arguments);
                }
                else {
                  result = apply(renamed_Operator->function_code, arguments);
                }
              }
              { 
                oEVALUATIONTREEo = old_OevaluationtreeO_001;
                oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Object* return_temp = result;

                  return1 = returntype;
                  return (return_temp);
                }
              }
            }
          }
          oEVALUATIONTREEo = old_OevaluationtreeO_001;
          oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oEVALUATIONTREEo = old_OevaluationtreeO_001;
        oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
        resignal();
      }
    }
  }
}

Object* evaluate_argument_tree(Object* tree, boolean evaluateP, Standard_Object*& return1) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        if (evaluateP) {
          return (evaluate_cons_tree(tree, return1));
        }
        else {
          { Object* return_temp = tree;

            return1 = SGT_WALK_CONS;
            return (return_temp);
          }
        }
      }
    }
    else if (wrapperP(tree)) {
      { Wrapper* tree = NULL;

        tree = ((Wrapper*)(tree_001));
        { Object* return_temp = tree;

          return1 = wrapped_type_to_type(tree->primary_type());
          return (return_temp);
        }
      }
    }
    else {
      if (evaluateP) {
        return (evaluate_atomic_tree(tree, return1));
      }
      else {
        { Object* return_temp = tree;

          return1 = tree->primary_type();
          return (return_temp);
        }
      }
    }
  }
}

Object* evaluate_atomic_tree(Object* tree, Standard_Object*& return1) {
  { Object* old_OevaluationparenttreeO_001 = oEVALUATIONPARENTTREEo;
    Object* old_OevaluationtreeO_001 = oEVALUATIONTREEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oEVALUATIONPARENTTREEo = oEVALUATIONTREEo;
          oEVALUATIONTREEo = tree;
          { Object* tree_001 = tree;

            if (symbolP(tree)) {
              { Symbol* tree = NULL;

                tree = ((Symbol*)(tree_001));
                if (tree == SYM_WALK_NULL) {
                  { 
                    oEVALUATIONTREEo = old_OevaluationtreeO_001;
                    oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                    { Object* return_temp = tree;

                      return1 = SGT_WALK_UNKNOWN;
                      return (return_temp);
                    }
                  }
                }
                else if (tree == SYM_WALK_TRUE) {
                  { 
                    oEVALUATIONTREEo = old_OevaluationtreeO_001;
                    oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                    { Object* return_temp = TRUE_WRAPPER;

                      return1 = SGT_WALK_BOOLEAN;
                      return (return_temp);
                    }
                  }
                }
                else if (tree == SYM_WALK_FALSE) {
                  { 
                    oEVALUATIONTREEo = old_OevaluationtreeO_001;
                    oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                    { Object* return_temp = FALSE_WRAPPER;

                      return1 = SGT_WALK_BOOLEAN;
                      return (return_temp);
                    }
                  }
                }
                else {
                  { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                    { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oPRINTREADABLYpo = TRUE;
                          signal_evaluation_error();
                          print_evaluation_error_context(">> ERROR: ", STANDARD_OUTPUT);
                          cout << endl << "   " << "Variable evaluation not yet implemented" << "." << endl;
                          oPRINTREADABLYpo = old_OprintreadablyPO_001;
                        }
                        oEXCEPTIONo = NULL;
                      }
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                    }
                    if (oEXCEPTIONo != NULL) {
                      if (TRUE) {
                        oPRINTREADABLYpo = old_OprintreadablyPO_001;
                        resignal();
                      }
                    }
                  }
                  { 
                    oEVALUATIONTREEo = old_OevaluationtreeO_001;
                    oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                    { Object* return_temp = NULL;

                      return1 = NULL;
                      return (return_temp);
                    }
                  }
                }
              }
            }
            else if (surrogateP(tree)) {
              { Surrogate* tree = NULL;

                tree = ((Surrogate*)(tree_001));
                { 
                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = tree;

                    return1 = SGT_WALK_SURROGATE;
                    return (return_temp);
                  }
                }
              }
            }
            else if (keywordP(tree)) {
              { Keyword* tree = NULL;

                tree = ((Keyword*)(tree_001));
                { 
                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = tree;

                    return1 = SGT_WALK_KEYWORD;
                    return (return_temp);
                  }
                }
              }
            }
            else if (wrapperP(tree)) {
              { Wrapper* tree = NULL;

                tree = ((Wrapper*)(tree_001));
                { Surrogate* return_value_001 = wrapped_type_to_type(tree->primary_type());

                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = tree;

                    return1 = return_value_001;
                    return (return_temp);
                  }
                }
              }
            }
            else {
              { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_evaluation_error();
                      print_evaluation_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << "   " << "Unknown atomic expression type: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
                      oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    resignal();
                  }
                }
              }
              { 
                oEVALUATIONTREEo = old_OevaluationtreeO_001;
                oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Object* return_temp = NULL;

                  return1 = NULL;
                  return (return_temp);
                }
              }
            }
          }
          oEVALUATIONTREEo = old_OevaluationtreeO_001;
          oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oEVALUATIONTREEo = old_OevaluationtreeO_001;
        oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
        resignal();
      }
    }
  }
}

Object* coerce_evaluated_tree(Object* tree, Object* sourcetree, Standard_Object* sourcetype, Standard_Object* targettype, boolean evaluateP, Standard_Object*& return1) {
  { Object* old_OevaluationparenttreeO_001 = oEVALUATIONPARENTTREEo;
    Object* old_OevaluationtreeO_001 = oEVALUATIONTREEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oEVALUATIONPARENTTREEo = oEVALUATIONTREEo;
          oEVALUATIONTREEo = sourcetree;
          { Surrogate* sourcebasetype = type_spec_to_base_type(sourcetype);
            Surrogate* targetbasetype = type_spec_to_base_type(targettype);

            if (tree == SYM_WALK_NULL) {
              if (targettype == SGT_WALK_INTEGER) {
                { 
                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = NULL_INTEGER_WRAPPER;

                    return1 = targettype;
                    return (return_temp);
                  }
                }
              }
              else if (targettype == SGT_WALK_FLOAT) {
                { 
                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = NULL_FLOAT_WRAPPER;

                    return1 = targettype;
                    return (return_temp);
                  }
                }
              }
              else if (targettype == SGT_WALK_STRING) {
                { 
                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = NULL_STRING_WRAPPER;

                    return1 = targettype;
                    return (return_temp);
                  }
                }
              }
              else if (targettype == SGT_WALK_BOOLEAN) {
                { 
                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = FALSE_WRAPPER;

                    return1 = targettype;
                    return (return_temp);
                  }
                }
              }
              else {
                { 
                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = NULL;

                    return1 = targettype;
                    return (return_temp);
                  }
                }
              }
            }
            if ((targettype == SGT_WALK_BOOLEAN) &&
                (!evaluateP)) {
              if (tree == SYM_WALK_TRUE) {
                { 
                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = TRUE_WRAPPER;

                    return1 = targettype;
                    return (return_temp);
                  }
                }
              }
              if (tree == SYM_WALK_FALSE) {
                { 
                  oEVALUATIONTREEo = old_OevaluationtreeO_001;
                  oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  { Object* return_temp = FALSE_WRAPPER;

                    return1 = targettype;
                    return (return_temp);
                  }
                }
              }
            }
            if (subtype_ofP(sourcebasetype, targetbasetype)) {
              { 
                oEVALUATIONTREEo = old_OevaluationtreeO_001;
                oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Object* return_temp = tree;

                  return1 = sourcetype;
                  return (return_temp);
                }
              }
            }
            if ((!evaluateP) &&
                (subtype_ofP(sourcebasetype, SGT_WALK_LITERAL) &&
                 subtype_ofP(sourcebasetype->type_to_wrapped_type(), targetbasetype))) {
              { Surrogate* return_value_001 = sourcebasetype->type_to_wrapped_type();

                oEVALUATIONTREEo = old_OevaluationtreeO_001;
                oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Object* return_temp = tree;

                  return1 = return_value_001;
                  return (return_temp);
                }
              }
            }
            if (subtype_ofP(targetbasetype, SGT_WALK_LITERAL) &&
                subtype_ofP(sourcebasetype, targetbasetype->type_to_wrapped_type())) {
              { 
                oEVALUATIONTREEo = old_OevaluationtreeO_001;
                oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Object* return_temp = tree;

                  return1 = targettype;
                  return (return_temp);
                }
              }
            }
            if (voidP(sourcetype)) {
              { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_evaluation_error();
                      print_evaluation_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << "   " << "`" << ((Cons*)(sourcetree))->value << "'" << " does not return a value" << "." << endl;
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_001;
                    resignal();
                  }
                }
              }
            }
            else {
              { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_evaluation_error();
                      print_evaluation_error_context(">> ERROR: ", STANDARD_OUTPUT);
                      cout << endl << "   " << "Type conflict: " << "`" << yield_type_spec_tree(sourcetype) << "'" << " found where " << "`" << yield_type_spec_tree(targettype) << "'" << " expected" << "." << endl;
                      oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_002;
                    resignal();
                  }
                }
              }
            }
            { 
              oEVALUATIONTREEo = old_OevaluationtreeO_001;
              oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              { Object* return_temp = NULL;

                return1 = NULL;
                return (return_temp);
              }
            }
          }
          oEVALUATIONTREEo = old_OevaluationtreeO_001;
          oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oEVALUATIONTREEo = old_OevaluationtreeO_001;
        oEVALUATIONPARENTTREEo = old_OevaluationparenttreeO_001;
        resignal();
      }
    }
  }
}

void startup_walk() {
  if (current_startup_time_phaseP(0)) {
    oQUOTATION_TABLEo = new_string_hash_table();
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
            KWD_WALK_WARN_ABOUT_UNDEFINED_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("WARN-ABOUT-UNDEFINED-METHODS", NULL, 2)));
            KWD_WALK_SUPPRESS_WARNINGS = ((Keyword*)(intern_rigid_symbol_wrt_module("SUPPRESS-WARNINGS", NULL, 2)));
            KWD_WALK_USE_BOOTSTRAP_TRANSLATOR = ((Keyword*)(intern_rigid_symbol_wrt_module("USE-BOOTSTRAP-TRANSLATOR", NULL, 2)));
            KWD_WALK_WARN_ABOUT_MISSING_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("WARN-ABOUT-MISSING-METHODS", NULL, 2)));
            KWD_WALK_USE_HARDCODED_SYMBOLS = ((Keyword*)(intern_rigid_symbol_wrt_module("USE-HARDCODED-SYMBOLS", NULL, 2)));
            KWD_WALK_USE_COMMON_LISP_STRUCTS = ((Keyword*)(intern_rigid_symbol_wrt_module("USE-COMMON-LISP-STRUCTS", NULL, 2)));
            KWD_WALK_USE_COMMON_LISP_VECTOR_STRUCTS = ((Keyword*)(intern_rigid_symbol_wrt_module("USE-COMMON-LISP-VECTOR-STRUCTS", NULL, 2)));
            KWD_WALK_USE_CPP_GARBAGE_COLLECTOR = ((Keyword*)(intern_rigid_symbol_wrt_module("USE-CPP-GARBAGE-COLLECTOR", NULL, 2)));
            KWD_WALK_TRANSLATE_WITH_COPYRIGHT_HEADER = ((Keyword*)(intern_rigid_symbol_wrt_module("TRANSLATE-WITH-COPYRIGHT-HEADER", NULL, 2)));
            SYM_WALK_WHEN = ((Symbol*)(intern_rigid_symbol_wrt_module("WHEN", NULL, 0)));
            SYM_WALK_AND = ((Symbol*)(intern_rigid_symbol_wrt_module("AND", NULL, 0)));
            SYM_WALK_DEFINEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINED?", NULL, 0)));
            SYM_WALK_oTRACED_KEYWORDSo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TRACED-KEYWORDS*", NULL, 0)));
            SYM_WALK_MEMBERp = ((Symbol*)(intern_rigid_symbol_wrt_module("MEMBER?", NULL, 0)));
            SYM_WALK_PRINT = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT", NULL, 0)));
            SYM_WALK_TRACE_IF = ((Symbol*)(intern_rigid_symbol_wrt_module("TRACE-IF", NULL, 0)));
            SYM_WALK_TRACE_IF_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("TRACE-IF-EXPANDER", NULL, 0)));
            SYM_WALK_EVALUATOR_WRAPPER_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("EVALUATOR-WRAPPER-CODE", NULL, 0)));
            SYM_WALK_THE_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-OBJECT", NULL, 0)));
            SYM_WALK_CATEGORY = ((Symbol*)(intern_rigid_symbol_wrt_module("CATEGORY", NULL, 0)));
            SYM_WALK_ANNOTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("ANNOTATION", NULL, 0)));
            SYM_WALK_AUXILIARYp = ((Symbol*)(intern_rigid_symbol_wrt_module("AUXILIARY?", NULL, 0)));
            SYM_WALK_CODE_REGISTER = ((Symbol*)(intern_rigid_symbol_wrt_module("CODE-REGISTER", NULL, 0)));
            SYM_WALK_TRANSLATION = ((Symbol*)(intern_rigid_symbol_wrt_module("TRANSLATION", NULL, 0)));
            SYM_WALK_REFERENCED_GLOBALS = ((Symbol*)(intern_rigid_symbol_wrt_module("REFERENCED-GLOBALS", NULL, 0)));
            SGT_WALK_TRANSLATION_UNIT = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSLATION-UNIT", NULL, 1)));
            SYM_WALK_CLASS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS", NULL, 0)));
            SYM_WALK_METHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD", NULL, 0)));
            SYM_WALK_MACRO = ((Symbol*)(intern_rigid_symbol_wrt_module("MACRO", NULL, 0)));
            SYM_WALK_GLOBAL_VARIABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("GLOBAL-VARIABLE", NULL, 0)));
            SYM_WALK_oTRANSLATIONUNITSo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TRANSLATIONUNITS*", NULL, 0)));
            SYM_WALK_oCURRENTTRANSLATIONUNITo = ((Symbol*)(intern_rigid_symbol_wrt_module("*CURRENTTRANSLATIONUNIT*", NULL, 0)));
            SYM_WALK_oTRANSLATIONPHASEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TRANSLATIONPHASE*", NULL, 0)));
            SYM_WALK_oTRANSLATIONVERBOSITYLEVELo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TRANSLATIONVERBOSITYLEVEL*", NULL, 0)));
            SYM_WALK_oUSEHARDCODEDSYMBOLSpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*USEHARDCODEDSYMBOLS?*", NULL, 0)));
            KWD_WALK_REAL = ((Keyword*)(intern_rigid_symbol_wrt_module("REAL", NULL, 2)));
            KWD_WALK_BOOTSTRAP = ((Keyword*)(intern_rigid_symbol_wrt_module("BOOTSTRAP", NULL, 2)));
            KWD_WALK_COMMON_LISP = ((Keyword*)(intern_rigid_symbol_wrt_module("COMMON-LISP", NULL, 2)));
            KWD_WALK_JAVA = ((Keyword*)(intern_rigid_symbol_wrt_module("JAVA", NULL, 2)));
            KWD_WALK_CPP = ((Keyword*)(intern_rigid_symbol_wrt_module("CPP", NULL, 2)));
            SYM_WALK_PROGN = ((Symbol*)(intern_rigid_symbol_wrt_module("PROGN", NULL, 0)));
            SYM_WALK_DEFCLASS = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFCLASS", NULL, 0)));
            SYM_WALK_DEFSLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFSLOT", NULL, 0)));
            SYM_WALK_DEFMETHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFMETHOD", NULL, 0)));
            SYM_WALK_DEFUN = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFUN", NULL, 0)));
            SYM_WALK_DEFOPERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFOPERATOR", NULL, 0)));
            SYM_WALK_DEFGLOBAL = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFGLOBAL", NULL, 0)));
            SYM_WALK_DEFSPECIAL = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFSPECIAL", NULL, 0)));
            SYM_WALK_DEFCONSTANT = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFCONSTANT", NULL, 0)));
            SYM_WALK_DEFTYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFTYPE", NULL, 0)));
            SYM_WALK_DEFMODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFMODULE", NULL, 0)));
            SYM_WALK_DEFMACRO = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFMACRO", NULL, 0)));
            SYM_WALK_STARTUP_TIME_PROGN = ((Symbol*)(intern_rigid_symbol_wrt_module("STARTUP-TIME-PROGN", NULL, 0)));
            SYM_WALK_VERBATIM = ((Symbol*)(intern_rigid_symbol_wrt_module("VERBATIM", NULL, 0)));
            SYM_WALK_MODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("MODULE", NULL, 0)));
            SYM_WALK_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPE", NULL, 0)));
            SYM_WALK_PRINT_METHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-METHOD", NULL, 0)));
            SYM_WALK_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT", NULL, 0)));
            KWD_WALK_IDL = ((Keyword*)(intern_rigid_symbol_wrt_module("IDL", NULL, 2)));
            KWD_WALK_CPP_STANDALONE = ((Keyword*)(intern_rigid_symbol_wrt_module("CPP-STANDALONE", NULL, 2)));
            SYM_WALK_oLOCALVARIABLETYPETABLEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*LOCALVARIABLETYPETABLE*", NULL, 0)));
            SYM_WALK_oMETHODBEINGWALKEDo = ((Symbol*)(intern_rigid_symbol_wrt_module("*METHODBEINGWALKED*", NULL, 0)));
            SYM_WALK_oFOUNDRETURNpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*FOUNDRETURN?*", NULL, 0)));
            SGT_WALK_VOID = ((Surrogate*)(intern_rigid_symbol_wrt_module("VOID", NULL, 1)));
            SYM_WALK_oTARGETTYPEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TARGETTYPE*", NULL, 0)));
            SYM_WALK_oLOCALGENSYMTABLEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*LOCALGENSYMTABLE*", NULL, 0)));
            SYM_WALK_oTRANSLATIONERRORSo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TRANSLATIONERRORS*", NULL, 0)));
            SYM_WALK_oTRANSLATIONWARNINGSo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TRANSLATIONWARNINGS*", NULL, 0)));
            SYM_WALK_oIGNORETRANSLATIONERRORSpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*IGNORETRANSLATIONERRORS?*", NULL, 0)));
            KWD_WALK_DEFINE = ((Keyword*)(intern_rigid_symbol_wrt_module("DEFINE", NULL, 2)));
            KWD_WALK_FINALIZE = ((Keyword*)(intern_rigid_symbol_wrt_module("FINALIZE", NULL, 2)));
            KWD_WALK_WALK = ((Keyword*)(intern_rigid_symbol_wrt_module("WALK", NULL, 2)));
            KWD_WALK_TRANSLATE = ((Keyword*)(intern_rigid_symbol_wrt_module("TRANSLATE", NULL, 2)));
            SGT_WALK_GLOBAL_VARIABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("GLOBAL-VARIABLE", NULL, 1)));
            SGT_WALK_TYPE_SPEC = ((Surrogate*)(intern_rigid_symbol_wrt_module("TYPE-SPEC", NULL, 1)));
            SGT_WALK_MODULE = ((Surrogate*)(intern_rigid_symbol_wrt_module("MODULE", NULL, 1)));
            SGT_WALK_UNINITIALIZED = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNINITIALIZED", NULL, 1)));
            SGT_WALK_UNKNOWN = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNKNOWN", NULL, 1)));
            SYM_WALK_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", NULL, 0)));
            SYM_WALK_ERROR = ((Symbol*)(intern_rigid_symbol_wrt_module("ERROR", NULL, 0)));
            SYM_WALK_EOL = ((Symbol*)(intern_rigid_symbol_wrt_module("EOL", NULL, 0)));
            SYM_WALK_ILLEGAL_EXPRESSION_FLAGGED_BY_THE_TRANSLATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("ILLEGAL-EXPRESSION-FLAGGED-BY-THE-TRANSLATOR", NULL, 0)));
            SYM_WALK_BAD_SYS = ((Symbol*)(intern_rigid_symbol_wrt_module("BAD-SYS", NULL, 0)));
            SGT_WALK_INTEGER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("INTEGER-WRAPPER", NULL, 1)));
            SGT_WALK_INTEGER = ((Surrogate*)(intern_rigid_symbol_wrt_module("INTEGER", NULL, 1)));
            SGT_WALK_TRANSIENT_INTEGER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-INTEGER-WRAPPER", NULL, 1)));
            SGT_WALK_FLOAT_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("FLOAT-WRAPPER", NULL, 1)));
            SGT_WALK_FLOAT = ((Surrogate*)(intern_rigid_symbol_wrt_module("FLOAT", NULL, 1)));
            SGT_WALK_TRANSIENT_FLOAT_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-FLOAT-WRAPPER", NULL, 1)));
            SGT_WALK_NUMBER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("NUMBER-WRAPPER", NULL, 1)));
            SGT_WALK_NUMBER = ((Surrogate*)(intern_rigid_symbol_wrt_module("NUMBER", NULL, 1)));
            SGT_WALK_STRING_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("STRING-WRAPPER", NULL, 1)));
            SGT_WALK_STRING = ((Surrogate*)(intern_rigid_symbol_wrt_module("STRING", NULL, 1)));
            SGT_WALK_TRANSIENT_STRING_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-STRING-WRAPPER", NULL, 1)));
            SGT_WALK_CHARACTER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("CHARACTER-WRAPPER", NULL, 1)));
            SGT_WALK_CHARACTER = ((Surrogate*)(intern_rigid_symbol_wrt_module("CHARACTER", NULL, 1)));
            SGT_WALK_TRANSIENT_CHARACTER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-CHARACTER-WRAPPER", NULL, 1)));
            SGT_WALK_BOOLEAN_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN-WRAPPER", NULL, 1)));
            SGT_WALK_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", NULL, 1)));
            SGT_WALK_FUNCTION_CODE_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("FUNCTION-CODE-WRAPPER", NULL, 1)));
            SGT_WALK_FUNCTION_CODE = ((Surrogate*)(intern_rigid_symbol_wrt_module("FUNCTION-CODE", NULL, 1)));
            SGT_WALK_TRANSIENT_FUNCTION_CODE_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-FUNCTION-CODE-WRAPPER", NULL, 1)));
            SGT_WALK_METHOD_CODE_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("METHOD-CODE-WRAPPER", NULL, 1)));
            SGT_WALK_METHOD_CODE = ((Surrogate*)(intern_rigid_symbol_wrt_module("METHOD-CODE", NULL, 1)));
            SGT_WALK_TRANSIENT_METHOD_CODE_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-METHOD-CODE-WRAPPER", NULL, 1)));
            SGT_WALK_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("OBJECT", NULL, 1)));
            SYM_WALK_WRAP_BOOLEAN = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-BOOLEAN", NULL, 0)));
            SYM_WALK_WRAP_LITERAL = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-LITERAL", NULL, 0)));
            SYM_WALK_INTEGER_TO_BOOLEAN_WRAPPER = ((Symbol*)(intern_rigid_symbol_wrt_module("INTEGER-TO-BOOLEAN-WRAPPER", NULL, 0)));
            SYM_WALK_INTEGER_TO_BOOLEAN = ((Symbol*)(intern_rigid_symbol_wrt_module("INTEGER-TO-BOOLEAN", NULL, 0)));
            SGT_WALK_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("SYMBOL", NULL, 1)));
            SYM_WALK_INTERN_SYMBOL = ((Symbol*)(intern_rigid_symbol_wrt_module("INTERN-SYMBOL", NULL, 0)));
            SYM_WALK_SYMBOL_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SYMBOL-NAME", NULL, 0)));
            SYM_WALK_WRAPPER_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAPPER-VALUE", NULL, 0)));
            SGT_WALK_SURROGATE = ((Surrogate*)(intern_rigid_symbol_wrt_module("SURROGATE", NULL, 1)));
            SGT_WALK_CLASS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CLASS", NULL, 1)));
            SYM_WALK_SURROGATE_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE-VALUE", NULL, 0)));
            SGT_WALK_INPUT_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("INPUT-STREAM", NULL, 1)));
            SGT_WALK_NATIVE_INPUT_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("NATIVE-INPUT-STREAM", NULL, 1)));
            SYM_WALK_NATIVE_STREAM = ((Symbol*)(intern_rigid_symbol_wrt_module("NATIVE-STREAM", NULL, 0)));
            SGT_WALK_OUTPUT_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("OUTPUT-STREAM", NULL, 1)));
            SGT_WALK_NATIVE_OUTPUT_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("NATIVE-OUTPUT-STREAM", NULL, 1)));
            SYM_WALK_IDENTITY = ((Symbol*)(intern_rigid_symbol_wrt_module("IDENTITY", NULL, 0)));
            SGT_WALK_SINGLE_FLOAT = ((Surrogate*)(intern_rigid_symbol_wrt_module("SINGLE-FLOAT", NULL, 1)));
            SGT_WALK_DOUBLE_FLOAT = ((Surrogate*)(intern_rigid_symbol_wrt_module("DOUBLE-FLOAT", NULL, 1)));
            SGT_WALK_SHORT_INTEGER = ((Surrogate*)(intern_rigid_symbol_wrt_module("SHORT-INTEGER", NULL, 1)));
            SGT_WALK_LONG_INTEGER = ((Surrogate*)(intern_rigid_symbol_wrt_module("LONG-INTEGER", NULL, 1)));
            SGT_WALK_UNSIGNED_SHORT_INTEGER = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNSIGNED-SHORT-INTEGER", NULL, 1)));
            SGT_WALK_UNSIGNED_LONG_INTEGER = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNSIGNED-LONG-INTEGER", NULL, 1)));
            SYM_WALK_VRLET = ((Symbol*)(intern_rigid_symbol_wrt_module("VRLET", NULL, 0)));
            SYM_WALK_SYS_CALL_METHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-CALL-METHOD", NULL, 0)));
            SYM_WALK_SYS_CALL_FUNCTION = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-CALL-FUNCTION", NULL, 0)));
            SYM_WALK_SAFE_CAST = ((Symbol*)(intern_rigid_symbol_wrt_module("SAFE-CAST", NULL, 0)));
            SYM_WALK_CAST = ((Symbol*)(intern_rigid_symbol_wrt_module("CAST", NULL, 0)));
            SGT_WALK_NON_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("NON-OBJECT", NULL, 1)));
            SGT_WALK_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("WRAPPER", NULL, 1)));
            SYM_WALK_LET = ((Symbol*)(intern_rigid_symbol_wrt_module("LET", NULL, 0)));
            SYM_WALK_VOID_SYS = ((Symbol*)(intern_rigid_symbol_wrt_module("VOID-SYS", NULL, 0)));
            SYM_WALK_TYPED_SYS = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPED-SYS", NULL, 0)));
            SYM_WALK_SLOT_TYPE_SPECIFIER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-TYPE-SPECIFIER", NULL, 0)));
            SGT_WALK_CONS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONS", NULL, 1)));
            SYM_WALK_SYS_FOREACH = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-FOREACH", NULL, 0)));
            SYM_WALK_SETQ = ((Symbol*)(intern_rigid_symbol_wrt_module("SETQ", NULL, 0)));
            SYM_WALK_SETF = ((Symbol*)(intern_rigid_symbol_wrt_module("SETF", NULL, 0)));
            SYM_WALK_SLOT_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-VALUE", NULL, 0)));
            SYM_WALK_SLOT_VALUE_SETTER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-VALUE-SETTER", NULL, 0)));
            SYM_WALK_LOOP = ((Symbol*)(intern_rigid_symbol_wrt_module("LOOP", NULL, 0)));
            SYM_WALK_VALUES = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUES", NULL, 0)));
            SYM_WALK_SPECIAL = ((Symbol*)(intern_rigid_symbol_wrt_module("SPECIAL", NULL, 0)));
            SYM_WALK_SYS_SPECIAL = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-SPECIAL", NULL, 0)));
            SYM_WALK_RETURN = ((Symbol*)(intern_rigid_symbol_wrt_module("RETURN", NULL, 0)));
            SYM_WALK_MV_SETQ = ((Symbol*)(intern_rigid_symbol_wrt_module("MV-SETQ", NULL, 0)));
            SYM_WALK_MV_BIND = ((Symbol*)(intern_rigid_symbol_wrt_module("MV-BIND", NULL, 0)));
            SYM_WALK_BREAK = ((Symbol*)(intern_rigid_symbol_wrt_module("BREAK", NULL, 0)));
            SYM_WALK_CONTINUE = ((Symbol*)(intern_rigid_symbol_wrt_module("CONTINUE", NULL, 0)));
            SYM_WALK_WHILE = ((Symbol*)(intern_rigid_symbol_wrt_module("WHILE", NULL, 0)));
            SYM_WALK_FOREACH = ((Symbol*)(intern_rigid_symbol_wrt_module("FOREACH", NULL, 0)));
            SYM_WALK_EXISTS = ((Symbol*)(intern_rigid_symbol_wrt_module("EXISTS", NULL, 0)));
            SYM_WALK_FORALL = ((Symbol*)(intern_rigid_symbol_wrt_module("FORALL", NULL, 0)));
            SYM_WALK_SOME = ((Symbol*)(intern_rigid_symbol_wrt_module("SOME", NULL, 0)));
            SYM_WALK_SETOF = ((Symbol*)(intern_rigid_symbol_wrt_module("SETOF", NULL, 0)));
            SYM_WALK_SET_OF = ((Symbol*)(intern_rigid_symbol_wrt_module("SET-OF", NULL, 0)));
            SYM_WALK_SELECT = ((Symbol*)(intern_rigid_symbol_wrt_module("SELECT", NULL, 0)));
            SYM_WALK_IF = ((Symbol*)(intern_rigid_symbol_wrt_module("IF", NULL, 0)));
            SYM_WALK_UNLESS = ((Symbol*)(intern_rigid_symbol_wrt_module("UNLESS", NULL, 0)));
            SYM_WALK_CHOOSE = ((Symbol*)(intern_rigid_symbol_wrt_module("CHOOSE", NULL, 0)));
            SYM_WALK_OR = ((Symbol*)(intern_rigid_symbol_wrt_module("OR", NULL, 0)));
            SYM_WALK_NOT = ((Symbol*)(intern_rigid_symbol_wrt_module("NOT", NULL, 0)));
            SYM_WALK_COND = ((Symbol*)(intern_rigid_symbol_wrt_module("COND", NULL, 0)));
            SYM_WALK_CASE = ((Symbol*)(intern_rigid_symbol_wrt_module("CASE", NULL, 0)));
            SYM_WALK_TYPECASE = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPECASE", NULL, 0)));
            SYM_WALK_EQp = ((Symbol*)(intern_rigid_symbol_wrt_module("EQ?", NULL, 0)));
            SYM_WALK_EQLp = ((Symbol*)(intern_rigid_symbol_wrt_module("EQL?", NULL, 0)));
            SYM_WALK_e = ((Symbol*)(intern_rigid_symbol_wrt_module("=", NULL, 0)));
            SYM_WALK_i = ((Symbol*)(intern_rigid_symbol_wrt_module("+", NULL, 0)));
            SYM_WALK__ = ((Symbol*)(intern_rigid_symbol_wrt_module("-", NULL, 0)));
            SYM_WALK_o = ((Symbol*)(intern_rigid_symbol_wrt_module("*", NULL, 0)));
            SYM_WALK_s = ((Symbol*)(intern_rigid_symbol_wrt_module("/", NULL, 0)));
            SYM_WALK_QUOTE = ((Symbol*)(intern_rigid_symbol_wrt_module("QUOTE", NULL, 0)));
            SYM_WALK_BQUOTE = ((Symbol*)(intern_rigid_symbol_wrt_module("BQUOTE", NULL, 0)));
            SYM_WALK_PRINT_STREAM = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-STREAM", NULL, 0)));
            SYM_WALK_PRINT_NATIVE_STREAM = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-NATIVE-STREAM", NULL, 0)));
            SYM_WALK_NEW = ((Symbol*)(intern_rigid_symbol_wrt_module("NEW", NULL, 0)));
            SYM_WALK_ALLOCATE = ((Symbol*)(intern_rigid_symbol_wrt_module("ALLOCATE", NULL, 0)));
            SYM_WALK_LOCAL_NEW = ((Symbol*)(intern_rigid_symbol_wrt_module("LOCAL-NEW", NULL, 0)));
            SYM_WALK_MAKE = ((Symbol*)(intern_rigid_symbol_wrt_module("MAKE", NULL, 0)));
            SYM_WALK_FUNCALL = ((Symbol*)(intern_rigid_symbol_wrt_module("FUNCALL", NULL, 0)));
            SYM_WALK_SYS_CALL_FUNCTION_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-CALL-FUNCTION-CODE", NULL, 0)));
            SYM_WALK_SYS_CALL_METHOD_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-CALL-METHOD-CODE", NULL, 0)));
            SYM_WALK_THE_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-CODE", NULL, 0)));
            SYM_WALK_EXCEPTION_CASE = ((Symbol*)(intern_rigid_symbol_wrt_module("EXCEPTION-CASE", NULL, 0)));
            SYM_WALK_INLINE = ((Symbol*)(intern_rigid_symbol_wrt_module("INLINE", NULL, 0)));
            SYM_WALK_SYS_SLOT_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-SLOT-VALUE", NULL, 0)));
            SYM_WALK_SYS_SLOT_VALUE_SETTER = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-SLOT-VALUE-SETTER", NULL, 0)));
            SYM_WALK_SYS_CALL_METHOD_SETTER = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-CALL-METHOD-SETTER", NULL, 0)));
            SYM_WALK_SYS_NEW = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-NEW", NULL, 0)));
            SYM_WALK_oCURRENTFILEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*CURRENTFILE*", NULL, 0)));
            KWD_WALK_SYMBOLS = ((Keyword*)(intern_rigid_symbol_wrt_module("SYMBOLS", NULL, 2)));
            SYM_WALK_INTERN_RIGID_SYMBOL_WRT_MODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("INTERN-RIGID-SYMBOL-WRT-MODULE", NULL, 0)));
            SYM_WALK_GET_MODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-MODULE", NULL, 0)));
            SYM_WALK_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            SYM_WALK_INTERN_SYMBOL_AT = ((Symbol*)(intern_rigid_symbol_wrt_module("INTERN-SYMBOL-AT", NULL, 0)));
            SYM_WALK_INTERN_SURROGATE_AT = ((Symbol*)(intern_rigid_symbol_wrt_module("INTERN-SURROGATE-AT", NULL, 0)));
            SYM_WALK_INTERN_KEYWORD_AT = ((Symbol*)(intern_rigid_symbol_wrt_module("INTERN-KEYWORD-AT", NULL, 0)));
            SYM_WALK_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", NULL, 0)));
            SYM_WALK_NIL = ((Symbol*)(intern_rigid_symbol_wrt_module("NIL", NULL, 0)));
            SYM_WALK_NULL_BOOLEAN = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-BOOLEAN", NULL, 0)));
            SYM_WALK_NULL_INTEGER = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-INTEGER", NULL, 0)));
            SYM_WALK_NULL_FLOAT = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-FLOAT", NULL, 0)));
            SGT_WALK_KEYWORD = ((Surrogate*)(intern_rigid_symbol_wrt_module("KEYWORD", NULL, 1)));
            KWD_WALK_PLACE_WHERE_VRLET_WAS = ((Keyword*)(intern_rigid_symbol_wrt_module("PLACE-WHERE-VRLET-WAS", NULL, 2)));
            KWD_WALK_PLACE_WHERE_LAST_EXPRESSION_WAS = ((Keyword*)(intern_rigid_symbol_wrt_module("PLACE-WHERE-LAST-EXPRESSION-WAS", NULL, 2)));
            KWD_WALK_DYNAMIC = ((Keyword*)(intern_rigid_symbol_wrt_module("DYNAMIC", NULL, 2)));
            SYM_WALK_IT = ((Symbol*)(intern_rigid_symbol_wrt_module("IT", NULL, 0)));
            SYM_WALK_ON = ((Symbol*)(intern_rigid_symbol_wrt_module("ON", NULL, 0)));
            SYM_WALK_DYNAMIC_SLOTS = ((Symbol*)(intern_rigid_symbol_wrt_module("DYNAMIC-SLOTS", NULL, 0)));
            SYM_WALK_WHERE = ((Symbol*)(intern_rigid_symbol_wrt_module("WHERE", NULL, 0)));
            SYM_WALK_KEY = ((Symbol*)(intern_rigid_symbol_wrt_module("KEY", NULL, 0)));
            SYM_WALK_DO = ((Symbol*)(intern_rigid_symbol_wrt_module("DO", NULL, 0)));
            SYM_WALK_WRAPPEDVALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAPPEDVALUE", NULL, 0)));
            SYM_WALK_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE", NULL, 0)));
            KWD_WALK_BIT = ((Keyword*)(intern_rigid_symbol_wrt_module("BIT", NULL, 2)));
            SYM_WALK_DYNAMICSLOTS = ((Symbol*)(intern_rigid_symbol_wrt_module("DYNAMICSLOTS", NULL, 0)));
            SYM_WALK_NEWVALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("NEWVALUE", NULL, 0)));
            SYM_WALK_FOUNDMATCHINGENTRYp = ((Symbol*)(intern_rigid_symbol_wrt_module("FOUNDMATCHINGENTRY?", NULL, 0)));
            SYM_WALK_THE_KV_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-KV-LIST", NULL, 0)));
            SYM_WALK_KV_CONS = ((Symbol*)(intern_rigid_symbol_wrt_module("KV-CONS", NULL, 0)));
            SYM_WALK_OLDVALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("OLDVALUE", NULL, 0)));
            KWD_WALK_CONTEXT_SENSITIVEp = ((Keyword*)(intern_rigid_symbol_wrt_module("CONTEXT-SENSITIVE?", NULL, 2)));
            KWD_WALK_DONT_INHERITp = ((Keyword*)(intern_rigid_symbol_wrt_module("DONT-INHERIT?", NULL, 2)));
            SYM_WALK_ACCESS_IN_CONTEXT = ((Symbol*)(intern_rigid_symbol_wrt_module("ACCESS-IN-CONTEXT", NULL, 0)));
            KWD_WALK_COPY_TO_CHILDRENp = ((Keyword*)(intern_rigid_symbol_wrt_module("COPY-TO-CHILDREN?", NULL, 2)));
            SYM_WALK_UPDATE_IN_CONTEXT = ((Symbol*)(intern_rigid_symbol_wrt_module("UPDATE-IN-CONTEXT", NULL, 0)));
            SYM_WALK_CS_VALUEp = ((Symbol*)(intern_rigid_symbol_wrt_module("CS-VALUE?", NULL, 0)));
            SYM_WALK_VARIABLE_DECLARATION = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-DECLARATION", NULL, 0)));
            SYM_WALK_ILLEGAL_VARIABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("ILLEGAL-VARIABLE", NULL, 0)));
            SYM_WALK_oSPECIALVARIABLESTACKo = ((Symbol*)(intern_rigid_symbol_wrt_module("*SPECIALVARIABLESTACK*", NULL, 0)));
            SYM_WALK_oSPECIALSENABLEDpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*SPECIALSENABLED?*", NULL, 0)));
            SYM_WALK_oNOFSPECIALSATLOOPENTRYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*NOFSPECIALSATLOOPENTRY*", NULL, 0)));
            KWD_WALK_SAVE_AND_RESTORE = ((Keyword*)(intern_rigid_symbol_wrt_module("SAVE-AND-RESTORE", NULL, 2)));
            SYM_WALK_EXCEPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("EXCEPTION", NULL, 0)));
            SYM_WALK_RESIGNAL = ((Symbol*)(intern_rigid_symbol_wrt_module("RESIGNAL", NULL, 0)));
            SGT_WALK_METHOD_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("METHOD-SLOT", NULL, 1)));
            SYM_WALK_OTHERWISE = ((Symbol*)(intern_rigid_symbol_wrt_module("OTHERWISE", NULL, 0)));
            SYM_WALK_SYMBOL_ID = ((Symbol*)(intern_rigid_symbol_wrt_module("SYMBOL-ID", NULL, 0)));
            SYM_WALK_GENERALIZED_SYMBOL = ((Symbol*)(intern_rigid_symbol_wrt_module("GENERALIZED-SYMBOL", NULL, 0)));
            SYM_WALK_BOOLEANp = ((Symbol*)(intern_rigid_symbol_wrt_module("BOOLEAN?", NULL, 0)));
            SYM_WALK_INTEGERp = ((Symbol*)(intern_rigid_symbol_wrt_module("INTEGER?", NULL, 0)));
            SYM_WALK_FLOATp = ((Symbol*)(intern_rigid_symbol_wrt_module("FLOAT?", NULL, 0)));
            SYM_WALK_STRINGp = ((Symbol*)(intern_rigid_symbol_wrt_module("STRING?", NULL, 0)));
            SYM_WALK_CHARACTERp = ((Symbol*)(intern_rigid_symbol_wrt_module("CHARACTER?", NULL, 0)));
            SYM_WALK_WRAPPERp = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAPPER?", NULL, 0)));
            SGT_WALK_VERBATIM_STRING_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("VERBATIM-STRING-WRAPPER", NULL, 1)));
            SYM_WALK_VERBATIM_STRINGp = ((Symbol*)(intern_rigid_symbol_wrt_module("VERBATIM-STRING?", NULL, 0)));
            SYM_WALK_SURROGATEp = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE?", NULL, 0)));
            SGT_WALK_TYPE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TYPE", NULL, 1)));
            SYM_WALK_TYPEp = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPE?", NULL, 0)));
            SYM_WALK_SYMBOLp = ((Symbol*)(intern_rigid_symbol_wrt_module("SYMBOL?", NULL, 0)));
            SGT_WALK_TRANSIENT_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRANSIENT-SYMBOL", NULL, 1)));
            SYM_WALK_TRANSIENT_SYMBOLp = ((Symbol*)(intern_rigid_symbol_wrt_module("TRANSIENT-SYMBOL?", NULL, 0)));
            SYM_WALK_KEYWORDp = ((Symbol*)(intern_rigid_symbol_wrt_module("KEYWORD?", NULL, 0)));
            SYM_WALK_CONSp = ((Symbol*)(intern_rigid_symbol_wrt_module("CONS?", NULL, 0)));
            SYM_WALK_CLASSp = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS?", NULL, 0)));
            SGT_WALK_STORAGE_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT", NULL, 1)));
            SYM_WALK_STORAGE_SLOTp = ((Symbol*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT?", NULL, 0)));
            SYM_WALK_METHOD_SLOTp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-SLOT?", NULL, 0)));
            SGT_WALK_ANCHORED_TYPE_SPECIFIER = ((Surrogate*)(intern_rigid_symbol_wrt_module("ANCHORED-TYPE-SPECIFIER", NULL, 1)));
            SYM_WALK_ANCHORED_TYPE_SPECIFIERp = ((Symbol*)(intern_rigid_symbol_wrt_module("ANCHORED-TYPE-SPECIFIER?", NULL, 0)));
            SGT_WALK_PARAMETRIC_TYPE_SPECIFIER = ((Surrogate*)(intern_rigid_symbol_wrt_module("PARAMETRIC-TYPE-SPECIFIER", NULL, 1)));
            SYM_WALK_PARAMETRIC_TYPE_SPECIFIERp = ((Symbol*)(intern_rigid_symbol_wrt_module("PARAMETRIC-TYPE-SPECIFIER?", NULL, 0)));
            SYM_WALK_ISAp = ((Symbol*)(intern_rigid_symbol_wrt_module("ISA?", NULL, 0)));
            SYM_WALK_TAXONOMY_ISAp = ((Symbol*)(intern_rigid_symbol_wrt_module("TAXONOMY-ISA?", NULL, 0)));
            SYM_WALK_STRING_EQLp = ((Symbol*)(intern_rigid_symbol_wrt_module("STRING-EQL?", NULL, 0)));
            SGT_WALK_STANDARD_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("STANDARD-OBJECT", NULL, 1)));
            SGT_WALK_LITERAL = ((Surrogate*)(intern_rigid_symbol_wrt_module("LITERAL", NULL, 1)));
            SYM_WALK_EQL_TO_BOOLEANp = ((Symbol*)(intern_rigid_symbol_wrt_module("EQL-TO-BOOLEAN?", NULL, 0)));
            SYM_WALK_EQL_TO_INTEGERp = ((Symbol*)(intern_rigid_symbol_wrt_module("EQL-TO-INTEGER?", NULL, 0)));
            SYM_WALK_EQL_TO_FLOATp = ((Symbol*)(intern_rigid_symbol_wrt_module("EQL-TO-FLOAT?", NULL, 0)));
            SYM_WALK_EQL_TO_STRINGp = ((Symbol*)(intern_rigid_symbol_wrt_module("EQL-TO-STRING?", NULL, 0)));
            SYM_WALK_GET_QUOTED_TREE = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-QUOTED-TREE", NULL, 0)));
            KWD_WALK_WARN = ((Keyword*)(intern_rigid_symbol_wrt_module("WARN", NULL, 2)));
            KWD_WALK_ERROR = ((Keyword*)(intern_rigid_symbol_wrt_module("ERROR", NULL, 2)));
            KWD_WALK_CONTINUABLE_ERROR = ((Keyword*)(intern_rigid_symbol_wrt_module("CONTINUABLE-ERROR", NULL, 2)));
            SYM_WALK_CONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CONS", NULL, 0)));
            SYM_WALK_CONS_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("CONS-LIST", NULL, 0)));
            SYM_WALK_GET_SYM = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-SYM", NULL, 0)));
            SYM_WALK_GET_SGT = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-SGT", NULL, 0)));
            SYM_WALK_GET_KWD = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-KWD", NULL, 0)));
            SGT_WALK_ARGUMENT_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("ARGUMENT-LIST", NULL, 1)));
            SYM_WALK_ANY_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("ANY-VALUE", NULL, 0)));
            SYM_WALK_METHOD_INHERITS_THROUGH = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-INHERITS-THROUGH", NULL, 0)));
            KWD_WALK_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            SYM_WALK_SLOT_WRITER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-WRITER", NULL, 0)));
            SYM_WALK_LOOKUP_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("LOOKUP-SLOT", NULL, 0)));
            SYM_WALK_TYPE_CLASS = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPE-CLASS", NULL, 0)));
            SYM_WALK_STORAGE_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT", NULL, 0)));
            KWD_WALK_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("METHODS", NULL, 2)));
            SYM_WALK_FUNCTION_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("FUNCTION-CODE", NULL, 0)));
            SYM_WALK_METHOD_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-CODE", NULL, 0)));
            KWD_WALK_METHOD = ((Keyword*)(intern_rigid_symbol_wrt_module("METHOD", NULL, 2)));
            KWD_WALK_CLASS = ((Keyword*)(intern_rigid_symbol_wrt_module("CLASS", NULL, 2)));
            KWD_WALK_EMBEDDED = ((Keyword*)(intern_rigid_symbol_wrt_module("EMBEDDED", NULL, 2)));
            SYM_WALK_CLASS_CONSTRUCTOR_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CONSTRUCTOR-CODE", NULL, 0)));
            SYM_WALK_SLOT_ACCESSOR_METHODS = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-ACCESSOR-METHODS", NULL, 0)));
            SYM_WALK_PRINT_FORM = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-FORM", NULL, 0)));
            SYM_WALK_PRINT_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-OBJECT", NULL, 0)));
            SYM_WALK_SELF = ((Symbol*)(intern_rigid_symbol_wrt_module("SELF", NULL, 0)));
            SYM_WALK_STREAM = ((Symbol*)(intern_rigid_symbol_wrt_module("STREAM", NULL, 0)));
            SYM_WALK_NATIVE_OUTPUT_STREAM = ((Symbol*)(intern_rigid_symbol_wrt_module("NATIVE-OUTPUT-STREAM", NULL, 0)));
            KWD_WALK_CLASSES = ((Keyword*)(intern_rigid_symbol_wrt_module("CLASSES", NULL, 2)));
            KWD_WALK_FINALIZE_CLASSES = ((Keyword*)(intern_rigid_symbol_wrt_module("FINALIZE-CLASSES", NULL, 2)));
            SYM_WALK_FINALIZE_CLASSES = ((Symbol*)(intern_rigid_symbol_wrt_module("FINALIZE-CLASSES", NULL, 0)));
            KWD_WALK_FINALIZE_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("FINALIZE-METHODS", NULL, 2)));
            SYM_WALK_FINALIZE_SLOTS = ((Symbol*)(intern_rigid_symbol_wrt_module("FINALIZE-SLOTS", NULL, 0)));
            SYM_WALK_CLEANUP_UNFINALIZED_CLASSES = ((Symbol*)(intern_rigid_symbol_wrt_module("CLEANUP-UNFINALIZED-CLASSES", NULL, 0)));
            SYM_WALK_DEFINE_EXTERNAL_SLOT_FROM_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINE-EXTERNAL-SLOT-FROM-STRINGIFIED-SOURCE", NULL, 0)));
            SYM_WALK_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("OBJECT", NULL, 0)));
            SYM_WALK_METHOD_LISP_MACROp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-LISP-MACRO?", NULL, 0)));
            SYM_WALK_STORE_MACRO = ((Symbol*)(intern_rigid_symbol_wrt_module("STORE-MACRO", NULL, 0)));
            KWD_WALK_UNBOUND_SPECIAL_VARIABLE = ((Keyword*)(intern_rigid_symbol_wrt_module("UNBOUND-SPECIAL-VARIABLE", NULL, 2)));
            KWD_WALK_GLOBALS = ((Keyword*)(intern_rigid_symbol_wrt_module("GLOBALS", NULL, 2)));
            SYM_WALK_VARIABLE_TYPE_SPECIFIER = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-TYPE-SPECIFIER", NULL, 0)));
            SYM_WALK_DEFINE_STELLA_GLOBAL_VARIABLE_FROM_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINE-STELLA-GLOBAL-VARIABLE-FROM-STRINGIFIED-SOURCE", NULL, 0)));
            SYM_WALK_GLOBAL = ((Symbol*)(intern_rigid_symbol_wrt_module("GLOBAL", NULL, 0)));
            SYM_WALK_LOOKUP_GLOBAL_VARIABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("LOOKUP-GLOBAL-VARIABLE", NULL, 0)));
            SYM_WALK_VARIABLE_GET_VALUE_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-GET-VALUE-CODE", NULL, 0)));
            SYM_WALK_VARIABLE_SET_VALUE_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-SET-VALUE-CODE", NULL, 0)));
            SYM_WALK_DEFINE_STELLA_TYPE_FROM_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINE-STELLA-TYPE-FROM-STRINGIFIED-SOURCE", NULL, 0)));
            KWD_WALK_FINAL = ((Keyword*)(intern_rigid_symbol_wrt_module("FINAL", NULL, 2)));
            SYM_WALK_CURRENT_STARTUP_TIME_PHASEp = ((Symbol*)(intern_rigid_symbol_wrt_module("CURRENT-STARTUP-TIME-PHASE?", NULL, 0)));
            KWD_WALK_MODULES = ((Keyword*)(intern_rigid_symbol_wrt_module("MODULES", NULL, 2)));
            SYM_WALK_WITHIN_MODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("WITHIN-MODULE", NULL, 0)));
            SYM_WALK_oSTELLA_MODULEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*STELLA-MODULE*", NULL, 0)));
            KWD_WALK_AUXILIARYp = ((Keyword*)(intern_rigid_symbol_wrt_module("AUXILIARY?", NULL, 2)));
            SYM_WALK_oPENDINGEXCEPTIONHANDLERpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PENDINGEXCEPTIONHANDLER?*", NULL, 0)));
            SYM_WALK_oEXCEPTIONHANDLERADDRESSo = ((Symbol*)(intern_rigid_symbol_wrt_module("*EXCEPTIONHANDLERADDRESS*", NULL, 0)));
            SYM_WALK_oEXCEPTIONo = ((Symbol*)(intern_rigid_symbol_wrt_module("*EXCEPTION*", NULL, 0)));
            SYM_WALK_SETUP_LONG_JUMPp = ((Symbol*)(intern_rigid_symbol_wrt_module("SETUP-LONG-JUMP?", NULL, 0)));
            SGT_WALK_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("EXCEPTION", NULL, 1)));
            SYM_WALK_SUBTYPE_OFp = ((Symbol*)(intern_rigid_symbol_wrt_module("SUBTYPE-OF?", NULL, 0)));
            SYM_WALK_oEXCEPTION_TYPEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*EXCEPTION-TYPE*", NULL, 0)));
            KWD_WALK_OTHERWISE = ((Keyword*)(intern_rigid_symbol_wrt_module("OTHERWISE", NULL, 2)));
            SGT_WALK_CODE = ((Surrogate*)(intern_rigid_symbol_wrt_module("CODE", NULL, 1)));
            SYM_WALK_MAIN = ((Symbol*)(intern_rigid_symbol_wrt_module("MAIN", NULL, 0)));
            SGT_WALK_COMPOUND_TYPE_SPECIFIER = ((Surrogate*)(intern_rigid_symbol_wrt_module("COMPOUND-TYPE-SPECIFIER", NULL, 1)));
            SYM_WALK_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 0)));
            SYM_WALK_EXPRESSION = ((Symbol*)(intern_rigid_symbol_wrt_module("EXPRESSION", NULL, 0)));
            SYM_WALK_IGNORE = ((Symbol*)(intern_rigid_symbol_wrt_module("IGNORE", NULL, 0)));
            SYM_WALK_INCREMENTALLY_TRANSLATE = ((Symbol*)(intern_rigid_symbol_wrt_module("INCREMENTALLY-TRANSLATE", NULL, 0)));
            SYM_WALK_REGISTER_NATIVE_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("REGISTER-NATIVE-NAME", NULL, 0)));
            SYM_WALK_REST = ((Symbol*)(intern_rigid_symbol_wrt_module("REST", NULL, 0)));
            SYM_WALK_NTH_REST = ((Symbol*)(intern_rigid_symbol_wrt_module("NTH-REST", NULL, 0)));
            SYM_WALK_NTH = ((Symbol*)(intern_rigid_symbol_wrt_module("NTH", NULL, 0)));
            SYM_WALK_ARGUMENTS = ((Symbol*)(intern_rigid_symbol_wrt_module("ARGUMENTS", NULL, 0)));
            SYM_WALK_RESULT = ((Symbol*)(intern_rigid_symbol_wrt_module("RESULT", NULL, 0)));
            SYM_WALK_METHOD_EVALUATE_ARGUMENTSp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-EVALUATE-ARGUMENTS?", NULL, 0)));
            SYM_WALK_METHOD_VARIABLE_ARGUMENTSp = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD-VARIABLE-ARGUMENTS?", NULL, 0)));
            SYM_WALK_oEVALUATIONERRORpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*EVALUATIONERROR?*", NULL, 0)));
            SYM_WALK_oEVALUATIONTREEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*EVALUATIONTREE*", NULL, 0)));
            SYM_WALK_oEVALUATIONPARENTTREEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*EVALUATIONPARENTTREE*", NULL, 0)));
          }
          if (current_startup_time_phaseP(4)) {
            oAVAILABLE_ENVIRONMENT_FEATURESo = ((List*)(list(9, KWD_WALK_WARN_ABOUT_UNDEFINED_METHODS, KWD_WALK_SUPPRESS_WARNINGS, KWD_WALK_USE_BOOTSTRAP_TRANSLATOR, KWD_WALK_WARN_ABOUT_MISSING_METHODS, KWD_WALK_USE_HARDCODED_SYMBOLS, KWD_WALK_USE_COMMON_LISP_STRUCTS, KWD_WALK_USE_COMMON_LISP_VECTOR_STRUCTS, KWD_WALK_USE_CPP_GARBAGE_COLLECTOR, KWD_WALK_TRANSLATE_WITH_COPYRIGHT_HEADER)));
            oCURRENT_ENVIRONMENT_FEATURESo = new_list();
            oDEFAULT_ENVIRONMENT_FEATURESo = ((List*)(list(3, KWD_WALK_WARN_ABOUT_UNDEFINED_METHODS, KWD_WALK_WARN_ABOUT_MISSING_METHODS, KWD_WALK_USE_CPP_GARBAGE_COLLECTOR)));
            reset_environment_features();
            oTARGETTYPEo = SGT_WALK_VOID;
            oWRAPPED_TYPE_TABLEo = listO(15, listO(3, SGT_WALK_INTEGER_WRAPPER, SGT_WALK_INTEGER, NIL), listO(3, SGT_WALK_TRANSIENT_INTEGER_WRAPPER, SGT_WALK_INTEGER, NIL), listO(3, SGT_WALK_FLOAT_WRAPPER, SGT_WALK_FLOAT, NIL), listO(3, SGT_WALK_TRANSIENT_FLOAT_WRAPPER, SGT_WALK_FLOAT, NIL), listO(3, SGT_WALK_NUMBER_WRAPPER, SGT_WALK_NUMBER, NIL), listO(3, SGT_WALK_STRING_WRAPPER, SGT_WALK_STRING, NIL), listO(3, SGT_WALK_TRANSIENT_STRING_WRAPPER, SGT_WALK_STRING, NIL), listO(3, SGT_WALK_CHARACTER_WRAPPER, SGT_WALK_CHARACTER, NIL), listO(3, SGT_WALK_TRANSIENT_CHARACTER_WRAPPER, SGT_WALK_CHARACTER, NIL), listO(3, SGT_WALK_BOOLEAN_WRAPPER, SGT_WALK_BOOLEAN, NIL), listO(3, SGT_WALK_FUNCTION_CODE_WRAPPER, SGT_WALK_FUNCTION_CODE, NIL), listO(3, SGT_WALK_TRANSIENT_FUNCTION_CODE_WRAPPER, SGT_WALK_FUNCTION_CODE, NIL), listO(3, SGT_WALK_METHOD_CODE_WRAPPER, SGT_WALK_METHOD_CODE, NIL), listO(3, SGT_WALK_TRANSIENT_METHOD_CODE_WRAPPER, SGT_WALK_METHOD_CODE, NIL), NIL);
            oCOERSION_TABLEo = listO(33, listO(4, SGT_WALK_BOOLEAN, SGT_WALK_BOOLEAN_WRAPPER, SYM_WALK_WRAP_BOOLEAN, NIL), listO(4, SGT_WALK_INTEGER, SGT_WALK_INTEGER_WRAPPER, SYM_WALK_WRAP_LITERAL, NIL), listO(4, SGT_WALK_INTEGER, SGT_WALK_BOOLEAN_WRAPPER, SYM_WALK_INTEGER_TO_BOOLEAN_WRAPPER, NIL), listO(4, SGT_WALK_INTEGER, SGT_WALK_BOOLEAN, SYM_WALK_INTEGER_TO_BOOLEAN, NIL), listO(4, SGT_WALK_FLOAT, SGT_WALK_FLOAT_WRAPPER, SYM_WALK_WRAP_LITERAL, NIL), listO(4, SGT_WALK_STRING, SGT_WALK_STRING_WRAPPER, SYM_WALK_WRAP_LITERAL, NIL), listO(4, SGT_WALK_STRING, SGT_WALK_SYMBOL, SYM_WALK_INTERN_SYMBOL, NIL), listO(4, SGT_WALK_CHARACTER, SGT_WALK_CHARACTER_WRAPPER, SYM_WALK_WRAP_LITERAL, NIL), listO(4, SGT_WALK_FUNCTION_CODE, SGT_WALK_FUNCTION_CODE_WRAPPER, SYM_WALK_WRAP_LITERAL, NIL), listO(4, SGT_WALK_METHOD_CODE, SGT_WALK_METHOD_CODE_WRAPPER, SYM_WALK_WRAP_LITERAL, NIL), listO(4, SGT_WALK_SYMBOL, SGT_WALK_STRING, SYM_WALK_SYMBOL_NAME, NIL), listO(4, SGT_WALK_BOOLEAN_WRAPPER, SGT_WALK_BOOLEAN, SYM_WALK_WRAPPER_VALUE, NIL), listO(4, SGT_WALK_INTEGER_WRAPPER, SGT_WALK_INTEGER, SYM_WALK_WRAPPER_VALUE, NIL), listO(4, SGT_WALK_FLOAT_WRAPPER, SGT_WALK_FLOAT, SYM_WALK_WRAPPER_VALUE, NIL), listO(4, SGT_WALK_STRING_WRAPPER, SGT_WALK_STRING, SYM_WALK_WRAPPER_VALUE, NIL), listO(4, SGT_WALK_CHARACTER_WRAPPER, SGT_WALK_CHARACTER, SYM_WALK_WRAPPER_VALUE, NIL), listO(4, SGT_WALK_FUNCTION_CODE_WRAPPER, SGT_WALK_FUNCTION_CODE, SYM_WALK_WRAPPER_VALUE, NIL), listO(4, SGT_WALK_METHOD_CODE_WRAPPER, SGT_WALK_METHOD_CODE, SYM_WALK_WRAPPER_VALUE, NIL), listO(4, SGT_WALK_SURROGATE, SGT_WALK_CLASS, SYM_WALK_SURROGATE_VALUE, NIL), listO(4, SGT_WALK_SURROGATE, SGT_WALK_MODULE, SYM_WALK_SURROGATE_VALUE, NIL), listO(4, SGT_WALK_INPUT_STREAM, SGT_WALK_NATIVE_INPUT_STREAM, SYM_WALK_NATIVE_STREAM, NIL), listO(4, SGT_WALK_OUTPUT_STREAM, SGT_WALK_NATIVE_OUTPUT_STREAM, SYM_WALK_NATIVE_STREAM, NIL), listO(4, SGT_WALK_NUMBER, SGT_WALK_INTEGER, SYM_WALK_IDENTITY, NIL), listO(4, SGT_WALK_NUMBER, SGT_WALK_FLOAT, SYM_WALK_IDENTITY, NIL), listO(4, SGT_WALK_INTEGER, SGT_WALK_FLOAT, SYM_WALK_IDENTITY, NIL), listO(4, SGT_WALK_INTEGER, SGT_WALK_SINGLE_FLOAT, SYM_WALK_IDENTITY, NIL), listO(4, SGT_WALK_FLOAT, SGT_WALK_SINGLE_FLOAT, SYM_WALK_IDENTITY, NIL), listO(4, SGT_WALK_FLOAT, SGT_WALK_DOUBLE_FLOAT, SYM_WALK_IDENTITY, NIL), listO(4, SGT_WALK_INTEGER, SGT_WALK_SHORT_INTEGER, SYM_WALK_IDENTITY, NIL), listO(4, SGT_WALK_INTEGER, SGT_WALK_LONG_INTEGER, SYM_WALK_IDENTITY, NIL), listO(4, SGT_WALK_INTEGER, SGT_WALK_UNSIGNED_SHORT_INTEGER, SYM_WALK_IDENTITY, NIL), listO(4, SGT_WALK_INTEGER, SGT_WALK_UNSIGNED_LONG_INTEGER, SYM_WALK_IDENTITY, NIL), NIL);
            oSYMBOL_REGISTRYo = new_hash_table();
            oSYMBOL_SETo = new_list();
            oSPECIALVARIABLESTACKo = new_key_value_list();
            oTYPE_PREDICATE_TABLEo = listO(24, listO(3, SGT_WALK_BOOLEAN, SYM_WALK_BOOLEANp, NIL), listO(3, SGT_WALK_INTEGER, SYM_WALK_INTEGERp, NIL), listO(3, SGT_WALK_FLOAT, SYM_WALK_FLOATp, NIL), listO(3, SGT_WALK_STRING, SYM_WALK_STRINGp, NIL), listO(3, SGT_WALK_CHARACTER, SYM_WALK_CHARACTERp, NIL), listO(3, SGT_WALK_WRAPPER, SYM_WALK_WRAPPERp, NIL), listO(3, SGT_WALK_BOOLEAN_WRAPPER, SYM_WALK_BOOLEANp, NIL), listO(3, SGT_WALK_INTEGER_WRAPPER, SYM_WALK_INTEGERp, NIL), listO(3, SGT_WALK_FLOAT_WRAPPER, SYM_WALK_FLOATp, NIL), listO(3, SGT_WALK_STRING_WRAPPER, SYM_WALK_STRINGp, NIL), listO(3, SGT_WALK_CHARACTER_WRAPPER, SYM_WALK_CHARACTERp, NIL), listO(3, SGT_WALK_VERBATIM_STRING_WRAPPER, SYM_WALK_VERBATIM_STRINGp, NIL), listO(3, SGT_WALK_SURROGATE, SYM_WALK_SURROGATEp, NIL), listO(3, SGT_WALK_TYPE, SYM_WALK_TYPEp, NIL), listO(3, SGT_WALK_SYMBOL, SYM_WALK_SYMBOLp, NIL), listO(3, SGT_WALK_TRANSIENT_SYMBOL, SYM_WALK_TRANSIENT_SYMBOLp, NIL), listO(3, SGT_WALK_KEYWORD, SYM_WALK_KEYWORDp, NIL), listO(3, SGT_WALK_CONS, SYM_WALK_CONSp, NIL), listO(3, SGT_WALK_CLASS, SYM_WALK_CLASSp, NIL), listO(3, SGT_WALK_STORAGE_SLOT, SYM_WALK_STORAGE_SLOTp, NIL), listO(3, SGT_WALK_METHOD_SLOT, SYM_WALK_METHOD_SLOTp, NIL), listO(3, SGT_WALK_ANCHORED_TYPE_SPECIFIER, SYM_WALK_ANCHORED_TYPE_SPECIFIERp, NIL), listO(3, SGT_WALK_PARAMETRIC_TYPE_SPECIFIER, SYM_WALK_PARAMETRIC_TYPE_SPECIFIERp, NIL), NIL);
            oNUMERIC_TYPE_HIERARCHYo = list(3, SGT_WALK_INTEGER, SGT_WALK_FLOAT, SGT_WALK_NUMBER);
            oMACRO_TABLEo = new_hash_table();
            oNATIVE_NAME_TABLEo = new_hash_table();
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("TRANSLATION-UNIT", "(DEFCLASS TRANSLATION-UNIT (STANDARD-OBJECT) :SLOTS ((THE-OBJECT :TYPE OBJECT) (CATEGORY :TYPE SYMBOL) (ANNOTATION :TYPE STRING) (AUXILIARY? :TYPE BOOLEAN) (CODE-REGISTER :TYPE OBJECT) (TRANSLATION :TYPE OBJECT) (REFERENCED-GLOBALS :TYPE (LIST OF GLOBAL-VARIABLE) :ALLOCATION :EMBEDDED :COMPONENT? TRUE)) :RECYCLE-METHOD :FREE-LIST :TERMINATOR TERMINATE-TRANSLATION-UNIT? :PRINT-FORM (PRINT-TRANSLATION-UNIT SELF STREAM))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_translation_unit));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_translation_unit_slot_value));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("DISPLAY-ENVIRONMENT-FEATURES", NULL, "(DEFUN DISPLAY-ENVIRONMENT-FEATURES () :DOCUMENTATION \"Print a list of the currently enabled environment \nfeatures and print a list of all Stella environment features.\")");

              method->function_code = ((cpp_function_code)(&display_environment_features));
            }
            { Method_Slot* method = define_method_from_stringified_source("ENABLE-ENVIRONMENT-FEATURE", "ARGUMENT-LIST", "(DEFUN ENABLE-ENVIRONMENT-FEATURE (|&REST| (FEATURES KEYWORD)) :DOCUMENTATION \"Enable the environment feature(s) indicated by the\nkeywords in 'features'.\")");

              method->function_code = ((cpp_function_code)(&enable_environment_feature));
            }
            { Method_Slot* method = define_method_from_stringified_source("DISABLE-ENVIRONMENT-FEATURE", "ARGUMENT-LIST", "(DEFUN DISABLE-ENVIRONMENT-FEATURE (|&REST| (FEATURES KEYWORD)) :DOCUMENTATION \"Disable the environment feature(s) indicated by the\nkeywords in 'features'.\")");

              method->function_code = ((cpp_function_code)(&disable_environment_feature));
            }
            { Method_Slot* method = define_method_from_stringified_source("RESET-ENVIRONMENT-FEATURES", NULL, "(DEFUN RESET-ENVIRONMENT-FEATURES () :DOCUMENTATION \"Reset the current environment features to their default\nsettings.\")");

              method->function_code = ((cpp_function_code)(&reset_environment_features));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRACE-IF-EXPANDER", "KEYWORD", "(DEFUN (TRACE-IF-EXPANDER OBJECT) ((KEYWORD KEYWORD) |&BODY| (BODY CONS)))");

              method->function_code = ((cpp_function_code)(&trace_if_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRACE-KEYWORD?", "KEYWORD", "(DEFUN (TRACE-KEYWORD? BOOLEAN) ((KEYWORD KEYWORD)))");

              method->function_code = ((cpp_function_code)(&trace_keywordP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-TRACE", "ARGUMENT-LIST", "(DEFUN (ADD-TRACE LIST) (|&REST| (KEYWORDS GENERALIZED-SYMBOL)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Enable trace messages identified by any of the listed `keywords'.  After\ncalling `(add-trace <keyword>)' code guarded by `(trace-if <keyword> ...)'\nwill be executed when it is encountered.\")");

              method->function_code = ((cpp_function_code)(&add_trace));
              set_dynamic_slot_value(method, SYM_WALK_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&add_trace_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("DROP-TRACE", "ARGUMENT-LIST", "(DEFUN (DROP-TRACE LIST) (|&REST| (KEYWORDS GENERALIZED-SYMBOL)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Disable trace messages identified by any of the listed `keywords'.  After\ncalling `(drop-trace <keyword>)' code guarded by `(trace-if <keyword> ...)'\nwill not be executed when it is encountered.\")");

              method->function_code = ((cpp_function_code)(&drop_trace));
              set_dynamic_slot_value(method, SYM_WALK_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&drop_trace_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-TRACE", NULL, "(DEFUN CLEAR-TRACE () :COMMAND? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Disable all tracing previously enabled with `add-trace'.\")");

              method->function_code = ((cpp_function_code)(&clear_trace));
            }
            { Method_Slot* method = define_method_from_stringified_source("NAME-QUOTED-TREE", "CONS", "(DEFUN (NAME-QUOTED-TREE STRING) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&name_quoted_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-QUOTED-TREE", "STRING", "(DEFUN (GET-QUOTED-TREE CONS) ((TREENAME STRING) (MODULENAME STRING)) :DOCUMENTATION \"Return the quoted tree with name 'treeName'.\")");

              method->function_code = ((cpp_function_code)(&get_quoted_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-TRANSLATION-UNIT?", "TRANSLATION-UNIT", "(DEFUN (TERMINATE-TRANSLATION-UNIT? BOOLEAN) ((SELF TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&terminate_translation_unitP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-TRANSLATION-UNIT", "TRANSLATION-UNIT", "(DEFUN PRINT-TRANSLATION-UNIT ((SELF TRANSLATION-UNIT) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_translation_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("USE-HARDCODED-SYMBOLS?", NULL, "(DEFUN (USE-HARDCODED-SYMBOLS? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&use_hardcoded_symbolsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("USE-BOOTSTRAP-TRANSLATOR?", NULL, "(DEFUN (USE-BOOTSTRAP-TRANSLATOR? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&use_bootstrap_translatorP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TOGGLE-TRANSLATORS", NULL, "(DEFUN (TOGGLE-TRANSLATORS KEYWORD) () :DOCUMENTATION \"Switch between the bootstrap and real translators.\")");

              method->function_code = ((cpp_function_code)(&toggle_translators));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSLATE-TO-COMMON-LISP?", NULL, "(DEFUN (TRANSLATE-TO-COMMON-LISP? BOOLEAN) () :DOCUMENTATION \"Return TRUE if current output language is Common-Lisp.\")");

              method->function_code = ((cpp_function_code)(&translate_to_common_lispP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSLATE-TO-SINGLE-INHERITANCE-LANGUAGE?", NULL, "(DEFUN (TRANSLATE-TO-SINGLE-INHERITANCE-LANGUAGE? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&translate_to_single_inheritance_languageP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TOGGLE-OUTPUT-LANGUAGE", NULL, "(DEFUN (TOGGLE-OUTPUT-LANGUAGE KEYWORD) () :DOCUMENTATION \"Switch between Common Lisp and C++ as output languages.\")");

              method->function_code = ((cpp_function_code)(&toggle_output_language));
            }
            { Method_Slot* method = define_method_from_stringified_source("DECLARATION-OPERATOR?", "SYMBOL", "(DEFUN (DECLARATION-OPERATOR? BOOLEAN) ((OPERATOR SYMBOL)))");

              method->function_code = ((cpp_function_code)(&declaration_operatorP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DECLARATION-TREE?", "CONS", "(DEFUN (DECLARATION-TREE? BOOLEAN) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&declaration_treeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-ANNOTATION", "CONS", "(DEFUN (CREATE-ANNOTATION STRING) ((TOP-LEVEL-TREE CONS)))");

              method->function_code = ((cpp_function_code)(&create_annotation));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-TOP-LEVEL-TREE", "CONS", "(DEFUN WALK-TOP-LEVEL-TREE ((TREE CONS) (CREATEANNOTATION? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&walk_top_level_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-TOP-LEVEL-EXPRESSION", "OBJECT", "(DEFUN (WALK-TOP-LEVEL-EXPRESSION OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&walk_top_level_expression));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-PHASE-ONE-UNIT", "TRANSLATION-UNIT", "(DEFUN WALK-PHASE-ONE-UNIT ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&walk_phase_one_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-AUXILIARY-TREE", "CONS", "(DEFUN WALK-AUXILIARY-TREE ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_auxiliary_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-WALK-AUXILIARY-TREE", "CONS", "(DEFUN (HELP-WALK-AUXILIARY-TREE TRANSLATION-UNIT) ((TREE CONS) (FINALIZE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&help_walk_auxiliary_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-ALL-PHASE-ONE-UNITS", "SYMBOL", "(DEFUN WALK-ALL-PHASE-ONE-UNITS ((STARTUPFNNAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&walk_all_phase_one_units));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSLATE-ALL-UNITS", NULL, "(DEFUN TRANSLATE-ALL-UNITS ())");

              method->function_code = ((cpp_function_code)(&translate_all_units));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMBINE-TRANSLATED-TREES", NULL, "(DEFUN (COMBINE-TRANSLATED-TREES CONS) ())");

              method->function_code = ((cpp_function_code)(&combine_translated_trees));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSLATE-WALKED-TREE", "OBJECT", "(DEFUN (TRANSLATE-WALKED-TREE OBJECT) ((CODETREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&translate_walked_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSLATOR-OUTPUT-LANGUAGE", NULL, "(DEFUN (TRANSLATOR-OUTPUT-LANGUAGE KEYWORD) ())");

              method->function_code = ((cpp_function_code)(&translator_output_language));
            }
            { Method_Slot* method = define_method_from_stringified_source("SET-TRANSLATOR-OUTPUT-LANGUAGE", "KEYWORD", "(DEFUN (SET-TRANSLATOR-OUTPUT-LANGUAGE KEYWORD) ((NEWLANGUAGE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&set_translator_output_language));
            }
            { Method_Slot* method = define_method_from_stringified_source("RESET-TRANSLATION-ERRORS", NULL, "(DEFUN RESET-TRANSLATION-ERRORS ())");

              method->function_code = ((cpp_function_code)(&reset_translation_errors));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-TRANSLATION-ERROR", NULL, "(DEFUN SIGNAL-TRANSLATION-ERROR ())");

              method->function_code = ((cpp_function_code)(&signal_translation_error));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-TRANSLATION-WARNING", NULL, "(DEFUN SIGNAL-TRANSLATION-WARNING ())");

              method->function_code = ((cpp_function_code)(&signal_translation_warning));
            }
            { Method_Slot* method = define_method_from_stringified_source("IGNORE-TRANSLATION-ERRORS?", NULL, "(DEFUN (IGNORE-TRANSLATION-ERRORS? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&ignore_translation_errorsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSLATION-ERRORS?", NULL, "(DEFUN (TRANSLATION-ERRORS? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&translation_errorsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUMMARIZE-TRANSLATION-ERRORS", NULL, "(DEFUN SUMMARIZE-TRANSLATION-ERRORS ())");

              method->function_code = ((cpp_function_code)(&summarize_translation_errors));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-ERROR-CONTEXT", "STRING", "(DEFUN PRINT-ERROR-CONTEXT ((PREFIX STRING) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_error_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUSH-VARIABLE-BINDING", "SYMBOL", "(DEFUN PUSH-VARIABLE-BINDING ((VARIABLE SYMBOL) (TYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&push_variable_binding));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP-VARIABLE-BINDING", NULL, "(DEFUN POP-VARIABLE-BINDING ())");

              method->function_code = ((cpp_function_code)(&pop_variable_binding));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-VARIABLE-TYPE", "SYMBOL", "(DEFUN (LOOKUP-VARIABLE-TYPE TYPE-SPEC) ((VARIABLENAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&lookup_variable_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("REGISTER-REFERENCE-TO-GLOBAL-VARIABLE", "SYMBOL", "(DEFUN REGISTER-REFERENCE-TO-GLOBAL-VARIABLE ((VARIABLENAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&register_reference_to_global_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOCAL-GENSYM", "STRING", "(DEFUN (LOCAL-GENSYM SYMBOL) ((PREFIX STRING)))");

              method->function_code = ((cpp_function_code)(&local_gensym));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-TRANSIENT-TYPE-SPEC", "TYPE-SPEC", "(DEFUN FREE-TRANSIENT-TYPE-SPEC ((SELF TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&free_transient_type_spec));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUPPRESS-WARNINGS?", NULL, "(DEFUN (SUPPRESS-WARNINGS? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&suppress_warningsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("BAD-ARGUMENT-RANGE?", "CONS", "(DEFUN (BAD-ARGUMENT-RANGE? BOOLEAN) ((TREE CONS) (MINARITY INTEGER) (MAXARITY INTEGER)))");

              method->function_code = ((cpp_function_code)(&bad_argument_rangeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("BAD-ARGUMENT-COUNT?", "CONS", "(DEFUN (BAD-ARGUMENT-COUNT? BOOLEAN) ((TREE CONS) (ARITY INTEGER)))");

              method->function_code = ((cpp_function_code)(&bad_argument_countP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-ILLEGAL-STATEMENT-TREE", NULL, "(DEFUN (YIELD-ILLEGAL-STATEMENT-TREE CONS) ())");

              method->function_code = ((cpp_function_code)(&yield_illegal_statement_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-ILLEGAL-EXPRESSION-TREE", NULL, "(DEFUN (YIELD-ILLEGAL-EXPRESSION-TREE OBJECT) ())");

              method->function_code = ((cpp_function_code)(&yield_illegal_expression_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-DONT-CALL-ME-TREE", "OBJECT", "(DEFUN (WALK-DONT-CALL-ME-TREE CONS TYPE-SPEC) ((TREE OBJECT) (RETURNTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&walk_dont_call_me_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("ILLEGAL-TREE?", "OBJECT", "(DEFUN (ILLEGAL-TREE? BOOLEAN) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&illegal_treeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NATIVE-CLASS-METHOD-INLINING?", NULL, "(DEFUN (NATIVE-CLASS-METHOD-INLINING? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&native_class_method_inliningP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PROGNIFY", "CONS", "(DEFUN (PROGNIFY OBJECT) ((TREES CONS)))");

              method->function_code = ((cpp_function_code)(&prognify));
            }
            { Method_Slot* method = define_method_from_stringified_source("OPTIMIZE-PROGN", "CONS", "(DEFUN (OPTIMIZE-PROGN OBJECT) ((PROGN-TREE CONS)))");

              method->function_code = ((cpp_function_code)(&optimize_progn));
            }
            { Method_Slot* method = define_method_from_stringified_source("TREE-TO-TREES", "OBJECT", "(DEFUN (TREE-TO-TREES CONS) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&tree_to_trees));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAPPED-TYPE-TO-TYPE", "TYPE", "(DEFUN (WRAPPED-TYPE-TO-TYPE TYPE) ((SELF TYPE)) :DOCUMENTATION \"Return the unwrapped type for the wrapped type 'self',\nor 'self' if it is not a wrapped type.\")");

              method->function_code = ((cpp_function_code)(&wrapped_type_to_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAPPER-VALUE-TYPE", "WRAPPER", "(DEFUN (WRAPPER-VALUE-TYPE TYPE) ((SELF WRAPPER)) :DOCUMENTATION \"Return the type of the value stored in the wrapper 'self'.\")");

              method->function_code = ((cpp_function_code)(&wrapper_value_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("TYPE-TO-WRAPPED-TYPE", "SURROGATE", "(DEFMETHOD (TYPE-TO-WRAPPED-TYPE TYPE) ((SELF TYPE)) :DOCUMENTATION \"Return the wrapped type for the type 'self',\nor 'self' if it is not a bare literal type.\")");

              method->method_code = ((cpp_method_code)(&Surrogate::type_to_wrapped_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-COERSION-METHOD", "TYPE", "(DEFUN (LOOKUP-COERSION-METHOD SYMBOL) ((SOURCETYPE TYPE) (TARGETTYPE TYPE) (EXPRESSION OBJECT)))");

              method->function_code = ((cpp_function_code)(&lookup_coersion_method));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSLATING-CODE?", NULL, "(DEFUN (TRANSLATING-CODE? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&translating_codeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VERIFY-TYPE", "TYPE", "(DEFUN (VERIFY-TYPE TYPE) ((SELF TYPE)))");

              method->function_code = ((cpp_function_code)(&verify_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("SAFE-SUBTYPE-OF?", "TYPE", "(DEFUN (SAFE-SUBTYPE-OF? BOOLEAN) ((SUBTYPE TYPE) (SUPERTYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&safe_subtype_ofP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WARN-ABOUT-UNKNOWN-SOURCE-TYPE", "OBJECT", "(DEFUN WARN-ABOUT-UNKNOWN-SOURCE-TYPE ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&warn_about_unknown_source_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("COERCE-A-TREE", "OBJECT", "(DEFUN (COERCE-A-TREE OBJECT TYPE-SPEC) ((TREE OBJECT) (SOURCETYPE TYPE-SPEC) (TARGETTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&coerce_a_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-COERCE-A-TREE", "OBJECT", "(DEFUN (HELP-COERCE-A-TREE OBJECT TYPE-SPEC BOOLEAN) ((TREE OBJECT) (SOURCETYPE TYPE-SPEC) (TARGETTYPE TYPE-SPEC) (TESTONLY? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&help_coerce_a_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("COERCIBLE?", "OBJECT", "(DEFUN (COERCIBLE? BOOLEAN) ((TREE OBJECT) (SOURCETYPE TYPE-SPEC) (TARGETTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&coercibleP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALKING-EXPRESSION?", NULL, "(DEFUN (WALKING-EXPRESSION? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&walking_expressionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-EXPRESSION-TREE", "OBJECT", "(DEFUN (WALK-EXPRESSION-TREE OBJECT TYPE-SPEC) ((EXPTREE OBJECT) (TARGETTYPE TYPE-SPEC) (OPERATORNAME SYMBOL) (VRLETISOK? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&walk_expression_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-WITHOUT-TYPE-TREE", "OBJECT", "(DEFUN (WALK-WITHOUT-TYPE-TREE OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&walk_without_type_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-LIST-OF-TREES", "CONS", "(DEFUN (WALK-LIST-OF-TREES CONS) ((TREES CONS)))");

              method->function_code = ((cpp_function_code)(&walk_list_of_trees));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-STATEMENT", "OBJECT", "(DEFUN (WALK-STATEMENT OBJECT) ((TREE OBJECT) (WARNONATOM? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&walk_statement));
            }
            { Method_Slot* method = define_method_from_stringified_source("ELIMINATE-VRLET-STATEMENT", "CONS", "(DEFUN (ELIMINATE-VRLET-STATEMENT CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&eliminate_vrlet_statement));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYS-TREE", "OBJECT", "(DEFUN (SYS-TREE CONS TYPE-SPEC) ((TREE OBJECT) (TYPESPEC TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&sys_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALKED-EXPRESSION-TYPE", "OBJECT", "(DEFUN (WALKED-EXPRESSION-TYPE TYPE-SPEC) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&walked_expression_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEED-IDENTICAL-METHOD-SIGNATURES?", NULL, "(DEFUN (NEED-IDENTICAL-METHOD-SIGNATURES? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&need_identical_method_signaturesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-MOST-GENERAL-RETURN-TYPE", "METHOD-SLOT", "(DEFUN (COMPUTE-MOST-GENERAL-RETURN-TYPE TYPE-SPEC) ((METHOD METHOD-SLOT) (RETURNTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&compute_most_general_return_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-REAL-SLOT-TYPE", "STORAGE-SLOT", "(DEFUN (COMPUTE-REAL-SLOT-TYPE TYPE-SPEC) ((SLOT STORAGE-SLOT) (FIRSTARGTYPE TYPE-SPEC) (RETURNTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&compute_real_slot_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("SYS-TREE-IF-NEEDED", "SLOT", "(DEFUN (SYS-TREE-IF-NEEDED OBJECT TYPE-SPEC) ((SLOT SLOT) (TREE OBJECT) (FIRSTARGTYPE TYPE-SPEC) (RETURNTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&sys_tree_if_needed));
            }
            { Method_Slot* method = define_method_from_stringified_source("TARGET-LANGUAGE-TYPE", "OBJECT", "(DEFUN (TARGET-LANGUAGE-TYPE TYPE) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&target_language_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("SET-TARGET-LANGUAGE-TYPE", "CONS", "(DEFUN (SET-TARGET-LANGUAGE-TYPE CONS TYPE-SPEC) ((SYSTREE CONS) (TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&set_target_language_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETE-NULL-STATEMENTS", "CONS", "(DEFUN (DELETE-NULL-STATEMENTS CONS) ((TREES CONS)))");

              method->function_code = ((cpp_function_code)(&delete_null_statements));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-A-TREE", "OBJECT", "(DEFUN (WALK-A-TREE OBJECT TYPE-SPEC) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&walk_a_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-WALK-A-TREE", "OBJECT", "(DEFUN (HELP-WALK-A-TREE OBJECT TYPE-SPEC) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&help_walk_a_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-A-CONS-TREE", "CONS", "(DEFUN (WALK-A-CONS-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_a_cons_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("INCREMENTAL-TRANSLATION?", NULL, "(DEFUN (INCREMENTAL-TRANSLATION? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&incremental_translationP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SYMBOL-CONSTANT-NAME", "GENERALIZED-SYMBOL", "(DEFUN (YIELD-SYMBOL-CONSTANT-NAME SYMBOL) ((SYMBOL GENERALIZED-SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_symbol_constant_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-STARTUP-SYMBOL", "GENERALIZED-SYMBOL", "(DEFUN (CREATE-STARTUP-SYMBOL SYMBOL) ((SYMBOL GENERALIZED-SYMBOL)))");

              method->function_code = ((cpp_function_code)(&create_startup_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("REGISTER-SYMBOL", "GENERALIZED-SYMBOL", "(DEFUN REGISTER-SYMBOL ((SYMBOL GENERALIZED-SYMBOL)))");

              method->function_code = ((cpp_function_code)(&register_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-SYMBOL-REGISTRY", NULL, "(DEFUN CLEAR-SYMBOL-REGISTRY ())");

              method->function_code = ((cpp_function_code)(&clear_symbol_registry));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-HARDCODED-INTERN-REGISTERED-SYMBOLS-TREE", NULL, "(DEFUN (YIELD-HARDCODED-INTERN-REGISTERED-SYMBOLS-TREE CONS) ())");

              method->function_code = ((cpp_function_code)(&yield_hardcoded_intern_registered_symbols_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-ATOMIC-TREE", "OBJECT", "(DEFMETHOD (WALK-ATOMIC-TREE OBJECT TYPE-SPEC) ((SELF OBJECT)))");

              method->method_code = ((cpp_method_code)(&Object::walk_atomic_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-ATOMIC-TREE", "WRAPPER", "(DEFMETHOD (WALK-ATOMIC-TREE OBJECT TYPE-SPEC) ((SELF WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Wrapper::walk_atomic_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-CONSTANT-SYMBOL", "SYMBOL", "(DEFUN (LOOKUP-CONSTANT-SYMBOL TYPE) ((SELF SYMBOL)))");

              method->function_code = ((cpp_function_code)(&lookup_constant_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONSTANT-SYMBOL?", "SYMBOL", "(DEFUN (CONSTANT-SYMBOL? BOOLEAN) ((SYMBOL SYMBOL)))");

              method->function_code = ((cpp_function_code)(&constant_symbolP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-CONSTANT-SYMBOL", "SYMBOL", "(DEFUN (WALK-CONSTANT-SYMBOL SYMBOL TYPE) ((SELF SYMBOL)))");

              method->function_code = ((cpp_function_code)(&walk_constant_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-ATOMIC-TREE", "SYMBOL", "(DEFMETHOD (WALK-ATOMIC-TREE OBJECT TYPE-SPEC) ((SELF SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Symbol::walk_atomic_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-ATOMIC-TREE", "KEYWORD", "(DEFMETHOD (WALK-ATOMIC-TREE OBJECT TYPE-SPEC) ((SELF KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Keyword::walk_atomic_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-ATOMIC-TREE", "SURROGATE", "(DEFMETHOD (WALK-ATOMIC-TREE OBJECT TYPE-SPEC) ((SELF SURROGATE)))");

              method->method_code = ((cpp_method_code)(&Surrogate::walk_atomic_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("VRLET-EXPRESSION?", "OBJECT", "(DEFUN (VRLET-EXPRESSION? BOOLEAN) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&vrlet_expressionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PROCEDURAL-EXPRESSION?", "OBJECT", "(DEFUN (PROCEDURAL-EXPRESSION? BOOLEAN) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&procedural_expressionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBSTITUTE-ONCE", "OBJECT", "(DEFUN (SUBSTITUTE-ONCE BOOLEAN) ((EXPRESSION OBJECT) (NEWTREE OBJECT) (OLDTREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&substitute_once));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSFORM-VRLET-EXPRESSION", "CONS", "(DEFUN (TRANSFORM-VRLET-EXPRESSION CONS TYPE-SPEC) ((STATEMENT CONS) (VREXPRESSION CONS)))");

              method->function_code = ((cpp_function_code)(&transform_vrlet_expression));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-TRANSFORM-BOOLEAN-PROCEDURAL-EXPRESSION", "OBJECT", "(DEFUN (HELP-TRANSFORM-BOOLEAN-PROCEDURAL-EXPRESSION CONS) ((EXPRESSION OBJECT) (TESTVARIABLE SYMBOL)))");

              method->function_code = ((cpp_function_code)(&help_transform_boolean_procedural_expression));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSFORM-BOOLEAN-PROCEDURAL-EXPRESSION", "CONS", "(DEFUN (TRANSFORM-BOOLEAN-PROCEDURAL-EXPRESSION CONS TYPE-SPEC) ((STATEMENT CONS) (VREXPRESSION CONS)))");

              method->function_code = ((cpp_function_code)(&transform_boolean_procedural_expression));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERCOLATE-OUT-BOOLEAN-VRLET-EXPRESSIONS", "CONS", "(DEFUN (PERCOLATE-OUT-BOOLEAN-VRLET-EXPRESSIONS CONS) ((BOOLEANEXPRESSION CONS)))");

              method->function_code = ((cpp_function_code)(&percolate_out_boolean_vrlet_expressions));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSFORM-PROCEDURAL-EXPRESSION", "CONS", "(DEFUN (TRANSFORM-PROCEDURAL-EXPRESSION CONS TYPE-SPEC) ((STATEMENT CONS) (VREXPRESSION CONS) (TYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&transform_procedural_expression));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERCOLATE-OUT-VRLET-EXPRESSION", "CONS", "(DEFUN (PERCOLATE-OUT-VRLET-EXPRESSION CONS TYPE-SPEC) ((STATEMENT CONS) (VREXPRESSION CONS) (TYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&percolate_out_vrlet_expression));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-SETQ-TREE", "CONS", "(DEFUN (WALK-SETQ-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_setq_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-FIXED-SLOT-VALUE-SETTER-TREE", "SLOT", "(DEFUN (YIELD-FIXED-SLOT-VALUE-SETTER-TREE CONS) ((SLOT SLOT) (OBJECTREF OBJECT) (VALUETREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&yield_fixed_slot_value_setter_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-SETF-TREE", "CONS", "(DEFUN (WALK-SETF-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_setf_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-DYNAMIC-SLOT-VALUE-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-DYNAMIC-SLOT-VALUE-TREE CONS) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (RETURNTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&yield_dynamic_slot_value_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-DYNAMIC-SLOT-VALUE-SETTER-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-DYNAMIC-SLOT-VALUE-SETTER-TREE CONS) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (VALUEREF OBJECT) (RETURNTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&yield_dynamic_slot_value_setter_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-NATIVE-SLOT-VALUE-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-NATIVE-SLOT-VALUE-TREE CONS) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (OBJECTTYPE TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&yield_native_slot_value_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CONTEXT-SENSITIVE-SLOT-VALUE-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-CONTEXT-SENSITIVE-SLOT-VALUE-TREE CONS TYPE-SPEC) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (RETURNTYPE TYPE-SPEC) (CSOPTIONS CONS)))");

              method->function_code = ((cpp_function_code)(&yield_context_sensitive_slot_value_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SLOT-VALUE-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-SLOT-VALUE-TREE CONS TYPE-SPEC) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (OBJECTTYPE TYPE-SPEC) (RETURNTYPE TYPE-SPEC) (CSOPTIONS CONS)))");

              method->function_code = ((cpp_function_code)(&yield_slot_value_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-SLOT-VALUE-TREE", "CONS", "(DEFUN (WALK-SLOT-VALUE-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_slot_value_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-NATIVE-SLOT-VALUE-SETTER-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-NATIVE-SLOT-VALUE-SETTER-TREE CONS) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (OBJECTTYPE TYPE-SPEC) (VALUEREF OBJECT)))");

              method->function_code = ((cpp_function_code)(&yield_native_slot_value_setter_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CONTEXT-SENSITIVE-SLOT-VALUE-SETTER-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-CONTEXT-SENSITIVE-SLOT-VALUE-SETTER-TREE CONS TYPE-SPEC) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (VALUEREF OBJECT) (RETURNTYPE TYPE-SPEC) (CSOPTIONS CONS)))");

              method->function_code = ((cpp_function_code)(&yield_context_sensitive_slot_value_setter_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SLOT-VALUE-SETTER-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-SLOT-VALUE-SETTER-TREE CONS TYPE-SPEC) ((SLOT STORAGE-SLOT) (OBJECTREF OBJECT) (OBJECTTYPE TYPE-SPEC) (VALUEREF OBJECT) (RETURNTYPE TYPE-SPEC) (CSOPTIONS CONS)))");

              method->function_code = ((cpp_function_code)(&yield_slot_value_setter_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-SLOT-VALUE-SETTER-TREE", "CONS", "(DEFUN (WALK-SLOT-VALUE-SETTER-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_slot_value_setter_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("SAFE-YIELD-TYPE-SPECIFIER", "OBJECT", "(DEFUN (SAFE-YIELD-TYPE-SPECIFIER TYPE-SPEC) ((TYPETREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&safe_yield_type_specifier));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-A-DECLARATION", "SYMBOL", "(DEFUN (WALK-A-DECLARATION CONS) ((VARIABLE SYMBOL) (TYPETREE OBJECT) (VALUE OBJECT) (INPUTPARAMETER? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&walk_a_declaration));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-VARIABLE-DECLARATIONS", "CONS", "(DEFUN (WALK-VARIABLE-DECLARATIONS CONS) ((DECLARATIONS CONS)))");

              method->function_code = ((cpp_function_code)(&walk_variable_declarations));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSFORM-LET-WITH-PROCEDURAL-EXPRESSION", "CONS", "(DEFUN (TRANSFORM-LET-WITH-PROCEDURAL-EXPRESSION CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&transform_let_with_procedural_expression));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP-LOCAL-VARIABLE-BINDINGS", "CONS", "(DEFUN POP-LOCAL-VARIABLE-BINDINGS ((DECLARATIONS CONS)))");

              method->function_code = ((cpp_function_code)(&pop_local_variable_bindings));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-LET-TREE", "CONS", "(DEFUN (WALK-LET-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_let_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("SPECIAL-IMPLEMENTATION-STYLE", NULL, "(DEFUN (SPECIAL-IMPLEMENTATION-STYLE KEYWORD) ())");

              method->function_code = ((cpp_function_code)(&special_implementation_style));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUSH-SPECIAL", "SYMBOL", "(DEFUN PUSH-SPECIAL ((VARIABLE SYMBOL) (OLDVALUEVARIABLE SYMBOL)))");

              method->function_code = ((cpp_function_code)(&push_special));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP-SPECIAL", NULL, "(DEFUN POP-SPECIAL ())");

              method->function_code = ((cpp_function_code)(&pop_special));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-OLD-VALUE-VARIABLE", "SYMBOL", "(DEFUN (LOOKUP-OLD-VALUE-VARIABLE SYMBOL) ((VARIABLE SYMBOL)))");

              method->function_code = ((cpp_function_code)(&lookup_old_value_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEED-TO-UNBIND-SPECIALS?", NULL, "(DEFUN (NEED-TO-UNBIND-SPECIALS? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&need_to_unbind_specialsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SPECIAL-UNBIND-TREE", "INTEGER", "(DEFUN (YIELD-SPECIAL-UNBIND-TREE CONS) ((NOFBINDINGS INTEGER)))");

              method->function_code = ((cpp_function_code)(&yield_special_unbind_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-RETURN-SPECIAL-UNBIND-TREE", NULL, "(DEFUN (YIELD-RETURN-SPECIAL-UNBIND-TREE CONS) ())");

              method->function_code = ((cpp_function_code)(&yield_return_special_unbind_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-LOOP-EXIT-SPECIAL-UNBIND-TREE", NULL, "(DEFUN (YIELD-LOOP-EXIT-SPECIAL-UNBIND-TREE CONS) ())");

              method->function_code = ((cpp_function_code)(&yield_loop_exit_special_unbind_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-SPECIAL-TREE", "CONS", "(DEFUN (WALK-SPECIAL-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_special_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-CL-SPECIAL-TREE", "CONS", "(DEFUN (WALK-CL-SPECIAL-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_cl_special_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-SAVE-AND-RESTORE-SPECIAL-TREE", "CONS", "(DEFUN (WALK-SAVE-AND-RESTORE-SPECIAL-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_save_and_restore_special_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-PROTECTED-SAVE-AND-RESTORE-SPECIAL-TREE", "CONS", "(DEFUN (WALK-PROTECTED-SAVE-AND-RESTORE-SPECIAL-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_protected_save_and_restore_special_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-CAST-TREE", "CONS", "(DEFUN (WALK-CAST-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_cast_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("VALUES-TREE?", "OBJECT", "(DEFUN (VALUES-TREE? BOOLEAN) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&values_treeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-VALUES-TREE", "CONS", "(DEFUN (WALK-VALUES-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_values_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-MV-EXPRESSION-TREE", "OBJECT", "(DEFUN (WALK-MV-EXPRESSION-TREE OBJECT CONS (LIST OF TYPE-SPEC)) ((TREE OBJECT) (TARGETTYPES (LIST OF TYPE-SPEC)) (OPERATOR SYMBOL)))");

              method->function_code = ((cpp_function_code)(&walk_mv_expression_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("LISTIFY-TYPE-SPEC", "TYPE-SPEC", "(DEFUN (LISTIFY-TYPE-SPEC (LIST OF TYPE-SPEC)) ((TYPESPEC TYPE-SPEC)))");

              method->function_code = ((cpp_function_code)(&listify_type_spec));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOT-FROM-EXPRESSION-TREE", "CONS", "(DEFUN (SLOT-FROM-EXPRESSION-TREE SLOT) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&slot_from_expression_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-MV-TREE", "OBJECT", "(DEFUN (WALK-MV-TREE OBJECT CONS (LIST OF TYPE-SPEC)) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&walk_mv_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-MV-VALUES-TREE", "CONS", "(DEFUN (WALK-MV-VALUES-TREE CONS CONS (LIST OF TYPE-SPEC)) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_mv_values_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("COERCE-MV-TREE", "OBJECT", "(DEFUN (COERCE-MV-TREE OBJECT CONS (LIST OF TYPE-SPEC)) ((TREE OBJECT) (OPERATOR SYMBOL) (SOURCETYPES (LIST OF TYPE-SPEC)) (TARGETTYPES (LIST OF TYPE-SPEC))))");

              method->function_code = ((cpp_function_code)(&coerce_mv_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-RETURN-AND-UNBIND-SPECIALS", "CONS", "(DEFUN (WALK-RETURN-AND-UNBIND-SPECIALS CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_return_and_unbind_specials));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-RETURN-TREE", "CONS", "(DEFUN (WALK-RETURN-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_return_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-MV-SETQ-TREE", "CONS", "(DEFUN (WALK-MV-SETQ-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_mv_setq_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-MV-BIND-TREE", "CONS", "(DEFUN (WALK-MV-BIND-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_mv_bind_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-LOOP-TREE", "CONS", "(DEFUN (WALK-LOOP-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_loop_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-LOOP-EXIT-TREE", "CONS", "(DEFUN (WALK-LOOP-EXIT-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_loop_exit_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-WHILE-TREE", "CONS", "(DEFUN (WALK-WHILE-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_while_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-CONDITIONAL-TREE", "CONS", "(DEFUN (WALK-CONDITIONAL-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_conditional_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-CHOOSE-TREE", "CONS", "(DEFUN (WALK-CHOOSE-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_choose_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-BOOLEAN-TREE", "CONS", "(DEFUN (WALK-BOOLEAN-TREE OBJECT TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_boolean_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("AND-OR-NOT-TREE?", "OBJECT", "(DEFUN (AND-OR-NOT-TREE? BOOLEAN) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&and_or_not_treeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-WALK-BOOLEAN-TREE", "CONS", "(DEFUN (HELP-WALK-BOOLEAN-TREE OBJECT) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&help_walk_boolean_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-COND-TREE", "CONS", "(DEFUN (WALK-COND-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_cond_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("COND-TREE-TO-IF-TREE", "CONS", "(DEFUN (COND-TREE-TO-IF-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cond_tree_to_if_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-HARDCODED-CASE-SYMBOL-ID-OR-IDS", "OBJECT", "(DEFUN (YIELD-HARDCODED-CASE-SYMBOL-ID-OR-IDS OBJECT) ((CASETEST OBJECT)))");

              method->function_code = ((cpp_function_code)(&yield_hardcoded_case_symbol_id_or_ids));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-HARDCODED-SYMBOL-CASE-TREE", "CONS", "(DEFUN (WALK-HARDCODED-SYMBOL-CASE-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_hardcoded_symbol_case_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-COND-TEST", "OBJECT", "(DEFUN (YIELD-COND-TEST CONS) ((CASETEST OBJECT) (TESTVARIABLE SYMBOL) (EQUALITYTEST SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_cond_test));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-COND-TEST-OR-TESTS", "OBJECT", "(DEFUN (YIELD-COND-TEST-OR-TESTS OBJECT) ((CASETEST OBJECT) (TESTVARIABLE SYMBOL) (EQUALITYTEST SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_cond_test_or_tests));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-NON-BUILT-IN-CASE-TREE", "CONS", "(DEFUN (WALK-NON-BUILT-IN-CASE-TREE CONS TYPE-SPEC) ((TREE CONS) (EQUALITYTEST SYMBOL)))");

              method->function_code = ((cpp_function_code)(&walk_non_built_in_case_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-CASE-TREE", "CONS", "(DEFUN (WALK-CASE-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_case_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-TYPECASE-TREE", "CONS", "(DEFUN (WALK-TYPECASE-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_typecase_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINISH-WALKING-EQL-TREE", "CONS", "(DEFUN (FINISH-WALKING-EQL-TREE CONS TYPE-SPEC) ((TREE CONS) (TYPE1 TYPE) (TYPE2 TYPE)))");

              method->function_code = ((cpp_function_code)(&finish_walking_eql_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINISH-WALKING-EQUAL-TREE", "CONS", "(DEFUN (FINISH-WALKING-EQUAL-TREE CONS TYPE-SPEC) ((TREE CONS) (TYPE1 TYPE) (TYPE2 TYPE)))");

              method->function_code = ((cpp_function_code)(&finish_walking_equal_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-EQUALITY-TREE", "CONS", "(DEFUN (WALK-EQUALITY-TREE OBJECT TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_equality_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("MORE-GENERAL-NUMERIC-TYPE", "TYPE", "(DEFUN (MORE-GENERAL-NUMERIC-TYPE TYPE) ((TYPE1 TYPE) (TYPE2 TYPE)))");

              method->function_code = ((cpp_function_code)(&more_general_numeric_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-ARITHMETIC-OPERATOR-CALL-TREE", "SYMBOL", "(DEFUN (YIELD-ARITHMETIC-OPERATOR-CALL-TREE CONS) ((OPERATOR SYMBOL) (OPERANDS CONS)))");

              method->function_code = ((cpp_function_code)(&yield_arithmetic_operator_call_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-NESTED-ARITHMETIC-OPERATOR-CALL-TREE", "SYMBOL", "(DEFUN (YIELD-NESTED-ARITHMETIC-OPERATOR-CALL-TREE CONS) ((OPERATOR SYMBOL) (OPERANDS CONS)))");

              method->function_code = ((cpp_function_code)(&yield_nested_arithmetic_operator_call_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-ARITHMETIC-TREE", "CONS", "(DEFUN (WALK-ARITHMETIC-TREE OBJECT TYPE) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_arithmetic_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-QUOTED-TREE", "CONS", "(DEFUN (WALK-QUOTED-TREE OBJECT TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_quoted_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-BQUOTE-TREE", "CONS", "(DEFUN (WALK-BQUOTE-TREE OBJECT TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_bquote_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXPAND-MACRO", "CONS", "(DEFUN (EXPAND-MACRO OBJECT) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&expand_macro));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-MACRO-TREE", "CONS", "(DEFUN (WALK-MACRO-TREE OBJECT TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_macro_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-PRINT-STREAM-TREE", "CONS", "(DEFUN (WALK-PRINT-STREAM-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_print_stream_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WARN-ABOUT-UNDEFINED-METHODS?", NULL, "(DEFUN (WARN-ABOUT-UNDEFINED-METHODS? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&warn_about_undefined_methodsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WARN-ABOUT-MISSING-METHODS?", NULL, "(DEFUN (WARN-ABOUT-MISSING-METHODS? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&warn_about_missing_methodsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-UNDEFINED-SLOT-TREE", "CONS", "(DEFUN (WALK-UNDEFINED-SLOT-TREE CONS TYPE) ((TREE CONS) (FIRSTARGTYPE TYPE-SPEC) (WARN? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&walk_undefined_slot_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-SLOT-ON-ABSTRACT-TYPE-TREE", "CONS", "(DEFUN (WALK-SLOT-ON-ABSTRACT-TYPE-TREE CONS TYPE-SPEC) ((TREE CONS) (ABSTRACTTYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&walk_slot_on_abstract_type_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-PROTOTYPE-METHOD", "SYMBOL", "(DEFUN (FIND-PROTOTYPE-METHOD METHOD-SLOT) ((METHODNAME SYMBOL) (ABSTRACTTYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&find_prototype_method));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPATIBLE-REAL-METHODS", "METHOD-SLOT", "(DEFUN (COMPATIBLE-REAL-METHODS INTEGER INTEGER BOOLEAN) ((PROTOTYPEMETHOD METHOD-SLOT) (ABSTRACTTYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&compatible_real_methods));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINISH-WALKING-CALL-SLOT-TREE", "SLOT", "(DEFMETHOD (FINISH-WALKING-CALL-SLOT-TREE CONS TYPE-SPEC) ((SELF SLOT) (TREE CONS) (FIRSTARGTYPE TYPE-SPEC)))");

              method->method_code = ((cpp_method_code)(&Slot::finish_walking_call_slot_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINISH-WALKING-CALL-SLOT-TREE", "STORAGE-SLOT", "(DEFMETHOD (FINISH-WALKING-CALL-SLOT-TREE CONS TYPE-SPEC) ((SELF STORAGE-SLOT) (TREE CONS) (FIRSTARGTYPE TYPE-SPEC)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::finish_walking_call_slot_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-LISTIFIED-VARIABLE-ARGUMENTS", "CONS", "(DEFUN (YIELD-LISTIFIED-VARIABLE-ARGUMENTS CONS) ((WALKEDARGS CONS) (TARGETTYPE TYPE-SPEC) (WRAPARGS? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&yield_listified_variable_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-VARIABLE-ARGUMENTS", "CONS", "(DEFUN (WALK-VARIABLE-ARGUMENTS CONS) ((ARGUMENTS CONS) (METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&walk_variable_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINISH-WALKING-CALL-SLOT-TREE", "METHOD-SLOT", "(DEFMETHOD (FINISH-WALKING-CALL-SLOT-TREE CONS TYPE-SPEC) ((SELF METHOD-SLOT) (TREE CONS) (FIRSTARGTYPE TYPE-SPEC)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::finish_walking_call_slot_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("QUOTE-ARGUMENTS", "METHOD-SLOT", "(DEFUN (QUOTE-ARGUMENTS CONS) ((METHOD METHOD-SLOT) (ARGUMENTS CONS)))");

              method->function_code = ((cpp_function_code)(&quote_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-FIRST-ARGUMENT-TO-FUNCTION", "METHOD-SLOT", "(DEFUN (WALK-FIRST-ARGUMENT-TO-FUNCTION TYPE-SPEC) ((FNSLOT METHOD-SLOT) (TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_first_argument_to_function));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-CALL-SLOT-TREE", "CONS", "(DEFUN (WALK-CALL-SLOT-TREE OBJECT TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_call_slot_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SYNTHESIZED-METHOD-BODY", "TRANSLATION-UNIT", "(DEFUN (YIELD-SYNTHESIZED-METHOD-BODY CONS) ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&yield_synthesized_method_body));
            }
            { Method_Slot* method = define_method_from_stringified_source("PASS-VARIABLE-ARGUMENTS-AS-LIST?", "METHOD-SLOT", "(DEFUN (PASS-VARIABLE-ARGUMENTS-AS-LIST? BOOLEAN) ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&pass_variable_arguments_as_listP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TOGGLE-VARIABLE-ARGUMENTS-TYPE", "METHOD-SLOT", "(DEFUN TOGGLE-VARIABLE-ARGUMENTS-TYPE ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&toggle_variable_arguments_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("VARIABLE-ARGUMENTS-TYPE", "METHOD-SLOT", "(DEFUN (VARIABLE-ARGUMENTS-TYPE TYPE-SPEC) ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&variable_arguments_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-METHOD-OBJECT", "TRANSLATION-UNIT", "(DEFUN (WALK-METHOD-OBJECT CONS) ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&walk_method_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-DEFMETHOD-TREE", "CONS", "(DEFUN WALK-DEFMETHOD-TREE ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_defmethod_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-INITIALIZE-SLOT-WRITER", "METHOD-SLOT", "(DEFUN (YIELD-INITIALIZE-SLOT-WRITER CONS) ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_initialize_slot_writer));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-METHOD-UNIT", "TRANSLATION-UNIT", "(DEFUN WALK-METHOD-UNIT ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&walk_method_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-SYS-CALL-TREE", "CONS", "(DEFUN (WALK-SYS-CALL-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_sys_call_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-DEFCLASS-TREE", "CONS", "(DEFUN WALK-DEFCLASS-TREE ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_defclass_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-INITIALIZE-HARDWIRED-SLOTS", "CLASS", "(DEFUN (YIELD-INITIALIZE-HARDWIRED-SLOTS CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_initialize_hardwired_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-INITIAL-VALUE-EXPRESSION", "STORAGE-SLOT", "(DEFUN (YIELD-INITIAL-VALUE-EXPRESSION OBJECT) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_initial_value_expression));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CONSTRUCTOR-ATTACHMENT", "CLASS", "(DEFUN (YIELD-CONSTRUCTOR-ATTACHMENT CONS) ((CLASS CLASS) (CLASSREF SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_constructor_attachment));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-SLOT-ACCESSOR-METHODS", "STORAGE-SLOT", "(DEFUN CLEAR-SLOT-ACCESSOR-METHODS ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&clear_slot_accessor_methods));
            }
            { Method_Slot* method = define_method_from_stringified_source("REGISTER-SLOT-ACCESSOR-METHOD", "STORAGE-SLOT", "(DEFUN REGISTER-SLOT-ACCESSOR-METHOD ((SLOT STORAGE-SLOT) (METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&register_slot_accessor_method));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-ACCESSOR-UNITS-FOR-SLOT", "STORAGE-SLOT", "(DEFUN CREATE-ACCESSOR-UNITS-FOR-SLOT ((SLOT STORAGE-SLOT) (CLASS CLASS) (NATIVEACCESSORS? BOOLEAN) (SIGNATURESONLY? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&create_accessor_units_for_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-ACCESSOR-UNITS-FOR-MIXIN-SLOT", "STORAGE-SLOT", "(DEFUN CREATE-ACCESSOR-UNITS-FOR-MIXIN-SLOT ((SLOT STORAGE-SLOT) (CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&create_accessor_units_for_mixin_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-SLOT-ACCESSOR-UNITS", "CLASS", "(DEFUN CREATE-SLOT-ACCESSOR-UNITS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&create_slot_accessor_units));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-INLINE-METHOD-UNITS", "CLASS", "(DEFUN CREATE-INLINE-METHOD-UNITS ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&create_inline_method_units));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-DEFPRINT-UNIT", "CLASS", "(DEFUN CREATE-DEFPRINT-UNIT ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&create_defprint_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-CLASS-UNIT", "TRANSLATION-UNIT", "(DEFUN WALK-CLASS-UNIT ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&walk_class_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-FINALIZATION-UNITS", NULL, "(DEFUN CREATE-FINALIZATION-UNITS ())");

              method->function_code = ((cpp_function_code)(&create_finalization_units));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-DEFSLOT-TREE", "CONS", "(DEFUN WALK-DEFSLOT-TREE ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_defslot_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-SLOT-UNIT", "TRANSLATION-UNIT", "(DEFUN WALK-SLOT-UNIT ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&walk_slot_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-MACRO", "SYMBOL", "(DEFUN (LOOKUP-MACRO METHOD-SLOT) ((NAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&lookup_macro));
            }
            { Method_Slot* method = define_method_from_stringified_source("STORE-MACRO", "SYMBOL", "(DEFUN STORE-MACRO ((NAME SYMBOL) (EXPANDERNAME SYMBOL) (EXPANDERCODE FUNCTION-CODE)))");

              method->function_code = ((cpp_function_code)(&store_macro));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-MACRO-EXPANDER-FUNCTION-NAME", "SYMBOL", "(DEFUN (YIELD-MACRO-EXPANDER-FUNCTION-NAME SYMBOL) ((MACRONAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_macro_expander_function_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-DEFMACRO-TREE", "CONS", "(DEFUN WALK-DEFMACRO-TREE ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_defmacro_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-MACRO-UNIT", "TRANSLATION-UNIT", "(DEFUN WALK-MACRO-UNIT ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&walk_macro_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-DEFGLOBAL-TREE", "CONS", "(DEFUN WALK-DEFGLOBAL-TREE ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_defglobal_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-GLOBAL-UNIT", "TRANSLATION-UNIT", "(DEFUN WALK-GLOBAL-UNIT ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&walk_global_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-DEFTYPE-TREE", "CONS", "(DEFUN WALK-DEFTYPE-TREE ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_deftype_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-TYPE-UNIT", "TRANSLATION-UNIT", "(DEFUN WALK-TYPE-UNIT ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&walk_type_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-STARTUP-TIME-PROGN-TREE", "CONS", "(DEFUN WALK-STARTUP-TIME-PROGN-TREE ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_startup_time_progn_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-STARTUP-TIME-PHASE", "CONS", "(DEFUN (EXTRACT-STARTUP-TIME-PHASE KEYWORD) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&extract_startup_time_phase));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-STARTUP-TIME-PROGN-UNIT", "TRANSLATION-UNIT", "(DEFUN WALK-STARTUP-TIME-PROGN-UNIT ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&walk_startup_time_progn_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMBINE-STARTUP-FUNCTION-UNITS", NULL, "(DEFUN (COMBINE-STARTUP-FUNCTION-UNITS CONS) ())");

              method->function_code = ((cpp_function_code)(&combine_startup_function_units));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-STARTUP-FUNCTION-UNIT", "SYMBOL", "(DEFUN CREATE-STARTUP-FUNCTION-UNIT ((STARTUPFNNAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&create_startup_function_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("DONT-GENERATE-STARTUP-CODE?", NULL, "(DEFUN (DONT-GENERATE-STARTUP-CODE? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&dont_generate_startup_codeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-ALL-STARTUP-TIME-PROGN-UNITS", NULL, "(DEFUN REMOVE-ALL-STARTUP-TIME-PROGN-UNITS ())");

              method->function_code = ((cpp_function_code)(&remove_all_startup_time_progn_units));
            }
            { Method_Slot* method = define_method_from_stringified_source("USE-STELLA-EXCEPTIONS?", NULL, "(DEFUN (USE-STELLA-EXCEPTIONS? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&use_stella_exceptionsP));
            }
            define_method_from_stringified_source("SETUP-LONG-JUMP?", "NATIVE-ENVIRONMENT-POINTER", "(DEFUN (SETUP-LONG-JUMP? BOOLEAN) ((ENVIRONMENT NATIVE-ENVIRONMENT-POINTER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("LONG-JUMP", "NATIVE-ENVIRONMENT-POINTER", "(DEFUN LONG-JUMP ((ENVIRONMENT NATIVE-ENVIRONMENT-POINTER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("CATCH", "NATIVE-ENVIRONMENT-POINTER", "(DEFUN (CL:CATCH BOOLEAN) ((TAG NATIVE-ENVIRONMENT-POINTER) (BODY VOID)) :NATIVE? TRUE)");
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL", "EXCEPTION", "(DEFUN SIGNAL ((EXCEPTION EXCEPTION)) :PUBLIC? TRUE :DOCUMENTATION \"Signal an 'exception'.  Signal an error if there is\nno pending exception handler that can handle 'exception'.\")");

              method->function_code = ((cpp_function_code)(&signal));
            }
            { Method_Slot* method = define_method_from_stringified_source("RESIGNAL", NULL, "(DEFUN RESIGNAL () :PUBLIC? TRUE :DOCUMENTATION \"Resignal the most recently re/signalled exception.\nSignal an error if there is no pending exception handler that can handle it.\")");

              method->function_code = ((cpp_function_code)(&resignal));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-EXCEPTION-CASE-TREE", "CONS", "(DEFUN (WALK-EXCEPTION-CASE-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_exception_case_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("LEXICALLY-VISIBLE-EXCEPTION-CASE?", NULL, "(DEFUN (LEXICALLY-VISIBLE-EXCEPTION-CASE? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&lexically_visible_exception_caseP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-PROTECTED-STATEMENT-TREE", "OBJECT", "(DEFUN (YIELD-PROTECTED-STATEMENT-TREE CONS) ((TREE OBJECT) (UNWINDPROTECT? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&yield_protected_statement_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-EXCEPTION-HANDLER-TREE", "CONS", "(DEFUN (YIELD-EXCEPTION-HANDLER-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&yield_exception_handler_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-VERBATIM-DEFINITION-TREE", "CONS", "(DEFUN WALK-VERBATIM-DEFINITION-TREE ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_verbatim_definition_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-VERBATIM-UNIT", "TRANSLATION-UNIT", "(DEFUN WALK-VERBATIM-UNIT ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&walk_verbatim_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-VERBATIM-TREE", "CONS", "(DEFUN (WALK-VERBATIM-TREE OBJECT TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_verbatim_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-DEFMODULE-TREE", "CONS", "(DEFUN WALK-DEFMODULE-TREE ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_defmodule_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-MODULE-UNIT", "TRANSLATION-UNIT", "(DEFUN WALK-MODULE-UNIT ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&walk_module_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-REQUIRED-ARGUMENT-VALUES", "CLASS", "(DEFUN (EXTRACT-REQUIRED-ARGUMENT-VALUES CONS) ((CLASS CLASS) (SLOTNAMESANDVALUES PROPERTY-LIST)))");

              method->function_code = ((cpp_function_code)(&extract_required_argument_values));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-NEW-ARGUMENTS-TREE", "CONS", "(DEFUN (YIELD-NEW-ARGUMENTS-TREE CONS CONS) ((KEYWORDSANDVALUES CONS) (CLASS CLASS) (SELFVARIABLE SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_new_arguments_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-NEW-TREE", "CONS", "(DEFUN (WALK-NEW-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_new_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-MAKE-TREE", "CONS", "(DEFUN (WALK-MAKE-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_make_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-FUNCALL-TREE", "CONS", "(DEFUN (WALK-FUNCALL-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_funcall_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-THE-CODE-TREE", "CONS", "(DEFUN (WALK-THE-CODE-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_the_code_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("DE-UGLIFY-ARGUMENTS", "CONS", "(DEFUN (DE-UGLIFY-ARGUMENTS CONS) ((UGLYARGUMENTS CONS)))");

              method->function_code = ((cpp_function_code)(&de_uglify_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("DE-UGLIFY-PARSE-TREE", "OBJECT", "(DEFUN (DE-UGLIFY-PARSE-TREE OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&de_uglify_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("REGISTER-NATIVE-NAME", "SYMBOL", "(DEFUN REGISTER-NATIVE-NAME ((NAME SYMBOL) (LANGUAGE KEYWORD) (CATEGORY KEYWORD)))");

              method->function_code = ((cpp_function_code)(&register_native_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("NATIVE-NAME?", "SYMBOL", "(DEFUN (NATIVE-NAME? BOOLEAN) ((NAME SYMBOL) (LANGUAGE KEYWORD) (CATEGORY KEYWORD)))");

              method->function_code = ((cpp_function_code)(&native_nameP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-RENAMED-NAME-IF-NATIVE", "SYMBOL", "(DEFUN (YIELD-RENAMED-NAME-IF-NATIVE SYMBOL) ((NAME SYMBOL) (LANGUAGE KEYWORD) (CATEGORY KEYWORD)))");

              method->function_code = ((cpp_function_code)(&yield_renamed_name_if_native));
            }
            { Method_Slot* method = define_method_from_stringified_source("METHOD-NEEDS-LISP-MACRO?", "METHOD-SLOT", "(DEFUN (METHOD-NEEDS-LISP-MACRO? BOOLEAN) ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&method_needs_lisp_macroP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-LISP-MACRO-TREES", "SYMBOL", "(DEFUN (YIELD-LISP-MACRO-TREES CONS CONS) ((NAME SYMBOL) (METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_lisp_macro_trees));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-LISP-MACRO-UNITS", "SYMBOL", "(DEFUN CREATE-LISP-MACRO-UNITS ((NAME SYMBOL) (METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&create_lisp_macro_units));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMMAND?", "METHOD-SLOT", "(DEFUN (COMMAND? BOOLEAN) ((METHOD METHOD-SLOT)) :DOCUMENTATION \"Return TRUE if 'method' is an evaluable command.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&commandP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-COMMAND", "SYMBOL", "(DEFUN (LOOKUP-COMMAND METHOD-SLOT) ((NAME SYMBOL)) :DOCUMENTATION \"If 'name' names an evaluable command return its associated\ncommand object;  otherwise, return NULL.  Currently, commands are not\npolymorphic, i.e., they can only be implemented by functions.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&lookup_command));
            }
            { Method_Slot* method = define_method_from_stringified_source("METHOD-MUST-BE-EVALUABLE?", "METHOD-SLOT", "(DEFUN (METHOD-MUST-BE-EVALUABLE? BOOLEAN) ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&method_must_be_evaluableP));
            }
            { Method_Slot* method = define_method_from_stringified_source("METHOD-NEEDS-EVALUATOR-WRAPPER?", "METHOD-SLOT", "(DEFUN (METHOD-NEEDS-EVALUATOR-WRAPPER? BOOLEAN) ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&method_needs_evaluator_wrapperP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-EVALUATOR-WRAPPER-NAME", "SYMBOL", "(DEFUN (YIELD-EVALUATOR-WRAPPER-NAME SYMBOL) ((METHODNAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_evaluator_wrapper_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-ARGUMENT-ACCESS-TREE", "SYMBOL", "(DEFUN (YIELD-ARGUMENT-ACCESS-TREE OBJECT) ((ARGUMENTSVARIABLE SYMBOL) (INDEX INTEGER) (RESTARGUMENT? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&yield_argument_access_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-EVALUATOR-WRAPPER-TREE", "METHOD-SLOT", "(DEFUN (YIELD-EVALUATOR-WRAPPER-TREE CONS) ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_evaluator_wrapper_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-EVALUATOR-WRAPPER-UNIT", "METHOD-SLOT", "(DEFUN CREATE-EVALUATOR-WRAPPER-UNIT ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&create_evaluator_wrapper_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("RESET-EVALUATION-ERROR", NULL, "(DEFUN RESET-EVALUATION-ERROR () :DOCUMENTATION \"Reset the global evaluation error indicator.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&reset_evaluation_error));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIGNAL-EVALUATION-ERROR", NULL, "(DEFUN SIGNAL-EVALUATION-ERROR () :DOCUMENTATION \"Signal an evaluation error.  This is done automatically\nby calling 'eval-error'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&signal_evaluation_error));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATION-ERROR?", NULL, "(DEFUN (EVALUATION-ERROR? BOOLEAN) () :DOCUMENTATION \"Return TRUE if the global evaluation error indicator is set.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&evaluation_errorP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-EVALUATION-ERROR-CONTEXT", "STRING", "(DEFUN PRINT-EVALUATION-ERROR-CONTEXT ((PREFIX STRING) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_evaluation_error_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE", "OBJECT", "(DEFUN (EVALUATE OBJECT TYPE-SPEC BOOLEAN) ((EXPRESSION OBJECT)) :DOCUMENTATION \"Evaluate the expression `expression' and return the result.\nCurrently, only the evaluation of (possibly nested) commands and global\nvariables is supported.  The second return value indicates the actual type \nof the result (which might have been wrapped), and the third return value\nindicates whether an error occurred during the evaluation.\" :LISP-MACRO? TRUE :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&evaluate));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-STRING", "STRING", "(DEFUN (EVALUATE-STRING OBJECT TYPE-SPEC BOOLEAN) ((EXPRESSION STRING)) :DOCUMENTATION \"Evaluate the expression represented by `expression' and return the result.\nThis is equivalent to `(evaluate (unstringify expression))'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&evaluate_string));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRY-TO-EVALUATE", "OBJECT", "(DEFUN (TRY-TO-EVALUATE OBJECT TYPE-SPEC BOOLEAN) ((TREE OBJECT)) :DOCUMENTATION \"Variant of 'evaluate' that only evaluates 'tree' if it\nrepresents an evaluable expression.  If it does not, 'tree' is returned\nunmodified.  This can be used to implement commands with mixed argument\nevaluation strategies.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&try_to_evaluate));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-CONS-TREE", "CONS", "(DEFUN (EVALUATE-CONS-TREE OBJECT TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&evaluate_cons_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-ARGUMENT-TREE", "OBJECT", "(DEFUN (EVALUATE-ARGUMENT-TREE OBJECT TYPE-SPEC) ((TREE OBJECT) (EVALUATE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&evaluate_argument_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVALUATE-ATOMIC-TREE", "OBJECT", "(DEFUN (EVALUATE-ATOMIC-TREE OBJECT TYPE-SPEC) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&evaluate_atomic_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("COERCE-EVALUATED-TREE", "OBJECT", "(DEFUN (COERCE-EVALUATED-TREE OBJECT TYPE-SPEC) ((TREE OBJECT) (SOURCETREE OBJECT) (SOURCETYPE TYPE-SPEC) (TARGETTYPE TYPE-SPEC) (EVALUATE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&coerce_evaluated_tree));
            }
            define_method_from_stringified_source("STARTUP-WALK", NULL, "(DEFUN STARTUP-WALK ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *AVAILABLE-ENVIRONMENT-FEATURES* (LIST OF KEYWORD) (CAST (LIST :WARN-ABOUT-UNDEFINED-METHODS :SUPPRESS-WARNINGS :USE-BOOTSTRAP-TRANSLATOR :WARN-ABOUT-MISSING-METHODS :USE-HARDCODED-SYMBOLS :USE-COMMON-LISP-STRUCTS :USE-COMMON-LISP-VECTOR-STRUCTS :USE-CPP-GARBAGE-COLLECTOR :TRANSLATE-WITH-COPYRIGHT-HEADER) (LIST OF KEYWORD)) :DOCUMENTATION \"List of Stella environment features.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CURRENT-ENVIRONMENT-FEATURES* (LIST OF KEYWORD) (NEW (LIST OF KEYWORD)) :DOCUMENTATION \"List of currently enabled environment features.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEFAULT-ENVIRONMENT-FEATURES* (LIST OF KEYWORD) (CAST (LIST :WARN-ABOUT-UNDEFINED-METHODS :WARN-ABOUT-MISSING-METHODS :USE-CPP-GARBAGE-COLLECTOR) (LIST OF KEYWORD)) :DOCUMENTATION \"List of features enabled upon call to\n'reset-environment-features'.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *TRACED-KEYWORDS* (LIST OF KEYWORD) NULL)");
            store_macro(SYM_WALK_TRACE_IF, SYM_WALK_TRACE_IF_EXPANDER, ((cpp_function_code)(&trace_if_expander)));
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *QUOTATION-TABLE* (STRING-HASH-TABLE OF STRING CONS) NULL :DOCUMENTATION \"Stores quoted cons trees.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *TRANSLATIONUNITS* (LIST OF TRANSLATION-UNIT) NULL :DOCUMENTATION \"List of objects representing partially walked\ntop-level definitions and auxiliary code.\")");
            { Global_Variable* global = SYM_WALK_oTRANSLATIONUNITSo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OtranslationunitsO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OtranslationunitsO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *CURRENTTRANSLATIONUNIT* TRANSLATION-UNIT NULL :DOCUMENTATION \"The translation unit currently operated on.\")");
            { Global_Variable* global = SYM_WALK_oCURRENTTRANSLATIONUNITo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OcurrenttranslationunitO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OcurrenttranslationunitO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *TRANSLATIONPHASE* KEYWORD NULL :DOCUMENTATION \"Indicates the current translation phase which is one of\n:DEFINE, :FINALIZE, :WALK, or :TRANSLATE.\")");
            { Global_Variable* global = SYM_WALK_oTRANSLATIONPHASEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OtranslationphaseO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OtranslationphaseO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *TRANSLATIONVERBOSITYLEVEL* INTEGER 1 :DOCUMENTATION \"The higher the level, the more progress annotations are\ngenerated during the translation of Stella declarations.\")");
            { Global_Variable* global = SYM_WALK_oTRANSLATIONVERBOSITYLEVELo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OtranslationverbositylevelO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OtranslationverbositylevelO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *USEHARDCODEDSYMBOLS?* BOOLEAN FALSE)");
            { Global_Variable* global = SYM_WALK_oUSEHARDCODEDSYMBOLSpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OusehardcodedsymbolsPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OusehardcodedsymbolsPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *LOCALVARIABLETYPETABLE* (KEY-VALUE-LIST OF SYMBOL TYPE-SPEC) :UNBOUND-SPECIAL-VARIABLE :DOCUMENTATION \"Table mapping local variable names their declared types\n(declared explicitly or implicitly).\")");
            { Global_Variable* global = SYM_WALK_oLOCALVARIABLETYPETABLEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OlocalvariabletypetableO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OlocalvariabletypetableO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *METHODBEINGWALKED* METHOD-SLOT NULL :DOCUMENTATION \"Contains the method or function being walked, or else NULL.\")");
            { Global_Variable* global = SYM_WALK_oMETHODBEINGWALKEDo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OmethodbeingwalkedO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OmethodbeingwalkedO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *FOUNDRETURN?* BOOLEAN FALSE :DOCUMENTATION \"Indicates that one or more return statements have been found\nduring the walk of the current method.\")");
            { Global_Variable* global = SYM_WALK_oFOUNDRETURNpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OfoundreturnPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OfoundreturnPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *TARGETTYPE* TYPE-SPEC @VOID :DOCUMENTATION \"Bound to the target type for an expression currently walked.\nUsed instead of an extra argument to 'walk-a-tree', since only a few types\nof expressions need to know about their expected type (e.g., FUNCALL).\")");
            { Global_Variable* global = SYM_WALK_oTARGETTYPEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OtargettypeO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OtargettypeO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *LOCALGENSYMTABLE* (KEY-VALUE-LIST OF SYMBOL INTEGER-WRAPPER) NULL :DOCUMENTATION \"Table that maps each prefix of a function-local gensym\nto its own gensym counter.\")");
            { Global_Variable* global = SYM_WALK_oLOCALGENSYMTABLEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OlocalgensymtableO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OlocalgensymtableO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *TRANSLATIONERRORS* INTEGER 0)");
            { Global_Variable* global = SYM_WALK_oTRANSLATIONERRORSo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OtranslationerrorsO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OtranslationerrorsO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *TRANSLATIONWARNINGS* INTEGER 0)");
            { Global_Variable* global = SYM_WALK_oTRANSLATIONWARNINGSo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OtranslationwarningsO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OtranslationwarningsO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *IGNORETRANSLATIONERRORS?* BOOLEAN TRUE :DOCUMENTATION \"If TRUE all passes of a translation will always be performed\nregardless of whether any errors were encountered.  Otherwise, translation\nends with the first pass that encountered an error.\" :PUBLIC? TRUE)");
            { Global_Variable* global = SYM_WALK_oIGNORETRANSLATIONERRORSpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OignoretranslationerrorsPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OignoretranslationerrorsPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *WRAPPED-TYPE-TABLE* (CONS OF CONS) (BQUOTE ((@INTEGER-WRAPPER @INTEGER) (@TRANSIENT-INTEGER-WRAPPER @INTEGER) (@FLOAT-WRAPPER @FLOAT) (@TRANSIENT-FLOAT-WRAPPER @FLOAT) (@NUMBER-WRAPPER @NUMBER) (@STRING-WRAPPER @STRING) (@TRANSIENT-STRING-WRAPPER @STRING) (@CHARACTER-WRAPPER @CHARACTER) (@TRANSIENT-CHARACTER-WRAPPER @CHARACTER) (@BOOLEAN-WRAPPER @BOOLEAN) (@FUNCTION-CODE-WRAPPER @FUNCTION-CODE) (@TRANSIENT-FUNCTION-CODE-WRAPPER @FUNCTION-CODE) (@METHOD-CODE-WRAPPER @METHOD-CODE) (@TRANSIENT-METHOD-CODE-WRAPPER @METHOD-CODE))) :DOCUMENTATION \"Table of pairs used by 'wrapper-value-type' and\n'type-to-wrapped-type'.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *COERSION-TABLE* (CONS OF CONS) (BQUOTE ((@BOOLEAN @BOOLEAN-WRAPPER WRAP-BOOLEAN) (@INTEGER @INTEGER-WRAPPER WRAP-LITERAL) (@INTEGER @BOOLEAN-WRAPPER INTEGER-TO-BOOLEAN-WRAPPER) (@INTEGER @BOOLEAN INTEGER-TO-BOOLEAN) (@FLOAT @FLOAT-WRAPPER WRAP-LITERAL) (@STRING @STRING-WRAPPER WRAP-LITERAL) (@STRING @SYMBOL INTERN-SYMBOL) (@CHARACTER @CHARACTER-WRAPPER WRAP-LITERAL) (@FUNCTION-CODE @FUNCTION-CODE-WRAPPER WRAP-LITERAL) (@METHOD-CODE @METHOD-CODE-WRAPPER WRAP-LITERAL) (@SYMBOL @STRING SYMBOL-NAME) (@BOOLEAN-WRAPPER @BOOLEAN WRAPPER-VALUE) (@INTEGER-WRAPPER @INTEGER WRAPPER-VALUE) (@FLOAT-WRAPPER @FLOAT WRAPPER-VALUE) (@STRING-WRAPPER @STRING WRAPPER-VALUE) (@CHARACTER-WRAPPER @CHARACTER WRAPPER-VALUE) (@FUNCTION-CODE-WRAPPER @FUNCTION-CODE WRAPPER-VALUE) (@METHOD-CODE-WRAPPER @METHOD-CODE WRAPPER-VALUE) (@SURROGATE @CLASS SURROGATE-VALUE) (@SURROGATE @MODULE SURROGATE-VALUE) (@INPUT-STREAM @NATIVE-INPUT-STREAM NATIVE-STREAM) (@OUTPUT-STREAM @NATIVE-OUTPUT-STREAM NATIVE-STREAM) (@NUMBER @INTEGER IDENTITY) (@NUMBER @FLOAT IDENTITY) (@INTEGER @FLOAT IDENTITY) (@INTEGER @SINGLE-FLOAT IDENTITY) (@FLOAT @SINGLE-FLOAT IDENTITY) (@FLOAT @DOUBLE-FLOAT IDENTITY) (@INTEGER @SHORT-INTEGER IDENTITY) (@INTEGER @LONG-INTEGER IDENTITY) (@INTEGER @UNSIGNED-SHORT-INTEGER IDENTITY) (@INTEGER @UNSIGNED-LONG-INTEGER IDENTITY))) :DOCUMENTATION \"Table of triples used by 'lookup-coersion-method' to\nlocate a coersion method.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *SYMBOL-REGISTRY* (HASH-TABLE OF GENERALIZED-SYMBOL GENERALIZED-SYMBOL) (NEW (HASH-TABLE OF GENERALIZED-SYMBOL GENERALIZED-SYMBOL)))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *SYMBOL-SET* (LIST OF GENERALIZED-SYMBOL) (NEW (LIST OF GENERALIZED-SYMBOL)))");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *CURRENTFILE* STRING NULL :DOCUMENTATION \"Name of file that is currently being translated.\nA NULL value indicates an incremental translation.\")");
            { Global_Variable* global = SYM_WALK_oCURRENTFILEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OcurrentfileO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OcurrentfileO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *SPECIALVARIABLESTACK* (KEY-VALUE-LIST OF SYMBOL SYMBOL) (NEW (KEY-VALUE-LIST OF SYMBOL SYMBOL)) :DOCUMENTATION \"Stack mirroring the current state of bound specials\nwith their associated old-value variables.\")");
            { Global_Variable* global = SYM_WALK_oSPECIALVARIABLESTACKo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OspecialvariablestackO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OspecialvariablestackO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *SPECIALSENABLED?* BOOLEAN TRUE :DOCUMENTATION \"TRUE if using specials is enabled and legal.\")");
            { Global_Variable* global = SYM_WALK_oSPECIALSENABLEDpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OspecialsenabledPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OspecialsenabledPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *NOFSPECIALSATLOOPENTRY* INTEGER 0 :DOCUMENTATION \"Number of specials bound at the most recent entry\nto a LOOP/WHILE/FOREACH construct.\")");
            { Global_Variable* global = SYM_WALK_oNOFSPECIALSATLOOPENTRYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OnofspecialsatloopentryO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OnofspecialsatloopentryO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *TYPE-PREDICATE-TABLE* (CONS OF CONS) (BQUOTE ((@BOOLEAN BOOLEAN?) (@INTEGER INTEGER?) (@FLOAT FLOAT?) (@STRING STRING?) (@CHARACTER CHARACTER?) (@WRAPPER WRAPPER?) (@BOOLEAN-WRAPPER BOOLEAN?) (@INTEGER-WRAPPER INTEGER?) (@FLOAT-WRAPPER FLOAT?) (@STRING-WRAPPER STRING?) (@CHARACTER-WRAPPER CHARACTER?) (@VERBATIM-STRING-WRAPPER VERBATIM-STRING?) (@SURROGATE SURROGATE?) (@TYPE TYPE?) (@SYMBOL SYMBOL?) (@TRANSIENT-SYMBOL TRANSIENT-SYMBOL?) (@KEYWORD KEYWORD?) (@CONS CONS?) (@CLASS CLASS?) (@STORAGE-SLOT STORAGE-SLOT?) (@METHOD-SLOT METHOD-SLOT?) (@ANCHORED-TYPE-SPECIFIER ANCHORED-TYPE-SPECIFIER?) (@PARAMETRIC-TYPE-SPECIFIER PARAMETRIC-TYPE-SPECIFIER?))) :DOCUMENTATION \"Table of specialized type predicates for various types.\nThese predicates have to be used instead of 'isa?', since they also work\nduring bootstrap when only some class objects are defined.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *NUMERIC-TYPE-HIERARCHY* (LIST OF TYPE) (LIST @INTEGER @FLOAT @NUMBER))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *MACRO-TABLE* (HASH-TABLE OF SYMBOL CONS) (NEW (HASH-TABLE OF SYMBOL CONS)) :DOCUMENTATION \"Associates macro names with the name and code of\ntheir expander function.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *EXCEPTIONHANDLERADDRESS* NATIVE-ENVIRONMENT-POINTER (VERBATIM :COMMON-LISP \":exception-handler\" :CPP \"NULL\") :DOCUMENTATION \"Points to the address of the most recently established\nStella exception handler.  For Common-Lisp this variable never gets rebound.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *PENDINGEXCEPTIONHANDLER?* BOOLEAN FALSE :DOCUMENTATION \"TRUE if at least one exception handler is pending.\")");
            { Global_Variable* global = SYM_WALK_oPENDINGEXCEPTIONHANDLERpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OpendingexceptionhandlerPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OpendingexceptionhandlerPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *EXCEPTION* EXCEPTION NULL :DOCUMENTATION \"The most recently signalled exception.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *EXCEPTION-TYPE* TYPE NULL :DOCUMENTATION \"The type of the most recently signalled exception.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *NATIVE-NAME-TABLE* (HASH-TABLE OF SYMBOL (KEY-VALUE-LIST OF KEYWORD LIST)) (NEW HASH-TABLE))");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *EVALUATIONERROR?* BOOLEAN FALSE)");
            { Global_Variable* global = SYM_WALK_oEVALUATIONERRORpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OevaluationerrorPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OevaluationerrorPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *EVALUATIONTREE* OBJECT NULL)");
            { Global_Variable* global = SYM_WALK_oEVALUATIONTREEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OevaluationtreeO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OevaluationtreeO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *EVALUATIONPARENTTREE* OBJECT NULL)");
            { Global_Variable* global = SYM_WALK_oEVALUATIONPARENTTREEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OevaluationparenttreeO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OevaluationparenttreeO));
            }
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

