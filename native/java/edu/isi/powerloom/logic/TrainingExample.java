//  -*- Mode: Java -*-
//
// TrainingExample.java

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

/** A single example of a proposition paired with the score
 *   that should be returned and the module it should be evaluated in.
 * @author Stella Java Translator
 */
public class TrainingExample extends StandardObject {
    public Cons query;
    public Symbol concept;
    public Symbol name;
    public double score;
    public Module module;
    public List inputFeatures;
    public Vector input;
    public Cons facts;
    public Vector nnHidden;
    public Stella_Object output;
    public double temp;
    public Stella_Object cachedSolution;
    public int timestamp;

  public static TrainingExample newTrainingExample() {
    { TrainingExample self = null;

      self = new TrainingExample();
      self.timestamp = Stella.NULL_INTEGER;
      self.cachedSolution = null;
      self.temp = Stella.NULL_FLOAT;
      self.output = null;
      self.nnHidden = null;
      self.facts = null;
      self.input = null;
      self.inputFeatures = null;
      self.module = null;
      self.score = Stella.NULL_FLOAT;
      self.name = null;
      self.concept = null;
      self.query = null;
      return (self);
    }
  }

  public static List getNearestNeighbors(TrainingExample probe, List cases, int k) {
    { List result = List.newList();
      Module currentModule = ((Module)(Stella.$MODULE$.get()));
      Vector neighbors = Vector.newVector(k);
      int farthest = 0;
      double distance = 0.0;
      Vector distances = Vector.newVector(k);

      { int i = Stella.NULL_INTEGER;
        int iter000 = 0;
        int upperBound000 = k - 1;

        while (iter000 <= upperBound000) {
          {
            i = iter000;
            iter000 = iter000 + 1;
          }
          (distances.theArray)[i] = (Stella.wrapFloat(999999.0));
        }
      }
      if (probe.input == null) {
        probe.input = Logic.createInputSignature(probe.query);
      }
      { TrainingExample renamed_Case = null;
        Cons iter001 = cases.theConsList;

        while (!(iter001 == Stella.NIL)) {
          {
            renamed_Case = ((TrainingExample)(iter001.value));
            iter001 = iter001.rest;
          }
          if (renamed_Case.input == null) {
            if (!(renamed_Case.module == null)) {
              renamed_Case.module.changeModule();
            }
            renamed_Case.input = Logic.createInputSignature(renamed_Case.query);
            currentModule.changeModule();
          }
          if (probe.input.length() == 1) {
            probe.input = Logic.createInputSignature(probe.query);
          }
          distance = Logic.hammingDistance(probe.input, renamed_Case.input) + 0.0;
          if (Logic.$PRINT_CASE_DISTANCES$) {
            System.out.println("  Distance from " + renamed_Case.query.last() + ": " + distance);
          }
          renamed_Case.temp = distance;
          if (distance < ((FloatWrapper)((distances.theArray)[farthest])).wrapperValue) {
            (distances.theArray)[farthest] = (Stella.wrapFloat(distance));
            (neighbors.theArray)[farthest] = renamed_Case;
            farthest = 0;
            { int j = Stella.NULL_INTEGER;
              int iter002 = 1;
              int upperBound001 = k - 1;

              while (iter002 <= upperBound001) {
                {
                  j = iter002;
                  iter002 = iter002 + 1;
                }
                if (((FloatWrapper)((distances.theArray)[j])).wrapperValue > ((FloatWrapper)((distances.theArray)[farthest])).wrapperValue) {
                  farthest = j;
                }
              }
            }
          }
        }
      }
      { int i = Stella.NULL_INTEGER;
        int iter003 = 0;
        int upperBound002 = k - 1;
        Cons collect000 = null;

        while (iter003 <= upperBound002) {
          {
            i = iter003;
            iter003 = iter003 + 1;
          }
          if (collect000 == null) {
            {
              collect000 = Stella_Object.cons(((TrainingExample)((neighbors.theArray)[i])), Stella.NIL);
              if (result.theConsList == Stella.NIL) {
                result.theConsList = collect000;
              }
              else {
                Cons.addConsToEndOfConsList(result.theConsList, collect000);
              }
            }
          }
          else {
            {
              collect000.rest = Stella_Object.cons(((TrainingExample)((neighbors.theArray)[i])), Stella.NIL);
              collect000 = collect000.rest;
            }
          }
        }
      }
      return (result);
    }
  }

  public static List getNnNearestNeighbors(TrainingExample probe, List cases, int k) {
    { List result = List.newList();
      Module currentModule = ((Module)(Stella.$MODULE$.get()));
      Vector neighbors = Vector.newVector(k);
      int farthest = 0;
      double distance = 0.0;
      Vector distances = Vector.newVector(k);

      Logic.shuffleList(cases);
      { int i = Stella.NULL_INTEGER;
        int iter000 = 0;
        int upperBound000 = k - 1;

        while (iter000 <= upperBound000) {
          {
            i = iter000;
            iter000 = iter000 + 1;
          }
          (distances.theArray)[i] = (Stella.wrapFloat(999999.0));
        }
      }
      probe.nnHidden = Logic.createHiddenSignature(probe.query);
      { TrainingExample renamed_Case = null;
        Cons iter001 = cases.theConsList;

        while (!(iter001 == Stella.NIL)) {
          {
            renamed_Case = ((TrainingExample)(iter001.value));
            iter001 = iter001.rest;
          }
          if (renamed_Case.nnHidden == null) {
            if (renamed_Case.module != null) {
              renamed_Case.module.changeModule();
            }
            if (renamed_Case.nnHidden == null) {
              renamed_Case.nnHidden = Logic.createHiddenSignature(renamed_Case.query);
            }
            currentModule.changeModule();
          }
          distance = Logic.euclideanDistance(probe.nnHidden, renamed_Case.nnHidden) + 0.0;
          if (Logic.$PRINT_CASE_DISTANCES$) {
            System.out.println("  Distance from " + renamed_Case.query.last() + ": " + distance);
          }
          renamed_Case.temp = distance;
          if (distance < ((FloatWrapper)((distances.theArray)[farthest])).wrapperValue) {
            (distances.theArray)[farthest] = (Stella.wrapFloat(distance));
            (neighbors.theArray)[farthest] = renamed_Case;
            farthest = 0;
            { int j = Stella.NULL_INTEGER;
              int iter002 = 1;
              int upperBound001 = k - 1;

              while (iter002 <= upperBound001) {
                {
                  j = iter002;
                  iter002 = iter002 + 1;
                }
                if (((FloatWrapper)((distances.theArray)[j])).wrapperValue > ((FloatWrapper)((distances.theArray)[farthest])).wrapperValue) {
                  farthest = j;
                }
              }
            }
          }
        }
      }
      { int i = Stella.NULL_INTEGER;
        int iter003 = 0;
        int upperBound002 = k - 1;
        Cons collect000 = null;

        while (iter003 <= upperBound002) {
          {
            i = iter003;
            iter003 = iter003 + 1;
          }
          if (((TrainingExample)((neighbors.theArray)[i])) != null) {
            if (collect000 == null) {
              {
                collect000 = Stella_Object.cons(((TrainingExample)((neighbors.theArray)[i])), Stella.NIL);
                if (result.theConsList == Stella.NIL) {
                  result.theConsList = collect000;
                }
                else {
                  Cons.addConsToEndOfConsList(result.theConsList, collect000);
                }
              }
            }
            else {
              {
                collect000.rest = Stella_Object.cons(((TrainingExample)((neighbors.theArray)[i])), Stella.NIL);
                collect000 = collect000.rest;
              }
            }
          }
        }
      }
      return (result);
    }
  }

  public static void printTrainingExample(TrainingExample example) {
    System.out.println(example.query + " in " + example.module);
  }

  public static Stella_Object accessTrainingExampleSlotValue(TrainingExample self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_QUERY) {
      if (setvalueP) {
        self.query = ((Cons)(value));
      }
      else {
        value = self.query;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CONCEPT) {
      if (setvalueP) {
        self.concept = ((Symbol)(value));
      }
      else {
        value = self.concept;
      }
    }
    else if (slotname == Logic.SYM_STELLA_NAME) {
      if (setvalueP) {
        self.name = ((Symbol)(value));
      }
      else {
        value = self.name;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_SCORE) {
      if (setvalueP) {
        self.score = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.score);
      }
    }
    else if (slotname == Logic.SYM_STELLA_MODULE) {
      if (setvalueP) {
        self.module = ((Module)(value));
      }
      else {
        value = self.module;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_INPUT_FEATURES) {
      if (setvalueP) {
        self.inputFeatures = ((List)(value));
      }
      else {
        value = self.inputFeatures;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_INPUT) {
      if (setvalueP) {
        self.input = ((Vector)(value));
      }
      else {
        value = self.input;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_FACTS) {
      if (setvalueP) {
        self.facts = ((Cons)(value));
      }
      else {
        value = self.facts;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_NN_HIDDEN) {
      if (setvalueP) {
        self.nnHidden = ((Vector)(value));
      }
      else {
        value = self.nnHidden;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_OUTPUT) {
      if (setvalueP) {
        self.output = value;
      }
      else {
        value = self.output;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_TEMP) {
      if (setvalueP) {
        self.temp = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.temp);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CACHED_SOLUTION) {
      if (setvalueP) {
        self.cachedSolution = value;
      }
      else {
        value = self.cachedSolution;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_TIMESTAMP) {
      if (setvalueP) {
        self.timestamp = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.timestamp);
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
    { TrainingExample self = this;

      return (Logic.SGT_LOGIC_TRAINING_EXAMPLE);
    }
  }

}

