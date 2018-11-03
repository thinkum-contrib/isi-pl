// foreach.hh

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
Cons* extract_one_in_clause(Cons* tail, Cons*& return1);
Cons* extract_one_generator_term(Cons* tail, Cons*& return1);
Cons* extract_generators_clause(Cons* tail, Cons*& return1);
Object* extract_option_and_residue(Symbol* option, Cons* tail, Cons*& return1);
Cons* extract_do_clause(Cons* tail, Cons*& return1);
Cons* foreach_to_prefix_foreach_tree(Cons* foreachtree);
Cons* walk_foreach_tree(Cons* tree, Standard_Object*& return1);
Object* walk_collection_tree(Object* tree, boolean dontoptimizeP, Standard_Object*& return1);
Cons* yield_in_cursor_clauses(Cons* intree, boolean dontoptimizeP, Cons*& return1, Object*& return2);
Cons* yield_in_cursor_clauses_for_general_collection(Object* collectiontree, Standard_Object* collectiontype, Symbol* keyvar, Symbol* valuevar, Cons*& return1, Object*& return2);
Cons* yield_in_cursor_clauses_for_integer_interval(Cons* collectiontree, Standard_Object* collectiontype, Symbol* keyvar, Symbol* valuevar, Cons*& return1, Object*& return2);
Cons* yield_in_cursor_clauses_for_vector(Object* collectiontree, Standard_Object* collectiontype, Symbol* keyvar, Symbol* valuevar, Cons*& return1, Object*& return2);
Cons* yield_on_cursor_clauses(Cons* ontree, Cons*& return1, Object*& return2);
Cons* collect_cursor_clauses(Cons* cursorstree, boolean dontoptimizeP, Cons*& return1, Object*& return2);
Cons* walk_cursors_tree(Cons* cursorstree, boolean dontoptimizeP, Cons*& return1, Object*& return2);
Cons* yield_collect_into_list_code(Symbol* collectvariable, Object* intovariable, Object* collecttree);
Cons* yield_collect_into_cons_code(Symbol* collectvariable, Object* intovariable, Object* collecttree);
Cons* yield_collect_code(Symbol* collectvariable, Object* intovariable, Object* collecttree);
Cons* walk_prefix_collect_into_tree(Cons* collectintotree, Cons* iterators, Cons* valuebindings, Cons* docode, Cons*& return1);
Cons* wrap_where_test(Object* wheretest, Cons* actions);
Cons* walk_prefix_foreach_body(Cons* iteratorclauses, Cons* valueclauses, Cons* wheretest, Cons* doactions);
Cons* walk_prefix_foreach_tree(Cons* tree, Standard_Object*& return1);
Cons* walk_exists_tree(Cons* tree, Standard_Object*& return1);
Cons* walk_forall_tree(Cons* tree, Standard_Object*& return1);
Cons* walk_some_tree(Cons* tree, Standard_Object*& return1);
Cons* extract_setof_nested_iterator_tree(Cons* iteratorclauses);
Symbol* yield_setof_next_function_name(Cons* valueclauses, Cons* wheretest);
Cons* walk_setof_tree(Cons* tree, Standard_Object*& return1);
void startup_foreach();

// Global declarations:
extern Symbol* SYM_FOREACH_AS;
extern Symbol* SYM_FOREACH_COMMA;
extern Symbol* SYM_FOREACH_DO;
extern Symbol* SYM_FOREACH_COLLECT;
extern Surrogate* SGT_FOREACH_VOID;
extern Symbol* SYM_FOREACH_WHERE;
extern Symbol* SYM_FOREACH_INTO;
extern Symbol* SYM_FOREACH_COLLECT_INTO;
extern Symbol* SYM_FOREACH_PREFIX_FOREACH;
extern Symbol* SYM_FOREACH_IN;
extern Symbol* SYM_FOREACH_X;
extern Symbol* SYM_FOREACH_NIL;
extern Symbol* SYM_FOREACH_FOREACH;
extern Symbol* SYM_FOREACH_EXISTS;
extern Symbol* SYM_FOREACH_FORALL;
extern Symbol* SYM_FOREACH_SOME;
extern Symbol* SYM_FOREACH_SETOF;
extern Symbol* SYM_FOREACH_SET_OF;
extern Symbol* SYM_FOREACH_INTERVAL;
extern Surrogate* SGT_FOREACH_INTEGER_INTERVAL;
extern Surrogate* SGT_FOREACH_ABSTRACT_ITERATOR;
extern Symbol* SYM_FOREACH_ALLOCATE_ITERATOR;
extern Symbol* SYM_FOREACH_FALSE;
extern Surrogate* SGT_FOREACH_STRING;
extern Surrogate* SGT_FOREACH_VECTOR;
extern Surrogate* SGT_FOREACH_LIST;
extern Surrogate* SGT_FOREACH_CONS;
extern Symbol* SYM_FOREACH_THE_CONS_LIST;
extern Surrogate* SGT_FOREACH_KEY_VALUE_LIST;
extern Surrogate* SGT_FOREACH_KV_CONS;
extern Symbol* SYM_FOREACH_THE_KV_LIST;
extern Surrogate* SGT_FOREACH_PROPERTY_LIST;
extern Symbol* SYM_FOREACH_THE_PLIST;
extern Symbol* SYM_FOREACH_KEY;
extern Symbol* SYM_FOREACH_VALUE;
extern Symbol* SYM_FOREACH_SETQ;
extern Symbol* SYM_FOREACH_REST;
extern Symbol* SYM_FOREACH_NOT;
extern Symbol* SYM_FOREACH_NILp;
extern Symbol* SYM_FOREACH_DEFINEDp;
extern Symbol* SYM_FOREACH_NEXTp;
extern Symbol* SYM_FOREACH_PROGN;
extern Symbol* SYM_FOREACH_ANY_VALUE;
extern Symbol* SYM_FOREACH_ANY_KEY;
extern Symbol* SYM_FOREACH_NULL;
extern Symbol* SYM_FOREACH_NULL_INTEGER;
extern Surrogate* SGT_FOREACH_NUMBER_WRAPPER;
extern Surrogate* SGT_FOREACH_INTEGER;
extern Surrogate* SGT_FOREACH_BOOLEAN;
extern Symbol* SYM_FOREACH_NULLp;
extern Symbol* SYM_FOREACH_ii;
extern Symbol* SYM_FOREACH_TRUE;
extern Symbol* SYM_FOREACH_le;
extern Symbol* SYM_FOREACH_OR;
extern Symbol* SYM_FOREACH_LENGTH;
extern Symbol* SYM_FOREACH_NTH;
extern Surrogate* SGT_FOREACH_CHARACTER;
extern Symbol* SYM_FOREACH_l;
extern Symbol* SYM_FOREACH_ON;
extern Symbol* SYM_FOREACH_AND;
extern Symbol* SYM_FOREACH_IF;
extern Symbol* SYM_FOREACH_PERMANENT_CONS;
extern Symbol* SYM_FOREACH_EMPTYp;
extern Symbol* SYM_FOREACH_SETF;
extern Symbol* SYM_FOREACH_ADD_CONS_TO_END_OF_CONS_LIST;
extern Symbol* SYM_FOREACH_CONS;
extern Surrogate* SGT_FOREACH_UNKNOWN;
extern Symbol* SYM_FOREACH_COND;
extern Symbol* SYM_FOREACH_CONSp;
extern Symbol* SYM_FOREACH_OTHERWISE;
extern Symbol* SYM_FOREACH_WHEN;
extern Symbol* SYM_FOREACH_SYS_FOREACH;
extern Symbol* SYM_FOREACH_VRLET;
extern Symbol* SYM_FOREACH_BREAK;
extern Symbol* SYM_FOREACH_ALWAYS;
extern Symbol* SYM_FOREACH_DEFUN;
extern Symbol* SYM_FOREACH_BOOLEAN;
extern Symbol* SYM_FOREACH_SELF;
extern Symbol* SYM_FOREACH_ALL_PURPOSE_ITERATOR;
extern Symbol* SYM_FOREACH_LET;
extern Symbol* SYM_FOREACH_NESTEDITERATOR;
extern Symbol* SYM_FOREACH_ITERATOR_NESTED_ITERATOR;
extern Symbol* SYM_FOREACH_WHILE;
extern Symbol* SYM_FOREACH_RETURN;
extern Symbol* SYM_FOREACH_NEW;
extern Symbol* SYM_FOREACH_ITERATOR_NEXT_CODE;
extern Symbol* SYM_FOREACH_THE_CODE;
extern Keyword* KWD_FOREACH_FUNCTION;
extern Surrogate* SGT_FOREACH_ALL_PURPOSE_ITERATOR;

