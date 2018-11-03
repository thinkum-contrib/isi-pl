// caches.hh

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


// Function signatures:
World* lookup_inference_cache(Module* module, Keyword* kind);
World* create_inference_cache(Module* module, Keyword* kind);
World* get_inference_cache(Module* module, Keyword* kind);
void destroy_inference_cache(World* world);
void check_for_out_of_date_inference_cache();
Context* get_query_context();
Context* get_top_level_update_context();
void inherit_cached_inferences(World* fromworld, World* toworld);
void inherit_truth_value_update(Proposition* proposition, World* toworld);
void inherit_variable_value_update(Skolem* skolem, World* toworld);
void do_propagate_constraints(Context* context);
void propagate_constraints(Cons* name);
void propagate_constraints_evaluator_wrapper(Cons* arguments);
void do_enable_constraint_propagation(Context* self);
void startup_caches();

// Global declarations:
extern Keyword* KWD_CACHES_STRICT;
extern Symbol* SYM_CACHES_STRICT_INFERENCE_CACHE;
extern Keyword* KWD_CACHES_DEFAULT;
extern Symbol* SYM_CACHES_DEFAULT_INFERENCE_CACHE;
extern Symbol* SYM_CACHES_MONOTONICp;
extern Symbol* SYM_CACHES_UP_TO_DATE_INFERENCESp;
extern Surrogate* SGT_CACHES_CLASH;
extern Symbol* SYM_CACHES_EVALUATOR_WRAPPER_CODE;
extern Surrogate* SGT_CACHES_MODULE;
extern Surrogate* SGT_CACHES_WORLD;

