//  -*- Mode: C++ -*-

// systems.cc

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

Object* evaluateCommand(Object* command, boolean finalizeP) {
  { boolean dummy1;

    { 
      BIND_STELLA_SPECIAL(oTRANSLATIONERRORSo, int, 0);
      BIND_STELLA_SPECIAL(oTRANSLATIONWARNINGSo, int, 0);
      BIND_STELLA_SPECIAL(oIGNORETRANSLATIONERRORSpo, boolean, FALSE);
      BIND_STELLA_SPECIAL(oTRANSLATIONUNITSo, List*, NULL);
      BIND_STELLA_SPECIAL(oTRANSLATIONPHASEo, Keyword*, KWD_SYSTEMS_DEFINE);
      BIND_STELLA_SPECIAL(oEVALUATIONTREEo, Object*, NULL);
      { Object* operatoR = NULL;
        Object* result = NULL;

        { Surrogate* testValue000 = safePrimaryType(command);

          if (testValue000 == SGT_SYSTEMS_STELLA_CONS) {
            { Object* command000 = command;
              Cons* command = ((Cons*)(command000));

              operatoR = command->value;
              if (subtypeOfSymbolP(safePrimaryType(operatoR))) {
                { Object* operator000 = operatoR;
                  Symbol* operatoR = ((Symbol*)(operator000));

                  if (operatoR == SYM_SYSTEMS_STELLA_IN_MODULE) {
                    handleInModuleTree(command, FALSE, dummy1);
                  }
                  else {
                    if (declarationTreeP(command)) {
                      oTRANSLATIONUNITSo.set(list(0));
                      walkTopLevelTree(command, FALSE);
                      switch (oTRANSLATIONUNITSo.get()->reverse()->length()) {
                        case 0: 
                          { OutputStringStream* stream000 = newOutputStringStream();

                            *(stream000->nativeStream) << "While evaluating '" << oEVALUATIONTREEo.get();
                            if (((boolean)(oEVALUATIONPARENTTREEo.get()))) {
                              *(stream000->nativeStream) << std::endl << "' inside '" << oEVALUATIONPARENTTREEo.get();
                            }
                            *(stream000->nativeStream) << "':" << std::endl;
                            *(stream000->nativeStream) << "Couldn't translate " << "`" << command << "'";
                            throw *newEvaluationException(stream000->theStringReader());
                          }
                        break;
                        case 1: 
                          result = ((TranslationUnit*)(oTRANSLATIONUNITSo.get()->first()))->theObject;
                        break;
                        default:
                          { Cons* results = NIL;

                            { TranslationUnit* unit = NULL;
                              Cons* iter000 = oTRANSLATIONUNITSo.get()->theConsList;
                              Cons* collect000 = NULL;

                              while (!(iter000 == NIL)) {
                                unit = ((TranslationUnit*)(iter000->value));
                                iter000 = iter000->rest;
                                if (!((boolean)(collect000))) {
                                  {
                                    collect000 = cons(unit->theObject, NIL);
                                    if (results == NIL) {
                                      results = collect000;
                                    }
                                    else {
                                      addConsToEndOfConsList(results, collect000);
                                    }
                                  }
                                }
                                else {
                                  {
                                    collect000->rest = cons(unit->theObject, NIL);
                                    collect000 = collect000->rest;
                                  }
                                }
                              }
                            }
                            result = results;
                          }
                        break;
                      }
                    }
                    else if (stringEqualP(operatoR->symbolName, "in-package")) {
                    }
                    else {
                      evaluate(command);
                    }
                  }
                }
              }
              else {
                evaluate(command);
              }
            }
          }
          else if (subtypeOfKeywordP(testValue000)) {
            { Object* command001 = command;
              Keyword* command = ((Keyword*)(command001));

              result = command;
            }
          }
          else if (subtypeOfSurrogateP(testValue000)) {
            { Object* command002 = command;
              Surrogate* command = ((Surrogate*)(command002));

              result = command;
            }
          }
          else {
            evaluate(command);
          }
        }
        if ((!translationErrorsP()) &&
            finalizeP) {
          oTRANSLATIONPHASEo.set(KWD_SYSTEMS_FINALIZE);
          if (((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
            runSystemFinalization(oCURRENTSYSTEMDEFINITIONo.get());
          }
          else {
            std::cout << "Can't run finalization because *currentSystemDefinition* is not set." << std::endl;
          }
        }
        return (result);
      }
    }
  }
}

void loadFile(char* file) {
  // Read STELLA commands from `file' and evaluate them.
  // The file should begin with an `in-module' declaration that specifies
  // the module within which all remaining commands are to be evaluated
  // The remaining commands are evaluated one-by-one, applying the function
  // `evaluate' to each of them.
  if (!probeFileP(file)) {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "File " << "`" << file << "'" << " does not exist.";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  { boolean toplevelinvocationP = oCURRENTFILEo.get() == NULL;
    boolean skipcommandP = FALSE;
    boolean seeninmoduleP = FALSE;
    Cons* commands = NIL;
    InputFileStream* inputstream = NULL;

    try {
      { 
        BIND_STELLA_SPECIAL(oCURRENTFILEo, char*, fileBaseName(file));
        inputstream = newInputFileStream(file);
        { 
          BIND_STELLA_SPECIAL(oMODULEo, Module*, oMODULEo.get());
          BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
          { Object* tree = NULL;
            SExpressionIterator* iter000 = sExpressions(inputstream);

            while (iter000->nextP()) {
              tree = iter000->value;
              if (safePrimaryType(tree) == SGT_SYSTEMS_STELLA_CONS) {
                { Object* tree000 = tree;
                  Cons* tree = ((Cons*)(tree000));

                  skipcommandP = handleInModuleTree(tree, seeninmoduleP, seeninmoduleP);
                  if (skipcommandP) {
                    continue;
                  }
                  { Object* operatoR = tree->value;

                    if (subtypeOfSymbolP(safePrimaryType(operatoR))) {
                      { Object* operator000 = operatoR;
                        Symbol* operatoR = ((Symbol*)(operator000));

                        if ((operatoR == SYM_SYSTEMS_STELLA_DEFMODULE) ||
                            ((operatoR == SYM_SYSTEMS_STELLA_DEFSYSTEM) ||
                             ((operatoR == SYM_SYSTEMS_STELLA_DEFCLASS) ||
                              ((operatoR == SYM_SYSTEMS_STELLA_DEFSLOT) ||
                               ((operatoR == SYM_SYSTEMS_STELLA_DEFUN) ||
                                (operatoR == SYM_SYSTEMS_STELLA_DEFMETHOD)))))) {
                          evaluateCommand(tree, FALSE);
                        }
                        else {
                          if (((boolean)(lookupCommand(operatoR)))) {
                            commands = cons(tree, commands);
                          }
                          else {
                            evaluateCommand(tree, FALSE);
                          }
                        }
                      }
                    }
                    else {
                      evaluateCommand(tree, FALSE);
                    }
                  }
                }
              }
              else {
                evaluateCommand(tree, FALSE);
              }
            }
          }
          { 
            BIND_STELLA_SPECIAL(oTRANSLATIONPHASEo, Keyword*, KWD_SYSTEMS_FINALIZE);
            runSystemFinalization(oCURRENTSYSTEMDEFINITIONo.get());
          }
          { Object* tree = NULL;
            Cons* iter001 = commands->reverse();

            while (!(iter001 == NIL)) {
              tree = iter001->value;
              iter001 = iter001->rest;
              evaluateCommand(tree, TRUE);
            }
          }
        }
      }
    }
catch (...) {
      if (toplevelinvocationP) {
        sweepTransients();
      }
      if (((boolean)(inputstream))) {
        inputstream->free();
      }
      throw;
    }
    if (toplevelinvocationP) {
      sweepTransients();
    }
    if (((boolean)(inputstream))) {
      inputstream->free();
    }
  }
}

void loadFileEvaluatorWrapper(Cons* arguments) {
  loadFile(((StringWrapper*)(arguments->value))->wrapperValue);
}

// A list of all defined systems.
List* oSYSTEMDEFINITIONSo = NULL;

char* makeSystemDefinitionFileName(char* name) {
  return (stringConcatenate(systemDefinitionsDirectory(), directorySeparatorString(), 2, stringDowncase(name), "-system.ste"));
}

Cons* parseListOfFilePaths(Cons* files) {
  { Cons* strings = NIL;

    { Object* filespec = NULL;
      Cons* iter000 = files;

      while (!(iter000 == NIL)) {
        filespec = iter000->value;
        iter000 = iter000->rest;
        strings = cons(wrapString(implodePathname(filespec)), strings);
      }
    }
    return (strings->reverse());
  }
}

SystemDefinition* defineSystem(Object* name, Cons* options) {
  { char* stringname = NULL;

    { Surrogate* testValue000 = safePrimaryType(name);

      if (subtypeOfStringP(testValue000)) {
        { Object* name000 = name;
          StringWrapper* name = ((StringWrapper*)(name000));

          stringname = name->wrapperValue;
        }
      }
      else if (subtypeOfSymbolP(testValue000)) {
        { Object* name001 = name;
          Symbol* name = ((Symbol*)(name001));

          stringname = stringDowncase(name->symbolName);
        }
      }
      else {
        std::cout << "Illegal system name: " << name;
        return (NULL);
      }
    }
    { SystemDefinition* self000 = newSystemDefinition();

      self000->name = stringname;
      { SystemDefinition* system = self000;
        SystemDefinition* requiredSystem = NULL;

        { PropertyList* self001 = newPropertyList();

          self001->thePlist = options;
          { PropertyList* plist = self001;

            { SystemDefinition* value000 = NULL;

              { SystemDefinition* s = NULL;
                Cons* iter000 = oSYSTEMDEFINITIONSo->theConsList;

                while (!(iter000 == NIL)) {
                  s = ((SystemDefinition*)(iter000->value));
                  iter000 = iter000->rest;
                  if (stringEqlP(s->name, stringname)) {
                    value000 = s;
                    break;
                  }
                }
              }
              { SystemDefinition* oldsystem = value000;

                { Object* key = NULL;
                  Object* value = NULL;
                  Cons* iter001 = plist->thePlist;

                  while (!(iter001 == NIL)) {
                    key = iter001->value;
                    value = iter001->rest->value;
                    iter001 = iter001->rest->rest;
                    { GeneralizedSymbol* testValue001 = ((GeneralizedSymbol*)(key));

                      if (testValue001 == KWD_SYSTEMS_DIRECTORY) {
                        system->directory = implodePathname(value);
                      }
                      else if (testValue001 == KWD_SYSTEMS_FILES) {
                        system->files = parseListOfFilePaths(((Cons*)(value)));
                      }
                      else if (testValue001 == KWD_SYSTEMS_REQUIRED_SYSTEMS) {
                        system->requiredSystems = ((Cons*)(value));
                        { Object* sys = NULL;
                          Cons* iter002 = ((Cons*)(value));

                          while (!(iter002 == NIL)) {
                            sys = iter002->value;
                            iter002 = iter002->rest;
                            requiredSystem = getSystemDefinition(((StringWrapper*)(sys))->wrapperValue);
                            if ((!stringEqualP(((StringWrapper*)(sys))->wrapperValue, "stella")) &&
                                (!requiredSystem->loadedP)) {
                              std::cout << "Making dependent system " << ((StringWrapper*)(sys))->wrapperValue << std::endl;
                              makeSystem(((StringWrapper*)(sys))->wrapperValue, oTRANSLATOROUTPUTLANGUAGEo.get(), NIL);
                              std::cout << std::endl << std::endl;
                            }
                          }
                        }
                      }
                      else if (testValue001 == KWD_SYSTEMS_LISP_ONLY_FILES) {
                        system->lispOnlyFiles = parseListOfFilePaths(((Cons*)(value)));
                      }
                      else if (testValue001 == KWD_SYSTEMS_CPP_ONLY_FILES) {
                        system->cppOnlyFiles = parseListOfFilePaths(((Cons*)(value)));
                      }
                      else if (testValue001 == KWD_SYSTEMS_JAVA_ONLY_FILES) {
                        system->javaOnlyFiles = parseListOfFilePaths(((Cons*)(value)));
                      }
                      else if (testValue001 == KWD_SYSTEMS_PREPROCESSED_FILES) {
                        system->preprocessedFiles = parseListOfFilePaths(((Cons*)(value)));
                      }
                      else if (testValue001 == KWD_SYSTEMS_CARDINAL_MODULE) {
                        system->cardinalModule = ((StringWrapper*)(value))->wrapperValue;
                      }
                      else if (testValue001 == KWD_SYSTEMS_ROOT_SOURCE_DIRECTORY) {
                        system->sourceRootDirectory = ((StringWrapper*)(value))->wrapperValue;
                      }
                      else if (testValue001 == KWD_SYSTEMS_ROOT_NATIVE_DIRECTORY) {
                        system->nativeRootDirectory = ((StringWrapper*)(value))->wrapperValue;
                      }
                      else if (testValue001 == KWD_SYSTEMS_ROOT_BINARY_DIRECTORY) {
                        system->binaryRootDirectory = ((StringWrapper*)(value))->wrapperValue;
                      }
                      else if ((testValue001 == KWD_SYSTEMS_BANNER) ||
                          (testValue001 == KWD_SYSTEMS_COPYRIGHT_HEADER)) {
                        system->banner = ((StringWrapper*)(value))->wrapperValue;
                      }
                      else if (testValue001 == KWD_SYSTEMS_PRODUCTION_SETTINGS) {
                        system->productionSettings = ((Cons*)(value));
                      }
                      else if (testValue001 == KWD_SYSTEMS_DEVELOPMENT_SETTINGS) {
                        system->developmentSettings = ((Cons*)(value));
                      }
                      else if (testValue001 == KWD_SYSTEMS_FINALIZATION_FUNCTION) {
                        system->finalizationFunction = ((Symbol*)(value));
                      }
                      else {
                        { OutputStringStream* stream000 = newOutputStringStream();

                          *(stream000->nativeStream) << "`" << testValue001 << "'" << " is not a valid case option";
                          throw *newStellaException(stream000->theStringReader());
                        }
                      }
                    }
                  }
                }
                oSYSTEMDEFINITIONSo->push(system);
                if (((boolean)(oldsystem))) {
                  std::cout << "Redefining system " << "`" << system->name << "'" << std::endl << std::endl;
                  oSYSTEMDEFINITIONSo->remove(oldsystem);
                }
                return (system);
              }
            }
          }
        }
      }
    }
  }
}

SystemDefinition* defsystem(Symbol* name, Cons* options) {
  // Define a system of files that collectively define
  // a Stella application.
  //    Required options are:
  //    :directory -- the path from the Stella root directory to the directory
  //                  containing the system files.  Can be a string or a list
  //                  of strings (do not include directory separators).
  //    :files -- a list of files in the system, containing strings and lists
  //              of strings; the latter defines exploded paths to files
  //              in subdirectories.
  //    Optional options are:
  //    :required-systems -- a list of systems (strings) that should be loaded
  //                         prior to loading this system.
  //    :cardinal-module -- the name (a string) of the principal module for this
  //                        system.
  //    :copyright-header -- string with a header for inclusion into all translated
  //                         files produced by Stella.
  //    :lisp-only-files  -- Like the :files keyword, but these are only included
  //    :cpp-only-files      in the translation for the specific language, namely
  //    :java-only-files     Common Lisp, C++ or Java
  return (defineSystem(name, options));
}

SystemDefinition* defsystemEvaluatorWrapper(Cons* arguments) {
  return (defsystem(((Symbol*)(arguments->value)), arguments->rest));
}

SystemDefinition* getSystemDefinition(char* name) {
  { SystemDefinition* value000 = NULL;

    { SystemDefinition* s = NULL;
      Cons* iter000 = oSYSTEMDEFINITIONSo->theConsList;

      while (!(iter000 == NIL)) {
        s = ((SystemDefinition*)(iter000->value));
        iter000 = iter000->rest;
        if (stringEqualP(s->name, name)) {
          value000 = s;
          break;
        }
      }
    }
    { SystemDefinition* system = value000;

      if (!((boolean)(system))) {
        { char* systemfilename = makeSystemDefinitionFileName(name);

          if (!probeFileP(systemfilename)) {
            *(STANDARD_ERROR->nativeStream) << "ERROR>> File " << systemfilename << " does not exist." << std::endl << "   Can't define system " << name << std::endl;
            return (NULL);
          }
          loadFile(systemfilename);
          { SystemDefinition* value001 = NULL;

            { SystemDefinition* s = NULL;
              Cons* iter001 = oSYSTEMDEFINITIONSo->theConsList;

              while (!(iter001 == NIL)) {
                s = ((SystemDefinition*)(iter001->value));
                iter001 = iter001->rest;
                if (stringEqualP(s->name, name)) {
                  value001 = s;
                  break;
                }
              }
            }
            system = value001;
          }
          if (!((boolean)(system))) {
            *(STANDARD_ERROR->nativeStream) << "ERROR>>  Can't find a system definition for system " << name << std::endl << "   within file " << systemfilename << "." << std::endl;
          }
        }
      }
      return (system);
    }
  }
}

Module* getCardinalModule(SystemDefinition* system) {
  { char* name = system->cardinalModule;
    Module* module = NULL;

    if (name != NULL) {
      module = getStellaModule(name, FALSE);
      if (!((boolean)(module))) {
        module = getStellaModule(stringUpcase(name), FALSE);
      }
    }
    if (!((boolean)(module))) {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "No cardinal module defined for system: " << "`" << system << "'" << std::endl << std::endl;
    }
    return (module);
  }
}

void helpGetSystemFiles(char* filename, List* collection, boolean probefileP) {
  if ((!probefileP) ||
      probeFileP(filename)) {
    collection->push(wrapString(filename));
  }
}

List* getSystemFiles(SystemDefinition* system, Keyword* type, boolean probefilesP) {
  { List* files = newList();
    char* filename = NULL;

    { 
      BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition*, getSystemDefinition(system->name));
      BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char*, (((boolean)(oCURRENTSYSTEMDEFINITIONo.get())) ? oCURRENTSYSTEMDEFINITIONo.get()->directory : NULL));
      if (((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
        {
          { StringWrapper* f = NULL;
            Cons* iter000 = oCURRENTSYSTEMDEFINITIONo.get()->files;

            while (!(iter000 == NIL)) {
              f = ((StringWrapper*)(iter000->value));
              iter000 = iter000->rest;
              if (type == KWD_SYSTEMS_JAVA) {
                filename = javaTranslateClassNamestring(wrapString(stringConcatenate("Startup-", f->wrapperValue, 0)))->wrapperValue;
              }
              else {
                filename = makeFileNameFromRelativePath(f, type);
              }
              helpGetSystemFiles(filename, files, probefilesP);
            }
          }
          if (type == KWD_SYSTEMS_JAVA) {
            if (!((boolean)(getCardinalModule(oCURRENTSYSTEMDEFINITIONo.get())))) {
              std::cout << "No cardinal module defined for system " << "`" << system->name << "'" << std::endl << std::endl;
              return (NIL_LIST);
            }
            { Class* clasS = NULL;
              Iterator* iter001 = allClasses(getCardinalModule(oCURRENTSYSTEMDEFINITIONo.get()), TRUE);

              while (iter001->nextP()) {
                clasS = ((Class*)(iter001->value));
                filename = clasS->javaMakeCodeOutputFileName(FALSE);
                helpGetSystemFiles(filename, files, probefilesP);
              }
            }
            filename = stringJavaMakeCodeOutputFileName(javaYieldFlotsamClassName(getCardinalModule(oCURRENTSYSTEMDEFINITIONo.get())), FALSE);
            helpGetSystemFiles(filename, files, probefilesP);
          }
          else {
          }
        }
      }
      else {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't find a system named " << "`" << system->name << "'" << std::endl << std::endl;
      }
    }
    return (files);
  }
}

void cleanSystem(char* systemname) {
  { SystemDefinition* system = getSystemDefinition(systemname);

    if (!((boolean)(system))) {
      return;
    }
    { StringWrapper* f = NULL;
      Cons* iter000 = getSystemFiles(system, KWD_SYSTEMS_LISP, TRUE)->theConsList;

      while (!(iter000 == NIL)) {
        f = ((StringWrapper*)(iter000->value));
        iter000 = iter000->rest;
        deleteFile(f->wrapperValue);
      }
    }
    { StringWrapper* f = NULL;
      Cons* iter001 = getSystemFiles(system, KWD_SYSTEMS_JAVA, TRUE)->theConsList;

      while (!(iter001 == NIL)) {
        f = ((StringWrapper*)(iter001->value));
        iter001 = iter001->rest;
        deleteFile(f->wrapperValue);
      }
    }
    { StringWrapper* f = NULL;
      Cons* iter002 = getSystemFiles(system, KWD_SYSTEMS_CPP, TRUE)->theConsList;

      while (!(iter002 == NIL)) {
        f = ((StringWrapper*)(iter002->value));
        iter002 = iter002->rest;
        deleteFile(f->wrapperValue);
      }
    }
    { StringWrapper* f = NULL;
      Cons* iter003 = getSystemFiles(system, KWD_SYSTEMS_LISP_BINARY, TRUE)->theConsList;

      while (!(iter003 == NIL)) {
        f = ((StringWrapper*)(iter003->value));
        iter003 = iter003->rest;
        deleteFile(f->wrapperValue);
      }
    }
  }
}

void computeOptimizationLevels(SystemDefinition* system, boolean productionmodeP) {
  { Cons* settings = NULL;

    if (productionmodeP) {
      settings = system->productionSettings;
    }
    else {
      settings = system->developmentSettings;
    }
    if (!((boolean)(settings))) {
      settings = getQuotedTree("((3 2 3 3) \"/STELLA\")", "/STELLA");
    }
    setOptimizationLevels(((IntegerWrapper*)(settings->nth(0)))->wrapperValue, ((IntegerWrapper*)(settings->nth(1)))->wrapperValue, ((IntegerWrapper*)(settings->nth(2)))->wrapperValue, ((IntegerWrapper*)(settings->nth(3)))->wrapperValue);
  }
}

Keyword* lispKeywordToStellaKeyword(Keyword* key) {
  { Keyword* stellakeyword = NULL;

    return (stellakeyword);
  }
}

PropertyList* vetOptions(Object* plist, Cons* legaloptions) {
  { PropertyList* propertylist = NULL;

    { Surrogate* testValue000 = safePrimaryType(plist);

      if (subtypeOfP(testValue000, SGT_SYSTEMS_STELLA_PROPERTY_LIST)) {
        { Object* plist000 = plist;
          PropertyList* plist = ((PropertyList*)(plist000));

          propertylist = plist;
        }
      }
      else if (testValue000 == SGT_SYSTEMS_STELLA_CONS) {
        { Object* plist001 = plist;
          Cons* plist = ((Cons*)(plist001));

          { PropertyList* self000 = newPropertyList();

            self000->thePlist = plist;
            propertylist = self000;
          }
        }
      }
      else if (subtypeOfP(testValue000, SGT_SYSTEMS_STELLA_LIST)) {
        { Object* plist002 = plist;
          List* plist = ((List*)(plist002));

          { PropertyList* self001 = newPropertyList();

            self001->thePlist = plist->theConsList;
            propertylist = self001;
          }
        }
      }
      else {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal argument passed to 'vet-options'" << std::endl;
        return (newPropertyList());
      }
    }
    { Object* key = NULL;
      Object* value = NULL;
      Cons* iter000 = propertylist->thePlist;

      while (!(iter000 == NIL)) {
        key = iter000->value;
        value = iter000->rest->value;
        iter000 = iter000->rest->rest;
        if ((!stellaObjectP(key)) ||
            ((!keywordP(key)) ||
             (((boolean)(legaloptions)) &&
              (!legaloptions->memberP(key))))) {
          value = value;
          if (!stellaObjectP(key)) {
            { PropertyList* newplist = newPropertyList();

              { Object* key = NULL;
                Object* value = NULL;
                Cons* iter001 = propertylist->thePlist;

                while (!(iter001 == NIL)) {
                  key = iter001->value;
                  value = iter001->rest->value;
                  iter001 = iter001->rest->rest;
                  newplist->insertAt(stellify(key), stellify(value));
                }
              }
              propertylist->thePlist = newplist->thePlist;
            }
            vetOptions(propertylist, legaloptions);
            return (propertylist);
          }
          propertylist->removeAt(key);
          std::cout << "Skipping illegal option: " << "`" << key << "'" << std::endl << std::endl;
          if (keywordP(key)) {
            std::cout << "   Legal options are: " << "`" << legaloptions << "'" << std::endl << std::endl;
          }
          else {
            std::cout << "   Option must be a keyword." << std::endl;
          }
          vetOptions(propertylist, legaloptions);
          return (propertylist);
        }
      }
    }
    return (propertylist);
  }
}

boolean makeSystem(char* systemname, Keyword* language, Cons* options) {
  // Translate all out-of-date files of system `systemName'
  // into `language' and then compile and load them (the latter is only possible
  // for Lisp right now).  The following keyword/value `options' are recognized:
  // 
  // `:two-pass?': if true, all files will be scanned twice, once to
  // load the signatures of objects defined in them, and once to actually
  // translate the definitions.  Otherwise, the translator will make one pass in
  // the case that the system is already loaded (and is being remade), and two
  // passes otherwise.
  // 
  // `:development-settings?' (default false): if true translation will favor
  // safe, readable and debuggable code over efficiency (according to the value
  // of `:development-settings' on the system definition).  If false, efficiency
  // will be favored instead (according to the value of `:production-settings'
  // on the system definition).
  // 
  // `:production-settings?' (default true): inverse to `:development-settings?'.
  // 
  // `:force-translation?' (default false): if true, files will be translated
  // whether or not their translations are up-to-date.
  // 
  // `:force-recompilation?' (default false): if true, translated files will be
  // recompiled whether or not their compilations are up-to-date (only supported
  // in Lisp right now).
  // 
  // `:load-system?' (default true): if true, compiled files will be loaded into
  // the current STELLA image (only supported in Lisp right now).
  // 
  // `:startup?' (default true): if true, the system startup function will
  // be called once all files have been loaded.
  language = ((Keyword*)(stellify(language)));
  { 
    BIND_STELLA_SPECIAL(oTRANSLATOROUTPUTLANGUAGEo, Keyword*, language);
    setTranslatorOutputLanguage(language);
    { PropertyList* self000 = newPropertyList();

      self000->thePlist = options;
      { PropertyList* plist = self000;
        boolean developmentsettingsP = FALSE;
        boolean forcetranslationP = FALSE;
        boolean forcerecompilationP = FALSE;
        boolean twopassP = ((boolean)(getSystemDefinition(systemname))) &&
            (!getSystemDefinition(systemname)->loadedP);
        boolean loadsystemP = language == KWD_SYSTEMS_COMMON_LISP;
        boolean startupsystemP = language == KWD_SYSTEMS_COMMON_LISP;
        boolean updatedsystemP = FALSE;
        SystemDefinition* system = getSystemDefinition(systemname);

        if (!((boolean)(system))) {
          std::cout << "Can't find a declaration for system named " << systemname << std::endl << "  Possibly a global path name needs to be set." << std::endl;
          return (FALSE);
        }
        vetOptions(plist, getQuotedTree("((:TWO-PASS? :DEVELOPMENT-SETTINGS? :PRODUCTION-SETTINGS? :FORCE-TRANSLATION? :FORCE-RECOMPILATION? :LOAD-SYSTEM? :STARTUP?) \"/STELLA\")", "/STELLA"));
        { Object* key = NULL;
          Object* value = NULL;
          Cons* iter000 = plist->thePlist;

          while (!(iter000 == NIL)) {
            key = iter000->value;
            value = iter000->rest->value;
            iter000 = iter000->rest->rest;
            { boolean truevalueP = eqlP(value, TRUE_WRAPPER);

              { GeneralizedSymbol* testValue000 = ((GeneralizedSymbol*)(key));

                if (testValue000 == KWD_SYSTEMS_DEVELOPMENT_SETTINGSp) {
                  developmentsettingsP = truevalueP;
                }
                else if (testValue000 == KWD_SYSTEMS_PRODUCTION_SETTINGSp) {
                  developmentsettingsP = !truevalueP;
                }
                else if (testValue000 == KWD_SYSTEMS_FORCE_TRANSLATIONp) {
                  forcetranslationP = truevalueP;
                }
                else if (testValue000 == KWD_SYSTEMS_FORCE_RECOMPILATIONp) {
                  forcerecompilationP = truevalueP;
                }
                else if (testValue000 == KWD_SYSTEMS_TWO_PASSp) {
                  twopassP = truevalueP;
                }
                else if (testValue000 == KWD_SYSTEMS_LOAD_SYSTEMp) {
                  loadsystemP = truevalueP;
                }
                else if (testValue000 == KWD_SYSTEMS_STARTUPp) {
                  startupsystemP = truevalueP;
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
        if (forcerecompilationP ||
            ((!system->loadedP) &&
             (forcetranslationP ||
              systemNeedsTranslationP(systemname, language)))) {
          loadPreprocessedFiles(systemname);
        }
        updatedsystemP = translateSystem(systemname, language, 6, KWD_SYSTEMS_TWO_PASSp, (twopassP ? TRUE_WRAPPER : FALSE_WRAPPER), KWD_SYSTEMS_FORCE_TRANSLATIONp, (forcetranslationP ? TRUE_WRAPPER : FALSE_WRAPPER), KWD_SYSTEMS_DEVELOPMENT_SETTINGSp, (developmentsettingsP ? TRUE_WRAPPER : FALSE_WRAPPER));
        if (loadsystemP &&
            loadSystem(systemname, language, 4, KWD_SYSTEMS_FORCE_RECOMPILATIONp, (forcerecompilationP ? TRUE_WRAPPER : FALSE_WRAPPER), KWD_SYSTEMS_STARTUPp, (startupsystemP ? TRUE_WRAPPER : FALSE_WRAPPER))) {
          updatedsystemP = TRUE;
        }
        return (updatedsystemP);
      }
    }
  }
}

BooleanWrapper* makeSystemEvaluatorWrapper(Cons* arguments) {
  return ((makeSystem(((StringWrapper*)(arguments->value))->wrapperValue, ((Keyword*)(arguments->rest->value)), arguments->rest->rest) ? TRUE_WRAPPER : FALSE_WRAPPER));
}

void runSystemFinalization(SystemDefinition* system) {
  { char* fnname = NULL;
    MethodSlot* finalizationfn = NULL;

    if (fnname != NULL) {
      finalizationfn = lookupFunctionByName(fnname);
    }
    if (((boolean)(finalizationfn))) {
      ((void  (*) ())finalizationfn->functionCode)();
    }
  }
}

Cons* systemDefinitionSourceFiles(SystemDefinition* system) {
  { Cons* files = copyConsList(system->files);

    if (oTRANSLATOROUTPUTLANGUAGEo.get() == KWD_SYSTEMS_COMMON_LISP) {
      files = files->subtract(system->javaOnlyFiles);
      files = files->subtract(system->cppOnlyFiles);
    }
    else if (oTRANSLATOROUTPUTLANGUAGEo.get() == KWD_SYSTEMS_JAVA) {
      files = files->subtract(system->lispOnlyFiles);
      files = files->subtract(system->cppOnlyFiles);
    }
    else if (oTRANSLATOROUTPUTLANGUAGEo.get() == KWD_SYSTEMS_CPP) {
      files = files->subtract(system->lispOnlyFiles);
      files = files->subtract(system->javaOnlyFiles);
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << oTRANSLATOROUTPUTLANGUAGEo.get() << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    return (files);
  }
}

Cons* filesPlusSystemStartup(Cons* files) {
  return (files->concatenate(consList(1, wrapString(systemStartupFileName(NULL))), 0));
}

Cons* systemDefinitionNativeFiles(SystemDefinition* system) {
  { Cons* files = copyConsList(system->files);

    if (oTRANSLATOROUTPUTLANGUAGEo.get() == KWD_SYSTEMS_COMMON_LISP) {
      files = files->unioN(system->lispOnlyFiles);
      if (oCURRENT_STELLA_FEATURESo.get()->membP(KWD_SYSTEMS_USE_COMMON_LISP_STRUCTS)) {
        files = cons(wrapString(clYieldStructClassFileName(system->name)), files);
      }
    }
    else if (oTRANSLATOROUTPUTLANGUAGEo.get() == KWD_SYSTEMS_JAVA) {
      files = files->unioN(system->javaOnlyFiles);
    }
    else if (oTRANSLATOROUTPUTLANGUAGEo.get() == KWD_SYSTEMS_CPP) {
      files = files->unioN(system->cppOnlyFiles);
    }
    else {
      { OutputStringStream* stream000 = newOutputStringStream();

        *(stream000->nativeStream) << "`" << oTRANSLATOROUTPUTLANGUAGEo.get() << "'" << " is not a valid case option";
        throw *newStellaException(stream000->theStringReader());
      }
    }
    return (files);
  }
}

boolean systemLoadedP(char* name) {
  // Return `true' if system `name' has been loaded.
  { boolean testValue000 = FALSE;

    if (stringEqualP(name, "STELLA")) {
      testValue000 = TRUE;
    }
    else {
      { boolean foundP000 = FALSE;

        { SystemDefinition* sys = NULL;
          Cons* iter000 = oSYSTEMDEFINITIONSo->theConsList;

          while (!(iter000 == NIL)) {
            sys = ((SystemDefinition*)(iter000->value));
            iter000 = iter000->rest;
            if (stringEqualP(sys->name, name) &&
                sys->loadedP) {
              foundP000 = TRUE;
              break;
            }
          }
        }
        testValue000 = foundP000;
      }
    }
    { boolean value000 = testValue000;

      return (value000);
    }
  }
}

void clearSystem(char* name) {
  // Clears out the system definition named `name'.  If
  // `name' is `null', then clear out all system definitions.  This function
  // is useful when changes have been made to the system definition, and one
  // wants to have it reloaded from the standard location in the file system.
  if (name == NULL) {
    oSYSTEMDEFINITIONSo = newList();
  }
  else {
    { SystemDefinition* value000 = NULL;

      { SystemDefinition* s = NULL;
        Cons* iter000 = oSYSTEMDEFINITIONSo->theConsList;

        while (!(iter000 == NIL)) {
          s = ((SystemDefinition*)(iter000->value));
          iter000 = iter000->rest;
          if (stringEqlP(s->name, name)) {
            value000 = s;
            break;
          }
        }
      }
      { SystemDefinition* sys = value000;

        if (((boolean)(sys))) {
          oSYSTEMDEFINITIONSo->remove(sys);
        }
      }
    }
  }
}

void loadPreprocessedFiles(char* systemname) {
  if ((!runningAsLispP()) ||
      (!((boolean)(getSystemDefinition(systemname)->preprocessedFiles)))) {
    return;
  }
  { 
    BIND_STELLA_SPECIAL(oTRANSLATOROUTPUTLANGUAGEo, Keyword*, KWD_SYSTEMS_COMMON_LISP);
    { 
      BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition*, getSystemDefinition(systemname));
      BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char*, (((boolean)(oCURRENTSYSTEMDEFINITIONo.get())) ? oCURRENTSYSTEMDEFINITIONo.get()->directory : NULL));
      if (((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
        {
          { Cons* preprocessedfiles = NIL;

            { StringWrapper* f = NULL;
              Cons* iter000 = oCURRENTSYSTEMDEFINITIONo.get()->preprocessedFiles;
              Cons* collect000 = NULL;

              while (!(iter000 == NIL)) {
                f = ((StringWrapper*)(iter000->value));
                iter000 = iter000->rest;
                if (!((boolean)(collect000))) {
                  {
                    collect000 = cons(wrapString(makeFileName(f->wrapperValue, KWD_SYSTEMS_STELLA, TRUE)), NIL);
                    if (preprocessedfiles == NIL) {
                      preprocessedfiles = collect000;
                    }
                    else {
                      addConsToEndOfConsList(preprocessedfiles, collect000);
                    }
                  }
                }
                else {
                  {
                    collect000->rest = cons(wrapString(makeFileName(f->wrapperValue, KWD_SYSTEMS_STELLA, TRUE)), NIL);
                    collect000 = collect000->rest;
                  }
                }
              }
            }
            { 
              BIND_STELLA_SPECIAL(oCURRENT_STELLA_FEATURESo, List*, oCURRENT_STELLA_FEATURESo.get()->copy());
              unsetStellaFeature(consList(1, KWD_SYSTEMS_WARN_ABOUT_UNDEFINED_METHODS));
              { Object* f = NULL;
                Cons* iter001 = preprocessedfiles;

                while (!(iter001 == NIL)) {
                  f = iter001->value;
                  iter001 = iter001->rest;
                  translateFile(((StringWrapper*)(f))->wrapperValue, oTRANSLATOROUTPUTLANGUAGEo.get(), FALSE);
                }
              }
            }
            compileAndLoadFiles(oCURRENTSYSTEMDEFINITIONo.get()->preprocessedFiles, oTRANSLATOROUTPUTLANGUAGEo.get(), FALSE);
            if (oCURRENT_STELLA_FEATURESo.get()->membP(KWD_SYSTEMS_USE_COMMON_LISP_STRUCTS)) {
              { StringWrapper* f = NULL;
                Cons* iter002 = oCURRENTSYSTEMDEFINITIONo.get()->preprocessedFiles;

                while (!(iter002 == NIL)) {
                  f = ((StringWrapper*)(iter002->value));
                  iter002 = iter002->rest;
                  deleteFile(makeFileName(f->wrapperValue, KWD_SYSTEMS_LISP, TRUE));
                }
              }
            }
            { Symbol* startupfn = NULL;
              Cons* iter003 = startupNamesFromFiles(oCURRENTSYSTEMDEFINITIONo.get()->preprocessedFiles);

              while (!(iter003 == NIL)) {
                startupfn = ((Symbol*)(iter003->value));
                iter003 = iter003->rest;
              }
            }
          }
        }
      }
      else {
        *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't find a system named " << "`" << systemname << "'" << std::endl << std::endl;
      }
    }
  }
}

boolean loadSystem(char* systemname, Keyword* language, int options, ...) {
  // Natively `language'-compile out-of-date translated files of system
  // `systemName' and then load them into the running system (this is only
  // supported/possible for Lisp at the moment).  Return true if at least one
  // file was compiled. The following keyword/value `options' are recognized:
  // 
  // `:force-recompilation?' (default false): if true, files will be compiled
  // whether or not their compilations are up-to-date.
  // 
  // `:startup?' (default true): if true, the system startup function will
  // be called once all files have been loaded.
  if (!runningAsLispP()) {
    return (FALSE);
  }
  language = ((Keyword*)(stellify(language)));
  { PropertyList* self000 = newPropertyList();

    { Cons* arglist000 = NIL;

      { Object* arg000 = NULL;
        va_list iter000;
        int iter000Count = options;
        Cons* collect000 = NULL;

        va_start(iter000, options);
        while ((iter000Count--) > 0) {
          arg000 = va_arg(iter000, Object*);
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(arg000, NIL);
              if (arglist000 == NIL) {
                arglist000 = collect000;
              }
              else {
                addConsToEndOfConsList(arglist000, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(arg000, NIL);
              collect000 = collect000->rest;
            }
          }
        }
        va_end(iter000);
      }
      self000->thePlist = arglist000;
    }
    { PropertyList* plist = self000;
      boolean forcerecompilationP = FALSE;
      boolean startupsystemP = TRUE;
      boolean translatedfileP = FALSE;

      vetOptions(plist, getQuotedTree("((:FORCE-RECOMPILATION? :STARTUP?) \"/STELLA\")", "/STELLA"));
      { Object* key = NULL;
        Object* value = NULL;
        Cons* iter001 = plist->thePlist;

        while (!(iter001 == NIL)) {
          key = iter001->value;
          value = iter001->rest->value;
          iter001 = iter001->rest->rest;
          { GeneralizedSymbol* testValue000 = ((GeneralizedSymbol*)(key));

            if (testValue000 == KWD_SYSTEMS_FORCE_RECOMPILATIONp) {
              forcerecompilationP = eqlP(value, TRUE_WRAPPER);
            }
            else if (testValue000 == KWD_SYSTEMS_STARTUPp) {
              startupsystemP = eqlP(value, TRUE_WRAPPER);
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
      { 
        BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONo, SystemDefinition*, getSystemDefinition(systemname));
        BIND_STELLA_SPECIAL(oCURRENTSYSTEMDEFINITIONSUBDIRECTORYo, char*, (((boolean)(oCURRENTSYSTEMDEFINITIONo.get())) ? oCURRENTSYSTEMDEFINITIONo.get()->directory : NULL));
        if (((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
          {
            if (oCURRENTSYSTEMDEFINITIONo.get()->loadedP) {
              std::cout << "Loading system " << "`" << systemname << "'" << " over top of itself." << std::endl << std::endl;
            }
            translatedfileP = compileAndLoadFiles(filesPlusSystemStartup(systemDefinitionNativeFiles(oCURRENTSYSTEMDEFINITIONo.get())), language, forcerecompilationP);
            oCURRENTSYSTEMDEFINITIONo.get()->loadedP = TRUE;
            if (startupsystemP) {
              runSystemStartupFunction(oCURRENTSYSTEMDEFINITIONo.get());
            }
          }
        }
        else {
          *(STANDARD_WARNING->nativeStream) << "Warning: " << "Can't find a system named " << "`" << systemname << "'" << std::endl << std::endl;
        }
      }
      return (translatedfileP);
    }
  }
}

boolean compileAndLoadFiles(Cons* files, Keyword* language, boolean forcerecompilationP) {
  if (language == KWD_SYSTEMS_COMMON_LISP) {
    return (clCompileAndLoadFiles(files, TRUE, forcerecompilationP));
  }
  else {
    std::cout << "'compile-and-load-files' NOT IMPLEMENTED FOR " << language << std::endl;
    return (FALSE);
  }
}

void runSystemStartupFunction(SystemDefinition* system) {
  if (!runningAsLispP()) {
    return;
  }
}

char* SystemDefinition::systemStartupFunctionName() {
  { SystemDefinition* system = this;

    return (stringSystemStartupFunctionName(system->name));
  }
}

char* stringSystemStartupFunctionName(char* systemname) {
  return (stringUpcase(stringConcatenate("startup-", systemname, 1, "-system")));
}

Symbol* systemStartupFunctionSymbol(SystemDefinition* system) {
  return (internSymbolInModule(system->systemStartupFunctionName(), getCardinalModule(system), TRUE));
}

Symbol* startupNameFromFile(char* file) {
  if (!probeFileP(makeFileName(file, KWD_SYSTEMS_STELLA, TRUE))) {
    { OutputStringStream* stream000 = newOutputStringStream();

      *(stream000->nativeStream) << "STELLA source file " << "`" << makeFileName(file, KWD_SYSTEMS_STELLA, TRUE) << "'" << " does not exist";
      throw *newStellaException(stream000->theStringReader());
    }
  }
  { char* longname = makeFileName(file, KWD_SYSTEMS_STELLA, TRUE);
    InputFileStream* inputstream = newInputFileStream(longname);
    Module* savedmodule = oMODULEo.get();
    boolean seeninmoduleP = FALSE;
    boolean unusedP = FALSE;
    Symbol* startupfnname = NULL;

    { 
      BIND_STELLA_SPECIAL(oTRANSIENTOBJECTSpo, boolean, TRUE);
      { Object* tree = NULL;
        SExpressionIterator* iter000 = sExpressions(inputstream);

        while (iter000->nextP()) {
          tree = iter000->value;
          { 
            BIND_STELLA_SPECIAL(oTRANSIENTOBJECTSpo, boolean, FALSE);
            if (safePrimaryType(tree) == SGT_SYSTEMS_STELLA_CONS) {
              { Object* tree000 = tree;
                Cons* tree = ((Cons*)(tree000));

                unusedP = handleInModuleTree(tree, seeninmoduleP, seeninmoduleP);
                unusedP = unusedP;
                if (seeninmoduleP) {
                  startupfnname = yieldStartupFunctionName(file);
                  savedmodule->changeModule();
                  inputstream->free();
                  return (startupfnname);
                }
              }
            }
            else {
            }
          }
        }
      }
    }
    *(STANDARD_WARNING->nativeStream) << "Warning: " << "Missing IN-MODULE declaration for file " << "`" << file << "'" << std::endl << std::endl;
    return (NULL);
  }
}

Cons* startupNamesFromFiles(Cons* files) {
  { Cons* names = NIL;

    { StringWrapper* f = NULL;
      Cons* iter000 = files;
      Cons* collect000 = NULL;

      while (!(iter000 == NIL)) {
        f = ((StringWrapper*)(iter000->value));
        iter000 = iter000->rest;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(startupNameFromFile(f->wrapperValue), NIL);
            if (names == NIL) {
              names = collect000;
            }
            else {
              addConsToEndOfConsList(names, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(startupNameFromFile(f->wrapperValue), NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    return (names);
  }
}

char* systemStartupFileName(SystemDefinition* system) {
  if (!((boolean)(system))) {
    system = oCURRENTSYSTEMDEFINITIONo.get();
  }
  if (((boolean)(system))) {
    return ("startup-system");
  }
  else {
    return (NULL);
  }
}

boolean systemStartupFileP(char* file) {
  if (file == NULL) {
    file = oCURRENTFILEo.get();
  }
  return ((file != NULL) &&
      stringEqlP(fileBaseName(file), systemStartupFileName(NULL)));
}

boolean systemStartedUpP(char* systemname, char* systemmodulename) {
  if (stringEqlP(stringUpcase(systemname), "STELLA")) {
    return (((boolean)(oMODULEo.get())));
  }
  if (!((boolean)(getStellaModule(systemmodulename, FALSE)))) {
    return (FALSE);
  }
  { Symbol* startupfunctionsymbol = lookupSymbolInModule(stringSystemStartupFunctionName(systemname), getStellaModule(systemmodulename, FALSE), TRUE);
    MethodSlot* startupfunction = (((boolean)(startupfunctionsymbol)) ? lookupFunction(startupfunctionsymbol) : ((MethodSlot*)(NULL)));

    return (((boolean)(startupfunction)) &&
        (startupfunction->functionCode != NULL));
  }
}

Cons* yieldStartupRequiredSystems(SystemDefinition* system) {
  { Cons* startupforms = NIL;

    { StringWrapper* systemname = NULL;
      Cons* iter000 = system->requiredSystems;
      Cons* collect000 = NULL;

      while (!(iter000 == NIL)) {
        systemname = ((StringWrapper*)(iter000->value));
        iter000 = iter000->rest;
        if (!((boolean)(collect000))) {
          {
            collect000 = cons(listO(4, SYM_SYSTEMS_STELLA_UNLESS, listO(3, SYM_SYSTEMS_STELLA_SYSTEM_STARTED_UPp, systemname, cons(wrapString(getCardinalModule(getSystemDefinition(systemname->wrapperValue))->moduleFullName), NIL)), cons(systemStartupFunctionSymbol(getSystemDefinition(systemname->wrapperValue)), NIL), NIL), NIL);
            if (startupforms == NIL) {
              startupforms = collect000;
            }
            else {
              addConsToEndOfConsList(startupforms, collect000);
            }
          }
        }
        else {
          {
            collect000->rest = cons(listO(4, SYM_SYSTEMS_STELLA_UNLESS, listO(3, SYM_SYSTEMS_STELLA_SYSTEM_STARTED_UPp, systemname, cons(wrapString(getCardinalModule(getSystemDefinition(systemname->wrapperValue))->moduleFullName), NIL)), cons(systemStartupFunctionSymbol(getSystemDefinition(systemname->wrapperValue)), NIL), NIL), NIL);
            collect000 = collect000->rest;
          }
        }
      }
    }
    return (listO(3, SYM_SYSTEMS_STELLA_STARTUP_TIME_PROGN, KWD_SYSTEMS_EARLY_INITS, startupforms->concatenate(NIL, 0)));
  }
}

Cons* collectStartupFormsFromSystemFile(SystemDefinition* system) {
  { char* systemfilename = makeSystemDefinitionFileName(system->name);
    InputFileStream* inputstream = newInputFileStream(systemfilename);
    Module* module = NULL;
    Cons* startupform = NULL;
    Cons* startupforms = NIL;

    { 
      BIND_STELLA_SPECIAL(oMODULEo, Module*, oMODULEo.get());
      BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
      { Object* tree = NULL;
        SExpressionIterator* iter000 = sExpressions(inputstream);
        Cons* collect000 = NULL;

        while (iter000->nextP()) {
          tree = iter000->value;
          startupform = NULL;
          if (safePrimaryType(tree) == SGT_SYSTEMS_STELLA_CONS) {
            { Object* tree000 = tree;
              Cons* tree = ((Cons*)(tree000));

              if (tree->value == SYM_SYSTEMS_STELLA_DEFMODULE) {
                evaluate(tree);
                module = getStellaModule(coerceToModuleName(tree->rest->value, TRUE), TRUE);
                if (((boolean)(module))) {
                  startupform = listO(4, SYM_SYSTEMS_STELLA_STARTUP_TIME_PROGN, KWD_SYSTEMS_MODULES, yieldDefineModule(module), NIL);
                }
              }
              if (tree->value == SYM_SYSTEMS_STELLA_IN_MODULE) {
                evaluate(tree);
              }
            }
          }
          else {
          }
          if (!((boolean)(startupform))) {
            continue;
          }
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(startupform, NIL);
              if (startupforms == NIL) {
                startupforms = collect000;
              }
              else {
                addConsToEndOfConsList(startupforms, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(startupform, NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
    }
    return (startupforms);
  }
}

void createSystemStartupFile(SystemDefinition* system) {
  if (!((boolean)(oCURRENTSYSTEMDEFINITIONo.get()))) {
    std::cout << "Must be within a system environment to create startup file " << std::endl << "   for system " << "`" << system->name << "'" << "." << std::endl << std::endl;
    return;
  }
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, getCardinalModule(system));
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    { char* file = makeFileName(systemStartupFileName(system), KWD_SYSTEMS_STELLA, TRUE);
      OutputFileStream* outputstream = newOutputFileStream(file);
      Cons* startupfnnames = NIL;
      Cons* startupforms = NIL;

      { StringWrapper* f = NULL;
        Cons* iter000 = systemDefinitionSourceFiles(system);
        Cons* collect000 = NULL;

        while (!(iter000 == NIL)) {
          f = ((StringWrapper*)(iter000->value));
          iter000 = iter000->rest;
          if (!((boolean)(collect000))) {
            {
              collect000 = cons(startupNameFromFile(f->wrapperValue), NIL);
              if (startupfnnames == NIL) {
                startupfnnames = collect000;
              }
              else {
                addConsToEndOfConsList(startupfnnames, collect000);
              }
            }
          }
          else {
            {
              collect000->rest = cons(startupNameFromFile(f->wrapperValue), NIL);
              collect000 = collect000->rest;
            }
          }
        }
      }
      clOutputFileHeader(outputstream, file, FALSE);
      startupforms = cons(listO(3, SYM_SYSTEMS_STELLA_IN_MODULE, wrapString(getCardinalModule(system)->moduleFullName), NIL), startupforms);
      startupforms = cons(listO(3, SYM_SYSTEMS_STELLA_DEFUN, systemStartupFunctionSymbol(system), listO(4, NIL, KWD_SYSTEMS_PUBLICp, SYM_SYSTEMS_STELLA_TRUE, NIL)), startupforms);
      if (stringEqlP(stringUpcase(system->name), "STELLA")) {
        startupforms = cons(listO(4, SYM_SYSTEMS_STELLA_STARTUP_TIME_PROGN, KWD_SYSTEMS_EARLY_INITS, listO(3, SYM_SYSTEMS_STELLA_STARTUP, SYM_SYSTEMS_STELLA_FALSE, NIL), NIL), startupforms);
      }
      else {
        if (((boolean)(system->requiredSystems))) {
          startupforms = cons(yieldStartupRequiredSystems(system), startupforms);
        }
        { Cons* form = NULL;
          Cons* iter001 = collectStartupFormsFromSystemFile(system);

          while (!(iter001 == NIL)) {
            form = ((Cons*)(iter001->value));
            iter001 = iter001->rest;
            startupforms = cons(form, startupforms);
          }
        }
        { Symbol* startupfn = NULL;
          Cons* iter002 = startupfnnames;

          while (!(iter002 == NIL)) {
            startupfn = ((Symbol*)(iter002->value));
            iter002 = iter002->rest;
            if (!((boolean)(lookupFunction(startupfn)))) {
              { 
                BIND_STELLA_SPECIAL(oMODULEo, Module*, startupfn->homeModule());
                BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
                defineMethodFromParseTree(listO(3, SYM_SYSTEMS_STELLA_DEFUN, startupfn, listO(4, NIL, KWD_SYSTEMS_PUBLICp, SYM_SYSTEMS_STELLA_TRUE, NIL)));
              }
            }
          }
        }
        { Cons* startupfncalls = NIL;

          { Symbol* startupfn = NULL;
            Cons* iter003 = startupfnnames;
            Cons* collect001 = NULL;

            while (!(iter003 == NIL)) {
              startupfn = ((Symbol*)(iter003->value));
              iter003 = iter003->rest;
              if (!((boolean)(collect001))) {
                {
                  collect001 = cons(cons(startupfn, NIL), NIL);
                  if (startupfncalls == NIL) {
                    startupfncalls = collect001;
                  }
                  else {
                    addConsToEndOfConsList(startupfncalls, collect001);
                  }
                }
              }
              else {
                {
                  collect001->rest = cons(cons(startupfn, NIL), NIL);
                  collect001 = collect001->rest;
                }
              }
            }
          }
          startupforms = cons(listO(4, SYM_SYSTEMS_STELLA_STARTUP_TIME_PROGN, listO(7, SYM_SYSTEMS_STELLA_FOREACH, SYM_SYSTEMS_STELLA_PHASE, SYM_SYSTEMS_STELLA_IN, listO(4, SYM_SYSTEMS_STELLA_INTERVAL, listO(3, SYM_SYSTEMS_STELLA_PHASE_TO_INTEGER, KWD_SYSTEMS_EARLY_INITS, NIL), listO(3, SYM_SYSTEMS_STELLA_PHASE_TO_INTEGER, KWD_SYSTEMS_FINAL, NIL), NIL), SYM_SYSTEMS_STELLA_DO, listO(4, SYM_SYSTEMS_STELLA_SETQ, SYM_SYSTEMS_STELLA_oSTARTUP_TIME_PHASEo, SYM_SYSTEMS_STELLA_PHASE, NIL), startupfncalls->concatenate(NIL, 0)), listO(4, SYM_SYSTEMS_STELLA_SETQ, SYM_SYSTEMS_STELLA_oSTARTUP_TIME_PHASEo, wrapInteger(999), NIL), NIL), startupforms);
        }
      }
      { 
        BIND_STELLA_SPECIAL(oPRINTREADABLYpo, boolean, TRUE);
        BIND_STELLA_SPECIAL(oPRINTPRETTYpo, boolean, TRUE);
        { Cons* form = NULL;
          Cons* iter004 = startupforms->reverse();

          while (!(iter004 == NIL)) {
            form = ((Cons*)(iter004->value));
            iter004 = iter004->rest;
            *(outputstream->nativeStream) << form << std::endl << std::endl;
          }
        }
      }
      outputstream->free();
    }
  }
}

void makeStella(boolean forcerecompilationP) {
  makeSystem("STELLA", KWD_SYSTEMS_COMMON_LISP, consList(4, KWD_SYSTEMS_FORCE_TRANSLATIONp, (forcerecompilationP ? TRUE_WRAPPER : FALSE_WRAPPER), KWD_SYSTEMS_DEVELOPMENT_SETTINGSp, FALSE_WRAPPER));
}

StringWrapper* parseConfigurationFileLine(char* line, Wrapper*& _Return1) {
  { int start = 0;
    int hashpos = stringPosition(line, '#', 0);
    int equalpos = stringPosition(line, '=', 0);
    int end = equalpos;
    int length = strlen(line);
    char* property = NULL;
    char* valuestring = NULL;
    Object* value = NULL;

    { boolean alwaysP000 = TRUE;

      { int i = NULL_INTEGER;
        int iter000 = 0;
        int upperBound000 = (((hashpos != NULL_INTEGER) ? hashpos : length)) - 1;

        while (iter000 <= upperBound000) {
          i = iter000;
          iter000 = iter000 + 1;
          if (!(oCHARACTER_TYPE_TABLEo[(int)(unsigned char) (line[i])] == KWD_SYSTEMS_WHITE_SPACE)) {
            alwaysP000 = FALSE;
            break;
          }
        }
      }
      if (alwaysP000) {
        _Return1 = NULL;
        return (NULL);
      }
    }
    if ((equalpos == NULL_INTEGER) ||
        (equalpos == 0)) {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal line in configuration file: " << "`" << line << "'" << std::endl;
      _Return1 = NULL;
      return (NULL);
    }
    while (oCHARACTER_TYPE_TABLEo[(int)(unsigned char) (line[start])] == KWD_SYSTEMS_WHITE_SPACE) {
      start = start + 1;
    }
    while (oCHARACTER_TYPE_TABLEo[(int)(unsigned char) (line[(end - 1)])] == KWD_SYSTEMS_WHITE_SPACE) {
      end = end - 1;
    }
    if (end <= start) {
      *(STANDARD_WARNING->nativeStream) << "Warning: " << "Illegal property in configuration file: " << "`" << line << "'" << std::endl;
      _Return1 = NULL;
      return (NULL);
    }
    property = stringSubsequence(line, start, end);
    valuestring = stringSubsequence(line, equalpos + 1, length);
    if (stringEqualP(valuestring, "TRUE")) {
      value = TRUE_WRAPPER;
    }
    else if (stringEqualP(valuestring, "FALSE")) {
      value = FALSE_WRAPPER;
    }
    else {
      try {
        { Surrogate* testValue000 = safePrimaryType(value = readSExpressionFromString(valuestring));

          if (subtypeOfIntegerP(testValue000) ||
              subtypeOfFloatP(testValue000)) {
          }
          else {
            value = wrapString(valuestring);
          }
        }
      }
      catch (ReadException ) {
        value = wrapString(valuestring);
      }
    }
    _Return1 = ((Wrapper*)(value));
    return (wrapString(property));
  }
}

KeyValueList* oSYSTEM_CONFIGURATION_TABLEo = NULL;

KeyValueList* loadConfigurationFile(char* file) {
  // Read a configuration `file' and return its content as a configuration table.
  // Also enter each property read into the global system configuration table.
  // Assumes Java-style property file syntax.  Each property name is represented
  // as a wrapped string and each value as a wrapped string/integer/float or boolean.
  { KeyValueList* configuration = newKeyValueList();

    { char* line = NULL;
      LineIterator* iter000 = lines(newInputFileStream(file));

      while (iter000->nextP()) {
        line = iter000->value;
        { StringWrapper* key = NULL;
          Wrapper* value = NULL;

          key = parseConfigurationFileLine(line, value);
          if (((boolean)(key))) {
            configuration->insertAt(key, value);
            oSYSTEM_CONFIGURATION_TABLEo->insertAt(key, value);
          }
        }
      }
    }
    return (configuration);
  }
}

Wrapper* lookupConfigurationProperty(char* property, Wrapper* defaultvalue, KeyValueList* configuration) {
  // Lookup `property' in `configuration' and return its value.
  // Use the global system configuration table if `configuration' is NULL.  Return
  // `defaultValue' if `property' is not defined.
  if (!((boolean)(configuration))) {
    configuration = oSYSTEM_CONFIGURATION_TABLEo;
  }
  { Wrapper* value = ((Wrapper*)(configuration->lookup(wrapString(property))));

    if (((boolean)(value))) {
      return (value);
    }
    else {
      return (defaultvalue);
    }
  }
}

Wrapper* setConfigurationProperty(char* property, Wrapper* value, KeyValueList* configuration) {
  // Set `property' in `configuration' to `value' and return it.
  // Use the global system configuration table if `configuration' is NULL.
  if (!((boolean)(configuration))) {
    configuration = oSYSTEM_CONFIGURATION_TABLEo;
  }
  configuration->insertAt(wrapString(property), value);
  return (value);
}

void configureStella(char* file) {
  // Perform STELLA run-time configuration.  If supplied, load the
  // configuration file `file' first which should be supplied with a physical pathname.
  if ((file != NULL) &&
      probeFileP(file)) {
    loadConfigurationFile(file);
  }
  defineLogicalHostProperty("PL", KWD_SYSTEMS_ROOT_DIRECTORY, lookupConfigurationProperty("PowerLoomRootDirectory", NULL, NULL));
}

void helpStartupSystems1() {
  {
    KWD_SYSTEMS_DEFINE = ((Keyword*)(internRigidSymbolWrtModule("DEFINE", NULL, 2)));
    SGT_SYSTEMS_STELLA_CONS = ((Surrogate*)(internRigidSymbolWrtModule("CONS", NULL, 1)));
    SYM_SYSTEMS_STELLA_IN_MODULE = ((Symbol*)(internRigidSymbolWrtModule("IN-MODULE", NULL, 0)));
    KWD_SYSTEMS_FINALIZE = ((Keyword*)(internRigidSymbolWrtModule("FINALIZE", NULL, 2)));
    SYM_SYSTEMS_STELLA_DEFMODULE = ((Symbol*)(internRigidSymbolWrtModule("DEFMODULE", NULL, 0)));
    SYM_SYSTEMS_STELLA_DEFSYSTEM = ((Symbol*)(internRigidSymbolWrtModule("DEFSYSTEM", NULL, 0)));
    SYM_SYSTEMS_STELLA_DEFCLASS = ((Symbol*)(internRigidSymbolWrtModule("DEFCLASS", NULL, 0)));
    SYM_SYSTEMS_STELLA_DEFSLOT = ((Symbol*)(internRigidSymbolWrtModule("DEFSLOT", NULL, 0)));
    SYM_SYSTEMS_STELLA_DEFUN = ((Symbol*)(internRigidSymbolWrtModule("DEFUN", NULL, 0)));
    SYM_SYSTEMS_STELLA_DEFMETHOD = ((Symbol*)(internRigidSymbolWrtModule("DEFMETHOD", NULL, 0)));
    KWD_SYSTEMS_DIRECTORY = ((Keyword*)(internRigidSymbolWrtModule("DIRECTORY", NULL, 2)));
    KWD_SYSTEMS_FILES = ((Keyword*)(internRigidSymbolWrtModule("FILES", NULL, 2)));
    KWD_SYSTEMS_REQUIRED_SYSTEMS = ((Keyword*)(internRigidSymbolWrtModule("REQUIRED-SYSTEMS", NULL, 2)));
    KWD_SYSTEMS_LISP_ONLY_FILES = ((Keyword*)(internRigidSymbolWrtModule("LISP-ONLY-FILES", NULL, 2)));
    KWD_SYSTEMS_CPP_ONLY_FILES = ((Keyword*)(internRigidSymbolWrtModule("CPP-ONLY-FILES", NULL, 2)));
    KWD_SYSTEMS_JAVA_ONLY_FILES = ((Keyword*)(internRigidSymbolWrtModule("JAVA-ONLY-FILES", NULL, 2)));
    KWD_SYSTEMS_PREPROCESSED_FILES = ((Keyword*)(internRigidSymbolWrtModule("PREPROCESSED-FILES", NULL, 2)));
    KWD_SYSTEMS_CARDINAL_MODULE = ((Keyword*)(internRigidSymbolWrtModule("CARDINAL-MODULE", NULL, 2)));
    KWD_SYSTEMS_ROOT_SOURCE_DIRECTORY = ((Keyword*)(internRigidSymbolWrtModule("ROOT-SOURCE-DIRECTORY", NULL, 2)));
    KWD_SYSTEMS_ROOT_NATIVE_DIRECTORY = ((Keyword*)(internRigidSymbolWrtModule("ROOT-NATIVE-DIRECTORY", NULL, 2)));
    KWD_SYSTEMS_ROOT_BINARY_DIRECTORY = ((Keyword*)(internRigidSymbolWrtModule("ROOT-BINARY-DIRECTORY", NULL, 2)));
    KWD_SYSTEMS_BANNER = ((Keyword*)(internRigidSymbolWrtModule("BANNER", NULL, 2)));
    KWD_SYSTEMS_COPYRIGHT_HEADER = ((Keyword*)(internRigidSymbolWrtModule("COPYRIGHT-HEADER", NULL, 2)));
    KWD_SYSTEMS_PRODUCTION_SETTINGS = ((Keyword*)(internRigidSymbolWrtModule("PRODUCTION-SETTINGS", NULL, 2)));
    KWD_SYSTEMS_DEVELOPMENT_SETTINGS = ((Keyword*)(internRigidSymbolWrtModule("DEVELOPMENT-SETTINGS", NULL, 2)));
    KWD_SYSTEMS_FINALIZATION_FUNCTION = ((Keyword*)(internRigidSymbolWrtModule("FINALIZATION-FUNCTION", NULL, 2)));
    KWD_SYSTEMS_JAVA = ((Keyword*)(internRigidSymbolWrtModule("JAVA", NULL, 2)));
    KWD_SYSTEMS_LISP = ((Keyword*)(internRigidSymbolWrtModule("LISP", NULL, 2)));
    KWD_SYSTEMS_CPP = ((Keyword*)(internRigidSymbolWrtModule("CPP", NULL, 2)));
    KWD_SYSTEMS_LISP_BINARY = ((Keyword*)(internRigidSymbolWrtModule("LISP-BINARY", NULL, 2)));
    SGT_SYSTEMS_STELLA_PROPERTY_LIST = ((Surrogate*)(internRigidSymbolWrtModule("PROPERTY-LIST", NULL, 1)));
    SGT_SYSTEMS_STELLA_LIST = ((Surrogate*)(internRigidSymbolWrtModule("LIST", NULL, 1)));
    KWD_SYSTEMS_COMMON_LISP = ((Keyword*)(internRigidSymbolWrtModule("COMMON-LISP", NULL, 2)));
    KWD_SYSTEMS_DEVELOPMENT_SETTINGSp = ((Keyword*)(internRigidSymbolWrtModule("DEVELOPMENT-SETTINGS?", NULL, 2)));
    KWD_SYSTEMS_PRODUCTION_SETTINGSp = ((Keyword*)(internRigidSymbolWrtModule("PRODUCTION-SETTINGS?", NULL, 2)));
    KWD_SYSTEMS_FORCE_TRANSLATIONp = ((Keyword*)(internRigidSymbolWrtModule("FORCE-TRANSLATION?", NULL, 2)));
    KWD_SYSTEMS_FORCE_RECOMPILATIONp = ((Keyword*)(internRigidSymbolWrtModule("FORCE-RECOMPILATION?", NULL, 2)));
    KWD_SYSTEMS_TWO_PASSp = ((Keyword*)(internRigidSymbolWrtModule("TWO-PASS?", NULL, 2)));
    KWD_SYSTEMS_LOAD_SYSTEMp = ((Keyword*)(internRigidSymbolWrtModule("LOAD-SYSTEM?", NULL, 2)));
    KWD_SYSTEMS_STARTUPp = ((Keyword*)(internRigidSymbolWrtModule("STARTUP?", NULL, 2)));
    KWD_SYSTEMS_USE_COMMON_LISP_STRUCTS = ((Keyword*)(internRigidSymbolWrtModule("USE-COMMON-LISP-STRUCTS", NULL, 2)));
    KWD_SYSTEMS_STELLA = ((Keyword*)(internRigidSymbolWrtModule("STELLA", NULL, 2)));
    KWD_SYSTEMS_WARN_ABOUT_UNDEFINED_METHODS = ((Keyword*)(internRigidSymbolWrtModule("WARN-ABOUT-UNDEFINED-METHODS", NULL, 2)));
    SYM_SYSTEMS_STELLA_UNLESS = ((Symbol*)(internRigidSymbolWrtModule("UNLESS", NULL, 0)));
    SYM_SYSTEMS_STELLA_SYSTEM_STARTED_UPp = ((Symbol*)(internRigidSymbolWrtModule("SYSTEM-STARTED-UP?", NULL, 0)));
    SYM_SYSTEMS_STELLA_STARTUP_TIME_PROGN = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-TIME-PROGN", NULL, 0)));
    KWD_SYSTEMS_EARLY_INITS = ((Keyword*)(internRigidSymbolWrtModule("EARLY-INITS", NULL, 2)));
    KWD_SYSTEMS_MODULES = ((Keyword*)(internRigidSymbolWrtModule("MODULES", NULL, 2)));
    KWD_SYSTEMS_PUBLICp = ((Keyword*)(internRigidSymbolWrtModule("PUBLIC?", NULL, 2)));
    SYM_SYSTEMS_STELLA_TRUE = ((Symbol*)(internRigidSymbolWrtModule("TRUE", NULL, 0)));
    SYM_SYSTEMS_STELLA_STARTUP = ((Symbol*)(internRigidSymbolWrtModule("STARTUP", NULL, 0)));
    SYM_SYSTEMS_STELLA_FALSE = ((Symbol*)(internRigidSymbolWrtModule("FALSE", NULL, 0)));
    SYM_SYSTEMS_STELLA_FOREACH = ((Symbol*)(internRigidSymbolWrtModule("FOREACH", NULL, 0)));
    SYM_SYSTEMS_STELLA_PHASE = ((Symbol*)(internRigidSymbolWrtModule("PHASE", NULL, 0)));
    SYM_SYSTEMS_STELLA_IN = ((Symbol*)(internRigidSymbolWrtModule("IN", NULL, 0)));
    SYM_SYSTEMS_STELLA_INTERVAL = ((Symbol*)(internRigidSymbolWrtModule("INTERVAL", NULL, 0)));
    SYM_SYSTEMS_STELLA_PHASE_TO_INTEGER = ((Symbol*)(internRigidSymbolWrtModule("PHASE-TO-INTEGER", NULL, 0)));
    KWD_SYSTEMS_FINAL = ((Keyword*)(internRigidSymbolWrtModule("FINAL", NULL, 2)));
    SYM_SYSTEMS_STELLA_DO = ((Symbol*)(internRigidSymbolWrtModule("DO", NULL, 0)));
    SYM_SYSTEMS_STELLA_SETQ = ((Symbol*)(internRigidSymbolWrtModule("SETQ", NULL, 0)));
  }
}

void startupSystems() {
  { 
    BIND_STELLA_SPECIAL(oMODULEo, Module*, oSTELLA_MODULEo);
    BIND_STELLA_SPECIAL(oCONTEXTo, Context*, oMODULEo.get());
    if (currentStartupTimePhaseP(2)) {
      helpStartupSystems1();
      SYM_SYSTEMS_STELLA_oSTARTUP_TIME_PHASEo = ((Symbol*)(internRigidSymbolWrtModule("*STARTUP-TIME-PHASE*", NULL, 0)));
      KWD_SYSTEMS_WHITE_SPACE = ((Keyword*)(internRigidSymbolWrtModule("WHITE-SPACE", NULL, 2)));
      SYM_SYSTEMS_STELLA_CONFIGURATION_TABLE = ((Symbol*)(internRigidSymbolWrtModule("CONFIGURATION-TABLE", NULL, 0)));
      KWD_SYSTEMS_ROOT_DIRECTORY = ((Keyword*)(internRigidSymbolWrtModule("ROOT-DIRECTORY", NULL, 2)));
      SYM_SYSTEMS_STELLA_STARTUP_SYSTEMS = ((Symbol*)(internRigidSymbolWrtModule("STARTUP-SYSTEMS", NULL, 0)));
      SYM_SYSTEMS_STELLA_METHOD_STARTUP_CLASSNAME = ((Symbol*)(internRigidSymbolWrtModule("METHOD-STARTUP-CLASSNAME", NULL, 0)));
    }
    if (currentStartupTimePhaseP(4)) {
      oSYSTEMDEFINITIONSo = newList();
      oSYSTEM_CONFIGURATION_TABLEo = newKeyValueList();
    }
    if (currentStartupTimePhaseP(5)) {
      defineStellaTypeFromStringifiedSource("(DEFTYPE CONFIGURATION-TABLE (KEY-VALUE-LIST OF STRING-WRAPPER WRAPPER))");
    }
    if (currentStartupTimePhaseP(6)) {
      finalizeClasses();
    }
    if (currentStartupTimePhaseP(7)) {
      defineFunctionObject("EVALUATE-COMMAND", "(DEFUN (EVALUATE-COMMAND OBJECT) ((COMMAND OBJECT) (FINALIZE? BOOLEAN)))", ((cpp_function_code)(&evaluateCommand)), NULL);
      defineFunctionObject("LOAD-FILE", "(DEFUN LOAD-FILE ((FILE STRING)) :DOCUMENTATION \"Read STELLA commands from `file' and evaluate them.\nThe file should begin with an `in-module' declaration that specifies\nthe module within which all remaining commands are to be evaluated\nThe remaining commands are evaluated one-by-one, applying the function\n`evaluate' to each of them.\" :COMMAND? TRUE :PUBLIC? TRUE)", ((cpp_function_code)(&loadFile)), ((cpp_function_code)(&loadFileEvaluatorWrapper)));
      defineFunctionObject("MAKE-SYSTEM-DEFINITION-FILE-NAME", "(DEFUN (MAKE-SYSTEM-DEFINITION-FILE-NAME FILE-NAME) ((NAME STRING)))", ((cpp_function_code)(&makeSystemDefinitionFileName)), NULL);
      defineFunctionObject("PARSE-LIST-OF-FILE-PATHS", "(DEFUN (PARSE-LIST-OF-FILE-PATHS (CONS OF STRING-WRAPPER)) ((FILES CONS)))", ((cpp_function_code)(&parseListOfFilePaths)), NULL);
      defineFunctionObject("DEFINE-SYSTEM", "(DEFUN (DEFINE-SYSTEM SYSTEM-DEFINITION) ((NAME OBJECT) (OPTIONS CONS)))", ((cpp_function_code)(&defineSystem)), NULL);
      defineFunctionObject("DEFSYSTEM", "(DEFUN (DEFSYSTEM SYSTEM-DEFINITION) ((NAME SYMBOL) |&REST| (OPTIONS OBJECT)) :COMMAND? TRUE :EVALUATE-ARGUMENTS? FALSE :PUBLIC? TRUE :DOCUMENTATION \"Define a system of files that collectively define\na Stella application.\n   Required options are:\n   :directory -- the path from the Stella root directory to the directory\n                 containing the system files.  Can be a string or a list\n                 of strings (do not include directory separators).\n   :files -- a list of files in the system, containing strings and lists\n             of strings; the latter defines exploded paths to files\n             in subdirectories.\n   Optional options are:\n   :required-systems -- a list of systems (strings) that should be loaded\n                        prior to loading this system.\n   :cardinal-module -- the name (a string) of the principal module for this\n                       system.\n   :copyright-header -- string with a header for inclusion into all translated\n                        files produced by Stella.\n   :lisp-only-files  -- Like the :files keyword, but these are only included\n   :cpp-only-files      in the translation for the specific language, namely\n   :java-only-files     Common Lisp, C++ or Java\")", ((cpp_function_code)(&defsystem)), ((cpp_function_code)(&defsystemEvaluatorWrapper)));
      defineFunctionObject("GET-SYSTEM-DEFINITION", "(DEFUN (GET-SYSTEM-DEFINITION SYSTEM-DEFINITION) ((NAME STRING)))", ((cpp_function_code)(&getSystemDefinition)), NULL);
      defineFunctionObject("GET-CARDINAL-MODULE", "(DEFUN (GET-CARDINAL-MODULE MODULE) ((SYSTEM SYSTEM-DEFINITION)))", ((cpp_function_code)(&getCardinalModule)), NULL);
      defineFunctionObject("HELP-GET-SYSTEM-FILES", "(DEFUN HELP-GET-SYSTEM-FILES ((FILENAME FILE-NAME) (COLLECTION LIST) (PROBEFILE? BOOLEAN)))", ((cpp_function_code)(&helpGetSystemFiles)), NULL);
      defineFunctionObject("GET-SYSTEM-FILES", "(DEFUN (GET-SYSTEM-FILES (LIST OF STRING-WRAPPER)) ((SYSTEM SYSTEM-DEFINITION) (TYPE KEYWORD) (PROBEFILES? BOOLEAN)))", ((cpp_function_code)(&getSystemFiles)), NULL);
      defineFunctionObject("CLEAN-SYSTEM", "(DEFUN CLEAN-SYSTEM ((SYSTEMNAME STRING)))", ((cpp_function_code)(&cleanSystem)), NULL);
      defineFunctionObject("COMPUTE-OPTIMIZATION-LEVELS", "(DEFUN COMPUTE-OPTIMIZATION-LEVELS ((SYSTEM SYSTEM-DEFINITION) (PRODUCTIONMODE? BOOLEAN)))", ((cpp_function_code)(&computeOptimizationLevels)), NULL);
      defineFunctionObject("LISP-KEYWORD-TO-STELLA-KEYWORD", "(DEFUN (LISP-KEYWORD-TO-STELLA-KEYWORD KEYWORD) ((KEY KEYWORD)))", ((cpp_function_code)(&lispKeywordToStellaKeyword)), NULL);
      defineFunctionObject("VET-OPTIONS", "(DEFUN (VET-OPTIONS PROPERTY-LIST) ((PLIST OBJECT) (LEGALOPTIONS (CONS OF KEYWORD))))", ((cpp_function_code)(&vetOptions)), NULL);
      defineFunctionObject("MAKE-SYSTEM", "(DEFUN (MAKE-SYSTEM BOOLEAN) ((SYSTEMNAME STRING) (LANGUAGE KEYWORD) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Translate all out-of-date files of system `systemName'\ninto `language' and then compile and load them (the latter is only possible\nfor Lisp right now).  The following keyword/value `options' are recognized:\n\n`:two-pass?': if true, all files will be scanned twice, once to\nload the signatures of objects defined in them, and once to actually\ntranslate the definitions.  Otherwise, the translator will make one pass in\nthe case that the system is already loaded (and is being remade), and two\npasses otherwise.\n\n`:development-settings?' (default false): if true translation will favor\nsafe, readable and debuggable code over efficiency (according to the value\nof `:development-settings' on the system definition).  If false, efficiency\nwill be favored instead (according to the value of `:production-settings'\non the system definition).\n\n`:production-settings?' (default true): inverse to `:development-settings?'.\n\n`:force-translation?' (default false): if true, files will be translated\nwhether or not their translations are up-to-date.\n\n`:force-recompilation?' (default false): if true, translated files will be\nrecompiled whether or not their compilations are up-to-date (only supported\nin Lisp right now).\n\n`:load-system?' (default true): if true, compiled files will be loaded into\nthe current STELLA image (only supported in Lisp right now).\n\n`:startup?' (default true): if true, the system startup function will\nbe called once all files have been loaded.\" :PUBLIC? TRUE :COMMAND? TRUE)", ((cpp_function_code)(&makeSystem)), ((cpp_function_code)(&makeSystemEvaluatorWrapper)));
      defineFunctionObject("RUN-SYSTEM-FINALIZATION", "(DEFUN RUN-SYSTEM-FINALIZATION ((SYSTEM SYSTEM-DEFINITION)))", ((cpp_function_code)(&runSystemFinalization)), NULL);
      defineFunctionObject("SYSTEM-DEFINITION-SOURCE-FILES", "(DEFUN (SYSTEM-DEFINITION-SOURCE-FILES (CONS OF STRING-WRAPPER)) ((SYSTEM SYSTEM-DEFINITION)))", ((cpp_function_code)(&systemDefinitionSourceFiles)), NULL);
      defineFunctionObject("FILES-PLUS-SYSTEM-STARTUP", "(DEFUN (FILES-PLUS-SYSTEM-STARTUP (CONS OF STRING-WRAPPER)) ((FILES (CONS OF STRING-WRAPPER))))", ((cpp_function_code)(&filesPlusSystemStartup)), NULL);
      defineFunctionObject("SYSTEM-DEFINITION-NATIVE-FILES", "(DEFUN (SYSTEM-DEFINITION-NATIVE-FILES (CONS OF STRING-WRAPPER)) ((SYSTEM SYSTEM-DEFINITION)))", ((cpp_function_code)(&systemDefinitionNativeFiles)), NULL);
      defineFunctionObject("SYSTEM-LOADED?", "(DEFUN (SYSTEM-LOADED? BOOLEAN) ((NAME STRING)) :DOCUMENTATION \"Return `true' if system `name' has been loaded.\" :PUBLIC? TRUE)", ((cpp_function_code)(&systemLoadedP)), NULL);
      defineFunctionObject("CLEAR-SYSTEM", "(DEFUN CLEAR-SYSTEM ((NAME STRING)) :DOCUMENTATION \"Clears out the system definition named `name'.  If\n`name' is `null', then clear out all system definitions.  This function\nis useful when changes have been made to the system definition, and one\nwants to have it reloaded from the standard location in the file system.\" :PUBLIC? TRUE)", ((cpp_function_code)(&clearSystem)), NULL);
      defineFunctionObject("LOAD-PREPROCESSED-FILES", "(DEFUN LOAD-PREPROCESSED-FILES ((SYSTEMNAME STRING)))", ((cpp_function_code)(&loadPreprocessedFiles)), NULL);
      defineFunctionObject("LOAD-SYSTEM", "(DEFUN (LOAD-SYSTEM BOOLEAN) ((SYSTEMNAME STRING) (LANGUAGE KEYWORD) |&REST| (OPTIONS OBJECT)) :DOCUMENTATION \"Natively `language'-compile out-of-date translated files of system\n`systemName' and then load them into the running system (this is only\nsupported/possible for Lisp at the moment).  Return true if at least one\nfile was compiled. The following keyword/value `options' are recognized:\n\n`:force-recompilation?' (default false): if true, files will be compiled\nwhether or not their compilations are up-to-date.\n\n`:startup?' (default true): if true, the system startup function will\nbe called once all files have been loaded.\" :PUBLIC? TRUE)", ((cpp_function_code)(&loadSystem)), NULL);
      defineFunctionObject("COMPILE-AND-LOAD-FILES", "(DEFUN (COMPILE-AND-LOAD-FILES BOOLEAN) ((FILES (CONS OF STRING-WRAPPER)) (LANGUAGE KEYWORD) (FORCERECOMPILATION? BOOLEAN)))", ((cpp_function_code)(&compileAndLoadFiles)), NULL);
      defineFunctionObject("RUN-SYSTEM-STARTUP-FUNCTION", "(DEFUN RUN-SYSTEM-STARTUP-FUNCTION ((SYSTEM SYSTEM-DEFINITION)))", ((cpp_function_code)(&runSystemStartupFunction)), NULL);
      defineMethodObject("(DEFMETHOD (SYSTEM-STARTUP-FUNCTION-NAME STRING) ((SYSTEM SYSTEM-DEFINITION)))", ((cpp_method_code)(&SystemDefinition::systemStartupFunctionName)), ((cpp_method_code)(NULL)));
      defineMethodObject("(DEFMETHOD (SYSTEM-STARTUP-FUNCTION-NAME STRING) ((SYSTEMNAME STRING)))", ((cpp_method_code)(NULL)), ((cpp_method_code)(NULL)));
      defineFunctionObject("SYSTEM-STARTUP-FUNCTION-SYMBOL", "(DEFUN (SYSTEM-STARTUP-FUNCTION-SYMBOL SYMBOL) ((SYSTEM SYSTEM-DEFINITION)))", ((cpp_function_code)(&systemStartupFunctionSymbol)), NULL);
      defineFunctionObject("STARTUP-NAME-FROM-FILE", "(DEFUN (STARTUP-NAME-FROM-FILE SYMBOL) ((FILE FILE-NAME)))", ((cpp_function_code)(&startupNameFromFile)), NULL);
      defineFunctionObject("STARTUP-NAMES-FROM-FILES", "(DEFUN (STARTUP-NAMES-FROM-FILES (CONS OF SYMBOL)) ((FILES (CONS OF STRING-WRAPPER))))", ((cpp_function_code)(&startupNamesFromFiles)), NULL);
      defineFunctionObject("SYSTEM-STARTUP-FILE-NAME", "(DEFUN (SYSTEM-STARTUP-FILE-NAME STRING) ((SYSTEM SYSTEM-DEFINITION)))", ((cpp_function_code)(&systemStartupFileName)), NULL);
      defineFunctionObject("SYSTEM-STARTUP-FILE?", "(DEFUN (SYSTEM-STARTUP-FILE? BOOLEAN) ((FILE FILE-NAME)))", ((cpp_function_code)(&systemStartupFileP)), NULL);
      defineFunctionObject("SYSTEM-STARTED-UP?", "(DEFUN (SYSTEM-STARTED-UP? BOOLEAN) ((SYSTEMNAME STRING) (SYSTEMMODULENAME STRING)))", ((cpp_function_code)(&systemStartedUpP)), NULL);
      defineFunctionObject("YIELD-STARTUP-REQUIRED-SYSTEMS", "(DEFUN (YIELD-STARTUP-REQUIRED-SYSTEMS CONS) ((SYSTEM SYSTEM-DEFINITION)))", ((cpp_function_code)(&yieldStartupRequiredSystems)), NULL);
      defineFunctionObject("COLLECT-STARTUP-FORMS-FROM-SYSTEM-FILE", "(DEFUN (COLLECT-STARTUP-FORMS-FROM-SYSTEM-FILE (CONS OF CONS)) ((SYSTEM SYSTEM-DEFINITION)))", ((cpp_function_code)(&collectStartupFormsFromSystemFile)), NULL);
      defineFunctionObject("CREATE-SYSTEM-STARTUP-FILE", "(DEFUN CREATE-SYSTEM-STARTUP-FILE ((SYSTEM SYSTEM-DEFINITION)))", ((cpp_function_code)(&createSystemStartupFile)), NULL);
      defineFunctionObject("MAKE-STELLA", "(DEFUN MAKE-STELLA ((FORCERECOMPILATION? BOOLEAN)))", ((cpp_function_code)(&makeStella)), NULL);
      defineFunctionObject("PARSE-CONFIGURATION-FILE-LINE", "(DEFUN (PARSE-CONFIGURATION-FILE-LINE STRING-WRAPPER WRAPPER) ((LINE STRING)))", ((cpp_function_code)(&parseConfigurationFileLine)), NULL);
      defineFunctionObject("LOAD-CONFIGURATION-FILE", "(DEFUN (LOAD-CONFIGURATION-FILE CONFIGURATION-TABLE) ((FILE FILE-NAME)) :DOCUMENTATION \"Read a configuration `file' and return its content as a configuration table.\nAlso enter each property read into the global system configuration table.\nAssumes Java-style property file syntax.  Each property name is represented\nas a wrapped string and each value as a wrapped string/integer/float or boolean.\" :PUBLIC? TRUE)", ((cpp_function_code)(&loadConfigurationFile)), NULL);
      defineFunctionObject("LOOKUP-CONFIGURATION-PROPERTY", "(DEFUN (LOOKUP-CONFIGURATION-PROPERTY WRAPPER) ((PROPERTY STRING) (DEFAULTVALUE WRAPPER) (CONFIGURATION CONFIGURATION-TABLE)) :DOCUMENTATION \"Lookup `property' in `configuration' and return its value.\nUse the global system configuration table if `configuration' is NULL.  Return\n`defaultValue' if `property' is not defined.\" :PUBLIC? TRUE)", ((cpp_function_code)(&lookupConfigurationProperty)), NULL);
      defineFunctionObject("SET-CONFIGURATION-PROPERTY", "(DEFUN (SET-CONFIGURATION-PROPERTY WRAPPER) ((PROPERTY STRING) (VALUE WRAPPER) (CONFIGURATION CONFIGURATION-TABLE)) :DOCUMENTATION \"Set `property' in `configuration' to `value' and return it.\nUse the global system configuration table if `configuration' is NULL.\" :PUBLIC? TRUE)", ((cpp_function_code)(&setConfigurationProperty)), NULL);
      defineFunctionObject("CONFIGURE-STELLA", "(DEFUN CONFIGURE-STELLA ((FILE FILE-NAME)) :DOCUMENTATION \"Perform STELLA run-time configuration.  If supplied, load the\nconfiguration file `file' first which should be supplied with a physical pathname.\" :PUBLIC? TRUE)", ((cpp_function_code)(&configureStella)), NULL);
      defineFunctionObject("STARTUP-SYSTEMS", "(DEFUN STARTUP-SYSTEMS () :PUBLIC? TRUE)", ((cpp_function_code)(&startupSystems)), NULL);
      { MethodSlot* function = lookupFunction(SYM_SYSTEMS_STELLA_STARTUP_SYSTEMS);

        setDynamicSlotValue(function->dynamicSlots, SYM_SYSTEMS_STELLA_METHOD_STARTUP_CLASSNAME, wrapString("_Startup-Systems"), NULL_STRING_WRAPPER);
      }
    }
    if (currentStartupTimePhaseP(8)) {
      finalizeSlots();
      cleanupUnfinalizedClasses();
    }
    if (currentStartupTimePhaseP(9)) {
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SYSTEMDEFINITIONS* (LIST OF SYSTEM-DEFINITION) (NEW LIST) :DOCUMENTATION \"A list of all defined systems.\")");
      defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SYSTEM-CONFIGURATION-TABLE* CONFIGURATION-TABLE (NEW CONFIGURATION-TABLE))");
    }
  }
}

Keyword* KWD_SYSTEMS_DEFINE = NULL;

Surrogate* SGT_SYSTEMS_STELLA_CONS = NULL;

Symbol* SYM_SYSTEMS_STELLA_IN_MODULE = NULL;

Keyword* KWD_SYSTEMS_FINALIZE = NULL;

Symbol* SYM_SYSTEMS_STELLA_DEFMODULE = NULL;

Symbol* SYM_SYSTEMS_STELLA_DEFSYSTEM = NULL;

Symbol* SYM_SYSTEMS_STELLA_DEFCLASS = NULL;

Symbol* SYM_SYSTEMS_STELLA_DEFSLOT = NULL;

Symbol* SYM_SYSTEMS_STELLA_DEFUN = NULL;

Symbol* SYM_SYSTEMS_STELLA_DEFMETHOD = NULL;

Keyword* KWD_SYSTEMS_DIRECTORY = NULL;

Keyword* KWD_SYSTEMS_FILES = NULL;

Keyword* KWD_SYSTEMS_REQUIRED_SYSTEMS = NULL;

Keyword* KWD_SYSTEMS_LISP_ONLY_FILES = NULL;

Keyword* KWD_SYSTEMS_CPP_ONLY_FILES = NULL;

Keyword* KWD_SYSTEMS_JAVA_ONLY_FILES = NULL;

Keyword* KWD_SYSTEMS_PREPROCESSED_FILES = NULL;

Keyword* KWD_SYSTEMS_CARDINAL_MODULE = NULL;

Keyword* KWD_SYSTEMS_ROOT_SOURCE_DIRECTORY = NULL;

Keyword* KWD_SYSTEMS_ROOT_NATIVE_DIRECTORY = NULL;

Keyword* KWD_SYSTEMS_ROOT_BINARY_DIRECTORY = NULL;

Keyword* KWD_SYSTEMS_BANNER = NULL;

Keyword* KWD_SYSTEMS_COPYRIGHT_HEADER = NULL;

Keyword* KWD_SYSTEMS_PRODUCTION_SETTINGS = NULL;

Keyword* KWD_SYSTEMS_DEVELOPMENT_SETTINGS = NULL;

Keyword* KWD_SYSTEMS_FINALIZATION_FUNCTION = NULL;

Keyword* KWD_SYSTEMS_JAVA = NULL;

Keyword* KWD_SYSTEMS_LISP = NULL;

Keyword* KWD_SYSTEMS_CPP = NULL;

Keyword* KWD_SYSTEMS_LISP_BINARY = NULL;

Surrogate* SGT_SYSTEMS_STELLA_PROPERTY_LIST = NULL;

Surrogate* SGT_SYSTEMS_STELLA_LIST = NULL;

Keyword* KWD_SYSTEMS_COMMON_LISP = NULL;

Keyword* KWD_SYSTEMS_DEVELOPMENT_SETTINGSp = NULL;

Keyword* KWD_SYSTEMS_PRODUCTION_SETTINGSp = NULL;

Keyword* KWD_SYSTEMS_FORCE_TRANSLATIONp = NULL;

Keyword* KWD_SYSTEMS_FORCE_RECOMPILATIONp = NULL;

Keyword* KWD_SYSTEMS_TWO_PASSp = NULL;

Keyword* KWD_SYSTEMS_LOAD_SYSTEMp = NULL;

Keyword* KWD_SYSTEMS_STARTUPp = NULL;

Keyword* KWD_SYSTEMS_USE_COMMON_LISP_STRUCTS = NULL;

Keyword* KWD_SYSTEMS_STELLA = NULL;

Keyword* KWD_SYSTEMS_WARN_ABOUT_UNDEFINED_METHODS = NULL;

Symbol* SYM_SYSTEMS_STELLA_UNLESS = NULL;

Symbol* SYM_SYSTEMS_STELLA_SYSTEM_STARTED_UPp = NULL;

Symbol* SYM_SYSTEMS_STELLA_STARTUP_TIME_PROGN = NULL;

Keyword* KWD_SYSTEMS_EARLY_INITS = NULL;

Keyword* KWD_SYSTEMS_MODULES = NULL;

Keyword* KWD_SYSTEMS_PUBLICp = NULL;

Symbol* SYM_SYSTEMS_STELLA_TRUE = NULL;

Symbol* SYM_SYSTEMS_STELLA_STARTUP = NULL;

Symbol* SYM_SYSTEMS_STELLA_FALSE = NULL;

Symbol* SYM_SYSTEMS_STELLA_FOREACH = NULL;

Symbol* SYM_SYSTEMS_STELLA_PHASE = NULL;

Symbol* SYM_SYSTEMS_STELLA_IN = NULL;

Symbol* SYM_SYSTEMS_STELLA_INTERVAL = NULL;

Symbol* SYM_SYSTEMS_STELLA_PHASE_TO_INTEGER = NULL;

Keyword* KWD_SYSTEMS_FINAL = NULL;

Symbol* SYM_SYSTEMS_STELLA_DO = NULL;

Symbol* SYM_SYSTEMS_STELLA_SETQ = NULL;

Symbol* SYM_SYSTEMS_STELLA_oSTARTUP_TIME_PHASEo = NULL;

Keyword* KWD_SYSTEMS_WHITE_SPACE = NULL;

Symbol* SYM_SYSTEMS_STELLA_CONFIGURATION_TABLE = NULL;

Keyword* KWD_SYSTEMS_ROOT_DIRECTORY = NULL;

Symbol* SYM_SYSTEMS_STELLA_STARTUP_SYSTEMS = NULL;

Symbol* SYM_SYSTEMS_STELLA_METHOD_STARTUP_CLASSNAME = NULL;

} // end of namespace stella
