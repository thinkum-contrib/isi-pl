//  -*- Mode: Java -*-
//
// CheckTypesRecord.java

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

public class CheckTypesRecord extends StandardObject {
    public Stella_Object parentProposition;
    public Description parentDescription;
    public Module module;

  public static CheckTypesRecord newCheckTypesRecord() {
    { CheckTypesRecord self = null;

      self = new CheckTypesRecord();
      self.module = null;
      self.parentDescription = null;
      self.parentProposition = null;
      return (self);
    }
  }

  public static Stella_Object accessCheckTypesRecordSlotValue(CheckTypesRecord self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_PARENT_PROPOSITION) {
      if (setvalueP) {
        self.parentProposition = value;
      }
      else {
        value = self.parentProposition;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_PARENT_DESCRIPTION) {
      if (setvalueP) {
        self.parentDescription = ((Description)(value));
      }
      else {
        value = self.parentDescription;
      }
    }
    else if (slotname == Logic.SYM_STELLA_MODULE) {
      if (setvalueP) {
        self.module = ((Module)(value));
      }
      else {
        value = self.module;
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
    { CheckTypesRecord self = this;

      return (Logic.SGT_LOGIC_CHECK_TYPES_RECORD);
    }
  }

}

