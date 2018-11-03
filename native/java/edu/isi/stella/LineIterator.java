//  -*- Mode: Java -*-
//
// LineIterator.java

/*--------------------------- BEGIN LICENSE BLOCK ---------------------------+
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
| Portions created by the Initial Developer are Copyright (C) 1996-2003      |
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
+---------------------------- END LICENSE BLOCK ----------------------------*/

package edu.isi.stella;

import edu.isi.stella.javalib.*;

/** Iterator that yields lines from an input stream.
 * @author Stella Java Translator
 */
public class LineIterator extends StreamIterator {
    /** The current value of this iterator
     */
    public String value;

  public static LineIterator newLineIterator() {
    { LineIterator self = null;

      self = new LineIterator();
      self.firstIterationP = Stella.TRUE;
      self.value = null;
      self.theStream = null;
      return (self);
    }
  }

  public boolean nextP() {
    { LineIterator self = this;

      self.firstIterationP = Stella.FALSE;
      { String line = null;
        boolean eofP = Stella.FALSE;

        { Object [] caller_MV_returnarray = new Object[1];

          line = InputStream.readLine(self.theStream, caller_MV_returnarray);
          eofP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[0])).wrapperValue));
        }
        if (eofP) {
          Stream.closeStream(self.theStream);
          return (Stella.FALSE);
        }
        else {
          self.value = line;
          return (Stella.TRUE);
        }
      }
    }
  }

  public Surrogate primaryType() {
    { LineIterator self = this;

      return (Stella.SGT_STELLA_LINE_ITERATOR);
    }
  }

  public void free() {
    { LineIterator self = this;

      if (StreamIterator.terminateStreamIteratorP(self)) {
        Stella_Object.unmake(self);
      }
    }
  }

}

