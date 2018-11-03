// query.hh

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

// Class headers:
class Query_Iterator;
class Control_Frame;
class Goal_Strategy;
class Query_Environment;
class Subquery_Frame;
class Boolean_Vector_Index_Node;
class Description_Extension_Iterator;
class Goal_Cache;
class Goal_Cache_Cluster;

// Function signatures:
Query_Iterator* new_query_iterator();
Object* access_query_iterator_slot_value(Query_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Control_Frame* new_control_frame();
Object* access_control_frame_slot_value(Control_Frame* self, Symbol* slotname, Object* value, boolean setvalueP);
Goal_Strategy* new_goal_strategy();
Object* access_goal_strategy_slot_value(Goal_Strategy* self, Symbol* slotname, Object* value, boolean setvalueP);
Query_Environment* new_query_environment();
Object* access_query_environment_slot_value(Query_Environment* self, Symbol* slotname, Object* value, boolean setvalueP);
Query_Environment* read_OqueryenvironmentO();
Query_Environment* write_OqueryenvironmentO(Query_Environment* value);
boolean deep_inference_modeP();
boolean subsumption_modeP();
Subquery_Frame* new_subquery_frame();
Object* access_subquery_frame_slot_value(Subquery_Frame* self, Symbol* slotname, Object* value, boolean setvalueP);
Boolean_Vector_Index_Node* new_boolean_vector_index_node();
Object* access_boolean_vector_index_node_slot_value(Boolean_Vector_Index_Node* self, Symbol* slotname, Object* value, boolean setvalueP);
Boolean_Vector_Index_Node* create_boolean_vector_index_node(Boolean_Vector_Index_Node* parentnode, boolean lastvalue);
Boolean_Vector* arguments_vector_to_boolean_vector(Vector* argumentsvector);
Boolean_Vector* zero_one_list_to_boolean_vector(List* zeroonelist);
void initialize_query_environment(Query_Environment* environment);
void expand_control_frame_stack(Query_Environment* queryenvironment);
Control_Frame* new_top_control_frame(Query_Environment* queryenvironment);
void pop_control_frame(Query_Environment* queryenvironment);
void pop_frames_down_to(Control_Frame* frame);
void expand_variable_frame_stack(Query_Environment* queryenvironment);
int allocate_block_of_variable_frames(int variablecount, Control_Frame* frame);
void deallocate_block_of_variable_frames(Control_Frame* frame);
void reset_current_variable_frame_offset(Control_Frame* frame, Keyword* localorparent);
void expand_unbinding_stack(Query_Environment* queryenvironment);
void print_environment_stacks();
void set_pattern_variable_binding(Pattern_Variable* variable, Object* value);
void unbind_variables_beginning_at(int ubstackoffset);
void unbind_pattern_variables(Control_Frame* frame);
void create_choice_point(Control_Frame* frame);
Object* bound_to(Pattern_Variable* self);
Object* argument_bound_to(Object* self);
Object* native_argument_bound_to(Object* self);
Slot* operator_bound_to(Object* self);
boolean help_unify_attributesP(Object* value1, Object* value2);
boolean fails_type_checkP(Pattern_Variable* v1, Object* i2);
boolean help_bind_variable_to_valueP(Pattern_Variable* variable, Object* value);
boolean bind_variable_to_valueP(Pattern_Variable* variable, Object* value, boolean autocleanupP);
boolean bind_argument_to_valueP(Object* argument, Object* value, boolean autocleanupP);
boolean bind_vector_of_arguments_to_valuesP(Vector* arguments, Cons* values);
void pcs();
Pattern_Variable* variable_from_unbinding_offset(Description* description, int uboffset);
int compute_frame_offset(Control_Frame* frame);
void print_one_variable_binding(Pattern_Variable* variable);
void print_variable_bindings(Control_Frame* frame);
void trace_goal_tree(Control_Frame* frame, int depth, Keyword* lastmove);
Keyword* interpret_and_scores(Control_Frame* frame, Keyword* lastmove);
Keyword* interpret_or_scores(Control_Frame* frame, Keyword* lastmove);
Keyword* interpret_fail_score(Control_Frame* frame, Keyword* lastmove);
Keyword* interpret_subgoals_scores(Control_Frame* frame, Keyword* lastmove);
Control_Frame* create_down_frame(Control_Frame* upframe, Proposition* downproposition);
boolean execute_backward_chaining_proofP(Query_Environment* queryenvironment);
Keyword* select_next_proof_strategy(Control_Frame* frame, Keyword* lastmove);
boolean read_OreversepolarityPO();
boolean write_OreversepolarityPO(boolean value);
Keyword* continue_atomic_proposition_proof(Control_Frame* frame, Keyword* lastmove);
boolean all_arguments_boundP(Proposition* goal);
Object* find_specializing_function_proposition_value(Proposition* self);
Object* query_for_asserted_function_proposition_value(Proposition* self);
Keyword* manufacture_defining_skolem(Slot* slot, Proposition* goalproposition);
Keyword* continue_function_proposition_proof(Proposition* self, Control_Frame* frame);
Keyword* continue_predicate_proposition_proof(Proposition* self, Control_Frame* frame);
Keyword* continue_equivalent_proposition_proof(Proposition* self, Control_Frame* frame);
Keyword* continue_in_proposition_proof(Proposition* self, Control_Frame* frame);
boolean inferrable_descriptionP(Object* self);
boolean unnamed_descriptionP(Object* self);
Keyword* continue_implies_proposition_proof(Proposition* self, Control_Frame* frame, Keyword* lastmove);
Keyword* spawn_contained_by_subquery(Control_Frame* upframe, Object* tail, Object* head);
Proposition* create_contained_by_argument(Object* collection, List* bridgeargs, boolean lastcallP);
Keyword* continue_constant_proposition_proof(Proposition* self, Control_Frame* frame);
Keyword* overlay_with_pattern_frame(Control_Frame* frame, Description* description);
boolean transfer_pattern_query_bindingsP(Control_Frame* frame, boolean futurebindingsP);
Iterator* allocate_antecedents_iterator(Subquery_Frame* subqueryframe, boolean reversepolarityP);
Keyword* continue_subgoals_proof(Control_Frame* frame);
Subquery_Frame* new_top_subquery_frame();
Subquery_Frame* allocate_subquery_frame(Description* description, Vector* externalarguments);
boolean terminate_subquery_frameP(Subquery_Frame* self);
Vector* copy_subquery_arguments(Vector* arguments, boolean omitlastargumentP, Description* description);
Keyword* overlay_with_subgoals_frame(Control_Frame* frame, Description* description, Vector* externalarguments, boolean omitlastargumentP, Keyword* phasesfilter);
Keyword* spawn_subquery(Control_Frame* upframe, Description* description, Keyword* phasesfilter, boolean overlayP);
Keyword* continue_disjunction_proof(Control_Frame* frame, Keyword* lastmove);
boolean disjoint_classesP(Class* class1, Class* class2);
boolean root_type_implies_memberP(Object* self, Object* member);
Keyword* collection_has_member(Object* self, Object* member);
boolean closed_collectionP(Object* self);
Iterator* collection_members(Object* self, Keyword* openorclosed);
Keyword* collection_contained_in_collection(Object* subcollection, Object* supercollection);
boolean collection_implies_collectionP(Object* subcollection, Object* supercollection);
Description_Extension_Iterator* new_description_extension_iterator();
Object* access_description_extension_iterator_slot_value(Description_Extension_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
void reserve_query_thread(Query_Environment* queryenvironment);
void release_query_thread(Query_Environment* queryenvironment);
List* release_all_query_threads();
List* clear_query_threads();
Goal_Cache* new_goal_cache();
Object* access_goal_cache_slot_value(Goal_Cache* self, Symbol* slotname, Object* value, boolean setvalueP);
List* get_cached_bindings(Goal_Cache* goalcache, Control_Frame* frame);
void print_goal_cache(Goal_Cache* self);
Goal_Cache_Cluster* new_goal_cache_cluster();
Object* access_goal_cache_cluster_slot_value(Goal_Cache_Cluster* self, Symbol* slotname, Object* value, boolean setvalueP);
Control_Frame* help_find_duplicated_goal(Control_Frame* goalframe, Control_Frame*& return1, int& return2);
Control_Frame* find_duplicated_goal(Control_Frame*& return1, int& return2);
Cons* yield_goal_bindings(Control_Frame* frame);
Goal_Cache* lookup_goal_cache(Goal_Cache_Cluster* cluster, Control_Frame* frame);
Goal_Cache_Cluster* find_goal_cache_cluster(Proposition* goal);
Goal_Cache* find_goal_cache(Control_Frame* frame);
Goal_Cache_Cluster* create_goal_cache_cluster(Proposition* goal);
boolean create_goal_cacheP(Control_Frame* frame);
Control_Frame* handle_depth_violation(Control_Frame* frame, int depth, int& return1);
Keyword* access_goal_cache(Control_Frame* frame);
void update_goal_cache(Control_Frame* frame, boolean successP);
Keyword* overlay_with_cached_bindings(Control_Frame* frame, Goal_Cache* goalcache);
Keyword* scan_cached_bindings(Control_Frame* frame);
void print_control_frame(Control_Frame* self, ostream* stream);
void print_goal_stack();
void pgs();
void print_query_iterator(Query_Iterator* self, ostream* stream);
Query_Iterator* allocate_query_iterator();
void free_query_iterator(Query_Iterator* self);
Query_Iterator* create_query_iterator(Description* description, Vector* outsidearguments);
void bootstrap_initialize_subquery_frame(Subquery_Frame* subqueryframe, Description* description, Vector* externalarguments, Vector* outsidearguments);
Cons* copy_vector_to_cons_list(Vector* vector);
Cons* standardize_query_tree(Object* querytree, boolean truefalseP);
Cons* consDstandardize_query_tree(Cons* querytree, boolean truefalseP);
void handle_query_exception(Exception* exception, char* command);
Query_Iterator* make_query(Object* querytree, boolean yesnoP);
boolean run_yes_or_no_queryP(Query_Iterator* queryiterator);
Object* coerce_to_tree(Object* self);
char* coerce_to_string(Object* self);
boolean ask(Object* proposition);
Boolean_Wrapper* ask_evaluator_wrapper(Cons* arguments);
Query_Iterator* retrieve(Cons* query);
Query_Iterator* retrieve_evaluator_wrapper(Cons* arguments);
Description* get_subsumption_definition(Description* self, Keyword* suborsuper);
boolean description_specializes_descriptionP(Description* sub, Description* super);
boolean vector_satisfies_descriptionP(Vector* vector, Description* description);
boolean instance_satisfies_descriptionP(Object* instance, Description* description);
Description* coerce_to_description(Object* self, Object* original);
boolean specializesP(Object* subobject, Object* superobject);
Logic_Object* coerce_to_instance(Object* self, Object* original);
Vector* coerce_to_vector(Object* self);
boolean satisfiesP(Object* instanceortuple, Object* relationref);
void startup_query();

// Global declarations:
extern Symbol* SYM_QUERY_QUERY_ENVIRONMENT;
extern Symbol* SYM_QUERY_EXTERNAL_VARIABLES;
extern Symbol* SYM_QUERY_SOLUTIONS;
extern Symbol* SYM_QUERY_EXHAUSTEDp;
extern Surrogate* SGT_QUERY_QUERY_ITERATOR;
extern Symbol* SYM_QUERY_STATE;
extern Symbol* SYM_QUERY_PHASE;
extern Symbol* SYM_QUERY_PROPOSITION;
extern Symbol* SYM_QUERY_REVERSE_POLARITYp;
extern Symbol* SYM_QUERY_UP;
extern Symbol* SYM_QUERY_DOWN;
extern Symbol* SYM_QUERY_BACK;
extern Symbol* SYM_QUERY_ARGUMENT_CURSOR;
extern Symbol* SYM_QUERY_ITERATOR;
extern Symbol* SYM_QUERY_SUBQUERY_FRAME;
extern Symbol* SYM_QUERY_PARENT_PATTERN_FRAME;
extern Symbol* SYM_QUERY_GOAL_CACHE;
extern Symbol* SYM_QUERY_PARTIAL_MATCH_FRAME;
extern Symbol* SYM_QUERY_DEBUG_FRAME_OFFSET;
extern Symbol* SYM_QUERY_DEBUG_DEPTH;
extern Symbol* SYM_QUERY_CHOICE_POINT_UNBINDING_OFFSET;
extern Surrogate* SGT_QUERY_CONTROL_FRAME;
extern Symbol* SYM_QUERY_KIND_OF_GOAL;
extern Symbol* SYM_QUERY_STRATEGY_PRIORITY;
extern Symbol* SYM_QUERY_STRATEGY_PROCEDURE;
extern Surrogate* SGT_QUERY_GOAL_STRATEGY;
extern List* oRECYCLED_QUERY_ENVIRONMENT_So;
extern Symbol* SYM_QUERY_CONTROL_FRAME_STACK;
extern Symbol* SYM_QUERY_CONTROL_FRAME_OFFSET_LIMIT;
extern Symbol* SYM_QUERY_TOP_CONTROL_FRAME_OFFSET;
extern Symbol* SYM_QUERY_VARIABLE_FRAME_STACK;
extern Symbol* SYM_QUERY_VARIABLE_FRAME_OFFSET_LIMIT;
extern Symbol* SYM_QUERY_TOP_VARIABLE_FRAME_OFFSET;
extern Symbol* SYM_QUERY_UNBINDING_STACK;
extern Symbol* SYM_QUERY_UNBINDING_STACK_OFFSET_LIMIT;
extern Symbol* SYM_QUERY_TOP_UNBINDING_STACK_OFFSET;
extern Symbol* SYM_QUERY_CURRENT_VARIABLE_FRAME_OFFSET;
extern Symbol* SYM_QUERY_CURRENT_SUBQUERY_FRAME;
extern Symbol* SYM_QUERY_PARTIAL_MATCH_STRATEGY;
extern Symbol* SYM_QUERY_LATEST_POSITIVE_SCORE;
extern Symbol* SYM_QUERY_ITERATIVE_DEEPENINGp;
extern Symbol* SYM_QUERY_CURRENT_DEPTH_CUTOFF;
extern Symbol* SYM_QUERY_MAXIMUM_DEPTH;
extern Symbol* SYM_QUERY_AUGMENTED_GOAL_CACHEp;
extern Symbol* SYM_QUERY_ACTIVE_GOAL_CACHES;
extern Symbol* SYM_QUERY_TRIGGERED_DEPTH_CUTOFFp;
extern Symbol* SYM_QUERY_FAILED_TO_FIND_DUPLICATE_SUBGOALp;
extern Symbol* SYM_QUERY_FOUND_AT_LEAST_ONE_SOLUTIONp;
extern Symbol* SYM_QUERY_DEEP_INFERENCEp;
extern Symbol* SYM_QUERY_QUERY_THREAD_OFFSET;
extern Symbol* SYM_QUERY_TIME_STAMP;
extern Symbol* SYM_QUERY_QUERY_ITERATOR;
extern Symbol* SYM_QUERY_SUBSUMPTION_QUERYp;
extern Symbol* SYM_QUERY_SPECIALIZING_DESCRIPTION;
extern Symbol* SYM_QUERY_OPTIMIZER_GOAL_RECORDS;
extern Symbol* SYM_QUERY_RESIDUE_GOALS;
extern Symbol* SYM_QUERY_BEST_GOAL_SEQUENCE;
extern Symbol* SYM_QUERY_BEST_COST;
extern Surrogate* SGT_QUERY_QUERY_ENVIRONMENT;
extern Query_Environment* oQUERYENVIRONMENTo;
extern Symbol* SYM_QUERY_oQUERYENVIRONMENTo;
extern int oDEFAULT_MAXIMUM_DEPTHo;
extern int oMAXIMUM_BACKTRACKING_DEPTHo;
extern int oINITIAL_BACKTRACKING_DEPTHo;
extern boolean oITERATIVE_DEEPENING_MODEpo;
extern boolean oDEEP_INFERENCE_MODEpo;
extern Subquery_Frame* oRECYCLED_SUBQUERY_FRAME_So;
extern Symbol* SYM_QUERY_CONTROL_FRAME;
extern Symbol* SYM_QUERY_DESCRIPTION;
extern Symbol* SYM_QUERY_EXTERNAL_ARGUMENTS;
extern Symbol* SYM_QUERY_BOOLEAN_VECTOR;
extern Symbol* SYM_QUERY_LOCAL_VARIABLE_FRAME_OFFSET;
extern Symbol* SYM_QUERY_OPTIMAL_PATTERN;
extern Symbol* SYM_QUERY_PHASES_FILTER;
extern Surrogate* SGT_QUERY_SUBQUERY_FRAME;
extern Symbol* SYM_QUERY_TRUE_LINK;
extern Symbol* SYM_QUERY_FALSE_LINK;
extern Symbol* SYM_QUERY_VECTOR;
extern Surrogate* SGT_QUERY_BOOLEAN_VECTOR_INDEX_NODE;
extern Boolean_Vector_Index_Node* oBOOLEAN_VECTOR_INDEXo;
extern Surrogate* SGT_QUERY_PATTERN_VARIABLE;
extern int oCONTROL_FRAME_STACK_QUANTUMo;
extern int oVARIABLE_FRAME_STACK_QUANTUMo;
extern int oUNBINDING_STACK_QUANTUMo;
extern Keyword* KWD_QUERY_QUERY_STACKS;
extern Keyword* KWD_QUERY_PATTERN;
extern Keyword* KWD_QUERY_CONTAINED_BY;
extern Keyword* KWD_QUERY_POPPED;
extern Keyword* KWD_QUERY_LOCAL;
extern Keyword* KWD_QUERY_PARENT;
extern Surrogate* SGT_QUERY_LOGIC_OBJECT;
extern Keyword* oTYPE_CHECK_STRATEGYo;
extern Keyword* KWD_QUERY_SORT;
extern Keyword* KWD_QUERY_NONE;
extern Keyword* KWD_QUERY_IN;
extern Surrogate* SGT_QUERY_SURROGATE;
extern Keyword* KWD_QUERY_SHALLOW_DISJOINT;
extern Keyword* KWD_QUERY_DISJOINT;
extern Symbol* SYM_QUERY_SKOLEM_NAME;
extern Surrogate* SGT_QUERY_LIST;
extern Keyword* KWD_QUERY_DOWN;
extern Keyword* KWD_QUERY_ITERATIVE_FORALL;
extern Keyword* KWD_QUERY_STATE_MACHINE;
extern Keyword* KWD_QUERY_SUBGOALS;
extern Keyword* KWD_QUERY_TERMINATION;
extern Keyword* KWD_QUERY_ANTECEDENTS;
extern Keyword* KWD_QUERY_REALISTIC;
extern Keyword* KWD_QUERY_COMPLEMENT;
extern Keyword* KWD_QUERY_UP_TRUE;
extern Keyword* KWD_QUERY_UP_FAIL;
extern Keyword* KWD_QUERY_AND;
extern Keyword* KWD_QUERY_OR;
extern Keyword* KWD_QUERY_NOT;
extern Keyword* KWD_QUERY_INITIAL;
extern Keyword* KWD_QUERY_GOAL_TREE;
extern Keyword* KWD_QUERY_SELECT_STRATEGY;
extern Keyword* KWD_QUERY_HEAVY_DUTY_DISJUNCTION;
extern Keyword* KWD_QUERY_FUNCTION;
extern Keyword* KWD_QUERY_PREDICATE;
extern Keyword* KWD_QUERY_EQUIVALENT;
extern Keyword* KWD_QUERY_IMPLIES;
extern Keyword* KWD_QUERY_CONSTANT;
extern Keyword* KWD_QUERY_CONTINUING_SUCCESS;
extern Keyword* KWD_QUERY_FINAL_SUCCESS;
extern Keyword* KWD_QUERY_FAILURE;
extern Keyword* KWD_QUERY_OVERLAY;
extern Keyword* KWD_QUERY_SPAWNED_SUBQUERY;
extern Keyword* KWD_QUERY_SUCCESS;
extern Keyword* KWD_QUERY_FAILED_OVERLAY;
extern Keyword* KWD_QUERY_SUBGOAL;
extern Keyword* KWD_QUERY_EXISTS;
extern Keyword* KWD_QUERY_FORALL;
extern Symbol* SYM_QUERY_IO_VARIABLES;
extern Keyword* KWD_QUERY_CACHED_BINDINGS;
extern Keyword* KWD_QUERY_FAIL;
extern Keyword* KWD_QUERY_END_SUBUMPTION_TEST;
extern boolean oREVERSEPOLARITYpo;
extern Symbol* SYM_QUERY_oREVERSEPOLARITYpo;
extern Surrogate* SGT_QUERY_PROPOSITION;
extern Keyword* KWD_QUERY_ALL_SUBGOAL_PHASES;
extern Keyword* KWD_QUERY_SUBGOALS_OVERLAY;
extern Keyword* KWD_QUERY_OPEN;
extern Keyword* KWD_QUERY_SCAN_COLLECTION;
extern Surrogate* SGT_QUERY_DESCRIPTION;
extern Symbol* SYM_QUERY_COMPLEMENT_DESCRIPTION;
extern Keyword* KWD_QUERY_SCAN_SUBCOLLECTIONS;
extern Keyword* KWD_QUERY_SCAN_SUPERCOLLECTIONS;
extern Keyword* KWD_QUERY_DO_CONTAINED_BY;
extern Keyword* KWD_QUERY_SUBSUMPTION_OVERLAY;
extern Symbol* SYM_QUERY_CONTAINED_BY;
extern Symbol* SYM_QUERY_IN;
extern Keyword* KWD_QUERY_SKIP_DEFINITION;
extern Keyword* KWD_QUERY_PRE_ANTECEDENTS;
extern Keyword* KWD_QUERY_DEFINITION;
extern Keyword* KWD_QUERY_FULL_SUBQUERY;
extern Symbol* SYM_QUERY_DEFINITION;
extern Symbol* SYM_QUERY_MONOTONICp;
extern Symbol* SYM_QUERY_NON_DISJOINTNESS_KLUDGEp;
extern Surrogate* SGT_QUERY_COLLECTION;
extern boolean oGLOBALLY_CLOSED_COLLECTIONSpo;
extern Surrogate* SGT_QUERY_COLLECTIONdCLOSED;
extern Keyword* KWD_QUERY_CLOSED;
extern Keyword* KWD_QUERY_PRIMITIVE;
extern Keyword* KWD_QUERY_ENUMERATION;
extern Symbol* SYM_QUERY_CURSOR;
extern Symbol* SYM_QUERY_ROOT_TYPE;
extern Symbol* SYM_QUERY_FILTER_TYPE;
extern Symbol* SYM_QUERY_NATIVE_CLASS_EXTENSION_ITERATOR;
extern Surrogate* SGT_QUERY_DESCRIPTION_EXTENSION_ITERATOR;
extern int oQUERY_THREAD_LIMITo;
extern int oMAXIMUM_QUERY_THREAD_OFFSETo;
extern List* oFREE_QUERY_THREAD_OFFSETSo;
extern Vector* oQUERY_ENVIRONMENTS_VECTORo;
extern Symbol* SYM_QUERY_GOAL_BINDINGS;
extern Symbol* SYM_QUERY_CACHED_BINDINGS;
extern Symbol* SYM_QUERY_REVERSE_POLARITY_CACHED_BINDINGS;
extern Symbol* SYM_QUERY_UP_FOR_GRABSp;
extern Symbol* SYM_QUERY_CLUSTER;
extern Surrogate* SGT_QUERY_GOAL_CACHE;
extern Symbol* SYM_QUERY_VECTOR_OF_GOAL_CACHE_TABLES;
extern Surrogate* SGT_QUERY_GOAL_CACHE_CLUSTER;
extern Keyword* KWD_QUERY_GOAL_CACHES;
extern Symbol* SYM_QUERY_GOAL_CACHE_CLUSTER;
extern Keyword* KWD_QUERY_EXECUTE_QUERY;
extern Keyword* KWD_QUERY_QUERY;
extern Symbol* SYM_QUERY_AND;
extern Symbol* SYM_QUERY_KAPPA;
extern Symbol* SYM_QUERY_COMMA;
extern Symbol* SYM_QUERY_WHERE;
extern Symbol* SYM_QUERY_EXISTS;
extern Keyword* KWD_QUERY_KIF;
extern Symbol* SYM_QUERY_TRUE;
extern Keyword* KWD_QUERY_STELLA;
extern Keyword* KWD_QUERY_PREFIX_STELLA;
extern Surrogate* SGT_QUERY_LOGIC_EXCEPTION;
extern Keyword* KWD_QUERY_EXCEPTIONS;
extern Surrogate* SGT_QUERY_EXCEPTION;
extern Symbol* SYM_QUERY_EVALUATOR_WRAPPER_CODE;
extern Query_Iterator* oMOST_RECENT_QUERYo;
extern Keyword* KWD_QUERY_SUB;
extern Keyword* KWD_QUERY_SUPER;
extern Vector* REUSABLE_SINGLETON_VECTOR;
extern Surrogate* SGT_QUERY_RELATION;
extern Surrogate* SGT_QUERY_VECTOR;

class Query_Iterator : public Iterator {
public:
  Query_Environment* query_environment;
  Vector* external_variables;
  List* solutions;
  boolean exhaustedP;
public:
  virtual List* listify();
public:
  virtual void print_object(ostream* stream);
  virtual Surrogate* primary_type();
  virtual Query_Iterator* retrieve_bindings(int nofbindings);
  virtual void reset();
  virtual boolean nextP();
  virtual void free();
};

class Control_Frame : public Standard_Object {
public:
  Keyword* state;
  Keyword* phase;
  Proposition* proposition;
  boolean reverse_polarityP;
  Control_Frame* up;
  Control_Frame* down;
  Control_Frame* back;
  int argument_cursor;
  Iterator* iterator;
  Control_Frame* parent_pattern_frame;
  Goal_Cache* goal_cache;
  Partial_Match_Frame* partial_match_frame;
  int debug_frame_offset;
  int debug_depth;
  int choice_point_unbinding_offset;
public:
  virtual void print_object(ostream* stream);
  virtual Surrogate* primary_type();
};

class Goal_Strategy : public Standard_Object {
public:
  Keyword* kind_of_goal;
  int strategy_priority;
  cpp_function_code strategy_procedure;
public:
  virtual Surrogate* primary_type();
};

class Query_Environment : public Standard_Object {
public:
  Vector* control_frame_stack;
  int control_frame_offset_limit;
  int top_control_frame_offset;
  Vector* variable_frame_stack;
  int variable_frame_offset_limit;
  int top_variable_frame_offset;
  Integer_Vector* unbinding_stack;
  int unbinding_stack_offset_limit;
  int top_unbinding_stack_offset;
  int current_variable_frame_offset;
  Subquery_Frame* current_subquery_frame;
  Partial_Match_Frame* partial_match_strategy;
  double latest_positive_score;
  boolean iterative_deepeningP;
  int current_depth_cutoff;
  int maximum_depth;
  boolean augmented_goal_cacheP;
  List* active_goal_caches;
  boolean triggered_depth_cutoffP;
  boolean failed_to_find_duplicate_subgoalP;
  boolean found_at_least_one_solutionP;
  boolean deep_inferenceP;
  int query_thread_offset;
  int time_stamp;
  Query_Iterator* query_iterator;
  boolean subsumption_queryP;
  Description* specializing_description;
  Extensible_Vector* optimizer_goal_records;
  List* residue_goals;
  List* best_goal_sequence;
  int best_cost;
public:
  virtual void free();
  virtual Surrogate* primary_type();
};

class Subquery_Frame : public Iterator {
public:
  Control_Frame* control_frame;
  Description* description;
  Vector* external_arguments;
  Boolean_Vector* boolean_vector;
  int local_variable_frame_offset;
  Description* optimal_pattern;
  Keyword* phases_filter;
  Iterator* iterator;
public:
  virtual void free();
  virtual Surrogate* primary_type();
};

class Boolean_Vector_Index_Node : public Standard_Object {
public:
  Boolean_Vector_Index_Node* true_link;
  Boolean_Vector_Index_Node* false_link;
  Boolean_Vector* vector;
public:
  virtual Surrogate* primary_type();
};

class Description_Extension_Iterator : public Iterator {
public:
  Cons* cursor;
  Surrogate* root_type;
  Surrogate* filter_type;
  Iterator* native_class_extension_iterator;
public:
  virtual Surrogate* primary_type();
  virtual boolean nextP();
};

class Goal_Cache : public Standard_Object {
public:
  List* cached_bindings;
  List* reverse_polarity_cached_bindings;
  boolean up_for_grabsP;
  Goal_Cache_Cluster* cluster;
public:
  virtual Surrogate* primary_type();
};

class Goal_Cache_Cluster : public Standard_Object {
public:
  Vector* vector_of_goal_cache_tables;
  int time_stamp;
  Proposition* proposition;
public:
  virtual Surrogate* primary_type();
};

