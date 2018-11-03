//  -*- Mode: C++ -*-

// cpp-translate-file.cc

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

DEFINE_STELLA_SPECIAL(oCURRENT_STREAMo, OutputStream* , NULL);

char* oCPP_TRANSLATED_FILE_SUFFIXo = "";

void cpptrans(Object* statement) {
  // Translate `statement' to C++ and print the result.
  { 
    BIND_STELLA_SPECIAL(oTRANSLATOROUTPUTLANGUAGEo, Keyword*, oTRANSLATOROUTPUTLANGUAGEo.get());
    BIND_STELLA_SPECIAL(oCURRENT_STREAMo, OutputStream*, STANDARD_OUTPUT);
    setTranslatorOutputLanguage(KWD_CPP_TRANSLATE_FILE_CPP);
    incrementallyTranslate(statement);
  }
}

char* cppMakeCodeOutputFileName(char* filename) {
  return (makeFileName(filename, KWD_CPP_TRANSLATE_FILE_CPP_CODE, FALSE));
}

char* cppMakeHeaderOutputFileName(char* filename) {
  return (makeFileName(filename, KWD_CPP_TRANSLATE_FILE_CPP_HEADER, FALSE));
}

void cppOutputFileHeader(OutputStream* stream, char* file) {
  *(stream->nativeStream) << "//  -*- Mode: C++ -*-" << std::endl << std::endl;
  if (file != NULL) {
    *(stream->nativeStream) << "// " << fileNameWithoutDirectory(file) << std::endl << std::endl;
  }
  outputCopyrightHeader(stream);
}

void cppOutputIncludeDirective(char* filename, boolean stripdirectoryP) {
  if (stripdirectoryP) {
    filename = fileNameWithoutDirectory(filename);
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << "#include \"" << filename << "\"" << std::endl;
}

void cppStandaloneOutputImportDeclarations(char* headerfilename) {
  cppOutputIncludeDirective(makeFileName("cpp-standalone", KWD_CPP_TRANSLATE_FILE_CPP_HEADER, TRUE), TRUE);
  cppOutputIncludeDirective(headerfilename, TRUE);
  *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
}

char* cppRelativizeHeaderFile(char* headerfile, char* systemname) {
  if (systemname == NULL) {
    systemname = oCURRENTSYSTEMDEFINITIONo.get()->name;
  }
  { 
    BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition*, getSystemDefinition(systemname));
    BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char*, (((boolean)(oCURRENTSYSTEMDEFINITIONo.get())) ? oCURRENTSYSTEMDEFINITIONo.get()->directory : NULL));
    if (((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
      {
        { char* directoryfile = makeFileName("dummy", KWD_CPP_TRANSLATE_FILE_CPP_HEADER, TRUE);

          headerfile = relativizeFileName(headerfile, directoryParentDirectory(directoryfile, 2));
        }
      }
    }
    else {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't find a system named " << "`" << systemname << "'" << std::endl << std::endl;
    }
  }
  return (headerfile);
}

void cppOutputImportDeclarations(char* systemname) {
  if (systemname == NULL) {
    if (!((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
      return;
    }
    systemname = oCURRENTSYSTEMDEFINITIONo.get()->name;
  }
  { 
    BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition*, getSystemDefinition(systemname));
    BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char*, (((boolean)(oCURRENTSYSTEMDEFINITIONo.get())) ? oCURRENTSYSTEMDEFINITIONo.get()->directory : NULL));
    if (((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
      {
        cppOutputIncludeDirective(cppRelativizeHeaderFile(makeFileName(cppYieldSystemHeaderFileName(systemname), KWD_CPP_TRANSLATE_FILE_CPP_HEADER, TRUE), systemname), FALSE);
        *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
      }
    }
    else {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't find a system named " << "`" << systemname << "'" << std::endl << std::endl;
    }
  }
}

void cppOutputClassHeadDeclarations(Cons* classes) {
  if (!(classes == NIL)) {
    *(oCURRENT_STREAMo.get()->nativeStream) << "// Class headers:" << std::endl;
  }
  { Object* clasS = NULL;
    Cons* iter000 = classes;

    while (!(iter000 == NIL)) {
      clasS = iter000->value;
      iter000 = iter000->rest;
      *(oCURRENT_STREAMo.get()->nativeStream) << "class " << ((StringWrapper*)(((Cons*)(clasS))->rest->value))->wrapperValue << ";" << std::endl;
    }
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
}

void cppOutputNamespaceHeader(Module* module) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "namespace " << cppYieldNamespacePrefixFromModule(module) << " {" << std::endl;
  { Module* usee = NULL;
    Cons* iter000 = visibleModules(module)->consify()->rest->reverse();

    while (!(iter000 == NIL)) {
      usee = ((Module*)(iter000->value));
      iter000 = iter000->rest;
      *(oCURRENT_STREAMo.get()->nativeStream) << "  using namespace " << cppYieldNamespacePrefixFromModule(usee) << ";" << std::endl;
    }
  }
  *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
}

void cppOutputNamespaceFooter(Module* module) {
  *(oCURRENT_STREAMo.get()->nativeStream) << "} // end of namespace " << cppYieldNamespacePrefixFromModule(module) << std::endl;
}

boolean cppUnitDefinesMainP(TranslationUnit* unit) {
  return ((unit->category == SYM_CPP_TRANSLATE_FILE_STELLA_METHOD) &&
      (((MethodSlot*)(unit->theObject))->slotName == SYM_CPP_TRANSLATE_FILE_STELLA_MAIN));
}

char* cppYieldMainFileName() {
  return (makeFileName("main", KWD_CPP_TRANSLATE_FILE_CPP_CODE, TRUE));
}

void cppOutputMain(TranslationUnit* unit) {
  { 
    BIND_STELLA_SPECIAL(oCURRENT_STREAMo, OutputStream*, newOutputFileStream(cppYieldMainFileName()));
    if (((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
      *(oCURRENT_STREAMo.get()->nativeStream) << "// main entry point for " << oCURRENTSYSTEMDEFINITIONo.get()->name << " system" << std::endl << std::endl;
    }
    cppOutputImportDeclarations(NULL);
    { Module* usee = NULL;
      Cons* iter000 = visibleModules(oMODULEo.get())->consify()->reverse();

      while (!(iter000 == NIL)) {
        usee = ((Module*)(iter000->value));
        iter000 = iter000->rest;
        *(oCURRENT_STREAMo.get()->nativeStream) << "using namespace " << cppYieldNamespacePrefixFromModule(usee) << ";" << std::endl;
      }
    }
    *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
    cppOutputStatement(unit->translation);
    oCURRENT_STREAMo.get()->free();
  }
}

List* cppSortUnitsForHeaderFile(List* fileunits) {
  { Cons* globals = NIL;
    Cons* auxiliaryglobals = NIL;
    Cons* methods = NIL;
    Cons* includestatements = NIL;
    Cons* classes = NIL;
    Cons* main = NIL;

    { TranslationUnit* unit = NULL;
      Cons* iter000 = fileunits->theConsList;

      while (!(iter000 == NIL)) {
        unit = ((TranslationUnit*)(iter000->value));
        iter000 = iter000->rest;
        { Symbol* testValue000 = unit->category;

          if ((testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_METHOD) ||
              ((testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_PRINT_METHOD) ||
               (testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_MACRO))) {
            if (cppUnitDefinesMainP(unit)) {
              main = cons(unit, main);
            }
            else {
              methods = cons(unit, methods);
            }
          }
          else if (testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_VERBATIM) {
            { Cons* translation = ((Cons*)(unit->translation));
              char* code = ((StringWrapper*)(translation->rest->value))->wrapperValue;

              if ((code[0] == '#') &&
                  (!(oCHARACTER_TYPE_TABLEo[(int)(unsigned char) (code[1])] == KWD_CPP_TRANSLATE_FILE_WHITE_SPACE))) {
                { TranslationUnit* self000 = newTranslationUnit();

                  self000->category = SYM_CPP_TRANSLATE_FILE_STELLA_VERBATIM;
                  self000->translation = copyConsTree(unit->translation);
                  includestatements = cons(self000, includestatements);
                }
                translation->secondSetter(wrapString(""));
              }
            }
          }
          else if (testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_CLASS) {
            classes = cons(unit, classes);
          }
          else if (testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_GLOBAL_VARIABLE) {
            if (auxiliaryVariableUnitP(unit)) {
              auxiliaryglobals = cons(unit, auxiliaryglobals);
              unit->category = SYM_CPP_TRANSLATE_FILE_STELLA_AUXILIARY_VARIABLE;
            }
            else {
              globals = cons(unit, globals);
            }
          }
          else if (testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_TYPE) {
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
    return (list(6, includestatements->reverse(), classes->reverse(), globals->reverse(), methods->reverse(), auxiliaryglobals->reverse(), main));
  }
}

void cppOutputNamespaceChange(Module* fromnamespace, Module* tonamespace) {
  if (!((tonamespace == fromnamespace) ||
      (((boolean)(fromnamespace)) &&
       stringEqlP(cppYieldNamespacePrefixFromModule(fromnamespace), cppYieldNamespacePrefixFromModule(tonamespace))))) {
    if (!(!((boolean)(fromnamespace)))) {
      *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
      cppOutputNamespaceFooter(fromnamespace);
      *(oCURRENT_STREAMo.get()->nativeStream) << std::endl << std::endl;
    }
    cppOutputNamespaceHeader(tonamespace);
  }
}

void cppOutputAllUnitsToFile(char* filename) {
  { char* codeoutputfile = makeFileName(filename, KWD_CPP_TRANSLATE_FILE_CPP_CODE, FALSE);
    char* headeroutputfile = makeFileName(filename, KWD_CPP_TRANSLATE_FILE_CPP_HEADER, FALSE);
    OutputFileStream* codeoutputstream = newOutputFileStream(codeoutputfile);
    OutputFileStream* headeroutputstream = newOutputFileStream(headeroutputfile);
    List* headerunits = cppSortUnitsForHeaderFile(oTRANSLATIONUNITSo.get());
    Cons* auxiliaryglobals = ((Cons*)(headerunits->fifth()));
    TranslationUnit* main = ((TranslationUnit*)(((Cons*)(headerunits->nth(5)))->value));
    Module* currentnamespacemodule = NULL;
    Module* currentunitmodule = NULL;

    { 
      BIND_STELLA_SPECIAL(oCURRENT_STREAMo, OutputStream*, headeroutputstream);
      std::cout << "Writing " << "`" << headeroutputfile << "'" << "..." << std::endl;
      cppOutputFileHeader(headeroutputstream, headeroutputfile);
      { Cons* bucket = NULL;
        Cons* iter000 = headerunits->theConsList;

        while (!(iter000 == NIL)) {
          bucket = ((Cons*)(iter000->value));
          iter000 = iter000->rest;
          { TranslationUnit* unit = NULL;
            int i = NULL_INTEGER;
            Cons* iter001 = bucket;
            int iter002 = 1;

            while (!(iter001 == NIL)) {
              unit = ((TranslationUnit*)(iter001->value));
              iter001 = iter001->rest;
              i = iter002;
              iter002 = iter002 + 1;
              if (((boolean)(unit->theObject)) &&
                  (!(unit->category == SYM_CPP_TRANSLATE_FILE_STELLA_VERBATIM))) {
                currentunitmodule = unit->theObject->homeModule();
                cppOutputNamespaceChange(currentnamespacemodule, currentunitmodule);
                currentnamespacemodule = currentunitmodule;
              }
              { Symbol* testValue000 = unit->category;

                if (testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_VERBATIM) {
                  if (i == 1) {
                    *(oCURRENT_STREAMo.get()->nativeStream) << "// Header files and macros:" << std::endl;
                  }
                  cppOutputStatement(unit->translation);
                  *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
                }
                else if (testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_CLASS) {
                  if (i == 1) {
                    *(oCURRENT_STREAMo.get()->nativeStream) << "// Class definitions:" << std::endl;
                  }
                  cppOutputClass(((Cons*)(unit->translation))->rest);
                }
                else if (testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_GLOBAL_VARIABLE) {
                  if (i == 1) {
                    *(oCURRENT_STREAMo.get()->nativeStream) << "// Global declarations:" << std::endl;
                  }
                  cppOutputGlobalDeclaration(((Cons*)(unit->translation)));
                }
                else if ((testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_METHOD) ||
                    ((testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_PRINT_METHOD) ||
                     (testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_MACRO))) {
                  if (i == 1) {
                    *(oCURRENT_STREAMo.get()->nativeStream) << "// Function signatures:" << std::endl;
                  }
                  { Cons* translation = ((Cons*)(unit->translation));

                    { GeneralizedSymbol* testValue001 = ((GeneralizedSymbol*)(translation->value));

                      if (testValue001 == SYM_CPP_TRANSLATE_FILE_STELLA_CPP_FUNCTION) {
                        cppOutputFunctionSignature(translation->rest);
                        *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
                      }
                      else if (testValue001 == SYM_CPP_TRANSLATE_FILE_STELLA_CPP_DEFPRINT) {
                        cppOutputDefprintSignature(translation->rest);
                        *(oCURRENT_STREAMo.get()->nativeStream) << ";" << std::endl;
                      }
                      else {
                      }
                    }
                  }
                }
                else if (testValue000 == SYM_CPP_TRANSLATE_FILE_STELLA_AUXILIARY_VARIABLE) {
                  if (i == 1) {
                    *(oCURRENT_STREAMo.get()->nativeStream) << "// Auxiliary global declarations:" << std::endl;
                  }
                  cppOutputGlobalDeclaration(((Cons*)(unit->translation)));
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
          *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
        }
      }
      cppOutputNamespaceFooter(currentnamespacemodule);
      std::cout << "Writing " << "`" << codeoutputfile << "'" << "..." << std::endl;
      oCURRENT_STREAMo.set(codeoutputstream);
      cppOutputFileHeader(codeoutputstream, codeoutputfile);
      if (oTRANSLATOROUTPUTLANGUAGEo.get() == KWD_CPP_TRANSLATE_FILE_CPP) {
        cppOutputImportDeclarations(NULL);
      }
      else if (oTRANSLATOROUTPUTLANGUAGEo.get() == KWD_CPP_TRANSLATE_FILE_CPP_STANDALONE) {
        cppStandaloneOutputImportDeclarations(headeroutputfile);
      }
      else {
        { OutputStringStream* stream001 = newOutputStringStream();

          *(stream001->nativeStream) << "`" << oTRANSLATOROUTPUTLANGUAGEo.get() << "'" << " is not a valid case option";
          throw *newStellaException(stream001->theStringReader());
        }
      }
      currentnamespacemodule = NULL;
      { TranslationUnit* unit = NULL;
        Cons* iter003 = oTRANSLATIONUNITSo.get()->theConsList;

        while (!(iter003 == NIL)) {
          unit = ((TranslationUnit*)(iter003->value));
          iter003 = iter003->rest;
          if (((boolean)(unit->theObject)) &&
              ((!(unit->category == SYM_CPP_TRANSLATE_FILE_STELLA_VERBATIM)) &&
               (!(unit->category == SYM_CPP_TRANSLATE_FILE_STELLA_AUXILIARY_VARIABLE)))) {
            currentunitmodule = unit->theObject->homeModule();
            cppOutputNamespaceChange(currentnamespacemodule, currentunitmodule);
            currentnamespacemodule = currentunitmodule;
          }
          { Symbol* testValue002 = unit->category;

            if ((testValue002 == SYM_CPP_TRANSLATE_FILE_STELLA_METHOD) ||
                ((testValue002 == SYM_CPP_TRANSLATE_FILE_STELLA_PRINT_METHOD) ||
                 (testValue002 == SYM_CPP_TRANSLATE_FILE_STELLA_MACRO))) {
              if (unit == main) {
                cppOutputStatement(copyConsTree(unit->translation));
              }
              else {
                cppOutputStatement(unit->translation);
              }
            }
            else if (testValue002 == SYM_CPP_TRANSLATE_FILE_STELLA_VERBATIM) {
              cppOutputVerbatim(((StringWrapper*)(((Cons*)(unit->translation))->rest->value)));
            }
            else if (testValue002 == SYM_CPP_TRANSLATE_FILE_STELLA_GLOBAL_VARIABLE) {
              if (!(auxiliaryVariableUnitP(unit))) {
                cppOutputVariableDefinition(((Cons*)(unit->translation)));
              }
            }
            else {
            }
          }
        }
      }
      { TranslationUnit* unit = NULL;
        Cons* iter004 = auxiliaryglobals;

        while (!(iter004 == NIL)) {
          unit = ((TranslationUnit*)(iter004->value));
          iter004 = iter004->rest;
          currentunitmodule = unit->theObject->homeModule();
          cppOutputNamespaceChange(currentnamespacemodule, currentunitmodule);
          currentnamespacemodule = currentunitmodule;
          cppOutputVariableDefinition(((Cons*)(unit->translation)));
        }
      }
      cppOutputNamespaceFooter(currentnamespacemodule);
      if (((boolean)(main))) {
        *(oCURRENT_STREAMo.get()->nativeStream) << std::endl << std::endl;
        cppOutputMain(main);
      }
      codeoutputstream->free();
      headeroutputstream->free();
    }
  }
}

void cppTranslateFile(char* filename) {
  translateFile(filename, KWD_CPP_TRANSLATE_FILE_CPP, FALSE);
}

void cppStandaloneTranslateFile(char* filename) {
  translateFile(filename, KWD_CPP_TRANSLATE_FILE_CPP_STANDALONE, FALSE);
}

void cppTranslateSystem(char* systemname) {
  // Translate the system `systemName' to C++.
  translateSystem(systemname, KWD_CPP_TRANSLATE_FILE_CPP, 6, KWD_CPP_TRANSLATE_FILE_TWO_PASSp, TRUE_WRAPPER, KWD_CPP_TRANSLATE_FILE_FORCE_TRANSLATIONp, TRUE_WRAPPER, KWD_CPP_TRANSLATE_FILE_PRODUCTION_SETTINGSp, TRUE_WRAPPER);
}

void cppTranslateWalkedSystemUnits(KeyValueList* systemunits) {
  { 
    BIND_STELLA_SPECIAL(oCURRENTFILEo, char*, NULL);
    BIND_STELLA_SPECIAL(oTRANSLATIONUNITSo, List*, NULL);
    { StringWrapper* file = NULL;
      List* units = NULL;
      KvCons* iter000 = systemunits->theKvList;

      while (((boolean)(iter000))) {
        file = ((StringWrapper*)(iter000->key));
        units = ((List*)(iter000->value));
        iter000 = iter000->rest;
        oCURRENTFILEo.set(fileBaseName(file->wrapperValue));
        oTRANSLATIONUNITSo.set(units);
        { 
          BIND_STELLA_SPECIAL(oMODULEo, Module*, computeFileUnitsModule(units));
          BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
          translateAndOutputUnitsToFile(file->wrapperValue, "C++");
        }
        cleanUpTranslationUnitsSpecial();
      }
    }
    cppOutputSystemSpecificFiles();
  }
}

void cppOutputSystemSpecificFiles() {
  cppOutputSystemHeaderFile();
  cppOutputSystemMakefile();
}

char* cppYieldSystemHeaderFileName(char* systemname) {
  return (stringConcatenate(stringDowncase(systemname), "-system", 0));
}

char* cppYieldSystemHeaderFileGuard(char* systemname) {
  return (stringConcatenate("_STELLA_", stringUpcase(systemname), 1, "_SYSTEM_HH"));
}

void cppOutputSystemHeaderFile() {
  { SystemDefinition* system = oCURRENTSYSTEMDEFINITIONo.get();
    char* systemname = system->name;
    char* headeroutputfile = makeFileName(cppYieldSystemHeaderFileName(systemname), KWD_CPP_TRANSLATE_FILE_CPP_HEADER, TRUE);
    OutputFileStream* headeroutputstream = newOutputFileStream(headeroutputfile);

    { 
      BIND_STELLA_SPECIAL(oCURRENT_STREAMo, OutputStream*, headeroutputstream);
      BIND_STELLA_SPECIAL(oMODULEo, Module*, getCardinalModule(oCURRENTSYSTEMDEFINITIONo.get()));
      BIND_STELLA_SPECIAL(oCPP_CURRENT_UNIT_MODULEo, Module*, NULL);
      *(oCURRENT_STREAMo.get()->nativeStream) << "// " << fileNameWithoutDirectory(headeroutputfile) << std::endl << std::endl;
      *(oCURRENT_STREAMo.get()->nativeStream) << "#ifndef " << cppYieldSystemHeaderFileGuard(systemname) << std::endl << "#define " << cppYieldSystemHeaderFileGuard(systemname) << std::endl << std::endl;
      if (((boolean)(system->requiredSystems))) {
        *(oCURRENT_STREAMo.get()->nativeStream) << "// Required systems:" << std::endl;
        { StringWrapper* reqsys = NULL;
          Cons* iter000 = system->requiredSystems;

          while (!(iter000 == NIL)) {
            reqsys = ((StringWrapper*)(iter000->value));
            iter000 = iter000->rest;
            cppOutputImportDeclarations(reqsys->wrapperValue);
          }
        }
      }
      *(oCURRENT_STREAMo.get()->nativeStream) << "// System-wide forward declarations:" << std::endl;
      { Module* currentnamespacemodule = NULL;

        { Class* clasS = NULL;
          Iterator* iter001 = allClasses(oMODULEo.get(), TRUE);

          while (iter001->nextP()) {
            clasS = ((Class*)(iter001->value));
            if (createNativeClassP(clasS)) {
              oCPP_CURRENT_UNIT_MODULEo.set(clasS->homeModule());
              cppOutputNamespaceChange(currentnamespacemodule, oCPP_CURRENT_UNIT_MODULEo.get());
              currentnamespacemodule = oCPP_CURRENT_UNIT_MODULEo.get();
              *(oCURRENT_STREAMo.get()->nativeStream) << "class " << cppTranslateClassName(clasS->classType)->wrapperValue << ";" << std::endl;
            }
          }
        }
        *(oCURRENT_STREAMo.get()->nativeStream) << std::endl;
        if (((boolean)(currentnamespacemodule))) {
          cppOutputNamespaceFooter(oCPP_CURRENT_UNIT_MODULEo.get());
        }
        *(oCURRENT_STREAMo.get()->nativeStream) << std::endl << std::endl;
      }
      *(oCURRENT_STREAMo.get()->nativeStream) << "// System components:" << std::endl;
      if (stringEqlP(systemname, "stella")) {
        cppOutputIncludeDirective(cppRelativizeHeaderFile(makeFileNameFromRelativePath(listO(3, wrapString("cpp-lib"), wrapString("cpp-primal"), NIL), KWD_CPP_TRANSLATE_FILE_CPP_HEADER), systemname), FALSE);
      }
      { StringWrapper* file = NULL;
        Cons* iter002 = filesPlusSystemStartup(systemDefinitionSourceFiles(system));

        while (!(iter002 == NIL)) {
          file = ((StringWrapper*)(iter002->value));
          iter002 = iter002->rest;
          cppOutputIncludeDirective(cppRelativizeHeaderFile(makeFileName(file->wrapperValue, KWD_CPP_TRANSLATE_FILE_CPP_HEADER, TRUE), systemname), FALSE);
        }
      }
      *(oCURRENT_STREAMo.get()->nativeStream) << std::endl << "#endif" << std::endl;
      headeroutputstream->free();
    }
  }
}

char* cppYieldSystemsRootDirectory() {
  { 
    BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition*, getSystemDefinition("STELLA"));
    BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char*, (((boolean)(oCURRENTSYSTEMDEFINITIONo.get())) ? oCURRENTSYSTEMDEFINITIONo.get()->directory : NULL));
    if (((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
      {
        return ("..");
      }
    }
    else {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't find a system named " << "STELLA" << std::endl << std::endl;
    }
  }
  return (NULL);
}

char* cppYieldStellaRootDirectory() {
  { 
    BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition*, getSystemDefinition("STELLA"));
    BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char*, (((boolean)(oCURRENTSYSTEMDEFINITIONo.get())) ? oCURRENTSYSTEMDEFINITIONo.get()->directory : NULL));
    if (((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
      {
        return (stringConcatenate(cppYieldSystemsRootDirectory(), "/", 1, fileBaseName(directoryFileName(directoryParentDirectory(makeFileName("dummy", KWD_CPP_TRANSLATE_FILE_CPP_CODE, TRUE), 1)))));
      }
    }
    else {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't find a system named " << "STELLA" << std::endl << std::endl;
    }
  }
  return (NULL);
}

void cppOutputSystemMakefile() {
  { char* makefile = makeFileName("Makefile", KWD_CPP_TRANSLATE_FILE_STELLA, TRUE);
    char* templatefile = stringConcatenate(fileNameWithoutExtension(makefile), ".in", 0);
    SystemDefinition* system = oCURRENTSYSTEMDEFINITIONo.get();

    if (!(probeFileP(templatefile))) {
      { 
        BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition*, getSystemDefinition("STELLA"));
        BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char*, (((boolean)(oCURRENTSYSTEMDEFINITIONo.get())) ? oCURRENTSYSTEMDEFINITIONo.get()->directory : NULL));
        if (((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
          {
            makefile = makeFileName("Makefile-default", KWD_CPP_TRANSLATE_FILE_STELLA, TRUE);
            templatefile = stringConcatenate(fileNameWithoutExtension(makefile), ".in", 0);
          }
        }
        else {
          *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't find a system named " << "STELLA" << std::endl << std::endl;
        }
      }
    }
    { KeyValueList* variables = newKeyValueList();
      OutputStringStream* systemfiles = newOutputStringStream();
      OutputStringStream* requiredsystems = newOutputStringStream();

      variables->insertAt(wrapString("SYSTEM-NAME"), wrapString(system->name));
      variables->insertAt(wrapString("PROGRAM-NAME"), wrapString(system->name));
      variables->insertAt(wrapString("MAIN-NAME"), wrapString(fileNameWithoutDirectory(cppYieldMainFileName())));
      variables->insertAt(wrapString("SYSTEMS-ROOT"), wrapString(cppYieldSystemsRootDirectory()));
      variables->insertAt(wrapString("STELLA-ROOT"), wrapString(cppYieldStellaRootDirectory()));
      { StringWrapper* file = NULL;
        Cons* iter000 = filesPlusSystemStartup(systemDefinitionSourceFiles(system));

        while (!(iter000 == NIL)) {
          file = ((StringWrapper*)(iter000->value));
          iter000 = iter000->rest;
          *(systemfiles->nativeStream) << fileNameWithoutDirectory(makeFileName(file->wrapperValue, KWD_CPP_TRANSLATE_FILE_CPP_CODE, TRUE)) << " ";
        }
      }
      variables->insertAt(wrapString("SYSTEM-FILES"), wrapString(systemfiles->theStringReader()));
      if (((boolean)(system->requiredSystems))) {
        { StringWrapper* reqsys = NULL;
          Cons* iter001 = system->requiredSystems;

          while (!(iter001 == NIL)) {
            reqsys = ((StringWrapper*)(iter001->value));
            iter001 = iter001->rest;
            *(requiredsystems->nativeStream) << reqsys->wrapperValue << " ";
          }
        }
      }
      variables->insertAt(wrapString("REQUIRED-SYSTEMS"), wrapString(requiredsystems->theStringReader()));
      makefile = fileNameWithoutExtension(makeFileName("Makefile", KWD_CPP_TRANSLATE_FILE_CPP_CODE, TRUE));
      substituteTemplateVariablesToMakefile(templatefile, makefile, variables);
    }
  }
}

char* oMAKEFILE_TEMPLATE_VARIABLE_PREFIXo = "#$";

char* substituteTemplateVariablesInString(char* string, KeyValueList* variables) {
  { int index = 0;
    int length = strlen(string);
    char* result = string;
    int variableend = 0;
    char* variablename = NULL;
    StringWrapper* variablevalue = NULL;

    for (;;) {
      index = stringSearch(result, oMAKEFILE_TEMPLATE_VARIABLE_PREFIXo, index);
      if (index == NULL_INTEGER) {
        break;
      }
      index = index + 2;
      if (index >= length) {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal template variable syntax in" << std::endl << "    " << "`" << string << "'" << std::endl;
        break;
      }
      if (!(result[index] == '(')) {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal template variable syntax in" << std::endl << "    " << "`" << string << "'" << std::endl;
        continue;
      }
      variableend = stringPosition(result, ')', index);
      if (variableend == NULL_INTEGER) {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal template variable syntax in" << std::endl << "    " << "`" << string << "'" << std::endl;
        continue;
      }
      index = index + 1;
      variablename = stringSubsequence(result, index, variableend);
      variablevalue = ((StringWrapper*)(variables->lookup(wrapString(variablename))));
      if (!((boolean)(variablevalue))) {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Undefined template variable: " << "`" << variablename << "'" << std::endl;
        continue;
      }
      result = stringConcatenate(stringSubsequence(result, 0, index - 3), variablevalue->wrapperValue, 1, stringSubsequence(result, variableend + 1, NULL_INTEGER));
      index = variableend + 1 + (strlen(result) - length);
      length = strlen(result);
    }
    return (result);
  }
}

void substituteTemplateVariablesToStream(InputStream* templatestream, OutputStream* outputstream, KeyValueList* variables) {
  { char* line = NULL;
    LineIterator* iter000 = lines(templatestream);

    while (iter000->nextP()) {
      line = iter000->value;
      *(outputstream->nativeStream) << substituteTemplateVariablesInString(line, variables) << std::endl;
    }
  }
}

void substituteTemplateVariablesToMakefile(char* templatefile, char* outputfile, KeyValueList* variables) {
  { OutputFileStream* out = newOutputFileStream(outputfile);

    *(out->nativeStream) << "# This file has been generated automatically.  " << "Modify at your own risk!" << std::endl << std::endl;
    substituteTemplateVariablesToStream(newInputFileStream(templatefile), out, variables);
    out->free();
  }
}

void startupCppTranslateFile() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oSTELLA_MODULEo);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      KWD_CPP_TRANSLATE_FILE_CPP = ((Keyword*)(internRigidSymbolWrtModule("CPP", NULL, 2)));
      KWD_CPP_TRANSLATE_FILE_CPP_CODE = ((Keyword*)(internRigidSymbolWrtModule("CPP-CODE", NULL, 2)));
      KWD_CPP_TRANSLATE_FILE_CPP_HEADER = ((Keyword*)(internRigidSymbolWrtModule("CPP-HEADER", NULL, 2)));
      SYM_CPP_TRANSLATE_FILE_STELLA_METHOD = ((Symbol*)(internRigidSymbolWrtModule("METHOD", NULL, 0)));
      SYM_CPP_TRANSLATE_FILE_STELLA_MAIN = ((Symbol*)(internRigidSymbolWrtModule("MAIN", NULL, 0)));
      SYM_CPP_TRANSLATE_FILE_STELLA_PRINT_METHOD = ((Symbol*)(internRigidSymbolWrtModule("PRINT-METHOD", NULL, 0)));
      SYM_CPP_TRANSLATE_FILE_STELLA_MACRO = ((Symbol*)(internRigidSymbolWrtModule("MACRO", NULL, 0)));
      SYM_CPP_TRANSLATE_FILE_STELLA_VERBATIM = ((Symbol*)(internRigidSymbolWrtModule("VERBATIM", NULL, 0)));
      SYM_CPP_TRANSLATE_FILE_STELLA_CLASS = ((Symbol*)(internRigidSymbolWrtModule("CLASS", NULL, 0)));
      SYM_CPP_TRANSLATE_FILE_STELLA_GLOBAL_VARIABLE = ((Symbol*)(internRigidSymbolWrtModule("GLOBAL-VARIABLE", NULL, 0)));
      SYM_CPP_TRANSLATE_FILE_STELLA_TYPE = ((Symbol*)(internRigidSymbolWrtModule("TYPE", NULL, 0)));
      KWD_CPP_TRANSLATE_FILE_WHITE_SPACE = ((Keyword*)(internRigidSymbolWrtModule("WHITE-SPACE", NULL, 2)));
      SYM_CPP_TRANSLATE_FILE_STELLA_AUXILIARY_VARIABLE = ((Symbol*)(internRigidSymbolWrtModule("AUXILIARY-VARIABLE", NULL, 0)));
      SYM_CPP_TRANSLATE_FILE_STELLA_CPP_FUNCTION = ((Symbol*)(internRigidSymbolWrtModule("CPP_FUNCTION", NULL, 0)));
      SYM_CPP_TRANSLATE_FILE_STELLA_CPP_DEFPRINT = ((Symbol*)(internRigidSymbolWrtModule("CPP_DEFPRINT", NULL, 0)));
      KWD_CPP_TRANSLATE_FILE_CPP_STANDALONE = ((Keyword*)(internRigidSymbolWrtModule("CPP-STANDALONE", NULL, 2)));
      KWD_CPP_TRANSLATE_FILE_TWO_PASSp = ((Keyword*)(internRigidSymbolWrtModule("TWO-PASS?", NULL, 2)));
      KWD_CPP_TRANSLATE_FILE_FORCE_TRANSLATIONp = ((Keyword*)(internRigidSymbolWrtModule("FORCE-TRANSLATION?", NULL, 2)));
      KWD_CPP_TRANSLATE_FILE_PRODUCTION_SETTINGSp = ((Keyword*)(internRigidSymbolWrtModule("PRODUCTION-SETTINGS?", NULL, 2)));
      KWD_CPP_TRANSLATE_FILE_STELLA = ((Keyword*)(internRigidSymbolWrtModule("STELLA", NULL, 2)));
      SYM_CPP_TRANSLATE_FILE_STELLA_STARTUP_CPP_TRANSLATE_FILE = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-CPP-TRANSLATE-FILE", NULL, 0)));
      SYM_CPP_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", NULL, 0)));
    }
    if (currentStartupTimePhaseP(4)) {
      oCURRENT_STREAMo.set(STANDARD_OUTPUT);
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("CPPTRANS", "(DEFUN CPPTRANS ((STATEMENT OBJECT)) :COMMAND? TRUE :PUBLIC? TRUE :EVALUATE-ARGUMENTS? FALSE :DOCUMENTATION \"Translate `statement' to C++ and print the result.\")", ((cpp_function_code)(&cpptrans)), NULL);
      defineFunctionObject("CPP-MAKE-CODE-OUTPUT-FILE-NAME", "(DEFUN (CPP-MAKE-CODE-OUTPUT-FILE-NAME FILE-NAME) ((FILENAME FILE-NAME)))", ((cpp_function_code)(&cppMakeCodeOutputFileName)), NULL);
      defineFunctionObject("CPP-MAKE-HEADER-OUTPUT-FILE-NAME", "(DEFUN (CPP-MAKE-HEADER-OUTPUT-FILE-NAME FILE-NAME) ((FILENAME FILE-NAME)))", ((cpp_function_code)(&cppMakeHeaderOutputFileName)), NULL);
      defineFunctionObject("CPP-OUTPUT-FILE-HEADER", "(DEFUN CPP-OUTPUT-FILE-HEADER ((STREAM OUTPUT-STREAM) (FILE FILE-NAME)))", ((cpp_function_code)(&cppOutputFileHeader)), NULL);
      defineFunctionObject("CPP-OUTPUT-INCLUDE-DIRECTIVE", "(DEFUN CPP-OUTPUT-INCLUDE-DIRECTIVE ((FILENAME FILE-NAME) (STRIPDIRECTORY? BOOLEAN)))", ((cpp_function_code)(&cppOutputIncludeDirective)), NULL);
      defineFunctionObject("CPP-STANDALONE-OUTPUT-IMPORT-DECLARATIONS", "(DEFUN CPP-STANDALONE-OUTPUT-IMPORT-DECLARATIONS ((HEADERFILENAME FILE-NAME)))", ((cpp_function_code)(&cppStandaloneOutputImportDeclarations)), NULL);
      defineFunctionObject("CPP-RELATIVIZE-HEADER-FILE", "(DEFUN (CPP-RELATIVIZE-HEADER-FILE FILE-NAME) ((HEADERFILE FILE-NAME) (SYSTEMNAME STRING)))", ((cpp_function_code)(&cppRelativizeHeaderFile)), NULL);
      defineFunctionObject("CPP-OUTPUT-IMPORT-DECLARATIONS", "(DEFUN CPP-OUTPUT-IMPORT-DECLARATIONS ((SYSTEMNAME STRING)))", ((cpp_function_code)(&cppOutputImportDeclarations)), NULL);
      defineFunctionObject("CPP-OUTPUT-CLASS-HEAD-DECLARATIONS", "(DEFUN CPP-OUTPUT-CLASS-HEAD-DECLARATIONS ((CLASSES CONS)))", ((cpp_function_code)(&cppOutputClassHeadDeclarations)), NULL);
      defineFunctionObject("CPP-OUTPUT-NAMESPACE-HEADER", "(DEFUN CPP-OUTPUT-NAMESPACE-HEADER ((MODULE MODULE)))", ((cpp_function_code)(&cppOutputNamespaceHeader)), NULL);
      defineFunctionObject("CPP-OUTPUT-NAMESPACE-FOOTER", "(DEFUN CPP-OUTPUT-NAMESPACE-FOOTER ((MODULE MODULE)))", ((cpp_function_code)(&cppOutputNamespaceFooter)), NULL);
      defineFunctionObject("CPP-UNIT-DEFINES-MAIN?", "(DEFUN (CPP-UNIT-DEFINES-MAIN? BOOLEAN) ((UNIT TRANSLATION-UNIT)))", ((cpp_function_code)(&cppUnitDefinesMainP)), NULL);
      defineFunctionObject("CPP-YIELD-MAIN-FILE-NAME", "(DEFUN (CPP-YIELD-MAIN-FILE-NAME FILE-NAME) ())", ((cpp_function_code)(&cppYieldMainFileName)), NULL);
      defineFunctionObject("CPP-OUTPUT-MAIN", "(DEFUN CPP-OUTPUT-MAIN ((UNIT TRANSLATION-UNIT)))", ((cpp_function_code)(&cppOutputMain)), NULL);
      defineFunctionObject("CPP-SORT-UNITS-FOR-HEADER-FILE", "(DEFUN (CPP-SORT-UNITS-FOR-HEADER-FILE (LIST OF (CONS OF TRANSLATION-UNIT))) ((FILEUNITS (LIST OF TRANSLATION-UNIT))))", ((cpp_function_code)(&cppSortUnitsForHeaderFile)), NULL);
      defineFunctionObject("CPP-OUTPUT-NAMESPACE-CHANGE", "(DEFUN CPP-OUTPUT-NAMESPACE-CHANGE ((FROMNAMESPACE MODULE) (TONAMESPACE MODULE)))", ((cpp_function_code)(&cppOutputNamespaceChange)), NULL);
      defineFunctionObject("CPP-OUTPUT-ALL-UNITS-TO-FILE", "(DEFUN CPP-OUTPUT-ALL-UNITS-TO-FILE ((FILENAME FILE-NAME)))", ((cpp_function_code)(&cppOutputAllUnitsToFile)), NULL);
      defineFunctionObject("CPP-TRANSLATE-FILE", "(DEFUN CPP-TRANSLATE-FILE ((FILENAME FILE-NAME)) :PUBLIC? TRUE)", ((cpp_function_code)(&cppTranslateFile)), NULL);
      defineFunctionObject("CPP-STANDALONE-TRANSLATE-FILE", "(DEFUN CPP-STANDALONE-TRANSLATE-FILE ((FILENAME FILE-NAME)))", ((cpp_function_code)(&cppStandaloneTranslateFile)), NULL);
      defineFunctionObject("CPP-TRANSLATE-SYSTEM", "(DEFUN CPP-TRANSLATE-SYSTEM ((SYSTEMNAME STRING)) :DOCUMENTATION \"Translate the system `systemName' to C++.\" :PUBLIC? TRUE)", ((cpp_function_code)(&cppTranslateSystem)), NULL);
      defineFunctionObject("CPP-TRANSLATE-WALKED-SYSTEM-UNITS", "(DEFUN CPP-TRANSLATE-WALKED-SYSTEM-UNITS ((SYSTEMUNITS SYSTEM-UNITS-ALIST)))", ((cpp_function_code)(&cppTranslateWalkedSystemUnits)), NULL);
      defineFunctionObject("CPP-OUTPUT-SYSTEM-SPECIFIC-FILES", "(DEFUN CPP-OUTPUT-SYSTEM-SPECIFIC-FILES ())", ((cpp_function_code)(&cppOutputSystemSpecificFiles)), NULL);
      defineFunctionObject("CPP-YIELD-SYSTEM-HEADER-FILE-NAME", "(DEFUN (CPP-YIELD-SYSTEM-HEADER-FILE-NAME STRING) ((SYSTEMNAME STRING)))", ((cpp_function_code)(&cppYieldSystemHeaderFileName)), NULL);
      defineFunctionObject("CPP-YIELD-SYSTEM-HEADER-FILE-GUARD", "(DEFUN (CPP-YIELD-SYSTEM-HEADER-FILE-GUARD STRING) ((SYSTEMNAME STRING)))", ((cpp_function_code)(&cppYieldSystemHeaderFileGuard)), NULL);
      defineFunctionObject("CPP-OUTPUT-SYSTEM-HEADER-FILE", "(DEFUN CPP-OUTPUT-SYSTEM-HEADER-FILE ())", ((cpp_function_code)(&cppOutputSystemHeaderFile)), NULL);
      defineFunctionObject("CPP-YIELD-SYSTEMS-ROOT-DIRECTORY", "(DEFUN (CPP-YIELD-SYSTEMS-ROOT-DIRECTORY STRING) ())", ((cpp_function_code)(&cppYieldSystemsRootDirectory)), NULL);
      defineFunctionObject("CPP-YIELD-STELLA-ROOT-DIRECTORY", "(DEFUN (CPP-YIELD-STELLA-ROOT-DIRECTORY STRING) ())", ((cpp_function_code)(&cppYieldStellaRootDirectory)), NULL);
      defineFunctionObject("CPP-OUTPUT-SYSTEM-MAKEFILE", "(DEFUN CPP-OUTPUT-SYSTEM-MAKEFILE ())", ((cpp_function_code)(&cppOutputSystemMakefile)), NULL);
      defineFunctionObject("SUBSTITUTE-TEMPLATE-VARIABLES-IN-STRING", "(DEFUN (SUBSTITUTE-TEMPLATE-VARIABLES-IN-STRING STRING) ((STRING STRING) (VARIABLES (KEY-VALUE-LIST OF STRING-WRAPPER STRING-WRAPPER))))", ((cpp_function_code)(&substituteTemplateVariablesInString)), NULL);
      defineFunctionObject("SUBSTITUTE-TEMPLATE-VARIABLES-TO-STREAM", "(DEFUN SUBSTITUTE-TEMPLATE-VARIABLES-TO-STREAM ((TEMPLATESTREAM INPUT-STREAM) (OUTPUTSTREAM OUTPUT-STREAM) (VARIABLES (KEY-VALUE-LIST OF STRING-WRAPPER STRING-WRAPPER))))", ((cpp_function_code)(&substituteTemplateVariablesToStream)), NULL);
      defineFunctionObject("SUBSTITUTE-TEMPLATE-VARIABLES-TO-MAKEFILE", "(DEFUN SUBSTITUTE-TEMPLATE-VARIABLES-TO-MAKEFILE ((TEMPLATEFILE STRING) (OUTPUTFILE STRING) (VARIABLES (KEY-VALUE-LIST OF STRING-WRAPPER STRING-WRAPPER))))", ((cpp_function_code)(&substituteTemplateVariablesToMakefile)), NULL);
      defineFunctionObject("STARTUP-CPP-TRANSLATE-FILE", "(DEFUN STARTUP-CPP-TRANSLATE-FILE () :PUBLIC? TRUE)", ((cpp_function_code)(&startupCppTranslateFile)), NULL);
      { MethodSlot* function = lookupFunction(SYM_CPP_TRANSLATE_FILE_STELLA_STARTUP_CPP_TRANSLATE_FILE);

        setDynamicSlotValue(function->dynamicSlots, SYM_CPP_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Cpp-Translate-File"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *CURRENT-STREAM* OUTPUT-STREAM STANDARD-OUTPUT)");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CPP-TRANSLATED-FILE-SUFFIX* STRING \"\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *MAKEFILE-TEMPLATE-VARIABLE-PREFIX* STRING \"#$\")");
    }
  }
}

Keyword* KWD_CPP_TRANSLATE_FILE_CPP = NULL;

Keyword* KWD_CPP_TRANSLATE_FILE_CPP_CODE = NULL;

Keyword* KWD_CPP_TRANSLATE_FILE_CPP_HEADER = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_METHOD = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_MAIN = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_PRINT_METHOD = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_MACRO = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_VERBATIM = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_CLASS = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_GLOBAL_VARIABLE = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_TYPE = NULL;

Keyword* KWD_CPP_TRANSLATE_FILE_WHITE_SPACE = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_AUXILIARY_VARIABLE = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_CPP_FUNCTION = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_CPP_DEFPRINT = NULL;

Keyword* KWD_CPP_TRANSLATE_FILE_CPP_STANDALONE = NULL;

Keyword* KWD_CPP_TRANSLATE_FILE_TWO_PASSp = NULL;

Keyword* KWD_CPP_TRANSLATE_FILE_FORCE_TRANSLATIONp = NULL;

Keyword* KWD_CPP_TRANSLATE_FILE_PRODUCTION_SETTINGSp = NULL;

Keyword* KWD_CPP_TRANSLATE_FILE_STELLA = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_STARTUP_CPP_TRANSLATE_FILE = NULL;

Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace stella
