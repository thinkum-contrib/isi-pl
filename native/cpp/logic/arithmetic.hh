//  -*- Mode: C++ -*-

// arithmetic.hh

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


namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

// Class definitions:
class IntegerInterval : public Thing {
// An interval of integers
public:
  int intervalLowerBound;
  int intervalUpperBound;
public:
  virtual Surrogate* primaryType();
};

class IntervalCache : public Thing {
public:
  Context* homeContext;
  LogicObject* intervalMember;
public:
  virtual Surrogate* primaryType();
  virtual void propagateInequalityToIntervalCache(Object* value, Surrogate* operatoR);
  virtual void evaluateTighterInterval();
};

class IntegerIntervalCache : public IntervalCache {
public:
  int lowerBound;
  int upperBound;
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
  virtual void propagateInequalityToIntervalCache(Object* value, Surrogate* operatoR);
  virtual void evaluateTighterInterval();
};

class FloatIntervalCache : public IntervalCache {
public:
  double lowerBound;
  double upperBound;
  boolean strictLowerBoundP;
  boolean strictUpperBoundP;
public:
  virtual void printObject(std::ostream* stream);
  virtual Surrogate* primaryType();
  virtual void propagateInequalityToIntervalCache(Object* value, Surrogate* operatoR);
  virtual void evaluateTighterInterval();
};



// Function signatures:
boolean arithmeticEqualTest(NumberWrapper* x, NumberWrapper* y);
boolean arithmeticLessTest(NumberWrapper* x, NumberWrapper* y);
boolean arithmeticGreaterTest(NumberWrapper* x, NumberWrapper* y);
NumberWrapper* plusComputation(NumberWrapper* x, NumberWrapper* y);
NumberWrapper* minusComputation(NumberWrapper* x, NumberWrapper* y);
NumberWrapper* timesComputation(NumberWrapper* x, NumberWrapper* y);
NumberWrapper* divideComputation(NumberWrapper* x, NumberWrapper* y);
NumberWrapper* sqrtComputation(NumberWrapper* x);
Object* plusConstraint(IntegerWrapper* missingArgument, NumberWrapper* x1, NumberWrapper* x2, NumberWrapper* x3);
Object* minusConstraint(IntegerWrapper* missingArgument, NumberWrapper* x1, NumberWrapper* x2, NumberWrapper* x3);
Object* timesConstraint(IntegerWrapper* missingArgument, NumberWrapper* x1, NumberWrapper* x2, NumberWrapper* x3);
Object* divideConstraint(IntegerWrapper* missingArgument, NumberWrapper* x1, NumberWrapper* x2, NumberWrapper* x3);
Object* sqrtConstraint(IntegerWrapper* missingArgument, NumberWrapper* x1, NumberWrapper* x2);
IntegerInterval* newIntegerInterval();
Object* accessIntegerIntervalSlotValue(IntegerInterval* self, Symbol* slotname, Object* value, boolean setvalueP);
IntervalCache* newIntervalCache();
Object* accessIntervalCacheSlotValue(IntervalCache* self, Symbol* slotname, Object* value, boolean setvalueP);
IntegerIntervalCache* newIntegerIntervalCache();
Object* accessIntegerIntervalCacheSlotValue(IntegerIntervalCache* self, Symbol* slotname, Object* value, boolean setvalueP);
FloatIntervalCache* newFloatIntervalCache();
Object* accessFloatIntervalCacheSlotValue(FloatIntervalCache* self, Symbol* slotname, Object* value, boolean setvalueP);
IntervalCache* createIntervalCache(LogicObject* intervalmember, boolean integerP);
IntervalCache* getIntervalCache(LogicObject* self);
int coerceIntervalBoundToInteger(Object* self, Surrogate* operatoR);
int integerDcoerceIntervalBoundToInteger(IntegerWrapper* self, Surrogate* operatoR);
int floatDcoerceIntervalBoundToInteger(FloatWrapper* self, Surrogate* operatoR);
void signalIntervalClash(IntervalCache* interval);
void evaluateAdjacentInequalities(LogicObject* self);
Surrogate* inverseInequalityOperator(Surrogate* operatoR);
void unifyIntervalCaches(IntervalCache* cache1, IntervalCache* cache2, Surrogate* operatoR);
NumberWrapper* accessIntervalBounds(Object* x, Keyword* lowerorupper, boolean& _Return1);
NumberWrapper* accessIntervalCacheBounds(IntervalCache* intervalcache, Keyword* lowerorupper, boolean& _Return1);
boolean compareIntervalBoundsP(Surrogate* relation, NumberWrapper* x, NumberWrapper* y);
boolean nullNumberP(NumberWrapper* self);
boolean satisfiesIntervalBoundsP(Object* object, NumberWrapper* value);
Keyword* lessSpecialist(ControlFrame* frame, Keyword* lastmove);
Keyword* greaterSpecialist(ControlFrame* frame, Keyword* lastmove);
void inequalityEvaluator(Proposition* self);
Object* concatenateConstraint(IntegerWrapper* missingArgument, StringWrapper* x1, StringWrapper* x2, StringWrapper* x3);
Keyword* subsequenceSpecialist(ControlFrame* frame, Keyword* lastmove);
IntegerWrapper* stringMatchComputation(Object* pattern, Object* x, Object* start, Object* end);
IntegerWrapper* lengthComputation(Object* x);
void helpStartupArithmetic1();
void startupArithmetic();

// Auxiliary global declarations:
extern Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_INTEGER_INTERVAL;
extern Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_LOWER_BOUND;
extern Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_UPPER_BOUND;
extern Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_INTERVAL_CACHE;
extern Symbol* SYM_ARITHMETIC_STELLA_HOME_CONTEXT;
extern Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_MEMBER;
extern Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_INTEGER_INTERVAL_CACHE;
extern Symbol* SYM_ARITHMETIC_STELLA_LOWER_BOUND;
extern Symbol* SYM_ARITHMETIC_STELLA_UPPER_BOUND;
extern Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_FLOAT_INTERVAL_CACHE;
extern Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_STRICT_LOWER_BOUNDp;
extern Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_STRICT_UPPER_BOUNDp;
extern Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_INTERVAL_CACHE_OF;
extern Surrogate* SGT_ARITHMETIC_STELLA_INTEGER;
extern Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_g;
extern Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_ge;
extern Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_l;
extern Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_el;
extern Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_INEQUALITY;
extern Surrogate* SGT_ARITHMETIC_LOGIC_LOGIC_OBJECT;
extern Keyword* KWD_ARITHMETIC_PROPAGATE;
extern Surrogate* SGT_ARITHMETIC_STELLA_NUMBER_WRAPPER;
extern Keyword* KWD_ARITHMETIC_LOWER_BOUND;
extern Keyword* KWD_ARITHMETIC_UPPER_BOUND;
extern Keyword* KWD_ARITHMETIC_TERMINAL_FAILURE;
extern Surrogate* SGT_ARITHMETIC_STELLA_INTEGER_WRAPPER;
extern Keyword* KWD_ARITHMETIC_FINAL_SUCCESS;
extern Keyword* KWD_ARITHMETIC_FAILURE;
extern Symbol* SYM_ARITHMETIC_STELLA_ITERATOR;
extern Keyword* KWD_ARITHMETIC_CONTINUING_SUCCESS;
extern Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_STARTUP_ARITHMETIC;
extern Symbol* SYM_ARITHMETIC_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace pl_kernel_kb
