// kif-in.cc

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

Symbol* SYM_KIF_IN_PARSE_TREE = NULL;

Symbol* SYM_KIF_IN_ISA = NULL;

Surrogate* SGT_KIF_IN_UNKNOWN = NULL;

Symbol* SYM_KIF_IN_COMMA = NULL;

Symbol* SYM_KIF_IN_THE_ONLY = NULL;

Symbol* SYM_KIF_IN_WHERE = NULL;

Symbol* SYM_KIF_IN_TRUE = NULL;

Symbol* SYM_KIF_IN_AND = NULL;

Symbol* SYM_KIF_IN_le = NULL;

Symbol* SYM_KIF_IN_IMPLIES = NULL;

Symbol* SYM_KIF_IN_ALWAYS = NULL;

Property_List* KIF_OPERATOR_TO_INTERNAL_STELLA_TABLE = NULL;

Symbol* SYM_KIF_IN_i = NULL;

Symbol* SYM_KIF_IN_PLUS = NULL;

Symbol* SYM_KIF_IN__ = NULL;

Symbol* SYM_KIF_IN_MINUS = NULL;

Symbol* SYM_KIF_IN_o = NULL;

Symbol* SYM_KIF_IN_TIMES = NULL;

Symbol* SYM_KIF_IN_s = NULL;

Symbol* SYM_KIF_IN_DIVIDE = NULL;

Symbol* SYM_KIF_IN_g = NULL;

Symbol* SYM_KIF_IN_GREATER_THANp = NULL;

Symbol* SYM_KIF_IN_ge = NULL;

Symbol* SYM_KIF_IN_GREATER_OR_EQUALp = NULL;

Symbol* SYM_KIF_IN_l = NULL;

Symbol* SYM_KIF_IN_LESS_THANp = NULL;

Symbol* SYM_KIF_IN_el = NULL;

Symbol* SYM_KIF_IN_LESS_OR_EQUALp = NULL;

Symbol* SYM_KIF_IN_SUBSET = NULL;

Symbol* SYM_KIF_IN_SUBSET_OF = NULL;

Symbol* SYM_KIF_IN_MEMBER = NULL;

Symbol* SYM_KIF_IN_OR = NULL;

Symbol* SYM_KIF_IN_NOT = NULL;

Symbol* SYM_KIF_IN_eg = NULL;

Symbol* SYM_KIF_IN_EXISTS = NULL;

Symbol* SYM_KIF_IN_FORALL = NULL;

Symbol* SYM_KIF_IN_IN = NULL;

Symbol* SYM_KIF_IN_THE = NULL;

Symbol* SYM_KIF_IN_SETOFALL = NULL;

Symbol* SYM_KIF_IN_KAPPA = NULL;

Symbol* SYM_KIF_IN_TOKEN_NAME = NULL;

Symbol* SYM_KIF_IN_TOKEN_TYPE = NULL;

Surrogate* SGT_KIF_IN_VARIABLE_TOKEN = NULL;

List* oVARIABLE_TOKENSo = NULL;

Key_Value_List* oVARIABLE_TOKEN_STACKo = NULL;

Symbol* SYM_KIF_IN_FALSE = NULL;

Symbol* SYM_KIF_IN_AS = NULL;

boolean oTYPEBECAMENARROWERpo;

Symbol* SYM_KIF_IN_oTYPEBECAMENARROWERpo = NULL;

List* oVISIBLE_TOKEN_STACKo = NULL;

Variable_Token* BLOCKING_TOKEN = NULL;

Symbol* SYM_KIF_IN_e = NULL;

Keyword* oLOGIC_DIALECTo = NULL;

Keyword* KWD_KIF_IN_KIF = NULL;

Symbol* SYM_KIF_IN_oLOGIC_DIALECTo = NULL;

Keyword* KWD_KIF_IN_STELLA = NULL;

Keyword* KWD_KIF_IN_PREFIX_STELLA = NULL;

Keyword* KWD_KIF_IN_SQL = NULL;

boolean question_mark_symbolP(Symbol* symbol) {
  return (string_nth(symbol->symbol_name, 0) == '?');
}

Symbol* remove_question_mark(Symbol* qmsymbol) {
  return (intern_symbol(string_subsequence(qmsymbol->symbol_name, 1, NULL_INTEGER)));
}

Generalized_Symbol* kif_symbol_to_stella_symbol(Symbol* symbol) {
  if (question_mark_symbolP(symbol)) {
    return (symbol);
  }
  else {
    return (symbol->surrogatify());
  }
}

Symbol* kif_variable_to_stella_variable(Object* variable) {
  { Object* variable_001 = variable;

    if (symbolP(variable)) {
      { Symbol* variable = NULL;

        variable = ((Symbol*)(variable_001));
        if (!question_mark_symbolP(variable)) {
          { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

            { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTREADABLYpo = TRUE;
                  cout << "PARSING ERROR: " << "Missing question mark on KIF variable: " << "`" << variable << "'" << "." << endl << endl;
                  signal(oTHE_PARSING_ERRORo);
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
        return (((Symbol*)(kif_symbol_to_stella_symbol(variable))));
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
              cout << "PARSING ERROR: " << "Illegal value in KIF expression where symbol expected " << "`" << variable << "'" << "." << endl << endl;
              signal(oTHE_PARSING_ERRORo);
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

boolean kif_variable_declarationP(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        if ((tree->length() == 2) &&
            (symbolP(tree->first()) &&
             (question_mark_symbolP(((Symbol*)(tree->first()))) &&
              (symbolP(tree->second()) &&
               (!question_mark_symbolP(((Symbol*)(tree->second())))))))) {
          return (TRUE);
        }
      }
    }
    else if (symbolP(tree)) {
      { Symbol* tree = NULL;

        tree = ((Symbol*)(tree_001));
        if (question_mark_symbolP(tree)) {
          return (TRUE);
        }
      }
    }
    else {
      return (FALSE);
    }
  }
  return (FALSE);
}

Cons* listify_kif_variable_declarations(Object* tree) {
  if (kif_variable_declarationP(tree)) {
    return (cons(tree, NIL));
  }
  else {
    return (((Cons*)(tree)));
  }
}

Cons* kif_variable_declaration_to_stella(Object* tree) {
  if (!kif_variable_declarationP(tree)) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            cout << "PARSING ERROR: " << "Illegal KIF variable declaration: " << "`" << tree << "'" << "." << endl << endl;
            signal(oTHE_PARSING_ERRORo);
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
    return (((Cons*)(tree)));
  }
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        tree->first_setter(kif_variable_to_stella_variable(tree->first()));
        tree->second_setter(typify(tree->second()));
        return (cons(SYM_KIF_IN_ISA, tree->concatenate(NIL)));
      }
    }
    else {
      return (listO(3, SYM_KIF_IN_ISA, kif_variable_to_stella_variable(tree), cons(SGT_KIF_IN_UNKNOWN, NIL)));
    }
  }
}

Cons* kif_variable_declarations_to_stella(Cons* tree) {
  { Cons_Iterator* it = tree->allocate_iterator();

    while (it->nextP()) {
      it->value_setter(kif_variable_declaration_to_stella(it->value));
    }
  }
  switch (tree->length()) {
    case 0: 
      return (NIL);
    case 1: 
      return (((Cons*)(tree->first())));
    default:
      return (cons(SYM_KIF_IN_COMMA, tree->concatenate(NIL)));
  }
}

Cons* kif_the_to_stella_the_only(Cons* tree) {
  tree = kif_setofall_to_stella_setofall(tree);
  tree->first_setter(SYM_KIF_IN_THE_ONLY);
  return (tree);
}

Cons* kif_setofall_to_stella_setofall(Cons* tree) {
  if (!((tree->length() == 3) ||
      (tree->length() == 2))) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            cout << "PARSING ERROR: " << "Illegal " << "`" << tree->first() << "'" << " tree: " << "`" << tree << "'" << "." << endl << endl;
            signal(oTHE_PARSING_ERRORo);
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
  tree->second_setter((kif_variable_declarationP(tree->second()) ? ((Object*)(kif_variable_declaration_to_stella(tree->second()))) : ((Object*)(kif_term_to_untyped_stella_term(tree->second())))));
  if (tree->third() != NULL) {
    tree->third_setter(listO(3, SYM_KIF_IN_WHERE, kif_sentence_to_untyped_stella_sentence(tree->third()), NIL));
  }
  return (tree);
}

Cons* kif_kappa_to_stella_kappa(Cons* tree) {
  if (!(tree->length() >= 2)) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            cout << "PARSING ERROR: " << "Illegal KAPPA tree: " << "`" << tree << "'" << "." << endl << endl;
            signal(oTHE_PARSING_ERRORo);
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
  { Cons* sentences = tree->rest->rest;

    tree->second_setter(kif_variable_declarations_to_stella(listify_kif_variable_declarations(tree->second())));
    { Cons_Iterator* it = sentences->allocate_iterator();

      while (it->nextP()) {
        it->value_setter(kif_sentence_to_untyped_stella_sentence(it->value));
      }
    }
    switch (sentences->length()) {
      case 0: 
        tree->rest->rest = cons(listO(3, SYM_KIF_IN_WHERE, SYM_KIF_IN_TRUE, NIL), NIL);
      break;
      case 1: 
        tree->third_setter(listO(3, SYM_KIF_IN_WHERE, tree->third(), NIL));
      break;
      default:
        tree->rest->rest = cons(listO(3, SYM_KIF_IN_WHERE, cons(SYM_KIF_IN_AND, sentences->concatenate(NIL)), NIL), NIL);
      break;
    }
    return (tree);
  }
}

Cons* kif_implies_to_stella_implies(Cons* tree) {
  if (tree->length() < 2) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            cout << "PARSING ERROR: " << "Illegal implication tree: " << "`" << tree << "'" << "." << endl << endl;
            signal(oTHE_PARSING_ERRORo);
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
  if (tree->first() == SYM_KIF_IN_le) {
    tree->rest = tree->rest->reverse();
  }
  change_kif_expressions_to_stella_expressions(tree->rest, FALSE);
  tree->first_setter(SYM_KIF_IN_IMPLIES);
  switch (tree->length()) {
    case 2: 
      return (((Cons*)(tree->second())));
    case 3: 
      return (tree);
    default:
      tree->rest = tree->rest->reverse();
      tree->rest->rest = cons(cons(SYM_KIF_IN_AND, tree->rest->rest->reverse()->concatenate(NIL)), NIL);
      tree->rest = tree->rest->reverse();
      return (tree);
  }
}

Cons* kif_exists_to_stella_exists(Cons* tree) {
  if (!(tree->length() == 3)) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            cout << "PARSING ERROR: " << "Illegal EXISTS tree: " << "`" << tree << "'" << "." << endl << endl;
            signal(oTHE_PARSING_ERRORo);
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
  { Object* sentence = kif_sentence_to_untyped_stella_sentence(tree->third());

    tree->second_setter(kif_variable_declarations_to_stella(listify_kif_variable_declarations(tree->second())));
    tree->third_setter(listO(3, SYM_KIF_IN_WHERE, sentence, NIL));
    return (tree);
  }
}

Cons* kif_forall_to_stella_forall(Cons* tree) {
  if (!(tree->length() == 3)) {
    { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oPRINTREADABLYpo = TRUE;
            cout << "PARSING ERROR: " << "Illegal FORALL tree: " << "`" << tree << "'" << "." << endl << endl;
            signal(oTHE_PARSING_ERRORo);
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
  { Object* sentence = kif_sentence_to_untyped_stella_sentence(tree->third());

    tree->second_setter(kif_variable_declarations_to_stella(listify_kif_variable_declarations(tree->second())));
    { Object* sentence_001 = sentence;

      if (consP(sentence)) {
        { Cons* sentence = NULL;

          sentence = ((Cons*)(sentence_001));
          { Object* test_value_001 = sentence->first();

            if (test_value_001 == SYM_KIF_IN_IMPLIES) {
              tree->third_setter(listO(3, SYM_KIF_IN_WHERE, sentence->second(), NIL));
              last_cons(tree)->rest = cons(listO(3, SYM_KIF_IN_ALWAYS, sentence->third(), NIL), NIL);
              free_cons_list(sentence);
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
    tree->third_setter(listO(3, SYM_KIF_IN_ALWAYS, sentence, NIL));
    return (tree);
  }
}

Cons* kif_predicate_to_stella_predicate(Cons* tree) {
  { Symbol* renamed_Operator = kif_operator_to_internal_stella(((Symbol*)(tree->first())));
    Cons* arguments = tree->rest;

    tree->first_setter(renamed_Operator);
    change_kif_expressions_to_stella_expressions(arguments, TRUE);
    if ((arguments->length() == 1) &&
        (renamed_Operator->get_class(FALSE) != NULL)) {
      tree = tree->concatenate(cons(typify(renamed_Operator), NIL));
      tree->first_setter(SYM_KIF_IN_ISA);
    }
    return (tree);
  }
}

Symbol* kif_operator_to_internal_stella(Symbol* renamed_Operator) {
  { Symbol* newoperator = ((Symbol*)(KIF_OPERATOR_TO_INTERNAL_STELLA_TABLE->lookup(renamed_Operator)));

    return (((newoperator != NULL) ? ((Symbol*)(newoperator)) : ((Symbol*)(renamed_Operator))));
  }
}

Symbol* internal_stella_operator_to_kif(Symbol* renamed_Operator) {
  { Symbol* value = NULL;
    Symbol* key = NULL;
    Cons* iter_001 = KIF_OPERATOR_TO_INTERNAL_STELLA_TABLE->the_plist;

    while (!nilP(iter_001)) {
      key = ((Symbol*)(iter_001->value));
      {
        value = ((Symbol*)(iter_001->rest->value));
        iter_001 = iter_001->rest->rest;
      }
      if (value == renamed_Operator) {
        return (key);
      }
    }
  }
  return (renamed_Operator);
}

void change_kif_expressions_to_stella_expressions(Cons* expressions, boolean termP) {
  { Cons_Iterator* term = expressions->allocate_iterator();

    while (term->nextP()) {
      term->value_setter((termP ? ((Object*)(kif_term_to_untyped_stella_term(term->value))) : ((Object*)(kif_sentence_to_untyped_stella_sentence(term->value)))));
    }
  }
}

Object* kif_sentence_to_untyped_stella_sentence(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Object* renamed_Operator = tree->first();

          if (!symbolP(renamed_Operator)) {
            { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    cout << "PARSING ERROR: " << "Bad first argument in KIF sentence: " << "`" << renamed_Operator << "'" << "." << endl << endl;
                    signal(oTHE_PARSING_ERRORo);
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
          if (renamed_Operator == SYM_KIF_IN_MEMBER) {
            tree->first_setter(SYM_KIF_IN_IN);
            change_kif_expressions_to_stella_expressions(tree->rest, TRUE);
            return (tree);
          }
          else if ((renamed_Operator == SYM_KIF_IN_AND) ||
              ((renamed_Operator == SYM_KIF_IN_OR) ||
               (renamed_Operator == SYM_KIF_IN_NOT))) {
            change_kif_expressions_to_stella_expressions(tree->rest, FALSE);
            return (tree);
          }
          else if ((renamed_Operator == SYM_KIF_IN_eg) ||
              (renamed_Operator == SYM_KIF_IN_le)) {
            return (kif_implies_to_stella_implies(tree));
          }
          else if (renamed_Operator == SYM_KIF_IN_EXISTS) {
            return (kif_exists_to_stella_exists(tree));
          }
          else if (renamed_Operator == SYM_KIF_IN_FORALL) {
            return (kif_forall_to_stella_forall(tree));
          }
          else {
            return (kif_predicate_to_stella_predicate(tree));
          }
        }
      }
    }
    else if (symbolP(tree)) {
      { Symbol* tree = NULL;

        tree = ((Symbol*)(tree_001));
        return (kif_symbol_to_stella_symbol(tree));
      }
    }
    else {
      return (tree);
    }
  }
}

Object* kif_term_to_untyped_stella_term(Object* tree) {
  { Object* tree_001 = tree;

    if (symbolP(tree)) {
      { Symbol* tree = NULL;

        tree = ((Symbol*)(tree_001));
        return (kif_symbol_to_stella_symbol(tree));
      }
    }
    else if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Object* renamed_Operator = tree->first();

          if (!symbolP(renamed_Operator)) {
            { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

              { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oPRINTREADABLYpo = TRUE;
                    cout << "PARSING ERROR: " << "Bad first argument in KIF term: " << "`" << renamed_Operator << "'" << "." << endl << endl;
                    signal(oTHE_PARSING_ERRORo);
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
          if (renamed_Operator == SYM_KIF_IN_THE) {
            return (kif_the_to_stella_the_only(tree));
          }
          else if (renamed_Operator == SYM_KIF_IN_SETOFALL) {
            return (kif_setofall_to_stella_setofall(tree));
          }
          else if (renamed_Operator == SYM_KIF_IN_KAPPA) {
            return (kif_kappa_to_stella_kappa(tree));
          }
          else {
            tree->first_setter(kif_operator_to_internal_stella(((Symbol*)(renamed_Operator))));
            change_kif_expressions_to_stella_expressions(tree->rest, TRUE);
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

Object* kif_expression_to_untyped_stella_expression(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Object* test_value_001 = tree->first();

          if ((test_value_001 == SYM_KIF_IN_THE) ||
              ((test_value_001 == SYM_KIF_IN_SETOFALL) ||
               (test_value_001 == SYM_KIF_IN_KAPPA))) {
            return (kif_term_to_untyped_stella_term(tree));
          }
          else {
            return (kif_sentence_to_untyped_stella_sentence(tree));
          }
        }
      }
    }
    else {
      return (kif_sentence_to_untyped_stella_sentence(tree));
    }
  }
}

Variable_Token* new_variable_token() {
  { Variable_Token* self = NULL;

    self = new Variable_Token;
    self->token_type = NULL;
    self->token_name = NULL;
    return (self);
  }
}

Object* access_variable_token_slot_value(Variable_Token* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_KIF_IN_TOKEN_NAME) {
    if (setvalueP) {
      self->token_name = ((Symbol*)(value));
    }
    else {
      return (self->token_name);
    }
  }
  else if (slotname == SYM_KIF_IN_TOKEN_TYPE) {
    if (setvalueP) {
      self->token_type = ((Standard_Object*)(value));
    }
    else {
      return (self->token_type);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Variable_Token::primary_type() {
  { Variable_Token* self = this;

    return (SGT_KIF_IN_VARIABLE_TOKEN);
  }
}

boolean tokenP(Object* object) {
  return (isaP(object, SGT_KIF_IN_VARIABLE_TOKEN));
}

Variable_Token* introduce_variable_token(Symbol* symbol, Object* typetree) {
  { Variable_Token* token = new_variable_token();

    token->token_name = symbol;
    token->token_type = typetree->yield_type_specifier();
    oVARIABLE_TOKENSo->push(token);
    oVARIABLE_TOKEN_STACKo->the_kv_list = kv_cons(symbol, token, oVARIABLE_TOKEN_STACKo->the_kv_list);
    return (token);
  }
}

Variable_Token* find_variable_token(Symbol* symbol) {
  { Variable_Token* token = ((Variable_Token*)(oVARIABLE_TOKEN_STACKo->lookup(symbol)));

    if (token == NULL) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              cout << "PARSING ERROR: " << "Undeclared variable " << "`" << symbol << "'" << "." << endl << endl;
              signal(oTHE_PARSING_ERRORo);
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
    return (token);
  }
}

void clear_token_tables() {
  { Variable_Token* token = NULL;
    Cons* iter_001 = oVARIABLE_TOKENSo->the_cons_list;

    while (!nilP(iter_001)) {
      {
        token = ((Variable_Token*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      token->free();
    }
  }
  oVARIABLE_TOKENSo->clear();
  oVARIABLE_TOKEN_STACKo->clear();
}

Class* compute_term_class(Object* term) {
  { Object* term_001 = term;

    if (wrapperP(term)) {
      { Wrapper* term = NULL;

        term = ((Wrapper*)(term_001));
        return (((Class*)(wrapper_value_type(term)->surrogate_value)));
      }
    }
    else if (taxonomy_isaP(term, SGT_KIF_IN_VARIABLE_TOKEN)) {
      { Variable_Token* term = NULL;

        term = ((Variable_Token*)(term_001));
        if (term->token_type == SGT_KIF_IN_UNKNOWN) {
          return (NULL);
        }
        else {
          return (((Class*)(type_spec_to_base_type(term->token_type)->surrogate_value)));
        }
      }
    }
    else if (surrogateP(term)) {
      { Surrogate* term = NULL;

        term = ((Surrogate*)(term_001));
        if (term->surrogate_value != NULL) {
          return (term->surrogate_value->primary_class());
        }
        else {
          return (NULL);
        }
      }
    }
    else {
      return (term->primary_class());
    }
  }
}

Slot* compute_term_slot(Cons* term) {
  if (term->second() == NULL) {
    return (NULL);
  }
  { Class* renamed_Class = compute_term_class(term->second());

    if (renamed_Class != NULL) {
      return (safe_lookup_slot(renamed_Class, ((Symbol*)(term->first()))));
    }
    else {
      return (NULL);
    }
  }
}

void substitute_tokens_into_terms(Cons* termlist) {
  { Cons_Iterator* it = termlist->allocate_iterator();

    while (it->nextP()) {
      { Object* term = it->value;

        { Object* term_001 = term;

          if (symbolP(term)) {
            { Symbol* term = NULL;

              term = ((Symbol*)(term_001));
              if ((term == SYM_KIF_IN_TRUE) ||
                  (term == SYM_KIF_IN_FALSE)) {
              }
              else {
                it->value_setter(find_variable_token(term));
              }
            }
          }
          else if (consP(term)) {
            { Cons* term = NULL;

              term = ((Cons*)(term_001));
              substitute_in_variable_tokens(term);
            }
          }
          else {
          }
        }
      }
    }
  }
}

void substitute_tokens_into_variable_declarations(Cons* declordecls) {
  { Object* test_value_001 = declordecls->first();

    if (test_value_001 == SYM_KIF_IN_ISA) {
      declordecls->second_setter(introduce_variable_token(((Symbol*)(declordecls->second())), declordecls->third()));
    }
    else if (test_value_001 == SYM_KIF_IN_IN) {
      { Slot* slot = compute_term_slot(((Cons*)(declordecls->third())));

        if (slot != NULL) {
        }
      }
    }
    else if ((test_value_001 == SYM_KIF_IN_COMMA) ||
        (test_value_001 == SYM_KIF_IN_AS)) {
      { Object* decl = NULL;
        Cons* iter_001 = declordecls->rest;

        while (!nilP(iter_001)) {
          {
            decl = iter_001->value;
            iter_001 = iter_001->rest;
          }
          substitute_tokens_into_variable_declarations(((Cons*)(decl)));
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
              cout << "PARSING ERROR: " << "Illegal clause headed by " << "`" << declordecls->first() << "'" << " encountered while parsing variable declarations." << endl << "." << endl << endl;
              signal(oTHE_PARSING_ERRORo);
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

void pop_tokens_in_declarations(Cons* declordecls) {
  { Object* test_value_001 = declordecls->first();

    if ((test_value_001 == SYM_KIF_IN_ISA) ||
        (test_value_001 == SYM_KIF_IN_IN)) {
      oVARIABLE_TOKEN_STACKo->pop();
    }
    else if ((test_value_001 == SYM_KIF_IN_AS) ||
        (test_value_001 == SYM_KIF_IN_COMMA)) {
      { Object* decl = NULL;
        Cons* iter_001 = declordecls->rest;

        while (!nilP(iter_001)) {
          {
            decl = iter_001->value;
            iter_001 = iter_001->rest;
          }
          pop_tokens_in_declarations(((Cons*)(decl)));
        }
      }
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

void substitute_in_variable_tokens(Cons* tree) {
  { Symbol* renamed_Operator = ((Symbol*)(tree->first()));

    if ((renamed_Operator == SYM_KIF_IN_EXISTS) ||
        ((renamed_Operator == SYM_KIF_IN_FORALL) ||
         ((renamed_Operator == SYM_KIF_IN_THE_ONLY) ||
          ((renamed_Operator == SYM_KIF_IN_SETOFALL) ||
           (renamed_Operator == SYM_KIF_IN_KAPPA))))) {
      substitute_tokens_into_variable_declarations(((Cons*)(tree->second())));
      substitute_tokens_into_terms(tree->rest->rest);
      pop_tokens_in_declarations(((Cons*)(tree->second())));
    }
    else {
      substitute_tokens_into_terms(tree->rest);
    }
  }
}

boolean read_OtypebecamenarrowerPO() {
  return (oTYPEBECAMENARROWERpo);
}

boolean write_OtypebecamenarrowerPO(boolean value) {
  oTYPEBECAMENARROWERpo = value;
  return (value);
}

void push_visible_tokens(Cons* declordecls) {
  { Object* test_value_001 = declordecls->first();

    if ((test_value_001 == SYM_KIF_IN_ISA) ||
        (test_value_001 == SYM_KIF_IN_IN)) {
      oVISIBLE_TOKEN_STACKo->push(((Variable_Token*)(declordecls->second())));
    }
    else if ((test_value_001 == SYM_KIF_IN_AS) ||
        (test_value_001 == SYM_KIF_IN_COMMA)) {
      { Object* decl = NULL;
        Cons* iter_001 = declordecls->rest;

        while (!nilP(iter_001)) {
          {
            decl = iter_001->value;
            iter_001 = iter_001->rest;
          }
          push_visible_tokens(((Cons*)(decl)));
        }
      }
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

void pop_visible_tokens(Cons* declordecls) {
  { Object* test_value_001 = declordecls->first();

    if ((test_value_001 == SYM_KIF_IN_ISA) ||
        (test_value_001 == SYM_KIF_IN_IN)) {
      oVISIBLE_TOKEN_STACKo->pop();
    }
    else if ((test_value_001 == SYM_KIF_IN_AS) ||
        (test_value_001 == SYM_KIF_IN_COMMA)) {
      { Object* decl = NULL;
        Cons* iter_001 = declordecls->rest;

        while (!nilP(iter_001)) {
          {
            decl = iter_001->value;
            iter_001 = iter_001->rest;
          }
          pop_visible_tokens(((Cons*)(decl)));
        }
      }
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

void block_visible_tokens() {
  oVISIBLE_TOKEN_STACKo->push(BLOCKING_TOKEN);
}

void unblock_visible_tokens() {
  oVISIBLE_TOKEN_STACKo->pop();
}

boolean all_tokens_blockedP() {
  return (oVISIBLE_TOKEN_STACKo->first() == BLOCKING_TOKEN);
}

boolean token_is_visibleP(Variable_Token* token) {
  { Variable_Token* vt = NULL;
    Cons* iter_001 = oVISIBLE_TOKEN_STACKo->the_cons_list;

    while (!nilP(iter_001)) {
      {
        vt = ((Variable_Token*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (vt == BLOCKING_TOKEN) {
        return (FALSE);
      }
      if (vt == token) {
        return (TRUE);
      }
    }
  }
  return (FALSE);
}

void update_token_type(Variable_Token* token, Surrogate* type) {
  { Surrogate* oldtype = type_spec_to_base_type(token->token_type);

    if ((oldtype == SGT_KIF_IN_UNKNOWN) ||
        (subtype_ofP(type, oldtype) &&
         (!(type == oldtype)))) {
      token->token_type = type;
      oTYPEBECAMENARROWERpo = TRUE;
    }
  }
}

void infer_variable_types_within_terms(Cons* termlist) {
  { Object* term = NULL;
    Cons* iter_001 = termlist;

    while (!nilP(iter_001)) {
      {
        term = iter_001->value;
        iter_001 = iter_001->rest;
      }
      help_infer_variable_types(term);
    }
  }
}

void infer_types_in_predication(Cons* predication) {
  block_visible_tokens();
  infer_variable_types_within_terms(predication->rest);
  unblock_visible_tokens();
  if (!tokenP(predication->last())) {
    return;
  }
  { Variable_Token* token = ((Variable_Token*)(predication->last()));
    Symbol* relationname = ((Symbol*)(predication->first()));

    if (!token_is_visibleP(token)) {
      return;
    }
    switch (predication->length()) {
      case 0: 
      case 1: 
      break;
      default:
        { Slot* slot = compute_term_slot(predication);

          if (slot != NULL) {
          }
        }
      break;
    }
  }
}

void infer_types_in_isa_term(Cons* isaterm) {
  if (tokenP(isaterm->second())) {
    { Variable_Token* token = ((Variable_Token*)(isaterm->second()));
      Surrogate* type = ((Surrogate*)(isaterm->third()));

      if (!token_is_visibleP(token)) {
        return;
      }
      if (((Class*)(type->surrogate_value)) != NULL) {
        update_token_type(token, type);
      }
    }
  }
}

void infer_types_in_in_term(Cons* interm) {
  if (tokenP(interm->second())) {
    { Variable_Token* token = ((Variable_Token*)(interm->second()));
      Slot* slot = NULL;

      if (!token_is_visibleP(token)) {
        return;
      }
      slot = compute_term_slot(((Cons*)(interm->third())));
      if (slot != NULL) {
      }
    }
  }
  block_visible_tokens();
  help_infer_variable_types(interm->third());
  unblock_visible_tokens();
}

void help_infer_equal_terms(Object* term1, Object* term2) {
  if (tokenP(term1) &&
      consP(term2)) {
    { Slot* slot = compute_term_slot(((Cons*)(term2)));

      if (slot != NULL) {
        update_token_type(((Variable_Token*)(term1)), slot->type());
      }
    }
  }
}

void infer_types_in_equal_term(Cons* eqterm) {
  help_infer_equal_terms(eqterm->second(), eqterm->third());
  help_infer_equal_terms(eqterm->third(), eqterm->second());
  block_visible_tokens();
  infer_variable_types_within_terms(eqterm->rest);
  unblock_visible_tokens();
}

void help_infer_variable_types(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Symbol* renamed_Operator = ((Symbol*)(tree->first()));

          if ((renamed_Operator == SYM_KIF_IN_EXISTS) ||
              ((renamed_Operator == SYM_KIF_IN_THE_ONLY) ||
               ((renamed_Operator == SYM_KIF_IN_SETOFALL) ||
                (renamed_Operator == SYM_KIF_IN_KAPPA)))) {
            push_visible_tokens(((Cons*)(tree->second())));
            help_infer_variable_types(tree->third());
            pop_visible_tokens(((Cons*)(tree->second())));
          }
          else if (renamed_Operator == SYM_KIF_IN_FORALL) {
            block_visible_tokens();
            push_visible_tokens(((Cons*)(tree->second())));
            infer_variable_types_within_terms(tree->rest->rest);
            pop_visible_tokens(((Cons*)(tree->second())));
            unblock_visible_tokens();
          }
          else if ((renamed_Operator == SYM_KIF_IN_AND) ||
              (renamed_Operator == SYM_KIF_IN_WHERE)) {
            infer_variable_types_within_terms(tree->rest);
          }
          else if ((renamed_Operator == SYM_KIF_IN_OR) ||
              ((renamed_Operator == SYM_KIF_IN_NOT) ||
               (renamed_Operator == SYM_KIF_IN_ALWAYS))) {
            block_visible_tokens();
            infer_variable_types_within_terms(tree->rest);
            unblock_visible_tokens();
          }
          else if (renamed_Operator == SYM_KIF_IN_ISA) {
            infer_types_in_isa_term(tree);
          }
          else if (renamed_Operator == SYM_KIF_IN_IN) {
            infer_types_in_in_term(tree);
          }
          else if (renamed_Operator == SYM_KIF_IN_e) {
            infer_types_in_equal_term(tree);
          }
          else {
            infer_types_in_predication(tree);
          }
        }
      }
    }
    else {
    }
  }
}

void infer_variable_types(Cons* tree) {
  { boolean old_OtypebecamenarrowerPO_001 = oTYPEBECAMENARROWERpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oTYPEBECAMENARROWERpo = FALSE;
          for (;;) {
            oVISIBLE_TOKEN_STACKo->clear();
            help_infer_variable_types(tree);
            if (!oTYPEBECAMENARROWERpo) {
              {
                {
                  oTYPEBECAMENARROWERpo = old_OtypebecamenarrowerPO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                }
                return;
              }
            }
            oTYPEBECAMENARROWERpo = FALSE;
          }
          oTYPEBECAMENARROWERpo = old_OtypebecamenarrowerPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oTYPEBECAMENARROWERpo = old_OtypebecamenarrowerPO_001;
        resignal();
      }
    }
  }
}

Object* substitute_out_variable_tokens(Object* tree) {
  { Object* tree_001 = tree;

    if (taxonomy_isaP(tree, SGT_KIF_IN_VARIABLE_TOKEN)) {
      { Variable_Token* tree = NULL;

        tree = ((Variable_Token*)(tree_001));
        return (tree->token_name);
      }
    }
    else if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Symbol* renamed_Operator = ((Symbol*)(tree->first()));
          Variable_Token* token = NULL;

          if (renamed_Operator == SYM_KIF_IN_ISA) {
            if (tokenP(tree->second())) {
              token = ((Variable_Token*)(tree->second()));
              tree->second_setter(token->token_name);
              if ((SGT_KIF_IN_UNKNOWN == tree->third()) ||
                  ((((Class*)(typify(tree->third())->surrogate_value)) != NULL) &&
                   sub_type_spec_ofP(token->token_type, typify(tree->third())))) {
                tree->third_setter(token->token_type);
              }
            }
            else {
              { Object* test_value_001 = tree->second();

                if (consP(test_value_001)) {
                  { Cons_Iterator* it = ((Cons*)(tree->second()))->allocate_iterator();

                    while (it->nextP()) {
                      it->value_setter(substitute_out_variable_tokens(it->value));
                    }
                  }
                }
                else {
                  return (tree);
                }
              }
            }
          }
          else {
            { Cons_Iterator* it = tree->rest->allocate_iterator();

              while (it->nextP()) {
                it->value_setter(substitute_out_variable_tokens(it->value));
              }
            }
          }
          return (tree);
        }
      }
    }
    else {
      return (tree);
    }
  }
}

void untyped_stella_tree_to_typed_stella(Cons* tree) {
  clear_token_tables();
  substitute_in_variable_tokens(tree);
  infer_variable_types(tree);
  substitute_out_variable_tokens(tree);
  { boolean untypedtokensP = FALSE;

    { Variable_Token* token = NULL;
      Cons* iter_001 = oVARIABLE_TOKENSo->the_cons_list;

      while (!nilP(iter_001)) {
        {
          token = ((Variable_Token*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (token->token_type == SGT_KIF_IN_UNKNOWN) {
          untypedtokensP = TRUE;
        }
      }
    }
    if (untypedtokensP) {
    }
  }
  clear_token_tables();
}

Object* convert_to_prefix_proposition_tree(Object* tree) {
  { Object* tree_001 = tree;

    if (consP(tree)) {
      { Cons* tree = NULL;

        tree = ((Cons*)(tree_001));
        { Symbol* renamed_Operator = ((Symbol*)(tree->first()));

          if (quantifier_symbolP(renamed_Operator)) {
            tree = infix_to_prefix_quantification_tree(tree);
          }
          else {
            { Cons_Iterator* it = tree->rest->allocate_iterator();

              while (it->nextP()) {
                if (consP(it->value)) {
                  it->value_setter(convert_to_prefix_proposition_tree(it->value));
                }
              }
            }
          }
          return (tree);
        }
      }
    }
    else {
      return (tree);
    }
  }
}

Cons* infix_to_prefix_quantification_tree(Cons* tree) {
  { Object* quantifier = tree->first();
    Cons* generatorsclause = NULL;
    Object* whereclause = NULL;
    Object* alwaysclause = NULL;
    Cons* residue = tree->rest;
    Cons* otree = NULL;

    tree->free_cons();
    generatorsclause = extract_generators_clause(residue, residue);
    if (generatorsclause == NULL) {
      free_cons_tree(residue);
      return (NULL);
    }
    whereclause = extract_option_and_residue(SYM_KIF_IN_WHERE, residue, residue);
    alwaysclause = extract_option_and_residue(SYM_KIF_IN_ALWAYS, residue, residue);
    otree = cons(quantifier, cons(convert_to_prefix_proposition_tree(generatorsclause), ((whereclause != NULL) ? ((Cons*)(cons(listO(3, SYM_KIF_IN_WHERE, convert_to_prefix_proposition_tree(whereclause), NIL), NIL))) : ((Cons*)(NIL)))->concatenate(((alwaysclause != NULL) ? ((Cons*)(cons(listO(3, SYM_KIF_IN_ALWAYS, convert_to_prefix_proposition_tree(alwaysclause), NIL), NIL))) : ((Cons*)(NIL)))->concatenate(NIL))));
    if (residue->non_emptyP()) {
      free_cons_tree(residue);
      free_cons_tree(otree);
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              cout << "PARSING ERROR: " << "Extra expressions at the end of quantified expression" << "." << endl << endl;
              signal(oTHE_PARSING_ERRORo);
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
    return (otree);
  }
}

Object* access_prefix_quantification_clause(Cons* prefixquantificationtree, Symbol* clausename, boolean extractP) {
  { Object* clause = NULL;
    Cons* clauses = prefixquantificationtree->rest->rest;
    Object* thisclause = NULL;

    while (clauses->non_emptyP()) {
      thisclause = clauses->first();
      { Object* thisclause_001 = thisclause;

        if (consP(thisclause)) {
          { Cons* thisclause = NULL;

            thisclause = ((Cons*)(thisclause_001));
            if (thisclause->first() == clausename) {
              clause = thisclause->second();
              if (extractP) {
                free_cons_list(thisclause);
                clauses->first_setter(NULL);
              }
              break;
            }
          }
        }
        else {
        }
      }
      clauses = clauses->rest;
    }
    if (extractP) {
      prefixquantificationtree->remove(NULL);
    }
    return (clause);
  }
}

Object* extract_where_clause(Cons* prefixquantificationtree) {
  return (access_prefix_quantification_clause(prefixquantificationtree, SYM_KIF_IN_WHERE, TRUE));
}

Object* extract_always_clause(Cons* prefixquantificationtree) {
  return (access_prefix_quantification_clause(prefixquantificationtree, SYM_KIF_IN_ALWAYS, TRUE));
}

Object* lookup_where_clause(Cons* prefixquantificationtree) {
  return (access_prefix_quantification_clause(prefixquantificationtree, SYM_KIF_IN_WHERE, FALSE));
}

Object* lookup_always_clause(Cons* prefixquantificationtree) {
  return (access_prefix_quantification_clause(prefixquantificationtree, SYM_KIF_IN_ALWAYS, FALSE));
}

Keyword* read_Ologic_dialectO() {
  return (oLOGIC_DIALECTo);
}

Keyword* write_Ologic_dialectO(Keyword* value) {
  oLOGIC_DIALECTo = value;
  return (value);
}

Object* standardize_logical_parse_tree(Object* tree) {
  { Object* standardizedtree = NULL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            if (oLOGIC_DIALECTo == KWD_KIF_IN_KIF) {
              standardizedtree = kif_expression_to_untyped_stella_expression(tree);
              if (consP(standardizedtree)) {
                untyped_stella_tree_to_typed_stella(((Cons*)(standardizedtree)));
              }
            }
            else if (oLOGIC_DIALECTo == KWD_KIF_IN_STELLA) {
              standardizedtree = convert_to_prefix_proposition_tree(tree);
            }
            else if (oLOGIC_DIALECTo == KWD_KIF_IN_PREFIX_STELLA) {
              standardizedtree = tree;
            }
            else if (oLOGIC_DIALECTo == KWD_KIF_IN_SQL) {
            }
            else {
              cerr << "`" << oLOGIC_DIALECTo << "'" << " is not a valid case option";
            }
            { 
              oTRANSIENTOBJECTSpo = old_OtransientobjectsPO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (standardizedtree);
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

Keyword* in_dialect(Object* dialect) {
  // Change the current logic dialect to `dialect'.
  // Currently supported dialects are `KIF', `STELLA', and `PREFIX-STELLA'.
  // The STELLA dialects are not recommended for the construction of knowledge
  // bases, they are mainly used internally by PowerLoom.
  { Object* dialect_001 = dialect;

    if (symbolP(dialect)) {
      { Symbol* dialect = NULL;

        dialect = ((Symbol*)(dialect_001));
        oLOGIC_DIALECTo = dialect->keywordify();
      }
    }
    else if (stringP(dialect)) {
      { String_Wrapper* dialect = NULL;

        dialect = ((String_Wrapper*)(dialect_001));
        oLOGIC_DIALECTo = string_keywordify(dialect->wrapper_value);
      }
    }
    else if (keywordP(dialect)) {
      { Keyword* dialect = NULL;

        dialect = ((Keyword*)(dialect_001));
        oLOGIC_DIALECTo = dialect;
      }
    }
    else {
      cerr << "IN-DIALECT: Illegal dialect specification: " << "`" << dialect << "'";
    }
  }
  return (oLOGIC_DIALECTo);
}

void startup_kif_in() {
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
            SYM_KIF_IN_PARSE_TREE = ((Symbol*)(intern_rigid_symbol_wrt_module("PARSE-TREE", NULL, 0)));
            SYM_KIF_IN_ISA = ((Symbol*)(intern_rigid_symbol_wrt_module("ISA", string_get_module("/STELLA", TRUE), 0)));
            SGT_KIF_IN_UNKNOWN = ((Surrogate*)(intern_rigid_symbol_wrt_module("UNKNOWN", string_get_module("/STELLA", TRUE), 1)));
            SYM_KIF_IN_COMMA = ((Symbol*)(intern_rigid_symbol_wrt_module("COMMA", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_THE_ONLY = ((Symbol*)(intern_rigid_symbol_wrt_module("THE-ONLY", NULL, 0)));
            SYM_KIF_IN_WHERE = ((Symbol*)(intern_rigid_symbol_wrt_module("WHERE", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_AND = ((Symbol*)(intern_rigid_symbol_wrt_module("AND", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_le = ((Symbol*)(intern_rigid_symbol_wrt_module("<=", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_IMPLIES = ((Symbol*)(intern_rigid_symbol_wrt_module("IMPLIES", NULL, 0)));
            SYM_KIF_IN_ALWAYS = ((Symbol*)(intern_rigid_symbol_wrt_module("ALWAYS", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_i = ((Symbol*)(intern_rigid_symbol_wrt_module("+", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_PLUS = ((Symbol*)(intern_rigid_symbol_wrt_module("PLUS", NULL, 0)));
            SYM_KIF_IN__ = ((Symbol*)(intern_rigid_symbol_wrt_module("-", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_MINUS = ((Symbol*)(intern_rigid_symbol_wrt_module("MINUS", NULL, 0)));
            SYM_KIF_IN_o = ((Symbol*)(intern_rigid_symbol_wrt_module("*", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_TIMES = ((Symbol*)(intern_rigid_symbol_wrt_module("TIMES", NULL, 0)));
            SYM_KIF_IN_s = ((Symbol*)(intern_rigid_symbol_wrt_module("/", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_DIVIDE = ((Symbol*)(intern_rigid_symbol_wrt_module("DIVIDE", NULL, 0)));
            SYM_KIF_IN_g = ((Symbol*)(intern_rigid_symbol_wrt_module(">", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_GREATER_THANp = ((Symbol*)(intern_rigid_symbol_wrt_module("GREATER-THAN?", NULL, 0)));
            SYM_KIF_IN_ge = ((Symbol*)(intern_rigid_symbol_wrt_module(">=", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_GREATER_OR_EQUALp = ((Symbol*)(intern_rigid_symbol_wrt_module("GREATER-OR-EQUAL?", NULL, 0)));
            SYM_KIF_IN_l = ((Symbol*)(intern_rigid_symbol_wrt_module("<", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_LESS_THANp = ((Symbol*)(intern_rigid_symbol_wrt_module("LESS-THAN?", NULL, 0)));
            SYM_KIF_IN_el = ((Symbol*)(intern_rigid_symbol_wrt_module("=<", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_LESS_OR_EQUALp = ((Symbol*)(intern_rigid_symbol_wrt_module("LESS-OR-EQUAL?", NULL, 0)));
            SYM_KIF_IN_SUBSET = ((Symbol*)(intern_rigid_symbol_wrt_module("SUBSET", NULL, 0)));
            SYM_KIF_IN_SUBSET_OF = ((Symbol*)(intern_rigid_symbol_wrt_module("SUBSET-OF", NULL, 0)));
            SYM_KIF_IN_MEMBER = ((Symbol*)(intern_rigid_symbol_wrt_module("MEMBER", NULL, 0)));
            SYM_KIF_IN_OR = ((Symbol*)(intern_rigid_symbol_wrt_module("OR", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_NOT = ((Symbol*)(intern_rigid_symbol_wrt_module("NOT", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_eg = ((Symbol*)(intern_rigid_symbol_wrt_module("=>", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_EXISTS = ((Symbol*)(intern_rigid_symbol_wrt_module("EXISTS", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_FORALL = ((Symbol*)(intern_rigid_symbol_wrt_module("FORALL", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_IN = ((Symbol*)(intern_rigid_symbol_wrt_module("IN", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_THE = ((Symbol*)(intern_rigid_symbol_wrt_module("THE", NULL, 0)));
            SYM_KIF_IN_SETOFALL = ((Symbol*)(intern_rigid_symbol_wrt_module("SETOFALL", NULL, 0)));
            SYM_KIF_IN_KAPPA = ((Symbol*)(intern_rigid_symbol_wrt_module("KAPPA", NULL, 0)));
            SYM_KIF_IN_TOKEN_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("TOKEN-NAME", NULL, 0)));
            SYM_KIF_IN_TOKEN_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("TOKEN-TYPE", NULL, 0)));
            SGT_KIF_IN_VARIABLE_TOKEN = ((Surrogate*)(intern_rigid_symbol_wrt_module("VARIABLE-TOKEN", NULL, 1)));
            SYM_KIF_IN_FALSE = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_AS = ((Symbol*)(intern_rigid_symbol_wrt_module("AS", string_get_module("/STELLA", TRUE), 0)));
            SYM_KIF_IN_oTYPEBECAMENARROWERpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*TYPEBECAMENARROWER?*", NULL, 0)));
            SYM_KIF_IN_e = ((Symbol*)(intern_rigid_symbol_wrt_module("=", string_get_module("/STELLA", TRUE), 0)));
            KWD_KIF_IN_KIF = ((Keyword*)(intern_rigid_symbol_wrt_module("KIF", NULL, 2)));
            SYM_KIF_IN_oLOGIC_DIALECTo = ((Symbol*)(intern_rigid_symbol_wrt_module("*LOGIC-DIALECT*", NULL, 0)));
            KWD_KIF_IN_STELLA = ((Keyword*)(intern_rigid_symbol_wrt_module("STELLA", NULL, 2)));
            KWD_KIF_IN_PREFIX_STELLA = ((Keyword*)(intern_rigid_symbol_wrt_module("PREFIX-STELLA", NULL, 2)));
            KWD_KIF_IN_SQL = ((Keyword*)(intern_rigid_symbol_wrt_module("SQL", NULL, 2)));
          }
          if (current_startup_time_phaseP(4)) {
            { Property_List* self_011 = new_property_list();

              self_011->the_plist = listO(19, SYM_KIF_IN_i, SYM_KIF_IN_PLUS, SYM_KIF_IN__, SYM_KIF_IN_MINUS, SYM_KIF_IN_o, SYM_KIF_IN_TIMES, SYM_KIF_IN_s, SYM_KIF_IN_DIVIDE, SYM_KIF_IN_g, SYM_KIF_IN_GREATER_THANp, SYM_KIF_IN_ge, SYM_KIF_IN_GREATER_OR_EQUALp, SYM_KIF_IN_l, SYM_KIF_IN_LESS_THANp, SYM_KIF_IN_el, SYM_KIF_IN_LESS_OR_EQUALp, SYM_KIF_IN_SUBSET, SYM_KIF_IN_SUBSET_OF, NIL);
              KIF_OPERATOR_TO_INTERNAL_STELLA_TABLE = self_011;
            }
            oVARIABLE_TOKENSo = new_list();
            oVARIABLE_TOKEN_STACKo = new_key_value_list();
            oVISIBLE_TOKEN_STACKo = new_list();
            BLOCKING_TOKEN = new_variable_token();
            oLOGIC_DIALECTo = KWD_KIF_IN_KIF;
          }
          if (current_startup_time_phaseP(5)) {
            define_stella_type_from_stringified_source("(DEFTYPE PARSE-TREE OBJECT)");
            { Class* renamed_Class = define_class_from_stringified_source("VARIABLE-TOKEN", "(DEFCLASS VARIABLE-TOKEN (OBJECT) :SLOTS ((TOKEN-NAME :TYPE SYMBOL) (TOKEN-TYPE :TYPE TYPE-SPEC)) :RECYCLE-METHOD :RECYCLE-LIST)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_variable_token));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_variable_token_slot_value));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("QUESTION-MARK-SYMBOL?", "SYMBOL", "(DEFUN (QUESTION-MARK-SYMBOL? BOOLEAN) ((SYMBOL SYMBOL)))");

              method->function_code = ((cpp_function_code)(&question_mark_symbolP));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-QUESTION-MARK", "SYMBOL", "(DEFUN (REMOVE-QUESTION-MARK SYMBOL) ((QMSYMBOL SYMBOL)))");

              method->function_code = ((cpp_function_code)(&remove_question_mark));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-SYMBOL-TO-STELLA-SYMBOL", "SYMBOL", "(DEFUN (KIF-SYMBOL-TO-STELLA-SYMBOL GENERALIZED-SYMBOL) ((SYMBOL SYMBOL)))");

              method->function_code = ((cpp_function_code)(&kif_symbol_to_stella_symbol));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-VARIABLE-TO-STELLA-VARIABLE", "OBJECT", "(DEFUN (KIF-VARIABLE-TO-STELLA-VARIABLE SYMBOL) ((VARIABLE OBJECT)))");

              method->function_code = ((cpp_function_code)(&kif_variable_to_stella_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-VARIABLE-DECLARATION?", "OBJECT", "(DEFUN (KIF-VARIABLE-DECLARATION? BOOLEAN) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&kif_variable_declarationP));
            }
            { Method_Slot* method = define_method_from_stringified_source("LISTIFY-KIF-VARIABLE-DECLARATIONS", "OBJECT", "(DEFUN (LISTIFY-KIF-VARIABLE-DECLARATIONS CONS) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&listify_kif_variable_declarations));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-VARIABLE-DECLARATION-TO-STELLA", "OBJECT", "(DEFUN (KIF-VARIABLE-DECLARATION-TO-STELLA CONS) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&kif_variable_declaration_to_stella));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-VARIABLE-DECLARATIONS-TO-STELLA", "CONS", "(DEFUN (KIF-VARIABLE-DECLARATIONS-TO-STELLA CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&kif_variable_declarations_to_stella));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-THE-TO-STELLA-THE-ONLY", "CONS", "(DEFUN (KIF-THE-TO-STELLA-THE-ONLY CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&kif_the_to_stella_the_only));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-SETOFALL-TO-STELLA-SETOFALL", "CONS", "(DEFUN (KIF-SETOFALL-TO-STELLA-SETOFALL CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&kif_setofall_to_stella_setofall));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-KAPPA-TO-STELLA-KAPPA", "CONS", "(DEFUN (KIF-KAPPA-TO-STELLA-KAPPA CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&kif_kappa_to_stella_kappa));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-IMPLIES-TO-STELLA-IMPLIES", "CONS", "(DEFUN (KIF-IMPLIES-TO-STELLA-IMPLIES CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&kif_implies_to_stella_implies));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-EXISTS-TO-STELLA-EXISTS", "CONS", "(DEFUN (KIF-EXISTS-TO-STELLA-EXISTS CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&kif_exists_to_stella_exists));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-FORALL-TO-STELLA-FORALL", "CONS", "(DEFUN (KIF-FORALL-TO-STELLA-FORALL CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&kif_forall_to_stella_forall));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-PREDICATE-TO-STELLA-PREDICATE", "CONS", "(DEFUN (KIF-PREDICATE-TO-STELLA-PREDICATE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&kif_predicate_to_stella_predicate));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-OPERATOR-TO-INTERNAL-STELLA", "SYMBOL", "(DEFUN (KIF-OPERATOR-TO-INTERNAL-STELLA SYMBOL) ((OPERATOR SYMBOL)))");

              method->function_code = ((cpp_function_code)(&kif_operator_to_internal_stella));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERNAL-STELLA-OPERATOR-TO-KIF", "SYMBOL", "(DEFUN (INTERNAL-STELLA-OPERATOR-TO-KIF SYMBOL) ((OPERATOR SYMBOL)))");

              method->function_code = ((cpp_function_code)(&internal_stella_operator_to_kif));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHANGE-KIF-EXPRESSIONS-TO-STELLA-EXPRESSIONS", "CONS", "(DEFUN CHANGE-KIF-EXPRESSIONS-TO-STELLA-EXPRESSIONS ((EXPRESSIONS CONS) (TERM? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&change_kif_expressions_to_stella_expressions));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-SENTENCE-TO-UNTYPED-STELLA-SENTENCE", "OBJECT", "(DEFUN (KIF-SENTENCE-TO-UNTYPED-STELLA-SENTENCE OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&kif_sentence_to_untyped_stella_sentence));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-TERM-TO-UNTYPED-STELLA-TERM", "OBJECT", "(DEFUN (KIF-TERM-TO-UNTYPED-STELLA-TERM OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&kif_term_to_untyped_stella_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("KIF-EXPRESSION-TO-UNTYPED-STELLA-EXPRESSION", "OBJECT", "(DEFUN (KIF-EXPRESSION-TO-UNTYPED-STELLA-EXPRESSION OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&kif_expression_to_untyped_stella_expression));
            }
            { Method_Slot* method = define_method_from_stringified_source("TOKEN?", "OBJECT", "(DEFUN (TOKEN? BOOLEAN) ((OBJECT OBJECT)))");

              method->function_code = ((cpp_function_code)(&tokenP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTRODUCE-VARIABLE-TOKEN", "SYMBOL", "(DEFUN (INTRODUCE-VARIABLE-TOKEN VARIABLE-TOKEN) ((SYMBOL SYMBOL) (TYPETREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&introduce_variable_token));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-VARIABLE-TOKEN", "SYMBOL", "(DEFUN (FIND-VARIABLE-TOKEN VARIABLE-TOKEN) ((SYMBOL SYMBOL)))");

              method->function_code = ((cpp_function_code)(&find_variable_token));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-TOKEN-TABLES", NULL, "(DEFUN CLEAR-TOKEN-TABLES ())");

              method->function_code = ((cpp_function_code)(&clear_token_tables));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-TERM-CLASS", "OBJECT", "(DEFUN (COMPUTE-TERM-CLASS CLASS) ((TERM OBJECT)))");

              method->function_code = ((cpp_function_code)(&compute_term_class));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-TERM-SLOT", "CONS", "(DEFUN (COMPUTE-TERM-SLOT SLOT) ((TERM CONS)))");

              method->function_code = ((cpp_function_code)(&compute_term_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBSTITUTE-TOKENS-INTO-TERMS", "CONS", "(DEFUN SUBSTITUTE-TOKENS-INTO-TERMS ((TERMLIST CONS)))");

              method->function_code = ((cpp_function_code)(&substitute_tokens_into_terms));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBSTITUTE-TOKENS-INTO-VARIABLE-DECLARATIONS", "CONS", "(DEFUN SUBSTITUTE-TOKENS-INTO-VARIABLE-DECLARATIONS ((DECLORDECLS CONS)))");

              method->function_code = ((cpp_function_code)(&substitute_tokens_into_variable_declarations));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP-TOKENS-IN-DECLARATIONS", "CONS", "(DEFUN POP-TOKENS-IN-DECLARATIONS ((DECLORDECLS CONS)))");

              method->function_code = ((cpp_function_code)(&pop_tokens_in_declarations));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBSTITUTE-IN-VARIABLE-TOKENS", "CONS", "(DEFUN SUBSTITUTE-IN-VARIABLE-TOKENS ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&substitute_in_variable_tokens));
            }
            { Method_Slot* method = define_method_from_stringified_source("PUSH-VISIBLE-TOKENS", "CONS", "(DEFUN PUSH-VISIBLE-TOKENS ((DECLORDECLS CONS)))");

              method->function_code = ((cpp_function_code)(&push_visible_tokens));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP-VISIBLE-TOKENS", "CONS", "(DEFUN POP-VISIBLE-TOKENS ((DECLORDECLS CONS)))");

              method->function_code = ((cpp_function_code)(&pop_visible_tokens));
            }
            { Method_Slot* method = define_method_from_stringified_source("BLOCK-VISIBLE-TOKENS", NULL, "(DEFUN BLOCK-VISIBLE-TOKENS ())");

              method->function_code = ((cpp_function_code)(&block_visible_tokens));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNBLOCK-VISIBLE-TOKENS", NULL, "(DEFUN UNBLOCK-VISIBLE-TOKENS ())");

              method->function_code = ((cpp_function_code)(&unblock_visible_tokens));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-TOKENS-BLOCKED?", NULL, "(DEFUN (ALL-TOKENS-BLOCKED? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&all_tokens_blockedP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TOKEN-IS-VISIBLE?", "VARIABLE-TOKEN", "(DEFUN (TOKEN-IS-VISIBLE? BOOLEAN) ((TOKEN VARIABLE-TOKEN)))");

              method->function_code = ((cpp_function_code)(&token_is_visibleP));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPDATE-TOKEN-TYPE", "VARIABLE-TOKEN", "(DEFUN UPDATE-TOKEN-TYPE ((TOKEN VARIABLE-TOKEN) (TYPE TYPE)))");

              method->function_code = ((cpp_function_code)(&update_token_type));
            }
            { Method_Slot* method = define_method_from_stringified_source("INFER-VARIABLE-TYPES-WITHIN-TERMS", "CONS", "(DEFUN INFER-VARIABLE-TYPES-WITHIN-TERMS ((TERMLIST CONS)))");

              method->function_code = ((cpp_function_code)(&infer_variable_types_within_terms));
            }
            { Method_Slot* method = define_method_from_stringified_source("INFER-TYPES-IN-PREDICATION", "CONS", "(DEFUN INFER-TYPES-IN-PREDICATION ((PREDICATION CONS)))");

              method->function_code = ((cpp_function_code)(&infer_types_in_predication));
            }
            { Method_Slot* method = define_method_from_stringified_source("INFER-TYPES-IN-ISA-TERM", "CONS", "(DEFUN INFER-TYPES-IN-ISA-TERM ((ISATERM CONS)))");

              method->function_code = ((cpp_function_code)(&infer_types_in_isa_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("INFER-TYPES-IN-IN-TERM", "CONS", "(DEFUN INFER-TYPES-IN-IN-TERM ((INTERM CONS)))");

              method->function_code = ((cpp_function_code)(&infer_types_in_in_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-INFER-EQUAL-TERMS", "OBJECT", "(DEFUN HELP-INFER-EQUAL-TERMS ((TERM1 OBJECT) (TERM2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&help_infer_equal_terms));
            }
            { Method_Slot* method = define_method_from_stringified_source("INFER-TYPES-IN-EQUAL-TERM", "CONS", "(DEFUN INFER-TYPES-IN-EQUAL-TERM ((EQTERM CONS)))");

              method->function_code = ((cpp_function_code)(&infer_types_in_equal_term));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-INFER-VARIABLE-TYPES", "OBJECT", "(DEFUN HELP-INFER-VARIABLE-TYPES ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&help_infer_variable_types));
            }
            { Method_Slot* method = define_method_from_stringified_source("INFER-VARIABLE-TYPES", "CONS", "(DEFUN INFER-VARIABLE-TYPES ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&infer_variable_types));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBSTITUTE-OUT-VARIABLE-TOKENS", "OBJECT", "(DEFUN (SUBSTITUTE-OUT-VARIABLE-TOKENS OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&substitute_out_variable_tokens));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNTYPED-STELLA-TREE-TO-TYPED-STELLA", "CONS", "(DEFUN UNTYPED-STELLA-TREE-TO-TYPED-STELLA ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&untyped_stella_tree_to_typed_stella));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONVERT-TO-PREFIX-PROPOSITION-TREE", "OBJECT", "(DEFUN (CONVERT-TO-PREFIX-PROPOSITION-TREE OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&convert_to_prefix_proposition_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("INFIX-TO-PREFIX-QUANTIFICATION-TREE", "CONS", "(DEFUN (INFIX-TO-PREFIX-QUANTIFICATION-TREE CONS) ((TREE CONS)))");

              method->function_code = ((cpp_function_code)(&infix_to_prefix_quantification_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("ACCESS-PREFIX-QUANTIFICATION-CLAUSE", "CONS", "(DEFUN (ACCESS-PREFIX-QUANTIFICATION-CLAUSE OBJECT) ((PREFIXQUANTIFICATIONTREE CONS) (CLAUSENAME SYMBOL) (EXTRACT? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&access_prefix_quantification_clause));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-WHERE-CLAUSE", "CONS", "(DEFUN (EXTRACT-WHERE-CLAUSE OBJECT) ((PREFIXQUANTIFICATIONTREE CONS)))");

              method->function_code = ((cpp_function_code)(&extract_where_clause));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-ALWAYS-CLAUSE", "CONS", "(DEFUN (EXTRACT-ALWAYS-CLAUSE OBJECT) ((PREFIXQUANTIFICATIONTREE CONS)))");

              method->function_code = ((cpp_function_code)(&extract_always_clause));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-WHERE-CLAUSE", "CONS", "(DEFUN (LOOKUP-WHERE-CLAUSE OBJECT) ((PREFIXQUANTIFICATIONTREE CONS)))");

              method->function_code = ((cpp_function_code)(&lookup_where_clause));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-ALWAYS-CLAUSE", "CONS", "(DEFUN (LOOKUP-ALWAYS-CLAUSE OBJECT) ((PREFIXQUANTIFICATIONTREE CONS)))");

              method->function_code = ((cpp_function_code)(&lookup_always_clause));
            }
            { Method_Slot* method = define_method_from_stringified_source("STANDARDIZE-LOGICAL-PARSE-TREE", "OBJECT", "(DEFUN (STANDARDIZE-LOGICAL-PARSE-TREE OBJECT) ((TREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&standardize_logical_parse_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("IN-DIALECT", "OBJECT", "(DEFUN (IN-DIALECT KEYWORD) ((DIALECT NAME)) :DOCUMENTATION \"Change the current logic dialect to `dialect'.\nCurrently supported dialects are `KIF', `STELLA', and `PREFIX-STELLA'.\nThe STELLA dialects are not recommended for the construction of knowledge\nbases, they are mainly used internally by PowerLoom.\" :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE)");

              method->function_code = ((cpp_function_code)(&in_dialect));
            }
            define_method_from_stringified_source("STARTUP-KIF-IN", NULL, "(DEFUN STARTUP-KIF-IN ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL KIF-OPERATOR-TO-INTERNAL-STELLA-TABLE (PROPERTY-LIST OF SYMBOL SYMBOL) (NEW PROPERTY-LIST :THE-PLIST (BQUOTE (+ PLUS - MINUS * TIMES |/| DIVIDE > GREATER-THAN? >= GREATER-OR-EQUAL? < LESS-THAN? =< LESS-OR-EQUAL? SUBSET SUBSET-OF))) :DOCUMENTATION \"Used to encode/decode KIF operators to the internal\nversion of Stella operators.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *VARIABLE-TOKENS* (LIST OF VARIABLE-TOKEN) (NEW LIST) :DOCUMENTATION \"List of all variable tokens.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *VARIABLE-TOKEN-STACK* (KEY-VALUE-LIST OF SYMBOL VARIABLE-TOKEN) (NEW KEY-VALUE-LIST) :DOCUMENTATION \"Stack of variable tokens visible (during parsing) from the\ncurrent scope.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *TYPEBECAMENARROWER?* BOOLEAN :DOCUMENTATION \"Used by 'infer-variable-types?' to record occurrence of\ntype narrowing.\")");
            { Global_Variable* global = SYM_KIF_IN_oTYPEBECAMENARROWERpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OtypebecamenarrowerPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OtypebecamenarrowerPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *VISIBLE-TOKEN-STACK* (LIST OF VARIABLE-TOKEN) (NEW LIST) :DOCUMENTATION \"Used by 'infer-variable-types?' to determine which\nvariables can be narrowed by a current predication.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL BLOCKING-TOKEN VARIABLE-TOKEN (NEW VARIABLE-TOKEN))");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *LOGIC-DIALECT* KEYWORD :KIF :DOCUMENTATION \"Indicates the current dialect of logic used to phrase\nqueries, assertions, and definitions.\")");
            { Global_Variable* global = SYM_KIF_IN_oLOGIC_DIALECTo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Ologic_dialectO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Ologic_dialectO));
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

