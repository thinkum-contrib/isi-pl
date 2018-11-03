//  -*- Mode: Java -*-
//
// ForwardChainingIndex.java

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

public class ForwardChainingIndex extends StandardObject {
    public Proposition forwardGoal;
    public Proposition masterRule;
    public Cons ioVariables;
    public Cons queryBody;
    public Cons inputBindings;
    public Symbol cacheId;
    public Description consequent;

  public static ForwardChainingIndex newForwardChainingIndex() {
    { ForwardChainingIndex self = null;

      self = new ForwardChainingIndex();
      self.consequent = null;
      self.cacheId = null;
      self.inputBindings = null;
      self.queryBody = null;
      self.ioVariables = null;
      self.masterRule = null;
      self.forwardGoal = null;
      return (self);
    }
  }

  public static Stella_Object accessForwardChainingIndexSlotValue(ForwardChainingIndex self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_FORWARD_GOAL) {
      if (setvalueP) {
        self.forwardGoal = ((Proposition)(value));
      }
      else {
        value = self.forwardGoal;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_MASTER_RULE) {
      if (setvalueP) {
        self.masterRule = ((Proposition)(value));
      }
      else {
        value = self.masterRule;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_IO_VARIABLES) {
      if (setvalueP) {
        self.ioVariables = ((Cons)(value));
      }
      else {
        value = self.ioVariables;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_QUERY_BODY) {
      if (setvalueP) {
        self.queryBody = ((Cons)(value));
      }
      else {
        value = self.queryBody;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_INPUT_BINDINGS) {
      if (setvalueP) {
        self.inputBindings = ((Cons)(value));
      }
      else {
        value = self.inputBindings;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CACHE_ID) {
      if (setvalueP) {
        self.cacheId = ((Symbol)(value));
      }
      else {
        value = self.cacheId;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CONSEQUENT) {
      if (setvalueP) {
        self.consequent = ((Description)(value));
      }
      else {
        value = self.consequent;
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
    { ForwardChainingIndex self = this;

      return (Logic.SGT_LOGIC_FORWARD_CHAINING_INDEX);
    }
  }

}

