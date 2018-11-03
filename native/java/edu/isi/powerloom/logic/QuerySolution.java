//  -*- Mode: Java -*-
//
// QuerySolution.java

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

public class QuerySolution extends StandardObject {
    public Vector bindings;
    public TruthValue truthValue;
    public double matchScore;
    public Justification justification;
    /** All recorded justifications for
     * this solution in case we have multiple ones from a partial match operation.
     */
    public List allJustifications;
    public QuerySolution next;

  public static QuerySolution newQuerySolution() {
    { QuerySolution self = null;

      self = new QuerySolution();
      self.next = null;
      self.allJustifications = null;
      self.justification = null;
      self.matchScore = Stella.NULL_FLOAT;
      self.truthValue = null;
      self.bindings = null;
      return (self);
    }
  }

  public static boolean solutionScoreGreaterThanP(QuerySolution s1, QuerySolution s2) {
    return (s1.matchScore > s2.matchScore);
  }

  public boolean deletedPSetter(boolean value) {
    { QuerySolution self = this;

      if (value) {
        self.bindings = null;
      }
      else {
        self.bindings = Stella.vector(Stella.NIL);
      }
      return (value);
    }
  }

  public boolean deletedP() {
    { QuerySolution self = this;

      return (self.bindings == null);
    }
  }

  public static Stella_Object accessQuerySolutionSlotValue(QuerySolution self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_BINDINGS) {
      if (setvalueP) {
        self.bindings = ((Vector)(value));
      }
      else {
        value = self.bindings;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_TRUTH_VALUE) {
      if (setvalueP) {
        self.truthValue = ((TruthValue)(value));
      }
      else {
        value = self.truthValue;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_MATCH_SCORE) {
      if (setvalueP) {
        self.matchScore = ((FloatWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFloat(self.matchScore);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_JUSTIFICATION) {
      if (setvalueP) {
        self.justification = ((Justification)(value));
      }
      else {
        value = self.justification;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_BEST_JUSTIFICATION) {
      if (setvalueP) {
        self.justification = ((Justification)(value));
      }
      else {
        value = self.justification;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_ALL_JUSTIFICATIONS) {
      if (setvalueP) {
        self.allJustifications = ((List)(value));
      }
      else {
        value = self.allJustifications;
      }
    }
    else if (slotname == Logic.SYM_STELLA_NEXT) {
      if (setvalueP) {
        self.next = ((QuerySolution)(value));
      }
      else {
        value = self.next;
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
    { QuerySolution self = this;

      return (Logic.SGT_LOGIC_QUERY_SOLUTION);
    }
  }

}

