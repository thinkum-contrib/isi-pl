// stella-in.cc

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

boolean oREDEFINE_IDENTICAL_CLASSESpo = FALSE;

Symbol* SYM_STELLA_IN_TRUE = NULL;

Symbol* SYM_STELLA_IN_FALSE = NULL;

Surrogate* SGT_STELLA_IN_GENERALIZED_SYMBOL = NULL;

Symbol* SYM_STELLA_IN_DEFMETHOD = NULL;

Keyword* KWD_STELLA_IN_PUBLIC_SLOTS = NULL;

Keyword* KWD_STELLA_IN_SLOTS = NULL;

Keyword* KWD_STELLA_IN_PUBLIC_METHODS = NULL;

Keyword* KWD_STELLA_IN_METHODS = NULL;

Keyword* KWD_STELLA_IN_PARAMETERS = NULL;

Keyword* KWD_STELLA_IN_KEY = NULL;

Keyword* KWD_STELLA_IN_SYNONYMS = NULL;

Keyword* KWD_STELLA_IN_DOCUMENTATION = NULL;

Keyword* KWD_STELLA_IN_CL_NATIVE_TYPE = NULL;

Keyword* KWD_STELLA_IN_CPP_NATIVE_TYPE = NULL;

Keyword* KWD_STELLA_IN_JAVA_NATIVE_TYPE = NULL;

Keyword* KWD_STELLA_IN_IDL_NATIVE_TYPE = NULL;

Keyword* KWD_STELLA_IN_ABSTRACTp = NULL;

Keyword* KWD_STELLA_IN_ACTIVEp = NULL;

Keyword* KWD_STELLA_IN_PUBLICp = NULL;

Keyword* KWD_STELLA_IN_CL_STRUCTp = NULL;

Keyword* KWD_STELLA_IN_MIXINp = NULL;

Keyword* KWD_STELLA_IN_RECYCLE_METHOD = NULL;

Symbol* SYM_STELLA_IN_NEXT_SWEEP_LIST_OBJECT = NULL;

Keyword* KWD_STELLA_IN_TYPE = NULL;

Keyword* KWD_STELLA_IN_EXTENSION = NULL;

Keyword* KWD_STELLA_IN_CREATOR = NULL;

Keyword* KWD_STELLA_IN_DESTRUCTOR = NULL;

Keyword* KWD_STELLA_IN_INITIALIZER = NULL;

Keyword* KWD_STELLA_IN_TERMINATOR = NULL;

Keyword* KWD_STELLA_IN_EQUALITY_TEST = NULL;

Keyword* KWD_STELLA_IN_INITIAL_VALUE = NULL;

Keyword* KWD_STELLA_IN_PRINT_FORM = NULL;

Keyword* KWD_STELLA_IN_PROPERTIES = NULL;

Keyword* KWD_STELLA_IN_META_ATTRIBUTES = NULL;

Keyword* KWD_STELLA_IN_CHILDREN = NULL;

Keyword* KWD_STELLA_IN_INITIALLY = NULL;

Keyword* KWD_STELLA_IN_DEFAULT = NULL;

Symbol* SYM_STELLA_IN_LIKE = NULL;

Keyword* KWD_STELLA_IN_ALLOCATION = NULL;

Keyword* KWD_STELLA_IN_READER = NULL;

Keyword* KWD_STELLA_IN_WRITER = NULL;

Keyword* KWD_STELLA_IN_INVERSE = NULL;

Keyword* KWD_STELLA_IN_RENAMES = NULL;

Keyword* KWD_STELLA_IN_REQUIREDp = NULL;

Keyword* KWD_STELLA_IN_COMPONENTp = NULL;

Keyword* KWD_STELLA_IN_READ_ONLYp = NULL;

Keyword* KWD_STELLA_IN_CONTEXT_SENSITIVEp = NULL;

Keyword* KWD_STELLA_IN_HARDWIREDp = NULL;

Keyword* KWD_STELLA_IN_OPTION_KEYWORD = NULL;

Keyword* KWD_STELLA_IN_OPTION_HANDLER = NULL;

Symbol* SYM_STELLA_IN_SETTER = NULL;

Keyword* KWD_STELLA_IN_RETURN_TYPES = NULL;

Keyword* KWD_STELLA_IN_STORAGE_SLOT = NULL;

Keyword* KWD_STELLA_IN_INHERITS_THROUGH = NULL;

Keyword* KWD_STELLA_IN_SETTERp = NULL;

Keyword* KWD_STELLA_IN_NATIVEp = NULL;

Keyword* KWD_STELLA_IN_AUXILIARYp = NULL;

Keyword* KWD_STELLA_IN_GLOBALLY_INLINEp = NULL;

Keyword* KWD_STELLA_IN_COMMANDp = NULL;

Keyword* KWD_STELLA_IN_LISP_MACROp = NULL;

Keyword* KWD_STELLA_IN_EVALUATE_ARGUMENTSp = NULL;

Keyword* KWD_STELLA_IN_INLINE = NULL;

Symbol* SYM_STELLA_IN_DEFUN = NULL;

List* oUNSUPPORTED_EXTERNAL_SLOT_OPTIONSo = NULL;

Keyword* KWD_STELLA_IN_DYNAMIC = NULL;

Surrogate* SGT_STELLA_IN_DYNAMIC_SLOTS_MIXIN = NULL;

Symbol* SYM_STELLA_IN_SLOT_OPTION_KEYWORD = NULL;

Method_Slot* oDEFAULT_OPTION_HANDLERo = NULL;

Symbol* SYM_STELLA_IN_DEFAULT_OPTION_HANDLER = NULL;

Symbol* SYM_STELLA_IN_SLOT_OPTION_HANDLER = NULL;

Surrogate* SGT_STELLA_IN_BOOLEAN = NULL;

Surrogate* SGT_STELLA_IN_MAPPABLE_OBJECT = NULL;

Surrogate* SGT_STELLA_IN_CONTEXT = NULL;

Object* permanentify_form(Object* form) {
  { Object* form_001 = form;

    if (symbolP(form)) {
      { Symbol* form = NULL;

        form = ((Symbol*)(form_001));
        if (form == SYM_STELLA_IN_TRUE) {
          return (form);
        }
        else if (form == SYM_STELLA_IN_FALSE) {
          return (form);
        }
        else {
          return (((Symbol*)(form->permanentify())));
        }
      }
    }
    else if (consP(form)) {
      { Cons* form = NULL;

        form = ((Cons*)(form_001));
        return (permanent_copy(form));
      }
    }
    else {
      return (form->permanentify());
    }
  }
}

Object* transientify_form(Object* form) {
  if (form != NULL) {
    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            { Object* return_value_001 = copy_cons_tree(form);

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
    return (NULL);
  }
}

List* collect_feature_list(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { List* result = NULL;

          if (tree->length() > 0) {
            result = new_list();
          }
          { Object* feature = NULL;
            Cons* iter_001 = tree;
            Cons* collect_001 = NULL;

            while (!nilP(iter_001)) {
              {
                feature = iter_001->value;
                iter_001 = iter_001->rest;
              }
              if (!isaP(feature, SGT_STELLA_IN_GENERALIZED_SYMBOL)) {
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
                          cout << endl << " " << "Ignoring illegal feature " << "`" << de_uglify_parse_tree(feature) << "'" << " in feature list: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
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
                continue;
              }
              if (collect_001 == NULL) {
                {
                  collect_001 = permanent_cons(feature->permanentify(), NIL);
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
                  collect_001->rest = permanent_cons(feature->permanentify(), NIL);
                  collect_001 = collect_001->rest;
                }
              }
            }
          }
          return (result);
        }
      }
    }
    else {
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
                cout << endl << " " << "Illegal atomic feature list: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
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
      return (NULL);
    }
  }
}

Key_Value_List* collect_key_value_list(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { int length = tree->length();
          Cons* cursor = tree;
          Object* key = NULL;
          Object* value = NULL;
          Key_Value_List* result = NULL;

          if (length == 0) {
            return (NULL);
          }
          if (oddP(length)) {
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
                      cout << endl << " " << "Unbalanced keys and values in key-value list: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
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
          result = new_key_value_list();
          while (cursor->non_emptyP()) {
            key = cursor->first();
            value = cursor->second();
            cursor = cursor->rest->rest;
            if (!isaP(key, SGT_STELLA_IN_GENERALIZED_SYMBOL)) {
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
                        cout << endl << " " << "Ignoring illegal key " << "`" << de_uglify_parse_tree(key) << "'" << " in key-value list: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
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
              continue;
            }
            if ((value == SYM_STELLA_IN_TRUE) ||
                (value == SYM_STELLA_IN_FALSE)) {
              value = symbol_to_wrapped_boolean(value);
            }
            else {
              value = permanent_copy(value);
            }
            result->insert_at(key->permanentify(), value);
          }
          return (result);
        }
      }
    }
    else {
      { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Illegal atomic key-value list: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_003;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_003;
            resignal();
          }
        }
      }
      return (NULL);
    }
  }
}

Method_Slot* define_inline_method(Symbol* name, Cons* parametersandbody) {
  { boolean dummy1;

    { Cons* parsetree = NULL;
      Method_Slot* method = NULL;

      { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oTRANSIENTOBJECTSpo = TRUE;
              parsetree = listO(3, SYM_STELLA_IN_DEFMETHOD, name, parametersandbody->concatenate(NIL));
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
      method = help_define_method_from_parse_tree(parsetree, "", dummy1);
      method->method_stringified_source = stringify(parsetree->nth_rest(3));
      return (method);
    }
  }
}

Class* help_define_class_from_parse_tree(Cons* parsetree, char* stringifiedsource) {
  { Cons* treedefinition = parsetree->rest;
    Cons* thesupers = ((Cons*)(treedefinition->second()));
    Property_List* theoptions = new_property_list();
    Surrogate* classtype = typify(treedefinition->first());
    List* directsupers = new_list();
    List* slots = new_list();
    Keyword_Key_Value_List* classoptions = new_keyword_key_value_list();
    Keyword* key = NULL;
    List* parameters = NULL;
    Cons* slottree = NULL;

    theoptions->the_plist = treedefinition->rest->rest;
    { Object* s = NULL;
      Cons* iter_001 = thesupers;
      Cons* collect_001 = NULL;

      while (!nilP(iter_001)) {
        {
          s = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = permanent_cons(typify(s), NIL);
            if (directsupers->the_cons_list->emptyP()) {
              directsupers->the_cons_list = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(directsupers->the_cons_list, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = permanent_cons(typify(s), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    { Object* thevalue = NULL;
      Object* thekey = NULL;
      Cons* iter_002 = theoptions->the_plist;

      while (!nilP(iter_002)) {
        thekey = iter_002->value;
        {
          thevalue = iter_002->rest->value;
          iter_002 = iter_002->rest->rest;
        }
        key = ((Keyword*)(thekey->permanentify()));
        if ((key == KWD_STELLA_IN_PUBLIC_SLOTS) ||
            (key == KWD_STELLA_IN_SLOTS)) {
          { Slot* localslot = NULL;

            { Object* slotdef = NULL;
              Cons* iter_003 = ((Cons*)(thevalue));
              Cons* collect_002 = NULL;

              while (!nilP(iter_003)) {
                {
                  slotdef = iter_003->value;
                  iter_003 = iter_003->rest;
                }
                if (!consP(slotdef)) {
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
                            cout << endl << " " << "Illegal slot definition:" << endl << "   " << "`" << de_uglify_parse_tree(slotdef) << "'" << endl << "." << endl;
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
                  continue;
                }
                localslot = define_storage_slot_from_parse_tree(((Cons*)(slotdef)), classtype);
                if (key == KWD_STELLA_IN_PUBLIC_SLOTS) {
                  localslot->slot_publicP = TRUE;
                }
                if (collect_002 == NULL) {
                  {
                    collect_002 = permanent_cons(localslot, NIL);
                    if (slots->the_cons_list->emptyP()) {
                      slots->the_cons_list = collect_002;
                    }
                    else {
                      add_cons_to_end_of_cons_list(slots->the_cons_list, collect_002);
                    }
                  }
                }
                else {
                  {
                    collect_002->rest = permanent_cons(localslot, NIL);
                    collect_002 = collect_002->rest;
                  }
                }
              }
            }
          }
        }
        else if ((key == KWD_STELLA_IN_PUBLIC_METHODS) ||
            (key == KWD_STELLA_IN_METHODS)) {
          { Slot* localslot = NULL;

            { Cons* methoddef = NIL;
              Cons* iter_004 = ((Cons*)(thevalue));
              Cons* collect_003 = NULL;

              while (!nilP(iter_004)) {
                {
                  methoddef = ((Cons*)(iter_004->value));
                  iter_004 = iter_004->rest;
                }
                if (!consP(methoddef)) {
                  { boolean old_OprintreadablyPO_002 = oPRINTREADABLYpo;

                    { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oPRINTREADABLYpo = TRUE;
                          signal_translation_warning();
                          if (!(suppress_warningsP())) {
                            print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                            cout << endl << " " << "Illegal inline method definition:" << endl << "   " << "`" << de_uglify_parse_tree(methoddef) << "'" << endl << "." << endl;
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
                  continue;
                }
                localslot = define_inline_method(((Symbol*)(methoddef->first())), methoddef->rest);
                if (key == KWD_STELLA_IN_PUBLIC_METHODS) {
                  localslot->slot_publicP = TRUE;
                }
                if (!(localslot->slot_owner == classtype)) {
                  { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

                    { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oPRINTREADABLYpo = TRUE;
                          signal_translation_error();
                          if (!(suppress_warningsP())) {
                            print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                            cout << endl << " " << "Defining a method for the class " << "`" << localslot->slot_owner << "'" << " inside of the class " << "`" << de_uglify_parse_tree(classtype) << "'" << "." << endl;
                          }
                          oPRINTREADABLYpo = old_OprintreadablyPO_003;
                        }
                        oEXCEPTIONo = NULL;
                      }
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
                    }
                    if (oEXCEPTIONo != NULL) {
                      if (TRUE) {
                        oPRINTREADABLYpo = old_OprintreadablyPO_003;
                        resignal();
                      }
                    }
                  }
                }
                if (collect_003 == NULL) {
                  {
                    collect_003 = permanent_cons(localslot, NIL);
                    if (slots->the_cons_list->emptyP()) {
                      slots->the_cons_list = collect_003;
                    }
                    else {
                      add_cons_to_end_of_cons_list(slots->the_cons_list, collect_003);
                    }
                  }
                }
                else {
                  {
                    collect_003->rest = permanent_cons(localslot, NIL);
                    collect_003 = collect_003->rest;
                  }
                }
              }
            }
          }
        }
        else if (key == KWD_STELLA_IN_PARAMETERS) {
          parameters = new_list();
          { Object* slotdef = NULL;
            Cons* iter_005 = ((Cons*)(thevalue));
            Cons* collect_004 = NULL;

            while (!nilP(iter_005)) {
              {
                slotdef = iter_005->value;
                iter_005 = iter_005->rest;
              }
              if (collect_004 == NULL) {
                {
                  collect_004 = permanent_cons(define_storage_slot_from_parse_tree(((Cons*)(slotdef)), classtype), NIL);
                  if (parameters->the_cons_list->emptyP()) {
                    parameters->the_cons_list = collect_004;
                  }
                  else {
                    add_cons_to_end_of_cons_list(parameters->the_cons_list, collect_004);
                  }
                }
              }
              else {
                {
                  collect_004->rest = permanent_cons(define_storage_slot_from_parse_tree(((Cons*)(slotdef)), classtype), NIL);
                  collect_004 = collect_004->rest;
                }
              }
            }
          }
          classoptions->insert_at(key, parameters);
        }
        else if (key == KWD_STELLA_IN_KEY) {
          if (!consP(thevalue)) {
            thevalue = local_cons(thekey, NIL);
          }
          in_place_objects_to_symbols(((Cons*)(thevalue)));
          classoptions->insert_at(key, ((Cons*)(thevalue)));
        }
        else if (key == KWD_STELLA_IN_SYNONYMS) {
          if (!consP(thevalue)) {
            thevalue = local_cons(thekey, NIL);
          }
          in_place_objects_to_types(((Cons*)(thevalue)));
          classoptions->insert_at(key, ((Cons*)(thevalue)));
        }
        else if ((key == KWD_STELLA_IN_DOCUMENTATION) ||
            ((key == KWD_STELLA_IN_CL_NATIVE_TYPE) ||
             ((key == KWD_STELLA_IN_CPP_NATIVE_TYPE) ||
              ((key == KWD_STELLA_IN_JAVA_NATIVE_TYPE) ||
               (key == KWD_STELLA_IN_IDL_NATIVE_TYPE))))) {
          classoptions->insert_at(key, thevalue);
        }
        else if ((key == KWD_STELLA_IN_ABSTRACTp) ||
            ((key == KWD_STELLA_IN_ACTIVEp) ||
             ((key == KWD_STELLA_IN_PUBLICp) ||
              ((key == KWD_STELLA_IN_CL_STRUCTp) ||
               (key == KWD_STELLA_IN_MIXINp))))) {
          classoptions->insert_at(key, symbol_to_wrapped_boolean(thevalue));
        }
        else if (key == KWD_STELLA_IN_RECYCLE_METHOD) {
          thevalue = thevalue->permanentify();
          classoptions->insert_at(key, thevalue);
          if (get_quoted_tree("((:SWEEP-LIST :FREE-AND-SWEEP-LIST) \"/STELLA\")", "/STELLA")->memberP(thevalue)) {
            { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

              { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oTRANSIENTOBJECTSpo = TRUE;
                    slottree = listO(4, SYM_STELLA_IN_NEXT_SWEEP_LIST_OBJECT, KWD_STELLA_IN_TYPE, treedefinition->first(), NIL);
                    oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
                  resignal();
                }
              }
            }
            slots->push(define_storage_slot_from_parse_tree(slottree, classtype));
          }
        }
        else if ((key == KWD_STELLA_IN_EXTENSION) ||
            ((key == KWD_STELLA_IN_CREATOR) ||
             ((key == KWD_STELLA_IN_DESTRUCTOR) ||
              ((key == KWD_STELLA_IN_INITIALIZER) ||
               ((key == KWD_STELLA_IN_TERMINATOR) ||
                (key == KWD_STELLA_IN_EQUALITY_TEST)))))) {
          classoptions->insert_at(key, thevalue->permanentify());
        }
        else if ((key == KWD_STELLA_IN_INITIAL_VALUE) ||
            (key == KWD_STELLA_IN_PRINT_FORM)) {
          classoptions->insert_at(key, permanentify_form(thevalue));
        }
        else if (key == KWD_STELLA_IN_PROPERTIES) {
          classoptions->insert_at(key, collect_feature_list(thevalue));
        }
        else if (key == KWD_STELLA_IN_META_ATTRIBUTES) {
          classoptions->insert_at(key, collect_key_value_list(thevalue));
        }
        else if (key == KWD_STELLA_IN_CHILDREN) {
          { Object* thevalue_001 = thevalue;

            if (consP(thevalue)) {
              { Cons* thevalue = NULL;

                thevalue = ((Cons*)(thevalue_001));
                { List* children = new_list();

                  { Object* child = NULL;
                    Cons* iter_006 = thevalue;
                    Cons* collect_005 = NULL;

                    while (!nilP(iter_006)) {
                      {
                        child = iter_006->value;
                        iter_006 = iter_006->rest;
                      }
                      if (symbolP(child)) {
                        if (collect_005 == NULL) {
                          {
                            collect_005 = permanent_cons(typify(child), NIL);
                            if (children->the_cons_list->emptyP()) {
                              children->the_cons_list = collect_005;
                            }
                            else {
                              add_cons_to_end_of_cons_list(children->the_cons_list, collect_005);
                            }
                          }
                        }
                        else {
                          {
                            collect_005->rest = permanent_cons(typify(child), NIL);
                            collect_005 = collect_005->rest;
                          }
                        }
                      }
                    }
                  }
                  classoptions->insert_at(key, children);
                }
              }
            }
            else {
              { boolean old_OprintreadablyPO_004 = oPRINTREADABLYpo;

                { jump_buffer old_OexceptionhandleraddressO_005 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTREADABLYpo = TRUE;
                      signal_translation_error();
                      if (!(suppress_warningsP())) {
                        print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                        cout << endl << " " << "Illegal :children specification: " << "`" << de_uglify_parse_tree(thevalue) << "'" << "." << endl;
                      }
                      oPRINTREADABLYpo = old_OprintreadablyPO_004;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_005;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oPRINTREADABLYpo = old_OprintreadablyPO_004;
                    resignal();
                  }
                }
              }
            }
          }
        }
        else {
          classoptions->insert_at(key, thevalue);
        }
      }
    }
    theoptions->the_plist = NULL;
    { Class* renamed_Class = define_stella_class(classtype, directsupers, slots, ((Keyword_Key_Value_List*)(classoptions->reverse())));

      if (renamed_Class != NULL) {
        renamed_Class->class_stringified_source = stringifiedsource;
      }
      return (renamed_Class);
    }
  }
}

Storage_Slot* define_storage_slot_from_parse_tree(Cons* slotdef, Surrogate* owner) {
  { Object* name = slotdef->first()->permanentify();
    Surrogate* basetype = NULL;
    Cons* typeexpression = NIL;
    Property_List* theoptions = new_property_list();
    Keyword_Key_Value_List* slotoptions = new_keyword_key_value_list();
    Keyword* key = NULL;
    Storage_Slot* slot = NULL;

    theoptions->the_plist = slotdef->rest;
    { Object* thevalue = NULL;
      Object* thekey = NULL;
      Cons* iter_001 = theoptions->the_plist;

      while (!nilP(iter_001)) {
        thekey = iter_001->value;
        {
          thevalue = iter_001->rest->value;
          iter_001 = iter_001->rest->rest;
        }
        key = ((Keyword*)(thekey->permanentify()));
        if ((key == KWD_STELLA_IN_INITIALLY) ||
            (key == KWD_STELLA_IN_DEFAULT)) {
          slotoptions->insert_at(key, permanentify_form(thevalue));
        }
        else if (key == KWD_STELLA_IN_TYPE) {
          { Object* thevalue_001 = thevalue;

            if (consP(thevalue)) {
              { Cons* thevalue = NULL;

                thevalue = ((Cons*)(thevalue_001));
                typeexpression = thevalue;
                if (thevalue->first() == SYM_STELLA_IN_LIKE) {
                  basetype = NULL;
                }
                else {
                  basetype = typify(thevalue->first());
                }
              }
            }
            else {
              basetype = typify(thevalue);
              if (defined_typeP(basetype)) {
                { Standard_Object* realtype = thevalue->yield_type_specifier();

                  basetype = type_spec_to_base_type(realtype);
                  if (!(typeP(realtype))) {
                    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

                      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                        oEXCEPTIONHANDLERADDRESSo = NULL;
                        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                          {
                            oTRANSIENTOBJECTSpo = TRUE;
                            typeexpression = ((Cons*)(yield_type_spec_tree(realtype)));
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
                }
              }
            }
          }
        }
        else if (key == KWD_STELLA_IN_ALLOCATION) {
          slotoptions->insert_at(key, thevalue->permanentify());
        }
        else if (key == KWD_STELLA_IN_READER) {
          slotoptions->insert_at(key, thevalue->permanentify());
        }
        else if (key == KWD_STELLA_IN_WRITER) {
          slotoptions->insert_at(key, thevalue->permanentify());
        }
        else if ((key == KWD_STELLA_IN_INVERSE) ||
            (key == KWD_STELLA_IN_RENAMES)) {
          slotoptions->insert_at(key, thevalue->permanentify());
        }
        else if ((key == KWD_STELLA_IN_PUBLICp) ||
            ((key == KWD_STELLA_IN_REQUIREDp) ||
             ((key == KWD_STELLA_IN_COMPONENTp) ||
              ((key == KWD_STELLA_IN_READ_ONLYp) ||
               ((key == KWD_STELLA_IN_ACTIVEp) ||
                ((key == KWD_STELLA_IN_CONTEXT_SENSITIVEp) ||
                 ((key == KWD_STELLA_IN_HARDWIREDp) ||
                  (key == KWD_STELLA_IN_ABSTRACTp)))))))) {
          slotoptions->insert_at(key, symbol_to_wrapped_boolean(thevalue));
        }
        else if (key == KWD_STELLA_IN_DOCUMENTATION) {
          slotoptions->insert_at(key, thevalue);
        }
        else if (key == KWD_STELLA_IN_PROPERTIES) {
          slotoptions->insert_at(key, collect_feature_list(thevalue));
        }
        else if (key == KWD_STELLA_IN_META_ATTRIBUTES) {
          slotoptions->insert_at(key, collect_key_value_list(thevalue));
        }
        else if ((key == KWD_STELLA_IN_OPTION_KEYWORD) ||
            (key == KWD_STELLA_IN_OPTION_HANDLER)) {
          slotoptions->insert_at(key, thevalue->permanentify());
        }
        else {
          slotoptions->insert_at(key, thevalue);
        }
      }
    }
    theoptions->the_plist = NULL;
    slot = ((Storage_Slot*)(define_stella_slot(((Symbol*)(name)), owner, basetype, typeexpression, ((Keyword_Key_Value_List*)(slotoptions->reverse())))));
    return (slot);
  }
}

Class* get_identical_class(char* classname, char* stringifiedsource) {
  { Surrogate* surrogate = lookup_surrogate(classname);
    Object* oldvalue = ((surrogate != NULL) ? ((Object*)(surrogate->surrogate_value)) : ((Object*)(NULL)));

    if (oldvalue != NULL) {
      { Object* oldvalue_001 = oldvalue;

        if (classP(oldvalue)) {
          { Class* oldvalue = NULL;

            oldvalue = ((Class*)(oldvalue_001));
            if ((oldvalue->class_stringified_source != NULL) &&
                (string_eqlP(oldvalue->class_stringified_source, stringifiedsource) &&
                 (surrogate->home_context == oMODULEo))) {
              return (oldvalue);
            }
          }
        }
        else {
        }
      }
    }
    return (NULL);
  }
}

Class* define_class_from_parse_tree(Cons* parsetree) {
  if (bad_argument_rangeP(parsetree, 2, NULL_INTEGER)) {
    return (NULL);
  }
  if (!(symbolP(parsetree->second()) &&
      consP(parsetree->third()))) {
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
              cout << endl << " " << "Illegal class definition: " << "`" << de_uglify_parse_tree(parsetree) << "'" << "." << endl;
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
  { Symbol* classname = ((Symbol*)(parsetree->second()));
    char* stringifiedsource = stringify(parsetree);
    Class* oldclass = get_identical_class(classname->symbol_name, stringifiedsource);

    if ((oldclass != NULL) &&
        (!oREDEFINE_IDENTICAL_CLASSESpo)) {
      return (oldclass);
    }
    return (help_define_class_from_parse_tree(parsetree, stringifiedsource));
  }
}

Class* define_class_from_stringified_source(char* classname, char* stringifiedsource) {
  { Class* oldclass = get_identical_class(classname, stringifiedsource);
    Cons* parsetree = NULL;
    Class* newclass = NULL;

    if ((oldclass != NULL) &&
        (!oREDEFINE_IDENTICAL_CLASSESpo)) {
      return (oldclass);
    }
    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            parsetree = ((Cons*)(unstringify(stringifiedsource)));
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
    newclass = help_define_class_from_parse_tree(parsetree, stringifiedsource);
    parsetree->free_parse_tree();
    return (newclass);
  }
}

Cons* extract_options(Cons* tree, Key_Value_List* optionstable) {
  { Cons* options = NULL;
    Cons* tail = NULL;

    while (tree->rest->non_emptyP() &&
        (!keywordP(tree->rest->value))) {
      tree = tree->rest;
    }
    if (tree->rest->emptyP() ||
        tree->rest->rest->emptyP()) {
      return (NIL);
    }
    if (optionstable != NULL) {
      optionstable->insert_at(tree->rest->value, tree->rest->rest->value);
    }
    options = tree->rest;
    tail = tree->rest->rest;
    while (tail->rest->rest->non_emptyP() &&
        keywordP(tail->rest->value)) {
      if (optionstable != NULL) {
        optionstable->insert_at(tail->rest->value, tail->rest->rest->value);
      }
      tail = tail->rest->rest;
    }
    tree->rest = tail->rest;
    tail->rest = NIL;
    return (options);
  }
}

Object* destructure_defmethod_tree(Cons* methodtree, Key_Value_List* optionstable, Cons*& return1, Cons*& return2) {
  // Return three parse trees representing the name,
  // parameters, and code body of the parse tree 'methodTree'.  Fill
  // 'optionsTable' with a dictionary of method options.
  // Storage note:  Options are treated specially because the other return
  // values are subtrees of 'methodTree', while 'optionsTable' is a newly-created
  // cons tree.  Note also, the parameter and body trees are destructively
  // removed from 'methodTree'.
  { Object* nametree = methodtree->second();
    Object* parameterstree = methodtree->third();

    if (!consP(parameterstree)) {
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
                cout << endl << " " << "Illegal parameter list: " << "`" << de_uglify_parse_tree(parameterstree) << "'" << "." << endl;
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
      parameterstree = NIL;
    }
    free_cons_list(extract_options(methodtree, optionstable));
    { Object* return_temp = nametree;

      return1 = ((Cons*)(parameterstree));
      return2 = methodtree->nth_rest(3);
      return (return_temp);
    }
  }
}

Symbol* yield_setter_method_name(Symbol* methodname) {
  return (intern_derived_symbol(methodname, string_concatenate(methodname->symbol_name, "-SETTER")));
}

Symbol* destructure_method_name_tree(Object* nametree, Cons*& return1) {
  { Object* nametree_001 = nametree;

    if (consP(nametree)) {
      { Cons* nametree = NULL;

        nametree = ((Cons*)(nametree_001));
        if (!symbolP(nametree->first())) {
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
                    cout << endl << " " << "Illegal method name: " << "`" << de_uglify_parse_tree(nametree) << "'" << "." << endl;
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
          { Symbol* return_temp = NULL;

            return1 = NULL;
            return (return_temp);
          }
        }
        if (nametree->second() == SYM_STELLA_IN_SETTER) {
          { Symbol* return_temp = yield_setter_method_name(((Symbol*)(nametree->first())));

            return1 = NIL;
            return (return_temp);
          }
        }
        else {
          { Symbol* return_temp = ((Symbol*)(nametree->first()));

            return1 = nametree->rest;
            return (return_temp);
          }
        }
      }
    }
    else if (symbolP(nametree)) {
      { Symbol* nametree = NULL;

        nametree = ((Symbol*)(nametree_001));
        { Symbol* return_temp = nametree;

          return1 = NIL;
          return (return_temp);
        }
      }
    }
    else {
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
                cout << endl << " " << "Illegal method name: " << "`" << de_uglify_parse_tree(nametree) << "'" << "." << endl;
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
      { Symbol* return_temp = NULL;

        return1 = NULL;
        return (return_temp);
      }
    }
  }
}

void in_place_normalize_method_options(Keyword_Key_Value_List* methodoptions, Symbol* methodname) {
  methodname = methodname;
  { Object* value = NULL;
    Keyword* key = NULL;
    Kv_List_Iterator* iter_001 = ((Kv_List_Iterator*)(methodoptions->allocate_iterator()));

    while (iter_001->nextP()) {
      key = ((Keyword*)(iter_001->key));
      {
        value = iter_001->value;
      }
      if ((key == KWD_STELLA_IN_TYPE) ||
          (key == KWD_STELLA_IN_RETURN_TYPES)) {
      }
      else if ((key == KWD_STELLA_IN_RENAMES) ||
          ((key == KWD_STELLA_IN_STORAGE_SLOT) ||
           (key == KWD_STELLA_IN_INHERITS_THROUGH))) {
        methodoptions->insert_at(key, value->permanentify());
      }
      else if ((key == KWD_STELLA_IN_PUBLICp) ||
          ((key == KWD_STELLA_IN_SETTERp) ||
           ((key == KWD_STELLA_IN_NATIVEp) ||
            ((key == KWD_STELLA_IN_AUXILIARYp) ||
             ((key == KWD_STELLA_IN_GLOBALLY_INLINEp) ||
              ((key == KWD_STELLA_IN_COMMANDp) ||
               ((key == KWD_STELLA_IN_LISP_MACROp) ||
                (key == KWD_STELLA_IN_EVALUATE_ARGUMENTSp)))))))) {
        methodoptions->insert_at(key, symbol_to_wrapped_boolean(value));
      }
      else if (key == KWD_STELLA_IN_DOCUMENTATION) {
        methodoptions->insert_at(key, value);
      }
      else if (key == KWD_STELLA_IN_INLINE) {
        { Object* value_001 = value;

          if (symbolP(value)) {
            { Symbol* value = NULL;

              value = ((Symbol*)(value_001));
              methodoptions->insert_at(key, ((Symbol*)(value->permanentify())));
            }
          }
          else if (consP(value)) {
            { Cons* value = NULL;

              value = ((Cons*)(value_001));
              { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

                { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oTRANSIENTOBJECTSpo = FALSE;
                      { Cons* symbolslist = NIL;

                        { Object* symbol = NULL;
                          Cons* iter_002 = value;
                          Cons* collect_001 = NULL;

                          while (!nilP(iter_002)) {
                            {
                              symbol = iter_002->value;
                              iter_002 = iter_002->rest;
                            }
                            if (collect_001 == NULL) {
                              {
                                collect_001 = cons(symbol->permanentify(), NIL);
                                if (nilP(symbolslist)) {
                                  symbolslist = collect_001;
                                }
                                else {
                                  add_cons_to_end_of_cons_list(symbolslist, collect_001);
                                }
                              }
                            }
                            else {
                              {
                                collect_001->rest = cons(symbol->permanentify(), NIL);
                                collect_001 = collect_001->rest;
                              }
                            }
                          }
                        }
                        methodoptions->insert_at(key, symbolslist);
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
          }
          else {
            cerr << "`" << value << "'" << " is not a valid case option";
          }
        }
      }
      else if (key == KWD_STELLA_IN_PROPERTIES) {
        methodoptions->insert_at(key, collect_feature_list(value));
      }
      else if (key == KWD_STELLA_IN_META_ATTRIBUTES) {
        methodoptions->insert_at(key, collect_key_value_list(value));
      }
      else {
        methodoptions->insert_at(key, value->permanentify());
      }
    }
  }
  methodoptions->reverse();
}

Method_Slot* get_function_with_identical_signature(Symbol* name, char* stringifiedsource) {
  { Method_Slot* oldmethod = lookup_function_or_stella_function(name);

    if ((oldmethod != NULL) &&
        string_eqlP(oldmethod->method_stringified_source, stringifiedsource)) {
      return (oldmethod);
    }
    return (NULL);
  }
}

Method_Slot* get_method_with_identical_signature(Symbol* name, Cons* parameterstree, char* stringifiedsource) {
  { Slot* existingslot = NULL;

    if (consP(parameterstree->first())) {
      parameterstree = ((Cons*)(parameterstree->first()));
      if (symbolP(parameterstree->last())) {
        existingslot = safe_lookup_slot(type_to_class(typify(((Symbol*)(parameterstree->last())))), name);
        if (existingslot != NULL) {
          { Slot* existingslot_001 = existingslot;

            if (method_slotP(existingslot)) {
              { Method_Slot* existingslot = NULL;

                existingslot = ((Method_Slot*)(existingslot_001));
                if (string_eqlP(existingslot->method_stringified_source, stringifiedsource)) {
                  return (existingslot);
                }
              }
            }
            else {
            }
          }
        }
      }
    }
    return (NULL);
  }
}

Method_Slot* help_define_method_from_parse_tree(Cons* inputtree, char* stringifiedsource, boolean& return1) {
  { Object* nametree = NULL;
    Cons* parameterstree = NULL;
    Keyword_Key_Value_List* methodoptions = new_keyword_key_value_list();
    Cons* bodytree = NULL;
    Symbol* name = NULL;
    Cons* returntypestree = NULL;
    boolean functionP = inputtree->first() == SYM_STELLA_IN_DEFUN;
    Method_Slot* oldmethod = NULL;

    nametree = destructure_defmethod_tree(inputtree, methodoptions, parameterstree, bodytree);
    name = destructure_method_name_tree(nametree, returntypestree);
    if (name == NULL) {
      { Method_Slot* return_temp = NULL;

        return1 = FALSE;
        return (return_temp);
      }
    }
    oldmethod = (functionP ? ((Method_Slot*)(get_function_with_identical_signature(name, stringifiedsource))) : ((Method_Slot*)(get_method_with_identical_signature(name, parameterstree, stringifiedsource))));
    if (oldmethod != NULL) {
      { Method_Slot* return_temp = oldmethod;

        return1 = TRUE;
        return (return_temp);
      }
    }
    in_place_normalize_method_options(methodoptions, name);
    { Method_Slot* method = define_stella_method_slot(name, returntypestree, functionP, parameterstree, methodoptions, bodytree);

      method->method_stringified_source = stringifiedsource;
      { Method_Slot* return_temp = method;

        return1 = FALSE;
        return (return_temp);
      }
    }
  }
}

Method_Slot* define_method_from_parse_tree(Cons* parsetree) {
  if (bad_argument_rangeP(parsetree, 2, NULL_INTEGER)) {
    return (NULL);
  }
  { Method_Slot* method = NULL;
    boolean identicalmethodP = FALSE;

    method = help_define_method_from_parse_tree(parsetree, stringify_method_definition_tree(parsetree), identicalmethodP);
    if (!(identicalmethodP ||
        ((method == NULL) ||
         method->method_auxiliaryP_reader()))) {
      attach_method_slot_to_owner(method);
    }
    return (method);
  }
}

char* stringify_method_definition_tree(Cons* parsetree) {
  { Cons* signature = NIL;
    char* signaturestring = NULL;
    Cons* optionstree = parsetree->nth_rest(3);

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            signature = cons(parsetree->first(), signature);
            signature = cons(parsetree->second(), signature);
            signature = cons(parsetree->third(), signature);
            while (keywordP(optionstree->first())) {
              signature = cons(optionstree->first(), signature);
              signature = cons(optionstree->second(), signature);
              optionstree = optionstree->rest->rest;
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
    signaturestring = stringify(signature->reverse());
    free_cons_list(signature);
    return (signaturestring);
  }
}

Method_Slot* define_method_from_stringified_source(char* methodname, char* classname, char* stringifiedsource) {
  {
    methodname = methodname;
    classname = classname;
  }
  { Cons* parsetree = NULL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            parsetree = ((Cons*)(unstringify(stringifiedsource)));
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
    { Method_Slot* method = NULL;
      boolean identicalmethodP = FALSE;

      method = help_define_method_from_parse_tree(parsetree, stringifiedsource, identicalmethodP);
      parsetree->free_parse_tree();
      if (!(identicalmethodP ||
          method->method_auxiliaryP_reader())) {
        attach_method_slot_to_owner(method);
      }
      return (method);
    }
  }
}

Storage_Slot* define_external_slot_from_parse_tree(Cons* parsetree) {
  if (bad_argument_rangeP(parsetree, 2, NULL_INTEGER)) {
    return (NULL);
  }
  if ((!symbolP(parsetree->second())) ||
      ((!symbolP(parsetree->third())) ||
       (!evenP(parsetree->nth_rest(3)->length())))) {
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
              cout << endl << " " << "Illegal external slot definition: " << "`" << de_uglify_parse_tree(parsetree) << "'" << "." << endl;
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
  { Symbol* classname = ((Symbol*)(parsetree->second()));
    Surrogate* owner = typify(classname);
    Class* ownerclass = ((Class*)(owner->surrogate_value));
    Storage_Slot* slot = NULL;
    Cons* options = parsetree->nth_rest(3);
    Class* marker = string_get_class("SLOT", TRUE);
    boolean abstractP = FALSE;

    if (ownerclass == NULL) {
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
                cout << endl << " " << "Can't define a slot on the non-existent class " << "`" << de_uglify_parse_tree(classname) << "'" << "." << endl;
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
      return (NULL);
    }
    while (options->non_emptyP()) {
      { Object* option = options->first();
        Object* value = options->second();

        if (oUNSUPPORTED_EXTERNAL_SLOT_OPTIONSo->memberP(((Keyword*)(option)))) {
          if ((!(option == KWD_STELLA_IN_ALLOCATION)) ||
              (!(value == KWD_STELLA_IN_DYNAMIC))) {
            { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    signal_translation_warning();
                    if (!(suppress_warningsP())) {
                      print_error_context(">> WARNING: ", STANDARD_OUTPUT);
                      cout << endl << " " << "Skipping slot option " << "`" << de_uglify_parse_tree(option) << "'" << " which is unsupported on external slots" << "." << endl;
                    }
                    oPRINTREADABLYpo = old_OprintreadablyPO_003;
                  }
                  oEXCEPTIONo = NULL;
                }
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
              }
              if (oEXCEPTIONo != NULL) {
                if (TRUE) {
                  oPRINTREADABLYpo = old_OprintreadablyPO_003;
                  resignal();
                }
              }
            }
          }
          options->first_setter(marker);
          if (value != NULL) {
            options->second_setter(marker);
          }
        }
        if (((option == KWD_STELLA_IN_ABSTRACTp) &&
            (value == SYM_STELLA_IN_TRUE)) ||
            (option == KWD_STELLA_IN_RENAMES)) {
          abstractP = TRUE;
        }
      }
      options = options->rest->rest;
    }
    if ((!abstractP) &&
        (ownerclass->class_finalizedP &&
         (!subtype_ofP(owner, SGT_STELLA_IN_DYNAMIC_SLOTS_MIXIN)))) {
      { boolean old_OprintreadablyPO_004 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_004 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              signal_translation_error();
              if (!(suppress_warningsP())) {
                print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                cout << endl << " " << "Can't define a non-abstract external slot on class " << "`" << de_uglify_parse_tree(classname) << "'" << "," << endl << " since it does not inherit DYNAMIC-SLOTS-MIXIN" << "." << endl;
              }
              oPRINTREADABLYpo = old_OprintreadablyPO_004;
            }
            oEXCEPTIONo = NULL;
          }
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_004;
        }
        if (oEXCEPTIONo != NULL) {
          if (TRUE) {
            oPRINTREADABLYpo = old_OprintreadablyPO_004;
            resignal();
          }
        }
      }
      return (NULL);
    }
    parsetree = parsetree->remove(marker);
    if (!(abstractP)) {
      parsetree = parsetree->concatenate(listO(3, KWD_STELLA_IN_ALLOCATION, KWD_STELLA_IN_DYNAMIC, NIL));
    }
    slot = define_storage_slot_from_parse_tree(parsetree->rest->rest, owner);
    if (slot != NULL) {
      attach_slot_to_owner(slot);
    }
    return (slot);
  }
}

Storage_Slot* define_external_slot_from_stringified_source(char* stringifiedsource) {
  return (define_external_slot_from_parse_tree(((Cons*)(unstringify(stringifiedsource)))));
}

Storage_Slot* lookup_slot_from_option_keyword(Surrogate* owner, Keyword* keyword) {
  { Class* ownerclass = ((Class*)(owner->surrogate_value));

    if (ownerclass != NULL) {
      { Slot* slot = NULL;
        Iterator* iter_001 = ownerclass->class_slots();

        while (iter_001->nextP()) {
          {
            slot = ((Slot*)(iter_001->value));
          }
          if (storage_slotP(slot) &&
              (dynamic_slot_value(((Storage_Slot*)(slot)), SYM_STELLA_IN_SLOT_OPTION_KEYWORD, NULL) == keyword)) {
            return (((Storage_Slot*)(slot)));
          }
        }
      }
    }
    return (NULL);
  }
}

Method_Slot* lookup_option_handler(Storage_Slot* slot) {
  { Symbol* handlername = ((Symbol*)(dynamic_slot_value(slot, SYM_STELLA_IN_SLOT_OPTION_HANDLER, NULL)));
    Method_Slot* handler = NULL;

    if (handlername == NULL) {
      if (oDEFAULT_OPTION_HANDLERo != NULL) {
        return (oDEFAULT_OPTION_HANDLERo);
      }
      else {
        return (SYM_STELLA_IN_DEFAULT_OPTION_HANDLER->lookup_function());
      }
    }
    handler = handlername->lookup_function();
    if ((oSAFETYo >= 2) &&
        ((handler != NULL) &&
         ((!(handlername == SYM_STELLA_IN_DEFAULT_OPTION_HANDLER)) &&
          (!handler->conforming_signaturesP(oDEFAULT_OPTION_HANDLERo))))) {
      cerr << "The signature of slot option handler " << "`" << handlername << "'" << " does not conform to that of 'default-option-handler'.";
    }
    return (handler);
  }
}

boolean run_option_handlerP(Object* object, Keyword* option, Object* valuetree) {
  { Storage_Slot* slot = lookup_slot_from_option_keyword(object->primary_type(), option);
    Method_Slot* handler = ((slot != NULL) ? ((Method_Slot*)(lookup_option_handler(slot))) : ((Method_Slot*)(NULL)));

    if (handler != NULL) {
      ((void (*) (Object*, Storage_Slot*, Object*))handler->function_code)(object, slot, valuetree);
      return (TRUE);
    }
    return (FALSE);
  }
}

void default_option_handler(Object* self, Storage_Slot* slot, Object* tree) {
  { Object* parsedvalue = tree->permanentify();

    { Surrogate* test_value_001 = slot->type();

      if (test_value_001 == SGT_STELLA_IN_BOOLEAN) {
        parsedvalue = symbol_to_wrapped_boolean(tree);
      }
      else {
      }
    }
    if (oSAFETYo >= 2) {
      if (!isaP(parsedvalue, slot->type()->type_to_wrapped_type())) {
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
                  cout << endl << " " << "Illegal value for " << "`" << ((Keyword*)(dynamic_slot_value(slot, SYM_STELLA_IN_SLOT_OPTION_KEYWORD, NULL))) << "'" << " option: " << "`" << de_uglify_parse_tree(tree) << "'" << "." << endl;
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
        return;
      }
      if (!isaP(self, SGT_STELLA_IN_DYNAMIC_SLOTS_MIXIN)) {
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
                  cout << endl << " " << "Cannot set option " << "`" << ((Keyword*)(dynamic_slot_value(slot, SYM_STELLA_IN_SLOT_OPTION_KEYWORD, NULL))) << "'" << " on " << "`" << de_uglify_parse_tree(self) << "'" << "," << endl << " since that object does not support dynamic slots" << "." << endl;
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
        return;
      }
      if (!(slot->allocation() == KWD_STELLA_IN_DYNAMIC)) {
        { boolean old_OprintreadablyPO_003 = oPRINTREADABLYpo;

          { jump_buffer old_OexceptionhandleraddressO_003 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTREADABLYpo = TRUE;
                signal_translation_error();
                if (!(suppress_warningsP())) {
                  print_error_context(">> ERROR: ", STANDARD_OUTPUT);
                  cout << endl << " " << "default-option-handler: Don't know how to handle option " << "`" << ((Keyword*)(dynamic_slot_value(slot, SYM_STELLA_IN_SLOT_OPTION_KEYWORD, NULL))) << "'" << endl << " for the non-dynamic slot " << "`" << type_to_symbol(slot->slot_owner) << "'" << "." << "`" << slot->slot_name << "'" << "." << endl;
                }
                oPRINTREADABLYpo = old_OprintreadablyPO_003;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_003;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTREADABLYpo = old_OprintreadablyPO_003;
              resignal();
            }
          }
        }
        return;
      }
    }
    { Object* self_001 = self;

      if (taxonomy_isaP(self, SGT_STELLA_IN_MAPPABLE_OBJECT)) {
        { Mappable_Object* self = NULL;

          self = ((Mappable_Object*)(self_001));
          set_dynamic_slot_value(self, slot->slot_name, parsedvalue, NULL);
        }
      }
      else if (taxonomy_isaP(self, SGT_STELLA_IN_CONTEXT)) {
        { Context* self = NULL;

          self = ((Context*)(self_001));
          set_dynamic_slot_value(self, slot->slot_name, parsedvalue, NULL);
        }
      }
      else {
        cerr << "default-option-handler: Don't know how to set slot " << "`" << slot->slot_name << "'" << endl << " on object " << "`" << self << "'" << " of type " << "`" << self->primary_type() << "'" << ".";
      }
    }
  }
}

void startup_stella_in() {
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
            SYM_STELLA_IN_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            SYM_STELLA_IN_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", NULL, 0)));
            SGT_STELLA_IN_GENERALIZED_SYMBOL = ((Surrogate*)(intern_rigid_symbol_wrt_module("GENERALIZED-SYMBOL", NULL, 1)));
            SYM_STELLA_IN_DEFMETHOD = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFMETHOD", NULL, 0)));
            KWD_STELLA_IN_PUBLIC_SLOTS = ((Keyword*)(intern_rigid_symbol_wrt_module("PUBLIC-SLOTS", NULL, 2)));
            KWD_STELLA_IN_SLOTS = ((Keyword*)(intern_rigid_symbol_wrt_module("SLOTS", NULL, 2)));
            KWD_STELLA_IN_PUBLIC_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("PUBLIC-METHODS", NULL, 2)));
            KWD_STELLA_IN_METHODS = ((Keyword*)(intern_rigid_symbol_wrt_module("METHODS", NULL, 2)));
            KWD_STELLA_IN_PARAMETERS = ((Keyword*)(intern_rigid_symbol_wrt_module("PARAMETERS", NULL, 2)));
            KWD_STELLA_IN_KEY = ((Keyword*)(intern_rigid_symbol_wrt_module("KEY", NULL, 2)));
            KWD_STELLA_IN_SYNONYMS = ((Keyword*)(intern_rigid_symbol_wrt_module("SYNONYMS", NULL, 2)));
            KWD_STELLA_IN_DOCUMENTATION = ((Keyword*)(intern_rigid_symbol_wrt_module("DOCUMENTATION", NULL, 2)));
            KWD_STELLA_IN_CL_NATIVE_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("CL-NATIVE-TYPE", NULL, 2)));
            KWD_STELLA_IN_CPP_NATIVE_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("CPP-NATIVE-TYPE", NULL, 2)));
            KWD_STELLA_IN_JAVA_NATIVE_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("JAVA-NATIVE-TYPE", NULL, 2)));
            KWD_STELLA_IN_IDL_NATIVE_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("IDL-NATIVE-TYPE", NULL, 2)));
            KWD_STELLA_IN_ABSTRACTp = ((Keyword*)(intern_rigid_symbol_wrt_module("ABSTRACT?", NULL, 2)));
            KWD_STELLA_IN_ACTIVEp = ((Keyword*)(intern_rigid_symbol_wrt_module("ACTIVE?", NULL, 2)));
            KWD_STELLA_IN_PUBLICp = ((Keyword*)(intern_rigid_symbol_wrt_module("PUBLIC?", NULL, 2)));
            KWD_STELLA_IN_CL_STRUCTp = ((Keyword*)(intern_rigid_symbol_wrt_module("CL-STRUCT?", NULL, 2)));
            KWD_STELLA_IN_MIXINp = ((Keyword*)(intern_rigid_symbol_wrt_module("MIXIN?", NULL, 2)));
            KWD_STELLA_IN_RECYCLE_METHOD = ((Keyword*)(intern_rigid_symbol_wrt_module("RECYCLE-METHOD", NULL, 2)));
            SYM_STELLA_IN_NEXT_SWEEP_LIST_OBJECT = ((Symbol*)(intern_rigid_symbol_wrt_module("NEXT-SWEEP-LIST-OBJECT", NULL, 0)));
            KWD_STELLA_IN_TYPE = ((Keyword*)(intern_rigid_symbol_wrt_module("TYPE", NULL, 2)));
            KWD_STELLA_IN_EXTENSION = ((Keyword*)(intern_rigid_symbol_wrt_module("EXTENSION", NULL, 2)));
            KWD_STELLA_IN_CREATOR = ((Keyword*)(intern_rigid_symbol_wrt_module("CREATOR", NULL, 2)));
            KWD_STELLA_IN_DESTRUCTOR = ((Keyword*)(intern_rigid_symbol_wrt_module("DESTRUCTOR", NULL, 2)));
            KWD_STELLA_IN_INITIALIZER = ((Keyword*)(intern_rigid_symbol_wrt_module("INITIALIZER", NULL, 2)));
            KWD_STELLA_IN_TERMINATOR = ((Keyword*)(intern_rigid_symbol_wrt_module("TERMINATOR", NULL, 2)));
            KWD_STELLA_IN_EQUALITY_TEST = ((Keyword*)(intern_rigid_symbol_wrt_module("EQUALITY-TEST", NULL, 2)));
            KWD_STELLA_IN_INITIAL_VALUE = ((Keyword*)(intern_rigid_symbol_wrt_module("INITIAL-VALUE", NULL, 2)));
            KWD_STELLA_IN_PRINT_FORM = ((Keyword*)(intern_rigid_symbol_wrt_module("PRINT-FORM", NULL, 2)));
            KWD_STELLA_IN_PROPERTIES = ((Keyword*)(intern_rigid_symbol_wrt_module("PROPERTIES", NULL, 2)));
            KWD_STELLA_IN_META_ATTRIBUTES = ((Keyword*)(intern_rigid_symbol_wrt_module("META-ATTRIBUTES", NULL, 2)));
            KWD_STELLA_IN_CHILDREN = ((Keyword*)(intern_rigid_symbol_wrt_module("CHILDREN", NULL, 2)));
            KWD_STELLA_IN_INITIALLY = ((Keyword*)(intern_rigid_symbol_wrt_module("INITIALLY", NULL, 2)));
            KWD_STELLA_IN_DEFAULT = ((Keyword*)(intern_rigid_symbol_wrt_module("DEFAULT", NULL, 2)));
            SYM_STELLA_IN_LIKE = ((Symbol*)(intern_rigid_symbol_wrt_module("LIKE", NULL, 0)));
            KWD_STELLA_IN_ALLOCATION = ((Keyword*)(intern_rigid_symbol_wrt_module("ALLOCATION", NULL, 2)));
            KWD_STELLA_IN_READER = ((Keyword*)(intern_rigid_symbol_wrt_module("READER", NULL, 2)));
            KWD_STELLA_IN_WRITER = ((Keyword*)(intern_rigid_symbol_wrt_module("WRITER", NULL, 2)));
            KWD_STELLA_IN_INVERSE = ((Keyword*)(intern_rigid_symbol_wrt_module("INVERSE", NULL, 2)));
            KWD_STELLA_IN_RENAMES = ((Keyword*)(intern_rigid_symbol_wrt_module("RENAMES", NULL, 2)));
            KWD_STELLA_IN_REQUIREDp = ((Keyword*)(intern_rigid_symbol_wrt_module("REQUIRED?", NULL, 2)));
            KWD_STELLA_IN_COMPONENTp = ((Keyword*)(intern_rigid_symbol_wrt_module("COMPONENT?", NULL, 2)));
            KWD_STELLA_IN_READ_ONLYp = ((Keyword*)(intern_rigid_symbol_wrt_module("READ-ONLY?", NULL, 2)));
            KWD_STELLA_IN_CONTEXT_SENSITIVEp = ((Keyword*)(intern_rigid_symbol_wrt_module("CONTEXT-SENSITIVE?", NULL, 2)));
            KWD_STELLA_IN_HARDWIREDp = ((Keyword*)(intern_rigid_symbol_wrt_module("HARDWIRED?", NULL, 2)));
            KWD_STELLA_IN_OPTION_KEYWORD = ((Keyword*)(intern_rigid_symbol_wrt_module("OPTION-KEYWORD", NULL, 2)));
            KWD_STELLA_IN_OPTION_HANDLER = ((Keyword*)(intern_rigid_symbol_wrt_module("OPTION-HANDLER", NULL, 2)));
            SYM_STELLA_IN_SETTER = ((Symbol*)(intern_rigid_symbol_wrt_module("SETTER", NULL, 0)));
            KWD_STELLA_IN_RETURN_TYPES = ((Keyword*)(intern_rigid_symbol_wrt_module("RETURN-TYPES", NULL, 2)));
            KWD_STELLA_IN_STORAGE_SLOT = ((Keyword*)(intern_rigid_symbol_wrt_module("STORAGE-SLOT", NULL, 2)));
            KWD_STELLA_IN_INHERITS_THROUGH = ((Keyword*)(intern_rigid_symbol_wrt_module("INHERITS-THROUGH", NULL, 2)));
            KWD_STELLA_IN_SETTERp = ((Keyword*)(intern_rigid_symbol_wrt_module("SETTER?", NULL, 2)));
            KWD_STELLA_IN_NATIVEp = ((Keyword*)(intern_rigid_symbol_wrt_module("NATIVE?", NULL, 2)));
            KWD_STELLA_IN_AUXILIARYp = ((Keyword*)(intern_rigid_symbol_wrt_module("AUXILIARY?", NULL, 2)));
            KWD_STELLA_IN_GLOBALLY_INLINEp = ((Keyword*)(intern_rigid_symbol_wrt_module("GLOBALLY-INLINE?", NULL, 2)));
            KWD_STELLA_IN_COMMANDp = ((Keyword*)(intern_rigid_symbol_wrt_module("COMMAND?", NULL, 2)));
            KWD_STELLA_IN_LISP_MACROp = ((Keyword*)(intern_rigid_symbol_wrt_module("LISP-MACRO?", NULL, 2)));
            KWD_STELLA_IN_EVALUATE_ARGUMENTSp = ((Keyword*)(intern_rigid_symbol_wrt_module("EVALUATE-ARGUMENTS?", NULL, 2)));
            KWD_STELLA_IN_INLINE = ((Keyword*)(intern_rigid_symbol_wrt_module("INLINE", NULL, 2)));
            SYM_STELLA_IN_DEFUN = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFUN", NULL, 0)));
            KWD_STELLA_IN_DYNAMIC = ((Keyword*)(intern_rigid_symbol_wrt_module("DYNAMIC", NULL, 2)));
            SGT_STELLA_IN_DYNAMIC_SLOTS_MIXIN = ((Surrogate*)(intern_rigid_symbol_wrt_module("DYNAMIC-SLOTS-MIXIN", NULL, 1)));
            SYM_STELLA_IN_SLOT_OPTION_KEYWORD = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-OPTION-KEYWORD", NULL, 0)));
            SYM_STELLA_IN_DEFAULT_OPTION_HANDLER = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFAULT-OPTION-HANDLER", NULL, 0)));
            SYM_STELLA_IN_SLOT_OPTION_HANDLER = ((Symbol*)(intern_rigid_symbol_wrt_module("SLOT-OPTION-HANDLER", NULL, 0)));
            SGT_STELLA_IN_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", NULL, 1)));
            SGT_STELLA_IN_MAPPABLE_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("MAPPABLE-OBJECT", NULL, 1)));
            SGT_STELLA_IN_CONTEXT = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONTEXT", NULL, 1)));
          }
          if (current_startup_time_phaseP(4)) {
            oUNSUPPORTED_EXTERNAL_SLOT_OPTIONSo = list(4, KWD_STELLA_IN_ALLOCATION, KWD_STELLA_IN_INITIALLY, KWD_STELLA_IN_CONTEXT_SENSITIVEp, KWD_STELLA_IN_HARDWIREDp);
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("PERMANENTIFY-FORM", "OBJECT", "(DEFUN (PERMANENTIFY-FORM OBJECT) ((FORM OBJECT)))");

              method->function_code = ((cpp_function_code)(&permanentify_form));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSIENTIFY-FORM", "OBJECT", "(DEFUN (TRANSIENTIFY-FORM OBJECT) ((FORM OBJECT)))");

              method->function_code = ((cpp_function_code)(&transientify_form));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-FEATURE-LIST", "OBJECT", "(DEFUN (COLLECT-FEATURE-LIST (LIST OF GENERALIZED-SYMBOL)) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&collect_feature_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-KEY-VALUE-LIST", "OBJECT", "(DEFUN (COLLECT-KEY-VALUE-LIST (KEY-VALUE-LIST OF GENERALIZED-SYMBOL OBJECT)) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&collect_key_value_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-INLINE-METHOD", "SYMBOL", "(DEFUN (DEFINE-INLINE-METHOD METHOD-SLOT) ((NAME SYMBOL) (PARAMETERSANDBODY CONS)))");

              method->function_code = ((cpp_function_code)(&define_inline_method));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-DEFINE-CLASS-FROM-PARSE-TREE", "CONS", "(DEFUN (HELP-DEFINE-CLASS-FROM-PARSE-TREE CLASS) ((PARSETREE CONS) (STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&help_define_class_from_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-STORAGE-SLOT-FROM-PARSE-TREE", "CONS", "(DEFUN (DEFINE-STORAGE-SLOT-FROM-PARSE-TREE STORAGE-SLOT) ((SLOTDEF CONS) (OWNER TYPE)))");

              method->function_code = ((cpp_function_code)(&define_storage_slot_from_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-IDENTICAL-CLASS", "STRING", "(DEFUN (GET-IDENTICAL-CLASS CLASS) ((CLASSNAME STRING) (STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&get_identical_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-CLASS-FROM-PARSE-TREE", "CONS", "(DEFUN (DEFINE-CLASS-FROM-PARSE-TREE CLASS) ((PARSETREE CONS)))");

              method->function_code = ((cpp_function_code)(&define_class_from_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-CLASS-FROM-STRINGIFIED-SOURCE", "STRING", "(DEFUN (DEFINE-CLASS-FROM-STRINGIFIED-SOURCE CLASS) ((CLASSNAME STRING) (STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&define_class_from_stringified_source));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-OPTIONS", "CONS", "(DEFUN (EXTRACT-OPTIONS CONS) ((TREE CONS) (OPTIONSTABLE KEY-VALUE-LIST)))");

              method->function_code = ((cpp_function_code)(&extract_options));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTRUCTURE-DEFMETHOD-TREE", "CONS", "(DEFUN (DESTRUCTURE-DEFMETHOD-TREE OBJECT CONS CONS) ((METHODTREE CONS) (OPTIONSTABLE KEY-VALUE-LIST)) :DOCUMENTATION \"Return three parse trees representing the name,\nparameters, and code body of the parse tree 'methodTree'.  Fill\n'optionsTable' with a dictionary of method options.\nStorage note:  Options are treated specially because the other return\nvalues are subtrees of 'methodTree', while 'optionsTable' is a newly-created\ncons tree.  Note also, the parameter and body trees are destructively\nremoved from 'methodTree'.\")");

              method->function_code = ((cpp_function_code)(&destructure_defmethod_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SETTER-METHOD-NAME", "SYMBOL", "(DEFUN (YIELD-SETTER-METHOD-NAME SYMBOL) ((METHODNAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_setter_method_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESTRUCTURE-METHOD-NAME-TREE", "OBJECT", "(DEFUN (DESTRUCTURE-METHOD-NAME-TREE SYMBOL CONS) ((NAMETREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&destructure_method_name_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("IN-PLACE-NORMALIZE-METHOD-OPTIONS", "KEYWORD-KEY-VALUE-LIST", "(DEFUN IN-PLACE-NORMALIZE-METHOD-OPTIONS ((METHODOPTIONS KEYWORD-KEY-VALUE-LIST) (METHODNAME SYMBOL)))");

              method->function_code = ((cpp_function_code)(&in_place_normalize_method_options));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-FUNCTION-WITH-IDENTICAL-SIGNATURE", "SYMBOL", "(DEFUN (GET-FUNCTION-WITH-IDENTICAL-SIGNATURE METHOD-SLOT) ((NAME SYMBOL) (STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&get_function_with_identical_signature));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-METHOD-WITH-IDENTICAL-SIGNATURE", "SYMBOL", "(DEFUN (GET-METHOD-WITH-IDENTICAL-SIGNATURE METHOD-SLOT) ((NAME SYMBOL) (PARAMETERSTREE CONS) (STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&get_method_with_identical_signature));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-DEFINE-METHOD-FROM-PARSE-TREE", "CONS", "(DEFUN (HELP-DEFINE-METHOD-FROM-PARSE-TREE METHOD-SLOT BOOLEAN) ((INPUTTREE CONS) (STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&help_define_method_from_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-METHOD-FROM-PARSE-TREE", "CONS", "(DEFUN (DEFINE-METHOD-FROM-PARSE-TREE METHOD-SLOT) ((PARSETREE CONS)))");

              method->function_code = ((cpp_function_code)(&define_method_from_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("STRINGIFY-METHOD-DEFINITION-TREE", "CONS", "(DEFUN (STRINGIFY-METHOD-DEFINITION-TREE STRING) ((PARSETREE CONS)))");

              method->function_code = ((cpp_function_code)(&stringify_method_definition_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-METHOD-FROM-STRINGIFIED-SOURCE", "STRING", "(DEFUN (DEFINE-METHOD-FROM-STRINGIFIED-SOURCE METHOD-SLOT) ((METHODNAME STRING) (CLASSNAME STRING) (STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&define_method_from_stringified_source));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-EXTERNAL-SLOT-FROM-PARSE-TREE", "CONS", "(DEFUN (DEFINE-EXTERNAL-SLOT-FROM-PARSE-TREE STORAGE-SLOT) ((PARSETREE CONS)))");

              method->function_code = ((cpp_function_code)(&define_external_slot_from_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-EXTERNAL-SLOT-FROM-STRINGIFIED-SOURCE", "STRING", "(DEFUN (DEFINE-EXTERNAL-SLOT-FROM-STRINGIFIED-SOURCE STORAGE-SLOT) ((STRINGIFIEDSOURCE STRING)))");

              method->function_code = ((cpp_function_code)(&define_external_slot_from_stringified_source));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-SLOT-FROM-OPTION-KEYWORD", "TYPE", "(DEFUN (LOOKUP-SLOT-FROM-OPTION-KEYWORD STORAGE-SLOT) ((OWNER TYPE) (KEYWORD KEYWORD)))");

              method->function_code = ((cpp_function_code)(&lookup_slot_from_option_keyword));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-OPTION-HANDLER", "STORAGE-SLOT", "(DEFUN (LOOKUP-OPTION-HANDLER METHOD-SLOT) ((SLOT STORAGE-SLOT)))");

              method->function_code = ((cpp_function_code)(&lookup_option_handler));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-OPTION-HANDLER?", "OBJECT", "(DEFUN (RUN-OPTION-HANDLER? BOOLEAN) ((OBJECT OBJECT) (OPTION KEYWORD) (VALUETREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&run_option_handlerP));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFAULT-OPTION-HANDLER", "OBJECT", "(DEFUN DEFAULT-OPTION-HANDLER ((SELF OBJECT) (SLOT STORAGE-SLOT) (TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&default_option_handler));
            }
            define_method_from_stringified_source("STARTUP-STELLA-IN", NULL, "(DEFUN STARTUP-STELLA-IN ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *REDEFINE-IDENTICAL-CLASSES?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE, always redefine classes, even if an\n                  identical class exists\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *UNSUPPORTED-EXTERNAL-SLOT-OPTIONS* (LIST OF KEYWORD) (LIST :ALLOCATION :INITIALLY :CONTEXT-SENSITIVE? :HARDWIRED?))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEFAULT-OPTION-HANDLER* METHOD-SLOT NULL)");
            oDEFAULT_OPTION_HANDLERo = SYM_STELLA_IN_DEFAULT_OPTION_HANDLER->lookup_function();
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

