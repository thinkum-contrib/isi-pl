//  -*- Mode: Java -*-
//
// SubstringPositionIterator.java

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

public class SubstringPositionIterator extends Iterator {
    public String superString;
    public String subString;
    public int start;
    public int subLength;

  public static SubstringPositionIterator newSubstringPositionIterator(String superString, String subString) {
    { SubstringPositionIterator self = null;

      self = new SubstringPositionIterator();
      self.superString = superString;
      self.subString = subString;
      self.firstIterationP = Stella.TRUE;
      self.value = null;
      self.subLength = (self.subString).length();
      self.start = 0;
      return (self);
    }
  }

  public int length() {
    { SubstringPositionIterator it = this;

      { int count = 0;
        String renamed_Super = it.superString;
        String sub = it.subString;
        int p1 = Native.stringSearch(renamed_Super, sub, 0);

        while (p1 != Stella.NULL_INTEGER) {
          count = count + 1;
          p1 = Native.stringSearch(renamed_Super, sub, p1 + 1);
        }
        return (count);
      }
    }
  }

  public boolean nextP() {
    { SubstringPositionIterator it = this;

      { int p1 = Native.stringSearch(it.superString, it.subString, it.start);

        if (p1 != Stella.NULL_INTEGER) {
          {
            it.value = Stella_Object.cons(Stella.wrapInteger(p1), Stella_Object.cons(Stella.wrapInteger(p1 + it.subLength), Stella.NIL));
            it.start = p1 + 1;
            return (Stella.TRUE);
          }
        }
        else {
          {
            it.value = null;
            return (Stella.FALSE);
          }
        }
      }
    }
  }

  public static Stella_Object accessSubstringPositionIteratorSlotValue(SubstringPositionIterator self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_SUPER_STRING) {
      if (setvalueP) {
        self.superString = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapString(self.superString);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_SUB_STRING) {
      if (setvalueP) {
        self.subString = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapString(self.subString);
      }
    }
    else if (slotname == Logic.SYM_STELLA_START) {
      if (setvalueP) {
        self.start = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.start);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_SUB_LENGTH) {
      if (setvalueP) {
        self.subLength = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.subLength);
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
    { SubstringPositionIterator self = this;

      return (Logic.SGT_LOGIC_SUBSTRING_POSITION_ITERATOR);
    }
  }

}

