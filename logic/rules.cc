// rules.cc

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

Keyword* KWD_RULES_OR = NULL;

Keyword* KWD_RULES_AND = NULL;

Keyword* KWD_RULES_EXISTS = NULL;

Keyword* KWD_RULES_IN = NULL;

Surrogate* SGT_RULES_SURROGATE = NULL;

Surrogate* SGT_RULES_SKOLEM = NULL;

Keyword* KWD_RULES_PREDICATE = NULL;

Keyword* KWD_RULES_FUNCTION = NULL;

Keyword* KWD_RULES_NOT = NULL;

Surrogate* SGT_RULES_DESCRIPTION = NULL;

Symbol* SYM_RULES_IMPLIES = NULL;

Symbol* SYM_RULES_SATELLITE_PROPOSITIONS = NULL;

Symbol* SYM_RULES_MASTER_PROPOSITION = NULL;

Keyword* KWD_RULES_HEAD = NULL;

Keyword* KWD_RULES_TAIL = NULL;

Symbol* SYM_RULES_EXISTS = NULL;

Symbol* SYM_RULES_IO_VARIABLES = NULL;

Keyword* KWD_RULES_ASSERT_TRUE = NULL;

Symbol* SYM_RULES_DESCRIPTION = NULL;

Keyword* KWD_RULES_IMPLIES = NULL;

Symbol* SYM_RULES_COMPLEMENT_DESCRIPTION = NULL;

Surrogate* SGT_RULES_SLOT = NULL;

Surrogate* SGT_RULES_PROPOSITION = NULL;

Symbol* SYM_RULES_SURROGATE_VALUE_INVERSE = NULL;

Symbol* SYM_RULES_ESTIMATED_CARDINALITY = NULL;

List* find_rule_tails(Proposition* proposition, Vector* variables, boolean& return1) {
  { List* resultlist = new_list();
    boolean equivalentP = FALSE;

    { Keyword* test_value_001 = proposition->kind;

      if (test_value_001 == KWD_RULES_OR) {
        { Object* arg = NULL;
          Vector* vector_001 = proposition->arguments;
          int index_001 = 0;
          int length_001 = vector_001->length();

          while (index_001 < length_001) {
            {
              arg = vector_001->nth(index_001);
              index_001 = index_001 + 1;
            }
            collect_matching_rule_goal(((Proposition*)(arg)), variables, resultlist);
          }
        }
      }
      else {
        collect_matching_rule_goal(proposition, variables, resultlist);
        equivalentP = resultlist->length() == 1;
      }
    }
    { List* return_temp = resultlist;

      return1 = equivalentP;
      return (return_temp);
    }
  }
}

List* find_rule_heads(Proposition* proposition, Vector* variables, boolean& return1) {
  { List* resultlist = new_list();
    boolean equivalentP = FALSE;

    { Keyword* test_value_001 = proposition->kind;

      if (test_value_001 == KWD_RULES_AND) {
        { int nonvariabletypescounter = 0;

          { Object* arg = NULL;
            Vector* vector_001 = proposition->arguments;
            int index_001 = 0;
            int length_001 = vector_001->length();

            while (index_001 < length_001) {
              {
                arg = vector_001->nth(index_001);
                index_001 = index_001 + 1;
              }
              if (!((Proposition*)(arg))->variable_typeP_reader()) {
                collect_matching_rule_goal(((Proposition*)(arg)), variables, resultlist);
                nonvariabletypescounter = nonvariabletypescounter + 1;
              }
            }
          }
          equivalentP = (nonvariabletypescounter == 1) &&
              (!resultlist->emptyP());
        }
      }
      else if (test_value_001 == KWD_RULES_EXISTS) {
        resultlist->free();
        return (find_rule_heads(((Proposition*)(proposition->arguments->first())), variables, return1));
      }
      else {
        collect_matching_rule_goal(proposition, variables, resultlist);
        equivalentP = resultlist->length() == 1;
      }
    }
    { List* return_temp = resultlist;

      return1 = equivalentP;
      return (return_temp);
    }
  }
}

void collect_matching_rule_goal(Proposition* goal, Vector* variables, List* collection) {
  { Keyword* test_value_001 = goal->kind;

    if (test_value_001 == KWD_RULES_IN) {
      { Object* firstarg = goal->arguments->first();
        Object* secondarg = goal->arguments->second();

        if ((firstarg == variables->first()) &&
            isaP(secondarg, SGT_RULES_SURROGATE)) {
          collection->push(cons_list(2, ((Surrogate*)(secondarg))->get_description(), variables));
        }
        else if (FALSE &&
            ((firstarg == variables->second()) &&
             isaP(secondarg, SGT_RULES_SKOLEM))) {
          { Proposition* functionproposition = ((Skolem*)(secondarg))->defining_proposition;

            if ((functionproposition != NULL) &&
                (eqlP(secondarg, functionproposition->arguments->second()) &&
                 ((variables->first() == functionproposition->arguments->first()) &&
                  isaP(functionproposition->renamed_Operator, SGT_RULES_SURROGATE)))) {
            }
          }
        }
      }
    }
    else if ((test_value_001 == KWD_RULES_PREDICATE) ||
        (test_value_001 == KWD_RULES_FUNCTION)) {
      { boolean test_value_002 = FALSE;

        test_value_002 = isaP(goal->renamed_Operator, SGT_RULES_SURROGATE);
        if (test_value_002) {
          { boolean alwaysP_001 = TRUE;

            { Object* a = NULL;
              Vector* vector_001 = goal->arguments;
              int index_001 = 0;
              int length_001 = vector_001->length();

              while (index_001 < length_001) {
                {
                  a = vector_001->nth(index_001);
                  index_001 = index_001 + 1;
                }
                if (!variables->memberP(a)) {
                  alwaysP_001 = FALSE;
                  break;
                }
              }
            }
            test_value_002 = alwaysP_001;
          }
        }
        if (test_value_002) {
          collection->push(cons_list(2, ((Surrogate*)(goal->renamed_Operator))->get_description(), goal->arguments));
        }
      }
    }
    else if (test_value_001 == KWD_RULES_NOT) {
      { Object* complementofgoal = goal->arguments->first();
        List* templist = new_list();
        Cons* matchingpair = NULL;

        collect_matching_rule_goal(((Proposition*)(complementofgoal)), variables, templist);
        matchingpair = ((Cons*)(templist->first()));
        templist->free();
        if (matchingpair != NULL) {
          matchingpair->first_setter(get_complement_description(((Description*)(matchingpair->first()))));
          collection->push(matchingpair);
        }
      }
    }
    else if (test_value_001 == KWD_RULES_AND) {
      { Proposition* singleatomicgoal = NULL;

        { Object* g = NULL;
          Vector* vector_002 = goal->arguments;
          int index_002 = 0;
          int length_002 = vector_002->length();

          while (index_002 < length_002) {
            {
              g = vector_002->nth(index_002);
              index_002 = index_002 + 1;
            }
            if (!((Proposition*)(g))->variable_typeP_reader()) {
              if (singleatomicgoal == NULL) {
                singleatomicgoal = ((Proposition*)(g));
              }
              else {
                return;
              }
            }
          }
        }
        if (singleatomicgoal != NULL) {
          collect_matching_rule_goal(singleatomicgoal, variables, collection);
        }
      }
    }
    else {
    }
  }
}

Object* maybe_substitute_surrogate_argument(Object* arg1, Object* arg2) {
  if (skolemP(arg2) ||
      description_modeP()) {
    { Object* arg1_001 = arg1;

      if (taxonomy_isaP(arg1, SGT_RULES_DESCRIPTION)) {
        { Description* arg1 = NULL;

          arg1 = ((Description*)(arg1_001));
          if (arg1->description_surrogate() != NULL) {
            return (arg1->description_surrogate());
          }
        }
      }
      else {
      }
    }
  }
  return (arg1);
}

Proposition* finish_building_implies_proposition(Object* head, Object* tail, Proposition* forallprop, boolean replacesforallP) {
  { Proposition* impliesprop = create_proposition(SYM_RULES_IMPLIES, 2);

    impliesprop->arguments->nth_setter(maybe_substitute_surrogate_argument(tail, head), 0);
    impliesprop->arguments->nth_setter(maybe_substitute_surrogate_argument(head, tail), 1);
    if (replacesforallP) {
      return (impliesprop);
    }
    { Proposition* duplicate = fasten_down_proposition(impliesprop);

      if (!(duplicate == impliesprop)) {
        assign_truth_value(duplicate, TRUE);
        return (duplicate);
      }
    }
    assign_truth_value(impliesprop, TRUE);
    if (forallprop->satellite_propositions_reader()->emptyP()) {
      set_dynamic_slot_value(forallprop, SYM_RULES_SATELLITE_PROPOSITIONS, new_list(), NULL);
    }
    forallprop->satellite_propositions_reader()->insert(impliesprop);
    set_dynamic_slot_value(impliesprop, SYM_RULES_MASTER_PROPOSITION, forallprop, NULL);
    return (forallprop);
  }
}

Object* construct_description_from_forall_proposition(Proposition* forallprop, Keyword* headortail, Vector* variables, boolean destructiveP) {
  { Description* description = new_description();
    Vector* iovariables = new_vector(variables->length());
    Cons* existentialvariables = NIL;

    { int i = NULL_INTEGER;
      Object* vbl = NULL;
      Vector* vector_001 = variables;
      int index_001 = 0;
      int length_001 = vector_001->length();
      int iter_001 = 0;

      while (index_001 < length_001) {
        {
          vbl = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        iovariables->nth_setter(((Pattern_Variable*)(vbl)), i);
      }
    }
    description->io_variables = iovariables;
    { Pattern_Variable* v = NULL;
      Vector* vector_002 = iovariables;
      int index_002 = 0;
      int length_002 = vector_002->length();

      while (index_002 < length_002) {
        {
          v = ((Pattern_Variable*)(vector_002->nth(index_002)));
          index_002 = index_002 + 1;
        }
        if (!variables->memberP(v)) {
          existentialvariables = cons(v, existentialvariables);
        }
      }
    }
    if (headortail == KWD_RULES_HEAD) {
      description->proposition = ((Proposition*)(forallprop->arguments->nth(1)));
      if (destructiveP) {
        forallprop->arguments->nth_setter(NULL, 1);
      }
    }
    else if (headortail == KWD_RULES_TAIL) {
      description->proposition = ((Proposition*)(forallprop->arguments->nth(0)));
      if (destructiveP) {
        forallprop->arguments->nth_setter(NULL, 0);
      }
    }
    else {
      cerr << "`" << headortail << "'" << " is not a valid case option";
    }
    compute_internal_variables(description);
    if (!destructiveP) {
      { Description* copy = copy_description(description, NULL);

        description->io_variables->free();
        description->internal_variables->free();
        description->io_variables = NULL;
        description->internal_variables = NULL;
        description->proposition = NULL;
        description = copy;
      }
    }
    if (!existentialvariables->emptyP()) {
      { Proposition* existsprop = create_proposition(SYM_RULES_EXISTS, 1);

        existsprop->kind = KWD_RULES_EXISTS;
        existsprop->arguments->nth_setter(description->proposition, 0);
        set_dynamic_slot_value(existsprop, SYM_RULES_IO_VARIABLES, copy_cons_list_to_variables_vector(existentialvariables), NULL);
        description->proposition = existsprop;
      }
    }
    return (finish_building_description(description, TRUE));
  }
}

Proposition* derive_one_implies_proposition(Cons* headpair, Cons* tailpair, Proposition* forallprop, boolean replacesforallP) {
  { Description* head = ((Description*)(headpair->first()));
    Vector* headarguments = ((Vector*)(headpair->second()));
    Description* tail = ((Description*)(tailpair->first()));
    Vector* tailarguments = ((Vector*)(tailpair->second()));

    free_cons_list(headpair);
    free_cons_list(tailpair);
    { boolean test_value_001 = FALSE;

      test_value_001 = head != NULL;
      if (test_value_001) {
        test_value_001 = tail != NULL;
        if (test_value_001) {
          if (!(headarguments->length() == tailarguments->length())) {
            test_value_001 = TRUE;
          }
          else {
            {
              { boolean alwaysP_001 = TRUE;

                { Object* vt = NULL;
                  Object* vh = NULL;
                  Vector* vector_001 = headarguments;
                  int index_001 = 0;
                  int length_001 = vector_001->length();
                  Vector* vector_002 = tailarguments;
                  int index_002 = 0;
                  int length_002 = vector_002->length();

                  while ((index_001 < length_001) &&
                      (index_002 < length_002)) {
                    {
                      vh = vector_001->nth(index_001);
                      index_001 = index_001 + 1;
                    }
                    {
                      vt = vector_002->nth(index_002);
                      index_002 = index_002 + 1;
                    }
                    if (!eqlP(vh, vt)) {
                      alwaysP_001 = FALSE;
                      break;
                    }
                  }
                }
                test_value_001 = alwaysP_001;
              }
              test_value_001 = !test_value_001;
            }
          }
        }
      }
      if (test_value_001) {
        tail = NULL;
      }
    }
    if (head == NULL) {
      head = ((Description*)(construct_description_from_forall_proposition(forallprop, KWD_RULES_HEAD, tailarguments, replacesforallP)));
    }
    if (tail == NULL) {
      tail = ((Description*)(construct_description_from_forall_proposition(forallprop, KWD_RULES_TAIL, headarguments, replacesforallP)));
    }
    return (finish_building_implies_proposition(head, tail, forallprop, replacesforallP));
  }
}

Proposition* derive_implies_propositions(Proposition* forallprop, Keyword* updatemode) {
  { Proposition* antecedentprop = ((Proposition*)(forallprop->arguments->nth(0)));
    Proposition* consequentprop = ((Proposition*)(forallprop->arguments->nth(1)));
    List* heads = NULL;
    List* tails = NULL;
    boolean equivalentheadP = FALSE;
    boolean equivalenttailP = FALSE;
    Proposition* result = forallprop;

    heads = find_rule_heads(consequentprop, ((Vector*)(dynamic_slot_value(forallprop, SYM_RULES_IO_VARIABLES, NULL))), equivalentheadP);
    tails = find_rule_tails(antecedentprop, ((Vector*)(dynamic_slot_value(forallprop, SYM_RULES_IO_VARIABLES, NULL))), equivalenttailP);
    if (equivalentheadP) {
      result = derive_one_implies_proposition(((Cons*)(heads->first())), (equivalenttailP ? ((Cons*)(((Cons*)(tails->first())))) : ((Cons*)(NIL))), forallprop, TRUE);
    }
    else if (equivalenttailP) {
      result = derive_one_implies_proposition(NIL, ((Cons*)(tails->first())), forallprop, TRUE);
    }
    else if (updatemode == KWD_RULES_ASSERT_TRUE) {
      { Cons* h = NIL;
        Cons* iter_001 = heads->the_cons_list;

        while (!nilP(iter_001)) {
          {
            h = ((Cons*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          derive_one_implies_proposition(h, NIL, forallprop, FALSE);
        }
      }
      { Cons* t = NIL;
        Cons* iter_002 = tails->the_cons_list;

        while (!nilP(iter_002)) {
          {
            t = ((Cons*)(iter_002->value));
            iter_002 = iter_002->rest;
          }
          derive_one_implies_proposition(NIL, t, forallprop, FALSE);
        }
      }
    }
    if ((result == forallprop) &&
        ((!equivalentheadP) &&
         ((!equivalenttailP) &&
          ((forallprop->satellite_propositions_reader()->length() < 2) &&
           ((updatemode == KWD_RULES_ASSERT_TRUE) &&
            (!description_modeP())))))) {
      cerr << "PowerLoom can't index the rule:" << endl << "   " << "`" << forallprop << "'" << endl << "   because neither its head nor its tail matches a primitive relation.";
    }
    if (!(result == forallprop)) {
      destroy_proposition(forallprop);
    }
    return (result);
  }
}

List* get_rules(Slot* slot) {
  if (slot == NULL) {
    return (NIL_LIST);
  }
  { Description* description = ((Description*)(dynamic_slot_value(slot, SYM_RULES_DESCRIPTION, NULL)));
    List* rules = list(0);

    if (description != NULL) {
      { Proposition* p = NULL;
        Cons* iter_001 = description->dependent_propositions->the_cons_list;

        while (!nilP(iter_001)) {
          {
            p = ((Proposition*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          if (p->kind == KWD_RULES_IMPLIES) {
            rules->push(p);
          }
        }
      }
      description = ((Description*)(dynamic_slot_value(description, SYM_RULES_COMPLEMENT_DESCRIPTION, NULL)));
      if (description != NULL) {
        { Proposition* p = NULL;
          Cons* iter_002 = description->dependent_propositions->the_cons_list;

          while (!nilP(iter_002)) {
            {
              p = ((Proposition*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            if (p->kind == KWD_RULES_IMPLIES) {
              rules->push(p);
            }
          }
        }
      }
    }
    return (rules);
  }
}

List* drop_rules(Slot* slot) {
  { List* rules = get_rules(slot);

    { Proposition* r = NULL;
      Cons* iter_001 = rules->the_cons_list;

      while (!nilP(iter_001)) {
        {
          r = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        destroy_proposition(r);
      }
    }
    return (rules);
  }
}

void print_rules(char* slotname) {
  { Object* slot = string_get_object(slotname, SGT_RULES_SLOT);

    if ((slot == NULL) ||
        (!isaP(slot, SGT_RULES_SLOT))) {
      cout << "Can't find a slot named " << slotname << endl;
      return;
    }
    { Proposition* rule = NULL;
      Cons* iter_001 = get_rules(((Slot*)(slot)))->the_cons_list;

      while (!nilP(iter_001)) {
        {
          rule = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        cout << rule;
        cout << endl;
      }
    }
  }
}

Proposition* define_rule(char* name, Object* ruletree) {
  { Surrogate* surrogate = intern_surrogate(name);
    Object* oldrule = surrogate->surrogate_value;
    Proposition* newrule = NULL;

    newrule = update_proposition(ruletree, KWD_RULES_ASSERT_TRUE);
    if ((newrule == NULL) ||
        (!isaP(newrule, SGT_RULES_PROPOSITION))) {
      { boolean old_OprintreadablyPO_001 = oPRINTREADABLYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oPRINTREADABLYpo = TRUE;
              cout << "Error in logical expression." << endl;
              cout << "   " << "Oops, bug in defrule prevents rule definition.  Please\n        notify your PowerLoom dealer." << endl;
              cout << "   Error occured while parsing the proposition: " << endl;
              cout << "   " << oPROPOSITIONUNDERCONSTRUCTIONo << endl;
              signal(oTHE_PROPOSITION_ERRORo);
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
    if (oldrule != NULL) {
      { Object* oldrule_001 = oldrule;

        if (taxonomy_isaP(oldrule, SGT_RULES_PROPOSITION)) {
          { Proposition* oldrule = NULL;

            oldrule = ((Proposition*)(oldrule_001));
            if (oldrule == newrule) {
              return (oldrule);
            }
            surrogate->surrogate_value = NULL;
            set_dynamic_slot_value(oldrule, SYM_RULES_SURROGATE_VALUE_INVERSE, NULL, NULL);
            destroy_proposition(oldrule);
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
                  cout << "Error in logical expression." << endl;
                  cout << "   " << "Can't define a rule named " << name << " because another object of type" << endl << "   " << oldrule->primary_type() << " already has that name." << endl << endl;
                  cout << "   Error occured while parsing the proposition: " << endl;
                  cout << "   " << oPROPOSITIONUNDERCONSTRUCTIONo << endl;
                  signal(oTHE_PROPOSITION_ERRORo);
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
          destroy_proposition(newrule);
        }
      }
    }
    surrogate->surrogate_value = newrule;
    set_dynamic_slot_value(newrule, SYM_RULES_SURROGATE_VALUE_INVERSE, surrogate, NULL);
    return (newrule);
  }
}

Proposition* defrule(Object* rulename, Object* rule) {
  // Define (or redefine) a rule (any axiom) named `ruleName'.
  // If an axiom with that name already exists, replace it with the new
  // axiom `rule'.
  {
    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;
      boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      oPENDINGEXCEPTIONHANDLERpo = TRUE;
      if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        { Proposition* return_value_001 = define_rule(coerce_to_string(rulename), coerce_to_tree(rule));

          oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          return (return_value_001);
        }
        oEXCEPTIONo = NULL;
      }
      oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        { Exception* e = oEXCEPTIONo;

          handle_query_exception(e, "defrule");
        }
      }
    }
  }
}

void delete_rule_caches_on_slot(Slot* slot) {
  { Proposition* rule = NULL;
    Cons* iter_001 = get_rules(slot)->the_cons_list;

    while (!nilP(iter_001)) {
      {
        rule = ((Proposition*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      { Object* arg = NULL;
        Vector* vector_001 = rule->arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            arg = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          if (((Description*)(arg))->query_patterns != NULL) {
            { Kv_List_Iterator* it = ((Kv_List_Iterator*)(((Description*)(arg))->query_patterns->allocate_iterator()));

              while (it->nextP()) {
                it->value_setter(NULL);
              }
            }
          }
        }
      }
    }
  }
}

void reset_query_caches() {
  // Zero out all caches managed by the query optimizer,
  // so that it will reoptimize subgoal queries upon next invocation.
  { Slot* slot = NULL;
    Iterator* iter_001 = all_slots(NULL, TRUE);

    while (iter_001->nextP()) {
      {
        slot = ((Slot*)(iter_001->value));
      }
      if (((Description*)(dynamic_slot_value(slot, SYM_RULES_DESCRIPTION, NULL))) != NULL) {
        delete_rule_caches_on_slot(slot);
      }
    }
  }
  { Class* renamed_Class = NULL;
    Iterator* iter_002 = all_classes(NULL, TRUE);

    while (iter_002->nextP()) {
      {
        renamed_Class = ((Class*)(iter_002->value));
      }
      if (((Description*)(dynamic_slot_value(renamed_Class, SYM_RULES_DESCRIPTION, NULL))) != NULL) {
        { Description* description = ((Description*)(dynamic_slot_value(renamed_Class, SYM_RULES_DESCRIPTION, NULL)));

          if (((Integer_Wrapper*)(dynamic_slot_value(description, SYM_RULES_ESTIMATED_CARDINALITY, NULL_INTEGER_WRAPPER)))->wrapper_value != NULL_INTEGER) {
            set_dynamic_slot_value(description, SYM_RULES_ESTIMATED_CARDINALITY, wrap_integer(NULL_INTEGER), NULL_INTEGER_WRAPPER);
          }
          if (description->query_patterns != NULL) {
            { Kv_List_Iterator* it = ((Kv_List_Iterator*)(description->query_patterns->allocate_iterator()));

              while (it->nextP()) {
                it->value_setter(NULL);
              }
            }
          }
        }
      }
    }
  }
}

void startup_rules() {
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
            KWD_RULES_OR = ((Keyword*)(intern_rigid_symbol_wrt_module("OR", NULL, 2)));
            KWD_RULES_AND = ((Keyword*)(intern_rigid_symbol_wrt_module("AND", NULL, 2)));
            KWD_RULES_EXISTS = ((Keyword*)(intern_rigid_symbol_wrt_module("EXISTS", NULL, 2)));
            KWD_RULES_IN = ((Keyword*)(intern_rigid_symbol_wrt_module("IN", NULL, 2)));
            SGT_RULES_SURROGATE = ((Surrogate*)(intern_rigid_symbol_wrt_module("SURROGATE", string_get_module("/STELLA", TRUE), 1)));
            SGT_RULES_SKOLEM = ((Surrogate*)(intern_rigid_symbol_wrt_module("SKOLEM", NULL, 1)));
            KWD_RULES_PREDICATE = ((Keyword*)(intern_rigid_symbol_wrt_module("PREDICATE", NULL, 2)));
            KWD_RULES_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            KWD_RULES_NOT = ((Keyword*)(intern_rigid_symbol_wrt_module("NOT", NULL, 2)));
            SGT_RULES_DESCRIPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 1)));
            SYM_RULES_IMPLIES = ((Symbol*)(intern_rigid_symbol_wrt_module("IMPLIES", NULL, 0)));
            SYM_RULES_SATELLITE_PROPOSITIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("SATELLITE-PROPOSITIONS", NULL, 0)));
            SYM_RULES_MASTER_PROPOSITION = ((Symbol*)(intern_rigid_symbol_wrt_module("MASTER-PROPOSITION", NULL, 0)));
            KWD_RULES_HEAD = ((Keyword*)(intern_rigid_symbol_wrt_module("HEAD", NULL, 2)));
            KWD_RULES_TAIL = ((Keyword*)(intern_rigid_symbol_wrt_module("TAIL", NULL, 2)));
            SYM_RULES_EXISTS = ((Symbol*)(intern_rigid_symbol_wrt_module("EXISTS", string_get_module("/STELLA", TRUE), 0)));
            SYM_RULES_IO_VARIABLES = ((Symbol*)(intern_rigid_symbol_wrt_module("IO-VARIABLES", NULL, 0)));
            KWD_RULES_ASSERT_TRUE = ((Keyword*)(intern_rigid_symbol_wrt_module("ASSERT-TRUE", NULL, 2)));
            SYM_RULES_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 0)));
            KWD_RULES_IMPLIES = ((Keyword*)(intern_rigid_symbol_wrt_module("IMPLIES", NULL, 2)));
            SYM_RULES_COMPLEMENT_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("COMPLEMENT-DESCRIPTION", NULL, 0)));
            SGT_RULES_SLOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("SLOT", string_get_module("/STELLA", TRUE), 1)));
            SGT_RULES_PROPOSITION = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPOSITION", NULL, 1)));
            SYM_RULES_SURROGATE_VALUE_INVERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("SURROGATE-VALUE-INVERSE", NULL, 0)));
            SYM_RULES_ESTIMATED_CARDINALITY = ((Symbol*)(intern_rigid_symbol_wrt_module("ESTIMATED-CARDINALITY", NULL, 0)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("FIND-RULE-TAILS", "PROPOSITION", "(DEFUN (FIND-RULE-TAILS (LIST OF CONS) BOOLEAN) ((PROPOSITION PROPOSITION) (VARIABLES VARIABLES-VECTOR)))");

              method->function_code = ((cpp_function_code)(&find_rule_tails));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-RULE-HEADS", "PROPOSITION", "(DEFUN (FIND-RULE-HEADS LIST BOOLEAN) ((PROPOSITION PROPOSITION) (VARIABLES VARIABLES-VECTOR)))");

              method->function_code = ((cpp_function_code)(&find_rule_heads));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-MATCHING-RULE-GOAL", "PROPOSITION", "(DEFUN COLLECT-MATCHING-RULE-GOAL ((GOAL PROPOSITION) (VARIABLES VARIABLES-VECTOR) (COLLECTION (LIST OF CONS))))");

              method->function_code = ((cpp_function_code)(&collect_matching_rule_goal));
            }
            { Method_Slot* method = define_method_from_stringified_source("MAYBE-SUBSTITUTE-SURROGATE-ARGUMENT", "OBJECT", "(DEFUN (MAYBE-SUBSTITUTE-SURROGATE-ARGUMENT OBJECT) ((ARG1 OBJECT) (ARG2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&maybe_substitute_surrogate_argument));
            }
            { Method_Slot* method = define_method_from_stringified_source("FINISH-BUILDING-IMPLIES-PROPOSITION", "OBJECT", "(DEFUN (FINISH-BUILDING-IMPLIES-PROPOSITION PROPOSITION) ((HEAD OBJECT) (TAIL OBJECT) (FORALLPROP PROPOSITION) (REPLACESFORALL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&finish_building_implies_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONSTRUCT-DESCRIPTION-FROM-FORALL-PROPOSITION", "PROPOSITION", "(DEFUN (CONSTRUCT-DESCRIPTION-FROM-FORALL-PROPOSITION OBJECT) ((FORALLPROP PROPOSITION) (HEADORTAIL KEYWORD) (VARIABLES VECTOR) (DESTRUCTIVE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&construct_description_from_forall_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("DERIVE-ONE-IMPLIES-PROPOSITION", "CONS", "(DEFUN (DERIVE-ONE-IMPLIES-PROPOSITION PROPOSITION) ((HEADPAIR CONS) (TAILPAIR CONS) (FORALLPROP PROPOSITION) (REPLACESFORALL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&derive_one_implies_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("DERIVE-IMPLIES-PROPOSITIONS", "PROPOSITION", "(DEFUN (DERIVE-IMPLIES-PROPOSITIONS PROPOSITION) ((FORALLPROP PROPOSITION) (UPDATEMODE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&derive_implies_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-RULES", "SLOT", "(DEFUN (GET-RULES (LIST OF PROPOSITION)) ((SLOT SLOT)))");

              method->function_code = ((cpp_function_code)(&get_rules));
            }
            { Method_Slot* method = define_method_from_stringified_source("DROP-RULES", "SLOT", "(DEFUN (DROP-RULES (LIST OF PROPOSITION)) ((SLOT SLOT)))");

              method->function_code = ((cpp_function_code)(&drop_rules));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-RULES", "STRING", "(DEFUN PRINT-RULES ((SLOTNAME STRING)))");

              method->function_code = ((cpp_function_code)(&print_rules));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFINE-RULE", "STRING", "(DEFUN (DEFINE-RULE PROPOSITION) ((NAME STRING) (RULETREE OBJECT)))");

              method->function_code = ((cpp_function_code)(&define_rule));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEFRULE", "OBJECT", "(DEFUN (DEFRULE PROPOSITION) ((RULENAME NAME) (RULE PARSE-TREE)) :DOCUMENTATION \"Define (or redefine) a rule (any axiom) named `ruleName'.\nIf an axiom with that name already exists, replace it with the new\naxiom `rule'.\" :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE)");

              method->function_code = ((cpp_function_code)(&defrule));
            }
            { Method_Slot* method = define_method_from_stringified_source("DELETE-RULE-CACHES-ON-SLOT", "SLOT", "(DEFUN DELETE-RULE-CACHES-ON-SLOT ((SLOT SLOT)))");

              method->function_code = ((cpp_function_code)(&delete_rule_caches_on_slot));
            }
            { Method_Slot* method = define_method_from_stringified_source("RESET-QUERY-CACHES", NULL, "(DEFUN RESET-QUERY-CACHES () :DOCUMENTATION \"Zero out all caches managed by the query optimizer,\nso that it will reoptimize subgoal queries upon next invocation.\")");

              method->function_code = ((cpp_function_code)(&reset_query_caches));
            }
            define_method_from_stringified_source("STARTUP-RULES", NULL, "(DEFUN STARTUP-RULES ())");
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

