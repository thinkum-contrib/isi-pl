// taxonomies.hh

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


// Function signatures:
Cons* help_collect_all_nodes(Taxonomy_Node* node);
Cons* all_nodes(Taxonomy_Graph* graph);
Taxonomy_Node* help_find_taxonomy_node(Taxonomy_Node* node, int label);
Taxonomy_Node* find_taxonomy_node(Taxonomy_Graph* graph, int label);
Taxonomy_Node* ftn(Taxonomy_Graph* graph, int label);
void create_link(Taxonomy_Graph* graph, Taxonomy_Node* parent, Taxonomy_Node* child);
void link_nodes(Taxonomy_Graph* graph, Taxonomy_Node* parent, Taxonomy_Node* child);
void compute_total_ancestors(Taxonomy_Node* node);
void add_node_to_graph(Taxonomy_Graph* graph, Taxonomy_Node* node, Taxonomy_Node* parent);
Taxonomy_Node* create_and_intern_node(Taxonomy_Graph* graph, Taxonomy_Node* parent, Object* nativeobject);
void remove_node_from_graph(Taxonomy_Graph* graph, Taxonomy_Node* node);
void remove_link(Taxonomy_Graph* graph, Taxonomy_Node* parent, Taxonomy_Node* child);
void print_graph_tree(Taxonomy_Node* node, int indent, Output_Stream* stream);
void print_graph(Taxonomy_Graph* graph, Output_Stream* stream);
void print_spanning_tree(Taxonomy_Node* node, int indent, Output_Stream* stream);
void print_forest(Taxonomy_Graph* graph, Output_Stream* stream);
Interval* create_interval(Taxonomy_Node* node);
void clear_tree_labels(Taxonomy_Node* node);
void clear_tree(Taxonomy_Node* node);
boolean labeledP(Taxonomy_Node* node);
void clear_graph_tree(Taxonomy_Node* node);
void clear_graph(Taxonomy_Graph* graph);
boolean interval_subsumes_integerP(Interval* interval, int n);
boolean taxonomy_node_subclass_ofP(Taxonomy_Node* descendant, Taxonomy_Node* ancestor);
void optimize_intervals(Taxonomy_Graph* graph);
boolean slow_taxonomy_node_subclass_ofP(Taxonomy_Node* descendant, Taxonomy_Node* ancestor);
Cons* most_general_nodes(Cons* nodes);
int read_Opostorder_numberO();
int write_Opostorder_numberO(int value);
void help_postorder_label_tree(Taxonomy_Node* node);
void postorder_label_tree(Taxonomy_Node* root);
int help_create_tree_intervals(Taxonomy_Node* self);
void create_initial_intervals(Taxonomy_Graph* graph);
boolean interval_subsumes_intervalP(Interval* parent, Interval* child);
boolean adjacentP(Interval* leftinterval, Interval* rightinterval);
Interval* merge_intervals(Interval* leftinterval, Interval* rightinterval);
Interval* allocate_new_interval(Taxonomy_Node* parent);
Iterator* all_intervals(Taxonomy_Node* node);
boolean all_intervals_nextP(All_Purpose_Iterator* self);
void remove_interval(Taxonomy_Node* node, Interval* interval);
void insert_interval(Taxonomy_Graph* graph, Taxonomy_Node* node, Interval* interval);
void add_interval_to_node(Taxonomy_Graph* graph, Interval* interval, Taxonomy_Node* node);
Interval* create_next_postorder_interval(Taxonomy_Graph* graph);
void propogate_foreign_interval(Taxonomy_Graph* graph, Interval* interval, Taxonomy_Node* node);
void create_spanning_tree(Taxonomy_Graph* graph, Taxonomy_Node* node);
void create_spanning_forest(Taxonomy_Graph* graph);
void startup_taxonomies();

// Global declarations:
extern int oNUMBERING_INTERVALo;
extern int MARKER_LABEL;
extern int DELETED_LABEL;
extern int oPOSTORDER_NUMBERo;
extern Symbol* SYM_TAXONOMIES_oPOSTORDER_NUMBERo;

