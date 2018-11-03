// normalize.cc

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

Keyword* KWD_NORMALIZE_AND = NULL;

Keyword* KWD_NORMALIZE_CONSTANT = NULL;

Surrogate* SGT_NORMALIZE_TRUE = NULL;

Symbol* SYM_NORMALIZE_CONSTANT = NULL;

Symbol* SYM_NORMALIZE_AND = NULL;

Keyword* KWD_NORMALIZE_OR = NULL;

Symbol* SYM_NORMALIZE_OR = NULL;

Symbol* SYM_NORMALIZE_IO_VARIABLES = NULL;

Keyword* KWD_NORMALIZE_EXISTS = NULL;

Keyword* KWD_NORMALIZE_NOT = NULL;

Keyword* KWD_NORMALIZE_FUNCTION = NULL;

Keyword* KWD_NORMALIZE_IN = NULL;

Keyword* KWD_NORMALIZE_EQUIVALENT = NULL;

Keyword* KWD_NORMALIZE_PREDICATE = NULL;

Surrogate* SGT_NORMALIZE_FALSE = NULL;

Symbol* SYM_NORMALIZE_EXISTS = NULL;

Surrogate* SGT_NORMALIZE_PROPOSITION = NULL;

Keyword* KWD_NORMALIZE_FORALL = NULL;

Keyword* KWD_NORMALIZE_IMPLIES = NULL;

Symbol* SYM_NORMALIZE_NOT = NULL;

Surrogate* SGT_NORMALIZE_NOT = NULL;

Surrogate* SGT_NORMALIZE_FORALL = NULL;

Surrogate* SGT_NORMALIZE_EXISTS = NULL;

Surrogate* SGT_NORMALIZE_OR = NULL;

Surrogate* SGT_NORMALIZE_AND = NULL;

Keyword* KWD_NORMALIZE_DESCRIPTION = NULL;

void collect_flat_conjuncts(Proposition* self, List* flatconjuncts) {
  { Keyword* test_value_001 = self->kind;

    if (test_value_001 == KWD_NORMALIZE_AND) {
      { Object* arg = NULL;
        Vector* vector_001 = self->arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            arg = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          collect_flat_conjuncts(((Proposition*)(arg)), flatconjuncts);
        }
      }
      self->free();
    }
    else if (test_value_001 == KWD_NORMALIZE_CONSTANT) {
      if (!(self->renamed_Operator == SGT_NORMALIZE_TRUE)) {
        flatconjuncts->push(self);
      }
    }
    else {
      flatconjuncts->push(self);
      self->dependent_propositions->clear();
    }
  }
}

void overlay_with_constant_proposition(Proposition* self, Proposition* constantproposition) {
  { Proposition* overlay = create_proposition(SYM_NORMALIZE_CONSTANT, 0);

    overlay->renamed_Operator = constantproposition->renamed_Operator;
    { Proposition* object_001 = overlay;
      Truth_Value* value_001 = ((Truth_Value*)(access_in_context(constantproposition->truth_value, constantproposition, FALSE)));
      Object* old_value_002 = object_001->truth_value;
      Object* new_value_001 = update_in_context(old_value_002, value_001, object_001, FALSE);

      if (!cs_valueP(old_value_002)) {
        object_001->truth_value = new_value_001;
      }
    }
    overlay_proposition(self, overlay);
  }
}

Proposition* conjoin_propositions(Cons* conjuncts) {
  { List* flatconjuncts = new_list();
    Proposition* result = NULL;

    { Proposition* c = NULL;
      Cons* iter_001 = conjuncts;

      while (!nilP(iter_001)) {
        {
          c = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        collect_flat_conjuncts(c, flatconjuncts);
      }
    }
    flatconjuncts->reverse();
    switch (flatconjuncts->length()) {
      case 0: 
        { Proposition* proposition = create_proposition(SYM_NORMALIZE_CONSTANT, 0);

          overlay_with_constant_proposition(proposition, TRUE_PROPOSITION);
          return (proposition);
        }
      break;
      case 1: 
        return (((Proposition*)(flatconjuncts->first())));
      default:
      break;
    }
    result = create_proposition(SYM_NORMALIZE_AND, flatconjuncts->length());
    result->arguments = copy_list_to_arguments_vector(flatconjuncts);
    { Object* c = NULL;
      Cons* iter_002 = flatconjuncts->the_cons_list;

      while (!nilP(iter_002)) {
        {
          c = iter_002->value;
          iter_002 = iter_002->rest;
        }
        add_dependent_proposition_link(c, result);
      }
    }
    return (result);
  }
}

void collect_flat_disjuncts(Proposition* self, List* flatdisjuncts) {
  { Keyword* test_value_001 = self->kind;

    if (test_value_001 == KWD_NORMALIZE_OR) {
      { Object* arg = NULL;
        Vector* vector_001 = self->arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            arg = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          collect_flat_disjuncts(((Proposition*)(arg)), flatdisjuncts);
        }
      }
      self->free();
    }
    else {
      flatdisjuncts->push(self);
      self->dependent_propositions->clear();
    }
  }
}

Proposition* disjoin_propositions(Cons* disjuncts) {
  { List* flatdisjuncts = new_list();
    Proposition* result = NULL;

    { Proposition* c = NULL;
      Cons* iter_001 = disjuncts;

      while (!nilP(iter_001)) {
        {
          c = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        collect_flat_disjuncts(c, flatdisjuncts);
      }
    }
    flatdisjuncts->reverse();
    if (flatdisjuncts->length() == 1) {
      return (((Proposition*)(flatdisjuncts->first())));
    }
    result = create_proposition(SYM_NORMALIZE_OR, flatdisjuncts->length());
    result->arguments = copy_list_to_arguments_vector(flatdisjuncts);
    { Object* c = NULL;
      Cons* iter_002 = flatdisjuncts->the_cons_list;

      while (!nilP(iter_002)) {
        {
          c = iter_002->value;
          iter_002 = iter_002->rest;
        }
        add_dependent_proposition_link(c, result);
      }
    }
    return (result);
  }
}

void overlay_proposition(Proposition* self, Proposition* overlayingprop) {
  self->kind = overlayingprop->kind;
  self->renamed_Operator = overlayingprop->renamed_Operator;
  { Proposition* object_001 = self;
    Truth_Value* value_001 = ((Truth_Value*)(access_in_context(overlayingprop->truth_value, overlayingprop, FALSE)));
    Object* old_value_002 = object_001->truth_value;
    Object* new_value_001 = update_in_context(old_value_002, value_001, object_001, FALSE);

    if (!cs_valueP(old_value_002)) {
      object_001->truth_value = new_value_001;
    }
  }
  self->arguments->free();
  self->arguments = overlayingprop->arguments;
  { Object* arg = NULL;
    Vector* vector_001 = self->arguments;
    int index_001 = 0;
    int length_001 = vector_001->length();

    while (index_001 < length_001) {
      {
        arg = vector_001->nth(index_001);
        index_001 = index_001 + 1;
      }
      remove_dependent_proposition_link(arg, overlayingprop);
      add_dependent_proposition_link(arg, self);
    }
  }
  if (((Vector*)(dynamic_slot_value(overlayingprop, SYM_NORMALIZE_IO_VARIABLES, NULL))) != NULL) {
    set_dynamic_slot_value(self, SYM_NORMALIZE_IO_VARIABLES, ((Vector*)(dynamic_slot_value(overlayingprop, SYM_NORMALIZE_IO_VARIABLES, NULL))), NULL);
  }
  overlayingprop->free();
}

void normalize_exists_proposition(Proposition* self) {
  { Proposition* whereproposition = ((Proposition*)(self->arguments->nth(0)));

    normalize_proposition(whereproposition);
    if (whereproposition->kind == KWD_NORMALIZE_EXISTS) {
      { Cons* combinedargs = NIL;
        Object* subwhereproposition = whereproposition->arguments->first();

        { Pattern_Variable* vbl = NULL;
          Vector* vector_001 = ((Vector*)(dynamic_slot_value(self, SYM_NORMALIZE_IO_VARIABLES, NULL)));
          int index_001 = 0;
          int length_001 = vector_001->length();
          Cons* collect_001 = NULL;

          while (index_001 < length_001) {
            {
              vbl = ((Pattern_Variable*)(vector_001->nth(index_001)));
              index_001 = index_001 + 1;
            }
            if (collect_001 == NULL) {
              {
                collect_001 = cons(vbl, NIL);
                if (nilP(combinedargs)) {
                  combinedargs = collect_001;
                }
                else {
                  add_cons_to_end_of_cons_list(combinedargs, collect_001);
                }
              }
            }
            else {
              {
                collect_001->rest = cons(vbl, NIL);
                collect_001 = collect_001->rest;
              }
            }
          }
        }
        { Pattern_Variable* vbl = NULL;
          Vector* vector_002 = ((Vector*)(dynamic_slot_value(whereproposition, SYM_NORMALIZE_IO_VARIABLES, NULL)));
          int index_002 = 0;
          int length_002 = vector_002->length();
          Cons* collect_002 = NULL;

          while (index_002 < length_002) {
            {
              vbl = ((Pattern_Variable*)(vector_002->nth(index_002)));
              index_002 = index_002 + 1;
            }
            if (collect_002 == NULL) {
              {
                collect_002 = cons(vbl, NIL);
                if (nilP(combinedargs)) {
                  combinedargs = collect_002;
                }
                else {
                  add_cons_to_end_of_cons_list(combinedargs, collect_002);
                }
              }
            }
            else {
              {
                collect_002->rest = cons(vbl, NIL);
                collect_002 = collect_002->rest;
              }
            }
          }
        }
        ((Vector*)(dynamic_slot_value(self, SYM_NORMALIZE_IO_VARIABLES, NULL)))->free();
        ((Vector*)(dynamic_slot_value(whereproposition, SYM_NORMALIZE_IO_VARIABLES, NULL)))->free();
        set_dynamic_slot_value(self, SYM_NORMALIZE_IO_VARIABLES, copy_cons_list_to_variables_vector(combinedargs), NULL);
        self->arguments->free();
        self->arguments = whereproposition->arguments;
        remove_dependent_proposition_link(subwhereproposition, whereproposition);
        add_dependent_proposition_link(subwhereproposition, self);
      }
    }
  }
}

Proposition* help_migrate_goals(List* negatedgoals, Proposition* antecedent) {
  { Cons* antecedentgoals = NIL;

    { Keyword* test_value_001 = antecedent->kind;

      if (test_value_001 == KWD_NORMALIZE_CONSTANT) {
        if (!(antecedent == TRUE_PROPOSITION)) {
          cerr << "Safety violation: " << "INTERNAL ERROR: Unexpected constant antecedent in `forall'.";
        }
      }
      else if (test_value_001 == KWD_NORMALIZE_AND) {
        { Object* g = NULL;
          Vector* vector_001 = antecedent->arguments;
          int index_001 = 0;
          int length_001 = vector_001->length();

          while (index_001 < length_001) {
            {
              g = vector_001->nth(index_001);
              index_001 = index_001 + 1;
            }
            antecedentgoals = cons(g, antecedentgoals);
            remove_dependent_proposition_link(g, antecedent);
          }
        }
      }
      else {
        antecedentgoals = cons(antecedent, antecedentgoals);
      }
    }
    { Proposition* ng = NULL;
      Cons* iter_001 = negatedgoals->the_cons_list;

      while (!nilP(iter_001)) {
        {
          ng = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        { Object* positivegoal = ng->arguments->first();

          antecedentgoals = cons(positivegoal, antecedentgoals);
          remove_dependent_proposition_link(positivegoal, ng);
        }
      }
    }
    { Proposition* newantecedent = conjoin_propositions(antecedentgoals);

      antecedentgoals->free();
      return (newantecedent);
    }
  }
}

void migrate_consequent_goals_to_antecedent(Proposition* self) {
  { Proposition* antecedent = ((Proposition*)(self->arguments->nth(0)));
    Proposition* consequent = ((Proposition*)(self->arguments->nth(1)));
    List* transferringgoals = new_list();

    { int i = NULL_INTEGER;
      Object* arg = NULL;
      Vector* vector_001 = consequent->arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();
      int iter_001 = 0;

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        { Proposition* conjunct = ((Proposition*)(arg));
          Proposition* goal = NULL;

          if (conjunct->kind == KWD_NORMALIZE_NOT) {
            goal = ((Proposition*)(conjunct->arguments->first()));
            if (goal->kind == KWD_NORMALIZE_FUNCTION) {
              transferringgoals->push(conjunct);
              remove_dependent_proposition_link(conjunct, consequent);
              consequent->arguments->nth_setter(FALSE_PROPOSITION, i);
            }
          }
        }
      }
    }
    if (transferringgoals->non_emptyP()) {
      antecedent = help_migrate_goals(transferringgoals, antecedent);
      self->arguments->nth_setter(antecedent, 0);
      add_dependent_proposition_link(antecedent, self);
    }
    normalize_proposition(antecedent);
    normalize_proposition(consequent);
  }
}

void normalize_forall_proposition(Proposition* self) {
  { Proposition* antecedent = ((Proposition*)(self->arguments->nth(0)));
    Proposition* consequent = ((Proposition*)(self->arguments->nth(1)));

    normalize_proposition(antecedent);
    normalize_proposition(consequent);
    if (!(consequent->kind == KWD_NORMALIZE_OR)) {
      return;
    }
    migrate_consequent_goals_to_antecedent(self);
  }
}

void normalize_not_proposition(Proposition* self) {
  { Proposition* proposition = ((Proposition*)(self->arguments->first()));

    { Keyword* test_value_001 = proposition->kind;

      if ((test_value_001 == KWD_NORMALIZE_IN) ||
          ((test_value_001 == KWD_NORMALIZE_EQUIVALENT) ||
           ((test_value_001 == KWD_NORMALIZE_PREDICATE) ||
            (test_value_001 == KWD_NORMALIZE_FUNCTION)))) {
        normalize_proposition(proposition);
      }
      else if (test_value_001 == KWD_NORMALIZE_CONSTANT) {
        if (proposition->renamed_Operator == SGT_NORMALIZE_TRUE) {
          overlay_with_constant_proposition(self, FALSE_PROPOSITION);
        }
        else if (proposition->renamed_Operator == SGT_NORMALIZE_FALSE) {
          overlay_with_constant_proposition(self, TRUE_PROPOSITION);
        }
        else {
        }
      }
      else {
        invert_proposition(proposition);
        overlay_proposition(self, proposition);
      }
    }
  }
}

void normalize_and_proposition(Proposition* self) {
  { Cons* existprops = NIL;
    Cons* otherprops = NIL;
    boolean conjoinP = FALSE;
    Cons* existsvariables = NIL;

    { Object* arg = NULL;
      Vector* vector_001 = self->arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        { Proposition* conjunct = ((Proposition*)(arg));

          normalize_proposition(conjunct);
          { Keyword* test_value_001 = conjunct->kind;

            if (test_value_001 == KWD_NORMALIZE_EXISTS) {
              existprops = cons(conjunct, existprops);
              conjoinP = TRUE;
            }
            else if (test_value_001 == KWD_NORMALIZE_AND) {
              otherprops = cons(conjunct, otherprops);
              conjoinP = TRUE;
            }
            else if (test_value_001 == KWD_NORMALIZE_CONSTANT) {
              if (conjunct->renamed_Operator == SGT_NORMALIZE_TRUE) {
                conjoinP = TRUE;
                otherprops = cons(conjunct, otherprops);
              }
              else if (conjunct->renamed_Operator == SGT_NORMALIZE_FALSE) {
                overlay_with_constant_proposition(self, FALSE_PROPOSITION);
                return;
              }
            }
            else {
              otherprops = cons(conjunct, otherprops);
            }
          }
        }
      }
    }
    { Proposition* e = NULL;
      Cons* iter_001 = existprops;

      while (!nilP(iter_001)) {
        {
          e = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        { Pattern_Variable* v = NULL;
          Vector* vector_002 = ((Vector*)(dynamic_slot_value(e, SYM_NORMALIZE_IO_VARIABLES, NULL)));
          int index_002 = 0;
          int length_002 = vector_002->length();
          Cons* collect_001 = NULL;

          while (index_002 < length_002) {
            {
              v = ((Pattern_Variable*)(vector_002->nth(index_002)));
              index_002 = index_002 + 1;
            }
            if (collect_001 == NULL) {
              {
                collect_001 = cons(v, NIL);
                if (nilP(existsvariables)) {
                  existsvariables = collect_001;
                }
                else {
                  add_cons_to_end_of_cons_list(existsvariables, collect_001);
                }
              }
            }
            else {
              {
                collect_001->rest = cons(v, NIL);
                collect_001 = collect_001->rest;
              }
            }
          }
        }
        otherprops = cons(e->arguments->first(), otherprops);
      }
    }
    if (existsvariables->non_emptyP()) {
      { Proposition* existsproposition = create_proposition(SYM_NORMALIZE_EXISTS, 1);

        set_dynamic_slot_value(existsproposition, SYM_NORMALIZE_IO_VARIABLES, copy_cons_list_to_variables_vector(existsvariables), NULL);
        existsproposition->arguments->nth_setter(conjoin_propositions(otherprops), 0);
        overlay_proposition(self, existsproposition);
      }
      free_cons_list(existsvariables);
      free_cons_list(existprops);
      free_cons_list(otherprops);
      return;
    }
    if (conjoinP) {
      overlay_proposition(self, conjoin_propositions(otherprops));
    }
    free_cons_list(otherprops);
  }
}

void normalize_or_proposition(Proposition* self) {
  { Cons* propositions = NIL;
    boolean disjoinP = FALSE;

    { Object* arg = NULL;
      Vector* vector_001 = self->arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        { Proposition* disjunct = ((Proposition*)(arg));

          normalize_proposition(disjunct);
          { Keyword* test_value_001 = disjunct->kind;

            if (test_value_001 == KWD_NORMALIZE_OR) {
              propositions = cons(disjunct, propositions);
              disjoinP = TRUE;
            }
            else if (test_value_001 == KWD_NORMALIZE_CONSTANT) {
              if (disjunct->renamed_Operator == SGT_NORMALIZE_FALSE) {
                disjoinP = TRUE;
              }
              else if (disjunct->renamed_Operator == SGT_NORMALIZE_TRUE) {
                overlay_with_constant_proposition(self, TRUE_PROPOSITION);
                return;
              }
              else {
                propositions = cons(disjunct, propositions);
              }
            }
            else {
              propositions = cons(disjunct, propositions);
            }
          }
        }
      }
    }
    if (disjoinP) {
      overlay_proposition(self, disjoin_propositions(propositions));
    }
    free_cons_list(propositions);
  }
}

void normalize_proposition(Proposition* self) {
  { Keyword* test_value_001 = self->kind;

    if (test_value_001 == KWD_NORMALIZE_AND) {
      normalize_and_proposition(self);
    }
    else if (test_value_001 == KWD_NORMALIZE_OR) {
      normalize_or_proposition(self);
    }
    else if (test_value_001 == KWD_NORMALIZE_NOT) {
      normalize_not_proposition(self);
    }
    else if ((test_value_001 == KWD_NORMALIZE_FUNCTION) ||
        ((test_value_001 == KWD_NORMALIZE_PREDICATE) ||
         (test_value_001 == KWD_NORMALIZE_IN))) {
      { Object* clause = NULL;
        Vector* vector_001 = self->arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            clause = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          if (isaP(clause, SGT_NORMALIZE_PROPOSITION)) {
            normalize_proposition(((Proposition*)(clause)));
          }
        }
      }
    }
    else if (test_value_001 == KWD_NORMALIZE_EXISTS) {
      normalize_exists_proposition(self);
    }
    else if (test_value_001 == KWD_NORMALIZE_FORALL) {
      normalize_forall_proposition(self);
    }
    else if ((test_value_001 == KWD_NORMALIZE_EQUIVALENT) ||
        ((test_value_001 == KWD_NORMALIZE_IMPLIES) ||
         (test_value_001 == KWD_NORMALIZE_CONSTANT))) {
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

void invert_atomic_proposition(Proposition* self) {
  { Proposition* newatomicproposition = create_proposition(SYM_NORMALIZE_NOT, 1);
    Vector* notarguments = newatomicproposition->arguments;
    Proposition* newnotproposition = self;

    notarguments->nth_setter(newatomicproposition, 0);
    newatomicproposition->kind = newnotproposition->kind;
    newnotproposition->kind = KWD_NORMALIZE_NOT;
    newatomicproposition->renamed_Operator = newnotproposition->renamed_Operator;
    newnotproposition->renamed_Operator = SGT_NORMALIZE_NOT;
    newatomicproposition->arguments = newnotproposition->arguments;
    newnotproposition->arguments = notarguments;
    { Object* arg = NULL;
      Vector* vector_001 = newatomicproposition->arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        remove_dependent_proposition_link(arg, newnotproposition);
        add_dependent_proposition_link(arg, newatomicproposition);
      }
    }
    add_dependent_proposition_link(newatomicproposition, newnotproposition);
  }
}

void invert_exists_proposition(Proposition* self) {
  { Proposition* whereproposition = ((Proposition*)(self->arguments->nth(0)));
    Vector* newarguments = new_vector(2);

    self->arguments->free();
    normalize_proposition(whereproposition);
    invert_proposition(whereproposition);
    self->kind = KWD_NORMALIZE_FORALL;
    self->renamed_Operator = SGT_NORMALIZE_FORALL;
    newarguments->nth_setter(TRUE_PROPOSITION, 0);
    newarguments->nth_setter(whereproposition, 1);
    self->arguments = newarguments;
    normalize_proposition(self);
  }
}

void invert_forall_proposition(Proposition* self) {
  { Proposition* antecedent = ((Proposition*)(self->arguments->nth(0)));
    Proposition* consequent = ((Proposition*)(self->arguments->nth(1)));
    Vector* newarguments = new_vector(1);

    self->arguments->free();
    normalize_proposition(antecedent);
    normalize_proposition(consequent);
    invert_proposition(consequent);
    self->kind = KWD_NORMALIZE_EXISTS;
    self->renamed_Operator = SGT_NORMALIZE_EXISTS;
    newarguments->nth_setter(conjoin_two_propositions(antecedent, consequent), 0);
    self->arguments = newarguments;
    normalize_proposition(self);
  }
}

Proposition* extract_proposition(Description* self, Key_Value_List* mapping) {
  { Proposition* proposition = self->proposition;
    Proposition* existsproposition = (self->internal_variables->non_emptyP() ? ((Proposition*)(create_proposition(SYM_NORMALIZE_EXISTS, 1))) : ((Proposition*)(NULL)));

    if (existsproposition != NULL) {
      set_dynamic_slot_value(existsproposition, SYM_NORMALIZE_IO_VARIABLES, copy_variables_vector(self->internal_variables, mapping), NULL);
    }
    proposition = copy_proposition(proposition, mapping);
    if (existsproposition != NULL) {
      existsproposition->arguments->nth_setter(proposition, 0);
      add_dependent_proposition_link(proposition, existsproposition);
      proposition = existsproposition;
    }
    return (proposition);
  }
}

void invert_implies_proposition(Proposition* self) {
  { Vector* arguments = self->arguments;
    Description* subset = ((Description*)((surrogateP(arguments->nth(0)) ? ((Object*)(((Surrogate*)(arguments->nth(0)))->get_description())) : ((Object*)(arguments->nth(0))))));
    Description* superset = ((Description*)((surrogateP(arguments->nth(1)) ? ((Object*)(((Surrogate*)(arguments->nth(1)))->get_description())) : ((Object*)(arguments->nth(1))))));
    Proposition* subsetprop = NULL;
    Proposition* supersetprop = NULL;
    Key_Value_List* mapping = new_key_value_list();
    Vector* newarguments = new_vector(1);

    self->kind = KWD_NORMALIZE_EXISTS;
    self->renamed_Operator = SGT_NORMALIZE_EXISTS;
    set_dynamic_slot_value(self, SYM_NORMALIZE_IO_VARIABLES, copy_variables_vector(subset->io_variables, mapping), NULL);
    { Pattern_Variable* supvar = NULL;
      Pattern_Variable* iovar = NULL;
      Vector* vector_001 = ((Vector*)(dynamic_slot_value(self, SYM_NORMALIZE_IO_VARIABLES, NULL)));
      int index_001 = 0;
      int length_001 = vector_001->length();
      Vector* vector_002 = superset->io_variables;
      int index_002 = 0;
      int length_002 = vector_002->length();

      while ((index_001 < length_001) &&
          (index_002 < length_002)) {
        {
          iovar = ((Pattern_Variable*)(vector_001->nth(index_001)));
          index_001 = index_001 + 1;
        }
        {
          supvar = ((Pattern_Variable*)(vector_002->nth(index_002)));
          index_002 = index_002 + 1;
        }
        mapping->insert_at(supvar, iovar);
      }
    }
    subsetprop = extract_proposition(subset, mapping);
    supersetprop = extract_proposition(superset, mapping);
    invert_proposition(supersetprop);
    newarguments->nth_setter(conjoin_two_propositions(subsetprop, supersetprop), 0);
    add_dependent_proposition_link(newarguments->nth(0), self);
    self->arguments->free();
    mapping->free();
    self->arguments = newarguments;
    normalize_proposition(self);
  }
}

void invert_proposition(Proposition* self) {
  { Keyword* test_value_001 = self->kind;

    if ((test_value_001 == KWD_NORMALIZE_FUNCTION) ||
        ((test_value_001 == KWD_NORMALIZE_PREDICATE) ||
         ((test_value_001 == KWD_NORMALIZE_IN) ||
          (test_value_001 == KWD_NORMALIZE_EQUIVALENT)))) {
      invert_atomic_proposition(self);
    }
    else if (test_value_001 == KWD_NORMALIZE_AND) {
      { int argumentcount = self->arguments->length();

        simplify_proposition(self);
        if (self->arguments->length() < argumentcount) {
          invert_proposition(self);
          return;
        }
      }
      self->kind = KWD_NORMALIZE_OR;
      self->renamed_Operator = SGT_NORMALIZE_OR;
      { Object* arg = NULL;
        Vector* vector_001 = self->arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            arg = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          invert_proposition(((Proposition*)(arg)));
        }
      }
    }
    else if (test_value_001 == KWD_NORMALIZE_OR) {
      self->kind = KWD_NORMALIZE_AND;
      self->renamed_Operator = SGT_NORMALIZE_AND;
      { Object* arg = NULL;
        Vector* vector_002 = self->arguments;
        int index_002 = 0;
        int length_002 = vector_002->length();

        while (index_002 < length_002) {
          {
            arg = vector_002->nth(index_002);
            index_002 = index_002 + 1;
          }
          invert_proposition(((Proposition*)(arg)));
        }
      }
    }
    else if (test_value_001 == KWD_NORMALIZE_NOT) {
      overlay_proposition(self, ((Proposition*)(self->arguments->first())));
    }
    else if (test_value_001 == KWD_NORMALIZE_EXISTS) {
      invert_exists_proposition(self);
    }
    else if (test_value_001 == KWD_NORMALIZE_FORALL) {
      invert_forall_proposition(self);
    }
    else if (test_value_001 == KWD_NORMALIZE_IMPLIES) {
      invert_implies_proposition(self);
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

void recursively_deassign_truth_values(Proposition* self) {
  { Proposition* object_001 = self;
    Truth_Value* value_001 = NULL;
    Object* old_value_001 = object_001->truth_value;
    Object* new_value_001 = update_in_context(old_value_001, value_001, object_001, FALSE);

    if (!cs_valueP(old_value_001)) {
      object_001->truth_value = new_value_001;
    }
  }
  { Object* arg = NULL;
    Vector* vector_001 = self->arguments;
    int index_001 = 0;
    int length_001 = vector_001->length();

    while (index_001 < length_001) {
      {
        arg = vector_001->nth(index_001);
        index_001 = index_001 + 1;
      }
      if (isaP(arg, SGT_NORMALIZE_PROPOSITION)) {
        recursively_deassign_truth_values(((Proposition*)(arg)));
      }
    }
  }
}

void reassign_truth_values(Proposition* self) {
  recursively_deassign_truth_values(self);
  { Keyword* old_OevaluationmodeO_001 = oEVALUATIONMODEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oEVALUATIONMODEo = KWD_NORMALIZE_DESCRIPTION;
          assign_truth_value(self, TRUE);
          oEVALUATIONMODEo = old_OevaluationmodeO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oEVALUATIONMODEo = old_OevaluationmodeO_001;
        resignal();
      }
    }
  }
}

void startup_normalize() {
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
            KWD_NORMALIZE_AND = ((Keyword*)(intern_rigid_symbol_wrt_module("AND", NULL, 2)));
            KWD_NORMALIZE_CONSTANT = ((Keyword*)(intern_rigid_symbol_wrt_module("CONSTANT", NULL, 2)));
            SGT_NORMALIZE_TRUE = ((Surrogate*)(intern_rigid_symbol_wrt_module("TRUE", string_get_module("/STELLA", TRUE), 1)));
            SYM_NORMALIZE_CONSTANT = ((Symbol*)(intern_rigid_symbol_wrt_module("CONSTANT", NULL, 0)));
            SYM_NORMALIZE_AND = ((Symbol*)(intern_rigid_symbol_wrt_module("AND", string_get_module("/STELLA", TRUE), 0)));
            KWD_NORMALIZE_OR = ((Keyword*)(intern_rigid_symbol_wrt_module("OR", NULL, 2)));
            SYM_NORMALIZE_OR = ((Symbol*)(intern_rigid_symbol_wrt_module("OR", string_get_module("/STELLA", TRUE), 0)));
            SYM_NORMALIZE_IO_VARIABLES = ((Symbol*)(intern_rigid_symbol_wrt_module("IO-VARIABLES", NULL, 0)));
            KWD_NORMALIZE_EXISTS = ((Keyword*)(intern_rigid_symbol_wrt_module("EXISTS", NULL, 2)));
            KWD_NORMALIZE_NOT = ((Keyword*)(intern_rigid_symbol_wrt_module("NOT", NULL, 2)));
            KWD_NORMALIZE_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            KWD_NORMALIZE_IN = ((Keyword*)(intern_rigid_symbol_wrt_module("IN", NULL, 2)));
            KWD_NORMALIZE_EQUIVALENT = ((Keyword*)(intern_rigid_symbol_wrt_module("EQUIVALENT", NULL, 2)));
            KWD_NORMALIZE_PREDICATE = ((Keyword*)(intern_rigid_symbol_wrt_module("PREDICATE", NULL, 2)));
            SGT_NORMALIZE_FALSE = ((Surrogate*)(intern_rigid_symbol_wrt_module("FALSE", string_get_module("/STELLA", TRUE), 1)));
            SYM_NORMALIZE_EXISTS = ((Symbol*)(intern_rigid_symbol_wrt_module("EXISTS", string_get_module("/STELLA", TRUE), 0)));
            SGT_NORMALIZE_PROPOSITION = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPOSITION", NULL, 1)));
            KWD_NORMALIZE_FORALL = ((Keyword*)(intern_rigid_symbol_wrt_module("FORALL", NULL, 2)));
            KWD_NORMALIZE_IMPLIES = ((Keyword*)(intern_rigid_symbol_wrt_module("IMPLIES", NULL, 2)));
            SYM_NORMALIZE_NOT = ((Symbol*)(intern_rigid_symbol_wrt_module("NOT", string_get_module("/STELLA", TRUE), 0)));
            SGT_NORMALIZE_NOT = ((Surrogate*)(intern_rigid_symbol_wrt_module("NOT", NULL, 1)));
            SGT_NORMALIZE_FORALL = ((Surrogate*)(intern_rigid_symbol_wrt_module("FORALL", NULL, 1)));
            SGT_NORMALIZE_EXISTS = ((Surrogate*)(intern_rigid_symbol_wrt_module("EXISTS", NULL, 1)));
            SGT_NORMALIZE_OR = ((Surrogate*)(intern_rigid_symbol_wrt_module("OR", NULL, 1)));
            SGT_NORMALIZE_AND = ((Surrogate*)(intern_rigid_symbol_wrt_module("AND", NULL, 1)));
            KWD_NORMALIZE_DESCRIPTION = ((Keyword*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 2)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-FLAT-CONJUNCTS", "PROPOSITION", "(DEFUN COLLECT-FLAT-CONJUNCTS ((SELF PROPOSITION) (FLATCONJUNCTS (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&collect_flat_conjuncts));
            }
            { Method_Slot* method = define_method_from_stringified_source("OVERLAY-WITH-CONSTANT-PROPOSITION", "PROPOSITION", "(DEFUN OVERLAY-WITH-CONSTANT-PROPOSITION ((SELF PROPOSITION) (CONSTANTPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&overlay_with_constant_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONJOIN-PROPOSITIONS", "CONS", "(DEFUN (CONJOIN-PROPOSITIONS PROPOSITION) ((CONJUNCTS (CONS OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&conjoin_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-FLAT-DISJUNCTS", "PROPOSITION", "(DEFUN COLLECT-FLAT-DISJUNCTS ((SELF PROPOSITION) (FLATDISJUNCTS (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&collect_flat_disjuncts));
            }
            { Method_Slot* method = define_method_from_stringified_source("DISJOIN-PROPOSITIONS", "CONS", "(DEFUN (DISJOIN-PROPOSITIONS PROPOSITION) ((DISJUNCTS (CONS OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&disjoin_propositions));
            }
            { Method_Slot* method = define_method_from_stringified_source("OVERLAY-PROPOSITION", "PROPOSITION", "(DEFUN OVERLAY-PROPOSITION ((SELF PROPOSITION) (OVERLAYINGPROP PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&overlay_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("NORMALIZE-EXISTS-PROPOSITION", "PROPOSITION", "(DEFUN NORMALIZE-EXISTS-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&normalize_exists_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-MIGRATE-GOALS", "LIST", "(DEFUN (HELP-MIGRATE-GOALS PROPOSITION) ((NEGATEDGOALS (LIST OF PROPOSITION)) (ANTECEDENT PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&help_migrate_goals));
            }
            { Method_Slot* method = define_method_from_stringified_source("MIGRATE-CONSEQUENT-GOALS-TO-ANTECEDENT", "PROPOSITION", "(DEFUN MIGRATE-CONSEQUENT-GOALS-TO-ANTECEDENT ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&migrate_consequent_goals_to_antecedent));
            }
            { Method_Slot* method = define_method_from_stringified_source("NORMALIZE-FORALL-PROPOSITION", "PROPOSITION", "(DEFUN NORMALIZE-FORALL-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&normalize_forall_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("NORMALIZE-NOT-PROPOSITION", "PROPOSITION", "(DEFUN NORMALIZE-NOT-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&normalize_not_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("NORMALIZE-AND-PROPOSITION", "PROPOSITION", "(DEFUN NORMALIZE-AND-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&normalize_and_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("NORMALIZE-OR-PROPOSITION", "PROPOSITION", "(DEFUN NORMALIZE-OR-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&normalize_or_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("NORMALIZE-PROPOSITION", "PROPOSITION", "(DEFUN NORMALIZE-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&normalize_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("INVERT-ATOMIC-PROPOSITION", "PROPOSITION", "(DEFUN INVERT-ATOMIC-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&invert_atomic_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("INVERT-EXISTS-PROPOSITION", "PROPOSITION", "(DEFUN INVERT-EXISTS-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&invert_exists_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("INVERT-FORALL-PROPOSITION", "PROPOSITION", "(DEFUN INVERT-FORALL-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&invert_forall_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXTRACT-PROPOSITION", "DESCRIPTION", "(DEFUN (EXTRACT-PROPOSITION PROPOSITION) ((SELF DESCRIPTION) (MAPPING ENTITY-MAPPING)))");

              method->function_code = ((cpp_function_code)(&extract_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("INVERT-IMPLIES-PROPOSITION", "PROPOSITION", "(DEFUN INVERT-IMPLIES-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&invert_implies_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("INVERT-PROPOSITION", "PROPOSITION", "(DEFUN INVERT-PROPOSITION ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&invert_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("RECURSIVELY-DEASSIGN-TRUTH-VALUES", "PROPOSITION", "(DEFUN RECURSIVELY-DEASSIGN-TRUTH-VALUES ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&recursively_deassign_truth_values));
            }
            { Method_Slot* method = define_method_from_stringified_source("REASSIGN-TRUTH-VALUES", "PROPOSITION", "(DEFUN REASSIGN-TRUTH-VALUES ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&reassign_truth_values));
            }
            define_method_from_stringified_source("STARTUP-NORMALIZE", NULL, "(DEFUN STARTUP-NORMALIZE ())");
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

