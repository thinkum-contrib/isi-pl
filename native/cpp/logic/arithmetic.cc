//  -*- Mode: C++ -*-

// arithmetic.cc

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

#include "logic/logic-system.hh"

namespace pl_kernel_kb {
  using namespace stella;
  using namespace logic;

boolean arithmeticEqualTest(NumberWrapper* x, NumberWrapper* y) {
  { Surrogate* testValue000 = safePrimaryType(x);

    if (subtypeOfIntegerP(testValue000)) {
      { NumberWrapper* x000 = x;
        IntegerWrapper* x = ((IntegerWrapper*)(x000));

        { Surrogate* testValue001 = safePrimaryType(y);

          if (subtypeOfIntegerP(testValue001)) {
            { NumberWrapper* y000 = y;
              IntegerWrapper* y = ((IntegerWrapper*)(y000));

              return (x->wrapperValue == y->wrapperValue);
            }
          }
          else if (subtypeOfFloatP(testValue001)) {
            { NumberWrapper* y001 = y;
              FloatWrapper* y = ((FloatWrapper*)(y001));

              return (((double)(x->wrapperValue)) == y->wrapperValue);
            }
          }
          else {
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
              throw *newStellaException(stream000->theStringReader());
            }
          }
        }
      }
    }
    else if (subtypeOfFloatP(testValue000)) {
      { NumberWrapper* x001 = x;
        FloatWrapper* x = ((FloatWrapper*)(x001));

        { Surrogate* testValue002 = safePrimaryType(y);

          if (subtypeOfIntegerP(testValue002)) {
            { NumberWrapper* y002 = y;
              IntegerWrapper* y = ((IntegerWrapper*)(y002));

              return (x->wrapperValue == ((double)(y->wrapperValue)));
            }
          }
          else if (subtypeOfFloatP(testValue002)) {
            { NumberWrapper* y003 = y;
              FloatWrapper* y = ((FloatWrapper*)(y003));

              return (x->wrapperValue == y->wrapperValue);
            }
          }
          else {
            { OutputStringStream* stream001 = newOutputStringStream();

              *(stream001->nativeStream) << "`" << testValue002 << "'" << " is not a valid case option";
              throw *newStellaException(stream001->theStringReader());
            }
          }
        }
      }
    }
    else {
      { OutputStringStream* stream002 = newOutputStringStream();

        *(stream002->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream002->theStringReader());
      }
    }
  }
}

boolean arithmeticLessTest(NumberWrapper* x, NumberWrapper* y) {
  { Surrogate* testValue000 = safePrimaryType(x);

    if (subtypeOfIntegerP(testValue000)) {
      { NumberWrapper* x000 = x;
        IntegerWrapper* x = ((IntegerWrapper*)(x000));

        { Surrogate* testValue001 = safePrimaryType(y);

          if (subtypeOfIntegerP(testValue001)) {
            { NumberWrapper* y000 = y;
              IntegerWrapper* y = ((IntegerWrapper*)(y000));

              return (x->wrapperValue < y->wrapperValue);
            }
          }
          else if (subtypeOfFloatP(testValue001)) {
            { NumberWrapper* y001 = y;
              FloatWrapper* y = ((FloatWrapper*)(y001));

              return (((double)(x->wrapperValue)) < y->wrapperValue);
            }
          }
          else {
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
              throw *newStellaException(stream000->theStringReader());
            }
          }
        }
      }
    }
    else if (subtypeOfFloatP(testValue000)) {
      { NumberWrapper* x001 = x;
        FloatWrapper* x = ((FloatWrapper*)(x001));

        { Surrogate* testValue002 = safePrimaryType(y);

          if (subtypeOfIntegerP(testValue002)) {
            { NumberWrapper* y002 = y;
              IntegerWrapper* y = ((IntegerWrapper*)(y002));

              return (x->wrapperValue < ((double)(y->wrapperValue)));
            }
          }
          else if (subtypeOfFloatP(testValue002)) {
            { NumberWrapper* y003 = y;
              FloatWrapper* y = ((FloatWrapper*)(y003));

              return (x->wrapperValue < y->wrapperValue);
            }
          }
          else {
            { OutputStringStream* stream001 = newOutputStringStream();

              *(stream001->nativeStream) << "`" << testValue002 << "'" << " is not a valid case option";
              throw *newStellaException(stream001->theStringReader());
            }
          }
        }
      }
    }
    else {
      { OutputStringStream* stream002 = newOutputStringStream();

        *(stream002->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream002->theStringReader());
      }
    }
  }
}

boolean arithmeticGreaterTest(NumberWrapper* x, NumberWrapper* y) {
  { Surrogate* testValue000 = safePrimaryType(x);

    if (subtypeOfIntegerP(testValue000)) {
      { NumberWrapper* x000 = x;
        IntegerWrapper* x = ((IntegerWrapper*)(x000));

        { Surrogate* testValue001 = safePrimaryType(y);

          if (subtypeOfIntegerP(testValue001)) {
            { NumberWrapper* y000 = y;
              IntegerWrapper* y = ((IntegerWrapper*)(y000));

              return (x->wrapperValue > y->wrapperValue);
            }
          }
          else if (subtypeOfFloatP(testValue001)) {
            { NumberWrapper* y001 = y;
              FloatWrapper* y = ((FloatWrapper*)(y001));

              return (((double)(x->wrapperValue)) > y->wrapperValue);
            }
          }
          else {
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
              throw *newStellaException(stream000->theStringReader());
            }
          }
        }
      }
    }
    else if (subtypeOfFloatP(testValue000)) {
      { NumberWrapper* x001 = x;
        FloatWrapper* x = ((FloatWrapper*)(x001));

        { Surrogate* testValue002 = safePrimaryType(y);

          if (subtypeOfIntegerP(testValue002)) {
            { NumberWrapper* y002 = y;
              IntegerWrapper* y = ((IntegerWrapper*)(y002));

              return (x->wrapperValue > ((double)(y->wrapperValue)));
            }
          }
          else if (subtypeOfFloatP(testValue002)) {
            { NumberWrapper* y003 = y;
              FloatWrapper* y = ((FloatWrapper*)(y003));

              return (x->wrapperValue > y->wrapperValue);
            }
          }
          else {
            { OutputStringStream* stream001 = newOutputStringStream();

              *(stream001->nativeStream) << "`" << testValue002 << "'" << " is not a valid case option";
              throw *newStellaException(stream001->theStringReader());
            }
          }
        }
      }
    }
    else {
      { OutputStringStream* stream002 = newOutputStringStream();

        *(stream002->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream002->theStringReader());
      }
    }
  }
}

NumberWrapper* plusComputation(NumberWrapper* x, NumberWrapper* y) {
  { double floatresult = NULL_FLOAT;

    { Surrogate* testValue000 = safePrimaryType(x);

      if (subtypeOfIntegerP(testValue000)) {
        { NumberWrapper* x000 = x;
          IntegerWrapper* x = ((IntegerWrapper*)(x000));

          { Surrogate* testValue001 = safePrimaryType(y);

            if (subtypeOfIntegerP(testValue001)) {
              { NumberWrapper* y000 = y;
                IntegerWrapper* y = ((IntegerWrapper*)(y000));

                return (wrapInteger(((int)(x->wrapperValue + y->wrapperValue))));
              }
            }
            else if (subtypeOfFloatP(testValue001)) {
              { NumberWrapper* y001 = y;
                FloatWrapper* y = ((FloatWrapper*)(y001));

                floatresult = x->wrapperValue + y->wrapperValue;
              }
            }
            else {
              { OutputStringStream* stream000 = newOutputStringStream();

                *(stream000->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
                throw *newStellaException(stream000->theStringReader());
              }
            }
          }
        }
      }
      else if (subtypeOfFloatP(testValue000)) {
        { NumberWrapper* x001 = x;
          FloatWrapper* x = ((FloatWrapper*)(x001));

          { Surrogate* testValue002 = safePrimaryType(y);

            if (subtypeOfIntegerP(testValue002)) {
              { NumberWrapper* y002 = y;
                IntegerWrapper* y = ((IntegerWrapper*)(y002));

                floatresult = x->wrapperValue + y->wrapperValue;
              }
            }
            else if (subtypeOfFloatP(testValue002)) {
              { NumberWrapper* y003 = y;
                FloatWrapper* y = ((FloatWrapper*)(y003));

                floatresult = x->wrapperValue + y->wrapperValue;
              }
            }
            else {
              { OutputStringStream* stream001 = newOutputStringStream();

                *(stream001->nativeStream) << "`" << testValue002 << "'" << " is not a valid case option";
                throw *newStellaException(stream001->theStringReader());
              }
            }
          }
        }
      }
      else {
        { OutputStringStream* stream002 = newOutputStringStream();

          *(stream002->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream002->theStringReader());
        }
      }
    }
    return (wrapFloat(floatresult));
  }
}

NumberWrapper* minusComputation(NumberWrapper* x, NumberWrapper* y) {
  { double floatresult = NULL_FLOAT;

    { Surrogate* testValue000 = safePrimaryType(x);

      if (subtypeOfIntegerP(testValue000)) {
        { NumberWrapper* x000 = x;
          IntegerWrapper* x = ((IntegerWrapper*)(x000));

          { Surrogate* testValue001 = safePrimaryType(y);

            if (subtypeOfIntegerP(testValue001)) {
              { NumberWrapper* y000 = y;
                IntegerWrapper* y = ((IntegerWrapper*)(y000));

                return (wrapInteger(((int)(x->wrapperValue - y->wrapperValue))));
              }
            }
            else if (subtypeOfFloatP(testValue001)) {
              { NumberWrapper* y001 = y;
                FloatWrapper* y = ((FloatWrapper*)(y001));

                floatresult = x->wrapperValue - y->wrapperValue;
              }
            }
            else {
              { OutputStringStream* stream000 = newOutputStringStream();

                *(stream000->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
                throw *newStellaException(stream000->theStringReader());
              }
            }
          }
        }
      }
      else if (subtypeOfFloatP(testValue000)) {
        { NumberWrapper* x001 = x;
          FloatWrapper* x = ((FloatWrapper*)(x001));

          { Surrogate* testValue002 = safePrimaryType(y);

            if (subtypeOfIntegerP(testValue002)) {
              { NumberWrapper* y002 = y;
                IntegerWrapper* y = ((IntegerWrapper*)(y002));

                floatresult = x->wrapperValue - y->wrapperValue;
              }
            }
            else if (subtypeOfFloatP(testValue002)) {
              { NumberWrapper* y003 = y;
                FloatWrapper* y = ((FloatWrapper*)(y003));

                floatresult = x->wrapperValue - y->wrapperValue;
              }
            }
            else {
              { OutputStringStream* stream001 = newOutputStringStream();

                *(stream001->nativeStream) << "`" << testValue002 << "'" << " is not a valid case option";
                throw *newStellaException(stream001->theStringReader());
              }
            }
          }
        }
      }
      else {
        { OutputStringStream* stream002 = newOutputStringStream();

          *(stream002->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream002->theStringReader());
        }
      }
    }
    return (wrapFloat(floatresult));
  }
}

NumberWrapper* timesComputation(NumberWrapper* x, NumberWrapper* y) {
  { double floatresult = NULL_FLOAT;

    { Surrogate* testValue000 = safePrimaryType(x);

      if (subtypeOfIntegerP(testValue000)) {
        { NumberWrapper* x000 = x;
          IntegerWrapper* x = ((IntegerWrapper*)(x000));

          { Surrogate* testValue001 = safePrimaryType(y);

            if (subtypeOfIntegerP(testValue001)) {
              { NumberWrapper* y000 = y;
                IntegerWrapper* y = ((IntegerWrapper*)(y000));

                return (wrapInteger(((int)(x->wrapperValue * y->wrapperValue))));
              }
            }
            else if (subtypeOfFloatP(testValue001)) {
              { NumberWrapper* y001 = y;
                FloatWrapper* y = ((FloatWrapper*)(y001));

                floatresult = x->wrapperValue * y->wrapperValue;
              }
            }
            else {
              { OutputStringStream* stream000 = newOutputStringStream();

                *(stream000->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
                throw *newStellaException(stream000->theStringReader());
              }
            }
          }
        }
      }
      else if (subtypeOfFloatP(testValue000)) {
        { NumberWrapper* x001 = x;
          FloatWrapper* x = ((FloatWrapper*)(x001));

          { Surrogate* testValue002 = safePrimaryType(y);

            if (subtypeOfIntegerP(testValue002)) {
              { NumberWrapper* y002 = y;
                IntegerWrapper* y = ((IntegerWrapper*)(y002));

                floatresult = x->wrapperValue * y->wrapperValue;
              }
            }
            else if (subtypeOfFloatP(testValue002)) {
              { NumberWrapper* y003 = y;
                FloatWrapper* y = ((FloatWrapper*)(y003));

                floatresult = x->wrapperValue * y->wrapperValue;
              }
            }
            else {
              { OutputStringStream* stream001 = newOutputStringStream();

                *(stream001->nativeStream) << "`" << testValue002 << "'" << " is not a valid case option";
                throw *newStellaException(stream001->theStringReader());
              }
            }
          }
        }
      }
      else {
        { OutputStringStream* stream002 = newOutputStringStream();

          *(stream002->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream002->theStringReader());
        }
      }
    }
    return (wrapFloat(floatresult));
  }
}

NumberWrapper* divideComputation(NumberWrapper* x, NumberWrapper* y) {
  try {
    { double floatresult = NULL_FLOAT;

      { Surrogate* testValue000 = safePrimaryType(x);

        if (subtypeOfIntegerP(testValue000)) {
          { NumberWrapper* x000 = x;
            IntegerWrapper* x = ((IntegerWrapper*)(x000));

            { Surrogate* testValue001 = safePrimaryType(y);

              if (subtypeOfIntegerP(testValue001)) {
                { NumberWrapper* y000 = y;
                  IntegerWrapper* y = ((IntegerWrapper*)(y000));

                  if (((x->wrapperValue) % (y->wrapperValue)) == 0) {
                    return (wrapInteger(((x->wrapperValue) / (y->wrapperValue))));
                  }
                  else {
                    floatresult = ((double)(x->wrapperValue)) / ((double)(y->wrapperValue));
                  }
                }
              }
              else if (subtypeOfFloatP(testValue001)) {
                { NumberWrapper* y001 = y;
                  FloatWrapper* y = ((FloatWrapper*)(y001));

                  floatresult = x->wrapperValue / y->wrapperValue;
                }
              }
              else {
                { OutputStringStream* stream000 = newOutputStringStream();

                  *(stream000->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
                  throw *newStellaException(stream000->theStringReader());
                }
              }
            }
          }
        }
        else if (subtypeOfFloatP(testValue000)) {
          { NumberWrapper* x001 = x;
            FloatWrapper* x = ((FloatWrapper*)(x001));

            { Surrogate* testValue002 = safePrimaryType(y);

              if (subtypeOfIntegerP(testValue002)) {
                { NumberWrapper* y002 = y;
                  IntegerWrapper* y = ((IntegerWrapper*)(y002));

                  floatresult = x->wrapperValue / y->wrapperValue;
                }
              }
              else if (subtypeOfFloatP(testValue002)) {
                { NumberWrapper* y003 = y;
                  FloatWrapper* y = ((FloatWrapper*)(y003));

                  floatresult = x->wrapperValue / y->wrapperValue;
                }
              }
              else {
                { OutputStringStream* stream001 = newOutputStringStream();

                  *(stream001->nativeStream) << "`" << testValue002 << "'" << " is not a valid case option";
                  throw *newStellaException(stream001->theStringReader());
                }
              }
            }
          }
        }
        else {
          { OutputStringStream* stream002 = newOutputStringStream();

            *(stream002->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
            throw *newStellaException(stream002->theStringReader());
          }
        }
      }
      return (wrapFloat(floatresult));
    }
  }
  catch (std::exception ) {
    return (NULL);
  }
}

NumberWrapper* sqrtComputation(NumberWrapper* x) {
  { double floatresult = NULL_FLOAT;
    int integerresult = NULL_INTEGER;

    { Surrogate* testValue000 = safePrimaryType(x);

      if (subtypeOfIntegerP(testValue000)) {
        { NumberWrapper* x000 = x;
          IntegerWrapper* x = ((IntegerWrapper*)(x000));

          floatresult = ::sqrt((((double)(x->wrapperValue))));
          integerresult = ((int)(floatresult));
          if (floatresult == ((double)(integerresult))) {
            return (wrapInteger(integerresult));
          }
          else {
            return (wrapFloat(floatresult));
          }
        }
      }
      else if (subtypeOfFloatP(testValue000)) {
        { NumberWrapper* x001 = x;
          FloatWrapper* x = ((FloatWrapper*)(x001));

          floatresult = ::sqrt((x->wrapperValue));
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    return (wrapFloat(floatresult));
  }
}

Object* plusConstraint(IntegerWrapper* missingArgument, NumberWrapper* x1, NumberWrapper* x2, NumberWrapper* x3) {
  { Object* value = NULL;

    switch (missingArgument->wrapperValue) {
      case -1: 
        value = (arithmeticEqualTest(plusComputation(x1, x2), x3) ? TRUE_WRAPPER : FALSE_WRAPPER);
      break;
      case 0: 
        value = minusComputation(x3, x2);
      break;
      case 1: 
        value = minusComputation(x3, x1);
      break;
      case 2: 
        value = plusComputation(x1, x2);
      break;
      default:
      break;
    }
    return (value);
  }
}

Object* minusConstraint(IntegerWrapper* missingArgument, NumberWrapper* x1, NumberWrapper* x2, NumberWrapper* x3) {
  { Object* value = NULL;

    switch (missingArgument->wrapperValue) {
      case -1: 
        value = (arithmeticEqualTest(minusComputation(x1, x2), x3) ? TRUE_WRAPPER : FALSE_WRAPPER);
      break;
      case 0: 
        value = plusComputation(x2, x3);
      break;
      case 1: 
        value = minusComputation(x1, x3);
      break;
      case 2: 
        value = minusComputation(x1, x2);
      break;
      default:
      break;
    }
    return (value);
  }
}

Object* timesConstraint(IntegerWrapper* missingArgument, NumberWrapper* x1, NumberWrapper* x2, NumberWrapper* x3) {
  { Object* value = NULL;

    switch (missingArgument->wrapperValue) {
      case -1: 
        value = (arithmeticEqualTest(timesComputation(x1, x2), x3) ? TRUE_WRAPPER : FALSE_WRAPPER);
      break;
      case 0: 
        value = divideComputation(x3, x2);
      break;
      case 1: 
        value = divideComputation(x3, x1);
      break;
      case 2: 
        value = timesComputation(x1, x2);
      break;
      default:
      break;
    }
    return (value);
  }
}

Object* divideConstraint(IntegerWrapper* missingArgument, NumberWrapper* x1, NumberWrapper* x2, NumberWrapper* x3) {
  { Object* value = NULL;

    switch (missingArgument->wrapperValue) {
      case -1: 
        { NumberWrapper* ratio = divideComputation(x1, x2);

          if (((boolean)(ratio))) {
            value = (arithmeticEqualTest(ratio, x3) ? TRUE_WRAPPER : FALSE_WRAPPER);
          }
          else {
            value = FALSE_WRAPPER;
          }
        }
      break;
      case 0: 
        value = timesComputation(x2, x3);
      break;
      case 1: 
        value = divideComputation(x1, x3);
      break;
      case 2: 
        value = divideComputation(x1, x2);
      break;
      default:
      break;
    }
    return (value);
  }
}

Object* sqrtConstraint(IntegerWrapper* missingArgument, NumberWrapper* x1, NumberWrapper* x2) {
  { Object* value = NULL;

    switch (missingArgument->wrapperValue) {
      case -1: 
        value = (arithmeticEqualTest(timesComputation(x2, x2), x1) ? TRUE_WRAPPER : FALSE_WRAPPER);
      break;
      case 0: 
        value = timesComputation(x2, x2);
      break;
      case 1: 
        if (arithmeticLessTest(x1, wrapInteger(0))) {
          value = NULL;
        }
        else {
          value = sqrtComputation(x1);
        }
      break;
      default:
      break;
    }
    return (value);
  }
}

IntegerInterval* newIntegerInterval() {
  { IntegerInterval* self = NULL;

    self = new IntegerInterval();
    self->dynamicSlots = newKeyValueList();
    self->surrogateValueInverse = NULL;
    self->intervalUpperBound = NULL_INTEGER;
    self->intervalLowerBound = NULL_INTEGER;
    return (self);
  }
}

Surrogate* IntegerInterval::primaryType() {
  { IntegerInterval* self = this;

    return (SGT_ARITHMETIC_PL_KERNEL_KB_INTEGER_INTERVAL);
  }
}

Object* accessIntegerIntervalSlotValue(IntegerInterval* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_LOWER_BOUND) {
    if (setvalueP) {
      self->intervalLowerBound = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->intervalLowerBound);
    }
  }
  else if (slotname == SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_UPPER_BOUND) {
    if (setvalueP) {
      self->intervalUpperBound = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->intervalUpperBound);
    }
  }
  else {
    if (setvalueP) {
      setDynamicSlotValue(self->dynamicSlots, slotname, value, NULL);
    }
    else {
      value = self->dynamicSlots->lookup(slotname);
    }
  }
  return (value);
}

IntervalCache* newIntervalCache() {
  { IntervalCache* self = NULL;

    self = new IntervalCache();
    self->dynamicSlots = newKeyValueList();
    self->surrogateValueInverse = NULL;
    self->intervalMember = NULL;
    self->homeContext = NULL;
    return (self);
  }
}

Surrogate* IntervalCache::primaryType() {
  { IntervalCache* self = this;

    return (SGT_ARITHMETIC_PL_KERNEL_KB_INTERVAL_CACHE);
  }
}

Object* accessIntervalCacheSlotValue(IntervalCache* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_ARITHMETIC_STELLA_HOME_CONTEXT) {
    if (setvalueP) {
      self->homeContext = ((Context*)(value));
    }
    else {
      value = self->homeContext;
    }
  }
  else if (slotname == SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_MEMBER) {
    if (setvalueP) {
      self->intervalMember = ((LogicObject*)(value));
    }
    else {
      value = self->intervalMember;
    }
  }
  else {
    if (setvalueP) {
      setDynamicSlotValue(self->dynamicSlots, slotname, value, NULL);
    }
    else {
      value = self->dynamicSlots->lookup(slotname);
    }
  }
  return (value);
}

IntegerIntervalCache* newIntegerIntervalCache() {
  { IntegerIntervalCache* self = NULL;

    self = new IntegerIntervalCache();
    self->dynamicSlots = newKeyValueList();
    self->surrogateValueInverse = NULL;
    self->intervalMember = NULL;
    self->homeContext = NULL;
    self->upperBound = NULL_INTEGER;
    self->lowerBound = NULL_INTEGER;
    return (self);
  }
}

Surrogate* IntegerIntervalCache::primaryType() {
  { IntegerIntervalCache* self = this;

    return (SGT_ARITHMETIC_PL_KERNEL_KB_INTEGER_INTERVAL_CACHE);
  }
}

Object* accessIntegerIntervalCacheSlotValue(IntegerIntervalCache* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_ARITHMETIC_STELLA_LOWER_BOUND) {
    if (setvalueP) {
      self->lowerBound = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->lowerBound);
    }
  }
  else if (slotname == SYM_ARITHMETIC_STELLA_UPPER_BOUND) {
    if (setvalueP) {
      self->upperBound = ((IntegerWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapInteger(self->upperBound);
    }
  }
  else {
    if (setvalueP) {
      setDynamicSlotValue(self->dynamicSlots, slotname, value, NULL);
    }
    else {
      value = self->dynamicSlots->lookup(slotname);
    }
  }
  return (value);
}

void IntegerIntervalCache::printObject(std::ostream* stream) {
  { IntegerIntervalCache* self = this;

    *(stream) << "|IIcache-of: " << self->intervalMember << " [" << (((self->lowerBound != NULL_INTEGER) ? integerToString(self->lowerBound) : (char*)"?")) << "," << (((self->upperBound != NULL_INTEGER) ? integerToString(self->upperBound) : (char*)"?")) << "]|";
  }
}

FloatIntervalCache* newFloatIntervalCache() {
  { FloatIntervalCache* self = NULL;

    self = new FloatIntervalCache();
    self->dynamicSlots = newKeyValueList();
    self->surrogateValueInverse = NULL;
    self->intervalMember = NULL;
    self->homeContext = NULL;
    self->strictUpperBoundP = FALSE;
    self->strictLowerBoundP = FALSE;
    self->upperBound = NULL_FLOAT;
    self->lowerBound = NULL_FLOAT;
    return (self);
  }
}

Surrogate* FloatIntervalCache::primaryType() {
  { FloatIntervalCache* self = this;

    return (SGT_ARITHMETIC_PL_KERNEL_KB_FLOAT_INTERVAL_CACHE);
  }
}

Object* accessFloatIntervalCacheSlotValue(FloatIntervalCache* self, Symbol* slotname, Object* value, boolean setvalueP) {
  if (slotname == SYM_ARITHMETIC_STELLA_LOWER_BOUND) {
    if (setvalueP) {
      self->lowerBound = ((FloatWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapFloat(self->lowerBound);
    }
  }
  else if (slotname == SYM_ARITHMETIC_STELLA_UPPER_BOUND) {
    if (setvalueP) {
      self->upperBound = ((FloatWrapper*)(value))->wrapperValue;
    }
    else {
      value = wrapFloat(self->upperBound);
    }
  }
  else if (slotname == SYM_ARITHMETIC_PL_KERNEL_KB_STRICT_LOWER_BOUNDp) {
    if (setvalueP) {
      self->strictLowerBoundP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->strictLowerBoundP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else if (slotname == SYM_ARITHMETIC_PL_KERNEL_KB_STRICT_UPPER_BOUNDp) {
    if (setvalueP) {
      self->strictUpperBoundP = coerceWrappedBooleanToBoolean(((BooleanWrapper*)(value)));
    }
    else {
      value = (self->strictUpperBoundP ? TRUE_WRAPPER : FALSE_WRAPPER);
    }
  }
  else {
    if (setvalueP) {
      setDynamicSlotValue(self->dynamicSlots, slotname, value, NULL);
    }
    else {
      value = self->dynamicSlots->lookup(slotname);
    }
  }
  return (value);
}

void FloatIntervalCache::printObject(std::ostream* stream) {
  { FloatIntervalCache* self = this;

    *(stream) << "|FIcache-of: " << self->intervalMember << " " << ((self->strictLowerBoundP ? (char*)"(" : (char*)"[")) << (((self->lowerBound != NULL_FLOAT) ? floatToString(self->lowerBound) : (char*)"?")) << "," << (((self->upperBound != NULL_FLOAT) ? floatToString(self->upperBound) : (char*)"?")) << ((self->strictUpperBoundP ? (char*)")" : (char*)"]")) << "|";
  }
}

IntervalCache* createIntervalCache(LogicObject* intervalmember, boolean integerP) {
  { IntervalCache* intervalcache = (integerP ? ((IntervalCache*)(newIntegerIntervalCache())) : ((IntervalCache*)(newFloatIntervalCache())));

    intervalcache->intervalMember = intervalmember;
    intervalcache->homeContext = oCONTEXTo.get();
    assertBinaryValue(SGT_ARITHMETIC_PL_KERNEL_KB_INTERVAL_CACHE_OF, intervalmember, intervalcache);
    return (intervalcache);
  }
}

IntervalCache* getIntervalCache(LogicObject* self) {
  { Object* intervalcache = accessBinaryValue(self, SGT_ARITHMETIC_PL_KERNEL_KB_INTERVAL_CACHE_OF);

    if (((boolean)(intervalcache)) &&
        ((!skolemP(intervalcache)) &&
         (((IntervalCache*)(intervalcache))->homeContext == oCONTEXTo.get()))) {
      return (((IntervalCache*)(intervalcache)));
    }
    else {
      return (createIntervalCache(self, testIsaP(self, SGT_ARITHMETIC_STELLA_INTEGER) ||
          (functionOutputSkolemP(self) &&
           logicalSubtypeOfP(((Skolem*)(self))->skolemType, SGT_ARITHMETIC_STELLA_INTEGER))));
    }
  }
}

int coerceIntervalBoundToInteger(Object* self, Surrogate* operatoR) {
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfIntegerP(testValue000)) {
      { Object* self000 = self;
        IntegerWrapper* self = ((IntegerWrapper*)(self000));

        return (integerDcoerceIntervalBoundToInteger(self, operatoR));
      }
    }
    else if (subtypeOfFloatP(testValue000)) {
      { Object* self001 = self;
        FloatWrapper* self = ((FloatWrapper*)(self001));

        return (floatDcoerceIntervalBoundToInteger(self, operatoR));
      }
    }
    else {
      return (NULL_INTEGER);
    }
  }
}

int integerDcoerceIntervalBoundToInteger(IntegerWrapper* self, Surrogate* operatoR) {
  if (self->wrapperValue == NULL_INTEGER) {
    return (NULL_INTEGER);
  }
  if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_g) {
    return (self->wrapperValue + 1);
  }
  else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_ge) {
    return (self->wrapperValue);
  }
  else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_l) {
    return (self->wrapperValue - 1);
  }
  else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_el) {
    return (self->wrapperValue);
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << operatoR << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

int floatDcoerceIntervalBoundToInteger(FloatWrapper* self, Surrogate* operatoR) {
  if (self->wrapperValue == NULL_FLOAT) {
    return (NULL_INTEGER);
  }
  if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_g) {
    return (stella::floor(self->wrapperValue) + 1);
  }
  else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_ge) {
    return (ceiling(self->wrapperValue));
  }
  else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_l) {
    return (ceiling(self->wrapperValue) - 1);
  }
  else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_el) {
    return (stella::floor(self->wrapperValue));
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << operatoR << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

void signalIntervalClash(IntervalCache* interval) {
  interval->intervalMember->markAsIncoherent();
  { OutputStringStream* stream000 = newOutputStringStream();

    *(stream000->nativeStream) << "Clash in interval values " << "`" << interval << "'" << std::endl;
    throw *newClash(stream000->theStringReader());
  }
}

void evaluateAdjacentInequalities(LogicObject* self) {
  { Proposition* dep = NULL;
    Iterator* iter000 = allSpecializingDependentPropositions(self, SGT_ARITHMETIC_PL_KERNEL_KB_INEQUALITY);

    while (iter000->nextP()) {
      dep = ((Proposition*)(iter000->value));
      { boolean alwaysP000 = TRUE;

        { Object* arg = NULL;
          Vector* vector000 = dep->arguments;
          int index000 = 0;
          int length000 = vector000->length();

          while (index000 < length000) {
            arg = (vector000->theArray)[index000];
            index000 = index000 + 1;
            if (!(isaP(valueOf(arg), SGT_ARITHMETIC_LOGIC_LOGIC_OBJECT) ||
                (!trueP(dep)))) {
              alwaysP000 = FALSE;
              break;
            }
          }
        }
        if (alwaysP000) {
          postForEvaluation(dep);
        }
      }
    }
  }
}

void IntervalCache::evaluateTighterInterval() {
  { IntervalCache* interval = this;

  }
}

void IntegerIntervalCache::evaluateTighterInterval() {
  { IntegerIntervalCache* interval = this;

    if (((boolean)(oTRACED_KEYWORDSo)) &&
        oTRACED_KEYWORDSo->membP(KWD_ARITHMETIC_PROPAGATE)) {
      std::cout << "TIGHTER BOUNDS ON: " << interval->intervalMember << std::endl << "   LB: " << interval->lowerBound << "   UB: " << interval->upperBound << std::endl;
    }
    evaluateAdjacentInequalities(interval->intervalMember);
    if ((interval->lowerBound == NULL_INTEGER) ||
        (interval->upperBound == NULL_INTEGER)) {
      return;
    }
    if (interval->lowerBound == interval->upperBound) {
      equateValues(interval->intervalMember, wrapInteger(interval->lowerBound));
    }
    else if (interval->lowerBound > interval->upperBound) {
      signalIntervalClash(interval);
    }
  }
}

void FloatIntervalCache::evaluateTighterInterval() {
  { FloatIntervalCache* interval = this;

    if ((interval->lowerBound != NULL_FLOAT) &&
        (interval->upperBound != NULL_FLOAT)) {
      if (interval->lowerBound == interval->upperBound) {
        if (interval->strictLowerBoundP ||
            interval->strictUpperBoundP) {
          signalIntervalClash(interval);
        }
        else {
          equateValues(interval->intervalMember, wrapFloat(interval->lowerBound));
        }
      }
      else if (interval->lowerBound > interval->upperBound) {
        signalIntervalClash(interval);
      }
    }
    evaluateAdjacentInequalities(interval->intervalMember);
  }
}

void IntervalCache::propagateInequalityToIntervalCache(Object* value, Surrogate* operatoR) {
  { IntervalCache* self = this;

    {
      operatoR = operatoR;
      value = value;
    }
  }
}

void IntegerIntervalCache::propagateInequalityToIntervalCache(Object* value, Surrogate* operatoR) {
  { IntegerIntervalCache* self = this;

    { int integervalue = coerceIntervalBoundToInteger(value, operatoR);

      if (integervalue == NULL_INTEGER) {
        return;
      }
      if ((operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_g) ||
          (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_ge)) {
        if ((self->lowerBound == NULL_INTEGER) ||
            (integervalue > self->lowerBound)) {
          self->lowerBound = integervalue;
          self->evaluateTighterInterval();
        }
      }
      else if ((operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_l) ||
          (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_el)) {
        if ((self->upperBound == NULL_INTEGER) ||
            (integervalue < self->upperBound)) {
          self->upperBound = integervalue;
          self->evaluateTighterInterval();
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << operatoR << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
  }
}

void FloatIntervalCache::propagateInequalityToIntervalCache(Object* value, Surrogate* operatoR) {
  { FloatIntervalCache* self = this;

    if (!(isaP(value, SGT_ARITHMETIC_STELLA_NUMBER_WRAPPER))) {
      return;
    }
    { double floatvalue = ((NumberWrapper*)(value))->numberWrapperToFloat();
      boolean tighterintervalP = FALSE;

      if (floatvalue == NULL_FLOAT) {
        return;
      }
      if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_g) {
        if ((self->lowerBound == NULL_FLOAT) ||
            ((floatvalue > self->lowerBound) ||
             ((floatvalue == self->lowerBound) &&
              (!self->strictLowerBoundP)))) {
          self->lowerBound = floatvalue;
          self->strictLowerBoundP = TRUE;
          tighterintervalP = TRUE;
        }
      }
      else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_ge) {
        if ((self->lowerBound == NULL_FLOAT) ||
            (floatvalue > self->lowerBound)) {
          self->lowerBound = floatvalue;
          self->strictLowerBoundP = FALSE;
          tighterintervalP = TRUE;
        }
      }
      else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_l) {
        if ((self->upperBound == NULL_FLOAT) ||
            ((floatvalue < self->upperBound) ||
             ((floatvalue == self->upperBound) &&
              (!self->strictUpperBoundP)))) {
          self->upperBound = floatvalue;
          self->strictUpperBoundP = TRUE;
          tighterintervalP = TRUE;
        }
      }
      else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_el) {
        if ((self->upperBound == NULL_FLOAT) ||
            (floatvalue < self->upperBound)) {
          self->upperBound = floatvalue;
          self->strictUpperBoundP = FALSE;
          tighterintervalP = TRUE;
        }
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << operatoR << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
      if (tighterintervalP) {
        self->evaluateTighterInterval();
      }
    }
  }
}

Surrogate* inverseInequalityOperator(Surrogate* operatoR) {
  if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_g) {
    return (SGT_ARITHMETIC_PL_KERNEL_KB_l);
  }
  else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_l) {
    return (SGT_ARITHMETIC_PL_KERNEL_KB_g);
  }
  else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_ge) {
    return (SGT_ARITHMETIC_PL_KERNEL_KB_el);
  }
  else if (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_el) {
    return (SGT_ARITHMETIC_PL_KERNEL_KB_ge);
  }
  else {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "`" << operatoR << "'" << " is not a valid case option";
      throw *newStellaException(stream000->theStringReader());
    }
  }
}

void unifyIntervalCaches(IntervalCache* cache1, IntervalCache* cache2, Surrogate* operatoR) {
  { boolean dummy1;
    boolean dummy2;
    boolean dummy3;
    boolean dummy4;

    if ((operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_g) ||
        (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_ge)) {
      cache1->propagateInequalityToIntervalCache(accessIntervalCacheBounds(cache2, KWD_ARITHMETIC_LOWER_BOUND, dummy1), operatoR);
      cache2->propagateInequalityToIntervalCache(accessIntervalCacheBounds(cache1, KWD_ARITHMETIC_UPPER_BOUND, dummy2), inverseInequalityOperator(operatoR));
    }
    else if ((operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_l) ||
        (operatoR == SGT_ARITHMETIC_PL_KERNEL_KB_el)) {
      cache1->propagateInequalityToIntervalCache(accessIntervalCacheBounds(cache2, KWD_ARITHMETIC_UPPER_BOUND, dummy3), operatoR);
      cache2->propagateInequalityToIntervalCache(accessIntervalCacheBounds(cache1, KWD_ARITHMETIC_LOWER_BOUND, dummy4), inverseInequalityOperator(operatoR));
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << operatoR << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

NumberWrapper* accessIntervalBounds(Object* x, Keyword* lowerorupper, boolean& _Return1) {
  if (subtypeOfP(safePrimaryType(x), SGT_ARITHMETIC_STELLA_NUMBER_WRAPPER)) {
    { Object* x000 = x;
      NumberWrapper* x = ((NumberWrapper*)(x000));

      _Return1 = FALSE;
      return (x);
    }
  }
  else {
    return (accessIntervalCacheBounds(((IntervalCache*)(accessBinaryValue(x, SGT_ARITHMETIC_PL_KERNEL_KB_INTERVAL_CACHE_OF))), lowerorupper, _Return1));
  }
}

NumberWrapper* accessIntervalCacheBounds(IntervalCache* intervalcache, Keyword* lowerorupper, boolean& _Return1) {
  if (!((boolean)(intervalcache))) {
    _Return1 = FALSE;
    return (NULL);
  }
  { Surrogate* testValue000 = safePrimaryType(intervalcache);

    if (subtypeOfP(testValue000, SGT_ARITHMETIC_PL_KERNEL_KB_INTEGER_INTERVAL_CACHE)) {
      { IntervalCache* intervalcache000 = intervalcache;
        IntegerIntervalCache* intervalcache = ((IntegerIntervalCache*)(intervalcache000));

        if (lowerorupper == KWD_ARITHMETIC_LOWER_BOUND) {
          _Return1 = FALSE;
          return (wrapInteger(intervalcache->lowerBound));
        }
        else if (lowerorupper == KWD_ARITHMETIC_UPPER_BOUND) {
          _Return1 = FALSE;
          return (wrapInteger(intervalcache->upperBound));
        }
        else {
          { OutputStringStream* stream000 = newOutputStringStream();

            *(stream000->nativeStream) << "`" << lowerorupper << "'" << " is not a valid case option";
            throw *newStellaException(stream000->theStringReader());
          }
        }
      }
    }
    else if (subtypeOfP(testValue000, SGT_ARITHMETIC_PL_KERNEL_KB_FLOAT_INTERVAL_CACHE)) {
      { IntervalCache* intervalcache001 = intervalcache;
        FloatIntervalCache* intervalcache = ((FloatIntervalCache*)(intervalcache001));

        if (lowerorupper == KWD_ARITHMETIC_LOWER_BOUND) {
          _Return1 = intervalcache->strictLowerBoundP;
          return (wrapFloat(intervalcache->lowerBound));
        }
        else if (lowerorupper == KWD_ARITHMETIC_UPPER_BOUND) {
          _Return1 = intervalcache->strictUpperBoundP;
          return (wrapFloat(intervalcache->upperBound));
        }
        else {
          { OutputStringStream* stream001 = newOutputStringStream();

            *(stream001->nativeStream) << "`" << lowerorupper << "'" << " is not a valid case option";
            throw *newStellaException(stream001->theStringReader());
          }
        }
      }
    }
    else {
      { OutputStringStream* stream002 = newOutputStringStream();

        *(stream002->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream002->theStringReader());
      }
    }
  }
}

boolean compareIntervalBoundsP(Surrogate* relation, NumberWrapper* x, NumberWrapper* y) {
  if (nullNumberP(x) ||
      nullNumberP(y)) {
    return (FALSE);
  }
  if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_el) {
    return (x->numberWrapperToFloat() <= y->numberWrapperToFloat());
  }
  else if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_l) {
    return (x->numberWrapperToFloat() < y->numberWrapperToFloat());
  }
  else {
    throw *newStellaException("Shouldn't get here!");
  }
}

boolean nullNumberP(NumberWrapper* self) {
  if (!((boolean)(self))) {
    return (TRUE);
  }
  { Surrogate* testValue000 = safePrimaryType(self);

    if (subtypeOfIntegerP(testValue000)) {
      { NumberWrapper* self000 = self;
        IntegerWrapper* self = ((IntegerWrapper*)(self000));

        return (self->wrapperValue == NULL_INTEGER);
      }
    }
    else if (subtypeOfFloatP(testValue000)) {
      { NumberWrapper* self001 = self;
        FloatWrapper* self = ((FloatWrapper*)(self001));

        return (self->wrapperValue == NULL_FLOAT);
      }
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
  }
}

boolean satisfiesIntervalBoundsP(Object* object, NumberWrapper* value) {
  { NumberWrapper* lb = NULL;
    boolean strictlowerP = FALSE;
    NumberWrapper* ub = NULL;
    boolean strictupperP = FALSE;
    boolean answer = TRUE;

    lb = accessIntervalBounds(object, KWD_ARITHMETIC_LOWER_BOUND, strictlowerP);
    ub = accessIntervalBounds(object, KWD_ARITHMETIC_UPPER_BOUND, strictupperP);
    if (nullNumberP(value)) {
      return (FALSE);
    }
    if (!(nullNumberP(lb))) {
      if (strictlowerP) {
        answer = compareIntervalBoundsP(SGT_ARITHMETIC_PL_KERNEL_KB_l, lb, value);
      }
      else {
        answer = compareIntervalBoundsP(SGT_ARITHMETIC_PL_KERNEL_KB_el, lb, value);
      }
    }
    if (!(nullNumberP(ub))) {
      if (strictupperP) {
        answer = answer &&
            compareIntervalBoundsP(SGT_ARITHMETIC_PL_KERNEL_KB_l, value, ub);
      }
      else {
        answer = answer &&
            compareIntervalBoundsP(SGT_ARITHMETIC_PL_KERNEL_KB_el, value, ub);
      }
    }
    return (answer);
  }
}

Keyword* lessSpecialist(ControlFrame* frame, Keyword* lastmove) {
  { Proposition* proposition = frame->proposition;
    Surrogate* relation = ((Surrogate*)(proposition->operatoR));
    Object* xarg = (proposition->arguments->theArray)[0];
    Object* yarg = (proposition->arguments->theArray)[1];
    Object* x = argumentBoundTo(xarg);
    Object* y = argumentBoundTo(yarg);
    NumberWrapper* xbound = NULL;
    boolean strictxP = FALSE;
    NumberWrapper* ybound = NULL;
    boolean strictyP = FALSE;

    lastmove = lastmove;
    { boolean successP = FALSE;

      if (!((boolean)(y))) {
        if (!((boolean)(x))) {
          return (KWD_ARITHMETIC_TERMINAL_FAILURE);
        }
        xbound = accessIntervalBounds(x, KWD_ARITHMETIC_UPPER_BOUND, strictxP);
        if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_l) {
          if ((!nullNumberP(xbound)) &&
              isaP(xbound, SGT_ARITHMETIC_STELLA_INTEGER_WRAPPER)) {
            xbound = wrapInteger(((IntegerWrapper*)(xbound))->wrapperValue + 1);
          }
        }
        else {
        }
        if (!nullNumberP(xbound)) {
          successP = bindVariableToValueP(((PatternVariable*)(yarg)), xbound, TRUE);
        }
        return (selectProofResult(successP, FALSE, FALSE));
      }
      if (!((boolean)(x))) {
        ybound = accessIntervalBounds(y, KWD_ARITHMETIC_LOWER_BOUND, strictyP);
        if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_l) {
          if ((!nullNumberP(ybound)) &&
              isaP(ybound, SGT_ARITHMETIC_STELLA_INTEGER_WRAPPER)) {
            ybound = wrapInteger(((IntegerWrapper*)(ybound))->wrapperValue - 1);
          }
        }
        else {
        }
        if (!nullNumberP(ybound)) {
          successP = bindVariableToValueP(((PatternVariable*)(xarg)), ybound, TRUE);
        }
        return (selectProofResult(successP, FALSE, FALSE));
      }
    }
    if (oREVERSEPOLARITYpo.get()) {
      { Object* tempnumber = x;

        x = y;
        y = tempnumber;
      }
      if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_l) {
        relation = SGT_ARITHMETIC_PL_KERNEL_KB_el;
      }
      else if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_el) {
        relation = SGT_ARITHMETIC_PL_KERNEL_KB_l;
      }
      else {
        { OutputStringStream* stream000 = newOutputStringStream();

          *(stream000->nativeStream) << "`" << relation << "'" << " is not a valid case option";
          throw *newStellaException(stream000->theStringReader());
        }
      }
    }
    { boolean successP = FALSE;

      xbound = accessIntervalBounds(x, KWD_ARITHMETIC_UPPER_BOUND, strictxP);
      ybound = accessIntervalBounds(y, KWD_ARITHMETIC_LOWER_BOUND, strictyP);
      if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_l) {
        successP = ((strictxP ||
            strictyP) &&
            compareIntervalBoundsP(SGT_ARITHMETIC_PL_KERNEL_KB_el, xbound, ybound)) ||
            compareIntervalBoundsP(SGT_ARITHMETIC_PL_KERNEL_KB_l, xbound, ybound);
      }
      else if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_el) {
        successP = compareIntervalBoundsP(relation, xbound, ybound);
      }
      else {
        { OutputStringStream* stream001 = newOutputStringStream();

          *(stream001->nativeStream) << "`" << relation << "'" << " is not a valid case option";
          throw *newStellaException(stream001->theStringReader());
        }
      }
      if (successP) {
        setFrameTruthValue(frame, TRUE_TRUTH_VALUE);
        return (KWD_ARITHMETIC_FINAL_SUCCESS);
      }
      xbound = accessIntervalBounds(x, KWD_ARITHMETIC_LOWER_BOUND, strictxP);
      ybound = accessIntervalBounds(y, KWD_ARITHMETIC_UPPER_BOUND, strictyP);
      if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_el) {
        successP = ((strictxP ||
            strictyP) &&
            compareIntervalBoundsP(SGT_ARITHMETIC_PL_KERNEL_KB_el, ybound, xbound)) ||
            compareIntervalBoundsP(SGT_ARITHMETIC_PL_KERNEL_KB_l, ybound, xbound);
      }
      else if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_l) {
        successP = compareIntervalBoundsP(SGT_ARITHMETIC_PL_KERNEL_KB_el, ybound, xbound);
      }
      else {
        { OutputStringStream* stream002 = newOutputStringStream();

          *(stream002->nativeStream) << "`" << relation << "'" << " is not a valid case option";
          throw *newStellaException(stream002->theStringReader());
        }
      }
      if (successP) {
        setFrameTruthValue(frame, FALSE_TRUTH_VALUE);
        return (KWD_ARITHMETIC_TERMINAL_FAILURE);
      }
    }
    if (skolemP(x) &&
        skolemP(y)) {
      return (KWD_ARITHMETIC_FAILURE);
    }
    else {
      return (KWD_ARITHMETIC_TERMINAL_FAILURE);
    }
  }
}

Keyword* greaterSpecialist(ControlFrame* frame, Keyword* lastmove) {
  { Proposition* proposition = frame->proposition;
    Surrogate* relation = ((Surrogate*)(proposition->operatoR));
    Vector* arguments = proposition->arguments;

    if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_g) {
      proposition->operatoR = SGT_ARITHMETIC_PL_KERNEL_KB_l;
    }
    else if (relation == SGT_ARITHMETIC_PL_KERNEL_KB_ge) {
      proposition->operatoR = SGT_ARITHMETIC_PL_KERNEL_KB_el;
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << relation << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    { Object* temp = (arguments->theArray)[0];

      (arguments->theArray)[0] = ((arguments->theArray)[1]);
      (arguments->theArray)[1] = temp;
    }
    return (lessSpecialist(frame, lastmove));
  }
}

void inequalityEvaluator(Proposition* self) {
  if (!(trueP(self))) {
    return;
  }
  { Object* arg1 = (self->arguments->theArray)[0];
    Object* arg2 = (self->arguments->theArray)[1];
    Object* value1 = valueOf(arg1);
    Object* value2 = valueOf(arg2);
    boolean skolem1P = isaP(value1, SGT_ARITHMETIC_LOGIC_LOGIC_OBJECT);
    boolean skolem2P = isaP(value2, SGT_ARITHMETIC_LOGIC_LOGIC_OBJECT);
    Surrogate* operatoR = ((Surrogate*)(self->operatoR));

    if (eqlP(value1, value2)) {
      if (!eqlP(arg1, value1)) {
        if (!eqlP(arg2, value2)) {
          unifyIntervalCaches(getIntervalCache(((LogicObject*)(arg1))), getIntervalCache(((LogicObject*)(arg2))), SGT_ARITHMETIC_PL_KERNEL_KB_el);
          unifyIntervalCaches(getIntervalCache(((LogicObject*)(arg1))), getIntervalCache(((LogicObject*)(arg2))), SGT_ARITHMETIC_PL_KERNEL_KB_ge);
          value2 = arg2;
          skolem2P = TRUE;
        }
        else {
          getIntervalCache(((LogicObject*)(arg1)))->propagateInequalityToIntervalCache(value2, SGT_ARITHMETIC_PL_KERNEL_KB_el);
          getIntervalCache(((LogicObject*)(arg1)))->propagateInequalityToIntervalCache(value2, SGT_ARITHMETIC_PL_KERNEL_KB_ge);
        }
        value1 = arg1;
        skolem1P = TRUE;
      }
      else if (!eqlP(arg2, value2)) {
        if (!eqlP(arg1, value1)) {
          unifyIntervalCaches(getIntervalCache(((LogicObject*)(arg2))), getIntervalCache(((LogicObject*)(arg1))), SGT_ARITHMETIC_PL_KERNEL_KB_el);
          unifyIntervalCaches(getIntervalCache(((LogicObject*)(arg2))), getIntervalCache(((LogicObject*)(arg1))), SGT_ARITHMETIC_PL_KERNEL_KB_ge);
          value1 = arg1;
          skolem1P = TRUE;
        }
        else {
          getIntervalCache(((LogicObject*)(arg2)))->propagateInequalityToIntervalCache(value1, SGT_ARITHMETIC_PL_KERNEL_KB_el);
          getIntervalCache(((LogicObject*)(arg2)))->propagateInequalityToIntervalCache(value1, SGT_ARITHMETIC_PL_KERNEL_KB_ge);
        }
        value2 = arg2;
        skolem2P = TRUE;
      }
    }
    if (skolem1P) {
      if (skolem2P) {
        unifyIntervalCaches(getIntervalCache(((LogicObject*)(value1))), getIntervalCache(((LogicObject*)(value2))), operatoR);
      }
      else {
        getIntervalCache(((LogicObject*)(value1)))->propagateInequalityToIntervalCache(value2, operatoR);
      }
    }
    else {
      if (skolem2P) {
        getIntervalCache(((LogicObject*)(value2)))->propagateInequalityToIntervalCache(value1, inverseInequalityOperator(operatoR));
      }
      else {
        evaluatePredicateProposition(self);
      }
    }
  }
}

Object* concatenateConstraint(IntegerWrapper* missingArgument, StringWrapper* x1, StringWrapper* x2, StringWrapper* x3) {
  { Object* value = NULL;

    switch (missingArgument->wrapperValue) {
      case -1: 
        value = (stringEqlP(stringConcatenate(x1->wrapperValue, x2->wrapperValue, 0), x3->wrapperValue) ? TRUE_WRAPPER : FALSE_WRAPPER);
      break;
      case 0: 
        { char* s2 = x2->wrapperValue;
          char* s3 = x3->wrapperValue;
          int n = strlen(s3) - strlen(s2);

          if ((n >= 0) &&
              stringEqlP(stringSubsequence(s3, n, NULL_INTEGER), s2)) {
            value = wrapString(stringSubsequence(s3, 0, n));
          }
          else {
            value = NULL;
          }
        }
      break;
      case 1: 
        { char* s1 = x1->wrapperValue;
          char* s3 = x3->wrapperValue;
          int l1 = strlen(s1);

          if (stringEqlP(stringSubsequence(s3, 0, l1), s1)) {
            value = wrapString(stringSubsequence(s3, l1, NULL_INTEGER));
          }
          else {
            value = NULL;
          }
        }
      break;
      case 2: 
        value = wrapString(stringConcatenate(x1->wrapperValue, x2->wrapperValue, 0));
      break;
      default:
      break;
    }
    return (value);
  }
}

Keyword* subsequenceSpecialist(ControlFrame* frame, Keyword* lastmove) {
  { Proposition* proposition = frame->proposition;
    Object* superarg = (proposition->arguments->theArray)[0];
    Object* superargvalue = argumentBoundTo(superarg);
    Object* p1Arg = (proposition->arguments->theArray)[1];
    Object* p1Argvalue = argumentBoundTo(p1Arg);
    Object* p2Arg = (proposition->arguments->theArray)[2];
    Object* p2Argvalue = argumentBoundTo(p2Arg);
    Object* subarg = (proposition->arguments->theArray)[3];
    Object* subargvalue = argumentBoundTo(subarg);
    Iterator* iterator = ((Iterator*)(dynamicSlotValue(frame->dynamicSlots, SYM_ARITHMETIC_STELLA_ITERATOR, NULL)));

    lastmove = lastmove;
    if (!((boolean)(iterator))) {
      if (!((boolean)(superargvalue))) {
        return (KWD_ARITHMETIC_FAILURE);
      }
      else if (!((boolean)(subargvalue))) {
        { int p1 = NULL_INTEGER;
          int p2 = NULL_INTEGER;
          char* super = NULL;

          if ((!((boolean)(p1Argvalue))) ||
              (!((boolean)(p2Argvalue)))) {
            return (KWD_ARITHMETIC_FAILURE);
          }
          else {
            {
              p1 = ((IntegerWrapper*)(p1Argvalue))->wrapperValue;
              p2 = ((IntegerWrapper*)(p2Argvalue))->wrapperValue;
              super = unwrapString(((StringWrapper*)(superargvalue)));
              if ((p1 < 0) ||
                  (p2 > strlen(super))) {
                return (KWD_ARITHMETIC_TERMINAL_FAILURE);
              }
              else {
                return (selectProofResult(bindArgumentToValueP(subarg, wrapString(stringSubsequence(super, p1, p2)), TRUE), FALSE, TRUE));
              }
            }
          }
        }
      }
      else if (!((boolean)(p1Argvalue))) {
        if (!((boolean)(p2Argvalue))) {
          {
            iterator = newSubstringPositionIterator(unwrapString(((StringWrapper*)(superargvalue))), unwrapString(((StringWrapper*)(subargvalue))));
            setDynamicSlotValue(frame->dynamicSlots, SYM_ARITHMETIC_STELLA_ITERATOR, iterator, NULL);
          }
        }
        else {
          { int p2 = ((IntegerWrapper*)(p2Argvalue))->wrapperValue;
            char* sub = unwrapString(((StringWrapper*)(subargvalue)));
            int lsub = strlen(sub);

            if (lsub > p2) {
              return (KWD_ARITHMETIC_TERMINAL_FAILURE);
            }
            else if (stringEqlP(stringSubsequence(unwrapString(((StringWrapper*)(superargvalue))), p2 - lsub, p2), sub)) {
              return (selectProofResult(bindArgumentToValueP(p1Arg, wrapInteger(p2 - lsub), TRUE), FALSE, TRUE));
            }
            else {
              return (KWD_ARITHMETIC_TERMINAL_FAILURE);
            }
          }
        }
      }
      else if (!((boolean)(p2Argvalue))) {
        { int p1 = ((IntegerWrapper*)(p1Argvalue))->wrapperValue;
          char* sub = unwrapString(((StringWrapper*)(subargvalue)));
          int lsub = strlen(sub);
          char* super = unwrapString(((StringWrapper*)(superargvalue)));
          int lsuper = strlen(super);

          if ((p1 < 0) ||
              ((p1 + lsub) > lsuper)) {
            return (KWD_ARITHMETIC_TERMINAL_FAILURE);
          }
          else if (stringEqlP(sub, stringSubsequence(super, p1, p1 + lsub))) {
            return (selectProofResult(bindArgumentToValueP(p2Arg, wrapInteger(p1 + lsub), TRUE), FALSE, TRUE));
          }
          else {
            return (KWD_ARITHMETIC_TERMINAL_FAILURE);
          }
        }
      }
      else {
        { boolean matchP = bindArgumentToValueP(subarg, wrapString(stringSubsequence(unwrapString(((StringWrapper*)(superargvalue))), ((IntegerWrapper*)(p1Argvalue))->wrapperValue, ((IntegerWrapper*)(p2Argvalue))->wrapperValue)), TRUE);

          setFrameTruthValue(frame, (matchP ? TRUE_TRUTH_VALUE : FALSE_TRUTH_VALUE));
          return (selectProofResult(matchP, FALSE, TRUE));
        }
      }
    }
    if (iterator->nextP() &&
        (bindArgumentToValueP(p1Arg, ((Cons*)(iterator->value))->value, TRUE) &&
         bindArgumentToValueP(p2Arg, ((Cons*)(iterator->value))->rest->value, TRUE))) {
      return (KWD_ARITHMETIC_CONTINUING_SUCCESS);
    }
    else {
      return (KWD_ARITHMETIC_TERMINAL_FAILURE);
    }
  }
}

IntegerWrapper* stringMatchComputation(Object* pattern, Object* x, Object* start, Object* end) {
  if (!(stringP(pattern) &&
      (integerP(start) &&
       integerP(end)))) {
    return (NULL);
  }
  { char* thepattern = ((StringWrapper*)(pattern))->wrapperValue;
    int thestart = ((IntegerWrapper*)(start))->wrapperValue;
    int theend = ((IntegerWrapper*)(end))->wrapperValue;
    char* name = (stringP(x) ? ((StringWrapper*)(x))->wrapperValue : objectNameString(x));
    int matchposition = NULL_INTEGER;

    if ((theend >= 0) &&
        (theend <= strlen(name))) {
      name = stringSubsequence(name, thestart, theend);
    }
    matchposition = stringSearch(name, thepattern, thestart);
    if (matchposition != NULL_INTEGER) {
      return (wrapInteger(matchposition));
    }
    else {
      return (NULL);
    }
  }
}

IntegerWrapper* lengthComputation(Object* x) {
  if (subtypeOfStringP(safePrimaryType(x))) {
    { Object* x000 = x;
      StringWrapper* x = ((StringWrapper*)(x000));

      return (wrapInteger(strlen((x->wrapperValue))));
    }
  }
  else {
    std::cout << "Length computation not yet implemented for Lists";
    return (wrapInteger(NULL_INTEGER));
  }
}

void helpStartupArithmetic1() {
  {
    SGT_ARITHMETIC_PL_KERNEL_KB_INTEGER_INTERVAL = ((Surrogate*)(internRigidSymbolWrtModule("INTEGER-INTERVAL", NULL, 1)));
    SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_LOWER_BOUND = ((Symbol*)(internRigidSymbolWrtModule("INTERVAL-LOWER-BOUND", NULL, 0)));
    SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_UPPER_BOUND = ((Symbol*)(internRigidSymbolWrtModule("INTERVAL-UPPER-BOUND", NULL, 0)));
    SGT_ARITHMETIC_PL_KERNEL_KB_INTERVAL_CACHE = ((Surrogate*)(internRigidSymbolWrtModule("INTERVAL-CACHE", NULL, 1)));
    SYM_ARITHMETIC_STELLA_HOME_CONTEXT = ((Symbol*)(internRigidSymbolWrtModule("HOME-CONTEXT", getStellaModule("/STELLA", TRUE), 0)));
    SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_MEMBER = ((Symbol*)(internRigidSymbolWrtModule("INTERVAL-MEMBER", NULL, 0)));
    SGT_ARITHMETIC_PL_KERNEL_KB_INTEGER_INTERVAL_CACHE = ((Surrogate*)(internRigidSymbolWrtModule("INTEGER-INTERVAL-CACHE", NULL, 1)));
    SYM_ARITHMETIC_STELLA_LOWER_BOUND = ((Symbol*)(internRigidSymbolWrtModule("LOWER-BOUND", getStellaModule("/STELLA", TRUE), 0)));
    SYM_ARITHMETIC_STELLA_UPPER_BOUND = ((Symbol*)(internRigidSymbolWrtModule("UPPER-BOUND", getStellaModule("/STELLA", TRUE), 0)));
    SGT_ARITHMETIC_PL_KERNEL_KB_FLOAT_INTERVAL_CACHE = ((Surrogate*)(internRigidSymbolWrtModule("FLOAT-INTERVAL-CACHE", NULL, 1)));
    SYM_ARITHMETIC_PL_KERNEL_KB_STRICT_LOWER_BOUNDp = ((Symbol*)(internRigidSymbolWrtModule("STRICT-LOWER-BOUND?", NULL, 0)));
    SYM_ARITHMETIC_PL_KERNEL_KB_STRICT_UPPER_BOUNDp = ((Symbol*)(internRigidSymbolWrtModule("STRICT-UPPER-BOUND?", NULL, 0)));
    SGT_ARITHMETIC_PL_KERNEL_KB_INTERVAL_CACHE_OF = ((Surrogate*)(internRigidSymbolWrtModule("INTERVAL-CACHE-OF", NULL, 1)));
    SGT_ARITHMETIC_STELLA_INTEGER = ((Surrogate*)(internRigidSymbolWrtModule("INTEGER", getStellaModule("/STELLA", TRUE), 1)));
    SGT_ARITHMETIC_PL_KERNEL_KB_g = ((Surrogate*)(internRigidSymbolWrtModule(">", NULL, 1)));
    SGT_ARITHMETIC_PL_KERNEL_KB_ge = ((Surrogate*)(internRigidSymbolWrtModule(">=", NULL, 1)));
    SGT_ARITHMETIC_PL_KERNEL_KB_l = ((Surrogate*)(internRigidSymbolWrtModule("<", NULL, 1)));
    SGT_ARITHMETIC_PL_KERNEL_KB_el = ((Surrogate*)(internRigidSymbolWrtModule("=<", NULL, 1)));
    SGT_ARITHMETIC_PL_KERNEL_KB_INEQUALITY = ((Surrogate*)(internRigidSymbolWrtModule("INEQUALITY", NULL, 1)));
    SGT_ARITHMETIC_LOGIC_LOGIC_OBJECT = ((Surrogate*)(internRigidSymbolWrtModule("LOGIC-OBJECT", getStellaModule("/LOGIC", TRUE), 1)));
    KWD_ARITHMETIC_PROPAGATE = ((Keyword*)(internRigidSymbolWrtModule("PROPAGATE", NULL, 2)));
    SGT_ARITHMETIC_STELLA_NUMBER_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("NUMBER-WRAPPER", getStellaModule("/STELLA", TRUE), 1)));
    KWD_ARITHMETIC_LOWER_BOUND = ((Keyword*)(internRigidSymbolWrtModule("LOWER-BOUND", NULL, 2)));
    KWD_ARITHMETIC_UPPER_BOUND = ((Keyword*)(internRigidSymbolWrtModule("UPPER-BOUND", NULL, 2)));
    KWD_ARITHMETIC_TERMINAL_FAILURE = ((Keyword*)(internRigidSymbolWrtModule("TERMINAL-FAILURE", NULL, 2)));
    SGT_ARITHMETIC_STELLA_INTEGER_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("INTEGER-WRAPPER", getStellaModule("/STELLA", TRUE), 1)));
    KWD_ARITHMETIC_FINAL_SUCCESS = ((Keyword*)(internRigidSymbolWrtModule("FINAL-SUCCESS", NULL, 2)));
    KWD_ARITHMETIC_FAILURE = ((Keyword*)(internRigidSymbolWrtModule("FAILURE", NULL, 2)));
    SYM_ARITHMETIC_STELLA_ITERATOR = ((Symbol*)(internRigidSymbolWrtModule("ITERATOR", getStellaModule("/STELLA", TRUE), 0)));
    KWD_ARITHMETIC_CONTINUING_SUCCESS = ((Keyword*)(internRigidSymbolWrtModule("CONTINUING-SUCCESS", NULL, 2)));
    SYM_ARITHMETIC_PL_KERNEL_KB_STARTUP_ARITHMETIC = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-ARITHMETIC", NULL, 0)));
    SYM_ARITHMETIC_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", getStellaModule("/STELLA", TRUE), 0)));
  }
}

void startupArithmetic() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getStellaModule("/PL-KERNEL-KB", oSTARTUP_TIME_PHASEo > 1));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupArithmetic1();
    }
    if (currentStartupTimePhaseP(5)) {
      { stella::Class* clasS = defineClassFromStringifiedSource("INTEGER-INTERVAL", "(DEFCLASS INTEGER-INTERVAL (THING) :DOCUMENTATION \"An interval of integers\" :SLOTS ((INTERVAL-LOWER-BOUND :TYPE INTEGER) (INTERVAL-UPPER-BOUND :TYPE INTEGER)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newIntegerInterval));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessIntegerIntervalSlotValue));
      }
      { stella::Class* clasS = defineClassFromStringifiedSource("INTERVAL-CACHE", "(DEFCLASS INTERVAL-CACHE (THING) :PUBLIC? TRUE :PUBLIC-SLOTS ((HOME-CONTEXT :TYPE CONTEXT) (INTERVAL-MEMBER :TYPE LOGIC-OBJECT)))");

        clasS->classConstructorCode = ((cpp_function_code)(&newIntervalCache));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessIntervalCacheSlotValue));
      }
      { stella::Class* clasS = defineClassFromStringifiedSource("INTEGER-INTERVAL-CACHE", "(DEFCLASS INTEGER-INTERVAL-CACHE (INTERVAL-CACHE) :PUBLIC? TRUE :PUBLIC-SLOTS ((LOWER-BOUND :TYPE INTEGER) (UPPER-BOUND :TYPE INTEGER)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|IIcache-of: \" (INTERVAL-MEMBER SELF) \" [\" (CHOOSE (DEFINED? (LOWER-BOUND SELF)) (INTEGER-TO-STRING (LOWER-BOUND SELF)) \"?\") \",\" (CHOOSE (DEFINED? (UPPER-BOUND SELF)) (INTEGER-TO-STRING (UPPER-BOUND SELF)) \"?\") \"]|\"))");

        clasS->classConstructorCode = ((cpp_function_code)(&newIntegerIntervalCache));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessIntegerIntervalCacheSlotValue));
      }
      { stella::Class* clasS = defineClassFromStringifiedSource("FLOAT-INTERVAL-CACHE", "(DEFCLASS FLOAT-INTERVAL-CACHE (INTERVAL-CACHE) :PUBLIC? TRUE :PUBLIC-SLOTS ((LOWER-BOUND :TYPE FLOAT) (UPPER-BOUND :TYPE FLOAT) (STRICT-LOWER-BOUND? :TYPE BOOLEAN) (STRICT-UPPER-BOUND? :TYPE BOOLEAN)) :PRINT-FORM (PRINT-NATIVE-STREAM STREAM \"|FIcache-of: \" (INTERVAL-MEMBER SELF) \" \" (CHOOSE (STRICT-LOWER-BOUND? SELF) \"(\" \"[\") (CHOOSE (DEFINED? (LOWER-BOUND SELF)) (FLOAT-TO-STRING (LOWER-BOUND SELF)) \"?\") \",\" (CHOOSE (DEFINED? (UPPER-BOUND SELF)) (FLOAT-TO-STRING (UPPER-BOUND SELF)) \"?\") (CHOOSE (STRICT-UPPER-BOUND? SELF) \")\" \"]\") \"|\"))");

        clasS->classConstructorCode = ((cpp_function_code)(&newFloatIntervalCache));
        clasS->classSlotAccessorCode = ((cpp_function_code)(&accessFloatIntervalCacheSlotValue));
      }
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("ARITHMETIC-EQUAL-TEST", "(DEFUN (ARITHMETIC-EQUAL-TEST BOOLEAN) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", ((cpp_function_code)(&arithmeticEqualTest)), NULL);
      defineFunctionObject("ARITHMETIC-LESS-TEST", "(DEFUN (ARITHMETIC-LESS-TEST BOOLEAN) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", ((cpp_function_code)(&arithmeticLessTest)), NULL);
      defineFunctionObject("ARITHMETIC-GREATER-TEST", "(DEFUN (ARITHMETIC-GREATER-TEST BOOLEAN) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", ((cpp_function_code)(&arithmeticGreaterTest)), NULL);
      defineFunctionObject("PLUS-COMPUTATION", "(DEFUN (PLUS-COMPUTATION NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", ((cpp_function_code)(&plusComputation)), NULL);
      defineFunctionObject("MINUS-COMPUTATION", "(DEFUN (MINUS-COMPUTATION NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", ((cpp_function_code)(&minusComputation)), NULL);
      defineFunctionObject("TIMES-COMPUTATION", "(DEFUN (TIMES-COMPUTATION NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", ((cpp_function_code)(&timesComputation)), NULL);
      defineFunctionObject("DIVIDE-COMPUTATION", "(DEFUN (DIVIDE-COMPUTATION NUMBER-WRAPPER) ((X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)) :PUBLIC? TRUE)", ((cpp_function_code)(&divideComputation)), NULL);
      defineFunctionObject("SQRT-COMPUTATION", "(DEFUN (SQRT-COMPUTATION NUMBER-WRAPPER) ((X NUMBER-WRAPPER)) :PUBLIC? TRUE)", ((cpp_function_code)(&sqrtComputation)), NULL);
      defineFunctionObject("PLUS-CONSTRAINT", "(DEFUN (PLUS-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 NUMBER-WRAPPER) (X2 NUMBER-WRAPPER) (X3 NUMBER-WRAPPER)))", ((cpp_function_code)(&plusConstraint)), NULL);
      defineFunctionObject("MINUS-CONSTRAINT", "(DEFUN (MINUS-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 NUMBER-WRAPPER) (X2 NUMBER-WRAPPER) (X3 NUMBER-WRAPPER)))", ((cpp_function_code)(&minusConstraint)), NULL);
      defineFunctionObject("TIMES-CONSTRAINT", "(DEFUN (TIMES-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 NUMBER-WRAPPER) (X2 NUMBER-WRAPPER) (X3 NUMBER-WRAPPER)))", ((cpp_function_code)(&timesConstraint)), NULL);
      defineFunctionObject("DIVIDE-CONSTRAINT", "(DEFUN (DIVIDE-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 NUMBER-WRAPPER) (X2 NUMBER-WRAPPER) (X3 NUMBER-WRAPPER)))", ((cpp_function_code)(&divideConstraint)), NULL);
      defineFunctionObject("SQRT-CONSTRAINT", "(DEFUN (SQRT-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 NUMBER-WRAPPER) (X2 NUMBER-WRAPPER)))", ((cpp_function_code)(&sqrtConstraint)), NULL);
      defineFunctionObject("CREATE-INTERVAL-CACHE", "(DEFUN (CREATE-INTERVAL-CACHE INTERVAL-CACHE) ((INTERVALMEMBER LOGIC-OBJECT) (INTEGER? BOOLEAN)) :PUBLIC? TRUE)", ((cpp_function_code)(&createIntervalCache)), NULL);
      defineFunctionObject("GET-INTERVAL-CACHE", "(DEFUN (GET-INTERVAL-CACHE INTERVAL-CACHE) ((SELF LOGIC-OBJECT)) :PUBLIC? TRUE)", ((cpp_function_code)(&getIntervalCache)), NULL);
      defineFunctionObject("COERCE-INTERVAL-BOUND-TO-INTEGER", "(DEFUN (COERCE-INTERVAL-BOUND-TO-INTEGER INTEGER) ((SELF OBJECT) (OPERATOR SURROGATE)) :PUBLIC? TRUE)", ((cpp_function_code)(&coerceIntervalBoundToInteger)), NULL);
      defineFunctionObject("INTEGER.COERCE-INTERVAL-BOUND-TO-INTEGER", "(DEFUN (INTEGER.COERCE-INTERVAL-BOUND-TO-INTEGER INTEGER) ((SELF INTEGER-WRAPPER) (OPERATOR SURROGATE)))", ((cpp_function_code)(&integerDcoerceIntervalBoundToInteger)), NULL);
      defineFunctionObject("FLOAT.COERCE-INTERVAL-BOUND-TO-INTEGER", "(DEFUN (FLOAT.COERCE-INTERVAL-BOUND-TO-INTEGER INTEGER) ((SELF FLOAT-WRAPPER) (OPERATOR SURROGATE)))", ((cpp_function_code)(&floatDcoerceIntervalBoundToInteger)), NULL);
      defineFunctionObject("SIGNAL-INTERVAL-CLASH", "(DEFUN SIGNAL-INTERVAL-CLASH ((INTERVAL INTERVAL-CACHE)))", ((cpp_function_code)(&signalIntervalClash)), NULL);
      defineFunctionObject("EVALUATE-ADJACENT-INEQUALITIES", "(DEFUN EVALUATE-ADJACENT-INEQUALITIES ((SELF LOGIC-OBJECT)))", ((cpp_function_code)(&evaluateAdjacentInequalities)), NULL);
      defineMethodObject("(DEFMETHOD EVALUATE-TIGHTER-INTERVAL ((INTERVAL INTERVAL-CACHE)))", ((cpp_method_code)(&IntervalCache::evaluateTighterInterval)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD EVALUATE-TIGHTER-INTERVAL ((INTERVAL INTEGER-INTERVAL-CACHE)))", ((cpp_method_code)(&IntegerIntervalCache::evaluateTighterInterval)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD EVALUATE-TIGHTER-INTERVAL ((INTERVAL FLOAT-INTERVAL-CACHE)))", ((cpp_method_code)(&FloatIntervalCache::evaluateTighterInterval)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD PROPAGATE-INEQUALITY-TO-INTERVAL-CACHE ((SELF INTERVAL-CACHE) (VALUE OBJECT) (OPERATOR SURROGATE)))", ((cpp_method_code)(&IntervalCache::propagateInequalityToIntervalCache)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD PROPAGATE-INEQUALITY-TO-INTERVAL-CACHE ((SELF INTEGER-INTERVAL-CACHE) (VALUE OBJECT) (OPERATOR SURROGATE)))", ((cpp_method_code)(&IntegerIntervalCache::propagateInequalityToIntervalCache)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD PROPAGATE-INEQUALITY-TO-INTERVAL-CACHE ((SELF FLOAT-INTERVAL-CACHE) (VALUE OBJECT) (OPERATOR SURROGATE)))", ((cpp_method_code)(&FloatIntervalCache::propagateInequalityToIntervalCache)), ((cpp_method_code)(NULL)));
      defineFunctionObject("INVERSE-INEQUALITY-OPERATOR", "(DEFUN (INVERSE-INEQUALITY-OPERATOR SURROGATE) ((OPERATOR SURROGATE)))", ((cpp_function_code)(&inverseInequalityOperator)), NULL);
      defineFunctionObject("UNIFY-INTERVAL-CACHES", "(DEFUN UNIFY-INTERVAL-CACHES ((CACHE1 INTERVAL-CACHE) (CACHE2 INTERVAL-CACHE) (OPERATOR SURROGATE)))", ((cpp_function_code)(&unifyIntervalCaches)), NULL);
      defineFunctionObject("ACCESS-INTERVAL-BOUNDS", "(DEFUN (ACCESS-INTERVAL-BOUNDS NUMBER-WRAPPER BOOLEAN) ((X OBJECT) (LOWERORUPPER KEYWORD)))", ((cpp_function_code)(&accessIntervalBounds)), NULL);
      defineFunctionObject("ACCESS-INTERVAL-CACHE-BOUNDS", "(DEFUN (ACCESS-INTERVAL-CACHE-BOUNDS NUMBER-WRAPPER BOOLEAN) ((INTERVALCACHE INTERVAL-CACHE) (LOWERORUPPER KEYWORD)))", ((cpp_function_code)(&accessIntervalCacheBounds)), NULL);
      defineFunctionObject("COMPARE-INTERVAL-BOUNDS?", "(DEFUN (COMPARE-INTERVAL-BOUNDS? BOOLEAN) ((RELATION SURROGATE) (X NUMBER-WRAPPER) (Y NUMBER-WRAPPER)))", ((cpp_function_code)(&compareIntervalBoundsP)), NULL);
      defineFunctionObject("NULL-NUMBER?", "(DEFUN (NULL-NUMBER? BOOLEAN) ((SELF NUMBER-WRAPPER)) :PUBLIC? TRUE)", ((cpp_function_code)(&nullNumberP)), NULL);
      defineFunctionObject("SATISFIES-INTERVAL-BOUNDS?", "(DEFUN (SATISFIES-INTERVAL-BOUNDS? BOOLEAN) ((OBJECT OBJECT) (VALUE NUMBER-WRAPPER)))", ((cpp_function_code)(&satisfiesIntervalBoundsP)), NULL);
      defineFunctionObject("LESS-SPECIALIST", "(DEFUN (LESS-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&lessSpecialist)), NULL);
      defineFunctionObject("GREATER-SPECIALIST", "(DEFUN (GREATER-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&greaterSpecialist)), NULL);
      defineFunctionObject("INEQUALITY-EVALUATOR", "(DEFUN INEQUALITY-EVALUATOR ((SELF PROPOSITION)))", ((cpp_function_code)(&inequalityEvaluator)), NULL);
      defineFunctionObject("CONCATENATE-CONSTRAINT", "(DEFUN (CONCATENATE-CONSTRAINT OBJECT) ((MISSING-ARGUMENT INTEGER-WRAPPER) (X1 STRING-WRAPPER) (X2 STRING-WRAPPER) (X3 STRING-WRAPPER)))", ((cpp_function_code)(&concatenateConstraint)), NULL);
      defineFunctionObject("SUBSEQUENCE-SPECIALIST", "(DEFUN (SUBSEQUENCE-SPECIALIST KEYWORD) ((FRAME CONTROL-FRAME) (LASTMOVE KEYWORD)))", ((cpp_function_code)(&subsequenceSpecialist)), NULL);
      defineFunctionObject("STRING-MATCH-COMPUTATION", "(DEFUN (STRING-MATCH-COMPUTATION INTEGER-WRAPPER) ((PATTERN OBJECT) (X OBJECT) (START OBJECT) (END OBJECT)))", ((cpp_function_code)(&stringMatchComputation)), NULL);
      defineFunctionObject("LENGTH-COMPUTATION", "(DEFUN (LENGTH-COMPUTATION INTEGER-WRAPPER) ((X OBJECT)))", ((cpp_function_code)(&lengthComputation)), NULL);
      defineFunctionObject("STARTUP-ARITHMETIC", "(DEFUN STARTUP-ARITHMETIC () :PUBLIC? TRUE)", ((cpp_function_code)(&startupArithmetic)), NULL);
      { MethodSlot* function = lookupFunction(SYM_ARITHMETIC_PL_KERNEL_KB_STARTUP_ARITHMETIC);

        setDynamicSlotValue(function->dynamicSlots, SYM_ARITHMETIC_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Arithmetic"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
  }
}

Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_INTEGER_INTERVAL = NULL;

Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_LOWER_BOUND = NULL;

Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_UPPER_BOUND = NULL;

Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_INTERVAL_CACHE = NULL;

Symbol* SYM_ARITHMETIC_STELLA_HOME_CONTEXT = NULL;

Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_INTERVAL_MEMBER = NULL;

Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_INTEGER_INTERVAL_CACHE = NULL;

Symbol* SYM_ARITHMETIC_STELLA_LOWER_BOUND = NULL;

Symbol* SYM_ARITHMETIC_STELLA_UPPER_BOUND = NULL;

Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_FLOAT_INTERVAL_CACHE = NULL;

Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_STRICT_LOWER_BOUNDp = NULL;

Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_STRICT_UPPER_BOUNDp = NULL;

Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_INTERVAL_CACHE_OF = NULL;

Surrogate* SGT_ARITHMETIC_STELLA_INTEGER = NULL;

Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_g = NULL;

Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_ge = NULL;

Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_l = NULL;

Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_el = NULL;

Surrogate* SGT_ARITHMETIC_PL_KERNEL_KB_INEQUALITY = NULL;

Surrogate* SGT_ARITHMETIC_LOGIC_LOGIC_OBJECT = NULL;

Keyword* KWD_ARITHMETIC_PROPAGATE = NULL;

Surrogate* SGT_ARITHMETIC_STELLA_NUMBER_WRAPPER = NULL;

Keyword* KWD_ARITHMETIC_LOWER_BOUND = NULL;

Keyword* KWD_ARITHMETIC_UPPER_BOUND = NULL;

Keyword* KWD_ARITHMETIC_TERMINAL_FAILURE = NULL;

Surrogate* SGT_ARITHMETIC_STELLA_INTEGER_WRAPPER = NULL;

Keyword* KWD_ARITHMETIC_FINAL_SUCCESS = NULL;

Keyword* KWD_ARITHMETIC_FAILURE = NULL;

Symbol* SYM_ARITHMETIC_STELLA_ITERATOR = NULL;

Keyword* KWD_ARITHMETIC_CONTINUING_SUCCESS = NULL;

Symbol* SYM_ARITHMETIC_PL_KERNEL_KB_STARTUP_ARITHMETIC = NULL;

Symbol* SYM_ARITHMETIC_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace pl_kernel_kb
