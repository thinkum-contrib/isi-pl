//  -*- Mode: Java -*-
//
// MethodSlot.java

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

public class MethodSlot extends Slot {
    public boolean methodSetterP;
    public List methodParameterNames;
    public List methodParameterTypeSpecifiers;
    public List methodReturnTypeSpecifiers;
    public String methodStringifiedSource;
    public java.lang.reflect.Method methodCode;
    public java.lang.reflect.Method functionCode;
    public boolean methodFunctionP;

  public static MethodSlot newMethodSlot() {
    { MethodSlot self = null;

      self = new MethodSlot();
      self.dynamicSlots = KeyValueList.newKeyValueList();
      self.abstractP = Stella.FALSE;
      self.slotDirectEquivalent = null;
      self.slotMarkedP = Stella.FALSE;
      self.slotExternalP = Stella.FALSE;
      self.slotRenamedP = Stella.FALSE;
      self.slotPublicP = Stella.TRUE;
      self.slotSlotref = null;
      self.slotBaseType = null;
      self.slotOwner = null;
      self.slotName = null;
      self.methodFunctionP = Stella.FALSE;
      self.functionCode = null;
      self.methodCode = ((java.lang.reflect.Method)(null));
      self.methodStringifiedSource = null;
      self.methodReturnTypeSpecifiers = null;
      self.methodParameterTypeSpecifiers = null;
      self.methodParameterNames = null;
      self.methodSetterP = Stella.FALSE;
      return (self);
    }
  }

  public static boolean idlConstructorP(MethodSlot method) {
    return ((method.type() == Stella.SGT_STELLA_VOID) &&
        ((method.methodParameterNames().length() == 1) &&
         (Stella.stringEqlP(method.slotOwner.symbolName, method.slotName.symbolName) &&
          (((Module)(method.slotOwner.homeContext)) == ((Module)(method.slotName.homeContext))))));
  }

  public static boolean illegalIdlMethodP(MethodSlot methodslot) {
    return (Stella.getQuotedTree("((DEFINED? NULL?) \"/STELLA\")", "/STELLA").memberP(methodslot.slotName));
  }

  public static Cons idlYieldConstructorSignatureTree(MethodSlot method) {
    Native.setSpecial(Stella.$METHODBEINGWALKED$, method);
    return (Stella_Object.cons(GeneralizedSymbol.idlTranslateClassName(Stella.internSymbolInModule(method.slotOwner.symbolName, ((Module)(method.slotOwner.homeContext)), Stella.TRUE)), Stella.list$(Stella_Object.cons(Stella.NIL, Stella_Object.cons(MethodSlot.idlTranslateConstructorName(method), Stella_Object.cons(Stella_Object.cons(MethodSlot.idlTranslateMethodParameters(method), Stella.NIL), Stella.NIL))))));
  }

  public static Cons idlYieldOperationSignatureTree(MethodSlot method) {
    { MethodSlot mostgeneralmethod = method;
      StandardObject returntype = null;

      Native.setSpecial(Stella.$METHODBEINGWALKED$, method);
      while ((mostgeneralmethod.slotDirectEquivalent != null) &&
          (Stella_Object.isaP(mostgeneralmethod.slotDirectEquivalent, Stella.SGT_STELLA_METHOD_SLOT) &&
           (!MethodSlot.methodContainsUnknownTypeP(((MethodSlot)(mostgeneralmethod.slotDirectEquivalent)))))) {
        mostgeneralmethod = ((MethodSlot)(mostgeneralmethod.slotDirectEquivalent));
      }
      returntype = mostgeneralmethod.slotBaseType;
      return (Stella_Object.cons((method.methodFunctionP ? null : GeneralizedSymbol.idlTranslateClassName(Stella.internSymbolInModule(method.slotOwner.symbolName, ((Module)(method.slotOwner.homeContext)), Stella.TRUE))), Stella.list$(Stella_Object.cons(Stella_Object.cons(StandardObject.idlTranslateTypeSpec(returntype), Stella.NIL), Stella_Object.cons(MethodSlot.idlTranslateFunctionName(method), Stella_Object.cons(Stella_Object.cons(MethodSlot.idlTranslateMethodParameters(method), Stella.NIL), Stella.NIL))))));
    }
  }

  public static StringWrapper idlTranslateConstructorName(MethodSlot constructor) {
    return (GeneralizedSymbol.idlTranslateClassName(constructor.slotName));
  }

  public static Cons idlTranslateMethodParameters(MethodSlot method) {
    { Cons result = Stella.NIL;
      Cons directions = Stella.NIL;

      if (method.methodParameterDirections().emptyP()) {
        { Symbol name = null;
          Cons iter000 = method.methodParameterNames().rest();
          Cons collect000 = null;

          while (!(iter000 == Stella.NIL)) {
            {
              name = ((Symbol)(iter000.value));
              iter000 = iter000.rest;
            }
            name = name;
            if (collect000 == null) {
              {
                collect000 = Stella_Object.cons(Stella.SYM_STELLA_IN, Stella.NIL);
                if (directions == Stella.NIL) {
                  directions = collect000;
                }
                else {
                  Cons.addConsToEndOfConsList(directions, collect000);
                }
              }
            }
            else {
              {
                collect000.rest = Stella_Object.cons(Stella.SYM_STELLA_IN, Stella.NIL);
                collect000 = collect000.rest;
              }
            }
          }
        }
      }
      else {
        directions = method.methodParameterDirections().rest();
      }
      { Stella_Object direction = null;
        StandardObject type = null;
        Symbol name = null;
        Cons iter001 = method.methodParameterNames().rest();
        Cons iter002 = method.methodParameterTypeSpecifiers().rest();
        Cons iter003 = directions;
        Cons collect001 = null;

        while ((!(iter001 == Stella.NIL)) &&
            ((!(iter002 == Stella.NIL)) &&
             (!(iter003 == Stella.NIL)))) {
          {
            name = ((Symbol)(iter001.value));
            iter001 = iter001.rest;
          }
          {
            type = ((StandardObject)(iter002.value));
            iter002 = iter002.rest;
          }
          {
            direction = iter003.value;
            iter003 = iter003.rest;
          }
          if (collect001 == null) {
            {
              collect001 = Stella_Object.cons(Symbol.idlTranslateMethodParameter(name, type, ((Symbol)(direction))), Stella.NIL);
              if (result == Stella.NIL) {
                result = collect001;
              }
              else {
                Cons.addConsToEndOfConsList(result, collect001);
              }
            }
          }
          else {
            {
              collect001.rest = Stella_Object.cons(Symbol.idlTranslateMethodParameter(name, type, ((Symbol)(direction))), Stella.NIL);
              collect001 = collect001.rest;
            }
          }
        }
      }
      return (result);
    }
  }

  public static StringWrapper idlTranslateFunctionName(MethodSlot function) {
    { Symbol functionname = function.slotName;
      String translatedname = null;

      if (MethodSlot.idlMethodObjectIsOverloadedFunctionP(function)) {
        functionname = Symbol.idlCreateOverloadedFunctionName(functionname, function.slotOwner);
      }
      translatedname = Symbol.idlTranslateName(functionname).wrapperValue;
      if (function.methodSetterP) {
        translatedname = translatedname + "_setter";
      }
      if (MethodSlot.slotReaderP(function)) {
        translatedname = translatedname + "_reader";
      }
      return (Stella.wrapString(translatedname));
    }
  }

  public static boolean idlMethodObjectIsOverloadedFunctionP(MethodSlot method) {
    return ((!method.methodFunctionP) &&
        (((StringWrapper)(KeyValueList.dynamicSlotValue(((Stella_Class)(method.slotOwner.surrogateValue)).dynamicSlots, Stella.SYM_STELLA_CLASS_IDL_NATIVE_TYPE, Stella.NULL_STRING_WRAPPER))).wrapperValue != null));
  }

  public static String javaYieldClassNameForFunction(MethodSlot function) {
    { String rawClassName = "";

      if (MethodSlot.javaFlotsamFunctionP(function)) {
        rawClassName = Module.javaYieldFlotsamClassName(function.homeModule());
        if (Module.omitJavaPackagePrefixP(function.homeModule(), Stella.javaYieldFlotsamTypeName(rawClassName))) {
          return (rawClassName);
        }
        else {
          return (Module.javaPackagePrefix(function.homeModule(), ".") + rawClassName);
        }
      }
      else if (((BooleanWrapper)(KeyValueList.dynamicSlotValue(function.dynamicSlots, Stella.SYM_STELLA_METHOD_NATIVEp, Stella.FALSE_WRAPPER))).wrapperValue) {
        return (Stella.javaYieldNativeClassName());
      }
      else if (function.methodStartupFunctionP()) {
        rawClassName = StringWrapper.javaTranslateClassNamestring(Stella.wrapString(((StringWrapper)(KeyValueList.dynamicSlotValue(function.dynamicSlots, Stella.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.NULL_STRING_WRAPPER))).wrapperValue)).wrapperValue;
        if (Module.omitJavaPackagePrefixP(function.homeModule(), Stella.javaYieldFlotsamTypeName(rawClassName))) {
          return (rawClassName);
        }
        else {
          return (Module.javaPackagePrefix(function.homeModule(), ".") + rawClassName);
        }
      }
      else if (((BooleanWrapper)(KeyValueList.dynamicSlotValue(function.dynamicSlots, Stella.SYM_STELLA_METHOD_CONSTRUCTORp, Stella.FALSE_WRAPPER))).wrapperValue) {
        return (StandardObject.javaTranslateTypeSpec(((StandardObject)(function.methodReturnTypeSpecifiers().first()))).wrapperValue);
      }
      else {
        return (StandardObject.javaTranslateTypeSpec(((StandardObject)(function.methodParameterTypeSpecifiers().first()))).wrapperValue);
      }
    }
  }

  public StringWrapper javaTranslateMethodName() {
    { MethodSlot method = this;

      { Symbol methodname = Symbol.yieldRenamedNameIfNative(method.slotName, Stella.KWD_JAVA, Stella.KWD_FUNCTION);
        String translatedname = null;

        if (MethodSlot.javaMethodObjectIsOverloadedFunctionP(method)) {
          methodname = Symbol.javaCreateOverloadedFunctionName(methodname, method.slotOwner);
        }
        translatedname = Symbol.javaTranslateName(methodname).wrapperValue;
        return (Stella.wrapString(translatedname));
      }
    }
  }

  public static boolean javaFunctionInDifferentModuleP(MethodSlot method) {
    { StandardObject firstparametertype = ((StandardObject)(method.methodParameterTypeSpecifiers().first()));

      if ((!(firstparametertype != null)) ||
          (method.homeModule() == StandardObject.typeSpecToClass(firstparametertype).homeModule())) {
        return (Stella.FALSE);
      }
      else {
        {
          if (!(MethodSlot.javaMethodObjectIsFunctionP(method))) {
            Stella.STANDARD_WARNING.nativeStream.println("Warning: Method `" + method + "' being defined on type `" + firstparametertype + "', but they are not in the same module!");
          }
          return (Stella.TRUE);
        }
      }
    }
  }

  public static boolean javaMethodObjectIsFunctionP(MethodSlot method) {
    return (method.methodFunctionP ||
        MethodSlot.javaMethodObjectIsOverloadedFunctionP(method));
  }

  public static boolean javaMethodObjectIsOverloadedFunctionP(MethodSlot method) {
    return ((!method.methodFunctionP) &&
        (MethodSlot.javaMethodObjectDefinedOnNativeTypeP(method) &&
         ((!((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_NATIVEp, Stella.FALSE_WRAPPER))).wrapperValue) ||
          Surrogate.subtypeOfP(method.slotOwner, Stella.SGT_STELLA_LITERAL))));
  }

  public static boolean javaMethodObjectDefinedOnNativeTypeP(MethodSlot method) {
    { StandardObject firstparametertype = ((StandardObject)(method.methodParameterTypeSpecifiers().first()));

      return ((firstparametertype != null) &&
          (((StringWrapper)(KeyValueList.dynamicSlotValue(StandardObject.typeSpecToClass(firstparametertype).dynamicSlots, Stella.SYM_STELLA_CLASS_JAVA_NATIVE_TYPE, Stella.NULL_STRING_WRAPPER))).wrapperValue != null));
    }
  }

  public static boolean zeroArgumentFunctionP(MethodSlot method) {
    return (method.methodFunctionP &&
        method.methodParameterNames().emptyP());
  }

  public static Cons javaTranslateMethodParameters(MethodSlot method) {
    { boolean skipfirstparameterP = !MethodSlot.javaMethodObjectIsFunctionP(method);
      Cons translatedparameters = Stella.NIL;

      { int i = Stella.NULL_INTEGER;
        StandardObject ptype = null;
        Symbol pname = null;
        Cons iter000 = method.methodParameterNames().theConsList;
        Cons iter001 = method.methodParameterTypeSpecifiers().theConsList;
        int iter002 = 1;
        Cons collect000 = null;

        while ((!(iter000 == Stella.NIL)) &&
            (!(iter001 == Stella.NIL))) {
          {
            pname = ((Symbol)(iter000.value));
            iter000 = iter000.rest;
          }
          {
            ptype = ((StandardObject)(iter001.value));
            iter001 = iter001.rest;
          }
          {
            i = iter002;
            iter002 = iter002 + 1;
          }
          if ((!skipfirstparameterP) ||
              (i > 1)) {
            if (collect000 == null) {
              {
                collect000 = Stella_Object.cons(Symbol.javaTranslateMethodParameter(pname, ptype, method), Stella.NIL);
                if (translatedparameters == Stella.NIL) {
                  translatedparameters = collect000;
                }
                else {
                  Cons.addConsToEndOfConsList(translatedparameters, collect000);
                }
              }
            }
            else {
              {
                collect000.rest = Stella_Object.cons(Symbol.javaTranslateMethodParameter(pname, ptype, method), Stella.NIL);
                collect000 = collect000.rest;
              }
            }
          }
        }
      }
      if (!(method.methodReturnTypeSpecifiers().rest() == Stella.NIL)) {
        translatedparameters = translatedparameters.concatenate(Stella_Object.cons(Stella.javaTranslateReturnParameter(), Stella.NIL), Stella.NIL);
      }
      return (translatedparameters);
    }
  }

  public static StringWrapper javaTranslateFunctionName(MethodSlot function) {
    { Symbol functionname = Symbol.yieldRenamedNameIfNative(function.slotName, Stella.KWD_JAVA, Stella.KWD_FUNCTION);
      String translatedname = null;

      if (MethodSlot.javaMethodObjectIsOverloadedFunctionP(function)) {
        functionname = Symbol.javaCreateOverloadedFunctionName(functionname, function.slotOwner);
      }
      translatedname = Symbol.javaTranslateName(functionname).wrapperValue;
      if (function.methodSetterP) {
        translatedname = translatedname + "_setter";
      }
      if (MethodSlot.slotReaderP(function)) {
        translatedname = translatedname + "_reader";
      }
      return (Stella.wrapString(translatedname));
    }
  }

  public static Cons javaTranslateParamTypeSpecifications(MethodSlot fn, StandardObject owner) {
    { Cons paramclasses = Stella.NIL;
      boolean skipparameterP = (!fn.methodFunctionP) &&
          (!MethodSlot.javaMethodObjectDefinedOnNativeTypeP(fn));

      { StandardObject ts = null;
        Cons iter000 = fn.methodParameterTypeSpecifiers().theConsList;

        while (!(iter000 == Stella.NIL)) {
          {
            ts = ((StandardObject)(iter000.value));
            iter000 = iter000.rest;
          }
          if (skipparameterP) {
            skipparameterP = Stella.FALSE;
          }
          else if (Stella_Object.anchoredTypeSpecifierP(ts)) {
            paramclasses = Stella_Object.cons(StandardObject.javaYieldClassObjectExpression(StandardObject.computeAnchoredTypeSpec(owner, ((AnchoredTypeSpecifier)(ts)))), paramclasses);
          }
          else {
            paramclasses = Stella_Object.cons(StandardObject.javaYieldClassObjectExpression(ts), paramclasses);
          }
        }
      }
      if (!(fn.methodReturnTypeSpecifiers().rest() == Stella.NIL)) {
        paramclasses = Stella_Object.cons(StandardObject.javaYieldClassObjectArrayExpression(Stella.SGT_STELLA_NATIVE_OBJECT_POINTER, 1), paramclasses);
      }
      return (Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_JAVA_ANONYMOUS_ARRAY, Stella_Object.cons(Stella.wrapString("java.lang.Class"), Stella_Object.cons(paramclasses.reverse().concatenate(Stella.NIL, Stella.NIL), Stella.NIL)))));
    }
  }

  public static StringWrapper javaYieldTranslatedClassAndFunctionNames(MethodSlot f, Object [] MV_returnarray) {
    if (MethodSlot.javaFlotsamFunctionP(f)) {
      { StringWrapper _return_temp = Stella.wrapString(Module.javaPackagePrefix(f.homeModule(), ".") + Module.javaYieldFlotsamClassName(f.homeModule()));

        MV_returnarray[0] = MethodSlot.javaTranslateFunctionName(f);
        return (_return_temp);
      }
    }
    else if (((BooleanWrapper)(KeyValueList.dynamicSlotValue(f.dynamicSlots, Stella.SYM_STELLA_METHOD_NATIVEp, Stella.FALSE_WRAPPER))).wrapperValue) {
      { StringWrapper _return_temp = Stella.wrapString(Stella.javaYieldFullNativeClassName());

        MV_returnarray[0] = MethodSlot.javaTranslateFunctionName(f);
        return (_return_temp);
      }
    }
    else if (f.methodStartupFunctionP()) {
      { StringWrapper _return_temp = Stella.wrapString(Module.javaPackagePrefix(f.homeModule(), ".") + StringWrapper.javaTranslateClassNamestring(Stella.wrapString(((StringWrapper)(KeyValueList.dynamicSlotValue(f.dynamicSlots, Stella.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.NULL_STRING_WRAPPER))).wrapperValue)).wrapperValue);

        MV_returnarray[0] = MethodSlot.javaTranslateFunctionName(f);
        return (_return_temp);
      }
    }
    else if (((BooleanWrapper)(KeyValueList.dynamicSlotValue(f.dynamicSlots, Stella.SYM_STELLA_METHOD_CONSTRUCTORp, Stella.FALSE_WRAPPER))).wrapperValue) {
      { StringWrapper _return_temp = StandardObject.javaYieldFullyQualifiedTypeName(((StandardObject)(f.methodReturnTypeSpecifiers().first())));

        MV_returnarray[0] = MethodSlot.javaTranslateFunctionName(f);
        return (_return_temp);
      }
    }
    else {
      { StringWrapper _return_temp = StandardObject.javaYieldFullyQualifiedTypeName(((StandardObject)(f.methodParameterTypeSpecifiers().first())));

        MV_returnarray[0] = MethodSlot.javaTranslateFunctionName(f);
        return (_return_temp);
      }
    }
  }

  public static Cons javaTranslateMethodSignature(MethodSlot method) {
    { Cons modifiers = Stella.NIL;
      Cons returntype = null;

      if (MethodSlot.javaSynchronizedMethodP(method)) {
        modifiers = Stella_Object.cons(Stella.wrapString("synchronized"), modifiers);
      }
      if (MethodSlot.javaMethodObjectIsFunctionP(method)) {
        modifiers = Stella_Object.cons(Stella.wrapString("static"), modifiers);
      }
      if (method.abstractP) {
        modifiers = Stella_Object.cons(Stella.wrapString("abstract"), modifiers);
      }
      if (method.publicP()) {
        modifiers = Stella_Object.cons(Stella.wrapString("public"), modifiers);
      }
      returntype = Stella_Object.cons(StandardObject.javaTranslateTypeSpec(MethodSlot.computeMostGeneralReturnType(method, method.computeReturnTypeSpec(method.slotOwner))), Stella.NIL);
      return (Stella_Object.cons(modifiers, Stella_Object.cons(returntype, Stella_Object.cons(method.javaTranslateMethodName(), Stella_Object.cons(MethodSlot.javaTranslateMethodParameters(method), Stella.NIL)))));
    }
  }

  public static boolean javaSynchronizedMethodP(MethodSlot method) {
    method = method;
    return (Stella.FALSE);
  }

  public static boolean javaFlotsamFunctionP(MethodSlot method) {
    return ((!((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_CONSTRUCTORp, Stella.FALSE_WRAPPER))).wrapperValue) &&
        ((!((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_NATIVEp, Stella.FALSE_WRAPPER))).wrapperValue) &&
         ((!method.methodStartupFunctionP()) &&
          (MethodSlot.zeroArgumentFunctionP(method) ||
           (MethodSlot.javaMethodObjectDefinedOnNativeTypeP(method) ||
            MethodSlot.javaFunctionInDifferentModuleP(method))))));
  }

  public static boolean cppNativeMethodP(MethodSlot methodslot) {
    { Symbol testValue000 = methodslot.slotName;

      if ((testValue000 == Stella.SYM_STELLA_DEFINEDp) ||
          (testValue000 == Stella.SYM_STELLA_NULLp)) {
        return (Stella.TRUE);
      }
      else {
        return (Stella.FALSE);
      }
    }
  }

  public static Cons cppYieldConstructorSignatureTree(MethodSlot method) {
    Native.setSpecial(Stella.$METHODBEINGWALKED$, method);
    return (Stella_Object.cons(GeneralizedSymbol.cppTranslateClassName(Stella.internSymbolInModule(method.slotOwner.symbolName, ((Module)(method.slotOwner.homeContext)), Stella.TRUE)), Stella.list$(Stella_Object.cons(Stella.NIL, Stella_Object.cons(MethodSlot.cppTranslateConstructorName(method), Stella_Object.cons(Stella_Object.cons(MethodSlot.cppTranslateFunctionParameters(method), Stella.NIL), Stella.NIL))))));
  }

  public static Cons cppYieldMemberFuncSignatureTree(MethodSlot method) {
    Native.setSpecial(Stella.$METHODBEINGWALKED$, method);
    return (Stella_Object.cons((method.methodFunctionP ? null : GeneralizedSymbol.cppTranslateClassName(Stella.internSymbolInModule(method.slotOwner.symbolName, ((Module)(method.slotOwner.homeContext)), Stella.TRUE))), Stella.list$(Stella_Object.cons(Stella_Object.cons(Stella.wrapString("virtual"), Stella_Object.cons(StandardObject.cppTranslateAndPointerizeTypeSpec(MethodSlot.computeMostGeneralReturnType(method, method.computeReturnTypeSpec(method.slotOwner))), Stella.NIL)), Stella_Object.cons(MethodSlot.cppTranslateFunctionName(method), Stella_Object.cons(Stella_Object.cons(MethodSlot.cppTranslateFunctionParameters(method), Stella.NIL), Stella.NIL))))));
  }

  public static boolean cppMethodObjectIsOverloadedFunctionP(MethodSlot method) {
    return ((!method.methodFunctionP) &&
        ((((StringWrapper)(KeyValueList.dynamicSlotValue(((Stella_Class)(method.slotOwner.surrogateValue)).dynamicSlots, Stella.SYM_STELLA_CLASS_CPP_NATIVE_TYPE, Stella.NULL_STRING_WRAPPER))).wrapperValue != null) &&
         ((!((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_NATIVEp, Stella.FALSE_WRAPPER))).wrapperValue) ||
          Surrogate.subtypeOfP(method.slotOwner, Stella.SGT_STELLA_LITERAL))));
  }

  public static boolean cppMethodObjectIsFunctionP(MethodSlot method) {
    return (method.methodFunctionP ||
        MethodSlot.cppMethodObjectIsOverloadedFunctionP(method));
  }

  public static StringWrapper cppTranslateMethodName(MethodSlot method) {
    { Surrogate methodtype = method.slotOwner;
      StringWrapper translatedname = MethodSlot.cppTranslateFunctionName(method);

      if (MethodSlot.cppMethodObjectIsFunctionP(method)) {
        return (translatedname);
      }
      else {
        return (Stella.wrapString(GeneralizedSymbol.cppTranslateClassName(Stella.internSymbolInModule(methodtype.symbolName, ((Module)(methodtype.homeContext)), Stella.TRUE)).wrapperValue + "::" + translatedname.wrapperValue));
      }
    }
  }

  public static StringWrapper cppTranslateFunctionName(MethodSlot function) {
    { Symbol functionname = Symbol.yieldRenamedNameIfNative(function.slotName, Stella.KWD_CPP, Stella.KWD_FUNCTION);
      String translatedname = null;

      if (MethodSlot.cppMethodObjectIsOverloadedFunctionP(function)) {
        functionname = Symbol.cppCreateOverloadedFunctionName(functionname, function.slotOwner);
      }
      translatedname = Symbol.cppTranslateName(functionname).wrapperValue;
      if (function.methodSetterP) {
        translatedname = translatedname + "_setter";
      }
      if (MethodSlot.slotReaderP(function)) {
        translatedname = translatedname + "_reader";
      }
      return (Stella.wrapString(Stella.cppYieldQualifiedName(translatedname, Symbol.cppFixupNameSymbol(function.slotName, function.homeModule()))));
    }
  }

  public static StringWrapper cppTranslateConstructorName(MethodSlot constructor) {
    return (GeneralizedSymbol.cppTranslateClassName(constructor.slotName));
  }

  public static boolean slotReaderP(MethodSlot method) {
    { Slot lookedupslot = null;

      if (!(method.methodFunctionP)) {
        lookedupslot = Stella_Class.lookupSlot(((Stella_Class)(method.slotOwner.surrogateValue)), method.slotName);
      }
      return ((lookedupslot != null) &&
          Stella_Object.isaP(lookedupslot, Stella.SGT_STELLA_STORAGE_SLOT));
    }
  }

  public static Cons cppTranslateFunctionParameters(MethodSlot method) {
    { boolean skipfirstparameterP = !MethodSlot.cppMethodObjectIsFunctionP(method);
      boolean variableargumentsP = ((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, Stella.FALSE_WRAPPER))).wrapperValue &&
          (!MethodSlot.passVariableArgumentsAsListP(method));
      Cons translatedparameters = Stella.NIL;

      { int i = Stella.NULL_INTEGER;
        StandardObject ptype = null;
        Symbol pname = null;
        Cons iter000 = method.methodParameterNames().theConsList;
        Cons iter001 = method.methodParameterTypeSpecifiers().theConsList;
        int iter002 = 1;
        Cons collect000 = null;

        while ((!(iter000 == Stella.NIL)) &&
            (!(iter001 == Stella.NIL))) {
          {
            pname = ((Symbol)(iter000.value));
            iter000 = iter000.rest;
          }
          {
            ptype = ((StandardObject)(iter001.value));
            iter001 = iter001.rest;
          }
          {
            i = iter002;
            iter002 = iter002 + 1;
          }
          if (((!skipfirstparameterP) ||
              (i > 1)) &&
              ((!variableargumentsP) ||
               (!(pname == MethodSlot.variableArgumentsName(method))))) {
            if (collect000 == null) {
              {
                collect000 = Stella_Object.cons(Symbol.cppTranslateFunctionParameter(pname, ptype, method), Stella.NIL);
                if (translatedparameters == Stella.NIL) {
                  translatedparameters = collect000;
                }
                else {
                  Cons.addConsToEndOfConsList(translatedparameters, collect000);
                }
              }
            }
            else {
              {
                collect000.rest = Stella_Object.cons(Symbol.cppTranslateFunctionParameter(pname, ptype, method), Stella.NIL);
                collect000 = collect000.rest;
              }
            }
          }
        }
      }
      { int rtypeindex = Stella.NULL_INTEGER;
        StandardObject rtype = null;
        Cons iter003 = method.methodReturnTypeSpecifiers().rest();
        int iter004 = 1;
        Cons collect001 = null;

        while (!(iter003 == Stella.NIL)) {
          {
            rtype = ((StandardObject)(iter003.value));
            iter003 = iter003.rest;
          }
          {
            rtypeindex = iter004;
            iter004 = iter004 + 1;
          }
          if (collect001 == null) {
            {
              collect001 = Stella_Object.cons(Stella.cppTranslateReturnParameter(rtypeindex, rtype), Stella.NIL);
              if (translatedparameters == Stella.NIL) {
                translatedparameters = collect001;
              }
              else {
                Cons.addConsToEndOfConsList(translatedparameters, collect001);
              }
            }
          }
          else {
            {
              collect001.rest = Stella_Object.cons(Stella.cppTranslateReturnParameter(rtypeindex, rtype), Stella.NIL);
              collect001 = collect001.rest;
            }
          }
        }
      }
      return (translatedparameters.concatenate(((variableargumentsP ? Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_CPP_VAR_ARGS, Stella_Object.cons(Symbol.cppTranslateName(MethodSlot.variableArgumentsName(method)), Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.NIL) : Stella.NIL)).concatenate(Stella.NIL, Stella.NIL), Stella.NIL));
    }
  }

  public void printDocumentation(OutputStream stream, boolean shortP) {
    { MethodSlot self = this;

      if (stream == null) {
        stream = Stella.STANDARD_OUTPUT;
      }
      { String documentation = ((StringWrapper)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_DOCUMENTATION, Stella.NULL_STRING_WRAPPER))).wrapperValue;

        stream.nativeStream.print(self.slotName);
        if (!(shortP)) {
          stream.nativeStream.print(" ");
          OutputStream.prettyPrintMethodParameters(stream, self);
        }
        stream.nativeStream.println(":");
        Stella.printDocumentationString((shortP ? Stella.shortDocumentation(documentation) : documentation), 2, stream);
      }
    }
  }

  public void prettyPrintObject(OutputStream stream) {
    { MethodSlot self = this;

      stream.nativeStream.print("(" + Native.stringDowncase(self.slotName.symbolName) + " ");
      OutputStream.prettyPrintMethodParameters(stream, self);
      stream.nativeStream.print(" :type ");
      stream.nativeStream.print((((((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null))) != null) ? Native.stringify(StandardObject.yieldTypeSpecTree(((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null))))) : Native.stringify(StandardObject.yieldTypeSpecTree(self.slotBaseType)))));
      stream.nativeStream.print(")");
    }
  }

  public static Cons clTranslateMethodParameters(MethodSlot method) {
    { boolean functionP = method.methodFunctionP;
      Cons otree = Stella.NIL;
      Stella_Object oparameter = null;
      Stella_Object firstparametertype = null;

      { int i = Stella.NULL_INTEGER;
        StandardObject ptype = null;
        Symbol parameter = null;
        Cons iter000 = method.methodParameterNames().theConsList;
        Cons iter001 = method.methodParameterTypeSpecifiers().theConsList;
        int iter002 = 1;

        while ((!(iter000 == Stella.NIL)) &&
            (!(iter001 == Stella.NIL))) {
          {
            parameter = ((Symbol)(iter000.value));
            iter000 = iter000.rest;
          }
          {
            ptype = ((StandardObject)(iter001.value));
            iter001 = iter001.rest;
          }
          {
            i = iter002;
            iter002 = iter002 + 1;
          }
          oparameter = Symbol.clTranslateLocalSymbol(parameter);
          if ((!functionP) &&
              (i == 1)) {
            firstparametertype = Stella_Class.clTranslateClassName(Surrogate.typeToClass(StandardObject.typeSpecToBaseType(ptype)));
            { Symbol testValue000 = Symbol.methodCallTypeForVectorStructs(method.slotName, method.slotOwner, functionP);

              if (testValue000 == Stella.SYM_STELLA_OBJECT_METHOD) {
                otree = Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_CLSYS_SELF, Stella_Object.cons(firstparametertype, Stella_Object.cons(Stella.NIL, Stella.NIL)))), otree);
                otree = Stella_Object.cons(oparameter, otree);
              }
              else if (testValue000 == Stella.SYM_STELLA_NON_OBJECT_METHOD) {
                otree = Stella_Object.cons(Stella_Object.cons(oparameter, Stella_Object.cons(firstparametertype, Stella.NIL)), otree);
                otree = Stella_Object.cons(Stella.SYM_STELLA_CLSYS_DUMMY, otree);
              }
              else {
                otree = Stella_Object.cons(Stella_Object.cons(oparameter, Stella_Object.cons(firstparametertype, Stella.NIL)), otree);
              }
            }
          }
          else {
            otree = Stella_Object.cons(oparameter, otree);
          }
        }
      }
      if (((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, Stella.FALSE_WRAPPER))).wrapperValue &&
          (!MethodSlot.passVariableArgumentsAsListP(method))) {
        otree.rest = Stella_Object.cons(Stella.internCommonLispSymbol("&REST"), otree.rest.concatenate(Stella.NIL, Stella.NIL));
      }
      return (otree.reverse());
    }
  }

  public static Cons clYieldMethodTypeDeclarationTree(MethodSlot method) {
    if (!(method.methodFunctionP)) {
      return (null);
    }
    { Stella_Object cltype = StandardObject.lookupClTypeFromStellaType(method.slotBaseType);

      if (cltype != null) {
        return (Stella.list$(Stella_Object.cons(Stella.internCommonLispSymbol("FTYPE"), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.internCommonLispSymbol("FUNCTION"), Stella_Object.cons(MethodSlot.clYieldMethodArglistTypeDeclarations(method), Stella_Object.cons(Stella_Object.cons(MethodSlot.clYieldMethodReturnTypeDeclaration(method), Stella.NIL), Stella.NIL)))), Stella_Object.cons(Symbol.clTranslateGlobalSymbol(method.slotName), Stella_Object.cons(Stella.NIL, Stella.NIL))))));
      }
      else {
        return (null);
      }
    }
  }

  public static Stella_Object clYieldMethodReturnTypeDeclaration(MethodSlot method) {
    { Cons types = Stella.NIL;
      Symbol cltype = null;

      { StandardObject tspec = null;
        Cons iter000 = method.methodReturnTypeSpecifiers().theConsList;

        while (!(iter000 == Stella.NIL)) {
          {
            tspec = ((StandardObject)(iter000.value));
            iter000 = iter000.rest;
          }
          cltype = ((Symbol)(StandardObject.lookupClTypeFromStellaType(StandardObject.computeRelativeTypeSpec(tspec, method.slotOwner))));
          if (cltype != null) {
            types = Stella_Object.cons(cltype, types);
          }
          else {
            types = Stella_Object.cons(Stella.internCommonLispSymbol("T"), types);
          }
        }
      }
      if (types.rest == Stella.NIL) {
        return (types.value);
      }
      else {
        return (Stella_Object.cons(Stella.internCommonLispSymbol("VALUES"), types.reverse().concatenate(Stella.NIL, Stella.NIL)));
      }
    }
  }

  public static Cons clYieldMethodArglistTypeDeclarations(MethodSlot method) {
    { Cons types = Stella.NIL;
      Symbol cltype = null;

      { StandardObject tspec = null;
        Cons iter000 = method.methodParameterTypeSpecifiers().theConsList;

        while (!(iter000 == Stella.NIL)) {
          {
            tspec = ((StandardObject)(iter000.value));
            iter000 = iter000.rest;
          }
          cltype = ((Symbol)(StandardObject.lookupClTypeFromStellaType(StandardObject.computeRelativeTypeSpec(tspec, method.slotOwner))));
          if (cltype != null) {
            types = Stella_Object.cons(cltype, types);
          }
          else {
            types = Stella_Object.cons(Stella.internCommonLispSymbol("T"), types);
          }
        }
      }
      return (types.reverse());
    }
  }

  public static Cons clYieldMethodParameterTypeDeclarationTrees(MethodSlot method) {
    { Cons types = Stella.NIL;
      Symbol cltype = null;

      { Symbol pname = null;
        StandardObject tspec = null;
        Cons iter000 = method.methodParameterTypeSpecifiers().theConsList;
        Cons iter001 = method.methodParameterNames().theConsList;

        while ((!(iter000 == Stella.NIL)) &&
            (!(iter001 == Stella.NIL))) {
          {
            tspec = ((StandardObject)(iter000.value));
            iter000 = iter000.rest;
          }
          {
            pname = ((Symbol)(iter001.value));
            iter001 = iter001.rest;
          }
          cltype = ((Symbol)(StandardObject.lookupClTypeFromStellaType(StandardObject.computeRelativeTypeSpec(tspec, method.slotOwner))));
          if (cltype != null) {
            types = Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.internCommonLispSymbol("TYPE"), Stella_Object.cons(cltype, Stella_Object.cons(Stella_Object.cons(Symbol.clTranslateLocalSymbol(pname), Stella.NIL), Stella.NIL)))), types);
          }
        }
      }
      return (types.reverse());
    }
  }

  public static boolean useDefconsmethodP(MethodSlot method) {
    if ((!method.methodFunctionP) &&
        ((List)(Stella.$CURRENT_STELLA_FEATURES$.get())).membP(Stella.KWD_USE_COMMON_LISP_CONSES)) {
      { Surrogate testValue000 = method.slotOwner;

        if (testValue000 == Stella.SGT_STELLA_CONS) {
          return (Stella.TRUE);
        }
        else if (testValue000 == Stella.SGT_STELLA_STANDARD_OBJECT) {
          if (Stella_Class.lookupSlot(((Stella_Class)(Stella.SGT_STELLA_CONS.surrogateValue)), method.slotName).slotOwner == Stella.SGT_STELLA_CONS) {
            return (Stella.FALSE);
          }
          else {
            return (Stella.TRUE);
          }
        }
        else if (testValue000 == Stella.SGT_STELLA_OBJECT) {
          { Surrogate testValue001 = Stella_Class.lookupSlot(((Stella_Class)(Stella.SGT_STELLA_CONS.surrogateValue)), method.slotName).slotOwner;

            if ((testValue001 == Stella.SGT_STELLA_CONS) ||
                (testValue001 == Stella.SGT_STELLA_STANDARD_OBJECT)) {
              return (Stella.FALSE);
            }
            else {
              return (Stella.TRUE);
            }
          }
        }
        else {
        }
      }
    }
    return (Stella.FALSE);
  }

  public static MethodSlot createEvaluatorWrapperUnit(MethodSlot method) {
    { boolean variableargumentsP = ((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, Stella.FALSE_WRAPPER))).wrapperValue;
      boolean evaluateargumentsP = method.methodEvaluateArgumentsP();
      Cons wrappertree = MethodSlot.yieldEvaluatorWrapperTree(method);
      MethodSlot wrappermethod = null;

      if (method.methodReturnTypeSpecifiers().length() > 1) {
        { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

          try {
            Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
            Stella.signalTranslationWarning();
            if (!(Stella.suppressWarningsP())) {
              Stella.printErrorContext(">> WARNING: ", Stella.STANDARD_WARNING);
              {
                Stella.STANDARD_WARNING.nativeStream.println();
                Stella.STANDARD_WARNING.nativeStream.println(" During interpreted command evaluation only the");
                Stella.STANDARD_WARNING.nativeStream.println(" first return value will be usable.");
              }
;
            }

          } finally {
            Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
          }
        }
      }
      if (!evaluateargumentsP) {
        KeyValueList.setDynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_EVALUATE_ARGUMENTSp, (Stella.TRUE ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER), Stella.FALSE_WRAPPER);
      }
      if (variableargumentsP) {
        KeyValueList.setDynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, (Stella.FALSE ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER), Stella.FALSE_WRAPPER);
      }
      wrappermethod = ((MethodSlot)(Cons.helpWalkAuxiliaryTree(wrappertree, Stella.TRUE).theObject));
      if (!evaluateargumentsP) {
        KeyValueList.setDynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_EVALUATE_ARGUMENTSp, (Stella.FALSE ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER), Stella.FALSE_WRAPPER);
      }
      if (variableargumentsP) {
        KeyValueList.setDynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, (Stella.TRUE ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER), Stella.FALSE_WRAPPER);
      }
      return (wrappermethod);
    }
  }

  public static Cons yieldEvaluatorWrapperTree(MethodSlot method) {
    { Stella_Object nametree = Symbol.yieldEvaluatorWrapperName(method.slotName);
      Cons calltree = Stella_Object.cons(method.slotName, Stella.NIL);
      List parametertypespecs = method.methodParameterTypeSpecifiers();
      Surrogate resulttype = method.type();
      int nofparameters = parametertypespecs.length();
      boolean variableargumentsP = ((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, Stella.FALSE_WRAPPER))).wrapperValue;

      { int index = Stella.NULL_INTEGER;
        int iter000 = 1;
        int upperBound000 = nofparameters;
        boolean unboundedP000 = upperBound000 == Stella.NULL_INTEGER;
        Cons collect000 = null;

        while (unboundedP000 ||
            (iter000 <= upperBound000)) {
          {
            index = iter000;
            iter000 = iter000 + 1;
          }
          if (collect000 == null) {
            {
              collect000 = Stella_Object.cons(Symbol.yieldArgumentAccessTree(Stella.SYM_STELLA_ARGUMENTS, index, variableargumentsP &&
                  (index == nofparameters)), Stella.NIL);
              if (calltree == Stella.NIL) {
                calltree = collect000;
              }
              else {
                Cons.addConsToEndOfConsList(calltree, collect000);
              }
            }
          }
          else {
            {
              collect000.rest = Stella_Object.cons(Symbol.yieldArgumentAccessTree(Stella.SYM_STELLA_ARGUMENTS, index, variableargumentsP &&
                  (index == nofparameters)), Stella.NIL);
              collect000 = collect000.rest;
            }
          }
        }
      }
      { StandardObject ptype = null;
        Cons iter001 = parametertypespecs.theConsList;
        ConsIterator it = calltree.rest.allocateIterator();

        while ((!(iter001 == Stella.NIL)) &&
            it.nextP()) {
          {
            ptype = ((StandardObject)(iter001.value));
            iter001 = iter001.rest;
          }
          if (StandardObject.subTypeSpecOfP(ptype, Stella.SGT_STELLA_LITERAL)) {
            it.valueSetter(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_WRAPPER_VALUE, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SAFE_CAST, Stella_Object.cons(it.value, Stella_Object.cons(Stella_Object.cons(StandardObject.typeSpecToBaseType(ptype).typeToWrappedType(), Stella.NIL), Stella.NIL)))), Stella_Object.cons(Stella.NIL, Stella.NIL)))));
          }
          else if (StandardObject.subTypeSpecOfP(ptype, Stella.SGT_STELLA_ARGUMENT_LIST)) {
            Symbol.pushVariableBinding(Stella.SYM_STELLA_ARGUMENTS, MethodSlot.yieldListifiedVariableArgumentsType(method));
            it.valueSetter(Stella_Object.sysTree(Stella_Object.walkWithoutTypeTree(it.value), ptype, new Object[1]));
            Stella.popVariableBinding();
          }
          else if (!(ptype == Stella.SGT_STELLA_OBJECT)) {
            it.valueSetter(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SAFE_CAST, Stella_Object.cons(it.value, Stella_Object.cons(Stella_Object.cons(StandardObject.yieldTypeSpecTree(ptype), Stella.NIL), Stella.NIL)))));
          }
        }
      }
      if (StandardObject.voidP(resulttype)) {
      }
      else if (Surrogate.subtypeOfP(resulttype, Stella.SGT_STELLA_LITERAL)) {
        nametree = Stella_Object.cons(nametree, Stella_Object.cons(resulttype.typeToWrappedType(), Stella.NIL));
        if (method.type() == Stella.SGT_STELLA_BOOLEAN) {
          calltree = Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_RETURN, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_WRAP_BOOLEAN, Stella_Object.cons(calltree, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.NIL, Stella.NIL))));
        }
        else {
          calltree = Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_LET, Stella_Object.cons(Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_RESULT, Stella_Object.cons(calltree, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.NIL), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_IF, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_DEFINEDp, Stella_Object.cons(Stella.SYM_STELLA_RESULT, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_RETURN, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_WRAP_LITERAL, Stella_Object.cons(Stella.SYM_STELLA_RESULT, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_RETURN, Stella_Object.cons(Stella.SYM_STELLA_NULL, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.NIL, Stella.NIL)))))), Stella_Object.cons(Stella.NIL, Stella.NIL)))));
        }
      }
      else {
        nametree = Stella_Object.cons(nametree, Stella_Object.cons(resulttype, Stella.NIL));
        calltree = Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_RETURN, Stella_Object.cons(calltree, Stella_Object.cons(Stella.NIL, Stella.NIL))));
      }
      return (Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_DEFUN, Stella_Object.cons(nametree, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_ARGUMENTS, Stella_Object.cons(Stella.SYM_STELLA_CONS, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.NIL), Stella_Object.cons(Stella.KWD_AUXILIARYp, Stella_Object.cons(Stella.SYM_STELLA_TRUE, Stella_Object.cons((((nofparameters == 0) ? Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_IGNORE, Stella_Object.cons(Stella.SYM_STELLA_ARGUMENTS, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.NIL) : Stella.NIL)).concatenate(Stella_Object.cons(calltree, Stella.NIL), Stella.NIL), Stella.NIL))))), Stella.NIL)))));
    }
  }

  public static boolean methodNeedsEvaluatorWrapperP(MethodSlot method) {
    { boolean testValue000 = Stella.FALSE;

      testValue000 = MethodSlot.methodMustBeEvaluableP(method);
      if (testValue000) {
        if (((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, Stella.FALSE_WRAPPER))).wrapperValue) {
          testValue000 = Stella.TRUE;
        }
        else {
          if (method.methodParameterNames().length() > 5) {
            testValue000 = Stella.TRUE;
          }
          else {
            if (method.methodReturnTypeSpecifiers().length() > 1) {
              testValue000 = Stella.TRUE;
            }
            else {
              if (Surrogate.subtypeOfP(method.type(), Stella.SGT_STELLA_LITERAL)) {
                testValue000 = Stella.TRUE;
              }
              else {
                { boolean foundP000 = Stella.FALSE;

                  { StandardObject tspec = null;
                    Cons iter000 = method.methodParameterTypeSpecifiers().theConsList;

                    loop000 : while (!(iter000 == Stella.NIL)) {
                      {
                        tspec = ((StandardObject)(iter000.value));
                        iter000 = iter000.rest;
                      }
                      if (Surrogate.subtypeOfP(StandardObject.typeSpecToBaseType(tspec), Stella.SGT_STELLA_LITERAL)) {
                        foundP000 = Stella.TRUE;
                        break loop000;
                      }
                    }
                  }
                  testValue000 = foundP000;
                }
              }
            }
          }
        }
      }
      { boolean value000 = testValue000;

        return (value000);
      }
    }
  }

  public static boolean methodMustBeEvaluableP(MethodSlot method) {
    return (MethodSlot.commandP(method) &&
        (!((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_NATIVEp, Stella.FALSE_WRAPPER))).wrapperValue));
  }

  /** Return <code>true</code> if <code>method</code> is an evaluable command.
   * @param method
   * @return boolean
   */
  public static boolean commandP(MethodSlot method) {
    return (((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_COMMANDp, Stella.FALSE_WRAPPER))).wrapperValue &&
        method.methodFunctionP);
  }

  public static boolean methodNeedsLispMacroP(MethodSlot method) {
    if (Stella.translateToCommonLispP() &&
        method.methodParameterNames().nonEmptyP()) {
      { BooleanWrapper lispmacroP = ((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_LISP_MACROp, null)));

        return (((lispmacroP != null) &&
            BooleanWrapper.coerceWrappedBooleanToBoolean(lispmacroP)) ||
            (MethodSlot.commandP(method) &&
             ((!((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_NATIVEp, Stella.FALSE_WRAPPER))).wrapperValue) &&
              ((lispmacroP == null) ||
               BooleanWrapper.coerceWrappedBooleanToBoolean(lispmacroP)))));
      }
    }
    else {
      return (Stella.FALSE);
    }
  }

  public boolean methodStartupFunctionP() {
    { MethodSlot method = this;

      return (((StringWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.NULL_STRING_WRAPPER))).wrapperValue != null);
    }
  }

  public static Cons yieldMixinMethodTree(MethodSlot method, Stella_Class renamed_Class) {
    { Cons tree = ((Cons)(Stella.unstringifyStellaSource(method.methodStringifiedSource, method.homeModule())));
      Cons parameters = ((Cons)(tree.rest.rest.value));
      Cons selftree = ((Cons)(parameters.value));
      Stella_Object selftypetree = StandardObject.yieldTypeSpecTree(((StandardObject)(method.methodParameterTypeSpecifiers().first())));
      Cons body = tree.nthRest(3);

      if (Stella_Object.safePrimaryType(selftypetree) == Stella.SGT_STELLA_CONS) {
        { Cons selftypetree000 = ((Cons)(selftypetree));

          selftypetree000.firstSetter(StandardObject.yieldTypeSpecTree(renamed_Class.classType));
        }
      }
      else {
        selftypetree = StandardObject.yieldTypeSpecTree(renamed_Class.classType);
      }
      Cons.lastCons(selftree).firstSetter(selftypetree);
      if (renamed_Class == ((Stella_Class)(Stella.SGT_STELLA_OBJECT.surrogateValue))) {
        body = Cons.extractOptions(tree, null).concatenate(Stella_Object.cons(Stella.SYM_STELLA_NULL, Stella.NIL), Stella.NIL);
      }
      return (Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_DEFMETHOD, Stella_Object.cons(tree.rest.value, Stella_Object.cons(Stella_Object.cons(parameters, Stella.list$(Stella_Object.cons(Stella.KWD_AUXILIARYp, Stella_Object.cons(Stella.SYM_STELLA_TRUE, Stella_Object.cons(Stella.KWD_PUBLICp, Stella_Object.cons((method.slotPublicP ? Stella.SYM_STELLA_TRUE : Stella.SYM_STELLA_FALSE), Stella_Object.cons(body.concatenate(Stella.NIL, Stella.NIL), Stella.NIL))))))), Stella.NIL)))));
    }
  }

  public static void registerAuxiliaryMethod(MethodSlot method, Slot reason) {
    if (method != null) {
      { Stella_Class renamed_Class = ((Stella_Class)(method.slotOwner.surrogateValue));
        List auxiliarymethods = null;

        if (renamed_Class != null) {
          auxiliarymethods = renamed_Class.classAuxiliaryMethods();
          if (List.nullListP(auxiliarymethods)) {
            auxiliarymethods = ((List)(KeyValueList.setDynamicSlotValue(renamed_Class.dynamicSlots, Stella.SYM_STELLA_CLASS_AUXILIARY_METHODS, List.newList(), null)));
          }
          MethodSlot.finalizeAuxiliaryMethod(method);
          { MethodSlot value000 = null;

            { MethodSlot aux = null;
              Cons iter000 = auxiliarymethods.theConsList;

              loop000 : while (!(iter000 == Stella.NIL)) {
                {
                  aux = ((MethodSlot)(iter000.value));
                  iter000 = iter000.rest;
                }
                if ((method.slotName == aux.slotName) &&
                    (method.slotOwner == aux.slotOwner)) {
                  value000 = aux;
                  break loop000;
                }
              }
            }
            auxiliarymethods.remove(value000);
          }
          auxiliarymethods.insert(method);
          KeyValueList.setDynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_AUXILIARY_METHOD_REASON, reason, null);
        }
      }
    }
  }

  public static Cons yieldVerbatimInlineCallTree(MethodSlot method, Cons walkedargs) {
    return (Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SYS_INLINE_CALL, Stella_Object.cons(Stella_Object.cons((method.methodFunctionP ? Stella.SYM_STELLA_SYS_CALL_FUNCTION : Stella.SYM_STELLA_SYS_CALL_METHOD), ((method.methodFunctionP ? Stella.NIL : Stella_Object.cons(method.slotOwner, Stella.NIL))).concatenate(Stella_Object.cons(method.slotName, walkedargs.concatenate(Stella.NIL, Stella.NIL)), Stella.NIL)), Stella_Object.cons(Stella.NIL, Stella.NIL)))));
  }

  public static Stella_Object walkInlineMethodCall(MethodSlot method, Cons walkedargs) {
    { Stella_Object body = MethodSlot.inlinableMethodBody(method);
      int nofreferences = Stella.NULL_INTEGER;
      Stella_Object inlinearg = null;
      boolean successP = Stella.TRUE;

      if (Stella_Object.verbatimTreeP(body) &&
          (Cons.lookupVerbatimTree(((Cons)(body)), null) != null)) {
        return (MethodSlot.yieldVerbatimInlineCallTree(method, walkedargs));
      }
      body = Stella_Object.copyConsTree(body);
      { Object old$InliningmethodcallP$000 = Stella.$INLININGMETHODCALLp$.get();
        Object old$Methodbeingwalked$000 = Stella.$METHODBEINGWALKED$.get();

        try {
          Native.setBooleanSpecial(Stella.$INLININGMETHODCALLp$, Stella.TRUE);
          Native.setSpecial(Stella.$METHODBEINGWALKED$, method);
          { Stella_Object arg = null;
            StandardObject tspec = null;
            Symbol var = null;
            Cons iter000 = method.methodParameterNames().theConsList;
            Cons iter001 = method.methodParameterTypeSpecifiers().theConsList;
            Cons iter002 = walkedargs;

            while ((!(iter000 == Stella.NIL)) &&
                ((!(iter001 == Stella.NIL)) &&
                 (!(iter002 == Stella.NIL)))) {
              {
                var = ((Symbol)(iter000.value));
                iter000 = iter000.rest;
              }
              {
                tspec = ((StandardObject)(iter001.value));
                iter001 = iter001.rest;
              }
              {
                arg = iter002.value;
                iter002 = iter002.rest;
              }
              Symbol.walkADeclaration(var, tspec, null, Stella.TRUE);
              Symbol.setLocalVariableInfo(var, Stella.KWD_INLINE_ARGUMENT, arg);
              Symbol.setLocalVariableInfo(var, Stella.KWD_INLINE_REFERENCES, Stella.wrapInteger(0));
            }
          }
          body = Stella_Object.walkExpressionTree(body, method.type(), Stella.SYM_STELLA_INLINE_CALL, Stella.TRUE, new Object[1]);

        } finally {
          Stella.$METHODBEINGWALKED$.set(old$Methodbeingwalked$000);
          Stella.$INLININGMETHODCALLp$.set(old$InliningmethodcallP$000);
        }
      }
      if (Stella_Object.proceduralExpressionP(body)) {
        successP = Stella.FALSE;
      }
      if (successP) {
        { Symbol var = null;
          Cons iter003 = method.methodParameterNames().theConsList;

          loop001 : while (!(iter003 == Stella.NIL)) {
            {
              var = ((Symbol)(iter003.value));
              iter003 = iter003.rest;
            }
            inlinearg = Symbol.getLocalVariableInfo(var, Stella.KWD_INLINE_ARGUMENT);
            nofreferences = ((IntegerWrapper)(Symbol.getLocalVariableInfo(var, Stella.KWD_INLINE_REFERENCES))).wrapperValue;
            switch (nofreferences) {
              case 0: 
                if (!Stella_Object.sideEffectFreeExpressionP(inlinearg)) {
                  successP = Stella.FALSE;
                  break loop001;
                }
              break;
              case 1: 
              break;
              default:
                if (!(Stella_Object.sideEffectFreeExpressionP(inlinearg) &&
                    ((Stella_Object.estimatedEvaluationCost(inlinearg) * nofreferences) <= 2))) {
                  successP = Stella.FALSE;
                  break loop001;
                }
              break;
            }
          }
        }
      }
      { Symbol var = null;
        Cons iter004 = method.methodParameterNames().theConsList;

        while (!(iter004 == Stella.NIL)) {
          {
            var = ((Symbol)(iter004.value));
            iter004 = iter004.rest;
          }
          var = var;
          Stella.popVariableBinding();
        }
      }
      return ((successP ? body : null));
    }
  }

  public static Stella_Object inlinableMethodBody(MethodSlot method) {
    { Cons definition = null;
      Stella_Object body = KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_CACHED_INLINABLE_METHOD_BODY, null);

      if (body == method) {
        return (null);
      }
      if (body != null) {
        return (body);
      }
      definition = ((Cons)(Stella.unstringifyStellaSource(method.methodStringifiedSource, method.homeModule())));
      Cons.extractOptions(definition, null);
      KeyValueList.setDynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_CACHED_INLINABLE_METHOD_BODY, method, null);
      if (definition.length() == 4) {
        body = definition.last();
        if (Stella_Object.safePrimaryType(body) == Stella.SGT_STELLA_CONS) {
          { Cons body000 = ((Cons)(body));

            if ((body000.value == Stella.SYM_STELLA_RETURN) &&
                (Stella_Object.verbatimTreeP(body000.rest.value) ||
                 (!Stella_Object.searchConsTreeP(body000, Stella.SYM_STELLA_VERBATIM)))) {
              return (KeyValueList.setDynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_CACHED_INLINABLE_METHOD_BODY, Stella_Object.permanentifyForm(body000.rest.value), null));
            }
          }
        }
        else {
        }
      }
      return (null);
    }
  }

  public static boolean mostSpecificMethodP(MethodSlot method) {
    { boolean alwaysP000 = Stella.TRUE;

      { Surrogate sub = null;
        Cons iter000 = ((Stella_Class)(method.slotOwner.surrogateValue)).classDirectSubs.theConsList;

        loop000 : while (!(iter000 == Stella.NIL)) {
          {
            sub = ((Surrogate)(iter000.value));
            iter000 = iter000.rest;
          }
          if (!Stella_Class.helpMostSpecificMethodP(((Stella_Class)(sub.surrogateValue)), method)) {
            alwaysP000 = Stella.FALSE;
            break loop000;
          }
        }
      }
      { boolean value000 = alwaysP000;

        return (value000);
      }
    }
  }

  public static boolean methodInlinableP(MethodSlot method) {
    if (StandardObject.voidP(method.type()) ||
        ((method.methodReturnTypeSpecifiers().length() > 1) ||
         ((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, Stella.FALSE_WRAPPER))).wrapperValue)) {
      return (Stella.FALSE);
    }
    if (method.methodFunctionP ||
        MethodSlot.mostSpecificMethodP(method)) {
      return (MethodSlot.inlinableMethodBody(method) != null);
    }
    else {
      { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

        try {
          Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
          Stella.signalTranslationWarning();
          if (!(Stella.suppressWarningsP())) {
            Stella.printErrorContext(">> WARNING: ", Stella.STANDARD_WARNING);
            {
              Stella.STANDARD_WARNING.nativeStream.println();
              Stella.STANDARD_WARNING.nativeStream.println(" Cannot inline method `" + Stella_Object.deUglifyParseTree(method) + "', since there are");
              Stella.STANDARD_WARNING.nativeStream.println(" one or more methods that specialize it.");
            }
;
          }

        } finally {
          Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
        }
      }
      return (Stella.FALSE);
    }
  }

  public static boolean inlineMethodCallP(MethodSlot method) {
    return (Stella.methodCallInliningEnabledP() &&
        ((((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_GLOBALLY_INLINEp, Stella.FALSE_WRAPPER))).wrapperValue ||
        ((((MethodSlot)(Stella.$METHODBEINGWALKED$.get())) != null) &&
         ((MethodSlot)(Stella.$METHODBEINGWALKED$.get())).methodInlinedFunctions().memberP(method.slotName))) &&
         MethodSlot.methodInlinableP(method)));
  }

  public static StandardObject walkFirstArgumentToFunction(MethodSlot fnslot, Cons tree) {
    { List ptypespecs = fnslot.methodParameterTypeSpecifiers();
      StandardObject targetts = ((StandardObject)(ptypespecs.first()));

      if (!fnslot.methodEvaluateArgumentsP()) {
        tree.rest = MethodSlot.quoteArguments(fnslot, tree.rest);
      }
      if (((BooleanWrapper)(KeyValueList.dynamicSlotValue(fnslot.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, Stella.FALSE_WRAPPER))).wrapperValue &&
          (ptypespecs.length() == 1)) {
        tree.rest = Cons.walkVariableArguments(tree.rest, fnslot);
        return (Stella.SGT_STELLA_UNKNOWN);
      }
      if ((tree.rest == Stella.NIL) ||
          fnslot.methodParameterTypeSpecifiers().emptyP()) {
        return (Stella.SGT_STELLA_UNKNOWN);
      }
      { Stella_Object otree = null;
        StandardObject otype = null;

        { Object [] caller_MV_returnarray = new Object[1];

          otree = Stella_Object.walkExpressionTree(tree.rest.value, targetts, fnslot.slotName, Stella.TRUE, caller_MV_returnarray);
          otype = ((StandardObject)(caller_MV_returnarray[0]));
        }
        tree.secondSetter(otree);
        if (Surrogate.subtypeOfIntegerP(Stella_Object.safePrimaryType(otree))) {
          { IntegerWrapper otree000 = ((IntegerWrapper)(otree));

            { Symbol testValue000 = fnslot.slotName;

              if (testValue000 == Stella.SYM_STELLA_GET_SYM) {
                GeneralizedSymbol.registerSymbol(Stella.getSymFromOffset(otree000.wrapperValue));
              }
              else if (testValue000 == Stella.SYM_STELLA_GET_SGT) {
                GeneralizedSymbol.registerSymbol(Stella.getSgtFromOffset(otree000.wrapperValue));
              }
              else if (testValue000 == Stella.SYM_STELLA_GET_KWD) {
                GeneralizedSymbol.registerSymbol(Stella.getKwdFromOffset(otree000.wrapperValue));
              }
              else {
              }
            }
          }
        }
        else {
        }
        return (otype);
      }
    }
  }

  public static Cons quoteArguments(MethodSlot method, Cons arguments) {
    { List ptypespecs = method.methodParameterTypeSpecifiers();
      int lastparameterindex = ptypespecs.length() - 1;
      StandardObject varargstype = (((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, Stella.FALSE_WRAPPER))).wrapperValue ? MethodSlot.variableArgumentsType(method) : ((StandardObject)(null)));
      StandardObject ptype = null;

      { int argindex = Stella.NULL_INTEGER;
        ConsIterator it = arguments.allocateIterator();
        int iter000 = 0;

        loop000 : while (it.nextP()) {
          {
            argindex = iter000;
            iter000 = iter000 + 1;
          }
          if (!(Stella_Object.surrogateP(it.value) ||
              Stella_Object.keywordP(it.value))) {
            if ((argindex >= lastparameterindex) &&
                (varargstype != null)) {
              ptype = varargstype;
            }
            else {
              ptype = ((StandardObject)(ptypespecs.nth(argindex)));
            }
            if ((it.value == Stella.SYM_STELLA_NULL) ||
                (((ptype == Stella.SGT_STELLA_BOOLEAN) &&
                ((it.value == Stella.SYM_STELLA_TRUE) ||
                 (it.value == Stella.SYM_STELLA_FALSE))) ||
                 (Stella_Object.wrapperP(it.value) &&
                  ((ptype != null) &&
                   StandardObject.subTypeSpecOfP(ptype, Stella.SGT_STELLA_LITERAL))))) {
              continue loop000;
            }
            it.valueSetter(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_COPY_CONS_TREE, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_QUOTE, Stella_Object.cons(it.value, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.NIL, Stella.NIL)))));
          }
        }
      }
      return (arguments);
    }
  }

  public Stella_Object finishWalkingCallSlotTree(Cons tree, StandardObject firstargtype, Object [] MV_returnarray) {
    { MethodSlot self = this;

      { Symbol methodname = self.slotName;
        StandardObject otypespec = self.computeReturnTypeSpec(firstargtype);
        Stella_Object otree = null;

        { List ptypespecs = self.methodParameterTypeSpecifiers();
          int nofparameters = ptypespecs.length();
          Cons cursor = tree.rest.rest;

          { int pindex = Stella.NULL_INTEGER;
            StandardObject targetts = null;
            Cons iter000 = ptypespecs.rest();
            int iter001 = 2;
            int upperBound000 = nofparameters;
            boolean unboundedP000 = upperBound000 == Stella.NULL_INTEGER;

            loop000 : while ((!(iter000 == Stella.NIL)) &&
                (unboundedP000 ||
                 (iter001 <= upperBound000))) {
              {
                targetts = ((StandardObject)(iter000.value));
                iter000 = iter000.rest;
              }
              {
                pindex = iter001;
                iter001 = iter001 + 1;
              }
              targetts = StandardObject.computeRelativeTypeSpec(targetts, firstargtype);
              if ((pindex == nofparameters) &&
                  ((BooleanWrapper)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, Stella.FALSE_WRAPPER))).wrapperValue) {
                tree.nthRestSetter(Cons.walkVariableArguments(cursor, self), pindex);
                break loop000;
              }
              cursor.value = Stella_Object.walkExpressionTree(cursor.value, targetts, methodname, Stella.TRUE, new Object[1]);
              cursor = cursor.rest;
            }
          }
        }
        { Stella_Object arg = null;
          Cons iter002 = tree.rest;

          while (!(iter002 == Stella.NIL)) {
            {
              arg = iter002.value;
              iter002 = iter002.rest;
            }
            if (Stella_Object.vrletExpressionP(arg)) {
              return (Cons.percolateOutVrletExpression(tree, ((Cons)(arg)), otypespec, MV_returnarray));
            }
          }
        }
        if (MethodSlot.inlineMethodCallP(self)) {
          otree = MethodSlot.walkInlineMethodCall(self, tree.rest);
          if (otree != null) {
            return (Stella_Object.sysTree(otree, otypespec, MV_returnarray));
          }
        }
        if (self.methodFunctionP) {
          otree = Stella_Object.cons(Stella.SYM_STELLA_SYS_CALL_FUNCTION, tree.concatenate(Stella.NIL, Stella.NIL));
        }
        else {
          otree = Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SYS_CALL_METHOD, Stella_Object.cons(self.slotOwner, Stella_Object.cons(tree.concatenate(Stella.NIL, Stella.NIL), Stella.NIL))));
        }
        { Stella_Object _return_temp = otree;

          MV_returnarray[0] = otypespec;
          return (_return_temp);
        }
      }
    }
  }

  public static StandardObject yieldListifiedVariableArgumentsType(MethodSlot method) {
    { Surrogate listbasetype = Stella.SGT_STELLA_CONS;
      StandardObject elementtype = MethodSlot.variableArgumentsType(method);

      if ((((Keyword)(Stella.$TRANSLATOROUTPUTLANGUAGE$.get())) == Stella.KWD_JAVA) &&
          (!MethodSlot.methodMustBeEvaluableP(method))) {
      }
      if (Stella_Object.typeP(elementtype)) {
        elementtype = ((Surrogate)(elementtype)).typeToWrappedType();
      }
      { ParametricTypeSpecifier self000 = ParametricTypeSpecifier.newParametricTypeSpecifier();

        self000.specifierBaseType = listbasetype;
        self000.specifierParameterTypes = Stella.list(Stella_Object.cons(elementtype, Stella.NIL));
        { ParametricTypeSpecifier value000 = self000;

          return (value000);
        }
      }
    }
  }

  public static Symbol variableArgumentsName(MethodSlot method) {
    return (((Symbol)(method.methodParameterNames().last())));
  }

  public static StandardObject variableArgumentsType(MethodSlot method) {
    return (StandardObject.extractParameterType(((StandardObject)(method.methodParameterTypeSpecifiers().last())), Stella.SYM_STELLA_ANY_VALUE, new Object[1]));
  }

  public static boolean passVariableArgumentsAsListP(MethodSlot method) {
    return (MethodSlot.methodMustBeEvaluableP(method) ||
        ((((Keyword)(Stella.$TRANSLATOROUTPUTLANGUAGE$.get())) == Stella.KWD_JAVA) &&
         ((((MethodSlot)(Stella.$METHODBEINGWALKED$.get())) == method) ||
          (!MethodSlot.stringConcatenateMethodP(method)))));
  }

  public static boolean stringConcatenateMethodP(MethodSlot method) {
    return ((method.slotName == Stella.SYM_STELLA_CONCATENATE) &&
        (method.slotOwner == Stella.SGT_STELLA_STRING));
  }

  public static int compatibleRealMethods(MethodSlot prototypemethod, Surrogate abstracttype, Object [] MV_returnarray) {
    { Symbol methodname = prototypemethod.slotName;
      int nofrealsubtypes = 0;
      int nofrealmethods = 0;
      boolean compatiblesignaturesP = Stella.TRUE;

      { Surrogate sub = null;
        Cons iter000 = ((Stella_Class)(abstracttype.surrogateValue)).classDirectSubs.theConsList;

        while (!(iter000 == Stella.NIL)) {
          {
            sub = ((Surrogate)(iter000.value));
            iter000 = iter000.rest;
          }
          if (((Stella_Class)(sub.surrogateValue)).abstractP) {
            { int nofsubs = Stella.NULL_INTEGER;
              int nofmethods = Stella.NULL_INTEGER;
              boolean compatibleP = Stella.FALSE;

              { Object [] caller_MV_returnarray = new Object[2];

                nofsubs = MethodSlot.compatibleRealMethods(prototypemethod, sub, caller_MV_returnarray);
                nofmethods = ((int)(((IntegerWrapper)(caller_MV_returnarray[0])).wrapperValue));
                compatibleP = ((boolean)(((BooleanWrapper)(caller_MV_returnarray[1])).wrapperValue));
              }
              nofrealsubtypes = nofrealsubtypes + nofsubs;
              nofrealmethods = nofrealmethods + nofmethods;
              if (!(compatibleP)) {
                compatiblesignaturesP = Stella.FALSE;
              }
            }
          }
          else {
            { Slot thismethod = null;

              nofrealsubtypes = nofrealsubtypes + 1;
              thismethod = Stella_Class.lookupSlot(((Stella_Class)(sub.surrogateValue)), methodname);
              if ((thismethod != null) &&
                  (!Stella_Object.storageSlotP(thismethod))) {
                nofrealmethods = nofrealmethods + 1;
                if (!(MethodSlot.identicalSignaturesP(prototypemethod, ((MethodSlot)(thismethod))))) {
                  compatiblesignaturesP = Stella.FALSE;
                }
              }
            }
          }
        }
      }
      { int _return_temp = nofrealsubtypes;

        MV_returnarray[0] = Stella.wrapInteger(nofrealmethods);
        MV_returnarray[1] = Stella.wrapBoolean(compatiblesignaturesP);
        return (_return_temp);
      }
    }
  }

  public static StandardObject computeMostGeneralReturnType(MethodSlot method, StandardObject returntype) {
    { StandardObject mostgeneralreturntype = returntype;
      MethodSlot mostgeneralmethod = method;

      while (mostgeneralmethod.slotDirectEquivalent != null) {
        mostgeneralmethod = ((MethodSlot)(mostgeneralmethod.slotDirectEquivalent));
        if (!(mostgeneralmethod.slotBaseType == Stella.SGT_STELLA_UNKNOWN)) {
          if (StandardObject.arrayTypeSpecifierP(mostgeneralreturntype)) {
            mostgeneralreturntype = mostgeneralmethod.computeReturnTypeSpec(mostgeneralmethod.slotOwner);
          }
          else {
            mostgeneralreturntype = mostgeneralmethod.slotBaseType;
          }
        }
      }
      return (mostgeneralreturntype);
    }
  }

  public static Cons wrapBodyWithLogFunctionCallTree(MethodSlot method, Cons body) {
    if (Stella_Object.consP(body.value) &&
        (!(((Cons)(body.value)).value == Stella.SYM_STELLA_INLINE))) {
      return (Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_LOG_FUNCTION_CALL, Stella_Object.cons(Stella.wrapString(Native.stringify(method)), Stella_Object.cons(Stella.NIL, Stella.NIL)))), body.concatenate(Stella.NIL, Stella.NIL)));
    }
    else {
      return (body);
    }
  }

  public static boolean logFunctionCallP(MethodSlot method) {
    if (Stella.$LOG_FUNCTION_CALLSp$ &&
        ((!((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_SLOT_AUXILIARYp, Stella.FALSE_WRAPPER))).wrapperValue) &&
         (!((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_GLOBALLY_INLINEp, Stella.FALSE_WRAPPER))).wrapperValue))) {
      { Symbol testValue000 = method.slotName;

        if ((testValue000 == Stella.SYM_STELLA_LOG_FUNCTION_CALL) ||
            ((testValue000 == Stella.SYM_STELLA_START_FUNCTION_CALL_LOGGING) ||
             ((testValue000 == Stella.SYM_STELLA_STOP_FUNCTION_CALL_LOGGING) ||
              ((testValue000 == Stella.SYM_STELLA_SET_CALL_LOG_BREAK_POINT) ||
               ((testValue000 == Stella.SYM_STELLA_BREAK_PROGRAM) ||
                ((testValue000 == Stella.SYM_STELLA_TERMINATE_PROGRAM) ||
                 ((testValue000 == Stella.SYM_STELLA_PO) ||
                  ((testValue000 == Stella.SYM_STELLA_DEFINEDp) ||
                   ((testValue000 == Stella.SYM_STELLA_NULLp) ||
                    ((testValue000 == Stella.SYM_STELLA_EQp) ||
                     ((testValue000 == Stella.SYM_STELLA_EQLp) ||
                      ((testValue000 == Stella.SYM_STELLA_l) ||
                       ((testValue000 == Stella.SYM_STELLA_le) ||
                        ((testValue000 == Stella.SYM_STELLA_g) ||
                         ((testValue000 == Stella.SYM_STELLA_ge) ||
                          (testValue000 == Stella.SYM_STELLA_CAST)))))))))))))))) {
          return (Stella.FALSE);
        }
        else {
          { boolean testValue001 = Stella.FALSE;

            if (method.methodParameterTypeSpecifiers().memberP(Stella.SGT_STELLA_UNKNOWN)) {
              testValue001 = Stella.TRUE;
            }
            else {
              if (method.methodParameterTypeSpecifiers().memberP(Stella.SGT_STELLA_LISP_CODE)) {
                testValue001 = Stella.TRUE;
              }
              else {
                if (method.methodReturnTypeSpecifiers().memberP(Stella.SGT_STELLA_UNKNOWN)) {
                  testValue001 = Stella.TRUE;
                }
                else {
                  if (method.methodReturnTypeSpecifiers().memberP(Stella.SGT_STELLA_LISP_CODE)) {
                    testValue001 = Stella.TRUE;
                  }
                  else {
                    {
                      { boolean foundP000 = Stella.FALSE;

                        { StandardObject tspec = null;
                          Cons iter000 = method.methodParameterTypeSpecifiers().theConsList;

                          loop000 : while (!(iter000 == Stella.NIL)) {
                            {
                              tspec = ((StandardObject)(iter000.value));
                              iter000 = iter000.rest;
                            }
                            if (StandardObject.subTypeSpecOfP(tspec, Stella.SGT_STELLA_OUTPUT_STREAM)) {
                              foundP000 = Stella.TRUE;
                              break loop000;
                            }
                          }
                        }
                        testValue001 = foundP000;
                      }
                      if (!testValue001) {
                        { boolean foundP001 = Stella.FALSE;

                          { StandardObject tspec = null;
                            Cons iter001 = method.methodParameterTypeSpecifiers().theConsList;

                            loop001 : while (!(iter001 == Stella.NIL)) {
                              {
                                tspec = ((StandardObject)(iter001.value));
                                iter001 = iter001.rest;
                              }
                              if (StandardObject.subTypeSpecOfP(tspec, Stella.SGT_STELLA_NATIVE_OUTPUT_STREAM)) {
                                foundP001 = Stella.TRUE;
                                break loop001;
                              }
                            }
                          }
                          testValue001 = foundP001;
                        }
                        if (!testValue001) {
                          testValue001 = (((String)(Stella.$CURRENTFILE$.get())) != null) &&
                              ((Native.stringSearch(((String)(Stella.$CURRENTFILE$.get())), "cl-primal", 0) != Stella.NULL_INTEGER) ||
                               (Native.stringSearch(((String)(Stella.$CURRENTFILE$.get())), "stella-to-cl", 0) != Stella.NULL_INTEGER));
                        }
                      }
                    }
                  }
                }
              }
            }
            if (testValue001) {
              return (Stella.FALSE);
            }
          }
        }
      }
      return (Stella.TRUE);
    }
    return (Stella.FALSE);
  }

  public static boolean stringifyMethodBodyP(MethodSlot method) {
    return (((BooleanWrapper)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_GLOBALLY_INLINEp, Stella.FALSE_WRAPPER))).wrapperValue ||
        ((!method.methodFunctionP) &&
         ((((Stella_Class)(method.slotOwner.surrogateValue)) == null) ||
          ((Stella_Class)(method.slotOwner.surrogateValue)).mixinP)));
  }

  public static void finalizeAuxiliaryMethod(MethodSlot method) {
    if ((method.slotBaseType == null) &&
        (((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null))) != null)) {
      method.slotBaseType = StandardObject.validateTypeSpecifier(((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null))), ((Stella_Class)(method.slotOwner.surrogateValue)), Stella.FALSE);
    }
  }

  public static boolean cppConstructorP(MethodSlot method) {
    return ((method.type() == Stella.SGT_STELLA_VOID) &&
        ((method.methodParameterNames().length() == 1) &&
         (Stella.stringEqlP(method.slotOwner.symbolName, method.slotName.symbolName) &&
          (((Module)(method.slotOwner.homeContext)) == ((Module)(method.slotName.homeContext))))));
  }

  public static boolean methodContainsAnchoredTypeP(MethodSlot method) {
    if (((Stella_Class)(method.slotOwner.surrogateValue)).abstractP) {
      if ((((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null))) != null) &&
          Stella_Object.isaP(((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null))), Stella.SGT_STELLA_ANCHORED_TYPE_SPECIFIER)) {
        return (Stella.TRUE);
      }
      { StandardObject ptype = null;
        Cons iter000 = method.methodParameterTypeSpecifiers().theConsList;

        while (!(iter000 == Stella.NIL)) {
          {
            ptype = ((StandardObject)(iter000.value));
            iter000 = iter000.rest;
          }
          if (Stella_Object.isaP(ptype, Stella.SGT_STELLA_ANCHORED_TYPE_SPECIFIER)) {
            return (Stella.TRUE);
          }
        }
      }
    }
    return (Stella.FALSE);
  }

  public static boolean methodContainsUnknownTypeP(MethodSlot method) {
    { boolean foundP000 = Stella.FALSE;

      { StandardObject rtype = null;
        Cons iter000 = method.methodReturnTypeSpecifiers().theConsList;

        loop000 : while (!(iter000 == Stella.NIL)) {
          {
            rtype = ((StandardObject)(iter000.value));
            iter000 = iter000.rest;
          }
          if (Surrogate.unknownTypeP(StandardObject.typeSpecToBaseType(StandardObject.computeRelativeTypeSpec(rtype, method.slotOwner)))) {
            foundP000 = Stella.TRUE;
            break loop000;
          }
        }
      }
      if (foundP000) {
        return (Stella.TRUE);
      }
    }
    { StandardObject ptype = null;
      Cons iter001 = method.methodParameterTypeSpecifiers().theConsList;

      while (!(iter001 == Stella.NIL)) {
        {
          ptype = ((StandardObject)(iter001.value));
          iter001 = iter001.rest;
        }
        if (Surrogate.unknownTypeP(StandardObject.typeSpecToBaseType(StandardObject.computeRelativeTypeSpec(ptype, method.slotOwner)))) {
          return (Stella.TRUE);
        }
      }
    }
    return (Stella.FALSE);
  }

  public static boolean nativeMethodP(MethodSlot slot) {
    return ((!slot.abstractP) &&
        (!MethodSlot.methodContainsUnknownTypeP(slot)));
  }

  public static boolean undefineConflictingDefinitionsP(MethodSlot newslot) {
    if (newslot.methodFunctionP) {
      if (MethodSlot.warnAboutFunctionShadowingSlotsP(newslot)) {
        if (!(Stella.yOrNP("Do you want to remove the conflicting method definitions? "))) {
          return (Stella.FALSE);
        }
        Symbol.undefineExternalSlots(newslot.slotName);
        Slot.unregisterSlotName(newslot);
      }
      if (Symbol.lookupMacro(newslot.slotName) != null) {
        if (!((BooleanWrapper)(KeyValueList.dynamicSlotValue(newslot.dynamicSlots, Stella.SYM_STELLA_METHOD_MACROp, Stella.FALSE_WRAPPER))).wrapperValue) {
          { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

            try {
              Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
              Stella.signalTranslationWarning();
              if (!(Stella.suppressWarningsP())) {
                Stella.printErrorContext(">> WARNING: ", Stella.STANDARD_WARNING);
                {
                  Stella.STANDARD_WARNING.nativeStream.println();
                  Stella.STANDARD_WARNING.nativeStream.println(" Function `" + Stella_Object.deUglifyParseTree(newslot) + "' redefines an exisiting macro of the same name.");
                }
;
              }

            } finally {
              Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
            }
          }
        }
        else {
          if (!(newslot.functionCode != null)) {
            newslot.functionCode = Symbol.lookupMacro(newslot.slotName).functionCode;
          }
        }
      }
      else if (Symbol.lookupFunction(newslot.slotName) != null) {
        if (((BooleanWrapper)(KeyValueList.dynamicSlotValue(newslot.dynamicSlots, Stella.SYM_STELLA_METHOD_MACROp, Stella.FALSE_WRAPPER))).wrapperValue) {
          { Object old$PrintreadablyP$001 = Stella.$PRINTREADABLYp$.get();

            try {
              Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
              Stella.signalTranslationWarning();
              if (!(Stella.suppressWarningsP())) {
                Stella.printErrorContext(">> WARNING: ", Stella.STANDARD_WARNING);
                {
                  Stella.STANDARD_WARNING.nativeStream.println();
                  Stella.STANDARD_WARNING.nativeStream.println(" Macro `" + Stella_Object.deUglifyParseTree(newslot) + "' redefines an exisiting function of the same name.");
                }
;
              }

            } finally {
              Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$001);
            }
          }
        }
      }
    }
    else {
      if (Slot.warnAboutSlotShadowedByAFunctionP(newslot)) {
        System.out.println(" Removing the preexisting function definition.");
        Symbol.undefineFunction(newslot.slotName);
      }
    }
    return (Stella.TRUE);
  }

  public static void destroyFunction(MethodSlot function) {
    { Symbol functionname = function.slotName;
      Surrogate slotref = function.slotSlotref;
      MethodSlot realfunction = Symbol.lookupFunction(functionname);

      if (function == realfunction) {
        Stella.$FUNCTION_LOOKUP_TABLE$.removeAt(functionname);
      }
      if ((slotref != null) &&
          (function == ((Slot)(slotref.surrogateValue)))) {
        slotref.surrogateValue = null;
      }
      function.deletedPSetter(Stella.TRUE);
      function.free();
    }
  }

  public static MethodSlot attachFunction(MethodSlot newfunction) {
    { Symbol name = newfunction.slotName;
      MethodSlot oldfunction = Symbol.lookupFunction(name);

      if (!MethodSlot.undefineConflictingDefinitionsP(newfunction)) {
        return (null);
      }
      Stella.$FUNCTION_LOOKUP_TABLE$.insertAt(name, newfunction);
      Slot.unregisterSlotName(newfunction);
      newfunction.slotExternalP = Stella.TRUE;
      newfunction.finalizeSlotTypeComputations();
      if (oldfunction != null) {
        HookList.runHooks(Stella.$REDEFINE_RELATION_HOOKS$, Stella.list(Stella_Object.cons(oldfunction, Stella_Object.cons(newfunction, Stella.NIL))));
        oldfunction.free();
      }
      return (newfunction);
    }
  }

  public StandardObject computeReturnTypeSpec(StandardObject firstargtype) {
    { MethodSlot self = this;

      if (((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null))) == null) {
        return (self.slotBaseType);
      }
      else {
        return (StandardObject.computeRelativeTypeSpec(((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null))), firstargtype));
      }
    }
  }

  public int arity() {
    { MethodSlot self = this;

      if (((BooleanWrapper)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, Stella.FALSE_WRAPPER))).wrapperValue) {
        return (Stella.NULL_INTEGER);
      }
      { int returntypecount = self.methodReturnTypeSpecifiers().length();
        int result = self.methodParameterTypeSpecifiers().length() + returntypecount;

        switch (returntypecount) {
          case 1: 
            if (((StandardObject)(self.methodReturnTypeSpecifiers().first())) == Stella.SGT_STELLA_BOOLEAN) {
              return (result - 1);
            }
            else {
              return (result);
            }
          case 0: 
            return (result);
          default:
            if (((StandardObject)(self.methodReturnTypeSpecifiers().last())) == Stella.SGT_STELLA_BOOLEAN) {
              return (result - 1);
            }
            else {
              return (result);
            }
        }
      }
    }
  }

  public int methodArgumentCount() {
    { MethodSlot self = this;

      return (self.methodParameterNames().length());
    }
  }

  public static void destroyMethod(MethodSlot self) {
    Slot.destroyExternalSlot(self);
  }

  public void unfinalizeLocalSlot() {
    { MethodSlot self = this;

    }
  }

  public void helpFinalizeLocalSlot() {
    { MethodSlot self = this;

    }
  }

  public void finalizeSlotTypeComputations() {
    { MethodSlot self = this;

      { Stella_Class ownerclass = ((self.slotOwner != null) ? ((Stella_Class)(self.slotOwner.surrogateValue)) : ((Stella_Class)(null)));

        { StandardObject ts = null;
          Cons iter000 = self.methodParameterTypeSpecifiers().theConsList;

          while (!(iter000 == Stella.NIL)) {
            {
              ts = ((StandardObject)(iter000.value));
              iter000 = iter000.rest;
            }
            StandardObject.validateTypeSpecifier(ts, ownerclass, Stella.FALSE);
          }
        }
        if (((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null))) != null) {
          self.slotBaseType = StandardObject.validateTypeSpecifier(((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null))), ownerclass, Stella.FALSE);
        }
        { StandardObject ts = null;
          Cons iter001 = self.methodReturnTypeSpecifiers().rest();

          while (!(iter001 == Stella.NIL)) {
            {
              ts = ((StandardObject)(iter001.value));
              iter001 = iter001.rest;
            }
            StandardObject.validateTypeSpecifier(ts, ownerclass, Stella.FALSE);
          }
        }
      }
    }
  }

  public static Cons synthesizeMethodBody(MethodSlot method) {
    if (((Stella_Class)(Stella.SGT_STELLA_BOOLEAN.surrogateValue)) == null) {
      return (Stella.NIL);
    }
    { Symbol storageslotname = ((Symbol)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_STORAGE_SLOT, null)));
      Symbol inheritanceslotname = ((Symbol)(KeyValueList.dynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_INHERITS_THROUGH, null)));
      StorageSlot storageslot = null;
      Slot inheritanceslot = null;
      Stella_Object defaultvalue = null;

      if (inheritanceslotname == Stella.SYM_STELLA_SUPER_CLASSES) {
        inheritanceslotname = Stella.SYM_STELLA_CLASS_ALL_SUPER_CLASSES;
      }
      else if (inheritanceslotname == Stella.SYM_STELLA_EQUIVALENT_SLOT) {
        inheritanceslotname = Stella.SYM_STELLA_SLOT_DIRECT_EQUIVALENT;
      }
      else {
      }
      storageslot = ((StorageSlot)(Stella_Class.lookupSlot(((Stella_Class)(method.slotOwner.surrogateValue)), storageslotname)));
      if (storageslot == null) {
        Stella.STANDARD_WARNING.nativeStream.println("Warning: :storage-slot references non-existent slot `" + storageslotname + "' on the class `" + method.slotOwner + "'");
        return (Stella.NIL);
      }
      inheritanceslot = Stella_Class.lookupSlot(((Stella_Class)(method.slotOwner.surrogateValue)), inheritanceslotname);
      if (inheritanceslot == null) {
        Stella.STANDARD_WARNING.nativeStream.println("Warning: :inherits-through references non-existent slot `" + inheritanceslotname + "' on the class `" + method.slotOwner + "'");
        return (Stella.NIL);
      }
      defaultvalue = storageslot.systemDefaultValue();
      return (Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_LET, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_CURSOR, Stella_Object.cons(Stella.SYM_STELLA_SELF, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_VALUE, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SLOT_VALUE, Stella_Object.cons(Stella.SYM_STELLA_CURSOR, Stella_Object.cons(storageslotname, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_LOOP, Stella_Object.cons(Stella_Object.cons(Stella.SYM_STELLA_WHEN, ((Surrogate.subtypeOfP(storageslot.type(), Stella.SGT_STELLA_BOOLEAN) ? Stella_Object.cons(Stella.SYM_STELLA_VALUE, Stella.NIL) : Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_DEFINEDp, Stella_Object.cons(Stella.SYM_STELLA_VALUE, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.NIL))).concatenate(Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_RETURN, Stella_Object.cons(Stella.SYM_STELLA_VALUE, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella.NIL), Stella.NIL)), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SETQ, Stella_Object.cons(Stella.SYM_STELLA_CURSOR, Stella_Object.cons(((Surrogate.subtypeOfP(inheritanceslot.type(), Stella.SGT_STELLA_COLLECTION) ||
          Surrogate.subtypeOfP(inheritanceslot.type(), Stella.SGT_STELLA_CONS)) ? Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_FIRST, Stella_Object.cons(Stella_Object.cons(inheritanceslotname, Stella_Object.cons(Stella.SYM_STELLA_CURSOR, Stella.NIL)), Stella_Object.cons(Stella.NIL, Stella.NIL)))) : Stella_Object.cons(inheritanceslotname, Stella_Object.cons(Stella.SYM_STELLA_CURSOR, Stella.NIL))), Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_IF, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_DEFINEDp, Stella_Object.cons(Stella.SYM_STELLA_CURSOR, Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SETQ, Stella_Object.cons(Stella.SYM_STELLA_VALUE, Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_SLOT_VALUE, Stella_Object.cons(Stella.SYM_STELLA_CURSOR, Stella_Object.cons(storageslotname, Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella_Object.cons(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_RETURN, Stella_Object.cons(((defaultvalue != null) ? defaultvalue : Stella.SYM_STELLA_NULL), Stella_Object.cons(Stella.NIL, Stella.NIL)))), Stella_Object.cons(Stella.NIL, Stella.NIL)))))), Stella_Object.cons(Stella.NIL, Stella.NIL)))))), Stella_Object.cons(Stella.NIL, Stella.NIL))))), Stella.NIL));
    }
  }

  public static Cons yieldDefineStellaMethodObject(MethodSlot method, MethodSlot codemethod, MethodSlot wrappermethod) {
    { String name = Native.stringify(method.slotName);

      if (method.methodFunctionP) {
        return (Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_DEFINE_FUNCTION_OBJECT, Stella_Object.cons((Stella.stringEqlP(name, method.slotName.symbolName) ? Stella.wrapString(name) : Stella.wrapString(" " + name)), Stella_Object.cons(Stella_Object.cons(Stella.yieldStringConstantTree(method.methodStringifiedSource), Stella_Object.cons(((codemethod != null) ? ((StandardObject)(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_THE_CODE, Stella_Object.cons(Stella.KWD_FUNCTION, Stella_Object.cons(codemethod.slotName, Stella_Object.cons(Stella.NIL, Stella.NIL))))))) : ((StandardObject)(Stella.SYM_STELLA_NULL))), Stella_Object.cons(((wrappermethod != null) ? ((StandardObject)(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_THE_CODE, Stella_Object.cons(Stella.KWD_FUNCTION, Stella_Object.cons(wrappermethod.slotName, Stella_Object.cons(Stella_Object.cons(wrappermethod, Stella.NIL), Stella.NIL))))))) : ((StandardObject)(Stella.SYM_STELLA_NULL))), Stella.NIL))), Stella.NIL)))));
      }
      else {
        return (Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_DEFINE_METHOD_OBJECT, Stella_Object.cons(Stella.yieldStringConstantTree(method.methodStringifiedSource), Stella_Object.cons(Stella_Object.cons(((codemethod != null) ? ((StandardObject)(Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_THE_CODE, Stella_Object.cons(Stella.KWD_METHOD, Stella_Object.cons(codemethod.slotOwner, Stella_Object.cons(Stella_Object.cons(codemethod.slotName, Stella.NIL), Stella.NIL))))))) : ((StandardObject)(Stella.SYM_STELLA_NULL))), Stella_Object.cons(Stella.SYM_STELLA_NULL, Stella.NIL)), Stella.NIL)))));
      }
    }
  }

  public static MethodSlot attachMethodSlotToOwner(MethodSlot newmethod) {
    if (newmethod.methodFunctionP) {
      return (MethodSlot.attachFunction(newmethod));
    }
    if (newmethod.slotOwner.surrogateValue == null) {
      return (newmethod);
    }
    if (!MethodSlot.undefineConflictingDefinitionsP(newmethod)) {
      return (null);
    }
    return (((MethodSlot)(Slot.attachSlotToOwner(newmethod))));
  }

  public static void incorporateFirstInputParameter(MethodSlot method) {
    { List parametertypespecs = method.methodParameterTypeSpecifiers();
      StandardObject firstargtype = ((StandardObject)(parametertypespecs.first()));

      if (!method.methodFunctionP) {
        if (parametertypespecs.emptyP()) {
          { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

            try {
              Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
              Stella.signalTranslationError();
              if (!(Stella.suppressWarningsP())) {
                Stella.printErrorContext(">> ERROR: ", Stella.STANDARD_ERROR);
                {
                  Stella.STANDARD_ERROR.nativeStream.println();
                  Stella.STANDARD_ERROR.nativeStream.println(" Method has no input parameters, converting it into a function.");
                }
;
              }

            } finally {
              Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
            }
          }
          method.methodFunctionP = Stella.TRUE;
          return;
        }
        else if ((firstargtype != null) &&
            (!Stella_Object.typeP(firstargtype))) {
          { Object old$PrintreadablyP$001 = Stella.$PRINTREADABLYp$.get();

            try {
              Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
              Stella.signalTranslationError();
              if (!(Stella.suppressWarningsP())) {
                Stella.printErrorContext(">> ERROR: ", Stella.STANDARD_ERROR);
                {
                  Stella.STANDARD_ERROR.nativeStream.println();
                  Stella.STANDARD_ERROR.nativeStream.println(" Illegal complex argument type for the first method parameter: ");
                  Stella.STANDARD_ERROR.nativeStream.println("   `" + Stella_Object.deUglifyParseTree(firstargtype) + "'.");
                }
;
              }

            } finally {
              Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$001);
            }
          }
          if (Stella_Object.anchoredTypeSpecifierP(firstargtype)) {
            method.methodParameterTypeSpecifiers().firstSetter(Stella.SGT_STELLA_UNKNOWN);
            firstargtype = Stella.SGT_STELLA_UNKNOWN;
          }
        }
      }
      method.slotOwner = ((firstargtype != null) ? StandardObject.typeSpecToBaseType(firstargtype) : null);
    }
  }

  public static void incorporateInputParameters(MethodSlot method, Cons parameters) {
    if (parameters == Stella.NIL) {
      return;
    }
    { Symbol name = null;
      StandardObject ts = null;
      Symbol direction = null;
      boolean variableargsP = Stella.FALSE;

      method.methodParameterNames = List.newList();
      method.methodParameterTypeSpecifiers = List.newList();
      { Stella_Object p = null;
        Cons iter000 = parameters;

        loop000 : while (!(iter000 == Stella.NIL)) {
          {
            p = iter000.value;
            iter000 = iter000.rest;
          }
          { Surrogate testValue000 = Stella_Object.safePrimaryType(p);

            if (testValue000 == Stella.SGT_STELLA_CONS) {
              { Cons p000 = ((Cons)(p));

                switch (p000.length()) {
                  case 2: 
                    direction = Stella.SYM_STELLA_IN;
                  break;
                  case 3: 
                    if ((p000.value == Stella.SYM_STELLA_IN) ||
                        ((p000.value == Stella.SYM_STELLA_OUT) ||
                         (p000.value == Stella.SYM_STELLA_INOUT))) {
                      direction = ((Symbol)(p000.value));
                      if (List.nullListP(method.methodParameterDirections())) {
                        KeyValueList.setDynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_PARAMETER_DIRECTIONS, List.newList(), null);
                        { Stella_Object par = null;
                          Cons iter001 = parameters;

                          loop001 : while (!(iter001 == Stella.NIL)) {
                            {
                              par = iter001.value;
                              iter001 = iter001.rest;
                            }
                            if (par == p000) {
                              break loop001;
                            }
                            else {
                              method.methodParameterDirections().insert(Stella.SYM_STELLA_IN);
                            }
                          }
                        }
                      }
                    }
                    else {
                      { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

                        try {
                          Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
                          Stella.signalTranslationError();
                          if (!(Stella.suppressWarningsP())) {
                            Stella.printErrorContext(">> ERROR: ", Stella.STANDARD_ERROR);
                            {
                              Stella.STANDARD_ERROR.nativeStream.println();
                              Stella.STANDARD_ERROR.nativeStream.println(" Illegal direction for method parameter: `" + Stella_Object.deUglifyParseTree(p000) + "'.");
                            }
;
                          }

                        } finally {
                          Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
                        }
                      }
                      direction = Stella.SYM_STELLA_IN;
                    }
                    p000 = p000.rest;
                  break;
                  default:
                    { Object old$PrintreadablyP$001 = Stella.$PRINTREADABLYp$.get();

                      try {
                        Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
                        Stella.signalTranslationError();
                        if (!(Stella.suppressWarningsP())) {
                          Stella.printErrorContext(">> ERROR: ", Stella.STANDARD_ERROR);
                          {
                            Stella.STANDARD_ERROR.nativeStream.println();
                            Stella.STANDARD_ERROR.nativeStream.println(" Illegal method parameter: `" + Stella_Object.deUglifyParseTree(p000) + "'.");
                          }
;
                        }

                      } finally {
                        Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$001);
                      }
                    }
                    continue loop000;
                }
                if (variableargsP) {
                  { Cons varargtype = Stella.list$(Stella_Object.cons(Stella.SYM_STELLA_ARGUMENT_LIST, Stella_Object.cons(Stella.SYM_STELLA_OF, Stella_Object.cons(p000.rest.value, Stella_Object.cons(Stella.NIL, Stella.NIL)))));

                    name = ((Symbol)(p000.value));
                    ts = varargtype.yieldTypeSpecifier();
                  }
                }
                else {
                  {
                    if (!(Stella_Object.symbolP(p000.value) &&
                        (Stella_Object.symbolP(p000.rest.value) ||
                         (Stella_Object.surrogateP(p000.rest.value) ||
                          Stella_Object.consP(p000.rest.value))))) {
                      { Object old$PrintreadablyP$002 = Stella.$PRINTREADABLYp$.get();

                        try {
                          Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
                          Stella.signalTranslationError();
                          if (!(Stella.suppressWarningsP())) {
                            Stella.printErrorContext(">> ERROR: ", Stella.STANDARD_ERROR);
                            {
                              Stella.STANDARD_ERROR.nativeStream.println();
                              Stella.STANDARD_ERROR.nativeStream.println(" Illegal method parameter: `" + Stella_Object.deUglifyParseTree(p000) + "'.");
                            }
;
                          }

                        } finally {
                          Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$002);
                        }
                      }
                      continue loop000;
                    }
                    name = ((Symbol)(p000.value));
                    ts = p000.rest.value.yieldTypeSpecifier();
                  }
                }
              }
            }
            else if (Surrogate.subtypeOfSymbolP(testValue000)) {
              { Symbol p000 = ((Symbol)(p));

                if (p000 == Stella.SYM_STELLA_aREST) {
                  KeyValueList.setDynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_VARIABLE_ARGUMENTSp, (Stella.TRUE ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER), Stella.FALSE_WRAPPER);
                  variableargsP = Stella.TRUE;
                  continue loop000;
                }
                else if (p000 == Stella.SYM_STELLA_aBODY) {
                  KeyValueList.setDynamicSlotValue(method.dynamicSlots, Stella.SYM_STELLA_METHOD_BODY_ARGUMENTp, (Stella.TRUE ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER), Stella.FALSE_WRAPPER);
                  continue loop000;
                }
                else {
                  { Object old$PrintreadablyP$003 = Stella.$PRINTREADABLYp$.get();

                    try {
                      Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
                      Stella.signalTranslationError();
                      if (!(Stella.suppressWarningsP())) {
                        Stella.printErrorContext(">> ERROR: ", Stella.STANDARD_ERROR);
                        {
                          Stella.STANDARD_ERROR.nativeStream.println();
                          Stella.STANDARD_ERROR.nativeStream.println(" Untyped parameter in parameter list: `" + Stella_Object.deUglifyParseTree(parameters) + "'.");
                        }
;
                      }

                    } finally {
                      Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$003);
                    }
                  }
                  name = p000;
                  ts = Stella.SGT_STELLA_UNKNOWN;
                }
              }
            }
            else {
              { Object old$PrintreadablyP$004 = Stella.$PRINTREADABLYp$.get();

                try {
                  Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
                  Stella.signalTranslationError();
                  if (!(Stella.suppressWarningsP())) {
                    Stella.printErrorContext(">> ERROR: ", Stella.STANDARD_ERROR);
                    {
                      Stella.STANDARD_ERROR.nativeStream.println();
                      Stella.STANDARD_ERROR.nativeStream.println(" Illegal parameter list: `" + Stella_Object.deUglifyParseTree(parameters) + "'.");
                    }
;
                  }

                } finally {
                  Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$004);
                }
              }
              continue loop000;
            }
          }
          method.methodParameterTypeSpecifiers().insert(ts);
          method.methodParameterNames().insert(((Symbol)(name.permanentify())));
          if (List.definedListP(method.methodParameterDirections())) {
            method.methodParameterDirections().insert(direction);
          }
        }
      }
      method.methodParameterNames().reverse();
      method.methodParameterTypeSpecifiers().reverse();
      method.methodParameterDirections().reverse();
    }
  }

  public static boolean identicalSignaturesP(MethodSlot method1, MethodSlot method2) {
    { boolean testValue000 = Stella.FALSE;

      { boolean alwaysP000 = Stella.TRUE;

        { StandardObject ts2 = null;
          StandardObject ts1 = null;
          Cons iter000 = method1.methodParameterTypeSpecifiers().rest();
          Cons iter001 = method2.methodParameterTypeSpecifiers().rest();

          loop000 : while ((!(iter000 == Stella.NIL)) &&
              (!(iter001 == Stella.NIL))) {
            {
              ts1 = ((StandardObject)(iter000.value));
              iter000 = iter000.rest;
            }
            {
              ts2 = ((StandardObject)(iter001.value));
              iter001 = iter001.rest;
            }
            if (!(StandardObject.subTypeSpecOfP(ts1 = StandardObject.computeRelativeTypeSpec(ts1, method1.slotOwner), ts2 = StandardObject.computeRelativeTypeSpec(ts2, method2.slotOwner)) &&
                StandardObject.subTypeSpecOfP(ts2, ts1))) {
              alwaysP000 = Stella.FALSE;
              break loop000;
            }
          }
        }
        testValue000 = alwaysP000;
      }
      if (testValue000) {
        { boolean alwaysP001 = Stella.TRUE;

          { StandardObject ts2 = null;
            StandardObject ts1 = null;
            Cons iter002 = method1.methodReturnTypeSpecifiers().theConsList;
            Cons iter003 = method2.methodReturnTypeSpecifiers().theConsList;

            loop001 : while ((!(iter002 == Stella.NIL)) &&
                (!(iter003 == Stella.NIL))) {
              {
                ts1 = ((StandardObject)(iter002.value));
                iter002 = iter002.rest;
              }
              {
                ts2 = ((StandardObject)(iter003.value));
                iter003 = iter003.rest;
              }
              if (!(StandardObject.subTypeSpecOfP(ts1 = StandardObject.computeRelativeTypeSpec(ts1, method1.slotOwner), ts2 = StandardObject.computeRelativeTypeSpec(ts2, method2.slotOwner)) &&
                  StandardObject.subTypeSpecOfP(ts2, ts1))) {
                alwaysP001 = Stella.FALSE;
                break loop001;
              }
            }
          }
          testValue000 = alwaysP001;
        }
      }
      { boolean value000 = testValue000;

        return (value000);
      }
    }
  }

  public boolean conformingSignaturesP(Slot superslot) {
    { MethodSlot self = this;

      if (StandardObject.conformingTypeSpecP(self.slotBaseType, superslot.type()) &&
          (StandardObject.conformingTypeSpecP(((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null))), ((CompoundTypeSpecifier)(KeyValueList.dynamicSlotValue(superslot.dynamicSlots, Stella.SYM_STELLA_SLOT_TYPE_SPECIFIER, null)))) &&
           (self.methodArgumentCount() == superslot.methodArgumentCount()))) {
        { Surrogate testValue000 = Stella_Object.safePrimaryType(superslot);

          if (Surrogate.subtypeOfStorageSlotP(testValue000)) {
            { StorageSlot superslot000 = ((StorageSlot)(superslot));

              return (self.methodReturnTypeSpecifiers().length() == 1);
            }
          }
          else if (Surrogate.subtypeOfMethodSlotP(testValue000)) {
            { MethodSlot superslot000 = ((MethodSlot)(superslot));

              { boolean testValue001 = Stella.FALSE;

                { boolean alwaysP000 = Stella.TRUE;

                  { StandardObject ts2 = null;
                    StandardObject ts1 = null;
                    Cons iter000 = self.methodParameterTypeSpecifiers().rest();
                    Cons iter001 = superslot000.methodParameterTypeSpecifiers().rest();

                    loop000 : while ((!(iter000 == Stella.NIL)) &&
                        (!(iter001 == Stella.NIL))) {
                      {
                        ts1 = ((StandardObject)(iter000.value));
                        iter000 = iter000.rest;
                      }
                      {
                        ts2 = ((StandardObject)(iter001.value));
                        iter001 = iter001.rest;
                      }
                      if (!StandardObject.conformingTypeSpecP(ts2, ts1)) {
                        alwaysP000 = Stella.FALSE;
                        break loop000;
                      }
                    }
                  }
                  testValue001 = alwaysP000;
                }
                if (testValue001) {
                  { boolean alwaysP001 = Stella.TRUE;

                    { StandardObject ts2 = null;
                      StandardObject ts1 = null;
                      Cons iter002 = self.methodReturnTypeSpecifiers().theConsList;
                      Cons iter003 = superslot000.methodReturnTypeSpecifiers().theConsList;

                      loop001 : while ((!(iter002 == Stella.NIL)) &&
                          (!(iter003 == Stella.NIL))) {
                        {
                          ts1 = ((StandardObject)(iter002.value));
                          iter002 = iter002.rest;
                        }
                        {
                          ts2 = ((StandardObject)(iter003.value));
                          iter003 = iter003.rest;
                        }
                        if (!StandardObject.conformingTypeSpecP(ts1, ts2)) {
                          alwaysP001 = Stella.FALSE;
                          break loop001;
                        }
                      }
                    }
                    testValue001 = alwaysP001;
                  }
                }
                { boolean value000 = testValue001;

                  return (value000);
                }
              }
            }
          }
          else {
          }
        }
      }
      return (Stella.FALSE);
    }
  }

  public static boolean warnAboutFunctionShadowingSlotsP(MethodSlot function) {
    { Symbol name = function.slotName;

      if (name.symbolSlotOffset != Stella.NULL_INTEGER) {
        { Cons slots = Stella.NIL;

          { Module module = null;
            Iterator iter000 = Stella.allModules();

            while (iter000.nextP()) {
              module = ((Module)(iter000.value));
              { Slot slot = null;
                Iterator iter001 = Module.allSlots(module, Stella.TRUE);
                Cons collect000 = null;

                while (iter001.nextP()) {
                  slot = ((Slot)(iter001.value));
                  if (slot.slotName == name) {
                    if (collect000 == null) {
                      {
                        collect000 = Stella_Object.cons(slot, Stella.NIL);
                        if (slots == Stella.NIL) {
                          slots = collect000;
                        }
                        else {
                          Cons.addConsToEndOfConsList(slots, collect000);
                        }
                      }
                    }
                    else {
                      {
                        collect000.rest = Stella_Object.cons(slot, Stella.NIL);
                        collect000 = collect000.rest;
                      }
                    }
                  }
                }
              }
            }
          }
          if (((BooleanWrapper)(KeyValueList.dynamicSlotValue(function.dynamicSlots, Stella.SYM_STELLA_METHOD_MACROp, Stella.FALSE_WRAPPER))).wrapperValue) {
            { Object old$PrintreadablyP$000 = Stella.$PRINTREADABLYp$.get();

              try {
                Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
                Stella.signalTranslationWarning();
                if (!(Stella.suppressWarningsP())) {
                  Stella.printErrorContext(">> WARNING: ", Stella.STANDARD_WARNING);
                  {
                    Stella.STANDARD_WARNING.nativeStream.println();
                    Stella.STANDARD_WARNING.nativeStream.println(" Macro `" + Stella_Object.deUglifyParseTree(name) + "' shadows the following methods/slots:");
                    Stella.STANDARD_WARNING.nativeStream.println("    `" + Stella_Object.deUglifyParseTree(slots) + "'.");
                  }
;
                }

              } finally {
                Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$000);
              }
            }
          }
          else {
            { Object old$PrintreadablyP$001 = Stella.$PRINTREADABLYp$.get();

              try {
                Native.setBooleanSpecial(Stella.$PRINTREADABLYp$, Stella.TRUE);
                Stella.signalTranslationWarning();
                if (!(Stella.suppressWarningsP())) {
                  Stella.printErrorContext(">> WARNING: ", Stella.STANDARD_WARNING);
                  {
                    Stella.STANDARD_WARNING.nativeStream.println();
                    Stella.STANDARD_WARNING.nativeStream.println(" Function `" + Stella_Object.deUglifyParseTree(name) + "' shadows the following methods/slots:");
                    Stella.STANDARD_WARNING.nativeStream.println("    `" + Stella_Object.deUglifyParseTree(slots) + "'.");
                  }
;
                }

              } finally {
                Stella.$PRINTREADABLYp$.set(old$PrintreadablyP$001);
              }
            }
          }
          return (Stella.TRUE);
        }
      }
      return (Stella.FALSE);
    }
  }

  public void printObject(java.io.PrintStream stream) {
    { MethodSlot self = this;

      if (self.methodFunctionP) {
        stream.print("|F|" + self.slotName.symbolName);
      }
      else {
        stream.print("|M|" + self.slotOwner.symbolName + "." + self.slotName.symbolName);
      }
    }
  }

  public static Stella_Object accessMethodSlotSlotValue(MethodSlot self, Symbol slotname, Stella_Object value, boolean setvalueP) {
    if (slotname == Stella.SYM_STELLA_METHOD_SETTERp) {
      if (setvalueP) {
        self.methodSetterP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.methodSetterP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
      }
    }
    else if (slotname == Stella.SYM_STELLA_METHOD_PARAMETER_NAMES) {
      if (setvalueP) {
        self.methodParameterNames = ((List)(value));
      }
      else {
        value = self.methodParameterNames();
      }
    }
    else if (slotname == Stella.SYM_STELLA_METHOD_PARAMETER_TYPE_SPECIFIERS) {
      if (setvalueP) {
        self.methodParameterTypeSpecifiers = ((List)(value));
      }
      else {
        value = self.methodParameterTypeSpecifiers();
      }
    }
    else if (slotname == Stella.SYM_STELLA_METHOD_PARAMETER_DIRECTIONS) {
      if (setvalueP) {
        KeyValueList.setDynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_METHOD_PARAMETER_DIRECTIONS, ((List)(value)), null);
      }
      else {
        value = self.methodParameterDirections();
      }
    }
    else if (slotname == Stella.SYM_STELLA_METHOD_RETURN_TYPE_SPECIFIERS) {
      if (setvalueP) {
        self.methodReturnTypeSpecifiers = ((List)(value));
      }
      else {
        value = self.methodReturnTypeSpecifiers();
      }
    }
    else if (slotname == Stella.SYM_STELLA_METHOD_STRINGIFIED_SOURCE) {
      if (setvalueP) {
        self.methodStringifiedSource = ((StringWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapString(self.methodStringifiedSource);
      }
    }
    else if (slotname == Stella.SYM_STELLA_METHOD_CODE) {
      if (setvalueP) {
        self.methodCode = ((MethodCodeWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapMethodCode(self.methodCode);
      }
    }
    else if (slotname == Stella.SYM_STELLA_FUNCTION_CODE) {
      if (setvalueP) {
        self.functionCode = ((FunctionCodeWrapper)(value)).wrapperValue;
      }
      else {
        value = Stella.wrapFunctionCode(self.functionCode);
      }
    }
    else if (slotname == Stella.SYM_STELLA_METHOD_FUNCTIONp) {
      if (setvalueP) {
        self.methodFunctionP = BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value)));
      }
      else {
        value = (self.methodFunctionP ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
      }
    }
    else if (slotname == Stella.SYM_STELLA_METHOD_INLINED_FUNCTIONS) {
      if (setvalueP) {
        KeyValueList.setDynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_METHOD_INLINED_FUNCTIONS, ((List)(value)), null);
      }
      else {
        value = self.methodInlinedFunctions();
      }
    }
    else if (slotname == Stella.SYM_STELLA_METHOD_EVALUATE_ARGUMENTSp) {
      if (setvalueP) {
        KeyValueList.setDynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_METHOD_EVALUATE_ARGUMENTSp, (BooleanWrapper.coerceWrappedBooleanToBoolean(((BooleanWrapper)(value))) ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER), Stella.FALSE_WRAPPER);
      }
      else {
        value = (self.methodEvaluateArgumentsP() ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER);
      }
    }
    else {
      if (slotname == Stella.SYM_STELLA_METHOD_DOCUMENTATION) {
        slotname = Stella.SYM_STELLA_DOCUMENTATION;
      }
      else if (slotname == Stella.SYM_STELLA_METHOD_AUXILIARYp) {
        slotname = Stella.SYM_STELLA_SLOT_AUXILIARYp;
      }
      else if (slotname == Stella.SYM_STELLA_METHOD_STORAGE_SLOT) {
        slotname = Stella.SYM_STELLA_STORAGE_SLOT;
      }
      else {
      }
      if (setvalueP) {
        KeyValueList.setDynamicSlotValue(self.dynamicSlots, slotname, value, null);
      }
      else {
        value = self.dynamicSlots.lookup(slotname);
      }
    }
    return (value);
  }

  public boolean methodEvaluateArgumentsP() {
    { MethodSlot self = this;

      return (((BooleanWrapper)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_METHOD_EVALUATE_ARGUMENTSp, Stella.TRUE_WRAPPER))).wrapperValue);
    }
  }

  public List methodInlinedFunctions() {
    { MethodSlot self = this;

      { List answer = ((List)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_METHOD_INLINED_FUNCTIONS, null)));

        if (answer == null) {
          return (Stella.NIL_LIST);
        }
        else {
          return (answer);
        }
      }
    }
  }

  public List methodReturnTypeSpecifiers() {
    { MethodSlot self = this;

      { List answer = self.methodReturnTypeSpecifiers;

        if (answer == null) {
          return (Stella.NIL_LIST);
        }
        else {
          return (answer);
        }
      }
    }
  }

  public List methodParameterDirections() {
    { MethodSlot self = this;

      { List answer = ((List)(KeyValueList.dynamicSlotValue(self.dynamicSlots, Stella.SYM_STELLA_METHOD_PARAMETER_DIRECTIONS, null)));

        if (answer == null) {
          return (Stella.NIL_LIST);
        }
        else {
          return (answer);
        }
      }
    }
  }

  public List methodParameterTypeSpecifiers() {
    { MethodSlot self = this;

      { List answer = self.methodParameterTypeSpecifiers;

        if (answer == null) {
          return (Stella.NIL_LIST);
        }
        else {
          return (answer);
        }
      }
    }
  }

  public List methodParameterNames() {
    { MethodSlot self = this;

      { List answer = self.methodParameterNames;

        if (answer == null) {
          return (Stella.NIL_LIST);
        }
        else {
          return (answer);
        }
      }
    }
  }

  public boolean setterP() {
    { MethodSlot self = this;

      return (self.methodSetterP);
    }
  }

  public Surrogate primaryType() {
    { MethodSlot self = this;

      return (Stella.SGT_STELLA_METHOD_SLOT);
    }
  }

}

