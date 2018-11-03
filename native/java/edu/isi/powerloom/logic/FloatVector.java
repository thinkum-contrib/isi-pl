//  -*- Mode: Java -*-
//
// FloatVector.java

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

public class FloatVector extends AbstractCollection {
    public int arraySize;
    public edu.isi.stella.Stella_Object[] theArray;

  public static FloatVector newFloatVector(int arraySize) {
    { FloatVector self = null;

      self = new FloatVector();
      self.arraySize = arraySize;
      self.theArray = null;
      FloatVector.initializeFloatVector(self);
      return (self);
    }
  }

  public boolean memberP(double renamed_Object) {
    { FloatVector self = this;

      { edu.isi.stella.Stella_Object[] array = self.theArray;

        { int i = Stella.NULL_INTEGER;
          int iter000 = 0;
          int upperBound000 = self.arraySize - 1;

          while (iter000 <= upperBound000) {
            {
              i = iter000;
              iter000 = iter000 + 1;
            }
            if (((FloatWrapper)(((FloatWrapper)(array[i])))).wrapperValue == renamed_Object) {
              return (Stella.TRUE);
            }
          }
        }
        return (Stella.FALSE);
      }
    }
  }

  public int length() {
    { FloatVector self = this;

      return (self.arraySize);
    }
  }

  public double nthSetter(double value, int position) {
    { FloatVector self = this;

      return (((FloatWrapper)(((FloatWrapper)((self.theArray)[position])))).wrapperValue = value);
    }
  }

  public double nth(int position) {
    { FloatVector self = this;

      return (((FloatWrapper)(((FloatWrapper)((self.theArray)[position])))).wrapperValue);
    }
  }

  /** Return TRUE if 'self' has length &gt; 0.
   * @return boolean
   */
  public boolean nonEmptyP() {
    { FloatVector self = this;

      return (self.arraySize > 0);
    }
  }

  /** Return TRUE if 'self' has length 0.
   * @return boolean
   */
  public boolean emptyP() {
    { FloatVector self = this;

      return (self.arraySize == 0);
    }
  }

  public void printVector(java.io.PrintStream stream) {
    { FloatVector self = this;

      if (self.arraySize == 0) {
        stream.print("|i|[]");
      }
      else {
        { int i = 0;
          int limit = 9;

          stream.print("|i|[");
          { double element = Stella.NULL_FLOAT;
            FloatVector vector000 = self;
            int index000 = 0;
            int length000 = vector000.arraySize;

            loop000 : while (index000 < length000) {
              {
                element = ((FloatWrapper)(((FloatWrapper)((vector000.theArray)[index000])))).wrapperValue;
                index000 = index000 + 1;
              }
              stream.print(element);
              i = i + 1;
              if (i > limit) {
                break loop000;
              }
              if (i < self.arraySize) {
                stream.print(" ");
              }
            }
          }
          if ((i <= limit) ||
              (i == self.arraySize)) {
            stream.print("]");
          }
          else {
            stream.print(" ...]");
          }
        }
      }
    }
  }

  public static void initializeFloatVector(FloatVector self) {
    { Vector vector = Vector.newVector(self.arraySize);

      { int i = Stella.NULL_INTEGER;
        int iter000 = 0;
        int upperBound000 = vector.length() - 1;

        while (iter000 <= upperBound000) {
          {
            i = iter000;
            iter000 = iter000 + 1;
          }
          (vector.theArray)[i] = (FloatWrapper.newFloatWrapper(Stella.NULL_FLOAT));
        }
      }
      self.theArray = ((edu.isi.stella.Stella_Object[])(vector.theArray));
      vector.theArray = null;
    }
  }

  public void printObject(java.io.PrintStream stream) {
    { FloatVector self = this;

      self.printVector(stream);
    }
  }

  public static Stella_Object accessFloatVectorSlotValue(FloatVector self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_STELLA_ARRAY_SIZE) {
      if (setvalueP) {
        self.arraySize = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.arraySize);
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
    { FloatVector self = this;

      return (Logic.SGT_LOGIC_FLOAT_VECTOR);
    }
  }

}

