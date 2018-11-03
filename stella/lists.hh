// lists.hh

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
boolean defined_listP(List* self);
boolean null_listP(List* self);
boolean terminate_listP(List* self);
boolean terminate_list_iteratorP(List_Iterator* self);
Object* search_plist(Cons* plist, Object* key);
Kv_Cons* kv_cons(Object* key, Object* value, Kv_Cons* rest);
void free_kv_cons(Kv_Cons* kvcons);
Kv_Cons* copy_kv_cons_list(Kv_Cons* kvconslist);
List* list(int values, ...);
Sequence* sequence(Surrogate* collectiontype, int values, ...);
Dictionary* dictionary(Surrogate* collectiontype, int alternatingkeysandvalues, ...);
void print_key_value_list(Key_Value_List* self, ostream* stream);
void print_cons_list(Cons* list, ostream* stream);
void startup_lists();

// Global declarations:
extern List* NIL_LIST;
extern Surrogate* SGT_LISTS_ABSTRACT_DICTIONARY_ITERATOR;
extern Symbol* SYM_LISTS_KEY;
extern Symbol* SYM_LISTS_KEY_SETTER;
extern Symbol* SYM_LISTS_SLOT_WRITER;
extern Surrogate* SGT_LISTS_ABSTRACT_ITERATOR;
extern Symbol* SYM_LISTS_VALUE;
extern Symbol* SYM_LISTS_VALUE_SETTER;
extern Symbol* SYM_LISTS_DELETED_OBJECTp;
extern Surrogate* SGT_LISTS_LIST;
extern Surrogate* SGT_LISTS_KEY_VALUE_LIST;
extern Surrogate* SGT_LISTS_PROPERTY_LIST;

