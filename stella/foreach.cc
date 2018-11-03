// foreach.cc

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

Symbol* SYM_FOREACH_AS = NULL;

Symbol* SYM_FOREACH_COMMA = NULL;

Symbol* SYM_FOREACH_DO = NULL;

Symbol* SYM_FOREACH_COLLECT = NULL;

Surrogate* SGT_FOREACH_VOID = NULL;

Symbol* SYM_FOREACH_WHERE = NULL;

Symbol* SYM_FOREACH_INTO = NULL;

Symbol* SYM_FOREACH_COLLECT_INTO = NULL;

Symbol* SYM_FOREACH_PREFIX_FOREACH = NULL;

Symbol* SYM_FOREACH_IN = NULL;

Symbol* SYM_FOREACH_X = NULL;

Symbol* SYM_FOREACH_NIL = NULL;

Symbol* SYM_FOREACH_FOREACH = NULL;

Symbol* SYM_FOREACH_EXISTS = NULL;

Symbol* SYM_FOREACH_FORALL = NULL;

Symbol* SYM_FOREACH_SOME = NULL;

Symbol* SYM_FOREACH_SETOF = NULL;

Symbol* SYM_FOREACH_SET_OF = NULL;

Symbol* SYM_FOREACH_INTERVAL = NULL;

Surrogate* SGT_FOREACH_INTEGER_INTERVAL = NULL;

Surrogate* SGT_FOREACH_ABSTRACT_ITERATOR = NULL;

Symbol* SYM_FOREACH_ALLOCATE_ITERATOR = NULL;

Symbol* SYM_FOREACH_FALSE = NULL;

Surrogate* SGT_FOREACH_STRING = NULL;

Surrogate* SGT_FOREACH_VECTOR = NULL;

Surrogate* SGT_FOREACH_LIST = NULL;

Surrogate* SGT_FOREACH_CONS = NULL;

Symbol* SYM_FOREACH_THE_CONS_LIST = NULL;

Surrogate* SGT_FOREACH_KEY_VALUE_LIST = NULL;

Surrogate* SGT_FOREACH_KV_CONS = NULL;

Symbol* SYM_FOREACH_THE_KV_LIST = NULL;

Surrogate* SGT_FOREACH_PROPERTY_LIST = NULL;

Symbol* SYM_FOREACH_THE_PLIST = NULL;

Symbol* SYM_FOREACH_KEY = NULL;

Symbol* SYM_FOREACH_VALUE = NULL;

Symbol* SYM_FOREACH_SETQ = NULL;

Symbol* SYM_FOREACH_REST = NULL;

Symbol* SYM_FOREACH_NOT = NULL;

Symbol* SYM_FOREACH_NILp = NULL;

Symbol* SYM_FOREACH_DEFINEDp = NULL;

Symbol* SYM_FOREACH_NEXTp = NULL;

Symbol* SYM_FOREACH_PROGN = NULL;

Symbol* SYM_FOREACH_ANY_VALUE = NULL;

Symbol* SYM_FOREACH_ANY_KEY = NULL;

Symbol* SYM_FOREACH_NULL = NULL;

Symbol* SYM_FOREACH_NULL_INTEGER = NULL;

Surrogate* SGT_FOREACH_NUMBER_WRAPPER = NULL;

Surrogate* SGT_FOREACH_INTEGER = NULL;

Surrogate* SGT_FOREACH_BOOLEAN = NULL;

Symbol* SYM_FOREACH_NULLp = NULL;

Symbol* SYM_FOREACH_ii = NULL;

Symbol* SYM_FOREACH_TRUE = NULL;

Symbol* SYM_FOREACH_le = NULL;

Symbol* SYM_FOREACH_OR = NULL;

Symbol* SYM_FOREACH_LENGTH = NULL;

Symbol* SYM_FOREACH_NTH = NULL;

Surrogate* SGT_FOREACH_CHARACTER = NULL;

Symbol* SYM_FOREACH_l = NULL;

Symbol* SYM_FOREACH_ON = NULL;

Symbol* SYM_FOREACH_AND = NULL;

Symbol* SYM_FOREACH_IF = NULL;

Symbol* SYM_FOREACH_PERMANENT_CONS = NULL;

Symbol* SYM_FOREACH_EMPTYp = NULL;

Symbol* SYM_FOREACH_SETF = NULL;

Symbol* SYM_FOREACH_ADD_CONS_TO_END_OF_CONS_LIST = NULL;

Symbol* SYM_FOREACH_CONS = NULL;

Surrogate* SGT_FOREACH_UNKNOWN = NULL;

Symbol* SYM_FOREACH_COND = NULL;

Symbol* SYM_FOREACH_CONSp = NULL;

Symbol* SYM_FOREACH_OTHERWISE = NULL;

Symbol* SYM_FOREACH_WHEN = NULL;

Symbol* SYM_FOREACH_SYS_FOREACH = NULL;

Symbol* SYM_FOREACH_VRLET = NULL;

Symbol* SYM_FOREACH_BREAK = NULL;

Symbol* SYM_FOREACH_ALWAYS = NULL;

Symbol* SYM_FOREACH_DEFUN = NULL;

Symbol* SYM_FOREACH_BOOLEAN = NULL;

Symbol* SYM_FOREACH_SELF = NULL;

Symbol* SYM_FOREACH_ALL_PURPOSE_ITERATOR = NULL;

Symbol* SYM_FOREACH_LET = NULL;

Symbol* SYM_FOREACH_NESTEDITERATOR = NULL;

Symbol* SYM_FOREACH_ITERATOR_NESTED_ITERATOR = NULL;

Symbol* SYM_FOREACH_WHILE = NULL;

Symbol* SYM_FOREACH_RETURN = NULL;

Symbol* SYM_FOREACH_NEW = NULL;

Symbol* SYM_FOREACH_ITERATOR_NEXT_CODE = NULL;

Symbol* SYM_FOREACH_THE_CODE = NULL;

Keyword* KWD_FOREACH_FUNCTION = NULL;

Surrogate* SGT_FOREACH_ALL_PURPOSE_ITERATOR = NULL;

Cons* extract_one_in_clause(Cons* tail, Cons*& return1) {
  { Object* variable = tail->first();
    Object* renamed_Operator = tail->second();
    Cons* clause = tail;

    if (!((symbolP(variable) ||
        consP(variable)) &&
        (get_quoted_tree("((IN ON ISA) \"/STELLA\")", "/STELLA")->memberP(renamed_Operator) &&
         (tail->third() != NULL)))) {
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
                cout << endl << " " << "Illegal syntax where 'IN', 'ON', or 'ISA' clause expected:" << endl << "   " << "`" << de_uglify_parse_tree(tail) << "'" << "." << endl;
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
      { Cons* return_temp = NULL;

        return1 = NIL;
        return (return_temp);
      }
    }
    clause->first_setter(renamed_Operator);
    clause->second_setter(variable);
    tail = tail->rest->rest->rest;
    clause->rest->rest->rest = NIL;
    { Cons* return_temp = clause;

      return1 = tail;
      return (return_temp);
    }
  }
}

Cons* extract_one_generator_term(Cons* tail, Cons*& return1) {
  { Cons* inclause = NULL;
    Cons* residue = NULL;
    Cons* parallelterms = NULL;
    Cons* temp = NULL;

    inclause = extract_one_in_clause(tail, residue);
    if (!(residue->first() == SYM_FOREACH_AS)) {
      { Cons* return_temp = inclause;

        return1 = residue;
        return (return_temp);
      }
    }
    parallelterms = cons(inclause, cons(SYM_FOREACH_AS, NIL));
    while (residue->first() == SYM_FOREACH_AS) {
      temp = residue;
      residue = residue->rest;
      temp->free_cons();
      inclause = extract_one_in_clause(residue, residue);
      parallelterms = cons(inclause, parallelterms);
    }
    { Cons* return_temp = parallelterms->reverse();

      return1 = residue;
      return (return_temp);
    }
  }
}

Cons* extract_generators_clause(Cons* tail, Cons*& return1) {
  { Cons* generatorterm = NULL;
    Cons* residue = NULL;
    Cons* generatorsclause = NULL;

    generatorterm = extract_one_generator_term(tail, residue);
    if (!(residue->first() == SYM_FOREACH_COMMA)) {
      { Cons* return_temp = generatorterm;

        return1 = residue;
        return (return_temp);
      }
    }
    generatorsclause = cons(generatorterm, cons(SYM_FOREACH_COMMA, NIL));
    while (residue->first() == SYM_FOREACH_COMMA) {
      generatorterm = extract_one_generator_term(residue->rest, residue);
      generatorsclause = cons(generatorterm, generatorsclause);
    }
    { Cons* return_temp = generatorsclause->reverse();

      return1 = residue;
      return (return_temp);
    }
  }
}

Object* extract_option_and_residue(Symbol* option, Cons* tail, Cons*& return1) {
  if (!(tail->first() == option)) {
    { Object* return_temp = NULL;

      return1 = tail;
      return (return_temp);
    }
  }
  { Object* argument = NULL;
    Cons* residue = NULL;

    argument = tail->second();
    residue = tail->rest->rest;
    tail->rest->rest = NIL;
    free_cons_list(tail);
    { Object* return_temp = argument;

      return1 = residue;
      return (return_temp);
    }
  }
}

Cons* extract_do_clause(Cons* tail, Cons*& return1) {
  { Standard_Object* dummy1;

    if (!(tail->first() == SYM_FOREACH_DO)) {
      { Cons* return_temp = NULL;

        return1 = tail;
        return (return_temp);
      }
    }
    { Cons* doclause = tail;
      Cons* lastdocons = NULL;

      tail = tail->rest;
      while (tail->non_emptyP() &&
          (!(tail->first() == SYM_FOREACH_COLLECT))) {
        lastdocons = tail;
        tail = tail->rest;
      }
      if (lastdocons == NULL) {
        {
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
                    cout << endl << " " << "Missing arguments to DO separator" << "." << endl;
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
          doclause->rest = cons_list(1, walk_dont_call_me_tree(NIL, SGT_FOREACH_VOID, dummy1));
        }
      }
      else {
        lastdocons->rest = NIL;
      }
      { Cons* return_temp = doclause;

        return1 = tail;
        return (return_temp);
      }
    }
  }
}

Cons* foreach_to_prefix_foreach_tree(Cons* foreachtree) {
  { Standard_Object* dummy1;

    { Cons* generatorsclause = NULL;
      Object* filterclause = NULL;
      Cons* doclause = NULL;
      Object* collectclause = NULL;
      Object* intoclause = NULL;
      Cons* residue = ((Cons*)(foreachtree->rest));
      Cons* otree = NULL;

      foreachtree->free_cons();
      generatorsclause = extract_generators_clause(residue, residue);
      if (generatorsclause == NULL) {
        free_cons_tree(residue);
        return (NULL);
      }
      filterclause = extract_option_and_residue(SYM_FOREACH_WHERE, residue, residue);
      if (filterclause != NULL) {
        filterclause = listO(3, SYM_FOREACH_WHERE, filterclause, NIL);
      }
      doclause = extract_do_clause(residue, residue);
      collectclause = extract_option_and_residue(SYM_FOREACH_COLLECT, residue, residue);
      intoclause = extract_option_and_residue(SYM_FOREACH_INTO, residue, residue);
      if ((collectclause != NULL) ||
          (intoclause != NULL)) {
        collectclause = listO(3, SYM_FOREACH_COLLECT_INTO, collectclause, cons(intoclause, NIL));
      }
      otree = listO(3, SYM_FOREACH_PREFIX_FOREACH, generatorsclause, ((filterclause != NULL) ? ((Cons*)(cons(filterclause, NIL))) : ((Cons*)(NIL)))->concatenate(((doclause != NULL) ? ((Cons*)(cons(doclause, NIL))) : ((Cons*)(NIL)))->concatenate(((collectclause != NULL) ? ((Cons*)(cons(collectclause, NIL))) : ((Cons*)(NIL)))->concatenate(NIL))));
      if (((collectclause != NULL) &&
          (intoclause == NULL)) ||
          ((intoclause != NULL) &&
           (collectclause == NULL))) {
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
                  cout << endl << " " << "Missing COLLECT or INTO clause in" << "." << endl;
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
        free_cons_tree(otree);
        return (NIL);
      }
      if (residue->non_emptyP()) {
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
                  cout << endl << " " << "Extra expressions at the end of foreach statement:" << "." << endl;
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
        free_cons_tree(residue);
        return (listO(4, SYM_FOREACH_PREFIX_FOREACH, listO(4, SYM_FOREACH_IN, SYM_FOREACH_X, SYM_FOREACH_NIL, NIL), listO(3, SYM_FOREACH_DO, walk_dont_call_me_tree(otree, SGT_FOREACH_VOID, dummy1), NIL), NIL));
      }
      return (otree);
    }
  }
}

Cons* walk_foreach_tree(Cons* tree, Standard_Object*& return1) {
  { int old_OnofspecialsatloopentryO_001 = oNOFSPECIALSATLOOPENTRYo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oNOFSPECIALSATLOOPENTRYo = oSPECIALVARIABLESTACKo->length();
          { Object* test_value_001 = tree->first();

            if (test_value_001 == SYM_FOREACH_FOREACH) {
              { Cons* return_value_001 = NULL;
                Standard_Object* return_value_002 = NULL;

                return_value_001 = walk_prefix_foreach_tree(foreach_to_prefix_foreach_tree(tree), return_value_002);
                oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Cons* return_temp = return_value_001;

                  return1 = return_value_002;
                  return (return_temp);
                }
              }
            }
            else if (test_value_001 == SYM_FOREACH_EXISTS) {
              { Cons* return_value_003 = NULL;
                Standard_Object* return_value_004 = NULL;

                return_value_003 = walk_exists_tree(tree, return_value_004);
                oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Cons* return_temp = return_value_003;

                  return1 = return_value_004;
                  return (return_temp);
                }
              }
            }
            else if (test_value_001 == SYM_FOREACH_FORALL) {
              { Cons* return_value_005 = NULL;
                Standard_Object* return_value_006 = NULL;

                return_value_005 = walk_forall_tree(tree, return_value_006);
                oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Cons* return_temp = return_value_005;

                  return1 = return_value_006;
                  return (return_temp);
                }
              }
            }
            else if (test_value_001 == SYM_FOREACH_SOME) {
              { Cons* return_value_007 = NULL;
                Standard_Object* return_value_008 = NULL;

                return_value_007 = walk_some_tree(tree, return_value_008);
                oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Cons* return_temp = return_value_007;

                  return1 = return_value_008;
                  return (return_temp);
                }
              }
            }
            else if ((test_value_001 == SYM_FOREACH_SETOF) ||
                (test_value_001 == SYM_FOREACH_SET_OF)) {
              { Cons* return_value_009 = NULL;
                Standard_Object* return_value_010 = NULL;

                return_value_009 = walk_setof_tree(tree, return_value_010);
                oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                { Cons* return_temp = return_value_009;

                  return1 = return_value_010;
                  return (return_temp);
                }
              }
            }
            else {
              cerr << "`" << test_value_001 << "'" << " is not a valid case option";
            }
          }
          oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oNOFSPECIALSATLOOPENTRYo = old_OnofspecialsatloopentryO_001;
        resignal();
      }
    }
  }
}

Object* walk_collection_tree(Object* tree, boolean dontoptimizeP, Standard_Object*& return1) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        if ((!dontoptimizeP) &&
            ((tree->first() == SYM_FOREACH_INTERVAL) &&
             (tree->length() == 3))) {
          { Object* return_temp = tree;

            return1 = SGT_FOREACH_INTEGER_INTERVAL;
            return (return_temp);
          }
        }
      }
    }
    else {
    }
  }
  return (walk_a_tree(tree, return1));
}

Cons* yield_in_cursor_clauses(Cons* intree, boolean dontoptimizeP, Cons*& return1, Object*& return2) {
  { Object* vartree = intree->second();
    Symbol* keyvar = NULL;
    Symbol* valuevar = NULL;
    Surrogate* collectionbasetype = NULL;

    { Object* collectiontree = NULL;
      Standard_Object* collectiontype = NULL;

      collectiontree = walk_collection_tree(intree->third(), dontoptimizeP, collectiontype);
      intree->third_setter(NULL);
      collectionbasetype = type_spec_to_base_type(collectiontype);
      if (dontoptimizeP &&
          (!safe_subtype_ofP(collectionbasetype, SGT_FOREACH_ABSTRACT_ITERATOR))) {
        collectiontree = walk_collection_tree(listO(3, SYM_FOREACH_ALLOCATE_ITERATOR, collectiontree, NIL), TRUE, collectiontype);
        collectionbasetype = type_spec_to_base_type(collectiontype);
      }
      { Object* vartree_001 = vartree;

        if (consP(vartree)) {
          { Cons* vartree = NULL;

            vartree = ((Cons*)(vartree_001));
            if (!(vartree->length() == 2)) {
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
                        cout << endl << " " << "Illegal number of variables in IN clause: " << "`" << de_uglify_parse_tree(intree) << "'" << "." << endl;
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
              { Cons* return_temp = NIL;

                return1 = NIL;
                return2 = SYM_FOREACH_FALSE;
                return (return_temp);
              }
            }
            keyvar = ((Symbol*)(vartree->first()));
            valuevar = ((Symbol*)(vartree->second()));
          }
        }
        else {
          valuevar = ((Symbol*)(vartree));
        }
      }
      if (collectionbasetype == SGT_FOREACH_INTEGER_INTERVAL) {
        return (yield_in_cursor_clauses_for_integer_interval(((Cons*)(collectiontree)), collectiontype, keyvar, valuevar, return1, return2));
      }
      else {
        if ((collectionbasetype == SGT_FOREACH_STRING) ||
            safe_subtype_ofP(collectionbasetype, SGT_FOREACH_VECTOR)) {
          return (yield_in_cursor_clauses_for_vector(collectiontree, collectiontype, keyvar, valuevar, return1, return2));
        }
        else {
          return (yield_in_cursor_clauses_for_general_collection(collectiontree, collectiontype, keyvar, valuevar, return1, return2));
        }
      }
    }
  }
}

Cons* yield_in_cursor_clauses_for_general_collection(Object* collectiontree, Standard_Object* collectiontype, Symbol* keyvar, Symbol* valuevar, Cons*& return1, Object*& return2) {
  { boolean dummy1;

    { Surrogate* collectionbasetype = type_spec_to_base_type(collectiontype);
      Symbol* iteratorvar = local_gensym("ITER");
      Cons* iteratorclauses = NIL;
      Cons* valueclauses = NIL;
      Object* continuationtest = NULL;
      Cons* keytree = NIL;
      Cons* valuetree = NIL;
      Cons* bumptrees = NIL;

      if (collectionbasetype == SGT_FOREACH_LIST) {
        iteratorclauses = cons(cons(iteratorvar, listO(3, SGT_FOREACH_CONS, listO(3, SYM_FOREACH_THE_CONS_LIST, collectiontree, NIL), NIL)), NIL);
        collectionbasetype = SGT_FOREACH_CONS;
      }
      else if (collectionbasetype == SGT_FOREACH_KEY_VALUE_LIST) {
        iteratorclauses = cons(cons(iteratorvar, listO(3, SGT_FOREACH_KV_CONS, listO(3, SYM_FOREACH_THE_KV_LIST, collectiontree, NIL), NIL)), NIL);
        collectionbasetype = SGT_FOREACH_KV_CONS;
      }
      else if (collectionbasetype == SGT_FOREACH_PROPERTY_LIST) {
        iteratorclauses = cons(cons(iteratorvar, listO(3, SGT_FOREACH_CONS, listO(3, SYM_FOREACH_THE_PLIST, collectiontree, NIL), NIL)), NIL);
      }
      else if ((collectionbasetype == SGT_FOREACH_CONS) ||
          (collectionbasetype == SGT_FOREACH_KV_CONS)) {
        iteratorclauses = cons(cons(iteratorvar, cons(collectionbasetype, cons(collectiontree, NIL))), NIL);
      }
      else {
        if (!(safe_subtype_ofP(collectionbasetype, SGT_FOREACH_ABSTRACT_ITERATOR))) {
          collectiontree = listO(3, SYM_FOREACH_ALLOCATE_ITERATOR, collectiontree, NIL);
        }
        iteratorclauses = cons(cons(iteratorvar, listO(3, SGT_FOREACH_ABSTRACT_ITERATOR, collectiontree, NIL)), NIL);
        collectionbasetype = SGT_FOREACH_ABSTRACT_ITERATOR;
      }
      if (keyvar != NULL) {
        keytree = listO(3, SYM_FOREACH_KEY, iteratorvar, NIL);
      }
      valuetree = listO(3, SYM_FOREACH_VALUE, iteratorvar, NIL);
      if (collectionbasetype == SGT_FOREACH_CONS) {
        bumptrees = cons(listO(3, SYM_FOREACH_SETQ, iteratorvar, cons(listO(3, SYM_FOREACH_REST, iteratorvar, NIL), NIL)), NIL);
        continuationtest = listO(3, SYM_FOREACH_NOT, listO(3, SYM_FOREACH_NILp, iteratorvar, NIL), NIL);
      }
      else if (collectionbasetype == SGT_FOREACH_KV_CONS) {
        bumptrees = cons(listO(3, SYM_FOREACH_SETQ, iteratorvar, cons(listO(3, SYM_FOREACH_REST, iteratorvar, NIL), NIL)), NIL);
        continuationtest = listO(3, SYM_FOREACH_DEFINEDp, iteratorvar, NIL);
      }
      else if (collectionbasetype == SGT_FOREACH_PROPERTY_LIST) {
        if (keyvar != NULL) {
          keytree = listO(3, SYM_FOREACH_VALUE, iteratorvar, NIL);
        }
        valuetree = listO(3, SYM_FOREACH_VALUE, listO(3, SYM_FOREACH_REST, iteratorvar, NIL), NIL);
        bumptrees = cons(listO(3, SYM_FOREACH_SETQ, iteratorvar, cons(listO(3, SYM_FOREACH_REST, listO(3, SYM_FOREACH_REST, iteratorvar, NIL), NIL), NIL)), NIL);
        continuationtest = listO(3, SYM_FOREACH_NOT, listO(3, SYM_FOREACH_NILp, iteratorvar, NIL), NIL);
      }
      else if (collectionbasetype == SGT_FOREACH_ABSTRACT_ITERATOR) {
        bumptrees = NIL;
        continuationtest = listO(3, SYM_FOREACH_NEXTp, iteratorvar, NIL);
      }
      else {
        cerr << "`" << collectionbasetype << "'" << " is not a valid case option";
      }
      valueclauses = cons(cons(valuevar, cons(extract_parameter_type(collectiontype, SYM_FOREACH_ANY_VALUE, dummy1), cons(listO(3, SYM_FOREACH_PROGN, listO(3, SYM_FOREACH_SETQ, valuevar, cons(valuetree, NIL)), bumptrees->concatenate(NIL)), NIL))), valueclauses);
      if (keyvar != NULL) {
        { Standard_Object* keytype = NULL;
          boolean parameterexistsP = FALSE;

          keytype = extract_parameter_type(collectiontype, SYM_FOREACH_ANY_KEY, parameterexistsP);
          if (parameterexistsP) {
            valueclauses = cons(cons(keyvar, cons(keytype, cons(listO(3, SYM_FOREACH_SETQ, keyvar, cons(keytree, NIL)), NIL))), valueclauses);
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
                      cout << endl << " " << "Illegal key variable specified for keyless collection " << "`" << de_uglify_parse_tree(collectiontype) << "'" << "." << endl;
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
            { Cons* return_temp = NIL;

              return1 = NIL;
              return2 = SYM_FOREACH_FALSE;
              return (return_temp);
            }
          }
        }
      }
      { Cons* return_temp = iteratorclauses;

        return1 = valueclauses;
        return2 = continuationtest;
        return (return_temp);
      }
    }
  }
}

Cons* yield_in_cursor_clauses_for_integer_interval(Cons* collectiontree, Standard_Object* collectiontype, Symbol* keyvar, Symbol* valuevar, Cons*& return1, Object*& return2) {
  collectiontype = collectiontype;
  if (keyvar != NULL) {
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
              cout << endl << " " << "Illegal key variable specified for INTEGER-INTERVAL" << "." << endl;
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
    { Cons* return_temp = NIL;

      return1 = NIL;
      return2 = SYM_FOREACH_FALSE;
      return (return_temp);
    }
  }
  { Object* upperbound = collectiontree->third();
    boolean knownunboundedP = (upperbound == SYM_FOREACH_NULL) ||
        (upperbound == SYM_FOREACH_NULL_INTEGER);
    boolean knownboundedP = (!knownunboundedP) &&
        (isaP(upperbound, SGT_FOREACH_NUMBER_WRAPPER) ||
         (consP(upperbound) &&
          get_quoted_tree("((+ - * |/| 1+ 1- ++ -- LENGTH) \"/STELLA\")", "/STELLA")->memberP(((Cons*)(upperbound))->first())));
    Symbol* iteratorvar = local_gensym("ITER");
    Symbol* upperboundvar = (knownunboundedP ? ((Symbol*)(NULL)) : ((Symbol*)(local_gensym("UPPER-BOUND"))));
    Symbol* unboundedvar = ((knownunboundedP ||
        knownboundedP) ? ((Symbol*)(NULL)) : ((Symbol*)(local_gensym("UNBOUNDED?"))));

    { Cons* return_temp = cons(cons(iteratorvar, listO(3, SGT_FOREACH_INTEGER, collectiontree->second(), NIL)), (knownunboundedP ? ((Cons*)(NIL)) : ((Cons*)(cons(cons(upperboundvar, listO(3, SGT_FOREACH_INTEGER, upperbound, NIL)), NIL))))->concatenate(((knownunboundedP ||
          knownboundedP) ? ((Cons*)(NIL)) : ((Cons*)(cons(cons(unboundedvar, listO(3, SGT_FOREACH_BOOLEAN, listO(3, SYM_FOREACH_NULLp, upperboundvar, NIL), NIL)), NIL))))->concatenate(NIL)));

      return1 = cons(cons(valuevar, listO(3, SGT_FOREACH_INTEGER, listO(4, SYM_FOREACH_PROGN, listO(3, SYM_FOREACH_SETQ, valuevar, cons(iteratorvar, NIL)), listO(3, SYM_FOREACH_ii, iteratorvar, NIL), NIL), NIL)), NIL);
      return2 = (knownunboundedP ? ((Standard_Object*)(SYM_FOREACH_TRUE)) : ((Standard_Object*)((knownboundedP ? ((Cons*)(listO(3, SYM_FOREACH_le, iteratorvar, cons(upperboundvar, NIL)))) : ((Cons*)(listO(3, SYM_FOREACH_OR, unboundedvar, cons(listO(3, SYM_FOREACH_le, iteratorvar, cons(upperboundvar, NIL)), NIL))))))));
      return (return_temp);
    }
  }
}

Cons* yield_in_cursor_clauses_for_vector(Object* collectiontree, Standard_Object* collectiontype, Symbol* keyvar, Symbol* valuevar, Cons*& return1, Object*& return2) {
  { boolean dummy1;

    if (keyvar != NULL) {
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
                cout << endl << " " << "Illegal key variable specified for " << "`" << de_uglify_parse_tree(collectiontype) << "'" << "." << endl;
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
      { Cons* return_temp = NIL;

        return1 = NIL;
        return2 = SYM_FOREACH_FALSE;
        return (return_temp);
      }
    }
    { Symbol* vectorvar = local_gensym("VECTOR");
      Symbol* indexvar = local_gensym("INDEX");
      Symbol* lengthvar = local_gensym("LENGTH");

      { Cons* return_temp = listO(4, cons(vectorvar, cons(collectiontype, cons(collectiontree, NIL))), cons(indexvar, listO(3, SGT_FOREACH_INTEGER, integer_wrap_literal(0), NIL)), cons(lengthvar, listO(3, SGT_FOREACH_INTEGER, listO(3, SYM_FOREACH_LENGTH, vectorvar, NIL), NIL)), NIL);

        return1 = cons(cons(valuevar, cons(((collectiontype == SGT_FOREACH_STRING) ? ((Standard_Object*)(SGT_FOREACH_CHARACTER)) : ((Standard_Object*)(extract_parameter_type(collectiontype, SYM_FOREACH_ANY_VALUE, dummy1)))), cons(listO(4, SYM_FOREACH_PROGN, listO(3, SYM_FOREACH_SETQ, valuevar, cons(listO(3, SYM_FOREACH_NTH, vectorvar, cons(indexvar, NIL)), NIL)), listO(3, SYM_FOREACH_ii, indexvar, NIL), NIL), NIL))), NIL);
        return2 = listO(3, SYM_FOREACH_l, indexvar, cons(lengthvar, NIL));
        return (return_temp);
      }
    }
  }
}

Cons* yield_on_cursor_clauses(Cons* ontree, Cons*& return1, Object*& return2) {
  { Object* iteratorvar = ontree->second();

    if (!symbolP(iteratorvar)) {
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
                cout << endl << " " << "Illegal ON clause with non-atomic variable: " << "`" << de_uglify_parse_tree(ontree) << "'" << "." << endl;
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
      { Cons* return_temp = NIL;

        return1 = NIL;
        return2 = SYM_FOREACH_FALSE;
        return (return_temp);
      }
    }
    { Object* collectiontree = NULL;
      Standard_Object* collectiontype = NULL;

      collectiontree = walk_collection_tree(ontree->third(), TRUE, collectiontype);
      ontree->third_setter(NULL);
      if (!safe_subtype_ofP(type_spec_to_base_type(collectiontype), SGT_FOREACH_ABSTRACT_ITERATOR)) {
        collectiontree = listO(3, SYM_FOREACH_ALLOCATE_ITERATOR, collectiontree, NIL);
      }
      { Cons* return_temp = cons(cons(iteratorvar, listO(3, SGT_FOREACH_ABSTRACT_ITERATOR, collectiontree, NIL)), NIL);

        return1 = NIL;
        return2 = listO(3, SYM_FOREACH_NEXTp, iteratorvar, NIL);
        return (return_temp);
      }
    }
  }
}

Cons* collect_cursor_clauses(Cons* cursorstree, boolean dontoptimizeP, Cons*& return1, Object*& return2) {
  { Object* test_value_001 = cursorstree->first();

    if (test_value_001 == SYM_FOREACH_IN) {
      return (yield_in_cursor_clauses(cursorstree, dontoptimizeP, return1, return2));
    }
    else if (test_value_001 == SYM_FOREACH_ON) {
      return (yield_on_cursor_clauses(cursorstree, return1, return2));
    }
    else if (test_value_001 == SYM_FOREACH_AS) {
      { Cons* alliteratorclauses = NIL;
        Cons* allvalueclauses = NIL;
        Cons* continuationtests = NIL;

        { Object* clause = NULL;
          Cons* iter_001 = cursorstree->rest;

          while (!nilP(iter_001)) {
            {
              clause = iter_001->value;
              iter_001 = iter_001->rest;
            }
            { Cons* iteratorclauses = NULL;
              Cons* valueclauses = NULL;
              Object* continuationtest = NULL;

              iteratorclauses = collect_cursor_clauses(((Cons*)(clause)), dontoptimizeP, valueclauses, continuationtest);
              alliteratorclauses = alliteratorclauses->concatenate(iteratorclauses);
              allvalueclauses = allvalueclauses->concatenate(valueclauses);
              continuationtests = cons(continuationtest, continuationtests);
            }
          }
        }
        { Cons* return_temp = alliteratorclauses;

          return1 = allvalueclauses;
          return2 = ((continuationtests->length() == 1) ? ((Object*)(continuationtests->first())) : ((Object*)(cons(SYM_FOREACH_AND, continuationtests->reverse()->remove(SYM_FOREACH_TRUE)->concatenate(NIL)))));
          return (return_temp);
        }
      }
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

Cons* walk_cursors_tree(Cons* cursorstree, boolean dontoptimizeP, Cons*& return1, Object*& return2) {
  { Standard_Object* dummy1;

    { Cons* iteratorclauses = NULL;
      Cons* valueclauses = NULL;
      Object* continuationtest = NULL;

      iteratorclauses = collect_cursor_clauses(cursorstree, dontoptimizeP, valueclauses, continuationtest);
      { Cons* clause = NIL;
        Cons* iter_001 = ((Cons*)(iteratorclauses));

        while (!nilP(iter_001)) {
          {
            clause = ((Cons*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          { Object* iteratortree = NULL;
            Standard_Object* iteratortype = NULL;

            iteratortree = walk_expression_tree(clause->third(), ((Standard_Object*)(clause->second())), SYM_FOREACH_FOREACH, FALSE, iteratortype);
            clause->second_setter(iteratortype);
            clause->third_setter(coerce_a_tree(iteratortree, iteratortype, iteratortype, dummy1));
          }
          push_variable_binding(((Symbol*)(clause->first())), type_spec_to_base_type(((Standard_Object*)(clause->second()))));
        }
      }
      { Cons* clause = NIL;
        Cons* iter_002 = ((Cons*)(valueclauses));

        while (!nilP(iter_002)) {
          {
            clause = ((Cons*)(iter_002->value));
            iter_002 = iter_002->rest;
          }
          push_variable_binding(((Symbol*)(clause->first())), type_spec_to_base_type(((Standard_Object*)(clause->second()))));
          clause->third_setter(walk_without_type_tree(clause->third()));
        }
      }
      continuationtest = walk_without_type_tree(continuationtest);
      { int i = NULL_INTEGER;
        int iter_003 = 1;
        int upper_bound_001 = iteratorclauses->length() + valueclauses->length();

        while (iter_003 <= upper_bound_001) {
          {
            i = iter_003;
            iter_003 = iter_003 + 1;
          }
          i = i;
          pop_variable_binding();
        }
      }
      { Cons* return_temp = iteratorclauses;

        return1 = valueclauses;
        return2 = continuationtest;
        return (return_temp);
      }
    }
  }
}

Cons* yield_collect_into_list_code(Symbol* collectvariable, Object* intovariable, Object* collecttree) {
  return (cons(listO(5, SYM_FOREACH_IF, listO(3, SYM_FOREACH_NULLp, collectvariable, NIL), listO(4, SYM_FOREACH_PROGN, listO(3, SYM_FOREACH_SETQ, collectvariable, cons(listO(3, SYM_FOREACH_PERMANENT_CONS, collecttree, cons(SYM_FOREACH_NIL, NIL)), NIL)), listO(5, SYM_FOREACH_IF, listO(3, SYM_FOREACH_EMPTYp, listO(3, SYM_FOREACH_THE_CONS_LIST, intovariable, NIL), NIL), listO(4, SYM_FOREACH_SETF, listO(3, SYM_FOREACH_THE_CONS_LIST, intovariable, NIL), collectvariable, NIL), listO(4, SYM_FOREACH_ADD_CONS_TO_END_OF_CONS_LIST, listO(3, SYM_FOREACH_THE_CONS_LIST, intovariable, NIL), collectvariable, NIL), NIL), NIL), listO(4, SYM_FOREACH_PROGN, listO(4, SYM_FOREACH_SETF, listO(3, SYM_FOREACH_REST, collectvariable, NIL), listO(3, SYM_FOREACH_PERMANENT_CONS, copy_cons_tree(collecttree), cons(SYM_FOREACH_NIL, NIL)), NIL), listO(3, SYM_FOREACH_SETQ, collectvariable, cons(listO(3, SYM_FOREACH_REST, collectvariable, NIL), NIL)), NIL), NIL), NIL));
}

Cons* yield_collect_into_cons_code(Symbol* collectvariable, Object* intovariable, Object* collecttree) {
  return (cons(listO(5, SYM_FOREACH_IF, listO(3, SYM_FOREACH_NULLp, collectvariable, NIL), listO(4, SYM_FOREACH_PROGN, listO(3, SYM_FOREACH_SETQ, collectvariable, cons(listO(3, SYM_FOREACH_CONS, collecttree, cons(SYM_FOREACH_NIL, NIL)), NIL)), listO(5, SYM_FOREACH_IF, listO(3, SYM_FOREACH_NILp, intovariable, NIL), listO(3, SYM_FOREACH_SETQ, intovariable, cons(collectvariable, NIL)), listO(3, SYM_FOREACH_ADD_CONS_TO_END_OF_CONS_LIST, intovariable, cons(collectvariable, NIL)), NIL), NIL), listO(4, SYM_FOREACH_PROGN, listO(4, SYM_FOREACH_SETF, listO(3, SYM_FOREACH_REST, collectvariable, NIL), listO(3, SYM_FOREACH_CONS, copy_cons_tree(collecttree), cons(SYM_FOREACH_NIL, NIL)), NIL), listO(3, SYM_FOREACH_SETQ, collectvariable, cons(listO(3, SYM_FOREACH_REST, collectvariable, NIL), NIL)), NIL), NIL), NIL));
}

Cons* yield_collect_code(Symbol* collectvariable, Object* intovariable, Object* collecttree) {
  { Standard_Object* dummy1;

    { Surrogate* intovariabletype = type_spec_to_base_type(lookup_variable_type(((Symbol*)(intovariable))));

      if (subtype_ofP(intovariabletype, SGT_FOREACH_LIST)) {
        return (yield_collect_into_list_code(collectvariable, intovariable, collecttree));
      }
      else if (subtype_ofP(intovariabletype, SGT_FOREACH_CONS)) {
        return (yield_collect_into_cons_code(collectvariable, intovariable, collecttree));
      }
      else if (intovariabletype == SGT_FOREACH_UNKNOWN) {
        return (cons(listO(5, SYM_FOREACH_IF, listO(3, SYM_FOREACH_NULLp, collectvariable, NIL), listO(4, SYM_FOREACH_PROGN, listO(3, SYM_FOREACH_SETQ, collectvariable, cons(listO(3, SYM_FOREACH_CONS, collecttree, cons(SYM_FOREACH_NIL, NIL)), NIL)), listO(5, SYM_FOREACH_COND, listO(3, listO(3, SYM_FOREACH_NILp, intovariable, NIL), listO(3, SYM_FOREACH_SETQ, intovariable, cons(collectvariable, NIL)), NIL), listO(3, listO(3, SYM_FOREACH_CONSp, intovariable, NIL), listO(3, SYM_FOREACH_ADD_CONS_TO_END_OF_CONS_LIST, intovariable, cons(collectvariable, NIL)), NIL), listO(3, SYM_FOREACH_OTHERWISE, listO(5, SYM_FOREACH_IF, listO(3, SYM_FOREACH_EMPTYp, listO(3, SYM_FOREACH_THE_CONS_LIST, intovariable, NIL), NIL), listO(4, SYM_FOREACH_SETF, listO(3, SYM_FOREACH_THE_CONS_LIST, intovariable, NIL), collectvariable, NIL), listO(4, SYM_FOREACH_ADD_CONS_TO_END_OF_CONS_LIST, listO(3, SYM_FOREACH_THE_CONS_LIST, intovariable, NIL), collectvariable, NIL), NIL), NIL), NIL), NIL), listO(4, SYM_FOREACH_PROGN, listO(4, SYM_FOREACH_SETF, listO(3, SYM_FOREACH_REST, collectvariable, NIL), listO(3, SYM_FOREACH_CONS, copy_cons_tree(collecttree), cons(SYM_FOREACH_NIL, NIL)), NIL), listO(3, SYM_FOREACH_SETQ, collectvariable, cons(listO(3, SYM_FOREACH_REST, collectvariable, NIL), NIL)), NIL), NIL), NIL));
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
                  cout << endl << " " << "Can't collect into a datatype other than LIST or CONS." << "." << endl;
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
        return (walk_dont_call_me_tree(collecttree, SGT_FOREACH_VOID, dummy1));
      }
    }
  }
}

Cons* walk_prefix_collect_into_tree(Cons* collectintotree, Cons* iterators, Cons* valuebindings, Cons* docode, Cons*& return1) {
  { Object* collecttree = collectintotree->second();
    Object* intotree = collectintotree->third();
    Symbol* collectvariable = local_gensym("COLLECT");
    Cons* collectintobindings = cons(cons(collectvariable, listO(3, SGT_FOREACH_CONS, SYM_FOREACH_NULL, NIL)), NIL);
    Cons* collectcode = NULL;
    Symbol* intovariable = NULL;
    Standard_Object* intovariabletype = NULL;

    free_cons_list(collectintotree);
    if (symbolP(intotree)) {
      {
        intovariable = ((Symbol*)(intotree));
        collectcode = yield_collect_code(collectvariable, intovariable, collecttree);
      }
    }
    else {
      {
        { Cons* d = NIL;
          Cons* iter_001 = ((Cons*)(valuebindings));

          while (!nilP(iter_001)) {
            {
              d = ((Cons*)(iter_001->value));
              iter_001 = iter_001->rest;
            }
            push_variable_binding(((Symbol*)(d->first())), ((Standard_Object*)(d->second())));
          }
        }
        intotree = walk_expression_tree(intotree, NULL, SYM_FOREACH_FOREACH, FALSE, intovariabletype);
        { Object* d = NULL;
          Cons* iter_002 = valuebindings;

          while (!nilP(iter_002)) {
            {
              d = iter_002->value;
              iter_002 = iter_002->rest;
            }
            {
            }
            pop_variable_binding();
          }
        }
        intovariable = local_gensym("INTO");
        collectintobindings = cons(cons_list(3, intovariable, intovariabletype, intotree), collectintobindings);
        push_variable_binding(intovariable, intovariabletype);
        collectcode = yield_collect_code(collectvariable, intovariable, collecttree);
        pop_variable_binding();
      }
    }
    { Cons* return_temp = iterators->concatenate(collectintobindings);

      return1 = docode->concatenate(collectcode);
      return (return_temp);
    }
  }
}

Cons* wrap_where_test(Object* wheretest, Cons* actions) {
  if (wheretest != NULL) {
    return (cons(listO(3, SYM_FOREACH_WHEN, wheretest, actions->concatenate(NIL)), NIL));
  }
  else {
    return (actions);
  }
}

Cons* walk_prefix_foreach_body(Cons* iteratorclauses, Cons* valueclauses, Cons* wheretest, Cons* doactions) {
  { Cons* otree = NULL;

    { Cons* c = NIL;
      Cons* iter_001 = ((Cons*)(iteratorclauses));

      while (!nilP(iter_001)) {
        {
          c = ((Cons*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        push_variable_binding(((Symbol*)(c->first())), ((Standard_Object*)(c->second())));
      }
    }
    { Cons* c = NIL;
      Cons* iter_002 = ((Cons*)(valueclauses));

      while (!nilP(iter_002)) {
        {
          c = ((Cons*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        push_variable_binding(((Symbol*)(c->first())), ((Standard_Object*)(c->second())));
      }
    }
    otree = walk_list_of_trees(wrap_where_test(wheretest, doactions));
    { Object* c = NULL;
      Cons* iter_003 = valueclauses;

      while (!nilP(iter_003)) {
        {
          c = iter_003->value;
          iter_003 = iter_003->rest;
        }
        {
        }
        pop_variable_binding();
      }
    }
    { Object* c = NULL;
      Cons* iter_004 = iteratorclauses;

      while (!nilP(iter_004)) {
        {
          c = iter_004->value;
          iter_004 = iter_004->rest;
        }
        {
        }
        pop_variable_binding();
      }
    }
    return (otree);
  }
}

Cons* walk_prefix_foreach_tree(Cons* tree, Standard_Object*& return1) {
  { Cons* tail = NULL;
    Cons* iteratorclauses = NULL;
    Cons* valueclauses = NULL;
    Object* continuationtest = NULL;
    Object* wheretest = NULL;
    Cons* doactions = NIL;

    iteratorclauses = walk_cursors_tree(((Cons*)(tree->second())), FALSE, valueclauses, continuationtest);
    tree->second_setter(NULL);
    tail = ((Cons*)(tree->rest->rest));
    if (((Cons*)(tail->first()))->first() == SYM_FOREACH_WHERE) {
      wheretest = ((Cons*)(tail->first()))->second();
      ((Cons*)(tail->first()))->second_setter(NULL);
      tail = tail->rest;
    }
    if (((Cons*)(tail->first()))->first() == SYM_FOREACH_DO) {
      doactions = ((Cons*)(tail->first()))->rest;
      ((Cons*)(tail->first()))->rest = NIL;
      tail = tail->rest;
    }
    if (tail->non_emptyP()) {
      iteratorclauses = walk_prefix_collect_into_tree(((Cons*)(tail->first())), iteratorclauses, valueclauses, doactions, doactions);
      tail->first_setter(NULL);
    }
    free_cons_tree(tree);
    { Cons* return_temp = listO(3, SYM_FOREACH_SYS_FOREACH, iteratorclauses, cons(valueclauses, cons(continuationtest, walk_prefix_foreach_body(iteratorclauses, valueclauses, ((Cons*)(wheretest)), doactions)->concatenate(NIL))));

      return1 = SGT_FOREACH_VOID;
      return (return_temp);
    }
  }
}

Cons* walk_exists_tree(Cons* tree, Standard_Object*& return1) {
  { Symbol* foundP = local_gensym("FOUND?");
    Cons* otree = listO(5, SYM_FOREACH_VRLET, cons(cons(foundP, cons(SYM_FOREACH_FALSE, NIL)), NIL), cons(SYM_FOREACH_FOREACH, tree->rest->concatenate(listO(4, SYM_FOREACH_DO, listO(3, SYM_FOREACH_SETQ, foundP, cons(SYM_FOREACH_TRUE, NIL)), cons(SYM_FOREACH_BREAK, NIL), NIL))), foundP, NIL);

    tree->free_cons();
    return (walk_a_cons_tree(otree, return1));
  }
}

Cons* walk_forall_tree(Cons* tree, Standard_Object*& return1) {
  { Symbol* alwaysP = local_gensym("ALWAYS?");
    Cons* iteratorsandwhere = NIL;
    Cons* alwaystest = NIL;
    Cons* precursor = NIL;
    Cons* cursor = tree;

    while (cursor->non_emptyP()) {
      if (cursor->first() == SYM_FOREACH_ALWAYS) {
        alwaystest = ((Cons*)(cursor->rest->first()));
        free_cons_list(cursor);
        precursor->rest = NIL;
        break;
      }
      precursor = cursor;
      cursor = cursor->rest;
    }
    iteratorsandwhere = tree->rest;
    tree->free_cons();
    { Cons* return_temp = ((Cons*)(listO(5, SYM_FOREACH_VRLET, cons(cons(alwaysP, cons(SYM_FOREACH_TRUE, NIL)), NIL), cons(SYM_FOREACH_FOREACH, iteratorsandwhere->concatenate(listO(3, SYM_FOREACH_DO, listO(5, SYM_FOREACH_WHEN, listO(3, SYM_FOREACH_NOT, alwaystest, NIL), listO(3, SYM_FOREACH_SETQ, alwaysP, cons(SYM_FOREACH_FALSE, NIL)), cons(SYM_FOREACH_BREAK, NIL), NIL), NIL))), alwaysP, NIL)));

      return1 = SGT_FOREACH_BOOLEAN;
      return (return_temp);
    }
  }
}

Cons* walk_some_tree(Cons* tree, Standard_Object*& return1) {
  { boolean dummy1;

    { Symbol* valuevar = local_gensym("VALUE");
      Object* iterationvar = tree->second();
      Cons* otree = NULL;

      { Object* sequenceref = NULL;
        Standard_Object* sequencetype = NULL;

        sequenceref = walk_a_tree(tree->fourth(), sequencetype);
        tree->fourth_setter(sequenceref);
        otree = listO(5, SYM_FOREACH_VRLET, cons(cons(valuevar, cons(extract_parameter_type(sequencetype, SYM_FOREACH_ANY_VALUE, dummy1), cons(SYM_FOREACH_NULL, NIL))), NIL), cons(SYM_FOREACH_FOREACH, tree->rest->concatenate(listO(4, SYM_FOREACH_DO, listO(3, SYM_FOREACH_SETQ, valuevar, cons(iterationvar, NIL)), cons(SYM_FOREACH_BREAK, NIL), NIL))), valuevar, NIL);
        tree->free_cons();
        return (walk_a_cons_tree(otree, return1));
      }
    }
  }
}

Cons* extract_setof_nested_iterator_tree(Cons* iteratorclauses) {
  { Cons* iterclauses = ((Cons*)(iteratorclauses));
    Object* subtree = ((Cons*)(iterclauses->first()))->third();

    ((Cons*)(iterclauses->first()))->third_setter(NULL);
    if (iterclauses->rest->non_emptyP()) {
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
                cout << endl << " " << "Too many iterators in 'setof' expression" << "." << endl;
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
    free_cons_tree(iterclauses);
    return (((Cons*)(subtree)));
  }
}

Symbol* yield_setof_next_function_name(Cons* valueclauses, Cons* wheretest) {
  { Cons* onlyvalueclause = ((Cons*)(valueclauses->first()));
    Object* valuevariable = onlyvalueclause->first();
    Object* valuetype = onlyvalueclause->second();
    Symbol* nextfunctionname = NULL;

    free_cons_tree(valueclauses);
    nextfunctionname = gensym("SETOF-NEXT-P");
    walk_auxiliary_tree(listO(5, SYM_FOREACH_DEFUN, cons(nextfunctionname, cons(SYM_FOREACH_BOOLEAN, NIL)), cons(listO(3, SYM_FOREACH_SELF, SYM_FOREACH_ALL_PURPOSE_ITERATOR, NIL), NIL), listO(5, SYM_FOREACH_LET, listO(3, listO(3, SYM_FOREACH_NESTEDITERATOR, listO(3, SYM_FOREACH_ITERATOR_NESTED_ITERATOR, SYM_FOREACH_SELF, NIL), NIL), cons(valuevariable, cons(valuetype, cons(SYM_FOREACH_NULL, NIL))), NIL), listO(5, SYM_FOREACH_WHILE, listO(3, SYM_FOREACH_NEXTp, SYM_FOREACH_NESTEDITERATOR, NIL), listO(3, SYM_FOREACH_SETQ, valuevariable, cons(listO(3, SYM_FOREACH_VALUE, SYM_FOREACH_NESTEDITERATOR, NIL), NIL)), listO(3, SYM_FOREACH_WHEN, wheretest, listO(3, listO(4, SYM_FOREACH_SETF, listO(3, SYM_FOREACH_VALUE, SYM_FOREACH_SELF, NIL), valuevariable, NIL), listO(3, SYM_FOREACH_RETURN, SYM_FOREACH_TRUE, NIL), NIL)), NIL), listO(3, SYM_FOREACH_RETURN, SYM_FOREACH_FALSE, NIL), NIL), NIL));
    return (nextfunctionname);
  }
}

Cons* walk_setof_tree(Cons* tree, Standard_Object*& return1) {
  tree = foreach_to_prefix_foreach_tree(tree);
  { Cons* iteratorssubtree = ((Cons*)(tree->second()));
    Symbol* iteratorvariable = local_gensym("ITER");
    Cons* tail = NULL;
    Cons* iteratorclauses = NULL;
    Cons* valueclauses = NULL;
    Object* continuationtest = NULL;
    Object* wheretest = NULL;

    tree->second_setter(NULL);
    if (get_quoted_tree("((ON AS) \"/STELLA\")", "/STELLA")->memberP(iteratorssubtree->first())) {
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
                cout << endl << " " << "Illegal reserved word " << "`" << iteratorssubtree->first() << "'" << " in 'setof' expression." << "." << endl;
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
    iteratorclauses = walk_cursors_tree(iteratorssubtree, TRUE, valueclauses, continuationtest);
    tail = ((Cons*)(tree->rest->rest));
    if (tail->non_emptyP() &&
        (((Cons*)(tail->first()))->first() == SYM_FOREACH_WHERE)) {
      wheretest = ((Cons*)(tail->first()))->second();
      ((Cons*)(tail->first()))->second_setter(NULL);
      tail = tail->rest;
    }
    if (tail->non_emptyP()) {
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
                cout << endl << " " << "Illegal 'setof' expression.  Syntax is " << endl << "   (SETOF <iterators> WHERE <boolean expression>)" << "." << endl;
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
    free_cons_tree(tree);
    { Cons* return_temp = listO(6, SYM_FOREACH_VRLET, cons(cons(iteratorvariable, cons(listO(3, SYM_FOREACH_NEW, SYM_FOREACH_ALL_PURPOSE_ITERATOR, NIL), NIL)), NIL), listO(4, SYM_FOREACH_SETF, listO(3, SYM_FOREACH_ITERATOR_NESTED_ITERATOR, iteratorvariable, NIL), extract_setof_nested_iterator_tree(iteratorclauses), NIL), listO(4, SYM_FOREACH_SETF, listO(3, SYM_FOREACH_ITERATOR_NEXT_CODE, iteratorvariable, NIL), listO(4, SYM_FOREACH_THE_CODE, KWD_FOREACH_FUNCTION, yield_setof_next_function_name(valueclauses, ((Cons*)(wheretest))), NIL), NIL), iteratorvariable, NIL);

      return1 = SGT_FOREACH_ALL_PURPOSE_ITERATOR;
      return (return_temp);
    }
  }
}

void startup_foreach() {
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
            SYM_FOREACH_AS = ((Symbol*)(intern_rigid_symbol_wrt_module("AS", NULL, 0)));
            SYM_FOREACH_COMMA = ((Symbol*)(intern_rigid_symbol_wrt_module("COMMA", NULL, 0)));
            SYM_FOREACH_DO = ((Symbol*)(intern_rigid_symbol_wrt_module("DO", NULL, 0)));
            SYM_FOREACH_COLLECT = ((Symbol*)(intern_rigid_symbol_wrt_module("COLLECT", NULL, 0)));
            SGT_FOREACH_VOID = ((Surrogate*)(intern_rigid_symbol_wrt_module("VOID", NULL, 1)));
            SYM_FOREACH_WHERE = ((Symbol*)(intern_rigid_symbol_wrt_module("WHERE", NULL, 0)));
            SYM_FOREACH_INTO = ((Symbol*)(intern_rigid_symbol_wrt_module("INTO", NULL, 0)));
            SYM_FOREACH_COLLECT_INTO = ((Symbol*)(intern_rigid_symbol_wrt_module("COLLECT-INTO", NULL, 0)));
            SYM_FOREACH_PREFIX_FOREACH = ((Symbol*)(intern_rigid_symbol_wrt_module("PREFIX-FOREACH", NULL, 0)));
            SYM_FOREACH_IN = ((Symbol*)(intern_rigid_symbol_wrt_module("IN", NULL, 0)));
            SYM_FOREACH_X = ((Symbol*)(intern_rigid_symbol_wrt_module("X", NULL, 0)));
            SYM_FOREACH_NIL = ((Symbol*)(intern_rigid_symbol_wrt_module("NIL", NULL, 0)));
            SYM_FOREACH_FOREACH = ((Symbol*)(intern_rigid_symbol_wrt_module("FOREACH", NULL, 0)));
            SYM_FOREACH_EXISTS = ((Symbol*)(intern_rigid_symbol_wrt_module("EXISTS", NULL, 0)));
            SYM_FOREACH_FORALL = ((Symbol*)(intern_rigid_symbol_wrt_module("FORALL", NULL, 0)));
            SYM_FOREACH_SOME = ((Symbol*)(intern_rigid_symbol_wrt_module("SOME", NULL, 0)));
            SYM_FOREACH_SETOF = ((Symbol*)(intern_rigid_symbol_wrt_module("SETOF", NULL, 0)));
            SYM_FOREACH_SET_OF = ((Symbol*)(intern_rigid_symbol_wrt_module("SET-OF", NULL, 0)));
            SYM_FOREACH_INTERVAL = ((Symbol*)(intern_rigid_symbol_wrt_module("INTERVAL", NULL, 0)));
            SGT_FOREACH_INTEGER_INTERVAL = ((Surrogate*)(intern_rigid_symbol_wrt_module("INTEGER-INTERVAL", NULL, 1)));
            SGT_FOREACH_ABSTRACT_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("ABSTRACT-ITERATOR", NULL, 1)));
            SYM_FOREACH_ALLOCATE_ITERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("ALLOCATE-ITERATOR", NULL, 0)));
            SYM_FOREACH_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", NULL, 0)));
            SGT_FOREACH_STRING = ((Surrogate*)(intern_rigid_symbol_wrt_module("STRING", NULL, 1)));
            SGT_FOREACH_VECTOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("VECTOR", NULL, 1)));
            SGT_FOREACH_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("LIST", NULL, 1)));
            SGT_FOREACH_CONS = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONS", NULL, 1)));
            SYM_FOREACH_THE_CONS_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-CONS-LIST", NULL, 0)));
            SGT_FOREACH_KEY_VALUE_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("KEY-VALUE-LIST", NULL, 1)));
            SGT_FOREACH_KV_CONS = ((Surrogate*)(intern_rigid_symbol_wrt_module("KV-CONS", NULL, 1)));
            SYM_FOREACH_THE_KV_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-KV-LIST", NULL, 0)));
            SGT_FOREACH_PROPERTY_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPERTY-LIST", NULL, 1)));
            SYM_FOREACH_THE_PLIST = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-PLIST", NULL, 0)));
            SYM_FOREACH_KEY = ((Symbol*)(intern_rigid_symbol_wrt_module("KEY", NULL, 0)));
            SYM_FOREACH_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("VALUE", NULL, 0)));
            SYM_FOREACH_SETQ = ((Symbol*)(intern_rigid_symbol_wrt_module("SETQ", NULL, 0)));
            SYM_FOREACH_REST = ((Symbol*)(intern_rigid_symbol_wrt_module("REST", NULL, 0)));
            SYM_FOREACH_NOT = ((Symbol*)(intern_rigid_symbol_wrt_module("NOT", NULL, 0)));
            SYM_FOREACH_NILp = ((Symbol*)(intern_rigid_symbol_wrt_module("NIL?", NULL, 0)));
            SYM_FOREACH_DEFINEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINED?", NULL, 0)));
            SYM_FOREACH_NEXTp = ((Symbol*)(intern_rigid_symbol_wrt_module("NEXT?", NULL, 0)));
            SYM_FOREACH_PROGN = ((Symbol*)(intern_rigid_symbol_wrt_module("PROGN", NULL, 0)));
            SYM_FOREACH_ANY_VALUE = ((Symbol*)(intern_rigid_symbol_wrt_module("ANY-VALUE", NULL, 0)));
            SYM_FOREACH_ANY_KEY = ((Symbol*)(intern_rigid_symbol_wrt_module("ANY-KEY", NULL, 0)));
            SYM_FOREACH_NULL = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL", NULL, 0)));
            SYM_FOREACH_NULL_INTEGER = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL-INTEGER", NULL, 0)));
            SGT_FOREACH_NUMBER_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("NUMBER-WRAPPER", NULL, 1)));
            SGT_FOREACH_INTEGER = ((Surrogate*)(intern_rigid_symbol_wrt_module("INTEGER", NULL, 1)));
            SGT_FOREACH_BOOLEAN = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN", NULL, 1)));
            SYM_FOREACH_NULLp = ((Symbol*)(intern_rigid_symbol_wrt_module("NULL?", NULL, 0)));
            SYM_FOREACH_ii = ((Symbol*)(intern_rigid_symbol_wrt_module("++", NULL, 0)));
            SYM_FOREACH_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", NULL, 0)));
            SYM_FOREACH_le = ((Symbol*)(intern_rigid_symbol_wrt_module("<=", NULL, 0)));
            SYM_FOREACH_OR = ((Symbol*)(intern_rigid_symbol_wrt_module("OR", NULL, 0)));
            SYM_FOREACH_LENGTH = ((Symbol*)(intern_rigid_symbol_wrt_module("LENGTH", NULL, 0)));
            SYM_FOREACH_NTH = ((Symbol*)(intern_rigid_symbol_wrt_module("NTH", NULL, 0)));
            SGT_FOREACH_CHARACTER = ((Surrogate*)(intern_rigid_symbol_wrt_module("CHARACTER", NULL, 1)));
            SYM_FOREACH_l = ((Symbol*)(intern_rigid_symbol_wrt_module("<", NULL, 0)));
            SYM_FOREACH_ON = ((Symbol*)(intern_rigid_symbol_wrt_module("ON", NULL, 0)));
            SYM_FOREACH_AND = ((Symbol*)(intern_rigid_symbol_wrt_module("AND", NULL, 0)));
            SYM_FOREACH_IF = ((Symbol*)(intern_rigid_symbol_wrt_module("IF", NULL, 0)));
            SYM_FOREACH_PERMANENT_CONS = ((Symbol*)(intern_rigid_symbol_wrt_module("PERMANENT-CONS", NULL, 0)));
            SYM_FOREACH_EMPTYp = ((Symbol*)(intern_rigid_symbol_wrt_module("EMPTY?", NULL, 0)));
            SYM_FOREACH_SETF = ((Symbol*)(intern_rigid_symbol_wrt_module("SETF", NULL, 0)));
            SYM_FOREACH_ADD_CONS_TO_END_OF_CONS_LIST = ((Symbol*)(intern_rigid_symbol_wrt_module("ADD-CONS-TO-END-OF-CONS-LIST", NULL, 0)));
            SYM_FOREACH_CONS = ((Symbol*)(intern_rigid_symbol_wrt_module("CONS", NULL, 0)));
            SGT_FOREACH_UNKNOWN = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNKNOWN", NULL, 1)));
            SYM_FOREACH_COND = ((Symbol*)(intern_rigid_symbol_wrt_module("COND", NULL, 0)));
            SYM_FOREACH_CONSp = ((Symbol*)(intern_rigid_symbol_wrt_module("CONS?", NULL, 0)));
            SYM_FOREACH_OTHERWISE = ((Symbol*)(intern_rigid_symbol_wrt_module("OTHERWISE", NULL, 0)));
            SYM_FOREACH_WHEN = ((Symbol*)(intern_rigid_symbol_wrt_module("WHEN", NULL, 0)));
            SYM_FOREACH_SYS_FOREACH = ((Symbol*)(intern_rigid_symbol_wrt_module("SYS-FOREACH", NULL, 0)));
            SYM_FOREACH_VRLET = ((Symbol*)(intern_rigid_symbol_wrt_module("VRLET", NULL, 0)));
            SYM_FOREACH_BREAK = ((Symbol*)(intern_rigid_symbol_wrt_module("BREAK", NULL, 0)));
            SYM_FOREACH_ALWAYS = ((Symbol*)(intern_rigid_symbol_wrt_module("ALWAYS", NULL, 0)));
            SYM_FOREACH_DEFUN = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFUN", NULL, 0)));
            SYM_FOREACH_BOOLEAN = ((Symbol*)(intern_rigid_symbol_wrt_module("BOOLEAN", NULL, 0)));
            SYM_FOREACH_SELF = ((Symbol*)(intern_rigid_symbol_wrt_module("SELF", NULL, 0)));
            SYM_FOREACH_ALL_PURPOSE_ITERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("ALL-PURPOSE-ITERATOR", NULL, 0)));
            SYM_FOREACH_LET = ((Symbol*)(intern_rigid_symbol_wrt_module("LET", NULL, 0)));
            SYM_FOREACH_NESTEDITERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("NESTEDITERATOR", NULL, 0)));
            SYM_FOREACH_ITERATOR_NESTED_ITERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-NESTED-ITERATOR", NULL, 0)));
            SYM_FOREACH_WHILE = ((Symbol*)(intern_rigid_symbol_wrt_module("WHILE", NULL, 0)));
            SYM_FOREACH_RETURN = ((Symbol*)(intern_rigid_symbol_wrt_module("RETURN", NULL, 0)));
            SYM_FOREACH_NEW = ((Symbol*)(intern_rigid_symbol_wrt_module("NEW", NULL, 0)));
            SYM_FOREACH_ITERATOR_NEXT_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR-NEXT-CODE", NULL, 0)));
            SYM_FOREACH_THE_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-CODE", NULL, 0)));
            KWD_FOREACH_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            SGT_FOREACH_ALL_PURPOSE_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("ALL-PURPOSE-ITERATOR", NULL, 1)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-ONE-IN-CLAUSE", "CONS", "(DEFUN (EXTRACT-ONE-IN-CLAUSE CONS CONS) ((TAIL CONS)))");

              method->function_code = ((cpp_function_code)(&extract_one_in_clause));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-ONE-GENERATOR-TERM", "CONS", "(DEFUN (EXTRACT-ONE-GENERATOR-TERM CONS CONS) ((TAIL CONS)))");

              method->function_code = ((cpp_function_code)(&extract_one_generator_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-GENERATORS-CLAUSE", "CONS", "(DEFUN (EXTRACT-GENERATORS-CLAUSE CONS CONS) ((TAIL CONS)))");

              method->function_code = ((cpp_function_code)(&extract_generators_clause));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-OPTION-AND-RESIDUE", "SYMBOL", "(DEFUN (EXTRACT-OPTION-AND-RESIDUE OBJECT CONS) ((OPTION SYMBOL) (TAIL CONS)))");

              method->function_code = ((cpp_function_code)(&extract_option_and_residue));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-DO-CLAUSE", "CONS", "(DEFUN (EXTRACT-DO-CLAUSE CONS CONS) ((TAIL CONS)))");

              method->function_code = ((cpp_function_code)(&extract_do_clause));
            }
            { Method_Slot* method = define_method_from_stringified_source("FOREACH-TO-PREFIX-FOREACH-TREE", "CONS", "(DEFUN (FOREACH-TO-PREFIX-FOREACH-TREE CONS) ((FOREACHTREE CONS)))");

              method->function_code = ((cpp_function_code)(&foreach_to_prefix_foreach_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-FOREACH-TREE", "CONS", "(DEFUN (WALK-FOREACH-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_foreach_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-COLLECTION-TREE", "OBJECT", "(DEFUN (WALK-COLLECTION-TREE OBJECT TYPE-SPEC) ((TREE OBJECT) (DONTOPTIMIZE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&walk_collection_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-IN-CURSOR-CLAUSES", "CONS", "(DEFUN (YIELD-IN-CURSOR-CLAUSES CONS CONS OBJECT) ((INTREE CONS) (DONTOPTIMIZE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&yield_in_cursor_clauses));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-IN-CURSOR-CLAUSES-FOR-GENERAL-COLLECTION", "OBJECT", "(DEFUN (YIELD-IN-CURSOR-CLAUSES-FOR-GENERAL-COLLECTION CONS CONS OBJECT) ((COLLECTIONTREE OBJECT) (COLLECTIONTYPE TYPE-SPEC) (KEYVAR SYMBOL) (VALUEVAR SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_in_cursor_clauses_for_general_collection));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-IN-CURSOR-CLAUSES-FOR-INTEGER-INTERVAL", "CONS", "(DEFUN (YIELD-IN-CURSOR-CLAUSES-FOR-INTEGER-INTERVAL CONS CONS OBJECT) ((COLLECTIONTREE CONS) (COLLECTIONTYPE TYPE-SPEC) (KEYVAR SYMBOL) (VALUEVAR SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_in_cursor_clauses_for_integer_interval));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-IN-CURSOR-CLAUSES-FOR-VECTOR", "OBJECT", "(DEFUN (YIELD-IN-CURSOR-CLAUSES-FOR-VECTOR CONS CONS OBJECT) ((COLLECTIONTREE OBJECT) (COLLECTIONTYPE TYPE-SPEC) (KEYVAR SYMBOL) (VALUEVAR SYMBOL)))");

              method->function_code = ((cpp_function_code)(&yield_in_cursor_clauses_for_vector));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-ON-CURSOR-CLAUSES", "CONS", "(DEFUN (YIELD-ON-CURSOR-CLAUSES CONS CONS OBJECT) ((ONTREE CONS)))");

              method->function_code = ((cpp_function_code)(&yield_on_cursor_clauses));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-CURSOR-CLAUSES", "CONS", "(DEFUN (COLLECT-CURSOR-CLAUSES CONS CONS OBJECT) ((CURSORSTREE CONS) (DONTOPTIMIZE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&collect_cursor_clauses));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-CURSORS-TREE", "CONS", "(DEFUN (WALK-CURSORS-TREE CONS CONS OBJECT) ((CURSORSTREE CONS) (DONTOPTIMIZE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&walk_cursors_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-COLLECT-INTO-LIST-CODE", "SYMBOL", "(DEFUN (YIELD-COLLECT-INTO-LIST-CODE CONS) ((COLLECTVARIABLE SYMBOL) (INTOVARIABLE OBJECT) (COLLECTTREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&yield_collect_into_list_code));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-COLLECT-INTO-CONS-CODE", "SYMBOL", "(DEFUN (YIELD-COLLECT-INTO-CONS-CODE CONS) ((COLLECTVARIABLE SYMBOL) (INTOVARIABLE OBJECT) (COLLECTTREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&yield_collect_into_cons_code));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-COLLECT-CODE", "SYMBOL", "(DEFUN (YIELD-COLLECT-CODE CONS) ((COLLECTVARIABLE SYMBOL) (INTOVARIABLE OBJECT) (COLLECTTREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&yield_collect_code));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-PREFIX-COLLECT-INTO-TREE", "CONS", "(DEFUN (WALK-PREFIX-COLLECT-INTO-TREE CONS CONS) ((COLLECTINTOTREE CONS) (ITERATORS CONS) (VALUEBINDINGS CONS) (DOCODE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_prefix_collect_into_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WRAP-WHERE-TEST", "OBJECT", "(DEFUN (WRAP-WHERE-TEST CONS) ((WHERETEST OBJECT) (ACTIONS CONS)))");

              method->function_code = ((cpp_function_code)(&wrap_where_test));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-PREFIX-FOREACH-BODY", "CONS", "(DEFUN (WALK-PREFIX-FOREACH-BODY CONS) ((ITERATORCLAUSES CONS) (VALUECLAUSES CONS) (WHERETEST CONS) (DOACTIONS CONS)))");

              method->function_code = ((cpp_function_code)(&walk_prefix_foreach_body));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-PREFIX-FOREACH-TREE", "CONS", "(DEFUN (WALK-PREFIX-FOREACH-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_prefix_foreach_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-EXISTS-TREE", "CONS", "(DEFUN (WALK-EXISTS-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_exists_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-FORALL-TREE", "CONS", "(DEFUN (WALK-FORALL-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_forall_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-SOME-TREE", "CONS", "(DEFUN (WALK-SOME-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_some_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-SETOF-NESTED-ITERATOR-TREE", "CONS", "(DEFUN (EXTRACT-SETOF-NESTED-ITERATOR-TREE CONS) ((ITERATORCLAUSES CONS)))");

              method->function_code = ((cpp_function_code)(&extract_setof_nested_iterator_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-SETOF-NEXT-FUNCTION-NAME", "CONS", "(DEFUN (YIELD-SETOF-NEXT-FUNCTION-NAME SYMBOL) ((VALUECLAUSES CONS) (WHERETEST CONS)))");

              method->function_code = ((cpp_function_code)(&yield_setof_next_function_name));
            }
            { Method_Slot* method = define_method_from_stringified_source("WALK-SETOF-TREE", "CONS", "(DEFUN (WALK-SETOF-TREE CONS TYPE-SPEC) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&walk_setof_tree));
            }
            define_method_from_stringified_source("STARTUP-FOREACH", NULL, "(DEFUN STARTUP-FOREACH ())");
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

