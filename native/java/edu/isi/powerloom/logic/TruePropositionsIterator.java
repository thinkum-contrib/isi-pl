//  -*- Mode: Java -*-
//
// TruePropositionsIterator.java

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

/** Iterator class that can generate sets of true propositions
 * matching its <code>selectionPattern</code>.
 * @author Stella Java Translator
 */
public class TruePropositionsIterator extends AbstractPropositionsIterator {
    /** Truth-value of the most recently generated proposition (or
     * projected argument thereof).  This truth value is not necessarily the strictest
     * and might have involved defaults.
     */
    public TruthValue truthValue;

  public static TruePropositionsIterator newTruePropositionsIterator() {
    { TruePropositionsIterator self = null;

      self = new TruePropositionsIterator();
      self.firstIterationP = true;
      self.value = null;
      self.equivalentsStack = null;
      self.propositionCursor = null;
      self.selectionPattern = null;
      self.truthValue = null;
      return (self);
    }
  }

  public boolean nextP() {
    { TruePropositionsIterator self = this;

      return (TruePropositionsIterator.truePropositionsIteratorDnextP(self));
    }
  }

  public static boolean truePropositionsIteratorDnextP(TruePropositionsIterator self) {
    { Iterator cursor = self.propositionCursor;
      Proposition proposition = null;

      if (cursor == null) {
        return (false);
      }
      loop000 : for (;;) {
        if (cursor.nextP()) {
          proposition = ((Proposition)(cursor.value));
        }
        else {
          { Cons pattern = AbstractPropositionsIterator.nextEquivalentSelectionPattern(self);

            if (pattern != null) {
              cursor = Logic.selectPropositions(pattern).allocateIterator();
              self.propositionCursor = cursor;
              continue loop000;
            }
            else {
              self.propositionCursor = null;
              return (false);
            }
          }
        }
        if ((!proposition.deletedP()) &&
            ((((Boolean)(Logic.$REVERSEPOLARITYp$.get())).booleanValue() ? Proposition.falseP(proposition) : (Proposition.trueP(proposition) ||
            Proposition.functionWithDefinedValueP(proposition))))) {
          self.value = proposition;
          self.truthValue = Proposition.propositionTruthValue(proposition);
          return (true);
        }
      }
    }
  }

  public static Stella_Object accessTruePropositionsIteratorSlotValue(TruePropositionsIterator self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_TRUTH_VALUE) {
      if (setvalueP) {
        self.truthValue = ((TruthValue)(value));
      }
      else {
        value = self.truthValue;
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
    { TruePropositionsIterator self = this;

      return (Logic.SGT_LOGIC_TRUE_PROPOSITIONS_ITERATOR);
    }
  }

}

