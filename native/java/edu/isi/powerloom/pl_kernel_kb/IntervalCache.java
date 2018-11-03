//  -*- Mode: Java -*-
//
// IntervalCache.java

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

package edu.isi.powerloom.pl_kernel_kb;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.powerloom.logic.*;
import edu.isi.stella.*;

public class IntervalCache extends Thing {
    public Context homeContext;
    public LogicObject intervalMember;

  public static IntervalCache newIntervalCache() {
    { IntervalCache self = null;

      self = new IntervalCache();
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.surrogateValueInverse = null;
      self.intervalMember = null;
      self.homeContext = null;
      return (self);
    }
  }

  public static NumberWrapper accessIntervalCacheBounds(IntervalCache intervalcache, Keyword lowerorupper, Object [] MV_returnarray) {
    if (intervalcache == null) {
      { NumberWrapper _return_temp = null;

        MV_returnarray[0] = Stella.wrapBoolean(false);
        return (_return_temp);
      }
    }
    { Surrogate testValue000 = Stella_Object.safePrimaryType(intervalcache);

      if (Surrogate.subtypeOfP(testValue000, PlKernelKb.SGT_PL_KERNEL_KB_INTEGER_INTERVAL_CACHE)) {
        { IntegerIntervalCache intervalcache000 = ((IntegerIntervalCache)(intervalcache));

          if (lowerorupper == PlKernelKb.KWD_LOWER_BOUND) {
            { NumberWrapper _return_temp = Stella.wrapInteger(intervalcache000.lowerBound);

              MV_returnarray[0] = Stella.wrapBoolean(false);
              return (_return_temp);
            }
          }
          else if (lowerorupper == PlKernelKb.KWD_UPPER_BOUND) {
            { NumberWrapper _return_temp = Stella.wrapInteger(intervalcache000.upperBound);

              MV_returnarray[0] = Stella.wrapBoolean(false);
              return (_return_temp);
            }
          }
          else {
            { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

              stream000.nativeStream.print("`" + lowerorupper + "' is not a valid case option");
              throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
            }
          }
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, PlKernelKb.SGT_PL_KERNEL_KB_FLOAT_INTERVAL_CACHE)) {
        { FloatIntervalCache intervalcache000 = ((FloatIntervalCache)(intervalcache));

          if (lowerorupper == PlKernelKb.KWD_LOWER_BOUND) {
            { NumberWrapper _return_temp = Stella.wrapFloat(intervalcache000.lowerBound);

              MV_returnarray[0] = Stella.wrapBoolean(intervalcache000.strictLowerBoundP);
              return (_return_temp);
            }
          }
          else if (lowerorupper == PlKernelKb.KWD_UPPER_BOUND) {
            { NumberWrapper _return_temp = Stella.wrapFloat(intervalcache000.upperBound);

              MV_returnarray[0] = Stella.wrapBoolean(intervalcache000.strictUpperBoundP);
              return (_return_temp);
            }
          }
          else {
            { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

              stream001.nativeStream.print("`" + lowerorupper + "' is not a valid case option");
              throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
            }
          }
        }
      }
      else {
        { OutputStringStream stream002 = OutputStringStream.newOutputStringStream();

          stream002.nativeStream.print("`" + testValue000 + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream002.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public static void unifyIntervalCaches(IntervalCache cache1, IntervalCache cache2, Surrogate operator) {
    if ((operator == PlKernelKb.SGT_PL_KERNEL_KB_g) ||
        (operator == Logic.SGT_PL_KERNEL_KB_ge)) {
      cache1.propagateInequalityToIntervalCache(IntervalCache.accessIntervalCacheBounds(cache2, PlKernelKb.KWD_LOWER_BOUND, new Object[1]), operator);
      cache2.propagateInequalityToIntervalCache(IntervalCache.accessIntervalCacheBounds(cache1, PlKernelKb.KWD_UPPER_BOUND, new Object[1]), PlKernelKb.inverseInequalityOperator(operator));
    }
    else if ((operator == PlKernelKb.SGT_PL_KERNEL_KB_l) ||
        (operator == PlKernelKb.SGT_PL_KERNEL_KB_el)) {
      cache1.propagateInequalityToIntervalCache(IntervalCache.accessIntervalCacheBounds(cache2, PlKernelKb.KWD_UPPER_BOUND, new Object[1]), operator);
      cache2.propagateInequalityToIntervalCache(IntervalCache.accessIntervalCacheBounds(cache1, PlKernelKb.KWD_LOWER_BOUND, new Object[1]), PlKernelKb.inverseInequalityOperator(operator));
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + operator + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public void propagateInequalityToIntervalCache(Stella_Object value, Surrogate operator) {
    { IntervalCache self = this;

      {
        operator = operator;
        value = value;
      }
    }
  }

  public void evaluateTighterInterval() {
    { IntervalCache interval = this;

    }
  }

  public static void signalIntervalClash(IntervalCache interval) {
    interval.intervalMember.markAsIncoherent();
    { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

      stream000.nativeStream.println("Clash in interval values `" + interval + "'");
      throw ((Clash)(Clash.newClash(stream000.theStringReader()).fillInStackTrace()));
    }
  }

  public static Stella_Object accessIntervalCacheSlotValue(IntervalCache self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == PlKernelKb.SYM_STELLA_HOME_CONTEXT) {
      if (setvalueP) {
        self.homeContext = ((Context)(value));
      }
      else {
        value = self.homeContext;
      }
    }
    else if (slotname == PlKernelKb.SYM_PL_KERNEL_KB_INTERVAL_MEMBER) {
      if (setvalueP) {
        self.intervalMember = ((LogicObject)(value));
      }
      else {
        value = self.intervalMember;
      }
    }
    else {
      if (setvalueP) {
        KeyValueList.setDynamicSlotValue(self.dynamicSlots, slotname, value, null);
      }
      else {
        value = self.dynamicSlots.lookup(slotname);
      }
    }
    return (value);
  }

  public Surrogate primaryType() {
    { IntervalCache self = this;

      return (Logic.SGT_PL_KERNEL_KB_INTERVAL_CACHE);
    }
  }

}

