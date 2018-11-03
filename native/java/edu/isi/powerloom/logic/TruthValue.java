//  -*- Mode: Java -*-
//
// TruthValue.java

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

public class TruthValue extends LogicObject {
    public double positiveScore;

  public static TruthValue newTruthValue() {
    { TruthValue self = null;

      self = new TruthValue();
      self.dependentPropositionsIndex = null;
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.homeContext = ((Context)(Stella.$CONTEXT$.get()));
      self.surrogateValueInverse = null;
      self.variableValueInverse = null;
      self.positiveScore = 0.0;
      LogicObject.logLogicObject(self);
      return (self);
    }
  }

  public static void printTruthValue(TruthValue self, OutputStream stream) {
    if (self == Logic.TRUE_TRUTH_VALUE) {
      stream.nativeStream.print("TRUE");
    }
    else if (self == Logic.FALSE_TRUTH_VALUE) {
      stream.nativeStream.print("FALSE");
    }
    else if (self == Logic.DEFAULT_TRUE_TRUTH_VALUE) {
      stream.nativeStream.print("DEFAULT-TRUE");
    }
    else if (self == Logic.DEFAULT_FALSE_TRUTH_VALUE) {
      stream.nativeStream.print("DEFAULT-FALSE");
    }
    else if (self == Logic.UNKNOWN_TRUTH_VALUE) {
      stream.nativeStream.print("UNKNOWN");
    }
    else {
      stream.nativeStream.print("|i|" + self.primaryType());
    }
  }

  /** Return TRUE if <code>self</code> represents UNKNOWN.
   * @param self
   * @return boolean
   */
  public static boolean unknownTruthValueP(TruthValue self) {
    return ((self == Logic.UNKNOWN_TRUTH_VALUE) ||
        (self == null));
  }

  /** Return TRUE if <code>self</code> is a default truth value.
   * @param self
   * @return boolean
   */
  public static boolean defaultTruthValueP(TruthValue self) {
    return ((self == Logic.DEFAULT_TRUE_TRUTH_VALUE) ||
        (self == Logic.DEFAULT_FALSE_TRUTH_VALUE));
  }

  /** Return TRUE if <code>self</code> is a strict truth value.
   * @param self
   * @return boolean
   */
  public static boolean strictTruthValueP(TruthValue self) {
    return ((self == Logic.TRUE_TRUTH_VALUE) ||
        (self == Logic.FALSE_TRUTH_VALUE));
  }

  /** Return TRUE if <code>self</code> represents some form of falsehood.
   * @param self
   * @return boolean
   */
  public static boolean falseTruthValueP(TruthValue self) {
    return ((self == Logic.FALSE_TRUTH_VALUE) ||
        (self == Logic.DEFAULT_FALSE_TRUTH_VALUE));
  }

  /** Return TRUE if <code>self</code> represents some form of truth.
   * @param self
   * @return boolean
   */
  public static boolean trueTruthValueP(TruthValue self) {
    return ((self == Logic.TRUE_TRUTH_VALUE) ||
        (self == Logic.DEFAULT_TRUE_TRUTH_VALUE));
  }

  /** If <code>tv2</code> has greater strength than <code>tv1</code>, adapt the strength of <code>tv1</code> (not
   * its value!) and return the result.  Otherwise, return <code>tv1</code> unmodified.
   * @param tv1
   * @param tv2
   * @return TruthValue
   */
  public static TruthValue strengthenTruthValue(TruthValue tv1, TruthValue tv2) {
    if (((tv2 == Logic.TRUE_TRUTH_VALUE) ||
        (tv2 == Logic.FALSE_TRUTH_VALUE)) &&
        ((tv1 == Logic.DEFAULT_TRUE_TRUTH_VALUE) ||
         (tv1 == Logic.DEFAULT_FALSE_TRUTH_VALUE))) {
      if ((tv1 == Logic.TRUE_TRUTH_VALUE) ||
          (tv1 == Logic.DEFAULT_TRUE_TRUTH_VALUE)) {
        return (Logic.TRUE_TRUTH_VALUE);
      }
      if ((tv1 == Logic.FALSE_TRUTH_VALUE) ||
          (tv1 == Logic.DEFAULT_FALSE_TRUTH_VALUE)) {
        return (Logic.FALSE_TRUTH_VALUE);
      }
    }
    return (tv1);
  }

  /** If <code>tv2</code> has lesser strength than <code>tv1</code>, adapt the strength of <code>tv1</code> (not
   * its value!) and return the result.  Otherwise, return <code>tv1</code> unmodified.
   * @param tv1
   * @param tv2
   * @return TruthValue
   */
  public static TruthValue weakenTruthValue(TruthValue tv1, TruthValue tv2) {
    if ((tv2 == Logic.UNKNOWN_TRUTH_VALUE) ||
        (tv2 == null)) {
      return (Logic.UNKNOWN_TRUTH_VALUE);
    }
    else if ((tv2 == Logic.DEFAULT_TRUE_TRUTH_VALUE) ||
        (tv2 == Logic.DEFAULT_FALSE_TRUTH_VALUE)) {
      if ((tv1 == Logic.TRUE_TRUTH_VALUE) ||
          (tv1 == Logic.DEFAULT_TRUE_TRUTH_VALUE)) {
        return (Logic.DEFAULT_TRUE_TRUTH_VALUE);
      }
      if ((tv1 == Logic.FALSE_TRUTH_VALUE) ||
          (tv1 == Logic.DEFAULT_FALSE_TRUTH_VALUE)) {
        return (Logic.DEFAULT_FALSE_TRUTH_VALUE);
      }
    }
    return (tv1);
  }

  /** Return the logical negation of <code>self</code>.
   * @param self
   * @return TruthValue
   */
  public static TruthValue invertTruthValue(TruthValue self) {
    if (self == Logic.TRUE_TRUTH_VALUE) {
      return (Logic.FALSE_TRUTH_VALUE);
    }
    else if (self == Logic.DEFAULT_TRUE_TRUTH_VALUE) {
      return (Logic.DEFAULT_FALSE_TRUTH_VALUE);
    }
    else if (self == Logic.FALSE_TRUTH_VALUE) {
      return (Logic.TRUE_TRUTH_VALUE);
    }
    else if (self == Logic.DEFAULT_FALSE_TRUTH_VALUE) {
      return (Logic.DEFAULT_TRUE_TRUTH_VALUE);
    }
    else {
      return (Logic.UNKNOWN_TRUTH_VALUE);
    }
  }

  /** Return the logical disjunction of truth values <code>tv1</code> and <code>tv2</code>.
   * @param tv1
   * @param tv2
   * @return TruthValue
   */
  public static TruthValue disjoinTruthValues(TruthValue tv1, TruthValue tv2) {
    if ((tv1 == Logic.TRUE_TRUTH_VALUE) ||
        (tv2 == Logic.TRUE_TRUTH_VALUE)) {
      return (Logic.TRUE_TRUTH_VALUE);
    }
    else if ((tv1 == Logic.DEFAULT_TRUE_TRUTH_VALUE) ||
        (tv2 == Logic.DEFAULT_TRUE_TRUTH_VALUE)) {
      return (Logic.DEFAULT_TRUE_TRUTH_VALUE);
    }
    else if ((tv1 == null) ||
        ((tv1 == Logic.UNKNOWN_TRUTH_VALUE) ||
         ((tv2 == null) ||
          (tv2 == Logic.UNKNOWN_TRUTH_VALUE)))) {
      return (Logic.UNKNOWN_TRUTH_VALUE);
    }
    else if ((tv1 == Logic.DEFAULT_FALSE_TRUTH_VALUE) ||
        (tv2 == Logic.DEFAULT_FALSE_TRUTH_VALUE)) {
      return (Logic.DEFAULT_FALSE_TRUTH_VALUE);
    }
    else {
      return (Logic.FALSE_TRUTH_VALUE);
    }
  }

  /** Return the logical conjunction of truth values <code>tv1</code> and <code>tv2</code>.
   * @param tv1
   * @param tv2
   * @return TruthValue
   */
  public static TruthValue conjoinTruthValues(TruthValue tv1, TruthValue tv2) {
    if ((tv1 == Logic.FALSE_TRUTH_VALUE) ||
        (tv2 == Logic.FALSE_TRUTH_VALUE)) {
      return (Logic.FALSE_TRUTH_VALUE);
    }
    else if ((tv1 == Logic.DEFAULT_FALSE_TRUTH_VALUE) &&
        (tv2 == Logic.DEFAULT_TRUE_TRUTH_VALUE)) {
      return (Logic.UNKNOWN_TRUTH_VALUE);
    }
    else if ((tv1 == Logic.DEFAULT_TRUE_TRUTH_VALUE) &&
        (tv2 == Logic.DEFAULT_FALSE_TRUTH_VALUE)) {
      return (Logic.UNKNOWN_TRUTH_VALUE);
    }
    else if ((tv1 == null) ||
        ((tv1 == Logic.UNKNOWN_TRUTH_VALUE) ||
         ((tv2 == null) ||
          (tv2 == Logic.UNKNOWN_TRUTH_VALUE)))) {
      return (Logic.UNKNOWN_TRUTH_VALUE);
    }
    else if ((tv1 == Logic.DEFAULT_FALSE_TRUTH_VALUE) ||
        (tv2 == Logic.DEFAULT_FALSE_TRUTH_VALUE)) {
      return (Logic.DEFAULT_FALSE_TRUTH_VALUE);
    }
    else if ((tv1 == Logic.DEFAULT_TRUE_TRUTH_VALUE) ||
        (tv2 == Logic.DEFAULT_TRUE_TRUTH_VALUE)) {
      return (Logic.DEFAULT_TRUE_TRUTH_VALUE);
    }
    else {
      return (Logic.TRUE_TRUTH_VALUE);
    }
  }

  public static Stella_Object accessTruthValueSlotValue(TruthValue self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_POSITIVE_SCORE) {
      if (setvalueP) {
        self.positiveScore = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.positiveScore);
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
    { TruthValue self = this;

      return (Logic.SGT_LOGIC_TRUTH_VALUE);
    }
  }

}

