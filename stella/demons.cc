// demons.cc

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

String_Hash_Table* oDEMONS_TABLEo = NULL;

List* oCONSTRUCTOR_DEMONSo = NULL;

List* oDESTRUCTOR_DEMONSo = NULL;

List* oALL_SLOTS_DEMONSo = NULL;

List* oALL_SLOTS_GUARD_DEMONSo = NULL;

Keyword* KWD_DEMONS_MODIFY = NULL;

Keyword* KWD_DEMONS_CREATE = NULL;

Keyword* KWD_DEMONS_DESTROY = NULL;

Keyword* KWD_DEMONS_ALL = NULL;

Keyword* KWD_DEMONS_CLASS = NULL;

Keyword* KWD_DEMONS_SLOT = NULL;

Keyword* KWD_DEMONS_CODE = NULL;

Keyword* KWD_DEMONS_METHOD = NULL;

Keyword* KWD_DEMONS_GUARDp = NULL;

Keyword* KWD_DEMONS_INHERITEDp = NULL;

Keyword* KWD_DEMONS_DOCUMENTATION = NULL;

Keyword* KWD_DEMONS_ACTIVATEp = NULL;

Symbol* SYM_DEMONS_SLOT_GUARD_DEMONS = NULL;

Symbol* SYM_DEMONS_SLOT_DEMONS = NULL;

Symbol* SYM_DEMONS_CLASS_GUARD_CONSTRUCTOR_DEMONS = NULL;

Symbol* SYM_DEMONS_CLASS_CONSTRUCTOR_DEMONS = NULL;

Symbol* SYM_DEMONS_CLASS_GUARD_DESTRUCTOR_DEMONS = NULL;

Symbol* SYM_DEMONS_CLASS_DESTRUCTOR_DEMONS = NULL;

Symbol* SYM_DEMONS_WRAP_LITERAL = NULL;

Symbol* SYM_DEMONS_TRUE = NULL;

Symbol* SYM_DEMONS_WRAP_BOOLEAN = NULL;

Symbol* SYM_DEMONS_FALSE = NULL;

Symbol* SYM_DEMONS_PROGN = NULL;

Symbol* SYM_DEMONS_DEFUN = NULL;

Symbol* SYM_DEMONS_STARTUP_TIME_PROGN = NULL;

Symbol* SYM_DEMONS_DEFINE_DEMON = NULL;

Symbol* SYM_DEMONS_THE_CODE = NULL;

Keyword* KWD_DEMONS_FUNCTION = NULL;

Symbol* SYM_DEMONS_DEFDEMON = NULL;

Symbol* SYM_DEMONS_DEFDEMON_EXPANDER = NULL;

Symbol* SYM_DEMONS_SLOT_VALUE = NULL;

Symbol* SYM_DEMONS_SELF = NULL;

Symbol* SYM_DEMONS_LET = NULL;

Symbol* SYM_DEMONS_VALUE = NULL;

Symbol* SYM_DEMONS_WHEN = NULL;

Symbol* SYM_DEMONS_DEFINEDp = NULL;

Symbol* SYM_DEMONS_RETURN = NULL;

Symbol* SYM_DEMONS_SETQ = NULL;

Symbol* SYM_DEMONS_NEW = NULL;

Symbol* SYM_DEMONS_SETF = NULL;

Symbol* SYM_DEMONS_OWNER_INSTANCE = NULL;

Symbol* SYM_DEMONS_ACTIVE_SLOT = NULL;

Symbol* SYM_DEMONS_GET_SLOT = NULL;

Symbol* SYM_DEMONS_BQUOTE = NULL;

Surrogate* SGT_DEMONS_BOOLEAN = NULL;

Symbol* SYM_DEMONS_CANT_OVERWRITE_ACTIVE_COLLECTION_SLOT = NULL;

Surrogate* SGT_DEMONS_LITERAL = NULL;

Symbol* SYM_DEMONS_SLOT = NULL;

Symbol* SYM_DEMONS_OLDVALUE = NULL;

Symbol* SYM_DEMONS_NOT = NULL;

Symbol* SYM_DEMONS_EQLp = NULL;

Symbol* SYM_DEMONS_IF = NULL;

Symbol* SYM_DEMONS_CHECK_FOR_SLOT_DEMONSp = NULL;

Symbol* SYM_DEMONS_WRAPPEDOLDVALUE = NULL;

Symbol* SYM_DEMONS_CHOOSE = NULL;

Symbol* SYM_DEMONS_NULL = NULL;

Symbol* SYM_DEMONS_WRAPPEDNEWVALUE = NULL;

Symbol* SYM_DEMONS_RUN_SLOT_GUARD_DEMONSp = NULL;

Symbol* SYM_DEMONS_RUN_SLOT_DEMONS = NULL;

Symbol* SYM_DEMONS_FREE = NULL;

Symbol* SYM_DEMONS_AND = NULL;

Symbol* SYM_DEMONS_EQp = NULL;

Symbol* SYM_DEMONS_SIGNATURE = NULL;

Symbol* SYM_DEMONS_DOCUMENTATION = NULL;

Surrogate* SGT_DEMONS_HOOK_LIST = NULL;

Hook_List* oCHANGE_MODULE_HOOKSo = NULL;

Hook_List* oCLEAR_MODULE_HOOKSo = NULL;

Hook_List* oREDEFINE_RELATION_HOOKSo = NULL;

Hook_List* oBLOCK_NATIVE_CLASS_CREATION_HOOKSo = NULL;

boolean validate_demon_referencesP(Demon* demon) {
  { Surrogate* classref = ((demon->demon_class_refs != NULL) ? ((Surrogate*)(((Surrogate*)(demon->demon_class_refs->first())))) : ((Surrogate*)(NULL)));
    Symbol* slotref = ((demon->demon_slot_refs != NULL) ? ((Symbol*)(((Symbol*)(demon->demon_slot_refs->first())))) : ((Symbol*)(NULL)));
    Slot* slot = NULL;

    if ((classref == NULL) &&
        (slotref == NULL)) {
      return (TRUE);
    }
    if (classref == NULL) {
      cerr << "Missing :class option in demon " << "`" << demon << "'";
      return (FALSE);
    }
    if (((Class*)(classref->surrogate_value)) == NULL) {
      cerr << "Class " << "`" << classref << "'" << " not yet defined.";
      return (FALSE);
    }
    if (demon->demon_action == KWD_DEMONS_MODIFY) {
      if (slotref == NULL) {
        cerr << "Missing :slot option in demon " << "`" << demon << "'";
        return (FALSE);
      }
      { boolean test_value_001 = FALSE;

        { 
          slot = lookup_slot(((Class*)(classref->surrogate_value)), slotref);
          test_value_001 = slot != NULL;
        }
        test_value_001 = !test_value_001;
        if (test_value_001) {
          cerr << "No slot named " << "`" << slotref << "'" << " exists on class " << "`" << ((Class*)(classref->surrogate_value)) << "'" << "." << endl << "Can't create demon " << "`" << demon << "'";
          return (FALSE);
        }
      }
      if (!storage_slotP(slot)) {
        cerr << "Can't install a demon on the method." << "`" << slot << "'";
        return (FALSE);
      }
    }
    return (TRUE);
  }
}

boolean incorporate_demon_optionsP(Demon* demon, Property_List* options) {
  if (options->lookup(KWD_DEMONS_CREATE) != NULL) {
    demon->demon_action = KWD_DEMONS_CREATE;
  }
  else if (options->lookup(KWD_DEMONS_DESTROY) != NULL) {
    demon->demon_action = KWD_DEMONS_DESTROY;
  }
  else {
    demon->demon_action = KWD_DEMONS_MODIFY;
  }
  { Object* v = NULL;
    Object* k = NULL;
    Cons* iter_001 = options->the_plist;

    while (!nilP(iter_001)) {
      k = iter_001->value;
      {
        v = iter_001->rest->value;
        iter_001 = iter_001->rest->rest;
      }
      if ((k == KWD_DEMONS_CREATE) ||
          (k == KWD_DEMONS_DESTROY)) {
        demon->demon_action = ((Keyword*)(k));
        if (v == KWD_DEMONS_ALL) {
          demon->demon_allP = TRUE;
        }
        else {
          demon->demon_class_refs->insert(v->surrogatify());
        }
      }
      else if (k == KWD_DEMONS_CLASS) {
        demon->demon_class_refs->insert(v->surrogatify());
      }
      else if (k == KWD_DEMONS_SLOT) {
        if (v == KWD_DEMONS_ALL) {
          demon->demon_allP = TRUE;
        }
        else {
          demon->demon_slot_refs->insert(((Symbol*)(v->permanentify())));
        }
      }
      else if (k == KWD_DEMONS_CODE) {
        demon->demon_code = ((Function_Code_Wrapper*)(v))->wrapper_value;
      }
      else if (k == KWD_DEMONS_METHOD) {
        demon->demon_method = ((Method_Slot*)(v));
      }
      else if (k == KWD_DEMONS_GUARDp) {
        demon->demon_guardP = TRUE;
      }
      else if (k == KWD_DEMONS_INHERITEDp) {
        demon->demon_inheritP = TRUE;
        cout << "Inherit? not yet implemented for demons" << endl;
      }
      else if (k == KWD_DEMONS_DOCUMENTATION) {
        demon->demon_documentation = ((String_Wrapper*)(v))->wrapper_value;
      }
      else {
        cerr << "`" << k << "'" << " is not a valid case option";
      }
    }
  }
  if (demon->demon_method != NULL) {
    demon->demon_code = demon->demon_method->function_code;
  }
  options->free();
  return (validate_demon_referencesP(demon));
}

Demon* lookup_demon(char* name) {
  // Return the demon named 'name'.
  return (((Demon*)(oDEMONS_TABLEo->lookup(name))));
}

Demon* define_demon(char* name, int options, ...) {
  // Define a class or slot demon.  Options are :create,
  // :destroy, :class, :slot, :guard?, :code, :method, :inherit?, and :documentation.
  { Demon* demon = new_demon();
    Property_List* plist = new_property_list();
    Cons* conslist = NIL;
    Demon* olddemon = NULL;
    boolean activateP = FALSE;

    { va_list ap;
      Object* item;
      Cons* collect_001 = NULL;

      va_start(ap, options);
      while (options > 0) {
        item = va_arg(ap, Object*);
        options = options - 1;
        if (collect_001 == NULL) {
          {
            collect_001 = cons(item, NIL);
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
            collect_001->rest = cons(item, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
      va_end(ap);
    }
    plist->the_plist = conslist;
    demon->demon_name = name;
    activateP = plist->remove_at(KWD_DEMONS_ACTIVATEp) == TRUE_WRAPPER;
    if (incorporate_demon_optionsP(demon, plist)) {
      { 
        olddemon = lookup_demon(name);
        if (olddemon != NULL) {
          deactivate_demon(olddemon);
          olddemon->free();
        }
      }
      oDEMONS_TABLEo->insert_at(demon->demon_name, demon);
      if (activateP) {
        activate_demon(demon);
      }
      return (demon);
    }
    demon->free();
    return (NULL);
  }
}

List* inject_demon(List* demonlist, Demon* demon) {
  if (null_listP(demonlist)) {
    demonlist = new_list();
  }
  { List_Iterator* it = ((List_Iterator*)(demonlist->allocate_iterator()));

    while (it->nextP()) {
      if (string_eqlP(((Demon*)(it->value))->demon_name, demon->demon_name)) {
        it->value_setter(demon);
        return (demonlist);
      }
    }
  }
  demonlist->insert(demon);
  return (demonlist);
}

List* eject_demon(List* demonlist, Demon* demon) {
  if (demonlist == NULL) {
    return (NULL);
  }
  demonlist->remove(demon);
  if (demonlist->emptyP()) {
    demonlist->free();
    demonlist = NULL;
  }
  return (demonlist);
}

void activate_demon(Demon* demon) {
  // Install 'demon' in the location(s) specified by its internal
  // structure.
  if (demon == NULL) {
    return;
  }
  { Keyword* test_value_001 = demon->demon_action;

    if (test_value_001 == KWD_DEMONS_MODIFY) {
      if (demon->demon_allP) {
        if (demon->demon_guardP) {
          oALL_SLOTS_GUARD_DEMONSo = inject_demon(oALL_SLOTS_GUARD_DEMONSo, demon);
        }
        else {
          oALL_SLOTS_DEMONSo = inject_demon(oALL_SLOTS_DEMONSo, demon);
        }
      }
      else {
        { Symbol* slotname = NULL;
          Surrogate* type = NULL;
          Cons* iter_001 = demon->demon_class_refs->the_cons_list;
          Cons* iter_002 = demon->demon_slot_refs->the_cons_list;

          while ((!nilP(iter_001)) &&
              (!nilP(iter_002))) {
            {
              type = ((Surrogate*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            {
              slotname = ((Symbol*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            { Storage_Slot* slot = ((Storage_Slot*)(safe_lookup_slot(((Class*)(type->surrogate_value)), slotname)));

              if (slot == NULL) {
                cerr << "Can't install demon on non-existant slot " << "`" << ((Class*)(type->surrogate_value)) << "'" << "." << "`" << slotname << "'";
                continue;
              }
              if (demon->demon_guardP) {
                set_dynamic_slot_value(slot, SYM_DEMONS_SLOT_GUARD_DEMONS, inject_demon(slot->slot_guard_demons_reader(), demon), NULL);
              }
              else {
                set_dynamic_slot_value(slot, SYM_DEMONS_SLOT_DEMONS, inject_demon(slot->slot_demons_reader(), demon), NULL);
              }
            }
          }
        }
      }
    }
    else if (test_value_001 == KWD_DEMONS_CREATE) {
      if (demon->demon_allP) {
        oCONSTRUCTOR_DEMONSo = inject_demon(oCONSTRUCTOR_DEMONSo, demon);
      }
      else {
        { Surrogate* classref = NULL;
          Cons* iter_003 = demon->demon_class_refs->the_cons_list;

          while (!nilP(iter_003)) {
            {
              classref = ((Surrogate*)(iter_003->value));
              iter_003 = iter_003->rest;
            }
            { Class* renamed_Class = ((Class*)(classref->surrogate_value));

              if (renamed_Class == NULL) {
                cerr << "Can't install demon on non-existant class " << "`" << classref << "'";
                continue;
              }
              if (demon->demon_guardP) {
                set_dynamic_slot_value(renamed_Class, SYM_DEMONS_CLASS_GUARD_CONSTRUCTOR_DEMONS, inject_demon(renamed_Class->class_guard_constructor_demons_reader(), demon), NULL);
              }
              else {
                set_dynamic_slot_value(renamed_Class, SYM_DEMONS_CLASS_CONSTRUCTOR_DEMONS, inject_demon(renamed_Class->class_constructor_demons_reader(), demon), NULL);
              }
            }
          }
        }
      }
    }
    else if (test_value_001 == KWD_DEMONS_DESTROY) {
      if (demon->demon_allP) {
        oDESTRUCTOR_DEMONSo = inject_demon(oDESTRUCTOR_DEMONSo, demon);
      }
      else {
        { Surrogate* classref = NULL;
          Cons* iter_004 = demon->demon_class_refs->the_cons_list;

          while (!nilP(iter_004)) {
            {
              classref = ((Surrogate*)(iter_004->value));
              iter_004 = iter_004->rest;
            }
            { Class* renamed_Class = ((Class*)(classref->surrogate_value));

              if (renamed_Class == NULL) {
                cerr << "Can't install demon on non-existant class " << "`" << classref << "'";
                continue;
              }
              if (demon->demon_guardP) {
                set_dynamic_slot_value(renamed_Class, SYM_DEMONS_CLASS_GUARD_DESTRUCTOR_DEMONS, inject_demon(renamed_Class->class_guard_destructor_demons_reader(), demon), NULL);
              }
              else {
                set_dynamic_slot_value(renamed_Class, SYM_DEMONS_CLASS_DESTRUCTOR_DEMONS, inject_demon(renamed_Class->class_destructor_demons_reader(), demon), NULL);
              }
            }
          }
        }
      }
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

void deactivate_demon(Demon* demon) {
  // Detach 'demon' from the location(s) specified by its internal
  // structure.
  if (demon == NULL) {
    return;
  }
  { Keyword* test_value_001 = demon->demon_action;

    if (test_value_001 == KWD_DEMONS_MODIFY) {
      if (demon->demon_allP) {
        if (demon->demon_guardP) {
          oALL_SLOTS_GUARD_DEMONSo = eject_demon(oALL_SLOTS_GUARD_DEMONSo, demon);
        }
        else {
          oALL_SLOTS_DEMONSo = eject_demon(oALL_SLOTS_DEMONSo, demon);
        }
      }
      else {
        { Symbol* slotname = NULL;
          Surrogate* type = NULL;
          Cons* iter_001 = demon->demon_class_refs->the_cons_list;
          Cons* iter_002 = demon->demon_slot_refs->the_cons_list;

          while ((!nilP(iter_001)) &&
              (!nilP(iter_002))) {
            {
              type = ((Surrogate*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            {
              slotname = ((Symbol*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            { Storage_Slot* slot = ((Storage_Slot*)(safe_lookup_slot(((Class*)(type->surrogate_value)), slotname)));

              if (slot == NULL) {
                cerr << "Can't remove demon from non-existant slot " << "`" << ((Class*)(type->surrogate_value)) << "'" << "." << "`" << slotname << "'";
                continue;
              }
              if (demon->demon_guardP) {
                set_dynamic_slot_value(slot, SYM_DEMONS_SLOT_GUARD_DEMONS, eject_demon(slot->slot_guard_demons_reader(), demon), NULL);
              }
              else {
                set_dynamic_slot_value(slot, SYM_DEMONS_SLOT_DEMONS, eject_demon(slot->slot_demons_reader(), demon), NULL);
              }
            }
          }
        }
      }
    }
    else if (test_value_001 == KWD_DEMONS_CREATE) {
      if (demon->demon_allP) {
        oCONSTRUCTOR_DEMONSo = eject_demon(oCONSTRUCTOR_DEMONSo, demon);
      }
      else {
        { Surrogate* classref = NULL;
          Cons* iter_003 = demon->demon_class_refs->the_cons_list;

          while (!nilP(iter_003)) {
            {
              classref = ((Surrogate*)(iter_003->value));
              iter_003 = iter_003->rest;
            }
            { Class* renamed_Class = ((Class*)(classref->surrogate_value));

              if (renamed_Class == NULL) {
                cerr << "Can't install demon on non-existant class " << "`" << classref << "'";
                continue;
              }
              if (demon->demon_guardP) {
                set_dynamic_slot_value(renamed_Class, SYM_DEMONS_CLASS_GUARD_CONSTRUCTOR_DEMONS, eject_demon(renamed_Class->class_guard_constructor_demons_reader(), demon), NULL);
              }
              else {
                set_dynamic_slot_value(renamed_Class, SYM_DEMONS_CLASS_CONSTRUCTOR_DEMONS, eject_demon(renamed_Class->class_constructor_demons_reader(), demon), NULL);
              }
            }
          }
        }
      }
    }
    else if (test_value_001 == KWD_DEMONS_DESTROY) {
      if (demon->demon_allP) {
        oDESTRUCTOR_DEMONSo = eject_demon(oDESTRUCTOR_DEMONSo, demon);
      }
      else {
        { Surrogate* classref = NULL;
          Cons* iter_004 = demon->demon_class_refs->the_cons_list;

          while (!nilP(iter_004)) {
            {
              classref = ((Surrogate*)(iter_004->value));
              iter_004 = iter_004->rest;
            }
            { Class* renamed_Class = ((Class*)(classref->surrogate_value));

              if (renamed_Class == NULL) {
                cerr << "Can't install demon on non-existant class " << "`" << classref << "'";
                continue;
              }
              if (demon->demon_guardP) {
                set_dynamic_slot_value(renamed_Class, SYM_DEMONS_CLASS_GUARD_DESTRUCTOR_DEMONS, eject_demon(renamed_Class->class_guard_destructor_demons_reader(), demon), NULL);
              }
              else {
                set_dynamic_slot_value(renamed_Class, SYM_DEMONS_CLASS_DESTRUCTOR_DEMONS, eject_demon(renamed_Class->class_destructor_demons_reader(), demon), NULL);
              }
            }
          }
        }
      }
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

Cons* destructure_defdemon_body(Cons* demontree, Cons*& return1) {
  { Cons* optionstree = demontree;
    Cons* bodytree = demontree;
    Cons* trailingcursor = NULL;

    while (keywordP(bodytree->first())) {
      trailingcursor = bodytree;
      bodytree = bodytree->rest->rest;
    }
    if (trailingcursor != NULL) {
      trailingcursor->rest->rest = NIL;
    }
    else {
      optionstree = NIL;
    }
    { Cons* return_temp = optionstree;

      return1 = bodytree;
      return (return_temp);
    }
  }
}

void in_place_normalize_demon_options(Cons* optionstree) {
  { Cons_Iterator* it = optionstree->allocate_iterator();

    while (it->nextP()) {
      if (wrapperP(it->value)) {
        it->value_setter(listO(3, SYM_DEMONS_WRAP_LITERAL, it->value, NIL));
      }
      else if (it->value == SYM_DEMONS_TRUE) {
        it->value_setter(listO(3, SYM_DEMONS_WRAP_BOOLEAN, SYM_DEMONS_TRUE, NIL));
      }
      else if (it->value == SYM_DEMONS_FALSE) {
        it->value_setter(listO(3, SYM_DEMONS_WRAP_BOOLEAN, SYM_DEMONS_FALSE, NIL));
      }
    }
  }
}

Object* defdemon_expander(String_Wrapper* name, Cons* parameterstree, Cons* optionsandbody) {
  // Define a demon 'name' and attach it to a class or slot.
  { Object* firstparameter = parameterstree->first();
    Surrogate* type = NULL;
    Symbol* demonfunctionname = intern_symbol(name->wrapper_value);

    if (!consP(firstparameter)) {
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
                cout << endl << " " << "Illegal first parameter in demon " << "`" << de_uglify_parse_tree(name) << "'" << "." << endl;
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
      return (NIL);
    }
    type = type_spec_to_base_type(safe_yield_type_specifier(((Cons*)(firstparameter))->second()));
    if (((Class*)(type->surrogate_value)) == NULL) {
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
                cout << endl << " " << "Demon defined on the non-existent class " << "`" << de_uglify_parse_tree(type) << "'" << "." << endl;
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
      return (NIL);
    }
    { Cons* optionstree = NULL;
      Cons* bodytree = NULL;

      optionstree = destructure_defdemon_body(optionsandbody, bodytree);
      in_place_normalize_demon_options(optionstree);
      return (listO(4, SYM_DEMONS_PROGN, listO(3, SYM_DEMONS_DEFUN, demonfunctionname, cons(parameterstree, bodytree->concatenate(NIL))), listO(3, SYM_DEMONS_STARTUP_TIME_PROGN, listO(3, SYM_DEMONS_DEFINE_DEMON, name, optionstree->concatenate(listO(3, KWD_DEMONS_CODE, listO(3, SYM_DEMONS_WRAP_LITERAL, listO(4, SYM_DEMONS_THE_CODE, KWD_DEMONS_FUNCTION, demonfunctionname, NIL), NIL), NIL))), NIL), NIL));
    }
  }
}

Object* read_slot_value(Standard_Object* self, Storage_Slot* slot) {
  { cpp_function_code code = ((Class*)(slot->slot_owner->surrogate_value))->class_slot_accessor_code;

    if (code != NULL) {
      return (((Object* (*) (Standard_Object*, Symbol*, Object*, boolean))code)(self, slot->slot_name, ((Object*)(NULL)), FALSE));
    }
    if (subtype_ofP(self->primary_type(), slot->slot_owner)) {
      cerr << "read-slot-value: No generic slot reader available for " << "`" << slot << "'" << ".";
    }
    else {
      cerr << "read-slot-value: Slot " << "`" << slot << "'" << " does not exist on" << endl << " object " << "`" << self << "'" << " of type " << "`" << self->primary_type() << "'" << ".";
    }
    return (NULL);
  }
}

Object* write_slot_value(Standard_Object* self, Storage_Slot* slot, Object* value) {
  { cpp_function_code code = ((Class*)(slot->slot_owner->surrogate_value))->class_slot_accessor_code;

    if (code != NULL) {
      return (((Object* (*) (Standard_Object*, Symbol*, Object*, boolean))code)(self, slot->slot_name, value, TRUE));
    }
    if (subtype_ofP(self->primary_type(), slot->slot_owner)) {
      cerr << "write-slot-value: No generic slot writer available for " << "`" << slot << "'" << ".";
    }
    else {
      cerr << "write-slot-value: Slot " << "`" << slot << "'" << " does not exist on" << endl << " object " << "`" << self << "'" << " of type " << "`" << self->primary_type() << "'" << ".";
    }
    return (NULL);
  }
}

Object* put_slot_value(Standard_Object* self, Storage_Slot* slot, Object* value) {
  if (slot->single_valuedP()) {
    return (write_slot_value(self, slot, value));
  }
  else {
    { List* oldvalues = ((List*)(read_slot_value(self, slot)));

      oldvalues->insert(value);
      return (value);
    }
  }
}

void drop_slot_value(Standard_Object* self, Storage_Slot* slot, Object* value) {
  if (slot->single_valuedP()) {
    { Object* oldvalue = read_slot_value(self, slot);

      if (eqlP(value, oldvalue)) {
        write_slot_value(self, slot, NULL);
      }
    }
  }
  else {
    { List* oldvalues = ((List*)(read_slot_value(self, slot)));

      oldvalues->remove(value);
    }
  }
}

boolean check_for_slot_demonsP(Storage_Slot* slot) {
  return ((oALL_SLOTS_DEMONSo != NULL) ||
      ((oALL_SLOTS_GUARD_DEMONSo != NULL) ||
       ((slot->slot_guard_demons_reader() != NULL) ||
        (slot->slot_demons_reader() != NULL))));
}

boolean run_slot_guard_demonsP(Standard_Object* self, Storage_Slot* slot, Object* oldvalue, Object* newvalue) {
  if (oALL_SLOTS_GUARD_DEMONSo != NULL) {
    { Demon* demon = NULL;
      Cons* iter_001 = oALL_SLOTS_GUARD_DEMONSo->the_cons_list;

      while (!nilP(iter_001)) {
        {
          demon = ((Demon*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (!((boolean (*) (Standard_Object*, Storage_Slot*, Object*, Object*))demon->demon_code)(self, slot, oldvalue, newvalue)) {
          return (FALSE);
        }
      }
    }
  }
  if (slot->slot_guard_demons_reader() != NULL) {
    { Demon* demon = NULL;
      Cons* iter_002 = slot->slot_guard_demons_reader()->the_cons_list;

      while (!nilP(iter_002)) {
        {
          demon = ((Demon*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        if (!((boolean (*) (Standard_Object*, Storage_Slot*, Object*, Object*))demon->demon_code)(self, slot, oldvalue, newvalue)) {
          return (FALSE);
        }
      }
    }
  }
  return (TRUE);
}

void run_slot_demons(Standard_Object* self, Storage_Slot* slot, Object* oldvalue, Object* newvalue) {
  if (oALL_SLOTS_DEMONSo != NULL) {
    { Demon* demon = NULL;
      Cons* iter_001 = oALL_SLOTS_DEMONSo->the_cons_list;

      while (!nilP(iter_001)) {
        {
          demon = ((Demon*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        ((void (*) (Standard_Object*, Storage_Slot*, Object*, Object*))demon->demon_code)(self, slot, oldvalue, newvalue);
      }
    }
  }
  if (slot->slot_demons_reader() != NULL) {
    { Demon* demon = NULL;
      Cons* iter_002 = slot->slot_demons_reader()->the_cons_list;

      while (!nilP(iter_002)) {
        {
          demon = ((Demon*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        ((void (*) (Standard_Object*, Storage_Slot*, Object*, Object*))demon->demon_code)(self, slot, oldvalue, newvalue);
      }
    }
  }
}

void run_constructor_demons(Standard_Object* self) {
  { Class* renamed_Class = self->primary_class();

    if (renamed_Class != NULL) {
      if (oCONSTRUCTOR_DEMONSo != NULL) {
        { Demon* demon = NULL;
          Cons* iter_001 = oCONSTRUCTOR_DEMONSo->the_cons_list;

          while (!nilP(iter_001)) {
            {
              demon = ((Demon*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            ((void (*) (Standard_Object*, Class*))demon->demon_code)(self, renamed_Class);
          }
        }
      }
      if (renamed_Class->class_constructor_demons_reader() != NULL) {
        { Demon* demon = NULL;
          Cons* iter_002 = renamed_Class->class_constructor_demons_reader()->the_cons_list;

          while (!nilP(iter_002)) {
            {
              demon = ((Demon*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            ((void (*) (Standard_Object*, Class*))demon->demon_code)(self, renamed_Class);
          }
        }
      }
    }
  }
}

void run_destructor_demons(Standard_Object* self) {
  { Class* renamed_Class = self->primary_class();

    if (renamed_Class != NULL) {
      if (oDESTRUCTOR_DEMONSo != NULL) {
        { Demon* demon = NULL;
          Cons* iter_001 = oDESTRUCTOR_DEMONSo->the_cons_list;

          while (!nilP(iter_001)) {
            {
              demon = ((Demon*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            ((void (*) (Standard_Object*, Class*))demon->demon_code)(self, renamed_Class);
          }
        }
      }
      if (renamed_Class->class_destructor_demons_reader() != NULL) {
        { Demon* demon = NULL;
          Cons* iter_002 = renamed_Class->class_destructor_demons_reader()->the_cons_list;

          while (!nilP(iter_002)) {
            {
              demon = ((Demon*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            ((void (*) (Standard_Object*, Class*))demon->demon_code)(self, renamed_Class);
          }
        }
      }
    }
  }
}

Cons* yield_active_slot_reader_body(Storage_Slot* slot, Object* defaultexpression) {
  { Symbol* slotname = slot->slot_name;

    if (slot->single_valuedP()) {
      return (wrap_with_default_value_and_return_code(listO(4, SYM_DEMONS_SLOT_VALUE, SYM_DEMONS_SELF, slotname, NIL), defaultexpression));
    }
    else {
      {
        if (defaultexpression != NULL) {
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
                    cout << endl << " " << "Can't define a default value for the active " << "collection-valued slot named." << "`" << slot->slot_name << "'" << "Ignoring the default value." << "." << endl;
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
        return (listO(9, SYM_DEMONS_LET, cons(listO(3, SYM_DEMONS_VALUE, listO(4, SYM_DEMONS_SLOT_VALUE, SYM_DEMONS_SELF, slotname, NIL), NIL), NIL), listO(4, SYM_DEMONS_WHEN, listO(3, SYM_DEMONS_DEFINEDp, SYM_DEMONS_VALUE, NIL), listO(3, SYM_DEMONS_RETURN, SYM_DEMONS_VALUE, NIL), NIL), listO(4, SYM_DEMONS_SETQ, SYM_DEMONS_VALUE, listO(3, SYM_DEMONS_NEW, type_to_symbol(slot->type()), NIL), NIL), listO(4, SYM_DEMONS_SETF, listO(3, SYM_DEMONS_OWNER_INSTANCE, SYM_DEMONS_VALUE, NIL), SYM_DEMONS_SELF, NIL), listO(4, SYM_DEMONS_SETF, listO(3, SYM_DEMONS_ACTIVE_SLOT, SYM_DEMONS_VALUE, NIL), listO(4, SYM_DEMONS_GET_SLOT, SYM_DEMONS_SELF, listO(3, SYM_DEMONS_BQUOTE, slot->slot_name, NIL), NIL), NIL), listO(4, SYM_DEMONS_SETF, listO(4, SYM_DEMONS_SLOT_VALUE, SYM_DEMONS_SELF, slotname, NIL), SYM_DEMONS_VALUE, NIL), listO(3, SYM_DEMONS_RETURN, SYM_DEMONS_VALUE, NIL), NIL));
      }
    }
  }
}

void cant_overwrite_active_collection_slot(Standard_Object* self, Symbol* slotname) {
  cerr << "Can't replace the value of the active slot " << "`" << slotname << "'" << " on the object " << endl << "`" << self << "'" << ".  Call 'insert' or 'remove' to add/remove slot values.";
}

Cons* yield_active_slot_writer_body(Storage_Slot* slot) {
  { Symbol* slotname = slot->slot_name;
    Symbol* wrappingfunction = ((slot->slot_base_type == SGT_DEMONS_BOOLEAN) ? ((Symbol*)(SYM_DEMONS_WRAP_BOOLEAN)) : ((Symbol*)(SYM_DEMONS_WRAP_LITERAL)));

    if (!slot->single_valuedP()) {
      return (listO(5, SYM_DEMONS_PROGN, SYM_DEMONS_VALUE, listO(4, SYM_DEMONS_CANT_OVERWRITE_ACTIVE_COLLECTION_SLOT, SYM_DEMONS_SELF, listO(3, SYM_DEMONS_BQUOTE, slotname, NIL), NIL), listO(3, SYM_DEMONS_RETURN, listO(4, SYM_DEMONS_SLOT_VALUE, SYM_DEMONS_SELF, slot->slot_name, NIL), NIL), NIL));
    }
    else if (subtype_ofP(slot->type(), SGT_DEMONS_LITERAL)) {
      return (listO(4, SYM_DEMONS_LET, listO(3, listO(3, SYM_DEMONS_SLOT, listO(4, SYM_DEMONS_GET_SLOT, SYM_DEMONS_SELF, listO(3, SYM_DEMONS_BQUOTE, slotname, NIL), NIL), NIL), listO(3, SYM_DEMONS_OLDVALUE, listO(4, SYM_DEMONS_SLOT_VALUE, SYM_DEMONS_SELF, slotname, NIL), NIL), NIL), listO(4, SYM_DEMONS_WHEN, listO(3, SYM_DEMONS_NOT, listO(4, SYM_DEMONS_EQLp, SYM_DEMONS_OLDVALUE, SYM_DEMONS_VALUE, NIL), NIL), listO(5, SYM_DEMONS_IF, listO(3, SYM_DEMONS_CHECK_FOR_SLOT_DEMONSp, SYM_DEMONS_SLOT, NIL), listO(5, SYM_DEMONS_LET, listO(3, listO(3, SYM_DEMONS_WRAPPEDOLDVALUE, listO(5, SYM_DEMONS_CHOOSE, listO(3, SYM_DEMONS_DEFINEDp, SYM_DEMONS_OLDVALUE, NIL), cons(wrappingfunction, cons(SYM_DEMONS_OLDVALUE, NIL)), SYM_DEMONS_NULL, NIL), NIL), listO(3, SYM_DEMONS_WRAPPEDNEWVALUE, listO(5, SYM_DEMONS_CHOOSE, listO(3, SYM_DEMONS_DEFINEDp, SYM_DEMONS_VALUE, NIL), cons(wrappingfunction, cons(SYM_DEMONS_VALUE, NIL)), SYM_DEMONS_NULL, NIL), NIL), NIL), listO(8, SYM_DEMONS_WHEN, listO(6, SYM_DEMONS_RUN_SLOT_GUARD_DEMONSp, SYM_DEMONS_SELF, SYM_DEMONS_SLOT, SYM_DEMONS_WRAPPEDOLDVALUE, SYM_DEMONS_WRAPPEDNEWVALUE, NIL), listO(4, SYM_DEMONS_SETF, listO(4, SYM_DEMONS_SLOT_VALUE, SYM_DEMONS_SELF, slotname, NIL), SYM_DEMONS_VALUE, NIL), listO(6, SYM_DEMONS_RUN_SLOT_DEMONS, SYM_DEMONS_SELF, SYM_DEMONS_SLOT, SYM_DEMONS_WRAPPEDOLDVALUE, SYM_DEMONS_WRAPPEDNEWVALUE, NIL), listO(4, SYM_DEMONS_WHEN, listO(3, SYM_DEMONS_DEFINEDp, SYM_DEMONS_WRAPPEDOLDVALUE, NIL), listO(3, SYM_DEMONS_FREE, SYM_DEMONS_WRAPPEDOLDVALUE, NIL), NIL), listO(4, SYM_DEMONS_WHEN, listO(3, SYM_DEMONS_DEFINEDp, SYM_DEMONS_WRAPPEDNEWVALUE, NIL), listO(3, SYM_DEMONS_FREE, SYM_DEMONS_WRAPPEDNEWVALUE, NIL), NIL), listO(3, SYM_DEMONS_RETURN, SYM_DEMONS_VALUE, NIL), NIL), listO(3, SYM_DEMONS_RETURN, SYM_DEMONS_OLDVALUE, NIL), NIL), listO(3, SYM_DEMONS_RETURN, listO(4, SYM_DEMONS_SETF, listO(4, SYM_DEMONS_SLOT_VALUE, SYM_DEMONS_SELF, slotname, NIL), SYM_DEMONS_VALUE, NIL), NIL), NIL), NIL), NIL));
    }
    else {
      return (listO(5, SYM_DEMONS_LET, listO(3, listO(3, SYM_DEMONS_SLOT, listO(4, SYM_DEMONS_GET_SLOT, SYM_DEMONS_SELF, listO(3, SYM_DEMONS_BQUOTE, slotname, NIL), NIL), NIL), listO(3, SYM_DEMONS_OLDVALUE, listO(4, SYM_DEMONS_SLOT_VALUE, SYM_DEMONS_SELF, slotname, NIL), NIL), NIL), listO(6, SYM_DEMONS_WHEN, listO(4, SYM_DEMONS_AND, listO(3, SYM_DEMONS_NOT, listO(4, SYM_DEMONS_EQp, SYM_DEMONS_OLDVALUE, SYM_DEMONS_VALUE, NIL), NIL), listO(6, SYM_DEMONS_RUN_SLOT_GUARD_DEMONSp, SYM_DEMONS_SELF, SYM_DEMONS_SLOT, SYM_DEMONS_OLDVALUE, SYM_DEMONS_VALUE, NIL), NIL), listO(4, SYM_DEMONS_SETF, listO(4, SYM_DEMONS_SLOT_VALUE, SYM_DEMONS_SELF, slotname, NIL), SYM_DEMONS_VALUE, NIL), listO(6, SYM_DEMONS_RUN_SLOT_DEMONS, SYM_DEMONS_SELF, SYM_DEMONS_SLOT, SYM_DEMONS_OLDVALUE, SYM_DEMONS_VALUE, NIL), listO(3, SYM_DEMONS_RETURN, SYM_DEMONS_VALUE, NIL), NIL), listO(3, SYM_DEMONS_RETURN, SYM_DEMONS_OLDVALUE, NIL), NIL));
    }
  }
}

void Active_List::insert(Object* value) {
  { Active_List* self = this;

    { Storage_Slot* slot = self->active_slot;
      Standard_Object* owner = self->owner_instance;

      if (run_slot_guard_demonsP(owner, slot, self, value)) {
        self->the_cons_list = cons(value, self->the_cons_list);
        run_slot_demons(owner, slot, NULL, value);
      }
    }
  }
}

void Active_Set::insert(Object* value) {
  { Active_Set* self = this;

    { Storage_Slot* slot = self->active_slot;
      Standard_Object* owner = self->owner_instance;

      if (!(self->the_cons_list->memberP(value))) {
        if (run_slot_guard_demonsP(owner, slot, self, value)) {
          self->the_cons_list = cons(value, self->the_cons_list);
          run_slot_demons(owner, slot, NULL, value);
        }
      }
    }
  }
}

Abstract_Collection* Active_List::remove(Object* value) {
  { Active_List* self = this;

    { Storage_Slot* slot = self->active_slot;
      Standard_Object* owner = self->owner_instance;

      if (self->the_cons_list->memberP(value)) {
        if (run_slot_guard_demonsP(owner, slot, value, NULL)) {
          self->the_cons_list = self->the_cons_list->remove(value);
          run_slot_demons(owner, slot, value, NULL);
        }
      }
      return (self);
    }
  }
}

Abstract_Collection* Active_Set::remove(Object* value) {
  { Active_Set* self = this;

    { Storage_Slot* slot = self->active_slot;
      Standard_Object* owner = self->owner_instance;

      if (self->the_cons_list->memberP(value)) {
        if (run_slot_guard_demonsP(owner, slot, value, NULL)) {
          self->the_cons_list = self->the_cons_list->remove(value);
          run_slot_demons(owner, slot, value, NULL);
        }
      }
      return (self);
    }
  }
}

Hook_List* new_hook_list() {
  { Hook_List* self = NULL;

    self = new Hook_List;
    self->the_kv_list = NULL;
    self->documentation = NULL;
    self->signature = NULL;
    return (self);
  }
}

Object* access_hook_list_slot_value(Hook_List* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_DEMONS_SIGNATURE) {
    if (setvalueP) {
      self->signature = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->signature));
    }
  }
  else if (slotname == SYM_DEMONS_DOCUMENTATION) {
    if (setvalueP) {
      self->documentation = ((String_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (string_wrap_literal(self->documentation));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Hook_List::primary_type() {
  { Hook_List* self = this;

    return (SGT_DEMONS_HOOK_LIST);
  }
}

void add_hook(Hook_List* hooklist, Symbol* hookfunction) {
  // Insert the function named 'hookFunction' into 'hookList'.
  { Method_Slot* function = hookfunction->lookup_function();

    if (function == NULL) {
      cerr << "Reference to non-existent hook function: 'hookFunction'.";
      return;
    }
    hooklist->insert_at(hookfunction, function_code_wrap_literal(function->function_code));
  }
}

void drop_hook(Hook_List* hooklist, Symbol* hookfunction) {
  // Remove the function named 'hookFunction' from 'hookList'.
  hooklist->remove_at(hookfunction);
}

void run_hooks(Hook_List* hooklist, Object* argument) {
  // Run all hook functions in 'hooklist', applying
  // each one to 'argument'.
  { Kv_List_Iterator* it = ((Kv_List_Iterator*)(hooklist->allocate_iterator()));

    while (it->nextP()) {
      ((void (*) (Object*))((Function_Code_Wrapper*)(it->value))->wrapper_value)(argument);
    }
  }
}

void startup_demons() {
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
            KWD_DEMONS_MODIFY = ((Keyword*)(intern_rigid_symbol_wrt_module("MODIFY", NULL, 2)));
            KWD_DEMONS_CREATE = ((Keyword*)(intern_rigid_symbol_wrt_module("CREATE", NULL, 2)));
            KWD_DEMONS_DESTROY = ((Keyword*)(intern_rigid_symbol_wrt_module("DESTROY", NULL, 2)));
            KWD_DEMONS_ALL = ((Keyword*)(intern_rigid_symbol_wrt_module("ALL", NULL, 2)));
            KWD_DEMONS_CLASS = ((Keyword*)(intern_rigid_symbol_wrt_module("CLASS", NULL, 2)));
            KWD_DEMONS_SLOT = ((Keyword*)(intern_rigid_symbol_wrt_module("SLOT", NULL, 2)));
            KWD_DEMONS_CODE = ((Keyword*)(intern_rigid_symbol_wrt_module("CODE", NULL, 2)));
            KWD_DEMONS_METHOD = ((Keyword*)(intern_rigid_symbol_wrt_module("METHOD", NULL, 2)));
            KWD_DEMONS_GUARDp = ((Keyword*)(intern_rigid_symbol_wrt_module("GUARD?", NULL, 2)));
            KWD_DEMONS_INHERITEDp = ((Keyword*)(intern_rigid_symbol_wrt_module("INHERITED?", NULL, 2)));
            KWD_DEMONS_DOCUMENTATION = ((Keyword*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 2)));
            KWD_DEMONS_ACTIVATEp = ((Keyword*)(intern_rigid_symbol_wrt_module("ACTIVATE?", NULL, 2)));
            SYM_DEMONS_SLOT_GUARD_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-GUARD-DEMONS", NULL, 0)));
            SYM_DEMONS_SLOT_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-DEMONS", NULL, 0)));
            SYM_DEMONS_CLASS_GUARD_CONSTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-GUARD-CONSTRUCTOR-DEMONS", NULL, 0)));
            SYM_DEMONS_CLASS_CONSTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-CONSTRUCTOR-DEMONS", NULL, 0)));
            SYM_DEMONS_CLASS_GUARD_DESTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-GUARD-DESTRUCTOR-DEMONS", NULL, 0)));
            SYM_DEMONS_CLASS_DESTRUCTOR_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CLASS-DESTRUCTOR-DEMONS", NULL, 0)));
            SYM_DEMONS_WRAP_LITERAL = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-LITERAL", NULL, 0)));
            SYM_DEMONS_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            SYM_DEMONS_WRAP_BOOLEAN = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAP-BOOLEAN", NULL, 0)));
            SYM_DEMONS_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", NULL, 0)));
            SYM_DEMONS_PROGN = ((Symbol*)(intern_rigid_symbol_wrt_module("PROGN", NULL, 0)));
            SYM_DEMONS_DEFUN = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFUN", NULL, 0)));
            SYM_DEMONS_STARTUP_TIME_PROGN = ((Symbol*)(intern_rigid_symbol_wrt_module("STARTUP-TIME-PROGN", NULL, 0)));
            SYM_DEMONS_DEFINE_DEMON = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINE-DEMON", NULL, 0)));
            SYM_DEMONS_THE_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-CODE", NULL, 0)));
            KWD_DEMONS_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            SYM_DEMONS_DEFDEMON = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFDEMON", NULL, 0)));
            SYM_DEMONS_DEFDEMON_EXPANDER = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFDEMON-EXPANDER", NULL, 0)));
            SYM_DEMONS_SLOT_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-VALUE", NULL, 0)));
            SYM_DEMONS_SELF = ((Symbol*)(intern_rigid_symbol_wrt_module("SELF", NULL, 0)));
            SYM_DEMONS_LET = ((Symbol*)(intern_rigid_symbol_wrt_module("LET", NULL, 0)));
            SYM_DEMONS_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE", NULL, 0)));
            SYM_DEMONS_WHEN = ((Symbol*)(intern_rigid_symbol_wrt_module("WHEN", NULL, 0)));
            SYM_DEMONS_DEFINEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINED?", NULL, 0)));
            SYM_DEMONS_RETURN = ((Symbol*)(intern_rigid_symbol_wrt_module("RETURN", NULL, 0)));
            SYM_DEMONS_SETQ = ((Symbol*)(intern_rigid_symbol_wrt_module("SETQ", NULL, 0)));
            SYM_DEMONS_NEW = ((Symbol*)(intern_rigid_symbol_wrt_module("NEW", NULL, 0)));
            SYM_DEMONS_SETF = ((Symbol*)(intern_rigid_symbol_wrt_module("SETF", NULL, 0)));
            SYM_DEMONS_OWNER_INSTANCE = ((Symbol*)(intern_rigid_symbol_wrt_module("OWNER-INSTANCE", NULL, 0)));
            SYM_DEMONS_ACTIVE_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("ACTIVE-SLOT", NULL, 0)));
            SYM_DEMONS_GET_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("GET-SLOT", NULL, 0)));
            SYM_DEMONS_BQUOTE = ((Symbol*)(intern_rigid_symbol_wrt_module("BQUOTE", NULL, 0)));
            SGT_DEMONS_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", NULL, 1)));
            SYM_DEMONS_CANT_OVERWRITE_ACTIVE_COLLECTION_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("CANT-OVERWRITE-ACTIVE-COLLECTION-SLOT", NULL, 0)));
            SGT_DEMONS_LITERAL = ((Surrogate*)(intern_rigid_symbol_wrt_module("LITERAL", NULL, 1)));
            SYM_DEMONS_SLOT = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT", NULL, 0)));
            SYM_DEMONS_OLDVALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("OLDVALUE", NULL, 0)));
            SYM_DEMONS_NOT = ((Symbol*)(intern_rigid_symbol_wrt_module("NOT", NULL, 0)));
            SYM_DEMONS_EQLp = ((Symbol*)(intern_rigid_symbol_wrt_module("EQL?", NULL, 0)));
            SYM_DEMONS_IF = ((Symbol*)(intern_rigid_symbol_wrt_module("IF", NULL, 0)));
            SYM_DEMONS_CHECK_FOR_SLOT_DEMONSp = ((Symbol*)(intern_rigid_symbol_wrt_module("CHECK-FOR-SLOT-DEMONS?", NULL, 0)));
            SYM_DEMONS_WRAPPEDOLDVALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAPPEDOLDVALUE", NULL, 0)));
            SYM_DEMONS_CHOOSE = ((Symbol*)(intern_rigid_symbol_wrt_module("CHOOSE", NULL, 0)));
            SYM_DEMONS_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", NULL, 0)));
            SYM_DEMONS_WRAPPEDNEWVALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("WRAPPEDNEWVALUE", NULL, 0)));
            SYM_DEMONS_RUN_SLOT_GUARD_DEMONSp = ((Symbol*)(intern_rigid_symbol_wrt_module("RUN-SLOT-GUARD-DEMONS?", NULL, 0)));
            SYM_DEMONS_RUN_SLOT_DEMONS = ((Symbol*)(intern_rigid_symbol_wrt_module("RUN-SLOT-DEMONS", NULL, 0)));
            SYM_DEMONS_FREE = ((Symbol*)(intern_rigid_symbol_wrt_module("FREE", NULL, 0)));
            SYM_DEMONS_AND = ((Symbol*)(intern_rigid_symbol_wrt_module("AND", NULL, 0)));
            SYM_DEMONS_EQp = ((Symbol*)(intern_rigid_symbol_wrt_module("EQ?", NULL, 0)));
            SYM_DEMONS_SIGNATURE = ((Symbol*)(intern_rigid_symbol_wrt_module("SIGNATURE", NULL, 0)));
            SYM_DEMONS_DOCUMENTATION = ((Symbol*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 0)));
            SGT_DEMONS_HOOK_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("HOOK-LIST", NULL, 1)));
          }
          if (current_startup_time_phaseP(4)) {
            oDEMONS_TABLEo = new_string_hash_table();
            oCHANGE_MODULE_HOOKSo = new_hook_list();
            oCLEAR_MODULE_HOOKSo = new_hook_list();
            oREDEFINE_RELATION_HOOKSo = new_hook_list();
            oBLOCK_NATIVE_CLASS_CREATION_HOOKSo = new_hook_list();
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("HOOK-LIST", "(DEFCLASS HOOK-LIST (KEY-VALUE-LIST) :DOCUMENTATION \"Each HOOK-LIST object contains a list of zero or\nmore function codes that get funcall'd some procedure.\" :PARAMETERS ((ANY-KEY :TYPE SYMBOL) (ANY-VALUE :TYPE FUNCTION-CODE-WRAPPER)) :SLOTS ((SIGNATURE :TYPE STRING) (DOCUMENTATION :TYPE STRING)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_hook_list));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_hook_list_slot_value));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("VALIDATE-DEMON-REFERENCES?", "DEMON", "(DEFUN (VALIDATE-DEMON-REFERENCES? BOOLEAN) ((DEMON DEMON)))");

              method->function_code = ((cpp_function_code)(&validate_demon_referencesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INCORPORATE-DEMON-OPTIONS?", "DEMON", "(DEFUN (INCORPORATE-DEMON-OPTIONS? BOOLEAN) ((DEMON DEMON) (OPTIONS PROPERTY-LIST)))");

              method->function_code = ((cpp_function_code)(&incorporate_demon_optionsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-DEMON", "STRING", "(DEFUN (LOOKUP-DEMON DEMON) ((NAME STRING)) :DOCUMENTATION \"Return the demon named 'name'.\")");

              method->function_code = ((cpp_function_code)(&lookup_demon));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-DEMON", "STRING", "(DEFUN (DEFINE-DEMON DEMON) ((NAME STRING) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Define a class or slot demon.  Options are :create,\n:destroy, :class, :slot, :guard?, :code, :method, :inherit?, and :documentation.\")");

              method->function_code = ((cpp_function_code)(&define_demon));
            }
            { Method_Slot* method = define_method_from_stringified_source("INJECT-DEMON", "LIST", "(DEFUN (INJECT-DEMON (LIST OF DEMON)) ((DEMONLIST (LIST OF DEMON)) (DEMON DEMON)))");

              method->function_code = ((cpp_function_code)(&inject_demon));
            }
            { Method_Slot* method = define_method_from_stringified_source("EJECT-DEMON", "LIST", "(DEFUN (EJECT-DEMON (LIST OF DEMON)) ((DEMONLIST (LIST OF DEMON)) (DEMON DEMON)))");

              method->function_code = ((cpp_function_code)(&eject_demon));
            }
            { Method_Slot* method = define_method_from_stringified_source("ACTIVATE-DEMON", "DEMON", "(DEFUN ACTIVATE-DEMON ((DEMON DEMON)) :DOCUMENTATION \"Install 'demon' in the location(s) specified by its internal\nstructure.\")");

              method->function_code = ((cpp_function_code)(&activate_demon));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEACTIVATE-DEMON", "DEMON", "(DEFUN DEACTIVATE-DEMON ((DEMON DEMON)) :DOCUMENTATION \"Detach 'demon' from the location(s) specified by its internal\nstructure.\")");

              method->function_code = ((cpp_function_code)(&deactivate_demon));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTRUCTURE-DEFDEMON-BODY", "CONS", "(DEFUN (DESTRUCTURE-DEFDEMON-BODY CONS CONS) ((DEMONTREE CONS)))");

              method->function_code = ((cpp_function_code)(&destructure_defdemon_body));
            }
            { Method_Slot* method = define_method_from_stringified_source("IN-PLACE-NORMALIZE-DEMON-OPTIONS", "CONS", "(DEFUN IN-PLACE-NORMALIZE-DEMON-OPTIONS ((OPTIONSTREE CONS)))");

              method->function_code = ((cpp_function_code)(&in_place_normalize_demon_options));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFDEMON-EXPANDER", "STRING-WRAPPER", "(DEFUN (DEFDEMON-EXPANDER OBJECT) ((NAME STRING-WRAPPER) (PARAMETERSTREE CONS) |&BODY| (OPTIONSANDBODY CONS)) :DOCUMENTATION \"Define a demon 'name' and attach it to a class or slot.\")");

              method->function_code = ((cpp_function_code)(&defdemon_expander));
            }
            { Method_Slot* method = define_method_from_stringified_source("READ-SLOT-VALUE", "STANDARD-OBJECT", "(DEFUN (READ-SLOT-VALUE OBJECT) ((SELF STANDARD-OBJECT) (SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&read_slot_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRITE-SLOT-VALUE", "STANDARD-OBJECT", "(DEFUN (WRITE-SLOT-VALUE OBJECT) ((SELF STANDARD-OBJECT) (SLOT STORAGE-SLOT) (VALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&write_slot_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUT-SLOT-VALUE", "STANDARD-OBJECT", "(DEFUN (PUT-SLOT-VALUE OBJECT) ((SELF STANDARD-OBJECT) (SLOT STORAGE-SLOT) (VALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&put_slot_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("DROP-SLOT-VALUE", "STANDARD-OBJECT", "(DEFUN DROP-SLOT-VALUE ((SELF STANDARD-OBJECT) (SLOT STORAGE-SLOT) (VALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&drop_slot_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHECK-FOR-SLOT-DEMONS?", "STORAGE-SLOT", "(DEFUN (CHECK-FOR-SLOT-DEMONS? BOOLEAN) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&check_for_slot_demonsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-SLOT-GUARD-DEMONS?", "STANDARD-OBJECT", "(DEFUN (RUN-SLOT-GUARD-DEMONS? BOOLEAN) ((SELF STANDARD-OBJECT) (SLOT STORAGE-SLOT) (OLDVALUE OBJECT) (NEWVALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&run_slot_guard_demonsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-SLOT-DEMONS", "STANDARD-OBJECT", "(DEFUN RUN-SLOT-DEMONS ((SELF STANDARD-OBJECT) (SLOT STORAGE-SLOT) (OLDVALUE OBJECT) (NEWVALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&run_slot_demons));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-CONSTRUCTOR-DEMONS", "STANDARD-OBJECT", "(DEFUN RUN-CONSTRUCTOR-DEMONS ((SELF STANDARD-OBJECT)))");

              method->function_code = ((cpp_function_code)(&run_constructor_demons));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-DESTRUCTOR-DEMONS", "STANDARD-OBJECT", "(DEFUN RUN-DESTRUCTOR-DEMONS ((SELF STANDARD-OBJECT)))");

              method->function_code = ((cpp_function_code)(&run_destructor_demons));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-ACTIVE-SLOT-READER-BODY", "STORAGE-SLOT", "(DEFUN (YIELD-ACTIVE-SLOT-READER-BODY CONS) ((SLOT STORAGE-SLOT) (DEFAULTEXPRESSION OBJECT)))");

              method->function_code = ((cpp_function_code)(&yield_active_slot_reader_body));
            }
            { Method_Slot* method = define_method_from_stringified_source("CANT-OVERWRITE-ACTIVE-COLLECTION-SLOT", "STANDARD-OBJECT", "(DEFUN CANT-OVERWRITE-ACTIVE-COLLECTION-SLOT ((SELF STANDARD-OBJECT) (SLOTNAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&cant_overwrite_active_collection_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-ACTIVE-SLOT-WRITER-BODY", "STORAGE-SLOT", "(DEFUN (YIELD-ACTIVE-SLOT-WRITER-BODY CONS) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&yield_active_slot_writer_body));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT", "ACTIVE-LIST", "(DEFMETHOD INSERT ((SELF ACTIVE-LIST) (VALUE (LIKE (ANY-VALUE SELF)))))");

              method->method_code = ((cpp_method_code)(&Active_List::insert));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT", "ACTIVE-SET", "(DEFMETHOD INSERT ((SELF ACTIVE-SET) (VALUE (LIKE (ANY-VALUE SELF)))))");

              method->method_code = ((cpp_method_code)(&Active_Set::insert));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE", "ACTIVE-LIST", "(DEFMETHOD (REMOVE ACTIVE-LIST) ((SELF ACTIVE-LIST) (VALUE (LIKE (ANY-VALUE SELF)))))");

              method->method_code = ((cpp_method_code)(&Active_List::remove));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE", "ACTIVE-SET", "(DEFMETHOD (REMOVE ACTIVE-SET) ((SELF ACTIVE-SET) (VALUE (LIKE (ANY-VALUE SELF)))))");

              method->method_code = ((cpp_method_code)(&Active_Set::remove));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-HOOK", "HOOK-LIST", "(DEFUN ADD-HOOK ((HOOKLIST HOOK-LIST) (HOOKFUNCTION SYMBOL)) :PUBLIC? TRUE :DOCUMENTATION \"Insert the function named 'hookFunction' into 'hookList'.\")");

              method->function_code = ((cpp_function_code)(&add_hook));
            }
            { Method_Slot* method = define_method_from_stringified_source("DROP-HOOK", "HOOK-LIST", "(DEFUN DROP-HOOK ((HOOKLIST HOOK-LIST) (HOOKFUNCTION SYMBOL)) :PUBLIC? TRUE :DOCUMENTATION \"Remove the function named 'hookFunction' from 'hookList'.\")");

              method->function_code = ((cpp_function_code)(&drop_hook));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-HOOKS", "HOOK-LIST", "(DEFUN RUN-HOOKS ((HOOKLIST HOOK-LIST) (ARGUMENT OBJECT)) :DOCUMENTATION \"Run all hook functions in 'hooklist', applying\neach one to 'argument'.\")");

              method->function_code = ((cpp_function_code)(&run_hooks));
            }
            define_method_from_stringified_source("STARTUP-DEMONS", NULL, "(DEFUN STARTUP-DEMONS ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEMONS-TABLE* STRING-HASH-TABLE (NEW STRING-HASH-TABLE) :DOCUMENTATION \"Table containing all active and inactive demons, indexed\non their names.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CONSTRUCTOR-DEMONS* (LIST OF DEMON) NULL :DOCUMENTATION \"These demons trigger every time an active instance is created.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DESTRUCTOR-DEMONS* (LIST OF DEMON) NULL :DOCUMENTATION \"These demons trigger every time an active instance is destroyed.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *ALL-SLOTS-DEMONS* (LIST OF DEMON) NULL :DOCUMENTATION \"These demons trigger every time a slot value is modified.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *ALL-SLOTS-GUARD-DEMONS* (LIST OF DEMON) NULL :DOCUMENTATION \"These demons trigger every time a slot value is modified, and\ncancel slot update when they return FALSE.\")");
            store_macro(SYM_DEMONS_DEFDEMON, SYM_DEMONS_DEFDEMON_EXPANDER, ((cpp_function_code)(&defdemon_expander)));
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CHANGE-MODULE-HOOKS* HOOK-LIST (NEW HOOK-LIST) :DOCUMENTATION \"HOOK-LIST called by 'in-module', applied to a\n'module' argument.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *CLEAR-MODULE-HOOKS* HOOK-LIST (NEW HOOK-LIST) :DOCUMENTATION \"HOOK-LIST called by 'clear-module', applied to a\n'module' argument.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *REDEFINE-RELATION-HOOKS* HOOK-LIST (NEW HOOK-LIST) :DOCUMENTATION \"HOOK-LIST is called by 'undefine-old-class'.  Each\nhook function is passed a LIST of two RELATION objects; the first is the\nold relation object and the second is the new (redefined) relation object.\nThe hook functions are expected to copy/transfer information from the\nold relation to the new relation so that it won't be lost.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *BLOCK-NATIVE-CLASS-CREATION-HOOKS* HOOK-LIST (NEW HOOK-LIST) :DOCUMENTATION \"HOOK-LIST called by 'create-native-class', applied to\na STELLA class.  Return value of TRUE blocks creation.\")");
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

