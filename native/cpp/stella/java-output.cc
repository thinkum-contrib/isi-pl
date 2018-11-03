//  -*- Mode: C++ -*-

// java-output.cc

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

#include "stella/stella-system.hh"

namespace stella {

DEFINE_STELLA_SPECIAL(oJAVA_INDENT_CHARSo, int , 0);

KeyValueList* oJAVA_STELLA_PACKAGE_MAPPINGo = NULL;

char* javaStellaPackage() {
  { char* stellapackage = oSTELLA_MODULEo->javaPackage_reader();

    if (stellapackage != NULL) {
      return (stellapackage);
    }
    else {
      return ("edu.isi.stella");
    }
  }
}

void javaOutputParseTree(Cons* constree) {
  { 
    BIND_STELLA_SPECIAL(oJAVA_INDENT_CHARSo, int, 0);
    oJAVA_STELLA_PACKAGE_MAPPINGo->insertAt(wrapString("STELLAROOT"), wrapString(javaStellaPackage()));
    javaOutputStatement(constree);
  }
}

void javaBumpIndent() {
  oJAVA_INDENT_CHARSo.set(oJAVA_INDENT_CHARSo.get() + 2);
}

void javaUnbumpIndent() {
  oJAVA_INDENT_CHARSo.set(oJAVA_INDENT_CHARSo.get() - 2);
}

void javaIndent() {
  { int i = NULL_INTEGER;
    int iter000 = 1;
    int upperBound000 = oJAVA_INDENT_CHARSo.get();
    boolean unboundedP000 = upperBound000 == NULL_INTEGER;

    while (unboundedP000 ||
        (iter000 <= upperBound000)) {
      i = iter000;
      iter000 = iter000 + 1;
      i = i;
      *(oCURRENT_STREAMo.get()->nativeStream) << " ";
    }
  }
}

void javaOutputStatement(Object* statement) {
  if (safePrimaryType(statement) == SGT_JAVA_OUTPUT_STELLA_CONS) {
    { Object* statement000 = statement;
      Cons* statement = ((Cons*)(statement000));

      if (statement == NIL) {
        return;
      }
      if (consP(statement->value) ||
          (!((boolean)(statement->value)))) {
        {
          javaOutputStatement(statement->value);
          javaOutputStatement(statement->rest);
        }
      }
      else {
        { GeneralizedSymbol* testValue000 = ((GeneralizedSymbol*)(statement->value));

          if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_CLASS) {
            javaOutputClass(statement->rest, FALSE);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_EXCEPTION_CLASS) {
            javaOutputClass(statement->rest, TRUE);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_NAMED_STATEMENT) {
            javaOutputNamedStatement(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_STATEMENTS) {
            javaOutputStatements(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_IDENT) {
            javaOutputIdentifier(((StringWrapper*)(statement->rest->value)));
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_EOL) {
            javaOutputIdentifier(((StringWrapper*)(statement->rest->value)));
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_LITERAL) {
            statement->rest->value->javaOutputLiteral();
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_COMMENT) {
            javaOutputComment(((StringWrapper*)(statement->rest->value)));
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_SYMBOL) {
            statement->rest->value->javaOutputLiteral();
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_CATCH) {
            javaOutputCatch(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_THROW) {
            javaOutputThrow(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_UNWIND_PROTECT) {
            javaOutputUnwindProtect(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_HANDLER_CASE) {
            javaOutputHandlerCase(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_SIGNAL) {
            javaOutputSignal(((Cons*)(statement->rest->value)));
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_VERBATIM) {
            javaOutputVerbatim(((StringWrapper*)(statement->rest->value)));
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_CAST) {
            javaOutputCast(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_GLOBAL) {
            javaOutputGlobalDefinition(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_TYPE) {
            javaOutputTypeExpression(((Cons*)(statement->rest)));
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_PROGN) {
            javaOutputProgn(((Cons*)(statement->rest->value)));
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_BLOCK) {
            javaOutputBlock(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_WITH_PROCESS_LOCK) {
            javaOutputWithProcessLock(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_RETURN) {
            javaOutputReturn(((Cons*)(statement->rest->value)));
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_MAKE) {
            javaOutputMake(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCALL) {
            javaOutputFuncall(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_CODE_CALL) {
            javaOutputMethodCodeCall(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_ASSIGN) {
            javaOutputAssignment(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_BREAK) {
            javaOutputBreak(((Cons*)(statement->rest->value)));
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_CONTINUE) {
            javaOutputContinue(((Cons*)(statement->rest->value)));
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_COND) {
            javaOutputCond(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_CASE) {
            javaOutputCase(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_IF) {
            javaOutputIf(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_WHEN) {
            javaOutputWhen(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_UNLESS) {
            javaOutputUnless(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_LOOP) {
            javaOutputLoop(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_WHILE) {
            javaOutputWhile(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_FOREACH) {
            javaOutputForeach(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_SLOT_VALUE) {
            javaOutputSlotValue(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_SLOT_VALUE_SETTER) {
            javaOutputSlotValueSetter(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_UNARY_OP) {
            javaOutputUnaryOperator(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_BINARY_OP) {
            javaOutputBinaryOperator(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_TERNARY_OP) {
            javaOutputTernaryOperator(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCTION_CALL) {
            javaOutputFunctionCall(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_CALL) {
            javaOutputMethodCall(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_ACTUALS) {
            javaOutputActualParameters(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_MAKE_ARRAY) {
            javaOutputMakeArray(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_ARRAY_INITIALIZER) {
            javaOutputArray(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_ANONYMOUS_ARRAY) {
            javaOutputAnonymousArray(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_AREF) {
            javaOutputAref(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD) {
            javaOutputMethod(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCTION) {
            javaOutputMethod(statement->rest);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_PRINT_STREAM) {
            javaOutputPrintStream(statement->rest, FALSE);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_PRINT_NATIVE_STREAM) {
            javaOutputPrintStream(statement->rest, TRUE);
          }
          else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_DECLARATIONS) {
            javaOutputDeclarations(((Cons*)(statement->rest)));
          }
          else {
            { OutputStringStream* stream000 = newOutputStringStream();

              *(stream000->nativeStream) << "`" << testValue000 << "'" << " is not a valid case option";
              throw *newStellaException(stream000->theStringReader());
            }
          }
        }
      }
    }
  }
  else {
    if (!((boolean)(statement))) {
      return;
    }
    statement->javaOutputLiteral();
  }
}

void javaMaybeOutputStatementWithParentheses(Object* statement) {
  if (javaOperatorP(statement)) {
    *(oCURRENT_STREAMo.get()->nativeStream) << "(";
  }
  javaOutputStatement(statement);
  if (javaOperatorP(statement)) {
    *(oCURRENT_STREAMo.get()->nativeStream) << ")";
  }
}

void javaOutputIdentifier(StringWrapper* identifier) {
  *(oCURRENT_STREAMo.get()->nativeStream) << identifier->wrapperValue;
}

void Object::javaOutputLiteral() {
  { Object* object = this;

  }
}

void stringJavaOutputLiteral(char* string) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "\"" << replaceSubstrings(replaceSubstrings(replaceSubstrings(replaceSubstrings(string, "\\\\", "\\"), "\\\"", makeString(1, '"')), "\\n", makeString(1, '\n')), "\\r", makeString(1, '\r')) << "\"";
}

void StringWrapper::javaOutputLiteral() {
  { StringWrapper* string = this;

    stringJavaOutputLiteral(string->wrapperValue);
  }
}

void MutableStringWrapper::javaOutputLiteral() {
  { MutableStringWrapper* string = this;

    *(oCURRENT_STREAMo.get()->nativeStream) << "new StringBuffer(";
    stringJavaOutputLiteral((string->wrapperValue));
    *(oCURRENT_STREAMo.get()->nativeStream) << ")";
  }
}

void CharacterWrapper::javaOutputLiteral() {
  { CharacterWrapper* character = this;

    switch (character->wrapperValue) {
      case '\'': 
        *(oCURRENT_STREAMo.get()->nativeStream) << "'\\''";
      break;
      case '\\': 
        *(oCURRENT_STREAMo.get()->nativeStream) << "'\\\\'";
      break;
      case '\n': 
        *(oCURRENT_STREAMo.get()->nativeStream) << "'\\n'";
      break;
      case '\b': 
        *(oCURRENT_STREAMo.get()->nativeStream) << "'\\b'";
      break;
      case '\t': 
        *(oCURRENT_STREAMo.get()->nativeStream) << "'\\t'";
      break;
      case '\r': 
        *(oCURRENT_STREAMo.get()->nativeStream) << "'\\r'";
      break;
      case '\f': 
        *(oCURRENT_STREAMo.get()->nativeStream) << "'\\f'";
      break;
      default:
        *(oCURRENT_STREAMo.get()->nativeStream) << "'" << character->wrapperValue << "'";
      break;
    }
  }
}

void IntegerWrapper::javaOutputLiteral() {
  { IntegerWrapper* inT = this;

    *(oCURRENT_STREAMo.get()->nativeStream) << inT->wrapperValue;
  }
}

void FloatWrapper::javaOutputLiteral() {
  { FloatWrapper* floaT = this;

    *(oCURRENT_STREAMo.get()->nativeStream) << floaT->wrapperValue;
  }
}

void BooleanWrapper::javaOutputLiteral() {
  { BooleanWrapper* boolean = this;

    if (boolean->wrapperValue) {
      *(oCURRENT_STREAMo.get()->nativeStream) << "true";
    }
    else {
      *(oCURRENT_STREAMo.get()->nativeStream) << "false";
    }
  }
}

void javaOutputMakeArray(Cons* statement) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "new ";
  *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(statement->value))->wrapperValue;
  { Object* dimension = NULL;
    Cons* iter000 = statement->rest;

    while (!(iter000 == NIL)) {
      dimension = iter000->value;
      iter000 = iter000->rest;
      *(oCURRENT_STREAMo.get()->nativeStream) << "[";
      javaOutputStatement(dimension);
      *(oCURRENT_STREAMo.get()->nativeStream) << "]";
    }
  }
}

void javaOutputArray(Cons* arrayelements) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "{";
  if (((boolean)(arrayelements->value))) {
    javaOutputStatement(arrayelements->value);
  }
  { Object* element = NULL;
    Cons* iter000 = arrayelements->rest;

    while (!(iter000 == NIL)) {
      element = iter000->value;
      iter000 = iter000->rest;
      *(oCURRENT_STREAMo.get()->nativeStream) << ", ";
      javaOutputStatement(element);
    }
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << "}";
}

void javaOutputAnonymousArray(Cons* statement) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "new ";
  *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(statement->value))->wrapperValue;
  *(oCURRENT_STREAMo.get()->nativeStream) << " [] ";
  javaOutputArray(statement->rest);
}

void javaOutputAref(Cons* statement) {
  javaOutputStatement(statement->value);
  { Object* dimension = NULL;
    Cons* iter000 = statement->rest;

    while (!(iter000 == NIL)) {
      dimension = iter000->value;
      iter000 = iter000->rest;
      *(oCURRENT_STREAMo.get()->nativeStream) << "[";
      javaOutputStatement(dimension);
      *(oCURRENT_STREAMo.get()->nativeStream) << "]";
    }
  }
}

void javaOutputSlotValue(Cons* statement) {
  javaOutputStatement(statement->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << "." << ((StringWrapper*)(statement->rest->value))->wrapperValue;
}

void javaOutputSlotValueSetter(Cons* statement) {
  javaOutputStatement(statement->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << "." << ((StringWrapper*)(statement->rest->value))->wrapperValue << " = ";
  javaOutputStatement(statement->rest->rest->value);
}

void javaOutputImplementsInterfaces(Cons* interfacelist) {
  *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(interfacelist->value))->wrapperValue;
  { StringWrapper* interface = NULL;
    Cons* iter000 = interfacelist->rest;

    while (!(iter000 == NIL)) {
      interface = ((StringWrapper*)(iter000->value));
      iter000 = iter000->rest;
      *(oCURRENT_STREAMo.get()->nativeStream) << ", " << interface->wrapperValue;
    }
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << " ";
}

void javaOutputClass(Cons* classdef, boolean exceptionclassP) {
  javaOutputClassDeclaration(classdef);
  *(oCURRENT_STREAMo.get()->nativeStream) << "{" << std::endl;
  javaBumpIndent();
  javaOutputClassVariableDefinitions(((Cons*)(classdef->nth(6))));
  javaOutputClassConstructors(((Cons*)(classdef->nth(7))), ((StringWrapper*)(classdef->fourth()))->wrapperValue, exceptionclassP);
  javaOutputClassMethods(((Cons*)(classdef->nth(8))));
  javaUnbumpIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl << std::endl;
}

void javaOutputClassDeclaration(Cons* classdef) {
  if (unwrapString(((StringWrapper*)(classdef->value))) != NULL) {
    javaOutputJavadocComment(((StringWrapper*)(classdef->value)), NULL, NULL, "Stella Java Translator", NULL);
  }
  { Object* m = NULL;
    Cons* iter000 = ((Cons*)(classdef->rest->value));

    while (!(iter000 == NIL)) {
      m = iter000->value;
      iter000 = iter000->rest;
      *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(m))->wrapperValue << " ";
    }
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(classdef->rest->rest->value))->wrapperValue << " " << ((StringWrapper*)(classdef->fourth()))->wrapperValue << " ";
  if (((boolean)(classdef->fifth()))) {
    *(oCURRENT_STREAMo.get()->nativeStream) << "extends " << ((StringWrapper*)(classdef->fifth()))->wrapperValue << " ";
  }
  if (!(((Cons*)(classdef->nth(5))) == NIL)) {
    *(oCURRENT_STREAMo.get()->nativeStream) << "implements ";
    javaOutputImplementsInterfaces(((Cons*)(classdef->nth(5))));
  }
}

void javaOutputClassVariableDefinitions(Cons* variabletranslations) {
  { Object* statement = NULL;
    Cons* iter000 = variabletranslations;

    while (!(iter000 == NIL)) {
      statement = iter000->value;
      iter000 = iter000->rest;
      javaOutputStatement(((Cons*)(statement)));
    }
  }
}

void javaOutputClassConstructors(Cons* constructors, char* classname, boolean exceptionclassP) {
  if (exceptionclassP) {
    javaOutputExceptionConstructor(classname);
  }
  { TranslationUnit* statement = NULL;
    Cons* iter000 = constructors;

    while (!(iter000 == NIL)) {
      statement = ((TranslationUnit*)(iter000->value));
      iter000 = iter000->rest;
      javaOutputStatement(javaTranslateUnit(statement));
      statement->translation = NULL;
      statement->codeRegister = NULL;
    }
  }
}

void javaOutputClassMethods(Cons* methods) {
  { TranslationUnit* statement = NULL;
    Cons* iter000 = methods;

    while (!(iter000 == NIL)) {
      statement = ((TranslationUnit*)(iter000->value));
      iter000 = iter000->rest;
      javaOutputStatement(javaTranslateUnit(statement));
      statement->translation = NULL;
      statement->codeRegister = NULL;
    }
  }
}

void javaOutputExceptionConstructor(char* exceptionname) {
  javaIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << "public " << exceptionname << " (String message) {" << std::endl;
  javaBumpIndent();
  javaIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << "super(message);" << std::endl;
  javaUnbumpIndent();
  javaIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl << std::endl;
}

void javaOutputNamedStatement(Cons* namedstatement) {
  javaOutputStatement(namedstatement->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << " : ";
  javaOutputStatement(namedstatement->rest->value);
}

void javaOutputFormalParameters(Cons* parameters) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "(";
  if (!(parameters == NIL)) {
    *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(((Cons*)(parameters->value))->value))->wrapperValue << " " << ((StringWrapper*)(((Cons*)(parameters->value))->rest->value))->wrapperValue;
    { Cons* parameter = NULL;
      Cons* iter000 = parameters->rest;

      while (!(iter000 == NIL)) {
        parameter = ((Cons*)(iter000->value));
        iter000 = iter000->rest;
        *(oCURRENT_STREAMo.get()->nativeStream) << ", " << ((StringWrapper*)(parameter->value))->wrapperValue << " " << ((StringWrapper*)(parameter->rest->value))->wrapperValue;
      }
    }
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << ")";
}

void javaOutputMethodSignature(Cons* method) {
  { Object* m = NULL;
    Cons* iter000 = ((Cons*)(method->value));

    while (!(iter000 == NIL)) {
      m = iter000->value;
      iter000 = iter000->rest;
      *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(m))->wrapperValue << " ";
    }
  }
  javaOutputTypeExpression(((Cons*)(method->rest->value)));
  *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(method->rest->rest->value))->wrapperValue;
  javaOutputFormalParameters(((Cons*)(method->fourth())));
}

Cons* javaSeparateCommentFromBody(Cons* body, Cons*& _Return1) {
  if ((body->value == SYM_JAVA_OUTPUT_STELLA_JAVA_STATEMENTS) &&
      ((!(body->rest == NIL)) &&
       (isaP(body->rest->value, SGT_JAVA_OUTPUT_STELLA_CONS) &&
        (((Cons*)(body->rest->value))->value == SYM_JAVA_OUTPUT_STELLA_JAVA_COMMENT)))) {
    { Object* comment = body->rest->value;

      body->rest = body->rest->rest;
      if (body->rest == NIL) {
        _Return1 = ((Cons*)(comment));
        return (NIL);
      }
      else {
        _Return1 = ((Cons*)(comment));
        return (body);
      }
    }
  }
  else {
    _Return1 = NULL;
    return (body);
  }
}

void javaOutputMethod(Cons* method) {
  { Cons* body = NULL;
    Cons* comment = NULL;

    body = javaSeparateCommentFromBody(((Cons*)(method->fifth())), comment);
    if (((boolean)(comment))) {
      javaIndent();
      javaOutputJavadocComment(((StringWrapper*)(comment->rest->value)), ((Cons*)(method->fourth())), ((StringWrapper*)(((Cons*)(method->rest->value))->value)), NULL, NULL);
    }
    javaIndent();
    javaOutputMethodSignature(method);
    if (!(body == NIL)) {
      *(oCURRENT_STREAMo.get()->nativeStream) << " {" << std::endl;
      javaBumpIndent();
      javaOutputStatement(body);
      javaUnbumpIndent();
      javaIndent();
      *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl;
    }
    else if (((Cons*)(method->value))->memberP(wrapString("abstract"))) {
      *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
    }
    else if (((Cons*)(method->rest->value))->memberP(wrapString("void"))) {
      std::cout << "Note: Void method " << "`" << method->rest->rest->value << "'" << " has an empty body." << std::endl;
      *(oCURRENT_STREAMo.get()->nativeStream) << " {}" << std::endl;
    }
    else {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "Method " << "`" << method->rest->rest->value << "'" << " has an empty body but is not abstract or void!" << std::endl;
      *(oCURRENT_STREAMo.get()->nativeStream) << " {}" << std::endl;
    }
    *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
  }
}

void Cons::javaOutputLiteral() {
  { Cons* cons = this;

    if (cons == NIL) {
      *(oCURRENT_STREAMo.get()->nativeStream) << "NIL";
    }
    else {
      {
        *(oCURRENT_STREAMo.get()->nativeStream) << "(" << cons->value << " . ";
        cons->rest->javaOutputLiteral();
      }
    }
  }
}

void QuotedExpression::javaOutputLiteral() {
  { QuotedExpression* tree = this;

    *(oCURRENT_STREAMo.get()->nativeStream) << "\"" << tree << "\"";
  }
}

void Symbol::javaOutputLiteral() {
  { Symbol* symbol = this;

    *(oCURRENT_STREAMo.get()->nativeStream) << javaTranslateSymbolName(symbol)->wrapperValue;
  }
}

void Surrogate::javaOutputLiteral() {
  { Surrogate* surrogate = this;

    *(oCURRENT_STREAMo.get()->nativeStream) << javaTranslateSurrogateName(surrogate)->wrapperValue;
  }
}

void Keyword::javaOutputLiteral() {
  { Keyword* keyword = this;

    *(oCURRENT_STREAMo.get()->nativeStream) << javaTranslateKeywordName(keyword)->wrapperValue;
  }
}

void javaOutputTypeExpression(Cons* typeexpression) {
  { StringWrapper* typeexpr = NULL;
    Cons* iter000 = typeexpression;

    while (!(iter000 == NIL)) {
      typeexpr = ((StringWrapper*)(iter000->value));
      iter000 = iter000->rest;
      *(oCURRENT_STREAMo.get()->nativeStream) << typeexpr->wrapperValue << " ";
    }
  }
}

Cons* oJAVA_SEMICOLON_STATEMENTSo = NULL;

boolean javaOutputSemicolonP(Cons* statement) {
  if (((boolean)(statement))) {
    return (oJAVA_SEMICOLON_STATEMENTSo->memberP(statement->value));
  }
  else {
    return (FALSE);
  }
}

boolean javaIndentStatementP(Cons* statement) {
  if (((boolean)(statement))) {
    return (!getQuotedTree("((JAVA_STATEMENTS JAVA_CATCH) \"/STELLA\")", "/STELLA")->memberP(statement->value));
  }
  else {
    return (FALSE);
  }
}

boolean javaIllegalStatementP(Cons* statement) {
  if (((boolean)(statement))) {
    return (getQuotedTree("((JAVA_LITERAL JAVA_IDENT) \"/STELLA\")", "/STELLA")->memberP(statement->value));
  }
  else {
    return (FALSE);
  }
}

void javaOutputStatements(Cons* statementlist) {
  { Object* statement = NULL;
    Cons* iter000 = statementlist;

    while (!(iter000 == NIL)) {
      statement = iter000->value;
      iter000 = iter000->rest;
      if (!(javaIllegalStatementP(((Cons*)(statement))))) {
        if (javaIndentStatementP(((Cons*)(statement)))) {
          javaIndent();
        }
        javaOutputStatement(statement);
        if (javaOutputSemicolonP(((Cons*)(statement)))) {
          *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
        }
      }
    }
  }
}

void javaOutputDeclarations(Cons* declarations) {
  javaBumpIndent();
  { Cons* declaration = NULL;
    Cons* iter000 = declarations;

    while (!(iter000 == NIL)) {
      declaration = ((Cons*)(iter000->value));
      iter000 = iter000->rest;
      if (((boolean)(declaration->rest->rest->value))) {
        javaIndent();
        javaOutputJavadocComment(((StringWrapper*)(declaration->rest->rest->value)), NIL, NULL, NULL, NULL);
      }
      javaIndent();
      javaOutputTypeExpression(((Cons*)(declaration->value)));
      *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(declaration->rest->value))->wrapperValue;
      *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
    }
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
  javaUnbumpIndent();
}

char* javaHeuristicallyTranslateName(char* stellaName, Cons* caseConvertedNameList) {
  { StringWrapper* pname = NULL;
    Cons* iter000 = caseConvertedNameList;

    while (!(iter000 == NIL)) {
      pname = ((StringWrapper*)(iter000->value));
      iter000 = iter000->rest;
      if (stringEqualP(pname->wrapperValue, stellaName)) {
        return (pname->wrapperValue);
      }
    }
  }
  { boolean testValue000 = FALSE;

    if (oMODULEo.get()->caseSensitiveP) {
      testValue000 = TRUE;
    }
    else {
      { boolean foundP000 = FALSE;

        { char ch = NULL_CHARACTER;
          char* vector000 = stellaName;
          int index000 = 0;
          int length000 = strlen(vector000);

          while (index000 < length000) {
            ch = vector000[index000];
            index000 = index000 + 1;
            if (upperCaseCharacterP(ch)) {
              foundP000 = TRUE;
              break;
            }
          }
        }
        testValue000 = foundP000;
      }
    }
    if (testValue000) {
      {
        return (javaTranslateNamestring(makeMatchingNameFull(stellaName, KWD_JAVA_OUTPUT_NO, KWD_JAVA_OUTPUT_NO, "- ", "", "", "", "", KWD_JAVA_OUTPUT_PRESERVE, "_")));
      }
    }
    else {
      if (stringMemberP(stellaName, '*')) {
        {
          return (javaTranslateNamestring(makeMatchingNameFull(stellaName, KWD_JAVA_OUTPUT_CLEVER, KWD_JAVA_OUTPUT_CLEVER, "- ", "", "", "", "", KWD_JAVA_OUTPUT_UPCASE, "_")));
        }
      }
      else {
        {
          return (javaTranslateNamestring(makeMatchingNameFull(stellaName, KWD_JAVA_OUTPUT_CLEVER, KWD_JAVA_OUTPUT_CLEVER, "- ", "", "", "", "", KWD_JAVA_OUTPUT_TITLECASEX, "")));
        }
      }
    }
  }
}

void javaOutputCommentString(char* comment, char* commentStart, char* commentContinuation, char* commentEnd, boolean javadocCommentP, Cons* caseConvertedNameList) {
  { boolean returnP = FALSE;
    boolean escapeP = FALSE;
    boolean insideQuoteP = FALSE;
    OutputStream* savedStream = oCURRENT_STREAMo.get();
    OutputStringStream* stringStream = NULL;
    char* stellaName = NULL;

    *(oCURRENT_STREAMo.get()->nativeStream) << commentStart;
    { char chaR = NULL_CHARACTER;
      char* vector000 = comment;
      int index000 = 0;
      int length000 = strlen(vector000);

      while (index000 < length000) {
        chaR = vector000[index000];
        index000 = index000 + 1;
        switch (chaR) {
          case '\n': 
            if (!(returnP)) {
              *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
              javaIndent();
              *(oCURRENT_STREAMo.get()->nativeStream) << commentContinuation;
            }
          break;
          case '\r': 
            *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
            javaIndent();
            *(oCURRENT_STREAMo.get()->nativeStream) << commentContinuation;
            returnP = TRUE;
            escapeP = FALSE;
            continue;
          break;
          case '`': 
            if (escapeP) {
              *(oCURRENT_STREAMo.get()->nativeStream) << chaR;
            }
            else if (insideQuoteP) {
              *(STANDARD_WARNING->nativeStream) << "Warning: " << "Encountered unescaped ` inside ` form in comment " << "`" << comment << "'" << std::endl;
              *(oCURRENT_STREAMo.get()->nativeStream) << chaR;
            }
            else {
              stringStream = newOutputStringStream();
              oCURRENT_STREAMo.set(stringStream);
              insideQuoteP = TRUE;
            }
          break;
          case '\'': 
            if (escapeP) {
              *(oCURRENT_STREAMo.get()->nativeStream) << chaR;
            }
            else if (insideQuoteP) {
              oCURRENT_STREAMo.set(savedStream);
              stellaName = stringStream->theStringReader();
              if (javadocCommentP) {
                *(oCURRENT_STREAMo.get()->nativeStream) << "<code>";
              }
              else {
                *(oCURRENT_STREAMo.get()->nativeStream) << "`";
              }
              *(oCURRENT_STREAMo.get()->nativeStream) << javaHeuristicallyTranslateName(stellaName, caseConvertedNameList);
              if (javadocCommentP) {
                *(oCURRENT_STREAMo.get()->nativeStream) << "</code>";
              }
              else {
                *(oCURRENT_STREAMo.get()->nativeStream) << "'";
              }
              insideQuoteP = FALSE;
            }
            else {
              *(oCURRENT_STREAMo.get()->nativeStream) << chaR;
            }
          break;
          case '\\': 
            if (escapeP) {
              *(oCURRENT_STREAMo.get()->nativeStream) << chaR;
            }
            else {
              {
                escapeP = TRUE;
                returnP = FALSE;
                continue;
              }
            }
          break;
          default:
            if (insideQuoteP ||
                (!javadocCommentP)) {
              *(oCURRENT_STREAMo.get()->nativeStream) << chaR;
            }
            else {
              writeHtmlCharacterQuotingSpecialCharacters(oCURRENT_STREAMo.get()->nativeStream, chaR);
            }
            returnP = FALSE;
            escapeP = FALSE;
          break;
        }
      }
    }
    if ((commentEnd != NULL) &&
        (!stringEqlP(commentEnd, ""))) {
      {
        javaIndent();
        *(oCURRENT_STREAMo.get()->nativeStream) << commentEnd;
      }
    }
    else {
      *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
    }
  }
}

void javaOutputComment(StringWrapper* tree) {
  javaOutputCommentString(tree->wrapperValue, "// ", "// ", NULL, FALSE, NIL);
}

void javaOutputJavadocComment(StringWrapper* tree, Cons* parameterNamesAndTypes, StringWrapper* returnValue, char* author, char* version) {
  { Cons* parameterNames = NIL;

    if (((boolean)(parameterNamesAndTypes))) {
      { Cons* n = NULL;
        Cons* iter000 = parameterNamesAndTypes;
        Cons* collect000 = NULL;

        while (!(iter000 == NIL)) {
          n = ((Cons*)(iter000->value));
          iter000 = iter000->rest;
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(((StringWrapper*)(n->rest->value)), NIL);
              if (parameterNames == NIL) {
                parameterNames = collect000;
              }
              else {
                addConsToEndOfConsList(parameterNames, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(((StringWrapper*)(n->rest->value)), NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    javaOutputCommentString(tree->wrapperValue, "/** ", " * ", NULL, TRUE, parameterNames);
    { StringWrapper* n = NULL;
      Cons* iter001 = parameterNames;

      while (!(iter001 == NIL)) {
        n = ((StringWrapper*)(iter001->value));
        iter001 = iter001->rest;
        javaIndent();
        *(oCURRENT_STREAMo.get()->nativeStream) << " * @param " << n->wrapperValue << std::endl;
      }
    }
    if (((boolean)(returnValue)) &&
        (!stringEqlP(returnValue->wrapperValue, "void"))) {
      javaIndent();
      *(oCURRENT_STREAMo.get()->nativeStream) << " * @return " << returnValue->wrapperValue << std::endl;
    }
    if ((author != NULL) &&
        (!(author == ""))) {
      javaIndent();
      *(oCURRENT_STREAMo.get()->nativeStream) << " * @author " << author << std::endl;
    }
    if ((version != NULL) &&
        (!(version == ""))) {
      javaIndent();
      *(oCURRENT_STREAMo.get()->nativeStream) << " * @version " << version << std::endl;
    }
    javaIndent();
    *(oCURRENT_STREAMo.get()->nativeStream) << " */" << std::endl;
  }
}

char* fixupDocumentationStringQuoting(char* documentation) {
  if (documentation == NULL) {
    return (NULL);
  }
  { int closingquoteposition = NULL_INTEGER;
    char precedingcharacter = NULL_CHARACTER;
    char* openparentheses = "([{";
    char* buffer = strcpy(new (GC) char[strlen(documentation)+1], documentation);

    { char chaR = NULL_CHARACTER;
      int i = NULL_INTEGER;
      char* vector000 = documentation;
      int index000 = 0;
      int length000 = strlen(vector000);
      int iter000 = 0;

      while (index000 < length000) {
        chaR = vector000[index000];
        index000 = index000 + 1;
        i = iter000;
        iter000 = iter000 + 1;
        switch (chaR) {
          case '`': 
          case '\'': 
            if (i == closingquoteposition) {
              continue;
            }
            if (i == 0) {
              precedingcharacter = ' ';
            }
            else {
              precedingcharacter = documentation[(i - 1)];
            }
            if ((oCHARACTER_TYPE_TABLEo[(int)(unsigned char) precedingcharacter] == KWD_JAVA_OUTPUT_WHITE_SPACE) ||
                stringMemberP(openparentheses, precedingcharacter)) {
              closingquoteposition = stringPosition(documentation, '\'', i + 1);
              if (closingquoteposition != NULL_INTEGER) {
                buffer[i] = '`';
              }
            }
          break;
          default:
          break;
        }
      }
    }
    return (buffer);
  }
}

void javaOutputVerbatim(StringWrapper* verbatimstatement) {
  *(oCURRENT_STREAMo.get()->nativeStream) << substituteTemplateVariablesInString(verbatimstatement->wrapperValue, oJAVA_STELLA_PACKAGE_MAPPINGo);
}

void javaOutputMake(Cons* statement) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "new ";
  javaOutputStatement(statement->value);
  javaOutputStatement(statement->rest->value);
}

void javaOutputCast(Cons* tree) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "((" << ((StringWrapper*)(tree->rest->value))->wrapperValue << ")(";
  javaOutputStatement(tree->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << "))";
}

void javaOutputProgn(Cons* progn) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "{" << std::endl;
  javaBumpIndent();
  javaOutputStatement(progn);
  javaUnbumpIndent();
  javaIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl;
}

void javaOutputBlock(Cons* block) {
  { boolean firststatementP = TRUE;

    *(oCURRENT_STREAMo.get()->nativeStream) << "{ ";
    javaBumpIndent();
    { Cons* declaration = NULL;
      Cons* iter000 = ((Cons*)(block->value));

      while (!(iter000 == NIL)) {
        declaration = ((Cons*)(iter000->value));
        iter000 = iter000->rest;
        if (!(firststatementP)) {
          javaIndent();
        }
        firststatementP = FALSE;
        *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(declaration->value))->wrapperValue;
        *(oCURRENT_STREAMo.get()->nativeStream) << " ";
        javaOutputStatement(declaration->rest->value);
        if (!(!((boolean)(declaration->rest->rest->value)))) {
          *(oCURRENT_STREAMo.get()->nativeStream) << " = ";
          javaOutputStatement(declaration->rest->rest->value);
        }
        *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
      }
    }
    *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
    javaOutputStatement(block->rest->value);
    javaUnbumpIndent();
    javaIndent();
    *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl;
  }
}

void javaOutputWithProcessLock(Cons* synch) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "synchronized (";
  javaOutputStatement(synch->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << ") ";
  javaOutputProgn(((Cons*)(synch->rest->value)));
}

void javaOutputReturn(Cons* returnstatement) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "return";
  if (((boolean)(returnstatement))) {
    *(oCURRENT_STREAMo.get()->nativeStream) << " (";
    javaOutputStatement(returnstatement);
    *(oCURRENT_STREAMo.get()->nativeStream) << ")";
  }
}

void javaOutputThrow(Cons* tree) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "throw new ";
  *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(tree->value))->wrapperValue;
}

void javaOutputCatch(Cons* tree) {
  *(oCURRENT_STREAMo.get()->nativeStream) << " catch (";
  *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(((Cons*)(tree->value))->value))->wrapperValue;
  *(oCURRENT_STREAMo.get()->nativeStream) << " ";
  *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(((Cons*)(tree->value))->rest->value))->wrapperValue;
  *(oCURRENT_STREAMo.get()->nativeStream) << ") {" << std::endl;
  javaBumpIndent();
  javaOutputStatements(tree->rest);
  javaUnbumpIndent();
  javaIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << "}";
}

void javaOutputUnwindProtect(Cons* tree) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "try {" << std::endl;
  javaBumpIndent();
  if (javaPrognP(tree->value)) {
    javaOutputStatement(((Cons*)(tree->value))->rest->value);
  }
  else if (javaIndentStatementP(((Cons*)(tree->value)))) {
    javaIndent();
    javaOutputStatement(tree->value);
    if (javaOutputSemicolonP(((Cons*)(tree->value)))) {
      *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
    }
  }
  else {
    javaOutputStatement(tree->value);
  }
  javaUnbumpIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
  javaIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << "} finally {" << std::endl;
  javaBumpIndent();
  javaOutputStatements(tree->rest);
  javaUnbumpIndent();
  javaIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl;
}

void javaOutputHandlerCase(Cons* tree) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "try {" << std::endl;
  javaBumpIndent();
  if (javaPrognP(tree->value)) {
    javaOutputStatement(((Cons*)(tree->value))->rest->value);
  }
  else {
    {
      javaIndent();
      javaOutputStatement(tree->value);
      if (javaOutputSemicolonP(((Cons*)(tree->value)))) {
        *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
      }
    }
  }
  javaUnbumpIndent();
  javaIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << "}";
  javaOutputStatements(tree->rest);
  *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
}

void javaOutputSignal(Cons* tree) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "throw ";
  javaOutputStatement(tree);
}

void javaOutputGlobalDefinition(Cons* global) {
  if (((StringWrapper*)(global->value))->wrapperValue != NULL) {
    javaIndent();
    javaOutputJavadocComment(((StringWrapper*)(global->value)), NIL, NULL, NULL, NULL);
  }
  javaIndent();
  javaOutputStatement(global->rest->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(global->rest->rest->value))->wrapperValue;
  if (!(global->rest->rest->rest == NIL)) {
    *(oCURRENT_STREAMo.get()->nativeStream) << " = ";
    javaOutputStatement(global->fourth());
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl << std::endl;
}

void javaOutputActualsAsConsExpression(Cons* arglist) {
  if (arglist == NIL) {
    *(oCURRENT_STREAMo.get()->nativeStream) << javaPrependGlobalClassName("NIL", oSTELLA_MODULEo);
  }
  else {
    {
      *(oCURRENT_STREAMo.get()->nativeStream) << ((StringWrapper*)(oJAVA_STELLA_PACKAGE_MAPPINGo->lookup(wrapString("STELLAROOT")))) << ".Stella_Object.cons(";
      javaOutputStatement(arglist->value);
      *(oCURRENT_STREAMo.get()->nativeStream) << ", ";
      javaOutputActualsAsConsExpression(arglist->rest);
      *(oCURRENT_STREAMo.get()->nativeStream) << ")";
    }
  }
}

void javaOutputFuncall(Cons* funcall) {
  *(oCURRENT_STREAMo.get()->nativeStream) << javaYieldFullNativeClassName() << ".funcall(";
  javaOutputStatement(funcall->rest->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << ", null, new java.lang.Object [] ";
  javaOutputArray(((Cons*)(funcall->rest->rest->value))->rest);
  *(oCURRENT_STREAMo.get()->nativeStream) << ")";
}

void javaOutputMethodCodeCall(Cons* methodcall) {
  *(oCURRENT_STREAMo.get()->nativeStream) << javaYieldFullNativeClassName() << ".funcall(";
  javaOutputStatement(methodcall->rest->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << ", ";
  javaOutputStatement(methodcall->rest->rest->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << ", new java.lang.Object []";
  javaOutputArray(((Cons*)(methodcall->fourth()))->rest);
  *(oCURRENT_STREAMo.get()->nativeStream) << ")";
}

void javaOutputBreak(Cons* tag) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "break ";
  javaOutputStatement(tag);
  *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
}

void javaOutputContinue(Cons* tag) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "continue ";
  javaOutputStatement(tag);
  *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
}

boolean javaStatementReturnsP(Cons* statement) {
  if (!((boolean)(statement))) {
    return (FALSE);
  }
  else if (statement == NIL) {
    return (FALSE);
  }
  else {
    { GeneralizedSymbol* testValue000 = ((GeneralizedSymbol*)(statement->value));

      if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_VERBATIM) {
        return (stringSearch(((StringWrapper*)(statement->rest->value))->wrapperValue, "throw new Error", 0) != NULL_INTEGER);
      }
      else if ((testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_RETURN) ||
          ((testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_CONTINUE) ||
           ((testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_BREAK) ||
            (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_SIGNAL)))) {
        return (TRUE);
      }
      else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_STATEMENTS) {
        return (javaLastStatementReturnsP(statement->rest));
      }
      else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_PROGN) {
        return (javaLastStatementReturnsP(((Cons*)(statement->rest->value))));
      }
      else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_BLOCK) {
        return (javaLastStatementReturnsP(((Cons*)(statement->rest->rest->value))));
      }
      else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_IF) {
        return (javaStatementReturnsP(((Cons*)(statement->rest->rest->value))) &&
            javaStatementReturnsP(((Cons*)(statement->fourth()))));
      }
      else if (testValue000 == SYM_JAVA_OUTPUT_STELLA_JAVA_COND) {
        { boolean testValue001 = FALSE;

          testValue001 = javaStatementReturnsP(((Cons*)(statement->rest->value)));
          if (testValue001) {
            { boolean alwaysP000 = TRUE;

              { Object* c = NULL;
                Cons* iter000 = ((Cons*)(statement->rest->rest->value));

                while (!(iter000 == NIL)) {
                  c = iter000->value;
                  iter000 = iter000->rest;
                  if (!javaLastStatementReturnsP(((Cons*)(c)))) {
                    alwaysP000 = FALSE;
                    break;
                  }
                }
              }
              testValue001 = alwaysP000;
            }
          }
          { boolean value000 = testValue001;

            return (value000);
          }
        }
      }
      else {
        return (FALSE);
      }
    }
  }
}

boolean javaLastStatementReturnsP(Cons* statements) {
  { Object* lastStatement = statements->last();

    return (isaP(lastStatement, SGT_JAVA_OUTPUT_STELLA_CONS) &&
        javaStatementReturnsP(((Cons*)(lastStatement))));
  }
}

void javaOutputCase(Cons* casE) {
  { Object* keyform = casE->value;
    Object* defaultcase = casE->rest->value;
    Object* conditions = casE->rest->rest->value;

    *(oCURRENT_STREAMo.get()->nativeStream) << "switch (";
    javaOutputStatement(keyform);
    *(oCURRENT_STREAMo.get()->nativeStream) << ") {" << std::endl;
    javaBumpIndent();
    { Cons* c = NULL;
      Cons* iter000 = ((Cons*)(conditions));

      while (!(iter000 == NIL)) {
        c = ((Cons*)(iter000->value));
        iter000 = iter000->rest;
        { Cons* condition = c;

          { Object* cond = NULL;
            Cons* iter001 = ((Cons*)((consP(((Cons*)(condition->value))->value) ? condition->value : cons(condition->value, NIL))));

            while (!(iter001 == NIL)) {
              cond = iter001->value;
              iter001 = iter001->rest;
              javaIndent();
              *(oCURRENT_STREAMo.get()->nativeStream) << "case ";
              javaOutputStatement(cond);
              *(oCURRENT_STREAMo.get()->nativeStream) << ": " << std::endl;
            }
          }
          javaBumpIndent();
          javaOutputStatement(condition->rest->value);
          javaUnbumpIndent();
          if (!(javaLastStatementReturnsP(((Cons*)(condition->rest->value))))) {
            javaIndent();
            *(oCURRENT_STREAMo.get()->nativeStream) << "break;" << std::endl;
          }
        }
      }
    }
    if (!((boolean)(defaultcase))) {
      std::cerr << "Safety violation: " << "INTERNAL ERROR: `java-output-case' expects an `otherwise' clause.";
    }
    javaIndent();
    *(oCURRENT_STREAMo.get()->nativeStream) << "default:" << std::endl;
    javaBumpIndent();
    javaOutputStatement(defaultcase);
    javaUnbumpIndent();
    if (!(javaLastStatementReturnsP(((Cons*)(defaultcase))))) {
      javaIndent();
      *(oCURRENT_STREAMo.get()->nativeStream) << "break;" << std::endl;
    }
    javaUnbumpIndent();
    javaIndent();
    *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl;
  }
}

void javaOutputCond(Cons* cond) {
  { Cons* defaultcondition = ((Cons*)(cond->value));
    Cons* conditions = ((Cons*)(cond->rest->value));
    Cons* firstcondition = ((Cons*)(conditions->value));
    Cons* restconditions = conditions->rest;

    if (((boolean)(defaultcondition)) &&
        (conditions == NIL)) {
      *(oCURRENT_STREAMo.get()->nativeStream) << "if (true) ";
      javaOutputStatement(defaultcondition);
      return;
    }
    *(oCURRENT_STREAMo.get()->nativeStream) << "if (";
    javaOutputStatement(firstcondition->value);
    *(oCURRENT_STREAMo.get()->nativeStream) << ") ";
    javaOutputStatement(firstcondition->rest->value);
    { Object* c = NULL;
      Cons* iter000 = restconditions;

      while (!(iter000 == NIL)) {
        c = iter000->value;
        iter000 = iter000->rest;
        { Cons* condition = ((Cons*)(c));

          javaIndent();
          *(oCURRENT_STREAMo.get()->nativeStream) << "else if (";
          javaOutputStatement(condition->value);
          *(oCURRENT_STREAMo.get()->nativeStream) << ") ";
          javaOutputStatement(condition->rest->value);
        }
      }
    }
    if (((boolean)(defaultcondition))) {
      javaIndent();
      *(oCURRENT_STREAMo.get()->nativeStream) << "else ";
      javaOutputStatement(defaultcondition);
    }
  }
}

boolean javaPrognP(Object* tree) {
  return (consP(tree) &&
      (((Cons*)(tree))->value == SYM_JAVA_OUTPUT_STELLA_JAVA_PROGN));
}

boolean javaBlockP(Object* tree) {
  return (consP(tree) &&
      (((Cons*)(tree))->value == SYM_JAVA_OUTPUT_STELLA_JAVA_BLOCK));
}

void javaOutputIf(Cons* tree) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "if (";
  javaOutputStatement(tree->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << ") ";
  if (javaPrognP(tree->rest->value) ||
      javaBlockP(tree->rest->value)) {
    javaOutputStatement(tree->rest->value);
  }
  else {
    {
      *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
      javaBumpIndent();
      javaIndent();
      javaOutputStatement(tree->rest->value);
      *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
      javaUnbumpIndent();
    }
  }
  if (!(!((boolean)(tree->rest->rest->value)))) {
    javaIndent();
    *(oCURRENT_STREAMo.get()->nativeStream) << "else ";
    if (javaPrognP(tree->rest->rest->value) ||
        javaBlockP(tree->rest->rest->value)) {
      javaOutputStatement(tree->rest->rest->value);
    }
    else {
      {
        *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
        javaBumpIndent();
        javaIndent();
        javaOutputStatement(tree->rest->rest->value);
        *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
        javaUnbumpIndent();
      }
    }
  }
}

void javaOutputWhen(Cons* tree) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "if (";
  javaOutputStatement(tree->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << ") {" << std::endl;
  javaBumpIndent();
  javaOutputStatement(tree->rest->value);
  javaUnbumpIndent();
  javaIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl;
}

void javaOutputUnless(Cons* tree) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "if (!(";
  javaOutputStatement(tree->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << ")) {" << std::endl;
  javaBumpIndent();
  javaOutputStatement(tree->rest->value);
  javaUnbumpIndent();
  javaIndent();
  *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl;
}

void javaOutputAssignment(Cons* assignment) {
  javaOutputStatement(assignment->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << " = ";
  javaOutputStatement(assignment->rest->value);
}

void javaOutputLoop(Cons* loop) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "for (;;) ";
  javaOutputStatement(loop->value);
}

void javaOutputWhile(Cons* loop) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "while (";
  javaOutputStatement(loop->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << ") ";
  javaOutputStatement(loop->rest->value);
}

void javaOutputForeach(Cons* loop) {
  { Object* continuationtest = loop->value;
    Object* nextassignments = loop->rest->value;
    Object* body = loop->rest->rest->value;

    *(oCURRENT_STREAMo.get()->nativeStream) << "while (";
    javaOutputStatement(continuationtest);
    *(oCURRENT_STREAMo.get()->nativeStream) << ") {" << std::endl;
    javaBumpIndent();
    javaOutputStatements(((Cons*)(nextassignments)));
    javaOutputStatements(((Cons*)(body)));
    javaUnbumpIndent();
    javaIndent();
    *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl;
  }
}

boolean javaEndOfLineTokenP(Object* token) {
  if (safePrimaryType(token) == SGT_JAVA_OUTPUT_STELLA_CONS) {
    { Object* token000 = token;
      Cons* token = ((Cons*)(token000));

      return (token->value == SYM_JAVA_OUTPUT_STELLA_JAVA_EOL);
    }
  }
  else {
  }
  return (FALSE);
}

void javaOutputPrintStream(Cons* exps, boolean nativestreamP) {
  { Object* stream = exps->value;
    boolean foundeolP = FALSE;
    boolean embeddedeolP = FALSE;
    Cons* printitems = NIL;

    { Object* i = NULL;
      Cons* iter000 = exps->rest;

      while (!(iter000 == NIL)) {
        i = iter000->value;
        iter000 = iter000->rest;
        if (foundeolP) {
          embeddedeolP = TRUE;
          break;
        }
        if (javaEndOfLineTokenP(i)) {
          foundeolP = TRUE;
        }
      }
    }
    if (embeddedeolP) {
      *(oCURRENT_STREAMo.get()->nativeStream) << "{" << std::endl;
      javaBumpIndent();
    }
    { ConsIterator* it = exps->rest->allocateIterator();

      while (it->nextP()) {
        { Object* item = it->value;

          if (javaEndOfLineTokenP(item)) {
            {
              if (embeddedeolP) {
                javaIndent();
              }
              javaHelpOutputPrintStream(stream, javaReverseAndConsolidateStrings(printitems), nativestreamP, TRUE);
              if (embeddedeolP) {
                *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
              }
              printitems = NIL;
            }
          }
          else {
            printitems = cons(item, printitems);
          }
        }
      }
    }
    if (!(printitems == NIL)) {
      if (embeddedeolP) {
        javaIndent();
      }
      javaHelpOutputPrintStream(stream, javaReverseAndConsolidateStrings(printitems), nativestreamP, FALSE);
      if (embeddedeolP) {
        *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
      }
    }
    if (embeddedeolP) {
      javaUnbumpIndent();
      javaIndent();
      *(oCURRENT_STREAMo.get()->nativeStream) << "}" << std::endl;
    }
  }
}

boolean javaLiteralStringP(Cons* item) {
  return ((item->value == SYM_JAVA_OUTPUT_STELLA_JAVA_LITERAL) &&
      isaP(item->rest->value, SGT_JAVA_OUTPUT_STELLA_STRING_WRAPPER));
}

Cons* javaReverseAndConsolidateStrings(Cons* items) {
  if (items == NIL) {
    return (NIL);
  }
  { Cons* outputItems = NIL;
    Cons* lastItem = ((Cons*)(items->value));

    { Cons* newItem = NULL;
      Cons* iter000 = items->rest;

      while (!(iter000 == NIL)) {
        newItem = ((Cons*)(iter000->value));
        iter000 = iter000->rest;
        if (javaLiteralStringP(newItem)) {
          if (javaLiteralStringP(lastItem)) {
            lastItem = listO(3, SYM_JAVA_OUTPUT_STELLA_JAVA_LITERAL, wrapString(stringConcatenate(((StringWrapper*)(newItem->rest->value))->wrapperValue, ((StringWrapper*)(lastItem->rest->value))->wrapperValue, 0)), NIL);
          }
          else {
            {
              outputItems = cons(lastItem, outputItems);
              lastItem = newItem;
            }
          }
        }
        else {
          {
            outputItems = cons(lastItem, outputItems);
            lastItem = newItem;
          }
        }
      }
    }
    outputItems = cons(lastItem, outputItems);
    return (outputItems);
  }
}

void javaHelpOutputPrintStream(Object* stream, Cons* exps, boolean nativestreamP, boolean endoflineP) {
  if (stream == SYM_JAVA_OUTPUT_STELLA_JAVA_STANDARD_OUT) {
    if (((boolean)(stringGetStellaClass("SYSTEM", FALSE))) ||
        inheritedClassNameConflictsP("SYSTEM")) {
      *(oCURRENT_STREAMo.get()->nativeStream) << "java.lang.System.out";
    }
    else {
      *(oCURRENT_STREAMo.get()->nativeStream) << "System.out";
    }
  }
  else if (stream == SYM_JAVA_OUTPUT_STELLA_JAVA_STANDARD_ERROR) {
    if (((boolean)(stringGetStellaClass("SYSTEM", FALSE))) ||
        inheritedClassNameConflictsP("SYSTEM")) {
      *(oCURRENT_STREAMo.get()->nativeStream) << "java.lang.System.err";
    }
    else {
      *(oCURRENT_STREAMo.get()->nativeStream) << "System.err";
    }
  }
  else {
    javaOutputStatement(stream);
    if (!nativestreamP) {
      *(oCURRENT_STREAMo.get()->nativeStream) << ".nativeStream";
    }
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << ((endoflineP ? (char*)".println(" : (char*)".print("));
  javaMaybeOutputStatementWithParentheses(exps->value);
  { Object* e = NULL;
    Cons* iter000 = exps->rest;

    while (!(iter000 == NIL)) {
      e = iter000->value;
      iter000 = iter000->rest;
      *(oCURRENT_STREAMo.get()->nativeStream) << " + ";
      javaMaybeOutputStatementWithParentheses(e);
    }
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << ")";
}

boolean javaIndentableBinaryOperatorP(StringWrapper* operatoR) {
  return (getQuotedTree("((\"||\" \"&&\") \"/STELLA\")", "/STELLA")->memberP(operatoR));
}

boolean javaCommutativeBinaryOperatorP(StringWrapper* operatoR) {
  return (getQuotedTree("((\"+\" \"*\") \"/STELLA\")", "/STELLA")->memberP(operatoR));
}

boolean javaBinaryOperatorP(Object* statement) {
  return (consP(statement) &&
      (SYM_JAVA_OUTPUT_STELLA_JAVA_BINARY_OP == ((Cons*)(statement))->value));
}

boolean javaOperatorP(Object* statement) {
  return (consP(statement) &&
      getQuotedTree("((JAVA_UNARY_OP JAVA_BINARY_OP JAVA_TERNARY_OP JAVA_ASSIGN JAVA_SLOT_VALUE_SETTER) \"/STELLA\")", "/STELLA")->memberP(((Cons*)(statement))->value));
}

void javaOutputUnaryOperator(Cons* expression) {
  { StringWrapper* op = ((StringWrapper*)(expression->value));
    Object* arg = expression->rest->value;

    *(oCURRENT_STREAMo.get()->nativeStream) << op->wrapperValue;
    javaMaybeOutputStatementWithParentheses(arg);
  }
}

boolean javaNestedOperatorNeedsParenthesesP(StringWrapper* op, Object* nested) {
  return (javaOperatorP(nested) &&
      (!(javaCommutativeBinaryOperatorP(op) &&
      stringEqlP(op->wrapperValue, ((StringWrapper*)(((Cons*)(nested))->rest->rest->value))->wrapperValue))));
}

void javaHelpOutputBinaryOperator(Cons* expression, int nestlevel) {
  { Object* arg1 = expression->value;
    StringWrapper* op = ((StringWrapper*)(expression->rest->value));
    Object* arg2 = expression->rest->rest->value;

    if (javaNestedOperatorNeedsParenthesesP(op, arg1)) {
      *(oCURRENT_STREAMo.get()->nativeStream) << "(";
    }
    if (javaBinaryOperatorP(op)) {
      javaHelpOutputBinaryOperator(((Cons*)(arg1))->rest, nestlevel + 1);
    }
    else {
      javaOutputStatement(arg1);
    }
    if (javaNestedOperatorNeedsParenthesesP(op, arg1)) {
      *(oCURRENT_STREAMo.get()->nativeStream) << ")";
    }
    *(oCURRENT_STREAMo.get()->nativeStream) << " ";
    *(oCURRENT_STREAMo.get()->nativeStream) << op->wrapperValue;
    if (javaIndentableBinaryOperatorP(op)) {
      {
        *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
        javaIndent();
        *(oCURRENT_STREAMo.get()->nativeStream) << "    ";
        { int i = NULL_INTEGER;
          int iter000 = 1;
          int upperBound000 = nestlevel;
          boolean unboundedP000 = upperBound000 == NULL_INTEGER;

          while (unboundedP000 ||
              (iter000 <= upperBound000)) {
            i = iter000;
            iter000 = iter000 + 1;
            i = i;
            *(oCURRENT_STREAMo.get()->nativeStream) << " ";
          }
        }
      }
    }
    else {
      *(oCURRENT_STREAMo.get()->nativeStream) << " ";
    }
    if (javaNestedOperatorNeedsParenthesesP(op, arg2)) {
      *(oCURRENT_STREAMo.get()->nativeStream) << "(";
    }
    if (javaBinaryOperatorP(arg2)) {
      javaHelpOutputBinaryOperator(((Cons*)(arg2))->rest, nestlevel + 1);
    }
    else {
      javaOutputStatement(arg2);
    }
    if (javaNestedOperatorNeedsParenthesesP(op, arg2)) {
      *(oCURRENT_STREAMo.get()->nativeStream) << ")";
    }
  }
}

void javaOutputBinaryOperator(Cons* expression) {
  javaHelpOutputBinaryOperator(expression, 0);
}

void javaOutputTernaryOperator(Cons* expression) {
  { Object* arg1 = expression->value;
    StringWrapper* op1 = ((StringWrapper*)(expression->rest->value));
    Object* arg2 = expression->rest->rest->value;
    StringWrapper* op2 = ((StringWrapper*)(expression->fourth()));
    Object* arg3 = expression->fifth();

    *(oCURRENT_STREAMo.get()->nativeStream) << "(";
    javaMaybeOutputStatementWithParentheses(arg1);
    *(oCURRENT_STREAMo.get()->nativeStream) << " ";
    *(oCURRENT_STREAMo.get()->nativeStream) << op1->wrapperValue;
    *(oCURRENT_STREAMo.get()->nativeStream) << " ";
    javaMaybeOutputStatementWithParentheses(arg2);
    *(oCURRENT_STREAMo.get()->nativeStream) << " ";
    *(oCURRENT_STREAMo.get()->nativeStream) << op2->wrapperValue;
    *(oCURRENT_STREAMo.get()->nativeStream) << " ";
    javaMaybeOutputStatementWithParentheses(arg3);
    *(oCURRENT_STREAMo.get()->nativeStream) << ")";
  }
}

void javaOutputMethodCall(Cons* methodcall) {
  javaMaybeOutputStatementWithParentheses(methodcall->rest->rest->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << ".";
  javaOutputStatement(methodcall->rest->value);
  javaOutputStatement(methodcall->fourth());
}

void javaOutputFunctionCall(Cons* functioncall) {
  javaMaybeOutputStatementWithParentheses(functioncall->value);
  *(oCURRENT_STREAMo.get()->nativeStream) << ".";
  javaOutputStatement(functioncall->rest->value);
  javaOutputStatement(functioncall->rest->rest->value);
}

void javaOutputActualParameters(Cons* parameters) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "(";
  if (((boolean)(parameters->value))) {
    javaOutputStatement(parameters->value);
  }
  { Object* parameter = NULL;
    Cons* iter000 = parameters->rest;

    while (!(iter000 == NIL)) {
      parameter = iter000->value;
      iter000 = iter000->rest;
      *(oCURRENT_STREAMo.get()->nativeStream) << ", ";
      javaOutputStatement(parameter);
    }
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << ")";
}

void helpStartupJavaOutput1() {
  {
    SGT_JAVA_OUTPUT_STELLA_CONS = ((Surrogate*)(internRigidSymbolWrtModule("CONS", NULL, 1)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_CLASS = ((Symbol*)(internRigidSymbolWrtModule("JAVA_CLASS", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_EXCEPTION_CLASS = ((Symbol*)(internRigidSymbolWrtModule("JAVA_EXCEPTION_CLASS", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_NAMED_STATEMENT = ((Symbol*)(internRigidSymbolWrtModule("JAVA_NAMED_STATEMENT", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_STATEMENTS = ((Symbol*)(internRigidSymbolWrtModule("JAVA_STATEMENTS", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_IDENT = ((Symbol*)(internRigidSymbolWrtModule("JAVA_IDENT", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_EOL = ((Symbol*)(internRigidSymbolWrtModule("JAVA_EOL", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_LITERAL = ((Symbol*)(internRigidSymbolWrtModule("JAVA_LITERAL", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_COMMENT = ((Symbol*)(internRigidSymbolWrtModule("JAVA_COMMENT", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_SYMBOL = ((Symbol*)(internRigidSymbolWrtModule("JAVA_SYMBOL", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_CATCH = ((Symbol*)(internRigidSymbolWrtModule("JAVA_CATCH", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_THROW = ((Symbol*)(internRigidSymbolWrtModule("JAVA_THROW", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_UNWIND_PROTECT = ((Symbol*)(internRigidSymbolWrtModule("JAVA_UNWIND_PROTECT", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_HANDLER_CASE = ((Symbol*)(internRigidSymbolWrtModule("JAVA_HANDLER_CASE", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_SIGNAL = ((Symbol*)(internRigidSymbolWrtModule("JAVA_SIGNAL", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_VERBATIM = ((Symbol*)(internRigidSymbolWrtModule("JAVA_VERBATIM", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_CAST = ((Symbol*)(internRigidSymbolWrtModule("JAVA_CAST", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_GLOBAL = ((Symbol*)(internRigidSymbolWrtModule("JAVA_GLOBAL", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_TYPE = ((Symbol*)(internRigidSymbolWrtModule("JAVA_TYPE", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_PROGN = ((Symbol*)(internRigidSymbolWrtModule("JAVA_PROGN", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_BLOCK = ((Symbol*)(internRigidSymbolWrtModule("JAVA_BLOCK", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_WITH_PROCESS_LOCK = ((Symbol*)(internRigidSymbolWrtModule("JAVA_WITH_PROCESS_LOCK", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_RETURN = ((Symbol*)(internRigidSymbolWrtModule("JAVA_RETURN", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_MAKE = ((Symbol*)(internRigidSymbolWrtModule("JAVA_MAKE", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCALL = ((Symbol*)(internRigidSymbolWrtModule("JAVA_FUNCALL", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_CODE_CALL = ((Symbol*)(internRigidSymbolWrtModule("JAVA_METHOD_CODE_CALL", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_ASSIGN = ((Symbol*)(internRigidSymbolWrtModule("JAVA_ASSIGN", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_BREAK = ((Symbol*)(internRigidSymbolWrtModule("JAVA_BREAK", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_CONTINUE = ((Symbol*)(internRigidSymbolWrtModule("JAVA_CONTINUE", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_COND = ((Symbol*)(internRigidSymbolWrtModule("JAVA_COND", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_CASE = ((Symbol*)(internRigidSymbolWrtModule("JAVA_CASE", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_IF = ((Symbol*)(internRigidSymbolWrtModule("JAVA_IF", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_WHEN = ((Symbol*)(internRigidSymbolWrtModule("JAVA_WHEN", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_UNLESS = ((Symbol*)(internRigidSymbolWrtModule("JAVA_UNLESS", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_LOOP = ((Symbol*)(internRigidSymbolWrtModule("JAVA_LOOP", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_WHILE = ((Symbol*)(internRigidSymbolWrtModule("JAVA_WHILE", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_FOREACH = ((Symbol*)(internRigidSymbolWrtModule("JAVA_FOREACH", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_SLOT_VALUE = ((Symbol*)(internRigidSymbolWrtModule("JAVA_SLOT_VALUE", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_SLOT_VALUE_SETTER = ((Symbol*)(internRigidSymbolWrtModule("JAVA_SLOT_VALUE_SETTER", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_UNARY_OP = ((Symbol*)(internRigidSymbolWrtModule("JAVA_UNARY_OP", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_BINARY_OP = ((Symbol*)(internRigidSymbolWrtModule("JAVA_BINARY_OP", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_TERNARY_OP = ((Symbol*)(internRigidSymbolWrtModule("JAVA_TERNARY_OP", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCTION_CALL = ((Symbol*)(internRigidSymbolWrtModule("JAVA_FUNCTION_CALL", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_CALL = ((Symbol*)(internRigidSymbolWrtModule("JAVA_METHOD_CALL", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_ACTUALS = ((Symbol*)(internRigidSymbolWrtModule("JAVA_ACTUALS", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_MAKE_ARRAY = ((Symbol*)(internRigidSymbolWrtModule("JAVA_MAKE_ARRAY", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_ARRAY_INITIALIZER = ((Symbol*)(internRigidSymbolWrtModule("JAVA_ARRAY_INITIALIZER", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_ANONYMOUS_ARRAY = ((Symbol*)(internRigidSymbolWrtModule("JAVA_ANONYMOUS_ARRAY", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_AREF = ((Symbol*)(internRigidSymbolWrtModule("JAVA_AREF", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD = ((Symbol*)(internRigidSymbolWrtModule("JAVA_METHOD", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCTION = ((Symbol*)(internRigidSymbolWrtModule("JAVA_FUNCTION", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_PRINT_STREAM = ((Symbol*)(internRigidSymbolWrtModule("JAVA_PRINT_STREAM", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_PRINT_NATIVE_STREAM = ((Symbol*)(internRigidSymbolWrtModule("JAVA_PRINT_NATIVE_STREAM", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_DECLARATIONS = ((Symbol*)(internRigidSymbolWrtModule("JAVA_DECLARATIONS", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCTION_POINTER = ((Symbol*)(internRigidSymbolWrtModule("JAVA_FUNCTION_POINTER", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_POINTER = ((Symbol*)(internRigidSymbolWrtModule("JAVA_METHOD_POINTER", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_SETTER_CALL = ((Symbol*)(internRigidSymbolWrtModule("JAVA_METHOD_SETTER_CALL", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_NEW = ((Symbol*)(internRigidSymbolWrtModule("JAVA_NEW", NULL, 0)));
    KWD_JAVA_OUTPUT_NO = ((Keyword*)(internRigidSymbolWrtModule("NO", NULL, 2)));
    KWD_JAVA_OUTPUT_PRESERVE = ((Keyword*)(internRigidSymbolWrtModule("PRESERVE", NULL, 2)));
  }
}

void helpStartupJavaOutput2() {
  {
    KWD_JAVA_OUTPUT_CLEVER = ((Keyword*)(internRigidSymbolWrtModule("CLEVER", NULL, 2)));
    KWD_JAVA_OUTPUT_UPCASE = ((Keyword*)(internRigidSymbolWrtModule("UPCASE", NULL, 2)));
    KWD_JAVA_OUTPUT_TITLECASEX = ((Keyword*)(internRigidSymbolWrtModule("TITLECASEX", NULL, 2)));
    KWD_JAVA_OUTPUT_WHITE_SPACE = ((Keyword*)(internRigidSymbolWrtModule("WHITE-SPACE", NULL, 2)));
    SGT_JAVA_OUTPUT_STELLA_STRING_WRAPPER = ((Surrogate*)(internRigidSymbolWrtModule("STRING-WRAPPER", NULL, 1)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_STANDARD_OUT = ((Symbol*)(internRigidSymbolWrtModule("JAVA_STANDARD_OUT", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_JAVA_STANDARD_ERROR = ((Symbol*)(internRigidSymbolWrtModule("JAVA_STANDARD_ERROR", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_STARTUP_JAVA_OUTPUT = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-JAVA-OUTPUT", NULL, 0)));
    SYM_JAVA_OUTPUT_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", NULL, 0)));
  }
}

void helpStartupJavaOutput3() {
  {
    defineFunctionObject("JAVA-STELLA-PACKAGE", "(DEFUN (JAVA-STELLA-PACKAGE STRING) ())", ((cpp_function_code)(&javaStellaPackage)), NULL);
    defineFunctionObject("JAVA-OUTPUT-PARSE-TREE", "(DEFUN JAVA-OUTPUT-PARSE-TREE ((CONSTREE CONS)))", ((cpp_function_code)(&javaOutputParseTree)), NULL);
    defineFunctionObject("JAVA-BUMP-INDENT", "(DEFUN JAVA-BUMP-INDENT ())", ((cpp_function_code)(&javaBumpIndent)), NULL);
    defineFunctionObject("JAVA-UNBUMP-INDENT", "(DEFUN JAVA-UNBUMP-INDENT ())", ((cpp_function_code)(&javaUnbumpIndent)), NULL);
    defineFunctionObject("JAVA-INDENT", "(DEFUN JAVA-INDENT ())", ((cpp_function_code)(&javaIndent)), NULL);
    defineFunctionObject("JAVA-OUTPUT-STATEMENT", "(DEFUN JAVA-OUTPUT-STATEMENT ((STATEMENT OBJECT)))", ((cpp_function_code)(&javaOutputStatement)), NULL);
    defineFunctionObject("JAVA-MAYBE-OUTPUT-STATEMENT-WITH-PARENTHESES", "(DEFUN JAVA-MAYBE-OUTPUT-STATEMENT-WITH-PARENTHESES ((STATEMENT OBJECT)))", ((cpp_function_code)(&javaMaybeOutputStatementWithParentheses)), NULL);
    defineFunctionObject("JAVA-OUTPUT-IDENTIFIER", "(DEFUN JAVA-OUTPUT-IDENTIFIER ((IDENTIFIER STRING-WRAPPER)))", ((cpp_function_code)(&javaOutputIdentifier)), NULL);
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((OBJECT OBJECT)))", ((cpp_method_code)(&Object::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((STRING STRING)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((STRING STRING-WRAPPER)))", ((cpp_method_code)(&StringWrapper::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((STRING MUTABLE-STRING-WRAPPER)))", ((cpp_method_code)(&MutableStringWrapper::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((CHARACTER CHARACTER-WRAPPER)))", ((cpp_method_code)(&CharacterWrapper::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((INT INTEGER-WRAPPER)))", ((cpp_method_code)(&IntegerWrapper::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((FLOAT FLOAT-WRAPPER)))", ((cpp_method_code)(&FloatWrapper::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((BOOLEAN BOOLEAN-WRAPPER)))", ((cpp_method_code)(&BooleanWrapper::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineFunctionObject("JAVA-OUTPUT-MAKE-ARRAY", "(DEFUN JAVA-OUTPUT-MAKE-ARRAY ((STATEMENT CONS)))", ((cpp_function_code)(&javaOutputMakeArray)), NULL);
    defineFunctionObject("JAVA-OUTPUT-ARRAY", "(DEFUN JAVA-OUTPUT-ARRAY ((ARRAYELEMENTS CONS)))", ((cpp_function_code)(&javaOutputArray)), NULL);
    defineFunctionObject("JAVA-OUTPUT-ANONYMOUS-ARRAY", "(DEFUN JAVA-OUTPUT-ANONYMOUS-ARRAY ((STATEMENT CONS)))", ((cpp_function_code)(&javaOutputAnonymousArray)), NULL);
    defineFunctionObject("JAVA-OUTPUT-AREF", "(DEFUN JAVA-OUTPUT-AREF ((STATEMENT CONS)))", ((cpp_function_code)(&javaOutputAref)), NULL);
    defineFunctionObject("JAVA-OUTPUT-SLOT-VALUE", "(DEFUN JAVA-OUTPUT-SLOT-VALUE ((STATEMENT CONS)))", ((cpp_function_code)(&javaOutputSlotValue)), NULL);
    defineFunctionObject("JAVA-OUTPUT-SLOT-VALUE-SETTER", "(DEFUN JAVA-OUTPUT-SLOT-VALUE-SETTER ((STATEMENT CONS)))", ((cpp_function_code)(&javaOutputSlotValueSetter)), NULL);
    defineFunctionObject("JAVA-OUTPUT-IMPLEMENTS-INTERFACES", "(DEFUN JAVA-OUTPUT-IMPLEMENTS-INTERFACES ((INTERFACELIST (CONS OF STRING-WRAPPER))))", ((cpp_function_code)(&javaOutputImplementsInterfaces)), NULL);
    defineFunctionObject("JAVA-OUTPUT-CLASS", "(DEFUN JAVA-OUTPUT-CLASS ((CLASSDEF CONS) (EXCEPTIONCLASS? BOOLEAN)))", ((cpp_function_code)(&javaOutputClass)), NULL);
    defineFunctionObject("JAVA-OUTPUT-CLASS-DECLARATION", "(DEFUN JAVA-OUTPUT-CLASS-DECLARATION ((CLASSDEF CONS)))", ((cpp_function_code)(&javaOutputClassDeclaration)), NULL);
    defineFunctionObject("JAVA-OUTPUT-CLASS-VARIABLE-DEFINITIONS", "(DEFUN JAVA-OUTPUT-CLASS-VARIABLE-DEFINITIONS ((VARIABLETRANSLATIONS CONS)))", ((cpp_function_code)(&javaOutputClassVariableDefinitions)), NULL);
    defineFunctionObject("JAVA-OUTPUT-CLASS-CONSTRUCTORS", "(DEFUN JAVA-OUTPUT-CLASS-CONSTRUCTORS ((CONSTRUCTORS (CONS OF TRANSLATION-UNIT)) (CLASSNAME STRING) (EXCEPTIONCLASS? BOOLEAN)))", ((cpp_function_code)(&javaOutputClassConstructors)), NULL);
    defineFunctionObject("JAVA-OUTPUT-CLASS-METHODS", "(DEFUN JAVA-OUTPUT-CLASS-METHODS ((METHODS (CONS OF TRANSLATION-UNIT))))", ((cpp_function_code)(&javaOutputClassMethods)), NULL);
    defineFunctionObject("JAVA-OUTPUT-EXCEPTION-CONSTRUCTOR", "(DEFUN JAVA-OUTPUT-EXCEPTION-CONSTRUCTOR ((EXCEPTIONNAME STRING)))", ((cpp_function_code)(&javaOutputExceptionConstructor)), NULL);
    defineFunctionObject("JAVA-OUTPUT-NAMED-STATEMENT", "(DEFUN JAVA-OUTPUT-NAMED-STATEMENT ((NAMEDSTATEMENT CONS)))", ((cpp_function_code)(&javaOutputNamedStatement)), NULL);
    defineFunctionObject("JAVA-OUTPUT-FORMAL-PARAMETERS", "(DEFUN JAVA-OUTPUT-FORMAL-PARAMETERS ((PARAMETERS (CONS OF CONS))))", ((cpp_function_code)(&javaOutputFormalParameters)), NULL);
    defineFunctionObject("JAVA-OUTPUT-METHOD-SIGNATURE", "(DEFUN JAVA-OUTPUT-METHOD-SIGNATURE ((METHOD CONS)))", ((cpp_function_code)(&javaOutputMethodSignature)), NULL);
    defineFunctionObject("JAVA-SEPARATE-COMMENT-FROM-BODY", "(DEFUN (JAVA-SEPARATE-COMMENT-FROM-BODY CONS CONS) ((BODY CONS)))", ((cpp_function_code)(&javaSeparateCommentFromBody)), NULL);
    defineFunctionObject("JAVA-OUTPUT-METHOD", "(DEFUN JAVA-OUTPUT-METHOD ((METHOD CONS)))", ((cpp_function_code)(&javaOutputMethod)), NULL);
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((CONS CONS)))", ((cpp_method_code)(&Cons::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((TREE QUOTED-EXPRESSION)))", ((cpp_method_code)(&QuotedExpression::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((SYMBOL SYMBOL)))", ((cpp_method_code)(&Symbol::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((SURROGATE SURROGATE)))", ((cpp_method_code)(&Surrogate::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineMethodObject("(DEFMETHOD JAVA-OUTPUT-LITERAL ((KEYWORD KEYWORD)))", ((cpp_method_code)(&Keyword::javaOutputLiteral)), ((cpp_method_code)(NULL)));
    defineFunctionObject("JAVA-OUTPUT-TYPE-EXPRESSION", "(DEFUN JAVA-OUTPUT-TYPE-EXPRESSION ((TYPEEXPRESSION (CONS OF STRING-WRAPPER))))", ((cpp_function_code)(&javaOutputTypeExpression)), NULL);
    defineFunctionObject("JAVA-OUTPUT-SEMICOLON?", "(DEFUN (JAVA-OUTPUT-SEMICOLON? BOOLEAN) ((STATEMENT CONS)))", ((cpp_function_code)(&javaOutputSemicolonP)), NULL);
    defineFunctionObject("JAVA-INDENT-STATEMENT?", "(DEFUN (JAVA-INDENT-STATEMENT? BOOLEAN) ((STATEMENT CONS)))", ((cpp_function_code)(&javaIndentStatementP)), NULL);
    defineFunctionObject("JAVA-ILLEGAL-STATEMENT?", "(DEFUN (JAVA-ILLEGAL-STATEMENT? BOOLEAN) ((STATEMENT CONS)))", ((cpp_function_code)(&javaIllegalStatementP)), NULL);
    defineFunctionObject("JAVA-OUTPUT-STATEMENTS", "(DEFUN JAVA-OUTPUT-STATEMENTS ((STATEMENTLIST CONS)))", ((cpp_function_code)(&javaOutputStatements)), NULL);
    defineFunctionObject("JAVA-OUTPUT-DECLARATIONS", "(DEFUN JAVA-OUTPUT-DECLARATIONS ((DECLARATIONS (CONS OF CONS))))", ((cpp_function_code)(&javaOutputDeclarations)), NULL);
    defineFunctionObject("JAVA-HEURISTICALLY-TRANSLATE-NAME", "(DEFUN (JAVA-HEURISTICALLY-TRANSLATE-NAME STRING) ((STELLA-NAME STRING) (CASE-CONVERTED-NAME-LIST (CONS OF STRING-WRAPPER))))", ((cpp_function_code)(&javaHeuristicallyTranslateName)), NULL);
    defineFunctionObject("JAVA-OUTPUT-COMMENT-STRING", "(DEFUN JAVA-OUTPUT-COMMENT-STRING ((COMMENT STRING) (COMMENT-START STRING) (COMMENT-CONTINUATION STRING) (COMMENT-END STRING) (JAVADOC-COMMENT? BOOLEAN) (CASE-CONVERTED-NAME-LIST (CONS OF STRING-WRAPPER))))", ((cpp_function_code)(&javaOutputCommentString)), NULL);
    defineFunctionObject("JAVA-OUTPUT-COMMENT", "(DEFUN JAVA-OUTPUT-COMMENT ((TREE STRING-WRAPPER)))", ((cpp_function_code)(&javaOutputComment)), NULL);
    defineFunctionObject("JAVA-OUTPUT-JAVADOC-COMMENT", "(DEFUN JAVA-OUTPUT-JAVADOC-COMMENT ((TREE STRING-WRAPPER) (PARAMETER-NAMES-AND-TYPES (CONS OF (CONS OF STRING-WRAPPER))) (RETURN-VALUE STRING-WRAPPER) (AUTHOR STRING) (VERSION STRING)))", ((cpp_function_code)(&javaOutputJavadocComment)), NULL);
    defineFunctionObject("FIXUP-DOCUMENTATION-STRING-QUOTING", "(DEFUN (FIXUP-DOCUMENTATION-STRING-QUOTING STRING) ((DOCUMENTATION STRING)))", ((cpp_function_code)(&fixupDocumentationStringQuoting)), NULL);
    defineFunctionObject("JAVA-OUTPUT-VERBATIM", "(DEFUN JAVA-OUTPUT-VERBATIM ((VERBATIMSTATEMENT STRING-WRAPPER)))", ((cpp_function_code)(&javaOutputVerbatim)), NULL);
    defineFunctionObject("JAVA-OUTPUT-MAKE", "(DEFUN JAVA-OUTPUT-MAKE ((STATEMENT CONS)))", ((cpp_function_code)(&javaOutputMake)), NULL);
    defineFunctionObject("JAVA-OUTPUT-CAST", "(DEFUN JAVA-OUTPUT-CAST ((TREE CONS)))", ((cpp_function_code)(&javaOutputCast)), NULL);
    defineFunctionObject("JAVA-OUTPUT-PROGN", "(DEFUN JAVA-OUTPUT-PROGN ((PROGN CONS)))", ((cpp_function_code)(&javaOutputProgn)), NULL);
    defineFunctionObject("JAVA-OUTPUT-BLOCK", "(DEFUN JAVA-OUTPUT-BLOCK ((BLOCK CONS)))", ((cpp_function_code)(&javaOutputBlock)), NULL);
    defineFunctionObject("JAVA-OUTPUT-WITH-PROCESS-LOCK", "(DEFUN JAVA-OUTPUT-WITH-PROCESS-LOCK ((SYNCH CONS)))", ((cpp_function_code)(&javaOutputWithProcessLock)), NULL);
    defineFunctionObject("JAVA-OUTPUT-RETURN", "(DEFUN JAVA-OUTPUT-RETURN ((RETURNSTATEMENT CONS)))", ((cpp_function_code)(&javaOutputReturn)), NULL);
    defineFunctionObject("JAVA-OUTPUT-THROW", "(DEFUN JAVA-OUTPUT-THROW ((TREE CONS)))", ((cpp_function_code)(&javaOutputThrow)), NULL);
    defineFunctionObject("JAVA-OUTPUT-CATCH", "(DEFUN JAVA-OUTPUT-CATCH ((TREE CONS)))", ((cpp_function_code)(&javaOutputCatch)), NULL);
    defineFunctionObject("JAVA-OUTPUT-UNWIND-PROTECT", "(DEFUN JAVA-OUTPUT-UNWIND-PROTECT ((TREE CONS)))", ((cpp_function_code)(&javaOutputUnwindProtect)), NULL);
  }
}

void startupJavaOutput() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oSTELLA_MODULEo);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupJavaOutput1();
      helpStartupJavaOutput2();
    }
    if (currentStartupTimePhaseP(4)) {
      oJAVA_STELLA_PACKAGE_MAPPINGo = newKeyValueList();
      oJAVA_SEMICOLON_STATEMENTSo = listO(22, SYM_JAVA_OUTPUT_STELLA_JAVA_ASSIGN, SYM_JAVA_OUTPUT_STELLA_JAVA_UNARY_OP, SYM_JAVA_OUTPUT_STELLA_JAVA_BINARY_OP, SYM_JAVA_OUTPUT_STELLA_JAVA_TERNARY_OP, SYM_JAVA_OUTPUT_STELLA_JAVA_CAST, SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCALL, SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCTION_CALL, SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCTION_POINTER, SYM_JAVA_OUTPUT_STELLA_JAVA_MAKE, SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_CALL, SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_CODE_CALL, SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_POINTER, SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_SETTER_CALL, SYM_JAVA_OUTPUT_STELLA_JAVA_NEW, SYM_JAVA_OUTPUT_STELLA_JAVA_PRINT_NATIVE_STREAM, SYM_JAVA_OUTPUT_STELLA_JAVA_PRINT_STREAM, SYM_JAVA_OUTPUT_STELLA_JAVA_RETURN, SYM_JAVA_OUTPUT_STELLA_JAVA_SIGNAL, SYM_JAVA_OUTPUT_STELLA_JAVA_SLOT_VALUE_SETTER, SYM_JAVA_OUTPUT_STELLA_JAVA_THROW, SYM_JAVA_OUTPUT_STELLA_JAVA_VERBATIM, NIL);
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      helpStartupJavaOutput3();
      defineFunctionObject("JAVA-OUTPUT-HANDLER-CASE", "(DEFUN JAVA-OUTPUT-HANDLER-CASE ((TREE CONS)))", ((cpp_function_code)(&javaOutputHandlerCase)), NULL);
      defineFunctionObject("JAVA-OUTPUT-SIGNAL", "(DEFUN JAVA-OUTPUT-SIGNAL ((TREE CONS)))", ((cpp_function_code)(&javaOutputSignal)), NULL);
      defineFunctionObject("JAVA-OUTPUT-GLOBAL-DEFINITION", "(DEFUN JAVA-OUTPUT-GLOBAL-DEFINITION ((GLOBAL CONS)))", ((cpp_function_code)(&javaOutputGlobalDefinition)), NULL);
      defineFunctionObject("JAVA-OUTPUT-ACTUALS-AS-CONS-EXPRESSION", "(DEFUN JAVA-OUTPUT-ACTUALS-AS-CONS-EXPRESSION ((ARGLIST CONS)))", ((cpp_function_code)(&javaOutputActualsAsConsExpression)), NULL);
      defineFunctionObject("JAVA-OUTPUT-FUNCALL", "(DEFUN JAVA-OUTPUT-FUNCALL ((FUNCALL CONS)))", ((cpp_function_code)(&javaOutputFuncall)), NULL);
      defineFunctionObject("JAVA-OUTPUT-METHOD-CODE-CALL", "(DEFUN JAVA-OUTPUT-METHOD-CODE-CALL ((METHODCALL CONS)))", ((cpp_function_code)(&javaOutputMethodCodeCall)), NULL);
      defineFunctionObject("JAVA-OUTPUT-BREAK", "(DEFUN JAVA-OUTPUT-BREAK ((TAG CONS)))", ((cpp_function_code)(&javaOutputBreak)), NULL);
      defineFunctionObject("JAVA-OUTPUT-CONTINUE", "(DEFUN JAVA-OUTPUT-CONTINUE ((TAG CONS)))", ((cpp_function_code)(&javaOutputContinue)), NULL);
      defineFunctionObject("JAVA-STATEMENT-RETURNS?", "(DEFUN (JAVA-STATEMENT-RETURNS? BOOLEAN) ((STATEMENT CONS)))", ((cpp_function_code)(&javaStatementReturnsP)), NULL);
      defineFunctionObject("JAVA-LAST-STATEMENT-RETURNS?", "(DEFUN (JAVA-LAST-STATEMENT-RETURNS? BOOLEAN) ((STATEMENTS CONS)))", ((cpp_function_code)(&javaLastStatementReturnsP)), NULL);
      defineFunctionObject("JAVA-OUTPUT-CASE", "(DEFUN JAVA-OUTPUT-CASE ((CASE CONS)))", ((cpp_function_code)(&javaOutputCase)), NULL);
      defineFunctionObject("JAVA-OUTPUT-COND", "(DEFUN JAVA-OUTPUT-COND ((COND CONS)))", ((cpp_function_code)(&javaOutputCond)), NULL);
      defineFunctionObject("JAVA-PROGN?", "(DEFUN (JAVA-PROGN? BOOLEAN) ((TREE OBJECT)))", ((cpp_function_code)(&javaPrognP)), NULL);
      defineFunctionObject("JAVA-BLOCK?", "(DEFUN (JAVA-BLOCK? BOOLEAN) ((TREE OBJECT)))", ((cpp_function_code)(&javaBlockP)), NULL);
      defineFunctionObject("JAVA-OUTPUT-IF", "(DEFUN JAVA-OUTPUT-IF ((TREE CONS)))", ((cpp_function_code)(&javaOutputIf)), NULL);
      defineFunctionObject("JAVA-OUTPUT-WHEN", "(DEFUN JAVA-OUTPUT-WHEN ((TREE CONS)))", ((cpp_function_code)(&javaOutputWhen)), NULL);
      defineFunctionObject("JAVA-OUTPUT-UNLESS", "(DEFUN JAVA-OUTPUT-UNLESS ((TREE CONS)))", ((cpp_function_code)(&javaOutputUnless)), NULL);
      defineFunctionObject("JAVA-OUTPUT-ASSIGNMENT", "(DEFUN JAVA-OUTPUT-ASSIGNMENT ((ASSIGNMENT CONS)))", ((cpp_function_code)(&javaOutputAssignment)), NULL);
      defineFunctionObject("JAVA-OUTPUT-LOOP", "(DEFUN JAVA-OUTPUT-LOOP ((LOOP CONS)))", ((cpp_function_code)(&javaOutputLoop)), NULL);
      defineFunctionObject("JAVA-OUTPUT-WHILE", "(DEFUN JAVA-OUTPUT-WHILE ((LOOP CONS)))", ((cpp_function_code)(&javaOutputWhile)), NULL);
      defineFunctionObject("JAVA-OUTPUT-FOREACH", "(DEFUN JAVA-OUTPUT-FOREACH ((LOOP CONS)))", ((cpp_function_code)(&javaOutputForeach)), NULL);
      defineFunctionObject("JAVA-END-OF-LINE-TOKEN?", "(DEFUN (JAVA-END-OF-LINE-TOKEN? BOOLEAN) ((TOKEN OBJECT)))", ((cpp_function_code)(&javaEndOfLineTokenP)), NULL);
      defineFunctionObject("JAVA-OUTPUT-PRINT-STREAM", "(DEFUN JAVA-OUTPUT-PRINT-STREAM ((EXPS CONS) (NATIVESTREAM? BOOLEAN)))", ((cpp_function_code)(&javaOutputPrintStream)), NULL);
      defineFunctionObject("JAVA-LITERAL-STRING?", "(DEFUN (JAVA-LITERAL-STRING? BOOLEAN) ((ITEM CONS)))", ((cpp_function_code)(&javaLiteralStringP)), NULL);
      defineFunctionObject("JAVA-REVERSE-AND-CONSOLIDATE-STRINGS", "(DEFUN (JAVA-REVERSE-AND-CONSOLIDATE-STRINGS CONS) ((ITEMS (CONS OF CONS))))", ((cpp_function_code)(&javaReverseAndConsolidateStrings)), NULL);
      defineFunctionObject("JAVA-HELP-OUTPUT-PRINT-STREAM", "(DEFUN JAVA-HELP-OUTPUT-PRINT-STREAM ((STREAM OBJECT) (EXPS CONS) (NATIVESTREAM? BOOLEAN) (ENDOFLINE? BOOLEAN)))", ((cpp_function_code)(&javaHelpOutputPrintStream)), NULL);
      defineFunctionObject("JAVA-INDENTABLE-BINARY-OPERATOR?", "(DEFUN (JAVA-INDENTABLE-BINARY-OPERATOR? BOOLEAN) ((OPERATOR STRING-WRAPPER)))", ((cpp_function_code)(&javaIndentableBinaryOperatorP)), NULL);
      defineFunctionObject("JAVA-COMMUTATIVE-BINARY-OPERATOR?", "(DEFUN (JAVA-COMMUTATIVE-BINARY-OPERATOR? BOOLEAN) ((OPERATOR STRING-WRAPPER)))", ((cpp_function_code)(&javaCommutativeBinaryOperatorP)), NULL);
      defineFunctionObject("JAVA-BINARY-OPERATOR?", "(DEFUN (JAVA-BINARY-OPERATOR? BOOLEAN) ((STATEMENT OBJECT)))", ((cpp_function_code)(&javaBinaryOperatorP)), NULL);
      defineFunctionObject("JAVA-OPERATOR?", "(DEFUN (JAVA-OPERATOR? BOOLEAN) ((STATEMENT OBJECT)))", ((cpp_function_code)(&javaOperatorP)), NULL);
      defineFunctionObject("JAVA-OUTPUT-UNARY-OPERATOR", "(DEFUN JAVA-OUTPUT-UNARY-OPERATOR ((EXPRESSION CONS)))", ((cpp_function_code)(&javaOutputUnaryOperator)), NULL);
      defineFunctionObject("JAVA-NESTED-OPERATOR-NEEDS-PARENTHESES?", "(DEFUN (JAVA-NESTED-OPERATOR-NEEDS-PARENTHESES? BOOLEAN) ((OP STRING-WRAPPER) (NESTED OBJECT)))", ((cpp_function_code)(&javaNestedOperatorNeedsParenthesesP)), NULL);
      defineFunctionObject("JAVA-HELP-OUTPUT-BINARY-OPERATOR", "(DEFUN JAVA-HELP-OUTPUT-BINARY-OPERATOR ((EXPRESSION CONS) (NESTLEVEL INTEGER)))", ((cpp_function_code)(&javaHelpOutputBinaryOperator)), NULL);
      defineFunctionObject("JAVA-OUTPUT-BINARY-OPERATOR", "(DEFUN JAVA-OUTPUT-BINARY-OPERATOR ((EXPRESSION CONS)))", ((cpp_function_code)(&javaOutputBinaryOperator)), NULL);
      defineFunctionObject("JAVA-OUTPUT-TERNARY-OPERATOR", "(DEFUN JAVA-OUTPUT-TERNARY-OPERATOR ((EXPRESSION CONS)))", ((cpp_function_code)(&javaOutputTernaryOperator)), NULL);
      defineFunctionObject("JAVA-OUTPUT-METHOD-CALL", "(DEFUN JAVA-OUTPUT-METHOD-CALL ((METHODCALL CONS)))", ((cpp_function_code)(&javaOutputMethodCall)), NULL);
      defineFunctionObject("JAVA-OUTPUT-FUNCTION-CALL", "(DEFUN JAVA-OUTPUT-FUNCTION-CALL ((FUNCTIONCALL CONS)))", ((cpp_function_code)(&javaOutputFunctionCall)), NULL);
      defineFunctionObject("JAVA-OUTPUT-ACTUAL-PARAMETERS", "(DEFUN JAVA-OUTPUT-ACTUAL-PARAMETERS ((PARAMETERS CONS)))", ((cpp_function_code)(&javaOutputActualParameters)), NULL);
      defineFunctionObject("STARTUP-JAVA-OUTPUT", "(DEFUN STARTUP-JAVA-OUTPUT () :PUBLIC? TRUE)", ((cpp_function_code)(&startupJavaOutput)), NULL);
      { MethodSlot* function = lookupFunction(SYM_JAVA_OUTPUT_STELLA_STARTUP_JAVA_OUTPUT);

        setDynamicSlotValue(function->dynamicSlots, SYM_JAVA_OUTPUT_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Java-Output"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *JAVA-INDENT-CHARS* INTEGER 0)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *JAVA-STELLA-PACKAGE-MAPPING* (KEY-VALUE-LIST OF STRING-WRAPPER STRING-WRAPPER) (NEW (KEY-VALUE-LIST OF STRING-WRAPPER STRING-WRAPPER)))");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *JAVA-SEMICOLON-STATEMENTS* (CONS OF SYMBOL) (BQUOTE (JAVA_ASSIGN JAVA_UNARY_OP JAVA_BINARY_OP JAVA_TERNARY_OP JAVA_CAST JAVA_FUNCALL JAVA_FUNCTION_CALL JAVA_FUNCTION_POINTER JAVA_MAKE JAVA_METHOD_CALL JAVA_METHOD_CODE_CALL JAVA_METHOD_POINTER JAVA_METHOD_SETTER_CALL JAVA_NEW JAVA_PRINT_NATIVE_STREAM JAVA_PRINT_STREAM JAVA_RETURN JAVA_SIGNAL JAVA_SLOT_VALUE_SETTER JAVA_THROW JAVA_VERBATIM)))");
    }
  }
}

Surrogate* SGT_JAVA_OUTPUT_STELLA_CONS = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_CLASS = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_EXCEPTION_CLASS = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_NAMED_STATEMENT = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_STATEMENTS = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_IDENT = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_EOL = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_LITERAL = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_COMMENT = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_SYMBOL = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_CATCH = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_THROW = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_UNWIND_PROTECT = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_HANDLER_CASE = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_SIGNAL = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_VERBATIM = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_CAST = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_GLOBAL = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_TYPE = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_PROGN = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_BLOCK = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_WITH_PROCESS_LOCK = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_RETURN = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_MAKE = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCALL = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_CODE_CALL = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_ASSIGN = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_BREAK = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_CONTINUE = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_COND = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_CASE = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_IF = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_WHEN = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_UNLESS = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_LOOP = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_WHILE = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_FOREACH = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_SLOT_VALUE = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_SLOT_VALUE_SETTER = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_UNARY_OP = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_BINARY_OP = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_TERNARY_OP = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCTION_CALL = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_CALL = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_ACTUALS = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_MAKE_ARRAY = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_ARRAY_INITIALIZER = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_ANONYMOUS_ARRAY = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_AREF = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCTION = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_PRINT_STREAM = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_PRINT_NATIVE_STREAM = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_DECLARATIONS = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_FUNCTION_POINTER = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_POINTER = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_METHOD_SETTER_CALL = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_NEW = NULL;

Keyword* KWD_JAVA_OUTPUT_NO = NULL;

Keyword* KWD_JAVA_OUTPUT_PRESERVE = NULL;

Keyword* KWD_JAVA_OUTPUT_CLEVER = NULL;

Keyword* KWD_JAVA_OUTPUT_UPCASE = NULL;

Keyword* KWD_JAVA_OUTPUT_TITLECASEX = NULL;

Keyword* KWD_JAVA_OUTPUT_WHITE_SPACE = NULL;

Surrogate* SGT_JAVA_OUTPUT_STELLA_STRING_WRAPPER = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_STANDARD_OUT = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_JAVA_STANDARD_ERROR = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_STARTUP_JAVA_OUTPUT = NULL;

Symbol* SYM_JAVA_OUTPUT_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace stella
