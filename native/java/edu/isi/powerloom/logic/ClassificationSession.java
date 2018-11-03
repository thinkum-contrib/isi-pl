//  -*- Mode: Java -*-
//
// ClassificationSession.java

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

public class ClassificationSession extends StandardObject {
    public World classificationWorld;
    public HashTable classificationCacheTable;
    public int classificationTimeclock;
    public List introductionTimestampStack;
    public boolean everythingClassifiedP;
    public LogicObject lastCacheTableKey;
    public ClassificationCache lastCacheTableValue;

  public static ClassificationSession newClassificationSession() {
    { ClassificationSession self = null;

      self = new ClassificationSession();
      self.lastCacheTableValue = null;
      self.lastCacheTableKey = null;
      self.everythingClassifiedP = false;
      self.introductionTimestampStack = Stella.list(Stella_Object.cons(Stella.wrapInteger(0), Stella.NIL));
      self.classificationTimeclock = 0;
      self.classificationCacheTable = HashTable.newHashTable();
      self.classificationWorld = null;
      return (self);
    }
  }

  public static Stella_Object accessClassificationSessionSlotValue(ClassificationSession self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_CLASSIFICATION_WORLD) {
      if (setvalueP) {
        self.classificationWorld = ((World)(value));
      }
      else {
        value = self.classificationWorld;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CLASSIFICATION_CACHE_TABLE) {
      if (setvalueP) {
        self.classificationCacheTable = ((HashTable)(value));
      }
      else {
        value = self.classificationCacheTable;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CLASSIFICATION_TIMECLOCK) {
      if (setvalueP) {
        self.classificationTimeclock = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.classificationTimeclock);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_INTRODUCTION_TIMESTAMP_STACK) {
      if (setvalueP) {
        self.introductionTimestampStack = ((List)(value));
      }
      else {
        value = self.introductionTimestampStack;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_EVERYTHING_CLASSIFIEDp) {
      if (setvalueP) {
        self.everythingClassifiedP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.everythingClassifiedP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_LAST_CACHE_TABLE_KEY) {
      if (setvalueP) {
        self.lastCacheTableKey = ((LogicObject)(value));
      }
      else {
        value = self.lastCacheTableKey;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_LAST_CACHE_TABLE_VALUE) {
      if (setvalueP) {
        self.lastCacheTableValue = ((ClassificationCache)(value));
      }
      else {
        value = self.lastCacheTableValue;
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
    { ClassificationSession self = this;

      return (Logic.SGT_LOGIC_CLASSIFICATION_SESSION);
    }
  }

}

