//  -*- Mode: Java -*-
//
// TokenizerStreamState.java

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

public class TokenizerStreamState extends StandardObject {
    public byte[] buffer;
    public int bufferSize;
    public int cursor;
    public int end;
    public int state;
    public TokenizerToken tokenList;

  public static TokenizerStreamState newTokenizerStreamState() {
    { TokenizerStreamState self = null;

      self = new TokenizerStreamState();
      self.tokenList = null;
      self.state = 1;
      self.end = Stella.$TOKENIZER_INITIAL_BUFFER_SIZE$;
      self.cursor = Stella.$TOKENIZER_INITIAL_BUFFER_SIZE$;
      self.bufferSize = Stella.$TOKENIZER_INITIAL_BUFFER_SIZE$;
      self.buffer = new byte[Stella.$TOKENIZER_INITIAL_BUFFER_SIZE$];
      return (self);
    }
  }

  public static Stella_Object accessTokenizerStreamStateSlotValue(TokenizerStreamState self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Stella.SYM_STELLA_BUFFER_SIZE) {
      if (setvalueP) {
        self.bufferSize = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.bufferSize);
      }
    }
    else if (slotname == Stella.SYM_STELLA_CURSOR) {
      if (setvalueP) {
        self.cursor = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.cursor);
      }
    }
    else if (slotname == Stella.SYM_STELLA_END) {
      if (setvalueP) {
        self.end = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.end);
      }
    }
    else if (slotname == Stella.SYM_STELLA_STATE) {
      if (setvalueP) {
        self.state = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.state);
      }
    }
    else if (slotname == Stella.SYM_STELLA_TOKEN_LIST) {
      if (setvalueP) {
        self.tokenList = ((TokenizerToken)(value));
      }
      else {
        value = self.tokenList;
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
    { TokenizerStreamState self = this;

      return (Stella.SGT_STELLA_TOKENIZER_STREAM_STATE);
    }
  }

  public static void ensureTokenizerBufferSize(TokenizerStreamState state, int currenttokenstart, int requiredspace) {
    { int size = state.bufferSize;
      int newsize = size;
      int end = ((state.end) % size);
      int freespace = ((currenttokenstart == -1) ? size : (((end <= currenttokenstart) ? (currenttokenstart - end) : (currenttokenstart + (size - end)))));
      byte[] buffer = state.buffer;
      byte[] newbuffer = buffer;

      while (freespace < requiredspace) {
        freespace = freespace + newsize;
        newsize = newsize * 2;
      }
      if (newsize > size) {
        newbuffer = new byte[newsize];
        if (currenttokenstart < 0) {
          state.cursor = 0;
          state.end = newsize;
        }
        else if (end > currenttokenstart) {
          { int i = Stella.NULL_INTEGER;
            int iter000 = currenttokenstart;
            int upperBound000 = end - 1;

            while (iter000 <= upperBound000) {
              {
                i = iter000;
                iter000 = iter000 + 1;
              }
              newbuffer[i] = (byte)(((char) (0x00ff & buffer[i])));
            }
          }
        }
        else {
          { int i = Stella.NULL_INTEGER;
            int iter001 = currenttokenstart;
            int upperBound001 = size - 1;

            while (iter001 <= upperBound001) {
              {
                i = iter001;
                iter001 = iter001 + 1;
              }
              newbuffer[i] = (byte)(((char) (0x00ff & buffer[i])));
            }
          }
          { int j = Stella.NULL_INTEGER;
            int i = Stella.NULL_INTEGER;
            int iter002 = 0;
            int upperBound002 = end - 1;
            int iter003 = size;

            while (iter002 <= upperBound002) {
              {
                i = iter002;
                iter002 = iter002 + 1;
              }
              {
                j = iter003;
                iter003 = iter003 + 1;
              }
              newbuffer[j] = (byte)(((char) (0x00ff & buffer[i])));
            }
          }
          state.end = size + end;
          state.cursor = state.end;
        }
        state.buffer = newbuffer;
        state.bufferSize = newsize;
      }
    }
  }

}

