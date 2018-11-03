// literals.cc

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

Integer_Wrapper* ZERO_WRAPPER = NULL;

Integer_Wrapper* ONE_WRAPPER = NULL;

Boolean_Wrapper* FALSE_WRAPPER = NULL;

Boolean_Wrapper* TRUE_WRAPPER = NULL;

Boolean_Wrapper* NULL_BOOLEAN_WRAPPER = NULL;

Integer_Wrapper* NULL_INTEGER_WRAPPER = NULL;

Float_Wrapper* NULL_FLOAT_WRAPPER = NULL;

String_Wrapper* NULL_STRING_WRAPPER = NULL;

Character_Wrapper* NULL_CHARACTER_WRAPPER = NULL;

Function_Code_Wrapper* NULL_FUNCTION_CODE_WRAPPER = NULL;

Method_Code_Wrapper* NULL_METHOD_CODE_WRAPPER = NULL;

Hash_Table* oLITERAL_TYPE_INFO_TABLEo = NULL;

List* oLITERAL_TYPESo = NULL;

Surrogate* SGT_LITERALS_BOOLEAN = NULL;

Keyword* KWD_LITERALS_NULL_WRAPPER = NULL;

Symbol* SYM_LITERALS_NULL_BOOLEAN_WRAPPER = NULL;

Surrogate* SGT_LITERALS_INTEGER = NULL;

Symbol* SYM_LITERALS_NULL_INTEGER_WRAPPER = NULL;

Surrogate* SGT_LITERALS_FLOAT = NULL;

Symbol* SYM_LITERALS_NULL_FLOAT_WRAPPER = NULL;

Surrogate* SGT_LITERALS_STRING = NULL;

Symbol* SYM_LITERALS_NULL_STRING_WRAPPER = NULL;

Surrogate* SGT_LITERALS_CHARACTER = NULL;

Symbol* SYM_LITERALS_NULL_CHARACTER_WRAPPER = NULL;

Surrogate* SGT_LITERALS_FUNCTION_CODE = NULL;

Symbol* SYM_LITERALS_NULL_FUNCTION_CODE_WRAPPER = NULL;

Surrogate* SGT_LITERALS_METHOD_CODE = NULL;

Symbol* SYM_LITERALS_NULL_METHOD_CODE_WRAPPER = NULL;

Keyword* KWD_LITERALS_WRAP_FUNCTION = NULL;

Symbol* SYM_LITERALS_WRAP_BOOLEAN = NULL;

Symbol* SYM_LITERALS_WRAP_INTEGER = NULL;

Symbol* SYM_LITERALS_WRAP_FLOAT = NULL;

Symbol* SYM_LITERALS_WRAP_STRING = NULL;

Symbol* SYM_LITERALS_WRAP_CHARACTER = NULL;

Symbol* SYM_LITERALS_WRAP_FUNCTION_CODE = NULL;

Symbol* SYM_LITERALS_WRAP_METHOD_CODE = NULL;

Symbol* SYM_LITERALS_NULL = NULL;

Symbol* SYM_LITERALS_NIL = NULL;

Symbol* SYM_LITERALS_CONS = NULL;

Symbol* SYM_LITERALS_WRAP_LITERAL = NULL;

Symbol* SYM_LITERALS_GET_KWD = NULL;

Symbol* SYM_LITERALS_TYPED_SYS = NULL;

Surrogate* SGT_LITERALS_SYMBOL = NULL;

Symbol* SYM_LITERALS_GET_SGT = NULL;

Symbol* SYM_LITERALS_INTERN_COMMON_LISP_SYMBOL = NULL;

Symbol* SYM_LITERALS_GET_SYM = NULL;

Symbol* SYM_LITERALS_LISTo = NULL;

Symbol* SYM_LITERALS_a = NULL;

Symbol* SYM_LITERALS_aa = NULL;

Symbol* SYM_LITERALS_CONCATENATE = NULL;

boolean Wrapper::terminate_wrapperP() {
  { Wrapper* self = this;

    if ((self == NULL_FLOAT_WRAPPER) ||
        ((self == NULL_STRING_WRAPPER) ||
         ((self == NULL_CHARACTER_WRAPPER) ||
          ((self == NULL_FUNCTION_CODE_WRAPPER) ||
           (self == NULL_METHOD_CODE_WRAPPER))))) {
      return (FALSE);
    }
    else {
      return (TRUE);
    }
  }
}

boolean Integer_Wrapper::terminate_wrapperP() {
  { Integer_Wrapper* self = this;

    if ((self == ZERO_WRAPPER) ||
        ((self == ONE_WRAPPER) ||
         (self == NULL_INTEGER_WRAPPER))) {
      return (FALSE);
    }
    else {
      return (TRUE);
    }
  }
}

Object* lookup_literal_type_info(Surrogate* type, Keyword* key) {
  { Key_Value_List* entry = ((Key_Value_List*)(oLITERAL_TYPE_INFO_TABLEo->lookup(type)));

    if (entry != NULL) {
      return (entry->lookup(key));
    }
    else {
      return (NULL);
    }
  }
}

void set_literal_type_info(Surrogate* type, Keyword* key, Object* value) {
  { Key_Value_List* entry = ((Key_Value_List*)(oLITERAL_TYPE_INFO_TABLEo->lookup(type)));

    if (entry == NULL) {
      entry = new_key_value_list();
      oLITERAL_TYPE_INFO_TABLEo->insert_at(type, entry);
      oLITERAL_TYPESo->insert_last(type);
    }
    entry->insert_at(key, value);
  }
}

Boolean_Wrapper* wrap_boolean(boolean value) {
  if (value == NULL_BOOLEAN) {
    return (NULL_BOOLEAN_WRAPPER);
  }
  else {
    if (value) {
      return (TRUE_WRAPPER);
    }
    else {
      return (FALSE_WRAPPER);
    }
  }
}

Integer_Wrapper* wrap_integer(int value) {
  if (value == NULL_INTEGER) {
    return (NULL_INTEGER_WRAPPER);
  }
  else {
    switch (value) {
      case 0: 
        return (ZERO_WRAPPER);
      case 1: 
        return (ONE_WRAPPER);
      default:
        if (oTRANSIENTOBJECTSpo) {
          return (new_transient_integer_wrapper(value));
        }
        else {
          return (new_integer_wrapper(value));
        }
      break;
    }
  }
}

Float_Wrapper* wrap_float(double value) {
  if (value == NULL_FLOAT) {
    return (NULL_FLOAT_WRAPPER);
  }
  else {
    if (oTRANSIENTOBJECTSpo) {
      return (new_transient_float_wrapper(value));
    }
    else {
      return (new_float_wrapper(value));
    }
  }
}

String_Wrapper* wrap_string(char* value) {
  if (value == NULL) {
    return (NULL_STRING_WRAPPER);
  }
  else {
    if (oTRANSIENTOBJECTSpo) {
      return (new_transient_string_wrapper(value));
    }
    else {
      return (new_string_wrapper(value));
    }
  }
}

Character_Wrapper* wrap_character(char value) {
  if (value == NULL_CHARACTER) {
    return (NULL_CHARACTER_WRAPPER);
  }
  else {
    if (oTRANSIENTOBJECTSpo) {
      return (new_transient_character_wrapper(value));
    }
    else {
      return (new_character_wrapper(value));
    }
  }
}

Function_Code_Wrapper* wrap_function_code(cpp_function_code value) {
  if (value == NULL) {
    return (NULL_FUNCTION_CODE_WRAPPER);
  }
  else {
    if (oTRANSIENTOBJECTSpo) {
      return (new_transient_function_code_wrapper(value));
    }
    else {
      return (new_function_code_wrapper(value));
    }
  }
}

Method_Code_Wrapper* wrap_method_code(cpp_method_code value) {
  if (value == NULL) {
    return (NULL_METHOD_CODE_WRAPPER);
  }
  else {
    if (oTRANSIENTOBJECTSpo) {
      return (new_transient_method_code_wrapper(value));
    }
    else {
      return (new_method_code_wrapper(value));
    }
  }
}

Integer_Wrapper* integer_wrap_literal(int value) {
  return (wrap_integer(value));
}

Float_Wrapper* float_wrap_literal(double value) {
  return (wrap_float(value));
}

String_Wrapper* string_wrap_literal(char* value) {
  return (wrap_string(value));
}

Character_Wrapper* character_wrap_literal(char value) {
  return (wrap_character(value));
}

Function_Code_Wrapper* function_code_wrap_literal(cpp_function_code value) {
  return (wrap_function_code(value));
}

Method_Code_Wrapper* method_code_wrap_literal(cpp_method_code value) {
  return (wrap_method_code(value));
}

Object* Standard_Object::copy_wrapped_literal() {
  { Standard_Object* self = this;

    return (self);
  }
}

Object* Integer_Wrapper::copy_wrapped_literal() {
  { Integer_Wrapper* self = this;

    return (integer_wrap_literal(self->wrapper_value));
  }
}

Object* Float_Wrapper::copy_wrapped_literal() {
  { Float_Wrapper* self = this;

    return (float_wrap_literal(self->wrapper_value));
  }
}

Object* String_Wrapper::copy_wrapped_literal() {
  { String_Wrapper* self = this;

    return (string_wrap_literal(self->wrapper_value));
  }
}

Object* Character_Wrapper::copy_wrapped_literal() {
  { Character_Wrapper* self = this;

    return (character_wrap_literal(self->wrapper_value));
  }
}

Object* Function_Code_Wrapper::copy_wrapped_literal() {
  { Function_Code_Wrapper* self = this;

    return (function_code_wrap_literal(self->wrapper_value));
  }
}

Object* Method_Code_Wrapper::copy_wrapped_literal() {
  { Method_Code_Wrapper* self = this;

    return (method_code_wrap_literal(self->wrapper_value));
  }
}

boolean Object::object_eqlP(Object* y) {
  { Object* x = this;

    cerr << "object-eql?: Don't know how to compare " << "`" << x << "'" << " with " << "`" << y << "'";
    return (FALSE);
  }
}

boolean Standard_Object::object_eqlP(Object* y) {
  { Standard_Object* x = this;

    return (x == y);
  }
}

boolean Integer_Wrapper::object_eqlP(Object* y) {
  { Integer_Wrapper* x = this;

    return (integerP(y) &&
        (x->wrapper_value == ((Integer_Wrapper*)(y))->wrapper_value));
  }
}

boolean Float_Wrapper::object_eqlP(Object* y) {
  { Float_Wrapper* x = this;

    return (floatP(y) &&
        (x->wrapper_value == ((Float_Wrapper*)(y))->wrapper_value));
  }
}

boolean Boolean_Wrapper::object_eqlP(Object* y) {
  { Boolean_Wrapper* x = this;

    return (x == y);
  }
}

boolean String_Wrapper::object_eqlP(Object* y) {
  { String_Wrapper* x = this;

    return (stringP(y) &&
        string_eqlP(x->wrapper_value, ((String_Wrapper*)(y))->wrapper_value));
  }
}

boolean Character_Wrapper::object_eqlP(Object* y) {
  { Character_Wrapper* x = this;

    return (characterP(y) &&
        (x->wrapper_value == ((Character_Wrapper*)(y))->wrapper_value));
  }
}

boolean eqlP(Object* x, Object* y) {
  // 'eql?' translates into the C++ '==' except that 
  //    (1) it tests for string equivalence when its first argument is a string,
  //    and (2) it understands wrapped literals.
  return (((x == NULL) ? ((boolean)(y == NULL)) : ((boolean)(x->object_eqlP(y)))));
}

boolean eql_to_booleanP(Object* y, boolean x) {
  return (booleanP(y) &&
      (((Boolean_Wrapper*)(y))->wrapper_value == x));
}

boolean eql_to_integerP(Object* y, int x) {
  return (integerP(y) &&
      (((Integer_Wrapper*)(y))->wrapper_value == x));
}

boolean eql_to_floatP(Object* y, double x) {
  return (floatP(y) &&
      (((Float_Wrapper*)(y))->wrapper_value == x));
}

boolean eql_to_stringP(Object* y, char* x) {
  return (stringP(y) &&
      string_eqlP(((String_Wrapper*)(y))->wrapper_value, x));
}

boolean eql_to_characterP(Object* y, char x) {
  return (characterP(y) &&
      (((Character_Wrapper*)(y))->wrapper_value == x));
}

Object* help_bquotify(Object* tree) {
  if (tree == NULL) {
    return (SYM_LITERALS_NULL);
  }
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        if (nilP(tree)) {
          return (SYM_LITERALS_NIL);
        }
        else {
          return (cons_list(3, SYM_LITERALS_CONS, help_bquotify(tree->value), help_bquotify(tree->rest)));
        }
      }
    }
    else if (integerP(tree)) {
      { Integer_Wrapper* tree = NULL;

        tree = ((Integer_Wrapper*)(tree_001));
        return (cons_list(2, SYM_LITERALS_WRAP_LITERAL, tree));
      }
    }
    else if (stringP(tree)) {
      { String_Wrapper* tree = NULL;

        tree = ((String_Wrapper*)(tree_001));
        return (cons_list(2, SYM_LITERALS_WRAP_LITERAL, tree));
      }
    }
    else if (floatP(tree)) {
      { Float_Wrapper* tree = NULL;

        tree = ((Float_Wrapper*)(tree_001));
        return (cons_list(2, SYM_LITERALS_WRAP_LITERAL, tree));
      }
    }
    else if (characterP(tree)) {
      { Character_Wrapper* tree = NULL;

        tree = ((Character_Wrapper*)(tree_001));
        return (cons_list(2, SYM_LITERALS_WRAP_LITERAL, tree));
      }
    }
    else if (keywordP(tree)) {
      { Keyword* tree = NULL;

        tree = ((Keyword*)(tree_001));
        if (use_hardcoded_symbolsP()) {
          return (cons_list(2, SYM_LITERALS_GET_KWD, integer_wrap_literal(((Keyword*)(tree->permanentify()))->symbol_id)));
        }
        else {
          {
            register_symbol(tree);
            return (cons_list(3, SYM_LITERALS_TYPED_SYS, yield_symbol_constant_name(tree), SGT_LITERALS_SYMBOL));
          }
        }
      }
    }
    else if (surrogateP(tree)) {
      { Surrogate* tree = NULL;

        tree = ((Surrogate*)(tree_001));
        if (use_hardcoded_symbolsP()) {
          return (cons_list(2, SYM_LITERALS_GET_SGT, integer_wrap_literal(tree->symbol_id)));
        }
        else {
          {
            register_symbol(tree);
            return (cons_list(3, SYM_LITERALS_TYPED_SYS, yield_symbol_constant_name(tree), SGT_LITERALS_SYMBOL));
          }
        }
      }
    }
    else if (symbolP(tree)) {
      { Symbol* tree = NULL;

        tree = ((Symbol*)(tree_001));
        if (symbol_common_lispP(tree)) {
          return (cons_list(2, SYM_LITERALS_INTERN_COMMON_LISP_SYMBOL, string_wrap_literal(tree->symbol_name)));
        }
        else {
          if (use_hardcoded_symbolsP()) {
            return (cons_list(2, SYM_LITERALS_GET_SYM, integer_wrap_literal(((Symbol*)(tree->permanentify()))->symbol_id)));
          }
          else {
            {
              register_symbol(tree);
              return (cons_list(3, SYM_LITERALS_TYPED_SYS, yield_symbol_constant_name(tree), SGT_LITERALS_SYMBOL));
            }
          }
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
                cout << endl << " " << "Illegal argument to quote: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
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
}

Object* bquotify(Object* tree) {
  return (help_bquotify(tree));
}

Object* expand_bquote_tree(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Cons* expandedtree = cons(SYM_LITERALS_LISTo, NIL);
          Cons* cursor = tree;
          Object* term = cursor->value;

          while (cursor->non_emptyP() &&
              (!((term == SYM_LITERALS_a) ||
              (term == SYM_LITERALS_aa)))) {
            expandedtree = cons(expand_bquote_tree(term), expandedtree);
            cursor = cursor->rest;
            term = cursor->first();
          }
          if (cursor->emptyP()) {
            return (cons(SYM_LITERALS_NIL, expandedtree)->reverse());
          }
          else if (term == SYM_LITERALS_a) {
            cursor = cursor->rest;
            if (cursor->emptyP()) {
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
                        cout << endl << " " << "Illegal bquote tree -- missing term after '&'." << "." << endl;
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
            return (cons(expand_bquote_tree(cursor->rest), cons(cursor->value, expandedtree))->reverse());
          }
          else {
            cursor = cursor->rest;
            if (cursor->emptyP()) {
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
                        cout << endl << " " << "Illegal bquote tree -- missing term after '&&'" << "." << endl;
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
            return (cons(cons_list(3, SYM_LITERALS_CONCATENATE, cursor->value, expand_bquote_tree(cursor->rest)), expandedtree)->reverse());
          }
        }
      }
    }
    else {
      return (bquotify(tree));
    }
  }
}

Object* simplify_bquote_tree(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Cons* cursor = tree->rest;

          while (cursor->non_emptyP()) {
            cursor->value = simplify_bquote_tree(cursor->value);
            cursor = cursor->rest;
          }
          if (!(tree->value == SYM_LITERALS_LISTo)) {
            return (tree);
          }
          switch (tree->rest->length()) {
            case 1: 
              { Object* arg = tree->rest->value;

                tree->rest->free_cons();
                tree->free_cons();
                return (arg);
              }
            break;
            case 2: 
              tree->value = SYM_LITERALS_CONS;
              return (tree);
            default:
              return (tree);
          }
        }
      }
    }
    else {
      return (tree);
    }
  }
}

Object* Object::permanentify() {
  { Object* self = this;

    return (self);
  }
}

Object* Symbol::permanentify() {
  { Symbol* self = this;

    return (self);
  }
}

Object* Keyword::permanentify() {
  { Keyword* self = this;

    return (self);
  }
}

Object* Transient_Symbol::permanentify() {
  { Transient_Symbol* self = this;

    return (intern_permanent_symbol(self->symbol_name));
  }
}

Object* Transient_Keyword::permanentify() {
  { Transient_Keyword* self = this;

    return (intern_permanent_keyword(self->symbol_name));
  }
}

Literal_Wrapper* Literal_Wrapper::permanentify_literal() {
  { Literal_Wrapper* self = this;

    cerr << "permanentify-literal: Not implemented for " << "`" << self << "'";
    return (NULL);
  }
}

Literal_Wrapper* Integer_Wrapper::permanentify_literal() {
  { Integer_Wrapper* self = this;

    return (integer_wrap_literal(self->wrapper_value));
  }
}

Literal_Wrapper* Float_Wrapper::permanentify_literal() {
  { Float_Wrapper* self = this;

    return (float_wrap_literal(self->wrapper_value));
  }
}

Literal_Wrapper* String_Wrapper::permanentify_literal() {
  { String_Wrapper* self = this;

    return (string_wrap_literal(self->wrapper_value));
  }
}

Literal_Wrapper* Character_Wrapper::permanentify_literal() {
  { Character_Wrapper* self = this;

    return (character_wrap_literal(self->wrapper_value));
  }
}

Function_Code_Wrapper* Function_Code_Wrapper::permanentify_literal() {
  { Function_Code_Wrapper* self = this;

    return (function_code_wrap_literal(self->wrapper_value));
  }
}

Method_Code_Wrapper* Method_Code_Wrapper::permanentify_literal() {
  { Method_Code_Wrapper* self = this;

    return (method_code_wrap_literal(self->wrapper_value));
  }
}

Object* Literal_Wrapper::permanentify() {
  { Literal_Wrapper* self = this;

    if (oTRANSIENTOBJECTSpo) {
      { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oTRANSIENTOBJECTSpo = FALSE;
              { Literal_Wrapper* return_value_001 = self->permanentify_literal();

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
    else {
      return (self->permanentify_literal());
    }
  }
}

Object* permanent_copy(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        if (nilP(tree)) {
          return (tree);
        }
        else {
          { Cons* cons = new_cons();

            cons->value = permanent_copy(tree->value);
            cons->rest = ((Cons*)(permanent_copy(tree->rest)));
            return (cons);
          }
        }
      }
    }
    else {
      return (tree->permanentify());
    }
  }
}

Symbol* Symbol::soft_permanentify() {
  { Symbol* symbol = this;

    return (symbol);
  }
}

Symbol* Transient_Symbol::soft_permanentify() {
  { Transient_Symbol* symbol = this;

    { Generalized_Symbol* permanentsymbol = lookup_rigid_symbol_wrt_module(symbol->symbol_name, ((((Module*)(symbol->home_context)) != NULL) ? ((Module*)(((Module*)(symbol->home_context)))) : ((Module*)(oMODULEo))), SYMBOL_SYM);

      if (permanentsymbol != NULL) {
        return (((Symbol*)(permanentsymbol)));
      }
      else {
        return (symbol);
      }
    }
  }
}

void print_character(char renamed_Char, ostream* stream) {
  *(stream) << "#\\";
  switch (renamed_Char) {
    case '\n': 
      *(stream) << "Newline";
    break;
    case '\b': 
      *(stream) << "Backspace";
    break;
    case '\t': 
      *(stream) << "Tab";
    break;
    case '\r': 
      *(stream) << "Return";
    break;
    case '\f': 
      *(stream) << "Page";
    break;
    default:
      *(stream) << renamed_Char;
    break;
  }
}

char upcase_character(char renamed_Char) {
  { int charcode = character_code(renamed_Char);

    if ((charcode >= character_code('a')) &&
        (charcode <= character_code('z'))) {
      return (code_character(character_code('A') + (charcode - character_code('a'))));
    }
    else {
      return (renamed_Char);
    }
  }
}

char downcase_character(char renamed_Char) {
  { int charcode = character_code(renamed_Char);

    if ((charcode >= character_code('A')) &&
        (charcode <= character_code('Z'))) {
      return (code_character(character_code('a') + (charcode - character_code('A'))));
    }
    else {
      return (renamed_Char);
    }
  }
}

void print_string_readably(char* string, ostream* stream) {
  *(stream) << "\"";
  { int i = NULL_INTEGER;
    int iter_001 = 0;
    int upper_bound_001 = string_length(string) - 1;

    while (iter_001 <= upper_bound_001) {
      {
        i = iter_001;
        iter_001 = iter_001 + 1;
      }
      { char renamed_Char = string_nth(string, i);

        if ((renamed_Char == '"') ||
            (renamed_Char == '\\')) {
          *(stream) << "\\" << renamed_Char;
        }
        else {
          *(stream) << renamed_Char;
        }
      }
    }
  }
  *(stream) << "\"";
}

void startup_literals() {
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
            SGT_LITERALS_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", NULL, 1)));
            KWD_LITERALS_NULL_WRAPPER = ((Keyword*)(intern_rigid_symbol_wrt_module("NULL-WRAPPER", NULL, 2)));
            SYM_LITERALS_NULL_BOOLEAN_WRAPPER = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-BOOLEAN-WRAPPER", NULL, 0)));
            SGT_LITERALS_INTEGER = ((Surrogate*)(intern_rigid_symbol_wrt_module("INTEGER", NULL, 1)));
            SYM_LITERALS_NULL_INTEGER_WRAPPER = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-INTEGER-WRAPPER", NULL, 0)));
            SGT_LITERALS_FLOAT = ((Surrogate*)(intern_rigid_symbol_wrt_module("FLOAT", NULL, 1)));
            SYM_LITERALS_NULL_FLOAT_WRAPPER = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-FLOAT-WRAPPER", NULL, 0)));
            SGT_LITERALS_STRING = ((Surrogate*)(intern_rigid_symbol_wrt_module("STRING", NULL, 1)));
            SYM_LITERALS_NULL_STRING_WRAPPER = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-STRING-WRAPPER", NULL, 0)));
            SGT_LITERALS_CHARACTER = ((Surrogate*)(intern_rigid_symbol_wrt_module("CHARACTER", NULL, 1)));
            SYM_LITERALS_NULL_CHARACTER_WRAPPER = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-CHARACTER-WRAPPER", NULL, 0)));
            SGT_LITERALS_FUNCTION_CODE = ((Surrogate*)(intern_rigid_symbol_wrt_module("FUNCTION-CODE", NULL, 1)));
            SYM_LITERALS_NULL_FUNCTION_CODE_WRAPPER = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-FUNCTION-CODE-WRAPPER", NULL, 0)));
            SGT_LITERALS_METHOD_CODE = ((Surrogate*)(intern_rigid_symbol_wrt_module("METHOD-CODE", NULL, 1)));
            SYM_LITERALS_NULL_METHOD_CODE_WRAPPER = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-METHOD-CODE-WRAPPER", NULL, 0)));
            KWD_LITERALS_WRAP_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("WRAP-FUNCTION", NULL, 2)));
            SYM_LITERALS_WRAP_BOOLEAN = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-BOOLEAN", NULL, 0)));
            SYM_LITERALS_WRAP_INTEGER = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-INTEGER", NULL, 0)));
            SYM_LITERALS_WRAP_FLOAT = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-FLOAT", NULL, 0)));
            SYM_LITERALS_WRAP_STRING = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-STRING", NULL, 0)));
            SYM_LITERALS_WRAP_CHARACTER = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-CHARACTER", NULL, 0)));
            SYM_LITERALS_WRAP_FUNCTION_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-FUNCTION-CODE", NULL, 0)));
            SYM_LITERALS_WRAP_METHOD_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-METHOD-CODE", NULL, 0)));
            SYM_LITERALS_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", NULL, 0)));
            SYM_LITERALS_NIL = ((Symbol*)(intern_rigid_symbol_wrt_module("NIL", NULL, 0)));
            SYM_LITERALS_CONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CONS", NULL, 0)));
            SYM_LITERALS_WRAP_LITERAL = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-LITERAL", NULL, 0)));
            SYM_LITERALS_GET_KWD = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-KWD", NULL, 0)));
            SYM_LITERALS_TYPED_SYS = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPED-SYS", NULL, 0)));
            SGT_LITERALS_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("SYMBOL", NULL, 1)));
            SYM_LITERALS_GET_SGT = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-SGT", NULL, 0)));
            SYM_LITERALS_INTERN_COMMON_LISP_SYMBOL = ((Symbol*)(intern_rigid_symbol_wrt_module("INTERN-COMMON-LISP-SYMBOL", NULL, 0)));
            SYM_LITERALS_GET_SYM = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-SYM", NULL, 0)));
            SYM_LITERALS_LISTo = ((Symbol*)(intern_rigid_symbol_wrt_module("LIST*", NULL, 0)));
            SYM_LITERALS_a = ((Symbol*)(intern_rigid_symbol_wrt_module("&", NULL, 0)));
            SYM_LITERALS_aa = ((Symbol*)(intern_rigid_symbol_wrt_module("&&", NULL, 0)));
            SYM_LITERALS_CONCATENATE = ((Symbol*)(intern_rigid_symbol_wrt_module("CONCATENATE", NULL, 0)));
          }
          if (current_startup_time_phaseP(4)) {
            ZERO_WRAPPER = new_integer_wrapper(0);
            ONE_WRAPPER = new_integer_wrapper(1);
            FALSE_WRAPPER = new_boolean_wrapper(FALSE);
            TRUE_WRAPPER = new_boolean_wrapper(TRUE);
            NULL_BOOLEAN_WRAPPER = new_boolean_wrapper(NULL_BOOLEAN);
            NULL_INTEGER_WRAPPER = new_integer_wrapper(NULL_INTEGER);
            NULL_FLOAT_WRAPPER = new_float_wrapper(NULL_FLOAT);
            NULL_STRING_WRAPPER = new_string_wrapper(NULL);
            NULL_CHARACTER_WRAPPER = new_character_wrapper(NULL_CHARACTER);
            NULL_FUNCTION_CODE_WRAPPER = new_function_code_wrapper(NULL);
            NULL_METHOD_CODE_WRAPPER = new_method_code_wrapper(((cpp_method_code)(NULL)));
            oLITERAL_TYPE_INFO_TABLEo = new_hash_table();
            oLITERAL_TYPESo = new_list();
            set_literal_type_info(SGT_LITERALS_BOOLEAN, KWD_LITERALS_NULL_WRAPPER, SYM_LITERALS_NULL_BOOLEAN_WRAPPER);
            set_literal_type_info(SGT_LITERALS_INTEGER, KWD_LITERALS_NULL_WRAPPER, SYM_LITERALS_NULL_INTEGER_WRAPPER);
            set_literal_type_info(SGT_LITERALS_FLOAT, KWD_LITERALS_NULL_WRAPPER, SYM_LITERALS_NULL_FLOAT_WRAPPER);
            set_literal_type_info(SGT_LITERALS_STRING, KWD_LITERALS_NULL_WRAPPER, SYM_LITERALS_NULL_STRING_WRAPPER);
            set_literal_type_info(SGT_LITERALS_CHARACTER, KWD_LITERALS_NULL_WRAPPER, SYM_LITERALS_NULL_CHARACTER_WRAPPER);
            set_literal_type_info(SGT_LITERALS_FUNCTION_CODE, KWD_LITERALS_NULL_WRAPPER, SYM_LITERALS_NULL_FUNCTION_CODE_WRAPPER);
            set_literal_type_info(SGT_LITERALS_METHOD_CODE, KWD_LITERALS_NULL_WRAPPER, SYM_LITERALS_NULL_METHOD_CODE_WRAPPER);
            set_literal_type_info(SGT_LITERALS_BOOLEAN, KWD_LITERALS_WRAP_FUNCTION, SYM_LITERALS_WRAP_BOOLEAN);
            set_literal_type_info(SGT_LITERALS_INTEGER, KWD_LITERALS_WRAP_FUNCTION, SYM_LITERALS_WRAP_INTEGER);
            set_literal_type_info(SGT_LITERALS_FLOAT, KWD_LITERALS_WRAP_FUNCTION, SYM_LITERALS_WRAP_FLOAT);
            set_literal_type_info(SGT_LITERALS_STRING, KWD_LITERALS_WRAP_FUNCTION, SYM_LITERALS_WRAP_STRING);
            set_literal_type_info(SGT_LITERALS_CHARACTER, KWD_LITERALS_WRAP_FUNCTION, SYM_LITERALS_WRAP_CHARACTER);
            set_literal_type_info(SGT_LITERALS_FUNCTION_CODE, KWD_LITERALS_WRAP_FUNCTION, SYM_LITERALS_WRAP_FUNCTION_CODE);
            set_literal_type_info(SGT_LITERALS_METHOD_CODE, KWD_LITERALS_WRAP_FUNCTION, SYM_LITERALS_WRAP_METHOD_CODE);
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-WRAPPER?", "WRAPPER", "(DEFMETHOD (TERMINATE-WRAPPER? BOOLEAN) ((SELF WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Wrapper::terminate_wrapperP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-WRAPPER?", "INTEGER-WRAPPER", "(DEFMETHOD (TERMINATE-WRAPPER? BOOLEAN) ((SELF INTEGER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Integer_Wrapper::terminate_wrapperP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-LITERAL-TYPE-INFO", "TYPE", "(DEFUN (LOOKUP-LITERAL-TYPE-INFO OBJECT) ((TYPE TYPE) (KEY KEYWORD)))");

              method->function_code = ((cpp_function_code)(&lookup_literal_type_info));
            }
            { Method_Slot* method = define_method_from_stringified_source("SET-LITERAL-TYPE-INFO", "TYPE", "(DEFUN SET-LITERAL-TYPE-INFO ((TYPE TYPE) (KEY KEYWORD) (VALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&set_literal_type_info));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-BOOLEAN", "BOOLEAN", "(DEFUN (WRAP-BOOLEAN BOOLEAN-WRAPPER) ((VALUE BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&wrap_boolean));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-INTEGER", "INTEGER", "(DEFUN (WRAP-INTEGER INTEGER-WRAPPER) ((VALUE INTEGER)))");

              method->function_code = ((cpp_function_code)(&wrap_integer));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-FLOAT", "FLOAT", "(DEFUN (WRAP-FLOAT FLOAT-WRAPPER) ((VALUE FLOAT)))");

              method->function_code = ((cpp_function_code)(&wrap_float));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-STRING", "STRING", "(DEFUN (WRAP-STRING STRING-WRAPPER) ((VALUE STRING)))");

              method->function_code = ((cpp_function_code)(&wrap_string));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-CHARACTER", "CHARACTER", "(DEFUN (WRAP-CHARACTER CHARACTER-WRAPPER) ((VALUE CHARACTER)))");

              method->function_code = ((cpp_function_code)(&wrap_character));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-FUNCTION-CODE", "FUNCTION-CODE", "(DEFUN (WRAP-FUNCTION-CODE FUNCTION-CODE-WRAPPER) ((VALUE FUNCTION-CODE)))");

              method->function_code = ((cpp_function_code)(&wrap_function_code));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-METHOD-CODE", "METHOD-CODE", "(DEFUN (WRAP-METHOD-CODE METHOD-CODE-WRAPPER) ((VALUE METHOD-CODE)))");

              method->function_code = ((cpp_function_code)(&wrap_method_code));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-LITERAL", "INTEGER", "(DEFMETHOD (WRAP-LITERAL INTEGER-WRAPPER) ((VALUE INTEGER)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-LITERAL", "FLOAT", "(DEFMETHOD (WRAP-LITERAL FLOAT-WRAPPER) ((VALUE FLOAT)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-LITERAL", "STRING", "(DEFMETHOD (WRAP-LITERAL STRING-WRAPPER) ((VALUE STRING)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-LITERAL", "CHARACTER", "(DEFMETHOD (WRAP-LITERAL CHARACTER-WRAPPER) ((VALUE CHARACTER)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-LITERAL", "FUNCTION-CODE", "(DEFMETHOD (WRAP-LITERAL FUNCTION-CODE-WRAPPER) ((VALUE FUNCTION-CODE)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-LITERAL", "METHOD-CODE", "(DEFMETHOD (WRAP-LITERAL METHOD-CODE-WRAPPER) ((VALUE METHOD-CODE)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-WRAPPED-LITERAL", "STANDARD-OBJECT", "(DEFMETHOD (COPY-WRAPPED-LITERAL OBJECT) ((SELF STANDARD-OBJECT)))");

              method->method_code = ((cpp_method_code)(&Standard_Object::copy_wrapped_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-WRAPPED-LITERAL", "INTEGER-WRAPPER", "(DEFMETHOD (COPY-WRAPPED-LITERAL OBJECT) ((SELF INTEGER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Integer_Wrapper::copy_wrapped_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-WRAPPED-LITERAL", "FLOAT-WRAPPER", "(DEFMETHOD (COPY-WRAPPED-LITERAL OBJECT) ((SELF FLOAT-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Float_Wrapper::copy_wrapped_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-WRAPPED-LITERAL", "STRING-WRAPPER", "(DEFMETHOD (COPY-WRAPPED-LITERAL OBJECT) ((SELF STRING-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&String_Wrapper::copy_wrapped_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-WRAPPED-LITERAL", "CHARACTER-WRAPPER", "(DEFMETHOD (COPY-WRAPPED-LITERAL OBJECT) ((SELF CHARACTER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Character_Wrapper::copy_wrapped_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-WRAPPED-LITERAL", "FUNCTION-CODE-WRAPPER", "(DEFMETHOD (COPY-WRAPPED-LITERAL OBJECT) ((SELF FUNCTION-CODE-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Function_Code_Wrapper::copy_wrapped_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-WRAPPED-LITERAL", "METHOD-CODE-WRAPPER", "(DEFMETHOD (COPY-WRAPPED-LITERAL OBJECT) ((SELF METHOD-CODE-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Method_Code_Wrapper::copy_wrapped_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("OBJECT-EQL?", "OBJECT", "(DEFMETHOD (OBJECT-EQL? BOOLEAN) ((X OBJECT) (Y OBJECT)))");

              method->method_code = ((cpp_method_code)(&Object::object_eqlP));
            }
            { Method_Slot* method = define_method_from_stringified_source("OBJECT-EQL?", "STANDARD-OBJECT", "(DEFMETHOD (OBJECT-EQL? BOOLEAN) ((X STANDARD-OBJECT) (Y OBJECT)))");

              method->method_code = ((cpp_method_code)(&Standard_Object::object_eqlP));
            }
            { Method_Slot* method = define_method_from_stringified_source("OBJECT-EQL?", "INTEGER-WRAPPER", "(DEFMETHOD (OBJECT-EQL? BOOLEAN) ((X INTEGER-WRAPPER) (Y OBJECT)))");

              method->method_code = ((cpp_method_code)(&Integer_Wrapper::object_eqlP));
            }
            { Method_Slot* method = define_method_from_stringified_source("OBJECT-EQL?", "FLOAT-WRAPPER", "(DEFMETHOD (OBJECT-EQL? BOOLEAN) ((X FLOAT-WRAPPER) (Y OBJECT)))");

              method->method_code = ((cpp_method_code)(&Float_Wrapper::object_eqlP));
            }
            { Method_Slot* method = define_method_from_stringified_source("OBJECT-EQL?", "BOOLEAN-WRAPPER", "(DEFMETHOD (OBJECT-EQL? BOOLEAN) ((X BOOLEAN-WRAPPER) (Y OBJECT)))");

              method->method_code = ((cpp_method_code)(&Boolean_Wrapper::object_eqlP));
            }
            { Method_Slot* method = define_method_from_stringified_source("OBJECT-EQL?", "STRING-WRAPPER", "(DEFMETHOD (OBJECT-EQL? BOOLEAN) ((X STRING-WRAPPER) (Y OBJECT)))");

              method->method_code = ((cpp_method_code)(&String_Wrapper::object_eqlP));
            }
            { Method_Slot* method = define_method_from_stringified_source("OBJECT-EQL?", "CHARACTER-WRAPPER", "(DEFMETHOD (OBJECT-EQL? BOOLEAN) ((X CHARACTER-WRAPPER) (Y OBJECT)))");

              method->method_code = ((cpp_method_code)(&Character_Wrapper::object_eqlP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EQL?", "OBJECT", "(DEFUN (EQL? BOOLEAN) ((X OBJECT) (Y OBJECT)) :DOCUMENTATION \"'eql?' translates into the C++ '==' except that \n   (1) it tests for string equivalence when its first argument is a string,\n   and (2) it understands wrapped literals.\")");

              method->function_code = ((cpp_function_code)(&eqlP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EQL-TO-BOOLEAN?", "OBJECT", "(DEFUN (EQL-TO-BOOLEAN? BOOLEAN) ((Y OBJECT) (X BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&eql_to_booleanP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EQL-TO-INTEGER?", "OBJECT", "(DEFUN (EQL-TO-INTEGER? BOOLEAN) ((Y OBJECT) (X INTEGER)))");

              method->function_code = ((cpp_function_code)(&eql_to_integerP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EQL-TO-FLOAT?", "OBJECT", "(DEFUN (EQL-TO-FLOAT? BOOLEAN) ((Y OBJECT) (X FLOAT)))");

              method->function_code = ((cpp_function_code)(&eql_to_floatP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EQL-TO-STRING?", "OBJECT", "(DEFUN (EQL-TO-STRING? BOOLEAN) ((Y OBJECT) (X STRING)))");

              method->function_code = ((cpp_function_code)(&eql_to_stringP));
            }
            { Method_Slot* method = define_method_from_stringified_source("EQL-TO-CHARACTER?", "OBJECT", "(DEFUN (EQL-TO-CHARACTER? BOOLEAN) ((Y OBJECT) (X CHARACTER)))");

              method->function_code = ((cpp_function_code)(&eql_to_characterP));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-BQUOTIFY", "OBJECT", "(DEFUN (HELP-BQUOTIFY OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&help_bquotify));
            }
            { Method_Slot* method = define_method_from_stringified_source("BQUOTIFY", "OBJECT", "(DEFUN (BQUOTIFY OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&bquotify));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXPAND-BQUOTE-TREE", "OBJECT", "(DEFUN (EXPAND-BQUOTE-TREE OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&expand_bquote_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMPLIFY-BQUOTE-TREE", "OBJECT", "(DEFUN (SIMPLIFY-BQUOTE-TREE OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&simplify_bquote_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY", "OBJECT", "(DEFMETHOD (PERMANENTIFY OBJECT) ((SELF OBJECT)))");

              method->method_code = ((cpp_method_code)(&Object::permanentify));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY", "SYMBOL", "(DEFMETHOD (PERMANENTIFY SYMBOL) ((SELF SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Symbol::permanentify));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY", "KEYWORD", "(DEFMETHOD (PERMANENTIFY KEYWORD) ((SELF KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Keyword::permanentify));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY", "TRANSIENT-SYMBOL", "(DEFMETHOD (PERMANENTIFY SYMBOL) ((SELF TRANSIENT-SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Transient_Symbol::permanentify));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY", "TRANSIENT-KEYWORD", "(DEFMETHOD (PERMANENTIFY KEYWORD) ((SELF TRANSIENT-KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Transient_Keyword::permanentify));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY-LITERAL", "LITERAL-WRAPPER", "(DEFMETHOD (PERMANENTIFY-LITERAL LITERAL-WRAPPER) ((SELF LITERAL-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Literal_Wrapper::permanentify_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY-LITERAL", "INTEGER-WRAPPER", "(DEFMETHOD (PERMANENTIFY-LITERAL INTEGER-WRAPPER) ((SELF INTEGER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Integer_Wrapper::permanentify_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY-LITERAL", "FLOAT-WRAPPER", "(DEFMETHOD (PERMANENTIFY-LITERAL FLOAT-WRAPPER) ((SELF FLOAT-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Float_Wrapper::permanentify_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY-LITERAL", "STRING-WRAPPER", "(DEFMETHOD (PERMANENTIFY-LITERAL STRING-WRAPPER) ((SELF STRING-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&String_Wrapper::permanentify_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY-LITERAL", "CHARACTER-WRAPPER", "(DEFMETHOD (PERMANENTIFY-LITERAL CHARACTER-WRAPPER) ((SELF CHARACTER-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Character_Wrapper::permanentify_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY-LITERAL", "FUNCTION-CODE-WRAPPER", "(DEFMETHOD (PERMANENTIFY-LITERAL FUNCTION-CODE-WRAPPER) ((SELF FUNCTION-CODE-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Function_Code_Wrapper::permanentify_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY-LITERAL", "METHOD-CODE-WRAPPER", "(DEFMETHOD (PERMANENTIFY-LITERAL METHOD-CODE-WRAPPER) ((SELF METHOD-CODE-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Method_Code_Wrapper::permanentify_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY", "LITERAL-WRAPPER", "(DEFMETHOD (PERMANENTIFY LITERAL-WRAPPER) ((SELF LITERAL-WRAPPER)))");

              method->method_code = ((cpp_method_code)(&Literal_Wrapper::permanentify));
            }
            { Method_Slot* method = define_method_from_stringified_source("PERMANENT-COPY", "OBJECT", "(DEFUN (PERMANENT-COPY OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&permanent_copy));
            }
            { Method_Slot* method = define_method_from_stringified_source("SOFT-PERMANENTIFY", "SYMBOL", "(DEFMETHOD (SOFT-PERMANENTIFY SYMBOL) ((SYMBOL SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Symbol::soft_permanentify));
            }
            { Method_Slot* method = define_method_from_stringified_source("SOFT-PERMANENTIFY", "TRANSIENT-SYMBOL", "(DEFMETHOD (SOFT-PERMANENTIFY SYMBOL) ((SYMBOL TRANSIENT-SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Transient_Symbol::soft_permanentify));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-CHARACTER", "CHARACTER", "(DEFUN PRINT-CHARACTER ((CHAR CHARACTER) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_character));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPCASE-CHARACTER", "CHARACTER", "(DEFUN (UPCASE-CHARACTER CHARACTER) ((CHAR CHARACTER)))");

              method->function_code = ((cpp_function_code)(&upcase_character));
            }
            { Method_Slot* method = define_method_from_stringified_source("DOWNCASE-CHARACTER", "CHARACTER", "(DEFUN (DOWNCASE-CHARACTER CHARACTER) ((CHAR CHARACTER)))");

              method->function_code = ((cpp_function_code)(&downcase_character));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-STRING-READABLY", "STRING", "(DEFUN PRINT-STRING-READABLY ((STRING STRING) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_string_readably));
            }
            define_method_from_stringified_source("STARTUP-LITERALS", NULL, "(DEFUN STARTUP-LITERALS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL ZERO-WRAPPER INTEGER-WRAPPER (NEW INTEGER-WRAPPER :WRAPPER-VALUE 0))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL ONE-WRAPPER INTEGER-WRAPPER (NEW INTEGER-WRAPPER :WRAPPER-VALUE 1))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL FALSE-WRAPPER BOOLEAN-WRAPPER (NEW BOOLEAN-WRAPPER :WRAPPER-VALUE FALSE))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL TRUE-WRAPPER BOOLEAN-WRAPPER (NEW BOOLEAN-WRAPPER :WRAPPER-VALUE TRUE))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL NULL-BOOLEAN-WRAPPER BOOLEAN-WRAPPER (NEW BOOLEAN-WRAPPER :WRAPPER-VALUE NULL-BOOLEAN))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL NULL-INTEGER-WRAPPER INTEGER-WRAPPER (NEW INTEGER-WRAPPER :WRAPPER-VALUE NULL))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL NULL-FLOAT-WRAPPER FLOAT-WRAPPER (NEW FLOAT-WRAPPER :WRAPPER-VALUE NULL))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL NULL-STRING-WRAPPER STRING-WRAPPER (NEW STRING-WRAPPER :WRAPPER-VALUE NULL))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL NULL-CHARACTER-WRAPPER CHARACTER-WRAPPER (NEW CHARACTER-WRAPPER :WRAPPER-VALUE NULL))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL NULL-FUNCTION-CODE-WRAPPER FUNCTION-CODE-WRAPPER (NEW FUNCTION-CODE-WRAPPER :WRAPPER-VALUE NULL))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL NULL-METHOD-CODE-WRAPPER METHOD-CODE-WRAPPER (NEW METHOD-CODE-WRAPPER :WRAPPER-VALUE NULL))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *LITERAL-TYPE-INFO-TABLE* (HASH-TABLE OF TYPE (KEY-VALUE-LIST OF KEYWORD OBJECT)) (NEW HASH-TABLE) :DOCUMENTATION \"Table that holds a variety of information about literal\ntypes, e.g., the name of their null-wrapper, wrap-function, etc.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *LITERAL-TYPES* (LIST OF TYPE) (NEW LIST) :DOCUMENTATION \"List of literal types stored in '*literal-type-info-table*'.\nMaintained for iteration purposes.\")");
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

