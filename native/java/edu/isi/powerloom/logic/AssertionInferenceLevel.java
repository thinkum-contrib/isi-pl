//  -*- Mode: Java -*-
//
// AssertionInferenceLevel.java

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

/** Specifies lookup of assertions only.
 * @author Stella Java Translator
 */
public class AssertionInferenceLevel extends SubsumptionInferenceLevel {
  public static AssertionInferenceLevel newAssertionInferenceLevel() {
    { AssertionInferenceLevel self = null;

      self = new AssertionInferenceLevel();
      self.keyword = null;
      return (self);
    }
  }

  public Cons levellizedAllClassInstances(Surrogate type) {
    { AssertionInferenceLevel level = this;

      { Cons members = Stella.NIL;

        { Stella_Object m = null;
          Cons iter000 = Logic.assertedCollectionMembers(Logic.getDescription(type), true).theConsList;

          while (!(iter000 == Stella.NIL)) {
            {
              m = iter000.value;
              iter000 = iter000.rest;
            }
            if (level.levellizedTestTypeOnInstanceP(m, type)) {
              members = Stella_Object.cons(m, members);
            }
          }
        }
        return (members);
      }
    }
  }

  public Surrogate primaryType() {
    { AssertionInferenceLevel self = this;

      return (Logic.SGT_LOGIC_ASSERTION_INFERENCE_LEVEL);
    }
  }

}

