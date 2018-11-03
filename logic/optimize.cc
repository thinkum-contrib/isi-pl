// optimize.cc

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

Symbol* SYM_OPTIMIZE_GENERATOR_GOALS = NULL;

Symbol* SYM_OPTIMIZE_OTHER_GOALS = NULL;

Surrogate* SGT_OPTIMIZE_GOAL_RECORD = NULL;

Surrogate* SGT_OPTIMIZE_PATTERN_VARIABLE = NULL;

Surrogate* SGT_OPTIMIZE_PROPOSITION = NULL;

Keyword* KWD_OPTIMIZE_OR = NULL;

Symbol* SYM_OPTIMIZE_PERMUTATION_TABLE = NULL;

Surrogate* SGT_OPTIMIZE_LITERAL = NULL;

Surrogate* SGT_OPTIMIZE_DESCRIPTION = NULL;

boolean oDISTRIBUTEDOPENGOALpo;

Symbol* SYM_OPTIMIZE_oDISTRIBUTEDOPENGOALpo = NULL;

Keyword* KWD_OPTIMIZE_FUNCTION = NULL;

Keyword* KWD_OPTIMIZE_EQUIVALENT = NULL;

Keyword* KWD_OPTIMIZE_IN = NULL;

Keyword* KWD_OPTIMIZE_PREDICATE = NULL;

Keyword* KWD_OPTIMIZE_NOT = NULL;

Symbol* SYM_OPTIMIZE_UNIQUENESSVECTORS = NULL;

Symbol* SYM_OPTIMIZE_INDEXING_VECTOR = NULL;

Boolean_Vector* V_0_0 = NULL;

Boolean_Vector* V_1_0 = NULL;

Boolean_Vector* V_0_1 = NULL;

Boolean_Vector* V_1_1 = NULL;

List* V_1_0_AND_V_0_1 = NULL;

List* V_1_0_SINGLETON = NULL;

List* V_0_1_SINGLETON = NULL;

Symbol* SYM_OPTIMIZE_INVERSE = NULL;

int ESTIMATED_SLOT_VALUE_COLLECTION_SIZE = 4;

int ESTIMATED_NUMBER_OF_PREDICATE_BINDINGS = 6;

Symbol* SYM_OPTIMIZE_DESCRIPTION = NULL;

Symbol* SYM_OPTIMIZE_ESTIMATED_CARDINALITY = NULL;

Surrogate* SGT_OPTIMIZE_LITERAL_WRAPPER = NULL;

Keyword* KWD_OPTIMIZE_OPEN = NULL;

Surrogate* SGT_OPTIMIZE_COLLECTION = NULL;

Keyword* KWD_OPTIMIZE_FORALL = NULL;

Keyword* KWD_OPTIMIZE_BOUND = NULL;

Keyword* KWD_OPTIMIZE_AND = NULL;

Keyword* KWD_OPTIMIZE_IMPLIES = NULL;

Keyword* KWD_OPTIMIZE_EXISTS = NULL;

Control_Frame* oQUERYOPTIMIZERCONTROLFRAMEo;

Symbol* SYM_OPTIMIZE_oQUERYOPTIMIZERCONTROLFRAMEo = NULL;

Keyword* KWD_OPTIMIZE_PATTERN = NULL;

boolean oPOSTOPTIMIZATIONpo = FALSE;

Symbol* SYM_OPTIMIZE_oPOSTOPTIMIZATIONpo = NULL;

Symbol* SYM_OPTIMIZE_ENTITY_MAPPING = NULL;

Keyword* KWD_OPTIMIZE_REALISTIC = NULL;

Keyword* KWD_OPTIMIZE_FLAT = NULL;

Symbol* SYM_OPTIMIZE_SKOLEM_NAME = NULL;

Symbol* SYM_OPTIMIZE_VARIABLE_TYPEp = NULL;

Symbol* SYM_OPTIMIZE_IO_VARIABLES = NULL;

Surrogate* SGT_OPTIMIZE_SKOLEM = NULL;

Surrogate* SGT_OPTIMIZE_SURROGATE = NULL;

Goal_Record* new_goal_record() {
  { Goal_Record* self = NULL;

    self = new Goal_Record;
    self->other_goals = new_list();
    self->generator_goals = new_list();
    return (self);
  }
}

Object* access_goal_record_slot_value(Goal_Record* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_OPTIMIZE_GENERATOR_GOALS) {
    if (setvalueP) {
      self->generator_goals = ((List*)(value));
    }
    else {
      return (self->generator_goals);
    }
  }
  else if (slotname == SYM_OPTIMIZE_OTHER_GOALS) {
    if (setvalueP) {
      self->other_goals = ((List*)(value));
    }
    else {
      return (self->other_goals);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Goal_Record::primary_type() {
  { Goal_Record* self = this;

    return (SGT_OPTIMIZE_GOAL_RECORD);
  }
}

boolean variable_boundP(Pattern_Variable* variable) {
  return ((bound_to(variable) != NULL) ||
      (((Object*)(access_in_context(variable->variable_value, variable, FALSE))) != NULL));
}

boolean argument_boundP(Object* argument) {
  { Object* argument_001 = argument;

    if (taxonomy_isaP(argument, SGT_OPTIMIZE_PATTERN_VARIABLE)) {
      { Pattern_Variable* argument = NULL;

        argument = ((Pattern_Variable*)(argument_001));
        return (variable_boundP(argument));
      }
    }
    else if (taxonomy_isaP(argument, SGT_OPTIMIZE_PROPOSITION)) {
      { Proposition* argument = NULL;

        argument = ((Proposition*)(argument_001));
        return (all_arguments_boundP(argument));
      }
    }
    else {
      return (TRUE);
    }
  }
}

boolean unbound_variableP(Object* argument) {
  { Object* argument_001 = argument;

    if (taxonomy_isaP(argument, SGT_OPTIMIZE_PATTERN_VARIABLE)) {
      { Pattern_Variable* argument = NULL;

        argument = ((Pattern_Variable*)(argument_001));
        return (!variable_boundP(argument));
      }
    }
    else {
      return (FALSE);
    }
  }
}

boolean has_disjunctionP(Proposition* goal) {
  if (goal->kind == KWD_OPTIMIZE_OR) {
    return (TRUE);
  }
  { boolean foundP_001 = FALSE;

    { Object* arg = NULL;
      Vector* vector_001 = goal->arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        if (isaP(arg, SGT_OPTIMIZE_PROPOSITION) &&
            has_disjunctionP(((Proposition*)(arg)))) {
          foundP_001 = TRUE;
          break;
        }
      }
    }
    { boolean value_001 = foundP_001;

      return (value_001);
    }
  }
}

boolean modal_goalP(Proposition* goal) {
  { boolean foundP_001 = FALSE;

    { Object* arg = NULL;
      Vector* vector_001 = goal->arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        if (isaP(arg, SGT_OPTIMIZE_PROPOSITION)) {
          foundP_001 = TRUE;
          break;
        }
      }
    }
    { boolean value_001 = foundP_001;

      return (value_001);
    }
  }
}

boolean has_inversionsP(Proposition* goal) {
  return (((Key_Value_List*)(dynamic_slot_value(((Slot*)(((Surrogate*)(goal->renamed_Operator))->surrogate_value)), SYM_OPTIMIZE_PERMUTATION_TABLE, NULL))) != NULL);
}

boolean computed_predicateP(Proposition* predicateproposition) {
  { Slot* slot = ((Slot*)(((Surrogate*)(predicateproposition->renamed_Operator))->surrogate_value));

    { Slot* slot_001 = slot;

      if (method_slotP(slot)) {
        { Method_Slot* slot = NULL;

          slot = ((Method_Slot*)(slot_001));
          return ((slot->method_code != NULL) ||
              (slot->function_code != NULL));
        }
      }
      else {
        return (FALSE);
      }
    }
  }
}

int simulate_create_choice_point() {
  return (oQUERYENVIRONMENTo->top_unbinding_stack_offset + 1);
}

boolean class_inherits_enumerated_extensionP(Class* renamed_Class) {
  if (renamed_Class->abstractP) {
    return (FALSE);
  }
  { Class* rootclass = leftmost_concrete_superclass(renamed_Class);

    return (!subtype_ofP(rootclass->class_type, SGT_OPTIMIZE_LITERAL));
  }
}

boolean generator_collectionP(Object* collection) {
  if (oREVERSEPOLARITYpo &&
      (!closed_collectionP(collection))) {
    return (FALSE);
  }
  { Object* collection_001 = collection;

    if (taxonomy_isaP(collection, SGT_OPTIMIZE_DESCRIPTION)) {
      { Description* collection = NULL;

        collection = ((Description*)(collection_001));
        return ((collection->native_relation != NULL) &&
            class_inherits_enumerated_extensionP(((Class*)(collection->native_relation))));
      }
    }
    else if (taxonomy_isaP(collection, SGT_OPTIMIZE_PATTERN_VARIABLE)) {
      { Pattern_Variable* collection = NULL;

        collection = ((Pattern_Variable*)(collection_001));
        { Object* boundtovalue = argument_bound_to(collection);

          if (boundtovalue != NULL) {
            return (generator_collectionP(boundtovalue));
          }
          else if (collection->defining_proposition != NULL) {
            return (TRUE);
          }
          else {
            return (FALSE);
          }
        }
      }
    }
    else {
      return (TRUE);
    }
  }
}

void initialize_optimizer_goal_records(int size) {
  { Extensible_Vector* stack = oQUERYENVIRONMENTo->optimizer_goal_records;

    if (stack == NULL) {
      stack = new_extensible_vector(20);
      oQUERYENVIRONMENTo->optimizer_goal_records = stack;
    }
    if (size > stack->length()) {
      stack->nth_setter(NULL, size);
    }
    { int i = NULL_INTEGER;
      int iter_001 = 0;
      int upper_bound_001 = size - 1;

      while (iter_001 <= upper_bound_001) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        { Goal_Record* goalrecord = ((Goal_Record*)(stack->nth(i)));

          if (goalrecord == NULL) {
            goalrecord = new_goal_record();
            stack->nth_setter(goalrecord, i);
          }
          goalrecord->generator_goals->clear();
          goalrecord->other_goals->clear();
        }
      }
    }
  }
}

Goal_Record* goal_record(Pattern_Variable* variable) {
  return (((Goal_Record*)(oQUERYENVIRONMENTo->optimizer_goal_records->nth(variable->bound_to_offset))));
}

boolean read_OdistributedopengoalPO() {
  return (oDISTRIBUTEDOPENGOALpo);
}

boolean write_OdistributedopengoalPO(boolean value) {
  oDISTRIBUTEDOPENGOALpo = value;
  return (value);
}

void help_distribute_goal(Object* argument, Proposition* parentgoal, boolean generatorP) {
  { Object* argument_001 = argument;

    if (taxonomy_isaP(argument, SGT_OPTIMIZE_PATTERN_VARIABLE)) {
      { Pattern_Variable* argument = NULL;

        argument = ((Pattern_Variable*)(argument_001));
        if (variable_boundP(argument)) {
          return;
        }
        { Goal_Record* goalrecord = goal_record(argument);

          if (goalrecord->generator_goals->memberP(parentgoal) ||
              goalrecord->other_goals->memberP(parentgoal)) {
            return;
          }
          if (generatorP) {
            goalrecord->generator_goals->insert(parentgoal);
          }
          else {
            goalrecord->other_goals->insert(parentgoal);
          }
          oDISTRIBUTEDOPENGOALpo = TRUE;
        }
      }
    }
    else if (taxonomy_isaP(argument, SGT_OPTIMIZE_PROPOSITION)) {
      { Proposition* argument = NULL;

        argument = ((Proposition*)(argument_001));
        { Object* arg = NULL;
          Vector* vector_001 = argument->arguments;
          int index_001 = 0;
          int length_001 = vector_001->length();

          while (index_001 < length_001) {
            {
              arg = vector_001->nth(index_001);
              index_001 = index_001 + 1;
            }
            help_distribute_goal(arg, parentgoal, generatorP);
          }
        }
      }
    }
    else {
    }
  }
}

void distribute_open_goal(Proposition* goal) {
  { boolean old_OdistributedopengoalPO_001 = oDISTRIBUTEDOPENGOALpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oDISTRIBUTEDOPENGOALpo = FALSE;
          { Keyword* test_value_001 = goal->kind;

            if (test_value_001 == KWD_OPTIMIZE_FUNCTION) {
              { Object* arg = NULL;
                Iterator* iter_001 = goal->arguments->but_last();

                while (iter_001->nextP()) {
                  {
                    arg = iter_001->value;
                  }
                  help_distribute_goal(arg, goal, !computed_predicateP(goal));
                }
              }
              help_distribute_goal(last_argument(goal), goal, FALSE);
            }
            else if (test_value_001 == KWD_OPTIMIZE_EQUIVALENT) {
              { Object* arg = NULL;
                Vector* vector_001 = goal->arguments;
                int index_001 = 0;
                int length_001 = vector_001->length();

                while (index_001 < length_001) {
                  {
                    arg = vector_001->nth(index_001);
                    index_001 = index_001 + 1;
                  }
                  help_distribute_goal(arg, goal, FALSE);
                }
              }
            }
            else if (test_value_001 == KWD_OPTIMIZE_IN) {
              help_distribute_goal(goal->arguments->first(), goal, generator_collectionP(goal->arguments->second()));
              help_distribute_goal(goal->arguments->second(), goal, FALSE);
            }
            else if (test_value_001 == KWD_OPTIMIZE_PREDICATE) {
              { Object* arg = NULL;
                Vector* vector_002 = goal->arguments;
                int index_002 = 0;
                int length_002 = vector_002->length();

                while (index_002 < length_002) {
                  {
                    arg = vector_002->nth(index_002);
                    index_002 = index_002 + 1;
                  }
                  help_distribute_goal(arg, goal, !computed_predicateP(goal));
                }
              }
            }
            else if (test_value_001 == KWD_OPTIMIZE_NOT) {
              help_distribute_goal(goal->arguments->first(), goal, FALSE);
            }
            else {
            }
          }
          if (!oDISTRIBUTEDOPENGOALpo) {
            oQUERYENVIRONMENTo->residue_goals->insert(goal);
          }
          oDISTRIBUTEDOPENGOALpo = old_OdistributedopengoalPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oDISTRIBUTEDOPENGOALpo = old_OdistributedopengoalPO_001;
        resignal();
      }
    }
  }
}

List* Slot::uniquenessvectors_reader() {
  { Slot* self = this;

    { List* answer = ((List*)(dynamic_slot_value(self, SYM_OPTIMIZE_UNIQUENESSVECTORS, NULL)));

      if (answer == NULL) {
        return (NIL_LIST);
      }
      else {
        return (answer);
      }
    }
  }
}

List* Slot::get_uniqueness_vectors() {
  { Slot* self = this;

    { List* cachedvectorlist = self->uniquenessvectors_reader();

      if (cachedvectorlist != NULL) {
        return (cachedvectorlist);
      }
      else {
        return (NIL_LIST);
      }
    }
  }
}

Boolean_Vector* Slot::get_indexing_vector() {
  { Slot* self = this;

    { Boolean_Vector* cachedvector = ((Boolean_Vector*)(dynamic_slot_value(self, SYM_OPTIMIZE_INDEXING_VECTOR, NULL)));

      if (cachedvector != NULL) {
        return (cachedvector);
      }
      { List* zeroonelist = new_list();

        { Surrogate* type = NULL;
          Iterator* iter_001 = slot_column_types(self);
          Cons* collect_001 = NULL;

          while (iter_001->nextP()) {
            {
              type = ((Surrogate*)(iter_001->value));
            }
            if (collect_001 == NULL) {
              {
                collect_001 = permanent_cons((type_has_backlinksP(type) ? ((Integer_Wrapper*)(ONE_WRAPPER)) : ((Integer_Wrapper*)(ZERO_WRAPPER))), NIL);
                if (zeroonelist->the_cons_list->emptyP()) {
                  zeroonelist->the_cons_list = collect_001;
                }
                else {
                  add_cons_to_end_of_cons_list(zeroonelist->the_cons_list, collect_001);
                }
              }
            }
            else {
              {
                collect_001->rest = permanent_cons((type_has_backlinksP(type) ? ((Integer_Wrapper*)(ONE_WRAPPER)) : ((Integer_Wrapper*)(ZERO_WRAPPER))), NIL);
                collect_001 = collect_001->rest;
              }
            }
          }
        }
        set_dynamic_slot_value(self, SYM_OPTIMIZE_INDEXING_VECTOR, zero_one_list_to_boolean_vector(zeroonelist), NULL);
        zeroonelist->free();
        return (((Boolean_Vector*)(dynamic_slot_value(self, SYM_OPTIMIZE_INDEXING_VECTOR, NULL))));
      }
    }
  }
}

List* Storage_Slot::get_uniqueness_vectors() {
  { Storage_Slot* self = this;

    { boolean singlevaluedinverseP = (((Slot*)(dynamic_slot_value(self, SYM_OPTIMIZE_INVERSE, NULL))) != NULL) &&
          ((Slot*)(dynamic_slot_value(self, SYM_OPTIMIZE_INVERSE, NULL)))->single_valuedP();

      if (self->single_valuedP()) {
        return ((singlevaluedinverseP ? ((List*)(V_1_0_AND_V_0_1)) : ((List*)(V_1_0_SINGLETON))));
      }
      else {
        return ((singlevaluedinverseP ? ((List*)(V_0_1_SINGLETON)) : ((List*)(NIL_LIST))));
      }
    }
  }
}

Boolean_Vector* Storage_Slot::get_indexing_vector() {
  { Storage_Slot* self = this;

    { boolean bitoneP = type_has_backlinksP(self->slot_owner) ||
          ((((Slot*)(dynamic_slot_value(self, SYM_OPTIMIZE_INVERSE, NULL))) != NULL) &&
           ((Slot*)(dynamic_slot_value(self, SYM_OPTIMIZE_INVERSE, NULL)))->index_on_valuesP_reader());
      boolean bittwoP = type_has_backlinksP(self->slot_base_type) ||
          self->index_on_valuesP_reader();

      if (bitoneP) {
        return ((bittwoP ? ((Boolean_Vector*)(V_1_1)) : ((Boolean_Vector*)(V_1_0))));
      }
      else {
        return ((bittwoP ? ((Boolean_Vector*)(V_0_1)) : ((Boolean_Vector*)(V_0_0))));
      }
    }
  }
}

int estimate_cardinality_of_class_extension(Class* renamed_Class) {
  if (renamed_Class == NULL) {
    return (NULL_INTEGER);
  }
  { Description* description = ((Description*)(dynamic_slot_value(renamed_Class, SYM_OPTIMIZE_DESCRIPTION, NULL)));

    if ((description != NULL) &&
        (((Integer_Wrapper*)(dynamic_slot_value(description, SYM_OPTIMIZE_ESTIMATED_CARDINALITY, NULL_INTEGER_WRAPPER)))->wrapper_value != NULL_INTEGER)) {
      return (max(((Integer_Wrapper*)(dynamic_slot_value(description, SYM_OPTIMIZE_ESTIMATED_CARDINALITY, NULL_INTEGER_WRAPPER)))->wrapper_value, 2));
    }
    else if (subtype_ofP(renamed_Class->class_type, SGT_OPTIMIZE_LITERAL_WRAPPER) ||
        subtype_ofP(renamed_Class->class_type, SGT_OPTIMIZE_LITERAL)) {
      return (NULL_INTEGER);
    }
    else if (description != NULL) {
      { int counter = 0;
        Iterator* members = collection_members(description, KWD_OPTIMIZE_OPEN);

        if (members != NULL) {
          { Iterator* m = members;

            while (m->nextP()) {
              if (counter < 20) {
                counter = counter + 1;
              }
            }
          }
          set_dynamic_slot_value(description, SYM_OPTIMIZE_ESTIMATED_CARDINALITY, wrap_integer(counter), NULL_INTEGER_WRAPPER);
        }
        return (max(counter, 2));
      }
    }
    else {
      return (20);
    }
  }
}

int estimate_predicate_goal_cost(Proposition* goal) {
  { Slot* slot = operator_bound_to(goal->renamed_Operator);
    Boolean_Vector* goalvector = arguments_vector_to_boolean_vector(goal->arguments);

    if (slot == NULL) {
      return (NULL_INTEGER);
    }
    { boolean test_value_001 = FALSE;

      { boolean foundP_001 = FALSE;

        { Boolean_Wrapper* ibit = NULL;
          Boolean_Wrapper* gbit = NULL;
          Boolean_Vector* vector_001 = goalvector;
          int index_001 = 0;
          int length_001 = vector_001->length();
          Boolean_Vector* vector_002 = slot->get_indexing_vector();
          int index_002 = 0;
          int length_002 = vector_002->length();

          while ((index_001 < length_001) &&
              (index_002 < length_002)) {
            {
              gbit = ((Boolean_Wrapper*)(vector_001->nth(index_001)));
              index_001 = index_001 + 1;
            }
            {
              ibit = ((Boolean_Wrapper*)(vector_002->nth(index_002)));
              index_002 = index_002 + 1;
            }
            if (eqlP(ibit, TRUE_WRAPPER) &&
                eqlP(gbit, TRUE_WRAPPER)) {
              foundP_001 = TRUE;
              break;
            }
          }
        }
        test_value_001 = foundP_001;
      }
      test_value_001 = !test_value_001;
      if (test_value_001) {
        return (NULL_INTEGER);
      }
    }
    { boolean allbitsmatchP = FALSE;

      { Boolean_Vector* uniquenesskey = NULL;
        Cons* iter_001 = slot->get_uniqueness_vectors()->the_cons_list;

        while (!nilP(iter_001)) {
          {
            uniquenesskey = ((Boolean_Vector*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          allbitsmatchP = TRUE;
          { Boolean_Wrapper* gbit = NULL;
            Boolean_Wrapper* ubit = NULL;
            Boolean_Vector* vector_003 = uniquenesskey;
            int index_003 = 0;
            int length_003 = vector_003->length();
            Boolean_Vector* vector_004 = goalvector;
            int index_004 = 0;
            int length_004 = vector_004->length();

            while ((index_003 < length_003) &&
                (index_004 < length_004)) {
              {
                ubit = ((Boolean_Wrapper*)(vector_003->nth(index_003)));
                index_003 = index_003 + 1;
              }
              {
                gbit = ((Boolean_Wrapper*)(vector_004->nth(index_004)));
                index_004 = index_004 + 1;
              }
              if (eqlP(ubit, TRUE_WRAPPER) &&
                  eqlP(gbit, FALSE_WRAPPER)) {
                allbitsmatchP = FALSE;
                break;
              }
            }
          }
          if (allbitsmatchP) {
            return (1);
          }
        }
      }
      return (ESTIMATED_NUMBER_OF_PREDICATE_BINDINGS);
    }
  }
}

int estimate_goal_cost(Proposition* goal) {
  { Keyword* test_value_001 = goal->kind;

    if (test_value_001 == KWD_OPTIMIZE_IN) {
      { Object* secondarg = argument_bound_to(goal->arguments->second());

        if (secondarg == NULL) {
          return (NULL_INTEGER);
        }
        { Object* secondarg_001 = secondarg;

          if (taxonomy_isaP(secondarg, SGT_OPTIMIZE_DESCRIPTION)) {
            { Description* secondarg = NULL;

              secondarg = ((Description*)(secondarg_001));
              return (estimate_cardinality_of_class_extension(((Class*)(secondarg->native_relation))));
            }
          }
          else if (taxonomy_isaP(secondarg, SGT_OPTIMIZE_COLLECTION)) {
            { Collection* secondarg = NULL;

              secondarg = ((Collection*)(secondarg_001));
              return (secondarg->length());
            }
          }
          else {
            return (ESTIMATED_SLOT_VALUE_COLLECTION_SIZE);
          }
        }
      }
    }
    else if ((test_value_001 == KWD_OPTIMIZE_FUNCTION) ||
        (test_value_001 == KWD_OPTIMIZE_PREDICATE)) {
      return (estimate_predicate_goal_cost(goal));
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

Proposition* cheapest_generator_goal(Pattern_Variable* variable, int& return1) {
  { Proposition* bestgoal = NULL;
    int bestcost = NULL_INTEGER;
    int cost = NULL_INTEGER;

    { Proposition* goal = NULL;
      Cons* iter_001 = goal_record(variable)->generator_goals->the_cons_list;

      while (!nilP(iter_001)) {
        {
          goal = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        cost = estimate_goal_cost(goal);
        if ((cost != NULL_INTEGER) &&
            ((bestcost == NULL_INTEGER) ||
             (cost < bestcost))) {
          if (cost == 1) {
            { Proposition* return_temp = goal;

              return1 = 1;
              return (return_temp);
            }
          }
          bestgoal = goal;
          bestcost = cost;
        }
      }
    }
    if (bestcost != NULL_INTEGER) {
      { Proposition* return_temp = bestgoal;

        return1 = bestcost;
        return (return_temp);
      }
    }
    else {
      { Proposition* return_temp = NULL;

        return1 = 0;
        return (return_temp);
      }
    }
  }
}

void propagate_single_valued_constraints(Proposition* goal, List* goalsequence) {
  { Vector* arguments = goal->arguments;

    { Keyword* test_value_001 = goal->kind;

      if (test_value_001 == KWD_OPTIMIZE_FUNCTION) {
        { boolean test_value_002 = FALSE;

          { boolean alwaysP_001 = TRUE;

            { Object* arg = NULL;
              Iterator* iter_001 = arguments->but_last();

              while (iter_001->nextP()) {
                {
                  arg = iter_001->value;
                }
                if (!argument_boundP(arg)) {
                  alwaysP_001 = FALSE;
                  break;
                }
              }
            }
            test_value_002 = alwaysP_001;
          }
          if (test_value_002) {
            test_value_002 = unbound_variableP(arguments->last());
          }
          if (test_value_002) {
            {
              goalsequence->push(goal);
              simulate_bind_variable_and_propagate_constraints(((Pattern_Variable*)(arguments->last())), goalsequence);
            }
          }
          else {
            {
            }
          }
        }
      }
      else if (test_value_001 == KWD_OPTIMIZE_IN) {
      }
      else if (test_value_001 == KWD_OPTIMIZE_EQUIVALENT) {
        if (unbound_variableP(arguments->first())) {
          goalsequence->push(goal);
          simulate_bind_variable_and_propagate_constraints(((Pattern_Variable*)(arguments->first())), goalsequence);
        }
        else if (unbound_variableP(arguments->second())) {
          goalsequence->push(goal);
          simulate_bind_variable_and_propagate_constraints(((Pattern_Variable*)(arguments->second())), goalsequence);
        }
      }
      else if (test_value_001 == KWD_OPTIMIZE_PREDICATE) {
      }
      else if (test_value_001 == KWD_OPTIMIZE_NOT) {
      }
      else {
        cerr << "`" << test_value_001 << "'" << " is not a valid case option";
      }
    }
  }
}

void collect_closed_goals(List* goals, List* goalsequence) {
  { Proposition* g = NULL;
    Cons* iter_001 = goals->the_cons_list;

    while (!nilP(iter_001)) {
      {
        g = ((Proposition*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (all_arguments_boundP(g) &&
          (!goalsequence->memberP(g))) {
        goalsequence->push(g);
      }
    }
  }
}

void simulate_bind_variable_and_propagate_constraints(Pattern_Variable* variable, List* goalsequence) {
  { Goal_Record* goalrecord = goal_record(variable);

    if (!unbound_variableP(variable)) {
      cerr << "Safety violation: " << "INTERNAL ERROR: Query optimizer found bound variable " << "where unbound variable was expected.";
    }
    simulate_bind_variable_to_value(variable);
    collect_closed_goals(goalrecord->generator_goals, goalsequence);
    collect_closed_goals(goalrecord->other_goals, goalsequence);
    { Proposition* g = NULL;
      Cons* iter_001 = goalrecord->generator_goals->the_cons_list;

      while (!nilP(iter_001)) {
        {
          g = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        propagate_single_valued_constraints(g, goalsequence);
      }
    }
    { Proposition* g = NULL;
      Cons* iter_002 = goalrecord->other_goals->the_cons_list;

      while (!nilP(iter_002)) {
        {
          g = ((Proposition*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        propagate_single_valued_constraints(g, goalsequence);
      }
    }
  }
}

void bind_all_variables_in_generator_goal(Proposition* goal, List* goalsequence) {
  { Object* arg = NULL;
    Vector* vector_001 = goal->arguments;
    int index_001 = 0;
    int length_001 = vector_001->length();

    while (index_001 < length_001) {
      {
        arg = vector_001->nth(index_001);
        index_001 = index_001 + 1;
      }
      if (isaP(arg, SGT_OPTIMIZE_PATTERN_VARIABLE) &&
          unbound_variableP(arg)) {
        simulate_bind_variable_and_propagate_constraints(((Pattern_Variable*)(arg)), goalsequence);
      }
    }
  }
}

void compute_optimal_open_goal_ordering(List* optimizervariables, int numberofopengoals, List* goalsequence, int cost) {
  { Cons* goalsequencecheckpoint = NULL;
    int choicepointunbindingoffset = NULL_INTEGER;
    int increasedcost = NULL_INTEGER;

    if (optimizervariables->emptyP()) {
      oQUERYENVIRONMENTo->best_goal_sequence = goalsequence;
      return;
    }
    { Pattern_Variable* vbl = NULL;
      Cons* iter_001 = optimizervariables->the_cons_list;

      while (!nilP(iter_001)) {
        {
          vbl = ((Pattern_Variable*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (!variable_boundP(vbl)) {
          { Proposition* generatorgoal = NULL;
            int generatorcost = NULL_INTEGER;

            generatorgoal = cheapest_generator_goal(vbl, generatorcost);
            if (generatorgoal == NULL) {
              continue;
            }
            increasedcost = cost * generatorcost;
            if ((oQUERYENVIRONMENTo->best_cost != NULL_INTEGER) &&
                (increasedcost >= oQUERYENVIRONMENTo->best_cost)) {
              continue;
            }
            goalsequencecheckpoint = goalsequence->the_cons_list;
            choicepointunbindingoffset = simulate_create_choice_point();
            goalsequence->push(generatorgoal);
            bind_all_variables_in_generator_goal(generatorgoal, goalsequence);
          }
          if (goalsequence->length() == numberofopengoals) {
            if ((oQUERYENVIRONMENTo->best_cost == NULL_INTEGER) ||
                (increasedcost < oQUERYENVIRONMENTo->best_cost)) {
              oQUERYENVIRONMENTo->best_cost = increasedcost;
              oQUERYENVIRONMENTo->best_goal_sequence = goalsequence->copy();
            }
          }
          else {
            compute_optimal_open_goal_ordering(optimizervariables, numberofopengoals, goalsequence, increasedcost);
          }
          goalsequence->the_cons_list = goalsequencecheckpoint;
          unbind_variables_beginning_at(choicepointunbindingoffset);
        }
      }
    }
  }
}

void collect_optimizer_variables(Proposition* proposition, List* collection) {
  { Keyword* test_value_001 = proposition->kind;

    if ((test_value_001 == KWD_OPTIMIZE_IN) ||
        ((test_value_001 == KWD_OPTIMIZE_FUNCTION) ||
         ((test_value_001 == KWD_OPTIMIZE_PREDICATE) ||
          (test_value_001 == KWD_OPTIMIZE_EQUIVALENT)))) {
      { Object* arg = NULL;
        Vector* vector_001 = proposition->arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            arg = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          if (unbound_variableP(arg)) {
            { Pattern_Variable* variable = ((Pattern_Variable*)(arg));

              if (!(variable == innermost_of(variable))) {
                simulate_bind_variable_to_value(variable);
              }
              else if ((variable->defining_proposition == NULL) &&
                  (!anonymous_variableP(variable))) {
                collection->insert_new(variable);
              }
            }
          }
        }
      }
    }
    else {
    }
  }
}

void optimize_ordering_of_conjuncts(Proposition* andproposition) {
  { List* initiallyclosedgoals = new_list();
    List* opengoals = new_list();
    List* optimizervariables = new_list();
    List* goalsequence = new_list();

    { Object* g = NULL;
      Vector* vector_001 = andproposition->arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          g = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        if (all_arguments_boundP(((Proposition*)(g)))) {
          initiallyclosedgoals->insert(((Proposition*)(g)));
        }
        else if (has_disjunctionP(((Proposition*)(g))) ||
            (((Proposition*)(g))->kind == KWD_OPTIMIZE_FORALL)) {
          oQUERYENVIRONMENTo->residue_goals->insert(((Proposition*)(g)));
        }
        else {
          opengoals->insert(((Proposition*)(g)));
        }
      }
    }
    { Proposition* goal = NULL;
      Cons* iter_001 = opengoals->the_cons_list;

      while (!nilP(iter_001)) {
        {
          goal = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        distribute_open_goal(goal);
      }
    }
    { Proposition* g = NULL;
      Cons* iter_002 = opengoals->the_cons_list;

      while (!nilP(iter_002)) {
        {
          g = ((Proposition*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        { boolean foundP_001 = FALSE;

          { Object* arg = NULL;
            Vector* vector_002 = g->arguments;
            int index_002 = 0;
            int length_002 = vector_002->length();

            while (index_002 < length_002) {
              {
                arg = vector_002->nth(index_002);
                index_002 = index_002 + 1;
              }
              if (argument_boundP(arg)) {
                foundP_001 = TRUE;
                break;
              }
            }
          }
          if (foundP_001) {
            propagate_single_valued_constraints(g, goalsequence);
          }
        }
      }
    }
    { Proposition* goal = NULL;
      Cons* iter_003 = opengoals->the_cons_list;

      while (!nilP(iter_003)) {
        {
          goal = ((Proposition*)(iter_003->value));
          iter_003 = iter_003->rest;
        }
        collect_optimizer_variables(goal, optimizervariables);
      }
    }
    compute_optimal_open_goal_ordering(optimizervariables, opengoals->length(), goalsequence, 1);
    if (oQUERYENVIRONMENTo->best_goal_sequence->emptyP()) {
      compute_backup_open_goal_ordering(opengoals->reverse());
    }
    reorder_goals(andproposition, initiallyclosedgoals, oQUERYENVIRONMENTo->best_goal_sequence->reverse(), oQUERYENVIRONMENTo->residue_goals);
  }
}

void compute_backup_open_goal_ordering(List* goalsequence) {
  { List* lastgoals = new_list();

    { Proposition* g = NULL;
      Cons* iter_001 = goalsequence->the_cons_list;

      while (!nilP(iter_001)) {
        {
          g = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if ((estimate_goal_cost(g) == NULL_INTEGER) &&
            g->variable_typeP_reader()) {
          lastgoals->push(g);
        }
        else {
          oQUERYENVIRONMENTo->best_goal_sequence->push(g);
        }
      }
    }
    { Object* g = NULL;
      Cons* iter_002 = lastgoals->reverse()->the_cons_list;

      while (!nilP(iter_002)) {
        {
          g = iter_002->value;
          iter_002 = iter_002->rest;
        }
        oQUERYENVIRONMENTo->best_goal_sequence->push(((Proposition*)(g)));
      }
    }
  }
}

void reorder_goals(Proposition* andproposition, List* initiallyclosedgoals, List* goalsequence, List* residuegoals) {
  { Vector* arguments = andproposition->arguments;
    int index = 0;

    { Proposition* g = NULL;
      Cons* iter_001 = initiallyclosedgoals->the_cons_list;

      while (!nilP(iter_001)) {
        {
          g = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        arguments->nth_setter(g, index);
        index = index + 1;
      }
    }
    { Proposition* g = NULL;
      Cons* iter_002 = goalsequence->the_cons_list;

      while (!nilP(iter_002)) {
        {
          g = ((Proposition*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        residuegoals->remove(g);
        arguments->nth_setter(g, index);
        index = index + 1;
      }
    }
    { Proposition* g = NULL;
      Cons* iter_003 = residuegoals->the_cons_list;

      while (!nilP(iter_003)) {
        {
          g = ((Proposition*)(iter_003->value));
          iter_003 = iter_003->rest;
        }
        arguments->nth_setter(g, index);
        index = index + 1;
      }
    }
  }
}

void simulate_bind_variable_to_value(Object* formula) {
  { Object* formula_001 = formula;

    if (taxonomy_isaP(formula, SGT_OPTIMIZE_PATTERN_VARIABLE)) {
      { Pattern_Variable* formula = NULL;

        formula = ((Pattern_Variable*)(formula_001));
        if (!argument_boundP(formula)) {
          set_pattern_variable_binding(formula, KWD_OPTIMIZE_BOUND);
        }
      }
    }
    else {
    }
  }
}

void warn_of_unbound_variable_argument(Proposition* proposition) {
  return;
  { Object* arg = NULL;
    Vector* vector_001 = proposition->arguments;
    int index_001 = 0;
    int length_001 = vector_001->length();

    while (index_001 < length_001) {
      {
        arg = vector_001->nth(index_001);
        index_001 = index_001 + 1;
      }
      if (unbound_variableP(arg)) {
        cerr << "Query Bug: Unbound variable " << "`" << arg << "'" << " encountered within proposition" << endl << "   " << "`" << proposition << "'" << " during query simulation.";
      }
    }
  }
}

void simulate_goal_evaluation(Proposition* goal) {
  { Vector* arguments = goal->arguments;
    boolean okP = FALSE;

    { Keyword* test_value_001 = goal->kind;

      if (test_value_001 == KWD_OPTIMIZE_FUNCTION) {
        { boolean choose_value_001 = FALSE;

          if (computed_predicateP(goal)) {
            { boolean alwaysP_001 = TRUE;

              { Object* arg = NULL;
                Iterator* iter_001 = arguments->but_last();

                while (iter_001->nextP()) {
                  {
                    arg = iter_001->value;
                  }
                  if (!argument_boundP(arg)) {
                    alwaysP_001 = FALSE;
                    break;
                  }
                }
              }
              choose_value_001 = alwaysP_001;
            }
          }
          else {
            { boolean foundP_001 = FALSE;

              { Object* arg = NULL;
                Vector* vector_001 = arguments;
                int index_001 = 0;
                int length_001 = vector_001->length();

                while (index_001 < length_001) {
                  {
                    arg = vector_001->nth(index_001);
                    index_001 = index_001 + 1;
                  }
                  if (argument_boundP(arg) &&
                      type_has_backlinksP(logical_type(arg))) {
                    foundP_001 = TRUE;
                    break;
                  }
                }
              }
              choose_value_001 = foundP_001;
            }
          }
          okP = choose_value_001;
        }
      }
      else if (test_value_001 == KWD_OPTIMIZE_PREDICATE) {
        { boolean choose_value_002 = FALSE;

          if (computed_predicateP(goal)) {
            { boolean alwaysP_002 = TRUE;

              { Object* arg = NULL;
                Vector* vector_002 = arguments;
                int index_002 = 0;
                int length_002 = vector_002->length();

                while (index_002 < length_002) {
                  {
                    arg = vector_002->nth(index_002);
                    index_002 = index_002 + 1;
                  }
                  if (!argument_boundP(arg)) {
                    alwaysP_002 = FALSE;
                    break;
                  }
                }
              }
              choose_value_002 = alwaysP_002;
            }
          }
          else {
            { boolean foundP_002 = FALSE;

              { Object* arg = NULL;
                Vector* vector_003 = arguments;
                int index_003 = 0;
                int length_003 = vector_003->length();

                while (index_003 < length_003) {
                  {
                    arg = vector_003->nth(index_003);
                    index_003 = index_003 + 1;
                  }
                  if (argument_boundP(arg) &&
                      type_has_backlinksP(logical_type(arg))) {
                    foundP_002 = TRUE;
                    break;
                  }
                }
              }
              choose_value_002 = foundP_002;
            }
          }
          okP = choose_value_002;
        }
      }
      else if (test_value_001 == KWD_OPTIMIZE_IN) {
        okP = argument_boundP(arguments->second());
      }
      else if (test_value_001 == KWD_OPTIMIZE_EQUIVALENT) {
        okP = argument_boundP(arguments->first()) ||
            argument_boundP(arguments->second());
      }
      else {
        cerr << "`" << test_value_001 << "'" << " is not a valid case option";
      }
    }
    if (!okP) {
      warn_of_unbound_variable_argument(goal);
    }
    { Object* arg = NULL;
      Vector* vector_004 = arguments;
      int index_004 = 0;
      int length_004 = vector_004->length();

      while (index_004 < length_004) {
        {
          arg = vector_004->nth(index_004);
          index_004 = index_004 + 1;
        }
        simulate_bind_variable_to_value(arg);
      }
    }
  }
}

void simulate_and_optimize_argument(Object* formula) {
  { Object* formula_001 = formula;

    if (taxonomy_isaP(formula, SGT_OPTIMIZE_PROPOSITION)) {
      { Proposition* formula = NULL;

        formula = ((Proposition*)(formula_001));
        simulate_and_optimize_query(formula);
      }
    }
    else if (taxonomy_isaP(formula, SGT_OPTIMIZE_DESCRIPTION)) {
      { Description* formula = NULL;

        formula = ((Description*)(formula_001));
        { Boolean_Vector* vectorofzeros = arguments_vector_to_boolean_vector(formula->io_variables);

          optimize_query(formula, vectorofzeros, oQUERYOPTIMIZERCONTROLFRAMEo);
        }
      }
    }
    else {
    }
  }
}

void simulate_and_optimize_query(Proposition* proposition) {
  { Vector* arguments = proposition->arguments;
    Keyword* kind = proposition->kind;

    if (oREVERSEPOLARITYpo) {
      if (kind == KWD_OPTIMIZE_AND) {
        kind = KWD_OPTIMIZE_OR;
      }
      else if (kind == KWD_OPTIMIZE_OR) {
        kind = KWD_OPTIMIZE_AND;
      }
      else if (kind == KWD_OPTIMIZE_IMPLIES) {
        cerr << "REVERSE POLARITY NOT YET IMPLEMENTED FOR :IMPLIES WITHIN " << "QUERY OPTIMIZER";
      }
      else {
      }
    }
    if ((kind == KWD_OPTIMIZE_FUNCTION) ||
        ((kind == KWD_OPTIMIZE_PREDICATE) ||
         ((kind == KWD_OPTIMIZE_IN) ||
          (kind == KWD_OPTIMIZE_EQUIVALENT)))) {
      simulate_goal_evaluation(proposition);
      { Object* arg = NULL;
        Vector* vector_001 = arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            arg = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          simulate_and_optimize_argument(arg);
        }
      }
    }
    else if (kind == KWD_OPTIMIZE_AND) {
      { int choicepointunbindingoffset = simulate_create_choice_point();

        initialize_optimizer_memory(-1);
        optimize_ordering_of_conjuncts(proposition);
        unbind_variables_beginning_at(choicepointunbindingoffset);
      }
      { Object* arg = NULL;
        Vector* vector_002 = arguments;
        int index_002 = 0;
        int length_002 = vector_002->length();

        while (index_002 < length_002) {
          {
            arg = vector_002->nth(index_002);
            index_002 = index_002 + 1;
          }
          simulate_and_optimize_query(((Proposition*)(arg)));
        }
      }
    }
    else if (kind == KWD_OPTIMIZE_OR) {
      { Object* arg = NULL;
        Vector* vector_003 = arguments;
        int index_003 = 0;
        int length_003 = vector_003->length();

        while (index_003 < length_003) {
          {
            arg = vector_003->nth(index_003);
            index_003 = index_003 + 1;
          }
          { int choicepointunbindingoffset = simulate_create_choice_point();

            simulate_and_optimize_query(((Proposition*)(arg)));
            unbind_variables_beginning_at(choicepointunbindingoffset);
          }
        }
      }
    }
    else if (kind == KWD_OPTIMIZE_NOT) {
      { boolean oldreversepolarityP = oREVERSEPOLARITYpo;

        { boolean old_OreversepolarityPO_001 = oREVERSEPOLARITYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oREVERSEPOLARITYpo = !oldreversepolarityP;
                if (oREVERSEPOLARITYpo) {
                  warn_of_unbound_variable_argument(proposition);
                }
                simulate_and_optimize_query(((Proposition*)(arguments->first())));
                oREVERSEPOLARITYpo = old_OreversepolarityPO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oREVERSEPOLARITYpo = old_OreversepolarityPO_001;
              resignal();
            }
          }
        }
      }
    }
    else if (kind == KWD_OPTIMIZE_IMPLIES) {
      warn_of_unbound_variable_argument(proposition);
      { Object* arg = NULL;
        Vector* vector_004 = arguments;
        int index_004 = 0;
        int length_004 = vector_004->length();

        while (index_004 < length_004) {
          {
            arg = vector_004->nth(index_004);
            index_004 = index_004 + 1;
          }
          simulate_and_optimize_argument(arg);
        }
      }
    }
    else if (kind == KWD_OPTIMIZE_EXISTS) {
      simulate_and_optimize_query(((Proposition*)(arguments->first())));
    }
    else if (kind == KWD_OPTIMIZE_FORALL) {
      { int choicepointunbindingoffset = simulate_create_choice_point();

        { Object* arg = NULL;
          Vector* vector_005 = arguments;
          int index_005 = 0;
          int length_005 = vector_005->length();

          while (index_005 < length_005) {
            {
              arg = vector_005->nth(index_005);
              index_005 = index_005 + 1;
            }
            simulate_and_optimize_argument(arg);
          }
        }
        unbind_variables_beginning_at(choicepointunbindingoffset);
      }
    }
    else {
    }
  }
}

void initialize_optimizer_memory(int stacksize) {
  if ((stacksize <= 0) &&
      (oQUERYENVIRONMENTo->optimizer_goal_records != NULL)) {
    stacksize = oQUERYENVIRONMENTo->optimizer_goal_records->length();
  }
  initialize_optimizer_goal_records(stacksize);
  oQUERYENVIRONMENTo->residue_goals->clear();
  oQUERYENVIRONMENTo->best_goal_sequence->clear();
  oQUERYENVIRONMENTo->best_cost = NULL_INTEGER;
}

Control_Frame* read_OqueryoptimizercontrolframeO() {
  return (oQUERYOPTIMIZERCONTROLFRAMEo);
}

Control_Frame* write_OqueryoptimizercontrolframeO(Control_Frame* value) {
  oQUERYOPTIMIZERCONTROLFRAMEo = value;
  return (value);
}

void optimize_query(Description* description, Boolean_Vector* booleanvector, Control_Frame* parentframe) {
  { Control_Frame* frame = create_down_frame(parentframe, NULL);
    int variablescount = description->io_variables->length() + description->internal_variables->length();

    initialize_optimizer_memory(variablescount);
    { Subquery_Frame* subqueryframe = new_top_subquery_frame();

      frame->iterator = subqueryframe;
      subqueryframe->control_frame = frame;
    }
    allocate_block_of_variable_frames(variablescount, frame);
    { Boolean_Wrapper* initiallyboundP = NULL;
      Pattern_Variable* iovar = NULL;
      Vector* vector_001 = description->io_variables;
      int index_001 = 0;
      int length_001 = vector_001->length();
      Boolean_Vector* vector_002 = booleanvector;
      int index_002 = 0;
      int length_002 = vector_002->length();

      while ((index_001 < length_001) &&
          (index_002 < length_002)) {
        {
          iovar = ((Pattern_Variable*)(vector_001->nth(index_001)));
          index_001 = index_001 + 1;
        }
        {
          initiallyboundP = ((Boolean_Wrapper*)(vector_002->nth(index_002)));
          index_002 = index_002 + 1;
        }
        if (initiallyboundP->wrapper_value) {
          simulate_bind_variable_to_value(iovar);
        }
      }
    }
    { Control_Frame* old_OqueryoptimizercontrolframeO_001 = oQUERYOPTIMIZERCONTROLFRAMEo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oQUERYOPTIMIZERCONTROLFRAMEo = frame;
            simulate_and_optimize_query(description->proposition);
            oQUERYOPTIMIZERCONTROLFRAMEo = old_OqueryoptimizercontrolframeO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oQUERYOPTIMIZERCONTROLFRAMEo = old_OqueryoptimizercontrolframeO_001;
          resignal();
        }
      }
    }
    frame->state = KWD_OPTIMIZE_PATTERN;
    unbind_pattern_variables(frame);
    pop_control_frame(oQUERYENVIRONMENTo);
    parentframe->down = NULL;
  }
}

Description* select_optimal_query_pattern(Description* description, Boolean_Vector* booleanvector, Control_Frame* parentframe) {
  { Description* pattern = NULL;
    Key_Value_List* querypatterns = description->query_patterns;

    if (querypatterns != NULL) {
      pattern = ((Description*)(querypatterns->lookup(booleanvector)));
    }
    if (pattern != NULL) {
      return (pattern);
    }
    if (querypatterns == NULL) {
      description->query_patterns = new_key_value_list();
    }
    pattern = copy_description(description, NULL);
    description->query_patterns->insert_at(booleanvector, pattern);
    optimize_query(pattern, booleanvector, parentframe);
    simplify_description(pattern, TRUE);
    return (pattern);
  }
}

boolean read_OpostoptimizationPO() {
  return (oPOSTOPTIMIZATIONpo);
}

boolean write_OpostoptimizationPO(boolean value) {
  oPOSTOPTIMIZATIONpo = value;
  return (value);
}

void simplify_description(Description* description, boolean postoptimizationP) {
  { boolean old_OpostoptimizationPO_001 = oPOSTOPTIMIZATIONpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPOSTOPTIMIZATIONpo = postoptimizationP;
          simplify_proposition(description->proposition);
          oPOSTOPTIMIZATIONpo = old_OpostoptimizationPO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPOSTOPTIMIZATIONpo = old_OpostoptimizationPO_001;
        resignal();
      }
    }
  }
}

Vector* copy_list_to_arguments_vector(List* arguments) {
  { Vector* vector = new_vector(arguments->length());

    { int i = NULL_INTEGER;
      Object* arg = NULL;
      Cons* iter_001 = arguments->the_cons_list;
      int iter_002 = 0;

      while (!nilP(iter_001)) {
        {
          arg = iter_001->value;
          iter_001 = iter_001->rest;
        }
        {
          i = iter_002;
          iter_002 = iter_002 + 1;
        }
        vector->nth_setter(arg, i);
      }
    }
    return (vector);
  }
}

boolean prior_conjunct_cancels_in_propositionP(Proposition* inconjunct, Proposition* priorconjunct) {
  { Keyword* test_value_001 = priorconjunct->kind;

    if (test_value_001 == KWD_OPTIMIZE_IN) {
      return (eqlP(priorconjunct->arguments->first(), inconjunct->arguments->first()) &&
          ((oPOSTOPTIMIZATIONpo ? ((boolean)(collection_implies_collectionP(priorconjunct->arguments->second(), inconjunct->arguments->second()))) : ((boolean)(eqlP(priorconjunct->arguments->second(), inconjunct->arguments->second()))))));
    }
    else if ((test_value_001 == KWD_OPTIMIZE_FUNCTION) ||
        (test_value_001 == KWD_OPTIMIZE_PREDICATE)) {
      { Object* inmember = inconjunct->arguments->first();
        Object* intype = inconjunct->arguments->second();

        { boolean test_value_002 = FALSE;

          test_value_002 = oPOSTOPTIMIZATIONpo;
          if (test_value_002) {
            test_value_002 = typeP(intype);
            if (test_value_002) {
              test_value_002 = surrogateP(((Surrogate*)(priorconjunct->renamed_Operator)));
              if (test_value_002) {
                { boolean foundP_001 = FALSE;

                  { Surrogate* argtype = NULL;
                    Object* arg = NULL;
                    Vector* vector_001 = priorconjunct->arguments;
                    int index_001 = 0;
                    int length_001 = vector_001->length();
                    Iterator* iter_001 = slot_column_types(((Slot*)(((Surrogate*)(priorconjunct->renamed_Operator))->surrogate_value)));

                    while ((index_001 < length_001) &&
                        iter_001->nextP()) {
                      {
                        arg = vector_001->nth(index_001);
                        index_001 = index_001 + 1;
                      }
                      {
                        argtype = ((Surrogate*)(iter_001->value));
                      }
                      if (eqlP(arg, inmember) &&
                          subtype_ofP(argtype, ((Surrogate*)(intype)))) {
                        foundP_001 = TRUE;
                        break;
                      }
                    }
                  }
                  test_value_002 = foundP_001;
                }
              }
            }
          }
          { boolean value_001 = test_value_002;

            return (value_001);
          }
        }
      }
    }
    else {
      return (FALSE);
    }
  }
}

void replace_connective_by_proposition(Proposition* connective, Proposition* proposition) {
  if (!((proposition->dependent_propositions->length() == 1) &&
      (proposition->dependent_propositions->first() == connective))) {
    cerr << "Safety violation: " << "INTERNAL ERROR: `replace-connective-by-proposition' encountered " << "unexpected connective/proposition structure.";
  }
  connective->kind = proposition->kind;
  connective->renamed_Operator = proposition->renamed_Operator;
  connective->arguments = proposition->arguments;
}

void simplify_conjunction(Proposition* andproposition) {
  { List* conjunctslist = new_list();
    Cons* cursor = NULL;

    { Object* arg = NULL;
      Vector* vector_001 = andproposition->arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        conjunctslist->push(((Proposition*)(arg)));
      }
    }
    cursor = conjunctslist->the_cons_list;
    while (cursor->non_emptyP()) {
      { Proposition* conjunct = ((Proposition*)(cursor->value));

        { Keyword* test_value_001 = conjunct->kind;

          if (test_value_001 == KWD_OPTIMIZE_EQUIVALENT) {
            if (eqlP(conjunct->arguments->first()->value_of(), conjunct->arguments->second()->value_of())) {
              { Object* arg = NULL;
                Vector* vector_002 = conjunct->arguments;
                int index_002 = 0;
                int length_002 = vector_002->length();

                while (index_002 < length_002) {
                  {
                    arg = vector_002->nth(index_002);
                    index_002 = index_002 + 1;
                  }
                  remove_dependent_proposition_link(arg, conjunct);
                }
              }
              cursor->value = TRUE_PROPOSITION;
            }
          }
          else if (test_value_001 == KWD_OPTIMIZE_IN) {
            { boolean foundP_001 = FALSE;

              { Proposition* priorconjunct = NULL;
                Cons* iter_001 = cursor->rest;

                while (!nilP(iter_001)) {
                  {
                    priorconjunct = ((Proposition*)(iter_001->value));
                    iter_001 = iter_001->rest;
                  }
                  if (prior_conjunct_cancels_in_propositionP(conjunct, priorconjunct)) {
                    foundP_001 = TRUE;
                    break;
                  }
                }
              }
              if (foundP_001) {
                { Object* arg = NULL;
                  Vector* vector_003 = conjunct->arguments;
                  int index_003 = 0;
                  int length_003 = vector_003->length();

                  while (index_003 < length_003) {
                    {
                      arg = vector_003->nth(index_003);
                      index_003 = index_003 + 1;
                    }
                    remove_dependent_proposition_link(arg, conjunct);
                  }
                }
                cursor->value = TRUE_PROPOSITION;
              }
            }
          }
          else {
          }
        }
      }
      cursor = cursor->rest;
    }
    if (conjunctslist->memberP(TRUE_PROPOSITION)) {
      conjunctslist->remove(TRUE_PROPOSITION);
      conjunctslist->reverse();
      if (conjunctslist->length() == 1) {
        replace_connective_by_proposition(andproposition, ((Proposition*)(conjunctslist->first())));
      }
      else {
        {
          andproposition->arguments = copy_list_to_arguments_vector(conjunctslist);
        }
      }
      conjunctslist->free();
    }
  }
}

void simplify_proposition(Proposition* proposition) {
  { Keyword* test_value_001 = proposition->kind;

    if (test_value_001 == KWD_OPTIMIZE_AND) {
      simplify_conjunction(proposition);
    }
    else {
      { Object* arg = NULL;
        Vector* vector_001 = proposition->arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            arg = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          { Object* arg_001 = arg;

            if (taxonomy_isaP(arg, SGT_OPTIMIZE_PROPOSITION)) {
              { Proposition* arg = NULL;

                arg = ((Proposition*)(arg_001));
                simplify_proposition(arg);
              }
            }
            else if (taxonomy_isaP(arg, SGT_OPTIMIZE_DESCRIPTION)) {
              { Description* arg = NULL;

                arg = ((Description*)(arg_001));
                simplify_description(arg, oPOSTOPTIMIZATIONpo);
              }
            }
            else {
            }
          }
        }
      }
    }
  }
}

Description* copy_description(Description* self, Key_Value_List* parentmapping) {
  { Description* copy = create_description(NULL_INTEGER, self->kind);
    Key_Value_List* mapping = new_key_value_list();

    if (parentmapping != NULL) {
      { Object* v = NULL;
        Object* k = NULL;
        Kv_Cons* iter_001 = parentmapping->the_kv_list;

        while (iter_001 != NULL) {
          k = iter_001->key;
          {
            v = iter_001->value;
            iter_001 = iter_001->rest;
          }
          if (isaP(k, SGT_OPTIMIZE_PATTERN_VARIABLE)) {
            mapping->insert_at(k, v);
          }
        }
      }
    }
    copy->io_variables = copy_variables_vector(self->io_variables, mapping);
    copy->internal_variables = copy_variables_vector(self->internal_variables, mapping);
    copy->proposition = copy_proposition(self->proposition, mapping);
    mapping->free();
    return (copy);
  }
}

Pattern_Variable* copy_variable(Pattern_Variable* self, Key_Value_List* mapping) {
  { Pattern_Variable* copy = ((Pattern_Variable*)(mapping->lookup(self)));

    if (copy != NULL) {
      return (copy);
    }
    copy = new_pattern_variable();
    copy->root_type = self->root_type;
    if ((oPRINTMODEo == KWD_OPTIMIZE_REALISTIC) ||
        (oPRINTMODEo == KWD_OPTIMIZE_FLAT)) {
      set_dynamic_slot_value(copy, SYM_OPTIMIZE_SKOLEM_NAME, ((Symbol*)(dynamic_slot_value(self, SYM_OPTIMIZE_SKOLEM_NAME, NULL))), NULL);
    }
    else {
      { char* copyname = string_concatenate("?CP", ((Symbol*)(dynamic_slot_value(self, SYM_OPTIMIZE_SKOLEM_NAME, NULL)))->symbol_name);

        string_nth_setter(copyname, '_', 3);
        set_dynamic_slot_value(copy, SYM_OPTIMIZE_SKOLEM_NAME, intern_symbol(copyname), NULL);
      }
    }
    { Pattern_Variable* object_001 = copy;
      boolean value_001 = ((Boolean_Wrapper*)(access_in_context(self->not_bottomP, self, FALSE)))->wrapper_value;
      Object* old_value_002 = object_001->not_bottomP;
      Object* new_value_001 = update_in_context(old_value_002, wrap_boolean(value_001), object_001, FALSE);

      if (!cs_valueP(old_value_002)) {
        object_001->not_bottomP = new_value_001;
      }
    }
    { Pattern_Variable* object_002 = copy;
      Object* value_002 = ((Object*)(access_in_context(self->variable_value, self, FALSE)));
      Object* old_value_004 = object_002->variable_value;
      Object* new_value_002 = update_in_context(old_value_004, value_002, object_002, FALSE);

      if (!cs_valueP(old_value_004)) {
        object_002->variable_value = new_value_002;
      }
    }
    copy->bound_to_offset = mapping->length();
    mapping->insert_at(self, copy);
    return (copy);
  }
}

Vector* copy_variables_vector(Vector* self, Key_Value_List* mapping) {
  if (self->emptyP()) {
    return (ZERO_VARIABLES_VECTOR);
  }
  { Vector* copy = new_vector(self->length());

    { int i = NULL_INTEGER;
      Pattern_Variable* vbl = NULL;
      Vector* vector_001 = self;
      int index_001 = 0;
      int length_001 = vector_001->length();
      int iter_001 = 0;

      while (index_001 < length_001) {
        {
          vbl = ((Pattern_Variable*)(vector_001->nth(index_001)));
          index_001 = index_001 + 1;
        }
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        copy->nth_setter(copy_variable(vbl, mapping), i);
      }
    }
    return (copy);
  }
}

Proposition* copy_proposition(Proposition* self, Key_Value_List* mapping) {
  { Proposition* copy = ((Proposition*)(mapping->lookup(self)));

    if (copy != NULL) {
      return (copy);
    }
    copy = new_proposition();
    copy->arguments = new_vector(self->arguments->length());
    copy->kind = self->kind;
    copy->renamed_Operator = copy_proposition_argument(self->renamed_Operator, mapping);
    { Proposition* object_001 = copy;
      Truth_Value* value_001 = ((Truth_Value*)(access_in_context(self->truth_value, self, FALSE)));
      Object* old_value_002 = object_001->truth_value;
      Object* new_value_001 = update_in_context(old_value_002, value_001, object_001, FALSE);

      if (!cs_valueP(old_value_002)) {
        object_001->truth_value = new_value_001;
      }
    }
    if (self->variable_typeP_reader()) {
      set_dynamic_slot_value(copy, SYM_OPTIMIZE_VARIABLE_TYPEp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
    }
    mapping->insert_at(self, copy);
    { Keyword* test_value_001 = self->kind;

      if ((test_value_001 == KWD_OPTIMIZE_FORALL) ||
          (test_value_001 == KWD_OPTIMIZE_EXISTS)) {
        set_dynamic_slot_value(copy, SYM_OPTIMIZE_IO_VARIABLES, copy_variables_vector(((Vector*)(dynamic_slot_value(self, SYM_OPTIMIZE_IO_VARIABLES, NULL))), mapping), NULL);
      }
      else {
      }
    }
    { int i = NULL_INTEGER;
      Object* arg = NULL;
      Vector* vector_001 = self->arguments;
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
        copy->arguments->nth_setter(copy_proposition_argument(arg, mapping), i);
      }
    }
    { Object* argcopy = NULL;
      Vector* vector_002 = copy->arguments;
      int index_002 = 0;
      int length_002 = vector_002->length();

      while (index_002 < length_002) {
        {
          argcopy = vector_002->nth(index_002);
          index_002 = index_002 + 1;
        }
        add_dependent_proposition_link(argcopy, copy);
      }
    }
    { Keyword* test_value_002 = self->kind;

      if (test_value_002 == KWD_OPTIMIZE_FUNCTION) {
        { Object* lastarg = last_argument(self);

          { Object* lastarg_001 = lastarg;

            if (taxonomy_isaP(lastarg, SGT_OPTIMIZE_PATTERN_VARIABLE)) {
              { Pattern_Variable* lastarg = NULL;

                lastarg = ((Pattern_Variable*)(lastarg_001));
                ((Pattern_Variable*)(mapping->lookup(lastarg)))->defining_proposition = copy;
              }
            }
            else {
            }
          }
        }
      }
      else {
      }
    }
    return (copy);
  }
}

Object* copy_proposition_argument(Object* self, Key_Value_List* mapping) {
  { Object* copy = mapping->lookup(self);

    if (copy != NULL) {
      return (copy);
    }
    { Object* self_001 = self;

      if (taxonomy_isaP(self, SGT_OPTIMIZE_PROPOSITION)) {
        { Proposition* self = NULL;

          self = ((Proposition*)(self_001));
          return (copy_proposition(self, mapping));
        }
      }
      else if (taxonomy_isaP(self, SGT_OPTIMIZE_DESCRIPTION)) {
        { Description* self = NULL;

          self = ((Description*)(self_001));
          return (copy_description(self, mapping));
        }
      }
      else if (taxonomy_isaP(self, SGT_OPTIMIZE_PATTERN_VARIABLE)) {
        { Pattern_Variable* self = NULL;

          self = ((Pattern_Variable*)(self_001));
          cerr << "OOPS -- BUG IN 'copy-description'";
        }
      }
      else {
        return (self);
      }
    }
  }
}

List* inherit_as_top_level_proposition(Proposition* proposition) {
  { Key_Value_List* mapping = new_key_value_list();
    List* resultlist = new_list();

    { Keyword* test_value_001 = proposition->kind;

      if (test_value_001 == KWD_OPTIMIZE_AND) {
        { Object* arg = NULL;
          Vector* vector_001 = proposition->arguments;
          int index_001 = 0;
          int length_001 = vector_001->length();

          while (index_001 < length_001) {
            {
              arg = vector_001->nth(index_001);
              index_001 = index_001 + 1;
            }
            resultlist->push(inherit_proposition(((Proposition*)(arg)), mapping));
          }
        }
      }
      else {
        resultlist->push(inherit_proposition(proposition, mapping));
      }
    }
    mapping->free();
    return (resultlist);
  }
}

Pattern_Variable* inherit_variable(Pattern_Variable* self, Key_Value_List* mapping) {
  { Pattern_Variable* copy = ((Pattern_Variable*)(mapping->lookup(self)));

    if (copy != NULL) {
      return (copy);
    }
    copy = ((Pattern_Variable*)(bound_to(self)));
    if (!(copy != NULL)) {
      cerr << "Safety violation: " << "INTERNAL ERROR: `inherit-variable' encountered NULL binding.";
    }
    mapping->insert_at(self, copy);
    if (self->defining_proposition != NULL) {
      { Pattern_Variable* copy_001 = copy;

        if (taxonomy_isaP(copy, SGT_OPTIMIZE_SKOLEM)) {
          { Skolem* copy = NULL;

            copy = ((Skolem*)(copy_001));
            if (!(copy->defining_proposition == NULL)) {
              cerr << "Safety violation: " << "INTERNAL ERROR: `inherit-variable' encountered " << "unexpected defining proposition on variable copy.";
            }
          }
        }
        else {
        }
      }
    }
    return (copy);
  }
}

Vector* inherit_variables_vector(Vector* self, Key_Value_List* mapping) {
  if (self->emptyP()) {
    return (ZERO_VARIABLES_VECTOR);
  }
  { Vector* copy = new_vector(self->length());

    { int i = NULL_INTEGER;
      Pattern_Variable* vbl = NULL;
      Vector* vector_001 = self;
      int index_001 = 0;
      int length_001 = vector_001->length();
      int iter_001 = 0;

      while (index_001 < length_001) {
        {
          vbl = ((Pattern_Variable*)(vector_001->nth(index_001)));
          index_001 = index_001 + 1;
        }
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        copy->nth_setter(inherit_variable(vbl, mapping), i);
      }
    }
    return (copy);
  }
}

Proposition* inherit_function_proposition(Proposition* self, Key_Value_List* mapping, boolean assertP) {
  { Surrogate* slotref = ((Surrogate*)(self->renamed_Operator));
    Cons* inputarguments = NIL;
    Proposition* functioncopy = NULL;

    { Object* arg = NULL;
      Iterator* iter_001 = self->arguments->but_last();
      Cons* collect_001 = NULL;

      while (iter_001->nextP()) {
        {
          arg = iter_001->value;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(arg, NIL);
            if (nilP(inputarguments)) {
              inputarguments = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(inputarguments, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(arg, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    functioncopy = ((Proposition*)(finish_evaluating_function_term(slotref, inputarguments)));
    free_cons_list(inputarguments);
    if (assertP) {
      {
        equate_values(function_representative(functioncopy), bound_to(((Pattern_Variable*)(last_argument(self)))));
        return (NULL);
      }
    }
    else {
      { Proposition* copy = finish_building_equivalence_proposition(function_representative(functioncopy), bound_to(((Pattern_Variable*)(last_argument(self)))));

        mapping->insert_at(self, copy);
        return (copy);
      }
    }
  }
}

Proposition* inherit_proposition(Proposition* self, Key_Value_List* mapping) {
  { Proposition* copy = ((Proposition*)(mapping->lookup(self)));

    if (copy != NULL) {
      return (copy);
    }
    else if (self->kind == KWD_OPTIMIZE_FUNCTION) {
      return (inherit_function_proposition(self, mapping, FALSE));
    }
    copy = new_proposition();
    copy->arguments = new_vector(self->arguments->length());
    copy->kind = self->kind;
    if (self->variable_typeP_reader()) {
      set_dynamic_slot_value(copy, SYM_OPTIMIZE_VARIABLE_TYPEp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
    }
    mapping->insert_at(self, copy);
    copy->renamed_Operator = (isaP(self->renamed_Operator, SGT_OPTIMIZE_SURROGATE) ? ((Object*)(self->renamed_Operator)) : ((Object*)(inherit_variable(((Pattern_Variable*)(self->renamed_Operator)), mapping))));
    { int i = NULL_INTEGER;
      Object* arg = NULL;
      Vector* vector_001 = self->arguments;
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
        copy->arguments->nth_setter(inherit_proposition_argument(arg, mapping), i);
      }
    }
    { Proposition* copyorduplicate = fasten_down_proposition(copy);

      if ((self->kind == KWD_OPTIMIZE_FUNCTION) &&
          (copyorduplicate == copy)) {
        { Pattern_Variable* argcopy = ((Pattern_Variable*)(mapping->lookup(last_argument(self))));

          if (!((argcopy->defining_proposition == NULL) ||
              (argcopy->defining_proposition == copyorduplicate))) {
            cerr << "Safety violation: " << "INTERNAL ERROR: `inherit-proposition' needs to point " << "at two defining propositions using a single skolem.";
          }
          argcopy->defining_proposition = copyorduplicate;
        }
      }
      return (copyorduplicate);
    }
  }
}

Object* inherit_proposition_argument(Object* self, Key_Value_List* mapping) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_OPTIMIZE_PROPOSITION)) {
      { Proposition* self = NULL;

        self = ((Proposition*)(self_001));
        return (inherit_proposition(self, mapping));
      }
    }
    else if (taxonomy_isaP(self, SGT_OPTIMIZE_DESCRIPTION)) {
      { Description* self = NULL;

        self = ((Description*)(self_001));
        return (copy_description(self, mapping));
      }
    }
    else if (taxonomy_isaP(self, SGT_OPTIMIZE_PATTERN_VARIABLE)) {
      { Pattern_Variable* self = NULL;

        self = ((Pattern_Variable*)(self_001));
        return (inherit_variable(self, mapping));
      }
    }
    else if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        return (self->surrogate_value);
      }
    }
    else {
      return (self);
    }
  }
}

void startup_optimize() {
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
            SYM_OPTIMIZE_GENERATOR_GOALS = ((Symbol*)(intern_rigid_symbol_wrt_module("GENERATOR-GOALS", NULL, 0)));
            SYM_OPTIMIZE_OTHER_GOALS = ((Symbol*)(intern_rigid_symbol_wrt_module("OTHER-GOALS", NULL, 0)));
            SGT_OPTIMIZE_GOAL_RECORD = ((Surrogate*)(intern_rigid_symbol_wrt_module("GOAL-RECORD", NULL, 1)));
            SGT_OPTIMIZE_PATTERN_VARIABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("PATTERN-VARIABLE", NULL, 1)));
            SGT_OPTIMIZE_PROPOSITION = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPOSITION", NULL, 1)));
            KWD_OPTIMIZE_OR = ((Keyword*)(intern_rigid_symbol_wrt_module("OR", NULL, 2)));
            SYM_OPTIMIZE_PERMUTATION_TABLE = ((Symbol*)(intern_rigid_symbol_wrt_module("PERMUTATION-TABLE", NULL, 0)));
            SGT_OPTIMIZE_LITERAL = ((Surrogate*)(intern_rigid_symbol_wrt_module("LITERAL", string_get_module("/STELLA", TRUE), 1)));
            SGT_OPTIMIZE_DESCRIPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 1)));
            SYM_OPTIMIZE_oDISTRIBUTEDOPENGOALpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*DISTRIBUTEDOPENGOAL?*", NULL, 0)));
            KWD_OPTIMIZE_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            KWD_OPTIMIZE_EQUIVALENT = ((Keyword*)(intern_rigid_symbol_wrt_module("EQUIVALENT", NULL, 2)));
            KWD_OPTIMIZE_IN = ((Keyword*)(intern_rigid_symbol_wrt_module("IN", NULL, 2)));
            KWD_OPTIMIZE_PREDICATE = ((Keyword*)(intern_rigid_symbol_wrt_module("PREDICATE", NULL, 2)));
            KWD_OPTIMIZE_NOT = ((Keyword*)(intern_rigid_symbol_wrt_module("NOT", NULL, 2)));
            SYM_OPTIMIZE_UNIQUENESSVECTORS = ((Symbol*)(intern_rigid_symbol_wrt_module("UNIQUENESSVECTORS", NULL, 0)));
            SYM_OPTIMIZE_INDEXING_VECTOR = ((Symbol*)(intern_rigid_symbol_wrt_module("INDEXING-VECTOR", NULL, 0)));
            SYM_OPTIMIZE_INVERSE = ((Symbol*)(intern_rigid_symbol_wrt_module("INVERSE", string_get_module("/STELLA", TRUE), 0)));
            SYM_OPTIMIZE_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 0)));
            SYM_OPTIMIZE_ESTIMATED_CARDINALITY = ((Symbol*)(intern_rigid_symbol_wrt_module("ESTIMATED-CARDINALITY", NULL, 0)));
            SGT_OPTIMIZE_LITERAL_WRAPPER = ((Surrogate*)(intern_rigid_symbol_wrt_module("LITERAL-WRAPPER", string_get_module("/STELLA", TRUE), 1)));
            KWD_OPTIMIZE_OPEN = ((Keyword*)(intern_rigid_symbol_wrt_module("OPEN", NULL, 2)));
            SGT_OPTIMIZE_COLLECTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION", string_get_module("/STELLA", TRUE), 1)));
            KWD_OPTIMIZE_FORALL = ((Keyword*)(intern_rigid_symbol_wrt_module("FORALL", NULL, 2)));
            KWD_OPTIMIZE_BOUND = ((Keyword*)(intern_rigid_symbol_wrt_module("BOUND", NULL, 2)));
            KWD_OPTIMIZE_AND = ((Keyword*)(intern_rigid_symbol_wrt_module("AND", NULL, 2)));
            KWD_OPTIMIZE_IMPLIES = ((Keyword*)(intern_rigid_symbol_wrt_module("IMPLIES", NULL, 2)));
            KWD_OPTIMIZE_EXISTS = ((Keyword*)(intern_rigid_symbol_wrt_module("EXISTS", NULL, 2)));
            SYM_OPTIMIZE_oQUERYOPTIMIZERCONTROLFRAMEo = ((Symbol*)(intern_rigid_symbol_wrt_module("*QUERYOPTIMIZERCONTROLFRAME*", NULL, 0)));
            KWD_OPTIMIZE_PATTERN = ((Keyword*)(intern_rigid_symbol_wrt_module("PATTERN", NULL, 2)));
            SYM_OPTIMIZE_oPOSTOPTIMIZATIONpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*POSTOPTIMIZATION?*", NULL, 0)));
            SYM_OPTIMIZE_ENTITY_MAPPING = ((Symbol*)(intern_rigid_symbol_wrt_module("ENTITY-MAPPING", NULL, 0)));
            KWD_OPTIMIZE_REALISTIC = ((Keyword*)(intern_rigid_symbol_wrt_module("REALISTIC", NULL, 2)));
            KWD_OPTIMIZE_FLAT = ((Keyword*)(intern_rigid_symbol_wrt_module("FLAT", NULL, 2)));
            SYM_OPTIMIZE_SKOLEM_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SKOLEM-NAME", NULL, 0)));
            SYM_OPTIMIZE_VARIABLE_TYPEp = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-TYPE?", NULL, 0)));
            SYM_OPTIMIZE_IO_VARIABLES = ((Symbol*)(intern_rigid_symbol_wrt_module("IO-VARIABLES", NULL, 0)));
            SGT_OPTIMIZE_SKOLEM = ((Surrogate*)(intern_rigid_symbol_wrt_module("SKOLEM", NULL, 1)));
            SGT_OPTIMIZE_SURROGATE = ((Surrogate*)(intern_rigid_symbol_wrt_module("SURROGATE", string_get_module("/STELLA", TRUE), 1)));
          }
          if (current_startup_time_phaseP(4)) {
            V_0_0 = zero_one_list_to_boolean_vector(list(2, integer_wrap_literal(0), integer_wrap_literal(0)));
            V_1_0 = zero_one_list_to_boolean_vector(list(2, integer_wrap_literal(1), integer_wrap_literal(0)));
            V_0_1 = zero_one_list_to_boolean_vector(list(2, integer_wrap_literal(0), integer_wrap_literal(1)));
            V_1_1 = zero_one_list_to_boolean_vector(list(2, integer_wrap_literal(1), integer_wrap_literal(1)));
            V_1_0_AND_V_0_1 = list(2, V_1_0, V_0_1);
            V_1_0_SINGLETON = list(1, V_1_0);
            V_0_1_SINGLETON = list(1, V_0_1);
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("GOAL-RECORD", "(DEFCLASS GOAL-RECORD (STANDARD-OBJECT) :SLOTS ((GENERATOR-GOALS :TYPE (LIST OF PROPOSITION) :ALLOCATION :EMBEDDED) (OTHER-GOALS :TYPE (LIST OF PROPOSITION) :ALLOCATION :EMBEDDED)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_goal_record));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_goal_record_slot_value));
            }
            define_stella_type_from_stringified_source("(DEFTYPE ENTITY-MAPPING (KEY-VALUE-LIST OF OBJECT OBJECT) :DOCUMENTATION \"Used to keep track of already copied variables\nand propositions within a 'copy-description' procedure.\")");
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("VARIABLE-BOUND?", "PATTERN-VARIABLE", "(DEFUN (VARIABLE-BOUND? BOOLEAN) ((VARIABLE PATTERN-VARIABLE)))");

              method->function_code = ((cpp_function_code)(&variable_boundP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ARGUMENT-BOUND?", "OBJECT", "(DEFUN (ARGUMENT-BOUND? BOOLEAN) ((ARGUMENT OBJECT)))");

              method->function_code = ((cpp_function_code)(&argument_boundP));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNBOUND-VARIABLE?", "OBJECT", "(DEFUN (UNBOUND-VARIABLE? BOOLEAN) ((ARGUMENT OBJECT)))");

              method->function_code = ((cpp_function_code)(&unbound_variableP));
            }
            { Method_Slot* method = define_method_from_stringified_source("HAS-DISJUNCTION?", "PROPOSITION", "(DEFUN (HAS-DISJUNCTION? BOOLEAN) ((GOAL PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&has_disjunctionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MODAL-GOAL?", "PROPOSITION", "(DEFUN (MODAL-GOAL? BOOLEAN) ((GOAL PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&modal_goalP));
            }
            { Method_Slot* method = define_method_from_stringified_source("HAS-INVERSIONS?", "PROPOSITION", "(DEFUN (HAS-INVERSIONS? BOOLEAN) ((GOAL PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&has_inversionsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTED-PREDICATE?", "PROPOSITION", "(DEFUN (COMPUTED-PREDICATE? BOOLEAN) ((PREDICATEPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&computed_predicateP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMULATE-CREATE-CHOICE-POINT", NULL, "(DEFUN (SIMULATE-CREATE-CHOICE-POINT INTEGER) ())");

              method->function_code = ((cpp_function_code)(&simulate_create_choice_point));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLASS-INHERITS-ENUMERATED-EXTENSION?", "CLASS", "(DEFUN (CLASS-INHERITS-ENUMERATED-EXTENSION? BOOLEAN) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&class_inherits_enumerated_extensionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("GENERATOR-COLLECTION?", "OBJECT", "(DEFUN (GENERATOR-COLLECTION? BOOLEAN) ((COLLECTION OBJECT)))");

              method->function_code = ((cpp_function_code)(&generator_collectionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-OPTIMIZER-GOAL-RECORDS", "INTEGER", "(DEFUN INITIALIZE-OPTIMIZER-GOAL-RECORDS ((SIZE INTEGER)))");

              method->function_code = ((cpp_function_code)(&initialize_optimizer_goal_records));
            }
            { Method_Slot* method = define_method_from_stringified_source("GOAL-RECORD", "PATTERN-VARIABLE", "(DEFUN (GOAL-RECORD GOAL-RECORD) ((VARIABLE PATTERN-VARIABLE)))");

              method->function_code = ((cpp_function_code)(&goal_record));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-DISTRIBUTE-GOAL", "OBJECT", "(DEFUN HELP-DISTRIBUTE-GOAL ((ARGUMENT OBJECT) (PARENTGOAL PROPOSITION) (GENERATOR? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&help_distribute_goal));
            }
            { Method_Slot* method = define_method_from_stringified_source("DISTRIBUTE-OPEN-GOAL", "PROPOSITION", "(DEFUN DISTRIBUTE-OPEN-GOAL ((GOAL PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&distribute_open_goal));
            }
            define_external_slot_from_stringified_source("(DEFSLOT SLOT UNIQUENESSVECTORS :TYPE (LIST OF BOOLEAN-VECTOR) :DOCUMENTATION \"Caches a list of vectors representing keys\nfor the slot/relation.\" :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT SLOT INDEXING-VECTOR :TYPE BOOLEAN-VECTOR :DOCUMENTATION \"Caches a vector indicating which arguments\nof a slot/relation have backlinks to referencing propositions.\" :ALLOCATION :DYNAMIC)");
            { Method_Slot* method = define_method_from_stringified_source("GET-UNIQUENESS-VECTORS", "SLOT", "(DEFMETHOD (GET-UNIQUENESS-VECTORS (LIST OF BOOLEAN-VECTOR)) ((SELF SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::get_uniqueness_vectors));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-INDEXING-VECTOR", "SLOT", "(DEFMETHOD (GET-INDEXING-VECTOR BOOLEAN-VECTOR) ((SELF SLOT)))");

              method->method_code = ((cpp_method_code)(&Slot::get_indexing_vector));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-UNIQUENESS-VECTORS", "STORAGE-SLOT", "(DEFMETHOD (GET-UNIQUENESS-VECTORS (LIST OF BOOLEAN-VECTOR)) ((SELF STORAGE-SLOT)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::get_uniqueness_vectors));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-INDEXING-VECTOR", "STORAGE-SLOT", "(DEFMETHOD (GET-INDEXING-VECTOR BOOLEAN-VECTOR) ((SELF STORAGE-SLOT)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::get_indexing_vector));
            }
            define_external_slot_from_stringified_source("(DEFSLOT DESCRIPTION ESTIMATED-CARDINALITY :TYPE INTEGER :DOCUMENTATION \"Stores an estimate of the current number of instances\nasserted to belong to a class or its subclasses.  The estimate\nmay be out of date, or may have been truncated by a thresholding\noperation.\" :ALLOCATION :DYNAMIC)");
            { Method_Slot* method = define_method_from_stringified_source("ESTIMATE-CARDINALITY-OF-CLASS-EXTENSION", "CLASS", "(DEFUN (ESTIMATE-CARDINALITY-OF-CLASS-EXTENSION INTEGER) ((CLASS CLASS)))");

              method->function_code = ((cpp_function_code)(&estimate_cardinality_of_class_extension));
            }
            { Method_Slot* method = define_method_from_stringified_source("ESTIMATE-PREDICATE-GOAL-COST", "PROPOSITION", "(DEFUN (ESTIMATE-PREDICATE-GOAL-COST INTEGER) ((GOAL PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&estimate_predicate_goal_cost));
            }
            { Method_Slot* method = define_method_from_stringified_source("ESTIMATE-GOAL-COST", "PROPOSITION", "(DEFUN (ESTIMATE-GOAL-COST INTEGER) ((GOAL PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&estimate_goal_cost));
            }
            { Method_Slot* method = define_method_from_stringified_source("CHEAPEST-GENERATOR-GOAL", "PATTERN-VARIABLE", "(DEFUN (CHEAPEST-GENERATOR-GOAL PROPOSITION INTEGER) ((VARIABLE PATTERN-VARIABLE)))");

              method->function_code = ((cpp_function_code)(&cheapest_generator_goal));
            }
            { Method_Slot* method = define_method_from_stringified_source("PROPAGATE-SINGLE-VALUED-CONSTRAINTS", "PROPOSITION", "(DEFUN PROPAGATE-SINGLE-VALUED-CONSTRAINTS ((GOAL PROPOSITION) (GOALSEQUENCE (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&propagate_single_valued_constraints));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-CLOSED-GOALS", "LIST", "(DEFUN COLLECT-CLOSED-GOALS ((GOALS (LIST OF PROPOSITION)) (GOALSEQUENCE (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&collect_closed_goals));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMULATE-BIND-VARIABLE-AND-PROPAGATE-CONSTRAINTS", "PATTERN-VARIABLE", "(DEFUN SIMULATE-BIND-VARIABLE-AND-PROPAGATE-CONSTRAINTS ((VARIABLE PATTERN-VARIABLE) (GOALSEQUENCE (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&simulate_bind_variable_and_propagate_constraints));
            }
            { Method_Slot* method = define_method_from_stringified_source("BIND-ALL-VARIABLES-IN-GENERATOR-GOAL", "PROPOSITION", "(DEFUN BIND-ALL-VARIABLES-IN-GENERATOR-GOAL ((GOAL PROPOSITION) (GOALSEQUENCE (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&bind_all_variables_in_generator_goal));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-OPTIMAL-OPEN-GOAL-ORDERING", "LIST", "(DEFUN COMPUTE-OPTIMAL-OPEN-GOAL-ORDERING ((OPTIMIZERVARIABLES (LIST OF PATTERN-VARIABLE)) (NUMBEROFOPENGOALS INTEGER) (GOALSEQUENCE (LIST OF PROPOSITION)) (COST INTEGER)))");

              method->function_code = ((cpp_function_code)(&compute_optimal_open_goal_ordering));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECT-OPTIMIZER-VARIABLES", "PROPOSITION", "(DEFUN COLLECT-OPTIMIZER-VARIABLES ((PROPOSITION PROPOSITION) (COLLECTION LIST)))");

              method->function_code = ((cpp_function_code)(&collect_optimizer_variables));
            }
            { Method_Slot* method = define_method_from_stringified_source("OPTIMIZE-ORDERING-OF-CONJUNCTS", "PROPOSITION", "(DEFUN OPTIMIZE-ORDERING-OF-CONJUNCTS ((ANDPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&optimize_ordering_of_conjuncts));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-BACKUP-OPEN-GOAL-ORDERING", "LIST", "(DEFUN COMPUTE-BACKUP-OPEN-GOAL-ORDERING ((GOALSEQUENCE (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&compute_backup_open_goal_ordering));
            }
            { Method_Slot* method = define_method_from_stringified_source("REORDER-GOALS", "PROPOSITION", "(DEFUN REORDER-GOALS ((ANDPROPOSITION PROPOSITION) (INITIALLYCLOSEDGOALS (LIST OF PROPOSITION)) (GOALSEQUENCE (LIST OF PROPOSITION)) (RESIDUEGOALS (LIST OF PROPOSITION))))");

              method->function_code = ((cpp_function_code)(&reorder_goals));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMULATE-BIND-VARIABLE-TO-VALUE", "OBJECT", "(DEFUN SIMULATE-BIND-VARIABLE-TO-VALUE ((FORMULA OBJECT)))");

              method->function_code = ((cpp_function_code)(&simulate_bind_variable_to_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("WARN-OF-UNBOUND-VARIABLE-ARGUMENT", "PROPOSITION", "(DEFUN WARN-OF-UNBOUND-VARIABLE-ARGUMENT ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&warn_of_unbound_variable_argument));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMULATE-GOAL-EVALUATION", "PROPOSITION", "(DEFUN SIMULATE-GOAL-EVALUATION ((GOAL PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&simulate_goal_evaluation));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMULATE-AND-OPTIMIZE-ARGUMENT", "OBJECT", "(DEFUN SIMULATE-AND-OPTIMIZE-ARGUMENT ((FORMULA OBJECT)))");

              method->function_code = ((cpp_function_code)(&simulate_and_optimize_argument));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMULATE-AND-OPTIMIZE-QUERY", "PROPOSITION", "(DEFUN SIMULATE-AND-OPTIMIZE-QUERY ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&simulate_and_optimize_query));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-OPTIMIZER-MEMORY", "INTEGER", "(DEFUN INITIALIZE-OPTIMIZER-MEMORY ((STACKSIZE INTEGER)))");

              method->function_code = ((cpp_function_code)(&initialize_optimizer_memory));
            }
            { Method_Slot* method = define_method_from_stringified_source("OPTIMIZE-QUERY", "DESCRIPTION", "(DEFUN OPTIMIZE-QUERY ((DESCRIPTION DESCRIPTION) (BOOLEANVECTOR BOOLEAN-VECTOR) (PARENTFRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&optimize_query));
            }
            { Method_Slot* method = define_method_from_stringified_source("SELECT-OPTIMAL-QUERY-PATTERN", "DESCRIPTION", "(DEFUN (SELECT-OPTIMAL-QUERY-PATTERN DESCRIPTION) ((DESCRIPTION DESCRIPTION) (BOOLEANVECTOR BOOLEAN-VECTOR) (PARENTFRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&select_optimal_query_pattern));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMPLIFY-DESCRIPTION", "DESCRIPTION", "(DEFUN SIMPLIFY-DESCRIPTION ((DESCRIPTION DESCRIPTION) (POSTOPTIMIZATION? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&simplify_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-LIST-TO-ARGUMENTS-VECTOR", "LIST", "(DEFUN (COPY-LIST-TO-ARGUMENTS-VECTOR ARGUMENTS-VECTOR) ((ARGUMENTS LIST)))");

              method->function_code = ((cpp_function_code)(&copy_list_to_arguments_vector));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRIOR-CONJUNCT-CANCELS-IN-PROPOSITION?", "PROPOSITION", "(DEFUN (PRIOR-CONJUNCT-CANCELS-IN-PROPOSITION? BOOLEAN) ((INCONJUNCT PROPOSITION) (PRIORCONJUNCT PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&prior_conjunct_cancels_in_propositionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("REPLACE-CONNECTIVE-BY-PROPOSITION", "PROPOSITION", "(DEFUN REPLACE-CONNECTIVE-BY-PROPOSITION ((CONNECTIVE PROPOSITION) (PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&replace_connective_by_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMPLIFY-CONJUNCTION", "PROPOSITION", "(DEFUN SIMPLIFY-CONJUNCTION ((ANDPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&simplify_conjunction));
            }
            { Method_Slot* method = define_method_from_stringified_source("SIMPLIFY-PROPOSITION", "PROPOSITION", "(DEFUN SIMPLIFY-PROPOSITION ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&simplify_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-DESCRIPTION", "DESCRIPTION", "(DEFUN (COPY-DESCRIPTION DESCRIPTION) ((SELF DESCRIPTION) (PARENTMAPPING ENTITY-MAPPING)))");

              method->function_code = ((cpp_function_code)(&copy_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-VARIABLE", "PATTERN-VARIABLE", "(DEFUN (COPY-VARIABLE PATTERN-VARIABLE) ((SELF PATTERN-VARIABLE) (MAPPING ENTITY-MAPPING)))");

              method->function_code = ((cpp_function_code)(&copy_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-VARIABLES-VECTOR", "VECTOR", "(DEFUN (COPY-VARIABLES-VECTOR VARIABLES-VECTOR) ((SELF VARIABLES-VECTOR) (MAPPING ENTITY-MAPPING)))");

              method->function_code = ((cpp_function_code)(&copy_variables_vector));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-PROPOSITION", "PROPOSITION", "(DEFUN (COPY-PROPOSITION PROPOSITION) ((SELF PROPOSITION) (MAPPING ENTITY-MAPPING)))");

              method->function_code = ((cpp_function_code)(&copy_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-PROPOSITION-ARGUMENT", "OBJECT", "(DEFUN (COPY-PROPOSITION-ARGUMENT OBJECT) ((SELF OBJECT) (MAPPING ENTITY-MAPPING)))");

              method->function_code = ((cpp_function_code)(&copy_proposition_argument));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-AS-TOP-LEVEL-PROPOSITION", "PROPOSITION", "(DEFUN (INHERIT-AS-TOP-LEVEL-PROPOSITION (LIST OF PROPOSITION)) ((PROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&inherit_as_top_level_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-VARIABLE", "PATTERN-VARIABLE", "(DEFUN (INHERIT-VARIABLE PATTERN-VARIABLE) ((SELF PATTERN-VARIABLE) (MAPPING ENTITY-MAPPING)))");

              method->function_code = ((cpp_function_code)(&inherit_variable));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-VARIABLES-VECTOR", "VECTOR", "(DEFUN (INHERIT-VARIABLES-VECTOR VARIABLES-VECTOR) ((SELF VARIABLES-VECTOR) (MAPPING ENTITY-MAPPING)))");

              method->function_code = ((cpp_function_code)(&inherit_variables_vector));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-FUNCTION-PROPOSITION", "PROPOSITION", "(DEFUN (INHERIT-FUNCTION-PROPOSITION PROPOSITION) ((SELF PROPOSITION) (MAPPING ENTITY-MAPPING) (ASSERT? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&inherit_function_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-PROPOSITION", "PROPOSITION", "(DEFUN (INHERIT-PROPOSITION PROPOSITION) ((SELF PROPOSITION) (MAPPING ENTITY-MAPPING)))");

              method->function_code = ((cpp_function_code)(&inherit_proposition));
            }
            { Method_Slot* method = define_method_from_stringified_source("INHERIT-PROPOSITION-ARGUMENT", "OBJECT", "(DEFUN (INHERIT-PROPOSITION-ARGUMENT OBJECT) ((SELF OBJECT) (MAPPING ENTITY-MAPPING)))");

              method->function_code = ((cpp_function_code)(&inherit_proposition_argument));
            }
            define_method_from_stringified_source("STARTUP-OPTIMIZE", NULL, "(DEFUN STARTUP-OPTIMIZE ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *DISTRIBUTEDOPENGOAL?* BOOLEAN :DOCUMENTATION \"Used by 'distribute-open-goal' to signal that\na goal was distributed by 'help-distribute-goal'.\")");
            { Global_Variable* global = SYM_OPTIMIZE_oDISTRIBUTEDOPENGOALpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OdistributedopengoalPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OdistributedopengoalPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT V-0-0 BOOLEAN-VECTOR (ZERO-ONE-LIST-TO-BOOLEAN-VECTOR (LIST 0 0)))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT V-1-0 BOOLEAN-VECTOR (ZERO-ONE-LIST-TO-BOOLEAN-VECTOR (LIST 1 0)))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT V-0-1 BOOLEAN-VECTOR (ZERO-ONE-LIST-TO-BOOLEAN-VECTOR (LIST 0 1)))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT V-1-1 BOOLEAN-VECTOR (ZERO-ONE-LIST-TO-BOOLEAN-VECTOR (LIST 1 1)))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT V-1-0-AND-V-0-1 (LIST OF BOOLEAN-VECTOR) (LIST V-1-0 V-0-1))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT V-1-0-SINGLETON (LIST OF BOOLEAN-VECTOR) (LIST V-1-0))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT V-0-1-SINGLETON (LIST OF BOOLEAN-VECTOR) (LIST V-0-1))");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT ESTIMATED-SLOT-VALUE-COLLECTION-SIZE INTEGER 4 :DOCUMENTATION \"Estimate of the average size of a collection\nrepresenting the fillers of a slot.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT ESTIMATED-NUMBER-OF-PREDICATE-BINDINGS INTEGER 6 :DOCUMENTATION \"Very crude estimate of the number of stored propositions\nthat will match a predicate at least one of whose arguments are bound.\nChosen to be larger than ESTIMATED-SLOT-VALUE-COLLECTION-SIZE.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *QUERYOPTIMIZERCONTROLFRAME* CONTROL-FRAME :DOCUMENTATION \"Keeps track of last control frame allocated by\nthe query optimizer.  Used by recursive invocations of the optimizer.\")");
            { Global_Variable* global = SYM_OPTIMIZE_oQUERYOPTIMIZERCONTROLFRAMEo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OqueryoptimizercontrolframeO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OqueryoptimizercontrolframeO));
            }
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *POSTOPTIMIZATION?* BOOLEAN FALSE :DOCUMENTATION \"Used by 'simplify-description' to permit application\nof order-dependent optimizations.\")");
            { Global_Variable* global = SYM_OPTIMIZE_oPOSTOPTIMIZATIONpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OpostoptimizationPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OpostoptimizationPO));
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

