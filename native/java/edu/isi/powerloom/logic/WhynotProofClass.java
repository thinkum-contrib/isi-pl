//  -*- Mode: Java -*-
//
// WhynotProofClass.java

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

/** Set of equivalent WhyNot proofs that differ in at most one
 * variable binding all on the same <code>deviatingVariable</code>.
 * @author Stella Java Translator
 */
public class WhynotProofClass extends Set {
    public Justification representative;
    public Justification deviatingPattern;
    public PatternVariable deviatingVariable;
    public List deviatingInstances;

  public static WhynotProofClass newWhynotProofClass() {
    { WhynotProofClass self = null;

      self = new WhynotProofClass();
      self.theConsList = Stella.NIL;
      self.deviatingInstances = List.newList();
      self.deviatingVariable = null;
      self.deviatingPattern = null;
      self.representative = null;
      return (self);
    }
  }

  public static boolean betterWhynotProofClassP(WhynotProofClass class1, WhynotProofClass class2) {
    return (Justification.betterWhynotProofP(class1.representative, class2.representative));
  }

  public static boolean insertWhynotProofToClassP(WhynotProofClass renamed_Class, Justification proof) {
    if (renamed_Class.emptyP()) {
      renamed_Class.theConsList = Stella_Object.cons(proof, renamed_Class.theConsList);
      renamed_Class.representative = proof;
      return (true);
    }
    { KeyValueList deviations = KeyValueList.newKeyValueList();
      int founddeviations = Justification.computeProofDeviation(proof, renamed_Class.representative, ((Integer)(Logic.$MAX_WHYNOT_PROOF_CLASS_DEVIATIONS$.get())).intValue(), deviations);

      if (founddeviations != Stella.NULL_INTEGER) {
        { Justification repdev = null;
          Justification newdev = null;
          KvCons iter000 = deviations.theKvList;

          while (iter000 != null) {
            newdev = ((Justification)(iter000.key));
            {
              repdev = ((Justification)(iter000.value));
              iter000 = iter000.rest;
            }
            if (founddeviations == 0) {
              return (true);
            }
            if (renamed_Class.deviatingPattern == null) {
              renamed_Class.deviatingPattern = repdev;
            }
            { Stella_Object repvalue = null;
              PatternVariable repvar = null;
              Stella_Object newvalue = null;
              PatternVariable newvar = null;
              KvCons iter001 = newdev.substitution.theKvList;
              KvCons iter002 = renamed_Class.deviatingPattern.substitution.theKvList;

              while ((iter001 != null) &&
                  (iter002 != null)) {
                newvar = ((PatternVariable)(iter001.key));
                {
                  newvalue = iter001.value;
                  iter001 = iter001.rest;
                }
                repvar = ((PatternVariable)(iter002.key));
                {
                  repvalue = iter002.value;
                  iter002 = iter002.rest;
                }
                if (!Stella_Object.eqlP(newvalue, repvalue)) {
                  repvar = repvar;
                  if (renamed_Class.deviatingVariable == null) {
                    renamed_Class.deviatingVariable = newvar;
                    renamed_Class.deviatingInstances.insert(repvalue);
                  }
                  else if (!(newvar == renamed_Class.deviatingVariable)) {
                    return (false);
                  }
                  else if (renamed_Class.deviatingInstances.memberP(newvalue)) {
                    return (true);
                  }
                  renamed_Class.deviatingInstances.insert(newvalue);
                }
              }
            }
            renamed_Class.theConsList = Stella_Object.cons(proof, renamed_Class.theConsList);
            return (true);
          }
        }
      }
      return (false);
    }
  }

  public static Stella_Object accessWhynotProofClassSlotValue(WhynotProofClass self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_REPRESENTATIVE) {
      if (setvalueP) {
        self.representative = ((Justification)(value));
      }
      else {
        value = self.representative;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_DEVIATING_PATTERN) {
      if (setvalueP) {
        self.deviatingPattern = ((Justification)(value));
      }
      else {
        value = self.deviatingPattern;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_DEVIATING_VARIABLE) {
      if (setvalueP) {
        self.deviatingVariable = ((PatternVariable)(value));
      }
      else {
        value = self.deviatingVariable;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_DEVIATING_INSTANCES) {
      if (setvalueP) {
        self.deviatingInstances = ((List)(value));
      }
      else {
        value = self.deviatingInstances;
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
    { WhynotProofClass self = this;

      return (Logic.SGT_LOGIC_WHYNOT_PROOF_CLASS);
    }
  }

}

