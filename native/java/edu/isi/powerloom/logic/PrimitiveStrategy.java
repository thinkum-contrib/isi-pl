//  -*- Mode: Java -*-
//
// PrimitiveStrategy.java

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

public class PrimitiveStrategy extends Justification {
    public Keyword strategy;

  public static PrimitiveStrategy newPrimitiveStrategy() {
    { PrimitiveStrategy self = null;

      self = new PrimitiveStrategy();
      self.negativeScore = Stella.NULL_FLOAT;
      self.positiveScore = Stella.NULL_FLOAT;
      self.truthValue = null;
      self.reversePolarityP = Stella.FALSE;
      self.substitution = null;
      self.patternJustification = null;
      self.antecedents = Stella.NIL;
      self.proposition = null;
      self.strategy = null;
      self.inferenceRule = Logic.KWD_PRIMITIVE_STRATEGY;
      return (self);
    }
  }

  public static Stella_Object accessPrimitiveStrategySlotValue(PrimitiveStrategy self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_INFERENCE_RULE) {
      if (setvalueP) {
        self.inferenceRule = ((Keyword)(value));
      }
      else {
        value = self.inferenceRule;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_STRATEGY) {
      if (setvalueP) {
        self.strategy = ((Keyword)(value));
      }
      else {
        value = self.strategy;
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

  public Keyword inferenceStrategy() {
    { PrimitiveStrategy self = this;

      return (self.strategy);
    }
  }

  public Surrogate primaryType() {
    { PrimitiveStrategy self = this;

      return (Logic.SGT_LOGIC_PRIMITIVE_STRATEGY);
    }
  }

}

