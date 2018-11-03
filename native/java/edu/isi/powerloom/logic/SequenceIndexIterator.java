//  -*- Mode: Java -*-
//
// SequenceIndexIterator.java

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

/** Iterator that generates successive members of a sequence index.
 * @author Stella Java Translator
 */
public class SequenceIndexIterator extends Iterator {
    public Cons listIteratorCursor;

  public static SequenceIndexIterator newSequenceIndexIterator() {
    { SequenceIndexIterator self = null;

      self = new SequenceIndexIterator();
      self.firstIterationP = true;
      self.value = null;
      self.listIteratorCursor = null;
      return (self);
    }
  }

  public boolean emptyP() {
    { SequenceIndexIterator self = this;

      return (self.listIteratorCursor == Stella.NIL);
    }
  }

  public boolean nextP() {
    { SequenceIndexIterator self = this;

      { Cons cursor = self.listIteratorCursor;
        Stella_Object value = null;

        for (;;) {
          if (cursor == Stella.NIL) {
            return (false);
          }
          value = cursor.value;
          if (!value.deletedP()) {
            self.value = value;
            self.listIteratorCursor = cursor.rest;
            return (true);
          }
          cursor = cursor.rest;
        }
      }
    }
  }

  public static Stella_Object accessSequenceIndexIteratorSlotValue(SequenceIndexIterator self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_STELLA_LIST_ITERATOR_CURSOR) {
      if (setvalueP) {
        self.listIteratorCursor = ((Cons)(value));
      }
      else {
        value = self.listIteratorCursor;
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
    { SequenceIndexIterator self = this;

      return (Logic.SGT_LOGIC_SEQUENCE_INDEX_ITERATOR);
    }
  }

}

