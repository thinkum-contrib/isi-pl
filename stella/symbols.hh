// symbols.hh

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
class Symbol_Processing_Environment;

// Function signatures:
int next_free_offset(Extensible_Symbol_Array* self);
void free_symbol_offset(Extensible_Symbol_Array* self, int offset);
void add_to_symbol_array_at(Extensible_Symbol_Array* array, int offset, Generalized_Symbol* symbol);
int add_to_symbol_array(Extensible_Symbol_Array* array, Generalized_Symbol* symbol);
boolean legal_symbol_array_offsetP(Extensible_Symbol_Array* array, int offset);
Extensible_Symbol_Array* read_Osymbol_arrayO();
Extensible_Symbol_Array* write_Osymbol_arrayO(Extensible_Symbol_Array* value);
Extensible_Symbol_Array* read_Osurrogate_arrayO();
Extensible_Symbol_Array* write_Osurrogate_arrayO(Extensible_Symbol_Array* value);
Extensible_Symbol_Array* read_Okeyword_arrayO();
Extensible_Symbol_Array* write_Okeyword_arrayO(Extensible_Symbol_Array* value);
Extensible_Symbol_Array* read_Oindexical_arrayO();
Extensible_Symbol_Array* write_Oindexical_arrayO(Extensible_Symbol_Array* value);
String_To_Integer_Hash_Table* read_Okeyword_offset_tableO();
String_To_Integer_Hash_Table* write_Okeyword_offset_tableO(String_To_Integer_Hash_Table* value);
Extensible_Symbol_Array* read_Ofixed_symbol_arrayO();
Extensible_Symbol_Array* write_Ofixed_symbol_arrayO(Extensible_Symbol_Array* value);
Extensible_Symbol_Array* read_Ofixed_surrogate_arrayO();
Extensible_Symbol_Array* write_Ofixed_surrogate_arrayO(Extensible_Symbol_Array* value);
Extensible_Symbol_Array* read_Ofixed_keyword_arrayO();
Extensible_Symbol_Array* write_Ofixed_keyword_arrayO(Extensible_Symbol_Array* value);
Extensible_Symbol_Array* read_Ofixed_indexical_arrayO();
Extensible_Symbol_Array* write_Ofixed_indexical_arrayO(Extensible_Symbol_Array* value);
Context* read_OcontextO();
Context* write_OcontextO(Context* value);
Module* read_OmoduleO();
Module* write_OmoduleO(Module* value);
Symbol* get_sym(int offset);
Surrogate* get_sgt(int offset);
Keyword* get_kwd(int offset);
Indexical* get_idx(int offset);
Generalized_Symbol* get_generalized_symbol_from_offset(Extensible_Symbol_Array* symbolarray, int offset);
Symbol* get_sym_from_offset(int offset);
Surrogate* get_sgt_from_offset(int offset);
Keyword* get_kwd_from_offset(int offset);
Indexical* get_idx_from_offset(int offset);
String_To_Integer_Hash_Table* select_symbol_offset_table(Module* module, int kindofsym);
Extensible_Symbol_Array* select_symbol_array(int kindofsym);
Generalized_Symbol* lookup_rigid_symbol_locally(char* name, Module* module, int kindofsym);
Cons* yield_visible_rigid_symbols_wrt_module(char* name, Module* module, int kindofsym);
Iterator* visible_rigid_symbols_wrt_module(char* name, Module* module, int kindofsym);
int lookup_rigid_symbol_offset_wrt_module(char* name, Module* module, int kindofsym);
Generalized_Symbol* lookup_rigid_symbol_wrt_module(char* name, Module* module, int kindofsym);
Generalized_Symbol* lookup_rigid_symbol(char* name, int kindofsym);
int lookup_indexical_symbol_offset_wrt_module(char* name, Module* module, int kindofsym);
Generalized_Symbol* lookup_indexical_symbol_wrt_module(char* name, Module* module, int kindofsym);
Generalized_Symbol* lookup_indexical_symbol(char* name, int kindofsym);
Symbol* lookup_symbol(char* name);
Symbol* lookup_symbol_in_module(char* name, Module* module, boolean localP);
Surrogate* lookup_surrogate(char* name);
Surrogate* lookup_surrogate_in_module(char* name, Module* module, boolean localP);
Keyword* lookup_keyword(char* name);
Indexical* lookup_indexical(char* name);
Generalized_Symbol* help_intern_generalized_symbol(char* name, int kindofsym, Extensible_Symbol_Array* array, int offset, Module* module);
Generalized_Symbol* intern_rigid_symbol_wrt_module(char* name, Module* module, int kindofsym);
Generalized_Symbol* intern_rigid_symbol_locally(char* name, Module* module, int kindofsym);
Generalized_Symbol* intern_indexical_symbol_wrt_module(char* name, Module* module, int kindofsym);
Generalized_Symbol* intern_rigid_symbol_case_sensitively(char* name, int kindofsym);
Symbol* intern_permanent_symbol(char* name);
Symbol* intern_symbol(char* name);
Symbol* intern_derived_symbol(Generalized_Symbol* basesymbol, char* newname);
Surrogate* intern_surrogate(char* name);
Indexical* intern_indexical(char* name);
Keyword* intern_permanent_keyword(char* name);
Keyword* intern_keyword(char* name);
void unintern_symbol(Symbol* self);
void unintern_surrogate(Surrogate* self);
Generalized_Symbol* intern_bootstrap_symbol_at(char* name, int offset, int kindofsym);
Symbol* intern_symbol_at(char* name, int offset);
Surrogate* intern_surrogate_at(char* name, int offset);
Keyword* intern_keyword_at(char* name, int offset);
Indexical* intern_indexical_at(char* name, int offset);
void initialize_kernel_module(Module* module, char* name, char* fullname, Module* parent);
void initialize_modules();
void initialize_symbols_and_modules();
Symbol* lookup_transient_symbol(char* name);
Keyword* lookup_transient_keyword(char* name);
Symbol* intern_transient_symbol(char* name);
Keyword* intern_transient_keyword(char* name);
void free_transient_symbols();
void free_transient_keywords();
Symbol* intern_common_lisp_symbol(char* name);
boolean symbol_common_lispP(Symbol* self);
boolean common_lisp_symbolP(Object* self);
void initialize_parsing_tables();
char* yield_gensym_name(char* prefix, int counter);
Symbol* gensym(char* prefix);
Surrogate* string_surrogatify(char* self);
Surrogate* typify(Object* self);
Keyword* string_keywordify(char* self);
void in_place_objects_to_symbols(Cons* conslist);
void in_place_objects_to_types(Cons* conslist);
boolean surrogate_nameP(char* name);
boolean qualified_nameP(char* name);
boolean keyword_nameP(char* name);
Generalized_Symbol* intern_generalized_symbol(char* name);
char* compute_full_name(char* name, Module* module);
boolean escaped_characterP(char* string, int position);
char* unescape_character(char* string, char character);
Object* symbol_value(Symbol* symbol);
Object* symbol_value_setter(Symbol* symbol, Object* value);
Cons* symbol_plist(Symbol* symbol);
Cons* symbol_plist_setter(Symbol* symbol, Cons* plist);
Object* symbol_property(Symbol* symbol, Standard_Object* key);
Object* symbol_property_setter(Symbol* symbol, Object* value, Standard_Object* key);
Vector* create_character_type_table();
boolean symbol_constituent_characterP(char character);
void print_symbol(Symbol* self, ostream* stream);
Symbol_Processing_Environment* new_symbol_processing_environment();
Object* access_symbol_processing_environment_slot_value(Symbol_Processing_Environment* self, Symbol* slotname, Object* value, boolean setvalueP);
void initialize_symbol_processing_environment(Symbol_Processing_Environment* self);
void switch_to_symbol_processing_environment(Symbol_Processing_Environment* env);
Symbol_Processing_Environment* create_stella_translation_environment();
void destroy_stella_translation_environment();
void startup_symbols();

// Global declarations:
extern Extensible_Symbol_Array* oSYMBOL_ARRAYo;
extern Symbol* SYM_SYMBOLS_oSYMBOL_ARRAYo;
extern Extensible_Symbol_Array* oSURROGATE_ARRAYo;
extern Symbol* SYM_SYMBOLS_oSURROGATE_ARRAYo;
extern Extensible_Symbol_Array* oKEYWORD_ARRAYo;
extern Symbol* SYM_SYMBOLS_oKEYWORD_ARRAYo;
extern Extensible_Symbol_Array* oINDEXICAL_ARRAYo;
extern Symbol* SYM_SYMBOLS_oINDEXICAL_ARRAYo;
extern String_To_Integer_Hash_Table* oKEYWORD_OFFSET_TABLEo;
extern Symbol* SYM_SYMBOLS_oKEYWORD_OFFSET_TABLEo;
extern Extensible_Symbol_Array* oFIXED_SYMBOL_ARRAYo;
extern Symbol* SYM_SYMBOLS_oFIXED_SYMBOL_ARRAYo;
extern Extensible_Symbol_Array* oFIXED_SURROGATE_ARRAYo;
extern Symbol* SYM_SYMBOLS_oFIXED_SURROGATE_ARRAYo;
extern Extensible_Symbol_Array* oFIXED_KEYWORD_ARRAYo;
extern Symbol* SYM_SYMBOLS_oFIXED_KEYWORD_ARRAYo;
extern Extensible_Symbol_Array* oFIXED_INDEXICAL_ARRAYo;
extern Symbol* SYM_SYMBOLS_oFIXED_INDEXICAL_ARRAYo;
extern String_Hash_Table* oTRANSIENT_SYMBOL_LOOKUP_TABLEo;
extern String_Hash_Table* oCOMMON_LISP_SYMBOL_LOOKUP_TABLEo;
extern String_Hash_Table* oTRANSIENT_KEYWORD_LOOKUP_TABLEo;
extern int SYMBOL_SYM;
extern int SURROGATE_SYM;
extern int KEYWORD_SYM;
extern int INDEXICAL_SYM;
extern Module* oROOT_MODULEo;
extern Module* oSTELLA_MODULEo;
extern Module* oCOMMON_LISP_MODULEo;
extern Module* oALTERNATE_STELLA_MODULEo;
extern Context* oCONTEXTo;
extern Symbol* SYM_SYMBOLS_oCONTEXTo;
extern Module* oMODULEo;
extern Symbol* SYM_SYMBOLS_oMODULEo;
extern char SURROGATE_PREFIX_CHARACTER;
extern char MODULE_SEPARATOR_CHARACTER;
extern char* MODULE_SEPARATOR_STRING;
extern int oCONTEXT_NUMBER_COUNTERo;
extern int oGENSYM_COUNTERo;
extern char ESCAPE_CHARACTER;
extern Keyword* KWD_SYMBOLS_OTHER;
extern Keyword* KWD_SYMBOLS_DIGIT;
extern Keyword* KWD_SYMBOLS_LETTER;
extern Keyword* KWD_SYMBOLS_SYMBOL_CONSTITUENT;
extern Keyword* KWD_SYMBOLS_SYMBOL_QUALIFIER;
extern Keyword* KWD_SYMBOLS_ESCAPE;
extern Keyword* KWD_SYMBOLS_OPEN_DELIMITER;
extern Keyword* KWD_SYMBOLS_CLOSE_DELIMITER;
extern Keyword* KWD_SYMBOLS_PAIRED_DELIMITER;
extern Keyword* KWD_SYMBOLS_WHITE_SPACE;
extern Vector* oCHARACTER_TYPE_TABLEo;
extern int oINITIAL_SYMBOL_ARRAY_SIZEo;
extern Symbol* SYM_SYMBOLS_NAME;
extern Symbol* SYM_SYMBOLS_SYMBOL_ARRAY;
extern Symbol* SYM_SYMBOLS_SURROGATE_ARRAY;
extern Symbol* SYM_SYMBOLS_KEYWORD_ARRAY;
extern Symbol* SYM_SYMBOLS_KEYWORD_OFFSET_TABLE;
extern Symbol* SYM_SYMBOLS_INDEXICAL_ARRAY;
extern Symbol* SYM_SYMBOLS_CARDINAL_MODULES;
extern Symbol* SYM_SYMBOLS_CURRENT_CONTEXT;
extern Surrogate* SGT_SYMBOLS_SYMBOL_PROCESSING_ENVIRONMENT;
extern Symbol_Processing_Environment* oSYMBOL_PROCESSING_ENVIRONMENTo;
extern Symbol_Processing_Environment* oSTELLA_TRANSLATION_ENVIRONMENTo;

class Symbol_Processing_Environment : public Standard_Object {
public:
  char* name;
  Extensible_Symbol_Array* symbol_array;
  Extensible_Symbol_Array* surrogate_array;
  Extensible_Symbol_Array* keyword_array;
  String_To_Integer_Hash_Table* keyword_offset_table;
  Extensible_Symbol_Array* indexical_array;
  List* cardinal_modules;
  Context* current_context;
public:
  virtual void free();
  virtual Surrogate* primary_type();
};

