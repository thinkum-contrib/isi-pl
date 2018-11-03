//  -*- Mode: Java -*-
//
// ClassificationCache.java

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

/** Records various kinds of data about a description
 * during a classification session.
 * @author Stella Java Translator
 */
public class ClassificationCache extends StandardObject {
    public List inferableDirectSubdescriptions;
    public int cacheUpclassificationTimestamp;
    public int cacheDownclassificationTimestamp;
    public int introductionTimestamp;

  public static ClassificationCache newClassificationCache() {
    { ClassificationCache self = null;

      self = new ClassificationCache();
      self.introductionTimestamp = 0;
      self.cacheDownclassificationTimestamp = -1;
      self.cacheUpclassificationTimestamp = -1;
      self.inferableDirectSubdescriptions = null;
      return (self);
    }
  }

  public static Stella_Object accessClassificationCacheSlotValue(ClassificationCache self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_INFERABLE_DIRECT_SUBDESCRIPTIONS) {
      if (setvalueP) {
        self.inferableDirectSubdescriptions = ((List)(value));
      }
      else {
        value = self.inferableDirectSubdescriptions;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CACHE_UPCLASSIFICATION_TIMESTAMP) {
      if (setvalueP) {
        self.cacheUpclassificationTimestamp = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.cacheUpclassificationTimestamp);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CACHE_DOWNCLASSIFICATION_TIMESTAMP) {
      if (setvalueP) {
        self.cacheDownclassificationTimestamp = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.cacheDownclassificationTimestamp);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_INTRODUCTION_TIMESTAMP) {
      if (setvalueP) {
        self.introductionTimestamp = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.introductionTimestamp);
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
    { ClassificationCache self = this;

      return (Logic.SGT_LOGIC_CLASSIFICATION_CACHE);
    }
  }

}

