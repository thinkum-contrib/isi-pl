// optimize.hh

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
class Goal_Record;

// Function signatures:
Goal_Record* new_goal_record();
Object* access_goal_record_slot_value(Goal_Record* self, Symbol* slotname, Object* value, boolean setvalueP);
boolean variable_boundP(Pattern_Variable* variable);
boolean argument_boundP(Object* argument);
boolean unbound_variableP(Object* argument);
boolean has_disjunctionP(Proposition* goal);
boolean modal_goalP(Proposition* goal);
boolean has_inversionsP(Proposition* goal);
boolean computed_predicateP(Proposition* predicateproposition);
int simulate_create_choice_point();
boolean class_inherits_enumerated_extensionP(Class* renamed_Class);
boolean generator_collectionP(Object* collection);
void initialize_optimizer_goal_records(int size);
Goal_Record* goal_record(Pattern_Variable* variable);
boolean read_OdistributedopengoalPO();
boolean write_OdistributedopengoalPO(boolean value);
void help_distribute_goal(Object* argument, Proposition* parentgoal, boolean generatorP);
void distribute_open_goal(Proposition* goal);
int estimate_cardinality_of_class_extension(Class* renamed_Class);
int estimate_predicate_goal_cost(Proposition* goal);
int estimate_goal_cost(Proposition* goal);
Proposition* cheapest_generator_goal(Pattern_Variable* variable, int& return1);
void propagate_single_valued_constraints(Proposition* goal, List* goalsequence);
void collect_closed_goals(List* goals, List* goalsequence);
void simulate_bind_variable_and_propagate_constraints(Pattern_Variable* variable, List* goalsequence);
void bind_all_variables_in_generator_goal(Proposition* goal, List* goalsequence);
void compute_optimal_open_goal_ordering(List* optimizervariables, int numberofopengoals, List* goalsequence, int cost);
void collect_optimizer_variables(Proposition* proposition, List* collection);
void optimize_ordering_of_conjuncts(Proposition* andproposition);
void compute_backup_open_goal_ordering(List* goalsequence);
void reorder_goals(Proposition* andproposition, List* initiallyclosedgoals, List* goalsequence, List* residuegoals);
void simulate_bind_variable_to_value(Object* formula);
void warn_of_unbound_variable_argument(Proposition* proposition);
void simulate_goal_evaluation(Proposition* goal);
void simulate_and_optimize_argument(Object* formula);
void simulate_and_optimize_query(Proposition* proposition);
void initialize_optimizer_memory(int stacksize);
Control_Frame* read_OqueryoptimizercontrolframeO();
Control_Frame* write_OqueryoptimizercontrolframeO(Control_Frame* value);
void optimize_query(Description* description, Boolean_Vector* booleanvector, Control_Frame* parentframe);
Description* select_optimal_query_pattern(Description* description, Boolean_Vector* booleanvector, Control_Frame* parentframe);
boolean read_OpostoptimizationPO();
boolean write_OpostoptimizationPO(boolean value);
void simplify_description(Description* description, boolean postoptimizationP);
Vector* copy_list_to_arguments_vector(List* arguments);
boolean prior_conjunct_cancels_in_propositionP(Proposition* inconjunct, Proposition* priorconjunct);
void replace_connective_by_proposition(Proposition* connective, Proposition* proposition);
void simplify_conjunction(Proposition* andproposition);
void simplify_proposition(Proposition* proposition);
Description* copy_description(Description* self, Key_Value_List* parentmapping);
Pattern_Variable* copy_variable(Pattern_Variable* self, Key_Value_List* mapping);
Vector* copy_variables_vector(Vector* self, Key_Value_List* mapping);
Proposition* copy_proposition(Proposition* self, Key_Value_List* mapping);
Object* copy_proposition_argument(Object* self, Key_Value_List* mapping);
List* inherit_as_top_level_proposition(Proposition* proposition);
Pattern_Variable* inherit_variable(Pattern_Variable* self, Key_Value_List* mapping);
Vector* inherit_variables_vector(Vector* self, Key_Value_List* mapping);
Proposition* inherit_function_proposition(Proposition* self, Key_Value_List* mapping, boolean assertP);
Proposition* inherit_proposition(Proposition* self, Key_Value_List* mapping);
Object* inherit_proposition_argument(Object* self, Key_Value_List* mapping);
void startup_optimize();

// Global declarations:
extern Symbol* SYM_OPTIMIZE_GENERATOR_GOALS;
extern Symbol* SYM_OPTIMIZE_OTHER_GOALS;
extern Surrogate* SGT_OPTIMIZE_GOAL_RECORD;
extern Surrogate* SGT_OPTIMIZE_PATTERN_VARIABLE;
extern Surrogate* SGT_OPTIMIZE_PROPOSITION;
extern Keyword* KWD_OPTIMIZE_OR;
extern Symbol* SYM_OPTIMIZE_PERMUTATION_TABLE;
extern Surrogate* SGT_OPTIMIZE_LITERAL;
extern Surrogate* SGT_OPTIMIZE_DESCRIPTION;
extern boolean oDISTRIBUTEDOPENGOALpo;
extern Symbol* SYM_OPTIMIZE_oDISTRIBUTEDOPENGOALpo;
extern Keyword* KWD_OPTIMIZE_FUNCTION;
extern Keyword* KWD_OPTIMIZE_EQUIVALENT;
extern Keyword* KWD_OPTIMIZE_IN;
extern Keyword* KWD_OPTIMIZE_PREDICATE;
extern Keyword* KWD_OPTIMIZE_NOT;
extern Symbol* SYM_OPTIMIZE_UNIQUENESSVECTORS;
extern Symbol* SYM_OPTIMIZE_INDEXING_VECTOR;
extern Boolean_Vector* V_0_0;
extern Boolean_Vector* V_1_0;
extern Boolean_Vector* V_0_1;
extern Boolean_Vector* V_1_1;
extern List* V_1_0_AND_V_0_1;
extern List* V_1_0_SINGLETON;
extern List* V_0_1_SINGLETON;
extern Symbol* SYM_OPTIMIZE_INVERSE;
extern int ESTIMATED_SLOT_VALUE_COLLECTION_SIZE;
extern int ESTIMATED_NUMBER_OF_PREDICATE_BINDINGS;
extern Symbol* SYM_OPTIMIZE_DESCRIPTION;
extern Symbol* SYM_OPTIMIZE_ESTIMATED_CARDINALITY;
extern Surrogate* SGT_OPTIMIZE_LITERAL_WRAPPER;
extern Keyword* KWD_OPTIMIZE_OPEN;
extern Surrogate* SGT_OPTIMIZE_COLLECTION;
extern Keyword* KWD_OPTIMIZE_FORALL;
extern Keyword* KWD_OPTIMIZE_BOUND;
extern Keyword* KWD_OPTIMIZE_AND;
extern Keyword* KWD_OPTIMIZE_IMPLIES;
extern Keyword* KWD_OPTIMIZE_EXISTS;
extern Control_Frame* oQUERYOPTIMIZERCONTROLFRAMEo;
extern Symbol* SYM_OPTIMIZE_oQUERYOPTIMIZERCONTROLFRAMEo;
extern Keyword* KWD_OPTIMIZE_PATTERN;
extern boolean oPOSTOPTIMIZATIONpo;
extern Symbol* SYM_OPTIMIZE_oPOSTOPTIMIZATIONpo;
extern Symbol* SYM_OPTIMIZE_ENTITY_MAPPING;
extern Keyword* KWD_OPTIMIZE_REALISTIC;
extern Keyword* KWD_OPTIMIZE_FLAT;
extern Symbol* SYM_OPTIMIZE_SKOLEM_NAME;
extern Symbol* SYM_OPTIMIZE_VARIABLE_TYPEp;
extern Symbol* SYM_OPTIMIZE_IO_VARIABLES;
extern Surrogate* SGT_OPTIMIZE_SKOLEM;
extern Surrogate* SGT_OPTIMIZE_SURROGATE;

class Goal_Record : public Standard_Object {
public:
  List* generator_goals;
  List* other_goals;
public:
  virtual Surrogate* primary_type();
};

