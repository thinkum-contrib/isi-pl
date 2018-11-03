// macros.cc

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

Symbol* SYM_MACROS_SETQ = NULL;

Symbol* SYM_MACROS_CONS = NULL;

Symbol* SYM_MACROS_PUSHQ = NULL;

Symbol* SYM_MACROS_PUSHQ_EXPANDER = NULL;

Symbol* SYM_MACROS_VRLET = NULL;

Symbol* SYM_MACROS_VALUE = NULL;

Symbol* SYM_MACROS_REST = NULL;

Symbol* SYM_MACROS_POPQ = NULL;

Symbol* SYM_MACROS_POPQ_EXPANDER = NULL;

Symbol* SYM_MACROS_SETF = NULL;

Symbol* SYM_MACROS_PUSHF = NULL;

Symbol* SYM_MACROS_PUSHF_EXPANDER = NULL;

Symbol* SYM_MACROS_UNSTRINGIFY = NULL;

Symbol* SYM_MACROS_STRING_QUOTE = NULL;

Symbol* SYM_MACROS_STRING_QUOTE_EXPANDER = NULL;

Symbol* SYM_MACROS_i = NULL;

Symbol* SYM_MACROS_ii = NULL;

Symbol* SYM_MACROS_ii_EXPANDER = NULL;

Symbol* SYM_MACROS__ = NULL;

Symbol* SYM_MACROS___ = NULL;

Symbol* SYM_MACROS____EXPANDER = NULL;

Symbol* SYM_MACROS_1i = NULL;

Symbol* SYM_MACROS_1i_EXPANDER = NULL;

Symbol* SYM_MACROS_1_ = NULL;

Symbol* SYM_MACROS_1__EXPANDER = NULL;

Symbol* SYM_MACROS_DEFINEDp = NULL;

Symbol* SYM_MACROS_SETQp = NULL;

Symbol* SYM_MACROS_SETQp_EXPANDER = NULL;

Symbol* SYM_MACROS_SPECIAL = NULL;

Symbol* SYM_MACROS_oTRANSIENTOBJECTSpo = NULL;

Symbol* SYM_MACROS_FALSE = NULL;

Symbol* SYM_MACROS_WITH_PERMANENT_OBJECTS = NULL;

Symbol* SYM_MACROS_WITH_PERMANENT_OBJECTS_EXPANDER = NULL;

Symbol* SYM_MACROS_TRUE = NULL;

Symbol* SYM_MACROS_WITH_TRANSIENT_OBJECTS = NULL;

Symbol* SYM_MACROS_WITH_TRANSIENT_OBJECTS_EXPANDER = NULL;

Symbol* SYM_MACROS_IGNORE = NULL;

Symbol* SYM_MACROS_IGNORE_EXPANDER = NULL;

Symbol* SYM_MACROS_CHOOSE = NULL;

Symbol* SYM_MACROS_NULL = NULL;

Symbol* SYM_MACROS_ONLY_IF = NULL;

Symbol* SYM_MACROS_ONLY_IF_EXPANDER = NULL;

Symbol* SYM_MACROS_PHASE_TO_INTEGER = NULL;

Symbol* SYM_MACROS_PHASE_TO_INTEGER_EXPANDER = NULL;

Symbol* SYM_MACROS_IF_OUTPUT_LANGUAGE = NULL;

Symbol* SYM_MACROS_IF_OUTPUT_LANGUAGE_EXPANDER = NULL;

Symbol* SYM_MACROS_oCONTEXTo = NULL;

Symbol* SYM_MACROS_SAFETY = NULL;

Symbol* SYM_MACROS_EQLp = NULL;

Symbol* SYM_MACROS_BASE_MODULE = NULL;

Symbol* SYM_MACROS_CAST = NULL;

Symbol* SYM_MACROS_WORLD = NULL;

Symbol* SYM_MACROS_oMODULEo = NULL;

Symbol* SYM_MACROS_WITHIN_WORLD = NULL;

Symbol* SYM_MACROS_WITHIN_WORLD_EXPANDER = NULL;

Symbol* SYM_MACROS_LET = NULL;

Symbol* SYM_MACROS_WITHIN_MODULE = NULL;

Symbol* SYM_MACROS_WITHIN_MODULE_EXPANDER = NULL;

Symbol* SYM_MACROS_IN = NULL;

Symbol* SYM_MACROS_AS = NULL;

Symbol* SYM_MACROS_COMMA = NULL;

Object* pushq_expander(Cons* variable, Object* value) {
  // Push 'value' onto the cons list 'variable'.
  return (listO(3, SYM_MACROS_SETQ, variable, cons(listO(3, SYM_MACROS_CONS, value, cons(variable, NIL)), NIL)));
}

Object* popq_expander(Cons* variable) {
  // Pops a value from the cons list 'variable'.
  { Symbol* valuevar = local_gensym("CONS");

    return (listO(5, SYM_MACROS_VRLET, cons(cons(valuevar, cons(listO(3, SYM_MACROS_VALUE, variable, NIL), NIL)), NIL), listO(3, SYM_MACROS_SETQ, variable, cons(listO(3, SYM_MACROS_REST, variable, NIL), NIL)), valuevar, NIL));
  }
}

Object* pushf_expander(Cons* place, Object* value) {
  // Push 'value' onto the cons list 'place'.
  { Cons* placecopy = ((Cons*)(copy_cons_tree(place)));

    return (listO(3, SYM_MACROS_SETF, place, cons(listO(3, SYM_MACROS_CONS, value, cons(placecopy, NIL)), NIL)));
  }
}

Object* string_quote_expander(Object* tree) {
  // Return a parse tree that evaluates to 'tree' at
  // run-time.  'tree' is encoded as a string within the parse tree.
  return (listO(3, SYM_MACROS_UNSTRINGIFY, string_wrap_literal(stringify(tree)), NIL));
}

Object* II_expander(Object* place) {
  // Increment the value of 'place' and return the result.
  return ((symbolP(place) ? ((Cons*)(listO(3, SYM_MACROS_SETQ, place, cons(listO(3, SYM_MACROS_i, place, cons(integer_wrap_literal(1), NIL)), NIL)))) : ((Cons*)(listO(3, SYM_MACROS_SETF, place, cons(listO(3, SYM_MACROS_i, copy_cons_tree(place), cons(integer_wrap_literal(1), NIL)), NIL))))));
}

Object* ___expander(Object* place) {
  // Decrement the value of 'place' and return the result.
  return ((symbolP(place) ? ((Cons*)(listO(3, SYM_MACROS_SETQ, place, cons(listO(3, SYM_MACROS__, place, cons(integer_wrap_literal(1), NIL)), NIL)))) : ((Cons*)(listO(3, SYM_MACROS_SETF, place, cons(listO(3, SYM_MACROS__, copy_cons_tree(place), cons(integer_wrap_literal(1), NIL)), NIL))))));
}

Object* oneI_expander(Object* expression) {
  // Add 1 to 'expression' and return the result.
  return (listO(3, SYM_MACROS_i, expression, cons(integer_wrap_literal(1), NIL)));
}

Object* one__expander(Object* expression) {
  // Subtract 1 from 'expression' and return the result.
  return (listO(3, SYM_MACROS__, expression, cons(integer_wrap_literal(1), NIL)));
}

Object* setqP_expander(Symbol* variable, Cons* expression) {
  // Assign 'variable' the result of evaluating 'expression', 
  // and return TRUE if 'expression' is not NULL else return FALSE.
  return (listO(5, SYM_MACROS_VRLET, NIL, listO(3, SYM_MACROS_SETQ, variable, cons(expression, NIL)), listO(3, SYM_MACROS_DEFINEDp, variable, NIL), NIL));
}

Object* with_permanent_objects_expander(Cons* body) {
  // Allocate 'permanent' (as opposed to 'transient')
  // objects within the scope of this declaration.
  return (listO(3, SYM_MACROS_SPECIAL, cons(listO(3, SYM_MACROS_oTRANSIENTOBJECTSpo, SYM_MACROS_FALSE, NIL), NIL), body->concatenate(NIL)));
}

Object* with_transient_objects_expander(Cons* body) {
  // Allocate 'transient' (as opposed to 'permanent')
  // objects within the scope of this declaration.
  return (listO(3, SYM_MACROS_SPECIAL, cons(listO(3, SYM_MACROS_oTRANSIENTOBJECTSpo, SYM_MACROS_TRUE, NIL), NIL), body->concatenate(NIL)));
}

Object* ignore_expander(Cons* variables) {
  // Ignore unused 'variables' with NoOp 'setq' statements.
  { Cons* ignoretrees = NIL;

    { Object* variable = NULL;
      Cons* iter_001 = variables;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          variable = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(listO(3, SYM_MACROS_SETQ, variable, cons(variable, NIL)), NIL);
            if (nilP(ignoretrees)) {
              ignoretrees = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(ignoretrees, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(listO(3, SYM_MACROS_SETQ, variable, cons(variable, NIL)), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    return (prognify(ignoretrees));
  }
}

Object* only_if_expander(Object* test, Object* expression) {
  // If 'test' is TRUE, return the result of evaluating 
  // 'expression'.
  return (listO(3, SYM_MACROS_CHOOSE, test, cons(expression, cons(SYM_MACROS_NULL, NIL))));
}

Object* phase_to_integer_expander(Keyword* startuptimephase) {
  // Expands into the integer representing 'startupTimePhase'.
  return (integer_wrap_literal(encode_startup_time_phase(startuptimephase)));
}

Object* if_output_language_expander(Keyword* language, Object* thenform, Object* elseform) {
  // Expand to 'thenForm' if the current translator output
  // language equals 'language'.  Otherwise, expand to 'elseForm'.  This can
  // be used to conditionally translate Stella code.
  if (language == translator_output_language()) {
    return (((thenform == SYM_MACROS_NULL) ? ((Object*)(NULL)) : ((Object*)(thenform))));
  }
  else {
    return (((elseform == SYM_MACROS_NULL) ? ((Object*)(NULL)) : ((Object*)(elseform))));
  }
}

Object* within_world_expander(Object* worldform, Cons* body) {
  // Execute `body' within the world resulting from `worldForm'.
  return (listO(4, SYM_MACROS_SPECIAL, cons(listO(3, SYM_MACROS_oCONTEXTo, worldform, NIL), NIL), listO(7, SYM_MACROS_SAFETY, integer_wrap_literal(3), listO(4, SYM_MACROS_EQLp, listO(3, SYM_MACROS_BASE_MODULE, listO(4, SYM_MACROS_CAST, SYM_MACROS_oCONTEXTo, SYM_MACROS_WORLD, NIL), NIL), SYM_MACROS_oMODULEo, NIL), string_wrap_literal("within-world: world "), SYM_MACROS_oCONTEXTo, string_wrap_literal(" does not have a base module"), NIL), body->concatenate(NIL)));
}

Object* within_module_expander(Object* moduleform, Cons* body) {
  // Execute `body' within the module resulting from `moduleForm'.
  // `*module*' is an acceptable `moduleForm'.  It will locally rebind 
  // `*module*' and `*context*' and shield the outer bindings from changes.
  if (moduleform == SYM_MACROS_oMODULEo) {
    { Symbol* tempvar = local_gensym("MODULE");

      return (listO(4, SYM_MACROS_LET, cons(cons(tempvar, cons(SYM_MACROS_oMODULEo, NIL)), NIL), listO(3, SYM_MACROS_SPECIAL, listO(3, listO(3, SYM_MACROS_oMODULEo, tempvar, NIL), listO(3, SYM_MACROS_oCONTEXTo, SYM_MACROS_oMODULEo, NIL), NIL), body->concatenate(NIL)), NIL));
    }
  }
  else {
    return (listO(3, SYM_MACROS_SPECIAL, listO(3, listO(3, SYM_MACROS_oMODULEo, moduleform, NIL), listO(3, SYM_MACROS_oCONTEXTo, SYM_MACROS_oMODULEo, NIL), NIL), body->concatenate(NIL)));
  }
}

Cons* extract_output_expressions_from_select(Cons* selectbody) {
  { Cons* outputs = NULL;
    Cons* tail = selectbody;

    while (tail != NULL) {
      if (get_quoted_tree("((WHERE FROM) \"/STELLA\")", "/STELLA")->memberP(tail->value)) {
        break;
      }
      outputs = cons(tail->value, outputs);
      tail = tail->rest;
      { Object* test_value_001 = tail->first();

        if (test_value_001 == SYM_MACROS_IN) {
          tail = tail->rest->rest;
        }
        else if ((test_value_001 == SYM_MACROS_AS) ||
            (test_value_001 == SYM_MACROS_COMMA)) {
          tail = tail->rest;
        }
        else {
        }
      }
    }
    return (outputs->reverse());
  }
}

void startup_macros() {
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
            SYM_MACROS_SETQ = ((Symbol*)(intern_rigid_symbol_wrt_module("SETQ", NULL, 0)));
            SYM_MACROS_CONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CONS", NULL, 0)));
            SYM_MACROS_PUSHQ = ((Symbol*)(intern_rigid_symbol_wrt_module("PUSHQ", NULL, 0)));
            SYM_MACROS_PUSHQ_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("PUSHQ-EXPANDER", NULL, 0)));
            SYM_MACROS_VRLET = ((Symbol*)(intern_rigid_symbol_wrt_module("VRLET", NULL, 0)));
            SYM_MACROS_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE", NULL, 0)));
            SYM_MACROS_REST = ((Symbol*)(intern_rigid_symbol_wrt_module("REST", NULL, 0)));
            SYM_MACROS_POPQ = ((Symbol*)(intern_rigid_symbol_wrt_module("POPQ", NULL, 0)));
            SYM_MACROS_POPQ_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("POPQ-EXPANDER", NULL, 0)));
            SYM_MACROS_SETF = ((Symbol*)(intern_rigid_symbol_wrt_module("SETF", NULL, 0)));
            SYM_MACROS_PUSHF = ((Symbol*)(intern_rigid_symbol_wrt_module("PUSHF", NULL, 0)));
            SYM_MACROS_PUSHF_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("PUSHF-EXPANDER", NULL, 0)));
            SYM_MACROS_UNSTRINGIFY = ((Symbol*)(intern_rigid_symbol_wrt_module("UNSTRINGIFY", NULL, 0)));
            SYM_MACROS_STRING_QUOTE = ((Symbol*)(intern_rigid_symbol_wrt_module("STRING-QUOTE", NULL, 0)));
            SYM_MACROS_STRING_QUOTE_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("STRING-QUOTE-EXPANDER", NULL, 0)));
            SYM_MACROS_i = ((Symbol*)(intern_rigid_symbol_wrt_module("+", NULL, 0)));
            SYM_MACROS_ii = ((Symbol*)(intern_rigid_symbol_wrt_module("++", NULL, 0)));
            SYM_MACROS_ii_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("++-EXPANDER", NULL, 0)));
            SYM_MACROS__ = ((Symbol*)(intern_rigid_symbol_wrt_module("-", NULL, 0)));
            SYM_MACROS___ = ((Symbol*)(intern_rigid_symbol_wrt_module("--", NULL, 0)));
            SYM_MACROS____EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("---EXPANDER", NULL, 0)));
            SYM_MACROS_1i = ((Symbol*)(intern_rigid_symbol_wrt_module("1+", NULL, 0)));
            SYM_MACROS_1i_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("1+-EXPANDER", NULL, 0)));
            SYM_MACROS_1_ = ((Symbol*)(intern_rigid_symbol_wrt_module("1-", NULL, 0)));
            SYM_MACROS_1__EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("1--EXPANDER", NULL, 0)));
            SYM_MACROS_DEFINEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINED?", NULL, 0)));
            SYM_MACROS_SETQp = ((Symbol*)(intern_rigid_symbol_wrt_module("SETQ?", NULL, 0)));
            SYM_MACROS_SETQp_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("SETQ?-EXPANDER", NULL, 0)));
            SYM_MACROS_SPECIAL = ((Symbol*)(intern_rigid_symbol_wrt_module("SPECIAL", NULL, 0)));
            SYM_MACROS_oTRANSIENTOBJECTSpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TRANSIENTOBJECTS?*", NULL, 0)));
            SYM_MACROS_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", NULL, 0)));
            SYM_MACROS_WITH_PERMANENT_OBJECTS = ((Symbol*)(intern_rigid_symbol_wrt_module("WITH-PERMANENT-OBJECTS", NULL, 0)));
            SYM_MACROS_WITH_PERMANENT_OBJECTS_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("WITH-PERMANENT-OBJECTS-EXPANDER", NULL, 0)));
            SYM_MACROS_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            SYM_MACROS_WITH_TRANSIENT_OBJECTS = ((Symbol*)(intern_rigid_symbol_wrt_module("WITH-TRANSIENT-OBJECTS", NULL, 0)));
            SYM_MACROS_WITH_TRANSIENT_OBJECTS_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("WITH-TRANSIENT-OBJECTS-EXPANDER", NULL, 0)));
            SYM_MACROS_IGNORE = ((Symbol*)(intern_rigid_symbol_wrt_module("IGNORE", NULL, 0)));
            SYM_MACROS_IGNORE_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("IGNORE-EXPANDER", NULL, 0)));
            SYM_MACROS_CHOOSE = ((Symbol*)(intern_rigid_symbol_wrt_module("CHOOSE", NULL, 0)));
            SYM_MACROS_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", NULL, 0)));
            SYM_MACROS_ONLY_IF = ((Symbol*)(intern_rigid_symbol_wrt_module("ONLY-IF", NULL, 0)));
            SYM_MACROS_ONLY_IF_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("ONLY-IF-EXPANDER", NULL, 0)));
            SYM_MACROS_PHASE_TO_INTEGER = ((Symbol*)(intern_rigid_symbol_wrt_module("PHASE-TO-INTEGER", NULL, 0)));
            SYM_MACROS_PHASE_TO_INTEGER_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("PHASE-TO-INTEGER-EXPANDER", NULL, 0)));
            SYM_MACROS_IF_OUTPUT_LANGUAGE = ((Symbol*)(intern_rigid_symbol_wrt_module("IF-OUTPUT-LANGUAGE", NULL, 0)));
            SYM_MACROS_IF_OUTPUT_LANGUAGE_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("IF-OUTPUT-LANGUAGE-EXPANDER", NULL, 0)));
            SYM_MACROS_oCONTEXTo = ((Symbol*)(intern_rigid_symbol_wrt_module("*CONTEXT*", NULL, 0)));
            SYM_MACROS_SAFETY = ((Symbol*)(intern_rigid_symbol_wrt_module("SAFETY", NULL, 0)));
            SYM_MACROS_EQLp = ((Symbol*)(intern_rigid_symbol_wrt_module("EQL?", NULL, 0)));
            SYM_MACROS_BASE_MODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("BASE-MODULE", NULL, 0)));
            SYM_MACROS_CAST = ((Symbol*)(intern_rigid_symbol_wrt_module("CAST", NULL, 0)));
            SYM_MACROS_WORLD = ((Symbol*)(intern_rigid_symbol_wrt_module("WORLD", NULL, 0)));
            SYM_MACROS_oMODULEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*MODULE*", NULL, 0)));
            SYM_MACROS_WITHIN_WORLD = ((Symbol*)(intern_rigid_symbol_wrt_module("WITHIN-WORLD", NULL, 0)));
            SYM_MACROS_WITHIN_WORLD_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("WITHIN-WORLD-EXPANDER", NULL, 0)));
            SYM_MACROS_LET = ((Symbol*)(intern_rigid_symbol_wrt_module("LET", NULL, 0)));
            SYM_MACROS_WITHIN_MODULE = ((Symbol*)(intern_rigid_symbol_wrt_module("WITHIN-MODULE", NULL, 0)));
            SYM_MACROS_WITHIN_MODULE_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("WITHIN-MODULE-EXPANDER", NULL, 0)));
            SYM_MACROS_IN = ((Symbol*)(intern_rigid_symbol_wrt_module("IN", NULL, 0)));
            SYM_MACROS_AS = ((Symbol*)(intern_rigid_symbol_wrt_module("AS", NULL, 0)));
            SYM_MACROS_COMMA = ((Symbol*)(intern_rigid_symbol_wrt_module("COMMA", NULL, 0)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("PUSHQ-EXPANDER", "CONS", "(DEFUN (PUSHQ-EXPANDER OBJECT) ((VARIABLE CONS) (VALUE OBJECT)) :DOCUMENTATION \"Push 'value' onto the cons list 'variable'.\")");

              method->function_code = ((cpp_function_code)(&pushq_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("POPQ-EXPANDER", "CONS", "(DEFUN (POPQ-EXPANDER OBJECT) ((VARIABLE CONS)) :DOCUMENTATION \"Pops a value from the cons list 'variable'.\")");

              method->function_code = ((cpp_function_code)(&popq_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUSHF-EXPANDER", "CONS", "(DEFUN (PUSHF-EXPANDER OBJECT) ((PLACE CONS) (VALUE OBJECT)) :DOCUMENTATION \"Push 'value' onto the cons list 'place'.\")");

              method->function_code = ((cpp_function_code)(&pushf_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRING-QUOTE-EXPANDER", "OBJECT", "(DEFUN (STRING-QUOTE-EXPANDER OBJECT) ((TREE OBJECT)) :DOCUMENTATION \"Return a parse tree that evaluates to 'tree' at\nrun-time.  'tree' is encoded as a string within the parse tree.\")");

              method->function_code = ((cpp_function_code)(&string_quote_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("++-EXPANDER", "OBJECT", "(DEFUN (++-EXPANDER OBJECT) ((PLACE OBJECT)) :DOCUMENTATION \"Increment the value of 'place' and return the result.\")");

              method->function_code = ((cpp_function_code)(&II_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("---EXPANDER", "OBJECT", "(DEFUN (---EXPANDER OBJECT) ((PLACE OBJECT)) :DOCUMENTATION \"Decrement the value of 'place' and return the result.\")");

              method->function_code = ((cpp_function_code)(&___expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("1+-EXPANDER", "OBJECT", "(DEFUN (1+-EXPANDER OBJECT) ((EXPRESSION OBJECT)) :DOCUMENTATION \"Add 1 to 'expression' and return the result.\")");

              method->function_code = ((cpp_function_code)(&oneI_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("1--EXPANDER", "OBJECT", "(DEFUN (1--EXPANDER OBJECT) ((EXPRESSION OBJECT)) :DOCUMENTATION \"Subtract 1 from 'expression' and return the result.\")");

              method->function_code = ((cpp_function_code)(&one__expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("SETQ?-EXPANDER", "SYMBOL", "(DEFUN (SETQ?-EXPANDER OBJECT) ((VARIABLE SYMBOL) (EXPRESSION CONS)) :DOCUMENTATION \"Assign 'variable' the result of evaluating 'expression', \nand return TRUE if 'expression' is not NULL else return FALSE.\")");

              method->function_code = ((cpp_function_code)(&setqP_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("WITH-PERMANENT-OBJECTS-EXPANDER", "CONS", "(DEFUN (WITH-PERMANENT-OBJECTS-EXPANDER OBJECT) (|&BODY| (BODY CONS)) :DOCUMENTATION \"Allocate 'permanent' (as opposed to 'transient')\nobjects within the scope of this declaration.\")");

              method->function_code = ((cpp_function_code)(&with_permanent_objects_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("WITH-TRANSIENT-OBJECTS-EXPANDER", "CONS", "(DEFUN (WITH-TRANSIENT-OBJECTS-EXPANDER OBJECT) (|&BODY| (BODY CONS)) :DOCUMENTATION \"Allocate 'transient' (as opposed to 'permanent')\nobjects within the scope of this declaration.\")");

              method->function_code = ((cpp_function_code)(&with_transient_objects_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("IGNORE-EXPANDER", "CONS", "(DEFUN (IGNORE-EXPANDER OBJECT) (|&BODY| (VARIABLES CONS)) :DOCUMENTATION \"Ignore unused 'variables' with NoOp 'setq' statements.\")");

              method->function_code = ((cpp_function_code)(&ignore_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("ONLY-IF-EXPANDER", "OBJECT", "(DEFUN (ONLY-IF-EXPANDER OBJECT) ((TEST OBJECT) (EXPRESSION OBJECT)) :DOCUMENTATION \"If 'test' is TRUE, return the result of evaluating \n'expression'.\")");

              method->function_code = ((cpp_function_code)(&only_if_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("PHASE-TO-INTEGER-EXPANDER", "KEYWORD", "(DEFUN (PHASE-TO-INTEGER-EXPANDER OBJECT) ((STARTUPTIMEPHASE KEYWORD)) :DOCUMENTATION \"Expands into the integer representing 'startupTimePhase'.\")");

              method->function_code = ((cpp_function_code)(&phase_to_integer_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("IF-OUTPUT-LANGUAGE-EXPANDER", "KEYWORD", "(DEFUN (IF-OUTPUT-LANGUAGE-EXPANDER OBJECT) ((LANGUAGE KEYWORD) (THENFORM OBJECT) (ELSEFORM OBJECT)) :DOCUMENTATION \"Expand to 'thenForm' if the current translator output\nlanguage equals 'language'.  Otherwise, expand to 'elseForm'.  This can\nbe used to conditionally translate Stella code.\")");

              method->function_code = ((cpp_function_code)(&if_output_language_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("WITHIN-WORLD-EXPANDER", "OBJECT", "(DEFUN (WITHIN-WORLD-EXPANDER OBJECT) ((WORLDFORM OBJECT) |&BODY| (BODY CONS)) :DOCUMENTATION \"Execute `body' within the world resulting from `worldForm'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&within_world_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("WITHIN-MODULE-EXPANDER", "OBJECT", "(DEFUN (WITHIN-MODULE-EXPANDER OBJECT) ((MODULEFORM OBJECT) |&BODY| (BODY CONS)) :DOCUMENTATION \"Execute `body' within the module resulting from `moduleForm'.\n`*module*' is an acceptable `moduleForm'.  It will locally rebind \n`*module*' and `*context*' and shield the outer bindings from changes.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&within_module_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-OUTPUT-EXPRESSIONS-FROM-SELECT", "CONS", "(DEFUN (EXTRACT-OUTPUT-EXPRESSIONS-FROM-SELECT CONS) ((SELECTBODY CONS)))");

              method->function_code = ((cpp_function_code)(&extract_output_expressions_from_select));
            }
            define_method_from_stringified_source("STARTUP-MACROS", NULL, "(DEFUN STARTUP-MACROS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            store_macro(SYM_MACROS_PUSHQ, SYM_MACROS_PUSHQ_EXPANDER, ((cpp_function_code)(&pushq_expander)));
            store_macro(SYM_MACROS_POPQ, SYM_MACROS_POPQ_EXPANDER, ((cpp_function_code)(&popq_expander)));
            store_macro(SYM_MACROS_PUSHF, SYM_MACROS_PUSHF_EXPANDER, ((cpp_function_code)(&pushf_expander)));
            store_macro(SYM_MACROS_STRING_QUOTE, SYM_MACROS_STRING_QUOTE_EXPANDER, ((cpp_function_code)(&string_quote_expander)));
            store_macro(SYM_MACROS_ii, SYM_MACROS_ii_EXPANDER, ((cpp_function_code)(&II_expander)));
            store_macro(SYM_MACROS___, SYM_MACROS____EXPANDER, ((cpp_function_code)(&___expander)));
            store_macro(SYM_MACROS_1i, SYM_MACROS_1i_EXPANDER, ((cpp_function_code)(&oneI_expander)));
            store_macro(SYM_MACROS_1_, SYM_MACROS_1__EXPANDER, ((cpp_function_code)(&one__expander)));
            store_macro(SYM_MACROS_SETQp, SYM_MACROS_SETQp_EXPANDER, ((cpp_function_code)(&setqP_expander)));
            store_macro(SYM_MACROS_WITH_PERMANENT_OBJECTS, SYM_MACROS_WITH_PERMANENT_OBJECTS_EXPANDER, ((cpp_function_code)(&with_permanent_objects_expander)));
            store_macro(SYM_MACROS_WITH_TRANSIENT_OBJECTS, SYM_MACROS_WITH_TRANSIENT_OBJECTS_EXPANDER, ((cpp_function_code)(&with_transient_objects_expander)));
            store_macro(SYM_MACROS_IGNORE, SYM_MACROS_IGNORE_EXPANDER, ((cpp_function_code)(&ignore_expander)));
            store_macro(SYM_MACROS_ONLY_IF, SYM_MACROS_ONLY_IF_EXPANDER, ((cpp_function_code)(&only_if_expander)));
            store_macro(SYM_MACROS_PHASE_TO_INTEGER, SYM_MACROS_PHASE_TO_INTEGER_EXPANDER, ((cpp_function_code)(&phase_to_integer_expander)));
            store_macro(SYM_MACROS_IF_OUTPUT_LANGUAGE, SYM_MACROS_IF_OUTPUT_LANGUAGE_EXPANDER, ((cpp_function_code)(&if_output_language_expander)));
            store_macro(SYM_MACROS_WITHIN_WORLD, SYM_MACROS_WITHIN_WORLD_EXPANDER, ((cpp_function_code)(&within_world_expander)));
            store_macro(SYM_MACROS_WITHIN_MODULE, SYM_MACROS_WITHIN_MODULE_EXPANDER, ((cpp_function_code)(&within_module_expander)));
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

