//  -*- Mode: Java -*-
//
// BooleanVectorIndexNode.java

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

public class BooleanVectorIndexNode extends StandardObject {
    public BooleanVectorIndexNode trueLink;
    public BooleanVectorIndexNode falseLink;
    public BooleanVector theVector;

  public static BooleanVectorIndexNode newBooleanVectorIndexNode() {
    { BooleanVectorIndexNode self = null;

      self = new BooleanVectorIndexNode();
      self.theVector = null;
      self.falseLink = null;
      self.trueLink = null;
      return (self);
    }
  }

  public static BooleanVectorIndexNode createBooleanVectorIndexNode(BooleanVectorIndexNode parentnode, boolean lastvalue) {
    { BooleanVectorIndexNode node = BooleanVectorIndexNode.newBooleanVectorIndexNode();
      int vectorlength = parentnode.theVector.length() + 1;
      BooleanVector vector = BooleanVector.newBooleanVector(vectorlength);

      node.theVector = vector;
      { int i = Stella.NULL_INTEGER;
        int iter000 = 0;
        int upperBound000 = vectorlength - 2;

        while (iter000 <= upperBound000) {
          {
            i = iter000;
            iter000 = iter000 + 1;
          }
          (vector.theArray)[i] = (((BooleanWrapper)((parentnode.theVector.theArray)[i])));
        }
      }
      (vector.theArray)[(vectorlength - 1)] = ((lastvalue ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER));
      if (lastvalue) {
        parentnode.trueLink = node;
      }
      else {
        parentnode.falseLink = node;
      }
      return (node);
    }
  }

  public static Stella_Object accessBooleanVectorIndexNodeSlotValue(BooleanVectorIndexNode self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_TRUE_LINK) {
      if (setvalueP) {
        self.trueLink = ((BooleanVectorIndexNode)(value));
      }
      else {
        value = self.trueLink;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_FALSE_LINK) {
      if (setvalueP) {
        self.falseLink = ((BooleanVectorIndexNode)(value));
      }
      else {
        value = self.falseLink;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_THE_VECTOR) {
      if (setvalueP) {
        self.theVector = ((BooleanVector)(value));
      }
      else {
        value = self.theVector;
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
    { BooleanVectorIndexNode self = this;

      return (Logic.SGT_LOGIC_BOOLEAN_VECTOR_INDEX_NODE);
    }
  }

}

