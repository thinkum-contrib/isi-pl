// propositions.hh

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
class Logic_Object;
class Skolem;
class Pattern_Variable;
class Description;
class Truth_Value;
class Proposition;

// Function signatures:
Logic_Object* new_logic_object();
Object* access_logic_object_slot_value(Logic_Object* self, Symbol* slotname, Object* value, boolean setvalueP);
Skolem* new_skolem();
Object* access_skolem_slot_value(Skolem* self, Symbol* slotname, Object* value, boolean setvalueP);
Pattern_Variable* new_pattern_variable();
Object* access_pattern_variable_slot_value(Pattern_Variable* self, Symbol* slotname, Object* value, boolean setvalueP);
Description* new_description();
Object* access_description_slot_value(Description* self, Symbol* slotname, Object* value, boolean setvalueP);
Truth_Value* new_truth_value();
Object* access_truth_value_slot_value(Truth_Value* self, Symbol* slotname, Object* value, boolean setvalueP);
Proposition* new_proposition();
Object* access_proposition_slot_value(Proposition* self, Symbol* slotname, Object* value, boolean setvalueP);
Proposition* create_proposition(Symbol* kind, int argumentcount);
void increment_now_time_stamp();
int get_now_time_stamp();
void update_now_time_stamp(Keyword* kbaction);
boolean bottomP(Object* self);
boolean logic_slotP(Slot* slot);
boolean type_has_backlinksP(Surrogate* type);
boolean no_backlinksP(Object* self);
boolean logic_object_permits_backlinksP(Logic_Object* object);
Keyword* read_OevaluationmodeO();
Keyword* write_OevaluationmodeO(Keyword* value);
boolean description_modeP();
boolean conceiving_updateP(Keyword* updatemode);
boolean descriptive_updateP(Keyword* updatemode);
boolean propagate_constraints_incrementallyP(World* self);
boolean context_dependent_search_modeP();
void log_newly_conceived_proposition(Module* self, Proposition* proposition);
void run_goes_true_demons(Proposition* proposition);
void run_goes_false_demons(Proposition* proposition);
void run_goes_unknown_demons(Proposition* proposition);
void react_to_proposition_update(Proposition* proposition, Keyword* updatemode);
void assign_truth_value(Proposition* self, boolean valueP);
void deassign_truth_value(Proposition* self, Keyword* updatemode);
void update_proposition_truth_value(Proposition* self, Keyword* updatemode);
void run_slot_inference_demons(Object* self, Storage_Slot* slot, Object* oldvalue, Object* newvalue);
void react_to_attribute_proposition_update(Skolem* skolem, Object* oldvalue, Object* newvalue, boolean toplevelupdateP);
boolean primitive_slotP(Slot* slot);
boolean attribute_propositionP(Proposition* proposition);
void add_dependent_proposition_link(Object* self, Proposition* proposition);
void remove_dependent_proposition_link(Object* self, Proposition* proposition);
boolean slotref_less_or_equalP(Surrogate* slot1, Surrogate* slot2);
boolean slotref_less_thanP(Surrogate* slot1, Surrogate* slot2);
void insert_sorted_by_slotref(List* self, Proposition* proposition);
void add_dependent_attribute_link(Logic_Object* object, Proposition* proposition);
void remove_dependent_attribute_link(Logic_Object* object, Proposition* proposition);
void signal_undefined_slot_value_failure(Object* object, Surrogate* slotref);
void assign_attribute_value(Standard_Object* self, Storage_Slot* slot, Object* value);
void clear_attribute_value(Standard_Object* object, Storage_Slot* slot);
void drop_attribute_value(Standard_Object* self, Storage_Slot* slot, Object* value);
Surrogate* lookup_slotref_on_instance(Object* term, Symbol* slotname);
boolean unboundP(Skolem* skolem);
boolean skolemP(Object* self);
boolean variableP(Object* self);
boolean native_valueP(Object* self);
Object* native_value_of(Object* self);
Logic_Object* equivalent_of(Logic_Object* self);
Pattern_Variable* innermost_variable_of(Pattern_Variable* self);
Object* innermost_of(Object* self);
Object* compute_function_value(Proposition* self);
Object* last_argument(Proposition* proposition);
Object* function_value(Proposition* self);
Object* function_representative(Proposition* self);
boolean compute_predicate_value(Proposition* self, boolean& return1);
Symbol* yield_anonymous_skolem_name(boolean variableP);
Cons* read_OfreeskolemsO();
Cons* write_OfreeskolemsO(Cons* value);
Skolem* help_create_skolem(Skolem* self, Surrogate* type, Symbol* name, boolean assertinP);
Skolem* create_skolem(Surrogate* type, Symbol* name);
Pattern_Variable* create_variable(Surrogate* type, Symbol* name, boolean assertinP);
boolean trueP(Proposition* self);
boolean falseP(Proposition* self);
boolean unknownP(Proposition* self);
void signal_unification_clash(Object* term1, Object* term2);
void signal_variable_value_clash(Skolem* skolem, Object* value1, Object* value2);
void signal_truth_value_clash(Proposition* proposition);
void signal_fail();
Surrogate* logical_type(Object* self);
void unify_types(Skolem* term1, Object* term2);
void scan_for_attributes_clash(List* attributes1, List* attributes2);
void unify_attribute_propositions(List* attributes1, List* attributes2);
void unify_skolem_and_value(Skolem* skolem, Object* value);
void bind_skolem_to_value(Skolem* fromskolem, Object* tovalue, boolean toplevelupdateP);
void unbind_skolem_value(Skolem* skolem, boolean toplevelupdateP);
void constrain_as_subset(Sequence* set1, Sequence* set2);
void equate_collections(Collection* col1, Collection* col2);
void equate_values(Object* term1, Object* term2);
boolean unequate_valuesP(Object* term1, Object* term2);
boolean description_equals_descriptionP(Object* arg1, Object* arg2);
boolean argument_equals_argumentP(Object* arg1, Object* arg2);
boolean proposition_eqlP(Proposition* self, Proposition* other);
boolean commutative_proposition_eqlP(Proposition* self, Proposition* other);
List* find_dependents_of_some_argument(Proposition* self);
Proposition* find_duplicate_proposition(Proposition* self);
void evaluate_and_proposition(Proposition* self);
void evaluate_or_proposition(Proposition* self);
void evaluate_not_proposition(Proposition* self);
void evaluate_equivalent_proposition(Proposition* self);
void evaluate_function_proposition(Proposition* self);
void evaluate_predicate_proposition(Proposition* self);
void evaluate_proposition(Proposition* self);
Object* evaluate_term(Object* self);
Object* evaluate_wrapped_literal_term(Literal_Wrapper* self);
Object* evaluate_surrogate_term(Surrogate* self);
boolean anonymous_variableP(Skolem* self);
Object* evaluate_symbol_term(Symbol* self);
void signal_undefined_term(Object* term);
Object* evaluate_setof_term(Cons* term);
Logic_Object* evaluate_create_term(Cons* term);
Logic_Object* create(Generalized_Symbol* type, Cons* name);
Logic_Object* create_evaluator_wrapper(Cons* arguments);
Class* leftmost_concrete_superclass(Class* self);
boolean has_multiple_root_classesP(Class* self);
void help_collect_root_classes(Class* self, List* allclasseslist, List* beenthere);
Iterator* all_root_classes(Class* self);
List* get_description_extension(Class* rootclass);
boolean indexed_by_logical_extensionsP(Logic_Object* self);
void help_update_root_types(Logic_Object* self, Surrogate* newroottype);
void update_root_types(Logic_Object* self, Surrogate* type);
void transfer_logic_information_from_relation_hook(List* relationslist);
void retract_relation_axioms(Relation* oldrelation);
Proposition* assert_description_implies_description(Description* sub, Description* super);
Proposition* assert_implies_link_between_relations(Relation* sub, Relation* super);
void finalize_superrelation_links(Relation* self);
Surrogate* verify_logical_and_native_types(Surrogate* logicaltype, Surrogate* nativetype);
Proposition* update_isa_proposition(Logic_Object* self, Surrogate* type, Keyword* updatemode);
Proposition* assert_isa_proposition(Logic_Object* self, Surrogate* type);
void update_property(Logic_Object* instance, Symbol* property, Keyword* updatemode);
void assert_property(Logic_Object* instance, Symbol* property);
Logic_Object* create_logic_object(Surrogate* type, Surrogate* name, Object* nativevalue);
Object* read_OpropositionunderconstructionO();
Object* write_OpropositionunderconstructionO(Object* value);
Cons* read_OtoplevelpropositionsO();
Cons* write_OtoplevelpropositionsO(Cons* value);
Proposition* build_top_level_proposition(Object* tree, Keyword* updatemode);
Proposition* fasten_down_proposition(Proposition* self);
Proposition* build_proposition(Object* tree, Keyword* updatemode);
Proposition* surrogateDbuild_proposition(Surrogate* self, Keyword* updatemode);
Proposition* symbolDbuild_proposition(Symbol* symbol, Keyword* updatemode);
Proposition* consDbuild_proposition(Cons* tree, Keyword* updatemode);
void verify_collection_argument(Object* self, Object* original);
void verify_relation_argument(Object* self);
void verify_number_of_proposition_arguments(Cons* tree, int correctnumber);
Proposition* build_in_proposition(Cons* tree, Keyword* updatemode);
Proposition* embed_negation_within_function_induced_exists(Proposition* existsproposition);
Proposition* build_and_or_not_proposition(Cons* tree, Keyword* updatemode);
boolean functional_termP(Object* term);
boolean clip_valueP(Object* term1, Object* term2);
Proposition* finish_building_equivalence_proposition(Object* term1, Object* term2);
Proposition* substitute_function_for_equivalence(Pattern_Variable* functionvariable, Object* term);
Proposition* build_equivalence_proposition(Cons* tree, Keyword* updatemode);
Proposition* build_conjunction_of_equality_propositions(Cons* tree, Keyword* updatemode);
Skolem* verify_second_order_variable(Skolem* variable, Keyword* kind);
Proposition* build_predicate_proposition(Cons* tree);
Proposition* build_exists_proposition(Cons* tree, Keyword* updatemode);
boolean top_level_exists_propositionP(Proposition* proposition);
Vector* collect_skolemized_exists_variables(Proposition* proposition);
boolean help_collect_skolemized_exists_variablesP(Proposition* proposition, List* result);
Proposition* build_forall_proposition(Cons* tree, Keyword* updatemode);
void verify_implies_argument(Object* self, Symbol* renamed_Operator);
Proposition* build_implies_proposition(Cons* tree, Keyword* updatemode);
Proposition* find_duplicate_function_proposition(Surrogate* slotref, Cons* arguments);
Proposition* create_function_proposition(Surrogate* slotref, Cons* inputarguments);
Proposition* create_second_order_function_proposition(Object* variablefunction, Cons* inputarguments);
Object* finish_evaluating_function_term(Surrogate* slotref, Cons* inputarguments);
Object* evaluate_function_term(Cons* tree);
boolean function_output_variableP(Object* self);
boolean function_output_skolemP(Object* self);
Object* remove_true_and_false(Cons* tree, boolean& return1);
Object* flatten_nested_operators(Cons* tree, boolean& return1);
Object* canonicalize_and_or_tree(Cons* tree);
Object* canonicalize_negation_tree(Cons* tree);
boolean quantifier_symbolP(Symbol* self);
Cons* canonicalize_quantification_tree(Cons* tree);
Object* consDcanonicalize_proposition_tree(Cons* tree);
Object* canonicalize_proposition_tree(Object* tree);
Proposition* update_proposition(Object* tree, Keyword* updatemode);
Proposition* help_update_proposition(Object* tree, Keyword* updatemode);
Object* smart_update_proposition(Object* tree, Keyword* updatemode);
Object* assert(Object* proposition);
Proposition* retract(Object* proposition);
Proposition* deny(Object* proposition);
Proposition* conceive(Object* proposition);
void unassert(Object* proposition);
void unassert_fact(Proposition* self);
void destroy_proposition(Proposition* proposition);
void destroy_instance(Logic_Object* object);
void destroy_term(Logic_Object* object);
void clear_logic_module_hook(Module* module);
void clear_instances(Cons* name);
void clear_instances_evaluator_wrapper(Cons* arguments);
void do_clear_instances(Module* module);
void help_transfer_proposition_arguments(Proposition* proposition, Logic_Object* fromobject, Logic_Object* toobject);
void transfer_propositions_to_logic_object(Logic_Object* fromobject, Logic_Object* toobject);
void startup_propositions();

// Global declarations:
extern Symbol* SYM_PROPOSITIONS_ALL_ROOT_TYPES;
extern Symbol* SYM_PROPOSITIONS_ALL_SURROGATE_VALUE_INVERSES;
extern Symbol* SYM_PROPOSITIONS_ROOT_TYPE;
extern Symbol* SYM_PROPOSITIONS_DEPENDENT_ATTRIBUTE_PROPOSITIONS;
extern Symbol* SYM_PROPOSITIONS_DEPENDENT_PROPOSITIONS;
extern Symbol* SYM_PROPOSITIONS_VARIABLE_VALUE;
extern Symbol* SYM_PROPOSITIONS_VARIABLE_VALUE_INVERSE;
extern Surrogate* SGT_PROPOSITIONS_LOGIC_OBJECT;
extern Symbol* SYM_PROPOSITIONS_SKOLEM_TYPE;
extern Symbol* SYM_PROPOSITIONS_NOT_BOTTOMp;
extern Symbol* SYM_PROPOSITIONS_DEFINING_PROPOSITION;
extern Surrogate* SGT_PROPOSITIONS_SKOLEM;
extern Symbol* SYM_PROPOSITIONS_BOUND_TO_OFFSET;
extern Surrogate* SGT_PROPOSITIONS_PATTERN_VARIABLE;
extern Symbol* SYM_PROPOSITIONS_OBJECT_VECTOR;
extern Symbol* SYM_PROPOSITIONS_ARGUMENTS_VECTOR;
extern Symbol* SYM_PROPOSITIONS_VARIABLES_VECTOR;
extern Vector* ZERO_VARIABLES_VECTOR;
extern Symbol* SYM_PROPOSITIONS_EXTENSION;
extern Symbol* SYM_PROPOSITIONS_IOTAp;
extern Symbol* SYM_PROPOSITIONS_PROPOSITION;
extern Symbol* SYM_PROPOSITIONS_IO_VARIABLES;
extern Symbol* SYM_PROPOSITIONS_INTERNAL_VARIABLES;
extern Symbol* SYM_PROPOSITIONS_KIND;
extern Symbol* SYM_PROPOSITIONS_NATIVE_RELATION;
extern Symbol* SYM_PROPOSITIONS_QUERY_PATTERNS;
extern Symbol* SYM_PROPOSITIONS_REFERENCED_BY;
extern Symbol* SYM_PROPOSITIONS_TAXONOMY_NODE;
extern Surrogate* SGT_PROPOSITIONS_DESCRIPTION;
extern Surrogate* SGT_PROPOSITIONS_SLOT;
extern Symbol* SYM_PROPOSITIONS_PARTIAL_MATCH_SCORE;
extern Symbol* SYM_PROPOSITIONS_SET_OF_SUPPORT;
extern Symbol* SYM_PROPOSITIONS_TIME_STAMP;
extern Symbol* SYM_PROPOSITIONS_POSITIVE_SCORE;
extern Symbol* SYM_PROPOSITIONS_NEGATIVE_SCORE;
extern Symbol* SYM_PROPOSITIONS_POSITIVE_SET_OF_SUPPORT;
extern Symbol* SYM_PROPOSITIONS_NEGATIVE_SET_OF_SUPPORT;
extern Surrogate* SGT_PROPOSITIONS_TRUTH_VALUE;
extern Symbol* SYM_PROPOSITIONS_VARIABLE_TYPEp;
extern Symbol* SYM_PROPOSITIONS_SUBRELATION_LINKp;
extern Symbol* SYM_PROPOSITIONS_SUBSUMPTION_LINKp;
extern Symbol* SYM_PROPOSITIONS_SATELLITE_PROPOSITIONS;
extern Symbol* SYM_PROPOSITIONS_DONT_OPTIMIZEp;
extern Symbol* SYM_PROPOSITIONS_FORWARD_ONLYp;
extern Symbol* SYM_PROPOSITIONS_BACKWARD_ONLYp;
extern Symbol* SYM_PROPOSITIONS_TRUTH_VALUE;
extern Symbol* SYM_PROPOSITIONS_ARGUMENTS;
extern Symbol* SYM_PROPOSITIONS_OPERATOR;
extern Symbol* SYM_PROPOSITIONS_SLOTREF;
extern Surrogate* SGT_PROPOSITIONS_PROPOSITION;
extern Symbol* SYM_PROPOSITIONS_FUNCTION;
extern Symbol* SYM_PROPOSITIONS_PREDICATE;
extern Symbol* SYM_PROPOSITIONS_CONTEXT_ASSUMED_PROPOSITIONS;
extern Symbol* SYM_PROPOSITIONS_MONOTONICp;
extern Symbol* SYM_PROPOSITIONS_TRUTH_MAINTAINEDp;
extern Symbol* SYM_PROPOSITIONS_UP_TO_DATE_INFERENCESp;
extern Symbol* SYM_PROPOSITIONS_LOCALLY_CONCEIVED_PROPOSITIONS;
extern Symbol* SYM_PROPOSITIONS_LOCALLY_BOUND_PROPOSITIONS;
extern Symbol* SYM_PROPOSITIONS_LOCALLY_BOUND_SKOLEMS;
extern int oNOW_TIME_STAMPo;
extern Keyword* oLAST_KB_ACTIONo;
extern Keyword* KWD_PROPOSITIONS_UPDATE_PROPOSITION;
extern Keyword* KWD_PROPOSITIONS_EXECUTE_QUERY;
extern Logic_Object* BOTTOM;
extern Symbol* SYM_PROPOSITIONS_BOTTOM;
extern Surrogate* SGT_PROPOSITIONS_LITERAL_WRAPPER;
extern Surrogate* SGT_PROPOSITIONS_LITERAL;
extern Keyword* KWD_PROPOSITIONS_OPEN_WORLD;
extern Keyword* KWD_PROPOSITIONS_CLOSED_WORLD;
extern Keyword* oEVALUATIONMODEo;
extern Keyword* KWD_PROPOSITIONS_EXTENSIONAL_ASSERTION;
extern Symbol* SYM_PROPOSITIONS_oEVALUATIONMODEo;
extern Keyword* KWD_PROPOSITIONS_DESCRIPTION;
extern Keyword* KWD_PROPOSITIONS_QUERY;
extern Keyword* KWD_PROPOSITIONS_CONCEIVE;
extern boolean oCLIPPING_ENABLEDo;
extern boolean oCONTEXT_DEPENDENT_SEARCH_MODEpo;
extern Keyword* KWD_PROPOSITIONS_IMPLIES;
extern Keyword* KWD_PROPOSITIONS_RETRACT_TRUE;
extern Symbol* SYM_PROPOSITIONS_MASTER_PROPOSITION;
extern Keyword* KWD_PROPOSITIONS_ASSERT_TRUE;
extern Keyword* KWD_PROPOSITIONS_ASSERT_FALSE;
extern Keyword* KWD_PROPOSITIONS_RETRACT_FALSE;
extern Symbol* SYM_PROPOSITIONS_STRICT_INFERENCE_CACHE;
extern Surrogate* SGT_PROPOSITIONS_MODULE;
extern Keyword* KWD_PROPOSITIONS_STRICT;
extern Keyword* KWD_PROPOSITIONS_FUNCTION;
extern Keyword* KWD_PROPOSITIONS_CONSTANT;
extern Symbol* SYM_PROPOSITIONS_DESCRIPTION;
extern Keyword* KWD_PROPOSITIONS_PRIMITIVE;
extern Surrogate* SGT_PROPOSITIONS_STORAGE_SLOT;
extern Symbol* SYM_PROPOSITIONS_COMPLEMENT_DESCRIPTION;
extern Keyword* KWD_PROPOSITIONS_IN;
extern Surrogate* SGT_PROPOSITIONS_UNKNOWN;
extern Surrogate* SGT_PROPOSITIONS_RELATION;
extern int oSKOLEM_ID_COUNTERo;
extern Cons* oFREESKOLEMSo;
extern Symbol* SYM_PROPOSITIONS_oFREESKOLEMSo;
extern Symbol* SYM_PROPOSITIONS_SKOLEM_NAME;
extern Truth_Value* TRUE_TRUTH_VALUE;
extern Truth_Value* FALSE_TRUTH_VALUE;
extern Surrogate* SGT_PROPOSITIONS_COLLECTION;
extern Surrogate* SGT_PROPOSITIONS_SURROGATE;
extern Keyword* KWD_PROPOSITIONS_AND;
extern Keyword* KWD_PROPOSITIONS_OR;
extern Proposition* TRUE_PROPOSITION;
extern Surrogate* SGT_PROPOSITIONS_TRUE;
extern Proposition* FALSE_PROPOSITION;
extern Surrogate* SGT_PROPOSITIONS_FALSE;
extern Symbol* SYM_PROPOSITIONS_PERMUTATION_TABLE;
extern Keyword* KWD_PROPOSITIONS_NOT;
extern Keyword* KWD_PROPOSITIONS_EQUIVALENT;
extern Keyword* KWD_PROPOSITIONS_PREDICATE;
extern Surrogate* SGT_PROPOSITIONS_TRAP_DOOR_SURROGATE;
extern Symbol* SYM_PROPOSITIONS_SETOFALL;
extern Symbol* SYM_PROPOSITIONS_THE_ONLY;
extern Symbol* SYM_PROPOSITIONS_KAPPA;
extern Symbol* SYM_PROPOSITIONS_SETOF;
extern Symbol* SYM_PROPOSITIONS_LISTOF;
extern Symbol* SYM_PROPOSITIONS_CREATE;
extern Keyword* KWD_PROPOSITIONS_INTENSIONAL_ASSERTION;
extern Symbol* ANONYMOUS_VARIABLE_NAME;
extern Symbol* SYM_PROPOSITIONS_p;
extern Symbol* SYM_PROPOSITIONS_EVALUATOR_WRAPPER_CODE;
extern Symbol* SYM_PROPOSITIONS_NON_DISJOINTNESS_KLUDGEp;
extern Symbol* SYM_PROPOSITIONS_CLASS_EXTENSION;
extern Symbol* SYM_PROPOSITIONS_TRANSFER_LOGIC_INFORMATION_FROM_RELATION_HOOK;
extern Symbol* SYM_PROPOSITIONS_IMPLIES;
extern Symbol* SYM_PROPOSITIONS_RELATION_ORIGINATED_PROPOSITIONS;
extern Symbol* SYM_PROPOSITIONS_ISA;
extern Symbol* SYM_PROPOSITIONS_SURROGATE_VALUE_INVERSE;
extern Object* oPROPOSITIONUNDERCONSTRUCTIONo;
extern Symbol* SYM_PROPOSITIONS_oPROPOSITIONUNDERCONSTRUCTIONo;
extern Cons* oTOPLEVELPROPOSITIONSo;
extern Symbol* SYM_PROPOSITIONS_oTOPLEVELPROPOSITIONSo;
extern Surrogate* SGT_PROPOSITIONS_STRING_WRAPPER;
extern Surrogate* SGT_PROPOSITIONS_LOGIC_EXCEPTION;
extern Keyword* KWD_PROPOSITIONS_EXCEPTIONS;
extern Surrogate* SGT_PROPOSITIONS_READ_EXCEPTION;
extern Symbol* SYM_PROPOSITIONS_CONSTANT;
extern Symbol* SYM_PROPOSITIONS_TRUE;
extern Symbol* SYM_PROPOSITIONS_FALSE;
extern Surrogate* SGT_PROPOSITIONS_SYMBOL;
extern Symbol* SYM_PROPOSITIONS_e;
extern Symbol* SYM_PROPOSITIONS_AND;
extern Symbol* SYM_PROPOSITIONS_OR;
extern Symbol* SYM_PROPOSITIONS_NOT;
extern Symbol* SYM_PROPOSITIONS_IN;
extern Symbol* SYM_PROPOSITIONS_SUBSET_OF;
extern Symbol* SYM_PROPOSITIONS_EXISTS;
extern Symbol* SYM_PROPOSITIONS_FORALL;
extern Keyword* KWD_PROPOSITIONS_EXISTS;
extern Symbol* SYM_PROPOSITIONS_EQUIVALENT;
extern Surrogate* SGT_PROPOSITIONS_FUNCTION;
extern Symbol* SYM_PROPOSITIONS_SECOND_ORDER;
extern Surrogate* SGT_PROPOSITIONS_ANY;
extern Surrogate* SGT_PROPOSITIONS_BOOLEAN;
extern Surrogate* SGT_PROPOSITIONS_BOOLEAN_WRAPPER;
extern Keyword* KWD_PROPOSITIONS_FORALL;
extern Symbol* SYM_PROPOSITIONS_ALWAYS;
extern Symbol* SYM_PROPOSITIONS_WHERE;
extern Symbol* SYM_PROPOSITIONS_SOME;
extern Symbol* SYM_PROPOSITIONS_DELETED_OBJECTp;
extern Keyword* KWD_PROPOSITIONS_DELETED;
extern Symbol* SYM_PROPOSITIONS_DEFINITION;
extern Symbol* SYM_PROPOSITIONS_CLEAR_LOGIC_MODULE_HOOK;
extern Symbol* SYM_PROPOSITIONS_TOTALp;
extern Symbol* SYM_PROPOSITIONS_INDEX_ON_VALUESp;

class Logic_Object : public Context_Sensitive_Object, public Dynamic_Slots_Mixin {
public:
  Surrogate* root_type;
  List* dependent_attribute_propositions;
  List* dependent_propositions;
  Object* variable_value;
  Object* variable_value_inverse;
public:
  virtual void print_object(ostream* stream);
  virtual Surrogate* primary_type();
  virtual Object* get_slot_value(char* slotname);
  virtual Slot* get_own_slot(char* slotname);
  virtual boolean deletedP_setter(boolean value);
  virtual boolean deletedP();
  virtual void update_logical_class_extension(Surrogate* type);
  virtual boolean monadicP();
  virtual List* all_root_types_reader();
  virtual Cons* variable_value_inverse_reader();
  virtual List* all_surrogate_value_inverses_reader();
};

class Skolem : public Logic_Object {
public:
  Object* not_bottomP;
  Proposition* defining_proposition;
public:
  virtual Surrogate* primary_type();
  virtual Object* value_of();
  virtual void propagate_kb_constraints(Context* context);
};

class Pattern_Variable : public Skolem {
public:
  int bound_to_offset;
public:
  virtual Surrogate* primary_type();
  virtual void update_logical_class_extension(Surrogate* type);
  virtual Object* binding_to_constant();
};

class Description : public Logic_Object {
public:
  Proposition* proposition;
  Vector* io_variables;
  Vector* internal_variables;
  Keyword* kind;
  Relation* native_relation;
  Key_Value_List* query_patterns;
  List* referenced_by;
  Taxonomy_Node* taxonomy_node;
public:
  virtual Surrogate* primary_type();
  virtual Description_Extension_Iterator* allocate_iterator();
  virtual Logic_Object* find_duplicate_description();
  virtual boolean primitiveP();
  virtual boolean monadicP();
  virtual int arity();
  virtual Pattern_Variable* representative();
  virtual boolean relationP();
  virtual boolean functionP();
  virtual Surrogate* description_surrogate();
  virtual List* extension_reader();
  virtual boolean iotaP_reader();
};

class Truth_Value : public Logic_Object {
public:
  double positive_score;
  double negative_score;
  List* positive_set_of_support;
  List* negative_set_of_support;
  int time_stamp;
public:
  virtual Surrogate* primary_type();
};

class Proposition : public Context_Sensitive_Object, public Dynamic_Slots_Mixin {
public:
  Keyword* kind;
  Object* truth_value;
  Vector* arguments;
  Object* renamed_Operator;
  List* dependent_propositions;
public:
  virtual void print_object(ostream* stream);
  virtual Surrogate* primary_type();
  virtual boolean deletedP_setter(boolean value);
  virtual boolean deletedP();
  virtual void propagate_kb_constraints(Context* context);
  virtual boolean variable_typeP_reader();
  virtual boolean subrelation_linkP_reader();
  virtual boolean subsumption_linkP_reader();
  virtual List* satellite_propositions_reader();
  virtual boolean dont_optimizeP_reader();
  virtual boolean forward_onlyP_reader();
  virtual boolean backward_onlyP_reader();
};

