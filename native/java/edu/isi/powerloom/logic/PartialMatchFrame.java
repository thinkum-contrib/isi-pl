//  -*- Mode: Java -*-
//
// PartialMatchFrame.java

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

/** Abstract class acting as placeholder for system and
 * user-defined partial match implementations.
 * @author Stella Java Translator
 */
public abstract class PartialMatchFrame extends StandardObject {
    public Keyword kind;
    public ControlFrame controlFrame;
    public PartialMatchFrame parent;
    public PartialMatchFrame child;
    public double positiveScore;
    public double negativeScore;
    public double dynamicCutoff;
    public Cons argumentScores;
    public Cons argumentWeights;
    public Cons unboundVars;
    public boolean successP;

  public double computePartialTruth(QueryIterator query) {
    { PartialMatchFrame self = this;

      query = query;
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("Don't know how to compute partial truth for `" + self + "'");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public QueryIterator retrievePartialSolutions(QueryIterator query) {
    { PartialMatchFrame self = this;

      query = query;
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("Don't know how to retrieve partial solutions for `" + self + "'");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public void initializePartialMatchStrategy(QueryIterator query) {
    { PartialMatchFrame self = this;

      { FloatWrapper minimumscore = ((FloatWrapper)(query.options.lookup(Logic.KWD_MINIMUM_SCORE)));
        double epsilon = 0.001;

        query.partialMatchStrategy = self;
        self.dynamicCutoff = ((minimumscore != null) ? minimumscore.wrapperValue : epsilon);
        KeyValueList.setDynamicSlotValue(query.dynamicSlots, Logic.SYM_LOGIC_LATEST_POSITIVE_SCORE, Stella.wrapFloat(0.0), Stella.NULL_FLOAT_WRAPPER);
      }
    }
  }

  public boolean earlyPartialMatchOrSuccessP() {
    { PartialMatchFrame self = this;

      return (false);
    }
  }

  public boolean earlyPartialMatchAndFailureP() {
    { PartialMatchFrame self = this;

      return (false);
    }
  }

  public void popPartialMatchScore() {
    { PartialMatchFrame self = this;

    }
  }

  public void recordPartialMatchScore(double score, double weight) {
    { PartialMatchFrame self = this;

      {
        score = score;
        weight = weight;
      }
    }
  }

  public void setBasePartialMatchTruth(Proposition prop, Keyword truth) {
    { PartialMatchFrame self = this;

      if (truth == Logic.KWD_TRUE) {
        KeyValueList.setDynamicSlotValue(((QueryIterator)(Logic.$QUERYITERATOR$.get())).dynamicSlots, Logic.SYM_LOGIC_LATEST_POSITIVE_SCORE, Stella.wrapFloat(1.0), Stella.NULL_FLOAT_WRAPPER);
      }
      else if (truth == Logic.KWD_FAIL) {
        KeyValueList.setDynamicSlotValue(((QueryIterator)(Logic.$QUERYITERATOR$.get())).dynamicSlots, Logic.SYM_LOGIC_LATEST_POSITIVE_SCORE, Stella.wrapFloat(0.0), Stella.NULL_FLOAT_WRAPPER);
      }
      else {
        { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

          stream000.nativeStream.print("`" + truth + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public Keyword continuePartialAntecedentsProof(Keyword lastmove) {
    { PartialMatchFrame self = this;

      return (ControlFrame.continueAntecedentsProof(self.controlFrame, lastmove));
    }
  }

  public Keyword continuePartialStrategiesProofs(Keyword lastmove) {
    { PartialMatchFrame self = this;

      return (ControlFrame.oldInterpretGoalScores(self.controlFrame, lastmove));
    }
  }

  public double computeGoalScore() {
    { PartialMatchFrame self = this;

      return (Stella.NULL_FLOAT);
    }
  }

  public Keyword continuePartialFailProof(Keyword lastmove) {
    { PartialMatchFrame self = this;

      lastmove = ControlFrame.oldInterpretFailScore(self.controlFrame, lastmove);
      return (ControlFrame.continueFailProof(self.controlFrame, lastmove));
    }
  }

  public Keyword continuePartialNotProof(Keyword lastmove) {
    { PartialMatchFrame self = this;

      return (ControlFrame.continueNotProof(self.controlFrame, lastmove));
    }
  }

  public double computeNotScore() {
    { PartialMatchFrame self = this;

      return (Stella.NULL_FLOAT);
    }
  }

  public Keyword continuePartialOrProof(Keyword lastmove) {
    { PartialMatchFrame self = this;

      lastmove = ControlFrame.oldInterpretOrScores(self.controlFrame, lastmove);
      return (ControlFrame.continueOrProof(self.controlFrame, lastmove));
    }
  }

  public double computeOrScore() {
    { PartialMatchFrame self = this;

      return (Stella.NULL_FLOAT);
    }
  }

  public Keyword continuePartialAndProof(ControlFrame frame, Keyword lastmove) {
    { PartialMatchFrame self = this;

      lastmove = ControlFrame.oldInterpretAndScores(frame, lastmove);
      return (ControlFrame.continueAndProof(frame, lastmove));
    }
  }

  public double computeAndScore() {
    { PartialMatchFrame self = this;

      return (Stella.NULL_FLOAT);
    }
  }

  public boolean allowUnboundVariablesP() {
    { PartialMatchFrame self = this;

      return (false);
    }
  }

  public void setJustificationPartialTruth(Justification justification) {
    { PartialMatchFrame self = this;

      justification.positiveScore = self.positiveScore;
      justification.negativeScore = self.negativeScore;
    }
  }

  public void setCachePartialTruth(AtomicGoalCache cache) {
    { PartialMatchFrame self = this;

      cache.positiveScore = self.positiveScore;
      cache.negativeScore = self.negativeScore;
    }
  }

  public void traceFramePartialTruth(Keyword lastmove, OutputStream stream) {
    { PartialMatchFrame self = this;

      { double weight = self.propositionWeight(self.controlFrame.proposition);

        if (lastmove == Logic.KWD_DOWN) {
          { double cutoff = self.computeDynamicCutoff();

            if (cutoff != Stella.NULL_FLOAT) {
              stream.nativeStream.print("cutoff=" + cutoff);
            }
          }
        }
        else if ((lastmove == Logic.KWD_UP_TRUE) ||
            (lastmove == Logic.KWD_UP_FAIL)) {
          { double score = self.positiveScore;

            stream.nativeStream.print("score=" + score);
            if ((weight != Stella.NULL_FLOAT) &&
                (!(weight == 1.0))) {
              stream.nativeStream.print(" weight=" + weight);
            }
          }
        }
        else {
        }
      }
    }
  }

  public void propagateFramePartialTruth(ControlFrame target) {
    { PartialMatchFrame source = this;

      { PartialMatchFrame targetpmf = target.partialMatchFrame;
        boolean flippolarityP = !(source.controlFrame.reversePolarityP == target.reversePolarityP);

        if (targetpmf == null) {
          if (flippolarityP) {
            targetpmf = ((PartialMatchFrame)(Surrogate.createObject(source.primaryType(), Stella_Object.cons(Logic.KWD_CONTROL_FRAME, Stella_Object.cons(target, Stella_Object.cons(Logic.KWD_KIND, Stella_Object.cons(target.state, Stella.NIL)))))));
            targetpmf.parent = source.parent;
            targetpmf.child = source;
          }
          else {
            targetpmf = source;
          }
          target.partialMatchFrame = targetpmf;
        }
        if (flippolarityP) {
          targetpmf.positiveScore = 0 - source.positiveScore;
          targetpmf.negativeScore = source.positiveScore;
        }
        else {
          targetpmf.positiveScore = source.positiveScore;
          targetpmf.negativeScore = source.negativeScore;
        }
        KeyValueList.setDynamicSlotValue(((QueryIterator)(Logic.$QUERYITERATOR$.get())).dynamicSlots, Logic.SYM_LOGIC_LATEST_POSITIVE_SCORE, Stella.wrapFloat(targetpmf.positiveScore), Stella.NULL_FLOAT_WRAPPER);
      }
    }
  }

  public void setFramePartialTruth(TruthValue truthvalue, double posscore, double negscore, boolean ignorepolarityP) {
    { PartialMatchFrame self = this;

      { boolean flippolarityP = self.controlFrame.reversePolarityP &&
            (!ignorepolarityP);

        if ((posscore == Stella.NULL_FLOAT) &&
            (truthvalue != null)) {
          posscore = truthvalue.positiveScore;
        }
        if ((negscore == Stella.NULL_FLOAT) &&
            (truthvalue != null)) {
          negscore = TruthValue.invertTruthValue(truthvalue).positiveScore;
        }
        if (flippolarityP) {
          { double aux = posscore;

            posscore = 0 - posscore;
            negscore = aux;
          }
        }
        self.positiveScore = posscore;
        self.negativeScore = negscore;
        KeyValueList.setDynamicSlotValue(((QueryIterator)(Logic.$QUERYITERATOR$.get())).dynamicSlots, Logic.SYM_LOGIC_LATEST_POSITIVE_SCORE, Stella.wrapFloat(posscore), Stella.NULL_FLOAT_WRAPPER);
      }
    }
  }

  public boolean definedFramePartialTruthP() {
    { PartialMatchFrame self = this;

      return ((self.positiveScore != Stella.NULL_FLOAT) ||
          (self.negativeScore != Stella.NULL_FLOAT));
    }
  }

  public void clearFramePartialTruth() {
    { PartialMatchFrame self = this;

      self.positiveScore = Stella.NULL_FLOAT;
      self.negativeScore = Stella.NULL_FLOAT;
    }
  }

  public double propositionWeight(Proposition proposition) {
    { PartialMatchFrame self = this;

      if (proposition != null) {
        { double weight = ((FloatWrapper)(KeyValueList.dynamicSlotValue(proposition.dynamicSlots, Logic.SYM_LOGIC_WEIGHT, Stella.NULL_FLOAT_WRAPPER))).wrapperValue;

          if (weight == Stella.NULL_FLOAT) {
            return (1.0);
          }
          else {
            return (weight);
          }
        }
      }
      else {
        return (1.0);
      }
    }
  }

  public boolean cutoffPartialMatchP(boolean traceP) {
    { PartialMatchFrame self = this;

      { double score = self.positiveScore;
        double cutoff = self.dynamicCutoff;
        boolean cutoffP = false;

        if ((score == Stella.NULL_FLOAT) ||
            ((cutoff == Stella.NULL_FLOAT) ||
             (cutoff == 0.0))) {
          cutoffP = false;
        }
        else if (cutoff < 0.0) {
          cutoffP = score > cutoff;
        }
        else {
          cutoffP = score < cutoff;
        }
        if (cutoffP &&
            traceP) {
          System.out.println("*** Cutting off search, cutoff=" + cutoff);
        }
        return (cutoffP);
      }
    }
  }

  public void setDynamicCutoff() {
    { PartialMatchFrame self = this;

      { double cutoff = self.computeDynamicCutoff();

        if (cutoff != Stella.NULL_FLOAT) {
          if ((cutoff < -100) ||
              (cutoff > 100)) {
            Stella.STANDARD_WARNING.nativeStream.println("Warning: *** fishy dynamic cutoff=`" + cutoff + "' computed, resetting to 0.0");
            cutoff = 0.0;
          }
          self.dynamicCutoff = cutoff;
        }
      }
    }
  }

  public double computeDynamicCutoff() {
    { PartialMatchFrame self = this;

      return (Stella.NULL_FLOAT);
    }
  }

  public PartialMatchFrame createPartialMatchFrame(ControlFrame frame, Keyword kind) {
    { PartialMatchFrame self = this;

      {
        frame = frame;
        kind = kind;
      }
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        {
          stream000.nativeStream.println("Missing concrete method named 'create-partial-match-frame' on the");
          stream000.nativeStream.print("   class `" + self.primaryType() + "'");
        }
;
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public static void linkToParentPartialMatchFrame(PartialMatchFrame self) {
    { ControlFrame controlframe = self.controlFrame.up;

      while ((controlframe != null) &&
          (controlframe.partialMatchFrame == null)) {
        controlframe = controlframe.up;
      }
      if (controlframe != null) {
        self.parent = controlframe.partialMatchFrame;
        controlframe.partialMatchFrame.child = self;
      }
    }
  }

  public static Stella_Object accessPartialMatchFrameSlotValue(PartialMatchFrame self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_KIND) {
      if (setvalueP) {
        self.kind = ((Keyword)(value));
      }
      else {
        value = self.kind;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CONTROL_FRAME) {
      if (setvalueP) {
        self.controlFrame = ((ControlFrame)(value));
      }
      else {
        value = self.controlFrame;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_PARENT) {
      if (setvalueP) {
        self.parent = ((PartialMatchFrame)(value));
      }
      else {
        value = self.parent;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CHILD) {
      if (setvalueP) {
        self.child = ((PartialMatchFrame)(value));
      }
      else {
        value = self.child;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_POSITIVE_SCORE) {
      if (setvalueP) {
        self.positiveScore = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.positiveScore);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_NEGATIVE_SCORE) {
      if (setvalueP) {
        self.negativeScore = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.negativeScore);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_DYNAMIC_CUTOFF) {
      if (setvalueP) {
        self.dynamicCutoff = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.dynamicCutoff);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_ARGUMENT_SCORES) {
      if (setvalueP) {
        self.argumentScores = ((Cons)(value));
      }
      else {
        value = self.argumentScores;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_ARGUMENT_WEIGHTS) {
      if (setvalueP) {
        self.argumentWeights = ((Cons)(value));
      }
      else {
        value = self.argumentWeights;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_UNBOUND_VARS) {
      if (setvalueP) {
        self.unboundVars = ((Cons)(value));
      }
      else {
        value = self.unboundVars;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_SUCCESSp) {
      if (setvalueP) {
        self.successP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.successP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
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

}

