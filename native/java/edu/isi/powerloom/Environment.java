//  -*- Mode: Java -*-
//
// Environment.java

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

package edu.isi.powerloom;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.powerloom.logic.*;
import edu.isi.stella.*;

public class Environment extends StandardObject {
    public String level;

  public static Environment newEnvironment() {
    { Environment self = null;

      self = new Environment();
      self.level = null;
      return (self);
    }
  }

  /** Return the currently set module
   * @param environment
   * @return Module
   */
  public static Module getCurrentModule(Environment environment) {
    environment = environment;
    return (((Module)(Stella.$MODULE$.get())));
  }

  public void printObject(java.io.PrintStream stream) {
    { Environment self = this;

      stream.print("|ENV|" + self.level);
    }
  }

  public static Stella_Object accessEnvironmentSlotValue(Environment self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == PLI.SYM_LOGIC_LEVEL) {
      if (setvalueP) {
        self.level = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapString(self.level);
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
    { Environment self = this;

      return (PLI.SGT_PLI_ENVIRONMENT);
    }
  }

}

