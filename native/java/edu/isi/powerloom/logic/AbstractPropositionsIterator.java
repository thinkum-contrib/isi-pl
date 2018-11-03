//  -*- Mode: Java -*-
//
// AbstractPropositionsIterator.java

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

/** Iterator class that can generate sets of propositions matching
 * its <code>selectionPattern</code>.
 * @author Stella Java Translator
 */
public class AbstractPropositionsIterator extends Iterator {
    public Cons selectionPattern;
    public Iterator propositionCursor;
    public Cons equivalentsStack;

  public static AbstractPropositionsIterator newAbstractPropositionsIterator() {
    { AbstractPropositionsIterator self = null;

      self = new AbstractPropositionsIterator();
      self.firstIterationP = true;
      self.value = null;
      self.equivalentsStack = null;
      self.propositionCursor = null;
      self.selectionPattern = null;
      return (self);
    }
  }

  public static Cons nextEquivalentSelectionPattern(AbstractPropositionsIterator self) {
    { Cons pattern = self.selectionPattern;
      LogicObject keywithequivalents = null;
      Cons equivalentsstack = self.equivalentsStack;
      LogicObject newskolem = null;
      Cons equivalentskolems = null;

      if (equivalentsstack == null) {
        keywithequivalents = Logic.findSelectionKeyWithEquivalents(pattern);
        if (keywithequivalents != null) {
          equivalentskolems = keywithequivalents.variableValueInverse();
          equivalentsstack = Stella_Object.cons(equivalentskolems, Stella.NIL);
        }
      }
      if (equivalentsstack == null) {
        self.equivalentsStack = Stella.NIL;
        return (null);
      }
      if (equivalentsstack == Stella.NIL) {
        return (null);
      }
      equivalentskolems = ((Cons)(equivalentsstack.value));
      newskolem = ((LogicObject)(equivalentskolems.value));
      equivalentsstack.firstSetter(equivalentskolems.rest);
      if (equivalentsstack.value == Stella.NIL) {
        equivalentsstack = equivalentsstack.rest;
      }
      if (!(newskolem.variableValueInverse() == Stella.NIL)) {
        equivalentsstack = Stella_Object.cons(newskolem.variableValueInverse(), equivalentsstack);
      }
      self.equivalentsStack = equivalentsstack;
      if (keywithequivalents == null) {
        keywithequivalents = Logic.findSelectionKeyWithEquivalents(pattern);
      }
      return (((Cons)(Stella_Object.substituteConsTree(((Cons)(Stella_Object.copyConsTree(pattern))), newskolem, keywithequivalents))));
    }
  }

  public static Stella_Object accessAbstractPropositionsIteratorSlotValue(AbstractPropositionsIterator self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_SELECTION_PATTERN) {
      if (setvalueP) {
        self.selectionPattern = ((Cons)(value));
      }
      else {
        value = self.selectionPattern;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_PROPOSITION_CURSOR) {
      if (setvalueP) {
        self.propositionCursor = ((Iterator)(value));
      }
      else {
        value = self.propositionCursor;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_EQUIVALENTS_STACK) {
      if (setvalueP) {
        self.equivalentsStack = ((Cons)(value));
      }
      else {
        value = self.equivalentsStack;
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
    { AbstractPropositionsIterator self = this;

      return (Logic.SGT_LOGIC_ABSTRACT_PROPOSITIONS_ITERATOR);
    }
  }

}

