//  -*- Mode: Java -*-
//
// PagingIndex.java

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

/** Index that manages a sequence of objects retrievable from
 * persistent storage.  Needs to be appropriately subclassed by actual store
 * implementations and facilitated with a proper iterator class.
 * @author Stella Java Translator
 */
public class PagingIndex extends SequenceIndex {
    public Cons selectionPattern;
    public ObjectStore store;

  public static PagingIndex newPagingIndex() {
    { PagingIndex self = null;

      self = new PagingIndex();
      self.theSequenceLength = Stella.NULL_INTEGER;
      self.theSequence = Stella.NIL;
      self.store = null;
      self.selectionPattern = null;
      return (self);
    }
  }

  public Iterator allocateIterator() {
    { PagingIndex self = this;

      { PagingIndexIterator self000 = PagingIndexIterator.newPagingIndexIterator();

        self000.listIteratorCursor = self.theSequence;
        { PagingIndexIterator value000 = self000;

          return (value000);
        }
      }
    }
  }

  public static void printPagingIndex(PagingIndex self, java.io.PrintStream stream) {
    { int limit = 10;

      stream.print("|PAGING-IDX|(" + self.selectionPattern);
      { int i = Stella.NULL_INTEGER;
        Stella_Object elt = null;
        Cons iter000 = self.theSequence;
        int iter001 = 1;
        int upperBound000 = limit;
        boolean unboundedP000 = upperBound000 == Stella.NULL_INTEGER;

        while ((!(iter000 == Stella.NIL)) &&
            (unboundedP000 ||
             (iter001 <= upperBound000))) {
          {
            elt = iter000.value;
            iter000 = iter000.rest;
          }
          {
            i = iter001;
            iter001 = iter001 + 1;
          }
          stream.print(" " + elt);
          if (i == limit) {
            stream.print("...");
          }
        }
      }
      stream.print(")");
    }
  }

  /** Destructively remove all deleted members of <code>self</code>.
   * @return SequenceIndex
   */
  public SequenceIndex removeDeletedMembers() {
    { PagingIndex self = this;

      { Cons sequence = self.theSequence.removeDeletedMembers();

        self.theSequence = sequence;
        self.theSequenceLength = Stella.NULL_INTEGER;
        return (self);
      }
    }
  }

  /** Return the estimated length of the sequences in 'self',
   * which could be too large if some of the members have been deleted.
   * @return int
   */
  public int estimatedLength() {
    { PagingIndex self = this;

      { int length = self.theSequenceLength;

        if (length == Stella.NULL_INTEGER) {
          length = self.theSequence.length();
          self.theSequenceLength = length;
        }
        return (length);
      }
    }
  }

  public void push(Stella_Object value) {
    { PagingIndex self = this;

      self.insert(value);
    }
  }

  public void insert(Stella_Object value) {
    { PagingIndex self = this;

      if (!(!(self == Logic.NIL_PAGING_INDEX))) {
        System.err.print("Safety violation: Attempt to insert into NIL-PAGING-INDEX");
      }
      self.theSequence = Stella_Object.cons(value, self.theSequence);
    }
  }

  public void printObject(java.io.PrintStream stream) {
    { PagingIndex self = this;

      PagingIndex.printPagingIndex(self, stream);
    }
  }

  public static Stella_Object accessPagingIndexSlotValue(PagingIndex self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_SELECTION_PATTERN) {
      if (setvalueP) {
        self.selectionPattern = ((Cons)(value));
      }
      else {
        value = self.selectionPattern;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_STORE) {
      if (setvalueP) {
        self.store = ((ObjectStore)(value));
      }
      else {
        value = self.store;
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
    { PagingIndex self = this;

      return (Logic.SGT_LOGIC_PAGING_INDEX);
    }
  }

}

