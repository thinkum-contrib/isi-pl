//  -*- Mode: C++ -*-

// systems.hh

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
| The Original Code is the STELLA Programming Language.                      |
|                                                                            |
| The Initial Developer of the Original Code is                              |
| UNIVERSITY OF SOUTHERN CALIFORNIA, INFORMATION SCIENCES INSTITUTE          |
| 4676 Admiralty Way, Marina Del Rey, California 90292, U.S.A.               |
|                                                                            |
| Portions created by the Initial Developer are Copyright (C) 1996-2006      |
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
+---------------------------- END LICENSE BLOCK -----------------------------+
*/



namespace stella {

// Global declarations:
extern List* oSYSTEMDEFINITIONSo;
extern KeyValueList* oSYSTEM_CONFIGURATION_TABLEo;

// Function signatures:
Object* evaluateCommand(Object* command, boolean finalizeP);
void loadFile(char* file);
void loadFileEvaluatorWrapper(Cons* arguments);
char* makeSystemDefinitionFileName(char* name);
Cons* parseListOfFilePaths(Cons* files);
SystemDefinition* defineSystem(Object* name, Cons* options);
SystemDefinition* defsystem(Symbol* name, Cons* options);
SystemDefinition* defsystemEvaluatorWrapper(Cons* arguments);
SystemDefinition* getSystemDefinition(char* name);
Module* getCardinalModule(SystemDefinition* system);
void helpGetSystemFiles(char* filename, List* collection, boolean probefileP);
List* getSystemFiles(SystemDefinition* system, Keyword* type, boolean probefilesP);
void cleanSystem(char* systemname);
void computeOptimizationLevels(SystemDefinition* system, boolean productionmodeP);
Keyword* lispKeywordToStellaKeyword(Keyword* key);
PropertyList* vetOptions(Object* plist, Cons* legaloptions);
boolean makeSystem(char* systemname, Keyword* language, Cons* options);
BooleanWrapper* makeSystemEvaluatorWrapper(Cons* arguments);
void runSystemFinalization(SystemDefinition* system);
Cons* systemDefinitionSourceFiles(SystemDefinition* system);
Cons* filesPlusSystemStartup(Cons* files);
Cons* systemDefinitionNativeFiles(SystemDefinition* system);
boolean systemLoadedP(char* name);
void clearSystem(char* name);
void loadPreprocessedFiles(char* systemname);
boolean loadSystem(char* systemname, Keyword* language, int options, ...);
boolean compileAndLoadFiles(Cons* files, Keyword* language, boolean forcerecompilationP);
void runSystemStartupFunction(SystemDefinition* system);
char* stringSystemStartupFunctionName(char* systemname);
Symbol* systemStartupFunctionSymbol(SystemDefinition* system);
Symbol* startupNameFromFile(char* file);
Cons* startupNamesFromFiles(Cons* files);
char* systemStartupFileName(SystemDefinition* system);
boolean systemStartupFileP(char* file);
boolean systemStartedUpP(char* systemname, char* systemmodulename);
Cons* yieldStartupRequiredSystems(SystemDefinition* system);
Cons* collectStartupFormsFromSystemFile(SystemDefinition* system);
void createSystemStartupFile(SystemDefinition* system);
List* helpAllRequiredSystems(char* systemName, List* found);
Cons* allRequiredSystems(char* systemName);
void makeStella(boolean forcerecompilationP);
StringWrapper* parseConfigurationFileLine(char* line, Wrapper*& _Return1, Keyword*& _Return2);
KeyValueList* loadConfigurationFile(char* file);
void saveConfigurationValue(OutputStream* stream, Object* value);
void saveConfigurationFile(KeyValueList* table, char* file, char* title);
Object* lookupConfigurationProperty(char* property, Wrapper* defaultvalue, KeyValueList* configuration);
Cons* lookupConfigurationPropertyValues(char* property, Object* defaultvalue, KeyValueList* configuration);
Object* setConfigurationProperty(char* property, Object* value, KeyValueList* configuration);
Object* addConfigurationProperty(char* property, Object* value, KeyValueList* configuration);
Object* clearConfigurationProperty(char* property, KeyValueList* configuration);
Object* removeConfigurationProperty(char* property, Object* value, KeyValueList* configuration);
void configureStella(char* file);
void helpStartupSystems1();
void helpStartupSystems2();
void startupSystems();

// Auxiliary global declarations:
extern Keyword* KWD_SYSTEMS_DEFINE;
extern Surrogate* SGT_SYSTEMS_STELLA_CONS;
extern Symbol* SYM_SYSTEMS_STELLA_IN_MODULE;
extern Keyword* KWD_SYSTEMS_FINALIZE;
extern Symbol* SYM_SYSTEMS_STELLA_DEFMODULE;
extern Symbol* SYM_SYSTEMS_STELLA_DEFSYSTEM;
extern Symbol* SYM_SYSTEMS_STELLA_DEFCLASS;
extern Symbol* SYM_SYSTEMS_STELLA_DEFSLOT;
extern Symbol* SYM_SYSTEMS_STELLA_DEFUN;
extern Symbol* SYM_SYSTEMS_STELLA_DEFMETHOD;
extern Keyword* KWD_SYSTEMS_DIRECTORY;
extern Keyword* KWD_SYSTEMS_FILES;
extern Keyword* KWD_SYSTEMS_REQUIRED_SYSTEMS;
extern Keyword* KWD_SYSTEMS_LISP_ONLY_FILES;
extern Keyword* KWD_SYSTEMS_CPP_ONLY_FILES;
extern Keyword* KWD_SYSTEMS_JAVA_ONLY_FILES;
extern Keyword* KWD_SYSTEMS_PREPROCESSED_FILES;
extern Keyword* KWD_SYSTEMS_CARDINAL_MODULE;
extern Keyword* KWD_SYSTEMS_ROOT_SOURCE_DIRECTORY;
extern Keyword* KWD_SYSTEMS_ROOT_NATIVE_DIRECTORY;
extern Keyword* KWD_SYSTEMS_ROOT_BINARY_DIRECTORY;
extern Keyword* KWD_SYSTEMS_BANNER;
extern Keyword* KWD_SYSTEMS_COPYRIGHT_HEADER;
extern Keyword* KWD_SYSTEMS_PRODUCTION_SETTINGS;
extern Keyword* KWD_SYSTEMS_DEVELOPMENT_SETTINGS;
extern Keyword* KWD_SYSTEMS_FINALIZATION_FUNCTION;
extern Keyword* KWD_SYSTEMS_JAVA;
extern Keyword* KWD_SYSTEMS_LISP;
extern Keyword* KWD_SYSTEMS_CPP;
extern Keyword* KWD_SYSTEMS_LISP_BINARY;
extern Surrogate* SGT_SYSTEMS_STELLA_PROPERTY_LIST;
extern Surrogate* SGT_SYSTEMS_STELLA_LIST;
extern Keyword* KWD_SYSTEMS_COMMON_LISP;
extern Keyword* KWD_SYSTEMS_DEVELOPMENT_SETTINGSp;
extern Keyword* KWD_SYSTEMS_PRODUCTION_SETTINGSp;
extern Keyword* KWD_SYSTEMS_FORCE_TRANSLATIONp;
extern Keyword* KWD_SYSTEMS_FORCE_RECOMPILATIONp;
extern Keyword* KWD_SYSTEMS_TWO_PASSp;
extern Keyword* KWD_SYSTEMS_LOAD_SYSTEMp;
extern Keyword* KWD_SYSTEMS_STARTUPp;
extern Keyword* KWD_SYSTEMS_USE_COMMON_LISP_STRUCTS;
extern Keyword* KWD_SYSTEMS_STELLA;
extern Keyword* KWD_SYSTEMS_WARN_ABOUT_UNDEFINED_METHODS;
extern Symbol* SYM_SYSTEMS_STELLA_UNLESS;
extern Symbol* SYM_SYSTEMS_STELLA_SYSTEM_STARTED_UPp;
extern Symbol* SYM_SYSTEMS_STELLA_STARTUP_TIME_PROGN;
extern Keyword* KWD_SYSTEMS_EARLY_INITS;
extern Keyword* KWD_SYSTEMS_MODULES;
extern Keyword* KWD_SYSTEMS_PUBLICp;
extern Symbol* SYM_SYSTEMS_STELLA_TRUE;
extern Symbol* SYM_SYSTEMS_STELLA_STARTUP;
extern Symbol* SYM_SYSTEMS_STELLA_FALSE;
extern Symbol* SYM_SYSTEMS_STELLA_FOREACH;
extern Symbol* SYM_SYSTEMS_STELLA_PHASE;
extern Symbol* SYM_SYSTEMS_STELLA_IN;
extern Symbol* SYM_SYSTEMS_STELLA_INTERVAL;
extern Symbol* SYM_SYSTEMS_STELLA_PHASE_TO_INTEGER;
extern Keyword* KWD_SYSTEMS_FINAL;
extern Symbol* SYM_SYSTEMS_STELLA_DO;
extern Symbol* SYM_SYSTEMS_STELLA_SETQ;
extern Symbol* SYM_SYSTEMS_STELLA_oSTARTUP_TIME_PHASEo;
extern Keyword* KWD_SYSTEMS_SET;
extern Keyword* KWD_SYSTEMS_WHITE_SPACE;
extern Keyword* KWD_SYSTEMS_ADD;
extern Symbol* SYM_SYSTEMS_STELLA_CONFIGURATION_TABLE;
extern Keyword* KWD_SYSTEMS_ROOT_DIRECTORY;
extern Symbol* SYM_SYSTEMS_STELLA_STARTUP_SYSTEMS;
extern Symbol* SYM_SYSTEMS_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace stella
