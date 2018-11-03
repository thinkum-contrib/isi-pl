// translate-file.hh

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
class Token_Iterator;

// Function signatures:
boolean read_OuserecordedsignaturesPO();
boolean write_OuserecordedsignaturesPO(boolean value);
Cons* stella_files(Keyword* outputlanguage);
boolean handle_in_module_tree(Cons* tree, boolean seeninmoduleP, boolean& return1);
void operate_on_file(char* file, Keyword* operation);
void translate_file(char* file, boolean walkonlyP);
boolean stella_need_to_translateP(Object* file);
boolean stella_need_to_compileP(Object* file);
boolean simple_translate_system(Cons* files, boolean twopassP, boolean forcetranslationP);
boolean simple_load_system(Cons* files);
void simple_make_clean(Cons* files);
void make_system(Cons* files, boolean forcerecompilationP);
void make_stella(boolean forcerecompilationP);
void output_all_units_to_file(char* sourcefile);
void record_signatures_of_all_units(char* sourcefile);
void create_symbol_startup_file(char* startupfile);
boolean translate_with_copyright_headerP();
void output_copyright_header(Output_Stream* stream);
char directory_separator();
char* file_name_without_directory(char* file);
char* file_name_without_type(char* file);
char* file_base_name(char* file);
Symbol* startup_function_name(char* sourcefile);
Token_Iterator* new_token_iterator();
Object* access_token_iterator_slot_value(Token_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Token_Iterator* tokenize(char* string, char* delimiters);
Cons* parse_pathname(char* pathname);
char* read_OsystemsourcedirectoryO();
char* write_OsystemsourcedirectoryO(char* value);
char* read_OsystembinarydirectoryO();
char* write_OsystembinarydirectoryO(char* value);
Cons* separate_last_cons(Cons* conslist, Object*& return1);
char* make_file_name(Object* relativepath, Keyword* type, char* root);
char* reroot_file_name(char* file, char* fromroot, char* toroot);
void startup_translate_file();

// Global declarations:
extern boolean oRECORD_SIGNATURESpo;
extern boolean oWALK_WITH_RECORDED_SIGNATURESpo;
extern boolean oUSERECORDEDSIGNATURESpo;
extern Symbol* SYM_TRANSLATE_FILE_oUSERECORDEDSIGNATURESpo;
extern Cons* oSTELLA_FILESo;
extern Keyword* KWD_TRANSLATE_FILE_COMMON_LISP;
extern Keyword* KWD_TRANSLATE_FILE_TRANSLATE;
extern Keyword* KWD_TRANSLATE_FILE_CPP;
extern Keyword* KWD_TRANSLATE_FILE_CPP_STANDALONE;
extern Keyword* KWD_TRANSLATE_FILE_IDL;
extern Keyword* KWD_TRANSLATE_FILE_JAVA;
extern Keyword* KWD_TRANSLATE_FILE_DEFINE;
extern Keyword* KWD_TRANSLATE_FILE_FINALIZE;
extern Keyword* KWD_TRANSLATE_FILE_WALK;
extern Keyword* KWD_TRANSLATE_FILE_STELLA;
extern Keyword* KWD_TRANSLATE_FILE_LISP;
extern Keyword* KWD_TRANSLATE_FILE_BINARY;
extern Symbol* SYM_TRANSLATE_FILE_STARTUP_TIME_PROGN;
extern Keyword* KWD_TRANSLATE_FILE_SYMBOLS;
extern Symbol* SYM_TRANSLATE_FILE_NULL;
extern char* oCOPYRIGHT_HEADERo;
extern Keyword* KWD_TRANSLATE_FILE_TRANSLATE_WITH_COPYRIGHT_HEADER;
extern Keyword* KWD_TRANSLATE_FILE_UNIX;
extern Keyword* KWD_TRANSLATE_FILE_MAC;
extern char TYPE_SEPARATOR;
extern Symbol* SYM_TRANSLATE_FILE_THE_STRING;
extern Symbol* SYM_TRANSLATE_FILE_DELIMITERS;
extern Symbol* SYM_TRANSLATE_FILE_CURSOR;
extern Symbol* SYM_TRANSLATE_FILE_END;
extern Surrogate* SGT_TRANSLATE_FILE_TOKEN_ITERATOR;
extern Keyword* oOSo;
extern char* oSYSTEMSOURCEDIRECTORYo;
extern Symbol* SYM_TRANSLATE_FILE_oSYSTEMSOURCEDIRECTORYo;
extern char* oSYSTEMBINARYDIRECTORYo;
extern Symbol* SYM_TRANSLATE_FILE_oSYSTEMBINARYDIRECTORYo;
extern char* oSTELLA_SOURCE_EXTENSIONo;
extern char* oSTELLA_BINARY_EXTENSIONo;
extern char* oSTELLA_LISP_EXTENSIONo;
extern char* oSTELLA_CPP_CODE_EXTENSIONo;
extern char* oSTELLA_CPP_HEADER_EXTENSIONo;
extern char* oSTELLA_JAVA_EXTENSIONo;
extern char* oSTELLA_IDL_EXTENSIONo;
extern Keyword* KWD_TRANSLATE_FILE_CPP_CODE;
extern Keyword* KWD_TRANSLATE_FILE_CPP_HEADER;
extern Keyword* KWD_TRANSLATE_FILE_NONE;
extern Keyword* KWD_TRANSLATE_FILE_DIRECTORY;

class Token_Iterator : public Abstract_Iterator {
public:
  String_Wrapper* value;
public:
  char* the_string;
  char* delimiters;
  int cursor;
  int end;
public:
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

