//  -*- Mode: Java -*-
//
// PropositionNeuralNetwork.java

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

public class PropositionNeuralNetwork extends StandardObject {
    public Proposition proposition;
    public Vector input;
    public Vector hidden;
    public double output;
    public Vector inputError;
    public Vector hiddenError;
    public twoDArray ih;
    public twoDArray ihDelta;
    public Vector ho;
    public Vector hoDelta;
    public twoDArray ihSlope;
    public twoDArray ihPrevSlope;
    public Vector hoSlope;
    public Vector hoPrevSlope;

  public static PropositionNeuralNetwork newPropositionNeuralNetwork() {
    { PropositionNeuralNetwork self = null;

      self = new PropositionNeuralNetwork();
      self.hoPrevSlope = null;
      self.hoSlope = null;
      self.ihPrevSlope = null;
      self.ihSlope = null;
      self.hoDelta = null;
      self.ho = null;
      self.ihDelta = null;
      self.ih = null;
      self.hiddenError = null;
      self.inputError = null;
      self.output = Stella.NULL_FLOAT;
      self.hidden = null;
      self.input = null;
      self.proposition = null;
      return (self);
    }
  }

  public static void printNeuralNetwork(PropositionNeuralNetwork net, OutputStream stream) {
    stream.nativeStream.println("defnetwork ");
    Proposition.printProposition(net.proposition, stream, false);
    stream.nativeStream.println();
    stream.nativeStream.println(net.input.length() + " " + net.hidden.length());
    { int i = Stella.NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = net.input.length() - 1;

      while (iter000 <= upperBound000) {
        {
          i = iter000;
          iter000 = iter000 + 1;
        }
        { int j = Stella.NULL_INTEGER;
          int iter001 = 0;
          int upperBound001 = net.hidden.length() - 1;

          while (iter001 <= upperBound001) {
            {
              j = iter001;
              iter001 = iter001 + 1;
            }
            { double value = ((FloatWrapper)((net.ih.theArray)[((i * net.ih.nofColumns) + j)])).wrapperValue;

              stream.nativeStream.print(" " + value);
            }
          }
        }
      }
    }
    stream.nativeStream.println();
    { FloatWrapper num = null;
      Vector vector000 = net.ho;
      int index000 = 0;
      int length000 = vector000.length();

      while (index000 < length000) {
        {
          num = ((FloatWrapper)((vector000.theArray)[index000]));
          index000 = index000 + 1;
        }
        { double value = num.wrapperValue;

          stream.nativeStream.print(" " + value);
        }
      }
    }
    stream.nativeStream.println();
  }

  public static void saveNeuralNetwork(PropositionNeuralNetwork net, String file) {
    { OutputFileStream fptr = OutputFileStream.newOutputFileStream(file);

      PropositionNeuralNetwork.printNeuralNetwork(net, fptr);
      fptr.free();
    }
  }

  public static double activatePropositionalNeuralNetwork(PropositionNeuralNetwork net) {
    { int numIn = net.input.length();
      int numHidden = net.hidden.length();
      Vector arguments = net.proposition.arguments;
      int stop = numIn - 1;
      Vector input = net.input;
      Vector hidden = net.hidden;
      twoDArray ih = net.ih;
      Vector ho = net.ho;
      double score = 0.0;
      double sum = 0.0;

      Logic.$ACTIVATED_NETWORKS$.push(net);
      (net.input.theArray)[0] = (Stella.wrapFloat(1.0));
      { int i = Stella.NULL_INTEGER;
        int iter000 = 1;
        int upperBound000 = stop;
        boolean unboundedP000 = upperBound000 == Stella.NULL_INTEGER;

        while (unboundedP000 ||
            (iter000 <= upperBound000)) {
          {
            i = iter000;
            iter000 = iter000 + 1;
          }
          if (((FloatWrapper)(KeyValueList.dynamicSlotValue(((Proposition)((arguments.theArray)[(i - 1)])).dynamicSlots, Logic.SYM_LOGIC_MATCH_SCORE, Stella.NULL_FLOAT_WRAPPER))).wrapperValue != Stella.NULL_FLOAT) {
            (input.theArray)[i] = (Stella.wrapFloat(((FloatWrapper)(KeyValueList.dynamicSlotValue(((Proposition)((arguments.theArray)[(i - 1)])).dynamicSlots, Logic.SYM_LOGIC_MATCH_SCORE, Stella.NULL_FLOAT_WRAPPER))).wrapperValue));
          }
          else {
            (input.theArray)[i] = (Stella.wrapFloat(0.0));
          }
        }
      }
      { int i = Stella.NULL_INTEGER;
        int iter001 = 0;
        int upperBound001 = numHidden - 1;

        while (iter001 <= upperBound001) {
          {
            i = iter001;
            iter001 = iter001 + 1;
          }
          { int j = Stella.NULL_INTEGER;
            int iter002 = 0;
            int upperBound002 = stop;
            boolean unboundedP001 = upperBound002 == Stella.NULL_INTEGER;

            while (unboundedP001 ||
                (iter002 <= upperBound002)) {
              {
                j = iter002;
                iter002 = iter002 + 1;
              }
              sum = sum + (((FloatWrapper)((input.theArray)[j])).wrapperValue * ((FloatWrapper)((ih.theArray)[((j * ih.nofColumns) + i)])).wrapperValue);
            }
          }
          (hidden.theArray)[i] = (Stella.wrapFloat(1.0 / (1.0 + Math.exp((0 - sum)))));
          score = score + (((FloatWrapper)((hidden.theArray)[i])).wrapperValue * ((FloatWrapper)((ho.theArray)[i])).wrapperValue);
        }
      }
      if ((1.0 + Math.exp((0 - score))) == 0.0) {
        System.out.println("Sum is " + score);
      }
      net.output = 1.0 / (1.0 + Math.exp((0 - score)));
      KeyValueList.setDynamicSlotValue(net.proposition.dynamicSlots, Logic.SYM_LOGIC_MATCH_SCORE, Stella.wrapFloat(net.output), Stella.NULL_FLOAT_WRAPPER);
      return (net.output);
    }
  }

  public static void randomizeNeuralNetwork(PropositionNeuralNetwork net) {
    { int numIn = net.input.length();
      int numHidden = net.hidden.length();

      { int h = Stella.NULL_INTEGER;
        int iter000 = 0;
        int upperBound000 = numHidden - 1;

        while (iter000 <= upperBound000) {
          {
            h = iter000;
            iter000 = iter000 + 1;
          }
          (net.hoDelta.theArray)[h] = (Stella.wrapFloat(0.0));
          { int i = Stella.NULL_INTEGER;
            int iter001 = 0;
            int upperBound001 = numIn - 1;

            while (iter001 <= upperBound001) {
              {
                i = iter001;
                iter001 = iter001 + 1;
              }
              (net.ihDelta.theArray)[((i * net.ihDelta.nofColumns) + h)] = (Stella.wrapFloat(0.0));
            }
          }
        }
      }
      { int i = Stella.NULL_INTEGER;
        int iter002 = 0;
        int upperBound002 = numHidden - 1;

        while (iter002 <= upperBound002) {
          {
            i = iter002;
            iter002 = iter002 + 1;
          }
          { int j = Stella.NULL_INTEGER;
            int iter003 = 0;
            int upperBound003 = numIn - 1;

            while (iter003 <= upperBound003) {
              {
                j = iter003;
                iter003 = iter003 + 1;
              }
              (net.ih.theArray)[((j * net.ih.nofColumns) + i)] = (Stella.wrapFloat(Logic.randomWeight(Logic.$WEIGHT_RANGE$)));
            }
          }
          (net.ho.theArray)[i] = (Stella.wrapFloat(Logic.randomWeight(Logic.$WEIGHT_RANGE$)));
        }
      }
    }
  }

  public static void clearSlopes(PropositionNeuralNetwork net) {
    { int h = Stella.NULL_INTEGER;
      int iter000 = 0;
      int upperBound000 = net.hidden.length() - 1;

      while (iter000 <= upperBound000) {
        {
          h = iter000;
          iter000 = iter000 + 1;
        }
        { int i = Stella.NULL_INTEGER;
          int iter001 = 0;
          int upperBound001 = net.input.length() - 1;

          while (iter001 <= upperBound001) {
            {
              i = iter001;
              iter001 = iter001 + 1;
            }
            (net.ihPrevSlope.theArray)[((i * net.ihPrevSlope.nofColumns) + h)] = (((FloatWrapper)((net.ihSlope.theArray)[((i * net.ihSlope.nofColumns) + h)])));
            (net.ihSlope.theArray)[((i * net.ihSlope.nofColumns) + h)] = (Stella.wrapFloat(((FloatWrapper)((net.ih.theArray)[((i * net.ih.nofColumns) + h)])).wrapperValue * Logic.$WEIGHT_DECAY$));
          }
        }
        (net.hoPrevSlope.theArray)[h] = (((FloatWrapper)((net.hoSlope.theArray)[h])));
        (net.hoSlope.theArray)[h] = (Stella.wrapFloat(((FloatWrapper)((net.ho.theArray)[h])).wrapperValue * Logic.$WEIGHT_DECAY$));
      }
    }
  }

  public static Stella_Object accessPropositionNeuralNetworkSlotValue(PropositionNeuralNetwork self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_PROPOSITION) {
      if (setvalueP) {
        self.proposition = ((Proposition)(value));
      }
      else {
        value = self.proposition;
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
    else if (slotname == Logic.SYM_LOGIC_HIDDEN) {
      if (setvalueP) {
        self.hidden = ((Vector)(value));
      }
      else {
        value = self.hidden;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_OUTPUT) {
      if (setvalueP) {
        self.output = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.output);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_INPUT_ERROR) {
      if (setvalueP) {
        self.inputError = ((Vector)(value));
      }
      else {
        value = self.inputError;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_HIDDEN_ERROR) {
      if (setvalueP) {
        self.hiddenError = ((Vector)(value));
      }
      else {
        value = self.hiddenError;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_IH) {
      if (setvalueP) {
        self.ih = ((twoDArray)(value));
      }
      else {
        value = self.ih;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_IH_DELTA) {
      if (setvalueP) {
        self.ihDelta = ((twoDArray)(value));
      }
      else {
        value = self.ihDelta;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_HO) {
      if (setvalueP) {
        self.ho = ((Vector)(value));
      }
      else {
        value = self.ho;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_HO_DELTA) {
      if (setvalueP) {
        self.hoDelta = ((Vector)(value));
      }
      else {
        value = self.hoDelta;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_IH_SLOPE) {
      if (setvalueP) {
        self.ihSlope = ((twoDArray)(value));
      }
      else {
        value = self.ihSlope;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_IH_PREV_SLOPE) {
      if (setvalueP) {
        self.ihPrevSlope = ((twoDArray)(value));
      }
      else {
        value = self.ihPrevSlope;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_HO_SLOPE) {
      if (setvalueP) {
        self.hoSlope = ((Vector)(value));
      }
      else {
        value = self.hoSlope;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_HO_PREV_SLOPE) {
      if (setvalueP) {
        self.hoPrevSlope = ((Vector)(value));
      }
      else {
        value = self.hoPrevSlope;
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
    { PropositionNeuralNetwork self = this;

      return (Logic.SGT_LOGIC_PROPOSITION_NEURAL_NETWORK);
    }
  }

}

