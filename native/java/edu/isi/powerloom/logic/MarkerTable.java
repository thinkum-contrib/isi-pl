//  -*- Mode: Java -*-
//
// MarkerTable.java

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

/** Used to record (mark) a set of objects.
 * Can be optimized for testing only, or also for recall.
 * @author Stella Java Translator
 */
public class MarkerTable extends StandardObject {
    public HashTable testTable;
    public List recallTable;
    public boolean supportsRecallP;

  public static MarkerTable newMarkerTable() {
    { MarkerTable self = null;

      self = new MarkerTable();
      self.supportsRecallP = false;
      self.recallTable = null;
      self.testTable = null;
      return (self);
    }
  }

  /** Return an iterator that generates all marked objects
   * recorded in 'self'.
   * @return ListIterator
   */
  public ListIterator recallMarkedObjects() {
    { MarkerTable self = this;

      return (((ListIterator)(self.recallTable.allocateIterator())));
    }
  }

  /** Return TRUE if 'object' is stored (marked) in 'self'.
   * @param renamed_Object
   * @return boolean
   */
  public boolean testMarkerP(Stella_Object renamed_Object) {
    { MarkerTable self = this;

      return (self.testTable.lookup(renamed_Object) != null);
    }
  }

  /** Record membership of 'object' in the marker
   * storage object 'self'.
   * @param renamed_Object
   */
  public void setMarker(Stella_Object renamed_Object) {
    { MarkerTable self = this;

      if (self.supportsRecallP) {
        if (self.testTable.lookup(renamed_Object) == null) {
          self.testTable.insertAt(renamed_Object, Stella.TRUE_WRAPPER);
          self.recallTable.push(renamed_Object);
        }
      }
      else {
        self.testTable.insertAt(renamed_Object, Stella.TRUE_WRAPPER);
      }
    }
  }

  public static Stella_Object accessMarkerTableSlotValue(MarkerTable self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_TEST_TABLE) {
      if (setvalueP) {
        self.testTable = ((HashTable)(value));
      }
      else {
        value = self.testTable;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_RECALL_TABLE) {
      if (setvalueP) {
        self.recallTable = ((List)(value));
      }
      else {
        value = self.recallTable;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_SUPPORTS_RECALLp) {
      if (setvalueP) {
        self.supportsRecallP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.supportsRecallP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
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
    { MarkerTable self = this;

      return (Logic.SGT_LOGIC_MARKER_TABLE);
    }
  }

}

