// contexts.cc

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

boolean oUNLINK_DISCARDED_CONTEXTS_ON_READpo = TRUE;

boolean oUNLINK_DISCARDED_CONTEXTS_ON_WRITEpo = TRUE;

boolean oCONTEXT_BACKTRACKING_MODEo = FALSE;

Surrogate* SGT_CONTEXTS_CS_VALUE = NULL;

Symbol* SYM_CONTEXTS_EVALUATOR_WRAPPER_CODE = NULL;

Surrogate* SGT_CONTEXTS_MODULE = NULL;

Surrogate* SGT_CONTEXTS_WORLD = NULL;

Symbol* SYM_CONTEXTS_WORLD_NAME = NULL;

boolean cs_valueP(Object* self) {
  return ((self != NULL) &&
      (self->primary_type() == SGT_CONTEXTS_CS_VALUE));
}

boolean subcontextP(Context* subcontext, Context* supercontext) {
  return ((subcontext == supercontext) ||
      subcontext->all_super_contexts->memberP(supercontext));
}

boolean discarded_contextP(Context* context) {
  return (oddP(context->context_number));
}

Context* help_find_context_by_number(int number, List* siblings) {
  { Context* c = NULL;
    Cons* iter_001 = siblings->the_cons_list;

    while (!nilP(iter_001)) {
      {
        c = ((Context*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (c->context_number == number) {
        return (c);
      }
      else if (c->context_number < number) {
        return (help_find_context_by_number(number, c->child_contexts));
      }
      else {
        continue;
      }
    }
  }
  return (NULL);
}

Context* find_context_by_number(int contextnumber) {
  return (help_find_context_by_number(contextnumber, oROOT_MODULEo->child_contexts));
}

Context* string_slowly_get_context(char* self) {
  { Context* context = get_context(self, FALSE);

    if (context != NULL) {
      return (context);
    }
    { Context* cxt = NULL;
      Cons* iter_001 = oROOT_MODULEo->child_contexts->the_cons_list;

      while (!nilP(iter_001)) {
        {
          cxt = ((Context*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (string_eqlP(cxt->context_name(), self)) {
          return (cxt);
        }
      }
    }
    { Context* cxt = NULL;
      Iterator* iter_002 = all_contexts();

      while (iter_002->nextP()) {
        {
          cxt = ((Context*)(iter_002->value));
        }
        if (string_eqlP(cxt->context_name(), self)) {
          if (context != NULL) {
            cout << "More than one context has the name " << "`" << self << "'" << endl;
            return (NULL);
          }
          context = cxt;
        }
      }
    }
    return (context);
  }
}

Context* integer_slowly_get_context(int self) {
  return (find_context_by_number(self));
}

Context* Symbol::slowly_get_context() {
  { Symbol* self = this;

    return (string_slowly_get_context(self->relative_name()));
  }
}

Context* slowly_change_context(Context* self) {
  if (self != NULL) {
    return (self->change_context());
  }
  else {
    return (oCONTEXTo);
  }
}

Context* cc(Cons* name) {
  // Change the current context to the one named `name'.  Return the
  // value of the new current context.  If no `name' is supplied, return
  // the value of `*context*'.  `cc' is a no-op if the context reference
  // cannot be successfully evaluated.
  { Context* context = oCONTEXTo;
    Object* namespec = name->first();

    if (namespec != NULL) {
      { Object* namespec_001 = namespec;

        if (integerP(namespec)) {
          { Integer_Wrapper* namespec = NULL;

            namespec = ((Integer_Wrapper*)(namespec_001));
            context = integer_slowly_get_context(namespec->wrapper_value);
          }
        }
        else {
          { char* contextname = coerce_to_module_name(namespec, TRUE);

            if (contextname != NULL) {
              context = string_slowly_get_context(contextname);
            }
          }
        }
      }
    }
    return (slowly_change_context(context));
  }
}

Context* cc_evaluator_wrapper(Cons* arguments) {
  return (cc(((Cons*)(arguments))));
}

void print_context(Context* self, ostream* stream) {
  { char* typestring = NULL;
    char* name = NULL;
    int number = self->context_number;

    if (!oCLASS_HIERARCHY_BOOTEDpo) {
      *(stream) << "|MDL|" << ((Module*)(self))->module_name;
      return;
    }
    { Context* self_001 = self;

      if (taxonomy_isaP(self, SGT_CONTEXTS_MODULE)) {
        { Module* self = NULL;

          self = ((Module*)(self_001));
          name = self->module_full_name;
          if (discarded_contextP(self)) {
            typestring = "|DISCARDED MDL|";
          }
          else {
            typestring = "|MDL|";
          }
        }
      }
      else if (taxonomy_isaP(self, SGT_CONTEXTS_WORLD)) {
        { World* self = NULL;

          self = ((World*)(self_001));
          name = ((String_Wrapper*)(dynamic_slot_value(self, SYM_CONTEXTS_WORLD_NAME, NULL_STRING_WRAPPER)))->wrapper_value;
          if (discarded_contextP(self)) {
            typestring = "|DISCARDED WLD|";
          }
          else {
            typestring = "|WLD|";
          }
        }
      }
      else {
        cerr << "`" << self << "'" << " is not a valid case option";
      }
    }
    if (discarded_contextP(self)) {
      number = number + 1;
    }
    if (name != NULL) {
      *(stream) << typestring << name;
    }
    else {
      *(stream) << typestring << number;
    }
  }
}

void help_print_context_tree(List* list, int level) {
  { Context* c = NULL;
    Cons* iter_001 = list->the_cons_list;

    while (!nilP(iter_001)) {
      {
        c = ((Context*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      cout << endl;
      { int i = NULL_INTEGER;
        int iter_002 = 1;
        int upper_bound_001 = 3 * level;

        while (iter_002 <= upper_bound_001) {
          {
            i = iter_002;
            iter_002 = iter_002 + 1;
          }
          {
          }
          cout << " ";
        }
      }
      cout << c->context_number;
      if (c->context_name() != NULL) {
        cout << "   " << c->context_name();
      }
      cout << endl;
      help_print_context_tree(c->child_contexts, level + 1);
    }
  }
}

void print_context_tree(Context* root) {
  if (root == NULL) {
    root = oROOT_MODULEo;
  }
  { List* toplist = list(1, root);

    help_print_context_tree(toplist, 0);
    toplist->free();
  }
}

Object* access_in_context(Object* value, Context_Sensitive_Object* object, boolean dontinheritP) {
  if ((value == NULL) ||
      (!cs_valueP(value))) {
    { Context* homecontext = object->home_context;

      if (dontinheritP) {
        if (oCONTEXTo == homecontext) {
          return (value);
        }
      }
      else {
        if ((homecontext == NULL) ||
            (subcontextP(oCONTEXTo, homecontext) ||
             (isaP(homecontext, SGT_CONTEXTS_MODULE) &&
              visible_fromP(((Module*)(homecontext)), oMODULEo)))) {
          return (value);
        }
      }
      return (NULL);
    }
  }
  { Kv_Cons* kvcons = ((Cs_Value*)(value))->the_kv_list;
    int contextnumber = NULL_INTEGER;

    { Context* target = oCONTEXTo;

      contextnumber = target->context_number;
      while ((kvcons != NULL) &&
          (contextnumber < ((Context*)(kvcons->key))->context_number)) {
        if (discarded_contextP(((Context*)(kvcons->key))) &&
            ((!oCONTEXT_BACKTRACKING_MODEo) &&
             oUNLINK_DISCARDED_CONTEXTS_ON_READpo)) {
          if (kvcons->rest != NULL) {
            { Kv_Cons* nextkvcons = kvcons->rest;

              kvcons->key = nextkvcons->key;
              kvcons->value = nextkvcons->value;
              kvcons->rest = nextkvcons->rest;
              nextkvcons->free();
            }
          }
          else {
            {
              ((Cs_Value*)(value))->remove_at(((Context*)(kvcons->key)));
              return (NULL);
            }
          }
        }
        else {
          kvcons = kvcons->rest;
        }
      }
      if (kvcons == NULL) {
        return (NULL);
      }
      if (target == kvcons->key) {
        return (kvcons->value);
      }
      if (dontinheritP) {
        return (NULL);
      }
    }
    { Context* target = NULL;
      Cons* iter_001 = oCONTEXTo->all_super_contexts;

      while (!nilP(iter_001)) {
        {
          target = ((Context*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        contextnumber = target->context_number;
        while ((kvcons != NULL) &&
            (contextnumber < ((Context*)(kvcons->key))->context_number)) {
          if (discarded_contextP(((Context*)(kvcons->key))) &&
              ((!oCONTEXT_BACKTRACKING_MODEo) &&
               oUNLINK_DISCARDED_CONTEXTS_ON_READpo)) {
            if (kvcons->rest != NULL) {
              { Kv_Cons* nextkvcons = kvcons->rest;

                kvcons->key = nextkvcons->key;
                kvcons->value = nextkvcons->value;
                kvcons->rest = nextkvcons->rest;
                nextkvcons->free();
              }
            }
            else {
              {
                ((Cs_Value*)(value))->remove_at(((Context*)(kvcons->key)));
                return (NULL);
              }
            }
          }
          else {
            kvcons = kvcons->rest;
          }
        }
        if (kvcons == NULL) {
          return (NULL);
        }
        if (target == kvcons->key) {
          return (kvcons->value);
        }
        if (dontinheritP) {
          return (NULL);
        }
      }
    }
    return (NULL);
  }
}

Context* compute_nearest_context(Object* value, Context_Sensitive_Object* object, Context* context) {
  if ((value == NULL) ||
      (!cs_valueP(value))) {
    return (object->home_context);
  }
  { Kv_Cons* kvcons = ((Cs_Value*)(value))->the_kv_list;
    int contextnumber = NULL_INTEGER;

    { Context* target = context;

      contextnumber = target->context_number;
      while ((kvcons != NULL) &&
          (contextnumber < ((Context*)(kvcons->key))->context_number)) {
        kvcons = kvcons->rest;
      }
      if (kvcons == NULL) {
        return (NULL);
      }
      if (target == kvcons->key) {
        return (target);
      }
    }
    { Context* target = NULL;
      Cons* iter_001 = context->all_super_contexts;

      while (!nilP(iter_001)) {
        {
          target = ((Context*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        contextnumber = target->context_number;
        while ((kvcons != NULL) &&
            (contextnumber < ((Context*)(kvcons->key))->context_number)) {
          kvcons = kvcons->rest;
        }
        if (kvcons == NULL) {
          return (NULL);
        }
        if (target == kvcons->key) {
          return (target);
        }
      }
    }
    return (NULL);
  }
}

void help_insert_a_cs_value(Kv_Cons* kvcons, Object* newvalue, Context* target, boolean overwriteP) {
  { int contextnumber = target->context_number;

    for (;;) {
      if ((!oCONTEXT_BACKTRACKING_MODEo) &&
          (oUNLINK_DISCARDED_CONTEXTS_ON_WRITEpo &&
           discarded_contextP(((Context*)(kvcons->key))))) {
        if (kvcons->rest != NULL) {
          { Kv_Cons* nextkvcons = kvcons->rest;

            kvcons->key = nextkvcons->key;
            kvcons->value = nextkvcons->value;
            kvcons->rest = nextkvcons->rest;
            nextkvcons->free();
          }
        }
        else {
          {
            kvcons->key = target;
            kvcons->value = newvalue;
            return;
          }
        }
      }
      if (kvcons->key == target) {
        if (overwriteP) {
          kvcons->value = newvalue;
        }
        return;
      }
      else if (((Context*)(kvcons->key))->context_number < contextnumber) {
        kvcons->rest = kv_cons(kvcons->key, kvcons->value, kvcons->rest);
        kvcons->key = target;
        kvcons->value = newvalue;
        return;
      }
      else if (kvcons->rest == NULL) {
        kvcons->rest = kv_cons(target, newvalue, NULL);
        return;
      }
      else {
        kvcons = kvcons->rest;
      }
    }
  }
}

void Cs_Value::insert_at(Context* context, Object* newvalue) {
  { Cs_Value* self = this;

    if (self->the_kv_list == NULL) {
      { Kv_Cons* kvcons = new_kv_cons();

        kvcons->key = context;
        kvcons->value = newvalue;
        self->the_kv_list = kvcons;
        return;
      }
    }
    help_insert_a_cs_value(self->the_kv_list, newvalue, context, TRUE);
  }
}

Object* update_in_context(Object* oldvalue, Object* newvalue, Context_Sensitive_Object* object, boolean copytochildrenP) {
  { Cs_Value* csvalue = NULL;
    Context* homecontext = object->home_context;

    if (cs_valueP(oldvalue)) {
      csvalue = ((Cs_Value*)(oldvalue));
    }
    else {
      if ((homecontext == oCONTEXTo) &&
          (oCONTEXTo->child_contexts->emptyP() ||
           (!copytochildrenP))) {
        return (newvalue);
      }
      else {
        {
          csvalue = new_cs_value();
          if (oldvalue != NULL) {
            csvalue->insert_at(homecontext, oldvalue);
          }
        }
      }
    }
    csvalue->insert_at(oCONTEXTo, newvalue);
    if (copytochildrenP) {
      copy_current_value_to_children(csvalue, object, newvalue);
    }
    return (csvalue);
  }
}

void copy_current_value_to_children(Cs_Value* csvalue, Context_Sensitive_Object* object, Object* parentvalue) {
  { Context* childcxt = NULL;
    Cons* iter_001 = oCONTEXTo->child_contexts->the_cons_list;

    while (!nilP(iter_001)) {
      {
        childcxt = ((Context*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      { Context* old_OcontextO_001 = oCONTEXTo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oCONTEXTo = childcxt;
              { Object* currentvalue = access_in_context(csvalue, object, FALSE);

                if (!eqlP(currentvalue, parentvalue)) {
                  help_insert_a_cs_value(csvalue->the_kv_list, currentvalue, childcxt, FALSE);
                }
              }
              oCONTEXTo = old_OcontextO_001;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oCONTEXTo = old_OcontextO_001;
            resignal();
          }
        }
      }
    }
  }
}

void startup_contexts() {
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
            SGT_CONTEXTS_CS_VALUE = ((Surrogate*)(intern_rigid_symbol_wrt_module("CS-VALUE", NULL, 1)));
            SYM_CONTEXTS_EVALUATOR_WRAPPER_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("EVALUATOR-WRAPPER-CODE", NULL, 0)));
            SGT_CONTEXTS_MODULE = ((Surrogate*)(intern_rigid_symbol_wrt_module("MODULE", NULL, 1)));
            SGT_CONTEXTS_WORLD = ((Surrogate*)(intern_rigid_symbol_wrt_module("WORLD", NULL, 1)));
            SYM_CONTEXTS_WORLD_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("WORLD-NAME", NULL, 0)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("CS-VALUE?", "OBJECT", "(DEFUN (CS-VALUE? BOOLEAN) ((SELF OBJECT)) :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&cs_valueP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBCONTEXT?", "CONTEXT", "(DEFUN (SUBCONTEXT? BOOLEAN) ((SUBCONTEXT CONTEXT) (SUPERCONTEXT CONTEXT)) :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&subcontextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DISCARDED-CONTEXT?", "CONTEXT", "(DEFUN (DISCARDED-CONTEXT? BOOLEAN) ((CONTEXT CONTEXT)))");

              method->function_code = ((cpp_function_code)(&discarded_contextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-FIND-CONTEXT-BY-NUMBER", "INTEGER", "(DEFUN (HELP-FIND-CONTEXT-BY-NUMBER CONTEXT) ((NUMBER INTEGER) (SIBLINGS (LIST OF CONTEXT))))");

              method->function_code = ((cpp_function_code)(&help_find_context_by_number));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-CONTEXT-BY-NUMBER", "INTEGER", "(DEFUN (FIND-CONTEXT-BY-NUMBER CONTEXT) ((CONTEXTNUMBER INTEGER)))");

              method->function_code = ((cpp_function_code)(&find_context_by_number));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOWLY-GET-CONTEXT", "STRING", "(DEFMETHOD (SLOWLY-GET-CONTEXT CONTEXT) ((SELF STRING)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOWLY-GET-CONTEXT", "INTEGER", "(DEFMETHOD (SLOWLY-GET-CONTEXT CONTEXT) ((SELF INTEGER)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOWLY-GET-CONTEXT", "SYMBOL", "(DEFMETHOD (SLOWLY-GET-CONTEXT CONTEXT) ((SELF SYMBOL)))");

              method->method_code = ((cpp_method_code)(&Symbol::slowly_get_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOWLY-CHANGE-CONTEXT", "CONTEXT", "(DEFUN (SLOWLY-CHANGE-CONTEXT CONTEXT) ((SELF CONTEXT)))");

              method->function_code = ((cpp_function_code)(&slowly_change_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("CC", "ARGUMENT-LIST", "(DEFUN (CC CONTEXT) (|&REST| (NAME NAME)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Change the current context to the one named `name'.  Return the\nvalue of the new current context.  If no `name' is supplied, return\nthe value of `*context*'.  `cc' is a no-op if the context reference\ncannot be successfully evaluated.\")");

              method->function_code = ((cpp_function_code)(&cc));
              set_dynamic_slot_value(method, SYM_CONTEXTS_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&cc_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-CONTEXT", "CONTEXT", "(DEFUN PRINT-CONTEXT ((SELF CONTEXT) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-PRINT-CONTEXT-TREE", "LIST", "(DEFUN HELP-PRINT-CONTEXT-TREE ((LIST (LIST OF CONTEXT)) (LEVEL INTEGER)))");

              method->function_code = ((cpp_function_code)(&help_print_context_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-CONTEXT-TREE", "CONTEXT", "(DEFUN PRINT-CONTEXT-TREE ((ROOT CONTEXT)))");

              method->function_code = ((cpp_function_code)(&print_context_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("ACCESS-IN-CONTEXT", "OBJECT", "(DEFUN (ACCESS-IN-CONTEXT OBJECT) ((VALUE OBJECT) (OBJECT CONTEXT-SENSITIVE-OBJECT) (DONTINHERIT? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&access_in_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-NEAREST-CONTEXT", "OBJECT", "(DEFUN (COMPUTE-NEAREST-CONTEXT CONTEXT) ((VALUE OBJECT) (OBJECT CONTEXT-SENSITIVE-OBJECT) (CONTEXT CONTEXT)))");

              method->function_code = ((cpp_function_code)(&compute_nearest_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-INSERT-A-CS-VALUE", "KV-CONS", "(DEFUN HELP-INSERT-A-CS-VALUE ((KVCONS KV-CONS) (NEWVALUE OBJECT) (TARGET CONTEXT) (OVERWRITE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&help_insert_a_cs_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT-AT", "CS-VALUE", "(DEFMETHOD INSERT-AT ((SELF CS-VALUE) (CONTEXT CONTEXT) (NEWVALUE OBJECT)))");

              method->method_code = ((cpp_method_code)(&Cs_Value::insert_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPDATE-IN-CONTEXT", "OBJECT", "(DEFUN (UPDATE-IN-CONTEXT OBJECT) ((OLDVALUE OBJECT) (NEWVALUE OBJECT) (OBJECT CONTEXT-SENSITIVE-OBJECT) (COPYTOCHILDREN? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&update_in_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-CURRENT-VALUE-TO-CHILDREN", "CS-VALUE", "(DEFUN COPY-CURRENT-VALUE-TO-CHILDREN ((CSVALUE CS-VALUE) (OBJECT CONTEXT-SENSITIVE-OBJECT) (PARENTVALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&copy_current_value_to_children));
            }
            define_method_from_stringified_source("STARTUP-CONTEXTS", NULL, "(DEFUN STARTUP-CONTEXTS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *UNLINK-DISCARDED-CONTEXTS-ON-READ?* BOOLEAN TRUE :DOCUMENTATION \"Eliminate pointers to discarded contexts while\naccessing a CS-VALUE context table.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *UNLINK-DISCARDED-CONTEXTS-ON-WRITE?* BOOLEAN TRUE :DOCUMENTATION \"Eliminate pointers to discarded contexts while\ninserting into a CS-VALUE context table.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CONTEXT-BACKTRACKING-MODE* BOOLEAN FALSE :DOCUMENTATION \"If true, indicates that contexts are being allocated\nand deallocated in depth-first fashion, and that deallocation of\nCS-VALUE entries is taken care of during context destruction.\")");
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

