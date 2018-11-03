//  -*- Mode: Java -*-
//
// ParallelControlFrame.java

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

public class ParallelControlFrame extends ControlFrame {
    public List childThreads;
    public boolean unboundVariablesP;
    public ParallelThread currentChildThread;
    public Context savedParentContext;
    public ParallelThread savedParentParallelThread;

  public static ParallelControlFrame newParallelControlFrame() {
    { ParallelControlFrame self = null;

      self = new ParallelControlFrame();
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.dontCacheGoalFailureP = Stella.FALSE;
      self.cachedGoalResultP = Stella.FALSE;
      self.goalBindings = null;
      self.justifications = List.newList();
      self.partialMatchFrame = null;
      self.nextStrategies = Stella.NIL;
      self.currentStrategy = null;
      self.choicePointUnbindingOffset = Stella.NULL_INTEGER;
      self.inheritedPatternRecord = null;
      self.patternRecord = null;
      self.argumentCursor = 0;
      self.result = null;
      self.down = null;
      self.up = null;
      self.allottedClockTicks = Stella.NULL_INTEGER;
      self.startingClockTicks = Stella.NULL_INTEGER;
      self.reversePolarityP = Stella.FALSE;
      self.truthValue = null;
      self.proposition = null;
      self.state = null;
      self.savedParentParallelThread = null;
      self.savedParentContext = null;
      self.currentChildThread = null;
      self.unboundVariablesP = Stella.FALSE;
      self.childThreads = List.newList();
      return (self);
    }
  }

  public static ParallelThread createChildThread(ParallelControlFrame pframe) {
    { Cons strategies = pframe.nextStrategies;
      ParallelThread childthread = ParallelThread.newParallelThread();
      ControlFrame downframe = ControlFrame.createDownFrame(pframe, pframe.proposition);

      downframe.state = Logic.KWD_STRATEGY;
      downframe.currentStrategy = ((Keyword)(strategies.value));
      pframe.nextStrategies = strategies.rest;
      if ((((QueryIterator)(Logic.$QUERYITERATOR$.get())) != null) &&
          (((QueryIterator)(Logic.$QUERYITERATOR$.get())).partialMatchStrategy != null)) {
        ControlFrame.createAndLinkPartialMatchFrame(downframe, Logic.KWD_STRATEGY);
      }
      childthread.topControlFrame = downframe;
      pframe.childThreads.insert(childthread);
      return (childthread);
    }
  }

  public static ParallelThread selectNextChildThread(ParallelControlFrame pframe) {
    return (((ParallelThread)(pframe.childThreads.first())));
  }

  public static Keyword continueParallelStrategiesProofs(ParallelControlFrame pframe, Keyword lastmove) {
    if (lastmove == Logic.KWD_DOWN) {
      if (pframe.down != null) {
        ParallelControlFrame.enterParallelThread(pframe, null);
        return (Logic.KWD_MOVE_DOWN);
      }
      return (ControlFrame.continueCurrentOrNextStrategy(pframe));
    }
    else if (lastmove == Logic.KWD_UP_TRUE) {
      ParallelControlFrame.exitParallelThread(pframe);
      if (pframe.unboundVariablesP) {
      }
      ControlFrame.propagateFrameTruthValue(pframe.result, pframe);
      if (pframe.down != null) {
        return (Logic.KWD_CONTINUING_SUCCESS);
      }
      else {
        return (Logic.KWD_FINAL_SUCCESS);
      }
    }
    else if (lastmove == Logic.KWD_UP_FAIL) {
      ParallelControlFrame.exitParallelThread(pframe);
      ControlFrame.propagateFrameTruthValue(pframe.result, pframe);
      return (Logic.KWD_FAILURE);
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + lastmove + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public static World enterHypotheticalWorld(ParallelControlFrame pframe) {
    { ParallelThread childthread = pframe.currentChildThread;
      World world = childthread.hypotheticalWorld;

      if (world == null) {
        {
          childthread.hypotheticalWorld = Logic.pushMonotonicWorld();
          Logic.initializeInferenceWorld(((World)(((Context)(Stella.$CONTEXT$.get())))));
        }
      }
      else {
      }
      return (world);
    }
  }

  public static void exitParallelThread(ParallelControlFrame pframe) {
    ((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentParallelThread = pframe.savedParentParallelThread;
    if (pframe.savedParentContext != null) {
      if ((pframe.down == null) &&
          (pframe.currentChildThread.hypotheticalWorld != null)) {
        {
          Stella.popWorld();
        }
      }
      else {
        pframe.savedParentContext.changeContext();
      }
      pframe.savedParentContext = null;
    }
    if (pframe.down == null) {
      pframe.childThreads.remove(pframe.currentChildThread);
      pframe.currentChildThread = null;
    }
  }

  public static void enterParallelThread(ParallelControlFrame pframe, ParallelThread childthread) {
    if (childthread != null) {
      {
        pframe.currentChildThread = childthread;
        pframe.down = childthread.topControlFrame;
      }
    }
    else {
      childthread = pframe.currentChildThread;
    }
    pframe.savedParentParallelThread = ((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentParallelThread;
    ((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentParallelThread = childthread;
    pframe.savedParentContext = ((Context)(Stella.$CONTEXT$.get()));
    if (childthread.hypotheticalWorld != null) {
      childthread.hypotheticalWorld.changeContext();
    }
  }

  public static Stella_Object accessParallelControlFrameSlotValue(ParallelControlFrame self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_CHILD_THREADS) {
      if (setvalueP) {
        self.childThreads = ((List)(value));
      }
      else {
        value = self.childThreads;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_UNBOUND_VARIABLESp) {
      if (setvalueP) {
        self.unboundVariablesP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.unboundVariablesP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
      }
    }
    else if (slotname == Logic.SYM_LOGIC_CURRENT_CHILD_THREAD) {
      if (setvalueP) {
        self.currentChildThread = ((ParallelThread)(value));
      }
      else {
        value = self.currentChildThread;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_SAVED_PARENT_CONTEXT) {
      if (setvalueP) {
        self.savedParentContext = ((Context)(value));
      }
      else {
        value = self.savedParentContext;
      }
    }
    else if (slotname == Logic.SYM_LOGIC_SAVED_PARENT_PARALLEL_THREAD) {
      if (setvalueP) {
        self.savedParentParallelThread = ((ParallelThread)(value));
      }
      else {
        value = self.savedParentParallelThread;
      }
    }
    else {
      if (setvalueP) {
        KeyValueList.setDynamicSlotValue(self.dynamicSlots, slotname, value, null);
      }
      else {
        value = self.dynamicSlots.lookup(slotname);
      }
    }
    return (value);
  }

  public Surrogate primaryType() {
    { ParallelControlFrame self = this;

      return (Logic.SGT_LOGIC_PARALLEL_CONTROL_FRAME);
    }
  }

}

