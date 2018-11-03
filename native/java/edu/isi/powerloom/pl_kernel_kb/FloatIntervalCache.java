//  -*- Mode: Java -*-
//
// FloatIntervalCache.java

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

package edu.isi.powerloom.pl_kernel_kb;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.powerloom.logic.*;
import edu.isi.stella.*;

public class FloatIntervalCache extends IntervalCache {
    public double lowerBound;
    public double upperBound;
    public boolean strictLowerBoundP;
    public boolean strictUpperBoundP;

  public static FloatIntervalCache newFloatIntervalCache() {
    { FloatIntervalCache self = null;

      self = new FloatIntervalCache();
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.surrogateValueInverse = null;
      self.intervalMember = null;
      self.homeContext = null;
      self.strictUpperBoundP = Stella.FALSE;
      self.strictLowerBoundP = Stella.FALSE;
      self.upperBound = Stella.NULL_FLOAT;
      self.lowerBound = Stella.NULL_FLOAT;
      return (self);
    }
  }

  public void propagateInequalityToIntervalCache(Stella_Object value, Surrogate operator) {
    { FloatIntervalCache self = this;

      if (!(Stella_Object.isaP(value, Logic.SGT_STELLA_NUMBER_WRAPPER))) {
        return;
      }
      { double floatvalue = ((NumberWrapper)(value)).numberWrapperToFloat();
        boolean tighterintervalP = Stella.FALSE;

        if (floatvalue == Stella.NULL_FLOAT) {
          return;
        }
        if (operator == PlKernelKb.SGT_PL_KERNEL_KB_g) {
          if ((self.lowerBound == Stella.NULL_FLOAT) ||
              ((floatvalue > self.lowerBound) ||
               ((floatvalue == self.lowerBound) &&
                (!self.strictLowerBoundP)))) {
            self.lowerBound = floatvalue;
            self.strictLowerBoundP = Stella.TRUE;
            tighterintervalP = Stella.TRUE;
          }
        }
        else if (operator == Logic.SGT_PL_KERNEL_KB_ge) {
          if ((self.lowerBound == Stella.NULL_FLOAT) ||
              (floatvalue > self.lowerBound)) {
            self.lowerBound = floatvalue;
            self.strictLowerBoundP = Stella.FALSE;
            tighterintervalP = Stella.TRUE;
          }
        }
        else if (operator == PlKernelKb.SGT_PL_KERNEL_KB_l) {
          if ((self.upperBound == Stella.NULL_FLOAT) ||
              ((floatvalue < self.upperBound) ||
               ((floatvalue == self.upperBound) &&
                (!self.strictUpperBoundP)))) {
            self.upperBound = floatvalue;
            self.strictUpperBoundP = Stella.TRUE;
            tighterintervalP = Stella.TRUE;
          }
        }
        else if (operator == PlKernelKb.SGT_PL_KERNEL_KB_el) {
          if ((self.upperBound == Stella.NULL_FLOAT) ||
              (floatvalue < self.upperBound)) {
            self.upperBound = floatvalue;
            self.strictUpperBoundP = Stella.FALSE;
            tighterintervalP = Stella.TRUE;
          }
        }
        else {
          { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

            stream000.nativeStream.print("`" + operator + "' is not a valid case option");
            throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
          }
        }
        if (tighterintervalP) {
          self.evaluateTighterInterval();
        }
      }
    }
  }

  public void evaluateTighterInterval() {
    { FloatIntervalCache interval = this;

      if ((interval.lowerBound != Stella.NULL_FLOAT) &&
          (interval.upperBound != Stella.NULL_FLOAT)) {
        if (interval.lowerBound == interval.upperBound) {
          if (interval.strictLowerBoundP ||
              interval.strictUpperBoundP) {
            IntervalCache.signalIntervalClash(interval);
          }
          else {
            Logic.equateValues(interval.intervalMember, Stella.wrapFloat(interval.lowerBound));
          }
        }
        else if (interval.lowerBound > interval.upperBound) {
          IntervalCache.signalIntervalClash(interval);
        }
      }
      PlKernelKb.evaluateAdjacentInequalities(interval.intervalMember);
    }
  }

  public void printObject(java.io.PrintStream stream) {
    { FloatIntervalCache self = this;

      stream.print("|FIcache-of: " + self.intervalMember + " " + ((self.strictLowerBoundP ? "(" : "[")) + (((self.lowerBound != Stella.NULL_FLOAT) ? Native.floatToString(self.lowerBound) : "?")) + "," + (((self.upperBound != Stella.NULL_FLOAT) ? Native.floatToString(self.upperBound) : "?")) + ((self.strictUpperBoundP ? ")" : "]")) + "|");
    }
  }

  public static Stella_Object accessFloatIntervalCacheSlotValue(FloatIntervalCache self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == PlKernelKb.SYM_STELLA_LOWER_BOUND) {
      if (setvalueP) {
        self.lowerBound = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.lowerBound);
      }
    }
    else if (slotname == PlKernelKb.SYM_STELLA_UPPER_BOUND) {
      if (setvalueP) {
        self.upperBound = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.upperBound);
      }
    }
    else if (slotname == PlKernelKb.SYM_PL_KERNEL_KB_STRICT_LOWER_BOUNDp) {
      if (setvalueP) {
        self.strictLowerBoundP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.strictLowerBoundP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
      }
    }
    else if (slotname == PlKernelKb.SYM_PL_KERNEL_KB_STRICT_UPPER_BOUNDp) {
      if (setvalueP) {
        self.strictUpperBoundP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.strictUpperBoundP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
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
    { FloatIntervalCache self = this;

      return (PlKernelKb.SGT_PL_KERNEL_KB_FLOAT_INTERVAL_CACHE);
    }
  }

}

