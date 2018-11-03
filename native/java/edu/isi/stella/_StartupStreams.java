//  -*- Mode: Java -*-
//
// _StartupStreams.java

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

package edu.isi.stella;

import edu.isi.stella.javalib.*;

public class _StartupStreams {
  static void helpStartupStreams1() {
    {
      Stella.SYM_STELLA_EOL = ((Symbol)(Stella.internRigidSymbolWrtModule("EOL", null, 0)));
      Stella.SYM_STELLA_PRINT_STREAM = ((Symbol)(Stella.internRigidSymbolWrtModule("PRINT-STREAM", null, 0)));
      Stella.SYM_STELLA_STANDARD_OUTPUT = ((Symbol)(Stella.internRigidSymbolWrtModule("STANDARD-OUTPUT", null, 0)));
      Stella.SYM_STELLA_FOREACH = ((Symbol)(Stella.internRigidSymbolWrtModule("FOREACH", null, 0)));
      Stella.SYM_STELLA_I = ((Symbol)(Stella.internRigidSymbolWrtModule("I", null, 0)));
      Stella.SYM_STELLA_IN = ((Symbol)(Stella.internRigidSymbolWrtModule("IN", null, 0)));
      Stella.SYM_STELLA_INTERVAL = ((Symbol)(Stella.internRigidSymbolWrtModule("INTERVAL", null, 0)));
      Stella.SYM_STELLA_DO = ((Symbol)(Stella.internRigidSymbolWrtModule("DO", null, 0)));
      Stella.SYM_STELLA_IGNORE = ((Symbol)(Stella.internRigidSymbolWrtModule("IGNORE", null, 0)));
      Stella.KWD_COMMON_LISP = ((Keyword)(Stella.internRigidSymbolWrtModule("COMMON-LISP", null, 2)));
      Stella.KWD_WARN = ((Keyword)(Stella.internRigidSymbolWrtModule("WARN", null, 2)));
      Stella.SYM_STELLA_STANDARD_WARNING = ((Symbol)(Stella.internRigidSymbolWrtModule("STANDARD-WARNING", null, 0)));
      Stella.SYM_STELLA_NULL = ((Symbol)(Stella.internRigidSymbolWrtModule("NULL", null, 0)));
      Stella.SYM_STELLA_STELLA_EXCEPTION = ((Symbol)(Stella.internRigidSymbolWrtModule("STELLA-EXCEPTION", null, 0)));
      Stella.SYM_STELLA_SIGNAL_EXCEPTION = ((Symbol)(Stella.internRigidSymbolWrtModule("SIGNAL-EXCEPTION", null, 0)));
      Stella.SYM_STELLA_NEW = ((Symbol)(Stella.internRigidSymbolWrtModule("NEW", null, 0)));
      Stella.KWD_MESSAGE = ((Keyword)(Stella.internRigidSymbolWrtModule("MESSAGE", null, 2)));
      Stella.SYM_STELLA_LET = ((Symbol)(Stella.internRigidSymbolWrtModule("LET", null, 0)));
      Stella.SYM_STELLA_OUTPUT_STRING_STREAM = ((Symbol)(Stella.internRigidSymbolWrtModule("OUTPUT-STRING-STREAM", null, 0)));
      Stella.SYM_STELLA_SIGNAL = ((Symbol)(Stella.internRigidSymbolWrtModule("SIGNAL", null, 0)));
      Stella.KWD_JAVA = ((Keyword)(Stella.internRigidSymbolWrtModule("JAVA", null, 2)));
      Stella.SYM_STELLA_ERROR_MESSAGE_ = ((Symbol)(Stella.internRigidSymbolWrtModule("ERROR_MESSAGE_", null, 0)));
      Stella.SYM_STELLA_VERBATIM = ((Symbol)(Stella.internRigidSymbolWrtModule("VERBATIM", null, 0)));
      Stella.KWD_CONTINUABLE_ERROR = ((Keyword)(Stella.internRigidSymbolWrtModule("CONTINUABLE-ERROR", null, 2)));
      Stella.SYM_STELLA_READ_EXCEPTION = ((Symbol)(Stella.internRigidSymbolWrtModule("READ-EXCEPTION", null, 0)));
      Stella.SYM_STELLA_DE_UGLIFY_PARSE_TREE = ((Symbol)(Stella.internRigidSymbolWrtModule("DE-UGLIFY-PARSE-TREE", null, 0)));
      Stella.SYM_STELLA_SPECIAL = ((Symbol)(Stella.internRigidSymbolWrtModule("SPECIAL", null, 0)));
      Stella.SYM_STELLA_$PRINTREADABLYp$ = ((Symbol)(Stella.internRigidSymbolWrtModule("*PRINTREADABLY?*", null, 0)));
      Stella.SYM_STELLA_SIGNAL_TRANSLATION_ERROR = ((Symbol)(Stella.internRigidSymbolWrtModule("SIGNAL-TRANSLATION-ERROR", null, 0)));
      Stella.SYM_STELLA_UNLESS = ((Symbol)(Stella.internRigidSymbolWrtModule("UNLESS", null, 0)));
      Stella.SYM_STELLA_SUPPRESS_WARNINGSp = ((Symbol)(Stella.internRigidSymbolWrtModule("SUPPRESS-WARNINGS?", null, 0)));
      Stella.SYM_STELLA_PRINT_ERROR_CONTEXT = ((Symbol)(Stella.internRigidSymbolWrtModule("PRINT-ERROR-CONTEXT", null, 0)));
      Stella.SYM_STELLA_STANDARD_ERROR = ((Symbol)(Stella.internRigidSymbolWrtModule("STANDARD-ERROR", null, 0)));
      Stella.SYM_STELLA_SIGNAL_TRANSLATION_WARNING = ((Symbol)(Stella.internRigidSymbolWrtModule("SIGNAL-TRANSLATION-WARNING", null, 0)));
      Stella.SYM_STELLA_WHEN = ((Symbol)(Stella.internRigidSymbolWrtModule("WHEN", null, 0)));
      Stella.SYM_STELLA_NOT = ((Symbol)(Stella.internRigidSymbolWrtModule("NOT", null, 0)));
      Stella.SYM_STELLA_$EVALUATIONTREE$ = ((Symbol)(Stella.internRigidSymbolWrtModule("*EVALUATIONTREE*", null, 0)));
      Stella.SYM_STELLA_DEFINEDp = ((Symbol)(Stella.internRigidSymbolWrtModule("DEFINED?", null, 0)));
      Stella.SYM_STELLA_$EVALUATIONPARENTTREE$ = ((Symbol)(Stella.internRigidSymbolWrtModule("*EVALUATIONPARENTTREE*", null, 0)));
      Stella.SYM_STELLA_EVALUATION_EXCEPTION = ((Symbol)(Stella.internRigidSymbolWrtModule("EVALUATION-EXCEPTION", null, 0)));
      Stella.SGT_STELLA_LITERAL_WRAPPER = ((Surrogate)(Stella.internRigidSymbolWrtModule("LITERAL-WRAPPER", null, 1)));
      Stella.SYM_STELLA_STRINGIFY = ((Symbol)(Stella.internRigidSymbolWrtModule("STRINGIFY", null, 0)));
      Stella.SYM_STELLA_VRLET = ((Symbol)(Stella.internRigidSymbolWrtModule("VRLET", null, 0)));
      Stella.SYM_STELLA_STRING = ((Symbol)(Stella.internRigidSymbolWrtModule("STRING", null, 0)));
      Stella.SYM_STELLA_SETQ = ((Symbol)(Stella.internRigidSymbolWrtModule("SETQ", null, 0)));
      Stella.SYM_STELLA_CONCATENATE = ((Symbol)(Stella.internRigidSymbolWrtModule("CONCATENATE", null, 0)));
      Stella.KWD_CLOSED = ((Keyword)(Stella.internRigidSymbolWrtModule("CLOSED", null, 2)));
      Stella.KWD_IF_EXISTS = ((Keyword)(Stella.internRigidSymbolWrtModule("IF-EXISTS", null, 2)));
      Stella.KWD_IF_EXISTS_ACTION = ((Keyword)(Stella.internRigidSymbolWrtModule("IF-EXISTS-ACTION", null, 2)));
      Stella.KWD_IF_NOT_EXISTS = ((Keyword)(Stella.internRigidSymbolWrtModule("IF-NOT-EXISTS", null, 2)));
      Stella.KWD_IF_NOT_EXISTS_ACTION = ((Keyword)(Stella.internRigidSymbolWrtModule("IF-NOT-EXISTS-ACTION", null, 2)));
      Stella.KWD_ABORT = ((Keyword)(Stella.internRigidSymbolWrtModule("ABORT", null, 2)));
      Stella.KWD_PROBE = ((Keyword)(Stella.internRigidSymbolWrtModule("PROBE", null, 2)));
      Stella.KWD_APPEND = ((Keyword)(Stella.internRigidSymbolWrtModule("APPEND", null, 2)));
      Stella.KWD_OPEN = ((Keyword)(Stella.internRigidSymbolWrtModule("OPEN", null, 2)));
      Stella.SYM_STELLA_UNWIND_PROTECT = ((Symbol)(Stella.internRigidSymbolWrtModule("UNWIND-PROTECT", null, 0)));
      Stella.SYM_STELLA_PROGN = ((Symbol)(Stella.internRigidSymbolWrtModule("PROGN", null, 0)));
      Stella.SYM_STELLA_OPEN_INPUT_FILE = ((Symbol)(Stella.internRigidSymbolWrtModule("OPEN-INPUT-FILE", null, 0)));
      Stella.SYM_STELLA_FREE = ((Symbol)(Stella.internRigidSymbolWrtModule("FREE", null, 0)));
      Stella.SYM_STELLA_OPEN_OUTPUT_FILE = ((Symbol)(Stella.internRigidSymbolWrtModule("OPEN-OUTPUT-FILE", null, 0)));
    }
  }

  static void helpStartupStreams2() {
    {
      Stella.SYM_STELLA_INPUT_STREAM = ((Symbol)(Stella.internRigidSymbolWrtModule("INPUT-STREAM", null, 0)));
      Stella.SYM_STELLA_OUTPUT_STREAM = ((Symbol)(Stella.internRigidSymbolWrtModule("OUTPUT-STREAM", null, 0)));
      Stella.SYM_STELLA_MV_SETQ = ((Symbol)(Stella.internRigidSymbolWrtModule("MV-SETQ", null, 0)));
      Stella.SYM_STELLA_OPEN_NETWORK_STREAM = ((Symbol)(Stella.internRigidSymbolWrtModule("OPEN-NETWORK-STREAM", null, 0)));
      Stella.SGT_STELLA_OBJECT = ((Surrogate)(Stella.internRigidSymbolWrtModule("OBJECT", null, 1)));
      Stella.SYM_STELLA_SUBSEQUENCE = ((Symbol)(Stella.internRigidSymbolWrtModule("SUBSEQUENCE", null, 0)));
      Stella.SYM_STELLA_POSITION = ((Symbol)(Stella.internRigidSymbolWrtModule("POSITION", null, 0)));
      Stella.SYM_STELLA_THE_STREAM = ((Symbol)(Stella.internRigidSymbolWrtModule("THE-STREAM", null, 0)));
      Stella.SGT_STELLA_S_EXPRESSION_ITERATOR = ((Surrogate)(Stella.internRigidSymbolWrtModule("S-EXPRESSION-ITERATOR", null, 1)));
      Stella.SGT_STELLA_LINE_ITERATOR = ((Surrogate)(Stella.internRigidSymbolWrtModule("LINE-ITERATOR", null, 1)));
      Stella.SGT_STELLA_NATIVE_LINE_ITERATOR = ((Surrogate)(Stella.internRigidSymbolWrtModule("NATIVE-LINE-ITERATOR", null, 1)));
      Stella.SGT_STELLA_CHARACTER_ITERATOR = ((Surrogate)(Stella.internRigidSymbolWrtModule("CHARACTER-ITERATOR", null, 1)));
      Stella.KWD_LOG_LEVELS = ((Keyword)(Stella.internRigidSymbolWrtModule("LOG-LEVELS", null, 2)));
      Stella.KWD_LEVEL = ((Keyword)(Stella.internRigidSymbolWrtModule("LEVEL", null, 2)));
      Stella.KWD_STREAM = ((Keyword)(Stella.internRigidSymbolWrtModule("STREAM", null, 2)));
      Stella.KWD_PREFIX = ((Keyword)(Stella.internRigidSymbolWrtModule("PREFIX", null, 2)));
      Stella.KWD_MAX_WIDTH = ((Keyword)(Stella.internRigidSymbolWrtModule("MAX-WIDTH", null, 2)));
      Stella.SYM_STELLA_STARTUP_STREAMS = ((Symbol)(Stella.internRigidSymbolWrtModule("STARTUP-STREAMS", null, 0)));
    }
  }

  static void helpStartupStreams3() {
    {
      Stella.EOL = Stella.SYM_STELLA_EOL;
      { InputStream self000 = InputStream.newInputStream();

        self000.nativeStream = new java.io.PushbackInputStream(java.lang.System.in);
        Stella.STANDARD_INPUT = self000;
      }
      Stella.$IGNORETRANSLATIONERRORSp$.setDefaultValue(new Boolean(true));
      Stella.SINGLE_QUOTE_STRING = StringWrapper.wrapString("'");
      Stella.SINGLE_BQUOTE_STRING = StringWrapper.wrapString("`");
      Stella.$OPEN_FILE_STREAMS$ = List.newList();
      Stella.$HTML_ESCAPE_TABLE$ = KeyValueList.newKeyValueList();
      Stella.$LOGGING_REGISTRY$ = KeyValueList.newKeyValueList();
      Stella.$LOGGING_LOCAL_TIME_ZONE$ = Stella.getLocalTimeZone();
    }
  }

  static void helpStartupStreams4() {
    {
      Stella.defineFunctionObject("FORMAT-MESSAGE-ARGUMENTS", "(DEFUN (FORMAT-MESSAGE-ARGUMENTS CONS) ((MESSAGEARGUMENTSTREE CONS) (TRAILINGEOL? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Cons", "formatMessageArguments", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("PRINT", "(DEFUN PRINT (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Print arguments to the standard output stream.\")", Native.find_java_method("edu.isi.stella.Cons", "print", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("PRINT-SPACES", "(DEFUN PRINT-SPACES (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"(print-spaces [stream] N) prints N spaces onto stream.  If\nno stream form is provided, then STANDARD-OUTPUT will be used.\")", Native.find_java_method("edu.isi.stella.Cons", "printSpaces", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("INFORM", "(DEFUN INFORM (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Print informative message, placing non-string arguments in quotes,\nand terminating with a newline.\")", Native.find_java_method("edu.isi.stella.Cons", "inform", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("WARN", "(DEFUN WARN (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Signal warning message, placing non-string arguments in quotes.\")", Native.find_java_method("edu.isi.stella.Cons", "warn", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("SIGNAL", "(DEFUN SIGNAL ((TYPE SYMBOL) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Signal error message, placing non-string arguments in quotes.\")", Native.find_java_method("edu.isi.stella.Symbol", "signal", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("ERROR", "(DEFUN ERROR (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Signal error message, placing non-string arguments in quotes.\")", Native.find_java_method("edu.isi.stella.Cons", "error", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("CONTINUABLE-ERROR", "(DEFUN CONTINUABLE-ERROR (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Signal error message, placing non-string arguments in quotes.\")", Native.find_java_method("edu.isi.stella.Cons", "continuableError", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("SIGNAL-READ-ERROR", "(DEFUN SIGNAL-READ-ERROR (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Specialized version of `signal' that throws a READ-EXCEPTION.\")", Native.find_java_method("edu.isi.stella.Cons", "signalReadError", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("ENSURE-FILE-EXISTS", "(DEFUN ENSURE-FILE-EXISTS ((FILENAME STRING) (CONTEXT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Ensures that `filename' exists.  If not, an exception of\ntype `NO-SUCH-FILE-EXCEPTION' is thrown with `context' supplying\ncontext for the error message.\")", Native.find_java_method("edu.isi.stella.Stella", "ensureFileExists", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("ENSURE-FILE-DOES-NOT-EXIST", "(DEFUN ENSURE-FILE-DOES-NOT-EXIST ((FILENAME STRING) (CONTEXT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Ensures that `filename' does not exist.  If it does,\nan exception of type `FILE-ALREADY-EXISTS-EXCEPTION' is thrown\nwith `context' supplying context for the error message.\")", Native.find_java_method("edu.isi.stella.Stella", "ensureFileDoesNotExist", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("FORMAT-WALK-MESSAGE-ARGUMENTS", "(DEFUN (FORMAT-WALK-MESSAGE-ARGUMENTS CONS) ((MESSAGEARGUMENTSTREE CONS)))", Native.find_java_method("edu.isi.stella.Cons", "formatWalkMessageArguments", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("WALK-ERROR", "(DEFUN WALK-ERROR (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", Native.find_java_method("edu.isi.stella.Cons", "walkError", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("WALK-INFORM", "(DEFUN WALK-INFORM (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", Native.find_java_method("edu.isi.stella.Cons", "walkInform", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("WALK-WARN", "(DEFUN WALK-WARN (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", Native.find_java_method("edu.isi.stella.Cons", "walkWarn", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("SAFETY", "(DEFUN SAFETY ((LEVEL INTEGER-WRAPPER) (TEST OBJECT) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Signal warning message, placing non-string arguments in quotes.\")", Native.find_java_method("edu.isi.stella.IntegerWrapper", "safety", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.IntegerWrapper"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("EVALUATION-ERROR", "(DEFUN EVALUATION-ERROR (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", Native.find_java_method("edu.isi.stella.Cons", "evaluationError", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("FORMAT-STRING-MESSAGE-ARGUMENTS", "(DEFUN (FORMAT-STRING-MESSAGE-ARGUMENTS CONS) ((MESSAGEARGUMENTS CONS) (TRAILINGEOL? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Cons", "formatStringMessageArguments", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("MESSAGE-TO-STRING", "(DEFUN MESSAGE-TO-STRING (|&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", Native.find_java_method("edu.isi.stella.Cons", "messageToString", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("TERMINATE-OUTPUT-STREAM?", "(DEFUN (TERMINATE-OUTPUT-STREAM? BOOLEAN) ((SELF OUTPUT-STREAM)))", Native.find_java_method("edu.isi.stella.OutputStream", "terminateOutputStreamP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.OutputStream")}), null);
      Stella.defineFunctionObject("TERMINATE-INPUT-STREAM?", "(DEFUN (TERMINATE-INPUT-STREAM? BOOLEAN) ((SELF INPUT-STREAM)))", Native.find_java_method("edu.isi.stella.InputStream", "terminateInputStreamP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.InputStream")}), null);
      Stella.defineFunctionObject("OPEN-OUTPUT-FILE", "(DEFUN (OPEN-OUTPUT-FILE FILE-OUTPUT-STREAM) ((FILENAME STRING) |&REST| (OPTIONS KEYWORD)) :DOCUMENTATION \"Open file `fileName' for output and return the resulting output stream.\nBy default the file will be created or overwritten if it already exists.\nIf `:IF-EXISTS' (or `:IF-EXISTS-ACTION') is one of the `options' its value\nspecifies what to do in case the file already exists.  If the value is\n`:SUPERSEDE' the pre-existing file will be overwritten.  If the value is\n`:APPEND' the preexisting file will be appended to (if the file did not\nyet exist the file will simply be created).  If the value is `:ERROR' then\nan error will be signaled.  If it is `:ABORT' or `:PROBE' the opening operation\nwill be aborted and NULL will be returned.\n\nIf `:IF-NOT-EXISTS' (or `:IF-NOT-EXISTS-ACTION') is one of the `options' its\nvalue specifies what to do in case the file does not already exist.  If the\nvalue is `:CREATE', the file will simply be created.  If the value is\n`:ERROR' then an error will be signaled.  If it is `:ABORT' or `:PROBE' the\nopening operation will be aborted and NULL will be returned.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "openOutputFile", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("INITIALIZE-FILE-OUTPUT-STREAM", "(DEFUN INITIALIZE-FILE-OUTPUT-STREAM ((SELF FILE-OUTPUT-STREAM)))", Native.find_java_method("edu.isi.stella.OutputFileStream", "initializeFileOutputStream", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.OutputFileStream")}), null);
      Stella.defineFunctionObject("TERMINATE-FILE-OUTPUT-STREAM?", "(DEFUN (TERMINATE-FILE-OUTPUT-STREAM? BOOLEAN) ((SELF FILE-OUTPUT-STREAM)))", Native.find_java_method("edu.isi.stella.OutputFileStream", "terminateFileOutputStreamP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.OutputFileStream")}), null);
      Stella.defineFunctionObject("OPEN-INPUT-FILE", "(DEFUN (OPEN-INPUT-FILE FILE-INPUT-STREAM) ((FILENAME STRING) |&REST| (OPTIONS KEYWORD)) :DOCUMENTATION \"Open file `fileName' for input and return the resulting input stream.\nBy default signal an error if the file does not exist.  The only legal\noption so far is `:IF-NOT-EXISTS' (or `:IF-NOT-EXISTS-ACTION') which\nspecifies what to do in case the file does not exist.  If its value is\n`:ERROR' then an error will be signaled.  If it is `:ABORT' or `:PROBE'\nthe opening operation will be aborted and NULL will be returned.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "openInputFile", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("INITIALIZE-FILE-INPUT-STREAM", "(DEFUN INITIALIZE-FILE-INPUT-STREAM ((SELF FILE-INPUT-STREAM)))", Native.find_java_method("edu.isi.stella.InputFileStream", "initializeFileInputStream", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.InputFileStream")}), null);
      Stella.defineFunctionObject("TERMINATE-FILE-INPUT-STREAM?", "(DEFUN (TERMINATE-FILE-INPUT-STREAM? BOOLEAN) ((SELF FILE-INPUT-STREAM)))", Native.find_java_method("edu.isi.stella.InputFileStream", "terminateFileInputStreamP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.InputFileStream")}), null);
      Stella.defineFunctionObject("INITIALIZE-STRING-OUTPUT-STREAM", "(DEFUN INITIALIZE-STRING-OUTPUT-STREAM ((SELF OUTPUT-STRING-STREAM)))", Native.find_java_method("edu.isi.stella.OutputStringStream", "initializeStringOutputStream", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.OutputStringStream")}), null);
      Stella.defineFunctionObject("TERMINATE-STRING-OUTPUT-STREAM?", "(DEFUN (TERMINATE-STRING-OUTPUT-STREAM? BOOLEAN) ((SELF OUTPUT-STRING-STREAM)))", Native.find_java_method("edu.isi.stella.OutputStringStream", "terminateStringOutputStreamP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.OutputStringStream")}), null);
      Stella.defineMethodObject("(DEFMETHOD (THE-STRING-READER STRING) ((SELF OUTPUT-STRING-STREAM)))", Native.find_java_method("edu.isi.stella.OutputStringStream", "theStringReader", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject("INITIALIZE-STRING-INPUT-STREAM", "(DEFUN INITIALIZE-STRING-INPUT-STREAM ((SELF INPUT-STRING-STREAM)))", Native.find_java_method("edu.isi.stella.InputStringStream", "initializeStringInputStream", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.InputStringStream")}), null);
      Stella.defineFunctionObject("TERMINATE-STRING-INPUT-STREAM?", "(DEFUN (TERMINATE-STRING-INPUT-STREAM? BOOLEAN) ((SELF INPUT-STRING-STREAM)))", Native.find_java_method("edu.isi.stella.InputStringStream", "terminateStringInputStreamP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.InputStringStream")}), null);
      Stella.defineFunctionObject("CLOSE-STREAM", "(DEFUN CLOSE-STREAM ((SELF STREAM)) :DOCUMENTATION \"Close the stream `self'.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stream", "closeStream", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stream")}), null);
      Stella.defineFunctionObject("FLUSH-OUTPUT", "(DEFUN FLUSH-OUTPUT ((SELF OUTPUT-STREAM)) :DOCUMENTATION \"Flush all buffered output of `self'.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.OutputStream", "flushOutput", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.OutputStream")}), null);
      Stella.defineFunctionObject("CLOSE-ALL-FILES", "(DEFUN CLOSE-ALL-FILES () :DOCUMENTATION \"Close all currently open file streams.  Use for emergencies or for cleanup.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "closeAllFiles", new java.lang.Class [] {}), null);
      Stella.defineFunctionObject("OPEN-NETWORK-STREAM", "(DEFUN (OPEN-NETWORK-STREAM INPUT-STREAM OUTPUT-STREAM) ((HOST STRING) (PORT INTEGER)) :DOCUMENTATION \"Open a TCP/IP network stream to `host' at `port' and return the result\nas an input/output stream pair.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "openNetworkStream", new java.lang.Class [] {Native.find_java_class("java.lang.String"), java.lang.Integer.TYPE, Native.find_java_class("[Ljava.lang.Object;")}), null);
      Stella.defineFunctionObject("WITH-INPUT-FILE", "(DEFUN WITH-INPUT-FILE ((BINDING CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Sets up an unwind-protected form which opens a file for\ninput and closes it afterwards.  The stream for reading is bound to the\nvariable provided in the macro form.\nSyntax is `(WITH-INPUT-FILE (var filename options*) body+)' where `options'\ncan be any that are legal for `open-input-file' (which see).\")", Native.find_java_method("edu.isi.stella.Cons", "withInputFile", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("WITH-OUTPUT-FILE", "(DEFUN WITH-OUTPUT-FILE ((BINDING CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Sets up an unwind-protected form which opens a file for\noutput and closes it afterwards.  The stream for writing is bound to the\nvariable provided in the macro form.\nSyntax is `(WITH-OUTPUT-FILE (var filename options*) body+)' where `options'\ncan be any that are legal for `open-output-file' (which see).\")", Native.find_java_method("edu.isi.stella.Cons", "withOutputFile", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("WITH-NETWORK-STREAM", "(DEFUN WITH-NETWORK-STREAM ((BINDING CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE :PUBLIC? TRUE :DOCUMENTATION \"Sets up an unwind-protected form which opens a network\nsocket stream to a host and port for input and output and closes it afterwards.\nSeparate variables as provided in the call are bound to the input and output\nstreams. Syntax is (WITH-NETWORK-STREAM (varIn varOut hostname port) body+)\")", Native.find_java_method("edu.isi.stella.Cons", "withNetworkStream", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("EXPAND-MARKUP-TAG-FUNCTION", "(DEFUN (EXPAND-MARKUP-TAG-FUNCTION CONS) ((TAG-AND-STREAM CONS) (BODY CONS) (XML? BOOLEAN)))", Native.find_java_method("edu.isi.stella.Cons", "expandMarkupTagFunction", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons"), java.lang.Boolean.TYPE}), null);
      Stella.defineFunctionObject("WITH-HTML-TAG", "(DEFUN WITH-HTML-TAG ((TAG-AND-STREAM CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", Native.find_java_method("edu.isi.stella.Cons", "withHtmlTag", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("WITH-XML-TAG", "(DEFUN WITH-XML-TAG ((TAG-AND-STREAM CONS) |&BODY| (BODY CONS)) :TYPE OBJECT :MACRO? TRUE)", Native.find_java_method("edu.isi.stella.Cons", "withXmlTag", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Cons"), Native.find_java_class("edu.isi.stella.Cons")}), null);
      Stella.defineFunctionObject("HTML-CHARACTER-NEEDS-QUOTING?", "(DEFUN (HTML-CHARACTER-NEEDS-QUOTING? BOOLEAN) ((CH CHARACTER)))", Native.find_java_method("edu.isi.stella.Stella", "htmlCharacterNeedsQuotingP", new java.lang.Class [] {java.lang.Character.TYPE}), null);
      Stella.defineFunctionObject("WRITE-HTML-CHARACTER-QUOTING-SPECIAL-CHARACTERS", "(DEFUN WRITE-HTML-CHARACTER-QUOTING-SPECIAL-CHARACTERS ((STREAM NATIVE-OUTPUT-STREAM) (CH CHARACTER)) :GLOBALLY-INLINE? TRUE (CASE CH (#\\> (PRINT-STREAM STREAM \"&gt;\")) (#\\< (PRINT-STREAM STREAM \"&lt;\")) (#\\& (PRINT-STREAM STREAM \"&amp;\")) (#\\\" (PRINT-STREAM STREAM \"&quot;\")) (OTHERWISE (PRINT-STREAM STREAM CH))) (RETURN))", Native.find_java_method("edu.isi.stella.Stella", "writeHtmlCharacterQuotingSpecialCharacters", new java.lang.Class [] {Native.find_java_class("java.io.PrintStream"), java.lang.Character.TYPE}), null);
      Stella.defineFunctionObject("WRITE-HTML-QUOTING-SPECIAL-CHARACTERS", "(DEFUN WRITE-HTML-QUOTING-SPECIAL-CHARACTERS ((STREAM NATIVE-OUTPUT-STREAM) (INPUT STRING)))", Native.find_java_method("edu.isi.stella.Stella", "writeHtmlQuotingSpecialCharacters", new java.lang.Class [] {Native.find_java_class("java.io.PrintStream"), Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("WRITE-HTML-ESCAPING-URL-SPECIAL-CHARACTERS", "(DEFUN WRITE-HTML-ESCAPING-URL-SPECIAL-CHARACTERS ((STREAM NATIVE-OUTPUT-STREAM) (INPUT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Writes a string and replaces unallowed URL characters according to RFC 2396\nwith %-format URL escape sequences.\")", Native.find_java_method("edu.isi.stella.Stella", "writeHtmlEscapingUrlSpecialCharacters", new java.lang.Class [] {Native.find_java_class("java.io.PrintStream"), Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("HEX-CHARACTER-VALUE", "(DEFUN (HEX-CHARACTER-VALUE INTEGER) ((C CHARACTER)) :GLOBALLY-INLINE? TRUE (LET ((V (POSITION \"0123456789ABCDEF\" C 0))) (WHEN (NULL? V) (SETQ V (POSITION \"0123456789abcdef\" C 0))) (RETURN V)))", Native.find_java_method("edu.isi.stella.Stella", "hexCharacterValue", new java.lang.Class [] {java.lang.Character.TYPE}), null);
      Stella.defineFunctionObject("UNESCAPE-URL-STRING", "(DEFUN (UNESCAPE-URL-STRING STRING) ((INPUT STRING)) :PUBLIC? TRUE :DOCUMENTATION \"Takes a string and replaces %-format URL escape sequences with their real\ncharacter equivalent according to RFC 2396.\")", Native.find_java_method("edu.isi.stella.Stella", "unescapeUrlString", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("UNESCAPE-HTML-STRING", "(DEFUN (UNESCAPE-HTML-STRING STRING) ((INPUT STRING)) :DOCUMENTATION \"Replaces HTML escape sequences such as &amp; with their\nassociated characters.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "unescapeHtmlString", new java.lang.Class [] {Native.find_java_class("java.lang.String")}), null);
      Stella.defineFunctionObject("TERMINATE-STREAM-ITERATOR?", "(DEFUN (TERMINATE-STREAM-ITERATOR? BOOLEAN) ((SELF STREAM-ITERATOR)))", Native.find_java_method("edu.isi.stella.StreamIterator", "terminateStreamIteratorP", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.StreamIterator")}), null);
      Stella.defineFunctionObject("S-EXPRESSIONS", "(DEFUN (S-EXPRESSIONS S-EXPRESSION-ITERATOR) ((STREAM INPUT-STREAM)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.InputStream", "sExpressions", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.InputStream")}), null);
      Stella.defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF S-EXPRESSION-ITERATOR)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.SExpressionIterator", "nextP", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject("NATIVE-LINES", "(DEFUN (NATIVE-LINES NATIVE-LINE-ITERATOR) ((STREAM INPUT-STREAM)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.InputStream", "nativeLines", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.InputStream")}), null);
      Stella.defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF NATIVE-LINE-ITERATOR)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.NativeLineIterator", "nextP", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject("LINES", "(DEFUN (LINES LINE-ITERATOR) ((STREAM INPUT-STREAM)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.InputStream", "lines", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.InputStream")}), null);
      Stella.defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF LINE-ITERATOR)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.LineIterator", "nextP", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject("CHARACTERS", "(DEFUN (CHARACTERS CHARACTER-ITERATOR) ((STREAM INPUT-STREAM)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.InputStream", "characters", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.InputStream")}), null);
      Stella.defineMethodObject("(DEFMETHOD (NEXT? BOOLEAN) ((SELF CHARACTER-ITERATOR)) :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.CharacterIterator", "nextP", new java.lang.Class [] {}), ((java.lang.reflect.Method)(null)));
      Stella.defineFunctionObject("LOOKUP-LOGGING-PARAMETER", "(DEFUN (LOOKUP-LOGGING-PARAMETER OBJECT) ((MODULE STRING) (PARAMETER KEYWORD) (DEFAULT OBJECT)) :DOCUMENTATION \"Lookup logging `parameter' for `module'.  Use `default' if no\nvalue is defined.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "lookupLoggingParameter", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Keyword"), Native.find_java_class("edu.isi.stella.Stella_Object")}), null);
      Stella.defineFunctionObject("SET-LOGGING-PARAMETERS", "(DEFUN SET-LOGGING-PARAMETERS ((MODULE STRING) |&REST| (|PARAMS&VALUES| OBJECT)) :DOCUMENTATION \"Set logging parameters for `module'.  The supported parameters are:\n  :LOG-LEVELS - a cons list of legal levels in ascending log level order;\n                for example, (:NONE :LOW :MEDIUM :HIGH) or (0 1 2 3).\n  :LEVEL      - the current log level for `module'\n  :STREAM     - the stream to log to (defaults to STANDARD-OUTPUT)\n  :PREFIX     - the prefix to use to identify the module (defaults to `module')\n  :MAX-WIDTH  - logging output lines will be kept to approximately this width\n                (defaults to 10000, minimum width of about 30 is used to\n                print line header information).\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "setLoggingParameters", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Cons")}), null);
    }
  }

  public static void startupStreams() {
    if (Stella.currentStartupTimePhaseP(0)) {
      { OutputStream self001 = OutputStream.newOutputStream();

        self001.nativeStream = java.lang.System.out;
        Stella.STANDARD_OUTPUT = self001;
      }
      if (!(Stella.STANDARD_WARNING != null)) {
        { OutputStream self002 = OutputStream.newOutputStream();

          self002.nativeStream = java.lang.System.err;
          Stella.STANDARD_WARNING = self002;
        }
      }
      { OutputStream self003 = OutputStream.newOutputStream();

        self003.nativeStream = java.lang.System.err;
        Stella.STANDARD_ERROR = self003;
      }
    }
    { Object old$Module$000 = Stella.$MODULE$.get();
      Object old$Context$000 = Stella.$CONTEXT$.get();

      try {
        Native.setSpecial(Stella.$MODULE$, Stella.$STELLA_MODULE$);
        Native.setSpecial(Stella.$CONTEXT$, ((Module)(Stella.$MODULE$.get())));
        if (Stella.currentStartupTimePhaseP(2)) {
          _StartupStreams.helpStartupStreams1();
          _StartupStreams.helpStartupStreams2();
        }
        if (Stella.currentStartupTimePhaseP(4)) {
          _StartupStreams.helpStartupStreams3();
        }
        if (Stella.currentStartupTimePhaseP(5)) {
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("STREAM-ITERATOR", "(DEFCLASS STREAM-ITERATOR (ABSTRACT-ITERATOR) :PUBLIC? TRUE :ABSTRACT? TRUE :DOCUMENTATION \"Iterator that yields tokens from an input stream.\" :SLOTS ((THE-STREAM :TYPE INPUT-STREAM)) :TERMINATOR TERMINATE-STREAM-ITERATOR?)");

            renamed_Class.classSlotAccessorCode = Native.find_java_method("edu.isi.stella.StreamIterator", "accessStreamIteratorSlotValue", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.StreamIterator"), Native.find_java_class("edu.isi.stella.Symbol"), Native.find_java_class("edu.isi.stella.Stella_Object"), java.lang.Boolean.TYPE});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("S-EXPRESSION-ITERATOR", "(DEFCLASS S-EXPRESSION-ITERATOR (STREAM-ITERATOR) :PUBLIC? TRUE :DOCUMENTATION \"Iterator that yields s-expressions from an input stream.\" :PARAMETERS ((ANY-VALUE :TYPE OBJECT)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.stella.SExpressionIterator", "newSExpressionIterator", new java.lang.Class [] {});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("LINE-ITERATOR", "(DEFCLASS LINE-ITERATOR (STREAM-ITERATOR) :PUBLIC? TRUE :DOCUMENTATION \"Iterator that yields lines with any line terminator sequence from an input stream.\" :PARAMETERS ((ANY-VALUE :TYPE STRING)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.stella.LineIterator", "newLineIterator", new java.lang.Class [] {});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("NATIVE-LINE-ITERATOR", "(DEFCLASS NATIVE-LINE-ITERATOR (STREAM-ITERATOR) :PUBLIC? TRUE :DOCUMENTATION \"Iterator that yields lines from an input stream.\" :PARAMETERS ((ANY-VALUE :TYPE STRING)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.stella.NativeLineIterator", "newNativeLineIterator", new java.lang.Class [] {});
          }
          { Stella_Class renamed_Class = Stella.defineClassFromStringifiedSource("CHARACTER-ITERATOR", "(DEFCLASS CHARACTER-ITERATOR (STREAM-ITERATOR) :PUBLIC? TRUE :DOCUMENTATION \"Iterator that yields characters from an input stream.\" :PARAMETERS ((ANY-VALUE :TYPE CHARACTER)))");

            renamed_Class.classConstructorCode = Native.find_java_method("edu.isi.stella.CharacterIterator", "newCharacterIterator", new java.lang.Class [] {});
          }
        }
        if (Stella.currentStartupTimePhaseP(6)) {
          Stella.finalizeClasses();
        }
        if (Stella.currentStartupTimePhaseP(7)) {
          _StartupStreams.helpStartupStreams4();
          Stella.defineFunctionObject("LOG-LEVEL<=", "(DEFUN (LOG-LEVEL<= BOOLEAN) ((LEVEL OBJECT) (MODULE STRING)) :DOCUMENTATION \"Return TRUE if `level' is lower than or equal to the current\nlog level of `module'.  Return FALSE if any of them are undefined.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella_Object", "logLevelLE", new java.lang.Class [] {Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("java.lang.String")}), null);
          Stella.defineFunctionObject("LOG-MESSAGE", "(DEFUN LOG-MESSAGE ((MODULE STRING) (LOGLEVEL OBJECT) (MESSAGE CONS)) :DOCUMENTATION \"Log all elements of `message' to `module's log stream if\n`logLevel' is the same or lower than the `module's log level.  Interprets `EOL'\nor :EOL to print a line terminator.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "logMessage", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("LOGMSG", "(DEFUN LOGMSG ((MODULE STRING) (LOGLEVEL OBJECT) |&REST| (MESSAGE OBJECT)) :DOCUMENTATION \"Log all elements of `message' to `module's log stream if\n`logLevel' is the same or lower than the `module's log level.  Interprets `EOL'\nor :EOL to print a line terminator.\" :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella.Stella", "logmsg", new java.lang.Class [] {Native.find_java_class("java.lang.String"), Native.find_java_class("edu.isi.stella.Stella_Object"), Native.find_java_class("edu.isi.stella.Cons")}), null);
          Stella.defineFunctionObject("STARTUP-STREAMS", "(DEFUN STARTUP-STREAMS () :PUBLIC? TRUE)", Native.find_java_method("edu.isi.stella._StartupStreams", "startupStreams", new java.lang.Class [] {}), null);
          { MethodSlot function = Symbol.lookupFunction(Stella.SYM_STELLA_STARTUP_STREAMS);

            KeyValueList.setDynamicSlotValue(function.dynamicSlots, Stella.SYM_STELLA_METHOD_STARTUP_CLASSNAME, StringWrapper.wrapString("_StartupStreams"), Stella.NULL_STRING_WRAPPER);
          }
        }
        if (Stella.currentStartupTimePhaseP(8)) {
          Stella.finalizeSlots();
          Stella.cleanupUnfinalizedClasses();
        }
        if (Stella.currentStartupTimePhaseP(9)) {
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL EOL SYMBOL (QUOTE EOL) :DOCUMENTATION \"Generates a newline character when passed to a stream.\" :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL EOL-STRING STRING \"\n\" :DOCUMENTATION \"A string constant containing the character sequence\nnecessary to generate a newline.\" :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL STANDARD-INPUT INPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard input stream for the host language.\" :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL STANDARD-OUTPUT OUTPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard output stream for the host language.\" :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL STANDARD-WARNING OUTPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard warning stream for the host language.\" :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL STANDARD-ERROR OUTPUT-STREAM NULL :DOCUMENTATION \"Denotes the standard error stream for the host language.\" :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFSPECIAL *IGNORETRANSLATIONERRORS?* BOOLEAN TRUE :DOCUMENTATION \"If `true' all passes of a translation will always be performed\nregardless of whether any errors were encountered.  Otherwise, translation\nends with the first pass that encountered an error.\" :PUBLIC? TRUE)");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL SINGLE-QUOTE-STRING STRING-WRAPPER (WRAP-LITERAL \"'\") :DOCUMENTATION \"Holds a string containing the single quote character.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL SINGLE-BQUOTE-STRING STRING-WRAPPER (WRAP-LITERAL \"`\") :DOCUMENTATION \"Holds a string containing the single backquote character.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *OPEN-FILE-STREAMS* (LIST OF STREAM) (NEW (LIST OF STREAM)) :DOCUMENTATION \"List of file streams that are currently open.\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *HTML-QUOTED-CHARACTERS* STRING \"><&\\\"\")");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *HTML-ESCAPE-TABLE* KEY-VALUE-LIST (NEW KEY-VALUE-LIST))");
          Stella.$HTML_ESCAPE_TABLE$.insertAt(StringWrapper.wrapString("lt"), CharacterWrapper.wrapCharacter('<'));
          Stella.$HTML_ESCAPE_TABLE$.insertAt(StringWrapper.wrapString("gt"), CharacterWrapper.wrapCharacter('>'));
          Stella.$HTML_ESCAPE_TABLE$.insertAt(StringWrapper.wrapString("amp"), CharacterWrapper.wrapCharacter('&'));
          Stella.$HTML_ESCAPE_TABLE$.insertAt(StringWrapper.wrapString("quot"), CharacterWrapper.wrapCharacter('"'));
          Stella.$HTML_ESCAPE_TABLE$.insertAt(StringWrapper.wrapString("apos"), CharacterWrapper.wrapCharacter('\''));
          Stella.$HTML_ESCAPE_TABLE$.insertAt(StringWrapper.wrapString("nbsp"), CharacterWrapper.wrapCharacter(' '));
          Stella.$HTML_ESCAPE_TABLE$.insertAt(StringWrapper.wrapString("NBSP"), CharacterWrapper.wrapCharacter(' '));
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LOGGING-REGISTRY* (KEY-VALUE-LIST OF STRING-WRAPPER (PROPERTY-LIST OF KEYWORD OBJECT)) (NEW KEY-VALUE-LIST))");
          Stella.defineStellaGlobalVariableFromStringifiedSource("(DEFGLOBAL *LOGGING-LOCAL-TIME-ZONE* FLOAT (GET-LOCAL-TIME-ZONE))");
        }

      } finally {
        Stella.$CONTEXT$.set(old$Context$000);
        Stella.$MODULE$.set(old$Module$000);
      }
    }
  }

}
