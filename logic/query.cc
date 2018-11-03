// query.cc

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

Symbol* SYM_QUERY_QUERY_ENVIRONMENT = NULL;

Symbol* SYM_QUERY_EXTERNAL_VARIABLES = NULL;

Symbol* SYM_QUERY_SOLUTIONS = NULL;

Symbol* SYM_QUERY_EXHAUSTEDp = NULL;

Surrogate* SGT_QUERY_QUERY_ITERATOR = NULL;

Symbol* SYM_QUERY_STATE = NULL;

Symbol* SYM_QUERY_PHASE = NULL;

Symbol* SYM_QUERY_PROPOSITION = NULL;

Symbol* SYM_QUERY_REVERSE_POLARITYp = NULL;

Symbol* SYM_QUERY_UP = NULL;

Symbol* SYM_QUERY_DOWN = NULL;

Symbol* SYM_QUERY_BACK = NULL;

Symbol* SYM_QUERY_ARGUMENT_CURSOR = NULL;

Symbol* SYM_QUERY_ITERATOR = NULL;

Symbol* SYM_QUERY_SUBQUERY_FRAME = NULL;

Symbol* SYM_QUERY_PARENT_PATTERN_FRAME = NULL;

Symbol* SYM_QUERY_GOAL_CACHE = NULL;

Symbol* SYM_QUERY_PARTIAL_MATCH_FRAME = NULL;

Symbol* SYM_QUERY_DEBUG_FRAME_OFFSET = NULL;

Symbol* SYM_QUERY_DEBUG_DEPTH = NULL;

Symbol* SYM_QUERY_CHOICE_POINT_UNBINDING_OFFSET = NULL;

Surrogate* SGT_QUERY_CONTROL_FRAME = NULL;

Symbol* SYM_QUERY_KIND_OF_GOAL = NULL;

Symbol* SYM_QUERY_STRATEGY_PRIORITY = NULL;

Symbol* SYM_QUERY_STRATEGY_PROCEDURE = NULL;

Surrogate* SGT_QUERY_GOAL_STRATEGY = NULL;

List* oRECYCLED_QUERY_ENVIRONMENT_So = NULL;

Symbol* SYM_QUERY_CONTROL_FRAME_STACK = NULL;

Symbol* SYM_QUERY_CONTROL_FRAME_OFFSET_LIMIT = NULL;

Symbol* SYM_QUERY_TOP_CONTROL_FRAME_OFFSET = NULL;

Symbol* SYM_QUERY_VARIABLE_FRAME_STACK = NULL;

Symbol* SYM_QUERY_VARIABLE_FRAME_OFFSET_LIMIT = NULL;

Symbol* SYM_QUERY_TOP_VARIABLE_FRAME_OFFSET = NULL;

Symbol* SYM_QUERY_UNBINDING_STACK = NULL;

Symbol* SYM_QUERY_UNBINDING_STACK_OFFSET_LIMIT = NULL;

Symbol* SYM_QUERY_TOP_UNBINDING_STACK_OFFSET = NULL;

Symbol* SYM_QUERY_CURRENT_VARIABLE_FRAME_OFFSET = NULL;

Symbol* SYM_QUERY_CURRENT_SUBQUERY_FRAME = NULL;

Symbol* SYM_QUERY_PARTIAL_MATCH_STRATEGY = NULL;

Symbol* SYM_QUERY_LATEST_POSITIVE_SCORE = NULL;

Symbol* SYM_QUERY_ITERATIVE_DEEPENINGp = NULL;

Symbol* SYM_QUERY_CURRENT_DEPTH_CUTOFF = NULL;

Symbol* SYM_QUERY_MAXIMUM_DEPTH = NULL;

Symbol* SYM_QUERY_AUGMENTED_GOAL_CACHEp = NULL;

Symbol* SYM_QUERY_ACTIVE_GOAL_CACHES = NULL;

Symbol* SYM_QUERY_TRIGGERED_DEPTH_CUTOFFp = NULL;

Symbol* SYM_QUERY_FAILED_TO_FIND_DUPLICATE_SUBGOALp = NULL;

Symbol* SYM_QUERY_FOUND_AT_LEAST_ONE_SOLUTIONp = NULL;

Symbol* SYM_QUERY_DEEP_INFERENCEp = NULL;

Symbol* SYM_QUERY_QUERY_THREAD_OFFSET = NULL;

Symbol* SYM_QUERY_TIME_STAMP = NULL;

Symbol* SYM_QUERY_QUERY_ITERATOR = NULL;

Symbol* SYM_QUERY_SUBSUMPTION_QUERYp = NULL;

Symbol* SYM_QUERY_SPECIALIZING_DESCRIPTION = NULL;

Symbol* SYM_QUERY_OPTIMIZER_GOAL_RECORDS = NULL;

Symbol* SYM_QUERY_RESIDUE_GOALS = NULL;

Symbol* SYM_QUERY_BEST_GOAL_SEQUENCE = NULL;

Symbol* SYM_QUERY_BEST_COST = NULL;

Surrogate* SGT_QUERY_QUERY_ENVIRONMENT = NULL;

Query_Environment* oQUERYENVIRONMENTo = NULL;

Symbol* SYM_QUERY_oQUERYENVIRONMENTo = NULL;

int oDEFAULT_MAXIMUM_DEPTHo = 25;

int oMAXIMUM_BACKTRACKING_DEPTHo = NULL_INTEGER;

int oINITIAL_BACKTRACKING_DEPTHo = 5;

boolean oITERATIVE_DEEPENING_MODEpo = FALSE;

boolean oDEEP_INFERENCE_MODEpo = FALSE;

Subquery_Frame* oRECYCLED_SUBQUERY_FRAME_So = NULL;

Symbol* SYM_QUERY_CONTROL_FRAME = NULL;

Symbol* SYM_QUERY_DESCRIPTION = NULL;

Symbol* SYM_QUERY_EXTERNAL_ARGUMENTS = NULL;

Symbol* SYM_QUERY_BOOLEAN_VECTOR = NULL;

Symbol* SYM_QUERY_LOCAL_VARIABLE_FRAME_OFFSET = NULL;

Symbol* SYM_QUERY_OPTIMAL_PATTERN = NULL;

Symbol* SYM_QUERY_PHASES_FILTER = NULL;

Surrogate* SGT_QUERY_SUBQUERY_FRAME = NULL;

Symbol* SYM_QUERY_TRUE_LINK = NULL;

Symbol* SYM_QUERY_FALSE_LINK = NULL;

Symbol* SYM_QUERY_VECTOR = NULL;

Surrogate* SGT_QUERY_BOOLEAN_VECTOR_INDEX_NODE = NULL;

Boolean_Vector_Index_Node* oBOOLEAN_VECTOR_INDEXo = NULL;

Surrogate* SGT_QUERY_PATTERN_VARIABLE = NULL;

int oCONTROL_FRAME_STACK_QUANTUMo = 100;

int oVARIABLE_FRAME_STACK_QUANTUMo = 100;

int oUNBINDING_STACK_QUANTUMo = 100;

Keyword* KWD_QUERY_QUERY_STACKS = NULL;

Keyword* KWD_QUERY_PATTERN = NULL;

Keyword* KWD_QUERY_CONTAINED_BY = NULL;

Keyword* KWD_QUERY_POPPED = NULL;

Keyword* KWD_QUERY_LOCAL = NULL;

Keyword* KWD_QUERY_PARENT = NULL;

Surrogate* SGT_QUERY_LOGIC_OBJECT = NULL;

Keyword* oTYPE_CHECK_STRATEGYo = NULL;

Keyword* KWD_QUERY_SORT = NULL;

Keyword* KWD_QUERY_NONE = NULL;

Keyword* KWD_QUERY_IN = NULL;

Surrogate* SGT_QUERY_SURROGATE = NULL;

Keyword* KWD_QUERY_SHALLOW_DISJOINT = NULL;

Keyword* KWD_QUERY_DISJOINT = NULL;

Symbol* SYM_QUERY_SKOLEM_NAME = NULL;

Surrogate* SGT_QUERY_LIST = NULL;

Keyword* KWD_QUERY_DOWN = NULL;

Keyword* KWD_QUERY_ITERATIVE_FORALL = NULL;

Keyword* KWD_QUERY_STATE_MACHINE = NULL;

Keyword* KWD_QUERY_SUBGOALS = NULL;

Keyword* KWD_QUERY_TERMINATION = NULL;

Keyword* KWD_QUERY_ANTECEDENTS = NULL;

Keyword* KWD_QUERY_REALISTIC = NULL;

Keyword* KWD_QUERY_COMPLEMENT = NULL;

Keyword* KWD_QUERY_UP_TRUE = NULL;

Keyword* KWD_QUERY_UP_FAIL = NULL;

Keyword* KWD_QUERY_AND = NULL;

Keyword* KWD_QUERY_OR = NULL;

Keyword* KWD_QUERY_NOT = NULL;

Keyword* KWD_QUERY_INITIAL = NULL;

Keyword* KWD_QUERY_GOAL_TREE = NULL;

Keyword* KWD_QUERY_SELECT_STRATEGY = NULL;

Keyword* KWD_QUERY_HEAVY_DUTY_DISJUNCTION = NULL;

Keyword* KWD_QUERY_FUNCTION = NULL;

Keyword* KWD_QUERY_PREDICATE = NULL;

Keyword* KWD_QUERY_EQUIVALENT = NULL;

Keyword* KWD_QUERY_IMPLIES = NULL;

Keyword* KWD_QUERY_CONSTANT = NULL;

Keyword* KWD_QUERY_CONTINUING_SUCCESS = NULL;

Keyword* KWD_QUERY_FINAL_SUCCESS = NULL;

Keyword* KWD_QUERY_FAILURE = NULL;

Keyword* KWD_QUERY_OVERLAY = NULL;

Keyword* KWD_QUERY_SPAWNED_SUBQUERY = NULL;

Keyword* KWD_QUERY_SUCCESS = NULL;

Keyword* KWD_QUERY_FAILED_OVERLAY = NULL;

Keyword* KWD_QUERY_SUBGOAL = NULL;

Keyword* KWD_QUERY_EXISTS = NULL;

Keyword* KWD_QUERY_FORALL = NULL;

Symbol* SYM_QUERY_IO_VARIABLES = NULL;

Keyword* KWD_QUERY_CACHED_BINDINGS = NULL;

Keyword* KWD_QUERY_FAIL = NULL;

Keyword* KWD_QUERY_END_SUBUMPTION_TEST = NULL;

boolean oREVERSEPOLARITYpo = FALSE;

Symbol* SYM_QUERY_oREVERSEPOLARITYpo = NULL;

Surrogate* SGT_QUERY_PROPOSITION = NULL;

Keyword* KWD_QUERY_ALL_SUBGOAL_PHASES = NULL;

Keyword* KWD_QUERY_SUBGOALS_OVERLAY = NULL;

Keyword* KWD_QUERY_OPEN = NULL;

Keyword* KWD_QUERY_SCAN_COLLECTION = NULL;

Surrogate* SGT_QUERY_DESCRIPTION = NULL;

Symbol* SYM_QUERY_COMPLEMENT_DESCRIPTION = NULL;

Keyword* KWD_QUERY_SCAN_SUBCOLLECTIONS = NULL;

Keyword* KWD_QUERY_SCAN_SUPERCOLLECTIONS = NULL;

Keyword* KWD_QUERY_DO_CONTAINED_BY = NULL;

Keyword* KWD_QUERY_SUBSUMPTION_OVERLAY = NULL;

Symbol* SYM_QUERY_CONTAINED_BY = NULL;

Symbol* SYM_QUERY_IN = NULL;

Keyword* KWD_QUERY_SKIP_DEFINITION = NULL;

Keyword* KWD_QUERY_PRE_ANTECEDENTS = NULL;

Keyword* KWD_QUERY_DEFINITION = NULL;

Keyword* KWD_QUERY_FULL_SUBQUERY = NULL;

Symbol* SYM_QUERY_DEFINITION = NULL;

Symbol* SYM_QUERY_MONOTONICp = NULL;

Symbol* SYM_QUERY_NON_DISJOINTNESS_KLUDGEp = NULL;

Surrogate* SGT_QUERY_COLLECTION = NULL;

boolean oGLOBALLY_CLOSED_COLLECTIONSpo = FALSE;

Surrogate* SGT_QUERY_COLLECTIONdCLOSED = NULL;

Keyword* KWD_QUERY_CLOSED = NULL;

Keyword* KWD_QUERY_PRIMITIVE = NULL;

Keyword* KWD_QUERY_ENUMERATION = NULL;

Symbol* SYM_QUERY_CURSOR = NULL;

Symbol* SYM_QUERY_ROOT_TYPE = NULL;

Symbol* SYM_QUERY_FILTER_TYPE = NULL;

Symbol* SYM_QUERY_NATIVE_CLASS_EXTENSION_ITERATOR = NULL;

Surrogate* SGT_QUERY_DESCRIPTION_EXTENSION_ITERATOR = NULL;

int oQUERY_THREAD_LIMITo = 8;

int oMAXIMUM_QUERY_THREAD_OFFSETo = NULL_INTEGER;

List* oFREE_QUERY_THREAD_OFFSETSo = NULL;

Vector* oQUERY_ENVIRONMENTS_VECTORo = NULL;

Symbol* SYM_QUERY_GOAL_BINDINGS = NULL;

Symbol* SYM_QUERY_CACHED_BINDINGS = NULL;

Symbol* SYM_QUERY_REVERSE_POLARITY_CACHED_BINDINGS = NULL;

Symbol* SYM_QUERY_UP_FOR_GRABSp = NULL;

Symbol* SYM_QUERY_CLUSTER = NULL;

Surrogate* SGT_QUERY_GOAL_CACHE = NULL;

Symbol* SYM_QUERY_VECTOR_OF_GOAL_CACHE_TABLES = NULL;

Surrogate* SGT_QUERY_GOAL_CACHE_CLUSTER = NULL;

Keyword* KWD_QUERY_GOAL_CACHES = NULL;

Symbol* SYM_QUERY_GOAL_CACHE_CLUSTER = NULL;

Keyword* KWD_QUERY_EXECUTE_QUERY = NULL;

Keyword* KWD_QUERY_QUERY = NULL;

Symbol* SYM_QUERY_AND = NULL;

Symbol* SYM_QUERY_KAPPA = NULL;

Symbol* SYM_QUERY_COMMA = NULL;

Symbol* SYM_QUERY_WHERE = NULL;

Symbol* SYM_QUERY_EXISTS = NULL;

Keyword* KWD_QUERY_KIF = NULL;

Symbol* SYM_QUERY_TRUE = NULL;

Keyword* KWD_QUERY_STELLA = NULL;

Keyword* KWD_QUERY_PREFIX_STELLA = NULL;

Surrogate* SGT_QUERY_LOGIC_EXCEPTION = NULL;

Keyword* KWD_QUERY_EXCEPTIONS = NULL;

Surrogate* SGT_QUERY_EXCEPTION = NULL;

Symbol* SYM_QUERY_EVALUATOR_WRAPPER_CODE = NULL;

Query_Iterator* oMOST_RECENT_QUERYo = NULL;

Keyword* KWD_QUERY_SUB = NULL;

Keyword* KWD_QUERY_SUPER = NULL;

Vector* REUSABLE_SINGLETON_VECTOR = NULL;

Surrogate* SGT_QUERY_RELATION = NULL;

Surrogate* SGT_QUERY_VECTOR = NULL;

Query_Iterator* new_query_iterator() {
  { Query_Iterator* self = NULL;

    self = new Query_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->exhaustedP = FALSE;
    self->solutions = new_list();
    self->external_variables = NULL;
    self->query_environment = NULL;
    return (self);
  }
}

Object* access_query_iterator_slot_value(Query_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_QUERY_ENVIRONMENT) {
    if (setvalueP) {
      self->query_environment = ((Query_Environment*)(value));
    }
    else {
      return (self->query_environment);
    }
  }
  else if (slotname == SYM_QUERY_EXTERNAL_VARIABLES) {
    if (setvalueP) {
      self->external_variables = ((Vector*)(value));
    }
    else {
      return (self->external_variables);
    }
  }
  else if (slotname == SYM_QUERY_SOLUTIONS) {
    if (setvalueP) {
      self->solutions = ((List*)(value));
    }
    else {
      return (self->solutions);
    }
  }
  else if (slotname == SYM_QUERY_EXHAUSTEDp) {
    if (setvalueP) {
      self->exhaustedP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->exhaustedP));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Query_Iterator::primary_type() {
  { Query_Iterator* self = this;

    return (SGT_QUERY_QUERY_ITERATOR);
  }
}

void Query_Iterator::print_object(ostream* stream) {
  { Query_Iterator* self = this;

    print_query_iterator(self, stream);
  }
}

Control_Frame* new_control_frame() {
  { Control_Frame* self = NULL;

    self = new Control_Frame;
    self->choice_point_unbinding_offset = NULL_INTEGER;
    self->debug_depth = 0;
    self->debug_frame_offset = NULL_INTEGER;
    self->partial_match_frame = NULL;
    self->goal_cache = NULL;
    self->parent_pattern_frame = NULL;
    self->iterator = NULL;
    self->argument_cursor = 0;
    self->back = NULL;
    self->down = NULL;
    self->up = NULL;
    self->reverse_polarityP = FALSE;
    self->proposition = NULL;
    self->phase = NULL;
    self->state = NULL;
    return (self);
  }
}

Object* access_control_frame_slot_value(Control_Frame* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_STATE) {
    if (setvalueP) {
      self->state = ((Keyword*)(value));
    }
    else {
      return (self->state);
    }
  }
  else if (slotname == SYM_QUERY_PHASE) {
    if (setvalueP) {
      self->phase = ((Keyword*)(value));
    }
    else {
      return (self->phase);
    }
  }
  else if (slotname == SYM_QUERY_PROPOSITION) {
    if (setvalueP) {
      self->proposition = ((Proposition*)(value));
    }
    else {
      return (self->proposition);
    }
  }
  else if (slotname == SYM_QUERY_REVERSE_POLARITYp) {
    if (setvalueP) {
      self->reverse_polarityP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->reverse_polarityP));
    }
  }
  else if (slotname == SYM_QUERY_UP) {
    if (setvalueP) {
      self->up = ((Control_Frame*)(value));
    }
    else {
      return (self->up);
    }
  }
  else if (slotname == SYM_QUERY_DOWN) {
    if (setvalueP) {
      self->down = ((Control_Frame*)(value));
    }
    else {
      return (self->down);
    }
  }
  else if (slotname == SYM_QUERY_BACK) {
    if (setvalueP) {
      self->back = ((Control_Frame*)(value));
    }
    else {
      return (self->back);
    }
  }
  else if (slotname == SYM_QUERY_ARGUMENT_CURSOR) {
    if (setvalueP) {
      self->argument_cursor = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->argument_cursor));
    }
  }
  else if (slotname == SYM_QUERY_ITERATOR) {
    if (setvalueP) {
      self->iterator = ((Iterator*)(value));
    }
    else {
      return (self->iterator);
    }
  }
  else if (slotname == SYM_QUERY_SUBQUERY_FRAME) {
    if (setvalueP) {
      self->iterator = ((Subquery_Frame*)(value));
    }
    else {
      return (((Subquery_Frame*)(self->iterator)));
    }
  }
  else if (slotname == SYM_QUERY_PARENT_PATTERN_FRAME) {
    if (setvalueP) {
      self->parent_pattern_frame = ((Control_Frame*)(value));
    }
    else {
      return (self->parent_pattern_frame);
    }
  }
  else if (slotname == SYM_QUERY_GOAL_CACHE) {
    if (setvalueP) {
      self->goal_cache = ((Goal_Cache*)(value));
    }
    else {
      return (self->goal_cache);
    }
  }
  else if (slotname == SYM_QUERY_PARTIAL_MATCH_FRAME) {
    if (setvalueP) {
      self->partial_match_frame = ((Partial_Match_Frame*)(value));
    }
    else {
      return (self->partial_match_frame);
    }
  }
  else if (slotname == SYM_QUERY_DEBUG_FRAME_OFFSET) {
    if (setvalueP) {
      self->debug_frame_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->debug_frame_offset));
    }
  }
  else if (slotname == SYM_QUERY_DEBUG_DEPTH) {
    if (setvalueP) {
      self->debug_depth = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->debug_depth));
    }
  }
  else if (slotname == SYM_QUERY_CHOICE_POINT_UNBINDING_OFFSET) {
    if (setvalueP) {
      self->choice_point_unbinding_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->choice_point_unbinding_offset));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Control_Frame::primary_type() {
  { Control_Frame* self = this;

    return (SGT_QUERY_CONTROL_FRAME);
  }
}

void Control_Frame::print_object(ostream* stream) {
  { Control_Frame* self = this;

    print_control_frame(self, stream);
  }
}

Goal_Strategy* new_goal_strategy() {
  { Goal_Strategy* self = NULL;

    self = new Goal_Strategy;
    self->strategy_procedure = NULL;
    self->strategy_priority = NULL_INTEGER;
    self->kind_of_goal = NULL;
    return (self);
  }
}

Object* access_goal_strategy_slot_value(Goal_Strategy* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_KIND_OF_GOAL) {
    if (setvalueP) {
      self->kind_of_goal = ((Keyword*)(value));
    }
    else {
      return (self->kind_of_goal);
    }
  }
  else if (slotname == SYM_QUERY_STRATEGY_PRIORITY) {
    if (setvalueP) {
      self->strategy_priority = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->strategy_priority));
    }
  }
  else if (slotname == SYM_QUERY_STRATEGY_PROCEDURE) {
    if (setvalueP) {
      self->strategy_procedure = ((Function_Code_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (function_code_wrap_literal(self->strategy_procedure));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Goal_Strategy::primary_type() {
  { Goal_Strategy* self = this;

    return (SGT_QUERY_GOAL_STRATEGY);
  }
}

Query_Environment* new_query_environment() {
  { Query_Environment* self = NULL;

    self = ((Query_Environment*)(oRECYCLED_QUERY_ENVIRONMENT_So->pop()));
    if (self != NULL) {
    }
    else {
      self = new Query_Environment;
    }
    self->best_cost = NULL_INTEGER;
    self->best_goal_sequence = new_list();
    self->residue_goals = new_list();
    self->optimizer_goal_records = NULL;
    self->specializing_description = NULL;
    self->subsumption_queryP = FALSE;
    self->query_iterator = NULL;
    self->time_stamp = NULL_INTEGER;
    self->query_thread_offset = NULL_INTEGER;
    self->deep_inferenceP = FALSE;
    self->found_at_least_one_solutionP = FALSE;
    self->failed_to_find_duplicate_subgoalP = FALSE;
    self->triggered_depth_cutoffP = FALSE;
    self->active_goal_caches = new_list();
    self->augmented_goal_cacheP = FALSE;
    self->maximum_depth = NULL_INTEGER;
    self->current_depth_cutoff = NULL_INTEGER;
    self->iterative_deepeningP = FALSE;
    self->latest_positive_score = NULL_FLOAT;
    self->partial_match_strategy = NULL;
    self->current_subquery_frame = NULL;
    self->current_variable_frame_offset = NULL_INTEGER;
    self->top_unbinding_stack_offset = NULL_INTEGER;
    self->unbinding_stack_offset_limit = NULL_INTEGER;
    self->unbinding_stack = NULL;
    self->top_variable_frame_offset = NULL_INTEGER;
    self->variable_frame_offset_limit = NULL_INTEGER;
    self->variable_frame_stack = NULL;
    self->top_control_frame_offset = NULL_INTEGER;
    self->control_frame_offset_limit = NULL_INTEGER;
    self->control_frame_stack = NULL;
    initialize_query_environment(self);
    return (self);
  }
}

void Query_Environment::free() {
  { Query_Environment* self = this;

    oRECYCLED_QUERY_ENVIRONMENT_So->push(self);
  }
}

Object* access_query_environment_slot_value(Query_Environment* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_CONTROL_FRAME_STACK) {
    if (setvalueP) {
      self->control_frame_stack = ((Vector*)(value));
    }
    else {
      return (self->control_frame_stack);
    }
  }
  else if (slotname == SYM_QUERY_CONTROL_FRAME_OFFSET_LIMIT) {
    if (setvalueP) {
      self->control_frame_offset_limit = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->control_frame_offset_limit));
    }
  }
  else if (slotname == SYM_QUERY_TOP_CONTROL_FRAME_OFFSET) {
    if (setvalueP) {
      self->top_control_frame_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->top_control_frame_offset));
    }
  }
  else if (slotname == SYM_QUERY_VARIABLE_FRAME_STACK) {
    if (setvalueP) {
      self->variable_frame_stack = ((Vector*)(value));
    }
    else {
      return (self->variable_frame_stack);
    }
  }
  else if (slotname == SYM_QUERY_VARIABLE_FRAME_OFFSET_LIMIT) {
    if (setvalueP) {
      self->variable_frame_offset_limit = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->variable_frame_offset_limit));
    }
  }
  else if (slotname == SYM_QUERY_TOP_VARIABLE_FRAME_OFFSET) {
    if (setvalueP) {
      self->top_variable_frame_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->top_variable_frame_offset));
    }
  }
  else if (slotname == SYM_QUERY_UNBINDING_STACK) {
    if (setvalueP) {
      self->unbinding_stack = ((Integer_Vector*)(value));
    }
    else {
      return (self->unbinding_stack);
    }
  }
  else if (slotname == SYM_QUERY_UNBINDING_STACK_OFFSET_LIMIT) {
    if (setvalueP) {
      self->unbinding_stack_offset_limit = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->unbinding_stack_offset_limit));
    }
  }
  else if (slotname == SYM_QUERY_TOP_UNBINDING_STACK_OFFSET) {
    if (setvalueP) {
      self->top_unbinding_stack_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->top_unbinding_stack_offset));
    }
  }
  else if (slotname == SYM_QUERY_CURRENT_VARIABLE_FRAME_OFFSET) {
    if (setvalueP) {
      self->current_variable_frame_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->current_variable_frame_offset));
    }
  }
  else if (slotname == SYM_QUERY_CURRENT_SUBQUERY_FRAME) {
    if (setvalueP) {
      self->current_subquery_frame = ((Subquery_Frame*)(value));
    }
    else {
      return (self->current_subquery_frame);
    }
  }
  else if (slotname == SYM_QUERY_PARTIAL_MATCH_STRATEGY) {
    if (setvalueP) {
      self->partial_match_strategy = ((Partial_Match_Frame*)(value));
    }
    else {
      return (self->partial_match_strategy);
    }
  }
  else if (slotname == SYM_QUERY_LATEST_POSITIVE_SCORE) {
    if (setvalueP) {
      self->latest_positive_score = ((Float_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (float_wrap_literal(self->latest_positive_score));
    }
  }
  else if (slotname == SYM_QUERY_ITERATIVE_DEEPENINGp) {
    if (setvalueP) {
      self->iterative_deepeningP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->iterative_deepeningP));
    }
  }
  else if (slotname == SYM_QUERY_CURRENT_DEPTH_CUTOFF) {
    if (setvalueP) {
      self->current_depth_cutoff = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->current_depth_cutoff));
    }
  }
  else if (slotname == SYM_QUERY_MAXIMUM_DEPTH) {
    if (setvalueP) {
      self->maximum_depth = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->maximum_depth));
    }
  }
  else if (slotname == SYM_QUERY_AUGMENTED_GOAL_CACHEp) {
    if (setvalueP) {
      self->augmented_goal_cacheP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->augmented_goal_cacheP));
    }
  }
  else if (slotname == SYM_QUERY_ACTIVE_GOAL_CACHES) {
    if (setvalueP) {
      self->active_goal_caches = ((List*)(value));
    }
    else {
      return (self->active_goal_caches);
    }
  }
  else if (slotname == SYM_QUERY_TRIGGERED_DEPTH_CUTOFFp) {
    if (setvalueP) {
      self->triggered_depth_cutoffP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->triggered_depth_cutoffP));
    }
  }
  else if (slotname == SYM_QUERY_FAILED_TO_FIND_DUPLICATE_SUBGOALp) {
    if (setvalueP) {
      self->failed_to_find_duplicate_subgoalP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->failed_to_find_duplicate_subgoalP));
    }
  }
  else if (slotname == SYM_QUERY_FOUND_AT_LEAST_ONE_SOLUTIONp) {
    if (setvalueP) {
      self->found_at_least_one_solutionP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->found_at_least_one_solutionP));
    }
  }
  else if (slotname == SYM_QUERY_DEEP_INFERENCEp) {
    if (setvalueP) {
      self->deep_inferenceP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->deep_inferenceP));
    }
  }
  else if (slotname == SYM_QUERY_QUERY_THREAD_OFFSET) {
    if (setvalueP) {
      self->query_thread_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->query_thread_offset));
    }
  }
  else if (slotname == SYM_QUERY_TIME_STAMP) {
    if (setvalueP) {
      self->time_stamp = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->time_stamp));
    }
  }
  else if (slotname == SYM_QUERY_QUERY_ITERATOR) {
    if (setvalueP) {
      self->query_iterator = ((Query_Iterator*)(value));
    }
    else {
      return (self->query_iterator);
    }
  }
  else if (slotname == SYM_QUERY_SUBSUMPTION_QUERYp) {
    if (setvalueP) {
      self->subsumption_queryP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->subsumption_queryP));
    }
  }
  else if (slotname == SYM_QUERY_SPECIALIZING_DESCRIPTION) {
    if (setvalueP) {
      self->specializing_description = ((Description*)(value));
    }
    else {
      return (self->specializing_description);
    }
  }
  else if (slotname == SYM_QUERY_OPTIMIZER_GOAL_RECORDS) {
    if (setvalueP) {
      self->optimizer_goal_records = ((Extensible_Vector*)(value));
    }
    else {
      return (self->optimizer_goal_records);
    }
  }
  else if (slotname == SYM_QUERY_RESIDUE_GOALS) {
    if (setvalueP) {
      self->residue_goals = ((List*)(value));
    }
    else {
      return (self->residue_goals);
    }
  }
  else if (slotname == SYM_QUERY_BEST_GOAL_SEQUENCE) {
    if (setvalueP) {
      self->best_goal_sequence = ((List*)(value));
    }
    else {
      return (self->best_goal_sequence);
    }
  }
  else if (slotname == SYM_QUERY_BEST_COST) {
    if (setvalueP) {
      self->best_cost = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->best_cost));
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Query_Environment::primary_type() {
  { Query_Environment* self = this;

    return (SGT_QUERY_QUERY_ENVIRONMENT);
  }
}

Query_Environment* read_OqueryenvironmentO() {
  return (oQUERYENVIRONMENTo);
}

Query_Environment* write_OqueryenvironmentO(Query_Environment* value) {
  oQUERYENVIRONMENTo = value;
  return (value);
}

boolean deep_inference_modeP() {
  // Determines whether expensive inferencing is warranted.
  return (oDEEP_INFERENCE_MODEpo);
}

boolean subsumption_modeP() {
  return ((oQUERYENVIRONMENTo != NULL) &&
      oQUERYENVIRONMENTo->subsumption_queryP);
}

Subquery_Frame* new_subquery_frame() {
  { Subquery_Frame* self = NULL;

    self = oRECYCLED_SUBQUERY_FRAME_So;
    if (self != NULL) {
      oRECYCLED_SUBQUERY_FRAME_So = ((Subquery_Frame*)(self->iterator));
    }
    else {
      self = new Subquery_Frame;
    }
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->iterator = NULL;
    self->phases_filter = NULL;
    self->optimal_pattern = NULL;
    self->local_variable_frame_offset = NULL_INTEGER;
    self->boolean_vector = NULL;
    self->external_arguments = NULL;
    self->description = NULL;
    self->control_frame = NULL;
    return (self);
  }
}

void Subquery_Frame::free() {
  { Subquery_Frame* self = this;

    if (!(terminate_subquery_frameP(self))) {
      return;
    }
    self->iterator = oRECYCLED_SUBQUERY_FRAME_So;
    oRECYCLED_SUBQUERY_FRAME_So = self;
  }
}

Object* access_subquery_frame_slot_value(Subquery_Frame* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_CONTROL_FRAME) {
    if (setvalueP) {
      self->control_frame = ((Control_Frame*)(value));
    }
    else {
      return (self->control_frame);
    }
  }
  else if (slotname == SYM_QUERY_DESCRIPTION) {
    if (setvalueP) {
      self->description = ((Description*)(value));
    }
    else {
      return (self->description);
    }
  }
  else if (slotname == SYM_QUERY_EXTERNAL_ARGUMENTS) {
    if (setvalueP) {
      self->external_arguments = ((Vector*)(value));
    }
    else {
      return (self->external_arguments);
    }
  }
  else if (slotname == SYM_QUERY_BOOLEAN_VECTOR) {
    if (setvalueP) {
      self->boolean_vector = ((Boolean_Vector*)(value));
    }
    else {
      return (self->boolean_vector);
    }
  }
  else if (slotname == SYM_QUERY_LOCAL_VARIABLE_FRAME_OFFSET) {
    if (setvalueP) {
      self->local_variable_frame_offset = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->local_variable_frame_offset));
    }
  }
  else if (slotname == SYM_QUERY_OPTIMAL_PATTERN) {
    if (setvalueP) {
      self->optimal_pattern = ((Description*)(value));
    }
    else {
      return (self->optimal_pattern);
    }
  }
  else if (slotname == SYM_QUERY_PHASES_FILTER) {
    if (setvalueP) {
      self->phases_filter = ((Keyword*)(value));
    }
    else {
      return (self->phases_filter);
    }
  }
  else if (slotname == SYM_QUERY_ITERATOR) {
    if (setvalueP) {
      self->iterator = ((Iterator*)(value));
    }
    else {
      return (self->iterator);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Subquery_Frame::primary_type() {
  { Subquery_Frame* self = this;

    return (SGT_QUERY_SUBQUERY_FRAME);
  }
}

Boolean_Vector_Index_Node* new_boolean_vector_index_node() {
  { Boolean_Vector_Index_Node* self = NULL;

    self = new Boolean_Vector_Index_Node;
    self->vector = NULL;
    self->false_link = NULL;
    self->true_link = NULL;
    return (self);
  }
}

Object* access_boolean_vector_index_node_slot_value(Boolean_Vector_Index_Node* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_TRUE_LINK) {
    if (setvalueP) {
      self->true_link = ((Boolean_Vector_Index_Node*)(value));
    }
    else {
      return (self->true_link);
    }
  }
  else if (slotname == SYM_QUERY_FALSE_LINK) {
    if (setvalueP) {
      self->false_link = ((Boolean_Vector_Index_Node*)(value));
    }
    else {
      return (self->false_link);
    }
  }
  else if (slotname == SYM_QUERY_VECTOR) {
    if (setvalueP) {
      self->vector = ((Boolean_Vector*)(value));
    }
    else {
      return (self->vector);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Boolean_Vector_Index_Node::primary_type() {
  { Boolean_Vector_Index_Node* self = this;

    return (SGT_QUERY_BOOLEAN_VECTOR_INDEX_NODE);
  }
}

Boolean_Vector_Index_Node* create_boolean_vector_index_node(Boolean_Vector_Index_Node* parentnode, boolean lastvalue) {
  { Boolean_Vector_Index_Node* node = new_boolean_vector_index_node();
    int vectorlength = parentnode->vector->length() + 1;
    Boolean_Vector* vector = new_boolean_vector(vectorlength);

    node->vector = vector;
    { int i = NULL_INTEGER;
      int iter_001 = 0;
      int upper_bound_001 = vectorlength - 2;

      while (iter_001 <= upper_bound_001) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        vector->nth_setter(((Boolean_Wrapper*)(parentnode->vector->nth(i))), i);
      }
    }
    vector->nth_setter(wrap_boolean(lastvalue), vectorlength - 1);
    if (lastvalue) {
      parentnode->true_link = node;
    }
    else {
      parentnode->false_link = node;
    }
    return (node);
  }
}

Boolean_Vector* arguments_vector_to_boolean_vector(Vector* argumentsvector) {
  { Boolean_Vector_Index_Node* node = oBOOLEAN_VECTOR_INDEXo;
    Boolean_Vector_Index_Node* nextnode = NULL;
    boolean boundP = FALSE;

    { Object* arg = NULL;
      Vector* vector_001 = argumentsvector;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        boundP = TRUE;
        { Object* arg_001 = arg;

          if (taxonomy_isaP(arg, SGT_QUERY_PATTERN_VARIABLE)) {
            { Pattern_Variable* arg = NULL;

              arg = ((Pattern_Variable*)(arg_001));
              boundP = bound_to(arg) != NULL;
            }
          }
          else {
          }
        }
        if (boundP) {
          {
            nextnode = node->true_link;
            if (nextnode == NULL) {
              nextnode = create_boolean_vector_index_node(node, TRUE);
            }
          }
        }
        else {
          {
            nextnode = node->false_link;
            if (nextnode == NULL) {
              nextnode = create_boolean_vector_index_node(node, FALSE);
            }
          }
        }
        node = nextnode;
      }
    }
    return (node->vector);
  }
}

Boolean_Vector* zero_one_list_to_boolean_vector(List* zeroonelist) {
  { Boolean_Vector_Index_Node* node = oBOOLEAN_VECTOR_INDEXo;
    Boolean_Vector_Index_Node* nextnode = NULL;

    { Integer_Wrapper* bit = NULL;
      Cons* iter_001 = zeroonelist->the_cons_list;

      while (!nilP(iter_001)) {
        {
          bit = ((Integer_Wrapper*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if (eqlP(bit, ONE_WRAPPER)) {
          {
            nextnode = node->true_link;
            if (nextnode == NULL) {
              nextnode = create_boolean_vector_index_node(node, TRUE);
            }
          }
        }
        else {
          {
            nextnode = node->false_link;
            if (nextnode == NULL) {
              nextnode = create_boolean_vector_index_node(node, FALSE);
            }
          }
        }
        node = nextnode;
      }
    }
    return (node->vector);
  }
}

void initialize_query_environment(Query_Environment* environment) {
  environment->control_frame_stack = new_vector(oCONTROL_FRAME_STACK_QUANTUMo);
  environment->control_frame_offset_limit = oCONTROL_FRAME_STACK_QUANTUMo - 1;
  environment->top_control_frame_offset = -1;
  environment->variable_frame_stack = new_vector(oVARIABLE_FRAME_STACK_QUANTUMo);
  environment->variable_frame_offset_limit = oVARIABLE_FRAME_STACK_QUANTUMo - 1;
  environment->top_variable_frame_offset = -1;
  environment->current_variable_frame_offset = -1;
  environment->unbinding_stack = new_integer_vector(oUNBINDING_STACK_QUANTUMo);
  environment->unbinding_stack_offset_limit = oUNBINDING_STACK_QUANTUMo - 1;
  environment->top_unbinding_stack_offset = -1;
}

void expand_control_frame_stack(Query_Environment* queryenvironment) {
  { int newstacklimit = queryenvironment->control_frame_offset_limit + oCONTROL_FRAME_STACK_QUANTUMo;
    Vector* newstack = new_vector(newstacklimit + 1);
    Vector* oldstack = queryenvironment->control_frame_stack;

    { int i = NULL_INTEGER;
      int iter_001 = 0;
      int upper_bound_001 = queryenvironment->top_control_frame_offset;
      boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

      while (unboundedP_001 ||
          (iter_001 <= upper_bound_001)) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        newstack->nth_setter(((Control_Frame*)(oldstack->nth(i))), i);
      }
    }
    oldstack->free();
    queryenvironment->control_frame_stack = newstack;
    queryenvironment->control_frame_offset_limit = newstacklimit;
  }
}

Control_Frame* new_top_control_frame(Query_Environment* queryenvironment) {
  { int topoffset = queryenvironment->top_control_frame_offset + 1;
    Control_Frame* frame = ((Control_Frame*)(queryenvironment->control_frame_stack->nth(topoffset)));

    queryenvironment->top_control_frame_offset = topoffset;
    if (frame != NULL) {
      return (frame);
    }
    if (topoffset == queryenvironment->control_frame_offset_limit) {
      expand_control_frame_stack(queryenvironment);
    }
    frame = new_control_frame();
    queryenvironment->control_frame_stack->nth_setter(frame, topoffset);
    return (frame);
  }
}

void pop_control_frame(Query_Environment* queryenvironment) {
  { Control_Frame* frame = ((Control_Frame*)(queryenvironment->control_frame_stack->nth(queryenvironment->top_control_frame_offset)));

    if ((oTRACED_KEYWORDSo != NULL) &&
        oTRACED_KEYWORDSo->memberP(KWD_QUERY_QUERY_STACKS)) {
      cout << "POP-control-frame:  state= " << frame->state << " F" << compute_frame_offset(frame) << endl;
    }
    if ((frame->state == KWD_QUERY_PATTERN) ||
        (frame->state == KWD_QUERY_CONTAINED_BY)) {
      deallocate_block_of_variable_frames(frame);
    }
    if (frame->iterator != NULL) {
      frame->iterator->free();
      frame->iterator = NULL;
    }
    frame->choice_point_unbinding_offset = NULL_INTEGER;
    queryenvironment->top_control_frame_offset = queryenvironment->top_control_frame_offset - 1;
    frame->state = KWD_QUERY_POPPED;
  }
}

void pop_frames_down_to(Control_Frame* frame) {
  while (!(frame == oQUERYENVIRONMENTo->control_frame_stack->nth(oQUERYENVIRONMENTo->top_control_frame_offset))) {
    pop_control_frame(oQUERYENVIRONMENTo);
  }
  if (frame->up != NULL) {
    frame->up->down = NULL;
  }
  pop_control_frame(oQUERYENVIRONMENTo);
}

void expand_variable_frame_stack(Query_Environment* queryenvironment) {
  cerr << "expand-variable-frame-stack: Write me, I am a dummy!";
  queryenvironment = queryenvironment;
}

int allocate_block_of_variable_frames(int variablecount, Control_Frame* frame) {
  if ((oTRACED_KEYWORDSo != NULL) &&
      oTRACED_KEYWORDSo->memberP(KWD_QUERY_QUERY_STACKS)) {
    cout << "allocate-block-of-variable-frames: " << variablecount << endl;
  }
  { int oldtopoffset = oQUERYENVIRONMENTo->top_variable_frame_offset;
    int variablesblockoffset = oldtopoffset + 1;
    int newtopoffset = oldtopoffset + variablecount;

    while (newtopoffset >= oQUERYENVIRONMENTo->variable_frame_offset_limit) {
      expand_variable_frame_stack(oQUERYENVIRONMENTo);
    }
    oQUERYENVIRONMENTo->top_variable_frame_offset = newtopoffset;
    { int i = NULL_INTEGER;
      int iter_001 = oldtopoffset + 1;
      int upper_bound_001 = newtopoffset;
      boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

      while (unboundedP_001 ||
          (iter_001 <= upper_bound_001)) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        oQUERYENVIRONMENTo->variable_frame_stack->nth_setter(NULL, i);
      }
    }
    ((Subquery_Frame*)(frame->iterator))->local_variable_frame_offset = variablesblockoffset;
    reset_current_variable_frame_offset(frame, KWD_QUERY_LOCAL);
    if (frame->choice_point_unbinding_offset == NULL_INTEGER) {
      create_choice_point(frame);
    }
    else {
    }
    return (variablesblockoffset);
  }
}

void deallocate_block_of_variable_frames(Control_Frame* frame) {
  if ((oTRACED_KEYWORDSo != NULL) &&
      oTRACED_KEYWORDSo->memberP(KWD_QUERY_QUERY_STACKS)) {
    cout << "deallocate-block-of-variable-frames: " << endl;
  }
  oQUERYENVIRONMENTo->top_variable_frame_offset = ((Subquery_Frame*)(frame->iterator))->local_variable_frame_offset - 1;
  reset_current_variable_frame_offset(frame, KWD_QUERY_PARENT);
}

void reset_current_variable_frame_offset(Control_Frame* frame, Keyword* localorparent) {
  if (localorparent == KWD_QUERY_LOCAL) {
    oQUERYENVIRONMENTo->current_variable_frame_offset = ((Subquery_Frame*)(frame->iterator))->local_variable_frame_offset;
  }
  else if (localorparent == KWD_QUERY_PARENT) {
    if (frame->parent_pattern_frame != NULL) {
      oQUERYENVIRONMENTo->current_variable_frame_offset = ((Subquery_Frame*)(frame->parent_pattern_frame->iterator))->local_variable_frame_offset;
    }
    else {
      oQUERYENVIRONMENTo->current_variable_frame_offset = 0;
    }
  }
  else {
    cerr << "`" << localorparent << "'" << " is not a valid case option";
  }
}

void expand_unbinding_stack(Query_Environment* queryenvironment) {
  cerr << "expand-unbinding-stack: Write me, I am a dummy!";
  queryenvironment = queryenvironment;
}

void print_environment_stacks() {
  cout << "-------------------------" << endl;
  cout << "top-control-frame-offset " << oQUERYENVIRONMENTo->top_control_frame_offset << endl;
  cout << "top-variable-frame-offset " << oQUERYENVIRONMENTo->top_variable_frame_offset << endl;
  cout << "    ";
  { int i = NULL_INTEGER;
    int iter_001 = 0;
    int upper_bound_001 = 10;

    while (iter_001 <= upper_bound_001) {
      {
        i = iter_001;
        iter_001 = iter_001 + 1;
      }
      if (oQUERYENVIRONMENTo->variable_frame_stack->nth(i) != NULL) {
        cout << oQUERYENVIRONMENTo->variable_frame_stack->nth(i) << " ";
      }
      else {
        cout << "_ ";
      }
    }
  }
  cout << endl;
  cout << "current-variable-frame-offset " << oQUERYENVIRONMENTo->current_variable_frame_offset << endl;
  cout << "top-unbinding-stack-offset " << oQUERYENVIRONMENTo->top_unbinding_stack_offset << endl;
  cout << "    " << oQUERYENVIRONMENTo->unbinding_stack << endl;
  cout << "-------------------------" << endl;
}

void set_pattern_variable_binding(Pattern_Variable* variable, Object* value) {
  if ((oTRACED_KEYWORDSo != NULL) &&
      oTRACED_KEYWORDSo->memberP(KWD_QUERY_QUERY_STACKS)) {
    cout << "set-pattern-variable-binding: " << variable << " " << value << endl;
  }
  { int vfstackoffset = oQUERYENVIRONMENTo->current_variable_frame_offset + variable->bound_to_offset;
    int ubstackoffset = oQUERYENVIRONMENTo->top_unbinding_stack_offset + 1;

    oQUERYENVIRONMENTo->variable_frame_stack->nth_setter(value, vfstackoffset);
    if (ubstackoffset == oQUERYENVIRONMENTo->unbinding_stack_offset_limit) {
      expand_unbinding_stack(oQUERYENVIRONMENTo);
    }
    oQUERYENVIRONMENTo->top_unbinding_stack_offset = ubstackoffset;
    oQUERYENVIRONMENTo->unbinding_stack->nth_setter(integer_wrap_literal(vfstackoffset), ubstackoffset);
  }
}

void unbind_variables_beginning_at(int ubstackoffset) {
  if ((oTRACED_KEYWORDSo != NULL) &&
      oTRACED_KEYWORDSo->memberP(KWD_QUERY_QUERY_STACKS)) {
    cout << "unbind-variables-beginning-at: " << "UBS= " << ubstackoffset << "#bindings= " << ((oQUERYENVIRONMENTo->top_unbinding_stack_offset - ubstackoffset) + 1) << endl;
  }
  { Vector* variablebindingstack = oQUERYENVIRONMENTo->variable_frame_stack;
    Integer_Vector* unbindingstack = oQUERYENVIRONMENTo->unbinding_stack;

    { int i = NULL_INTEGER;
      int iter_001 = ubstackoffset;
      int upper_bound_001 = oQUERYENVIRONMENTo->top_unbinding_stack_offset;
      boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

      while (unboundedP_001 ||
          (iter_001 <= upper_bound_001)) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        variablebindingstack->nth_setter(NULL, ((Integer_Wrapper*)(unbindingstack->nth(i)))->wrapper_value);
        unbindingstack->nth_setter(NULL, i);
      }
    }
    oQUERYENVIRONMENTo->top_unbinding_stack_offset = ubstackoffset - 1;
  }
}

void unbind_pattern_variables(Control_Frame* frame) {
  if (frame->choice_point_unbinding_offset != NULL_INTEGER) {
    unbind_variables_beginning_at(frame->choice_point_unbinding_offset);
  }
}

void create_choice_point(Control_Frame* frame) {
  if ((oTRACED_KEYWORDSo != NULL) &&
      oTRACED_KEYWORDSo->memberP(KWD_QUERY_QUERY_STACKS)) {
    cout << "create-choice-point: " << "CP= " << frame->choice_point_unbinding_offset << " NEWCP= " << (oQUERYENVIRONMENTo->top_unbinding_stack_offset + 1) << endl;
  }
  if (frame->choice_point_unbinding_offset == NULL_INTEGER) {
    frame->choice_point_unbinding_offset = oQUERYENVIRONMENTo->top_unbinding_stack_offset + 1;
  }
  else {
    unbind_variables_beginning_at(frame->choice_point_unbinding_offset);
  }
}

Object* bound_to(Pattern_Variable* self) {
  return (oQUERYENVIRONMENTo->variable_frame_stack->nth(oQUERYENVIRONMENTo->current_variable_frame_offset + self->bound_to_offset));
}

Object* argument_bound_to(Object* self) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_QUERY_PATTERN_VARIABLE)) {
      { Pattern_Variable* self = NULL;

        self = ((Pattern_Variable*)(self_001));
        { Object* value = bound_to(self);

          if ((value == NULL) &&
              (((Object*)(access_in_context(self->variable_value, self, FALSE))) != NULL)) {
            value = self->value_of();
            if (skolemP(value)) {
              return (NULL);
            }
            bind_variable_to_valueP(self, value, TRUE);
          }
          return (value);
        }
      }
    }
    else if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        return (self->value_of());
      }
    }
    else {
      return (self);
    }
  }
}

Object* native_argument_bound_to(Object* self) {
  { Object* value = argument_bound_to(self);

    if (value != NULL) {
      { Object* value_001 = value;

        if (taxonomy_isaP(value, SGT_QUERY_LOGIC_OBJECT)) {
          { Logic_Object* value = NULL;

            value = ((Logic_Object*)(value_001));
            if (((Object*)(access_in_context(value->variable_value, value, FALSE))) != NULL) {
              return (((Object*)(access_in_context(value->variable_value, value, FALSE))));
            }
            else {
              return (NULL);
            }
          }
        }
        else if (surrogateP(value)) {
          { Surrogate* value = NULL;

            value = ((Surrogate*)(value_001));
            { Object* surrogatevalue = value->surrogate_value;

              if (surrogatevalue != NULL) {
                return (native_value_of(surrogatevalue));
              }
              else {
                return (NULL);
              }
            }
          }
        }
        else {
          return (value);
        }
      }
    }
    else {
      return (NULL);
    }
  }
}

Slot* operator_bound_to(Object* self) {
  { Object* self_001 = self;

    if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        return (((Slot*)(self->surrogate_value)));
      }
    }
    else {
      return (((Slot*)(native_argument_bound_to(self))));
    }
  }
}

boolean help_unify_attributesP(Object* value1, Object* value2) {
  return (eqlP(value1, value2) ||
      (skolemP(value1) &&
       help_bind_variable_to_valueP(((Pattern_Variable*)(value1)), value2)));
}

boolean fails_type_checkP(Pattern_Variable* v1, Object* i2) {
  if (oTYPE_CHECK_STRATEGYo == KWD_QUERY_NONE) {
    return (FALSE);
  }
  else if (oTYPE_CHECK_STRATEGYo == KWD_QUERY_SORT) {
    { Surrogate* type1 = NULL;
      Surrogate* type2 = NULL;
      Class* class1 = NULL;
      Class* class2 = NULL;

      { Proposition* p = NULL;
        Cons* iter_001 = v1->dependent_propositions->the_cons_list;

        while (!nilP(iter_001)) {
          {
            p = ((Proposition*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          if ((p->kind == KWD_QUERY_IN) &&
              (isaP(p->arguments->second(), SGT_QUERY_SURROGATE) &&
               trueP(p))) {
            type1 = ((Surrogate*)(p->arguments->second()));
            class1 = ((Class*)(type1->surrogate_value));
            break;
          }
        }
      }
      if ((class1 == NULL) ||
          (!class1->sortP_reader())) {
        return (FALSE);
      }
      { Object* i2_001 = i2;

        if (taxonomy_isaP(i2, SGT_QUERY_LOGIC_OBJECT)) {
          { Logic_Object* i2 = NULL;

            i2 = ((Logic_Object*)(i2_001));
            { Proposition* p = NULL;
              Cons* iter_002 = i2->dependent_propositions->the_cons_list;

              while (!nilP(iter_002)) {
                {
                  p = ((Proposition*)(iter_002->value));
                  iter_002 = iter_002->rest;
                }
                if ((p->kind == KWD_QUERY_IN) &&
                    isaP(p->arguments->second(), SGT_QUERY_SURROGATE)) {
                  type2 = ((Surrogate*)(p->arguments->second()));
                  class2 = ((Class*)(type2->surrogate_value));
                  if (class2->sortP_reader() &&
                      subclass_ofP(class2, class1)) {
                    return (FALSE);
                  }
                }
              }
            }
          }
        }
        else {
          type2 = logical_type(i2);
          class2 = ((Class*)(type2->surrogate_value));
          if (class2->sortP_reader() &&
              subclass_ofP(class2, class1)) {
            return (FALSE);
          }
        }
      }
      if ((class2 != NULL) &&
          class2->sortP_reader()) {
        return (TRUE);
      }
      return (FALSE);
    }
  }
  else if (oTYPE_CHECK_STRATEGYo == KWD_QUERY_SHALLOW_DISJOINT) {
    if ((v1->root_type != NULL) &&
        disjoint_classesP(((Class*)(v1->root_type->surrogate_value)), ((Class*)(logical_type(i2)->surrogate_value)))) {
      return (TRUE);
    }
    return (FALSE);
  }
  else if (oTYPE_CHECK_STRATEGYo == KWD_QUERY_DISJOINT) {
    { Surrogate* type1 = NULL;
      Surrogate* type2 = NULL;

      { Proposition* p = NULL;
        Cons* iter_003 = v1->dependent_propositions->the_cons_list;

        while (!nilP(iter_003)) {
          {
            p = ((Proposition*)(iter_003->value));
            iter_003 = iter_003->rest;
          }
          if ((p->kind == KWD_QUERY_IN) &&
              isaP(p->arguments->second(), SGT_QUERY_SURROGATE)) {
            type1 = ((Surrogate*)(p->arguments->second()));
            break;
          }
        }
      }
      if (type1 == NULL) {
        return (FALSE);
      }
      { Object* i2_002 = i2;

        if (taxonomy_isaP(i2, SGT_QUERY_LOGIC_OBJECT)) {
          { Logic_Object* i2 = NULL;

            i2 = ((Logic_Object*)(i2_002));
            { Proposition* p = NULL;
              Cons* iter_004 = i2->dependent_propositions->the_cons_list;

              while (!nilP(iter_004)) {
                {
                  p = ((Proposition*)(iter_004->value));
                  iter_004 = iter_004->rest;
                }
                if ((p->kind == KWD_QUERY_IN) &&
                    isaP(p->arguments->second(), SGT_QUERY_SURROGATE)) {
                  type2 = ((Surrogate*)(p->arguments->second()));
                  break;
                }
              }
            }
          }
        }
        else {
          type2 = logical_type(i2);
        }
      }
      if (type2 == NULL) {
        return (FALSE);
      }
      return (disjoint_classesP(((Class*)(type1->surrogate_value)), ((Class*)(type2->surrogate_value))));
    }
  }
  else {
    cerr << "`" << oTYPE_CHECK_STRATEGYo << "'" << " is not a valid case option";
  }
}

boolean help_bind_variable_to_valueP(Pattern_Variable* variable, Object* value) {
  if (fails_type_checkP(variable, value)) {
    return (FALSE);
  }
  { Object* boundtovalue = bound_to(variable);
    Object* variablevalue = ((Object*)(access_in_context(variable->variable_value, variable, FALSE)));

    if (variablevalue != NULL) {
      variablevalue = variablevalue->value_of();
      set_pattern_variable_binding(variable, variablevalue);
      return (eqlP(variablevalue, value));
    }
    else if (boundtovalue == NULL) {
      set_pattern_variable_binding(variable, value);
    }
    else if (eqlP(boundtovalue, value)) {
      return (TRUE);
    }
    else {
      return (FALSE);
    }
    return (TRUE);
    { Proposition* prop = NULL;
      Cons* iter_001 = variable->dependent_attribute_propositions->the_cons_list;

      while (!nilP(iter_001)) {
        {
          prop = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        { Description* slotdescription = ((Description*)(dynamic_slot_value(((Slot*)(((Surrogate*)(prop->renamed_Operator))->surrogate_value)), SYM_QUERY_DESCRIPTION, NULL)));

          if ((slotdescription != NULL) &&
              all_direct_supercollections(slotdescription)->nextP()) {
            continue;
          }
        }
        { Object* slotvariable = last_argument(prop);
          Object* slotvalue = query_for_asserted_function_proposition_value(prop);

          if (!((slotvalue != NULL) &&
              help_unify_attributesP(slotvariable, slotvalue))) {
            return (FALSE);
          }
        }
      }
    }
    return (TRUE);
  }
}

boolean bind_variable_to_valueP(Pattern_Variable* variable, Object* value, boolean autocleanupP) {
  if (autocleanupP) {
    { int ubstackoffset = oQUERYENVIRONMENTo->top_unbinding_stack_offset;
      boolean successP = FALSE;

      successP = help_bind_variable_to_valueP(variable, value);
      if (!successP) {
        unbind_variables_beginning_at(ubstackoffset + 1);
      }
      return (successP);
    }
  }
  else {
    return (help_bind_variable_to_valueP(variable, value));
  }
}

boolean bind_argument_to_valueP(Object* argument, Object* value, boolean autocleanupP) {
  { Object* argument_001 = argument;

    if (taxonomy_isaP(argument, SGT_QUERY_PATTERN_VARIABLE)) {
      { Pattern_Variable* argument = NULL;

        argument = ((Pattern_Variable*)(argument_001));
        if (autocleanupP) {
          { int ubstackoffset = oQUERYENVIRONMENTo->top_unbinding_stack_offset;
            boolean successP = FALSE;

            successP = help_bind_variable_to_valueP(argument, value);
            if (!successP) {
              unbind_variables_beginning_at(ubstackoffset + 1);
            }
            return (successP);
          }
        }
        else {
          return (help_bind_variable_to_valueP(argument, value));
        }
      }
    }
    else if (surrogateP(argument)) {
      { Surrogate* argument = NULL;

        argument = ((Surrogate*)(argument_001));
        return (eqlP(argument->value_of(), value));
      }
    }
    else {
      return (eqlP(argument, value));
    }
  }
}

boolean bind_vector_of_arguments_to_valuesP(Vector* arguments, Cons* values) {
  { int ubstackoffset = oQUERYENVIRONMENTo->top_unbinding_stack_offset;
    boolean successP = FALSE;

    { boolean alwaysP_001 = TRUE;

      { Object* v = NULL;
        Object* arg = NULL;
        Vector* vector_001 = arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();
        Cons* iter_001 = values;

        while ((index_001 < length_001) &&
            (!nilP(iter_001))) {
          {
            arg = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          {
            v = iter_001->value;
            iter_001 = iter_001->rest;
          }
          if (!bind_argument_to_valueP(arg, v, FALSE)) {
            alwaysP_001 = FALSE;
            break;
          }
        }
      }
      successP = alwaysP_001;
    }
    if (!successP) {
      unbind_variables_beginning_at(ubstackoffset + 1);
    }
    return (successP);
  }
}

void pcs() {
  { int i = NULL_INTEGER;
    int iter_001 = 0;
    int upper_bound_001 = oQUERYENVIRONMENTo->top_control_frame_offset;
    boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

    while (unboundedP_001 ||
        (iter_001 <= upper_bound_001)) {
      {
        i = iter_001;
        iter_001 = iter_001 + 1;
      }
      cout << ((Control_Frame*)(oQUERYENVIRONMENTo->control_frame_stack->nth(i))) << endl;
    }
  }
}

Pattern_Variable* variable_from_unbinding_offset(Description* description, int uboffset) {
  { int offset = ((Integer_Wrapper*)(oQUERYENVIRONMENTo->unbinding_stack->nth(uboffset)))->wrapper_value - oQUERYENVIRONMENTo->current_variable_frame_offset;

    { Pattern_Variable* vbl = NULL;
      Vector* vector_001 = description->io_variables;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          vbl = ((Pattern_Variable*)(vector_001->nth(index_001)));
          index_001 = index_001 + 1;
        }
        if (vbl->bound_to_offset == offset) {
          return (vbl);
        }
      }
    }
    { Pattern_Variable* vbl = NULL;
      Vector* vector_002 = description->internal_variables;
      int index_002 = 0;
      int length_002 = vector_002->length();

      while (index_002 < length_002) {
        {
          vbl = ((Pattern_Variable*)(vector_002->nth(index_002)));
          index_002 = index_002 + 1;
        }
        if (vbl->bound_to_offset == offset) {
          return (vbl);
        }
      }
    }
    return (NULL);
  }
}

int compute_frame_offset(Control_Frame* frame) {
  if (frame->debug_frame_offset != NULL_INTEGER) {
    return (frame->debug_frame_offset);
  }
  if (oQUERYENVIRONMENTo == NULL) {
    return (-9);
  }
  { int i = NULL_INTEGER;
    int iter_001 = 0;
    int upper_bound_001 = 99;

    while (iter_001 <= upper_bound_001) {
      {
        i = iter_001;
        iter_001 = iter_001 + 1;
      }
      if (frame == oQUERYENVIRONMENTo->control_frame_stack->nth(i)) {
        return (i);
      }
    }
  }
}

void print_one_variable_binding(Pattern_Variable* variable) {
  cout << ((Symbol*)(dynamic_slot_value(variable, SYM_QUERY_SKOLEM_NAME, NULL))) << "=";
  if (variable->bound_to_offset != NULL_INTEGER) {
    print_unformatted_logical_form(bound_to(variable), STANDARD_OUTPUT);
  }
  else {
    cout << NULL;
  }
  cout << " ";
}

void print_variable_bindings(Control_Frame* frame) {
  if ((frame->parent_pattern_frame != NULL) &&
      (!(frame->state == KWD_QUERY_PATTERN))) {
    frame = frame->parent_pattern_frame;
  }
  { Subquery_Frame* suqueryframe = ((Subquery_Frame*)(frame->iterator));
    Description* description = NULL;

    if (suqueryframe != NULL) {
      { Subquery_Frame* suqueryframe_001 = suqueryframe;

        if (taxonomy_isaP(suqueryframe, SGT_QUERY_SUBQUERY_FRAME)) {
          { Subquery_Frame* suqueryframe = NULL;

            suqueryframe = ((Subquery_Frame*)(suqueryframe_001));
            if (frame->state == KWD_QUERY_CONTAINED_BY) {
              { Proposition* inproposition = ((Proposition*)(frame->proposition->arguments->nth(0)));
                Object* member = inproposition->arguments->nth(0);

                { Object* member_001 = member;

                  if (taxonomy_isaP(member, SGT_QUERY_PATTERN_VARIABLE)) {
                    { Pattern_Variable* member = NULL;

                      member = ((Pattern_Variable*)(member_001));
                      print_one_variable_binding(member);
                    }
                  }
                  else if (taxonomy_isaP(member, SGT_QUERY_LIST)) {
                    { List* member = NULL;

                      member = ((List*)(member_001));
                      { Object* m = NULL;
                        Cons* iter_001 = member->the_cons_list;

                        while (!nilP(iter_001)) {
                          {
                            m = iter_001->value;
                            iter_001 = iter_001->rest;
                          }
                          print_one_variable_binding(((Pattern_Variable*)(m)));
                        }
                      }
                    }
                  }
                  else {
                    cerr << "`" << member << "'" << " is not a valid case option";
                  }
                }
              }
              return;
            }
            description = suqueryframe->optimal_pattern;
            if (description != NULL) {
              { Pattern_Variable* vbl = NULL;
                Vector* vector_001 = description->io_variables;
                int index_001 = 0;
                int length_001 = vector_001->length();

                while (index_001 < length_001) {
                  {
                    vbl = ((Pattern_Variable*)(vector_001->nth(index_001)));
                    index_001 = index_001 + 1;
                  }
                  if (bound_to(vbl) != NULL) {
                    print_one_variable_binding(vbl);
                  }
                }
              }
              { Pattern_Variable* vbl = NULL;
                Vector* vector_002 = description->internal_variables;
                int index_002 = 0;
                int length_002 = vector_002->length();

                while (index_002 < length_002) {
                  {
                    vbl = ((Pattern_Variable*)(vector_002->nth(index_002)));
                    index_002 = index_002 + 1;
                  }
                  if (bound_to(vbl) != NULL) {
                    print_one_variable_binding(vbl);
                  }
                }
              }
            }
            return;
          }
        }
        else {
        }
      }
    }
  }
}

void trace_goal_tree(Control_Frame* frame, int depth, Keyword* lastmove) {
  if (get_quoted_tree("((:IN :FUNCTION :PREDICATE :EQUIVALENT :IMPLIES :CONSTANT) \"/LOGIC\")", "/LOGIC")->memberP(frame->state) &&
      ((lastmove == KWD_QUERY_DOWN) &&
       (frame->choice_point_unbinding_offset != NULL_INTEGER))) {
    unbind_variables_beginning_at(frame->choice_point_unbinding_offset);
  }
  if (get_quoted_tree("((:AND :OR) \"/LOGIC\")", "/LOGIC")->memberP(frame->state) &&
      ((lastmove == KWD_QUERY_DOWN) &&
       ((frame->down != NULL) &&
        (get_quoted_tree("((:IN :FUNCTION :PREDICATE :EQUIVALENT :IMPLIES :CONSTANT) \"/LOGIC\")", "/LOGIC")->memberP(frame->down->state) &&
         (frame->down->choice_point_unbinding_offset != NULL_INTEGER))))) {
    unbind_variables_beginning_at(frame->down->choice_point_unbinding_offset);
  }
  if ((frame->state == KWD_QUERY_ITERATIVE_FORALL) &&
      (lastmove == KWD_QUERY_DOWN)) {
    return;
  }
  { boolean invertP = frame->reverse_polarityP;

    if (trace_keywordP(KWD_QUERY_STATE_MACHINE)) {
      cout << "F" << compute_frame_offset(frame);
      if (frame->choice_point_unbinding_offset != NULL_INTEGER) {
        cout << "," << frame->choice_point_unbinding_offset << " ";
      }
      else {
        cout << "   ";
      }
    }
    { int i = NULL_INTEGER;
      int iter_001 = 1;
      int upper_bound_001 = depth;
      boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

      while (unboundedP_001 ||
          (iter_001 <= upper_bound_001)) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        cout << "| ";
      }
    }
    if (lastmove == KWD_QUERY_DOWN) {
      { Keyword* test_value_001 = frame->state;

        if (test_value_001 == KWD_QUERY_SUBGOALS) {
          if (frame->phase == KWD_QUERY_TERMINATION) {
            cout << "FAIL";
            return;
          }
          { Description* description = ((Subquery_Frame*)(frame->iterator))->description;

            if (frame->down == NULL) {
              cout << "SUBGOALING: ";
            }
            else if ((frame->down != NULL) &&
                (frame->phase == KWD_QUERY_ANTECEDENTS)) {
              cout << "RULE: ";
              { Keyword* old_OprintmodeO_001 = oPRINTMODEo;
                Output_Stream* old_OprintlogicalformstreamO_001 = oPRINTLOGICALFORMSTREAMo;
                int old_OindentcounterO_001 = oINDENTCOUNTERo;

                { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                  oEXCEPTIONHANDLERADDRESSo = NULL;
                  if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                      setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                    {
                      oPRINTMODEo = KWD_QUERY_REALISTIC;
                      oPRINTLOGICALFORMSTREAMo = STANDARD_OUTPUT;
                      oINDENTCOUNTERo = (2 * depth) + 7;
                      print_descriptions_as_kif_rule(description, ((((Subquery_Frame*)(frame->down->iterator))->optimal_pattern != NULL) ? ((Description*)(((Subquery_Frame*)(frame->down->iterator))->optimal_pattern)) : ((Description*)(((Subquery_Frame*)(frame->iterator))->description))));
                      oINDENTCOUNTERo = old_OindentcounterO_001;
                      oPRINTLOGICALFORMSTREAMo = old_OprintlogicalformstreamO_001;
                      oPRINTMODEo = old_OprintmodeO_001;
                    }
                    oEXCEPTIONo = NULL;
                  }
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                }
                if (oEXCEPTIONo != NULL) {
                  if (TRUE) {
                    oINDENTCOUNTERo = old_OindentcounterO_001;
                    oPRINTLOGICALFORMSTREAMo = old_OprintlogicalformstreamO_001;
                    oPRINTMODEo = old_OprintmodeO_001;
                    resignal();
                  }
                }
              }
            }
            else if ((frame->up != NULL) &&
                (frame->up->phase == KWD_QUERY_COMPLEMENT)) {
              cout << "COMPLEMENT GOAL: ";
              print_unformatted_logical_form(description->proposition, STANDARD_OUTPUT);
            }
            else {
              if (frame->up != NULL) {
                cout << "UNIMPLEMENTED TRACE STATE";
              }
            }
          }
        }
        else if (test_value_001 == KWD_QUERY_PATTERN) {
          cout << "PATTERN: [";
          { boolean firsttimeP = TRUE;

            { Boolean_Wrapper* tv = NULL;
              Boolean_Vector* vector_001 = ((Subquery_Frame*)(frame->iterator))->boolean_vector;
              int index_001 = 0;
              int length_001 = vector_001->length();

              while (index_001 < length_001) {
                {
                  tv = ((Boolean_Wrapper*)(vector_001->nth(index_001)));
                  index_001 = index_001 + 1;
                }
                if (firsttimeP) {
                  firsttimeP = FALSE;
                }
                else {
                  cout << ",";
                }
                if (tv->wrapper_value) {
                  cout << "T";
                }
                else {
                  cout << "F";
                }
              }
            }
          }
          cout << "]";
        }
        else {
          cout << "GOAL: ";
          if (invertP) {
            cout << "~";
          }
          print_unformatted_logical_form(frame->proposition, STANDARD_OUTPUT);
        }
      }
    }
    else if ((lastmove == KWD_QUERY_UP_TRUE) ||
        (lastmove == KWD_QUERY_UP_FAIL)) {
      if (lastmove == KWD_QUERY_UP_TRUE) {
        cout << "| SUCC: ";
        { Control_Frame* old_OprintinframeO_001 = oPRINTINFRAMEo;

          { jump_buffer old_OexceptionhandleraddressO_002 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oPRINTINFRAMEo = frame;
                print_variable_bindings(frame);
                oPRINTINFRAMEo = old_OprintinframeO_001;
              }
              oEXCEPTIONo = NULL;
            }
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_002;
          }
          if (oEXCEPTIONo != NULL) {
            if (TRUE) {
              oPRINTINFRAMEo = old_OprintinframeO_001;
              resignal();
            }
          }
        }
      }
      else if (lastmove == KWD_QUERY_UP_FAIL) {
        cout << "| FAIL ";
      }
      else {
        cerr << "`" << lastmove << "'" << " is not a valid case option";
      }
    }
    else {
      cout << "????: ";
    }
    if (trace_keywordP(KWD_QUERY_STATE_MACHINE)) {
      cout << " state= " << frame->state << "  lastMove= " << lastmove << " depth= " << depth << " revPty?= " << frame->reverse_polarityP;
    }
    cout << endl;
  }
}

Keyword* interpret_and_scores(Control_Frame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    if (frame->partial_match_frame == NULL) {
      create_and_link_partial_match_frame(frame, KWD_QUERY_AND);
    }
  }
  else if ((lastmove == KWD_QUERY_UP_TRUE) ||
      (lastmove == KWD_QUERY_UP_FAIL)) {
    record_latest_partial_match_score(frame);
    if (compute_partial_match_and_failureP(frame)) {
      lastmove = KWD_QUERY_UP_FAIL;
    }
    else if (((frame->argument_cursor + 1) == frame->proposition->arguments->length()) &&
        (!compute_partial_match_scoreP(frame))) {
      lastmove = KWD_QUERY_UP_FAIL;
    }
    else {
      lastmove = KWD_QUERY_UP_TRUE;
    }
  }
  else {
    cerr << "`" << lastmove << "'" << " is not a valid case option";
  }
  return (lastmove);
}

Keyword* interpret_or_scores(Control_Frame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    if (frame->partial_match_frame == NULL) {
      create_and_link_partial_match_frame(frame, KWD_QUERY_OR);
    }
  }
  else if ((lastmove == KWD_QUERY_UP_TRUE) ||
      (lastmove == KWD_QUERY_UP_FAIL)) {
    record_latest_partial_match_score(frame);
    if (compute_partial_match_or_successP(frame)) {
      lastmove = KWD_QUERY_UP_TRUE;
    }
    else if (((frame->argument_cursor + 1) == frame->proposition->arguments->length()) &&
        compute_partial_match_scoreP(frame)) {
      lastmove = KWD_QUERY_UP_TRUE;
    }
    else {
      lastmove = KWD_QUERY_UP_FAIL;
    }
  }
  else {
    cerr << "`" << lastmove << "'" << " is not a valid case option";
  }
  return (lastmove);
}

Keyword* interpret_fail_score(Control_Frame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    if (frame->partial_match_frame == NULL) {
      create_and_link_partial_match_frame(frame, KWD_QUERY_NOT);
    }
  }
  else if ((lastmove == KWD_QUERY_UP_TRUE) ||
      (lastmove == KWD_QUERY_UP_FAIL)) {
    record_latest_partial_match_score(frame);
    if (compute_partial_match_scoreP(frame)) {
      lastmove = KWD_QUERY_UP_TRUE;
    }
    else {
      lastmove = KWD_QUERY_UP_FAIL;
    }
  }
  else {
    cerr << "`" << lastmove << "'" << " is not a valid case option";
  }
  return (lastmove);
}

Keyword* interpret_subgoals_scores(Control_Frame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    if (frame->partial_match_frame == NULL) {
      create_and_link_partial_match_frame(frame, KWD_QUERY_OR);
      record_latest_partial_match_score(frame);
    }
  }
  else if ((lastmove == KWD_QUERY_UP_TRUE) ||
      (lastmove == KWD_QUERY_UP_FAIL)) {
    { Query_Environment* queryenvironment = oQUERYENVIRONMENTo;
      Partial_Match_Frame* partialmatchframe = frame->partial_match_frame;
      double maxscore = partialmatchframe->compute_or_score();
      double latestscore = queryenvironment->latest_positive_score;

      if (frame->phase == KWD_QUERY_ANTECEDENTS) {
        { Proposition* impliesprop = ((Proposition*)(((Subquery_Frame*)(frame->iterator))->iterator->value));

          latestscore = frame->partial_match_frame->compute_rule_score(latestscore, ((Truth_Value*)(access_in_context(impliesprop->truth_value, impliesprop, FALSE))));
          queryenvironment->latest_positive_score = latestscore;
        }
      }
      record_latest_partial_match_score(frame);
      if (compute_partial_match_scoreP(frame)) {
        lastmove = KWD_QUERY_UP_TRUE;
      }
      else {
        {
          lastmove = KWD_QUERY_UP_FAIL;
        }
      }
    }
  }
  else {
    cerr << "`" << lastmove << "'" << " is not a valid case option";
  }
  return (lastmove);
}

Control_Frame* create_down_frame(Control_Frame* upframe, Proposition* downproposition) {
  { Control_Frame* downframe = new_top_control_frame(oQUERYENVIRONMENTo);

    upframe->down = downframe;
    downframe->up = upframe;
    downframe->reverse_polarityP = upframe->reverse_polarityP;
    downframe->proposition = downproposition;
    downframe->phase = KWD_QUERY_INITIAL;
    downframe->down = NULL;
    downframe->back = NULL;
    downframe->goal_cache = NULL;
    downframe->debug_depth = 0;
    if (downproposition != NULL) {
      downframe->state = downproposition->kind;
      if (downframe->reverse_polarityP) {
        { Keyword* test_value_001 = downframe->state;

          if (test_value_001 == KWD_QUERY_AND) {
            downframe->state = KWD_QUERY_OR;
          }
          else if (test_value_001 == KWD_QUERY_OR) {
            downframe->state = KWD_QUERY_AND;
          }
          else {
          }
        }
      }
      downframe->argument_cursor = 0;
    }
    if (upframe->state == KWD_QUERY_PATTERN) {
      downframe->parent_pattern_frame = upframe;
    }
    else {
      downframe->parent_pattern_frame = upframe->parent_pattern_frame;
    }
    downframe->debug_frame_offset = compute_frame_offset(downframe);
    return (downframe);
  }
}

boolean execute_backward_chaining_proofP(Query_Environment* queryenvironment) {
  if (queryenvironment->top_control_frame_offset < 1) {
    return (FALSE);
  }
  { Query_Environment* old_OqueryenvironmentO_001 = oQUERYENVIRONMENTo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oQUERYENVIRONMENTo = queryenvironment;
          oCONTEXTo = get_query_context();
          { Control_Frame* frame = ((Control_Frame*)(queryenvironment->control_frame_stack->nth(0)));
            Proposition* proposition = frame->proposition;
            int depth = 0;
            Keyword* lastmove = KWD_QUERY_DOWN;
            boolean partialmatchP = queryenvironment->partial_match_strategy != NULL;

            for (;;) {
              if (trace_keywordP(KWD_QUERY_GOAL_TREE)) {
                trace_goal_tree(frame, depth, lastmove);
              }
              { Keyword* test_value_001 = frame->state;

                if (test_value_001 == KWD_QUERY_AND) {
                  if (partialmatchP) {
                    lastmove = interpret_and_scores(frame, lastmove);
                  }
                  if (lastmove == KWD_QUERY_DOWN) {
                    {
                      depth = depth + 1;
                      if (depth > queryenvironment->current_depth_cutoff) {
                        if (frame->down != NULL) {
                          pop_frames_down_to(frame->down);
                        }
                        depth = depth - 1;
                        frame = handle_depth_violation(frame, depth, depth);
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                      else if (frame->down != NULL) {
                        frame = frame->down;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_DOWN;
                      }
                      else {
                        { Control_Frame* upframe = frame;

                          proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                          frame = create_down_frame(upframe, proposition);
                          frame->debug_depth = depth;
                          lastmove = KWD_QUERY_DOWN;
                        }
                      }
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_TRUE) {
                    if (frame->down == NULL) {
                      frame->argument_cursor = frame->argument_cursor + 1;
                      if (frame->argument_cursor < proposition->arguments->length()) {
                        {
                          depth = depth + 1;
                          if (depth > queryenvironment->current_depth_cutoff) {
                            if (frame->down != NULL) {
                              pop_frames_down_to(frame->down);
                            }
                            depth = depth - 1;
                            frame = handle_depth_violation(frame, depth, depth);
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_UP_FAIL;
                          }
                          else if (frame->down != NULL) {
                            frame = frame->down;
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_DOWN;
                          }
                          else {
                            { Control_Frame* upframe = frame;

                              proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                              frame = create_down_frame(upframe, proposition);
                              frame->debug_depth = depth;
                              lastmove = KWD_QUERY_DOWN;
                            }
                          }
                        }
                      }
                      else {
                        if (frame->back == NULL) {
                          {
                            update_goal_cache(frame, TRUE);
                            depth = depth - 1;
                            frame = frame->up;
                            proposition = frame->proposition;
                            pop_control_frame(queryenvironment);
                            if (!(frame->down->down == NULL)) {
                              cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                            }
                            frame->down = NULL;
                            lastmove = KWD_QUERY_UP_TRUE;
                          }
                        }
                        else {
                          {
                            { Control_Frame* forwardframe = frame;

                              frame = frame->back;
                              proposition = frame->proposition;
                              forwardframe->back = NULL;
                              forwardframe->up->down = frame;
                              pop_control_frame(queryenvironment);
                            }
                            {
                              update_goal_cache(frame, TRUE);
                              depth = depth - 1;
                              frame = frame->up;
                              proposition = frame->proposition;
                              lastmove = KWD_QUERY_UP_TRUE;
                            }
                          }
                        }
                      }
                    }
                    else if (frame->argument_cursor == (proposition->arguments->length() - 1)) {
                      {
                        update_goal_cache(frame, TRUE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                    else {
                      { Control_Frame* backframe = frame;
                        Control_Frame* upframe = backframe->up;

                        frame = create_down_frame(upframe, backframe->proposition);
                        frame->back = backframe;
                        frame->state = KWD_QUERY_AND;
                        frame->argument_cursor = backframe->argument_cursor + 1;
                      }
                      {
                        depth = depth + 1;
                        if (depth > queryenvironment->current_depth_cutoff) {
                          if (frame->down != NULL) {
                            pop_frames_down_to(frame->down);
                          }
                          depth = depth - 1;
                          frame = handle_depth_violation(frame, depth, depth);
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_UP_FAIL;
                        }
                        else if (frame->down != NULL) {
                          frame = frame->down;
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_DOWN;
                        }
                        else {
                          { Control_Frame* upframe = frame;

                            proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                            frame = create_down_frame(upframe, proposition);
                            frame->debug_depth = depth;
                            lastmove = KWD_QUERY_DOWN;
                          }
                        }
                      }
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_FAIL) {
                    if (frame->back == NULL) {
                      {
                        update_goal_cache(frame, FALSE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        pop_control_frame(queryenvironment);
                        if (!(frame->down->down == NULL)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                        }
                        frame->down = NULL;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                    }
                    else {
                      {
                        { Control_Frame* forwardframe = frame;

                          frame = frame->back;
                          proposition = frame->proposition;
                          forwardframe->back = NULL;
                          forwardframe->up->down = frame;
                          pop_control_frame(queryenvironment);
                        }
                        {
                          depth = depth + 1;
                          if (depth > queryenvironment->current_depth_cutoff) {
                            if (frame->down != NULL) {
                              pop_frames_down_to(frame->down);
                            }
                            depth = depth - 1;
                            frame = handle_depth_violation(frame, depth, depth);
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_UP_FAIL;
                          }
                          else if (frame->down != NULL) {
                            frame = frame->down;
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_DOWN;
                          }
                          else {
                            { Control_Frame* upframe = frame;

                              proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                              frame = create_down_frame(upframe, proposition);
                              frame->debug_depth = depth;
                              lastmove = KWD_QUERY_DOWN;
                            }
                          }
                        }
                      }
                    }
                  }
                  else {
                    cerr << "`" << lastmove << "'" << " is not a valid case option";
                  }
                }
                else if (test_value_001 == KWD_QUERY_OR) {
                  if (partialmatchP) {
                    lastmove = interpret_or_scores(frame, lastmove);
                  }
                  if (lastmove == KWD_QUERY_DOWN) {
                    {
                      depth = depth + 1;
                      if (depth > queryenvironment->current_depth_cutoff) {
                        if (frame->down != NULL) {
                          pop_frames_down_to(frame->down);
                        }
                        depth = depth - 1;
                        frame = handle_depth_violation(frame, depth, depth);
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                      else if (frame->down != NULL) {
                        frame = frame->down;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_DOWN;
                      }
                      else {
                        { Control_Frame* upframe = frame;

                          proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                          frame = create_down_frame(upframe, proposition);
                          frame->debug_depth = depth;
                          lastmove = KWD_QUERY_DOWN;
                        }
                      }
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_TRUE) {
                    if (frame->down == NULL) {
                      frame->argument_cursor = frame->argument_cursor + 1;
                    }
                    if (frame->argument_cursor < proposition->arguments->length()) {
                      {
                        update_goal_cache(frame, TRUE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                    else {
                      {
                        update_goal_cache(frame, TRUE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        pop_control_frame(queryenvironment);
                        if (!(frame->down->down == NULL)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                        }
                        frame->down = NULL;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_FAIL) {
                    frame->argument_cursor = frame->argument_cursor + 1;
                    if (frame->argument_cursor < proposition->arguments->length()) {
                      {
                        depth = depth + 1;
                        if (depth > queryenvironment->current_depth_cutoff) {
                          if (frame->down != NULL) {
                            pop_frames_down_to(frame->down);
                          }
                          depth = depth - 1;
                          frame = handle_depth_violation(frame, depth, depth);
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_UP_FAIL;
                        }
                        else if (frame->down != NULL) {
                          frame = frame->down;
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_DOWN;
                        }
                        else {
                          { Control_Frame* upframe = frame;

                            proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                            frame = create_down_frame(upframe, proposition);
                            frame->debug_depth = depth;
                            lastmove = KWD_QUERY_DOWN;
                          }
                        }
                      }
                    }
                    else {
                      if (oQUERYENVIRONMENTo->deep_inferenceP) {
                        {
                          frame->state = KWD_QUERY_SELECT_STRATEGY;
                          frame->phase = KWD_QUERY_HEAVY_DUTY_DISJUNCTION;
                          lastmove = KWD_QUERY_DOWN;
                        }
                      }
                      else {
                        {
                          update_goal_cache(frame, FALSE);
                          depth = depth - 1;
                          frame = frame->up;
                          proposition = frame->proposition;
                          pop_control_frame(queryenvironment);
                          if (!(frame->down->down == NULL)) {
                            cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                          }
                          frame->down = NULL;
                          lastmove = KWD_QUERY_UP_FAIL;
                        }
                      }
                    }
                  }
                  else {
                    cerr << "`" << lastmove << "'" << " is not a valid case option";
                  }
                }
                else if (test_value_001 == KWD_QUERY_NOT) {
                  if (lastmove == KWD_QUERY_DOWN) {
                    { boolean oldreversepolarityP = frame->reverse_polarityP;

                      frame->reverse_polarityP = !oldreversepolarityP;
                      {
                        depth = depth + 1;
                        if (depth > queryenvironment->current_depth_cutoff) {
                          if (frame->down != NULL) {
                            pop_frames_down_to(frame->down);
                          }
                          depth = depth - 1;
                          frame = handle_depth_violation(frame, depth, depth);
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_UP_FAIL;
                        }
                        else if (frame->down != NULL) {
                          frame = frame->down;
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_DOWN;
                        }
                        else {
                          { Control_Frame* upframe = frame;

                            proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                            frame = create_down_frame(upframe, proposition);
                            frame->debug_depth = depth;
                            lastmove = KWD_QUERY_DOWN;
                          }
                        }
                      }
                      frame->up->reverse_polarityP = oldreversepolarityP;
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_TRUE) {
                    if (frame->down != NULL) {
                      pop_frames_down_to(frame->down);
                    }
                    {
                      update_goal_cache(frame, TRUE);
                      depth = depth - 1;
                      frame = frame->up;
                      proposition = frame->proposition;
                      pop_control_frame(queryenvironment);
                      if (!(frame->down->down == NULL)) {
                        cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                      }
                      frame->down = NULL;
                      lastmove = KWD_QUERY_UP_TRUE;
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_FAIL) {
                    {
                      update_goal_cache(frame, FALSE);
                      depth = depth - 1;
                      frame = frame->up;
                      proposition = frame->proposition;
                      pop_control_frame(queryenvironment);
                      if (!(frame->down->down == NULL)) {
                        cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                      }
                      frame->down = NULL;
                      lastmove = KWD_QUERY_UP_FAIL;
                    }
                  }
                  else {
                    cerr << "`" << lastmove << "'" << " is not a valid case option";
                  }
                }
                else if ((test_value_001 == KWD_QUERY_IN) ||
                    ((test_value_001 == KWD_QUERY_FUNCTION) ||
                     ((test_value_001 == KWD_QUERY_PREDICATE) ||
                      ((test_value_001 == KWD_QUERY_EQUIVALENT) ||
                       ((test_value_001 == KWD_QUERY_IMPLIES) ||
                        (test_value_001 == KWD_QUERY_CONSTANT)))))) {
                  create_choice_point(frame);
                  { Keyword* test_value_002 = continue_atomic_proposition_proof(frame, lastmove);

                    if (test_value_002 == KWD_QUERY_CONTINUING_SUCCESS) {
                      {
                        update_goal_cache(frame, TRUE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                    else if (test_value_002 == KWD_QUERY_FINAL_SUCCESS) {
                      {
                        update_goal_cache(frame, TRUE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        pop_control_frame(queryenvironment);
                        if (!(frame->down->down == NULL)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                        }
                        frame->down = NULL;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                    else if (test_value_002 == KWD_QUERY_FAILURE) {
                      {
                        update_goal_cache(frame, FALSE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        pop_control_frame(queryenvironment);
                        if (!(frame->down->down == NULL)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                        }
                        frame->down = NULL;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                    }
                    else if (test_value_002 == KWD_QUERY_OVERLAY) {
                      lastmove = KWD_QUERY_DOWN;
                    }
                    else if (test_value_002 == KWD_QUERY_SPAWNED_SUBQUERY) {
                      {
                        depth = depth + 1;
                        if (depth > queryenvironment->current_depth_cutoff) {
                          if (frame->down != NULL) {
                            pop_frames_down_to(frame->down);
                          }
                          depth = depth - 1;
                          frame = handle_depth_violation(frame, depth, depth);
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_UP_FAIL;
                        }
                        else if (frame->down != NULL) {
                          frame = frame->down;
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_DOWN;
                        }
                        else {
                          { Control_Frame* upframe = frame;

                            proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                            frame = create_down_frame(upframe, proposition);
                            frame->debug_depth = depth;
                            lastmove = KWD_QUERY_DOWN;
                          }
                        }
                      }
                    }
                    else {
                      cerr << "`" << test_value_002 << "'" << " is not a valid case option";
                    }
                  }
                }
                else if (test_value_001 == KWD_QUERY_SUBGOALS) {
                  if (partialmatchP) {
                    lastmove = interpret_subgoals_scores(frame, lastmove);
                  }
                  if (lastmove == KWD_QUERY_DOWN) {
                    if (frame->down != NULL) {
                      {
                        depth = depth + 1;
                        if (depth > queryenvironment->current_depth_cutoff) {
                          if (frame->down != NULL) {
                            pop_frames_down_to(frame->down);
                          }
                          depth = depth - 1;
                          frame = handle_depth_violation(frame, depth, depth);
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_UP_FAIL;
                        }
                        else if (frame->down != NULL) {
                          frame = frame->down;
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_DOWN;
                        }
                        else {
                          { Control_Frame* upframe = frame;

                            proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                            frame = create_down_frame(upframe, proposition);
                            frame->debug_depth = depth;
                            lastmove = KWD_QUERY_DOWN;
                          }
                        }
                      }
                    }
                    else {
                      { Keyword* test_value_003 = continue_subgoals_proof(frame);

                        if (test_value_003 == KWD_QUERY_SPAWNED_SUBQUERY) {
                          {
                            depth = depth + 1;
                            if (depth > queryenvironment->current_depth_cutoff) {
                              if (frame->down != NULL) {
                                pop_frames_down_to(frame->down);
                              }
                              depth = depth - 1;
                              frame = handle_depth_violation(frame, depth, depth);
                              proposition = frame->proposition;
                              lastmove = KWD_QUERY_UP_FAIL;
                            }
                            else if (frame->down != NULL) {
                              frame = frame->down;
                              proposition = frame->proposition;
                              lastmove = KWD_QUERY_DOWN;
                            }
                            else {
                              { Control_Frame* upframe = frame;

                                proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                                frame = create_down_frame(upframe, proposition);
                                frame->debug_depth = depth;
                                lastmove = KWD_QUERY_DOWN;
                              }
                            }
                          }
                        }
                        else if (test_value_003 == KWD_QUERY_SUCCESS) {
                          {
                            if (frame->up != NULL) {
                              update_goal_cache(frame, TRUE);
                            }
                            depth = depth - 1;
                            frame = frame->up;
                            if (frame == NULL) {
                              { 
                                oCONTEXTo = old_OcontextO_001;
                                oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
                                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                                return (TRUE);
                              }
                            }
                            pop_control_frame(queryenvironment);
                            if (frame != NULL) {
                              if (!(frame->down->down == NULL)) {
                                cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                              }
                              frame->down = NULL;
                            }
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_UP_TRUE;
                          }
                        }
                        else if (test_value_003 == KWD_QUERY_FAILURE) {
                          {
                            if (frame->up != NULL) {
                              update_goal_cache(frame, FALSE);
                            }
                            depth = depth - 1;
                            frame = frame->up;
                            if (frame == NULL) {
                              { 
                                oCONTEXTo = old_OcontextO_001;
                                oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
                                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                                return (FALSE);
                              }
                            }
                            pop_control_frame(queryenvironment);
                            if (frame != NULL) {
                              if (!(frame->down->down == NULL)) {
                                cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                              }
                              frame->down = NULL;
                            }
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_UP_FAIL;
                          }
                        }
                        else if (test_value_003 == KWD_QUERY_OVERLAY) {
                          lastmove = KWD_QUERY_DOWN;
                        }
                        else if (test_value_003 == KWD_QUERY_FAILED_OVERLAY) {
                          if (frame->down != NULL) {
                            {
                              depth = depth + 1;
                              if (depth > queryenvironment->current_depth_cutoff) {
                                if (frame->down != NULL) {
                                  pop_frames_down_to(frame->down);
                                }
                                depth = depth - 1;
                                frame = handle_depth_violation(frame, depth, depth);
                                proposition = frame->proposition;
                                lastmove = KWD_QUERY_UP_FAIL;
                              }
                              else if (frame->down != NULL) {
                                frame = frame->down;
                                proposition = frame->proposition;
                                lastmove = KWD_QUERY_DOWN;
                              }
                              else {
                                { Control_Frame* upframe = frame;

                                  proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                                  frame = create_down_frame(upframe, proposition);
                                  frame->debug_depth = depth;
                                  lastmove = KWD_QUERY_DOWN;
                                }
                              }
                            }
                          }
                          {
                            update_goal_cache(frame, FALSE);
                            depth = depth - 1;
                            frame = frame->up;
                            proposition = frame->proposition;
                            pop_control_frame(queryenvironment);
                            if (!(frame->down->down == NULL)) {
                              cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                            }
                            frame->down = NULL;
                            lastmove = KWD_QUERY_UP_FAIL;
                          }
                        }
                        else {
                          cerr << "`" << test_value_003 << "'" << " is not a valid case option";
                        }
                      }
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_TRUE) {
                    if (frame->down != NULL) {
                      {
                        if (frame->up != NULL) {
                          update_goal_cache(frame, TRUE);
                        }
                        depth = depth - 1;
                        frame = frame->up;
                        if (frame == NULL) {
                          { 
                            oCONTEXTo = old_OcontextO_001;
                            oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
                            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                            return (TRUE);
                          }
                        }
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                    else {
                      {
                        if (frame->up != NULL) {
                          update_goal_cache(frame, TRUE);
                        }
                        depth = depth - 1;
                        frame = frame->up;
                        if (frame == NULL) {
                          { 
                            oCONTEXTo = old_OcontextO_001;
                            oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
                            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                            return (TRUE);
                          }
                        }
                        pop_control_frame(queryenvironment);
                        if (frame != NULL) {
                          if (!(frame->down->down == NULL)) {
                            cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                          }
                          frame->down = NULL;
                        }
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_FAIL) {
                    lastmove = KWD_QUERY_DOWN;
                  }
                  else {
                    cerr << "`" << lastmove << "'" << " is not a valid case option";
                  }
                }
                else if (test_value_001 == KWD_QUERY_PATTERN) {
                  if (lastmove == KWD_QUERY_DOWN) {
                    reset_current_variable_frame_offset(frame, KWD_QUERY_LOCAL);
                    if (!(frame->down != NULL)) {
                      cerr << "Safety violation: " << "INTERNAL ERROR: Missing down frame.";
                    }
                    {
                      depth = depth + 1;
                      if (depth > queryenvironment->current_depth_cutoff) {
                        if (frame->down != NULL) {
                          pop_frames_down_to(frame->down);
                        }
                        depth = depth - 1;
                        frame = handle_depth_violation(frame, depth, depth);
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                      else if (frame->down != NULL) {
                        frame = frame->down;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_DOWN;
                      }
                      else {
                        { Control_Frame* upframe = frame;

                          proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                          frame = create_down_frame(upframe, proposition);
                          frame->debug_depth = depth;
                          lastmove = KWD_QUERY_DOWN;
                        }
                      }
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_TRUE) {
                    { boolean futurebindingsP = frame->down != NULL;

                      if (transfer_pattern_query_bindingsP(frame, futurebindingsP)) {
                        if (futurebindingsP) {
                          {
                            if (frame->up != NULL) {
                              update_goal_cache(frame, TRUE);
                            }
                            depth = depth - 1;
                            frame = frame->up;
                            if (frame == NULL) {
                              { 
                                oCONTEXTo = old_OcontextO_001;
                                oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
                                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                                return (TRUE);
                              }
                            }
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_UP_TRUE;
                          }
                        }
                        else {
                          {
                            if (frame->up != NULL) {
                              update_goal_cache(frame, TRUE);
                            }
                            depth = depth - 1;
                            frame = frame->up;
                            if (frame == NULL) {
                              { 
                                oCONTEXTo = old_OcontextO_001;
                                oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
                                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                                return (TRUE);
                              }
                            }
                            pop_control_frame(queryenvironment);
                            if (frame != NULL) {
                              if (!(frame->down->down == NULL)) {
                                cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                              }
                              frame->down = NULL;
                            }
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_UP_TRUE;
                          }
                        }
                      }
                      else if (futurebindingsP) {
                        {
                          depth = depth + 1;
                          if (depth > queryenvironment->current_depth_cutoff) {
                            if (frame->down != NULL) {
                              pop_frames_down_to(frame->down);
                            }
                            depth = depth - 1;
                            frame = handle_depth_violation(frame, depth, depth);
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_UP_FAIL;
                          }
                          else if (frame->down != NULL) {
                            frame = frame->down;
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_DOWN;
                          }
                          else {
                            { Control_Frame* upframe = frame;

                              proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                              frame = create_down_frame(upframe, proposition);
                              frame->debug_depth = depth;
                              lastmove = KWD_QUERY_DOWN;
                            }
                          }
                        }
                      }
                      else {
                        {
                          if (frame->up != NULL) {
                            update_goal_cache(frame, FALSE);
                          }
                          depth = depth - 1;
                          frame = frame->up;
                          if (frame == NULL) {
                            { 
                              oCONTEXTo = old_OcontextO_001;
                              oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
                              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                              return (FALSE);
                            }
                          }
                          pop_control_frame(queryenvironment);
                          if (frame != NULL) {
                            if (!(frame->down->down == NULL)) {
                              cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                            }
                            frame->down = NULL;
                          }
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_UP_FAIL;
                        }
                      }
                    }
                  }
                  else if ((lastmove == KWD_QUERY_UP_FAIL) ||
                      (lastmove == KWD_QUERY_FAILED_OVERLAY)) {
                    unbind_pattern_variables(frame);
                    {
                      if (frame->up != NULL) {
                        update_goal_cache(frame, FALSE);
                      }
                      depth = depth - 1;
                      frame = frame->up;
                      if (frame == NULL) {
                        { 
                          oCONTEXTo = old_OcontextO_001;
                          oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
                          oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                          return (FALSE);
                        }
                      }
                      pop_control_frame(queryenvironment);
                      if (frame != NULL) {
                        if (!(frame->down->down == NULL)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                        }
                        frame->down = NULL;
                      }
                      proposition = frame->proposition;
                      lastmove = KWD_QUERY_UP_FAIL;
                    }
                  }
                  else {
                    cerr << "`" << lastmove << "'" << " is not a valid case option";
                  }
                }
                else if ((test_value_001 == KWD_QUERY_CONTAINED_BY) ||
                    (test_value_001 == KWD_QUERY_ITERATIVE_FORALL)) {
                  if (lastmove == KWD_QUERY_DOWN) {
                    if (frame->state == KWD_QUERY_CONTAINED_BY) {
                      reset_current_variable_frame_offset(frame, KWD_QUERY_LOCAL);
                    }
                    {
                      depth = depth + 1;
                      if (depth > queryenvironment->current_depth_cutoff) {
                        if (frame->down != NULL) {
                          pop_frames_down_to(frame->down);
                        }
                        depth = depth - 1;
                        frame = handle_depth_violation(frame, depth, depth);
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                      else if (frame->down != NULL) {
                        frame = frame->down;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_DOWN;
                      }
                      else {
                        { Control_Frame* upframe = frame;

                          proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                          frame = create_down_frame(upframe, proposition);
                          frame->debug_depth = depth;
                          lastmove = KWD_QUERY_DOWN;
                        }
                      }
                    }
                    frame->up->back = frame;
                  }
                  else if (lastmove == KWD_QUERY_UP_TRUE) {
                    switch (frame->argument_cursor) {
                      case 0: 
                        frame->down = NULL;
                        frame->argument_cursor = 1;
                        {
                          depth = depth + 1;
                          if (depth > queryenvironment->current_depth_cutoff) {
                            if (frame->down != NULL) {
                              pop_frames_down_to(frame->down);
                            }
                            depth = depth - 1;
                            frame = handle_depth_violation(frame, depth, depth);
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_UP_FAIL;
                          }
                          else if (frame->down != NULL) {
                            frame = frame->down;
                            proposition = frame->proposition;
                            lastmove = KWD_QUERY_DOWN;
                          }
                          else {
                            { Control_Frame* upframe = frame;

                              proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                              frame = create_down_frame(upframe, proposition);
                              frame->debug_depth = depth;
                              lastmove = KWD_QUERY_DOWN;
                            }
                          }
                        }
                      break;
                      case 1: 
                        if (frame->down != NULL) {
                          pop_frames_down_to(frame->down);
                        }
                        if (frame->back->state == KWD_QUERY_POPPED) {
                          {
                            update_goal_cache(frame, TRUE);
                            depth = depth - 1;
                            frame = frame->up;
                            proposition = frame->proposition;
                            pop_control_frame(queryenvironment);
                            if (!(frame->down->down == NULL)) {
                              cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                            }
                            frame->down = NULL;
                            lastmove = KWD_QUERY_UP_TRUE;
                          }
                        }
                        else {
                          {
                            frame->down = frame->back;
                            frame->argument_cursor = 0;
                            {
                              depth = depth + 1;
                              if (depth > queryenvironment->current_depth_cutoff) {
                                if (frame->down != NULL) {
                                  pop_frames_down_to(frame->down);
                                }
                                depth = depth - 1;
                                frame = handle_depth_violation(frame, depth, depth);
                                proposition = frame->proposition;
                                lastmove = KWD_QUERY_UP_FAIL;
                              }
                              else if (frame->down != NULL) {
                                frame = frame->down;
                                proposition = frame->proposition;
                                lastmove = KWD_QUERY_DOWN;
                              }
                              else {
                                { Control_Frame* upframe = frame;

                                  proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                                  frame = create_down_frame(upframe, proposition);
                                  frame->debug_depth = depth;
                                  lastmove = KWD_QUERY_DOWN;
                                }
                              }
                            }
                          }
                        }
                      break;
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_FAIL) {
                    switch (frame->argument_cursor) {
                      case 0: 
                        if (!(frame->back->state == KWD_QUERY_POPPED)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Failed to pop antecedent frame.";
                        }
                        {
                          update_goal_cache(frame, TRUE);
                          depth = depth - 1;
                          frame = frame->up;
                          proposition = frame->proposition;
                          pop_control_frame(queryenvironment);
                          if (!(frame->down->down == NULL)) {
                            cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                          }
                          frame->down = NULL;
                          lastmove = KWD_QUERY_UP_TRUE;
                        }
                      break;
                      case 1: 
                        if (!(frame->back->state == KWD_QUERY_POPPED)) {
                          pop_frames_down_to(frame->back);
                        }
                        {
                          update_goal_cache(frame, FALSE);
                          depth = depth - 1;
                          frame = frame->up;
                          proposition = frame->proposition;
                          pop_control_frame(queryenvironment);
                          if (!(frame->down->down == NULL)) {
                            cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                          }
                          frame->down = NULL;
                          lastmove = KWD_QUERY_UP_FAIL;
                        }
                      break;
                    }
                  }
                  else {
                    cerr << "`" << lastmove << "'" << " is not a valid case option";
                  }
                }
                else if (test_value_001 == KWD_QUERY_SELECT_STRATEGY) {
                  { Keyword* test_value_004 = select_next_proof_strategy(frame, lastmove);

                    if (test_value_004 == KWD_QUERY_FINAL_SUCCESS) {
                      {
                        update_goal_cache(frame, TRUE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        pop_control_frame(queryenvironment);
                        if (!(frame->down->down == NULL)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                        }
                        frame->down = NULL;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                    else if (test_value_004 == KWD_QUERY_FAILURE) {
                      {
                        update_goal_cache(frame, FALSE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        pop_control_frame(queryenvironment);
                        if (!(frame->down->down == NULL)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                        }
                        frame->down = NULL;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                    }
                    else if (test_value_004 == KWD_QUERY_SUBGOAL) {
                      {
                        depth = depth + 1;
                        if (depth > queryenvironment->current_depth_cutoff) {
                          if (frame->down != NULL) {
                            pop_frames_down_to(frame->down);
                          }
                          depth = depth - 1;
                          frame = handle_depth_violation(frame, depth, depth);
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_UP_FAIL;
                        }
                        else if (frame->down != NULL) {
                          frame = frame->down;
                          proposition = frame->proposition;
                          lastmove = KWD_QUERY_DOWN;
                        }
                        else {
                          { Control_Frame* upframe = frame;

                            proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                            frame = create_down_frame(upframe, proposition);
                            frame->debug_depth = depth;
                            lastmove = KWD_QUERY_DOWN;
                          }
                        }
                      }
                    }
                    else {
                      cerr << "`" << test_value_004 << "'" << " is not a valid case option";
                    }
                  }
                }
                else if (test_value_001 == KWD_QUERY_EXISTS) {
                  if (lastmove == KWD_QUERY_DOWN) {
                    {
                      depth = depth + 1;
                      if (depth > queryenvironment->current_depth_cutoff) {
                        if (frame->down != NULL) {
                          pop_frames_down_to(frame->down);
                        }
                        depth = depth - 1;
                        frame = handle_depth_violation(frame, depth, depth);
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                      else if (frame->down != NULL) {
                        frame = frame->down;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_DOWN;
                      }
                      else {
                        { Control_Frame* upframe = frame;

                          proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                          frame = create_down_frame(upframe, proposition);
                          frame->debug_depth = depth;
                          lastmove = KWD_QUERY_DOWN;
                        }
                      }
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_TRUE) {
                    if (frame->down == NULL) {
                      {
                        update_goal_cache(frame, TRUE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        pop_control_frame(queryenvironment);
                        if (!(frame->down->down == NULL)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                        }
                        frame->down = NULL;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                    else {
                      {
                        update_goal_cache(frame, TRUE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_FAIL) {
                    if (frame->down == NULL) {
                      {
                        update_goal_cache(frame, FALSE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        pop_control_frame(queryenvironment);
                        if (!(frame->down->down == NULL)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                        }
                        frame->down = NULL;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                    }
                    else {
                      {
                        update_goal_cache(frame, FALSE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                    }
                  }
                  else {
                    cerr << "`" << lastmove << "'" << " is not a valid case option";
                  }
                }
                else if (test_value_001 == KWD_QUERY_FORALL) {
                  { boolean test_value_005 = FALSE;

                    if (frame->reverse_polarityP) {
                      test_value_005 = TRUE;
                    }
                    else {
                      { boolean alwaysP_001 = TRUE;

                        { Pattern_Variable* var = NULL;
                          Vector* vector_001 = ((Vector*)(dynamic_slot_value(proposition, SYM_QUERY_IO_VARIABLES, NULL)));
                          int index_001 = 0;
                          int length_001 = vector_001->length();

                          while (index_001 < length_001) {
                            {
                              var = ((Pattern_Variable*)(vector_001->nth(index_001)));
                              index_001 = index_001 + 1;
                            }
                            if (!closed_collectionP(logical_type(var)->get_description())) {
                              alwaysP_001 = FALSE;
                              {
                                break;
                              }
                            }
                          }
                        }
                        test_value_005 = alwaysP_001;
                      }
                    }
                    if (test_value_005) {
                      {
                        frame->state = KWD_QUERY_ITERATIVE_FORALL;
                        lastmove = KWD_QUERY_DOWN;
                      }
                    }
                    else {
                      {
                        {
                          update_goal_cache(frame, FALSE);
                          depth = depth - 1;
                          frame = frame->up;
                          proposition = frame->proposition;
                          pop_control_frame(queryenvironment);
                          if (!(frame->down->down == NULL)) {
                            cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                          }
                          frame->down = NULL;
                          lastmove = KWD_QUERY_UP_FAIL;
                        }
                      }
                    }
                  }
                }
                else if (test_value_001 == KWD_QUERY_CACHED_BINDINGS) {
                  if (!(lastmove == KWD_QUERY_DOWN)) {
                    cerr << "Safety violation: " << "INTERNAL ERROR: Illeal move into :CACHED-BINDINGS state.";
                  }
                  create_choice_point(frame);
                  { Keyword* test_value_006 = scan_cached_bindings(frame);

                    if (test_value_006 == KWD_QUERY_CONTINUING_SUCCESS) {
                      {
                        update_goal_cache(frame, TRUE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                    else if (test_value_006 == KWD_QUERY_FINAL_SUCCESS) {
                      {
                        update_goal_cache(frame, TRUE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        pop_control_frame(queryenvironment);
                        if (!(frame->down->down == NULL)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                        }
                        frame->down = NULL;
                        lastmove = KWD_QUERY_UP_TRUE;
                      }
                    }
                    else if (test_value_006 == KWD_QUERY_FAILURE) {
                      {
                        update_goal_cache(frame, FALSE);
                        depth = depth - 1;
                        frame = frame->up;
                        proposition = frame->proposition;
                        pop_control_frame(queryenvironment);
                        if (!(frame->down->down == NULL)) {
                          cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                        }
                        frame->down = NULL;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                    }
                    else {
                      cerr << "`" << test_value_006 << "'" << " is not a valid case option";
                    }
                  }
                }
                else if (test_value_001 == KWD_QUERY_FAIL) {
                  if (frame->reverse_polarityP) {
                    cerr << ":FAIL not implemented for negative polarity.";
                  }
                  if (partialmatchP) {
                    lastmove = interpret_fail_score(frame, lastmove);
                  }
                  if (lastmove == KWD_QUERY_DOWN) {
                    create_choice_point(frame);
                    {
                      depth = depth + 1;
                      if (depth > queryenvironment->current_depth_cutoff) {
                        if (frame->down != NULL) {
                          pop_frames_down_to(frame->down);
                        }
                        depth = depth - 1;
                        frame = handle_depth_violation(frame, depth, depth);
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_UP_FAIL;
                      }
                      else if (frame->down != NULL) {
                        frame = frame->down;
                        proposition = frame->proposition;
                        lastmove = KWD_QUERY_DOWN;
                      }
                      else {
                        { Control_Frame* upframe = frame;

                          proposition = ((Proposition*)(proposition->arguments->nth(upframe->argument_cursor)));
                          frame = create_down_frame(upframe, proposition);
                          frame->debug_depth = depth;
                          lastmove = KWD_QUERY_DOWN;
                        }
                      }
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_TRUE) {
                    unbind_pattern_variables(frame);
                    {
                      update_goal_cache(frame, FALSE);
                      depth = depth - 1;
                      frame = frame->up;
                      proposition = frame->proposition;
                      pop_control_frame(queryenvironment);
                      if (!(frame->down->down == NULL)) {
                        cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                      }
                      frame->down = NULL;
                      lastmove = KWD_QUERY_UP_FAIL;
                    }
                  }
                  else if (lastmove == KWD_QUERY_UP_FAIL) {
                    unbind_pattern_variables(frame);
                    {
                      update_goal_cache(frame, TRUE);
                      depth = depth - 1;
                      frame = frame->up;
                      proposition = frame->proposition;
                      pop_control_frame(queryenvironment);
                      if (!(frame->down->down == NULL)) {
                        cerr << "Safety violation: " << "INTERNAL ERROR: Forgot to pop frame " << "below top frame.";
                      }
                      frame->down = NULL;
                      lastmove = KWD_QUERY_UP_TRUE;
                    }
                  }
                  else {
                    cerr << "`" << lastmove << "'" << " is not a valid case option";
                  }
                }
                else {
                  cerr << "`" << test_value_001 << "'" << " is not a valid case option";
                }
              }
            }
          }
          oCONTEXTo = old_OcontextO_001;
          oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oCONTEXTo = old_OcontextO_001;
        oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
        resignal();
      }
    }
  }
}

Keyword* select_next_proof_strategy(Control_Frame* frame, Keyword* lastmove) {
  { Keyword* test_value_001 = frame->phase;

    if (test_value_001 == KWD_QUERY_END_SUBUMPTION_TEST) {
      if (lastmove == KWD_QUERY_UP_TRUE) {
        if (frame->down != NULL) {
          pop_frames_down_to(frame->down);
        }
        return (KWD_QUERY_FINAL_SUCCESS);
      }
      else {
        return (KWD_QUERY_FAILURE);
      }
    }
    else if (test_value_001 == KWD_QUERY_HEAVY_DUTY_DISJUNCTION) {
      return (continue_disjunction_proof(frame, lastmove));
    }
    else {
      cerr << "`" << test_value_001 << "'" << " is not a valid case option";
    }
  }
}

Object* Slot::apply_slot_to_native_query_arguments(Vector* arguments) {
  { Slot* slot = this;

    arguments = arguments;
    return (BOTTOM);
  }
}

Object* Storage_Slot::apply_slot_to_native_query_arguments(Vector* arguments) {
  { Storage_Slot* slot = this;

    if (logic_slotP(slot)) {
      return (BOTTOM);
    }
    { Object* firstarg = native_value_of(arguments->nth(0));

      if (firstarg != NULL) {
        return (read_slot_value(((Standard_Object*)(firstarg)), slot));
      }
      else {
        return (BOTTOM);
      }
    }
  }
}

Object* Method_Slot::apply_slot_to_native_query_arguments(Vector* arguments) {
  { Method_Slot* slot = this;

    if (logic_slotP(slot)) {
      return (BOTTOM);
    }
    { cpp_method_code code = slot->method_code;

      if (code == NULL) {
        return (BOTTOM);
      }
      switch (slot->method_argument_count()) {
        case 1: 
          { Object* firstarg = native_argument_bound_to(arguments->nth(0));

            if (firstarg != NULL) {
              return ((firstarg->*((Object* (Object::*) ()) code)) ());
            }
            else {
              return (BOTTOM);
            }
          }
        break;
        case 2: 
          { Object* firstarg = native_argument_bound_to(arguments->nth(0));
            Object* secondarg = native_argument_bound_to(arguments->nth(1));

            if ((firstarg != NULL) &&
                (secondarg != NULL)) {
              return ((firstarg->*((Object* (Object::*) (Object*)) code)) (secondarg));
            }
            else {
              return (BOTTOM);
            }
          }
        break;
        case 3: 
          { Object* firstarg = native_argument_bound_to(arguments->nth(0));
            Object* secondarg = native_argument_bound_to(arguments->nth(1));
            Object* thirdarg = native_argument_bound_to(arguments->nth(2));

            if ((firstarg != NULL) &&
                ((secondarg != NULL) &&
                 (thirdarg != NULL))) {
              return ((firstarg->*((Object* (Object::*) (Object*, Object*)) code)) (secondarg, thirdarg));
            }
            else {
              return (BOTTOM);
            }
          }
        break;
        case 4: 
          { Object* firstarg = native_argument_bound_to(arguments->nth(0));
            Object* secondarg = native_argument_bound_to(arguments->nth(1));
            Object* thirdarg = native_argument_bound_to(arguments->nth(2));
            Object* fourtharg = native_argument_bound_to(arguments->nth(3));

            if ((firstarg != NULL) &&
                ((secondarg != NULL) &&
                 ((thirdarg != NULL) &&
                  (fourtharg != NULL)))) {
              return ((firstarg->*((Object* (Object::*) (Object*, Object*, Object*)) code)) (secondarg, thirdarg, fourtharg));
            }
            else {
              return (BOTTOM);
            }
          }
        break;
        case 5: 
          { Object* firstarg = native_argument_bound_to(arguments->nth(0));
            Object* secondarg = native_argument_bound_to(arguments->nth(1));
            Object* thirdarg = native_argument_bound_to(arguments->nth(2));
            Object* fourtharg = native_argument_bound_to(arguments->nth(3));
            Object* fiftharg = native_argument_bound_to(arguments->nth(4));

            if ((firstarg != NULL) &&
                ((secondarg != NULL) &&
                 ((thirdarg != NULL) &&
                  ((fourtharg != NULL) &&
                   (fiftharg != NULL))))) {
              return ((firstarg->*((Object* (Object::*) (Object*, Object*, Object*, Object*)) code)) (secondarg, thirdarg, fourtharg, fiftharg));
            }
            else {
              return (BOTTOM);
            }
          }
        break;
        default:
          cerr << "Too many arguments in predication.  Max 5.  Slot is " << "`" << slot << "'";
          return (BOTTOM);
      }
    }
  }
}

boolean read_OreversepolarityPO() {
  return (oREVERSEPOLARITYpo);
}

boolean write_OreversepolarityPO(boolean value) {
  oREVERSEPOLARITYpo = value;
  return (value);
}

Keyword* continue_atomic_proposition_proof(Control_Frame* frame, Keyword* lastmove) {
  { boolean old_OreversepolarityPO_001 = oREVERSEPOLARITYpo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oREVERSEPOLARITYpo = frame->reverse_polarityP;
          { Proposition* proposition = frame->proposition;
            Keyword* result = NULL;

            if (oREVERSEPOLARITYpo &&
                (!all_arguments_boundP(proposition))) {
              { 
                oREVERSEPOLARITYpo = old_OreversepolarityPO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (KWD_QUERY_FAILURE);
              }
            }
            result = access_goal_cache(frame);
            if (result != NULL) {
              { 
                oREVERSEPOLARITYpo = old_OreversepolarityPO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (result);
              }
            }
            { Keyword* test_value_001 = proposition->kind;

              if (test_value_001 == KWD_QUERY_FUNCTION) {
                result = continue_function_proposition_proof(proposition, frame);
              }
              else if (test_value_001 == KWD_QUERY_IN) {
                result = continue_in_proposition_proof(proposition, frame);
              }
              else if (test_value_001 == KWD_QUERY_PREDICATE) {
                result = continue_predicate_proposition_proof(proposition, frame);
              }
              else if (test_value_001 == KWD_QUERY_EQUIVALENT) {
                result = continue_equivalent_proposition_proof(proposition, frame);
              }
              else if (test_value_001 == KWD_QUERY_IMPLIES) {
                result = continue_implies_proposition_proof(proposition, frame, lastmove);
              }
              else if (test_value_001 == KWD_QUERY_CONSTANT) {
                result = continue_constant_proposition_proof(proposition, frame);
              }
              else {
                cerr << "`" << test_value_001 << "'" << " is not a valid case option";
              }
            }
            if (oREVERSEPOLARITYpo &&
                (result == KWD_QUERY_CONTINUING_SUCCESS)) {
              { 
                oREVERSEPOLARITYpo = old_OreversepolarityPO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (KWD_QUERY_FINAL_SUCCESS);
              }
            }
            else {
              { 
                oREVERSEPOLARITYpo = old_OreversepolarityPO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (result);
              }
            }
          }
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

boolean all_arguments_boundP(Proposition* goal) {
  { Object* arg = NULL;
    Vector* vector_001 = goal->arguments;
    int index_001 = 0;
    int length_001 = vector_001->length();

    while (index_001 < length_001) {
      {
        arg = vector_001->nth(index_001);
        index_001 = index_001 + 1;
      }
      { Object* arg_001 = arg;

        if (taxonomy_isaP(arg, SGT_QUERY_PATTERN_VARIABLE)) {
          { Pattern_Variable* arg = NULL;

            arg = ((Pattern_Variable*)(arg_001));
            if (bound_to(arg) == NULL) {
              return (FALSE);
            }
          }
        }
        else if (taxonomy_isaP(arg, SGT_QUERY_PROPOSITION)) {
          { Proposition* arg = NULL;

            arg = ((Proposition*)(arg_001));
            if (!all_arguments_boundP(arg)) {
              return (FALSE);
            }
          }
        }
        else {
        }
      }
    }
  }
  return (TRUE);
}

Object* find_specializing_function_proposition_value(Proposition* self) {
  { Logic_Object* logicargument = find_logic_object_bound_to_argument(self);

    if (logicargument != NULL) {
      if (attribute_propositionP(self)) {
        { Proposition* prop = NULL;
          Iterator* iter_001 = all_dependent_attribute_propositions(logicargument, KWD_QUERY_FUNCTION);

          while (iter_001->nextP()) {
            {
              prop = ((Proposition*)(iter_001->value));
            }
            if (specializes_attribute_propositionP(prop, self)) {
              return (last_argument(prop)->value_of());
            }
          }
        }
      }
      else {
        { Object* prop = NULL;
          Iterator* iter_002 = all_directly_dependent_propositions(logicargument, KWD_QUERY_FUNCTION);

          while (iter_002->nextP()) {
            {
              prop = iter_002->value;
            }
            if (specializes_predicate_propositionP(((Proposition*)(prop)), self)) {
              return (last_argument(((Proposition*)(prop)))->value_of());
            }
          }
        }
      }
    }
    return (NULL);
  }
}

Object* query_for_asserted_function_proposition_value(Proposition* self) {
  { Object* value = NULL;

    value = find_specializing_function_proposition_value(self);
    if (value != NULL) {
      return (value);
    }
    { Slot* slot = operator_bound_to(self->renamed_Operator);

      if (slot == NULL) {
        return (NULL);
      }
      value = slot->apply_slot_to_native_query_arguments(self->arguments);
    }
    if (bottomP(value)) {
      return (NULL);
    }
    else {
      return (value);
    }
  }
}

Keyword* manufacture_defining_skolem(Slot* slot, Proposition* goalproposition) {
  { Cons* argumentvalues = NIL;

    { Object* arg = NULL;
      Vector* vector_001 = goalproposition->arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        argumentvalues = cons(argument_bound_to(arg), argumentvalues);
      }
    }
    { boolean test_value_001 = FALSE;

      if (argumentvalues->first() != NULL) {
        test_value_001 = TRUE;
      }
      else {
        { boolean foundP_001 = FALSE;

          { Object* value = NULL;
            Cons* iter_001 = argumentvalues->rest;

            while (!nilP(iter_001)) {
              {
                value = iter_001->value;
                iter_001 = iter_001->rest;
              }
              if (value == NULL) {
                foundP_001 = TRUE;
                break;
              }
            }
          }
          test_value_001 = foundP_001;
        }
      }
      if (test_value_001) {
        return (KWD_QUERY_FAILURE);
      }
    }
    { Cons* inputvalues = argumentvalues->rest->reverse();
      Proposition* definingproposition = create_function_proposition(slot->slot_slotref, inputvalues);

      bind_variable_to_valueP(((Pattern_Variable*)(last_argument(goalproposition))), last_argument(definingproposition), TRUE);
      return (KWD_QUERY_FINAL_SUCCESS);
    }
  }
}

Keyword* continue_function_proposition_proof(Proposition* self, Control_Frame* frame) {
  { boolean firstoccurrenceP = frame->iterator == NULL;
    boolean singlevaluedbindingsP = FALSE;

    if (firstoccurrenceP) {
      { Slot* slot = operator_bound_to(self->renamed_Operator);

        if (slot == NULL) {
          return (KWD_QUERY_FAILURE);
        }
        { Object* value = slot->apply_slot_to_native_query_arguments(self->arguments);

          if (!bottomP(value)) {
            { boolean successfulbindingP = bind_variable_to_valueP(((Pattern_Variable*)(last_argument(self))), value, TRUE);

              if (oREVERSEPOLARITYpo) {
                return ((successfulbindingP ? ((Keyword*)(KWD_QUERY_FAILURE)) : ((Keyword*)(KWD_QUERY_FINAL_SUCCESS))));
              }
              else {
                return ((successfulbindingP ? ((Keyword*)(KWD_QUERY_FINAL_SUCCESS)) : ((Keyword*)(KWD_QUERY_FAILURE))));
              }
            }
          }
        }
      }
      frame->iterator = all_specializing_propositions(self);
      singlevaluedbindingsP = argument_boundP(self->arguments->first());
    }
    if (frame->iterator->nextP()) {
      if (singlevaluedbindingsP) {
        return (KWD_QUERY_FINAL_SUCCESS);
      }
      else {
        return (KWD_QUERY_CONTINUING_SUCCESS);
      }
    }
  }
  if (oREVERSEPOLARITYpo) {
    { Directly_Dependent_Propositions_Iterator* clashiterator = all_clashing_propositions(self);

      { boolean old_OreversepolarityPO_001 = oREVERSEPOLARITYpo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oREVERSEPOLARITYpo = FALSE;
              if (clashiterator->nextP()) {
                clashiterator->free();
                { 
                  oREVERSEPOLARITYpo = old_OreversepolarityPO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  return (KWD_QUERY_FINAL_SUCCESS);
                }
              }
              clashiterator->free();
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
  { Slot* slot = operator_bound_to(self->renamed_Operator);
    Description* description = ((Description*)(dynamic_slot_value(slot, SYM_QUERY_DESCRIPTION, NULL)));

    if (slot->totalP_reader() &&
        (!oREVERSEPOLARITYpo)) {
      { Keyword* result = manufacture_defining_skolem(slot, self);

        if (result == KWD_QUERY_FINAL_SUCCESS) {
          return (result);
        }
      }
    }
    if (description != NULL) {
      return (overlay_with_subgoals_frame(frame, description, self->arguments, FALSE, KWD_QUERY_ALL_SUBGOAL_PHASES));
    }
    else {
      return (KWD_QUERY_FAILURE);
    }
  }
}

Keyword* continue_predicate_proposition_proof(Proposition* self, Control_Frame* frame) {
  { boolean allargsboundfirsttimeP = FALSE;

    if (frame->iterator == NULL) {
      { Slot* slot = operator_bound_to(self->renamed_Operator);

        if (slot == NULL) {
          return (KWD_QUERY_FAILURE);
        }
        { Object* value = slot->apply_slot_to_native_query_arguments(self->arguments);

          if (!bottomP(value)) {
            if (oREVERSEPOLARITYpo) {
              return ((eqlP(value, FALSE_WRAPPER) ? ((Keyword*)(KWD_QUERY_FINAL_SUCCESS)) : ((Keyword*)(KWD_QUERY_FAILURE))));
            }
            else {
              return ((eqlP(value, TRUE_WRAPPER) ? ((Keyword*)(KWD_QUERY_FINAL_SUCCESS)) : ((Keyword*)(KWD_QUERY_FAILURE))));
            }
          }
        }
      }
      frame->iterator = all_specializing_propositions(self);
      allargsboundfirsttimeP = all_arguments_boundP(self);
    }
    if (frame->iterator->nextP()) {
      if (allargsboundfirsttimeP) {
        return (KWD_QUERY_FINAL_SUCCESS);
      }
      else {
        return (KWD_QUERY_CONTINUING_SUCCESS);
      }
    }
    { Description* description = ((Description*)(dynamic_slot_value(((Slot*)(((Surrogate*)(self->renamed_Operator))->surrogate_value)), SYM_QUERY_DESCRIPTION, NULL)));

      if (description != NULL) {
        return (overlay_with_subgoals_frame(frame, description, self->arguments, FALSE, KWD_QUERY_ALL_SUBGOAL_PHASES));
      }
      else {
        return (KWD_QUERY_FAILURE);
      }
    }
  }
}

Keyword* continue_equivalent_proposition_proof(Proposition* self, Control_Frame* frame) {
  frame = frame;
  { Vector* arguments = self->arguments;
    Object* firstarg = arguments->nth(0);
    Object* firstvalue = argument_bound_to(firstarg);
    Object* secondarg = arguments->nth(1);
    Object* secondvalue = argument_bound_to(secondarg);
    boolean successP = FALSE;

    if (oREVERSEPOLARITYpo) {
      return ((eqlP(firstvalue, secondvalue) ? ((Keyword*)(KWD_QUERY_FAILURE)) : ((Keyword*)(KWD_QUERY_FINAL_SUCCESS))));
    }
    if (firstvalue != NULL) {
      if (secondvalue != NULL) {
        successP = eqlP(firstvalue, secondvalue);
      }
      else {
        successP = bind_variable_to_valueP(((Pattern_Variable*)(secondarg)), firstvalue, TRUE);
      }
    }
    else {
      if (secondvalue != NULL) {
        successP = bind_variable_to_valueP(((Pattern_Variable*)(firstarg)), secondvalue, TRUE);
      }
      else {
        successP = FALSE;
      }
    }
    return ((successP ? ((Keyword*)(KWD_QUERY_FINAL_SUCCESS)) : ((Keyword*)(KWD_QUERY_FAILURE))));
  }
}

Keyword* continue_in_proposition_proof(Proposition* self, Control_Frame* frame) {
  { Vector* arguments = self->arguments;
    Object* memberarg = arguments->nth(0);
    Object* collection = NULL;

    for (;;) {
      { Keyword* test_value_001 = frame->phase;

        if (test_value_001 == KWD_QUERY_INITIAL) {
          { Object* member = argument_bound_to(memberarg);

            collection = argument_bound_to(arguments->nth(1));
            if (!(collection != NULL)) {
              cerr << "Safety violation: " << "INTERNAL ERROR: Bug in query optimizer: " << "Unbound collection variable " << "`" << self->arguments->nth(1) << "'" << " encountered during query evaluation.";
            }
            if (member != NULL) {
              { Keyword* result = collection_has_member(collection, member);

                if (result != NULL) {
                  return (result);
                }
                else {
                  frame->phase = KWD_QUERY_SUBGOALS_OVERLAY;
                }
              }
            }
            else {
              {
                frame->iterator = collection_members(collection, KWD_QUERY_OPEN);
                if (frame->iterator != NULL) {
                  frame->phase = KWD_QUERY_SCAN_COLLECTION;
                }
                else {
                  frame->phase = KWD_QUERY_SUBGOALS_OVERLAY;
                }
              }
            }
          }
        }
        else if (test_value_001 == KWD_QUERY_SCAN_COLLECTION) {
          while (frame->iterator->nextP()) {
            if (bind_variable_to_valueP(((Pattern_Variable*)(memberarg)), frame->iterator->value->value_of(), TRUE)) {
              return (KWD_QUERY_CONTINUING_SUCCESS);
            }
          }
          frame->iterator->free();
          frame->phase = KWD_QUERY_SUBGOALS_OVERLAY;
        }
        else if (test_value_001 == KWD_QUERY_SUBGOALS_OVERLAY) {
          if (collection == NULL) {
            collection = argument_bound_to(arguments->nth(1));
          }
          if (inferrable_descriptionP(collection)) {
            return (overlay_with_subgoals_frame(frame, ((Description*)(collection)), arguments, TRUE, KWD_QUERY_ALL_SUBGOAL_PHASES));
          }
          else {
            return (KWD_QUERY_FAILURE);
          }
        }
        else {
          cerr << "`" << test_value_001 << "'" << " is not a valid case option";
        }
      }
    }
  }
}

boolean inferrable_descriptionP(Object* self) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_QUERY_DESCRIPTION)) {
      { Description* self = NULL;

        self = ((Description*)(self_001));
        if (oREVERSEPOLARITYpo &&
            (((Description*)(dynamic_slot_value(self, SYM_QUERY_COMPLEMENT_DESCRIPTION, NULL))) != NULL)) {
          self = ((Description*)(dynamic_slot_value(self, SYM_QUERY_COMPLEMENT_DESCRIPTION, NULL)));
        }
        { boolean test_value_001 = FALSE;

          if (!self->primitiveP()) {
            test_value_001 = TRUE;
          }
          else {
            { boolean foundP_001 = FALSE;

              { Proposition* p = NULL;
                Cons* iter_001 = self->dependent_propositions->the_cons_list;

                while (!nilP(iter_001)) {
                  {
                    p = ((Proposition*)(iter_001->value));
                    iter_001 = iter_001->rest;
                  }
                  if ((p->kind == KWD_QUERY_IMPLIES) &&
                      (self == p->arguments->nth(1))) {
                    foundP_001 = TRUE;
                    break;
                  }
                }
              }
              test_value_001 = foundP_001;
            }
          }
          { boolean value_001 = test_value_001;

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

boolean unnamed_descriptionP(Object* self) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_QUERY_DESCRIPTION)) {
      { Description* self = NULL;

        self = ((Description*)(self_001));
        return (self->native_relation == NULL);
      }
    }
    else {
      return (FALSE);
    }
  }
}

Keyword* continue_implies_proposition_proof(Proposition* self, Control_Frame* frame, Keyword* lastmove) {
  { Object* subcollectionarg = self->arguments->first();
    Object* supercollectionarg = self->arguments->second();
    Object* subcollection = NULL;
    Object* supercollection = NULL;

    for (;;) {
      { Keyword* test_value_001 = frame->phase;

        if (test_value_001 == KWD_QUERY_INITIAL) {
          subcollection = argument_bound_to(subcollectionarg);
          supercollection = argument_bound_to(supercollectionarg);
          if (subcollection == NULL) {
            if (supercollection == NULL) {
              if (!((subcollection != NULL) &&
                  (supercollection != NULL))) {
                cerr << "Safety violation: " << "INTERNAL ERROR: Bug in query optimizer: " << "two unbound :IMPLIES arguments.";
              }
            }
            frame->iterator = all_subcollections(((Logic_Object*)(supercollection)));
            frame->phase = KWD_QUERY_SCAN_SUBCOLLECTIONS;
          }
          else if (supercollection == NULL) {
            frame->iterator = all_supercollections(((Logic_Object*)(subcollection)));
            frame->phase = KWD_QUERY_SCAN_SUPERCOLLECTIONS;
          }
          else {
            if ((!unnamed_descriptionP(subcollection)) &&
                ((!unnamed_descriptionP(supercollection)) &&
                 collection_implies_collectionP(subcollection, supercollection))) {
              return (KWD_QUERY_FINAL_SUCCESS);
            }
            if ((!inferrable_descriptionP(subcollection)) &&
                (!inferrable_descriptionP(supercollection))) {
              return (collection_contained_in_collection(subcollection, supercollection));
            }
            if (closed_collectionP(subcollection)) {
              frame->phase = KWD_QUERY_DO_CONTAINED_BY;
            }
            else {
              frame->phase = KWD_QUERY_SUBSUMPTION_OVERLAY;
            }
          }
        }
        else if ((test_value_001 == KWD_QUERY_SCAN_SUBCOLLECTIONS) ||
            (test_value_001 == KWD_QUERY_SCAN_SUPERCOLLECTIONS)) {
          while (frame->iterator->nextP()) {
            if (bind_variable_to_valueP(((Pattern_Variable*)(((frame->phase == KWD_QUERY_SCAN_SUBCOLLECTIONS) ? ((Object*)(supercollectionarg)) : ((Object*)(subcollectionarg))))), frame->iterator->value->value_of(), TRUE)) {
              return (KWD_QUERY_CONTINUING_SUCCESS);
            }
          }
          frame->iterator->free();
          return (KWD_QUERY_FAILURE);
        }
        else if (test_value_001 == KWD_QUERY_DO_CONTAINED_BY) {
          if (lastmove == KWD_QUERY_DOWN) {
            return (spawn_contained_by_subquery(frame, subcollection, supercollection));
          }
          else if (lastmove == KWD_QUERY_UP_TRUE) {
            return (KWD_QUERY_FINAL_SUCCESS);
          }
          else if (lastmove == KWD_QUERY_UP_FAIL) {
            frame->phase = KWD_QUERY_SUBSUMPTION_OVERLAY;
          }
          else {
            cerr << "`" << lastmove << "'" << " is not a valid case option";
          }
        }
        else if (test_value_001 == KWD_QUERY_SUBSUMPTION_OVERLAY) {
          if (subcollection == NULL) {
            subcollection = argument_bound_to(subcollectionarg);
            supercollection = argument_bound_to(supercollectionarg);
          }
          if (isaP(subcollection, SGT_QUERY_DESCRIPTION) &&
              (isaP(supercollection, SGT_QUERY_DESCRIPTION) &&
               description_specializes_descriptionP(((Description*)(subcollection)), ((Description*)(supercollection))))) {
            return (KWD_QUERY_FINAL_SUCCESS);
          }
          else {
            return (KWD_QUERY_FAILURE);
          }
        }
        else {
          cerr << "`" << test_value_001 << "'" << " is not a valid case option";
        }
      }
    }
  }
}

Keyword* spawn_contained_by_subquery(Control_Frame* upframe, Object* tail, Object* head) {
  { Proposition* proposition = create_proposition(SYM_QUERY_CONTAINED_BY, 2);
    Vector* arguments = proposition->arguments;
    Description* description = (isaP(tail, SGT_QUERY_DESCRIPTION) ? ((Description*)(((Description*)(tail)))) : ((Description*)(((Description*)(head)))));
    int arity = description->arity();
    List* bridgearguments = new_list();
    Control_Frame* containedbyframe = create_down_frame(upframe, proposition);

    { Pattern_Variable* vbl = NULL;
      int i = NULL_INTEGER;
      int iter_001 = 0;
      Vector* vector_001 = description->io_variables;
      int index_001 = 0;
      int length_001 = vector_001->length();

      while (index_001 < length_001) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        {
          vbl = ((Pattern_Variable*)(vector_001->nth(index_001)));
          index_001 = index_001 + 1;
        }
        { Pattern_Variable* bridgevbl = new_pattern_variable();

          bridgevbl->bound_to_offset = i;
          set_dynamic_slot_value(bridgevbl, SYM_QUERY_SKOLEM_NAME, ((Symbol*)(dynamic_slot_value(vbl, SYM_QUERY_SKOLEM_NAME, NULL))), NULL);
          bridgevbl->root_type = vbl->root_type;
          bridgearguments->insert_last(bridgevbl);
        }
      }
    }
    containedbyframe->state = KWD_QUERY_CONTAINED_BY;
    containedbyframe->proposition = proposition;
    arguments->nth_setter(create_contained_by_argument(tail, bridgearguments, FALSE), 0);
    arguments->nth_setter(create_contained_by_argument(head, bridgearguments, TRUE), 1);
    containedbyframe->iterator = allocate_subquery_frame(NULL, NULL);
    ((Subquery_Frame*)(containedbyframe->iterator))->control_frame = containedbyframe;
    allocate_block_of_variable_frames(arity, containedbyframe);
    return (KWD_QUERY_SPAWNED_SUBQUERY);
  }
}

Proposition* create_contained_by_argument(Object* collection, List* bridgeargs, boolean lastcallP) {
  { Proposition* inproposition = create_proposition(SYM_QUERY_IN, 2);
    Vector* arguments = inproposition->arguments;

    arguments->nth_setter(collection, 1);
    if (isaP(collection, SGT_QUERY_DESCRIPTION) &&
        (((Description*)(collection))->arity() > 1)) {
      arguments->nth_setter(bridgeargs, 0);
    }
    else {
      {
        arguments->nth_setter(bridgeargs->first(), 0);
        if (lastcallP) {
          bridgeargs->free();
        }
      }
    }
    return (inproposition);
  }
}

Keyword* continue_constant_proposition_proof(Proposition* self, Control_Frame* frame) {
  frame = frame;
  if (oREVERSEPOLARITYpo) {
    if (falseP(self)) {
      return (KWD_QUERY_FINAL_SUCCESS);
    }
    else {
      return (KWD_QUERY_FAILURE);
    }
  }
  else {
    if (trueP(self)) {
      return (KWD_QUERY_FINAL_SUCCESS);
    }
    else {
      return (KWD_QUERY_FAILURE);
    }
  }
}

Keyword* overlay_with_pattern_frame(Control_Frame* frame, Description* description) {
  { Subquery_Frame* subqueryframe = ((Subquery_Frame*)(frame->iterator));
    Vector* externalarguments = subqueryframe->external_arguments;
    Description* optimalpattern = select_optimal_query_pattern(description, subqueryframe->boolean_vector, frame);
    Cons* externalbindings = NIL;

    frame->state = KWD_QUERY_PATTERN;
    subqueryframe->optimal_pattern = optimalpattern;
    frame->proposition = optimalpattern->proposition;
    { Object* arg = NULL;
      Vector* vector_001 = externalarguments;
      int index_001 = 0;
      int length_001 = vector_001->length();
      Cons* collect_001 = NULL;

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(argument_bound_to(arg), NIL);
            if (nilP(externalbindings)) {
              externalbindings = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(externalbindings, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(argument_bound_to(arg), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    { int variablescount = optimalpattern->io_variables->length() + optimalpattern->internal_variables->length();

      allocate_block_of_variable_frames(variablescount, frame);
    }
    { Object* extbinding = NULL;
      Pattern_Variable* iovar = NULL;
      Vector* vector_002 = optimalpattern->io_variables;
      int index_002 = 0;
      int length_002 = vector_002->length();
      Cons* iter_001 = externalbindings;

      while ((index_002 < length_002) &&
          (!nilP(iter_001))) {
        {
          iovar = ((Pattern_Variable*)(vector_002->nth(index_002)));
          index_002 = index_002 + 1;
        }
        {
          extbinding = iter_001->value;
          iter_001 = iter_001->rest;
        }
        if ((extbinding != NULL) &&
            (!bind_variable_to_valueP(iovar, extbinding, FALSE))) {
          return (KWD_QUERY_FAILED_OVERLAY);
        }
      }
    }
    free_cons_list(externalbindings);
    { Pattern_Variable* internalvar = NULL;
      Vector* vector_003 = optimalpattern->internal_variables;
      int index_003 = 0;
      int length_003 = vector_003->length();

      while (index_003 < length_003) {
        {
          internalvar = ((Pattern_Variable*)(vector_003->nth(index_003)));
          index_003 = index_003 + 1;
        }
        if (FALSE) {
          if (!bind_variable_to_valueP(internalvar, internalvar->binding_to_constant()->value_of(), FALSE)) {
            return (KWD_QUERY_FAILURE);
          }
        }
      }
    }
    if (frame->down == NULL) {
      create_down_frame(frame, optimalpattern->proposition);
    }
    return (KWD_QUERY_OVERLAY);
  }
}

boolean transfer_pattern_query_bindingsP(Control_Frame* frame, boolean futurebindingsP) {
  if ((oTRACED_KEYWORDSo != NULL) &&
      oTRACED_KEYWORDSo->memberP(KWD_QUERY_QUERY_STACKS)) {
    cout << "TRANSFER-pattern-query-bindings?: " << endl;
  }
  { Subquery_Frame* subqueryframe = ((Subquery_Frame*)(frame->iterator));
    Boolean_Vector* booleanvector = subqueryframe->boolean_vector;
    Vector* externalarguments = subqueryframe->external_arguments;
    Vector* iovariables = subqueryframe->optimal_pattern->io_variables;
    int lastindex = booleanvector->length() - 1;
    Cons* iovariablevalues = NIL;
    int topunbindingoffset = NULL_INTEGER;

    { int i = NULL_INTEGER;
      int iter_001 = 0;
      int upper_bound_001 = lastindex;
      boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;
      Cons* collect_001 = NULL;

      while (unboundedP_001 ||
          (iter_001 <= upper_bound_001)) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(((!((Boolean_Wrapper*)(booleanvector->nth(i)))->wrapper_value) ? ((Object*)(bound_to(((Pattern_Variable*)(iovariables->nth(i)))))) : ((Object*)(NULL))), NIL);
            if (nilP(iovariablevalues)) {
              iovariablevalues = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(iovariablevalues, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(((!((Boolean_Wrapper*)(booleanvector->nth(i)))->wrapper_value) ? ((Object*)(bound_to(((Pattern_Variable*)(iovariables->nth(i)))))) : ((Object*)(NULL))), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    if (!futurebindingsP) {
      unbind_pattern_variables(frame);
    }
    reset_current_variable_frame_offset(frame, KWD_QUERY_PARENT);
    topunbindingoffset = oQUERYENVIRONMENTo->top_unbinding_stack_offset;
    { Boolean_Wrapper* initiallyboundP = NULL;
      Object* externalarg = NULL;
      Object* value = NULL;
      Cons* iter_002 = iovariablevalues;
      Vector* vector_001 = externalarguments;
      int index_001 = 0;
      int length_001 = vector_001->length();
      Boolean_Vector* vector_002 = booleanvector;
      int index_002 = 0;
      int length_002 = vector_002->length();

      while ((!nilP(iter_002)) &&
          ((index_001 < length_001) &&
           (index_002 < length_002))) {
        {
          value = iter_002->value;
          iter_002 = iter_002->rest;
        }
        {
          externalarg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        {
          initiallyboundP = ((Boolean_Wrapper*)(vector_002->nth(index_002)));
          index_002 = index_002 + 1;
        }
        if (!initiallyboundP->wrapper_value) {
          if (!bind_argument_to_valueP(externalarg, value, FALSE)) {
            if ((oTRACED_KEYWORDSo != NULL) &&
                oTRACED_KEYWORDSo->memberP(KWD_QUERY_QUERY_STACKS)) {
              cout << "TRANSFER FAILS! " << endl;
            }
            unbind_variables_beginning_at(topunbindingoffset + 1);
            free_cons_list(iovariablevalues);
            if (futurebindingsP) {
              reset_current_variable_frame_offset(frame, KWD_QUERY_LOCAL);
            }
            return (FALSE);
          }
        }
      }
    }
    free_cons_list(iovariablevalues);
    return (TRUE);
  }
}

Iterator* allocate_antecedents_iterator(Subquery_Frame* subqueryframe, boolean reversepolarityP) {
  { Description* goaldescription = subqueryframe->description;
    Vector* externalarguments = subqueryframe->external_arguments;
    Cons* antecedents = NIL;
    Description* antecedentdescription = NULL;
    boolean failstypecheckP = FALSE;

    if ((goaldescription->native_relation != NULL) &&
        goaldescription->native_relation->sortP_reader()) {
      return (NULL);
    }
    { Proposition* prop = NULL;
      Cons* iter_001 = goaldescription->dependent_propositions->the_cons_list;

      while (!nilP(iter_001)) {
        {
          prop = ((Proposition*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if ((prop->kind == KWD_QUERY_IMPLIES) &&
            (((reversepolarityP ? ((boolean)(prop->arguments->first() == goaldescription)) : ((boolean)(prop->arguments->second() == goaldescription)))) &&
             trueP(prop))) {
          antecedentdescription = ((Description*)((reversepolarityP ? ((Object*)(prop->arguments->second())) : ((Object*)(prop->arguments->first())))));
          failstypecheckP = FALSE;
          { Object* arg = NULL;
            Pattern_Variable* v = NULL;
            Vector* vector_001 = antecedentdescription->io_variables;
            int index_001 = 0;
            int length_001 = vector_001->length();
            Vector* vector_002 = externalarguments;
            int index_002 = 0;
            int length_002 = vector_002->length();

            while ((index_001 < length_001) &&
                (index_002 < length_002)) {
              {
                v = ((Pattern_Variable*)(vector_001->nth(index_001)));
                index_001 = index_001 + 1;
              }
              {
                arg = vector_002->nth(index_002);
                index_002 = index_002 + 1;
              }
              { Object* value = argument_bound_to(arg);

                if ((value != NULL) &&
                    fails_type_checkP(v, value)) {
                  failstypecheckP = TRUE;
                  break;
                }
              }
            }
          }
          if (!failstypecheckP) {
            antecedents = cons(prop, antecedents);
          }
        }
      }
    }
    if (antecedents->emptyP()) {
      return (NULL);
    }
    else {
      return (((Iterator*)(antecedents->allocate_destructive_list_iterator())));
    }
  }
}

Keyword* continue_subgoals_proof(Control_Frame* frame) {
  { Subquery_Frame* subqueryframe = ((Subquery_Frame*)(frame->iterator));
    Description* description = subqueryframe->description;
    boolean reversepolarityP = frame->reverse_polarityP;

    for (;;) {
      { Keyword* test_value_001 = frame->phase;

        if (test_value_001 == KWD_QUERY_INITIAL) {
          if (reversepolarityP &&
              (((Description*)(dynamic_slot_value(description, SYM_QUERY_COMPLEMENT_DESCRIPTION, NULL))) != NULL)) {
            { Description* complement = ((Description*)(dynamic_slot_value(description, SYM_QUERY_COMPLEMENT_DESCRIPTION, NULL)));

              frame->reverse_polarityP = FALSE;
              frame->phase = KWD_QUERY_COMPLEMENT;
              return (spawn_subquery(frame, complement, (complement->primitiveP() ? ((Keyword*)(KWD_QUERY_SKIP_DEFINITION)) : ((Keyword*)(KWD_QUERY_ALL_SUBGOAL_PHASES))), FALSE));
            }
          }
          frame->phase = KWD_QUERY_PRE_ANTECEDENTS;
        }
        else if (test_value_001 == KWD_QUERY_COMPLEMENT) {
          frame->reverse_polarityP = TRUE;
          frame->phase = KWD_QUERY_PRE_ANTECEDENTS;
        }
        else if (test_value_001 == KWD_QUERY_PRE_ANTECEDENTS) {
          { Iterator* iterator = allocate_antecedents_iterator(subqueryframe, reversepolarityP);

            if (iterator != NULL) {
              {
                subqueryframe->iterator = iterator;
                frame->phase = KWD_QUERY_ANTECEDENTS;
              }
            }
            else {
              { Keyword* test_value_002 = subqueryframe->phases_filter;

                if (test_value_002 == KWD_QUERY_ALL_SUBGOAL_PHASES) {
                  frame->phase = KWD_QUERY_DEFINITION;
                }
                else if (test_value_002 == KWD_QUERY_SKIP_DEFINITION) {
                  return (KWD_QUERY_FAILURE);
                }
                else {
                  cerr << "`" << test_value_002 << "'" << " is not a valid case option";
                }
              }
            }
          }
        }
        else if (test_value_001 == KWD_QUERY_ANTECEDENTS) {
          { Iterator* iterator = subqueryframe->iterator;
            Proposition* impliesproposition = NULL;
            Description* antecedentdescription = NULL;

            if (iterator->nextP()) {
              impliesproposition = ((Proposition*)(iterator->value));
              antecedentdescription = ((Description*)((reversepolarityP ? ((Object*)(impliesproposition->arguments->second())) : ((Object*)(impliesproposition->arguments->first())))));
              return (spawn_subquery(frame, antecedentdescription, (impliesproposition->subrelation_linkP_reader() ? ((Keyword*)(KWD_QUERY_SKIP_DEFINITION)) : ((Keyword*)(KWD_QUERY_FULL_SUBQUERY))), FALSE));
            }
            subqueryframe->iterator = NULL;
            iterator->free();
            { Keyword* test_value_003 = subqueryframe->phases_filter;

              if (test_value_003 == KWD_QUERY_ALL_SUBGOAL_PHASES) {
                frame->phase = KWD_QUERY_DEFINITION;
              }
              else if (test_value_003 == KWD_QUERY_SKIP_DEFINITION) {
                return (KWD_QUERY_FAILURE);
              }
              else {
                cerr << "`" << test_value_003 << "'" << " is not a valid case option";
              }
            }
          }
        }
        else if (test_value_001 == KWD_QUERY_DEFINITION) {
          { Relation* relation = description->native_relation;
            Description* definition = ((relation != NULL) ? ((Description*)(((Description*)(dynamic_slot_value(relation, SYM_QUERY_DEFINITION, NULL))))) : ((Description*)(description)));

            if (definition != NULL) {
              return (spawn_subquery(frame, definition, NULL, TRUE));
            }
            else {
              return (KWD_QUERY_FAILURE);
            }
          }
        }
        else {
          cerr << "`" << test_value_001 << "'" << " is not a valid case option";
        }
      }
    }
  }
}

Subquery_Frame* new_top_subquery_frame() {
  return (new_subquery_frame());
}

Subquery_Frame* allocate_subquery_frame(Description* description, Vector* externalarguments) {
  { Subquery_Frame* subqueryframe = new_top_subquery_frame();

    if (description != NULL) {
      subqueryframe->description = description;
      subqueryframe->external_arguments = externalarguments;
      subqueryframe->boolean_vector = arguments_vector_to_boolean_vector(externalarguments);
    }
    oQUERYENVIRONMENTo->current_subquery_frame = subqueryframe;
    return (subqueryframe);
  }
}

boolean terminate_subquery_frameP(Subquery_Frame* self) {
  if ((oQUERYENVIRONMENTo->current_subquery_frame == self) &&
      (self->control_frame->parent_pattern_frame != NULL)) {
    oQUERYENVIRONMENTo->current_subquery_frame = ((Subquery_Frame*)(self->control_frame->parent_pattern_frame->iterator));
  }
  if (self->external_arguments != NULL) {
    self->external_arguments->free();
  }
  if (self->iterator != NULL) {
    self->iterator->free();
  }
  self->iterator = NULL;
  self->optimal_pattern = NULL;
  return (TRUE);
}

Vector* copy_subquery_arguments(Vector* arguments, boolean omitlastargumentP, Description* description) {
  if (omitlastargumentP &&
      ((description->arity() > 1) &&
       isaP(arguments->first(), SGT_QUERY_LIST))) {
    { List* tuple = ((List*)(arguments->first()));
      Vector* copiedarguments = new_vector(tuple->length());

      { Object* value = NULL;
        int i = NULL_INTEGER;
        int iter_001 = 0;
        int upper_bound_001 = tuple->length() - 1;
        Cons* iter_002 = tuple->the_cons_list;

        while ((iter_001 <= upper_bound_001) &&
            (!nilP(iter_002))) {
          {
            i = iter_001;
            iter_001 = iter_001 + 1;
          }
          {
            value = iter_002->value;
            iter_002 = iter_002->rest;
          }
          copiedarguments->nth_setter(value, i);
        }
      }
      return (copiedarguments);
    }
  }
  else {
    { int argumentcount = (omitlastargumentP ? ((int)(arguments->length() - 1)) : ((int)(arguments->length())));
      Vector* copiedarguments = new_vector(argumentcount);

      { int i = NULL_INTEGER;
        int iter_003 = 0;
        int upper_bound_002 = argumentcount - 1;

        while (iter_003 <= upper_bound_002) {
          {
            i = iter_003;
            iter_003 = iter_003 + 1;
          }
          copiedarguments->nth_setter(arguments->nth(i), i);
        }
      }
      return (copiedarguments);
    }
  }
}

Keyword* overlay_with_subgoals_frame(Control_Frame* frame, Description* description, Vector* externalarguments, boolean omitlastargumentP, Keyword* phasesfilter) {
  if (frame->iterator != NULL) {
    frame->iterator->free();
  }
  frame->state = KWD_QUERY_SUBGOALS;
  frame->phase = KWD_QUERY_INITIAL;
  { Subquery_Frame* subqueryframe = allocate_subquery_frame(description, copy_subquery_arguments(externalarguments, omitlastargumentP, description));

    frame->iterator = subqueryframe;
    subqueryframe->control_frame = frame;
    subqueryframe->phases_filter = phasesfilter;
    subqueryframe->local_variable_frame_offset = ((Subquery_Frame*)(frame->parent_pattern_frame->iterator))->local_variable_frame_offset;
  }
  return (KWD_QUERY_OVERLAY);
}

Keyword* spawn_subquery(Control_Frame* upframe, Description* description, Keyword* phasesfilter, boolean overlayP) {
  if (overlayP) {
    return (overlay_with_pattern_frame(upframe, description));
  }
  { Subquery_Frame* subqueryframe = ((Subquery_Frame*)(upframe->iterator));
    Vector* externalarguments = subqueryframe->external_arguments;
    Control_Frame* downframe = create_down_frame(upframe, NULL);

    overlay_with_subgoals_frame(downframe, description, externalarguments, FALSE, phasesfilter);
    if (phasesfilter == KWD_QUERY_FULL_SUBQUERY) {
      return (overlay_with_pattern_frame(downframe, description));
    }
    else {
      return (KWD_QUERY_SPAWNED_SUBQUERY);
    }
  }
}

Keyword* continue_disjunction_proof(Control_Frame* frame, Keyword* lastmove) {
  if (lastmove == KWD_QUERY_DOWN) {
    if (!all_arguments_boundP(frame->proposition)) {
      return (KWD_QUERY_FAILURE);
    }
    push_world();
    set_dynamic_slot_value(((World*)(oCONTEXTo)), SYM_QUERY_MONOTONICp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
    { Proposition* disjunctiveproposition = frame->proposition;
      boolean firstdisjunctP = TRUE;

      { Object* disjunct = NULL;
        Vector* vector_001 = disjunctiveproposition->arguments;
        int index_001 = 0;
        int length_001 = vector_001->length();

        while (index_001 < length_001) {
          {
            disjunct = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          if (firstdisjunctP) {
            firstdisjunctP = FALSE;
          }
          else {
            { Proposition* prop = NULL;
              Cons* iter_001 = inherit_as_top_level_proposition(((Proposition*)(disjunct)))->the_cons_list;

              while (!nilP(iter_001)) {
                {
                  prop = ((Proposition*)(iter_001->value));
                  iter_001 = iter_001->rest;
                }
                if ((oTRACED_KEYWORDSo != NULL) &&
                    oTRACED_KEYWORDSo->memberP(KWD_QUERY_GOAL_TREE)) {
                  cout << "assume that " << prop << " is FALSE." << endl;
                }
                assign_truth_value(prop, FALSE);
              }
            }
          }
        }
      }
      frame->argument_cursor = 0;
      return (KWD_QUERY_SUBGOAL);
    }
  }
  else if (lastmove == KWD_QUERY_UP_TRUE) {
    pop_world();
    return (KWD_QUERY_FINAL_SUCCESS);
  }
  else if (lastmove == KWD_QUERY_UP_FAIL) {
    pop_world();
    return (KWD_QUERY_FAILURE);
  }
  else {
    cerr << "`" << lastmove << "'" << " is not a valid case option";
  }
}

boolean disjoint_classesP(Class* class1, Class* class2) {
  return ((!(class1 == class2)) &&
      ((!subclass_ofP(class1, class2)) &&
       ((!subclass_ofP(class2, class1)) &&
        ((((Boolean_Wrapper*)(dynamic_slot_value(class1, SYM_QUERY_NON_DISJOINTNESS_KLUDGEp, NULL))) == NULL) ||
         (((Boolean_Wrapper*)(dynamic_slot_value(class2, SYM_QUERY_NON_DISJOINTNESS_KLUDGEp, NULL))) == NULL)))));
}

boolean root_type_implies_memberP(Object* self, Object* member) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_QUERY_DESCRIPTION)) {
      { Description* self = NULL;

        self = ((Description*)(self_001));
        if (self->native_relation == NULL) {
          return (FALSE);
        }
        if (oREVERSEPOLARITYpo) {
          { Class* rootclass = leftmost_concrete_superclass(((Class*)(self->native_relation)));

            return (disjoint_classesP(((Class*)(logical_type(member)->surrogate_value)), rootclass));
          }
        }
        else {
          return (subclass_ofP(((Class*)(logical_type(member)->surrogate_value)), ((Class*)(self->native_relation))));
        }
      }
    }
    else {
      return (FALSE);
    }
  }
}

Keyword* collection_has_member(Object* self, Object* member) {
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_QUERY_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        if (root_type_implies_memberP(self, member) ||
            exists_specializing_in_propositionP(((Logic_Object*)(member)), self)) {
          return (KWD_QUERY_FINAL_SUCCESS);
        }
        if (closed_collectionP(self)) {
          if (oREVERSEPOLARITYpo) {
            { boolean old_OreversepolarityPO_001 = oREVERSEPOLARITYpo;

              { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                oEXCEPTIONHANDLERADDRESSo = NULL;
                if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                    setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                  {
                    oREVERSEPOLARITYpo = FALSE;
                    { Keyword* return_value_001 = (exists_specializing_in_propositionP(((Logic_Object*)(member)), self) ? ((Keyword*)(KWD_QUERY_FAILURE)) : ((Keyword*)(KWD_QUERY_FINAL_SUCCESS)));

                      oREVERSEPOLARITYpo = old_OreversepolarityPO_001;
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                      return (return_value_001);
                    }
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
          else {
            return (KWD_QUERY_FAILURE);
          }
        }
        return (NULL);
      }
    }
    else if (taxonomy_isaP(self, SGT_QUERY_COLLECTION)) {
      { Collection* self = NULL;

        self = ((Collection*)(self_001));
        { boolean foundP_001 = FALSE;

          { Object* m = NULL;
            Iterator* iter_001 = ((Iterator*)(self->allocate_iterator()));

            while (iter_001->nextP()) {
              {
                m = iter_001->value;
              }
              if (eqlP(m->value_of(), member)) {
                foundP_001 = TRUE;
                break;
              }
            }
          }
          { boolean memberP = foundP_001;

            if (oREVERSEPOLARITYpo) {
              return ((memberP ? ((Keyword*)(KWD_QUERY_FAILURE)) : ((Keyword*)(KWD_QUERY_FINAL_SUCCESS))));
            }
            else {
              return ((memberP ? ((Keyword*)(KWD_QUERY_FINAL_SUCCESS)) : ((Keyword*)(KWD_QUERY_FAILURE))));
            }
          }
        }
      }
    }
    else {
      cerr << "`" << self << "'" << " is not a valid case option";
    }
  }
}

boolean closed_collectionP(Object* self) {
  if (oGLOBALLY_CLOSED_COLLECTIONSpo) {
    return (TRUE);
  }
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_QUERY_COLLECTION)) {
      { Collection* self = NULL;

        self = ((Collection*)(self_001));
        return (TRUE);
      }
    }
    else if (taxonomy_isaP(self, SGT_QUERY_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        { boolean old_OreversepolarityPO_001 = oREVERSEPOLARITYpo;

          { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

            oEXCEPTIONHANDLERADDRESSo = NULL;
            if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
              {
                oREVERSEPOLARITYpo = FALSE;
                { boolean return_value_001 = exists_property_propositionP(self, SGT_QUERY_COLLECTIONdCLOSED);

                  oREVERSEPOLARITYpo = old_OreversepolarityPO_001;
                  oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                  return (return_value_001);
                }
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
    else {
      cerr << "`" << self << "'" << " is not a valid case option";
    }
  }
}

Iterator* collection_members(Object* self, Keyword* openorclosed) {
  if (oREVERSEPOLARITYpo) {
    if (openorclosed == KWD_QUERY_OPEN) {
      openorclosed = KWD_QUERY_CLOSED;
    }
    else if (openorclosed == KWD_QUERY_CLOSED) {
      openorclosed = KWD_QUERY_OPEN;
    }
    else {
      cerr << "`" << openorclosed << "'" << " is not a valid case option";
    }
  }
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_QUERY_COLLECTION)) {
      { Collection* self = NULL;

        self = ((Collection*)(self_001));
        return (((Iterator*)(self->allocate_iterator())));
      }
    }
    else if (taxonomy_isaP(self, SGT_QUERY_DESCRIPTION)) {
      { Description* self = NULL;

        self = ((Description*)(self_001));
        { Keyword* test_value_001 = self->kind;

          if (test_value_001 == KWD_QUERY_PRIMITIVE) {
            if ((openorclosed == KWD_QUERY_OPEN) ||
                closed_collectionP(self)) {
              return (self->allocate_iterator());
            }
          }
          else if (test_value_001 == KWD_QUERY_ENUMERATION) {
            return (self->allocate_iterator());
          }
          else {
            return (NULL);
          }
        }
      }
    }
    else if (taxonomy_isaP(self, SGT_QUERY_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        if ((openorclosed == KWD_QUERY_OPEN) ||
            closed_collectionP(self)) {
          return (all_in_proposition_members(self));
        }
      }
    }
    else {
      return (NULL);
    }
  }
  return (NULL);
}

Keyword* collection_contained_in_collection(Object* subcollection, Object* supercollection) {
  { Iterator* iterator = collection_members(subcollection, KWD_QUERY_CLOSED);

    { boolean test_value_001 = FALSE;

      test_value_001 = iterator != NULL;
      if (test_value_001) {
        { boolean alwaysP_001 = TRUE;

          { Object* m = NULL;
            Iterator* iter_001 = iterator;

            while (iter_001->nextP()) {
              {
                m = iter_001->value;
              }
              if (!(collection_has_member(supercollection, m->value_of()) == KWD_QUERY_FINAL_SUCCESS)) {
                alwaysP_001 = FALSE;
                break;
              }
            }
          }
          test_value_001 = alwaysP_001;
        }
      }
      if (test_value_001) {
        return (KWD_QUERY_FINAL_SUCCESS);
      }
      else {
        return (KWD_QUERY_FAILURE);
      }
    }
  }
}

boolean collection_implies_collectionP(Object* subcollection, Object* supercollection) {
  if (eqlP(subcollection, supercollection)) {
    return (TRUE);
  }
  if (isaP(subcollection, SGT_QUERY_LOGIC_OBJECT) &&
      isaP(supercollection, SGT_QUERY_LOGIC_OBJECT)) {
    return (all_supercollections(((Logic_Object*)(subcollection)))->memberP(supercollection));
  }
  else {
    return (FALSE);
  }
}

Description_Extension_Iterator* new_description_extension_iterator() {
  { Description_Extension_Iterator* self = NULL;

    self = new Description_Extension_Iterator;
    self->first_iterationP = TRUE;
    self->value = NULL;
    self->native_class_extension_iterator = NULL;
    self->filter_type = NULL;
    self->root_type = NULL;
    self->cursor = NULL;
    return (self);
  }
}

Object* access_description_extension_iterator_slot_value(Description_Extension_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_CURSOR) {
    if (setvalueP) {
      self->cursor = ((Cons*)(value));
    }
    else {
      return (self->cursor);
    }
  }
  else if (slotname == SYM_QUERY_ROOT_TYPE) {
    if (setvalueP) {
      self->root_type = ((Surrogate*)(value));
    }
    else {
      return (self->root_type);
    }
  }
  else if (slotname == SYM_QUERY_FILTER_TYPE) {
    if (setvalueP) {
      self->filter_type = ((Surrogate*)(value));
    }
    else {
      return (self->filter_type);
    }
  }
  else if (slotname == SYM_QUERY_NATIVE_CLASS_EXTENSION_ITERATOR) {
    if (setvalueP) {
      self->native_class_extension_iterator = ((Iterator*)(value));
    }
    else {
      return (self->native_class_extension_iterator);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Description_Extension_Iterator::primary_type() {
  { Description_Extension_Iterator* self = this;

    return (SGT_QUERY_DESCRIPTION_EXTENSION_ITERATOR);
  }
}

Description_Extension_Iterator* Description::allocate_iterator() {
  { Description* self = this;

    { Description_Extension_Iterator* iterator = new_description_extension_iterator();
      Class* nativeclass = ((Class*)(self->native_relation));
      Class* rootclass = leftmost_concrete_superclass(nativeclass);

      if (!((nativeclass != NULL) &&
          (!(self->kind == KWD_QUERY_DEFINITION)))) {
        cerr << "Safety violation: " << "INTERNAL ERROR: Illegal call to `DESCRIPTION.allocate-iterator'.";
      }
      if (subsumption_modeP()) {
        { Description* description = oQUERYENVIRONMENTo->specializing_description;
          Cons* internalvariables = NIL;

          { Pattern_Variable* v = NULL;
            Vector* vector_001 = description->internal_variables;
            int index_001 = 0;
            int length_001 = vector_001->length();
            Cons* collect_001 = NULL;

            while (index_001 < length_001) {
              {
                v = ((Pattern_Variable*)(vector_001->nth(index_001)));
                index_001 = index_001 + 1;
              }
              if (collect_001 == NULL) {
                {
                  collect_001 = cons(v, NIL);
                  if (nilP(internalvariables)) {
                    internalvariables = collect_001;
                  }
                  else {
                    add_cons_to_end_of_cons_list(internalvariables, collect_001);
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
          iterator->cursor = internalvariables;
          iterator->root_type = NULL;
        }
      }
      else {
        {
          iterator->cursor = get_description_extension(rootclass)->the_cons_list;
          iterator->root_type = rootclass->class_type;
        }
      }
      iterator->filter_type = nativeclass->class_type;
      return (iterator);
    }
  }
}

boolean Description_Extension_Iterator::nextP() {
  { Description_Extension_Iterator* self = this;

    { Cons* cursor = self->cursor;
      Cons* trailingcursor = NULL;
      Logic_Object* value = NULL;

      if (self->first_iterationP) {
        self->first_iterationP = FALSE;
      }
      else {
        cursor = cursor->rest;
      }
      while (!nilP(cursor)) {
        value = ((Logic_Object*)(cursor->value));
        if (value->deletedP() ||
            (!indexed_by_logical_extensionsP(value))) {
          if (trailingcursor != NULL) {
            trailingcursor->rest = cursor->rest;
            cursor = trailingcursor;
          }
        }
        else if ((self->root_type == self->filter_type) ||
            exists_specializing_in_propositionP(value, self->filter_type)) {
          self->value = value;
          self->cursor = cursor;
          return (TRUE);
        }
        trailingcursor = cursor;
        cursor = cursor->rest;
      }
      return (FALSE);
    }
  }
}

void reserve_query_thread(Query_Environment* queryenvironment) {
  // Find a free query thread and assign it to 'queryEnvironment'.
  // Signal a :QUERY-THREAD-LIMIT-VIOLATION exception if all threads are taken.
  { Integer_Wrapper* offset = ((Integer_Wrapper*)(oFREE_QUERY_THREAD_OFFSETSo->pop()));

    if (offset == NULL) {
      cout << "Releasing all query threads!" << endl;
      clear_query_threads();
      reserve_query_thread(queryenvironment);
      return;
      signal(oTHE_QUERY_THREAD_LIMIT_VIOLATIONo);
    }
    oQUERY_ENVIRONMENTS_VECTORo->nth_setter(queryenvironment, offset->wrapper_value);
    queryenvironment->query_thread_offset = offset->wrapper_value;
    return;
  }
}

void release_query_thread(Query_Environment* queryenvironment) {
  // Release the query thread for 'queryEnvironment'.
  if (queryenvironment == NULL) {
    return;
  }
  { int offset = queryenvironment->query_thread_offset;

    oQUERY_ENVIRONMENTS_VECTORo->nth_setter(NULL, offset);
    oFREE_QUERY_THREAD_OFFSETSo->push(integer_wrap_literal(offset));
  }
}

List* release_all_query_threads() {
  // Free up all query threads (buggy queries may have
  // failed to terminate).
  { int offset = NULL_INTEGER;
    int iter_001 = 0;
    int upper_bound_001 = oMAXIMUM_QUERY_THREAD_OFFSETo;
    boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

    while (unboundedP_001 ||
        (iter_001 <= upper_bound_001)) {
      {
        offset = iter_001;
        iter_001 = iter_001 + 1;
      }
      cout << "off" << offset << " mm " << ((Query_Environment*)(oQUERY_ENVIRONMENTS_VECTORo->nth(offset))) << endl;
      if (((Query_Environment*)(oQUERY_ENVIRONMENTS_VECTORo->nth(offset))) != NULL) {
        free_query_iterator(((Query_Environment*)(oQUERY_ENVIRONMENTS_VECTORo->nth(offset)))->query_iterator);
      }
    }
  }
  return (oFREE_QUERY_THREAD_OFFSETSo);
}

List* clear_query_threads() {
  { int offset = NULL_INTEGER;
    int iter_001 = 0;
    int upper_bound_001 = oMAXIMUM_QUERY_THREAD_OFFSETo;
    boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

    while (unboundedP_001 ||
        (iter_001 <= upper_bound_001)) {
      {
        offset = iter_001;
        iter_001 = iter_001 + 1;
      }
      oQUERY_ENVIRONMENTS_VECTORo->nth_setter(NULL, offset);
      oFREE_QUERY_THREAD_OFFSETSo->insert_new(integer_wrap_literal(offset));
    }
  }
  return (oFREE_QUERY_THREAD_OFFSETSo);
}

Goal_Cache* new_goal_cache() {
  { Goal_Cache* self = NULL;

    self = new Goal_Cache;
    self->cluster = NULL;
    self->up_for_grabsP = FALSE;
    self->reverse_polarity_cached_bindings = new_list();
    self->cached_bindings = new_list();
    return (self);
  }
}

Object* access_goal_cache_slot_value(Goal_Cache* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_CACHED_BINDINGS) {
    if (setvalueP) {
      self->cached_bindings = ((List*)(value));
    }
    else {
      return (self->cached_bindings);
    }
  }
  else if (slotname == SYM_QUERY_REVERSE_POLARITY_CACHED_BINDINGS) {
    if (setvalueP) {
      self->reverse_polarity_cached_bindings = ((List*)(value));
    }
    else {
      return (self->reverse_polarity_cached_bindings);
    }
  }
  else if (slotname == SYM_QUERY_UP_FOR_GRABSp) {
    if (setvalueP) {
      self->up_for_grabsP = ((Boolean_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (wrap_boolean(self->up_for_grabsP));
    }
  }
  else if (slotname == SYM_QUERY_CLUSTER) {
    if (setvalueP) {
      self->cluster = ((Goal_Cache_Cluster*)(value));
    }
    else {
      return (self->cluster);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Goal_Cache::primary_type() {
  { Goal_Cache* self = this;

    return (SGT_QUERY_GOAL_CACHE);
  }
}

List* get_cached_bindings(Goal_Cache* goalcache, Control_Frame* frame) {
  return ((frame->reverse_polarityP ? ((List*)(goalcache->reverse_polarity_cached_bindings)) : ((List*)(goalcache->cached_bindings))));
}

void print_goal_cache(Goal_Cache* self) {
  cout << "<<";
  { Query_Environment* old_OqueryenvironmentO_001 = oQUERYENVIRONMENTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oQUERYENVIRONMENTo = NULL;
          cout << self->cluster->proposition;
          oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
        resignal();
      }
    }
  }
  cout << "  INPUT: ";
  { Goal_Cache* v = NULL;
    Cons* k = NIL;
    Kv_Cons* iter_001 = ((Key_Value_List*)(self->cluster->vector_of_goal_cache_tables->nth(oQUERYENVIRONMENTo->query_thread_offset)))->the_kv_list;

    while (iter_001 != NULL) {
      k = ((Cons*)(iter_001->key));
      {
        v = ((Goal_Cache*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (v == self) {
        cout << k << endl;
        break;
      }
    }
  }
  cout << "    BINDINGS: " << self->cached_bindings;
  if (!self->reverse_polarity_cached_bindings->emptyP()) {
    cout << endl << "    NEGATIVE BINDINGS: " << self->reverse_polarity_cached_bindings;
  }
  cout << ">>" << endl;
}

Goal_Cache_Cluster* new_goal_cache_cluster() {
  { Goal_Cache_Cluster* self = NULL;

    self = new Goal_Cache_Cluster;
    self->proposition = NULL;
    self->time_stamp = NULL_INTEGER;
    self->vector_of_goal_cache_tables = NULL;
    return (self);
  }
}

Object* access_goal_cache_cluster_slot_value(Goal_Cache_Cluster* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_QUERY_VECTOR_OF_GOAL_CACHE_TABLES) {
    if (setvalueP) {
      self->vector_of_goal_cache_tables = ((Vector*)(value));
    }
    else {
      return (self->vector_of_goal_cache_tables);
    }
  }
  else if (slotname == SYM_QUERY_TIME_STAMP) {
    if (setvalueP) {
      self->time_stamp = ((Integer_Wrapper*)(value))->wrapper_value;
    }
    else {
      return (integer_wrap_literal(self->time_stamp));
    }
  }
  else if (slotname == SYM_QUERY_PROPOSITION) {
    if (setvalueP) {
      self->proposition = ((Proposition*)(value));
    }
    else {
      return (self->proposition);
    }
  }
  else {
    cerr << "`" << slotname << "'" << " is not a valid case option";
  }
  if (setvalueP) {
    return (value);
  }
}

Surrogate* Goal_Cache_Cluster::primary_type() {
  { Goal_Cache_Cluster* self = this;

    return (SGT_QUERY_GOAL_CACHE_CLUSTER);
  }
}

Control_Frame* help_find_duplicated_goal(Control_Frame* goalframe, Control_Frame*& return1, int& return2) {
  { Proposition* atomicgoal = goalframe->proposition;
    Cons* bindings = yield_goal_bindings(goalframe);
    int depth = 1;
    Control_Frame* firstgoalframe = NULL;
    Proposition* testgoal = NULL;
    Control_Frame* testframe = NULL;
    Control_Frame* restartframe = NULL;
    int restartdepth = NULL_INTEGER;

    testframe = ((Control_Frame*)(oQUERYENVIRONMENTo->control_frame_stack->nth(0)))->down;
    for (;;) {
      testgoal = testframe->proposition;
      { boolean test_value_001 = FALSE;

        test_value_001 = testgoal != NULL;
        if (test_value_001) {
          test_value_001 = eqlP(testgoal->renamed_Operator, atomicgoal->renamed_Operator);
          if (test_value_001) {
            test_value_001 = (!(testgoal->kind == KWD_QUERY_IN)) ||
                eqlP(testgoal->arguments->nth(1), atomicgoal->arguments->nth(1));
            if (test_value_001) {
              test_value_001 = testframe->reverse_polarityP == goalframe->reverse_polarityP;
              if (test_value_001) {
                { boolean alwaysP_001 = TRUE;

                  { Object* b2 = NULL;
                    Object* b1 = NULL;
                    Cons* iter_001 = bindings;
                    Cons* iter_002 = yield_goal_bindings(testframe);

                    while ((!nilP(iter_001)) &&
                        (!nilP(iter_002))) {
                      {
                        b1 = iter_001->value;
                        iter_001 = iter_001->rest;
                      }
                      {
                        b2 = iter_002->value;
                        iter_002 = iter_002->rest;
                      }
                      if (!eqlP(b1, b2)) {
                        alwaysP_001 = FALSE;
                        break;
                      }
                    }
                  }
                  test_value_001 = alwaysP_001;
                }
              }
            }
          }
        }
        if (test_value_001) {
          if (firstgoalframe == NULL) {
            firstgoalframe = testframe;
          }
          else {
            { Control_Frame* return_temp = firstgoalframe;

              return1 = restartframe;
              return2 = restartdepth;
              return (return_temp);
            }
          }
        }
      }
      restartframe = testframe;
      restartdepth = depth;
      testframe = testframe->down;
      depth = depth + 1;
      if (testframe == NULL) {
        { Control_Frame* return_temp = NULL;

          return1 = NULL;
          return2 = NULL_INTEGER;
          return (return_temp);
        }
      }
    }
  }
}

Control_Frame* find_duplicated_goal(Control_Frame*& return1, int& return2) {
  { Control_Frame* trialframe = NULL;
    Proposition* trialgoal = NULL;

    { int i = NULL_INTEGER;
      Reverse_Integer_Interval_Iterator* iter_001 = interval(2, oQUERYENVIRONMENTo->top_control_frame_offset)->reverse();

      while (iter_001->nextP()) {
        {
          i = iter_001->value;
        }
        trialframe = ((Control_Frame*)(oQUERYENVIRONMENTo->control_frame_stack->nth(i)));
        trialgoal = trialframe->proposition;
        if (trialgoal != NULL) {
          { Keyword* test_value_001 = trialgoal->kind;

            if ((test_value_001 == KWD_QUERY_FUNCTION) ||
                ((test_value_001 == KWD_QUERY_PREDICATE) ||
                 (test_value_001 == KWD_QUERY_IN))) {
              { Control_Frame* goalframe = NULL;
                Control_Frame* restartframe = NULL;
                int restartdepth = NULL_INTEGER;

                goalframe = help_find_duplicated_goal(trialframe, restartframe, restartdepth);
                if (goalframe != NULL) {
                  { Control_Frame* old_OprintinframeO_001 = oPRINTINFRAMEo;

                    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

                      oEXCEPTIONHANDLERADDRESSo = NULL;
                      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                        {
                          oPRINTINFRAMEo = trialframe;
                          if ((oTRACED_KEYWORDSo != NULL) &&
                              oTRACED_KEYWORDSo->memberP(KWD_QUERY_GOAL_CACHES)) {
                            cout << "DUPLICATED GOAL: " << trialgoal << endl << "  DEPTH " << restartdepth << endl;
                          }
                          oPRINTINFRAMEo = old_OprintinframeO_001;
                        }
                        oEXCEPTIONo = NULL;
                      }
                      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                    }
                    if (oEXCEPTIONo != NULL) {
                      if (TRUE) {
                        oPRINTINFRAMEo = old_OprintinframeO_001;
                        resignal();
                      }
                    }
                  }
                  { Control_Frame* return_temp = goalframe;

                    return1 = restartframe;
                    return2 = restartdepth;
                    return (return_temp);
                  }
                }
              }
            }
            else {
            }
          }
        }
      }
    }
    if ((oTRACED_KEYWORDSo != NULL) &&
        oTRACED_KEYWORDSo->memberP(KWD_QUERY_GOAL_CACHES)) {
      cout << "FAILED TO FIND DUPLICATE GOAL" << endl;
    }
    oQUERYENVIRONMENTo->failed_to_find_duplicate_subgoalP = TRUE;
    { Control_Frame* return_temp = NULL;

      return1 = NULL;
      return2 = NULL_INTEGER;
      return (return_temp);
    }
  }
}

Cons* yield_goal_bindings(Control_Frame* frame) {
  { Proposition* goal = frame->proposition;
    Cons* result = NIL;
    int savecurrentoffset = oQUERYENVIRONMENTo->current_variable_frame_offset;

    oQUERYENVIRONMENTo->current_variable_frame_offset = ((Subquery_Frame*)(frame->parent_pattern_frame->iterator))->local_variable_frame_offset;
    { Object* arg = NULL;
      Vector* vector_001 = goal->arguments;
      int index_001 = 0;
      int length_001 = vector_001->length();
      Cons* collect_001 = NULL;

      while (index_001 < length_001) {
        {
          arg = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(argument_bound_to(arg), NIL);
            if (nilP(result)) {
              result = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(result, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(argument_bound_to(arg), NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    oQUERYENVIRONMENTo->current_variable_frame_offset = savecurrentoffset;
    return (result);
  }
}

Goal_Cache* lookup_goal_cache(Goal_Cache_Cluster* cluster, Control_Frame* frame) {
  { Cons* bindings = yield_goal_bindings(frame);

    { Goal_Cache* v = NULL;
      Cons* k = NIL;
      Kv_Cons* iter_001 = ((Key_Value_List*)(cluster->vector_of_goal_cache_tables->nth(oQUERYENVIRONMENTo->query_thread_offset)))->the_kv_list;

      while (iter_001 != NULL) {
        k = ((Cons*)(iter_001->key));
        {
          v = ((Goal_Cache*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        { boolean alwaysP_001 = TRUE;

          { Object* v2 = NULL;
            Object* v1 = NULL;
            Cons* iter_002 = bindings;
            Cons* iter_003 = k;

            while ((!nilP(iter_002)) &&
                (!nilP(iter_003))) {
              {
                v1 = iter_002->value;
                iter_002 = iter_002->rest;
              }
              {
                v2 = iter_003->value;
                iter_003 = iter_003->rest;
              }
              if (!eqlP(v1, v2)) {
                alwaysP_001 = FALSE;
                break;
              }
            }
          }
          if (alwaysP_001) {
            free_cons_list(bindings);
            return (v);
          }
        }
      }
    }
    free_cons_list(bindings);
    return (NULL);
  }
}

Goal_Cache_Cluster* find_goal_cache_cluster(Proposition* goal) {
  { Keyword* test_value_001 = goal->kind;

    if ((test_value_001 == KWD_QUERY_PREDICATE) ||
        (test_value_001 == KWD_QUERY_FUNCTION)) {
      if (goal->renamed_Operator->primary_type() == SGT_QUERY_SURROGATE) {
        return (((Goal_Cache_Cluster*)(dynamic_slot_value(((Slot*)(((Surrogate*)(goal->renamed_Operator))->surrogate_value)), SYM_QUERY_GOAL_CACHE_CLUSTER, NULL))));
      }
    }
    else if (test_value_001 == KWD_QUERY_IN) {
      { Object* secondarg = goal->arguments->nth(1);

        if (secondarg->primary_type() == SGT_QUERY_SURROGATE) {
          return (((Goal_Cache_Cluster*)(dynamic_slot_value(((Class*)(((Surrogate*)(secondarg))->surrogate_value)), SYM_QUERY_GOAL_CACHE_CLUSTER, NULL))));
        }
      }
    }
    else {
      return (NULL);
    }
  }
  return (NULL);
}

Goal_Cache* find_goal_cache(Control_Frame* frame) {
  { Proposition* goal = frame->proposition;
    Goal_Cache_Cluster* cluster = find_goal_cache_cluster(goal);

    if (cluster == NULL) {
      return (NULL);
    }
    else if (cluster->time_stamp < get_now_time_stamp()) {
      ((Key_Value_List*)(cluster->vector_of_goal_cache_tables->nth(oQUERYENVIRONMENTo->query_thread_offset)))->clear();
      return (NULL);
    }
    else {
      return (lookup_goal_cache(cluster, frame));
    }
  }
}

Goal_Cache_Cluster* create_goal_cache_cluster(Proposition* goal) {
  { Goal_Cache_Cluster* cluster = new_goal_cache_cluster();

    cluster->vector_of_goal_cache_tables = new_vector(oQUERY_THREAD_LIMITo);
    { int i = NULL_INTEGER;
      int iter_001 = 0;
      int upper_bound_001 = oMAXIMUM_QUERY_THREAD_OFFSETo;
      boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

      while (unboundedP_001 ||
          (iter_001 <= upper_bound_001)) {
        {
          i = iter_001;
          iter_001 = iter_001 + 1;
        }
        cluster->vector_of_goal_cache_tables->nth_setter(new_key_value_list(), i);
      }
    }
    cluster->proposition = goal;
    return (cluster);
  }
}

boolean create_goal_cacheP(Control_Frame* frame) {
  { Proposition* goal = frame->proposition;
    Goal_Cache_Cluster* cluster = find_goal_cache_cluster(goal);

    if (cluster == NULL) {
      cluster = create_goal_cache_cluster(goal);
      { Keyword* test_value_001 = goal->kind;

        if ((test_value_001 == KWD_QUERY_PREDICATE) ||
            (test_value_001 == KWD_QUERY_FUNCTION)) {
          if (goal->renamed_Operator->primary_type() == SGT_QUERY_SURROGATE) {
            set_dynamic_slot_value(((Slot*)(((Surrogate*)(goal->renamed_Operator))->surrogate_value)), SYM_QUERY_GOAL_CACHE_CLUSTER, cluster, NULL);
          }
          else {
            return (FALSE);
          }
        }
        else if (test_value_001 == KWD_QUERY_IN) {
          { Object* secondarg = goal->arguments->nth(1);

            if (secondarg->primary_type() == SGT_QUERY_SURROGATE) {
              set_dynamic_slot_value(((Class*)(((Surrogate*)(secondarg))->surrogate_value)), SYM_QUERY_GOAL_CACHE_CLUSTER, cluster, NULL);
            }
            else {
              return (FALSE);
            }
          }
        }
        else {
          return (FALSE);
        }
      }
    }
    cluster->time_stamp = get_now_time_stamp();
    { Goal_Cache* goalcache = lookup_goal_cache(cluster, frame);

      if (goalcache == NULL) {
        goalcache = new_goal_cache();
        goalcache->cluster = cluster;
        ((Key_Value_List*)(cluster->vector_of_goal_cache_tables->nth(oQUERYENVIRONMENTo->query_thread_offset)))->insert_at(yield_goal_bindings(frame), goalcache);
        frame->goal_cache = goalcache;
        goalcache->up_for_grabsP = FALSE;
        oQUERYENVIRONMENTo->active_goal_caches->insert(goalcache);
        oQUERYENVIRONMENTo->augmented_goal_cacheP = TRUE;
      }
      return (TRUE);
    }
  }
}

Control_Frame* handle_depth_violation(Control_Frame* frame, int depth, int& return1) {
  if ((oTRACED_KEYWORDSo != NULL) &&
      oTRACED_KEYWORDSo->memberP(KWD_QUERY_GOAL_TREE)) {
    cout << "CUTOFF: depth = " << depth << endl;
  }
  if ((oTRACED_KEYWORDSo != NULL) &&
      oTRACED_KEYWORDSo->memberP(KWD_QUERY_GOAL_CACHES)) {
    cout << "CUTOFF: depth = " << depth << endl;
  }
  oQUERYENVIRONMENTo->triggered_depth_cutoffP = TRUE;
  if (!(frame == oQUERYENVIRONMENTo->control_frame_stack->nth(oQUERYENVIRONMENTo->top_control_frame_offset))) {
    cerr << "Safety violation: " << "INTERNAL ERROR: Depth violation did not occur at the top " << "of the control stack.";
  }
  { Control_Frame* goalframe = NULL;
    Control_Frame* restartframe = NULL;
    int restartdepth = NULL_INTEGER;

    goalframe = find_duplicated_goal(restartframe, restartdepth);
    if ((goalframe != NULL) &&
        ((find_goal_cache(goalframe) == NULL) &&
         create_goal_cacheP(goalframe))) {
      if (restartframe->down != NULL) {
        pop_frames_down_to(restartframe->down);
        restartframe->down = NULL;
      }
      if (!(zeroP(restartframe->debug_depth) ||
          (restartdepth == restartframe->debug_depth))) {
        cerr << "Safety violation: " << "INTERNAL ERROR: Incorrect depth value in restart frame.";
      }
      { Control_Frame* return_temp = restartframe;

        return1 = restartdepth;
        return (return_temp);
      }
    }
  }
  { Control_Frame* return_temp = frame;

    return1 = depth;
    return (return_temp);
  }
}

Keyword* access_goal_cache(Control_Frame* frame) {
  { Proposition* proposition = frame->proposition;
    Goal_Cache* goalcache = NULL;
    List* cachedbindings = NULL;

    { boolean test_value_001 = FALSE;

      { 
        goalcache = find_goal_cache(frame);
        test_value_001 = goalcache != NULL;
      }
      test_value_001 = !test_value_001;
      if (test_value_001) {
        return (NULL);
      }
    }
    if (frame->goal_cache != NULL) {
      if (!(goalcache == frame->goal_cache)) {
        cerr << "Safety violation: " << "INTERNAL ERROR: Found non-matching goal cache.";
      }
      return (NULL);
    }
    else if (goalcache->up_for_grabsP) {
      frame->goal_cache = goalcache;
      goalcache->up_for_grabsP = FALSE;
      return (NULL);
    }
    cachedbindings = get_cached_bindings(goalcache, frame);
    switch (cachedbindings->length()) {
      case 0: 
        if ((oTRACED_KEYWORDSo != NULL) &&
            oTRACED_KEYWORDSo->memberP(KWD_QUERY_GOAL_CACHES)) {
          cout << "EMPTY CACHE: " << proposition << endl;
        }
        return (KWD_QUERY_FAILURE);
      case 1: 
        if ((oTRACED_KEYWORDSo != NULL) &&
            oTRACED_KEYWORDSo->memberP(KWD_QUERY_GOAL_CACHES)) {
          cout << "USED CACHED BINDING: " << proposition << endl;
        }
        if (bind_vector_of_arguments_to_valuesP(proposition->arguments, ((Cons*)(cachedbindings->first())))) {
          return (KWD_QUERY_FINAL_SUCCESS);
        }
        else {
          return (KWD_QUERY_FAILURE);
        }
      break;
      default:
        if ((oTRACED_KEYWORDSo != NULL) &&
            oTRACED_KEYWORDSo->memberP(KWD_QUERY_GOAL_CACHES)) {
          cout << "USED MANY CACHED BINDINGS: " << proposition << endl;
        }
        return (overlay_with_cached_bindings(frame, goalcache));
    }
  }
}

void update_goal_cache(Control_Frame* frame, boolean successP) {
  if (!successP) {
    return;
  }
  { Goal_Cache* goalcache = frame->goal_cache;

    if (goalcache != NULL) {
      { List* cachedbindings = get_cached_bindings(goalcache, frame);
        Cons* bindings = yield_goal_bindings(frame);

        { boolean foundP_001 = FALSE;

          { Cons* oldbindings = NIL;
            Cons* iter_001 = cachedbindings->the_cons_list;

            while (!nilP(iter_001)) {
              {
                oldbindings = ((Cons*)(iter_001->value));
                iter_001 = iter_001->rest;
              }
              { boolean alwaysP_001 = TRUE;

                { Object* v2 = NULL;
                  Object* v1 = NULL;
                  Cons* iter_002 = bindings;
                  Cons* iter_003 = oldbindings;

                  while ((!nilP(iter_002)) &&
                      (!nilP(iter_003))) {
                    {
                      v1 = iter_002->value;
                      iter_002 = iter_002->rest;
                    }
                    {
                      v2 = iter_003->value;
                      iter_003 = iter_003->rest;
                    }
                    if (!eqlP(v1, v2)) {
                      alwaysP_001 = FALSE;
                      break;
                    }
                  }
                }
                if (alwaysP_001) {
                  foundP_001 = TRUE;
                  break;
                }
              }
            }
          }
          if (foundP_001) {
            free_cons_list(bindings);
            return;
          }
        }
        if ((oTRACED_KEYWORDSo != NULL) &&
            oTRACED_KEYWORDSo->memberP(KWD_QUERY_GOAL_CACHES)) {
          cout << "AUGMENT CACHE: " << bindings << "  " << frame << endl;
        }
        cachedbindings->push(bindings);
        oQUERYENVIRONMENTo->augmented_goal_cacheP = TRUE;
      }
    }
  }
}

Keyword* overlay_with_cached_bindings(Control_Frame* frame, Goal_Cache* goalcache) {
  frame->iterator = ((List_Iterator*)(get_cached_bindings(goalcache, frame)->allocate_iterator()));
  frame->state = KWD_QUERY_CACHED_BINDINGS;
  return (KWD_QUERY_OVERLAY);
}

Keyword* scan_cached_bindings(Control_Frame* frame) {
  { Iterator* iterator = frame->iterator;

    while (iterator->nextP()) {
      if (bind_vector_of_arguments_to_valuesP(frame->proposition->arguments, ((Cons*)(iterator->value)))) {
        if (iterator->emptyP()) {
          return (KWD_QUERY_FINAL_SUCCESS);
        }
        else {
          return (KWD_QUERY_CONTINUING_SUCCESS);
        }
      }
    }
    return (KWD_QUERY_FAILURE);
  }
}

void print_control_frame(Control_Frame* self, ostream* stream) {
  *(stream) << "|CF|" << compute_frame_offset(self) << "[";
  if (self->choice_point_unbinding_offset != NULL_INTEGER) {
    *(stream) << self->choice_point_unbinding_offset;
  }
  else {
    *(stream) << "_";
  }
  if ((self->iterator != NULL) &&
      isaP(self->iterator, SGT_QUERY_SUBQUERY_FRAME)) {
    *(stream) << " " << ((Subquery_Frame*)(self->iterator))->local_variable_frame_offset;
  }
  else {
    *(stream) << " " << "_";
  }
  { Control_Frame* old_OprintinframeO_001 = oPRINTINFRAMEo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPRINTINFRAMEo = self;
          *(stream) << " " << self->state << " " << self->phase << "  UP: " << (((self->up != NULL) ? ((int)(compute_frame_offset(self->up))) : ((int)(NULL_INTEGER)))) << "  DOWN: " << (((self->down != NULL) ? ((int)(compute_frame_offset(self->down))) : ((int)(NULL_INTEGER)))) << " " << self->proposition << "]";
          oPRINTINFRAMEo = old_OprintinframeO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPRINTINFRAMEo = old_OprintinframeO_001;
        resignal();
      }
    }
  }
}

void print_goal_stack() {
  // Print stack of goals.  Assumes that query has been interrupted
  // with a full stack of control frames.
  { int i = NULL_INTEGER;
    int iter_001 = 0;
    int upper_bound_001 = oQUERYENVIRONMENTo->top_control_frame_offset;
    boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

    while (unboundedP_001 ||
        (iter_001 <= upper_bound_001)) {
      {
        i = iter_001;
        iter_001 = iter_001 + 1;
      }
      { Control_Frame* frame = ((Control_Frame*)(oQUERYENVIRONMENTo->control_frame_stack->nth(i)));

        if (frame->proposition != NULL) {
          { Control_Frame* old_OprintinframeO_001 = oPRINTINFRAMEo;

            { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

              oEXCEPTIONHANDLERADDRESSo = NULL;
              if ((!oPENDINGEXCEPTIONHANDLERpo) ||
                  setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
                {
                  oPRINTINFRAMEo = frame;
                  cout << frame->proposition << endl;
                  oPRINTINFRAMEo = old_OprintinframeO_001;
                }
                oEXCEPTIONo = NULL;
              }
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
            }
            if (oEXCEPTIONo != NULL) {
              if (TRUE) {
                oPRINTINFRAMEo = old_OprintinframeO_001;
                resignal();
              }
            }
          }
        }
      }
    }
  }
}

void pgs() {
  print_goal_stack();
}

void print_query_iterator(Query_Iterator* self, ostream* stream) {
  { List* solutions = self->solutions;
    int nofsolutions = solutions->length();
    boolean exhaustedP = self->exhaustedP;
    int arity = ((((Vector*)(solutions->first())) != NULL) ? ((int)(((Vector*)(solutions->first()))->length())) : ((int)(NULL_INTEGER)));

    switch (nofsolutions) {
      case 0: 
        if (exhaustedP) {
          *(stream) << "No solutions.";
        }
        else {
          *(stream) << "No solutions so far.";
        }
        return;
      case 1: 
        *(stream) << "There is 1 solution";
      break;
      default:
        *(stream) << "There are " << nofsolutions << " solutions";
      break;
    }
    if (!(exhaustedP)) {
      *(stream) << " so far";
    }
    *(stream) << ":" << endl;
    { int i = NULL_INTEGER;
      Vector* solution = NULL;
      Cons* iter_001 = solutions->the_cons_list;
      int iter_002 = 1;

      while (!nilP(iter_001)) {
        {
          solution = ((Vector*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        {
          i = iter_002;
          iter_002 = iter_002 + 1;
        }
        *(stream) << "  #" << i << ": ";
        { int vi = NULL_INTEGER;
          Object* value = NULL;
          Vector* vector_001 = solution;
          int index_001 = 0;
          int length_001 = vector_001->length();
          int iter_003 = 0;

          while (index_001 < length_001) {
            {
              value = vector_001->nth(index_001);
              index_001 = index_001 + 1;
            }
            {
              vi = iter_003;
              iter_003 = iter_003 + 1;
            }
            *(stream) << ((Symbol*)(dynamic_slot_value(((Pattern_Variable*)(self->external_variables->nth(vi))), SYM_QUERY_SKOLEM_NAME, NULL))) << "=" << value << (((vi < (arity - 1)) ? ((char*)(", ")) : ((char*)(""))));
          }
        }
        if (i < nofsolutions) {
          *(stream) << endl;
        }
      }
    }
  }
}

Query_Iterator* allocate_query_iterator() {
  { Query_Iterator* queryiterator = new_query_iterator();
    Query_Environment* queryenvironment = new_query_environment();

    queryiterator->query_environment = queryenvironment;
    queryenvironment->query_iterator = queryiterator;
    reserve_query_thread(queryenvironment);
    update_now_time_stamp(KWD_QUERY_EXECUTE_QUERY);
    queryenvironment->time_stamp = get_now_time_stamp();
    return (queryiterator);
  }
}

void Query_Iterator::free() {
  { Query_Iterator* self = this;

    free_query_iterator(self);
  }
}

void free_query_iterator(Query_Iterator* self) {
  if (self->query_environment == NULL) {
    return;
  }
  ((Vector*)(self->value))->free();
  self->query_environment->free();
  self->query_environment = NULL;
}

Query_Iterator* create_query_iterator(Description* description, Vector* outsidearguments) {
  { Query_Iterator* queryiterator = allocate_query_iterator();
    Query_Environment* queryenvironment = queryiterator->query_environment;
    Control_Frame* topcontrolframe = new_top_control_frame(queryenvironment);
    int variablescount = description->io_variables->length();
    Vector* externalvariables = new_vector(variablescount);

    { Query_Environment* old_OqueryenvironmentO_001 = oQUERYENVIRONMENTo;
      Keyword* old_OevaluationmodeO_001 = oEVALUATIONMODEo;
      Cons* old_OtoplevelpropositionsO_001 = oTOPLEVELPROPOSITIONSo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oQUERYENVIRONMENTo = queryenvironment;
            oEVALUATIONMODEo = KWD_QUERY_QUERY;
            oTOPLEVELPROPOSITIONSo = NULL;
            topcontrolframe->proposition = description->proposition;
            topcontrolframe->phase = KWD_QUERY_INITIAL;
            topcontrolframe->up = NULL;
            { int i = NULL_INTEGER;
              Pattern_Variable* iovar = NULL;
              Vector* vector_001 = description->io_variables;
              int index_001 = 0;
              int length_001 = vector_001->length();
              int iter_001 = 0;

              while (index_001 < length_001) {
                {
                  iovar = ((Pattern_Variable*)(vector_001->nth(index_001)));
                  index_001 = index_001 + 1;
                }
                {
                  i = iter_001;
                  iter_001 = iter_001 + 1;
                }
                externalvariables->nth_setter(create_variable(iovar->root_type, ((Symbol*)(dynamic_slot_value(iovar, SYM_QUERY_SKOLEM_NAME, NULL))), TRUE), i);
                ((Pattern_Variable*)(externalvariables->nth(i)))->bound_to_offset = i;
              }
            }
            { Subquery_Frame* subqueryframe = new_top_subquery_frame();

              topcontrolframe->iterator = subqueryframe;
              subqueryframe->control_frame = topcontrolframe;
              allocate_block_of_variable_frames(variablescount, topcontrolframe);
              bootstrap_initialize_subquery_frame(subqueryframe, description, externalvariables, outsidearguments);
            }
            overlay_with_pattern_frame(topcontrolframe, description);
            queryenvironment->maximum_depth = oMAXIMUM_BACKTRACKING_DEPTHo;
            queryenvironment->augmented_goal_cacheP = FALSE;
            queryenvironment->active_goal_caches->clear();
            queryenvironment->iterative_deepeningP = oITERATIVE_DEEPENING_MODEpo;
            queryenvironment->current_depth_cutoff = (queryenvironment->iterative_deepeningP ? ((int)(min(oINITIAL_BACKTRACKING_DEPTHo, queryenvironment->maximum_depth))) : ((int)(queryenvironment->maximum_depth)));
            queryenvironment->triggered_depth_cutoffP = FALSE;
            queryenvironment->failed_to_find_duplicate_subgoalP = FALSE;
            queryenvironment->found_at_least_one_solutionP = FALSE;
            queryenvironment->deep_inferenceP = deep_inference_modeP();
            queryiterator->external_variables = externalvariables;
            queryiterator->value = new_vector(variablescount);
            { 
              oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
              oEVALUATIONMODEo = old_OevaluationmodeO_001;
              oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (queryiterator);
            }
            oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
            oEVALUATIONMODEo = old_OevaluationmodeO_001;
            oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oTOPLEVELPROPOSITIONSo = old_OtoplevelpropositionsO_001;
          oEVALUATIONMODEo = old_OevaluationmodeO_001;
          oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
          resignal();
        }
      }
    }
  }
}

void bootstrap_initialize_subquery_frame(Subquery_Frame* subqueryframe, Description* description, Vector* externalarguments, Vector* outsidearguments) {
  if (description != NULL) {
    subqueryframe->description = description;
    subqueryframe->external_arguments = externalarguments;
    if (outsidearguments != NULL) {
      if (outsidearguments->length() > externalarguments->length()) {
        signal(oTHE_FAIL_EXCEPTIONo);
      }
      { Object* value = NULL;
        Object* arg = NULL;
        Vector* vector_001 = externalarguments;
        int index_001 = 0;
        int length_001 = vector_001->length();
        Vector* vector_002 = outsidearguments;
        int index_002 = 0;
        int length_002 = vector_002->length();

        while ((index_001 < length_001) &&
            (index_002 < length_002)) {
          {
            arg = vector_001->nth(index_001);
            index_001 = index_001 + 1;
          }
          {
            value = vector_002->nth(index_002);
            index_002 = index_002 + 1;
          }
          if (!bind_argument_to_valueP(arg, value, FALSE)) {
            signal(oTHE_FAIL_EXCEPTIONo);
          }
        }
      }
    }
    subqueryframe->boolean_vector = arguments_vector_to_boolean_vector(externalarguments);
    subqueryframe->phases_filter = KWD_QUERY_ALL_SUBGOAL_PHASES;
  }
  oQUERYENVIRONMENTo->current_subquery_frame = subqueryframe;
}

boolean Query_Iterator::nextP() {
  { Query_Iterator* self = this;

    { Query_Environment* queryenvironment = self->query_environment;
      Vector* valuevector = ((Vector*)(self->value));

      if (self->exhaustedP) {
        return (FALSE);
      }
      for (;;) {
        while (execute_backward_chaining_proofP(queryenvironment)) {
          { int i = NULL_INTEGER;
            Pattern_Variable* ev = NULL;
            Vector* vector_001 = self->external_variables;
            int index_001 = 0;
            int length_001 = vector_001->length();
            int iter_001 = 0;

            while (index_001 < length_001) {
              {
                ev = ((Pattern_Variable*)(vector_001->nth(index_001)));
                index_001 = index_001 + 1;
              }
              {
                i = iter_001;
                iter_001 = iter_001 + 1;
              }
              valuevector->nth_setter(bound_to(ev), i);
            }
          }
          queryenvironment->found_at_least_one_solutionP = TRUE;
          { boolean foundP_001 = FALSE;

            { Vector* solution = NULL;
              Cons* iter_002 = self->solutions->the_cons_list;

              while (!nilP(iter_002)) {
                {
                  solution = ((Vector*)(iter_002->value));
                  iter_002 = iter_002->rest;
                }
                { boolean alwaysP_001 = TRUE;

                  { Object* newbinding = NULL;
                    Object* oldbinding = NULL;
                    Vector* vector_002 = solution;
                    int index_002 = 0;
                    int length_002 = vector_002->length();
                    Vector* vector_003 = valuevector;
                    int index_003 = 0;
                    int length_003 = vector_003->length();

                    while ((index_002 < length_002) &&
                        (index_003 < length_003)) {
                      {
                        oldbinding = vector_002->nth(index_002);
                        index_002 = index_002 + 1;
                      }
                      {
                        newbinding = vector_003->nth(index_003);
                        index_003 = index_003 + 1;
                      }
                      if (!eqlP(oldbinding, newbinding)) {
                        alwaysP_001 = FALSE;
                        break;
                      }
                    }
                  }
                  if (alwaysP_001) {
                    foundP_001 = TRUE;
                    break;
                  }
                }
              }
            }
            if (foundP_001) {
              continue;
            }
          }
          self->solutions->insert_last(valuevector->copy());
          return (TRUE);
        }
        if (queryenvironment->augmented_goal_cacheP) {
          self->reset();
        }
        else if (queryenvironment->iterative_deepeningP &&
            (queryenvironment->triggered_depth_cutoffP &&
             (queryenvironment->current_depth_cutoff < queryenvironment->maximum_depth))) {
          queryenvironment->current_depth_cutoff = queryenvironment->current_depth_cutoff + 1;
          self->reset();
        }
        else {
          if (queryenvironment->failed_to_find_duplicate_subgoalP &&
              (!queryenvironment->found_at_least_one_solutionP)) {
            cout << "Failed to find a duplicate subgoal on one or more occurrences when" << endl << "   the depth cutoff " << queryenvironment->current_depth_cutoff << " was exceeded.  Consider increasing the cutoff" << endl << "   and trying again." << endl;
          }
          release_query_thread(queryenvironment);
          queryenvironment->query_thread_offset = NULL_INTEGER;
          self->exhaustedP = TRUE;
          return (FALSE);
        }
      }
    }
  }
}

void Query_Iterator::reset() {
  { Query_Iterator* self = this;

    { Query_Environment* queryenvironment = self->query_environment;
      Control_Frame* initialframe = ((Control_Frame*)(queryenvironment->control_frame_stack->nth(0)));

      if (initialframe->down != NULL) {
        pop_frames_down_to(initialframe->down);
      }
      overlay_with_pattern_frame(initialframe, ((Subquery_Frame*)(initialframe->iterator))->description);
      queryenvironment->augmented_goal_cacheP = FALSE;
      { Goal_Cache* goalcache = NULL;
        Cons* iter_001 = queryenvironment->active_goal_caches->the_cons_list;

        while (!nilP(iter_001)) {
          {
            goalcache = ((Goal_Cache*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          goalcache->up_for_grabsP = TRUE;
        }
      }
      queryenvironment->triggered_depth_cutoffP = FALSE;
    }
  }
}

Cons* copy_vector_to_cons_list(Vector* vector) {
  { Cons* result = NIL;

    { Object* element = NULL;
      Vector* vector_001 = vector;
      int index_001 = 0;
      int length_001 = vector_001->length();
      Cons* collect_001 = NULL;

      while (index_001 < length_001) {
        {
          element = vector_001->nth(index_001);
          index_001 = index_001 + 1;
        }
        if (collect_001 == NULL) {
          {
            collect_001 = cons(element, NIL);
            if (nilP(result)) {
              result = collect_001;
            }
            else {
              add_cons_to_end_of_cons_list(result, collect_001);
            }
          }
        }
        else {
          {
            collect_001->rest = cons(element, NIL);
            collect_001 = collect_001->rest;
          }
        }
      }
    }
    return (result);
  }
}

List* Query_Iterator::listify() {
  // Return the list of tuples generated by 'self'.
  // Tuples of arity=1 are represented directly by the first element,
  // tuples of arity>1 are represented by a CONS list.
  { Query_Iterator* self = this;

    { List* solutions = self->solutions;
      List* listifiedsolutions = new_list();
      int arity = 0;

      while (self->nextP()) {
      }
      if (solutions->non_emptyP()) {
        arity = ((Vector*)(solutions->first()))->length();
      }
      { Vector* solution = NULL;
        Cons* iter_001 = solutions->the_cons_list;
        Cons* collect_001 = NULL;

        while (!nilP(iter_001)) {
          {
            solution = ((Vector*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          if (collect_001 == NULL) {
            {
              collect_001 = permanent_cons(((arity == 1) ? ((Object*)(solution->first())) : ((Object*)(copy_vector_to_cons_list(solution)))), NIL);
              if (listifiedsolutions->the_cons_list->emptyP()) {
                listifiedsolutions->the_cons_list = collect_001;
              }
              else {
                add_cons_to_end_of_cons_list(listifiedsolutions->the_cons_list, collect_001);
              }
            }
          }
          else {
            {
              collect_001->rest = permanent_cons(((arity == 1) ? ((Object*)(solution->first())) : ((Object*)(copy_vector_to_cons_list(solution)))), NIL);
              collect_001 = collect_001->rest;
            }
          }
        }
      }
      return (listifiedsolutions);
    }
  }
}

Cons* standardize_query_tree(Object* querytree, boolean truefalseP) {
  if (!consP(querytree)) {
    querytree = listO(3, SYM_QUERY_AND, querytree, NIL);
  }
  return (consDstandardize_query_tree(((Cons*)(querytree)), truefalseP));
}

Cons* consDstandardize_query_tree(Cons* querytree, boolean truefalseP) {
  { Cons* standardizedtree = NULL;

    { boolean old_OtransientobjectsPO_001 = oTRANSIENTOBJECTSpo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oTRANSIENTOBJECTSpo = TRUE;
            if (truefalseP) {
              standardizedtree = listO(4, SYM_QUERY_KAPPA, cons(SYM_QUERY_COMMA, NIL), listO(3, SYM_QUERY_WHERE, canonicalize_proposition_tree(standardize_logical_parse_tree(querytree)), NIL), NIL);
            }
            else {
              querytree = cons(SYM_QUERY_EXISTS, querytree->concatenate(NIL));
              if (oLOGIC_DIALECTo == KWD_QUERY_KIF) {
                if (querytree->length() < 3) {
                  querytree = querytree->concatenate(cons(SYM_QUERY_TRUE, NIL));
                }
              }
              else if (oLOGIC_DIALECTo == KWD_QUERY_STELLA) {
                if (!querytree->memberP(SYM_QUERY_WHERE)) {
                  querytree = querytree->concatenate(listO(3, SYM_QUERY_WHERE, SYM_QUERY_TRUE, NIL));
                }
              }
              else if (oLOGIC_DIALECTo == KWD_QUERY_PREFIX_STELLA) {
                if (lookup_where_clause(querytree) == NULL) {
                  querytree = querytree->concatenate(cons(listO(3, SYM_QUERY_WHERE, SYM_QUERY_TRUE, NIL), NIL));
                }
              }
              else {
              }
              standardizedtree = canonicalize_quantification_tree(((Cons*)(standardize_logical_parse_tree(querytree))));
              standardizedtree->first_setter(SYM_QUERY_KAPPA);
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
    return (standardizedtree);
  }
}

void handle_query_exception(Exception* exception, char* command) {
  { Exception* exception_001 = exception;

    if (taxonomy_isaP(exception, SGT_QUERY_LOGIC_EXCEPTION)) {
      { Logic_Exception* exception = NULL;

        exception = ((Logic_Exception*)(exception_001));
        if ((oTRACED_KEYWORDSo != NULL) &&
            oTRACED_KEYWORDSo->memberP(KWD_QUERY_EXCEPTIONS)) {
          cout << command << ": Caught " << exception->primary_type() << endl;
        }
      }
    }
    else if (taxonomy_isaP(exception, SGT_QUERY_EXCEPTION)) {
      { Exception* exception = NULL;

        exception = ((Exception*)(exception_001));
        cerr << "`" << command << "'" << ": Caught " << "`" << exception->primary_type() << "'" << endl;
      }
    }
    else {
      cerr << "`" << exception << "'" << " is not a valid case option";
    }
  }
}

Query_Iterator* make_query(Object* querytree, boolean yesnoP) {
  { Cons* prefixquerytree = standardize_query_tree(querytree, yesnoP);

    { Keyword* old_OevaluationmodeO_001 = oEVALUATIONMODEo;
      Cons* old_OlogicvariabletableO_001 = oLOGICVARIABLETABLEo;
      Object* old_OpropositionunderconstructionO_001 = oPROPOSITIONUNDERCONSTRUCTIONo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oEVALUATIONMODEo = KWD_QUERY_QUERY;
            oLOGICVARIABLETABLEo = NIL;
            oPROPOSITIONUNDERCONSTRUCTIONo = prefixquerytree;
            { Query_Iterator* queryiterator = create_query_iterator(evaluate_description_term(prefixquerytree, FALSE), NULL);

              free_cons_tree(prefixquerytree);
              free_cons_list(oLOGICVARIABLETABLEo);
              { 
                oPROPOSITIONUNDERCONSTRUCTIONo = old_OpropositionunderconstructionO_001;
                oLOGICVARIABLETABLEo = old_OlogicvariabletableO_001;
                oEVALUATIONMODEo = old_OevaluationmodeO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (queryiterator);
              }
            }
            oPROPOSITIONUNDERCONSTRUCTIONo = old_OpropositionunderconstructionO_001;
            oLOGICVARIABLETABLEo = old_OlogicvariabletableO_001;
            oEVALUATIONMODEo = old_OevaluationmodeO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oPROPOSITIONUNDERCONSTRUCTIONo = old_OpropositionunderconstructionO_001;
          oLOGICVARIABLETABLEo = old_OlogicvariabletableO_001;
          oEVALUATIONMODEo = old_OevaluationmodeO_001;
          resignal();
        }
      }
    }
  }
}

boolean run_yes_or_no_queryP(Query_Iterator* queryiterator) {
  { Query_Environment* queryenvironment = queryiterator->query_environment;

    { Query_Environment* old_OqueryenvironmentO_001 = oQUERYENVIRONMENTo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oQUERYENVIRONMENTo = queryenvironment;
            if (queryiterator->nextP()) {
              release_query_thread(queryenvironment);
              queryenvironment->query_thread_offset = NULL_INTEGER;
              { 
                oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
                oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                return (TRUE);
              }
            }
            oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
          resignal();
        }
      }
    }
    return (NULL_BOOLEAN);
  }
}

Object* coerce_to_tree(Object* self) {
  { Object* self_001 = self;

    if (stringP(self)) {
      { String_Wrapper* self = NULL;

        self = ((String_Wrapper*)(self_001));
        return (unstringify(self->wrapper_value));
      }
    }
    else {
      return (self);
    }
  }
}

char* coerce_to_string(Object* self) {
  { Object* self_001 = self;

    if (stringP(self)) {
      { String_Wrapper* self = NULL;

        self = ((String_Wrapper*)(self_001));
        return (self->wrapper_value);
      }
    }
    else if (symbolP(self)) {
      { Symbol* self = NULL;

        self = ((Symbol*)(self_001));
        return (self->symbol_name);
      }
    }
    else if (keywordP(self)) {
      { Keyword* self = NULL;

        self = ((Keyword*)(self_001));
        return (self->symbol_name);
      }
    }
    else if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        return (self->symbol_name);
      }
    }
    else {
      cout << "Can't convert " << self << " into a string." << endl;
      signal(oTHE_PARSING_ERRORo);
    }
  }
}

boolean ask(Object* proposition) {
  // Perform inference to determine whether `proposition' is true.
  // Return TRUE if `proposition' was found to be true; return NULL otherwise.
  // KIF example: `(ask (happy Fred))' will return TRUE if Fred was indeed
  // found to be happy.  Note, that for this query to run, the logic constant
  // `Fred' and the relation (or slot) `happy' must already be defined (see
  // `assert').  Use `(set/unset-feature goal-trace)' to en/disable goal tracing
  // of the inference engine.
  {
    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;
      boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      oPENDINGEXCEPTIONHANDLERpo = TRUE;
      if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        { Object* tree = coerce_to_tree(proposition);

          finalize_relations();
          if (tree != NULL) {
            { boolean return_value_001 = run_yes_or_no_queryP(make_query(tree, TRUE));

              oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (return_value_001);
            }
          }
          else {
            { 
              oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (NULL_BOOLEAN);
            }
          }
        }
        oEXCEPTIONo = NULL;
      }
      oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        { Exception* e = oEXCEPTIONo;

          handle_query_exception(e, "ask");
          return (NULL_BOOLEAN);
        }
      }
    }
  }
}

Boolean_Wrapper* ask_evaluator_wrapper(Cons* arguments) {
  { boolean result = ask(arguments->value);

    if (result != NULL_BOOLEAN) {
      return (wrap_boolean(result));
    }
    else {
      return (NULL);
    }
  }
}

Query_Iterator* Query_Iterator::retrieve_bindings(int nofbindings) {
  { Query_Iterator* query = this;

    finalize_relations();
    { Query_Environment* old_OqueryenvironmentO_001 = oQUERYENVIRONMENTo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oQUERYENVIRONMENTo = query->query_environment;
            { Vector* solution = NULL;
              int i = NULL_INTEGER;
              int iter_001 = 1;
              int upper_bound_001 = nofbindings;
              boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;
              Query_Iterator* iter_002 = query;

              while ((unboundedP_001 ||
                  (iter_001 <= upper_bound_001)) &&
                  iter_002->nextP()) {
                {
                  i = iter_001;
                  iter_001 = iter_001 + 1;
                }
                {
                  solution = ((Vector*)(iter_002->value));
                }
                {
                  solution = solution;
                  i = i;
                }
              }
            }
            { 
              oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (query);
            }
            oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
          }
          oEXCEPTIONo = NULL;
        }
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          oQUERYENVIRONMENTo = old_OqueryenvironmentO_001;
          resignal();
        }
      }
    }
  }
}

Query_Iterator* Cons::retrieve_bindings(int nofbindings) {
  { Cons* query = this;

    finalize_relations();
    if ((query->length() == 1) &&
        stringP(query->first())) {
      query = ((Cons*)(coerce_to_tree(query->first())));
    }
    return (make_query(query, FALSE)->retrieve_bindings(nofbindings));
  }
}

Query_Iterator* retrieve(Cons* query) {
  // Retrieve elements of a relation (tuples) that satisfy a proposition.
  // The accepted syntax is:
  // 	 
  //   (retrieve [<integer> | all]
  //             [{<variable-spec> | (<variable-spec>+)}
  //              [<proposition>]])
  // 	
  // The variables and proposition are similar to an `exists' sentence or
  // `kappa' term without the quantifier.  <proposition> usually contains
  // references to the listed variables.  No other free variable references
  // are allowed.  If <proposition> is omitted, it defaults to TRUE.  
  // 
  // A solution is a set of bindings for the listed variables for which
  // <proposition> is true.  The optional first argument controls how many
  // solutions should be generated before control is returned.  The keyword
  // `all' indicates that all solutions should be generated.  By default,
  // `retrieve' returns after it has found one new solution or if it cannot
  // find any more solutions.
  // 
  // `retrieve' returns an iterator which saves all the necessary state of
  // a query and stores all generated solutions.  When used interactively,
  // the returned iterator will print out with the set of solutions collected
  // so far.  Calling `retrieve' without any arguments (or only with the first
  // argument) will generate one (or more) solutions to the most recently
  // asked query.
  // 
  // KIF examples:
  // 	 
  //   (retrieve (?x Person) (happy ?x)) 
  // 	
  // will try to find the next happy person and store it in the returned 
  // query iterator.
  // 	 
  //   (retrieve 10 (?x Person) (happy ?x))
  // 	
  // will try to find 10 happy people.
  // 	 
  //   (retrieve 10)
  // 	
  // will try to find the next 10 happy people.
  // 	 
  //   (retrieve all (?x Person) (happy ?x))
  // 	
  // will find all happy people.
  // 	 
  //   (retrieve all (?x Person))
  // 	
  // will find all people.
  // 	 
  //   (retrieve (?x Person) (or (happy ?x) (parent-of Fred ?x)))
  // 	
  // will try to find the next person that is happy or has Fred as a parent.
  // 	 
  //   (retrieve ((?x Person) (?y Person)) (parent-of ?x ?y))
  // 	
  // will try to find the next pair of parent/child.
  // 	 
  //   (retrieve all (?x Person)
  //             (exists (?y Person) (parent-of ?x ?y)))
  // 	
  // will generate the set of all parents.  Note, that for these queries to run,
  // the class `Person', the relations `happy' and `parent-of', and the logic
  // constant `Fred' must already be defined (see `assert').
  // 
  // Use `(set/unset-feature goal-trace)' to en/disable goal tracing of the
  // inference engine.
  { Object* firstarg = query->first();
    int nofbindings = 1;

    if (firstarg != NULL) {
      { Object* firstarg_001 = firstarg;

        if (integerP(firstarg)) {
          { Integer_Wrapper* firstarg = NULL;

            firstarg = ((Integer_Wrapper*)(firstarg_001));
            nofbindings = firstarg->wrapper_value;
            query = query->rest;
          }
        }
        else if (symbolP(firstarg)) {
          { Symbol* firstarg = NULL;

            firstarg = ((Symbol*)(firstarg_001));
            if (string_eqlP(firstarg->symbol_name, "ALL")) {
              nofbindings = NULL_INTEGER;
              query = query->rest;
            }
          }
        }
        else if (keywordP(firstarg)) {
          { Keyword* firstarg = NULL;

            firstarg = ((Keyword*)(firstarg_001));
            if (string_eqlP(firstarg->symbol_name, "ALL")) {
              nofbindings = NULL_INTEGER;
              query = query->rest;
            }
          }
        }
        else {
        }
      }
    }
    {
      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;
        boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        oPENDINGEXCEPTIONHANDLERpo = TRUE;
        if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          if (query->emptyP() &&
              (oMOST_RECENT_QUERYo != NULL)) {
            { Query_Iterator* return_value_001 = oMOST_RECENT_QUERYo->retrieve_bindings(nofbindings);

              oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (return_value_001);
            }
          }
          else {
            { Query_Iterator* return_value_002 = oMOST_RECENT_QUERYo = query->retrieve_bindings(nofbindings);

              oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (return_value_002);
            }
          }
          oEXCEPTIONo = NULL;
        }
        oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
        oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
      }
      if (oEXCEPTIONo != NULL) {
        if (TRUE) {
          { Exception* e = oEXCEPTIONo;

            handle_query_exception(e, "retrieve");
            return (NULL);
          }
        }
      }
    }
  }
}

Query_Iterator* retrieve_evaluator_wrapper(Cons* arguments) {
  return (retrieve(((Cons*)(arguments))));
}

Description* get_subsumption_definition(Description* self, Keyword* suborsuper) {
  suborsuper = suborsuper;
  return ((((self->native_relation != NULL) &&
      (((Description*)(dynamic_slot_value(self->native_relation, SYM_QUERY_DEFINITION, NULL))) != NULL)) ? ((Description*)(((Description*)(dynamic_slot_value(self->native_relation, SYM_QUERY_DEFINITION, NULL))))) : ((Description*)(self))));
}

boolean description_specializes_descriptionP(Description* sub, Description* super) {
  if (collection_implies_collectionP(sub, super)) {
    return (TRUE);
  }
  if ((oTRACED_KEYWORDSo != NULL) &&
      oTRACED_KEYWORDSo->memberP(KWD_QUERY_GOAL_TREE)) {
    cout << "Subsumption Test:" << endl;
  }
  {
    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;
      boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      oPENDINGEXCEPTIONHANDLERpo = TRUE;
      if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        { Description* subdescription = get_subsumption_definition(sub, KWD_QUERY_SUB);
          Description* superdescription = get_subsumption_definition(super, KWD_QUERY_SUPER);
          Query_Iterator* queryiterator = create_query_iterator(superdescription, subdescription->io_variables);
          Query_Environment* queryenvironment = queryiterator->query_environment;
          boolean pushedworldP = FALSE;
          boolean resultP = FALSE;

          queryenvironment->subsumption_queryP = TRUE;
          queryenvironment->specializing_description = subdescription;
          if (unknownP(subdescription->proposition)) {
            push_world();
            set_dynamic_slot_value(((World*)(oCONTEXTo)), SYM_QUERY_MONOTONICp, wrap_boolean(TRUE), NULL_BOOLEAN_WRAPPER);
            pushedworldP = TRUE;
            assign_truth_value(subdescription->proposition, TRUE);
          }
          resultP = run_yes_or_no_queryP(queryiterator) != NULL_BOOLEAN;
          if (pushedworldP) {
            pop_world();
          }
          { 
            oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
            return (resultP);
          }
        }
        oEXCEPTIONo = NULL;
      }
      oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        { Exception* e = oEXCEPTIONo;

          handle_query_exception(e, "specializes?");
          return (FALSE);
        }
      }
    }
  }
}

boolean vector_satisfies_descriptionP(Vector* vector, Description* description) {
  {
    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;
      boolean old_OpendingexceptionhandlerPO_001 = oPENDINGEXCEPTIONHANDLERpo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      oPENDINGEXCEPTIONHANDLERpo = TRUE;
      if (setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        { boolean test_value_001 = FALSE;

          test_value_001 = vector->length() == description->arity();
          if (test_value_001) {
            { boolean alwaysP_001 = TRUE;

              { Object* value = NULL;
                Vector* vector_001 = vector;
                int index_001 = 0;
                int length_001 = vector_001->length();

                while (index_001 < length_001) {
                  {
                    value = vector_001->nth(index_001);
                    index_001 = index_001 + 1;
                  }
                  if (!(value != NULL)) {
                    alwaysP_001 = FALSE;
                    break;
                  }
                }
              }
              test_value_001 = alwaysP_001;
            }
            if (test_value_001) {
              test_value_001 = run_yes_or_no_queryP(create_query_iterator(description, vector)) != NULL_BOOLEAN;
            }
          }
          { boolean return_value_001 = test_value_001;

            oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
            oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
            return (return_value_001);
          }
        }
        oEXCEPTIONo = NULL;
      }
      oPENDINGEXCEPTIONHANDLERpo = old_OpendingexceptionhandlerPO_001;
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        { Exception* e = oEXCEPTIONo;

          handle_query_exception(e, "satisfies?");
          return (FALSE);
        }
      }
    }
  }
}

boolean instance_satisfies_descriptionP(Object* instance, Description* description) {
  REUSABLE_SINGLETON_VECTOR->nth_setter(instance, 0);
  return (vector_satisfies_descriptionP(REUSABLE_SINGLETON_VECTOR, description));
}

Description* coerce_to_description(Object* self, Object* original) {
  if (original == NULL) {
    original = self;
  }
  if (self == NULL) {
    cout << "Can't find a description for the object " << "`" << original << "'" << "." << endl;
    return (NULL);
  }
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_QUERY_DESCRIPTION)) {
      { Description* self = NULL;

        self = ((Description*)(self_001));
        return (self);
      }
    }
    else if (taxonomy_isaP(self, SGT_QUERY_RELATION)) {
      { Relation* self = NULL;

        self = ((Relation*)(self_001));
        return (self->get_description());
      }
    }
    else if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        return (coerce_to_description(self->surrogate_value, original));
      }
    }
    else if (symbolP(self)) {
      { Symbol* self = NULL;

        self = ((Symbol*)(self_001));
        return (coerce_to_description(lookup_surrogate_in_module(self->symbol_name, ((Module*)(self->home_context)), FALSE), original));
      }
    }
    else if (keywordP(self)) {
      { Keyword* self = NULL;

        self = ((Keyword*)(self_001));
        return (coerce_to_description(lookup_surrogate(self->symbol_name), original));
      }
    }
    else if (stringP(self)) {
      { String_Wrapper* self = NULL;

        self = ((String_Wrapper*)(self_001));
        return (coerce_to_description(lookup_surrogate(self->wrapper_value), original));
      }
    }
    else {
      return (coerce_to_description(NULL, original));
    }
  }
}

boolean specializesP(Object* subobject, Object* superobject) {
  // Return TRUE if the description associated with `subObject'
  // specializes the description for `superObject'.  Return FALSE if we could
  // not prove that `subObject' specializes `superObject'.
  { Description* subdescription = coerce_to_description(subobject, NULL);
    Description* superdescription = coerce_to_description(superobject, NULL);

    finalize_relations();
    { Context* old_OcontextO_001 = oCONTEXTo;

      { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

        oEXCEPTIONHANDLERADDRESSo = NULL;
        if ((!oPENDINGEXCEPTIONHANDLERpo) ||
            setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
          {
            oCONTEXTo = oCONTEXTo->get_constraint_propagation_world();
            if (!(((World*)(oCONTEXTo))->base_module == oMODULEo)) {
              cerr << "Safety violation: " << "within-world: world " << "`" << oCONTEXTo << "'" << " does not have a base module";
            }
            { boolean return_value_001 = (subdescription != NULL) &&
                  ((superdescription != NULL) &&
                   description_specializes_descriptionP(subdescription, superdescription));

              oCONTEXTo = old_OcontextO_001;
              oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
              return (return_value_001);
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

Logic_Object* coerce_to_instance(Object* self, Object* original) {
  if (original == NULL) {
    original = self;
  }
  if (self == NULL) {
    cout << "Can't find a logic object " << "`" << original << "'" << "." << endl;
    return (NULL);
  }
  { Object* self_001 = self;

    if (taxonomy_isaP(self, SGT_QUERY_LOGIC_OBJECT)) {
      { Logic_Object* self = NULL;

        self = ((Logic_Object*)(self_001));
        return (self);
      }
    }
    else if (taxonomy_isaP(self, SGT_QUERY_RELATION)) {
      { Relation* self = NULL;

        self = ((Relation*)(self_001));
        return (self->get_description());
      }
    }
    else if (surrogateP(self)) {
      { Surrogate* self = NULL;

        self = ((Surrogate*)(self_001));
        return (coerce_to_instance(self->surrogate_value, original));
      }
    }
    else if (symbolP(self)) {
      { Symbol* self = NULL;

        self = ((Symbol*)(self_001));
        return (coerce_to_instance(lookup_surrogate_in_module(self->symbol_name, ((Module*)(self->home_context)), FALSE), original));
      }
    }
    else if (keywordP(self)) {
      { Keyword* self = NULL;

        self = ((Keyword*)(self_001));
        return (coerce_to_instance(lookup_surrogate(self->symbol_name), original));
      }
    }
    else if (stringP(self)) {
      { String_Wrapper* self = NULL;

        self = ((String_Wrapper*)(self_001));
        return (coerce_to_instance(lookup_surrogate(self->wrapper_value), original));
      }
    }
    else {
      return (coerce_to_instance(NULL, original));
    }
  }
}

Vector* coerce_to_vector(Object* self) {
  { Vector* vector = NULL;

    { Object* self_001 = self;

      if (taxonomy_isaP(self, SGT_QUERY_VECTOR)) {
        { Vector* self = NULL;

          self = ((Vector*)(self_001));
          vector = self;
          { int i = NULL_INTEGER;
            Object* m = NULL;
            Vector* vector_001 = self;
            int index_001 = 0;
            int length_001 = vector_001->length();
            int iter_001 = 0;

            while (index_001 < length_001) {
              {
                m = vector_001->nth(index_001);
                index_001 = index_001 + 1;
              }
              {
                i = iter_001;
                iter_001 = iter_001 + 1;
              }
              vector->nth_setter(coerce_to_instance(m, NULL), i);
            }
          }
        }
      }
      else if (taxonomy_isaP(self, SGT_QUERY_LIST)) {
        { List* self = NULL;

          self = ((List*)(self_001));
          vector = new_vector(self->length());
          { int i = NULL_INTEGER;
            Object* m = NULL;
            Cons* iter_002 = self->the_cons_list;
            int iter_003 = 0;

            while (!nilP(iter_002)) {
              {
                m = iter_002->value;
                iter_002 = iter_002->rest;
              }
              {
                i = iter_003;
                iter_003 = iter_003 + 1;
              }
              vector->nth_setter(coerce_to_instance(m, NULL), i);
            }
          }
        }
      }
      else if (consP(self)) {
        { Cons* self = NULL;

          self = ((Cons*)(self_001));
          vector = new_vector(self->length());
          { int i = NULL_INTEGER;
            Object* m = NULL;
            Cons* iter_004 = self;
            int iter_005 = 0;

            while (!nilP(iter_004)) {
              {
                m = iter_004->value;
                iter_004 = iter_004->rest;
              }
              {
                i = iter_005;
                iter_005 = iter_005 + 1;
              }
              vector->nth_setter(coerce_to_instance(m, NULL), i);
            }
          }
        }
      }
      else {
        cout << "Don't know how to coerce " << "`" << self << "'" << " of type " << "`" << self->primary_type() << "'" << endl << "   into a vector." << endl;
      }
    }
    return (vector);
  }
}

boolean satisfiesP(Object* instanceortuple, Object* relationref) {
  // Return TRUE if `instanceOrTuple' satisfies the
  // definition of the relation `relationRef'.  `instanceOrTuple' can be a single
  // object, the name or surrogate of an object, or a collection (a list or vector)
  // of objects. `relationRef' can be a relation, description, surrogate or relation
  // name.  Return FALSE if we could not prove that `instanceOrTuple' satisfies
  // `relationRef'.
  { Description* description = coerce_to_description(relationref, NULL);

    if (description != NULL) {
      finalize_relations();
      { Context* old_OcontextO_001 = oCONTEXTo;

        { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

          oEXCEPTIONHANDLERADDRESSo = NULL;
          if ((!oPENDINGEXCEPTIONHANDLERpo) ||
              setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
            {
              oCONTEXTo = oCONTEXTo->get_constraint_propagation_world();
              if (!(((World*)(oCONTEXTo))->base_module == oMODULEo)) {
                cerr << "Safety violation: " << "within-world: world " << "`" << oCONTEXTo << "'" << " does not have a base module";
              }
              if (isaP(instanceortuple, SGT_QUERY_COLLECTION) ||
                  consP(instanceortuple)) {
                { Vector* vector = coerce_to_vector(instanceortuple);

                  { boolean return_value_001 = (vector != NULL) &&
                        vector_satisfies_descriptionP(vector, description);

                    oCONTEXTo = old_OcontextO_001;
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                    return (return_value_001);
                  }
                }
              }
              else {
                { Logic_Object* instance = coerce_to_instance(instanceortuple, NULL);

                  { boolean return_value_002 = (instance != NULL) &&
                        instance_satisfies_descriptionP(instance, description);

                    oCONTEXTo = old_OcontextO_001;
                    oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
                    return (return_value_002);
                  }
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
    return (FALSE);
  }
}

void startup_query() {
  if (current_startup_time_phaseP(0)) {
    oRECYCLED_QUERY_ENVIRONMENT_So = make_non_recycled_list();
  }
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
            SYM_QUERY_QUERY_ENVIRONMENT = ((Symbol*)(intern_rigid_symbol_wrt_module("QUERY-ENVIRONMENT", NULL, 0)));
            SYM_QUERY_EXTERNAL_VARIABLES = ((Symbol*)(intern_rigid_symbol_wrt_module("EXTERNAL-VARIABLES", NULL, 0)));
            SYM_QUERY_SOLUTIONS = ((Symbol*)(intern_rigid_symbol_wrt_module("SOLUTIONS", NULL, 0)));
            SYM_QUERY_EXHAUSTEDp = ((Symbol*)(intern_rigid_symbol_wrt_module("EXHAUSTED?", NULL, 0)));
            SGT_QUERY_QUERY_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("QUERY-ITERATOR", NULL, 1)));
            SYM_QUERY_STATE = ((Symbol*)(intern_rigid_symbol_wrt_module("STATE", string_get_module("/STELLA", TRUE), 0)));
            SYM_QUERY_PHASE = ((Symbol*)(intern_rigid_symbol_wrt_module("PHASE", string_get_module("/STELLA", TRUE), 0)));
            SYM_QUERY_PROPOSITION = ((Symbol*)(intern_rigid_symbol_wrt_module("PROPOSITION", NULL, 0)));
            SYM_QUERY_REVERSE_POLARITYp = ((Symbol*)(intern_rigid_symbol_wrt_module("REVERSE-POLARITY?", NULL, 0)));
            SYM_QUERY_UP = ((Symbol*)(intern_rigid_symbol_wrt_module("UP", NULL, 0)));
            SYM_QUERY_DOWN = ((Symbol*)(intern_rigid_symbol_wrt_module("DOWN", NULL, 0)));
            SYM_QUERY_BACK = ((Symbol*)(intern_rigid_symbol_wrt_module("BACK", NULL, 0)));
            SYM_QUERY_ARGUMENT_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("ARGUMENT-CURSOR", NULL, 0)));
            SYM_QUERY_ITERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATOR", string_get_module("/STELLA", TRUE), 0)));
            SYM_QUERY_SUBQUERY_FRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SUBQUERY-FRAME", NULL, 0)));
            SYM_QUERY_PARENT_PATTERN_FRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("PARENT-PATTERN-FRAME", NULL, 0)));
            SYM_QUERY_GOAL_CACHE = ((Symbol*)(intern_rigid_symbol_wrt_module("GOAL-CACHE", NULL, 0)));
            SYM_QUERY_PARTIAL_MATCH_FRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("PARTIAL-MATCH-FRAME", NULL, 0)));
            SYM_QUERY_DEBUG_FRAME_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("DEBUG-FRAME-OFFSET", NULL, 0)));
            SYM_QUERY_DEBUG_DEPTH = ((Symbol*)(intern_rigid_symbol_wrt_module("DEBUG-DEPTH", NULL, 0)));
            SYM_QUERY_CHOICE_POINT_UNBINDING_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("CHOICE-POINT-UNBINDING-OFFSET", NULL, 0)));
            SGT_QUERY_CONTROL_FRAME = ((Surrogate*)(intern_rigid_symbol_wrt_module("CONTROL-FRAME", NULL, 1)));
            SYM_QUERY_KIND_OF_GOAL = ((Symbol*)(intern_rigid_symbol_wrt_module("KIND-OF-GOAL", NULL, 0)));
            SYM_QUERY_STRATEGY_PRIORITY = ((Symbol*)(intern_rigid_symbol_wrt_module("STRATEGY-PRIORITY", NULL, 0)));
            SYM_QUERY_STRATEGY_PROCEDURE = ((Symbol*)(intern_rigid_symbol_wrt_module("STRATEGY-PROCEDURE", NULL, 0)));
            SGT_QUERY_GOAL_STRATEGY = ((Surrogate*)(intern_rigid_symbol_wrt_module("GOAL-STRATEGY", NULL, 1)));
            SYM_QUERY_CONTROL_FRAME_STACK = ((Symbol*)(intern_rigid_symbol_wrt_module("CONTROL-FRAME-STACK", NULL, 0)));
            SYM_QUERY_CONTROL_FRAME_OFFSET_LIMIT = ((Symbol*)(intern_rigid_symbol_wrt_module("CONTROL-FRAME-OFFSET-LIMIT", NULL, 0)));
            SYM_QUERY_TOP_CONTROL_FRAME_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("TOP-CONTROL-FRAME-OFFSET", NULL, 0)));
            SYM_QUERY_VARIABLE_FRAME_STACK = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-FRAME-STACK", NULL, 0)));
            SYM_QUERY_VARIABLE_FRAME_OFFSET_LIMIT = ((Symbol*)(intern_rigid_symbol_wrt_module("VARIABLE-FRAME-OFFSET-LIMIT", NULL, 0)));
            SYM_QUERY_TOP_VARIABLE_FRAME_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("TOP-VARIABLE-FRAME-OFFSET", NULL, 0)));
            SYM_QUERY_UNBINDING_STACK = ((Symbol*)(intern_rigid_symbol_wrt_module("UNBINDING-STACK", NULL, 0)));
            SYM_QUERY_UNBINDING_STACK_OFFSET_LIMIT = ((Symbol*)(intern_rigid_symbol_wrt_module("UNBINDING-STACK-OFFSET-LIMIT", NULL, 0)));
            SYM_QUERY_TOP_UNBINDING_STACK_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("TOP-UNBINDING-STACK-OFFSET", NULL, 0)));
            SYM_QUERY_CURRENT_VARIABLE_FRAME_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("CURRENT-VARIABLE-FRAME-OFFSET", NULL, 0)));
            SYM_QUERY_CURRENT_SUBQUERY_FRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("CURRENT-SUBQUERY-FRAME", NULL, 0)));
            SYM_QUERY_PARTIAL_MATCH_STRATEGY = ((Symbol*)(intern_rigid_symbol_wrt_module("PARTIAL-MATCH-STRATEGY", NULL, 0)));
            SYM_QUERY_LATEST_POSITIVE_SCORE = ((Symbol*)(intern_rigid_symbol_wrt_module("LATEST-POSITIVE-SCORE", NULL, 0)));
            SYM_QUERY_ITERATIVE_DEEPENINGp = ((Symbol*)(intern_rigid_symbol_wrt_module("ITERATIVE-DEEPENING?", NULL, 0)));
            SYM_QUERY_CURRENT_DEPTH_CUTOFF = ((Symbol*)(intern_rigid_symbol_wrt_module("CURRENT-DEPTH-CUTOFF", NULL, 0)));
            SYM_QUERY_MAXIMUM_DEPTH = ((Symbol*)(intern_rigid_symbol_wrt_module("MAXIMUM-DEPTH", NULL, 0)));
            SYM_QUERY_AUGMENTED_GOAL_CACHEp = ((Symbol*)(intern_rigid_symbol_wrt_module("AUGMENTED-GOAL-CACHE?", NULL, 0)));
            SYM_QUERY_ACTIVE_GOAL_CACHES = ((Symbol*)(intern_rigid_symbol_wrt_module("ACTIVE-GOAL-CACHES", NULL, 0)));
            SYM_QUERY_TRIGGERED_DEPTH_CUTOFFp = ((Symbol*)(intern_rigid_symbol_wrt_module("TRIGGERED-DEPTH-CUTOFF?", NULL, 0)));
            SYM_QUERY_FAILED_TO_FIND_DUPLICATE_SUBGOALp = ((Symbol*)(intern_rigid_symbol_wrt_module("FAILED-TO-FIND-DUPLICATE-SUBGOAL?", NULL, 0)));
            SYM_QUERY_FOUND_AT_LEAST_ONE_SOLUTIONp = ((Symbol*)(intern_rigid_symbol_wrt_module("FOUND-AT-LEAST-ONE-SOLUTION?", NULL, 0)));
            SYM_QUERY_DEEP_INFERENCEp = ((Symbol*)(intern_rigid_symbol_wrt_module("DEEP-INFERENCE?", NULL, 0)));
            SYM_QUERY_QUERY_THREAD_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("QUERY-THREAD-OFFSET", NULL, 0)));
            SYM_QUERY_TIME_STAMP = ((Symbol*)(intern_rigid_symbol_wrt_module("TIME-STAMP", NULL, 0)));
            SYM_QUERY_QUERY_ITERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("QUERY-ITERATOR", NULL, 0)));
            SYM_QUERY_SUBSUMPTION_QUERYp = ((Symbol*)(intern_rigid_symbol_wrt_module("SUBSUMPTION-QUERY?", NULL, 0)));
            SYM_QUERY_SPECIALIZING_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("SPECIALIZING-DESCRIPTION", NULL, 0)));
            SYM_QUERY_OPTIMIZER_GOAL_RECORDS = ((Symbol*)(intern_rigid_symbol_wrt_module("OPTIMIZER-GOAL-RECORDS", NULL, 0)));
            SYM_QUERY_RESIDUE_GOALS = ((Symbol*)(intern_rigid_symbol_wrt_module("RESIDUE-GOALS", NULL, 0)));
            SYM_QUERY_BEST_GOAL_SEQUENCE = ((Symbol*)(intern_rigid_symbol_wrt_module("BEST-GOAL-SEQUENCE", NULL, 0)));
            SYM_QUERY_BEST_COST = ((Symbol*)(intern_rigid_symbol_wrt_module("BEST-COST", NULL, 0)));
            SGT_QUERY_QUERY_ENVIRONMENT = ((Surrogate*)(intern_rigid_symbol_wrt_module("QUERY-ENVIRONMENT", NULL, 1)));
            SYM_QUERY_oQUERYENVIRONMENTo = ((Symbol*)(intern_rigid_symbol_wrt_module("*QUERYENVIRONMENT*", NULL, 0)));
            SYM_QUERY_CONTROL_FRAME = ((Symbol*)(intern_rigid_symbol_wrt_module("CONTROL-FRAME", NULL, 0)));
            SYM_QUERY_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 0)));
            SYM_QUERY_EXTERNAL_ARGUMENTS = ((Symbol*)(intern_rigid_symbol_wrt_module("EXTERNAL-ARGUMENTS", NULL, 0)));
            SYM_QUERY_BOOLEAN_VECTOR = ((Symbol*)(intern_rigid_symbol_wrt_module("BOOLEAN-VECTOR", string_get_module("/STELLA", TRUE), 0)));
            SYM_QUERY_LOCAL_VARIABLE_FRAME_OFFSET = ((Symbol*)(intern_rigid_symbol_wrt_module("LOCAL-VARIABLE-FRAME-OFFSET", NULL, 0)));
            SYM_QUERY_OPTIMAL_PATTERN = ((Symbol*)(intern_rigid_symbol_wrt_module("OPTIMAL-PATTERN", NULL, 0)));
            SYM_QUERY_PHASES_FILTER = ((Symbol*)(intern_rigid_symbol_wrt_module("PHASES-FILTER", NULL, 0)));
            SGT_QUERY_SUBQUERY_FRAME = ((Surrogate*)(intern_rigid_symbol_wrt_module("SUBQUERY-FRAME", NULL, 1)));
            SYM_QUERY_TRUE_LINK = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE-LINK", NULL, 0)));
            SYM_QUERY_FALSE_LINK = ((Symbol*)(intern_rigid_symbol_wrt_module("FALSE-LINK", NULL, 0)));
            SYM_QUERY_VECTOR = ((Symbol*)(intern_rigid_symbol_wrt_module("VECTOR", string_get_module("/STELLA", TRUE), 0)));
            SGT_QUERY_BOOLEAN_VECTOR_INDEX_NODE = ((Surrogate*)(intern_rigid_symbol_wrt_module("BOOLEAN-VECTOR-INDEX-NODE", NULL, 1)));
            SGT_QUERY_PATTERN_VARIABLE = ((Surrogate*)(intern_rigid_symbol_wrt_module("PATTERN-VARIABLE", NULL, 1)));
            KWD_QUERY_QUERY_STACKS = ((Keyword*)(intern_rigid_symbol_wrt_module("QUERY-STACKS", NULL, 2)));
            KWD_QUERY_PATTERN = ((Keyword*)(intern_rigid_symbol_wrt_module("PATTERN", NULL, 2)));
            KWD_QUERY_CONTAINED_BY = ((Keyword*)(intern_rigid_symbol_wrt_module("CONTAINED-BY", NULL, 2)));
            KWD_QUERY_POPPED = ((Keyword*)(intern_rigid_symbol_wrt_module("POPPED", NULL, 2)));
            KWD_QUERY_LOCAL = ((Keyword*)(intern_rigid_symbol_wrt_module("LOCAL", NULL, 2)));
            KWD_QUERY_PARENT = ((Keyword*)(intern_rigid_symbol_wrt_module("PARENT", NULL, 2)));
            SGT_QUERY_LOGIC_OBJECT = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-OBJECT", NULL, 1)));
            KWD_QUERY_SORT = ((Keyword*)(intern_rigid_symbol_wrt_module("SORT", NULL, 2)));
            KWD_QUERY_NONE = ((Keyword*)(intern_rigid_symbol_wrt_module("NONE", NULL, 2)));
            KWD_QUERY_IN = ((Keyword*)(intern_rigid_symbol_wrt_module("IN", NULL, 2)));
            SGT_QUERY_SURROGATE = ((Surrogate*)(intern_rigid_symbol_wrt_module("SURROGATE", string_get_module("/STELLA", TRUE), 1)));
            KWD_QUERY_SHALLOW_DISJOINT = ((Keyword*)(intern_rigid_symbol_wrt_module("SHALLOW-DISJOINT", NULL, 2)));
            KWD_QUERY_DISJOINT = ((Keyword*)(intern_rigid_symbol_wrt_module("DISJOINT", NULL, 2)));
            SYM_QUERY_SKOLEM_NAME = ((Symbol*)(intern_rigid_symbol_wrt_module("SKOLEM-NAME", NULL, 0)));
            SGT_QUERY_LIST = ((Surrogate*)(intern_rigid_symbol_wrt_module("LIST", string_get_module("/STELLA", TRUE), 1)));
            KWD_QUERY_DOWN = ((Keyword*)(intern_rigid_symbol_wrt_module("DOWN", NULL, 2)));
            KWD_QUERY_ITERATIVE_FORALL = ((Keyword*)(intern_rigid_symbol_wrt_module("ITERATIVE-FORALL", NULL, 2)));
            KWD_QUERY_STATE_MACHINE = ((Keyword*)(intern_rigid_symbol_wrt_module("STATE-MACHINE", NULL, 2)));
            KWD_QUERY_SUBGOALS = ((Keyword*)(intern_rigid_symbol_wrt_module("SUBGOALS", NULL, 2)));
            KWD_QUERY_TERMINATION = ((Keyword*)(intern_rigid_symbol_wrt_module("TERMINATION", NULL, 2)));
            KWD_QUERY_ANTECEDENTS = ((Keyword*)(intern_rigid_symbol_wrt_module("ANTECEDENTS", NULL, 2)));
            KWD_QUERY_REALISTIC = ((Keyword*)(intern_rigid_symbol_wrt_module("REALISTIC", NULL, 2)));
            KWD_QUERY_COMPLEMENT = ((Keyword*)(intern_rigid_symbol_wrt_module("COMPLEMENT", NULL, 2)));
            KWD_QUERY_UP_TRUE = ((Keyword*)(intern_rigid_symbol_wrt_module("UP-TRUE", NULL, 2)));
            KWD_QUERY_UP_FAIL = ((Keyword*)(intern_rigid_symbol_wrt_module("UP-FAIL", NULL, 2)));
            KWD_QUERY_AND = ((Keyword*)(intern_rigid_symbol_wrt_module("AND", NULL, 2)));
            KWD_QUERY_OR = ((Keyword*)(intern_rigid_symbol_wrt_module("OR", NULL, 2)));
            KWD_QUERY_NOT = ((Keyword*)(intern_rigid_symbol_wrt_module("NOT", NULL, 2)));
            KWD_QUERY_INITIAL = ((Keyword*)(intern_rigid_symbol_wrt_module("INITIAL", NULL, 2)));
            KWD_QUERY_GOAL_TREE = ((Keyword*)(intern_rigid_symbol_wrt_module("GOAL-TREE", NULL, 2)));
            KWD_QUERY_SELECT_STRATEGY = ((Keyword*)(intern_rigid_symbol_wrt_module("SELECT-STRATEGY", NULL, 2)));
            KWD_QUERY_HEAVY_DUTY_DISJUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("HEAVY-DUTY-DISJUNCTION", NULL, 2)));
            KWD_QUERY_FUNCTION = ((Keyword*)(intern_rigid_symbol_wrt_module("FUNCTION", NULL, 2)));
            KWD_QUERY_PREDICATE = ((Keyword*)(intern_rigid_symbol_wrt_module("PREDICATE", NULL, 2)));
            KWD_QUERY_EQUIVALENT = ((Keyword*)(intern_rigid_symbol_wrt_module("EQUIVALENT", NULL, 2)));
            KWD_QUERY_IMPLIES = ((Keyword*)(intern_rigid_symbol_wrt_module("IMPLIES", NULL, 2)));
            KWD_QUERY_CONSTANT = ((Keyword*)(intern_rigid_symbol_wrt_module("CONSTANT", NULL, 2)));
            KWD_QUERY_CONTINUING_SUCCESS = ((Keyword*)(intern_rigid_symbol_wrt_module("CONTINUING-SUCCESS", NULL, 2)));
            KWD_QUERY_FINAL_SUCCESS = ((Keyword*)(intern_rigid_symbol_wrt_module("FINAL-SUCCESS", NULL, 2)));
            KWD_QUERY_FAILURE = ((Keyword*)(intern_rigid_symbol_wrt_module("FAILURE", NULL, 2)));
            KWD_QUERY_OVERLAY = ((Keyword*)(intern_rigid_symbol_wrt_module("OVERLAY", NULL, 2)));
            KWD_QUERY_SPAWNED_SUBQUERY = ((Keyword*)(intern_rigid_symbol_wrt_module("SPAWNED-SUBQUERY", NULL, 2)));
            KWD_QUERY_SUCCESS = ((Keyword*)(intern_rigid_symbol_wrt_module("SUCCESS", NULL, 2)));
            KWD_QUERY_FAILED_OVERLAY = ((Keyword*)(intern_rigid_symbol_wrt_module("FAILED-OVERLAY", NULL, 2)));
            KWD_QUERY_SUBGOAL = ((Keyword*)(intern_rigid_symbol_wrt_module("SUBGOAL", NULL, 2)));
            KWD_QUERY_EXISTS = ((Keyword*)(intern_rigid_symbol_wrt_module("EXISTS", NULL, 2)));
            KWD_QUERY_FORALL = ((Keyword*)(intern_rigid_symbol_wrt_module("FORALL", NULL, 2)));
            SYM_QUERY_IO_VARIABLES = ((Symbol*)(intern_rigid_symbol_wrt_module("IO-VARIABLES", NULL, 0)));
            KWD_QUERY_CACHED_BINDINGS = ((Keyword*)(intern_rigid_symbol_wrt_module("CACHED-BINDINGS", NULL, 2)));
            KWD_QUERY_FAIL = ((Keyword*)(intern_rigid_symbol_wrt_module("FAIL", NULL, 2)));
            KWD_QUERY_END_SUBUMPTION_TEST = ((Keyword*)(intern_rigid_symbol_wrt_module("END-SUBUMPTION-TEST", NULL, 2)));
            SYM_QUERY_oREVERSEPOLARITYpo = ((Symbol*)(intern_rigid_symbol_wrt_module("*REVERSEPOLARITY?*", NULL, 0)));
            SGT_QUERY_PROPOSITION = ((Surrogate*)(intern_rigid_symbol_wrt_module("PROPOSITION", NULL, 1)));
            KWD_QUERY_ALL_SUBGOAL_PHASES = ((Keyword*)(intern_rigid_symbol_wrt_module("ALL-SUBGOAL-PHASES", NULL, 2)));
            KWD_QUERY_SUBGOALS_OVERLAY = ((Keyword*)(intern_rigid_symbol_wrt_module("SUBGOALS-OVERLAY", NULL, 2)));
            KWD_QUERY_OPEN = ((Keyword*)(intern_rigid_symbol_wrt_module("OPEN", NULL, 2)));
            KWD_QUERY_SCAN_COLLECTION = ((Keyword*)(intern_rigid_symbol_wrt_module("SCAN-COLLECTION", NULL, 2)));
            SGT_QUERY_DESCRIPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("DESCRIPTION", NULL, 1)));
            SYM_QUERY_COMPLEMENT_DESCRIPTION = ((Symbol*)(intern_rigid_symbol_wrt_module("COMPLEMENT-DESCRIPTION", NULL, 0)));
            KWD_QUERY_SCAN_SUBCOLLECTIONS = ((Keyword*)(intern_rigid_symbol_wrt_module("SCAN-SUBCOLLECTIONS", NULL, 2)));
            KWD_QUERY_SCAN_SUPERCOLLECTIONS = ((Keyword*)(intern_rigid_symbol_wrt_module("SCAN-SUPERCOLLECTIONS", NULL, 2)));
            KWD_QUERY_DO_CONTAINED_BY = ((Keyword*)(intern_rigid_symbol_wrt_module("DO-CONTAINED-BY", NULL, 2)));
            KWD_QUERY_SUBSUMPTION_OVERLAY = ((Keyword*)(intern_rigid_symbol_wrt_module("SUBSUMPTION-OVERLAY", NULL, 2)));
            SYM_QUERY_CONTAINED_BY = ((Symbol*)(intern_rigid_symbol_wrt_module("CONTAINED-BY", NULL, 0)));
            SYM_QUERY_IN = ((Symbol*)(intern_rigid_symbol_wrt_module("IN", string_get_module("/STELLA", TRUE), 0)));
            KWD_QUERY_SKIP_DEFINITION = ((Keyword*)(intern_rigid_symbol_wrt_module("SKIP-DEFINITION", NULL, 2)));
            KWD_QUERY_PRE_ANTECEDENTS = ((Keyword*)(intern_rigid_symbol_wrt_module("PRE-ANTECEDENTS", NULL, 2)));
            KWD_QUERY_DEFINITION = ((Keyword*)(intern_rigid_symbol_wrt_module("DEFINITION", NULL, 2)));
            KWD_QUERY_FULL_SUBQUERY = ((Keyword*)(intern_rigid_symbol_wrt_module("FULL-SUBQUERY", NULL, 2)));
            SYM_QUERY_DEFINITION = ((Symbol*)(intern_rigid_symbol_wrt_module("DEFINITION", NULL, 0)));
            SYM_QUERY_MONOTONICp = ((Symbol*)(intern_rigid_symbol_wrt_module("MONOTONIC?", NULL, 0)));
            SYM_QUERY_NON_DISJOINTNESS_KLUDGEp = ((Symbol*)(intern_rigid_symbol_wrt_module("NON-DISJOINTNESS-KLUDGE?", NULL, 0)));
            SGT_QUERY_COLLECTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION", string_get_module("/STELLA", TRUE), 1)));
            SGT_QUERY_COLLECTIONdCLOSED = ((Surrogate*)(intern_rigid_symbol_wrt_module("COLLECTION.CLOSED", string_get_module("/STELLA", TRUE), 1)));
            KWD_QUERY_CLOSED = ((Keyword*)(intern_rigid_symbol_wrt_module("CLOSED", NULL, 2)));
            KWD_QUERY_PRIMITIVE = ((Keyword*)(intern_rigid_symbol_wrt_module("PRIMITIVE", NULL, 2)));
            KWD_QUERY_ENUMERATION = ((Keyword*)(intern_rigid_symbol_wrt_module("ENUMERATION", NULL, 2)));
            SYM_QUERY_CURSOR = ((Symbol*)(intern_rigid_symbol_wrt_module("CURSOR", string_get_module("/STELLA", TRUE), 0)));
            SYM_QUERY_ROOT_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("ROOT-TYPE", NULL, 0)));
            SYM_QUERY_FILTER_TYPE = ((Symbol*)(intern_rigid_symbol_wrt_module("FILTER-TYPE", NULL, 0)));
            SYM_QUERY_NATIVE_CLASS_EXTENSION_ITERATOR = ((Symbol*)(intern_rigid_symbol_wrt_module("NATIVE-CLASS-EXTENSION-ITERATOR", NULL, 0)));
            SGT_QUERY_DESCRIPTION_EXTENSION_ITERATOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("DESCRIPTION-EXTENSION-ITERATOR", NULL, 1)));
            SYM_QUERY_GOAL_BINDINGS = ((Symbol*)(intern_rigid_symbol_wrt_module("GOAL-BINDINGS", NULL, 0)));
            SYM_QUERY_CACHED_BINDINGS = ((Symbol*)(intern_rigid_symbol_wrt_module("CACHED-BINDINGS", NULL, 0)));
            SYM_QUERY_REVERSE_POLARITY_CACHED_BINDINGS = ((Symbol*)(intern_rigid_symbol_wrt_module("REVERSE-POLARITY-CACHED-BINDINGS", NULL, 0)));
            SYM_QUERY_UP_FOR_GRABSp = ((Symbol*)(intern_rigid_symbol_wrt_module("UP-FOR-GRABS?", NULL, 0)));
            SYM_QUERY_CLUSTER = ((Symbol*)(intern_rigid_symbol_wrt_module("CLUSTER", NULL, 0)));
            SGT_QUERY_GOAL_CACHE = ((Surrogate*)(intern_rigid_symbol_wrt_module("GOAL-CACHE", NULL, 1)));
            SYM_QUERY_VECTOR_OF_GOAL_CACHE_TABLES = ((Symbol*)(intern_rigid_symbol_wrt_module("VECTOR-OF-GOAL-CACHE-TABLES", NULL, 0)));
            SGT_QUERY_GOAL_CACHE_CLUSTER = ((Surrogate*)(intern_rigid_symbol_wrt_module("GOAL-CACHE-CLUSTER", NULL, 1)));
            KWD_QUERY_GOAL_CACHES = ((Keyword*)(intern_rigid_symbol_wrt_module("GOAL-CACHES", NULL, 2)));
            SYM_QUERY_GOAL_CACHE_CLUSTER = ((Symbol*)(intern_rigid_symbol_wrt_module("GOAL-CACHE-CLUSTER", NULL, 0)));
            KWD_QUERY_EXECUTE_QUERY = ((Keyword*)(intern_rigid_symbol_wrt_module("EXECUTE-QUERY", NULL, 2)));
            KWD_QUERY_QUERY = ((Keyword*)(intern_rigid_symbol_wrt_module("QUERY", NULL, 2)));
            SYM_QUERY_AND = ((Symbol*)(intern_rigid_symbol_wrt_module("AND", string_get_module("/STELLA", TRUE), 0)));
            SYM_QUERY_KAPPA = ((Symbol*)(intern_rigid_symbol_wrt_module("KAPPA", NULL, 0)));
            SYM_QUERY_COMMA = ((Symbol*)(intern_rigid_symbol_wrt_module("COMMA", string_get_module("/STELLA", TRUE), 0)));
            SYM_QUERY_WHERE = ((Symbol*)(intern_rigid_symbol_wrt_module("WHERE", string_get_module("/STELLA", TRUE), 0)));
            SYM_QUERY_EXISTS = ((Symbol*)(intern_rigid_symbol_wrt_module("EXISTS", string_get_module("/STELLA", TRUE), 0)));
            KWD_QUERY_KIF = ((Keyword*)(intern_rigid_symbol_wrt_module("KIF", NULL, 2)));
            SYM_QUERY_TRUE = ((Symbol*)(intern_rigid_symbol_wrt_module("TRUE", string_get_module("/STELLA", TRUE), 0)));
            KWD_QUERY_STELLA = ((Keyword*)(intern_rigid_symbol_wrt_module("STELLA", NULL, 2)));
            KWD_QUERY_PREFIX_STELLA = ((Keyword*)(intern_rigid_symbol_wrt_module("PREFIX-STELLA", NULL, 2)));
            SGT_QUERY_LOGIC_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("LOGIC-EXCEPTION", NULL, 1)));
            KWD_QUERY_EXCEPTIONS = ((Keyword*)(intern_rigid_symbol_wrt_module("EXCEPTIONS", NULL, 2)));
            SGT_QUERY_EXCEPTION = ((Surrogate*)(intern_rigid_symbol_wrt_module("EXCEPTION", string_get_module("/STELLA", TRUE), 1)));
            SYM_QUERY_EVALUATOR_WRAPPER_CODE = ((Symbol*)(intern_rigid_symbol_wrt_module("EVALUATOR-WRAPPER-CODE", string_get_module("/STELLA", TRUE), 0)));
            KWD_QUERY_SUB = ((Keyword*)(intern_rigid_symbol_wrt_module("SUB", NULL, 2)));
            KWD_QUERY_SUPER = ((Keyword*)(intern_rigid_symbol_wrt_module("SUPER", NULL, 2)));
            SGT_QUERY_RELATION = ((Surrogate*)(intern_rigid_symbol_wrt_module("RELATION", string_get_module("/STELLA", TRUE), 1)));
            SGT_QUERY_VECTOR = ((Surrogate*)(intern_rigid_symbol_wrt_module("VECTOR", string_get_module("/STELLA", TRUE), 1)));
          }
          if (current_startup_time_phaseP(4)) {
            oMAXIMUM_BACKTRACKING_DEPTHo = oDEFAULT_MAXIMUM_DEPTHo;
            { Boolean_Vector_Index_Node* self_032 = new_boolean_vector_index_node();

              self_032->vector = new_boolean_vector(0);
              oBOOLEAN_VECTOR_INDEXo = self_032;
            }
            oTYPE_CHECK_STRATEGYo = KWD_QUERY_SORT;
            oMAXIMUM_QUERY_THREAD_OFFSETo = oQUERY_THREAD_LIMITo - 1;
            oFREE_QUERY_THREAD_OFFSETSo = list(0);
            oQUERY_ENVIRONMENTS_VECTORo = new_vector(oQUERY_THREAD_LIMITo);
            REUSABLE_SINGLETON_VECTOR = new_vector(1);
          }
          if (current_startup_time_phaseP(5)) {
            { Class* renamed_Class = define_class_from_stringified_source("QUERY-ITERATOR", "(DEFCLASS QUERY-ITERATOR (ITERATOR) :DOCUMENTATION \"A query iterator points to a query environment\nrepresenting the initial or intermediate state of a query.  The iterator's\n'value' is a vector representing a satisfying set bindings of the query's\noutput variables.  Each call to the iterator writes a new set of bindings\ninto the vector.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT-VECTOR)) :SLOTS ((QUERY-ENVIRONMENT :TYPE QUERY-ENVIRONMENT) (EXTERNAL-VARIABLES :TYPE VARIABLES-VECTOR) (SOLUTIONS :TYPE (LIST OF ARGUMENTS-VECTOR) :INITIALLY (NEW LIST)) (EXHAUSTED? :TYPE BOOLEAN)) :PRINT-FORM (PRINT-QUERY-ITERATOR SELF STREAM))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_query_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_query_iterator_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("CONTROL-FRAME", "(DEFCLASS CONTROL-FRAME (STANDARD-OBJECT) :SLOTS ((STATE :TYPE KEYWORD) (PHASE :TYPE KEYWORD) (PROPOSITION :TYPE PROPOSITION) (REVERSE-POLARITY? :TYPE BOOLEAN) (UP :TYPE CONTROL-FRAME) (DOWN :TYPE CONTROL-FRAME) (BACK :TYPE CONTROL-FRAME) (ARGUMENT-CURSOR :TYPE INTEGER :INITIALLY 0) (ITERATOR :TYPE ITERATOR) (SUBQUERY-FRAME :TYPE SUBQUERY-FRAME :RENAMES ITERATOR) (PARENT-PATTERN-FRAME :TYPE CONTROL-FRAME) (GOAL-CACHE :TYPE GOAL-CACHE) (PARTIAL-MATCH-FRAME :TYPE PARTIAL-MATCH-FRAME) (DEBUG-FRAME-OFFSET :TYPE INTEGER) (DEBUG-DEPTH :TYPE INTEGER :INITIALLY 0) (CHOICE-POINT-UNBINDING-OFFSET :TYPE INTEGER)) :PRINT-FORM (PRINT-CONTROL-FRAME SELF STREAM))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_control_frame));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_control_frame_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("GOAL-STRATEGY", "(DEFCLASS GOAL-STRATEGY (STANDARD-OBJECT) :DOCUMENTATION \"A goal-strategy contains a procedure for proving\none or more kinds of goals.\" :SLOTS ((KIND-OF-GOAL :TYPE KEYWORD) (STRATEGY-PRIORITY :TYPE INTEGER) (STRATEGY-PROCEDURE :TYPE FUNCTION-CODE)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_goal_strategy));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_goal_strategy_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("QUERY-ENVIRONMENT", "(DEFCLASS QUERY-ENVIRONMENT (STANDARD-OBJECT) :SLOTS ((CONTROL-FRAME-STACK :TYPE (VECTOR OF CONTROL-FRAME)) (CONTROL-FRAME-OFFSET-LIMIT :TYPE INTEGER) (TOP-CONTROL-FRAME-OFFSET :TYPE INTEGER) (VARIABLE-FRAME-STACK :TYPE (VECTOR OF OBJECT)) (VARIABLE-FRAME-OFFSET-LIMIT :TYPE INTEGER) (TOP-VARIABLE-FRAME-OFFSET :TYPE INTEGER) (UNBINDING-STACK :TYPE INTEGER-VECTOR) (UNBINDING-STACK-OFFSET-LIMIT :TYPE INTEGER) (TOP-UNBINDING-STACK-OFFSET :TYPE INTEGER) (CURRENT-VARIABLE-FRAME-OFFSET :TYPE INTEGER) (CURRENT-SUBQUERY-FRAME :TYPE SUBQUERY-FRAME) (PARTIAL-MATCH-STRATEGY :TYPE PARTIAL-MATCH-FRAME) (LATEST-POSITIVE-SCORE :TYPE PARTIAL-MATCH-SCORE) (ITERATIVE-DEEPENING? :TYPE BOOLEAN) (CURRENT-DEPTH-CUTOFF :TYPE INTEGER) (MAXIMUM-DEPTH :TYPE INTEGER) (AUGMENTED-GOAL-CACHE? :TYPE BOOLEAN) (ACTIVE-GOAL-CACHES :TYPE (LIST OF GOAL-CACHE) :ALLOCATION :EMBEDDED) (TRIGGERED-DEPTH-CUTOFF? :TYPE BOOLEAN) (FAILED-TO-FIND-DUPLICATE-SUBGOAL? :TYPE BOOLEAN) (FOUND-AT-LEAST-ONE-SOLUTION? :TYPE BOOLEAN) (DEEP-INFERENCE? :TYPE BOOLEAN) (QUERY-THREAD-OFFSET :TYPE INTEGER) (TIME-STAMP :TYPE TIME-STAMP) (QUERY-ITERATOR :TYPE QUERY-ITERATOR) (SUBSUMPTION-QUERY? :TYPE BOOLEAN) (SPECIALIZING-DESCRIPTION :TYPE DESCRIPTION) (OPTIMIZER-GOAL-RECORDS :TYPE (EXTENSIBLE-VECTOR OF GOAL-RECORD)) (RESIDUE-GOALS :TYPE (LIST OF PROPOSITION) :ALLOCATION :EMBEDDED) (BEST-GOAL-SEQUENCE :TYPE (LIST OF PROPOSITION) :ALLOCATION :EMBEDDED) (BEST-COST :TYPE INTEGER)) :INITIALIZER INITIALIZE-QUERY-ENVIRONMENT :RECYCLE-METHOD :FREE-LIST)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_query_environment));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_query_environment_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("SUBQUERY-FRAME", "(DEFCLASS SUBQUERY-FRAME (ITERATOR) :DOCUMENTATION \"A subquery frame records state needed to search\nantecedent descriptions, subclasses, and a defining description to produce\nits bindings.\" :SLOTS ((CONTROL-FRAME :TYPE CONTROL-FRAME) (DESCRIPTION :TYPE DESCRIPTION) (EXTERNAL-ARGUMENTS :TYPE ARGUMENTS-VECTOR) (BOOLEAN-VECTOR :TYPE BOOLEAN-VECTOR) (LOCAL-VARIABLE-FRAME-OFFSET :TYPE INTEGER) (OPTIMAL-PATTERN :TYPE DESCRIPTION) (PHASES-FILTER :TYPE KEYWORD) (ITERATOR :TYPE (ITERATOR OF PROPOSITION))) :RECYCLE-METHOD :FREE-LIST :TERMINATOR TERMINATE-SUBQUERY-FRAME?)");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_subquery_frame));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_subquery_frame_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("BOOLEAN-VECTOR-INDEX-NODE", "(DEFCLASS BOOLEAN-VECTOR-INDEX-NODE (STANDARD-OBJECT) :SLOTS ((TRUE-LINK :TYPE BOOLEAN-VECTOR-INDEX-NODE) (FALSE-LINK :TYPE BOOLEAN-VECTOR-INDEX-NODE) (VECTOR :TYPE BOOLEAN-VECTOR)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_boolean_vector_index_node));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_boolean_vector_index_node_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("DESCRIPTION-EXTENSION-ITERATOR", "(DEFCLASS DESCRIPTION-EXTENSION-ITERATOR (ITERATOR) :DOCUMENTATION \"Iterates over the extension of a top-level description,\nfiltering out deleted objects.  May create logic instances on-the-fly by\nwrapping native objects in the extension of the class attached to the\ndescription.\" :PARAMETERS ((ANY-VALUE :TYPE LOGIC-OBJECT)) :SLOTS ((CURSOR :TYPE (CONS OF LOGIC-OBJECT)) (ROOT-TYPE :TYPE TYPE) (FILTER-TYPE :TYPE TYPE) (NATIVE-CLASS-EXTENSION-ITERATOR :TYPE ITERATOR)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_description_extension_iterator));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_description_extension_iterator_slot_value));
            }
            define_stella_type_from_stringified_source("(DEFTYPE GOAL-BINDINGS (CONS OF OBJECT))");
            { Class* renamed_Class = define_class_from_stringified_source("GOAL-CACHE", "(DEFCLASS GOAL-CACHE (STANDARD-OBJECT) :DOCUMENTATION \"Cache of output bindings derived for a particular goal\nand set of input bindings.\" :SLOTS ((CACHED-BINDINGS :TYPE (LIST OF GOAL-BINDINGS) :ALLOCATION :EMBEDDED) (REVERSE-POLARITY-CACHED-BINDINGS :TYPE (LIST OF GOAL-BINDINGS) :ALLOCATION :EMBEDDED) (UP-FOR-GRABS? :TYPE BOOLEAN) (CLUSTER :TYPE GOAL-CACHE-CLUSTER)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_goal_cache));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_goal_cache_slot_value));
            }
            { Class* renamed_Class = define_class_from_stringified_source("GOAL-CACHE-CLUSTER", "(DEFCLASS GOAL-CACHE-CLUSTER (STANDARD-OBJECT) :SLOTS ((VECTOR-OF-GOAL-CACHE-TABLES :TYPE (VECTOR SIZE 8 OF (KEY-VALUE-LIST OF GOAL-BINDINGS GOAL-CACHE))) (TIME-STAMP :TYPE TIME-STAMP) (PROPOSITION :TYPE PROPOSITION)))");

              renamed_Class->class_constructor_code = ((cpp_function_code)(&new_goal_cache_cluster));
              renamed_Class->class_slot_accessor_code = ((cpp_function_code)(&access_goal_cache_cluster_slot_value));
            }
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("DEEP-INFERENCE-MODE?", NULL, "(DEFUN (DEEP-INFERENCE-MODE? BOOLEAN) () :DOCUMENTATION \"Determines whether expensive inferencing is warranted.\")");

              method->function_code = ((cpp_function_code)(&deep_inference_modeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SUBSUMPTION-MODE?", NULL, "(DEFUN (SUBSUMPTION-MODE? BOOLEAN) ())");

              method->function_code = ((cpp_function_code)(&subsumption_modeP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-BOOLEAN-VECTOR-INDEX-NODE", "BOOLEAN-VECTOR-INDEX-NODE", "(DEFUN (CREATE-BOOLEAN-VECTOR-INDEX-NODE BOOLEAN-VECTOR-INDEX-NODE) ((PARENTNODE BOOLEAN-VECTOR-INDEX-NODE) (LASTVALUE BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&create_boolean_vector_index_node));
            }
            { Method_Slot* method = define_method_from_stringified_source("ARGUMENTS-VECTOR-TO-BOOLEAN-VECTOR", "VECTOR", "(DEFUN (ARGUMENTS-VECTOR-TO-BOOLEAN-VECTOR BOOLEAN-VECTOR) ((ARGUMENTSVECTOR ARGUMENTS-VECTOR)))");

              method->function_code = ((cpp_function_code)(&arguments_vector_to_boolean_vector));
            }
            { Method_Slot* method = define_method_from_stringified_source("ZERO-ONE-LIST-TO-BOOLEAN-VECTOR", "LIST", "(DEFUN (ZERO-ONE-LIST-TO-BOOLEAN-VECTOR BOOLEAN-VECTOR) ((ZEROONELIST (LIST OF INTEGER-WRAPPER))))");

              method->function_code = ((cpp_function_code)(&zero_one_list_to_boolean_vector));
            }
            { Method_Slot* method = define_method_from_stringified_source("INITIALIZE-QUERY-ENVIRONMENT", "QUERY-ENVIRONMENT", "(DEFUN INITIALIZE-QUERY-ENVIRONMENT ((ENVIRONMENT QUERY-ENVIRONMENT)))");

              method->function_code = ((cpp_function_code)(&initialize_query_environment));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXPAND-CONTROL-FRAME-STACK", "QUERY-ENVIRONMENT", "(DEFUN EXPAND-CONTROL-FRAME-STACK ((QUERYENVIRONMENT QUERY-ENVIRONMENT)))");

              method->function_code = ((cpp_function_code)(&expand_control_frame_stack));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEW-TOP-CONTROL-FRAME", "QUERY-ENVIRONMENT", "(DEFUN (NEW-TOP-CONTROL-FRAME CONTROL-FRAME) ((QUERYENVIRONMENT QUERY-ENVIRONMENT)))");

              method->function_code = ((cpp_function_code)(&new_top_control_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP-CONTROL-FRAME", "QUERY-ENVIRONMENT", "(DEFUN POP-CONTROL-FRAME ((QUERYENVIRONMENT QUERY-ENVIRONMENT)))");

              method->function_code = ((cpp_function_code)(&pop_control_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("POP-FRAMES-DOWN-TO", "CONTROL-FRAME", "(DEFUN POP-FRAMES-DOWN-TO ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&pop_frames_down_to));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXPAND-VARIABLE-FRAME-STACK", "QUERY-ENVIRONMENT", "(DEFUN EXPAND-VARIABLE-FRAME-STACK ((QUERYENVIRONMENT QUERY-ENVIRONMENT)))");

              method->function_code = ((cpp_function_code)(&expand_variable_frame_stack));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-BLOCK-OF-VARIABLE-FRAMES", "INTEGER", "(DEFUN (ALLOCATE-BLOCK-OF-VARIABLE-FRAMES INTEGER) ((VARIABLECOUNT INTEGER) (FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&allocate_block_of_variable_frames));
            }
            { Method_Slot* method = define_method_from_stringified_source("DEALLOCATE-BLOCK-OF-VARIABLE-FRAMES", "CONTROL-FRAME", "(DEFUN DEALLOCATE-BLOCK-OF-VARIABLE-FRAMES ((FRAME CONTROL-FRAME)) :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&deallocate_block_of_variable_frames));
            }
            { Method_Slot* method = define_method_from_stringified_source("RESET-CURRENT-VARIABLE-FRAME-OFFSET", "CONTROL-FRAME", "(DEFUN RESET-CURRENT-VARIABLE-FRAME-OFFSET ((FRAME CONTROL-FRAME) (LOCALORPARENT KEYWORD)))");

              method->function_code = ((cpp_function_code)(&reset_current_variable_frame_offset));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXPAND-UNBINDING-STACK", "QUERY-ENVIRONMENT", "(DEFUN EXPAND-UNBINDING-STACK ((QUERYENVIRONMENT QUERY-ENVIRONMENT)))");

              method->function_code = ((cpp_function_code)(&expand_unbinding_stack));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-ENVIRONMENT-STACKS", NULL, "(DEFUN PRINT-ENVIRONMENT-STACKS ())");

              method->function_code = ((cpp_function_code)(&print_environment_stacks));
            }
            { Method_Slot* method = define_method_from_stringified_source("SET-PATTERN-VARIABLE-BINDING", "PATTERN-VARIABLE", "(DEFUN SET-PATTERN-VARIABLE-BINDING ((VARIABLE PATTERN-VARIABLE) (VALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&set_pattern_variable_binding));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNBIND-VARIABLES-BEGINNING-AT", "INTEGER", "(DEFUN UNBIND-VARIABLES-BEGINNING-AT ((UBSTACKOFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&unbind_variables_beginning_at));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNBIND-PATTERN-VARIABLES", "CONTROL-FRAME", "(DEFUN UNBIND-PATTERN-VARIABLES ((FRAME CONTROL-FRAME)) :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&unbind_pattern_variables));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-CHOICE-POINT", "CONTROL-FRAME", "(DEFUN CREATE-CHOICE-POINT ((FRAME CONTROL-FRAME)) :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&create_choice_point));
            }
            { Method_Slot* method = define_method_from_stringified_source("BOUND-TO", "PATTERN-VARIABLE", "(DEFUN (BOUND-TO OBJECT) ((SELF PATTERN-VARIABLE)) :GLOBALLY-INLINE? TRUE)");

              method->function_code = ((cpp_function_code)(&bound_to));
            }
            { Method_Slot* method = define_method_from_stringified_source("ARGUMENT-BOUND-TO", "OBJECT", "(DEFUN (ARGUMENT-BOUND-TO OBJECT) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&argument_bound_to));
            }
            { Method_Slot* method = define_method_from_stringified_source("NATIVE-ARGUMENT-BOUND-TO", "OBJECT", "(DEFUN (NATIVE-ARGUMENT-BOUND-TO OBJECT) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&native_argument_bound_to));
            }
            { Method_Slot* method = define_method_from_stringified_source("OPERATOR-BOUND-TO", "OBJECT", "(DEFUN (OPERATOR-BOUND-TO SLOT) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&operator_bound_to));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-UNIFY-ATTRIBUTES?", "OBJECT", "(DEFUN (HELP-UNIFY-ATTRIBUTES? BOOLEAN) ((VALUE1 OBJECT) (VALUE2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&help_unify_attributesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FAILS-TYPE-CHECK?", "PATTERN-VARIABLE", "(DEFUN (FAILS-TYPE-CHECK? BOOLEAN) ((V1 PATTERN-VARIABLE) (I2 OBJECT)))");

              method->function_code = ((cpp_function_code)(&fails_type_checkP));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-BIND-VARIABLE-TO-VALUE?", "PATTERN-VARIABLE", "(DEFUN (HELP-BIND-VARIABLE-TO-VALUE? BOOLEAN) ((VARIABLE PATTERN-VARIABLE) (VALUE OBJECT)))");

              method->function_code = ((cpp_function_code)(&help_bind_variable_to_valueP));
            }
            { Method_Slot* method = define_method_from_stringified_source("BIND-VARIABLE-TO-VALUE?", "PATTERN-VARIABLE", "(DEFUN (BIND-VARIABLE-TO-VALUE? BOOLEAN) ((VARIABLE PATTERN-VARIABLE) (VALUE OBJECT) (AUTOCLEANUP? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&bind_variable_to_valueP));
            }
            { Method_Slot* method = define_method_from_stringified_source("BIND-ARGUMENT-TO-VALUE?", "OBJECT", "(DEFUN (BIND-ARGUMENT-TO-VALUE? BOOLEAN) ((ARGUMENT OBJECT) (VALUE OBJECT) (AUTOCLEANUP? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&bind_argument_to_valueP));
            }
            { Method_Slot* method = define_method_from_stringified_source("BIND-VECTOR-OF-ARGUMENTS-TO-VALUES?", "VECTOR", "(DEFUN (BIND-VECTOR-OF-ARGUMENTS-TO-VALUES? BOOLEAN) ((ARGUMENTS ARGUMENTS-VECTOR) (VALUES CONS)))");

              method->function_code = ((cpp_function_code)(&bind_vector_of_arguments_to_valuesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("PCS", NULL, "(DEFUN PCS ())");

              method->function_code = ((cpp_function_code)(&pcs));
            }
            { Method_Slot* method = define_method_from_stringified_source("VARIABLE-FROM-UNBINDING-OFFSET", "DESCRIPTION", "(DEFUN (VARIABLE-FROM-UNBINDING-OFFSET PATTERN-VARIABLE) ((DESCRIPTION DESCRIPTION) (UBOFFSET INTEGER)))");

              method->function_code = ((cpp_function_code)(&variable_from_unbinding_offset));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-FRAME-OFFSET", "CONTROL-FRAME", "(DEFUN (COMPUTE-FRAME-OFFSET INTEGER) ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&compute_frame_offset));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-ONE-VARIABLE-BINDING", "PATTERN-VARIABLE", "(DEFUN PRINT-ONE-VARIABLE-BINDING ((VARIABLE PATTERN-VARIABLE)))");

              method->function_code = ((cpp_function_code)(&print_one_variable_binding));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-VARIABLE-BINDINGS", "CONTROL-FRAME", "(DEFUN PRINT-VARIABLE-BINDINGS ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&print_variable_bindings));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRACE-GOAL-TREE", "CONTROL-FRAME", "(DEFUN TRACE-GOAL-TREE ((FRAME CONTROL-FRAME) (DEPTH INTEGER) (LASTMOVE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&trace_goal_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERPRET-AND-SCORES", "CONTROL-FRAME", "(DEFUN (INTERPRET-AND-SCORES KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&interpret_and_scores));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERPRET-OR-SCORES", "CONTROL-FRAME", "(DEFUN (INTERPRET-OR-SCORES KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&interpret_or_scores));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERPRET-FAIL-SCORE", "CONTROL-FRAME", "(DEFUN (INTERPRET-FAIL-SCORE KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&interpret_fail_score));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERPRET-SUBGOALS-SCORES", "CONTROL-FRAME", "(DEFUN (INTERPRET-SUBGOALS-SCORES KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&interpret_subgoals_scores));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-DOWN-FRAME", "CONTROL-FRAME", "(DEFUN (CREATE-DOWN-FRAME CONTROL-FRAME) ((UPFRAME CONTROL-FRAME) (DOWNPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&create_down_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("EXECUTE-BACKWARD-CHAINING-PROOF?", "QUERY-ENVIRONMENT", "(DEFUN (EXECUTE-BACKWARD-CHAINING-PROOF? BOOLEAN) ((QUERYENVIRONMENT QUERY-ENVIRONMENT)))");

              method->function_code = ((cpp_function_code)(&execute_backward_chaining_proofP));
            }
            { Method_Slot* method = define_method_from_stringified_source("SELECT-NEXT-PROOF-STRATEGY", "CONTROL-FRAME", "(DEFUN (SELECT-NEXT-PROOF-STRATEGY KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&select_next_proof_strategy));
            }
            { Method_Slot* method = define_method_from_stringified_source("APPLY-SLOT-TO-NATIVE-QUERY-ARGUMENTS", "SLOT", "(DEFMETHOD (APPLY-SLOT-TO-NATIVE-QUERY-ARGUMENTS OBJECT) ((SLOT SLOT) (ARGUMENTS VECTOR)))");

              method->method_code = ((cpp_method_code)(&Slot::apply_slot_to_native_query_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("APPLY-SLOT-TO-NATIVE-QUERY-ARGUMENTS", "STORAGE-SLOT", "(DEFMETHOD (APPLY-SLOT-TO-NATIVE-QUERY-ARGUMENTS OBJECT) ((SLOT STORAGE-SLOT) (ARGUMENTS VECTOR)))");

              method->method_code = ((cpp_method_code)(&Storage_Slot::apply_slot_to_native_query_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("APPLY-SLOT-TO-NATIVE-QUERY-ARGUMENTS", "METHOD-SLOT", "(DEFMETHOD (APPLY-SLOT-TO-NATIVE-QUERY-ARGUMENTS OBJECT) ((SLOT METHOD-SLOT) (ARGUMENTS VECTOR)))");

              method->method_code = ((cpp_method_code)(&Method_Slot::apply_slot_to_native_query_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTINUE-ATOMIC-PROPOSITION-PROOF", "CONTROL-FRAME", "(DEFUN (CONTINUE-ATOMIC-PROPOSITION-PROOF KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&continue_atomic_proposition_proof));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-ARGUMENTS-BOUND?", "PROPOSITION", "(DEFUN (ALL-ARGUMENTS-BOUND? BOOLEAN) ((GOAL PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&all_arguments_boundP));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-SPECIALIZING-FUNCTION-PROPOSITION-VALUE", "PROPOSITION", "(DEFUN (FIND-SPECIALIZING-FUNCTION-PROPOSITION-VALUE OBJECT) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&find_specializing_function_proposition_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("QUERY-FOR-ASSERTED-FUNCTION-PROPOSITION-VALUE", "PROPOSITION", "(DEFUN (QUERY-FOR-ASSERTED-FUNCTION-PROPOSITION-VALUE OBJECT) ((SELF PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&query_for_asserted_function_proposition_value));
            }
            { Method_Slot* method = define_method_from_stringified_source("MANUFACTURE-DEFINING-SKOLEM", "SLOT", "(DEFUN (MANUFACTURE-DEFINING-SKOLEM KEYWORD) ((SLOT SLOT) (GOALPROPOSITION PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&manufacture_defining_skolem));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTINUE-FUNCTION-PROPOSITION-PROOF", "PROPOSITION", "(DEFUN (CONTINUE-FUNCTION-PROPOSITION-PROOF KEYWORD) ((SELF PROPOSITION) (FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&continue_function_proposition_proof));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTINUE-PREDICATE-PROPOSITION-PROOF", "PROPOSITION", "(DEFUN (CONTINUE-PREDICATE-PROPOSITION-PROOF KEYWORD) ((SELF PROPOSITION) (FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&continue_predicate_proposition_proof));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTINUE-EQUIVALENT-PROPOSITION-PROOF", "PROPOSITION", "(DEFUN (CONTINUE-EQUIVALENT-PROPOSITION-PROOF KEYWORD) ((SELF PROPOSITION) (FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&continue_equivalent_proposition_proof));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTINUE-IN-PROPOSITION-PROOF", "PROPOSITION", "(DEFUN (CONTINUE-IN-PROPOSITION-PROOF KEYWORD) ((SELF PROPOSITION) (FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&continue_in_proposition_proof));
            }
            { Method_Slot* method = define_method_from_stringified_source("INFERRABLE-DESCRIPTION?", "OBJECT", "(DEFUN (INFERRABLE-DESCRIPTION? BOOLEAN) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&inferrable_descriptionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("UNNAMED-DESCRIPTION?", "OBJECT", "(DEFUN (UNNAMED-DESCRIPTION? BOOLEAN) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&unnamed_descriptionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTINUE-IMPLIES-PROPOSITION-PROOF", "PROPOSITION", "(DEFUN (CONTINUE-IMPLIES-PROPOSITION-PROOF KEYWORD) ((SELF PROPOSITION) (FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&continue_implies_proposition_proof));
            }
            { Method_Slot* method = define_method_from_stringified_source("SPAWN-CONTAINED-BY-SUBQUERY", "CONTROL-FRAME", "(DEFUN (SPAWN-CONTAINED-BY-SUBQUERY KEYWORD) ((UPFRAME CONTROL-FRAME) (TAIL OBJECT) (HEAD OBJECT)))");

              method->function_code = ((cpp_function_code)(&spawn_contained_by_subquery));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-CONTAINED-BY-ARGUMENT", "OBJECT", "(DEFUN (CREATE-CONTAINED-BY-ARGUMENT PROPOSITION) ((COLLECTION OBJECT) (BRIDGEARGS LIST) (LASTCALL? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&create_contained_by_argument));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTINUE-CONSTANT-PROPOSITION-PROOF", "PROPOSITION", "(DEFUN (CONTINUE-CONSTANT-PROPOSITION-PROOF KEYWORD) ((SELF PROPOSITION) (FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&continue_constant_proposition_proof));
            }
            { Method_Slot* method = define_method_from_stringified_source("OVERLAY-WITH-PATTERN-FRAME", "CONTROL-FRAME", "(DEFUN (OVERLAY-WITH-PATTERN-FRAME KEYWORD) ((FRAME CONTROL-FRAME) (DESCRIPTION DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&overlay_with_pattern_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("TRANSFER-PATTERN-QUERY-BINDINGS?", "CONTROL-FRAME", "(DEFUN (TRANSFER-PATTERN-QUERY-BINDINGS? BOOLEAN) ((FRAME CONTROL-FRAME) (FUTUREBINDINGS? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&transfer_pattern_query_bindingsP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-ANTECEDENTS-ITERATOR", "SUBQUERY-FRAME", "(DEFUN (ALLOCATE-ANTECEDENTS-ITERATOR (ITERATOR OF PROPOSITION)) ((SUBQUERYFRAME SUBQUERY-FRAME) (REVERSEPOLARITY? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&allocate_antecedents_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTINUE-SUBGOALS-PROOF", "CONTROL-FRAME", "(DEFUN (CONTINUE-SUBGOALS-PROOF KEYWORD) ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&continue_subgoals_proof));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEW-TOP-SUBQUERY-FRAME", NULL, "(DEFUN (NEW-TOP-SUBQUERY-FRAME SUBQUERY-FRAME) ())");

              method->function_code = ((cpp_function_code)(&new_top_subquery_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-SUBQUERY-FRAME", "DESCRIPTION", "(DEFUN (ALLOCATE-SUBQUERY-FRAME SUBQUERY-FRAME) ((DESCRIPTION DESCRIPTION) (EXTERNALARGUMENTS ARGUMENTS-VECTOR)))");

              method->function_code = ((cpp_function_code)(&allocate_subquery_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("TERMINATE-SUBQUERY-FRAME?", "SUBQUERY-FRAME", "(DEFUN (TERMINATE-SUBQUERY-FRAME? BOOLEAN) ((SELF SUBQUERY-FRAME)))");

              method->function_code = ((cpp_function_code)(&terminate_subquery_frameP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-SUBQUERY-ARGUMENTS", "VECTOR", "(DEFUN (COPY-SUBQUERY-ARGUMENTS ARGUMENTS-VECTOR) ((ARGUMENTS OBJECT-VECTOR) (OMITLASTARGUMENT? BOOLEAN) (DESCRIPTION DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&copy_subquery_arguments));
            }
            { Method_Slot* method = define_method_from_stringified_source("OVERLAY-WITH-SUBGOALS-FRAME", "CONTROL-FRAME", "(DEFUN (OVERLAY-WITH-SUBGOALS-FRAME KEYWORD) ((FRAME CONTROL-FRAME) (DESCRIPTION DESCRIPTION) (EXTERNALARGUMENTS ARGUMENTS-VECTOR) (OMITLASTARGUMENT? BOOLEAN) (PHASESFILTER KEYWORD)))");

              method->function_code = ((cpp_function_code)(&overlay_with_subgoals_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("SPAWN-SUBQUERY", "CONTROL-FRAME", "(DEFUN (SPAWN-SUBQUERY KEYWORD) ((UPFRAME CONTROL-FRAME) (DESCRIPTION DESCRIPTION) (PHASESFILTER KEYWORD) (OVERLAY? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&spawn_subquery));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONTINUE-DISJUNCTION-PROOF", "CONTROL-FRAME", "(DEFUN (CONTINUE-DISJUNCTION-PROOF KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))");

              method->function_code = ((cpp_function_code)(&continue_disjunction_proof));
            }
            { Method_Slot* method = define_method_from_stringified_source("DISJOINT-CLASSES?", "CLASS", "(DEFUN (DISJOINT-CLASSES? BOOLEAN) ((CLASS1 CLASS) (CLASS2 CLASS)))");

              method->function_code = ((cpp_function_code)(&disjoint_classesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ROOT-TYPE-IMPLIES-MEMBER?", "OBJECT", "(DEFUN (ROOT-TYPE-IMPLIES-MEMBER? BOOLEAN) ((SELF OBJECT) (MEMBER OBJECT)))");

              method->function_code = ((cpp_function_code)(&root_type_implies_memberP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECTION-HAS-MEMBER", "OBJECT", "(DEFUN (COLLECTION-HAS-MEMBER KEYWORD) ((SELF OBJECT) (MEMBER OBJECT)))");

              method->function_code = ((cpp_function_code)(&collection_has_member));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLOSED-COLLECTION?", "OBJECT", "(DEFUN (CLOSED-COLLECTION? BOOLEAN) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&closed_collectionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECTION-MEMBERS", "OBJECT", "(DEFUN (COLLECTION-MEMBERS ITERATOR) ((SELF OBJECT) (OPENORCLOSED KEYWORD)))");

              method->function_code = ((cpp_function_code)(&collection_members));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECTION-CONTAINED-IN-COLLECTION", "OBJECT", "(DEFUN (COLLECTION-CONTAINED-IN-COLLECTION KEYWORD) ((SUBCOLLECTION OBJECT) (SUPERCOLLECTION OBJECT)))");

              method->function_code = ((cpp_function_code)(&collection_contained_in_collection));
            }
            { Method_Slot* method = define_method_from_stringified_source("COLLECTION-IMPLIES-COLLECTION?", "OBJECT", "(DEFUN (COLLECTION-IMPLIES-COLLECTION? BOOLEAN) ((SUBCOLLECTION OBJECT) (SUPERCOLLECTION OBJECT)))");

              method->function_code = ((cpp_function_code)(&collection_implies_collectionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-ITERATOR", "DESCRIPTION", "(DEFMETHOD (ALLOCATE-ITERATOR DESCRIPTION-EXTENSION-ITERATOR) ((SELF DESCRIPTION)))");

              method->method_code = ((cpp_method_code)(&Description::allocate_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "DESCRIPTION-EXTENSION-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF DESCRIPTION-EXTENSION-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Description_Extension_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("RESERVE-QUERY-THREAD", "QUERY-ENVIRONMENT", "(DEFUN RESERVE-QUERY-THREAD ((QUERYENVIRONMENT QUERY-ENVIRONMENT)) :DOCUMENTATION \"Find a free query thread and assign it to 'queryEnvironment'.\nSignal a :QUERY-THREAD-LIMIT-VIOLATION exception if all threads are taken.\")");

              method->function_code = ((cpp_function_code)(&reserve_query_thread));
            }
            { Method_Slot* method = define_method_from_stringified_source("RELEASE-QUERY-THREAD", "QUERY-ENVIRONMENT", "(DEFUN RELEASE-QUERY-THREAD ((QUERYENVIRONMENT QUERY-ENVIRONMENT)) :DOCUMENTATION \"Release the query thread for 'queryEnvironment'.\")");

              method->function_code = ((cpp_function_code)(&release_query_thread));
            }
            { Method_Slot* method = define_method_from_stringified_source("RELEASE-ALL-QUERY-THREADS", NULL, "(DEFUN (RELEASE-ALL-QUERY-THREADS (LIST OF INTEGER-WRAPPER)) () :DOCUMENTATION \"Free up all query threads (buggy queries may have\nfailed to terminate).\")");

              method->function_code = ((cpp_function_code)(&release_all_query_threads));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-QUERY-THREADS", NULL, "(DEFUN (CLEAR-QUERY-THREADS (LIST OF INTEGER-WRAPPER)) ())");

              method->function_code = ((cpp_function_code)(&clear_query_threads));
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-CACHED-BINDINGS", "GOAL-CACHE", "(DEFUN (GET-CACHED-BINDINGS (LIST OF GOAL-BINDINGS)) ((GOALCACHE GOAL-CACHE) (FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&get_cached_bindings));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-GOAL-CACHE", "GOAL-CACHE", "(DEFUN PRINT-GOAL-CACHE ((SELF GOAL-CACHE)))");

              method->function_code = ((cpp_function_code)(&print_goal_cache));
            }
            define_external_slot_from_stringified_source("(DEFSLOT SLOT GOAL-CACHE-CLUSTER :TYPE GOAL-CACHE-CLUSTER :DOCUMENTATION \"Allow attachment of goal caches to slots.\" :ALLOCATION :DYNAMIC)");
            define_external_slot_from_stringified_source("(DEFSLOT CLASS GOAL-CACHE-CLUSTER :TYPE GOAL-CACHE-CLUSTER :DOCUMENTATION \"Allow attachment of goal caches to classes.\" :ALLOCATION :DYNAMIC)");
            { Method_Slot* method = define_method_from_stringified_source("HELP-FIND-DUPLICATED-GOAL", "CONTROL-FRAME", "(DEFUN (HELP-FIND-DUPLICATED-GOAL CONTROL-FRAME CONTROL-FRAME INTEGER) ((GOALFRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&help_find_duplicated_goal));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-DUPLICATED-GOAL", NULL, "(DEFUN (FIND-DUPLICATED-GOAL CONTROL-FRAME CONTROL-FRAME INTEGER) ())");

              method->function_code = ((cpp_function_code)(&find_duplicated_goal));
            }
            { Method_Slot* method = define_method_from_stringified_source("YIELD-GOAL-BINDINGS", "CONTROL-FRAME", "(DEFUN (YIELD-GOAL-BINDINGS CONS) ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&yield_goal_bindings));
            }
            { Method_Slot* method = define_method_from_stringified_source("LOOKUP-GOAL-CACHE", "GOAL-CACHE-CLUSTER", "(DEFUN (LOOKUP-GOAL-CACHE GOAL-CACHE) ((CLUSTER GOAL-CACHE-CLUSTER) (FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&lookup_goal_cache));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-GOAL-CACHE-CLUSTER", "PROPOSITION", "(DEFUN (FIND-GOAL-CACHE-CLUSTER GOAL-CACHE-CLUSTER) ((GOAL PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&find_goal_cache_cluster));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-GOAL-CACHE", "CONTROL-FRAME", "(DEFUN (FIND-GOAL-CACHE GOAL-CACHE) ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&find_goal_cache));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-GOAL-CACHE-CLUSTER", "PROPOSITION", "(DEFUN (CREATE-GOAL-CACHE-CLUSTER GOAL-CACHE-CLUSTER) ((GOAL PROPOSITION)))");

              method->function_code = ((cpp_function_code)(&create_goal_cache_cluster));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-GOAL-CACHE?", "CONTROL-FRAME", "(DEFUN (CREATE-GOAL-CACHE? BOOLEAN) ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&create_goal_cacheP));
            }
            { Method_Slot* method = define_method_from_stringified_source("HANDLE-DEPTH-VIOLATION", "CONTROL-FRAME", "(DEFUN (HANDLE-DEPTH-VIOLATION CONTROL-FRAME INTEGER) ((FRAME CONTROL-FRAME) (DEPTH INTEGER)))");

              method->function_code = ((cpp_function_code)(&handle_depth_violation));
            }
            { Method_Slot* method = define_method_from_stringified_source("ACCESS-GOAL-CACHE", "CONTROL-FRAME", "(DEFUN (ACCESS-GOAL-CACHE KEYWORD) ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&access_goal_cache));
            }
            { Method_Slot* method = define_method_from_stringified_source("UPDATE-GOAL-CACHE", "CONTROL-FRAME", "(DEFUN UPDATE-GOAL-CACHE ((FRAME CONTROL-FRAME) (SUCCESS? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&update_goal_cache));
            }
            { Method_Slot* method = define_method_from_stringified_source("OVERLAY-WITH-CACHED-BINDINGS", "CONTROL-FRAME", "(DEFUN (OVERLAY-WITH-CACHED-BINDINGS KEYWORD) ((FRAME CONTROL-FRAME) (GOALCACHE GOAL-CACHE)))");

              method->function_code = ((cpp_function_code)(&overlay_with_cached_bindings));
            }
            { Method_Slot* method = define_method_from_stringified_source("SCAN-CACHED-BINDINGS", "CONTROL-FRAME", "(DEFUN (SCAN-CACHED-BINDINGS KEYWORD) ((FRAME CONTROL-FRAME)))");

              method->function_code = ((cpp_function_code)(&scan_cached_bindings));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-CONTROL-FRAME", "CONTROL-FRAME", "(DEFUN PRINT-CONTROL-FRAME ((SELF CONTROL-FRAME) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_control_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-GOAL-STACK", NULL, "(DEFUN PRINT-GOAL-STACK () :DOCUMENTATION \"Print stack of goals.  Assumes that query has been interrupted\nwith a full stack of control frames.\")");

              method->function_code = ((cpp_function_code)(&print_goal_stack));
            }
            { Method_Slot* method = define_method_from_stringified_source("PGS", NULL, "(DEFUN PGS ())");

              method->function_code = ((cpp_function_code)(&pgs));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-QUERY-ITERATOR", "QUERY-ITERATOR", "(DEFUN PRINT-QUERY-ITERATOR ((SELF QUERY-ITERATOR) (STREAM NATIVE-OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_query_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-QUERY-ITERATOR", NULL, "(DEFUN (ALLOCATE-QUERY-ITERATOR QUERY-ITERATOR) ())");

              method->function_code = ((cpp_function_code)(&allocate_query_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE", "QUERY-ITERATOR", "(DEFMETHOD FREE ((SELF QUERY-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Query_Iterator::free));
            }
            { Method_Slot* method = define_method_from_stringified_source("FREE-QUERY-ITERATOR", "QUERY-ITERATOR", "(DEFUN FREE-QUERY-ITERATOR ((SELF QUERY-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&free_query_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-QUERY-ITERATOR", "DESCRIPTION", "(DEFUN (CREATE-QUERY-ITERATOR QUERY-ITERATOR) ((DESCRIPTION DESCRIPTION) (OUTSIDEARGUMENTS VECTOR)))");

              method->function_code = ((cpp_function_code)(&create_query_iterator));
            }
            { Method_Slot* method = define_method_from_stringified_source("BOOTSTRAP-INITIALIZE-SUBQUERY-FRAME", "SUBQUERY-FRAME", "(DEFUN BOOTSTRAP-INITIALIZE-SUBQUERY-FRAME ((SUBQUERYFRAME SUBQUERY-FRAME) (DESCRIPTION DESCRIPTION) (EXTERNALARGUMENTS ARGUMENTS-VECTOR) (OUTSIDEARGUMENTS VECTOR)))");

              method->function_code = ((cpp_function_code)(&bootstrap_initialize_subquery_frame));
            }
            { Method_Slot* method = define_method_from_stringified_source("NEXT?", "QUERY-ITERATOR", "(DEFMETHOD (NEXT? BOOLEAN) ((SELF QUERY-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Query_Iterator::nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("RESET", "QUERY-ITERATOR", "(DEFMETHOD RESET ((SELF QUERY-ITERATOR)))");

              method->method_code = ((cpp_method_code)(&Query_Iterator::reset));
            }
            { Method_Slot* method = define_method_from_stringified_source("COPY-VECTOR-TO-CONS-LIST", "VECTOR", "(DEFUN (COPY-VECTOR-TO-CONS-LIST CONS) ((VECTOR VECTOR)))");

              method->function_code = ((cpp_function_code)(&copy_vector_to_cons_list));
            }
            { Method_Slot* method = define_method_from_stringified_source("LISTIFY", "QUERY-ITERATOR", "(DEFMETHOD (LISTIFY LIST) ((SELF QUERY-ITERATOR)) :DOCUMENTATION \"Return the list of tuples generated by 'self'.\nTuples of arity=1 are represented directly by the first element,\ntuples of arity>1 are represented by a CONS list.\" :PUBLIC? TRUE)");

              method->method_code = ((cpp_method_code)(&Query_Iterator::listify));
            }
            { Method_Slot* method = define_method_from_stringified_source("STANDARDIZE-QUERY-TREE", "OBJECT", "(DEFUN (STANDARDIZE-QUERY-TREE CONS) ((QUERYTREE OBJECT) (TRUEFALSE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&standardize_query_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CONS.STANDARDIZE-QUERY-TREE", "CONS", "(DEFUN (CONS.STANDARDIZE-QUERY-TREE CONS) ((QUERYTREE CONS) (TRUEFALSE? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&consDstandardize_query_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("HANDLE-QUERY-EXCEPTION", "EXCEPTION", "(DEFUN HANDLE-QUERY-EXCEPTION ((EXCEPTION EXCEPTION) (COMMAND STRING)))");

              method->function_code = ((cpp_function_code)(&handle_query_exception));
            }
            { Method_Slot* method = define_method_from_stringified_source("MAKE-QUERY", "OBJECT", "(DEFUN (MAKE-QUERY QUERY-ITERATOR) ((QUERYTREE OBJECT) (YESNO? BOOLEAN)))");

              method->function_code = ((cpp_function_code)(&make_query));
            }
            { Method_Slot* method = define_method_from_stringified_source("RUN-YES-OR-NO-QUERY?", "QUERY-ITERATOR", "(DEFUN (RUN-YES-OR-NO-QUERY? BOOLEAN) ((QUERYITERATOR QUERY-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&run_yes_or_no_queryP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COERCE-TO-TREE", "OBJECT", "(DEFUN (COERCE-TO-TREE OBJECT) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&coerce_to_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("COERCE-TO-STRING", "OBJECT", "(DEFUN (COERCE-TO-STRING STRING) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&coerce_to_string));
            }
            { Method_Slot* method = define_method_from_stringified_source("ASK", "OBJECT", "(DEFUN (ASK BOOLEAN) ((PROPOSITION PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Perform inference to determine whether `proposition' is true.\nReturn TRUE if `proposition' was found to be true; return NULL otherwise.\nKIF example: `(ask (happy Fred))' will return TRUE if Fred was indeed\nfound to be happy.  Note, that for this query to run, the logic constant\n`Fred' and the relation (or slot) `happy' must already be defined (see\n`assert').  Use `(set/unset-feature goal-trace)' to en/disable goal tracing\nof the inference engine.\")");

              method->function_code = ((cpp_function_code)(&ask));
              set_dynamic_slot_value(method, SYM_QUERY_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&ask_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("RETRIEVE-BINDINGS", "QUERY-ITERATOR", "(DEFMETHOD (RETRIEVE-BINDINGS QUERY-ITERATOR) ((QUERY QUERY-ITERATOR) (NOFBINDINGS INTEGER)))");

              method->method_code = ((cpp_method_code)(&Query_Iterator::retrieve_bindings));
            }
            { Method_Slot* method = define_method_from_stringified_source("RETRIEVE-BINDINGS", "CONS", "(DEFMETHOD (RETRIEVE-BINDINGS QUERY-ITERATOR) ((QUERY CONS) (NOFBINDINGS INTEGER)))");

              method->method_code = ((cpp_method_code)(&Cons::retrieve_bindings));
            }
            { Method_Slot* method = define_method_from_stringified_source("RETRIEVE", "ARGUMENT-LIST", "(DEFUN (RETRIEVE QUERY-ITERATOR) (|&REST| (QUERY PARSE-TREE)) :PUBLIC? TRUE :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Retrieve elements of a relation (tuples) that satisfy a proposition.\nThe accepted syntax is:\n	 \n  (retrieve [<integer> | all]\n            [{<variable-spec> | (<variable-spec>+)}\n             [<proposition>]])\n	\nThe variables and proposition are similar to an `exists' sentence or\n`kappa' term without the quantifier.  <proposition> usually contains\nreferences to the listed variables.  No other free variable references\nare allowed.  If <proposition> is omitted, it defaults to TRUE.  \n\nA solution is a set of bindings for the listed variables for which\n<proposition> is true.  The optional first argument controls how many\nsolutions should be generated before control is returned.  The keyword\n`all' indicates that all solutions should be generated.  By default,\n`retrieve' returns after it has found one new solution or if it cannot\nfind any more solutions.\n\n`retrieve' returns an iterator which saves all the necessary state of\na query and stores all generated solutions.  When used interactively,\nthe returned iterator will print out with the set of solutions collected\nso far.  Calling `retrieve' without any arguments (or only with the first\nargument) will generate one (or more) solutions to the most recently\nasked query.\n\nKIF examples:\n	 \n  (retrieve (?x Person) (happy ?x)) \n	\nwill try to find the next happy person and store it in the returned \nquery iterator.\n	 \n  (retrieve 10 (?x Person) (happy ?x))\n	\nwill try to find 10 happy people.\n	 \n  (retrieve 10)\n	\nwill try to find the next 10 happy people.\n	 \n  (retrieve all (?x Person) (happy ?x))\n	\nwill find all happy people.\n	 \n  (retrieve all (?x Person))\n	\nwill find all people.\n	 \n  (retrieve (?x Person) (or (happy ?x) (parent-of Fred ?x)))\n	\nwill try to find the next person that is happy or has Fred as a parent.\n	 \n  (retrieve ((?x Person) (?y Person)) (parent-of ?x ?y))\n	\nwill try to find the next pair of parent/child.\n	 \n  (retrieve all (?x Person)\n            (exists (?y Person) (parent-of ?x ?y)))\n	\nwill generate the set of all parents.  Note, that for these queries to run,\nthe class `Person', the relations `happy' and `parent-of', and the logic\nconstant `Fred' must already be defined (see `assert').\n\nUse `(set/unset-feature goal-trace)' to en/disable goal tracing of the\ninference engine.\")");

              method->function_code = ((cpp_function_code)(&retrieve));
              set_dynamic_slot_value(method, SYM_QUERY_EVALUATOR_WRAPPER_CODE, wrap_function_code(((cpp_function_code)(&retrieve_evaluator_wrapper))), NULL_FUNCTION_CODE_WRAPPER);
            }
            { Method_Slot* method = define_method_from_stringified_source("GET-SUBSUMPTION-DEFINITION", "DESCRIPTION", "(DEFUN (GET-SUBSUMPTION-DEFINITION DESCRIPTION) ((SELF DESCRIPTION) (SUBORSUPER KEYWORD)))");

              method->function_code = ((cpp_function_code)(&get_subsumption_definition));
            }
            { Method_Slot* method = define_method_from_stringified_source("DESCRIPTION-SPECIALIZES-DESCRIPTION?", "DESCRIPTION", "(DEFUN (DESCRIPTION-SPECIALIZES-DESCRIPTION? BOOLEAN) ((SUB DESCRIPTION) (SUPER DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&description_specializes_descriptionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("VECTOR-SATISFIES-DESCRIPTION?", "VECTOR", "(DEFUN (VECTOR-SATISFIES-DESCRIPTION? BOOLEAN) ((VECTOR VECTOR) (DESCRIPTION DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&vector_satisfies_descriptionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSTANCE-SATISFIES-DESCRIPTION?", "OBJECT", "(DEFUN (INSTANCE-SATISFIES-DESCRIPTION? BOOLEAN) ((INSTANCE OBJECT) (DESCRIPTION DESCRIPTION)))");

              method->function_code = ((cpp_function_code)(&instance_satisfies_descriptionP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COERCE-TO-DESCRIPTION", "OBJECT", "(DEFUN (COERCE-TO-DESCRIPTION DESCRIPTION) ((SELF OBJECT) (ORIGINAL OBJECT)))");

              method->function_code = ((cpp_function_code)(&coerce_to_description));
            }
            { Method_Slot* method = define_method_from_stringified_source("SPECIALIZES?", "OBJECT", "(DEFUN (SPECIALIZES? BOOLEAN) ((SUBOBJECT OBJECT) (SUPEROBJECT OBJECT)) :DOCUMENTATION \"Return TRUE if the description associated with `subObject'\nspecializes the description for `superObject'.  Return FALSE if we could\nnot prove that `subObject' specializes `superObject'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&specializesP));
            }
            { Method_Slot* method = define_method_from_stringified_source("COERCE-TO-INSTANCE", "OBJECT", "(DEFUN (COERCE-TO-INSTANCE LOGIC-OBJECT) ((SELF OBJECT) (ORIGINAL OBJECT)))");

              method->function_code = ((cpp_function_code)(&coerce_to_instance));
            }
            { Method_Slot* method = define_method_from_stringified_source("COERCE-TO-VECTOR", "OBJECT", "(DEFUN (COERCE-TO-VECTOR VECTOR) ((SELF OBJECT)))");

              method->function_code = ((cpp_function_code)(&coerce_to_vector));
            }
            { Method_Slot* method = define_method_from_stringified_source("SATISFIES?", "OBJECT", "(DEFUN (SATISFIES? BOOLEAN) ((INSTANCEORTUPLE OBJECT) (RELATIONREF OBJECT)) :DOCUMENTATION \"Return TRUE if `instanceOrTuple' satisfies the\ndefinition of the relation `relationRef'.  `instanceOrTuple' can be a single\nobject, the name or surrogate of an object, or a collection (a list or vector)\nof objects. `relationRef' can be a relation, description, surrogate or relation\nname.  Return FALSE if we could not prove that `instanceOrTuple' satisfies\n`relationRef'.\" :PUBLIC? TRUE)");

              method->function_code = ((cpp_function_code)(&satisfiesP));
            }
            define_method_from_stringified_source("STARTUP-QUERY", NULL, "(DEFUN STARTUP-QUERY ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *QUERYENVIRONMENT* QUERY-ENVIRONMENT NULL :DOCUMENTATION \"Points to the query environment used by the currently executing query.\")");
            { Global_Variable* global = SYM_QUERY_oQUERYENVIRONMENTo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OqueryenvironmentO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OqueryenvironmentO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEFAULT-MAXIMUM-DEPTH* INTEGER 25 :DOCUMENTATION \"Possibly a good value for the maximum backtracking depth.\nMore testing is needed.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *MAXIMUM-BACKTRACKING-DEPTH* INTEGER *DEFAULT-MAXIMUM-DEPTH* :DOCUMENTATION \"Value for the maximum depth allowable during\nbacktrack search.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *INITIAL-BACKTRACKING-DEPTH* INTEGER 5 :DOCUMENTATION \"Value of the initial depth used during an interative\ndeepening search.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *ITERATIVE-DEEPENING-MODE?* BOOLEAN FALSE :DOCUMENTATION \"Default setting.  If TRUE, queries are evaluated\nusing iterative deepening from depth '*initial-backtracking-depth*'\nto depth '*maximum-backtracking-depth*'.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *DEEP-INFERENCE-MODE?* BOOLEAN FALSE :DOCUMENTATION \"Default setting.  If TRUE, warrants use of assumption-based\nproofs.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *BOOLEAN-VECTOR-INDEX* BOOLEAN-VECTOR-INDEX-NODE (NEW BOOLEAN-VECTOR-INDEX-NODE :VECTOR (NEW BOOLEAN-VECTOR :ARRAY-SIZE 0)) :DOCUMENTATION \"Points to the head of a discrimination tree of containing\nall boolean vectors.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT *CONTROL-FRAME-STACK-QUANTUM* INTEGER 100 :DOCUMENTATION \"The size of the query frame stack is a multiple of the\nstack quantum.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT *VARIABLE-FRAME-STACK-QUANTUM* INTEGER 100 :DOCUMENTATION \"The size of the variable bindings stack is a multiple of the\nstack quantum.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT *UNBINDING-STACK-QUANTUM* INTEGER 100 :DOCUMENTATION \"The size of the old binding frame stack is a multiple of the\nstack quantum.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *TYPE-CHECK-STRATEGY* KEYWORD :SORT :DOCUMENTATION \"Determines whether there is a slow but thorough type test\nwhen variables are bound, a fast but very shallow one, or none.  Values\nare :NONE, :SORT, :DISJOINT  The default is :NONE because disjointness isn't\nyet mature.\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *REVERSEPOLARITY?* BOOLEAN FALSE :DOCUMENTATION \"Signals atomic proposition provers that polarity is negative.\")");
            { Global_Variable* global = SYM_QUERY_oREVERSEPOLARITYpo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_OreversepolarityPO));
              global->variable_set_value_code = ((cpp_function_code)(&write_OreversepolarityPO));
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *GLOBALLY-CLOSED-COLLECTIONS?* BOOLEAN FALSE :DOCUMENTATION \"If TRUE, all collections are assumed to be closed.\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT *QUERY-THREAD-LIMIT* INTEGER 8 :DOCUMENTATION \"Maximum number of simultaneous query threads.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *MAXIMUM-QUERY-THREAD-OFFSET* INTEGER (1- *QUERY-THREAD-LIMIT*))");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *FREE-QUERY-THREAD-OFFSETS* (LIST OF INTEGER-WRAPPER) (LIST) :DOCUMENTATION \"List of unused query thread offsets.\")");
            { int i = NULL_INTEGER;
              Reverse_Integer_Interval_Iterator* iter_034 = interval(0, oMAXIMUM_QUERY_THREAD_OFFSETo)->reverse();

              while (iter_034->nextP()) {
                {
                  i = iter_034->value;
                }
                oFREE_QUERY_THREAD_OFFSETSo->push(integer_wrap_literal(i));
              }
            }
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *QUERY-ENVIRONMENTS-VECTOR* (VECTOR OF QUERY-ENVIRONMENT) (NEW VECTOR :ARRAY-SIZE *QUERY-THREAD-LIMIT*) :DOCUMENTATION \"Records currently active (unreleased) query environments.\")");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *MOST-RECENT-QUERY* QUERY-ITERATOR NULL)");
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL REUSABLE-SINGLETON-VECTOR VECTOR (NEW VECTOR :ARRAY-SIZE 1) :DOCUMENTATION \"Used by 'instance-satisfies-description?'.\")");
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

