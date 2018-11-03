//  -*- Mode: Java -*-
//
// Surrogate.java

/*--------------------------- BEGIN LICENSE BLOCK ---------------------------+
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
| The Original Code is the STELLA Programming Language.                      |
|                                                                            |
| The Initial Developer of the Original Code is                              |
| UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
| 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
|                                                                            |
| Portions created by the Initial Developer are Copyright (C) 1996-2003      |
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
+---------------------------- END LICENSE BLOCK ----------------------------*/

package edu.isi.stella;

import edu.isi.stella.javalib.*;

/** Rigid surrogate.
 * @author Stella Java Translator
 */
public class Surrogate extends GeneralizedSymbol {
    public Stella_Object surrogateValue;

  public static Surrogate newSurrogate(String symbolName) {
    { Surrogate self = null;

      self = new Surrogate();
      self.symbolName = symbolName;
      self.homeContext = ((Context)(Stella.$CONTEXT$.get()));
      self.symbolId = Stella.NULL_INTEGER;
      self.surrogateValue = null;
      return (self);
    }
  }

  public void idlOutputLiteral() {
    { Surrogate surrogate = this;

      ((OutputStream)(Stella.$CURRENT_STREAM$.get())).nativeStream.print(Surrogate.idlTranslateSurrogateName(surrogate).wrapperValue);
    }
  }

  public static StringWrapper idlTranslateSurrogateId(Surrogate surrogate) {
    return (GeneralizedSymbol.idlTranslateSymbolConstantId(surrogate));
  }

  public static StringWrapper idlTranslateSurrogateName(Surrogate surrogate) {
    return (GeneralizedSymbol.idlTranslateSymbolConstantName(surrogate));
  }

  public void javaOutputLiteral() {
    { Surrogate surrogate = this;

      ((OutputStream)(Stella.$CURRENT_STREAM$.get())).nativeStream.print(Surrogate.javaTranslateSurrogateName(surrogate).wrapperValue);
    }
  }

  public static Cons javaTranslateDefinedOrNull(Surrogate classtype, Stella_Object renamed_Object, boolean nullP) {
    { String operator = (nullP ? "==" : "!=");

      if (Surrogate.subtypeOfP(classtype, Stella.SGT_STELLA_OBJECT)) {
        return (Cons.javaTranslateOperatorCall(Stella_Object.cons(Stella.wrapString(operator), Stella.NIL), Stella_Object.cons(renamed_Object, Stella_Object.cons(Stella.SYM_STELLA_NULL, Stella.NIL)), 2));
      }
      else if (Surrogate.subtypeOfP(classtype, Stella.SGT_STELLA_INTEGER)) {
        return (Cons.javaTranslateOperatorCall(Stella_Object.cons(Stella.wrapString(operator), Stella.NIL), Stella_Object.cons(renamed_Object, Stella_Object.cons(Stella.SYM_STELLA_NULL_INTEGER, Stella.NIL)), 2));
      }
      else if (Surrogate.subtypeOfP(classtype, Stella.SGT_STELLA_FLOAT)) {
        return (Cons.javaTranslateOperatorCall(Stella_Object.cons(Stella.wrapString(operator), Stella.NIL), Stella_Object.cons(renamed_Object, Stella_Object.cons(Stella.SYM_STELLA_NULL_FLOAT, Stella.NIL)), 2));
      }
      else if (Surrogate.subtypeOfP(classtype, Stella.SGT_STELLA_SINGLE_FLOAT)) {
        return (Cons.javaTranslateOperatorCall(Stella_Object.cons(Stella.wrapString(operator), Stella.NIL), Stella_Object.cons(renamed_Object, Stella_Object.cons(Stella.SYM_STELLA_NULL_SINGLE_FLOAT, Stella.NIL)), 2));
      }
      else if (Surrogate.subtypeOfP(classtype, Stella.SGT_STELLA_CHARACTER)) {
        return (Cons.javaTranslateOperatorCall(Stella_Object.cons(Stella.wrapString(operator), Stella.NIL), Stella_Object.cons(renamed_Object, Stella_Object.cons(Stella.SYM_STELLA_NULL_CHARACTER, Stella.NIL)), 2));
      }
      else {
        return (Cons.javaTranslateOperatorCall(Stella_Object.cons(Stella.wrapString(operator), Stella.NIL), Stella_Object.cons(renamed_Object, Stella_Object.cons(Stella.SYM_STELLA_NULL, Stella.NIL)), 2));
      }
    }
  }

  public static StringWrapper javaTranslateSurrogateId(Surrogate surrogate) {
    return (GeneralizedSymbol.javaTranslateSymbolConstantId(surrogate));
  }

  public static StringWrapper javaTranslateSurrogateName(Surrogate surrogate) {
    return (GeneralizedSymbol.javaTranslateSymbolConstantName(surrogate));
  }

  public void cppOutputLiteral() {
    { Surrogate surrogate = this;

      ((OutputStream)(Stella.$CURRENT_STREAM$.get())).nativeStream.print(Surrogate.cppTranslateSurrogateName(surrogate).wrapperValue);
    }
  }

  public static Cons cppTranslateDefinedPMethodCall(Surrogate argumenttype, Stella_Object argument, boolean nullP) {
    { Stella_Object nullvalue = Surrogate.typeToWalkedNullValueTree(argumenttype);

      if (Stella.optimizeBooleanTestsP() &&
          Surrogate.subtypeOfP(argumenttype, Stella.SGT_STELLA_OBJECT)) {
        argument = Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_CAST, Stella_Object.cons(argument, Stella_Object.cons(Stella_Object.cons(Stella.SGT_STELLA_BOOLEAN, Stella.NIL), Stella.NIL))));
        if (nullP) {
          return (Cons.cppTranslateOperatorCall(Symbol.cppLookupOperatorTable(Stella.SYM_STELLA_NOT), Stella_Object.cons(argument, Stella.NIL), 1));
        }
        else {
          return (((Cons)(Stella_Object.cppTranslateATree(argument))));
        }
      }
      else {
        return (Cons.cppTranslateOperatorCall(Symbol.cppLookupOperatorTable((nullP ? Stella.SYM_STELLA_EQp : Stella.SYM_STELLA_xe)), Stella_Object.cons(argument, Stella_Object.cons(nullvalue, Stella.NIL)), 2));
      }
    }
  }

  public static StringWrapper cppTranslateSurrogateId(Surrogate surrogate) {
    return (GeneralizedSymbol.cppTranslateSymbolConstantId(surrogate));
  }

  public static StringWrapper cppTranslateSurrogateName(Surrogate surrogate) {
    return (GeneralizedSymbol.cppTranslateSymbolConstantName(surrogate));
  }

  public Cons cppTranslateAtomicTree() {
    { Surrogate tree = this;

      if (Stella.useHardcodedSymbolsP()) {
        return (Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_CPP_SYMBOL, Stella_Object.cons(tree, Stella_Object.cons(Stella.NIL, Stella.NIL)))));
      }
      else {
        return (GeneralizedSymbol.yieldSymbolConstantName(tree).cppTranslateAtomicTree());
      }
    }
  }

  public static void initializeMemoizationTable(Surrogate memotablesurrogate, String options) {
    { PropertyList self000 = PropertyList.newPropertyList();

      self000.thePlist = ((Cons)(Stella.readSExpressionFromString(options)));
      { PropertyList theoptions = self000;
        Stella_Object oldtable = memotablesurrogate.surrogateValue;
        IntegerWrapper size = ((IntegerWrapper)(theoptions.lookup(Stella.KWD_MAX_VALUES)));

        { MemoizationTable chooseValue000 = null;

          if (size != null) {
            { MruMemoizationTable self001 = MruMemoizationTable.newMruMemoizationTable();

              self001.maxEntries = size.wrapperValue;
              chooseValue000 = self001;
            }
          }
          else {
            chooseValue000 = MemoizationTable.newMemoizationTable();
          }
          { MemoizationTable table = chooseValue000;

            table.tableName = memotablesurrogate;
            if (theoptions.lookup(Stella.KWD_TIMESTAMPS) != null) {
              table.timestamps = ((Cons)(theoptions.lookup(Stella.KWD_TIMESTAMPS)));
            }
            Stella.$ALL_MEMOIZATION_TABLES$.remove(((MemoizationTable)(oldtable)));
            Stella.$ALL_MEMOIZATION_TABLES$.insert(table);
            memotablesurrogate.surrogateValue = table;
          }
        }
      }
    }
  }

  public static Stella_Object yieldStructSlotAccessorName(Surrogate classtype, Symbol slotname) {
    return (Module.yieldGlobalLispSymbol(((Module)(classtype.homeContext)), "%" + classtype.symbolName + "." + slotname.symbolName));
  }

  public Stella_Object clTranslateAtomicTree() {
    { Surrogate tree = this;

      if (Stella.useHardcodedSymbolsP()) {
        { IntegerWrapper offset = Stella.wrapInteger(tree.symbolId);

          return (Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_GET_SGT, Stella_Object.cons(offset, Stella_Object.cons(Stella.NIL, Stella.NIL)))));
        }
      }
      else {
        return (Symbol.clTranslateGlobalSymbol(GeneralizedSymbol.yieldSymbolConstantName(tree)));
      }
    }
  }

  public static Surrogate moreGeneralNumericType(Surrogate type1, Surrogate type2) {
    { int position1 = Stella.$NUMERIC_TYPE_HIERARCHY$.position(type1, 0);
      int position2 = Stella.$NUMERIC_TYPE_HIERARCHY$.position(type2, 0);

      if ((position1 == Stella.NULL_INTEGER) ||
          (position2 == Stella.NULL_INTEGER)) {
        return (Stella.SGT_STELLA_NUMBER);
      }
      if (position1 > position2) {
        return (type1);
      }
      else {
        return (type2);
      }
    }
  }

  public static void verifyTypecaseClauseType(Surrogate testtype, Surrogate clausetype, List precedingclausetypes, Cons clause) {
    { Surrogate shadowingtype = null;
      Surrogate wrappedclausetype = clausetype.typeToWrappedType();

      if (wrappedclausetype != null) {
        clausetype = wrappedclausetype;
      }
      if (Surrogate.unknownTypeP(clausetype)) {
        {
          { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

            try {
              Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
              Stella.signalTranslationError();
              if (!(Stella.suppressWarningsP())) {
                Stella.printErrorContext(">> ERROR: ", Stella.STANDARD_ERROR);
                {
                  Stella.STANDARD_ERROR.nativeStream.println();
                  Stella.STANDARD_ERROR.nativeStream.println(" Reference to undefined or unwrappable non-object type in `typecase': `" + Stella_Object.deUglifyParseTree(clausetype) + "'.");
                }
;
              }

            } finally {
              Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
            }
          }
        }
      }
      else {
        if ((!(testtype == Stella.SGT_STELLA_UNKNOWN)) &&
            (!StandardObject.subTypeSpecOfP(clausetype, testtype))) {
          {
            { Object old$PrintreadablyP$001 = Stella.$PRINTREADABLYp$.get();

              try {
                Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
                Stella.signalTranslationWarning();
                if (!(Stella.suppressWarningsP())) {
                  Stella.printErrorContext(">> WARNING: ", Stella.STANDARD_WARNING);
                  {
                    Stella.STANDARD_WARNING.nativeStream.println();
                    Stella.STANDARD_WARNING.nativeStream.println(" Type `" + Stella_Object.deUglifyParseTree(clausetype) + "' of `typecase' clause ");
                    Stella.STANDARD_WARNING.nativeStream.println("    `" + Stella_Object.deUglifyParseTree(clause) + "'");
                    Stella.STANDARD_WARNING.nativeStream.println(" is not a subtype of the test expression type `" + Stella_Object.deUglifyParseTree(testtype) + "'.");
                  }
;
                }

              } finally {
                Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$001);
              }
            }
          }
        }
        else {
          { 
            { Surrogate value000 = null;

              { Surrogate type = null;
                Cons iter000 = precedingclausetypes.theConsList;

                loop000 : while (!(iter000 == Stella.NIL)) {
                  {
                    type = ((Surrogate)(iter000.value));
                    iter000 = iter000.rest;
                  }
                  if (Surrogate.subtypeOfP(clausetype, type)) {
                    value000 = type;
                    break loop000;
                  }
                }
              }
              shadowingtype = value000;
            }
            if (shadowingtype != null) {
              {
                { Object old$PrintreadablyP$002 = Stella.$PRINTREADABLYp$.get();

                  try {
                    Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
                    Stella.signalTranslationWarning();
                    if (!(Stella.suppressWarningsP())) {
                      Stella.printErrorContext(">> WARNING: ", Stella.STANDARD_WARNING);
                      {
                        Stella.STANDARD_WARNING.nativeStream.println();
                        Stella.STANDARD_WARNING.nativeStream.println(" Type `" + Stella_Object.deUglifyParseTree(clausetype) + "' of `typecase' clause ");
                        Stella.STANDARD_WARNING.nativeStream.println("    `" + Stella_Object.deUglifyParseTree(clause) + "'");
                        Stella.STANDARD_WARNING.nativeStream.println(" is shadowed by type `" + Stella_Object.deUglifyParseTree(shadowingtype) + "'.");
                      }
;
                    }

                  } finally {
                    Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$002);
                  }
                }
              }
            }
            else {
              {
                precedingclausetypes.push(clausetype);
              }
            }
          }
        }
      }
    }
  }

  public static Cons yieldSubtypeOfPCaseTest(Surrogate casekey, Stella_Object testexpression) {
    { Cons entry = null;
      Cons iter000 = Stella.$TYPE_PREDICATE_TABLE$;

      while (!(iter000 == Stella.NIL)) {
        {
          entry = ((Cons)(iter000.value));
          iter000 = iter000.rest;
        }
        if (entry.value == casekey) {
          return (Stella_Object.cons(entry.rest.rest.value, Stella_Object.cons(Stella_Object.copyConsTree(testexpression), Stella.NIL)));
        }
      }
    }
    return (Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SUBTYPE_OFp, Stella_Object.cons(Stella_Object.copyConsTree(testexpression), Stella_Object.cons(Stella_Object.cons(casekey, Stella.NIL), Stella.NIL)))));
  }

  public static Cons yieldIsaPCaseTest(Surrogate casekey, Stella_Object testexpression) {
    { Cons entry = null;
      Cons iter000 = Stella.$TYPE_PREDICATE_TABLE$;

      while (!(iter000 == Stella.NIL)) {
        {
          entry = ((Cons)(iter000.value));
          iter000 = iter000.rest;
        }
        if (entry.value == casekey) {
          return (Stella_Object.cons(entry.rest.value, Stella_Object.cons(Stella_Object.copyConsTree(testexpression), Stella.NIL)));
        }
      }
    }
    return (Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_ISAp, Stella_Object.cons(Stella_Object.copyConsTree(testexpression), Stella_Object.cons(Stella_Object.cons(casekey, Stella.NIL), Stella.NIL)))));
  }

  public Stella_Object walkAtomicTree(Object [] MV_returnarray) {
    { Surrogate self = this;

      GeneralizedSymbol.registerSymbol(self);
      { Stella_Object _return_temp = self;

        MV_returnarray[0] = Stella.SGT_STELLA_SURROGATE;
        return (_return_temp);
      }
    }
  }

  public static boolean safeSubtypeOfP(Surrogate subtype, Surrogate supertype) {
    Surrogate.verifyType(subtype);
    Surrogate.verifyType(supertype);
    return (Surrogate.subtypeOfP(subtype, supertype));
  }

  public static Surrogate verifyType(Surrogate self) {
    if ((self.surrogateValue != null) &&
        (!Stella_Object.stellaClassP(self.surrogateValue))) {
      {
        Stella.STANDARD_WARNING.nativeStream.println("Warning: Illegal object `" + self.surrogateValue + "' found");
        Stella.STANDARD_WARNING.nativeStream.println("   where STELLA class expected");
        Stella.STANDARD_WARNING.nativeStream.println();
      }
;
      self.surrogateValue = ((Stella_Class)(Stella.SGT_STELLA_UNKNOWN.surrogateValue));
    }
    if (Stella.translatingCodeP() &&
        ((((Stella_Class)(self.surrogateValue)) == null) ||
         (((Stella_Class)(self.surrogateValue)) == ((Stella_Class)(Stella.SGT_STELLA_UNKNOWN.surrogateValue))))) {
      { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

        try {
          Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
          Stella.signalTranslationWarning();
          if (!(Stella.suppressWarningsP())) {
            Stella.printErrorContext(">> WARNING: ", Stella.STANDARD_OUTPUT);
            {
              System.out.println();
              System.out.println(" Reference to undefined class `" + self.symbolName + "'.");
            }
;
          }

        } finally {
          Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
        }
      }
      self.surrogateValue = ((Stella_Class)(Stella.SGT_STELLA_UNKNOWN.surrogateValue));
    }
    return (self);
  }

  public static Stella_Object lookupCoersionMethod(Surrogate sourcetype, Surrogate targettype, Stella_Object expression) {
    expression = expression;
    sourcetype = Surrogate.canonicalType(sourcetype);
    { Cons triple = null;
      Cons iter000 = Stella.$COERSION_TABLE$;

      while (!(iter000 == Stella.NIL)) {
        {
          triple = ((Cons)(iter000.value));
          iter000 = iter000.rest;
        }
        if (Surrogate.subtypeOfP(sourcetype, ((Surrogate)(triple.value))) &&
            Surrogate.subtypeOfP(((Surrogate)(triple.rest.value)), targettype)) {
          return (triple.rest.rest.value);
        }
      }
    }
    return (null);
  }

  /** Return the wrapped type for the type <code>self</code>,
   * or 'self' if it is not a bare literal type.
   * @return Surrogate
   */
  public Surrogate typeToWrappedType() {
    { Surrogate self = this;

      if (((Stella_Class)(self.surrogateValue)) == null) {
        { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

          try {
            Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
            Stella.signalTranslationError();
            if (!(Stella.suppressWarningsP())) {
              Stella.printErrorContext(">> ERROR: ", Stella.STANDARD_ERROR);
              {
                Stella.STANDARD_ERROR.nativeStream.println();
                Stella.STANDARD_ERROR.nativeStream.println(" Can't find a class named `" + Stella_Object.deUglifyParseTree(self) + "'.");
              }
;
            }

          } finally {
            Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
          }
        }
        return (Stella.SGT_STELLA_UNKNOWN);
      }
      if (Surrogate.subtypeOfP(self, Stella.SGT_STELLA_OBJECT)) {
        return (self);
      }
      { Cons entry = null;
        Cons iter000 = Stella.$WRAPPED_TYPE_TABLE$;

        while (!(iter000 == Stella.NIL)) {
          {
            entry = ((Cons)(iter000.value));
            iter000 = iter000.rest;
          }
          if (entry.rest.value == self) {
            return (((Surrogate)(entry.value)));
          }
        }
      }
      { Surrogate realtype = ((Stella_Class)(self.surrogateValue)).classType;

        if (!(self == realtype)) {
          { Cons entry = null;
            Cons iter001 = Stella.$WRAPPED_TYPE_TABLE$;

            while (!(iter001 == Stella.NIL)) {
              {
                entry = ((Cons)(iter001.value));
                iter001 = iter001.rest;
              }
              if (entry.rest.value == realtype) {
                return (((Surrogate)(entry.value)));
              }
            }
          }
        }
      }
      return (null);
    }
  }

  /** Return the unwrapped type for the wrapped type <code>self</code>,
   * or <code>self</code> if it is not a wrapped type.
   * @param self
   * @return Surrogate
   */
  public static Surrogate wrappedTypeToType(Surrogate self) {
    { Cons entry = null;
      Cons iter000 = Stella.$WRAPPED_TYPE_TABLE$;

      while (!(iter000 == Stella.NIL)) {
        {
          entry = ((Cons)(iter000.value));
          iter000 = iter000.rest;
        }
        if (entry.value == self) {
          return (((Surrogate)(entry.rest.value)));
        }
      }
    }
    return (self);
  }

  public static boolean useVectorStyleIterationP(Surrogate collectiontype) {
    return ((collectiontype == Stella.SGT_STELLA_STRING) ||
        ((collectiontype == Stella.SGT_STELLA_MUTABLE_STRING) ||
         (Surrogate.safeSubtypeOfP(collectiontype, Stella.SGT_STELLA_VECTOR) ||
          (Surrogate.safeSubtypeOfP(collectiontype, Stella.SGT_STELLA_SEQUENCE_MIXIN) &&
           (Stella_Class.lookupSlot(((Stella_Class)(collectiontype.surrogateValue)), Stella.SYM_STELLA_THE_ARRAY) != null)))));
  }

  public static StorageSlot lookupSlotFromOptionKeyword(Surrogate owner, Keyword keyword) {
    { Stella_Class ownerclass = ((Stella_Class)(owner.surrogateValue));

      if (ownerclass != null) {
        { Slot slot = null;
          Iterator iter000 = ownerclass.classSlots();

          while (iter000.nextP()) {
            slot = ((Slot)(iter000.value));
            if (Stella_Object.storageSlotP(slot) &&
                (((Keyword)(KeyValueList.dynamicSlotValue(((StorageSlot)(slot)).dynamicSlots, Stella.SYM_STELLA_SLOT_OPTION_KEYWORD, null))) == keyword)) {
              return (((StorageSlot)(slot)));
            }
          }
        }
      }
      return (null);
    }
  }

  public static boolean genericallyAccessibleTypeP(Surrogate type) {
    return (Surrogate.subtypeOfP(type, Stella.SGT_STELLA_OBJECT) ||
        (Surrogate.subtypeOfP(type, Stella.SGT_STELLA_LITERAL) &&
         (Surrogate.lookupLiteralTypeInfo(type, Stella.KWD_WRAP_FUNCTION) != null)));
  }

  public static RecycleList createRecycleList(Surrogate classtype, int itemsize) {
    { RecycleList list = RecycleList.newRecycleList();

      { RecycleList value000 = null;

        { RecycleList list000 = null;
          Cons iter000 = Stella.$ALL_RECYCLE_LISTS$.theConsList;

          loop000 : while (!(iter000 == Stella.NIL)) {
            {
              list000 = ((RecycleList)(iter000.value));
              iter000 = iter000.rest;
            }
            if (list000.recycleListOf == classtype) {
              value000 = list000;
              break loop000;
            }
          }
        }
        { RecycleList oldlist = value000;

          if (oldlist != null) {
            RecycleList.clearRecycleList(oldlist);
            Stella.$ALL_RECYCLE_LISTS$.remove(oldlist);
          }
          Stella.$ALL_RECYCLE_LISTS$.push(list);
          list.recycleListOf = classtype;
          list.itemSize = itemsize;
          return (list);
        }
      }
    }
  }

  public static boolean unknownTypeP(Surrogate type) {
    return ((type == Stella.SGT_STELLA_UNKNOWN) ||
        ((Surrogate.typeToClass(type) == null) ||
         ((Surrogate.typeToClass(type) == Surrogate.typeToClass(Stella.SGT_STELLA_UNKNOWN)) ||
          (Surrogate.subtypeOfP(type, Stella.SGT_STELLA_NON_OBJECT) &&
           Surrogate.typeToClass(type).abstractP))));
  }

  public static Stella_Object typeToWalkedNullValueTree(Surrogate type) {
    { Stella_Object nullvalue = Surrogate.typeToNullValueTree(type);

      if (nullvalue == Stella.SYM_STELLA_NULL) {
        return (nullvalue);
      }
      else {
        return (Stella_Object.walkExpressionTree(nullvalue, type, Stella.SYM_STELLA_NULL, Stella.FALSE, new Object[1]));
      }
    }
  }

  public static Stella_Object typeToNullValueTree(Surrogate type) {
    { Stella_Class renamed_Class = Surrogate.typeToClass(type);

      if ((renamed_Class != null) &&
          (Surrogate.subtypeOfP(type, Stella.SGT_STELLA_LITERAL) ||
           Surrogate.subtypeOfP(type, Stella.SGT_STELLA_SECOND_CLASS_OBJECT))) {
        { Stella_Object nullvalue = renamed_Class.initialValue();

          if (nullvalue != null) {
            return (Stella_Object.copyConsTree(nullvalue));
          }
        }
      }
      return (Stella.SYM_STELLA_NULL);
    }
  }

  /** Set the value of the global variable for the surrogate
   * 'self' to 'value'.
   * @param self
   * @param value
   * @return Stella_Object
   */
  public static Stella_Object setGlobalValue(Surrogate self, Stella_Object value) {
    return (((Stella_Object)(edu.isi.stella.javalib.Native.funcall(self.lookupGlobalVariable().variableSetValueCode, null, new java.lang.Object [] {value}))));
  }

  /** Return the (possibly-wrapped) value of the global
   * variable for the surrogate 'self'.
   * @param self
   * @return Stella_Object
   */
  public static Stella_Object getGlobalValue(Surrogate self) {
    return (((Stella_Object)(edu.isi.stella.javalib.Native.funcall(self.lookupGlobalVariable().variableGetValueCode, null, new java.lang.Object [] {}))));
  }

  /** Return a global variable with name 'self'.
   * @return GlobalVariable
   */
  public GlobalVariable lookupGlobalVariable() {
    { Surrogate self = this;

      { Symbol symbol = ((Symbol)(Stella.lookupRigidSymbolWrtModule(self.symbolName, ((Module)(self.homeContext)), Stella.SYMBOL_SYM)));

        if (symbol != null) {
          return (symbol.lookupGlobalVariable());
        }
        else {
          return (null);
        }
      }
    }
  }

  public static boolean optimisticSubtypeOfP(Surrogate subtype, Surrogate supertype) {
    if ((((Stella_Class)(subtype.surrogateValue)) != null) &&
        ((((Stella_Class)(supertype.surrogateValue)) != null) &&
         ((Stella_Class)(subtype.surrogateValue)).classFinalizedP)) {
      return (Surrogate.subtypeOfP(subtype, supertype));
    }
    else {
      return (Stella.TRUE);
    }
  }

  public StandardObject yieldTypeSpecifier() {
    { Surrogate typespectree = this;

      return (Surrogate.realTypeSpecifier(typespectree));
    }
  }

  public static Surrogate canonicalType(Surrogate type) {
    { Stella_Class renamed_Class = ((Stella_Class)(type.surrogateValue));

      if (renamed_Class != null) {
        return (renamed_Class.classType);
      }
      else {
        return (type);
      }
    }
  }

  public static StandardObject realTypeSpecifier(Surrogate type) {
    { Stella_Object value = type.surrogateValue;

      if (Surrogate.definedTypeP(type)) {
        if (Stella_Object.typeP(value)) {
          return (Surrogate.realTypeSpecifier(((Surrogate)(value))));
        }
        else {
          return (((StandardObject)(value)));
        }
      }
      else {
        return (type);
      }
    }
  }

  public static boolean definedTypeP(Surrogate type) {
    { Stella_Object value = type.surrogateValue;
      Surrogate valuetype = null;

      if (value != null) {
        valuetype = value.primaryType();
        return ((Stella.SGT_STELLA_SURROGATE == valuetype) ||
            ((Stella.SGT_STELLA_PARAMETRIC_TYPE_SPECIFIER == valuetype) ||
             (Stella.SGT_STELLA_ANCHORED_TYPE_SPECIFIER == valuetype)));
      }
      return (Stella.FALSE);
    }
  }

  public static Surrogate slotrefType(Surrogate slotref) {
    return (((Slot)(slotref.surrogateValue)).type());
  }

  public static Slot lookupSlotFromSlotref(Surrogate slotref) {
    { Stella_Object value = slotref.surrogateValue;

      if (value != null) {
        if (Stella_Object.isaP(value, Stella.SGT_STELLA_SLOT)) {
          return (((Slot)(value)));
        }
        Stella.STANDARD_WARNING.nativeStream.println("Warning: lookup-slot-from-slotref: `" + slotref + "' already points to non-slot `" + value + "'");
        return (null);
      }
    }
    { String slotrefname = slotref.symbolName;
      Module slotrefmodule = ((Module)(slotref.homeContext));
      int dotposition = Native.string_position(slotrefname, '.', 0);
      Surrogate type = null;
      Symbol slotname = null;
      Slot slot = null;

      if (dotposition != Stella.NULL_INTEGER) {
        type = Stella.lookupSurrogateInModule(Native.string_subsequence(slotrefname, 0, dotposition), slotrefmodule, Stella.FALSE);
      }
      else {
        type = Stella.SGT_STELLA_ANY;
        dotposition = -1;
      }
      if (type != null) {
        type = ((Surrogate)(Surrogate.realTypeSpecifier(type)));
      }
      if ((type != null) &&
          Stella_Object.stellaClassP(type.surrogateValue)) {
        slotname = Stella.lookupSymbolInModule(Native.string_subsequence(slotrefname, dotposition + 1, Stella.NULL_INTEGER), slotrefmodule, Stella.FALSE);
        if (slotname != null) {
          slot = Symbol.lookupFunction(slotname);
          if (slot == null) {
            slot = Stella_Class.lookupSlot(((Stella_Class)(type.surrogateValue)), slotname);
          }
          if (slot != null) {
            if (slot.slotSlotref == null) {
              Surrogate.lookupSlotref(((slot.slotOwner == null) ? Stella.SGT_STELLA_ANY : slot.slotOwner), slot.slotName);
            }
            slotref.surrogateValue = slot;
          }
        }
      }
      return (slot);
    }
  }

  public static boolean slotrefP(Surrogate self) {
    return (Native.string_position(self.symbolName, '.', 0) != Stella.NULL_INTEGER);
  }

  public static Surrogate lookupSlotref(Surrogate self, Symbol slotname) {
    self = ((Surrogate)(Surrogate.realTypeSpecifier(self)));
    { Stella_Class renamed_Class = ((Stella_Class)(self.surrogateValue));
      Slot slot = null;
      Surrogate slotref = null;

      slot = Symbol.lookupFunction(slotname);
      if (slot == null) {
        slot = Stella_Class.lookupSlot(renamed_Class, slotname);
      }
      if (slot == null) {
        if (renamed_Class != null) {
          return (null);
        }
      }
      else {
        self = slot.slotOwner;
        if (self == null) {
          self = Stella.SGT_STELLA_ANY;
        }
        slotref = slot.slotSlotref;
      }
      if (slotref == null) {
        { Object old$Module$000 = Stella.$MODULE$.get();
          Object old$Context$000 = Stella.$CONTEXT$.get();

          try {
            Native.setSpecial(Stella.$MODULE$, ((slot != null) ? slot.homeModule() : ((Module)(((Symbol)(slotname.permanentify())).homeContext))));
            Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
            slotref = Stella.internSlotref(self.symbolName, slotname.symbolName);

          } finally {
            Stella.$CONTEXT$.set(old$Context$000);
            Stella.$MODULE$.set(old$Module$000);
          }
        }
        slotref.surrogateValue = slot;
        if (slot != null) {
          slot.slotSlotref = slotref;
        }
      }
      return (slotref);
    }
  }

  /** Return <code>true</code> iff the class named <code>subType</code> is a subclass 
   * of the class named <code>superType</code>.
   * @param subType
   * @param superType
   * @return boolean
   */
  public static boolean subtypeOfP(Surrogate subType, Surrogate superType) {
    { Stella_Class subclass = Surrogate.typeToClass(subType);
      Stella_Class superclass = Surrogate.typeToClass(superType);

      if (subclass == null) {
        { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

          try {
            Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
            Stella.signalTranslationError();
            if (!(Stella.suppressWarningsP())) {
              Stella.printErrorContext(">> ERROR: ", Stella.STANDARD_ERROR);
              {
                Stella.STANDARD_ERROR.nativeStream.println();
                Stella.STANDARD_ERROR.nativeStream.println(" Reference to non-existent class: `" + Stella_Object.deUglifyParseTree(subType) + "'");
                Stella.STANDARD_ERROR.nativeStream.println(".");
              }
;
            }

          } finally {
            Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
          }
        }
        return (Stella.FALSE);
      }
      if (superclass == null) {
        { Object old$PrintreadablyP$001 = Stella.$PRINTREADABLYp$.get();

          try {
            Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
            Stella.signalTranslationError();
            if (!(Stella.suppressWarningsP())) {
              Stella.printErrorContext(">> ERROR: ", Stella.STANDARD_ERROR);
              {
                Stella.STANDARD_ERROR.nativeStream.println();
                Stella.STANDARD_ERROR.nativeStream.println(" Reference to non-existent class: `" + Stella_Object.deUglifyParseTree(superType) + "'");
                Stella.STANDARD_ERROR.nativeStream.println(".");
              }
;
            }

          } finally {
            Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$001);
          }
        }
        return (Stella.FALSE);
      }
      return (Stella_Class.subclassOfP(subclass, superclass));
    }
  }

  public static List collectBadSuperClasses(Surrogate type, List badones) {
    { Stella_Object value = type.surrogateValue;

      if (Stella_Object.stellaClassP(value)) {
        { Surrogate renamed_Super = null;
          Cons iter000 = ((Stella_Class)(value)).classDirectSupers.theConsList;

          while (!(iter000 == Stella.NIL)) {
            {
              renamed_Super = ((Surrogate)(iter000.value));
              iter000 = iter000.rest;
            }
            Surrogate.collectBadSuperClasses(renamed_Super, badones);
          }
        }
      }
      else {
        badones.insertNew(type);
      }
      return (badones);
    }
  }

  public static boolean filterUnboundSurrogateP(Surrogate self, AllPurposeIterator iterator) {
    iterator = iterator;
    return (!(self.surrogateValue != null));
  }

  public static Surrogate collectionToActiveCollection(Surrogate type) {
    if ((type == Stella.SGT_STELLA_SET) ||
        (type == Stella.SGT_STELLA_ACTIVE_SET)) {
      return (Stella.SGT_STELLA_ACTIVE_SET);
    }
    else if ((type == Stella.SGT_STELLA_LIST) ||
        (type == Stella.SGT_STELLA_ACTIVE_LIST)) {
      return (Stella.SGT_STELLA_ACTIVE_LIST);
    }
    else {
      return (null);
    }
  }

  public static void insertPrimitiveSuper(Surrogate newsuper, List supers) {
    { boolean foundP000 = Stella.FALSE;

      { Surrogate sup = null;
        Cons iter000 = supers.theConsList;

        loop000 : while (!(iter000 == Stella.NIL)) {
          {
            sup = ((Surrogate)(iter000.value));
            iter000 = iter000.rest;
          }
          if (Surrogate.subtypeOfP(newsuper, sup)) {
            foundP000 = Stella.TRUE;
            break loop000;
          }
        }
      }
      if (!(foundP000)) {
        { Surrogate subsumedsuper = null;

          loop001 : for (;;) {
            { 
              { Surrogate value000 = null;

                { Surrogate sup = null;
                  Cons iter001 = supers.theConsList;

                  loop002 : while (!(iter001 == Stella.NIL)) {
                    {
                      sup = ((Surrogate)(iter001.value));
                      iter001 = iter001.rest;
                    }
                    if (Surrogate.subtypeOfP(sup, newsuper)) {
                      value000 = sup;
                      break loop002;
                    }
                  }
                }
                subsumedsuper = value000;
              }
              if (!(subsumedsuper != null)) {
                break loop001;
              }
            }
            supers = ((List)(supers.remove(subsumedsuper)));
          }
          supers.insert(newsuper);
        }
      }
    }
  }

  public void destroyClass() {
    { Surrogate self = this;

      { Stella_Class renamed_Class = ((Stella_Class)(self.surrogateValue));

        if (renamed_Class == null) {
          System.out.println("Can't destroy non-existent class `" + self + "'.");
        }
        else {
          renamed_Class.destroyClass();
        }
      }
    }
  }

  /** Return a Stella class with name <code>name</code>.
   * Caution:  If the class already exists, the Stella class object gets
   * redefined, but the native C++ class is not redefined.
   * @param name
   * @param supers
   * @param slots
   * @param options
   * @return Stella_Class
   */
  public static Stella_Class defineStellaClass(Surrogate name, List supers, List slots, KeywordKeyValueList options) {
    { Stella_Class renamed_Class = Stella_Class.newClass();
      List parameterslots = ((List)(options.lookup(Stella.KWD_PARAMETERS)));
      Stella_Object oldclass = null;
      boolean successP = Stella.FALSE;

      if ((!(name.homeContext == ((Module)(Stella.$MODULE$.get())))) &&
          (!Context.visibleFromP(name.homeContext, ((Module)(Stella.$MODULE$.get()))))) {
        {
          Stella.STANDARD_WARNING.nativeStream.println("Warning: Can't define a class named `" + name + "' because the module ");
          Stella.STANDARD_WARNING.nativeStream.println("   `" + name.homeContext.contextName() + "' is not visible from the current module `" + ((Module)(Stella.$MODULE$.get())).contextName() + "'.");
          Stella.STANDARD_WARNING.nativeStream.println();
        }
;
        return (null);
      }
      { boolean value000 = Stella.FALSE;
        Stella_Object value001 = null;
        Surrogate value002 = null;

        { Object [] caller_MV_returnarray = new Object[2];

          value000 = Stella_Object.bindToSurrogateP(renamed_Class, name.symbolName, Stella.TRUE, Stella.TRUE, caller_MV_returnarray);
          value001 = ((Stella_Object)(caller_MV_returnarray[0]));
          value002 = ((Surrogate)(caller_MV_returnarray[1]));
        }
        {
          successP = value000;
          oldclass = value001;
          name = value002;
        }
      }
      if (!successP) {
        return (null);
      }
      renamed_Class.classType = name;
      if (parameterslots != null) {
        { Slot s = null;
          Cons iter000 = parameterslots.theConsList;

          while (!(iter000 == Stella.NIL)) {
            {
              s = ((Slot)(iter000.value));
              iter000 = iter000.rest;
            }
            s.abstractP = Stella.TRUE;
            slots.insertLast(s);
          }
        }
      }
      Stella_Class.initializeSlotAndMethodCache(renamed_Class);
      { Surrogate s = null;
        Cons iter001 = supers.theConsList;
        List into000 = renamed_Class.classDirectSupers;
        Cons collect000 = null;

        while (!(iter001 == Stella.NIL)) {
          {
            s = ((Surrogate)(iter001.value));
            iter001 = iter001.rest;
          }
          if ((!Stella_Object.stellaClassP(s.surrogateValue)) &&
              ((!(((Module)(s.homeContext)) == ((Module)(Stella.$MODULE$.get())))) &&
               Context.visibleFromP(((Module)(s.homeContext)), ((Module)(Stella.$MODULE$.get()))))) {
            if (((Integer)(Stella.$DEBUGLEVEL$.get())).intValue() >= 3) {
              System.out.println("Automatically shadowing bogus super `" + s + "' of class `" + name + "'");
            }
            s = Stella.shadowSurrogate(s.symbolName);
          }
          if (collect000 == null) {
            {
              collect000 = Stella_Object.cons(s, Stella.NIL);
              if (into000.theConsList == Stella.NIL) {
                into000.theConsList = collect000;
              }
              else {
                Cons.addConsToEndOfConsList(into000.theConsList, collect000);
              }
            }
          }
          else {
            {
              collect000.rest = Stella_Object.cons(s, Stella.NIL);
              collect000 = collect000.rest;
            }
          }
        }
      }
      Stella_Class.incorporateClassOptions(renamed_Class, options);
      { boolean testValue000 = Stella.FALSE;

        testValue000 = !renamed_Class.primitiveP();
        if (testValue000) {
          { boolean foundP000 = Stella.FALSE;

            { Slot slot = null;
              Cons iter002 = slots.theConsList;

              loop002 : while (!(iter002 == Stella.NIL)) {
                {
                  slot = ((Slot)(iter002.value));
                  iter002 = iter002.rest;
                }
                if (slot.primitiveP()) {
                  foundP000 = Stella.TRUE;
                  break loop002;
                }
              }
            }
            testValue000 = foundP000;
          }
        }
        if (testValue000) {
          Stella.STANDARD_WARNING.nativeStream.println("Warning: Defined class `" + renamed_Class + "' illegally specifies primitive slots.");
        }
      }
      renamed_Class.classLocalSlots = slots;
      if ((oldclass != null) &&
          Stella_Object.isaP(oldclass, Stella.SGT_STELLA_CLASS)) {
        Stella_Class.undefineOldClass(((Stella_Class)(oldclass)), renamed_Class);
      }
      if (renamed_Class.classTaxonomyNode == null) {
        renamed_Class.classTaxonomyNode = TaxonomyGraph.createTaxonomyNode(Stella.$CLASS_TAXONOMY_GRAPH$, null, renamed_Class, renamed_Class.classDirectSupers.emptyP());
      }
      { Slot slot = null;
        Cons iter003 = slots.theConsList;

        while (!(iter003 == Stella.NIL)) {
          {
            slot = ((Slot)(iter003.value));
            iter003 = iter003.rest;
          }
          Slot.registerSlotName(slot);
        }
      }
      Stella_Class.rememberUnfinalizedClass(renamed_Class, Stella.TRUE);
      return (renamed_Class);
    }
  }

  /** Funcallable version of the <code>renamed_New</code> operator.
   * Return an instance of the class named by <code>type</code>.  If <code>initialValuePairs</code>
   * is supplied, it has to be a key/value list similar to what's accepted by <code>renamed_New</code>
   * and the named slots will be initialized with the supplied values.  Similar to
   * <code>renamed_New</code>, all required arguments for <code>type</code> must be included.  Since all the
   * slot initialization, etc. is handled dynamically at run time, <code>createObject</code>
   * is much slower than <code>renamed_New</code>; therefore, it should only be used if <code>type</code> cannot
   * be known at translation time.
   * @param type
   * @param initialValuePairs
   * @return Stella_Object
   */
  public static Stella_Object createObject(Surrogate type, Cons initialValuePairs) {
    { Stella_Class renamed_Class = type.getStellaClass(Stella.TRUE);
      java.lang.reflect.Method constructorcode = Stella_Class.getConstructor(renamed_Class, Stella.TRUE);

      { PropertyList chooseValue000 = null;

        if (initialValuePairs.length() == 0) {
          chooseValue000 = null;
        }
        else {
          { PropertyList self000 = PropertyList.newPropertyList();

            self000.thePlist = initialValuePairs;
            chooseValue000 = self000;
          }
        }
        { PropertyList initialvalues = chooseValue000;
          List requiredslots = renamed_Class.classRequiredSlotNames();
          Cons requiredslotvalues = Stella.NIL;
          Stella_Object slotvalue = null;
          Slot slot = null;
          Stella_Object renamed_Object = null;

          if (!(constructorcode != null)) {
            { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

              stream000.nativeStream.print("create-object: no funcallable constructor available for `" + type + "'");
              throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
            }
          }
          if (requiredslots.nonEmptyP()) {
            if (initialvalues == null) {
              { OutputStringStream stream001 = OutputStringStream.newOutputStringStream();

                stream001.nativeStream.print("create-object: missing initial values for `" + type + "''s required slots");
                throw ((StellaException)(StellaException.newStellaException(stream001.theStringReader()).fillInStackTrace()));
              }
            }
            { Symbol reqslotname = null;
              Cons iter000 = requiredslots.theConsList;
              Cons collect000 = null;

              while (!(iter000 == Stella.NIL)) {
                {
                  reqslotname = ((Symbol)(iter000.value));
                  iter000 = iter000.rest;
                }
                slot = Stella_Class.lookupSlot(renamed_Class, reqslotname);
                if (!(Surrogate.subtypeOfP(slot.type(), Stella.SGT_STELLA_OBJECT))) {
                  { OutputStringStream stream002 = OutputStringStream.newOutputStringStream();

                    stream002.nativeStream.print("create-object: can't yet initialize required slot `" + type + "'.`" + reqslotname + "', since its type is not a subtype of OBJECT");
                    throw ((StellaException)(StellaException.newStellaException(stream002.theStringReader()).fillInStackTrace()));
                  }
                }
                slotvalue = initialvalues.lookup(reqslotname.keywordify());
                initialvalues.removeAt(reqslotname.keywordify());
                if (slotvalue == null) {
                  { OutputStringStream stream003 = OutputStringStream.newOutputStringStream();

                    stream003.nativeStream.print("create-object: missing initial value for required slot `" + type + "'.`" + reqslotname + "'");
                    throw ((StellaException)(StellaException.newStellaException(stream003.theStringReader()).fillInStackTrace()));
                  }
                }
                if (collect000 == null) {
                  {
                    collect000 = Stella_Object.cons(slotvalue, Stella.NIL);
                    if (requiredslotvalues == Stella.NIL) {
                      requiredslotvalues = collect000;
                    }
                    else {
                      Cons.addConsToEndOfConsList(requiredslotvalues, collect000);
                    }
                  }
                }
                else {
                  {
                    collect000.rest = Stella_Object.cons(slotvalue, Stella.NIL);
                    collect000 = collect000.rest;
                  }
                }
              }
            }
          }
          renamed_Object = Stella.apply(constructorcode, requiredslotvalues);
          if (initialvalues != null) {
            { Stella_Object value = null;
              Stella_Object slotname = null;
              Cons iter001 = initialvalues.thePlist;

              while (!(iter001 == Stella.NIL)) {
                slotname = iter001.value;
                {
                  value = iter001.rest.value;
                  iter001 = iter001.rest.rest;
                }
                if (Surrogate.subtypeOfKeywordP(Stella_Object.safePrimaryType(slotname))) {
                  { Keyword slotname000 = ((Keyword)(slotname));

                    slot = Stella_Class.lookupSlot(renamed_Class, GeneralizedSymbol.internDerivedSymbol(type, slotname000.symbolName));
                    if (!Stella_Object.storageSlotP(slot)) {
                      { OutputStringStream stream004 = OutputStringStream.newOutputStringStream();

                        stream004.nativeStream.print("create-object: slot `" + slotname000 + "' does not exist on class `" + type + "'");
                        throw ((StellaException)(StellaException.newStellaException(stream004.theStringReader()).fillInStackTrace()));
                      }
                    }
                    StandardObject.putSlotValue(((StandardObject)(renamed_Object)), ((StorageSlot)(slot)), value);
                  }
                }
                else {
                  { OutputStringStream stream005 = OutputStringStream.newOutputStringStream();

                    stream005.nativeStream.print("create-object: illegal initialization option: `" + slotname + "'");
                    throw ((StellaException)(StellaException.newStellaException(stream005.theStringReader()).fillInStackTrace()));
                  }
                }
              }
            }
          }
          return (renamed_Object);
        }
      }
    }
  }

  /** Return a class with name <code>className</code>.  If none exists, break
   * if <code>errorP</code>, else return <code>null</code>.
   * @param errorP
   * @return Stella_Class
   */
  public Stella_Class getStellaClass(boolean errorP) {
    { Surrogate className = this;

      { Stella_Object renamed_Class = className.surrogateValue;

        if ((renamed_Class != null) &&
            Stella_Object.stellaClassP(renamed_Class)) {
          return (((Stella_Class)(renamed_Class)));
        }
        if (errorP) {
          { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

            stream000.nativeStream.print("Class ``" + className + "'' does not exist.");
            { String error_message_ = stream000.theStringReader();

              Native.continuableError(error_message_);
            }
          }
        }
        return (null);
      }
    }
  }

  public static Stella_Class typeToClass(Surrogate type) {
    return (((Stella_Class)(type.surrogateValue)));
  }

  public static void setLiteralTypeInfo(Surrogate type, Keyword key, Stella_Object value) {
    { KeyValueList entry = ((KeyValueList)(Stella.$LITERAL_TYPE_INFO_TABLE$.lookup(type)));

      if (entry == null) {
        entry = KeyValueList.newKeyValueList();
        Stella.$LITERAL_TYPE_INFO_TABLE$.insertAt(type, entry);
        Stella.$LITERAL_TYPES$.insertLast(type);
      }
      entry.insertAt(key, value);
    }
  }

  public static Stella_Object lookupLiteralTypeInfo(Surrogate type, Keyword key) {
    { KeyValueList entry = ((KeyValueList)(Stella.$LITERAL_TYPE_INFO_TABLE$.lookup(type)));

      if (entry != null) {
        return (entry.lookup(key));
      }
      else {
        return (null);
      }
    }
  }

  public static void printSurrogate(Surrogate self, java.io.PrintStream stream) {
    { boolean visibleP = self == Stella.lookupSurrogateInModule(self.symbolName, ((Module)(Stella.$MODULE$.get())), Stella.FALSE);
      Module module = ((Module)(self.homeContext));

      if (!visibleP) {
        if ((self.symbolId == -1) ||
            (module == null)) {
          stream.print("<<UNINTERNED>>/");
        }
        else {
          stream.print(module.moduleFullName + "/");
        }
      }
      stream.print("@");
      if (((Boolean)(Stella.$PRINTREADABLYp$.get())).booleanValue()) {
        Stella.printSymbolNameReadably(self.symbolName, stream, ((Module)(Stella.$MODULE$.get())).caseSensitiveP);
      }
      else {
        stream.print(self.symbolName);
      }
    }
  }

  /** Return <code>true</code> if <code>self</code> is visible from the current module.
   * @param self
   * @return boolean
   */
  public static boolean visibleSurrogateP(Surrogate self) {
    return (self == Stella.lookupSurrogateInModule(self.symbolName, ((Module)(Stella.$MODULE$.get())), Stella.FALSE));
  }

  public String localPrintName() {
    { Surrogate self = this;

      return ("@" + self.symbolName);
    }
  }

  public Surrogate surrogatify() {
    { Surrogate self = this;

      return (self);
    }
  }

  /** Convert <code>surrogate</code> into a symbol with the same name and module.
   * @param surrogate
   * @return Symbol
   */
  public static Symbol symbolize(Surrogate surrogate) {
    return (Stella.internSymbolInModule(surrogate.symbolName, ((Module)(surrogate.homeContext)), Stella.TRUE));
  }

  /** Convert <code>type</code> into a symbol with the same name and module.
   * @param type
   * @return Symbol
   */
  public static Symbol typeToSymbol(Surrogate type) {
    return (Stella.internSymbolInModule(type.symbolName, ((Module)(type.homeContext)), Stella.TRUE));
  }

  public static Symbol surrogateToSymbol(Surrogate self) {
    return (Stella.internSymbolInModule(self.symbolName, ((Module)(Stella.$MODULE$.get())), Stella.FALSE));
  }

  /** Remove <code>self</code> from its home module and the surrogate table.
   * @param self
   */
  public static void uninternSurrogate(Surrogate self) {
    { ExtensibleSymbolArray surrogatearray = Stella.selectSymbolArray(Stella.SURROGATE_SYM);
      StringToIntegerHashTable offsettable = ((((Module)(self.homeContext)) != null) ? Module.selectSymbolOffsetTable(((Module)(self.homeContext)), Stella.SURROGATE_SYM) : ((StringToIntegerHashTable)(null)));
      int surrogateid = self.symbolId;
      Surrogate realsurrogate = Stella.getSgtFromOffset(surrogateid);

      if (self == realsurrogate) {
        ExtensibleSymbolArray.freeSymbolOffset(surrogatearray, surrogateid);
      }
      if ((offsettable != null) &&
          (surrogateid == offsettable.lookup(self.symbolName))) {
        offsettable.removeAt(self.symbolName);
      }
      self.symbolId = -1;
      self.surrogateValue = null;
    }
  }

  /** Safe version of <code>importSurrogate</code> (which see).  Only imports <code>surrogate</code> if
   * no surrogate with that name is currently interned or visible in <code>module</code>.
   * Returns <code>surrogate</code> if it was imported or the conflicting surrogate in <code>module</code>
   * otherwise.
   * @param surrogate
   * @param module
   * @return Surrogate
   */
  public static Surrogate safeImportSurrogate(Surrogate surrogate, Module module) {
    { String name = surrogate.symbolName;
      Surrogate modulesurrogate = Stella.lookupSurrogateInModule(name, module, Stella.FALSE);

      if (modulesurrogate != null) {
        return (modulesurrogate);
      }
      else {
        return (Surrogate.importSurrogate(surrogate, module));
      }
    }
  }

  /** Import <code>surrogate</code> into <code>module</code> and return the imported <code>surrogate</code>.
   * Signal an error if a different surrogate with the same name already exists
   * locally in <code>module</code>.  Any surrogate with the same name visible in <code>module</code> by
   * inheritance will be shadowed by the newly imported <code>surrogate</code>.
   * @param surrogate
   * @param module
   * @return Surrogate
   */
  public static Surrogate importSurrogate(Surrogate surrogate, Module module) {
    { String name = surrogate.symbolName;
      Surrogate modulesurrogate = Stella.lookupSurrogateInModule(name, module, Stella.TRUE);

      if (!(modulesurrogate == surrogate)) {
        if (modulesurrogate != null) {
          { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

            stream000.nativeStream.print("Can't import, a surrogate with name `" + name + "' already exists in `" + module + "'");
            throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
          }
        }
        if (surrogate != null) {
          Module.selectSymbolOffsetTable(module, Stella.SURROGATE_SYM).insertAt(name, surrogate.symbolId);
        }
      }
      return (surrogate);
    }
  }

  /** Return a dictionary of <code>collectiontype</code> containing <code>values</code>, in order.
   * Currently supported <code>collectiontype</code>s are @HASH-TABLE, @STELLA-HASH-TABLE,
   * @KEY-VALUE-LIST, @KEY-VALUE-MAP and @PROPERTY-LIST.
   * @param collectiontype
   * @param alternatingkeysandvalues
   * @return AbstractDictionary
   */
  public static AbstractDictionary dictionary(Surrogate collectiontype, Cons alternatingkeysandvalues) {
    { AbstractDictionary dictionary = ((AbstractDictionary)(Surrogate.createObject(collectiontype, Stella.NIL)));
      Stella_Object key = null;
      Stella_Object value = null;
      Cons copy = Stella.NIL;
      Cons cursor = null;

      { Stella_Object item = null;
        Cons iter000 = alternatingkeysandvalues;
        Cons collect000 = null;

        while (!(iter000 == Stella.NIL)) {
          {
            item = iter000.value;
            iter000 = iter000.rest;
          }
          if (collect000 == null) {
            {
              collect000 = Stella_Object.cons(item, Stella.NIL);
              if (copy == Stella.NIL) {
                copy = collect000;
              }
              else {
                Cons.addConsToEndOfConsList(copy, collect000);
              }
            }
          }
          else {
            {
              collect000.rest = Stella_Object.cons(item, Stella.NIL);
              collect000 = collect000.rest;
            }
          }
        }
      }
      cursor = copy;
      while (!(cursor == Stella.NIL)) {
        key = cursor.value;
        value = cursor.rest.value;
        { Surrogate testValue000 = Stella_Object.safePrimaryType(dictionary);

          if (Surrogate.subtypeOfP(testValue000, Stella.SGT_STELLA_HASH_TABLE)) {
            { HashTable dictionary000 = ((HashTable)(dictionary));

              dictionary000.insertAt(key, value);
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, Stella.SGT_STELLA_STELLA_HASH_TABLE)) {
            { StellaHashTable dictionary000 = ((StellaHashTable)(dictionary));

              dictionary000.insertAt(key, value);
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, Stella.SGT_STELLA_KEY_VALUE_LIST)) {
            { KeyValueList dictionary000 = ((KeyValueList)(dictionary));

              dictionary000.insertAt(key, value);
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, Stella.SGT_STELLA_KEY_VALUE_MAP)) {
            { KeyValueMap dictionary000 = ((KeyValueMap)(dictionary));

              dictionary000.insertAt(key, value);
            }
          }
          else if (Surrogate.subtypeOfP(testValue000, Stella.SGT_STELLA_PROPERTY_LIST)) {
            { PropertyList dictionary000 = ((PropertyList)(dictionary));

              dictionary000.insertAt(key, value);
            }
          }
          else {
            { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

              stream000.nativeStream.print("dictionary: Can't create dictionaries of type `" + collectiontype + "'");
              throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
            }
          }
        }
        cursor = cursor.rest.rest;
      }
      return (dictionary);
    }
  }

  /** Return a sequence containing <code>values</code>, in order.
   * @param collectiontype
   * @param values
   * @return Sequence
   */
  public static Sequence sequence(Surrogate collectiontype, Cons values) {
    { Sequence sequence = ((Sequence)(Surrogate.createObject(collectiontype, Stella.NIL)));

      { Stella_Object i = null;
        Cons iter000 = values;

        while (!(iter000 == Stella.NIL)) {
          {
            i = iter000.value;
            iter000 = iter000.rest;
          }
          if (Surrogate.subtypeOfP(Stella_Object.safePrimaryType(sequence), Stella.SGT_STELLA_LIST)) {
            { List sequence000 = ((List)(sequence));

              sequence000.insertLast(i);
            }
          }
          else {
            { OutputStringStream stream000 = OutputStringStream.newOutputStringStream();

              stream000.nativeStream.print("sequence: Don't know how to `insert-last' into a `" + collectiontype + "'");
              throw ((StellaException)(StellaException.newStellaException(stream000.theStringReader()).fillInStackTrace()));
            }
          }
        }
      }
      return (sequence);
    }
  }

  public static boolean subtypeOfParametricTypeSpecifierP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_PARAMETRIC_TYPE_SPECIFIER.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_PARAMETRIC_TYPE_SPECIFIER));
    }
  }

  public static boolean subtypeOfAnchoredTypeSpecifierP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_ANCHORED_TYPE_SPECIFIER.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_ANCHORED_TYPE_SPECIFIER));
    }
  }

  public static boolean subtypeOfMethodSlotP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_METHOD_SLOT.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_METHOD_SLOT));
    }
  }

  public static boolean subtypeOfStorageSlotP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_STORAGE_SLOT.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_STORAGE_SLOT));
    }
  }

  public static boolean subtypeOfClassP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      { Stella_Class typeclass = ((Stella_Class)(type.surrogateValue));

        return ((typeclass != null) &&
            Stella_Class.subclassOfP(typeclass, ((Stella_Class)(Stella.SGT_STELLA_CLASS.surrogateValue))));
      }
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_CLASS));
    }
  }

  public static boolean subtypeOfConsP(Surrogate type) {
    return (type == Stella.SGT_STELLA_CONS);
  }

  public static boolean subtypeOfKeywordP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_KEYWORD.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_KEYWORD));
    }
  }

  public static boolean subtypeOfTransientSymbolP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_TRANSIENT_SYMBOL.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_TRANSIENT_SYMBOL));
    }
  }

  public static boolean subtypeOfSymbolP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_SYMBOL.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_SYMBOL) ||
          Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_TRANSIENT_SYMBOL));
    }
  }

  public static boolean subtypeOfTypeP(Surrogate type) {
    return (Surrogate.subtypeOfSurrogateP(type));
  }

  public static boolean subtypeOfSurrogateP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_SURROGATE.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_SURROGATE));
    }
  }

  public static boolean subtypeOfWrapperP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_WRAPPER.surrogateValue))));
    }
    else {
      return (Surrogate.subtypeOfBooleanP(type) ||
          (Surrogate.subtypeOfIntegerP(type) ||
           (Surrogate.subtypeOfFloatP(type) ||
            (Surrogate.subtypeOfStringP(type) ||
             (Surrogate.subtypeOfCharacterP(type) ||
              Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_WRAPPER))))));
    }
  }

  public static boolean subtypeOfCharacterP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_CHARACTER_WRAPPER.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_CHARACTER_WRAPPER));
    }
  }

  public static boolean subtypeOfVerbatimStringP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_VERBATIM_STRING_WRAPPER.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_VERBATIM_STRING_WRAPPER));
    }
  }

  public static boolean subtypeOfStringP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_STRING_WRAPPER.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_STRING_WRAPPER) ||
          Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_VERBATIM_STRING_WRAPPER));
    }
  }

  public static boolean subtypeOfFloatP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_FLOAT_WRAPPER.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_FLOAT_WRAPPER));
    }
  }

  public static boolean subtypeOfIntegerP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_INTEGER_WRAPPER.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_INTEGER_WRAPPER));
    }
  }

  public static boolean subtypeOfBooleanP(Surrogate type) {
    if (Stella.$CLASS_HIERARCHY_BOOTEDp$) {
      return (Stella_Class.subclassOfP(((Stella_Class)(type.surrogateValue)), ((Stella_Class)(Stella.SGT_STELLA_BOOLEAN_WRAPPER.surrogateValue))));
    }
    else {
      return (Surrogate.bootstrapSubtypeOfP(type, Stella.SGT_STELLA_BOOLEAN_WRAPPER));
    }
  }

  public static boolean bootstrapSubtypeOfP(Surrogate subtype, Surrogate supertype) {
    return ((subtype == supertype) ||
        ((((Stella_Class)(subtype.surrogateValue)) != null) &&
         ((((Stella_Class)(supertype.surrogateValue)) != null) &&
          Surrogate.subtypeOfP(subtype, supertype))));
  }

  public void printObject(java.io.PrintStream stream) {
    { Surrogate self = this;

      Surrogate.printSurrogate(self, stream);
    }
  }

  public static Stella_Object accessSurrogateSlotValue(Surrogate self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Stella.SYM_STELLA_SURROGATE_VALUE) {
      if (setvalueP) {
        self.surrogateValue = value;
      }
      else {
        value = self.surrogateValue;
      }
    }
    else if (slotname == Stella.SYM_STELLA_SURROGATE_NAME) {
      if (setvalueP) {
        self.symbolName = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapString(self.symbolName);
      }
    }
    else if (slotname == Stella.SYM_STELLA_TYPE_CLASS) {
      if (setvalueP) {
        self.surrogateValue = ((Stella_Class)(value));
      }
      else {
        value = ((Stella_Class)(self.surrogateValue));
      }
    }
    else if (slotname == Stella.SYM_STELLA_TYPE_NAME) {
      if (setvalueP) {
        self.symbolName = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapString(self.symbolName);
      }
    }
    else if (slotname == Stella.SYM_STELLA_SLOTREF_SLOT) {
      if (setvalueP) {
        self.surrogateValue = ((Slot)(value));
      }
      else {
        value = ((Slot)(self.surrogateValue));
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
    { Surrogate self = this;

      return (Stella.SGT_STELLA_SURROGATE);
    }
  }

}

