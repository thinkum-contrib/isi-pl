//  -*- Mode: Java -*-
//
// SequenceIndex.java

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

/** Abstract class for managing a sequence of objects.
 * @author Stella Java Translator
 */
public abstract class SequenceIndex extends StandardObject {
    public Cons theSequence;
    public int theSequenceLength;

  public static boolean emptyPropositionsIndexP(SequenceIndex index, Stella_Object primarykey, boolean specializeP) {
    if ((!specializeP) &&
        ((index == Logic.NIL_PAGING_INDEX) ||
         (index == Logic.NIL_NON_PAGING_INDEX))) {
      if (Surrogate.subtypeOfP(Stella_Object.safePrimaryType(primarykey), Logic.SGT_LOGIC_LOGIC_OBJECT)) {
        { LogicObject primarykey000 = ((LogicObject)(primarykey));

          if (primarykey000.variableValueInverse() == Stella.NIL) {
            return (true);
          }
        }
      }
      else {
        return (true);
      }
    }
    return (false);
  }

  public Iterator allocateIterator() {
    { SequenceIndex self = this;

      { SequenceIndexIterator self000 = SequenceIndexIterator.newSequenceIndexIterator();

        self000.listIteratorCursor = self.theSequence;
        { SequenceIndexIterator value000 = self000;

          return (value000);
        }
      }
    }
  }

  public static void printSequenceIndex(SequenceIndex self, java.io.PrintStream stream) {
    { int limit = 10;

      stream.print("|SEQ-IDX|(");
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
          if (i > 1) {
            stream.print(" ");
          }
          stream.print(elt);
          if (i == limit) {
            stream.print("...");
          }
        }
      }
      stream.print(")");
    }
  }

  public Cons consify() {
    { SequenceIndex self = this;

      { Cons value000 = Stella.NIL;

        { Stella_Object i = null;
          Iterator iter000 = self.allocateIterator();
          Cons collect000 = null;

          while (iter000.nextP()) {
            i = iter000.value;
            if (collect000 == null) {
              {
                collect000 = Stella_Object.cons(i, Stella.NIL);
                if (value000 == Stella.NIL) {
                  value000 = collect000;
                }
                else {
                  Cons.addConsToEndOfConsList(value000, collect000);
                }
              }
            }
            else {
              {
                collect000.rest = Stella_Object.cons(i, Stella.NIL);
                collect000 = collect000.rest;
              }
            }
          }
        }
        { Cons value001 = value000;

          return (value001);
        }
      }
    }
  }

  public SequenceIndex removeDeletedMembers() {
    { SequenceIndex self = this;

      { Cons sequence = self.theSequence.removeDeletedMembers();

        self.theSequence = sequence;
        self.theSequenceLength = Stella.NULL_INTEGER;
        return (self);
      }
    }
  }

  public static int sequenceIndexDestimatedLength(SequenceIndex self) {
    { int length = self.theSequenceLength;

      if (length == Stella.NULL_INTEGER) {
        length = self.theSequence.length();
        self.theSequenceLength = length;
      }
      return (length);
    }
  }

  public int estimatedLength() {
    { SequenceIndex self = this;

      return (SequenceIndex.sequenceIndexDestimatedLength(self));
    }
  }

  public boolean emptyP() {
    { SequenceIndex self = this;

      if (self.theSequence == Stella.NIL) {
        return (true);
      }
      if (!self.theSequence.value.deletedP()) {
        return (false);
      }
      self.removeDeletedMembers();
      return (self.theSequence == Stella.NIL);
    }
  }

  public Stella_Object first() {
    { SequenceIndex self = this;

      { Stella_Object item = null;
        Iterator iter000 = self.allocateIterator();

        while (iter000.nextP()) {
          item = iter000.value;
          return (item);
        }
      }
      return (null);
    }
  }

  public void push(Stella_Object value) {
    { SequenceIndex self = this;

      self.insert(value);
    }
  }

  public void insert(Stella_Object value) {
    { SequenceIndex self = this;

      if (!(!(self == Logic.NIL_NON_PAGING_INDEX))) {
        System.err.print("Safety violation: Attempt to insert into NIL-NON-PAGING-INDEX");
      }
      self.theSequence = Stella_Object.cons(value, self.theSequence);
      { int length = self.theSequenceLength;

        if (length != Stella.NULL_INTEGER) {
          self.theSequenceLength = length + 1;
        }
      }
    }
  }

  public void printObject(java.io.PrintStream stream) {
    { SequenceIndex self = this;

      SequenceIndex.printSequenceIndex(self, stream);
    }
  }

  public static Stella_Object accessSequenceIndexSlotValue(SequenceIndex self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_THE_SEQUENCE) {
      if (setvalueP) {
        self.theSequence = ((Cons)(value));
      }
      else {
        value = self.theSequence;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_THE_SEQUENCE_LENGTH) {
      if (setvalueP) {
        self.theSequenceLength = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.theSequenceLength);
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

}

