// contexts.hh

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
boolean cs_valueP(Object* self);
boolean subcontextP(Context* subcontext, Context* supercontext);
boolean discarded_contextP(Context* context);
Context* help_find_context_by_number(int number, List* siblings);
Context* find_context_by_number(int contextnumber);
Context* string_slowly_get_context(char* self);
Context* integer_slowly_get_context(int self);
Context* slowly_change_context(Context* self);
Context* cc(Cons* name);
Context* cc_evaluator_wrapper(Cons* arguments);
void print_context(Context* self, ostream* stream);
void help_print_context_tree(List* list, int level);
void print_context_tree(Context* root);
Object* access_in_context(Object* value, Context_Sensitive_Object* object, boolean dontinheritP);
Context* compute_nearest_context(Object* value, Context_Sensitive_Object* object, Context* context);
void help_insert_a_cs_value(Kv_Cons* kvcons, Object* newvalue, Context* target, boolean overwriteP);
Object* update_in_context(Object* oldvalue, Object* newvalue, Context_Sensitive_Object* object, boolean copytochildrenP);
void copy_current_value_to_children(Cs_Value* csvalue, Context_Sensitive_Object* object, Object* parentvalue);
void startup_contexts();

// Global declarations:
extern boolean oUNLINK_DISCARDED_CONTEXTS_ON_READpo;
extern boolean oUNLINK_DISCARDED_CONTEXTS_ON_WRITEpo;
extern boolean oCONTEXT_BACKTRACKING_MODEo;
extern Surrogate* SGT_CONTEXTS_CS_VALUE;
extern Symbol* SYM_CONTEXTS_EVALUATOR_WRAPPER_CODE;
extern Surrogate* SGT_CONTEXTS_MODULE;
extern Surrogate* SGT_CONTEXTS_WORLD;
extern Symbol* SYM_CONTEXTS_WORLD_NAME;

