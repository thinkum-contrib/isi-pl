// conses.hh

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
boolean nilP(Object* x);
void free_cons_list(Cons* self);
Cons* cons(Object* value, Cons* rest);
Cons* permanent_cons(Object* value, Cons* rest);
Cons* local_cons(Object* value, Cons* rest);
Cons* last_cons(Cons* self);
boolean terminate_cons_iteratorP(Cons_Iterator* self);
void add_cons_to_end_of_cons_list(Cons* self, Cons* lastcons);
boolean but_last_nextP(All_Purpose_Iterator* self);
Cons* transient_cons(Object* value, Object* rest);
Cons* yield_cons_list_of(Object* self);
Cons* copy_cons_list(Cons* self);
Cons* permanent_copy_cons_list(Cons* self);
Cons* cons_list(int values, ...);
Cons* listO(int values, ...);
Cons* append(Cons* conslist1, Cons* conslist2);
Cons* help_sort_cons_list(Cons* list, int length, cpp_function_code predicate);
Cons* merge_cons_lists(Cons* list1, Cons* list2, cpp_function_code predicate);
boolean generalized_symbol_less_thanP(Generalized_Symbol* x, Generalized_Symbol* y);
boolean wrapped_integer_less_thanP(Integer_Wrapper* x, Integer_Wrapper* y);
boolean wrapped_float_less_thanP(Float_Wrapper* x, Float_Wrapper* y);
boolean wrapped_string_less_thanP(String_Wrapper* x, String_Wrapper* y);
cpp_function_code choose_sort_predicate(Cons* self);
boolean search_cons_treeP(Object* tree, Object* value);
Object* copy_cons_tree(Object* self);
void free_cons_tree(Object* self);
boolean equal_cons_treesP(Object* tree1, Object* tree2);
Object* substitute_cons_tree(Object* tree, Object* newvalue, Object* oldvalue);
boolean read_OprintprettyPO();
boolean write_OprintprettyPO(boolean value);
boolean read_OprintreadablyPO();
boolean write_OprintreadablyPO(boolean value);
void print_cons(Cons* tree, ostream* stream, char* lparen, char* rparen);
void pprint_cons(Cons* tree, ostream* stream, char* lparen, char* rparen);
boolean read_OprintprettycodePO();
boolean write_OprintprettycodePO(boolean value);
void print_stella_code(Object* tree, ostream* stream);
void print_stella_definition(Object* tree, ostream* stream);
int tree_size(Object* self);
boolean read_OdepthexceededPO();
boolean write_OdepthexceededPO(boolean value);
int safely_compute_tree_size(Cons* tree, int depthcount, int cutoff);
int safe_tree_size(Cons* tree, char*& return1);
void startup_conses();

// Global declarations:
extern Cons* NIL;
extern Surrogate* SGT_CONSES_ABSTRACT_ITERATOR;
extern Symbol* SYM_CONSES_VALUE;
extern Symbol* SYM_CONSES_VALUE_SETTER;
extern Symbol* SYM_CONSES_SLOT_WRITER;
extern Surrogate* SGT_CONSES_GENERALIZED_SYMBOL;
extern boolean oPRINTPRETTYpo;
extern Symbol* SYM_CONSES_oPRINTPRETTYpo;
extern boolean oPRINTREADABLYpo;
extern Symbol* SYM_CONSES_oPRINTREADABLYpo;
extern Symbol* ELIPSIS;
extern boolean oPRINTPRETTYCODEpo;
extern Symbol* SYM_CONSES_oPRINTPRETTYCODEpo;
extern boolean oDEPTHEXCEEDEDpo;
extern Symbol* SYM_CONSES_oDEPTHEXCEEDEDpo;
extern int oDEPTHCUTOFFo;

