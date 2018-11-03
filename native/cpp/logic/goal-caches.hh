//  -*- Mode: C++ -*-

// goal-caches.hh

/*
 +--------------------------------------------------------------------------+
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
 +--------------------------------------------------------------------------+
*/


namespace logic {
  using namespace stella;

// Class definitions:
class GoalCache : public StandardObject {
// Cache of output bindings derived for a particular goal
// and set of input bindings.
public:
  List* cachedBindings;
  int timestamp;
  Proposition* proposition;
  boolean reversePolarityP;
  Context* cacheContext;
public:
  virtual Surrogate* primaryType();
};

class AtomicGoalCache : public StandardObject {
// Cache data structure to store the result of proving an atomic
// and possibly open `proposition' relative to a set of variable `bindings'.
public:
  Context* goalContext;
  int timestamp;
  TruthValue* truthValue;
  boolean reversePolarityP;
  Proposition* proposition;
  Cons* bindings;
  Justification* justification;
  double positiveScore;
  double negativeScore;
  AtomicGoalCache* previous;
  AtomicGoalCache* next;
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
};

class AtomicGoalCacheIterator : public Iterator {
public:
  ControlFrame* goal;
  AtomicGoalCache* cacheList;
public:
  virtual Surrogate* primaryType();
  virtual boolean nextP();
};


// Global declarations:
extern boolean oCACHE_SUCCEEDED_GOALSpo;
extern boolean oCACHE_FAILED_GOALSpo;
extern int oCACHE_GOAL_QUANTUMo;
extern Vector* oSUCCEEDED_GOALS_CACHEo;
extern Vector* oFAILED_GOALS_CACHEo;
extern DECLARE_STELLA_SPECIAL(oUNIFICATION_VECTOR_1o, Vector* );
extern DECLARE_STELLA_SPECIAL(oUNIFICATION_VECTOR_2o, Vector* );

// Function signatures:
GoalCache* newGoalCache();
Object* accessGoalCacheSlotValue(GoalCache* self, Symbol* slotname, Object* value, boolean setvalueP);
void traceGoalCache(char* string, ControlFrame* frame);
void removeObsoleteGoalCaches(KeyValueList* table);
Cons* yieldGoalBindings(Proposition* goal);
KeyValueList* findGoalCacheTable(Proposition* goal);
boolean createGoalCacheP(ControlFrame* frame);
GoalCache* lookupGoalCache(KeyValueList* table);
GoalCache* findGoalCache(ControlFrame* frame);
void updateGoalCache(ControlFrame* frame, boolean successP);
Cons* yieldRelativeGoalBindings(ControlFrame* frame);
Keyword* continueCachedBindingsProof(ControlFrame* frame, Keyword* lastmove);
boolean topLevelQueryContextP(Context* self);
boolean cacheQueryResultsP();
char* toggleGoalCaching();
AtomicGoalCache* newAtomicGoalCache();
Object* accessAtomicGoalCacheSlotValue(AtomicGoalCache* self, Symbol* slotname, Object* value, boolean setvalueP);
void printAtomicGoalCache(AtomicGoalCache* self, std::ostream* stream);
void clearQueryResultsCache();
void printQueryResultsCache(int limit);
int succeededGoalIndex(ControlFrame* frame);
int failedGoalIndex(ControlFrame* frame);
int goalHashCode(ControlFrame* frame);
int hashUnboundGoalVariable(PatternVariable* var, Vector* arguments, int code);
int hashGoalArgument(Object* arg, int code);
Surrogate* cachedGoalOperator(Proposition* goal);
AtomicGoalCache* getGoalCacheList(Proposition* goal);
AtomicGoalCache* setGoalCacheList(Proposition* goal, AtomicGoalCache* firstcache);
AtomicGoalCache* createAtomicGoalCache(ControlFrame* frame, AtomicGoalCache* cache, boolean successP);
boolean cacheMatchesGoalP(AtomicGoalCache* cache, ControlFrame* goal, boolean successP, Keyword* mode);
boolean goalInstantiatesCacheP(ControlFrame* goal, AtomicGoalCache* cache, boolean successP);
boolean cacheInstantiatesGoalP(AtomicGoalCache* cache, ControlFrame* goal, boolean successP);
void dontCacheGoalFailureBetweenFrames(ControlFrame* topframe, ControlFrame* bottomframe);
void cacheGoal(ControlFrame* frame, boolean successP, boolean keepframeP, int clockticks);
AtomicGoalCache* findCachedGoal(ControlFrame* frame, Keyword* successorfailure);
AtomicGoalCacheIterator* newAtomicGoalCacheIterator();
Object* accessAtomicGoalCacheIteratorSlotValue(AtomicGoalCacheIterator* self, Symbol* slotname, Object* value, boolean setvalueP);
AtomicGoalCacheIterator* allCachedPropositions(ControlFrame* goal);
void helpStartupGoalCaches1();
void startupGoalCaches();

// Auxiliary global declarations:
extern Surrogate* SGT_GOAL_CACHES_LOGIC_GOAL_CACHE;
extern Symbol* SYM_GOAL_CACHES_LOGIC_CACHED_BINDINGS;
extern Symbol* SYM_GOAL_CACHES_LOGIC_TIMESTAMP;
extern Symbol* SYM_GOAL_CACHES_LOGIC_PROPOSITION;
extern Symbol* SYM_GOAL_CACHES_LOGIC_REVERSE_POLARITYp;
extern Symbol* SYM_GOAL_CACHES_LOGIC_CACHE_CONTEXT;
extern Keyword* KWD_GOAL_CACHES_GOAL_CACHES;
extern Symbol* SYM_GOAL_CACHES_LOGIC_GOAL_CACHE_TABLE;
extern Keyword* KWD_GOAL_CACHES_ISA;
extern Keyword* KWD_GOAL_CACHES_PREDICATE;
extern Keyword* KWD_GOAL_CACHES_FUNCTION;
extern Symbol* SYM_GOAL_CACHES_LOGIC_NEGATED_GOAL_CACHE_TABLE;
extern Surrogate* SGT_GOAL_CACHES_STELLA_SURROGATE;
extern Symbol* SYM_GOAL_CACHES_LOGIC_GOAL_CACHE;
extern Keyword* KWD_GOAL_CACHES_DUPLICATE_GOALS_WITH_CACHING;
extern Symbol* SYM_GOAL_CACHES_LOGIC_CACHED_BINDINGS_ITERATOR;
extern Keyword* KWD_GOAL_CACHES_FAILURE;
extern Keyword* KWD_GOAL_CACHES_FINAL_SUCCESS;
extern Keyword* KWD_GOAL_CACHES_CONTINUING_SUCCESS;
extern Symbol* SYM_GOAL_CACHES_LOGIC_INFERENCE_CACHE_OF;
extern Keyword* KWD_GOAL_CACHES_DUPLICATE_GOALS;
extern Surrogate* SGT_GOAL_CACHES_LOGIC_ATOMIC_GOAL_CACHE;
extern Symbol* SYM_GOAL_CACHES_LOGIC_GOAL_CONTEXT;
extern Symbol* SYM_GOAL_CACHES_LOGIC_TRUTH_VALUE;
extern Symbol* SYM_GOAL_CACHES_LOGIC_BINDINGS;
extern Symbol* SYM_GOAL_CACHES_LOGIC_JUSTIFICATION;
extern Symbol* SYM_GOAL_CACHES_LOGIC_POSITIVE_SCORE;
extern Symbol* SYM_GOAL_CACHES_LOGIC_NEGATIVE_SCORE;
extern Symbol* SYM_GOAL_CACHES_LOGIC_PREVIOUS;
extern Symbol* SYM_GOAL_CACHES_STELLA_NEXT;
extern Keyword* KWD_GOAL_CACHES_REALISTIC;
extern Surrogate* SGT_GOAL_CACHES_LOGIC_PATTERN_VARIABLE;
extern Surrogate* SGT_GOAL_CACHES_LOGIC_SKOLEM;
extern Surrogate* SGT_GOAL_CACHES_LOGIC_LOGIC_OBJECT;
extern Symbol* SYM_GOAL_CACHES_LOGIC_GOAL_CACHE_LIST;
extern Keyword* KWD_GOAL_CACHES_GOAL_INSTANTIATES_CACHE;
extern Keyword* KWD_GOAL_CACHES_CACHE_INSTANTIATES_GOAL;
extern Keyword* KWD_GOAL_CACHES_ATOMIC_GOAL;
extern Surrogate* SGT_GOAL_CACHES_PL_KERNEL_KB_FRAME_PREDICATE;
extern Keyword* KWD_GOAL_CACHES_EXECUTE_QUERY;
extern Symbol* SYM_GOAL_CACHES_LOGIC_CHECK_FOR_CACHED_GOALSp;
extern Keyword* KWD_GOAL_CACHES_SUCCESS;
extern Surrogate* SGT_GOAL_CACHES_LOGIC_ATOMIC_GOAL_CACHE_ITERATOR;
extern Symbol* SYM_GOAL_CACHES_LOGIC_GOAL;
extern Symbol* SYM_GOAL_CACHES_LOGIC_CACHE_LIST;
extern Symbol* SYM_GOAL_CACHES_LOGIC_STARTUP_GOAL_CACHES;
extern Symbol* SYM_GOAL_CACHES_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace logic
