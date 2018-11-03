// taxonomies.cc

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

#include "stella-includes.hh"

int oNUMBERING_INTERVALo = 100;

int MARKER_LABEL = -99;

int DELETED_LABEL = -99;

int oPOSTORDER_NUMBERo = NULL_INTEGER;

Symbol* SYM_TAXONOMIES_oPOSTORDER_NUMBERo = NULL;

Cons* help_collect_all_nodes(Taxonomy_Node* node) {
  { Cons* result = NIL;

    { Taxonomy_Node* child = NULL;
      Cons* iter_001 = node->tree_children;

      while (!nilP(iter_001)) {
        {
          child = ((Taxonomy_Node*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        result = help_collect_all_nodes(child)->concatenate(result);
      }
    }
    return (cons(node, result));
  }
}

Cons* all_nodes(Taxonomy_Graph* graph) {
  { Cons* result = NIL;

    { Taxonomy_Node* root = NULL;
      Cons* iter_001 = graph->roots;

      while (!nilP(iter_001)) {
        {
          root = ((Taxonomy_Node*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        result = help_collect_all_nodes(root)->concatenate(result);
      }
    }
    return (result);
  }
}

Taxonomy_Node* help_find_taxonomy_node(Taxonomy_Node* node, int label) {
  if (node->label == label) {
    return (node);
  }
  { Taxonomy_Node* result = NULL;

    { Taxonomy_Node* child = NULL;
      Cons* iter_001 = node->children;

      while (!nilP(iter_001)) {
        {
          child = ((Taxonomy_Node*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        result = help_find_taxonomy_node(child, label);
        if (result != NULL) {
          return (result);
        }
      }
    }
    return (NULL);
  }
}

Taxonomy_Node* find_taxonomy_node(Taxonomy_Graph* graph, int label) {
  { Taxonomy_Node* result = NULL;

    { Taxonomy_Node* root = NULL;
      Cons* iter_001 = graph->roots;

      while (!nilP(iter_001)) {
        {
          root = ((Taxonomy_Node*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        result = help_find_taxonomy_node(root, label);
        if (result != NULL) {
          return (result);
        }
      }
    }
    return (NULL);
  }
}

Taxonomy_Node* ftn(Taxonomy_Graph* graph, int label) {
  return (find_taxonomy_node(graph, label));
}

void create_link(Taxonomy_Graph* graph, Taxonomy_Node* parent, Taxonomy_Node* child) {
  if (child->parents->emptyP()) {
    graph->roots = graph->roots->remove(child);
  }
  child->parents = cons(parent, child->parents);
  parent->children = cons(child, parent->children);
  compute_total_ancestors(child);
}

void link_nodes(Taxonomy_Graph* graph, Taxonomy_Node* parent, Taxonomy_Node* child) {
  if (parent->children->memberP(child)) {
    return;
  }
  if (graph->incremental_modeP) {
    if (child->initial_interval == NULL) {
      { Interval* interval = allocate_new_interval(parent);

        if (interval == NULL) {
          if (graph->renumber_if_out_of_numbersP) {
            create_link(graph, parent, child);
            create_spanning_forest(graph);
            return;
          }
          interval = create_next_postorder_interval(graph);
          propogate_foreign_interval(graph, interval, parent);
        }
        child->initial_interval = interval;
        insert_interval(graph, child, interval);
        child->label = interval->upper_bound;
        parent->tree_children = cons(child, parent->tree_children->reverse())->reverse();
      }
    }
    else {
      { Interval* interval = NULL;
        Iterator* iter_001 = all_intervals(child);

        while (iter_001->nextP()) {
          {
            interval = ((Interval*)(iter_001->value));
          }
          propogate_foreign_interval(graph, interval, parent);
        }
      }
    }
  }
  create_link(graph, parent, child);
}

void compute_total_ancestors(Taxonomy_Node* node) {
  { int totalancestors = 0;

    { Taxonomy_Node* parent = NULL;
      Cons* iter_001 = node->parents;

      while (!nilP(iter_001)) {
        {
          parent = ((Taxonomy_Node*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        totalancestors = totalancestors + parent->total_ancestors;
      }
    }
    node->total_ancestors = totalancestors + 1;
    { Taxonomy_Node* child = NULL;
      Cons* iter_002 = node->children;

      while (!nilP(iter_002)) {
        {
          child = ((Taxonomy_Node*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        compute_total_ancestors(child);
      }
    }
  }
}

void add_node_to_graph(Taxonomy_Graph* graph, Taxonomy_Node* node, Taxonomy_Node* parent) {
  if (parent == NULL) {
    graph->roots = cons(node, graph->roots);
    if (graph->incremental_modeP) {
      { Interval* interval = create_next_postorder_interval(graph);

        node->first_interval_lower_bound = interval->lower_bound;
        node->first_interval_upper_bound = interval->upper_bound;
        node->initial_interval = interval;
        node->label = graph->largest_postorder_number;
      }
    }
    return;
  }
  link_nodes(graph, parent, node);
}

Taxonomy_Node* create_and_intern_node(Taxonomy_Graph* graph, Taxonomy_Node* parent, Object* nativeobject) {
  { Taxonomy_Node* self_001 = new_taxonomy_node();

    self_001->native_object = nativeobject;
    { Taxonomy_Node* node = self_001;

      add_node_to_graph(graph, node, parent);
      return (node);
    }
  }
}

void remove_node_from_graph(Taxonomy_Graph* graph, Taxonomy_Node* node) {
  { Cons* parentscopy = copy_cons_list(node->parents);
    Cons* childrencopy = copy_cons_list(node->children);

    { Object* parent = NULL;
      Cons* iter_001 = parentscopy;

      while (!nilP(iter_001)) {
        {
          parent = iter_001->value;
          iter_001 = iter_001->rest;
        }
        remove_link(graph, ((Taxonomy_Node*)(parent)), node);
      }
    }
    { Object* child = NULL;
      Cons* iter_002 = childrencopy;

      while (!nilP(iter_002)) {
        {
          child = iter_002->value;
          iter_002 = iter_002->rest;
        }
        remove_link(graph, node, ((Taxonomy_Node*)(child)));
      }
    }
    node->intervals = NIL;
    node->label = DELETED_LABEL;
    if (graph->roots->memberP(node)) {
      graph->roots = graph->roots->remove(node);
    }
  }
}

void remove_link(Taxonomy_Graph* graph, Taxonomy_Node* parent, Taxonomy_Node* child) {
  if (!parent->children->memberP(child)) {
    cerr << "remove-link: " << "`" << parent << "'" << " and " << "`" << child << "'" << " aren't linked";
    return;
  }
  { boolean treelinkP = parent->tree_children->memberP(child);

    parent->children = parent->children->remove(child);
    if (treelinkP) {
      parent->tree_children = parent->tree_children->remove(child);
    }
    child->parents = child->parents->remove(parent);
    if (child->parents->emptyP()) {
      graph->roots = cons(child, graph->roots);
    }
    if (graph->incremental_modeP) {
      parent->intervals = cons(parent->initial_interval, NIL);
      { Taxonomy_Node* child = NULL;
        Cons* iter_001 = parent->children;

        while (!nilP(iter_001)) {
          {
            child = ((Taxonomy_Node*)(iter_001->value));
            iter_001 = iter_001->rest;
          }
          { Interval* interval = NULL;
            Cons* iter_002 = child->intervals;

            while (!nilP(iter_002)) {
              {
                interval = ((Interval*)(iter_002->value));
                iter_002 = iter_002->rest;
              }
              propogate_foreign_interval(graph, interval, parent);
            }
          }
        }
      }
    }
  }
}

void print_graph_tree(Taxonomy_Node* node, int indent, Output_Stream* stream) {
  { int i = NULL_INTEGER;
    int iter_001 = 1;
    int upper_bound_001 = indent;
    boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

    while (unboundedP_001 ||
        (iter_001 <= upper_bound_001)) {
      {
        i = iter_001;
        iter_001 = iter_001 + 1;
      }
      *(stream->native_stream) << " ";
    }
  }
  *(stream->native_stream) << node << endl;
  { Taxonomy_Node* child = NULL;
    Cons* iter_002 = node->children;

    while (!nilP(iter_002)) {
      {
        child = ((Taxonomy_Node*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      print_graph_tree(child, indent + 2, stream);
    }
  }
}

void print_graph(Taxonomy_Graph* graph, Output_Stream* stream) {
  { Taxonomy_Node* root = NULL;
    Cons* iter_001 = graph->roots;

    while (!nilP(iter_001)) {
      {
        root = ((Taxonomy_Node*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      print_graph_tree(root, 0, stream);
      *(stream->native_stream) << endl;
    }
  }
}

void print_spanning_tree(Taxonomy_Node* node, int indent, Output_Stream* stream) {
  { int i = NULL_INTEGER;
    int iter_001 = 1;
    int upper_bound_001 = indent;
    boolean unboundedP_001 = upper_bound_001 == NULL_INTEGER;

    while (unboundedP_001 ||
        (iter_001 <= upper_bound_001)) {
      {
        i = iter_001;
        iter_001 = iter_001 + 1;
      }
      *(stream->native_stream) << " ";
    }
  }
  *(stream->native_stream) << node << endl;
  { Taxonomy_Node* child = NULL;
    Cons* iter_002 = node->tree_children;

    while (!nilP(iter_002)) {
      {
        child = ((Taxonomy_Node*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      print_spanning_tree(child, indent + 2, stream);
    }
  }
}

void print_forest(Taxonomy_Graph* graph, Output_Stream* stream) {
  { Taxonomy_Node* root = NULL;
    Cons* iter_001 = graph->roots;

    while (!nilP(iter_001)) {
      {
        root = ((Taxonomy_Node*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      print_spanning_tree(root, 0, stream);
      *(stream->native_stream) << endl;
    }
  }
}

Interval* create_interval(Taxonomy_Node* node) {
  { Interval* interval = new_interval();

    node->intervals = cons(interval, node->intervals);
    return (interval);
  }
}

void clear_tree_labels(Taxonomy_Node* node) {
  node->label = NULL_INTEGER;
  { Taxonomy_Node* child = NULL;
    Cons* iter_001 = node->children;

    while (!nilP(iter_001)) {
      {
        child = ((Taxonomy_Node*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      clear_tree_labels(child);
    }
  }
}

void clear_tree(Taxonomy_Node* node) {
  node->label = NULL_INTEGER;
  node->first_interval_lower_bound = NULL_INTEGER;
  node->first_interval_upper_bound = NULL_INTEGER;
  node->intervals = NIL;
  { Taxonomy_Node* child = NULL;
    Cons* iter_001 = node->children;

    while (!nilP(iter_001)) {
      {
        child = ((Taxonomy_Node*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      clear_tree(child);
    }
  }
}

boolean labeledP(Taxonomy_Node* node) {
  return (node->label != NULL_INTEGER);
}

void clear_graph_tree(Taxonomy_Node* node) {
  if (!(labeledP(node))) {
    return;
  }
  node->label = NULL_INTEGER;
  node->intervals = NIL;
  node->tree_children = NIL;
  { Taxonomy_Node* child = NULL;
    Cons* iter_001 = node->children;

    while (!nilP(iter_001)) {
      {
        child = ((Taxonomy_Node*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      clear_graph_tree(child);
    }
  }
}

void clear_graph(Taxonomy_Graph* graph) {
  { Taxonomy_Node* root = NULL;
    Cons* iter_001 = graph->roots;

    while (!nilP(iter_001)) {
      {
        root = ((Taxonomy_Node*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      clear_graph_tree(root);
    }
  }
}

boolean interval_subsumes_integerP(Interval* interval, int n) {
  return ((n >= interval->lower_bound) &&
      (n <= interval->upper_bound));
}

boolean taxonomy_node_subclass_ofP(Taxonomy_Node* descendant, Taxonomy_Node* ancestor) {
  { int descendantlabel = descendant->label;

    if ((descendantlabel >= ancestor->first_interval_lower_bound) &&
        (descendantlabel <= ancestor->first_interval_upper_bound)) {
      return (TRUE);
    }
    { Interval* interval = NULL;
      Cons* iter_001 = ancestor->intervals;

      while (!nilP(iter_001)) {
        {
          interval = ((Interval*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if ((descendantlabel >= interval->lower_bound) &&
            (descendantlabel <= interval->upper_bound)) {
          return (TRUE);
        }
      }
    }
    return (FALSE);
  }
}

void optimize_intervals(Taxonomy_Graph* graph) {
  { Interval* firstinterval = NULL;

    { Taxonomy_Node* node = NULL;
      Cons* iter_001 = all_nodes(graph);

      while (!nilP(iter_001)) {
        {
          node = ((Taxonomy_Node*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        firstinterval = ((Interval*)(node->intervals->value));
        node->first_interval_lower_bound = firstinterval->lower_bound;
        node->first_interval_upper_bound = firstinterval->upper_bound;
        node->intervals = node->intervals->rest;
      }
    }
  }
}

boolean slow_taxonomy_node_subclass_ofP(Taxonomy_Node* descendant, Taxonomy_Node* ancestor) {
  if (descendant == ancestor) {
    return (TRUE);
  }
  { Taxonomy_Node* parent = NULL;
    Cons* iter_001 = descendant->parents;

    while (!nilP(iter_001)) {
      {
        parent = ((Taxonomy_Node*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      if (slow_taxonomy_node_subclass_ofP(parent, ancestor)) {
        return (TRUE);
      }
    }
  }
  return (FALSE);
}

Cons* most_general_nodes(Cons* nodes) {
  { boolean node1hasparent = FALSE;
    Cons* result = NIL;

    { Taxonomy_Node* node1 = NULL;
      Cons* iter_001 = nodes;

      while (!nilP(iter_001)) {
        {
          node1 = ((Taxonomy_Node*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        node1hasparent = FALSE;
        { Taxonomy_Node* node2 = NULL;
          Cons* iter_002 = nodes;

          while (!nilP(iter_002)) {
            {
              node2 = ((Taxonomy_Node*)(iter_002->value));
              iter_002 = iter_002->rest;
            }
            if ((!(node1 == node2)) &&
                taxonomy_node_subclass_ofP(node1, node2)) {
              node1hasparent = TRUE;
              break;
            }
          }
        }
        if (!(node1hasparent)) {
          result = cons(node1, result);
        }
      }
    }
    return (result);
  }
}

int read_Opostorder_numberO() {
  return (oPOSTORDER_NUMBERo);
}

int write_Opostorder_numberO(int value) {
  oPOSTORDER_NUMBERo = value;
  return (value);
}

void help_postorder_label_tree(Taxonomy_Node* node) {
  { Taxonomy_Node* child = NULL;
    Cons* iter_001 = node->tree_children;

    while (!nilP(iter_001)) {
      {
        child = ((Taxonomy_Node*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      help_postorder_label_tree(child);
    }
  }
  oPOSTORDER_NUMBERo = oPOSTORDER_NUMBERo + oNUMBERING_INTERVALo;
  node->label = oPOSTORDER_NUMBERo;
}

void postorder_label_tree(Taxonomy_Node* root) {
  { int old_Opostorder_numberO_001 = oPOSTORDER_NUMBERo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPOSTORDER_NUMBERo = 0;
          help_postorder_label_tree(root);
          oPOSTORDER_NUMBERo = old_Opostorder_numberO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPOSTORDER_NUMBERo = old_Opostorder_numberO_001;
        resignal();
      }
    }
  }
}

int help_create_tree_intervals(Taxonomy_Node* self) {
  { Interval* newinterval = create_interval(self);
    int minchildlabel = NULL_INTEGER;
    int mylabel = NULL_INTEGER;
    int prevpostnumber = oPOSTORDER_NUMBERo;

    if (self->initial_interval != NULL) {
      cerr << "`help-create-tree-intervals': Initial interval already defined";
    }
    self->initial_interval = newinterval;
    if (!(self->tree_children->emptyP())) {
      minchildlabel = help_create_tree_intervals(((Taxonomy_Node*)(self->tree_children->first())));
    }
    { Taxonomy_Node* child = NULL;
      Cons* iter_001 = self->tree_children->rest;

      while (!nilP(iter_001)) {
        {
          child = ((Taxonomy_Node*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        help_create_tree_intervals(child);
      }
    }
    oPOSTORDER_NUMBERo = oPOSTORDER_NUMBERo + oNUMBERING_INTERVALo;
    mylabel = oPOSTORDER_NUMBERo;
    if (self->tree_children->emptyP()) {
      minchildlabel = prevpostnumber + 1;
    }
    newinterval->lower_bound = minchildlabel;
    newinterval->upper_bound = mylabel;
    self->label = mylabel;
    return (minchildlabel);
  }
}

void create_initial_intervals(Taxonomy_Graph* graph) {
  { int old_Opostorder_numberO_001 = oPOSTORDER_NUMBERo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oPOSTORDER_NUMBERo = 0;
          { Taxonomy_Node* root = NULL;
            Cons* iter_001 = graph->roots;

            while (!nilP(iter_001)) {
              {
                root = ((Taxonomy_Node*)(iter_001->value));
                iter_001 = iter_001->rest;
              }
              help_create_tree_intervals(root);
            }
          }
          graph->largest_postorder_number = oPOSTORDER_NUMBERo;
          oPOSTORDER_NUMBERo = old_Opostorder_numberO_001;
        }
        oEXCEPTIONo = NULL;
      }
      oEXCEPTIONHANDLERADDRESSo = old_OexceptionhandleraddressO_001;
    }
    if (oEXCEPTIONo != NULL) {
      if (TRUE) {
        oPOSTORDER_NUMBERo = old_Opostorder_numberO_001;
        resignal();
      }
    }
  }
}

boolean interval_subsumes_intervalP(Interval* parent, Interval* child) {
  return ((child->upper_bound <= parent->upper_bound) &&
      (child->lower_bound >= parent->lower_bound));
}

boolean adjacentP(Interval* leftinterval, Interval* rightinterval) {
  return ((rightinterval->lower_bound - 1) == leftinterval->upper_bound);
}

Interval* merge_intervals(Interval* leftinterval, Interval* rightinterval) {
  { Interval* self_001 = new_interval();

    self_001->lower_bound = leftinterval->lower_bound;
    self_001->upper_bound = rightinterval->upper_bound;
    { Interval* value_001 = self_001;

      return (value_001);
    }
  }
}

Interval* allocate_new_interval(Taxonomy_Node* parent) {
  { Interval* parentinterval = parent->initial_interval;

    if (parent->tree_children->emptyP()) {
      if (parentinterval->lower_bound == parentinterval->upper_bound) {
        return (NULL);
      }
      { Interval* self_001 = new_interval();

        self_001->lower_bound = parentinterval->lower_bound;
        self_001->upper_bound = parentinterval->upper_bound - floor_(oNUMBERING_INTERVALo / 2.0);
        { Interval* value_001 = self_001;

          return (value_001);
        }
      }
    }
    { Taxonomy_Node* rightchild = ((Taxonomy_Node*)(parent->tree_children->last()));
      Interval* rightchildinterval = rightchild->initial_interval;

      if (rightchildinterval->upper_bound >= (parentinterval->upper_bound - 1)) {
        return (NULL);
      }
      { Interval* self_002 = new_interval();

        self_002->lower_bound = rightchildinterval->upper_bound + 1;
        self_002->upper_bound = ceiling((parentinterval->upper_bound + rightchildinterval->upper_bound) / 2.0);
        { Interval* value_002 = self_002;

          return (value_002);
        }
      }
    }
  }
}

Iterator* all_intervals(Taxonomy_Node* node) {
  { All_Purpose_Iterator* iterator = new_all_purpose_iterator();

    iterator->iterator_cons_list = copy_cons_list(node->intervals);
    if (node->first_interval_lower_bound >= 0) {
      { Interval* self_002 = new_interval();

        self_002->lower_bound = node->first_interval_lower_bound;
        self_002->upper_bound = node->first_interval_upper_bound;
        iterator->iterator_object = self_002;
      }
    }
    iterator->iterator_next_code = ((cpp_function_code)(&all_intervals_nextP));
    iterator->first_iterationP = TRUE;
    return (iterator);
  }
}

boolean all_intervals_nextP(All_Purpose_Iterator* self) {
  if (self->iterator_object != NULL) {
    self->value = self->iterator_object;
    self->iterator_object = NULL;
    return (TRUE);
  }
  if (self->first_iterationP) {
    self->first_iterationP = FALSE;
  }
  else {
    self->iterator_cons_list = self->iterator_cons_list->rest;
  }
  self->value = self->iterator_cons_list->value;
  return (self->iterator_cons_list->non_emptyP());
}

void remove_interval(Taxonomy_Node* node, Interval* interval) {
  if ((interval->lower_bound == node->first_interval_lower_bound) &&
      (interval->upper_bound == node->first_interval_upper_bound)) {
    if (node->intervals->emptyP()) {
      {
        node->first_interval_lower_bound = -1;
        node->first_interval_upper_bound = -1;
      }
    }
    else {
      {
        node->first_interval_lower_bound = ((Interval*)(node->intervals->first()))->lower_bound;
        node->first_interval_upper_bound = ((Interval*)(node->intervals->first()))->upper_bound;
        node->intervals = node->intervals->rest;
      }
    }
  }
  else {
    node->intervals = node->intervals->remove(interval);
  }
}

void insert_interval(Taxonomy_Graph* graph, Taxonomy_Node* node, Interval* interval) {
  if (graph->incremental_modeP &&
      (node->first_interval_lower_bound == -1)) {
    {
      node->first_interval_lower_bound = interval->lower_bound;
      node->first_interval_upper_bound = interval->upper_bound;
    }
  }
  else {
    node->intervals = cons(interval, node->intervals);
  }
}

void add_interval_to_node(Taxonomy_Graph* graph, Interval* interval, Taxonomy_Node* node) {
  { Interval* existinginterval = NULL;
    Iterator* iter_001 = all_intervals(node);

    while (iter_001->nextP()) {
      {
        existinginterval = ((Interval*)(iter_001->value));
      }
      if (interval_subsumes_intervalP(existinginterval, interval)) {
        return;
      }
    }
  }
  { Interval* existinginterval = NULL;
    Iterator* iter_002 = all_intervals(node);

    while (iter_002->nextP()) {
      {
        existinginterval = ((Interval*)(iter_002->value));
      }
      if (interval_subsumes_intervalP(interval, existinginterval)) {
        remove_interval(node, existinginterval);
      }
      if (adjacentP(existinginterval, interval)) {
        remove_interval(node, existinginterval);
        insert_interval(graph, node, merge_intervals(existinginterval, interval));
        return;
      }
      if (adjacentP(interval, existinginterval)) {
        remove_interval(node, existinginterval);
        insert_interval(graph, node, merge_intervals(interval, existinginterval));
        return;
      }
    }
  }
  insert_interval(graph, node, interval);
}

Interval* create_next_postorder_interval(Taxonomy_Graph* graph) {
  { Interval* newinterval = new_interval();

    newinterval->lower_bound = graph->largest_postorder_number + 1;
    newinterval->upper_bound = graph->largest_postorder_number + oNUMBERING_INTERVALo;
    graph->largest_postorder_number = newinterval->upper_bound;
    return (newinterval);
  }
}

void propogate_foreign_interval(Taxonomy_Graph* graph, Interval* interval, Taxonomy_Node* node) {
  add_interval_to_node(graph, interval, node);
  { Taxonomy_Node* parent = NULL;
    Cons* iter_001 = node->parents;

    while (!nilP(iter_001)) {
      {
        parent = ((Taxonomy_Node*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      propogate_foreign_interval(graph, interval, parent);
    }
  }
}

void create_spanning_tree(Taxonomy_Graph* graph, Taxonomy_Node* node) {
  if (labeledP(node)) {
    return;
  }
  node->label = MARKER_LABEL;
  { Taxonomy_Node* maxparent = NULL;
    int maxparentvalue = NULL_INTEGER;

    { Taxonomy_Node* parent = NULL;
      Cons* iter_001 = node->parents;

      while (!nilP(iter_001)) {
        {
          parent = ((Taxonomy_Node*)(iter_001->value));
          iter_001 = iter_001->rest;
        }
        if ((maxparentvalue == NULL_INTEGER) ||
            (parent->total_ancestors > maxparentvalue)) {
          maxparent = parent;
          maxparentvalue = parent->total_ancestors;
        }
      }
    }
    { Taxonomy_Node* parent = NULL;
      Cons* iter_002 = node->parents;

      while (!nilP(iter_002)) {
        {
          parent = ((Taxonomy_Node*)(iter_002->value));
          iter_002 = iter_002->rest;
        }
        if (parent == maxparent) {
          parent->tree_children = cons(node, parent->tree_children);
        }
        else {
          graph->broken_links = cons(cons(parent, cons(node, NIL)), graph->broken_links);
        }
      }
    }
    { Taxonomy_Node* child = NULL;
      Cons* iter_003 = node->children;

      while (!nilP(iter_003)) {
        {
          child = ((Taxonomy_Node*)(iter_003->value));
          iter_003 = iter_003->rest;
        }
        create_spanning_tree(graph, child);
      }
    }
  }
}

void create_spanning_forest(Taxonomy_Graph* graph) {
  clear_graph(graph);
  { Taxonomy_Node* root = NULL;
    Cons* iter_001 = graph->roots;

    while (!nilP(iter_001)) {
      {
        root = ((Taxonomy_Node*)(iter_001->value));
        iter_001 = iter_001->rest;
      }
      create_spanning_tree(graph, root);
    }
  }
  create_initial_intervals(graph);
  { Cons* link = NIL;
    Cons* iter_002 = graph->broken_links;

    while (!nilP(iter_002)) {
      {
        link = ((Cons*)(iter_002->value));
        iter_002 = iter_002->rest;
      }
      propogate_foreign_interval(graph, ((Taxonomy_Node*)(link->second()))->initial_interval, ((Taxonomy_Node*)(link->first())));
    }
  }
  optimize_intervals(graph);
  graph->incremental_modeP = TRUE;
}

void startup_taxonomies() {
  { Module* old_OmoduleO_001 = oMODULEo;
    Context* old_OcontextO_001 = oCONTEXTo;

    { jump_buffer old_OexceptionhandleraddressO_001 = oEXCEPTIONHANDLERADDRESSo;

      oEXCEPTIONHANDLERADDRESSo = NULL;
      if ((!oPENDINGEXCEPTIONHANDLERpo) ||
          setup_long_jumpP(oEXCEPTIONHANDLERADDRESSo)) {
        {
          oMODULEo = oSTELLA_MODULEo;
          oCONTEXTo = oMODULEo;
          if (current_startup_time_phaseP(2)) {
            SYM_TAXONOMIES_oPOSTORDER_NUMBERo = ((Symbol*)(intern_rigid_symbol_wrt_module("*POSTORDER-NUMBER*", NULL, 0)));
          }
          if (current_startup_time_phaseP(6)) {
            finalize_classes();
          }
          if (current_startup_time_phaseP(7)) {
            { Method_Slot* method = define_method_from_stringified_source("HELP-COLLECT-ALL-NODES", "TAXONOMY-NODE", "(DEFUN (HELP-COLLECT-ALL-NODES (CONS OF TAXONOMY-NODE)) ((NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&help_collect_all_nodes));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-NODES", "TAXONOMY-GRAPH", "(DEFUN (ALL-NODES (CONS OF TAXONOMY-NODE)) ((GRAPH TAXONOMY-GRAPH)))");

              method->function_code = ((cpp_function_code)(&all_nodes));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-FIND-TAXONOMY-NODE", "TAXONOMY-NODE", "(DEFUN (HELP-FIND-TAXONOMY-NODE TAXONOMY-NODE) ((NODE TAXONOMY-NODE) (LABEL INTEGER)))");

              method->function_code = ((cpp_function_code)(&help_find_taxonomy_node));
            }
            { Method_Slot* method = define_method_from_stringified_source("FIND-TAXONOMY-NODE", "TAXONOMY-GRAPH", "(DEFUN (FIND-TAXONOMY-NODE TAXONOMY-NODE) ((GRAPH TAXONOMY-GRAPH) (LABEL INTEGER)))");

              method->function_code = ((cpp_function_code)(&find_taxonomy_node));
            }
            { Method_Slot* method = define_method_from_stringified_source("FTN", "TAXONOMY-GRAPH", "(DEFUN (FTN TAXONOMY-NODE) ((GRAPH TAXONOMY-GRAPH) (LABEL INTEGER)))");

              method->function_code = ((cpp_function_code)(&ftn));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-LINK", "TAXONOMY-GRAPH", "(DEFUN CREATE-LINK ((GRAPH TAXONOMY-GRAPH) (PARENT TAXONOMY-NODE) (CHILD TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&create_link));
            }
            { Method_Slot* method = define_method_from_stringified_source("LINK-NODES", "TAXONOMY-GRAPH", "(DEFUN LINK-NODES ((GRAPH TAXONOMY-GRAPH) (PARENT TAXONOMY-NODE) (CHILD TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&link_nodes));
            }
            { Method_Slot* method = define_method_from_stringified_source("COMPUTE-TOTAL-ANCESTORS", "TAXONOMY-NODE", "(DEFUN COMPUTE-TOTAL-ANCESTORS ((NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&compute_total_ancestors));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-NODE-TO-GRAPH", "TAXONOMY-GRAPH", "(DEFUN ADD-NODE-TO-GRAPH ((GRAPH TAXONOMY-GRAPH) (NODE TAXONOMY-NODE) (PARENT TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&add_node_to_graph));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-AND-INTERN-NODE", "TAXONOMY-GRAPH", "(DEFUN (CREATE-AND-INTERN-NODE TAXONOMY-NODE) ((GRAPH TAXONOMY-GRAPH) (PARENT TAXONOMY-NODE) (NATIVEOBJECT OBJECT)))");

              method->function_code = ((cpp_function_code)(&create_and_intern_node));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-NODE-FROM-GRAPH", "TAXONOMY-GRAPH", "(DEFUN REMOVE-NODE-FROM-GRAPH ((GRAPH TAXONOMY-GRAPH) (NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&remove_node_from_graph));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-LINK", "TAXONOMY-GRAPH", "(DEFUN REMOVE-LINK ((GRAPH TAXONOMY-GRAPH) (PARENT TAXONOMY-NODE) (CHILD TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&remove_link));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-GRAPH-TREE", "TAXONOMY-NODE", "(DEFUN PRINT-GRAPH-TREE ((NODE TAXONOMY-NODE) (INDENT INTEGER) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_graph_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-GRAPH", "TAXONOMY-GRAPH", "(DEFUN PRINT-GRAPH ((GRAPH TAXONOMY-GRAPH) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_graph));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-SPANNING-TREE", "TAXONOMY-NODE", "(DEFUN PRINT-SPANNING-TREE ((NODE TAXONOMY-NODE) (INDENT INTEGER) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_spanning_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("PRINT-FOREST", "TAXONOMY-GRAPH", "(DEFUN PRINT-FOREST ((GRAPH TAXONOMY-GRAPH) (STREAM OUTPUT-STREAM)))");

              method->function_code = ((cpp_function_code)(&print_forest));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-INTERVAL", "TAXONOMY-NODE", "(DEFUN (CREATE-INTERVAL INTERVAL) ((NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&create_interval));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-TREE-LABELS", "TAXONOMY-NODE", "(DEFUN CLEAR-TREE-LABELS ((NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&clear_tree_labels));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-TREE", "TAXONOMY-NODE", "(DEFUN CLEAR-TREE ((NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&clear_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("LABELED?", "TAXONOMY-NODE", "(DEFUN (LABELED? BOOLEAN) ((NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&labeledP));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-GRAPH-TREE", "TAXONOMY-NODE", "(DEFUN CLEAR-GRAPH-TREE ((NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&clear_graph_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CLEAR-GRAPH", "TAXONOMY-GRAPH", "(DEFUN CLEAR-GRAPH ((GRAPH TAXONOMY-GRAPH)))");

              method->function_code = ((cpp_function_code)(&clear_graph));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERVAL-SUBSUMES-INTEGER?", "INTERVAL", "(DEFUN (INTERVAL-SUBSUMES-INTEGER? BOOLEAN) ((INTERVAL INTERVAL) (N INTEGER)))");

              method->function_code = ((cpp_function_code)(&interval_subsumes_integerP));
            }
            { Method_Slot* method = define_method_from_stringified_source("TAXONOMY-NODE-SUBCLASS-OF?", "TAXONOMY-NODE", "(DEFUN (TAXONOMY-NODE-SUBCLASS-OF? BOOLEAN) ((DESCENDANT TAXONOMY-NODE) (ANCESTOR TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&taxonomy_node_subclass_ofP));
            }
            { Method_Slot* method = define_method_from_stringified_source("OPTIMIZE-INTERVALS", "TAXONOMY-GRAPH", "(DEFUN OPTIMIZE-INTERVALS ((GRAPH TAXONOMY-GRAPH)))");

              method->function_code = ((cpp_function_code)(&optimize_intervals));
            }
            { Method_Slot* method = define_method_from_stringified_source("SLOW-TAXONOMY-NODE-SUBCLASS-OF?", "TAXONOMY-NODE", "(DEFUN (SLOW-TAXONOMY-NODE-SUBCLASS-OF? BOOLEAN) ((DESCENDANT TAXONOMY-NODE) (ANCESTOR TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&slow_taxonomy_node_subclass_ofP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MOST-GENERAL-NODES", "CONS", "(DEFUN (MOST-GENERAL-NODES (CONS OF TAXONOMY-NODE)) ((NODES (CONS OF TAXONOMY-NODE))))");

              method->function_code = ((cpp_function_code)(&most_general_nodes));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-POSTORDER-LABEL-TREE", "TAXONOMY-NODE", "(DEFUN HELP-POSTORDER-LABEL-TREE ((NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&help_postorder_label_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("POSTORDER-LABEL-TREE", "TAXONOMY-NODE", "(DEFUN POSTORDER-LABEL-TREE ((ROOT TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&postorder_label_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("HELP-CREATE-TREE-INTERVALS", "TAXONOMY-NODE", "(DEFUN (HELP-CREATE-TREE-INTERVALS INTEGER) ((SELF TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&help_create_tree_intervals));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-INITIAL-INTERVALS", "TAXONOMY-GRAPH", "(DEFUN CREATE-INITIAL-INTERVALS ((GRAPH TAXONOMY-GRAPH)))");

              method->function_code = ((cpp_function_code)(&create_initial_intervals));
            }
            { Method_Slot* method = define_method_from_stringified_source("INTERVAL-SUBSUMES-INTERVAL?", "INTERVAL", "(DEFUN (INTERVAL-SUBSUMES-INTERVAL? BOOLEAN) ((PARENT INTERVAL) (CHILD INTERVAL)))");

              method->function_code = ((cpp_function_code)(&interval_subsumes_intervalP));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADJACENT?", "INTERVAL", "(DEFUN (ADJACENT? BOOLEAN) ((LEFTINTERVAL INTERVAL) (RIGHTINTERVAL INTERVAL)))");

              method->function_code = ((cpp_function_code)(&adjacentP));
            }
            { Method_Slot* method = define_method_from_stringified_source("MERGE-INTERVALS", "INTERVAL", "(DEFUN (MERGE-INTERVALS INTERVAL) ((LEFTINTERVAL INTERVAL) (RIGHTINTERVAL INTERVAL)))");

              method->function_code = ((cpp_function_code)(&merge_intervals));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALLOCATE-NEW-INTERVAL", "TAXONOMY-NODE", "(DEFUN (ALLOCATE-NEW-INTERVAL INTERVAL) ((PARENT TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&allocate_new_interval));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-INTERVALS", "TAXONOMY-NODE", "(DEFUN (ALL-INTERVALS (ITERATOR OF INTERVAL)) ((NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&all_intervals));
            }
            { Method_Slot* method = define_method_from_stringified_source("ALL-INTERVALS-NEXT?", "ALL-PURPOSE-ITERATOR", "(DEFUN (ALL-INTERVALS-NEXT? BOOLEAN) ((SELF ALL-PURPOSE-ITERATOR)))");

              method->function_code = ((cpp_function_code)(&all_intervals_nextP));
            }
            { Method_Slot* method = define_method_from_stringified_source("REMOVE-INTERVAL", "TAXONOMY-NODE", "(DEFUN REMOVE-INTERVAL ((NODE TAXONOMY-NODE) (INTERVAL INTERVAL)))");

              method->function_code = ((cpp_function_code)(&remove_interval));
            }
            { Method_Slot* method = define_method_from_stringified_source("INSERT-INTERVAL", "TAXONOMY-GRAPH", "(DEFUN INSERT-INTERVAL ((GRAPH TAXONOMY-GRAPH) (NODE TAXONOMY-NODE) (INTERVAL INTERVAL)))");

              method->function_code = ((cpp_function_code)(&insert_interval));
            }
            { Method_Slot* method = define_method_from_stringified_source("ADD-INTERVAL-TO-NODE", "TAXONOMY-GRAPH", "(DEFUN ADD-INTERVAL-TO-NODE ((GRAPH TAXONOMY-GRAPH) (INTERVAL INTERVAL) (NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&add_interval_to_node));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-NEXT-POSTORDER-INTERVAL", "TAXONOMY-GRAPH", "(DEFUN (CREATE-NEXT-POSTORDER-INTERVAL INTERVAL) ((GRAPH TAXONOMY-GRAPH)))");

              method->function_code = ((cpp_function_code)(&create_next_postorder_interval));
            }
            { Method_Slot* method = define_method_from_stringified_source("PROPOGATE-FOREIGN-INTERVAL", "TAXONOMY-GRAPH", "(DEFUN PROPOGATE-FOREIGN-INTERVAL ((GRAPH TAXONOMY-GRAPH) (INTERVAL INTERVAL) (NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&propogate_foreign_interval));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-SPANNING-TREE", "TAXONOMY-GRAPH", "(DEFUN CREATE-SPANNING-TREE ((GRAPH TAXONOMY-GRAPH) (NODE TAXONOMY-NODE)))");

              method->function_code = ((cpp_function_code)(&create_spanning_tree));
            }
            { Method_Slot* method = define_method_from_stringified_source("CREATE-SPANNING-FOREST", "TAXONOMY-GRAPH", "(DEFUN CREATE-SPANNING-FOREST ((GRAPH TAXONOMY-GRAPH)))");

              method->function_code = ((cpp_function_code)(&create_spanning_forest));
            }
            define_method_from_stringified_source("STARTUP-TAXONOMIES", NULL, "(DEFUN STARTUP-TAXONOMIES ())");
          }
          if (current_startup_time_phaseP(8)) {
            finalize_slots();
            cleanup_unfinalized_classes();
          }
          if (current_startup_time_phaseP(9)) {
            define_stella_global_variable_from_stringified_source("(DEFGLOBAL *NUMBERING-INTERVAL* INTEGER 100 :DOCUMENTATION \"Spacing between succesive nodes\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT MARKER-LABEL INTEGER -99 :DOCUMENTATION \"Dummy label used for marking a node\")");
            define_stella_global_variable_from_stringified_source("(DEFCONSTANT DELETED-LABEL INTEGER -99 :DOCUMENTATION \"Label used for marking deleted nodes\")");
            define_stella_global_variable_from_stringified_source("(DEFSPECIAL *POSTORDER-NUMBER* INTEGER NULL)");
            { Global_Variable* global = SYM_TAXONOMIES_oPOSTORDER_NUMBERo->lookup_global_variable();

              global->variable_get_value_code = ((cpp_function_code)(&read_Opostorder_numberO));
              global->variable_set_value_code = ((cpp_function_code)(&write_Opostorder_numberO));
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

