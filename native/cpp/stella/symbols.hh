//  -*- Mode: C++ -*-

// symbols.hh

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
| Portions created by the Initial Developer are Copyright (C) 1996-2012      |
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
extern ExtensibleSymbolArray* oSYMBOL_ARRAYo;
extern ExtensibleSymbolArray* oSURROGATE_ARRAYo;
extern ExtensibleSymbolArray* oKEYWORD_ARRAYo;
extern StringToIntegerHashTable* oKEYWORD_OFFSET_TABLEo;
extern ExtensibleSymbolArray* oFIXED_SYMBOL_ARRAYo;
extern ExtensibleSymbolArray* oFIXED_SURROGATE_ARRAYo;
extern ExtensibleSymbolArray* oFIXED_KEYWORD_ARRAYo;
extern StringHashTable* oTRANSIENT_SYMBOL_LOOKUP_TABLEo;
extern StringHashTable* oCOMMON_LISP_SYMBOL_LOOKUP_TABLEo;
extern int SYMBOL_SYM;
extern int SURROGATE_SYM;
extern int KEYWORD_SYM;
extern Module* oROOT_MODULEo;
extern Module* oSTELLA_MODULEo;
extern Module* oCOMMON_LISP_MODULEo;
extern Module* oALTERNATE_STELLA_MODULEo;
extern DECLARE_STELLA_SPECIAL(oCONTEXTo, Context* );
extern DECLARE_STELLA_SPECIAL(oMODULEo, Module* );
extern char SURROGATE_PREFIX_CHARACTER;
extern char MODULE_SEPARATOR_CHARACTER;
extern char* MODULE_SEPARATOR_STRING;
extern int oCONTEXT_NUMBER_COUNTERo;
extern int oGENSYM_COUNTERo;
extern char* oGENSYM_MASKo;
extern char* oSYMBOL_ESCAPE_CODE_TABLEo;
extern char* oCASE_SENSITIVE_SYMBOL_ESCAPE_CODE_TABLEo;

// Function signatures:
int nextFreeOffset(ExtensibleSymbolArray* self);
void freeSymbolOffset(ExtensibleSymbolArray* self, int offset);
void addToSymbolArrayAt(ExtensibleSymbolArray* array, int offset, GeneralizedSymbol* symbol);
int addToSymbolArray(ExtensibleSymbolArray* array, GeneralizedSymbol* symbol);
boolean legalSymbolArrayOffsetP(ExtensibleSymbolArray* array, int offset);
Symbol* getSym(int offset);
Surrogate* getSgt(int offset);
Keyword* getKwd(int offset);
GeneralizedSymbol* getGeneralizedSymbolFromOffset(ExtensibleSymbolArray* symbolarray, int offset);
Symbol* getSymFromOffset(int offset);
Surrogate* getSgtFromOffset(int offset);
Keyword* getKwdFromOffset(int offset);
StringToIntegerHashTable* selectSymbolOffsetTable(Module* module, int kindofsym);
ExtensibleSymbolArray* selectSymbolArray(int kindofsym);
GeneralizedSymbol* lookupRigidSymbolLocally(char* name, Module* module, int kindofsym);
Cons* yieldVisibleRigidSymbolsWrtModule(char* name, Module* module, int kindofsym);
Iterator* visibleRigidSymbolsWrtModule(char* name, Module* module, int kindofsym);
Cons* removeShadowedSymbols(Cons* visiblesymbols);
int lookupRigidSymbolOffsetWrtModule(char* name, Module* module, int kindofsym);
GeneralizedSymbol* lookupRigidSymbolWrtModule(char* name, Module* module, int kindofsym);
GeneralizedSymbol* lookupRigidSymbol(char* name, int kindofsym);
Symbol* lookupSymbol(char* name);
Symbol* lookupSymbolInModule(char* name, Module* module, boolean localP);
Cons* lookupVisibleSymbolsInModule(char* name, Module* module, boolean enforceshadowingP);
Surrogate* lookupSurrogate(char* name);
Surrogate* lookupSurrogateInModule(char* name, Module* module, boolean localP);
Cons* lookupVisibleSurrogatesInModule(char* name, Module* module, boolean enforceshadowingP);
Keyword* lookupKeyword(char* name);
GeneralizedSymbol* helpInternGeneralizedSymbol(char* name, int kindofsym, ExtensibleSymbolArray* array, int offset, Module* module);
GeneralizedSymbol* internRigidSymbolWrtModule(char* name, Module* module, int kindofsym);
GeneralizedSymbol* internRigidSymbolLocally(char* name, Module* module, int kindofsym);
GeneralizedSymbol* internRigidSymbolCaseSensitively(char* name, int kindofsym, boolean tryupcasingP);
Symbol* internPermanentSymbol(char* name);
Symbol* internSymbol(char* name);
Symbol* internSymbolInModule(char* name, Module* module, boolean localP);
Symbol* internDerivedSymbol(GeneralizedSymbol* basesymbol, char* newname);
Surrogate* internSurrogate(char* name);
Surrogate* internSurrogateInModule(char* name, Module* module, boolean localP);
Surrogate* internDerivedSurrogate(GeneralizedSymbol* basesymbol, char* newname);
Keyword* internKeyword(char* name);
Symbol* importSymbol(Symbol* symbol, Module* module);
Surrogate* importSurrogate(Surrogate* surrogate, Module* module);
Symbol* safeImportSymbol(Symbol* symbol, Module* module);
Surrogate* safeImportSurrogate(Surrogate* surrogate, Module* module);
void uninternSymbol(Symbol* self);
void uninternSurrogate(Surrogate* self);
GeneralizedSymbol* internBootstrapSymbolAt(char* name, int offset, int kindofsym);
Symbol* internSymbolAt(char* name, int offset);
Surrogate* internSurrogateAt(char* name, int offset);
Keyword* internKeywordAt(char* name, int offset);
void initializeKernelModule(Module* module, char* name, char* fullname, Module* parent);
void initializeKernelModules();
void initializeSymbolsAndKernelModules();
Symbol* lookupTransientSymbol(char* name);
Symbol* internTransientSymbol(char* name);
void freeTransientSymbols();
Symbol* internCommonLispSymbol(char* name);
boolean symbolCommonLispP(Symbol* self);
boolean commonLispSymbolP(Object* self);
void initializeParsingTables();
char* yieldGensymName(char* prefix, int counter);
char* yieldUniqueGensymName(char* prefix, Module* module);
Symbol* gensym(char* prefix);
Symbol* surrogateToSymbol(Surrogate* self);
Symbol* typeToSymbol(Surrogate* type);
Symbol* symbolize(Surrogate* surrogate);
Surrogate* symbolToType(Symbol* self);
Surrogate* stringToSurrogate(char* self);
Surrogate* symbolToSurrogate(Symbol* self);
Surrogate* stringSurrogatify(char* self);
Surrogate* typify(Object* self);
Keyword* stringKeywordify(char* self);
void inPlaceObjectsToSymbols(Cons* conslist);
void inPlaceObjectsToTypes(Cons* conslist);
boolean surrogateNameP(char* name);
boolean keywordNameP(char* name);
GeneralizedSymbol* internStellaName(char* name);
char* computeFullName(char* name, Module* module);
boolean visibleSymbolP(Symbol* self);
boolean visibleSurrogateP(Surrogate* self);
Object* symbolValue(Symbol* symbol);
Object* symbolValueSetter(Symbol* symbol, Object* value);
Cons* symbolPlist(Symbol* symbol);
Cons* symbolPlistSetter(Symbol* symbol, Cons* plist);
Object* symbolProperty(Symbol* symbol, StandardObject* key);
Object* symbolPropertySetter(Symbol* symbol, Object* value, StandardObject* key);
boolean symbolConstituentCharacterP(char character);
char* initializeSymbolEscapeCodeTable(boolean casesensitiveP);
Keyword* computeSymbolEscapeCode(char* name, boolean casesensitiveP);
void printSymbolNameReadably(char* name, std::ostream* stream, boolean casesensitiveP);
char* readableSymbolName(char* name, boolean casesensitiveP);
void printSymbol(Symbol* self, std::ostream* stream);
void printSurrogate(Surrogate* self, std::ostream* stream);
void printKeyword(Keyword* self, std::ostream* stream);
void helpStartupSymbols1();
void helpStartupSymbols2();
void helpStartupSymbols3();
void startupSymbols();

// Auxiliary global declarations:
extern Symbol* SYM_SYMBOLS_STELLA_MODULE_LISP_PACKAGE;
extern Symbol* SYM_SYMBOLS_STELLA_JAVA_PACKAGE;
extern Symbol* SYM_SYMBOLS_STELLA_MODULE_CPP_PACKAGE;
extern Symbol* SYM_SYMBOLS_STELLA_CODE_ONLYp;
extern Keyword* KWD_SYMBOLS_SYMBOL;
extern Keyword* KWD_SYMBOLS_SURROGATE;
extern Keyword* KWD_SYMBOLS_KEYWORD;
extern Keyword* KWD_SYMBOLS_LETTER;
extern Keyword* KWD_SYMBOLS_DIGIT;
extern Keyword* KWD_SYMBOLS_SYMBOL_CONSTITUENT;
extern Keyword* KWD_SYMBOLS_ESCAPED;
extern Keyword* KWD_SYMBOLS_UNESCAPED;
extern Keyword* KWD_SYMBOLS_COMPLEX_ESCAPED;
extern Symbol* SYM_SYMBOLS_STELLA_STARTUP_SYMBOLS;
extern Symbol* SYM_SYMBOLS_STELLA_METHOD_STARTUP_CLASSNAME;


} // end of namespace stella
