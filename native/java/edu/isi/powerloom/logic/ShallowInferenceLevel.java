//  -*- Mode: Java -*-
//
// ShallowInferenceLevel.java

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

/** Specifies lookup of assertions plus simple frame computations.
 * @author Stella Java Translator
 */
public class ShallowInferenceLevel extends SubsumptionInferenceLevel {
  public static ShallowInferenceLevel newShallowInferenceLevel() {
    { ShallowInferenceLevel self = null;

      self = new ShallowInferenceLevel();
      self.keyword = null;
      return (self);
    }
  }

  public Cons levellizedAllSlotValueTypes(LogicObject self, Surrogate relation) {
    { ShallowInferenceLevel level = this;

      { NamedDescription description = Logic.getDescription(relation);
        Cons valuetypes = Logic.allRelationValues(Logic.SGT_PL_KERNEL_KB_RANGE_TYPE, Stella.consList(Stella_Object.cons(description, Stella_Object.cons(self, Stella.NIL))));

        if (Logic.testClosedSlotP(relation) ||
            Logic.testFunctionSlotP(relation)) {
          { Cons fillers = LogicObject.allSlotValues(self, relation);
            Cons possibletypes = Stella.NIL;

            { Stella_Object f = null;
              Cons iter000 = fillers;

              while (!(iter000 == Stella.NIL)) {
                {
                  f = iter000.value;
                  iter000 = iter000.rest;
                }
                { NamedDescription d = null;
                  Cons iter001 = Logic.allAssertedTypes(f);

                  while (!(iter001 == Stella.NIL)) {
                    {
                      d = ((NamedDescription)(iter001.value));
                      iter001 = iter001.rest;
                    }
                    if (!possibletypes.memberP(d)) {
                      possibletypes = Stella_Object.cons(d, possibletypes);
                    }
                  }
                }
              }
            }
            { LogicObject d = null;
              Cons iter002 = possibletypes;

              while (!(iter002 == Stella.NIL)) {
                {
                  d = ((LogicObject)(iter002.value));
                  iter002 = iter002.rest;
                }
                { boolean testValue000 = false;

                  testValue000 = !valuetypes.memberP(d);
                  if (testValue000) {
                    { boolean alwaysP000 = true;

                      { Stella_Object f = null;
                        Cons iter003 = fillers;

                        loop003 : while (!(iter003 == Stella.NIL)) {
                          {
                            f = iter003.value;
                            iter003 = iter003.rest;
                          }
                          if (!Logic.testTypeOnInstanceP(f, d.surrogateValueInverse)) {
                            alwaysP000 = false;
                            break loop003;
                          }
                        }
                      }
                      testValue000 = alwaysP000;
                    }
                  }
                  if (testValue000) {
                    valuetypes = Stella_Object.cons(d, valuetypes);
                  }
                }
              }
            }
          }
        }
        return (Logic.filterOutUnnamedDescriptions(valuetypes));
      }
    }
  }

  public int levellizedGetSlotMaximumCardinality(LogicObject self, Surrogate relation) {
    { ShallowInferenceLevel level = this;

      { NamedDescription description = Logic.getDescription(relation);
        Stella_Object maxcardinality = Logic.allRelationValues(Logic.SGT_PL_KERNEL_KB_RANGE_MAX_CARDINALITY, Stella.consList(Stella_Object.cons(description, Stella_Object.cons(self, Stella.NIL)))).value;
        int fillercount = Stella.NULL_INTEGER;

        if (Logic.testClosedSlotP(relation)) {
          fillercount = LogicObject.allSlotValues(self, relation).length();
        }
        else if (Logic.testFunctionSlotP(relation)) {
          fillercount = 1;
        }
        if (maxcardinality == null) {
          return (fillercount);
        }
        else if (fillercount == Stella.NULL_INTEGER) {
          return (((IntegerWrapper)(maxcardinality)).wrapperValue);
        }
        else {
          return (Stella.min(((IntegerWrapper)(maxcardinality)).wrapperValue, fillercount));
        }
      }
    }
  }

  public int levellizedGetSlotMinimumCardinality(LogicObject self, Surrogate relation) {
    { ShallowInferenceLevel level = this;

      { NamedDescription description = Logic.getDescription(relation);
        Stella_Object mincardinality = Logic.allRelationValues(Logic.SGT_PL_KERNEL_KB_RANGE_MIN_CARDINALITY, Stella.consList(Stella_Object.cons(description, Stella_Object.cons(self, Stella.NIL)))).value;
        int fillercount = LogicObject.allSlotValues(self, relation).length();

        if (mincardinality == null) {
          mincardinality = Stella.wrapInteger(0);
        }
        return (Stella.max(((IntegerWrapper)(mincardinality)).wrapperValue, fillercount));
      }
    }
  }

  public boolean levellizedTestTypeOnInstanceP(Stella_Object self, Surrogate type) {
    { ShallowInferenceLevel level = this;

      { boolean foundP000 = false;

        { Proposition p = null;
          Iterator iter000 = Logic.allTrueDependentPropositions(self, type, false);

          loop000 : while (iter000.nextP()) {
            p = ((Proposition)(iter000.value));
            if (p.kind == Logic.KWD_ISA) {
              foundP000 = true;
              break loop000;
            }
          }
        }
        { boolean value000 = foundP000;

          return (value000);
        }
      }
    }
  }

  public Surrogate primaryType() {
    { ShallowInferenceLevel self = this;

      return (Logic.SGT_LOGIC_SHALLOW_INFERENCE_LEVEL);
    }
  }

}

