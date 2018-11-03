//  -*- Mode: Java -*-
//
// SubsumptionInferenceLevel.java

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

/** Specifies lookup augmented with cached
 * subsumption links and equality reasoning.
 * @author Stella Java Translator
 */
public class SubsumptionInferenceLevel extends BacktrackingInferenceLevel {
  public static SubsumptionInferenceLevel newSubsumptionInferenceLevel() {
    { SubsumptionInferenceLevel self = null;

      self = new SubsumptionInferenceLevel();
      self.keyword = null;
      return (self);
    }
  }

  public Cons levellizedAllSlotValueTypes(LogicObject self, Surrogate relation) {
    { SubsumptionInferenceLevel level = this;

      { Cons valuetypes = Logic.SHALLOW_INFERENCE.levellizedAllSlotValueTypes(self, relation);

        { NamedDescription superrelation = null;
          Cons iter000 = NamedDescription.allSuperrelations(Logic.getDescription(relation), Stella.FALSE);

          while (!(iter000 == Stella.NIL)) {
            {
              superrelation = ((NamedDescription)(iter000.value));
              iter000 = iter000.rest;
            }
            { Stella_Object supertype = null;
              Cons iter001 = Logic.allRelationValues(Logic.SGT_PL_KERNEL_KB_RANGE_TYPE, Stella.consList(Stella_Object.cons(superrelation, Stella_Object.cons(self, Stella.NIL))));

              while (!(iter001 == Stella.NIL)) {
                {
                  supertype = iter001.value;
                  iter001 = iter001.rest;
                }
                if (!valuetypes.memberP(supertype)) {
                  valuetypes = Stella_Object.cons(supertype, valuetypes);
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
    { SubsumptionInferenceLevel level = this;

      { int maxcardinality = Logic.SHALLOW_INFERENCE.levellizedGetSlotMaximumCardinality(self, relation);

        { NamedDescription superdescription = null;
          Cons iter000 = NamedDescription.allSuperrelations(Logic.getDescription(relation), Stella.FALSE);

          while (!(iter000 == Stella.NIL)) {
            {
              superdescription = ((NamedDescription)(iter000.value));
              iter000 = iter000.rest;
            }
            { Stella_Object supermaxcardinality = Logic.allRelationValues(Logic.SGT_PL_KERNEL_KB_RANGE_MAX_CARDINALITY, Stella.consList(Stella_Object.cons(superdescription, Stella_Object.cons(self, Stella.NIL)))).value;

              if (supermaxcardinality != null) {
                if (maxcardinality != Stella.NULL_INTEGER) {
                  maxcardinality = Stella.min(maxcardinality, ((IntegerWrapper)(supermaxcardinality)).wrapperValue);
                }
                else {
                  maxcardinality = ((IntegerWrapper)(supermaxcardinality)).wrapperValue;
                }
              }
            }
          }
        }
        return (maxcardinality);
      }
    }
  }

  public int levellizedGetSlotMinimumCardinality(LogicObject self, Surrogate relation) {
    { SubsumptionInferenceLevel level = this;

      { int mincardinality = Logic.SHALLOW_INFERENCE.levellizedGetSlotMinimumCardinality(self, relation);

        { NamedDescription subdescription = null;
          Cons iter000 = NamedDescription.allSubrelations(Logic.getDescription(relation), Stella.FALSE);

          while (!(iter000 == Stella.NIL)) {
            {
              subdescription = ((NamedDescription)(iter000.value));
              iter000 = iter000.rest;
            }
            { Stella_Object submincardinality = Logic.allRelationValues(Logic.SGT_PL_KERNEL_KB_RANGE_MIN_CARDINALITY, Stella.consList(Stella_Object.cons(subdescription, Stella_Object.cons(self, Stella.NIL)))).value;

              if (submincardinality != null) {
                mincardinality = Stella.max(mincardinality, ((IntegerWrapper)(submincardinality)).wrapperValue);
              }
            }
          }
        }
        return (mincardinality);
      }
    }
  }

  public boolean levellizedTestRelationOnArgumentsP(Surrogate relation, Cons arguments) {
    { SubsumptionInferenceLevel level = this;

      { boolean foundP000 = Stella.FALSE;

        { ConsIterator p = Logic.allPropositionsMatchingArguments(arguments, relation, level == Logic.SUBSUMPTION_INFERENCE).allocateIterator();

          loop000 : while (p.nextP()) {
            foundP000 = Stella.TRUE;
            break loop000;
          }
        }
        { boolean value000 = foundP000;

          return (value000);
        }
      }
    }
  }

  public Cons levellizedAllRelationValues(Surrogate relation, Cons nminusonearguments) {
    { SubsumptionInferenceLevel level = this;

      { Cons values = Stella.NIL;

        { Proposition p = null;
          Cons iter000 = Logic.allPropositionsMatchingArguments(nminusonearguments, relation, level == Logic.SUBSUMPTION_INFERENCE);
          Cons collect000 = null;

          while (!(iter000 == Stella.NIL)) {
            {
              p = ((Proposition)(iter000.value));
              iter000 = iter000.rest;
            }
            if (collect000 == null) {
              {
                collect000 = Stella_Object.cons(Logic.valueOf((p.arguments.theArray)[(p.arguments.length() - 1)]), Stella.NIL);
                if (values == Stella.NIL) {
                  values = collect000;
                }
                else {
                  Cons.addConsToEndOfConsList(values, collect000);
                }
              }
            }
            else {
              {
                collect000.rest = Stella_Object.cons(Logic.valueOf((p.arguments.theArray)[(p.arguments.length() - 1)]), Stella.NIL);
                collect000 = collect000.rest;
              }
            }
          }
        }
        return (values);
      }
    }
  }

  public Cons levellizedAllClassInstances(Surrogate type) {
    { SubsumptionInferenceLevel level = this;

      { Cons members = Stella.NIL;

        { Stella_Object m = null;
          Cons iter000 = Logic.assertedCollectionMembers(Logic.getDescription(type), Stella.FALSE).theConsList;

          while (!(iter000 == Stella.NIL)) {
            {
              m = iter000.value;
              iter000 = iter000.rest;
            }
            members = Stella_Object.cons(m, members);
          }
        }
        return (members);
      }
    }
  }

  public boolean levellizedTestTypeOnInstanceP(Stella_Object self, Surrogate type) {
    { SubsumptionInferenceLevel level = this;

      { boolean foundP000 = Stella.FALSE;

        { Proposition p = null;
          Iterator iter000 = Logic.allTrueDependentPropositions(self, type, Stella.TRUE);

          loop000 : while (iter000.nextP()) {
            p = ((Proposition)(iter000.value));
            if (p.kind == Logic.KWD_ISA) {
              foundP000 = Stella.TRUE;
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
    { SubsumptionInferenceLevel self = this;

      return (Logic.SGT_LOGIC_SUBSUMPTION_INFERENCE_LEVEL);
    }
  }

}

