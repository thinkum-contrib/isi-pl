//  -*- Mode: Java -*-
//
// TransitiveClosureIterator.java

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

/** Iterator that visits all nodes reachable using an
 * embedded adjacency function.
 * @author Stella Java Translator
 */
public class TransitiveClosureIterator extends Iterator {
    public java.lang.reflect.Method allocateAdjacencyIteratorFunction;
    public java.lang.reflect.Method filterP;
    public Cons adjacencyIteratorStack;
    public Cons beenThereList;

  public static TransitiveClosureIterator newTransitiveClosureIterator() {
    { TransitiveClosureIterator self = null;

      self = new TransitiveClosureIterator();
      self.firstIterationP = true;
      self.value = null;
      self.beenThereList = null;
      self.adjacencyIteratorStack = Stella.NIL;
      self.filterP = null;
      self.allocateAdjacencyIteratorFunction = null;
      return (self);
    }
  }

  public boolean nextP() {
    { TransitiveClosureIterator self = this;

      return (TransitiveClosureIterator.transitiveClosureIteratorDnextP(self));
    }
  }

  public static boolean transitiveClosureIteratorDnextP(TransitiveClosureIterator self) {
    { Stella_Object node = self.value;
      Iterator adjacencyiterator = ((Iterator)(edu.isi.stella.javalib.Native.funcall(self.allocateAdjacencyIteratorFunction, null, new java.lang.Object [] {node})));

      if (adjacencyiterator != null) {
        self.adjacencyIteratorStack = Stella_Object.cons(adjacencyiterator, self.adjacencyIteratorStack);
      }
      else {
        {
          adjacencyiterator = ((Iterator)(self.adjacencyIteratorStack.value));
          if (adjacencyiterator == null) {
            return (false);
          }
        }
      }
      for (;;) {
        while (!adjacencyiterator.nextP()) {
          self.adjacencyIteratorStack = self.adjacencyIteratorStack.rest;
          adjacencyiterator = ((Iterator)(self.adjacencyIteratorStack.value));
          if (adjacencyiterator == null) {
            return (false);
          }
        }
        node = adjacencyiterator.value;
        if ((!self.beenThereList.memberP(node)) &&
            ((self.filterP == null) ||
             ((Boolean)(edu.isi.stella.javalib.Native.funcall(self.filterP, null, new java.lang.Object [] {node}))).booleanValue())) {
          self.beenThereList = Stella_Object.cons(node, self.beenThereList);
          self.value = node;
          return (true);
        }
      }
    }
  }

  public static Stella_Object accessTransitiveClosureIteratorSlotValue(TransitiveClosureIterator self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_ALLOCATE_ADJACENCY_ITERATOR_FUNCTION) {
      if (setvalueP) {
        self.allocateAdjacencyIteratorFunction = ((FunctionCodeWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFunctionCode(self.allocateAdjacencyIteratorFunction);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_FILTERp) {
      if (setvalueP) {
        self.filterP = ((FunctionCodeWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFunctionCode(self.filterP);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_ADJACENCY_ITERATOR_STACK) {
      if (setvalueP) {
        self.adjacencyIteratorStack = ((Cons)(value));
      }
      else {
        value = self.adjacencyIteratorStack;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_BEEN_THERE_LIST) {
      if (setvalueP) {
        self.beenThereList = ((Cons)(value));
      }
      else {
        value = self.beenThereList;
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
    { TransitiveClosureIterator self = this;

      return (Logic.SGT_LOGIC_TRANSITIVE_CLOSURE_ITERATOR);
    }
  }

}

