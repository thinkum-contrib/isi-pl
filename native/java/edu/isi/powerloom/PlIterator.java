//  -*- Mode: Java -*-
//
// PlIterator.java

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

package edu.isi.powerloom;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.powerloom.logic.*;
import edu.isi.stella.*;

public class PlIterator extends Iterator {
    public Cons cursor;

  public static PlIterator newPlIterator() {
    { PlIterator self = null;

      self = new PlIterator();
      self.firstIterationP = true;
      self.value = null;
      self.cursor = null;
      return (self);
    }
  }

  /** Convert <code>self</code> into a Stella CONS.
   * @return Cons
   */
  public Cons consify() {
    { PlIterator self = this;

      { Cons value000 = Stella.NIL;

        { Stella_Object x = null;
          PlIterator iter000 = self;
          Cons collect000 = null;

          while (iter000.nextP()) {
            x = iter000.value;
            if (collect000 == null) {
              {
                collect000 = Stella_Object.cons(x, Stella.NIL);
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
                collect000.rest = Stella_Object.cons(x, Stella.NIL);
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

  /** Convert <code>self</code> into a Stella LIST.
   * @return List
   */
  public List listify() {
    { PlIterator self = this;

      { List self000 = List.newList();

        { Cons value001 = Stella.NIL;

          { Stella_Object x = null;
            PlIterator iter000 = self;
            Cons collect000 = null;

            while (iter000.nextP()) {
              x = iter000.value;
              if (collect000 == null) {
                {
                  collect000 = Stella_Object.cons(x, Stella.NIL);
                  if (value001 == Stella.NIL) {
                    value001 = collect000;
                  }
                  else {
                    Cons.addConsToEndOfConsList(value001, collect000);
                  }
                }
              }
              else {
                {
                  collect000.rest = Stella_Object.cons(x, Stella.NIL);
                  collect000 = collect000.rest;
                }
              }
            }
          }
          self000.theConsList = value001;
        }
        { List value000 = self000;

          return (value000);
        }
      }
    }
  }

  /** Number of items in <code>self</code>.
   * @return int
   */
  public int length() {
    { PlIterator self = this;

      return (self.cursor.length());
    }
  }

  /** Return TRUE if the iterator <code>self</code> has no more elements.
   * @return boolean
   */
  public boolean emptyP() {
    { PlIterator self = this;

      return (self.cursor == Stella.NIL);
    }
  }

  /** Advance the PL-Iterator <code>self</code> and return <code>true</code> if more
   * elements are available, <code>false</code> otherwise.
   * @return boolean
   */
  public boolean nextP() {
    { PlIterator self = this;

      { Cons cursor = self.cursor;

        if (cursor == Stella.NIL) {
          self.value = null;
          return (false);
        }
        self.value = cursor.value;
        self.cursor = cursor.rest;
        return (true);
      }
    }
  }

  public static Stella_Object accessPlIteratorSlotValue(PlIterator self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_STELLA_CURSOR) {
      if (setvalueP) {
        self.cursor = ((Cons)(value));
      }
      else {
        value = self.cursor;
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
    { PlIterator self = this;

      return (PLI.SGT_PLI_PL_ITERATOR);
    }
  }

}

