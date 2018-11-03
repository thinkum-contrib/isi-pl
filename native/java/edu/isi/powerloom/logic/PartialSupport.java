//  -*- Mode: Java -*-
//
// PartialSupport.java

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

public class PartialSupport extends StandardObject {
    public Proposition fact;
    public Proposition axiom;
    public double score;
    public int id;
    public Cons argumentScores;

  public static PartialSupport newPartialSupport() {
    { PartialSupport self = null;

      self = new PartialSupport();
      self.argumentScores = null;
      self.id = Stella.NULL_INTEGER;
      self.score = Stella.NULL_FLOAT;
      self.axiom = null;
      self.fact = null;
      return (self);
    }
  }

  public static Stella_Object accessPartialSupportSlotValue(PartialSupport self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_FACT) {
      if (setvalueP) {
        self.fact = ((Proposition)(value));
      }
      else {
        value = self.fact;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_AXIOM) {
      if (setvalueP) {
        self.axiom = ((Proposition)(value));
      }
      else {
        value = self.axiom;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_SCORE) {
      if (setvalueP) {
        self.score = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.score);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_ID) {
      if (setvalueP) {
        self.id = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.id);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_ARGUMENT_SCORES) {
      if (setvalueP) {
        self.argumentScores = ((Cons)(value));
      }
      else {
        value = self.argumentScores;
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
    { PartialSupport self = this;

      return (Logic.SGT_LOGIC_PARTIAL_SUPPORT);
    }
  }

}

