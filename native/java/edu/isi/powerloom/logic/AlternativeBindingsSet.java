//  -*- Mode: Java -*-
//
// AlternativeBindingsSet.java

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

/** Represents a set of alternative bindings collected for the pattern
 * variable <code>_theVariableSelf_</code>.
 * @author Stella Java Translator
 */
public class AlternativeBindingsSet extends Thing {
    public PatternVariable theVariable;
    public Set bindings;

  public static AlternativeBindingsSet newAlternativeBindingsSet() {
    { AlternativeBindingsSet self = null;

      self = new AlternativeBindingsSet();
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.surrogateValueInverse = Logic.SGT_LOGIC_ALTERNATIVE_BINDINGS_SET;
      self.bindings = Set.newSet();
      self.theVariable = null;
      return (self);
    }
  }

  public static Set alternativeBindings(AlternativeBindingsSet bindingsset) {
    return (bindingsset.bindings);
  }

  public void printObject(java.io.PrintStream stream) {
    { AlternativeBindingsSet self = this;

      stream.print(Native.stringDowncase(Skolem.getSkolemPrintName(self.theVariable)));
    }
  }

  public static Stella_Object accessAlternativeBindingsSetSlotValue(AlternativeBindingsSet self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_THE_VARIABLE) {
      if (setvalueP) {
        self.theVariable = ((PatternVariable)(value));
      }
      else {
        value = self.theVariable;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_BINDINGS) {
      if (setvalueP) {
        self.bindings = ((Set)(value));
      }
      else {
        value = self.bindings;
      }
    }
    else if (slotname == Logic.SYM_STELLA_SURROGATE_VALUE_INVERSE) {
      if (setvalueP) {
        self.surrogateValueInverse = ((Surrogate)(value));
      }
      else {
        value = self.surrogateValueInverse;
      }
    }
    else {
      if (setvalueP) {
        KeyValueList.setDynamicSlotValue(self.dynamicSlots, slotname, value, null);
      }
      else {
        value = self.dynamicSlots.lookup(slotname);
      }
    }
    return (value);
  }

  public Surrogate primaryType() {
    { AlternativeBindingsSet self = this;

      return (Logic.SGT_LOGIC_ALTERNATIVE_BINDINGS_SET);
    }
  }

}

