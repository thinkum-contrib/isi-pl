//  -*- Mode: Java -*-
//
// twoDArray.java

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

/** Two-dimensional arrays with elements of type OBJECT.
 * @author Stella Java Translator
 */
public class twoDArray extends MultiDimensionalArray {
    public int nofRows;
    public int nofColumns;
    public edu.isi.stella.Stella_Object[] theArray;

  public static twoDArray new2DArray(int nofRows, int nofColumns) {
    { twoDArray self = null;

      self = new twoDArray();
      self.nofRows = nofRows;
      self.nofColumns = nofColumns;
      self.theArray = null;
      twoDArray.initialize2DArray(self);
      return (self);
    }
  }

  /** Print the array <code>self</code> to <code>stream</code>.
   * @param stream
   */
  public void printArray(java.io.PrintStream stream) {
    { twoDArray self = this;

      { int nofRows = self.nofRows;
        int nofColumns = self.nofColumns;
        int limit = 9;

        stream.print("|i|[");
        { int row = Stella.NULL_INTEGER;
          int iter000 = 0;
          int upperBound000 = nofRows - 1;

          loop000 : while (iter000 <= upperBound000) {
            {
              row = iter000;
              iter000 = iter000 + 1;
            }
            stream.print("[");
            { int column = Stella.NULL_INTEGER;
              int iter001 = 0;
              int upperBound001 = nofColumns - 1;

              loop001 : while (iter001 <= upperBound001) {
                {
                  column = iter001;
                  iter001 = iter001 + 1;
                }
                stream.print((self.theArray)[((row * self.nofColumns) + column)]);
                if (column > limit) {
                  stream.print(" ...]");
                  break loop001;
                }
                else if (column < (nofColumns - 1)) {
                  stream.print(" ");
                }
                else {
                  stream.print("]");
                }
              }
            }
            if (row > limit) {
              stream.print(" ...]");
              break loop000;
            }
            else if (row < (nofRows - 1)) {
              stream.print(" ");
            }
            else {
              stream.print("]");
            }
          }
        }
      }
    }
  }

  /** Fill the two-dimensional array <code>self</code> in row-major-order
   * from <code>values</code>.  Missing values will retain their old values, extraneous values
   * will be ignored.
   * @param values
   */
  public void fillArray(Cons values) {
    { twoDArray self = this;

      { edu.isi.stella.Stella_Object[] nativearray = self.theArray;

        { Stella_Object value = null;
          int i = Stella.NULL_INTEGER;
          int iter000 = 0;
          int upperBound000 = (self.nofRows * self.nofColumns) - 1;
          Cons iter001 = values;

          while ((iter000 <= upperBound000) &&
              (!(iter001 == Stella.NIL))) {
            {
              i = iter000;
              iter000 = iter000 + 1;
            }
            {
              value = iter001.value;
              iter001 = iter001.rest;
            }
            nativearray[i] = value;
          }
        }
      }
    }
  }

  /** Set the element of <code>array</code> at position [<code>row</code>, <code>column</code>]
   * to <code>value</code> and return the result.
   * @param value
   * @param row
   * @param column
   * @return Stella_Object
   */
  public Stella_Object twoDElementSetter(Stella_Object value, int row, int column) {
    { twoDArray array = this;

      return ((array.theArray)[((row * array.nofColumns) + column)] = value);
    }
  }

  /** Return the element of <code>array</code> at position [<code>row</code>, <code>column</code>].
   * @param row
   * @param column
   * @return Stella_Object
   */
  public Stella_Object twoDElement(int row, int column) {
    { twoDArray array = this;

      return ((array.theArray)[((row * array.nofColumns) + column)]);
    }
  }

  public static void initialize2DArray(twoDArray self) {
    { Vector vector = Vector.newVector(self.nofRows * self.nofColumns);

      self.theArray = vector.theArray;
      vector.theArray = null;
    }
  }

  public void printObject(java.io.PrintStream stream) {
    { twoDArray self = this;

      self.printArray(stream);
    }
  }

  public static Stella_Object access2DArraySlotValue(twoDArray self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_NOF_ROWS) {
      if (setvalueP) {
        self.nofRows = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.nofRows);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_NOF_COLUMNS) {
      if (setvalueP) {
        self.nofColumns = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.nofColumns);
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
    { twoDArray self = this;

      return (Logic.SGT_LOGIC_2_D_ARRAY);
    }
  }

}

