//  -*- Mode: Java -*-
//
// WhynotDeepPartialMatch.java

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

/** Variant of WhyNot partial match geared towards deep proofs.
 * @author Stella Java Translator
 */
public class WhynotDeepPartialMatch extends WhynotPartialMatch {
  public static WhynotDeepPartialMatch newWhynotDeepPartialMatch(Keyword kind, ControlFrame controlFrame) {
    { WhynotDeepPartialMatch self = null;

      self = new WhynotDeepPartialMatch();
      self.kind = kind;
      self.controlFrame = controlFrame;
      self.successP = false;
      self.unboundVars = Stella.NIL;
      self.argumentWeights = Stella.NIL;
      self.argumentScores = Stella.NIL;
      self.dynamicCutoff = Stella.NULL_FLOAT;
      self.negativeScore = Stella.NULL_FLOAT;
      self.positiveScore = Stella.NULL_FLOAT;
      self.maximumScore = 0.0;
      self.totalWeight = Stella.NULL_FLOAT;
      self.accumulatedWeight = 0.0;
      self.accumulatedScore = 0.0;
      self.child = null;
      self.parent = null;
      self.unknownGoalCutoff = Stella.NULL_INTEGER;
      IncrementalPartialMatch.initializeIncrementalPartialMatch(self);
      return (self);
    }
  }

  public double maxUnconstrainedFanout() {
    { WhynotDeepPartialMatch self = this;

      return (1000000.0);
    }
  }

  public double chainingDepthDegradation() {
    { WhynotDeepPartialMatch self = this;

      return (1.0);
    }
  }

  public PartialMatchFrame createPartialMatchFrame(ControlFrame frame, Keyword kind) {
    { WhynotDeepPartialMatch self = this;

      return (WhynotDeepPartialMatch.newWhynotDeepPartialMatch(kind, frame));
    }
  }

  public Surrogate primaryType() {
    { WhynotDeepPartialMatch self = this;

      return (Logic.SGT_LOGIC_WHYNOT_DEEP_PARTIAL_MATCH);
    }
  }

}

