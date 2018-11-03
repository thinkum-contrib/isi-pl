//  -*- Mode: Java -*-
//
// PlKernelKb.java

/*
 +---------------------------- BEGIN LICENSE BLOCK ---------------------------+
 |                                                                            |
 | Version: MPL 1.1/GPL 2.0/LGPL 2.1                                          |
 |                                                                            |
 | The contents of this file are subject to the Mozilla Public License        |
 | Version 1.1 (the "License"); you may not use this file except in           |
 | compliance with the License. You may obtain a copy of the License at       |
 | http://www.mozilla.org/MPL/                                                |
 |                                                                            |
 | Software distributed under the License is distributed on an "AS IS" basis, |
 | WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License   |
 | for the specific language governing rights and limitations under the       |
 | License.                                                                   |
 |                                                                            |
 | The Original Code is the PowerLoom KR&R System.                            |
 |                                                                            |
 | The Initial Developer of the Original Code is                              |
 | UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
 | 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
 |                                                                            |
 | Portions created by the Initial Developer are Copyright (C) 1997-2006      |
 | the Initial Developer. All Rights Reserved.                                |
 |                                                                            |
 | Contributor(s):                                                            |
 |                                                                            |
 | Alternatively, the contents of this file may be used under the terms of    |
 | either the GNU General Public License Version 2 or later (the "GPL"), or   |
 | the GNU Lesser General Public License Version 2.1 or later (the "LGPL"),   |
 | in which case the provisions of the GPL or the LGPL are applicable instead |
 | of those above. If you wish to allow use of your version of this file only |
 | under the terms of either the GPL or the LGPL, and not to allow others to  |
 | use your version of this file under the terms of the MPL, indicate your    |
 | decision by deleting the provisions above and replace them with the notice |
 | and other provisions required by the GPL or the LGPL. If you do not delete |
 | the provisions above, a recipient may use your version of this file under  |
 | the terms of any one of the MPL, the GPL or the LGPL.                      |
 |                                                                            |
 +----------------------------- END LICENSE BLOCK ----------------------------+
*/

package edu.isi.powerloom.pl_kernel_kb;

import edu.isi.stella.javalib.Native;
import edu.isi.stella.javalib.StellaSpecialVariable;
import edu.isi.powerloom.logic.*;
import edu.isi.stella.*;

public class PlKernelKb {
  public static Cons $PL_KERNEL_KB_DEFINITIONS$ = null;

  public static Symbol SYM_PL_KERNEL_KB_STARTUP_PL_KERNEL_KB = null;

  public static Surrogate SGT_PL_KERNEL_KB_INTEGER_INTERVAL = null;

  public static Symbol SYM_PL_KERNEL_KB_INTERVAL_LOWER_BOUND = null;

  public static Symbol SYM_PL_KERNEL_KB_INTERVAL_UPPER_BOUND = null;

  public static Symbol SYM_PL_KERNEL_KB_INTERVAL_MEMBER = null;

  public static Symbol SYM_STELLA_LOWER_BOUND = null;

  public static Symbol SYM_STELLA_UPPER_BOUND = null;

  public static Symbol SYM_PL_KERNEL_KB_STRICT_LOWER_BOUNDp = null;

  public static Symbol SYM_PL_KERNEL_KB_STRICT_UPPER_BOUNDp = null;

  public static Surrogate SGT_PL_KERNEL_KB_INTERVAL_CACHE_OF = null;

  public static Surrogate SGT_PL_KERNEL_KB_g = null;

  public static Surrogate SGT_PL_KERNEL_KB_l = null;

  public static Surrogate SGT_PL_KERNEL_KB_el = null;

  public static Keyword KWD_LOWER_BOUND = null;

  public static Keyword KWD_UPPER_BOUND = null;

  public static Surrogate SGT_PL_KERNEL_KB_e = null;

  public static Symbol SYM_PL_KERNEL_KB_STARTUP_ARITHMETIC = null;

  public static Keyword computationSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Vector arguments = proposition.arguments;
      NamedDescription description = Logic.getDescription(((Surrogate)(proposition.operator)));
      java.lang.reflect.Method computationcode = NamedDescription.lookupComputation(description);
      Stella_Object value = null;
      Cons boundarguments = Stella.NIL;
      boolean successP = false;

      lastmove = lastmove;
      if (NamedDescription.functionDescriptionP(description)) {
        { Stella_Object arg = null;
          Vector vector000 = arguments;
          int index000 = 0;
          int length000 = vector000.length();
          Stella_Object domain = null;
          Iterator iter000 = NamedDescription.allDomainTypes(description);
          Cons collect000 = null;

          for (;(index000 < length000) &&
                    iter000.nextP(); index000 = index000 + 1) {
            arg = (vector000.theArray)[index000];
            domain = iter000.value;
            value = Logic.argumentBoundTo(arg);
            if ((value == null) ||
                (Logic.skolemP(value) ||
                 (!Logic.checkStrictTypeP(arg, ((Surrogate)(domain)), true)))) {
              return (Logic.KWD_FAILURE);
            }
            if (collect000 == null) {
              {
                collect000 = Stella_Object.cons(value, Stella.NIL);
                if (boundarguments == Stella.NIL) {
                  boundarguments = collect000;
                }
                else {
                  Cons.addConsToEndOfConsList(boundarguments, collect000);
                }
              }
            }
            else {
              {
                collect000.rest = Stella_Object.cons(value, Stella.NIL);
                collect000 = collect000.rest;
              }
            }
          }
        }
        value = Stella.apply(computationcode, boundarguments);
        if (value == null) {
          return (Logic.KWD_FAILURE);
        }
        { Stella_Object lastarg = (proposition.arguments.theArray)[(proposition.arguments.length() - 1)];

          successP = (Stella_Object.isaP(lastarg, Logic.SGT_LOGIC_PATTERN_VARIABLE) ? PatternVariable.bindVariableToValueP(((PatternVariable)(lastarg)), value, true) : Stella_Object.eqlP(Logic.valueOf(lastarg), value));
        }
      }
      else {
        { Stella_Object arg = null;
          Vector vector001 = arguments;
          int index001 = 0;
          int length001 = vector001.length();
          Stella_Object domain = null;
          Iterator iter001 = NamedDescription.allArgumentTypes(description);
          Cons collect001 = null;

          for (;(index001 < length001) &&
                    iter001.nextP(); index001 = index001 + 1) {
            arg = (vector001.theArray)[index001];
            domain = iter001.value;
            value = Logic.argumentBoundTo(arg);
            if ((value == null) ||
                (Logic.skolemP(value) ||
                 (!Logic.checkStrictTypeP(arg, ((Surrogate)(domain)), true)))) {
              return (Logic.KWD_FAILURE);
            }
            if (collect001 == null) {
              {
                collect001 = Stella_Object.cons(value, Stella.NIL);
                if (boundarguments == Stella.NIL) {
                  boundarguments = collect001;
                }
                else {
                  Cons.addConsToEndOfConsList(boundarguments, collect001);
                }
              }
            }
            else {
              {
                collect001.rest = Stella_Object.cons(value, Stella.NIL);
                collect001 = collect001.rest;
              }
            }
          }
        }
        successP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(Stella.apply(computationcode, boundarguments))));
      }
      return (Logic.selectTestResult(successP, true, frame));
    }
  }

  public static Keyword constraintSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      NamedDescription description = Logic.getDescription(((Surrogate)(proposition.operator)));
      java.lang.reflect.Method computationcode = NamedDescription.lookupConstraint(description);
      Stella_Object value = null;
      int nullcount = 0;
      int variableindex = -1;
      Cons argumentvalues = Stella.NIL;

      lastmove = lastmove;
      { Stella_Object arg = null;
        Vector vector000 = proposition.arguments;
        int index000 = 0;
        int length000 = vector000.length();
        Stella_Object domain = null;
        Iterator iter000 = NamedDescription.allArgumentTypes(description);
        int i = Stella.NULL_INTEGER;
        int iter001 = 0;
        Cons collect000 = null;

        for (;(index000 < length000) &&
                  iter000.nextP(); index000 = index000 + 1, iter001 = iter001 + 1) {
          arg = (vector000.theArray)[index000];
          domain = iter000.value;
          i = iter001;
          value = Logic.argumentBoundTo(arg);
          if ((value == null) &&
              Stella_Object.isaP(arg, Logic.SGT_LOGIC_PATTERN_VARIABLE)) {
            nullcount = nullcount + 1;
            variableindex = i;
          }
          else if ((value != null) &&
              Stella_Object.isaP(value, Logic.SGT_LOGIC_SKOLEM)) {
            return (Logic.KWD_FAILURE);
          }
          else if (!Logic.checkStrictTypeP(value, ((Surrogate)(domain)), true)) {
            return (Logic.KWD_FAILURE);
          }
          if (collect000 == null) {
            {
              collect000 = Stella_Object.cons(value, Stella.NIL);
              if (argumentvalues == Stella.NIL) {
                argumentvalues = collect000;
              }
              else {
                Cons.addConsToEndOfConsList(argumentvalues, collect000);
              }
            }
          }
          else {
            {
              collect000.rest = Stella_Object.cons(value, Stella.NIL);
              collect000 = collect000.rest;
            }
          }
        }
      }
      switch (nullcount) {
        case 0: 
          value = Stella.apply(computationcode, Stella_Object.cons(IntegerWrapper.wrapInteger(variableindex), argumentvalues));
          return (Logic.selectTestResult(((BooleanWrapper)(value)) == Stella.TRUE_WRAPPER, true, frame));
        case 1: 
          if (((Boolean)(Logic.$REVERSEPOLARITYp$.get())).booleanValue()) {
            return (Logic.KWD_FAILURE);
          }
          value = Stella.apply(computationcode, Stella_Object.cons(IntegerWrapper.wrapInteger(variableindex), argumentvalues));
          if (value == null) {
            return (Logic.KWD_FAILURE);
          }
          return (Logic.selectTestResult(PatternVariable.bindVariableToValueP(((PatternVariable)((proposition.arguments.theArray)[variableindex])), value, true), true, frame));
        default:
          return (Logic.KWD_FAILURE);
      }
    }
  }

  public static Keyword squareRootSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object mainarg = (proposition.arguments.theArray)[0];
      Stella_Object mainargvalue = Logic.argumentBoundTo(mainarg);
      Stella_Object rootarg = (proposition.arguments.theArray)[1];
      Stella_Object rootargvalue = Logic.argumentBoundTo(rootarg);
      Iterator iterator = ((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null)));
      Cons collection = Stella.NIL;

      lastmove = lastmove;
      if (iterator == null) {
        if (mainargvalue == null) {
          if (rootargvalue == null) {
            return (Logic.KWD_TERMINAL_FAILURE);
          }
          else {
            if (Stella_Object.isaP(rootargvalue, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
              if (((Boolean)(Logic.$REVERSEPOLARITYp$.get())).booleanValue()) {
                return (Logic.KWD_FAILURE);
              }
              else {
                return (Logic.selectProofResult(Logic.bindArgumentToValueP(mainarg, PlKernelKb.timesComputation(((NumberWrapper)(rootargvalue)), ((NumberWrapper)(rootargvalue))), true), false, true));
              }
            }
            else {
              return (Logic.KWD_TERMINAL_FAILURE);
            }
          }
        }
        else {
          if (Stella_Object.isaP(mainargvalue, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
            if (PlKernelKb.arithmeticLessTest(((NumberWrapper)(mainargvalue)), IntegerWrapper.wrapInteger(0))) {
              return (Logic.KWD_TERMINAL_FAILURE);
            }
            else {
              if ((rootargvalue == null) &&
                  ((Boolean)(Logic.$REVERSEPOLARITYp$.get())).booleanValue()) {
                return (Logic.KWD_FAILURE);
              }
              else {
                { NumberWrapper sqrt = PlKernelKb.sqrtComputation(((NumberWrapper)(mainargvalue)));

                  collection = Stella.consList(Stella_Object.cons(sqrt, Stella_Object.cons(PlKernelKb.negateComputation(sqrt), Stella.NIL)));
                }
              }
            }
          }
          else {
            return (Logic.KWD_TERMINAL_FAILURE);
          }
        }
      }
      if (rootargvalue != null) {
        return (Logic.selectTestResult(PlKernelKb.arithmeticEqualTest(((NumberWrapper)(rootargvalue)), ((NumberWrapper)(collection.value))) ||
            PlKernelKb.arithmeticEqualTest(((NumberWrapper)(rootargvalue)), ((NumberWrapper)(collection.rest.value))), true, frame));
      }
      if (iterator == null) {
        iterator = collection.allocateIterator();
        KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, iterator, null);
      }
      if (iterator.nextP() &&
          Logic.bindArgumentToValueP(rootarg, iterator.value, true)) {
        return (Logic.KWD_CONTINUING_SUCCESS);
      }
      else {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
    }
  }

  public static Keyword absoluteValueSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object mainarg = (proposition.arguments.theArray)[0];
      Stella_Object mainargvalue = Logic.argumentBoundTo(mainarg);
      Stella_Object absarg = (proposition.arguments.theArray)[1];
      Stella_Object absargvalue = Logic.argumentBoundTo(absarg);
      Iterator iterator = ((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null)));
      Cons collection = Stella.NIL;

      lastmove = lastmove;
      if (iterator == null) {
        if (absargvalue == null) {
          if (mainargvalue == null) {
            return (Logic.KWD_TERMINAL_FAILURE);
          }
          else {
            if (Stella_Object.isaP(mainargvalue, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
              if (((Boolean)(Logic.$REVERSEPOLARITYp$.get())).booleanValue()) {
                return (Logic.KWD_FAILURE);
              }
              else {
                return (Logic.selectProofResult(Logic.bindArgumentToValueP(absarg, PlKernelKb.absComputation(((NumberWrapper)(mainargvalue))), true), false, true));
              }
            }
            else {
              return (Logic.KWD_TERMINAL_FAILURE);
            }
          }
        }
        else {
          if (Stella_Object.isaP(absargvalue, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
            if (PlKernelKb.arithmeticLessTest(((NumberWrapper)(absargvalue)), IntegerWrapper.wrapInteger(0))) {
              return (Logic.KWD_TERMINAL_FAILURE);
            }
            else {
              if (((Boolean)(Logic.$REVERSEPOLARITYp$.get())).booleanValue()) {
                return (Logic.KWD_FAILURE);
              }
              else {
                collection = Stella.consList(Stella_Object.cons(absargvalue, Stella_Object.cons(PlKernelKb.negateComputation(((NumberWrapper)(absargvalue))), Stella.NIL)));
              }
            }
          }
          else {
            return (Logic.KWD_TERMINAL_FAILURE);
          }
        }
      }
      if (mainargvalue != null) {
        return (Logic.selectTestResult(PlKernelKb.arithmeticEqualTest(((NumberWrapper)(mainargvalue)), ((NumberWrapper)(collection.value))) ||
            PlKernelKb.arithmeticEqualTest(((NumberWrapper)(mainargvalue)), ((NumberWrapper)(collection.rest.value))), true, frame));
      }
      if (iterator == null) {
        iterator = collection.allocateIterator();
        KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, iterator, null);
      }
      if (iterator.nextP() &&
          Logic.bindArgumentToValueP(mainarg, iterator.value, true)) {
        return (Logic.KWD_CONTINUING_SUCCESS);
      }
      else {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
    }
  }

  public static Keyword memberOfSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Vector arguments = proposition.arguments;
      Stella_Object memberarg = (arguments.theArray)[0];
      Stella_Object member = Logic.argumentBoundTo(memberarg);
      Stella_Object collectionarg = (arguments.theArray)[1];
      Stella_Object collection = Logic.argumentBoundTo(collectionarg);
      Iterator iterator = ((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null)));

      if (lastmove == Logic.KWD_UP_TRUE) {
        return (((frame.down != null) ? Logic.KWD_CONTINUING_SUCCESS : Logic.KWD_FINAL_SUCCESS));
      }
      else if (lastmove == Logic.KWD_UP_FAIL) {
        return (Logic.KWD_FAILURE);
      }
      else {
      }
      if (iterator == null) {
        if (collection == null) {
          if (member == null) {
            return (Logic.KWD_FAILURE);
          }
          iterator = ((ListIterator)(Logic.enumerationsContainingMember(member).allocateIterator()));
        }
        else {
          { Surrogate testValue000 = Stella_Object.safePrimaryType(collection);

            if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_NAMED_DESCRIPTION)) {
              { NamedDescription collection000 = ((NamedDescription)(collection));

                { Proposition isaprop = Logic.createProposition(Logic.SYM_STELLA_ISA, 1);

                  isaprop.operator = collection000.surrogateValueInverse;
                  (isaprop.arguments.theArray)[0] = memberarg;
                  ControlFrame.createDownFrame(frame, isaprop);
                  return (Logic.KWD_MOVE_DOWN);
                }
              }
            }
            else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_DESCRIPTION)) {
              { Description collection000 = ((Description)(collection));

                { boolean testValue001 = false;

                  testValue001 = collection000.arity() == 1;
                  if (testValue001) {
                    if (((Vector)(KeyValueList.dynamicSlotValue(collection000.dynamicSlots, Logic.SYM_LOGIC_EXTERNAL_VARIABLES, null))) == null) {
                      testValue001 = true;
                    }
                    else {
                      { boolean alwaysP000 = true;

                        { PatternVariable var = null;
                          Vector vector000 = ((Vector)(KeyValueList.dynamicSlotValue(collection000.dynamicSlots, Logic.SYM_LOGIC_EXTERNAL_VARIABLES, null)));
                          int index000 = 0;
                          int length000 = vector000.length();

                          loop000 : for (;index000 < length000; index000 = index000 + 1) {
                            var = ((PatternVariable)((vector000.theArray)[index000]));
                            if (!(Logic.argumentBoundTo(var) != null)) {
                              alwaysP000 = false;
                              break loop000;
                            }
                          }
                        }
                        testValue001 = alwaysP000;
                      }
                    }
                  }
                  if (testValue001) {
                    {
                      if (ControlFrame.overlayWithPatternFrameP(ControlFrame.createDownFrame(frame, null), collection000, Stella.vector(Stella_Object.cons(memberarg, Stella.NIL)))) {
                        return (Logic.KWD_MOVE_DOWN);
                      }
                      else {
                        return (Logic.KWD_FAILURE);
                      }
                    }
                  }
                  else {
                    {
                      return (Logic.KWD_FAILURE);
                    }
                  }
                }
              }
            }
            else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_STELLA_COLLECTION)) {
              { Collection collection000 = ((Collection)(collection));

                if (member == null) {
                  iterator = ((ListIterator)(Logic.assertedCollectionMembers(collection000, false).allocateIterator()));
                }
                else {
                  return (Logic.selectTestResult(Logic.memberOfCollectionP(member, collection000), false, frame));
                }
              }
            }
            else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_LOGIC_OBJECT)) {
              { LogicObject collection000 = ((LogicObject)(collection));

                if (member == null) {
                  iterator = ((ListIterator)(Logic.assertedCollectionMembers(collection000, false).allocateIterator()));
                }
                else {
                  return (Logic.selectTestResult(Logic.memberOfCollectionP(member, collection000), false, frame));
                }
              }
            }
            else {
              return (Logic.KWD_FAILURE);
            }
          }
        }
        KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, iterator, null);
      }
      while (iterator.nextP()) {
        if (collection == null) {
          if (PatternVariable.bindVariableToValueP(((PatternVariable)(collectionarg)), Logic.valueOf(iterator.value), true)) {
            return (Logic.KWD_CONTINUING_SUCCESS);
          }
        }
        else {
          if (PatternVariable.bindVariableToValueP(((PatternVariable)(memberarg)), Logic.valueOf(iterator.value), true)) {
            return (Logic.KWD_CONTINUING_SUCCESS);
          }
        }
      }
      return (Logic.KWD_FAILURE);
    }
  }

  public static void memberOfEvaluator(Proposition self) {
    { Stella_Object member = Logic.valueOf((self.arguments.theArray)[0]);
      Stella_Object collection = Logic.valueOf((self.arguments.theArray)[1]);

      if (Proposition.trueP(self)) {
        if (Stella_Object.isaP(collection, Logic.SGT_LOGIC_DESCRIPTION) &&
            (Stella_Object.isaP(member, Logic.SGT_LOGIC_LOGIC_OBJECT) &&
             (!Description.namedDescriptionP(((Description)(collection)))))) {
          Logic.inheritUnnamedDescription(((LogicObject)(member)), ((Description)(collection)), Proposition.defaultTrueP(self));
        }
        if (Logic.logicalCollectionP(collection)) {
          { Object old$ReversepolarityP$000 = Logic.$REVERSEPOLARITYp$.get();

            try {
              Native.setBooleanSpecial(Logic.$REVERSEPOLARITYp$, true);
              if (Logic.memberOfCollectionP(member, collection) &&
                  (!Logic.skolemP(member))) {
                Proposition.signalTruthValueClash(self);
              }

            } finally {
              Logic.$REVERSEPOLARITYp$.set(old$ReversepolarityP$000);
            }
          }
        }
      }
    }
  }

  public static Keyword instanceOfSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Vector arguments = proposition.arguments;
      Stella_Object memberarg = (arguments.theArray)[0];
      Stella_Object member = Logic.argumentBoundTo(memberarg);
      Stella_Object collectionarg = (arguments.theArray)[1];
      Stella_Object collection = Logic.argumentBoundTo(collectionarg);
      Iterator iterator = ((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null)));

      if (lastmove == Logic.KWD_UP_TRUE) {
        return (((frame.down != null) ? Logic.KWD_CONTINUING_SUCCESS : Logic.KWD_FINAL_SUCCESS));
      }
      else if (lastmove == Logic.KWD_UP_FAIL) {
        return (Logic.KWD_FAILURE);
      }
      else {
      }
      if (iterator == null) {
        if (collection != null) {
          if (Logic.classP(collection) &&
              Stella_Object.isaP(collection, Logic.SGT_LOGIC_NAMED_DESCRIPTION)) {
            { Proposition isaproposition = Logic.createProposition(Logic.SYM_STELLA_ISA, 1);

              isaproposition.operator = ((NamedDescription)(collection)).surrogateValueInverse;
              (isaproposition.arguments.theArray)[0] = memberarg;
              ControlFrame.createSubgoalFrame(frame, isaproposition, null);
              return (Logic.KWD_MOVE_DOWN);
            }
          }
          else if (member == null) {
            ControlFrame.createSubgoalFrame(frame, frame.proposition, Logic.KWD_SCAN_COLLECTION);
            return (Logic.KWD_MOVE_DOWN);
          }
          else {
            if (Logic.memberOfCollectionP(member, collection)) {
              return (Logic.KWD_FINAL_SUCCESS);
            }
            else {
              return (Logic.KWD_FAILURE);
            }
          }
        }
        else if (member != null) {
          iterator = Logic.allTypes(member).allocateIterator();
          KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, iterator, null);
        }
        else {
          return (Logic.KWD_FAILURE);
        }
      }
      if (iterator != null) {
        if (iterator.nextP()) {
          PatternVariable.bindVariableToValueP(((PatternVariable)(collectionarg)), iterator.value, true);
          return (Logic.KWD_CONTINUING_SUCCESS);
        }
        return (Logic.KWD_FAILURE);
      }
      return (Logic.KWD_FAILURE);
    }
  }

  public static Keyword subsetOfSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object subcollectionarg = (proposition.arguments.theArray)[0];
      Stella_Object supercollectionarg = (proposition.arguments.theArray)[1];
      Stella_Object subcollection = Logic.equivalentValueOf(Logic.argumentBoundTo(subcollectionarg));
      Stella_Object supercollection = Logic.equivalentValueOf(Logic.argumentBoundTo(supercollectionarg));
      Iterator iterator = ((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null)));

      lastmove = lastmove;
      if (iterator == null) {
        if ((subcollection != null) &&
            (supercollection != null)) {
          if (LogicObject.collectionImpliesCollectionP(((LogicObject)(subcollection)), ((LogicObject)(supercollection)))) {
            return (Logic.selectTestResult(true, true, frame));
          }
          else if (Logic.testDisjointTermsP(subcollection, supercollection)) {
            return (Logic.selectTestResult(false, true, frame));
          }
          else {
            return (Logic.KWD_FAILURE);
          }
        }
        else if (subcollection != null) {
          { Surrogate testValue000 = Stella_Object.safePrimaryType(subcollection);

            if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_LOGIC_OBJECT)) {
              { LogicObject subcollection000 = ((LogicObject)(subcollection));

                iterator = Stella_Object.cons(subcollection000, Stella.NIL).allocateIterator().concatenate(LogicObject.allSupercollections(subcollection000), Stella.NIL);
              }
            }
            else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_STELLA_COLLECTION)) {
              { Collection subcollection000 = ((Collection)(subcollection));

                return (Logic.KWD_FAILURE);
              }
            }
            else {
              { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
        else if (supercollection != null) {
          { Surrogate testValue001 = Stella_Object.safePrimaryType(supercollection);

            if (Surrogate.subtypeOfP(testValue001, Logic.SGT_LOGIC_LOGIC_OBJECT)) {
              { LogicObject supercollection000 = ((LogicObject)(supercollection));

                iterator = Stella_Object.cons(supercollection000, Stella.NIL).allocateIterator().concatenate(LogicObject.allSubcollections(supercollection000), Stella.NIL);
              }
            }
            else if (Surrogate.subtypeOfP(testValue001, Logic.SGT_STELLA_COLLECTION)) {
              { Collection supercollection000 = ((Collection)(supercollection));

                return (Logic.KWD_FAILURE);
              }
            }
            else {
              { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

                stream001.nativeStream.print("`" + testValue001 + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
        else {
          {
            System.out.println();
            System.out.println(" Found 'subset-of' goal with two unbound arguments.");
            System.out.println("   Possibly the query needs rewriting.");
            System.out.println();
          }
;
          return (Logic.KWD_FAILURE);
        }
        KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, iterator, null);
      }
      while (iterator.nextP()) {
        { Stella_Object value = Logic.valueOf(iterator.value);

          if (true &&
              (((subcollection != null) ? PatternVariable.bindVariableToValueP(((PatternVariable)(supercollectionarg)), value, true) : PatternVariable.bindVariableToValueP(((PatternVariable)(subcollectionarg)), value, true)))) {
            return (Logic.KWD_CONTINUING_SUCCESS);
          }
        }
      }
      return (Logic.KWD_FAILURE);
    }
  }

  public static Keyword holdsSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition holdsproposition = frame.proposition;
      Vector holdsarguments = holdsproposition.arguments;
      int holdsarity = holdsarguments.length() - 1;
      Stella_Object description = Logic.argumentBoundTo((holdsarguments.theArray)[0]);

      if (description != null) {
        if (lastmove == Logic.KWD_UP_TRUE) {
          return (((frame.down != null) ? Logic.KWD_CONTINUING_SUCCESS : Logic.KWD_FINAL_SUCCESS));
        }
        else if (lastmove == Logic.KWD_UP_FAIL) {
          return (Logic.KWD_FAILURE);
        }
        else if (lastmove == Logic.KWD_DOWN) {
        }
        else {
          { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

            stream000.nativeStream.print("`" + lastmove + "' is not a valid case option");
            throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
          }
        }
        { Surrogate testValue000 = Stella_Object.safePrimaryType(description);

          if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_NAMED_DESCRIPTION)) {
            { NamedDescription description000 = ((NamedDescription)(description));

              { int argcountminus1 = holdsarguments.length() - 1;
                Symbol kind = Logic.SYM_STELLA_PREDICATE;
                Proposition relationproposition = null;
                Surrogate relationref = description000.surrogateValueInverse;

                if (NamedDescription.classDescriptionP(description000)) {
                  kind = Logic.SYM_STELLA_ISA;
                }
                else if (NamedDescription.functionDescriptionP(description000)) {
                  kind = Logic.SYM_STELLA_FUNCTION;
                }
                relationproposition = Logic.createProposition(kind, argcountminus1);
                relationproposition.operator = relationref;
                { int i = Stella.NULL_INTEGER;
                  int iter000 = 0;
                  int upperBound000 = argcountminus1 - 1;

                  for (;iter000 <= upperBound000; iter000 = iter000 + 1) {
                    i = iter000;
                    (relationproposition.arguments.theArray)[i] = ((holdsarguments.theArray)[(i + 1)]);
                  }
                }
                ControlFrame.createSubgoalFrame(frame, relationproposition, null);
                return (Logic.KWD_MOVE_DOWN);
              }
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_DESCRIPTION)) {
            { Description description000 = ((Description)(description));

              { int argcountminus1 = holdsarguments.length() - 1;
                Proposition dummyproposition = Logic.createProposition(Logic.SYM_STELLA_DUMMY, argcountminus1);
                ControlFrame subgoalframe = ControlFrame.createSubgoalFrame(frame, dummyproposition, Logic.KWD_FULL_SUBQUERY);

                { int i = Stella.NULL_INTEGER;
                  int iter001 = 0;
                  int upperBound001 = argcountminus1 - 1;

                  for (;iter001 <= upperBound001; iter001 = iter001 + 1) {
                    i = iter001;
                    (dummyproposition.arguments.theArray)[i] = ((holdsarguments.theArray)[(i + 1)]);
                  }
                }
                KeyValueList.setDynamicSlotValue(subgoalframe.dynamicSlots, Logic.SYM_LOGIC_DESCRIPTION, description000, null);
                return (Logic.KWD_MOVE_DOWN);
              }
            }
          }
          else {
          }
        }
      }
      else {
        { Iterator iterator = ((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null)));
          Stella_Object backlinkedarg = null;
          int backlinkedargposition = -1;
          boolean nomatchesP = false;

          if (iterator == null) {
            { Object [] caller_MV_returnarray = new Object[1];

              backlinkedarg = Proposition.selectArgumentWithBacklinks(holdsproposition, caller_MV_returnarray);
              nomatchesP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[0])).wrapperValue));
            }
            if (backlinkedarg != null) {
              { int value000 = Stella.NULL_INTEGER;

                { int i = Stella.NULL_INTEGER;
                  IntegerIntervalIterator iter002 = Stella.interval(-1, Stella.NULL_INTEGER);
                  Stella_Object arg = null;
                  Vector vector000 = holdsarguments;
                  int index000 = 0;
                  int length000 = vector000.length();

                  loop002 : for (;iter002.nextP() &&
                            (index000 < length000); index000 = index000 + 1) {
                    i = iter002.value;
                    arg = (vector000.theArray)[index000];
                    if ((i >= 0) &&
                        Stella_Object.eqlP(backlinkedarg, Logic.argumentBoundTo(arg))) {
                      value000 = i;
                      break loop002;
                    }
                  }
                }
                backlinkedargposition = value000;
              }
              { Cons value001 = Stella.NIL;

                { Proposition prop = null;
                  Iterator iter003 = Logic.unfilteredDependentPropositions(backlinkedarg, null).allocateIterator();
                  Cons collect000 = null;

                  while (iter003.nextP()) {
                    prop = ((Proposition)(iter003.value));
                    if (((prop.kind == Logic.KWD_FUNCTION) ||
                        ((prop.kind == Logic.KWD_PREDICATE) ||
                         (prop.kind == Logic.KWD_ISA))) &&
                        ((prop.arguments.length() == holdsarity) &&
                         (Proposition.trueP(prop) &&
                          (prop.arguments.position(backlinkedarg, 0) == backlinkedargposition)))) {
                      if (collect000 == null) {
                        {
                          collect000 = Stella_Object.cons(prop, Stella.NIL);
                          if (value001 == Stella.NIL) {
                            value001 = collect000;
                          }
                          else {
                            Cons.addConsToEndOfConsList(value001, collect000);
                          }
                        }
                      }
                      else {
                        {
                          collect000.rest = Stella_Object.cons(prop, Stella.NIL);
                          collect000 = collect000.rest;
                        }
                      }
                    }
                  }
                }
                iterator = value001.allocateIterator();
              }
            }
            KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, iterator, null);
          }
          if (iterator != null) {
            { PatternRecord patternrecord = ((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentPatternRecord;
              int ubstackoffset = patternrecord.topUnbindingStackOffset;

              { Proposition prop = null;
                Iterator iter004 = ((Iterator)(iterator));

                loop004 : while (iter004.nextP()) {
                  prop = ((Proposition)(iter004.value));
                  if (!(PatternVariable.bindVariableToValueP(((PatternVariable)((holdsarguments.theArray)[0])), Logic.getDescription(((Surrogate)(prop.operator))), true))) {
                    continue loop004;
                  }
                  { boolean alwaysP000 = true;

                    { Stella_Object arg = null;
                      Vector vector001 = holdsarguments;
                      int index001 = 0;
                      int length001 = vector001.length();
                      int i = Stella.NULL_INTEGER;
                      int iter005 = -1;

                      loop005 : for (;index001 < length001; index001 = index001 + 1, iter005 = iter005 + 1) {
                        arg = (vector001.theArray)[index001];
                        i = iter005;
                        if (i >= 0) {
                          if (!Logic.bindArgumentToValueP(arg, (prop.arguments.theArray)[i], true)) {
                            alwaysP000 = false;
                            break loop005;
                          }
                        }
                      }
                    }
                    if (alwaysP000) {
                      return (Logic.KWD_CONTINUING_SUCCESS);
                    }
                  }
                  PatternRecord.unbindVariablesBeginningAt(patternrecord, ubstackoffset + 1);
                }
              }
            }
          }
        }
      }
      return (Logic.KWD_FAILURE);
    }
  }

  public static Keyword cutSpecialist(ControlFrame frame, Keyword lastmove) {
    lastmove = lastmove;
    if (((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null))) == null) {
      KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, Logic.EMPTY_PROPOSITIONS_ITERATOR, null);
      return (Logic.KWD_CONTINUING_SUCCESS);
    }
    else {
      { ControlFrame parentframe = frame.up;

        if ((parentframe == null) ||
            (!(parentframe.state == Logic.KWD_AND))) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        { Vector conjuncts = ((Vector)(KeyValueList.dynamicSlotValue(parentframe.dynamicSlots, Logic.SYM_STELLA_ARGUMENTS, null)));

          if (conjuncts != null) {
            { ControlFrame conjunct = null;
              Vector vector000 = conjuncts;
              int index000 = 0;
              int length000 = vector000.length();

              loop000 : for (;index000 < length000; index000 = index000 + 1) {
                conjunct = ((ControlFrame)((vector000.theArray)[index000]));
                if (conjunct == frame) {
                  break loop000;
                }
                else {
                  ControlFrame.popControlFrame(conjunct);
                }
              }
            }
          }
        }
        return (Logic.KWD_TERMINAL_FAILURE);
      }
    }
  }

  public static Keyword boundVariablesSpecialist(ControlFrame frame, Keyword lastmove) {
    { boolean alwaysP000 = true;

      { Stella_Object arg = null;
        Vector vector000 = frame.proposition.arguments;
        int index000 = 0;
        int length000 = vector000.length();

        loop000 : for (;index000 < length000; index000 = index000 + 1) {
          arg = (vector000.theArray)[index000];
          if (!(Logic.argumentBoundTo(arg) != null)) {
            alwaysP000 = false;
            break loop000;
          }
        }
      }
      { boolean allboundP = alwaysP000;

        lastmove = lastmove;
        return (Logic.selectTestResult(allboundP, true, frame));
      }
    }
  }

  public static Keyword forkSpecialist(ControlFrame frame, Keyword lastmove) {
    if (lastmove == Logic.KWD_DOWN) {
      return (Logic.KWD_MOVE_DOWN);
    }
    else if (lastmove == Logic.KWD_UP_TRUE) {
      if (frame.argumentCursor > 0) {
        return (Logic.KWD_CONTINUING_SUCCESS);
      }
      frame.down = null;
      frame.argumentCursor = 1;
      return (Logic.KWD_MOVE_DOWN);
    }
    else if (lastmove == Logic.KWD_UP_FAIL) {
      if (frame.argumentCursor > 0) {
        return (Logic.KWD_FAILURE);
      }
      frame.down = null;
      frame.argumentCursor = 2;
      return (Logic.KWD_MOVE_DOWN);
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + lastmove + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public static Keyword querySpecialist(ControlFrame frame, Keyword lastmove) {
    { QueryIterator subqueryiterator = ((QueryIterator)(((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null)))));
      boolean truefalsequeryP = false;
      boolean partialqueryP = false;
      boolean successP = false;
      ControlFrame result = null;

      lastmove = lastmove;
      if (subqueryiterator == null) {
        { Object [] caller_MV_returnarray = new Object[2];

          subqueryiterator = ControlFrame.createQuerySpecialistIterator(frame, caller_MV_returnarray);
          truefalsequeryP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[0])).wrapperValue));
          partialqueryP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[1])).wrapperValue));
        }
        if (subqueryiterator == null) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        else {
          KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, subqueryiterator, null);
        }
        if (partialqueryP) {
          if (truefalsequeryP) {
            Logic.callAskPartial(subqueryiterator);
          }
          else {
            Logic.callRetrievePartial(subqueryiterator);
          }
        }
      }
      else {
        partialqueryP = subqueryiterator.partialMatchStrategy != null;
      }
      if ((Stella.$TRACED_KEYWORDS$ != null) &&
          Stella.$TRACED_KEYWORDS$.membP(Logic.KWD_GOAL_TREE)) {
        System.out.println();
      }
      loop000 : for (;;) {
        if (partialqueryP) {
          successP = subqueryiterator.querySucceededP();
          if (successP) {
            { QuerySolution solution = subqueryiterator.solutions.pop();

              result = subqueryiterator.baseControlFrame;
              if (!(truefalsequeryP)) {
                subqueryiterator.value = solution;
              }
              result.truthValue = solution.truthValue;
              if (((Boolean)(Logic.$RECORD_JUSTIFICATIONSp$.get())).booleanValue()) {
                KeyValueList.setDynamicSlotValue(result.dynamicSlots, Logic.SYM_LOGIC_JUSTIFICATION, solution.justification, null);
              }
              result.partialMatchFrame.positiveScore = solution.matchScore;
            }
          }
        }
        else {
          { Object old$Queryiterator$000 = Logic.$QUERYITERATOR$.get();
            Object old$ReversepolarityP$000 = Logic.$REVERSEPOLARITYp$.get();
            Object old$Inferencelevel$000 = Logic.$INFERENCELEVEL$.get();
            Object old$GenerateAllProofsP$000 = Logic.$GENERATE_ALL_PROOFSp$.get();

            try {
              Native.setSpecial(Logic.$QUERYITERATOR$, subqueryiterator);
              Native.setBooleanSpecial(Logic.$REVERSEPOLARITYp$, frame.reversePolarityP);
              Native.setSpecial(Logic.$INFERENCELEVEL$, Logic.currentInferenceLevel());
              Native.setBooleanSpecial(Logic.$GENERATE_ALL_PROOFSp$, false);
              { int howmany = Logic.lookupHowManySolutions(subqueryiterator);

                if ((howmany == Stella.NULL_INTEGER) ||
                    (howmany >= 1)) {
                  successP = subqueryiterator.nextP();
                }
                if (howmany == Stella.NULL_INTEGER) {
                }
                else if (howmany <= 1) {
                  subqueryiterator.exhaustedP = true;
                }
                else {
                  subqueryiterator.options.insertAt(Logic.KWD_HOW_MANY, IntegerWrapper.wrapInteger(howmany - 1));
                }
                if (successP) {
                  result = subqueryiterator.baseControlFrame;
                }
              }

            } finally {
              Logic.$GENERATE_ALL_PROOFSp$.set(old$GenerateAllProofsP$000);
              Logic.$INFERENCELEVEL$.set(old$Inferencelevel$000);
              Logic.$REVERSEPOLARITYp$.set(old$ReversepolarityP$000);
              Logic.$QUERYITERATOR$.set(old$Queryiterator$000);
            }
          }
        }
        if (successP) {
          { Stella_Object var = null;
            Cons iter000 = frame.querySpecialistIoVariables().theConsList;
            Stella_Object value = null;
            Vector vector000 = ((QuerySolution)(subqueryiterator.value)).bindings;
            int index000 = 0;
            int length000 = vector000.length();

            loop001 : for (;(!(iter000 == Stella.NIL)) &&
                      (index000 < length000); iter000 = iter000.rest, index000 = index000 + 1) {
              var = iter000.value;
              value = (vector000.theArray)[index000];
              if (!(PatternVariable.bindVariableToValueP(((PatternVariable)(var)), value, true))) {
                successP = false;
                break loop001;
              }
            }
          }
          if ((!successP) &&
              (!truefalsequeryP)) {
            continue loop000;
          }
        }
        break loop000;
      }
      if ((Stella.$TRACED_KEYWORDS$ != null) &&
          Stella.$TRACED_KEYWORDS$.membP(Logic.KWD_GOAL_TREE)) {
        System.out.println();
      }
      if (successP) {
        ControlFrame.propagateFrameTruthValue(result, frame);
        if (((((QueryIterator)(Logic.$QUERYITERATOR$.get())) != null) &&
            (((QueryIterator)(Logic.$QUERYITERATOR$.get())).partialMatchStrategy != null)) &&
            partialqueryP) {
          result.partialMatchFrame.propagateFramePartialTruth(frame);
        }
        if (((Boolean)(Logic.$RECORD_JUSTIFICATIONSp$.get())).booleanValue()) {
          ControlFrame.recordGoalJustification(frame, ((Justification)(KeyValueList.dynamicSlotValue(result.dynamicSlots, Logic.SYM_LOGIC_JUSTIFICATION, null))));
        }
        if (truefalsequeryP) {
          return (Logic.KWD_FINAL_SUCCESS);
        }
        else {
          return (Logic.KWD_CONTINUING_SUCCESS);
        }
      }
      else {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
    }
  }

  public static Keyword conceptPrototypeSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Description renamed_Class = ((Description)(Logic.argumentBoundTo((proposition.arguments.theArray)[0])));
      Stella_Object prototypeargument = (proposition.arguments.theArray)[1];
      LogicObject prototype = null;

      lastmove = lastmove;
      if ((renamed_Class == null) ||
          (!Stella_Object.isaP(renamed_Class, Logic.SGT_LOGIC_DESCRIPTION))) {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      prototype = ((LogicObject)(Logic.accessBinaryValue(renamed_Class, Logic.SGT_PL_KERNEL_KB_CONCEPT_PROTOTYPE)));
      if (prototype == null) {
        { Object old$Context$000 = Stella.$CONTEXT$.get();
          Object old$Module$000 = Stella.$MODULE$.get();

          try {
            Native.setSpecial(Stella.$CONTEXT$, renamed_Class.homeContext);
            Native.setSpecial(Stella.$MODULE$, ((Context)(Stella.$CONTEXT$.get())).baseModule);
            prototype = Logic.createHypothesizedInstance((Stella_Object.isaP(renamed_Class, Logic.SGT_LOGIC_NAMED_DESCRIPTION) ? ("proto-" + renamed_Class.descriptionName().symbolName) : "prototype"));
            { Object old$InvisibleassertionP$000 = Logic.$INVISIBLEASSERTIONp$.get();

              try {
                Native.setBooleanSpecial(Logic.$INVISIBLEASSERTIONp$, true);
                Logic.assertMemberOfProposition(prototype, renamed_Class);
                Logic.assertBinaryValue(Logic.SGT_PL_KERNEL_KB_CONCEPT_PROTOTYPE, renamed_Class, prototype);

              } finally {
                Logic.$INVISIBLEASSERTIONp$.set(old$InvisibleassertionP$000);
              }
            }

          } finally {
            Stella.$MODULE$.set(old$Module$000);
            Stella.$CONTEXT$.set(old$Context$000);
          }
        }
      }
      return (Logic.selectProofResult(Logic.bindArgumentToValueP(prototypeargument, prototype, true), false, true));
    }
  }

  public static Keyword closedSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object argvalue = Logic.argumentBoundTo((proposition.arguments.theArray)[0]);
      boolean closedP = Logic.closedTermP(argvalue);

      lastmove = lastmove;
      if (argvalue == null) {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      if (((Boolean)(Logic.$REVERSEPOLARITYp$.get())).booleanValue()) {
        closedP = !closedP;
      }
      return (Logic.selectProofResult(closedP, false, true));
    }
  }

  public static Keyword singleValuedSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object argvalue = Logic.argumentBoundTo((proposition.arguments.theArray)[0]);
      boolean singlevaluedP = Logic.singleValuedTermP(argvalue);

      lastmove = lastmove;
      if (argvalue == null) {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      if (((Boolean)(Logic.$REVERSEPOLARITYp$.get())).booleanValue()) {
        singlevaluedP = !singlevaluedP;
      }
      if (singlevaluedP) {
        return (Logic.KWD_FINAL_SUCCESS);
      }
      else {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
    }
  }

  public static Keyword collectIntoSetSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object collectionarg = (proposition.arguments.theArray)[0];
      Stella_Object collectionvalue = Logic.argumentBoundTo(collectionarg);
      Stella_Object listarg = (proposition.arguments.theArray)[1];

      lastmove = lastmove;
      if (collectionvalue == null) {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      if (((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null))) == null) {
        if (Logic.enumeratedSetP(collectionvalue) &&
            (((LogicObject)(collectionvalue)).variableValueInverse() == Stella.NIL)) {
          Logic.bindArgumentToValueP(listarg, collectionvalue, true);
          return (Logic.KWD_FINAL_SUCCESS);
        }
        { Surrogate testValue000 = Stella_Object.safePrimaryType(collectionvalue);

          if (Surrogate.subtypeOfP(testValue000, Logic.SGT_STELLA_COLLECTION)) {
            { Collection collectionvalue000 = ((Collection)(collectionvalue));

              { List members = Logic.assertedCollectionMembers(collectionvalue000, false);

                if (members == null) {
                  return (Logic.KWD_TERMINAL_FAILURE);
                }
                Logic.bindArgumentToValueP(listarg, Logic.createEnumeratedSet(members), true);
                return (Logic.KWD_FINAL_SUCCESS);
              }
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_SKOLEM)) {
            { Skolem collectionvalue000 = ((Skolem)(collectionvalue));

              { List members = Logic.assertedCollectionMembers(collectionvalue000, false);

                if (members == null) {
                  return (Logic.KWD_TERMINAL_FAILURE);
                }
                Logic.bindArgumentToValueP(listarg, Logic.createEnumeratedSet(members), true);
                return (Logic.KWD_FINAL_SUCCESS);
              }
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_DESCRIPTION)) {
            { Description collectionvalue000 = ((Description)(collectionvalue));

              { boolean testValue001 = false;

                testValue001 = ((Vector)(KeyValueList.dynamicSlotValue(collectionvalue000.dynamicSlots, Logic.SYM_LOGIC_EXTERNAL_VARIABLES, null))) != null;
                if (testValue001) {
                  { boolean foundP000 = false;

                    { PatternVariable v = null;
                      Vector vector000 = ((Vector)(KeyValueList.dynamicSlotValue(collectionvalue000.dynamicSlots, Logic.SYM_LOGIC_EXTERNAL_VARIABLES, null)));
                      int index000 = 0;
                      int length000 = vector000.length();

                      loop000 : for (;index000 < length000; index000 = index000 + 1) {
                        v = ((PatternVariable)((vector000.theArray)[index000]));
                        if (!(Logic.argumentBoundTo(v) != null)) {
                          foundP000 = true;
                          break loop000;
                        }
                      }
                    }
                    testValue001 = foundP000;
                  }
                }
                if (testValue001) {
                  return (Logic.KWD_TERMINAL_FAILURE);
                }
              }
              if (Description.inferableP(collectionvalue000)) {
                {
                  ControlFrame.createCollectDescriptionExtensionFrame(frame, collectionvalue000);
                  KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, Logic.EMPTY_PROPOSITIONS_ITERATOR, null);
                  return (Logic.KWD_MOVE_DOWN);
                }
              }
              else {
                { List members = Logic.assertedCollectionMembers(collectionvalue000, false);

                  if (members == null) {
                    return (Logic.KWD_TERMINAL_FAILURE);
                  }
                  Logic.bindArgumentToValueP(listarg, Logic.createEnumeratedSet(members), true);
                  return (Logic.KWD_FINAL_SUCCESS);
                }
              }
            }
          }
          else {
            return (Logic.KWD_FAILURE);
          }
        }
      }
      if (frame.down == null) {
        return (Logic.KWD_FAILURE);
      }
      { List list = frame.down.patternRecord.collectionList;

        ControlFrame.popFramesUpTo(frame.down);
        list.removeDuplicates();
        Logic.bindArgumentToValueP(listarg, Logic.createEnumeratedSet(list), true);
        return (Logic.KWD_FINAL_SUCCESS);
      }
    }
  }

  public static Keyword lengthOfListSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object listarg = (proposition.arguments.theArray)[0];
      Stella_Object listskolem = Logic.argumentBoundTo(listarg);
      Stella_Object lengtharg = (proposition.arguments.theArray)[1];

      lastmove = lastmove;
      if ((listskolem != null) &&
          (!Logic.logicalCollectionP(listskolem))) {
        {
          System.out.println();
          System.out.println("Non list appears in second argument to 'LENGTH-OF-LIST'");
          System.out.println();
        }
;
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      { List listvalue = Logic.assertedCollectionMembers(listskolem, true);
        int len = Stella.NULL_INTEGER;

        if (listvalue == null) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        len = ((List)(listvalue)).length();
        return (Logic.selectTestResult(Logic.bindArgumentToValueP(lengtharg, IntegerWrapper.wrapInteger(len), true), true, frame));
      }
    }
  }

  public static Keyword minimumOfNumbersSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object listarg = (proposition.arguments.theArray)[0];
      Stella_Object listskolem = Logic.argumentBoundTo(listarg);
      Stella_Object minarg = (proposition.arguments.theArray)[1];
      Stella_Object minvalue = Logic.argumentBoundTo(minarg);
      NumberWrapper minimum = null;
      boolean missingnumbersP = false;

      lastmove = lastmove;
      if ((listskolem != null) &&
          (!Logic.logicalCollectionP(listskolem))) {
        {
          System.out.println();
          System.out.println("Non list appears in second argument to 'MINIMUM-OF-NUMBERS'");
          System.out.println();
        }
;
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      { List listvalue = Logic.assertedCollectionMembers(listskolem, true);

        if (listvalue.emptyP()) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        { Stella_Object v = null;
          Cons iter000 = listvalue.theConsList;

          for (;!(iter000 == Stella.NIL); iter000 = iter000.rest) {
            v = iter000.value;
            if (Stella_Object.isaP(v, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
              if ((minimum == null) ||
                  PlKernelKb.arithmeticLessTest(((NumberWrapper)(v)), minimum)) {
                minimum = ((NumberWrapper)(v));
              }
            }
            else {
              missingnumbersP = true;
            }
          }
        }
        if (minimum == null) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        if (missingnumbersP) {
          if ((minvalue != null) &&
              (Stella_Object.isaP(minvalue, Logic.SGT_STELLA_NUMBER_WRAPPER) &&
               PlKernelKb.arithmeticGreaterTest(((NumberWrapper)(minvalue)), minimum))) {
            {
              ControlFrame.setFrameTruthValue(frame, Logic.FALSE_TRUTH_VALUE);
              return (Logic.KWD_TERMINAL_FAILURE);
            }
          }
          else {
            {
              ControlFrame.setFrameTruthValue(frame, Logic.UNKNOWN_TRUTH_VALUE);
              return (Logic.KWD_FAILURE);
            }
          }
        }
        return (Logic.selectTestResult(Logic.bindArgumentToValueP(minarg, minimum, true), true, frame));
      }
    }
  }

  public static Keyword maximumOfNumbersSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object listarg = (proposition.arguments.theArray)[0];
      Stella_Object listskolem = Logic.argumentBoundTo(listarg);
      Stella_Object maxarg = (proposition.arguments.theArray)[1];
      Stella_Object maxvalue = Logic.argumentBoundTo(maxarg);
      NumberWrapper maximum = null;
      boolean missingnumbersP = false;

      lastmove = lastmove;
      if ((listskolem != null) &&
          (!Logic.logicalCollectionP(listskolem))) {
        {
          System.out.println();
          System.out.println("Non list appears in second argument to 'MAXIMUM-OF-NUMBERS'");
          System.out.println();
        }
;
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      { List listvalue = Logic.assertedCollectionMembers(listskolem, true);

        if (listvalue.emptyP()) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        { Stella_Object v = null;
          Cons iter000 = listvalue.theConsList;

          for (;!(iter000 == Stella.NIL); iter000 = iter000.rest) {
            v = iter000.value;
            if (Stella_Object.isaP(v, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
              if ((maximum == null) ||
                  PlKernelKb.arithmeticGreaterTest(((NumberWrapper)(v)), maximum)) {
                maximum = ((NumberWrapper)(v));
              }
            }
            else {
              missingnumbersP = true;
            }
          }
        }
        if (maximum == null) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        if (missingnumbersP) {
          if ((maxvalue != null) &&
              (Stella_Object.isaP(maxvalue, Logic.SGT_STELLA_NUMBER_WRAPPER) &&
               PlKernelKb.arithmeticLessTest(((NumberWrapper)(maxvalue)), maximum))) {
            {
              ControlFrame.setFrameTruthValue(frame, Logic.FALSE_TRUTH_VALUE);
              return (Logic.KWD_TERMINAL_FAILURE);
            }
          }
          else {
            {
              ControlFrame.setFrameTruthValue(frame, Logic.UNKNOWN_TRUTH_VALUE);
              return (Logic.KWD_FAILURE);
            }
          }
        }
        return (Logic.selectTestResult(Logic.bindArgumentToValueP(maxarg, maximum, true), true, frame));
      }
    }
  }

  public static Keyword sumOfNumbersSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object listarg = (proposition.arguments.theArray)[0];
      Stella_Object listskolem = Logic.argumentBoundTo(listarg);
      Stella_Object sumarg = (proposition.arguments.theArray)[1];
      NumberWrapper sum = null;

      lastmove = lastmove;
      if ((listskolem != null) &&
          (!Logic.logicalCollectionP(listskolem))) {
        {
          System.out.println();
          System.out.println("Non list appears in second argument to 'SUM-OF-NUMBERS'");
          System.out.println();
        }
;
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      { List listvalue = Logic.assertedCollectionMembers(listskolem, true);

        if (listvalue.emptyP()) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        { Stella_Object v = null;
          Cons iter000 = listvalue.theConsList;

          for (;!(iter000 == Stella.NIL); iter000 = iter000.rest) {
            v = iter000.value;
            if (Stella_Object.isaP(v, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
              if (sum == null) {
                sum = ((NumberWrapper)(v));
              }
              else {
                sum = PlKernelKb.plusComputation(((NumberWrapper)(v)), sum);
              }
            }
            else {
              return (Logic.KWD_FAILURE);
            }
          }
        }
        if (sum == null) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        return (Logic.selectTestResult(Logic.bindArgumentToValueP(sumarg, sum, true), true, frame));
      }
    }
  }

  public static Keyword meanOfNumbersSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object listarg = (proposition.arguments.theArray)[0];
      Stella_Object listskolem = Logic.argumentBoundTo(listarg);
      Stella_Object meanarg = (proposition.arguments.theArray)[1];
      NumberWrapper sum = IntegerWrapper.wrapInteger(0);
      int numbercount = 0;

      lastmove = lastmove;
      if ((listskolem != null) &&
          (!Logic.logicalCollectionP(listskolem))) {
        {
          System.out.println();
          System.out.println("Non list appears in second argument to 'MEAN-OF-NUMBERS'");
          System.out.println();
        }
;
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      { List listvalue = Logic.assertedCollectionMembers(listskolem, true);

        if (listvalue.emptyP()) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        { Stella_Object v = null;
          Cons iter000 = listvalue.theConsList;

          for (;!(iter000 == Stella.NIL); iter000 = iter000.rest) {
            v = iter000.value;
            if (Stella_Object.isaP(v, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
              {
                sum = PlKernelKb.plusComputation(((NumberWrapper)(v)), sum);
                numbercount = numbercount + 1;
              }
            }
            else {
              return (Logic.KWD_FAILURE);
            }
          }
        }
        if (numbercount == 0) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        else {
          return (Logic.selectTestResult(Logic.bindArgumentToValueP(meanarg, PlKernelKb.divideComputation(sum, IntegerWrapper.wrapInteger(numbercount)), true), true, frame));
        }
      }
    }
  }

  public static Keyword medianOfNumbersSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object listarg = (proposition.arguments.theArray)[0];
      List sortlist = List.newList();
      Stella_Object listskolem = Logic.argumentBoundTo(listarg);
      Stella_Object medianarg = (proposition.arguments.theArray)[1];
      int numbercount = 0;
      NumberWrapper result = null;

      lastmove = lastmove;
      if ((listskolem != null) &&
          (!Logic.logicalCollectionP(listskolem))) {
        {
          System.out.println();
          System.out.println("Non list appears in second argument to 'MEDIAN-OF-NUMBERS'");
          System.out.println();
        }
;
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      { List listvalue = Logic.assertedCollectionMembers(listskolem, true);

        if (listvalue.emptyP()) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        { Stella_Object v = null;
          Cons iter000 = listvalue.theConsList;

          for (;!(iter000 == Stella.NIL); iter000 = iter000.rest) {
            v = iter000.value;
            if (Stella_Object.isaP(v, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
              sortlist.push(((NumberWrapper)(v)));
            }
            else {
              return (Logic.KWD_FAILURE);
            }
          }
        }
        numbercount = sortlist.length();
        if (numbercount == 0) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        sortlist.sort(Native.find_java_method("edu.isi.powerloom.pl_kernel_kb.PlKernelKb", "arithmeticLessTest", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.NumberWrapper"), Native.find_java_class("edu.isi.stella.NumberWrapper")}));
        if (((numbercount % 2) == 1)) {
          result = ((NumberWrapper)(sortlist.nth(((int)((numbercount - 1) / 2.0)))));
        }
        else {
          result = PlKernelKb.divideComputation(PlKernelKb.plusComputation(((NumberWrapper)(sortlist.nth(((int)((numbercount / 2.0) - 1))))), ((NumberWrapper)(sortlist.nth(((int)(numbercount / 2.0)))))), IntegerWrapper.wrapInteger(2));
        }
        return (Logic.selectTestResult(Logic.bindArgumentToValueP(medianarg, result, true), true, frame));
      }
    }
  }

  public static Keyword standardDeviationSpecialist(ControlFrame frame, Keyword lastmove) {
    return (ControlFrame.computeVarianceOrStandardDeviation(frame, lastmove, true));
  }

  public static Keyword varianceSpecialist(ControlFrame frame, Keyword lastmove) {
    return (ControlFrame.computeVarianceOrStandardDeviation(frame, lastmove, false));
  }

  public static Keyword hasPartitionMembershipSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object argumentvalue = Logic.argumentBoundTo((proposition.arguments.theArray)[0]);

      lastmove = lastmove;
      if ((argumentvalue == null) ||
          (!Stella_Object.isaP(argumentvalue, Logic.SGT_LOGIC_LOGIC_OBJECT))) {
        return (Logic.KWD_FAILURE);
      }
      { Proposition value000 = null;

        { Proposition p = null;
          Iterator iter000 = Logic.unfilteredDependentPropositions(argumentvalue, Logic.SGT_PL_KERNEL_KB_HAS_PARTITION_MEMBERSHIP).allocateIterator();

          loop000 : while (iter000.nextP()) {
            p = ((Proposition)(iter000.value));
            if (((Surrogate)(p.operator)) == Logic.SGT_PL_KERNEL_KB_HAS_PARTITION_MEMBERSHIP) {
              value000 = p;
              break loop000;
            }
          }
        }
        { Proposition haspartitionproposition = value000;

          if (haspartitionproposition != null) {
            if (Proposition.trueP(haspartitionproposition)) {
              return (Logic.KWD_FINAL_SUCCESS);
            }
            else if (Proposition.falseP(haspartitionproposition)) {
              return (Logic.KWD_TERMINAL_FAILURE);
            }
          }
          if (LogicObject.derivePartitionMembershipsP(((LogicObject)(argumentvalue)))) {
            {
              LogicObject.updateProperty(((LogicObject)(argumentvalue)), Logic.SGT_PL_KERNEL_KB_HAS_PARTITION_MEMBERSHIP, Logic.KWD_ASSERT_TRUE);
              return (Logic.KWD_FINAL_SUCCESS);
            }
          }
          else {
            {
              LogicObject.updateProperty(((LogicObject)(argumentvalue)), Logic.SGT_PL_KERNEL_KB_HAS_PARTITION_MEMBERSHIP, Logic.KWD_ASSERT_FALSE);
              return (Logic.KWD_TERMINAL_FAILURE);
            }
          }
        }
      }
    }
  }

  public static Keyword refutationDisjointSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Description class1 = ((Description)(Logic.argumentBoundTo((proposition.arguments.theArray)[0])));
      Description class2 = ((Description)(Logic.argumentBoundTo((proposition.arguments.theArray)[1])));

      lastmove = lastmove;
      if ((class1 == null) ||
          ((class2 == null) ||
           (proposition.arguments.length() > 2))) {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      Logic.pushMonotonicWorld();
      Logic.initializeInferenceWorld(((World)(((Context)(Stella.$CONTEXT$.get())))));
      try {
        { LogicObject skolem = Logic.createHypothesizedInstance("refutation-disjoint");

          { Description c = null;
            Cons iter000 = ((Cons)(Stella.consList(Stella_Object.cons(class1, Stella_Object.cons(class2, Stella.NIL)))));

            for (;!(iter000 == Stella.NIL); iter000 = iter000.rest) {
              c = ((Description)(iter000.value));
              Logic.assertMemberOfProposition(skolem, c);
            }
          }
          Logic.elaborateInstance(skolem);
        }
      } catch (Clash e000) {
        Stella.popWorld();
        return (Logic.KWD_FINAL_SUCCESS);
      }
      Stella.popWorld();
      return (Logic.KWD_FAILURE);
    }
  }

  public static Keyword emptySpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object argvalue = Logic.argumentBoundTo((proposition.arguments.theArray)[0]);
      boolean emptyP = Logic.emptyTermP(argvalue);

      lastmove = lastmove;
      return (Logic.selectProofResult(emptyP, false, true));
    }
  }

  public static Context contextOfComputation(Stella_Object instance) {
    return (instance.homeModule());
  }

  public static Keyword istSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object contextvalue = Logic.argumentBoundTo((proposition.arguments.theArray)[0]);
      Stella_Object propositionvalue = Logic.argumentBoundTo((proposition.arguments.theArray)[1]);
      SavedContextProofAdjunct adjunct = ((SavedContextProofAdjunct)(((ProofAdjunct)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_LOGIC_PROOF_ADJUNCT, null)))));

      if (lastmove == Logic.KWD_DOWN) {
        if ((contextvalue == null) ||
            ((propositionvalue == null) ||
             (!Stella_Object.isaP(contextvalue, Logic.SGT_STELLA_CONTEXT)))) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        { SavedContextProofAdjunct self001 = SavedContextProofAdjunct.newSavedContextProofAdjunct();

          self001.savedContext = ((Context)(Stella.$CONTEXT$.get()));
          KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_LOGIC_PROOF_ADJUNCT, self001, null);
        }
        ((Context)(contextvalue)).changeContext();
        frame.argumentCursor = 1;
        return (Logic.KWD_MOVE_DOWN);
      }
      else if (lastmove == Logic.KWD_UP_TRUE) {
        ControlFrame.propagateFrameTruthValue(frame.result, frame);
        if ((((QueryIterator)(Logic.$QUERYITERATOR$.get())) != null) &&
            (((QueryIterator)(Logic.$QUERYITERATOR$.get())).partialMatchStrategy != null)) {
          frame.result.partialMatchFrame.propagateFramePartialTruth(frame);
        }
        if (((Boolean)(Logic.$RECORD_JUSTIFICATIONSp$.get())).booleanValue()) {
          { Justification self002 = Justification.newJustification();

            self002.inferenceRule = Logic.KWD_IST_INTRODUCTION;
            self002.antecedents = Stella_Object.cons(((Justification)(KeyValueList.dynamicSlotValue(frame.result.dynamicSlots, Logic.SYM_LOGIC_JUSTIFICATION, null))), Stella.NIL);
            ControlFrame.recordGoalJustification(frame, self002);
          }
        }
        adjunct.savedContext.changeContext();
        if (frame.down != null) {
          return (Logic.KWD_CONTINUING_SUCCESS);
        }
        else {
          return (Logic.KWD_FINAL_SUCCESS);
        }
      }
      else if (lastmove == Logic.KWD_UP_FAIL) {
        ControlFrame.propagateFrameTruthValue(frame.result, frame);
        if ((((QueryIterator)(Logic.$QUERYITERATOR$.get())) != null) &&
            (((QueryIterator)(Logic.$QUERYITERATOR$.get())).partialMatchStrategy != null)) {
          frame.result.partialMatchFrame.propagateFramePartialTruth(frame);
        }
        if (((Boolean)(Logic.$RECORD_JUSTIFICATIONSp$.get())).booleanValue()) {
          ControlFrame.recordPrimitiveJustification(frame, Logic.KWD_UP_FAIL);
        }
        adjunct.savedContext.changeContext();
        return (Logic.KWD_FAILURE);
      }
      else {
        { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

          stream000.nativeStream.print("`" + lastmove + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public static Keyword rangeMinCardinalitySpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object relation = Logic.argumentBoundTo((proposition.arguments.theArray)[0]);
      Stella_Object instance = Logic.argumentBoundTo((proposition.arguments.theArray)[1]);
      Stella_Object mincardarg = (proposition.arguments.theArray)[2];
      Stella_Object mincardvalue = Logic.argumentBoundTo(mincardarg);
      int computedvalue = Stella.NULL_INTEGER;

      lastmove = lastmove;
      if (!Logic.$ACCELERATE_FRAME_COMPUTATIONSp$) {
        return (Logic.KWD_FAILURE);
      }
      if ((relation == null) ||
          (instance == null)) {
        return (Logic.KWD_FAILURE);
      }
      { boolean testValue000 = false;

        testValue000 = Stella_Object.isaP(relation, Logic.SGT_LOGIC_NAMED_DESCRIPTION);
        if (testValue000) {
          { 
            computedvalue = NamedDescription.computeMinimumCardinality(((NamedDescription)(relation)), instance);
            testValue000 = computedvalue != Stella.NULL_INTEGER;
          }
        }
        if (testValue000) {
          { TruthValue tv = Logic.UNKNOWN_TRUTH_VALUE;

            if ((mincardvalue != null) &&
                Stella_Object.isaP(mincardvalue, Logic.SGT_STELLA_INTEGER_WRAPPER)) {
              if (computedvalue >= ((NumberWrapper)(mincardvalue)).numberWrapperToFloat()) {
                {
                  tv = Logic.TRUE_TRUTH_VALUE;
                }
              }
              else {
                if (Logic.closedTermP(relation)) {
                  {
                    tv = Logic.FALSE_TRUTH_VALUE;
                  }
                }
                else {
                  { boolean testValue001 = false;

                    { 
                      computedvalue = NamedDescription.computeMaximumCardinality(((NamedDescription)(relation)), instance);
                      testValue001 = computedvalue != Stella.NULL_INTEGER;
                    }
                    if (testValue001) {
                      testValue001 = computedvalue < ((NumberWrapper)(mincardvalue)).numberWrapperToFloat();
                    }
                    if (testValue001) {
                      tv = Logic.FALSE_TRUTH_VALUE;
                    }
                  }
                }
              }
            }
            else {
              if (Logic.bindArgumentToValueP(mincardarg, IntegerWrapper.wrapInteger(computedvalue), true)) {
                tv = Logic.TRUE_TRUTH_VALUE;
              }
              else {
                tv = Logic.FALSE_TRUTH_VALUE;
              }
            }
            if (((Boolean)(Logic.$REVERSEPOLARITYp$.get())).booleanValue()) {
              tv = TruthValue.invertTruthValue(tv);
            }
            ControlFrame.setFrameTruthValue(frame, tv);
            if ((tv == Logic.TRUE_TRUTH_VALUE) ||
                (tv == Logic.DEFAULT_TRUE_TRUTH_VALUE)) {
              return (Logic.KWD_FINAL_SUCCESS);
            }
            else if ((tv == Logic.FALSE_TRUTH_VALUE) ||
                (tv == Logic.DEFAULT_FALSE_TRUTH_VALUE)) {
              return (Logic.KWD_FAILURE);
            }
            else {
              return (Logic.KWD_FAILURE);
            }
          }
        }
        else {
          return (Logic.KWD_FAILURE);
        }
      }
    }
  }

  public static Keyword rangeMaxCardinalitySpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object relation = Logic.argumentBoundTo((proposition.arguments.theArray)[0]);
      Stella_Object instance = Logic.argumentBoundTo((proposition.arguments.theArray)[1]);
      Stella_Object maxcardarg = (proposition.arguments.theArray)[2];
      Stella_Object maxcardvalue = Logic.argumentBoundTo(maxcardarg);
      int computedvalue = Stella.NULL_INTEGER;

      lastmove = lastmove;
      if (!Logic.$ACCELERATE_FRAME_COMPUTATIONSp$) {
        return (Logic.KWD_FAILURE);
      }
      if ((relation == null) ||
          (instance == null)) {
        return (Logic.KWD_FAILURE);
      }
      { boolean testValue000 = false;

        testValue000 = Stella_Object.isaP(relation, Logic.SGT_LOGIC_NAMED_DESCRIPTION);
        if (testValue000) {
          { 
            computedvalue = NamedDescription.computeMaximumCardinality(((NamedDescription)(relation)), instance);
            testValue000 = computedvalue != Stella.NULL_INTEGER;
          }
        }
        if (testValue000) {
          { boolean successP = (((maxcardvalue != null) &&
                Stella_Object.isaP(maxcardvalue, Logic.SGT_STELLA_INTEGER_WRAPPER)) ? (computedvalue <= ((NumberWrapper)(maxcardvalue)).numberWrapperToFloat()) : Logic.bindArgumentToValueP(maxcardarg, IntegerWrapper.wrapInteger(computedvalue), true));

            return (Logic.selectTestResult(successP, true, frame));
          }
        }
        else {
          { boolean testValue001 = false;

            testValue001 = maxcardvalue != null;
            if (testValue001) {
              testValue001 = Stella_Object.isaP(maxcardvalue, Logic.SGT_STELLA_INTEGER_WRAPPER);
              if (testValue001) {
                { 
                  computedvalue = NamedDescription.computeMinimumCardinality(((NamedDescription)(relation)), instance);
                  testValue001 = computedvalue != Stella.NULL_INTEGER;
                }
                if (testValue001) {
                  testValue001 = computedvalue > ((NumberWrapper)(maxcardvalue)).numberWrapperToFloat();
                }
              }
            }
            if (testValue001) {
              return (Logic.selectTestResult(false, true, frame));
            }
            else {
              return (Logic.KWD_FAILURE);
            }
          }
        }
      }
    }
  }

  public static Keyword rangeTypeSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object relation = Logic.argumentBoundTo((proposition.arguments.theArray)[0]);
      Stella_Object instance = Logic.argumentBoundTo((proposition.arguments.theArray)[1]);
      Stella_Object valuetypearg = (proposition.arguments.theArray)[2];
      Stella_Object valuetypevalue = Logic.argumentBoundTo(valuetypearg);

      lastmove = lastmove;
      if (!Logic.$ACCELERATE_FRAME_COMPUTATIONSp$) {
        return (Logic.KWD_FAILURE);
      }
      if ((relation == null) ||
          (instance == null)) {
        return (Logic.KWD_FAILURE);
      }
      if (valuetypevalue == null) {
        return (Logic.KWD_FAILURE);
      }
      if (Stella_Object.isaP(valuetypevalue, Logic.SGT_STELLA_SURROGATE)) {
        valuetypevalue = Logic.surrogateToDescription(((Surrogate)(valuetypevalue)));
      }
      if ((!Stella_Object.isaP(relation, Logic.SGT_LOGIC_NAMED_DESCRIPTION)) ||
          ((!Stella_Object.isaP(valuetypevalue, Logic.SGT_LOGIC_NAMED_DESCRIPTION)) ||
           (valuetypevalue == null))) {
        return (Logic.KWD_FAILURE);
      }
      if (NamedDescription.testRangeTypeP(((NamedDescription)(relation)), instance, ((NamedDescription)(valuetypevalue)))) {
        return (Logic.selectTestResult(true, true, frame));
      }
      else {
        return (Logic.KWD_FAILURE);
      }
    }
  }

  public static Keyword reflexiveRelationSpecialist(ControlFrame frame, Keyword lastmove) {
    lastmove = lastmove;
    { Proposition proposition = frame.proposition;
      Stella_Object arg1 = Logic.argumentBoundTo((proposition.arguments.theArray)[0]);
      Stella_Object arg2 = Logic.argumentBoundTo((proposition.arguments.theArray)[1]);

      if (Stella_Object.eqlP(arg1, arg2) ||
          Stella_Object.eqlP(Logic.argumentBoundTo(arg1), Logic.argumentBoundTo(arg2))) {
        return (Logic.selectTestResult(true, true, frame));
      }
      else {
        return (Logic.KWD_FAILURE);
      }
    }
  }

  public static Keyword irreflexiveRelationSpecialist(ControlFrame frame, Keyword lastmove) {
    lastmove = lastmove;
    { Proposition proposition = frame.proposition;
      Stella_Object arg1 = Logic.argumentBoundTo((proposition.arguments.theArray)[0]);
      Stella_Object arg2 = Logic.argumentBoundTo((proposition.arguments.theArray)[1]);

      if (Stella_Object.eqlP(arg1, arg2) ||
          Stella_Object.eqlP(Logic.argumentBoundTo(arg1), Logic.argumentBoundTo(arg2))) {
        return (Logic.selectTestResult(false, true, frame));
      }
      else {
        return (Logic.KWD_FAILURE);
      }
    }
  }

  public static StringWrapper objectNameComputation(Stella_Object objectarg) {
    { String nameString = Logic.objectNameString(Logic.valueOf(objectarg));

      if (nameString == null) {
        return (null);
      }
      else {
        return (StringWrapper.wrapString(nameString));
      }
    }
  }

  public static Stella_Object nameToObjectComputation(StringWrapper namearg) {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, ((Context)(Stella.$CONTEXT$.get())).baseModule);
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        { Stella_Object temp000 = Logic.getInstance(namearg);

          { Stella_Object value000 = ((temp000 != null) ? temp000 : Logic.createLogicInstance(Stella.internSurrogateInModule(namearg.wrapperValue, ((Module)(Stella.$MODULE$.get())), true), null));

            return (value000);
          }
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

  public static IntegerWrapper arityComputation(Stella_Object descriptionarg) {
    { Stella_Object description = Logic.valueOf(descriptionarg);

      if (description != null) {
        if (Surrogate.subtypeOfP(Stella_Object.safePrimaryType(description), Logic.SGT_LOGIC_DESCRIPTION)) {
          { Description description000 = ((Description)(description));

            return (IntegerWrapper.wrapInteger(description000.arity()));
          }
        }
        else {
          return (null);
        }
      }
      else {
        return (null);
      }
    }
  }

  public static Keyword aritySpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object relationArg = (proposition.arguments.theArray)[0];
      Stella_Object relationArgValue = Logic.argumentBoundTo(relationArg);
      Stella_Object arityArg = (proposition.arguments.theArray)[1];
      Stella_Object arityArgValue = Logic.argumentBoundTo(arityArg);
      IntegerWrapper computedArity = PlKernelKb.arityComputation(relationArgValue);
      Iterator iterator = ((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null)));

      lastmove = lastmove;
      if (iterator == null) {
        if (relationArgValue == null) {
          iterator = Logic.allNamedDescriptions(((Module)(Stella.$MODULE$.get())), false);
          KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, iterator, null);
        }
        else if (arityArgValue == null) {
          return (Logic.selectProofResult(Logic.bindArgumentToValueP(arityArg, computedArity, true), false, true));
        }
        else {
          if (computedArity == null) {
            return (Logic.KWD_FAILURE);
          }
          else {
            if (Surrogate.subtypeOfIntegerP(Stella_Object.safePrimaryType(arityArgValue))) {
              { IntegerWrapper arityArgValue000 = ((IntegerWrapper)(arityArgValue));

                return (Logic.selectTestResult(Stella_Object.eqlP(arityArgValue000, computedArity), true, frame));
              }
            }
            else {
              return (Logic.selectTestResult(Logic.bindArgumentToValueP(arityArg, computedArity, true), true, frame));
            }
          }
        }
      }
      { NamedDescription description = null;

        while (iterator.nextP()) {
          description = ((NamedDescription)(iterator.value));
          computedArity = PlKernelKb.arityComputation(description);
          if (Logic.bindArgumentToValueP(arityArg, computedArity, true) &&
              Logic.bindArgumentToValueP(relationArg, description, true)) {
            return (Logic.KWD_CONTINUING_SUCCESS);
          }
        }
        return (Logic.KWD_FAILURE);
      }
    }
  }

  public static Keyword relationHierarchySpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      GeneralizedSymbol relation = proposition.operator;
      Stella_Object boundarg = (proposition.arguments.theArray)[0];
      Stella_Object boundargvalue = Logic.argumentBoundTo(boundarg);
      Stella_Object otherarg = (proposition.arguments.theArray)[1];
      Stella_Object otherargvalue = Logic.argumentBoundTo(otherarg);
      boolean reflexiveP = false;
      Iterator iterator = ((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null)));
      Cons collection = Stella.NIL;

      lastmove = lastmove;
      if (boundargvalue == null) {
        if (otherargvalue == null) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        else {
          boundarg = otherarg;
          boundargvalue = otherargvalue;
          otherarg = (proposition.arguments.theArray)[0];
          otherargvalue = null;
          if (relation == Logic.SGT_PL_KERNEL_KB_DIRECT_SUBRELATION) {
            relation = Logic.SGT_PL_KERNEL_KB_DIRECT_SUPERRELATION;
          }
          else if (relation == Logic.SGT_PL_KERNEL_KB_DIRECT_SUPERRELATION) {
            relation = Logic.SGT_PL_KERNEL_KB_DIRECT_SUBRELATION;
          }
          else if (relation == Logic.SGT_PL_KERNEL_KB_SUBRELATION) {
            relation = Logic.SGT_PL_KERNEL_KB_SUPERRELATION;
          }
          else if (relation == Logic.SGT_PL_KERNEL_KB_SUPERRELATION) {
            relation = Logic.SGT_PL_KERNEL_KB_SUBRELATION;
          }
          else if (relation == Logic.SGT_PL_KERNEL_KB_PROPER_SUBRELATION) {
            relation = Logic.SGT_PL_KERNEL_KB_PROPER_SUPERRELATION;
          }
          else if (relation == Logic.SGT_PL_KERNEL_KB_PROPER_SUPERRELATION) {
            relation = Logic.SGT_PL_KERNEL_KB_PROPER_SUBRELATION;
          }
          else {
          }
        }
      }
      if (!Stella_Object.isaP(boundargvalue, Logic.SGT_LOGIC_NAMED_DESCRIPTION)) {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      if (iterator == null) {
        if (relation == Logic.SGT_PL_KERNEL_KB_DIRECT_SUBRELATION) {
          collection = NamedDescription.allDirectSubrelations(((NamedDescription)(boundargvalue)), true);
        }
        else if (relation == Logic.SGT_PL_KERNEL_KB_SUBRELATION) {
          reflexiveP = true;
          collection = NamedDescription.allSubrelations(((NamedDescription)(boundargvalue)), false);
        }
        else if (relation == Logic.SGT_PL_KERNEL_KB_PROPER_SUBRELATION) {
          collection = NamedDescription.allSubrelations(((NamedDescription)(boundargvalue)), true);
        }
        else if (relation == Logic.SGT_PL_KERNEL_KB_DIRECT_SUPERRELATION) {
          collection = NamedDescription.allDirectSuperrelations(((NamedDescription)(boundargvalue)), true);
        }
        else if (relation == Logic.SGT_PL_KERNEL_KB_SUPERRELATION) {
          reflexiveP = true;
          collection = NamedDescription.allSuperrelations(((NamedDescription)(boundargvalue)), false);
        }
        else if (relation == Logic.SGT_PL_KERNEL_KB_PROPER_SUPERRELATION) {
          collection = NamedDescription.allSuperrelations(((NamedDescription)(boundargvalue)), true);
        }
        else if (relation == Logic.SGT_PL_KERNEL_KB_EQUIVALENT_RELATION) {
          collection = NamedDescription.allEquivalentRelations(((NamedDescription)(boundargvalue)), true);
        }
        else {
          { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

            stream000.nativeStream.print("`" + relation + "' is not a valid case option");
            throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
          }
        }
        if (reflexiveP &&
            (!collection.membP(boundargvalue))) {
          collection = Stella_Object.cons(boundargvalue, collection);
        }
      }
      if (otherargvalue != null) {
        if (collection.membP(otherargvalue)) {
          return (Logic.KWD_FINAL_SUCCESS);
        }
        else {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
      }
      if (iterator == null) {
        if (collection == Stella.NIL) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        iterator = collection.allocateIterator();
        KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, iterator, null);
      }
      if (iterator.nextP() &&
          Logic.bindArgumentToValueP(otherarg, iterator.value, true)) {
        return (Logic.KWD_CONTINUING_SUCCESS);
      }
      else {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
    }
  }

  public static Keyword projectColumnSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object projectionarg = (proposition.arguments.theArray)[0];
      Stella_Object projectionvalue = Logic.argumentBoundTo(projectionarg);
      Stella_Object collectionarg = (proposition.arguments.theArray)[1];
      Stella_Object collectionvalue = Logic.argumentBoundTo(collectionarg);
      int selector = Stella.NULL_INTEGER;
      Stella_Object listarg = (proposition.arguments.theArray)[2];

      lastmove = lastmove;
      if ((collectionvalue == null) ||
          ((projectionvalue == null) ||
           (!Stella_Object.isaP(projectionvalue, Logic.SGT_STELLA_INTEGER_WRAPPER)))) {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
      selector = ((IntegerWrapper)(projectionvalue)).wrapperValue;
      if (((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null))) == null) {
        { Surrogate testValue000 = Stella_Object.safePrimaryType(collectionvalue);

          if (Surrogate.subtypeOfP(testValue000, Logic.SGT_STELLA_COLLECTION)) {
            { Collection collectionvalue000 = ((Collection)(collectionvalue));

              { List members = Logic.helpProjectNthColumn(selector, Logic.assertedCollectionMembers(collectionvalue000, false));

                if (members == null) {
                  return (Logic.KWD_TERMINAL_FAILURE);
                }
                return (Logic.selectProofResult(Logic.bindArgumentToValueP(listarg, Logic.createLogicalList(members), true), false, true));
              }
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_SKOLEM)) {
            { Skolem collectionvalue000 = ((Skolem)(collectionvalue));

              { List members = Logic.helpProjectNthColumn(selector, Logic.assertedCollectionMembers(collectionvalue000, false));

                if (members == null) {
                  return (Logic.KWD_TERMINAL_FAILURE);
                }
                return (Logic.selectProofResult(Logic.bindArgumentToValueP(listarg, Logic.createLogicalList(members), true), false, true));
              }
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_DESCRIPTION)) {
            { Description collectionvalue000 = ((Description)(collectionvalue));

              { boolean testValue001 = false;

                testValue001 = ((Vector)(KeyValueList.dynamicSlotValue(collectionvalue000.dynamicSlots, Logic.SYM_LOGIC_EXTERNAL_VARIABLES, null))) != null;
                if (testValue001) {
                  { boolean foundP000 = false;

                    { PatternVariable v = null;
                      Vector vector000 = ((Vector)(KeyValueList.dynamicSlotValue(collectionvalue000.dynamicSlots, Logic.SYM_LOGIC_EXTERNAL_VARIABLES, null)));
                      int index000 = 0;
                      int length000 = vector000.length();

                      loop000 : for (;index000 < length000; index000 = index000 + 1) {
                        v = ((PatternVariable)((vector000.theArray)[index000]));
                        if (!(Logic.argumentBoundTo(v) != null)) {
                          foundP000 = true;
                          break loop000;
                        }
                      }
                    }
                    testValue001 = foundP000;
                  }
                }
                if (testValue001) {
                  return (Logic.KWD_TERMINAL_FAILURE);
                }
              }
              if (Description.inferableP(collectionvalue000)) {
                {
                  ControlFrame.createCollectDescriptionExtensionFrame(frame, collectionvalue000);
                  KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, Logic.EMPTY_PROPOSITIONS_ITERATOR, null);
                  return (Logic.KWD_MOVE_DOWN);
                }
              }
              else {
                { List members = Logic.helpProjectNthColumn(selector, Logic.assertedCollectionMembers(collectionvalue000, false));

                  if (members == null) {
                    return (Logic.KWD_TERMINAL_FAILURE);
                  }
                  return (Logic.selectProofResult(Logic.bindArgumentToValueP(listarg, Logic.createLogicalList(members), true), false, true));
                }
              }
            }
          }
          else {
            return (Logic.KWD_FAILURE);
          }
        }
      }
      if (frame.down == null) {
        return (Logic.KWD_FAILURE);
      }
      { List list = Logic.helpProjectNthColumn(selector, frame.down.patternRecord.collectionList);

        ControlFrame.popFramesUpTo(frame.down);
        if (list == null) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        return (Logic.selectProofResult(Logic.bindArgumentToValueP(listarg, Logic.createLogicalList(list), true), false, true));
      }
    }
  }

  public static void assertSynonymDemon(Proposition self) {
    { Stella_Object term = Logic.valueOf((self.arguments.theArray)[0]);
      Stella_Object synonym = Logic.valueOf((self.arguments.theArray)[1]);
      Surrogate synonymname = null;

      if ((!Stella_Object.eqlP(term, synonym)) &&
          Stella_Object.isaP(synonym, Logic.SGT_LOGIC_LOGIC_OBJECT)) {
        synonymname = ((LogicObject)(synonym)).surrogateValueInverse;
        synonymname.surrogateValue = term;
        Logic.assertTuple(Logic.SGT_PL_KERNEL_KB_SYNONYM, Stella.consList(Stella_Object.cons(term, Stella_Object.cons(term, Stella.NIL))));
      }
    }
  }

  public static void retractSynonymDemon(Proposition self) {
    { Stella_Object term = Logic.valueOf((self.arguments.theArray)[0]);
      Stella_Object synonym = null;
      Surrogate synonymname = null;

      { Proposition prop = null;
        Iterator iter000 = Logic.allTrueDependentPropositions(term, Logic.SGT_PL_KERNEL_KB_SYNONYM, false);

        while (iter000.nextP()) {
          prop = ((Proposition)(iter000.value));
          synonym = Logic.valueOf((prop.arguments.theArray)[1]);
          if (Stella_Object.isaP(synonym, Logic.SGT_LOGIC_LOGIC_OBJECT)) {
            synonymname = ((LogicObject)(synonym)).surrogateValueInverse;
            synonymname.surrogateValue = synonym;
          }
          { Proposition object000 = prop;
            TruthValue value000 = null;
            Stella_Object oldValue000 = object000.truthValue;
            Stella_Object newValue000 = Stella_Object.updateInContext(oldValue000, value000, object000.homeContext, false);

            if (!((oldValue000 != null) &&
                (oldValue000.primaryType() == Logic.SGT_STELLA_CS_VALUE))) {
              object000.truthValue = newValue000;
            }
          }
        }
      }
    }
  }

  public static Keyword differentSpecialist(ControlFrame frame, Keyword lastmove) {
    { Vector arguments = frame.proposition.arguments;
      Cons argumentvalues = Stella.NIL;
      boolean unboundargsP = false;
      Stella_Object value = null;

      lastmove = lastmove;
      { Stella_Object arg = null;
        Vector vector000 = arguments;
        int index000 = 0;
        int length000 = vector000.length();
        Cons collect000 = null;

        for (;index000 < length000; index000 = index000 + 1) {
          arg = (vector000.theArray)[index000];
          if (collect000 == null) {
            {
              collect000 = Stella_Object.cons(Logic.valueOf(Logic.argumentBoundTo(arg)), Stella.NIL);
              if (argumentvalues == Stella.NIL) {
                argumentvalues = collect000;
              }
              else {
                Cons.addConsToEndOfConsList(argumentvalues, collect000);
              }
            }
          }
          else {
            {
              collect000.rest = Stella_Object.cons(Logic.valueOf(Logic.argumentBoundTo(arg)), Stella.NIL);
              collect000 = collect000.rest;
            }
          }
        }
      }
      while (!(argumentvalues == Stella.NIL)) {
        value = argumentvalues.value;
        if (value == null) {
          unboundargsP = true;
        }
        else {
          { boolean foundP000 = false;

            { Stella_Object value2 = null;
              Cons iter000 = argumentvalues.rest;

              loop002 : for (;!(iter000 == Stella.NIL); iter000 = iter000.rest) {
                value2 = iter000.value;
                if (Stella_Object.eqlP(value, value2)) {
                  foundP000 = true;
                  break loop002;
                }
              }
            }
            if (foundP000) {
              return (Logic.selectTestResult(false, true, frame));
            }
          }
        }
        argumentvalues = argumentvalues.rest;
      }
      if (unboundargsP) {
        return (Logic.KWD_FAILURE);
      }
      else {
        return (Logic.selectTestResult(true, true, frame));
      }
    }
  }

  /** Bootstrap the PowerLoom built-in kernel KB.
   */
  public static void initializeKernelKb() {
    { Stella_Object kernelinitfile = Stella.lookupConfigurationProperty("PLKernelKBInitFile", StringWrapper.wrapString("PL:sources;logic;pl-kernel-kb.plm"), null);
      Cons kernelkbdefinitions = ((Cons)(Stella_Object.copyConsTree(PlKernelKb.$PL_KERNEL_KB_DEFINITIONS$)));
      NamedDescription dummyconcept = null;

      kernelinitfile = kernelinitfile;
      { Object old$WarnifredefineP$000 = Stella.$WARNIFREDEFINEp$.get();

        try {
          Native.setBooleanSpecial(Stella.$WARNIFREDEFINEp$, false);
          { Object old$Module$000 = Stella.$MODULE$.get();
            Object old$Context$000 = Stella.$CONTEXT$.get();

            try {
              Native.setSpecial(Stella.$MODULE$, Stella.getStellaModule("PL-KERNEL-KB", true));
              Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
              { NamedDescription self000 = NamedDescription.newNamedDescription();

                self000.surrogateValueInverse = Logic.SGT_PL_KERNEL_KB_CONCEPT;
                self000.ioVariableTypes = Stella.list(Stella_Object.cons(Logic.SGT_PL_KERNEL_KB_CONCEPT, Stella.NIL));
                dummyconcept = self000;
              }
              Logic.SGT_PL_KERNEL_KB_CONCEPT.surrogateValue = dummyconcept;
              NamedDescription.getDescriptionExtension(dummyconcept, true);
              Logic.updateIsaProposition(dummyconcept, Logic.SGT_PL_KERNEL_KB_CONCEPT, Logic.KWD_ASSERT_TRUE);
              Logic.SGT_PL_KERNEL_KB_CLASS.surrogateValue = dummyconcept;
              Stella_Object.evaluate(kernelkbdefinitions.value);
              Logic.SGT_PL_KERNEL_KB_CLASS.surrogateValue = Logic.SGT_PL_KERNEL_KB_CONCEPT.surrogateValue;
              { Stella_Object definition = null;
                Cons iter000 = kernelkbdefinitions.rest;

                for (;!(iter000 == Stella.NIL); iter000 = iter000.rest) {
                  definition = iter000.value;
                  Stella_Object.evaluate(definition);
                }
              }
              Logic.finalizeObjects();
              { Module mdl = null;
                Iterator iter001 = Stella.allModules();

                while (iter001.nextP()) {
                  mdl = ((Module)(iter001.value));
                  Logic.introduceModule(mdl);
                }
              }
              { NamedDescription thing = Logic.getDescription(Logic.SYM_STELLA_THING.getStellaClass(true));

                Stella.evaluateString("(ASSERT (DOCUMENTATION THING  \n           \"The class of all things.  `Thing' is the top-most concept\nin the concept hierarchy.\"))");
              }

            } finally {
              Stella.$CONTEXT$.set(old$Context$000);
              Stella.$MODULE$.set(old$Module$000);
            }
          }

        } finally {
          Stella.$WARNIFREDEFINEp$.set(old$WarnifredefineP$000);
        }
      }
    }
  }

  public static boolean arithmeticEqualTest(NumberWrapper x, NumberWrapper y) {
    { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

      if (Surrogate.subtypeOfIntegerP(testValue000)) {
        { IntegerWrapper x000 = ((IntegerWrapper)(x));

          { Surrogate testValue001 = Stella_Object.safePrimaryType(y);

            if (Surrogate.subtypeOfIntegerP(testValue001)) {
              { IntegerWrapper y000 = ((IntegerWrapper)(y));

                return (x000.wrapperValue == y000.wrapperValue);
              }
            }
            else if (Surrogate.subtypeOfFloatP(testValue001)) {
              { FloatWrapper y000 = ((FloatWrapper)(y));

                return (((double)(x000.wrapperValue)) == y000.wrapperValue);
              }
            }
            else {
              { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                stream000.nativeStream.print("`" + testValue001 + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
      }
      else if (Surrogate.subtypeOfFloatP(testValue000)) {
        { FloatWrapper x000 = ((FloatWrapper)(x));

          { Surrogate testValue002 = Stella_Object.safePrimaryType(y);

            if (Surrogate.subtypeOfIntegerP(testValue002)) {
              { IntegerWrapper y000 = ((IntegerWrapper)(y));

                return (x000.wrapperValue == ((double)(y000.wrapperValue)));
              }
            }
            else if (Surrogate.subtypeOfFloatP(testValue002)) {
              { FloatWrapper y000 = ((FloatWrapper)(y));

                return (x000.wrapperValue == y000.wrapperValue);
              }
            }
            else {
              { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

                stream001.nativeStream.print("`" + testValue002 + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
      }
      else {
        { OutputStringStream stream002 = OutputStringStream.newOutputStringStream();

          stream002.nativeStream.print("`" + testValue000 + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream002.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public static boolean arithmeticLessTest(NumberWrapper x, NumberWrapper y) {
    { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

      if (Surrogate.subtypeOfIntegerP(testValue000)) {
        { IntegerWrapper x000 = ((IntegerWrapper)(x));

          { Surrogate testValue001 = Stella_Object.safePrimaryType(y);

            if (Surrogate.subtypeOfIntegerP(testValue001)) {
              { IntegerWrapper y000 = ((IntegerWrapper)(y));

                return (x000.wrapperValue < y000.wrapperValue);
              }
            }
            else if (Surrogate.subtypeOfFloatP(testValue001)) {
              { FloatWrapper y000 = ((FloatWrapper)(y));

                return (((double)(x000.wrapperValue)) < y000.wrapperValue);
              }
            }
            else {
              { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                stream000.nativeStream.print("`" + testValue001 + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
      }
      else if (Surrogate.subtypeOfFloatP(testValue000)) {
        { FloatWrapper x000 = ((FloatWrapper)(x));

          { Surrogate testValue002 = Stella_Object.safePrimaryType(y);

            if (Surrogate.subtypeOfIntegerP(testValue002)) {
              { IntegerWrapper y000 = ((IntegerWrapper)(y));

                return (x000.wrapperValue < ((double)(y000.wrapperValue)));
              }
            }
            else if (Surrogate.subtypeOfFloatP(testValue002)) {
              { FloatWrapper y000 = ((FloatWrapper)(y));

                return (x000.wrapperValue < y000.wrapperValue);
              }
            }
            else {
              { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

                stream001.nativeStream.print("`" + testValue002 + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
      }
      else {
        { OutputStringStream stream002 = OutputStringStream.newOutputStringStream();

          stream002.nativeStream.print("`" + testValue000 + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream002.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public static boolean arithmeticGreaterTest(NumberWrapper x, NumberWrapper y) {
    { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

      if (Surrogate.subtypeOfIntegerP(testValue000)) {
        { IntegerWrapper x000 = ((IntegerWrapper)(x));

          { Surrogate testValue001 = Stella_Object.safePrimaryType(y);

            if (Surrogate.subtypeOfIntegerP(testValue001)) {
              { IntegerWrapper y000 = ((IntegerWrapper)(y));

                return (x000.wrapperValue > y000.wrapperValue);
              }
            }
            else if (Surrogate.subtypeOfFloatP(testValue001)) {
              { FloatWrapper y000 = ((FloatWrapper)(y));

                return (((double)(x000.wrapperValue)) > y000.wrapperValue);
              }
            }
            else {
              { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                stream000.nativeStream.print("`" + testValue001 + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
      }
      else if (Surrogate.subtypeOfFloatP(testValue000)) {
        { FloatWrapper x000 = ((FloatWrapper)(x));

          { Surrogate testValue002 = Stella_Object.safePrimaryType(y);

            if (Surrogate.subtypeOfIntegerP(testValue002)) {
              { IntegerWrapper y000 = ((IntegerWrapper)(y));

                return (x000.wrapperValue > ((double)(y000.wrapperValue)));
              }
            }
            else if (Surrogate.subtypeOfFloatP(testValue002)) {
              { FloatWrapper y000 = ((FloatWrapper)(y));

                return (x000.wrapperValue > y000.wrapperValue);
              }
            }
            else {
              { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

                stream001.nativeStream.print("`" + testValue002 + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
      }
      else {
        { OutputStringStream stream002 = OutputStringStream.newOutputStringStream();

          stream002.nativeStream.print("`" + testValue000 + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream002.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public static NumberWrapper plusComputation(NumberWrapper x, NumberWrapper y) {
    { double floatresult = Stella.NULL_FLOAT;

      { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

        if (Surrogate.subtypeOfIntegerP(testValue000)) {
          { IntegerWrapper x000 = ((IntegerWrapper)(x));

            { Surrogate testValue001 = Stella_Object.safePrimaryType(y);

              if (Surrogate.subtypeOfIntegerP(testValue001)) {
                { IntegerWrapper y000 = ((IntegerWrapper)(y));

                  return (IntegerWrapper.wrapInteger(((int)(x000.wrapperValue + y000.wrapperValue))));
                }
              }
              else if (Surrogate.subtypeOfFloatP(testValue001)) {
                { FloatWrapper y000 = ((FloatWrapper)(y));

                  floatresult = x000.wrapperValue + y000.wrapperValue;
                }
              }
              else {
                { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                  stream000.nativeStream.print("`" + testValue001 + "' is not a valid case option");
                  throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
                }
              }
            }
          }
        }
        else if (Surrogate.subtypeOfFloatP(testValue000)) {
          { FloatWrapper x000 = ((FloatWrapper)(x));

            { Surrogate testValue002 = Stella_Object.safePrimaryType(y);

              if (Surrogate.subtypeOfIntegerP(testValue002)) {
                { IntegerWrapper y000 = ((IntegerWrapper)(y));

                  floatresult = x000.wrapperValue + y000.wrapperValue;
                }
              }
              else if (Surrogate.subtypeOfFloatP(testValue002)) {
                { FloatWrapper y000 = ((FloatWrapper)(y));

                  floatresult = x000.wrapperValue + y000.wrapperValue;
                }
              }
              else {
                { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

                  stream001.nativeStream.print("`" + testValue002 + "' is not a valid case option");
                  throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
                }
              }
            }
          }
        }
        else {
          { OutputStringStream stream002 = OutputStringStream.newOutputStringStream();

            stream002.nativeStream.print("`" + testValue000 + "' is not a valid case option");
            throw ((StellaException)(StellaException.newStellaException(stream002.theStringReader()).fillInStackTrace()));
          }
        }
      }
      return (FloatWrapper.wrapFloat(floatresult));
    }
  }

  public static NumberWrapper minusComputation(NumberWrapper x, NumberWrapper y) {
    { double floatresult = Stella.NULL_FLOAT;

      { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

        if (Surrogate.subtypeOfIntegerP(testValue000)) {
          { IntegerWrapper x000 = ((IntegerWrapper)(x));

            { Surrogate testValue001 = Stella_Object.safePrimaryType(y);

              if (Surrogate.subtypeOfIntegerP(testValue001)) {
                { IntegerWrapper y000 = ((IntegerWrapper)(y));

                  return (IntegerWrapper.wrapInteger(((int)(x000.wrapperValue - y000.wrapperValue))));
                }
              }
              else if (Surrogate.subtypeOfFloatP(testValue001)) {
                { FloatWrapper y000 = ((FloatWrapper)(y));

                  floatresult = x000.wrapperValue - y000.wrapperValue;
                }
              }
              else {
                { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                  stream000.nativeStream.print("`" + testValue001 + "' is not a valid case option");
                  throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
                }
              }
            }
          }
        }
        else if (Surrogate.subtypeOfFloatP(testValue000)) {
          { FloatWrapper x000 = ((FloatWrapper)(x));

            { Surrogate testValue002 = Stella_Object.safePrimaryType(y);

              if (Surrogate.subtypeOfIntegerP(testValue002)) {
                { IntegerWrapper y000 = ((IntegerWrapper)(y));

                  floatresult = x000.wrapperValue - y000.wrapperValue;
                }
              }
              else if (Surrogate.subtypeOfFloatP(testValue002)) {
                { FloatWrapper y000 = ((FloatWrapper)(y));

                  floatresult = x000.wrapperValue - y000.wrapperValue;
                }
              }
              else {
                { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

                  stream001.nativeStream.print("`" + testValue002 + "' is not a valid case option");
                  throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
                }
              }
            }
          }
        }
        else {
          { OutputStringStream stream002 = OutputStringStream.newOutputStringStream();

            stream002.nativeStream.print("`" + testValue000 + "' is not a valid case option");
            throw ((StellaException)(StellaException.newStellaException(stream002.theStringReader()).fillInStackTrace()));
          }
        }
      }
      return (FloatWrapper.wrapFloat(floatresult));
    }
  }

  public static NumberWrapper timesComputation(NumberWrapper x, NumberWrapper y) {
    { double floatresult = Stella.NULL_FLOAT;

      { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

        if (Surrogate.subtypeOfIntegerP(testValue000)) {
          { IntegerWrapper x000 = ((IntegerWrapper)(x));

            { Surrogate testValue001 = Stella_Object.safePrimaryType(y);

              if (Surrogate.subtypeOfIntegerP(testValue001)) {
                { IntegerWrapper y000 = ((IntegerWrapper)(y));

                  return (IntegerWrapper.wrapInteger(((int)(x000.wrapperValue * y000.wrapperValue))));
                }
              }
              else if (Surrogate.subtypeOfFloatP(testValue001)) {
                { FloatWrapper y000 = ((FloatWrapper)(y));

                  floatresult = x000.wrapperValue * y000.wrapperValue;
                }
              }
              else {
                { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                  stream000.nativeStream.print("`" + testValue001 + "' is not a valid case option");
                  throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
                }
              }
            }
          }
        }
        else if (Surrogate.subtypeOfFloatP(testValue000)) {
          { FloatWrapper x000 = ((FloatWrapper)(x));

            { Surrogate testValue002 = Stella_Object.safePrimaryType(y);

              if (Surrogate.subtypeOfIntegerP(testValue002)) {
                { IntegerWrapper y000 = ((IntegerWrapper)(y));

                  floatresult = x000.wrapperValue * y000.wrapperValue;
                }
              }
              else if (Surrogate.subtypeOfFloatP(testValue002)) {
                { FloatWrapper y000 = ((FloatWrapper)(y));

                  floatresult = x000.wrapperValue * y000.wrapperValue;
                }
              }
              else {
                { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

                  stream001.nativeStream.print("`" + testValue002 + "' is not a valid case option");
                  throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
                }
              }
            }
          }
        }
        else {
          { OutputStringStream stream002 = OutputStringStream.newOutputStringStream();

            stream002.nativeStream.print("`" + testValue000 + "' is not a valid case option");
            throw ((StellaException)(StellaException.newStellaException(stream002.theStringReader()).fillInStackTrace()));
          }
        }
      }
      return (FloatWrapper.wrapFloat(floatresult));
    }
  }

  public static NumberWrapper divideComputation(NumberWrapper x, NumberWrapper y) {
    try {
      { double floatresult = Stella.NULL_FLOAT;

        { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

          if (Surrogate.subtypeOfIntegerP(testValue000)) {
            { IntegerWrapper x000 = ((IntegerWrapper)(x));

              { Surrogate testValue001 = Stella_Object.safePrimaryType(y);

                if (Surrogate.subtypeOfIntegerP(testValue001)) {
                  { IntegerWrapper y000 = ((IntegerWrapper)(y));

                    if (((x000.wrapperValue) % (y000.wrapperValue)) == 0) {
                      return (IntegerWrapper.wrapInteger(((x000.wrapperValue) / (y000.wrapperValue))));
                    }
                    else {
                      floatresult = ((double)(x000.wrapperValue)) / ((double)(y000.wrapperValue));
                    }
                  }
                }
                else if (Surrogate.subtypeOfFloatP(testValue001)) {
                  { FloatWrapper y000 = ((FloatWrapper)(y));

                    floatresult = x000.wrapperValue / y000.wrapperValue;
                  }
                }
                else {
                  { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                    stream000.nativeStream.print("`" + testValue001 + "' is not a valid case option");
                    throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
                  }
                }
              }
            }
          }
          else if (Surrogate.subtypeOfFloatP(testValue000)) {
            { FloatWrapper x000 = ((FloatWrapper)(x));

              { Surrogate testValue002 = Stella_Object.safePrimaryType(y);

                if (Surrogate.subtypeOfIntegerP(testValue002)) {
                  { IntegerWrapper y000 = ((IntegerWrapper)(y));

                    floatresult = x000.wrapperValue / y000.wrapperValue;
                  }
                }
                else if (Surrogate.subtypeOfFloatP(testValue002)) {
                  { FloatWrapper y000 = ((FloatWrapper)(y));

                    floatresult = x000.wrapperValue / y000.wrapperValue;
                  }
                }
                else {
                  { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

                    stream001.nativeStream.print("`" + testValue002 + "' is not a valid case option");
                    throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
                  }
                }
              }
            }
          }
          else {
            { OutputStringStream stream002 = OutputStringStream.newOutputStringStream();

              stream002.nativeStream.print("`" + testValue000 + "' is not a valid case option");
              throw ((StellaException)(StellaException.newStellaException(stream002.theStringReader()).fillInStackTrace()));
            }
          }
        }
        return (FloatWrapper.wrapFloat(floatresult));
      }
    } catch (java.lang.Exception e000) {
      return (null);
    }
  }

  public static NumberWrapper sqrtComputation(NumberWrapper x) {
    { double floatresult = Stella.NULL_FLOAT;
      int integerresult = Stella.NULL_INTEGER;

      { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

        if (Surrogate.subtypeOfIntegerP(testValue000)) {
          { IntegerWrapper x000 = ((IntegerWrapper)(x));

            floatresult = Math.sqrt((((double)(x000.wrapperValue))));
            integerresult = ((int)(floatresult));
            if (floatresult == ((double)(integerresult))) {
              return (IntegerWrapper.wrapInteger(integerresult));
            }
            else {
              return (FloatWrapper.wrapFloat(floatresult));
            }
          }
        }
        else if (Surrogate.subtypeOfFloatP(testValue000)) {
          { FloatWrapper x000 = ((FloatWrapper)(x));

            floatresult = Math.sqrt((x000.wrapperValue));
          }
        }
        else {
          { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

            stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
            throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
          }
        }
      }
      return (FloatWrapper.wrapFloat(floatresult));
    }
  }

  public static NumberWrapper negateComputation(NumberWrapper x) {
    { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

      if (Surrogate.subtypeOfIntegerP(testValue000)) {
        { IntegerWrapper x000 = ((IntegerWrapper)(x));

          return (IntegerWrapper.wrapInteger(0 - IntegerWrapper.unwrapInteger(x000)));
        }
      }
      else if (Surrogate.subtypeOfFloatP(testValue000)) {
        { FloatWrapper x000 = ((FloatWrapper)(x));

          return (FloatWrapper.wrapFloat(0.0 - FloatWrapper.unwrapFloat(x000)));
        }
      }
      else {
        { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

          stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public static NumberWrapper absComputation(NumberWrapper x) {
    { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

      if (Surrogate.subtypeOfIntegerP(testValue000)) {
        { IntegerWrapper x000 = ((IntegerWrapper)(x));

          if (IntegerWrapper.unwrapInteger(x000) < 0) {
            return (IntegerWrapper.wrapInteger(0 - IntegerWrapper.unwrapInteger(x000)));
          }
          else {
            return (x000);
          }
        }
      }
      else if (Surrogate.subtypeOfFloatP(testValue000)) {
        { FloatWrapper x000 = ((FloatWrapper)(x));

          if (FloatWrapper.unwrapFloat(x000) < 0.0) {
            return (FloatWrapper.wrapFloat(0.0 - FloatWrapper.unwrapFloat(x000)));
          }
          else {
            return (x000);
          }
        }
      }
      else {
        { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

          stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public static Stella_Object plusConstraint(IntegerWrapper missingArgument, NumberWrapper x1, NumberWrapper x2, NumberWrapper x3) {
    { Stella_Object value = null;

      switch (missingArgument.wrapperValue) {
        case -1: 
          value = (PlKernelKb.arithmeticEqualTest(PlKernelKb.plusComputation(x1, x2), x3) ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
        break;
        case 0: 
          value = PlKernelKb.minusComputation(x3, x2);
        break;
        case 1: 
          value = PlKernelKb.minusComputation(x3, x1);
        break;
        case 2: 
          value = PlKernelKb.plusComputation(x1, x2);
        break;
        default:
        break;
      }
      return (value);
    }
  }

  public static Stella_Object minusConstraint(IntegerWrapper missingArgument, NumberWrapper x1, NumberWrapper x2, NumberWrapper x3) {
    { Stella_Object value = null;

      switch (missingArgument.wrapperValue) {
        case -1: 
          value = (PlKernelKb.arithmeticEqualTest(PlKernelKb.minusComputation(x1, x2), x3) ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
        break;
        case 0: 
          value = PlKernelKb.plusComputation(x2, x3);
        break;
        case 1: 
          value = PlKernelKb.minusComputation(x1, x3);
        break;
        case 2: 
          value = PlKernelKb.minusComputation(x1, x2);
        break;
        default:
        break;
      }
      return (value);
    }
  }

  public static Stella_Object timesConstraint(IntegerWrapper missingArgument, NumberWrapper x1, NumberWrapper x2, NumberWrapper x3) {
    { Stella_Object value = null;

      switch (missingArgument.wrapperValue) {
        case -1: 
          value = (PlKernelKb.arithmeticEqualTest(PlKernelKb.timesComputation(x1, x2), x3) ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
        break;
        case 0: 
          value = PlKernelKb.divideComputation(x3, x2);
        break;
        case 1: 
          value = PlKernelKb.divideComputation(x3, x1);
        break;
        case 2: 
          value = PlKernelKb.timesComputation(x1, x2);
        break;
        default:
        break;
      }
      return (value);
    }
  }

  public static Stella_Object divideConstraint(IntegerWrapper missingArgument, NumberWrapper x1, NumberWrapper x2, NumberWrapper x3) {
    { Stella_Object value = null;

      switch (missingArgument.wrapperValue) {
        case -1: 
          { NumberWrapper ratio = PlKernelKb.divideComputation(x1, x2);

            if (ratio != null) {
              value = (PlKernelKb.arithmeticEqualTest(ratio, x3) ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
            }
            else {
              value = Stella.FALSE_WRAPPER;
            }
          }
        break;
        case 0: 
          value = PlKernelKb.timesComputation(x2, x3);
        break;
        case 1: 
          value = PlKernelKb.divideComputation(x1, x3);
        break;
        case 2: 
          value = PlKernelKb.divideComputation(x1, x2);
        break;
        default:
        break;
      }
      return (value);
    }
  }

  public static Stella_Object negateConstraint(IntegerWrapper missingArgument, NumberWrapper x1, NumberWrapper x2) {
    { Stella_Object value = null;

      switch (missingArgument.wrapperValue) {
        case -1: 
          value = (PlKernelKb.arithmeticEqualTest(x1, PlKernelKb.negateComputation(x2)) ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
        break;
        case 0: 
          value = PlKernelKb.negateComputation(x2);
        break;
        case 1: 
          value = PlKernelKb.negateComputation(x1);
        break;
        default:
        break;
      }
      return (value);
    }
  }

  public static Stella_Object sqrtConstraint(IntegerWrapper missingArgument, NumberWrapper x1, NumberWrapper x2) {
    { Stella_Object value = null;

      switch (missingArgument.wrapperValue) {
        case -1: 
          value = (PlKernelKb.arithmeticEqualTest(PlKernelKb.timesComputation(x2, x2), x1) ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
        break;
        case 0: 
          value = PlKernelKb.timesComputation(x2, x2);
        break;
        case 1: 
          if (PlKernelKb.arithmeticLessTest(x1, IntegerWrapper.wrapInteger(0))) {
            value = null;
          }
          else {
            value = PlKernelKb.sqrtComputation(x1);
          }
        break;
        default:
        break;
      }
      return (value);
    }
  }

  public static void printInterval(java.io.PrintStream stream, Stella_Object lower, boolean strictLowerP, Stella_Object upper, boolean strictUpperP) {
    if (strictLowerP) {
      stream.print("(");
    }
    else {
      stream.print("[");
    }
    if (lower != null) {
      stream.print(lower);
    }
    else {
      stream.print("?");
    }
    stream.print(",");
    if (upper != null) {
      stream.print(upper);
    }
    else {
      stream.print("?");
    }
    if (strictUpperP) {
      stream.print(")");
    }
    else {
      stream.print("]");
    }
  }

  public static IntervalCache createIntervalCache(LogicObject intervalmember) {
    { IntervalCache intervalcache = IntervalCache.newIntervalCache();

      intervalcache.intervalMember = intervalmember;
      intervalcache.homeContext = ((Context)(Stella.$CONTEXT$.get()));
      Logic.assertBinaryValue(PlKernelKb.SGT_PL_KERNEL_KB_INTERVAL_CACHE_OF, intervalmember, intervalcache);
      return (intervalcache);
    }
  }

  public static IntervalCache getIntervalCache(LogicObject self) {
    { Stella_Object intervalcache = Logic.accessBinaryValue(self, PlKernelKb.SGT_PL_KERNEL_KB_INTERVAL_CACHE_OF);

      if ((intervalcache != null) &&
          (!Logic.skolemP(intervalcache))) {
        { IntervalCache thiscache = ((IntervalCache)(intervalcache));
          IntervalCache copycache = null;
          Proposition proposition = null;

          if (thiscache.homeContext == ((Context)(Stella.$CONTEXT$.get()))) {
            return (thiscache);
          }
          { IntervalCache self000 = IntervalCache.newIntervalCache();

            self000.homeContext = ((Context)(Stella.$CONTEXT$.get()));
            self000.intervalMember = self;
            self000.lowerBound = thiscache.lowerBound;
            self000.upperBound = thiscache.upperBound;
            self000.strictLowerBoundP = thiscache.strictLowerBoundP;
            self000.strictUpperBoundP = thiscache.strictUpperBoundP;
            copycache = self000;
          }
          { Proposition value000 = null;

            { Proposition p = null;
              Iterator iter000 = Logic.unfilteredDependentPropositions(self, PlKernelKb.SGT_PL_KERNEL_KB_INTERVAL_CACHE_OF).allocateIterator();

              loop000 : while (iter000.nextP()) {
                p = ((Proposition)(iter000.value));
                if (((Surrogate)(p.operator)) == PlKernelKb.SGT_PL_KERNEL_KB_INTERVAL_CACHE_OF) {
                  value000 = p;
                  break loop000;
                }
              }
            }
            proposition = value000;
          }
          Logic.equateValues(Logic.valueOf((proposition.arguments.theArray)[(proposition.arguments.length() - 1)]), copycache);
          return (copycache);
        }
      }
      else {
        return (PlKernelKb.createIntervalCache(self));
      }
    }
  }

  public static void evaluateAdjacentInequalities(LogicObject self) {
    { Proposition dep = null;
      Iterator iter000 = Logic.allSpecializingDependentPropositions(self, Logic.SGT_PL_KERNEL_KB_INEQUALITY);

      while (iter000.nextP()) {
        dep = ((Proposition)(iter000.value));
        { boolean alwaysP000 = true;

          { Stella_Object arg = null;
            Vector vector000 = dep.arguments;
            int index000 = 0;
            int length000 = vector000.length();

            loop001 : for (;index000 < length000; index000 = index000 + 1) {
              arg = (vector000.theArray)[index000];
              if (!(Stella_Object.isaP(Logic.valueOf(arg), Logic.SGT_LOGIC_LOGIC_OBJECT) ||
                  (!Proposition.trueP(dep)))) {
                alwaysP000 = false;
                break loop001;
              }
            }
          }
          if (alwaysP000) {
            Proposition.postForEvaluation(dep);
          }
        }
      }
    }
  }

  public static Surrogate inverseInequalityOperator(Surrogate operator) {
    if (operator == PlKernelKb.SGT_PL_KERNEL_KB_g) {
      return (PlKernelKb.SGT_PL_KERNEL_KB_l);
    }
    else if (operator == PlKernelKb.SGT_PL_KERNEL_KB_l) {
      return (PlKernelKb.SGT_PL_KERNEL_KB_g);
    }
    else if (operator == Logic.SGT_PL_KERNEL_KB_ge) {
      return (PlKernelKb.SGT_PL_KERNEL_KB_el);
    }
    else if (operator == PlKernelKb.SGT_PL_KERNEL_KB_el) {
      return (Logic.SGT_PL_KERNEL_KB_ge);
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + operator + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public static Stella_Object accessIntervalBounds(Stella_Object x, Keyword lowerorupper, Object [] MV_returnarray) {
    { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

      if (Surrogate.subtypeOfP(testValue000, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
        { NumberWrapper x000 = ((NumberWrapper)(x));

          { Stella_Object _return_temp = x000;

            MV_returnarray[0] = BooleanWrapper.wrapBoolean(false);
            return (_return_temp);
          }
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_QUANTITY_LOGIC_WRAPPER)) {
        { QuantityLogicWrapper x000 = ((QuantityLogicWrapper)(x));

          { Stella_Object _return_temp = x000;

            MV_returnarray[0] = BooleanWrapper.wrapBoolean(false);
            return (_return_temp);
          }
        }
      }
      else {
        return (IntervalCache.accessIntervalCacheBounds(((IntervalCache)(Logic.accessBinaryValue(x, PlKernelKb.SGT_PL_KERNEL_KB_INTERVAL_CACHE_OF))), lowerorupper, MV_returnarray));
      }
    }
  }

  public static boolean compareIntervalBoundsP(Surrogate relation, Stella_Object x, Stella_Object y) {
    if (PlKernelKb.nullLiteralWrapperP(x) ||
        PlKernelKb.nullLiteralWrapperP(y)) {
      return (false);
    }
    if (relation == PlKernelKb.SGT_PL_KERNEL_KB_e) {
      return (Stella_Object.eqlP(x, y));
    }
    { Surrogate testValue000 = Stella_Object.safePrimaryType(x);

      if (Surrogate.subtypeOfP(testValue000, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
        { NumberWrapper x000 = ((NumberWrapper)(x));

          { Surrogate testValue001 = Stella_Object.safePrimaryType(y);

            if (Surrogate.subtypeOfP(testValue001, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
              { NumberWrapper y000 = ((NumberWrapper)(y));

                { double floatX = x000.numberWrapperToFloat();
                  double floatY = y000.numberWrapperToFloat();

                  if (relation == PlKernelKb.SGT_PL_KERNEL_KB_el) {
                    return (floatX <= floatY);
                  }
                  else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_l) {
                    return (floatX < floatY);
                  }
                  else if (relation == Logic.SGT_PL_KERNEL_KB_ge) {
                    return (floatX >= floatY);
                  }
                  else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_g) {
                    return (floatX > floatY);
                  }
                  else {
                    { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                      stream000.nativeStream.print("`" + relation + "' is not a valid case option");
                      throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
                    }
                  }
                }
              }
            }
            else if (Surrogate.subtypeOfP(testValue001, Logic.SGT_LOGIC_QUANTITY_LOGIC_WRAPPER)) {
              { QuantityLogicWrapper y000 = ((QuantityLogicWrapper)(y));

                { Quantity quantityY = y000.wrapperValue;
                  Quantity quantityX = quantityY.coerceTo(x000);

                  if (relation == PlKernelKb.SGT_PL_KERNEL_KB_el) {
                    return (quantityX.lessEqualP(quantityY));
                  }
                  else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_l) {
                    return (quantityX.lessP(quantityY));
                  }
                  else if (relation == Logic.SGT_PL_KERNEL_KB_ge) {
                    return (quantityX.greaterEqualP(quantityY));
                  }
                  else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_g) {
                    return (quantityX.greaterP(quantityY));
                  }
                  else {
                    { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

                      stream001.nativeStream.print("`" + relation + "' is not a valid case option");
                      throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
                    }
                  }
                }
              }
            }
            else {
              { OutputStringStream stream002 = OutputStringStream.newOutputStringStream();

                stream002.nativeStream.print("`" + testValue001 + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream002.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_QUANTITY_LOGIC_WRAPPER)) {
        { QuantityLogicWrapper x000 = ((QuantityLogicWrapper)(x));

          { Surrogate testValue002 = Stella_Object.safePrimaryType(y);

            if (Surrogate.subtypeOfP(testValue002, Logic.SGT_STELLA_NUMBER_WRAPPER)) {
              { NumberWrapper y000 = ((NumberWrapper)(y));

                { Quantity quantityX = x000.wrapperValue;
                  Quantity quantityY = quantityX.coerceTo(y000);

                  if (relation == PlKernelKb.SGT_PL_KERNEL_KB_el) {
                    return (quantityX.lessEqualP(quantityY));
                  }
                  else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_l) {
                    return (quantityX.lessP(quantityY));
                  }
                  else if (relation == Logic.SGT_PL_KERNEL_KB_ge) {
                    return (quantityX.greaterEqualP(quantityY));
                  }
                  else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_g) {
                    return (quantityX.greaterP(quantityY));
                  }
                  else {
                    { OutputStringStream stream003 = OutputStringStream.newOutputStringStream();

                      stream003.nativeStream.print("`" + relation + "' is not a valid case option");
                      throw ((StellaException)(StellaException.newStellaException(stream003.theStringReader()).fillInStackTrace()));
                    }
                  }
                }
              }
            }
            else if (Surrogate.subtypeOfP(testValue002, Logic.SGT_LOGIC_QUANTITY_LOGIC_WRAPPER)) {
              { QuantityLogicWrapper y000 = ((QuantityLogicWrapper)(y));

                if (relation == PlKernelKb.SGT_PL_KERNEL_KB_el) {
                  return (x000.wrapperValue.lessEqualP(y000.wrapperValue));
                }
                else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_l) {
                  return (x000.wrapperValue.lessP(y000.wrapperValue));
                }
                else if (relation == Logic.SGT_PL_KERNEL_KB_ge) {
                  return (x000.wrapperValue.greaterEqualP(y000.wrapperValue));
                }
                else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_g) {
                  return (x000.wrapperValue.greaterP(y000.wrapperValue));
                }
                else {
                  { OutputStringStream stream004 = OutputStringStream.newOutputStringStream();

                    stream004.nativeStream.print("`" + relation + "' is not a valid case option");
                    throw ((StellaException)(StellaException.newStellaException(stream004.theStringReader()).fillInStackTrace()));
                  }
                }
              }
            }
            else {
              { OutputStringStream stream005 = OutputStringStream.newOutputStringStream();

                stream005.nativeStream.print("`" + testValue002 + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream005.theStringReader()).fillInStackTrace()));
              }
            }
          }
        }
      }
      else {
        { OutputStringStream stream006 = OutputStringStream.newOutputStringStream();

          stream006.nativeStream.print("`" + testValue000 + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream006.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public static boolean nullNumberP(NumberWrapper self) {
    if (self == null) {
      return (true);
    }
    { Surrogate testValue000 = Stella_Object.safePrimaryType(self);

      if (Surrogate.subtypeOfIntegerP(testValue000)) {
        { IntegerWrapper self000 = ((IntegerWrapper)(self));

          return (self000.wrapperValue == Stella.NULL_INTEGER);
        }
      }
      else if (Surrogate.subtypeOfFloatP(testValue000)) {
        { FloatWrapper self000 = ((FloatWrapper)(self));

          return (self000.wrapperValue == Stella.NULL_FLOAT);
        }
      }
      else {
        { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

          stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public static boolean nullLiteralWrapperP(Stella_Object self) {
    if (self == null) {
      return (true);
    }
    { Surrogate testValue000 = Stella_Object.safePrimaryType(self);

      if (Surrogate.subtypeOfIntegerP(testValue000)) {
        { IntegerWrapper self000 = ((IntegerWrapper)(self));

          return (self000.wrapperValue == Stella.NULL_INTEGER);
        }
      }
      else if (Surrogate.subtypeOfFloatP(testValue000)) {
        { FloatWrapper self000 = ((FloatWrapper)(self));

          return (self000.wrapperValue == Stella.NULL_FLOAT);
        }
      }
      else if (Surrogate.subtypeOfP(testValue000, Logic.SGT_LOGIC_QUANTITY_LOGIC_WRAPPER)) {
        { QuantityLogicWrapper self000 = ((QuantityLogicWrapper)(self));

          return (self000.wrapperValue == null);
        }
      }
      else if (Surrogate.subtypeOfStringP(testValue000)) {
        { StringWrapper self000 = ((StringWrapper)(self));

          return (self000.wrapperValue == null);
        }
      }
      else if (Surrogate.subtypeOfCharacterP(testValue000)) {
        { CharacterWrapper self000 = ((CharacterWrapper)(self));

          return (self000.wrapperValue == Stella.NULL_CHARACTER);
        }
      }
      else {
        { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

          stream000.nativeStream.print("`" + testValue000 + "' is not a valid case option");
          throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
        }
      }
    }
  }

  public static boolean satisfiesIntervalBoundsP(Stella_Object renamed_Object, Stella_Object value) {
    { Stella_Object lb = null;
      boolean strictlowerP = false;
      Stella_Object ub = null;
      boolean strictupperP = false;
      boolean answer = true;

      { Object [] caller_MV_returnarray = new Object[1];

        lb = PlKernelKb.accessIntervalBounds(renamed_Object, PlKernelKb.KWD_LOWER_BOUND, caller_MV_returnarray);
        strictlowerP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[0])).wrapperValue));
      }
      { Object [] caller_MV_returnarray = new Object[1];

        ub = PlKernelKb.accessIntervalBounds(renamed_Object, PlKernelKb.KWD_UPPER_BOUND, caller_MV_returnarray);
        strictupperP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[0])).wrapperValue));
      }
      if (PlKernelKb.nullLiteralWrapperP(value)) {
        return (false);
      }
      if (!(PlKernelKb.nullLiteralWrapperP(lb))) {
        if (strictlowerP) {
          answer = PlKernelKb.compareIntervalBoundsP(PlKernelKb.SGT_PL_KERNEL_KB_l, lb, value);
        }
        else {
          answer = PlKernelKb.compareIntervalBoundsP(PlKernelKb.SGT_PL_KERNEL_KB_el, lb, value);
        }
      }
      if (!(PlKernelKb.nullLiteralWrapperP(ub))) {
        if (strictupperP) {
          answer = answer &&
              PlKernelKb.compareIntervalBoundsP(PlKernelKb.SGT_PL_KERNEL_KB_l, value, ub);
        }
        else {
          answer = answer &&
              PlKernelKb.compareIntervalBoundsP(PlKernelKb.SGT_PL_KERNEL_KB_el, value, ub);
        }
      }
      return (answer);
    }
  }

  public static Keyword lessSpecialistHelper(ControlFrame frame, Surrogate relation, Stella_Object xarg, Stella_Object yarg) {
    { Stella_Object x = Logic.argumentBoundTo(xarg);
      Stella_Object y = Logic.argumentBoundTo(yarg);
      Stella_Object xbound = null;
      boolean strictxP = false;
      Stella_Object ybound = null;
      boolean strictyP = false;
      boolean successP = false;

      if (y == null) {
        if (x == null) {
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        { Object [] caller_MV_returnarray = new Object[1];

          xbound = PlKernelKb.accessIntervalBounds(x, PlKernelKb.KWD_UPPER_BOUND, caller_MV_returnarray);
          strictxP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[0])).wrapperValue));
        }
        if ((!PlKernelKb.nullLiteralWrapperP(xbound)) &&
            ((relation == PlKernelKb.SGT_PL_KERNEL_KB_el) ||
             Stella_Object.isaP(xbound, Logic.SGT_STELLA_INTEGER_WRAPPER))) {
          if (relation == PlKernelKb.SGT_PL_KERNEL_KB_l) {
            xbound = IntegerWrapper.wrapInteger(((IntegerWrapper)(xbound)).wrapperValue + 1);
          }
          successP = PatternVariable.bindVariableToValueP(((PatternVariable)(yarg)), xbound, true);
        }
        return (Logic.selectProofResult(successP, false, false));
      }
      if (x == null) {
        { Object [] caller_MV_returnarray = new Object[1];

          ybound = PlKernelKb.accessIntervalBounds(y, PlKernelKb.KWD_LOWER_BOUND, caller_MV_returnarray);
          strictyP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[0])).wrapperValue));
        }
        if ((!PlKernelKb.nullNumberP(((NumberWrapper)(ybound)))) &&
            ((relation == PlKernelKb.SGT_PL_KERNEL_KB_el) ||
             Stella_Object.isaP(ybound, Logic.SGT_STELLA_INTEGER_WRAPPER))) {
          if (relation == PlKernelKb.SGT_PL_KERNEL_KB_l) {
            ybound = IntegerWrapper.wrapInteger(((IntegerWrapper)(ybound)).wrapperValue - 1);
          }
          successP = PatternVariable.bindVariableToValueP(((PatternVariable)(xarg)), ybound, true);
        }
        return (Logic.selectProofResult(successP, false, false));
      }
      { boolean successP000 = false;

        { Object [] caller_MV_returnarray = new Object[1];

          xbound = PlKernelKb.accessIntervalBounds(x, PlKernelKb.KWD_UPPER_BOUND, caller_MV_returnarray);
          strictxP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[0])).wrapperValue));
        }
        { Object [] caller_MV_returnarray = new Object[1];

          ybound = PlKernelKb.accessIntervalBounds(y, PlKernelKb.KWD_LOWER_BOUND, caller_MV_returnarray);
          strictyP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[0])).wrapperValue));
        }
        try {
          if (relation == PlKernelKb.SGT_PL_KERNEL_KB_l) {
            successP000 = ((strictxP ||
                strictyP) &&
                PlKernelKb.compareIntervalBoundsP(PlKernelKb.SGT_PL_KERNEL_KB_el, xbound, ybound)) ||
                PlKernelKb.compareIntervalBoundsP(PlKernelKb.SGT_PL_KERNEL_KB_l, xbound, ybound);
          }
          else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_el) {
            successP000 = PlKernelKb.compareIntervalBoundsP(relation, xbound, ybound);
          }
          else {
            { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

              stream000.nativeStream.print("`" + relation + "' is not a valid case option");
              throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
            }
          }
        } catch (IncompatibleQuantityException e000) {
          ControlFrame.setFrameTruthValue(frame, Logic.UNKNOWN_TRUTH_VALUE);
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        if (successP000) {
          ControlFrame.setFrameTruthValue(frame, Logic.TRUE_TRUTH_VALUE);
          return (Logic.KWD_FINAL_SUCCESS);
        }
        { Object [] caller_MV_returnarray = new Object[1];

          xbound = PlKernelKb.accessIntervalBounds(x, PlKernelKb.KWD_LOWER_BOUND, caller_MV_returnarray);
          strictxP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[0])).wrapperValue));
        }
        { Object [] caller_MV_returnarray = new Object[1];

          ybound = PlKernelKb.accessIntervalBounds(y, PlKernelKb.KWD_UPPER_BOUND, caller_MV_returnarray);
          strictyP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[0])).wrapperValue));
        }
        try {
          if (relation == PlKernelKb.SGT_PL_KERNEL_KB_el) {
            successP000 = ((strictxP ||
                strictyP) &&
                PlKernelKb.compareIntervalBoundsP(PlKernelKb.SGT_PL_KERNEL_KB_el, ybound, xbound)) ||
                PlKernelKb.compareIntervalBoundsP(PlKernelKb.SGT_PL_KERNEL_KB_l, ybound, xbound);
          }
          else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_l) {
            successP000 = PlKernelKb.compareIntervalBoundsP(PlKernelKb.SGT_PL_KERNEL_KB_el, ybound, xbound);
          }
          else {
            { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

              stream001.nativeStream.print("`" + relation + "' is not a valid case option");
              throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
            }
          }
        } catch (IncompatibleQuantityException e001) {
          ControlFrame.setFrameTruthValue(frame, Logic.UNKNOWN_TRUTH_VALUE);
          return (Logic.KWD_TERMINAL_FAILURE);
        }
        if (successP000) {
          ControlFrame.setFrameTruthValue(frame, Logic.FALSE_TRUTH_VALUE);
          return (Logic.KWD_TERMINAL_FAILURE);
        }
      }
      if (Logic.skolemP(x) &&
          Logic.skolemP(y)) {
        return (Logic.KWD_FAILURE);
      }
      else {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
    }
  }

  public static Keyword inequalitySpecialist(ControlFrame frame, Keyword lastmove) {
    lastmove = lastmove;
    { Proposition proposition = frame.proposition;
      Surrogate relation = ((Surrogate)(proposition.operator));

      if (((Boolean)(Logic.$REVERSEPOLARITYp$.get())).booleanValue()) {
        { Object old$ReversepolarityP$000 = Logic.$REVERSEPOLARITYp$.get();

          try {
            Native.setBooleanSpecial(Logic.$REVERSEPOLARITYp$, false);
            if (relation == PlKernelKb.SGT_PL_KERNEL_KB_l) {
              return (PlKernelKb.lessSpecialistHelper(frame, PlKernelKb.SGT_PL_KERNEL_KB_el, (proposition.arguments.theArray)[1], (proposition.arguments.theArray)[0]));
            }
            else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_el) {
              return (PlKernelKb.lessSpecialistHelper(frame, PlKernelKb.SGT_PL_KERNEL_KB_l, (proposition.arguments.theArray)[1], (proposition.arguments.theArray)[0]));
            }
            else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_g) {
              return (PlKernelKb.lessSpecialistHelper(frame, PlKernelKb.SGT_PL_KERNEL_KB_el, (proposition.arguments.theArray)[0], (proposition.arguments.theArray)[1]));
            }
            else if (relation == Logic.SGT_PL_KERNEL_KB_ge) {
              return (PlKernelKb.lessSpecialistHelper(frame, PlKernelKb.SGT_PL_KERNEL_KB_l, (proposition.arguments.theArray)[0], (proposition.arguments.theArray)[1]));
            }
            else {
              { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

                stream000.nativeStream.print("`" + relation + "' is not a valid case option");
                throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
              }
            }

          } finally {
            Logic.$REVERSEPOLARITYp$.set(old$ReversepolarityP$000);
          }
        }
      }
      else {
        if (relation == PlKernelKb.SGT_PL_KERNEL_KB_l) {
          return (PlKernelKb.lessSpecialistHelper(frame, PlKernelKb.SGT_PL_KERNEL_KB_l, (proposition.arguments.theArray)[0], (proposition.arguments.theArray)[1]));
        }
        else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_el) {
          return (PlKernelKb.lessSpecialistHelper(frame, PlKernelKb.SGT_PL_KERNEL_KB_el, (proposition.arguments.theArray)[0], (proposition.arguments.theArray)[1]));
        }
        else if (relation == PlKernelKb.SGT_PL_KERNEL_KB_g) {
          return (PlKernelKb.lessSpecialistHelper(frame, PlKernelKb.SGT_PL_KERNEL_KB_l, (proposition.arguments.theArray)[1], (proposition.arguments.theArray)[0]));
        }
        else if (relation == Logic.SGT_PL_KERNEL_KB_ge) {
          return (PlKernelKb.lessSpecialistHelper(frame, PlKernelKb.SGT_PL_KERNEL_KB_el, (proposition.arguments.theArray)[1], (proposition.arguments.theArray)[0]));
        }
        else {
          { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

            stream001.nativeStream.print("`" + relation + "' is not a valid case option");
            throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
          }
        }
      }
    }
  }

  public static void inequalityEvaluator(Proposition self) {
    if (!(Proposition.trueP(self))) {
      return;
    }
    { Stella_Object arg1 = (self.arguments.theArray)[0];
      Stella_Object arg2 = (self.arguments.theArray)[1];
      Stella_Object value1 = Logic.valueOf(arg1);
      Stella_Object value2 = Logic.valueOf(arg2);
      boolean skolem1P = Stella_Object.isaP(value1, Logic.SGT_LOGIC_LOGIC_OBJECT);
      boolean skolem2P = Stella_Object.isaP(value2, Logic.SGT_LOGIC_LOGIC_OBJECT);
      Surrogate operator = ((Surrogate)(self.operator));

      if (Stella_Object.eqlP(value1, value2)) {
        if (!Stella_Object.eqlP(arg1, value1)) {
          if (!Stella_Object.eqlP(arg2, value2)) {
            IntervalCache.unifyIntervalCaches(PlKernelKb.getIntervalCache(((LogicObject)(arg1))), PlKernelKb.getIntervalCache(((LogicObject)(arg2))), PlKernelKb.SGT_PL_KERNEL_KB_el);
            IntervalCache.unifyIntervalCaches(PlKernelKb.getIntervalCache(((LogicObject)(arg1))), PlKernelKb.getIntervalCache(((LogicObject)(arg2))), Logic.SGT_PL_KERNEL_KB_ge);
            value2 = arg2;
            skolem2P = true;
          }
          else {
            PlKernelKb.getIntervalCache(((LogicObject)(arg1))).propagateInequalityToIntervalCache(value2, PlKernelKb.SGT_PL_KERNEL_KB_el);
            PlKernelKb.getIntervalCache(((LogicObject)(arg1))).propagateInequalityToIntervalCache(value2, Logic.SGT_PL_KERNEL_KB_ge);
          }
          value1 = arg1;
          skolem1P = true;
        }
        else if (!Stella_Object.eqlP(arg2, value2)) {
          if (!Stella_Object.eqlP(arg1, value1)) {
            IntervalCache.unifyIntervalCaches(PlKernelKb.getIntervalCache(((LogicObject)(arg2))), PlKernelKb.getIntervalCache(((LogicObject)(arg1))), PlKernelKb.SGT_PL_KERNEL_KB_el);
            IntervalCache.unifyIntervalCaches(PlKernelKb.getIntervalCache(((LogicObject)(arg2))), PlKernelKb.getIntervalCache(((LogicObject)(arg1))), Logic.SGT_PL_KERNEL_KB_ge);
            value1 = arg1;
            skolem1P = true;
          }
          else {
            PlKernelKb.getIntervalCache(((LogicObject)(arg2))).propagateInequalityToIntervalCache(value1, PlKernelKb.SGT_PL_KERNEL_KB_el);
            PlKernelKb.getIntervalCache(((LogicObject)(arg2))).propagateInequalityToIntervalCache(value1, Logic.SGT_PL_KERNEL_KB_ge);
          }
          value2 = arg2;
          skolem2P = true;
        }
      }
      if (skolem1P) {
        if (skolem2P) {
          IntervalCache.unifyIntervalCaches(PlKernelKb.getIntervalCache(((LogicObject)(value1))), PlKernelKb.getIntervalCache(((LogicObject)(value2))), operator);
        }
        else {
          PlKernelKb.getIntervalCache(((LogicObject)(value1))).propagateInequalityToIntervalCache(value2, operator);
        }
      }
      else {
        if (skolem2P) {
          PlKernelKb.getIntervalCache(((LogicObject)(value2))).propagateInequalityToIntervalCache(value1, PlKernelKb.inverseInequalityOperator(operator));
        }
        else {
          Proposition.evaluatePredicateProposition(self);
        }
      }
    }
  }

  public static Stella_Object concatenateConstraint(IntegerWrapper missingArgument, StringWrapper x1, StringWrapper x2, StringWrapper x3) {
    { Stella_Object value = null;

      switch (missingArgument.wrapperValue) {
        case -1: 
          value = (Stella.stringEqlP(x1.wrapperValue + x2.wrapperValue, x3.wrapperValue) ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
        break;
        case 0: 
          { String s2 = x2.wrapperValue;
            String s3 = x3.wrapperValue;
            int n = s3.length() - s2.length();

            if ((n >= 0) &&
                Stella.stringEqlP(Native.string_subsequence(s3, n, Stella.NULL_INTEGER), s2)) {
              value = StringWrapper.wrapString(Native.string_subsequence(s3, 0, n));
            }
            else {
              value = null;
            }
          }
        break;
        case 1: 
          { String s1 = x1.wrapperValue;
            String s3 = x3.wrapperValue;
            int l1 = s1.length();

            if (Stella.stringEqlP(Native.string_subsequence(s3, 0, l1), s1)) {
              value = StringWrapper.wrapString(Native.string_subsequence(s3, l1, Stella.NULL_INTEGER));
            }
            else {
              value = null;
            }
          }
        break;
        case 2: 
          value = StringWrapper.wrapString(x1.wrapperValue + x2.wrapperValue);
        break;
        default:
        break;
      }
      return (value);
    }
  }

  public static Keyword subsequenceSpecialist(ControlFrame frame, Keyword lastmove) {
    { Proposition proposition = frame.proposition;
      Stella_Object superarg = (proposition.arguments.theArray)[0];
      Stella_Object superargvalue = Logic.argumentBoundTo(superarg);
      Stella_Object p1Arg = (proposition.arguments.theArray)[1];
      Stella_Object p1Argvalue = Logic.argumentBoundTo(p1Arg);
      Stella_Object p2Arg = (proposition.arguments.theArray)[2];
      Stella_Object p2Argvalue = Logic.argumentBoundTo(p2Arg);
      Stella_Object subarg = (proposition.arguments.theArray)[3];
      Stella_Object subargvalue = Logic.argumentBoundTo(subarg);
      Iterator iterator = ((Iterator)(KeyValueList.dynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, null)));

      lastmove = lastmove;
      if (iterator == null) {
        if (superargvalue == null) {
          return (Logic.KWD_FAILURE);
        }
        else if (subargvalue == null) {
          { int p1 = Stella.NULL_INTEGER;
            int p2 = Stella.NULL_INTEGER;
            String renamed_Super = null;

            if ((p1Argvalue == null) ||
                (p2Argvalue == null)) {
              return (Logic.KWD_FAILURE);
            }
            else {
              {
                p1 = ((IntegerWrapper)(p1Argvalue)).wrapperValue;
                p2 = ((IntegerWrapper)(p2Argvalue)).wrapperValue;
                renamed_Super = StringWrapper.unwrapString(((StringWrapper)(superargvalue)));
                if ((p1 < 0) ||
                    (p2 > renamed_Super.length())) {
                  return (Logic.KWD_TERMINAL_FAILURE);
                }
                else {
                  return (Logic.selectProofResult(Logic.bindArgumentToValueP(subarg, StringWrapper.wrapString(Native.string_subsequence(renamed_Super, p1, p2)), true), false, true));
                }
              }
            }
          }
        }
        else if (p1Argvalue == null) {
          if (p2Argvalue == null) {
            {
              iterator = SubstringPositionIterator.newSubstringPositionIterator(StringWrapper.unwrapString(((StringWrapper)(superargvalue))), StringWrapper.unwrapString(((StringWrapper)(subargvalue))));
              KeyValueList.setDynamicSlotValue(frame.dynamicSlots, Logic.SYM_STELLA_ITERATOR, iterator, null);
            }
          }
          else {
            { int p2 = ((IntegerWrapper)(p2Argvalue)).wrapperValue;
              String sub = StringWrapper.unwrapString(((StringWrapper)(subargvalue)));
              int lsub = sub.length();

              if (lsub > p2) {
                return (Logic.KWD_TERMINAL_FAILURE);
              }
              else if (Stella.stringEqlP(Native.string_subsequence(StringWrapper.unwrapString(((StringWrapper)(superargvalue))), p2 - lsub, p2), sub)) {
                return (Logic.selectProofResult(Logic.bindArgumentToValueP(p1Arg, IntegerWrapper.wrapInteger(p2 - lsub), true), false, true));
              }
              else {
                return (Logic.KWD_TERMINAL_FAILURE);
              }
            }
          }
        }
        else if (p2Argvalue == null) {
          { int p1 = ((IntegerWrapper)(p1Argvalue)).wrapperValue;
            String sub = StringWrapper.unwrapString(((StringWrapper)(subargvalue)));
            int lsub = sub.length();
            String renamed_Super = StringWrapper.unwrapString(((StringWrapper)(superargvalue)));
            int lsuper = renamed_Super.length();

            if ((p1 < 0) ||
                ((p1 + lsub) > lsuper)) {
              return (Logic.KWD_TERMINAL_FAILURE);
            }
            else if (Stella.stringEqlP(sub, Native.string_subsequence(renamed_Super, p1, p1 + lsub))) {
              return (Logic.selectProofResult(Logic.bindArgumentToValueP(p2Arg, IntegerWrapper.wrapInteger(p1 + lsub), true), false, true));
            }
            else {
              return (Logic.KWD_TERMINAL_FAILURE);
            }
          }
        }
        else {
          { String superString = StringWrapper.unwrapString(((StringWrapper)(superargvalue)));
            int beginIndex = IntegerWrapper.unwrapInteger(((IntegerWrapper)(p1Argvalue)));
            int endIndex = IntegerWrapper.unwrapInteger(((IntegerWrapper)(p2Argvalue)));
            boolean matchP = (endIndex <= superString.length()) &&
                Logic.bindArgumentToValueP(subarg, StringWrapper.wrapString(Native.string_subsequence(superString, beginIndex, endIndex)), true);

            ControlFrame.setFrameTruthValue(frame, (matchP ? Logic.TRUE_TRUTH_VALUE : Logic.FALSE_TRUTH_VALUE));
            return (Logic.selectProofResult(matchP, false, true));
          }
        }
      }
      if (iterator.nextP() &&
          (Logic.bindArgumentToValueP(p1Arg, ((Cons)(iterator.value)).value, true) &&
           Logic.bindArgumentToValueP(p2Arg, ((Cons)(iterator.value)).rest.value, true))) {
        return (Logic.KWD_CONTINUING_SUCCESS);
      }
      else {
        return (Logic.KWD_TERMINAL_FAILURE);
      }
    }
  }

  public static IntegerWrapper stringMatchComputation(Stella_Object pattern, Stella_Object x, Stella_Object start, Stella_Object end) {
    if (!(Stella_Object.stringP(pattern) &&
        (Stella_Object.integerP(start) &&
         Stella_Object.integerP(end)))) {
      return (null);
    }
    { String thepattern = ((StringWrapper)(pattern)).wrapperValue;
      int thestart = ((IntegerWrapper)(start)).wrapperValue;
      int theend = ((IntegerWrapper)(end)).wrapperValue;
      String name = (Stella_Object.stringP(x) ? ((StringWrapper)(x)).wrapperValue : Logic.objectNameString(x));
      int matchposition = Stella.NULL_INTEGER;

      if ((theend >= 0) &&
          (theend <= name.length())) {
        name = Native.string_subsequence(name, thestart, theend);
      }
      matchposition = Native.stringSearch(name, thepattern, thestart);
      if (matchposition != Stella.NULL_INTEGER) {
        return (IntegerWrapper.wrapInteger(matchposition));
      }
      else {
        return (null);
      }
    }
  }

  public static IntegerWrapper lengthComputation(Stella_Object x) {
    if (Surrogate.subtypeOfStringP(Stella_Object.safePrimaryType(x))) {
      { StringWrapper x000 = ((StringWrapper)(x));

        return (IntegerWrapper.wrapInteger((x000.wrapperValue).length()));
      }
    }
    else {
      System.out.print("Length computation not yet implemented for Lists");
      return (IntegerWrapper.wrapInteger(Stella.NULL_INTEGER));
    }
  }

}
