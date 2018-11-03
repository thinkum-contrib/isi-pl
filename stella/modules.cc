// modules.cc

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

Keyword* oSUBCONTEXT_REVISION_POLICYo = NULL;

Keyword* KWD_MODULES_DESTROY = NULL;

Surrogate* SGT_MODULES_MODULE = NULL;

Symbol* SYM_MODULES_NAME = NULL;

Cons* oSHADOWEDSURROGATESo = NULL;

Symbol* SYM_MODULES_oSHADOWEDSURROGATESo = NULL;

Symbol* SYM_MODULES_SHADOWED_SURROGATES = NULL;

Keyword* KWD_MODULES_INCLUDES = NULL;

Keyword* KWD_MODULES_USES = NULL;

Keyword* KWD_MODULES_SHADOW = NULL;

Keyword* KWD_MODULES_DOCUMENTATION = NULL;

Keyword* KWD_MODULES_CASE_SENSITIVEp = NULL;

Symbol* SYM_MODULES_TRUE = NULL;

Keyword* KWD_MODULES_PACKAGE = NULL;

Keyword* KWD_MODULES_REQUIRES = NULL;

Keyword* KWD_MODULES_DIRECTORY_FILE = NULL;

Keyword* KWD_MODULES_CODE_FILES = NULL;

Keyword* KWD_MODULES_DEFINITIONS_FILE = NULL;

Keyword* KWD_MODULES_PRESERVE = NULL;

Keyword* KWD_MODULES_CLEAR = NULL;

Keyword* KWD_MODULES_PREORDER = NULL;

Surrogate* SGT_MODULES_WORLD = NULL;

Symbol* SYM_MODULES_DEFINE_MODULE_FROM_STRINGIFIED_SOURCE = NULL;

Symbol* SYM_MODULES_EVALUATOR_WRAPPER_CODE = NULL;

Symbol* SYM_MODULES_WORLD_NAME = NULL;

Keyword* KWD_MODULES_POSTORDER = NULL;

Keyword* KWD_MODULES_INORDER = NULL;

Symbol* SYM_MODULES_CLEARABLEp = NULL;

Iterator* Context::parent_contexts() {
  { Context* self = this;

    return (NULL);
  }
}

Iterator* Module::parent_contexts() {
  { Module* self = this;

    return (((List_Iterator*)(self->parent_modules->allocate_iterator())));
  }
}

Iterator* World::parent_contexts() {
  { World* self = this;

    return (((Cons*)(cons(self->parent_context, NIL)))->allocate_destructive_list_iterator());
  }
}

Context* compute_context_or_module_from_pathname(char* pathname, boolean moduleP, boolean symbolnameP, int& return1) {
  { Context* context = ((string_nth(pathname, 0) == MODULE_SEPARATOR_CHARACTER) ? ((Context*)(oROOT_MODULEo)) : ((Context*)((moduleP ? ((Context*)(oMODULEo)) : ((Context*)(oCONTEXTo))))));
    int componentend = ((context == oROOT_MODULEo) ? ((int)(0)) : ((int)(-1)));
    int componentstart = NULL_INTEGER;
    int lastcharpos = string_length(pathname) - 1;

    while (componentend < lastcharpos) {
      componentstart = componentend + 1;
      componentend = componentstart;
      { int i = NULL_INTEGER;
        int iter_001 = componentstart;
        int upper_bound_001 = lastcharpos;
        boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

        while (unboundedP_001 ||
            (iter_001 <= upper_bound_001)) {
          {
            i = iter_001;
            iter_001 = iter_001 + 1;
          }
          if ((!(string_nth(pathname, i) == MODULE_SEPARATOR_CHARACTER)) ||
              escaped_characterP(pathname, i)) {
            componentend = componentend + 1;
          }
          else {
            break;
          }
        }
      }
      if (symbolnameP &&
          (componentend > lastcharpos)) {
        { Context* return_temp = context;

          return1 = componentstart;
          return (return_temp);
        }
      }
      if (context != NULL) {
        if (componentstart == componentend) {
          continue;
        }
        else if (component_matchP("..", pathname, componentstart, componentend)) {
          if (!(context->parent_contexts()->emptyP())) {
            context = (moduleP ? ((Context*)(((Module*)(context))->parent_module())) : ((Context*)(((Context*)(context->parent_contexts()->pop())))));
          }
        }
        else if (component_matchP(".", pathname, componentstart, componentend)) {
        }
        else {
          { Context* value_001 = NULL;

            { Context* child = NULL;
              Cons* iter_002 = context->child_contexts->the_cons_list;

              while (!nilP(iter_002)) {
                {
                  child = ((Context*)(iter_002->value));
                  iter_002 = iter_002->rest;
                }
                if (((!moduleP) ||
                    isaP(child, SGT_MODULES_MODULE)) &&
                    component_matchP((moduleP ? ((char*)(((Module*)(child))->module_name)) : ((char*)(child->context_name()))), pathname, componentstart, componentend)) {
                  value_001 = child;
                  break;
                }
              }
            }
            context = value_001;
          }
          if ((context == NULL) ||
              (moduleP &&
               (!isaP(context, SGT_MODULES_MODULE)))) {
            if (!(moduleP)) {
              cerr << "Bad path name.  Context named " << "`" << pathname << "'" << " not found.";
            }
          }
        }
      }
    }
    { Context* return_temp = context;

      return1 = NULL_INTEGER;
      return (return_temp);
    }
  }
}

boolean component_matchP(char* component, char* string, int start, int end) {
  { boolean test_value_001 = FALSE;

    test_value_001 = string_length(component) == (end - start);
    if (test_value_001) {
      { boolean alwaysP_001 = TRUE;

        { int i = NULL_INTEGER;
          char renamed_Char = NULL_CHARACTER;
          char* vector_001 = component;
          int index_001 = 0;
          int length_001 = string_length(vector_001);
          int iter_001 = start;

          while (index_001 < length_001) {
            {
              renamed_Char = string_nth(vector_001, index_001);
              index_001 = index_001 + 1;
            }
            {
              i = iter_001;
              iter_001 = iter_001 + 1;
            }
            if (!(renamed_Char == string_nth(string, i))) {
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

Module* compute_module_and_bare_name(char* name, char*& return1) {
  { Context* module = NULL;
    int barenamestart = NULL_INTEGER;

    module = compute_context_or_module_from_pathname(name, TRUE, TRUE, barenamestart);
    { Module* return_temp = ((Module*)(module));

      return1 = ((barenamestart != NULL_INTEGER) ? ((char*)(string_subsequence(name, barenamestart, NULL_INTEGER))) : ((char*)(NULL)));
      return (return_temp);
    }
  }
}

Generalized_Symbol* intern_qualified_name(char* name) {
  { Module* module = NULL;
    char* barename = NULL;

    module = compute_module_and_bare_name(name, barename);
    if (module == NULL) {
      return (NULL);
    }
    if (string_eqlP(barename, "")) {
      if ((module == oMODULEo) ||
          (module == oROOT_MODULEo)) {
        return (intern_rigid_symbol_wrt_module("/", oSTELLA_MODULEo, SYMBOL_SYM));
      }
      else {
        {
          cerr << "Empty symbol name encountered";
          return (NULL);
        }
      }
    }
    if (surrogate_nameP(barename)) {
      return (intern_rigid_symbol_wrt_module(string_subsequence(barename, 1, NULL_INTEGER), module, SURROGATE_SYM));
    }
    else {
      return (intern_rigid_symbol_wrt_module(barename, module, SYMBOL_SYM));
    }
  }
}

Context* get_context(char* pathname, boolean warnP) {
  // Return the context located at 'pathName', or NULL
  // if no such context exists.  If 'warn?' is TRUE, print a warning
  // message if no context is found.
  { int dummy1;

    { Context* context = NULL;

      if (qualified_nameP(pathname)) {
        context = compute_context_or_module_from_pathname(pathname, FALSE, FALSE, dummy1);
      }
      else {
        {
          { Context* value_001 = NULL;

            { Context* child = NULL;
              Cons* iter_001 = oCONTEXTo->child_contexts->the_cons_list;

              while (!nilP(iter_001)) {
                {
                  child = ((Context*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                if ((child->context_name() != NULL) &&
                    string_eqlP(child->context_name(), pathname)) {
                  value_001 = child;
                  break;
                }
              }
            }
            context = value_001;
          }
          if (context == NULL) {
            if (string_eqlP(oCONTEXTo->context_name(), pathname)) {
              return (oCONTEXTo);
            }
            if (string_eqlP(oMODULEo->context_name(), pathname)) {
              return (oMODULEo);
            }
          }
        }
      }
      if ((context == NULL) &&
          warnP) {
        cerr << "Can't find a context located at " << "`" << pathname << "'" << ".";
      }
      return (context);
    }
  }
}

Module* string_scan_for_module(char* name, Module* vantagepoint) {
  if (string_eqlP(vantagepoint->context_name(), name)) {
    return (vantagepoint);
  }
  { Context* super = NULL;
    Cons* iter_001 = vantagepoint->all_super_contexts;

    while (!nilP(iter_001)) {
      {
        super = ((Context*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (string_eqlP(super->context_name(), name)) {
        return (((Module*)(super)));
      }
    }
  }
  { Context* cardinal = NULL;
    Cons* iter_002 = oROOT_MODULEo->child_contexts->the_cons_list;

    while (!nilP(iter_002)) {
      {
        cardinal = ((Context*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      if (string_eqlP(cardinal->context_name(), name)) {
        return (((Module*)(cardinal)));
      }
    }
  }
  return (NULL);
}

Module* string_get_module(char* pathname, boolean warnP) {
  // Return the module located at 'pathName', or NULL
  // if no such module exists.  The search looks at ancestors and top-most
  //  (cardinal) modules.  If 'warn?' is TRUE, print a warning
  // message if no module is found.
  { int dummy1;

    if (string_eqlP(pathname, oMODULEo->module_full_name)) {
      return (oMODULEo);
    }
    { Module* module = NULL;

      if (qualified_nameP(pathname)) {
        module = ((Module*)(compute_context_or_module_from_pathname(pathname, TRUE, FALSE, dummy1)));
      }
      else {
        module = string_scan_for_module(pathname, oMODULEo);
      }
      if ((module == NULL) &&
          warnP) {
        cerr << "Can't find a module located at " << "`" << pathname << "'" << ".";
      }
      return (module);
    }
  }
}

char* coerce_to_module_name(Object* namespec, boolean warnP) {
  { Object* namespec_001 = namespec;

    if (stringP(namespec)) {
      { String_Wrapper* namespec = NULL;

        namespec = ((String_Wrapper*)(namespec_001));
        return (namespec->wrapper_value);
      }
    }
    else if (keywordP(namespec)) {
      { Keyword* namespec = NULL;

        namespec = ((Keyword*)(namespec_001));
        return (namespec->symbol_name);
      }
    }
    else if (symbolP(namespec)) {
      { Symbol* namespec = NULL;

        namespec = ((Symbol*)(namespec_001));
        { Module* module = ((Module*)(namespec->home_context));

          if (module == NULL) {
            return (namespec->symbol_name);
          }
          else if (module == oROOT_MODULEo) {
            return (string_concatenate("/", namespec->symbol_name));
          }
          else {
            return (namespec->visible_name());
          }
        }
      }
    }
    else if (surrogateP(namespec)) {
      { Surrogate* namespec = NULL;

        namespec = ((Surrogate*)(namespec_001));
        { Module* module = ((Module*)(namespec->home_context));

          if (module == NULL) {
            return (namespec->symbol_name);
          }
          else if (module == oROOT_MODULEo) {
            return (string_concatenate("/", namespec->symbol_name));
          }
          else {
            return (namespec->visible_name());
          }
        }
      }
    }
    else {
      if (warnP) {
        cerr << "Illegal module name: " << "`" << namespec << "'";
      }
      return (NULL);
    }
  }
}

Module* coerce_to_module(Object* object, boolean warnP) {
  if (object == NULL) {
    return (oMODULEo);
  }
  { Object* object_001 = object;

    if (taxonomy_isaP(object, SGT_MODULES_MODULE)) {
      { Module* object = NULL;

        object = ((Module*)(object_001));
        return (object);
      }
    }
    else {
      { char* modulename = coerce_to_module_name(object, warnP);
        Module* module = NULL;

        if (modulename != NULL) {
          if (qualified_nameP(modulename)) {
            return (string_get_module(modulename, warnP));
          }
          { 
            module = string_get_module(string_concatenate("./", modulename), FALSE);
            if (module != NULL) {
              return (module);
            }
            else {
              return (string_get_module(modulename, warnP));
            }
          }
        }
        return (NULL);
      }
    }
  }
}

Module* find_or_create_module(char* pathname) {
  // Return a module located at `pathname' if one exists,
  //   otherwise create one
  { Module* module = string_get_module(pathname, FALSE);

    if (!(module != NULL)) {
      module = define_module(pathname, NIL);
    }
    return (module);
  }
}

Module* change_current_module(Module* module) {
  oMODULEo = module;
  oCONTEXTo = module;
  run_hooks(oCHANGE_MODULE_HOOKSo, module);
  return (module);
}

Context* change_current_context(Context* context) {
  if (!(context->base_module == oMODULEo)) {
    change_current_module(context->base_module);
  }
  oCONTEXTo = context;
  return (context);
}

Context* Context::change_context() {
  // Change the current context to be the context
  // 'context'.
  { Context* context = this;

    if (context == oCONTEXTo) {
      return (context);
    }
    else {
      return (change_current_context(context));
    }
  }
}

Context* string_change_context(char* contextname) {
  // Change the current context to be the context named
  // 'contextName'.
  { Context* context = get_context(contextname, TRUE);

    if (context == NULL) {
      return (oCONTEXTo);
    }
    else {
      return (change_current_context(context));
    }
  }
}

Module* Module::change_module() {
  // Change the current module to be the module
  // 'module'.
  { Module* module = this;

    return (change_current_module(module));
  }
}

Module* string_change_module(char* modulename) {
  // Change the current module to be the module named
  // 'moduleName'.
  { Module* module = string_get_module(modulename, TRUE);

    if (module == NULL) {
      return (oMODULEo);
    }
    else {
      return (change_current_module(module));
    }
  }
}

boolean Module::multiple_parentsP() {
  // Return TRUE if 'module' has more than one parent.
  { Module* module = this;

    return (module->parent_modules->rest()->non_emptyP());
  }
}

void normalize_parent_modules(Module* self) {
  if (!self->multiple_parentsP()) {
    return;
  }
  { List* parents = self->parent_modules;

    { Module* supermodule = NULL;
      Cons* iter_001 = parents->the_cons_list;

      while (!nilP(iter_001)) {
        {
          supermodule = ((Module*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        { Module* othersupermodule = NULL;
          Cons* iter_002 = parents->the_cons_list;

          while (!nilP(iter_002)) {
            {
              othersupermodule = ((Module*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            if (!(othersupermodule == supermodule)) {
              if (supermodule->all_super_contexts->memberP(othersupermodule)) {
                cout << "Bad list of parents defined for module " << "`" << self->context_name() << "'" << "." << endl << "  The module " << "`" << othersupermodule->context_name() << "'" << " is not a direct ancestor." << endl;
                parents->remove(othersupermodule);
              }
            }
          }
        }
      }
    }
    if (self->multiple_parentsP() &&
        isaP(self, SGT_MODULES_MODULE)) {
      cerr << "Module " << "`" << self->context_name() << "'" << " has multiple parents.";
    }
  }
}

void inherit_supercontexts(Module* module) {
  { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTRANSIENTOBJECTSpo = FALSE;
          if (!module->multiple_parentsP()) {
            { Module* onlyparent = ((Module*)(module->parent_modules->first()));

              if (onlyparent != NULL) {
                module->all_super_contexts = cons(onlyparent, onlyparent->all_super_contexts);
                {
                  {
                    oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  }
                  return;
                }
              }
            }
          }
          { Cons* allsupercontexts = NIL;
            Cons* sublist = NULL;

            normalize_parent_modules(module);
            module->parent_modules->reverse();
            { Module* parent = NULL;
              Cons* iter_001 = module->parent_modules->the_cons_list;

              while (!nilP(iter_001)) {
                {
                  parent = ((Module*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                sublist = NIL;
                { Context* ancestor = NULL;
                  Cons* iter_002 = parent->all_super_contexts;
                  Cons* collect_001 = NULL;

                  while (!nilP(iter_002)) {
                    {
                      ancestor = ((Context*)(iter_002->value));
                      iter_002 = iter_002->rest;
                    }
                    if (!allsupercontexts->memberP(ancestor)) {
                      if (collect_001 == NULL) {
                        {
                          collect_001 = cons(ancestor, NIL);
                          if (nilP(sublist)) {
                            sublist = collect_001;
                          }
                          else {
                            add_cons_to_end_of_cons_list(sublist, collect_001);
                          }
                        }
                      }
                      else {
                        {
                          collect_001->rest = cons(ancestor, NIL);
                          collect_001 = collect_001->rest;
                        }
                      }
                    }
                  }
                }
                sublist = cons(parent, sublist);
                allsupercontexts = sublist->concatenate(allsupercontexts);
              }
            }
            module->all_super_contexts = allsupercontexts;
            module->parent_modules->reverse();
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

void uninherit_supercontexts(Module* module) {
  if (module->multiple_parentsP()) {
    free_cons_list(module->all_super_contexts);
  }
  else if (module->all_super_contexts->non_emptyP()) {
    module->all_super_contexts->free_cons();
  }
  module->all_super_contexts = NIL;
}

void inherit_used_modules(Module* module) {
  { List* usees = module->uses;

    if (usees->emptyP()) {
      if (module->parent_modules->emptyP()) {
        usees->push(oSTELLA_MODULEo);
        oSTELLA_MODULEo->used_by->insert_new(module);
      }
      else {
        { Module* parent = NULL;
          Cons* iter_001 = module->parent_modules->the_cons_list;

          while (!nilP(iter_001)) {
            {
              parent = ((Module*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            { Module* parentusees = NULL;
              Cons* iter_002 = parent->uses->the_cons_list;

              while (!nilP(iter_002)) {
                {
                  parentusees = ((Module*)(iter_002->value));
                  iter_002 = iter_002->rest;
                }
                usees->insert_new(parentusees);
                parentusees->used_by->insert_new(module);
              }
            }
          }
        }
        usees->reverse();
      }
    }
    else if (usees->memberP(module)) {
      usees->remove(module);
    }
    else {
    }
  }
}

void uninherit_used_modules(Module* module) {
  { List* usees = module->uses;

    if (usees->emptyP()) {
      usees->push(module);
    }
    else if (string_search(module->stringified_options, ":USES ", 0) == NULL_INTEGER) {
      { Module* usee = NULL;
        Cons* iter_001 = usees->the_cons_list;

        while (!nilP(iter_001)) {
          {
            usee = ((Module*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          usee->used_by->remove(module);
        }
      }
      usees->clear();
    }
  }
}

Cons* read_OshadowedsurrogatesO() {
  return (oSHADOWEDSURROGATESo);
}

Cons* write_OshadowedsurrogatesO(Cons* value) {
  oSHADOWEDSURROGATESo = value;
  return (value);
}

void finalize_module(Module* self) {
  inherit_supercontexts(self);
  inherit_used_modules(self);
  oCONTEXT_NUMBER_COUNTERo = oCONTEXT_NUMBER_COUNTERo + 2;
  self->context_number = oCONTEXT_NUMBER_COUNTERo;
  self->cardinal_module = ((self->parent_module() == NULL) ? ((Module*)(self)) : ((Module*)(self->parent_module()->cardinal_module)));
  self->symbol_offset_table = new_string_to_integer_hash_table();
  self->surrogate_offset_table = new_string_to_integer_hash_table();
  if (cardinal_moduleP(self)) {
    self->indexical_offset_table = new_string_to_integer_hash_table();
  }
  if (oSHADOWEDSURROGATESo->non_emptyP()) {
    set_dynamic_slot_value(self, SYM_MODULES_SHADOWED_SURROGATES, new_list(), NULL);
    { Module* old_OmoduleO_001 = oMODULEo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oMODULEo = self;
            { Symbol* sym = NULL;
              Cons* iter_001 = oSHADOWEDSURROGATESo;

              while (!nilP(iter_001)) {
                {
                  sym = ((Symbol*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                self->shadowed_surrogates_reader()->insert_last(shadow_surrogate(sym->symbol_name));
              }
            }
            oMODULEo = old_OmoduleO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oMODULEo = old_OmoduleO_001;
          resignal();
        }
      }
    }
  }
}

void finalize_world(World* self) {
  { Context* parentcontext = self->parent_context;

    self->all_super_contexts = cons(parentcontext, parentcontext->all_super_contexts);
    oCONTEXT_NUMBER_COUNTERo = oCONTEXT_NUMBER_COUNTERo + 2;
    self->context_number = oCONTEXT_NUMBER_COUNTERo;
  }
}

void Module::unfinalize_module() {
  { Module* self = this;

    uninherit_supercontexts(self);
    uninherit_used_modules(self);
    if (cardinal_moduleP(self)) {
      oROOT_MODULEo->child_contexts->remove(self);
    }
    else {
      { Module* parent = NULL;
        Cons* iter_001 = self->parent_modules->the_cons_list;

        while (!nilP(iter_001)) {
          {
            parent = ((Module*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          parent->child_contexts->remove(self);
        }
      }
    }
    self->parent_modules->clear();
    self->context_number = self->context_number - 1;
    self->module_full_name = NULL;
  }
}

void World::unfinalize_world() {
  { World* self = this;

    self->all_super_contexts->free_cons();
    self->parent_context->child_contexts->remove(self);
    self->context_number = self->context_number - 1;
    self->all_super_contexts = NULL;
    self->parent_context = NULL;
  }
}

void destroy_module(Module* self) {
  // Destroy the module 'self', and recursively destroy
  // all contexts that inherit 'self'.
  if ((self == oROOT_MODULEo) ||
      (self == oSTELLA_MODULEo)) {
    cerr << "Can't destroy the root module or the STELLA module.";
    return;
  }
  { Context* child = NULL;
    Cons* iter_001 = self->child_contexts->copy()->the_cons_list;

    while (!nilP(iter_001)) {
      {
        child = ((Context*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      child->destroy_context();
    }
  }
  { Module* parentmodule = self->parent_module();

    if (parentmodule == NULL) {
      parentmodule = self->cardinal_module;
    }
    if (parentmodule == NULL) {
      parentmodule = oSTELLA_MODULEo;
    }
    self->unfinalize_module();
    if (self == oMODULEo) {
      parentmodule->change_module();
    }
  }
}

void destroy_world(World* self) {
  if (self->child_contexts->non_emptyP()) {
    { World* child = NULL;
      Cons* iter_001 = self->child_contexts->the_cons_list;

      while (!nilP(iter_001)) {
        {
          child = ((World*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        destroy_world(child);
      }
    }
  }
  self->unfinalize_world();
  if (self == oCONTEXTo) {
    oCONTEXTo = self->parent_context;
  }
}

void Module::destroy_context() {
  // Destroy the context 'self', and recursively destroy
  // all contexts that inherit 'self'.
  { Module* self = this;

    destroy_module(self);
  }
}

void World::destroy_context() {
  // Destroy the context 'self', and recursively destroy
  // all contexts that inherit 'self'.
  { World* self = this;

    destroy_world(self);
  }
}

void string_destroy_context(char* self) {
  // Destroy the context 'self', and recursively destroy
  // all contexts that inherit 'self'.
  { Context* context = get_context(self, TRUE);

    if (!(context == NULL)) {
      context->destroy_context();
    }
  }
}

void Context::destroy_context() {
  // Make the translator happy.
  { Context* self = this;

  }
}

void link_to_parent_module(Module* self, Module* parent, boolean insert_firstP) {
  if (!(parent == oROOT_MODULEo)) {
    if (insert_firstP) {
      self->parent_modules->insert(parent);
    }
    else {
      self->parent_modules->insert_last(parent);
    }
  }
  parent->child_contexts->insert(self);
}

void incorporate_module_name(Module* module, char* name) {
  { Module* parentmodule = NULL;
    char* barename = NULL;

    if (qualified_nameP(name)) {
      {
        parentmodule = compute_module_and_bare_name(name, barename);
        if (parentmodule == NULL) {
          cerr << "Bad path name:  " << "`" << name << "'" << " when defining the module " << "`" << barename << "'";
          return;
        }
        link_to_parent_module(module, parentmodule, TRUE);
      }
    }
    else {
      {
        parentmodule = ((Module*)(module->parent_modules->first()));
        if (parentmodule == NULL) {
          parentmodule = oROOT_MODULEo;
        }
        barename = name;
      }
    }
    module->module_name = barename;
    module->module_full_name = compute_full_name("", module);
  }
}

void incorporate_includes_modules(Module* module, Object* includees) {
  { Object* includees_001 = includees;

    if (consP(includees)) {
      { Cons* includees = NULL;

        includees = ((Cons*)(includees_001));
        { Object* name = NULL;
          Cons* iter_001 = includees;

          while (!nilP(iter_001)) {
            {
              name = iter_001->value;
              iter_001 = iter_001->rest;
            }
            incorporate_includes_modules(module, name);
          }
        }
      }
    }
    else if (stringP(includees)) {
      { String_Wrapper* includees = NULL;

        includees = ((String_Wrapper*)(includees_001));
        { Module* includeemodule = string_get_module(includees->wrapper_value, TRUE);

          if (includeemodule != NULL) {
            module->parent_modules->insert_last(includeemodule);
            includeemodule->child_contexts->insert(module);
          }
        }
      }
    }
    else if (symbolP(includees)) {
      { Symbol* includees = NULL;

        includees = ((Symbol*)(includees_001));
        { Module* includeemodule = string_get_module(includees->symbol_name, TRUE);

          if (includeemodule != NULL) {
            module->parent_modules->insert_last(includeemodule);
            includeemodule->child_contexts->insert(module);
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
                cout << endl << " " << "Illegal argument to ':includes' option" << "`" << de_uglify_parse_tree(includees) << "'" << "." << endl;
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
  }
}

void incorporate_uses_modules(Module* module, Object* usees) {
  { Object* usees_001 = usees;

    if (consP(usees)) {
      { Cons* usees = NULL;

        usees = ((Cons*)(usees_001));
        { Object* name = NULL;
          Cons* iter_001 = usees;

          while (!nilP(iter_001)) {
            {
              name = iter_001->value;
              iter_001 = iter_001->rest;
            }
            incorporate_uses_modules(module, name);
          }
        }
        if (module->uses->emptyP()) {
          module->uses->insert(module);
        }
      }
    }
    else if (stringP(usees)) {
      { String_Wrapper* usees = NULL;

        usees = ((String_Wrapper*)(usees_001));
        { Module* useemodule = string_get_module(usees->wrapper_value, TRUE);

          if (useemodule != NULL) {
            module->uses->insert_last(useemodule);
            useemodule->used_by->insert(module);
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
                cout << endl << " " << "Illegal argument to ':uses' option " << "." << endl;
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
  }
}

void incorporate_module_options(Module* self, Cons* options) {
  { Property_List* self_001 = new_property_list();

    self_001->the_plist = options;
    { Property_List* plist = self_001;

      { Object* value = NULL;
        Object* key = NULL;
        Cons* iter_001 = plist->the_plist;

        while (!nilP(iter_001)) {
          key = iter_001->value;
          {
            value = iter_001->rest->value;
            iter_001 = iter_001->rest->rest;
          }
          { Keyword* test_value_001 = ((Keyword*)(key));

            if (test_value_001 == KWD_MODULES_INCLUDES) {
              incorporate_includes_modules(self, value);
            }
            else if (test_value_001 == KWD_MODULES_USES) {
              incorporate_uses_modules(self, value);
            }
            else if (test_value_001 == KWD_MODULES_SHADOW) {
              oSHADOWEDSURROGATESo = ((Cons*)(value));
            }
            else {
              value = permanent_copy(value);
              { Keyword* test_value_002 = ((Keyword*)(key));

                if (test_value_002 == KWD_MODULES_DOCUMENTATION) {
                  self->documentation = ((String_Wrapper*)(value))->wrapper_value;
                }
                else if (test_value_002 == KWD_MODULES_CASE_SENSITIVEp) {
                  self->case_sensitiveP = value == SYM_MODULES_TRUE;
                }
                else if (test_value_002 == KWD_MODULES_PACKAGE) {
                  self->module_native_package = ((String_Wrapper*)(value))->wrapper_value;
                }
                else if (test_value_002 == KWD_MODULES_REQUIRES) {
                  self->requires = ((List*)(value));
                }
                else if (test_value_002 == KWD_MODULES_DIRECTORY_FILE) {
                  self->directory_file = ((String_Wrapper*)(value))->wrapper_value;
                }
                else if (test_value_002 == KWD_MODULES_CODE_FILES) {
                  self->code_files = ((List*)(value));
                }
                else if (test_value_002 == KWD_MODULES_DEFINITIONS_FILE) {
                  self->definitions_file = ((String_Wrapper*)(value))->wrapper_value;
                }
                else {
                  if (!(run_option_handlerP(self, ((Keyword*)(key)), value))) {
                    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

                      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                        oEXCEPTIONHANDLERADDRESSo = NULL;
                        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                          {
                            oPRINTREADABLYpo = TRUE;
                            signal_translation_warning();
                            if (!(suppress_warningsP())) {
                              print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                              cout << endl << " " << "Skipping invalid module option: " << "`" << de_uglify_parse_tree(key) << "'" << "." << endl;
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
                }
              }
            }
          }
        }
      }
      plist->free();
    }
  }
}

void undefine_module(Module* oldmodule, Module* newmodule) {
  cout << "Redefining the module " << "`" << oldmodule->context_name() << "'" << endl;
  if (oSUBCONTEXT_REVISION_POLICYo == KWD_MODULES_DESTROY) {
    oldmodule->destroy_context();
    return;
  }
  else if (oSUBCONTEXT_REVISION_POLICYo == KWD_MODULES_PRESERVE) {
  }
  else if (oSUBCONTEXT_REVISION_POLICYo == KWD_MODULES_CLEAR) {
    { Context* c = NULL;
      All_Purpose_Iterator* iter_001 = all_subcontexts(oldmodule, KWD_MODULES_PREORDER);

      while (iter_001->nextP()) {
        {
          c = ((Context*)(iter_001->value));
        }
        clear_context(c);
      }
    }
  }
  else {
    cerr << "`" << oSUBCONTEXT_REVISION_POLICYo << "'" << " is not a valid case option";
  }
  { Module* p = NULL;
    Cons* iter_002 = oldmodule->parent_modules->the_cons_list;

    while (!nilP(iter_002)) {
      {
        p = ((Module*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      p->child_contexts->remove(oldmodule);
    }
  }
  { Context* c = NULL;
    Cons* iter_003 = oldmodule->child_contexts->the_cons_list;

    while (!nilP(iter_003)) {
      {
        c = ((Context*)(iter_003->value));
        iter_003 = iter_003->rest;
      }
      { Context* c_001 = c;

        if (taxonomy_isaP(c, SGT_MODULES_MODULE)) {
          { Module* c = NULL;

            c = ((Module*)(c_001));
            c->parent_modules->the_cons_list->substitute(newmodule, oldmodule);
          }
        }
        else if (taxonomy_isaP(c, SGT_MODULES_WORLD)) {
          { World* c = NULL;

            c = ((World*)(c_001));
            c->parent_context = newmodule;
          }
        }
        else {
          cerr << "`" << c << "'" << " is not a valid case option";
        }
      }
    }
  }
  newmodule->child_contexts->the_cons_list = oldmodule->child_contexts->the_cons_list;
  oldmodule->child_contexts->the_cons_list = NIL;
  oldmodule->free();
}

Module* define_module(char* name, Cons* options) {
  // Define or redefine a module named 'name' having the
  // options 'options'.  Return the new module.
  { Cons* old_OshadowedsurrogatesO_001 = oSHADOWEDSURROGATESo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oSHADOWEDSURROGATESo = NIL;
          { Module* module = NULL;
            char* stringifiedoptions = stringify(options);
            Module* oldmodule = NULL;

            oldmodule = string_get_module(name, FALSE);
            if ((oldmodule != NULL) &&
                string_eqlP(stringifiedoptions, oldmodule->stringified_options)) {
              { 
                oSHADOWEDSURROGATESo = old_OshadowedsurrogatesO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (oldmodule);
              }
            }
            module = new_module();
            if (oldmodule != NULL) {
              undefine_module(oldmodule, module);
            }
            module->stringified_options = stringifiedoptions;
            incorporate_module_options(module, options);
            incorporate_module_name(module, name);
            module->base_module = module;
            { Module* parent = NULL;
              Cons* iter_001 = module->parent_modules->the_cons_list;

              while (!nilP(iter_001)) {
                {
                  parent = ((Module*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                { 
                  { Context* value_001 = NULL;

                    { Context* child = NULL;
                      Cons* iter_002 = parent->child_contexts->the_cons_list;

                      while (!nilP(iter_002)) {
                        {
                          child = ((Context*)(iter_002->value));
                          iter_002 = iter_002->rest;
                        }
                        if ((!(child == module)) &&
                            (isaP(child, SGT_MODULES_MODULE) &&
                             string_eqlP(((Module*)(child))->module_full_name, module->module_full_name))) {
                          value_001 = child;
                          {
                            break;
                          }
                        }
                      }
                    }
                    oldmodule = ((Module*)(value_001));
                  }
                  if (oldmodule != NULL) {
                    undefine_module(oldmodule, module);
                    {
                      break;
                    }
                  }
                }
              }
            }
            finalize_module(module);
            { 
              oSHADOWEDSURROGATESo = old_OshadowedsurrogatesO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (module);
            }
          }
          oSHADOWEDSURROGATESo = old_OshadowedsurrogatesO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oSHADOWEDSURROGATESo = old_OshadowedsurrogatesO_001;
        resignal();
      }
    }
  }
}

Module* define_module_from_stringified_source(char* name, char* stringifiedoptions) {
  return (define_module(name, ((Cons*)(unstringify(stringifiedoptions)))));
}

Cons* yield_define_module(Module* module) {
  return (listO(3, SYM_MODULES_DEFINE_MODULE_FROM_STRINGIFIED_SOURCE, string_wrap_literal(module->module_full_name), cons(yield_string_constant_tree(module->stringified_options), NIL)));
}

void defmodule(Object* name, Cons* options) {
  // Define (or redefine) a module named `name'.
  // The accepted syntax is:
  // 	 
  //   (defmodule <module-name>
  //      [:documentation <docstring>]
  //      [:includes {<module-name> | (<module-name>*)}]
  //      [:uses {<module-name> | (<module-name>*)}]
  //      [:package <package-name-string>]
  //      [:case-sensitive? {TRUE | FALSE}]
  //      [:shadow (<symbol>*)])
  //      [<other-options>*])
  // 	
  // `name' can be a string or a symbol.  The list of modules specified in the
  // `:includes' option plus (if supplied) the parent in the path used for `name'
  // become the new module's parents.  If no `:uses' option was supplied, the
  // new module will use the `STELLA' module by default, otherwise, it will use
  // the set of specified modules.  `:package' specifies the name of a native
  // package or name space in which symbols of the module should be allocated
  // when they get translated into a native language such as Lisp or C++.
  // By default, Lisp symbols are allocated in the `STELLA' package, and C++ names
  // are translated without any prefixes.  If `:case-sensitive?' is supplied
  // as TRUE, symbols in the module will be interned case-sensitively, otherwise
  // (the default), they will be converted to uppercase before they get interned.
  // Modules can shadow definitions of functions and classes inherited from
  // parents or used modules.  Shadowing is done automatically, but generates
  // a warning unless the shadowed type or function name is listed in the
  // `:shadow' option of the module definition.  CAUTION: The implementation of
  // shadowing is still somewhat fragile.
  // 
  // Examples:
  // 	 
  //   (defmodule "/PL-USER"
  //     :uses ("LOGIC" "STELLA")
  //     :package "PL-USER")
  // 
  //   (defmodule /PL-USER/GENEALOGY)
  // 	
  // Modules include objects from other modules via two separate mechanisms:
  // (1) they inherit from their parents specified via the `:includes' option
  // and/or a fully qualified module name, and (2) they inherit from used
  // modules specified via the `:uses' option.  The main difference between
  // the two mechanisms is that inheritance from parents is transitive, while
  // uses-links are only followed one level deep.  I.e., a module A that uses
  // B will see all objects of B (and any of B's parents) but not see anything
  // from modules used by B.  Another difference is that only objects declared
  // as public can be inherited via uses-links (this is not yet enforced).
  // Note that - contrary to Lisp - there are separate name spaces for classes,
  // functions, and variables.  For example, a module could inherit the class
  // `CONS' from the `STELLA' module, but shadow the function of the same name.
  // CAUTION: The implementation of this semantics has not yet been fully
  // completed.
  { char* modulename = coerce_to_module_name(name, TRUE);

    if (modulename != NULL) {
      define_module(modulename, options);
    }
  }
}

void defmodule_evaluator_wrapper(Cons* arguments) {
  defmodule(arguments->value, ((Cons*)(arguments->rest)));
}

World* create_world(Context* parentcontext, char* name) {
  // Create a new world below the world or module 'parentContext'.
  // Optionally, specify a name.
  { World* world = new_world();

    if (name != NULL) {
      set_dynamic_slot_value(world, SYM_MODULES_WORLD_NAME, wrap_string(name), NULL_STRING_WRAPPER);
      { boolean foundP_001 = FALSE;

        { Context* sibling = NULL;
          Cons* iter_001 = parentcontext->child_contexts->the_cons_list;

          while (!nilP(iter_001)) {
            {
              sibling = ((Context*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            if (string_eqlP(sibling->context_name(), name)) {
              foundP_001 = TRUE;
              break;
            }
          }
        }
        if (foundP_001) {
          cerr << "Can't create a world named " << "`" << name << "'" << " because a sibling already has that name.";
          return (NULL);
        }
      }
    }
    world->parent_context = parentcontext;
    parentcontext->child_contexts->insert(world);
    world->base_module = parentcontext->base_module;
    finalize_world(world);
    return (world);
  }
}

World* push_world() {
  // Spawn a new world that is a child of the current context,
  // and change the current context to the new world.
  return (((World*)(oCONTEXTo = create_world(oCONTEXTo, NULL))));
}

Context* pop_world() {
  // Destroy the current world and change the current
  // context to be its parent.  Return the current context. Nothing happens
  // if there is no current world.
  if (!(oCONTEXTo == oMODULEo)) {
    { World* world = ((World*)(oCONTEXTo));

      oCONTEXTo = world->parent_context;
      destroy_world(world);
    }
  }
  return (oCONTEXTo);
}

All_Purpose_Iterator* all_subcontexts(Context* context, Keyword* traversal) {
  // Return an iterator that generates all subcontexts of
  // 'self' (not including 'self') in the order specified by 'traversal' (one
  // of :preorder, :inorder, or :postorder).
  { All_Purpose_Iterator* contextsiterator = new_all_purpose_iterator();
    Cons* subcontexts = NIL;

    { Context* child = NULL;
      Cons* iter_001 = context->child_contexts->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          child = ((Context*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(child, NIL);
            if (nilP(subcontexts)) {
              subcontexts = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(subcontexts, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(child, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    if (traversal == KWD_MODULES_POSTORDER) {
      subcontexts = subcontexts->reverse();
    }
    contextsiterator->iterator_cons_list = subcontexts;
    contextsiterator->iterator_object = traversal;
    contextsiterator->iterator_next_code = ((cpp_function_code)(&all_subcontexts_nextP));
    return (contextsiterator);
  }
}

boolean all_subcontexts_nextP(All_Purpose_Iterator* self) {
  { Keyword* traversal = ((Keyword*)(self->iterator_object));
    Cons* remainingcontexts = self->iterator_cons_list;
    Context* thiscontext = NULL;
    Cons* subcontexts = NIL;

    if (remainingcontexts->emptyP()) {
      self->value = NULL;
      return (FALSE);
    }
    thiscontext = ((Context*)(remainingcontexts->first()));
    { Cons* headcons = remainingcontexts;

      remainingcontexts = remainingcontexts->rest;
      headcons->free_cons();
    }
    { Context* child = NULL;
      Cons* iter_001 = thiscontext->child_contexts->the_cons_list;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          child = ((Context*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if ((child->parent_contexts()->pop() == thiscontext) ||
            child->parent_contexts()->emptyP()) {
          if (collect_001 == NULL) {
            {
              collect_001 = cons(child, NIL);
              if (nilP(subcontexts)) {
                subcontexts = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(subcontexts, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = cons(child, NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
    }
    if (subcontexts->emptyP()) {
      self->iterator_cons_list = remainingcontexts;
    }
    else {
      if (traversal == KWD_MODULES_PREORDER) {
        last_cons(subcontexts)->rest = remainingcontexts;
        self->iterator_cons_list = subcontexts;
      }
      else if (traversal == KWD_MODULES_POSTORDER) {
        subcontexts = subcontexts->reverse();
        last_cons(subcontexts)->rest = remainingcontexts;
        self->iterator_cons_list = subcontexts;
      }
      else if (traversal == KWD_MODULES_INORDER) {
        if (remainingcontexts->emptyP()) {
          self->iterator_cons_list = subcontexts;
        }
        else {
          last_cons(remainingcontexts)->rest = subcontexts;
          self->iterator_cons_list = remainingcontexts;
        }
      }
      else {
        cerr << "`" << traversal << "'" << " is not a valid case option";
      }
    }
    self->value = thiscontext;
    return (TRUE);
  }
}

Iterator* all_contexts() {
  // Return an iterator that generates all contexts.
  { All_Purpose_Iterator* iterator = all_subcontexts(oROOT_MODULEo, KWD_MODULES_PREORDER);

    free_cons_list(iterator->iterator_cons_list);
    iterator->iterator_cons_list = cons(oROOT_MODULEo, NIL);
    return (iterator);
  }
}

boolean filter_moduleP(Object* self, All_Purpose_Iterator* iterator) {
  return (self->primary_type() == SGT_MODULES_MODULE);
}

Iterator* all_modules() {
  // Return an iterator that generates all modules.
  { Iterator* contextsiterator = all_contexts();
    All_Purpose_Iterator* iterator = new_all_purpose_iterator();

    iterator->first_iterationP = TRUE;
    iterator->iterator_nested_iterator = contextsiterator;
    iterator->iterator_next_code = ((cpp_function_code)(&filtered_nested_iterator_nextP));
    iterator->iterator_filter_code = ((cpp_function_code)(&filter_moduleP));
    return (iterator);
  }
}

Iterator* visible_modules(Module* from) {
  // Return an iterator that generates all modules visible from module `from'.
  // The generated modules are generated from most- to least-specific and 
  // will start with the module `from'.
  { Cons* visiblemodules = NIL;

    if (from == NULL) {
      from = oMODULEo;
    }
    visiblemodules = cons(from, visiblemodules);
    { Context* super = NULL;
      Cons* iter_001 = from->all_super_contexts;

      while (!nilP(iter_001)) {
        {
          super = ((Context*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        visiblemodules = cons(super, visiblemodules);
      }
    }
    { Module* usee = NULL;
      Cons* iter_002 = from->uses->the_cons_list;

      while (!nilP(iter_002)) {
        {
          usee = ((Module*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        visiblemodules = cons(usee, visiblemodules);
        { Context* useesuper = NULL;
          Cons* iter_003 = usee->all_super_contexts;

          while (!nilP(iter_003)) {
            {
              useesuper = ((Context*)(iter_003->value));
              iter_003 = iter_003->rest;
            }
            if (!visiblemodules->membP(useesuper)) {
              visiblemodules = cons(useesuper, visiblemodules);
            }
          }
        }
      }
    }
    return (visiblemodules->reverse()->allocate_destructive_list_iterator());
  }
}

boolean cardinal_moduleP(Module* self) {
  return (self->cardinal_module == self);
}

boolean visible_fromP(Module* viewedmodule, Module* frommodule) {
  { boolean test_value_001 = FALSE;

    if (viewedmodule == frommodule) {
      test_value_001 = TRUE;
    }
    else {
      if (frommodule->all_super_contexts->memberP(viewedmodule)) {
        test_value_001 = TRUE;
      }
      else {
        { boolean foundP_001 = FALSE;

          { Module* usesmodule = NULL;
            Cons* iter_001 = frommodule->uses->the_cons_list;

            while (!nilP(iter_001)) {
              {
                usesmodule = ((Module*)(iter_001->value));
                iter_001 = iter_001->rest;
              }
              if ((viewedmodule == usesmodule) ||
                  usesmodule->all_super_contexts->memberP(viewedmodule)) {
                foundP_001 = TRUE;
                break;
              }
            }
          }
          test_value_001 = foundP_001;
        }
      }
    }
    { boolean value_001 = test_value_001;

      return (value_001);
    }
  }
}

void clear_one_context(Context* self) {
  { Context* self_001 = self;

    if (taxonomy_isaP(self, SGT_MODULES_MODULE)) {
      { Module* self = NULL;

        self = ((Module*)(self_001));
        if (!self->clearableP_reader()) {
          cerr << "Module " << "`" << self->module_full_name << "'" << " cannot be cleared!";
          return;
        }
        run_hooks(oCLEAR_MODULE_HOOKSo, self);
        { Method_Slot* function = NULL;
          Iterator* iter_001 = all_functions(self, TRUE);

          while (iter_001->nextP()) {
            {
              function = ((Method_Slot*)(iter_001->value));
            }
            destroy_function(function);
          }
        }
        { Global_Variable* variable = NULL;
          Iterator* iter_002 = all_variables(self, TRUE);

          while (iter_002->nextP()) {
            {
              variable = ((Global_Variable*)(iter_002->value));
            }
            destroy_variable(variable);
          }
        }
        { Class* renamed_Class = NULL;
          Iterator* iter_003 = all_classes(self, TRUE);

          while (iter_003->nextP()) {
            {
              renamed_Class = ((Class*)(iter_003->value));
            }
            renamed_Class->destroy_class();
          }
        }
        { Symbol* symbol = NULL;
          Iterator* iter_004 = all_symbols(self, TRUE);

          while (iter_004->nextP()) {
            {
              symbol = ((Symbol*)(iter_004->value));
            }
            unintern_symbol(symbol);
          }
        }
        { Surrogate* surrogate = NULL;
          Iterator* iter_005 = all_surrogates(self, TRUE);

          while (iter_005->nextP()) {
            {
              surrogate = ((Surrogate*)(iter_005->value));
            }
            unintern_surrogate(surrogate);
          }
        }
        { Module* old_OmoduleO_001 = oMODULEo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oMODULEo = self;
                { List_Iterator* it = ((List_Iterator*)(self->shadowed_surrogates_reader()->allocate_iterator()));

                  while (it->nextP()) {
                    it->value_setter(shadow_surrogate(((Surrogate*)(it->value))->symbol_name));
                  }
                }
                oMODULEo = old_OmoduleO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oMODULEo = old_OmoduleO_001;
              resignal();
            }
          }
        }
      }
    }
    else {
    }
  }
}

void clear_context(Context* self) {
  // Destroy all objects belonging to 'self' or any of its subcontexts.
  { Context* child = NULL;
    Cons* iter_001 = self->child_contexts->the_cons_list;

    while (!nilP(iter_001)) {
      {
        child = ((Context*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      clear_context(child);
    }
  }
  clear_one_context(self);
}

void clear_module(Cons* name) {
  // Destroy all objects belonging to module `name' or any of its children.
  // If no `name' is supplied, the current module will be cleared after
  // confirming with the user.  Important modules such as STELLA are protected
  // against accidental clearing.
  { Module* module = coerce_to_module(name->first(), TRUE);

    if (module != NULL) {
      if (name->non_emptyP() ||
          y_or_nP(string_concatenate("Really clear module ", string_concatenate(module->module_full_name, "? ")))) {
        clear_context(module);
      }
    }
  }
}

void clear_module_evaluator_wrapper(Cons* arguments) {
  clear_module(((Cons*)(arguments)));
}

void startup_modules() {
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
            KWD_MODULES_DESTROY = ((Keyword*)(intern_rigid_symbol_wrt_module("DESTROY", NULL, 2)));
            SGT_MODULES_MODULE = ((Surrogate*)(intern_rigid_symbol_wrt_module("MODULE", NULL, 1)));
            SYM_MODULES_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("NAME", NULL, 0)));
            SYM_MODULES_oSHADOWEDSURROGATESo = ((Symbol*)(intern_rigid_symbol_wrt_module("*SHADOWEDSURROGATES*", NULL, 0)));
            SYM_MODULES_SHADOWED_SURROGATES = ((Symbol*)(intern_rigid_symbol_wrt_module("SHADOWED-SURROGATES", NULL, 0)));
            KWD_MODULES_INCLUDES = ((Keyword*)(intern_rigid_symbol_wrt_module("INCLUDES", NULL, 2)));
            KWD_MODULES_USES = ((Keyword*)(intern_rigid_symbol_wrt_module("USES", NULL, 2)));
            KWD_MODULES_SHADOW = ((Keyword*)(intern_rigid_symbol_wrt_module("SHADOW", NULL, 2)));
            KWD_MODULES_DOCUMENTATION = ((Keyword*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 2)));
            KWD_MODULES_CASE_SENSITIVEp = ((Keyword*)(intern_rigid_symbol_wrt_module("CASE-SENSITIVE?", NULL, 2)));
            SYM_MODULES_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            KWD_MODULES_PACKAGE = ((Keyword*)(intern_rigid_symbol_wrt_module("PACKAGE", NULL, 2)));
            KWD_MODULES_REQUIRES = ((Keyword*)(intern_rigid_symbol_wrt_module("REQUIRES", NULL, 2)));
            KWD_MODULES_DIRECTORY_FILE = ((Keyword*)(intern_rigid_symbol_wrt_module("DIRECTORY-FILE", NULL, 2)));
            KWD_MODULES_CODE_FILES = ((Keyword*)(intern_rigid_symbol_wrt_module("CODE-FILES", NULL, 2)));
            KWD_MODULES_DEFINITIONS_FILE = ((Keyword*)(intern_rigid_symbol_wrt_module("DEFINITIONS-FILE", NULL, 2)));
            KWD_MODULES_PRESERVE = ((Keyword*)(intern_rigid_symbol_wrt_module("PRESERVE", NULL, 2)));
            KWD_MODULES_CLEAR = ((Keyword*)(intern_rigid_symbol_wrt_module("CLEAR", NULL, 2)));
            KWD_MODULES_PREORDER = ((Keyword*)(intern_rigid_symbol_wrt_module("PREORDER", NULL, 2)));
            SGT_MODULES_WORLD = ((Surrogate*)(intern_rigid_symbol_wrt_module("WORLD", NULL, 1)));
            SYM_MODULES_DEFINE_MODULE_FROM_STRINGIFIED_SOURCE = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINE-MODULE-FROM-STRINGIFIED-SOURCE", NULL, 0)));
            SYM_MODULES_EVALUATOR_WRAPPER_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("EVALUATOR-WRAPPER-CODE", NULL, 0)));
            SYM_MODULES_WORLD_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("WORLD-NAME", NULL, 0)));
            KWD_MODULES_POSTORDER = ((Keyword*)(intern_rigid_symbol_wrt_module("POSTORDER", NULL, 2)));
            KWD_MODULES_INORDER = ((Keyword*)(intern_rigid_symbol_wrt_module("INORDER", NULL, 2)));
            SYM_MODULES_CLEARABLEp = ((Symbol*)(intern_rigid_symbol_wrt_module("CLEARABLE?", NULL, 0)));
          }
          if (current_startup_time_phaseP(4)) {
            oSUBCONTEXT_REVISION_POLICYo = KWD_MODULES_DESTROY;
          }
          if (current_startup_time_phaseP(5)) {
            define_stella_type_from_stringified_source("(DEFTYPE NAME OBJECT)");
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("PARENT-CONTEXTS", "CONTEXT", "(DEFMETHOD (PARENT-CONTEXTS (ITERATOR OF CONTEXT)) ((SELF CONTEXT)))");

              method->method_code = ((cpp_method_code)(&Context::parent_contexts));
            }
            { Method_Slot* method = define_method_from_stringified_source("PARENT-CONTEXTS", "MODULE", "(DEFMETHOD (PARENT-CONTEXTS (ITERATOR OF CONTEXT)) ((SELF MODULE)) :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Module::parent_contexts));
            }
            { Method_Slot* method = define_method_from_stringified_source("PARENT-CONTEXTS", "WORLD", "(DEFMETHOD (PARENT-CONTEXTS (ITERATOR OF CONTEXT)) ((SELF WORLD)) :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&World::parent_contexts));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-CONTEXT-OR-MODULE-FROM-PATHNAME", "STRING", "(DEFUN (COMPUTE-CONTEXT-OR-MODULE-FROM-PATHNAME CONTEXT INTEGER) ((PATHNAME STRING) (MODULE? BOOLEAN) (SYMBOLNAME? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&compute_context_or_module_from_pathname));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPONENT-MATCH?", "STRING", "(DEFUN (COMPONENT-MATCH? BOOLEAN) ((COMPONENT STRING) (STRING STRING) (START INTEGER) (END INTEGER)))");

              method->function_code = ((cpp_function_code)(&component_matchP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-MODULE-AND-BARE-NAME", "STRING", "(DEFUN (COMPUTE-MODULE-AND-BARE-NAME MODULE STRING) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&compute_module_and_bare_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERN-QUALIFIED-NAME", "STRING", "(DEFUN (INTERN-QUALIFIED-NAME GENERALIZED-SYMBOL) ((NAME STRING)))");

              method->function_code = ((cpp_function_code)(&intern_qualified_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-CONTEXT", "STRING", "(DEFUN (GET-CONTEXT CONTEXT) ((PATHNAME STRING) (WARN? BOOLEAN)) :DOCUMENTATION \"Return the context located at 'pathName', or NULL\nif no such context exists.  If 'warn?' is TRUE, print a warning\nmessage if no context is found.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&get_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("SCAN-FOR-MODULE", "STRING", "(DEFMETHOD (SCAN-FOR-MODULE MODULE) ((NAME STRING) (VANTAGEPOINT MODULE)))");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-MODULE", "STRING", "(DEFMETHOD (GET-MODULE MODULE) ((PATHNAME STRING) (WARN? BOOLEAN)) :DOCUMENTATION \"Return the module located at 'pathName', or NULL\nif no such module exists.  The search looks at ancestors and top-most\n (cardinal) modules.  If 'warn?' is TRUE, print a warning\nmessage if no module is found.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("COERCE-TO-MODULE-NAME", "OBJECT", "(DEFUN (COERCE-TO-MODULE-NAME STRING) ((NAMESPEC NAME) (WARN? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&coerce_to_module_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("COERCE-TO-MODULE", "OBJECT", "(DEFUN (COERCE-TO-MODULE MODULE) ((OBJECT OBJECT) (WARN? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&coerce_to_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-OR-CREATE-MODULE", "STRING", "(DEFUN (FIND-OR-CREATE-MODULE MODULE) ((PATHNAME STRING)) :DOCUMENTATION \"Return a module located at `pathname' if one exists,\n  otherwise create one\")");

              method->function_code = ((cpp_function_code)(&find_or_create_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHANGE-CURRENT-MODULE", "MODULE", "(DEFUN (CHANGE-CURRENT-MODULE MODULE) ((MODULE MODULE)))");

              method->function_code = ((cpp_function_code)(&change_current_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHANGE-CURRENT-CONTEXT", "CONTEXT", "(DEFUN (CHANGE-CURRENT-CONTEXT CONTEXT) ((CONTEXT CONTEXT)))");

              method->function_code = ((cpp_function_code)(&change_current_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHANGE-CONTEXT", "CONTEXT", "(DEFMETHOD (CHANGE-CONTEXT CONTEXT) ((CONTEXT CONTEXT)) :DOCUMENTATION \"Change the current context to be the context\n'context'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Context::change_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHANGE-CONTEXT", "STRING", "(DEFMETHOD (CHANGE-CONTEXT CONTEXT) ((CONTEXTNAME STRING)) :DOCUMENTATION \"Change the current context to be the context named\n'contextName'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHANGE-MODULE", "MODULE", "(DEFMETHOD (CHANGE-MODULE MODULE) ((MODULE MODULE)) :DOCUMENTATION \"Change the current module to be the module\n'module'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Module::change_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHANGE-MODULE", "STRING", "(DEFMETHOD (CHANGE-MODULE MODULE) ((MODULENAME STRING)) :DOCUMENTATION \"Change the current module to be the module named\n'moduleName'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("MULTIPLE-PARENTS?", "MODULE", "(DEFMETHOD (MULTIPLE-PARENTS? BOOLEAN) ((MODULE MODULE)) :DOCUMENTATION \"Return TRUE if 'module' has more than one parent.\")");

              method->method_code = ((cpp_method_code)(&Module::multiple_parentsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("NORMALIZE-PARENT-MODULES", "MODULE", "(DEFUN NORMALIZE-PARENT-MODULES ((SELF MODULE)))");

              method->function_code = ((cpp_function_code)(&normalize_parent_modules));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-SUPERCONTEXTS", "MODULE", "(DEFUN INHERIT-SUPERCONTEXTS ((MODULE MODULE)))");

              method->function_code = ((cpp_function_code)(&inherit_supercontexts));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNINHERIT-SUPERCONTEXTS", "MODULE", "(DEFUN UNINHERIT-SUPERCONTEXTS ((MODULE MODULE)))");

              method->function_code = ((cpp_function_code)(&uninherit_supercontexts));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-USED-MODULES", "MODULE", "(DEFUN INHERIT-USED-MODULES ((MODULE MODULE)))");

              method->function_code = ((cpp_function_code)(&inherit_used_modules));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNINHERIT-USED-MODULES", "MODULE", "(DEFUN UNINHERIT-USED-MODULES ((MODULE MODULE)))");

              method->function_code = ((cpp_function_code)(&uninherit_used_modules));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-MODULE", "MODULE", "(DEFUN FINALIZE-MODULE ((SELF MODULE)))");

              method->function_code = ((cpp_function_code)(&finalize_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINALIZE-WORLD", "WORLD", "(DEFUN FINALIZE-WORLD ((SELF WORLD)))");

              method->function_code = ((cpp_function_code)(&finalize_world));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNFINALIZE-MODULE", "MODULE", "(DEFMETHOD UNFINALIZE-MODULE ((SELF MODULE)))");

              method->method_code = ((cpp_method_code)(&Module::unfinalize_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNFINALIZE-WORLD", "WORLD", "(DEFMETHOD UNFINALIZE-WORLD ((SELF WORLD)))");

              method->method_code = ((cpp_method_code)(&World::unfinalize_world));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-MODULE", "MODULE", "(DEFUN DESTROY-MODULE ((SELF MODULE)) :DOCUMENTATION \"Destroy the module 'self', and recursively destroy\nall contexts that inherit 'self'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&destroy_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-WORLD", "WORLD", "(DEFUN DESTROY-WORLD ((SELF WORLD)) :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&destroy_world));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-CONTEXT", "MODULE", "(DEFMETHOD DESTROY-CONTEXT ((SELF MODULE)) :DOCUMENTATION \"Destroy the context 'self', and recursively destroy\nall contexts that inherit 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Module::destroy_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-CONTEXT", "WORLD", "(DEFMETHOD DESTROY-CONTEXT ((SELF WORLD)) :DOCUMENTATION \"Destroy the context 'self', and recursively destroy\nall contexts that inherit 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&World::destroy_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-CONTEXT", "STRING", "(DEFMETHOD DESTROY-CONTEXT ((SELF STRING)) :DOCUMENTATION \"Destroy the context 'self', and recursively destroy\nall contexts that inherit 'self'.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(NULL));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTROY-CONTEXT", "CONTEXT", "(DEFMETHOD DESTROY-CONTEXT ((SELF CONTEXT)) :DOCUMENTATION \"Make the translator happy.\")");

              method->method_code = ((cpp_method_code)(&Context::destroy_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("LINK-TO-PARENT-MODULE", "MODULE", "(DEFUN LINK-TO-PARENT-MODULE ((SELF MODULE) (PARENT MODULE) (INSERT-FIRST? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&link_to_parent_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("INCORPORATE-MODULE-NAME", "MODULE", "(DEFUN INCORPORATE-MODULE-NAME ((MODULE MODULE) (NAME STRING)))");

              method->function_code = ((cpp_function_code)(&incorporate_module_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("INCORPORATE-INCLUDES-MODULES", "MODULE", "(DEFUN INCORPORATE-INCLUDES-MODULES ((MODULE MODULE) (INCLUDEES OBJECT)))");

              method->function_code = ((cpp_function_code)(&incorporate_includes_modules));
            }
            { Method_Slot* method = define_method_from_stringified_source("INCORPORATE-USES-MODULES", "MODULE", "(DEFUN INCORPORATE-USES-MODULES ((MODULE MODULE) (USEES OBJECT)))");

              method->function_code = ((cpp_function_code)(&incorporate_uses_modules));
            }
            { Method_Slot* method = define_method_from_stringified_source("INCORPORATE-MODULE-OPTIONS", "MODULE", "(DEFUN INCORPORATE-MODULE-OPTIONS ((SELF MODULE) (OPTIONS CONS)))");

              method->function_code = ((cpp_function_code)(&incorporate_module_options));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNDEFINE-MODULE", "MODULE", "(DEFUN UNDEFINE-MODULE ((OLDMODULE MODULE) (NEWMODULE MODULE)))");

              method->function_code = ((cpp_function_code)(&undefine_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-MODULE", "STRING", "(DEFUN (DEFINE-MODULE MODULE) ((NAME STRING) (OPTIONS CONS)) :DOCUMENTATION \"Define or redefine a module named 'name' having the\noptions 'options'.  Return the new module.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&define_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-MODULE-FROM-STRINGIFIED-SOURCE", "STRING", "(DEFUN (DEFINE-MODULE-FROM-STRINGIFIED-SOURCE MODULE) ((NAME STRING) (STRINGIFIEDOPTIONS STRING)))");

              method->function_code = ((cpp_function_code)(&define_module_from_stringified_source));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-DEFINE-MODULE", "MODULE", "(DEFUN (YIELD-DEFINE-MODULE CONS) ((MODULE MODULE)))");

              method->function_code = ((cpp_function_code)(&yield_define_module));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFMODULE", "OBJECT", "(DEFUN DEFMODULE ((NAME NAME) |&REST| (OPTIONS OBJECT)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Define (or redefine) a module named `name'.\nThe accepted syntax is:\n	 \n  (defmodule <module-name>\n     [:documentation <docstring>]\n     [:includes {<module-name> | (<module-name>*)}]\n     [:uses {<module-name> | (<module-name>*)}]\n     [:package <package-name-string>]\n     [:case-sensitive? {TRUE | FALSE}]\n     [:shadow (<symbol>*)])\n     [<other-options>*])\n	\n`name' can be a string or a symbol.  The list of modules specified in the\n`:includes' option plus (if supplied) the parent in the path used for `name'\nbecome the new module's parents.  If no `:uses' option was supplied, the\nnew module will use the `STELLA' module by default, otherwise, it will use\nthe set of specified modules.  `:package' specifies the name of a native\npackage or name space in which symbols of the module should be allocated\nwhen they get translated into a native language such as Lisp or C++.\nBy default, Lisp symbols are allocated in the `STELLA' package, and C++ names\nare translated without any prefixes.  If `:case-sensitive?' is supplied\nas TRUE, symbols in the module will be interned case-sensitively, otherwise\n(the default), they will be converted to uppercase before they get interned.\nModules can shadow definitions of functions and classes inherited from\nparents or used modules.  Shadowing is done automatically, but generates\na warning unless the shadowed type or function name is listed in the\n`:shadow' option of the module definition.  CAUTION: The implementation of\nshadowing is still somewhat fragile.\n\nExamples:\n	 \n  (defmodule \\\"/PL-USER\\\"\n    :uses (\\\"LOGIC\\\" \\\"STELLA\\\")\n    :package \\\"PL-USER\\\")\n\n  (defmodule /PL-USER/GENEALOGY)\n	\nModules include objects from other modules via two separate mechanisms:\n(1) they inherit from their parents specified via the `:includes' option\nand/or a fully qualified module name, and (2) they inherit from used\nmodules specified via the `:uses' option.  The main difference between\nthe two mechanisms is that inheritance from parents is transitive, while\nuses-links are only followed one level deep.  I.e., a module A that uses\nB will see all objects of B (and any of B's parents) but not see anything\nfrom modules used by B.  Another difference is that only objects declared\nas public can be inherited via uses-links (this is not yet enforced).\nNote that - contrary to Lisp - there are separate name spaces for classes,\nfunctions, and variables.  For example, a module could inherit the class\n`CONS' from the `STELLA' module, but shadow the function of the same name.\nCAUTION: The implementation of this semantics has not yet been fully\ncompleted.\")");

              method->function_code = ((cpp_function_code)(&defmodule));
              set_dynamic_slot_value(method, SYM_MODULES_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&defmodule_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            define_method_from_stringified_source("IN-MODULE", "OBJECT", "(DEFUN (IN-MODULE MODULE) ((NAME NAME)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :NATIVE? TRUE :DOCUMENTATION \"Change the current module to the module named `name'.\")");
            { Method_Slot* method = define_method_from_stringified_source("CREATE-WORLD", "CONTEXT", "(DEFUN (CREATE-WORLD WORLD) ((PARENTCONTEXT CONTEXT) (NAME STRING)) :DOCUMENTATION \"Create a new world below the world or module 'parentContext'.\nOptionally, specify a name.\" :PUBLIC? TRUE :INLINE FINALIZE-WORLD)");

              method->function_code = ((cpp_function_code)(&create_world));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUSH-WORLD", NULL, "(DEFUN (PUSH-WORLD WORLD) () :DOCUMENTATION \"Spawn a new world that is a child of the current context,\nand change the current context to the new world.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&push_world));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP-WORLD", NULL, "(DEFUN (POP-WORLD CONTEXT) () :DOCUMENTATION \"Destroy the current world and change the current\ncontext to be its parent.  Return the current context. Nothing happens\nif there is no current world.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&pop_world));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-SUBCONTEXTS", "CONTEXT", "(DEFUN (ALL-SUBCONTEXTS (ALL-PURPOSE-ITERATOR OF CONTEXT)) ((CONTEXT CONTEXT) (TRAVERSAL KEYWORD)) :DOCUMENTATION \"Return an iterator that generates all subcontexts of\n'self' (not including 'self') in the order specified by 'traversal' (one\nof :preorder, :inorder, or :postorder).\")");

              method->function_code = ((cpp_function_code)(&all_subcontexts));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-SUBCONTEXTS-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ALL-SUBCONTEXTS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&all_subcontexts_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-CONTEXTS", NULL, "(DEFUN (ALL-CONTEXTS (ITERATOR OF CONTEXT)) () :DOCUMENTATION \"Return an iterator that generates all contexts.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_contexts));
            }
            { Method_Slot* method = define_method_from_stringified_source("FILTER-MODULE?", "OBJECT", "(DEFUN (FILTER-MODULE? BOOLEAN) ((SELF OBJECT) (ITERATOR ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&filter_moduleP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-MODULES", NULL, "(DEFUN (ALL-MODULES (ITERATOR OF MODULE)) () :DOCUMENTATION \"Return an iterator that generates all modules.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&all_modules));
            }
            { Method_Slot* method = define_method_from_stringified_source("VISIBLE-MODULES", "MODULE", "(DEFUN (VISIBLE-MODULES (ITERATOR OF MODULE)) ((FROM MODULE)) :DOCUMENTATION \"Return an iterator that generates all modules visible from module `from'.\nThe generated modules are generated from most- to least-specific and \nwill start with the module `from'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&visible_modules));
            }
            { Method_Slot* method = define_method_from_stringified_source("CARDINAL-MODULE?", "MODULE", "(DEFUN (CARDINAL-MODULE? BOOLEAN) ((SELF MODULE)))");

              method->function_code = ((cpp_function_code)(&cardinal_moduleP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VISIBLE-FROM?", "MODULE", "(DEFUN (VISIBLE-FROM? BOOLEAN) ((VIEWEDMODULE MODULE) (FROMMODULE MODULE)))");

              method->function_code = ((cpp_function_code)(&visible_fromP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-ONE-CONTEXT", "CONTEXT", "(DEFUN CLEAR-ONE-CONTEXT ((SELF CONTEXT)))");

              method->function_code = ((cpp_function_code)(&clear_one_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-CONTEXT", "CONTEXT", "(DEFUN CLEAR-CONTEXT ((SELF CONTEXT)) :DOCUMENTATION \"Destroy all objects belonging to 'self' or any of its subcontexts.\")");

              method->function_code = ((cpp_function_code)(&clear_context));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-MODULE", "ARGUMENT-LIST", "(DEFUN CLEAR-MODULE (|&REST| (NAME NAME)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Destroy all objects belonging to module `name' or any of its children.\nIf no `name' is supplied, the current module will be cleared after\nconfirming with the user.  Important modules such as STELLA are protected\nagainst accidental clearing.\")");

              method->function_code = ((cpp_function_code)(&clear_module));
              set_dynamic_slot_value(method, SYM_MODULES_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&clear_module_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            define_method_from_stringified_source("STARTUP-MODULES", NULL, "(DEFUN STARTUP-MODULES ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *SUBCONTEXT-REVISION-POLICY* KEYWORD :DESTROY :DOCUMENTATION \"Controls actions reflexive transitive closure of\n   subcontexts when a context is revised.\n   Values are ':destroy' -- destroy subcontexts;\n   ':clear' -- clear contents of subcontexts;\n   ':preserve' -- don't disturb subcontexts.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *SHADOWEDSURROGATES* (CONS OF SYMBOL) NULL :DOCUMENTATION \"Holds list of symbols representing surrogates\nto be shadowed during module finalization.\")");
            { Global_Variable* global = SYM_MODULES_oSHADOWEDSURROGATESo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OshadowedsurrogatesO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OshadowedsurrogatesO));
            }
            set_dynamic_slot_value(oROOT_MODULEo, SYM_MODULES_CLEARABLEp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
            set_dynamic_slot_value(oSTELLA_MODULEo, SYM_MODULES_CLEARABLEp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
            set_dynamic_slot_value(oCOMMON_LISP_MODULEo, SYM_MODULES_CLEARABLEp, wrap_boolean(FALSE), NULL_BOOLEAN_WRAPPER);
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

