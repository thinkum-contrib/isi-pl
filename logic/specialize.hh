// specialize.hh

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
class Abstract_Dependent_Propositions_Iterator;
class Directly_Dependent_Propositions_Iterator;
class Transitive_Closure_Iterator;
class Direct_Supercollections_Iterator;

// Function signatures:
Abstract_Dependent_Propositions_Iterator* new_abstract_dependent_propositions_iterator();
Object* access_abstract_dependent_propositions_iterator_slot_value(Abstract_Dependent_Propositions_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Directly_Dependent_Propositions_Iterator* new_directly_dependent_propositions_iterator();
Object* access_directly_dependent_propositions_iterator_slot_value(Directly_Dependent_Propositions_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Cons* find_propositions_on_next_equivalent_skolem(Abstract_Dependent_Propositions_Iterator* self);
Iterator* all_directly_dependent_propositions(Logic_Object* self, Keyword* kind);
Iterator* all_dependent_attribute_propositions(Logic_Object* self, Keyword* kind);
boolean slotref_specializes_slotrefP(Surrogate* slotref1, Surrogate* slotref2);
Logic_Object* find_logic_object_bound_to_argument(Proposition* proposition);
boolean specializes_predicate_propositionP(Proposition* subproposition, Proposition* referenceproposition);
boolean specializes_in_propositionP(Proposition* subproposition, Proposition* referenceproposition);
boolean failing_subsumption_testP(Proposition* subproposition, Proposition* referenceproposition);
Iterator* all_specializing_propositions(Proposition* self);
boolean specializes_attribute_propositionP(Proposition* subproposition, Proposition* referenceproposition);
Object* fast_get_attribute_proposition_value(Logic_Object* self, Surrogate* relation);
Object* get_attribute_proposition_value(Logic_Object* self, Surrogate* relation);
boolean specializes_property_propositionP(Proposition* subproposition, Proposition* referenceproposition);
boolean exists_property_propositionP(Logic_Object* self, Surrogate* relation);
boolean exists_specializing_in_propositionP(Logic_Object* member, Object* collection);
boolean matches_in_proposition_collection_argumentP(Proposition* subproposition, Proposition* referenceproposition);
Directly_Dependent_Propositions_Iterator* all_in_proposition_members(Logic_Object* collection);
Transitive_Closure_Iterator* new_transitive_closure_iterator();
Object* access_transitive_closure_iterator_slot_value(Transitive_Closure_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Iterator* allocate_transitive_closure_iterator(Object* startnode, cpp_function_code allocateadjacencyiterator, cpp_function_code filterfunction);
Direct_Supercollections_Iterator* new_direct_supercollections_iterator();
Object* access_direct_supercollections_iterator_slot_value(Direct_Supercollections_Iterator* self, Symbol* slotname, Object* value, boolean setvalueP);
Iterator* all_directly_linked_objects(Logic_Object* self, Keyword* kind, boolean inverseP);
Iterator* all_direct_supercollections(Logic_Object* self);
Iterator* all_direct_subcollections(Logic_Object* self);
Iterator* all_supercollections(Logic_Object* self);
Iterator* all_subcollections(Logic_Object* self);
boolean clashes_with_function_propositionP(Proposition* nextproposition, Proposition* referenceproposition);
Directly_Dependent_Propositions_Iterator* all_clashing_propositions(Proposition* self);
List* relations_with_descriptions();
void build_subsumption_taxonomy_graph();
void clear_implication_subsumption_graph();
void initialize_implication_subsumption_graph();
Taxonomy_Node* find_description_implication_subsumption_node(Description* description);
Taxonomy_Node* create_description_implication_subsumption_node(Description* description, Taxonomy_Node* parentnode);
Taxonomy_Node* find_or_create_description_implication_subsumption_node(Description* description);
Description* create_description_for_relation_and_ancestors(Relation* self);
void add_taxonomy_implies_subsumes_link(Description* taildescription, Description* headdescription);
void drop_taxonomy_implies_subsumes_link(Description* taildescription, Description* headdescription);
boolean taxonomy_implies_or_is_subsumedP(Relation* premise, Relation* conclusion);
void startup_specialize();

// Global declarations:
extern Symbol* SYM_SPECIALIZE_PROPOSITION_CURSOR;
extern Symbol* SYM_SPECIALIZE_KIND_OF_PROPOSITION;
extern Symbol* SYM_SPECIALIZE_ATTRIBUTE_PROPOSITIONSp;
extern Symbol* SYM_SPECIALIZE_VARIABLE_VALUE_INVERSE_STACK;
extern Surrogate* SGT_SPECIALIZE_ABSTRACT_DEPENDENT_PROPOSITIONS_ITERATOR;
extern Symbol* SYM_SPECIALIZE_SUBSUMPTION_TEST_FILTERp;
extern Symbol* SYM_SPECIALIZE_RETURN_ARGUMENT_INDEX;
extern Symbol* SYM_SPECIALIZE_REFERENCE_PROPOSITION;
extern Surrogate* SGT_SPECIALIZE_DIRECTLY_DEPENDENT_PROPOSITIONS_ITERATOR;
extern Keyword* KWD_SPECIALIZE_FUNCTION;
extern Symbol* SYM_SPECIALIZE_DESCRIPTION;
extern Surrogate* SGT_SPECIALIZE_LOGIC_OBJECT;
extern Iterator* EMPTY_ALL_PROPOSITIONS_ITERATOR;
extern Keyword* KWD_SPECIALIZE_PREDICATE;
extern Keyword* KWD_SPECIALIZE_IN;
extern Proposition* BLANK_PROPERTY_PROPOSITION;
extern Symbol* SYM_SPECIALIZE_PREDICATE;
extern Proposition* BLANK_IN_PROPOSITION;
extern Symbol* SYM_SPECIALIZE_IN;
extern Symbol* SYM_SPECIALIZE_ALLOCATE_ADJACENCY_ITERATOR_FUNCTION;
extern Symbol* SYM_SPECIALIZE_FILTERp;
extern Symbol* SYM_SPECIALIZE_ADJACENCY_ITERATOR_STACK;
extern Symbol* SYM_SPECIALIZE_BEEN_THERE_LIST;
extern Surrogate* SGT_SPECIALIZE_TRANSITIVE_CLOSURE_ITERATOR;
extern Symbol* SYM_SPECIALIZE_INVERSEp;
extern Symbol* SYM_SPECIALIZE_REFERENCE_INSTANCE;
extern Surrogate* SGT_SPECIALIZE_DIRECT_SUPERCOLLECTIONS_ITERATOR;
extern Keyword* KWD_SPECIALIZE_IMPLIES;
extern Taxonomy_Graph* oIMPLICATION_SUBSUMPTION_GRAPHo;

class Abstract_Dependent_Propositions_Iterator : public Iterator {
public:
  Cons* proposition_cursor;
  Keyword* kind_of_proposition;
  boolean attribute_propositionsP;
  Cons* variable_value_inverse_stack;
public:
  virtual Surrogate* primary_type();
};

class Directly_Dependent_Propositions_Iterator : public Abstract_Dependent_Propositions_Iterator {
public:
  cpp_function_code subsumption_test_filterP;
  int return_argument_index;
  Proposition* reference_proposition;
public:
  virtual Surrogate* primary_type();
  virtual boolean nextP();
};

class Transitive_Closure_Iterator : public Iterator {
public:
  cpp_function_code allocate_adjacency_iterator_function;
  cpp_function_code filterP;
  Cons* adjacency_iterator_stack;
  Cons* been_there_list;
public:
  virtual Surrogate* primary_type();
  virtual boolean nextP();
  virtual void free();
};

class Direct_Supercollections_Iterator : public Abstract_Dependent_Propositions_Iterator {
public:
  boolean inverseP;
  Logic_Object* reference_instance;
public:
  virtual Surrogate* primary_type();
  virtual boolean nextP();
};

