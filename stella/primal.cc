// primal.cc

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

boolean TRUE = 1;

boolean FALSE = 0;

boolean NULL_BOOLEAN = -1;

int NULL_INTEGER = 1 << (sizeof (int) / sizeof (char) * 8 - 1);

short int NULL_SHORT_INTEGER = 1 << (sizeof (short int) / sizeof (char) * 8 - 1);

long int NULL_LONG_INTEGER = 1 << (sizeof (long int) / sizeof (char) * 8 - 1);

unsigned short int NULL_UNSIGNED_SHORT_INTEGER = (unsigned short int) -1;

unsigned long int NULL_UNSIGNED_LONG_INTEGER = (unsigned long int) -1;

double NULL_FLOAT = -HUGE_VAL /* IEEE infinity, defined in <math.h> */;

float NULL_SINGLE_FLOAT = -HUGE_VAL /* IEEE infinity, defined in <math.h> */;

double NULL_DOUBLE_FLOAT = NULL_FLOAT;

char NULL_CHARACTER = '\0';

char NULL_OCTET = NULL_CHARACTER;

Symbol* SYM_PRIMAL_FLOOR = NULL;

Keyword* KWD_PRIMAL_CPP = NULL;

Keyword* KWD_PRIMAL_FUNCTION = NULL;

boolean oTRANSIENTOBJECTSpo = FALSE;

Symbol* SYM_PRIMAL_oTRANSIENTOBJECTSpo = NULL;

int random(int n) {
  // Generate a random integer in the interval [0..n-1].
  // 'n' must be <= 2^15.
  if (n > 32768) {
    cerr << "random: Can only generate random numbers between 0 and (2^15)-1.";
  }
  { int rnum = abs(rand()) % n;

    return (rnum);
  }
}

int min(int x, int y) {
  // Return the minimum of `x' and `y'.  If either is NULL, return the other.
  if (x == NULL_INTEGER) {
    return (y);
  }
  if (y == NULL_INTEGER) {
    return (x);
  }
  return (((x < y) ? ((int)(x)) : ((int)(y))));
}

int max(int x, int y) {
  // Return the maximum of `x' and `y'.  If either is NULL, return the other.
  if (x == NULL_INTEGER) {
    return (y);
  }
  if (y == NULL_INTEGER) {
    return (x);
  }
  return (((x > y) ? ((int)(x)) : ((int)(y))));
}

boolean read_OtransientobjectsPO() {
  return (oTRANSIENTOBJECTSpo);
}

boolean write_OtransientobjectsPO(boolean value) {
  oTRANSIENTOBJECTSpo = value;
  return (value);
}

int string_compare(char* x, char* y) {
  // Compare 'x' and 'y' lexicographically, and return -1, 0, 
  // or 1, depending on whether 'x' is less than, equal, or greater than 'y'.
  { int temp1 = NULL_INTEGER;
    int temp2 = NULL_INTEGER;

    { char c2 = NULL_CHARACTER;
      char c1 = NULL_CHARACTER;
      char* vector_001 = x;
      int index_001 = 0;
      int length_001 = string_length(vector_001);
      char* vector_002 = y;
      int index_002 = 0;
      int length_002 = string_length(vector_002);

      while ((index_001 < length_001) &&
          (index_002 < length_002)) {
        {
          c1 = string_nth(vector_001, index_001);
          index_001 = index_001 + 1;
        }
        {
          c2 = string_nth(vector_002, index_002);
          index_002 = index_002 + 1;
        }
        temp1 = character_code(c1);
        temp2 = character_code(c2);
        if (temp1 < temp2) {
          return (-1);
        }
        if (temp1 > temp2) {
          return (1);
        }
      }
    }
    temp1 = string_length(x);
    temp2 = string_length(y);
    if (temp1 == temp2) {
      return (0);
    }
    else {
      if (temp1 < temp2) {
        return (-1);
      }
      else {
        return (1);
      }
    }
  }
}

boolean stringL(char* x, char* y) {
  // Return TRUE if 'x' is lexicographically < 'y'.
  return (string_compare(x, y) == -1);
}

boolean stringLE(char* x, char* y) {
  // Return TRUE if 'x' is lexicographically <= 'y'.
  return (string_compare(x, y) <= 0);
}

boolean stringGE(char* x, char* y) {
  // Return TRUE if 'x' is lexicographically >= 'y'.
  return (string_compare(x, y) >= 0);
}

boolean stringG(char* x, char* y) {
  // Return TRUE if 'x' is lexicographically > 'y'.
  return (string_compare(x, y) == 1);
}

void Vector::print_vector(ostream* stream) {
  { Vector* self = this;

    if (self->length() == 0) {
      *(stream) << "|i|[]";
    }
    else {
      { int i = 0;
        int limit = 9;

        *(stream) << "|i|[";
        { Object* element = NULL;
          Vector* vector_001 = self;
          int index_001 = 0;
          int length_001 = vector_001->length();

          while (index_001 < length_001) {
            {
              element = vector_001->nth(index_001);
              index_001 = index_001 + 1;
            }
            *(stream) << element;
            i = i + 1;
            if (i > limit) {
              break;
            }
            if (i < self->length()) {
              *(stream) << " ";
            }
          }
        }
        if ((i <= limit) ||
            (i == self->length())) {
          *(stream) << "]";
        }
        else {
          *(stream) << " ...]";
        }
      }
    }
  }
}

boolean Vector::emptyP() {
  // Return TRUE if 'self' has length 0.
  { Vector* self = this;

    return (self->length() == 0);
  }
}

boolean Vector::non_emptyP() {
  // Return TRUE if 'self' has length > 0.
  { Vector* self = this;

    return (self->length() > 0);
  }
}

Object* Vector::second() {
  { Vector* self = this;

    return (self->nth(1));
  }
}

Object* Vector::third() {
  { Vector* self = this;

    return (self->nth(2));
  }
}

Object* Vector::fourth() {
  { Vector* self = this;

    return (self->nth(3));
  }
}

Object* Vector::fifth() {
  { Vector* self = this;

    return (self->nth(4));
  }
}

Object* Vector::last() {
  // Return the last item in the vector 'self'.
  { Vector* self = this;

    return (self->nth(self->length() - 1));
  }
}

Object* Vector::last_setter(Object* value) {
  { Vector* self = this;

    return (self->nth_setter(value, self->length() - 1));
  }
}

Vector* Vector::copy() {
  // Return a copy of the vector 'self'.
  { Vector* self = this;

    { Vector* copy = new_vector(self->array_size);

      { int i = NULL_INTEGER;
        int iter_001 = 0;
        int upper_bound_001 = self->array_size - 1;

        while (iter_001 <= upper_bound_001) {
          {
            i = iter_001;
            iter_001 = iter_001 + 1;
          }
          copy->nth_setter(self->nth(i), i);
        }
      }
      return (copy);
    }
  }
}

int Vector_Sequence::length() {
  { Vector_Sequence* self = this;

    return (self->sequence_length);
  }
}

void startup_primal() {
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
            SYM_PRIMAL_FLOOR = ((Symbol*)(intern_rigid_symbol_wrt_module("FLOOR", NULL, 0)));
            KWD_PRIMAL_CPP = ((Keyword*)(intern_rigid_symbol_wrt_module("CPP", NULL, 2)));
            KWD_PRIMAL_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            SYM_PRIMAL_oTRANSIENTOBJECTSpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TRANSIENTOBJECTS?*", NULL, 0)));
          }
          if (current_startup_time_phaseP(4)) {
            NULL_OCTET = NULL_CHARACTER;
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            define_method_from_stringified_source("NULL?", "UNKNOWN", "(DEFMETHOD (NULL? BOOLEAN) ((TEST UNKNOWN)) :NATIVE? TRUE)");
            define_method_from_stringified_source("NULL?", "OBJECT", "(DEFMETHOD (NULL? BOOLEAN) ((TEST OBJECT)) :NATIVE? TRUE)");
            define_method_from_stringified_source("NULL?", "STRING", "(DEFMETHOD (NULL? BOOLEAN) ((TEST STRING)) :NATIVE? TRUE)");
            define_method_from_stringified_source("NULL?", "CHARACTER", "(DEFMETHOD (NULL? BOOLEAN) ((TEST CHARACTER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("NULL?", "BOOLEAN", "(DEFMETHOD (NULL? BOOLEAN) ((TEST BOOLEAN)) :NATIVE? TRUE)");
            define_method_from_stringified_source("NULL?", "CODE", "(DEFMETHOD (NULL? BOOLEAN) ((TEST CODE)) :NATIVE? TRUE)");
            define_method_from_stringified_source("NULL?", "INTEGER", "(DEFMETHOD (NULL? BOOLEAN) ((TEST INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("NULL?", "FLOAT", "(DEFMETHOD (NULL? BOOLEAN) ((TEST FLOAT)) :NATIVE? TRUE)");
            define_method_from_stringified_source("DEFINED?", "UNKNOWN", "(DEFMETHOD (DEFINED? BOOLEAN) ((TEST UNKNOWN)) :NATIVE? TRUE)");
            define_method_from_stringified_source("DEFINED?", "OBJECT", "(DEFMETHOD (DEFINED? BOOLEAN) ((TEST OBJECT)) :NATIVE? TRUE)");
            define_method_from_stringified_source("DEFINED?", "STRING", "(DEFMETHOD (DEFINED? BOOLEAN) ((TEST STRING)) :NATIVE? TRUE)");
            define_method_from_stringified_source("DEFINED?", "CHARACTER", "(DEFMETHOD (DEFINED? BOOLEAN) ((TEST CHARACTER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("DEFINED?", "BOOLEAN", "(DEFMETHOD (DEFINED? BOOLEAN) ((TEST BOOLEAN)) :NATIVE? TRUE)");
            define_method_from_stringified_source("DEFINED?", "CODE", "(DEFMETHOD (DEFINED? BOOLEAN) ((TEST CODE)) :NATIVE? TRUE)");
            define_method_from_stringified_source("DEFINED?", "INTEGER", "(DEFMETHOD (DEFINED? BOOLEAN) ((TEST INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("DEFINED?", "FLOAT", "(DEFMETHOD (DEFINED? BOOLEAN) ((TEST FLOAT)) :NATIVE? TRUE)");
            define_method_from_stringified_source(">", "NUMBER", "(DEFUN (> BOOLEAN) ((X NUMBER) (Y NUMBER)) :NATIVE? TRUE)");
            define_method_from_stringified_source(">=", "NUMBER", "(DEFUN (>= BOOLEAN) ((X NUMBER) (Y NUMBER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("<", "NUMBER", "(DEFUN (< BOOLEAN) ((X NUMBER) (Y NUMBER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("<=", "NUMBER", "(DEFUN (<= BOOLEAN) ((X NUMBER) (Y NUMBER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("+", "NUMBER", "(DEFUN (+ NUMBER) ((X NUMBER) (Y NUMBER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("-", "NUMBER", "(DEFUN (- NUMBER) ((X NUMBER) (Y NUMBER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("*", "NUMBER", "(DEFUN (* NUMBER) ((X NUMBER) (Y NUMBER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("/", "NUMBER", "(DEFUN (|/| NUMBER) ((X NUMBER) (Y NUMBER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("ZERO?", "INTEGER", "(DEFUN (ZERO? BOOLEAN) ((X INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("PLUS?", "INTEGER", "(DEFUN (PLUS? BOOLEAN) ((X INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("EVEN?", "INTEGER", "(DEFUN (EVEN? BOOLEAN) ((X INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("ODD?", "INTEGER", "(DEFUN (ODD? BOOLEAN) ((X INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("MOD", "INTEGER", "(DEFUN (MOD INTEGER) ((X INTEGER) (MODULO INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("CEILING", "NUMBER", "(DEFUN (CEILING INTEGER) ((N NUMBER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("FLOOR", "NUMBER", "(DEFUN (FLOOR INTEGER) ((N NUMBER)) :NATIVE? TRUE)");
            { Method_Slot* method = define_method_from_stringified_source("RANDOM", "INTEGER", "(DEFUN (RANDOM INTEGER) ((N INTEGER)) :PUBLIC? TRUE :DOCUMENTATION \"Generate a random integer in the interval [0..n-1].\n'n' must be <= 2^15.\")");

              method->function_code = ((cpp_function_code)(&random));
            }
            { Method_Slot* method = define_method_from_stringified_source("MIN", "INTEGER", "(DEFUN (MIN INTEGER) ((X INTEGER) (Y INTEGER)) :DOCUMENTATION \"Return the minimum of `x' and `y'.  If either is NULL, return the other.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&min));
            }
            { Method_Slot* method = define_method_from_stringified_source("MAX", "INTEGER", "(DEFUN (MAX INTEGER) ((X INTEGER) (Y INTEGER)) :DOCUMENTATION \"Return the maximum of `x' and `y'.  If either is NULL, return the other.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&max));
            }
            define_method_from_stringified_source("CHARACTER-CODE", "CHARACTER", "(DEFUN (CHARACTER-CODE INTEGER) ((CHAR CHARACTER)) :DOCUMENTATION \"Return the 8-bit ASCII code of 'char' as an integer.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("CODE-CHARACTER", "INTEGER", "(DEFUN (CODE-CHARACTER CHARACTER) ((CODE INTEGER)) :DOCUMENTATION \"Return the character encoded by 'code' (0 <= 'code' <= 255).\" :NATIVE? TRUE)");
            define_method_from_stringified_source("STRING-EQL?", "STRING", "(DEFUN (STRING-EQL? BOOLEAN) ((X STRING) (Y STRING)) :NATIVE? TRUE)");
            { Method_Slot* method = define_method_from_stringified_source("STRING-COMPARE", "STRING", "(DEFUN (STRING-COMPARE INTEGER) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Compare 'x' and 'y' lexicographically, and return -1, 0, \nor 1, depending on whether 'x' is less than, equal, or greater than 'y'.\")");

              method->function_code = ((cpp_function_code)(&string_compare));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING<", "STRING", "(DEFUN (STRING< BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if 'x' is lexicographically < 'y'.\")");

              method->function_code = ((cpp_function_code)(&stringL));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING<=", "STRING", "(DEFUN (STRING<= BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if 'x' is lexicographically <= 'y'.\")");

              method->function_code = ((cpp_function_code)(&stringLE));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING>=", "STRING", "(DEFUN (STRING>= BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if 'x' is lexicographically >= 'y'.\")");

              method->function_code = ((cpp_function_code)(&stringGE));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING>", "STRING", "(DEFUN (STRING> BOOLEAN) ((X STRING) (Y STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return TRUE if 'x' is lexicographically > 'y'.\")");

              method->function_code = ((cpp_function_code)(&stringG));
            }
            define_method_from_stringified_source("MAKE-STRING", "INTEGER", "(DEFUN (MAKE-STRING STRING) ((SIZE INTEGER) (INITIALELEMENT CHARACTER)) :DOCUMENTATION \"Return a string of 'size' characters.  If 'initialElement'\nis defined, initialize all elements of the new string with it.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("CONCATENATE", "STRING", "(DEFMETHOD (CONCATENATE STRING) ((STRING1 STRING) (STRING2 STRING)) :DOCUMENTATION \"Return a string representing the concatenation of\n'string1' and 'string2'.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("PERMANENT-STRING-UPCASE", "STRING", "(DEFUN (PERMANENT-STRING-UPCASE STRING) ((STRING STRING)) :DOCUMENTATION \"Return an upper-case copy of 'string' allocated\nusing the permanent string pool.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("STRING-UPCASE", "STRING", "(DEFUN (STRING-UPCASE STRING) ((STRING STRING)) :DOCUMENTATION \"Return an upper-case copy of 'string'.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("STRING-DOWNCASE", "STRING", "(DEFUN (STRING-DOWNCASE STRING) ((STRING STRING)) :DOCUMENTATION \"Return a lower-case copy of 'string'.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("STRING-CAPITALIZE", "STRING", "(DEFUN (STRING-CAPITALIZE STRING) ((STRING STRING)) :DOCUMENTATION \"Return a capitalized version of 'string'.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("COPY", "STRING", "(DEFMETHOD (COPY STRING) ((STRING STRING)) :DOCUMENTATION \"Return a copy of 'string'.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("SUBSTITUTE", "STRING", "(DEFMETHOD (SUBSTITUTE STRING) ((SELF STRING) (NEWCHAR CHARACTER) (OLDCHAR CHARACTER)) :DOCUMENTATION \"Substitute all occurences of 'oldChar' with 'newChar'\nin the string 'self'.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("INTEGER-TO-STRING", "INTEGER", "(DEFUN (INTEGER-TO-STRING STRING) ((INTEGER INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("MEMBER?", "STRING", "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF STRING) (CHAR CHARACTER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("NTH", "STRING", "(DEFMETHOD (NTH CHARACTER) ((SELF STRING) (POSITION INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("NTH-SETTER", "STRING", "(DEFMETHOD (NTH-SETTER CHARACTER) ((SELF STRING) (CHAR CHARACTER) (POSITION INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("REST", "STRING", "(DEFMETHOD (REST STRING) ((SELF STRING)) :NATIVE? TRUE)");
            define_method_from_stringified_source("LENGTH", "STRING", "(DEFMETHOD (LENGTH INTEGER) ((SELF STRING)) :NATIVE? TRUE)");
            define_method_from_stringified_source("POSITION", "STRING", "(DEFMETHOD (POSITION INTEGER) ((STRING STRING) (CHARACTER CHARACTER) (START INTEGER)) :DOCUMENTATION \"Return the position of 'character' within 'string' (counting\nfrom zero); or return NULL if 'character' does not occur within 'string'.\nIf 'start' was supplied as non-NULL, only consider the substring starting\nat 'start', however, the returned position will always be relative to the\nentire string.\" :NATIVE? TRUE :PUBLIC? TRUE)");
            define_method_from_stringified_source("STRING-SEARCH", "STRING", "(DEFUN (STRING-SEARCH INTEGER) ((STRING STRING) (SUBSTRING STRING) (START INTEGER)) :DOCUMENTATION \"Return start position of the left-most occurrence of\n'substring' in 'string', beginning from 'start'.  Return NULL if it is not\na substring.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("SUBSEQUENCE", "STRING", "(DEFMETHOD (SUBSEQUENCE STRING) ((STRING STRING) (START INTEGER) (END INTEGER)) :DOCUMENTATION \"Return a substring of 'string' beginning at position 'start'\nand ending up to but not including position 'end', counting from zero.  An\n'end' value of NULL stands for the rest of the string.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("STRINGIFY", "OBJECT", "(DEFUN (STRINGIFY STRING) ((EXPRESSION OBJECT)) :NATIVE? TRUE)");
            define_method_from_stringified_source("UNSTRINGIFY", "STRING", "(DEFUN (UNSTRINGIFY OBJECT) ((STRING STRING)) :NATIVE? TRUE)");
            define_method_from_stringified_source("FREE-HASH-TABLE-VALUES", "ABSTRACT-HASH-TABLE", "(DEFMETHOD FREE-HASH-TABLE-VALUES ((SELF ABSTRACT-HASH-TABLE)) :DOCUMENTATION \"Call free on each value in the hash table 'self'.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("INITIALIZE-HASH-TABLE", "ABSTRACT-HASH-TABLE", "(DEFMETHOD INITIALIZE-HASH-TABLE ((SELF ABSTRACT-HASH-TABLE)) :DOCUMENTATION \"Insert a newly-created native hash table into 'self'.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("LOOKUP", "HASH-TABLE", "(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF HASH-TABLE) (KEY (LIKE (ANY-KEY SELF)))) :NATIVE? TRUE)");
            define_method_from_stringified_source("INSERT-AT", "HASH-TABLE", "(DEFMETHOD INSERT-AT ((SELF HASH-TABLE) (KEY (LIKE (ANY-KEY SELF))) (VALUE (LIKE (ANY-VALUE SELF)))) :NATIVE? TRUE)");
            define_method_from_stringified_source("REMOVE-AT", "HASH-TABLE", "(DEFMETHOD REMOVE-AT ((SELF HASH-TABLE) (KEY (LIKE (ANY-KEY SELF)))) :NATIVE? TRUE)");
            define_method_from_stringified_source("LOOKUP", "INTEGER-HASH-TABLE", "(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF INTEGER-HASH-TABLE) (KEY INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("INSERT-AT", "INTEGER-HASH-TABLE", "(DEFMETHOD INSERT-AT ((SELF INTEGER-HASH-TABLE) (KEY INTEGER) (VALUE OBJECT)) :NATIVE? TRUE)");
            define_method_from_stringified_source("LOOKUP", "FLOAT-HASH-TABLE", "(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF FLOAT-HASH-TABLE) (KEY FLOAT)) :NATIVE? TRUE)");
            define_method_from_stringified_source("INSERT-AT", "FLOAT-HASH-TABLE", "(DEFMETHOD INSERT-AT ((SELF FLOAT-HASH-TABLE) (KEY FLOAT) (VALUE OBJECT)) :NATIVE? TRUE)");
            define_method_from_stringified_source("INITIALIZE-HASH-TABLE", "STRING-HASH-TABLE", "(DEFMETHOD INITIALIZE-HASH-TABLE ((SELF STRING-HASH-TABLE)) :DOCUMENTATION \"Insert a newly-created native hash table into 'self'.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("LOOKUP", "STRING-HASH-TABLE", "(DEFMETHOD (LOOKUP (LIKE (ANY-VALUE SELF))) ((SELF STRING-HASH-TABLE) (KEY STRING)) :NATIVE? TRUE)");
            define_method_from_stringified_source("INSERT-AT", "STRING-HASH-TABLE", "(DEFMETHOD INSERT-AT ((SELF STRING-HASH-TABLE) (KEY STRING) (VALUE OBJECT)) :NATIVE? TRUE)");
            define_method_from_stringified_source("REMOVE-AT", "STRING-HASH-TABLE", "(DEFMETHOD REMOVE-AT ((SELF STRING-HASH-TABLE) (KEY STRING)) :NATIVE? TRUE)");
            define_method_from_stringified_source("INITIALIZE-HASH-TABLE", "STRING-TO-INTEGER-HASH-TABLE", "(DEFMETHOD INITIALIZE-HASH-TABLE ((SELF STRING-TO-INTEGER-HASH-TABLE)) :DOCUMENTATION \"Insert a newly-created native hash table into 'self'.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("LOOKUP", "STRING-TO-INTEGER-HASH-TABLE", "(DEFMETHOD (LOOKUP INTEGER) ((SELF STRING-TO-INTEGER-HASH-TABLE) (KEY STRING)) :NATIVE? TRUE)");
            define_method_from_stringified_source("INSERT-AT", "STRING-TO-INTEGER-HASH-TABLE", "(DEFMETHOD INSERT-AT ((SELF STRING-TO-INTEGER-HASH-TABLE) (KEY STRING) (VALUE INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("REMOVE-AT", "STRING-TO-INTEGER-HASH-TABLE", "(DEFMETHOD REMOVE-AT ((SELF STRING-TO-INTEGER-HASH-TABLE) (KEY STRING)) :NATIVE? TRUE)");
            define_method_from_stringified_source("INITIALIZE-VECTOR", "VECTOR", "(DEFMETHOD INITIALIZE-VECTOR ((SELF VECTOR)) :NATIVE? TRUE)");
            { Method_Slot* method = define_method_from_stringified_source("PRINT-VECTOR", "VECTOR", "(DEFMETHOD PRINT-VECTOR ((SELF VECTOR) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->method_code = ((cpp_method_code)(&Vector::print_vector));
            }
            { Method_Slot* method = define_method_from_stringified_source("EMPTY?", "VECTOR", "(DEFMETHOD (EMPTY? BOOLEAN) ((SELF VECTOR)) :DOCUMENTATION \"Return TRUE if 'self' has length 0.\")");

              method->method_code = ((cpp_method_code)(&Vector::emptyP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NON-EMPTY?", "VECTOR", "(DEFMETHOD (NON-EMPTY? BOOLEAN) ((SELF VECTOR)) :DOCUMENTATION \"Return TRUE if 'self' has length > 0.\")");

              method->method_code = ((cpp_method_code)(&Vector::non_emptyP));
            }
            define_method_from_stringified_source("FIRST", "VECTOR", "(DEFMETHOD (FIRST (LIKE (ANY-VALUE SELF))) ((SELF VECTOR)) :NATIVE? TRUE)");
            { Method_Slot* method = define_method_from_stringified_source("SECOND", "VECTOR", "(DEFMETHOD (SECOND (LIKE (ANY-VALUE SELF))) ((SELF VECTOR)))");

              method->method_code = ((cpp_method_code)(&Vector::second));
            }
            { Method_Slot* method = define_method_from_stringified_source("THIRD", "VECTOR", "(DEFMETHOD (THIRD (LIKE (ANY-VALUE SELF))) ((SELF VECTOR)))");

              method->method_code = ((cpp_method_code)(&Vector::third));
            }
            { Method_Slot* method = define_method_from_stringified_source("FOURTH", "VECTOR", "(DEFMETHOD (FOURTH (LIKE (ANY-VALUE SELF))) ((SELF VECTOR)))");

              method->method_code = ((cpp_method_code)(&Vector::fourth));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIFTH", "VECTOR", "(DEFMETHOD (FIFTH (LIKE (ANY-VALUE SELF))) ((SELF VECTOR)))");

              method->method_code = ((cpp_method_code)(&Vector::fifth));
            }
            define_method_from_stringified_source("NTH", "VECTOR", "(DEFMETHOD (NTH (LIKE (ANY-VALUE SELF))) ((SELF VECTOR) (OFFSET INTEGER)) :NATIVE? TRUE)");
            define_method_from_stringified_source("NTH-SETTER", "VECTOR", "(DEFMETHOD (NTH-SETTER (LIKE (ANY-VALUE SELF))) ((SELF VECTOR) (VALUE OBJECT) (POSITION INTEGER)) :NATIVE? TRUE)");
            { Method_Slot* method = define_method_from_stringified_source("LAST", "VECTOR", "(DEFMETHOD (LAST (LIKE (ANY-VALUE SELF))) ((SELF VECTOR)) :DOCUMENTATION \"Return the last item in the vector 'self'.\")");

              method->method_code = ((cpp_method_code)(&Vector::last));
            }
            { Method_Slot* method = define_method_from_stringified_source("LAST-SETTER", "VECTOR", "(DEFMETHOD (LAST-SETTER (LIKE (ANY-VALUE SELF))) ((SELF VECTOR) (VALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Vector::last_setter));
            }
            define_method_from_stringified_source("LENGTH", "VECTOR", "(DEFMETHOD (LENGTH INTEGER) ((SELF VECTOR)) :NATIVE? TRUE)");
            define_method_from_stringified_source("MEMBER?", "VECTOR", "(DEFMETHOD (MEMBER? BOOLEAN) ((SELF VECTOR) (OBJECT OBJECT)) :NATIVE? TRUE)");
            define_method_from_stringified_source("INSERT-AT", "VECTOR", "(DEFMETHOD INSERT-AT ((SELF VECTOR) (OFFSET INTEGER) (VALUE (LIKE (ANY-VALUE SELF)))) :NATIVE? TRUE)");
            define_method_from_stringified_source("RESIZE-VECTOR", "VECTOR", "(DEFUN RESIZE-VECTOR ((SELF VECTOR) (SIZE INTEGER)) :DOCUMENTATION \"Increase the size of 'self' to 'size'.\" :NATIVE? TRUE)");
            { Method_Slot* method = define_method_from_stringified_source("COPY", "VECTOR", "(DEFMETHOD (COPY (VECTOR OF (LIKE (ANY-VALUE SELF)))) ((SELF VECTOR)) :DOCUMENTATION \"Return a copy of the vector 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Vector::copy));
            }
            define_method_from_stringified_source("CLEAR", "VECTOR", "(DEFMETHOD CLEAR ((SELF VECTOR)) :NATIVE? TRUE)");
            define_method_from_stringified_source("INSERT-AT", "EXTENSIBLE-VECTOR", "(DEFMETHOD INSERT-AT ((SELF EXTENSIBLE-VECTOR) (OFFSET INTEGER) (VALUE (LIKE (ANY-VALUE SELF)))) :NATIVE? TRUE)");
            define_method_from_stringified_source("INSERT-AT", "EXTENSIBLE-SYMBOL-ARRAY", "(DEFMETHOD INSERT-AT ((SELF EXTENSIBLE-SYMBOL-ARRAY) (OFFSET INTEGER) (VALUE (LIKE (ANY-VALUE SELF)))) :NATIVE? TRUE)");
            define_method_from_stringified_source("INSERT", "VECTOR-SEQUENCE", "(DEFMETHOD INSERT ((SELF VECTOR-SEQUENCE) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Append 'value' to the END of the sequence 'self'.  \nResize the array if necessary.\" :NATIVE? TRUE)");
            define_method_from_stringified_source("REMOVE", "VECTOR-SEQUENCE", "(DEFMETHOD (REMOVE VECTOR-SEQUENCE) ((SELF VECTOR-SEQUENCE) (VALUE (LIKE (ANY-VALUE SELF)))) :DOCUMENTATION \"Remove 'value' from the sequence 'self', and left shift\nthe values after it to close the gap.\" :NATIVE? TRUE)");
            { Method_Slot* method = define_method_from_stringified_source("LENGTH", "VECTOR-SEQUENCE", "(DEFMETHOD (LENGTH INTEGER) ((SELF VECTOR-SEQUENCE)))");

              method->method_code = ((cpp_method_code)(&Vector_Sequence::length));
            }
            define_method_from_stringified_source("UNMAKE", "UNKNOWN", "(DEFUN UNMAKE ((SELF UNKNOWN)) :NATIVE? TRUE)");
            define_method_from_stringified_source("OPEN-NATIVE-STREAM?", "STREAM", "(DEFUN (OPEN-NATIVE-STREAM? BOOLEAN) ((STREAM STREAM)) :NATIVE? TRUE)");
            define_method_from_stringified_source("CLOSE-NATIVE-STREAM?", "STREAM", "(DEFUN (CLOSE-NATIVE-STREAM? BOOLEAN) ((STREAM STREAM)) :NATIVE? TRUE)");
            define_method_from_stringified_source("READ-S-EXPRESSION", "NATIVE-INPUT-STREAM", "(DEFUN (READ-S-EXPRESSION OBJECT BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)) :NATIVE? TRUE)");
            define_method_from_stringified_source("READ-LINE", "NATIVE-INPUT-STREAM", "(DEFUN (READ-LINE STRING BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)) :NATIVE? TRUE)");
            define_method_from_stringified_source("READ-CHARACTER", "NATIVE-INPUT-STREAM", "(DEFUN (READ-CHARACTER CHARACTER BOOLEAN) ((STREAM NATIVE-INPUT-STREAM)) :NATIVE? TRUE)");
            define_method_from_stringified_source("PROBE-FILE?", "FILE-NAME", "(DEFUN (PROBE-FILE? BOOLEAN) ((FILENAME FILE-NAME)) :NATIVE? TRUE)");
            define_method_from_stringified_source("FILE-WRITE-DATE", "FILE-NAME", "(DEFUN (FILE-WRITE-DATE INTEGER) ((FILENAME FILE-NAME)) :NATIVE? TRUE)");
            define_method_from_stringified_source("FILE-LENGTH", "FILE-NAME", "(DEFUN (FILE-LENGTH INTEGER) ((FILENAME FILE-NAME)) :NATIVE? TRUE)");
            define_method_from_stringified_source("DELETE-FILE", "FILE-NAME", "(DEFUN DELETE-FILE ((FILENAME FILE-NAME)) :NATIVE? TRUE)");
            define_method_from_stringified_source("ALLOCATE-ITERATOR", "LISP-CONS", "(DEFMETHOD (ALLOCATE-ITERATOR LISP-CONS-ITERATOR) ((SELF LISP-CONS)) :NATIVE? TRUE)");
            define_method_from_stringified_source("NEXT?", "LISP-CONS-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF LISP-CONS-ITERATOR)) :NATIVE? TRUE)");
            define_method_from_stringified_source("STARTUP-PRIMAL", NULL, "(DEFUN STARTUP-PRIMAL ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT TRUE BOOLEAN (VERBATIM :COMMON-LISP 1 :CPP \"1\"))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT FALSE BOOLEAN (VERBATIM :COMMON-LISP 0 :CPP \"0\"))");
            define_stella_global_variable_from_stringified_source("(defconstant NULL UNKNOWN NULL)");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT NULL-BOOLEAN BOOLEAN (VERBATIM :COMMON-LISP CL:MOST-POSITIVE-FIXNUM :CPP \"-1\"))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT NULL-INTEGER INTEGER (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-FIXNUM :CPP \"1 << (sizeof (int) / sizeof (char) * 8 - 1)\"))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT NULL-SHORT-INTEGER SHORT-INTEGER (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-FIXNUM :CPP \"1 << (sizeof (short int) / sizeof (char) * 8 - 1)\"))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT NULL-LONG-INTEGER LONG-INTEGER (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-FIXNUM :CPP \"1 << (sizeof (long int) / sizeof (char) * 8 - 1)\"))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT NULL-UNSIGNED-SHORT-INTEGER UNSIGNED-SHORT-INTEGER (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-FIXNUM :CPP \"(unsigned short int) -1\"))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT NULL-UNSIGNED-LONG-INTEGER UNSIGNED-LONG-INTEGER (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-FIXNUM :CPP \"(unsigned long int) -1\"))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT NULL-FLOAT FLOAT (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-DOUBLE-FLOAT :CPP \"-HUGE_VAL /* IEEE infinity, defined in <math.h> */\"))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT NULL-SINGLE-FLOAT SINGLE-FLOAT (VERBATIM :COMMON-LISP CL:MOST-NEGATIVE-SINGLE-FLOAT :CPP \"-HUGE_VAL /* IEEE infinity, defined in <math.h> */\"))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT NULL-DOUBLE-FLOAT DOUBLE-FLOAT NULL-FLOAT)");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT NULL-CHARACTER CHARACTER (VERBATIM :COMMON-LISP (CL:CODE-CHAR 0) :CPP \"'\\\\0'\"))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT NULL-OCTET CHARACTER NULL-CHARACTER)");
            register_native_name(SYM_PRIMAL_FLOOR, KWD_PRIMAL_CPP, KWD_PRIMAL_FUNCTION);
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *TRANSIENTOBJECTS?* BOOLEAN FALSE)");
            { Global_Variable* global = SYM_PRIMAL_oTRANSIENTOBJECTSpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OtransientobjectsPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OtransientobjectsPO));
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

