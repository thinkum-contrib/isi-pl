//  -*- Mode: Java -*-
//
// PatternRecord.java

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

/** A pattern record records bookkeeping data used during
 * the processing of a description.
 * @author Stella Java Translator
 */
public class PatternRecord extends StandardObject {
    public ControlFrame controlFrame;
    public Vector variableBindings;
    public IntegerVector unbindingStack;
    public int topUnbindingStackOffset;
    public Description description;
    public Vector externalArguments;
    public BooleanVector booleanVector;
    public Description optimalPattern;
    public List collectionList;

  public static PatternRecord newPatternRecord() {
    { PatternRecord self = null;

      self = new PatternRecord();
      self.collectionList = null;
      self.optimalPattern = null;
      self.booleanVector = null;
      self.externalArguments = null;
      self.description = null;
      self.topUnbindingStackOffset = Stella.NULL_INTEGER;
      self.unbindingStack = null;
      self.variableBindings = null;
      self.controlFrame = null;
      return (self);
    }
  }

  public static boolean terminatePatternRecordP(PatternRecord self) {
    if (self.externalArguments != null) {
      self.externalArguments.free();
    }
    self.optimalPattern = null;
    return (Stella.TRUE);
  }

  public static void unbindVariablesBeginningAt(PatternRecord patternrecord, int ubstackoffset) {
    { Vector variablebindingsvector = patternrecord.variableBindings;
      IntegerVector unbindingstack = patternrecord.unbindingStack;

      if (patternrecord.topUnbindingStackOffset < ubstackoffset) {
        return;
      }
      if ((Stella.$TRACED_KEYWORDS$ != null) &&
          Stella.$TRACED_KEYWORDS$.membP(Logic.KWD_QUERY_STACKS)) {
        System.out.println("unbind-variables-beginning-at: UBS= " + ubstackoffset + "  F" + ControlFrame.debugFrameId(patternrecord.controlFrame) + "  #bindings= " + ((patternrecord.topUnbindingStackOffset - ubstackoffset) + 1));
      }
      { int i = Stella.NULL_INTEGER;
        int iter000 = ubstackoffset;
        int upperBound000 = patternrecord.topUnbindingStackOffset;
        boolean unboundedP000 = upperBound000 == Stella.NULL_INTEGER;

        while (unboundedP000 ||
            (iter000 <= upperBound000)) {
          {
            i = iter000;
            iter000 = iter000 + 1;
          }
          (variablebindingsvector.theArray)[(((IntegerWrapper)((unbindingstack.theArray)[i])).wrapperValue)] = null;
          (unbindingstack.theArray)[i] = null;
        }
      }
      patternrecord.topUnbindingStackOffset = ubstackoffset - 1;
    }
  }

  public static void activatePatternRecord(PatternRecord patternrecord, int variablecount) {
    { Vector vector = patternrecord.variableBindings;
      IntegerVector stack = patternrecord.unbindingStack;

      if ((vector != null) &&
          (vector.arraySize >= variablecount)) {
        { int i = Stella.NULL_INTEGER;
          int iter000 = 0;
          int upperBound000 = variablecount - 1;

          while (iter000 <= upperBound000) {
            {
              i = iter000;
              iter000 = iter000 + 1;
            }
            (vector.theArray)[i] = null;
            (stack.theArray)[i] = null;
          }
        }
      }
      else {
        {
          patternrecord.variableBindings = Vector.newVector(variablecount);
          patternrecord.unbindingStack = IntegerVector.newIntegerVector(variablecount);
        }
      }
      patternrecord.topUnbindingStackOffset = -1;
      ((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentPatternRecord = patternrecord;
    }
  }

  public static Stella_Object accessPatternRecordSlotValue(PatternRecord self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_CONTROL_FRAME) {
      if (setvalueP) {
        self.controlFrame = ((ControlFrame)(value));
      }
      else {
        value = self.controlFrame;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_VARIABLE_BINDINGS) {
      if (setvalueP) {
        self.variableBindings = ((Vector)(value));
      }
      else {
        value = self.variableBindings;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_UNBINDING_STACK) {
      if (setvalueP) {
        self.unbindingStack = ((IntegerVector)(value));
      }
      else {
        value = self.unbindingStack;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_TOP_UNBINDING_STACK_OFFSET) {
      if (setvalueP) {
        self.topUnbindingStackOffset = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.topUnbindingStackOffset);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_DESCRIPTION) {
      if (setvalueP) {
        self.description = ((Description)(value));
      }
      else {
        value = self.description;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_EXTERNAL_ARGUMENTS) {
      if (setvalueP) {
        self.externalArguments = ((Vector)(value));
      }
      else {
        value = self.externalArguments;
      }
    }
    else if (slotname == Logic.SYM_STELLA_BOOLEAN_VECTOR) {
      if (setvalueP) {
        self.booleanVector = ((BooleanVector)(value));
      }
      else {
        value = self.booleanVector;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_OPTIMAL_PATTERN) {
      if (setvalueP) {
        self.optimalPattern = ((Description)(value));
      }
      else {
        value = self.optimalPattern;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_COLLECTION_LIST) {
      if (setvalueP) {
        self.collectionList = ((List)(value));
      }
      else {
        value = self.collectionList;
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
    { PatternRecord self = this;

      return (Logic.SGT_LOGIC_PATTERN_RECORD);
    }
  }

  public void free() {
    { PatternRecord self = this;

      if (PatternRecord.terminatePatternRecordP(self)) {
        Stella_Object.unmake(self);
      }
    }
  }

}

