// read.hh

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
char read_next_character(istream* stream, boolean& return1);
void unread_last_character(char renamed_Char, istream* stream);
char read_next_significant_character(istream* stream, boolean& return1);
boolean eat_next_character_if_whitespace(istream* stream);
char* read_delimited_string(istream* stream, char* delimiters, boolean eatdelimiterP, boolean& return1);
Object* read_stella_exp(istream* stream, boolean& return1);
Cons* read_stella_list(istream* stream, boolean& return1);
String_Wrapper* read_stella_string(istream* stream, boolean& return1);
Generalized_Symbol* read_fully_escaped_stella_symbol(istream* stream, boolean& return1);
Object* read_stella_hash_syntax(istream* stream, boolean& return1);
Character_Wrapper* read_stella_character_constant(istream* stream, boolean& return1);
void skip_parenthesized_comment(istream* stream);
Object* read_stella_atom(istream* stream, boolean& return1);
boolean digit_characterP(char renamed_Char);
Keyword* classify_stella_atom(char* atom);
boolean string_represents_integerP(char* string);
boolean string_represents_floatP(char* string);
boolean string_represents_common_lisp_symbolP(char* string);
char* common_lisp_symbol_name(char* qualifiedname);
Object* read_stella_expression(istream* stream, boolean& return1);
boolean yes_or_noP(char* message);
boolean y_or_nP(char* message);
void startup_read();

// Global declarations:
extern ostream* oINPUTECHOSTREAMo;
extern boolean oUNREAD_LAST_CHARACTERpo;
extern int READ_BUFFER_SIZE;
extern char* oREAD_BUFFERo;
extern char* oSTELLA_ATOM_DELIMITERSo;
extern Keyword* KWD_READ_SYMBOL;
extern Keyword* KWD_READ_COMMON_LISP_SYMBOL;
extern Keyword* KWD_READ_INTEGER;
extern Keyword* KWD_READ_FLOAT;

