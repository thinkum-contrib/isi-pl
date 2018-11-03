//  -*- Mode: Java -*-
//
// AtomicGoalCacheIterator.java

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

package edu.isi.powerloom.logic;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.stella.*;

public class AtomicGoalCacheIterator extends Iterator {
    public ControlFrame goal;
    public AtomicGoalCache cacheList;

  public static AtomicGoalCacheIterator newAtomicGoalCacheIterator() {
    { AtomicGoalCacheIterator self = null;

      self = new AtomicGoalCacheIterator();
      self.firstIterationP = Stella.TRUE;
      self.value = null;
      self.cacheList = null;
      self.goal = null;
      return (self);
    }
  }

  public boolean nextP() {
    { AtomicGoalCacheIterator self = this;

      { ControlFrame goal = self.goal;
        AtomicGoalCache cachelist = self.cacheList;

        if ((cachelist != null) &&
            (!(goal.proposition.operator == cachelist.proposition.operator))) {
          self.cacheList = null;
          return (Stella.FALSE);
        }
        while ((cachelist != null) &&
            ((!AtomicGoalCache.cacheMatchesGoalP(cachelist, goal, Stella.TRUE, Logic.KWD_CACHE_INSTANTIATES_GOAL)) ||
             (((!(!((Boolean)(Logic.$DONTUSEDEFAULTKNOWLEDGEp$.get())).booleanValue())) &&
            ((goal.truthValue == Logic.DEFAULT_TRUE_TRUTH_VALUE) ||
             (goal.truthValue == Logic.DEFAULT_FALSE_TRUTH_VALUE))) ||
              (((Boolean)(Logic.$RECORD_JUSTIFICATIONSp$.get())).booleanValue() &&
               (cachelist.justification == null))))) {
          cachelist = cachelist.next;
        }
        if (cachelist != null) {
          self.value = cachelist;
          self.cacheList = cachelist.next;
          return (Stella.TRUE);
        }
        else {
          return (Stella.FALSE);
        }
      }
    }
  }

  public static Stella_Object accessAtomicGoalCacheIteratorSlotValue(AtomicGoalCacheIterator self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_GOAL) {
      if (setvalueP) {
        self.goal = ((ControlFrame)(value));
      }
      else {
        value = self.goal;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CACHE_LIST) {
      if (setvalueP) {
        self.cacheList = ((AtomicGoalCache)(value));
      }
      else {
        value = self.cacheList;
      }
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + slotname + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
    return (value);
  }

  public Surrogate primaryType() {
    { AtomicGoalCacheIterator self = this;

      return (Logic.SGT_LOGIC_ATOMIC_GOAL_CACHE_ITERATOR);
    }
  }

}

