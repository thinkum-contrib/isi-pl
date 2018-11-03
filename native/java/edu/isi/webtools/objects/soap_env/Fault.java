//  -*- Mode: Java -*-
//
// Fault.java

/*
+---------------------------- BEGIN LICENSE BLOCK ---------------------------+
|                                                                            |
| Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          |
|                                                                            |
| The contents of this file are subject to the Mozilla Public License        |
| Version 1.1 (the "License"); you may not use this file except in           |
| compliance with the License. You may obtain a copy of the License at       |
| http://www.mozilla.org/MPL/                                                |
|                                                                            |
| Software distributed under the License is distributed on an "AS IS" basis, |
| WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   |
| for the specific language governing rights and limitations under the       |
| License.                                                                   |
|                                                                            |
| The Original Code is the STELLA Programming Language.                      |
|                                                                            |
| The Initial Developer of the Original Code is                              |
| UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
| 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
|                                                                            |
| Portions created by the Initial Developer are Copyright (C) 2003-2012      |
| the Initial Developer. All Rights Reserved.                                |
|                                                                            |
| Contributor(s):                                                            |
|                                                                            |
| Alternatively, the contents of this file may be used under the terms of    |
| either the GNU General Public License Version 2 or later (the "GPL"), or   |
| the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   |
| in which case the provisions of the GPL or the LGPL are applicable instead |
| of those above. If you wish to allow use of your version of this file only |
| under the terms of either the GPL or the LGPL, and not to allow others to  |
| use your version of this file under the terms of the MPL, indicate your    |
| decision by deleting the provisions above and replace them with the notice |
| and other provisions required by the GPL or the LGPL. If you do not delete |
| the provisions above, a recipient may use your version of this file under  |
| the terms of any one of the MPL, the GPL or the LGPL.                      |
|                                                                            |
+---------------------------- END LICENSE BLOCK -----------------------------+
*/

package edu.isi.webtools.objects.soap_env;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.webtools.objects.xml_objects.*;
import edu.isi.stella.*;

public class Fault extends XMLObject {
    public faultcode faultcode;
    public faultstring faultstring;
    public faultactor faultactor;
    public detail detail;

  public static Fault new_Fault() {
    { Fault self = null;

      self = new Fault();
      self.cdataContent = null;
      self.textContent = null;
      self.detail = null;
      self.faultactor = null;
      self.faultstring = null;
      self.faultcode = null;
      return (self);
    }
  }

  public static Stella_Object access_Fault_Slot_Value(Fault self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == SoapEnv.SYM_SOAP_ENV_faultcode) {
      if (setvalueP) {
        self.faultcode = ((faultcode)(value));
      }
      else {
        value = self.faultcode;
      }
    }
    else if (slotname == SoapEnv.SYM_SOAP_ENV_faultstring) {
      if (setvalueP) {
        self.faultstring = ((faultstring)(value));
      }
      else {
        value = self.faultstring;
      }
    }
    else if (slotname == SoapEnv.SYM_SOAP_ENV_faultactor) {
      if (setvalueP) {
        self.faultactor = ((faultactor)(value));
      }
      else {
        value = self.faultactor;
      }
    }
    else if (slotname == SoapEnv.SYM_SOAP_ENV_detail) {
      if (setvalueP) {
        self.detail = ((detail)(value));
      }
      else {
        value = self.detail;
      }
    }
    else {
      { OutputStringStream STREAM_000 = OutputStringStream.newOutputStringStream();

        STREAM_000.nativeStream.print("`" + slotname + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(STREAM_000.theStringReader()).fillInStackTrace()));
      }
    }
    return (value);
  }

  public Surrogate primaryType() {
    { Fault self = this;

      return (SoapEnv.SGT_SOAP_ENV_Fault);
    }
  }

}

