//  -*- Mode: Java -*-
//
// PatternVariable.java

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

/** A variable in a logical expression.
 * @author Stella Java Translator
 */
public class PatternVariable extends Skolem {
    public int boundToOffset;

  public static PatternVariable newPatternVariable() {
    { PatternVariable self = null;

      self = new PatternVariable();
      self.dependentPropositionsIndex = null;
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.homeContext = ((Context)(Stella.$CONTEXT$.get()));
      self.surrogateValueInverse = null;
      self.variableValueInverse = null;
      self.definingProposition = null;
      self.variableValue = null;
      self.skolemType = null;
      self.skolemName = null;
      self.boundToOffset = Stella.NULL_INTEGER;
      LogicObject.logLogicObject(self);
      return (self);
    }
  }

  public static Skolem createSkolemForUnmappedVariable(PatternVariable variable, KeyValueList mapping) {
    { Stella_Object skolem = mapping.lookup(variable);

      if (skolem != null) {
        return (((Skolem)(skolem)));
      }
      skolem = Logic.createVariableOrSkolem(variable.skolemType, null);
      mapping.insertAt(variable, skolem);
      return (((Skolem)(skolem)));
    }
  }

  public static PatternVariable copyVariable(PatternVariable self, KeyValueList mapping) {
    { PatternVariable copy = ((PatternVariable)(mapping.lookup(self)));

      if (copy != null) {
        return (copy);
      }
      copy = Logic.createVariable(self.skolemType, self.skolemName, Stella.FALSE);
      if ((((Keyword)(Logic.$PRINTMODE$.get())) == Logic.KWD_REALISTIC) ||
          (((Keyword)(Logic.$PRINTMODE$.get())) == Logic.KWD_FLAT)) {
        copy.skolemName = self.skolemName;
      }
      else {
        { String copyname = "?CP_" + Native.string_subsequence(self.skolemName.symbolName, 1, Stella.NULL_INTEGER);

          copy.skolemName = Stella.internSymbol(copyname);
        }
      }
      copy.skolemType = self.skolemType;
      if (((Stella_Object)(Stella_Object.accessInContext(self.variableValue, self.homeContext, Stella.FALSE))) != null) {
        { PatternVariable object000 = copy;
          Stella_Object value000 = ((Stella_Object)(Stella_Object.accessInContext(self.variableValue, self.homeContext, Stella.FALSE)));
          Stella_Object oldValue002 = object000.variableValue;
          Stella_Object newValue000 = Stella_Object.updateInContext(oldValue002, value000, object000.homeContext, Stella.FALSE);

          if (!((oldValue002 != null) &&
              (oldValue002.primaryType() == Logic.SGT_STELLA_CS_VALUE))) {
            object000.variableValue = newValue000;
          }
        }
      }
      mapping.insertAt(self, copy);
      return (copy);
    }
  }

  public static void simulateBindVariableAndPropagateConstraints(PatternVariable variable, List goalsequence) {
    { GoalRecord goalrecord = PatternVariable.goalRecord(variable);

      Logic.simulateBindVariableToValue(variable);
      Logic.collectClosedGoals(goalrecord.generatorGoals, goalsequence);
      Logic.collectClosedGoals(goalrecord.otherGoals, goalsequence);
      { Proposition g = null;
        Cons iter000 = goalrecord.generatorGoals.theConsList;

        while (!(iter000 == Stella.NIL)) {
          {
            g = ((Proposition)(iter000.value));
            iter000 = iter000.rest;
          }
          Proposition.propagateSingleValuedConstraints(g, goalsequence);
        }
      }
      { Proposition g = null;
        Cons iter001 = goalrecord.otherGoals.theConsList;

        while (!(iter001 == Stella.NIL)) {
          {
            g = ((Proposition)(iter001.value));
            iter001 = iter001.rest;
          }
          Proposition.propagateSingleValuedConstraints(g, goalsequence);
        }
      }
    }
  }

  public static Proposition cheapestGeneratorGoal(PatternVariable variable, Object [] MV_returnarray) {
    if ((Stella.$TRACED_KEYWORDS$ != null) &&
        Stella.$TRACED_KEYWORDS$.membP(Logic.KWD_OPTIMIZER)) {
      {
        System.out.println();
        System.out.println("CHEAPEST: " + variable + " GENERATORS: " + PatternVariable.goalRecord(variable).generatorGoals);
      }
;
    }
    { Proposition bestgoal = null;
      double bestcost = Stella.NULL_FLOAT;
      double bestfanout = Stella.NULL_FLOAT;
      double generatorcost = Stella.NULL_FLOAT;
      double generatorfanout = Stella.NULL_FLOAT;

      { Proposition goal = null;
        Cons iter000 = PatternVariable.goalRecord(variable).generatorGoals.theConsList;

        while (!(iter000 == Stella.NIL)) {
          {
            goal = ((Proposition)(iter000.value));
            iter000 = iter000.rest;
          }
          generatorcost = Proposition.estimateGoalCost(goal);
          generatorfanout = Proposition.estimateGoalFanout(goal);
          if ((generatorfanout != Stella.NULL_FLOAT) &&
              ((bestfanout == Stella.NULL_FLOAT) ||
               ((generatorfanout < bestfanout) ||
                ((generatorfanout == bestfanout) &&
                 (generatorcost < bestcost))))) {
            if ((generatorfanout == 1.0) &&
                (generatorcost == 1.0)) {
              { Proposition _return_temp = goal;

                MV_returnarray[0] = Stella.wrapFloat(1.0);
                MV_returnarray[1] = Stella.wrapFloat(1.0);
                return (_return_temp);
              }
            }
            bestgoal = goal;
            bestfanout = generatorfanout;
            bestcost = generatorcost;
          }
        }
      }
      if (bestfanout != Stella.NULL_FLOAT) {
        {
          if ((Stella.$TRACED_KEYWORDS$ != null) &&
              Stella.$TRACED_KEYWORDS$.membP(Logic.KWD_OPTIMIZER)) {
            System.out.println("  SELECTED: " + bestgoal + "  " + bestcost + "  " + bestfanout);
          }
          { Proposition _return_temp = bestgoal;

            MV_returnarray[0] = Stella.wrapFloat(bestcost);
            MV_returnarray[1] = Stella.wrapFloat(bestfanout);
            return (_return_temp);
          }
        }
      }
      else {
        { Proposition _return_temp = null;

          MV_returnarray[0] = Stella.wrapFloat(0.0);
          MV_returnarray[1] = Stella.wrapFloat(0.0);
          return (_return_temp);
        }
      }
    }
  }

  public static GoalRecord goalRecord(PatternVariable variable) {
    return (((GoalRecord)((((ExtensibleVector)(KeyValueList.dynamicSlotValue(((QueryIterator)(Logic.$QUERYITERATOR$.get())).dynamicSlots, Logic.SYM_LOGIC_OPTIMIZER_GOAL_RECORDS, null))).theArray)[(variable.boundToOffset)])));
  }

  public static boolean variableBoundP(PatternVariable variable) {
    return (((((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentPatternRecord.variableBindings.theArray)[(variable.boundToOffset)] != null) ||
        (((Stella_Object)(Stella_Object.accessInContext(variable.variableValue, variable.homeContext, Stella.FALSE))) != null));
  }

  public static Stella_Object generateOneVariable(PatternVariable self, boolean typedP) {
    if ((((Justification)(Logic.$CURRENTJUSTIFICATION$.get())) != null) &&
        (Logic.justificationArgumentBoundTo(self, null) != null)) {
      return (Logic.generateTerm(Logic.justificationArgumentBoundTo(self, null)));
    }
    { Symbol name = PatternVariable.generateNameOfVariable(self);

      if (typedP &&
          (!(Logic.logicalType(self) == Logic.SGT_STELLA_THING))) {
        return (Stella_Object.cons(name, Stella_Object.cons(Surrogate.surrogateToSymbol(Logic.logicalType(self)), Stella.NIL)));
      }
      else {
        return (name);
      }
    }
  }

  public static Symbol generateNameOfVariable(PatternVariable self) {
    if (((KeyValueList)(Logic.$SKOLEMNAMEMAPPINGTABLE$.get())) != null) {
      { Skolem temp000 = ((Skolem)(((KeyValueList)(Logic.$SKOLEMNAMEMAPPINGTABLE$.get())).lookup(self)));

        self = ((temp000 != null) ? ((PatternVariable)(temp000)) : self);
      }
    }
    if (((KeyValueList)(Logic.$CANONICALVARIABLENAMEMAPPING$.get())) == null) {
      return (self.skolemName);
    }
    { Stella_Object canonicalname = ((KeyValueList)(Logic.$CANONICALVARIABLENAMEMAPPING$.get())).lookup(self);

      if (canonicalname == null) {
        canonicalname = ((Symbol)(Logic.SYSTEM_DEFINED_ARGUMENT_NAMES.nth(Native.setIntSpecial(Logic.$CANONICALVARIABLECOUNTER$, ((Integer)(Logic.$CANONICALVARIABLECOUNTER$.get())).intValue() + 1))));
        ((KeyValueList)(Logic.$CANONICALVARIABLENAMEMAPPING$.get())).insertAt(self, canonicalname);
      }
      return (((Symbol)(canonicalname)));
    }
  }

  public static void printQuantifiedVariable(PatternVariable self, OutputStream stream) {
    PatternVariable.printVariable(self, stream);
  }

  public static void printVariable(PatternVariable self, OutputStream stream) {
    if ((((Justification)(Logic.$CURRENTJUSTIFICATION$.get())) != null) &&
        (Logic.justificationArgumentBoundTo(self, null) != null)) {
      Logic.prettyPrintLogicalForm(Logic.justificationArgumentBoundTo(self, null), stream);
      return;
    }
    { Stella_Object value = ((((ControlFrame)(Logic.$PRINTINFRAME$.get())) != null) ? PatternVariable.boundToInFrame(self, ((ControlFrame)(Logic.$PRINTINFRAME$.get()))) : PatternVariable.safeBoundTo(self));

      if (value != null) {
        PatternVariable.printVariableName(self, stream);
        stream.nativeStream.print(Logic.VARIABLE_BINDING_SEPARATOR);
        { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

          try {
            Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
            Logic.printVariableValue(value, stream);
            return;

          } finally {
            Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
          }
        }
      }
    }
    Skolem.printValueOfChain(self, stream, Logic.innermostOf(self));
  }

  public static void printVariableName(PatternVariable self, OutputStream stream) {
    Skolem.printSkolemName(self, stream);
  }

  public static void printKifVariable(PatternVariable self) {
    { OutputStream stream = ((OutputStream)(Logic.$PRINTLOGICALFORMSTREAM$.get()));

      PatternVariable.printVariable(self, stream);
    }
  }

  public static int hashUnboundGoalVariable(PatternVariable var, Vector arguments, int code) {
    { int varindex = 1;

      { int i = Stella.NULL_INTEGER;
        Stella_Object arg = null;
        Vector vector000 = arguments;
        int index000 = 0;
        int length000 = vector000.length();
        int iter000 = 0;

        while (index000 < length000) {
          {
            arg = (vector000.theArray)[index000];
            index000 = index000 + 1;
          }
          {
            i = iter000;
            iter000 = iter000 + 1;
          }
          if (var == arg) {
            return (Stella.hashString("#v", code + varindex));
          }
          else if (Stella_Object.isaP(arg, Logic.SGT_LOGIC_PATTERN_VARIABLE) &&
              (arguments.position(arg, 0) == i)) {
            varindex = varindex + 1;
          }
        }
      }
      throw ((StellaException)(StellaException.newStellaException("Shouldn't get here!").fillInStackTrace()));
    }
  }

  public static void printOneVariableBinding(PatternVariable variable) {
    System.out.print(variable.skolemName + "=");
    if (variable.boundToOffset != Stella.NULL_INTEGER) {
      { Stella_Object value = ((((ControlFrame)(Logic.$PRINTINFRAME$.get())) != null) ? PatternVariable.boundToInFrame(variable, ((ControlFrame)(Logic.$PRINTINFRAME$.get()))) : PatternVariable.safeBoundTo(variable));

        Logic.printUnformattedLogicalForm(value, Stella.STANDARD_OUTPUT);
      }
    }
    else {
      System.out.print(Logic.SYM_STELLA_NULL);
    }
    System.out.print(" ");
  }

  public static boolean bindVariableToValueP(PatternVariable variable, Stella_Object value, boolean autocleanupP) {
    if (value == null) {
      if (((((QueryIterator)(Logic.$QUERYITERATOR$.get())) != null) &&
          (((QueryIterator)(Logic.$QUERYITERATOR$.get())).partialMatchStrategy != null)) &&
          ((QueryIterator)(Logic.$QUERYITERATOR$.get())).partialMatchStrategy.allowUnboundVariablesP()) {
        return (Stella.TRUE);
      }
      { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

        try {
          Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
          Stella.STANDARD_WARNING.nativeStream.println("WARNING: Tried to bind " + variable + " to NULL value.  Potentially a PowerLoom bug");
          Logic.helpSignalPropositionError(Stella.STANDARD_WARNING, Logic.KWD_WARNING);

        } finally {
          Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
        }
      }
      return (Stella.FALSE);
    }
    if (autocleanupP) {
      { PatternRecord patternrecord = ((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentPatternRecord;
        int ubstackoffset = patternrecord.topUnbindingStackOffset;
        boolean successP = Stella.FALSE;

        successP = PatternVariable.helpBindVariableToValueP(variable, value);
        if (!successP) {
          PatternRecord.unbindVariablesBeginningAt(patternrecord, ubstackoffset + 1);
        }
        return (successP);
      }
    }
    else {
      return (PatternVariable.helpBindVariableToValueP(variable, value));
    }
  }

  public static boolean helpBindVariableToValueP(PatternVariable variable, Stella_Object value) {
    if (((Keyword)(Logic.$TYPE_CHECK_STRATEGY$.get())) == Logic.KWD_LOOKUP) {
      { boolean typeisokP = Stella.FALSE;

        { Object [] caller_MV_returnarray = new Object[1];

          typeisokP = Logic.checkTypeP(value, variable.skolemType, Stella.TRUE, caller_MV_returnarray);
          value = ((Stella_Object)(caller_MV_returnarray[0]));
        }
        if ((!typeisokP) &&
            Description.nonInferableP(Logic.surrogateToDescription(variable.skolemType))) {
          if ((Stella.$TRACED_KEYWORDS$ != null) &&
              Stella.$TRACED_KEYWORDS$.membP(Logic.KWD_PERFORMANCE_CLUES)) {
            System.out.println("TYPE CHECK VIOLATION in 'bind-variable-to-value?'.  Type= " + variable.skolemType + " Value= " + value);
          }
          return (Stella.FALSE);
        }
      }
    }
    else if (((Keyword)(Logic.$TYPE_CHECK_STRATEGY$.get())) == Logic.KWD_NONE) {
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + ((Keyword)(Logic.$TYPE_CHECK_STRATEGY$.get())) + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
    { Stella_Object boundtovalue = (((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentPatternRecord.variableBindings.theArray)[(variable.boundToOffset)];
      Stella_Object variablevalue = ((Stella_Object)(Stella_Object.accessInContext(variable.variableValue, variable.homeContext, Stella.FALSE)));

      Logic.elaborateInstance(value);
      if ((variablevalue != null) &&
          (boundtovalue == null)) {
        variablevalue = Logic.valueOf(variablevalue);
        PatternVariable.setPatternVariableBinding(variable, variablevalue);
        return (Stella_Object.eqlP(variablevalue, value));
      }
      else if (boundtovalue == null) {
        PatternVariable.setPatternVariableBinding(variable, value);
      }
      else if (Stella_Object.equalP(boundtovalue, value)) {
        return (Stella.TRUE);
      }
      else {
        return (Stella.FALSE);
      }
      return (Stella.TRUE);
    }
  }

  public static boolean failsAntecedentTypeCheckP(PatternVariable v1, Stella_Object i2) {
    if (((Keyword)(Logic.$TYPE_CHECK_STRATEGY$.get())) == Logic.KWD_LOOKUP) {
      { Surrogate type = v1.skolemType;
        boolean typeisokP = Logic.checkTypeP(i2, type, Stella.TRUE, new Object[1]);

        if ((!typeisokP) &&
            Description.nonInferableP(Logic.surrogateToDescription(type))) {
          return (Stella.TRUE);
        }
        else {
          return (Stella.FALSE);
        }
      }
    }
    else if (((Keyword)(Logic.$TYPE_CHECK_STRATEGY$.get())) == Logic.KWD_NONE) {
      return (Stella.FALSE);
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + ((Keyword)(Logic.$TYPE_CHECK_STRATEGY$.get())) + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public static boolean failsUnificationTypeCheckP(PatternVariable v1, Stella_Object i2) {
    if (((Keyword)(Logic.$TYPE_CHECK_STRATEGY$.get())) == Logic.KWD_NONE) {
      return (Stella.FALSE);
    }
    else if (((Keyword)(Logic.$TYPE_CHECK_STRATEGY$.get())) == Logic.KWD_LOOKUP) {
      { Surrogate type = v1.skolemType;
        boolean typeisokP = Logic.checkTypeP(i2, type, Stella.TRUE, new Object[1]);

        if ((!typeisokP) &&
            Description.nonInferableP(Logic.surrogateToDescription(type))) {
          return (Stella.TRUE);
        }
        else {
          return (Stella.FALSE);
        }
      }
    }
    else if (((Keyword)(Logic.$TYPE_CHECK_STRATEGY$.get())) == Logic.KWD_SHALLOW_DISJOINT) {
      if ((v1.skolemType != null) &&
          NamedDescription.disjointClassesP(Logic.getDescription(v1.skolemType), Logic.getDescription(Logic.logicalType(i2)))) {
        return (Stella.TRUE);
      }
      return (Stella.FALSE);
    }
    else if (((Keyword)(Logic.$TYPE_CHECK_STRATEGY$.get())) == Logic.KWD_DISJOINT) {
      { Surrogate type1 = null;
        Surrogate type2 = null;

        { Proposition p = null;
          Iterator iter000 = Logic.unfilteredDependentIsaPropositions(v1).allocateIterator();

          loop000 : while (iter000.nextP()) {
            p = ((Proposition)(iter000.value));
            if (p.kind == Logic.KWD_ISA) {
              type1 = ((Surrogate)((p.arguments.theArray)[1]));
              break loop000;
            }
          }
        }
        if (type1 == null) {
          return (Stella.FALSE);
        }
        if (Surrogate.subtypeOfP(Stella_Object.safePrimaryType(i2), Logic.SGT_LOGIC_LOGIC_OBJECT)) {
          { LogicObject i2000 = ((LogicObject)(i2));

            { Proposition p = null;
              Iterator iter001 = Logic.unfilteredDependentIsaPropositions(i2000).allocateIterator();

              loop001 : while (iter001.nextP()) {
                p = ((Proposition)(iter001.value));
                if (p.kind == Logic.KWD_ISA) {
                  type2 = ((Surrogate)((p.arguments.theArray)[1]));
                  break loop001;
                }
              }
            }
          }
        }
        else {
          type2 = Logic.logicalType(i2);
        }
        if (type2 == null) {
          return (Stella.FALSE);
        }
        return (NamedDescription.disjointClassesP(Logic.getDescription(type1), Logic.getDescription(type2)));
      }
    }
    else {
      { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

        stream000.nativeStream.print("`" + ((Keyword)(Logic.$TYPE_CHECK_STRATEGY$.get())) + "' is not a valid case option");
        throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
      }
    }
  }

  public static Stella_Object boundToInRecord(PatternVariable self, PatternRecord record) {
    return ((record.variableBindings.theArray)[(self.boundToOffset)]);
  }

  public static Stella_Object boundToInFrame(PatternVariable self, ControlFrame frame) {
    { Vector bindings = ControlFrame.operativePatternRecord(frame).variableBindings;
      int offset = self.boundToOffset;

      if ((bindings != null) &&
          ((offset != Stella.NULL_INTEGER) &&
           (offset < bindings.length()))) {
        return ((bindings.theArray)[offset]);
      }
      else {
        return (null);
      }
    }
  }

  public static Stella_Object safeBoundTo(PatternVariable self) {
    if (((QueryIterator)(Logic.$QUERYITERATOR$.get())) != null) {
      { Vector bindings = ((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentPatternRecord.variableBindings;
        int offset = self.boundToOffset;

        if ((bindings != null) &&
            ((offset != Stella.NULL_INTEGER) &&
             (offset < bindings.length()))) {
          return ((bindings.theArray)[offset]);
        }
      }
    }
    return (null);
  }

  public static Stella_Object boundTo(PatternVariable self) {
    return ((((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentPatternRecord.variableBindings.theArray)[(self.boundToOffset)]);
  }

  public static void setPatternVariableBinding(PatternVariable variable, Stella_Object value) {
    if ((Stella.$TRACED_KEYWORDS$ != null) &&
        Stella.$TRACED_KEYWORDS$.membP(Logic.KWD_QUERY_STACKS)) {
      System.out.println("set-pattern-variable-binding: " + variable + " " + value + "  F" + ControlFrame.debugFrameId(((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentPatternRecord.controlFrame));
    }
    { PatternRecord patternrecord = ((QueryIterator)(Logic.$QUERYITERATOR$.get())).currentPatternRecord;
      int vboffset = variable.boundToOffset;
      int ubstackoffset = patternrecord.topUnbindingStackOffset + 1;

      (patternrecord.variableBindings.theArray)[vboffset] = value;
      patternrecord.topUnbindingStackOffset = ubstackoffset;
      (patternrecord.unbindingStack.theArray)[ubstackoffset] = (Stella.wrapInteger(vboffset));
    }
  }

  public static PatternVariable renameLogicVariableApart(PatternVariable variable, boolean destructiveP) {
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, variable.homeModule());
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        { Symbol newname = Stella.localGensym(variable.skolemName.symbolName);

          if (!(destructiveP)) {
            variable = PatternVariable.copyVariable(variable, KeyValueList.newKeyValueList());
          }
          variable.skolemName = newname;
          return (variable);
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

  public static void addVariableType(PatternVariable variable, Surrogate newtype, KeyValueList table, Cons visiblevariables) {
    if (!visiblevariables.memberP(variable)) {
      return;
    }
    { List types = ((List)(table.lookup(variable)));

      if (types == null) {
        table.insertAt(variable, Stella.list(Stella_Object.cons(newtype, Stella.NIL)));
      }
      else {
        {
          { Surrogate t = null;
            Cons iter000 = types.theConsList;

            while (!(iter000 == Stella.NIL)) {
              {
                t = ((Surrogate)(iter000.value));
                iter000 = iter000.rest;
              }
              if (Logic.logicalSubtypeOfP(t, newtype)) {
                return;
              }
              if (Logic.logicalSubtypeOfP(newtype, t)) {
                types.remove(t);
                PatternVariable.addVariableType(variable, newtype, table, visiblevariables);
                return;
              }
            }
          }
          types.insert(newtype);
        }
      }
      Native.setBooleanSpecial(Logic.$ADDEDNEWTYPEp$, Stella.TRUE);
    }
  }

  public static boolean freeVariableP(PatternVariable variable, Proposition proposition) {
    { Keyword testValue000 = proposition.kind;

      if ((testValue000 == Logic.KWD_FORALL) ||
          (testValue000 == Logic.KWD_EXISTS)) {
        if (((Vector)(KeyValueList.dynamicSlotValue(proposition.dynamicSlots, Logic.SYM_LOGIC_IO_VARIABLES, null))).memberP(variable)) {
          return (Stella.FALSE);
        }
      }
      else {
      }
    }
    { boolean alwaysP000 = Stella.TRUE;

      { Stella_Object arg = null;
        Vector vector000 = proposition.arguments;
        int index000 = 0;
        int length000 = vector000.length();

        loop000 : while (index000 < length000) {
          {
            arg = (vector000.theArray)[index000];
            index000 = index000 + 1;
          }
          if (Stella_Object.isaP(arg, Logic.SGT_LOGIC_PROPOSITION)) {
            if (!PatternVariable.freeVariableP(variable, ((Proposition)(arg)))) {
              alwaysP000 = Stella.FALSE;
              break loop000;
            }
          }
        }
      }
      { boolean value000 = alwaysP000;

        return (value000);
      }
    }
  }

  public static boolean topLevelExistentialVariableP(PatternVariable variable, Description description) {
    return ((!description.ioVariables.memberP(variable)) &&
        (description.internalVariables.memberP(variable) &&
         PatternVariable.freeVariableP(variable, description.proposition)));
  }

  public static PatternVariable innermostVariableOf(PatternVariable self) {
    for (;;) {
      { PatternVariable tightestvariable = self;
        Stella_Object value = null;

        for (;;) {
          value = ((Stella_Object)(Stella_Object.accessInContext(tightestvariable.variableValue, tightestvariable.homeContext, Stella.FALSE)));
          if ((value != null) &&
              Logic.variableP(value)) {
            tightestvariable = ((PatternVariable)(value));
          }
          else {
            return (tightestvariable);
          }
        }
      }
    }
  }

  public static Stella_Object accessPatternVariableSlotValue(PatternVariable self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Logic.SYM_LOGIC_BOUND_TO_OFFSET) {
      if (setvalueP) {
        self.boundToOffset = ((IntegerWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapInteger(self.boundToOffset);
      }
    }
    else if (slotname == Logic.SYM_STELLA_VARIABLE_NAME) {
      if (setvalueP) {
        self.skolemName = ((Symbol)(value));
      }
      else {
        value = self.skolemName;
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
    { PatternVariable self = this;

      return (Logic.SGT_LOGIC_PATTERN_VARIABLE);
    }
  }

}

