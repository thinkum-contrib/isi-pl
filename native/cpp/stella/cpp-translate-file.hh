//  -*- Mode: C++ -*-

// cpp-translate-file.hh

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
extern DECLARE_STELLA_SPECIAL(oCURRENT_STREAMo, OutputStream* );
extern char* oCPP_TRANSLATED_FILE_SUFFIXo;
extern char* oMAKEFILE_TEMPLATE_VARIABLE_PREFIXo;

// Function signatures:
void cpptrans(Object* statement);
char* cppMakeCodeOutputFileName(char* filename);
char* cppMakeHeaderOutputFileName(char* filename);
void cppOutputFileHeader(OutputStream* stream, char* file);
void cppOutputIncludeDirective(char* filename, boolean stripdirectoryP);
void cppStandaloneOutputImportDeclarations(char* headerfilename);
char* cppRelativizeHeaderFile(char* headerfile, char* systemname);
void cppOutputImportDeclarations(char* systemname);
void cppOutputClassHeadDeclarations(Cons* classes);
void cppOutputNamespaceHeader(Module* module);
void cppOutputNamespaceFooter(Module* module);
boolean cppUnitDefinesMainP(TranslationUnit* unit);
char* cppYieldMainFileName();
void cppOutputMain(TranslationUnit* unit);
List* cppSortUnitsForHeaderFile(List* fileunits);
void cppOutputNamespaceChange(Module* fromnamespace, Module* tonamespace);
void cppOutputAllUnitsToFile(char* filename);
void cppTranslateFile(char* filename);
void cppStandaloneTranslateFile(char* filename);
void cppTranslateSystem(char* systemname);
void cppTranslateWalkedSystemUnits(KeyValueList* systemunits);
void cppOutputSystemSpecificFiles();
char* cppYieldSystemHeaderFileName(char* systemname);
char* cppYieldSystemHeaderFileGuard(char* systemname);
void cppOutputSystemHeaderFile();
char* cppYieldSystemsRootDirectory();
char* cppYieldStellaRootDirectory();
void cppOutputSystemMakefile();
char* substituteTemplateVariablesInString(char* string, KeyValueList* variables);
void substituteTemplateVariablesToStream(InputStream* templatestream, OutputStream* outputstream, KeyValueList* variables);
void substituteTemplateVariablesToMakefile(char* templatefile, char* outputfile, KeyValueList* variables);
void startupCppTranslateFile();

// Auxiliary global declarations:
extern Keyword* KWD_CPP_TRANSLATE_FILE_CPP;
extern Keyword* KWD_CPP_TRANSLATE_FILE_CPP_CODE;
extern Keyword* KWD_CPP_TRANSLATE_FILE_CPP_HEADER;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_METHOD;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_PRINT_METHOD;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_MACRO;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_VERBATIM;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_CLASS;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_GLOBAL_VARIABLE;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_TYPE;
extern Keyword* KWD_CPP_TRANSLATE_FILE_WHITE_SPACE;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_AUXILIARY_VARIABLE;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_CPP_FUNCTION;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_CPP_DEFPRINT;
extern Keyword* KWD_CPP_TRANSLATE_FILE_CPP_STANDALONE;
extern Keyword* KWD_CPP_TRANSLATE_FILE_TWO_PASSp;
extern Keyword* KWD_CPP_TRANSLATE_FILE_FORCE_TRANSLATIONp;
extern Keyword* KWD_CPP_TRANSLATE_FILE_PRODUCTION_SETTINGSp;
extern Keyword* KWD_CPP_TRANSLATE_FILE_UPPERCASE;
extern Keyword* KWD_CPP_TRANSLATE_FILE_STELLA;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_STARTUP_CPP_TRANSLATE_FILE;
extern Symbol* SYM_CPP_TRANSLATE_FILE_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace stella
