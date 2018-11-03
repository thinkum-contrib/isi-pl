//  -*- Mode: Java -*-
//
// DecisionTree.java

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

public class DecisionTree extends StandardObject {
    public Symbol feature;
    public int featureIndex;
    public Proposition proposition;
    public boolean truthValue;
    public Symbol concept;
    public DecisionTree trueBranch;
    public DecisionTree falseBranch;

  public static DecisionTree newDecisionTree() {
    { DecisionTree self = null;

      self = new DecisionTree();
      self.falseBranch = null;
      self.trueBranch = null;
      self.concept = null;
      self.truthValue = false;
      self.proposition = null;
      self.featureIndex = Stella.NULL_INTEGER;
      self.feature = null;
      return (self);
    }
  }

  public static List getPropositionsFromDecisionTree(DecisionTree tree) {
    if (tree.feature == null) {
      return (List.newList());
    }
    { List theList = DecisionTree.getPropositionsFromDecisionTree(tree.trueBranch).concatenate(DecisionTree.getPropositionsFromDecisionTree(tree.falseBranch), Stella.NIL);

      theList.push(tree.proposition);
      return (theList);
    }
  }

  public static void sortExamplesByTree(DecisionTree tree, List examples, List sortedExamples) {
    if (tree.feature == null) {
      sortedExamples.push(examples);
      return;
    }
    { List trueExamples = List.newList();
      List falseExamples = List.newList();

      { TrainingExample example = null;
        Cons iter000 = examples.theConsList;

        while (!(iter000 == Stella.NIL)) {
          {
            example = ((TrainingExample)(iter000.value));
            iter000 = iter000.rest;
          }
          if (Stella_Object.eqlP((example.input.theArray)[(tree.featureIndex)], Stella.ONE_WRAPPER)) {
            trueExamples.push(example);
          }
          else {
            falseExamples.push(example);
          }
        }
      }
      DecisionTree.sortExamplesByTree(tree.trueBranch, trueExamples, sortedExamples);
      DecisionTree.sortExamplesByTree(tree.falseBranch, falseExamples, sortedExamples);
    }
  }

  public static void extractPathsFromTree(DecisionTree tree, Cons antecedentStack, List antecedent) {
    if (tree.feature == null) {
      antecedent.push(Stella_Object.cons((tree.truthValue ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER), antecedentStack));
      return;
    }
    { Cons prop = Proposition.propositionToCons(tree.proposition);

      DecisionTree.extractPathsFromTree(tree.trueBranch, Stella_Object.cons(prop, antecedentStack), antecedent);
      DecisionTree.extractPathsFromTree(tree.falseBranch, Stella_Object.cons(Stella.list$(Stella_Object.cons(Logic.SYM_LOGIC_FAIL, Stella_Object.cons(prop, Stella_Object.cons(Stella.NIL, Stella.NIL)))), antecedentStack), antecedent);
    }
  }

  public static List buildRulesFromTree(DecisionTree tree, List props) {
    { List rules = List.newList();
      Cons consProps = Stella.NIL;

      { Proposition prop = null;
        Cons iter000 = props.theConsList;
        Cons collect000 = null;

        while (!(iter000 == Stella.NIL)) {
          {
            prop = ((Proposition)(iter000.value));
            iter000 = iter000.rest;
          }
          if (collect000 == null) {
            {
              collect000 = Stella_Object.cons(Proposition.propositionToCons(prop), Stella.NIL);
              if (consProps == Stella.NIL) {
                consProps = collect000;
              }
              else {
                Cons.addConsToEndOfConsList(consProps, collect000);
              }
            }
          }
          else {
            {
              collect000.rest = Stella_Object.cons(Proposition.propositionToCons(prop), Stella.NIL);
              collect000 = collect000.rest;
            }
          }
        }
      }
      Logic.$INDUCED_DECISION_RULES$ = List.newList();
      DecisionTree.extractPathsFromTree(tree, Stella.NIL, rules);
      return (rules);
    }
  }

  public static void helpPrintDecisionTree(DecisionTree tree, int level, java.io.PrintStream stream) {
    if (tree.feature == null) {
      if (tree.truthValue) {
        stream.println("True");
      }
      else {
        stream.println("False");
      }
      return;
    }
    stream.println();
    { int i = Stella.NULL_INTEGER;
      int iter000 = 1;
      int upperBound000 = level;
      boolean unboundedP000 = upperBound000 == Stella.NULL_INTEGER;

      while (unboundedP000 ||
          (iter000 <= upperBound000)) {
        {
          i = iter000;
          iter000 = iter000 + 1;
        }
        i = i;
        stream.print("|   ");
      }
    }
    stream.print(tree.proposition + " = 1: ");
    DecisionTree.helpPrintDecisionTree(tree.trueBranch, level + 1, stream);
    { int i = Stella.NULL_INTEGER;
      int iter001 = 1;
      int upperBound001 = level;
      boolean unboundedP001 = upperBound001 == Stella.NULL_INTEGER;

      while (unboundedP001 ||
          (iter001 <= upperBound001)) {
        {
          i = iter001;
          iter001 = iter001 + 1;
        }
        i = i;
        stream.print("|   ");
      }
    }
    stream.print(tree.proposition + " = 0: ");
    DecisionTree.helpPrintDecisionTree(tree.falseBranch, level + 1, stream);
  }

  public static void printDecisionTree(DecisionTree tree, java.io.PrintStream stream) {
    DecisionTree.helpPrintDecisionTree(tree, 0, stream);
  }

  public static void addPropositionsToDecisionTree(DecisionTree tree, HashTable table) {
    if (tree.feature == null) {
      return;
    }
    tree.proposition = ((Proposition)(table.lookup(tree.feature)));
    DecisionTree.addPropositionsToDecisionTree(tree.trueBranch, table);
    DecisionTree.addPropositionsToDecisionTree(tree.falseBranch, table);
  }

  public static boolean traverseDecisionTree(DecisionTree tree, Vector features) {
    if (tree.feature == null) {
      return (tree.truthValue);
    }
    if (Stella_Object.eqlP(((IntegerWrapper)((features.theArray)[(tree.featureIndex)])), Stella.ONE_WRAPPER)) {
      return (DecisionTree.traverseDecisionTree(tree.trueBranch, features));
    }
    else {
      return (DecisionTree.traverseDecisionTree(tree.falseBranch, features));
    }
  }

  public static boolean askDecisionTree(DecisionTree tree, Cons query) {
    { Vector signature = Logic.createInputSignature(query);

      return (DecisionTree.traverseDecisionTree(tree, signature));
    }
  }

  public void printObject(java.io.PrintStream stream) {
    { DecisionTree self = this;

      DecisionTree.printDecisionTree(self, stream);
    }
  }

  public static Stella_Object accessDecisionTreeSlotValue(DecisionTree self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_FEATURE) {
      if (setvalueP) {
        self.feature = ((Symbol)(value));
      }
      else {
        value = self.feature;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_FEATURE_INDEX) {
      if (setvalueP) {
        self.featureIndex = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.featureIndex);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_PROPOSITION) {
      if (setvalueP) {
        self.proposition = ((Proposition)(value));
      }
      else {
        value = self.proposition;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_TRUTH_VALUE) {
      if (setvalueP) {
        self.truthValue = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.truthValue ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
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
    else if (slotname == Logic.SYM_LOGIC_TRUE_BRANCH) {
      if (setvalueP) {
        self.trueBranch = ((DecisionTree)(value));
      }
      else {
        value = self.trueBranch;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_FALSE_BRANCH) {
      if (setvalueP) {
        self.falseBranch = ((DecisionTree)(value));
      }
      else {
        value = self.falseBranch;
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
    { DecisionTree self = this;

      return (Logic.SGT_LOGIC_DECISION_TREE);
    }
  }

}

