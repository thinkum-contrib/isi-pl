// caches.cc

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997                   | 
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

Keyword* KWD_CACHES_STRICT = NULL;

Symbol* SYM_CACHES_STRICT_INFERENCE_CACHE = NULL;

Keyword* KWD_CACHES_DEFAULT = NULL;

Symbol* SYM_CACHES_DEFAULT_INFERENCE_CACHE = NULL;

Symbol* SYM_CACHES_MONOTONICp = NULL;

Symbol* SYM_CACHES_UP_TO_DATE_INFERENCESp = NULL;

Surrogate* SGT_CACHES_CLASH = NULL;

Symbol* SYM_CACHES_EVALUATOR_WRAPPER_CODE = NULL;

Surrogate* SGT_CACHES_MODULE = NULL;

Surrogate* SGT_CACHES_WORLD = NULL;

World* lookup_inference_cache(Module* module, Keyword* kind) {
  if (kind == KWD_CACHES_STRICT) {
    return (((World*)(dynamic_slot_value(module, SYM_CACHES_STRICT_INFERENCE_CACHE, NULL))));
  }
  else if (kind == KWD_CACHES_DEFAULT) {
    return (((World*)(dynamic_slot_value(module, SYM_CACHES_DEFAULT_INFERENCE_CACHE, NULL))));
  }
  else {
    cerr << "`" << kind << "'" << " is not a valid case option";
  }
}

World* create_inference_cache(Module* module, Keyword* kind) {
  { World* world = NULL;

    if (kind == KWD_CACHES_STRICT) {
      world = create_world(module, NULL);
      set_dynamic_slot_value(world, SYM_CACHES_MONOTONICp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
      set_dynamic_slot_value(module, SYM_CACHES_STRICT_INFERENCE_CACHE, world, NULL);
      set_dynamic_slot_value(world, SYM_CACHES_UP_TO_DATE_INFERENCESp, wrap_boolean(!all_propositions(module, TRUE)->nextP()), NULL_BOOLEAN_WRAPPER);
    }
    else if (kind == KWD_CACHES_DEFAULT) {
      world = create_world(get_inference_cache(module, KWD_CACHES_STRICT), NULL);
      set_dynamic_slot_value(module, SYM_CACHES_DEFAULT_INFERENCE_CACHE, world, NULL);
    }
    else {
      cerr << "`" << kind << "'" << " is not a valid case option";
    }
    return (world);
  }
}

World* get_inference_cache(Module* module, Keyword* kind) {
  { World* world = lookup_inference_cache(module, kind);

    if (world != NULL) {
      return (world);
    }
    world = create_inference_cache(module, kind);
    { Module* parentmodule = NULL;
      Cons* iter_001 = module->parent_modules->the_cons_list;

      while (!nilP(iter_001)) {
        {
          parentmodule = ((Module*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        inherit_cached_inferences(lookup_inference_cache(parentmodule, kind), world);
      }
    }
    return (world);
  }
}

void destroy_inference_cache(World* world) {
  destroy_world(world);
}

void check_for_out_of_date_inference_cache() {
  if (oMODULEo == oCONTEXTo) {
    { World* cache = ((World*)(dynamic_slot_value(oMODULEo, SYM_CACHES_STRICT_INFERENCE_CACHE, NULL)));

      if ((cache != NULL) &&
          cache->monotonicP_reader()) {
        destroy_inference_cache(cache);
        set_dynamic_slot_value(oMODULEo, SYM_CACHES_STRICT_INFERENCE_CACHE, NULL, NULL);
      }
    }
    return;
  }
  { World* world = ((World*)(oCONTEXTo));

    if (world->truth_maintainedP_reader()) {
    }
    else if (world->monotonicP_reader()) {
      cerr << "Retraction occurred in world " << "`" << world << "'" << " which is marked monotonic.";
    }
    else {
      set_dynamic_slot_value(world, SYM_CACHES_UP_TO_DATE_INFERENCESp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
    }
  }
}

Context* get_query_context() {
  if (!(oMODULEo == oCONTEXTo)) {
    return (oCONTEXTo);
  }
  { World* cache = ((World*)(dynamic_slot_value(oMODULEo, SYM_CACHES_STRICT_INFERENCE_CACHE, NULL)));

    if (cache != NULL) {
      return (cache);
    }
    else {
      return (oMODULEo);
    }
  }
}

Context* get_top_level_update_context() {
  if (oCONTEXTo == dynamic_slot_value(oMODULEo, SYM_CACHES_STRICT_INFERENCE_CACHE, NULL)) {
    return (oMODULEo);
  }
  else {
    return (oCONTEXTo);
  }
}

World* Context::get_constraint_propagation_world() {
  { Context* self = this;

    return (((World*)(self)));
  }
}

World* Module::get_constraint_propagation_world() {
  { Module* self = this;

    return (get_inference_cache(self, KWD_CACHES_STRICT));
  }
}

void inherit_cached_inferences(World* fromworld, World* toworld) {
  toworld = toworld;
  if (fromworld == NULL) {
    return;
  }
}

void inherit_truth_value_update(Proposition* proposition, World* toworld) {
}

void inherit_variable_value_update(Skolem* skolem, World* toworld) {
}

void do_propagate_constraints(Context* context) {
  // Trigger constraint propagation over all propositions
  // in the module or world `context'.
  { World* world = context->get_constraint_propagation_world();
    Module* module = context->base_module;

    if (world->up_to_date_inferencesP_reader()) {
      return;
    }
    {
      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;
        boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        oPENDINGEXCEPTIONHANDLERpo = TRUE;
        if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          { Proposition* p = NULL;
            Iterator* iter_001 = all_propositions(module, TRUE);

            while (iter_001->nextP()) {
              {
                p = ((Proposition*)(iter_001->value));
              }
              world->react_to_kb_update(p);
            }
          }
          oEXCEPTIONo = NULL;
        }
        oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (subtype_ofP(oEXCEPTION_TYPEo, SGT_CACHES_CLASH)) {
          cout << "One or more facts need to be retracted to eliminate" << endl << "   the inconsistency." << endl;
        }
        else {
          resignal();
        }
      }
    }
    set_dynamic_slot_value(world, SYM_CACHES_UP_TO_DATE_INFERENCESp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
  }
}

void propagate_constraints(Cons* name) {
  // Trigger constraint propagation over all propositions of module `name'.
  // If no `name' is supplied, the current module will be used.  This also
  // enables incremental constraint propagation for future monotonic updates to
  // the module.  Once a non-monotonic update is performed, i.e., a retraction
  // or clipping of a function value, all cached inferences will be discarded
  // and constraint propagation will be turned off until this function is
  // called again.
  { Module* module = coerce_to_module(name->first(), TRUE);

    if (module != NULL) {
      do_propagate_constraints(module);
    }
  }
}

void propagate_constraints_evaluator_wrapper(Cons* arguments) {
  propagate_constraints(((Cons*)(arguments)));
}

void do_enable_constraint_propagation(Context* self) {
  // Find or create a strict inference cache for context `self',
  // which will contain the inferences derived from future updates to `self'.
  { Context* self_001 = self;

    if (taxonomy_isaP(self, SGT_CACHES_MODULE)) {
      { Module* self = NULL;

        self = ((Module*)(self_001));
        get_inference_cache(self, KWD_CACHES_STRICT);
      }
    }
    else if (taxonomy_isaP(self, SGT_CACHES_WORLD)) {
      { World* self = NULL;

        self = ((World*)(self_001));
        if (!propagate_constraints_incrementallyP(self)) {
          cout << "Can't propagate constraints in world " << "`" << self << "'" << " because" << endl << "   it is neither marked `monotonic?' nor " << "`truth-maintained?'." << endl;
        }
      }
    }
    else {
      cerr << "`" << self << "'" << " is not a valid case option";
    }
  }
}

void startup_caches() {
  { Module* old_OmoduleO_001 = oMODULEo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = string_get_module("/LOGIC", TRUE);
          oCONTEXTo = oMODULEo;
          if (current_startup_time_phaseP(2)) {
            KWD_CACHES_STRICT = ((Keyword*)(intern_rigid_symbol_wrt_module("STRICT", NULL, 2)));
            SYM_CACHES_STRICT_INFERENCE_CACHE = ((Symbol*)(intern_rigid_symbol_wrt_module("STRICT-INFERENCE-CACHE", NULL, 0)));
            KWD_CACHES_DEFAULT = ((Keyword*)(intern_rigid_symbol_wrt_module("DEFAULT", NULL, 2)));
            SYM_CACHES_DEFAULT_INFERENCE_CACHE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFAULT-INFERENCE-CACHE", NULL, 0)));
            SYM_CACHES_MONOTONICp = ((Symbol*)(intern_rigid_symbol_wrt_module("MONOTONIC?", NULL, 0)));
            SYM_CACHES_UP_TO_DATE_INFERENCESp = ((Symbol*)(intern_rigid_symbol_wrt_module("UP-TO-DATE-INFERENCES?", NULL, 0)));
            SGT_CACHES_CLASH = ((Surrogate*)(intern_rigid_symbol_wrt_module("CLASH", NULL, 1)));
            SYM_CACHES_EVALUATOR_WRAPPER_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("EVALUATOR-WRAPPER-CODE", string_get_module("/STELLA", TRUE), 0)));
            SGT_CACHES_MODULE = ((Surrogate*)(intern_rigid_symbol_wrt_module("MODULE", string_get_module("/STELLA", TRUE), 1)));
            SGT_CACHES_WORLD = ((Surrogate*)(intern_rigid_symbol_wrt_module("WORLD", string_get_module("/STELLA", TRUE), 1)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-INFERENCE-CACHE", "MODULE", "(DEFUN (LOOKUP-INFERENCE-CACHE WORLD) ((MODULE MODULE) (KIND KEYWORD)))");

              method->function_code = ((cpp_function_code)(&lookup_inference_cache));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-INFERENCE-CACHE", "MODULE", "(DEFUN (CREATE-INFERENCE-CACHE WORLD) ((MODULE MODULE) (KIND KEYWORD)))");

              method->function_code = ((cpp_function_code)(&create_inference_cache));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-INFERENCE-CACHE", "MODULE", "(DEFUN (GET-INFERENCE-CACHE WORLD) ((MODULE MODULE) (KIND KEYWORD)))");

              method->function_code = ((cpp_function_code)(&get_inference_cache));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-INFERENCE-CACHE", "WORLD", "(DEFUN DESTROY-INFERENCE-CACHE ((WORLD WORLD)))");

              method->function_code = ((cpp_function_code)(&destroy_inference_cache));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHECK-FOR-OUT-OF-DATE-INFERENCE-CACHE", NULL, "(DEFUN CHECK-FOR-OUT-OF-DATE-INFERENCE-CACHE ())");

              method->function_code = ((cpp_function_code)(&check_for_out_of_date_inference_cache));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-QUERY-CONTEXT", NULL, "(DEFUN (GET-QUERY-CONTEXT CONTEXT) ())");

              method->function_code = ((cpp_function_code)(&get_query_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-TOP-LEVEL-UPDATE-CONTEXT", NULL, "(DEFUN (GET-TOP-LEVEL-UPDATE-CONTEXT CONTEXT) ())");

              method->function_code = ((cpp_function_code)(&get_top_level_update_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-CONSTRAINT-PROPAGATION-WORLD", "CONTEXT", "(DEFMETHOD (GET-CONSTRAINT-PROPAGATION-WORLD WORLD) ((SELF CONTEXT)))");

              method->method_code = ((cpp_method_code)(&Context::get_constraint_propagation_world));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-CONSTRAINT-PROPAGATION-WORLD", "MODULE", "(DEFMETHOD (GET-CONSTRAINT-PROPAGATION-WORLD WORLD) ((SELF MODULE)))");

              method->method_code = ((cpp_method_code)(&Module::get_constraint_propagation_world));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-CACHED-INFERENCES", "WORLD", "(DEFUN INHERIT-CACHED-INFERENCES ((FROMWORLD WORLD) (TOWORLD WORLD)))");

              method->function_code = ((cpp_function_code)(&inherit_cached_inferences));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-TRUTH-VALUE-UPDATE", "PROPOSITION", "(DEFUN INHERIT-TRUTH-VALUE-UPDATE ((PROPOSITION PROPOSITION) (TOWORLD WORLD)))");

              method->function_code = ((cpp_function_code)(&inherit_truth_value_update));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-VARIABLE-VALUE-UPDATE", "SKOLEM", "(DEFUN INHERIT-VARIABLE-VALUE-UPDATE ((SKOLEM SKOLEM) (TOWORLD WORLD)))");

              method->function_code = ((cpp_function_code)(&inherit_variable_value_update));
            }
            { Method_Slot* method = define_method_from_stringified_source("DO-PROPAGATE-CONSTRAINTS", "CONTEXT", "(DEFUN DO-PROPAGATE-CONSTRAINTS ((CONTEXT CONTEXT)) :DOCUMENTATION \"Trigger constraint propagation over all propositions\nin the module or world `context'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&do_propagate_constraints));
            }
            { Method_Slot* method = define_method_from_stringified_source("PROPAGATE-CONSTRAINTS", "ARGUMENT-LIST", "(DEFUN PROPAGATE-CONSTRAINTS (|&REST| (NAME NAME)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Trigger constraint propagation over all propositions of module `name'.\nIf no `name' is supplied, the current module will be used.  This also\nenables incremental constraint propagation for future monotonic updates to\nthe module.  Once a non-monotonic update is performed, i.e., a retraction\nor clipping of a function value, all cached inferences will be discarded\nand constraint propagation will be turned off until this function is\ncalled again.\")");

              method->function_code = ((cpp_function_code)(&propagate_constraints));
              set_dynamic_slot_value(method, SYM_CACHES_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&propagate_constraints_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("DO-ENABLE-CONSTRAINT-PROPAGATION", "CONTEXT", "(DEFUN DO-ENABLE-CONSTRAINT-PROPAGATION ((SELF CONTEXT)) :DOCUMENTATION \"Find or create a strict inference cache for context `self',\nwhich will contain the inferences derived from future updates to `self'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&do_enable_constraint_propagation));
            }
            define_method_from_stringified_source("STARTUP-CACHES", NULL, "(DEFUN STARTUP-CACHES ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
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

