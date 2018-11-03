//  -*- Mode: Java -*-
//
// ComputedProcedure.java

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

/** Each instance denotes a programming language 
 * function that computes some procedure.  The slot 'procedure-name'
 * provides the name of the procedure.  The slot 'procedure-code'
 * points directly to the procedure itself.  Both slots are optional;
 * if neither is supplied, the procedure will be invoked by extracting
 * its name from the name of the instance.
 * @author Stella Java Translator
 */
public class ComputedProcedure extends Thing {
    public Symbol procedureName;
    public java.lang.reflect.Method procedureCode;

  public static ComputedProcedure newComputedProcedure() {
    { ComputedProcedure self = null;

      self = new ComputedProcedure();
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.surrogateValueInverse = null;
      self.procedureCode = null;
      self.procedureName = null;
      return (self);
    }
  }

  public static Stella_Object accessComputedProcedureSlotValue(ComputedProcedure self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_PROCEDURE_NAME) {
      if (setvalueP) {
        self.procedureName = ((Symbol)(value));
      }
      else {
        value = self.procedureName;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_PROCEDURE_CODE) {
      if (setvalueP) {
        self.procedureCode = ((FunctionCodeWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFunctionCode(self.procedureCode);
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
    { ComputedProcedure self = this;

      return (Logic.SGT_LOGIC_COMPUTED_PROCEDURE);
    }
  }

}

