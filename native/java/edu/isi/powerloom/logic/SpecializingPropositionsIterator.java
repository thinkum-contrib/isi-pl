//  -*- Mode: Java -*-
//
// SpecializingPropositionsIterator.java

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

/** Iterator class that can generate sets of true propositions
 * matching its <code>selectionPattern</code> or a more specific pattern that substitutes
 * one of the relations in <code>specializingRelations</code>.
 * @author Stella Java Translator
 */
public class SpecializingPropositionsIterator extends TruePropositionsIterator {
    public Cons specializingRelations;

  public static SpecializingPropositionsIterator newSpecializingPropositionsIterator() {
    { SpecializingPropositionsIterator self = null;

      self = new SpecializingPropositionsIterator();
      self.firstIterationP = Stella.TRUE;
      self.value = null;
      self.equivalentsStack = null;
      self.propositionCursor = null;
      self.selectionPattern = null;
      self.truthValue = null;
      self.specializingRelations = null;
      return (self);
    }
  }

  public boolean nextP() {
    { SpecializingPropositionsIterator self = this;

      return (SpecializingPropositionsIterator.specializingPropositionsIteratorDnextP(self));
    }
  }

  public static boolean specializingPropositionsIteratorDnextP(SpecializingPropositionsIterator self) {
    { Cons specializingrelations = self.specializingRelations;

      for (;;) {
        if (TruePropositionsIterator.truePropositionsIteratorDnextP(self)) {
          if ((specializingrelations != null) &&
              (!(specializingrelations == Stella.NIL))) {
            self.truthValue = TruthValue.conjoinTruthValues(self.truthValue, ((TruthValue)(((Cons)(specializingrelations.value)).rest.value)));
          }
          self.specializingRelations = specializingrelations;
          return (Stella.TRUE);
        }
        if (specializingrelations == null) {
          if (((Keyword)(self.selectionPattern.value)) == Logic.KWD_RELATION) {
            { NamedDescription relationdescription = Logic.surrogateToDescription(((Surrogate)(self.selectionPattern.rest.rest.value)));

              if (relationdescription != null) {
                specializingrelations = LogicObject.allSupportedNamedSubcollections(relationdescription);
              }
              else {
                specializingrelations = Stella.NIL;
              }
            }
          }
          else {
            { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

              stream000.nativeStream.print("Illegal selection pattern in `" + self + "'");
              throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
            }
          }
        }
        else {
          specializingrelations = specializingrelations.rest;
        }
        if (specializingrelations == Stella.NIL) {
          self.value = null;
          return (Stella.FALSE);
        }
        self.selectionPattern.rest.rest.firstSetter(((NamedDescription)(((Cons)(specializingrelations.value)).value)).surrogateValueInverse);
        self.propositionCursor = Logic.selectPropositions(self.selectionPattern).allocateIterator();
        self.equivalentsStack = null;
      }
    }
  }

  public static Stella_Object accessSpecializingPropositionsIteratorSlotValue(SpecializingPropositionsIterator self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_SPECIALIZING_RELATIONS) {
      if (setvalueP) {
        self.specializingRelations = ((Cons)(value));
      }
      else {
        value = self.specializingRelations;
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
    { SpecializingPropositionsIterator self = this;

      return (Logic.SGT_LOGIC_SPECIALIZING_PROPOSITIONS_ITERATOR);
    }
  }

}

