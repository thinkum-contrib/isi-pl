// streams.hh

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
class Stream_Iterator;
class S_Expression_Iterator;
class Line_Iterator;
class Character_Iterator;

// Function signatures:
Cons* format_message_arguments(Cons* messageargumentstree, boolean trailingeolP);
Object* print_expander(Cons* body);
Object* inform_expander(Cons* body);
Object* warn_expander(Cons* body);
Object* error_expander(Cons* body);
Object* continuable_error_expander(Cons* body);
Cons* format_walk_message_arguments(Cons* messageargumentstree);
Object* walk_error_expander(Cons* body);
Object* walk_inform_expander(Cons* body);
Object* walk_warn_expander(Cons* body);
int read_OsafetyO();
int write_OsafetyO(int value);
Object* safety_expander(Integer_Wrapper* level, Object* test, Cons* body);
Object* eval_error_expander(Cons* body);
void initialize_file_stream(Stream* self);
boolean terminate_file_streamP(Stream* self);
void open_stream(Stream* self);
void close_stream(Stream* self);
void close_all_files();
Object* access_stream_iterator_slot_value(Stream_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
S_Expression_Iterator* new_s_expression_iterator();
Line_Iterator* new_line_iterator();
Character_Iterator* new_character_iterator();
boolean terminate_stream_iteratorP(Stream_Iterator* self);
S_Expression_Iterator* s_expressions(Input_Stream* stream);
Line_Iterator* lines(Input_Stream* stream);
Character_Iterator* characters(Input_Stream* stream);
void startup_streams();

// Global declarations:
extern Symbol* EOL;
extern Symbol* SYM_STREAMS_EOL;
extern Input_Stream* STANDARD_INPUT;
extern Output_Stream* STANDARD_OUTPUT;
extern Output_Stream* STANDARD_WARNING;
extern Output_Stream* STANDARD_ERROR;
extern String_Wrapper* SINGLE_QUOTE_STRING;
extern String_Wrapper* SINGLE_BQUOTE_STRING;
extern Symbol* SYM_STREAMS_PRINT_STREAM;
extern Symbol* SYM_STREAMS_STANDARD_OUTPUT;
extern Symbol* SYM_STREAMS_PRINT;
extern Symbol* SYM_STREAMS_PRINT_EXPANDER;
extern Symbol* SYM_STREAMS_INFORM;
extern Symbol* SYM_STREAMS_INFORM_EXPANDER;
extern Keyword* KWD_STREAMS_WARN;
extern Symbol* SYM_STREAMS_WARN;
extern Symbol* SYM_STREAMS_WARN_EXPANDER;
extern Keyword* KWD_STREAMS_ERROR;
extern Symbol* SYM_STREAMS_ERROR;
extern Symbol* SYM_STREAMS_ERROR_EXPANDER;
extern Keyword* KWD_STREAMS_CONTINUABLE_ERROR;
extern Symbol* SYM_STREAMS_CONTINUABLE_ERROR;
extern Symbol* SYM_STREAMS_CONTINUABLE_ERROR_EXPANDER;
extern Symbol* SYM_STREAMS_DE_UGLIFY_PARSE_TREE;
extern Symbol* SYM_STREAMS_SPECIAL;
extern Symbol* SYM_STREAMS_oPRINTREADABLYpo;
extern Symbol* SYM_STREAMS_TRUE;
extern Symbol* SYM_STREAMS_SIGNAL_TRANSLATION_ERROR;
extern Symbol* SYM_STREAMS_UNLESS;
extern Symbol* SYM_STREAMS_SUPPRESS_WARNINGSp;
extern Symbol* SYM_STREAMS_PRINT_ERROR_CONTEXT;
extern Symbol* SYM_STREAMS_WALK_ERROR;
extern Symbol* SYM_STREAMS_WALK_ERROR_EXPANDER;
extern Symbol* SYM_STREAMS_SIGNAL_TRANSLATION_WARNING;
extern Symbol* SYM_STREAMS_WALK_INFORM;
extern Symbol* SYM_STREAMS_WALK_INFORM_EXPANDER;
extern Symbol* SYM_STREAMS_WALK_WARN;
extern Symbol* SYM_STREAMS_WALK_WARN_EXPANDER;
extern int oSAFETYo;
extern Symbol* SYM_STREAMS_oSAFETYo;
extern Symbol* SYM_STREAMS_WHEN;
extern Symbol* SYM_STREAMS_NOT;
extern Symbol* SYM_STREAMS_SAFETY;
extern Symbol* SYM_STREAMS_SAFETY_EXPANDER;
extern Symbol* SYM_STREAMS_SIGNAL_EVALUATION_ERROR;
extern Symbol* SYM_STREAMS_PRINT_EVALUATION_ERROR_CONTEXT;
extern Symbol* SYM_STREAMS_EVAL_ERROR;
extern Symbol* SYM_STREAMS_EVAL_ERROR_EXPANDER;
extern List* oOPEN_FILE_STREAMSo;
extern Keyword* KWD_STREAMS_OPEN;
extern Keyword* KWD_STREAMS_CLOSED;
extern Surrogate* SGT_STREAMS_INPUT_FILE_STREAM;
extern Surrogate* SGT_STREAMS_OUTPUT_FILE_STREAM;
extern Symbol* SYM_STREAMS_THE_STREAM;
extern Surrogate* SGT_STREAMS_S_EXPRESSION_ITERATOR;
extern Surrogate* SGT_STREAMS_LINE_ITERATOR;
extern Surrogate* SGT_STREAMS_CHARACTER_ITERATOR;

class Stream_Iterator : public Abstract_Iterator {
public:
  Input_Stream* the_stream;
};

class S_Expression_Iterator : public Stream_Iterator {
public:
  Object* value;
public:
  virtual void free();
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

class Line_Iterator : public Stream_Iterator {
public:
  char* value;
public:
  virtual void free();
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

class Character_Iterator : public Stream_Iterator {
public:
  char value;
public:
  virtual void free();
  virtual boolean nextP();
  virtual Surrogate* primary_type();
};

