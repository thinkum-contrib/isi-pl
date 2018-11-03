//  -*- Mode: Java -*-
//
// IntegerIntervalCache.java

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

public class IntegerIntervalCache extends IntervalCache {
    public int lowerBound;
    public int upperBound;

  public static IntegerIntervalCache newIntegerIntervalCache() {
    { IntegerIntervalCache self = null;

      self = new IntegerIntervalCache();
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.surrogateValueInverse = null;
      self.intervalMember = null;
      self.homeContext = null;
      self.upperBound = Stella.NULL_INTEGER;
      self.lowerBound = Stella.NULL_INTEGER;
      return (self);
    }
  }

  public void propagateInequalityToIntervalCache(Stella_Object value, Surrogate operator) {
    { IntegerIntervalCache self = this;

      { int integervalue = PlKernelKb.coerceIntervalBoundToInteger(value, operator);

        if (integervalue == Stella.NULL_INTEGER) {
          return;
        }
        if ((operator == PlKernelKb.SGT_PL_KERNEL_KB_g) ||
            (operator == Logic.SGT_PL_KERNEL_KB_ge)) {
          if ((self.lowerBound == Stella.NULL_INTEGER) ||
              (integervalue > self.lowerBound)) {
            self.lowerBound = integervalue;
            self.evaluateTighterInterval();
          }
        }
        else if ((operator == PlKernelKb.SGT_PL_KERNEL_KB_l) ||
            (operator == PlKernelKb.SGT_PL_KERNEL_KB_el)) {
          if ((self.upperBound == Stella.NULL_INTEGER) ||
              (integervalue < self.upperBound)) {
            self.upperBound = integervalue;
            self.evaluateTighterInterval();
          }
        }
        else {
          { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

            stream000.nativeStream.print("`" + operator + "' is not a valid case option");
            throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
          }
        }
      }
    }
  }

  public void evaluateTighterInterval() {
    { IntegerIntervalCache interval = this;

      if ((Stella.$TRACED_KEYWORDS$ != null) &&
          Stella.$TRACED_KEYWORDS$.membP(Logic.KWD_PROPAGATE)) {
        {
          System.out.println("TIGHTER BOUNDS ON: " + interval.intervalMember);
          System.out.println("   LB: " + interval.lowerBound + "   UB: " + interval.upperBound);
        }
;
      }
      PlKernelKb.evaluateAdjacentInequalities(interval.intervalMember);
      if ((interval.lowerBound == Stella.NULL_INTEGER) ||
          (interval.upperBound == Stella.NULL_INTEGER)) {
        return;
      }
      if (interval.lowerBound == interval.upperBound) {
        Logic.equateValues(interval.intervalMember, Stella.wrapInteger(interval.lowerBound));
      }
      else if (interval.lowerBound > interval.upperBound) {
        IntervalCache.signalIntervalClash(interval);
      }
    }
  }

  public void printObject(java.io.PrintStream stream) {
    { IntegerIntervalCache self = this;

      stream.print("|IIcache-of: " + self.intervalMember + " [" + (((self.lowerBound != Stella.NULL_INTEGER) ? Native.integerToString(self.lowerBound) : "?")) + "," + (((self.upperBound != Stella.NULL_INTEGER) ? Native.integerToString(self.upperBound) : "?")) + "]|");
    }
  }

  public static Stella_Object accessIntegerIntervalCacheSlotValue(IntegerIntervalCache self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == PlKernelKb.SYM_STELLA_LOWER_BOUND) {
      if (setvalueP) {
        self.lowerBound = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.lowerBound);
      }
    }
    else if (slotname == PlKernelKb.SYM_STELLA_UPPER_BOUND) {
      if (setvalueP) {
        self.upperBound = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.upperBound);
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
    { IntegerIntervalCache self = this;

      return (PlKernelKb.SGT_PL_KERNEL_KB_INTEGER_INTERVAL_CACHE);
    }
  }

}

