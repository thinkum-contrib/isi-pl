// literals.hh

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
Object* lookup_literal_type_info(Surrogate* type, Keyword* key);
void set_literal_type_info(Surrogate* type, Keyword* key, Object* value);
Boolean_Wrapper* wrap_boolean(boolean value);
Integer_Wrapper* wrap_integer(int value);
Float_Wrapper* wrap_float(double value);
String_Wrapper* wrap_string(char* value);
Character_Wrapper* wrap_character(char value);
Function_Code_Wrapper* wrap_function_code(cpp_function_code value);
Method_Code_Wrapper* wrap_method_code(cpp_method_code value);
Integer_Wrapper* integer_wrap_literal(int value);
Float_Wrapper* float_wrap_literal(double value);
String_Wrapper* string_wrap_literal(char* value);
Character_Wrapper* character_wrap_literal(char value);
Function_Code_Wrapper* function_code_wrap_literal(cpp_function_code value);
Method_Code_Wrapper* method_code_wrap_literal(cpp_method_code value);
boolean eqlP(Object* x, Object* y);
boolean eql_to_booleanP(Object* y, boolean x);
boolean eql_to_integerP(Object* y, int x);
boolean eql_to_floatP(Object* y, double x);
boolean eql_to_stringP(Object* y, char* x);
boolean eql_to_characterP(Object* y, char x);
Object* help_bquotify(Object* tree);
Object* bquotify(Object* tree);
Object* expand_bquote_tree(Object* tree);
Object* simplify_bquote_tree(Object* tree);
Object* permanent_copy(Object* tree);
void print_character(char renamed_Char, ostream* stream);
char upcase_character(char renamed_Char);
char downcase_character(char renamed_Char);
void print_string_readably(char* string, ostream* stream);
void startup_literals();

// Global declarations:
extern Integer_Wrapper* ZERO_WRAPPER;
extern Integer_Wrapper* ONE_WRAPPER;
extern Boolean_Wrapper* FALSE_WRAPPER;
extern Boolean_Wrapper* TRUE_WRAPPER;
extern Boolean_Wrapper* NULL_BOOLEAN_WRAPPER;
extern Integer_Wrapper* NULL_INTEGER_WRAPPER;
extern Float_Wrapper* NULL_FLOAT_WRAPPER;
extern String_Wrapper* NULL_STRING_WRAPPER;
extern Character_Wrapper* NULL_CHARACTER_WRAPPER;
extern Function_Code_Wrapper* NULL_FUNCTION_CODE_WRAPPER;
extern Method_Code_Wrapper* NULL_METHOD_CODE_WRAPPER;
extern Hash_Table* oLITERAL_TYPE_INFO_TABLEo;
extern List* oLITERAL_TYPESo;
extern Surrogate* SGT_LITERALS_BOOLEAN;
extern Keyword* KWD_LITERALS_NULL_WRAPPER;
extern Symbol* SYM_LITERALS_NULL_BOOLEAN_WRAPPER;
extern Surrogate* SGT_LITERALS_INTEGER;
extern Symbol* SYM_LITERALS_NULL_INTEGER_WRAPPER;
extern Surrogate* SGT_LITERALS_FLOAT;
extern Symbol* SYM_LITERALS_NULL_FLOAT_WRAPPER;
extern Surrogate* SGT_LITERALS_STRING;
extern Symbol* SYM_LITERALS_NULL_STRING_WRAPPER;
extern Surrogate* SGT_LITERALS_CHARACTER;
extern Symbol* SYM_LITERALS_NULL_CHARACTER_WRAPPER;
extern Surrogate* SGT_LITERALS_FUNCTION_CODE;
extern Symbol* SYM_LITERALS_NULL_FUNCTION_CODE_WRAPPER;
extern Surrogate* SGT_LITERALS_METHOD_CODE;
extern Symbol* SYM_LITERALS_NULL_METHOD_CODE_WRAPPER;
extern Keyword* KWD_LITERALS_WRAP_FUNCTION;
extern Symbol* SYM_LITERALS_WRAP_BOOLEAN;
extern Symbol* SYM_LITERALS_WRAP_INTEGER;
extern Symbol* SYM_LITERALS_WRAP_FLOAT;
extern Symbol* SYM_LITERALS_WRAP_STRING;
extern Symbol* SYM_LITERALS_WRAP_CHARACTER;
extern Symbol* SYM_LITERALS_WRAP_FUNCTION_CODE;
extern Symbol* SYM_LITERALS_WRAP_METHOD_CODE;
extern Symbol* SYM_LITERALS_NULL;
extern Symbol* SYM_LITERALS_NIL;
extern Symbol* SYM_LITERALS_CONS;
extern Symbol* SYM_LITERALS_WRAP_LITERAL;
extern Symbol* SYM_LITERALS_GET_KWD;
extern Symbol* SYM_LITERALS_TYPED_SYS;
extern Surrogate* SGT_LITERALS_SYMBOL;
extern Symbol* SYM_LITERALS_GET_SGT;
extern Symbol* SYM_LITERALS_INTERN_COMMON_LISP_SYMBOL;
extern Symbol* SYM_LITERALS_GET_SYM;
extern Symbol* SYM_LITERALS_LISTo;
extern Symbol* SYM_LITERALS_a;
extern Symbol* SYM_LITERALS_aa;
extern Symbol* SYM_LITERALS_CONCATENATE;

