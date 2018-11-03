//  -*- Mode: Java -*-
//
// _StartupSymbols.java

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
+---------------------------- END LICENSE BLOCK -----------------------------+
*/

package edu.isi.stella;

import edu.isi.stella.javalib.*;

public class _StartupSymbols {
  static void helpStartupSymbols1() {
    {
      Stella.SYM_STELLA_CODE_ONLYp = ((Symbol)(Stella.internRigidSymbolWrtModule("CODE-ONLY?", null, 0)));
      Stella.KWD_DIGIT = ((Keyword)(Stella.internRigidSymbolWrtModule("DIGIT", null, 2)));
      Stella.KWD_LETTER = ((Keyword)(Stella.internRigidSymbolWrtModule("LETTER", null, 2)));
      Stella.KWD_SYMBOL_CONSTITUENT = ((Keyword)(Stella.internRigidSymbolWrtModule("SYMBOL-CONSTITUENT", null, 2)));
      Stella.KWD_ESCAPED = ((Keyword)(Stella.internRigidSymbolWrtModule("ESCAPED", null, 2)));
      Stella.KWD_UNESCAPED = ((Keyword)(Stella.internRigidSymbolWrtModule("UNESCAPED", null, 2)));
      Stella.KWD_SYMBOL = ((Keyword)(Stella.internRigidSymbolWrtModule("SYMBOL", null, 2)));
      Stella.KWD_COMPLEX_ESCAPED = ((Keyword)(Stella.internRigidSymbolWrtModule("COMPLEX-ESCAPED", null, 2)));
      Stella.SYM_STELLA_STARTUP_SYMBOLS = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-SYMBOLS", null, 0)));
    }
  }

  static void helpStartupSymbols2() {
    {
      Stella.defineFunctionObject("NEXT-FREE-OFFSET", "(DEFUN (NEXT-FREE-OFFSET INTEGER) ((SELF EXTENSIBLE-SYMBOL-ARRAY)))", Native.find_java_method("edu.isi.stella.ExtensibleSymbolArray", "nextFreeOffset", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.ExtensibleSymbolArray")}), null);
      Stella.defineFunctionObject("FREE-SYMBOL-OFFSET", "(DEFUN FREE-SYMBOL-OFFSET ((SELF EXTENSIBLE-SYMBOL-ARRAY) (OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.ExtensibleSymbolArray", "freeSymbolOffset", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.ExtensibleSymbolArray"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("ADD-TO-SYMBOL-ARRAY-AT", "(DEFUN ADD-TO-SYMBOL-ARRAY-AT ((ARRAY EXTENSIBLE-SYMBOL-ARRAY) (OFFSET INTEGER) (SYMBOL GENERALIZED-SYMBOL)))", Native.find_java_method("edu.isi.stella.ExtensibleSymbolArray", "addToSymbolArrayAt", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.ExtensibleSymbolArray"), java.lang.Integer.TYPE, Native.find_java_class("edu.isi.stella.GeneralizedSymbol")}), null);
      Stella.defineFunctionObject("ADD-TO-SYMBOL-ARRAY", "(DEFUN (ADD-TO-SYMBOL-ARRAY INTEGER) ((ARRAY EXTENSIBLE-SYMBOL-ARRAY) (SYMBOL GENERALIZED-SYMBOL)))", Native.find_java_method("edu.isi.stella.ExtensibleSymbolArray", "addToSymbolArray", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.ExtensibleSymbolArray"), Native.find_java_class("edu.isi.stella.GeneralizedSymbol")}), null);
      Stella.defineFunctionObject("LEGAL-SYMBOL-ARRAY-OFFSET?", "(DEFUN (LEGAL-SYMBOL-ARRAY-OFFSET? BOOLEAN) ((ARRAY EXTENSIBLE-SYMBOL-ARRAY) (OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.ExtensibleSymbolArray", "legalSymbolArrayOffsetP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.ExtensibleSymbolArray"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("GET-SYM", "(DEFUN (GET-SYM SYMBOL) ((OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "getSym", new java.lang.Class [] {java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("GET-SGT", "(DEFUN (GET-SGT SURROGATE) ((OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "getSgt", new java.lang.Class [] {java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("GET-KWD", "(DEFUN (GET-KWD KEYWORD) ((OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "getKwd", new java.lang.Class [] {java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("GET-GENERALIZED-SYMBOL-FROM-OFFSET", "(DEFUN (GET-GENERALIZED-SYMBOL-FROM-OFFSET GENERALIZED-SYMBOL) ((SYMBOLARRAY EXTENSIBLE-SYMBOL-ARRAY) (OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.ExtensibleSymbolArray", "getGeneralizedSymbolFromOffset", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.ExtensibleSymbolArray"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("GET-SYM-FROM-OFFSET", "(DEFUN (GET-SYM-FROM-OFFSET SYMBOL) ((OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "getSymFromOffset", new java.lang.Class [] {java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("GET-SGT-FROM-OFFSET", "(DEFUN (GET-SGT-FROM-OFFSET SURROGATE) ((OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "getSgtFromOffset", new java.lang.Class [] {java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("GET-KWD-FROM-OFFSET", "(DEFUN (GET-KWD-FROM-OFFSET KEYWORD) ((OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "getKwdFromOffset", new java.lang.Class [] {java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("SELECT-SYMBOL-OFFSET-TABLE", "(DEFUN (SELECT-SYMBOL-OFFSET-TABLE STRING-TO-INTEGER-HASH-TABLE) ((MODULE MODULE) (KINDOFSYM INTEGER)))", Native.find_java_method("edu.isi.stella.Module", "selectSymbolOffsetTable", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Module"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("SELECT-SYMBOL-ARRAY", "(DEFUN (SELECT-SYMBOL-ARRAY EXTENSIBLE-SYMBOL-ARRAY) ((KINDOFSYM INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "selectSymbolArray", new java.lang.Class [] {java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("LOOKUP-RIGID-SYMBOL-LOCALLY", "(DEFUN (LOOKUP-RIGID-SYMBOL-LOCALLY GENERALIZED-SYMBOL) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "lookupRigidSymbolLocally", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("YIELD-VISIBLE-RIGID-SYMBOLS-WRT-MODULE", "(DEFUN (YIELD-VISIBLE-RIGID-SYMBOLS-WRT-MODULE (CONS OF GENERALIZED-SYMBOL)) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "yieldVisibleRigidSymbolsWrtModule", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("VISIBLE-RIGID-SYMBOLS-WRT-MODULE", "(DEFUN (VISIBLE-RIGID-SYMBOLS-WRT-MODULE (ITERATOR OF GENERALIZED-SYMBOL)) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "visibleRigidSymbolsWrtModule", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("REMOVE-SHADOWED-SYMBOLS", "(DEFUN (REMOVE-SHADOWED-SYMBOLS (CONS OF GENERALIZED-SYMBOL)) ((VISIBLESYMBOLS (CONS OF GENERALIZED-SYMBOL))))", Native.find_java_method("edu.isi.stella.Cons", "removeShadowedSymbols", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("LOOKUP-RIGID-SYMBOL-OFFSET-WRT-MODULE", "(DEFUN (LOOKUP-RIGID-SYMBOL-OFFSET-WRT-MODULE INTEGER) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "lookupRigidSymbolOffsetWrtModule", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("LOOKUP-RIGID-SYMBOL-WRT-MODULE", "(DEFUN (LOOKUP-RIGID-SYMBOL-WRT-MODULE GENERALIZED-SYMBOL) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "lookupRigidSymbolWrtModule", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("LOOKUP-RIGID-SYMBOL", "(DEFUN (LOOKUP-RIGID-SYMBOL GENERALIZED-SYMBOL) ((NAME STRING) (KINDOFSYM INTEGER)) :DOCUMENTATION \"Return the symbol named `name'.  Case sensitive.\")", Native.find_java_method("edu.isi.stella.Stella", "lookupRigidSymbol", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("LOOKUP-SYMBOL", "(DEFUN (LOOKUP-SYMBOL SYMBOL) ((NAME STRING)) :DOCUMENTATION \"Return the first symbol with `name' visible from the current module.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "lookupSymbol", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("LOOKUP-SYMBOL-IN-MODULE", "(DEFUN (LOOKUP-SYMBOL-IN-MODULE SYMBOL) ((NAME STRING) (MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Return the first symbol with `name' visible from `module'.\nIf `local?' only consider symbols directly interned in `module'.\nIf `module' is `null', use `*MODULE*' instead.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "lookupSymbolInModule", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("LOOKUP-VISIBLE-SYMBOLS-IN-MODULE", "(DEFUN (LOOKUP-VISIBLE-SYMBOLS-IN-MODULE (CONS OF SYMBOL)) ((NAME STRING) (MODULE MODULE) (ENFORCESHADOWING? BOOLEAN)) :DOCUMENTATION \"Return the list of symbols with `name' visible from `module'.\nMore specific symbols (relative to the module precedence order defined by\n`visible-modules') come earlier in the list.  If `module' is `null', start\nfrom `*MODULE*' instead.  If `enforceShadowing?' is true, do not return any\nsymbols that are shadowed due to some :SHADOW declaration.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "lookupVisibleSymbolsInModule", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("LOOKUP-SURROGATE", "(DEFUN (LOOKUP-SURROGATE SURROGATE) ((NAME STRING)) :DOCUMENTATION \"Return the first surrogate with `name' visible from the current module.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "lookupSurrogate", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("LOOKUP-SURROGATE-IN-MODULE", "(DEFUN (LOOKUP-SURROGATE-IN-MODULE SURROGATE) ((NAME STRING) (MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Return the first surrogate with `name' visible from `module'.\nIf `local?' only consider surrogates directly interned in `module'.\nIf `module' is `null', use `*MODULE*' instead.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "lookupSurrogateInModule", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("LOOKUP-VISIBLE-SURROGATES-IN-MODULE", "(DEFUN (LOOKUP-VISIBLE-SURROGATES-IN-MODULE (CONS OF SURROGATE)) ((NAME STRING) (MODULE MODULE) (ENFORCESHADOWING? BOOLEAN)) :DOCUMENTATION \"Return the list of surrogates with `name' visible from `module'.\nMore specific surrogates (relative to the module precedence order defined by\n`visible-modules') come earlier in the list.  If `module' is `null', start\nfrom `*MODULE*' instead.  If `enforceShadowing?' is true, do not return any\nsurrogates that are shadowed due to some :SHADOW declaration.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "lookupVisibleSurrogatesInModule", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("LOOKUP-KEYWORD", "(DEFUN (LOOKUP-KEYWORD KEYWORD) ((NAME STRING)) :DOCUMENTATION \"Return the keyword with `name' if it exists.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "lookupKeyword", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("HELP-INTERN-GENERALIZED-SYMBOL", "(DEFUN (HELP-INTERN-GENERALIZED-SYMBOL GENERALIZED-SYMBOL) ((NAME STRING) (KINDOFSYM INTEGER) (ARRAY EXTENSIBLE-SYMBOL-ARRAY) (OFFSET INTEGER) (MODULE MODULE)))", Native.find_java_method("edu.isi.stella.Stella", "helpInternGeneralizedSymbol", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Integer.TYPE, Native.find_java_class("edu.isi.stella.ExtensibleSymbolArray"), java.lang.Integer.TYPE, Native.find_java_class("edu.isi.stella.Module")}), null);
      Stella.defineFunctionObject("INTERN-RIGID-SYMBOL-WRT-MODULE", "(DEFUN (INTERN-RIGID-SYMBOL-WRT-MODULE GENERALIZED-SYMBOL) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)) :PUBLIC? TRUE :DOCUMENTATION \"Return a newly-created or existing rigid symbol with\nname `name'.\")", Native.find_java_method("edu.isi.stella.Stella", "internRigidSymbolWrtModule", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("INTERN-RIGID-SYMBOL-LOCALLY", "(DEFUN (INTERN-RIGID-SYMBOL-LOCALLY GENERALIZED-SYMBOL) ((NAME STRING) (MODULE MODULE) (KINDOFSYM INTEGER)) :PUBLIC? TRUE :DOCUMENTATION \"Return a newly-created or existing rigid symbol\ninterned into the module `module' with name `name'.\")", Native.find_java_method("edu.isi.stella.Stella", "internRigidSymbolLocally", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("INTERN-RIGID-SYMBOL-CASE-SENSITIVELY", "(DEFUN (INTERN-RIGID-SYMBOL-CASE-SENSITIVELY GENERALIZED-SYMBOL) ((NAME STRING) (KINDOFSYM INTEGER) (TRYUPCASING? BOOLEAN)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "internRigidSymbolCaseSensitively", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Integer.TYPE, java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("INTERN-PERMANENT-SYMBOL", "(DEFUN (INTERN-PERMANENT-SYMBOL SYMBOL) ((NAME STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return a newly-created or existing permanent symbol with\nname `name'.\")", Native.find_java_method("edu.isi.stella.Stella", "internPermanentSymbol", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("INTERN-SYMBOL", "(DEFUN (INTERN-SYMBOL SYMBOL) ((NAME STRING)) :DOCUMENTATION \"Return a newly-created or existing symbol with name `name'.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "internSymbol", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("INTERN-SYMBOL-IN-MODULE", "(DEFUN (INTERN-SYMBOL-IN-MODULE SYMBOL) ((NAME STRING) (MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Look for a symbol named `name' in `module' (if `local?' do\nnot consider inherited modules).  If none exists, intern it locally in\n`module'.  Return the existing or newly-created symbol.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "internSymbolInModule", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("INTERN-DERIVED-SYMBOL", "(DEFUN (INTERN-DERIVED-SYMBOL SYMBOL) ((BASESYMBOL GENERALIZED-SYMBOL) (NEWNAME STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return a newly-created or existing symbol with name\n`newName' which is interned in the same module as `baseSymbol'.\")", Native.find_java_method("edu.isi.stella.GeneralizedSymbol", "internDerivedSymbol", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.GeneralizedSymbol"), Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("INTERN-SURROGATE", "(DEFUN (INTERN-SURROGATE SURROGATE) ((NAME STRING)) :DOCUMENTATION \"Return a newly-created or existing surrogate with name `name'.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "internSurrogate", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("INTERN-SURROGATE-IN-MODULE", "(DEFUN (INTERN-SURROGATE-IN-MODULE SURROGATE) ((NAME STRING) (MODULE MODULE) (LOCAL? BOOLEAN)) :DOCUMENTATION \"Look for a symbol named `name' in `module' (if `local?' do\nnot consider inherited modules).  If none exists, intern it locally in\n`module'.  Return the existing or newly-created symbol.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "internSurrogateInModule", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("INTERN-DERIVED-SURROGATE", "(DEFUN (INTERN-DERIVED-SURROGATE SURROGATE) ((BASESYMBOL GENERALIZED-SYMBOL) (NEWNAME STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Return a newly-created or existing surrogate with name\n`newName' which is interned in the same module as `baseSymbol'.\")", Native.find_java_method("edu.isi.stella.GeneralizedSymbol", "internDerivedSurrogate", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.GeneralizedSymbol"), Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("INTERN-KEYWORD", "(DEFUN (INTERN-KEYWORD KEYWORD) ((NAME STRING)) :DOCUMENTATION \"Return a newly-created or existing keyword with name\n`name'.  Storage note: a COPY of `name' is stored in the keyword\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "internKeyword", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("IMPORT-SYMBOL", "(DEFUN (IMPORT-SYMBOL SYMBOL) ((SYMBOL SYMBOL) (MODULE MODULE)) :DOCUMENTATION \"Import `symbol' into `module' and return the imported `symbol'.\nSignal an error if a different symbol with the same name already exists\nlocally in `module'.  Any symbol with the same name visible in `module' by\ninheritance will be shadowed by the newly imported `symbol'.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Symbol", "importSymbol", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Module")}), null);
      Stella.defineFunctionObject("IMPORT-SURROGATE", "(DEFUN (IMPORT-SURROGATE SURROGATE) ((SURROGATE SURROGATE) (MODULE MODULE)) :DOCUMENTATION \"Import `surrogate' into `module' and return the imported `surrogate'.\nSignal an error if a different surrogate with the same name already exists\nlocally in `module'.  Any surrogate with the same name visible in `module' by\ninheritance will be shadowed by the newly imported `surrogate'.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Surrogate", "importSurrogate", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate"), Native.find_java_class("edu.isi.stella.Module")}), null);
      Stella.defineFunctionObject("SAFE-IMPORT-SYMBOL", "(DEFUN (SAFE-IMPORT-SYMBOL SYMBOL) ((SYMBOL SYMBOL) (MODULE MODULE)) :DOCUMENTATION \"Safe version of `import-symbol' (which see).  Only imports `symbol' if\nno symbol with that name is currently interned or visible in `module'.\nReturns `symbol' if it was imported or the conflicting symbol in `module'\notherwise.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Symbol", "safeImportSymbol", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Module")}), null);
      Stella.defineFunctionObject("SAFE-IMPORT-SURROGATE", "(DEFUN (SAFE-IMPORT-SURROGATE SURROGATE) ((SURROGATE SURROGATE) (MODULE MODULE)) :DOCUMENTATION \"Safe version of `import-surrogate' (which see).  Only imports `surrogate' if\nno surrogate with that name is currently interned or visible in `module'.\nReturns `surrogate' if it was imported or the conflicting surrogate in `module'\notherwise.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Surrogate", "safeImportSurrogate", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate"), Native.find_java_class("edu.isi.stella.Module")}), null);
      Stella.defineFunctionObject("UNINTERN-SYMBOL", "(DEFUN UNINTERN-SYMBOL ((SELF SYMBOL)) :DOCUMENTATION \"Remove `self' from its home module and the symbol table.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Symbol", "uninternSymbol", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol")}), null);
      Stella.defineFunctionObject("UNINTERN-SURROGATE", "(DEFUN UNINTERN-SURROGATE ((SELF SURROGATE)) :DOCUMENTATION \"Remove `self' from its home module and the surrogate table.\")", Native.find_java_method("edu.isi.stella.Surrogate", "uninternSurrogate", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate")}), null);
      Stella.defineMethodObject("(DEFMETHOD (DELETED? BOOLEAN) ((SELF GENERALIZED-SYMBOL)) :GLOBALLY-INLINE? TRUE (RETURN (EQL? (SYMBOL-ID SELF) -1)))", Native.find_java_method("edu.isi.stella.GeneralizedSymbol", "deletedP", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject("INTERN-BOOTSTRAP-SYMBOL-AT", "(DEFUN (INTERN-BOOTSTRAP-SYMBOL-AT GENERALIZED-SYMBOL) ((NAME STRING) (OFFSET INTEGER) (KINDOFSYM INTEGER)) :DOCUMENTATION \"Interns a symbol, or keyword with\n`name' and symbol-id `offset'.\nIf a symbol with that ID already existed, an error is signaled.  This\nfunction is used to recreate the symbol table in a way where symbol IDs\nwhich got hardwired into translated code will refer to the correct objects.\")", Native.find_java_method("edu.isi.stella.Stella", "internBootstrapSymbolAt", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Integer.TYPE, java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("INTERN-SYMBOL-AT", "(DEFUN (INTERN-SYMBOL-AT SYMBOL) ((NAME STRING) (OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "internSymbolAt", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("INTERN-SURROGATE-AT", "(DEFUN (INTERN-SURROGATE-AT SURROGATE) ((NAME STRING) (OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "internSurrogateAt", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("INTERN-KEYWORD-AT", "(DEFUN (INTERN-KEYWORD-AT KEYWORD) ((NAME STRING) (OFFSET INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "internKeywordAt", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("INITIALIZE-KERNEL-MODULE", "(DEFUN INITIALIZE-KERNEL-MODULE ((MODULE MODULE) (NAME STRING) (FULLNAME STRING) (PARENT MODULE)))", Native.find_java_method("edu.isi.stella.Module", "initializeKernelModule", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Module"), Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module")}), null);
      Stella.defineFunctionObject("INITIALIZE-KERNEL-MODULES", "(DEFUN INITIALIZE-KERNEL-MODULES ())", Native.find_java_method("edu.isi.stella.Stella", "initializeKernelModules", new java.lang.Class [] {}), null);
      Stella.defineFunctionObject("INITIALIZE-SYMBOLS-AND-KERNEL-MODULES", "(DEFUN INITIALIZE-SYMBOLS-AND-KERNEL-MODULES ())", Native.find_java_method("edu.isi.stella.Stella", "initializeSymbolsAndKernelModules", new java.lang.Class [] {}), null);
      Stella.defineFunctionObject("LOOKUP-TRANSIENT-SYMBOL", "(DEFUN (LOOKUP-TRANSIENT-SYMBOL SYMBOL) ((NAME STRING)))", Native.find_java_method("edu.isi.stella.Stella", "lookupTransientSymbol", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("INTERN-TRANSIENT-SYMBOL", "(DEFUN (INTERN-TRANSIENT-SYMBOL SYMBOL) ((NAME STRING)))", Native.find_java_method("edu.isi.stella.Stella", "internTransientSymbol", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("FREE-TRANSIENT-SYMBOLS", "(DEFUN FREE-TRANSIENT-SYMBOLS ())", Native.find_java_method("edu.isi.stella.Stella", "freeTransientSymbols", new java.lang.Class [] {}), null);
      Stella.defineFunctionObject("INTERN-COMMON-LISP-SYMBOL", "(DEFUN (INTERN-COMMON-LISP-SYMBOL SYMBOL) ((NAME STRING)))", Native.find_java_method("edu.isi.stella.Stella", "internCommonLispSymbol", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("SYMBOL-COMMON-LISP?", "(DEFUN (SYMBOL-COMMON-LISP? BOOLEAN) ((SELF SYMBOL)))", Native.find_java_method("edu.isi.stella.Symbol", "symbolCommonLispP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol")}), null);
      Stella.defineFunctionObject("COMMON-LISP-SYMBOL?", "(DEFUN (COMMON-LISP-SYMBOL? BOOLEAN) ((SELF OBJECT)))", Native.find_java_method("edu.isi.stella.Stella_Object", "commonLispSymbolP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
    }
  }

  static void helpStartupSymbols3() {
    {
      Stella.defineFunctionObject("INITIALIZE-PARSING-TABLES", "(DEFUN INITIALIZE-PARSING-TABLES () :DOCUMENTATION \"Create indices for recording transient symbols and\nCommon Lisp symbols while parsing.\")", Native.find_java_method("edu.isi.stella.Stella", "initializeParsingTables", new java.lang.Class [] {}), null);
      Stella.defineFunctionObject("YIELD-GENSYM-NAME", "(DEFUN (YIELD-GENSYM-NAME STRING) ((PREFIX STRING) (COUNTER INTEGER)))", Native.find_java_method("edu.isi.stella.Stella", "yieldGensymName", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Integer.TYPE}), null);
      Stella.defineFunctionObject("YIELD-UNIQUE-GENSYM-NAME", "(DEFUN (YIELD-UNIQUE-GENSYM-NAME STRING) ((PREFIX STRING) (MODULE MODULE)))", Native.find_java_method("edu.isi.stella.Stella", "yieldUniqueGensymName", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module")}), null);
      Stella.defineFunctionObject("GENSYM", "(DEFUN (GENSYM SYMBOL) ((PREFIX STRING)) :DOCUMENTATION \"Return a transient symbol with a name beginning with\n`prefix' and ending with a globally gensym'd integer.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "gensym", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("SURROGATE-TO-SYMBOL", "(DEFUN (SURROGATE-TO-SYMBOL SYMBOL) ((SELF SURROGATE)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Surrogate", "surrogateToSymbol", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate")}), null);
      Stella.defineFunctionObject("TYPE-TO-SYMBOL", "(DEFUN (TYPE-TO-SYMBOL SYMBOL) ((TYPE TYPE)) :DOCUMENTATION \"Convert `type' into a symbol with the same name and module.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (INTERN-SYMBOL-IN-MODULE (SYMBOL-NAME TYPE) (INTERNED-IN TYPE) TRUE)))", Native.find_java_method("edu.isi.stella.Surrogate", "typeToSymbol", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate")}), null);
      Stella.defineFunctionObject("SYMBOLIZE", "(DEFUN (SYMBOLIZE SYMBOL) ((SURROGATE SURROGATE)) :DOCUMENTATION \"Convert `surrogate' into a symbol with the same name and module.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (TYPE-TO-SYMBOL SURROGATE)))", Native.find_java_method("edu.isi.stella.Surrogate", "symbolize", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate")}), null);
      Stella.defineFunctionObject("STRING-TO-SURROGATE", "(DEFUN (STRING-TO-SURROGATE SURROGATE) ((SELF STRING)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "stringToSurrogate", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("SYMBOL-TO-SURROGATE", "(DEFUN (SYMBOL-TO-SURROGATE SURROGATE) ((SELF SYMBOL)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Symbol", "symbolToSurrogate", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol")}), null);
      Stella.defineMethodObject("(DEFMETHOD (SURROGATIFY SURROGATE) ((SELF SURROGATE)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Surrogate", "surrogatify", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD (SURROGATIFY SURROGATE) ((SELF SYMBOL)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Symbol", "surrogatify", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD (SURROGATIFY SURROGATE) ((SELF STRING)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "string_surrogatify", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD (SURROGATIFY SURROGATE) ((SELF CONS)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Cons", "surrogatify", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD (SURROGATIFY SURROGATE) ((SELF OBJECT)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella_Object", "surrogatify", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject("TYPIFY", "(DEFUN (TYPIFY TYPE) ((SELF OBJECT)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella_Object", "typify", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineMethodObject("(DEFMETHOD (KEYWORDIFY KEYWORD) ((SELF KEYWORD)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Keyword", "keywordify", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD (KEYWORDIFY KEYWORD) ((SELF GENERALIZED-SYMBOL)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.GeneralizedSymbol", "keywordify", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD (KEYWORDIFY KEYWORD) ((SELF STRING-WRAPPER)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.StringWrapper", "keywordify", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD (KEYWORDIFY KEYWORD) ((SELF STRING)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "string_keywordify", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject("IN-PLACE-OBJECTS-TO-SYMBOLS", "(DEFUN IN-PLACE-OBJECTS-TO-SYMBOLS ((CONSLIST CONS)))", Native.find_java_method("edu.isi.stella.Cons", "inPlaceObjectsToSymbols", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("IN-PLACE-OBJECTS-TO-TYPES", "(DEFUN IN-PLACE-OBJECTS-TO-TYPES ((CONSLIST CONS)))", Native.find_java_method("edu.isi.stella.Cons", "inPlaceObjectsToTypes", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("SURROGATE-NAME?", "(DEFUN (SURROGATE-NAME? BOOLEAN) ((NAME STRING)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "surrogateNameP", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("QUALIFIED-NAME?", "(DEFUN (QUALIFIED-NAME? BOOLEAN) ((NAME STRING)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "qualifiedNameP", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("KEYWORD-NAME?", "(DEFUN (KEYWORD-NAME? BOOLEAN) ((NAME STRING)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "keywordNameP", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("INTERN-GENERALIZED-SYMBOL", "(DEFUN (INTERN-GENERALIZED-SYMBOL GENERALIZED-SYMBOL) ((NAME STRING)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "internGeneralizedSymbol", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("COMPUTE-FULL-NAME", "(DEFUN (COMPUTE-FULL-NAME STRING) ((NAME STRING) (MODULE MODULE)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "computeFullName", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Module")}), null);
      Stella.defineMethodObject("(DEFMETHOD (LOCAL-PRINT-NAME STRING) ((SELF GENERALIZED-SYMBOL)))", Native.find_java_method("edu.isi.stella.GeneralizedSymbol", "localPrintName", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD (LOCAL-PRINT-NAME STRING) ((SELF SURROGATE)))", Native.find_java_method("edu.isi.stella.Surrogate", "localPrintName", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineMethodObject("(DEFMETHOD (RELATIVE-NAME STRING) ((SELF GENERALIZED-SYMBOL)))", Native.find_java_method("edu.isi.stella.GeneralizedSymbol", "relativeName", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject("VISIBLE-SYMBOL?", "(DEFUN (VISIBLE-SYMBOL? BOOLEAN) ((SELF SYMBOL)) :DOCUMENTATION \"Return `true' if `self' is visible from the current module.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (EQL? SELF (LOOKUP-SYMBOL-IN-MODULE (SYMBOL-NAME SELF) *MODULE* FALSE))))", Native.find_java_method("edu.isi.stella.Symbol", "visibleSymbolP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol")}), null);
      Stella.defineFunctionObject("VISIBLE-SURROGATE?", "(DEFUN (VISIBLE-SURROGATE? BOOLEAN) ((SELF SURROGATE)) :DOCUMENTATION \"Return `true' if `self' is visible from the current module.\" :GLOBALLY-INLINE? TRUE :PUBLIC? TRUE (RETURN (EQL? SELF (LOOKUP-SURROGATE-IN-MODULE (SYMBOL-NAME SELF) *MODULE* FALSE))))", Native.find_java_method("edu.isi.stella.Surrogate", "visibleSurrogateP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate")}), null);
      Stella.defineMethodObject("(DEFMETHOD (VISIBLE-NAME STRING) ((SELF GENERALIZED-SYMBOL)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.GeneralizedSymbol", "visibleName", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject("SYMBOL-VALUE", "(DEFUN (SYMBOL-VALUE OBJECT) ((SYMBOL SYMBOL)) :DOCUMENTATION \"Return the value of `symbol'.  Note, that this value is not\nvisible to code that references a variable with the same name as `symbol'.\nThe `symbol-value' is simply a special property that can always be accessed\nin constant time.  The `symbol-value' of a symbol can be changed with `setf'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (VALUE (SYMBOL-VALUE-AND-PLIST SYMBOL))))", Native.find_java_method("edu.isi.stella.Symbol", "symbolValue", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol")}), null);
      Stella.defineFunctionObject("SYMBOL-VALUE-SETTER", "(DEFUN (SYMBOL-VALUE-SETTER OBJECT) ((SYMBOL SYMBOL) (VALUE OBJECT)))", Native.find_java_method("edu.isi.stella.Symbol", "symbolValueSetter", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("SYMBOL-PLIST", "(DEFUN (SYMBOL-PLIST CONS) ((SYMBOL SYMBOL)) :DOCUMENTATION \"Return the property list of `symbol'.  The `symbol-plist'\nof a symbol can be set with `setf'.  IMPORTANT: Property list are modified \ndestructively, hence, if you supply it as a whole make sure to always supply\na modfiable copy, e.g., by using `bquote'.\" :PUBLIC? TRUE :GLOBALLY-INLINE? TRUE (RETURN (REST (SYMBOL-VALUE-AND-PLIST SYMBOL))))", Native.find_java_method("edu.isi.stella.Symbol", "symbolPlist", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol")}), null);
      Stella.defineFunctionObject("SYMBOL-PLIST-SETTER", "(DEFUN (SYMBOL-PLIST-SETTER CONS) ((SYMBOL SYMBOL) (PLIST CONS)))", Native.find_java_method("edu.isi.stella.Symbol", "symbolPlistSetter", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("SYMBOL-PROPERTY", "(DEFUN (SYMBOL-PROPERTY OBJECT) ((SYMBOL SYMBOL) (KEY STANDARD-OBJECT)) :DOCUMENTATION \"Return the property of `symbol' whose key is `eq?' to `key'.\nSymbol properties can be set with `setf'.\")", Native.find_java_method("edu.isi.stella.Symbol", "symbolProperty", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.StandardObject")}), null);
      Stella.defineFunctionObject("SYMBOL-PROPERTY-SETTER", "(DEFUN (SYMBOL-PROPERTY-SETTER OBJECT) ((SYMBOL SYMBOL) (VALUE OBJECT) (KEY STANDARD-OBJECT)))", Native.find_java_method("edu.isi.stella.Symbol", "symbolPropertySetter", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.StandardObject")}), null);
      Stella.defineFunctionObject("SYMBOL-CONSTITUENT-CHARACTER?", "(DEFUN (SYMBOL-CONSTITUENT-CHARACTER? BOOLEAN) ((CHARACTER CHARACTER)))", Native.find_java_method("edu.isi.stella.Stella", "symbolConstituentCharacterP", new java.lang.Class [] {java.lang.Character.TYPE}), null);
      Stella.defineFunctionObject("INITIALIZE-SYMBOL-ESCAPE-CODE-TABLE", "(DEFUN (INITIALIZE-SYMBOL-ESCAPE-CODE-TABLE STRING) ((CASESENSITIVE? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Stella", "initializeSymbolEscapeCodeTable", new java.lang.Class [] {java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("COMPUTE-SYMBOL-ESCAPE-CODE", "(DEFUN (COMPUTE-SYMBOL-ESCAPE-CODE KEYWORD) ((NAME STRING) (CASESENSITIVE? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Stella", "computeSymbolEscapeCode", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("PRINT-SYMBOL-NAME-READABLY", "(DEFUN PRINT-SYMBOL-NAME-READABLY ((NAME STRING) (STREAM NATIVE-OUTPUT-STREAM) (CASESENSITIVE? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Stella", "printSymbolNameReadably", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("java.io.PrintStream"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("PRINT-SYMBOL", "(DEFUN PRINT-SYMBOL ((SELF SYMBOL) (STREAM NATIVE-OUTPUT-STREAM)))", Native.find_java_method("edu.isi.stella.Symbol", "printSymbol", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("java.io.PrintStream")}), null);
      Stella.defineFunctionObject("PRINT-SURROGATE", "(DEFUN PRINT-SURROGATE ((SELF SURROGATE) (STREAM NATIVE-OUTPUT-STREAM)))", Native.find_java_method("edu.isi.stella.Surrogate", "printSurrogate", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Surrogate"), Native.find_java_class("java.io.PrintStream")}), null);
      Stella.defineFunctionObject("PRINT-KEYWORD", "(DEFUN PRINT-KEYWORD ((SELF KEYWORD) (STREAM NATIVE-OUTPUT-STREAM)))", Native.find_java_method("edu.isi.stella.Keyword", "printKeyword", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Keyword"), Native.find_java_class("java.io.PrintStream")}), null);
      Stella.defineFunctionObject("STARTUP-SYMBOLS", "(DEFUN STARTUP-SYMBOLS () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella._StartupSymbols", "startupSymbols", new java.lang.Class [] {}), null);
      { MethodSlot function = Symbol.lookupFunction(Stella.SYM_STELLA_STARTUP_SYMBOLS);

        KeyValueList.setDynamicSlotValue(function.dynamicSlots, Stella.SYM_STELLA_METHOD_STARTUP_CLASSNAME, Stella.wrapString("_Startup-Symbols"), Stella.NULL_STRING_WRAPPER);
      }
    }
  }

  public static void startupSymbols() {
    if (Stella.currentStartupTimePhaseP(0)) {
      if (Stella.$FIXED_SYMBOL_ARRAY$ == null) {
        Stella.initializeSymbolsAndKernelModules();
      }
      Stella.initializeParsingTables();
    }
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.$STELLA_MODULE$);
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupSymbols.helpStartupSymbols1();
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          KeyValueList.setDynamicSlotValue(Stella.$STELLA_MODULE$.dynamicSlots, Stella.SYM_STELLA_JAVA_PACKAGE, Stella.wrapString("edu.isi.stella"), Stella.NULL_STRING_WRAPPER);
          KeyValueList.setDynamicSlotValue(Stella.$STELLA_MODULE$.dynamicSlots, Stella.SYM_STELLA_MODULE_LISP_PACKAGE, Stella.wrapString("STELLA"), Stella.NULL_STRING_WRAPPER);
          KeyValueList.setDynamicSlotValue(Stella.$STELLA_MODULE$.dynamicSlots, Stella.SYM_STELLA_MODULE_CPP_PACKAGE, Stella.wrapString("stella"), Stella.NULL_STRING_WRAPPER);
          KeyValueList.setDynamicSlotValue(Stella.$ROOT_MODULE$.dynamicSlots, Stella.SYM_STELLA_CODE_ONLYp, (true ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER), Stella.FALSE_WRAPPER);
          KeyValueList.setDynamicSlotValue(Stella.$STELLA_MODULE$.dynamicSlots, Stella.SYM_STELLA_CODE_ONLYp, (true ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER), Stella.FALSE_WRAPPER);
          KeyValueList.setDynamicSlotValue(Stella.$COMMON_LISP_MODULE$.dynamicSlots, Stella.SYM_STELLA_CODE_ONLYp, (true ? Stella.TRUE_WRAPPER : Stella.FALSE_WRAPPER), Stella.FALSE_WRAPPER);
          Stella.$SYMBOL_ESCAPE_CODE_TABLE$ = Stella.initializeSymbolEscapeCodeTable(false);
          Stella.$CASE_SENSITIVE_SYMBOL_ESCAPE_CODE_TABLE$ = Stella.initializeSymbolEscapeCodeTable(true);
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          _StartupSymbols.helpStartupSymbols2();
          _StartupSymbols.helpStartupSymbols3();
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SYMBOL-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF SYMBOL) NULL :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SURROGATE-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF SURROGATE) NULL :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *KEYWORD-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF KEYWORD) NULL :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *KEYWORD-OFFSET-TABLE* STRING-TO-INTEGER-HASH-TABLE NULL)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *FIXED-SYMBOL-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF SYMBOL) NULL)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *FIXED-SURROGATE-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF SURROGATE) NULL)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *FIXED-KEYWORD-ARRAY* (EXTENSIBLE-SYMBOL-ARRAY OF KEYWORD) NULL)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *TRANSIENT-SYMBOL-LOOKUP-TABLE* STRING-HASH-TABLE NULL)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *COMMON-LISP-SYMBOL-LOOKUP-TABLE* STRING-HASH-TABLE NULL)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT SYMBOL-SYM INTEGER 0)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT SURROGATE-SYM INTEGER 1)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT KEYWORD-SYM INTEGER 2)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *ROOT-MODULE* MODULE NULL :PUBLIC? TRUE :DOCUMENTATION \"Pointer to the top-most module ROOT-MODULE.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *STELLA-MODULE* MODULE NULL :PUBLIC? TRUE :DOCUMENTATION \"Pointer to the module STELLA containing definitions of \nSTELLA classes and methods.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *COMMON-LISP-MODULE* MODULE NULL :PUBLIC? TRUE :DOCUMENTATION \"Pointer to the module COMMON-LISP containing Common\nLisp symbols (and maybe other things).\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *ALTERNATE-STELLA-MODULE* MODULE NULL :DOCUMENTATION \"Pointer to the module ALTERNATE-STELLA containing\ndefinitions of STELLA classes and methods generated during the\ntranslation of STELLA files.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *CONTEXT* CONTEXT :UNBOUND-SPECIAL-VARIABLE :DOCUMENTATION \"Points to the current context (either a module or a\nworld).  Set by calls to `change-world' and `change-module'.\" :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *MODULE* MODULE :UNBOUND-SPECIAL-VARIABLE :DOCUMENTATION \"Points to the current module.  Set by calls to\n`change-context' and `change-module'.\" :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT SURROGATE-PREFIX-CHARACTER CHARACTER #\\@ :DOCUMENTATION \"Character used to prefix the name of a surrogate.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT MODULE-SEPARATOR-CHARACTER CHARACTER #\\/ :DOCUMENTATION \"Character used to concatenate a module name\nto a symbol or surrogate name to form a qualified name.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFCONSTANT MODULE-SEPARATOR-STRING STRING \"/\" :DOCUMENTATION \"String containing character used to concatenate a module name\nto a symbol or surrogate name to form a qualified name.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CONTEXT-NUMBER-COUNTER* INTEGER -2 :DOCUMENTATION \"Contains the number of the last-created\ncontext (all 'live' contexts are even-numbered).\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *GENSYM-COUNTER* INTEGER 0 :DOCUMENTATION \"Incremented once for each gensym call.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *GENSYM-MASK* STRING \"-000\" :DOCUMENTATION \"Defines the separator character for gensyms,\nand the fill digits.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *SYMBOL-ESCAPE-CODE-TABLE* STRING (INITIALIZE-SYMBOL-ESCAPE-CODE-TABLE FALSE))");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *CASE-SENSITIVE-SYMBOL-ESCAPE-CODE-TABLE* STRING (INITIALIZE-SYMBOL-ESCAPE-CODE-TABLE TRUE))");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
