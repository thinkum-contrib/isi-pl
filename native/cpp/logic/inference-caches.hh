//  -*- Mode: C++ -*-

// inference-caches.hh

/*--------------------------------------------------------------------------+
 |                                                                          |
 |  COPYRIGHT (C) UNIVERSITY OF SOUTHERN CALIFORNIA, 1997-2003              |
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



namespace logic {
  using namespace stella;

// Global declarations:
extern DECLARE_STELLA_SPECIAL(oINVISIBLEASSERTIONpo, boolean );

// Function signatures:
boolean worldStateP(Context* self);
Context* getWorldState(Context* self);
World* lookupInferenceCache(Context* context, Keyword* kind);
void initializeInferenceWorld(World* world);
World* createInferenceCache(Context* context, Keyword* kind);
World* getInferenceCache(Context* context, Keyword* kind);
void destroyInferenceCache(Context* context, Keyword* kind);
void unlinkInferenceCache(World* self);
void destroyInferenceCaches(Context* context);
boolean metaPropositionP(Proposition* proposition);
void handleOutOfDateInferenceCache(Keyword* assertorretract, Proposition* proposition);
World* bestInferenceCache(Context* context);
Context* getQueryContext();
Context* getPropertyTestContext();
Context* getInferableTestContext();
Context* getTopLevelUpdateContext();
World* lookupConstraintPropagationWorld(Context* self);
void inheritCachedInferences(World* fromworld, World* toworld);
void inheritTruthValueUpdate(Proposition* proposition, World* toworld);
void inheritVariableValueUpdate(Skolem* skolem, World* toworld);
void callPropagateConstraints(Context* context);
void propagateConstraints(Cons* name);
void propagateConstraintsEvaluatorWrapper(Cons* arguments);
void repropagateConstraints(Cons* name);
void repropagateConstraintsEvaluatorWrapper(Cons* arguments);
void callRunForwardRules(Module* module, boolean forceP);
void runForwardRules(Object* moduleref, Cons* force);
void runForwardRulesEvaluatorWrapper(Cons* arguments);
void startupInferenceCaches();

// Auxiliary global declarations:
extern Surrogate* SGT_INFERENCE_CACHES_STELLA_WORLD;
extern Symbol* SYM_INFERENCE_CACHES_LOGIC_INFERENCE_CACHE_OF;
extern Symbol* SYM_INFERENCE_CACHES_LOGIC_MONOTONICp;
extern Keyword* KWD_INFERENCE_CACHES_JUST_IN_TIME;
extern Symbol* SYM_INFERENCE_CACHES_LOGIC_JUST_IN_TIME_INFERENCE_CACHE;
extern Keyword* KWD_INFERENCE_CACHES_META;
extern Symbol* SYM_INFERENCE_CACHES_LOGIC_META_INFERENCE_CACHE;
extern Keyword* KWD_INFERENCE_CACHES_TMS;
extern Symbol* SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINED_INFERENCE_CACHE;
extern Symbol* SYM_INFERENCE_CACHES_LOGIC_EVALUATION_STATE_TABLE;
extern Symbol* SYM_INFERENCE_CACHES_LOGIC_EVALUATION_QUEUE;
extern Symbol* SYM_INFERENCE_CACHES_LOGIC_UP_TO_DATE_INFERENCESp;
extern Surrogate* SGT_INFERENCE_CACHES_LOGIC_DESCRIPTION;
extern Surrogate* SGT_INFERENCE_CACHES_STELLA_LITERAL_WRAPPER;
extern Surrogate* SGT_INFERENCE_CACHES_PL_KERNEL_KB_HIDDEN_RELATION;
extern Keyword* KWD_INFERENCE_CACHES_RETRACT;
extern Symbol* SYM_INFERENCE_CACHES_LOGIC_TRUTH_MAINTAINEDp;
extern Keyword* KWD_INFERENCE_CACHES_PERFORMANCE_CLUES;
extern Keyword* KWD_INFERENCE_CACHES_FORCE;
extern Symbol* SYM_INFERENCE_CACHES_LOGIC_STARTUP_INFERENCE_CACHES;
extern Symbol* SYM_INFERENCE_CACHES_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
