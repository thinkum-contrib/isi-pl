//  -*- Mode: Java -*-
//
// DirectlyLinkedObjectsIterator.java

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

public class DirectlyLinkedObjectsIterator extends TruePropositionsIterator {
    public boolean inverseP;
    public TruthValue rootTruthValue;

  public static DirectlyLinkedObjectsIterator newDirectlyLinkedObjectsIterator() {
    { DirectlyLinkedObjectsIterator self = null;

      self = new DirectlyLinkedObjectsIterator();
      self.firstIterationP = Stella.TRUE;
      self.value = null;
      self.equivalentsStack = null;
      self.propositionCursor = null;
      self.selectionPattern = null;
      self.truthValue = null;
      self.rootTruthValue = Logic.TRUE_TRUTH_VALUE;
      self.inverseP = Stella.FALSE;
      return (self);
    }
  }

  public boolean nextP() {
    { DirectlyLinkedObjectsIterator self = this;

      { Proposition proposition = null;

        { Object old$ReversepolarityP$000 = Logic.$REVERSEPOLARITYp$.get();

          try {
            Native.setBooleanSpecial(Logic.$REVERSEPOLARITYp$, Stella.FALSE);
            if (TruePropositionsIterator.truePropositionsIteratorDnextP(self)) {
              proposition = ((Proposition)(self.value));
              self.value = Logic.valueOf((self.inverseP ? (proposition.arguments.theArray)[0] : (proposition.arguments.theArray)[1]));
              self.truthValue = TruthValue.conjoinTruthValues(self.truthValue, self.rootTruthValue);
              return (Stella.TRUE);
            }
            self.value = null;
            return (Stella.FALSE);

          } finally {
            Logic.$REVERSEPOLARITYp$.set(old$ReversepolarityP$000);
          }
        }
      }
    }
  }

  public static Stella_Object accessDirectlyLinkedObjectsIteratorSlotValue(DirectlyLinkedObjectsIterator self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_INVERSEp) {
      if (setvalueP) {
        self.inverseP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.inverseP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_ROOT_TRUTH_VALUE) {
      if (setvalueP) {
        self.rootTruthValue = ((TruthValue)(value));
      }
      else {
        value = self.rootTruthValue;
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
    { DirectlyLinkedObjectsIterator self = this;

      return (Logic.SGT_LOGIC_DIRECTLY_LINKED_OBJECTS_ITERATOR);
    }
  }

}

