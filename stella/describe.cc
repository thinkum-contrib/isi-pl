// describe.cc

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

Symbol* SYM_DESCRIBE_BQUOTE = NULL;

Symbol* SYM_DESCRIBE_GET_OBJECT = NULL;

Symbol* SYM_DESCRIBE_GET = NULL;

Symbol* SYM_DESCRIBE_GET_EXPANDER = NULL;

Key_Value_List* oSTRING_TO_OBJECT_FUNCTIONSo = NULL;

List* oINTEGER_TO_OBJECT_FUNCTIONSo = NULL;

Surrogate* SGT_DESCRIBE_CLASS = NULL;

Surrogate* SGT_DESCRIBE_FUNCTION_CODE_WRAPPER = NULL;

Surrogate* SGT_DESCRIBE_OBJECT = NULL;

Surrogate* SGT_DESCRIBE_CONTEXT = NULL;

Surrogate* SGT_DESCRIBE_METHOD_SLOT = NULL;

Surrogate* SGT_DESCRIBE_SLOT = NULL;

Surrogate* SGT_DESCRIBE_DEMON = NULL;

Keyword* oDEFAULT_DESCRIBE_MODEo = NULL;

Keyword* KWD_DESCRIBE_VERBOSE = NULL;

Keyword* KWD_DESCRIBE_TERSE = NULL;

Keyword* KWD_DESCRIBE_SOURCE = NULL;

Symbol* SYM_DESCRIBE_VERBOSE = NULL;

Symbol* SYM_DESCRIBE_TERSE = NULL;

Symbol* SYM_DESCRIBE_SOURCE = NULL;

Symbol* SYM_DESCRIBE_LET = NULL;

Symbol* SYM_DESCRIBE_NAMEEXPRESSION = NULL;

Symbol* SYM_DESCRIBE_OBJECT = NULL;

Symbol* SYM_DESCRIBE_ONLY_IF = NULL;

Symbol* SYM_DESCRIBE_DEFINEDp = NULL;

Symbol* SYM_DESCRIBE_NULL = NULL;

Symbol* SYM_DESCRIBE_IF = NULL;

Symbol* SYM_DESCRIBE_NULLp = NULL;

Symbol* SYM_DESCRIBE_PRINT = NULL;

Symbol* SYM_DESCRIBE_DESCRIBE_OBJECT = NULL;

Symbol* SYM_DESCRIBE_STANDARD_OUTPUT = NULL;

Symbol* SYM_DESCRIBE_DESCRIBE = NULL;

Symbol* SYM_DESCRIBE_DESCRIBE_EXPANDER = NULL;

Keyword* KWD_DESCRIBE_VOID = NULL;

int oPRETTY_PRINT_LIST_CUTOFFo = 5;

Surrogate* SGT_DESCRIBE_LIST = NULL;

Surrogate* SGT_DESCRIBE_ITERATOR = NULL;

Cons* oSLOTOPTIONSLOTSo = NULL;

Symbol* SYM_DESCRIBE_oSLOTOPTIONSLOTSo = NULL;

Cons* oCLASSOPTIONSLOTSo = NULL;

Symbol* SYM_DESCRIBE_oCLASSOPTIONSLOTSo = NULL;

Property_List* oCLASSUNSTRINGIFIEDOPTIONSo = NULL;

Symbol* SYM_DESCRIBE_oCLASSUNSTRINGIFIEDOPTIONSo = NULL;

Symbol* SYM_DESCRIBE_SLOT_OPTION_KEYWORD = NULL;

Surrogate* SGT_DESCRIBE_RELATION = NULL;

Surrogate* SGT_DESCRIBE_STORAGE_SLOT = NULL;

Surrogate* SGT_DESCRIBE_BOOLEAN_WRAPPER = NULL;

Surrogate* SGT_DESCRIBE_LITERAL_WRAPPER = NULL;

Symbol* SYM_DESCRIBE_TRUE = NULL;

Symbol* SYM_DESCRIBE_FALSE = NULL;

Symbol* SYM_DESCRIBE_NULL_BOOLEAN = NULL;

Symbol* SYM_DESCRIBE_SLOT_INITIAL_VALUE = NULL;

Symbol* SYM_DESCRIBE_SLOT_TYPE_SPECIFIER = NULL;

Symbol* SYM_DESCRIBE_SLOT = NULL;

Keyword* KWD_DESCRIBE_OWNER = NULL;

Keyword* KWD_DESCRIBE_TYPE = NULL;

Keyword* KWD_DESCRIBE_INITIALLY = NULL;

Symbol* SYM_DESCRIBE_DEFMODULE = NULL;

Keyword* KWD_DESCRIBE_INCLUDES = NULL;

Keyword* KWD_DESCRIBE_USES = NULL;

Keyword* KWD_DESCRIBE_SHADOWS = NULL;

Symbol* SYM_DESCRIBE_gg_INFERRED_SLOTS = NULL;

Keyword* KWD_DESCRIBE_CHILDREN = NULL;

Keyword* KWD_DESCRIBE_USED_BY = NULL;

Keyword* KWD_DESCRIBE_CARDINAL_MODULE = NULL;

Symbol* SYM_DESCRIBE_DOCUMENTATION = NULL;

Object* get_expander(Object* name, Cons* body) {
  { Object* type = body->first();

    if (symbolP(name)) {
      name = listO(3, SYM_DESCRIBE_BQUOTE, name, NIL);
    }
    if (symbolP(type)) {
      type = listO(3, SYM_DESCRIBE_BQUOTE, type, NIL);
    }
    return (listO(3, SYM_DESCRIBE_GET_OBJECT, name, cons(type, NIL)));
  }
}

Object* Object::get_object(Object* type) {
  { Object* self = this;

    return (search_for_object(self, type));
  }
}

Object* string_get_object(char* self, Object* type) {
  { String_Wrapper* wrappedstring = string_wrap_literal(self);
    Object* object = search_for_object(wrappedstring, type);

    wrappedstring->free();
    return (object);
  }
}

Object* integer_get_object(int self, Object* type) {
  { Integer_Wrapper* wrappedinteger = integer_wrap_literal(self);
    Object* object = search_for_object(wrappedinteger, type);

    wrappedinteger->free();
    return (object);
  }
}

Object* search_for_object(Object* self, Object* typeref) {
  // If 'self' is a string or a symbol, search for an object named
  // 'self' of type 'type'.  Otherwise, if 'self' is an object, return it.
  { Surrogate* classtype = NULL;

    if (typeref != NULL) {
      { Object* typeref_001 = typeref;

        if (symbolP(typeref)) {
          { Symbol* typeref = NULL;

            typeref = ((Symbol*)(typeref_001));
            classtype = lookup_surrogate(typeref->symbol_name);
          }
        }
        else if (surrogateP(typeref)) {
          { Surrogate* typeref = NULL;

            typeref = ((Surrogate*)(typeref_001));
            classtype = typeref;
          }
        }
        else if (stringP(typeref)) {
          { String_Wrapper* typeref = NULL;

            typeref = ((String_Wrapper*)(typeref_001));
            classtype = lookup_surrogate(typeref->wrapper_value);
          }
        }
        else if (classP(typeref)) {
          { Class* typeref = NULL;

            typeref = ((Class*)(typeref_001));
            classtype = typeref->class_type;
          }
        }
        else {
          cout << "Invalid type reference: " << "`" << typeref << "'" << endl;
        }
      }
      if ((classtype != NULL) &&
          ((classtype->surrogate_value == NULL) ||
           (!isaP(classtype->surrogate_value, SGT_DESCRIBE_CLASS)))) {
        cout << "No class exists with name: " << "`" << classtype->symbol_name << "'" << endl;
        classtype = NULL;
      }
    }
    { Object* self_001 = self;

      if (stringP(self)) {
        { String_Wrapper* self = NULL;

          self = ((String_Wrapper*)(self_001));
          { char* string = self->wrapper_value;
            Object* object = NULL;

            { Code_Wrapper* fn = NULL;
              Surrogate* type = NULL;
              Kv_Cons* iter_001 = oSTRING_TO_OBJECT_FUNCTIONSo->the_kv_list;

              while (iter_001 != NULL) {
                type = ((Surrogate*)(iter_001->key));
                {
                  fn = ((Code_Wrapper*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                if ((classtype == NULL) ||
                    subtype_ofP(classtype, type)) {
                  { Code_Wrapper* fn_001 = fn;

                    if (taxonomy_isaP(fn, SGT_DESCRIBE_FUNCTION_CODE_WRAPPER)) {
                      { Function_Code_Wrapper* fn = NULL;

                        fn = ((Function_Code_Wrapper*)(fn_001));
                        object = ((Object* (*) (char*))fn->wrapper_value)(string);
                      }
                    }
                    else {
                      cerr << "`" << fn << "'" << " is not a valid case option";
                    }
                  }
                  if (object != NULL) {
                    return (object);
                  }
                }
              }
            }
            return (NULL);
          }
        }
      }
      else if (symbolP(self)) {
        { Symbol* self = NULL;

          self = ((Symbol*)(self_001));
          return (search_for_object(string_wrap_literal(self->symbol_name), classtype));
        }
      }
      else if (integerP(self)) {
        { Integer_Wrapper* self = NULL;

          self = ((Integer_Wrapper*)(self_001));
          { int integer = self->wrapper_value;
            Object* object = NULL;

            { Code_Wrapper* fn = NULL;
              Cons* iter_002 = oINTEGER_TO_OBJECT_FUNCTIONSo->the_cons_list;

              while (!nilP(iter_002)) {
                {
                  fn = ((Code_Wrapper*)(iter_002->value));
                  iter_002 = iter_002->rest;
                }
                { Code_Wrapper* fn_002 = fn;

                  if (taxonomy_isaP(fn, SGT_DESCRIBE_FUNCTION_CODE_WRAPPER)) {
                    { Function_Code_Wrapper* fn = NULL;

                      fn = ((Function_Code_Wrapper*)(fn_002));
                      object = ((Object* (*) (int))fn->wrapper_value)(integer);
                    }
                  }
                  else {
                    cerr << "`" << fn << "'" << " is not a valid case option";
                  }
                }
                if (object != NULL) {
                  return (object);
                }
              }
            }
            return (NULL);
          }
        }
      }
      else if (taxonomy_isaP(self, SGT_DESCRIBE_OBJECT)) {
        { Object* self = NULL;

          self = ((Object*)(self_001));
          return (self);
        }
      }
      else {
        return (NULL);
      }
    }
  }
}

boolean filter_string_to_classP(Class* self, All_Purpose_Iterator* iterator) {
  if (iterator->iterator_integer == 1) {
    return (string_eqlP(class_name(self), ((String_Wrapper*)(iterator->iterator_object))->wrapper_value));
  }
  else {
    return (string_search(class_name(self), ((String_Wrapper*)(iterator->iterator_object))->wrapper_value, 0) != NULL_INTEGER);
  }
}

Iterator* string_to_classes(char* string, boolean exactP) {
  { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

    iterator->iterator_nested_iterator = all_classes(NULL, FALSE);
    iterator->iterator_filter_code = ((cpp_function_code)(&filter_string_to_classP));
    iterator->iterator_next_code = ((cpp_function_code)(&filtered_nested_iterator_nextP));
    iterator->iterator_object = string_wrap_literal(string);
    iterator->iterator_integer = (exactP ? ((int)(1)) : ((int)(0)));
    return (iterator);
  }
}

Object* string_to_class(char* string) {
  return (string_get_class(string, FALSE));
}

Object* string_to_context(char* string) {
  return (string_slowly_get_context(string));
}

Object* string_to_function(char* string) {
  return (string_lookup_function(string));
}

boolean dotted_stringP(char* string) {
  return (string_position(string, '.', 0) != NULL_INTEGER);
}

char* yield_exploded_method_name(char* dottedstring, char*& return1) {
  { int dotposition = string_position(dottedstring, '.', 0);
    char* firststring = NULL;
    char* secondstring = NULL;

    if (dotposition != NULL_INTEGER) {
      firststring = string_subsequence(dottedstring, 0, dotposition);
      secondstring = string_subsequence(dottedstring, dotposition + 1, NULL_INTEGER);
    }
    { char* return_temp = firststring;

      return1 = secondstring;
      return (return_temp);
    }
  }
}

Object* string_to_slot(char* string) {
  if (dotted_stringP(string)) {
    { char* classstring = NULL;
      char* slotstring = NULL;

      classstring = yield_exploded_method_name(string, slotstring);
      { Class* renamed_Class = string_get_class(classstring, FALSE);
        Symbol* slotname = NULL;

        if (renamed_Class != NULL) {
          slotname = lookup_symbol(slotstring);
          if (slotname != NULL) {
            return (safe_lookup_slot(renamed_Class, slotname));
          }
        }
      }
    }
  }
  else {
    { Symbol* symbol = lookup_symbol(string);

      if (symbol != NULL) {
        return (lookup_function_or_stella_function(symbol));
      }
    }
  }
  return (NULL);
}

Object* string_to_demon(char* string) {
  return (lookup_demon(string));
}

Object* integer_to_context(int integer) {
  return (integer_slowly_get_context(integer));
}

Object* describe_expander(Object* name, Cons* body) {
  // Print a description of an object in :verbose, :terse,
  // or :source modes.
  { Object* mode = body->first();
    Keyword* validmode = NULL;

    if (symbolP(name)) {
      name = listO(3, SYM_DESCRIBE_BQUOTE, name, NIL);
    }
    if (mode == NULL) {
      mode = oDEFAULT_DESCRIBE_MODEo;
    }
    { Object* mode_001 = mode;

      if (keywordP(mode)) {
        { Keyword* mode = NULL;

          mode = ((Keyword*)(mode_001));
          if ((mode == KWD_DESCRIBE_VERBOSE) ||
              ((mode == KWD_DESCRIBE_TERSE) ||
               (mode == KWD_DESCRIBE_SOURCE))) {
            validmode = mode;
          }
          else {
          }
        }
      }
      else if (symbolP(mode)) {
        { Symbol* mode = NULL;

          mode = ((Symbol*)(mode_001));
          if (mode == SYM_DESCRIBE_VERBOSE) {
            validmode = KWD_DESCRIBE_VERBOSE;
          }
          else if (mode == SYM_DESCRIBE_TERSE) {
            validmode = KWD_DESCRIBE_TERSE;
          }
          else if (mode == SYM_DESCRIBE_SOURCE) {
            validmode = KWD_DESCRIBE_SOURCE;
          }
          else {
          }
        }
      }
      else {
      }
    }
    if (validmode == NULL) {
      cout << "Valid modes (the second argument to 'describe') are " << endl << "   :VERBOSE, :TERSE, and :SOURCE" << endl;
      validmode = oDEFAULT_DESCRIBE_MODEo;
    }
    return (listO(4, SYM_DESCRIBE_LET, listO(3, listO(3, SYM_DESCRIBE_NAMEEXPRESSION, name, NIL), listO(3, SYM_DESCRIBE_OBJECT, listO(4, SYM_DESCRIBE_ONLY_IF, listO(3, SYM_DESCRIBE_DEFINEDp, SYM_DESCRIBE_NAMEEXPRESSION, NIL), listO(4, SYM_DESCRIBE_GET_OBJECT, SYM_DESCRIBE_NAMEEXPRESSION, SYM_DESCRIBE_NULL, NIL), NIL), NIL), NIL), listO(5, SYM_DESCRIBE_IF, listO(3, SYM_DESCRIBE_NULLp, SYM_DESCRIBE_OBJECT, NIL), listO(3, SYM_DESCRIBE_PRINT, SYM_DESCRIBE_NULL, NIL), listO(5, SYM_DESCRIBE_DESCRIBE_OBJECT, SYM_DESCRIBE_OBJECT, SYM_DESCRIBE_STANDARD_OUTPUT, mode, NIL), NIL), NIL));
  }
}

void describe_tersely(Object* self, Output_Stream* stream) {
  { ostream* nativestream = stream->native_stream;
    Keyword* result = KWD_DESCRIBE_VOID;

    *(stream->native_stream) << ":TERSE MODE NOT YET IMPLEMENTED";
  }
}

void pretty_print_stella_tree(Cons* tree, Output_Stream* stream) {
  tree = ((Cons*)(consify_lists_and_iterators(tree)));
  { boolean old_OprintprettycodePO_001 = oPRINTPRETTYCODEpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRINTPRETTYCODEpo = TRUE;
          print_stella_code(tree, stream->native_stream);
          oPRINTPRETTYCODEpo = old_OprintprettycodePO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPRINTPRETTYCODEpo = old_OprintprettycodePO_001;
        resignal();
      }
    }
  }
  free_cons_tree(tree);
}

void pretty_print_definition_tree(Cons* tree, Output_Stream* stream) {
  tree = ((Cons*)(consify_lists_and_iterators(tree)));
  { boolean old_OprintprettycodePO_001 = oPRINTPRETTYCODEpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRINTPRETTYCODEpo = TRUE;
          print_stella_definition(tree, stream->native_stream);
          oPRINTPRETTYCODEpo = old_OprintprettycodePO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPRINTPRETTYCODEpo = old_OprintprettycodePO_001;
        resignal();
      }
    }
  }
  free_cons_tree(tree);
}

Object* consify_lists_and_iterators(Object* tree) {
  if (tree == NULL) {
    return (tree);
  }
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Cons_Iterator* cons = tree->allocate_iterator();

          while (cons->nextP()) {
            cons->value_setter(consify_lists_and_iterators(cons->value));
          }
        }
        return (tree);
      }
    }
    else if (taxonomy_isaP(tree, SGT_DESCRIBE_LIST)) {
      { List* tree = NULL;

        tree = ((List*)(tree_001));
        { Cons* conslist = NIL;

          { int i = NULL_INTEGER;
            Object* item = NULL;
            Cons* iter_001 = tree->the_cons_list;
            int iter_002 = 0;
            int upper_bound_001 = oPRETTY_PRINT_LIST_CUTOFFo;
            boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;
            Cons* collect_001 = NULL;

            while ((!nilP(iter_001)) &&
                (unboundedP_001 ||
                 (iter_002 <= upper_bound_001))) {
              {
                item = iter_001->value;
                iter_001 = iter_001->rest;
              }
              {
                i = iter_002;
                iter_002 = iter_002 + 1;
              }
              if (collect_001 == NULL) {
                {
                  collect_001 = cons(((i == oPRETTY_PRINT_LIST_CUTOFFo) ? ((Object*)(ELIPSIS)) : ((Object*)(item))), NIL);
                  if (nilP(conslist)) {
                    conslist = collect_001;
                  }
                  else {
                    add_cons_to_end_of_cons_list(conslist, collect_001);
                  }
                }
              }
              else {
                {
                  collect_001->rest = cons(((i == oPRETTY_PRINT_LIST_CUTOFFo) ? ((Object*)(ELIPSIS)) : ((Object*)(item))), NIL);
                  collect_001 = collect_001->rest;
                }
              }
            }
          }
          return (conslist);
        }
      }
    }
    else if (taxonomy_isaP(tree, SGT_DESCRIBE_ITERATOR)) {
      { Iterator* tree = NULL;

        tree = ((Iterator*)(tree_001));
        { Cons* conslist = NIL;

          { int i = NULL_INTEGER;
            Object* item = NULL;
            Iterator* iter_003 = tree;
            int iter_004 = 0;
            int upper_bound_002 = oPRETTY_PRINT_LIST_CUTOFFo;
            boolean unboundedP_002 = upper_bound_002 == NULL_INTEGER;
            Cons* collect_002 = NULL;

            while (iter_003->nextP() &&
                (unboundedP_002 ||
                 (iter_004 <= upper_bound_002))) {
              {
                item = iter_003->value;
              }
              {
                i = iter_004;
                iter_004 = iter_004 + 1;
              }
              if (collect_002 == NULL) {
                {
                  collect_002 = cons(((i == oPRETTY_PRINT_LIST_CUTOFFo) ? ((Object*)(ELIPSIS)) : ((Object*)(item))), NIL);
                  if (nilP(conslist)) {
                    conslist = collect_002;
                  }
                  else {
                    add_cons_to_end_of_cons_list(conslist, collect_002);
                  }
                }
              }
              else {
                {
                  collect_002->rest = cons(((i == oPRETTY_PRINT_LIST_CUTOFFo) ? ((Object*)(ELIPSIS)) : ((Object*)(item))), NIL);
                  collect_002 = collect_002->rest;
                }
              }
            }
          }
          return (conslist);
        }
      }
    }
    else {
      return (tree);
    }
  }
}

void Module::print_definition(Stream* stream) {
  { Module* self = this;

    { Cons* options = ((Cons*)(unstringify(self->stringified_options)));

      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              *(((Output_Stream*)(stream))->native_stream) << "(defmodule \"" << self->module_full_name << "\"";
              while (!options->emptyP()) {
                *(((Output_Stream*)(stream))->native_stream) << endl << "  " << options->first() << " " << options->second();
                options = options->nth_rest(2);
              }
              *(((Output_Stream*)(stream))->native_stream) << ")" << endl;
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

void print_class_list(Iterator* self, Output_Stream* stream) {
  *(stream->native_stream) << "(";
  if (self->nextP()) {
    *(stream->native_stream) << ((Class*)(self->value))->class_type->symbol_name;
  }
  while (self->nextP()) {
    *(stream->native_stream) << " " << ((Class*)(self->value))->class_type->symbol_name;
  }
  *(stream->native_stream) << ")";
}

void Slot::pretty_print_object(Output_Stream* stream) {
  { Slot* self = this;

    stream = stream;
  }
}

Cons* read_OslotoptionslotsO() {
  return (oSLOTOPTIONSLOTSo);
}

Cons* write_OslotoptionslotsO(Cons* value) {
  oSLOTOPTIONSLOTSo = value;
  return (value);
}

Cons* read_OclassoptionslotsO() {
  return (oCLASSOPTIONSLOTSo);
}

Cons* write_OclassoptionslotsO(Cons* value) {
  oCLASSOPTIONSLOTSo = value;
  return (value);
}

Property_List* read_OclassunstringifiedoptionsO() {
  return (oCLASSUNSTRINGIFIEDOPTIONSo);
}

Property_List* write_OclassunstringifiedoptionsO(Property_List* value) {
  oCLASSUNSTRINGIFIEDOPTIONSo = value;
  return (value);
}

Cons* get_class_options() {
  { Cons* result = NIL;

    { Storage_Slot* slot = NULL;
      Iterator* iter_001 = private_class_storage_slots(((Class*)(SGT_DESCRIBE_CLASS->surrogate_value)));
      Cons* collect_001 = NULL;

      while (iter_001->nextP()) {
        {
          slot = ((Storage_Slot*)(iter_001->value));
        }
        if (((Keyword*)(dynamic_slot_value(slot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL))) != NULL) {
          if (collect_001 == NULL) {
            {
              collect_001 = cons(slot, NIL);
              if (nilP(result)) {
                result = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(result, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = cons(slot, NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
    }
    { Storage_Slot* slot = NULL;
      Iterator* iter_002 = public_class_storage_slots(((Class*)(SGT_DESCRIBE_CLASS->surrogate_value)));
      Cons* collect_002 = NULL;

      while (iter_002->nextP()) {
        {
          slot = ((Storage_Slot*)(iter_002->value));
        }
        if (((Keyword*)(dynamic_slot_value(slot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL))) != NULL) {
          if (collect_002 == NULL) {
            {
              collect_002 = cons(slot, NIL);
              if (nilP(result)) {
                result = collect_002;
              }
              else {
                add_cons_to_end_of_cons_list(result, collect_002);
              }
            }
          }
          else {
            {
              collect_002->rest = cons(slot, NIL);
              collect_002 = collect_002->rest;
            }
          }
        }
      }
    }
    { Storage_Slot* slot = NULL;
      Iterator* iter_003 = private_class_storage_slots(((Class*)(SGT_DESCRIBE_RELATION->surrogate_value)));
      Cons* collect_003 = NULL;

      while (iter_003->nextP()) {
        {
          slot = ((Storage_Slot*)(iter_003->value));
        }
        if (((Keyword*)(dynamic_slot_value(slot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL))) != NULL) {
          if (collect_003 == NULL) {
            {
              collect_003 = cons(slot, NIL);
              if (nilP(result)) {
                result = collect_003;
              }
              else {
                add_cons_to_end_of_cons_list(result, collect_003);
              }
            }
          }
          else {
            {
              collect_003->rest = cons(slot, NIL);
              collect_003 = collect_003->rest;
            }
          }
        }
      }
    }
    { Storage_Slot* slot = NULL;
      Iterator* iter_004 = public_class_storage_slots(((Class*)(SGT_DESCRIBE_RELATION->surrogate_value)));
      Cons* collect_004 = NULL;

      while (iter_004->nextP()) {
        {
          slot = ((Storage_Slot*)(iter_004->value));
        }
        if (((Keyword*)(dynamic_slot_value(slot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL))) != NULL) {
          if (collect_004 == NULL) {
            {
              collect_004 = cons(slot, NIL);
              if (nilP(result)) {
                result = collect_004;
              }
              else {
                add_cons_to_end_of_cons_list(result, collect_004);
              }
            }
          }
          else {
            {
              collect_004->rest = cons(slot, NIL);
              collect_004 = collect_004->rest;
            }
          }
        }
      }
    }
    return (result);
  }
}

Property_List* get_unstringified_class_options(Class* renamed_Class) {
  { Property_List* theoptions = new_property_list();

    theoptions->the_plist = ((Cons*)(unstringify(renamed_Class->class_stringified_source)))->rest->rest->rest;
    return (theoptions);
  }
}

Cons* get_slot_options() {
  { Cons* result = NIL;

    { Storage_Slot* slot = NULL;
      Iterator* iter_001 = private_class_storage_slots(((Class*)(SGT_DESCRIBE_STORAGE_SLOT->surrogate_value)));
      Cons* collect_001 = NULL;

      while (iter_001->nextP()) {
        {
          slot = ((Storage_Slot*)(iter_001->value));
        }
        if (((Keyword*)(dynamic_slot_value(slot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL))) != NULL) {
          if (collect_001 == NULL) {
            {
              collect_001 = cons(slot, NIL);
              if (nilP(result)) {
                result = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(result, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = cons(slot, NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
    }
    return (result);
  }
}

void pretty_print_literal(Object* literal, Output_Stream* stream) {
  { Object* literal_001 = literal;

    if (booleanP(literal)) {
      { Boolean_Wrapper* literal = NULL;

        literal = ((Boolean_Wrapper*)(literal_001));
        if (eqlP(literal, TRUE_WRAPPER)) {
          *(stream->native_stream) << "TRUE";
        }
        else {
          *(stream->native_stream) << "FALSE";
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
              *(stream->native_stream) << literal;
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

boolean literal_eqlP(Object* x, Object* y) {
  if (((x != NULL) &&
      isaP(x, SGT_DESCRIBE_BOOLEAN_WRAPPER)) ||
      ((y != NULL) &&
       isaP(y, SGT_DESCRIBE_BOOLEAN_WRAPPER))) {
    return (((((Boolean_Wrapper*)(x)) == NULL) &&
        (!((Boolean_Wrapper*)(y))->wrapper_value)) ||
        (((((Boolean_Wrapper*)(y)) == NULL) &&
        (!((Boolean_Wrapper*)(x))->wrapper_value)) ||
         eqlP(x, y)));
  }
  return (eqlP(x, y));
}

Object* convert_to_literal(Object* object) {
  if (object == NULL) {
    return (object);
  }
  { Object* object_001 = object;

    if (taxonomy_isaP(object, SGT_DESCRIBE_LITERAL_WRAPPER)) {
      { Literal_Wrapper* object = NULL;

        object = ((Literal_Wrapper*)(object_001));
        return (object);
      }
    }
    else if (symbolP(object)) {
      { Symbol* object = NULL;

        object = ((Symbol*)(object_001));
        if (object == SYM_DESCRIBE_TRUE) {
          return (TRUE_WRAPPER);
        }
        if (object == SYM_DESCRIBE_FALSE) {
          return (FALSE_WRAPPER);
        }
        if (object == SYM_DESCRIBE_NULL_BOOLEAN) {
          return (NULL_BOOLEAN_WRAPPER);
        }
        return (object);
      }
    }
    else if (keywordP(object)) {
      { Keyword* object = NULL;

        object = ((Keyword*)(object_001));
        return (object);
      }
    }
    else if (surrogateP(object)) {
      { Surrogate* object = NULL;

        object = ((Surrogate*)(object_001));
        return (object);
      }
    }
    else {
      cerr << "`convert-to-literal': Can't handle non-boolean literals";
      return (NULL);
    }
  }
}

void pretty_print_class_options(Class* renamed_Class, Output_Stream* stream) {
  { Object* optionvalue = NULL;

    { Storage_Slot* optionslot = NULL;
      Cons* iter_001 = oCLASSOPTIONSLOTSo;

      while (!nilP(iter_001)) {
        {
          optionslot = ((Storage_Slot*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        optionvalue = read_slot_value(renamed_Class, optionslot);
        if (optionvalue == NULL) {
          continue;
        }
        { Object* optionvalue_001 = optionvalue;

          if (taxonomy_isaP(optionvalue, SGT_DESCRIBE_LITERAL_WRAPPER)) {
            { Literal_Wrapper* optionvalue = NULL;

              optionvalue = ((Literal_Wrapper*)(optionvalue_001));
              if (!(literal_eqlP(convert_to_literal(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_INITIAL_VALUE, NULL)), optionvalue) ||
                  literal_eqlP(convert_to_literal(optionslot->default_form()), optionvalue))) {
                *(stream->native_stream) << endl << "  :" << string_downcase(((Keyword*)(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL)))->symbol_name) << " ";
                pretty_print_literal(optionvalue, stream);
              }
            }
          }
          else if (symbolP(optionvalue)) {
            { Symbol* optionvalue = NULL;

              optionvalue = ((Symbol*)(optionvalue_001));
              if (!(literal_eqlP(convert_to_literal(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_INITIAL_VALUE, NULL)), optionvalue) ||
                  literal_eqlP(convert_to_literal(optionslot->default_form()), optionvalue))) {
                *(stream->native_stream) << endl << "  :" << string_downcase(((Keyword*)(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL)))->symbol_name) << " ";
                pretty_print_literal(optionvalue, stream);
              }
            }
          }
          else if (keywordP(optionvalue)) {
            { Keyword* optionvalue = NULL;

              optionvalue = ((Keyword*)(optionvalue_001));
              if (!(literal_eqlP(convert_to_literal(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_INITIAL_VALUE, NULL)), optionvalue) ||
                  literal_eqlP(convert_to_literal(optionslot->default_form()), optionvalue))) {
                *(stream->native_stream) << endl << "  :" << string_downcase(((Keyword*)(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL)))->symbol_name) << " ";
                pretty_print_literal(optionvalue, stream);
              }
            }
          }
          else if (surrogateP(optionvalue)) {
            { Surrogate* optionvalue = NULL;

              optionvalue = ((Surrogate*)(optionvalue_001));
              if (!(literal_eqlP(convert_to_literal(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_INITIAL_VALUE, NULL)), optionvalue) ||
                  literal_eqlP(convert_to_literal(optionslot->default_form()), optionvalue))) {
                *(stream->native_stream) << endl << "  :" << string_downcase(((Keyword*)(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL)))->symbol_name) << " ";
                pretty_print_literal(optionvalue, stream);
              }
            }
          }
          else if (taxonomy_isaP(optionvalue, SGT_DESCRIBE_LIST)) {
            { List* optionvalue = NULL;

              optionvalue = ((List*)(optionvalue_001));
              if (!(optionvalue->emptyP() ||
                  ((dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_INITIAL_VALUE, NULL) == optionvalue) ||
                   (optionslot->default_form() == optionvalue)))) {
                { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;
                  boolean old_OprintprettyPO_001 = oPRINTPRETTYpo;

                  { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        oPRINTPRETTYpo = TRUE;
                        *(stream->native_stream) << endl << "  :" << string_downcase(((Keyword*)(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL)))->symbol_name) << " ";
                        *(stream->native_stream) << oCLASSUNSTRINGIFIEDOPTIONSo->lookup(((Keyword*)(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL))));
                        oPRINTPRETTYpo = old_OprintprettyPO_001;
                        oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTPRETTYpo = old_OprintprettyPO_001;
                      oPRINTREADABLYpo = old_OprintreadablyPO_001;
                      resignal();
                    }
                  }
                }
              }
            }
          }
          else if (consP(optionvalue)) {
            { Cons* optionvalue = NULL;

              optionvalue = ((Cons*)(optionvalue_001));
              if (!(optionvalue->emptyP() ||
                  ((dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_INITIAL_VALUE, NULL) == optionvalue) ||
                   (optionslot->default_form() == optionvalue)))) {
                { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;
                  boolean old_OprintprettyPO_002 = oPRINTPRETTYpo;

                  { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                    oEXCEPTIONHANDLERADDRESSo = NULL;
                    if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                        setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                      {
                        oPRINTREADABLYpo = TRUE;
                        oPRINTPRETTYpo = TRUE;
                        *(stream->native_stream) << endl << "  :" << string_downcase(((Keyword*)(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL)))->symbol_name) << " ";
                        *(stream->native_stream) << optionvalue;
                        oPRINTPRETTYpo = old_OprintprettyPO_002;
                        oPRINTREADABLYpo = old_OprintreadablyPO_002;
                      }
                      oEXCEPTIONo = NULL;
                    }
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
                  }
                  if (oEXCEPTIONo != NULL) {
                    if (TRUE) {
                      oPRINTPRETTYpo = old_OprintprettyPO_002;
                      oPRINTREADABLYpo = old_OprintreadablyPO_002;
                      resignal();
                    }
                  }
                }
              }
            }
          }
          else {
          }
        }
      }
    }
  }
}

void pretty_print_slot_options(Storage_Slot* slot, Output_Stream* stream) {
  { Object* slotvalue = NULL;

    { Storage_Slot* optionslot = NULL;
      Cons* iter_001 = oSLOTOPTIONSLOTSo;

      while (!nilP(iter_001)) {
        {
          optionslot = ((Storage_Slot*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        slotvalue = read_slot_value(slot, optionslot);
        if (slotvalue == NULL) {
          continue;
        }
        { Object* slotvalue_001 = slotvalue;

          if (taxonomy_isaP(slotvalue, SGT_DESCRIBE_LITERAL_WRAPPER)) {
            { Literal_Wrapper* slotvalue = NULL;

              slotvalue = ((Literal_Wrapper*)(slotvalue_001));
              if (!literal_eqlP(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_INITIAL_VALUE, NULL), slotvalue)) {
                *(stream->native_stream) << " :" << string_downcase(((Keyword*)(dynamic_slot_value(optionslot, SYM_DESCRIBE_SLOT_OPTION_KEYWORD, NULL)))->symbol_name) << " ";
                pretty_print_literal(slotvalue, stream);
              }
            }
          }
          else {
          }
        }
      }
    }
  }
}

void Storage_Slot::pretty_print_object(Output_Stream* stream) {
  { Storage_Slot* self = this;

    *(stream->native_stream) << "(" << string_downcase(self->slot_name->symbol_name) << " :type ";
    *(stream->native_stream) << (((((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_DESCRIBE_SLOT_TYPE_SPECIFIER, NULL))) != NULL) ? ((char*)(stringify(yield_type_spec_tree(((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_DESCRIBE_SLOT_TYPE_SPECIFIER, NULL))))))) : ((char*)(stringify(yield_type_spec_tree(self->slot_base_type))))));
    pretty_print_slot_options(self, stream);
    *(stream->native_stream) << ")";
  }
}

void pretty_print_method_parameters(Output_Stream* stream, Method_Slot* method) {
  { int lastargindex = (method->method_variable_argumentsP_reader() ? ((int)(method->method_parameter_names_reader()->length())) : ((int)(-1)));

    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            *(stream->native_stream) << "(";
            { int i = NULL_INTEGER;
              Standard_Object* tspec = NULL;
              Symbol* parameter = NULL;
              Cons* iter_001 = method->method_parameter_names_reader()->the_cons_list;
              Cons* iter_002 = method->method_parameter_type_specifiers_reader()->the_cons_list;
              int iter_003 = 1;

              while ((!nilP(iter_001)) &&
                  (!nilP(iter_002))) {
                {
                  parameter = ((Symbol*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                {
                  tspec = ((Standard_Object*)(iter_002->value));
                  iter_002 = iter_002->rest;
                }
                {
                  i = iter_003;
                  iter_003 = iter_003 + 1;
                }
                if (i > 1) {
                  *(stream->native_stream) << " ";
                }
                if (i == lastargindex) {
                  *(stream->native_stream) << "&rest ";
                  tspec = variable_arguments_type(method);
                }
                *(stream->native_stream) << "(" << string_downcase(parameter->symbol_name) << " " << yield_type_spec_tree(tspec) << ")";
              }
            }
            *(stream->native_stream) << ")";
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

void Method_Slot::pretty_print_object(Output_Stream* stream) {
  { Method_Slot* self = this;

    *(stream->native_stream) << "(" << string_downcase(self->slot_name->symbol_name) << " ";
    pretty_print_method_parameters(stream, self);
    *(stream->native_stream) << " :type ";
    *(stream->native_stream) << (((((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_DESCRIBE_SLOT_TYPE_SPECIFIER, NULL))) != NULL) ? ((char*)(stringify(yield_type_spec_tree(((Compound_Type_Specifier*)(dynamic_slot_value(self, SYM_DESCRIBE_SLOT_TYPE_SPECIFIER, NULL))))))) : ((char*)(stringify(yield_type_spec_tree(self->slot_base_type))))));
    *(stream->native_stream) << ")";
  }
}

void pretty_print_slot_block(Output_Stream* stream, Iterator* iterator, char* slotgroup) {
  if (iterator->nextP()) {
    { Slot* slot = ((Slot*)(iterator->value));

      *(stream->native_stream) << endl << "  " << slotgroup << endl << "  (";
      slot->pretty_print_object(stream);
    }
  }
  else {
    return;
  }
  { Slot* slot = NULL;
    Iterator* iter_001 = iterator;

    while (iter_001->nextP()) {
      {
        slot = ((Slot*)(iter_001->value));
      }
      *(stream->native_stream) << endl << "   ";
      slot->pretty_print_object(stream);
    }
  }
  *(stream->native_stream) << ")";
}

void pretty_print_slots(Class* self, Output_Stream* stream) {
  pretty_print_slot_block(stream, public_class_storage_slots(self), ":public-slots");
  pretty_print_slot_block(stream, private_class_storage_slots(self), ":slots");
  pretty_print_slot_block(stream, public_class_methods(self), ":public-methods");
  pretty_print_slot_block(stream, private_class_methods(self), ":methods");
}

void Class::pretty_print_object(Output_Stream* stream) {
  { Class* self = this;

    { Cons* old_OslotoptionslotsO_001 = oSLOTOPTIONSLOTSo;
      Cons* old_OclassoptionslotsO_001 = oCLASSOPTIONSLOTSo;
      Property_List* old_OclassunstringifiedoptionsO_001 = oCLASSUNSTRINGIFIEDOPTIONSo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oSLOTOPTIONSLOTSo = get_slot_options();
            oCLASSOPTIONSLOTSo = get_class_options();
            oCLASSUNSTRINGIFIEDOPTIONSo = get_unstringified_class_options(self);
            *(stream->native_stream) << "(defclass " << self->class_type->symbol_name << " ";
            print_class_list(new_types_to_classes_iterator(self->class_direct_supers->the_cons_list), stream);
            pretty_print_class_options(self, stream);
            pretty_print_slots(self, stream);
            *(stream->native_stream) << ")" << endl;
            if (class_tables(self, NIL)->nextP()) {
              *(stream->native_stream) << endl;
              { Table* table = NULL;
                Iterator* iter_001 = class_tables(self, NIL);

                while (iter_001->nextP()) {
                  {
                    table = ((Table*)(iter_001->value));
                  }
                  table->pretty_print_object(stream);
                  *(stream->native_stream) << endl;
                }
              }
              *(stream->native_stream) << endl;
            }
            oCLASSUNSTRINGIFIEDOPTIONSo = old_OclassunstringifiedoptionsO_001;
            oCLASSOPTIONSLOTSo = old_OclassoptionslotsO_001;
            oSLOTOPTIONSLOTSo = old_OslotoptionslotsO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oCLASSUNSTRINGIFIEDOPTIONSo = old_OclassunstringifiedoptionsO_001;
          oCLASSOPTIONSLOTSo = old_OclassoptionslotsO_001;
          oSLOTOPTIONSLOTSo = old_OslotoptionslotsO_001;
          resignal();
        }
      }
    }
  }
}

void Object::describe_object(Stream* stream, Keyword* mode) {
  // Prints a description of 'self' to stream 'stream'.  'mode'
  // can be :terse, :verbose, or :source.  The :terse mode is often equivalent
  // to the standard print function.
  { Object* self = this;

    mode = mode;
    describe_tersely(self, ((Output_Stream*)(stream)));
  }
}

void Class::describe_object(Stream* stream, Keyword* mode) {
  { Class* self = this;

    if (mode == KWD_DESCRIBE_SOURCE) {
      pretty_print_definition_tree(((Cons*)(unstringify(self->class_stringified_source))), ((Output_Stream*)(stream)));
    }
    else if (mode == KWD_DESCRIBE_TERSE) {
      describe_tersely(self, ((Output_Stream*)(stream)));
    }
    else if (mode == KWD_DESCRIBE_VERBOSE) {
      *(((Output_Stream*)(stream))->native_stream) << "SOURCE mode:" << endl;
      self->describe_object(stream, KWD_DESCRIBE_SOURCE);
    }
    else {
      cerr << "`" << mode << "'" << " is not a valid case option";
    }
  }
}

void Storage_Slot::describe_object(Stream* stream, Keyword* mode) {
  { Storage_Slot* self = this;

    if (mode == KWD_DESCRIBE_SOURCE) {
      *(((Output_Stream*)(stream))->native_stream) << "TERSE mode:" << endl;
      self->describe_object(stream, KWD_DESCRIBE_TERSE);
    }
    else if (mode == KWD_DESCRIBE_TERSE) {
      describe_tersely(self, ((Output_Stream*)(stream)));
    }
    else if (mode == KWD_DESCRIBE_VERBOSE) {
      pretty_print_definition_tree(listO(3, SYM_DESCRIBE_SLOT, self->slot_name, listO(3, KWD_DESCRIBE_OWNER, string_wrap_literal(self->slot_owner->symbol_name), listO(3, KWD_DESCRIBE_TYPE, self->slot_base_type, listO(3, KWD_DESCRIBE_INITIALLY, dynamic_slot_value(self, SYM_DESCRIBE_SLOT_INITIAL_VALUE, NULL), NIL)))), ((Output_Stream*)(stream)));
    }
    else {
      cerr << "`" << mode << "'" << " is not a valid case option";
    }
  }
}

void Module::describe_object(Stream* stream, Keyword* mode) {
  { Module* self = this;

    if (mode == KWD_DESCRIBE_SOURCE) {
      pretty_print_stella_tree(((Cons*)(unstringify(xmodule_stringified_source(self)))), ((Output_Stream*)(stream)));
    }
    else if (mode == KWD_DESCRIBE_TERSE) {
      describe_tersely(self, ((Output_Stream*)(stream)));
    }
    else if (mode == KWD_DESCRIBE_VERBOSE) {
      pretty_print_definition_tree(listO(3, SYM_DESCRIBE_DEFMODULE, string_wrap_literal(self->module_name), listO(3, KWD_DESCRIBE_INCLUDES, self->parent_modules, listO(3, KWD_DESCRIBE_USES, self->uses, listO(3, KWD_DESCRIBE_SHADOWS, self->shadowed_surrogates_reader(), listO(4, SYM_DESCRIBE_gg_INFERRED_SLOTS, KWD_DESCRIBE_CHILDREN, self->child_contexts, listO(3, KWD_DESCRIBE_USED_BY, self->used_by, listO(3, KWD_DESCRIBE_CARDINAL_MODULE, self->cardinal_module, NIL))))))), ((Output_Stream*)(stream)));
    }
    else {
      cerr << "`" << mode << "'" << " is not a valid case option";
    }
  }
}

char* xmodule_stringified_source(Module* self) {
  return (string_concatenate("(defmodule ", string_concatenate(self->module_name, string_concatenate(" ", string_concatenate(self->stringified_options, ")")))));
}

char* short_documentation(char* documentation) {
  { int lineend = NULL_INTEGER;
    int sentenceend = NULL_INTEGER;

    if (documentation == NULL) {
      documentation = "Not documented.";
    }
    lineend = string_position(documentation, '\n', 0);
    if (lineend == NULL_INTEGER) {
      return (documentation);
    }
    if (string_memberP(".!", string_nth(documentation, lineend - 1))) {
      return (string_subsequence(documentation, 0, lineend));
    }
    sentenceend = string_position(documentation, '.', 0);
    if ((sentenceend != NULL_INTEGER) &&
        (sentenceend <= 155)) {
      return (string_subsequence(documentation, 0, sentenceend + 1));
    }
    else {
      return (string_subsequence(documentation, 0, lineend));
    }
  }
}

void print_documentation_string(char* string, int indent, Output_Stream* stream) {
  { boolean freshlineP = TRUE;

    if (indent == NULL_INTEGER) {
      indent = 0;
    }
    { char renamed_Char = NULL_CHARACTER;
      char* vector_001 = string;
      int index_001 = 0;
      int length_001 = string_length(vector_001);

      while (index_001 < length_001) {
        {
          renamed_Char = string_nth(vector_001, index_001);
          index_001 = index_001 + 1;
        }
        if (freshlineP) {
          { int i = NULL_INTEGER;
            int iter_001 = 1;
            int upper_bound_001 = indent;
            boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

            while (unboundedP_001 ||
                (iter_001 <= upper_bound_001)) {
              {
                i = iter_001;
                iter_001 = iter_001 + 1;
              }
              i = i;
              *(stream->native_stream) << " ";
            }
          }
          freshlineP = FALSE;
        }
        *(stream->native_stream) << renamed_Char;
        if (renamed_Char == '\n') {
          freshlineP = TRUE;
        }
      }
    }
    *(stream->native_stream) << endl;
  }
}

void Method_Slot::print_documentation(Output_Stream* stream, boolean shortP) {
  { Method_Slot* self = this;

    if (stream == NULL) {
      stream = STANDARD_OUTPUT;
    }
    { char* documentation = ((String_Wrapper*)(dynamic_slot_value(self, SYM_DESCRIBE_DOCUMENTATION, NULL_STRING_WRAPPER)))->wrapper_value;

      *(stream->native_stream) << self->slot_name;
      if (!(shortP)) {
        *(stream->native_stream) << " ";
        pretty_print_method_parameters(stream, self);
      }
      *(stream->native_stream) << ":" << endl;
      print_documentation_string((shortP ? ((char*)(short_documentation(documentation))) : ((char*)(documentation))), 2, stream);
    }
  }
}

void startup_describe() {
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
            SYM_DESCRIBE_BQUOTE = ((Symbol*)(intern_rigid_symbol_wrt_module("BQUOTE", NULL, 0)));
            SYM_DESCRIBE_GET_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-OBJECT", NULL, 0)));
            SYM_DESCRIBE_GET = ((Symbol*)(intern_rigid_symbol_wrt_module("GET", NULL, 0)));
            SYM_DESCRIBE_GET_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-EXPANDER", NULL, 0)));
            SGT_DESCRIBE_CLASS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CLASS", NULL, 1)));
            SGT_DESCRIBE_FUNCTION_CODE_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("FUNCTION-CODE-WRAPPER", NULL, 1)));
            SGT_DESCRIBE_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("OBJECT", NULL, 1)));
            SGT_DESCRIBE_CONTEXT = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONTEXT", NULL, 1)));
            SGT_DESCRIBE_METHOD_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("METHOD-SLOT", NULL, 1)));
            SGT_DESCRIBE_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("SLOT", NULL, 1)));
            SGT_DESCRIBE_DEMON = ((Surrogate*)(intern_rigid_symbol_wrt_module("DEMON", NULL, 1)));
            KWD_DESCRIBE_VERBOSE = ((Keyword*)(intern_rigid_symbol_wrt_module("VERBOSE", NULL, 2)));
            KWD_DESCRIBE_TERSE = ((Keyword*)(intern_rigid_symbol_wrt_module("TERSE", NULL, 2)));
            KWD_DESCRIBE_SOURCE = ((Keyword*)(intern_rigid_symbol_wrt_module("SOURCE", NULL, 2)));
            SYM_DESCRIBE_VERBOSE = ((Symbol*)(intern_rigid_symbol_wrt_module("VERBOSE", NULL, 0)));
            SYM_DESCRIBE_TERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("TERSE", NULL, 0)));
            SYM_DESCRIBE_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("SOURCE", NULL, 0)));
            SYM_DESCRIBE_LET = ((Symbol*)(intern_rigid_symbol_wrt_module("LET", NULL, 0)));
            SYM_DESCRIBE_NAMEEXPRESSION = ((Symbol*)(intern_rigid_symbol_wrt_module("NAMEEXPRESSION", NULL, 0)));
            SYM_DESCRIBE_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("OBJECT", NULL, 0)));
            SYM_DESCRIBE_ONLY_IF = ((Symbol*)(intern_rigid_symbol_wrt_module("ONLY-IF", NULL, 0)));
            SYM_DESCRIBE_DEFINEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINED?", NULL, 0)));
            SYM_DESCRIBE_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", NULL, 0)));
            SYM_DESCRIBE_IF = ((Symbol*)(intern_rigid_symbol_wrt_module("IF", NULL, 0)));
            SYM_DESCRIBE_NULLp = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL?", NULL, 0)));
            SYM_DESCRIBE_PRINT = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT", NULL, 0)));
            SYM_DESCRIBE_DESCRIBE_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIBE-OBJECT", NULL, 0)));
            SYM_DESCRIBE_STANDARD_OUTPUT = ((Symbol*)(intern_rigid_symbol_wrt_module("STANDARD-OUTPUT", NULL, 0)));
            SYM_DESCRIBE_DESCRIBE = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIBE", NULL, 0)));
            SYM_DESCRIBE_DESCRIBE_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIBE-EXPANDER", NULL, 0)));
            KWD_DESCRIBE_VOID = ((Keyword*)(intern_rigid_symbol_wrt_module("VOID", NULL, 2)));
            SGT_DESCRIBE_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("LIST", NULL, 1)));
            SGT_DESCRIBE_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("ITERATOR", NULL, 1)));
            SYM_DESCRIBE_oSLOTOPTIONSLOTSo = ((Symbol*)(intern_rigid_symbol_wrt_module("*SLOTOPTIONSLOTS*", NULL, 0)));
            SYM_DESCRIBE_oCLASSOPTIONSLOTSo = ((Symbol*)(intern_rigid_symbol_wrt_module("*CLASSOPTIONSLOTS*", NULL, 0)));
            SYM_DESCRIBE_oCLASSUNSTRINGIFIEDOPTIONSo = ((Symbol*)(intern_rigid_symbol_wrt_module("*CLASSUNSTRINGIFIEDOPTIONS*", NULL, 0)));
            SYM_DESCRIBE_SLOT_OPTION_KEYWORD = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-OPTION-KEYWORD", NULL, 0)));
            SGT_DESCRIBE_RELATION = ((Surrogate*)(intern_rigid_symbol_wrt_module("RELATION", NULL, 1)));
            SGT_DESCRIBE_STORAGE_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT", NULL, 1)));
            SGT_DESCRIBE_BOOLEAN_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN-WRAPPER", NULL, 1)));
            SGT_DESCRIBE_LITERAL_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("LITERAL-WRAPPER", NULL, 1)));
            SYM_DESCRIBE_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            SYM_DESCRIBE_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", NULL, 0)));
            SYM_DESCRIBE_NULL_BOOLEAN = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-BOOLEAN", NULL, 0)));
            SYM_DESCRIBE_SLOT_INITIAL_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-INITIAL-VALUE", NULL, 0)));
            SYM_DESCRIBE_SLOT_TYPE_SPECIFIER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-TYPE-SPECIFIER", NULL, 0)));
            SYM_DESCRIBE_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT", NULL, 0)));
            KWD_DESCRIBE_OWNER = ((Keyword*)(intern_rigid_symbol_wrt_module("OWNER", NULL, 2)));
            KWD_DESCRIBE_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("TYPE", NULL, 2)));
            KWD_DESCRIBE_INITIALLY = ((Keyword*)(intern_rigid_symbol_wrt_module("INITIALLY", NULL, 2)));
            SYM_DESCRIBE_DEFMODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFMODULE", NULL, 0)));
            KWD_DESCRIBE_INCLUDES = ((Keyword*)(intern_rigid_symbol_wrt_module("INCLUDES", NULL, 2)));
            KWD_DESCRIBE_USES = ((Keyword*)(intern_rigid_symbol_wrt_module("USES", NULL, 2)));
            KWD_DESCRIBE_SHADOWS = ((Keyword*)(intern_rigid_symbol_wrt_module("SHADOWS", NULL, 2)));
            SYM_DESCRIBE_gg_INFERRED_SLOTS = ((Symbol*)(intern_rigid_symbol_wrt_module(">>_INFERRED_SLOTS", NULL, 0)));
            KWD_DESCRIBE_CHILDREN = ((Keyword*)(intern_rigid_symbol_wrt_module("CHILDREN", NULL, 2)));
            KWD_DESCRIBE_USED_BY = ((Keyword*)(intern_rigid_symbol_wrt_module("USED-BY", NULL, 2)));
            KWD_DESCRIBE_CARDINAL_MODULE = ((Keyword*)(intern_rigid_symbol_wrt_module("CARDINAL-MODULE", NULL, 2)));
            SYM_DESCRIBE_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 0)));
          }
          if (current_startup_time_phaseP(4)) {
            oSTRING_TO_OBJECT_FUNCTIONSo = new_key_value_list();
            oINTEGER_TO_OBJECT_FUNCTIONSo = list(0);
            oDEFAULT_DESCRIBE_MODEo = KWD_DESCRIBE_VERBOSE;
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("GET-EXPANDER", "OBJECT", "(DEFUN (GET-EXPANDER OBJECT) ((NAME OBJECT) |&BODY| (BODY CONS)))");

              method->function_code = ((cpp_function_code)(&get_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-OBJECT", "OBJECT", "(DEFMETHOD (GET-OBJECT OBJECT) ((SELF OBJECT) (TYPE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Object::get_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-OBJECT", "STRING", "(DEFMETHOD (GET-OBJECT OBJECT) ((SELF STRING) (TYPE OBJECT)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-OBJECT", "INTEGER", "(DEFMETHOD (GET-OBJECT OBJECT) ((SELF INTEGER) (TYPE OBJECT)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("SEARCH-FOR-OBJECT", "OBJECT", "(DEFUN (SEARCH-FOR-OBJECT OBJECT) ((SELF OBJECT) (TYPEREF OBJECT)) :DOCUMENTATION \"If 'self' is a string or a symbol, search for an object named\n'self' of type 'type'.  Otherwise, if 'self' is an object, return it.\")");

              method->function_code = ((cpp_function_code)(&search_for_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-STRING-TO-CLASS?", "CLASS", "(DEFUN (FILTER-STRING-TO-CLASS? BOOLEAN) ((SELF CLASS) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_string_to_classP));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING-TO-CLASSES", "STRING", "(DEFUN (STRING-TO-CLASSES (ITERATOR OF CLASS)) ((STRING STRING) (EXACT? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&string_to_classes));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING-TO-CLASS", "STRING", "(DEFUN (STRING-TO-CLASS OBJECT) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&string_to_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING-TO-CONTEXT", "STRING", "(DEFUN (STRING-TO-CONTEXT OBJECT) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&string_to_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING-TO-FUNCTION", "STRING", "(DEFUN (STRING-TO-FUNCTION OBJECT) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&string_to_function));
            }
            { Method_Slot* method = define_method_from_stringified_source("DOTTED-STRING?", "STRING", "(DEFUN (DOTTED-STRING? BOOLEAN) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&dotted_stringP));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-EXPLODED-METHOD-NAME", "STRING", "(DEFUN (YIELD-EXPLODED-METHOD-NAME STRING STRING) ((DOTTEDSTRING STRING)))");

              method->function_code = ((cpp_function_code)(&yield_exploded_method_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING-TO-SLOT", "STRING", "(DEFUN (STRING-TO-SLOT OBJECT) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&string_to_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING-TO-DEMON", "STRING", "(DEFUN (STRING-TO-DEMON OBJECT) ((STRING STRING)))");

              method->function_code = ((cpp_function_code)(&string_to_demon));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTEGER-TO-CONTEXT", "INTEGER", "(DEFUN (INTEGER-TO-CONTEXT OBJECT) ((INTEGER INTEGER)))");

              method->function_code = ((cpp_function_code)(&integer_to_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIBE-EXPANDER", "OBJECT", "(DEFUN (DESCRIBE-EXPANDER OBJECT) ((NAME OBJECT) |&BODY| (BODY CONS)) :DOCUMENTATION \"Print a description of an object in :verbose, :terse,\nor :source modes.\")");

              method->function_code = ((cpp_function_code)(&describe_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIBE-TERSELY", "OBJECT", "(DEFUN DESCRIBE-TERSELY ((SELF OBJECT) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&describe_tersely));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-STELLA-TREE", "CONS", "(DEFUN PRETTY-PRINT-STELLA-TREE ((TREE CONS) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&pretty_print_stella_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-DEFINITION-TREE", "CONS", "(DEFUN PRETTY-PRINT-DEFINITION-TREE ((TREE CONS) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&pretty_print_definition_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONSIFY-LISTS-AND-ITERATORS", "OBJECT", "(DEFUN (CONSIFY-LISTS-AND-ITERATORS OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&consify_lists_and_iterators));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-DEFINITION", "MODULE", "(DEFMETHOD PRINT-DEFINITION ((SELF MODULE) (STREAM STREAM)))");

              method->method_code = ((cpp_method_code)(&Module::print_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-CLASS-LIST", "ITERATOR", "(DEFUN PRINT-CLASS-LIST ((SELF (ITERATOR OF CLASS)) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_class_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-OBJECT", "SLOT", "(DEFMETHOD PRETTY-PRINT-OBJECT ((SELF SLOT) (STREAM OUTPUT-STREAM)))");

              method->method_code = ((cpp_method_code)(&Slot::pretty_print_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-CLASS-OPTIONS", NULL, "(DEFUN (GET-CLASS-OPTIONS (CONS OF STORAGE-SLOT)) ())");

              method->function_code = ((cpp_function_code)(&get_class_options));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-UNSTRINGIFIED-CLASS-OPTIONS", "CLASS", "(DEFUN (GET-UNSTRINGIFIED-CLASS-OPTIONS PROPERTY-LIST) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&get_unstringified_class_options));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-SLOT-OPTIONS", NULL, "(DEFUN (GET-SLOT-OPTIONS (CONS OF STORAGE-SLOT)) ())");

              method->function_code = ((cpp_function_code)(&get_slot_options));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-LITERAL", "OBJECT", "(DEFUN PRETTY-PRINT-LITERAL ((LITERAL OBJECT) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&pretty_print_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("LITERAL-EQL?", "OBJECT", "(DEFUN (LITERAL-EQL? BOOLEAN) ((X OBJECT) (Y OBJECT)))");

              method->function_code = ((cpp_function_code)(&literal_eqlP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONVERT-TO-LITERAL", "OBJECT", "(DEFUN (CONVERT-TO-LITERAL OBJECT) ((OBJECT OBJECT)))");

              method->function_code = ((cpp_function_code)(&convert_to_literal));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-CLASS-OPTIONS", "CLASS", "(DEFUN PRETTY-PRINT-CLASS-OPTIONS ((CLASS CLASS) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&pretty_print_class_options));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-SLOT-OPTIONS", "STORAGE-SLOT", "(DEFUN PRETTY-PRINT-SLOT-OPTIONS ((SLOT STORAGE-SLOT) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&pretty_print_slot_options));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-OBJECT", "STORAGE-SLOT", "(DEFMETHOD PRETTY-PRINT-OBJECT ((SELF STORAGE-SLOT) (STREAM OUTPUT-STREAM)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::pretty_print_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-METHOD-PARAMETERS", "OUTPUT-STREAM", "(DEFUN PRETTY-PRINT-METHOD-PARAMETERS ((STREAM OUTPUT-STREAM) (METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&pretty_print_method_parameters));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-OBJECT", "METHOD-SLOT", "(DEFMETHOD PRETTY-PRINT-OBJECT ((SELF METHOD-SLOT) (STREAM OUTPUT-STREAM)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::pretty_print_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-SLOT-BLOCK", "OUTPUT-STREAM", "(DEFUN PRETTY-PRINT-SLOT-BLOCK ((STREAM OUTPUT-STREAM) (ITERATOR (ITERATOR OF SLOT)) (SLOTGROUP STRING)))");

              method->function_code = ((cpp_function_code)(&pretty_print_slot_block));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-SLOTS", "CLASS", "(DEFUN PRETTY-PRINT-SLOTS ((SELF CLASS) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&pretty_print_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRETTY-PRINT-OBJECT", "CLASS", "(DEFMETHOD PRETTY-PRINT-OBJECT ((SELF CLASS) (STREAM OUTPUT-STREAM)))");

              method->method_code = ((cpp_method_code)(&Class::pretty_print_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIBE-OBJECT", "OBJECT", "(DEFMETHOD DESCRIBE-OBJECT ((SELF OBJECT) (STREAM STREAM) (MODE KEYWORD)) :DOCUMENTATION \"Prints a description of 'self' to stream 'stream'.  'mode'\ncan be :terse, :verbose, or :source.  The :terse mode is often equivalent\nto the standard print function.\")");

              method->method_code = ((cpp_method_code)(&Object::describe_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIBE-OBJECT", "CLASS", "(DEFMETHOD DESCRIBE-OBJECT ((SELF CLASS) (STREAM STREAM) (MODE KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Class::describe_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIBE-OBJECT", "STORAGE-SLOT", "(DEFMETHOD DESCRIBE-OBJECT ((SELF STORAGE-SLOT) (STREAM STREAM) (MODE KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::describe_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIBE-OBJECT", "MODULE", "(DEFMETHOD DESCRIBE-OBJECT ((SELF MODULE) (STREAM STREAM) (MODE KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Module::describe_object));
            }
            { Method_Slot* method = define_method_from_stringified_source("XMODULE-STRINGIFIED-SOURCE", "MODULE", "(DEFUN (XMODULE-STRINGIFIED-SOURCE STRING) ((SELF MODULE)))");

              method->function_code = ((cpp_function_code)(&xmodule_stringified_source));
            }
            { Method_Slot* method = define_method_from_stringified_source("SHORT-DOCUMENTATION", "STRING", "(DEFUN (SHORT-DOCUMENTATION STRING) ((DOCUMENTATION STRING)))");

              method->function_code = ((cpp_function_code)(&short_documentation));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-DOCUMENTATION-STRING", "STRING", "(DEFUN PRINT-DOCUMENTATION-STRING ((STRING STRING) (INDENT INTEGER) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_documentation_string));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-DOCUMENTATION", "METHOD-SLOT", "(DEFMETHOD PRINT-DOCUMENTATION ((SELF METHOD-SLOT) (STREAM OUTPUT-STREAM) (SHORT? BOOLEAN)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::print_documentation));
            }
            define_method_from_stringified_source("STARTUP-DESCRIBE", NULL, "(DEFUN STARTUP-DESCRIBE ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            store_macro(SYM_DESCRIBE_GET, SYM_DESCRIBE_GET_EXPANDER, ((cpp_function_code)(&get_expander)));
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *STRING-TO-OBJECT-FUNCTIONS* (KEY-VALUE-LIST OF TYPE CODE-WRAPPER) (NEW KEY-VALUE-LIST) :DOCUMENTATION \"Table of functions (keyed by type of object returned) that can\nbe called to search for an object identified by a string.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *INTEGER-TO-OBJECT-FUNCTIONS* (LIST OF CODE-WRAPPER) (LIST) :DOCUMENTATION \"List of functions that can be called to search for\nan object identified by an integer.\")");
            oSTRING_TO_OBJECT_FUNCTIONSo->clear();
            oSTRING_TO_OBJECT_FUNCTIONSo->insert_at(SGT_DESCRIBE_CLASS, function_code_wrap_literal(((cpp_function_code)(&string_to_class))));
            oSTRING_TO_OBJECT_FUNCTIONSo->insert_at(SGT_DESCRIBE_CONTEXT, function_code_wrap_literal(((cpp_function_code)(&string_to_context))));
            oSTRING_TO_OBJECT_FUNCTIONSo->insert_at(SGT_DESCRIBE_METHOD_SLOT, function_code_wrap_literal(((cpp_function_code)(&string_to_function))));
            oSTRING_TO_OBJECT_FUNCTIONSo->insert_at(SGT_DESCRIBE_SLOT, function_code_wrap_literal(((cpp_function_code)(&string_to_slot))));
            oSTRING_TO_OBJECT_FUNCTIONSo->insert_at(SGT_DESCRIBE_DEMON, function_code_wrap_literal(((cpp_function_code)(&string_to_demon))));
            oINTEGER_TO_OBJECT_FUNCTIONSo->insert(function_code_wrap_literal(((cpp_function_code)(&integer_to_context))));
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEFAULT-DESCRIBE-MODE* KEYWORD :VERBOSE :DOCUMENTATION \"Specifies the print mode for 'describe' when no second\nargument is given.\")");
            store_macro(SYM_DESCRIBE_DESCRIBE, SYM_DESCRIBE_DESCRIBE_EXPANDER, ((cpp_function_code)(&describe_expander)));
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *PRETTY-PRINT-LIST-CUTOFF* INTEGER 5 :DOCUMENTATION \"Lists longer than the cutoff are truncated during\npretty printing.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *SLOTOPTIONSLOTS* (CONS OF STORAGE-SLOT) NULL :DOCUMENTATION \"List of slots containing storage-slot options\")");
            { Global_Variable* global = SYM_DESCRIBE_oSLOTOPTIONSLOTSo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OslotoptionslotsO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OslotoptionslotsO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *CLASSOPTIONSLOTS* (CONS OF STORAGE-SLOT) NULL :DOCUMENTATION \"List of slots containing class options\")");
            { Global_Variable* global = SYM_DESCRIBE_oCLASSOPTIONSLOTSo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OclassoptionslotsO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OclassoptionslotsO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *CLASSUNSTRINGIFIEDOPTIONS* PROPERTY-LIST NULL :DOCUMENTATION \"Plist of unstringifed class options\")");
            { Global_Variable* global = SYM_DESCRIBE_oCLASSUNSTRINGIFIEDOPTIONSo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OclassunstringifiedoptionsO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OclassunstringifiedoptionsO));
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

