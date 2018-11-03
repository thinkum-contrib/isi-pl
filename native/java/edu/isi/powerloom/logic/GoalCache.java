//  -*- Mode: Java -*-
//
// GoalCache.java

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

package edu.isi.powerloom.logic;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.stella.*;

/** Cache of output bindings derived for a particular goal
 * and set of input bindings.
 * @author Stella Java Translator
 */
public class GoalCache extends StandardObject {
    public List cachedBindings;
    public int timestamp;
    public Proposition proposition;
    public boolean reversePolarityP;
    public Context cacheContext;

  public static GoalCache newGoalCache() {
    { GoalCache self = null;

      self = new GoalCache();
      self.cacheContext = null;
      self.reversePolarityP = false;
      self.proposition = null;
      self.timestamp = Stella.NULL_INTEGER;
      self.cachedBindings = List.newList();
      return (self);
    }
  }

  public static Stella_Object accessGoalCacheSlotValue(GoalCache self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_CACHED_BINDINGS) {
      if (setvalueP) {
        self.cachedBindings = ((List)(value));
      }
      else {
        value = self.cachedBindings;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_TIMESTAMP) {
      if (setvalueP) {
        self.timestamp = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.timestamp);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_PROPOSITION) {
      if (setvalueP) {
        self.proposition = ((Proposition)(value));
      }
      else {
        value = self.proposition;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_REVERSE_POLARITYp) {
      if (setvalueP) {
        self.reversePolarityP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.reversePolarityP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CACHE_CONTEXT) {
      if (setvalueP) {
        self.cacheContext = ((Context)(value));
      }
      else {
        value = self.cacheContext;
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
    { GoalCache self = this;

      return (Logic.SGT_LOGIC_GOAL_CACHE);
    }
  }

}

