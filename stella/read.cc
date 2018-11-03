// read.cc

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

ostream* oINPUTECHOSTREAMo = NULL;

boolean oUNREAD_LAST_CHARACTERpo = FALSE;

int READ_BUFFER_SIZE = NULL_INTEGER;

char* oREAD_BUFFERo = NULL;

char* oSTELLA_ATOM_DELIMITERSo = NULL;

Keyword* KWD_READ_SYMBOL = NULL;

Keyword* KWD_READ_COMMON_LISP_SYMBOL = NULL;

Keyword* KWD_READ_INTEGER = NULL;

Keyword* KWD_READ_FLOAT = NULL;

char read_next_character(istream* stream, boolean& return1) {
  { char renamed_Char = NULL_CHARACTER;
    boolean eofP = FALSE;

    renamed_Char = read_character(stream, eofP);
    if (!((oINPUTECHOSTREAMo == NULL) ||
        oUNREAD_LAST_CHARACTERpo)) {
      *(oINPUTECHOSTREAMo) << renamed_Char;
    }
    oUNREAD_LAST_CHARACTERpo = FALSE;
    { char return_temp = renamed_Char;

      return1 = eofP;
      return (return_temp);
    }
  }
}

void unread_last_character(char renamed_Char, istream* stream) {
  if (!(oINPUTECHOSTREAMo == NULL)) {
    oUNREAD_LAST_CHARACTERpo = TRUE;
  }
  unread_character(renamed_Char, stream);
}

char read_next_significant_character(istream* stream, boolean& return1) {
  { char renamed_Char = NULL_CHARACTER;
    boolean eofP = FALSE;

    for (;;) {
      renamed_Char = read_next_character(stream, eofP);
      if (eofP) {
        { char return_temp = NULL_CHARACTER;

          return1 = TRUE;
          return (return_temp);
        }
      }
      else {
        switch (renamed_Char) {
          case ' ': 
          case '\t': 
          case '\n': 
          break;
          case ';': 
            for (;;) {
              renamed_Char = read_next_character(stream, eofP);
              if (eofP) {
                { char return_temp = NULL_CHARACTER;

                  return1 = TRUE;
                  return (return_temp);
                }
              }
              else {
                if (renamed_Char == '\n') {
                  break;
                }
              }
            }
          break;
          default:
            { char return_temp = renamed_Char;

              return1 = FALSE;
              return (return_temp);
            }
          break;
        }
      }
    }
  }
}

boolean eat_next_character_if_whitespace(istream* stream) {
  { char renamed_Char = NULL_CHARACTER;
    boolean eofP = FALSE;

    renamed_Char = read_next_character(stream, eofP);
    renamed_Char = renamed_Char;
    if (eofP) {
      return (TRUE);
    }
    else {
      switch (renamed_Char) {
        case ' ': 
        case '\t': 
        case '\n': 
          return (FALSE);
        default:
          unread_last_character(renamed_Char, stream);
          return (FALSE);
      }
    }
  }
}

char* read_delimited_string(istream* stream, char* delimiters, boolean eatdelimiterP, boolean& return1) {
  { int fillpointer = 0;
    char* string = NULL;
    char renamed_Char = NULL_CHARACTER;
    boolean eofP = FALSE;

    for (;;) {
      renamed_Char = read_next_character(stream, eofP);
      if (eofP ||
          string_memberP(delimiters, renamed_Char)) {
        if (!(eofP ||
            eatdelimiterP)) {
          unread_last_character(renamed_Char, stream);
        }
        string = make_string(fillpointer, NULL_CHARACTER);
        { int i = NULL_INTEGER;
          int iter_001 = 0;
          int upper_bound_001 = fillpointer - 1;

          while (iter_001 <= upper_bound_001) {
            {
              i = iter_001;
              iter_001 = iter_001 + 1;
            }
            string_nth_setter(string, string_nth(oREAD_BUFFERo, i), i);
          }
        }
        { char* return_temp = string;

          return1 = eofP;
          return (return_temp);
        }
      }
      else {
        if (renamed_Char == '\\') {
          renamed_Char = read_next_character(stream, eofP);
          if (eofP) {
            { char* return_temp = NULL;

              return1 = TRUE;
              return (return_temp);
            }
          }
        }
        if (fillpointer == READ_BUFFER_SIZE) {
          cerr << "Read-buffer overflow, atom or string too long";
        }
        string_nth_setter(oREAD_BUFFERo, renamed_Char, fillpointer);
        fillpointer = fillpointer + 1;
      }
    }
  }
}

Object* read_stella_exp(istream* stream, boolean& return1) {
  { char renamed_Char = NULL_CHARACTER;
    boolean eofP = FALSE;

    renamed_Char = read_next_significant_character(stream, eofP);
    if (eofP) {
      { Object* return_temp = NULL;

        return1 = TRUE;
        return (return_temp);
      }
    }
    switch (renamed_Char) {
      case '(': 
        return (read_stella_list(stream, return1));
      case ')': 
        cerr << "Extra right parenthesis encountered";
      break;
      case '"': 
        return (read_stella_string(stream, return1));
      case '#': 
        return (read_stella_hash_syntax(stream, return1));
      case '|': 
        return (read_fully_escaped_stella_symbol(stream, return1));
      default:
        if (renamed_Char == '\\') {
          renamed_Char = read_next_character(stream, eofP);
          if (eofP) {
            { Object* return_temp = NULL;

              return1 = TRUE;
              return (return_temp);
            }
          }
        }
        unread_last_character(renamed_Char, stream);
        return (read_stella_atom(stream, return1));
    }
  }
}

Cons* read_stella_list(istream* stream, boolean& return1) {
  { char renamed_Char = NULL_CHARACTER;
    boolean eofP = FALSE;
    Cons* list = NIL;
    Object* object = NULL;

    for (;;) {
      renamed_Char = read_next_significant_character(stream, eofP);
      if (eofP) {
        cerr << "EOF encountered before end of list";
      }
      if (renamed_Char == ')') {
        { Cons* return_temp = list->reverse();

          return1 = FALSE;
          return (return_temp);
        }
      }
      unread_last_character(renamed_Char, stream);
      object = read_stella_exp(stream, eofP);
      if (eofP) {
        { Cons* return_temp = NULL;

          return1 = TRUE;
          return (return_temp);
        }
      }
      else {
        list = cons(object, list);
      }
    }
  }
}

String_Wrapper* read_stella_string(istream* stream, boolean& return1) {
  { char* string = NULL;
    boolean eofP = FALSE;

    string = read_delimited_string(stream, "\"", TRUE, eofP);
    if (eofP) {
      cerr << "EOF encountered before end of string";
      { String_Wrapper* return_temp = NULL;

        return1 = TRUE;
        return (return_temp);
      }
    }
    { String_Wrapper* return_temp = string_wrap_literal(string);

      return1 = FALSE;
      return (return_temp);
    }
  }
}

Generalized_Symbol* read_fully_escaped_stella_symbol(istream* stream, boolean& return1) {
  { char* string = NULL;
    boolean eofP = FALSE;

    string = read_delimited_string(stream, "|", TRUE, eofP);
    if (eofP) {
      cerr << "EOF encountered before end of fully escaped symbol";
      { Generalized_Symbol* return_temp = NULL;

        return1 = TRUE;
        return (return_temp);
      }
    }
    { Generalized_Symbol* return_temp = intern_generalized_symbol(string);

      return1 = FALSE;
      return (return_temp);
    }
  }
}

Object* read_stella_hash_syntax(istream* stream, boolean& return1) {
  { char renamed_Char = NULL_CHARACTER;
    boolean eofP = FALSE;

    renamed_Char = read_next_character(stream, eofP);
    if (eofP) {
      cerr << "EOF encountered before end of #-syntax";
    }
    switch (renamed_Char) {
      case '\\': 
        return (read_stella_character_constant(stream, return1));
      case '|': 
        skip_parenthesized_comment(stream);
        return (read_stella_exp(stream, return1));
      default:
        cerr << "Illegal #-syntax sub-character " << "`" << renamed_Char << "'";
      break;
    }
  }
}

Character_Wrapper* read_stella_character_constant(istream* stream, boolean& return1) {
  { char renamed_Char = NULL_CHARACTER;
    char* string = NULL;
    boolean eofP = FALSE;

    renamed_Char = read_next_character(stream, eofP);
    if (eofP) {
      cerr << "EOF encountered before end of character constant";
    }
    if (string_memberP("sSnNbBtTrRpP", renamed_Char)) {
      unread_last_character(renamed_Char, stream);
      string = read_delimited_string(stream, oSTELLA_ATOM_DELIMITERSo, FALSE, eofP);
      if (string_length(string) > 1) {
        { int i = NULL_INTEGER;
          int iter_001 = 0;
          int upper_bound_001 = string_length(string) - 1;

          while (iter_001 <= upper_bound_001) {
            {
              i = iter_001;
              iter_001 = iter_001 + 1;
            }
            string_nth_setter(string, downcase_character(string_nth(string, i)), i);
          }
        }
        if (string_eqlP(string, "space")) {
          renamed_Char = ' ';
        }
        else if (string_eqlP(string, "newline")) {
          renamed_Char = '\n';
        }
        else if (string_eqlP(string, "backspace")) {
          renamed_Char = '\b';
        }
        else if (string_eqlP(string, "tab")) {
          renamed_Char = '\t';
        }
        else if (string_eqlP(string, "return")) {
          renamed_Char = '\r';
        }
        else if (string_eqlP(string, "page")) {
          renamed_Char = '\f';
        }
        else {
          cerr << "Illegal character constant: '#\\" << "`" << string << "'" << "'";
        }
      }
    }
    { Character_Wrapper* return_temp = character_wrap_literal(renamed_Char);

      return1 = eofP;
      return (return_temp);
    }
  }
}

void skip_parenthesized_comment(istream* stream) {
  { char renamed_Char = NULL_CHARACTER;
    boolean eofP = FALSE;
    boolean escapeP = FALSE;
    int state = 0;

    for (;;) {
      renamed_Char = read_next_character(stream, eofP);
      if (eofP) {
        cerr << "EOF encountered before end of parenthesized comment";
      }
      switch (renamed_Char) {
        case '\\': 
          escapeP = !escapeP;
          state = 0;
        break;
        case '|': 
          if (!(escapeP)) {
            state = state + 1;
          }
        break;
        case '#': 
          if (!(escapeP)) {
            state = state + 1;
          }
        break;
        default:
          escapeP = FALSE;
          state = 0;
        break;
      }
      if (state == 2) {
        return;
      }
    }
  }
}

Object* read_stella_atom(istream* stream, boolean& return1) {
  { char* atom = NULL;
    boolean eofP = FALSE;

    atom = read_delimited_string(stream, oSTELLA_ATOM_DELIMITERSo, FALSE, eofP);
    { Keyword* test_value_001 = classify_stella_atom(atom);

      if (test_value_001 == KWD_READ_SYMBOL) {
        { Object* return_temp = intern_generalized_symbol(atom);

          return1 = eofP;
          return (return_temp);
        }
      }
      else if (test_value_001 == KWD_READ_COMMON_LISP_SYMBOL) {
        { Object* return_temp = intern_common_lisp_symbol(common_lisp_symbol_name(atom));

          return1 = eofP;
          return (return_temp);
        }
      }
      else if (test_value_001 == KWD_READ_INTEGER) {
        { Object* return_temp = integer_wrap_literal(string_to_integer(atom));

          return1 = eofP;
          return (return_temp);
        }
      }
      else if (test_value_001 == KWD_READ_FLOAT) {
        { Object* return_temp = float_wrap_literal(string_to_float(atom));

          return1 = eofP;
          return (return_temp);
        }
      }
      else {
        cerr << "`" << test_value_001 << "'" << " is not a valid case option";
      }
    }
  }
}

boolean digit_characterP(char renamed_Char) {
  return (string_memberP("0123456789", renamed_Char));
}

Keyword* classify_stella_atom(char* atom) {
  { boolean couldbeintegerP = TRUE;
    boolean couldbefloatP = TRUE;
    int length = string_length(atom);

    if (length == 0) {
      return (KWD_READ_SYMBOL);
    }
    { int i = NULL_INTEGER;
      int iter_001 = 0;
      int upper_bound_001 = length - 1;

      while (iter_001 <= upper_bound_001) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        switch (string_nth(atom, i)) {
          case '+': 
          case '-': 
          case '0': 
          case '1': 
          case '2': 
          case '3': 
          case '4': 
          case '5': 
          case '6': 
          case '7': 
          case '8': 
          case '9': 
          break;
          case '.': 
          case 'e': 
          case 'E': 
            couldbeintegerP = FALSE;
          break;
          default:
            couldbeintegerP = FALSE;
            couldbefloatP = FALSE;
            break;
          break;
        }
      }
    }
    if (couldbeintegerP &&
        string_represents_integerP(atom)) {
      return (KWD_READ_INTEGER);
    }
    if (couldbefloatP &&
        string_represents_floatP(atom)) {
      return (KWD_READ_FLOAT);
    }
    if (string_memberP(atom, ':') &&
        string_represents_common_lisp_symbolP(atom)) {
      return (KWD_READ_COMMON_LISP_SYMBOL);
    }
    return (KWD_READ_SYMBOL);
  }
}

boolean string_represents_integerP(char* string) {
  { int start = 0;
    int length = string_length(string);

    if (length == 0) {
      return (FALSE);
    }
    if (string_memberP("+-", string_nth(string, 0))) {
      start = 1;
    }
    { boolean test_value_001 = FALSE;

      test_value_001 = length > start;
      if (test_value_001) {
        { boolean alwaysP_001 = TRUE;

          { int i = NULL_INTEGER;
            int iter_001 = start;
            int upper_bound_001 = length - 1;

            while (iter_001 <= upper_bound_001) {
              {
                i = iter_001;
                iter_001 = iter_001 + 1;
              }
              if (!digit_characterP(string_nth(string, i))) {
                alwaysP_001 = FALSE;
                break;
              }
            }
          }
          test_value_001 = alwaysP_001;
        }
      }
      { boolean value_001 = test_value_001;

        return (value_001);
      }
    }
  }
}

boolean string_represents_floatP(char* string) {
  { int i = 0;
    int length = string_length(string);
    boolean haveintegralpartP = FALSE;
    boolean havefractionP = FALSE;

    if (length == 0) {
      return (FALSE);
    }
    if (string_memberP("+-", string_nth(string, 0))) {
      i = 1;
    }
    while ((i < length) &&
        digit_characterP(string_nth(string, i))) {
      haveintegralpartP = TRUE;
      i = i + 1;
    }
    if (i >= length) {
      return (FALSE);
    }
    if (string_nth(string, i) == '.') {
      i = i + 1;
      while ((i < length) &&
          digit_characterP(string_nth(string, i))) {
        havefractionP = TRUE;
        i = i + 1;
      }
      if (i >= length) {
        return (havefractionP);
      }
    }
    if (string_memberP("eE", string_nth(string, i)) &&
        (haveintegralpartP ||
         havefractionP)) {
      i = i + 1;
      if (i >= length) {
        return (FALSE);
      }
      if (string_memberP("+-", string_nth(string, i))) {
        i = i + 1;
      }
      if (i >= length) {
        return (FALSE);
      }
      while ((i < length) &&
          digit_characterP(string_nth(string, i))) {
        i = i + 1;
      }
      if (i >= length) {
        return (TRUE);
      }
    }
    return (FALSE);
  }
}

boolean string_represents_common_lisp_symbolP(char* string) {
  return ((string_length(string) >= 4) &&
      (string_memberP("cC", string_nth(string, 0)) &&
       (string_memberP("lL", string_nth(string, 1)) &&
        (string_nth(string, 2) == ':'))));
}

char* common_lisp_symbol_name(char* qualifiedname) {
  return (string_subsequence(qualifiedname, ((string_nth(qualifiedname, 3) == ':') ? ((int)(4)) : ((int)(3))), string_length(qualifiedname)));
}

Object* read_stella_expression(istream* stream, boolean& return1) {
  // Read one Stella s-expression (parse-tree) from 'stream'.
  // Return TRUE as the second value on EOF.  This is the Stella implementation
  // of 'read-s-expression' (which uses the native LISP or YACC/BISON reader).
  { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTRANSIENTOBJECTSpo = TRUE;
          { Object* object = NULL;
            boolean eofP = FALSE;

            object = read_stella_exp(stream, eofP);
            if (!(eofP)) {
              eofP = eat_next_character_if_whitespace(stream);
            }
            { 
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              { Object* return_temp = object;

                return1 = eofP;
                return (return_temp);
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

boolean yes_or_noP(char* message) {
  // Read a line of input from STANDARD-INPUT and return TRUE
  // if the input was `yes' or FALSE if the input was `no'.  Loop until either
  // `yes' or `no' was entered.  If 'message' is non-NULL prompt with it before
  // the input is read.
  { boolean dummy1;

    { char* input = NULL;

      for (;;) {
        if (message != NULL) {
          cout << message;
        }
        input = string_upcase(read_line(STANDARD_INPUT->native_stream, dummy1));
        if (string_eqlP(input, "YES")) {
          return (TRUE);
        }
        if (string_eqlP(input, "NO")) {
          return (FALSE);
        }
        cout << "Type `yes' for yes or `no' for no." << endl;
      }
    }
  }
}

boolean y_or_nP(char* message) {
  // Read a line of input from STANDARD-INPUT and return TRUE
  // if the input was `y' or FALSE if the input was `n'.  Loop until either
  // `y' or `n' was entered.  If 'message' is non-NULL prompt with it before
  // the input is read.
  { boolean dummy1;

    { char* input = NULL;

      for (;;) {
        if (message != NULL) {
          cout << message;
        }
        input = read_line(STANDARD_INPUT->native_stream, dummy1);
        if (string_length(input) > 0) {
          switch (string_nth(input, 0)) {
            case 'y': 
            case 'Y': 
              return (TRUE);
            case 'n': 
            case 'N': 
              return (FALSE);
            default:
            break;
          }
        }
        cout << "Type `y' for yes or `n' for no." << endl;
      }
    }
  }
}

void startup_read() {
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
            KWD_READ_SYMBOL = ((Keyword*)(intern_rigid_symbol_wrt_module("SYMBOL", NULL, 2)));
            KWD_READ_COMMON_LISP_SYMBOL = ((Keyword*)(intern_rigid_symbol_wrt_module("COMMON-LISP-SYMBOL", NULL, 2)));
            KWD_READ_INTEGER = ((Keyword*)(intern_rigid_symbol_wrt_module("INTEGER", NULL, 2)));
            KWD_READ_FLOAT = ((Keyword*)(intern_rigid_symbol_wrt_module("FLOAT", NULL, 2)));
          }
          if (current_startup_time_phaseP(4)) {
            READ_BUFFER_SIZE = 16 * 1024;
            oREAD_BUFFERo = make_string(READ_BUFFER_SIZE, NULL_CHARACTER);
            oSTELLA_ATOM_DELIMITERSo = string_copy("     ()\"|#;");
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("READ-NEXT-CHARACTER", "NATIVE-INPUT-STREAM", "(DEFUN (READ-NEXT-CHARACTER CHARACTER BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&read_next_character));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNREAD-LAST-CHARACTER", "CHARACTER", "(DEFUN UNREAD-LAST-CHARACTER ((CHAR CHARACTER) (STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&unread_last_character));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-NEXT-SIGNIFICANT-CHARACTER", "NATIVE-INPUT-STREAM", "(DEFUN (READ-NEXT-SIGNIFICANT-CHARACTER CHARACTER BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&read_next_significant_character));
            }
            { Method_Slot* method = define_method_from_stringified_source("EAT-NEXT-CHARACTER-IF-WHITESPACE", "NATIVE-INPUT-STREAM", "(DEFUN (EAT-NEXT-CHARACTER-IF-WHITESPACE BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&eat_next_character_if_whitespace));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-DELIMITED-STRING", "NATIVE-INPUT-STREAM", "(DEFUN (READ-DELIMITED-STRING STRING BOOLEAN) ((STREAM NATIVE-INPUT-STREAM) (DELIMITERS STRING) (EATDELIMITER? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&read_delimited_string));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-STELLA-EXP", "NATIVE-INPUT-STREAM", "(DEFUN (READ-STELLA-EXP OBJECT BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&read_stella_exp));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-STELLA-LIST", "NATIVE-INPUT-STREAM", "(DEFUN (READ-STELLA-LIST CONS BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&read_stella_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-STELLA-STRING", "NATIVE-INPUT-STREAM", "(DEFUN (READ-STELLA-STRING STRING-WRAPPER BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&read_stella_string));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-FULLY-ESCAPED-STELLA-SYMBOL", "NATIVE-INPUT-STREAM", "(DEFUN (READ-FULLY-ESCAPED-STELLA-SYMBOL GENERALIZED-SYMBOL BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&read_fully_escaped_stella_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-STELLA-HASH-SYNTAX", "NATIVE-INPUT-STREAM", "(DEFUN (READ-STELLA-HASH-SYNTAX OBJECT BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&read_stella_hash_syntax));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-STELLA-CHARACTER-CONSTANT", "NATIVE-INPUT-STREAM", "(DEFUN (READ-STELLA-CHARACTER-CONSTANT CHARACTER-WRAPPER BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&read_stella_character_constant));
            }
            { Method_Slot* method = define_method_from_stringified_source("SKIP-PARENTHESIZED-COMMENT", "NATIVE-INPUT-STREAM", "(DEFUN SKIP-PARENTHESIZED-COMMENT ((STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&skip_parenthesized_comment));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-STELLA-ATOM", "NATIVE-INPUT-STREAM", "(DEFUN (READ-STELLA-ATOM OBJECT BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&read_stella_atom));
            }
            { Method_Slot* method = define_method_from_stringified_source("DIGIT-CHARACTER?", "CHARACTER", "(DEFUN (DIGIT-CHARACTER? BOOLEAN) ((CHAR CHARACTER)))");

              method->function_code = ((cpp_function_code)(&digit_characterP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASSIFY-STELLA-ATOM", "STRING", "(DEFUN (CLASSIFY-STELLA-ATOM KEYWORD) ((ATOM STRING)))");

              method->function_code = ((cpp_function_code)(&classify_stella_atom));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING-REPRESENTS-INTEGER?", "STRING", "(DEFUN (STRING-REPRESENTS-INTEGER? BOOLEAN) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&string_represents_integerP));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING-REPRESENTS-FLOAT?", "STRING", "(DEFUN (STRING-REPRESENTS-FLOAT? BOOLEAN) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&string_represents_floatP));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING-REPRESENTS-COMMON-LISP-SYMBOL?", "STRING", "(DEFUN (STRING-REPRESENTS-COMMON-LISP-SYMBOL? BOOLEAN) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&string_represents_common_lisp_symbolP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMMON-LISP-SYMBOL-NAME", "STRING", "(DEFUN (COMMON-LISP-SYMBOL-NAME STRING) ((QUALIFIEDNAME STRING)))");

              method->function_code = ((cpp_function_code)(&common_lisp_symbol_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-STELLA-EXPRESSION", "NATIVE-INPUT-STREAM", "(DEFUN (READ-STELLA-EXPRESSION OBJECT BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)) :DOCUMENTATION \"Read one Stella s-expression (parse-tree) from 'stream'.\nReturn TRUE as the second value on EOF.  This is the Stella implementation\nof 'read-s-expression' (which uses the native LISP or YACC/BISON reader).\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&read_stella_expression));
            }
            { Method_Slot* method = define_method_from_stringified_source("YES-OR-NO?", "STRING", "(DEFUN (YES-OR-NO? BOOLEAN) ((MESSAGE STRING)) :DOCUMENTATION \"Read a line of input from STANDARD-INPUT and return TRUE\nif the input was `yes' or FALSE if the input was `no'.  Loop until either\n`yes' or `no' was entered.  If 'message' is non-NULL prompt with it before\nthe input is read.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&yes_or_noP));
            }
            { Method_Slot* method = define_method_from_stringified_source("Y-OR-N?", "STRING", "(DEFUN (Y-OR-N? BOOLEAN) ((MESSAGE STRING)) :DOCUMENTATION \"Read a line of input from STANDARD-INPUT and return TRUE\nif the input was `y' or FALSE if the input was `n'.  Loop until either\n`y' or `n' was entered.  If 'message' is non-NULL prompt with it before\nthe input is read.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&y_or_nP));
            }
            define_method_from_stringified_source("STARTUP-READ", NULL, "(DEFUN STARTUP-READ ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *INPUTECHOSTREAM* NATIVE-OUTPUT-STREAM NULL :DOCUMENTATION \"If non-NULL, characters read with 'read-next-character' will\nbe echoed to the stream bound to '*inputEchoStream*'.\" :PUBLIC? TRUE)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *UNREAD-LAST-CHARACTER?* BOOLEAN FALSE)");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT READ-BUFFER-SIZE INTEGER (* 16 1024))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *READ-BUFFER* STRING (MAKE-STRING READ-BUFFER-SIZE NULL))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STELLA-ATOM-DELIMITERS* STRING (COPY \"     ()\\\"|#;\"))");
            string_nth_setter(oSTELLA_ATOM_DELIMITERSo, ' ', 0);
            string_nth_setter(oSTELLA_ATOM_DELIMITERSo, '\t', 1);
            string_nth_setter(oSTELLA_ATOM_DELIMITERSo, '\n', 2);
            string_nth_setter(oSTELLA_ATOM_DELIMITERSo, '\r', 3);
            string_nth_setter(oSTELLA_ATOM_DELIMITERSo, '\f', 4);
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

