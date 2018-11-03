// streams.cc

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

Symbol* EOL = NULL;

Symbol* SYM_STREAMS_EOL = NULL;

Input_Stream* STANDARD_INPUT = NULL;

Output_Stream* STANDARD_OUTPUT = NULL;

Output_Stream* STANDARD_WARNING = NULL;

Output_Stream* STANDARD_ERROR = NULL;

String_Wrapper* SINGLE_QUOTE_STRING = NULL;

String_Wrapper* SINGLE_BQUOTE_STRING = NULL;

Symbol* SYM_STREAMS_PRINT_STREAM = NULL;

Symbol* SYM_STREAMS_STANDARD_OUTPUT = NULL;

Symbol* SYM_STREAMS_PRINT = NULL;

Symbol* SYM_STREAMS_PRINT_EXPANDER = NULL;

Symbol* SYM_STREAMS_INFORM = NULL;

Symbol* SYM_STREAMS_INFORM_EXPANDER = NULL;

Keyword* KWD_STREAMS_WARN = NULL;

Symbol* SYM_STREAMS_WARN = NULL;

Symbol* SYM_STREAMS_WARN_EXPANDER = NULL;

Keyword* KWD_STREAMS_ERROR = NULL;

Symbol* SYM_STREAMS_ERROR = NULL;

Symbol* SYM_STREAMS_ERROR_EXPANDER = NULL;

Keyword* KWD_STREAMS_CONTINUABLE_ERROR = NULL;

Symbol* SYM_STREAMS_CONTINUABLE_ERROR = NULL;

Symbol* SYM_STREAMS_CONTINUABLE_ERROR_EXPANDER = NULL;

Symbol* SYM_STREAMS_DE_UGLIFY_PARSE_TREE = NULL;

Symbol* SYM_STREAMS_SPECIAL = NULL;

Symbol* SYM_STREAMS_oPRINTREADABLYpo = NULL;

Symbol* SYM_STREAMS_TRUE = NULL;

Symbol* SYM_STREAMS_SIGNAL_TRANSLATION_ERROR = NULL;

Symbol* SYM_STREAMS_UNLESS = NULL;

Symbol* SYM_STREAMS_SUPPRESS_WARNINGSp = NULL;

Symbol* SYM_STREAMS_PRINT_ERROR_CONTEXT = NULL;

Symbol* SYM_STREAMS_WALK_ERROR = NULL;

Symbol* SYM_STREAMS_WALK_ERROR_EXPANDER = NULL;

Symbol* SYM_STREAMS_SIGNAL_TRANSLATION_WARNING = NULL;

Symbol* SYM_STREAMS_WALK_INFORM = NULL;

Symbol* SYM_STREAMS_WALK_INFORM_EXPANDER = NULL;

Symbol* SYM_STREAMS_WALK_WARN = NULL;

Symbol* SYM_STREAMS_WALK_WARN_EXPANDER = NULL;

int oSAFETYo = 3;

Symbol* SYM_STREAMS_oSAFETYo = NULL;

Symbol* SYM_STREAMS_WHEN = NULL;

Symbol* SYM_STREAMS_NOT = NULL;

Symbol* SYM_STREAMS_SAFETY = NULL;

Symbol* SYM_STREAMS_SAFETY_EXPANDER = NULL;

Symbol* SYM_STREAMS_SIGNAL_EVALUATION_ERROR = NULL;

Symbol* SYM_STREAMS_PRINT_EVALUATION_ERROR_CONTEXT = NULL;

Symbol* SYM_STREAMS_EVAL_ERROR = NULL;

Symbol* SYM_STREAMS_EVAL_ERROR_EXPANDER = NULL;

List* oOPEN_FILE_STREAMSo = NULL;

Keyword* KWD_STREAMS_OPEN = NULL;

Keyword* KWD_STREAMS_CLOSED = NULL;

Surrogate* SGT_STREAMS_INPUT_FILE_STREAM = NULL;

Surrogate* SGT_STREAMS_OUTPUT_FILE_STREAM = NULL;

Symbol* SYM_STREAMS_THE_STREAM = NULL;

Surrogate* SGT_STREAMS_S_EXPRESSION_ITERATOR = NULL;

Surrogate* SGT_STREAMS_LINE_ITERATOR = NULL;

Surrogate* SGT_STREAMS_CHARACTER_ITERATOR = NULL;

Cons* format_message_arguments(Cons* messageargumentstree, boolean trailingeolP) {
  { Cons* augmentedarguments = NIL;

    { Object* item = NULL;
      Cons* iter_001 = messageargumentstree;

      while (!nilP(iter_001)) {
        {
          item = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if (stringP(item) ||
            (item == EOL)) {
          augmentedarguments = cons(item, augmentedarguments);
        }
        else {
          augmentedarguments = cons(SINGLE_BQUOTE_STRING, augmentedarguments);
          augmentedarguments = cons(item, augmentedarguments);
          augmentedarguments = cons(SINGLE_QUOTE_STRING, augmentedarguments);
        }
      }
    }
    if (trailingeolP) {
      augmentedarguments = cons(EOL, augmentedarguments);
    }
    free_cons_list(messageargumentstree);
    return (augmentedarguments->reverse());
  }
}

Object* print_expander(Cons* body) {
  // Print arguments to the standard output stream.
  return (listO(3, SYM_STREAMS_PRINT_STREAM, SYM_STREAMS_STANDARD_OUTPUT, body->concatenate(NIL)));
}

Object* inform_expander(Cons* body) {
  // Print informative message, placing non-string arguments in quotes,
  // and terminating with a newline.
  body = format_message_arguments(body, TRUE);
  return (listO(3, SYM_STREAMS_PRINT_STREAM, SYM_STREAMS_STANDARD_OUTPUT, body->concatenate(NIL)));
}

Object* warn_expander(Cons* body) {
  // Signal warning message, placing non-string arguments in quotes.
  body = format_message_arguments(body, FALSE);
  return (listO(3, SYM_STREAMS_PRINT_STREAM, KWD_STREAMS_WARN, body->concatenate(NIL)));
}

Object* error_expander(Cons* body) {
  // Signal error message, placing non-string arguments in quotes.
  body = format_message_arguments(body, FALSE);
  return (listO(3, SYM_STREAMS_PRINT_STREAM, KWD_STREAMS_ERROR, body->concatenate(NIL)));
}

Object* continuable_error_expander(Cons* body) {
  // Signal error message, placing non-string arguments in quotes.
  body = format_message_arguments(body, FALSE);
  return (listO(3, SYM_STREAMS_PRINT_STREAM, KWD_STREAMS_CONTINUABLE_ERROR, body->concatenate(NIL)));
}

Cons* format_walk_message_arguments(Cons* messageargumentstree) {
  { Cons_Iterator* it = messageargumentstree->allocate_iterator();

    while (it->nextP()) {
      { Object* item = it->value;

        { Object* item_001 = item;

          if (symbolP(item)) {
            { Symbol* item = NULL;

              item = ((Symbol*)(item_001));
              if (!(item == EOL)) {
                it->value_setter(listO(3, SYM_STREAMS_DE_UGLIFY_PARSE_TREE, item, NIL));
              }
            }
          }
          else {
          }
        }
      }
    }
  }
  return (messageargumentstree);
}

Object* walk_error_expander(Cons* body) {
  { Cons* messagearguments = format_walk_message_arguments(body);

    return (listO(5, SYM_STREAMS_SPECIAL, cons(listO(3, SYM_STREAMS_oPRINTREADABLYpo, SYM_STREAMS_TRUE, NIL), NIL), cons(SYM_STREAMS_SIGNAL_TRANSLATION_ERROR, NIL), listO(5, SYM_STREAMS_UNLESS, cons(SYM_STREAMS_SUPPRESS_WARNINGSp, NIL), listO(4, SYM_STREAMS_PRINT_ERROR_CONTEXT, string_wrap_literal(">> ERROR: "), SYM_STREAMS_STANDARD_OUTPUT, NIL), listO(4, SYM_STREAMS_INFORM, SYM_STREAMS_EOL, string_wrap_literal(" "), messagearguments->concatenate(cons(string_wrap_literal("."), NIL))), NIL), NIL));
  }
}

Object* walk_inform_expander(Cons* body) {
  { Cons* messagearguments = format_walk_message_arguments(body);

    return (listO(5, SYM_STREAMS_SPECIAL, cons(listO(3, SYM_STREAMS_oPRINTREADABLYpo, SYM_STREAMS_TRUE, NIL), NIL), cons(SYM_STREAMS_SIGNAL_TRANSLATION_WARNING, NIL), listO(5, SYM_STREAMS_UNLESS, cons(SYM_STREAMS_SUPPRESS_WARNINGSp, NIL), listO(4, SYM_STREAMS_PRINT_ERROR_CONTEXT, string_wrap_literal(">> WARNING: "), SYM_STREAMS_STANDARD_OUTPUT, NIL), listO(4, SYM_STREAMS_INFORM, SYM_STREAMS_EOL, string_wrap_literal(" "), messagearguments->concatenate(cons(string_wrap_literal("."), NIL))), NIL), NIL));
  }
}

Object* walk_warn_expander(Cons* body) {
  { Cons* messagearguments = format_walk_message_arguments(body);

    return (listO(5, SYM_STREAMS_SPECIAL, cons(listO(3, SYM_STREAMS_oPRINTREADABLYpo, SYM_STREAMS_TRUE, NIL), NIL), cons(SYM_STREAMS_SIGNAL_TRANSLATION_WARNING, NIL), listO(5, SYM_STREAMS_UNLESS, cons(SYM_STREAMS_SUPPRESS_WARNINGSp, NIL), listO(4, SYM_STREAMS_PRINT_ERROR_CONTEXT, string_wrap_literal(">> WARNING: "), SYM_STREAMS_STANDARD_OUTPUT, NIL), listO(4, SYM_STREAMS_INFORM, SYM_STREAMS_EOL, string_wrap_literal(" "), messagearguments->concatenate(cons(string_wrap_literal("."), NIL))), NIL), NIL));
  }
}

int read_OsafetyO() {
  return (oSAFETYo);
}

int write_OsafetyO(int value) {
  oSAFETYo = value;
  return (value);
}

Object* safety_expander(Integer_Wrapper* level, Object* test, Cons* body) {
  // Signal warning message, placing non-string arguments in quotes.
  if (level->wrapper_value > oSAFETYo) {
    free_cons_tree(test);
    free_cons_tree(body);
    return (NIL);
  }
  body = format_message_arguments(body, FALSE);
  return (listO(4, SYM_STREAMS_WHEN, listO(3, SYM_STREAMS_NOT, test, NIL), listO(4, SYM_STREAMS_PRINT_STREAM, KWD_STREAMS_ERROR, string_wrap_literal("Safety violation: "), body->concatenate(NIL)), NIL));
}

Object* eval_error_expander(Cons* body) {
  { Cons* messagearguments = format_walk_message_arguments(body);

    return (listO(6, SYM_STREAMS_SPECIAL, cons(listO(3, SYM_STREAMS_oPRINTREADABLYpo, SYM_STREAMS_TRUE, NIL), NIL), cons(SYM_STREAMS_SIGNAL_EVALUATION_ERROR, NIL), listO(4, SYM_STREAMS_PRINT_EVALUATION_ERROR_CONTEXT, string_wrap_literal(">> ERROR: "), SYM_STREAMS_STANDARD_OUTPUT, NIL), listO(4, SYM_STREAMS_INFORM, SYM_STREAMS_EOL, string_wrap_literal("   "), messagearguments->concatenate(cons(string_wrap_literal("."), NIL))), NIL));
  }
}

void initialize_file_stream(Stream* self) {
  open_stream(self);
  if (!(self->state == KWD_STREAMS_OPEN)) {
    cerr << "initialize-file-stream: Could not open " << "`" << self << "'";
  }
}

boolean terminate_file_streamP(Stream* self) {
  close_stream(self);
  return (self->state == KWD_STREAMS_CLOSED);
}

void open_stream(Stream* self) {
  { boolean successP = open_native_streamP(self);

    if (successP) {
      self->state = KWD_STREAMS_OPEN;
      { Stream* self_001 = self;

        if (taxonomy_isaP(self, SGT_STREAMS_INPUT_FILE_STREAM)) {
          { Input_File_Stream* self = NULL;

            self = ((Input_File_Stream*)(self_001));
            oOPEN_FILE_STREAMSo->push(self);
          }
        }
        else if (taxonomy_isaP(self, SGT_STREAMS_OUTPUT_FILE_STREAM)) {
          { Output_File_Stream* self = NULL;

            self = ((Output_File_Stream*)(self_001));
            oOPEN_FILE_STREAMSo->push(self);
          }
        }
        else {
        }
      }
      return;
    }
  }
}

void close_stream(Stream* self) {
  { boolean successP = close_native_streamP(self);

    if (successP) {
      self->state = KWD_STREAMS_CLOSED;
      { Stream* self_001 = self;

        if (taxonomy_isaP(self, SGT_STREAMS_INPUT_FILE_STREAM)) {
          { Input_File_Stream* self = NULL;

            self = ((Input_File_Stream*)(self_001));
            oOPEN_FILE_STREAMSo->remove(self);
          }
        }
        else if (taxonomy_isaP(self, SGT_STREAMS_OUTPUT_FILE_STREAM)) {
          { Output_File_Stream* self = NULL;

            self = ((Output_File_Stream*)(self_001));
            oOPEN_FILE_STREAMSo->remove(self);
          }
        }
        else {
        }
      }
      return;
    }
  }
}

void close_all_files() {
  { List* openstreams = oOPEN_FILE_STREAMSo->copy();

    { Stream* stream = NULL;
      Cons* iter_001 = openstreams->the_cons_list;

      while (!nilP(iter_001)) {
        {
          stream = ((Stream*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        close_stream(stream);
      }
    }
    openstreams->free();
  }
}

Object* access_stream_iterator_slot_value(Stream_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_STREAMS_THE_STREAM) {
    if (setvalueP) {
      self->the_stream = ((Input_Stream*)(value));
    }
    else {
      return (self->the_stream);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

S_Expression_Iterator* new_s_expression_iterator() {
  { S_Expression_Iterator* self = NULL;

    self = new S_Expression_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->the_stream = NULL;
    return (self);
  }
}

void S_Expression_Iterator::free() {
  { S_Expression_Iterator* self = this;

    if (terminate_stream_iteratorP(self)) {
      unmake(self);
    }
  }
}

Surrogate* S_Expression_Iterator::primary_type() {
  { S_Expression_Iterator* self = this;

    return (SGT_STREAMS_S_EXPRESSION_ITERATOR);
  }
}

Line_Iterator* new_line_iterator() {
  { Line_Iterator* self = NULL;

    self = new Line_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->the_stream = NULL;
    return (self);
  }
}

void Line_Iterator::free() {
  { Line_Iterator* self = this;

    if (terminate_stream_iteratorP(self)) {
      unmake(self);
    }
  }
}

Surrogate* Line_Iterator::primary_type() {
  { Line_Iterator* self = this;

    return (SGT_STREAMS_LINE_ITERATOR);
  }
}

Character_Iterator* new_character_iterator() {
  { Character_Iterator* self = NULL;

    self = new Character_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL_CHARACTER;
    self->the_stream = NULL;
    return (self);
  }
}

void Character_Iterator::free() {
  { Character_Iterator* self = this;

    if (terminate_stream_iteratorP(self)) {
      unmake(self);
    }
  }
}

Surrogate* Character_Iterator::primary_type() {
  { Character_Iterator* self = this;

    return (SGT_STREAMS_CHARACTER_ITERATOR);
  }
}

boolean terminate_stream_iteratorP(Stream_Iterator* self) {
  if (self->the_stream != NULL) {
    self->the_stream->free();
  }
  return (TRUE);
}

S_Expression_Iterator* s_expressions(Input_Stream* stream) {
  { S_Expression_Iterator* self_001 = new_s_expression_iterator();

    self_001->the_stream = stream;
    { S_Expression_Iterator* value_001 = self_001;

      return (value_001);
    }
  }
}

boolean S_Expression_Iterator::nextP() {
  { S_Expression_Iterator* self = this;

    self->first_iterationP = FALSE;
    { Object* object = NULL;
      boolean eofP = FALSE;

      object = read_s_expression(self->the_stream->native_stream, eofP);
      if (eofP) {
        close_stream(self->the_stream);
        return (FALSE);
      }
      else {
        self->value = object;
        return (TRUE);
      }
    }
  }
}

Line_Iterator* lines(Input_Stream* stream) {
  { Line_Iterator* self_001 = new_line_iterator();

    self_001->the_stream = stream;
    { Line_Iterator* value_001 = self_001;

      return (value_001);
    }
  }
}

boolean Line_Iterator::nextP() {
  { Line_Iterator* self = this;

    self->first_iterationP = FALSE;
    { char* line = NULL;
      boolean eofP = FALSE;

      line = read_line(self->the_stream->native_stream, eofP);
      if (eofP) {
        close_stream(self->the_stream);
        return (FALSE);
      }
      else {
        self->value = line;
        return (TRUE);
      }
    }
  }
}

Character_Iterator* characters(Input_Stream* stream) {
  { Character_Iterator* self_001 = new_character_iterator();

    self_001->the_stream = stream;
    { Character_Iterator* value_001 = self_001;

      return (value_001);
    }
  }
}

boolean Character_Iterator::nextP() {
  { Character_Iterator* self = this;

    self->first_iterationP = FALSE;
    { char renamed_Char = NULL_CHARACTER;
      boolean eofP = FALSE;

      renamed_Char = read_character(self->the_stream->native_stream, eofP);
      if (eofP) {
        close_stream(self->the_stream);
        return (FALSE);
      }
      else {
        self->value = renamed_Char;
        return (TRUE);
      }
    }
  }
}

void startup_streams() {
  if (current_startup_time_phaseP(0)) {
    if (!(STANDARD_INPUT != NULL)) {
      { Input_Stream* self_000 = new_input_stream();

        self_000->native_stream = &cin;
        STANDARD_INPUT = self_000;
      }
    }
    if (!(STANDARD_OUTPUT != NULL)) {
      { Output_Stream* self_001 = new_output_stream();

        self_001->native_stream = &cout;
        STANDARD_OUTPUT = self_001;
      }
    }
    if (!(STANDARD_WARNING != NULL)) {
      { Output_Stream* self_002 = new_output_stream();

        self_002->native_stream = &cerr;
        STANDARD_WARNING = self_002;
      }
    }
    if (!(STANDARD_ERROR != NULL)) {
      { Output_Stream* self_003 = new_output_stream();

        self_003->native_stream = &cerr;
        STANDARD_ERROR = self_003;
      }
    }
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
            SYM_STREAMS_EOL = ((Symbol*)(intern_rigid_symbol_wrt_module("EOL", NULL, 0)));
            SYM_STREAMS_PRINT_STREAM = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-STREAM", NULL, 0)));
            SYM_STREAMS_STANDARD_OUTPUT = ((Symbol*)(intern_rigid_symbol_wrt_module("STANDARD-OUTPUT", NULL, 0)));
            SYM_STREAMS_PRINT = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT", NULL, 0)));
            SYM_STREAMS_PRINT_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-EXPANDER", NULL, 0)));
            SYM_STREAMS_INFORM = ((Symbol*)(intern_rigid_symbol_wrt_module("INFORM", NULL, 0)));
            SYM_STREAMS_INFORM_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("INFORM-EXPANDER", NULL, 0)));
            KWD_STREAMS_WARN = ((Keyword*)(intern_rigid_symbol_wrt_module("WARN", NULL, 2)));
            SYM_STREAMS_WARN = ((Symbol*)(intern_rigid_symbol_wrt_module("WARN", NULL, 0)));
            SYM_STREAMS_WARN_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("WARN-EXPANDER", NULL, 0)));
            KWD_STREAMS_ERROR = ((Keyword*)(intern_rigid_symbol_wrt_module("ERROR", NULL, 2)));
            SYM_STREAMS_ERROR = ((Symbol*)(intern_rigid_symbol_wrt_module("ERROR", NULL, 0)));
            SYM_STREAMS_ERROR_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("ERROR-EXPANDER", NULL, 0)));
            KWD_STREAMS_CONTINUABLE_ERROR = ((Keyword*)(intern_rigid_symbol_wrt_module("CONTINUABLE-ERROR", NULL, 2)));
            SYM_STREAMS_CONTINUABLE_ERROR = ((Symbol*)(intern_rigid_symbol_wrt_module("CONTINUABLE-ERROR", NULL, 0)));
            SYM_STREAMS_CONTINUABLE_ERROR_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("CONTINUABLE-ERROR-EXPANDER", NULL, 0)));
            SYM_STREAMS_DE_UGLIFY_PARSE_TREE = ((Symbol*)(intern_rigid_symbol_wrt_module("DE-UGLIFY-PARSE-TREE", NULL, 0)));
            SYM_STREAMS_SPECIAL = ((Symbol*)(intern_rigid_symbol_wrt_module("SPECIAL", NULL, 0)));
            SYM_STREAMS_oPRINTREADABLYpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*PRINTREADABLY?*", NULL, 0)));
            SYM_STREAMS_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            SYM_STREAMS_SIGNAL_TRANSLATION_ERROR = ((Symbol*)(intern_rigid_symbol_wrt_module("SIGNAL-TRANSLATION-ERROR", NULL, 0)));
            SYM_STREAMS_UNLESS = ((Symbol*)(intern_rigid_symbol_wrt_module("UNLESS", NULL, 0)));
            SYM_STREAMS_SUPPRESS_WARNINGSp = ((Symbol*)(intern_rigid_symbol_wrt_module("SUPPRESS-WARNINGS?", NULL, 0)));
            SYM_STREAMS_PRINT_ERROR_CONTEXT = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-ERROR-CONTEXT", NULL, 0)));
            SYM_STREAMS_WALK_ERROR = ((Symbol*)(intern_rigid_symbol_wrt_module("WALK-ERROR", NULL, 0)));
            SYM_STREAMS_WALK_ERROR_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("WALK-ERROR-EXPANDER", NULL, 0)));
            SYM_STREAMS_SIGNAL_TRANSLATION_WARNING = ((Symbol*)(intern_rigid_symbol_wrt_module("SIGNAL-TRANSLATION-WARNING", NULL, 0)));
            SYM_STREAMS_WALK_INFORM = ((Symbol*)(intern_rigid_symbol_wrt_module("WALK-INFORM", NULL, 0)));
            SYM_STREAMS_WALK_INFORM_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("WALK-INFORM-EXPANDER", NULL, 0)));
            SYM_STREAMS_WALK_WARN = ((Symbol*)(intern_rigid_symbol_wrt_module("WALK-WARN", NULL, 0)));
            SYM_STREAMS_WALK_WARN_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("WALK-WARN-EXPANDER", NULL, 0)));
            SYM_STREAMS_oSAFETYo = ((Symbol*)(intern_rigid_symbol_wrt_module("*SAFETY*", NULL, 0)));
            SYM_STREAMS_WHEN = ((Symbol*)(intern_rigid_symbol_wrt_module("WHEN", NULL, 0)));
            SYM_STREAMS_NOT = ((Symbol*)(intern_rigid_symbol_wrt_module("NOT", NULL, 0)));
            SYM_STREAMS_SAFETY = ((Symbol*)(intern_rigid_symbol_wrt_module("SAFETY", NULL, 0)));
            SYM_STREAMS_SAFETY_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("SAFETY-EXPANDER", NULL, 0)));
            SYM_STREAMS_SIGNAL_EVALUATION_ERROR = ((Symbol*)(intern_rigid_symbol_wrt_module("SIGNAL-EVALUATION-ERROR", NULL, 0)));
            SYM_STREAMS_PRINT_EVALUATION_ERROR_CONTEXT = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-EVALUATION-ERROR-CONTEXT", NULL, 0)));
            SYM_STREAMS_EVAL_ERROR = ((Symbol*)(intern_rigid_symbol_wrt_module("EVAL-ERROR", NULL, 0)));
            SYM_STREAMS_EVAL_ERROR_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("EVAL-ERROR-EXPANDER", NULL, 0)));
            KWD_STREAMS_OPEN = ((Keyword*)(intern_rigid_symbol_wrt_module("OPEN", NULL, 2)));
            KWD_STREAMS_CLOSED = ((Keyword*)(intern_rigid_symbol_wrt_module("CLOSED", NULL, 2)));
            SGT_STREAMS_INPUT_FILE_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("INPUT-FILE-STREAM", NULL, 1)));
            SGT_STREAMS_OUTPUT_FILE_STREAM = ((Surrogate*)(intern_rigid_symbol_wrt_module("OUTPUT-FILE-STREAM", NULL, 1)));
            SYM_STREAMS_THE_STREAM = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-STREAM", NULL, 0)));
            SGT_STREAMS_S_EXPRESSION_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("S-EXPRESSION-ITERATOR", NULL, 1)));
            SGT_STREAMS_LINE_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("LINE-ITERATOR", NULL, 1)));
            SGT_STREAMS_CHARACTER_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("CHARACTER-ITERATOR", NULL, 1)));
          }
          if (current_startup_time_phaseP(4)) {
            EOL = SYM_STREAMS_EOL;
            SINGLE_QUOTE_STRING = string_wrap_literal("'");
            SINGLE_BQUOTE_STRING = string_wrap_literal("`");
            oOPEN_FILE_STREAMSo = new_list();
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("STREAM-ITERATOR", "(DEFCLASS STREAM-ITERATOR (ABSTRACT-ITERATOR) :ABSTRACT? TRUE :DOCUMENTATION \"Iterator that yields tokens from an input stream.\" :SLOTS ((THE-STREAM :TYPE INPUT-STREAM)) :TERMINATOR TERMINATE-STREAM-ITERATOR?)");

              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_stream_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("S-EXPRESSION-ITERATOR", "(DEFCLASS S-EXPRESSION-ITERATOR (STREAM-ITERATOR) :DOCUMENTATION \"Iterator that yields s-expressions from an input stream.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_s_expression_iterator));
            }
            { Class* renamed_Class = define_class_from_stringified_source("LINE-ITERATOR", "(DEFCLASS LINE-ITERATOR (STREAM-ITERATOR) :DOCUMENTATION \"Iterator that yields lines from an input stream.\" :PARAMETERS ((ANY-VALUE :TYPE STRING)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_line_iterator));
            }
            { Class* renamed_Class = define_class_from_stringified_source("CHARACTER-ITERATOR", "(DEFCLASS CHARACTER-ITERATOR (STREAM-ITERATOR) :DOCUMENTATION \"Iterator that yields characters from an input stream.\" :PARAMETERS ((ANY-VALUE :TYPE CHARACTER)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_character_iterator));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("FORMAT-MESSAGE-ARGUMENTS", "CONS", "(DEFUN (FORMAT-MESSAGE-ARGUMENTS CONS) ((MESSAGEARGUMENTSTREE CONS) (TRAILINGEOL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&format_message_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-EXPANDER", "CONS", "(DEFUN (PRINT-EXPANDER OBJECT) (|&BODY| (BODY CONS)) :DOCUMENTATION \"Print arguments to the standard output stream.\")");

              method->function_code = ((cpp_function_code)(&print_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("INFORM-EXPANDER", "CONS", "(DEFUN (INFORM-EXPANDER OBJECT) (|&BODY| (BODY CONS)) :DOCUMENTATION \"Print informative message, placing non-string arguments in quotes,\nand terminating with a newline.\")");

              method->function_code = ((cpp_function_code)(&inform_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("WARN-EXPANDER", "CONS", "(DEFUN (WARN-EXPANDER OBJECT) (|&BODY| (BODY CONS)) :DOCUMENTATION \"Signal warning message, placing non-string arguments in quotes.\")");

              method->function_code = ((cpp_function_code)(&warn_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("ERROR-EXPANDER", "CONS", "(DEFUN (ERROR-EXPANDER OBJECT) (|&BODY| (BODY CONS)) :DOCUMENTATION \"Signal error message, placing non-string arguments in quotes.\")");

              method->function_code = ((cpp_function_code)(&error_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTINUABLE-ERROR-EXPANDER", "CONS", "(DEFUN (CONTINUABLE-ERROR-EXPANDER OBJECT) (|&BODY| (BODY CONS)) :DOCUMENTATION \"Signal error message, placing non-string arguments in quotes.\")");

              method->function_code = ((cpp_function_code)(&continuable_error_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("FORMAT-WALK-MESSAGE-ARGUMENTS", "CONS", "(DEFUN (FORMAT-WALK-MESSAGE-ARGUMENTS CONS) ((MESSAGEARGUMENTSTREE CONS)))");

              method->function_code = ((cpp_function_code)(&format_walk_message_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-ERROR-EXPANDER", "CONS", "(DEFUN (WALK-ERROR-EXPANDER OBJECT) (|&BODY| (BODY CONS)))");

              method->function_code = ((cpp_function_code)(&walk_error_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-INFORM-EXPANDER", "CONS", "(DEFUN (WALK-INFORM-EXPANDER OBJECT) (|&BODY| (BODY CONS)))");

              method->function_code = ((cpp_function_code)(&walk_inform_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-WARN-EXPANDER", "CONS", "(DEFUN (WALK-WARN-EXPANDER OBJECT) (|&BODY| (BODY CONS)))");

              method->function_code = ((cpp_function_code)(&walk_warn_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("SAFETY-EXPANDER", "INTEGER-WRAPPER", "(DEFUN (SAFETY-EXPANDER OBJECT) ((LEVEL INTEGER-WRAPPER) (TEST OBJECT) |&BODY| (BODY CONS)) :DOCUMENTATION \"Signal warning message, placing non-string arguments in quotes.\")");

              method->function_code = ((cpp_function_code)(&safety_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("EVAL-ERROR-EXPANDER", "CONS", "(DEFUN (EVAL-ERROR-EXPANDER OBJECT) (|&BODY| (BODY CONS)))");

              method->function_code = ((cpp_function_code)(&eval_error_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-FILE-STREAM", "STREAM", "(DEFUN INITIALIZE-FILE-STREAM ((SELF STREAM)))");

              method->function_code = ((cpp_function_code)(&initialize_file_stream));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-FILE-STREAM?", "STREAM", "(DEFUN (TERMINATE-FILE-STREAM? BOOLEAN) ((SELF STREAM)))");

              method->function_code = ((cpp_function_code)(&terminate_file_streamP));
            }
            { Method_Slot* method = define_method_from_stringified_source("OPEN-STREAM", "STREAM", "(DEFUN OPEN-STREAM ((SELF STREAM)))");

              method->function_code = ((cpp_function_code)(&open_stream));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLOSE-STREAM", "STREAM", "(DEFUN CLOSE-STREAM ((SELF STREAM)))");

              method->function_code = ((cpp_function_code)(&close_stream));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLOSE-ALL-FILES", NULL, "(DEFUN CLOSE-ALL-FILES ())");

              method->function_code = ((cpp_function_code)(&close_all_files));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-STREAM-ITERATOR?", "STREAM-ITERATOR", "(DEFUN (TERMINATE-STREAM-ITERATOR? BOOLEAN) ((SELF STREAM-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&terminate_stream_iteratorP));
            }
            { Method_Slot* method = define_method_from_stringified_source("S-EXPRESSIONS", "INPUT-STREAM", "(DEFUN (S-EXPRESSIONS S-EXPRESSION-ITERATOR) ((STREAM INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&s_expressions));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "S-EXPRESSION-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF S-EXPRESSION-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&S_Expression_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LINES", "INPUT-STREAM", "(DEFUN (LINES LINE-ITERATOR) ((STREAM INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&lines));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "LINE-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF LINE-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Line_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHARACTERS", "INPUT-STREAM", "(DEFUN (CHARACTERS CHARACTER-ITERATOR) ((STREAM INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&characters));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "CHARACTER-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF CHARACTER-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Character_Iterator::nextP));
            }
            define_method_from_stringified_source("STARTUP-STREAMS", NULL, "(DEFUN STARTUP-STREAMS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL EOL SYMBOL (QUOTE EOL) :DOCUMENTATION \"Generates a newline character when passed to a stream.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL STANDARD-INPUT INPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard input stream for the host language.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL STANDARD-OUTPUT OUTPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard output stream for the host language.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL STANDARD-WARNING OUTPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard warning stream for the host language.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL STANDARD-ERROR OUTPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard error stream for the host language.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL SINGLE-QUOTE-STRING STRING-WRAPPER (WRAP-LITERAL \"'\") :DOCUMENTATION \"Holds a string containing the single quote character.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL SINGLE-BQUOTE-STRING STRING-WRAPPER (WRAP-LITERAL \"`\") :DOCUMENTATION \"Holds a string containing the single backquote character.\")");
            store_macro(SYM_STREAMS_PRINT, SYM_STREAMS_PRINT_EXPANDER, ((cpp_function_code)(&print_expander)));
            store_macro(SYM_STREAMS_INFORM, SYM_STREAMS_INFORM_EXPANDER, ((cpp_function_code)(&inform_expander)));
            store_macro(SYM_STREAMS_WARN, SYM_STREAMS_WARN_EXPANDER, ((cpp_function_code)(&warn_expander)));
            store_macro(SYM_STREAMS_ERROR, SYM_STREAMS_ERROR_EXPANDER, ((cpp_function_code)(&error_expander)));
            store_macro(SYM_STREAMS_CONTINUABLE_ERROR, SYM_STREAMS_CONTINUABLE_ERROR_EXPANDER, ((cpp_function_code)(&continuable_error_expander)));
            store_macro(SYM_STREAMS_WALK_ERROR, SYM_STREAMS_WALK_ERROR_EXPANDER, ((cpp_function_code)(&walk_error_expander)));
            store_macro(SYM_STREAMS_WALK_INFORM, SYM_STREAMS_WALK_INFORM_EXPANDER, ((cpp_function_code)(&walk_inform_expander)));
            store_macro(SYM_STREAMS_WALK_WARN, SYM_STREAMS_WALK_WARN_EXPANDER, ((cpp_function_code)(&walk_warn_expander)));
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *SAFETY* INTEGER 3 :DOCUMENTATION \"Integer between 0 and 3.  Higher levels call more\nsafety checks.\")");
            { Global_Variable* global = SYM_STREAMS_oSAFETYo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OsafetyO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OsafetyO));
            }
            store_macro(SYM_STREAMS_SAFETY, SYM_STREAMS_SAFETY_EXPANDER, ((cpp_function_code)(&safety_expander)));
            store_macro(SYM_STREAMS_EVAL_ERROR, SYM_STREAMS_EVAL_ERROR_EXPANDER, ((cpp_function_code)(&eval_error_expander)));
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *OPEN-FILE-STREAMS* (LIST OF STREAM) (NEW (LIST OF STREAM)) :DOCUMENTATION \"List of file streams that are currently open.\")");
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

