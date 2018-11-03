// cl-translate.cc

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

Symbol* SYM_CL_TRANSLATE_SYS_CALL_FUNCTION = NULL;

Symbol* SYM_CL_TRANSLATE_SYS_CALL_METHOD = NULL;

Key_Value_List* oCL_OPERATOR_TABLEo = NULL;

Surrogate* SGT_CL_TRANSLATE_KEY_VALUE_LIST = NULL;

Symbol* SYM_CL_TRANSLATE_i = NULL;

Symbol* SYM_CL_TRANSLATE__ = NULL;

Symbol* SYM_CL_TRANSLATE_o = NULL;

Symbol* SYM_CL_TRANSLATE_s = NULL;

Symbol* SYM_CL_TRANSLATE_EQp = NULL;

Symbol* SYM_CL_TRANSLATE_l = NULL;

Symbol* SYM_CL_TRANSLATE_le = NULL;

Symbol* SYM_CL_TRANSLATE_ge = NULL;

Symbol* SYM_CL_TRANSLATE_g = NULL;

Symbol* SYM_CL_TRANSLATE_e = NULL;

Symbol* SYM_CL_TRANSLATE_xse = NULL;

Keyword* KWD_CL_TRANSLATE_USE_COMMON_LISP_STRUCTS = NULL;

Keyword* KWD_CL_TRANSLATE_USE_COMMON_LISP_VECTOR_STRUCTS = NULL;

Surrogate* SGT_CL_TRANSLATE_VOID = NULL;

Symbol* SYM_CL_TRANSLATE_VOID_SYS = NULL;

Symbol* SYM_CL_TRANSLATE_TYPED_SYS = NULL;

Symbol* SYM_CL_TRANSLATE_BAD_SYS = NULL;

Symbol* SYM_CL_TRANSLATE_SETQ = NULL;

Symbol* SYM_CL_TRANSLATE_SYS_SLOT_VALUE = NULL;

Symbol* SYM_CL_TRANSLATE_SYS_SLOT_VALUE_SETTER = NULL;

Symbol* SYM_CL_TRANSLATE_PROGN = NULL;

Symbol* SYM_CL_TRANSLATE_LOOP = NULL;

Symbol* SYM_CL_TRANSLATE_SYS_FOREACH = NULL;

Symbol* SYM_CL_TRANSLATE_LET = NULL;

Symbol* SYM_CL_TRANSLATE_STARTUP_TIME_PROGN = NULL;

Symbol* SYM_CL_TRANSLATE_SPECIAL = NULL;

Symbol* SYM_CL_TRANSLATE_CAST = NULL;

Symbol* SYM_CL_TRANSLATE_SAFE_CAST = NULL;

Symbol* SYM_CL_TRANSLATE_RETURN = NULL;

Symbol* SYM_CL_TRANSLATE_BREAK = NULL;

Symbol* SYM_CL_TRANSLATE_CONTINUE = NULL;

Symbol* SYM_CL_TRANSLATE_WHILE = NULL;

Symbol* SYM_CL_TRANSLATE_IF = NULL;

Symbol* SYM_CL_TRANSLATE_CHOOSE = NULL;

Symbol* SYM_CL_TRANSLATE_WHEN = NULL;

Symbol* SYM_CL_TRANSLATE_UNLESS = NULL;

Symbol* SYM_CL_TRANSLATE_AND = NULL;

Symbol* SYM_CL_TRANSLATE_OR = NULL;

Symbol* SYM_CL_TRANSLATE_NOT = NULL;

Symbol* SYM_CL_TRANSLATE_COND = NULL;

Symbol* SYM_CL_TRANSLATE_CASE = NULL;

Symbol* SYM_CL_TRANSLATE_MAKE = NULL;

Symbol* SYM_CL_TRANSLATE_SYS_NEW = NULL;

Symbol* SYM_CL_TRANSLATE_MV_SETQ = NULL;

Symbol* SYM_CL_TRANSLATE_QUOTE = NULL;

Symbol* SYM_CL_TRANSLATE_SYS_CALL_FUNCTION_CODE = NULL;

Symbol* SYM_CL_TRANSLATE_SYS_CALL_METHOD_CODE = NULL;

Symbol* SYM_CL_TRANSLATE_THE_CODE = NULL;

Symbol* SYM_CL_TRANSLATE_PRINT_STREAM = NULL;

Symbol* SYM_CL_TRANSLATE_PRINT_NATIVE_STREAM = NULL;

Symbol* SYM_CL_TRANSLATE_VERBATIM = NULL;

Symbol* SYM_CL_TRANSLATE_INLINE = NULL;

Symbol* SYM_CL_TRANSLATE_IGNORE = NULL;

Keyword* KWD_CL_TRANSLATE_CONTINUE = NULL;

Symbol* SYM_CL_TRANSLATE_GET_KWD = NULL;

Symbol* SYM_CL_TRANSLATE_GET_SGT = NULL;

Symbol* SYM_CL_TRANSLATE_CLSYS_SVAL = NULL;

Symbol* SYM_CL_TRANSLATE_NTH = NULL;

Symbol* SYM_CL_TRANSLATE_NTH_SETTER = NULL;

Symbol* SYM_CL_TRANSLATE_NULLp = NULL;

Symbol* SYM_CL_TRANSLATE_DEFINEDp = NULL;

Symbol* SYM_CL_TRANSLATE_NORMAL_CALL = NULL;

Surrogate* SGT_CL_TRANSLATE_OBJECT = NULL;

Symbol* SYM_CL_TRANSLATE_NON_OBJECT_METHOD = NULL;

Symbol* SYM_CL_TRANSLATE_PRINT_OBJECT = NULL;

Symbol* SYM_CL_TRANSLATE_OBJECT_METHOD = NULL;

Keyword* KWD_CL_TRANSLATE_COMMON_LISP = NULL;

Keyword* KWD_CL_TRANSLATE_FUNCTION = NULL;

Symbol* SYM_CL_TRANSLATE_CLSYS_CALL = NULL;

Symbol* SYM_CL_TRANSLATE_NULL = NULL;

Surrogate* SGT_CL_TRANSLATE_STRING = NULL;

Surrogate* SGT_CL_TRANSLATE_VECTOR = NULL;

Symbol* SYM_CL_TRANSLATE_THE_ARRAY = NULL;

Symbol* SYM_CL_TRANSLATE_DO = NULL;

Symbol* SYM_CL_TRANSLATE_EVAL_WHEN = NULL;

Symbol* SYM_CL_TRANSLATE_PRIMARY_TYPE = NULL;

Symbol* SYM_CL_TRANSLATE_NILp = NULL;

Symbol* SYM_CL_TRANSLATE_EMPTYp = NULL;

Symbol* SYM_CL_TRANSLATE_NON_EMPTYp = NULL;

Surrogate* SGT_CL_TRANSLATE_LITERAL = NULL;

Surrogate* SGT_CL_TRANSLATE_NUMBER = NULL;

Surrogate* SGT_CL_TRANSLATE_BOOLEAN = NULL;

Surrogate* SGT_CL_TRANSLATE_CODE = NULL;

Surrogate* SGT_CL_TRANSLATE_CONS = NULL;

Symbol* SYM_CL_TRANSLATE_NIL = NULL;

Symbol* SYM_CL_TRANSLATE_OTHERWISE = NULL;

Symbol* SYM_CL_TRANSLATE_TRUE = NULL;

Symbol* SYM_CL_TRANSLATE_FALSE = NULL;

Symbol* SYM_CL_TRANSLATE_CLASS_CL_NATIVE_TYPE = NULL;

Symbol* SYM_CL_TRANSLATE_CLSYS_MAKE = NULL;

Symbol* SYM_CL_TRANSLATE_rrSTREAM = NULL;

Keyword* KWD_CL_TRANSLATE_WARN = NULL;

Keyword* KWD_CL_TRANSLATE_ERROR = NULL;

Keyword* KWD_CL_TRANSLATE_CONTINUABLE_ERROR = NULL;

Symbol* SYM_CL_TRANSLATE_GLOBAL_VARIABLE = NULL;

Symbol* SYM_CL_TRANSLATE_CLASS = NULL;

Symbol* SYM_CL_TRANSLATE_METHOD = NULL;

Symbol* SYM_CL_TRANSLATE_MACRO = NULL;

Symbol* SYM_CL_TRANSLATE_PRINT_METHOD = NULL;

Symbol* SYM_CL_TRANSLATE_TYPE = NULL;

Symbol* SYM_CL_TRANSLATE_CLSYS_SELF = NULL;

Symbol* SYM_CL_TRANSLATE_CLSYS_DUMMY = NULL;

Symbol* SYM_CL_TRANSLATE_DOCUMENTATION = NULL;

Symbol* SYM_CL_TRANSLATE_SELF = NULL;

Symbol* SYM_CL_TRANSLATE_oCLSYS_SELFo = NULL;

Keyword* KWD_CL_TRANSLATE_VOID = NULL;

Keyword* KWD_CL_TRANSLATE_EMBEDDED = NULL;

Keyword* KWD_CL_TRANSLATE_INSTANCE = NULL;

Keyword* KWD_CL_TRANSLATE_ALLOCATION = NULL;

Keyword* KWD_CL_TRANSLATE_DOCUMENTATION = NULL;

Keyword* KWD_CL_TRANSLATE_ACCESSOR = NULL;

Symbol* SYM_CL_TRANSLATE_CLASS_CL_STRUCT_SLOTS = NULL;

Keyword* KWD_CL_TRANSLATE_CONC_NAME = NULL;

Keyword* KWD_CL_TRANSLATE_CONSTRUCTOR = NULL;

Keyword* KWD_CL_TRANSLATE_INCLUDE = NULL;

Keyword* KWD_CL_TRANSLATE_UNBOUND_SPECIAL_VARIABLE = NULL;

Symbol* SYM_CL_TRANSLATE_STREAM = NULL;

Symbol* destructure_call_tree(Cons* tree, Surrogate*& return1, Cons*& return2) {
  { Object* test_value_001 = tree->first();

    if (test_value_001 == SYM_CL_TRANSLATE_SYS_CALL_FUNCTION) {
      { Symbol* return_temp = ((Symbol*)(tree->second()));

        return1 = NULL;
        return2 = tree->rest->rest;
        return (return_temp);
      }
    }
    else if (test_value_001 == SYM_CL_TRANSLATE_SYS_CALL_METHOD) {
      { Symbol* return_temp = ((Symbol*)(tree->third()));

        return1 = ((Surrogate*)(tree->second()));
        return2 = tree->rest->rest->rest;
        return (return_temp);
      }
    }
    else {
      { Symbol* return_temp = ((Symbol*)(tree->first()));

        return1 = NULL;
        return2 = tree->rest;
        return (return_temp);
      }
    }
  }
}

boolean use_cl_structsP() {
  return (oCURRENT_ENVIRONMENT_FEATURESo->memberP(KWD_CL_TRANSLATE_USE_COMMON_LISP_STRUCTS));
}

boolean use_vector_structsP() {
  return (oCURRENT_ENVIRONMENT_FEATURESo->memberP(KWD_CL_TRANSLATE_USE_COMMON_LISP_VECTOR_STRUCTS));
}

Cons* cl_translate_list_of_trees(Cons* trees) {
  { Cons* cursor = trees;

    while (cursor->non_emptyP()) {
      cursor->value = cl_translate_a_tree(cursor->value);
      cursor = cursor->rest;
    }
    return (trees);
  }
}

Cons* cl_translate_void_sys(Cons* tree) {
  { Object* otree = cl_translate_a_tree(tree->second());

    tree->free_cons();
    return (((Cons*)(otree)));
  }
}

Object* cl_translate_typed_sys(Cons* tree) {
  { Object* otree = cl_translate_a_tree(tree->second());

    free_transient_type_spec(((Standard_Object*)(tree->third())));
    tree->free_cons();
    return (otree);
  }
}

Object* cl_translate_bad_sys(Cons* tree) {
  { Object* returntype = tree->third();

    tree->free_cons();
    if (returntype == SGT_CL_TRANSLATE_VOID) {
      return (yield_illegal_statement_tree());
    }
    else {
      return (yield_illegal_expression_tree());
    }
  }
}

Object* cl_translate_a_tree(Object* tree) {
  return (help_cl_translate_a_tree(tree));
}

Object* help_cl_translate_a_tree(Object* tree) {
  if (tree == NULL) {
    return (tree);
  }
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        if (nilP(tree)) {
          return (tree);
        }
        { Object* test_value_001 = tree->first();

          if (test_value_001 == SYM_CL_TRANSLATE_VOID_SYS) {
            return (cl_translate_void_sys(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_TYPED_SYS) {
            return (cl_translate_typed_sys(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_BAD_SYS) {
            return (cl_translate_bad_sys(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_SETQ) {
            return (cl_translate_setq_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_SYS_SLOT_VALUE) {
            return (cl_translate_fixed_slot_value_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_SYS_SLOT_VALUE_SETTER) {
            return (cl_translate_fixed_slot_value_setter_tree(tree));
          }
          else if ((test_value_001 == SYM_CL_TRANSLATE_SYS_CALL_METHOD) ||
              (test_value_001 == SYM_CL_TRANSLATE_SYS_CALL_FUNCTION)) {
            return (cl_translate_call_method_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_PROGN) {
            tree->value = intern_common_lisp_symbol("PROGN");
            tree->rest = cl_translate_list_of_trees(tree->rest);
            return (tree);
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_LOOP) {
            tree->value = intern_common_lisp_symbol("LOOP");
            tree->rest = maybe_wrap_with_continue_label(cl_translate_list_of_trees(tree->rest));
            return (tree);
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_SYS_FOREACH) {
            return (cl_translate_foreach_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_LET) {
            return (cl_translate_let_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_STARTUP_TIME_PROGN) {
            return (cl_translate_startup_time_progn_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_SPECIAL) {
            return (cl_translate_special_tree(tree));
          }
          else if ((test_value_001 == SYM_CL_TRANSLATE_CAST) ||
              (test_value_001 == SYM_CL_TRANSLATE_SAFE_CAST)) {
            return (cl_translate_cast_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_RETURN) {
            return (cl_translate_return_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_BREAK) {
            tree->first_setter(intern_common_lisp_symbol("RETURN"));
            return (tree);
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_CONTINUE) {
            return (listO(3, intern_common_lisp_symbol("GO"), KWD_CL_TRANSLATE_CONTINUE, NIL));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_WHILE) {
            return (cl_translate_while_tree(tree));
          }
          else if ((test_value_001 == SYM_CL_TRANSLATE_IF) ||
              ((test_value_001 == SYM_CL_TRANSLATE_CHOOSE) ||
               ((test_value_001 == SYM_CL_TRANSLATE_WHEN) ||
                (test_value_001 == SYM_CL_TRANSLATE_UNLESS)))) {
            return (cl_translate_conditional_tree(tree));
          }
          else if ((test_value_001 == SYM_CL_TRANSLATE_AND) ||
              ((test_value_001 == SYM_CL_TRANSLATE_OR) ||
               (test_value_001 == SYM_CL_TRANSLATE_NOT))) {
            return (cl_translate_boolean_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_COND) {
            return (cl_translate_cond_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_CASE) {
            return (cl_translate_case_tree(tree));
          }
          else if ((test_value_001 == SYM_CL_TRANSLATE_EQp) ||
              ((test_value_001 == SYM_CL_TRANSLATE_g) ||
               ((test_value_001 == SYM_CL_TRANSLATE_ge) ||
                ((test_value_001 == SYM_CL_TRANSLATE_l) ||
                 (test_value_001 == SYM_CL_TRANSLATE_le))))) {
            return (cl_translate_operator_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_MAKE) {
            return (cl_translate_make_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_SYS_NEW) {
            return (cl_translate_new_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_MV_SETQ) {
            tree->first_setter(intern_common_lisp_symbol("MULTIPLE-VALUE-SETQ"));
            tree->third_setter(cl_translate_a_tree(tree->third()));
            return (tree);
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_QUOTE) {
            tree->first_setter(intern_common_lisp_symbol("QUOTE"));
            return (tree);
          }
          else if ((test_value_001 == SYM_CL_TRANSLATE_SYS_CALL_FUNCTION_CODE) ||
              (test_value_001 == SYM_CL_TRANSLATE_SYS_CALL_METHOD_CODE)) {
            return (cl_translate_call_function_code_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_THE_CODE) {
            return (cl_translate_the_code_tree(tree));
          }
          else if ((test_value_001 == SYM_CL_TRANSLATE_PRINT_STREAM) ||
              (test_value_001 == SYM_CL_TRANSLATE_PRINT_NATIVE_STREAM)) {
            return (cl_translate_print_stream_tree(tree));
          }
          else if (test_value_001 == SYM_CL_TRANSLATE_VERBATIM) {
            return (cl_translate_verbatim_tree(tree));
          }
          else if ((test_value_001 == SYM_CL_TRANSLATE_INLINE) ||
              (test_value_001 == SYM_CL_TRANSLATE_IGNORE)) {
            return (cl_translate_inline_tree(tree));
          }
          else {
            cerr << "`" << test_value_001 << "'" << " is not a valid case option";
          }
        }
      }
    }
    else {
      return (tree->cl_translate_atomic_tree());
    }
  }
}

Object* Object::cl_translate_atomic_tree() {
  { Object* tree = this;

    return (tree);
  }
}

Object* Symbol::cl_translate_atomic_tree() {
  { Symbol* tree = this;

    if (tree->lookup_global_variable() != NULL) {
      return (cl_translate_global_symbol(tree));
    }
    else {
      { Module* symbolmodule = ((Module*)(tree->home_context));

        if ((symbolmodule == NULL) ||
            (symbolmodule == oMODULEo)) {
          return (tree);
        }
        else {
          return (new_verbatim_string_wrapper(tree->symbol_name));
        }
      }
    }
  }
}

Object* Keyword::cl_translate_atomic_tree() {
  { Keyword* tree = this;

    if (use_hardcoded_symbolsP()) {
      { Integer_Wrapper* offset = integer_wrap_literal(tree->keywordify()->symbol_id);

        return (listO(3, SYM_CL_TRANSLATE_GET_KWD, offset, NIL));
      }
    }
    else {
      return (cl_translate_global_symbol(yield_symbol_constant_name(tree)));
    }
  }
}

Object* Surrogate::cl_translate_atomic_tree() {
  { Surrogate* tree = this;

    if (use_hardcoded_symbolsP()) {
      { Integer_Wrapper* offset = integer_wrap_literal(tree->symbol_id);

        return (listO(3, SYM_CL_TRANSLATE_GET_SGT, offset, NIL));
      }
    }
    else {
      return (cl_translate_global_symbol(yield_symbol_constant_name(tree)));
    }
  }
}

Object* cl_translate_global_symbol(Symbol* symbol) {
  { Module* symbolmodule = ((Module*)(symbol->home_context));

    if (symbolmodule == oCOMMON_LISP_MODULEo) {
      return (symbol);
    }
    if (symbolmodule == NULL) {
      symbolmodule = oMODULEo;
    }
    return (yield_global_lisp_symbol(symbolmodule, symbol->symbol_name));
  }
}

Object* yield_global_lisp_symbol(Module* symbolmodule, char* symbolname) {
  { char* lispsymbolpackage = (((symbolmodule == NULL) ||
        ((symbolmodule == oMODULEo) ||
         string_eqlP(symbolmodule->native_package(), oMODULEo->native_package()))) ? ((char*)(NULL)) : ((char*)(symbolmodule->native_package())));
    char* lispsymbolname = ((symbolmodule->module_native_package != NULL) ? ((char*)(symbolname)) : ((char*)(compute_full_name(symbolname, symbolmodule))));

    if (symbolmodule->case_sensitiveP) {
      lispsymbolname = string_concatenate("|", string_concatenate(lispsymbolname, "|"));
    }
    if (lispsymbolpackage == NULL) {
      return (new_verbatim_string_wrapper(lispsymbolname));
    }
    else {
      return (new_verbatim_string_wrapper(string_concatenate(lispsymbolpackage, string_concatenate("::", lispsymbolname))));
    }
  }
}

Cons* cl_translate_setq_tree(Cons* tree) {
  tree->first_setter(intern_common_lisp_symbol("SETQ"));
  tree->second_setter(cl_translate_a_tree(tree->second()));
  tree->third_setter(cl_translate_a_tree(tree->third()));
  return (tree);
}

Object* yield_struct_slot_accessor_name(Surrogate* classtype, Symbol* slotname) {
  return (yield_global_lisp_symbol(((Module*)(classtype->home_context)), string_concatenate(classtype->symbol_name, string_concatenate("...", slotname->symbol_name))));
}

Object* yield_clos_slot_accessor_name(Symbol* slotname) {
  return (yield_global_lisp_symbol(((Module*)(slotname->home_context)), string_concatenate(slotname->symbol_name, "...OF")));
}

Cons* yield_slot_value_reader_tree(Symbol* slotname, Object* objectref, Surrogate* objecttype) {
  if (use_cl_structsP()) {
    if (use_vector_structsP()) {
      return (cons(cl_translate_global_symbol(SYM_CL_TRANSLATE_CLSYS_SVAL), cons(integer_wrap_literal(cl_struct_slot_offset(slotname, objecttype)), cons(cl_translate_global_symbol(type_to_symbol(objecttype)), cons(cl_translate_global_symbol(slotname), cons(objectref, NIL))))));
    }
    else {
      return (cons(yield_struct_slot_accessor_name(objecttype, slotname), cons(objectref, NIL)));
    }
  }
  else {
    return (cons(cl_translate_global_symbol(SYM_CL_TRANSLATE_CLSYS_SVAL), cons(cl_translate_global_symbol(type_to_symbol(objecttype)), cons(cl_translate_global_symbol(slotname), cons(objectref, NIL)))));
  }
}

Cons* yield_slot_value_writer_tree(Symbol* slotname, Object* objectref, Surrogate* objecttype, Object* valueref) {
  return (listO(3, intern_common_lisp_symbol("SETF"), yield_slot_value_reader_tree(slotname, objectref, objecttype), cons(valueref, NIL)));
}

Symbol* true_slot_name(Symbol* slotname, Surrogate* type) {
  return (canonical_slot(((Storage_Slot*)(lookup_slot(((Class*)(type->surrogate_value)), slotname))))->slot_name);
}

Cons* cl_translate_fixed_slot_value_tree(Cons* tree) {
  { Surrogate* objtype = ((Surrogate*)(tree->second()));
    Symbol* slotname = true_slot_name(((Symbol*)(tree->third())), objtype);
    Object* objref = cl_translate_a_tree(tree->fourth());
    Cons* otree = yield_slot_value_reader_tree(slotname, objref, objtype);

    free_cons_list(tree);
    return (otree);
  }
}

Cons* cl_translate_fixed_slot_value_setter_tree(Cons* tree) {
  { Surrogate* objtype = ((Surrogate*)(tree->second()));
    Symbol* slotname = true_slot_name(((Symbol*)(tree->third())), objtype);
    Object* objref = cl_translate_a_tree(tree->fourth());
    Object* valueref = cl_translate_a_tree(tree->fifth());
    Cons* otree = yield_slot_value_writer_tree(slotname, objref, objtype, valueref);

    free_cons_list(tree);
    return (otree);
  }
}

Cons* cl_translate_call_method_tree(Cons* tree) {
  { Symbol* renamed_Operator = NULL;
    Surrogate* owner = NULL;
    Cons* arguments = NULL;

    renamed_Operator = destructure_call_tree(tree, owner, arguments);
    owner = owner;
    if ((renamed_Operator == SYM_CL_TRANSLATE_NTH) ||
        (renamed_Operator == SYM_CL_TRANSLATE_NTH_SETTER)) {
      return (cl_translate_nth_tree(tree));
    }
    if (oCL_OPERATOR_TABLEo->lookup(renamed_Operator) != NULL) {
      return (cl_translate_operator_tree(tree));
    }
    return (cl_translate_normal_call_method_tree(renamed_Operator, owner, arguments));
  }
}

Symbol* method_call_type_for_vector_structs(Symbol* slotname, Surrogate* owner, boolean functionP) {
  if (functionP ||
      ((owner == NULL) ||
       ((slotname == SYM_CL_TRANSLATE_NULLp) ||
        ((slotname == SYM_CL_TRANSLATE_DEFINEDp) ||
         (symbol_common_lispP(slotname) ||
          ((!use_cl_structsP()) ||
           (!use_vector_structsP()))))))) {
    return (SYM_CL_TRANSLATE_NORMAL_CALL);
  }
  if (!subtype_ofP(owner, SGT_CL_TRANSLATE_OBJECT)) {
    return (SYM_CL_TRANSLATE_NON_OBJECT_METHOD);
  }
  else {
    if (slotname == SYM_CL_TRANSLATE_PRINT_OBJECT) {
      return (SYM_CL_TRANSLATE_PRINT_OBJECT);
    }
    else {
      return (SYM_CL_TRANSLATE_OBJECT_METHOD);
    }
  }
}

Cons* cl_translate_normal_call_method_tree(Symbol* renamed_Operator, Surrogate* owner, Cons* arguments) {
  { Object* translatedoperator = cl_translate_global_symbol(yield_renamed_name_if_native(renamed_Operator, KWD_CL_TRANSLATE_COMMON_LISP, KWD_CL_TRANSLATE_FUNCTION));

    { Symbol* test_value_001 = method_call_type_for_vector_structs(renamed_Operator, owner, owner == NULL);

      if ((test_value_001 == SYM_CL_TRANSLATE_OBJECT_METHOD) ||
          (test_value_001 == SYM_CL_TRANSLATE_PRINT_OBJECT)) {
        return (cons(cl_translate_global_symbol(SYM_CL_TRANSLATE_CLSYS_CALL), cons(translatedoperator, cl_translate_list_of_trees(arguments)->concatenate(NIL))));
      }
      else if (test_value_001 == SYM_CL_TRANSLATE_NON_OBJECT_METHOD) {
        return (cons(translatedoperator, cons(cl_translate_a_tree(arguments->first()), cons(SYM_CL_TRANSLATE_NULL, cl_translate_list_of_trees(arguments->rest)->concatenate(NIL)))));
      }
      else {
        return (cons(translatedoperator, cl_translate_list_of_trees(arguments)->concatenate(NIL)));
      }
    }
  }
}

Cons* cl_translate_nth_tree(Cons* tree) {
  { Symbol* renamed_Operator = NULL;
    Surrogate* owner = NULL;
    Cons* arguments = NULL;

    renamed_Operator = destructure_call_tree(tree, owner, arguments);
    { boolean setterP = renamed_Operator == SYM_CL_TRANSLATE_NTH_SETTER;
      Object* collection = arguments->first();
      Object* position = arguments->last();
      Object* value = (setterP ? ((Object*)(arguments->second())) : ((Object*)(NULL)));

      if ((owner == SGT_CL_TRANSLATE_STRING) ||
          (owner == SGT_CL_TRANSLATE_VECTOR)) {
        renamed_Operator = intern_common_lisp_symbol("CHAR");
        if (owner == SGT_CL_TRANSLATE_VECTOR) {
          collection = listO(5, SYM_CL_TRANSLATE_SYS_SLOT_VALUE, SGT_CL_TRANSLATE_VECTOR, SYM_CL_TRANSLATE_THE_ARRAY, collection, NIL);
          renamed_Operator = intern_common_lisp_symbol("AREF");
        }
        tree = cons(renamed_Operator, cons(cl_translate_a_tree(collection), cons(cl_translate_a_tree(position), NIL)));
        if (setterP) {
          tree = listO(3, intern_common_lisp_symbol("SETF"), tree, cons(cl_translate_a_tree(value), NIL));
        }
        return (tree);
      }
      else {
      }
      return (cl_translate_normal_call_method_tree(renamed_Operator, owner, arguments));
    }
  }
}

boolean duplicate_cursor_variableP(Symbol* variable, Cons* iteratorbindings) {
  { boolean foundP_001 = FALSE;

    { Cons* ib = NIL;
      Cons* iter_001 = ((Cons*)(iteratorbindings));

      while (!nilP(iter_001)) {
        {
          ib = ((Cons*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (ib->first() == variable) {
          foundP_001 = TRUE;
          break;
        }
      }
    }
    { boolean value_001 = foundP_001;

      return (value_001);
    }
  }
}

Cons* cl_translate_foreach_tree(Cons* tree) {
  { Cons* iteratorbindings = ((Cons*)(tree->second()));
    Cons* cursorbindings = ((Cons*)(tree->third()));
    Cons* continuationtest = cl_translate_boolean_test(tree->fourth(), FALSE);
    Cons* body = cl_translate_list_of_trees(tree->nth_rest(4));
    Cons* declarations = NIL;
    Cons* nextassignments = NIL;
    Object* iteratorconstructor = NULL;

    tree->nth_rest_setter(NIL, 4);
    free_cons_list(tree);
    { Cons* binding = NIL;
      Cons* iter_001 = iteratorbindings;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          binding = ((Cons*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        iteratorconstructor = cl_translate_a_tree(binding->third());
        binding->third_setter(NULL);
        if (collect_001 == NULL) {
          {
            collect_001 = cons(cons(binding->first()->cl_translate_atomic_tree(), cons(iteratorconstructor, NIL)), NIL);
            if (nilP(declarations)) {
              declarations = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(declarations, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(cons(binding->first()->cl_translate_atomic_tree(), cons(iteratorconstructor, NIL)), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    { Cons* binding = NIL;
      Cons* iter_002 = cursorbindings;

      while (!nilP(iter_002)) {
        {
          binding = ((Cons*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        nextassignments = cons(cl_translate_a_tree(binding->third()), nextassignments);
        binding->third_setter(NULL);
        if (!(duplicate_cursor_variableP(((Symbol*)(binding->first())), iteratorbindings))) {
          declarations = cons(cons(binding->first()->cl_translate_atomic_tree(), cons(cl_translate_global_symbol(SYM_CL_TRANSLATE_NULL), NIL)), declarations);
        }
      }
    }
    free_cons_tree(iteratorbindings);
    free_cons_tree(cursorbindings);
    return (listO(3, intern_common_lisp_symbol("LET*"), declarations, cons(listO(4, intern_common_lisp_symbol("LOOP"), SYM_CL_TRANSLATE_WHILE, continuationtest, cons(SYM_CL_TRANSLATE_DO, nextassignments->reverse()->concatenate(maybe_wrap_with_continue_label(body)->concatenate(NIL)))), NIL)));
  }
}

Cons* maybe_wrap_with_continue_label(Cons* translatedloopbody) {
  if (search_cons_treeP(translatedloopbody, KWD_CL_TRANSLATE_CONTINUE)) {
    return (cons(cons(intern_common_lisp_symbol("TAGBODY"), translatedloopbody->concatenate(cons(KWD_CL_TRANSLATE_CONTINUE, NIL))), NIL));
  }
  else {
    return (translatedloopbody);
  }
}

Cons* cl_translate_let_tree(Cons* tree) {
  { Cons* odeclarations = NIL;

    { Cons* d = NIL;
      Cons* iter_001 = ((Cons*)(tree->second()));

      while (!nilP(iter_001)) {
        {
          d = ((Cons*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        free_transient_type_spec(((Standard_Object*)(d->second())));
        odeclarations = cons(cons(d->first()->cl_translate_atomic_tree(), cons(cl_translate_a_tree(d->third()), NIL)), odeclarations);
        free_cons_list(d);
      }
    }
    free_cons_list(((Cons*)(tree->second())));
    tree->first_setter(intern_common_lisp_symbol("LET*"));
    tree->second_setter(odeclarations->reverse());
    tree->rest->rest = cl_translate_list_of_trees(tree->rest->rest);
    return (tree);
  }
}

Cons* cl_translate_special_tree(Cons* tree) {
  { Cons* translatedtree = cl_translate_let_tree(tree);
    Cons* specialvars = NIL;

    { Cons* decl = NIL;
      Cons* iter_001 = ((Cons*)(tree->second()));
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          decl = ((Cons*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(decl->first(), NIL);
            if (nilP(specialvars)) {
              specialvars = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(specialvars, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(decl->first(), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    translatedtree->rest->rest = cons(listO(3, intern_common_lisp_symbol("DECLARE"), cons(intern_common_lisp_symbol("SPECIAL"), specialvars->concatenate(NIL)), NIL), translatedtree->rest->rest);
    return (translatedtree);
  }
}

Cons* cl_translate_startup_time_progn_tree(Cons* tree) {
  tree->value = intern_common_lisp_symbol("PROGN");
  tree->rest = cl_translate_list_of_trees(tree->rest);
  return (listO(4, SYM_CL_TRANSLATE_EVAL_WHEN, listO(3, intern_common_lisp_symbol("LOAD"), intern_common_lisp_symbol("EVAL"), NIL), tree, NIL));
}

Object* cast(Object* value, Surrogate* type) {
  // Perform a run-time type check, and then return 'value'.
  if ((oSAFETYo >= 2) &&
      ((oSTARTUP_TIME_PHASEo == 999) &&
       oUNFINALIZED_CLASSESo->emptyP())) {
    if ((value != NULL) &&
        (!isaP(value, type))) {
      cerr << "Run-time casting violation.  The value: " << endl << "`" << value << "'" << endl << " is not of type " << "`" << type << "'" << ".";
    }
  }
  return (value);
}

Object* cl_translate_cast_tree(Cons* tree) {
  { Object* expression = tree->second();
    Object* type = tree->third();

    tree->second_setter(cl_translate_a_tree(expression));
    tree->third_setter(cl_translate_a_tree(type));
    if ((oSAFETYo < 2) ||
        ((tree->first() == SYM_CL_TRANSLATE_SAFE_CAST) ||
         (safe_lookup_slot(type_to_class(((Surrogate*)(type))), SYM_CL_TRANSLATE_PRIMARY_TYPE) == NULL))) {
      expression = tree->second();
      tree->second_setter(NIL);
      free_cons_tree(tree);
      return (expression);
    }
    tree->first_setter(cl_translate_global_symbol(SYM_CL_TRANSLATE_CAST));
    return (tree);
  }
}

Cons* cl_translate_return_tree(Cons* tree) {
  { Cons* returnvalues = cl_translate_list_of_trees(tree->rest);

    if (returnvalues->rest->non_emptyP()) {
      returnvalues = cons(cons(intern_common_lisp_symbol("VALUES"), returnvalues->concatenate(NIL)), NIL);
    }
    tree->free_cons();
    return (listO(3, intern_common_lisp_symbol("RETURN-FROM"), cl_translate_global_symbol(yield_renamed_name_if_native(((Method_Slot*)(oCURRENTTRANSLATIONUNITo->the_object))->slot_name, KWD_CL_TRANSLATE_COMMON_LISP, KWD_CL_TRANSLATE_FUNCTION)), returnvalues->concatenate(NIL)));
  }
}

Cons* cl_translate_boolean_test(Object* tree, boolean invertP) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Object* test_value_001 = tree->first();

          if (test_value_001 == SYM_CL_TRANSLATE_NOT) {
            { Object* postree = tree->second();

              free_cons_list(tree);
              return (cl_translate_boolean_test(postree, !invertP));
            }
          }
          else if ((test_value_001 == SYM_CL_TRANSLATE_AND) ||
              (test_value_001 == SYM_CL_TRANSLATE_OR)) {
            { Cons* cursor = tree->rest;

              while (cursor->non_emptyP()) {
                cursor->value = cl_translate_boolean_test(cursor->value, FALSE);
                cursor = cursor->rest;
              }
            }
            if (tree->first() == SYM_CL_TRANSLATE_AND) {
              tree->first_setter(intern_common_lisp_symbol("AND"));
            }
            else {
              tree->first_setter(intern_common_lisp_symbol("OR"));
            }
            if (invertP) {
              tree = listO(3, intern_common_lisp_symbol("NOT"), tree, NIL);
            }
            return (tree);
          }
          else {
          }
        }
      }
    }
    else {
    }
  }
  return (cl_translate_plain_boolean_test(tree, invertP));
}

Cons* cl_translate_plain_boolean_test(Object* tree, boolean invertP) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Symbol* renamed_Operator = NULL;
          Surrogate* owner = NULL;
          Cons* arguments = NULL;

          renamed_Operator = destructure_call_tree(tree, owner, arguments);
          if ((renamed_Operator == SYM_CL_TRANSLATE_l) ||
              ((renamed_Operator == SYM_CL_TRANSLATE_le) ||
               ((renamed_Operator == SYM_CL_TRANSLATE_e) ||
                ((renamed_Operator == SYM_CL_TRANSLATE_ge) ||
                 (renamed_Operator == SYM_CL_TRANSLATE_g))))) {
            if (invertP) {
              if (renamed_Operator == SYM_CL_TRANSLATE_l) {
                renamed_Operator = SYM_CL_TRANSLATE_ge;
              }
              else if (renamed_Operator == SYM_CL_TRANSLATE_le) {
                renamed_Operator = SYM_CL_TRANSLATE_g;
              }
              else if (renamed_Operator == SYM_CL_TRANSLATE_e) {
                renamed_Operator = SYM_CL_TRANSLATE_xse;
              }
              else if (renamed_Operator == SYM_CL_TRANSLATE_ge) {
                renamed_Operator = SYM_CL_TRANSLATE_l;
              }
              else if (renamed_Operator == SYM_CL_TRANSLATE_g) {
                renamed_Operator = SYM_CL_TRANSLATE_le;
              }
              else {
                cerr << "`" << renamed_Operator << "'" << " is not a valid case option";
              }
            }
            return (cons(oCL_OPERATOR_TABLEo->lookup(renamed_Operator), cl_translate_list_of_trees(arguments)->concatenate(NIL)));
          }
          else if (renamed_Operator == SYM_CL_TRANSLATE_EQp) {
            { Standard_Object* argtype1 = walked_expression_type(arguments->first());
              Standard_Object* argtype2 = walked_expression_type(arguments->second());

              if (sub_type_spec_ofP(argtype1, SGT_CL_TRANSLATE_LITERAL) &&
                  sub_type_spec_ofP(argtype2, SGT_CL_TRANSLATE_LITERAL)) {
                if (argtype1 == SGT_CL_TRANSLATE_STRING) {
                  renamed_Operator = intern_common_lisp_symbol("EQ");
                }
                else if (sub_type_spec_ofP(argtype1, SGT_CL_TRANSLATE_NUMBER) ||
                    sub_type_spec_ofP(argtype1, SGT_CL_TRANSLATE_BOOLEAN)) {
                  renamed_Operator = intern_common_lisp_symbol("=");
                }
                else {
                  renamed_Operator = intern_common_lisp_symbol("EQL");
                }
              }
              else {
                renamed_Operator = intern_common_lisp_symbol("EQ");
              }
              tree = ((Cons*)(cl_translate_a_tree(tree)));
              tree->first_setter(renamed_Operator);
              if (invertP) {
                return (listO(3, intern_common_lisp_symbol("NOT"), tree, NIL));
              }
              else {
                return (tree);
              }
            }
          }
          else if ((renamed_Operator == SYM_CL_TRANSLATE_NULLp) ||
              (renamed_Operator == SYM_CL_TRANSLATE_DEFINEDp)) {
            if ((owner == SGT_CL_TRANSLATE_OBJECT) ||
                ((owner == SGT_CL_TRANSLATE_STRING) ||
                 (owner == SGT_CL_TRANSLATE_CODE))) {
              tree = listO(3, intern_common_lisp_symbol("EQ"), cl_translate_a_tree(arguments->first()), cons(SYM_CL_TRANSLATE_NULL, NIL));
              if ((invertP &&
                  (renamed_Operator == SYM_CL_TRANSLATE_NULLp)) ||
                  ((!invertP) &&
                   (renamed_Operator == SYM_CL_TRANSLATE_DEFINEDp))) {
                return (listO(3, intern_common_lisp_symbol("NOT"), tree, NIL));
              }
              else {
                return (tree);
              }
            }
            else {
            }
          }
          else if ((renamed_Operator == SYM_CL_TRANSLATE_NILp) ||
              ((renamed_Operator == SYM_CL_TRANSLATE_EMPTYp) ||
               (renamed_Operator == SYM_CL_TRANSLATE_NON_EMPTYp))) {
            if ((renamed_Operator == SYM_CL_TRANSLATE_NILp) ||
                (owner == SGT_CL_TRANSLATE_CONS)) {
              tree = listO(3, intern_common_lisp_symbol("EQ"), cl_translate_a_tree(arguments->first()), cons(SYM_CL_TRANSLATE_NIL, NIL));
              if ((invertP &&
                  ((renamed_Operator == SYM_CL_TRANSLATE_NILp) ||
                   (renamed_Operator == SYM_CL_TRANSLATE_EMPTYp))) ||
                  ((!invertP) &&
                   (renamed_Operator == SYM_CL_TRANSLATE_NON_EMPTYp))) {
                return (listO(3, intern_common_lisp_symbol("NOT"), tree, NIL));
              }
              else {
                return (tree);
              }
            }
          }
          else {
          }
        }
      }
    }
    else {
    }
  }
  tree = cl_translate_a_tree(tree);
  if (invertP) {
    return (listO(3, intern_common_lisp_symbol("EQ"), tree, cons(integer_wrap_literal(0), NIL)));
  }
  else {
    return (listO(3, intern_common_lisp_symbol("EQ"), tree, cons(integer_wrap_literal(1), NIL)));
  }
}

Cons* cl_translate_while_tree(Cons* tree) {
  { Cons* test = cl_translate_boolean_test(tree->second(), FALSE);
    Cons* body = cl_translate_list_of_trees(tree->rest->rest);

    tree->rest->rest = NIL;
    free_cons_list(tree);
    return ((body->emptyP() ? ((Cons*)(listO(4, intern_common_lisp_symbol("LOOP"), SYM_CL_TRANSLATE_WHILE, test, NIL))) : ((Cons*)(listO(4, intern_common_lisp_symbol("LOOP"), SYM_CL_TRANSLATE_WHILE, test, cons(SYM_CL_TRANSLATE_DO, maybe_wrap_with_continue_label(body)->concatenate(NIL)))))));
  }
}

Cons* cl_translate_conditional_tree(Cons* tree) {
  { Object* renamed_Operator = tree->first();
    Object* test = tree->second();
    Cons* body = cl_translate_list_of_trees(tree->rest->rest);

    tree->rest->rest = NIL;
    free_cons_list(tree);
    if ((renamed_Operator == SYM_CL_TRANSLATE_IF) ||
        (renamed_Operator == SYM_CL_TRANSLATE_CHOOSE)) {
      return (listO(3, intern_common_lisp_symbol("IF"), cl_translate_boolean_test(test, FALSE), body->concatenate(NIL)));
    }
    else if (renamed_Operator == SYM_CL_TRANSLATE_WHEN) {
      return (listO(3, intern_common_lisp_symbol("WHEN"), cl_translate_boolean_test(test, FALSE), body->concatenate(NIL)));
    }
    else if (renamed_Operator == SYM_CL_TRANSLATE_UNLESS) {
      return (listO(3, intern_common_lisp_symbol("WHEN"), cl_translate_boolean_test(test, TRUE), body->concatenate(NIL)));
    }
    else {
      cerr << "`" << renamed_Operator << "'" << " is not a valid case option";
    }
  }
}

Cons* cl_translate_cond_tree(Cons* tree) {
  { Cons* condition = NIL;
    Cons* iter_001 = ((Cons*)(tree->rest));

    while (!nilP(iter_001)) {
      {
        condition = ((Cons*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (condition->value == SYM_CL_TRANSLATE_OTHERWISE) {
        condition->value = intern_common_lisp_symbol("T");
      }
      else {
        condition->value = cl_translate_boolean_test(condition->value, FALSE);
      }
      condition->rest = cl_translate_list_of_trees(condition->rest);
    }
  }
  tree->value = intern_common_lisp_symbol("COND");
  return (tree);
}

Cons* cl_translate_case_tree(Cons* tree) {
  { boolean otherwiseP = FALSE;

    tree->second_setter(cl_translate_a_tree(tree->second()));
    { Cons* cond = NIL;
      Cons* iter_001 = ((Cons*)(tree->rest->rest));

      while (!nilP(iter_001)) {
        {
          cond = ((Cons*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (cond->first() == SYM_CL_TRANSLATE_OTHERWISE) {
          otherwiseP = TRUE;
          cond->first_setter(intern_common_lisp_symbol("OTHERWISE"));
        }
        else if (consP(cond->first())) {
          cond->first_setter(cl_translate_list_of_trees(((Cons*)(cond->first()))));
        }
        else {
          cond->first_setter(cl_translate_a_tree(cond->first()));
        }
        cond->rest = cl_translate_list_of_trees(cond->rest);
      }
    }
    tree->first_setter((otherwiseP ? ((Symbol*)(intern_common_lisp_symbol("CASE"))) : ((Symbol*)(intern_common_lisp_symbol("ECASE")))));
    return (tree);
  }
}

Cons* cl_translate_boolean_tree(Cons* tree) {
  tree = cl_translate_boolean_test(tree, FALSE);
  return (listO(3, intern_common_lisp_symbol("IF"), tree, listO(3, SYM_CL_TRANSLATE_TRUE, SYM_CL_TRANSLATE_FALSE, NIL)));
}

Symbol* class_to_native_symbol(Class* renamed_Class) {
  if (((String_Wrapper*)(dynamic_slot_value(renamed_Class, SYM_CL_TRANSLATE_CLASS_CL_NATIVE_TYPE, NULL_STRING_WRAPPER)))->wrapper_value != NULL) {
    return (intern_common_lisp_symbol(((String_Wrapper*)(dynamic_slot_value(renamed_Class, SYM_CL_TRANSLATE_CLASS_CL_NATIVE_TYPE, NULL_STRING_WRAPPER)))->wrapper_value));
  }
  else {
    return (class_symbol(renamed_Class));
  }
}

Object* yield_struct_constructor_name(Class* renamed_Class) {
  return (yield_global_lisp_symbol(((Module*)(renamed_Class->class_type->home_context)), string_concatenate("MAKE...", class_to_native_symbol(renamed_Class)->symbol_name)));
}

Cons* cl_translate_make_tree(Cons* tree) {
  { Class* renamed_Class = ((Class*)(typify(tree->second())->surrogate_value));
    Object* classsymbol = cl_translate_global_symbol(class_to_native_symbol(renamed_Class));
    Cons* otree = NULL;

    if (use_cl_structsP()) {
      if (use_vector_structsP()) {
        otree = cons(cl_translate_global_symbol(SYM_CL_TRANSLATE_CLSYS_MAKE), cons(classsymbol, cons(integer_wrap_literal(cl_struct_slots(renamed_Class)->length() + 1), NIL)));
      }
      else {
        otree = cons(yield_struct_constructor_name(renamed_Class), NIL);
      }
    }
    else {
      otree = listO(3, intern_common_lisp_symbol("MAKE-INSTANCE"), listO(3, intern_common_lisp_symbol("QUOTE"), classsymbol, NIL), NIL);
    }
    free_cons_list(tree);
    return (otree);
  }
}

Cons* cl_translate_new_tree(Cons* tree) {
  { Object* typespec = tree->second();
    Object* constructorname = cl_translate_global_symbol(yield_constructor_name((typeP(typespec) ? ((Surrogate*)(((Surrogate*)(typespec)))) : ((Surrogate*)(((Parametric_Type_Specifier*)(typespec))->specifier_base_type)))->get_class(TRUE)));
    Cons* requiredargrefs = cl_translate_list_of_trees(tree->rest->rest);

    tree->rest->free_cons();
    tree->free_cons();
    return (cons(constructorname, requiredargrefs->concatenate(NIL)));
  }
}

Cons* cl_translate_operator_tree(Cons* tree) {
  { Symbol* renamed_Operator = NULL;
    Surrogate* owner = NULL;
    Cons* arguments = NULL;

    renamed_Operator = destructure_call_tree(tree, owner, arguments);
    owner = owner;
    if ((renamed_Operator == SYM_CL_TRANSLATE_i) ||
        (renamed_Operator == SYM_CL_TRANSLATE__)) {
      if ((arguments->length() == 2) &&
          arguments->memberP(ONE_WRAPPER)) {
        if (eqlP(arguments->first(), ONE_WRAPPER)) {
          arguments = arguments->rest;
        }
        else {
          arguments->rest = NIL;
        }
        if (renamed_Operator == SYM_CL_TRANSLATE_i) {
          renamed_Operator = intern_common_lisp_symbol("1+");
        }
        else {
          renamed_Operator = intern_common_lisp_symbol("1-");
        }
      }
    }
    else {
    }
    if ((renamed_Operator == SYM_CL_TRANSLATE_i) ||
        ((renamed_Operator == SYM_CL_TRANSLATE__) ||
         ((renamed_Operator == SYM_CL_TRANSLATE_o) ||
          (renamed_Operator == SYM_CL_TRANSLATE_s)))) {
      renamed_Operator = ((Symbol*)(oCL_OPERATOR_TABLEo->lookup(renamed_Operator)));
    }
    else {
    }
    return (cons(cl_translate_global_symbol(renamed_Operator), cl_translate_list_of_trees(arguments)->concatenate(NIL)));
  }
}

Cons* yield_format_arguments(Cons* tree) {
  { char* formatstring = "";
    Cons* formatarguments = NIL;

    tree->rest->rest = tree->rest->rest->reverse();
    { Object* arg = NULL;
      Cons* iter_001 = tree->rest->rest;

      while (!nilP(iter_001)) {
        {
          arg = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if (stringP(arg)) {
          formatstring = string_concatenate(((String_Wrapper*)(arg))->wrapper_value, formatstring);
        }
        else if (arg == EOL) {
          formatstring = string_concatenate("~%", formatstring);
        }
        else {
          formatstring = string_concatenate("~A", formatstring);
          formatarguments = cons(cl_translate_a_tree(arg), formatarguments);
        }
      }
    }
    formatarguments = cons(string_wrap_literal(formatstring), formatarguments);
    free_cons_list(tree);
    return (formatarguments);
  }
}

Cons* yield_print_tree(Cons* tree) {
  { Object* stream = tree->second();
    Cons* arguments = tree->rest->rest;
    Surrogate* argumenttype = NULL;
    Symbol* printoperator = NULL;
    char* compoundedstring = NULL;
    Cons* printforms = NIL;

    stream = cl_translate_a_tree(stream);
    { Object* arg = NULL;
      Cons* iter_001 = arguments;

      while (!nilP(iter_001)) {
        {
          arg = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if (arg == EOL) {
          printforms = cons(listO(3, intern_common_lisp_symbol("TERPRI"), SYM_CL_TRANSLATE_rrSTREAM, NIL), printforms);
          printforms = cons(listO(3, intern_common_lisp_symbol("FORCE-OUTPUT"), SYM_CL_TRANSLATE_rrSTREAM, NIL), printforms);
          compoundedstring = NULL;
        }
        else {
          argumenttype = type_spec_to_base_type(walked_expression_type(arg));
          if (argumenttype == SGT_CL_TRANSLATE_STRING) {
            printoperator = intern_common_lisp_symbol("WRITE-STRING");
          }
          else {
            if (subtype_ofP(argumenttype, SGT_CL_TRANSLATE_OBJECT)) {
              printoperator = SYM_CL_TRANSLATE_PRINT_OBJECT;
            }
            else {
              printoperator = intern_common_lisp_symbol("PRINC");
            }
          }
          { Object* arg_001 = arg;

            if (stringP(arg)) {
              { String_Wrapper* arg = NULL;

                arg = ((String_Wrapper*)(arg_001));
                if (compoundedstring != NULL) {
                  compoundedstring = string_concatenate(compoundedstring, arg->wrapper_value);
                  ((Cons*)(printforms->first()))->second_setter(string_wrap_literal(compoundedstring));
                  continue;
                }
                compoundedstring = arg->wrapper_value;
              }
            }
            else {
              compoundedstring = NULL;
            }
          }
          { Symbol* test_value_001 = method_call_type_for_vector_structs(printoperator, argumenttype, !(printoperator == SYM_CL_TRANSLATE_PRINT_OBJECT));

            if (test_value_001 == SYM_CL_TRANSLATE_PRINT_OBJECT) {
              printforms = cons(cl_translate_normal_call_method_tree(SYM_CL_TRANSLATE_PRINT_OBJECT, argumenttype, cons(arg, cons(SYM_CL_TRANSLATE_rrSTREAM, NIL))), printforms);
            }
            else {
              printforms = cons(cons(printoperator, cons(cl_translate_a_tree(arg), cons(SYM_CL_TRANSLATE_rrSTREAM, NIL))), printforms);
            }
          }
        }
      }
    }
    printforms = printforms->reverse();
    if (consP(stream) &&
        (printforms->length() > 1)) {
      printforms = listO(3, intern_common_lisp_symbol("LET"), cons(listO(3, SYM_CL_TRANSLATE_rrSTREAM, stream, NIL), NIL), printforms->concatenate(NIL));
    }
    else {
      { Object* printform = NULL;
        Cons* iter_002 = printforms;

        while (!nilP(iter_002)) {
          {
            printform = iter_002->value;
            iter_002 = iter_002->rest;
          }
          last_cons(((Cons*)(printform)))->value = stream;
        }
      }
      if (printforms->length() > 1) {
        printforms = cons(intern_common_lisp_symbol("PROGN"), printforms->concatenate(NIL));
      }
      else {
        printforms = ((Cons*)(printforms->first()));
      }
    }
    free_cons_list(tree);
    return (printforms);
  }
}

Cons* cl_translate_print_stream_tree(Cons* tree) {
  { Object* stream = tree->second();

    if (stream == KWD_CL_TRANSLATE_WARN) {
      return (cons(intern_common_lisp_symbol("WARN"), yield_format_arguments(tree)->concatenate(NIL)));
    }
    else if (stream == KWD_CL_TRANSLATE_ERROR) {
      return (cons(intern_common_lisp_symbol("ERROR"), yield_format_arguments(tree)->concatenate(NIL)));
    }
    else if (stream == KWD_CL_TRANSLATE_CONTINUABLE_ERROR) {
      return (listO(3, intern_common_lisp_symbol("CERROR"), string_wrap_literal("Continue anyway? "), yield_format_arguments(tree)->concatenate(NIL)));
    }
    else {
      return (yield_print_tree(tree));
    }
  }
}

Cons* cl_translate_call_function_code_tree(Cons* tree) {
  { Cons* otree = tree->rest;

    tree->second()->free_parse_tree();
    tree->free_cons();
    otree->rest = cl_translate_list_of_trees(otree->rest);
    otree->first_setter(intern_common_lisp_symbol("FUNCALL"));
    return (otree);
  }
}

Cons* cl_translate_the_code_tree(Cons* tree) {
  { Symbol* name = ((Symbol*)(((tree->second() == KWD_CL_TRANSLATE_FUNCTION) ? ((Object*)(tree->third())) : ((Object*)(tree->fourth())))));

    free_cons_list(tree);
    return (listO(3, intern_common_lisp_symbol("FUNCTION"), cl_translate_global_symbol(yield_renamed_name_if_native(name, KWD_CL_TRANSLATE_COMMON_LISP, KWD_CL_TRANSLATE_FUNCTION)), NIL));
  }
}

Object* cl_translate_verbatim_tree(Cons* tree) {
  { Cons* cursor = tree->rest;
    Object* verbatimcode = NULL;

    while (cursor->non_emptyP()) {
      if (cursor->value == KWD_CL_TRANSLATE_COMMON_LISP) {
        verbatimcode = cursor->rest->value;
        cursor->rest->value = NULL;
        break;
      }
      cursor = cursor->rest->rest;
    }
    free_cons_tree(tree);
    return (verbatimcode);
  }
}

Cons* cl_translate_inline_tree(Cons* tree) {
  { Object* renamed_Operator = tree->first();
    Cons* body = cl_translate_list_of_trees(tree->rest);

    tree->free_cons();
    if (renamed_Operator == SYM_CL_TRANSLATE_INLINE) {
      renamed_Operator = intern_common_lisp_symbol("INLINE");
    }
    else if (renamed_Operator == SYM_CL_TRANSLATE_IGNORE) {
      renamed_Operator = intern_common_lisp_symbol("IGNORE");
    }
    else {
      cerr << "`" << renamed_Operator << "'" << " is not a valid case option";
    }
    return (listO(3, intern_common_lisp_symbol("DECLARE"), cons(renamed_Operator, body->concatenate(NIL)), NIL));
  }
}

Object* cl_translate_unit(Translation_Unit* unit) {
  { Symbol* test_value_001 = unit->category;

    if (test_value_001 == SYM_CL_TRANSLATE_GLOBAL_VARIABLE) {
      return (cl_translate_define_global_variable_unit(unit));
    }
    else if (test_value_001 == SYM_CL_TRANSLATE_CLASS) {
      return (cl_translate_define_native_class_unit(unit));
    }
    else if ((test_value_001 == SYM_CL_TRANSLATE_METHOD) ||
        (test_value_001 == SYM_CL_TRANSLATE_MACRO)) {
      return (cl_translate_define_method_unit(unit));
    }
    else if (test_value_001 == SYM_CL_TRANSLATE_PRINT_METHOD) {
      return (cl_translate_defprint_unit(unit));
    }
    else if ((test_value_001 == SYM_CL_TRANSLATE_STARTUP_TIME_PROGN) ||
        (test_value_001 == SYM_CL_TRANSLATE_VERBATIM)) {
      return (cl_translate_a_tree(unit->the_object));
    }
    else if (test_value_001 == SYM_CL_TRANSLATE_TYPE) {
      unit->category = NULL;
      return (NIL);
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

Cons* cl_translate_method_parameters(Method_Slot* method) {
  { boolean functionP = method->method_functionP;
    Cons* otree = NIL;
    Object* firstparametertype = NULL;

    { int i = NULL_INTEGER;
      Standard_Object* ptype = NULL;
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
          ptype = ((Standard_Object*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        {
          i = iter_003;
          iter_003 = iter_003 + 1;
        }
        if ((!functionP) &&
            (i == 1)) {
          firstparametertype = cl_translate_global_symbol(class_to_native_symbol(type_to_class(type_spec_to_base_type(ptype))));
          { Symbol* test_value_001 = method_call_type_for_vector_structs(method->slot_name, method->slot_owner, functionP);

            if (test_value_001 == SYM_CL_TRANSLATE_OBJECT_METHOD) {
              otree = cons(listO(3, SYM_CL_TRANSLATE_CLSYS_SELF, firstparametertype, NIL), otree);
              otree = cons(parameter, otree);
            }
            else if (test_value_001 == SYM_CL_TRANSLATE_NON_OBJECT_METHOD) {
              otree = cons(cons(parameter, cons(firstparametertype, NIL)), otree);
              otree = cons(SYM_CL_TRANSLATE_CLSYS_DUMMY, otree);
            }
            else {
              otree = cons(cons(parameter, cons(firstparametertype, NIL)), otree);
            }
          }
        }
        else {
          otree = cons(parameter, otree);
        }
      }
    }
    if (method->method_variable_argumentsP_reader() &&
        (!pass_variable_arguments_as_listP(method))) {
      otree->rest = cons(intern_common_lisp_symbol("&REST"), otree->rest->concatenate(NIL));
    }
    return (otree->reverse());
  }
}

Cons* cl_translate_define_method_unit(Translation_Unit* unit) {
  { Method_Slot* method = ((Method_Slot*)(unit->the_object));
    Symbol* methodname = method->slot_name;
    char* documentation = ((String_Wrapper*)(dynamic_slot_value(method, SYM_CL_TRANSLATE_DOCUMENTATION, NULL_STRING_WRAPPER)))->wrapper_value;
    boolean functionP = method->method_functionP;
    Cons* bodytree = ((Cons*)(unit->code_register));
    Cons* extratrees = NIL;
    Cons* otree = NIL;

    { Symbol* test_value_001 = method_call_type_for_vector_structs(methodname, method->slot_owner, functionP);

      if (test_value_001 == SYM_CL_TRANSLATE_PRINT_OBJECT) {
        extratrees = cons(listO(4, SYM_CL_TRANSLATE_SETQ, SYM_CL_TRANSLATE_SELF, cl_translate_global_symbol(SYM_CL_TRANSLATE_oCLSYS_SELFo), NIL), NIL);
      }
      else if (test_value_001 == SYM_CL_TRANSLATE_NON_OBJECT_METHOD) {
        extratrees = cons(listO(3, intern_common_lisp_symbol("DECLARE"), listO(3, intern_common_lisp_symbol("IGNORE"), SYM_CL_TRANSLATE_CLSYS_DUMMY, NIL), NIL), NIL);
      }
      else {
      }
    }
    otree = cons((functionP ? ((Symbol*)(intern_common_lisp_symbol("DEFUN"))) : ((Symbol*)(intern_common_lisp_symbol("DEFMETHOD")))), cons(cl_translate_global_symbol(yield_renamed_name_if_native(methodname, KWD_CL_TRANSLATE_COMMON_LISP, KWD_CL_TRANSLATE_FUNCTION)), cons(cl_translate_method_parameters(method), ((documentation != NULL) ? ((Cons*)(cons(string_wrap_literal(documentation), NIL))) : ((Cons*)(NIL)))->concatenate(extratrees->concatenate(cl_translate_list_of_trees(bodytree)->concatenate(cons(KWD_CL_TRANSLATE_VOID, NIL)))))));
    if (method->method_auxiliaryP_reader()) {
      method->free();
    }
    return (otree);
  }
}

Cons* yield_clos_slot_tree(Storage_Slot* slot) {
  { Symbol* slotname = true_slot_name(slot->slot_name, slot->slot_owner);
    Keyword* allocation = slot->allocation();
    Cons* allocationform = NIL;
    char* documentation = ((String_Wrapper*)(dynamic_slot_value(slot, SYM_CL_TRANSLATE_DOCUMENTATION, NULL_STRING_WRAPPER)))->wrapper_value;
    Cons* documentationform = NIL;

    if (allocation == KWD_CL_TRANSLATE_EMBEDDED) {
      allocation = KWD_CL_TRANSLATE_INSTANCE;
    }
    else {
    }
    if (allocation != NULL) {
      allocationform = listO(3, KWD_CL_TRANSLATE_ALLOCATION, allocation, NIL);
    }
    if (documentation != NULL) {
      documentationform = listO(3, KWD_CL_TRANSLATE_DOCUMENTATION, string_wrap_literal(documentation), NIL);
    }
    return (cons(cl_translate_global_symbol(slotname), documentationform->concatenate(allocationform->concatenate(listO(3, KWD_CL_TRANSLATE_ACCESSOR, yield_clos_slot_accessor_name(slotname), NIL)))));
  }
}

Cons* yield_clos_class_tree(Class* renamed_Class) {
  { Cons* directsupers = NIL;
    Cons* closslotdefs = NIL;
    char* documentation = ((String_Wrapper*)(dynamic_slot_value(renamed_Class, SYM_CL_TRANSLATE_DOCUMENTATION, NULL_STRING_WRAPPER)))->wrapper_value;

    { Surrogate* super = NULL;
      Iterator* iter_001 = class_native_supers(renamed_Class);
      Cons* collect_001 = NULL;

      while (iter_001->nextP()) {
        {
          super = ((Surrogate*)(iter_001->value));
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(cl_translate_global_symbol(type_to_symbol(super)), NIL);
            if (nilP(directsupers)) {
              directsupers = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(directsupers, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(cl_translate_global_symbol(type_to_symbol(super)), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    { Slot* slot = NULL;
      Iterator* iter_002 = renamed_Class->class_slots();
      Cons* collect_002 = NULL;

      while (iter_002->nextP()) {
        {
          slot = ((Slot*)(iter_002->value));
        }
        if (storage_slotP(slot) &&
            native_slotP(((Storage_Slot*)(slot)))) {
          if (!(native_slot_home(((Storage_Slot*)(slot)), renamed_Class) == renamed_Class)) {
            if ((slot->slot_base_type != NULL) &&
                (!(((Class*)(slot->slot_base_type->surrogate_value)) != NULL))) {
              cerr << "Can't generate a native slot named " << "`" << slot->slot_name << "'" << " for the class " << "`" << class_name(renamed_Class) << "'" << endl << " because the slot's :type " << "`" << slot->slot_base_type << "'" << " is undefined.";
            }
            continue;
          }
          if (collect_002 == NULL) {
            {
              collect_002 = cons(yield_clos_slot_tree(((Storage_Slot*)(slot))), NIL);
              if (nilP(closslotdefs)) {
                closslotdefs = collect_002;
              }
              else {
                add_cons_to_end_of_cons_list(closslotdefs, collect_002);
              }
            }
          }
          else {
            {
              collect_002->rest = cons(yield_clos_slot_tree(((Storage_Slot*)(slot))), NIL);
              collect_002 = collect_002->rest;
            }
          }
        }
      }
    }
    return (listO(3, intern_common_lisp_symbol("DEFCLASS"), cl_translate_global_symbol(class_symbol(renamed_Class)), cons(directsupers, cons(closslotdefs, ((documentation != NULL) ? ((Cons*)(cons(listO(3, KWD_CL_TRANSLATE_DOCUMENTATION, string_wrap_literal(documentation), NIL), NIL))) : ((Cons*)(NIL)))->concatenate(NIL)))));
  }
}

List* compute_cl_struct_slots(Class* renamed_Class) {
  { Surrogate* value_001 = NULL;

    { Surrogate* super = NULL;
      Iterator* iter_001 = class_native_supers(renamed_Class);

      while (iter_001->nextP()) {
        {
          super = ((Surrogate*)(iter_001->value));
        }
        if (!((Class*)(super->surrogate_value))->mixinP) {
          value_001 = super;
          break;
        }
      }
    }
    { Surrogate* realsuper = value_001;
      List* result = ((realsuper != NULL) ? ((List*)(compute_cl_struct_slots(((Class*)(realsuper->surrogate_value))))) : ((List*)(NULL)));

      if (!(result != NULL)) {
        result = new_list();
      }
      { Surrogate* super = NULL;
        Iterator* iter_002 = class_native_supers(renamed_Class);

        while (iter_002->nextP()) {
          {
            super = ((Surrogate*)(iter_002->value));
          }
          if (!(super == realsuper)) {
            { Slot* slot = NULL;
              Iterator* iter_003 = ((Class*)(super->surrogate_value))->class_slots();
              Cons* collect_001 = NULL;

              while (iter_003->nextP()) {
                {
                  slot = ((Slot*)(iter_003->value));
                }
                if (storage_slotP(slot) &&
                    native_slotP(((Storage_Slot*)(slot)))) {
                  if (collect_001 == NULL) {
                    {
                      collect_001 = permanent_cons(slot, NIL);
                      if (result->the_cons_list->emptyP()) {
                        result->the_cons_list = collect_001;
                      }
                      else {
                        add_cons_to_end_of_cons_list(result->the_cons_list, collect_001);
                      }
                    }
                  }
                  else {
                    {
                      collect_001->rest = permanent_cons(slot, NIL);
                      collect_001 = collect_001->rest;
                    }
                  }
                }
              }
            }
          }
        }
      }
      { Slot* slot = NULL;
        Cons* iter_004 = renamed_Class->class_local_slots->the_cons_list;
        Cons* collect_002 = NULL;

        while (!nilP(iter_004)) {
          {
            slot = ((Slot*)(iter_004->value));
            iter_004 = iter_004->rest;
          }
          if (storage_slotP(slot) &&
              native_slotP(((Storage_Slot*)(slot)))) {
            if (collect_002 == NULL) {
              {
                collect_002 = permanent_cons(slot, NIL);
                if (result->the_cons_list->emptyP()) {
                  result->the_cons_list = collect_002;
                }
                else {
                  add_cons_to_end_of_cons_list(result->the_cons_list, collect_002);
                }
              }
            }
            else {
              {
                collect_002->rest = permanent_cons(slot, NIL);
                collect_002 = collect_002->rest;
              }
            }
          }
        }
      }
      return (result);
    }
  }
}

List* cl_struct_slots(Class* renamed_Class) {
  { List* slots = renamed_Class->class_cl_struct_slots_reader();

    if (defined_listP(slots)) {
      return (slots);
    }
    else {
      return (((List*)(set_dynamic_slot_value(renamed_Class, SYM_CL_TRANSLATE_CLASS_CL_STRUCT_SLOTS, compute_cl_struct_slots(renamed_Class), NULL))));
    }
  }
}

int cl_struct_slot_offset(Symbol* slotname, Surrogate* classtype) {
  { List* slots = cl_struct_slots(((Class*)(classtype->surrogate_value)));
    int offset = 1;

    { Storage_Slot* slot = NULL;
      Cons* iter_001 = slots->the_cons_list;

      while (!nilP(iter_001)) {
        {
          slot = ((Storage_Slot*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (slot->slot_name == slotname) {
          return (offset);
        }
        else {
          offset = offset + 1;
        }
      }
    }
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
              cout << endl << " " << "Can't find slot " << "`" << de_uglify_parse_tree(slotname) << "'" << " on CL-struct class " << "`" << de_uglify_parse_tree(classtype) << "'" << "." << endl;
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
    return (NULL_INTEGER);
  }
}

Cons* yield_struct_slot_trees(Class* renamed_Class) {
  { Cons* structslotdefs = NIL;

    { Storage_Slot* slot = NULL;
      Cons* iter_001 = cl_struct_slots(renamed_Class)->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          slot = ((Storage_Slot*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (!(mixin_slot_home(slot, renamed_Class) == renamed_Class)) {
          if ((slot->slot_base_type != NULL) &&
              (!(((Class*)(slot->slot_base_type->surrogate_value)) != NULL))) {
            cerr << "Can't generate a native slot named " << "`" << slot->slot_name << "'" << " for the class " << "`" << class_name(renamed_Class) << "'" << endl << " because the slot's :type " << "`" << slot->slot_base_type << "'" << " is undefined.";
          }
          continue;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(cons(slot->slot_name, cons(SYM_CL_TRANSLATE_NULL, NIL)), NIL);
            if (nilP(structslotdefs)) {
              structslotdefs = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(structslotdefs, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(cons(slot->slot_name, cons(SYM_CL_TRANSLATE_NULL, NIL)), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    return (structslotdefs);
  }
}

Cons* yield_struct_tree(Class* renamed_Class) {
  { Surrogate* value_001 = NULL;

    { Surrogate* super = NULL;
      Iterator* iter_001 = class_native_supers(renamed_Class);

      while (iter_001->nextP()) {
        {
          super = ((Surrogate*)(iter_001->value));
        }
        if (!((Class*)(super->surrogate_value))->mixinP) {
          value_001 = super;
          break;
        }
      }
    }
    { Surrogate* super = value_001;
      char* documentation = ((String_Wrapper*)(dynamic_slot_value(renamed_Class, SYM_CL_TRANSLATE_DOCUMENTATION, NULL_STRING_WRAPPER)))->wrapper_value;

      return (listO(3, intern_common_lisp_symbol("DEFSTRUCT"), cons(cl_translate_global_symbol(class_symbol(renamed_Class)), listO(3, listO(3, KWD_CL_TRANSLATE_CONC_NAME, yield_global_lisp_symbol(((Module*)(renamed_Class->class_type->home_context)), string_concatenate(class_name(renamed_Class), "...")), NIL), listO(3, KWD_CL_TRANSLATE_CONSTRUCTOR, yield_struct_constructor_name(renamed_Class), cons(NIL, NIL)), ((super != NULL) ? ((Cons*)(cons(listO(3, KWD_CL_TRANSLATE_INCLUDE, cl_translate_global_symbol(type_to_symbol(super)), NIL), NIL))) : ((Cons*)(NIL)))->concatenate(NIL))), ((documentation != NULL) ? ((Cons*)(cons(string_wrap_literal(documentation), NIL))) : ((Cons*)(NIL)))->concatenate(yield_struct_slot_trees(renamed_Class)->concatenate(NIL))));
    }
  }
}

Object* yield_vector_struct_name(Class* renamed_Class) {
  return (yield_global_lisp_symbol(((Module*)(renamed_Class->class_type->home_context)), string_concatenate("CLSYS-", class_name(renamed_Class))));
}

Cons* yield_vector_struct_tree(Class* renamed_Class) {
  { Surrogate* value_001 = NULL;

    { Surrogate* super = NULL;
      Iterator* iter_001 = class_native_supers(renamed_Class);

      while (iter_001->nextP()) {
        {
          super = ((Surrogate*)(iter_001->value));
        }
        if (!((Class*)(super->surrogate_value))->mixinP) {
          value_001 = super;
          break;
        }
      }
    }
    { Surrogate* super = value_001;
      char* documentation = ((String_Wrapper*)(dynamic_slot_value(renamed_Class, SYM_CL_TRANSLATE_DOCUMENTATION, NULL_STRING_WRAPPER)))->wrapper_value;

      return (listO(3, intern_common_lisp_symbol("DEFCLASS"), cl_translate_global_symbol(class_symbol(renamed_Class)), cons(((super != NULL) ? ((Cons*)(cons(cl_translate_global_symbol(type_to_symbol(super)), NIL))) : ((Cons*)(NIL))), cons(NIL, ((documentation != NULL) ? ((Cons*)(cons(listO(3, KWD_CL_TRANSLATE_DOCUMENTATION, string_wrap_literal(documentation), NIL), NIL))) : ((Cons*)(NIL)))->concatenate(NIL)))));
    }
  }
}

Cons* cl_translate_define_native_class_unit(Translation_Unit* unit) {
  { Class* renamed_Class = ((Class*)(unit->the_object));

    if (use_cl_structsP()) {
      if (use_vector_structsP()) {
        return (yield_vector_struct_tree(renamed_Class));
      }
      else {
        return (yield_struct_tree(renamed_Class));
      }
    }
    else {
      return (yield_clos_class_tree(renamed_Class));
    }
  }
}

Cons* cl_translate_define_global_variable_unit(Translation_Unit* unit) {
  { Global_Variable* global = ((Global_Variable*)(unit->the_object));
    Object* name = cl_translate_global_symbol(global->variable_name);
    char* documentation = global->documentation;
    boolean unboundspecialP = global->variable_specialP &&
        (unit->code_register == KWD_CL_TRANSLATE_UNBOUND_SPECIAL_VARIABLE);
    Object* initialvaluetree = cl_translate_a_tree(unit->code_register);
    Symbol* renamed_Operator = intern_common_lisp_symbol("DEFVAR");

    if (global->variable_constantP &&
        FALSE) {
      renamed_Operator = intern_common_lisp_symbol("DEFCONSTANT");
    }
    return ((unboundspecialP ? ((Cons*)(listO(3, intern_common_lisp_symbol("DEFVAR"), name, NIL))) : ((Cons*)(cons(renamed_Operator, cons(name, cons(initialvaluetree, ((documentation != NULL) ? ((Cons*)(cons(string_wrap_literal(documentation), NIL))) : ((Cons*)(NIL)))->concatenate(NIL))))))));
  }
}

Cons* cl_translate_defprint_unit(Translation_Unit* unit) {
  { Class* renamed_Class = ((Class*)(unit->the_object));
    Object* body = unit->code_register;
    Cons* extratrees = NIL;

    { Symbol* test_value_001 = method_call_type_for_vector_structs(SYM_CL_TRANSLATE_PRINT_OBJECT, renamed_Class->class_type, FALSE);

      if (test_value_001 == SYM_CL_TRANSLATE_PRINT_OBJECT) {
        extratrees = cons(listO(4, SYM_CL_TRANSLATE_SETQ, SYM_CL_TRANSLATE_SELF, cl_translate_global_symbol(SYM_CL_TRANSLATE_oCLSYS_SELFo), NIL), NIL);
      }
      else {
      }
    }
    return (listO(4, intern_common_lisp_symbol("DEFMETHOD"), SYM_CL_TRANSLATE_PRINT_OBJECT, listO(3, listO(3, SYM_CL_TRANSLATE_SELF, class_symbol(renamed_Class), NIL), SYM_CL_TRANSLATE_STREAM, NIL), extratrees->concatenate(cons(cl_translate_a_tree(body), NIL))));
  }
}

void startup_cl_translate() {
  if (current_startup_time_phaseP(0)) {
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
            SYM_CL_TRANSLATE_SYS_CALL_FUNCTION = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-CALL-FUNCTION", NULL, 0)));
            SYM_CL_TRANSLATE_SYS_CALL_METHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-CALL-METHOD", NULL, 0)));
            SGT_CL_TRANSLATE_KEY_VALUE_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("KEY-VALUE-LIST", NULL, 1)));
            SYM_CL_TRANSLATE_i = ((Symbol*)(intern_rigid_symbol_wrt_module("+", NULL, 0)));
            SYM_CL_TRANSLATE__ = ((Symbol*)(intern_rigid_symbol_wrt_module("-", NULL, 0)));
            SYM_CL_TRANSLATE_o = ((Symbol*)(intern_rigid_symbol_wrt_module("*", NULL, 0)));
            SYM_CL_TRANSLATE_s = ((Symbol*)(intern_rigid_symbol_wrt_module("/", NULL, 0)));
            SYM_CL_TRANSLATE_EQp = ((Symbol*)(intern_rigid_symbol_wrt_module("EQ?", NULL, 0)));
            SYM_CL_TRANSLATE_l = ((Symbol*)(intern_rigid_symbol_wrt_module("<", NULL, 0)));
            SYM_CL_TRANSLATE_le = ((Symbol*)(intern_rigid_symbol_wrt_module("<=", NULL, 0)));
            SYM_CL_TRANSLATE_ge = ((Symbol*)(intern_rigid_symbol_wrt_module(">=", NULL, 0)));
            SYM_CL_TRANSLATE_g = ((Symbol*)(intern_rigid_symbol_wrt_module(">", NULL, 0)));
            SYM_CL_TRANSLATE_e = ((Symbol*)(intern_rigid_symbol_wrt_module("=", NULL, 0)));
            SYM_CL_TRANSLATE_xse = ((Symbol*)(intern_rigid_symbol_wrt_module("!/=", NULL, 0)));
            KWD_CL_TRANSLATE_USE_COMMON_LISP_STRUCTS = ((Keyword*)(intern_rigid_symbol_wrt_module("USE-COMMON-LISP-STRUCTS", NULL, 2)));
            KWD_CL_TRANSLATE_USE_COMMON_LISP_VECTOR_STRUCTS = ((Keyword*)(intern_rigid_symbol_wrt_module("USE-COMMON-LISP-VECTOR-STRUCTS", NULL, 2)));
            SGT_CL_TRANSLATE_VOID = ((Surrogate*)(intern_rigid_symbol_wrt_module("VOID", NULL, 1)));
            SYM_CL_TRANSLATE_VOID_SYS = ((Symbol*)(intern_rigid_symbol_wrt_module("VOID-SYS", NULL, 0)));
            SYM_CL_TRANSLATE_TYPED_SYS = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPED-SYS", NULL, 0)));
            SYM_CL_TRANSLATE_BAD_SYS = ((Symbol*)(intern_rigid_symbol_wrt_module("BAD-SYS", NULL, 0)));
            SYM_CL_TRANSLATE_SETQ = ((Symbol*)(intern_rigid_symbol_wrt_module("SETQ", NULL, 0)));
            SYM_CL_TRANSLATE_SYS_SLOT_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-SLOT-VALUE", NULL, 0)));
            SYM_CL_TRANSLATE_SYS_SLOT_VALUE_SETTER = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-SLOT-VALUE-SETTER", NULL, 0)));
            SYM_CL_TRANSLATE_PROGN = ((Symbol*)(intern_rigid_symbol_wrt_module("PROGN", NULL, 0)));
            SYM_CL_TRANSLATE_LOOP = ((Symbol*)(intern_rigid_symbol_wrt_module("LOOP", NULL, 0)));
            SYM_CL_TRANSLATE_SYS_FOREACH = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-FOREACH", NULL, 0)));
            SYM_CL_TRANSLATE_LET = ((Symbol*)(intern_rigid_symbol_wrt_module("LET", NULL, 0)));
            SYM_CL_TRANSLATE_STARTUP_TIME_PROGN = ((Symbol*)(intern_rigid_symbol_wrt_module("STARTUP-TIME-PROGN", NULL, 0)));
            SYM_CL_TRANSLATE_SPECIAL = ((Symbol*)(intern_rigid_symbol_wrt_module("SPECIAL", NULL, 0)));
            SYM_CL_TRANSLATE_CAST = ((Symbol*)(intern_rigid_symbol_wrt_module("CAST", NULL, 0)));
            SYM_CL_TRANSLATE_SAFE_CAST = ((Symbol*)(intern_rigid_symbol_wrt_module("SAFE-CAST", NULL, 0)));
            SYM_CL_TRANSLATE_RETURN = ((Symbol*)(intern_rigid_symbol_wrt_module("RETURN", NULL, 0)));
            SYM_CL_TRANSLATE_BREAK = ((Symbol*)(intern_rigid_symbol_wrt_module("BREAK", NULL, 0)));
            SYM_CL_TRANSLATE_CONTINUE = ((Symbol*)(intern_rigid_symbol_wrt_module("CONTINUE", NULL, 0)));
            SYM_CL_TRANSLATE_WHILE = ((Symbol*)(intern_rigid_symbol_wrt_module("WHILE", NULL, 0)));
            SYM_CL_TRANSLATE_IF = ((Symbol*)(intern_rigid_symbol_wrt_module("IF", NULL, 0)));
            SYM_CL_TRANSLATE_CHOOSE = ((Symbol*)(intern_rigid_symbol_wrt_module("CHOOSE", NULL, 0)));
            SYM_CL_TRANSLATE_WHEN = ((Symbol*)(intern_rigid_symbol_wrt_module("WHEN", NULL, 0)));
            SYM_CL_TRANSLATE_UNLESS = ((Symbol*)(intern_rigid_symbol_wrt_module("UNLESS", NULL, 0)));
            SYM_CL_TRANSLATE_AND = ((Symbol*)(intern_rigid_symbol_wrt_module("AND", NULL, 0)));
            SYM_CL_TRANSLATE_OR = ((Symbol*)(intern_rigid_symbol_wrt_module("OR", NULL, 0)));
            SYM_CL_TRANSLATE_NOT = ((Symbol*)(intern_rigid_symbol_wrt_module("NOT", NULL, 0)));
            SYM_CL_TRANSLATE_COND = ((Symbol*)(intern_rigid_symbol_wrt_module("COND", NULL, 0)));
            SYM_CL_TRANSLATE_CASE = ((Symbol*)(intern_rigid_symbol_wrt_module("CASE", NULL, 0)));
            SYM_CL_TRANSLATE_MAKE = ((Symbol*)(intern_rigid_symbol_wrt_module("MAKE", NULL, 0)));
            SYM_CL_TRANSLATE_SYS_NEW = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-NEW", NULL, 0)));
            SYM_CL_TRANSLATE_MV_SETQ = ((Symbol*)(intern_rigid_symbol_wrt_module("MV-SETQ", NULL, 0)));
            SYM_CL_TRANSLATE_QUOTE = ((Symbol*)(intern_rigid_symbol_wrt_module("QUOTE", NULL, 0)));
            SYM_CL_TRANSLATE_SYS_CALL_FUNCTION_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-CALL-FUNCTION-CODE", NULL, 0)));
            SYM_CL_TRANSLATE_SYS_CALL_METHOD_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-CALL-METHOD-CODE", NULL, 0)));
            SYM_CL_TRANSLATE_THE_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-CODE", NULL, 0)));
            SYM_CL_TRANSLATE_PRINT_STREAM = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-STREAM", NULL, 0)));
            SYM_CL_TRANSLATE_PRINT_NATIVE_STREAM = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-NATIVE-STREAM", NULL, 0)));
            SYM_CL_TRANSLATE_VERBATIM = ((Symbol*)(intern_rigid_symbol_wrt_module("VERBATIM", NULL, 0)));
            SYM_CL_TRANSLATE_INLINE = ((Symbol*)(intern_rigid_symbol_wrt_module("INLINE", NULL, 0)));
            SYM_CL_TRANSLATE_IGNORE = ((Symbol*)(intern_rigid_symbol_wrt_module("IGNORE", NULL, 0)));
            KWD_CL_TRANSLATE_CONTINUE = ((Keyword*)(intern_rigid_symbol_wrt_module("CONTINUE", NULL, 2)));
            SYM_CL_TRANSLATE_GET_KWD = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-KWD", NULL, 0)));
            SYM_CL_TRANSLATE_GET_SGT = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-SGT", NULL, 0)));
            SYM_CL_TRANSLATE_CLSYS_SVAL = ((Symbol*)(intern_rigid_symbol_wrt_module("CLSYS-SVAL", NULL, 0)));
            SYM_CL_TRANSLATE_NTH = ((Symbol*)(intern_rigid_symbol_wrt_module("NTH", NULL, 0)));
            SYM_CL_TRANSLATE_NTH_SETTER = ((Symbol*)(intern_rigid_symbol_wrt_module("NTH-SETTER", NULL, 0)));
            SYM_CL_TRANSLATE_NULLp = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL?", NULL, 0)));
            SYM_CL_TRANSLATE_DEFINEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINED?", NULL, 0)));
            SYM_CL_TRANSLATE_NORMAL_CALL = ((Symbol*)(intern_rigid_symbol_wrt_module("NORMAL-CALL", NULL, 0)));
            SGT_CL_TRANSLATE_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("OBJECT", NULL, 1)));
            SYM_CL_TRANSLATE_NON_OBJECT_METHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("NON-OBJECT-METHOD", NULL, 0)));
            SYM_CL_TRANSLATE_PRINT_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-OBJECT", NULL, 0)));
            SYM_CL_TRANSLATE_OBJECT_METHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("OBJECT-METHOD", NULL, 0)));
            KWD_CL_TRANSLATE_COMMON_LISP = ((Keyword*)(intern_rigid_symbol_wrt_module("COMMON-LISP", NULL, 2)));
            KWD_CL_TRANSLATE_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            SYM_CL_TRANSLATE_CLSYS_CALL = ((Symbol*)(intern_rigid_symbol_wrt_module("CLSYS-CALL", NULL, 0)));
            SYM_CL_TRANSLATE_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", NULL, 0)));
            SGT_CL_TRANSLATE_STRING = ((Surrogate*)(intern_rigid_symbol_wrt_module("STRING", NULL, 1)));
            SGT_CL_TRANSLATE_VECTOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("VECTOR", NULL, 1)));
            SYM_CL_TRANSLATE_THE_ARRAY = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-ARRAY", NULL, 0)));
            SYM_CL_TRANSLATE_DO = ((Symbol*)(intern_rigid_symbol_wrt_module("DO", NULL, 0)));
            SYM_CL_TRANSLATE_EVAL_WHEN = ((Symbol*)(intern_rigid_symbol_wrt_module("EVAL-WHEN", NULL, 0)));
            SYM_CL_TRANSLATE_PRIMARY_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("PRIMARY-TYPE", NULL, 0)));
            SYM_CL_TRANSLATE_NILp = ((Symbol*)(intern_rigid_symbol_wrt_module("NIL?", NULL, 0)));
            SYM_CL_TRANSLATE_EMPTYp = ((Symbol*)(intern_rigid_symbol_wrt_module("EMPTY?", NULL, 0)));
            SYM_CL_TRANSLATE_NON_EMPTYp = ((Symbol*)(intern_rigid_symbol_wrt_module("NON-EMPTY?", NULL, 0)));
            SGT_CL_TRANSLATE_LITERAL = ((Surrogate*)(intern_rigid_symbol_wrt_module("LITERAL", NULL, 1)));
            SGT_CL_TRANSLATE_NUMBER = ((Surrogate*)(intern_rigid_symbol_wrt_module("NUMBER", NULL, 1)));
            SGT_CL_TRANSLATE_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", NULL, 1)));
            SGT_CL_TRANSLATE_CODE = ((Surrogate*)(intern_rigid_symbol_wrt_module("CODE", NULL, 1)));
            SGT_CL_TRANSLATE_CONS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONS", NULL, 1)));
            SYM_CL_TRANSLATE_NIL = ((Symbol*)(intern_rigid_symbol_wrt_module("NIL", NULL, 0)));
            SYM_CL_TRANSLATE_OTHERWISE = ((Symbol*)(intern_rigid_symbol_wrt_module("OTHERWISE", NULL, 0)));
            SYM_CL_TRANSLATE_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            SYM_CL_TRANSLATE_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", NULL, 0)));
            SYM_CL_TRANSLATE_CLASS_CL_NATIVE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CL-NATIVE-TYPE", NULL, 0)));
            SYM_CL_TRANSLATE_CLSYS_MAKE = ((Symbol*)(intern_rigid_symbol_wrt_module("CLSYS-MAKE", NULL, 0)));
            SYM_CL_TRANSLATE_rrSTREAM = ((Symbol*)(intern_rigid_symbol_wrt_module("%%STREAM", NULL, 0)));
            KWD_CL_TRANSLATE_WARN = ((Keyword*)(intern_rigid_symbol_wrt_module("WARN", NULL, 2)));
            KWD_CL_TRANSLATE_ERROR = ((Keyword*)(intern_rigid_symbol_wrt_module("ERROR", NULL, 2)));
            KWD_CL_TRANSLATE_CONTINUABLE_ERROR = ((Keyword*)(intern_rigid_symbol_wrt_module("CONTINUABLE-ERROR", NULL, 2)));
            SYM_CL_TRANSLATE_GLOBAL_VARIABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("GLOBAL-VARIABLE", NULL, 0)));
            SYM_CL_TRANSLATE_CLASS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS", NULL, 0)));
            SYM_CL_TRANSLATE_METHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("METHOD", NULL, 0)));
            SYM_CL_TRANSLATE_MACRO = ((Symbol*)(intern_rigid_symbol_wrt_module("MACRO", NULL, 0)));
            SYM_CL_TRANSLATE_PRINT_METHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("PRINT-METHOD", NULL, 0)));
            SYM_CL_TRANSLATE_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("TYPE", NULL, 0)));
            SYM_CL_TRANSLATE_CLSYS_SELF = ((Symbol*)(intern_rigid_symbol_wrt_module("CLSYS-SELF", NULL, 0)));
            SYM_CL_TRANSLATE_CLSYS_DUMMY = ((Symbol*)(intern_rigid_symbol_wrt_module("CLSYS-DUMMY", NULL, 0)));
            SYM_CL_TRANSLATE_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 0)));
            SYM_CL_TRANSLATE_SELF = ((Symbol*)(intern_rigid_symbol_wrt_module("SELF", NULL, 0)));
            SYM_CL_TRANSLATE_oCLSYS_SELFo = ((Symbol*)(intern_rigid_symbol_wrt_module("*CLSYS-SELF*", NULL, 0)));
            KWD_CL_TRANSLATE_VOID = ((Keyword*)(intern_rigid_symbol_wrt_module("VOID", NULL, 2)));
            KWD_CL_TRANSLATE_EMBEDDED = ((Keyword*)(intern_rigid_symbol_wrt_module("EMBEDDED", NULL, 2)));
            KWD_CL_TRANSLATE_INSTANCE = ((Keyword*)(intern_rigid_symbol_wrt_module("INSTANCE", NULL, 2)));
            KWD_CL_TRANSLATE_ALLOCATION = ((Keyword*)(intern_rigid_symbol_wrt_module("ALLOCATION", NULL, 2)));
            KWD_CL_TRANSLATE_DOCUMENTATION = ((Keyword*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 2)));
            KWD_CL_TRANSLATE_ACCESSOR = ((Keyword*)(intern_rigid_symbol_wrt_module("ACCESSOR", NULL, 2)));
            SYM_CL_TRANSLATE_CLASS_CL_STRUCT_SLOTS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CL-STRUCT-SLOTS", NULL, 0)));
            KWD_CL_TRANSLATE_CONC_NAME = ((Keyword*)(intern_rigid_symbol_wrt_module("CONC-NAME", NULL, 2)));
            KWD_CL_TRANSLATE_CONSTRUCTOR = ((Keyword*)(intern_rigid_symbol_wrt_module("CONSTRUCTOR", NULL, 2)));
            KWD_CL_TRANSLATE_INCLUDE = ((Keyword*)(intern_rigid_symbol_wrt_module("INCLUDE", NULL, 2)));
            KWD_CL_TRANSLATE_UNBOUND_SPECIAL_VARIABLE = ((Keyword*)(intern_rigid_symbol_wrt_module("UNBOUND-SPECIAL-VARIABLE", NULL, 2)));
            SYM_CL_TRANSLATE_STREAM = ((Symbol*)(intern_rigid_symbol_wrt_module("STREAM", NULL, 0)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("DESTRUCTURE-CALL-TREE", "CONS", "(DEFUN (DESTRUCTURE-CALL-TREE SYMBOL TYPE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&destructure_call_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("USE-CL-STRUCTS?", NULL, "(DEFUN (USE-CL-STRUCTS? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&use_cl_structsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("USE-VECTOR-STRUCTS?", NULL, "(DEFUN (USE-VECTOR-STRUCTS? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&use_vector_structsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-LIST-OF-TREES", "CONS", "(DEFUN (CL-TRANSLATE-LIST-OF-TREES CONS) ((TREES CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_list_of_trees));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-VOID-SYS", "CONS", "(DEFUN (CL-TRANSLATE-VOID-SYS CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_void_sys));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-TYPED-SYS", "CONS", "(DEFUN (CL-TRANSLATE-TYPED-SYS OBJECT) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_typed_sys));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-BAD-SYS", "CONS", "(DEFUN (CL-TRANSLATE-BAD-SYS OBJECT) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_bad_sys));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-A-TREE", "OBJECT", "(DEFUN (CL-TRANSLATE-A-TREE OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&cl_translate_a_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-CL-TRANSLATE-A-TREE", "OBJECT", "(DEFUN (HELP-CL-TRANSLATE-A-TREE OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&help_cl_translate_a_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-ATOMIC-TREE", "OBJECT", "(DEFMETHOD (CL-TRANSLATE-ATOMIC-TREE OBJECT) ((TREE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Object::cl_translate_atomic_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-ATOMIC-TREE", "SYMBOL", "(DEFMETHOD (CL-TRANSLATE-ATOMIC-TREE OBJECT) ((TREE SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Symbol::cl_translate_atomic_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-ATOMIC-TREE", "KEYWORD", "(DEFMETHOD (CL-TRANSLATE-ATOMIC-TREE OBJECT) ((TREE KEYWORD)))");

              method->method_code = ((cpp_method_code)(&Keyword::cl_translate_atomic_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-ATOMIC-TREE", "SURROGATE", "(DEFMETHOD (CL-TRANSLATE-ATOMIC-TREE OBJECT) ((TREE SURROGATE)))");

              method->method_code = ((cpp_method_code)(&Surrogate::cl_translate_atomic_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-GLOBAL-SYMBOL", "SYMBOL", "(DEFUN (CL-TRANSLATE-GLOBAL-SYMBOL OBJECT) ((SYMBOL SYMBOL)))");

              method->function_code = ((cpp_function_code)(&cl_translate_global_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-GLOBAL-LISP-SYMBOL", "MODULE", "(DEFUN (YIELD-GLOBAL-LISP-SYMBOL OBJECT) ((SYMBOLMODULE MODULE) (SYMBOLNAME STRING)))");

              method->function_code = ((cpp_function_code)(&yield_global_lisp_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-SETQ-TREE", "CONS", "(DEFUN (CL-TRANSLATE-SETQ-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_setq_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-STRUCT-SLOT-ACCESSOR-NAME", "TYPE", "(DEFUN (YIELD-STRUCT-SLOT-ACCESSOR-NAME OBJECT) ((CLASSTYPE TYPE) (SLOTNAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_struct_slot_accessor_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CLOS-SLOT-ACCESSOR-NAME", "SYMBOL", "(DEFUN (YIELD-CLOS-SLOT-ACCESSOR-NAME OBJECT) ((SLOTNAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_clos_slot_accessor_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SLOT-VALUE-READER-TREE", "SYMBOL", "(DEFUN (YIELD-SLOT-VALUE-READER-TREE CONS) ((SLOTNAME SYMBOL) (OBJECTREF OBJECT) (OBJECTTYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&yield_slot_value_reader_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SLOT-VALUE-WRITER-TREE", "SYMBOL", "(DEFUN (YIELD-SLOT-VALUE-WRITER-TREE CONS) ((SLOTNAME SYMBOL) (OBJECTREF OBJECT) (OBJECTTYPE TYPE) (VALUEREF OBJECT)))");

              method->function_code = ((cpp_function_code)(&yield_slot_value_writer_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRUE-SLOT-NAME", "SYMBOL", "(DEFUN (TRUE-SLOT-NAME SYMBOL) ((SLOTNAME SYMBOL) (TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&true_slot_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-FIXED-SLOT-VALUE-TREE", "CONS", "(DEFUN (CL-TRANSLATE-FIXED-SLOT-VALUE-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_fixed_slot_value_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-FIXED-SLOT-VALUE-SETTER-TREE", "CONS", "(DEFUN (CL-TRANSLATE-FIXED-SLOT-VALUE-SETTER-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_fixed_slot_value_setter_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-CALL-METHOD-TREE", "CONS", "(DEFUN (CL-TRANSLATE-CALL-METHOD-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_call_method_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("METHOD-CALL-TYPE-FOR-VECTOR-STRUCTS", "SYMBOL", "(DEFUN (METHOD-CALL-TYPE-FOR-VECTOR-STRUCTS SYMBOL) ((SLOTNAME SYMBOL) (OWNER TYPE) (FUNCTION? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&method_call_type_for_vector_structs));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-NORMAL-CALL-METHOD-TREE", "SYMBOL", "(DEFUN (CL-TRANSLATE-NORMAL-CALL-METHOD-TREE CONS) ((OPERATOR SYMBOL) (OWNER TYPE) (ARGUMENTS CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_normal_call_method_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-NTH-TREE", "CONS", "(DEFUN (CL-TRANSLATE-NTH-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_nth_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("DUPLICATE-CURSOR-VARIABLE?", "SYMBOL", "(DEFUN (DUPLICATE-CURSOR-VARIABLE? BOOLEAN) ((VARIABLE SYMBOL) (ITERATORBINDINGS CONS)))");

              method->function_code = ((cpp_function_code)(&duplicate_cursor_variableP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-FOREACH-TREE", "CONS", "(DEFUN (CL-TRANSLATE-FOREACH-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_foreach_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("MAYBE-WRAP-WITH-CONTINUE-LABEL", "CONS", "(DEFUN (MAYBE-WRAP-WITH-CONTINUE-LABEL CONS) ((TRANSLATEDLOOPBODY CONS)))");

              method->function_code = ((cpp_function_code)(&maybe_wrap_with_continue_label));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-LET-TREE", "CONS", "(DEFUN (CL-TRANSLATE-LET-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_let_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-SPECIAL-TREE", "CONS", "(DEFUN (CL-TRANSLATE-SPECIAL-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_special_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-STARTUP-TIME-PROGN-TREE", "CONS", "(DEFUN (CL-TRANSLATE-STARTUP-TIME-PROGN-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_startup_time_progn_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CAST", "OBJECT", "(DEFUN (CAST OBJECT) ((VALUE OBJECT) (TYPE TYPE)) :DOCUMENTATION \"Perform a run-time type check, and then return 'value'.\")");

              method->function_code = ((cpp_function_code)(&cast));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-CAST-TREE", "CONS", "(DEFUN (CL-TRANSLATE-CAST-TREE OBJECT) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_cast_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-RETURN-TREE", "CONS", "(DEFUN (CL-TRANSLATE-RETURN-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_return_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-BOOLEAN-TEST", "OBJECT", "(DEFUN (CL-TRANSLATE-BOOLEAN-TEST CONS) ((TREE OBJECT) (INVERT? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&cl_translate_boolean_test));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-PLAIN-BOOLEAN-TEST", "OBJECT", "(DEFUN (CL-TRANSLATE-PLAIN-BOOLEAN-TEST CONS) ((TREE OBJECT) (INVERT? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&cl_translate_plain_boolean_test));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-WHILE-TREE", "CONS", "(DEFUN (CL-TRANSLATE-WHILE-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_while_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-CONDITIONAL-TREE", "CONS", "(DEFUN (CL-TRANSLATE-CONDITIONAL-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_conditional_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-COND-TREE", "CONS", "(DEFUN (CL-TRANSLATE-COND-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_cond_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-CASE-TREE", "CONS", "(DEFUN (CL-TRANSLATE-CASE-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_case_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-BOOLEAN-TREE", "CONS", "(DEFUN (CL-TRANSLATE-BOOLEAN-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_boolean_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-TO-NATIVE-SYMBOL", "CLASS", "(DEFUN (CLASS-TO-NATIVE-SYMBOL SYMBOL) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&class_to_native_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-STRUCT-CONSTRUCTOR-NAME", "CLASS", "(DEFUN (YIELD-STRUCT-CONSTRUCTOR-NAME OBJECT) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_struct_constructor_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-MAKE-TREE", "CONS", "(DEFUN (CL-TRANSLATE-MAKE-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_make_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-NEW-TREE", "CONS", "(DEFUN (CL-TRANSLATE-NEW-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_new_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-OPERATOR-TREE", "CONS", "(DEFUN (CL-TRANSLATE-OPERATOR-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_operator_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-FORMAT-ARGUMENTS", "CONS", "(DEFUN (YIELD-FORMAT-ARGUMENTS CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&yield_format_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-PRINT-TREE", "CONS", "(DEFUN (YIELD-PRINT-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&yield_print_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-PRINT-STREAM-TREE", "CONS", "(DEFUN (CL-TRANSLATE-PRINT-STREAM-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_print_stream_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-CALL-FUNCTION-CODE-TREE", "CONS", "(DEFUN (CL-TRANSLATE-CALL-FUNCTION-CODE-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_call_function_code_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-THE-CODE-TREE", "CONS", "(DEFUN (CL-TRANSLATE-THE-CODE-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_the_code_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-VERBATIM-TREE", "CONS", "(DEFUN (CL-TRANSLATE-VERBATIM-TREE OBJECT) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_verbatim_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-INLINE-TREE", "CONS", "(DEFUN (CL-TRANSLATE-INLINE-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&cl_translate_inline_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-UNIT", "TRANSLATION-UNIT", "(DEFUN (CL-TRANSLATE-UNIT OBJECT) ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&cl_translate_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-METHOD-PARAMETERS", "METHOD-SLOT", "(DEFUN (CL-TRANSLATE-METHOD-PARAMETERS CONS) ((METHOD METHOD-SLOT)))");

              method->function_code = ((cpp_function_code)(&cl_translate_method_parameters));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-DEFINE-METHOD-UNIT", "TRANSLATION-UNIT", "(DEFUN (CL-TRANSLATE-DEFINE-METHOD-UNIT CONS) ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&cl_translate_define_method_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CLOS-SLOT-TREE", "STORAGE-SLOT", "(DEFUN (YIELD-CLOS-SLOT-TREE CONS) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_clos_slot_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-CLOS-CLASS-TREE", "CLASS", "(DEFUN (YIELD-CLOS-CLASS-TREE CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_clos_class_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-CL-STRUCT-SLOTS", "CLASS", "(DEFUN (COMPUTE-CL-STRUCT-SLOTS (LIST OF STORAGE-SLOT)) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&compute_cl_struct_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-STRUCT-SLOTS", "CLASS", "(DEFUN (CL-STRUCT-SLOTS (LIST OF STORAGE-SLOT)) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&cl_struct_slots));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-STRUCT-SLOT-OFFSET", "SYMBOL", "(DEFUN (CL-STRUCT-SLOT-OFFSET INTEGER) ((SLOTNAME SYMBOL) (CLASSTYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&cl_struct_slot_offset));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-STRUCT-SLOT-TREES", "CLASS", "(DEFUN (YIELD-STRUCT-SLOT-TREES CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_struct_slot_trees));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-STRUCT-TREE", "CLASS", "(DEFUN (YIELD-STRUCT-TREE CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_struct_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-VECTOR-STRUCT-NAME", "CLASS", "(DEFUN (YIELD-VECTOR-STRUCT-NAME OBJECT) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_vector_struct_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-VECTOR-STRUCT-TREE", "CLASS", "(DEFUN (YIELD-VECTOR-STRUCT-TREE CONS) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&yield_vector_struct_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-DEFINE-NATIVE-CLASS-UNIT", "TRANSLATION-UNIT", "(DEFUN (CL-TRANSLATE-DEFINE-NATIVE-CLASS-UNIT CONS) ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&cl_translate_define_native_class_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-DEFINE-GLOBAL-VARIABLE-UNIT", "TRANSLATION-UNIT", "(DEFUN (CL-TRANSLATE-DEFINE-GLOBAL-VARIABLE-UNIT CONS) ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&cl_translate_define_global_variable_unit));
            }
            { Method_Slot* method = define_method_from_stringified_source("CL-TRANSLATE-DEFPRINT-UNIT", "TRANSLATION-UNIT", "(DEFUN (CL-TRANSLATE-DEFPRINT-UNIT CONS) ((UNIT TRANSLATION-UNIT)))");

              method->function_code = ((cpp_function_code)(&cl_translate_defprint_unit));
            }
            define_method_from_stringified_source("STARTUP-CL-TRANSLATE", NULL, "(DEFUN STARTUP-CL-TRANSLATE ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CL-OPERATOR-TABLE* KEY-VALUE-LIST NULL :DOCUMENTATION \"Mapping from STELLA operators to Common-Lisp operators.\")");
            oCL_OPERATOR_TABLEo = ((Key_Value_List*)(dictionary(SGT_CL_TRANSLATE_KEY_VALUE_LIST, 22, SYM_CL_TRANSLATE_i, intern_common_lisp_symbol("+"), SYM_CL_TRANSLATE__, intern_common_lisp_symbol("-"), SYM_CL_TRANSLATE_o, intern_common_lisp_symbol("*"), SYM_CL_TRANSLATE_s, intern_common_lisp_symbol("/"), SYM_CL_TRANSLATE_EQp, intern_common_lisp_symbol("EQL"), SYM_CL_TRANSLATE_l, intern_common_lisp_symbol("<"), SYM_CL_TRANSLATE_le, intern_common_lisp_symbol("<="), SYM_CL_TRANSLATE_ge, intern_common_lisp_symbol(">="), SYM_CL_TRANSLATE_g, intern_common_lisp_symbol(">"), SYM_CL_TRANSLATE_e, intern_common_lisp_symbol("="), SYM_CL_TRANSLATE_xse, intern_common_lisp_symbol("/="))));
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

