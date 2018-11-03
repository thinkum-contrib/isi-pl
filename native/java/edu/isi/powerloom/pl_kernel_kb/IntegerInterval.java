//  -*- Mode: Java -*-
//
// IntegerInterval.java

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

/** An interval of integers
 * @author Stella Java Translator
 */
public class IntegerInterval extends Thing {
    public int intervalLowerBound;
    public int intervalUpperBound;

  public static IntegerInterval newIntegerInterval() {
    { IntegerInterval self = null;

      self = new IntegerInterval();
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.surrogateValueInverse = null;
      self.intervalUpperBound = Stella.NULL_INTEGER;
      self.intervalLowerBound = Stella.NULL_INTEGER;
      return (self);
    }
  }

  public static Stella_Object accessIntegerIntervalSlotValue(IntegerInterval self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == PlKernelKb.SYM_PL_KERNEL_KB_INTERVAL_LOWER_BOUND) {
      if (setvalueP) {
        self.intervalLowerBound = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.intervalLowerBound);
      }
    }
    else if (slotname == PlKernelKb.SYM_PL_KERNEL_KB_INTERVAL_UPPER_BOUND) {
      if (setvalueP) {
        self.intervalUpperBound = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.intervalUpperBound);
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
    { IntegerInterval self = this;

      return (PlKernelKb.SGT_PL_KERNEL_KB_INTEGER_INTERVAL);
    }
  }

}

